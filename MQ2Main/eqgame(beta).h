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
#define __ExpectedVersionDate                                     "Nov 30 2018"
#define __ExpectedVersionTime                                     "09:19:17"
#define __ActualVersionDate_x                                      0xAD117C
#define __ActualVersionTime_x                                      0xAD1170

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x6155A0
#define __MemChecker1_x                                            0x8EA6B0
#define __MemChecker2_x                                            0x6A4A80
#define __MemChecker3_x                                            0x6A49D0
#define __MemChecker4_x                                            0x8418B0
#define __EncryptPad0_x                                            0xC05340
#define __EncryptPad1_x                                            0xC635D0
#define __EncryptPad2_x                                            0xC15EC8
#define __EncryptPad3_x                                            0xC15AC8
#define __EncryptPad4_x                                            0xC53E40
#define __EncryptPad5_x                                            0x1034AE0
#define __AC1_x                                                    0x7FE326
#define __AC2_x                                                    0x5D031F
#define __AC3_x                                                    0x5D71AF
#define __AC4_x                                                    0x5DAFD0
#define __AC5_x                                                    0x5E118F
#define __AC6_x                                                    0x5E5756
#define __AC7_x                                                    0x5CFD90
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
#define __do_loot_x                                                0x59DB20
#define __DrawHandler_x                                            0x16B9440
#define __GroupCount_x                                             0xE78452
#define __Guilds_x                                                 0xE7E9B0
#define __gWorld_x                                                 0xE7AD2C
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
#define pinstCDisplay_x                                            0xE7ACCC
#define pinstCEverQuest_x                                          0x1034C20
#define pinstEverQuestInfo_x                                       0xE88138
#define pinstCharData_x                                            0xE7AD34
#define pinstCharSpawn_x                                           0xE7A89C
#define pinstControlledMissile_x                                   0xE7AD30
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
#define pinstPCData_x                                              0xE7AD34
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
#define pinstCAlertWnd_x                                           0xDC6AFC
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
#define pinstCEventCalendarWnd_x                                   0xDC6560
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
#define pinstCPlayerNotesWnd_x                                     0xDC6AA0
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
#define pinstCSkillsWnd_x                                          0xDC655C
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
#define pinstCTradeWnd_x                                           0xDC6A9C
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
#define __CastRay_x                                                0x599040
#define __CastRay2_x                                               0x599090
#define __ConvertItemTags_x                                        0x5B3CC0
#define __CrashHandler_x                                           0x84B200
#define __EQGetTime_x                                              0x8EA1A0
#define __ExecuteCmd_x                                             0x591980
#define __FixHeading_x                                             0x97ADD0
#define __get_bearing_x                                            0x598B90
#define __get_melee_range_x                                        0x599280
#define __GetAnimationCache_x                                      0x708480
#define __GetGaugeValueFromEQ_x                                    0x7FCB30
#define __GetLabelFromEQ_x                                         0x7FE2B0
#define __GetXTargetType_x                                         0x97C8A0
#define __HeadingDiff_x                                            0x97AE40
#define __HelpPath_x                                               0xF27594
#define __LoadFrontEnd_x                                           0x6A08E0
#define __NewUIINI_x                                               0x7FC800
#define __pCrashHandler_x                                          0x105D418
#define __ProcessGameEvents_x                                      0x5F6A60
#define __ProcessMouseEvent_x                                      0x5F6220
#define __SaveColors_x                                             0x542AF0
#define __STMLToText_x                                             0x91DEC0
#define __ToggleKeyRingItem_x                                      0x505D40
#define CrashDetected_x                                            0x6A23D0
#define DrawNetStatus_x                                            0x622A10
#define Expansion_HoT_x                                            0xE89504
#define Teleport_Table_Size_x                                      0xE7A800
#define Teleport_Table_x                                           0xE78640
#define Util__FastTime_x                                           0x8E9D60
#define wwsCrashReportCheckForUploader_x                           0x84BFF0
#define wwsCrashReportPlatformLaunchUploader_x                     0x84E6D0
#define __HandleMouseWheel_x                                       0x6A4B30

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x48B590
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x494410
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4941D0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x54A550
#define AltAdvManager__IsAbilityReady_x                            0x5494A0
#define AltAdvManager__GetAAById_x                                 0x5496A0
#define AltAdvManager__CanTrainAbility_x                           0x549710
#define AltAdvManager__CanSeeAbility_x                             0x549A70

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C75D0
#define CharacterZoneClient__HasSkill_x                            0x4D22A0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D39C0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BB9C0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4B8130
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D6380
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D6460
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D6540
#define CharacterZoneClient__FindAffectSlot_x                      0x4C04A0
#define CharacterZoneClient__BardCastBard_x                        0x4C3100
#define CharacterZoneClient__GetMaxEffects_x                       0x4B8200
#define CharacterZoneClient__GetEffect_x                           0x4B8070
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C14A0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C1570
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C15C0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C1710
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C18E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6CA7F0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6D8030

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x605390
#define CButtonWnd__CButtonWnd_x                                   0x91A2B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6F6E50
#define CChatManager__InitContextMenu_x                            0x6F0EF0
#define CChatManager__FreeChatWindow_x                             0x6F5D60
#define CChatManager__GetLockedActiveChatWindow_x                  0x6FA760
#define CChatManager__SetLockedActiveChatWindow_x                  0x6F6BF0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x92EA20
#define CContextMenu__dCContextMenu_x                              0x92EC50
#define CContextMenu__AddMenuItem_x                                0x92EC60
#define CContextMenu__RemoveMenuItem_x                             0x92EF60
#define CContextMenu__RemoveAllMenuItems_x                         0x92EF80
#define CContextMenu__CheckMenuItem_x                              0x92F000
#define CContextMenu__SetMenuItem_x                                0x92EE90
#define CContextMenu__AddSeparator_x                               0x92EDF0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x92F5A0
#define CContextMenuManager__RemoveMenu_x                          0x92F610
#define CContextMenuManager__PopupMenu_x                           0x92F6D0
#define CContextMenuManager__Flush_x                               0x92F540
#define CContextMenuManager__GetMenu_x                             0x496610

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8CAA70
#define CChatService__GetFriendName_x                              0x8CAA80

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6F73C0
#define CChatWindow__Clear_x                                       0x6F8420
#define CChatWindow__WndNotification_x                             0x6F8990

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x92BEB0
#define CComboWnd__Draw_x                                          0x92B3B0
#define CComboWnd__GetCurChoice_x                                  0x92BCF0
#define CComboWnd__GetListRect_x                                   0x92B860
#define CComboWnd__GetTextRect_x                                   0x92BF10
#define CComboWnd__InsertChoice_x                                  0x92B9F0
#define CComboWnd__SetColors_x                                     0x92B9C0
#define CComboWnd__SetChoice_x                                     0x92BCC0
#define CComboWnd__GetItemCount_x                                  0x92BD00
#define CComboWnd__GetCurChoiceText_x                              0x92BD40

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x700660
#define CContainerWnd__vftable_x                                   0xADA428
#define CContainerWnd__SetContainer_x                              0x701BD0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x5428B0
#define CDisplay__GetClickedActor_x                                0x535860
#define CDisplay__GetUserDefinedColor_x                            0x52DF40
#define CDisplay__GetWorldFilePath_x                               0x5372B0
#define CDisplay__is3dON_x                                         0x532530
#define CDisplay__ReloadUI_x                                       0x53C9D0
#define CDisplay__WriteTextHD2_x                                   0x532310
#define CDisplay__TrueDistance_x                                   0x538F10
#define CDisplay__SetViewActor_x                                   0x5351B0
#define CDisplay__GetFloorHeight_x                                 0x5325F0
#define CDisplay__SetRenderWindow_x                                0x530F20
#define CDisplay__ToggleScreenshotMode_x                           0x534C80

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x94E570

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x933100
#define CEditWnd__GetCharIndexPt_x                                 0x933FF0
#define CEditWnd__GetDisplayString_x                               0x933E90
#define CEditWnd__GetHorzOffset_x                                  0x932730
#define CEditWnd__GetLineForPrintableChar_x                        0x935130
#define CEditWnd__GetSelStartPt_x                                  0x9342A0
#define CEditWnd__GetSTMLSafeText_x                                0x933CB0
#define CEditWnd__PointFromPrintableChar_x                         0x934D60
#define CEditWnd__SelectableCharFromPoint_x                        0x934ED0
#define CEditWnd__SetEditable_x                                    0x934370

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5E4C80
#define CEverQuest__ClickedPlayer_x                                0x5D6F90
#define CEverQuest__CreateTargetIndicator_x                        0x5F3D10
#define CEverQuest__DeleteTargetIndicator_x                        0x5F3DA0
#define CEverQuest__DoTellWindow_x                                 0x4E3580
#define CEverQuest__OutputTextToLog_x                              0x4E37B0
#define CEverQuest__DropHeldItemOnGround_x                         0x5CC850
#define CEverQuest__dsp_chat_x                                     0x4E3B40
#define CEverQuest__trimName_x                                     0x5F0090
#define CEverQuest__Emote_x                                        0x5E5490
#define CEverQuest__EnterZone_x                                    0x5DF5E0
#define CEverQuest__GetBodyTypeDesc_x                              0x5E9930
#define CEverQuest__GetClassDesc_x                                 0x5E9F70
#define CEverQuest__GetClassThreeLetterCode_x                      0x5EA570
#define CEverQuest__GetDeityDesc_x                                 0x5F2660
#define CEverQuest__GetLangDesc_x                                  0x5EA730
#define CEverQuest__GetRaceDesc_x                                  0x5E9F50
#define CEverQuest__InterpretCmd_x                                 0x5F2C30
#define CEverQuest__LeftClickedOnPlayer_x                          0x5D0A40
#define CEverQuest__LMouseUp_x                                     0x5CEDC0
#define CEverQuest__RightClickedOnPlayer_x                         0x5D1320
#define CEverQuest__RMouseUp_x                                     0x5CFD50
#define CEverQuest__SetGameState_x                                 0x5CC5E0
#define CEverQuest__UPCNotificationFlush_x                         0x5EFF90
#define CEverQuest__IssuePetCommand_x                              0x5EBB30
#define CEverQuest__ReportSuccessfulHit_x                          0x5E6890

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7125B0
#define CGaugeWnd__CalcLinesFillRect_x                             0x712610
#define CGaugeWnd__Draw_x                                          0x711CA0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4ACD50
#define CGuild__GetGuildName_x                                     0x4ABE30
#define CGuild__GetGuildIndex_x                                    0x4AC1C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x72D9D0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x605750

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x73A970
#define CInvSlotMgr__MoveItem_x                                    0x7396D0
#define CInvSlotMgr__SelectSlot_x                                  0x73AA40

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x737F80
#define CInvSlot__SliderComplete_x                                 0x735CE0
#define CInvSlot__GetItemBase_x                                    0x735670
#define CInvSlot__UpdateItem_x                                     0x7357E0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x73C390
#define CInvSlotWnd__CInvSlotWnd_x                                 0x73B660
#define CInvSlotWnd__HandleLButtonUp_x                             0x73BF10

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7F8D20
#define CItemDisplayWnd__UpdateStrings_x                           0x74A670
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x7445E0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x744B00
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x74AC90
#define CItemDisplayWnd__AboutToShow_x                             0x74A2B0
#define CItemDisplayWnd__WndNotification_x                         0x74C1D0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x830860

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x750330

// CLabel 
#define CLabel__Draw_x                                             0x755D90

// CListWnd
#define CListWnd__CListWnd_x                                       0x904620
#define CListWnd__dCListWnd_x                                      0x904940
#define CListWnd__AddColumn_x                                      0x908C40
#define CListWnd__AddColumn1_x                                     0x908C90
#define CListWnd__AddLine_x                                        0x909020
#define CListWnd__AddString_x                                      0x908E20
#define CListWnd__CalculateFirstVisibleLine_x                      0x908A00
#define CListWnd__CalculateVSBRange_x                              0x9087E0
#define CListWnd__ClearSel_x                                       0x909800
#define CListWnd__ClearAllSel_x                                    0x909860
#define CListWnd__CloseAndUpdateEditWindow_x                       0x90A260
#define CListWnd__Compare_x                                        0x908120
#define CListWnd__Draw_x                                           0x904A40
#define CListWnd__DrawColumnSeparators_x                           0x907210
#define CListWnd__DrawHeader_x                                     0x907670
#define CListWnd__DrawItem_x                                       0x907A60
#define CListWnd__DrawLine_x                                       0x907370
#define CListWnd__DrawSeparator_x                                  0x9072B0
#define CListWnd__EnableLine_x                                     0x906AF0
#define CListWnd__EnsureVisible_x                                  0x90A190
#define CListWnd__ExtendSel_x                                      0x909730
#define CListWnd__GetColumnMinWidth_x                              0x906630
#define CListWnd__GetColumnWidth_x                                 0x9065A0
#define CListWnd__GetCurSel_x                                      0x905F30
#define CListWnd__GetItemAtPoint_x                                 0x906D60
#define CListWnd__GetItemAtPoint1_x                                0x906DD0
#define CListWnd__GetItemData_x                                    0x905FB0
#define CListWnd__GetItemHeight_x                                  0x906370
#define CListWnd__GetItemIcon_x                                    0x906140
#define CListWnd__GetItemRect_x                                    0x906BE0
#define CListWnd__GetItemText_x                                    0x905FF0
#define CListWnd__GetSelList_x                                     0x9098B0
#define CListWnd__GetSeparatorRect_x                               0x907010
#define CListWnd__InsertLine_x                                     0x909410
#define CListWnd__RemoveLine_x                                     0x909560
#define CListWnd__SetColors_x                                      0x9087B0
#define CListWnd__SetColumnJustification_x                         0x9084E0
#define CListWnd__SetColumnWidth_x                                 0x908400
#define CListWnd__SetCurSel_x                                      0x909670
#define CListWnd__SetItemColor_x                                   0x909E50
#define CListWnd__SetItemData_x                                    0x909E10
#define CListWnd__SetItemText_x                                    0x909A30
#define CListWnd__ShiftColumnSeparator_x                           0x9085A0
#define CListWnd__Sort_x                                           0x9082A0
#define CListWnd__ToggleSel_x                                      0x9096A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x76B360
#define CMapViewWnd__GetWorldCoordinates_x                         0x769A70
#define CMapViewWnd__HandleLButtonDown_x                           0x766AD0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x78E760
// CMerchantWnd__RequestBuyItem_x                             
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x78F040
// CMerchantWnd__RequestSellItem_x
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x78F580
#define CMerchantWnd__SelectRecoverySlot_x                         0x7923B0
//CMerchantWnd__SelectBuySellSlot_x before
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x78D140
//CMerchantWnd__ActualSelect_x
#define CMerchantWnd__SelectBuySellSlot_x                          0x797FB0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x78E390

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x898860
#define CPacketScrambler__hton_x                                   0x898850

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9234E0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9238F0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9236E0
#define CSidlManager__CreateLabel_x                                0x7F0170
#define CSidlManager__CreateXWndFromTemplate_x                     0x9269C0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x926BA0
#define CSidlManager__CreateXWnd_x                                 0x7F00A0
#define CSidlManager__CreateHotButtonWnd_x                         0x7F0660

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x920040
#define CSidlScreenWnd__CalculateVSBRange_x                        0x91FF30
#define CSidlScreenWnd__ConvertToRes_x                             0x945400
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x91F9C0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x91F6B0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x91F780
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x91F850
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9204E0
#define CSidlScreenWnd__EnableIniStorage_x                         0x9209B0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9206D0
#define CSidlScreenWnd__Init1_x                                    0x91F2A0
#define CSidlScreenWnd__LoadIniInfo_x                              0x920A00
#define CSidlScreenWnd__LoadIniListWnd_x                           0x921550
#define CSidlScreenWnd__LoadSidlScreen_x                           0x91E6A0
#define CSidlScreenWnd__StoreIniInfo_x                             0x9210C0
#define CSidlScreenWnd__StoreIniVis_x                              0x921430
#define CSidlScreenWnd__WndNotification_x                          0x9203F0
#define CSidlScreenWnd__GetChildItem_x                             0x920930
#define CSidlScreenWnd__HandleLButtonUp_x                          0x910050
#define CSidlScreenWnd__m_layoutCopy_x                             0x16B8388

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x669D30
#define CSkillMgr__GetSkillCap_x                                   0x669F10
#define CSkillMgr__GetNameToken_x                                  0x6694C0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x930390
#define CSliderWnd__SetValue_x                                     0x930200
#define CSliderWnd__SetNumTicks_x                                  0x930260

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7F5F80

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9370B0
#define CStmlWnd__CalculateHSBRange_x                              0x938120
#define CStmlWnd__CalculateVSBRange_x                              0x938090
#define CStmlWnd__CanBreakAtCharacter_x                            0x93C490
#define CStmlWnd__FastForwardToEndOfTag_x                          0x93D120
#define CStmlWnd__ForceParseNow_x                                  0x937650
#define CStmlWnd__GetNextTagPiece_x                                0x93C3F0
#define CStmlWnd__GetSTMLText_x                                    0x4F5620
#define CStmlWnd__GetVisibleText_x                                 0x937670
#define CStmlWnd__InitializeWindowVariables_x                      0x93CF70
#define CStmlWnd__MakeStmlColorTag_x                               0x936790
#define CStmlWnd__MakeWndNotificationTag_x                         0x936800
#define CStmlWnd__SetSTMLText_x                                    0x935840
#define CStmlWnd__StripFirstSTMLLines_x                            0x93E280
#define CStmlWnd__UpdateHistoryString_x                            0x93D330

// CTabWnd 
#define CTabWnd__Draw_x                                            0x941F90
#define CTabWnd__DrawCurrentPage_x                                 0x9425B0
#define CTabWnd__DrawTab_x                                         0x942380
#define CTabWnd__GetCurrentPage_x                                  0x9417F0
#define CTabWnd__GetPageInnerRect_x                                0x941A30
#define CTabWnd__GetTabInnerRect_x                                 0x941970
#define CTabWnd__GetTabRect_x                                      0x941820
#define CTabWnd__InsertPage_x                                      0x941C20
#define CTabWnd__SetPage_x                                         0x941AB0
#define CTabWnd__SetPageRect_x                                     0x941ED0
#define CTabWnd__UpdatePage_x                                      0x942240
#define CTabWnd__GetPageFromTabIndex_x                             0x9422C0
#define CTabWnd__GetCurrentTabIndex_x                              0x9417E0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x750790
#define CPageWnd__SetTabText_x                                     0x94E980

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A6920

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x90CEB0
#define CTextureFont__GetTextExtent_x                              0x90D070

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x69D720
#define CHtmlComponentWnd__ValidateUri_x                           0x72F3C0
#define CHtmlWnd__SetClientCallbacks_x                             0x60A710
#define CHtmlWnd__AddObserver_x                                    0x60A730
#define CHtmlWnd__RemoveObserver_x                                 0x60A790
#define Window__getProgress_x                                      0x848E70
#define Window__getStatus_x                                        0x848E90
#define Window__getURI_x                                           0x848EA0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x94AF00

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8F9E30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4ADFF0
#define CXStr__CXStr1_x                                            0x9BC880
#define CXStr__CXStr3_x                                            0x8E62D0
#define CXStr__dCXStr_x                                            0x473050
#define CXStr__operator_equal_x                                    0x8E6500
#define CXStr__operator_equal1_x                                   0x8E6540
#define CXStr__operator_plus_equal1_x                              0x8E6FD0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x92E630
#define CXWnd__BringToTop_x                                        0x913800
#define CXWnd__Center_x                                            0x913380
#define CXWnd__ClrFocus_x                                          0x9131C0
#define CXWnd__Destroy_x                                           0x913260
#define CXWnd__DoAllDrawing_x                                      0x90F7E0
#define CXWnd__DrawChildren_x                                      0x90F7B0
#define CXWnd__DrawColoredRect_x                                   0x90FC40
#define CXWnd__DrawTooltip_x                                       0x90E310
#define CXWnd__DrawTooltipAtPoint_x                                0x90E3D0
#define CXWnd__GetBorderFrame_x                                    0x90FAA0
#define CXWnd__GetChildWndAt_x                                     0x9138A0
#define CXWnd__GetClientClipRect_x                                 0x911A80
#define CXWnd__GetScreenClipRect_x                                 0x911B50
#define CXWnd__GetScreenRect_x                                     0x911CE0
#define CXWnd__GetTooltipRect_x                                    0x90FC90
#define CXWnd__GetWindowTextA_x                                    0x497DC0
#define CXWnd__IsActive_x                                          0x916790
#define CXWnd__IsDescendantOf_x                                    0x9126F0
#define CXWnd__IsReallyVisible_x                                   0x912720
#define CXWnd__IsType_x                                            0x913F00
#define CXWnd__Move_x                                              0x912790
#define CXWnd__Move1_x                                             0x912850
#define CXWnd__ProcessTransition_x                                 0x913330
#define CXWnd__Refade_x                                            0x912B30
#define CXWnd__Resize_x                                            0x912DD0
#define CXWnd__Right_x                                             0x9135C0
#define CXWnd__SetFocus_x                                          0x913180
#define CXWnd__SetFont_x                                           0x9131F0
#define CXWnd__SetKeyTooltip_x                                     0x913D30
#define CXWnd__SetMouseOver_x                                      0x910BF0
#define CXWnd__StartFade_x                                         0x9125C0
#define CXWnd__GetChildItem_x                                      0x913A10
#define CXWnd__SetParent_x                                         0x912490

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9464D0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9167D0
#define CXWndManager__DrawWindows_x                                0x9167F0
#define CXWndManager__GetKeyboardFlags_x                           0x918F70
#define CXWndManager__HandleKeyboardMsg_x                          0x918B70
#define CXWndManager__RemoveWnd_x                                  0x9191C0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x919720

// CDBStr
#define CDBStr__GetString_x                                        0x52CF00

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4B90E0
#define EQ_Character__Cur_HP_x                                     0x4CF320
#define EQ_Character__Cur_Mana_x                                   0x4D6A40
#define EQ_Character__GetAACastingTimeModifier_x                   0x4BC000
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4AFC20
#define EQ_Character__GetFocusRangeModifier_x                      0x4AFD70
#define EQ_Character__GetHPRegen_x                                 0x4DC9C0
#define EQ_Character__GetEnduranceRegen_x                          0x4DCFD0
#define EQ_Character__GetManaRegen_x                               0x4DD410
#define EQ_Character__Max_Endurance_x                              0x6305C0
#define EQ_Character__Max_HP_x                                     0x4CF150
#define EQ_Character__Max_Mana_x                                   0x6303C0
#define EQ_Character__doCombatAbility_x                            0x632A80
#define EQ_Character__UseSkill_x                                   0x4DF200
#define EQ_Character__GetConLevel_x                                0x6298E0
#define EQ_Character__IsExpansionFlag_x                            0x590120
#define EQ_Character__TotalEffect_x                                0x4C2680
#define EQ_Character__GetPCSpellAffect_x                           0x4BCBF0
#define EQ_Character__SpellDuration_x                              0x4BC720
#define EQ_Character__FindItemByRecord_x                           0x4D4930
#define EQ_Character__GetAdjustedSkill_x                           0x4D2060
#define EQ_Character__GetBaseSkill_x                               0x4D3000
#define EQ_Character__CanUseItem_x                                 0x4D6D50

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8B7A30

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x646D20

//PcClient
#define PcClient__PcClient_x                                       0x627020

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B6D70
#define CCharacterListWnd__EnterWorld_x                            0x4B67B0
#define CCharacterListWnd__Quit_x                                  0x4B64C0
#define CCharacterListWnd__UpdateList_x                            0x4B6940

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x60B950
#define EQ_Item__CreateItemTagString_x                             0x892240
#define EQ_Item__IsStackable_x                                     0x896C30
#define EQ_Item__GetImageNum_x                                     0x893C50
#define EQ_Item__CreateItemClient_x                                0x60AB10
#define EQ_Item__GetItemValue_x                                    0x894E90
#define EQ_Item__ValueSellMerchant_x                               0x8983F0
#define EQ_Item__IsKeyRingItem_x                                   0x896580
#define EQ_Item__CanGoInBag_x                                      0x60BA70
#define EQ_Item__GetMaxItemCount_x                                 0x895260
#define EQ_Item__GetHeldItem_x                                     0x893B20
#define EQ_Item__GetAugmentFitBySlot_x                             0x891B80

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x54B270
#define EQ_LoadingS__Array_x                                       0xBED130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x630F20
#define EQ_PC__GetAlternateAbilityId_x                             0x8A16B0
#define EQ_PC__GetCombatAbility_x                                  0x8A1D20
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A1D90
#define EQ_PC__GetItemRecastTimer_x                                0x633000
#define EQ_PC__HasLoreItem_x                                       0x62A0B0
#define EQ_PC__AlertInventoryChanged_x                             0x629220
#define EQ_PC__GetPcZoneClient_x                                   0x655490
#define EQ_PC__RemoveMyAffect_x                                    0x636200
#define EQ_PC__GetKeyRingItems_x                                   0x8A2630
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A23B0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A2920

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5965C0
#define EQItemList__add_object_x                                   0x5C1F70
#define EQItemList__add_item_x                                     0x596BD0
#define EQItemList__delete_item_x                                  0x596C20
#define EQItemList__FreeItemList_x                                 0x596B20

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x52A470

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6485A0
#define EQPlayer__dEQPlayer_x                                      0x63B870
#define EQPlayer__DoAttack_x                                       0x650170
#define EQPlayer__EQPlayer_x                                       0x63BF20
#define EQPlayer__SetNameSpriteState_x                             0x6405D0
#define EQPlayer__SetNameSpriteTint_x                              0x6414A0
#define PlayerBase__HasProperty_j_x                                0x9791B0
#define EQPlayer__IsTargetable_x                                   0x979650
#define EQPlayer__CanSee_x                                         0x9794B0
#define EQPlayer__CanSee1_x                                        0x979580
#define PlayerBase__GetVisibilityLineSegment_x                     0x979270

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x652F40
#define PlayerZoneClient__GetLevel_x                               0x6554D0
#define PlayerZoneClient__IsValidTeleport_x                        0x5C30C0
#define PlayerZoneClient__LegalPlayerRace_x                        0x544680

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x64B280
#define EQPlayerManager__GetSpawnByName_x                          0x64B2A0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x64B330

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x60F1E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x60F220
#define KeypressHandler__ClearCommandStateArray_x                  0x610610
#define KeypressHandler__HandleKeyDown_x                           0x610630
#define KeypressHandler__HandleKeyUp_x                             0x6106D0
#define KeypressHandler__SaveKeymapping_x                          0x610AB0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7671F0
#define MapViewMap__SaveEx_x                                       0x76A590
#define MapViewMap__SetZoom_x                                      0x76EC60

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8B5920

// StringTable 
#define StringTable__getString_x                                   0x8B08F0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x635E70
#define PcZoneClient__RemovePetEffect_x                            0x6364A0
#define PcZoneClient__HasAlternateAbility_x                        0x630200
#define PcZoneClient__GetCurrentMod_x                              0x4E2300
#define PcZoneClient__GetModCap_x                                  0x4E2200
#define PcZoneClient__CanEquipItem_x                               0x6308B0
#define PcZoneClient__GetItemByID_x                                0x633480
#define PcZoneClient__GetItemByItemClass_x                         0x6335D0
#define PcZoneClient__RemoveBuffEffect_x                           0x6364C0
#define PcZoneClient__BandolierSwap_x                              0x6314E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5C7CB0

//IconCache
#define IconCache__GetIcon_x                                       0x707D10

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6FF800
#define CContainerMgr__CloseContainer_x                            0x6FFAD0
#define CContainerMgr__OpenExperimentContainer_x                   0x700550

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7C2620

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x603B70

//CLootWnd
#define CLootWnd__LootAll_x                                        0x75D590
#define CLootWnd__RequestLootSlot_x                                0x75C950

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5639F0
#define EQ_Spell__SpellAffects_x                                   0x563E60
#define EQ_Spell__SpellAffectBase_x                                0x563C20
#define EQ_Spell__IsStackable_x                                    0x4C6EF0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C6D40
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B4130
#define EQ_Spell__IsSPAStacking_x                                  0x564C90
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5641B0
#define EQ_Spell__IsNoRemove_x                                     0x4C6ED0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x564CA0
#define __IsResEffectSpell_x                                       0x4C61C0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AAA60

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8BFEE0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8080C0
#define CTargetWnd__WndNotification_x                              0x807950
#define CTargetWnd__RefreshTargetBuffs_x                           0x807C20
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x806AA0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x80C790

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x527E60

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x55EF80
#define EqSoundManager__PlayScriptMp3_x                            0x55F0E0
#define EqSoundManager__SoundAssistPlay_x                          0x66DBC0
#define EqSoundManager__WaveInstancePlay_x                         0x66D130

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x51BDF0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x931D70

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x552FF0
#define CAltAbilityData__GetMercMaxRank_x                          0x552F90
#define CAltAbilityData__GetMaxRank_x                              0x548350

//CTargetRing
#define CTargetRing__Cast_x                                        0x601C70

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C6D20
#define CharacterBase__CreateItemGlobalIndex_x                     0x502290
#define CharacterBase__CreateItemIndex_x                           0x609D50
#define CharacterBase__GetItemPossession_x                         0x4B3FE0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8C8560
#define CharacterBase__GetEffectId_x                               0x4C6CD0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6E7840
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6E8060

//messages
#define msg_spell_worn_off_x                                       0x588210
#define msg_new_text_x                                             0x57D040
#define __msgTokenTextParam_x                                      0x58A880
#define msgTokenText_x                                             0x58AAD0

//SpellManager
#define SpellManager__vftable_x                                    0xAB4A88
#define SpellManager__SpellManager_x                               0x670EE0
#define Spellmanager__LoadTextSpells_x                             0x6717B0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6710B0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x97D190

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x502940
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x58E6C0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x622870
#define ItemGlobalIndex__IsValidIndex_x                            0x5029A0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C0820
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C0AA0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7560E0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x703F60
#define CCursorAttachment__Deactivate_x                            0x704F40

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x944610
#define CEQSuiteTextureLoader__GetTexture_x                        0x9442D0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x4FF8B0

//IString
#define IString__Append_x                                          0x4EF7D0

//Camera
#define CDisplay__cameraType_x                                     0xDC6B34
#define EverQuest__Cameras_x                                       0xE89840

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x507FC0
#define LootFiltersManager__GetItemFilterData_x                    0x5078B0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x5078E0
#define LootFiltersManager__SetItemLootFilter_x                    0x507B00

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7B0610

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x982EA0
#define CResolutionHandler__GetWindowedStyle_x                     0x668790

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x6FC5C0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8D2FA0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x71C750
#define CGroupWnd__UpdateDisplay_x                                 0x71BAB0

//ItemBase
#define ItemBase__IsLore_x                                         0x8965E0
#define ItemBase__IsLoreEquipped_x                                 0x896650

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4F5C90

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
