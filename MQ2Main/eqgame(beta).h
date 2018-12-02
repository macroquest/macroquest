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
#define __ExpectedVersionDate                                     "Dec  2 2018"
#define __ExpectedVersionTime                                     "04:43:58"
#define __ActualVersionDate_x                                      0xAD1134
#define __ActualVersionTime_x                                      0xAD1128

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x616660
#define __MemChecker1_x                                            0x8EB350
#define __MemChecker2_x                                            0x6A5BA0
#define __MemChecker3_x                                            0x6A5AF0
#define __MemChecker4_x                                            0x842710
#define __EncryptPad0_x                                            0xC05340
#define __EncryptPad1_x                                            0xC635D0
#define __EncryptPad2_x                                            0xC15EC8
#define __EncryptPad3_x                                            0xC15AC8
#define __EncryptPad4_x                                            0xC53E40
#define __EncryptPad5_x                                            0x1034AE0
#define __AC1_x                                                    0x7FF106
#define __AC2_x                                                    0x5D140F
#define __AC3_x                                                    0x5D829F
#define __AC4_x                                                    0x5DC0C0
#define __AC5_x                                                    0x5E2320
#define __AC6_x                                                    0x5E68F6
#define __AC7_x                                                    0x5D0E80
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
#define __do_loot_x                                                0x59EBA0
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
#define __ScreenMode_x                                             0xDC6A90
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
#define pinstCamActor_x                                            0xDC6A84
#define pinstCDBStr_x                                              0xDC6424
#define pinstCDisplay_x                                            0xE7AAB4
#define pinstCEverQuest_x                                          0x1034C20
#define pinstEverQuestInfo_x                                       0xE88138
#define pinstCharData_x                                            0xE7ACEC
#define pinstCharSpawn_x                                           0xE7A89C
#define pinstControlledMissile_x                                   0xE7ACDC
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
#define pinstPCData_x                                              0xE7ACEC
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
#define pinstTrackTarget_x                                         0xE7A8A8
#define pinstTradeTarget_x                                         0xE7A858
#define instTributeActive_x                                        0xDC6385
#define pinstViewActor_x                                           0xDC6A80
#define pinstWorldData_x                                           0xE7A764
#define pinstZoneAddr_x                                            0xE886B8
#define pinstPlayerPath_x                                          0xF28D60
#define pinstTargetIndicator_x                                     0xF29B18
#define pinstCTargetManager_x                                      0xF29BB0
#define EQObject_Top_x                                             0xE7A804

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDC6540
#define pinstCAchievementsWnd_x                                    0xDC652C
#define pinstCActionsWnd_x                                         0xDC65A4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDC6A40
#define pinstCAdvancedLootWnd_x                                    0xDC6588
#define pinstCAdventureLeaderboardWnd_x                            0x1036240
#define pinstCAdventureRequestWnd_x                                0x10362F0
#define pinstCAdventureStatsWnd_x                                  0x10363A0
#define pinstCAggroMeterWnd_x                                      0xDC6AC4
#define pinstCAlarmWnd_x                                           0xDC6B30
#define pinstCAlertHistoryWnd_x                                    0xDC64E8
#define pinstCAlertStackWnd_x                                      0xDC6AD8
#define pinstCAlertWnd_x                                           0xDC6AF8
#define pinstCAltStorageWnd_x                                      0x1036700
#define pinstCAudioTriggersWindow_x                                0xC7A298
#define pinstCAuraWnd_x                                            0xDC6AC0
#define pinstCAvaZoneWnd_x                                         0xDC64F0
#define pinstCBandolierWnd_x                                       0xDC6B08
#define pinstCBankWnd_x                                            0xDC64EC
#define pinstCBarterMerchantWnd_x                                  0x1037940
#define pinstCBarterSearchWnd_x                                    0x10379F0
#define pinstCBarterWnd_x                                          0x1037AA0
#define pinstCBazaarConfirmationWnd_x                              0xDC6AD4
#define pinstCBazaarSearchWnd_x                                    0xDC662C
#define pinstCBazaarWnd_x                                          0xDC6B04
#define pinstCBlockedBuffWnd_x                                     0xDC64D0
#define pinstCBlockedPetBuffWnd_x                                  0xDC64FC
#define pinstCBodyTintWnd_x                                        0xDC6AA4
#define pinstCBookWnd_x                                            0xDC6B2C
#define pinstCBreathWnd_x                                          0xDC6544
#define pinstCBuffWindowNORMAL_x                                   0xDC6D48
#define pinstCBuffWindowSHORT_x                                    0xDC6D4C
#define pinstCBugReportWnd_x                                       0xDC6538
#define pinstCButtonWnd_x                                          0x16B8728
#define pinstCCastingWnd_x                                         0xDC6534
#define pinstCCastSpellWnd_x                                       0xDC6A44
//#define pinstCCharacterCreationWnd_x                             0xDAAE5C
#define pinstCCharacterListWnd_x                                   0xDC6548
#define pinstCChatWindowManager_x                                  0x1038560
#define pinstCClaimWnd_x                                           0x10386B8
#define pinstCColorPickerWnd_x                                     0xDC6578
#define pinstCCombatAbilityWnd_x                                   0xDC6ACC
#define pinstCCombatSkillsSelectWnd_x                              0xDC65A0
#define pinstCCompassWnd_x                                         0xDC6A74
#define pinstCConfirmationDialog_x                                 0x103D5B8
#define pinstCContainerMgr_x                                       0xDC6ADC
#define pinstCContextMenuManager_x                                 0x16B84B8
#define pinstCCursorAttachment_x                                   0xDC6530
#define pinstCDistillerInfo_x                                      0x103BFC4
#define pinstCDynamicZoneWnd_x                                     0x1038C80
#define pinstCEditLabelWnd_x                                       0xDC6D38
#define pinstCEQMainWnd_x                                          0x1038EC8
#define pinstCEventCalendarWnd_x                                   0xDC655C
#define pinstCExtendedTargetWnd_x                                  0xDC6AB4
#define pinstCFacePick_x                                           0xDC6570
#define pinstCFactionWnd_x                                         0xDC6528
#define pinstCFellowshipWnd_x                                      0x10390C8
#define pinstCFileSelectionWnd_x                                   0xDC6574
#define pinstCFindItemWnd_x                                        0xDC6B24
#define pinstCFindLocationWnd_x                                    0x1039220
#define pinstCFriendsWnd_x                                         0xDC65C4
#define pinstCGemsGameWnd_x                                        0xDC6B00
#define pinstCGiveWnd_x                                            0xDC6B28
#define pinstCGroupSearchFiltersWnd_x                              0xDC6AE4
#define pinstCGroupSearchWnd_x                                     0x1039618
#define pinstCGroupWnd_x                                           0x10396C8
#define pinstCGuildBankWnd_x                                       0xE894FC
#define pinstCGuildCreationWnd_x                                   0x1039828
#define pinstCGuildMgmtWnd_x                                       0x10398D8
#define pinstCharacterCreation_x                                   0xDC6AC8
#define pinstCHelpWnd_x                                            0xDC6A7C
#define pinstCHeritageSelectionWnd_x                               0xDC6584
#define pinstCHotButtonWnd_x                                       0x103BA30
#define pinstCHotButtonWnd1_x                                      0x103BA30
#define pinstCHotButtonWnd2_x                                      0x103BA34
#define pinstCHotButtonWnd3_x                                      0x103BA38
#define pinstCHotButtonWnd4_x                                      0x103BA3C
#define pinstCIconSelectionWnd_x                                   0xDC650C
#define pinstCInspectWnd_x                                         0xDC6508
#define pinstCInventoryWnd_x                                       0xDC6B10
#define pinstCInvSlotMgr_x                                         0xDC6AAC
#define pinstCItemDisplayManager_x                                 0x103BFC0
#define pinstCItemExpTransferWnd_x                                 0x103C0F0
#define pinstCItemOverflowWnd_x                                    0xDC6630
#define pinstCJournalCatWnd_x                                      0xDC6590
//#define pinstCJournalNPCWnd_x                                    0xDAB354
#define pinstCJournalTextWnd_x                                     0xDC6554
#define pinstCKeyRingWnd_x                                         0xDC64C4
#define pinstCLargeDialogWnd_x                                     0x103E238
#define pinstCLayoutCopyWnd_x                                      0x103C440
#define pinstCLFGuildWnd_x                                         0x103C4F0
#define pinstCLoadskinWnd_x                                        0xDC6B0C
#define pinstCLootFiltersCopyWnd_x                                 0xC962B8
#define pinstCLootFiltersWnd_x                                     0xDC6B20
#define pinstCLootSettingsWnd_x                                    0xDC6D40
#define pinstCLootWnd_x                                            0xDC6564
#define pinstCMailAddressBookWnd_x                                 0xDC6500
#define pinstCMailCompositionWnd_x                                 0xDC64DC
#define pinstCMailIgnoreListWnd_x                                  0xDC6504
#define pinstCMailWnd_x                                            0xDC6D50
#define pinstCManageLootWnd_x                                      0xDC7B68
#define pinstCMapToolbarWnd_x                                      0xDC6B14
#define pinstCMapViewWnd_x                                         0xDC6AEC
#define pinstCMarketplaceWnd_x                                     0xDC6568
#define pinstCMerchantWnd_x                                        0xDC659C
#define pinstCMIZoneSelectWnd_x                                    0x103CD28
#define pinstCMusicPlayerWnd_x                                     0xDC64C0
#define pinstCNameChangeMercWnd_x                                  0xDC6AA8
#define pinstCNameChangePetWnd_x                                   0xDC6A6C
#define pinstCNameChangeWnd_x                                      0xDC654C
#define pinstCNoteWnd_x                                            0xDC6A4C
#define pinstCObjectPreviewWnd_x                                   0xDC658C
#define pinstCOptionsWnd_x                                         0xDC6B18
#define pinstCPetInfoWnd_x                                         0xDC64E0
#define pinstCPetitionQWnd_x                                       0xDC65A8
//#define pinstCPlayerCustomizationWnd_x                           0xDAADC4
#define pinstCPlayerNotesWnd_x                                     0xDC6A9C
#define pinstCPlayerWnd_x                                          0xDC65B0
#define pinstCPopupWndManager_x                                    0x103D5B8
#define pinstCProgressionSelectionWnd_x                            0x103D668
#define pinstCPurchaseGroupWnd_x                                   0xDC6A38
#define pinstCPurchaseWnd_x                                        0xDC6594
#define pinstCPvPLeaderboardWnd_x                                  0x103D718
#define pinstCPvPStatsWnd_x                                        0x103D7C8
#define pinstCQuantityWnd_x                                        0xDC6514
#define pinstCRaceChangeWnd_x                                      0xDC656C
#define pinstCRaidOptionsWnd_x                                     0xDC6AE8
#define pinstCRaidWnd_x                                            0xDC6518
#define pinstCRealEstateItemsWnd_x                                 0xDC653C
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDC6558
#define pinstCRealEstateManageWnd_x                                0xDC6D44
#define pinstCRealEstateNeighborhoodWnd_x                          0xDC64C8
#define pinstCRealEstatePlotSearchWnd_x                            0xDC64F4
#define pinstCRealEstatePurchaseWnd_x                              0xDC651C
#define pinstCRespawnWnd_x                                         0xDC6AE0
//#define pinstCRewardSelectionWnd_x                               0x1022600
#define pinstCSelectorWnd_x                                        0xDC6AB8
#define pinstCSendMoneyWnd_x                                       0xDC6D3C
#define pinstCServerListWnd_x                                      0xDC64E4
#define pinstCSkillsSelectWnd_x                                    0xDC657C
#define pinstCSkillsWnd_x                                          0xDC6560
#define pinstCSocialEditWnd_x                                      0xDC6524
#define pinstCSocialWnd_x                                          0xDC6ABC
#define pinstCSpellBookWnd_x                                       0xDC6AB0
#define pinstCStoryWnd_x                                           0xDC6A48
#define pinstCTargetOfTargetWnd_x                                  0x103F5F8
#define pinstCTargetWnd_x                                          0xDC64D4
#define pinstCTaskOverlayWnd_x                                     0xDC64F8
#define pinstCTaskSelectWnd_x                                      0x103F750
#define pinstCTaskManager_x                                        0xC96AB8
#define pinstCTaskTemplateSelectWnd_x                              0x103F800
#define pinstCTaskWnd_x                                            0x103F8B0
#define pinstCTextEntryWnd_x                                       0xDC6A78
#define pinstCTextOverlay_x                                        0xC7A5A8
#define pinstCTimeLeftWnd_x                                        0xDC6580
#define pinstCTipWndCONTEXT_x                                      0x103FAB4
#define pinstCTipWndOFDAY_x                                        0x103FAB0
#define pinstCTitleWnd_x                                           0x103FB60
#define pinstCTrackingWnd_x                                        0xDC64D8
#define pinstCTradeskillWnd_x                                      0x103FCC8
#define pinstCTradeWnd_x                                           0xDC6AA0
#define pinstCTrainWnd_x                                           0xDC6510
#define pinstCTributeBenefitWnd_x                                  0x103FEC8
#define pinstCTributeMasterWnd_x                                   0x103FF78
#define pinstCTributeTrophyWnd_x                                   0x1040028
#define pinstCVideoModesWnd_x                                      0xDC6AD0
#define pinstCVoiceMacroWnd_x                                      0xF2A0E0
#define pinstCVoteResultsWnd_x                                     0xDC6A3C
#define pinstCVoteWnd_x                                            0xDC65AC
#define pinstCWebManager_x                                         0xF2A244
#define pinstCZoneGuideWnd_x                                       0xDC6D54
#define pinstCZonePathWnd_x                                        0xDC64CC

#define pinstEQSuiteTextureLoader_x                                0xC650A0
#define pinstItemIconCache_x                                       0x1038E80
#define pinstLootFiltersManager_x                                  0xC96368
#define pinstRewardSelectionWnd_x                                  0x103DF10

//// 
// Section 3: Miscellaneous Offsets 
////
#define __AppCrashWrapper_x                                        0xC15ABC
#define __CastRay_x                                                0x59A0C0
#define __CastRay2_x                                               0x59A110
#define __ConvertItemTags_x                                        0x5B4D40
#define __CrashHandler_x                                           0x84C070
#define __EQGetTime_x                                              0x8EAE40
#define __ExecuteCmd_x                                             0x5929F0
#define __FixHeading_x                                             0x97BA60
#define __get_bearing_x                                            0x599C10
#define __get_melee_range_x                                        0x59A300
#define __GetAnimationCache_x                                      0x7094A0
#define __GetGaugeValueFromEQ_x                                    0x7FD910
#define __GetLabelFromEQ_x                                         0x7FF090
#define __GetXTargetType_x                                         0x97D530
#define __HeadingDiff_x                                            0x97BAD0
#define __HelpPath_x                                               0xF27594
#define __LoadFrontEnd_x                                           0x6A1A00
#define __NewUIINI_x                                               0x7FD5E0
#define __pCrashHandler_x                                          0x105D418
#define __ProcessGameEvents_x                                      0x5F7C00
#define __ProcessMouseEvent_x                                      0x5F73C0
#define __SaveColors_x                                             0x542C90
#define __STMLToText_x                                             0x91ED50
#define __ToggleKeyRingItem_x                                      0x505EF0
#define CrashDetected_x                                            0x6A34F0
#define DrawNetStatus_x                                            0x623D20
#define Expansion_HoT_x                                            0xE89504
#define Teleport_Table_Size_x                                      0xE7A800
#define Teleport_Table_x                                           0xE78640
#define Util__FastTime_x                                           0x8EAA00
#define wwsCrashReportCheckForUploader_x                           0x84CDC0
#define wwsCrashReportPlatformLaunchUploader_x                     0x84F480
#define __HandleMouseWheel_x                                       0x6A5C50

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B6F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494570
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494330

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54A6D0
#define AltAdvManager__IsAbilityReady_x                            0x549620
#define AltAdvManager__GetAAById_x                                 0x549820
#define AltAdvManager__CanTrainAbility_x                           0x549890
#define AltAdvManager__CanSeeAbility_x                             0x549BF0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C76E0
#define CharacterZoneClient__HasSkill_x                            0x4D23B0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3AD0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BBA50
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B81D0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6480
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D6560
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6640
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0530
#define CharacterZoneClient__BardCastBard_x                        0x4C31A0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B82A0
#define CharacterZoneClient__GetEffect_x                           0x4B8110
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1530
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1600
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C1650
#define CharacterZoneClient__CalcAffectChange_x                    0x4C17A0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C1970

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CB980

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D92D0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x6063B0
#define CButtonWnd__CButtonWnd_x                                   0x91B170

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F7E60
#define CChatManager__InitContextMenu_x                            0x6F1F00
#define CChatManager__FreeChatWindow_x                             0x6F6D70
#define CChatManager__GetLockedActiveChatWindow_x                  0x6FB770
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F7C00

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x92F990
#define CContextMenu__dCContextMenu_x                              0x92FBC0
#define CContextMenu__AddMenuItem_x                                0x92FBD0
#define CContextMenu__RemoveMenuItem_x                             0x92FED0
#define CContextMenu__RemoveAllMenuItems_x                         0x92FEF0
#define CContextMenu__CheckMenuItem_x                              0x92FF70
#define CContextMenu__SetMenuItem_x                                0x92FE00
#define CContextMenu__AddSeparator_x                               0x92FD60

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x930510
#define CContextMenuManager__RemoveMenu_x                          0x930580
#define CContextMenuManager__PopupMenu_x                           0x930640
#define CContextMenuManager__Flush_x                               0x9304B0
#define CContextMenuManager__GetMenu_x                             0x4967C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CB670
#define CChatService__GetFriendName_x                              0x8CB680

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F83D0
#define CChatWindow__Clear_x                                       0x6F9430
#define CChatWindow__WndNotification_x                             0x6F99A0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x92CE20
#define CComboWnd__Draw_x                                          0x92C320
#define CComboWnd__GetCurChoice_x                                  0x92CC60
#define CComboWnd__GetListRect_x                                   0x92C7D0
#define CComboWnd__GetTextRect_x                                   0x92CE80
#define CComboWnd__InsertChoice_x                                  0x92C960
#define CComboWnd__SetColors_x                                     0x92C930
#define CComboWnd__SetChoice_x                                     0x92CC30
#define CComboWnd__GetItemCount_x                                  0x92CC70
#define CComboWnd__GetCurChoiceText_x                              0x92CCB0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x701670
#define CContainerWnd__vftable_x                                   0xADA3D8
#define CContainerWnd__SetContainer_x                              0x702BE0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x542A50
#define CDisplay__GetClickedActor_x                                0x535A00
#define CDisplay__GetUserDefinedColor_x                            0x52E0E0
#define CDisplay__GetWorldFilePath_x                               0x537450
#define CDisplay__is3dON_x                                         0x5326D0
#define CDisplay__ReloadUI_x                                       0x53CB70
#define CDisplay__WriteTextHD2_x                                   0x5324B0
#define CDisplay__TrueDistance_x                                   0x5390B0
#define CDisplay__SetViewActor_x                                   0x535350
#define CDisplay__GetFloorHeight_x                                 0x532790
#define CDisplay__SetRenderWindow_x                                0x5310C0
#define CDisplay__ToggleScreenshotMode_x                           0x534E20

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94F140

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x934060
#define CEditWnd__GetCharIndexPt_x                                 0x934F40
#define CEditWnd__GetDisplayString_x                               0x934DE0
#define CEditWnd__GetHorzOffset_x                                  0x9336A0
#define CEditWnd__GetLineForPrintableChar_x                        0x936040
#define CEditWnd__GetSelStartPt_x                                  0x9351E0
#define CEditWnd__GetSTMLSafeText_x                                0x934C00
#define CEditWnd__PointFromPrintableChar_x                         0x935C80
#define CEditWnd__SelectableCharFromPoint_x                        0x935DF0
#define CEditWnd__SetEditable_x                                    0x9352A0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E5E20
#define CEverQuest__ClickedPlayer_x                                0x5D8080
#define CEverQuest__CreateTargetIndicator_x                        0x5F4EB0
#define CEverQuest__DeleteTargetIndicator_x                        0x5F4F40
#define CEverQuest__DoTellWindow_x                                 0x4E3590
#define CEverQuest__OutputTextToLog_x                              0x4E37C0
#define CEverQuest__DropHeldItemOnGround_x                         0x5CD940
#define CEverQuest__dsp_chat_x                                     0x4E3B50
#define CEverQuest__trimName_x                                     0x5F1230
#define CEverQuest__Emote_x                                        0x5E6630
#define CEverQuest__EnterZone_x                                    0x5E06D0
#define CEverQuest__GetBodyTypeDesc_x                              0x5EAAD0
#define CEverQuest__GetClassDesc_x                                 0x5EB110
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EB710
#define CEverQuest__GetDeityDesc_x                                 0x5F3800
#define CEverQuest__GetLangDesc_x                                  0x5EB8D0
#define CEverQuest__GetRaceDesc_x                                  0x5EB0F0
#define CEverQuest__InterpretCmd_x                                 0x5F3DD0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D1B30
#define CEverQuest__LMouseUp_x                                     0x5CFEB0
#define CEverQuest__RightClickedOnPlayer_x                         0x5D2410
#define CEverQuest__RMouseUp_x                                     0x5D0E40
#define CEverQuest__SetGameState_x                                 0x5CD6D0
#define CEverQuest__UPCNotificationFlush_x                         0x5F1130
#define CEverQuest__IssuePetCommand_x                              0x5ECCD0
#define CEverQuest__ReportSuccessfulHit_x                          0x5E7A30

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x713620
#define CGaugeWnd__CalcLinesFillRect_x                             0x713680
#define CGaugeWnd__Draw_x                                          0x712D10

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACD00
#define CGuild__GetGuildName_x                                     0x4ABDE0
#define CGuild__GetGuildIndex_x                                    0x4AC170

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72EA70

//CHotButton
#define CHotButton__SetButtonSize_x                                0x606770

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x73BA80
#define CInvSlotMgr__MoveItem_x                                    0x73A790
#define CInvSlotMgr__SelectSlot_x                                  0x73BB50

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x739040
#define CInvSlot__SliderComplete_x                                 0x736DA0
#define CInvSlot__GetItemBase_x                                    0x736710
#define CInvSlot__UpdateItem_x                                     0x736880

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x73D4A0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x73C770
#define CInvSlotWnd__HandleLButtonUp_x                             0x73D020

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F9AF0
#define CItemDisplayWnd__UpdateStrings_x                           0x74B780
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x745710
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x745C30
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x74BDA0
#define CItemDisplayWnd__AboutToShow_x                             0x74B3C0
#define CItemDisplayWnd__WndNotification_x                         0x74D2F0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x831550

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x751430

// CLabel 
#define CLabel__Draw_x                                             0x756F00

// CListWnd
#define CListWnd__CListWnd_x                                       0x9054A0
#define CListWnd__dCListWnd_x                                      0x9057C0
#define CListWnd__AddColumn_x                                      0x909AC0
#define CListWnd__AddColumn1_x                                     0x909B10
#define CListWnd__AddLine_x                                        0x909EA0
#define CListWnd__AddString_x                                      0x909CA0
#define CListWnd__CalculateFirstVisibleLine_x                      0x909880
#define CListWnd__CalculateVSBRange_x                              0x909670
#define CListWnd__ClearSel_x                                       0x90A680
#define CListWnd__ClearAllSel_x                                    0x90A6E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90B0F0
#define CListWnd__Compare_x                                        0x908FB0
#define CListWnd__Draw_x                                           0x9058C0
#define CListWnd__DrawColumnSeparators_x                           0x908090
#define CListWnd__DrawHeader_x                                     0x908500
#define CListWnd__DrawItem_x                                       0x9088F0
#define CListWnd__DrawLine_x                                       0x908200
#define CListWnd__DrawSeparator_x                                  0x908130
#define CListWnd__EnableLine_x                                     0x907970
#define CListWnd__EnsureVisible_x                                  0x90B020
#define CListWnd__ExtendSel_x                                      0x90A5B0
#define CListWnd__GetColumnMinWidth_x                              0x9074B0
#define CListWnd__GetColumnWidth_x                                 0x907420
#define CListWnd__GetCurSel_x                                      0x906DB0
#define CListWnd__GetItemAtPoint_x                                 0x907BE0
#define CListWnd__GetItemAtPoint1_x                                0x907C50
#define CListWnd__GetItemData_x                                    0x906E30
#define CListWnd__GetItemHeight_x                                  0x9071F0
#define CListWnd__GetItemIcon_x                                    0x906FC0
#define CListWnd__GetItemRect_x                                    0x907A60
#define CListWnd__GetItemText_x                                    0x906E70
#define CListWnd__GetSelList_x                                     0x90A730
#define CListWnd__GetSeparatorRect_x                               0x907E90
#define CListWnd__InsertLine_x                                     0x90A290
#define CListWnd__RemoveLine_x                                     0x90A3E0
#define CListWnd__SetColors_x                                      0x909640
#define CListWnd__SetColumnJustification_x                         0x909370
#define CListWnd__SetColumnWidth_x                                 0x909290
#define CListWnd__SetCurSel_x                                      0x90A4F0
#define CListWnd__SetItemColor_x                                   0x90ACE0
#define CListWnd__SetItemData_x                                    0x90ACA0
#define CListWnd__SetItemText_x                                    0x90A8B0
#define CListWnd__ShiftColumnSeparator_x                           0x909430
#define CListWnd__Sort_x                                           0x909130
#define CListWnd__ToggleSel_x                                      0x90A520

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x76C340
#define CMapViewWnd__GetWorldCoordinates_x                         0x76AA50
#define CMapViewWnd__HandleLButtonDown_x                           0x767AB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78F700
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x78FFE0
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x790510
#define CMerchantWnd__SelectRecoverySlot_x                         0x793350
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x78E0F0
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x798F40
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78F340

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x899520
#define CPacketScrambler__hton_x                                   0x899510

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x924330
#define CSidlManager__FindScreenPieceTemplate_x                    0x924740
#define CSidlManager__FindScreenPieceTemplate1_x                   0x924530
#define CSidlManager__CreateLabel_x                                0x7F0ED0
#define CSidlManager__CreateXWndFromTemplate_x                     0x927810
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9279F0
#define CSidlManager__CreateXWnd_x                                 0x7F0E00
#define CSidlManager__CreateHotButtonWnd_x                         0x7F13D0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x920EB0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x920DB0
#define CSidlScreenWnd__ConvertToRes_x                             0x945F80
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x920840
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x920530
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x920600
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9206D0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x921350
#define CSidlScreenWnd__EnableIniStorage_x                         0x921820
#define CSidlScreenWnd__GetSidlPiece_x                             0x921540
#define CSidlScreenWnd__Init1_x                                    0x920120
#define CSidlScreenWnd__LoadIniInfo_x                              0x921870
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9223A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91F530
#define CSidlScreenWnd__StoreIniInfo_x                             0x921F20
#define CSidlScreenWnd__StoreIniVis_x                              0x922280
#define CSidlScreenWnd__WndNotification_x                          0x921260
#define CSidlScreenWnd__GetChildItem_x                             0x9217A0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x910EA0
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B8388

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66AD20
#define CSkillMgr__GetSkillCap_x                                   0x66AF00
#define CSkillMgr__GetNameToken_x                                  0x66A4B0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x931300
#define CSliderWnd__SetValue_x                                     0x931170
#define CSliderWnd__SetNumTicks_x                                  0x9311D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F6D60

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x937FB0
#define CStmlWnd__CalculateHSBRange_x                              0x939040
#define CStmlWnd__CalculateVSBRange_x                              0x938FB0
#define CStmlWnd__CanBreakAtCharacter_x                            0x93D3B0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x93E040
#define CStmlWnd__ForceParseNow_x                                  0x938550
#define CStmlWnd__GetNextTagPiece_x                                0x93D310
#define CStmlWnd__GetSTMLText_x                                    0x4F58D0
#define CStmlWnd__GetVisibleText_x                                 0x938570
#define CStmlWnd__InitializeWindowVariables_x                      0x93DE90
#define CStmlWnd__MakeStmlColorTag_x                               0x937690
#define CStmlWnd__MakeWndNotificationTag_x                         0x937700
#define CStmlWnd__SetSTMLText_x                                    0x936740
#define CStmlWnd__StripFirstSTMLLines_x                            0x93F1A0
#define CStmlWnd__UpdateHistoryString_x                            0x93E250

// CTabWnd 
#define CTabWnd__Draw_x                                            0x942EB0
#define CTabWnd__DrawCurrentPage_x                                 0x9434D0
#define CTabWnd__DrawTab_x                                         0x9432A0
#define CTabWnd__GetCurrentPage_x                                  0x942710
#define CTabWnd__GetPageInnerRect_x                                0x942950
#define CTabWnd__GetTabInnerRect_x                                 0x942890
#define CTabWnd__GetTabRect_x                                      0x942740
#define CTabWnd__InsertPage_x                                      0x942B40
#define CTabWnd__SetPage_x                                         0x9429D0
#define CTabWnd__SetPageRect_x                                     0x942DF0
#define CTabWnd__UpdatePage_x                                      0x943160
#define CTabWnd__GetPageFromTabIndex_x                             0x9431E0
#define CTabWnd__GetCurrentTabIndex_x                              0x942700

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x751890
#define CPageWnd__SetTabText_x                                     0x94F550

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A68C0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x90DD10
#define CTextureFont__GetTextExtent_x                              0x90DED0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69E850
#define CHtmlComponentWnd__ValidateUri_x                           0x730460
#define CHtmlWnd__SetClientCallbacks_x                             0x60B730
#define CHtmlWnd__AddObserver_x                                    0x60B750
#define CHtmlWnd__RemoveObserver_x                                 0x60B7B0
#define Window__getProgress_x                                      0x849CE0
#define Window__getStatus_x                                        0x849D00
#define Window__getURI_x                                           0x849D10

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94BAD0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FAD50

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4AE060
#define CXStr__CXStr1_x                                            0x4F08F0
#define CXStr__CXStr3_x                                            0x8E6F70
#define CXStr__dCXStr_x                                            0x472F50
#define CXStr__operator_equal_x                                    0x8E71A0
#define CXStr__operator_equal1_x                                   0x8E71E0
#define CXStr__operator_plus_equal1_x                              0x8E7C70

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92F5A0
#define CXWnd__BringToTop_x                                        0x9146D0
#define CXWnd__Center_x                                            0x914250
#define CXWnd__ClrFocus_x                                          0x914090
#define CXWnd__Destroy_x                                           0x914130
#define CXWnd__DoAllDrawing_x                                      0x910630
#define CXWnd__DrawChildren_x                                      0x910600
#define CXWnd__DrawColoredRect_x                                   0x910A90
#define CXWnd__DrawTooltip_x                                       0x90F160
#define CXWnd__DrawTooltipAtPoint_x                                0x90F220
#define CXWnd__GetBorderFrame_x                                    0x9108F0
#define CXWnd__GetChildWndAt_x                                     0x914770
#define CXWnd__GetClientClipRect_x                                 0x912900
#define CXWnd__GetScreenClipRect_x                                 0x9129D0
#define CXWnd__GetScreenRect_x                                     0x912B90
#define CXWnd__GetTooltipRect_x                                    0x910AE0
#define CXWnd__GetWindowTextA_x                                    0x497F30
#define CXWnd__IsActive_x                                          0x917650
#define CXWnd__IsDescendantOf_x                                    0x9135C0
#define CXWnd__IsReallyVisible_x                                   0x9135F0
#define CXWnd__IsType_x                                            0x914DE0
#define CXWnd__Move_x                                              0x913660
#define CXWnd__Move1_x                                             0x913720
#define CXWnd__ProcessTransition_x                                 0x914200
#define CXWnd__Refade_x                                            0x913A00
#define CXWnd__Resize_x                                            0x913CA0
#define CXWnd__Right_x                                             0x914490
#define CXWnd__SetFocus_x                                          0x914050
#define CXWnd__SetFont_x                                           0x9140C0
#define CXWnd__SetKeyTooltip_x                                     0x914C00
#define CXWnd__SetMouseOver_x                                      0x911A60
#define CXWnd__StartFade_x                                         0x913490
#define CXWnd__GetChildItem_x                                      0x9148E0
#define CXWnd__SetParent_x                                         0x913350

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x947050

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x917690
#define CXWndManager__DrawWindows_x                                0x9176B0
#define CXWndManager__GetKeyboardFlags_x                           0x919E10
#define CXWndManager__HandleKeyboardMsg_x                          0x919A10
#define CXWndManager__RemoveWnd_x                                  0x91A050
#define CXWndManager__RemovePendingDeletionWnd_x                   0x91A590

// CDBStr
#define CDBStr__GetString_x                                        0x52D090

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B9180
#define EQ_Character__Cur_HP_x                                     0x4CF430
#define EQ_Character__Cur_Mana_x                                   0x4D6B40
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BC090
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFC20
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFD70
#define EQ_Character__GetHPRegen_x                                 0x4DCAA0
#define EQ_Character__GetEnduranceRegen_x                          0x4DD0B0
#define EQ_Character__GetManaRegen_x                               0x4DD4F0
#define EQ_Character__Max_Endurance_x                              0x631860
#define EQ_Character__Max_HP_x                                     0x4CF260
#define EQ_Character__Max_Mana_x                                   0x631660
#define EQ_Character__doCombatAbility_x                            0x633D30
#define EQ_Character__UseSkill_x                                   0x4DF300
#define EQ_Character__GetConLevel_x                                0x62ABD0
#define EQ_Character__IsExpansionFlag_x                            0x5911B0
#define EQ_Character__TotalEffect_x                                0x4C2720
#define EQ_Character__GetPCSpellAffect_x                           0x4BCC80
#define EQ_Character__SpellDuration_x                              0x4BC7B0
#define EQ_Character__FindItemByRecord_x                           0x4D4A40
#define EQ_Character__GetAdjustedSkill_x                           0x4D2170
#define EQ_Character__GetBaseSkill_x                               0x4D3110
#define EQ_Character__CanUseItem_x                                 0x4D6E50

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B8520

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x647BB0

//PcClient
#define PcClient__PcClient_x                                       0x628300

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6DF0
#define CCharacterListWnd__EnterWorld_x                            0x4B6830
#define CCharacterListWnd__Quit_x                                  0x4B6540
#define CCharacterListWnd__UpdateList_x                            0x4B69C0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x60C980
#define EQ_Item__CreateItemTagString_x                             0x892E90
#define EQ_Item__IsStackable_x                                     0x8978F0
#define EQ_Item__GetImageNum_x                                     0x8948E0
#define EQ_Item__CreateItemClient_x                                0x60BB30
#define EQ_Item__GetItemValue_x                                    0x895B80
#define EQ_Item__ValueSellMerchant_x                               0x8990C0
#define EQ_Item__IsKeyRingItem_x                                   0x897250
#define EQ_Item__CanGoInBag_x                                      0x60CAA0
#define EQ_Item__GetMaxItemCount_x                                 0x895F40
#define EQ_Item__GetHeldItem_x                                     0x8947B0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8927E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54B3E0
#define EQ_LoadingS__Array_x                                       0xBED130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6321C0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A22D0
#define EQ_PC__GetCombatAbility_x                                  0x8A2940
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A29B0
#define EQ_PC__GetItemRecastTimer_x                                0x6342B0
#define EQ_PC__HasLoreItem_x                                       0x62B3A0
#define EQ_PC__AlertInventoryChanged_x                             0x62A500
#define EQ_PC__GetPcZoneClient_x                                   0x656350
#define EQ_PC__RemoveMyAffect_x                                    0x6374A0
#define EQ_PC__GetKeyRingItems_x                                   0x8A3250
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A2FD0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A3540

// EQItemList 
#define EQItemList__EQItemList_x                                   0x597630
#define EQItemList__add_object_x                                   0x5C3010
#define EQItemList__add_item_x                                     0x597C40
#define EQItemList__delete_item_x                                  0x597C90
#define EQItemList__FreeItemList_x                                 0x597B90

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52A650

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x649430
#define EQPlayer__dEQPlayer_x                                      0x63CB10
#define EQPlayer__DoAttack_x                                       0x651010
#define EQPlayer__EQPlayer_x                                       0x63D1C0
#define EQPlayer__SetNameSpriteState_x                             0x641460
#define EQPlayer__SetNameSpriteTint_x                              0x642330
#define PlayerBase__HasProperty_j_x                                0x979E40
#define EQPlayer__IsTargetable_x                                   0x97A2E0
#define EQPlayer__CanSee_x                                         0x97A140
#define EQPlayer__CanSee1_x                                        0x97A210
#define PlayerBase__GetVisibilityLineSegment_x                     0x979F00

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x653DE0
#define PlayerZoneClient__GetLevel_x                               0x656390
#define PlayerZoneClient__IsValidTeleport_x                        0x5C4160
#define PlayerZoneClient__LegalPlayerRace_x                        0x5447F0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x64C130
#define EQPlayerManager__GetSpawnByName_x                          0x64C150
#define EQPlayerManager__GetPlayerFromPartialName_x                0x64C1E0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x610220
#define KeypressHandler__AttachKeyToEqCommand_x                    0x610260
#define KeypressHandler__ClearCommandStateArray_x                  0x611650
#define KeypressHandler__HandleKeyDown_x                           0x611670
#define KeypressHandler__HandleKeyUp_x                             0x611710
#define KeypressHandler__SaveKeymapping_x                          0x611AF0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7681D0
#define MapViewMap__SaveEx_x                                       0x76B570
#define MapViewMap__SetZoom_x                                      0x76FC40

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B6420

// StringTable 
#define StringTable__getString_x                                   0x8B14C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x637110
#define PcZoneClient__RemovePetEffect_x                            0x637740
#define PcZoneClient__HasAlternateAbility_x                        0x6314A0
#define PcZoneClient__GetCurrentMod_x                              0x4E2400
#define PcZoneClient__GetModCap_x                                  0x4E2300
#define PcZoneClient__CanEquipItem_x                               0x631B50
#define PcZoneClient__GetItemByID_x                                0x634720
#define PcZoneClient__GetItemByItemClass_x                         0x634870
#define PcZoneClient__RemoveBuffEffect_x                           0x637760
#define PcZoneClient__BandolierSwap_x                              0x632780

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C8D40

//IconCache
#define IconCache__GetIcon_x                                       0x708D30

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x700810
#define CContainerMgr__CloseContainer_x                            0x700AE0
#define CContainerMgr__OpenExperimentContainer_x                   0x701560

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C3520

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x604B90

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75E6B0
#define CLootWnd__RequestLootSlot_x                                0x75DA60

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5638B0
#define EQ_Spell__SpellAffects_x                                   0x563D20
#define EQ_Spell__SpellAffectBase_x                                0x563AE0
#define EQ_Spell__IsStackable_x                                    0x4C6FD0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6E50
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B4130
#define EQ_Spell__IsSPAStacking_x                                  0x564B50
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x564070
#define EQ_Spell__IsNoRemove_x                                     0x4C6FB0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x564B60
#define __IsResEffectSpell_x                                       0x4C6280

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AAA10

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C0AB0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x808EE0
#define CTargetWnd__WndNotification_x                              0x808770
#define CTargetWnd__RefreshTargetBuffs_x                           0x808A40
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x8078C0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x80D5B0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5280B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55EE50
#define EqSoundManager__PlayScriptMp3_x                            0x55EFB0
#define EqSoundManager__SoundAssistPlay_x                          0x66EB90
#define EqSoundManager__WaveInstancePlay_x                         0x66E100

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51C080

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x932CE0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x553140
#define CAltAbilityData__GetMercMaxRank_x                          0x5530E0
#define CAltAbilityData__GetMaxRank_x                              0x5484D0

//CTargetRing
#define CTargetRing__Cast_x                                        0x602C80

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6E30
#define CharacterBase__CreateItemGlobalIndex_x                     0x502400
#define CharacterBase__CreateItemIndex_x                           0x60AD70
#define CharacterBase__GetItemPossession_x                         0x4B3FE0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C9140
#define CharacterBase__GetEffectId_x                               0x4C6DE0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E8970
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E9190

//messages
#define msg_spell_worn_off_x                                       0x5891E0
#define msg_new_text_x                                             0x57DFF0
#define __msgTokenTextParam_x                                      0x58B840
#define msgTokenText_x                                             0x58BA90

//SpellManager
#define SpellManager__vftable_x                                    0xAB4A88
#define SpellManager__SpellManager_x                               0x671EB0
#define Spellmanager__LoadTextSpells_x                             0x672780
#define SpellManager__GetSpellByGroupAndRank_x                     0x672080

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x97DE20

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x502AE0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58F6A0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x623B80
#define ItemGlobalIndex__IsValidIndex_x                            0x502B40

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C13F0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C1670

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x757250

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x704F90
#define CCursorAttachment__Deactivate_x                            0x705F60

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x945550
#define CEQSuiteTextureLoader__GetTexture_x                        0x945210

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FF9E0

//IString
#define IString__Append_x                                          0x4EFA30

//Camera
#define CDisplay__cameraType_x                                     0xDC6B34
#define EverQuest__Cameras_x                                       0xE89840

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x508160
#define LootFiltersManager__GetItemFilterData_x                    0x507A60
#define LootFiltersManager__RemoveItemLootFilter_x                 0x507A90
#define LootFiltersManager__SetItemLootFilter_x                    0x507CB0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B14F0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x983C30
#define CResolutionHandler__GetWindowedStyle_x                     0x669720

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6FD5D0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D3C50

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x71D770
#define CGroupWnd__UpdateDisplay_x                                 0x71CAD0

//ItemBase
#define ItemBase__IsLore_x                                         0x8972B0
#define ItemBase__IsLoreEquipped_x                                 0x897320

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F5ED0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C2F00
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C30B0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C3110

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x65EE10
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x662A70

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
