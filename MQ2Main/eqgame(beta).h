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
#if defined(EQBETA)
#include "eqgame-private(beta).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Dec  5 2018"
#define __ExpectedVersionTime                                     "04:21:02"
#define __ActualVersionDate_x                                      0xAD116C
#define __ActualVersionTime_x                                      0xAD1160

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x615850
#define __MemChecker1_x                                            0x8EA780
#define __MemChecker2_x                                            0x6A4DC0
#define __MemChecker3_x                                            0x6A4D10
#define __MemChecker4_x                                            0x841DD0
#define __EncryptPad0_x                                            0xC05340
#define __EncryptPad1_x                                            0xC635D0
#define __EncryptPad2_x                                            0xC15EC8
#define __EncryptPad3_x                                            0xC15AC8
#define __EncryptPad4_x                                            0xC53E40
#define __EncryptPad5_x                                            0x1034AE0
#define __AC1_x                                                    0x7FE426
#define __AC2_x                                                    0x5D05CF
#define __AC3_x                                                    0x5D745F
#define __AC4_x                                                    0x5DB280
#define __AC5_x                                                    0x5E14E0
#define __AC6_x                                                    0x5E5AB6
#define __AC7_x                                                    0x5D0040
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E8A344

// Direct Input
#define DI8__Main_x                                                0x1034B04
#define DI8__Keyboard_x                                            0x1034B08
#define DI8__Mouse_x                                               0xF2A448
#define DI8__Mouse_Copy_x                                          0xE881A4
#define DI8__Mouse_Check_x                                         0xF2A76C
#define __AutoSkillArray_x                                         0xE890BC
#define __Attack_x                                                 0xF26EC3
#define __Autofire_x                                               0xF26EC4
#define __BindList_x                                               0xBF3F20
#define g_eqCommandStates_x                                        0xBF4C90
#define __Clicks_x                                                 0xE8825C
#define __CommandList_x                                            0xBF5848
#define __CurrentMapLabel_x                                        0x103CA6C
#define __CurrentSocial_x                                          0xBDE730
#define __DoAbilityList_x                                          0xEBE9E4
#define __do_loot_x                                                0x59DBA0
#define __DrawHandler_x                                            0x16B9440
#define __GroupCount_x                                             0xE78452
#define __Guilds_x                                                 0xE7E9B0
#define __gWorld_x                                                 0xE7ACD4
#define __HWnd_x                                                   0xF2A44C
#define __heqmain_x                                                0x1034AC8
#define __InChatMode_x                                             0xE8818C
#define __LastTell_x                                               0xE8A0E0
#define __LMouseHeldTime_x                                         0xE882C8
#define __Mouse_x                                                  0x1034AEC
#define __MouseLook_x                                              0xE88222
#define __MouseEventTime_x                                         0xF27978
#define __gpbCommandEvent_x                                        0xE7A774
#define __NetStatusToggle_x                                        0xE88225
#define __PCNames_x                                                0xE8969C
#define __RangeAttackReady_x                                       0xE893A0
#define __RMouseHeldTime_x                                         0xE882C4
#define __RunWalkState_x                                           0xE88190
#define __ScreenMode_x                                             0xDC6A98
#define __ScreenX_x                                                0xE88144
#define __ScreenY_x                                                0xE88140
#define __ScreenXMax_x                                             0xE88148
#define __ScreenYMax_x                                             0xE8814C
#define __ServerHost_x                                             0xE7A9AB
#define __ServerName_x                                             0xEBE9A4
#define __ShiftKeyDown_x                                           0xE8881C
#define __ShowNames_x                                              0xE8955C
#define __Socials_x                                                0xEBEAA4
#define __SubscriptionType_x                                       0x107E5BC
#define __TargetAggroHolder_x                                      0x103F428
#define __ZoneType_x                                               0xE88620
#define __GroupAggro_x                                             0x103F468
#define __LoginName_x                                              0x103535C
#define __Inviter_x                                                0xF26E40
#define __AttackOnAssist_x                                         0xE89518
#define __UseTellWindows_x                                         0xE89834
#define __gfMaxZoomCameraDistance_x                                0xAC6648
#define __gfMaxCameraDistance_x                                    0xAF3A98
#define __pulAutoRun_x                                             0xE88240
#define __pulForward_x                                             0xE8986C
#define __pulBackward_x                                            0xE89870
#define __pulTurnRight_x                                           0xE89874
#define __pulTurnLeft_x                                            0xE89878
#define __pulStrafeLeft_x                                          0xE8987C
#define __pulStrafeRight_x                                         0xE89880
//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE7AD48
#define instEQZoneInfo_x                                           0xE88418
#define instKeypressHandler_x                                      0xF27928
#define pinstActiveBanker_x                                        0xE7A854
#define pinstActiveCorpse_x                                        0xE7A84C
#define pinstActiveGMaster_x                                       0xE7A850
#define pinstActiveMerchant_x                                      0xE7A848
#define pinstAggroInfo_x                                           0xC79E08
#define pinstAltAdvManager_x                                       0xDC76F0
#define pinstAuraMgr_x                                             0xC95988
#define pinstBandageTarget_x                                       0xE7A864
#define pinstCamActor_x                                            0xDC6A8C
#define pinstCDBStr_x                                              0xDC6424
#define pinstCDisplay_x                                            0xE7AAB4
#define pinstCEverQuest_x                                          0x1034C20
#define pinstEverQuestInfo_x                                       0xE88138
#define pinstCharData_x                                            0xE7ACE8
#define pinstCharSpawn_x                                           0xE7A89C
#define pinstControlledMissile_x                                   0xE7ACD8
#define pinstControlledPlayer_x                                    0xE7A89C
#define pinstCResolutionHandler_x                                  0x16B9670
#define pinstCSidlManager_x                                        0x16B8504
#define pinstCXWndManager_x                                        0x16B84F8
#define instDynamicZone_x                                          0xE7E888
#define pinstDZMember_x                                            0xE7E998
#define pinstDZTimerInfo_x                                         0xE7E99C
#define pinstEQItemList_x                                          0xE76F38
#define pinstEQObjectList_x                                        0xE78128
#define instEQMisc_x                                               0xDC6360
#define pinstEQSoundManager_x                                      0xDC7F50
#define pinstEQSpellStrings_x                                      0xC87F40
#define instExpeditionLeader_x                                     0xE7E8D2
#define instExpeditionName_x                                       0xE7E912
#define pinstGroup_x                                               0xE7844E
#define pinstImeManager_x                                          0x16B84FC
#define pinstLocalPlayer_x                                         0xE7A844
#define pinstMercenaryData_x                                       0xF28124
#define pinstMercenaryStats_x                                      0x103F574
#define pinstMercAltAbilities_x                                    0xDC7CC0
#define pinstModelPlayer_x                                         0xE7A85C
#define pinstPCData_x                                              0xE7ACE8
#define pinstRealEstateItems_x                                     0xF29608
#define pinstSkillMgr_x                                            0xF296D8
#define pinstSpawnManager_x                                        0xF28CC8
#define pinstSpellManager_x                                        0xF298B0
#define pinstSpellSets_x                                           0xF1FAEC
#define pinstStringTable_x                                         0xE7A648
#define pinstSwitchManager_x                                       0xE782E8
#define pinstTarget_x                                              0xE7A898
#define pinstTargetObject_x                                        0xE7A8A4
#define pinstTargetSwitch_x                                        0xE7AD3C
#define pinstTaskMember_x                                          0xDC61F4
#define pinstTrackTarget_x                                         0xE7A8A0
#define pinstTradeTarget_x                                         0xE7A858
#define instTributeActive_x                                        0xDC6385
#define pinstViewActor_x                                           0xDC6A88
#define pinstWorldData_x                                           0xE7A764
#define pinstZoneAddr_x                                            0xE886B8
#define pinstPlayerPath_x                                          0xF28D60
#define pinstTargetIndicator_x                                     0xF29B18
#define pinstCTargetManager_x                                      0xF29BB0
#define EQObject_Top_x                                             0xE7A804

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDC6548
#define pinstCAchievementsWnd_x                                    0xDC6538
#define pinstCActionsWnd_x                                         0xDC65AC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDC6A4C
#define pinstCAdvancedLootWnd_x                                    0xDC6590
#define pinstCAdventureLeaderboardWnd_x                            0x1036240
#define pinstCAdventureRequestWnd_x                                0x10362F0
#define pinstCAdventureStatsWnd_x                                  0x10363A0
#define pinstCAggroMeterWnd_x                                      0xDC6ACC
#define pinstCAlarmWnd_x                                           0xDC6B38
#define pinstCAlertHistoryWnd_x                                    0xDC64F0
#define pinstCAlertStackWnd_x                                      0xDC6AE0
#define pinstCAlertWnd_x                                           0xDC6B04
#define pinstCAltStorageWnd_x                                      0x1036700
#define pinstCAudioTriggersWindow_x                                0xC7A298
#define pinstCAuraWnd_x                                            0xDC6AC8
#define pinstCAvaZoneWnd_x                                         0xDC64F8
#define pinstCBandolierWnd_x                                       0xDC6B0C
#define pinstCBankWnd_x                                            0xDC64F4
#define pinstCBarterMerchantWnd_x                                  0x1037940
#define pinstCBarterSearchWnd_x                                    0x10379F0
#define pinstCBarterWnd_x                                          0x1037AA0
#define pinstCBazaarConfirmationWnd_x                              0xDC6ADC
#define pinstCBazaarSearchWnd_x                                    0xDC6634
#define pinstCBazaarWnd_x                                          0xDC6B10
#define pinstCBlockedBuffWnd_x                                     0xDC64D8
#define pinstCBlockedPetBuffWnd_x                                  0xDC6504
#define pinstCBodyTintWnd_x                                        0xDC6AAC
#define pinstCBookWnd_x                                            0xDC6B30
#define pinstCBreathWnd_x                                          0xDC654C
#define pinstCBuffWindowNORMAL_x                                   0xDC6D4C
#define pinstCBuffWindowSHORT_x                                    0xDC6D50
#define pinstCBugReportWnd_x                                       0xDC6540
#define pinstCButtonWnd_x                                          0x16B8728
#define pinstCCastingWnd_x                                         0xDC653C
#define pinstCCastSpellWnd_x                                       0xDC6A48
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDC6550
#define pinstCChatWindowManager_x                                  0x1038560
#define pinstCClaimWnd_x                                           0x10386B8
#define pinstCColorPickerWnd_x                                     0xDC6580
#define pinstCCombatAbilityWnd_x                                   0xDC6AD8
#define pinstCCombatSkillsSelectWnd_x                              0xDC65A8
#define pinstCCompassWnd_x                                         0xDC6A7C
#define pinstCConfirmationDialog_x                                 0x103D5B8
#define pinstCContainerMgr_x                                       0xDC6AE4
#define pinstCContextMenuManager_x                                 0x16B84B8
#define pinstCCursorAttachment_x                                   0xDC6534
#define pinstCDistillerInfo_x                                      0x103BFC4
#define pinstCDynamicZoneWnd_x                                     0x1038C80
#define pinstCEditLabelWnd_x                                       0xDC6D40
#define pinstCEQMainWnd_x                                          0x1038EC8
#define pinstCEventCalendarWnd_x                                   0xDC6568
#define pinstCExtendedTargetWnd_x                                  0xDC6ABC
#define pinstCFacePick_x                                           0xDC6578
#define pinstCFactionWnd_x                                         0xDC6530
#define pinstCFellowshipWnd_x                                      0x10390C8
#define pinstCFileSelectionWnd_x                                   0xDC657C
#define pinstCFindItemWnd_x                                        0xDC6B2C
#define pinstCFindLocationWnd_x                                    0x1039220
#define pinstCFriendsWnd_x                                         0xDC65CC
#define pinstCGemsGameWnd_x                                        0xDC6B08
#define pinstCGiveWnd_x                                            0xDC6B34
#define pinstCGroupSearchFiltersWnd_x                              0xDC6AEC
#define pinstCGroupSearchWnd_x                                     0x1039618
#define pinstCGroupWnd_x                                           0x10396C8
#define pinstCGuildBankWnd_x                                       0xE894FC
#define pinstCGuildCreationWnd_x                                   0x1039828
#define pinstCGuildMgmtWnd_x                                       0x10398D8
#define pinstCharacterCreation_x                                   0xDC6AD0
#define pinstCHelpWnd_x                                            0xDC6A80
#define pinstCHeritageSelectionWnd_x                               0xDC658C
#define pinstCHotButtonWnd_x                                       0x103BA30
#define pinstCHotButtonWnd1_x                                      0x103BA30
#define pinstCHotButtonWnd2_x                                      0x103BA34
#define pinstCHotButtonWnd3_x                                      0x103BA38
#define pinstCHotButtonWnd4_x                                      0x103BA3C
#define pinstCIconSelectionWnd_x                                   0xDC6514
#define pinstCInspectWnd_x                                         0xDC6510
#define pinstCInventoryWnd_x                                       0xDC6B14
#define pinstCInvSlotMgr_x                                         0xDC6AB0
#define pinstCItemDisplayManager_x                                 0x103BFC0
#define pinstCItemExpTransferWnd_x                                 0x103C0F0
#define pinstCItemOverflowWnd_x                                    0xDC6638
#define pinstCJournalCatWnd_x                                      0xDC6598
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDC655C
#define pinstCKeyRingWnd_x                                         0xDC64CC
#define pinstCLargeDialogWnd_x                                     0x103E238
#define pinstCLayoutCopyWnd_x                                      0x103C440
#define pinstCLFGuildWnd_x                                         0x103C4F0
#define pinstCLoadskinWnd_x                                        0xDC6B18
#define pinstCLootFiltersCopyWnd_x                                 0xC962B8
#define pinstCLootFiltersWnd_x                                     0xDC6B28
#define pinstCLootSettingsWnd_x                                    0xDC6D48
#define pinstCLootWnd_x                                            0xDC656C
#define pinstCMailAddressBookWnd_x                                 0xDC6508
#define pinstCMailCompositionWnd_x                                 0xDC64E0
#define pinstCMailIgnoreListWnd_x                                  0xDC650C
#define pinstCMailWnd_x                                            0xDC64C0
#define pinstCManageLootWnd_x                                      0xDC7B68
#define pinstCMapToolbarWnd_x                                      0xDC6B20
#define pinstCMapViewWnd_x                                         0xDC6AF4
#define pinstCMarketplaceWnd_x                                     0xDC6570
#define pinstCMerchantWnd_x                                        0xDC65A4
#define pinstCMIZoneSelectWnd_x                                    0x103CD28
#define pinstCMusicPlayerWnd_x                                     0xDC64C8
#define pinstCNameChangeMercWnd_x                                  0xDC6AB4
#define pinstCNameChangePetWnd_x                                   0xDC6A74
#define pinstCNameChangeWnd_x                                      0xDC6554
#define pinstCNoteWnd_x                                            0xDC6A54
#define pinstCObjectPreviewWnd_x                                   0xDC6594
#define pinstCOptionsWnd_x                                         0xDC6B24
#define pinstCPetInfoWnd_x                                         0xDC64E4
#define pinstCPetitionQWnd_x                                       0xDC65B0
//#define pinstCPlayerCustomizationWnd_x                           0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDC6AA4
#define pinstCPlayerWnd_x                                          0xDC65B4
#define pinstCPopupWndManager_x                                    0x103D5B8
#define pinstCProgressionSelectionWnd_x                            0x103D668
#define pinstCPurchaseGroupWnd_x                                   0xDC6A40
#define pinstCPurchaseWnd_x                                        0xDC65A0
#define pinstCPvPLeaderboardWnd_x                                  0x103D718
#define pinstCPvPStatsWnd_x                                        0x103D7C8
#define pinstCQuantityWnd_x                                        0xDC651C
#define pinstCRaceChangeWnd_x                                      0xDC6574
#define pinstCRaidOptionsWnd_x                                     0xDC6AF0
#define pinstCRaidWnd_x                                            0xDC6520
#define pinstCRealEstateItemsWnd_x                                 0xDC6544
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDC6560
#define pinstCRealEstateManageWnd_x                                0xDC6D54
#define pinstCRealEstateNeighborhoodWnd_x                          0xDC64D0
#define pinstCRealEstatePlotSearchWnd_x                            0xDC64FC
#define pinstCRealEstatePurchaseWnd_x                              0xDC6524
#define pinstCRespawnWnd_x                                         0xDC6AE8
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDC6AC0
#define pinstCSendMoneyWnd_x                                       0xDC6D44
#define pinstCServerListWnd_x                                      0xDC64EC
#define pinstCSkillsSelectWnd_x                                    0xDC6584
#define pinstCSkillsWnd_x                                          0xDC6564
#define pinstCSocialEditWnd_x                                      0xDC652C
#define pinstCSocialWnd_x                                          0xDC6AC4
#define pinstCSpellBookWnd_x                                       0xDC6AB8
#define pinstCStoryWnd_x                                           0xDC6A50
#define pinstCTargetOfTargetWnd_x                                  0x103F5F8
#define pinstCTargetWnd_x                                          0xDC64DC
#define pinstCTaskOverlayWnd_x                                     0xDC6500
#define pinstCTaskSelectWnd_x                                      0x103F750
#define pinstCTaskManager_x                                        0xC96AB8
#define pinstCTaskTemplateSelectWnd_x                              0x103F800
#define pinstCTaskWnd_x                                            0x103F8B0
#define pinstCTextEntryWnd_x                                       0xDC6A84
#define pinstCTextOverlay_x                                        0xC7A5A8
#define pinstCTimeLeftWnd_x                                        0xDC6588
#define pinstCTipWndCONTEXT_x                                      0x103FAB4
#define pinstCTipWndOFDAY_x                                        0x103FAB0
#define pinstCTitleWnd_x                                           0x103FB60
#define pinstCTrackingWnd_x                                        0xDC64E8
#define pinstCTradeskillWnd_x                                      0x103FCC8
#define pinstCTradeWnd_x                                           0xDC6AA8
#define pinstCTrainWnd_x                                           0xDC6518
#define pinstCTributeBenefitWnd_x                                  0x103FEC8
#define pinstCTributeMasterWnd_x                                   0x103FF78
#define pinstCTributeTrophyWnd_x                                   0x1040028
#define pinstCVideoModesWnd_x                                      0xDC6AD4
#define pinstCVoiceMacroWnd_x                                      0xF2A0E0
#define pinstCVoteResultsWnd_x                                     0xDC6A44
#define pinstCVoteWnd_x                                            0xDC65B8
#define pinstCWebManager_x                                         0xF2A244
#define pinstCZoneGuideWnd_x                                       0xDC64C4
#define pinstCZonePathWnd_x                                        0xDC64D4

#define pinstEQSuiteTextureLoader_x                                0xC650A0
#define pinstItemIconCache_x                                       0x1038E80
#define pinstLootFiltersManager_x                                  0xC96368
#define pinstRewardSelectionWnd_x                                  0x103DF10

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC15ABC
#define __CastRay_x                                                0x5990C0
#define __CastRay2_x                                               0x599110
#define __ConvertItemTags_x                                        0x5B3D40
#define __CrashHandler_x                                           0x84B700
#define __EQGetTime_x                                              0x8EA270
#define __ExecuteCmd_x                                             0x591A40
#define __FixHeading_x                                             0x97AF10
#define __get_bearing_x                                            0x598C10
#define __get_melee_range_x                                        0x599300
#define __GetAnimationCache_x                                      0x708750
#define __GetGaugeValueFromEQ_x                                    0x7FCC30
#define __GetLabelFromEQ_x                                         0x7FE3B0
#define __GetXTargetType_x                                         0x97C9E0
#define __HeadingDiff_x                                            0x97AF80
#define __HelpPath_x                                               0xF27594
#define __LoadFrontEnd_x                                           0x6A0C20
#define __NewUIINI_x                                               0x7FC900
#define __pCrashHandler_x                                          0x105D418
#define __ProcessGameEvents_x                                      0x5F6DB0
#define __ProcessMouseEvent_x                                      0x5F6570
#define __SaveColors_x                                             0x542D00
#define __STMLToText_x                                             0x91DE50
#define __ToggleKeyRingItem_x                                      0x505F90
#define CrashDetected_x                                            0x6A2710
#define DrawNetStatus_x                                            0x622DD0
#define Expansion_HoT_x                                            0xE89504
#define Teleport_Table_Size_x                                      0xE7A800
#define Teleport_Table_x                                           0xE78640
#define Util__FastTime_x                                           0x8E9E30
#define wwsCrashReportCheckForUploader_x                           0x84C1C0
#define wwsCrashReportPlatformLaunchUploader_x                     0x84E880
#define __HandleMouseWheel_x                                       0x6A4E70

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B760
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4945E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4943A0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54A7F0
#define AltAdvManager__IsAbilityReady_x                            0x549740
#define AltAdvManager__GetAAById_x                                 0x549940
#define AltAdvManager__CanTrainAbility_x                           0x5499B0
#define AltAdvManager__CanSeeAbility_x                             0x549D10

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7600
#define CharacterZoneClient__HasSkill_x                            0x4D22D0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D39F0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB930
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B80B0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D63C0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D64A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6580
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0410
#define CharacterZoneClient__BardCastBard_x                        0x4C3080
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8180
#define CharacterZoneClient__GetEffect_x                           0x4B7FF0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1410
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C14E0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1530
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1680
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1850

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CABA0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D8270

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x605680
#define CButtonWnd__CButtonWnd_x                                   0x91A240

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F70B0
#define CChatManager__InitContextMenu_x                            0x6F1150
#define CChatManager__FreeChatWindow_x                             0x6F5FC0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6FAA20
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F6E50

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x92EA80
#define CContextMenu__dCContextMenu_x                              0x92ECB0
#define CContextMenu__AddMenuItem_x                                0x92ECC0
#define CContextMenu__RemoveMenuItem_x                             0x92EFD0
#define CContextMenu__RemoveAllMenuItems_x                         0x92EFF0
#define CContextMenu__CheckMenuItem_x                              0x92F070
#define CContextMenu__SetMenuItem_x                                0x92EEF0
#define CContextMenu__AddSeparator_x                               0x92EE50

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x92F610
#define CContextMenuManager__RemoveMenu_x                          0x92F680
#define CContextMenuManager__PopupMenu_x                           0x92F740
#define CContextMenuManager__Flush_x                               0x92F5B0
#define CContextMenuManager__GetMenu_x                             0x496860

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CAAD0
#define CChatService__GetFriendName_x                              0x8CAAE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F7620
#define CChatWindow__Clear_x                                       0x6F8680
#define CChatWindow__WndNotification_x                             0x6F8BF0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x92BF10
#define CComboWnd__Draw_x                                          0x92B3F0
#define CComboWnd__GetCurChoice_x                                  0x92BD50
#define CComboWnd__GetListRect_x                                   0x92B8B0
#define CComboWnd__GetTextRect_x                                   0x92BF80
#define CComboWnd__InsertChoice_x                                  0x92BA40
#define CComboWnd__SetColors_x                                     0x92BA10
#define CComboWnd__SetChoice_x                                     0x92BD20
#define CComboWnd__GetItemCount_x                                  0x92BD60
#define CComboWnd__GetCurChoiceText_x                              0x92BDA0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x700920
#define CContainerWnd__vftable_x                                   0xADA410
#define CContainerWnd__SetContainer_x                              0x701E90

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x542AC0
#define CDisplay__GetClickedActor_x                                0x535A70
#define CDisplay__GetUserDefinedColor_x                            0x52E150
#define CDisplay__GetWorldFilePath_x                               0x5374C0
#define CDisplay__is3dON_x                                         0x532740
#define CDisplay__ReloadUI_x                                       0x53CBE0
#define CDisplay__WriteTextHD2_x                                   0x532520
#define CDisplay__TrueDistance_x                                   0x539120
#define CDisplay__SetViewActor_x                                   0x5353C0
#define CDisplay__GetFloorHeight_x                                 0x532800
#define CDisplay__SetRenderWindow_x                                0x531130
#define CDisplay__ToggleScreenshotMode_x                           0x534E90

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94E400

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9331B0
#define CEditWnd__GetCharIndexPt_x                                 0x9340B0
#define CEditWnd__GetDisplayString_x                               0x933F50
#define CEditWnd__GetHorzOffset_x                                  0x9327D0
#define CEditWnd__GetLineForPrintableChar_x                        0x9352B0
#define CEditWnd__GetSelStartPt_x                                  0x934360
#define CEditWnd__GetSTMLSafeText_x                                0x933D70
#define CEditWnd__PointFromPrintableChar_x                         0x934EE0
#define CEditWnd__SelectableCharFromPoint_x                        0x935050
#define CEditWnd__SetEditable_x                                    0x934430

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E4FE0
#define CEverQuest__ClickedPlayer_x                                0x5D7240
#define CEverQuest__CreateTargetIndicator_x                        0x5F4060
#define CEverQuest__DeleteTargetIndicator_x                        0x5F40F0
#define CEverQuest__DoTellWindow_x                                 0x4E34D0
#define CEverQuest__OutputTextToLog_x                              0x4E3700
#define CEverQuest__DropHeldItemOnGround_x                         0x5CCB00
#define CEverQuest__dsp_chat_x                                     0x4E3A90
#define CEverQuest__trimName_x                                     0x5F03E0
#define CEverQuest__Emote_x                                        0x5E57F0
#define CEverQuest__EnterZone_x                                    0x5DF890
#define CEverQuest__GetBodyTypeDesc_x                              0x5E9C90
#define CEverQuest__GetClassDesc_x                                 0x5EA2D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EA8D0
#define CEverQuest__GetDeityDesc_x                                 0x5F29B0
#define CEverQuest__GetLangDesc_x                                  0x5EAA90
#define CEverQuest__GetRaceDesc_x                                  0x5EA2B0
#define CEverQuest__InterpretCmd_x                                 0x5F2F80
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D0CF0
#define CEverQuest__LMouseUp_x                                     0x5CF070
#define CEverQuest__RightClickedOnPlayer_x                         0x5D15D0
#define CEverQuest__RMouseUp_x                                     0x5D0000
#define CEverQuest__SetGameState_x                                 0x5CC890
#define CEverQuest__UPCNotificationFlush_x                         0x5F02E0
#define CEverQuest__IssuePetCommand_x                              0x5EBE90
#define CEverQuest__ReportSuccessfulHit_x                          0x5E6BF0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x712930
#define CGaugeWnd__CalcLinesFillRect_x                             0x712990
#define CGaugeWnd__Draw_x                                          0x712040

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACCF0
#define CGuild__GetGuildName_x                                     0x4ABDD0
#define CGuild__GetGuildIndex_x                                    0x4AC160

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72DCE0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x605A40

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x73ACE0
#define CInvSlotMgr__MoveItem_x                                    0x739A00
#define CInvSlotMgr__SelectSlot_x                                  0x73ADB0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7382B0
#define CInvSlot__SliderComplete_x                                 0x736010
#define CInvSlot__GetItemBase_x                                    0x735990
#define CInvSlot__UpdateItem_x                                     0x735B00

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x73C700
#define CInvSlotWnd__CInvSlotWnd_x                                 0x73B9D0
#define CInvSlotWnd__HandleLButtonUp_x                             0x73C280

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F8E20
#define CItemDisplayWnd__UpdateStrings_x                           0x74A960
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7448F0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x744E00
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x74AF80
#define CItemDisplayWnd__AboutToShow_x                             0x74A5B0
#define CItemDisplayWnd__WndNotification_x                         0x74C4D0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8309B0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x750620

// CLabel 
#define CLabel__Draw_x                                             0x756070

// CListWnd
#define CListWnd__CListWnd_x                                       0x904680
#define CListWnd__dCListWnd_x                                      0x9049A0
#define CListWnd__AddColumn_x                                      0x908CB0
#define CListWnd__AddColumn1_x                                     0x908D00
#define CListWnd__AddLine_x                                        0x909090
#define CListWnd__AddString_x                                      0x908E90
#define CListWnd__CalculateFirstVisibleLine_x                      0x908A70
#define CListWnd__CalculateVSBRange_x                              0x908840
#define CListWnd__ClearSel_x                                       0x909870
#define CListWnd__ClearAllSel_x                                    0x9098D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90A2F0
#define CListWnd__Compare_x                                        0x908180
#define CListWnd__Draw_x                                           0x904AA0
#define CListWnd__DrawColumnSeparators_x                           0x907260
#define CListWnd__DrawHeader_x                                     0x9076C0
#define CListWnd__DrawItem_x                                       0x907AC0
#define CListWnd__DrawLine_x                                       0x9073C0
#define CListWnd__DrawSeparator_x                                  0x907300
#define CListWnd__EnableLine_x                                     0x906B50
#define CListWnd__EnsureVisible_x                                  0x90A210
#define CListWnd__ExtendSel_x                                      0x9097A0
#define CListWnd__GetColumnMinWidth_x                              0x906690
#define CListWnd__GetColumnWidth_x                                 0x906600
#define CListWnd__GetCurSel_x                                      0x905F90
#define CListWnd__GetItemAtPoint_x                                 0x906DC0
#define CListWnd__GetItemAtPoint1_x                                0x906E30
#define CListWnd__GetItemData_x                                    0x906010
#define CListWnd__GetItemHeight_x                                  0x9063D0
#define CListWnd__GetItemIcon_x                                    0x9061A0
#define CListWnd__GetItemRect_x                                    0x906C40
#define CListWnd__GetItemText_x                                    0x906050
#define CListWnd__GetSelList_x                                     0x909920
#define CListWnd__GetSeparatorRect_x                               0x907070
#define CListWnd__InsertLine_x                                     0x909480
#define CListWnd__RemoveLine_x                                     0x9095D0
#define CListWnd__SetColors_x                                      0x908810
#define CListWnd__SetColumnJustification_x                         0x908540
#define CListWnd__SetColumnWidth_x                                 0x908460
#define CListWnd__SetCurSel_x                                      0x9096E0
#define CListWnd__SetItemColor_x                                   0x909EC0
#define CListWnd__SetItemData_x                                    0x909E80
#define CListWnd__SetItemText_x                                    0x909AA0
#define CListWnd__ShiftColumnSeparator_x                           0x908600
#define CListWnd__Sort_x                                           0x908300
#define CListWnd__ToggleSel_x                                      0x909710

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x76B580
#define CMapViewWnd__GetWorldCoordinates_x                         0x769C90
#define CMapViewWnd__HandleLButtonDown_x                           0x766CF0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78E990
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x78F270
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x78F7A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7925E0
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x78D370
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x7981D0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78E5D0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x898840
#define CPacketScrambler__hton_x                                   0x898830

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x923410
#define CSidlManager__FindScreenPieceTemplate_x                    0x923820
#define CSidlManager__FindScreenPieceTemplate1_x                   0x923610
#define CSidlManager__CreateLabel_x                                0x7F02A0
#define CSidlManager__CreateXWndFromTemplate_x                     0x9268F0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x926AD0
#define CSidlManager__CreateXWnd_x                                 0x7F01D0
#define CSidlManager__CreateHotButtonWnd_x                         0x7F0790

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x91FF90
#define CSidlScreenWnd__CalculateVSBRange_x                        0x91FE90
#define CSidlScreenWnd__ConvertToRes_x                             0x9452A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x91F920
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x91F610
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x91F6E0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x91F7B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x920420
#define CSidlScreenWnd__EnableIniStorage_x                         0x9208F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x920610
#define CSidlScreenWnd__Init1_x                                    0x91F220
#define CSidlScreenWnd__LoadIniInfo_x                              0x920940
#define CSidlScreenWnd__LoadIniListWnd_x                           0x921470
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91E630
#define CSidlScreenWnd__StoreIniInfo_x                             0x920FF0
#define CSidlScreenWnd__StoreIniVis_x                              0x921350
#define CSidlScreenWnd__WndNotification_x                          0x920330
#define CSidlScreenWnd__GetChildItem_x                             0x920870
#define CSidlScreenWnd__HandleLButtonUp_x                          0x910100
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B8388

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x669E70
#define CSkillMgr__GetSkillCap_x                                   0x66A050
#define CSkillMgr__GetNameToken_x                                  0x669600

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x930420
#define CSliderWnd__SetValue_x                                     0x930290
#define CSliderWnd__SetNumTicks_x                                  0x9302F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F6090

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x937230
#define CStmlWnd__CalculateHSBRange_x                              0x9382A0
#define CStmlWnd__CalculateVSBRange_x                              0x938210
#define CStmlWnd__CanBreakAtCharacter_x                            0x93C610
#define CStmlWnd__FastForwardToEndOfTag_x                          0x93D2A0
#define CStmlWnd__ForceParseNow_x                                  0x9377D0
#define CStmlWnd__GetNextTagPiece_x                                0x93C570
#define CStmlWnd__GetSTMLText_x                                    0x4F5560
#define CStmlWnd__GetVisibleText_x                                 0x9377F0
#define CStmlWnd__InitializeWindowVariables_x                      0x93D0F0
#define CStmlWnd__MakeStmlColorTag_x                               0x936910
#define CStmlWnd__MakeWndNotificationTag_x                         0x936980
#define CStmlWnd__SetSTMLText_x                                    0x9359C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x93E400
#define CStmlWnd__UpdateHistoryString_x                            0x93D4B0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x942180
#define CTabWnd__DrawCurrentPage_x                                 0x9427A0
#define CTabWnd__DrawTab_x                                         0x942570
#define CTabWnd__GetCurrentPage_x                                  0x9419E0
#define CTabWnd__GetPageInnerRect_x                                0x941C20
#define CTabWnd__GetTabInnerRect_x                                 0x941B60
#define CTabWnd__GetTabRect_x                                      0x941A10
#define CTabWnd__InsertPage_x                                      0x941E10
#define CTabWnd__SetPage_x                                         0x941CA0
#define CTabWnd__SetPageRect_x                                     0x9420C0
#define CTabWnd__UpdatePage_x                                      0x942430
#define CTabWnd__GetPageFromTabIndex_x                             0x9424B0
#define CTabWnd__GetCurrentTabIndex_x                              0x9419D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x750A80
#define CPageWnd__SetTabText_x                                     0x94E810

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6830

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x90CF40
#define CTextureFont__GetTextExtent_x                              0x90D100

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69DA60
#define CHtmlComponentWnd__ValidateUri_x                           0x72F6D0
#define CHtmlWnd__SetClientCallbacks_x                             0x60AA30
#define CHtmlWnd__AddObserver_x                                    0x60AA50
#define CHtmlWnd__RemoveObserver_x                                 0x60AAB0
#define Window__getProgress_x                                      0x849370
#define Window__getStatus_x                                        0x849390
#define Window__getURI_x                                           0x8493A0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94AD90

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FA070

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADF90
#define CXStr__CXStr1_x                                            0x902B60
#define CXStr__CXStr3_x                                            0x8E6360
#define CXStr__dCXStr_x                                            0x472FC0
#define CXStr__operator_equal_x                                    0x8E6590
#define CXStr__operator_equal1_x                                   0x8E65D0
#define CXStr__operator_plus_equal1_x                              0x8E7060

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92E6A0
#define CXWnd__BringToTop_x                                        0x9137C0
#define CXWnd__Center_x                                            0x913340
#define CXWnd__ClrFocus_x                                          0x913170
#define CXWnd__Destroy_x                                           0x913220
#define CXWnd__DoAllDrawing_x                                      0x90F890
#define CXWnd__DrawChildren_x                                      0x90F860
#define CXWnd__DrawColoredRect_x                                   0x90FCF0
#define CXWnd__DrawTooltip_x                                       0x90E3A0
#define CXWnd__DrawTooltipAtPoint_x                                0x90E460
#define CXWnd__GetBorderFrame_x                                    0x90FB50
#define CXWnd__GetChildWndAt_x                                     0x913860
#define CXWnd__GetClientClipRect_x                                 0x911AE0
#define CXWnd__GetScreenClipRect_x                                 0x911BB0
#define CXWnd__GetScreenRect_x                                     0x911D70
#define CXWnd__GetTooltipRect_x                                    0x90FD40
#define CXWnd__GetWindowTextA_x                                    0x498000
#define CXWnd__IsActive_x                                          0x9166D0
#define CXWnd__IsDescendantOf_x                                    0x912740
#define CXWnd__IsReallyVisible_x                                   0x912770
#define CXWnd__IsType_x                                            0x913ED0
#define CXWnd__Move_x                                              0x9127D0
#define CXWnd__Move1_x                                             0x912880
#define CXWnd__ProcessTransition_x                                 0x9132F0
#define CXWnd__Refade_x                                            0x912B30
#define CXWnd__Resize_x                                            0x912DB0
#define CXWnd__Right_x                                             0x913580
#define CXWnd__SetFocus_x                                          0x913130
#define CXWnd__SetFont_x                                           0x9131A0
#define CXWnd__SetKeyTooltip_x                                     0x913CF0
#define CXWnd__SetMouseOver_x                                      0x910C80
#define CXWnd__StartFade_x                                         0x912610
#define CXWnd__GetChildItem_x                                      0x9139D0
#define CXWnd__SetParent_x                                         0x9124E0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x946370

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x916710
#define CXWndManager__DrawWindows_x                                0x916730
#define CXWndManager__GetKeyboardFlags_x                           0x918EB0
#define CXWndManager__HandleKeyboardMsg_x                          0x918AB0
#define CXWndManager__RemoveWnd_x                                  0x919100
#define CXWndManager__RemovePendingDeletionWnd_x                   0x919660

// CDBStr
#define CDBStr__GetString_x                                        0x52D100

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9060
#define EQ_Character__Cur_HP_x                                     0x4CF350
#define EQ_Character__Cur_Mana_x                                   0x4D6A80
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BBF70
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFBC0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFD10
#define EQ_Character__GetHPRegen_x                                 0x4DCA00
#define EQ_Character__GetEnduranceRegen_x                          0x4DD010
#define EQ_Character__GetManaRegen_x                               0x4DD450
#define EQ_Character__Max_Endurance_x                              0x630720
#define EQ_Character__Max_HP_x                                     0x4CF180
#define EQ_Character__Max_Mana_x                                   0x630520
#define EQ_Character__doCombatAbility_x                            0x632BF0
#define EQ_Character__UseSkill_x                                   0x4DF260
#define EQ_Character__GetConLevel_x                                0x629C60
#define EQ_Character__IsExpansionFlag_x                            0x590200
#define EQ_Character__TotalEffect_x                                0x4C2600
#define EQ_Character__GetPCSpellAffect_x                           0x4BCB60
#define EQ_Character__SpellDuration_x                              0x4BC690
#define EQ_Character__FindItemByRecord_x                           0x4D4960
#define EQ_Character__GetAdjustedSkill_x                           0x4D2090
#define EQ_Character__GetBaseSkill_x                               0x4D3030
#define EQ_Character__CanUseItem_x                                 0x4D6D90

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B79F0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x646A30

//PcClient
#define PcClient__PcClient_x                                       0x627390

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6D00
#define CCharacterListWnd__EnterWorld_x                            0x4B6740
#define CCharacterListWnd__Quit_x                                  0x4B6450
#define CCharacterListWnd__UpdateList_x                            0x4B68D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x60BC50
#define EQ_Item__CreateItemTagString_x                             0x8921E0
#define EQ_Item__IsStackable_x                                     0x896BF0
#define EQ_Item__GetImageNum_x                                     0x893C40
#define EQ_Item__CreateItemClient_x                                0x60AE10
#define EQ_Item__GetItemValue_x                                    0x894E90
#define EQ_Item__ValueSellMerchant_x                               0x8983E0
#define EQ_Item__IsKeyRingItem_x                                   0x896540
#define EQ_Item__CanGoInBag_x                                      0x60BD70
#define EQ_Item__GetMaxItemCount_x                                 0x895260
#define EQ_Item__GetHeldItem_x                                     0x893B10
#define EQ_Item__GetAugmentFitBySlot_x                             0x891B20

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54B510
#define EQ_LoadingS__Array_x                                       0xBED130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x631080
#define EQ_PC__GetAlternateAbilityId_x                             0x8A15E0
#define EQ_PC__GetCombatAbility_x                                  0x8A1C50
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A1CC0
#define EQ_PC__GetItemRecastTimer_x                                0x633170
#define EQ_PC__HasLoreItem_x                                       0x62A480
#define EQ_PC__AlertInventoryChanged_x                             0x629590
#define EQ_PC__GetPcZoneClient_x                                   0x655230
#define EQ_PC__RemoveMyAffect_x                                    0x636370
#define EQ_PC__GetKeyRingItems_x                                   0x8A2560
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A22E0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A2850

// EQItemList 
#define EQItemList__EQItemList_x                                   0x596680
#define EQItemList__add_object_x                                   0x5C22F0
#define EQItemList__add_item_x                                     0x596C90
#define EQItemList__delete_item_x                                  0x596CE0
#define EQItemList__FreeItemList_x                                 0x596BE0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52A730

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6482B0
#define EQPlayer__dEQPlayer_x                                      0x63B9A0
#define EQPlayer__DoAttack_x                                       0x64FEF0
#define EQPlayer__EQPlayer_x                                       0x63C050
#define EQPlayer__SetNameSpriteState_x                             0x6402E0
#define EQPlayer__SetNameSpriteTint_x                              0x6411B0
#define PlayerBase__HasProperty_j_x                                0x9792A0
#define EQPlayer__IsTargetable_x                                   0x979740
#define EQPlayer__CanSee_x                                         0x9795A0
#define EQPlayer__CanSee1_x                                        0x979670
#define PlayerBase__GetVisibilityLineSegment_x                     0x979360

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x652CC0
#define PlayerZoneClient__GetLevel_x                               0x655270
#define PlayerZoneClient__IsValidTeleport_x                        0x5C3440
#define PlayerZoneClient__LegalPlayerRace_x                        0x5448A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x64B030
#define EQPlayerManager__GetSpawnByName_x                          0x64B050
#define EQPlayerManager__GetPlayerFromPartialName_x                0x64B0E0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x60F4F0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x60F530
#define KeypressHandler__ClearCommandStateArray_x                  0x610920
#define KeypressHandler__HandleKeyDown_x                           0x610940
#define KeypressHandler__HandleKeyUp_x                             0x6109E0
#define KeypressHandler__SaveKeymapping_x                          0x610DC0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x767410
#define MapViewMap__SaveEx_x                                       0x76A7B0
#define MapViewMap__SetZoom_x                                      0x76EE80

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B58E0

// StringTable 
#define StringTable__getString_x                                   0x8B0860

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x635FE0
#define PcZoneClient__RemovePetEffect_x                            0x636610
#define PcZoneClient__HasAlternateAbility_x                        0x630360
#define PcZoneClient__GetCurrentMod_x                              0x4E2360
#define PcZoneClient__GetModCap_x                                  0x4E2260
#define PcZoneClient__CanEquipItem_x                               0x630A10
#define PcZoneClient__GetItemByID_x                                0x6335F0
#define PcZoneClient__GetItemByItemClass_x                         0x633740
#define PcZoneClient__RemoveBuffEffect_x                           0x636630
#define PcZoneClient__BandolierSwap_x                              0x631640

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C7FC0

//IconCache
#define IconCache__GetIcon_x                                       0x707FE0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6FFAC0
#define CContainerMgr__CloseContainer_x                            0x6FFD90
#define CContainerMgr__OpenExperimentContainer_x                   0x700810

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C2900

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x603E50

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75D8E0
#define CLootWnd__RequestLootSlot_x                                0x75CC90

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5639C0
#define EQ_Spell__SpellAffects_x                                   0x563E30
#define EQ_Spell__SpellAffectBase_x                                0x563BF0
#define EQ_Spell__IsStackable_x                                    0x4C6F10
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6D60
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B40D0
#define EQ_Spell__IsSPAStacking_x                                  0x564C60
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x564180
#define EQ_Spell__IsNoRemove_x                                     0x4C6EF0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x564C70
#define __IsResEffectSpell_x                                       0x4C6160

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AAA00

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8BFF60

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8081E0
#define CTargetWnd__WndNotification_x                              0x807A70
#define CTargetWnd__RefreshTargetBuffs_x                           0x807D40
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x806BC0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x80C8C0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x528140
#define CTaskManager__HandleMessage_x                              0x526890

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55EF30
#define EqSoundManager__PlayScriptMp3_x                            0x55F090
#define EqSoundManager__SoundAssistPlay_x                          0x66DCE0
#define EqSoundManager__WaveInstancePlay_x                         0x66D250

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51C0D0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x931E00

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5531F0
#define CAltAbilityData__GetMercMaxRank_x                          0x553190
#define CAltAbilityData__GetMaxRank_x                              0x5485F0

//CTargetRing
#define CTargetRing__Cast_x                                        0x601F40

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6D40
#define CharacterBase__CreateItemGlobalIndex_x                     0x5024E0
#define CharacterBase__CreateItemIndex_x                           0x60A040
#define CharacterBase__GetItemPossession_x                         0x4B3F80
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C85F0
#define CharacterBase__GetEffectId_x                               0x4C6CF0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E7B50
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E8370

//messages
#define msg_spell_worn_off_x                                       0x5882D0
#define msg_new_text_x                                             0x57D0C0
#define __msgTokenTextParam_x                                      0x58A930
#define msgTokenText_x                                             0x58AB80

//SpellManager
#define SpellManager__vftable_x                                    0xAB4A98
#define SpellManager__SpellManager_x                               0x671010
#define Spellmanager__LoadTextSpells_x                             0x6718E0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6711E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x97D2D0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x502B90
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58E7A0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x622C30
#define ItemGlobalIndex__IsValidIndex_x                            0x502BF0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C08A0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C0B20

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7563B0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x704220
#define CCursorAttachment__Deactivate_x                            0x705200

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x944850
#define CEQSuiteTextureLoader__GetTexture_x                        0x944510

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FFB20

//IString
#define IString__Append_x                                          0x4EF830

//Camera
#define CDisplay__cameraType_x                                     0xDC6B3C
#define EverQuest__Cameras_x                                       0xE89840

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x508210
#define LootFiltersManager__GetItemFilterData_x                    0x507B00
#define LootFiltersManager__RemoveItemLootFilter_x                 0x507B30
#define LootFiltersManager__SetItemLootFilter_x                    0x507D50

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B08E0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x982F90
#define CResolutionHandler__GetWindowedStyle_x                     0x6688F0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6FC880

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D3080

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x71CAA0
#define CGroupWnd__UpdateDisplay_x                                 0x71BE00

//ItemBase
#define ItemBase__IsLore_x                                         0x8965A0
#define ItemBase__IsLoreEquipped_x                                 0x896610

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F5BD0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C21E0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C2390
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C23F0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x65DDB0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x661A10

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
