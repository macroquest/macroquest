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
#define __ExpectedVersionDate                                     "Oct 13 2020"
#define __ExpectedVersionTime                                     "11:24:29"
#define __ActualVersionDate_x                                      0xAF22BC
#define __ActualVersionTime_x                                      0xAF22B0
#define __ActualVersionBuild_x                                     0xAE02CC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x640E60
#define __MemChecker1_x                                            0x8F3F90
#define __MemChecker2_x                                            0x6B1720
#define __MemChecker3_x                                            0x6B1670
#define __MemChecker4_x                                            0x84A8D0
#define __EncryptPad0_x                                            0xC27500
#define __EncryptPad1_x                                            0xC84D38
#define __EncryptPad2_x                                            0xC378C8
#define __EncryptPad3_x                                            0xC374C8
#define __EncryptPad4_x                                            0xC752D8
#define __EncryptPad5_x                                            0xF470B8
#define __AC1_x                                                    0x809436
#define __AC2_x                                                    0x5FA5FF
#define __AC3_x                                                    0x601C50
#define __AC4_x                                                    0x605C00
#define __AC5_x                                                    0x60BEEF
#define __AC6_x                                                    0x6103A6
#define __AC7_x                                                    0x5FA070
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x191CC4

// Direct Input
#define DI8__Main_x                                                0xF470D8
#define DI8__Keyboard_x                                            0xF470DC
#define DI8__Mouse_x                                               0xF470F4
#define DI8__Mouse_Copy_x                                          0xEA045C
#define DI8__Mouse_Check_x                                         0xF44C0C
#define __AutoSkillArray_x                                         0xEA1378
#define __Attack_x                                                 0xF3F19B
#define __Autofire_x                                               0xF3F19C
#define __BindList_x                                               0xC15F38
#define g_eqCommandStates_x                                        0xC16CB8
#define __Clicks_x                                                 0xEA0514
#define __CommandList_x                                            0xC17878
#define __CurrentMapLabel_x                                        0xF57AAC
#define __CurrentSocial_x                                          0xBFF7C8
#define __DoAbilityList_x                                          0xED6CBC
#define __do_loot_x                                                0x5C6290
#define __DrawHandler_x                                            0x15D6AA0
#define __GroupCount_x                                             0xE9B532
#define __Guilds_x                                                 0xE9F398
#define __gWorld_x                                                 0xE9B3AC
#define __HWnd_x                                                   0xF470F8
#define __heqmain_x                                                0xF470A0
#define __InChatMode_x                                             0xEA0444
#define __LastTell_x                                               0xEA23B8
#define __LMouseHeldTime_x                                         0xEA0580
#define __Mouse_x                                                  0xF470C4
#define __MouseLook_x                                              0xEA04DA
#define __MouseEventTime_x                                         0xF3FC7C
#define __gpbCommandEvent_x                                        0xE98E30
#define __NetStatusToggle_x                                        0xEA04DD
#define __PCNames_x                                                0xEA1968
#define __RangeAttackReady_x                                       0xEA165C
#define __RMouseHeldTime_x                                         0xEA057C
#define __RunWalkState_x                                           0xEA0448
#define __ScreenMode_x                                             0xDE67C8
#define __ScreenX_x                                                0xEA03FC
#define __ScreenY_x                                                0xEA03F8
#define __ScreenXMax_x                                             0xEA0400
#define __ScreenYMax_x                                             0xEA0404
#define __ServerHost_x                                             0xE98FFB
#define __ServerName_x                                             0xED6C7C
#define __ShiftKeyDown_x                                           0xEA0AD8
#define __ShowNames_x                                              0xEA1818
#define EverQuestInfo__bSocialChanged_x                            0xED6D04
#define __Socials_x                                                0xED6D7C
#define __SubscriptionType_x                                       0xF9BD70
#define __TargetAggroHolder_x                                      0xF5A460
#define __ZoneType_x                                               0xEA08D8
#define __GroupAggro_x                                             0xF5A4A0
#define __LoginName_x                                              0xF47834
#define __Inviter_x                                                0xF3F118
#define __AttackOnAssist_x                                         0xEA17D4
#define __UseTellWindows_x                                         0xEA1B00
#define __gfMaxZoomCameraDistance_x                                0xAE9EC8
#define __gfMaxCameraDistance_x                                    0xB12B48
#define __pulAutoRun_x                                             0xEA04F8
#define __pulForward_x                                             0xEA1B38
#define __pulBackward_x                                            0xEA1B3C
#define __pulTurnRight_x                                           0xEA1B40
#define __pulTurnLeft_x                                            0xEA1B44
#define __pulStrafeLeft_x                                          0xEA1B48
#define __pulStrafeRight_x                                         0xEA1B4C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE9B730
#define instEQZoneInfo_x                                           0xEA06D0
#define pinstActiveBanker_x                                        0xE9931C
#define pinstActiveCorpse_x                                        0xE99314
#define pinstActiveGMaster_x                                       0xE99318
#define pinstActiveMerchant_x                                      0xE99310
#define pinstAltAdvManager_x                                       0xDE7960
#define pinstBandageTarget_x                                       0xE9932C
#define pinstCamActor_x                                            0xDE67B8
#define pinstCDBStr_x                                              0xDE667C
#define pinstCDisplay_x                                            0xE9B384
#define pinstCEverQuest_x                                          0xF470F0
#define pinstEverQuestInfo_x                                       0xEA03F0
#define pinstCharData_x                                            0xE9B720
#define pinstCharSpawn_x                                           0xE99364
#define pinstControlledMissile_x                                   0xE99374
#define pinstControlledPlayer_x                                    0xE99364
#define pinstCResolutionHandler_x                                  0x15D6CD0
#define pinstCSidlManager_x                                        0x15D5C68
#define pinstCXWndManager_x                                        0x15D5C64
#define instDynamicZone_x                                          0xE9F270
#define pinstDZMember_x                                            0xE9F380
#define pinstDZTimerInfo_x                                         0xE9F384
#define pinstEqLogin_x                                             0xF47180
#define instEQMisc_x                                               0xDE65C0
#define pinstEQSoundManager_x                                      0xDE8930
#define pinstEQSpellStrings_x                                      0xCA8F78
#define instExpeditionLeader_x                                     0xE9F2BA
#define instExpeditionName_x                                       0xE9F2FA
#define pinstGroup_x                                               0xE9B52E
#define pinstImeManager_x                                          0x15D5C60
#define pinstLocalPlayer_x                                         0xE9930C
#define pinstMercenaryData_x                                       0xF41768
#define pinstMercenaryStats_x                                      0xF5A52C
#define pinstModelPlayer_x                                         0xE99324
#define pinstPCData_x                                              0xE9B720
#define pinstSkillMgr_x                                            0xF438D0
#define pinstSpawnManager_x                                        0xF42378
#define pinstSpellManager_x                                        0xF43B10
#define pinstSpellSets_x                                           0xF37DC4
#define pinstStringTable_x                                         0xE9B728
#define pinstSwitchManager_x                                       0xE98CD0
#define pinstTarget_x                                              0xE99360
#define pinstTargetObject_x                                        0xE9936C
#define pinstTargetSwitch_x                                        0xE9937C
#define pinstTaskMember_x                                          0xDE6450
#define pinstTrackTarget_x                                         0xE99368
#define pinstTradeTarget_x                                         0xE99320
#define instTributeActive_x                                        0xDE65E1
#define pinstViewActor_x                                           0xDE67B4
#define pinstWorldData_x                                           0xE98E20
#define pinstZoneAddr_x                                            0xEA0970
#define pinstPlayerPath_x                                          0xF42410
#define pinstTargetIndicator_x                                     0xF43D78
#define EQObject_Top_x                                             0xE99104
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDE6AFC
#define pinstCAchievementsWnd_x                                    0xDE6754
#define pinstCActionsWnd_x                                         0xDE6F90
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDE6814
#define pinstCAdvancedLootWnd_x                                    0xDE67AC
#define pinstCAdventureLeaderboardWnd_x                            0xF51280
#define pinstCAdventureRequestWnd_x                                0xF51330
#define pinstCAdventureStatsWnd_x                                  0xF513E0
#define pinstCAggroMeterWnd_x                                      0xDE67FC
#define pinstCAlarmWnd_x                                           0xDE677C
#define pinstCAlertHistoryWnd_x                                    0xDE688C
#define pinstCAlertStackWnd_x                                      0xDE67E4
#define pinstCAlertWnd_x                                           0xDE67F8
#define pinstCAltStorageWnd_x                                      0xF51740
#define pinstCAudioTriggersWindow_x                                0xC9B2A8
#define pinstCAuraWnd_x                                            0xDE67B0
#define pinstCAvaZoneWnd_x                                         0xDE6860
#define pinstCBandolierWnd_x                                       0xDE6810
#define pinstCBankWnd_x                                            0xDE6844
#define pinstCBarterMerchantWnd_x                                  0xF52980
#define pinstCBarterSearchWnd_x                                    0xF52A30
#define pinstCBarterWnd_x                                          0xF52AE0
#define pinstCBazaarConfirmationWnd_x                              0xDE6790
#define pinstCBazaarSearchWnd_x                                    0xDE6B00
#define pinstCBazaarWnd_x                                          0xDE6760
#define pinstCBlockedBuffWnd_x                                     0xDE67D8
#define pinstCBlockedPetBuffWnd_x                                  0xDE6800
#define pinstCBodyTintWnd_x                                        0xDE6FA4
#define pinstCBookWnd_x                                            0xDE683C
#define pinstCBreathWnd_x                                          0xDE6B84
#define pinstCBuffWindowNORMAL_x                                   0xDE67A4
#define pinstCBuffWindowSHORT_x                                    0xDE67A8
#define pinstCBugReportWnd_x                                       0xDE6840
#define pinstCButtonWnd_x                                          0x15D5ED0
#define pinstCCastingWnd_x                                         0xDE6830
#define pinstCCastSpellWnd_x                                       0xDE6B0C
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDE6FB0
#define pinstCChatWindowManager_x                                  0xF535A0
#define pinstCClaimWnd_x                                           0xF536F8
#define pinstCColorPickerWnd_x                                     0xDE6AA8
#define pinstCCombatAbilityWnd_x                                   0xDE6770
#define pinstCCombatSkillsSelectWnd_x                              0xDE6728
#define pinstCCompassWnd_x                                         0xDE6F94
#define pinstCConfirmationDialog_x                                 0xF585F8
#define pinstCContainerMgr_x                                       0xDE6FA0
#define pinstCContextMenuManager_x                                 0x15D5C20
#define pinstCCursorAttachment_x                                   0xDE6824
#define pinstCDynamicZoneWnd_x                                     0xF53CC0
#define pinstCEditLabelWnd_x                                       0xDE67A0
#define pinstCEQMainWnd_x                                          0xF53F08
#define pinstCEventCalendarWnd_x                                   0xDE6B04
#define pinstCExtendedTargetWnd_x                                  0xDE67E0
#define pinstCFacePick_x                                           0xDE672C
#define pinstCFactionWnd_x                                         0xDE674C
#define pinstCFellowshipWnd_x                                      0xF54108
#define pinstCFileSelectionWnd_x                                   0xDE6AA4
#define pinstCFindItemWnd_x                                        0xDE673C
#define pinstCFindLocationWnd_x                                    0xF54260
#define pinstCFriendsWnd_x                                         0xDE6740
#define pinstCGemsGameWnd_x                                        0xDE6748
#define pinstCGiveWnd_x                                            0xDE6780
#define pinstCGroupSearchFiltersWnd_x                              0xDE6818
#define pinstCGroupSearchWnd_x                                     0xF54658
#define pinstCGroupWnd_x                                           0xF54708
#define pinstCGuildBankWnd_x                                       0xEA17B8
#define pinstCGuildCreationWnd_x                                   0xF54868
#define pinstCGuildMgmtWnd_x                                       0xF54918
#define pinstCharacterCreation_x                                   0xDE6734
#define pinstCHelpWnd_x                                            0xDE6784
#define pinstCHeritageSelectionWnd_x                               0xDE6738
#define pinstCHotButtonWnd_x                                       0xF56A70
#define pinstCHotButtonWnd1_x                                      0xF56A70
#define pinstCHotButtonWnd2_x                                      0xF56A74
#define pinstCHotButtonWnd3_x                                      0xF56A78
#define pinstCHotButtonWnd4_x                                      0xF56A7C
#define pinstCIconSelectionWnd_x                                   0xDE6820
#define pinstCInspectWnd_x                                         0xDE6804
#define pinstCInventoryWnd_x                                       0xDE67BC
#define pinstCInvSlotMgr_x                                         0xDE6AEC
#define pinstCItemDisplayManager_x                                 0xF57000
#define pinstCItemExpTransferWnd_x                                 0xF57130
#define pinstCItemOverflowWnd_x                                    0xDE6B08
#define pinstCJournalCatWnd_x                                      0xDE6ABC
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDE6878
#define pinstCKeyRingWnd_x                                         0xDE682C
#define pinstCLargeDialogWnd_x                                     0xF59278
#define pinstCLayoutCopyWnd_x                                      0xF57480
#define pinstCLFGuildWnd_x                                         0xF57530
#define pinstCLoadskinWnd_x                                        0xDE6764
#define pinstCLootFiltersCopyWnd_x                                 0xCB7958
#define pinstCLootFiltersWnd_x                                     0xDE67E8
#define pinstCLootSettingsWnd_x                                    0xDE680C
#define pinstCLootWnd_x                                            0xDE6AC0
#define pinstCMailAddressBookWnd_x                                 0xDE6AF4
#define pinstCMailCompositionWnd_x                                 0xDE6AB0
#define pinstCMailIgnoreListWnd_x                                  0xDE6AF8
#define pinstCMailWnd_x                                            0xDE6A9C
#define pinstCManageLootWnd_x                                      0xDE7E10
#define pinstCMapToolbarWnd_x                                      0xDE678C
#define pinstCMapViewWnd_x                                         0xDE6758
#define pinstCMarketplaceWnd_x                                     0xDE67EC
#define pinstCMerchantWnd_x                                        0xDE6ACC
#define pinstCMIZoneSelectWnd_x                                    0xF57D68
#define pinstCMusicPlayerWnd_x                                     0xDE6A98
#define pinstCNameChangeMercWnd_x                                  0xDE6788
#define pinstCNameChangePetWnd_x                                   0xDE675C
#define pinstCNameChangeWnd_x                                      0xDE679C
#define pinstCNoteWnd_x                                            0xDE6768
#define pinstCObjectPreviewWnd_x                                   0xDE6808
#define pinstCOptionsWnd_x                                         0xDE6774
#define pinstCPetInfoWnd_x                                         0xDE6894
#define pinstCPetitionQWnd_x                                       0xDE6724
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDE6FA8
#define pinstCPlayerWnd_x                                          0xDE6888
#define pinstCPopupWndManager_x                                    0xF585F8
#define pinstCProgressionSelectionWnd_x                            0xF586A8
#define pinstCPurchaseGroupWnd_x                                   0xDE685C
#define pinstCPurchaseWnd_x                                        0xDE6834
#define pinstCPvPLeaderboardWnd_x                                  0xF58758
#define pinstCPvPStatsWnd_x                                        0xF58808
#define pinstCQuantityWnd_x                                        0xDE6874
#define pinstCRaceChangeWnd_x                                      0xDE67D0
#define pinstCRaidOptionsWnd_x                                     0xDE681C
#define pinstCRaidWnd_x                                            0xDE6AC8
#define pinstCRealEstateItemsWnd_x                                 0xDE6750
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDE6F98
#define pinstCRealEstateManageWnd_x                                0xDE6864
#define pinstCRealEstateNeighborhoodWnd_x                          0xDE6880
#define pinstCRealEstatePlotSearchWnd_x                            0xDE6AA0
#define pinstCRealEstatePurchaseWnd_x                              0xDE6AB8
#define pinstCRespawnWnd_x                                         0xDE67F4
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDE6720
#define pinstCSendMoneyWnd_x                                       0xDE6794
#define pinstCServerListWnd_x                                      0xDE6AC4
#define pinstCSkillsSelectWnd_x                                    0xDE671C
#define pinstCSkillsWnd_x                                          0xDE6F9C
#define pinstCSocialEditWnd_x                                      0xDE6828
#define pinstCSocialWnd_x                                          0xDE6778
#define pinstCSpellBookWnd_x                                       0xDE676C
#define pinstCStoryWnd_x                                           0xDE6F8C
#define pinstCTargetOfTargetWnd_x                                  0xF5A5B0
#define pinstCTargetWnd_x                                          0xDE67F0
#define pinstCTaskOverlayWnd_x                                     0xDE6854
#define pinstCTaskSelectWnd_x                                      0xF5A708
#define pinstCTaskManager_x                                        0xCB8298
#define pinstCTaskTemplateSelectWnd_x                              0xF5A7B8
#define pinstCTaskWnd_x                                            0xF5A868
#define pinstCTextEntryWnd_x                                       0xDE6838
#define pinstCTimeLeftWnd_x                                        0xDE6718
#define pinstCTipWndCONTEXT_x                                      0xF5AA6C
#define pinstCTipWndOFDAY_x                                        0xF5AA68
#define pinstCTitleWnd_x                                           0xF5AB18
#define pinstCTrackingWnd_x                                        0xDE67DC
#define pinstCTradeskillWnd_x                                      0xF5AC80
#define pinstCTradeWnd_x                                           0xDE6FAC
#define pinstCTrainWnd_x                                           0xDE6AB4
#define pinstCTributeBenefitWnd_x                                  0xF5AE80
#define pinstCTributeMasterWnd_x                                   0xF5AF30
#define pinstCTributeTrophyWnd_x                                   0xF5AFE0
#define pinstCVideoModesWnd_x                                      0xDE6884
#define pinstCVoiceMacroWnd_x                                      0xF44330
#define pinstCVoteResultsWnd_x                                     0xDE6744
#define pinstCVoteWnd_x                                            0xDE6730
#define pinstCWebManager_x                                         0xF449AC
#define pinstCZoneGuideWnd_x                                       0xDE6858
#define pinstCZonePathWnd_x                                        0xDE6870

#define pinstEQSuiteTextureLoader_x                                0xC85658
#define pinstItemIconCache_x                                       0xF53EC0
#define pinstLootFiltersManager_x                                  0xCB7A08
#define pinstRewardSelectionWnd_x                                  0xF58F50

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C1980
#define __CastRay2_x                                               0x5C19D0
#define __ConvertItemTags_x                                        0x5DD570
#define __CleanItemTags_x                                          0x47CE50
#define __DoesFileExist_x                                          0x8F6FC0
#define __EQGetTime_x                                              0x8F3BC0
#define __ExecuteCmd_x                                             0x5BA300
#define __FixHeading_x                                             0x988A10
#define __FlushDxKeyboard_x                                        0x6AD5C0
#define __GameLoop_x                                               0x6B08F0
#define __get_bearing_x                                            0x5C14E0
#define __get_melee_range_x                                        0x5C1BC0
#define __GetAnimationCache_x                                      0x715E10
#define __GetGaugeValueFromEQ_x                                    0x8078E0
#define __GetLabelFromEQ_x                                         0x8093C0
#define __GetXTargetType_x                                         0x98A4E0
#define __HandleMouseWheel_x                                       0x6B17D0
#define __HeadingDiff_x                                            0x988A80
#define __HelpPath_x                                               0xF3F86C
#define __LoadFrontEnd_x                                           0x6ADC00
#define __NewUIINI_x                                               0x8075B0
#define __ProcessGameEvents_x                                      0x622280
#define __ProcessMouseEvent_x                                      0x621A10
#define __SaveColors_x                                             0x55ABD0
#define __STMLToText_x                                             0x92BF30
#define __ToggleKeyRingItem_x                                      0x5196F0
#define CMemoryMappedFile__SetFile_x                               0xA77F40
#define CrashDetected_x                                            0x6AF6B0
#define DrawNetStatus_x                                            0x64E2E0
#define Expansion_HoT_x                                            0xEA17C0
#define Teleport_Table_Size_x                                      0xE98EB8
#define Teleport_Table_x                                           0xE99380
#define Util__FastTime_x                                           0x8F3790
#define __CopyLayout_x                                             0x63C610
#define __WndProc_x                                                0x6AFBB0
#define __ProcessKeyboardEvent_x                                   0x6AF150

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490120
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499120
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498EF0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4936C0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492B10

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x562DE0
#define AltAdvManager__IsAbilityReady_x                            0x561B80
#define AltAdvManager__GetAAById_x                                 0x561F10
#define AltAdvManager__CanTrainAbility_x                           0x561F80
#define AltAdvManager__CanSeeAbility_x                             0x5622E0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CAFB0
#define CharacterZoneClient__HasSkill_x                            0x4D5E30
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7550
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2820
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBCB0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9F00
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9FE0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA0C0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4910
#define CharacterZoneClient__BardCastBard_x                        0x4C7340
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF6C0
#define CharacterZoneClient__GetEffect_x                           0x4BBBF0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5980
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5A50
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5AA0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5BF0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C5DD0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3960
#define CharacterZoneClient__FindItemByGuid_x                      0x4D84B0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7F30

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D7450
#define CBankWnd__WndNotification_x                                0x6D7230

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E4B50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x929710
#define CButtonWnd__CButtonWnd_x                                   0x928310

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x704FE0
#define CChatManager__InitContextMenu_x                            0x6FE110
#define CChatManager__FreeChatWindow_x                             0x703B20
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9870
#define CChatManager__SetLockedActiveChatWindow_x                  0x704C60
#define CChatManager__CreateChatWindow_x                           0x704160

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9980

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93C860
#define CContextMenu__dCContextMenu_x                              0x93CAA0
#define CContextMenu__AddMenuItem_x                                0x93CAB0
#define CContextMenu__RemoveMenuItem_x                             0x93CDC0
#define CContextMenu__RemoveAllMenuItems_x                         0x93CDE0
#define CContextMenu__CheckMenuItem_x                              0x93CE60
#define CContextMenu__SetMenuItem_x                                0x93CCE0
#define CContextMenu__AddSeparator_x                               0x93CC40

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x93D400
#define CContextMenuManager__RemoveMenu_x                          0x93D470
#define CContextMenuManager__PopupMenu_x                           0x93D530
#define CContextMenuManager__Flush_x                               0x93D3A0
#define CContextMenuManager__GetMenu_x                             0x49B490
#define CContextMenuManager__CreateDefaultMenu_x                   0x710770

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CE9C0
#define CChatService__GetFriendName_x                              0x8CE9D0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x705860
#define CChatWindow__Clear_x                                       0x706B30
#define CChatWindow__WndNotification_x                             0x7072C0
#define CChatWindow__AddHistory_x                                  0x7063F0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x939CB0
#define CComboWnd__Draw_x                                          0x9391A0
#define CComboWnd__GetCurChoice_x                                  0x939AF0
#define CComboWnd__GetListRect_x                                   0x939650
#define CComboWnd__GetTextRect_x                                   0x939D20
#define CComboWnd__InsertChoice_x                                  0x9397E0
#define CComboWnd__SetColors_x                                     0x9397B0
#define CComboWnd__SetChoice_x                                     0x939AC0
#define CComboWnd__GetItemCount_x                                  0x939B00
#define CComboWnd__GetCurChoiceText_x                              0x939B40
#define CComboWnd__GetChoiceText_x                                 0x939B10
#define CComboWnd__InsertChoiceAtIndex_x                           0x939880

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70E190
#define CContainerWnd__vftable_x                                   0xAFB4AC
#define CContainerWnd__SetContainer_x                              0x70F6E0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x555580
#define CDisplay__PreZoneMainUI_x                                  0x555590
#define CDisplay__CleanGameUI_x                                    0x55A990
#define CDisplay__GetClickedActor_x                                0x54D9E0
#define CDisplay__GetUserDefinedColor_x                            0x546050
#define CDisplay__GetWorldFilePath_x                               0x54F450
#define CDisplay__is3dON_x                                         0x54A640
#define CDisplay__ReloadUI_x                                       0x554A90
#define CDisplay__WriteTextHD2_x                                   0x54A430
#define CDisplay__TrueDistance_x                                   0x551110
#define CDisplay__SetViewActor_x                                   0x54D300
#define CDisplay__GetFloorHeight_x                                 0x54A700
#define CDisplay__SetRenderWindow_x                                0x549080
#define CDisplay__ToggleScreenshotMode_x                           0x54CDD0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95C5B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x93FD60
#define CEditWnd__EnsureCaretVisible_x                             0x941F30
#define CEditWnd__GetCaretPt_x                                     0x940EE0
#define CEditWnd__GetCharIndexPt_x                                 0x940C90
#define CEditWnd__GetDisplayString_x                               0x940B30
#define CEditWnd__GetHorzOffset_x                                  0x93F400
#define CEditWnd__GetLineForPrintableChar_x                        0x941E30
#define CEditWnd__GetSelStartPt_x                                  0x940F40
#define CEditWnd__GetSTMLSafeText_x                                0x940950
#define CEditWnd__PointFromPrintableChar_x                         0x941A60
#define CEditWnd__SelectableCharFromPoint_x                        0x941BD0
#define CEditWnd__SetEditable_x                                    0x941010
#define CEditWnd__SetWindowTextA_x                                 0x9406D0
#define CEditWnd__ReplaceSelection_x                               0x9416D0
#define CEditWnd__ReplaceSelection1_x                              0x941650

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60F880
#define CEverQuest__ClickedPlayer_x                                0x601A30
#define CEverQuest__CreateTargetIndicator_x                        0x61F3F0
#define CEverQuest__DeleteTargetIndicator_x                        0x61F480
#define CEverQuest__DoTellWindow_x                                 0x4E9A60
#define CEverQuest__OutputTextToLog_x                              0x4E9D30
#define CEverQuest__DropHeldItemOnGround_x                         0x5F6B80
#define CEverQuest__dsp_chat_x                                     0x4EA0C0
#define CEverQuest__trimName_x                                     0x61B5A0
#define CEverQuest__Emote_x                                        0x6100E0
#define CEverQuest__EnterZone_x                                    0x60A1E0
#define CEverQuest__GetBodyTypeDesc_x                              0x614B30
#define CEverQuest__GetClassDesc_x                                 0x615170
#define CEverQuest__GetClassThreeLetterCode_x                      0x615770
#define CEverQuest__GetDeityDesc_x                                 0x61DC40
#define CEverQuest__GetLangDesc_x                                  0x615930
#define CEverQuest__GetRaceDesc_x                                  0x615150
#define CEverQuest__InterpretCmd_x                                 0x61E210
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FAD20
#define CEverQuest__LMouseUp_x                                     0x5F90A0
#define CEverQuest__RightClickedOnPlayer_x                         0x5FB600
#define CEverQuest__RMouseUp_x                                     0x5FA030
#define CEverQuest__SetGameState_x                                 0x5F6910
#define CEverQuest__UPCNotificationFlush_x                         0x61B4A0
#define CEverQuest__IssuePetCommand_x                              0x616D40
#define CEverQuest__ReportSuccessfulHit_x                          0x611430

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x71FED0
#define CGaugeWnd__CalcLinesFillRect_x                             0x71FF30
#define CGaugeWnd__Draw_x                                          0x71F550

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AFC20
#define CGuild__GetGuildName_x                                     0x4AE6D0
#define CGuild__GetGuildIndex_x                                    0x4AECD0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x739B50

//CHotButton
#define CHotButton__SetCheck_x                                     0x630BD0
#define CHotButton__SetButtonSize_x                                0x630F90

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x746C50
#define CInvSlotMgr__MoveItem_x                                    0x745920
#define CInvSlotMgr__SelectSlot_x                                  0x746D20

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x744110
#define CInvSlot__SliderComplete_x                                 0x741E50
#define CInvSlot__GetItemBase_x                                    0x7417C0
#define CInvSlot__UpdateItem_x                                     0x741930

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7487B0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x747940
#define CInvSlotWnd__HandleLButtonUp_x                             0x748330

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x802C40
#define CItemDisplayWnd__UpdateStrings_x                           0x756FB0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x750C20
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x751150
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7575C0
#define CItemDisplayWnd__AboutToShow_x                             0x756C00
#define CItemDisplayWnd__WndNotification_x                         0x758840
#define CItemDisplayWnd__RequestConvertItem_x                      0x758170
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x755C60
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x756A20

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x833740

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75CD80

// CLabel 
#define CLabel__Draw_x                                             0x7627A0

// CListWnd
#define CListWnd__CListWnd_x                                       0x912510
#define CListWnd__dCListWnd_x                                      0x912830
#define CListWnd__AddColumn_x                                      0x916CA0
#define CListWnd__AddColumn1_x                                     0x916CF0
#define CListWnd__AddLine_x                                        0x917080
#define CListWnd__AddString_x                                      0x916E80
#define CListWnd__CalculateFirstVisibleLine_x                      0x916A60
#define CListWnd__CalculateVSBRange_x                              0x916850
#define CListWnd__ClearSel_x                                       0x917860
#define CListWnd__ClearAllSel_x                                    0x9178C0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x9182E0
#define CListWnd__Compare_x                                        0x916180
#define CListWnd__Draw_x                                           0x912960
#define CListWnd__DrawColumnSeparators_x                           0x915150
#define CListWnd__DrawHeader_x                                     0x9155C0
#define CListWnd__DrawItem_x                                       0x915AC0
#define CListWnd__DrawLine_x                                       0x9152C0
#define CListWnd__DrawSeparator_x                                  0x9151F0
#define CListWnd__EnableLine_x                                     0x914A30
#define CListWnd__EnsureVisible_x                                  0x918200
#define CListWnd__ExtendSel_x                                      0x917790
#define CListWnd__GetColumnTooltip_x                               0x914570
#define CListWnd__GetColumnMinWidth_x                              0x9145E0
#define CListWnd__GetColumnWidth_x                                 0x9144E0
#define CListWnd__GetCurSel_x                                      0x913E70
#define CListWnd__GetItemAtPoint_x                                 0x914CB0
#define CListWnd__GetItemAtPoint1_x                                0x914D20
#define CListWnd__GetItemData_x                                    0x913EF0
#define CListWnd__GetItemHeight_x                                  0x9142B0
#define CListWnd__GetItemIcon_x                                    0x914080
#define CListWnd__GetItemRect_x                                    0x914B20
#define CListWnd__GetItemText_x                                    0x913F30
#define CListWnd__GetSelList_x                                     0x917910
#define CListWnd__GetSeparatorRect_x                               0x914F60
#define CListWnd__InsertLine_x                                     0x917470
#define CListWnd__RemoveLine_x                                     0x9175C0
#define CListWnd__SetColors_x                                      0x916820
#define CListWnd__SetColumnJustification_x                         0x916550
#define CListWnd__SetColumnLabel_x                                 0x916E20
#define CListWnd__SetColumnWidth_x                                 0x916470
#define CListWnd__SetCurSel_x                                      0x9176D0
#define CListWnd__SetItemColor_x                                   0x917EB0
#define CListWnd__SetItemData_x                                    0x917E70
#define CListWnd__SetItemText_x                                    0x917A80
#define CListWnd__ShiftColumnSeparator_x                           0x916610
#define CListWnd__Sort_x                                           0x916300
#define CListWnd__ToggleSel_x                                      0x917700
#define CListWnd__SetColumnsSizable_x                              0x9166C0
#define CListWnd__SetItemWnd_x                                     0x917D30
#define CListWnd__GetItemWnd_x                                     0x9140D0
#define CListWnd__SetItemIcon_x                                    0x917B00
#define CListWnd__CalculateCustomWindowPositions_x                 0x916B60
#define CListWnd__SetVScrollPos_x                                  0x916450

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x777E70
#define CMapViewWnd__GetWorldCoordinates_x                         0x776580
#define CMapViewWnd__HandleLButtonDown_x                           0x7735C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x798260
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x798B40
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x799070
#define CMerchantWnd__SelectRecoverySlot_x                         0x79C020
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x796DD0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A1BF0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x797E70

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89CA10
#define CPacketScrambler__hton_x                                   0x89CA00

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x931500
#define CSidlManager__FindScreenPieceTemplate_x                    0x931910
#define CSidlManager__FindScreenPieceTemplate1_x                   0x931700
#define CSidlManager__CreateLabel_x                                0x7F9E00
#define CSidlManager__CreateXWndFromTemplate_x                     0x934870
#define CSidlManager__CreateXWndFromTemplate1_x                    0x934A40
#define CSidlManager__CreateXWnd_x                                 0x7F9D30
#define CSidlManager__CreateHotButtonWnd_x                         0x7FA2F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x92DFE0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x92DEE0
#define CSidlScreenWnd__ConvertToRes_x                             0x957100
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x92D9D0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x92D6C0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x92D790
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x92D860
#define CSidlScreenWnd__DrawSidlPiece_x                            0x92E480
#define CSidlScreenWnd__EnableIniStorage_x                         0x92E950
#define CSidlScreenWnd__GetSidlPiece_x                             0x92E670
#define CSidlScreenWnd__Init1_x                                    0x92D2C0
#define CSidlScreenWnd__LoadIniInfo_x                              0x92E9A0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x92F4E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92C6E0
#define CSidlScreenWnd__StoreIniInfo_x                             0x92F060
#define CSidlScreenWnd__StoreIniVis_x                              0x92F3C0
#define CSidlScreenWnd__WndNotification_x                          0x92E390
#define CSidlScreenWnd__GetChildItem_x                             0x92E8D0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x91E070
#define CSidlScreenWnd__m_layoutCopy_x                             0x15D5AF0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x696540
#define CSkillMgr__GetSkillCap_x                                   0x696720
#define CSkillMgr__GetNameToken_x                                  0x695CC0
#define CSkillMgr__IsActivatedSkill_x                              0x695E00
#define CSkillMgr__IsCombatSkill_x                                 0x695D40

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x93E1E0
#define CSliderWnd__SetValue_x                                     0x93E050
#define CSliderWnd__SetNumTicks_x                                  0x93E0B0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7FFFC0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x946B30
#define CStmlWnd__ParseSTML_x                                      0x947E80
#define CStmlWnd__CalculateHSBRange_x                              0x947C60
#define CStmlWnd__CalculateVSBRange_x                              0x947BD0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94BF90
#define CStmlWnd__FastForwardToEndOfTag_x                          0x94CC20
#define CStmlWnd__ForceParseNow_x                                  0x947120
#define CStmlWnd__GetNextTagPiece_x                                0x94BEF0
#define CStmlWnd__GetSTMLText_x                                    0x50AA10
#define CStmlWnd__GetVisibleText_x                                 0x947140
#define CStmlWnd__InitializeWindowVariables_x                      0x94CA70
#define CStmlWnd__MakeStmlColorTag_x                               0x9461A0
#define CStmlWnd__MakeWndNotificationTag_x                         0x946210
#define CStmlWnd__SetSTMLText_x                                    0x945250
#define CStmlWnd__StripFirstSTMLLines_x                            0x94DD20
#define CStmlWnd__UpdateHistoryString_x                            0x94CE30

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9443A0
#define CTabWnd__DrawCurrentPage_x                                 0x944AD0
#define CTabWnd__DrawTab_x                                         0x9447F0
#define CTabWnd__GetCurrentPage_x                                  0x943BA0
#define CTabWnd__GetPageInnerRect_x                                0x943DE0
#define CTabWnd__GetTabInnerRect_x                                 0x943D20
#define CTabWnd__GetTabRect_x                                      0x943BD0
#define CTabWnd__InsertPage_x                                      0x943FF0
#define CTabWnd__RemovePage_x                                      0x944160
#define CTabWnd__SetPage_x                                         0x943E60
#define CTabWnd__SetPageRect_x                                     0x9442E0
#define CTabWnd__UpdatePage_x                                      0x9446B0
#define CTabWnd__GetPageFromTabIndex_x                             0x944730
#define CTabWnd__GetCurrentTabIndex_x                              0x943B90

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75D190
#define CPageWnd__SetTabText_x                                     0x9436E0
#define CPageWnd__FlashTab_x                                       0x943740

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8F10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91AF30
#define CTextureFont__GetTextExtent_x                              0x91B0F0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6AA7A0
#define CHtmlComponentWnd__ValidateUri_x                           0x73B540
#define CHtmlWnd__SetClientCallbacks_x                             0x636030
#define CHtmlWnd__AddObserver_x                                    0x636050
#define CHtmlWnd__RemoveObserver_x                                 0x6360B0
#define Window__getProgress_x                                      0x851F00
#define Window__getStatus_x                                        0x851F20
#define Window__getURI_x                                           0x851F30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x953F10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x907F50

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9760
#define CXStr__CXStr1_x                                            0x8428B0
#define CXStr__CXStr3_x                                            0x8EFB40
#define CXStr__dCXStr_x                                            0x477FB0
#define CXStr__operator_equal_x                                    0x8EFD70
#define CXStr__operator_equal1_x                                   0x8EFDB0
#define CXStr__operator_plus_equal1_x                              0x8F0840
#define CXStr__SetString_x                                         0x8F2730
#define CXStr__operator_char_p_x                                   0x8F02B0
#define CXStr__GetChar_x                                           0x8F2080
#define CXStr__Delete_x                                            0x8F1930
#define CXStr__GetUnicode_x                                        0x8F20F0
#define CXStr__GetLength_x                                         0x47D200
#define CXStr__Mid_x                                               0x47D210
#define CXStr__Insert_x                                            0x8F2150
#define CXStr__FindNext_x                                          0x8F1DA0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93C470
#define CXWnd__BringToTop_x                                        0x921850
#define CXWnd__Center_x                                            0x9213D0
#define CXWnd__ClrFocus_x                                          0x9211F0
#define CXWnd__Destroy_x                                           0x921290
#define CXWnd__DoAllDrawing_x                                      0x91D800
#define CXWnd__DrawChildren_x                                      0x91D7D0
#define CXWnd__DrawColoredRect_x                                   0x91DC60
#define CXWnd__DrawTooltip_x                                       0x91C310
#define CXWnd__DrawTooltipAtPoint_x                                0x91C3D0
#define CXWnd__GetBorderFrame_x                                    0x91DAC0
#define CXWnd__GetChildWndAt_x                                     0x9218F0
#define CXWnd__GetClientClipRect_x                                 0x91FA70
#define CXWnd__GetScreenClipRect_x                                 0x91FB40
#define CXWnd__GetScreenRect_x                                     0x91FD10
#define CXWnd__GetRelativeRect_x                                   0x91FDE0
#define CXWnd__GetTooltipRect_x                                    0x91DCB0
#define CXWnd__GetWindowTextA_x                                    0x49CC40
#define CXWnd__IsActive_x                                          0x91E3F0
#define CXWnd__IsDescendantOf_x                                    0x920740
#define CXWnd__IsReallyVisible_x                                   0x920770
#define CXWnd__IsType_x                                            0x921F60
#define CXWnd__Move_x                                              0x9207D0
#define CXWnd__Move1_x                                             0x920880
#define CXWnd__ProcessTransition_x                                 0x921380
#define CXWnd__Refade_x                                            0x920B60
#define CXWnd__Resize_x                                            0x920E00
#define CXWnd__Right_x                                             0x921610
#define CXWnd__SetFocus_x                                          0x9211B0
#define CXWnd__SetFont_x                                           0x921220
#define CXWnd__SetKeyTooltip_x                                     0x921D80
#define CXWnd__SetMouseOver_x                                      0x91EC30
#define CXWnd__StartFade_x                                         0x920620
#define CXWnd__GetChildItem_x                                      0x921A60
#define CXWnd__SetParent_x                                         0x9204D0
#define CXWnd__Minimize_x                                          0x920E70

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x958180

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9247F0
#define CXWndManager__DrawWindows_x                                0x924810
#define CXWndManager__GetKeyboardFlags_x                           0x926F30
#define CXWndManager__HandleKeyboardMsg_x                          0x926AE0
#define CXWndManager__RemoveWnd_x                                  0x927160
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9276E0

// CDBStr
#define CDBStr__GetString_x                                        0x544FF0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BFE20
#define EQ_Character__Cur_HP_x                                     0x4D2E70
#define EQ_Character__Cur_Mana_x                                   0x4DA5C0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C2E90
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B35A0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B36F0
#define EQ_Character__GetHPRegen_x                                 0x4E04C0
#define EQ_Character__GetEnduranceRegen_x                          0x4E0AC0
#define EQ_Character__GetManaRegen_x                               0x4E0F00
#define EQ_Character__Max_Endurance_x                              0x65C630
#define EQ_Character__Max_HP_x                                     0x4D2CA0
#define EQ_Character__Max_Mana_x                                   0x65C430
#define EQ_Character__doCombatAbility_x                            0x65EA10
#define EQ_Character__UseSkill_x                                   0x4E2D00
#define EQ_Character__GetConLevel_x                                0x6552A0
#define EQ_Character__IsExpansionFlag_x                            0x5B8AA0
#define EQ_Character__TotalEffect_x                                0x4C6C30
#define EQ_Character__GetPCSpellAffect_x                           0x4C3BE0
#define EQ_Character__SpellDuration_x                              0x4C3710
#define EQ_Character__MySpellDuration_x                            0x4B1ED0
#define EQ_Character__GetAdjustedSkill_x                           0x4D5BF0
#define EQ_Character__GetBaseSkill_x                               0x4D6B90
#define EQ_Character__CanUseItem_x                                 0x4DA8D0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BB9B0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6729D0

//PcClient
#define PcClient__vftable_x                                        0xAEEF30
#define PcClient__PcClient_x                                       0x652A00

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BA850
#define CCharacterListWnd__EnterWorld_x                            0x4BA220
#define CCharacterListWnd__Quit_x                                  0x4B9F70
#define CCharacterListWnd__UpdateList_x                            0x4BA410

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6371F0
#define EQ_Item__CreateItemTagString_x                             0x896000
#define EQ_Item__IsStackable_x                                     0x89ACA0
#define EQ_Item__GetImageNum_x                                     0x897B80
#define EQ_Item__CreateItemClient_x                                0x636430
#define EQ_Item__GetItemValue_x                                    0x898E80
#define EQ_Item__ValueSellMerchant_x                               0x89C5F0
#define EQ_Item__IsKeyRingItem_x                                   0x89A5C0
#define EQ_Item__CanGoInBag_x                                      0x637310
#define EQ_Item__IsEmpty_x                                         0x89A100
#define EQ_Item__GetMaxItemCount_x                                 0x899290
#define EQ_Item__GetHeldItem_x                                     0x897A50
#define EQ_Item__GetAugmentFitBySlot_x                             0x895860

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x563AB0
#define EQ_LoadingS__Array_x                                       0xC0EC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65CF30
#define EQ_PC__GetAlternateAbilityId_x                             0x8A5630
#define EQ_PC__GetCombatAbility_x                                  0x8A5CA0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A5D10
#define EQ_PC__GetItemRecastTimer_x                                0x65EF90
#define EQ_PC__HasLoreItem_x                                       0x655AB0
#define EQ_PC__AlertInventoryChanged_x                             0x654BD0
#define EQ_PC__GetPcZoneClient_x                                   0x6819C0
#define EQ_PC__RemoveMyAffect_x                                    0x6621C0
#define EQ_PC__GetKeyRingItems_x                                   0x8A65A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A6330
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A68A0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BEF00
#define EQItemList__add_object_x                                   0x5EC3D0
#define EQItemList__add_item_x                                     0x5BF460
#define EQItemList__delete_item_x                                  0x5BF4B0
#define EQItemList__FreeItemList_x                                 0x5BF3B0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x541B20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6742D0
#define EQPlayer__dEQPlayer_x                                      0x667650
#define EQPlayer__DoAttack_x                                       0x67C160
#define EQPlayer__EQPlayer_x                                       0x667D10
#define EQPlayer__SetNameSpriteState_x                             0x66BFE0
#define EQPlayer__SetNameSpriteTint_x                              0x66CEC0
#define PlayerBase__HasProperty_j_x                                0x986E20
#define EQPlayer__IsTargetable_x                                   0x9872C0
#define EQPlayer__CanSee_x                                         0x987120
#define EQPlayer__CanSee1_x                                        0x9871F0
#define PlayerBase__GetVisibilityLineSegment_x                     0x986EE0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67F460
#define PlayerZoneClient__GetLevel_x                               0x681A00
#define PlayerZoneClient__IsValidTeleport_x                        0x5ED550
#define PlayerZoneClient__LegalPlayerRace_x                        0x55C850

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x677080
#define EQPlayerManager__GetSpawnByName_x                          0x677130
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6771C0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63A870
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63A8F0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63A930
#define KeypressHandler__ClearCommandStateArray_x                  0x63BD20
#define KeypressHandler__HandleKeyDown_x                           0x63BD40
#define KeypressHandler__HandleKeyUp_x                             0x63BDE0
#define KeypressHandler__SaveKeymapping_x                          0x63C230

// MapViewMap 
#define MapViewMap__Clear_x                                        0x773CE0
#define MapViewMap__SaveEx_x                                       0x7770A0
#define MapViewMap__SetZoom_x                                      0x77B760

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B9A20

// StringTable 
#define StringTable__getString_x                                   0x8B47F0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x661E30
#define PcZoneClient__RemovePetEffect_x                            0x662460
#define PcZoneClient__HasAlternateAbility_x                        0x65C260
#define PcZoneClient__GetCurrentMod_x                              0x4E5E20
#define PcZoneClient__GetModCap_x                                  0x4E5D20
#define PcZoneClient__CanEquipItem_x                               0x65C910
#define PcZoneClient__GetItemByID_x                                0x65F400
#define PcZoneClient__GetItemByItemClass_x                         0x65F550
#define PcZoneClient__RemoveBuffEffect_x                           0x662480
#define PcZoneClient__BandolierSwap_x                              0x65D4E0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65EF30

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F20D0

//IconCache
#define IconCache__GetIcon_x                                       0x715810

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70D330
#define CContainerMgr__CloseContainer_x                            0x70D600
#define CContainerMgr__OpenExperimentContainer_x                   0x70E080

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CC550

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62F370

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76A290
#define CLootWnd__RequestLootSlot_x                                0x769570

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58B560
#define EQ_Spell__SpellAffects_x                                   0x58B9D0
#define EQ_Spell__SpellAffectBase_x                                0x58B790
#define EQ_Spell__IsStackable_x                                    0x4CA8C0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CA740
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7A90
#define EQ_Spell__IsSPAStacking_x                                  0x58C820
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58BD30
#define EQ_Spell__IsNoRemove_x                                     0x4CA8A0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58C830
#define __IsResEffectSpell_x                                       0x4C9B70

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD170

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C4060

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x813370
#define CTargetWnd__WndNotification_x                              0x812BB0
#define CTargetWnd__RefreshTargetBuffs_x                           0x812E80
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x811D10

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8179E0
#define CTaskWnd__ConfirmAbandonTask_x                             0x81A620

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53F570
#define CTaskManager__HandleMessage_x                              0x53D9F0
#define CTaskManager__GetTaskStatus_x                              0x53F620
#define CTaskManager__GetElementDescription_x                      0x53F6A0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5866C0
#define EqSoundManager__PlayScriptMp3_x                            0x586980
#define EqSoundManager__SoundAssistPlay_x                          0x69A480
#define EqSoundManager__WaveInstancePlay_x                         0x6999F0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x530B40

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x942BF0
#define CTextureAnimation__Draw_x                                  0x942DF0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x93EB40

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56B6B0
#define CAltAbilityData__GetMercMaxRank_x                          0x56B640
#define CAltAbilityData__GetMaxRank_x                              0x560A00

//CTargetRing
#define CTargetRing__Cast_x                                        0x62D490

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CA720
#define CharacterBase__CreateItemGlobalIndex_x                     0x5178F0
#define CharacterBase__CreateItemIndex_x                           0x6355E0
#define CharacterBase__GetItemPossession_x                         0x503460
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CC6B0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CC710
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F4340
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F4B70
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F4C20

//messages
#define msg_spell_worn_off_x                                       0x5B0AE0
#define msg_new_text_x                                             0x5A5470
#define __msgTokenTextParam_x                                      0x5B2D80
#define msgTokenText_x                                             0x5B2FD0

//SpellManager
#define SpellManager__vftable_x                                    0xAD72BC
#define SpellManager__SpellManager_x                               0x69D7A0
#define Spellmanager__LoadTextSpells_x                             0x69E090
#define SpellManager__GetSpellByGroupAndRank_x                     0x69D970

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98ADD0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x517F40
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B6F70
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64E140
#define ItemGlobalIndex__IsValidIndex_x                            0x517FD0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C4A00
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C4C80

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x762AE0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x711A10
#define CCursorAttachment__AttachToCursor1_x                       0x711A50
#define CCursorAttachment__Deactivate_x                            0x712A40

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x935890
#define CSidlManagerBase__CreatePageWnd_x                          0x935090
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x931320
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9312B0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9528B0
#define CEQSuiteTextureLoader__GetTexture_x                        0x952570

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x514E40
#define CFindItemWnd__WndNotification_x                            0x515920
#define CFindItemWnd__Update_x                                     0x516490
#define CFindItemWnd__PickupSelectedItem_x                         0x514660

//IString
#define IString__Append_x                                          0x504C80

//Camera
#define CDisplay__cameraType_x                                     0xDE6890
#define EverQuest__Cameras_x                                       0xEA1B0C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51D890
#define LootFiltersManager__GetItemFilterData_x                    0x51D190
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51D1C0
#define LootFiltersManager__SetItemLootFilter_x                    0x51D3E0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BA380

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x990A20
#define CResolutionHandler__GetWindowedStyle_x                     0x694E90

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x709FE0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D9F10
#define CDistillerInfo__Instance_x                                 0x8D9EB0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x728EB0
#define CGroupWnd__UpdateDisplay_x                                 0x728200

//ItemBase
#define ItemBase__IsLore_x                                         0x89A670
#define ItemBase__IsLoreEquipped_x                                 0x89A6E0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EC330
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EC470
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EC4D0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68A0E0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68DA40

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50B040

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F7300
#define FactionManagerClient__HandleFactionMessage_x               0x4F7970
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F7F70
#define FactionManagerClient__GetMaxFaction_x                      0x4F7F8F
#define FactionManagerClient__GetMinFaction_x                      0x4F7F40

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x503430

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x919F80

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BF20

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x503690

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56AB30

//CTargetManager
#define CTargetManager__Get_x                                      0x6A1050

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68A0E0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8CD0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BF350

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF3F1A0

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BDB90
#define CAAWnd__UpdateSelected_x                                   0x6BA400
#define CAAWnd__Update_x                                           0x6BCEB0

//CXRect
#define CXRect__operator_and_x                                     0x71FF90

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x482EA0

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
