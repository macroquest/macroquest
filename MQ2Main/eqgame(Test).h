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
#define __ExpectedVersionDate                                     "May 12 2020"
#define __ExpectedVersionTime                                     "10:53:14"
#define __ActualVersionDate_x                                      0xB1B45C
#define __ActualVersionTime_x                                      0xB1B450
#define __ActualVersionBuild_x                                     0xB07104

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x63E1E0
#define __MemChecker1_x                                            0x912790
#define __MemChecker2_x                                            0x6CD0E0
#define __MemChecker3_x                                            0x6CD030
#define __MemChecker4_x                                            0x868C90
#define __EncryptPad0_x                                            0xC53500
#define __EncryptPad1_x                                            0xCB1668
#define __EncryptPad2_x                                            0xC63D98
#define __EncryptPad3_x                                            0xC63998
#define __EncryptPad4_x                                            0xCA1C18
#define __EncryptPad5_x                                            0xF7286C
#define __AC1_x                                                    0x825836
#define __AC2_x                                                    0x5F7DFF
#define __AC3_x                                                    0x5FF44F
#define __AC4_x                                                    0x603410
#define __AC5_x                                                    0x6096BF
#define __AC6_x                                                    0x60DBC6
#define __AC7_x                                                    0x5F7870
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x76F58

// Direct Input
#define DI8__Main_x                                                0xF7288C
#define DI8__Keyboard_x                                            0xF72890
#define DI8__Mouse_x                                               0xF728AC
#define DI8__Mouse_Copy_x                                          0xECDF14
#define DI8__Mouse_Check_x                                         0xF73358
#define __AutoSkillArray_x                                         0xECEE2C
#define __Attack_x                                                 0xF6CC53
#define __Autofire_x                                               0xF6CC54
#define __BindList_x                                               0xC41F30
#define g_eqCommandStates_x                                        0xC42CB0
#define __Clicks_x                                                 0xECDFCC
#define __CommandList_x                                            0xC43870
#define __CurrentMapLabel_x                                        0xF8571C
#define __CurrentSocial_x                                          0xC2B7CC
#define __DoAbilityList_x                                          0xF04774
#define __do_loot_x                                                0x5C35D0
#define __DrawHandler_x                                            0x1604A98
#define __GroupCount_x                                             0xEC8F1A
#define __Guilds_x                                                 0xECCE50
#define __gWorld_x                                                 0xEC8F04
#define __HWnd_x                                                   0xF72930
#define __heqmain_x                                                0xF757EC
#define __InChatMode_x                                             0xECDEFC
#define __LastTell_x                                               0xECFE70
#define __LMouseHeldTime_x                                         0xECE038
#define __Mouse_x                                                  0xF72878
#define __MouseLook_x                                              0xECDF92
#define __MouseEventTime_x                                         0xF6D734
#define __gpbCommandEvent_x                                        0xEC9118
#define __NetStatusToggle_x                                        0xECDF95
#define __PCNames_x                                                0xECF41C
#define __RangeAttackReady_x                                       0xECF110
#define __RMouseHeldTime_x                                         0xECE034
#define __RunWalkState_x                                           0xECDF00
#define __ScreenMode_x                                             0xE14254
#define __ScreenX_x                                                0xECDEB4
#define __ScreenY_x                                                0xECDEB0
#define __ScreenXMax_x                                             0xECDEB8
#define __ScreenYMax_x                                             0xECDEBC
#define __ServerHost_x                                             0xEC69FB
#define __ServerName_x                                             0xF04734
#define __ShiftKeyDown_x                                           0xECE58C
#define __ShowNames_x                                              0xECF2CC
#define EverQuestInfo__bSocialChanged_x                            0xF047BC
#define __Socials_x                                                0xF04834
#define __SubscriptionType_x                                       0xFC9C28
#define __TargetAggroHolder_x                                      0xF880D0
#define __ZoneType_x                                               0xECE390
#define __GroupAggro_x                                             0xF88110
#define __LoginName_x                                              0xF72FEC
#define __Inviter_x                                                0xF6CBD0
#define __AttackOnAssist_x                                         0xECF288
#define __UseTellWindows_x                                         0xECF5B8
#define __gfMaxZoomCameraDistance_x                                0xB10D60
#define __gfMaxCameraDistance_x                                    0xB3D1E4
#define __pulAutoRun_x                                             0xECDFB0
#define __pulForward_x                                             0xECF5F0
#define __pulBackward_x                                            0xECF5F4
#define __pulTurnRight_x                                           0xECF5F8
#define __pulTurnLeft_x                                            0xECF5FC
#define __pulStrafeLeft_x                                          0xECF600
#define __pulStrafeRight_x                                         0xECF604

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEC91E8
#define instEQZoneInfo_x                                           0xECE188
#define pinstActiveBanker_x                                        0xEC68EC
#define pinstActiveCorpse_x                                        0xEC68E4
#define pinstActiveGMaster_x                                       0xEC68E8
#define pinstActiveMerchant_x                                      0xEC68E0
#define pinstAltAdvManager_x                                       0xE15418
#define pinstBandageTarget_x                                       0xEC6D0C
#define pinstCamActor_x                                            0xE14244
#define pinstCDBStr_x                                              0xE14134
#define pinstCDisplay_x                                            0xEC8D68
#define pinstCEverQuest_x                                          0xF728A8
#define pinstEverQuestInfo_x                                       0xECDEA8
#define pinstCharData_x                                            0xEC9108
#define pinstCharSpawn_x                                           0xEC6D44
#define pinstControlledMissile_x                                   0xEC6D54
#define pinstControlledPlayer_x                                    0xEC6D44
#define pinstCResolutionHandler_x                                  0x1604CC8
#define pinstCSidlManager_x                                        0x1603C60
#define pinstCXWndManager_x                                        0x1603C5C
#define instDynamicZone_x                                          0xECCD28
#define pinstDZMember_x                                            0xECCE38
#define pinstDZTimerInfo_x                                         0xECCE3C
#define pinstEqLogin_x                                             0xF72938
#define instEQMisc_x                                               0xE14078
#define pinstEQSoundManager_x                                      0xE163E8
#define pinstEQSpellStrings_x                                      0xCD6A90
#define instExpeditionLeader_x                                     0xECCD72
#define instExpeditionName_x                                       0xECCDB2
#define pinstGroup_x                                               0xEC8F16
#define pinstImeManager_x                                          0x1603C58
#define pinstLocalPlayer_x                                         0xEC68DC
#define pinstMercenaryData_x                                       0xF6F22C
#define pinstMercenaryStats_x                                      0xF8821C
#define pinstModelPlayer_x                                         0xEC68F4
#define pinstPCData_x                                              0xEC9108
#define pinstSkillMgr_x                                            0xF71390
#define pinstSpawnManager_x                                        0xF6FE38
#define pinstSpellManager_x                                        0xF715D0
#define pinstSpellSets_x                                           0xF6587C
#define pinstStringTable_x                                         0xEC9110
#define pinstSwitchManager_x                                       0xEC6788
#define pinstTarget_x                                              0xEC6D40
#define pinstTargetObject_x                                        0xEC6D4C
#define pinstTargetSwitch_x                                        0xEC8D60
#define pinstTaskMember_x                                          0xE13F08
#define pinstTrackTarget_x                                         0xEC6D48
#define pinstTradeTarget_x                                         0xEC68F0
#define instTributeActive_x                                        0xE14099
#define pinstViewActor_x                                           0xE14240
#define pinstWorldData_x                                           0xEC6D5C
#define pinstZoneAddr_x                                            0xECE428
#define pinstPlayerPath_x                                          0xF6FED0
#define pinstTargetIndicator_x                                     0xF71838
#define EQObject_Top_x                                             0xEC68D8
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE149BC
#define pinstCAchievementsWnd_x                                    0xE14A34
#define pinstCActionsWnd_x                                         0xE149E4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE14258
#define pinstCAdvancedLootWnd_x                                    0xE141F8
#define pinstCAdventureLeaderboardWnd_x                            0xF7EEF0
#define pinstCAdventureRequestWnd_x                                0xF7EFA0
#define pinstCAdventureStatsWnd_x                                  0xF7F050
#define pinstCAggroMeterWnd_x                                      0xE14264
#define pinstCAlarmWnd_x                                           0xE141D0
#define pinstCAlertHistoryWnd_x                                    0xE142C0
#define pinstCAlertStackWnd_x                                      0xE14200
#define pinstCAlertWnd_x                                           0xE14220
#define pinstCAltStorageWnd_x                                      0xF7F3B0
#define pinstCAudioTriggersWindow_x                                0xCC8DC0
#define pinstCAuraWnd_x                                            0xE14204
#define pinstCAvaZoneWnd_x                                         0xE1427C
#define pinstCBandolierWnd_x                                       0xE14248
#define pinstCBankWnd_x                                            0xE142A8
#define pinstCBarterMerchantWnd_x                                  0xF805F0
#define pinstCBarterSearchWnd_x                                    0xF806A0
#define pinstCBarterWnd_x                                          0xF80750
#define pinstCBazaarConfirmationWnd_x                              0xE141E0
#define pinstCBazaarSearchWnd_x                                    0xE149C0
#define pinstCBazaarWnd_x                                          0xE14A50
#define pinstCBlockedBuffWnd_x                                     0xE14214
#define pinstCBlockedPetBuffWnd_x                                  0xE14238
#define pinstCBodyTintWnd_x                                        0xE149F0
#define pinstCBookWnd_x                                            0xE14290
#define pinstCBreathWnd_x                                          0xE149D0
#define pinstCBuffWindowNORMAL_x                                   0xE141F0
#define pinstCBuffWindowSHORT_x                                    0xE141F4
#define pinstCBugReportWnd_x                                       0xE142A0
#define pinstCButtonWnd_x                                          0x1603EC8
#define pinstCCastingWnd_x                                         0xE14280
#define pinstCCastSpellWnd_x                                       0xE149C8
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE14A08
#define pinstCChatWindowManager_x                                  0xF81210
#define pinstCClaimWnd_x                                           0xF81368
#define pinstCColorPickerWnd_x                                     0xE14308
#define pinstCCombatAbilityWnd_x                                   0xE14A64
#define pinstCCombatSkillsSelectWnd_x                              0xE14A18
#define pinstCCompassWnd_x                                         0xE149E8
#define pinstCConfirmationDialog_x                                 0xF86268
#define pinstCContainerMgr_x                                       0xE14A04
#define pinstCContextMenuManager_x                                 0x1603C18
#define pinstCCursorAttachment_x                                   0xE14270
#define pinstCDynamicZoneWnd_x                                     0xF81930
#define pinstCEditLabelWnd_x                                       0xE141EC
#define pinstCEQMainWnd_x                                          0xF81B78
#define pinstCEventCalendarWnd_x                                   0xE149B8
#define pinstCExtendedTargetWnd_x                                  0xE14234
#define pinstCFacePick_x                                           0xE14A2C
#define pinstCFactionWnd_x                                         0xE14A40
#define pinstCFellowshipWnd_x                                      0xF81D78
#define pinstCFileSelectionWnd_x                                   0xE142E8
#define pinstCFindItemWnd_x                                        0xE14A24
#define pinstCFindLocationWnd_x                                    0xF81ED0
#define pinstCFriendsWnd_x                                         0xE14A28
#define pinstCGemsGameWnd_x                                        0xE14A38
#define pinstCGiveWnd_x                                            0xE141DC
#define pinstCGroupSearchFiltersWnd_x                              0xE14288
#define pinstCGroupSearchWnd_x                                     0xF822C8
#define pinstCGroupWnd_x                                           0xF82378
#define pinstCGuildBankWnd_x                                       0xECF26C
#define pinstCGuildCreationWnd_x                                   0xF824D8
#define pinstCGuildMgmtWnd_x                                       0xF82588
#define pinstCharacterCreation_x                                   0xE14A1C
#define pinstCHelpWnd_x                                            0xE141D4
#define pinstCHeritageSelectionWnd_x                               0xE14A44
#define pinstCHotButtonWnd_x                                       0xF846E0
#define pinstCHotButtonWnd1_x                                      0xF846E0
#define pinstCHotButtonWnd2_x                                      0xF846E4
#define pinstCHotButtonWnd3_x                                      0xF846E8
#define pinstCHotButtonWnd4_x                                      0xF846EC
#define pinstCIconSelectionWnd_x                                   0xE14268
#define pinstCInspectWnd_x                                         0xE1423C
#define pinstCInventoryWnd_x                                       0xE1420C
#define pinstCInvSlotMgr_x                                         0xE149C4
#define pinstCItemDisplayManager_x                                 0xF84C70
#define pinstCItemExpTransferWnd_x                                 0xF84DA0
#define pinstCItemOverflowWnd_x                                    0xE149CC
#define pinstCJournalCatWnd_x                                      0xE1432C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE142C4
#define pinstCKeyRingWnd_x                                         0xE14278
#define pinstCLargeDialogWnd_x                                     0xF86EE8
#define pinstCLayoutCopyWnd_x                                      0xF850F0
#define pinstCLFGuildWnd_x                                         0xF851A0
#define pinstCLoadskinWnd_x                                        0xE14A4C
#define pinstCLootFiltersCopyWnd_x                                 0xCE5410
#define pinstCLootFiltersWnd_x                                     0xE14208
#define pinstCLootSettingsWnd_x                                    0xE14230
#define pinstCLootWnd_x                                            0xE14540
#define pinstCMailAddressBookWnd_x                                 0xE149D4
#define pinstCMailCompositionWnd_x                                 0xE149B4
#define pinstCMailIgnoreListWnd_x                                  0xE142EC
#define pinstCMailWnd_x                                            0xE14314
#define pinstCManageLootWnd_x                                      0xE158C8
#define pinstCMapToolbarWnd_x                                      0xE141D8
#define pinstCMapViewWnd_x                                         0xE14A48
#define pinstCMarketplaceWnd_x                                     0xE14210
#define pinstCMerchantWnd_x                                        0xE145AC
#define pinstCMIZoneSelectWnd_x                                    0xF859D8
#define pinstCMusicPlayerWnd_x                                     0xE142B4
#define pinstCNameChangeMercWnd_x                                  0xE14A60
#define pinstCNameChangePetWnd_x                                   0xE14A3C
#define pinstCNameChangeWnd_x                                      0xE141E4
#define pinstCNoteWnd_x                                            0xE14A58
#define pinstCObjectPreviewWnd_x                                   0xE1422C
#define pinstCOptionsWnd_x                                         0xE14A68
#define pinstCPetInfoWnd_x                                         0xE142DC
#define pinstCPetitionQWnd_x                                       0xE14A0C
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE149F4
#define pinstCPlayerWnd_x                                          0xE142E4
#define pinstCPopupWndManager_x                                    0xF86268
#define pinstCProgressionSelectionWnd_x                            0xF86318
#define pinstCPurchaseGroupWnd_x                                   0xE14298
#define pinstCPurchaseWnd_x                                        0xE1426C
#define pinstCPvPLeaderboardWnd_x                                  0xF863C8
#define pinstCPvPStatsWnd_x                                        0xF86478
#define pinstCQuantityWnd_x                                        0xE142C8
#define pinstCRaceChangeWnd_x                                      0xE141FC
#define pinstCRaidOptionsWnd_x                                     0xE1428C
#define pinstCRaidWnd_x                                            0xE14544
#define pinstCRealEstateItemsWnd_x                                 0xE14A30
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE149E0
#define pinstCRealEstateManageWnd_x                                0xE142A4
#define pinstCRealEstateNeighborhoodWnd_x                          0xE142BC
#define pinstCRealEstatePlotSearchWnd_x                            0xE142E0
#define pinstCRealEstatePurchaseWnd_x                              0xE14318
#define pinstCRespawnWnd_x                                         0xE14228
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE14A10
#define pinstCSendMoneyWnd_x                                       0xE141E8
#define pinstCServerListWnd_x                                      0xE14320
#define pinstCSkillsSelectWnd_x                                    0xE14A00
#define pinstCSkillsWnd_x                                          0xE149EC
#define pinstCSocialEditWnd_x                                      0xE14274
#define pinstCSocialWnd_x                                          0xE14A54
#define pinstCSpellBookWnd_x                                       0xE14A5C
#define pinstCStoryWnd_x                                           0xE149DC
#define pinstCTargetOfTargetWnd_x                                  0xF882A0
#define pinstCTargetWnd_x                                          0xE14224
#define pinstCTaskOverlayWnd_x                                     0xE14294
#define pinstCTaskSelectWnd_x                                      0xF883F8
#define pinstCTaskManager_x                                        0xCE5D50
#define pinstCTaskTemplateSelectWnd_x                              0xF884A8
#define pinstCTaskWnd_x                                            0xF88558
#define pinstCTextEntryWnd_x                                       0xE14284
#define pinstCTimeLeftWnd_x                                        0xE149F8
#define pinstCTipWndCONTEXT_x                                      0xF8875C
#define pinstCTipWndOFDAY_x                                        0xF88758
#define pinstCTitleWnd_x                                           0xF88808
#define pinstCTrackingWnd_x                                        0xE14218
#define pinstCTradeskillWnd_x                                      0xF88970
#define pinstCTradeWnd_x                                           0xE149FC
#define pinstCTrainWnd_x                                           0xE14324
#define pinstCTributeBenefitWnd_x                                  0xF88B70
#define pinstCTributeMasterWnd_x                                   0xF88C20
#define pinstCTributeTrophyWnd_x                                   0xF88CD0
#define pinstCVideoModesWnd_x                                      0xE1431C
#define pinstCVoiceMacroWnd_x                                      0xF71FA0
#define pinstCVoteResultsWnd_x                                     0xE14A20
#define pinstCVoteWnd_x                                            0xE14A14
#define pinstCWebManager_x                                         0xF7261C
#define pinstCZoneGuideWnd_x                                       0xE1429C
#define pinstCZonePathWnd_x                                        0xE142AC

#define pinstEQSuiteTextureLoader_x                                0xCB3140
#define pinstItemIconCache_x                                       0xF81B30
#define pinstLootFiltersManager_x                                  0xCE54C0
#define pinstRewardSelectionWnd_x                                  0xF86BC0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5BE9A0
#define __CastRay2_x                                               0x5BE9F0
#define __ConvertItemTags_x                                        0x5DA830
#define __CleanItemTags_x                                          0x47CFB0
#define __DoesFileExist_x                                          0x915870
#define __EQGetTime_x                                              0x912260
#define __ExecuteCmd_x                                             0x5B7200
#define __FixHeading_x                                             0x9AD9A0
#define __GameLoop_x                                               0x6CC2B0
#define __get_bearing_x                                            0x5BE510
#define __get_melee_range_x                                        0x5BEBE0
#define __GetAnimationCache_x                                      0x731890
#define __GetGaugeValueFromEQ_x                                    0x823CE0
#define __GetLabelFromEQ_x                                         0x8257C0
#define __GetXTargetType_x                                         0x9AF3F0
#define __HandleMouseWheel_x                                       0x6CD190
#define __HeadingDiff_x                                            0x9ADA10
#define __HelpPath_x                                               0xF6D324
#define __LoadFrontEnd_x                                           0x6C95D0
#define __NewUIINI_x                                               0x8239B0
#define __ProcessGameEvents_x                                      0x61F5E0
#define __ProcessMouseEvent_x                                      0x61EDA0
#define __SaveColors_x                                             0x5594A0
#define __STMLToText_x                                             0x950DB0
#define __ToggleKeyRingItem_x                                      0x51A270
#define CMemoryMappedFile__SetFile_x                               0xA9CD10
#define CrashDetected_x                                            0x6CB070
#define DrawNetStatus_x                                            0x64B3C0
#define Expansion_HoT_x                                            0xECF274
#define Teleport_Table_Size_x                                      0xEC91A4
#define Teleport_Table_x                                           0xEC6D60
#define Util__FastTime_x                                           0x911E30

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4901E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499100
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498ED0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493780
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492BD0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x561670
#define AltAdvManager__IsAbilityReady_x                            0x560410
#define AltAdvManager__GetAAById_x                                 0x5607A0
#define AltAdvManager__CanTrainAbility_x                           0x560810
#define AltAdvManager__CanSeeAbility_x                             0x560B70

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CAD70
#define CharacterZoneClient__HasSkill_x                            0x4D5BF0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7310
#define CharacterZoneClient__IsStackBlocked_x                      0x4BF4F0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBB20
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9C70
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9D50
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9E30
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3BF0
#define CharacterZoneClient__BardCastBard_x                        0x4C6770
#define CharacterZoneClient__GetMaxEffects_x                       0x4BBBF0
#define CharacterZoneClient__GetEffect_x                           0x4BBA60
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4C40
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4D10
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4D60
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4EB0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5080
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3800
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8270
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7CF0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6F2E30
#define CBankWnd__WndNotification_x                                0x6F2C10

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x700670

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x62DDE0
#define CButtonWnd__CButtonWnd_x                                   0x94D180

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x720940
#define CChatManager__InitContextMenu_x                            0x719A70
#define CChatManager__FreeChatWindow_x                             0x71F480
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E91B0
#define CChatManager__SetLockedActiveChatWindow_x                  0x7205C0
#define CChatManager__CreateChatWindow_x                           0x71FAC0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E92D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x961800
#define CContextMenu__dCContextMenu_x                              0x961A40
#define CContextMenu__AddMenuItem_x                                0x961A50
#define CContextMenu__RemoveMenuItem_x                             0x961D60
#define CContextMenu__RemoveAllMenuItems_x                         0x961D80
#define CContextMenu__CheckMenuItem_x                              0x961E00
#define CContextMenu__SetMenuItem_x                                0x961C80
#define CContextMenu__AddSeparator_x                               0x961BE0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9623A0
#define CContextMenuManager__RemoveMenu_x                          0x962410
#define CContextMenuManager__PopupMenu_x                           0x9624D0
#define CContextMenuManager__Flush_x                               0x962340
#define CContextMenuManager__GetMenu_x                             0x49B300
#define CContextMenuManager__CreateDefaultMenu_x                   0x72C090

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8ED320
#define CChatService__GetFriendName_x                              0x8ED330

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x721170
#define CChatWindow__Clear_x                                       0x722440
#define CChatWindow__WndNotification_x                             0x722BD0
#define CChatWindow__AddHistory_x                                  0x721D00

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x95EC60
#define CComboWnd__Draw_x                                          0x95E140
#define CComboWnd__GetCurChoice_x                                  0x95EAA0
#define CComboWnd__GetListRect_x                                   0x95E600
#define CComboWnd__GetTextRect_x                                   0x95ECD0
#define CComboWnd__InsertChoice_x                                  0x95E790
#define CComboWnd__SetColors_x                                     0x95E760
#define CComboWnd__SetChoice_x                                     0x95EA70
#define CComboWnd__GetItemCount_x                                  0x95EAB0
#define CComboWnd__GetCurChoiceText_x                              0x95EAF0
#define CComboWnd__GetChoiceText_x                                 0x95EAC0
#define CComboWnd__InsertChoiceAtIndex_x                           0x95E830

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x729AA0
#define CContainerWnd__vftable_x                                   0xB2464C
#define CContainerWnd__SetContainer_x                              0x72AFF0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x553E50
#define CDisplay__PreZoneMainUI_x                                  0x553E60
#define CDisplay__CleanGameUI_x                                    0x559260
#define CDisplay__GetClickedActor_x                                0x54C210
#define CDisplay__GetUserDefinedColor_x                            0x544870
#define CDisplay__GetWorldFilePath_x                               0x54DC80
#define CDisplay__is3dON_x                                         0x548E70
#define CDisplay__ReloadUI_x                                       0x5532D0
#define CDisplay__WriteTextHD2_x                                   0x548C60
#define CDisplay__TrueDistance_x                                   0x54F940
#define CDisplay__SetViewActor_x                                   0x54BB30
#define CDisplay__GetFloorHeight_x                                 0x548F30
#define CDisplay__SetRenderWindow_x                                0x547890
#define CDisplay__ToggleScreenshotMode_x                           0x54B600

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x981510

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x964D70
#define CEditWnd__EnsureCaretVisible_x                             0x966F40
#define CEditWnd__GetCaretPt_x                                     0x965EF0
#define CEditWnd__GetCharIndexPt_x                                 0x965CA0
#define CEditWnd__GetDisplayString_x                               0x965B40
#define CEditWnd__GetHorzOffset_x                                  0x9643A0
#define CEditWnd__GetLineForPrintableChar_x                        0x966E40
#define CEditWnd__GetSelStartPt_x                                  0x965F50
#define CEditWnd__GetSTMLSafeText_x                                0x965960
#define CEditWnd__PointFromPrintableChar_x                         0x966A70
#define CEditWnd__SelectableCharFromPoint_x                        0x966BE0
#define CEditWnd__SetEditable_x                                    0x966020
#define CEditWnd__SetWindowTextA_x                                 0x9656E0
#define CEditWnd__ReplaceSelection_x                               0x9666E0
#define CEditWnd__ReplaceSelection1_x                              0x966660

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60D0A0
#define CEverQuest__ClickedPlayer_x                                0x5FF230
#define CEverQuest__CreateTargetIndicator_x                        0x61C870
#define CEverQuest__DeleteTargetIndicator_x                        0x61C900
#define CEverQuest__DoTellWindow_x                                 0x4E93B0
#define CEverQuest__OutputTextToLog_x                              0x4E9680
#define CEverQuest__DropHeldItemOnGround_x                         0x5F4390
#define CEverQuest__dsp_chat_x                                     0x4E9A10
#define CEverQuest__trimName_x                                     0x618A80
#define CEverQuest__Emote_x                                        0x60D900
#define CEverQuest__EnterZone_x                                    0x607990
#define CEverQuest__GetBodyTypeDesc_x                              0x6121C0
#define CEverQuest__GetClassDesc_x                                 0x612800
#define CEverQuest__GetClassThreeLetterCode_x                      0x612E00
#define CEverQuest__GetDeityDesc_x                                 0x61B0C0
#define CEverQuest__GetLangDesc_x                                  0x612FC0
#define CEverQuest__GetRaceDesc_x                                  0x6127E0
#define CEverQuest__InterpretCmd_x                                 0x61B690
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F8520
#define CEverQuest__LMouseUp_x                                     0x5F68B0
#define CEverQuest__RightClickedOnPlayer_x                         0x5F8E00
#define CEverQuest__RMouseUp_x                                     0x5F7830
#define CEverQuest__SetGameState_x                                 0x5F4120
#define CEverQuest__UPCNotificationFlush_x                         0x618980
#define CEverQuest__IssuePetCommand_x                              0x6143C0
#define CEverQuest__ReportSuccessfulHit_x                          0x60EC50

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x73B9C0
#define CGaugeWnd__CalcLinesFillRect_x                             0x73BA20
#define CGaugeWnd__Draw_x                                          0x73B050

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFB80
#define CGuild__GetGuildName_x                                     0x4AE630
#define CGuild__GetGuildIndex_x                                    0x4AEC30

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x755BF0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62E1A0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x762C40
#define CInvSlotMgr__MoveItem_x                                    0x761960
#define CInvSlotMgr__SelectSlot_x                                  0x762D10

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7601A0
#define CInvSlot__SliderComplete_x                                 0x75DF10
#define CInvSlot__GetItemBase_x                                    0x75D880
#define CInvSlot__UpdateItem_x                                     0x75D9F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7647A0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x763930
#define CInvSlotWnd__HandleLButtonUp_x                             0x764320

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x81F060
#define CItemDisplayWnd__UpdateStrings_x                           0x772F60
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76CBE0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76D110
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x773560
#define CItemDisplayWnd__AboutToShow_x                             0x772BD0
#define CItemDisplayWnd__WndNotification_x                         0x774690
#define CItemDisplayWnd__RequestConvertItem_x                      0x774110
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x771C30
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7729F0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x857C10

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x778B90

// CLabel 
#define CLabel__Draw_x                                             0x77E5E0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9375B0
#define CListWnd__dCListWnd_x                                      0x9378D0
#define CListWnd__AddColumn_x                                      0x93BD20
#define CListWnd__AddColumn1_x                                     0x93BD70
#define CListWnd__AddLine_x                                        0x93C100
#define CListWnd__AddString_x                                      0x93BF00
#define CListWnd__CalculateFirstVisibleLine_x                      0x93BAF0
#define CListWnd__CalculateVSBRange_x                              0x93B8D0
#define CListWnd__ClearSel_x                                       0x93C8E0
#define CListWnd__ClearAllSel_x                                    0x93C940
#define CListWnd__CloseAndUpdateEditWindow_x                       0x93D340
#define CListWnd__Compare_x                                        0x93B200
#define CListWnd__Draw_x                                           0x937A00
#define CListWnd__DrawColumnSeparators_x                           0x93A1E0
#define CListWnd__DrawHeader_x                                     0x93A640
#define CListWnd__DrawItem_x                                       0x93AB40
#define CListWnd__DrawLine_x                                       0x93A340
#define CListWnd__DrawSeparator_x                                  0x93A280
#define CListWnd__EnableLine_x                                     0x939AD0
#define CListWnd__EnsureVisible_x                                  0x93D270
#define CListWnd__ExtendSel_x                                      0x93C810
#define CListWnd__GetColumnTooltip_x                               0x939610
#define CListWnd__GetColumnMinWidth_x                              0x939680
#define CListWnd__GetColumnWidth_x                                 0x939580
#define CListWnd__GetCurSel_x                                      0x938F10
#define CListWnd__GetItemAtPoint_x                                 0x939D40
#define CListWnd__GetItemAtPoint1_x                                0x939DB0
#define CListWnd__GetItemData_x                                    0x938F90
#define CListWnd__GetItemHeight_x                                  0x939350
#define CListWnd__GetItemIcon_x                                    0x939120
#define CListWnd__GetItemRect_x                                    0x939BC0
#define CListWnd__GetItemText_x                                    0x938FD0
#define CListWnd__GetSelList_x                                     0x93C990
#define CListWnd__GetSeparatorRect_x                               0x939FF0
#define CListWnd__InsertLine_x                                     0x93C4F0
#define CListWnd__RemoveLine_x                                     0x93C640
#define CListWnd__SetColors_x                                      0x93B8A0
#define CListWnd__SetColumnJustification_x                         0x93B5D0
#define CListWnd__SetColumnLabel_x                                 0x93BEA0
#define CListWnd__SetColumnWidth_x                                 0x93B4F0
#define CListWnd__SetCurSel_x                                      0x93C750
#define CListWnd__SetItemColor_x                                   0x93CF30
#define CListWnd__SetItemData_x                                    0x93CEF0
#define CListWnd__SetItemText_x                                    0x93CB00
#define CListWnd__ShiftColumnSeparator_x                           0x93B690
#define CListWnd__Sort_x                                           0x93B380
#define CListWnd__ToggleSel_x                                      0x93C780
#define CListWnd__SetColumnsSizable_x                              0x93B740
#define CListWnd__SetItemWnd_x                                     0x93CDB0
#define CListWnd__GetItemWnd_x                                     0x939170
#define CListWnd__SetItemIcon_x                                    0x93CB80
#define CListWnd__CalculateCustomWindowPositions_x                 0x93BBE0
#define CListWnd__SetVScrollPos_x                                  0x93B4D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x793D00
#define CMapViewWnd__GetWorldCoordinates_x                         0x792410
#define CMapViewWnd__HandleLButtonDown_x                           0x78F450

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B3F80
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B4860
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B4D90
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B7D10
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B2B00
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BD8C0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B3BA0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8BAF70
#define CPacketScrambler__hton_x                                   0x8BAF60

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9563B0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9567C0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9565B0
#define CSidlManager__CreateLabel_x                                0x816260
#define CSidlManager__CreateXWndFromTemplate_x                     0x959720
#define CSidlManager__CreateXWndFromTemplate1_x                    0x959900
#define CSidlManager__CreateXWnd_x                                 0x816190
#define CSidlManager__CreateHotButtonWnd_x                         0x816760

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x952ED0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x952DD0
#define CSidlScreenWnd__ConvertToRes_x                             0x97BFF0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x952860
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x952550
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x952620
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9526F0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x953350
#define CSidlScreenWnd__EnableIniStorage_x                         0x953820
#define CSidlScreenWnd__GetSidlPiece_x                             0x953540
#define CSidlScreenWnd__Init1_x                                    0x952150
#define CSidlScreenWnd__LoadIniInfo_x                              0x953870
#define CSidlScreenWnd__LoadIniListWnd_x                           0x954390
#define CSidlScreenWnd__LoadSidlScreen_x                           0x951570
#define CSidlScreenWnd__StoreIniInfo_x                             0x953F10
#define CSidlScreenWnd__StoreIniVis_x                              0x954270
#define CSidlScreenWnd__WndNotification_x                          0x953260
#define CSidlScreenWnd__GetChildItem_x                             0x9537A0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9430E0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1603AE8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x692F00
#define CSkillMgr__GetSkillCap_x                                   0x6930E0
#define CSkillMgr__GetNameToken_x                                  0x692680
#define CSkillMgr__IsActivatedSkill_x                              0x6927C0
#define CSkillMgr__IsCombatSkill_x                                 0x692700

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x963180
#define CSliderWnd__SetValue_x                                     0x962FF0
#define CSliderWnd__SetNumTicks_x                                  0x963050

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x81C3A0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x96B990
#define CStmlWnd__ParseSTML_x                                      0x96CD10
#define CStmlWnd__CalculateHSBRange_x                              0x96CAF0
#define CStmlWnd__CalculateVSBRange_x                              0x96CA70
#define CStmlWnd__CanBreakAtCharacter_x                            0x970E20
#define CStmlWnd__FastForwardToEndOfTag_x                          0x971AB0
#define CStmlWnd__ForceParseNow_x                                  0x96BFD0
#define CStmlWnd__GetNextTagPiece_x                                0x970D80
#define CStmlWnd__GetSTMLText_x                                    0x509890
#define CStmlWnd__GetVisibleText_x                                 0x96BFF0
#define CStmlWnd__InitializeWindowVariables_x                      0x971900
#define CStmlWnd__MakeStmlColorTag_x                               0x96B000
#define CStmlWnd__MakeWndNotificationTag_x                         0x96B070
#define CStmlWnd__SetSTMLText_x                                    0x96A0B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x972B70
#define CStmlWnd__UpdateHistoryString_x                            0x971CC0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x969200
#define CTabWnd__DrawCurrentPage_x                                 0x969930
#define CTabWnd__DrawTab_x                                         0x969650
#define CTabWnd__GetCurrentPage_x                                  0x968A00
#define CTabWnd__GetPageInnerRect_x                                0x968C40
#define CTabWnd__GetTabInnerRect_x                                 0x968B80
#define CTabWnd__GetTabRect_x                                      0x968A30
#define CTabWnd__InsertPage_x                                      0x968E50
#define CTabWnd__RemovePage_x                                      0x968FC0
#define CTabWnd__SetPage_x                                         0x968CC0
#define CTabWnd__SetPageRect_x                                     0x969140
#define CTabWnd__UpdatePage_x                                      0x969510
#define CTabWnd__GetPageFromTabIndex_x                             0x969590
#define CTabWnd__GetCurrentTabIndex_x                              0x9689F0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x778F60
#define CPageWnd__SetTabText_x                                     0x968540
#define CPageWnd__FlashTab_x                                       0x9685A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8E80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93FF80
#define CTextureFont__GetTextExtent_x                              0x940140

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C6190
#define CHtmlComponentWnd__ValidateUri_x                           0x7575E0
#define CHtmlWnd__SetClientCallbacks_x                             0x633210
#define CHtmlWnd__AddObserver_x                                    0x633230
#define CHtmlWnd__RemoveObserver_x                                 0x633290
#define Window__getProgress_x                                      0x870240
#define Window__getStatus_x                                        0x870260
#define Window__getURI_x                                           0x870270

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x978E00

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x92D310

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E90A0
#define CXStr__CXStr1_x                                            0x504A50
#define CXStr__CXStr3_x                                            0x90E3C0
#define CXStr__dCXStr_x                                            0x478690
#define CXStr__operator_equal_x                                    0x90E5F0
#define CXStr__operator_equal1_x                                   0x90E630
#define CXStr__operator_plus_equal1_x                              0x90F0C0
#define CXStr__SetString_x                                         0x910FB0
#define CXStr__operator_char_p_x                                   0x90EB00
#define CXStr__GetChar_x                                           0x910900
#define CXStr__Delete_x                                            0x9101B0
#define CXStr__GetUnicode_x                                        0x910970
#define CXStr__GetLength_x                                         0x47D360
#define CXStr__Mid_x                                               0x47D370
#define CXStr__Insert_x                                            0x9109D0
#define CXStr__FindNext_x                                          0x910620

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x961420
#define CXWnd__BringToTop_x                                        0x946750
#define CXWnd__Center_x                                            0x9462D0
#define CXWnd__ClrFocus_x                                          0x9460F0
#define CXWnd__Destroy_x                                           0x946190
#define CXWnd__DoAllDrawing_x                                      0x942870
#define CXWnd__DrawChildren_x                                      0x942840
#define CXWnd__DrawColoredRect_x                                   0x942CD0
#define CXWnd__DrawTooltip_x                                       0x941370
#define CXWnd__DrawTooltipAtPoint_x                                0x941430
#define CXWnd__GetBorderFrame_x                                    0x942B30
#define CXWnd__GetChildWndAt_x                                     0x9467F0
#define CXWnd__GetClientClipRect_x                                 0x944AB0
#define CXWnd__GetScreenClipRect_x                                 0x944B80
#define CXWnd__GetScreenRect_x                                     0x944D40
#define CXWnd__GetRelativeRect_x                                   0x944DF0
#define CXWnd__GetTooltipRect_x                                    0x942D20
#define CXWnd__GetWindowTextA_x                                    0x49CA00
#define CXWnd__IsActive_x                                          0x943460
#define CXWnd__IsDescendantOf_x                                    0x9456E0
#define CXWnd__IsReallyVisible_x                                   0x945710
#define CXWnd__IsType_x                                            0x946E50
#define CXWnd__Move_x                                              0x945770
#define CXWnd__Move1_x                                             0x945820
#define CXWnd__ProcessTransition_x                                 0x946280
#define CXWnd__Refade_x                                            0x945AD0
#define CXWnd__Resize_x                                            0x945D50
#define CXWnd__Right_x                                             0x946510
#define CXWnd__SetFocus_x                                          0x9460B0
#define CXWnd__SetFont_x                                           0x946120
#define CXWnd__SetKeyTooltip_x                                     0x946C60
#define CXWnd__SetMouseOver_x                                      0x943C50
#define CXWnd__StartFade_x                                         0x9455C0
#define CXWnd__GetChildItem_x                                      0x946960
#define CXWnd__SetParent_x                                         0x945490
#define CXWnd__Minimize_x                                          0x945DC0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x97D070

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9495E0
#define CXWndManager__DrawWindows_x                                0x949600
#define CXWndManager__GetKeyboardFlags_x                           0x94BDD0
#define CXWndManager__HandleKeyboardMsg_x                          0x94B980
#define CXWndManager__RemoveWnd_x                                  0x94C000
#define CXWndManager__RemovePendingDeletionWnd_x                   0x94C550

// CDBStr
#define CDBStr__GetString_x                                        0x543840

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BCB00
#define EQ_Character__Cur_HP_x                                     0x4D2C30
#define EQ_Character__Cur_Mana_x                                   0x4DA330
#define EQ_Character__GetCastingTimeModifier_x                     0x4BFB40
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3440
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3590
#define EQ_Character__GetHPRegen_x                                 0x4E00D0
#define EQ_Character__GetEnduranceRegen_x                          0x4E06D0
#define EQ_Character__GetManaRegen_x                               0x4E0B10
#define EQ_Character__Max_Endurance_x                              0x659730
#define EQ_Character__Max_HP_x                                     0x4D2A60
#define EQ_Character__Max_Mana_x                                   0x659530
#define EQ_Character__doCombatAbility_x                            0x65BB50
#define EQ_Character__UseSkill_x                                   0x4E28F0
#define EQ_Character__GetConLevel_x                                0x652370
#define EQ_Character__IsExpansionFlag_x                            0x5B59B0
#define EQ_Character__TotalEffect_x                                0x4C5EB0
#define EQ_Character__GetPCSpellAffect_x                           0x4C0890
#define EQ_Character__SpellDuration_x                              0x4C03C0
#define EQ_Character__MySpellDuration_x                            0x4B1D70
#define EQ_Character__GetAdjustedSkill_x                           0x4D59B0
#define EQ_Character__GetBaseSkill_x                               0x4D6950
#define EQ_Character__CanUseItem_x                                 0x4DA640

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8DA320

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x66FB00

//PcClient
#define PcClient__vftable_x                                        0xB15DC8
#define PcClient__PcClient_x                                       0x64FAD0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA6D0
#define CCharacterListWnd__EnterWorld_x                            0x4BA0B0
#define CCharacterListWnd__Quit_x                                  0x4B9E00
#define CCharacterListWnd__UpdateList_x                            0x4BA2A0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x634400
#define EQ_Item__CreateItemTagString_x                             0x8B4530
#define EQ_Item__IsStackable_x                                     0x8B91D0
#define EQ_Item__GetImageNum_x                                     0x8B6090
#define EQ_Item__CreateItemClient_x                                0x633630
#define EQ_Item__GetItemValue_x                                    0x8B73D0
#define EQ_Item__ValueSellMerchant_x                               0x8BAB50
#define EQ_Item__IsKeyRingItem_x                                   0x8B8AF0
#define EQ_Item__CanGoInBag_x                                      0x634520
#define EQ_Item__IsEmpty_x                                         0x8B8640
#define EQ_Item__GetMaxItemCount_x                                 0x8B77E0
#define EQ_Item__GetHeldItem_x                                     0x8B5F60
#define EQ_Item__GetAugmentFitBySlot_x                             0x8B3E70

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x562340
#define EQ_LoadingS__Array_x                                       0xC3AC60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65A070
#define EQ_PC__GetAlternateAbilityId_x                             0x8C3FA0
#define EQ_PC__GetCombatAbility_x                                  0x8C4610
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C4680
#define EQ_PC__GetItemRecastTimer_x                                0x65C0D0
#define EQ_PC__HasLoreItem_x                                       0x652B80
#define EQ_PC__AlertInventoryChanged_x                             0x651CA0
#define EQ_PC__GetPcZoneClient_x                                   0x67E5A0
#define EQ_PC__RemoveMyAffect_x                                    0x65F310
#define EQ_PC__GetKeyRingItems_x                                   0x8C4F10
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C4CA0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C5210

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BBF00
#define EQItemList__add_object_x                                   0x5E9B90
#define EQItemList__add_item_x                                     0x5BC460
#define EQItemList__delete_item_x                                  0x5BC4B0
#define EQItemList__FreeItemList_x                                 0x5BC3B0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x540400

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x671380
#define EQPlayer__dEQPlayer_x                                      0x664850
#define EQPlayer__DoAttack_x                                       0x679260
#define EQPlayer__EQPlayer_x                                       0x664F10
#define EQPlayer__SetNameSpriteState_x                             0x669180
#define EQPlayer__SetNameSpriteTint_x                              0x66A060
#define PlayerBase__HasProperty_j_x                                0x9ABDB0
#define EQPlayer__IsTargetable_x                                   0x9AC250
#define EQPlayer__CanSee_x                                         0x9AC0B0
#define EQPlayer__CanSee1_x                                        0x9AC180
#define PlayerBase__GetVisibilityLineSegment_x                     0x9ABE70

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67C040
#define PlayerZoneClient__GetLevel_x                               0x67E5E0
#define PlayerZoneClient__IsValidTeleport_x                        0x5EAD00
#define PlayerZoneClient__LegalPlayerRace_x                        0x55B090

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x674160
#define EQPlayerManager__GetSpawnByName_x                          0x674210
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6742A0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x637B40
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x637BC0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x637C00
#define KeypressHandler__ClearCommandStateArray_x                  0x639010
#define KeypressHandler__HandleKeyDown_x                           0x639030
#define KeypressHandler__HandleKeyUp_x                             0x6390D0
#define KeypressHandler__SaveKeymapping_x                          0x639520

// MapViewMap 
#define MapViewMap__Clear_x                                        0x78FB70
#define MapViewMap__SaveEx_x                                       0x792F30
#define MapViewMap__SetZoom_x                                      0x7975F0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D8350

// StringTable 
#define StringTable__getString_x                                   0x8D3210

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x65EF80
#define PcZoneClient__RemovePetEffect_x                            0x65F5B0
#define PcZoneClient__HasAlternateAbility_x                        0x659360
#define PcZoneClient__GetCurrentMod_x                              0x4E59B0
#define PcZoneClient__GetModCap_x                                  0x4E58B0
#define PcZoneClient__CanEquipItem_x                               0x659A10
#define PcZoneClient__GetItemByID_x                                0x65C550
#define PcZoneClient__GetItemByItemClass_x                         0x65C6A0
#define PcZoneClient__RemoveBuffEffect_x                           0x65F5D0
#define PcZoneClient__BandolierSwap_x                              0x65A620
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65C070

//Doors
#define EQSwitch__UseSwitch_x                                      0x5EF870

//IconCache
#define IconCache__GetIcon_x                                       0x731130

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x728C40
#define CContainerMgr__CloseContainer_x                            0x728F10
#define CContainerMgr__OpenExperimentContainer_x                   0x729990

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E83C0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62C5C0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7860B0
#define CLootWnd__RequestLootSlot_x                                0x7852E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x588EE0
#define EQ_Spell__SpellAffects_x                                   0x589350
#define EQ_Spell__SpellAffectBase_x                                0x589110
#define EQ_Spell__IsStackable_x                                    0x4CA680
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA4D0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7910
#define EQ_Spell__IsSPAStacking_x                                  0x58A1A0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5896B0
#define EQ_Spell__IsNoRemove_x                                     0x4CA660
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58A1B0
#define __IsResEffectSpell_x                                       0x4C9930

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD0E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8E2980

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82F840
#define CTargetWnd__WndNotification_x                              0x82F080
#define CTargetWnd__RefreshTargetBuffs_x                           0x82F350
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82E1E0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x833E90
#define CTaskWnd__ConfirmAbandonTask_x                             0x836AD0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53DE10
#define CTaskManager__HandleMessage_x                              0x53C2B0
#define CTaskManager__GetTaskStatus_x                              0x53DEC0
#define CTaskManager__GetElementDescription_x                      0x53DF40

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x584050
#define EqSoundManager__PlayScriptMp3_x                            0x584310
#define EqSoundManager__SoundAssistPlay_x                          0x696E40
#define EqSoundManager__WaveInstancePlay_x                         0x6963B0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52F420

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x967A50
#define CTextureAnimation__Draw_x                                  0x967C50

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x963AE0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x569DE0
#define CAltAbilityData__GetMercMaxRank_x                          0x569D70
#define CAltAbilityData__GetMaxRank_x                              0x55F290

//CTargetRing
#define CTargetRing__Cast_x                                        0x62A6E0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA4B0
#define CharacterBase__CreateItemGlobalIndex_x                     0x5167C0
#define CharacterBase__CreateItemIndex_x                           0x6327C0
#define CharacterBase__GetItemPossession_x                         0x502330
#define CharacterBase__GetItemByGlobalIndex_x                      0x8EAFF0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8EB050
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x70FCF0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x710520
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x7105D0

//messages
#define msg_spell_worn_off_x                                       0x5AD8D0
#define msg_new_text_x                                             0x5A22D0
#define __msgTokenTextParam_x                                      0x5AFB70
#define msgTokenText_x                                             0x5AFDC0

//SpellManager
#define SpellManager__vftable_x                                    0xAFE148
#define SpellManager__SpellManager_x                               0x69A170
#define Spellmanager__LoadTextSpells_x                             0x69AA60
#define SpellManager__GetSpellByGroupAndRank_x                     0x69A340

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9AFCE0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x516E40
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B3D40
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64B220
#define ItemGlobalIndex__IsValidIndex_x                            0x516EA0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8E3320
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8E35A0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77E920

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72D330
#define CCursorAttachment__AttachToCursor1_x                       0x72D370
#define CCursorAttachment__Deactivate_x                            0x72E360

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x95A760
#define CSidlManagerBase__CreatePageWnd_x                          0x959F50
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9561D0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x956160

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9778D0
#define CEQSuiteTextureLoader__GetTexture_x                        0x977590

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x513D30
#define CFindItemWnd__WndNotification_x                            0x514810
#define CFindItemWnd__Update_x                                     0x515380
#define CFindItemWnd__PickupSelectedItem_x                         0x513570

//IString
#define IString__Append_x                                          0x503B60

//Camera
#define CDisplay__cameraType_x                                     0xE14328
#define EverQuest__Cameras_x                                       0xECF5C4

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51C600
#define LootFiltersManager__GetItemFilterData_x                    0x51BF10
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51BF40
#define LootFiltersManager__SetItemLootFilter_x                    0x51C160

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D6180

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B5820
#define CResolutionHandler__GetWindowedStyle_x                     0x691AC0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7258E0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F88D0
#define CDistillerInfo__Instance_x                                 0x8F8870

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7449B0
#define CGroupWnd__UpdateDisplay_x                                 0x743D00

//ItemBase
#define ItemBase__IsLore_x                                         0x8B8BA0
#define ItemBase__IsLoreEquipped_x                                 0x8B8C10

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5E9AF0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5E9C30
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5E9C90

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x686CD0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68A6B0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50A0E0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F66C0
#define FactionManagerClient__HandleFactionMessage_x               0x4F6D30
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F72F0
#define FactionManagerClient__GetMaxFaction_x                      0x4F730F
#define FactionManagerClient__GetMinFaction_x                      0x4F72C0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x502300

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x93EFE0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BCE0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x502570

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x5692A0

//CTargetManager
#define CTargetManager__Get_x                                      0x69D990

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x686CD0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8C40

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BC350

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF6CC58

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6D9510
#define CAAWnd__UpdateSelected_x                                   0x6D5D80
#define CAAWnd__Update_x                                           0x6D8830

//CXRect
#define CXRect__operator_and_x                                     0x73BA80

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
