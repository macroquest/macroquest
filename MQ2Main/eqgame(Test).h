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
#define __ExpectedVersionDate                                     "Jul  9 2018"
#define __ExpectedVersionTime                                     "13:15:10"
#define __ActualVersionDate_x                                      0xAC060C
#define __ActualVersionTime_x                                      0xAC0600

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x60A100
#define __MemChecker1_x                                            0x8DBE20
#define __MemChecker2_x                                            0x698AC0
#define __MemChecker3_x                                            0x698A10
#define __MemChecker4_x                                            0x835BC0
#define __EncryptPad0_x                                            0xBF2498
#define __EncryptPad1_x                                            0xC50628
#define __EncryptPad2_x                                            0xC034D0
#define __EncryptPad3_x                                            0xC030D0
#define __EncryptPad4_x                                            0xC413C0
#define __EncryptPad5_x                                            0xF0E0C8
#define __AC1_x                                                    0x7F22D6
#define __AC2_x                                                    0x5C5BAF
#define __AC3_x                                                    0x5CCA3F
#define __AC4_x                                                    0x5D08C0
#define __AC5_x                                                    0x5D6AF0
#define __AC6_x                                                    0x5DB032
#define __AC7_x                                                    0x5C5620
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1AC5B4

// Direct Input
#define DI8__Main_x                                                0xF0E0EC
#define DI8__Keyboard_x                                            0xF0E0F0
#define DI8__Mouse_x                                               0xF0E0B0
#define DI8__Mouse_Copy_x                                          0xE6BDA4
#define DI8__Mouse_Check_x                                         0xF0EFB0
#define __AutoSkillArray_x                                         0xE6CCB4
#define __Attack_x                                                 0xF0AA9B
#define __Autofire_x                                               0xF0AA9C
#define __BindList_x                                               0xBE1088
#define g_eqCommandStates_x                                        0xBE1DF8
#define __Clicks_x                                                 0xE6BE5C
#define __CommandList_x                                            0xBE29B0
#define __CurrentMapLabel_x                                        0x10206D4
#define __CurrentSocial_x                                          0xBCC710
#define __DoAbilityList_x                                          0xEA25BC
#define __do_loot_x                                                0x593090
#define __DrawHandler_x                                            0x169BBE8
#define __GroupCount_x                                             0xE5C062
#define __Guilds_x                                                 0xE625B0
#define __gWorld_x                                                 0xE5C3AC
#define __HWnd_x                                                   0xF0E0B4
#define __heqmain_x                                                0x101930C
#define __InChatMode_x                                             0xE6BD8C
#define __LastTell_x                                               0xE6DCB8
#define __LMouseHeldTime_x                                         0xE6BEC8
#define __Mouse_x                                                  0xF0E0D4
#define __MouseLook_x                                              0xE6BE22
#define __MouseEventTime_x                                         0xF0B550
#define __gpbCommandEvent_x                                        0xE5C2E4
#define __NetStatusToggle_x                                        0xE6BE25
#define __PCNames_x                                                0xE6D278
#define __RangeAttackReady_x                                       0xE6CF98
#define __RMouseHeldTime_x                                         0xE6BEC4
#define __RunWalkState_x                                           0xE6BD90
#define __ScreenMode_x                                             0xDAA944
#define __ScreenX_x                                                0xE6BD44
#define __ScreenY_x                                                0xE6BD40
#define __ScreenXMax_x                                             0xE6BD48
#define __ScreenYMax_x                                             0xE6BD4C
#define __ServerHost_x                                             0xE5C4B3
#define __ServerName_x                                             0xEA257C
#define __ShiftKeyDown_x                                           0xE6C41C
#define __ShowNames_x                                              0xE6D150
#define __Socials_x                                                0xEA267C
#define __SubscriptionType_x                                       0x106219C
#define __TargetAggroHolder_x                                      0x102308C
#define __ZoneType_x                                               0xE6C220
#define __GroupAggro_x                                             0x10230CC
#define __LoginName_x                                              0xF0E944
#define __Inviter_x                                                0xF0AA18
#define __AttackOnAssist_x                                         0xE6D10C
#define __UseTellWindows_x                                         0xE6D410
#define __gfMaxZoomCameraDistance_x                                0xAB5B40
#define __gfMaxCameraDistance_x                                    0xAE2F70
#define __pulAutoRun_x                                             0xE6BE40
#define __pulForward_x                                             0xE6D448
#define __pulBackward_x                                            0xE6D44C
#define __pulTurnRight_x                                           0xE6D450
#define __pulTurnLeft_x                                            0xE6D454
#define __pulStrafeLeft_x                                          0xE6D458
#define __pulStrafeRight_x                                         0xE6D45C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE5E958
#define instEQZoneInfo_x                                           0xE6C018
#define instKeypressHandler_x                                      0xF0B500
#define pinstActiveBanker_x                                        0xE5E900
#define pinstActiveCorpse_x                                        0xE5E8F8
#define pinstActiveGMaster_x                                       0xE5E8FC
#define pinstActiveMerchant_x                                      0xE5E8F4
#define pinstAggroInfo_x                                           0xC66CF8
#define pinstAltAdvManager_x                                       0xDAB2F8
#define pinstAuraMgr_x                                             0xC779E0
#define pinstBandageTarget_x                                       0xE5E910
#define pinstCamActor_x                                            0xDAA924
#define pinstCDBStr_x                                              0xDAA04C
#define pinstCDisplay_x                                            0xE5C04C
#define pinstCEverQuest_x                                          0xF0E208
#define pinstEverQuestInfo_x                                       0xE6BD38
#define pinstCharData_x                                            0xE5C25C
#define pinstCharSpawn_x                                           0xE5E948
#define pinstControlledMissile_x                                   0xE5C260
#define pinstControlledPlayer_x                                    0xE5E948
#define pinstCResolutionHandler_x                                  0x169BE18
#define pinstCSidlManager_x                                        0x169ACAC
#define pinstCXWndManager_x                                        0x169ACA0
#define instDynamicZone_x                                          0xE62488
#define pinstDZMember_x                                            0xE62598
#define pinstDZTimerInfo_x                                         0xE6259C
#define pinstEQItemList_x                                          0xE5AB48
#define pinstEQObjectList_x                                        0xE5BD38
#define instEQMisc_x                                               0xDA9F88
#define pinstEQSoundManager_x                                      0xDABB58
#define pinstEQSpellStrings_x                                      0xC74E30
#define instExpeditionLeader_x                                     0xE624D2
#define instExpeditionName_x                                       0xE62512
#define pinstGroup_x                                               0xE5C05E
#define pinstImeManager_x                                          0x169ACA4
#define pinstLocalPlayer_x                                         0xE5E8F0
#define pinstMercenaryData_x                                       0xF0BCF0
#define pinstMercenaryStats_x                                      0x10231D8
#define pinstMercAltAbilities_x                                    0xDAB8C8
#define pinstModelPlayer_x                                         0xE5E908
#define pinstPCData_x                                              0xE5C25C
#define pinstRealEstateItems_x                                     0xF0D1E0
#define pinstSkillMgr_x                                            0xF0D2B0
#define pinstSpawnManager_x                                        0xF0C8A0
#define pinstSpellManager_x                                        0xF0D518
#define pinstSpellSets_x                                           0xF036C4
#define pinstStringTable_x                                         0xE5C7C4
#define pinstSwitchManager_x                                       0xE5BEF8
#define pinstTarget_x                                              0xE5E944
#define pinstTargetObject_x                                        0xE5E950
#define pinstTargetSwitch_x                                        0xE5C268
#define pinstTaskMember_x                                          0xDA9E18
#define pinstTrackTarget_x                                         0xE5E94C
#define pinstTradeTarget_x                                         0xE5E904
#define instTributeActive_x                                        0xDA9FAD
#define pinstViewActor_x                                           0xDAA91C
#define pinstWorldData_x                                           0xE5C2DC
#define pinstZoneAddr_x                                            0xE6C2B8
#define pinstPlayerPath_x                                          0xF0C938
#define pinstTargetIndicator_x                                     0xF0D780
#define pinstCTargetManager_x                                      0xF0D818
#define EQObject_Top_x                                             0xE5E8EC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDAA174
#define pinstCAchievementsWnd_x                                    0xDAA418
#define pinstCActionsWnd_x                                         0xDAA3D0
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDAA15C
#define pinstCAdvancedLootWnd_x                                    0xDAA104
#define pinstCAdventureLeaderboardWnd_x                            0x1019EA8
#define pinstCAdventureRequestWnd_x                                0x1019F58
#define pinstCAdventureStatsWnd_x                                  0x101A008
#define pinstCAggroMeterWnd_x                                      0xDAA43C
#define pinstCAlarmWnd_x                                           0xDAA3FC
#define pinstCAlertHistoryWnd_x                                    0xDAA3D8
#define pinstCAlertStackWnd_x                                      0xDAA170
#define pinstCAlertWnd_x                                           0xDAA384
#define pinstCAltStorageWnd_x                                      0x101A368
#define pinstCAudioTriggersWindow_x                                0xC67188
#define pinstCAuraWnd_x                                            0xDAA438
#define pinstCAvaZoneWnd_x                                         0xDAA3B8
#define pinstCBandolierWnd_x                                       0xDAA47C
#define pinstCBankWnd_x                                            0xDAA108
#define pinstCBarterMerchantWnd_x                                  0x101B5A8
#define pinstCBarterSearchWnd_x                                    0x101B658
#define pinstCBarterWnd_x                                          0x101B708
#define pinstCBazaarConfirmationWnd_x                              0xDAA168
#define pinstCBazaarSearchWnd_x                                    0xDAA3E8
#define pinstCBazaarWnd_x                                          0xDAA474
#define pinstCBlockedBuffWnd_x                                     0xDAA0F0
#define pinstCBlockedPetBuffWnd_x                                  0xDAA114
#define pinstCBodyTintWnd_x                                        0xDAA390
#define pinstCBookWnd_x                                            0xDAA904
#define pinstCBreathWnd_x                                          0xDAA388
#define pinstCBuffWindowNORMAL_x                                   0xDAA960
#define pinstCBuffWindowSHORT_x                                    0xDAA964
#define pinstCBugReportWnd_x                                       0xDAA164
#define pinstCButtonWnd_x                                          0x169AE98
#define pinstCCastingWnd_x                                         0xDAA160
#define pinstCCastSpellWnd_x                                       0xDAA3F8
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDAA394
#define pinstCChatWindowManager_x                                  0x101C1C8
#define pinstCClaimWnd_x                                           0x101C320
#define pinstCColorPickerWnd_x                                     0xDAA3A8
#define pinstCCombatAbilityWnd_x                                   0xDAA448
#define pinstCCombatSkillsSelectWnd_x                              0xDAA3CC
#define pinstCCompassWnd_x                                         0xDAA17C
#define pinstCConfirmationDialog_x                                 0x1021220
#define pinstCContainerMgr_x                                       0xDAA46C
#define pinstCContextMenuManager_x                                 0x169AC60
#define pinstCCursorAttachment_x                                   0xDAA154
#define pinstCDynamicZoneWnd_x                                     0x101C8E8
#define pinstCEditLabelWnd_x                                       0xDAA910
#define pinstCEQMainWnd_x                                          0x101CB30
#define pinstCEventCalendarWnd_x                                   0xDAA434
#define pinstCExtendedTargetWnd_x                                  0xDAA430
#define pinstCFacePick_x                                           0xDAA3B0
#define pinstCFellowshipWnd_x                                      0x101CD30
#define pinstCFileSelectionWnd_x                                   0xDAA0EC
#define pinstCFindItemWnd_x                                        0xDAA460
#define pinstCFindLocationWnd_x                                    0x101CE88
#define pinstCFriendsWnd_x                                         0xDAA3EC
#define pinstCGemsGameWnd_x                                        0xDAA3D4
#define pinstCGiveWnd_x                                            0xDAA900
#define pinstCGroupSearchFiltersWnd_x                              0xDAA458
#define pinstCGroupSearchWnd_x                                     0x101D280
#define pinstCGroupWnd_x                                           0x101D330
#define pinstCGuildBankWnd_x                                       0xE6D0F4
#define pinstCGuildCreationWnd_x                                   0x101D490
#define pinstCGuildMgmtWnd_x                                       0x101D540
#define pinstCharacterCreation_x                                   0xDAA440
#define pinstCHelpWnd_x                                            0xDAA408
#define pinstCHeritageSelectionWnd_x                               0xDAA3BC
#define pinstCHotButtonWnd_x                                       0x101F698
#define pinstCHotButtonWnd1_x                                      0x101F698
#define pinstCHotButtonWnd2_x                                      0x101F69C
#define pinstCHotButtonWnd3_x                                      0x101F6A0
#define pinstCHotButtonWnd4_x                                      0x101F6A4
#define pinstCIconSelectionWnd_x                                   0xDAA124
#define pinstCInspectWnd_x                                         0xDAA120
#define pinstCInventoryWnd_x                                       0xDAA48C
#define pinstCInvSlotMgr_x                                         0xDAA420
#define pinstCItemDisplayManager_x                                 0x101FC28
#define pinstCItemExpTransferWnd_x                                 0x101FD58
#define pinstCItemOverflowWnd_x                                    0xDAA3F0
#define pinstCJournalCatWnd_x                                      0xDAA118
//#define pinstCJournalNPCWnd_x                                      0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDAA958
#define pinstCKeyRingWnd_x                                         0xDAA96C
#define pinstCLargeDialogWnd_x                                     0x1021EA0
#define pinstCLayoutCopyWnd_x                                      0x10200A8
#define pinstCLFGuildWnd_x                                         0x1020158
#define pinstCLoadskinWnd_x                                        0xDAA3E4
#define pinstCLootFiltersCopyWnd_x                                 0xC781C0
#define pinstCLootFiltersWnd_x                                     0xDAA398
#define pinstCLootSettingsWnd_x                                    0xDAA3A4
#define pinstCLootWnd_x                                            0xDAA3A0
#define pinstCMailAddressBookWnd_x                                 0xDAA12C
#define pinstCMailCompositionWnd_x                                 0xDAA10C
#define pinstCMailIgnoreListWnd_x                                  0xDAA130
#define pinstCMailWnd_x                                            0xDAA970
#define pinstCManageLootWnd_x                                      0xDAB770
#define pinstCMapToolbarWnd_x                                      0xDAA4F4
#define pinstCMapViewWnd_x                                         0xDAA464
#define pinstCMarketplaceWnd_x                                     0xDAA468
#define pinstCMerchantWnd_x                                        0xDAA3C8
#define pinstCMIZoneSelectWnd_x                                    0x1020990
#define pinstCMusicPlayerWnd_x                                     0xDAA968
#define pinstCNameChangeMercWnd_x                                  0xDAA110
#define pinstCNameChangePetWnd_x                                   0xDAA0E8
#define pinstCNameChangeWnd_x                                      0xDAA444
#define pinstCNoteWnd_x                                            0xDAA404
#define pinstCObjectPreviewWnd_x                                   0xDAA90C
#define pinstCOptionsWnd_x                                         0xDAA4F8
#define pinstCPetInfoWnd_x                                         0xDAA0FC
#define pinstCPetitionQWnd_x                                       0xDAA128
//#define pinstCPlayerCustomizationWnd_x                             0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDAA38C
#define pinstCPlayerWnd_x                                          0xDAA3F4
#define pinstCPopupWndManager_x                                    0x1021220
#define pinstCProgressionSelectionWnd_x                            0x10212D0
#define pinstCPurchaseGroupWnd_x                                   0xDAA974
#define pinstCPurchaseWnd_x                                        0xDAA950
#define pinstCPvPLeaderboardWnd_x                                  0x1021380
#define pinstCPvPStatsWnd_x                                        0x1021430
#define pinstCQuantityWnd_x                                        0xDAA140
#define pinstCRaceChangeWnd_x                                      0xDAA470
#define pinstCRaidOptionsWnd_x                                     0xDAA45C
#define pinstCRaidWnd_x                                            0xDAA148
#define pinstCRealEstateItemsWnd_x                                 0xDAA424
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDAA450
#define pinstCRealEstateManageWnd_x                                0xDAA3C0
#define pinstCRealEstateNeighborhoodWnd_x                          0xDAA3DC
#define pinstCRealEstatePlotSearchWnd_x                            0xDAA400
#define pinstCRealEstatePurchaseWnd_x                              0xDAA40C
#define pinstCRespawnWnd_x                                         0xDAA454
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDAA42C
#define pinstCSendMoneyWnd_x                                       0xDAA954
#define pinstCServerListWnd_x                                      0xDAA41C
#define pinstCSkillsSelectWnd_x                                    0xDAA3AC
#define pinstCSkillsWnd_x                                          0xDAA39C
#define pinstCSocialEditWnd_x                                      0xDAA14C
#define pinstCSocialWnd_x                                          0xDAA150
#define pinstCSpellBookWnd_x                                       0xDAA428
#define pinstCStoryWnd_x                                           0xDAA16C
#define pinstCTargetOfTargetWnd_x                                  0x1023260
#define pinstCTargetWnd_x                                          0xDAA0F8
#define pinstCTaskOverlayWnd_x                                     0xDAA3E0
#define pinstCTaskSelectWnd_x                                      0x10233B8
#define pinstCTaskSomething_x                                      0xC789C0
#define pinstCTaskTemplateSelectWnd_x                              0x1023468
#define pinstCTaskWnd_x                                            0x1023518
#define pinstCTextEntryWnd_x                                       0xDAA380
#define pinstCTextOverlay_x                                        0xC67498
#define pinstCTimeLeftWnd_x                                        0xDAA100
#define pinstCTipWndCONTEXT_x                                      0x102371C
#define pinstCTipWndOFDAY_x                                        0x1023718
#define pinstCTitleWnd_x                                           0x10237C8
#define pinstCTrackingWnd_x                                        0xDAA0F4
#define pinstCTradeskillWnd_x                                      0x1023930
#define pinstCTradeWnd_x                                           0xDAA410
#define pinstCTrainWnd_x                                           0xDAA134
#define pinstCTributeBenefitWnd_x                                  0x1023B30
#define pinstCTributeMasterWnd_x                                   0x1023BE0
#define pinstCTributeTrophyWnd_x                                   0x1023C90
#define pinstCVideoModesWnd_x                                      0xDAA11C
#define pinstCVoiceMacroWnd_x                                      0xF0DD48
#define pinstCVoteResultsWnd_x                                     0xDAA95C
#define pinstCVoteWnd_x                                            0xDAA908
#define pinstCWebManager_x                                         0xF0DEAC
#define pinstCZoneGuideWnd_x                                       0xDAA3B4
#define pinstCZonePathWnd_x                                        0xDAA3C4

#define pinstEQSuiteTextureLoader_x                                0xC520E0
#define pinstItemIconCache_x                                       0x101CAE8
#define pinstLootFiltersManager_x                                  0xC78270
#define pinstRewardSelectionWnd_x                                  0x1021B78

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC030C4
#define __CastRay_x                                                0x58E5B0
#define __CastRay2_x                                               0x58E600
#define __ConvertItemTags_x                                        0x5A9320
#define __CrashHandler_x                                           0x83F520
#define __EQGetTime_x                                              0x8DB750
#define __ExecuteCmd_x                                             0x586F30
#define __FixHeading_x                                             0x96C5A0
#define __get_bearing_x                                            0x58E0F0
#define __get_melee_range_x                                        0x58E7F0
#define __GetAnimationCache_x                                      0x6FC400
#define __GetGaugeValueFromEQ_x                                    0x7F0AF0
#define __GetLabelFromEQ_x                                         0x7F2260
#define __GetXTargetType_x                                         0x96E070
#define __HeadingDiff_x                                            0x96C610
#define __HelpPath_x                                               0xF0B16C
#define __LoadFrontEnd_x                                           0x694920
#define __NewUIINI_x                                               0x7F07C0
#define __pCrashHandler_x                                          0x1040FF8
#define __ProcessGameEvents_x                                      0x5EBA00
#define __ProcessMouseEvent_x                                      0x5EB1C0
#define __SaveColors_x                                             0x537FC0
#define __STMLToText_x                                             0x90F650
#define __ToggleKeyRingItem_x                                      0x4FB6D0
#define CrashDetected_x                                            0x696410
#define DrawNetStatus_x                                            0x617520
#define Expansion_HoT_x                                            0xE6D0FC
#define Teleport_Table_Size_x                                      0xE5C36C
#define Teleport_Table_x                                           0xE5C7C8
#define Util__FastTime_x                                           0x8DB310
#define wwsCrashReportCheckForUploader_x                           0x83FFD0
#define wwsCrashReportPlatformLaunchUploader_x                     0x8426B0
#define __HandleMouseWheel_x                                       0x698B70

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48AB10
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4938F0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4936D0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x53F750
#define AltAdvManager__IsAbilityReady_x                            0x53E810
#define AltAdvManager__GetAAById_x                                 0x53EA10
#define AltAdvManager__CanTrainAbility_x                           0x53EA80
#define AltAdvManager__CanSeeAbility_x                             0x53ECB0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C6760
#define CharacterZoneClient__HasSkill_x                            0x4D1300
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2A20
#define CharacterZoneClient__IsStackBlocked_x                      0x4BA9F0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B7080
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D5170
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D5250
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D5330
#define CharacterZoneClient__FindAffectSlot_x                      0x4BF620
#define CharacterZoneClient__BardCastBard_x                        0x4C22A0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B7150
#define CharacterZoneClient__GetEffect_x                           0x4B6FC0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C0630
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C0700
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C0750
#define CharacterZoneClient__CalcAffectChange_x                    0x4C08A0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C0A70

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BEBC0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6CC570

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5F9DC0
#define CButtonWnd__CButtonWnd_x                                   0x90BA70

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6EAE00
#define CChatManager__InitContextMenu_x                            0x6E5160
#define CChatManager__FreeChatWindow_x                             0x6E9D50
#define CChatManager__GetLockedActiveChatWindow_x                  0x6EE6A0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6EABA0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9202D0
#define CContextMenu__dCContextMenu_x                              0x920500
#define CContextMenu__AddMenuItem_x                                0x920510
#define CContextMenu__RemoveMenuItem_x                             0x920810
#define CContextMenu__RemoveAllMenuItems_x                         0x920830
#define CContextMenu__CheckMenuItem_x                              0x9208B0
#define CContextMenu__SetMenuItem_x                                0x920740

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x920E50
#define CContextMenuManager__RemoveMenu_x                          0x920EC0
#define CContextMenuManager__PopupMenu_x                           0x920F80
#define CContextMenuManager__Flush_x                               0x920DF0
#define CContextMenuManager__GetMenu_x                             0x495AD0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BD4D0
#define CChatService__GetFriendName_x                              0x8BD4E0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6EB370
#define CChatWindow__Clear_x                                       0x6EC3C0
#define CChatWindow__WndNotification_x                             0x6EC930

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x91D770
#define CComboWnd__Draw_x                                          0x91CC70
#define CComboWnd__GetCurChoice_x                                  0x91D5B0
#define CComboWnd__GetListRect_x                                   0x91D120
#define CComboWnd__GetTextRect_x                                   0x91D7D0
#define CComboWnd__InsertChoice_x                                  0x91D2B0
#define CComboWnd__SetColors_x                                     0x91D280
#define CComboWnd__SetChoice_x                                     0x91D580
#define CComboWnd__GetItemCount_x                                  0x91D5C0
#define CComboWnd__GetCurChoiceText_x                              0x91D600

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F45B0
#define CContainerWnd__vftable_x                                   0xAC99F0
#define CContainerWnd__SetContainer_x                              0x6F5B20

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x537D80
#define CDisplay__GetClickedActor_x                                0x52ADD0
#define CDisplay__GetUserDefinedColor_x                            0x5234D0
#define CDisplay__GetWorldFilePath_x                               0x52C820
#define CDisplay__is3dON_x                                         0x527AC0
#define CDisplay__ReloadUI_x                                       0x531F40
#define CDisplay__WriteTextHD2_x                                   0x5278A0
#define CDisplay__TrueDistance_x                                   0x52E480
#define CDisplay__SetViewActor_x                                   0x52A720

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x93FCE0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9249B0
#define CEditWnd__GetCharIndexPt_x                                 0x925890
#define CEditWnd__GetDisplayString_x                               0x925730
#define CEditWnd__GetHorzOffset_x                                  0x923FF0
#define CEditWnd__GetLineForPrintableChar_x                        0x926990
#define CEditWnd__GetSelStartPt_x                                  0x925B30
#define CEditWnd__GetSTMLSafeText_x                                0x925550
#define CEditWnd__PointFromPrintableChar_x                         0x9265D0
#define CEditWnd__SelectableCharFromPoint_x                        0x926740
#define CEditWnd__SetEditable_x                                    0x925BF0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5DA560
#define CEverQuest__ClickedPlayer_x                                0x5CC820
#define CEverQuest__CreateTargetIndicator_x                        0x5E8CE0
#define CEverQuest__DeleteTargetIndicator_x                        0x5E8D70
#define CEverQuest__DoTellWindow_x                                 0x4E15D0
#define CEverQuest__OutputTextToLog_x                              0x4E1800
#define CEverQuest__DropHeldItemOnGround_x                         0x5C20E0
#define CEverQuest__dsp_chat_x                                     0x4E1B90
#define CEverQuest__trimName_x                                     0x5E52A0
#define CEverQuest__Emote_x                                        0x5DAD70
#define CEverQuest__EnterZone_x                                    0x5D4EE0
#define CEverQuest__GetBodyTypeDesc_x                              0x5DEB40
#define CEverQuest__GetClassDesc_x                                 0x5DF180
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DF780
#define CEverQuest__GetDeityDesc_x                                 0x5E7630
#define CEverQuest__GetLangDesc_x                                  0x5DF940
#define CEverQuest__GetRaceDesc_x                                  0x5DF160
#define CEverQuest__InterpretCmd_x                                 0x5E7C00
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C62D0
#define CEverQuest__LMouseUp_x                                     0x5C4650
#define CEverQuest__RightClickedOnPlayer_x                         0x5C6BB0
#define CEverQuest__RMouseUp_x                                     0x5C55E0
#define CEverQuest__SetGameState_x                                 0x5C1E70
#define CEverQuest__UPCNotificationFlush_x                         0x5E51A0
#define CEverQuest__IssuePetCommand_x                              0x5E0D40
#define CEverQuest__ReportSuccessfulHit_x                          0x5DBA10

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7065D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x706630
#define CGaugeWnd__Draw_x                                          0x705CC0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABFA0
#define CGuild__GetGuildName_x                                     0x4AAFE0
#define CGuild__GetGuildIndex_x                                    0x4AB370

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x721990

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72E8D0
#define CInvSlotMgr__MoveItem_x                                    0x72D5F0
#define CInvSlotMgr__SelectSlot_x                                  0x72E9A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x72BE90
#define CInvSlot__SliderComplete_x                                 0x729CB0
#define CInvSlot__GetItemBase_x                                    0x729620
#define CInvSlot__UpdateItem_x                                     0x729790

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7302F0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x72F5C0
#define CInvSlotWnd__HandleLButtonUp_x                             0x72FE70

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7ECCA0
#define CItemDisplayWnd__UpdateStrings_x                           0x73EFB0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x738F80
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x739470
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x73F540
#define CItemDisplayWnd__AboutToShow_x                             0x73EBF0
#define CItemDisplayWnd__WndNotification_x                         0x740860

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8245A0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7448D0

// CLabel 
#define CLabel__Draw_x                                             0x74A340

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F5E40
#define CListWnd__dCListWnd_x                                      0x8F6160
#define CListWnd__AddColumn_x                                      0x8FA460
#define CListWnd__AddColumn1_x                                     0x8FA4B0
#define CListWnd__AddLine_x                                        0x8FA840
#define CListWnd__AddString_x                                      0x8FA640
#define CListWnd__CalculateFirstVisibleLine_x                      0x8FA220
#define CListWnd__CalculateVSBRange_x                              0x8FA000
#define CListWnd__ClearSel_x                                       0x8FB020
#define CListWnd__ClearAllSel_x                                    0x8FB080
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8FBA60
#define CListWnd__Compare_x                                        0x8F9940
#define CListWnd__Draw_x                                           0x8F6260
#define CListWnd__DrawColumnSeparators_x                           0x8F8A20
#define CListWnd__DrawHeader_x                                     0x8F8E90
#define CListWnd__DrawItem_x                                       0x8F9280
#define CListWnd__DrawLine_x                                       0x8F8B90
#define CListWnd__DrawSeparator_x                                  0x8F8AC0
#define CListWnd__EnableLine_x                                     0x8F8300
#define CListWnd__EnsureVisible_x                                  0x8FB990
#define CListWnd__ExtendSel_x                                      0x8FAF50
#define CListWnd__GetColumnMinWidth_x                              0x8F7E40
#define CListWnd__GetColumnWidth_x                                 0x8F7DB0
#define CListWnd__GetCurSel_x                                      0x8F7740
#define CListWnd__GetItemAtPoint_x                                 0x8F8570
#define CListWnd__GetItemAtPoint1_x                                0x8F85E0
#define CListWnd__GetItemData_x                                    0x8F77C0
#define CListWnd__GetItemHeight_x                                  0x8F7B80
#define CListWnd__GetItemIcon_x                                    0x8F7950
#define CListWnd__GetItemRect_x                                    0x8F83F0
#define CListWnd__GetItemText_x                                    0x8F7800
#define CListWnd__GetSelList_x                                     0x8FB0D0
#define CListWnd__GetSeparatorRect_x                               0x8F8820
#define CListWnd__InsertLine_x                                     0x8FAC30
#define CListWnd__RemoveLine_x                                     0x8FAD80
#define CListWnd__SetColors_x                                      0x8F9FD0
#define CListWnd__SetColumnJustification_x                         0x8F9D00
#define CListWnd__SetColumnWidth_x                                 0x8F9C20
#define CListWnd__SetCurSel_x                                      0x8FAE90
#define CListWnd__SetItemColor_x                                   0x8FB650
#define CListWnd__SetItemData_x                                    0x8FB610
#define CListWnd__SetItemText_x                                    0x8FB250
#define CListWnd__ShiftColumnSeparator_x                           0x8F9DC0
#define CListWnd__Sort_x                                           0x8F9AC0
#define CListWnd__ToggleSel_x                                      0x8FAEC0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x75F8F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x782AB0
#define CMerchantWnd__RequestBuyItem_x                             0x783390
#define CMerchantWnd__RequestSellItem_x                            0x7838D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x786710
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x783110
#define CMerchantWnd__ActualSelect_x                               0x78C280

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x88B910
#define CPacketScrambler__hton_x                                   0x88B900

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x914C50
#define CSidlManager__FindScreenPieceTemplate_x                    0x915060
#define CSidlManager__FindScreenPieceTemplate1_x                   0x914E50
#define CSidlManager__CreateLabel_x                                0x7E4160
#define CSidlManager__CreateXWndFromTemplate_x                     0x918130
#define CSidlManager__CreateXWndFromTemplate1_x                    0x918310

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9117A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9116A0
#define CSidlScreenWnd__ConvertToRes_x                             0x9364D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x911130
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x910E20
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x910EF0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x910FC0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x911C40
#define CSidlScreenWnd__EnableIniStorage_x                         0x912110
#define CSidlScreenWnd__GetSidlPiece_x                             0x911E30
#define CSidlScreenWnd__Init1_x                                    0x910A30
#define CSidlScreenWnd__LoadIniInfo_x                              0x912160
#define CSidlScreenWnd__LoadIniListWnd_x                           0x912CC0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x90FE30
#define CSidlScreenWnd__StoreIniInfo_x                             0x912830
#define CSidlScreenWnd__StoreIniVis_x                              0x912BA0
#define CSidlScreenWnd__WndNotification_x                          0x911B50
#define CSidlScreenWnd__GetChildItem_x                             0x912090
#define CSidlScreenWnd__HandleLButtonUp_x                          0x901830
#define CSidlScreenWnd__m_layoutCopy_x                             0x169AB30

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65DFD0
#define CSkillMgr__GetSkillCap_x                                   0x65E1B0
#define CSkillMgr__GetNameToken_x                                  0x65D760

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x921C50
#define CSliderWnd__SetValue_x                                     0x921AC0
#define CSliderWnd__SetNumTicks_x                                  0x921B20

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7E9F10

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x928830
#define CStmlWnd__CalculateHSBRange_x                              0x9298C0
#define CStmlWnd__CalculateVSBRange_x                              0x929830
#define CStmlWnd__CanBreakAtCharacter_x                            0x92DC00
#define CStmlWnd__FastForwardToEndOfTag_x                          0x92E7F0
#define CStmlWnd__ForceParseNow_x                                  0x928DD0
#define CStmlWnd__GetNextTagPiece_x                                0x92DB60
#define CStmlWnd__GetSTMLText_x                                    0x4EFA30
#define CStmlWnd__GetVisibleText_x                                 0x928DF0
#define CStmlWnd__InitializeWindowVariables_x                      0x92E640
#define CStmlWnd__MakeStmlColorTag_x                               0x927FC0
#define CStmlWnd__MakeWndNotificationTag_x                         0x928030
#define CStmlWnd__SetSTMLText_x                                    0x927090
#define CStmlWnd__StripFirstSTMLLines_x                            0x92F950
#define CStmlWnd__UpdateHistoryString_x                            0x92EA00

// CTabWnd 
#define CTabWnd__Draw_x                                            0x932FE0
#define CTabWnd__DrawCurrentPage_x                                 0x933600
#define CTabWnd__DrawTab_x                                         0x9333D0
#define CTabWnd__GetCurrentPage_x                                  0x932840
#define CTabWnd__GetPageInnerRect_x                                0x932A80
#define CTabWnd__GetTabInnerRect_x                                 0x9329C0
#define CTabWnd__GetTabRect_x                                      0x932870
#define CTabWnd__InsertPage_x                                      0x932C70
#define CTabWnd__SetPage_x                                         0x932B00
#define CTabWnd__SetPageRect_x                                     0x932F20
#define CTabWnd__UpdatePage_x                                      0x933290
#define CTabWnd__GetPageFromTabIndex_x                             0x933310
#define CTabWnd__GetCurrentTabIndex_x                              0x932830

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x744D30
#define CPageWnd__SetTabText_x                                     0x9400F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5A30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8FE6B0
#define CTextureFont__GetTextExtent_x                              0x8FE870

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6916C0
#define CHtmlComponentWnd__ValidateUri_x                           0x723380
#define CHtmlWnd__SetClientCallbacks_x                             0x5FF120
#define CHtmlWnd__AddObserver_x                                    0x5FF140
#define CHtmlWnd__RemoveObserver_x                                 0x5FF1A0
#define Window__getProgress_x                                      0x83D190
#define Window__getStatus_x                                        0x83D1B0
#define Window__getURI_x                                           0x83D1C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x93C620

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8EB610

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AD2C0
#define CXStr__CXStr1_x                                            0x8F4100
#define CXStr__CXStr3_x                                            0x8D7840
#define CXStr__dCXStr_x                                            0x472490
#define CXStr__operator_equal_x                                    0x8D7A70
#define CXStr__operator_equal1_x                                   0x8D7AB0
#define CXStr__operator_plus_equal1_x                              0x8D8540

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x91FEF0
#define CXWnd__BringToTop_x                                        0x905010
#define CXWnd__Center_x                                            0x904B90
#define CXWnd__ClrFocus_x                                          0x9049D0
#define CXWnd__Destroy_x                                           0x904A70
#define CXWnd__DoAllDrawing_x                                      0x900FB0
#define CXWnd__DrawChildren_x                                      0x900F80
#define CXWnd__DrawColoredRect_x                                   0x901420
#define CXWnd__DrawTooltip_x                                       0x8FFB00
#define CXWnd__DrawTooltipAtPoint_x                                0x8FFBC0
#define CXWnd__GetBorderFrame_x                                    0x901280
#define CXWnd__GetChildWndAt_x                                     0x9050B0
#define CXWnd__GetClientClipRect_x                                 0x903280
#define CXWnd__GetScreenClipRect_x                                 0x903350
#define CXWnd__GetScreenRect_x                                     0x903510
#define CXWnd__GetTooltipRect_x                                    0x901470
#define CXWnd__GetWindowTextA_x                                    0x497180
#define CXWnd__IsActive_x                                          0x907F90
#define CXWnd__IsDescendantOf_x                                    0x903F30
#define CXWnd__IsReallyVisible_x                                   0x903F60
#define CXWnd__IsType_x                                            0x905710
#define CXWnd__Move_x                                              0x903FD0
#define CXWnd__Move1_x                                             0x904090
#define CXWnd__ProcessTransition_x                                 0x904B40
#define CXWnd__Refade_x                                            0x904360
#define CXWnd__Resize_x                                            0x9045E0
#define CXWnd__Right_x                                             0x904DD0
#define CXWnd__SetFocus_x                                          0x904990
#define CXWnd__SetFont_x                                           0x904A00
#define CXWnd__SetKeyTooltip_x                                     0x905540
#define CXWnd__SetMouseOver_x                                      0x9023E0
#define CXWnd__StartFade_x                                         0x903E00
#define CXWnd__GetChildItem_x                                      0x905220
#define CXWnd__SetParent_x                                         0x903CC0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9375A0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x907FD0
#define CXWndManager__DrawWindows_x                                0x907FF0
#define CXWndManager__GetKeyboardFlags_x                           0x90A770
#define CXWndManager__HandleKeyboardMsg_x                          0x90A370
#define CXWndManager__RemoveWnd_x                                  0x90A9B0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x90AEE0

// CDBStr
#define CDBStr__GetString_x                                        0x522470

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8030
#define EQ_Character__Cur_HP_x                                     0x4CE380
#define EQ_Character__Cur_Mana_x                                   0x4D5830
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BB180
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AEEB0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AF000
#define EQ_Character__GetHPRegen_x                                 0x4DAF00
#define EQ_Character__GetEnduranceRegen_x                          0x4DB510
#define EQ_Character__GetManaRegen_x                               0x4DB950
#define EQ_Character__Max_Endurance_x                              0x624CE0
#define EQ_Character__Max_HP_x                                     0x4CE1B0
#define EQ_Character__Max_Mana_x                                   0x624AE0
#define EQ_Character__doCombatAbility_x                            0x626E90
#define EQ_Character__UseSkill_x                                   0x4DD740
#define EQ_Character__GetConLevel_x                                0x61E2C0
#define EQ_Character__IsExpansionFlag_x                            0x5858F0
#define EQ_Character__TotalEffect_x                                0x4C1820
#define EQ_Character__GetPCSpellAffect_x                           0x4BBD70
#define EQ_Character__SpellDuration_x                              0x4BB8A0
#define EQ_Character__FindItemByRecord_x                           0x4D3990
#define EQ_Character__GetAdjustedSkill_x                           0x4D10C0
#define EQ_Character__GetBaseSkill_x                               0x4D2060
#define EQ_Character__CanUseItem_x                                 0x4D5B40

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8AA860

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x63AFC0

//PcClient
#define PcClient__PcClient_x                                       0x61BB80

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B5E10
#define CCharacterListWnd__EnterWorld_x                            0x4B5850
#define CCharacterListWnd__Quit_x                                  0x4B5560
#define CCharacterListWnd__UpdateList_x                            0x4B59E0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x600340
#define EQ_Item__CreateItemTagString_x                             0x885C30
#define EQ_Item__IsStackable_x                                     0x889DE0
#define EQ_Item__GetImageNum_x                                     0x8873F0
#define EQ_Item__CreateItemClient_x                                0x5FF500
#define EQ_Item__GetItemValue_x                                    0x8884A0
#define EQ_Item__ValueSellMerchant_x                               0x88B4B0
#define EQ_Item__IsKeyRingItem_x                                   0x8897B0
#define EQ_Item__CanGoInBag_x                                      0x600460
#define EQ_Item__GetMaxItemCount_x                                 0x8885A0
#define EQ_Item__GetHeldItem_x                                     0x8872C0
#define EQ_Item__GetAugmentFitBySlot_x                             0x885780

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x540430
#define EQ_LoadingS__Array_x                                       0xBDA298

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x625640
#define EQ_PC__GetAlternateAbilityId_x                             0x8945A0
#define EQ_PC__GetCombatAbility_x                                  0x894C10
#define EQ_PC__GetCombatAbilityTimer_x                             0x894C80
#define EQ_PC__GetItemRecastTimer_x                                0x627410
#define EQ_PC__HasLoreItem_x                                       0x61EA30
#define EQ_PC__AlertInventoryChanged_x                             0x61DD90
#define EQ_PC__GetPcZoneClient_x                                   0x6496D0
#define EQ_PC__RemoveMyAffect_x                                    0x62A540
#define EQ_PC__GetKeyRingItems_x                                   0x895520
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8952A0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x895810

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58BB40
#define EQItemList__add_object_x                                   0x5B7700
#define EQItemList__add_item_x                                     0x58C150
#define EQItemList__delete_item_x                                  0x58C1A0
#define EQItemList__FreeItemList_x                                 0x58C0A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x51FAF0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x63C840
#define EQPlayer__dEQPlayer_x                                      0x62FB50
#define EQPlayer__DoAttack_x                                       0x644400
#define EQPlayer__EQPlayer_x                                       0x630200
#define EQPlayer__SetNameSpriteState_x                             0x6348B0
#define EQPlayer__SetNameSpriteTint_x                              0x635740
#define PlayerBase__HasProperty_j_x                                0x96A980
#define EQPlayer__IsTargetable_x                                   0x96AE20
#define EQPlayer__CanSee_x                                         0x96AC80
#define EQPlayer__CanSee1_x                                        0x96AD50
#define PlayerBase__GetVisibilityLineSegment_x                     0x96AA40

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6471C0
#define PlayerZoneClient__GetLevel_x                               0x649710
#define PlayerZoneClient__IsValidTeleport_x                        0x5B8850
#define PlayerZoneClient__LegalPlayerRace_x                        0x539B00

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x63F520
#define EQPlayerManager__GetSpawnByName_x                          0x63F540
#define EQPlayerManager__GetPlayerFromPartialName_x                0x63F5D0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x603CE0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x603D20
#define KeypressHandler__ClearCommandStateArray_x                  0x605110
#define KeypressHandler__HandleKeyDown_x                           0x605130
#define KeypressHandler__HandleKeyUp_x                             0x6051D0
#define KeypressHandler__SaveKeymapping_x                          0x6055B0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x75B780
#define MapViewMap__SaveEx_x                                       0x75EB20
#define MapViewMap__SetZoom_x                                      0x7631F0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A8750

// StringTable 
#define StringTable__getString_x                                   0x8A3710

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x62A1B0
#define PcZoneClient__RemovePetEffect_x                            0x62A7E0
#define PcZoneClient__HasAlternateAbility_x                        0x624920
#define PcZoneClient__GetCurrentMod_x                              0x4E06B0
#define PcZoneClient__GetModCap_x                                  0x4E05B0
#define PcZoneClient__CanEquipItem_x                               0x624FD0
#define PcZoneClient__GetItemByID_x                                0x627880
#define PcZoneClient__GetItemByItemClass_x                         0x627910
#define PcZoneClient__RemoveBuffEffect_x                           0x62A800

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BD4F0

//IconCache
#define IconCache__GetIcon_x                                       0x6FBC90

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F3750
#define CContainerMgr__CloseContainer_x                            0x6F3A20
#define CContainerMgr__OpenExperimentContainer_x                   0x6F44A0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B6970

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F85A0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x751B10
#define CLootWnd__RequestLootSlot_x                                0x750ED0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x558B10
#define EQ_Spell__SpellAffects_x                                   0x558F80
#define EQ_Spell__SpellAffectBase_x                                0x558D40
#define EQ_Spell__IsStackable_x                                    0x4C6070
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5F20
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B33D0
#define EQ_Spell__IsSPAStacking_x                                  0x559D30
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5592D0
#define EQ_Spell__IsNoRemove_x                                     0x4C6050
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x559D40
#define __IsResEffectSpell_x                                       0x4C5390

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A9C40

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8B2AC0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7FC020
#define CTargetWnd__WndNotification_x                              0x7FB8B0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7FBB80
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7FAA10

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8006F0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x554080
#define EqSoundManager__PlayScriptMp3_x                            0x5541E0
#define EqSoundManager__SoundAssistPlay_x                          0x661B50
#define EqSoundManager__WaveInstancePlay_x                         0x661000

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x511560

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x923630

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x547FF0
#define CAltAbilityData__GetMercMaxRank_x                          0x547F90
#define CAltAbilityData__GetMaxRank_x                              0x53D740

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F66B0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5F00
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F7B90
#define CharacterBase__CreateItemIndex_x                           0x5FE730
#define CharacterBase__GetItemPossession_x                         0x4B3280
#define CharacterBase__GetItemByGlobalIndex_x                      0x8BB010
#define CharacterBase__GetEffectId_x                               0x4C5EB0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6DBC10
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6DC430

//messages
#define msg_spell_worn_off_x                                       0x57E1A0
#define msg_new_text_x                                             0x5733B0
#define __msgTokenTextParam_x                                      0x5807F0
#define msgTokenText_x                                             0x580A40

//SpellManager
#define SpellManager__vftable_x                                    0xAA4850
#define SpellManager__SpellManager_x                               0x664E40
#define Spellmanager__LoadTextSpells_x                             0x6656A0
#define SpellManager__GetSpellByGroupAndRank_x                     0x665010

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x96E960

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F8240
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x583F90
#define ItemGlobalIndex__IsEquippedLocation_x                      0x617380
#define ItemGlobalIndex__IsValidIndex_x                            0x4F82A0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B3400
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B3680

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x74A690

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F7EB0
#define CCursorAttachment__Deactivate_x                            0x6F8E80

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x935B10
#define CEQSuiteTextureLoader__GetTexture_x                        0x9357D0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F5210

//IString
#define IString__Append_x                                          0x4E9A80

//Camera
#define CDisplay__cameraType_x                                     0xDAA178
#define EverQuest__Cameras_x                                       0xE6D41C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FD950
#define LootFiltersManager__GetItemFilterData_x                    0x4FD240
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FD270
#define LootFiltersManager__SetItemLootFilter_x                    0x4FD490

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A4870

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x974760
#define CResolutionHandler__GetWindowedStyle_x                     0x65CAC0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6F0510

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
