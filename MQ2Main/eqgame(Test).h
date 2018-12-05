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
#define __ExpectedVersionDate                                     "Dec  4 2018"
#define __ExpectedVersionTime                                     "10:37:34"
#define __ActualVersionDate_x                                      0xAD012C
#define __ActualVersionTime_x                                      0xAD0120

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x6164F0
#define __MemChecker1_x                                            0x8EA8F0
#define __MemChecker2_x                                            0x6A54E0
#define __MemChecker3_x                                            0x6A5430
#define __MemChecker4_x                                            0x841DD0
#define __EncryptPad0_x                                            0xC04340
#define __EncryptPad1_x                                            0xC625D0
#define __EncryptPad2_x                                            0xC14EC8
#define __EncryptPad3_x                                            0xC14AC8
#define __EncryptPad4_x                                            0xC52E40
#define __EncryptPad5_x                                            0x1033AE0
#define __AC1_x                                                    0x7FE716
#define __AC2_x                                                    0x5D11FF
#define __AC3_x                                                    0x5D808F
#define __AC4_x                                                    0x5DBEB0
#define __AC5_x                                                    0x5E2110
#define __AC6_x                                                    0x5E66D6
#define __AC7_x                                                    0x5D0C70
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E8E344

// Direct Input
#define DI8__Main_x                                                0x1033B04
#define DI8__Keyboard_x                                            0x1033B08
#define DI8__Mouse_x                                               0xF29448
#define DI8__Mouse_Copy_x                                          0xE871A4
#define DI8__Mouse_Check_x                                         0xF2976C
#define __AutoSkillArray_x                                         0xE880BC
#define __Attack_x                                                 0xF25EC3
#define __Autofire_x                                               0xF25EC4
#define __BindList_x                                               0xBF2F20
#define g_eqCommandStates_x                                        0xBF3C90
#define __Clicks_x                                                 0xE8725C
#define __CommandList_x                                            0xBF4848
#define __CurrentMapLabel_x                                        0x103BA6C
#define __CurrentSocial_x                                          0xBDD730
#define __DoAbilityList_x                                          0xEBD9E4
#define __do_loot_x                                                0x59E8F0
#define __DrawHandler_x                                            0x16B8440
#define __GroupCount_x                                             0xE77452
#define __Guilds_x                                                 0xE7D9B0
#define __gWorld_x                                                 0xE79CD4
#define __HWnd_x                                                   0xF2944C
#define __heqmain_x                                                0x1033AC8
#define __InChatMode_x                                             0xE8718C
#define __LastTell_x                                               0xE890E0
#define __LMouseHeldTime_x                                         0xE872C8
#define __Mouse_x                                                  0x1033AEC
#define __MouseLook_x                                              0xE87222
#define __MouseEventTime_x                                         0xF26978
#define __gpbCommandEvent_x                                        0xE7976C
#define __NetStatusToggle_x                                        0xE87225
#define __PCNames_x                                                0xE8869C
#define __RangeAttackReady_x                                       0xE883A0
#define __RMouseHeldTime_x                                         0xE872C4
#define __RunWalkState_x                                           0xE87190
#define __ScreenMode_x                                             0xDC5A94
#define __ScreenX_x                                                0xE87144
#define __ScreenY_x                                                0xE87140
#define __ScreenXMax_x                                             0xE87148
#define __ScreenYMax_x                                             0xE8714C
#define __ServerHost_x                                             0xE799AB
#define __ServerName_x                                             0xEBD9A4
#define __ShiftKeyDown_x                                           0xE8781C
#define __ShowNames_x                                              0xE8855C
#define __Socials_x                                                0xEBDAA4
#define __SubscriptionType_x                                       0x107D5BC
#define __TargetAggroHolder_x                                      0x103E428
#define __ZoneType_x                                               0xE87620
#define __GroupAggro_x                                             0x103E468
#define __LoginName_x                                              0x103435C
#define __Inviter_x                                                0xF25E40
#define __AttackOnAssist_x                                         0xE88518
#define __UseTellWindows_x                                         0xE88834
#define __gfMaxZoomCameraDistance_x                                0xAC5648
#define __gfMaxCameraDistance_x                                    0xAF2A90
#define __pulAutoRun_x                                             0xE87240
#define __pulForward_x                                             0xE8886C
#define __pulBackward_x                                            0xE88870
#define __pulTurnRight_x                                           0xE88874
#define __pulTurnLeft_x                                            0xE88878
#define __pulStrafeLeft_x                                          0xE8887C
#define __pulStrafeRight_x                                         0xE88880

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE79D48
#define instEQZoneInfo_x                                           0xE87418
#define instKeypressHandler_x                                      0xF26928
#define pinstActiveBanker_x                                        0xE79854
#define pinstActiveCorpse_x                                        0xE7984C
#define pinstActiveGMaster_x                                       0xE79850
#define pinstActiveMerchant_x                                      0xE79848
#define pinstAggroInfo_x                                           0xC78E08
#define pinstAltAdvManager_x                                       0xDC66F0
#define pinstAuraMgr_x                                             0xC94988
#define pinstBandageTarget_x                                       0xE79864
#define pinstCamActor_x                                            0xDC5A88
#define pinstCDBStr_x                                              0xDC5424
#define pinstCDisplay_x                                            0xE79AB4
#define pinstCEverQuest_x                                          0x1033C20
#define pinstEverQuestInfo_x                                       0xE87138
#define pinstCharData_x                                            0xE79CF0
#define pinstCharSpawn_x                                           0xE7989C
#define pinstControlledMissile_x                                   0xE79CDC
#define pinstControlledPlayer_x                                    0xE7989C
#define pinstCResolutionHandler_x                                  0x16B8670
#define pinstCSidlManager_x                                        0x16B7504
#define pinstCXWndManager_x                                        0x16B74F8
#define instDynamicZone_x                                          0xE7D888
#define pinstDZMember_x                                            0xE7D998
#define pinstDZTimerInfo_x                                         0xE7D99C
#define pinstEQItemList_x                                          0xE75F38
#define pinstEQObjectList_x                                        0xE77128
#define instEQMisc_x                                               0xDC5360
#define pinstEQSoundManager_x                                      0xDC6F50
#define pinstEQSpellStrings_x                                      0xC86F40
#define instExpeditionLeader_x                                     0xE7D8D2
#define instExpeditionName_x                                       0xE7D912
#define pinstGroup_x                                               0xE7744E
#define pinstImeManager_x                                          0x16B74FC
#define pinstLocalPlayer_x                                         0xE79844
#define pinstMercenaryData_x                                       0xF27124
#define pinstMercenaryStats_x                                      0x103E574
#define pinstMercAltAbilities_x                                    0xDC6CC0
#define pinstModelPlayer_x                                         0xE7985C
#define pinstPCData_x                                              0xE79CF0
#define pinstRealEstateItems_x                                     0xF28608
#define pinstSkillMgr_x                                            0xF286D8
#define pinstSpawnManager_x                                        0xF27CC8
#define pinstSpellManager_x                                        0xF288B0
#define pinstSpellSets_x                                           0xF1EAEC
#define pinstStringTable_x                                         0xE79648
#define pinstSwitchManager_x                                       0xE772E8
#define pinstTarget_x                                              0xE79898
#define pinstTargetObject_x                                        0xE798A4
#define pinstTargetSwitch_x                                        0xE79D3C
#define pinstTaskMember_x                                          0xDC51F4
#define pinstTrackTarget_x                                         0xE798A0
#define pinstTradeTarget_x                                         0xE79858
#define instTributeActive_x                                        0xDC5385
#define pinstViewActor_x                                           0xDC5A84
#define pinstWorldData_x                                           0xE79764
#define pinstZoneAddr_x                                            0xE876B8
#define pinstPlayerPath_x                                          0xF27D60
#define pinstTargetIndicator_x                                     0xF28B18
#define pinstCTargetManager_x                                      0xF28BB0
#define EQObject_Top_x                                             0xE79804
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDC5544
#define pinstCAchievementsWnd_x                                    0xDC5534
#define pinstCActionsWnd_x                                         0xDC55A8
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDC5A48
#define pinstCAdvancedLootWnd_x                                    0xDC558C
#define pinstCAdventureLeaderboardWnd_x                            0x1035240
#define pinstCAdventureRequestWnd_x                                0x10352F0
#define pinstCAdventureStatsWnd_x                                  0x10353A0
#define pinstCAggroMeterWnd_x                                      0xDC5AC8
#define pinstCAlarmWnd_x                                           0xDC5B34
#define pinstCAlertHistoryWnd_x                                    0xDC54EC
#define pinstCAlertStackWnd_x                                      0xDC5ADC
#define pinstCAlertWnd_x                                           0xDC5B00
#define pinstCAltStorageWnd_x                                      0x1035700
#define pinstCAudioTriggersWindow_x                                0xC79298
#define pinstCAuraWnd_x                                            0xDC5AC4
#define pinstCAvaZoneWnd_x                                         0xDC54F4
#define pinstCBandolierWnd_x                                       0xDC5B08
#define pinstCBankWnd_x                                            0xDC54F0
#define pinstCBarterMerchantWnd_x                                  0x1036940
#define pinstCBarterSearchWnd_x                                    0x10369F0
#define pinstCBarterWnd_x                                          0x1036AA0
#define pinstCBazaarConfirmationWnd_x                              0xDC5AD8
#define pinstCBazaarSearchWnd_x                                    0xDC5630
#define pinstCBazaarWnd_x                                          0xDC5B0C
#define pinstCBlockedBuffWnd_x                                     0xDC54D4
#define pinstCBlockedPetBuffWnd_x                                  0xDC5500
#define pinstCBodyTintWnd_x                                        0xDC5AA8
#define pinstCBookWnd_x                                            0xDC5B2C
#define pinstCBreathWnd_x                                          0xDC5548
#define pinstCBuffWindowNORMAL_x                                   0xDC5D48
#define pinstCBuffWindowSHORT_x                                    0xDC5D4C
#define pinstCBugReportWnd_x                                       0xDC553C
#define pinstCButtonWnd_x                                          0x16B7728
#define pinstCCastingWnd_x                                         0xDC5538
#define pinstCCastSpellWnd_x                                       0xDC5A44
//#define pinstCCharacterCreationWnd_x                               0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDC554C
#define pinstCChatWindowManager_x                                  0x1037560
#define pinstCClaimWnd_x                                           0x10376B8
#define pinstCColorPickerWnd_x                                     0xDC557C
#define pinstCCombatAbilityWnd_x                                   0xDC5AD0
#define pinstCCombatSkillsSelectWnd_x                              0xDC55A4
#define pinstCCompassWnd_x                                         0xDC5A78
#define pinstCConfirmationDialog_x                                 0x103C5B8
#define pinstCContainerMgr_x                                       0xDC5AE0
#define pinstCContextMenuManager_x                                 0x16B74B8
#define pinstCCursorAttachment_x                                   0xDC5530
#define pinstCDistillerInfo_x                                      0x103AFC4
#define pinstCDynamicZoneWnd_x                                     0x1037C80
#define pinstCEditLabelWnd_x                                       0xDC5B3C
#define pinstCEQMainWnd_x                                          0x1037EC8
#define pinstCEventCalendarWnd_x                                   0xDC5564
#define pinstCExtendedTargetWnd_x                                  0xDC5AB8
#define pinstCFacePick_x                                           0xDC5574
#define pinstCFactionWnd_x                                         0xDC552C
#define pinstCFellowshipWnd_x                                      0x10380C8
#define pinstCFileSelectionWnd_x                                   0xDC5578
#define pinstCFindItemWnd_x                                        0xDC5B28
#define pinstCFindLocationWnd_x                                    0x1038220
#define pinstCFriendsWnd_x                                         0xDC562C
#define pinstCGemsGameWnd_x                                        0xDC5B04
#define pinstCGiveWnd_x                                            0xDC5B30
#define pinstCGroupSearchFiltersWnd_x                              0xDC5AE8
#define pinstCGroupSearchWnd_x                                     0x1038618
#define pinstCGroupWnd_x                                           0x10386C8
#define pinstCGuildBankWnd_x                                       0xE884FC
#define pinstCGuildCreationWnd_x                                   0x1038828
#define pinstCGuildMgmtWnd_x                                       0x10388D8
#define pinstCharacterCreation_x                                   0xDC5ACC
#define pinstCHelpWnd_x                                            0xDC5A7C
#define pinstCHeritageSelectionWnd_x                               0xDC5588
#define pinstCHotButtonWnd_x                                       0x103AA30
#define pinstCHotButtonWnd1_x                                      0x103AA30
#define pinstCHotButtonWnd2_x                                      0x103AA34
#define pinstCHotButtonWnd3_x                                      0x103AA38
#define pinstCHotButtonWnd4_x                                      0x103AA3C
#define pinstCIconSelectionWnd_x                                   0xDC5510
#define pinstCInspectWnd_x                                         0xDC550C
#define pinstCInventoryWnd_x                                       0xDC5B10
#define pinstCInvSlotMgr_x                                         0xDC5AB0
#define pinstCItemDisplayManager_x                                 0x103AFC0
#define pinstCItemExpTransferWnd_x                                 0x103B0F0
#define pinstCItemOverflowWnd_x                                    0xDC5634
#define pinstCJournalCatWnd_x                                      0xDC5594
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDC5558
#define pinstCKeyRingWnd_x                                         0xDC54C8
#define pinstCLargeDialogWnd_x                                     0x103D238
#define pinstCLayoutCopyWnd_x                                      0x103B440
#define pinstCLFGuildWnd_x                                         0x103B4F0
#define pinstCLoadskinWnd_x                                        0xDC5B14
#define pinstCLootFiltersCopyWnd_x                                 0xC952B8
#define pinstCLootFiltersWnd_x                                     0xDC5B24
#define pinstCLootSettingsWnd_x                                    0xDC5D44
#define pinstCLootWnd_x                                            0xDC5568
#define pinstCMailAddressBookWnd_x                                 0xDC5504
#define pinstCMailCompositionWnd_x                                 0xDC54DC
#define pinstCMailIgnoreListWnd_x                                  0xDC5508
#define pinstCMailWnd_x                                            0xDC5D54
#define pinstCManageLootWnd_x                                      0xDC6B68
#define pinstCMapToolbarWnd_x                                      0xDC5B18
#define pinstCMapViewWnd_x                                         0xDC5AF0
#define pinstCMarketplaceWnd_x                                     0xDC556C
#define pinstCMerchantWnd_x                                        0xDC55A0
#define pinstCMIZoneSelectWnd_x                                    0x103BD28
#define pinstCMusicPlayerWnd_x                                     0xDC54C4
#define pinstCNameChangeMercWnd_x                                  0xDC5AAC
#define pinstCNameChangePetWnd_x                                   0xDC5A70
#define pinstCNameChangeWnd_x                                      0xDC5550
#define pinstCNoteWnd_x                                            0xDC5A50
#define pinstCObjectPreviewWnd_x                                   0xDC5590
#define pinstCOptionsWnd_x                                         0xDC5B1C
#define pinstCPetInfoWnd_x                                         0xDC54E0
#define pinstCPetitionQWnd_x                                       0xDC55AC
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDC5AA0
#define pinstCPlayerWnd_x                                          0xDC55B0
#define pinstCPopupWndManager_x                                    0x103C5B8
#define pinstCProgressionSelectionWnd_x                            0x103C668
#define pinstCPurchaseGroupWnd_x                                   0xDC5A3C
#define pinstCPurchaseWnd_x                                        0xDC559C
#define pinstCPvPLeaderboardWnd_x                                  0x103C718
#define pinstCPvPStatsWnd_x                                        0x103C7C8
#define pinstCQuantityWnd_x                                        0xDC5518
#define pinstCRaceChangeWnd_x                                      0xDC5570
#define pinstCRaidOptionsWnd_x                                     0xDC5AEC
#define pinstCRaidWnd_x                                            0xDC551C
#define pinstCRealEstateItemsWnd_x                                 0xDC5540
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDC555C
#define pinstCRealEstateManageWnd_x                                0xDC5D50
#define pinstCRealEstateNeighborhoodWnd_x                          0xDC54CC
#define pinstCRealEstatePlotSearchWnd_x                            0xDC54F8
#define pinstCRealEstatePurchaseWnd_x                              0xDC5520
#define pinstCRespawnWnd_x                                         0xDC5AE4
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDC5ABC
#define pinstCSendMoneyWnd_x                                       0xDC5D40
#define pinstCServerListWnd_x                                      0xDC54E8
#define pinstCSkillsSelectWnd_x                                    0xDC5580
#define pinstCSkillsWnd_x                                          0xDC5560
#define pinstCSocialEditWnd_x                                      0xDC5528
#define pinstCSocialWnd_x                                          0xDC5AC0
#define pinstCSpellBookWnd_x                                       0xDC5AB4
#define pinstCStoryWnd_x                                           0xDC5A4C
#define pinstCTargetOfTargetWnd_x                                  0x103E5F8
#define pinstCTargetWnd_x                                          0xDC54D8
#define pinstCTaskOverlayWnd_x                                     0xDC54FC
#define pinstCTaskSelectWnd_x                                      0x103E750
#define pinstCTaskManager_x                                        0xC95AB8
#define pinstCTaskTemplateSelectWnd_x                              0x103E800
#define pinstCTaskWnd_x                                            0x103E8B0
#define pinstCTextEntryWnd_x                                       0xDC5A80
#define pinstCTextOverlay_x                                        0xC795A8
#define pinstCTimeLeftWnd_x                                        0xDC5584
#define pinstCTipWndCONTEXT_x                                      0x103EAB4
#define pinstCTipWndOFDAY_x                                        0x103EAB0
#define pinstCTitleWnd_x                                           0x103EB60
#define pinstCTrackingWnd_x                                        0xDC54E4
#define pinstCTradeskillWnd_x                                      0x103ECC8
#define pinstCTradeWnd_x                                           0xDC5AA4
#define pinstCTrainWnd_x                                           0xDC5514
#define pinstCTributeBenefitWnd_x                                  0x103EEC8
#define pinstCTributeMasterWnd_x                                   0x103EF78
#define pinstCTributeTrophyWnd_x                                   0x103F028
#define pinstCVideoModesWnd_x                                      0xDC5AD4
#define pinstCVoiceMacroWnd_x                                      0xF290E0
#define pinstCVoteResultsWnd_x                                     0xDC5A40
#define pinstCVoteWnd_x                                            0xDC55B4
#define pinstCWebManager_x                                         0xF29244
#define pinstCZoneGuideWnd_x                                       0xDC54C0
#define pinstCZonePathWnd_x                                        0xDC54D0

#define pinstEQSuiteTextureLoader_x                                0xC640A0
#define pinstItemIconCache_x                                       0x1037E80
#define pinstLootFiltersManager_x                                  0xC95368
#define pinstRewardSelectionWnd_x                                  0x103CF10

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC14ABC
#define __CastRay_x                                                0x599E10
#define __CastRay2_x                                               0x599E60
#define __ConvertItemTags_x                                        0x5B4A90
#define __CrashHandler_x                                           0x84B780
#define __EQGetTime_x                                              0x8EA3E0
#define __ExecuteCmd_x                                             0x5927A0
#define __FixHeading_x                                             0x97AC30
#define __get_bearing_x                                            0x599960
#define __get_melee_range_x                                        0x59A050
#define __GetAnimationCache_x                                      0x708CF0
#define __GetGaugeValueFromEQ_x                                    0x7FCF20
#define __GetLabelFromEQ_x                                         0x7FE6A0
#define __GetXTargetType_x                                         0x97C690
#define __HandleMouseWheel_x                                       0x6A5590
#define __HeadingDiff_x                                            0x97ACA0
#define __HelpPath_x                                               0xF26594
#define __LoadFrontEnd_x                                           0x6A1340
#define __NewUIINI_x                                               0x7FCBF0
#define __pCrashHandler_x                                          0x105C418
#define __ProcessGameEvents_x                                      0x5F79E0
#define __ProcessMouseEvent_x                                      0x5F71A0
#define __SaveColors_x                                             0x543580
#define __STMLToText_x                                             0x91DFB0
#define __ToggleKeyRingItem_x                                      0x506510
#define CrashDetected_x                                            0x6A2E30
#define DrawNetStatus_x                                            0x623910
#define Expansion_HoT_x                                            0xE88504
#define Teleport_Table_Size_x                                      0xE79800
#define Teleport_Table_x                                           0xE77640
#define Util__FastTime_x                                           0x8E9FA0
#define wwsCrashReportCheckForUploader_x                           0x84C270
#define wwsCrashReportPlatformLaunchUploader_x                     0x84E950

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B670
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4944E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4942A0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54B0C0
#define AltAdvManager__IsAbilityReady_x                            0x54A010
#define AltAdvManager__GetAAById_x                                 0x54A210
#define AltAdvManager__CanTrainAbility_x                           0x54A280
#define AltAdvManager__CanSeeAbility_x                             0x54A5E0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7710
#define CharacterZoneClient__HasSkill_x                            0x4D23E0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3B00
#define CharacterZoneClient__IsStackBlocked_x                      0x4BBB00
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B8270
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D64D0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D65B0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6690
#define CharacterZoneClient__FindAffectSlot_x                      0x4C05E0
#define CharacterZoneClient__BardCastBard_x                        0x4C3240
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8340
#define CharacterZoneClient__GetEffect_x                           0x4B81B0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C15E0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C16B0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1700
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1850
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1A20

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CB240

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D8C90

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x6061B0
#define CButtonWnd__CButtonWnd_x                                   0x91A3A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F7680
#define CChatManager__InitContextMenu_x                            0x6F1720
#define CChatManager__FreeChatWindow_x                             0x6F6590
#define CChatManager__GetLockedActiveChatWindow_x                  0x6FAFD0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F7420

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x92EB60
#define CContextMenu__dCContextMenu_x                              0x92ED90
#define CContextMenu__AddMenuItem_x                                0x92EDA0
#define CContextMenu__RemoveMenuItem_x                             0x92F0B0
#define CContextMenu__RemoveAllMenuItems_x                         0x92F0D0
#define CContextMenu__CheckMenuItem_x                              0x92F150
#define CContextMenu__SetMenuItem_x                                0x92EFD0
#define CContextMenu__AddSeparator_x                               0x92EF30

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x92F6F0
#define CContextMenuManager__RemoveMenu_x                          0x92F760
#define CContextMenuManager__PopupMenu_x                           0x92F820
#define CContextMenuManager__Flush_x                               0x92F690
#define CContextMenuManager__GetMenu_x                             0x496700

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CAD90
#define CChatService__GetFriendName_x                              0x8CADA0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F7BF0
#define CChatWindow__Clear_x                                       0x6F8C40
#define CChatWindow__WndNotification_x                             0x6F91A0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x92C000
#define CComboWnd__Draw_x                                          0x92B500
#define CComboWnd__GetCurChoice_x                                  0x92BE40
#define CComboWnd__GetListRect_x                                   0x92B9B0
#define CComboWnd__GetTextRect_x                                   0x92C070
#define CComboWnd__InsertChoice_x                                  0x92BB40
#define CComboWnd__SetColors_x                                     0x92BB10
#define CComboWnd__SetChoice_x                                     0x92BE10
#define CComboWnd__GetItemCount_x                                  0x92BE50
#define CComboWnd__GetCurChoiceText_x                              0x92BE90

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x700EC0
#define CContainerWnd__vftable_x                                   0xAD93D0
#define CContainerWnd__SetContainer_x                              0x702430

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x543340
#define CDisplay__GetClickedActor_x                                0x536300
#define CDisplay__GetUserDefinedColor_x                            0x52E9E0
#define CDisplay__GetWorldFilePath_x                               0x537D50
#define CDisplay__is3dON_x                                         0x532FD0
#define CDisplay__ReloadUI_x                                       0x53D470
#define CDisplay__WriteTextHD2_x                                   0x532DB0
#define CDisplay__TrueDistance_x                                   0x5399B0
#define CDisplay__SetViewActor_x                                   0x535C50
#define CDisplay__GetFloorHeight_x                                 0x533090
#define CDisplay__SetRenderWindow_x                                0x5319C0
#define CDisplay__ToggleScreenshotMode_x                           0x535720

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94E350

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x933250
#define CEditWnd__GetCharIndexPt_x                                 0x934150
#define CEditWnd__GetDisplayString_x                               0x933FF0
#define CEditWnd__GetHorzOffset_x                                  0x932880
#define CEditWnd__GetLineForPrintableChar_x                        0x935290
#define CEditWnd__GetSelStartPt_x                                  0x934400
#define CEditWnd__GetSTMLSafeText_x                                0x933E10
#define CEditWnd__PointFromPrintableChar_x                         0x934EC0
#define CEditWnd__SelectableCharFromPoint_x                        0x935030
#define CEditWnd__SetEditable_x                                    0x9344D0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E5C00
#define CEverQuest__ClickedPlayer_x                                0x5D7E70
#define CEverQuest__CreateTargetIndicator_x                        0x5F4C90
#define CEverQuest__DeleteTargetIndicator_x                        0x5F4D20
#define CEverQuest__DoTellWindow_x                                 0x4E3600
#define CEverQuest__OutputTextToLog_x                              0x4E3830
#define CEverQuest__DropHeldItemOnGround_x                         0x5CD730
#define CEverQuest__dsp_chat_x                                     0x4E3BC0
#define CEverQuest__trimName_x                                     0x5F1010
#define CEverQuest__Emote_x                                        0x5E6410
#define CEverQuest__EnterZone_x                                    0x5E04C0
#define CEverQuest__GetBodyTypeDesc_x                              0x5EA8B0
#define CEverQuest__GetClassDesc_x                                 0x5EAEF0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EB4F0
#define CEverQuest__GetDeityDesc_x                                 0x5F35E0
#define CEverQuest__GetLangDesc_x                                  0x5EB6B0
#define CEverQuest__GetRaceDesc_x                                  0x5EAED0
#define CEverQuest__InterpretCmd_x                                 0x5F3BB0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D1920
#define CEverQuest__LMouseUp_x                                     0x5CFCA0
#define CEverQuest__RightClickedOnPlayer_x                         0x5D2200
#define CEverQuest__RMouseUp_x                                     0x5D0C30
#define CEverQuest__SetGameState_x                                 0x5CD4C0
#define CEverQuest__UPCNotificationFlush_x                         0x5F0F10
#define CEverQuest__IssuePetCommand_x                              0x5ECAB0
#define CEverQuest__ReportSuccessfulHit_x                          0x5E7810

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x712E80
#define CGaugeWnd__CalcLinesFillRect_x                             0x712EE0
#define CGaugeWnd__Draw_x                                          0x712570

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACE50
#define CGuild__GetGuildName_x                                     0x4ABF30
#define CGuild__GetGuildIndex_x                                    0x4AC2C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72E240

//CHotButton
#define CHotButton__SetButtonSize_x                                0x606570

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x73B1B0
#define CInvSlotMgr__MoveItem_x                                    0x739F10
#define CInvSlotMgr__SelectSlot_x                                  0x73B280

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7387B0
#define CInvSlot__SliderComplete_x                                 0x736510
#define CInvSlot__GetItemBase_x                                    0x735EA0
#define CInvSlot__UpdateItem_x                                     0x736010

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x73CBB0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x73BE80
#define CInvSlotWnd__HandleLButtonUp_x                             0x73C730

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F9110
#define CItemDisplayWnd__UpdateStrings_x                           0x74AE10
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x744E00
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x745300
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x74B430
#define CItemDisplayWnd__AboutToShow_x                             0x74AA60
#define CItemDisplayWnd__WndNotification_x                         0x74C970

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x830A90

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x750AD0

// CLabel 
#define CLabel__Draw_x                                             0x756550

// CListWnd
#define CListWnd__CListWnd_x                                       0x9047F0
#define CListWnd__dCListWnd_x                                      0x904B10
#define CListWnd__AddColumn_x                                      0x908E50
#define CListWnd__AddColumn1_x                                     0x908EA0
#define CListWnd__AddLine_x                                        0x909230
#define CListWnd__AddString_x                                      0x909030
#define CListWnd__CalculateFirstVisibleLine_x                      0x908C10
#define CListWnd__CalculateVSBRange_x                              0x9089F0
#define CListWnd__ClearSel_x                                       0x909A10
#define CListWnd__ClearAllSel_x                                    0x909A70
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90A4A0
#define CListWnd__Compare_x                                        0x908330
#define CListWnd__Draw_x                                           0x904C10
#define CListWnd__DrawColumnSeparators_x                           0x907400
#define CListWnd__DrawHeader_x                                     0x907870
#define CListWnd__DrawItem_x                                       0x907C70
#define CListWnd__DrawLine_x                                       0x907570
#define CListWnd__DrawSeparator_x                                  0x9074A0
#define CListWnd__EnableLine_x                                     0x906CD0
#define CListWnd__EnsureVisible_x                                  0x90A3C0
#define CListWnd__ExtendSel_x                                      0x909940
#define CListWnd__GetColumnMinWidth_x                              0x906810
#define CListWnd__GetColumnWidth_x                                 0x906780
#define CListWnd__GetCurSel_x                                      0x906110
#define CListWnd__GetItemAtPoint_x                                 0x906F50
#define CListWnd__GetItemAtPoint1_x                                0x906FC0
#define CListWnd__GetItemData_x                                    0x906190
#define CListWnd__GetItemHeight_x                                  0x906550
#define CListWnd__GetItemIcon_x                                    0x906320
#define CListWnd__GetItemRect_x                                    0x906DC0
#define CListWnd__GetItemText_x                                    0x9061D0
#define CListWnd__GetSelList_x                                     0x909AC0
#define CListWnd__GetSeparatorRect_x                               0x907200
#define CListWnd__InsertLine_x                                     0x909620
#define CListWnd__RemoveLine_x                                     0x909770
#define CListWnd__SetColors_x                                      0x9089C0
#define CListWnd__SetColumnJustification_x                         0x9086F0
#define CListWnd__SetColumnWidth_x                                 0x908610
#define CListWnd__SetCurSel_x                                      0x909880
#define CListWnd__SetItemColor_x                                   0x90A070
#define CListWnd__SetItemData_x                                    0x90A030
#define CListWnd__SetItemText_x                                    0x909C40
#define CListWnd__ShiftColumnSeparator_x                           0x9087B0
#define CListWnd__Sort_x                                           0x9084B0
#define CListWnd__ToggleSel_x                                      0x9098B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x76B990
#define CMapViewWnd__GetWorldCoordinates_x                         0x76A0A0
#define CMapViewWnd__HandleLButtonDown_x                           0x767100

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78EE80
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x78F760
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x78FC90
#define CMerchantWnd__SelectRecoverySlot_x                         0x792AD0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x78D860
#define CMerchantWnd__SelectBuySellSlot_x                          0x7986C0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78EAC0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x898A90
#define CPacketScrambler__hton_x                                   0x898A80

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x923590
#define CSidlManager__FindScreenPieceTemplate_x                    0x9239A0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x923790
#define CSidlManager__CreateLabel_x                                0x7F0560
#define CSidlManager__CreateXWndFromTemplate_x                     0x926A70
#define CSidlManager__CreateXWndFromTemplate1_x                    0x926C50
#define CSidlManager__CreateXWnd_x                                 0x7F0490
#define CSidlManager__CreateHotButtonWnd_x                         0x7F0A50

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x920110
#define CSidlScreenWnd__CalculateVSBRange_x                        0x920010
#define CSidlScreenWnd__ConvertToRes_x                             0x945190
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x91FAB0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x91F7A0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x91F870
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x91F940
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9205B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x920A80
#define CSidlScreenWnd__GetSidlPiece_x                             0x9207A0
#define CSidlScreenWnd__Init1_x                                    0x91F390
#define CSidlScreenWnd__LoadIniInfo_x                              0x920AD0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x921600
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91E790
#define CSidlScreenWnd__StoreIniInfo_x                             0x921180
#define CSidlScreenWnd__StoreIniVis_x                              0x9214E0
#define CSidlScreenWnd__WndNotification_x                          0x9204C0
#define CSidlScreenWnd__GetChildItem_x                             0x920A00
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9102C0
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B7388

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66AA60
#define CSkillMgr__GetSkillCap_x                                   0x66AC40
#define CSkillMgr__GetNameToken_x                                  0x66A1F0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9304D0
#define CSliderWnd__SetValue_x                                     0x930340
#define CSliderWnd__SetNumTicks_x                                  0x9303A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F6390

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x937210
#define CStmlWnd__CalculateHSBRange_x                              0x9382A0
#define CStmlWnd__CalculateVSBRange_x                              0x938210
#define CStmlWnd__CanBreakAtCharacter_x                            0x93C600
#define CStmlWnd__FastForwardToEndOfTag_x                          0x93D290
#define CStmlWnd__ForceParseNow_x                                  0x9377B0
#define CStmlWnd__GetNextTagPiece_x                                0x93C560
#define CStmlWnd__GetSTMLText_x                                    0x4F5840
#define CStmlWnd__GetVisibleText_x                                 0x9377D0
#define CStmlWnd__InitializeWindowVariables_x                      0x93D0E0
#define CStmlWnd__MakeStmlColorTag_x                               0x9368F0
#define CStmlWnd__MakeWndNotificationTag_x                         0x936960
#define CStmlWnd__SetSTMLText_x                                    0x9359A0
#define CStmlWnd__StripFirstSTMLLines_x                            0x93E3F0
#define CStmlWnd__UpdateHistoryString_x                            0x93D4A0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9420F0
#define CTabWnd__DrawCurrentPage_x                                 0x942710
#define CTabWnd__DrawTab_x                                         0x9424E0
#define CTabWnd__GetCurrentPage_x                                  0x941950
#define CTabWnd__GetPageInnerRect_x                                0x941B90
#define CTabWnd__GetTabInnerRect_x                                 0x941AD0
#define CTabWnd__GetTabRect_x                                      0x941980
#define CTabWnd__InsertPage_x                                      0x941D80
#define CTabWnd__SetPage_x                                         0x941C10
#define CTabWnd__SetPageRect_x                                     0x942030
#define CTabWnd__UpdatePage_x                                      0x9423A0
#define CTabWnd__GetPageFromTabIndex_x                             0x942420
#define CTabWnd__GetCurrentTabIndex_x                              0x941940

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x750F50
#define CPageWnd__SetTabText_x                                     0x94E760

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A68F0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x90D120
#define CTextureFont__GetTextExtent_x                              0x90D2E0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69E190
#define CHtmlComponentWnd__ValidateUri_x                           0x72FC30
#define CHtmlWnd__SetClientCallbacks_x                             0x60B540
#define CHtmlWnd__AddObserver_x                                    0x60B560
#define CHtmlWnd__RemoveObserver_x                                 0x60B5C0
#define Window__getProgress_x                                      0x8493E0
#define Window__getStatus_x                                        0x849400
#define Window__getURI_x                                           0x849410

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94AC90

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FA050

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AE0F0
#define CXStr__CXStr1_x                                            0x839A90
#define CXStr__CXStr3_x                                            0x8E6510
#define CXStr__dCXStr_x                                            0x472F60
#define CXStr__operator_equal_x                                    0x8E6740
#define CXStr__operator_equal1_x                                   0x8E6780
#define CXStr__operator_plus_equal1_x                              0x8E7210

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92E780
#define CXWnd__BringToTop_x                                        0x913A40
#define CXWnd__Center_x                                            0x9135C0
#define CXWnd__ClrFocus_x                                          0x913400
#define CXWnd__Destroy_x                                           0x9134A0
#define CXWnd__DoAllDrawing_x                                      0x90FA60
#define CXWnd__DrawChildren_x                                      0x90FA30
#define CXWnd__DrawColoredRect_x                                   0x90FEB0
#define CXWnd__DrawTooltip_x                                       0x90E580
#define CXWnd__DrawTooltipAtPoint_x                                0x90E640
#define CXWnd__GetBorderFrame_x                                    0x90FD10
#define CXWnd__GetChildWndAt_x                                     0x913AE0
#define CXWnd__GetClientClipRect_x                                 0x911CC0
#define CXWnd__GetScreenClipRect_x                                 0x911D90
#define CXWnd__GetScreenRect_x                                     0x911F60
#define CXWnd__GetTooltipRect_x                                    0x90FF00
#define CXWnd__GetWindowTextA_x                                    0x497E70
#define CXWnd__IsActive_x                                          0x916990
#define CXWnd__IsDescendantOf_x                                    0x912970
#define CXWnd__IsReallyVisible_x                                   0x9129A0
#define CXWnd__IsType_x                                            0x914150
#define CXWnd__Move_x                                              0x912A20
#define CXWnd__Move1_x                                             0x912AD0
#define CXWnd__ProcessTransition_x                                 0x913570
#define CXWnd__Refade_x                                            0x912DA0
#define CXWnd__Resize_x                                            0x913030
#define CXWnd__Right_x                                             0x913800
#define CXWnd__SetFocus_x                                          0x9133C0
#define CXWnd__SetFont_x                                           0x913430
#define CXWnd__SetKeyTooltip_x                                     0x913F60
#define CXWnd__SetMouseOver_x                                      0x910E40
#define CXWnd__StartFade_x                                         0x912840
#define CXWnd__GetChildItem_x                                      0x913C40
#define CXWnd__SetParent_x                                         0x912700

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x946270

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9169D0
#define CXWndManager__DrawWindows_x                                0x9169F0
#define CXWndManager__GetKeyboardFlags_x                           0x9190A0
#define CXWndManager__HandleKeyboardMsg_x                          0x918CB0
#define CXWndManager__RemoveWnd_x                                  0x9192E0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x919820

// CDBStr
#define CDBStr__GetString_x                                        0x52D980

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9220
#define EQ_Character__Cur_HP_x                                     0x4CF460
#define EQ_Character__Cur_Mana_x                                   0x4D6B90
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BC140
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFCF0
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFE40
#define EQ_Character__GetHPRegen_x                                 0x4DCB10
#define EQ_Character__GetEnduranceRegen_x                          0x4DD120
#define EQ_Character__GetManaRegen_x                               0x4DD560
#define EQ_Character__Max_Endurance_x                              0x631470
#define EQ_Character__Max_HP_x                                     0x4CF290
#define EQ_Character__Max_Mana_x                                   0x631270
#define EQ_Character__doCombatAbility_x                            0x633940
#define EQ_Character__UseSkill_x                                   0x4DF370
#define EQ_Character__GetConLevel_x                                0x62A810
#define EQ_Character__IsExpansionFlag_x                            0x590F30
#define EQ_Character__TotalEffect_x                                0x4C27C0
#define EQ_Character__GetPCSpellAffect_x                           0x4BCD30
#define EQ_Character__SpellDuration_x                              0x4BC860
#define EQ_Character__FindItemByRecord_x                           0x4D4A70
#define EQ_Character__GetAdjustedSkill_x                           0x4D21A0
#define EQ_Character__GetBaseSkill_x                               0x4D3140
#define EQ_Character__CanUseItem_x                                 0x4D6EA0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B7D90

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x647780

//PcClient
#define PcClient__PcClient_x                                       0x627F50

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6E80
#define CCharacterListWnd__EnterWorld_x                            0x4B68C0
#define CCharacterListWnd__Quit_x                                  0x4B65D0
#define CCharacterListWnd__UpdateList_x                            0x4B6A50

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x60C780
#define EQ_Item__CreateItemTagString_x                             0x8923E0
#define EQ_Item__IsStackable_x                                     0x896E10
#define EQ_Item__GetImageNum_x                                     0x893E40
#define EQ_Item__CreateItemClient_x                                0x60B940
#define EQ_Item__GetItemValue_x                                    0x895090
#define EQ_Item__ValueSellMerchant_x                               0x898620
#define EQ_Item__IsKeyRingItem_x                                   0x896760
#define EQ_Item__CanGoInBag_x                                      0x60C8A0
#define EQ_Item__GetMaxItemCount_x                                 0x895460
#define EQ_Item__GetHeldItem_x                                     0x893D10
#define EQ_Item__GetAugmentFitBySlot_x                             0x891D20

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54BDA0
#define EQ_LoadingS__Array_x                                       0xBEC130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x631DD0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A1920
#define EQ_PC__GetCombatAbility_x                                  0x8A1F90
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A2000
#define EQ_PC__GetItemRecastTimer_x                                0x633EC0
#define EQ_PC__HasLoreItem_x                                       0x62AFD0
#define EQ_PC__AlertInventoryChanged_x                             0x62A150
#define EQ_PC__GetPcZoneClient_x                                   0x655FF0
#define EQ_PC__RemoveMyAffect_x                                    0x6370B0
#define EQ_PC__GetKeyRingItems_x                                   0x8A28A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A2620
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A2B90

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5973C0
#define EQItemList__add_object_x                                   0x5C2EE0
#define EQItemList__add_item_x                                     0x5979D0
#define EQItemList__delete_item_x                                  0x597A20
#define EQItemList__FreeItemList_x                                 0x597920

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52AF90

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x649000
#define EQPlayer__dEQPlayer_x                                      0x63C720
#define EQPlayer__DoAttack_x                                       0x650CB0
#define EQPlayer__EQPlayer_x                                       0x63CDD0
#define EQPlayer__SetNameSpriteState_x                             0x641040
#define EQPlayer__SetNameSpriteTint_x                              0x641F00
#define PlayerBase__HasProperty_j_x                                0x979010
#define EQPlayer__IsTargetable_x                                   0x9794B0
#define EQPlayer__CanSee_x                                         0x979310
#define EQPlayer__CanSee1_x                                        0x9793E0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9790D0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x653A80
#define PlayerZoneClient__GetLevel_x                               0x656030
#define PlayerZoneClient__IsValidTeleport_x                        0x5C4030
#define PlayerZoneClient__LegalPlayerRace_x                        0x545180

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x64BD90
#define EQPlayerManager__GetSpawnByName_x                          0x64BDB0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x64BE40

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x610100
#define KeypressHandler__AttachKeyToEqCommand_x                    0x610140
#define KeypressHandler__ClearCommandStateArray_x                  0x611530
#define KeypressHandler__HandleKeyDown_x                           0x611550
#define KeypressHandler__HandleKeyUp_x                             0x6115F0
#define KeypressHandler__SaveKeymapping_x                          0x6119D0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x767820
#define MapViewMap__SaveEx_x                                       0x76ABC0
#define MapViewMap__SetZoom_x                                      0x76F280

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B5C50

// StringTable 
#define StringTable__getString_x                                   0x8B0C10

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x636D20
#define PcZoneClient__RemovePetEffect_x                            0x637350
#define PcZoneClient__HasAlternateAbility_x                        0x6310B0
#define PcZoneClient__GetCurrentMod_x                              0x4E2460
#define PcZoneClient__GetModCap_x                                  0x4E2360
#define PcZoneClient__CanEquipItem_x                               0x631760
#define PcZoneClient__GetItemByID_x                                0x634330
#define PcZoneClient__GetItemByItemClass_x                         0x634480
#define PcZoneClient__RemoveBuffEffect_x                           0x637370
#define PcZoneClient__BandolierSwap_x                              0x632390

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C8C20

//IconCache
#define IconCache__GetIcon_x                                       0x708580

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x700060
#define CContainerMgr__CloseContainer_x                            0x700330
#define CContainerMgr__OpenExperimentContainer_x                   0x700DB0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C2CA0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x604990

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75DCC0
#define CLootWnd__RequestLootSlot_x                                0x75D070

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x564420
#define EQ_Spell__SpellAffects_x                                   0x564890
#define EQ_Spell__SpellAffectBase_x                                0x564650
#define EQ_Spell__IsStackable_x                                    0x4C7030
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6EB0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B4220
#define EQ_Spell__IsSPAStacking_x                                  0x5656C0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x564BE0
#define EQ_Spell__IsNoRemove_x                                     0x4C7010
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5656D0
#define __IsResEffectSpell_x                                       0x4C6300

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AAAF0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C01E0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8084B0
#define CTargetWnd__WndNotification_x                              0x807D40
#define CTargetWnd__RefreshTargetBuffs_x                           0x808010
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x806EA0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x80CB70

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x528900
#define CTaskManager__HandleMessage_x                              0x527080

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55F9A0
#define EqSoundManager__PlayScriptMp3_x                            0x55FB00
#define EqSoundManager__SoundAssistPlay_x                          0x66E970
#define EqSoundManager__WaveInstancePlay_x                         0x66DEE0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51C900

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x931EB0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x553B00
#define CAltAbilityData__GetMercMaxRank_x                          0x553AA0
#define CAltAbilityData__GetMaxRank_x                              0x548EC0

//CTargetRing
#define CTargetRing__Cast_x                                        0x602A90

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6E90
#define CharacterBase__CreateItemGlobalIndex_x                     0x502910
#define CharacterBase__CreateItemIndex_x                           0x60AB80
#define CharacterBase__GetItemPossession_x                         0x4B40D0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C8870
#define CharacterBase__GetEffectId_x                               0x4C6E40

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E8220
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E8A40

//messages
#define msg_spell_worn_off_x                                       0x589070
#define msg_new_text_x                                             0x57DEA0
#define __msgTokenTextParam_x                                      0x58B6E0
#define msgTokenText_x                                             0x58B930

//SpellManager
#define SpellManager__vftable_x                                    0xAB3A90
#define SpellManager__SpellManager_x                               0x671CA0
#define Spellmanager__LoadTextSpells_x                             0x672570
#define SpellManager__GetSpellByGroupAndRank_x                     0x671E70

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x97CF80

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x502FF0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58F4E0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x623720
#define ItemGlobalIndex__IsValidIndex_x                            0x503050

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C0B20
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C0DA0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7568A0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7047A0
#define CCursorAttachment__Deactivate_x                            0x705780

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9445F0
#define CEQSuiteTextureLoader__GetTexture_x                        0x9442B0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FFF00

//IString
#define IString__Append_x                                          0x4EFAB0

//Camera
#define CDisplay__cameraType_x                                     0xDC5B38
#define EverQuest__Cameras_x                                       0xE88840

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5087A0
#define LootFiltersManager__GetItemFilterData_x                    0x508090
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5080C0
#define LootFiltersManager__SetItemLootFilter_x                    0x5082E0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B0D20

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x982D10
#define CResolutionHandler__GetWindowedStyle_x                     0x6694A0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6FCE30

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D3330

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x71D000
#define CGroupWnd__UpdateDisplay_x                                 0x71C370

//ItemBase
#define ItemBase__IsLore_x                                         0x8967C0
#define ItemBase__IsLoreEquipped_x                                 0x896830

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C2DD0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C2F80
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C2FE0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x65EAA0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6626F0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";

