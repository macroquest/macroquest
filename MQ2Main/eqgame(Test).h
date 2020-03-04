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
#define __ExpectedVersionDate                                     "Mar  2 2020"
#define __ExpectedVersionTime                                     "21:19:58"
#define __ActualVersionDate_x                                      0xB18380
#define __ActualVersionTime_x                                      0xB18374
#define __ActualVersionBuild_x                                     0xB040D4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x63C810
#define __MemChecker1_x                                            0x90FF00
#define __MemChecker2_x                                            0x6CB290
#define __MemChecker3_x                                            0x6CB1E0
#define __MemChecker4_x                                            0x866530
#define __EncryptPad0_x                                            0xC4F4E8
#define __EncryptPad1_x                                            0xCAD650
#define __EncryptPad2_x                                            0xC5FD80
#define __EncryptPad3_x                                            0xC5F980
#define __EncryptPad4_x                                            0xC9DC00
#define __EncryptPad5_x                                            0xF6E7DC
#define __AC1_x                                                    0x823266
#define __AC2_x                                                    0x5F652F
#define __AC3_x                                                    0x5FDC2F
#define __AC4_x                                                    0x601C00
#define __AC5_x                                                    0x607F0F
#define __AC6_x                                                    0x60C406
#define __AC7_x                                                    0x5F5FA0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x6E178

// Direct Input
#define DI8__Main_x                                                0xF6E7FC
#define DI8__Keyboard_x                                            0xF6E800
#define DI8__Mouse_x                                               0xF6E81C
#define DI8__Mouse_Copy_x                                          0xEC9E84
#define DI8__Mouse_Check_x                                         0xF6F2C8
#define __AutoSkillArray_x                                         0xECAD9C
#define __Attack_x                                                 0xF68BC3
#define __Autofire_x                                               0xF68BC4
#define __BindList_x                                               0xC3DF30
#define g_eqCommandStates_x                                        0xC3ECB0
#define __Clicks_x                                                 0xEC9F3C
#define __CommandList_x                                            0xC3F870
#define __CurrentMapLabel_x                                        0xF8168C
#define __CurrentSocial_x                                          0xC277CC
#define __DoAbilityList_x                                          0xF006E4
#define __do_loot_x                                                0x5C2030
#define __DrawHandler_x                                            0x1600A08
#define __GroupCount_x                                             0xEC4A1A
#define __Guilds_x                                                 0xEC8DC8
#define __gWorld_x                                                 0xEC4C10
#define __HWnd_x                                                   0xF6F2A8
#define __heqmain_x                                                0xF7175C
#define __InChatMode_x                                             0xEC9E6C
#define __LastTell_x                                               0xECBDE0
#define __LMouseHeldTime_x                                         0xEC9FA8
#define __Mouse_x                                                  0xF6E7E8
#define __MouseLook_x                                              0xEC9F02
#define __MouseEventTime_x                                         0xF696A4
#define __gpbCommandEvent_x                                        0xEC4C1C
#define __NetStatusToggle_x                                        0xEC9F05
#define __PCNames_x                                                0xECB38C
#define __RangeAttackReady_x                                       0xECB080
#define __RMouseHeldTime_x                                         0xEC9FA4
#define __RunWalkState_x                                           0xEC9E70
#define __ScreenMode_x                                             0xE101A8
#define __ScreenX_x                                                0xEC9E24
#define __ScreenY_x                                                0xEC9E20
#define __ScreenXMax_x                                             0xEC9E28
#define __ScreenYMax_x                                             0xEC9E2C
#define __ServerHost_x                                             0xEC4E4B
#define __ServerName_x                                             0xF006A4
#define __ShiftKeyDown_x                                           0xECA4FC
#define __ShowNames_x                                              0xECB23C
#define EverQuestInfo__bSocialChanged_x                            0xF0072C
#define __Socials_x                                                0xF007A4
#define __SubscriptionType_x                                       0xFC5B98
#define __TargetAggroHolder_x                                      0xF84040
#define __ZoneType_x                                               0xECA300
#define __GroupAggro_x                                             0xF84080
#define __LoginName_x                                              0xF6EF54
#define __Inviter_x                                                0xF68B40
#define __AttackOnAssist_x                                         0xECB1F8
#define __UseTellWindows_x                                         0xECB528
#define __gfMaxZoomCameraDistance_x                                0xB0DCE8
#define __gfMaxCameraDistance_x                                    0xB3A07C
#define __pulAutoRun_x                                             0xEC9F20
#define __pulForward_x                                             0xECB560
#define __pulBackward_x                                            0xECB564
#define __pulTurnRight_x                                           0xECB568
#define __pulTurnLeft_x                                            0xECB56C
#define __pulStrafeLeft_x                                          0xECB570
#define __pulStrafeRight_x                                         0xECB574

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEC5160
#define instEQZoneInfo_x                                           0xECA0F8
#define pinstActiveBanker_x                                        0xEC4CF8
#define pinstActiveCorpse_x                                        0xEC4CF0
#define pinstActiveGMaster_x                                       0xEC4CF4
#define pinstActiveMerchant_x                                      0xEC4CEC
#define pinstAltAdvManager_x                                       0xE11390
#define pinstBandageTarget_x                                       0xEC4D08
#define pinstCamActor_x                                            0xE1019C
#define pinstCDBStr_x                                              0xE100AC
#define pinstCDisplay_x                                            0xEC4868
#define pinstCEverQuest_x                                          0xF6E818
#define pinstEverQuestInfo_x                                       0xEC9E18
#define pinstCharData_x                                            0xEC4A04
#define pinstCharSpawn_x                                           0xEC4D40
#define pinstControlledMissile_x                                   0xEC2854
#define pinstControlledPlayer_x                                    0xEC4D40
#define pinstCResolutionHandler_x                                  0x1600C38
#define pinstCSidlManager_x                                        0x15FFBD0
#define pinstCXWndManager_x                                        0x15FFBCC
#define instDynamicZone_x                                          0xEC8CA0
#define pinstDZMember_x                                            0xEC8DB0
#define pinstDZTimerInfo_x                                         0xEC8DB4
#define pinstEqLogin_x                                             0xF6E8A0
#define instEQMisc_x                                               0xE0FFF0
#define pinstEQSoundManager_x                                      0xE12360
#define pinstEQSpellStrings_x                                      0xCD29F8
#define instExpeditionLeader_x                                     0xEC8CEA
#define instExpeditionName_x                                       0xEC8D2A
#define pinstGroup_x                                               0xEC4A16
#define pinstImeManager_x                                          0x15FFBC8
#define pinstLocalPlayer_x                                         0xEC4CE8
#define pinstMercenaryData_x                                       0xF6B19C
#define pinstMercenaryStats_x                                      0xF8418C
#define pinstModelPlayer_x                                         0xEC4D00
#define pinstPCData_x                                              0xEC4A04
#define pinstSkillMgr_x                                            0xF6D300
#define pinstSpawnManager_x                                        0xF6BDA8
#define pinstSpellManager_x                                        0xF6D540
#define pinstSpellSets_x                                           0xF617EC
#define pinstStringTable_x                                         0xEC4C08
#define pinstSwitchManager_x                                       0xEC2700
#define pinstTarget_x                                              0xEC4D3C
#define pinstTargetObject_x                                        0xEC4F54
#define pinstTargetSwitch_x                                        0xEC285C
#define pinstTaskMember_x                                          0xE0FE80
#define pinstTrackTarget_x                                         0xEC4D44
#define pinstTradeTarget_x                                         0xEC4CFC
#define instTributeActive_x                                        0xE10011
#define pinstViewActor_x                                           0xE10198
#define pinstWorldData_x                                           0xEC4864
#define pinstZoneAddr_x                                            0xECA398
#define pinstPlayerPath_x                                          0xF6BE40
#define pinstTargetIndicator_x                                     0xF6D7A8
#define EQObject_Top_x                                             0xEC4CE4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE1047C
#define pinstCAchievementsWnd_x                                    0xE1098C
#define pinstCActionsWnd_x                                         0xE104D4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE101BC
#define pinstCAdvancedLootWnd_x                                    0xE10154
#define pinstCAdventureLeaderboardWnd_x                            0xF7AE60
#define pinstCAdventureRequestWnd_x                                0xF7AF10
#define pinstCAdventureStatsWnd_x                                  0xF7AFC0
#define pinstCAggroMeterWnd_x                                      0xE101C0
#define pinstCAlarmWnd_x                                           0xE109CC
#define pinstCAlertHistoryWnd_x                                    0xE10210
#define pinstCAlertStackWnd_x                                      0xE10158
#define pinstCAlertWnd_x                                           0xE10178
#define pinstCAltStorageWnd_x                                      0xF7B320
#define pinstCAudioTriggersWindow_x                                0xCC4D28
#define pinstCAuraWnd_x                                            0xE10164
#define pinstCAvaZoneWnd_x                                         0xE10214
#define pinstCBandolierWnd_x                                       0xE101B4
#define pinstCBankWnd_x                                            0xE101FC
#define pinstCBarterMerchantWnd_x                                  0xF7C560
#define pinstCBarterSearchWnd_x                                    0xF7C610
#define pinstCBarterWnd_x                                          0xF7C6C0
#define pinstCBazaarConfirmationWnd_x                              0xE109C8
#define pinstCBazaarSearchWnd_x                                    0xE10480
#define pinstCBazaarWnd_x                                          0xE109AC
#define pinstCBlockedBuffWnd_x                                     0xE10170
#define pinstCBlockedPetBuffWnd_x                                  0xE10190
#define pinstCBodyTintWnd_x                                        0xE10948
#define pinstCBookWnd_x                                            0xE101E8
#define pinstCBreathWnd_x                                          0xE10490
#define pinstCBuffWindowNORMAL_x                                   0xE10148
#define pinstCBuffWindowSHORT_x                                    0xE1014C
#define pinstCBugReportWnd_x                                       0xE101F8
#define pinstCButtonWnd_x                                          0x15FFE38
#define pinstCCastingWnd_x                                         0xE101D4
#define pinstCCastSpellWnd_x                                       0xE10484
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE10960
#define pinstCChatWindowManager_x                                  0xF7D180
#define pinstCClaimWnd_x                                           0xF7D2D8
#define pinstCColorPickerWnd_x                                     0xE10248
#define pinstCCombatAbilityWnd_x                                   0xE109BC
#define pinstCCombatSkillsSelectWnd_x                              0xE10970
#define pinstCCompassWnd_x                                         0xE10940
#define pinstCConfirmationDialog_x                                 0xF821D8
#define pinstCContainerMgr_x                                       0xE1095C
#define pinstCContextMenuManager_x                                 0x15FFB88
#define pinstCCursorAttachment_x                                   0xE101C8
#define pinstCDynamicZoneWnd_x                                     0xF7D8A0
#define pinstCEditLabelWnd_x                                       0xE109E0
#define pinstCEQMainWnd_x                                          0xF7DAE8
#define pinstCEventCalendarWnd_x                                   0xE10474
#define pinstCExtendedTargetWnd_x                                  0xE1018C
#define pinstCFacePick_x                                           0xE10988
#define pinstCFactionWnd_x                                         0xE10998
#define pinstCFellowshipWnd_x                                      0xF7DCE8
#define pinstCFileSelectionWnd_x                                   0xE1023C
#define pinstCFindItemWnd_x                                        0xE10980
#define pinstCFindLocationWnd_x                                    0xF7DE40
#define pinstCFriendsWnd_x                                         0xE1097C
#define pinstCGemsGameWnd_x                                        0xE10994
#define pinstCGiveWnd_x                                            0xE109D4
#define pinstCGroupSearchFiltersWnd_x                              0xE101D8
#define pinstCGroupSearchWnd_x                                     0xF7E238
#define pinstCGroupWnd_x                                           0xF7E2E8
#define pinstCGuildBankWnd_x                                       0xECB1DC
#define pinstCGuildCreationWnd_x                                   0xF7E448
#define pinstCGuildMgmtWnd_x                                       0xF7E4F8
#define pinstCharacterCreation_x                                   0xE10978
#define pinstCHelpWnd_x                                            0xE109C4
#define pinstCHeritageSelectionWnd_x                               0xE1099C
#define pinstCHotButtonWnd_x                                       0xF80650
#define pinstCHotButtonWnd1_x                                      0xF80650
#define pinstCHotButtonWnd2_x                                      0xF80654
#define pinstCHotButtonWnd3_x                                      0xF80658
#define pinstCHotButtonWnd4_x                                      0xF8065C
#define pinstCIconSelectionWnd_x                                   0xE101C4
#define pinstCInspectWnd_x                                         0xE10194
#define pinstCInventoryWnd_x                                       0xE10168
#define pinstCInvSlotMgr_x                                         0xE1048C
#define pinstCItemDisplayManager_x                                 0xF80BE0
#define pinstCItemExpTransferWnd_x                                 0xF80D10
#define pinstCItemOverflowWnd_x                                    0xE10488
#define pinstCJournalCatWnd_x                                      0xE10460
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE10218
#define pinstCKeyRingWnd_x                                         0xE101D0
#define pinstCLargeDialogWnd_x                                     0xF82E58
#define pinstCLayoutCopyWnd_x                                      0xF81060
#define pinstCLFGuildWnd_x                                         0xF81110
#define pinstCLoadskinWnd_x                                        0xE109A8
#define pinstCLootFiltersCopyWnd_x                                 0xCE1388
#define pinstCLootFiltersWnd_x                                     0xE1015C
#define pinstCLootSettingsWnd_x                                    0xE10184
#define pinstCLootWnd_x                                            0xE10464
#define pinstCMailAddressBookWnd_x                                 0xE1049C
#define pinstCMailCompositionWnd_x                                 0xE10478
#define pinstCMailIgnoreListWnd_x                                  0xE104A4
#define pinstCMailWnd_x                                            0xE1024C
#define pinstCManageLootWnd_x                                      0xE11840
#define pinstCMapToolbarWnd_x                                      0xE109D0
#define pinstCMapViewWnd_x                                         0xE109A0
#define pinstCMarketplaceWnd_x                                     0xE10160
#define pinstCMerchantWnd_x                                        0xE10470
#define pinstCMIZoneSelectWnd_x                                    0xF81948
#define pinstCMusicPlayerWnd_x                                     0xE10208
#define pinstCNameChangeMercWnd_x                                  0xE109B0
#define pinstCNameChangePetWnd_x                                   0xE10990
#define pinstCNameChangeWnd_x                                      0xE109D8
#define pinstCNoteWnd_x                                            0xE109B4
#define pinstCObjectPreviewWnd_x                                   0xE1017C
#define pinstCOptionsWnd_x                                         0xE109C0
#define pinstCPetInfoWnd_x                                         0xE10230
#define pinstCPetitionQWnd_x                                       0xE10964
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE10950
#define pinstCPlayerWnd_x                                          0xE10238
#define pinstCPopupWndManager_x                                    0xF821D8
#define pinstCProgressionSelectionWnd_x                            0xF82288
#define pinstCPurchaseGroupWnd_x                                   0xE101EC
#define pinstCPurchaseWnd_x                                        0xE101B8
#define pinstCPvPLeaderboardWnd_x                                  0xF82338
#define pinstCPvPStatsWnd_x                                        0xF823E8
#define pinstCQuantityWnd_x                                        0xE1021C
#define pinstCRaceChangeWnd_x                                      0xE10150
#define pinstCRaidOptionsWnd_x                                     0xE101E4
#define pinstCRaidWnd_x                                            0xE10468
#define pinstCRealEstateItemsWnd_x                                 0xE10984
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE104C0
#define pinstCRealEstateManageWnd_x                                0xE101F4
#define pinstCRealEstateNeighborhoodWnd_x                          0xE1020C
#define pinstCRealEstatePlotSearchWnd_x                            0xE1022C
#define pinstCRealEstatePurchaseWnd_x                              0xE10240
#define pinstCRespawnWnd_x                                         0xE10188
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE1096C
#define pinstCSendMoneyWnd_x                                       0xE109DC
#define pinstCServerListWnd_x                                      0xE10254
#define pinstCSkillsSelectWnd_x                                    0xE10958
#define pinstCSkillsWnd_x                                          0xE10944
#define pinstCSocialEditWnd_x                                      0xE101CC
#define pinstCSocialWnd_x                                          0xE109A4
#define pinstCSpellBookWnd_x                                       0xE109B8
#define pinstCStoryWnd_x                                           0xE104BC
#define pinstCTargetOfTargetWnd_x                                  0xF84210
#define pinstCTargetWnd_x                                          0xE10180
#define pinstCTaskOverlayWnd_x                                     0xE101E0
#define pinstCTaskSelectWnd_x                                      0xF84368
#define pinstCTaskManager_x                                        0xCE1CC8
#define pinstCTaskTemplateSelectWnd_x                              0xF84418
#define pinstCTaskWnd_x                                            0xF844C8
#define pinstCTextEntryWnd_x                                       0xE101DC
#define pinstCTimeLeftWnd_x                                        0xE1094C
#define pinstCTipWndCONTEXT_x                                      0xF846CC
#define pinstCTipWndOFDAY_x                                        0xF846C8
#define pinstCTitleWnd_x                                           0xF84778
#define pinstCTrackingWnd_x                                        0xE10174
#define pinstCTradeskillWnd_x                                      0xF848E0
#define pinstCTradeWnd_x                                           0xE10954
#define pinstCTrainWnd_x                                           0xE1025C
#define pinstCTributeBenefitWnd_x                                  0xF84AE0
#define pinstCTributeMasterWnd_x                                   0xF84B90
#define pinstCTributeTrophyWnd_x                                   0xF84C40
#define pinstCVideoModesWnd_x                                      0xE10244
#define pinstCVoiceMacroWnd_x                                      0xF6DF10
#define pinstCVoteResultsWnd_x                                     0xE10974
#define pinstCVoteWnd_x                                            0xE10968
#define pinstCWebManager_x                                         0xF6E58C
#define pinstCZoneGuideWnd_x                                       0xE101F0
#define pinstCZonePathWnd_x                                        0xE10200

#define pinstEQSuiteTextureLoader_x                                0xCAF128
#define pinstItemIconCache_x                                       0xF7DAA0
#define pinstLootFiltersManager_x                                  0xCE1438
#define pinstRewardSelectionWnd_x                                  0xF82B30

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5BD400
#define __CastRay2_x                                               0x5BD450
#define __ConvertItemTags_x                                        0x5D9020
#define __CleanItemTags_x                                          0x47D240
#define __DoesFileExist_x                                          0x912FE0
#define __EQGetTime_x                                              0x90F9D0
#define __ExecuteCmd_x                                             0x5B5C90
#define __FixHeading_x                                             0x9AA660
#define __GameLoop_x                                               0x6CA460
#define __get_bearing_x                                            0x5BCF70
#define __get_melee_range_x                                        0x5BD640
#define __GetAnimationCache_x                                      0x72F9A0
#define __GetGaugeValueFromEQ_x                                    0x821710
#define __GetLabelFromEQ_x                                         0x8231F0
#define __GetXTargetType_x                                         0x9AC0B0
#define __HandleMouseWheel_x                                       0x6CB340
#define __HeadingDiff_x                                            0x9AA6D0
#define __HelpPath_x                                               0xF69294
#define __LoadFrontEnd_x                                           0x6C7780
#define __NewUIINI_x                                               0x8213E0
#define __ProcessGameEvents_x                                      0x61DD10
#define __ProcessMouseEvent_x                                      0x61D4D0
#define __SaveColors_x                                             0x5588E0
#define __STMLToText_x                                             0x94DCE0
#define __ToggleKeyRingItem_x                                      0x519360
#define CMemoryMappedFile__SetFile_x                               0xA999C0
#define CrashDetected_x                                            0x6C9220
#define DrawNetStatus_x                                            0x649B30
#define Expansion_HoT_x                                            0xECB1E4
#define Teleport_Table_Size_x                                      0xEC4CA4
#define Teleport_Table_x                                           0xEC2860
#define Util__FastTime_x                                           0x90F5A0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490520
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499440
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499210
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493AC0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492F10

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x560A60
#define AltAdvManager__IsAbilityReady_x                            0x55F800
#define AltAdvManager__GetAAById_x                                 0x55FB90
#define AltAdvManager__CanTrainAbility_x                           0x55FC00
#define AltAdvManager__CanSeeAbility_x                             0x55FF60

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9F40
#define CharacterZoneClient__HasSkill_x                            0x4D4DC0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D64E0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE5E0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAC10
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8E70
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8F50
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9030
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2CE0
#define CharacterZoneClient__BardCastBard_x                        0x4C5860
#define CharacterZoneClient__GetMaxEffects_x                       0x4BACE0
#define CharacterZoneClient__GetEffect_x                           0x4BAB50
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3D30
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3E00
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3E50
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3FA0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4170
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2AB0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7440
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6EC0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6F1000
#define CBankWnd__WndNotification_x                                0x6F0DE0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6FE640

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x62C490
#define CButtonWnd__CButtonWnd_x                                   0x94A0D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x71EA00
#define CChatManager__InitContextMenu_x                            0x717B30
#define CChatManager__FreeChatWindow_x                             0x71D540
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8530
#define CChatManager__SetLockedActiveChatWindow_x                  0x71E680
#define CChatManager__CreateChatWindow_x                           0x71DB80

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8640

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x95E670
#define CContextMenu__dCContextMenu_x                              0x95E8A0
#define CContextMenu__AddMenuItem_x                                0x95E8B0
#define CContextMenu__RemoveMenuItem_x                             0x95EBB0
#define CContextMenu__RemoveAllMenuItems_x                         0x95EBD0
#define CContextMenu__CheckMenuItem_x                              0x95EC50
#define CContextMenu__SetMenuItem_x                                0x95EAE0
#define CContextMenu__AddSeparator_x                               0x95EA40

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x95F1E0
#define CContextMenuManager__RemoveMenu_x                          0x95F250
#define CContextMenuManager__PopupMenu_x                           0x95F310
#define CContextMenuManager__Flush_x                               0x95F180
#define CContextMenuManager__GetMenu_x                             0x49B630
#define CContextMenuManager__CreateDefaultMenu_x                   0x72A1B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8EADA0
#define CChatService__GetFriendName_x                              0x8EADB0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x71F270
#define CChatWindow__Clear_x                                       0x720540
#define CChatWindow__WndNotification_x                             0x720CD0
#define CChatWindow__AddHistory_x                                  0x71FE00

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x95BAD0
#define CComboWnd__Draw_x                                          0x95AFE0
#define CComboWnd__GetCurChoice_x                                  0x95B910
#define CComboWnd__GetListRect_x                                   0x95B480
#define CComboWnd__GetTextRect_x                                   0x95BB30
#define CComboWnd__InsertChoice_x                                  0x95B610
#define CComboWnd__SetColors_x                                     0x95B5E0
#define CComboWnd__SetChoice_x                                     0x95B8E0
#define CComboWnd__GetItemCount_x                                  0x95B920
#define CComboWnd__GetCurChoiceText_x                              0x95B960
#define CComboWnd__GetChoiceText_x                                 0x95B930
#define CComboWnd__InsertChoiceAtIndex_x                           0x95B6A0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x727B90
#define CContainerWnd__vftable_x                                   0xB21564
#define CContainerWnd__SetContainer_x                              0x7290F0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x553290
#define CDisplay__PreZoneMainUI_x                                  0x5532A0
#define CDisplay__CleanGameUI_x                                    0x5586A0
#define CDisplay__GetClickedActor_x                                0x54B590
#define CDisplay__GetUserDefinedColor_x                            0x543BF0
#define CDisplay__GetWorldFilePath_x                               0x54D000
#define CDisplay__is3dON_x                                         0x5481F0
#define CDisplay__ReloadUI_x                                       0x552710
#define CDisplay__WriteTextHD2_x                                   0x547FE0
#define CDisplay__TrueDistance_x                                   0x54ECC0
#define CDisplay__SetViewActor_x                                   0x54AEB0
#define CDisplay__GetFloorHeight_x                                 0x5482B0
#define CDisplay__SetRenderWindow_x                                0x546C10
#define CDisplay__ToggleScreenshotMode_x                           0x54A980

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x97E2D0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x961B90
#define CEditWnd__EnsureCaretVisible_x                             0x963CF0
#define CEditWnd__GetCaretPt_x                                     0x962CE0
#define CEditWnd__GetCharIndexPt_x                                 0x962AA0
#define CEditWnd__GetDisplayString_x                               0x962950
#define CEditWnd__GetHorzOffset_x                                  0x9611E0
#define CEditWnd__GetLineForPrintableChar_x                        0x963BF0
#define CEditWnd__GetSelStartPt_x                                  0x962D40
#define CEditWnd__GetSTMLSafeText_x                                0x962770
#define CEditWnd__PointFromPrintableChar_x                         0x963840
#define CEditWnd__SelectableCharFromPoint_x                        0x9639A0
#define CEditWnd__SetEditable_x                                    0x962E00
#define CEditWnd__SetWindowTextA_x                                 0x9624F0
#define CEditWnd__ReplaceSelection_x                               0x9634C0
#define CEditWnd__ReplaceSelection1_x                              0x963440

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60B8E0
#define CEverQuest__ClickedPlayer_x                                0x5FDA10
#define CEverQuest__CreateTargetIndicator_x                        0x61AFA0
#define CEverQuest__DeleteTargetIndicator_x                        0x61B030
#define CEverQuest__DoTellWindow_x                                 0x4E8720
#define CEverQuest__OutputTextToLog_x                              0x4E89F0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F2A50
#define CEverQuest__dsp_chat_x                                     0x4E8D80
#define CEverQuest__trimName_x                                     0x617110
#define CEverQuest__Emote_x                                        0x60C140
#define CEverQuest__EnterZone_x                                    0x6061E0
#define CEverQuest__GetBodyTypeDesc_x                              0x610A00
#define CEverQuest__GetClassDesc_x                                 0x611040
#define CEverQuest__GetClassThreeLetterCode_x                      0x611640
#define CEverQuest__GetDeityDesc_x                                 0x6197F0
#define CEverQuest__GetLangDesc_x                                  0x611800
#define CEverQuest__GetRaceDesc_x                                  0x611020
#define CEverQuest__InterpretCmd_x                                 0x619DC0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F6C50
#define CEverQuest__LMouseUp_x                                     0x5F4FE0
#define CEverQuest__RightClickedOnPlayer_x                         0x5F7530
#define CEverQuest__RMouseUp_x                                     0x5F5F60
#define CEverQuest__SetGameState_x                                 0x5F27E0
#define CEverQuest__UPCNotificationFlush_x                         0x617010
#define CEverQuest__IssuePetCommand_x                              0x612C00
#define CEverQuest__ReportSuccessfulHit_x                          0x60D490

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x739C00
#define CGaugeWnd__CalcLinesFillRect_x                             0x739C60
#define CGaugeWnd__Draw_x                                          0x739290

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF570
#define CGuild__GetGuildName_x                                     0x4AE5B0
#define CGuild__GetGuildIndex_x                                    0x4AE9F0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x753E20

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62C850

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x760E90
#define CInvSlotMgr__MoveItem_x                                    0x75FBA0
#define CInvSlotMgr__SelectSlot_x                                  0x760F60

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x75E3E0
#define CInvSlot__SliderComplete_x                                 0x75C140
#define CInvSlot__GetItemBase_x                                    0x75BAB0
#define CInvSlot__UpdateItem_x                                     0x75BC20

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7629F0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x761B80
#define CInvSlotWnd__HandleLButtonUp_x                             0x762570

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x81CAB0
#define CItemDisplayWnd__UpdateStrings_x                           0x771250
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76AEC0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76B3F0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x771850
#define CItemDisplayWnd__AboutToShow_x                             0x770EB0
#define CItemDisplayWnd__WndNotification_x                         0x772990
#define CItemDisplayWnd__RequestConvertItem_x                      0x772400
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x76FF10
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x770CD0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8554F0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x776E90

// CLabel 
#define CLabel__Draw_x                                             0x77C870

// CListWnd
#define CListWnd__CListWnd_x                                       0x934310
#define CListWnd__dCListWnd_x                                      0x934630
#define CListWnd__AddColumn_x                                      0x938A90
#define CListWnd__AddColumn1_x                                     0x938AE0
#define CListWnd__AddLine_x                                        0x938E70
#define CListWnd__AddString_x                                      0x938C70
#define CListWnd__CalculateFirstVisibleLine_x                      0x938860
#define CListWnd__CalculateVSBRange_x                              0x938640
#define CListWnd__ClearSel_x                                       0x939650
#define CListWnd__ClearAllSel_x                                    0x9396B0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x93A0A0
#define CListWnd__Compare_x                                        0x937F70
#define CListWnd__Draw_x                                           0x934760
#define CListWnd__DrawColumnSeparators_x                           0x936F40
#define CListWnd__DrawHeader_x                                     0x9373B0
#define CListWnd__DrawItem_x                                       0x9378B0
#define CListWnd__DrawLine_x                                       0x9370B0
#define CListWnd__DrawSeparator_x                                  0x936FE0
#define CListWnd__EnableLine_x                                     0x936820
#define CListWnd__EnsureVisible_x                                  0x939FE0
#define CListWnd__ExtendSel_x                                      0x939580
#define CListWnd__GetColumnTooltip_x                               0x936360
#define CListWnd__GetColumnMinWidth_x                              0x9363D0
#define CListWnd__GetColumnWidth_x                                 0x9362D0
#define CListWnd__GetCurSel_x                                      0x935C60
#define CListWnd__GetItemAtPoint_x                                 0x936A90
#define CListWnd__GetItemAtPoint1_x                                0x936B00
#define CListWnd__GetItemData_x                                    0x935CE0
#define CListWnd__GetItemHeight_x                                  0x9360A0
#define CListWnd__GetItemIcon_x                                    0x935E70
#define CListWnd__GetItemRect_x                                    0x936910
#define CListWnd__GetItemText_x                                    0x935D20
#define CListWnd__GetSelList_x                                     0x939700
#define CListWnd__GetSeparatorRect_x                               0x936D40
#define CListWnd__InsertLine_x                                     0x939260
#define CListWnd__RemoveLine_x                                     0x9393B0
#define CListWnd__SetColors_x                                      0x938610
#define CListWnd__SetColumnJustification_x                         0x938340
#define CListWnd__SetColumnLabel_x                                 0x938C10
#define CListWnd__SetColumnWidth_x                                 0x938260
#define CListWnd__SetCurSel_x                                      0x9394C0
#define CListWnd__SetItemColor_x                                   0x939CA0
#define CListWnd__SetItemData_x                                    0x939C60
#define CListWnd__SetItemText_x                                    0x939870
#define CListWnd__ShiftColumnSeparator_x                           0x938400
#define CListWnd__Sort_x                                           0x9380F0
#define CListWnd__ToggleSel_x                                      0x9394F0
#define CListWnd__SetColumnsSizable_x                              0x9384B0
#define CListWnd__SetItemWnd_x                                     0x939B20
#define CListWnd__GetItemWnd_x                                     0x935EC0
#define CListWnd__SetItemIcon_x                                    0x9398F0
#define CListWnd__CalculateCustomWindowPositions_x                 0x938950
#define CListWnd__SetVScrollPos_x                                  0x938240

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x791FE0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7906F0
#define CMapViewWnd__HandleLButtonDown_x                           0x78D730

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B22B0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B2B90
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B30C0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B6050
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B0E10
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BBC10
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B1EC0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8B89C0
#define CPacketScrambler__hton_x                                   0x8B89B0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9532F0
#define CSidlManager__FindScreenPieceTemplate_x                    0x953700
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9534F0
#define CSidlManager__CreateLabel_x                                0x813D90
#define CSidlManager__CreateXWndFromTemplate_x                     0x956660
#define CSidlManager__CreateXWndFromTemplate1_x                    0x956840
#define CSidlManager__CreateXWnd_x                                 0x813CC0
#define CSidlManager__CreateHotButtonWnd_x                         0x814290

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x94FE20
#define CSidlScreenWnd__CalculateVSBRange_x                        0x94FD20
#define CSidlScreenWnd__ConvertToRes_x                             0x978DC0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x94F7B0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x94F4A0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x94F570
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x94F640
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9502C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x950790
#define CSidlScreenWnd__GetSidlPiece_x                             0x9504B0
#define CSidlScreenWnd__Init1_x                                    0x94F0A0
#define CSidlScreenWnd__LoadIniInfo_x                              0x9507E0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9512D0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x94E4A0
#define CSidlScreenWnd__StoreIniInfo_x                             0x950E60
#define CSidlScreenWnd__StoreIniVis_x                              0x9511B0
#define CSidlScreenWnd__WndNotification_x                          0x9501D0
#define CSidlScreenWnd__GetChildItem_x                             0x950710
#define CSidlScreenWnd__HandleLButtonUp_x                          0x93FF70
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FFA58

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6912B0
#define CSkillMgr__GetSkillCap_x                                   0x691490
#define CSkillMgr__GetNameToken_x                                  0x690A30
#define CSkillMgr__IsActivatedSkill_x                              0x690B70
#define CSkillMgr__IsCombatSkill_x                                 0x690AB0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x95FFC0
#define CSliderWnd__SetValue_x                                     0x95FE30
#define CSliderWnd__SetNumTicks_x                                  0x95FE90

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x819E80

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x968730
#define CStmlWnd__ParseSTML_x                                      0x969A70
#define CStmlWnd__CalculateHSBRange_x                              0x969840
#define CStmlWnd__CalculateVSBRange_x                              0x9697C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x96DB80
#define CStmlWnd__FastForwardToEndOfTag_x                          0x96E810
#define CStmlWnd__ForceParseNow_x                                  0x968D20
#define CStmlWnd__GetNextTagPiece_x                                0x96DAE0
#define CStmlWnd__GetSTMLText_x                                    0x508E40
#define CStmlWnd__GetVisibleText_x                                 0x968D40
#define CStmlWnd__InitializeWindowVariables_x                      0x96E660
#define CStmlWnd__MakeStmlColorTag_x                               0x967DA0
#define CStmlWnd__MakeWndNotificationTag_x                         0x967E10
#define CStmlWnd__SetSTMLText_x                                    0x966E50
#define CStmlWnd__StripFirstSTMLLines_x                            0x96F900
#define CStmlWnd__UpdateHistoryString_x                            0x96EA20

// CTabWnd 
#define CTabWnd__Draw_x                                            0x965FA0
#define CTabWnd__DrawCurrentPage_x                                 0x9666D0
#define CTabWnd__DrawTab_x                                         0x9663F0
#define CTabWnd__GetCurrentPage_x                                  0x9657A0
#define CTabWnd__GetPageInnerRect_x                                0x9659E0
#define CTabWnd__GetTabInnerRect_x                                 0x965920
#define CTabWnd__GetTabRect_x                                      0x9657D0
#define CTabWnd__InsertPage_x                                      0x965BF0
#define CTabWnd__SetPage_x                                         0x965A60
#define CTabWnd__SetPageRect_x                                     0x965EE0
#define CTabWnd__UpdatePage_x                                      0x9662B0
#define CTabWnd__GetPageFromTabIndex_x                             0x966330
#define CTabWnd__GetCurrentTabIndex_x                              0x965790

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x777260
#define CPageWnd__SetTabText_x                                     0x9652F0
#define CPageWnd__FlashTab_x                                       0x965350

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9020

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93CE60
#define CTextureFont__GetTextExtent_x                              0x93D020

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C4340
#define CHtmlComponentWnd__ValidateUri_x                           0x755810
#define CHtmlWnd__SetClientCallbacks_x                             0x6318E0
#define CHtmlWnd__AddObserver_x                                    0x631900
#define CHtmlWnd__RemoveObserver_x                                 0x631960
#define Window__getProgress_x                                      0x86DB20
#define Window__getStatus_x                                        0x86DB40
#define Window__getURI_x                                           0x86DB50

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x975BD0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x929EA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8370
#define CXStr__CXStr1_x                                            0x504000
#define CXStr__CXStr3_x                                            0x90BB70
#define CXStr__dCXStr_x                                            0x478770
#define CXStr__operator_equal_x                                    0x90BDA0
#define CXStr__operator_equal1_x                                   0x90BDE0
#define CXStr__operator_plus_equal1_x                              0x90C870
#define CXStr__SetString_x                                         0x90E760
#define CXStr__operator_char_p_x                                   0x90C2B0
#define CXStr__GetChar_x                                           0x90E0B0
#define CXStr__Delete_x                                            0x90D960
#define CXStr__GetUnicode_x                                        0x90E120
#define CXStr__GetLength_x                                         0x4A8DD0
#define CXStr__Mid_x                                               0x47D5F0
#define CXStr__Insert_x                                            0x90E180
#define CXStr__FindNext_x                                          0x90DDD0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x95E280
#define CXWnd__BringToTop_x                                        0x9436A0
#define CXWnd__Center_x                                            0x943220
#define CXWnd__ClrFocus_x                                          0x943040
#define CXWnd__Destroy_x                                           0x9430E0
#define CXWnd__DoAllDrawing_x                                      0x93F700
#define CXWnd__DrawChildren_x                                      0x93F6D0
#define CXWnd__DrawColoredRect_x                                   0x93FB60
#define CXWnd__DrawTooltip_x                                       0x93E240
#define CXWnd__DrawTooltipAtPoint_x                                0x93E300
#define CXWnd__GetBorderFrame_x                                    0x93F9C0
#define CXWnd__GetChildWndAt_x                                     0x943740
#define CXWnd__GetClientClipRect_x                                 0x941990
#define CXWnd__GetScreenClipRect_x                                 0x941A60
#define CXWnd__GetScreenRect_x                                     0x941C20
#define CXWnd__GetRelativeRect_x                                   0x941CD0
#define CXWnd__GetTooltipRect_x                                    0x93FBB0
#define CXWnd__GetWindowTextA_x                                    0x49CD30
#define CXWnd__IsActive_x                                          0x9402F0
#define CXWnd__IsDescendantOf_x                                    0x9425E0
#define CXWnd__IsReallyVisible_x                                   0x942610
#define CXWnd__IsType_x                                            0x943DA0
#define CXWnd__Move_x                                              0x942680
#define CXWnd__Move1_x                                             0x942730
#define CXWnd__ProcessTransition_x                                 0x9431D0
#define CXWnd__Refade_x                                            0x9429E0
#define CXWnd__Resize_x                                            0x942C80
#define CXWnd__Right_x                                             0x943460
#define CXWnd__SetFocus_x                                          0x943000
#define CXWnd__SetFont_x                                           0x943070
#define CXWnd__SetKeyTooltip_x                                     0x943BB0
#define CXWnd__SetMouseOver_x                                      0x940B20
#define CXWnd__StartFade_x                                         0x9424D0
#define CXWnd__GetChildItem_x                                      0x9438B0
#define CXWnd__SetParent_x                                         0x942380
#define CXWnd__Minimize_x                                          0x942CF0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x979E40

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x946560
#define CXWndManager__DrawWindows_x                                0x946580
#define CXWndManager__GetKeyboardFlags_x                           0x948D80
#define CXWndManager__HandleKeyboardMsg_x                          0x948930
#define CXWndManager__RemoveWnd_x                                  0x948FA0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9494F0

// CDBStr
#define CDBStr__GetString_x                                        0x542BB0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBBF0
#define EQ_Character__Cur_HP_x                                     0x4D1E00
#define EQ_Character__Cur_Mana_x                                   0x4D9530
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEC30
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B26F0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2840
#define EQ_Character__GetHPRegen_x                                 0x4DF2D0
#define EQ_Character__GetEnduranceRegen_x                          0x4DF8D0
#define EQ_Character__GetManaRegen_x                               0x4DFD10
#define EQ_Character__Max_Endurance_x                              0x657D00
#define EQ_Character__Max_HP_x                                     0x4D1C30
#define EQ_Character__Max_Mana_x                                   0x657B00
#define EQ_Character__doCombatAbility_x                            0x65A140
#define EQ_Character__UseSkill_x                                   0x4E1B00
#define EQ_Character__GetConLevel_x                                0x650B30
#define EQ_Character__IsExpansionFlag_x                            0x5B44B0
#define EQ_Character__TotalEffect_x                                0x4C4FA0
#define EQ_Character__GetPCSpellAffect_x                           0x4BF980
#define EQ_Character__SpellDuration_x                              0x4BF4B0
#define EQ_Character__GetAdjustedSkill_x                           0x4D4B80
#define EQ_Character__GetBaseSkill_x                               0x4D5B20
#define EQ_Character__CanUseItem_x                                 0x4D9840

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8D7CA0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x66E280

//PcClient
#define PcClient__PcClient_x                                       0x64E270

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9860
#define CCharacterListWnd__EnterWorld_x                            0x4B92A0
#define CCharacterListWnd__Quit_x                                  0x4B8FF0
#define CCharacterListWnd__UpdateList_x                            0x4B9430

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x632AB0
#define EQ_Item__CreateItemTagString_x                             0x8B2010
#define EQ_Item__IsStackable_x                                     0x8B6C10
#define EQ_Item__GetImageNum_x                                     0x8B3A70
#define EQ_Item__CreateItemClient_x                                0x631CE0
#define EQ_Item__GetItemValue_x                                    0x8B4E60
#define EQ_Item__ValueSellMerchant_x                               0x8B85A0
#define EQ_Item__IsKeyRingItem_x                                   0x8B6530
#define EQ_Item__CanGoInBag_x                                      0x632BD0
#define EQ_Item__IsEmpty_x                                         0x8B6080
#define EQ_Item__GetMaxItemCount_x                                 0x8B5270
#define EQ_Item__GetHeldItem_x                                     0x8B3940
#define EQ_Item__GetAugmentFitBySlot_x                             0x8B1880

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x561780
#define EQ_LoadingS__Array_x                                       0xC36C60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x658640
#define EQ_PC__GetAlternateAbilityId_x                             0x8C1A10
#define EQ_PC__GetCombatAbility_x                                  0x8C2080
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C20F0
#define EQ_PC__GetItemRecastTimer_x                                0x65A6C0
#define EQ_PC__HasLoreItem_x                                       0x651340
#define EQ_PC__AlertInventoryChanged_x                             0x650460
#define EQ_PC__GetPcZoneClient_x                                   0x67CCA0
#define EQ_PC__RemoveMyAffect_x                                    0x65D8F0
#define EQ_PC__GetKeyRingItems_x                                   0x8C2980
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C2710
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C2C80

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BA990
#define EQItemList__add_object_x                                   0x5E8240
#define EQItemList__add_item_x                                     0x5BAEF0
#define EQItemList__delete_item_x                                  0x5BAF40
#define EQItemList__FreeItemList_x                                 0x5BAE40

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53F6E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x66FB00
#define EQPlayer__dEQPlayer_x                                      0x662E60
#define EQPlayer__DoAttack_x                                       0x677930
#define EQPlayer__EQPlayer_x                                       0x663520
#define EQPlayer__SetNameSpriteState_x                             0x6677E0
#define EQPlayer__SetNameSpriteTint_x                              0x6686B0
#define PlayerBase__HasProperty_j_x                                0x9A8A60
#define EQPlayer__IsTargetable_x                                   0x9A8F00
#define EQPlayer__CanSee_x                                         0x9A8D60
#define EQPlayer__CanSee1_x                                        0x9A8E30
#define PlayerBase__GetVisibilityLineSegment_x                     0x9A8B20

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67A730
#define PlayerZoneClient__GetLevel_x                               0x67CCE0
#define PlayerZoneClient__IsValidTeleport_x                        0x5E93B0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55A500

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x672850
#define EQPlayerManager__GetSpawnByName_x                          0x672900
#define EQPlayerManager__GetPlayerFromPartialName_x                0x672990

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6361C0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x636240
#define KeypressHandler__AttachKeyToEqCommand_x                    0x636280
#define KeypressHandler__ClearCommandStateArray_x                  0x637690
#define KeypressHandler__HandleKeyDown_x                           0x6376B0
#define KeypressHandler__HandleKeyUp_x                             0x637750
#define KeypressHandler__SaveKeymapping_x                          0x637BA0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x78DE50
#define MapViewMap__SaveEx_x                                       0x791210
#define MapViewMap__SetZoom_x                                      0x7958D0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D5D00

// StringTable 
#define StringTable__getString_x                                   0x8D0B10

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x65D560
#define PcZoneClient__RemovePetEffect_x                            0x65DB90
#define PcZoneClient__HasAlternateAbility_x                        0x657930
#define PcZoneClient__GetCurrentMod_x                              0x4E4BC0
#define PcZoneClient__GetModCap_x                                  0x4E4AC0
#define PcZoneClient__CanEquipItem_x                               0x657FE0
#define PcZoneClient__GetItemByID_x                                0x65AB30
#define PcZoneClient__GetItemByItemClass_x                         0x65AC80
#define PcZoneClient__RemoveBuffEffect_x                           0x65DBB0
#define PcZoneClient__BandolierSwap_x                              0x658C00
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65A660

//Doors
#define EQSwitch__UseSwitch_x                                      0x5EDF20

//IconCache
#define IconCache__GetIcon_x                                       0x72F240

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x726D30
#define CContainerMgr__CloseContainer_x                            0x727000
#define CContainerMgr__OpenExperimentContainer_x                   0x727A80

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E62D0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62AC70

//CLootWnd
#define CLootWnd__LootAll_x                                        0x784340
#define CLootWnd__RequestLootSlot_x                                0x783570

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x588040
#define EQ_Spell__SpellAffects_x                                   0x5884B0
#define EQ_Spell__SpellAffectBase_x                                0x588270
#define EQ_Spell__IsStackable_x                                    0x4C9810
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9600
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6BC0
#define EQ_Spell__IsSPAStacking_x                                  0x589300
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x588810
#define EQ_Spell__IsNoRemove_x                                     0x4C97F0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x589310
#define __IsResEffectSpell_x                                       0x4C8A20

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD110

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8E02F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82D1D0
#define CTargetWnd__WndNotification_x                              0x82CA10
#define CTargetWnd__RefreshTargetBuffs_x                           0x82CCE0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82BB70

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x831810

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53D120
#define CTaskManager__HandleMessage_x                              0x53B5A0
#define CTaskManager__GetTaskStatus_x                              0x53D1D0
#define CTaskManager__GetElementDescription_x                      0x53D250

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x583250
#define EqSoundManager__PlayScriptMp3_x                            0x583510
#define EqSoundManager__SoundAssistPlay_x                          0x695240
#define EqSoundManager__WaveInstancePlay_x                         0x6947B0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52E7E0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9647F0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5692F0
#define CAltAbilityData__GetMercMaxRank_x                          0x569280
#define CAltAbilityData__GetMaxRank_x                              0x55E680

//CTargetRing
#define CTargetRing__Cast_x                                        0x628D90

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C95E0
#define CharacterBase__CreateItemGlobalIndex_x                     0x5159C0
#define CharacterBase__CreateItemIndex_x                           0x630E90
#define CharacterBase__GetItemPossession_x                         0x501810
#define CharacterBase__GetItemByGlobalIndex_x                      0x8E8950
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8E89B0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x70DD60
#define CCastSpellWnd__IsBardSongPlaying_x                         0x70E590
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x70E640

//messages
#define msg_spell_worn_off_x                                       0x5ACA70
#define msg_new_text_x                                             0x5A1410
#define __msgTokenTextParam_x                                      0x5AED10
#define msgTokenText_x                                             0x5AEF60

//SpellManager
#define SpellManager__vftable_x                                    0xAFB158
#define SpellManager__SpellManager_x                               0x698560
#define Spellmanager__LoadTextSpells_x                             0x698E50
#define SpellManager__GetSpellByGroupAndRank_x                     0x698730

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9AC9A0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x516040
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B29D0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x649990
#define ItemGlobalIndex__IsValidIndex_x                            0x5160A0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8E0C90
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8E0F10

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77CBB0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72B450
#define CCursorAttachment__AttachToCursor1_x                       0x72B490
#define CCursorAttachment__Deactivate_x                            0x72C470

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9576A0
#define CSidlManagerBase__CreatePageWnd_x                          0x956E90
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x953110
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9530A0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9745D0
#define CEQSuiteTextureLoader__GetTexture_x                        0x974290

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x513030
#define CFindItemWnd__WndNotification_x                            0x513B10
#define CFindItemWnd__Update_x                                     0x514680
#define CFindItemWnd__PickupSelectedItem_x                         0x512870

//IString
#define IString__Append_x                                          0x503110

//Camera
#define CDisplay__cameraType_x                                     0xE10258
#define EverQuest__Cameras_x                                       0xECB534

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51B700
#define LootFiltersManager__GetItemFilterData_x                    0x51B000
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51B030
#define LootFiltersManager__SetItemLootFilter_x                    0x51B250

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D40C0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B25B0
#define CResolutionHandler__GetWindowedStyle_x                     0x68FC60

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7239E0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F6000
#define CDistillerInfo__Instance_x                                 0x8F5FA0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x742BE0
#define CGroupWnd__UpdateDisplay_x                                 0x741F30

//ItemBase
#define ItemBase__IsLore_x                                         0x8B65E0
#define ItemBase__IsLoreEquipped_x                                 0x8B6650

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5E81A0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5E82E0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5E8340

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6853D0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x688D40

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x509440

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F5BD0
#define FactionManagerClient__HandleFactionMessage_x               0x4F6240
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F6800
#define FactionManagerClient__GetMaxFaction_x                      0x4F681F
#define FactionManagerClient__GetMinFaction_x                      0x4F67D0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5017E0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x93BD40

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C010

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x501B20

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x568790

//CTargetManager
#define CTargetManager__Get_x                                      0x69BE30

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6853D0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8DE0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BADE0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF68BC8

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6D7670

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";

//__eqgraphics_fopen
//Jan 09 2020 EQGraphicsDX9.dll
//IDA Style Sig: E8 ? ? ? ? 83 C4 08 89 45 A0
//#define __eqgraphics_fopen_x                                       0x101473C8
static PBYTE efPattern = (PBYTE)"\xE8\x00\x00\x00\x00\x83\xC4\x08\x89\x45\xA0";
static char efMask[] = "x????xxxxxx";
