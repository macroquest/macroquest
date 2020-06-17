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
#define __ExpectedVersionDate                                     "Jun  8 2020"
#define __ExpectedVersionTime                                     "23:15:20"
#define __ActualVersionDate_x                                      0xB1E618
#define __ActualVersionTime_x                                      0xB1E60C
#define __ActualVersionBuild_x                                     0xB0A2AC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x640540
#define __MemChecker1_x                                            0x915070
#define __MemChecker2_x                                            0x6CF7A0
#define __MemChecker3_x                                            0x6CF6F0
#define __MemChecker4_x                                            0x86B040
#define __EncryptPad0_x                                            0xC56520
#define __EncryptPad1_x                                            0xCB4688
#define __EncryptPad2_x                                            0xC66DB8
#define __EncryptPad3_x                                            0xC669B8
#define __EncryptPad4_x                                            0xCA4C38
#define __EncryptPad5_x                                            0xF77D70
#define __AC1_x                                                    0x827AF6
#define __AC2_x                                                    0x5F9FBF
#define __AC3_x                                                    0x60160F
#define __AC4_x                                                    0x6055D0
#define __AC5_x                                                    0x60B87F
#define __AC6_x                                                    0x60FD86
#define __AC7_x                                                    0x5F9A30
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x70A0C

// Direct Input
#define DI8__Main_x                                                0xF77D90
#define DI8__Keyboard_x                                            0xF77D94
#define DI8__Mouse_x                                               0xF77DAC
#define DI8__Mouse_Copy_x                                          0xED0F5C
#define DI8__Mouse_Check_x                                         0xF758C4
#define __AutoSkillArray_x                                         0xED1E74
#define __Attack_x                                                 0xF6FC9B
#define __Autofire_x                                               0xF6FC9C
#define __BindList_x                                               0xC44F38
#define g_eqCommandStates_x                                        0xC45CB8
#define __Clicks_x                                                 0xED1014
#define __CommandList_x                                            0xC46878
#define __CurrentMapLabel_x                                        0xF88764
#define __CurrentSocial_x                                          0xC2E7D4
#define __DoAbilityList_x                                          0xF077BC
#define __do_loot_x                                                0x5C5F20
#define __DrawHandler_x                                            0x1607AE0
#define __GroupCount_x                                             0xECC032
#define __Guilds_x                                                 0xECFE98
#define __gWorld_x                                                 0xECC014
#define __HWnd_x                                                   0xF77DB0
#define __heqmain_x                                                0xF77D58
#define __InChatMode_x                                             0xED0F44
#define __LastTell_x                                               0xED2EB8
#define __LMouseHeldTime_x                                         0xED1080
#define __Mouse_x                                                  0xF77D7C
#define __MouseLook_x                                              0xED0FDA
#define __MouseEventTime_x                                         0xF7077C
#define __gpbCommandEvent_x                                        0xEC9928
#define __NetStatusToggle_x                                        0xED0FDD
#define __PCNames_x                                                0xED2464
#define __RangeAttackReady_x                                       0xED2158
#define __RMouseHeldTime_x                                         0xED107C
#define __RunWalkState_x                                           0xED0F48
#define __ScreenMode_x                                             0xE172CC
#define __ScreenX_x                                                0xED0EFC
#define __ScreenY_x                                                0xED0EF8
#define __ScreenXMax_x                                             0xED0F00
#define __ScreenYMax_x                                             0xED0F04
#define __ServerHost_x                                             0xEC9B13
#define __ServerName_x                                             0xF0777C
#define __ShiftKeyDown_x                                           0xED15D4
#define __ShowNames_x                                              0xED2314
#define EverQuestInfo__bSocialChanged_x                            0xF07804
#define __Socials_x                                                0xF0787C
#define __SubscriptionType_x                                       0xFCCC70
#define __TargetAggroHolder_x                                      0xF8B118
#define __ZoneType_x                                               0xED13D8
#define __GroupAggro_x                                             0xF8B158
#define __LoginName_x                                              0xF784EC
#define __Inviter_x                                                0xF6FC18
#define __AttackOnAssist_x                                         0xED22D0
#define __UseTellWindows_x                                         0xED2600
#define __gfMaxZoomCameraDistance_x                                0xB13F10
#define __gfMaxCameraDistance_x                                    0xB403A8
#define __pulAutoRun_x                                             0xED0FF8
#define __pulForward_x                                             0xED2638
#define __pulBackward_x                                            0xED263C
#define __pulTurnRight_x                                           0xED2640
#define __pulTurnLeft_x                                            0xED2644
#define __pulStrafeLeft_x                                          0xED2648
#define __pulStrafeRight_x                                         0xED264C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xECC230
#define instEQZoneInfo_x                                           0xED11D0
#define pinstActiveBanker_x                                        0xEC9A04
#define pinstActiveCorpse_x                                        0xEC99FC
#define pinstActiveGMaster_x                                       0xEC9A00
#define pinstActiveMerchant_x                                      0xEC99F8
#define pinstAltAdvManager_x                                       0xE18460
#define pinstBandageTarget_x                                       0xEC9C20
#define pinstCamActor_x                                            0xE172BC
#define pinstCDBStr_x                                              0xE1717C
#define pinstCDisplay_x                                            0xECBE80
#define pinstCEverQuest_x                                          0xF77DA8
#define pinstEverQuestInfo_x                                       0xED0EF0
#define pinstCharData_x                                            0xECC01C
#define pinstCharSpawn_x                                           0xEC9E5C
#define pinstControlledMissile_x                                   0xEC9E70
#define pinstControlledPlayer_x                                    0xEC9E5C
#define pinstCResolutionHandler_x                                  0x1607D10
#define pinstCSidlManager_x                                        0x1606CA8
#define pinstCXWndManager_x                                        0x1606CA4
#define instDynamicZone_x                                          0xECFD70
#define pinstDZMember_x                                            0xECFE80
#define pinstDZTimerInfo_x                                         0xECFE84
#define pinstEqLogin_x                                             0xF77E38
#define instEQMisc_x                                               0xE170C0
#define pinstEQSoundManager_x                                      0xE19430
#define pinstEQSpellStrings_x                                      0xCD9AD8
#define instExpeditionLeader_x                                     0xECFDBA
#define instExpeditionName_x                                       0xECFDFA
#define pinstGroup_x                                               0xECC02E
#define pinstImeManager_x                                          0x1606CA0
#define pinstLocalPlayer_x                                         0xEC99F4
#define pinstMercenaryData_x                                       0xF72274
#define pinstMercenaryStats_x                                      0xF8B264
#define pinstModelPlayer_x                                         0xEC9A0C
#define pinstPCData_x                                              0xECC01C
#define pinstSkillMgr_x                                            0xF743D8
#define pinstSpawnManager_x                                        0xF72E80
#define pinstSpellManager_x                                        0xF74618
#define pinstSpellSets_x                                           0xF688C4
#define pinstStringTable_x                                         0xECC224
#define pinstSwitchManager_x                                       0xEC97D0
#define pinstTarget_x                                              0xEC9C24
#define pinstTargetObject_x                                        0xEC9E64
#define pinstTargetSwitch_x                                        0xECBE78
#define pinstTaskMember_x                                          0xE16F50
#define pinstTrackTarget_x                                         0xEC9E60
#define pinstTradeTarget_x                                         0xEC9A08
#define instTributeActive_x                                        0xE170E1
#define pinstViewActor_x                                           0xE172B8
#define pinstWorldData_x                                           0xEC9E6C
#define pinstZoneAddr_x                                            0xED1470
#define pinstPlayerPath_x                                          0xF72F18
#define pinstTargetIndicator_x                                     0xF74880
#define EQObject_Top_x                                             0xEC99F0
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE175D4
#define pinstCAchievementsWnd_x                                    0xE17244
#define pinstCActionsWnd_x                                         0xE17A74
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE172F4
#define pinstCAdvancedLootWnd_x                                    0xE1728C
#define pinstCAdventureLeaderboardWnd_x                            0xF81F38
#define pinstCAdventureRequestWnd_x                                0xF81FE8
#define pinstCAdventureStatsWnd_x                                  0xF82098
#define pinstCAggroMeterWnd_x                                      0xE172F8
#define pinstCAlarmWnd_x                                           0xE1725C
#define pinstCAlertHistoryWnd_x                                    0xE17370
#define pinstCAlertStackWnd_x                                      0xE172AC
#define pinstCAlertWnd_x                                           0xE172E0
#define pinstCAltStorageWnd_x                                      0xF823F8
#define pinstCAudioTriggersWindow_x                                0xCCBE08
#define pinstCAuraWnd_x                                            0xE17294
#define pinstCAvaZoneWnd_x                                         0xE1732C
#define pinstCBandolierWnd_x                                       0xE172EC
#define pinstCBankWnd_x                                            0xE17328
#define pinstCBarterMerchantWnd_x                                  0xF83638
#define pinstCBarterSearchWnd_x                                    0xF836E8
#define pinstCBarterWnd_x                                          0xF83798
#define pinstCBazaarConfirmationWnd_x                              0xE1727C
#define pinstCBazaarSearchWnd_x                                    0xE175DC
#define pinstCBazaarWnd_x                                          0xE17240
#define pinstCBlockedBuffWnd_x                                     0xE1729C
#define pinstCBlockedPetBuffWnd_x                                  0xE172DC
#define pinstCBodyTintWnd_x                                        0xE17A80
#define pinstCBookWnd_x                                            0xE1731C
#define pinstCBreathWnd_x                                          0xE1765C
#define pinstCBuffWindowNORMAL_x                                   0xE17284
#define pinstCBuffWindowSHORT_x                                    0xE17288
#define pinstCBugReportWnd_x                                       0xE17324
#define pinstCButtonWnd_x                                          0x1606F10
#define pinstCCastingWnd_x                                         0xE1730C
#define pinstCCastSpellWnd_x                                       0xE17654
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE17A9C
#define pinstCChatWindowManager_x                                  0xF84258
#define pinstCClaimWnd_x                                           0xF843B0
#define pinstCColorPickerWnd_x                                     0xE1758C
#define pinstCCombatAbilityWnd_x                                   0xE17254
#define pinstCCombatSkillsSelectWnd_x                              0xE17AA4
#define pinstCCompassWnd_x                                         0xE17A78
#define pinstCConfirmationDialog_x                                 0xF892B0
#define pinstCContainerMgr_x                                       0xE17A94
#define pinstCContextMenuManager_x                                 0x1606C60
#define pinstCCursorAttachment_x                                   0xE17300
#define pinstCDynamicZoneWnd_x                                     0xF84978
#define pinstCEditLabelWnd_x                                       0xE17278
#define pinstCEQMainWnd_x                                          0xF84BC0
#define pinstCEventCalendarWnd_x                                   0xE17660
#define pinstCExtendedTargetWnd_x                                  0xE172D8
#define pinstCFacePick_x                                           0xE17220
#define pinstCFactionWnd_x                                         0xE1722C
#define pinstCFellowshipWnd_x                                      0xF84DC0
#define pinstCFileSelectionWnd_x                                   0xE1737C
#define pinstCFindItemWnd_x                                        0xE17218
#define pinstCFindLocationWnd_x                                    0xF84F18
#define pinstCFriendsWnd_x                                         0xE1721C
#define pinstCGemsGameWnd_x                                        0xE17228
#define pinstCGiveWnd_x                                            0xE17268
#define pinstCGroupSearchFiltersWnd_x                              0xE17314
#define pinstCGroupSearchWnd_x                                     0xF85310
#define pinstCGroupWnd_x                                           0xF853C0
#define pinstCGuildBankWnd_x                                       0xED22B4
#define pinstCGuildCreationWnd_x                                   0xF85520
#define pinstCGuildMgmtWnd_x                                       0xF855D0
#define pinstCharacterCreation_x                                   0xE17AAC
#define pinstCHelpWnd_x                                            0xE17260
#define pinstCHeritageSelectionWnd_x                               0xE17230
#define pinstCHotButtonWnd_x                                       0xF87728
#define pinstCHotButtonWnd1_x                                      0xF87728
#define pinstCHotButtonWnd2_x                                      0xF8772C
#define pinstCHotButtonWnd3_x                                      0xF87730
#define pinstCHotButtonWnd4_x                                      0xF87734
#define pinstCIconSelectionWnd_x                                   0xE172FC
#define pinstCInspectWnd_x                                         0xE172E4
#define pinstCInventoryWnd_x                                       0xE17298
#define pinstCInvSlotMgr_x                                         0xE175EC
#define pinstCItemDisplayManager_x                                 0xF87CB8
#define pinstCItemExpTransferWnd_x                                 0xF87DE8
#define pinstCItemOverflowWnd_x                                    0xE17658
#define pinstCJournalCatWnd_x                                      0xE17598
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE17350
#define pinstCKeyRingWnd_x                                         0xE17308
#define pinstCLargeDialogWnd_x                                     0xF89F30
#define pinstCLayoutCopyWnd_x                                      0xF88138
#define pinstCLFGuildWnd_x                                         0xF881E8
#define pinstCLoadskinWnd_x                                        0xE1723C
#define pinstCLootFiltersCopyWnd_x                                 0xCE8458
#define pinstCLootFiltersWnd_x                                     0xE172B4
#define pinstCLootSettingsWnd_x                                    0xE172F0
#define pinstCLootWnd_x                                            0xE1759C
#define pinstCMailAddressBookWnd_x                                 0xE17664
#define pinstCMailCompositionWnd_x                                 0xE175CC
#define pinstCMailIgnoreListWnd_x                                  0xE17A68
#define pinstCMailWnd_x                                            0xE17590
#define pinstCManageLootWnd_x                                      0xE18910
#define pinstCMapToolbarWnd_x                                      0xE17264
#define pinstCMapViewWnd_x                                         0xE17234
#define pinstCMarketplaceWnd_x                                     0xE172C4
#define pinstCMerchantWnd_x                                        0xE175A8
#define pinstCMIZoneSelectWnd_x                                    0xF88A20
#define pinstCMusicPlayerWnd_x                                     0xE1736C
#define pinstCNameChangeMercWnd_x                                  0xE17270
#define pinstCNameChangePetWnd_x                                   0xE1724C
#define pinstCNameChangeWnd_x                                      0xE17280
#define pinstCNoteWnd_x                                            0xE17248
#define pinstCObjectPreviewWnd_x                                   0xE172E8
#define pinstCOptionsWnd_x                                         0xE17258
#define pinstCPetInfoWnd_x                                         0xE17368
#define pinstCPetitionQWnd_x                                       0xE17AA8
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE17A88
#define pinstCPlayerWnd_x                                          0xE17378
#define pinstCPopupWndManager_x                                    0xF892B0
#define pinstCProgressionSelectionWnd_x                            0xF89360
#define pinstCPurchaseGroupWnd_x                                   0xE17334
#define pinstCPurchaseWnd_x                                        0xE17320
#define pinstCPvPLeaderboardWnd_x                                  0xF89410
#define pinstCPvPStatsWnd_x                                        0xF894C0
#define pinstCQuantityWnd_x                                        0xE17354
#define pinstCRaceChangeWnd_x                                      0xE172A4
#define pinstCRaidOptionsWnd_x                                     0xE17318
#define pinstCRaidWnd_x                                            0xE175A0
#define pinstCRealEstateItemsWnd_x                                 0xE17238
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE17A84
#define pinstCRealEstateManageWnd_x                                0xE17340
#define pinstCRealEstateNeighborhoodWnd_x                          0xE17360
#define pinstCRealEstatePlotSearchWnd_x                            0xE17384
#define pinstCRealEstatePurchaseWnd_x                              0xE175A4
#define pinstCRespawnWnd_x                                         0xE172B0
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE17AA0
#define pinstCSendMoneyWnd_x                                       0xE17274
#define pinstCServerListWnd_x                                      0xE175AC
#define pinstCSkillsSelectWnd_x                                    0xE17A90
#define pinstCSkillsWnd_x                                          0xE17A7C
#define pinstCSocialEditWnd_x                                      0xE17304
#define pinstCSocialWnd_x                                          0xE1726C
#define pinstCSpellBookWnd_x                                       0xE17250
#define pinstCStoryWnd_x                                           0xE17A70
#define pinstCTargetOfTargetWnd_x                                  0xF8B2E8
#define pinstCTargetWnd_x                                          0xE172A8
#define pinstCTaskOverlayWnd_x                                     0xE17330
#define pinstCTaskSelectWnd_x                                      0xF8B440
#define pinstCTaskManager_x                                        0xCE8D98
#define pinstCTaskTemplateSelectWnd_x                              0xF8B4F0
#define pinstCTaskWnd_x                                            0xF8B5A0
#define pinstCTextEntryWnd_x                                       0xE17310
#define pinstCTimeLeftWnd_x                                        0xE17A98
#define pinstCTipWndCONTEXT_x                                      0xF8B7A4
#define pinstCTipWndOFDAY_x                                        0xF8B7A0
#define pinstCTitleWnd_x                                           0xF8B850
#define pinstCTrackingWnd_x                                        0xE172A0
#define pinstCTradeskillWnd_x                                      0xF8B9B8
#define pinstCTradeWnd_x                                           0xE17A8C
#define pinstCTrainWnd_x                                           0xE17594
#define pinstCTributeBenefitWnd_x                                  0xF8BBB8
#define pinstCTributeMasterWnd_x                                   0xF8BC68
#define pinstCTributeTrophyWnd_x                                   0xF8BD18
#define pinstCVideoModesWnd_x                                      0xE17374
#define pinstCVoiceMacroWnd_x                                      0xF74FE8
#define pinstCVoteResultsWnd_x                                     0xE17224
#define pinstCVoteWnd_x                                            0xE17AB0
#define pinstCWebManager_x                                         0xF75664
#define pinstCZoneGuideWnd_x                                       0xE17338
#define pinstCZonePathWnd_x                                        0xE17358

#define pinstEQSuiteTextureLoader_x                                0xCB6160
#define pinstItemIconCache_x                                       0xF84B78
#define pinstLootFiltersManager_x                                  0xCE8508
#define pinstRewardSelectionWnd_x                                  0xF89C08

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C12F0
#define __CastRay2_x                                               0x5C1340
#define __ConvertItemTags_x                                        0x5DD180
#define __CleanItemTags_x                                          0x47D5B0
#define __DoesFileExist_x                                          0x9180A0
#define __EQGetTime_x                                              0x914B40
#define __ExecuteCmd_x                                             0x5B9B90
#define __FixHeading_x                                             0x9AF7E0
#define __FlushDxKeyboard_x                                        0x6CB640
#define __GameLoop_x                                               0x6CE970
#define __get_bearing_x                                            0x5C0E50
#define __get_melee_range_x                                        0x5C1530
#define __GetAnimationCache_x                                      0x733ED0
#define __GetGaugeValueFromEQ_x                                    0x825FA0
#define __GetLabelFromEQ_x                                         0x827A80
#define __GetXTargetType_x                                         0x9B12A0
#define __HandleMouseWheel_x                                       0x6CF850
#define __HeadingDiff_x                                            0x9AF850
#define __HelpPath_x                                               0xF7036C
#define __LoadFrontEnd_x                                           0x6CBC80
#define __NewUIINI_x                                               0x825C70
#define __ProcessGameEvents_x                                      0x621930
#define __ProcessMouseEvent_x                                      0x6210F0
#define __SaveColors_x                                             0x55A8A0
#define __STMLToText_x                                             0x952E30
#define __ToggleKeyRingItem_x                                      0x51B040
#define CMemoryMappedFile__SetFile_x                               0xA9EA70
#define CrashDetected_x                                            0x6CD730
#define DrawNetStatus_x                                            0x64D7B0
#define Expansion_HoT_x                                            0xED22BC
#define Teleport_Table_Size_x                                      0xEC99B0
#define Teleport_Table_x                                           0xEC9E78
#define Util__FastTime_x                                           0x914710
#define __CopyLayout_x                                             0x63BC50
#define __WndProc_x                                                0x6CDC30
#define __ProcessKeyboardEvent_x                                   0x6CD1D0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490980
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499950
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499720
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493F10
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x493360

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x562A10
#define AltAdvManager__IsAbilityReady_x                            0x5617B0
#define AltAdvManager__GetAAById_x                                 0x561B40
#define AltAdvManager__CanTrainAbility_x                           0x561BB0
#define AltAdvManager__CanSeeAbility_x                             0x561F10

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB570
#define CharacterZoneClient__HasSkill_x                            0x4D63F0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7B10
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2E60
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BC2F0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA480
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA560
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA640
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4F40
#define CharacterZoneClient__BardCastBard_x                        0x4C7940
#define CharacterZoneClient__GetMaxEffects_x                       0x4BFD10
#define CharacterZoneClient__GetEffect_x                           0x4BC230
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5F90
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C6060
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C60B0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C6200
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C63D0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B4020
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8A70
#define CharacterZoneClient__FindItemByRecord_x                    0x4D84F0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6F5470
#define CBankWnd__WndNotification_x                                0x6F5250

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x702E70

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x6300B0
#define CButtonWnd__CButtonWnd_x                                   0x94F200

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x722FC0
#define CChatManager__InitContextMenu_x                            0x71C100
#define CChatManager__FreeChatWindow_x                             0x721B00
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9C60
#define CChatManager__SetLockedActiveChatWindow_x                  0x722C40
#define CChatManager__CreateChatWindow_x                           0x722140

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9D70

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x963890
#define CContextMenu__dCContextMenu_x                              0x963AB0
#define CContextMenu__AddMenuItem_x                                0x963AC0
#define CContextMenu__RemoveMenuItem_x                             0x963DC0
#define CContextMenu__RemoveAllMenuItems_x                         0x963DE0
#define CContextMenu__CheckMenuItem_x                              0x963E60
#define CContextMenu__SetMenuItem_x                                0x963CF0
#define CContextMenu__AddSeparator_x                               0x963C50

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9643F0
#define CContextMenuManager__RemoveMenu_x                          0x964460
#define CContextMenuManager__PopupMenu_x                           0x964520
#define CContextMenuManager__Flush_x                               0x964390
#define CContextMenuManager__GetMenu_x                             0x49BD60
#define CContextMenuManager__CreateDefaultMenu_x                   0x72E700

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8EF950
#define CChatService__GetFriendName_x                              0x8EF960

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x723830
#define CChatWindow__Clear_x                                       0x724AF0
#define CChatWindow__WndNotification_x                             0x725280
#define CChatWindow__AddHistory_x                                  0x7243B0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x960D00
#define CComboWnd__Draw_x                                          0x960210
#define CComboWnd__GetCurChoice_x                                  0x960B40
#define CComboWnd__GetListRect_x                                   0x9606B0
#define CComboWnd__GetTextRect_x                                   0x960D60
#define CComboWnd__InsertChoice_x                                  0x960840
#define CComboWnd__SetColors_x                                     0x960810
#define CComboWnd__SetChoice_x                                     0x960B10
#define CComboWnd__GetItemCount_x                                  0x960B50
#define CComboWnd__GetCurChoiceText_x                              0x960B90
#define CComboWnd__GetChoiceText_x                                 0x960B60
#define CComboWnd__InsertChoiceAtIndex_x                           0x9608D0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x72C140
#define CContainerWnd__vftable_x                                   0xB2780C
#define CContainerWnd__SetContainer_x                              0x72D690

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x555250
#define CDisplay__PreZoneMainUI_x                                  0x555260
#define CDisplay__CleanGameUI_x                                    0x55A660
#define CDisplay__GetClickedActor_x                                0x54D610
#define CDisplay__GetUserDefinedColor_x                            0x545C70
#define CDisplay__GetWorldFilePath_x                               0x54F080
#define CDisplay__is3dON_x                                         0x54A270
#define CDisplay__ReloadUI_x                                       0x5546D0
#define CDisplay__WriteTextHD2_x                                   0x54A060
#define CDisplay__TrueDistance_x                                   0x550D40
#define CDisplay__SetViewActor_x                                   0x54CF30
#define CDisplay__GetFloorHeight_x                                 0x54A330
#define CDisplay__SetRenderWindow_x                                0x548C90
#define CDisplay__ToggleScreenshotMode_x                           0x54CA00

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9835E0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x966DB0
#define CEditWnd__EnsureCaretVisible_x                             0x968F10
#define CEditWnd__GetCaretPt_x                                     0x967F00
#define CEditWnd__GetCharIndexPt_x                                 0x967CC0
#define CEditWnd__GetDisplayString_x                               0x967B70
#define CEditWnd__GetHorzOffset_x                                  0x966400
#define CEditWnd__GetLineForPrintableChar_x                        0x968E10
#define CEditWnd__GetSelStartPt_x                                  0x967F60
#define CEditWnd__GetSTMLSafeText_x                                0x967990
#define CEditWnd__PointFromPrintableChar_x                         0x968A60
#define CEditWnd__SelectableCharFromPoint_x                        0x968BC0
#define CEditWnd__SetEditable_x                                    0x968020
#define CEditWnd__SetWindowTextA_x                                 0x967710
#define CEditWnd__ReplaceSelection_x                               0x9686E0
#define CEditWnd__ReplaceSelection1_x                              0x968660

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60F260
#define CEverQuest__ClickedPlayer_x                                0x6013F0
#define CEverQuest__CreateTargetIndicator_x                        0x61EBC0
#define CEverQuest__DeleteTargetIndicator_x                        0x61EC50
#define CEverQuest__DoTellWindow_x                                 0x4E9E50
#define CEverQuest__OutputTextToLog_x                              0x4EA120
#define CEverQuest__DropHeldItemOnGround_x                         0x5F6550
#define CEverQuest__dsp_chat_x                                     0x4EA4B0
#define CEverQuest__trimName_x                                     0x61ADD0
#define CEverQuest__Emote_x                                        0x60FAC0
#define CEverQuest__EnterZone_x                                    0x609B50
#define CEverQuest__GetBodyTypeDesc_x                              0x614370
#define CEverQuest__GetClassDesc_x                                 0x6149B0
#define CEverQuest__GetClassThreeLetterCode_x                      0x614FB0
#define CEverQuest__GetDeityDesc_x                                 0x61D410
#define CEverQuest__GetLangDesc_x                                  0x615170
#define CEverQuest__GetRaceDesc_x                                  0x614990
#define CEverQuest__InterpretCmd_x                                 0x61D9E0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FA6E0
#define CEverQuest__LMouseUp_x                                     0x5F8A70
#define CEverQuest__RightClickedOnPlayer_x                         0x5FAFC0
#define CEverQuest__RMouseUp_x                                     0x5F99F0
#define CEverQuest__SetGameState_x                                 0x5F62E0
#define CEverQuest__UPCNotificationFlush_x                         0x61ACD0
#define CEverQuest__IssuePetCommand_x                              0x616570
#define CEverQuest__ReportSuccessfulHit_x                          0x610E10

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x73DFA0
#define CGaugeWnd__CalcLinesFillRect_x                             0x73E000
#define CGaugeWnd__Draw_x                                          0x73D620

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B03A0
#define CGuild__GetGuildName_x                                     0x4AEE50
#define CGuild__GetGuildIndex_x                                    0x4AF450

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7581A0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x630470

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7651F0
#define CInvSlotMgr__MoveItem_x                                    0x763F10
#define CInvSlotMgr__SelectSlot_x                                  0x7652C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x762740
#define CInvSlot__SliderComplete_x                                 0x7604B0
#define CInvSlot__GetItemBase_x                                    0x75FE20
#define CInvSlot__UpdateItem_x                                     0x75FF90

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x766D30
#define CInvSlotWnd__CInvSlotWnd_x                                 0x765EC0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7668B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8212D0
#define CItemDisplayWnd__UpdateStrings_x                           0x7754F0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76F180
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76F6B0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x775AF0
#define CItemDisplayWnd__AboutToShow_x                             0x775160
#define CItemDisplayWnd__WndNotification_x                         0x776C30
#define CItemDisplayWnd__RequestConvertItem_x                      0x7766A0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7741C0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x774F80

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x85A0B0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x77B130

// CLabel 
#define CLabel__Draw_x                                             0x780BC0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9395C0
#define CListWnd__dCListWnd_x                                      0x9398E0
#define CListWnd__AddColumn_x                                      0x93DD20
#define CListWnd__AddColumn1_x                                     0x93DD70
#define CListWnd__AddLine_x                                        0x93E100
#define CListWnd__AddString_x                                      0x93DF00
#define CListWnd__CalculateFirstVisibleLine_x                      0x93DAF0
#define CListWnd__CalculateVSBRange_x                              0x93D8E0
#define CListWnd__ClearSel_x                                       0x93E8E0
#define CListWnd__ClearAllSel_x                                    0x93E940
#define CListWnd__CloseAndUpdateEditWindow_x                       0x93F330
#define CListWnd__Compare_x                                        0x93D210
#define CListWnd__Draw_x                                           0x939A10
#define CListWnd__DrawColumnSeparators_x                           0x93C1E0
#define CListWnd__DrawHeader_x                                     0x93C650
#define CListWnd__DrawItem_x                                       0x93CB50
#define CListWnd__DrawLine_x                                       0x93C350
#define CListWnd__DrawSeparator_x                                  0x93C280
#define CListWnd__EnableLine_x                                     0x93BAC0
#define CListWnd__EnsureVisible_x                                  0x93F270
#define CListWnd__ExtendSel_x                                      0x93E810
#define CListWnd__GetColumnTooltip_x                               0x93B600
#define CListWnd__GetColumnMinWidth_x                              0x93B670
#define CListWnd__GetColumnWidth_x                                 0x93B570
#define CListWnd__GetCurSel_x                                      0x93AF00
#define CListWnd__GetItemAtPoint_x                                 0x93BD30
#define CListWnd__GetItemAtPoint1_x                                0x93BDA0
#define CListWnd__GetItemData_x                                    0x93AF80
#define CListWnd__GetItemHeight_x                                  0x93B340
#define CListWnd__GetItemIcon_x                                    0x93B110
#define CListWnd__GetItemRect_x                                    0x93BBB0
#define CListWnd__GetItemText_x                                    0x93AFC0
#define CListWnd__GetSelList_x                                     0x93E990
#define CListWnd__GetSeparatorRect_x                               0x93BFE0
#define CListWnd__InsertLine_x                                     0x93E4F0
#define CListWnd__RemoveLine_x                                     0x93E640
#define CListWnd__SetColors_x                                      0x93D8B0
#define CListWnd__SetColumnJustification_x                         0x93D5E0
#define CListWnd__SetColumnLabel_x                                 0x93DEA0
#define CListWnd__SetColumnWidth_x                                 0x93D500
#define CListWnd__SetCurSel_x                                      0x93E750
#define CListWnd__SetItemColor_x                                   0x93EF30
#define CListWnd__SetItemData_x                                    0x93EEF0
#define CListWnd__SetItemText_x                                    0x93EB00
#define CListWnd__ShiftColumnSeparator_x                           0x93D6A0
#define CListWnd__Sort_x                                           0x93D390
#define CListWnd__ToggleSel_x                                      0x93E780
#define CListWnd__SetColumnsSizable_x                              0x93D750
#define CListWnd__SetItemWnd_x                                     0x93EDB0
#define CListWnd__GetItemWnd_x                                     0x93B160
#define CListWnd__SetItemIcon_x                                    0x93EB80
#define CListWnd__CalculateCustomWindowPositions_x                 0x93DBE0
#define CListWnd__SetVScrollPos_x                                  0x93D4E0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x796290
#define CMapViewWnd__GetWorldCoordinates_x                         0x7949A0
#define CMapViewWnd__HandleLButtonDown_x                           0x7919E0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B6510
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B6DF0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B7320
#define CMerchantWnd__SelectRecoverySlot_x                         0x7BA2A0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B5080
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BFE50
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B6120

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8BD580
#define CPacketScrambler__hton_x                                   0x8BD570

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x958460
#define CSidlManager__FindScreenPieceTemplate_x                    0x958870
#define CSidlManager__FindScreenPieceTemplate1_x                   0x958660
#define CSidlManager__CreateLabel_x                                0x8184C0
#define CSidlManager__CreateXWndFromTemplate_x                     0x95B7D0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x95B9A0
#define CSidlManager__CreateXWnd_x                                 0x8183F0
#define CSidlManager__CreateHotButtonWnd_x                         0x8189B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x954F30
#define CSidlScreenWnd__CalculateVSBRange_x                        0x954E30
#define CSidlScreenWnd__ConvertToRes_x                             0x97E120
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9548D0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9545C0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x954690
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x954760
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9553C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x955890
#define CSidlScreenWnd__GetSidlPiece_x                             0x9555B0
#define CSidlScreenWnd__Init1_x                                    0x9541E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x9558E0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x956440
#define CSidlScreenWnd__LoadSidlScreen_x                           0x9535F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x955FB0
#define CSidlScreenWnd__StoreIniVis_x                              0x956320
#define CSidlScreenWnd__WndNotification_x                          0x9552D0
#define CSidlScreenWnd__GetChildItem_x                             0x955810
#define CSidlScreenWnd__HandleLButtonUp_x                          0x945040
#define CSidlScreenWnd__m_layoutCopy_x                             0x1606B30

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6958E0
#define CSkillMgr__GetSkillCap_x                                   0x695AC0
#define CSkillMgr__GetNameToken_x                                  0x695060
#define CSkillMgr__IsActivatedSkill_x                              0x6951A0
#define CSkillMgr__IsCombatSkill_x                                 0x6950E0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9651E0
#define CSliderWnd__SetValue_x                                     0x965050
#define CSliderWnd__SetNumTicks_x                                  0x9650B0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x81E600

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x96D930
#define CStmlWnd__ParseSTML_x                                      0x96EC60
#define CStmlWnd__CalculateHSBRange_x                              0x96EA40
#define CStmlWnd__CalculateVSBRange_x                              0x96E9C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x972D70
#define CStmlWnd__FastForwardToEndOfTag_x                          0x973A00
#define CStmlWnd__ForceParseNow_x                                  0x96DF20
#define CStmlWnd__GetNextTagPiece_x                                0x972CD0
#define CStmlWnd__GetSTMLText_x                                    0x50A9C0
#define CStmlWnd__GetVisibleText_x                                 0x96DF40
#define CStmlWnd__InitializeWindowVariables_x                      0x973850
#define CStmlWnd__MakeStmlColorTag_x                               0x96CFA0
#define CStmlWnd__MakeWndNotificationTag_x                         0x96D010
#define CStmlWnd__SetSTMLText_x                                    0x96C050
#define CStmlWnd__StripFirstSTMLLines_x                            0x974AF0
#define CStmlWnd__UpdateHistoryString_x                            0x973C10

// CTabWnd 
#define CTabWnd__Draw_x                                            0x96B1A0
#define CTabWnd__DrawCurrentPage_x                                 0x96B8D0
#define CTabWnd__DrawTab_x                                         0x96B5F0
#define CTabWnd__GetCurrentPage_x                                  0x96A9B0
#define CTabWnd__GetPageInnerRect_x                                0x96ABF0
#define CTabWnd__GetTabInnerRect_x                                 0x96AB30
#define CTabWnd__GetTabRect_x                                      0x96A9E0
#define CTabWnd__InsertPage_x                                      0x96AE00
#define CTabWnd__RemovePage_x                                      0x96AF70
#define CTabWnd__SetPage_x                                         0x96AC70
#define CTabWnd__SetPageRect_x                                     0x96B0E0
#define CTabWnd__UpdatePage_x                                      0x96B4B0
#define CTabWnd__GetPageFromTabIndex_x                             0x96B530
#define CTabWnd__GetCurrentTabIndex_x                              0x96A9A0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x77B500
#define CPageWnd__SetTabText_x                                     0x96A500
#define CPageWnd__FlashTab_x                                       0x96A560

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9700

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x941F70
#define CTextureFont__GetTextExtent_x                              0x942130

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C8810
#define CHtmlComponentWnd__ValidateUri_x                           0x759B90
#define CHtmlWnd__SetClientCallbacks_x                             0x6354F0
#define CHtmlWnd__AddObserver_x                                    0x635510
#define CHtmlWnd__RemoveObserver_x                                 0x635570
#define Window__getProgress_x                                      0x872680
#define Window__getStatus_x                                        0x8726A0
#define Window__getURI_x                                           0x8726B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x97AF30

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x92F2A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9B50
#define CXStr__CXStr1_x                                            0x862FC0
#define CXStr__CXStr3_x                                            0x910B00
#define CXStr__dCXStr_x                                            0x4787D0
#define CXStr__operator_equal_x                                    0x910D30
#define CXStr__operator_equal1_x                                   0x910D70
#define CXStr__operator_plus_equal1_x                              0x911800
#define CXStr__SetString_x                                         0x9136F0
#define CXStr__operator_char_p_x                                   0x911240
#define CXStr__GetChar_x                                           0x913040
#define CXStr__Delete_x                                            0x9128F0
#define CXStr__GetUnicode_x                                        0x9130B0
#define CXStr__GetLength_x                                         0x47D960
#define CXStr__Mid_x                                               0x47D970
#define CXStr__Insert_x                                            0x913110
#define CXStr__FindNext_x                                          0x912D60

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x963490
#define CXWnd__BringToTop_x                                        0x9487B0
#define CXWnd__Center_x                                            0x948330
#define CXWnd__ClrFocus_x                                          0x948150
#define CXWnd__Destroy_x                                           0x9481F0
#define CXWnd__DoAllDrawing_x                                      0x944800
#define CXWnd__DrawChildren_x                                      0x9447D0
#define CXWnd__DrawColoredRect_x                                   0x944C30
#define CXWnd__DrawTooltip_x                                       0x943350
#define CXWnd__DrawTooltipAtPoint_x                                0x943410
#define CXWnd__GetBorderFrame_x                                    0x944AA0
#define CXWnd__GetChildWndAt_x                                     0x948850
#define CXWnd__GetClientClipRect_x                                 0x946A30
#define CXWnd__GetScreenClipRect_x                                 0x946AE0
#define CXWnd__GetScreenRect_x                                     0x946C60
#define CXWnd__GetRelativeRect_x                                   0x946D20
#define CXWnd__GetTooltipRect_x                                    0x944C80
#define CXWnd__GetWindowTextA_x                                    0x49D450
#define CXWnd__IsActive_x                                          0x9453B0
#define CXWnd__IsDescendantOf_x                                    0x947670
#define CXWnd__IsReallyVisible_x                                   0x9476A0
#define CXWnd__IsType_x                                            0x948EA0
#define CXWnd__Move_x                                              0x947720
#define CXWnd__Move1_x                                             0x9477D0
#define CXWnd__ProcessTransition_x                                 0x9482E0
#define CXWnd__Refade_x                                            0x947AA0
#define CXWnd__Resize_x                                            0x947D60
#define CXWnd__Right_x                                             0x948570
#define CXWnd__SetFocus_x                                          0x948110
#define CXWnd__SetFont_x                                           0x948180
#define CXWnd__SetKeyTooltip_x                                     0x948CC0
#define CXWnd__SetMouseOver_x                                      0x945C00
#define CXWnd__StartFade_x                                         0x947550
#define CXWnd__GetChildItem_x                                      0x9489B0
#define CXWnd__SetParent_x                                         0x947400
#define CXWnd__Minimize_x                                          0x947DD0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x97F1A0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x94B690
#define CXWndManager__DrawWindows_x                                0x94B6B0
#define CXWndManager__GetKeyboardFlags_x                           0x94DE80
#define CXWndManager__HandleKeyboardMsg_x                          0x94DA40
#define CXWndManager__RemoveWnd_x                                  0x94E0B0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x94E630

// CDBStr
#define CDBStr__GetString_x                                        0x544C10

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4C0470
#define EQ_Character__Cur_HP_x                                     0x4D3430
#define EQ_Character__Cur_Mana_x                                   0x4DAB40
#define EQ_Character__GetCastingTimeModifier_x                     0x4C34C0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3C60
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3DB0
#define EQ_Character__GetHPRegen_x                                 0x4E0950
#define EQ_Character__GetEnduranceRegen_x                          0x4E0F50
#define EQ_Character__GetManaRegen_x                               0x4E1390
#define EQ_Character__Max_Endurance_x                              0x65BF50
#define EQ_Character__Max_HP_x                                     0x4D3260
#define EQ_Character__Max_Mana_x                                   0x65BD50
#define EQ_Character__doCombatAbility_x                            0x65E370
#define EQ_Character__UseSkill_x                                   0x4E3180
#define EQ_Character__GetConLevel_x                                0x654700
#define EQ_Character__IsExpansionFlag_x                            0x5B83A0
#define EQ_Character__TotalEffect_x                                0x4C7230
#define EQ_Character__GetPCSpellAffect_x                           0x4C4210
#define EQ_Character__SpellDuration_x                              0x4C3D40
#define EQ_Character__MySpellDuration_x                            0x4B2590
#define EQ_Character__GetAdjustedSkill_x                           0x4D61B0
#define EQ_Character__GetBaseSkill_x                               0x4D7150
#define EQ_Character__CanUseItem_x                                 0x4DAE50

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8DC910

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6722F0

//PcClient
#define PcClient__vftable_x                                        0xB18F78
#define PcClient__PcClient_x                                       0x651E70

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BAE60
#define CCharacterListWnd__EnterWorld_x                            0x4BA840
#define CCharacterListWnd__Quit_x                                  0x4BA590
#define CCharacterListWnd__UpdateList_x                            0x4BAA30

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6366C0
#define EQ_Item__CreateItemTagString_x                             0x8B6B50
#define EQ_Item__IsStackable_x                                     0x8BB7D0
#define EQ_Item__GetImageNum_x                                     0x8B86A0
#define EQ_Item__CreateItemClient_x                                0x6358F0
#define EQ_Item__GetItemValue_x                                    0x8B99C0
#define EQ_Item__ValueSellMerchant_x                               0x8BD160
#define EQ_Item__IsKeyRingItem_x                                   0x8BB0F0
#define EQ_Item__CanGoInBag_x                                      0x6367E0
#define EQ_Item__IsEmpty_x                                         0x8BAC30
#define EQ_Item__GetMaxItemCount_x                                 0x8B9DD0
#define EQ_Item__GetHeldItem_x                                     0x8B8570
#define EQ_Item__GetAugmentFitBySlot_x                             0x8B64A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x563710
#define EQ_LoadingS__Array_x                                       0xC3DC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65C890
#define EQ_PC__GetAlternateAbilityId_x                             0x8C65E0
#define EQ_PC__GetCombatAbility_x                                  0x8C6C50
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C6CC0
#define EQ_PC__GetItemRecastTimer_x                                0x65E8F0
#define EQ_PC__HasLoreItem_x                                       0x654EC0
#define EQ_PC__AlertInventoryChanged_x                             0x654040
#define EQ_PC__GetPcZoneClient_x                                   0x6812B0
#define EQ_PC__RemoveMyAffect_x                                    0x661B20
#define EQ_PC__GetKeyRingItems_x                                   0x8C7550
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C72E0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C7850

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BE840
#define EQItemList__add_object_x                                   0x5EBE20
#define EQItemList__add_item_x                                     0x5BEDA0
#define EQItemList__delete_item_x                                  0x5BEDF0
#define EQItemList__FreeItemList_x                                 0x5BECF0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5417D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x673B70
#define EQPlayer__dEQPlayer_x                                      0x667020
#define EQPlayer__DoAttack_x                                       0x67BA50
#define EQPlayer__EQPlayer_x                                       0x6676E0
#define EQPlayer__SetNameSpriteState_x                             0x66B970
#define EQPlayer__SetNameSpriteTint_x                              0x66C850
#define PlayerBase__HasProperty_j_x                                0x9ADBF0
#define EQPlayer__IsTargetable_x                                   0x9AE090
#define EQPlayer__CanSee_x                                         0x9ADEF0
#define EQPlayer__CanSee1_x                                        0x9ADFC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9ADCB0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67ED50
#define PlayerZoneClient__GetLevel_x                               0x6812F0
#define PlayerZoneClient__IsValidTeleport_x                        0x5ECF90
#define PlayerZoneClient__LegalPlayerRace_x                        0x55C4F0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x676960
#define EQPlayerManager__GetSpawnByName_x                          0x676A10
#define EQPlayerManager__GetPlayerFromPartialName_x                0x676AA0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x639E90
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x639F10
#define KeypressHandler__AttachKeyToEqCommand_x                    0x639F50
#define KeypressHandler__ClearCommandStateArray_x                  0x63B360
#define KeypressHandler__HandleKeyDown_x                           0x63B380
#define KeypressHandler__HandleKeyUp_x                             0x63B420
#define KeypressHandler__SaveKeymapping_x                          0x63B870

// MapViewMap 
#define MapViewMap__Clear_x                                        0x792100
#define MapViewMap__SaveEx_x                                       0x7954C0
#define MapViewMap__SetZoom_x                                      0x799B80

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8DA890

// StringTable 
#define StringTable__getString_x                                   0x8D57C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x661790
#define PcZoneClient__RemovePetEffect_x                            0x661DC0
#define PcZoneClient__HasAlternateAbility_x                        0x65BB80
#define PcZoneClient__GetCurrentMod_x                              0x4E6230
#define PcZoneClient__GetModCap_x                                  0x4E6130
#define PcZoneClient__CanEquipItem_x                               0x65C230
#define PcZoneClient__GetItemByID_x                                0x65ED60
#define PcZoneClient__GetItemByItemClass_x                         0x65EEB0
#define PcZoneClient__RemoveBuffEffect_x                           0x661DE0
#define PcZoneClient__BandolierSwap_x                              0x65CE40
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65E890

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F1A40

//IconCache
#define IconCache__GetIcon_x                                       0x733770

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x72B2E0
#define CContainerMgr__CloseContainer_x                            0x72B5B0
#define CContainerMgr__OpenExperimentContainer_x                   0x72C030

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7EA830

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62E8A0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x788660
#define CLootWnd__RequestLootSlot_x                                0x787940

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58A310
#define EQ_Spell__SpellAffects_x                                   0x58A780
#define EQ_Spell__SpellAffectBase_x                                0x58A540
#define EQ_Spell__IsStackable_x                                    0x4CAE90
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CACB0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B8130
#define EQ_Spell__IsSPAStacking_x                                  0x58B5D0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58AAE0
#define EQ_Spell__IsNoRemove_x                                     0x4CAE70
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58B5E0
#define __IsResEffectSpell_x                                       0x4CA140

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD930

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8E4E90

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x831A70
#define CTargetWnd__WndNotification_x                              0x8312B0
#define CTargetWnd__RefreshTargetBuffs_x                           0x831580
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x830420

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8360A0
#define CTaskWnd__ConfirmAbandonTask_x                             0x838CD0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53F220
#define CTaskManager__HandleMessage_x                              0x53D6C0
#define CTaskManager__GetTaskStatus_x                              0x53F2D0
#define CTaskManager__GetElementDescription_x                      0x53F350

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x585480
#define EqSoundManager__PlayScriptMp3_x                            0x585740
#define EqSoundManager__SoundAssistPlay_x                          0x699890
#define EqSoundManager__WaveInstancePlay_x                         0x698E00

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x530790

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x969A10
#define CTextureAnimation__Draw_x                                  0x969C10

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x965B40

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56B210
#define CAltAbilityData__GetMercMaxRank_x                          0x56B1A0
#define CAltAbilityData__GetMaxRank_x                              0x560630

//CTargetRing
#define CTargetRing__Cast_x                                        0x62C9C0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CAC90
#define CharacterBase__CreateItemGlobalIndex_x                     0x517610
#define CharacterBase__CreateItemIndex_x                           0x634AA0
#define CharacterBase__GetItemPossession_x                         0x503230
#define CharacterBase__GetItemByGlobalIndex_x                      0x8ED510
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8ED570
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x712290
#define CCastSpellWnd__IsBardSongPlaying_x                         0x712AC0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x712B70

//messages
#define msg_spell_worn_off_x                                       0x5B03A0
#define msg_new_text_x                                             0x5A4D90
#define __msgTokenTextParam_x                                      0x5B2640
#define msgTokenText_x                                             0x5B2890

//SpellManager
#define SpellManager__vftable_x                                    0xB0130C
#define SpellManager__SpellManager_x                               0x69CBB0
#define Spellmanager__LoadTextSpells_x                             0x69D4A0
#define SpellManager__GetSpellByGroupAndRank_x                     0x69CD80

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9B1B90

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x517C60
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B6820
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64D610
#define ItemGlobalIndex__IsValidIndex_x                            0x517CC0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8E5830
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8E5AB0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x780F00

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72F990
#define CCursorAttachment__AttachToCursor1_x                       0x72F9D0
#define CCursorAttachment__Deactivate_x                            0x7309B0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x95C7F0
#define CSidlManagerBase__CreatePageWnd_x                          0x95BFF0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x958280
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x958210

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x979C00
#define CEQSuiteTextureLoader__GetTexture_x                        0x9798C0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x514BB0
#define CFindItemWnd__WndNotification_x                            0x515690
#define CFindItemWnd__Update_x                                     0x516200
#define CFindItemWnd__PickupSelectedItem_x                         0x5143F0

//IString
#define IString__Append_x                                          0x504B50

//Camera
#define CDisplay__cameraType_x                                     0xE17380
#define EverQuest__Cameras_x                                       0xED260C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51D3E0
#define LootFiltersManager__GetItemFilterData_x                    0x51CCE0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51CD10
#define LootFiltersManager__SetItemLootFilter_x                    0x51CF30

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D8670

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B7710
#define CResolutionHandler__GetWindowedStyle_x                     0x694240

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x727F90

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8FAF30
#define CDistillerInfo__Instance_x                                 0x8FAED0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x746F60
#define CGroupWnd__UpdateDisplay_x                                 0x7462C0

//ItemBase
#define ItemBase__IsLore_x                                         0x8BB1A0
#define ItemBase__IsLoreEquipped_x                                 0x8BB210

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EBD80
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EBEC0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EBF20

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6899A0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68D310

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50AFD0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F7360
#define FactionManagerClient__HandleFactionMessage_x               0x4F79D0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F7F90
#define FactionManagerClient__GetMaxFaction_x                      0x4F7FAF
#define FactionManagerClient__GetMinFaction_x                      0x4F7F60

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x503200

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x940FD0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C760

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x503560

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56A6A0

//CTargetManager
#define CTargetManager__Get_x                                      0x6A0400

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6899A0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A94C0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BEC90

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF6FCA0

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6DBB80
#define CAAWnd__UpdateSelected_x                                   0x6D8400
#define CAAWnd__Update_x                                           0x6DAEB0

//CXRect
#define CXRect__operator_and_x                                     0x73E060

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4835B0

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
