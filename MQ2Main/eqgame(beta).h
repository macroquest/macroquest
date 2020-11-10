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
#define __ExpectedVersionDate                                     "Nov 10 2020"
#define __ExpectedVersionTime                                     "04:21:40"
#define __ActualVersionDate_x                                      0xAF654C
#define __ActualVersionTime_x                                      0xAF6540
#define __ActualVersionBuild_x                                     0xAE4554

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x643740
#define __MemChecker1_x                                            0x8F6720
#define __MemChecker2_x                                            0x6B3910
#define __MemChecker3_x                                            0x6B3860
#define __MemChecker4_x                                            0x84CA60
#define __EncryptPad0_x                                            0xC2C9C8
#define __EncryptPad1_x                                            0xC8A210
#define __EncryptPad2_x                                            0xC3CD90
#define __EncryptPad3_x                                            0xC3C990
#define __EncryptPad4_x                                            0xC7A7A0
#define __EncryptPad5_x                                            0xF4C650
#define __AC1_x                                                    0x80B276
#define __AC2_x                                                    0x5FCDDF
#define __AC3_x                                                    0x604430
#define __AC4_x                                                    0x6083E0
#define __AC5_x                                                    0x60E6DF
#define __AC6_x                                                    0x612B86
#define __AC7_x                                                    0x5FC850
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x19045C

// Direct Input
#define DI8__Main_x                                                0xF4C670
#define DI8__Keyboard_x                                            0xF4C674
#define DI8__Mouse_x                                               0xF4C688
#define DI8__Mouse_Copy_x                                          0xEA59DC
#define DI8__Mouse_Check_x                                         0xF4A1A4
#define __AutoSkillArray_x                                         0xEA68F8
#define __Attack_x                                                 0xF4472B
#define __Autofire_x                                               0xF4472C
#define __BindList_x                                               0xC1B3F8
#define g_eqCommandStates_x                                        0xC1C178
#define __Clicks_x                                                 0xEA5A94
#define __CommandList_x                                            0xC1CD38
#define __CurrentMapLabel_x                                        0xF5D14C
#define __CurrentSocial_x                                          0xC047C8
#define __DoAbilityList_x                                          0xEDC24C
#define __do_loot_x                                                0x5C8800
#define __DrawHandler_x                                            0x15DC140
#define __GroupCount_x                                             0xEA0A7A
#define __Guilds_x                                                 0xEA4918
#define __gWorld_x                                                 0xEA0924
#define __HWnd_x                                                   0xF4C68C
#define __heqmain_x                                                0xF4C638
#define __InChatMode_x                                             0xEA59C4
#define __LastTell_x                                               0xEA7948
#define __LMouseHeldTime_x                                         0xEA5B00
#define __Mouse_x                                                  0xF4C65C
#define __MouseLook_x                                              0xEA5A5A
#define __MouseEventTime_x                                         0xF4520C
#define __gpbCommandEvent_x                                        0xE9E3CC
#define __NetStatusToggle_x                                        0xEA5A5D
#define __PCNames_x                                                0xEA6EF4
#define __RangeAttackReady_x                                       0xEA6BDC
#define __RMouseHeldTime_x                                         0xEA5AFC
#define __RunWalkState_x                                           0xEA59C8
#define __ScreenMode_x                                             0xDEC1D8
#define __ScreenX_x                                                0xEA597C
#define __ScreenY_x                                                0xEA5978
#define __ScreenXMax_x                                             0xEA5980
#define __ScreenYMax_x                                             0xEA5984
#define __ServerHost_x                                             0xE9E59B
#define __ServerName_x                                             0xEDC20C
#define __ShiftKeyDown_x                                           0xEA6058
#define __ShowNames_x                                              0xEA6D98
#define EverQuestInfo__bSocialChanged_x                            0xEDC294
#define __Socials_x                                                0xEDC30C
#define __SubscriptionType_x                                       0xFA1410
#define __TargetAggroHolder_x                                      0xF5FB00
#define __ZoneType_x                                               0xEA5E58
#define __GroupAggro_x                                             0xF5FB40
#define __LoginName_x                                              0xF4CDCC
#define __Inviter_x                                                0xF446A8
#define __AttackOnAssist_x                                         0xEA6D54
#define __UseTellWindows_x                                         0xEA708C
#define __gfMaxZoomCameraDistance_x                                0xAEE170
#define __gfMaxCameraDistance_x                                    0xB16DF0
#define __pulAutoRun_x                                             0xEA5A78
#define __pulForward_x                                             0xEA70C4
#define __pulBackward_x                                            0xEA70C8
#define __pulTurnRight_x                                           0xEA70CC
#define __pulTurnLeft_x                                            0xEA70D0
#define __pulStrafeLeft_x                                          0xEA70D4
#define __pulStrafeRight_x                                         0xEA70D8

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEA0CB0
#define instEQZoneInfo_x                                           0xEA5C50
#define pinstActiveBanker_x                                        0xE9E8B8
#define pinstActiveCorpse_x                                        0xE9E8B0
#define pinstActiveGMaster_x                                       0xE9E8B4
#define pinstActiveMerchant_x                                      0xE9E8AC
#define pinstAltAdvManager_x                                       0xDECEE0
#define pinstBandageTarget_x                                       0xE9E8C8
#define pinstCamActor_x                                            0xDEC1C8
#define pinstCDBStr_x                                              0xDEBBFC
#define pinstCDisplay_x                                            0xE9E914
#define pinstCEverQuest_x                                          0xF4C690
#define pinstEverQuestInfo_x                                       0xEA5970
#define pinstCharData_x                                            0xE9E3B8
#define pinstCharSpawn_x                                           0xE9E900
#define pinstControlledMissile_x                                   0xE9E910
#define pinstControlledPlayer_x                                    0xE9E900
#define pinstCResolutionHandler_x                                  0x15DC370
#define pinstCSidlManager_x                                        0x15DB308
#define pinstCXWndManager_x                                        0x15DB304
#define instDynamicZone_x                                          0xEA47F0
#define pinstDZMember_x                                            0xEA4900
#define pinstDZTimerInfo_x                                         0xEA4904
#define pinstEqLogin_x                                             0xF4C718
#define instEQMisc_x                                               0xDEBB40
#define pinstEQSoundManager_x                                      0xDEDEB0
#define pinstEQSpellStrings_x                                      0xCAE448
#define instExpeditionLeader_x                                     0xEA483A
#define instExpeditionName_x                                       0xEA487A
#define pinstGroup_x                                               0xEA0A76
#define pinstImeManager_x                                          0x15DB300
#define pinstLocalPlayer_x                                         0xE9E6A4
#define pinstMercenaryData_x                                       0xF46D00
#define pinstMercenaryStats_x                                      0xF5FBCC
#define pinstModelPlayer_x                                         0xE9E8C0
#define pinstPCData_x                                              0xE9E3B8
#define pinstSkillMgr_x                                            0xF48E68
#define pinstSpawnManager_x                                        0xF47910
#define pinstSpellManager_x                                        0xF490A8
#define pinstSpellSets_x                                           0xF3D354
#define pinstStringTable_x                                         0xE9E3C0
#define pinstSwitchManager_x                                       0xE9E250
#define pinstTarget_x                                              0xE9E8FC
#define pinstTargetObject_x                                        0xE9E908
#define pinstTargetSwitch_x                                        0xE9E91C
#define pinstTaskMember_x                                          0xDEB9D0
#define pinstTrackTarget_x                                         0xE9E904
#define pinstTradeTarget_x                                         0xE9E8BC
#define instTributeActive_x                                        0xDEBB61
#define pinstViewActor_x                                           0xDEC1C4
#define pinstWorldData_x                                           0xE9E3B4
#define pinstZoneAddr_x                                            0xEA5EF0
#define pinstPlayerPath_x                                          0xF479A8
#define pinstTargetIndicator_x                                     0xF49310
#define EQObject_Top_x                                             0xE9E494
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDEC500
#define pinstCAchievementsWnd_x                                    0xDEC174
#define pinstCActionsWnd_x                                         0xDEBC9C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDEC234
#define pinstCAdvancedLootWnd_x                                    0xDEC1E8
#define pinstCAdventureLeaderboardWnd_x                            0xF56920
#define pinstCAdventureRequestWnd_x                                0xF569D0
#define pinstCAdventureStatsWnd_x                                  0xF56A80
#define pinstCAggroMeterWnd_x                                      0xDEC21C
#define pinstCAlarmWnd_x                                           0xDEC1A0
#define pinstCAlertHistoryWnd_x                                    0xDEC4B4
#define pinstCAlertStackWnd_x                                      0xDEC204
#define pinstCAlertWnd_x                                           0xDEC218
#define pinstCAltStorageWnd_x                                      0xF56DE0
#define pinstCAudioTriggersWindow_x                                0xCA0778
#define pinstCAuraWnd_x                                            0xDEC1EC
#define pinstCAvaZoneWnd_x                                         0xDEC4B0
#define pinstCBandolierWnd_x                                       0xDEC230
#define pinstCBankWnd_x                                            0xDEC274
#define pinstCBarterMerchantWnd_x                                  0xF58020
#define pinstCBarterSearchWnd_x                                    0xF580D0
#define pinstCBarterWnd_x                                          0xF58180
#define pinstCBazaarConfirmationWnd_x                              0xDEC1B4
#define pinstCBazaarSearchWnd_x                                    0xDEC504
#define pinstCBazaarWnd_x                                          0xDEC180
#define pinstCBlockedBuffWnd_x                                     0xDEC1F8
#define pinstCBlockedPetBuffWnd_x                                  0xDEC220
#define pinstCBodyTintWnd_x                                        0xDEC128
#define pinstCBookWnd_x                                            0xDEC268
#define pinstCBreathWnd_x                                          0xDEC514
#define pinstCBuffWindowNORMAL_x                                   0xDEC1D4
#define pinstCBuffWindowSHORT_x                                    0xDEC1DC
#define pinstCBugReportWnd_x                                       0xDEC26C
#define pinstCButtonWnd_x                                          0x15DB570
#define pinstCCastingWnd_x                                         0xDEC25C
#define pinstCCastSpellWnd_x                                       0xDEC510
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDEC134
#define pinstCChatWindowManager_x                                  0xF58C40
#define pinstCClaimWnd_x                                           0xF58D98
#define pinstCColorPickerWnd_x                                     0xDEC4C8
#define pinstCCombatAbilityWnd_x                                   0xDEC190
#define pinstCCombatSkillsSelectWnd_x                              0xDEC148
#define pinstCCompassWnd_x                                         0xDEBD14
#define pinstCConfirmationDialog_x                                 0xF5DC98
#define pinstCContainerMgr_x                                       0xDEC124
#define pinstCContextMenuManager_x                                 0x15DB2C0
#define pinstCCursorAttachment_x                                   0xDEC244
#define pinstCDynamicZoneWnd_x                                     0xF59360
#define pinstCEditLabelWnd_x                                       0xDEC1C0
#define pinstCEQMainWnd_x                                          0xF595A8
#define pinstCEventCalendarWnd_x                                   0xDEC508
#define pinstCExtendedTargetWnd_x                                  0xDEC200
#define pinstCFacePick_x                                           0xDEC14C
#define pinstCFactionWnd_x                                         0xDEC16C
#define pinstCFellowshipWnd_x                                      0xF597A8
#define pinstCFileSelectionWnd_x                                   0xDEC4C4
#define pinstCFindItemWnd_x                                        0xDEC15C
#define pinstCFindLocationWnd_x                                    0xF59900
#define pinstCFriendsWnd_x                                         0xDEC160
#define pinstCGemsGameWnd_x                                        0xDEC168
#define pinstCGiveWnd_x                                            0xDEC1A4
#define pinstCGroupSearchFiltersWnd_x                              0xDEC238
#define pinstCGroupSearchWnd_x                                     0xF59CF8
#define pinstCGroupWnd_x                                           0xF59DA8
#define pinstCGuildBankWnd_x                                       0xEA6D38
#define pinstCGuildCreationWnd_x                                   0xF59F08
#define pinstCGuildMgmtWnd_x                                       0xF59FB8
#define pinstCharacterCreation_x                                   0xDEC154
#define pinstCHelpWnd_x                                            0xDEC1A8
#define pinstCHeritageSelectionWnd_x                               0xDEC158
#define pinstCHotButtonWnd_x                                       0xF5C110
#define pinstCHotButtonWnd1_x                                      0xF5C110
#define pinstCHotButtonWnd2_x                                      0xF5C114
#define pinstCHotButtonWnd3_x                                      0xF5C118
#define pinstCHotButtonWnd4_x                                      0xF5C11C
#define pinstCIconSelectionWnd_x                                   0xDEC240
#define pinstCInspectWnd_x                                         0xDEC224
#define pinstCInventoryWnd_x                                       0xDEC1F0
#define pinstCInvSlotMgr_x                                         0xDEC4F4
#define pinstCItemDisplayManager_x                                 0xF5C6A0
#define pinstCItemExpTransferWnd_x                                 0xF5C7D4
#define pinstCItemOverflowWnd_x                                    0xDEC50C
#define pinstCJournalCatWnd_x                                      0xDEC4E0
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDEC4A0
#define pinstCKeyRingWnd_x                                         0xDEC24C
#define pinstCLargeDialogWnd_x                                     0xF5E918
#define pinstCLayoutCopyWnd_x                                      0xF5CB20
#define pinstCLFGuildWnd_x                                         0xF5CBD0
#define pinstCLoadskinWnd_x                                        0xDEC184
#define pinstCLootFiltersCopyWnd_x                                 0xCBCED8
#define pinstCLootFiltersWnd_x                                     0xDEC208
#define pinstCLootSettingsWnd_x                                    0xDEC22C
#define pinstCLootWnd_x                                            0xDEC4E4
#define pinstCMailAddressBookWnd_x                                 0xDEC4F8
#define pinstCMailCompositionWnd_x                                 0xDEC4D0
#define pinstCMailIgnoreListWnd_x                                  0xDEC4FC
#define pinstCMailWnd_x                                            0xDEC4D4
#define pinstCManageLootWnd_x                                      0xDED390
#define pinstCMapToolbarWnd_x                                      0xDEC1B0
#define pinstCMapViewWnd_x                                         0xDEC178
#define pinstCMarketplaceWnd_x                                     0xDEC20C
#define pinstCMerchantWnd_x                                        0xDEC4F0
#define pinstCMIZoneSelectWnd_x                                    0xF5D408
#define pinstCMusicPlayerWnd_x                                     0xDEC4BC
#define pinstCNameChangeMercWnd_x                                  0xDEC1AC
#define pinstCNameChangePetWnd_x                                   0xDEC17C
#define pinstCNameChangeWnd_x                                      0xDEC1BC
#define pinstCNoteWnd_x                                            0xDEC188
#define pinstCObjectPreviewWnd_x                                   0xDEC228
#define pinstCOptionsWnd_x                                         0xDEC194
#define pinstCPetInfoWnd_x                                         0xDEC4B8
#define pinstCPetitionQWnd_x                                       0xDEC144
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDEC12C
#define pinstCPlayerWnd_x                                          0xDEC4AC
#define pinstCPopupWndManager_x                                    0xF5DC98
#define pinstCProgressionSelectionWnd_x                            0xF5DD48
#define pinstCPurchaseGroupWnd_x                                   0xDEC280
#define pinstCPurchaseWnd_x                                        0xDEC260
#define pinstCPvPLeaderboardWnd_x                                  0xF5DDF8
#define pinstCPvPStatsWnd_x                                        0xF5DEA8
#define pinstCQuantityWnd_x                                        0xDEC49C
#define pinstCRaceChangeWnd_x                                      0xDEC1F4
#define pinstCRaidOptionsWnd_x                                     0xDEC23C
#define pinstCRaidWnd_x                                            0xDEC4EC
#define pinstCRealEstateItemsWnd_x                                 0xDEC170
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDEBD18
#define pinstCRealEstateManageWnd_x                                0xDEC284
#define pinstCRealEstateNeighborhoodWnd_x                          0xDEC4A8
#define pinstCRealEstatePlotSearchWnd_x                            0xDEC4C0
#define pinstCRealEstatePurchaseWnd_x                              0xDEC4DC
#define pinstCRespawnWnd_x                                         0xDEC214
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDEC140
#define pinstCSendMoneyWnd_x                                       0xDEC1B8
#define pinstCServerListWnd_x                                      0xDEC4E8
#define pinstCSkillsSelectWnd_x                                    0xDEC13C
#define pinstCSkillsWnd_x                                          0xDEBD1C
#define pinstCSocialEditWnd_x                                      0xDEC248
#define pinstCSocialWnd_x                                          0xDEC198
#define pinstCSpellBookWnd_x                                       0xDEC18C
#define pinstCStoryWnd_x                                           0xDEBC98
#define pinstCTargetOfTargetWnd_x                                  0xF5FC50
#define pinstCTargetWnd_x                                          0xDEC210
#define pinstCTaskOverlayWnd_x                                     0xDEC278
#define pinstCTaskSelectWnd_x                                      0xF5FDA8
#define pinstCTaskManager_x                                        0xCBD818
#define pinstCTaskTemplateSelectWnd_x                              0xF5FE58
#define pinstCTaskWnd_x                                            0xF5FF08
#define pinstCTextEntryWnd_x                                       0xDEC264
#define pinstCTimeLeftWnd_x                                        0xDEC138
#define pinstCTipWndCONTEXT_x                                      0xF6010C
#define pinstCTipWndOFDAY_x                                        0xF60108
#define pinstCTitleWnd_x                                           0xF601B8
#define pinstCTrackingWnd_x                                        0xDEC1FC
#define pinstCTradeskillWnd_x                                      0xF60320
#define pinstCTradeWnd_x                                           0xDEC130
#define pinstCTrainWnd_x                                           0xDEC4D8
#define pinstCTributeBenefitWnd_x                                  0xF60520
#define pinstCTributeMasterWnd_x                                   0xF605D0
#define pinstCTributeTrophyWnd_x                                   0xF60680
#define pinstCVideoModesWnd_x                                      0xDEC288
#define pinstCVoiceMacroWnd_x                                      0xF498C8
#define pinstCVoteResultsWnd_x                                     0xDEC164
#define pinstCVoteWnd_x                                            0xDEC150
#define pinstCWebManager_x                                         0xF49F44
#define pinstCZoneGuideWnd_x                                       0xDEC27C
#define pinstCZonePathWnd_x                                        0xDEC498

#define pinstEQSuiteTextureLoader_x                                0xC8AB30
#define pinstItemIconCache_x                                       0xF59560
#define pinstLootFiltersManager_x                                  0xCBCF88
#define pinstRewardSelectionWnd_x                                  0xF5E5F0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C3EF0
#define __CastRay2_x                                               0x5C3F40
#define __ConvertItemTags_x                                        0x5DFC10
#define __CleanItemTags_x                                          0x47D360
#define __DoesFileExist_x                                          0x8F9750
#define __EQGetTime_x                                              0x8F6350
#define __ExecuteCmd_x                                             0x5BC7E0
#define __FixHeading_x                                             0x98BFD0
#define __FlushDxKeyboard_x                                        0x6AF7B0
#define __GameLoop_x                                               0x6B2AE0
#define __get_bearing_x                                            0x5C3A50
#define __get_melee_range_x                                        0x5C4130
#define __GetAnimationCache_x                                      0x717E10
#define __GetGaugeValueFromEQ_x                                    0x809720
#define __GetLabelFromEQ_x                                         0x80B200
#define __GetXTargetType_x                                         0x98DA90
#define __HandleMouseWheel_x                                       0x6B39C0
#define __HeadingDiff_x                                            0x98C040
#define __HelpPath_x                                               0xF44DFC
#define __LoadFrontEnd_x                                           0x6AFDF0
#define __NewUIINI_x                                               0x8093F0
#define __ProcessGameEvents_x                                      0x624A50
#define __ProcessMouseEvent_x                                      0x6241E0
#define __SaveColors_x                                             0x55CD40
#define __STMLToText_x                                             0x92F430
#define __ToggleKeyRingItem_x                                      0x51B640
#define CMemoryMappedFile__SetFile_x                               0xA7B330
#define CrashDetected_x                                            0x6B18A0
#define DrawNetStatus_x                                            0x6509E0
#define Expansion_HoT_x                                            0xEA6D40
#define Teleport_Table_Size_x                                      0xE9E454
#define Teleport_Table_x                                           0xE9E920
#define Util__FastTime_x                                           0x8F5F20
#define __CopyLayout_x                                             0x63ED80
#define __WndProc_x                                                0x6B1DA0
#define __ProcessKeyboardEvent_x                                   0x6B1340

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490750
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499750
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499520
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493CF0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x493140

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x564E30
#define AltAdvManager__IsAbilityReady_x                            0x563BD0
#define AltAdvManager__GetAAById_x                                 0x563F60
#define AltAdvManager__CanTrainAbility_x                           0x563FD0
#define AltAdvManager__CanSeeAbility_x                             0x564330

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB530
#define CharacterZoneClient__HasSkill_x                            0x4D63B0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7AD0
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2B50
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BBFE0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA480
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA560
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA640
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4C40
#define CharacterZoneClient__BardCastBard_x                        0x4C7670
#define CharacterZoneClient__GetMaxEffects_x                       0x4BF9F0
#define CharacterZoneClient__GetEffect_x                           0x4BBF20
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5CB0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C5D80
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C5DD0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C5F20
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C6100
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B3F70
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8A30
#define CharacterZoneClient__FindItemByRecord_x                    0x4D84B0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D9560
#define CBankWnd__WndNotification_x                                0x6D9340

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E6D40

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x92CC10
#define CButtonWnd__CButtonWnd_x                                   0x92B820

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706FC0
#define CChatManager__InitContextMenu_x                            0x700100
#define CChatManager__FreeChatWindow_x                             0x705B00
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9F20
#define CChatManager__SetLockedActiveChatWindow_x                  0x706C40
#define CChatManager__CreateChatWindow_x                           0x706140

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4EA030

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x93FE60
#define CContextMenu__dCContextMenu_x                              0x940090
#define CContextMenu__AddMenuItem_x                                0x9400A0
#define CContextMenu__RemoveMenuItem_x                             0x9403B0
#define CContextMenu__RemoveAllMenuItems_x                         0x9403D0
#define CContextMenu__CheckMenuItem_x                              0x940450
#define CContextMenu__SetMenuItem_x                                0x9402D0
#define CContextMenu__AddSeparator_x                               0x940230

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9409E0
#define CContextMenuManager__RemoveMenu_x                          0x940A50
#define CContextMenuManager__PopupMenu_x                           0x940B10
#define CContextMenuManager__Flush_x                               0x940980
#define CContextMenuManager__GetMenu_x                             0x49B9B0
#define CContextMenuManager__CreateDefaultMenu_x                   0x712770

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D1140
#define CChatService__GetFriendName_x                              0x8D1150

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7077F0
#define CChatWindow__Clear_x                                       0x708AB0
#define CChatWindow__WndNotification_x                             0x709240
#define CChatWindow__AddHistory_x                                  0x708370

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x93D2D0
#define CComboWnd__Draw_x                                          0x93C7E0
#define CComboWnd__GetCurChoice_x                                  0x93D110
#define CComboWnd__GetListRect_x                                   0x93CC80
#define CComboWnd__GetTextRect_x                                   0x93D340
#define CComboWnd__InsertChoice_x                                  0x93CE10
#define CComboWnd__SetColors_x                                     0x93CDE0
#define CComboWnd__SetChoice_x                                     0x93D0E0
#define CComboWnd__GetItemCount_x                                  0x93D120
#define CComboWnd__GetCurChoiceText_x                              0x93D160
#define CComboWnd__GetChoiceText_x                                 0x93D130
#define CComboWnd__InsertChoiceAtIndex_x                           0x93CEA0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x710190
#define CContainerWnd__vftable_x                                   0xAFF744
#define CContainerWnd__SetContainer_x                              0x7116F0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x5576A0
#define CDisplay__PreZoneMainUI_x                                  0x5576B0
#define CDisplay__CleanGameUI_x                                    0x55CB00
#define CDisplay__GetClickedActor_x                                0x54FB00
#define CDisplay__GetUserDefinedColor_x                            0x548170
#define CDisplay__GetWorldFilePath_x                               0x551570
#define CDisplay__is3dON_x                                         0x54C760
#define CDisplay__ReloadUI_x                                       0x556BB0
#define CDisplay__WriteTextHD2_x                                   0x54C550
#define CDisplay__TrueDistance_x                                   0x553230
#define CDisplay__SetViewActor_x                                   0x54F420
#define CDisplay__GetFloorHeight_x                                 0x54C820
#define CDisplay__SetRenderWindow_x                                0x54B1A0
#define CDisplay__ToggleScreenshotMode_x                           0x54EEF0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x95FBA0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x943350
#define CEditWnd__EnsureCaretVisible_x                             0x945520
#define CEditWnd__GetCaretPt_x                                     0x9444D0
#define CEditWnd__GetCharIndexPt_x                                 0x944280
#define CEditWnd__GetDisplayString_x                               0x944120
#define CEditWnd__GetHorzOffset_x                                  0x9429F0
#define CEditWnd__GetLineForPrintableChar_x                        0x945420
#define CEditWnd__GetSelStartPt_x                                  0x944530
#define CEditWnd__GetSTMLSafeText_x                                0x943F40
#define CEditWnd__PointFromPrintableChar_x                         0x945050
#define CEditWnd__SelectableCharFromPoint_x                        0x9451C0
#define CEditWnd__SetEditable_x                                    0x944600
#define CEditWnd__SetWindowTextA_x                                 0x943CC0
#define CEditWnd__ReplaceSelection_x                               0x944CC0
#define CEditWnd__ReplaceSelection1_x                              0x944C40

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x612060
#define CEverQuest__ClickedPlayer_x                                0x604210
#define CEverQuest__CreateTargetIndicator_x                        0x621BC0
#define CEverQuest__DeleteTargetIndicator_x                        0x621C50
#define CEverQuest__DoTellWindow_x                                 0x4EA110
#define CEverQuest__OutputTextToLog_x                              0x4EA3E0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F9360
#define CEverQuest__dsp_chat_x                                     0x4EA770
#define CEverQuest__trimName_x                                     0x61DD70
#define CEverQuest__Emote_x                                        0x6128C0
#define CEverQuest__EnterZone_x                                    0x60C9D0
#define CEverQuest__GetBodyTypeDesc_x                              0x617310
#define CEverQuest__GetClassDesc_x                                 0x617950
#define CEverQuest__GetClassThreeLetterCode_x                      0x617F50
#define CEverQuest__GetDeityDesc_x                                 0x620410
#define CEverQuest__GetLangDesc_x                                  0x618110
#define CEverQuest__GetRaceDesc_x                                  0x617930
#define CEverQuest__InterpretCmd_x                                 0x6209E0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FD500
#define CEverQuest__LMouseUp_x                                     0x5FB880
#define CEverQuest__RightClickedOnPlayer_x                         0x5FDDE0
#define CEverQuest__RMouseUp_x                                     0x5FC810
#define CEverQuest__SetGameState_x                                 0x5F90F0
#define CEverQuest__UPCNotificationFlush_x                         0x61DC70
#define CEverQuest__IssuePetCommand_x                              0x619520
#define CEverQuest__ReportSuccessfulHit_x                          0x613C10

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x721F00
#define CGaugeWnd__CalcLinesFillRect_x                             0x721F60
#define CGaugeWnd__Draw_x                                          0x721580

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B0210
#define CGuild__GetGuildName_x                                     0x4AECC0
#define CGuild__GetGuildIndex_x                                    0x4AF2C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73BAF0

//CHotButton
#define CHotButton__SetCheck_x                                     0x633240
#define CHotButton__SetButtonSize_x                                0x633600

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x748B50
#define CInvSlotMgr__MoveItem_x                                    0x747870
#define CInvSlotMgr__SelectSlot_x                                  0x748C20

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7460A0
#define CInvSlot__SliderComplete_x                                 0x743DE0
#define CInvSlot__GetItemBase_x                                    0x743780
#define CInvSlot__UpdateItem_x                                     0x7438F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74A6A0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x749840
#define CInvSlotWnd__HandleLButtonUp_x                             0x74A220

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x804A90
#define CItemDisplayWnd__UpdateStrings_x                           0x758DA0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x752B00
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x753000
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7593B0
#define CItemDisplayWnd__AboutToShow_x                             0x7589E0
#define CItemDisplayWnd__WndNotification_x                         0x75A610
#define CItemDisplayWnd__RequestConvertItem_x                      0x759F50
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x757A40
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x758800

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8354B0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75EB50

// CLabel 
#define CLabel__Draw_x                                             0x764610

// CListWnd
#define CListWnd__CListWnd_x                                       0x915A20
#define CListWnd__dCListWnd_x                                      0x915D40
#define CListWnd__AddColumn_x                                      0x91A1C0
#define CListWnd__AddColumn1_x                                     0x91A210
#define CListWnd__AddLine_x                                        0x91A5A0
#define CListWnd__AddString_x                                      0x91A3A0
#define CListWnd__CalculateFirstVisibleLine_x                      0x919F80
#define CListWnd__CalculateVSBRange_x                              0x919D70
#define CListWnd__ClearSel_x                                       0x91AD80
#define CListWnd__ClearAllSel_x                                    0x91ADE0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x91B800
#define CListWnd__Compare_x                                        0x9196A0
#define CListWnd__Draw_x                                           0x915E70
#define CListWnd__DrawColumnSeparators_x                           0x918670
#define CListWnd__DrawHeader_x                                     0x918AE0
#define CListWnd__DrawItem_x                                       0x918FE0
#define CListWnd__DrawLine_x                                       0x9187E0
#define CListWnd__DrawSeparator_x                                  0x918710
#define CListWnd__EnableLine_x                                     0x917F40
#define CListWnd__EnsureVisible_x                                  0x91B720
#define CListWnd__ExtendSel_x                                      0x91ACB0
#define CListWnd__GetColumnTooltip_x                               0x917A80
#define CListWnd__GetColumnMinWidth_x                              0x917AF0
#define CListWnd__GetColumnWidth_x                                 0x9179F0
#define CListWnd__GetCurSel_x                                      0x917380
#define CListWnd__GetItemAtPoint_x                                 0x9181C0
#define CListWnd__GetItemAtPoint1_x                                0x918230
#define CListWnd__GetItemData_x                                    0x917400
#define CListWnd__GetItemHeight_x                                  0x9177C0
#define CListWnd__GetItemIcon_x                                    0x917590
#define CListWnd__GetItemRect_x                                    0x918030
#define CListWnd__GetItemText_x                                    0x917440
#define CListWnd__GetSelList_x                                     0x91AE30
#define CListWnd__GetSeparatorRect_x                               0x918470
#define CListWnd__InsertLine_x                                     0x91A990
#define CListWnd__RemoveLine_x                                     0x91AAE0
#define CListWnd__SetColors_x                                      0x919D40
#define CListWnd__SetColumnJustification_x                         0x919A70
#define CListWnd__SetColumnLabel_x                                 0x91A340
#define CListWnd__SetColumnWidth_x                                 0x919990
#define CListWnd__SetCurSel_x                                      0x91ABF0
#define CListWnd__SetItemColor_x                                   0x91B3D0
#define CListWnd__SetItemData_x                                    0x91B390
#define CListWnd__SetItemText_x                                    0x91AFA0
#define CListWnd__ShiftColumnSeparator_x                           0x919B30
#define CListWnd__Sort_x                                           0x919820
#define CListWnd__ToggleSel_x                                      0x91AC20
#define CListWnd__SetColumnsSizable_x                              0x919BE0
#define CListWnd__SetItemWnd_x                                     0x91B250
#define CListWnd__GetItemWnd_x                                     0x9175E0
#define CListWnd__SetItemIcon_x                                    0x91B020
#define CListWnd__CalculateCustomWindowPositions_x                 0x91A080
#define CListWnd__SetVScrollPos_x                                  0x919970

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x779D60
#define CMapViewWnd__GetWorldCoordinates_x                         0x778470
#define CMapViewWnd__HandleLButtonDown_x                           0x7754B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79A0F0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79A9D0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79AF00
#define CMerchantWnd__SelectRecoverySlot_x                         0x79DEA0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x798C60
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A3A70
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x799D00

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x89E9C0
#define CPacketScrambler__hton_x                                   0x89E9B0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x934A20
#define CSidlManager__FindScreenPieceTemplate_x                    0x934E30
#define CSidlManager__FindScreenPieceTemplate1_x                   0x934C20
#define CSidlManager__CreateLabel_x                                0x7FBD60
#define CSidlManager__CreateXWndFromTemplate_x                     0x937D90
#define CSidlManager__CreateXWndFromTemplate1_x                    0x937F70
#define CSidlManager__CreateXWnd_x                                 0x7FBC90
#define CSidlManager__CreateHotButtonWnd_x                         0x7FC250

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9314F0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9313F0
#define CSidlScreenWnd__ConvertToRes_x                             0x95A680
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x930EF0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x930BE0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x930CB0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x930D80
#define CSidlScreenWnd__DrawSidlPiece_x                            0x931990
#define CSidlScreenWnd__EnableIniStorage_x                         0x931E60
#define CSidlScreenWnd__GetSidlPiece_x                             0x931B80
#define CSidlScreenWnd__Init1_x                                    0x9307E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x931EB0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x932A00
#define CSidlScreenWnd__LoadSidlScreen_x                           0x92FBE0
#define CSidlScreenWnd__StoreIniInfo_x                             0x932570
#define CSidlScreenWnd__StoreIniVis_x                              0x9328E0
#define CSidlScreenWnd__WndNotification_x                          0x9318A0
#define CSidlScreenWnd__GetChildItem_x                             0x931DE0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9215D0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15DB190

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x698A80
#define CSkillMgr__GetSkillCap_x                                   0x698C60
#define CSkillMgr__GetNameToken_x                                  0x698200
#define CSkillMgr__IsActivatedSkill_x                              0x698340
#define CSkillMgr__IsCombatSkill_x                                 0x698280

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9417C0
#define CSliderWnd__SetValue_x                                     0x941630
#define CSliderWnd__SetNumTicks_x                                  0x941690

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x801E50

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94A110
#define CStmlWnd__ParseSTML_x                                      0x94B450
#define CStmlWnd__CalculateHSBRange_x                              0x94B230
#define CStmlWnd__CalculateVSBRange_x                              0x94B1B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x94F560
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9501F0
#define CStmlWnd__ForceParseNow_x                                  0x94A700
#define CStmlWnd__GetNextTagPiece_x                                0x94F4C0
#define CStmlWnd__GetSTMLText_x                                    0x50CB20
#define CStmlWnd__GetVisibleText_x                                 0x94A720
#define CStmlWnd__InitializeWindowVariables_x                      0x950040
#define CStmlWnd__MakeStmlColorTag_x                               0x949780
#define CStmlWnd__MakeWndNotificationTag_x                         0x9497F0
#define CStmlWnd__SetSTMLText_x                                    0x948830
#define CStmlWnd__StripFirstSTMLLines_x                            0x9512F0
#define CStmlWnd__UpdateHistoryString_x                            0x950400

// CTabWnd 
#define CTabWnd__Draw_x                                            0x947970
#define CTabWnd__DrawCurrentPage_x                                 0x9480A0
#define CTabWnd__DrawTab_x                                         0x947DC0
#define CTabWnd__GetCurrentPage_x                                  0x947180
#define CTabWnd__GetPageInnerRect_x                                0x9473C0
#define CTabWnd__GetTabInnerRect_x                                 0x947300
#define CTabWnd__GetTabRect_x                                      0x9471B0
#define CTabWnd__InsertPage_x                                      0x9475D0
#define CTabWnd__RemovePage_x                                      0x947740
#define CTabWnd__SetPage_x                                         0x947440
#define CTabWnd__SetPageRect_x                                     0x9478B0
#define CTabWnd__UpdatePage_x                                      0x947C80
#define CTabWnd__GetPageFromTabIndex_x                             0x947D00
#define CTabWnd__GetCurrentTabIndex_x                              0x947170

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75EF60
#define CPageWnd__SetTabText_x                                     0x946CD0
#define CPageWnd__FlashTab_x                                       0x946D30

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9580

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x91E4C0
#define CTextureFont__GetTextExtent_x                              0x91E680

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6ACC50
#define CHtmlComponentWnd__ValidateUri_x                           0x73D4E0
#define CHtmlWnd__SetClientCallbacks_x                             0x6386A0
#define CHtmlWnd__AddObserver_x                                    0x6386C0
#define CHtmlWnd__RemoveObserver_x                                 0x638720
#define Window__getProgress_x                                      0x854020
#define Window__getStatus_x                                        0x854040
#define Window__getURI_x                                           0x854050

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x957490

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x90B620

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9C60
#define CXStr__CXStr1_x                                            0x844600
#define CXStr__CXStr3_x                                            0x8F2310
#define CXStr__dCXStr_x                                            0x4784B0
#define CXStr__operator_equal_x                                    0x8F2540
#define CXStr__operator_equal1_x                                   0x8F2580
#define CXStr__operator_plus_equal1_x                              0x8F3010
#define CXStr__SetString_x                                         0x8F4F00
#define CXStr__operator_char_p_x                                   0x8F2A80
#define CXStr__GetChar_x                                           0x8F4830
#define CXStr__Delete_x                                            0x8F4100
#define CXStr__GetUnicode_x                                        0x8F48A0
#define CXStr__GetLength_x                                         0x47D710
#define CXStr__Mid_x                                               0x47D720
#define CXStr__Insert_x                                            0x8F4900
#define CXStr__FindNext_x                                          0x8F4570

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x93FA80
#define CXWnd__BringToTop_x                                        0x924D80
#define CXWnd__Center_x                                            0x924900
#define CXWnd__ClrFocus_x                                          0x924710
#define CXWnd__Destroy_x                                           0x9247C0
#define CXWnd__DoAllDrawing_x                                      0x920D90
#define CXWnd__DrawChildren_x                                      0x920D60
#define CXWnd__DrawColoredRect_x                                   0x9211C0
#define CXWnd__DrawTooltip_x                                       0x91F8D0
#define CXWnd__DrawTooltipAtPoint_x                                0x91F990
#define CXWnd__GetBorderFrame_x                                    0x921030
#define CXWnd__GetChildWndAt_x                                     0x924E20
#define CXWnd__GetClientClipRect_x                                 0x922FF0
#define CXWnd__GetScreenClipRect_x                                 0x9230C0
#define CXWnd__GetScreenRect_x                                     0x923250
#define CXWnd__GetRelativeRect_x                                   0x923310
#define CXWnd__GetTooltipRect_x                                    0x921210
#define CXWnd__GetWindowTextA_x                                    0x49D150
#define CXWnd__IsActive_x                                          0x921940
#define CXWnd__IsDescendantOf_x                                    0x923C50
#define CXWnd__IsReallyVisible_x                                   0x923C80
#define CXWnd__IsType_x                                            0x925490
#define CXWnd__Move_x                                              0x923CE0
#define CXWnd__Move1_x                                             0x923D90
#define CXWnd__ProcessTransition_x                                 0x9248B0
#define CXWnd__Refade_x                                            0x924060
#define CXWnd__Resize_x                                            0x924320
#define CXWnd__Right_x                                             0x924B40
#define CXWnd__SetFocus_x                                          0x9246D0
#define CXWnd__SetFont_x                                           0x924740
#define CXWnd__SetKeyTooltip_x                                     0x9252A0
#define CXWnd__SetMouseOver_x                                      0x922190
#define CXWnd__StartFade_x                                         0x923B30
#define CXWnd__GetChildItem_x                                      0x924F90
#define CXWnd__SetParent_x                                         0x9239F0
#define CXWnd__Minimize_x                                          0x924390

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95B700

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x927CC0
#define CXWndManager__DrawWindows_x                                0x927CE0
#define CXWndManager__GetKeyboardFlags_x                           0x92A4C0
#define CXWndManager__HandleKeyboardMsg_x                          0x92A080
#define CXWndManager__RemoveWnd_x                                  0x92A6F0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92AC70

// CDBStr
#define CDBStr__GetString_x                                        0x547130

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4C0150
#define EQ_Character__Cur_HP_x                                     0x4D33F0
#define EQ_Character__Cur_Mana_x                                   0x4DAB40
#define EQ_Character__GetCastingTimeModifier_x                     0x4C31C0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3BB0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3D00
#define EQ_Character__GetHPRegen_x                                 0x4E0A40
#define EQ_Character__GetEnduranceRegen_x                          0x4E1040
#define EQ_Character__GetManaRegen_x                               0x4E1480
#define EQ_Character__Max_Endurance_x                              0x65EF90
#define EQ_Character__Max_HP_x                                     0x4D3220
#define EQ_Character__Max_Mana_x                                   0x65ED90
#define EQ_Character__doCombatAbility_x                            0x661380
#define EQ_Character__UseSkill_x                                   0x4E3280
#define EQ_Character__GetConLevel_x                                0x6578C0
#define EQ_Character__IsExpansionFlag_x                            0x5BAFE0
#define EQ_Character__TotalEffect_x                                0x4C6F60
#define EQ_Character__GetPCSpellAffect_x                           0x4C3F10
#define EQ_Character__SpellDuration_x                              0x4C3A40
#define EQ_Character__MySpellDuration_x                            0x4B24E0
#define EQ_Character__GetAdjustedSkill_x                           0x4D6170
#define EQ_Character__GetBaseSkill_x                               0x4D7110
#define EQ_Character__CanUseItem_x                                 0x4DAE50

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8BDFB0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x675270

//PcClient
#define PcClient__vftable_x                                        0xAF31D0
#define PcClient__PcClient_x                                       0x655030

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BAB90
#define CCharacterListWnd__EnterWorld_x                            0x4BA560
#define CCharacterListWnd__Quit_x                                  0x4BA2B0
#define CCharacterListWnd__UpdateList_x                            0x4BA750

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x639880
#define EQ_Item__CreateItemTagString_x                             0x897EC0
#define EQ_Item__IsStackable_x                                     0x89CC00
#define EQ_Item__GetImageNum_x                                     0x899A80
#define EQ_Item__CreateItemClient_x                                0x638AC0
#define EQ_Item__GetItemValue_x                                    0x89AD70
#define EQ_Item__ValueSellMerchant_x                               0x89E5A0
#define EQ_Item__IsKeyRingItem_x                                   0x89C500
#define EQ_Item__CanGoInBag_x                                      0x6399A0
#define EQ_Item__IsEmpty_x                                         0x89C050
#define EQ_Item__GetMaxItemCount_x                                 0x89B190
#define EQ_Item__GetHeldItem_x                                     0x899950
#define EQ_Item__GetAugmentFitBySlot_x                             0x897710

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x565B40
#define EQ_LoadingS__Array_x                                       0xC14128

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65F890
#define EQ_PC__GetAlternateAbilityId_x                             0x8A79F0
#define EQ_PC__GetCombatAbility_x                                  0x8A8060
#define EQ_PC__GetCombatAbilityTimer_x                             0x8A80D0
#define EQ_PC__GetItemRecastTimer_x                                0x661900
#define EQ_PC__HasLoreItem_x                                       0x6580E0
#define EQ_PC__AlertInventoryChanged_x                             0x657200
#define EQ_PC__GetPcZoneClient_x                                   0x684270
#define EQ_PC__RemoveMyAffect_x                                    0x664B30
#define EQ_PC__GetKeyRingItems_x                                   0x8A89A0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8A8720
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8A8CA0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5C1440
#define EQItemList__add_object_x                                   0x5EEB00
#define EQItemList__add_item_x                                     0x5C19A0
#define EQItemList__delete_item_x                                  0x5C19F0
#define EQItemList__FreeItemList_x                                 0x5C18F0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x543CB0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x676B70
#define EQPlayer__dEQPlayer_x                                      0x669EE0
#define EQPlayer__DoAttack_x                                       0x67EA10
#define EQPlayer__EQPlayer_x                                       0x66A5A0
#define EQPlayer__SetNameSpriteState_x                             0x66E880
#define EQPlayer__SetNameSpriteTint_x                              0x66F760
#define PlayerBase__HasProperty_j_x                                0x98A3E0
#define EQPlayer__IsTargetable_x                                   0x98A880
#define EQPlayer__CanSee_x                                         0x98A6E0
#define EQPlayer__CanSee1_x                                        0x98A7B0
#define PlayerBase__GetVisibilityLineSegment_x                     0x98A4A0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x681D10
#define PlayerZoneClient__GetLevel_x                               0x6842B0
#define PlayerZoneClient__IsValidTeleport_x                        0x5EFC60
#define PlayerZoneClient__LegalPlayerRace_x                        0x55E930

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6798C0
#define EQPlayerManager__GetSpawnByName_x                          0x679970
#define EQPlayerManager__GetPlayerFromPartialName_x                0x679A00

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x63CFE0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x63D060
#define KeypressHandler__AttachKeyToEqCommand_x                    0x63D0A0
#define KeypressHandler__ClearCommandStateArray_x                  0x63E490
#define KeypressHandler__HandleKeyDown_x                           0x63E4B0
#define KeypressHandler__HandleKeyUp_x                             0x63E550
#define KeypressHandler__SaveKeymapping_x                          0x63E9A0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x775BD0
#define MapViewMap__SaveEx_x                                       0x778F90
#define MapViewMap__SetZoom_x                                      0x77D650

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BBF70

// StringTable 
#define StringTable__getString_x                                   0x8B6E60

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6647A0
#define PcZoneClient__RemovePetEffect_x                            0x664DD0
#define PcZoneClient__HasAlternateAbility_x                        0x65EBC0
#define PcZoneClient__GetCurrentMod_x                              0x4E63A0
#define PcZoneClient__GetModCap_x                                  0x4E62A0
#define PcZoneClient__CanEquipItem_x                               0x65F270
#define PcZoneClient__GetItemByID_x                                0x661D70
#define PcZoneClient__GetItemByItemClass_x                         0x661EC0
#define PcZoneClient__RemoveBuffEffect_x                           0x664DF0
#define PcZoneClient__BandolierSwap_x                              0x65FE50
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x6618A0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F47E0

//IconCache
#define IconCache__GetIcon_x                                       0x717810

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70F330
#define CContainerMgr__CloseContainer_x                            0x70F600
#define CContainerMgr__OpenExperimentContainer_x                   0x710080

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CE4D0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x631A10

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76C090
#define CLootWnd__RequestLootSlot_x                                0x76B370

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58D450
#define EQ_Spell__SpellAffects_x                                   0x58D8C0
#define EQ_Spell__SpellAffectBase_x                                0x58D680
#define EQ_Spell__IsStackable_x                                    0x4CAE40
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CAC30
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B7E70
#define EQ_Spell__IsSPAStacking_x                                  0x58E710
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58DC20
#define EQ_Spell__IsNoRemove_x                                     0x4CAE20
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58E720
#define __IsResEffectSpell_x                                       0x4C9F90

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD770

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C66E0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8151F0
#define CTargetWnd__WndNotification_x                              0x814A30
#define CTargetWnd__RefreshTargetBuffs_x                           0x814D00
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x813BA0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x819860
#define CTaskWnd__ConfirmAbandonTask_x                             0x81C4A0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5416C0
#define CTaskManager__HandleMessage_x                              0x53FB30
#define CTaskManager__GetTaskStatus_x                              0x541770
#define CTaskManager__GetElementDescription_x                      0x5417F0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5885F0
#define EqSoundManager__PlayScriptMp3_x                            0x5888B0
#define EqSoundManager__SoundAssistPlay_x                          0x69CA10
#define EqSoundManager__WaveInstancePlay_x                         0x69BF80

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x532AD0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9461E0
#define CTextureAnimation__Draw_x                                  0x9463E0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x942130

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56D620
#define CAltAbilityData__GetMercMaxRank_x                          0x56D5B0
#define CAltAbilityData__GetMaxRank_x                              0x562A50

//CTargetRing
#define CTargetRing__Cast_x                                        0x62FB30

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CAC10
#define CharacterBase__CreateItemGlobalIndex_x                     0x519850
#define CharacterBase__CreateItemIndex_x                           0x637C50
#define CharacterBase__GetItemPossession_x                         0x505490
#define CharacterBase__GetItemByGlobalIndex_x                      0x8CED20
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8CED80
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F6300
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F6B30
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F6BE0

//messages
#define msg_spell_worn_off_x                                       0x5B2F50
#define msg_new_text_x                                             0x5A78E0
#define __msgTokenTextParam_x                                      0x5B51F0
#define msgTokenText_x                                             0x5B5440

//SpellManager
#define SpellManager__vftable_x                                    0xADB564
#define SpellManager__SpellManager_x                               0x69FD40
#define Spellmanager__LoadTextSpells_x                             0x6A0630
#define SpellManager__GetSpellByGroupAndRank_x                     0x69FF10

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x98E380

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x519EA0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B93C0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x650840
#define ItemGlobalIndex__IsValidIndex_x                            0x519F30

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C7080
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C7300

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x764950

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x713A10
#define CCursorAttachment__AttachToCursor1_x                       0x713A50
#define CCursorAttachment__Deactivate_x                            0x714A40

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x938DC0
#define CSidlManagerBase__CreatePageWnd_x                          0x9385C0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x934840
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9347D0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x955F00
#define CEQSuiteTextureLoader__GetTexture_x                        0x955BC0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x516DD0
#define CFindItemWnd__WndNotification_x                            0x5178B0
#define CFindItemWnd__Update_x                                     0x518420
#define CFindItemWnd__PickupSelectedItem_x                         0x516600

//IString
#define IString__Append_x                                          0x506DB0

//Camera
#define CDisplay__cameraType_x                                     0xDEC290
#define EverQuest__Cameras_x                                       0xEA7098

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51F7D0
#define LootFiltersManager__GetItemFilterData_x                    0x51F0D0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51F100
#define LootFiltersManager__SetItemLootFilter_x                    0x51F320

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BC300

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x993FC0
#define CResolutionHandler__GetWindowedStyle_x                     0x697390

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70BF60

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DC770
#define CDistillerInfo__Instance_x                                 0x8DC710

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72AE60
#define CGroupWnd__UpdateDisplay_x                                 0x72A1C0

//ItemBase
#define ItemBase__IsLore_x                                         0x89C5B0
#define ItemBase__IsLoreEquipped_x                                 0x89C630

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EEA60
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EEBA0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EEC00

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C9A0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6902E0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50D500

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F96C0
#define FactionManagerClient__HandleFactionMessage_x               0x4F9D30
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4FA2F0
#define FactionManagerClient__GetMaxFaction_x                      0x4FA30F
#define FactionManagerClient__GetMinFaction_x                      0x4FA2C0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x505460

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x91D470

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C460

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5057C0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56CAB0

//CTargetManager
#define CTargetManager__Get_x                                      0x6A35B0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x68C9A0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A9340

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5C1890

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF44730

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6BFCC0
#define CAAWnd__UpdateSelected_x                                   0x6BC530
#define CAAWnd__Update_x                                           0x6BEFE0

//CXRect
#define CXRect__operator_and_x                                     0x721FC0

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x483350

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
