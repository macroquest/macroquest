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
#define __ExpectedVersionDate                                     "Jul 19 2018"
#define __ExpectedVersionTime                                     "13:02:14"
#define __ActualVersionDate_x                                      0xABE5FC
#define __ActualVersionTime_x                                      0xABE5F0

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x608FD0
#define __MemChecker1_x                                            0x8D9C70
#define __MemChecker2_x                                            0x697A10
#define __MemChecker3_x                                            0x697960
#define __MemChecker4_x                                            0x833500
#define __EncryptPad0_x                                            0xBF0498
#define __EncryptPad1_x                                            0xC4E628
#define __EncryptPad2_x                                            0xC014D0
#define __EncryptPad3_x                                            0xC010D0
#define __EncryptPad4_x                                            0xC3F3C0
#define __EncryptPad5_x                                            0xF0C0C8
#define __AC1_x                                                    0x7EFF76
#define __AC2_x                                                    0x5C4ABF
#define __AC3_x                                                    0x5CB94F
#define __AC4_x                                                    0x5CF7D0
#define __AC5_x                                                    0x5D5A00
#define __AC6_x                                                    0x5D9F42
#define __AC7_x                                                    0x5C4530
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1AC5B4

// Direct Input
#define DI8__Main_x                                                0xF0C0EC
#define DI8__Keyboard_x                                            0xF0C0F0
#define DI8__Mouse_x                                               0xF0C0B0
#define DI8__Mouse_Copy_x                                          0xE69DA4
#define DI8__Mouse_Check_x                                         0xF0CFB0
#define __AutoSkillArray_x                                         0xE6ACB4
#define __Attack_x                                                 0xF08A9B
#define __Autofire_x                                               0xF08A9C
#define __BindList_x                                               0xBDF088
#define g_eqCommandStates_x                                        0xBDFDF8
#define __Clicks_x                                                 0xE69E5C
#define __CommandList_x                                            0xBE09B0
#define __CurrentMapLabel_x                                        0x101E6D4
#define __CurrentSocial_x                                          0xBCA710
#define __DoAbilityList_x                                          0xEA05BC
#define __do_loot_x                                                0x592150
#define __DrawHandler_x                                            0x1699BE8
#define __GroupCount_x                                             0xE5A062
#define __Guilds_x                                                 0xE605B0
#define __gWorld_x                                                 0xE5A3AC
#define __HWnd_x                                                   0xF0C0B4
#define __heqmain_x                                                0x101730C
#define __InChatMode_x                                             0xE69D8C
#define __LastTell_x                                               0xE6BCB8
#define __LMouseHeldTime_x                                         0xE69EC8
#define __Mouse_x                                                  0xF0C0D4
#define __MouseLook_x                                              0xE69E22
#define __MouseEventTime_x                                         0xF09550
#define __gpbCommandEvent_x                                        0xE5A2E4
#define __NetStatusToggle_x                                        0xE69E25
#define __PCNames_x                                                0xE6B278
#define __RangeAttackReady_x                                       0xE6AF98
#define __RMouseHeldTime_x                                         0xE69EC4
#define __RunWalkState_x                                           0xE69D90
#define __ScreenMode_x                                             0xDA8944
#define __ScreenX_x                                                0xE69D44
#define __ScreenY_x                                                0xE69D40
#define __ScreenXMax_x                                             0xE69D48
#define __ScreenYMax_x                                             0xE69D4C
#define __ServerHost_x                                             0xE5A4B3
#define __ServerName_x                                             0xEA057C
#define __ShiftKeyDown_x                                           0xE6A41C
#define __ShowNames_x                                              0xE6B150
#define __Socials_x                                                0xEA067C
#define __SubscriptionType_x                                       0x106019C
#define __TargetAggroHolder_x                                      0x102108C
#define __ZoneType_x                                               0xE6A220
#define __GroupAggro_x                                             0x10210CC
#define __LoginName_x                                              0xF0C944
#define __Inviter_x                                                0xF08A18
#define __AttackOnAssist_x                                         0xE6B10C
#define __UseTellWindows_x                                         0xE6B410
#define __gfMaxZoomCameraDistance_x                                0xAB3B28
#define __gfMaxCameraDistance_x                                    0xAE0F68
#define __pulAutoRun_x                                             0xE69E40
#define __pulForward_x                                             0xE6B448
#define __pulBackward_x                                            0xE6B44C
#define __pulTurnRight_x                                           0xE6B450
#define __pulTurnLeft_x                                            0xE6B454
#define __pulStrafeLeft_x                                          0xE6B458
#define __pulStrafeRight_x                                         0xE6B45C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE5C958
#define instEQZoneInfo_x                                           0xE6A018
#define instKeypressHandler_x                                      0xF09500
#define pinstActiveBanker_x                                        0xE5C900
#define pinstActiveCorpse_x                                        0xE5C8F8
#define pinstActiveGMaster_x                                       0xE5C8FC
#define pinstActiveMerchant_x                                      0xE5C8F4
#define pinstAggroInfo_x                                           0xC64CF8
#define pinstAltAdvManager_x                                       0xDA92F8
#define pinstAuraMgr_x                                             0xC759E0
#define pinstBandageTarget_x                                       0xE5C910
#define pinstCamActor_x                                            0xDA8924
#define pinstCDBStr_x                                              0xDA804C
#define pinstCDisplay_x                                            0xE5A04C
#define pinstCEverQuest_x                                          0xF0C208
#define pinstEverQuestInfo_x                                       0xE69D38
#define pinstCharData_x                                            0xE5A25C
#define pinstCharSpawn_x                                           0xE5C948
#define pinstControlledMissile_x                                   0xE5A260
#define pinstControlledPlayer_x                                    0xE5C948
#define pinstCResolutionHandler_x                                  0x1699E18
#define pinstCSidlManager_x                                        0x1698CAC
#define pinstCXWndManager_x                                        0x1698CA0
#define instDynamicZone_x                                          0xE60488
#define pinstDZMember_x                                            0xE60598
#define pinstDZTimerInfo_x                                         0xE6059C
#define pinstEQItemList_x                                          0xE58B48
#define pinstEQObjectList_x                                        0xE59D38
#define instEQMisc_x                                               0xDA7F88
#define pinstEQSoundManager_x                                      0xDA9B58
#define pinstEQSpellStrings_x                                      0xC72E30
#define instExpeditionLeader_x                                     0xE604D2
#define instExpeditionName_x                                       0xE60512
#define pinstGroup_x                                               0xE5A05E
#define pinstImeManager_x                                          0x1698CA4
#define pinstLocalPlayer_x                                         0xE5C8F0
#define pinstMercenaryData_x                                       0xF09CF0
#define pinstMercenaryStats_x                                      0x10211D8
#define pinstMercAltAbilities_x                                    0xDA98C8
#define pinstModelPlayer_x                                         0xE5C908
#define pinstPCData_x                                              0xE5A25C
#define pinstRealEstateItems_x                                     0xF0B1E0
#define pinstSkillMgr_x                                            0xF0B2B0
#define pinstSpawnManager_x                                        0xF0A8A0
#define pinstSpellManager_x                                        0xF0B518
#define pinstSpellSets_x                                           0xF016C4
#define pinstStringTable_x                                         0xE5A7C4
#define pinstSwitchManager_x                                       0xE59EF8
#define pinstTarget_x                                              0xE5C944
#define pinstTargetObject_x                                        0xE5C950
#define pinstTargetSwitch_x                                        0xE5A268
#define pinstTaskMember_x                                          0xDA7E18
#define pinstTrackTarget_x                                         0xE5C94C
#define pinstTradeTarget_x                                         0xE5C904
#define instTributeActive_x                                        0xDA7FAD
#define pinstViewActor_x                                           0xDA891C
#define pinstWorldData_x                                           0xE5A2DC
#define pinstZoneAddr_x                                            0xE6A2B8
#define pinstPlayerPath_x                                          0xF0A938
#define pinstTargetIndicator_x                                     0xF0B780
#define pinstCTargetManager_x                                      0xF0B818
#define EQObject_Top_x                                             0xE5C8EC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDA8174
#define pinstCAchievementsWnd_x                                    0xDA8418
#define pinstCActionsWnd_x                                         0xDA83D0
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDA815C
#define pinstCAdvancedLootWnd_x                                    0xDA8104
#define pinstCAdventureLeaderboardWnd_x                            0x1017EA8
#define pinstCAdventureRequestWnd_x                                0x1017F58
#define pinstCAdventureStatsWnd_x                                  0x1018008
#define pinstCAggroMeterWnd_x                                      0xDA843C
#define pinstCAlarmWnd_x                                           0xDA83FC
#define pinstCAlertHistoryWnd_x                                    0xDA83D8
#define pinstCAlertStackWnd_x                                      0xDA8170
#define pinstCAlertWnd_x                                           0xDA8384
#define pinstCAltStorageWnd_x                                      0x1018368
#define pinstCAudioTriggersWindow_x                                0xC65188
#define pinstCAuraWnd_x                                            0xDA8438
#define pinstCAvaZoneWnd_x                                         0xDA83B8
#define pinstCBandolierWnd_x                                       0xDA847C
#define pinstCBankWnd_x                                            0xDA8108
#define pinstCBarterMerchantWnd_x                                  0x10195A8
#define pinstCBarterSearchWnd_x                                    0x1019658
#define pinstCBarterWnd_x                                          0x1019708
#define pinstCBazaarConfirmationWnd_x                              0xDA8168
#define pinstCBazaarSearchWnd_x                                    0xDA83E8
#define pinstCBazaarWnd_x                                          0xDA8474
#define pinstCBlockedBuffWnd_x                                     0xDA80F0
#define pinstCBlockedPetBuffWnd_x                                  0xDA8114
#define pinstCBodyTintWnd_x                                        0xDA8390
#define pinstCBookWnd_x                                            0xDA8904
#define pinstCBreathWnd_x                                          0xDA8388
#define pinstCBuffWindowNORMAL_x                                   0xDA8960
#define pinstCBuffWindowSHORT_x                                    0xDA8964
#define pinstCBugReportWnd_x                                       0xDA8164
#define pinstCButtonWnd_x                                          0x1698E98
#define pinstCCastingWnd_x                                         0xDA8160
#define pinstCCastSpellWnd_x                                       0xDA83F8
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDA8394
#define pinstCChatWindowManager_x                                  0x101A1C8
#define pinstCClaimWnd_x                                           0x101A320
#define pinstCColorPickerWnd_x                                     0xDA83A8
#define pinstCCombatAbilityWnd_x                                   0xDA8448
#define pinstCCombatSkillsSelectWnd_x                              0xDA83CC
#define pinstCCompassWnd_x                                         0xDA817C
#define pinstCConfirmationDialog_x                                 0x101F220
#define pinstCContainerMgr_x                                       0xDA846C
#define pinstCContextMenuManager_x                                 0x1698C60
#define pinstCCursorAttachment_x                                   0xDA8154
#define pinstCDynamicZoneWnd_x                                     0x101A8E8
#define pinstCEditLabelWnd_x                                       0xDA8910
#define pinstCEQMainWnd_x                                          0x101AB30
#define pinstCEventCalendarWnd_x                                   0xDA8434
#define pinstCExtendedTargetWnd_x                                  0xDA8430
#define pinstCFacePick_x                                           0xDA83B0
#define pinstCFellowshipWnd_x                                      0x101AD30
#define pinstCFileSelectionWnd_x                                   0xDA80EC
#define pinstCFindItemWnd_x                                        0xDA8460
#define pinstCFindLocationWnd_x                                    0x101AE88
#define pinstCFriendsWnd_x                                         0xDA83EC
#define pinstCGemsGameWnd_x                                        0xDA83D4
#define pinstCGiveWnd_x                                            0xDA8900
#define pinstCGroupSearchFiltersWnd_x                              0xDA8458
#define pinstCGroupSearchWnd_x                                     0x101B280
#define pinstCGroupWnd_x                                           0x101B330
#define pinstCGuildBankWnd_x                                       0xE6B0F4
#define pinstCGuildCreationWnd_x                                   0x101B490
#define pinstCGuildMgmtWnd_x                                       0x101B540
#define pinstCharacterCreation_x                                   0xDA8440
#define pinstCHelpWnd_x                                            0xDA8408
#define pinstCHeritageSelectionWnd_x                               0xDA83BC
#define pinstCHotButtonWnd_x                                       0x101D698
#define pinstCHotButtonWnd1_x                                      0x101D698
#define pinstCHotButtonWnd2_x                                      0x101D69C
#define pinstCHotButtonWnd3_x                                      0x101D6A0
#define pinstCHotButtonWnd4_x                                      0x101D6A4
#define pinstCIconSelectionWnd_x                                   0xDA8124
#define pinstCInspectWnd_x                                         0xDA8120
#define pinstCInventoryWnd_x                                       0xDA848C
#define pinstCInvSlotMgr_x                                         0xDA8420
#define pinstCItemDisplayManager_x                                 0x101DC28
#define pinstCItemExpTransferWnd_x                                 0x101DD58
#define pinstCItemOverflowWnd_x                                    0xDA83F0
#define pinstCJournalCatWnd_x                                      0xDA8118
//#define pinstCJournalNPCWnd_x                                      0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDA8958
#define pinstCKeyRingWnd_x                                         0xDA896C
#define pinstCLargeDialogWnd_x                                     0x101FEA0
#define pinstCLayoutCopyWnd_x                                      0x101E0A8
#define pinstCLFGuildWnd_x                                         0x101E158
#define pinstCLoadskinWnd_x                                        0xDA83E4
#define pinstCLootFiltersCopyWnd_x                                 0xC761C0
#define pinstCLootFiltersWnd_x                                     0xDA8398
#define pinstCLootSettingsWnd_x                                    0xDA83A4
#define pinstCLootWnd_x                                            0xDA83A0
#define pinstCMailAddressBookWnd_x                                 0xDA812C
#define pinstCMailCompositionWnd_x                                 0xDA810C
#define pinstCMailIgnoreListWnd_x                                  0xDA8130
#define pinstCMailWnd_x                                            0xDA8970
#define pinstCManageLootWnd_x                                      0xDA9770
#define pinstCMapToolbarWnd_x                                      0xDA84F4
#define pinstCMapViewWnd_x                                         0xDA8464
#define pinstCMarketplaceWnd_x                                     0xDA8468
#define pinstCMerchantWnd_x                                        0xDA83C8
#define pinstCMIZoneSelectWnd_x                                    0x101E990
#define pinstCMusicPlayerWnd_x                                     0xDA8968
#define pinstCNameChangeMercWnd_x                                  0xDA8110
#define pinstCNameChangePetWnd_x                                   0xDA80E8
#define pinstCNameChangeWnd_x                                      0xDA8444
#define pinstCNoteWnd_x                                            0xDA8404
#define pinstCObjectPreviewWnd_x                                   0xDA890C
#define pinstCOptionsWnd_x                                         0xDA84F8
#define pinstCPetInfoWnd_x                                         0xDA80FC
#define pinstCPetitionQWnd_x                                       0xDA8128
//#define pinstCPlayerCustomizationWnd_x                             0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDA838C
#define pinstCPlayerWnd_x                                          0xDA83F4
#define pinstCPopupWndManager_x                                    0x101F220
#define pinstCProgressionSelectionWnd_x                            0x101F2D0
#define pinstCPurchaseGroupWnd_x                                   0xDA8974
#define pinstCPurchaseWnd_x                                        0xDA8950
#define pinstCPvPLeaderboardWnd_x                                  0x101F380
#define pinstCPvPStatsWnd_x                                        0x101F430
#define pinstCQuantityWnd_x                                        0xDA8140
#define pinstCRaceChangeWnd_x                                      0xDA8470
#define pinstCRaidOptionsWnd_x                                     0xDA845C
#define pinstCRaidWnd_x                                            0xDA8148
#define pinstCRealEstateItemsWnd_x                                 0xDA8424
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDA8450
#define pinstCRealEstateManageWnd_x                                0xDA83C0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDA83DC
#define pinstCRealEstatePlotSearchWnd_x                            0xDA8400
#define pinstCRealEstatePurchaseWnd_x                              0xDA840C
#define pinstCRespawnWnd_x                                         0xDA8454
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDA842C
#define pinstCSendMoneyWnd_x                                       0xDA8954
#define pinstCServerListWnd_x                                      0xDA841C
#define pinstCSkillsSelectWnd_x                                    0xDA83AC
#define pinstCSkillsWnd_x                                          0xDA839C
#define pinstCSocialEditWnd_x                                      0xDA814C
#define pinstCSocialWnd_x                                          0xDA8150
#define pinstCSpellBookWnd_x                                       0xDA8428
#define pinstCStoryWnd_x                                           0xDA816C
#define pinstCTargetOfTargetWnd_x                                  0x1021260
#define pinstCTargetWnd_x                                          0xDA80F8
#define pinstCTaskOverlayWnd_x                                     0xDA83E0
#define pinstCTaskSelectWnd_x                                      0x10213B8
#define pinstCTaskSomething_x                                      0xC769C0
#define pinstCTaskTemplateSelectWnd_x                              0x1021468
#define pinstCTaskWnd_x                                            0x1021518
#define pinstCTextEntryWnd_x                                       0xDA8380
#define pinstCTextOverlay_x                                        0xC65498
#define pinstCTimeLeftWnd_x                                        0xDA8100
#define pinstCTipWndCONTEXT_x                                      0x102171C
#define pinstCTipWndOFDAY_x                                        0x1021718
#define pinstCTitleWnd_x                                           0x10217C8
#define pinstCTrackingWnd_x                                        0xDA80F4
#define pinstCTradeskillWnd_x                                      0x1021930
#define pinstCTradeWnd_x                                           0xDA8410
#define pinstCTrainWnd_x                                           0xDA8134
#define pinstCTributeBenefitWnd_x                                  0x1021B30
#define pinstCTributeMasterWnd_x                                   0x1021BE0
#define pinstCTributeTrophyWnd_x                                   0x1021C90
#define pinstCVideoModesWnd_x                                      0xDA811C
#define pinstCVoiceMacroWnd_x                                      0xF0BD48
#define pinstCVoteResultsWnd_x                                     0xDA895C
#define pinstCVoteWnd_x                                            0xDA8908
#define pinstCWebManager_x                                         0xF0BEAC
#define pinstCZoneGuideWnd_x                                       0xDA83B4
#define pinstCZonePathWnd_x                                        0xDA83C4

#define pinstEQSuiteTextureLoader_x                                0xC500E0
#define pinstItemIconCache_x                                       0x101AAE8
#define pinstLootFiltersManager_x                                  0xC76270
#define pinstRewardSelectionWnd_x                                  0x101FB78

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC010C4
#define __CastRay_x                                                0x58D670
#define __CastRay2_x                                               0x58D6C0
#define __ConvertItemTags_x                                        0x5A83D0
#define __CrashHandler_x                                           0x83CE40
#define __EQGetTime_x                                              0x8D95A0
#define __ExecuteCmd_x                                             0x586030
#define __FixHeading_x                                             0x96A170
#define __get_bearing_x                                            0x58D1C0
#define __get_melee_range_x                                        0x58D8B0
#define __GetAnimationCache_x                                      0x6FB3B0
#define __GetGaugeValueFromEQ_x                                    0x7EE790
#define __GetLabelFromEQ_x                                         0x7EFF00
#define __GetXTargetType_x                                         0x96BC40
#define __HeadingDiff_x                                            0x96A1E0
#define __HelpPath_x                                               0xF0916C
#define __LoadFrontEnd_x                                           0x693870
#define __NewUIINI_x                                               0x7EE460
#define __pCrashHandler_x                                          0x103EFF8
#define __ProcessGameEvents_x                                      0x5EA910
#define __ProcessMouseEvent_x                                      0x5EA0D0
#define __SaveColors_x                                             0x538050
#define __STMLToText_x                                             0x90D3F0
#define __ToggleKeyRingItem_x                                      0x4FB690
#define CrashDetected_x                                            0x695360
#define DrawNetStatus_x                                            0x616560
#define Expansion_HoT_x                                            0xE6B0FC
#define Teleport_Table_Size_x                                      0xE5A36C
#define Teleport_Table_x                                           0xE5A7C8
#define Util__FastTime_x                                           0x8D9160
#define wwsCrashReportCheckForUploader_x                           0x83DC30
#define wwsCrashReportPlatformLaunchUploader_x                     0x840310
#define __HandleMouseWheel_x                                       0x697AC0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48AA10
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4937F0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4935D0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x53F8F0
#define AltAdvManager__IsAbilityReady_x                            0x53E9C0
#define AltAdvManager__GetAAById_x                                 0x53EBC0
#define AltAdvManager__CanTrainAbility_x                           0x53EC30
#define AltAdvManager__CanSeeAbility_x                             0x53EE60

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C66B0
#define CharacterZoneClient__HasSkill_x                            0x4D1250
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2970
#define CharacterZoneClient__IsStackBlocked_x                      0x4BA960
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B6FF0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D50D0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D51B0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5290
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF590
#define CharacterZoneClient__BardCastBard_x                        0x4C2210
#define CharacterZoneClient__GetMaxEffects_x                       0x4B70C0
#define CharacterZoneClient__GetEffect_x                           0x4B6F30
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C05A0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0670
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C06C0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0810
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C09E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BDB10

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6CB220

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5F8C40
#define CButtonWnd__CButtonWnd_x                                   0x9097E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6E9D90
#define CChatManager__InitContextMenu_x                            0x6E40F0
#define CChatManager__FreeChatWindow_x                             0x6E8CE0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6ED620
#define CChatManager__SetLockedActiveChatWindow_x                  0x6E9B30

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x91DF50
#define CContextMenu__dCContextMenu_x                              0x91E180
#define CContextMenu__AddMenuItem_x                                0x91E190
#define CContextMenu__RemoveMenuItem_x                             0x91E4A0
#define CContextMenu__RemoveAllMenuItems_x                         0x91E4C0
#define CContextMenu__CheckMenuItem_x                              0x91E540
#define CContextMenu__SetMenuItem_x                                0x91E3C0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x91EAE0
#define CContextMenuManager__RemoveMenu_x                          0x91EB50
#define CContextMenuManager__PopupMenu_x                           0x91EC10
#define CContextMenuManager__Flush_x                               0x91EA80
#define CContextMenuManager__GetMenu_x                             0x4959C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BB3B0
#define CChatService__GetFriendName_x                              0x8BB3C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6EA300
#define CChatWindow__Clear_x                                       0x6EB350
#define CChatWindow__WndNotification_x                             0x6EB8B0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x91B3F0
#define CComboWnd__Draw_x                                          0x91A8F0
#define CComboWnd__GetCurChoice_x                                  0x91B230
#define CComboWnd__GetListRect_x                                   0x91ADA0
#define CComboWnd__GetTextRect_x                                   0x91B460
#define CComboWnd__InsertChoice_x                                  0x91AF30
#define CComboWnd__SetColors_x                                     0x91AF00
#define CComboWnd__SetChoice_x                                     0x91B200
#define CComboWnd__GetItemCount_x                                  0x91B240
#define CComboWnd__GetCurChoiceText_x                              0x91B280

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F3520
#define CContainerWnd__vftable_x                                   0xAC79E8
#define CContainerWnd__SetContainer_x                              0x6F4A90

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x537E10
#define CDisplay__GetClickedActor_x                                0x52AE70
#define CDisplay__GetUserDefinedColor_x                            0x523570
#define CDisplay__GetWorldFilePath_x                               0x52C8C0
#define CDisplay__is3dON_x                                         0x527B60
#define CDisplay__ReloadUI_x                                       0x531FE0
#define CDisplay__WriteTextHD2_x                                   0x527940
#define CDisplay__TrueDistance_x                                   0x52E520
#define CDisplay__SetViewActor_x                                   0x52A7C0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x93D960

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x922640
#define CEditWnd__GetCharIndexPt_x                                 0x923540
#define CEditWnd__GetDisplayString_x                               0x9233E0
#define CEditWnd__GetHorzOffset_x                                  0x921C70
#define CEditWnd__GetLineForPrintableChar_x                        0x924680
#define CEditWnd__GetSelStartPt_x                                  0x9237F0
#define CEditWnd__GetSTMLSafeText_x                                0x923200
#define CEditWnd__PointFromPrintableChar_x                         0x9242B0
#define CEditWnd__SelectableCharFromPoint_x                        0x924420
#define CEditWnd__SetEditable_x                                    0x9238C0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5D9470
#define CEverQuest__ClickedPlayer_x                                0x5CB730
#define CEverQuest__CreateTargetIndicator_x                        0x5E7BF0
#define CEverQuest__DeleteTargetIndicator_x                        0x5E7C80
#define CEverQuest__DoTellWindow_x                                 0x4E1530
#define CEverQuest__OutputTextToLog_x                              0x4E1760
#define CEverQuest__DropHeldItemOnGround_x                         0x5C0FF0
#define CEverQuest__dsp_chat_x                                     0x4E1AF0
#define CEverQuest__trimName_x                                     0x5E41B0
#define CEverQuest__Emote_x                                        0x5D9C80
#define CEverQuest__EnterZone_x                                    0x5D3DF0
#define CEverQuest__GetBodyTypeDesc_x                              0x5DDA50
#define CEverQuest__GetClassDesc_x                                 0x5DE090
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DE690
#define CEverQuest__GetDeityDesc_x                                 0x5E6540
#define CEverQuest__GetLangDesc_x                                  0x5DE850
#define CEverQuest__GetRaceDesc_x                                  0x5DE070
#define CEverQuest__InterpretCmd_x                                 0x5E6B10
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C51E0
#define CEverQuest__LMouseUp_x                                     0x5C3560
#define CEverQuest__RightClickedOnPlayer_x                         0x5C5AC0
#define CEverQuest__RMouseUp_x                                     0x5C44F0
#define CEverQuest__SetGameState_x                                 0x5C0D80
#define CEverQuest__UPCNotificationFlush_x                         0x5E40B0
#define CEverQuest__IssuePetCommand_x                              0x5DFC50
#define CEverQuest__ReportSuccessfulHit_x                          0x5DA920

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7054D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x705530
#define CGaugeWnd__Draw_x                                          0x704BC0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABFC0
#define CGuild__GetGuildName_x                                     0x4AB000
#define CGuild__GetGuildIndex_x                                    0x4AB390

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7207F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72D6F0
#define CInvSlotMgr__MoveItem_x                                    0x72C400
#define CInvSlotMgr__SelectSlot_x                                  0x72D7C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x72ACA0
#define CInvSlot__SliderComplete_x                                 0x728AC0
#define CInvSlot__GetItemBase_x                                    0x728430
#define CInvSlot__UpdateItem_x                                     0x7285A0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x72F0F0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x72E3C0
#define CInvSlotWnd__HandleLButtonUp_x                             0x72EC70

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7EA910
#define CItemDisplayWnd__UpdateStrings_x                           0x73CF70
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x736F40
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x737430
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x73D500
#define CItemDisplayWnd__AboutToShow_x                             0x73CBD0
#define CItemDisplayWnd__WndNotification_x                         0x73E820

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8221F0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x742880

// CLabel 
#define CLabel__Draw_x                                             0x7482E0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F3BD0
#define CListWnd__dCListWnd_x                                      0x8F3EF0
#define CListWnd__AddColumn_x                                      0x8F81F0
#define CListWnd__AddColumn1_x                                     0x8F8240
#define CListWnd__AddLine_x                                        0x8F85D0
#define CListWnd__AddString_x                                      0x8F83D0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8F7FC0
#define CListWnd__CalculateVSBRange_x                              0x8F7DB0
#define CListWnd__ClearSel_x                                       0x8F8DB0
#define CListWnd__ClearAllSel_x                                    0x8F8E10
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8F9800
#define CListWnd__Compare_x                                        0x8F76F0
#define CListWnd__Draw_x                                           0x8F3FF0
#define CListWnd__DrawColumnSeparators_x                           0x8F67C0
#define CListWnd__DrawHeader_x                                     0x8F6C30
#define CListWnd__DrawItem_x                                       0x8F7030
#define CListWnd__DrawLine_x                                       0x8F6930
#define CListWnd__DrawSeparator_x                                  0x8F6860
#define CListWnd__EnableLine_x                                     0x8F60A0
#define CListWnd__EnsureVisible_x                                  0x8F9730
#define CListWnd__ExtendSel_x                                      0x8F8CE0
#define CListWnd__GetColumnMinWidth_x                              0x8F5BE0
#define CListWnd__GetColumnWidth_x                                 0x8F5B50
#define CListWnd__GetCurSel_x                                      0x8F54E0
#define CListWnd__GetItemAtPoint_x                                 0x8F6310
#define CListWnd__GetItemAtPoint1_x                                0x8F6380
#define CListWnd__GetItemData_x                                    0x8F5560
#define CListWnd__GetItemHeight_x                                  0x8F5920
#define CListWnd__GetItemIcon_x                                    0x8F56F0
#define CListWnd__GetItemRect_x                                    0x8F6190
#define CListWnd__GetItemText_x                                    0x8F55A0
#define CListWnd__GetSelList_x                                     0x8F8E60
#define CListWnd__GetSeparatorRect_x                               0x8F65C0
#define CListWnd__InsertLine_x                                     0x8F89C0
#define CListWnd__RemoveLine_x                                     0x8F8B10
#define CListWnd__SetColors_x                                      0x8F7D80
#define CListWnd__SetColumnJustification_x                         0x8F7AB0
#define CListWnd__SetColumnWidth_x                                 0x8F79D0
#define CListWnd__SetCurSel_x                                      0x8F8C20
#define CListWnd__SetItemColor_x                                   0x8F93F0
#define CListWnd__SetItemData_x                                    0x8F93B0
#define CListWnd__SetItemText_x                                    0x8F8FE0
#define CListWnd__ShiftColumnSeparator_x                           0x8F7B70
#define CListWnd__Sort_x                                           0x8F7870
#define CListWnd__ToggleSel_x                                      0x8F8C50

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x75D870

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x780820
#define CMerchantWnd__RequestBuyItem_x                             0x781100
#define CMerchantWnd__RequestSellItem_x                            0x781640
#define CMerchantWnd__SelectRecoverySlot_x                         0x784480
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x780E80
#define CMerchantWnd__ActualSelect_x                               0x789FF0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x889650
#define CPacketScrambler__hton_x                                   0x889640

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9129C0
#define CSidlManager__FindScreenPieceTemplate_x                    0x912DD0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x912BC0
#define CSidlManager__CreateLabel_x                                0x7E1DE0
#define CSidlManager__CreateXWndFromTemplate_x                     0x915EA0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x916080

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x90F530
#define CSidlScreenWnd__CalculateVSBRange_x                        0x90F430
#define CSidlScreenWnd__ConvertToRes_x                             0x9341B0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x90EED0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x90EBC0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x90EC90
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x90ED60
#define CSidlScreenWnd__DrawSidlPiece_x                            0x90F9C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x90FE90
#define CSidlScreenWnd__GetSidlPiece_x                             0x90FBB0
#define CSidlScreenWnd__Init1_x                                    0x90E7D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x90FEE0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x910A20
#define CSidlScreenWnd__LoadSidlScreen_x                           0x90DBD0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9105A0
#define CSidlScreenWnd__StoreIniVis_x                              0x910900
#define CSidlScreenWnd__WndNotification_x                          0x90F8D0
#define CSidlScreenWnd__GetChildItem_x                             0x90FE10
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8FF620
#define CSidlScreenWnd__m_layoutCopy_x                             0x1698B30

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65CBF0
#define CSkillMgr__GetSkillCap_x                                   0x65CDD0
#define CSkillMgr__GetNameToken_x                                  0x65C380

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x91F8C0
#define CSliderWnd__SetValue_x                                     0x91F730
#define CSliderWnd__SetNumTicks_x                                  0x91F790

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7E7B90

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x926520
#define CStmlWnd__CalculateHSBRange_x                              0x927590
#define CStmlWnd__CalculateVSBRange_x                              0x927500
#define CStmlWnd__CanBreakAtCharacter_x                            0x92B8C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x92C4B0
#define CStmlWnd__ForceParseNow_x                                  0x926AC0
#define CStmlWnd__GetNextTagPiece_x                                0x92B820
#define CStmlWnd__GetSTMLText_x                                    0x4EF950
#define CStmlWnd__GetVisibleText_x                                 0x926AE0
#define CStmlWnd__InitializeWindowVariables_x                      0x92C300
#define CStmlWnd__MakeStmlColorTag_x                               0x925CB0
#define CStmlWnd__MakeWndNotificationTag_x                         0x925D20
#define CStmlWnd__SetSTMLText_x                                    0x924D80
#define CStmlWnd__StripFirstSTMLLines_x                            0x92D600
#define CStmlWnd__UpdateHistoryString_x                            0x92C6C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x930C60
#define CTabWnd__DrawCurrentPage_x                                 0x931280
#define CTabWnd__DrawTab_x                                         0x931050
#define CTabWnd__GetCurrentPage_x                                  0x9304C0
#define CTabWnd__GetPageInnerRect_x                                0x930700
#define CTabWnd__GetTabInnerRect_x                                 0x930640
#define CTabWnd__GetTabRect_x                                      0x9304F0
#define CTabWnd__InsertPage_x                                      0x9308F0
#define CTabWnd__SetPage_x                                         0x930780
#define CTabWnd__SetPageRect_x                                     0x930BA0
#define CTabWnd__UpdatePage_x                                      0x930F10
#define CTabWnd__GetPageFromTabIndex_x                             0x930F90
#define CTabWnd__GetCurrentTabIndex_x                              0x9304B0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x742CE0
#define CPageWnd__SetTabText_x                                     0x93DD70

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5A40

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8FC4B0
#define CTextureFont__GetTextExtent_x                              0x8FC670

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6905E0
#define CHtmlComponentWnd__ValidateUri_x                           0x7221E0
#define CHtmlWnd__SetClientCallbacks_x                             0x5FDFC0
#define CHtmlWnd__AddObserver_x                                    0x5FDFE0
#define CHtmlWnd__RemoveObserver_x                                 0x5FE040
#define Window__getProgress_x                                      0x83AAB0
#define Window__getStatus_x                                        0x83AAD0
#define Window__getURI_x                                           0x83AAE0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x93A2A0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8E95D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD220
#define CXStr__CXStr1_x                                            0x9ABF10
#define CXStr__CXStr3_x                                            0x8D5690
#define CXStr__dCXStr_x                                            0x4724C0
#define CXStr__operator_equal_x                                    0x8D58C0
#define CXStr__operator_equal1_x                                   0x8D5900
#define CXStr__operator_plus_equal1_x                              0x8D6390

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x91DB70
#define CXWnd__BringToTop_x                                        0x902DA0
#define CXWnd__Center_x                                            0x902920
#define CXWnd__ClrFocus_x                                          0x902750
#define CXWnd__Destroy_x                                           0x902800
#define CXWnd__DoAllDrawing_x                                      0x8FEDC0
#define CXWnd__DrawChildren_x                                      0x8FED90
#define CXWnd__DrawColoredRect_x                                   0x8FF210
#define CXWnd__DrawTooltip_x                                       0x8FD8F0
#define CXWnd__DrawTooltipAtPoint_x                                0x8FD9B0
#define CXWnd__GetBorderFrame_x                                    0x8FF070
#define CXWnd__GetChildWndAt_x                                     0x902E40
#define CXWnd__GetClientClipRect_x                                 0x901030
#define CXWnd__GetScreenClipRect_x                                 0x901100
#define CXWnd__GetScreenRect_x                                     0x9012D0
#define CXWnd__GetTooltipRect_x                                    0x8FF260
#define CXWnd__GetWindowTextA_x                                    0x497060
#define CXWnd__IsActive_x                                          0x905CF0
#define CXWnd__IsDescendantOf_x                                    0x901CC0
#define CXWnd__IsReallyVisible_x                                   0x901CF0
#define CXWnd__IsType_x                                            0x9034A0
#define CXWnd__Move_x                                              0x901D70
#define CXWnd__Move1_x                                             0x901E20
#define CXWnd__ProcessTransition_x                                 0x9028D0
#define CXWnd__Refade_x                                            0x9020E0
#define CXWnd__Resize_x                                            0x902370
#define CXWnd__Right_x                                             0x902B60
#define CXWnd__SetFocus_x                                          0x902710
#define CXWnd__SetFont_x                                           0x902780
#define CXWnd__SetKeyTooltip_x                                     0x9032B0
#define CXWnd__SetMouseOver_x                                      0x9001A0
#define CXWnd__StartFade_x                                         0x901B90
#define CXWnd__GetChildItem_x                                      0x902FA0
#define CXWnd__SetParent_x                                         0x901A60

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x935280

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x905D30
#define CXWndManager__DrawWindows_x                                0x905D50
#define CXWndManager__GetKeyboardFlags_x                           0x9084B0
#define CXWndManager__HandleKeyboardMsg_x                          0x9080C0
#define CXWndManager__RemoveWnd_x                                  0x908700
#define CXWndManager__RemovePendingDeletionWnd_x                   0x908C60

// CDBStr
#define CDBStr__GetString_x                                        0x522540

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B7FA0
#define EQ_Character__Cur_HP_x                                     0x4CE2D0
#define EQ_Character__Cur_Mana_x                                   0x4D5790
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BB0F0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AEE20
#define EQ_Character__GetFocusRangeModifier_x                      0x4AEF70
#define EQ_Character__GetHPRegen_x                                 0x4DAE60
#define EQ_Character__GetEnduranceRegen_x                          0x4DB470
#define EQ_Character__GetManaRegen_x                               0x4DB8B0
#define EQ_Character__Max_Endurance_x                              0x623BB0
#define EQ_Character__Max_HP_x                                     0x4CE100
#define EQ_Character__Max_Mana_x                                   0x6239B0
#define EQ_Character__doCombatAbility_x                            0x625D60
#define EQ_Character__UseSkill_x                                   0x4DD6C0
#define EQ_Character__GetConLevel_x                                0x61D230
#define EQ_Character__IsExpansionFlag_x                            0x5849F0
#define EQ_Character__TotalEffect_x                                0x4C1790
#define EQ_Character__GetPCSpellAffect_x                           0x4BBCE0
#define EQ_Character__SpellDuration_x                              0x4BB810
#define EQ_Character__FindItemByRecord_x                           0x4D38E0
#define EQ_Character__GetAdjustedSkill_x                           0x4D1010
#define EQ_Character__GetBaseSkill_x                               0x4D1FB0
#define EQ_Character__CanUseItem_x                                 0x4D5AA0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8A8610

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x639A80

//PcClient
#define PcClient__PcClient_x                                       0x61AB00

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B5D80
#define CCharacterListWnd__EnterWorld_x                            0x4B57C0
#define CCharacterListWnd__Quit_x                                  0x4B54D0
#define CCharacterListWnd__UpdateList_x                            0x4B5950

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5FF1D0
#define EQ_Item__CreateItemTagString_x                             0x8839B0
#define EQ_Item__IsStackable_x                                     0x887B20
#define EQ_Item__GetImageNum_x                                     0x885180
#define EQ_Item__CreateItemClient_x                                0x5FE3A0
#define EQ_Item__GetItemValue_x                                    0x886210
#define EQ_Item__ValueSellMerchant_x                               0x8891F0
#define EQ_Item__IsKeyRingItem_x                                   0x8874E0
#define EQ_Item__CanGoInBag_x                                      0x5FF2F0
#define EQ_Item__GetMaxItemCount_x                                 0x886310
#define EQ_Item__GetHeldItem_x                                     0x885050
#define EQ_Item__GetAugmentFitBySlot_x                             0x8834F0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x540620
#define EQ_LoadingS__Array_x                                       0xBD8298

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x624510
#define EQ_PC__GetAlternateAbilityId_x                             0x8922A0
#define EQ_PC__GetCombatAbility_x                                  0x892910
#define EQ_PC__GetCombatAbilityTimer_x                             0x892980
#define EQ_PC__GetItemRecastTimer_x                                0x6262E0
#define EQ_PC__HasLoreItem_x                                       0x61D9F0
#define EQ_PC__AlertInventoryChanged_x                             0x61CD10
#define EQ_PC__GetPcZoneClient_x                                   0x648320
#define EQ_PC__RemoveMyAffect_x                                    0x629420
#define EQ_PC__GetKeyRingItems_x                                   0x893220
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x892FA0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x893510

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58AC10
#define EQItemList__add_object_x                                   0x5B67B0
#define EQItemList__add_item_x                                     0x58B220
#define EQItemList__delete_item_x                                  0x58B270
#define EQItemList__FreeItemList_x                                 0x58B170

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x51FBA0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x63B300
#define EQPlayer__dEQPlayer_x                                      0x62EA40
#define EQPlayer__DoAttack_x                                       0x643030
#define EQPlayer__EQPlayer_x                                       0x62F0F0
#define EQPlayer__SetNameSpriteState_x                             0x633370
#define EQPlayer__SetNameSpriteTint_x                              0x634200
#define PlayerBase__HasProperty_j_x                                0x968530
#define EQPlayer__IsTargetable_x                                   0x9689D0
#define EQPlayer__CanSee_x                                         0x968830
#define EQPlayer__CanSee1_x                                        0x968900
#define PlayerBase__GetVisibilityLineSegment_x                     0x9685F0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x645DF0
#define PlayerZoneClient__GetLevel_x                               0x648360
#define PlayerZoneClient__IsValidTeleport_x                        0x5B7900
#define PlayerZoneClient__LegalPlayerRace_x                        0x539BF0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x63E130
#define EQPlayerManager__GetSpawnByName_x                          0x63E150
#define EQPlayerManager__GetPlayerFromPartialName_x                0x63E1E0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x602BA0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x602BE0
#define KeypressHandler__ClearCommandStateArray_x                  0x603FD0
#define KeypressHandler__HandleKeyDown_x                           0x603FF0
#define KeypressHandler__HandleKeyUp_x                             0x604090
#define KeypressHandler__SaveKeymapping_x                          0x604470

// MapViewMap 
#define MapViewMap__Clear_x                                        0x759700
#define MapViewMap__SaveEx_x                                       0x75CAA0
#define MapViewMap__SetZoom_x                                      0x761160

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A6500

// StringTable 
#define StringTable__getString_x                                   0x8A14C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x629090
#define PcZoneClient__RemovePetEffect_x                            0x6296C0
#define PcZoneClient__HasAlternateAbility_x                        0x6237F0
#define PcZoneClient__GetCurrentMod_x                              0x4E0620
#define PcZoneClient__GetModCap_x                                  0x4E0520
#define PcZoneClient__CanEquipItem_x                               0x623EA0
#define PcZoneClient__GetItemByID_x                                0x626760
#define PcZoneClient__GetItemByItemClass_x                         0x6267F0
#define PcZoneClient__RemoveBuffEffect_x                           0x6296E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BC4D0

//IconCache
#define IconCache__GetIcon_x                                       0x6FAC40

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F26C0
#define CContainerMgr__CloseContainer_x                            0x6F2990
#define CContainerMgr__OpenExperimentContainer_x                   0x6F3410

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B4550

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F7420

//CLootWnd
#define CLootWnd__LootAll_x                                        0x74FC20
#define CLootWnd__RequestLootSlot_x                                0x74EFD0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x558AE0
#define EQ_Spell__SpellAffects_x                                   0x558F50
#define EQ_Spell__SpellAffectBase_x                                0x558D10
#define EQ_Spell__IsStackable_x                                    0x4C5FB0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5E60
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3340
#define EQ_Spell__IsSPAStacking_x                                  0x559D00
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5592A0
#define EQ_Spell__IsNoRemove_x                                     0x4C5F90
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x559D10
#define __IsResEffectSpell_x                                       0x4C5300

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9C50

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B08A0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7F9CC0
#define CTargetWnd__WndNotification_x                              0x7F9550
#define CTargetWnd__RefreshTargetBuffs_x                           0x7F9820
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7F86B0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7FE380

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x554070
#define EqSoundManager__PlayScriptMp3_x                            0x5541D0
#define EqSoundManager__SoundAssistPlay_x                          0x6607F0
#define EqSoundManager__WaveInstancePlay_x                         0x65FCA0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x511590

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9212A0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x548210
#define CAltAbilityData__GetMercMaxRank_x                          0x5481B0
#define CAltAbilityData__GetMaxRank_x                              0x53D8F0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F5530

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5E40
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F7AD0
#define CharacterBase__CreateItemIndex_x                           0x5FD5C0
#define CharacterBase__GetItemPossession_x                         0x4B31F0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8B8E10
#define CharacterBase__GetEffectId_x                               0x4C5DF0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DABC0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6DB3E0

//messages
#define msg_spell_worn_off_x                                       0x57D2C0
#define msg_new_text_x                                             0x5724A0
#define __msgTokenTextParam_x                                      0x57F910
#define msgTokenText_x                                             0x57FB60

//SpellManager
#define SpellManager__vftable_x                                    0xAA2850
#define SpellManager__SpellManager_x                               0x663AF0
#define Spellmanager__LoadTextSpells_x                             0x664350
#define SpellManager__GetSpellByGroupAndRank_x                     0x663CC0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x96C530

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F8180
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x583090
#define ItemGlobalIndex__IsEquippedLocation_x                      0x6163C0
#define ItemGlobalIndex__IsValidIndex_x                            0x4F81E0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B11E0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B1460

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x748630

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F6DF0
#define CCursorAttachment__Deactivate_x                            0x6F7DD0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9333A0
#define CEQSuiteTextureLoader__GetTexture_x                        0x933060

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F5180

//IString
#define IString__Append_x                                          0x4E9930

//Camera
#define CDisplay__cameraType_x                                     0xDA8178
#define EverQuest__Cameras_x                                       0xE6B41C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FD910
#define LootFiltersManager__GetItemFilterData_x                    0x4FD200
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FD230
#define LootFiltersManager__SetItemLootFilter_x                    0x4FD450

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A25B0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x972230
#define CResolutionHandler__GetWindowedStyle_x                     0x65B7B0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6EF490

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
