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
#define __ExpectedVersionDate                                     "May 26 2020"
#define __ExpectedVersionTime                                     "08:54:23"
#define __ActualVersionDate_x                                      0xB1B420
#define __ActualVersionTime_x                                      0xB1B414
#define __ActualVersionBuild_x                                     0xB07114

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x63EAF0
#define __MemChecker1_x                                            0x912BB0
#define __MemChecker2_x                                            0x6CD880
#define __MemChecker3_x                                            0x6CD7D0
#define __MemChecker4_x                                            0x869270
#define __EncryptPad0_x                                            0xC53500
#define __EncryptPad1_x                                            0xCB1668
#define __EncryptPad2_x                                            0xC63D98
#define __EncryptPad3_x                                            0xC63998
#define __EncryptPad4_x                                            0xCA1C18
#define __EncryptPad5_x                                            0xF7286C
#define __AC1_x                                                    0x8259D6
#define __AC2_x                                                    0x5F86FF
#define __AC3_x                                                    0x5FFD4F
#define __AC4_x                                                    0x603D10
#define __AC5_x                                                    0x609FBF
#define __AC6_x                                                    0x60E4C6
#define __AC7_x                                                    0x5F8170
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
#define __do_loot_x                                                0x5C3F40
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
#define __gfMaxZoomCameraDistance_x                                0xB10D70
#define __gfMaxCameraDistance_x                                    0xB3D1F4
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
#define pinstCMailWnd_x                                            0xE14318
#define pinstCManageLootWnd_x                                      0xE158C8
#define pinstCMapToolbarWnd_x                                      0xE141D8
#define pinstCMapViewWnd_x                                         0xE14A48
#define pinstCMarketplaceWnd_x                                     0xE14210
#define pinstCMerchantWnd_x                                        0xE145AC
#define pinstCMIZoneSelectWnd_x                                    0xF859D8
#define pinstCMusicPlayerWnd_x                                     0xE142B4
#define pinstCNameChangeMercWnd_x                                  0xE14A5C
#define pinstCNameChangePetWnd_x                                   0xE14A3C
#define pinstCNameChangeWnd_x                                      0xE141E4
#define pinstCNoteWnd_x                                            0xE14A58
#define pinstCObjectPreviewWnd_x                                   0xE1422C
#define pinstCOptionsWnd_x                                         0xE14A68
#define pinstCPetInfoWnd_x                                         0xE142E0
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
#define pinstCRealEstatePlotSearchWnd_x                            0xE142DC
#define pinstCRealEstatePurchaseWnd_x                              0xE14314
#define pinstCRespawnWnd_x                                         0xE14228
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE14A10
#define pinstCSendMoneyWnd_x                                       0xE141E8
#define pinstCServerListWnd_x                                      0xE14320
#define pinstCSkillsSelectWnd_x                                    0xE14A00
#define pinstCSkillsWnd_x                                          0xE149EC
#define pinstCSocialEditWnd_x                                      0xE14274
#define pinstCSocialWnd_x                                          0xE14A54
#define pinstCSpellBookWnd_x                                       0xE14A60
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
#define __CastRay_x                                                0x5BF310
#define __CastRay2_x                                               0x5BF360
#define __ConvertItemTags_x                                        0x5DB1A0
#define __CleanItemTags_x                                          0x47CFC0
#define __DoesFileExist_x                                          0x915BE0
#define __EQGetTime_x                                              0x912680
#define __ExecuteCmd_x                                             0x5B7B90
#define __FixHeading_x                                             0x9AD330
#define __GameLoop_x                                               0x6CCA50
#define __get_bearing_x                                            0x5BEE80
#define __get_melee_range_x                                        0x5BF550
#define __GetAnimationCache_x                                      0x731ED0
#define __GetGaugeValueFromEQ_x                                    0x823E80
#define __GetLabelFromEQ_x                                         0x825960
#define __GetXTargetType_x                                         0x9AED10
#define __HandleMouseWheel_x                                       0x6CD930
#define __HeadingDiff_x                                            0x9AD3A0
#define __HelpPath_x                                               0xF6D324
#define __LoadFrontEnd_x                                           0x6C9D70
#define __NewUIINI_x                                               0x823B50
#define __ProcessGameEvents_x                                      0x620060
#define __ProcessMouseEvent_x                                      0x61F820
#define __SaveColors_x                                             0x559A40
#define __STMLToText_x                                             0x9507A0
#define __ToggleKeyRingItem_x                                      0x51A4F0
#define CMemoryMappedFile__SetFile_x                               0xA9C430
#define CrashDetected_x                                            0x6CB810
#define DrawNetStatus_x                                            0x64C050
#define Expansion_HoT_x                                            0xECF274
#define Teleport_Table_Size_x                                      0xEC91A4
#define Teleport_Table_x                                           0xEC6D60
#define Util__FastTime_x                                           0x912250
#define __CopyLayout_x                                             0x63A220

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490270
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499170
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498F40
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493800
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492C50

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x561BE0
#define AltAdvManager__IsAbilityReady_x                            0x560980
#define AltAdvManager__GetAAById_x                                 0x560D10
#define AltAdvManager__CanTrainAbility_x                           0x560D80
#define AltAdvManager__CanSeeAbility_x                             0x5610E0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB040
#define CharacterZoneClient__HasSkill_x                            0x4D5EC0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D75E0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BF6D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBD00
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9F60
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA040
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA120
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3DD0
#define CharacterZoneClient__BardCastBard_x                        0x4C6950
#define CharacterZoneClient__GetMaxEffects_x                       0x4BBDD0
#define CharacterZoneClient__GetEffect_x                           0x4BBC40
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4E20
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4EF0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4F40
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5090
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5260
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3A50
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8540
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7FC0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6F3470
#define CBankWnd__WndNotification_x                                0x6F3250

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x700CE0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x62E7C0
#define CButtonWnd__CButtonWnd_x                                   0x94CBA0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x720EE0
#define CChatManager__InitContextMenu_x                            0x71A010
#define CChatManager__FreeChatWindow_x                             0x71FA20
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9460
#define CChatManager__SetLockedActiveChatWindow_x                  0x720B60
#define CChatManager__CreateChatWindow_x                           0x720060

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9570

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9611A0
#define CContextMenu__dCContextMenu_x                              0x9613E0
#define CContextMenu__AddMenuItem_x                                0x9613F0
#define CContextMenu__RemoveMenuItem_x                             0x961700
#define CContextMenu__RemoveAllMenuItems_x                         0x961720
#define CContextMenu__CheckMenuItem_x                              0x9617A0
#define CContextMenu__SetMenuItem_x                                0x961620
#define CContextMenu__AddSeparator_x                               0x961580

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x961D40
#define CContextMenuManager__RemoveMenu_x                          0x961DB0
#define CContextMenuManager__PopupMenu_x                           0x961E70
#define CContextMenuManager__Flush_x                               0x961CE0
#define CContextMenuManager__GetMenu_x                             0x49B330
#define CContextMenuManager__CreateDefaultMenu_x                   0x72C6F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8ED800
#define CChatService__GetFriendName_x                              0x8ED810

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7217D0
#define CChatWindow__Clear_x                                       0x722AA0
#define CChatWindow__WndNotification_x                             0x723230
#define CChatWindow__AddHistory_x                                  0x722360

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x95E600
#define CComboWnd__Draw_x                                          0x95DAF0
#define CComboWnd__GetCurChoice_x                                  0x95E440
#define CComboWnd__GetListRect_x                                   0x95DFA0
#define CComboWnd__GetTextRect_x                                   0x95E670
#define CComboWnd__InsertChoice_x                                  0x95E130
#define CComboWnd__SetColors_x                                     0x95E100
#define CComboWnd__SetChoice_x                                     0x95E410
#define CComboWnd__GetItemCount_x                                  0x95E450
#define CComboWnd__GetCurChoiceText_x                              0x95E490
#define CComboWnd__GetChoiceText_x                                 0x95E460
#define CComboWnd__InsertChoiceAtIndex_x                           0x95E1D0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x72A0F0
#define CContainerWnd__vftable_x                                   0xB2461C
#define CContainerWnd__SetContainer_x                              0x72B650

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5543F0
#define CDisplay__PreZoneMainUI_x                                  0x554400
#define CDisplay__CleanGameUI_x                                    0x559800
#define CDisplay__GetClickedActor_x                                0x54C7B0
#define CDisplay__GetUserDefinedColor_x                            0x544E10
#define CDisplay__GetWorldFilePath_x                               0x54E220
#define CDisplay__is3dON_x                                         0x549410
#define CDisplay__ReloadUI_x                                       0x553870
#define CDisplay__WriteTextHD2_x                                   0x549200
#define CDisplay__TrueDistance_x                                   0x54FEE0
#define CDisplay__SetViewActor_x                                   0x54C0D0
#define CDisplay__GetFloorHeight_x                                 0x5494D0
#define CDisplay__SetRenderWindow_x                                0x547E30
#define CDisplay__ToggleScreenshotMode_x                           0x54BBA0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x980EA0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x964740
#define CEditWnd__EnsureCaretVisible_x                             0x966910
#define CEditWnd__GetCaretPt_x                                     0x9658C0
#define CEditWnd__GetCharIndexPt_x                                 0x965670
#define CEditWnd__GetDisplayString_x                               0x965510
#define CEditWnd__GetHorzOffset_x                                  0x963D70
#define CEditWnd__GetLineForPrintableChar_x                        0x966810
#define CEditWnd__GetSelStartPt_x                                  0x965920
#define CEditWnd__GetSTMLSafeText_x                                0x965330
#define CEditWnd__PointFromPrintableChar_x                         0x966440
#define CEditWnd__SelectableCharFromPoint_x                        0x9665B0
#define CEditWnd__SetEditable_x                                    0x9659F0
#define CEditWnd__SetWindowTextA_x                                 0x9650B0
#define CEditWnd__ReplaceSelection_x                               0x9660B0
#define CEditWnd__ReplaceSelection1_x                              0x966030

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60D9A0
#define CEverQuest__ClickedPlayer_x                                0x5FFB30
#define CEverQuest__CreateTargetIndicator_x                        0x61D300
#define CEverQuest__DeleteTargetIndicator_x                        0x61D390
#define CEverQuest__DoTellWindow_x                                 0x4E9650
#define CEverQuest__OutputTextToLog_x                              0x4E9920
#define CEverQuest__DropHeldItemOnGround_x                         0x5F4C90
#define CEverQuest__dsp_chat_x                                     0x4E9CB0
#define CEverQuest__trimName_x                                     0x619510
#define CEverQuest__Emote_x                                        0x60E200
#define CEverQuest__EnterZone_x                                    0x608290
#define CEverQuest__GetBodyTypeDesc_x                              0x612AC0
#define CEverQuest__GetClassDesc_x                                 0x613100
#define CEverQuest__GetClassThreeLetterCode_x                      0x613700
#define CEverQuest__GetDeityDesc_x                                 0x61BB50
#define CEverQuest__GetLangDesc_x                                  0x6138C0
#define CEverQuest__GetRaceDesc_x                                  0x6130E0
#define CEverQuest__InterpretCmd_x                                 0x61C120
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F8E20
#define CEverQuest__LMouseUp_x                                     0x5F71B0
#define CEverQuest__RightClickedOnPlayer_x                         0x5F9700
#define CEverQuest__RMouseUp_x                                     0x5F8130
#define CEverQuest__SetGameState_x                                 0x5F4A20
#define CEverQuest__UPCNotificationFlush_x                         0x619410
#define CEverQuest__IssuePetCommand_x                              0x614CC0
#define CEverQuest__ReportSuccessfulHit_x                          0x60F550

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x73C0A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x73C100
#define CGaugeWnd__Draw_x                                          0x73B720

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFCE0
#define CGuild__GetGuildName_x                                     0x4AE790
#define CGuild__GetGuildIndex_x                                    0x4AED90

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x756280

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62EB80

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x763200
#define CInvSlotMgr__MoveItem_x                                    0x761F60
#define CInvSlotMgr__SelectSlot_x                                  0x7632D0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7607E0
#define CInvSlot__SliderComplete_x                                 0x75E540
#define CInvSlot__GetItemBase_x                                    0x75DEE0
#define CInvSlot__UpdateItem_x                                     0x75E050

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x764D40
#define CInvSlotWnd__CInvSlotWnd_x                                 0x763EE0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7648C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x81F220
#define CItemDisplayWnd__UpdateStrings_x                           0x773410
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76D120
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76D640
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x773A10
#define CItemDisplayWnd__AboutToShow_x                             0x773070
#define CItemDisplayWnd__WndNotification_x                         0x774B30
#define CItemDisplayWnd__RequestConvertItem_x                      0x7745B0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7720E0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x772E90

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x857FD0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x779040

// CLabel 
#define CLabel__Draw_x                                             0x77EAA0

// CListWnd
#define CListWnd__CListWnd_x                                       0x936CF0
#define CListWnd__dCListWnd_x                                      0x937010
#define CListWnd__AddColumn_x                                      0x93B4A0
#define CListWnd__AddColumn1_x                                     0x93B4F0
#define CListWnd__AddLine_x                                        0x93B880
#define CListWnd__AddString_x                                      0x93B680
#define CListWnd__CalculateFirstVisibleLine_x                      0x93B260
#define CListWnd__CalculateVSBRange_x                              0x93B040
#define CListWnd__ClearSel_x                                       0x93C060
#define CListWnd__ClearAllSel_x                                    0x93C0C0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x93CAE0
#define CListWnd__Compare_x                                        0x93A970
#define CListWnd__Draw_x                                           0x937140
#define CListWnd__DrawColumnSeparators_x                           0x939940
#define CListWnd__DrawHeader_x                                     0x939DB0
#define CListWnd__DrawItem_x                                       0x93A2B0
#define CListWnd__DrawLine_x                                       0x939AB0
#define CListWnd__DrawSeparator_x                                  0x9399E0
#define CListWnd__EnableLine_x                                     0x939210
#define CListWnd__EnsureVisible_x                                  0x93CA00
#define CListWnd__ExtendSel_x                                      0x93BF90
#define CListWnd__GetColumnTooltip_x                               0x938D50
#define CListWnd__GetColumnMinWidth_x                              0x938DC0
#define CListWnd__GetColumnWidth_x                                 0x938CC0
#define CListWnd__GetCurSel_x                                      0x938650
#define CListWnd__GetItemAtPoint_x                                 0x939490
#define CListWnd__GetItemAtPoint1_x                                0x939500
#define CListWnd__GetItemData_x                                    0x9386D0
#define CListWnd__GetItemHeight_x                                  0x938A90
#define CListWnd__GetItemIcon_x                                    0x938860
#define CListWnd__GetItemRect_x                                    0x939300
#define CListWnd__GetItemText_x                                    0x938710
#define CListWnd__GetSelList_x                                     0x93C110
#define CListWnd__GetSeparatorRect_x                               0x939740
#define CListWnd__InsertLine_x                                     0x93BC70
#define CListWnd__RemoveLine_x                                     0x93BDC0
#define CListWnd__SetColors_x                                      0x93B010
#define CListWnd__SetColumnJustification_x                         0x93AD40
#define CListWnd__SetColumnLabel_x                                 0x93B620
#define CListWnd__SetColumnWidth_x                                 0x93AC60
#define CListWnd__SetCurSel_x                                      0x93BED0
#define CListWnd__SetItemColor_x                                   0x93C6B0
#define CListWnd__SetItemData_x                                    0x93C670
#define CListWnd__SetItemText_x                                    0x93C280
#define CListWnd__ShiftColumnSeparator_x                           0x93AE00
#define CListWnd__Sort_x                                           0x93AAF0
#define CListWnd__ToggleSel_x                                      0x93BF00
#define CListWnd__SetColumnsSizable_x                              0x93AEB0
#define CListWnd__SetItemWnd_x                                     0x93C530
#define CListWnd__GetItemWnd_x                                     0x9388B0
#define CListWnd__SetItemIcon_x                                    0x93C300
#define CListWnd__CalculateCustomWindowPositions_x                 0x93B360
#define CListWnd__SetVScrollPos_x                                  0x93AC40

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x794100
#define CMapViewWnd__GetWorldCoordinates_x                         0x792810
#define CMapViewWnd__HandleLButtonDown_x                           0x78F850

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B44A0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B4D80
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B52B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B8230
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B3010
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BDDF0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B40C0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8BB410
#define CPacketScrambler__hton_x                                   0x8BB400

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x955DE0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9561F0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x955FE0
#define CSidlManager__CreateLabel_x                                0x8164A0
#define CSidlManager__CreateXWndFromTemplate_x                     0x959150
#define CSidlManager__CreateXWndFromTemplate1_x                    0x959330
#define CSidlManager__CreateXWnd_x                                 0x8163D0
#define CSidlManager__CreateHotButtonWnd_x                         0x816990

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9528C0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9527C0
#define CSidlScreenWnd__ConvertToRes_x                             0x97B9F0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x952250
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x951F40
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x952010
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9520E0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x952D60
#define CSidlScreenWnd__EnableIniStorage_x                         0x953230
#define CSidlScreenWnd__GetSidlPiece_x                             0x952F50
#define CSidlScreenWnd__Init1_x                                    0x951B40
#define CSidlScreenWnd__LoadIniInfo_x                              0x953280
#define CSidlScreenWnd__LoadIniListWnd_x                           0x953DC0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x950F50
#define CSidlScreenWnd__StoreIniInfo_x                             0x953940
#define CSidlScreenWnd__StoreIniVis_x                              0x953CA0
#define CSidlScreenWnd__WndNotification_x                          0x952C70
#define CSidlScreenWnd__GetChildItem_x                             0x9531B0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9428D0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1603AE8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x693A60
#define CSkillMgr__GetSkillCap_x                                   0x693C40
#define CSkillMgr__GetNameToken_x                                  0x6931E0
#define CSkillMgr__IsActivatedSkill_x                              0x693320
#define CSkillMgr__IsCombatSkill_x                                 0x693260

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x962B40
#define CSliderWnd__SetValue_x                                     0x9629B0
#define CSliderWnd__SetNumTicks_x                                  0x962A10

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x81C5F0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x96B370
#define CStmlWnd__ParseSTML_x                                      0x96C680
#define CStmlWnd__CalculateHSBRange_x                              0x96C450
#define CStmlWnd__CalculateVSBRange_x                              0x96C3C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x970790
#define CStmlWnd__FastForwardToEndOfTag_x                          0x971420
#define CStmlWnd__ForceParseNow_x                                  0x96B910
#define CStmlWnd__GetNextTagPiece_x                                0x9706F0
#define CStmlWnd__GetSTMLText_x                                    0x509EF0
#define CStmlWnd__GetVisibleText_x                                 0x96B930
#define CStmlWnd__InitializeWindowVariables_x                      0x971270
#define CStmlWnd__MakeStmlColorTag_x                               0x96A9E0
#define CStmlWnd__MakeWndNotificationTag_x                         0x96AA50
#define CStmlWnd__SetSTMLText_x                                    0x969A90
#define CStmlWnd__StripFirstSTMLLines_x                            0x972520
#define CStmlWnd__UpdateHistoryString_x                            0x971630

// CTabWnd 
#define CTabWnd__Draw_x                                            0x968BE0
#define CTabWnd__DrawCurrentPage_x                                 0x969310
#define CTabWnd__DrawTab_x                                         0x969030
#define CTabWnd__GetCurrentPage_x                                  0x9683E0
#define CTabWnd__GetPageInnerRect_x                                0x968620
#define CTabWnd__GetTabInnerRect_x                                 0x968560
#define CTabWnd__GetTabRect_x                                      0x968410
#define CTabWnd__InsertPage_x                                      0x968830
#define CTabWnd__RemovePage_x                                      0x9689A0
#define CTabWnd__SetPage_x                                         0x9686A0
#define CTabWnd__SetPageRect_x                                     0x968B20
#define CTabWnd__UpdatePage_x                                      0x968EF0
#define CTabWnd__GetPageFromTabIndex_x                             0x968F70
#define CTabWnd__GetCurrentTabIndex_x                              0x9683D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x779410
#define CPageWnd__SetTabText_x                                     0x967F20
#define CPageWnd__FlashTab_x                                       0x967F80

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9040

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93F760
#define CTextureFont__GetTextExtent_x                              0x93F920

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C6BD0
#define CHtmlComponentWnd__ValidateUri_x                           0x757C70
#define CHtmlWnd__SetClientCallbacks_x                             0x633C00
#define CHtmlWnd__AddObserver_x                                    0x633C20
#define CHtmlWnd__RemoveObserver_x                                 0x633C80
#define Window__getProgress_x                                      0x870890
#define Window__getStatus_x                                        0x8708B0
#define Window__getURI_x                                           0x8708C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x978800

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x92C9E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9350
#define CXStr__CXStr1_x                                            0x4814B0
#define CXStr__CXStr3_x                                            0x90E7E0
#define CXStr__dCXStr_x                                            0x478700
#define CXStr__operator_equal_x                                    0x90EA10
#define CXStr__operator_equal1_x                                   0x90EA50
#define CXStr__operator_plus_equal1_x                              0x90F4E0
#define CXStr__SetString_x                                         0x9113D0
#define CXStr__operator_char_p_x                                   0x90EF20
#define CXStr__GetChar_x                                           0x910D20
#define CXStr__Delete_x                                            0x9105D0
#define CXStr__GetUnicode_x                                        0x910D90
#define CXStr__GetLength_x                                         0x47D370
#define CXStr__Mid_x                                               0x47D380
#define CXStr__Insert_x                                            0x910DF0
#define CXStr__FindNext_x                                          0x910A40

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x960DC0
#define CXWnd__BringToTop_x                                        0x9460F0
#define CXWnd__Center_x                                            0x945C70
#define CXWnd__ClrFocus_x                                          0x945A80
#define CXWnd__Destroy_x                                           0x945B30
#define CXWnd__DoAllDrawing_x                                      0x942060
#define CXWnd__DrawChildren_x                                      0x942030
#define CXWnd__DrawColoredRect_x                                   0x9424C0
#define CXWnd__DrawTooltip_x                                       0x940B70
#define CXWnd__DrawTooltipAtPoint_x                                0x940C30
#define CXWnd__GetBorderFrame_x                                    0x942320
#define CXWnd__GetChildWndAt_x                                     0x946190
#define CXWnd__GetClientClipRect_x                                 0x944320
#define CXWnd__GetScreenClipRect_x                                 0x9443F0
#define CXWnd__GetScreenRect_x                                     0x9445C0
#define CXWnd__GetRelativeRect_x                                   0x944690
#define CXWnd__GetTooltipRect_x                                    0x942510
#define CXWnd__GetWindowTextA_x                                    0x49CA50
#define CXWnd__IsActive_x                                          0x942C50
#define CXWnd__IsDescendantOf_x                                    0x944FD0
#define CXWnd__IsReallyVisible_x                                   0x945000
#define CXWnd__IsType_x                                            0x946800
#define CXWnd__Move_x                                              0x945080
#define CXWnd__Move1_x                                             0x945130
#define CXWnd__ProcessTransition_x                                 0x945C20
#define CXWnd__Refade_x                                            0x945410
#define CXWnd__Resize_x                                            0x9456A0
#define CXWnd__Right_x                                             0x945EB0
#define CXWnd__SetFocus_x                                          0x945A40
#define CXWnd__SetFont_x                                           0x945AB0
#define CXWnd__SetKeyTooltip_x                                     0x946620
#define CXWnd__SetMouseOver_x                                      0x943480
#define CXWnd__StartFade_x                                         0x944EB0
#define CXWnd__GetChildItem_x                                      0x946300
#define CXWnd__SetParent_x                                         0x944D70
#define CXWnd__Minimize_x                                          0x945710

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x97CA70

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x949050
#define CXWndManager__DrawWindows_x                                0x949070
#define CXWndManager__GetKeyboardFlags_x                           0x94B830
#define CXWndManager__HandleKeyboardMsg_x                          0x94B3E0
#define CXWndManager__RemoveWnd_x                                  0x94BA50
#define CXWndManager__RemovePendingDeletionWnd_x                   0x94BFC0

// CDBStr
#define CDBStr__GetString_x                                        0x543DD0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BCCE0
#define EQ_Character__Cur_HP_x                                     0x4D2F00
#define EQ_Character__Cur_Mana_x                                   0x4DA620
#define EQ_Character__GetCastingTimeModifier_x                     0x4BFD20
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3690
#define EQ_Character__GetFocusRangeModifier_x                      0x4B37E0
#define EQ_Character__GetHPRegen_x                                 0x4E03C0
#define EQ_Character__GetEnduranceRegen_x                          0x4E09C0
#define EQ_Character__GetManaRegen_x                               0x4E0E00
#define EQ_Character__Max_Endurance_x                              0x65A940
#define EQ_Character__Max_HP_x                                     0x4D2D30
#define EQ_Character__Max_Mana_x                                   0x65A740
#define EQ_Character__doCombatAbility_x                            0x65CD70
#define EQ_Character__UseSkill_x                                   0x4E2BF0
#define EQ_Character__GetConLevel_x                                0x653040
#define EQ_Character__IsExpansionFlag_x                            0x5B6360
#define EQ_Character__TotalEffect_x                                0x4C6090
#define EQ_Character__GetPCSpellAffect_x                           0x4C0A70
#define EQ_Character__SpellDuration_x                              0x4C05A0
#define EQ_Character__MySpellDuration_x                            0x4B1FC0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5C80
#define EQ_Character__GetBaseSkill_x                               0x4D6C20
#define EQ_Character__CanUseItem_x                                 0x4DA930

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8DA830

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x670D10

//PcClient
#define PcClient__vftable_x                                        0xB15DD4
#define PcClient__PcClient_x                                       0x6507B0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA8B0
#define CCharacterListWnd__EnterWorld_x                            0x4BA290
#define CCharacterListWnd__Quit_x                                  0x4B9FE0
#define CCharacterListWnd__UpdateList_x                            0x4BA480

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x634DF0
#define EQ_Item__CreateItemTagString_x                             0x8B49E0
#define EQ_Item__IsStackable_x                                     0x8B9620
#define EQ_Item__GetImageNum_x                                     0x8B6520
#define EQ_Item__CreateItemClient_x                                0x634020
#define EQ_Item__GetItemValue_x                                    0x8B7810
#define EQ_Item__ValueSellMerchant_x                               0x8BAFE0
#define EQ_Item__IsKeyRingItem_x                                   0x8B8F20
#define EQ_Item__CanGoInBag_x                                      0x634F10
#define EQ_Item__IsEmpty_x                                         0x8B8A80
#define EQ_Item__GetMaxItemCount_x                                 0x8B7C30
#define EQ_Item__GetHeldItem_x                                     0x8B63F0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8B4310

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x5628F0
#define EQ_LoadingS__Array_x                                       0xC3AC60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65B280
#define EQ_PC__GetAlternateAbilityId_x                             0x8C4500
#define EQ_PC__GetCombatAbility_x                                  0x8C4B70
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C4BE0
#define EQ_PC__GetItemRecastTimer_x                                0x65D2F0
#define EQ_PC__HasLoreItem_x                                       0x653800
#define EQ_PC__AlertInventoryChanged_x                             0x652980
#define EQ_PC__GetPcZoneClient_x                                   0x67F8E0
#define EQ_PC__RemoveMyAffect_x                                    0x660530
#define EQ_PC__GetKeyRingItems_x                                   0x8C5470
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C5200
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C5770

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BC870
#define EQItemList__add_object_x                                   0x5EA420
#define EQItemList__add_item_x                                     0x5BCDD0
#define EQItemList__delete_item_x                                  0x5BCE20
#define EQItemList__FreeItemList_x                                 0x5BCD20

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x540980

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x672590
#define EQPlayer__dEQPlayer_x                                      0x665A70
#define EQPlayer__DoAttack_x                                       0x67A590
#define EQPlayer__EQPlayer_x                                       0x666130
#define EQPlayer__SetNameSpriteState_x                             0x66A390
#define EQPlayer__SetNameSpriteTint_x                              0x66B270
#define PlayerBase__HasProperty_j_x                                0x9AB730
#define EQPlayer__IsTargetable_x                                   0x9ABBD0
#define EQPlayer__CanSee_x                                         0x9ABA30
#define EQPlayer__CanSee1_x                                        0x9ABB00
#define PlayerBase__GetVisibilityLineSegment_x                     0x9AB7F0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67D370
#define PlayerZoneClient__GetLevel_x                               0x67F920
#define PlayerZoneClient__IsValidTeleport_x                        0x5EB590
#define PlayerZoneClient__LegalPlayerRace_x                        0x55B6C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x675400
#define EQPlayerManager__GetSpawnByName_x                          0x6754B0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x675540

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x638460
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6384E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x638520
#define KeypressHandler__ClearCommandStateArray_x                  0x639930
#define KeypressHandler__HandleKeyDown_x                           0x639950
#define KeypressHandler__HandleKeyUp_x                             0x6399F0
#define KeypressHandler__SaveKeymapping_x                          0x639E40

// MapViewMap 
#define MapViewMap__Clear_x                                        0x78FF70
#define MapViewMap__SaveEx_x                                       0x793330
#define MapViewMap__SetZoom_x                                      0x7979F0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D8850

// StringTable 
#define StringTable__getString_x                                   0x8D3740

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6601A0
#define PcZoneClient__RemovePetEffect_x                            0x6607D0
#define PcZoneClient__HasAlternateAbility_x                        0x65A570
#define PcZoneClient__GetCurrentMod_x                              0x4E5CA0
#define PcZoneClient__GetModCap_x                                  0x4E5BA0
#define PcZoneClient__CanEquipItem_x                               0x65AC20
#define PcZoneClient__GetItemByID_x                                0x65D770
#define PcZoneClient__GetItemByItemClass_x                         0x65D8C0
#define PcZoneClient__RemoveBuffEffect_x                           0x6607F0
#define PcZoneClient__BandolierSwap_x                              0x65B840
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65D290

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F0100

//IconCache
#define IconCache__GetIcon_x                                       0x731770

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x729290
#define CContainerMgr__CloseContainer_x                            0x729560
#define CContainerMgr__OpenExperimentContainer_x                   0x729FE0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E8600

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62CFA0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x786590
#define CLootWnd__RequestLootSlot_x                                0x7857C0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5894F0
#define EQ_Spell__SpellAffects_x                                   0x589960
#define EQ_Spell__SpellAffectBase_x                                0x589720
#define EQ_Spell__IsStackable_x                                    0x4CA950
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA740
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7B60
#define EQ_Spell__IsSPAStacking_x                                  0x58A7B0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x589CC0
#define EQ_Spell__IsNoRemove_x                                     0x4CA930
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58A7C0
#define __IsResEffectSpell_x                                       0x4C9AF0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD1E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8E2E30

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82F950
#define CTargetWnd__WndNotification_x                              0x82F190
#define CTargetWnd__RefreshTargetBuffs_x                           0x82F460
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82E300

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x833F80
#define CTaskWnd__ConfirmAbandonTask_x                             0x836BB0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53E3B0
#define CTaskManager__HandleMessage_x                              0x53C850
#define CTaskManager__GetTaskStatus_x                              0x53E460
#define CTaskManager__GetElementDescription_x                      0x53E4E0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x584620
#define EqSoundManager__PlayScriptMp3_x                            0x5848E0
#define EqSoundManager__SoundAssistPlay_x                          0x697A40
#define EqSoundManager__WaveInstancePlay_x                         0x696FB0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52F9D0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x967430
#define CTextureAnimation__Draw_x                                  0x967630

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x9634B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56A4D0
#define CAltAbilityData__GetMercMaxRank_x                          0x56A460
#define CAltAbilityData__GetMaxRank_x                              0x55F800

//CTargetRing
#define CTargetRing__Cast_x                                        0x62B0C0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA720
#define CharacterBase__CreateItemGlobalIndex_x                     0x516BA0
#define CharacterBase__CreateItemIndex_x                           0x6331B0
#define CharacterBase__GetItemPossession_x                         0x502900
#define CharacterBase__GetItemByGlobalIndex_x                      0x8EB4C0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8EB520
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x710290
#define CCastSpellWnd__IsBardSongPlaying_x                         0x710AC0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x710B70

//messages
#define msg_spell_worn_off_x                                       0x5AE390
#define msg_new_text_x                                             0x5A2D70
#define __msgTokenTextParam_x                                      0x5B0630
#define msgTokenText_x                                             0x5B0880

//SpellManager
#define SpellManager__vftable_x                                    0xAFE168
#define SpellManager__SpellManager_x                               0x69AD70
#define Spellmanager__LoadTextSpells_x                             0x69B660
#define SpellManager__GetSpellByGroupAndRank_x                     0x69AF40

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9AF600

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5171F0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B4800
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64BEB0
#define ItemGlobalIndex__IsValidIndex_x                            0x517250

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8E37D0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8E3A50

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77EDE0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72D980
#define CCursorAttachment__AttachToCursor1_x                       0x72D9C0
#define CCursorAttachment__Deactivate_x                            0x72E9B0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x95A180
#define CSidlManagerBase__CreatePageWnd_x                          0x959980
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x955C00
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x955B90

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9770B0
#define CEQSuiteTextureLoader__GetTexture_x                        0x976D70

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x514170
#define CFindItemWnd__WndNotification_x                            0x514C50
#define CFindItemWnd__Update_x                                     0x5157C0
#define CFindItemWnd__PickupSelectedItem_x                         0x5139B0

//IString
#define IString__Append_x                                          0x504130

//Camera
#define CDisplay__cameraType_x                                     0xE14328
#define EverQuest__Cameras_x                                       0xECF5C4

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51C880
#define LootFiltersManager__GetItemFilterData_x                    0x51C190
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51C1C0
#define LootFiltersManager__SetItemLootFilter_x                    0x51C3E0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D6430

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B5140
#define CResolutionHandler__GetWindowedStyle_x                     0x692650

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x725F40

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F8CC0
#define CDistillerInfo__Instance_x                                 0x8F8C60

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x745070
#define CGroupWnd__UpdateDisplay_x                                 0x7443C0

//ItemBase
#define ItemBase__IsLore_x                                         0x8B8FD0
#define ItemBase__IsLoreEquipped_x                                 0x8B9050

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EA380
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EA4C0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EA520

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x687FE0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68B980

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50A570

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F6B70
#define FactionManagerClient__HandleFactionMessage_x               0x4F71E0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F77E0
#define FactionManagerClient__GetMaxFaction_x                      0x4F77FF
#define FactionManagerClient__GetMinFaction_x                      0x4F77B0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x5028D0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x93E780

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BD30

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x502B40

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x569970

//CTargetManager
#define CTargetManager__Get_x                                      0x69E5C0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x687FE0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8E00

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BCCC0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF6CC58

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6D9CA0
#define CAAWnd__UpdateSelected_x                                   0x6D6510
#define CAAWnd__Update_x                                           0x6D8FC0

//CXRect
#define CXRect__operator_and_x                                     0x73C160

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
