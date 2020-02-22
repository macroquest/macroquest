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
#define __ExpectedVersionDate                                     "Feb 13 2020"
#define __ExpectedVersionTime                                     "15:45:01"
#define __ActualVersionDate_x                                      0xB17BC0
#define __ActualVersionTime_x                                      0xB17BB4
#define __ActualVersionBuild_x                                     0xB038E4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x63AA90
#define __MemChecker1_x                                            0x90DD80
#define __MemChecker2_x                                            0x6C9550
#define __MemChecker3_x                                            0x6C94A0
#define __MemChecker4_x                                            0x864360
#define __EncryptPad0_x                                            0xC4F3F0
#define __EncryptPad1_x                                            0xCAD658
#define __EncryptPad2_x                                            0xC5FC88
#define __EncryptPad3_x                                            0xC5F888
#define __EncryptPad4_x                                            0xC9DC08
#define __EncryptPad5_x                                            0xF6E814
#define __AC1_x                                                    0x8212C6
#define __AC2_x                                                    0x5F480F
#define __AC3_x                                                    0x5FBF0F
#define __AC4_x                                                    0x5FFEE0
#define __AC5_x                                                    0x6061EF
#define __AC6_x                                                    0x60A6E6
#define __AC7_x                                                    0x5F4280
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x6EEC8

// Direct Input
#define DI8__Main_x                                                0xF6E834
#define DI8__Keyboard_x                                            0xF6E838
#define DI8__Mouse_x                                               0xF6E854
#define DI8__Mouse_Copy_x                                          0xEC9EBC
#define DI8__Mouse_Check_x                                         0xF6F300
#define __AutoSkillArray_x                                         0xECADD4
#define __Attack_x                                                 0xF68BFB
#define __Autofire_x                                               0xF68BFC
#define __BindList_x                                               0xC3DE20
#define g_eqCommandStates_x                                        0xC3EBA0
#define __Clicks_x                                                 0xEC9F74
#define __CommandList_x                                            0xC3F760
#define __CurrentMapLabel_x                                        0xF816C4
#define __CurrentSocial_x                                          0xC277CC
#define __DoAbilityList_x                                          0xF0071C
#define __do_loot_x                                                0x5C0280
#define __DrawHandler_x                                            0x1600A40
#define __GroupCount_x                                             0xEC49D2
#define __Guilds_x                                                 0xEC8DD8
#define __gWorld_x                                                 0xEC4C20
#define __HWnd_x                                                   0xF6F2E0
#define __heqmain_x                                                0xF71794
#define __InChatMode_x                                             0xEC9EA4
#define __LastTell_x                                               0xECBE18
#define __LMouseHeldTime_x                                         0xEC9FE0
#define __Mouse_x                                                  0xF6E820
#define __MouseLook_x                                              0xEC9F3A
#define __MouseEventTime_x                                         0xF696DC
#define __gpbCommandEvent_x                                        0xEC4C28
#define __NetStatusToggle_x                                        0xEC9F3D
#define __PCNames_x                                                0xECB3C4
#define __RangeAttackReady_x                                       0xECB0B8
#define __RMouseHeldTime_x                                         0xEC9FDC
#define __RunWalkState_x                                           0xEC9EA8
#define __ScreenMode_x                                             0xE10638
#define __ScreenX_x                                                0xEC9E5C
#define __ScreenY_x                                                0xEC9E58
#define __ScreenXMax_x                                             0xEC9E60
#define __ScreenYMax_x                                             0xEC9E64
#define __ServerHost_x                                             0xEC4E5B
#define __ServerName_x                                             0xF006DC
#define __ShiftKeyDown_x                                           0xECA534
#define __ShowNames_x                                              0xECB274
#define EverQuestInfo__bSocialChanged_x                            0xF00764
#define __Socials_x                                                0xF007DC
#define __SubscriptionType_x                                       0xFC5BD0
#define __TargetAggroHolder_x                                      0xF84078
#define __ZoneType_x                                               0xECA338
#define __GroupAggro_x                                             0xF840B8
#define __LoginName_x                                              0xF6EF8C
#define __Inviter_x                                                0xF68B78
#define __AttackOnAssist_x                                         0xECB230
#define __UseTellWindows_x                                         0xECB560
#define __gfMaxZoomCameraDistance_x                                0xB0D520
#define __gfMaxCameraDistance_x                                    0xB398DC
#define __pulAutoRun_x                                             0xEC9F58
#define __pulForward_x                                             0xECB598
#define __pulBackward_x                                            0xECB59C
#define __pulTurnRight_x                                           0xECB5A0
#define __pulTurnLeft_x                                            0xECB5A4
#define __pulStrafeLeft_x                                          0xECB5A8
#define __pulStrafeRight_x                                         0xECB5AC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEC5170
#define instEQZoneInfo_x                                           0xECA130
#define pinstActiveBanker_x                                        0xEC4D08
#define pinstActiveCorpse_x                                        0xEC4D00
#define pinstActiveGMaster_x                                       0xEC4D04
#define pinstActiveMerchant_x                                      0xEC4CFC
#define pinstAltAdvManager_x                                       0xE113A8
#define pinstBandageTarget_x                                       0xEC4D18
#define pinstCamActor_x                                            0xE10628
#define pinstCDBStr_x                                              0xE100C4
#define pinstCDisplay_x                                            0xEC4878
#define pinstCEverQuest_x                                          0xF6E850
#define pinstEverQuestInfo_x                                       0xEC9E50
#define pinstCharData_x                                            0xEC4C10
#define pinstCharSpawn_x                                           0xEC4D50
#define pinstControlledMissile_x                                   0xEC2864
#define pinstControlledPlayer_x                                    0xEC4D50
#define pinstCResolutionHandler_x                                  0x1600C70
#define pinstCSidlManager_x                                        0x15FFC08
#define pinstCXWndManager_x                                        0x15FFC04
#define instDynamicZone_x                                          0xEC8CB0
#define pinstDZMember_x                                            0xEC8DC0
#define pinstDZTimerInfo_x                                         0xEC8DC4
#define pinstEqLogin_x                                             0xF6E8D8
#define instEQMisc_x                                               0xE10008
#define pinstEQSoundManager_x                                      0xE12378
#define pinstEQSpellStrings_x                                      0xCD29E8
#define instExpeditionLeader_x                                     0xEC8CFA
#define instExpeditionName_x                                       0xEC8D3A
#define pinstGroup_x                                               0xEC49CE
#define pinstImeManager_x                                          0x15FFC00
#define pinstLocalPlayer_x                                         0xEC4CF8
#define pinstMercenaryData_x                                       0xF6B1D4
#define pinstMercenaryStats_x                                      0xF841C4
#define pinstModelPlayer_x                                         0xEC4D10
#define pinstPCData_x                                              0xEC4C10
#define pinstSkillMgr_x                                            0xF6D338
#define pinstSpawnManager_x                                        0xF6BDE0
#define pinstSpellManager_x                                        0xF6D578
#define pinstSpellSets_x                                           0xF61824
#define pinstStringTable_x                                         0xEC4C1C
#define pinstSwitchManager_x                                       0xEC2710
#define pinstTarget_x                                              0xEC4D4C
#define pinstTargetObject_x                                        0xEC4F64
#define pinstTargetSwitch_x                                        0xEC286C
#define pinstTaskMember_x                                          0xE0FE98
#define pinstTrackTarget_x                                         0xEC4D54
#define pinstTradeTarget_x                                         0xEC4D0C
#define instTributeActive_x                                        0xE10029
#define pinstViewActor_x                                           0xE10624
#define pinstWorldData_x                                           0xEC4874
#define pinstZoneAddr_x                                            0xECA3D0
#define pinstPlayerPath_x                                          0xF6BE78
#define pinstTargetIndicator_x                                     0xF6D7E0
#define EQObject_Top_x                                             0xEC4CF4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE108F4
#define pinstCAchievementsWnd_x                                    0xE10964
#define pinstCActionsWnd_x                                         0xE1091C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE10630
#define pinstCAdvancedLootWnd_x                                    0xE1017C
#define pinstCAdventureLeaderboardWnd_x                            0xF7AE98
#define pinstCAdventureRequestWnd_x                                0xF7AF48
#define pinstCAdventureStatsWnd_x                                  0xF7AFF8
#define pinstCAggroMeterWnd_x                                      0xE10644
#define pinstCAlarmWnd_x                                           0xE109BC
#define pinstCAlertHistoryWnd_x                                    0xE10690
#define pinstCAlertStackWnd_x                                      0xE109F4
#define pinstCAlertWnd_x                                           0xE101E4
#define pinstCAltStorageWnd_x                                      0xF7B358
#define pinstCAudioTriggersWindow_x                                0xCC4D18
#define pinstCAuraWnd_x                                            0xE105F0
#define pinstCAvaZoneWnd_x                                         0xE10950
#define pinstCBandolierWnd_x                                       0xE10620
#define pinstCBankWnd_x                                            0xE1068C
#define pinstCBarterMerchantWnd_x                                  0xF7C598
#define pinstCBarterSearchWnd_x                                    0xF7C648
#define pinstCBarterWnd_x                                          0xF7C6F8
#define pinstCBazaarConfirmationWnd_x                              0xE10998
#define pinstCBazaarSearchWnd_x                                    0xE108F8
#define pinstCBazaarWnd_x                                          0xE1099C
#define pinstCBlockedBuffWnd_x                                     0xE105FC
#define pinstCBlockedPetBuffWnd_x                                  0xE10618
#define pinstCBodyTintWnd_x                                        0xE10928
#define pinstCBookWnd_x                                            0xE10678
#define pinstCBreathWnd_x                                          0xE1090C
#define pinstCBuffWindowNORMAL_x                                   0xE10160
#define pinstCBuffWindowSHORT_x                                    0xE10168
#define pinstCBugReportWnd_x                                       0xE10680
#define pinstCButtonWnd_x                                          0x15FFE70
#define pinstCCastingWnd_x                                         0xE10668
#define pinstCCastSpellWnd_x                                       0xE10900
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE10944
#define pinstCChatWindowManager_x                                  0xF7D1B8
#define pinstCClaimWnd_x                                           0xF7D310
#define pinstCColorPickerWnd_x                                     0xE106C4
#define pinstCCombatAbilityWnd_x                                   0xE109B0
#define pinstCCombatSkillsSelectWnd_x                              0xE10958
#define pinstCCompassWnd_x                                         0xE10920
#define pinstCConfirmationDialog_x                                 0xF82210
#define pinstCContainerMgr_x                                       0xE10940
#define pinstCContextMenuManager_x                                 0x15FFBC0
#define pinstCCursorAttachment_x                                   0xE10650
#define pinstCDynamicZoneWnd_x                                     0xF7D8D8
#define pinstCEditLabelWnd_x                                       0xE109F0
#define pinstCEQMainWnd_x                                          0xF7DB20
#define pinstCEventCalendarWnd_x                                   0xE106D8
#define pinstCExtendedTargetWnd_x                                  0xE10610
#define pinstCFacePick_x                                           0xE10974
#define pinstCFactionWnd_x                                         0xE10988
#define pinstCFellowshipWnd_x                                      0xF7DD20
#define pinstCFileSelectionWnd_x                                   0xE106BC
#define pinstCFindItemWnd_x                                        0xE10970
#define pinstCFindLocationWnd_x                                    0xF7DE78
#define pinstCFriendsWnd_x                                         0xE1096C
#define pinstCGemsGameWnd_x                                        0xE10984
#define pinstCGiveWnd_x                                            0xE109C4
#define pinstCGroupSearchFiltersWnd_x                              0xE1066C
#define pinstCGroupSearchWnd_x                                     0xF7E270
#define pinstCGroupWnd_x                                           0xF7E320
#define pinstCGuildBankWnd_x                                       0xECB214
#define pinstCGuildCreationWnd_x                                   0xF7E480
#define pinstCGuildMgmtWnd_x                                       0xF7E530
#define pinstCharacterCreation_x                                   0xE10960
#define pinstCHelpWnd_x                                            0xE109B8
#define pinstCHeritageSelectionWnd_x                               0xE1098C
#define pinstCHotButtonWnd_x                                       0xF80688
#define pinstCHotButtonWnd1_x                                      0xF80688
#define pinstCHotButtonWnd2_x                                      0xF8068C
#define pinstCHotButtonWnd3_x                                      0xF80690
#define pinstCHotButtonWnd4_x                                      0xF80694
#define pinstCIconSelectionWnd_x                                   0xE10648
#define pinstCInspectWnd_x                                         0xE1061C
#define pinstCInventoryWnd_x                                       0xE105F8
#define pinstCInvSlotMgr_x                                         0xE10908
#define pinstCItemDisplayManager_x                                 0xF80C18
#define pinstCItemExpTransferWnd_x                                 0xF80D48
#define pinstCItemOverflowWnd_x                                    0xE10904
#define pinstCJournalCatWnd_x                                      0xE108E0
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE1069C
#define pinstCKeyRingWnd_x                                         0xE10660
#define pinstCLargeDialogWnd_x                                     0xF82E90
#define pinstCLayoutCopyWnd_x                                      0xF81098
#define pinstCLFGuildWnd_x                                         0xF81148
#define pinstCLoadskinWnd_x                                        0xE10994
#define pinstCLootFiltersCopyWnd_x                                 0xCE13A0
#define pinstCLootFiltersWnd_x                                     0xE109F8
#define pinstCLootSettingsWnd_x                                    0xE105F4
#define pinstCLootWnd_x                                            0xE108E4
#define pinstCMailAddressBookWnd_x                                 0xE10910
#define pinstCMailCompositionWnd_x                                 0xE108F0
#define pinstCMailIgnoreListWnd_x                                  0xE10914
#define pinstCMailWnd_x                                            0xE106CC
#define pinstCManageLootWnd_x                                      0xE11858
#define pinstCMapToolbarWnd_x                                      0xE109C0
#define pinstCMapViewWnd_x                                         0xE10990
#define pinstCMarketplaceWnd_x                                     0xE10164
#define pinstCMerchantWnd_x                                        0xE108EC
#define pinstCMIZoneSelectWnd_x                                    0xF81980
#define pinstCMusicPlayerWnd_x                                     0xE10694
#define pinstCNameChangeMercWnd_x                                  0xE1097C
#define pinstCNameChangePetWnd_x                                   0xE10968
#define pinstCNameChangeWnd_x                                      0xE109A4
#define pinstCNoteWnd_x                                            0xE109A8
#define pinstCObjectPreviewWnd_x                                   0xE105EC
#define pinstCOptionsWnd_x                                         0xE109B4
#define pinstCPetInfoWnd_x                                         0xE106AC
#define pinstCPetitionQWnd_x                                       0xE10948
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE10930
#define pinstCPlayerWnd_x                                          0xE106B8
#define pinstCPopupWndManager_x                                    0xF82210
#define pinstCProgressionSelectionWnd_x                            0xF822C0
#define pinstCPurchaseGroupWnd_x                                   0xE10654
#define pinstCPurchaseWnd_x                                        0xE10614
#define pinstCPvPLeaderboardWnd_x                                  0xF82370
#define pinstCPvPStatsWnd_x                                        0xF82420
#define pinstCQuantityWnd_x                                        0xE106A0
#define pinstCRaceChangeWnd_x                                      0xE109EC
#define pinstCRaidOptionsWnd_x                                     0xE10674
#define pinstCRaidWnd_x                                            0xE108E8
#define pinstCRealEstateItemsWnd_x                                 0xE1095C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE108FC
#define pinstCRealEstateManageWnd_x                                0xE10664
#define pinstCRealEstateNeighborhoodWnd_x                          0xE10688
#define pinstCRealEstatePlotSearchWnd_x                            0xE10698
#define pinstCRealEstatePurchaseWnd_x                              0xE106B4
#define pinstCRespawnWnd_x                                         0xE1060C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE10954
#define pinstCSendMoneyWnd_x                                       0xE109E8
#define pinstCServerListWnd_x                                      0xE106C8
#define pinstCSkillsSelectWnd_x                                    0xE10938
#define pinstCSkillsWnd_x                                          0xE10924
#define pinstCSocialEditWnd_x                                      0xE1065C
#define pinstCSocialWnd_x                                          0xE10978
#define pinstCSpellBookWnd_x                                       0xE109AC
#define pinstCStoryWnd_x                                           0xE10918
#define pinstCTargetOfTargetWnd_x                                  0xF84248
#define pinstCTargetWnd_x                                          0xE10608
#define pinstCTaskOverlayWnd_x                                     0xE1064C
#define pinstCTaskSelectWnd_x                                      0xF843A0
#define pinstCTaskManager_x                                        0xCE1CE0
#define pinstCTaskTemplateSelectWnd_x                              0xF84450
#define pinstCTaskWnd_x                                            0xF84500
#define pinstCTextEntryWnd_x                                       0xE10670
#define pinstCTimeLeftWnd_x                                        0xE1092C
#define pinstCTipWndCONTEXT_x                                      0xF84704
#define pinstCTipWndOFDAY_x                                        0xF84700
#define pinstCTitleWnd_x                                           0xF847B0
#define pinstCTrackingWnd_x                                        0xE10600
#define pinstCTradeskillWnd_x                                      0xF84918
#define pinstCTradeWnd_x                                           0xE10934
#define pinstCTrainWnd_x                                           0xE106D4
#define pinstCTributeBenefitWnd_x                                  0xF84B18
#define pinstCTributeMasterWnd_x                                   0xF84BC8
#define pinstCTributeTrophyWnd_x                                   0xF84C78
#define pinstCVideoModesWnd_x                                      0xE106D0
#define pinstCVoiceMacroWnd_x                                      0xF6DF48
#define pinstCVoteResultsWnd_x                                     0xE1094C
#define pinstCVoteWnd_x                                            0xE1093C
#define pinstCWebManager_x                                         0xF6E5C4
#define pinstCZoneGuideWnd_x                                       0xE10658
#define pinstCZonePathWnd_x                                        0xE1067C

#define pinstEQSuiteTextureLoader_x                                0xCAF130
#define pinstItemIconCache_x                                       0xF7DAD8
#define pinstLootFiltersManager_x                                  0xCE1450
#define pinstRewardSelectionWnd_x                                  0xF82B68

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5BB6E0
#define __CastRay2_x                                               0x5BB730
#define __ConvertItemTags_x                                        0x5D7280
#define __CleanItemTags_x                                          0x47D210
#define __DoesFileExist_x                                          0x910E00
#define __EQGetTime_x                                              0x90D850
#define __ExecuteCmd_x                                             0x5B3F00
#define __FixHeading_x                                             0x9A9650
#define __GameLoop_x                                               0x6C8720
#define __get_bearing_x                                            0x5BB250
#define __get_melee_range_x                                        0x5BB920
#define __GetAnimationCache_x                                      0x72DCA0
#define __GetGaugeValueFromEQ_x                                    0x81F770
#define __GetLabelFromEQ_x                                         0x821250
#define __GetXTargetType_x                                         0x9AB0A0
#define __HandleMouseWheel_x                                       0x6C9600
#define __HeadingDiff_x                                            0x9A96C0
#define __HelpPath_x                                               0xF692CC
#define __LoadFrontEnd_x                                           0x6C5A40
#define __NewUIINI_x                                               0x81F440
#define __ProcessGameEvents_x                                      0x61BF80
#define __ProcessMouseEvent_x                                      0x61B740
#define __SaveColors_x                                             0x5593C0
#define __STMLToText_x                                             0x94CA00
#define __ToggleKeyRingItem_x                                      0x51A1D0
#define CMemoryMappedFile__SetFile_x                               0xA98990
#define CrashDetected_x                                            0x6C74E0
#define DrawNetStatus_x                                            0x647E00
#define Expansion_HoT_x                                            0xECB21C
#define Teleport_Table_Size_x                                      0xEC4CB4
#define Teleport_Table_x                                           0xEC2870
#define Util__FastTime_x                                           0x90D420

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4904B0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4993D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4991A0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A50
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492EA0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x561090
#define AltAdvManager__IsAbilityReady_x                            0x55FE30
#define AltAdvManager__GetAAById_x                                 0x5601C0
#define AltAdvManager__CanTrainAbility_x                           0x560230
#define AltAdvManager__CanSeeAbility_x                             0x560590

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA160
#define CharacterZoneClient__HasSkill_x                            0x4D4FE0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6700
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE890
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAEC0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9080
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9160
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9240
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2F90
#define CharacterZoneClient__BardCastBard_x                        0x4C5AF0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAF90
#define CharacterZoneClient__GetEffect_x                           0x4BAE00
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3FE0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C40B0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4100
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4250
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4420
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2D40
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7660
#define CharacterZoneClient__FindItemByRecord_x                    0x4D70E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6EF240
#define CBankWnd__WndNotification_x                                0x6EF020

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6FCB90

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x62A7D0
#define CButtonWnd__CButtonWnd_x                                   0x948DE0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x71CD00
#define CChatManager__InitContextMenu_x                            0x715E30
#define CChatManager__FreeChatWindow_x                             0x71B840
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8610
#define CChatManager__SetLockedActiveChatWindow_x                  0x71C980
#define CChatManager__CreateChatWindow_x                           0x71BE80

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8720

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x95D3F0
#define CContextMenu__dCContextMenu_x                              0x95D630
#define CContextMenu__AddMenuItem_x                                0x95D640
#define CContextMenu__RemoveMenuItem_x                             0x95D950
#define CContextMenu__RemoveAllMenuItems_x                         0x95D970
#define CContextMenu__CheckMenuItem_x                              0x95D9F0
#define CContextMenu__SetMenuItem_x                                0x95D870
#define CContextMenu__AddSeparator_x                               0x95D7D0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x95DF90
#define CContextMenuManager__RemoveMenu_x                          0x95E000
#define CContextMenuManager__PopupMenu_x                           0x95E0C0
#define CContextMenuManager__Flush_x                               0x95DF30
#define CContextMenuManager__GetMenu_x                             0x49B600
#define CContextMenuManager__CreateDefaultMenu_x                   0x7284A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8E8CA0
#define CChatService__GetFriendName_x                              0x8E8CB0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x71D570
#define CChatWindow__Clear_x                                       0x71E840
#define CChatWindow__WndNotification_x                             0x71EFD0
#define CChatWindow__AddHistory_x                                  0x71E100

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x95A840
#define CComboWnd__Draw_x                                          0x959D30
#define CComboWnd__GetCurChoice_x                                  0x95A680
#define CComboWnd__GetListRect_x                                   0x95A1E0
#define CComboWnd__GetTextRect_x                                   0x95A8B0
#define CComboWnd__InsertChoice_x                                  0x95A370
#define CComboWnd__SetColors_x                                     0x95A340
#define CComboWnd__SetChoice_x                                     0x95A650
#define CComboWnd__GetItemCount_x                                  0x95A690
#define CComboWnd__GetCurChoiceText_x                              0x95A6D0
#define CComboWnd__GetChoiceText_x                                 0x95A6A0
#define CComboWnd__InsertChoiceAtIndex_x                           0x95A410

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x725E90
#define CContainerWnd__vftable_x                                   0xB20DA4
#define CContainerWnd__SetContainer_x                              0x7273F0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x553D90
#define CDisplay__PreZoneMainUI_x                                  0x553DA0
#define CDisplay__CleanGameUI_x                                    0x559180
#define CDisplay__GetClickedActor_x                                0x54C090
#define CDisplay__GetUserDefinedColor_x                            0x5446F0
#define CDisplay__GetWorldFilePath_x                               0x54DB00
#define CDisplay__is3dON_x                                         0x548CF0
#define CDisplay__ReloadUI_x                                       0x553210
#define CDisplay__WriteTextHD2_x                                   0x548AE0
#define CDisplay__TrueDistance_x                                   0x54F7C0
#define CDisplay__SetViewActor_x                                   0x54B9B0
#define CDisplay__GetFloorHeight_x                                 0x548DB0
#define CDisplay__SetRenderWindow_x                                0x547710
#define CDisplay__ToggleScreenshotMode_x                           0x54B480

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x97D0C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x960960
#define CEditWnd__EnsureCaretVisible_x                             0x962B30
#define CEditWnd__GetCaretPt_x                                     0x961AE0
#define CEditWnd__GetCharIndexPt_x                                 0x961890
#define CEditWnd__GetDisplayString_x                               0x961730
#define CEditWnd__GetHorzOffset_x                                  0x95FF90
#define CEditWnd__GetLineForPrintableChar_x                        0x962A30
#define CEditWnd__GetSelStartPt_x                                  0x961B40
#define CEditWnd__GetSTMLSafeText_x                                0x961550
#define CEditWnd__PointFromPrintableChar_x                         0x962660
#define CEditWnd__SelectableCharFromPoint_x                        0x9627D0
#define CEditWnd__SetEditable_x                                    0x961C10
#define CEditWnd__SetWindowTextA_x                                 0x9612D0
#define CEditWnd__ReplaceSelection_x                               0x9622D0
#define CEditWnd__ReplaceSelection1_x                              0x962250

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x609BC0
#define CEverQuest__ClickedPlayer_x                                0x5FBCF0
#define CEverQuest__CreateTargetIndicator_x                        0x619220
#define CEverQuest__DeleteTargetIndicator_x                        0x6192B0
#define CEverQuest__DoTellWindow_x                                 0x4E8800
#define CEverQuest__OutputTextToLog_x                              0x4E8AD0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F0D30
#define CEverQuest__dsp_chat_x                                     0x4E8E60
#define CEverQuest__trimName_x                                     0x615420
#define CEverQuest__Emote_x                                        0x60A420
#define CEverQuest__EnterZone_x                                    0x6044C0
#define CEverQuest__GetBodyTypeDesc_x                              0x60ECE0
#define CEverQuest__GetClassDesc_x                                 0x60F320
#define CEverQuest__GetClassThreeLetterCode_x                      0x60F920
#define CEverQuest__GetDeityDesc_x                                 0x617A70
#define CEverQuest__GetLangDesc_x                                  0x60FAE0
#define CEverQuest__GetRaceDesc_x                                  0x60F300
#define CEverQuest__InterpretCmd_x                                 0x618040
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F4F30
#define CEverQuest__LMouseUp_x                                     0x5F32C0
#define CEverQuest__RightClickedOnPlayer_x                         0x5F5810
#define CEverQuest__RMouseUp_x                                     0x5F4240
#define CEverQuest__SetGameState_x                                 0x5F0AC0
#define CEverQuest__UPCNotificationFlush_x                         0x615320
#define CEverQuest__IssuePetCommand_x                              0x610EE0
#define CEverQuest__ReportSuccessfulHit_x                          0x60B770

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x737F60
#define CGaugeWnd__CalcLinesFillRect_x                             0x737FC0
#define CGaugeWnd__Draw_x                                          0x7375E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF6E0
#define CGuild__GetGuildName_x                                     0x4AE710
#define CGuild__GetGuildIndex_x                                    0x4AEB50

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x752120

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62AB90

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x75F0F0
#define CInvSlotMgr__MoveItem_x                                    0x75DE50
#define CInvSlotMgr__SelectSlot_x                                  0x75F1C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x75C6D0
#define CInvSlot__SliderComplete_x                                 0x75A430
#define CInvSlot__GetItemBase_x                                    0x759DC0
#define CInvSlot__UpdateItem_x                                     0x759F30

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x760C40
#define CInvSlotWnd__CInvSlotWnd_x                                 0x75FDE0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7607C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x81AAE0
#define CItemDisplayWnd__UpdateStrings_x                           0x76F330
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7690A0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7695A0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x76F930
#define CItemDisplayWnd__AboutToShow_x                             0x76EF70
#define CItemDisplayWnd__WndNotification_x                         0x770A00
#define CItemDisplayWnd__RequestConvertItem_x                      0x7704D0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x76DFD0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x76ED90

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x853570

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x774EF0

// CLabel 
#define CLabel__Draw_x                                             0x77A930

// CListWnd
#define CListWnd__CListWnd_x                                       0x932EE0
#define CListWnd__dCListWnd_x                                      0x933200
#define CListWnd__AddColumn_x                                      0x937690
#define CListWnd__AddColumn1_x                                     0x9376E0
#define CListWnd__AddLine_x                                        0x937A70
#define CListWnd__AddString_x                                      0x937870
#define CListWnd__CalculateFirstVisibleLine_x                      0x937450
#define CListWnd__CalculateVSBRange_x                              0x937230
#define CListWnd__ClearSel_x                                       0x938250
#define CListWnd__ClearAllSel_x                                    0x9382B0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x938CD0
#define CListWnd__Compare_x                                        0x936B60
#define CListWnd__Draw_x                                           0x933330
#define CListWnd__DrawColumnSeparators_x                           0x935B30
#define CListWnd__DrawHeader_x                                     0x935FA0
#define CListWnd__DrawItem_x                                       0x9364A0
#define CListWnd__DrawLine_x                                       0x935CA0
#define CListWnd__DrawSeparator_x                                  0x935BD0
#define CListWnd__EnableLine_x                                     0x935400
#define CListWnd__EnsureVisible_x                                  0x938BF0
#define CListWnd__ExtendSel_x                                      0x938180
#define CListWnd__GetColumnTooltip_x                               0x934F40
#define CListWnd__GetColumnMinWidth_x                              0x934FB0
#define CListWnd__GetColumnWidth_x                                 0x934EB0
#define CListWnd__GetCurSel_x                                      0x934840
#define CListWnd__GetItemAtPoint_x                                 0x935680
#define CListWnd__GetItemAtPoint1_x                                0x9356F0
#define CListWnd__GetItemData_x                                    0x9348C0
#define CListWnd__GetItemHeight_x                                  0x934C80
#define CListWnd__GetItemIcon_x                                    0x934A50
#define CListWnd__GetItemRect_x                                    0x9354F0
#define CListWnd__GetItemText_x                                    0x934900
#define CListWnd__GetSelList_x                                     0x938300
#define CListWnd__GetSeparatorRect_x                               0x935930
#define CListWnd__InsertLine_x                                     0x937E60
#define CListWnd__RemoveLine_x                                     0x937FB0
#define CListWnd__SetColors_x                                      0x937200
#define CListWnd__SetColumnJustification_x                         0x936F30
#define CListWnd__SetColumnLabel_x                                 0x937810
#define CListWnd__SetColumnWidth_x                                 0x936E50
#define CListWnd__SetCurSel_x                                      0x9380C0
#define CListWnd__SetItemColor_x                                   0x9388A0
#define CListWnd__SetItemData_x                                    0x938860
#define CListWnd__SetItemText_x                                    0x938470
#define CListWnd__ShiftColumnSeparator_x                           0x936FF0
#define CListWnd__Sort_x                                           0x936CE0
#define CListWnd__ToggleSel_x                                      0x9380F0
#define CListWnd__SetColumnsSizable_x                              0x9370A0
#define CListWnd__SetItemWnd_x                                     0x938720
#define CListWnd__GetItemWnd_x                                     0x934AA0
#define CListWnd__SetItemIcon_x                                    0x9384F0
#define CListWnd__CalculateCustomWindowPositions_x                 0x937550
#define CListWnd__SetVScrollPos_x                                  0x936E30

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x790150
#define CMapViewWnd__GetWorldCoordinates_x                         0x78E860
#define CMapViewWnd__HandleLButtonDown_x                           0x78B8A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B0280
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B0B60
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B1080
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B4000
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7AEDF0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7B9BB0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7AFEA0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8B6AF0
#define CPacketScrambler__hton_x                                   0x8B6AE0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x952070
#define CSidlManager__FindScreenPieceTemplate_x                    0x952480
#define CSidlManager__FindScreenPieceTemplate1_x                   0x952270
#define CSidlManager__CreateLabel_x                                0x811D30
#define CSidlManager__CreateXWndFromTemplate_x                     0x9553E0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9555C0
#define CSidlManager__CreateXWnd_x                                 0x811C60
#define CSidlManager__CreateHotButtonWnd_x                         0x812230

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x94EB30
#define CSidlScreenWnd__CalculateVSBRange_x                        0x94EA30
#define CSidlScreenWnd__ConvertToRes_x                             0x977BB0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x94E4C0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x94E1B0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x94E280
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x94E350
#define CSidlScreenWnd__DrawSidlPiece_x                            0x94EFD0
#define CSidlScreenWnd__EnableIniStorage_x                         0x94F4A0
#define CSidlScreenWnd__GetSidlPiece_x                             0x94F1C0
#define CSidlScreenWnd__Init1_x                                    0x94DDB0
#define CSidlScreenWnd__LoadIniInfo_x                              0x94F4F0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x950050
#define CSidlScreenWnd__LoadSidlScreen_x                           0x94D1B0
#define CSidlScreenWnd__StoreIniInfo_x                             0x94FBC0
#define CSidlScreenWnd__StoreIniVis_x                              0x94FF30
#define CSidlScreenWnd__WndNotification_x                          0x94EEE0
#define CSidlScreenWnd__GetChildItem_x                             0x94F420
#define CSidlScreenWnd__HandleLButtonUp_x                          0x93EAC0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FFA90

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x68F890
#define CSkillMgr__GetSkillCap_x                                   0x68FA70
#define CSkillMgr__GetNameToken_x                                  0x68F010
#define CSkillMgr__IsActivatedSkill_x                              0x68F150
#define CSkillMgr__IsCombatSkill_x                                 0x68F090

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x95ED70
#define CSliderWnd__SetValue_x                                     0x95EBE0
#define CSliderWnd__SetNumTicks_x                                  0x95EC40

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x817E20

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x967590
#define CStmlWnd__ParseSTML_x                                      0x9688E0
#define CStmlWnd__CalculateHSBRange_x                              0x9686B0
#define CStmlWnd__CalculateVSBRange_x                              0x968630
#define CStmlWnd__CanBreakAtCharacter_x                            0x96C9F0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x96D680
#define CStmlWnd__ForceParseNow_x                                  0x967B80
#define CStmlWnd__GetNextTagPiece_x                                0x96C950
#define CStmlWnd__GetSTMLText_x                                    0x509AB0
#define CStmlWnd__GetVisibleText_x                                 0x967BA0
#define CStmlWnd__InitializeWindowVariables_x                      0x96D4D0
#define CStmlWnd__MakeStmlColorTag_x                               0x966C00
#define CStmlWnd__MakeWndNotificationTag_x                         0x966C70
#define CStmlWnd__SetSTMLText_x                                    0x965CB0
#define CStmlWnd__StripFirstSTMLLines_x                            0x96E780
#define CStmlWnd__UpdateHistoryString_x                            0x96D890

// CTabWnd 
#define CTabWnd__Draw_x                                            0x964E00
#define CTabWnd__DrawCurrentPage_x                                 0x965530
#define CTabWnd__DrawTab_x                                         0x965250
#define CTabWnd__GetCurrentPage_x                                  0x964600
#define CTabWnd__GetPageInnerRect_x                                0x964840
#define CTabWnd__GetTabInnerRect_x                                 0x964780
#define CTabWnd__GetTabRect_x                                      0x964630
#define CTabWnd__InsertPage_x                                      0x964A50
#define CTabWnd__SetPage_x                                         0x9648C0
#define CTabWnd__SetPageRect_x                                     0x964D40
#define CTabWnd__UpdatePage_x                                      0x965110
#define CTabWnd__GetPageFromTabIndex_x                             0x965190
#define CTabWnd__GetCurrentTabIndex_x                              0x9645F0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7752C0
#define CPageWnd__SetTabText_x                                     0x964140

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9210

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93B920
#define CTextureFont__GetTextExtent_x                              0x93BAE0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C25E0
#define CHtmlComponentWnd__ValidateUri_x                           0x753B20
#define CHtmlWnd__SetClientCallbacks_x                             0x62FC10
#define CHtmlWnd__AddObserver_x                                    0x62FC30
#define CHtmlWnd__RemoveObserver_x                                 0x62FC90
#define Window__getProgress_x                                      0x86B990
#define Window__getStatus_x                                        0x86B9B0
#define Window__getURI_x                                           0x86B9C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9749C0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x928B30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8450
#define CXStr__CXStr1_x                                            0x504C20
#define CXStr__CXStr3_x                                            0x9099F0
#define CXStr__dCXStr_x                                            0x4787C0
#define CXStr__operator_equal_x                                    0x909C20
#define CXStr__operator_equal1_x                                   0x909C60
#define CXStr__operator_plus_equal1_x                              0x90A6F0
#define CXStr__SetString_x                                         0x90C5E0
#define CXStr__operator_char_p_x                                   0x90A160
#define CXStr__GetChar_x                                           0x90BF10
#define CXStr__Delete_x                                            0x90B7E0
#define CXStr__GetUnicode_x                                        0x90BF80
#define CXStr__GetLength_x                                         0x4A8FC0
#define CXStr__Mid_x                                               0x47D5C0
#define CXStr__Insert_x                                            0x90BFE0
#define CXStr__FindNext_x                                          0x90BC50

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x95D000
#define CXWnd__BringToTop_x                                        0x9422B0
#define CXWnd__Center_x                                            0x941E30
#define CXWnd__ClrFocus_x                                          0x941C40
#define CXWnd__Destroy_x                                           0x941CF0
#define CXWnd__DoAllDrawing_x                                      0x93E250
#define CXWnd__DrawChildren_x                                      0x93E220
#define CXWnd__DrawColoredRect_x                                   0x93E6B0
#define CXWnd__DrawTooltip_x                                       0x93CD50
#define CXWnd__DrawTooltipAtPoint_x                                0x93CE10
#define CXWnd__GetBorderFrame_x                                    0x93E510
#define CXWnd__GetChildWndAt_x                                     0x942350
#define CXWnd__GetClientClipRect_x                                 0x940520
#define CXWnd__GetScreenClipRect_x                                 0x9405D0
#define CXWnd__GetScreenRect_x                                     0x940750
#define CXWnd__GetRelativeRect_x                                   0x940820
#define CXWnd__GetTooltipRect_x                                    0x93E700
#define CXWnd__GetWindowTextA_x                                    0x49CD10
#define CXWnd__IsActive_x                                          0x93EE30
#define CXWnd__IsDescendantOf_x                                    0x941170
#define CXWnd__IsReallyVisible_x                                   0x9411A0
#define CXWnd__IsType_x                                            0x9429D0
#define CXWnd__Move_x                                              0x941210
#define CXWnd__Move1_x                                             0x9412D0
#define CXWnd__ProcessTransition_x                                 0x941DE0
#define CXWnd__Refade_x                                            0x9415B0
#define CXWnd__Resize_x                                            0x941850
#define CXWnd__Right_x                                             0x942070
#define CXWnd__SetFocus_x                                          0x941C00
#define CXWnd__SetFont_x                                           0x941C70
#define CXWnd__SetKeyTooltip_x                                     0x9427E0
#define CXWnd__SetMouseOver_x                                      0x93F680
#define CXWnd__StartFade_x                                         0x941050
#define CXWnd__GetChildItem_x                                      0x9424C0
#define CXWnd__SetParent_x                                         0x940F00
#define CXWnd__Minimize_x                                          0x9418C0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x978C30

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x945230
#define CXWndManager__DrawWindows_x                                0x945250
#define CXWndManager__GetKeyboardFlags_x                           0x947A50
#define CXWndManager__HandleKeyboardMsg_x                          0x947600
#define CXWndManager__RemoveWnd_x                                  0x947C80
#define CXWndManager__RemovePendingDeletionWnd_x                   0x948200

// CDBStr
#define CDBStr__GetString_x                                        0x5436A0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBEA0
#define EQ_Character__Cur_HP_x                                     0x4D2020
#define EQ_Character__Cur_Mana_x                                   0x4D9740
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEEE0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2980
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2AD0
#define EQ_Character__GetHPRegen_x                                 0x4DF4E0
#define EQ_Character__GetEnduranceRegen_x                          0x4DFAE0
#define EQ_Character__GetManaRegen_x                               0x4DFF20
#define EQ_Character__Max_Endurance_x                              0x655B40
#define EQ_Character__Max_HP_x                                     0x4D1E50
#define EQ_Character__Max_Mana_x                                   0x655940
#define EQ_Character__doCombatAbility_x                            0x657F80
#define EQ_Character__UseSkill_x                                   0x4E1D00
#define EQ_Character__GetConLevel_x                                0x64EDC0
#define EQ_Character__IsExpansionFlag_x                            0x5B26E0
#define EQ_Character__TotalEffect_x                                0x4C5230
#define EQ_Character__GetPCSpellAffect_x                           0x4BFC30
#define EQ_Character__SpellDuration_x                              0x4BF760
#define EQ_Character__GetAdjustedSkill_x                           0x4D4DA0
#define EQ_Character__GetBaseSkill_x                               0x4D5D40
#define EQ_Character__CanUseItem_x                                 0x4D9A50

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8D5B50

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x66C4B0

//PcClient
#define PcClient__PcClient_x                                       0x64C510

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9B00
#define CCharacterListWnd__EnterWorld_x                            0x4B9540
#define CCharacterListWnd__Quit_x                                  0x4B9290
#define CCharacterListWnd__UpdateList_x                            0x4B96D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x630DC0
#define EQ_Item__CreateItemTagString_x                             0x8B0150
#define EQ_Item__IsStackable_x                                     0x8B4D70
#define EQ_Item__GetImageNum_x                                     0x8B1BD0
#define EQ_Item__CreateItemClient_x                                0x630030
#define EQ_Item__GetItemValue_x                                    0x8B2FC0
#define EQ_Item__ValueSellMerchant_x                               0x8B66D0
#define EQ_Item__IsKeyRingItem_x                                   0x8B4690
#define EQ_Item__CanGoInBag_x                                      0x630EE0
#define EQ_Item__IsEmpty_x                                         0x8B41E0
#define EQ_Item__GetMaxItemCount_x                                 0x8B33D0
#define EQ_Item__GetHeldItem_x                                     0x8B1AA0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8AFAA0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x561D60
#define EQ_LoadingS__Array_x                                       0xC36B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x656480
#define EQ_PC__GetAlternateAbilityId_x                             0x8BF910
#define EQ_PC__GetCombatAbility_x                                  0x8BFF80
#define EQ_PC__GetCombatAbilityTimer_x                             0x8BFFF0
#define EQ_PC__GetItemRecastTimer_x                                0x658500
#define EQ_PC__HasLoreItem_x                                       0x64F580
#define EQ_PC__AlertInventoryChanged_x                             0x64E700
#define EQ_PC__GetPcZoneClient_x                                   0x67AF60
#define EQ_PC__RemoveMyAffect_x                                    0x65B730
#define EQ_PC__GetKeyRingItems_x                                   0x8C0880
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C0610
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C0B80

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5B8C30
#define EQItemList__add_object_x                                   0x5E6480
#define EQItemList__add_item_x                                     0x5B9190
#define EQItemList__delete_item_x                                  0x5B91E0
#define EQItemList__FreeItemList_x                                 0x5B90E0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x540220

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x66DD30
#define EQPlayer__dEQPlayer_x                                      0x660C40
#define EQPlayer__DoAttack_x                                       0x675BF0
#define EQPlayer__EQPlayer_x                                       0x661300
#define EQPlayer__SetNameSpriteState_x                             0x665A10
#define EQPlayer__SetNameSpriteTint_x                              0x6668E0
#define PlayerBase__HasProperty_j_x                                0x9A7A50
#define EQPlayer__IsTargetable_x                                   0x9A7EF0
#define EQPlayer__CanSee_x                                         0x9A7D50
#define EQPlayer__CanSee1_x                                        0x9A7E20
#define PlayerBase__GetVisibilityLineSegment_x                     0x9A7B10

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6789F0
#define PlayerZoneClient__GetLevel_x                               0x67AFA0
#define PlayerZoneClient__IsValidTeleport_x                        0x5E7600
#define PlayerZoneClient__LegalPlayerRace_x                        0x55AFB0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x670AF0
#define EQPlayerManager__GetSpawnByName_x                          0x670BA0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x670C30

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x634450
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6344D0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x634510
#define KeypressHandler__ClearCommandStateArray_x                  0x635920
#define KeypressHandler__HandleKeyDown_x                           0x635940
#define KeypressHandler__HandleKeyUp_x                             0x6359E0
#define KeypressHandler__SaveKeymapping_x                          0x635E30

// MapViewMap 
#define MapViewMap__Clear_x                                        0x78BFC0
#define MapViewMap__SaveEx_x                                       0x78F380
#define MapViewMap__SetZoom_x                                      0x793A40

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D3C50

// StringTable 
#define StringTable__getString_x                                   0x8CEAA0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x65B3A0
#define PcZoneClient__RemovePetEffect_x                            0x65B9D0
#define PcZoneClient__HasAlternateAbility_x                        0x655770
#define PcZoneClient__GetCurrentMod_x                              0x4E4DC0
#define PcZoneClient__GetModCap_x                                  0x4E4CC0
#define PcZoneClient__CanEquipItem_x                               0x655E20
#define PcZoneClient__GetItemByID_x                                0x658970
#define PcZoneClient__GetItemByItemClass_x                         0x658AC0
#define PcZoneClient__RemoveBuffEffect_x                           0x65B9F0
#define PcZoneClient__BandolierSwap_x                              0x656A40
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6584A0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5EC180

//IconCache
#define IconCache__GetIcon_x                                       0x72D540

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x725030
#define CContainerMgr__CloseContainer_x                            0x725300
#define CContainerMgr__OpenExperimentContainer_x                   0x725D80

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E41E0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x628FB0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x782400
#define CLootWnd__RequestLootSlot_x                                0x781630

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x586780
#define EQ_Spell__SpellAffects_x                                   0x586BF0
#define EQ_Spell__SpellAffectBase_x                                0x5869B0
#define EQ_Spell__IsStackable_x                                    0x4C9A50
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C98A0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6E50
#define EQ_Spell__IsSPAStacking_x                                  0x587A40
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x586F50
#define EQ_Spell__IsNoRemove_x                                     0x4C9A30
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x587A50
#define __IsResEffectSpell_x                                       0x4C8C50

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD280

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8DE1F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82B2A0
#define CTargetWnd__WndNotification_x                              0x82AAE0
#define CTargetWnd__RefreshTargetBuffs_x                           0x82ADB0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x829C40

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x82F8B0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53DC40
#define CTaskManager__HandleMessage_x                              0x53C0F0
#define CTaskManager__GetTaskStatus_x                              0x53DCF0
#define CTaskManager__GetElementDescription_x                      0x53DD70

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x581950
#define EqSoundManager__PlayScriptMp3_x                            0x581C10
#define EqSoundManager__SoundAssistPlay_x                          0x6937F0
#define EqSoundManager__WaveInstancePlay_x                         0x692D60

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52F3F0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x963650

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x569800
#define CAltAbilityData__GetMercMaxRank_x                          0x569790
#define CAltAbilityData__GetMaxRank_x                              0x55ECB0

//CTargetRing
#define CTargetRing__Cast_x                                        0x6270D0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9880
#define CharacterBase__CreateItemGlobalIndex_x                     0x516840
#define CharacterBase__CreateItemIndex_x                           0x62F1C0
#define CharacterBase__GetItemPossession_x                         0x502530
#define CharacterBase__GetItemByGlobalIndex_x                      0x8E6850
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8E68B0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x70BFC0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x70C7F0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x70C8A0

//messages
#define msg_spell_worn_off_x                                       0x5AAA80
#define msg_new_text_x                                             0x59F800
#define __msgTokenTextParam_x                                      0x5ACFA0
#define msgTokenText_x                                             0x5AD1F0

//SpellManager
#define SpellManager__vftable_x                                    0xAFA780
#define SpellManager__SpellManager_x                               0x696B20
#define Spellmanager__LoadTextSpells_x                             0x697410
#define SpellManager__GetSpellByGroupAndRank_x                     0x696CF0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9AB990

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x516EC0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B0D30
#define ItemGlobalIndex__IsEquippedLocation_x                      0x647C60
#define ItemGlobalIndex__IsValidIndex_x                            0x516F20

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8DEB90
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8DEE10

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77AC70

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x729740
#define CCursorAttachment__AttachToCursor1_x                       0x729780
#define CCursorAttachment__Deactivate_x                            0x72A770

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x956420
#define CSidlManagerBase__CreatePageWnd_x                          0x955C10
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x951E90
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x951E20

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9736E0
#define CEQSuiteTextureLoader__GetTexture_x                        0x9733A0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x513DE0
#define CFindItemWnd__WndNotification_x                            0x5148C0
#define CFindItemWnd__Update_x                                     0x515430
#define CFindItemWnd__PickupSelectedItem_x                         0x513630

//IString
#define IString__Append_x                                          0x4F3AA0

//Camera
#define CDisplay__cameraType_x                                     0xE106DC
#define EverQuest__Cameras_x                                       0xECB56C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51C560
#define LootFiltersManager__GetItemFilterData_x                    0x51BE70
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51BEA0
#define LootFiltersManager__SetItemLootFilter_x                    0x51C0C0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D2160

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B1530
#define CResolutionHandler__GetWindowedStyle_x                     0x68E1A0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x721CE0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F40C0
#define CDistillerInfo__Instance_x                                 0x8F4060

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x740EE0
#define CGroupWnd__UpdateDisplay_x                                 0x740230

//ItemBase
#define ItemBase__IsLore_x                                         0x8B4740
#define ItemBase__IsLoreEquipped_x                                 0x8B47B0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5E63E0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5E6520
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5E6580

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x683670
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x687010

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50A0F0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F6780
#define FactionManagerClient__HandleFactionMessage_x               0x4F6DF0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F73F0
#define FactionManagerClient__GetMaxFaction_x                      0x4F740F
#define FactionManagerClient__GetMinFaction_x                      0x4F73C0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x502500

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x93A940

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BFF0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5027E0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x568CC0

//CTargetManager
#define CTargetManager__Get_x                                      0x69A380

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x683670

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8FD0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5B9080

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF68C00

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
