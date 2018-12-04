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
#define __ExpectedVersionDate                                     "Dec  3 2018"
#define __ExpectedVersionTime                                     "04:21:49"
#define __ActualVersionDate_x                                      0xAD112C
#define __ActualVersionTime_x                                      0xAD1120

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x615D10
#define __MemChecker1_x                                            0x8EAD80
#define __MemChecker2_x                                            0x6A4EB0
#define __MemChecker3_x                                            0x6A4E00
#define __MemChecker4_x                                            0x8420C0
#define __EncryptPad0_x                                            0xC05340
#define __EncryptPad1_x                                            0xC635D0
#define __EncryptPad2_x                                            0xC15EC8
#define __EncryptPad3_x                                            0xC15AC8
#define __EncryptPad4_x                                            0xC53E40
#define __EncryptPad5_x                                            0x1034AE0
#define __AC1_x                                                    0x7FE9D6
#define __AC2_x                                                    0x5D0A9F
#define __AC3_x                                                    0x5D792F
#define __AC4_x                                                    0x5DB750
#define __AC5_x                                                    0x5E19B0
#define __AC6_x                                                    0x5E5F86
#define __AC7_x                                                    0x5D0510
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
#define __do_loot_x                                                0x59E1E0
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
#define __gfMaxZoomCameraDistance_x                                0xAC6640
#define __gfMaxCameraDistance_x                                    0xAF3AA0
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
#define __CastRay_x                                                0x599700
#define __CastRay2_x                                               0x599750
#define __ConvertItemTags_x                                        0x5B4380
#define __CrashHandler_x                                           0x84BA80
#define __EQGetTime_x                                              0x8EA870
#define __ExecuteCmd_x                                             0x592030
#define __FixHeading_x                                             0x97B390
#define __get_bearing_x                                            0x599250
#define __get_melee_range_x                                        0x599940
#define __GetAnimationCache_x                                      0x708A10
#define __GetGaugeValueFromEQ_x                                    0x7FD1E0
#define __GetLabelFromEQ_x                                         0x7FE960
#define __GetXTargetType_x                                         0x97CE60
#define __HeadingDiff_x                                            0x97B400
#define __HelpPath_x                                               0xF27594
#define __LoadFrontEnd_x                                           0x6A0D10
#define __NewUIINI_x                                               0x7FCEB0
#define __pCrashHandler_x                                          0x105D418
#define __ProcessGameEvents_x                                      0x5F7290
#define __ProcessMouseEvent_x                                      0x5F6A50
#define __SaveColors_x                                             0x542E60
#define __STMLToText_x                                             0x91E570
#define __ToggleKeyRingItem_x                                      0x505E00
#define CrashDetected_x                                            0x6A2800
#define DrawNetStatus_x                                            0x6231F0
#define Expansion_HoT_x                                            0xE89504
#define Teleport_Table_Size_x                                      0xE7A800
#define Teleport_Table_x                                           0xE78640
#define Util__FastTime_x                                           0x8EA430
#define wwsCrashReportCheckForUploader_x                           0x84C550
#define wwsCrashReportPlatformLaunchUploader_x                     0x84EC20
#define __HandleMouseWheel_x                                       0x6A4F60

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B4F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494380
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x494140

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54A890
#define AltAdvManager__IsAbilityReady_x                            0x5497E0
#define AltAdvManager__GetAAById_x                                 0x5499E0
#define AltAdvManager__CanTrainAbility_x                           0x549A50
#define AltAdvManager__CanSeeAbility_x                             0x549DB0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C7460
#define CharacterZoneClient__HasSkill_x                            0x4D2130
#define CharacterZoneClient__MakeMeVisible_x                       0x4D3850
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB8A0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B8020
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6200
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D62E0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D63C0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C0380
#define CharacterZoneClient__BardCastBard_x                        0x4C2FE0
#define CharacterZoneClient__GetMaxEffects_x                       0x4B80F0
#define CharacterZoneClient__GetEffect_x                           0x4B7F60
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C1380
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1450
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C14A0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C15F0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C17C0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CACA0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D8490

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x605A60
#define CButtonWnd__CButtonWnd_x                                   0x91A960

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F7270
#define CChatManager__InitContextMenu_x                            0x6F1310
#define CChatManager__FreeChatWindow_x                             0x6F6180
#define CChatManager__GetLockedActiveChatWindow_x                  0x6FAB80
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F7010

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x92F250
#define CContextMenu__dCContextMenu_x                              0x92F480
#define CContextMenu__AddMenuItem_x                                0x92F490
#define CContextMenu__RemoveMenuItem_x                             0x92F7A0
#define CContextMenu__RemoveAllMenuItems_x                         0x92F7C0
#define CContextMenu__CheckMenuItem_x                              0x92F840
#define CContextMenu__SetMenuItem_x                                0x92F6C0
#define CContextMenu__AddSeparator_x                               0x92F620

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x92FDE0
#define CContextMenuManager__RemoveMenu_x                          0x92FE50
#define CContextMenuManager__PopupMenu_x                           0x92FF10
#define CContextMenuManager__Flush_x                               0x92FD80
#define CContextMenuManager__GetMenu_x                             0x4965A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CAF00
#define CChatService__GetFriendName_x                              0x8CAF10

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F77E0
#define CChatWindow__Clear_x                                       0x6F8840
#define CChatWindow__WndNotification_x                             0x6F8DB0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x92C6E0
#define CComboWnd__Draw_x                                          0x92BBC0
#define CComboWnd__GetCurChoice_x                                  0x92C520
#define CComboWnd__GetListRect_x                                   0x92C080
#define CComboWnd__GetTextRect_x                                   0x92C750
#define CComboWnd__InsertChoice_x                                  0x92C210
#define CComboWnd__SetColors_x                                     0x92C1E0
#define CComboWnd__SetChoice_x                                     0x92C4F0
#define CComboWnd__GetItemCount_x                                  0x92C530
#define CComboWnd__GetCurChoiceText_x                              0x92C570

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x700BE0
#define CContainerWnd__vftable_x                                   0xADA3D0
#define CContainerWnd__SetContainer_x                              0x702150

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x542C20
#define CDisplay__GetClickedActor_x                                0x535BD0
#define CDisplay__GetUserDefinedColor_x                            0x52E2B0
#define CDisplay__GetWorldFilePath_x                               0x537620
#define CDisplay__is3dON_x                                         0x5328A0
#define CDisplay__ReloadUI_x                                       0x53CD40
#define CDisplay__WriteTextHD2_x                                   0x532680
#define CDisplay__TrueDistance_x                                   0x539280
#define CDisplay__SetViewActor_x                                   0x535520
#define CDisplay__GetFloorHeight_x                                 0x532960
#define CDisplay__SetRenderWindow_x                                0x531290
#define CDisplay__ToggleScreenshotMode_x                           0x534FF0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94EA60

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x933960
#define CEditWnd__GetCharIndexPt_x                                 0x934860
#define CEditWnd__GetDisplayString_x                               0x934700
#define CEditWnd__GetHorzOffset_x                                  0x932F90
#define CEditWnd__GetLineForPrintableChar_x                        0x9359A0
#define CEditWnd__GetSelStartPt_x                                  0x934B10
#define CEditWnd__GetSTMLSafeText_x                                0x934520
#define CEditWnd__PointFromPrintableChar_x                         0x9355D0
#define CEditWnd__SelectableCharFromPoint_x                        0x935740
#define CEditWnd__SetEditable_x                                    0x934BE0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E54B0
#define CEverQuest__ClickedPlayer_x                                0x5D7710
#define CEverQuest__CreateTargetIndicator_x                        0x5F4540
#define CEverQuest__DeleteTargetIndicator_x                        0x5F45D0
#define CEverQuest__DoTellWindow_x                                 0x4E32C0
#define CEverQuest__OutputTextToLog_x                              0x4E34F0
#define CEverQuest__DropHeldItemOnGround_x                         0x5CCFD0
#define CEverQuest__dsp_chat_x                                     0x4E3880
#define CEverQuest__trimName_x                                     0x5F08C0
#define CEverQuest__Emote_x                                        0x5E5CC0
#define CEverQuest__EnterZone_x                                    0x5DFD60
#define CEverQuest__GetBodyTypeDesc_x                              0x5EA160
#define CEverQuest__GetClassDesc_x                                 0x5EA7A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EADA0
#define CEverQuest__GetDeityDesc_x                                 0x5F2E90
#define CEverQuest__GetLangDesc_x                                  0x5EAF60
#define CEverQuest__GetRaceDesc_x                                  0x5EA780
#define CEverQuest__InterpretCmd_x                                 0x5F3460
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D11C0
#define CEverQuest__LMouseUp_x                                     0x5CF540
#define CEverQuest__RightClickedOnPlayer_x                         0x5D1AA0
#define CEverQuest__RMouseUp_x                                     0x5D04D0
#define CEverQuest__SetGameState_x                                 0x5CCD60
#define CEverQuest__UPCNotificationFlush_x                         0x5F07C0
#define CEverQuest__IssuePetCommand_x                              0x5EC360
#define CEverQuest__ReportSuccessfulHit_x                          0x5E70C0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x712C10
#define CGaugeWnd__CalcLinesFillRect_x                             0x712C70
#define CGaugeWnd__Draw_x                                          0x712300

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACBD0
#define CGuild__GetGuildName_x                                     0x4ABCB0
#define CGuild__GetGuildIndex_x                                    0x4AC040

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72E040

//CHotButton
#define CHotButton__SetButtonSize_x                                0x605E20

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x73AFF0
#define CInvSlotMgr__MoveItem_x                                    0x739D50
#define CInvSlotMgr__SelectSlot_x                                  0x73B0C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x738600
#define CInvSlot__SliderComplete_x                                 0x736360
#define CInvSlot__GetItemBase_x                                    0x735CE0
#define CInvSlot__UpdateItem_x                                     0x735E50

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x73CA10
#define CInvSlotWnd__CInvSlotWnd_x                                 0x73BCE0
#define CInvSlotWnd__HandleLButtonUp_x                             0x73C590

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F9380
#define CItemDisplayWnd__UpdateStrings_x                           0x74AD20
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x744C90
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7451B0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x74B340
#define CItemDisplayWnd__AboutToShow_x                             0x74A960
#define CItemDisplayWnd__WndNotification_x                         0x74C880

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x830D60

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7509E0

// CLabel 
#define CLabel__Draw_x                                             0x756450

// CListWnd
#define CListWnd__CListWnd_x                                       0x904C20
#define CListWnd__dCListWnd_x                                      0x904F40
#define CListWnd__AddColumn_x                                      0x909290
#define CListWnd__AddColumn1_x                                     0x9092E0
#define CListWnd__AddLine_x                                        0x909670
#define CListWnd__AddString_x                                      0x909470
#define CListWnd__CalculateFirstVisibleLine_x                      0x909050
#define CListWnd__CalculateVSBRange_x                              0x908E20
#define CListWnd__ClearSel_x                                       0x909E50
#define CListWnd__ClearAllSel_x                                    0x909EB0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90A8E0
#define CListWnd__Compare_x                                        0x908760
#define CListWnd__Draw_x                                           0x905040
#define CListWnd__DrawColumnSeparators_x                           0x907830
#define CListWnd__DrawHeader_x                                     0x907CA0
#define CListWnd__DrawItem_x                                       0x9080A0
#define CListWnd__DrawLine_x                                       0x9079A0
#define CListWnd__DrawSeparator_x                                  0x9078D0
#define CListWnd__EnableLine_x                                     0x907100
#define CListWnd__EnsureVisible_x                                  0x90A800
#define CListWnd__ExtendSel_x                                      0x909D80
#define CListWnd__GetColumnMinWidth_x                              0x906C40
#define CListWnd__GetColumnWidth_x                                 0x906BB0
#define CListWnd__GetCurSel_x                                      0x906540
#define CListWnd__GetItemAtPoint_x                                 0x907380
#define CListWnd__GetItemAtPoint1_x                                0x9073F0
#define CListWnd__GetItemData_x                                    0x9065C0
#define CListWnd__GetItemHeight_x                                  0x906980
#define CListWnd__GetItemIcon_x                                    0x906750
#define CListWnd__GetItemRect_x                                    0x9071F0
#define CListWnd__GetItemText_x                                    0x906600
#define CListWnd__GetSelList_x                                     0x909F00
#define CListWnd__GetSeparatorRect_x                               0x907630
#define CListWnd__InsertLine_x                                     0x909A60
#define CListWnd__RemoveLine_x                                     0x909BB0
#define CListWnd__SetColors_x                                      0x908DF0
#define CListWnd__SetColumnJustification_x                         0x908B20
#define CListWnd__SetColumnWidth_x                                 0x908A40
#define CListWnd__SetCurSel_x                                      0x909CC0
#define CListWnd__SetItemColor_x                                   0x90A4B0
#define CListWnd__SetItemData_x                                    0x90A470
#define CListWnd__SetItemText_x                                    0x90A080
#define CListWnd__ShiftColumnSeparator_x                           0x908BE0
#define CListWnd__Sort_x                                           0x9088E0
#define CListWnd__ToggleSel_x                                      0x909CF0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x76B8F0
#define CMapViewWnd__GetWorldCoordinates_x                         0x76A000
#define CMapViewWnd__HandleLButtonDown_x                           0x767060

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78ED90
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x78F670
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x78FBB0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7929F0
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x78D760
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x7985F0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78E9C0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x898DD0
#define CPacketScrambler__hton_x                                   0x898DC0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x923BA0
#define CSidlManager__FindScreenPieceTemplate_x                    0x923FB0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x923DA0
#define CSidlManager__CreateLabel_x                                0x7F07B0
#define CSidlManager__CreateXWndFromTemplate_x                     0x927080
#define CSidlManager__CreateXWndFromTemplate1_x                    0x927260
#define CSidlManager__CreateXWnd_x                                 0x7F06E0
#define CSidlManager__CreateHotButtonWnd_x                         0x7F0CB0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9206F0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9205E0
#define CSidlScreenWnd__ConvertToRes_x                             0x945900
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x920070
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x91FD60
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x91FE30
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x91FF00
#define CSidlScreenWnd__DrawSidlPiece_x                            0x920B90
#define CSidlScreenWnd__EnableIniStorage_x                         0x921060
#define CSidlScreenWnd__GetSidlPiece_x                             0x920D80
#define CSidlScreenWnd__Init1_x                                    0x91F950
#define CSidlScreenWnd__LoadIniInfo_x                              0x9210B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x921C10
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91ED50
#define CSidlScreenWnd__StoreIniInfo_x                             0x921780
#define CSidlScreenWnd__StoreIniVis_x                              0x921AF0
#define CSidlScreenWnd__WndNotification_x                          0x920AA0
#define CSidlScreenWnd__GetChildItem_x                             0x920FE0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x910700
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B8388

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x66A250
#define CSkillMgr__GetSkillCap_x                                   0x66A430
#define CSkillMgr__GetNameToken_x                                  0x6699E0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x930BE0
#define CSliderWnd__SetValue_x                                     0x930A50
#define CSliderWnd__SetNumTicks_x                                  0x930AB0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F65F0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x937920
#define CStmlWnd__CalculateHSBRange_x                              0x9389B0
#define CStmlWnd__CalculateVSBRange_x                              0x938920
#define CStmlWnd__CanBreakAtCharacter_x                            0x93CD20
#define CStmlWnd__FastForwardToEndOfTag_x                          0x93D9B0
#define CStmlWnd__ForceParseNow_x                                  0x937EC0
#define CStmlWnd__GetNextTagPiece_x                                0x93CC80
#define CStmlWnd__GetSTMLText_x                                    0x4F5800
#define CStmlWnd__GetVisibleText_x                                 0x937EE0
#define CStmlWnd__InitializeWindowVariables_x                      0x93D800
#define CStmlWnd__MakeStmlColorTag_x                               0x937000
#define CStmlWnd__MakeWndNotificationTag_x                         0x937070
#define CStmlWnd__SetSTMLText_x                                    0x9360B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x93EB10
#define CStmlWnd__UpdateHistoryString_x                            0x93DBC0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x942830
#define CTabWnd__DrawCurrentPage_x                                 0x942E50
#define CTabWnd__DrawTab_x                                         0x942C20
#define CTabWnd__GetCurrentPage_x                                  0x942090
#define CTabWnd__GetPageInnerRect_x                                0x9422D0
#define CTabWnd__GetTabInnerRect_x                                 0x942210
#define CTabWnd__GetTabRect_x                                      0x9420C0
#define CTabWnd__InsertPage_x                                      0x9424C0
#define CTabWnd__SetPage_x                                         0x942350
#define CTabWnd__SetPageRect_x                                     0x942770
#define CTabWnd__UpdatePage_x                                      0x942AE0
#define CTabWnd__GetPageFromTabIndex_x                             0x942B60
#define CTabWnd__GetCurrentTabIndex_x                              0x942080

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x750E40
#define CPageWnd__SetTabText_x                                     0x94EE70

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A66D0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x90D530
#define CTextureFont__GetTextExtent_x                              0x90D6F0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69DB40
#define CHtmlComponentWnd__ValidateUri_x                           0x72FA30
#define CHtmlWnd__SetClientCallbacks_x                             0x60AE20
#define CHtmlWnd__AddObserver_x                                    0x60AE40
#define CHtmlWnd__RemoveObserver_x                                 0x60AEA0
#define Window__getProgress_x                                      0x8496E0
#define Window__getStatus_x                                        0x849700
#define Window__getURI_x                                           0x849710

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94B3F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8FA490

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADE70
#define CXStr__CXStr1_x                                            0x4F0960
#define CXStr__CXStr3_x                                            0x8E6960
#define CXStr__dCXStr_x                                            0x472F80
#define CXStr__operator_equal_x                                    0x8E6B90
#define CXStr__operator_equal1_x                                   0x8E6BD0
#define CXStr__operator_plus_equal1_x                              0x8E7660

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92EE70
#define CXWnd__BringToTop_x                                        0x913EB0
#define CXWnd__Center_x                                            0x913A30
#define CXWnd__ClrFocus_x                                          0x913860
#define CXWnd__Destroy_x                                           0x913910
#define CXWnd__DoAllDrawing_x                                      0x90FE80
#define CXWnd__DrawChildren_x                                      0x90FE50
#define CXWnd__DrawColoredRect_x                                   0x9102F0
#define CXWnd__DrawTooltip_x                                       0x90E9A0
#define CXWnd__DrawTooltipAtPoint_x                                0x90EA60
#define CXWnd__GetBorderFrame_x                                    0x910150
#define CXWnd__GetChildWndAt_x                                     0x913F50
#define CXWnd__GetClientClipRect_x                                 0x912140
#define CXWnd__GetScreenClipRect_x                                 0x9121F0
#define CXWnd__GetScreenRect_x                                     0x9123A0
#define CXWnd__GetTooltipRect_x                                    0x910340
#define CXWnd__GetWindowTextA_x                                    0x497D20
#define CXWnd__IsActive_x                                          0x916E50
#define CXWnd__IsDescendantOf_x                                    0x912DC0
#define CXWnd__IsReallyVisible_x                                   0x912DF0
#define CXWnd__IsType_x                                            0x9145D0
#define CXWnd__Move_x                                              0x912E60
#define CXWnd__Move1_x                                             0x912F10
#define CXWnd__ProcessTransition_x                                 0x9139E0
#define CXWnd__Refade_x                                            0x9131F0
#define CXWnd__Resize_x                                            0x913480
#define CXWnd__Right_x                                             0x913C70
#define CXWnd__SetFocus_x                                          0x913820
#define CXWnd__SetFont_x                                           0x913890
#define CXWnd__SetKeyTooltip_x                                     0x9143E0
#define CXWnd__SetMouseOver_x                                      0x9112B0
#define CXWnd__StartFade_x                                         0x912C90
#define CXWnd__GetChildItem_x                                      0x9140C0
#define CXWnd__SetParent_x                                         0x912B60

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9469D0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x916E90
#define CXWndManager__DrawWindows_x                                0x916EB0
#define CXWndManager__GetKeyboardFlags_x                           0x919620
#define CXWndManager__HandleKeyboardMsg_x                          0x919220
#define CXWndManager__RemoveWnd_x                                  0x919870
#define CXWndManager__RemovePendingDeletionWnd_x                   0x919DD0

// CDBStr
#define CDBStr__GetString_x                                        0x52D270

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B8FD0
#define EQ_Character__Cur_HP_x                                     0x4CF1B0
#define EQ_Character__Cur_Mana_x                                   0x4D68C0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BBEE0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFA70
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFBC0
#define EQ_Character__GetHPRegen_x                                 0x4DC840
#define EQ_Character__GetEnduranceRegen_x                          0x4DCE50
#define EQ_Character__GetManaRegen_x                               0x4DD290
#define EQ_Character__Max_Endurance_x                              0x630E90
#define EQ_Character__Max_HP_x                                     0x4CEFE0
#define EQ_Character__Max_Mana_x                                   0x630C90
#define EQ_Character__doCombatAbility_x                            0x633360
#define EQ_Character__UseSkill_x                                   0x4DF0A0
#define EQ_Character__GetConLevel_x                                0x62A070
#define EQ_Character__IsExpansionFlag_x                            0x5907F0
#define EQ_Character__TotalEffect_x                                0x4C2560
#define EQ_Character__GetPCSpellAffect_x                           0x4BCAD0
#define EQ_Character__SpellDuration_x                              0x4BC600
#define EQ_Character__FindItemByRecord_x                           0x4D47C0
#define EQ_Character__GetAdjustedSkill_x                           0x4D1EF0
#define EQ_Character__GetBaseSkill_x                               0x4D2E90
#define EQ_Character__CanUseItem_x                                 0x4D6BD0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B7EB0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x647200

//PcClient
#define PcClient__PcClient_x                                       0x6277A0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6C60
#define CCharacterListWnd__EnterWorld_x                            0x4B66A0
#define CCharacterListWnd__Quit_x                                  0x4B63B0
#define CCharacterListWnd__UpdateList_x                            0x4B6830

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x60C070
#define EQ_Item__CreateItemTagString_x                             0x892790
#define EQ_Item__IsStackable_x                                     0x897190
#define EQ_Item__GetImageNum_x                                     0x8941C0
#define EQ_Item__CreateItemClient_x                                0x60B220
#define EQ_Item__GetItemValue_x                                    0x895430
#define EQ_Item__ValueSellMerchant_x                               0x898970
#define EQ_Item__IsKeyRingItem_x                                   0x896AE0
#define EQ_Item__CanGoInBag_x                                      0x60C190
#define EQ_Item__GetMaxItemCount_x                                 0x895800
#define EQ_Item__GetHeldItem_x                                     0x894090
#define EQ_Item__GetAugmentFitBySlot_x                             0x8920D0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54B570
#define EQ_LoadingS__Array_x                                       0xBED130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x6317F0
#define EQ_PC__GetAlternateAbilityId_x                             0x8A1B90
#define EQ_PC__GetCombatAbility_x                                  0x8A2200
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A2270
#define EQ_PC__GetItemRecastTimer_x                                0x6338E0
#define EQ_PC__HasLoreItem_x                                       0x62A840
#define EQ_PC__AlertInventoryChanged_x                             0x6299A0
#define EQ_PC__GetPcZoneClient_x                                   0x655C90
#define EQ_PC__RemoveMyAffect_x                                    0x636AD0
#define EQ_PC__GetKeyRingItems_x                                   0x8A2B10
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A2890
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A2E00

// EQItemList 
#define EQItemList__EQItemList_x                                   0x596C70
#define EQItemList__add_object_x                                   0x5C26A0
#define EQItemList__add_item_x                                     0x597280
#define EQItemList__delete_item_x                                  0x5972D0
#define EQItemList__FreeItemList_x                                 0x5971D0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52A8D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x648A80
#define EQPlayer__dEQPlayer_x                                      0x63C160
#define EQPlayer__DoAttack_x                                       0x650950
#define EQPlayer__EQPlayer_x                                       0x63C810
#define EQPlayer__SetNameSpriteState_x                             0x640AB0
#define EQPlayer__SetNameSpriteTint_x                              0x641980
#define PlayerBase__HasProperty_j_x                                0x979770
#define EQPlayer__IsTargetable_x                                   0x979C10
#define EQPlayer__CanSee_x                                         0x979A70
#define EQPlayer__CanSee1_x                                        0x979B40
#define PlayerBase__GetVisibilityLineSegment_x                     0x979830

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x653720
#define PlayerZoneClient__GetLevel_x                               0x655CD0
#define PlayerZoneClient__IsValidTeleport_x                        0x5C37F0
#define PlayerZoneClient__LegalPlayerRace_x                        0x544A00

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x64BA00
#define EQPlayerManager__GetSpawnByName_x                          0x64BA20
#define EQPlayerManager__GetPlayerFromPartialName_x                0x64BAB0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x60F960
#define KeypressHandler__AttachKeyToEqCommand_x                    0x60F9A0
#define KeypressHandler__ClearCommandStateArray_x                  0x610D90
#define KeypressHandler__HandleKeyDown_x                           0x610DB0
#define KeypressHandler__HandleKeyUp_x                             0x610E50
#define KeypressHandler__SaveKeymapping_x                          0x611230

// MapViewMap 
#define MapViewMap__Clear_x                                        0x767780
#define MapViewMap__SaveEx_x                                       0x76AB20
#define MapViewMap__SetZoom_x                                      0x76F1F0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B5DA0

// StringTable 
#define StringTable__getString_x                                   0x8B0E30

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x636740
#define PcZoneClient__RemovePetEffect_x                            0x636D70
#define PcZoneClient__HasAlternateAbility_x                        0x630AD0
#define PcZoneClient__GetCurrentMod_x                              0x4E21A0
#define PcZoneClient__GetModCap_x                                  0x4E20A0
#define PcZoneClient__CanEquipItem_x                               0x631180
#define PcZoneClient__GetItemByID_x                                0x633D50
#define PcZoneClient__GetItemByItemClass_x                         0x633EA0
#define PcZoneClient__RemoveBuffEffect_x                           0x636D90
#define PcZoneClient__BandolierSwap_x                              0x631DB0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C8490

//IconCache
#define IconCache__GetIcon_x                                       0x7082A0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6FFCD0
#define CContainerMgr__CloseContainer_x                            0x6FFFA0
#define CContainerMgr__OpenExperimentContainer_x                   0x700A20

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C2CC0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x604240

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75DBE0
#define CLootWnd__RequestLootSlot_x                                0x75CF90

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x563D20
#define EQ_Spell__SpellAffects_x                                   0x564190
#define EQ_Spell__SpellAffectBase_x                                0x563F50
#define EQ_Spell__IsStackable_x                                    0x4C6D70
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6C20
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B3FC0
#define EQ_Spell__IsSPAStacking_x                                  0x564FC0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5644E0
#define EQ_Spell__IsNoRemove_x                                     0x4C6D50
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x564FD0
#define __IsResEffectSpell_x                                       0x4C60A0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AA8E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C0380

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x808770
#define CTargetWnd__WndNotification_x                              0x808000
#define CTargetWnd__RefreshTargetBuffs_x                           0x8082D0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x807150

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x80CE40

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x528290

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55F2C0
#define EqSoundManager__PlayScriptMp3_x                            0x55F420
#define EqSoundManager__SoundAssistPlay_x                          0x66E0A0
#define EqSoundManager__WaveInstancePlay_x                         0x66D610

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51C260

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9325C0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x553380
#define CAltAbilityData__GetMercMaxRank_x                          0x553320
#define CAltAbilityData__GetMaxRank_x                              0x548690

//CTargetRing
#define CTargetRing__Cast_x                                        0x602340

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6C00
#define CharacterBase__CreateItemGlobalIndex_x                     0x502350
#define CharacterBase__CreateItemIndex_x                           0x60A430
#define CharacterBase__GetItemPossession_x                         0x4B3E70
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C8A20
#define CharacterBase__GetEffectId_x                               0x4C6BB0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E7CD0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E84F0

//messages
#define msg_spell_worn_off_x                                       0x588900
#define msg_new_text_x                                             0x57D710
#define __msgTokenTextParam_x                                      0x58AF70
#define msgTokenText_x                                             0x58B1C0

//SpellManager
#define SpellManager__vftable_x                                    0xAB4A80
#define SpellManager__SpellManager_x                               0x6713C0
#define Spellmanager__LoadTextSpells_x                             0x671C90
#define SpellManager__GetSpellByGroupAndRank_x                     0x671590

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x97D750

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x502A00
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58EDA0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x623050
#define ItemGlobalIndex__IsValidIndex_x                            0x502A60

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C0CC0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C0F40

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7567A0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x7044F0
#define CCursorAttachment__Deactivate_x                            0x7054D0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x944DE0
#define CEQSuiteTextureLoader__GetTexture_x                        0x944AA0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FF970

//IString
#define IString__Append_x                                          0x4EFAA0

//Camera
#define CDisplay__cameraType_x                                     0xDC6B34
#define EverQuest__Cameras_x                                       0xE89840

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x508080
#define LootFiltersManager__GetItemFilterData_x                    0x507970
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5079A0
#define LootFiltersManager__SetItemLootFilter_x                    0x507BC0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B0CA0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9834D0
#define CResolutionHandler__GetWindowedStyle_x                     0x668E50

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6FC9E0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D34D0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x71CDC0
#define CGroupWnd__UpdateDisplay_x                                 0x71C120

//ItemBase
#define ItemBase__IsLore_x                                         0x896B40
#define ItemBase__IsLoreEquipped_x                                 0x896BB0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F5E70

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5C2590
#define EQPlacedItemManager__GetItemByGuid_x                       0x5C2740
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5C27A0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x65E750
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6623E0

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
