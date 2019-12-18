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
#define __ExpectedVersionDate                                     "Dec 17 2019"
#define __ExpectedVersionTime                                     "04:24:11"
#define __ActualVersionDate_x                                      0xB0C640
#define __ActualVersionTime_x                                      0xB0C634
#define __ActualVersionBuild_x                                     0xAF8314

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x631C10
#define __MemChecker1_x                                            0x904530
#define __MemChecker2_x                                            0x6C0570
#define __MemChecker3_x                                            0x6C04C0
#define __MemChecker4_x                                            0x85AF70
#define __EncryptPad0_x                                            0xC433E8
#define __EncryptPad1_x                                            0xCA1650
#define __EncryptPad2_x                                            0xC53C80
#define __EncryptPad3_x                                            0xC53880
#define __EncryptPad4_x                                            0xC91C00
#define __EncryptPad5_x                                            0xF6DE08
#define __AC1_x                                                    0x8177E6
#define __AC2_x                                                    0x5EBB3F
#define __AC3_x                                                    0x5F323F
#define __AC4_x                                                    0x5F7210
#define __AC5_x                                                    0x5FD51F
#define __AC6_x                                                    0x601B36
#define __AC7_x                                                    0x5EB5B0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x19138C

// Direct Input
#define DI8__Main_x                                                0xF6DE30
#define DI8__Keyboard_x                                            0xF6DE34
#define DI8__Mouse_x                                               0xF6DE14
#define DI8__Mouse_Copy_x                                          0xEC6564
#define DI8__Mouse_Check_x                                         0xF6B95C
#define __AutoSkillArray_x                                         0xEC747C
#define __Attack_x                                                 0xF652A3
#define __Autofire_x                                               0xF652A4
#define __BindList_x                                               0xC31E20
#define g_eqCommandStates_x                                        0xC32BA0
#define __Clicks_x                                                 0xEC661C
#define __CommandList_x                                            0xC33760
#define __CurrentMapLabel_x                                        0xF7DD44
#define __CurrentSocial_x                                          0xC1B7C0
#define __DoAbilityList_x                                          0xEFCDC4
#define __do_loot_x                                                0x5B7600
#define __DrawHandler_x                                            0x15FD0C0
#define __GroupCount_x                                             0xEB681A
#define __Guilds_x                                                 0xEBCD70
#define __gWorld_x                                                 0xEB6F60
#define __HWnd_x                                                   0xF6DE18
#define __heqmain_x                                                0xF6DDF0
#define __InChatMode_x                                             0xEC654C
#define __LastTell_x                                               0xEC84C0
#define __LMouseHeldTime_x                                         0xEC6688
#define __Mouse_x                                                  0xF6DE1C
#define __MouseLook_x                                              0xEC65E2
#define __MouseEventTime_x                                         0xF65D84
#define __gpbCommandEvent_x                                        0xEB6A18
#define __NetStatusToggle_x                                        0xEC65E5
#define __PCNames_x                                                0xEC7A6C
#define __RangeAttackReady_x                                       0xEC7760
#define __RMouseHeldTime_x                                         0xEC6684
#define __RunWalkState_x                                           0xEC6550
#define __ScreenMode_x                                             0xE04278
#define __ScreenX_x                                                0xEC6504
#define __ScreenY_x                                                0xEC6500
#define __ScreenXMax_x                                             0xEC6508
#define __ScreenYMax_x                                             0xEC650C
#define __ServerHost_x                                             0xEB6C4B
#define __ServerName_x                                             0xEFCD84
#define __ShiftKeyDown_x                                           0xEC6BDC
#define __ShowNames_x                                              0xEC791C
#define __Socials_x                                                0xEFCE84
#define __SubscriptionType_x                                       0xFC2250
#define __TargetAggroHolder_x                                      0xF806F8
#define __ZoneType_x                                               0xEC69E0
#define __GroupAggro_x                                             0xF80738
#define __LoginName_x                                              0xF6B5EC
#define __Inviter_x                                                0xF65220
#define __AttackOnAssist_x                                         0xEC78D8
#define __UseTellWindows_x                                         0xEC7C08
#define __gfMaxZoomCameraDistance_x                                0xB01FA0
#define __gfMaxCameraDistance_x                                    0xB2E34C
#define __pulAutoRun_x                                             0xEC6600
#define __pulForward_x                                             0xEC7C40
#define __pulBackward_x                                            0xEC7C44
#define __pulTurnRight_x                                           0xEC7C48
#define __pulTurnLeft_x                                            0xEC7C4C
#define __pulStrafeLeft_x                                          0xEC7C50
#define __pulStrafeRight_x                                         0xEC7C54

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB9108
#define instEQZoneInfo_x                                           0xEC67D8
#define pinstActiveBanker_x                                        0xEB6A30
#define pinstActiveCorpse_x                                        0xEB6A28
#define pinstActiveGMaster_x                                       0xEB6A2C
#define pinstActiveMerchant_x                                      0xEB6A24
#define pinstAltAdvManager_x                                       0xE05340
#define pinstBandageTarget_x                                       0xEB6A40
#define pinstCamActor_x                                            0xE0426C
#define pinstCDBStr_x                                              0xE0405C
#define pinstCDisplay_x                                            0xEB8FDC
#define pinstCEverQuest_x                                          0xF6AEB0
#define pinstEverQuestInfo_x                                       0xEC64F8
#define pinstCharData_x                                            0xEB67FC
#define pinstCharSpawn_x                                           0xEB6A78
#define pinstControlledMissile_x                                   0xEB6F5C
#define pinstControlledPlayer_x                                    0xEB6A78
#define pinstCResolutionHandler_x                                  0x15FD2F0
#define pinstCSidlManager_x                                        0x15FC288
#define pinstCXWndManager_x                                        0x15FC284
#define instDynamicZone_x                                          0xEBCC48
#define pinstDZMember_x                                            0xEBCD58
#define pinstDZTimerInfo_x                                         0xEBCD5C
#define pinstEqLogin_x                                             0xF6AF38
#define instEQMisc_x                                               0xE03FA0
#define pinstEQSoundManager_x                                      0xE06310
#define pinstEQSpellStrings_x                                      0xCC69B8
#define instExpeditionLeader_x                                     0xEBCC92
#define instExpeditionName_x                                       0xEBCCD2
#define pinstGroup_x                                               0xEB6816
#define pinstImeManager_x                                          0x15FC280
#define pinstLocalPlayer_x                                         0xEB6A20
#define pinstMercenaryData_x                                       0xF67878
#define pinstMercenaryStats_x                                      0xF80844
#define pinstModelPlayer_x                                         0xEB6A38
#define pinstPCData_x                                              0xEB67FC
#define pinstSkillMgr_x                                            0xF699E0
#define pinstSpawnManager_x                                        0xF68488
#define pinstSpellManager_x                                        0xF69C20
#define pinstSpellSets_x                                           0xF5DECC
#define pinstStringTable_x                                         0xEB6800
#define pinstSwitchManager_x                                       0xEB66A8
#define pinstTarget_x                                              0xEB6A74
#define pinstTargetObject_x                                        0xEB6B00
#define pinstTargetSwitch_x                                        0xEB6F7C
#define pinstTaskMember_x                                          0xE03E30
#define pinstTrackTarget_x                                         0xEB6A7C
#define pinstTradeTarget_x                                         0xEB6A34
#define instTributeActive_x                                        0xE03FC1
#define pinstViewActor_x                                           0xE04268
#define pinstWorldData_x                                           0xEB6A0C
#define pinstZoneAddr_x                                            0xEC6A78
#define pinstPlayerPath_x                                          0xF68520
#define pinstTargetIndicator_x                                     0xF69E88
#define EQObject_Top_x                                             0xEB6A1C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE0411C
#define pinstCAchievementsWnd_x                                    0xE04118
#define pinstCActionsWnd_x                                         0xE04778
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE041F0
#define pinstCAdvancedLootWnd_x                                    0xE041AC
#define pinstCAdventureLeaderboardWnd_x                            0xF77518
#define pinstCAdventureRequestWnd_x                                0xF775C8
#define pinstCAdventureStatsWnd_x                                  0xF77678
#define pinstCAggroMeterWnd_x                                      0xE04710
#define pinstCAlarmWnd_x                                           0xE0417C
#define pinstCAlertHistoryWnd_x                                    0xE04210
#define pinstCAlertStackWnd_x                                      0xE04184
#define pinstCAlertWnd_x                                           0xE04194
#define pinstCAltStorageWnd_x                                      0xF779D8
#define pinstCAudioTriggersWindow_x                                0xCB8CE8
#define pinstCAuraWnd_x                                            0xE04234
#define pinstCAvaZoneWnd_x                                         0xE041C8
#define pinstCBandolierWnd_x                                       0xE042A4
#define pinstCBankWnd_x                                            0xE04230
#define pinstCBarterMerchantWnd_x                                  0xF78C18
#define pinstCBarterSearchWnd_x                                    0xF78CC8
#define pinstCBarterWnd_x                                          0xF78D78
#define pinstCBazaarConfirmationWnd_x                              0xE04148
#define pinstCBazaarSearchWnd_x                                    0xE04758
#define pinstCBazaarWnd_x                                          0xE04160
#define pinstCBlockedBuffWnd_x                                     0xE04238
#define pinstCBlockedPetBuffWnd_x                                  0xE04290
#define pinstCBodyTintWnd_x                                        0xE04990
#define pinstCBookWnd_x                                            0xE04734
#define pinstCBreathWnd_x                                          0xE04130
#define pinstCBuffWindowNORMAL_x                                   0xE04214
#define pinstCBuffWindowSHORT_x                                    0xE04218
#define pinstCBugReportWnd_x                                       0xE04224
#define pinstCButtonWnd_x                                          0x15FC4F0
#define pinstCCastingWnd_x                                         0xE04728
#define pinstCCastSpellWnd_x                                       0xE04128
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE04178
#define pinstCChatWindowManager_x                                  0xF79838
#define pinstCClaimWnd_x                                           0xF79990
#define pinstCColorPickerWnd_x                                     0xE04784
#define pinstCCombatAbilityWnd_x                                   0xE04170
#define pinstCCombatSkillsSelectWnd_x                              0xE04198
#define pinstCCompassWnd_x                                         0xE04780
#define pinstCConfirmationDialog_x                                 0xF7E890
#define pinstCContainerMgr_x                                       0xE0416C
#define pinstCContextMenuManager_x                                 0x15FC240
#define pinstCCursorAttachment_x                                   0xE0471C
#define pinstCDynamicZoneWnd_x                                     0xF79F58
#define pinstCEditLabelWnd_x                                       0xE0420C
#define pinstCEQMainWnd_x                                          0xF7A1A0
#define pinstCEventCalendarWnd_x                                   0xE04720
#define pinstCExtendedTargetWnd_x                                  0xE04284
#define pinstCFacePick_x                                           0xE041B0
#define pinstCFactionWnd_x                                         0xE04158
#define pinstCFellowshipWnd_x                                      0xF7A3A0
#define pinstCFileSelectionWnd_x                                   0xE04724
#define pinstCFindItemWnd_x                                        0xE04144
#define pinstCFindLocationWnd_x                                    0xF7A4F8
#define pinstCFriendsWnd_x                                         0xE041A8
#define pinstCGemsGameWnd_x                                        0xE04154
#define pinstCGiveWnd_x                                            0xE04180
#define pinstCGroupSearchFiltersWnd_x                              0xE0472C
#define pinstCGroupSearchWnd_x                                     0xF7A8F0
#define pinstCGroupWnd_x                                           0xF7A9A0
#define pinstCGuildBankWnd_x                                       0xEC78BC
#define pinstCGuildCreationWnd_x                                   0xF7AB00
#define pinstCGuildMgmtWnd_x                                       0xF7ABB0
#define pinstCharacterCreation_x                                   0xE041A0
#define pinstCHelpWnd_x                                            0xE041E4
#define pinstCHeritageSelectionWnd_x                               0xE041C0
#define pinstCHotButtonWnd_x                                       0xF7CD08
#define pinstCHotButtonWnd1_x                                      0xF7CD08
#define pinstCHotButtonWnd2_x                                      0xF7CD0C
#define pinstCHotButtonWnd3_x                                      0xF7CD10
#define pinstCHotButtonWnd4_x                                      0xF7CD14
#define pinstCIconSelectionWnd_x                                   0xE04718
#define pinstCInspectWnd_x                                         0xE041E0
#define pinstCInventoryWnd_x                                       0xE041B4
#define pinstCInvSlotMgr_x                                         0xE0412C
#define pinstCItemDisplayManager_x                                 0xF7D298
#define pinstCItemExpTransferWnd_x                                 0xF7D3C8
#define pinstCItemOverflowWnd_x                                    0xE0475C
#define pinstCJournalCatWnd_x                                      0xE04738
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE04288
#define pinstCKeyRingWnd_x                                         0xE04200
#define pinstCLargeDialogWnd_x                                     0xF7F510
#define pinstCLayoutCopyWnd_x                                      0xF7D718
#define pinstCLFGuildWnd_x                                         0xF7D7C8
#define pinstCLoadskinWnd_x                                        0xE0415C
#define pinstCLootFiltersCopyWnd_x                                 0xCD5338
#define pinstCLootFiltersWnd_x                                     0xE04188
#define pinstCLootSettingsWnd_x                                    0xE041A4
#define pinstCLootWnd_x                                            0xE0473C
#define pinstCMailAddressBookWnd_x                                 0xE04134
#define pinstCMailCompositionWnd_x                                 0xE04110
#define pinstCMailIgnoreListWnd_x                                  0xE04138
#define pinstCMailWnd_x                                            0xE04988
#define pinstCManageLootWnd_x                                      0xE057F0
#define pinstCMapToolbarWnd_x                                      0xE041EC
#define pinstCMapViewWnd_x                                         0xE041C4
#define pinstCMarketplaceWnd_x                                     0xE0418C
#define pinstCMerchantWnd_x                                        0xE04740
#define pinstCMIZoneSelectWnd_x                                    0xF7E000
#define pinstCMusicPlayerWnd_x                                     0xE04748
#define pinstCNameChangeMercWnd_x                                  0xE04140
#define pinstCNameChangePetWnd_x                                   0xE04120
#define pinstCNameChangeWnd_x                                      0xE04150
#define pinstCNoteWnd_x                                            0xE041CC
#define pinstCObjectPreviewWnd_x                                   0xE0419C
#define pinstCOptionsWnd_x                                         0xE041D0
#define pinstCPetInfoWnd_x                                         0xE04760
#define pinstCPetitionQWnd_x                                       0xE04108
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE040F8
#define pinstCPlayerWnd_x                                          0xE0476C
#define pinstCPopupWndManager_x                                    0xF7E890
#define pinstCProgressionSelectionWnd_x                            0xF7E940
#define pinstCPurchaseGroupWnd_x                                   0xE041D8
#define pinstCPurchaseWnd_x                                        0xE041B8
#define pinstCPvPLeaderboardWnd_x                                  0xF7E9F0
#define pinstCPvPStatsWnd_x                                        0xF7EAA0
#define pinstCQuantityWnd_x                                        0xE0428C
#define pinstCRaceChangeWnd_x                                      0xE04174
#define pinstCRaidOptionsWnd_x                                     0xE04730
#define pinstCRaidWnd_x                                            0xE04104
#define pinstCRealEstateItemsWnd_x                                 0xE04114
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE04744
#define pinstCRealEstateManageWnd_x                                0xE041E8
#define pinstCRealEstateNeighborhoodWnd_x                          0xE04204
#define pinstCRealEstatePlotSearchWnd_x                            0xE04228
#define pinstCRealEstatePurchaseWnd_x                              0xE04264
#define pinstCRespawnWnd_x                                         0xE04260
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE04124
#define pinstCSendMoneyWnd_x                                       0xE04190
#define pinstCServerListWnd_x                                      0xE0430C
#define pinstCSkillsSelectWnd_x                                    0xE04164
#define pinstCSkillsWnd_x                                          0xE0414C
#define pinstCSocialEditWnd_x                                      0xE041F8
#define pinstCSocialWnd_x                                          0xE0413C
#define pinstCSpellBookWnd_x                                       0xE04168
#define pinstCStoryWnd_x                                           0xE04768
#define pinstCTargetOfTargetWnd_x                                  0xF808C8
#define pinstCTargetWnd_x                                          0xE0425C
#define pinstCTaskOverlayWnd_x                                     0xE041D4
#define pinstCTaskSelectWnd_x                                      0xF80A20
#define pinstCTaskManager_x                                        0xCD5C78
#define pinstCTaskTemplateSelectWnd_x                              0xF80AD0
#define pinstCTaskWnd_x                                            0xF80B80
#define pinstCTextEntryWnd_x                                       0xE0421C
#define pinstCTimeLeftWnd_x                                        0xE04770
#define pinstCTipWndCONTEXT_x                                      0xF80D84
#define pinstCTipWndOFDAY_x                                        0xF80D80
#define pinstCTitleWnd_x                                           0xF80E30
#define pinstCTrackingWnd_x                                        0xE041BC
#define pinstCTradeskillWnd_x                                      0xF80F98
#define pinstCTradeWnd_x                                           0xE04100
#define pinstCTrainWnd_x                                           0xE040FC
#define pinstCTributeBenefitWnd_x                                  0xF81198
#define pinstCTributeMasterWnd_x                                   0xF81248
#define pinstCTributeTrophyWnd_x                                   0xF812F8
#define pinstCVideoModesWnd_x                                      0xE04774
#define pinstCVoiceMacroWnd_x                                      0xF6A5F0
#define pinstCVoteResultsWnd_x                                     0xE0410C
#define pinstCVoteWnd_x                                            0xE0498C
#define pinstCWebManager_x                                         0xF6AC6C
#define pinstCZoneGuideWnd_x                                       0xE041DC
#define pinstCZonePathWnd_x                                        0xE041F4

#define pinstEQSuiteTextureLoader_x                                0xCA3128
#define pinstItemIconCache_x                                       0xF7A158
#define pinstLootFiltersManager_x                                  0xCD53E8
#define pinstRewardSelectionWnd_x                                  0xF7F1E8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5B2A60
#define __CastRay2_x                                               0x5B2AB0
#define __ConvertItemTags_x                                        0x5CE5F0
#define __CleanItemTags_x                                          0x47CFF0
#define __DoesFileExist_x                                          0x9075D0
#define __EQGetTime_x                                              0x904000
#define __ExecuteCmd_x                                             0x5AB2F0
#define __FixHeading_x                                             0x99F1E0
#define __GameLoop_x                                               0x6BF760
#define __get_bearing_x                                            0x5B25D0
#define __get_melee_range_x                                        0x5B2CA0
#define __GetAnimationCache_x                                      0x724B90
#define __GetGaugeValueFromEQ_x                                    0x815C90
#define __GetLabelFromEQ_x                                         0x817770
#define __GetXTargetType_x                                         0x9A0BC0
#define __HandleMouseWheel_x                                       0x6C0620
#define __HeadingDiff_x                                            0x99F250
#define __HelpPath_x                                               0xF65974
#define __LoadFrontEnd_x                                           0x6BCA80
#define __NewUIINI_x                                               0x815960
#define __ProcessGameEvents_x                                      0x6132E0
#define __ProcessMouseEvent_x                                      0x612AA0
#define __SaveColors_x                                             0x553790
#define __STMLToText_x                                             0x942370
#define __ToggleKeyRingItem_x                                      0x516650
#define CMemoryMappedFile__SetFile_x                               0xA8E520
#define CrashDetected_x                                            0x6BE520
#define DrawNetStatus_x                                            0x63F1A0
#define Expansion_HoT_x                                            0xEC78C4
#define Teleport_Table_Size_x                                      0xEB6B08
#define Teleport_Table_x                                           0xEB6F80
#define Util__FastTime_x                                           0x903BD0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4901E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4990E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498EB0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493770
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492BC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x55B2A0
#define AltAdvManager__IsAbilityReady_x                            0x55A1D0
#define AltAdvManager__GetAAById_x                                 0x55A3D0
#define AltAdvManager__CanTrainAbility_x                           0x55A440
#define AltAdvManager__CanSeeAbility_x                             0x55A7A0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9FB0
#define CharacterZoneClient__HasSkill_x                            0x4D4EA0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D65C0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE260
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA860
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8F40
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9020
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9100
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3060
#define CharacterZoneClient__BardCastBard_x                        0x4C5BC0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA930
#define CharacterZoneClient__GetEffect_x                           0x4BA7A0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C40B0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4180
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C41D0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4320
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C44F0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2710
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7520
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6FA0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E62F0
#define CBankWnd__WndNotification_x                                0x6E60D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F3A00

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x6219F0
#define CButtonWnd__CButtonWnd_x                                   0x93E760

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x713D40
#define CChatManager__InitContextMenu_x                            0x70CE90
#define CChatManager__FreeChatWindow_x                             0x712880
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E85D0
#define CChatManager__SetLockedActiveChatWindow_x                  0x7139C0
#define CChatManager__CreateChatWindow_x                           0x712EC0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E86E0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x952DE0
#define CContextMenu__dCContextMenu_x                              0x953020
#define CContextMenu__AddMenuItem_x                                0x953030
#define CContextMenu__RemoveMenuItem_x                             0x953340
#define CContextMenu__RemoveAllMenuItems_x                         0x953360
#define CContextMenu__CheckMenuItem_x                              0x9533E0
#define CContextMenu__SetMenuItem_x                                0x953260
#define CContextMenu__AddSeparator_x                               0x9531C0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x953980
#define CContextMenuManager__RemoveMenu_x                          0x9539F0
#define CContextMenuManager__PopupMenu_x                           0x953AB0
#define CContextMenuManager__Flush_x                               0x953920
#define CContextMenuManager__GetMenu_x                             0x49B270
#define CContextMenuManager__CreateDefaultMenu_x                   0x71F3A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DF4A0
#define CChatService__GetFriendName_x                              0x8DF4B0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7145B0
#define CChatWindow__Clear_x                                       0x715880
#define CChatWindow__WndNotification_x                             0x716010
#define CChatWindow__AddHistory_x                                  0x715140

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x950230
#define CComboWnd__Draw_x                                          0x94F720
#define CComboWnd__GetCurChoice_x                                  0x950070
#define CComboWnd__GetListRect_x                                   0x94FBD0
#define CComboWnd__GetTextRect_x                                   0x9502A0
#define CComboWnd__InsertChoice_x                                  0x94FD60
#define CComboWnd__SetColors_x                                     0x94FD30
#define CComboWnd__SetChoice_x                                     0x950040
#define CComboWnd__GetItemCount_x                                  0x950080
#define CComboWnd__GetCurChoiceText_x                              0x9500C0
#define CComboWnd__GetChoiceText_x                                 0x950090
#define CComboWnd__InsertChoiceAtIndex_x                           0x94FE00

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71CD90
#define CContainerWnd__vftable_x                                   0xB1583C
#define CContainerWnd__SetContainer_x                              0x71E2F0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54E1C0
#define CDisplay__PreZoneMainUI_x                                  0x54E1D0
#define CDisplay__CleanGameUI_x                                    0x553550
#define CDisplay__GetClickedActor_x                                0x5464E0
#define CDisplay__GetUserDefinedColor_x                            0x53EBA0
#define CDisplay__GetWorldFilePath_x                               0x547F50
#define CDisplay__is3dON_x                                         0x543140
#define CDisplay__ReloadUI_x                                       0x54D650
#define CDisplay__WriteTextHD2_x                                   0x542F30
#define CDisplay__TrueDistance_x                                   0x549C10
#define CDisplay__SetViewActor_x                                   0x545E00
#define CDisplay__GetFloorHeight_x                                 0x543200
#define CDisplay__SetRenderWindow_x                                0x541B60
#define CDisplay__ToggleScreenshotMode_x                           0x5458D0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x972D70

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x956360
#define CEditWnd__GetCharIndexPt_x                                 0x957290
#define CEditWnd__GetDisplayString_x                               0x957130
#define CEditWnd__GetHorzOffset_x                                  0x955990
#define CEditWnd__GetLineForPrintableChar_x                        0x958430
#define CEditWnd__GetSelStartPt_x                                  0x957540
#define CEditWnd__GetSTMLSafeText_x                                0x956F50
#define CEditWnd__PointFromPrintableChar_x                         0x958060
#define CEditWnd__SelectableCharFromPoint_x                        0x9581D0
#define CEditWnd__SetEditable_x                                    0x957610
#define CEditWnd__SetWindowTextA_x                                 0x956CD0
#define CEditWnd__ReplaceSelection_x                               0x957CD0
#define CEditWnd__ReplaceSelection1_x                              0x957C50

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x601010
#define CEverQuest__ClickedPlayer_x                                0x5F3020
#define CEverQuest__CreateTargetIndicator_x                        0x610580
#define CEverQuest__DeleteTargetIndicator_x                        0x610610
#define CEverQuest__DoTellWindow_x                                 0x4E87C0
#define CEverQuest__OutputTextToLog_x                              0x4E8A90
#define CEverQuest__DropHeldItemOnGround_x                         0x5E8060
#define CEverQuest__dsp_chat_x                                     0x4E8E20
#define CEverQuest__trimName_x                                     0x60C870
#define CEverQuest__Emote_x                                        0x601870
#define CEverQuest__EnterZone_x                                    0x5FB7F0
#define CEverQuest__GetBodyTypeDesc_x                              0x606130
#define CEverQuest__GetClassDesc_x                                 0x606770
#define CEverQuest__GetClassThreeLetterCode_x                      0x606D70
#define CEverQuest__GetDeityDesc_x                                 0x60EEC0
#define CEverQuest__GetLangDesc_x                                  0x606F30
#define CEverQuest__GetRaceDesc_x                                  0x606750
#define CEverQuest__InterpretCmd_x                                 0x60F490
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EC260
#define CEverQuest__LMouseUp_x                                     0x5EA5F0
#define CEverQuest__RightClickedOnPlayer_x                         0x5ECB40
#define CEverQuest__RMouseUp_x                                     0x5EB570
#define CEverQuest__SetGameState_x                                 0x5E7DF0
#define CEverQuest__UPCNotificationFlush_x                         0x60C770
#define CEverQuest__IssuePetCommand_x                              0x608330
#define CEverQuest__ReportSuccessfulHit_x                          0x602BC0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72EC20
#define CGaugeWnd__CalcLinesFillRect_x                             0x72EC80
#define CGaugeWnd__Draw_x                                          0x72E2A0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF220
#define CGuild__GetGuildName_x                                     0x4AE300
#define CGuild__GetGuildIndex_x                                    0x4AE690

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x748E30

//CHotButton
#define CHotButton__SetButtonSize_x                                0x621DB0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x755E10
#define CInvSlotMgr__MoveItem_x                                    0x754B70
#define CInvSlotMgr__SelectSlot_x                                  0x755EE0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7533B0
#define CInvSlot__SliderComplete_x                                 0x751110
#define CInvSlot__GetItemBase_x                                    0x750AA0
#define CInvSlot__UpdateItem_x                                     0x750C10

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x757950
#define CInvSlotWnd__CInvSlotWnd_x                                 0x756AE0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7574D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x811010
#define CItemDisplayWnd__UpdateStrings_x                           0x765FA0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75FD20
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x760220
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7665A0
#define CItemDisplayWnd__AboutToShow_x                             0x765C00
#define CItemDisplayWnd__WndNotification_x                         0x767670
#define CItemDisplayWnd__RequestConvertItem_x                      0x767140
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x764C70
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x765A20

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x849B80

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76BB60

// CLabel 
#define CLabel__Draw_x                                             0x771530

// CListWnd
#define CListWnd__CListWnd_x                                       0x928860
#define CListWnd__dCListWnd_x                                      0x928B80
#define CListWnd__AddColumn_x                                      0x92D010
#define CListWnd__AddColumn1_x                                     0x92D060
#define CListWnd__AddLine_x                                        0x92D3F0
#define CListWnd__AddString_x                                      0x92D1F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x92CDD0
#define CListWnd__CalculateVSBRange_x                              0x92CBB0
#define CListWnd__ClearSel_x                                       0x92DBD0
#define CListWnd__ClearAllSel_x                                    0x92DC30
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92E650
#define CListWnd__Compare_x                                        0x92C4E0
#define CListWnd__Draw_x                                           0x928CB0
#define CListWnd__DrawColumnSeparators_x                           0x92B4B0
#define CListWnd__DrawHeader_x                                     0x92B920
#define CListWnd__DrawItem_x                                       0x92BE20
#define CListWnd__DrawLine_x                                       0x92B620
#define CListWnd__DrawSeparator_x                                  0x92B550
#define CListWnd__EnableLine_x                                     0x92AD80
#define CListWnd__EnsureVisible_x                                  0x92E570
#define CListWnd__ExtendSel_x                                      0x92DB00
#define CListWnd__GetColumnTooltip_x                               0x92A8C0
#define CListWnd__GetColumnMinWidth_x                              0x92A930
#define CListWnd__GetColumnWidth_x                                 0x92A830
#define CListWnd__GetCurSel_x                                      0x92A1C0
#define CListWnd__GetItemAtPoint_x                                 0x92B000
#define CListWnd__GetItemAtPoint1_x                                0x92B070
#define CListWnd__GetItemData_x                                    0x92A240
#define CListWnd__GetItemHeight_x                                  0x92A600
#define CListWnd__GetItemIcon_x                                    0x92A3D0
#define CListWnd__GetItemRect_x                                    0x92AE70
#define CListWnd__GetItemText_x                                    0x92A280
#define CListWnd__GetSelList_x                                     0x92DC80
#define CListWnd__GetSeparatorRect_x                               0x92B2B0
#define CListWnd__InsertLine_x                                     0x92D7E0
#define CListWnd__RemoveLine_x                                     0x92D930
#define CListWnd__SetColors_x                                      0x92CB80
#define CListWnd__SetColumnJustification_x                         0x92C8B0
#define CListWnd__SetColumnWidth_x                                 0x92C7D0
#define CListWnd__SetCurSel_x                                      0x92DA40
#define CListWnd__SetItemColor_x                                   0x92E220
#define CListWnd__SetItemData_x                                    0x92E1E0
#define CListWnd__SetItemText_x                                    0x92DDF0
#define CListWnd__ShiftColumnSeparator_x                           0x92C970
#define CListWnd__Sort_x                                           0x92C660
#define CListWnd__ToggleSel_x                                      0x92DA70
#define CListWnd__SetColumnsSizable_x                              0x92CA20
#define CListWnd__SetItemWnd_x                                     0x92E0A0
#define CListWnd__GetItemWnd_x                                     0x92A420
#define CListWnd__SetItemIcon_x                                    0x92DE70
#define CListWnd__CalculateCustomWindowPositions_x                 0x92CED0
#define CListWnd__SetVScrollPos_x                                  0x92C7B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x786CD0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7853E0
#define CMapViewWnd__HandleLButtonDown_x                           0x782420

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A6D00
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A75E0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A7B00
#define CMerchantWnd__SelectRecoverySlot_x                         0x7AAA70
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A5870
#define CMerchantWnd__SelectBuySellSlot_x                          0x7B0620
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A6920

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8ACFA0
#define CPacketScrambler__hton_x                                   0x8ACF90

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9479E0
#define CSidlManager__FindScreenPieceTemplate_x                    0x947DF0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x947BE0
#define CSidlManager__CreateLabel_x                                0x8084D0
#define CSidlManager__CreateXWndFromTemplate_x                     0x94AD50
#define CSidlManager__CreateXWndFromTemplate1_x                    0x94AF30
#define CSidlManager__CreateXWnd_x                                 0x808400
#define CSidlManager__CreateHotButtonWnd_x                         0x8089C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9444A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9443A0
#define CSidlScreenWnd__ConvertToRes_x                             0x969D50
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x943E30
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x943B20
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x943BF0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x943CC0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x944940
#define CSidlScreenWnd__EnableIniStorage_x                         0x944E10
#define CSidlScreenWnd__GetSidlPiece_x                             0x944B30
#define CSidlScreenWnd__Init1_x                                    0x943720
#define CSidlScreenWnd__LoadIniInfo_x                              0x944E60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9459C0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x942B20
#define CSidlScreenWnd__StoreIniInfo_x                             0x945530
#define CSidlScreenWnd__StoreIniVis_x                              0x9458A0
#define CSidlScreenWnd__WndNotification_x                          0x944850
#define CSidlScreenWnd__GetChildItem_x                             0x944D90
#define CSidlScreenWnd__HandleLButtonUp_x                          0x934420
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FC110

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x686B80
#define CSkillMgr__GetSkillCap_x                                   0x686D60
#define CSkillMgr__GetNameToken_x                                  0x686300
#define CSkillMgr__IsActivatedSkill_x                              0x686440
#define CSkillMgr__IsCombatSkill_x                                 0x686380

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x954770
#define CSliderWnd__SetValue_x                                     0x9545E0
#define CSliderWnd__SetNumTicks_x                                  0x954640

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80E490

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95CF90
#define CStmlWnd__CalculateHSBRange_x                              0x95E0B0
#define CStmlWnd__CalculateVSBRange_x                              0x95E030
#define CStmlWnd__CanBreakAtCharacter_x                            0x9623F0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x963080
#define CStmlWnd__ForceParseNow_x                                  0x95D580
#define CStmlWnd__GetNextTagPiece_x                                0x962350
#define CStmlWnd__GetSTMLText_x                                    0x505F50
#define CStmlWnd__GetVisibleText_x                                 0x95D5A0
#define CStmlWnd__InitializeWindowVariables_x                      0x962ED0
#define CStmlWnd__MakeStmlColorTag_x                               0x95C600
#define CStmlWnd__MakeWndNotificationTag_x                         0x95C670
#define CStmlWnd__SetSTMLText_x                                    0x95B6B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x964180
#define CStmlWnd__UpdateHistoryString_x                            0x963290

// CTabWnd 
#define CTabWnd__Draw_x                                            0x95A800
#define CTabWnd__DrawCurrentPage_x                                 0x95AF30
#define CTabWnd__DrawTab_x                                         0x95AC50
#define CTabWnd__GetCurrentPage_x                                  0x95A000
#define CTabWnd__GetPageInnerRect_x                                0x95A240
#define CTabWnd__GetTabInnerRect_x                                 0x95A180
#define CTabWnd__GetTabRect_x                                      0x95A030
#define CTabWnd__InsertPage_x                                      0x95A450
#define CTabWnd__SetPage_x                                         0x95A2C0
#define CTabWnd__SetPageRect_x                                     0x95A740
#define CTabWnd__UpdatePage_x                                      0x95AB10
#define CTabWnd__GetPageFromTabIndex_x                             0x95AB90
#define CTabWnd__GetCurrentTabIndex_x                              0x959FF0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76BF30
#define CPageWnd__SetTabText_x                                     0x959B40

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8E00

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x9312A0
#define CTextureFont__GetTextExtent_x                              0x931460

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B9910
#define CHtmlComponentWnd__ValidateUri_x                           0x74A820
#define CHtmlWnd__SetClientCallbacks_x                             0x626E20
#define CHtmlWnd__AddObserver_x                                    0x626E40
#define CHtmlWnd__RemoveObserver_x                                 0x626EA0
#define Window__getProgress_x                                      0x862580
#define Window__getStatus_x                                        0x8625A0
#define Window__getURI_x                                           0x8625B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96F800

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91E4B0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8310
#define CXStr__CXStr1_x                                            0x926EC0
#define CXStr__CXStr3_x                                            0x9000F0
#define CXStr__dCXStr_x                                            0x4786F0
#define CXStr__operator_equal_x                                    0x900320
#define CXStr__operator_equal1_x                                   0x900360
#define CXStr__operator_plus_equal1_x                              0x900DF0
#define CXStr__SetString_x                                         0x902CF0
#define CXStr__operator_char_p_x                                   0x900830
#define CXStr__GetChar_x                                           0x902640
#define CXStr__Delete_x                                            0x901EF0
#define CXStr__GetUnicode_x                                        0x9026B0
#define CXStr__GetLength_x                                         0x47D3A0
#define CXStr__Mid_x                                               0x47D3B0
#define CXStr__Insert_x                                            0x902710
#define CXStr__FindNext_x                                          0x902360

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9529F0
#define CXWnd__BringToTop_x                                        0x937C60
#define CXWnd__Center_x                                            0x9377E0
#define CXWnd__ClrFocus_x                                          0x9375F0
#define CXWnd__Destroy_x                                           0x9376A0
#define CXWnd__DoAllDrawing_x                                      0x933BB0
#define CXWnd__DrawChildren_x                                      0x933B80
#define CXWnd__DrawColoredRect_x                                   0x934010
#define CXWnd__DrawTooltip_x                                       0x9326D0
#define CXWnd__DrawTooltipAtPoint_x                                0x932790
#define CXWnd__GetBorderFrame_x                                    0x933E70
#define CXWnd__GetChildWndAt_x                                     0x937D00
#define CXWnd__GetClientClipRect_x                                 0x935E90
#define CXWnd__GetScreenClipRect_x                                 0x935F60
#define CXWnd__GetScreenRect_x                                     0x936120
#define CXWnd__GetTooltipRect_x                                    0x934060
#define CXWnd__GetWindowTextA_x                                    0x49CA10
#define CXWnd__IsActive_x                                          0x934790
#define CXWnd__IsDescendantOf_x                                    0x936B30
#define CXWnd__IsReallyVisible_x                                   0x936B60
#define CXWnd__IsType_x                                            0x938360
#define CXWnd__Move_x                                              0x936BE0
#define CXWnd__Move1_x                                             0x936CA0
#define CXWnd__ProcessTransition_x                                 0x937790
#define CXWnd__Refade_x                                            0x936F80
#define CXWnd__Resize_x                                            0x937200
#define CXWnd__Right_x                                             0x937A20
#define CXWnd__SetFocus_x                                          0x9375B0
#define CXWnd__SetFont_x                                           0x937620
#define CXWnd__SetKeyTooltip_x                                     0x938190
#define CXWnd__SetMouseOver_x                                      0x934FE0
#define CXWnd__StartFade_x                                         0x936A10
#define CXWnd__GetChildItem_x                                      0x937E70
#define CXWnd__SetParent_x                                         0x9368D0
#define CXWnd__Minimize_x                                          0x937270

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x96ADD0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x93ABB0
#define CXWndManager__DrawWindows_x                                0x93ABD0
#define CXWndManager__GetKeyboardFlags_x                           0x93D3B0
#define CXWndManager__HandleKeyboardMsg_x                          0x93CF60
#define CXWndManager__RemoveWnd_x                                  0x93D5D0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93DB30

// CDBStr
#define CDBStr__GetString_x                                        0x53DB70

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB840
#define EQ_Character__Cur_HP_x                                     0x4D1EE0
#define EQ_Character__Cur_Mana_x                                   0x4D9600
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE8B0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2350
#define EQ_Character__GetFocusRangeModifier_x                      0x4B24A0
#define EQ_Character__GetHPRegen_x                                 0x4DF3A0
#define EQ_Character__GetEnduranceRegen_x                          0x4DF9A0
#define EQ_Character__GetManaRegen_x                               0x4DFDE0
#define EQ_Character__Max_Endurance_x                              0x64D2E0
#define EQ_Character__Max_HP_x                                     0x4D1D10
#define EQ_Character__Max_Mana_x                                   0x64D0E0
#define EQ_Character__doCombatAbility_x                            0x64F740
#define EQ_Character__UseSkill_x                                   0x4E1BC0
#define EQ_Character__GetConLevel_x                                0x6460F0
#define EQ_Character__IsExpansionFlag_x                            0x5A9B20
#define EQ_Character__TotalEffect_x                                0x4C5300
#define EQ_Character__GetPCSpellAffect_x                           0x4BF600
#define EQ_Character__SpellDuration_x                              0x4BF130
#define EQ_Character__GetAdjustedSkill_x                           0x4D4C60
#define EQ_Character__GetBaseSkill_x                               0x4D5C00
#define EQ_Character__CanUseItem_x                                 0x4D9910

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CC320

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x663C50

//PcClient
#define PcClient__PcClient_x                                       0x643830

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B94A0
#define CCharacterListWnd__EnterWorld_x                            0x4B8EE0
#define CCharacterListWnd__Quit_x                                  0x4B8C30
#define CCharacterListWnd__UpdateList_x                            0x4B9070

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x627FF0
#define EQ_Item__CreateItemTagString_x                             0x8A6570
#define EQ_Item__IsStackable_x                                     0x8AB1B0
#define EQ_Item__GetImageNum_x                                     0x8A7FE0
#define EQ_Item__CreateItemClient_x                                0x627240
#define EQ_Item__GetItemValue_x                                    0x8A93F0
#define EQ_Item__ValueSellMerchant_x                               0x8ACB80
#define EQ_Item__IsKeyRingItem_x                                   0x8AAAD0
#define EQ_Item__CanGoInBag_x                                      0x628110
#define EQ_Item__IsEmpty_x                                         0x8AA610
#define EQ_Item__GetMaxItemCount_x                                 0x8A9800
#define EQ_Item__GetHeldItem_x                                     0x8A7EB0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A5EB0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55BF70
#define EQ_LoadingS__Array_x                                       0xC2AB60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64DC40
#define EQ_PC__GetAlternateAbilityId_x                             0x8B5D80
#define EQ_PC__GetCombatAbility_x                                  0x8B63F0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B6460
#define EQ_PC__GetItemRecastTimer_x                                0x64FCC0
#define EQ_PC__HasLoreItem_x                                       0x646900
#define EQ_PC__AlertInventoryChanged_x                             0x645A30
#define EQ_PC__GetPcZoneClient_x                                   0x6726E0
#define EQ_PC__RemoveMyAffect_x                                    0x652EF0
#define EQ_PC__GetKeyRingItems_x                                   0x8B6CF0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B6A80
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B6FF0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5B0000
#define EQItemList__add_object_x                                   0x5DD900
#define EQItemList__add_item_x                                     0x5B0560
#define EQItemList__delete_item_x                                  0x5B05B0
#define EQItemList__FreeItemList_x                                 0x5B04B0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53A6B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6654D0
#define EQPlayer__dEQPlayer_x                                      0x658410
#define EQPlayer__DoAttack_x                                       0x66D370
#define EQPlayer__EQPlayer_x                                       0x658AD0
#define EQPlayer__SetNameSpriteState_x                             0x65D1C0
#define EQPlayer__SetNameSpriteTint_x                              0x65E080
#define PlayerBase__HasProperty_j_x                                0x99D5F0
#define EQPlayer__IsTargetable_x                                   0x99DA90
#define EQPlayer__CanSee_x                                         0x99D8F0
#define EQPlayer__CanSee1_x                                        0x99D9C0
#define PlayerBase__GetVisibilityLineSegment_x                     0x99D6B0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x670170
#define PlayerZoneClient__GetLevel_x                               0x672720
#define PlayerZoneClient__IsValidTeleport_x                        0x5DEA90
#define PlayerZoneClient__LegalPlayerRace_x                        0x555380

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x668280
#define EQPlayerManager__GetSpawnByName_x                          0x668330
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6683C0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x62B750
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x62B7D0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x62B810
#define KeypressHandler__ClearCommandStateArray_x                  0x62CC20
#define KeypressHandler__HandleKeyDown_x                           0x62CC40
#define KeypressHandler__HandleKeyUp_x                             0x62CCE0
#define KeypressHandler__SaveKeymapping_x                          0x62D130

// MapViewMap 
#define MapViewMap__Clear_x                                        0x782B40
#define MapViewMap__SaveEx_x                                       0x785F00
#define MapViewMap__SetZoom_x                                      0x78A5C0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8CA240

// StringTable 
#define StringTable__getString_x                                   0x8C5030

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x652B60
#define PcZoneClient__RemovePetEffect_x                            0x653190
#define PcZoneClient__HasAlternateAbility_x                        0x64CF10
#define PcZoneClient__GetCurrentMod_x                              0x4E4C70
#define PcZoneClient__GetModCap_x                                  0x4E4B70
#define PcZoneClient__CanEquipItem_x                               0x64D5E0
#define PcZoneClient__GetItemByID_x                                0x650130
#define PcZoneClient__GetItemByItemClass_x                         0x650280
#define PcZoneClient__RemoveBuffEffect_x                           0x6531B0
#define PcZoneClient__BandolierSwap_x                              0x64E200
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64FC60

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E3540

//IconCache
#define IconCache__GetIcon_x                                       0x724430

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x71BF30
#define CContainerMgr__CloseContainer_x                            0x71C200
#define CContainerMgr__OpenExperimentContainer_x                   0x71CC80

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7DAA20

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x6201D0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x779030
#define CLootWnd__RequestLootSlot_x                                0x778260

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57C920
#define EQ_Spell__SpellAffects_x                                   0x57CD90
#define EQ_Spell__SpellAffectBase_x                                0x57CB50
#define EQ_Spell__IsStackable_x                                    0x4C9910
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9730
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6840
#define EQ_Spell__IsSPAStacking_x                                  0x57DBE0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57D0F0
#define EQ_Spell__IsNoRemove_x                                     0x4C98F0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57DBF0
#define __IsResEffectSpell_x                                       0x4C8D20

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACEC0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D4970

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x821730
#define CTargetWnd__WndNotification_x                              0x820FC0
#define CTargetWnd__RefreshTargetBuffs_x                           0x821290
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x820130

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x825D20

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x538130
#define CTaskManager__HandleMessage_x                              0x5365A0
#define CTaskManager__GetTaskStatus_x                              0x5381E0
#define CTaskManager__GetElementDescription_x                      0x538260

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5778A0
#define EqSoundManager__PlayScriptMp3_x                            0x577B60
#define EqSoundManager__SoundAssistPlay_x                          0x68AA60
#define EqSoundManager__WaveInstancePlay_x                         0x689FD0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52B9E0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x959050

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x563A10
#define CAltAbilityData__GetMercMaxRank_x                          0x5639A0
#define CAltAbilityData__GetMaxRank_x                              0x559050

//CTargetRing
#define CTargetRing__Cast_x                                        0x61E2E0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9710
#define CharacterBase__CreateItemGlobalIndex_x                     0x512BD0
#define CharacterBase__CreateItemIndex_x                           0x6263D0
#define CharacterBase__GetItemPossession_x                         0x4FE940
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DCF70
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DCFD0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x703030
#define CCastSpellWnd__IsBardSongPlaying_x                         0x703860
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x703910

//messages
#define msg_spell_worn_off_x                                       0x5A1CF0
#define msg_new_text_x                                             0x596A80
#define __msgTokenTextParam_x                                      0x5A4210
#define msgTokenText_x                                             0x5A4460

//SpellManager
#define SpellManager__vftable_x                                    0xAEF664
#define SpellManager__SpellManager_x                               0x68DD90
#define Spellmanager__LoadTextSpells_x                             0x68E680
#define SpellManager__GetSpellByGroupAndRank_x                     0x68DF60

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9A14B0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x513280
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A7FB0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63F000
#define ItemGlobalIndex__IsValidIndex_x                            0x5132E0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D5310
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D5590

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x771870

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x720630
#define CCursorAttachment__AttachToCursor1_x                       0x720670
#define CCursorAttachment__Deactivate_x                            0x721660

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94BD80
#define CSidlManagerBase__CreatePageWnd_x                          0x94B580
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x947800
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x947790

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x968D00
#define CEQSuiteTextureLoader__GetTexture_x                        0x9689C0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x5101A0
#define CFindItemWnd__WndNotification_x                            0x510C80
#define CFindItemWnd__Update_x                                     0x5117C0
#define CFindItemWnd__PickupSelectedItem_x                         0x50F9F0

//IString
#define IString__Append_x                                          0x4F1360

//Camera
#define CDisplay__cameraType_x                                     0xE0477C
#define EverQuest__Cameras_x                                       0xEC7C14

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5189E0
#define LootFiltersManager__GetItemFilterData_x                    0x5182F0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x518320
#define LootFiltersManager__SetItemLootFilter_x                    0x518540

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C8A50

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A71B0
#define CResolutionHandler__GetWindowedStyle_x                     0x6856B0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x718D10

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8EA560
#define CDistillerInfo__Instance_x                                 0x8EA500

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x737BF0
#define CGroupWnd__UpdateDisplay_x                                 0x736F40

//ItemBase
#define ItemBase__IsLore_x                                         0x8AAB80
#define ItemBase__IsLoreEquipped_x                                 0x8AABF0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DD860
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DD9A0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DDA00

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x67ADE0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67E740

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x506560

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F3310
#define FactionManagerClient__HandleFactionMessage_x               0x4F3980
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F3F80
#define FactionManagerClient__GetMaxFaction_x                      0x4F3F9F
#define FactionManagerClient__GetMinFaction_x                      0x4F3F50

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FE910

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x9302F0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BCF0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FEBF0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x562EB0

//CTargetManager
#define CTargetManager__Get_x                                      0x691610

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x67ADE0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8BC0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5B0450

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF652A8

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
