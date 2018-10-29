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
#define __ExpectedVersionDate                                     "Oct 26 2018"
#define __ExpectedVersionTime                                     "10:16:03"
#define __ActualVersionDate_x                                      0xABF69C
#define __ActualVersionTime_x                                      0xABF690

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x608F60
#define __MemChecker1_x                                            0x8DAB60
#define __MemChecker2_x                                            0x6973C0
#define __MemChecker3_x                                            0x697310
#define __MemChecker4_x                                            0x832C40
#define __EncryptPad0_x                                            0xBF14C0
#define __EncryptPad1_x                                            0xC4F1A0
#define __EncryptPad2_x                                            0xC02048
#define __EncryptPad3_x                                            0xC01C48
#define __EncryptPad4_x                                            0xC3FF38
#define __EncryptPad5_x                                            0x1017E54
#define __AC1_x                                                    0x7EF946
#define __AC2_x                                                    0x5C4ADF
#define __AC3_x                                                    0x5CB96F
#define __AC4_x                                                    0x5CF7E0
#define __AC5_x                                                    0x5D599F
#define __AC6_x                                                    0x5D9ED6
#define __AC7_x                                                    0x5C4550
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1EB6CDC

// Direct Input
#define DI8__Main_x                                                0x1017E74
#define DI8__Keyboard_x                                            0x1017E78
#define DI8__Mouse_x                                               0xF0CD30
#define DI8__Mouse_Copy_x                                          0xE6AA8C
#define DI8__Mouse_Check_x                                         0xF0DAE0
#define __AutoSkillArray_x                                         0xE6B9A4
#define __Attack_x                                                 0xF097A7
#define __Autofire_x                                               0xF097A8
#define __BindList_x                                               0xBE00C0
#define g_eqCommandStates_x                                        0xBE0E30
#define __Clicks_x                                                 0xE6AB44
#define __CommandList_x                                            0xBE19E8
#define __CurrentMapLabel_x                                        0x101F354
#define __CurrentSocial_x                                          0xBCB734
#define __DoAbilityList_x                                          0xEA12C8
#define __do_loot_x                                                0x5922A0
#define __DrawHandler_x                                            0x169A888
#define __GroupCount_x                                             0xE5ADBA
#define __Guilds_x                                                 0xE61298
#define __gWorld_x                                                 0xE5CFB4
#define __HWnd_x                                                   0xF0CD34
#define __heqmain_x                                                0x1017E3C
#define __InChatMode_x                                             0xE6AA74
#define __LastTell_x                                               0xE6C9C4
#define __LMouseHeldTime_x                                         0xE6ABB0
#define __Mouse_x                                                  0x1017E60
#define __MouseLook_x                                              0xE6AB0A
#define __MouseEventTime_x                                         0xF0A260
#define __gpbCommandEvent_x                                        0xE5D1CC
#define __NetStatusToggle_x                                        0xE6AB0D
#define __PCNames_x                                                0xE6BF84
#define __RangeAttackReady_x                                       0xE6BC88
#define __RMouseHeldTime_x                                         0xE6ABAC
#define __RunWalkState_x                                           0xE6AA78
#define __ScreenMode_x                                             0xDA9614
#define __ScreenX_x                                                0xE6AA2C
#define __ScreenY_x                                                0xE6AA28
#define __ScreenXMax_x                                             0xE6AA30
#define __ScreenYMax_x                                             0xE6AA34
#define __ServerHost_x                                             0xE5D31B
#define __ServerName_x                                             0xEA1288
#define __ShiftKeyDown_x                                           0xE6B104
#define __ShowNames_x                                              0xE6BE44
#define __Socials_x                                                0xEA1388
#define __SubscriptionType_x                                       0x1060E1C
#define __TargetAggroHolder_x                                      0x1021D0C
#define __ZoneType_x                                               0xE6AF08
#define __GroupAggro_x                                             0x1021D4C
#define __LoginName_x                                              0xF0D474
#define __Inviter_x                                                0xF09724
#define __AttackOnAssist_x                                         0xE6BE00
#define __UseTellWindows_x                                         0xE6C11C
#define __gfMaxZoomCameraDistance_x                                0xAB4AE0
#define __gfMaxCameraDistance_x                                    0xAE20A8
#define __pulAutoRun_x                                             0xE6AB28
#define __pulForward_x                                             0xE6C154
#define __pulBackward_x                                            0xE6C158
#define __pulTurnRight_x                                           0xE6C15C
#define __pulTurnLeft_x                                            0xE6C160
#define __pulStrafeLeft_x                                          0xE6C164
#define __pulStrafeRight_x                                         0xE6C168

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE5D630
#define instEQZoneInfo_x                                           0xE6AD00
#define instKeypressHandler_x                                      0xF0A210
#define pinstActiveBanker_x                                        0xE5AD30
#define pinstActiveCorpse_x                                        0xE5AD28
#define pinstActiveGMaster_x                                       0xE5AD2C
#define pinstActiveMerchant_x                                      0xE5AD24
#define pinstAggroInfo_x                                           0xC659B8
#define pinstAltAdvManager_x                                       0xDA9FD0
#define pinstAuraMgr_x                                             0xC766A0
#define pinstBandageTarget_x                                       0xE5AD40
#define pinstCamActor_x                                            0xDA9608
#define pinstCDBStr_x                                              0xDA8D0C
#define pinstCDisplay_x                                            0xE5AD84
#define pinstCEverQuest_x                                          0x1017F90
#define pinstEverQuestInfo_x                                       0xE6AA20
#define pinstCharData_x                                            0xE5AD8C
#define pinstCharSpawn_x                                           0xE5AD78
#define pinstControlledMissile_x                                   0xE5AD90
#define pinstControlledPlayer_x                                    0xE5AD78
#define pinstCResolutionHandler_x                                  0x169AAB8
#define pinstCSidlManager_x                                        0x169994C
#define pinstCXWndManager_x                                        0x1699940
#define instDynamicZone_x                                          0xE61170
#define pinstDZMember_x                                            0xE61280
#define pinstDZTimerInfo_x                                         0xE61284
#define pinstEQItemList_x                                          0xE59820
#define pinstEQObjectList_x                                        0xE5AA10
#define instEQMisc_x                                               0xDA8C48
#define pinstEQSoundManager_x                                      0xDAA830
#define pinstEQSpellStrings_x                                      0xC73AF0
#define instExpeditionLeader_x                                     0xE611BA
#define instExpeditionName_x                                       0xE611FA
#define pinstGroup_x                                               0xE5ADB6
#define pinstImeManager_x                                          0x1699944
#define pinstLocalPlayer_x                                         0xE5AD20
#define pinstMercenaryData_x                                       0xF0AA00
#define pinstMercenaryStats_x                                      0x1021E58
#define pinstMercAltAbilities_x                                    0xDAA5A0
#define pinstModelPlayer_x                                         0xE5AD38
#define pinstPCData_x                                              0xE5AD8C
#define pinstRealEstateItems_x                                     0xF0BEF0
#define pinstSkillMgr_x                                            0xF0BFC0
#define pinstSpawnManager_x                                        0xF0B5B0
#define pinstSpellManager_x                                        0xF0C198
#define pinstSpellSets_x                                           0xF023D0
#define pinstStringTable_x                                         0xE5D01C
#define pinstSwitchManager_x                                       0xE5ABD0
#define pinstTarget_x                                              0xE5AD74
#define pinstTargetObject_x                                        0xE5AD80
#define pinstTargetSwitch_x                                        0xE5AD98
#define pinstTaskMember_x                                          0xDA8AD8
#define pinstTrackTarget_x                                         0xE5AD7C
#define pinstTradeTarget_x                                         0xE5AD34
#define instTributeActive_x                                        0xDA8C6D
#define pinstViewActor_x                                           0xDA9600
#define pinstWorldData_x                                           0xE5ADA4
#define pinstZoneAddr_x                                            0xE6AFA0
#define pinstPlayerPath_x                                          0xF0B648
#define pinstTargetIndicator_x                                     0xF0C400
#define pinstCTargetManager_x                                      0xF0C498
#define EQObject_Top_x                                             0xE5D424
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDA9594
#define pinstCAchievementsWnd_x                                    0xDA8DC8
#define pinstCActionsWnd_x                                         0xDA95F4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDA9580
#define pinstCAdvancedLootWnd_x                                    0xDA9548
#define pinstCAdventureLeaderboardWnd_x                            0x1018B28
#define pinstCAdventureRequestWnd_x                                0x1018BD8
#define pinstCAdventureStatsWnd_x                                  0x1018C88
#define pinstCAggroMeterWnd_x                                      0xDA8E04
#define pinstCAlarmWnd_x                                           0xDA8DB4
#define pinstCAlertHistoryWnd_x                                    0xDA9634
#define pinstCAlertStackWnd_x                                      0xDA95A8
#define pinstCAlertWnd_x                                           0xDA95B8
#define pinstCAltStorageWnd_x                                      0x1018FE8
#define pinstCAudioTriggersWindow_x                                0xC65E48
#define pinstCAuraWnd_x                                            0xDA8DFC
#define pinstCAvaZoneWnd_x                                         0xDA95F0
#define pinstCBandolierWnd_x                                       0xDA9040
#define pinstCBankWnd_x                                            0xDA9540
#define pinstCBarterMerchantWnd_x                                  0x101A228
#define pinstCBarterSearchWnd_x                                    0x101A2D8
#define pinstCBarterWnd_x                                          0x101A388
#define pinstCBazaarConfirmationWnd_x                              0xDA95A0
#define pinstCBazaarSearchWnd_x                                    0xDA9620
#define pinstCBazaarWnd_x                                          0xDA903C
#define pinstCBlockedBuffWnd_x                                     0xDA9524
#define pinstCBlockedPetBuffWnd_x                                  0xDA954C
#define pinstCBodyTintWnd_x                                        0xDA95B4
#define pinstCBookWnd_x                                            0xDA9064
#define pinstCBreathWnd_x                                          0xDA95A4
#define pinstCBuffWindowNORMAL_x                                   0xDA94E8
#define pinstCBuffWindowSHORT_x                                    0xDA94EC
#define pinstCBugReportWnd_x                                       0xDA958C
#define pinstCButtonWnd_x                                          0x1699B38
#define pinstCCastingWnd_x                                         0xDA9588
#define pinstCCastSpellWnd_x                                       0xDA8DAC
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDA95B0
#define pinstCChatWindowManager_x                                  0x101AE48
#define pinstCClaimWnd_x                                           0x101AFA0
#define pinstCColorPickerWnd_x                                     0xDA95CC
#define pinstCCombatAbilityWnd_x                                   0xDA8E0C
#define pinstCCombatSkillsSelectWnd_x                              0xDA95EC
#define pinstCCompassWnd_x                                         0xDA9598
#define pinstCConfirmationDialog_x                                 0x101FEA0
#define pinstCContainerMgr_x                                       0xDA9034
#define pinstCContextMenuManager_x                                 0x1699900
#define pinstCCursorAttachment_x                                   0xDA957C
#define pinstCDistillerInfo_x                                      0x101E8AC
#define pinstCDynamicZoneWnd_x                                     0x101B568
#define pinstCEditLabelWnd_x                                       0xDA94D4
#define pinstCEQMainWnd_x                                          0x101B7B0
#define pinstCEventCalendarWnd_x                                   0xDA8E14
#define pinstCExtendedTargetWnd_x                                  0xDA8DF4
#define pinstCFacePick_x                                           0xDA95D4
#define pinstCFellowshipWnd_x                                      0x101B9B0
#define pinstCFileSelectionWnd_x                                   0xDA9528
#define pinstCFindItemWnd_x                                        0xDA902C
#define pinstCFindLocationWnd_x                                    0x101BB08
#define pinstCFriendsWnd_x                                         0xDA9624
#define pinstCGemsGameWnd_x                                        0xDA95F8
#define pinstCGiveWnd_x                                            0xDA9050
#define pinstCGroupSearchFiltersWnd_x                              0xDA9020
#define pinstCGroupSearchWnd_x                                     0x101BF00
#define pinstCGroupWnd_x                                           0x101BFB0
#define pinstCGuildBankWnd_x                                       0xE6BDE4
#define pinstCGuildCreationWnd_x                                   0x101C110
#define pinstCGuildMgmtWnd_x                                       0x101C1C0
#define pinstCharacterCreation_x                                   0xDA8E08
#define pinstCHelpWnd_x                                            0xDA8DBC
#define pinstCHeritageSelectionWnd_x                               0xDA95DC
#define pinstCHotButtonWnd_x                                       0x101E318
#define pinstCHotButtonWnd1_x                                      0x101E318
#define pinstCHotButtonWnd2_x                                      0x101E31C
#define pinstCHotButtonWnd3_x                                      0x101E320
#define pinstCHotButtonWnd4_x                                      0x101E324
#define pinstCIconSelectionWnd_x                                   0xDA955C
#define pinstCInspectWnd_x                                         0xDA9554
#define pinstCInventoryWnd_x                                       0xDA9044
#define pinstCInvSlotMgr_x                                         0xDA8DD0
#define pinstCItemDisplayManager_x                                 0x101E8A8
#define pinstCItemExpTransferWnd_x                                 0x101E9DC
#define pinstCItemOverflowWnd_x                                    0xDA9628
#define pinstCJournalCatWnd_x                                      0xDA9550
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDA94E4
#define pinstCKeyRingWnd_x                                         0xDA9518
#define pinstCLargeDialogWnd_x                                     0x1020B20
#define pinstCLayoutCopyWnd_x                                      0x101ED28
#define pinstCLFGuildWnd_x                                         0x101EDD8
#define pinstCLoadskinWnd_x                                        0xDA9630
#define pinstCLootFiltersCopyWnd_x                                 0xC76E80
#define pinstCLootFiltersWnd_x                                     0xDA95C8
#define pinstCLootSettingsWnd_x                                    0xDA95D8
#define pinstCLootWnd_x                                            0xDA95C0
#define pinstCMailAddressBookWnd_x                                 0xDA9560
#define pinstCMailCompositionWnd_x                                 0xDA9544
#define pinstCMailIgnoreListWnd_x                                  0xDA9564
#define pinstCMailWnd_x                                            0xDA951C
#define pinstCManageLootWnd_x                                      0xDAA448
#define pinstCMapToolbarWnd_x                                      0xDA9048
#define pinstCMapViewWnd_x                                         0xDA9028
#define pinstCMarketplaceWnd_x                                     0xDA9030
#define pinstCMerchantWnd_x                                        0xDA95E8
#define pinstCMIZoneSelectWnd_x                                    0x101F610
#define pinstCMusicPlayerWnd_x                                     0xDA9510
#define pinstCNameChangeMercWnd_x                                  0xDA9558
#define pinstCNameChangePetWnd_x                                   0xDA953C
#define pinstCNameChangeWnd_x                                      0xDA8E00
#define pinstCNoteWnd_x                                            0xDA8DB8
#define pinstCObjectPreviewWnd_x                                   0xDA90CC
#define pinstCOptionsWnd_x                                         0xDA904C
#define pinstCPetInfoWnd_x                                         0xDA9534
#define pinstCPetitionQWnd_x                                       0xDA9568
//#define pinstCPlayerCustomizationWnd_x                             0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDA95AC
#define pinstCPlayerWnd_x                                          0xDA962C
#define pinstCPopupWndManager_x                                    0x101FEA0
#define pinstCProgressionSelectionWnd_x                            0x101FF50
#define pinstCPurchaseGroupWnd_x                                   0xDA9514
#define pinstCPurchaseWnd_x                                        0xDA94D8
#define pinstCPvPLeaderboardWnd_x                                  0x1020000
#define pinstCPvPStatsWnd_x                                        0x10200B0
#define pinstCQuantityWnd_x                                        0xDA9570
#define pinstCRaceChangeWnd_x                                      0xDA9038
#define pinstCRaidOptionsWnd_x                                     0xDA9024
#define pinstCRaidWnd_x                                            0xDA9574
#define pinstCRealEstateItemsWnd_x                                 0xDA8DD4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDA8E10
#define pinstCRealEstateManageWnd_x                                0xDA95E0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDA95FC
#define pinstCRealEstatePlotSearchWnd_x                            0xDA8DA8
#define pinstCRealEstatePurchaseWnd_x                              0xDA8DC0
#define pinstCRespawnWnd_x                                         0xDA8E1C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDA8DF0
#define pinstCSendMoneyWnd_x                                       0xDA94DC
#define pinstCServerListWnd_x                                      0xDA8DD8
#define pinstCSkillsSelectWnd_x                                    0xDA95D0
#define pinstCSkillsWnd_x                                          0xDA95BC
#define pinstCSocialEditWnd_x                                      0xDA9578
#define pinstCSocialWnd_x                                          0xDA9584
#define pinstCSpellBookWnd_x                                       0xDA8DEC
#define pinstCStoryWnd_x                                           0xDA9590
#define pinstCTargetOfTargetWnd_x                                  0x1021EE0
#define pinstCTargetWnd_x                                          0xDA9530
#define pinstCTaskOverlayWnd_x                                     0xDA8DB0
#define pinstCTaskSelectWnd_x                                      0x1022038
#define pinstCTaskSomething_x                                      0xC77680
#define pinstCTaskTemplateSelectWnd_x                              0x10220E8
#define pinstCTaskWnd_x                                            0x1022198
#define pinstCTextEntryWnd_x                                       0xDA959C
#define pinstCTextOverlay_x                                        0xC66158
#define pinstCTimeLeftWnd_x                                        0xDA9538
#define pinstCTipWndCONTEXT_x                                      0x102239C
#define pinstCTipWndOFDAY_x                                        0x1022398
#define pinstCTitleWnd_x                                           0x1022448
#define pinstCTrackingWnd_x                                        0xDA952C
#define pinstCTradeskillWnd_x                                      0x10225B0
#define pinstCTradeWnd_x                                           0xDA8DC4
#define pinstCTrainWnd_x                                           0xDA956C
#define pinstCTributeBenefitWnd_x                                  0x10227B0
#define pinstCTributeMasterWnd_x                                   0x1022860
#define pinstCTributeTrophyWnd_x                                   0x1022910
#define pinstCVideoModesWnd_x                                      0xDA8DCC
#define pinstCVoiceMacroWnd_x                                      0xF0C9C8
#define pinstCVoteResultsWnd_x                                     0xDA9520
#define pinstCVoteWnd_x                                            0xDA94E0
#define pinstCWebManager_x                                         0xF0CB2C
#define pinstCZoneGuideWnd_x                                       0xDA95E4
#define pinstCZonePathWnd_x                                        0xDA9604

#define pinstEQSuiteTextureLoader_x                                0xC50C58
#define pinstItemIconCache_x                                       0x101B768
#define pinstLootFiltersManager_x                                  0xC76F30
#define pinstRewardSelectionWnd_x                                  0x10207F8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC01C3C
#define __CastRay_x                                                0x58D7C0
#define __CastRay2_x                                               0x58D810
#define __ConvertItemTags_x                                        0x5A83A0
#define __CrashHandler_x                                           0x83C580
#define __EQGetTime_x                                              0x8DA650
#define __ExecuteCmd_x                                             0x5861A0
#define __FixHeading_x                                             0x96B040
#define __get_bearing_x                                            0x58D300
#define __get_melee_range_x                                        0x58DA00
#define __GetAnimationCache_x                                      0x6FAF60
#define __GetGaugeValueFromEQ_x                                    0x7EE160
#define __GetLabelFromEQ_x                                         0x7EF8D0
#define __GetXTargetType_x                                         0x96CAA0
#define __HandleMouseWheel_x                                       0x697470
#define __HeadingDiff_x                                            0x96B0B0
#define __HelpPath_x                                               0xF09E7C
#define __LoadFrontEnd_x                                           0x693220
#define __NewUIINI_x                                               0x7EDE30
#define __pCrashHandler_x                                          0x103FC78
#define __ProcessGameEvents_x                                      0x5EA990
#define __ProcessMouseEvent_x                                      0x5EA150
#define __SaveColors_x                                             0x5380F0
#define __STMLToText_x                                             0x90E0E0
#define __ToggleKeyRingItem_x                                      0x4FB1C0
#define CrashDetected_x                                            0x694D10
#define DrawNetStatus_x                                            0x616320
#define Expansion_HoT_x                                            0xE6BDEC
#define Teleport_Table_Size_x                                      0xE5D1D8
#define Teleport_Table_x                                           0xE5AFB0
#define Util__FastTime_x                                           0x8DA210
#define wwsCrashReportCheckForUploader_x                           0x83D410
#define wwsCrashReportPlatformLaunchUploader_x                     0x83FAF0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48A960
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493740
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493520

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x53FAB0
#define AltAdvManager__IsAbilityReady_x                            0x53EB30
#define AltAdvManager__GetAAById_x                                 0x53ED30
#define AltAdvManager__CanTrainAbility_x                           0x53EDA0
#define AltAdvManager__CanSeeAbility_x                             0x53EFD0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6390
#define CharacterZoneClient__HasSkill_x                            0x4D0F30
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2650
#define CharacterZoneClient__IsStackBlocked_x                      0x4BA7B0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B6F30
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D4D80
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D4E60
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D4F40
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF290
#define CharacterZoneClient__BardCastBard_x                        0x4C1EF0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7000
#define CharacterZoneClient__GetEffect_x                           0x4B6E70
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0290
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0360
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C03B0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C0500
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C06D0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BD4A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6CAC10

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5F8D80
#define CButtonWnd__CButtonWnd_x                                   0x90A4E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6E9870
#define CChatManager__InitContextMenu_x                            0x6E3910
#define CChatManager__FreeChatWindow_x                             0x6E8780
#define CChatManager__GetLockedActiveChatWindow_x                  0x6ED120
#define CChatManager__SetLockedActiveChatWindow_x                  0x6E9610

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x91ED60
#define CContextMenu__dCContextMenu_x                              0x91EF90
#define CContextMenu__AddMenuItem_x                                0x91EFA0
#define CContextMenu__RemoveMenuItem_x                             0x91F2B0
#define CContextMenu__RemoveAllMenuItems_x                         0x91F2D0
#define CContextMenu__CheckMenuItem_x                              0x91F350
#define CContextMenu__SetMenuItem_x                                0x91F1D0
#define CContextMenu__AddSeparator_x                               0x91F130

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x91F8E0
#define CContextMenuManager__RemoveMenu_x                          0x91F950
#define CContextMenuManager__PopupMenu_x                           0x91FA10
#define CContextMenuManager__Flush_x                               0x91F880
#define CContextMenuManager__GetMenu_x                             0x495960

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BB180
#define CChatService__GetFriendName_x                              0x8BB190

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6E9DE0
#define CChatWindow__Clear_x                                       0x6EAE40
#define CChatWindow__WndNotification_x                             0x6EB3B0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x91C1E0
#define CComboWnd__Draw_x                                          0x91B6E0
#define CComboWnd__GetCurChoice_x                                  0x91C020
#define CComboWnd__GetListRect_x                                   0x91BB80
#define CComboWnd__GetTextRect_x                                   0x91C250
#define CComboWnd__InsertChoice_x                                  0x91BD10
#define CComboWnd__SetColors_x                                     0x91BCE0
#define CComboWnd__SetChoice_x                                     0x91BFF0
#define CComboWnd__GetItemCount_x                                  0x91C030
#define CComboWnd__GetCurChoiceText_x                              0x91C070

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F3150
#define CContainerWnd__vftable_x                                   0xAC8A88
#define CContainerWnd__SetContainer_x                              0x6F46C0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x537EB0
#define CDisplay__GetClickedActor_x                                0x52AF10
#define CDisplay__GetUserDefinedColor_x                            0x5235F0
#define CDisplay__GetWorldFilePath_x                               0x52C960
#define CDisplay__is3dON_x                                         0x527BE0
#define CDisplay__ReloadUI_x                                       0x532080
#define CDisplay__WriteTextHD2_x                                   0x5279C0
#define CDisplay__TrueDistance_x                                   0x52E5C0
#define CDisplay__SetViewActor_x                                   0x52A860
#define CDisplay__GetFloorHeight_x                                 0x527CA0
#define CDisplay__SetRenderWindow_x                                0x5265D0
#define CDisplay__ToggleScreenshotMode_x                           0x52A330

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x93E760

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x923440
#define CEditWnd__GetCharIndexPt_x                                 0x924330
#define CEditWnd__GetDisplayString_x                               0x9241D0
#define CEditWnd__GetHorzOffset_x                                  0x922A70
#define CEditWnd__GetLineForPrintableChar_x                        0x925440
#define CEditWnd__GetSelStartPt_x                                  0x9245E0
#define CEditWnd__GetSTMLSafeText_x                                0x923FF0
#define CEditWnd__PointFromPrintableChar_x                         0x925080
#define CEditWnd__SelectableCharFromPoint_x                        0x9251F0
#define CEditWnd__SetEditable_x                                    0x9246A0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5D9400
#define CEverQuest__ClickedPlayer_x                                0x5CB750
#define CEverQuest__CreateTargetIndicator_x                        0x5E7C70
#define CEverQuest__DeleteTargetIndicator_x                        0x5E7D00
#define CEverQuest__DoTellWindow_x                                 0x4E11D0
#define CEverQuest__OutputTextToLog_x                              0x4E1400
#define CEverQuest__DropHeldItemOnGround_x                         0x5C1010
#define CEverQuest__dsp_chat_x                                     0x4E1790
#define CEverQuest__trimName_x                                     0x5E4230
#define CEverQuest__Emote_x                                        0x5D9C10
#define CEverQuest__EnterZone_x                                    0x5D3DF0
#define CEverQuest__GetBodyTypeDesc_x                              0x5DDAD0
#define CEverQuest__GetClassDesc_x                                 0x5DE110
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DE710
#define CEverQuest__GetDeityDesc_x                                 0x5E65C0
#define CEverQuest__GetLangDesc_x                                  0x5DE8D0
#define CEverQuest__GetRaceDesc_x                                  0x5DE0F0
#define CEverQuest__InterpretCmd_x                                 0x5E6B90
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C5200
#define CEverQuest__LMouseUp_x                                     0x5C3580
#define CEverQuest__RightClickedOnPlayer_x                         0x5C5AE0
#define CEverQuest__RMouseUp_x                                     0x5C4510
#define CEverQuest__SetGameState_x                                 0x5C0DA0
#define CEverQuest__UPCNotificationFlush_x                         0x5E4130
#define CEverQuest__IssuePetCommand_x                              0x5DFCD0
#define CEverQuest__ReportSuccessfulHit_x                          0x5DA930

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7050B0
#define CGaugeWnd__CalcLinesFillRect_x                             0x705110
#define CGaugeWnd__Draw_x                                          0x7047B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABEE0
#define CGuild__GetGuildName_x                                     0x4AAF20
#define CGuild__GetGuildIndex_x                                    0x4AB2B0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x720450

//CHotButton
#define CHotButton__SetButtonSize_x                                0x5F9140

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72D2D0
#define CInvSlotMgr__MoveItem_x                                    0x72C030
#define CInvSlotMgr__SelectSlot_x                                  0x72D3A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x72A8E0
#define CInvSlot__SliderComplete_x                                 0x728700
#define CInvSlot__GetItemBase_x                                    0x7280A0
#define CInvSlot__UpdateItem_x                                     0x728210

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x72ECD0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x72DFA0
#define CInvSlotWnd__HandleLButtonUp_x                             0x72E850

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7EA350
#define CItemDisplayWnd__UpdateStrings_x                           0x73CA10
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x736A80
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x736F60
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x73CFA0
#define CItemDisplayWnd__AboutToShow_x                             0x73C680
#define CItemDisplayWnd__WndNotification_x                         0x73E2B0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x821AB0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x742310

// CLabel 
#define CLabel__Draw_x                                             0x747D70

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F49C0
#define CListWnd__dCListWnd_x                                      0x8F4CE0
#define CListWnd__AddColumn_x                                      0x8F8FF0
#define CListWnd__AddColumn1_x                                     0x8F9040
#define CListWnd__AddLine_x                                        0x8F93D0
#define CListWnd__AddString_x                                      0x8F91D0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8F8DC0
#define CListWnd__CalculateVSBRange_x                              0x8F8BB0
#define CListWnd__ClearSel_x                                       0x8F9BB0
#define CListWnd__ClearAllSel_x                                    0x8F9C10
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8FA600
#define CListWnd__Compare_x                                        0x8F84F0
#define CListWnd__Draw_x                                           0x8F4DE0
#define CListWnd__DrawColumnSeparators_x                           0x8F75C0
#define CListWnd__DrawHeader_x                                     0x8F7A30
#define CListWnd__DrawItem_x                                       0x8F7E30
#define CListWnd__DrawLine_x                                       0x8F7730
#define CListWnd__DrawSeparator_x                                  0x8F7660
#define CListWnd__EnableLine_x                                     0x8F6EA0
#define CListWnd__EnsureVisible_x                                  0x8FA530
#define CListWnd__ExtendSel_x                                      0x8F9AE0
#define CListWnd__GetColumnMinWidth_x                              0x8F69E0
#define CListWnd__GetColumnWidth_x                                 0x8F6950
#define CListWnd__GetCurSel_x                                      0x8F62E0
#define CListWnd__GetItemAtPoint_x                                 0x8F7110
#define CListWnd__GetItemAtPoint1_x                                0x8F7180
#define CListWnd__GetItemData_x                                    0x8F6360
#define CListWnd__GetItemHeight_x                                  0x8F6720
#define CListWnd__GetItemIcon_x                                    0x8F64F0
#define CListWnd__GetItemRect_x                                    0x8F6F90
#define CListWnd__GetItemText_x                                    0x8F63A0
#define CListWnd__GetSelList_x                                     0x8F9C60
#define CListWnd__GetSeparatorRect_x                               0x8F73C0
#define CListWnd__InsertLine_x                                     0x8F97C0
#define CListWnd__RemoveLine_x                                     0x8F9910
#define CListWnd__SetColors_x                                      0x8F8B80
#define CListWnd__SetColumnJustification_x                         0x8F88B0
#define CListWnd__SetColumnWidth_x                                 0x8F87D0
#define CListWnd__SetCurSel_x                                      0x8F9A20
#define CListWnd__SetItemColor_x                                   0x8FA1F0
#define CListWnd__SetItemData_x                                    0x8FA1B0
#define CListWnd__SetItemText_x                                    0x8F9DE0
#define CListWnd__ShiftColumnSeparator_x                           0x8F8970
#define CListWnd__Sort_x                                           0x8F8670
#define CListWnd__ToggleSel_x                                      0x8F9A50

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x75D3C0
#define CMapViewWnd__GetWorldCoordinates_x                         0x75BAD0
#define CMapViewWnd__HandleLButtonDown_x                           0x758B30

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7802B0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x780B90
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7810D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x783F00
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x77EC90
#define CMerchantWnd__SelectBuySellSlot_x                          0x789A90
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x77FEE0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x888E50
#define CPacketScrambler__hton_x                                   0x888E40

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9136C0
#define CSidlManager__FindScreenPieceTemplate_x                    0x913AD0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9138C0
#define CSidlManager__CreateLabel_x                                0x7E1790
#define CSidlManager__CreateXWndFromTemplate_x                     0x916BA0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x916D80
#define CSidlManager__CreateXWnd_x                                 0x7E16C0
#define CSidlManager__CreateHotButtonWnd_x                         0x7E1C80

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x910250
#define CSidlScreenWnd__CalculateVSBRange_x                        0x910150
#define CSidlScreenWnd__ConvertToRes_x                             0x935000
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x90FBE0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x90F8D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x90F9A0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x90FA70
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9106E0
#define CSidlScreenWnd__EnableIniStorage_x                         0x910BB0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9108D0
#define CSidlScreenWnd__Init1_x                                    0x90F4C0
#define CSidlScreenWnd__LoadIniInfo_x                              0x910C00
#define CSidlScreenWnd__LoadIniListWnd_x                           0x911730
#define CSidlScreenWnd__LoadSidlScreen_x                           0x90E8C0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9112B0
#define CSidlScreenWnd__StoreIniVis_x                              0x911610
#define CSidlScreenWnd__WndNotification_x                          0x9105F0
#define CSidlScreenWnd__GetChildItem_x                             0x910B30
#define CSidlScreenWnd__HandleLButtonUp_x                          0x900450
#define CSidlScreenWnd__m_layoutCopy_x                             0x16997D0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65CD20
#define CSkillMgr__GetSkillCap_x                                   0x65CF00
#define CSkillMgr__GetNameToken_x                                  0x65C4B0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9206C0
#define CSliderWnd__SetValue_x                                     0x920530
#define CSliderWnd__SetNumTicks_x                                  0x920590

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7E7580

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9272D0
#define CStmlWnd__CalculateHSBRange_x                              0x928340
#define CStmlWnd__CalculateVSBRange_x                              0x9282B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x92C680
#define CStmlWnd__FastForwardToEndOfTag_x                          0x92D270
#define CStmlWnd__ForceParseNow_x                                  0x927870
#define CStmlWnd__GetNextTagPiece_x                                0x92C5E0
#define CStmlWnd__GetSTMLText_x                                    0x4EF580
#define CStmlWnd__GetVisibleText_x                                 0x927890
#define CStmlWnd__InitializeWindowVariables_x                      0x92D0C0
#define CStmlWnd__MakeStmlColorTag_x                               0x926A60
#define CStmlWnd__MakeWndNotificationTag_x                         0x926AD0
#define CStmlWnd__SetSTMLText_x                                    0x925B30
#define CStmlWnd__StripFirstSTMLLines_x                            0x92E3C0
#define CStmlWnd__UpdateHistoryString_x                            0x92D480

// CTabWnd 
#define CTabWnd__Draw_x                                            0x931B60
#define CTabWnd__DrawCurrentPage_x                                 0x932180
#define CTabWnd__DrawTab_x                                         0x931F50
#define CTabWnd__GetCurrentPage_x                                  0x9313C0
#define CTabWnd__GetPageInnerRect_x                                0x931600
#define CTabWnd__GetTabInnerRect_x                                 0x931540
#define CTabWnd__GetTabRect_x                                      0x9313F0
#define CTabWnd__InsertPage_x                                      0x9317F0
#define CTabWnd__SetPage_x                                         0x931680
#define CTabWnd__SetPageRect_x                                     0x931AA0
#define CTabWnd__UpdatePage_x                                      0x931E10
#define CTabWnd__GetPageFromTabIndex_x                             0x931E90
#define CTabWnd__GetCurrentTabIndex_x                              0x9313B0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x742770
#define CPageWnd__SetTabText_x                                     0x93EB70

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A59A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8FD2E0
#define CTextureFont__GetTextExtent_x                              0x8FD4A0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x690070
#define CHtmlComponentWnd__ValidateUri_x                           0x721E40
#define CHtmlWnd__SetClientCallbacks_x                             0x5FE120
#define CHtmlWnd__AddObserver_x                                    0x5FE140
#define CHtmlWnd__RemoveObserver_x                                 0x5FE1A0
#define Window__getProgress_x                                      0x83A1F0
#define Window__getStatus_x                                        0x83A210
#define Window__getURI_x                                           0x83A220

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x93B0F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8EA230

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD140
#define CXStr__CXStr1_x                                            0x82AB50
#define CXStr__CXStr3_x                                            0x8D6780
#define CXStr__dCXStr_x                                            0x472340
#define CXStr__operator_equal_x                                    0x8D69B0
#define CXStr__operator_equal1_x                                   0x8D69F0
#define CXStr__operator_plus_equal1_x                              0x8D7480

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x91E970
#define CXWnd__BringToTop_x                                        0x903BD0
#define CXWnd__Center_x                                            0x903750
#define CXWnd__ClrFocus_x                                          0x903580
#define CXWnd__Destroy_x                                           0x903630
#define CXWnd__DoAllDrawing_x                                      0x8FFBE0
#define CXWnd__DrawChildren_x                                      0x8FFBB0
#define CXWnd__DrawColoredRect_x                                   0x900040
#define CXWnd__DrawTooltip_x                                       0x8FE710
#define CXWnd__DrawTooltipAtPoint_x                                0x8FE7D0
#define CXWnd__GetBorderFrame_x                                    0x8FFEA0
#define CXWnd__GetChildWndAt_x                                     0x903C70
#define CXWnd__GetClientClipRect_x                                 0x901E60
#define CXWnd__GetScreenClipRect_x                                 0x901F30
#define CXWnd__GetScreenRect_x                                     0x902100
#define CXWnd__GetTooltipRect_x                                    0x900090
#define CXWnd__GetWindowTextA_x                                    0x497020
#define CXWnd__IsActive_x                                          0x906A80
#define CXWnd__IsDescendantOf_x                                    0x902B10
#define CXWnd__IsReallyVisible_x                                   0x902B40
#define CXWnd__IsType_x                                            0x9042B0
#define CXWnd__Move_x                                              0x902BC0
#define CXWnd__Move1_x                                             0x902C70
#define CXWnd__ProcessTransition_x                                 0x903700
#define CXWnd__Refade_x                                            0x902F40
#define CXWnd__Resize_x                                            0x9031D0
#define CXWnd__Right_x                                             0x903990
#define CXWnd__SetFocus_x                                          0x903540
#define CXWnd__SetFont_x                                           0x9035B0
#define CXWnd__SetKeyTooltip_x                                     0x9040E0
#define CXWnd__SetMouseOver_x                                      0x900FF0
#define CXWnd__StartFade_x                                         0x9029E0
#define CXWnd__GetChildItem_x                                      0x903DE0
#define CXWnd__SetParent_x                                         0x9028A0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9360D0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x906AC0
#define CXWndManager__DrawWindows_x                                0x906AE0
#define CXWndManager__GetKeyboardFlags_x                           0x9091A0
#define CXWndManager__HandleKeyboardMsg_x                          0x908DA0
#define CXWndManager__RemoveWnd_x                                  0x9093F0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x909950

// CDBStr
#define CDBStr__GetString_x                                        0x522580

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B7EE0
#define EQ_Character__Cur_HP_x                                     0x4CDFB0
#define EQ_Character__Cur_Mana_x                                   0x4D5440
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BADF0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AED40
#define EQ_Character__GetFocusRangeModifier_x                      0x4AEE90
#define EQ_Character__GetHPRegen_x                                 0x4DAB20
#define EQ_Character__GetEnduranceRegen_x                          0x4DB130
#define EQ_Character__GetManaRegen_x                               0x4DB570
#define EQ_Character__Max_Endurance_x                              0x623EB0
#define EQ_Character__Max_HP_x                                     0x4CDDE0
#define EQ_Character__Max_Mana_x                                   0x623CB0
#define EQ_Character__doCombatAbility_x                            0x626060
#define EQ_Character__UseSkill_x                                   0x4DD360
#define EQ_Character__GetConLevel_x                                0x61D080
#define EQ_Character__IsExpansionFlag_x                            0x584AA0
#define EQ_Character__TotalEffect_x                                0x4C1470
#define EQ_Character__GetPCSpellAffect_x                           0x4BB9E0
#define EQ_Character__SpellDuration_x                              0x4BB510
#define EQ_Character__FindItemByRecord_x                           0x4D35C0
#define EQ_Character__GetAdjustedSkill_x                           0x4D0CF0
#define EQ_Character__GetBaseSkill_x                               0x4D1C90
#define EQ_Character__CanUseItem_x                                 0x4D5750

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8A8260

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x639E50

//PcClient
#define PcClient__PcClient_x                                       0x61A940

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B5CC0
#define CCharacterListWnd__EnterWorld_x                            0x4B5700
#define CCharacterListWnd__Quit_x                                  0x4B5410
#define CCharacterListWnd__UpdateList_x                            0x4B5890

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5FF340
#define EQ_Item__CreateItemTagString_x                             0x8831C0
#define EQ_Item__IsStackable_x                                     0x887330
#define EQ_Item__GetImageNum_x                                     0x884940
#define EQ_Item__CreateItemClient_x                                0x5FE520
#define EQ_Item__GetItemValue_x                                    0x885A00
#define EQ_Item__ValueSellMerchant_x                               0x8889E0
#define EQ_Item__IsKeyRingItem_x                                   0x886CF0
#define EQ_Item__CanGoInBag_x                                      0x5FF460
#define EQ_Item__GetMaxItemCount_x                                 0x885B00
#define EQ_Item__GetHeldItem_x                                     0x884810
#define EQ_Item__GetAugmentFitBySlot_x                             0x882D10

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5407E0
#define EQ_LoadingS__Array_x                                       0xBD92D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x624810
#define EQ_PC__GetAlternateAbilityId_x                             0x891D50
#define EQ_PC__GetCombatAbility_x                                  0x8923C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x892430
#define EQ_PC__GetItemRecastTimer_x                                0x6265E0
#define EQ_PC__HasLoreItem_x                                       0x61D7F0
#define EQ_PC__AlertInventoryChanged_x                             0x61CB50
#define EQ_PC__GetPcZoneClient_x                                   0x648660
#define EQ_PC__RemoveMyAffect_x                                    0x629720
#define EQ_PC__GetKeyRingItems_x                                   0x892CD0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x892A50
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x892FC0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58AD80
#define EQItemList__add_object_x                                   0x5B66D0
#define EQItemList__add_item_x                                     0x58B390
#define EQItemList__delete_item_x                                  0x58B3E0
#define EQItemList__FreeItemList_x                                 0x58B2E0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x51FAF0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x63B6D0
#define EQPlayer__dEQPlayer_x                                      0x62EDA0
#define EQPlayer__DoAttack_x                                       0x643380
#define EQPlayer__EQPlayer_x                                       0x62F450
#define EQPlayer__SetNameSpriteState_x                             0x633710
#define EQPlayer__SetNameSpriteTint_x                              0x6345D0
#define PlayerBase__HasProperty_j_x                                0x969420
#define EQPlayer__IsTargetable_x                                   0x9698C0
#define EQPlayer__CanSee_x                                         0x969720
#define EQPlayer__CanSee1_x                                        0x9697F0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9694E0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x646150
#define PlayerZoneClient__GetLevel_x                               0x6486A0
#define PlayerZoneClient__IsValidTeleport_x                        0x5B7820
#define PlayerZoneClient__LegalPlayerRace_x                        0x539CC0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x63E440
#define EQPlayerManager__GetSpawnByName_x                          0x63E460
#define EQPlayerManager__GetPlayerFromPartialName_x                0x63E4F0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x602BC0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x602C00
#define KeypressHandler__ClearCommandStateArray_x                  0x603FF0
#define KeypressHandler__HandleKeyDown_x                           0x604010
#define KeypressHandler__HandleKeyUp_x                             0x6040B0
#define KeypressHandler__SaveKeymapping_x                          0x604490

// MapViewMap 
#define MapViewMap__Clear_x                                        0x759250
#define MapViewMap__SaveEx_x                                       0x75C5F0
#define MapViewMap__SetZoom_x                                      0x760CC0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A6150

// StringTable 
#define StringTable__getString_x                                   0x8A0FF0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x629390
#define PcZoneClient__RemovePetEffect_x                            0x6299C0
#define PcZoneClient__HasAlternateAbility_x                        0x623AF0
#define PcZoneClient__GetCurrentMod_x                              0x4E02C0
#define PcZoneClient__GetModCap_x                                  0x4E01C0
#define PcZoneClient__CanEquipItem_x                               0x6241A0
#define PcZoneClient__GetItemByID_x                                0x626A60
#define PcZoneClient__GetItemByItemClass_x                         0x626AF0
#define PcZoneClient__RemoveBuffEffect_x                           0x6299E0
#define PcZoneClient__BandolierSwap_x                              0x624DD0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BC4D0

//IconCache
#define IconCache__GetIcon_x                                       0x6FA7F0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F2240
#define CContainerMgr__CloseContainer_x                            0x6F2510
#define CContainerMgr__OpenExperimentContainer_x                   0x6F2F90

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B4150

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F7560

//CLootWnd
#define CLootWnd__LootAll_x                                        0x74F6D0
#define CLootWnd__RequestLootSlot_x                                0x74EA90

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x558DB0
#define EQ_Spell__SpellAffects_x                                   0x559220
#define EQ_Spell__SpellAffectBase_x                                0x558FE0
#define EQ_Spell__IsStackable_x                                    0x4C5C80
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5B00
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3250
#define EQ_Spell__IsSPAStacking_x                                  0x55A050
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x559570
#define EQ_Spell__IsNoRemove_x                                     0x4C5C60
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x55A060
#define __IsResEffectSpell_x                                       0x4C4FB0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9BA0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B0730

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7F96C0
#define CTargetWnd__WndNotification_x                              0x7F8F50
#define CTargetWnd__RefreshTargetBuffs_x                           0x7F9220
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7F80A0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7FDD90

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x554350
#define EqSoundManager__PlayScriptMp3_x                            0x5544B0
#define EqSoundManager__SoundAssistPlay_x                          0x6607C0
#define EqSoundManager__WaveInstancePlay_x                         0x65FD30

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5113D0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9220A0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x548440
#define CAltAbilityData__GetMercMaxRank_x                          0x5483E0
#define CAltAbilityData__GetMaxRank_x                              0x53D9E0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F5660

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5AE0
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F7650
#define CharacterBase__CreateItemIndex_x                           0x5FD730
#define CharacterBase__GetItemPossession_x                         0x4B3100
#define CharacterBase__GetItemByGlobalIndex_x                      0x8B8C80
#define CharacterBase__GetEffectId_x                               0x4C5A90

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DA3E0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6DAC00

//messages
#define msg_spell_worn_off_x                                       0x57D1A0
#define msg_new_text_x                                             0x572390
#define __msgTokenTextParam_x                                      0x57F7F0
#define msgTokenText_x                                             0x57FA40

//SpellManager
#define SpellManager__vftable_x                                    0xAA3840
#define SpellManager__SpellManager_x                               0x663AE0
#define Spellmanager__LoadTextSpells_x                             0x6643B0
#define SpellManager__GetSpellByGroupAndRank_x                     0x663CB0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x96D390

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F7D00
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x582FF0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x616180
#define ItemGlobalIndex__IsValidIndex_x                            0x4F7D60

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B1070
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B12F0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7480B0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F6A50
#define CCursorAttachment__Deactivate_x                            0x6F7A20

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x934580
#define CEQSuiteTextureLoader__GetTexture_x                        0x934240

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F4CF0

//IString
#define IString__Append_x                                          0x4E95F0

//Camera
#define CDisplay__cameraType_x                                     0xDA8E18
#define EverQuest__Cameras_x                                       0xE6C128

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FD440
#define LootFiltersManager__GetItemFilterData_x                    0x4FCD30
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FCD60
#define LootFiltersManager__SetItemLootFilter_x                    0x4FCF80

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A2190

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x973080
#define CResolutionHandler__GetWindowedStyle_x                     0x65B8A0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6EEF90

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8C3010

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x70F250
#define CGroupWnd__UpdateDisplay_x                                 0x70E5B0

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
