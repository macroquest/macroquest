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
#define __ExpectedVersionDate                                     "Apr 24 2018"
#define __ExpectedVersionTime                                     "09:41:38"
#define __ActualVersionDate_x                                      0xABD24C
#define __ActualVersionTime_x                                      0xABD240

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x607C00
#define __MemChecker1_x                                            0x8D8530
#define __MemChecker2_x                                            0x695E00
#define __MemChecker3_x                                            0x695D50
#define __MemChecker4_x                                            0x830730
#define __EncryptPad0_x                                            0xBF0FD0
#define __EncryptPad1_x                                            0xC4EED0
#define __EncryptPad2_x                                            0xC01B58
#define __EncryptPad3_x                                            0xC01758
#define __EncryptPad4_x                                            0xC3FC80
#define __EncryptPad5_x                                            0xF0CAA4
#define __AC1_x                                                    0x7EE366
#define __AC2_x                                                    0x5C40CF
#define __AC3_x                                                    0x5CAF5F
#define __AC4_x                                                    0x5CEE00
#define __AC5_x                                                    0x5D5040
#define __AC6_x                                                    0x5D9442
#define __AC7_x                                                    0x5C3B40
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1AC54C

// Direct Input
#define DI8__Main_x                                                0xF0CAC8
#define DI8__Keyboard_x                                            0xF0CACC
#define DI8__Mouse_x                                               0xF0CA90
#define DI8__Mouse_Copy_x                                          0xE6A81C
#define DI8__Mouse_Check_x                                         0xF0D990
#define __AutoSkillArray_x                                         0xE6B72C
#define __Attack_x                                                 0xF09507
#define __Autofire_x                                               0xF09508
#define __BindList_x                                               0xBDFBD8
#define g_eqCommandStates_x                                        0xBE0940
#define __Clicks_x                                                 0xE6A8D4
#define __CommandList_x                                            0xBE14F8
#define __CurrentMapLabel_x                                        0x101F15C
#define __CurrentSocial_x                                          0xBCB260
#define __DoAbilityList_x                                          0xEA1028
#define __do_loot_x                                                0x591900
#define __DrawHandler_x                                            0x169A598
#define __GroupCount_x                                             0xE5D1CA
#define __Guilds_x                                                 0xE61028
#define __gWorld_x                                                 0xE5B01C
#define __HWnd_x                                                   0xF0CA94
#define __heqmain_x                                                0x1017CEC
#define __InChatMode_x                                             0xE6A804
#define __LastTell_x                                               0xE6C724
#define __LMouseHeldTime_x                                         0xE6A940
#define __Mouse_x                                                  0xF0CAB0
#define __MouseLook_x                                              0xE6A89A
#define __MouseEventTime_x                                         0xF09FC0
#define __gpbCommandEvent_x                                        0xE5AB40
#define __NetStatusToggle_x                                        0xE6A89D
#define __PCNames_x                                                0xE6BCE8
#define __RangeAttackReady_x                                       0xE6BA10
#define __RMouseHeldTime_x                                         0xE6A93C
#define __RunWalkState_x                                           0xE6A808
#define __ScreenMode_x                                             0xDA9380
#define __ScreenX_x                                                0xE6A7BC
#define __ScreenY_x                                                0xE6A7B8
#define __ScreenXMax_x                                             0xE6A7C0
#define __ScreenYMax_x                                             0xE6A7C4
#define __ServerHost_x                                             0xE5AD0B
#define __ServerName_x                                             0xEA0FE8
#define __ShiftKeyDown_x                                           0xE6AE94
#define __ShowNames_x                                              0xE6BBC8
#define __Socials_x                                                0xEA10E8
#define __SubscriptionType_x                                       0x1060B9C
#define __TargetAggroHolder_x                                      0x1021B2C
#define __ZoneType_x                                               0xE6AC98
#define __GroupAggro_x                                             0x1021B6C
#define __LoginName_x                                              0xF0D63C
#define __Inviter_x                                                0xF09484
#define __AttackOnAssist_x                                         0xE6BB84
#define __UseTellWindows_x                                         0xE6BE80

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE5D3D0
#define instEQZoneInfo_x                                           0xE6AA90
#define instKeypressHandler_x                                      0xF09F70
#define pinstActiveBanker_x                                        0xE5D160
#define pinstActiveCorpse_x                                        0xE5D158
#define pinstActiveGMaster_x                                       0xE5D15C
#define pinstActiveMerchant_x                                      0xE5D154
#define pinstAggroInfo_x                                           0xC657E0
#define pinstAltAdvManager_x                                       0xDA9D70
#define pinstAuraMgr_x                                             0xC76458
#define pinstBandageTarget_x                                       0xE5D170
#define pinstCamActor_x                                            0xDA9370
#define pinstCDBStr_x                                              0xDA8AC4
#define pinstCDisplay_x                                            0xE5D3B8
#define pinstCEverQuest_x                                          0xF0CBE8
#define pinstEverQuestInfo_x                                       0xE6A7B0
#define pinstCharData_x                                            0xE5D3C8
#define pinstCharSpawn_x                                           0xE5D1A8
#define pinstControlledMissile_x                                   0xE5AAC0
#define pinstControlledPlayer_x                                    0xE5D1A8
#define pinstCResolutionHandler_x                                  0x169A7C8
#define pinstCSidlManager_x                                        0x169965C
#define pinstCXWndManager_x                                        0x1699650
#define instDynamicZone_x                                          0xE60F00
#define pinstDZMember_x                                            0xE61010
#define pinstDZTimerInfo_x                                         0xE61014
#define pinstEQItemList_x                                          0xE595C0
#define pinstEQObjectList_x                                        0xE5A7B0
#define instEQMisc_x                                               0xDA8A00
#define pinstEQSoundManager_x                                      0xDAA5D0
#define pinstEQSpellStrings_x                                      0xC738A8
#define instExpeditionLeader_x                                     0xE60F4A
#define instExpeditionName_x                                       0xE60F8A
#define pinstGroup_x                                               0xE5D1C6
#define pinstImeManager_x                                          0x1699654
#define pinstLocalPlayer_x                                         0xE5D150
#define pinstMercenaryData_x                                       0xF0A760
#define pinstMercenaryStats_x                                      0x1021C78
#define pinstMercAltAbilities_x                                    0xDAA340
#define pinstModelPlayer_x                                         0xE5D168
#define pinstPCData_x                                              0xE5D3C8
#define pinstRealEstateItems_x                                     0xF0BC50
#define pinstSkillMgr_x                                            0xF0BD20
#define pinstSpawnManager_x                                        0xF0B310
#define pinstSpellManager_x                                        0xF0BEF8
#define pinstSpellSets_x                                           0xF02130
#define pinstStringTable_x                                         0xE5D024
#define pinstSwitchManager_x                                       0xE5A970
#define pinstTarget_x                                              0xE5D1A4
#define pinstTargetObject_x                                        0xE5D1B4
#define pinstTargetSwitch_x                                        0xE5AAE0
#define pinstTaskMember_x                                          0xDA8890
#define pinstTrackTarget_x                                         0xE5D1AC
#define pinstTradeTarget_x                                         0xE5D164
#define instTributeActive_x                                        0xDA8A25
#define pinstViewActor_x                                           0xDA936C
#define pinstWorldData_x                                           0xE5AE14
#define pinstZoneAddr_x                                            0xE6AD30
#define pinstPlayerPath_x                                          0xF0B3A8
#define pinstTargetIndicator_x                                     0xF0C160
#define pinstCTargetManager_x                                      0xF0C1F8
#define EQObject_Top_x                                             0xE5D14C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDA8B84
#define pinstCAchievementsWnd_x                                    0xDA8E2C
#define pinstCActionsWnd_x                                         0xDA8DE0
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDA8B64
#define pinstCAdvancedLootWnd_x                                    0xDA93AC
#define pinstCAdventureLeaderboardWnd_x                            0x1018888
#define pinstCAdventureRequestWnd_x                                0x1018938
#define pinstCAdventureStatsWnd_x                                  0x10189E8
#define pinstCAggroMeterWnd_x                                      0xDA8E54
#define pinstCAlarmWnd_x                                           0xDA8E14
#define pinstCAlertHistoryWnd_x                                    0xDA8DEC
#define pinstCAlertStackWnd_x                                      0xDA8B78
#define pinstCAlertWnd_x                                           0xDA8B8C
#define pinstCAltStorageWnd_x                                      0x1018D48
#define pinstCAudioTriggersWindow_x                                0xC65C70
#define pinstCAuraWnd_x                                            0xDA8E4C
#define pinstCAvaZoneWnd_x                                         0xDA8DCC
#define pinstCBandolierWnd_x                                       0xDA8F04
#define pinstCBankWnd_x                                            0xDA93A8
#define pinstCBarterMerchantWnd_x                                  0x1019F88
#define pinstCBarterSearchWnd_x                                    0x101A038
#define pinstCBarterWnd_x                                          0x101A0E8
#define pinstCBazaarConfirmationWnd_x                              0xDA8B74
#define pinstCBazaarSearchWnd_x                                    0xDA8E04
#define pinstCBazaarWnd_x                                          0xDA8E7C
#define pinstCBlockedBuffWnd_x                                     0xDA9394
#define pinstCBlockedPetBuffWnd_x                                  0xDA93BC
#define pinstCBodyTintWnd_x                                        0xDA8BA0
#define pinstCBookWnd_x                                            0xDA9318
#define pinstCBreathWnd_x                                          0xDA8B98
#define pinstCBuffWindowNORMAL_x                                   0xDA9358
#define pinstCBuffWindowSHORT_x                                    0xDA935C
#define pinstCBugReportWnd_x                                       0xDA8B80
#define pinstCButtonWnd_x                                          0x1699810
#define pinstCCastingWnd_x                                         0xDA8B60
#define pinstCCastSpellWnd_x                                       0xDA8E0C
//#define pinstCCharacterCreationWnd_x                               0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDA8BA4
#define pinstCChatWindowManager_x                                  0x101ABA8
#define pinstCClaimWnd_x                                           0x101AD00
#define pinstCColorPickerWnd_x                                     0xDA8DBC
#define pinstCCombatAbilityWnd_x                                   0xDA8E50
#define pinstCCombatSkillsSelectWnd_x                              0xDA8DE4
#define pinstCCompassWnd_x                                         0xDA8B88
#define pinstCConfirmationDialog_x                                 0x101FCA8
#define pinstCContainerMgr_x                                       0xDA8F00
#define pinstCContextMenuManager_x                                 0x1699610
#define pinstCCursorAttachment_x                                   0xDA93EC
#define pinstCDynamicZoneWnd_x                                     0x101B2C8
#define pinstCEditLabelWnd_x                                       0xDA9344
#define pinstCEQMainWnd_x                                          0x101B510
#define pinstCEventCalendarWnd_x                                   0xDA8E48
#define pinstCExtendedTargetWnd_x                                  0xDA8E44
#define pinstCFacePick_x                                           0xDA8DC4
#define pinstCFeedbackWnd_x                                        0xDA93F0
#define pinstCFellowshipWnd_x                                      0x101B7B8
#define pinstCFileSelectionWnd_x                                   0xDA9398
#define pinstCFindItemWnd_x                                        0xDA8E70
#define pinstCFindLocationWnd_x                                    0x101B910
#define pinstCFriendsWnd_x                                         0xDA8E00
#define pinstCGemsGameWnd_x                                        0xDA8DE8
#define pinstCGiveWnd_x                                            0xDA9314
#define pinstCGroupSearchFiltersWnd_x                              0xDA8E68
#define pinstCGroupSearchWnd_x                                     0x101BD08
#define pinstCGroupWnd_x                                           0x101BDB8
#define pinstCGuildBankWnd_x                                       0xE6BB6C
#define pinstCGuildCreationWnd_x                                   0x101BF18
#define pinstCGuildMgmtWnd_x                                       0x101BFC8
#define pinstCharacterCreation_x                                   0xDA8E5C
#define pinstCHelpWnd_x                                            0xDA8E1C
#define pinstCHeritageSelectionWnd_x                               0xDA8DD0
#define pinstCHotButtonWnd_x                                       0x101E120
#define pinstCHotButtonWnd1_x                                      0x101E120
#define pinstCHotButtonWnd2_x                                      0x101E124
#define pinstCHotButtonWnd3_x                                      0x101E128
#define pinstCHotButtonWnd4_x                                      0x101E12C
#define pinstCIconSelectionWnd_x                                   0xDA93C8
#define pinstCInspectWnd_x                                         0xDA93B8
#define pinstCInventoryWnd_x                                       0xDA8EFC
#define pinstCInvSlotMgr_x                                         0xDA8E40
#define pinstCItemDisplayManager_x                                 0x101E6B0
#define pinstCItemExpTransferWnd_x                                 0x101E7E4
#define pinstCItemOverflowWnd_x                                    0xDA8DF4
#define pinstCJournalCatWnd_x                                      0xDA93C0
//#define pinstCJournalNPCWnd_x                                      0xDAB354
#define pinstCJournalTextWnd_x                                     0xDA9354
#define pinstCKeyRingWnd_x                                         0xDA9360
#define pinstCLargeDialogWnd_x                                     0x1020928
#define pinstCLayoutCopyWnd_x                                      0x101EB30
#define pinstCLFGuildWnd_x                                         0x101EBE0
#define pinstCLoadskinWnd_x                                        0xDA8DFC
#define pinstCLootFiltersCopyWnd_x                                 0xC76C38
#define pinstCLootFiltersWnd_x                                     0xDA8BAC
#define pinstCLootSettingsWnd_x                                    0xDA8DB8
#define pinstCLootWnd_x                                            0xDA8DB0
#define pinstCMailAddressBookWnd_x                                 0xDA93D0
#define pinstCMailCompositionWnd_x                                 0xDA93B4
#define pinstCMailIgnoreListWnd_x                                  0xDA93D4
#define pinstCMailWnd_x                                            0xDA9374
#define pinstCManageLootWnd_x                                      0xDAA1E8
#define pinstCMapToolbarWnd_x                                      0xDA9310
#define pinstCMapViewWnd_x                                         0xDA8E74
#define pinstCMarketplaceWnd_x                                     0xDA8E78
#define pinstCMerchantWnd_x                                        0xDA8DD8
#define pinstCMIZoneSelectWnd_x                                    0x101F418
#define pinstCMusicPlayerWnd_x                                     0xDA9364
#define pinstCNameChangeMercWnd_x                                  0xDA93B0
#define pinstCNameChangePetWnd_x                                   0xDA938C
#define pinstCNameChangeWnd_x                                      0xDA8E58
#define pinstCNoteWnd_x                                            0xDA8E18
#define pinstCObjectPreviewWnd_x                                   0xDA9320
#define pinstCOptionsWnd_x                                         0xDA8F08
#define pinstCPetInfoWnd_x                                         0xDA93A4
#define pinstCPetitionQWnd_x                                       0xDA93C4
//#define pinstCPlayerCustomizationWnd_x                             0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDA8B9C
#define pinstCPlayerWnd_x                                          0xDA8E08
#define pinstCPopupWndManager_x                                    0x101FCA8
#define pinstCProgressionSelectionWnd_x                            0x101FD58
#define pinstCPurchaseGroupWnd_x                                   0xDA9368
#define pinstCPurchaseWnd_x                                        0xDA934C
#define pinstCPvPLeaderboardWnd_x                                  0x101FE08
#define pinstCPvPStatsWnd_x                                        0x101FEB8
#define pinstCQuantityWnd_x                                        0xDA93CC
#define pinstCRaceChangeWnd_x                                      0xDA8E84
#define pinstCRaidOptionsWnd_x                                     0xDA8E6C
#define pinstCRaidWnd_x                                            0xDA93E0
#define pinstCRealEstateItemsWnd_x                                 0xDA8E38
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDA8E60
#define pinstCRealEstateManageWnd_x                                0xDA8DD4
#define pinstCRealEstateNeighborhoodWnd_x                          0xDA8DF0
#define pinstCRealEstatePlotSearchWnd_x                            0xDA8E10
#define pinstCRealEstatePurchaseWnd_x                              0xDA8E24
#define pinstCRespawnWnd_x                                         0xDA8E64
//#define pinstCRewardSelectionWnd_x                                 0x1022600
#define pinstCSelectorWnd_x                                        0xDA8E3C
#define pinstCSendMoneyWnd_x                                       0xDA9334
#define pinstCServerListWnd_x                                      0xDA8E30
#define pinstCSkillsSelectWnd_x                                    0xDA8DC0
#define pinstCSkillsWnd_x                                          0xDA8DB4
#define pinstCSocialEditWnd_x                                      0xDA93DC
#define pinstCSocialWnd_x                                          0xDA93E4
#define pinstCSpellBookWnd_x                                       0xDA8E34
#define pinstCStoryWnd_x                                           0xDA8B7C
#define pinstCTargetOfTargetWnd_x                                  0x1021D00
#define pinstCTargetWnd_x                                          0xDA939C
#define pinstCTaskOverlayWnd_x                                     0xDA8DF8
#define pinstCTaskSelectWnd_x                                      0x1021E58
#define pinstCTaskSomething_x                                      0xC77438
#define pinstCTaskTemplateSelectWnd_x                              0x1021F08
#define pinstCTaskWnd_x                                            0x1021FB8
#define pinstCTextEntryWnd_x                                       0xDA8B90
#define pinstCTextOverlay_x                                        0xC65F10
#define pinstCTimeLeftWnd_x                                        0xDA93A0
#define pinstCTipWndCONTEXT_x                                      0x10221BC
#define pinstCTipWndOFDAY_x                                        0x10221B8
#define pinstCTitleWnd_x                                           0x1022268
#define pinstCTrackingWnd_x                                        0xDA9390
#define pinstCTradeskillWnd_x                                      0x10223D0
#define pinstCTradeWnd_x                                           0xDA8E20
#define pinstCTrainWnd_x                                           0xDA93D8
#define pinstCTributeBenefitWnd_x                                  0x10225D0
#define pinstCTributeMasterWnd_x                                   0x1022680
#define pinstCTributeTrophyWnd_x                                   0x1022730
#define pinstCVideoModesWnd_x                                      0xDA93E8
#define pinstCVoiceMacroWnd_x                                      0xF0C728
#define pinstCVoteResultsWnd_x                                     0xDA9350
#define pinstCVoteWnd_x                                            0xDA931C
#define pinstCWebManager_x                                         0xF0C88C
#define pinstCZoneGuideWnd_x                                       0xDA8DC8
#define pinstCZonePathWnd_x                                        0xDA8DDC

#define pinstEQSuiteTextureLoader_x                                0xC50970
#define pinstItemIconCache_x                                       0x101B4C8
#define pinstLootFiltersManager_x                                  0xC76CE8
#define pinstRewardSelectionWnd_x                                  0x1020600

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC0174C
#define __CastRay_x                                                0x58CE20
#define __CastRay2_x                                               0x58CE70
#define __ConvertItemTags_x                                        0x5A7A40
#define __CrashHandler_x                                           0x83A250
#define __EQGetTime_x                                              0x8D7E50
#define __ExecuteCmd_x                                             0x5858B0
#define __FixHeading_x                                             0x9689A0
#define __get_bearing_x                                            0x58C960
#define __get_melee_range_x                                        0x58D060
#define __GetAnimationCache_x                                      0x6F95C0
#define __GetGaugeValueFromEQ_x                                    0x7ECB80
#define __GetLabelFromEQ_x                                         0x7EE2F0
#define __GetXTargetType_x                                         0x96A470
#define __HeadingDiff_x                                            0x968A10
#define __HelpPath_x                                               0xF09BDC
#define __LoadFrontEnd_x                                           0x691C40
#define __NewUIINI_x                                               0x7EC850
#define __pCrashHandler_x                                          0x103F9F8
#define __ProcessGameEvents_x                                      0x5E9D30
#define __ProcessMouseEvent_x                                      0x5E94F0
#define __SaveColors_x                                             0x537BF0
#define __STMLToText_x                                             0x90BD90
#define __ToggleKeyRingItem_x                                      0x4FAE90
#define CrashDetected_x                                            0x693730
#define DrawNetStatus_x                                            0x615100
#define Expansion_HoT_x                                            0xE6BB74
#define Teleport_Table_Size_x                                      0xE5ABC8
#define Teleport_Table_x                                           0xE5B020
#define Util__FastTime_x                                           0x8D7A10
#define wwsCrashReportCheckForUploader_x                           0x83AC90
#define wwsCrashReportPlatformLaunchUploader_x                     0x83D350
#define __SaveColors_x                                             0x537BF0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48A9C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x493770
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x493550

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x53F190
#define AltAdvManager__IsAbilityReady_x                            0x53E250
#define AltAdvManager__GetAAById_x                                 0x53E450
#define AltAdvManager__CanTrainAbility_x                           0x53E4C0
#define AltAdvManager__CanSeeAbility_x                             0x53E6F0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C5B80
#define CharacterZoneClient__HasSkill_x                            0x4D0D10
#define CharacterZoneClient__MakeMeVisible_x                       0x4D2430
#define CharacterZoneClient__IsStackBlocked_x                      0x4B9DE0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B64B0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D4980
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D4A60
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D4B40
#define CharacterZoneClient__FindAffectSlot_x                      0x4BE8C0
#define CharacterZoneClient__BardCastBard_x                        0x4C1640
#define CharacterZoneClient__GetMaxEffects_x                       0x4B6580
#define CharacterZoneClient__GetEffect_x                           0x4B63F0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4BF8D0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4BF9A0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4BF9F0
#define CharacterZoneClient__CalcAffectChange_x                    0x4BFB40
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4BFD10

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6BBF80

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6C9AE0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5F7C10
#define CButtonWnd__CButtonWnd_x                                   0x908160

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6E7F10
#define CChatManager__InitContextMenu_x                            0x6E2360
#define CChatManager__FreeChatWindow_x                             0x6E6EA0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6EB7C0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6E7CB0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x91C940
#define CContextMenu__dCContextMenu_x                              0x91CB70
#define CContextMenu__AddMenuItem_x                                0x91CB80
#define CContextMenu__RemoveMenuItem_x                             0x91CE90
#define CContextMenu__RemoveAllMenuItems_x                         0x91CEB0
#define CContextMenu__CheckMenuItem_x                              0x91CF30
#define CContextMenu__SetMenuItem_x                                0x91CDB0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x91D4D0
#define CContextMenuManager__RemoveMenu_x                          0x91D540
#define CContextMenuManager__PopupMenu_x                           0x91D600
#define CContextMenuManager__Flush_x                               0x91D470
#define CContextMenuManager__GetMenu_x                             0x4956B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8BA3C0
#define CChatService__GetFriendName_x                              0x8BA3D0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6E8480
#define CChatWindow__Clear_x                                       0x6E94E0
#define CChatWindow__WndNotification_x                             0x6E9A50

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x919DC0
#define CComboWnd__Draw_x                                          0x9192B0
#define CComboWnd__GetCurChoice_x                                  0x919C00
#define CComboWnd__GetListRect_x                                   0x919760
#define CComboWnd__GetTextRect_x                                   0x919E30
#define CComboWnd__InsertChoice_x                                  0x9198F0
#define CComboWnd__SetColors_x                                     0x9198C0
#define CComboWnd__SetChoice_x                                     0x919BD0
#define CComboWnd__GetItemCount_x                                  0x919C10
#define CComboWnd__GetCurChoiceText_x                              0x919C50

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6F1760
#define CContainerWnd__vftable_x                                   0xAC6630

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x5379B0
#define CDisplay__GetClickedActor_x                                0x52A9C0
#define CDisplay__GetUserDefinedColor_x                            0x5230C0
#define CDisplay__GetWorldFilePath_x                               0x52C410
#define CDisplay__is3dON_x                                         0x5276B0
#define CDisplay__ReloadUI_x                                       0x531B30
#define CDisplay__WriteTextHD2_x                                   0x527490
#define CDisplay__TrueDistance_x                                   0x52E070

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x93C200

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x920360
#define CEditWnd__GetCharIndexPt_x                                 0x921260
#define CEditWnd__GetDisplayString_x                               0x921100
#define CEditWnd__GetHorzOffset_x                                  0x91F990
#define CEditWnd__GetLineForPrintableChar_x                        0x9223A0
#define CEditWnd__GetSelStartPt_x                                  0x921510
#define CEditWnd__GetSTMLSafeText_x                                0x920F20
#define CEditWnd__PointFromPrintableChar_x                         0x921FD0
#define CEditWnd__SelectableCharFromPoint_x                        0x922140
#define CEditWnd__SetEditable_x                                    0x9215E0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5D8970
#define CEverQuest__ClickedPlayer_x                                0x5CAD40
#define CEverQuest__CreateTargetIndicator_x                        0x5E7010
#define CEverQuest__DeleteTargetIndicator_x                        0x5E70A0
#define CEverQuest__DoTellWindow_x                                 0x4E0CC0
#define CEverQuest__OutputTextToLog_x                              0x4E0EF0
#define CEverQuest__DropHeldItemOnGround_x                         0x5C0600
#define CEverQuest__dsp_chat_x                                     0x4E12C0
#define CEverQuest__trimName_x                                     0x5E3690
#define CEverQuest__Emote_x                                        0x5D9180
#define CEverQuest__EnterZone_x                                    0x5D3430
#define CEverQuest__GetBodyTypeDesc_x                              0x5DCF20
#define CEverQuest__GetClassDesc_x                                 0x5DD560
#define CEverQuest__GetClassThreeLetterCode_x                      0x5DDB60
#define CEverQuest__GetDeityDesc_x                                 0x5E5A20
#define CEverQuest__GetLangDesc_x                                  0x5DDD20
#define CEverQuest__GetRaceDesc_x                                  0x5DD540
#define CEverQuest__InterpretCmd_x                                 0x5E5FF0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5C47F0
#define CEverQuest__LMouseUp_x                                     0x5C2B70
#define CEverQuest__RightClickedOnPlayer_x                         0x5C50D0
#define CEverQuest__RMouseUp_x                                     0x5C3B00
#define CEverQuest__SetGameState_x                                 0x5C0390
#define CEverQuest__UPCNotificationFlush_x                         0x5E3590
#define CEverQuest__IssuePetCommand_x                              0x5DF120
#define CEverQuest__ReportSuccessfulHit_x                          0x5D9E20

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x703DB0
#define CGaugeWnd__CalcLinesFillRect_x                             0x703E10
#define CGaugeWnd__Draw_x                                          0x7034A0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ABA30
#define CGuild__GetGuildName_x                                     0x4AAA70
#define CGuild__GetGuildIndex_x                                    0x4AAE00

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x71F2D0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x72C090
#define CInvSlotMgr__MoveItem_x                                    0x72ADF0
#define CInvSlotMgr__SelectSlot_x                                  0x72C160

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7296A0
#define CInvSlot__SliderComplete_x                                 0x7274D0
#define CInvSlot__GetItemBase_x                                    0x726E60
#define CInvSlot__UpdateItem_x                                     0x726FD0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x72DA90
#define CInvSlotWnd__CInvSlotWnd_x                                 0x72CD60

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7E8DE0
#define CItemDisplayWnd__UpdateStrings_x                           0x73B810
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x735990
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x735E70
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x73BDA0
#define CItemDisplayWnd__AboutToShow_x                             0x73B480
#define CItemDisplayWnd__WndNotification_x                         0x73D060

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8206F0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7410D0

// CLabel 
#define CLabel__Draw_x                                             0x746B30

// CListWnd
#define CListWnd__CListWnd_x                                       0x8F2400
#define CListWnd__dCListWnd_x                                      0x8F2720
#define CListWnd__AddColumn_x                                      0x8F6A40
#define CListWnd__AddColumn1_x                                     0x8F6A90
#define CListWnd__AddLine_x                                        0x8F6E20
#define CListWnd__AddString_x                                      0x8F6C20
#define CListWnd__CalculateFirstVisibleLine_x                      0x8F6810
#define CListWnd__CalculateVSBRange_x                              0x8F65F0
#define CListWnd__ClearSel_x                                       0x8F7600
#define CListWnd__ClearAllSel_x                                    0x8F7660
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8F8040
#define CListWnd__Compare_x                                        0x8F5F30
#define CListWnd__Draw_x                                           0x8F2820
#define CListWnd__DrawColumnSeparators_x                           0x8F5000
#define CListWnd__DrawHeader_x                                     0x8F5470
#define CListWnd__DrawItem_x                                       0x8F5870
#define CListWnd__DrawLine_x                                       0x8F5170
#define CListWnd__DrawSeparator_x                                  0x8F50A0
#define CListWnd__EnableLine_x                                     0x8F48E0
#define CListWnd__EnsureVisible_x                                  0x8F7F70
#define CListWnd__ExtendSel_x                                      0x8F7530
#define CListWnd__GetColumnMinWidth_x                              0x8F4420
#define CListWnd__GetColumnWidth_x                                 0x8F4390
#define CListWnd__GetCurSel_x                                      0x8F3D20
#define CListWnd__GetItemAtPoint_x                                 0x8F4B50
#define CListWnd__GetItemAtPoint1_x                                0x8F4BC0
#define CListWnd__GetItemData_x                                    0x8F3DA0
#define CListWnd__GetItemHeight_x                                  0x8F4160
#define CListWnd__GetItemIcon_x                                    0x8F3F30
#define CListWnd__GetItemRect_x                                    0x8F49D0
#define CListWnd__GetItemText_x                                    0x8F3DE0
#define CListWnd__GetSelList_x                                     0x8F76B0
#define CListWnd__GetSeparatorRect_x                               0x8F4E00
#define CListWnd__InsertLine_x                                     0x8F7210
#define CListWnd__RemoveLine_x                                     0x8F7360
#define CListWnd__SetColors_x                                      0x8F65C0
#define CListWnd__SetColumnJustification_x                         0x8F62F0
#define CListWnd__SetColumnWidth_x                                 0x8F6210
#define CListWnd__SetCurSel_x                                      0x8F7470
#define CListWnd__SetItemColor_x                                   0x8F7C30
#define CListWnd__SetItemData_x                                    0x8F7BF0
#define CListWnd__SetItemText_x                                    0x8F7830
#define CListWnd__ShiftColumnSeparator_x                           0x8F63B0
#define CListWnd__Sort_x                                           0x8F60B0
#define CListWnd__ToggleSel_x                                      0x8F74A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x75BFD0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x77F240
#define CMerchantWnd__RequestBuyItem_x                             0x77FB20
#define CMerchantWnd__RequestSellItem_x                            0x780050
#define CMerchantWnd__SelectRecoverySlot_x                         0x782E80
//did this get another arg?
#define CMerchantWnd__SelectBuySellSlot_x                          0x77F8A0
#define CMerchantWnd__ActualSelect_x                               0x7889A0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x886B40
#define CPacketScrambler__hton_x                                   0x886B30

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9113A0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9117B0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9115A0
#define CSidlManager__CreateLabel_x                                0x7E0260
#define CSidlManager__CreateXWndFromTemplate_x                     0x914880
#define CSidlManager__CreateXWndFromTemplate1_x                    0x914A50

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x90DEF0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x90DE00
#define CSidlScreenWnd__ConvertToRes_x                             0x932A60
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x90D890
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x90D580
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x90D650
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x90D720
#define CSidlScreenWnd__DrawSidlPiece_x                            0x90E380
#define CSidlScreenWnd__EnableIniStorage_x                         0x90E850
#define CSidlScreenWnd__GetSidlPiece_x                             0x90E570
#define CSidlScreenWnd__Init1_x                                    0x90D170
#define CSidlScreenWnd__LoadIniInfo_x                              0x90E8A0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x90F400
#define CSidlScreenWnd__LoadSidlScreen_x                           0x90C570
#define CSidlScreenWnd__StoreIniInfo_x                             0x90EF70
#define CSidlScreenWnd__StoreIniVis_x                              0x90F2E0
#define CSidlScreenWnd__WndNotification_x                          0x90E290
#define CSidlScreenWnd__GetChildItem_x                             0x90E7D0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8FDEF0
#define CSidlScreenWnd__m_layoutCopy_x                             0x16994E0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x65B8F0
#define CSkillMgr__GetSkillCap_x                                   0x65BAD0
#define CSkillMgr__GetNameToken_x                                  0x65B080

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x932130
#define CSliderWnd__SetValue_x                                     0x931FA0
#define CSliderWnd__SetNumTicks_x                                  0x932000

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7E6080

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x924210
#define CStmlWnd__CalculateHSBRange_x                              0x9252C0
#define CStmlWnd__CalculateVSBRange_x                              0x925240
#define CStmlWnd__CanBreakAtCharacter_x                            0x9295D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x92A160
#define CStmlWnd__ForceParseNow_x                                  0x924800
#define CStmlWnd__GetNextTagPiece_x                                0x929530
#define CStmlWnd__GetSTMLText_x                                    0x4EF130
#define CStmlWnd__GetVisibleText_x                                 0x924820
#define CStmlWnd__InitializeWindowVariables_x                      0x929FB0
#define CStmlWnd__MakeStmlColorTag_x                               0x9239A0
#define CStmlWnd__MakeWndNotificationTag_x                         0x923A10
#define CStmlWnd__SetSTMLText_x                                    0x922A90
#define CStmlWnd__StripFirstSTMLLines_x                            0x92B2B0
#define CStmlWnd__UpdateHistoryString_x                            0x92A370

// CTabWnd 
#define CTabWnd__Draw_x                                            0x92E920
#define CTabWnd__DrawCurrentPage_x                                 0x92EF40
#define CTabWnd__DrawTab_x                                         0x92ED10
#define CTabWnd__GetCurrentPage_x                                  0x92E180
#define CTabWnd__GetPageInnerRect_x                                0x92E3C0
#define CTabWnd__GetTabInnerRect_x                                 0x92E300
#define CTabWnd__GetTabRect_x                                      0x92E1B0
#define CTabWnd__InsertPage_x                                      0x92E5B0
#define CTabWnd__SetPage_x                                         0x92E440
#define CTabWnd__SetPageRect_x                                     0x92E860
#define CTabWnd__UpdatePage_x                                      0x92EBD0
#define CTabWnd__GetPageFromTabIndex_x                             0x92EC50
#define CTabWnd__GetCurrentTabIndex_x                              0x92E170

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x741530
#define CPageWnd__SetTabText_x                                     0x93C610

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A5480

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8FAD60
#define CTextureFont__GetTextExtent_x                              0x8FAF20

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x68EA00
#define CHtmlComponentWnd__ValidateUri_x                           0x720C30
#define CHtmlWnd__SetClientCallbacks_x                             0x5FCD30
#define CHtmlWnd__AddObserver_x                                    0x5FCD50
#define CHtmlWnd__RemoveObserver_x                                 0x5FCDB0
#define Window__getProgress_x                                      0x837CE0
#define Window__getStatus_x                                        0x837D00
#define Window__getURI_x                                           0x837D10

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x938B90

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8E7E00

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ACD70
#define CXStr__CXStr1_x                                            0x828000
#define CXStr__CXStr3_x                                            0x8D3F80
#define CXStr__dCXStr_x                                            0x4724A0
#define CXStr__operator_equal_x                                    0x8D41B0
#define CXStr__operator_equal1_x                                   0x8D41F0
#define CXStr__operator_plus_equal1_x                              0x8D4C80

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x91C550
#define CXWnd__BringToTop_x                                        0x9016F0
#define CXWnd__Center_x                                            0x901270
#define CXWnd__ClrFocus_x                                          0x9010A0
#define CXWnd__Destroy_x                                           0x901150
#define CXWnd__DoAllDrawing_x                                      0x8FD680
#define CXWnd__DrawChildren_x                                      0x8FD650
#define CXWnd__DrawColoredRect_x                                   0x8FDAE0
#define CXWnd__DrawTooltip_x                                       0x8FC1B0
#define CXWnd__DrawTooltipAtPoint_x                                0x8FC270
#define CXWnd__GetBorderFrame_x                                    0x8FD940
#define CXWnd__GetChildWndAt_x                                     0x901790
#define CXWnd__GetClientClipRect_x                                 0x8FF950
#define CXWnd__GetScreenClipRect_x                                 0x8FFA00
#define CXWnd__GetScreenRect_x                                     0x8FFB80
#define CXWnd__GetTooltipRect_x                                    0x8FDB30
#define CXWnd__GetWindowTextA_x                                    0x496C80
#define CXWnd__IsActive_x                                          0x904670
#define CXWnd__IsDescendantOf_x                                    0x9005A0
#define CXWnd__IsReallyVisible_x                                   0x9005D0
#define CXWnd__IsType_x                                            0x901DF0
#define CXWnd__Move_x                                              0x900650
#define CXWnd__Move1_x                                             0x900710
#define CXWnd__ProcessTransition_x                                 0x901220
#define CXWnd__Refade_x                                            0x9009F0
#define CXWnd__Resize_x                                            0x900CB0
#define CXWnd__Right_x                                             0x9014B0
#define CXWnd__SetFocus_x                                          0x901060
#define CXWnd__SetFont_x                                           0x9010D0
#define CXWnd__SetKeyTooltip_x                                     0x901C10
#define CXWnd__SetMouseOver_x                                      0x8FEAA0
#define CXWnd__StartFade_x                                         0x900470
#define CXWnd__GetChildItem_x                                      0x901900
#define CXWnd__SetParent_x                                         0x900330

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x933B40

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9046B0
#define CXWndManager__DrawWindows_x                                0x9046D0
#define CXWndManager__GetKeyboardFlags_x                           0x906E40
#define CXWndManager__HandleKeyboardMsg_x                          0x906A40
#define CXWndManager__RemoveWnd_x                                  0x907090
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9075D0

// CDBStr
#define CDBStr__GetString_x                                        0x522050

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B7460
#define EQ_Character__Cur_HP_x                                     0x4CDDA0
#define EQ_Character__Cur_Mana_x                                   0x4D5040
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BA3C0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AE7F0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AE940
#define EQ_Character__GetHPRegen_x                                 0x4DA630
#define EQ_Character__GetEnduranceRegen_x                          0x4DAC60
#define EQ_Character__GetManaRegen_x                               0x4DB0A0
#define EQ_Character__Max_Endurance_x                              0x6227D0
#define EQ_Character__Max_HP_x                                     0x4CDBD0
#define EQ_Character__Max_Mana_x                                   0x622650
#define EQ_Character__doCombatAbility_x                            0x624920
#define EQ_Character__UseSkill_x                                   0x4DCE90
#define EQ_Character__GetConLevel_x                                0x61BE10
#define EQ_Character__IsExpansionFlag_x                            0x584260
#define EQ_Character__TotalEffect_x                                0x4C0BC0
#define EQ_Character__GetPCSpellAffect_x                           0x4BAFB0
#define EQ_Character__SpellDuration_x                              0x4BAAE0
#define EQ_Character__FindItemByRecord_x                           0x4D33A0
#define EQ_Character__GetAdjustedSkill_x                           0x4D0AD0
#define EQ_Character__GetBaseSkill_x                               0x4D1A70
#define EQ_Character__CanUseItem_x                                 0x4D5350

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8A59B0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x638A30

//PcClient
#define PcClient__PcClient_x                                       0x6196E0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B5240
#define CCharacterListWnd__EnterWorld_x                            0x4B4C80
#define CCharacterListWnd__Quit_x                                  0x4B4990
#define CCharacterListWnd__UpdateList_x                            0x4B4E10

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5FDF60
#define EQ_Item__CreateItemTagString_x                             0x880E70
#define EQ_Item__IsStackable_x                                     0x885030
#define EQ_Item__GetImageNum_x                                     0x8826B0
#define EQ_Item__CreateItemClient_x                                0x5FD130
#define EQ_Item__GetItemValue_x                                    0x883750
#define EQ_Item__ValueSellMerchant_x                               0x8866D0
#define EQ_Item__IsKeyRingItem_x                                   0x8849F0
#define EQ_Item__CanGoInBag_x                                      0x5FE080
#define EQ_Item__GetMaxItemCount_x                                 0x883850
#define EQ_Item__GetHeldItem_x                                     0x8824C0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8809C0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x53FEC0
#define EQ_LoadingS__Array_x                                       0xBD8DE8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6230D0
#define EQ_PC__GetAlternateAbilityId_x                             0x88F710
#define EQ_PC__GetCombatAbility_x                                  0x88FD80
#define EQ_PC__GetCombatAbilityTimer_x                             0x88FDF0
#define EQ_PC__GetItemRecastTimer_x                                0x624EA0
#define EQ_PC__HasLoreItem_x                                       0x61C580
#define EQ_PC__AlertInventoryChanged_x                             0x61B8D0
#define EQ_PC__GetPcZoneClient_x                                   0x647110
#define EQ_PC__RemoveMyAffect_x                                    0x628050
#define EQ_PC__GetKeyRingItems_x                                   0x890690
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x890410
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x890980

// EQItemList 
#define EQItemList__EQItemList_x                                   0x58A3C0
#define EQItemList__add_object_x                                   0x5B5D00
#define EQItemList__add_item_x                                     0x58A9D0
#define EQItemList__delete_item_x                                  0x58AA20
#define EQItemList__FreeItemList_x                                 0x58A920

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x51F6B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x63A2B0
#define EQPlayer__dEQPlayer_x                                      0x62D6B0
#define EQPlayer__DoAttack_x                                       0x641E40
#define EQPlayer__EQPlayer_x                                       0x62DD60
#define EQPlayer__SetNameSpriteState_x                             0x632320
#define EQPlayer__SetNameSpriteTint_x                              0x6331B0
#define PlayerBase__HasProperty_j_x                                0x966D80
#define EQPlayer__IsTargetable_x                                   0x967220
#define EQPlayer__CanSee_x                                         0x967080
#define EQPlayer__CanSee1_x                                        0x967150
#define PlayerBase__GetVisibilityLineSegment_x                     0x966E40

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x644C00
#define PlayerZoneClient__GetLevel_x                               0x647150
#define PlayerZoneClient__IsValidTeleport_x                        0x5B6E50
#define PlayerZoneClient__LegalPlayerRace_x                        0x539710

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x63CF80
#define EQPlayerManager__GetSpawnByName_x                          0x63CFA0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x63D030

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6017F0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x601830
#define KeypressHandler__ClearCommandStateArray_x                  0x602C20
#define KeypressHandler__HandleKeyDown_x                           0x602C40
#define KeypressHandler__HandleKeyUp_x                             0x602CE0
#define KeypressHandler__SaveKeymapping_x                          0x6030C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x757E60
#define MapViewMap__SaveEx_x                                       0x75B200
#define MapViewMap__SetZoom_x                                      0x75F8E0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8A38A0

// StringTable 
#define StringTable__getString_x                                   0x89E810

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x627CC0
#define PcZoneClient__RemovePetEffect_x                            0x6282F0
#define PcZoneClient__HasAlternateAbility_x                        0x622490
#define PcZoneClient__GetCurrentMod_x                              0x4DFDD0
#define PcZoneClient__GetModCap_x                                  0x4DFCD0
#define PcZoneClient__CanEquipItem_x                               0x622A60
#define PcZoneClient__GetItemByID_x                                0x625310
#define PcZoneClient__GetItemByItemClass_x                         0x6253A0
#define PcZoneClient__RemoveBuffEffect_x                           0x628310

//Doors
#define EQSwitch__UseSwitch_x                                      0x5BBB00

//IconCache
#define IconCache__GetIcon_x                                       0x6F8E50

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6F0900
#define CContainerMgr__CloseContainer_x                            0x6F0BD0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7B2D00

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5F63F0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x74E2D0
#define CLootWnd__RequestLootSlot_x                                0x74D690

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x558620
#define EQ_Spell__SpellAffects_x                                   0x558AB0
#define EQ_Spell__SpellAffectBase_x                                0x558850
#define EQ_Spell__IsStackable_x                                    0x4C5470
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C5290
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B2890
#define EQ_Spell__IsSPAStacking_x                                  0x559690
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x558E00
#define EQ_Spell__IsNoRemove_x                                     0x4C5450
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5596A0
#define __IsResEffectSpell_x                                       0x4C4720

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4A96A0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8AF7E0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7F8270
#define CTargetWnd__WndNotification_x                              0x7F7B00
#define CTargetWnd__RefreshTargetBuffs_x                           0x7F7DD0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x7F6C60

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7FC940

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x553B80
#define EqSoundManager__PlayScriptMp3_x                            0x553CE0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x511170

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x91EFC0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x547B30
#define CAltAbilityData__GetMercMaxRank_x                          0x547AD0
#define CAltAbilityData__GetMaxRank_x                              0x53D340

//CTargetRing
#define CTargetRing__Cast_x                                        0x5F4500

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C5270
#define CharacterBase__CreateItemGlobalIndex_x                     0x4F7360
#define CharacterBase__CreateItemIndex_x                           0x5FC340
#define CharacterBase__GetItemPossession_x                         0x4B2740
#define CharacterBase__GetItemByGlobalIndex_x                      0x8B7ED0
#define CharacterBase__GetEffectId_x                               0x4C5220

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6D8F30
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6D9750

//messages
#define msg_spell_worn_off_x                                       0x57CC10
#define msg_new_text_x                                             0x571E30
#define __msgTokenTextParam_x                                      0x57F260
#define msgTokenText_x                                             0x57F4B0

//SpellManager
#define SpellManager__vftable_x                                    0xAA17B0
#define SpellManager__SpellManager_x                               0x662710
#define Spellmanager__LoadTextSpells_x                             0x662A90

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x96AD60

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4F7A10
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5829C0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x614F60
#define ItemGlobalIndex__IsValidIndex_x                            0x4F7A70

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8B01C0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8B0440

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x746E80

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6F5060
#define CCursorAttachment__Deactivate_x                            0x6F6040

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x930F40
#define CEQSuiteTextureLoader__GetTexture_x                        0x930C00

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4F49E0

//IString
#define IString__Append_x                                          0x4E9140

//Camera
#define CDisplay__cameraType_x                                     0xDA8BA8
#define EverQuest__Cameras_x                                       0xE6BE8C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x4FD110
#define LootFiltersManager__GetItemFilterData_x                    0x4FCA00
#define LootFiltersManager__RemoveItemLootFilter_x                 0x4FCA30
#define LootFiltersManager__SetItemLootFilter_x                    0x4FCC50

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7A0D80

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x970A80
#define CResolutionHandler__GetWindowedStyle_x                     0x65A470

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
