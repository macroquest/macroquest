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
#define __ExpectedVersionDate                                     "Nov  7 2019"
#define __ExpectedVersionTime                                     "04:22:30"
#define __ActualVersionDate_x                                      0xB0719C
#define __ActualVersionTime_x                                      0xB07190
#define __ActualVersionBuild_x                                     0xAF2E7C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62D2C0
#define __MemChecker1_x                                            0x8FFBD0
#define __MemChecker2_x                                            0x6BB570
#define __MemChecker3_x                                            0x6BB4C0
#define __MemChecker4_x                                            0x8573D0
#define __EncryptPad0_x                                            0xC3D3E8
#define __EncryptPad1_x                                            0xC9B5A8
#define __EncryptPad2_x                                            0xC4DC80
#define __EncryptPad3_x                                            0xC4D880
#define __EncryptPad4_x                                            0xC8BC00
#define __EncryptPad5_x                                            0xF64D6C
#define __AC1_x                                                    0x813DF6
#define __AC2_x                                                    0x5E73CF
#define __AC3_x                                                    0x5EEACF
#define __AC4_x                                                    0x5F2AA0
#define __AC5_x                                                    0x5F8DAF
#define __AC6_x                                                    0x5FD3C6
#define __AC7_x                                                    0x5E6E40
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x192138

// Direct Input
#define DI8__Main_x                                                0xF67250
#define DI8__Keyboard_x                                            0xF67254
#define DI8__Mouse_x                                               0xF66208
#define DI8__Mouse_Copy_x                                          0xEC0434
#define DI8__Mouse_Check_x                                         0xF64D94
#define __AutoSkillArray_x                                         0xEC134C
#define __Attack_x                                                 0xF5F173
#define __Autofire_x                                               0xF5F174
#define __BindList_x                                               0xC2BE20
#define g_eqCommandStates_x                                        0xC2CBA0
#define __Clicks_x                                                 0xEC04EC
#define __CommandList_x                                            0xC2D760
#define __CurrentMapLabel_x                                        0xF77BF4
#define __CurrentSocial_x                                          0xC157CC
#define __DoAbilityList_x                                          0xEF6C94
#define __do_loot_x                                                0x5B3850
#define __DrawHandler_x                                            0x15F6F68
#define __GroupCount_x                                             0xEB2DEA
#define __Guilds_x                                                 0xEB6C40
#define __gWorld_x                                                 0xEB2C4C
#define __HWnd_x                                                   0xF66210
#define __heqmain_x                                                0xF67244
#define __InChatMode_x                                             0xEC041C
#define __LastTell_x                                               0xEC2390
#define __LMouseHeldTime_x                                         0xEC0558
#define __Mouse_x                                                  0xF67230
#define __MouseLook_x                                              0xEC04B2
#define __MouseEventTime_x                                         0xF5FC54
#define __gpbCommandEvent_x                                        0xEB06D8
#define __NetStatusToggle_x                                        0xEC04B5
#define __PCNames_x                                                0xEC193C
#define __RangeAttackReady_x                                       0xEC1630
#define __RMouseHeldTime_x                                         0xEC0554
#define __RunWalkState_x                                           0xEC0420
#define __ScreenMode_x                                             0xDFE080
#define __ScreenX_x                                                0xEC03D4
#define __ScreenY_x                                                0xEC03D0
#define __ScreenXMax_x                                             0xEC03D8
#define __ScreenYMax_x                                             0xEC03DC
#define __ServerHost_x                                             0xEB090B
#define __ServerName_x                                             0xEF6C54
#define __ShiftKeyDown_x                                           0xEC0AAC
#define __ShowNames_x                                              0xEC17EC
#define __Socials_x                                                0xEF6D54
#define __SubscriptionType_x                                       0xFBC0F8
#define __TargetAggroHolder_x                                      0xF7A5A8
#define __ZoneType_x                                               0xEC08B0
#define __GroupAggro_x                                             0xF7A5E8
#define __LoginName_x                                              0xF679A4
#define __Inviter_x                                                0xF5F0F0
#define __AttackOnAssist_x                                         0xEC17A8
#define __UseTellWindows_x                                         0xEC1AD8
#define __gfMaxZoomCameraDistance_x                                0xAFCAF8
#define __gfMaxCameraDistance_x                                    0xB29044
#define __pulAutoRun_x                                             0xEC04D0
#define __pulForward_x                                             0xEC1B10
#define __pulBackward_x                                            0xEC1B14
#define __pulTurnRight_x                                           0xEC1B18
#define __pulTurnLeft_x                                            0xEC1B1C
#define __pulStrafeLeft_x                                          0xEC1B20
#define __pulStrafeRight_x                                         0xEC1B24

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB2FE0
#define instEQZoneInfo_x                                           0xEC06A8
#define pinstActiveBanker_x                                        0xEB06F0
#define pinstActiveCorpse_x                                        0xEB06E8
#define pinstActiveGMaster_x                                       0xEB06EC
#define pinstActiveMerchant_x                                      0xEB06E4
#define pinstAltAdvManager_x                                       0xDFF210
#define pinstBandageTarget_x                                       0xEB0700
#define pinstCamActor_x                                            0xDFE074
#define pinstCDBStr_x                                              0xDFDF2C
#define pinstCDisplay_x                                            0xEB2C34
#define pinstCEverQuest_x                                          0xF67268
#define pinstEverQuestInfo_x                                       0xEC03C8
#define pinstCharData_x                                            0xEB2DCC
#define pinstCharSpawn_x                                           0xEB07B8
#define pinstControlledMissile_x                                   0xEB0C24
#define pinstControlledPlayer_x                                    0xEB07B8
#define pinstCResolutionHandler_x                                  0x15F7198
#define pinstCSidlManager_x                                        0x15F6130
#define pinstCXWndManager_x                                        0x15F612C
#define instDynamicZone_x                                          0xEB6B18
#define pinstDZMember_x                                            0xEB6C28
#define pinstDZTimerInfo_x                                         0xEB6C2C
#define pinstEqLogin_x                                             0xF672F0
#define instEQMisc_x                                               0xDFDE70
#define pinstEQSoundManager_x                                      0xE001E0
#define pinstEQSpellStrings_x                                      0xCC08D8
#define instExpeditionLeader_x                                     0xEB6B62
#define instExpeditionName_x                                       0xEB6BA2
#define pinstGroup_x                                               0xEB2DE6
#define pinstImeManager_x                                          0x15F6128
#define pinstLocalPlayer_x                                         0xEB06E0
#define pinstMercenaryData_x                                       0xF61744
#define pinstMercenaryStats_x                                      0xF7A6F4
#define pinstModelPlayer_x                                         0xEB06F8
#define pinstPCData_x                                              0xEB2DCC
#define pinstSkillMgr_x                                            0xF638B0
#define pinstSpawnManager_x                                        0xF62358
#define pinstSpellManager_x                                        0xF63AD0
#define pinstSpellSets_x                                           0xF57D9C
#define pinstStringTable_x                                         0xEB2DD0
#define pinstSwitchManager_x                                       0xEB0580
#define pinstTarget_x                                              0xEB0734
#define pinstTargetObject_x                                        0xEB07C0
#define pinstTargetSwitch_x                                        0xEB0C2C
#define pinstTaskMember_x                                          0xDFDD00
#define pinstTrackTarget_x                                         0xEB07BC
#define pinstTradeTarget_x                                         0xEB06F4
#define instTributeActive_x                                        0xDFDE91
#define pinstViewActor_x                                           0xDFE070
#define pinstWorldData_x                                           0xEB0C20
#define pinstZoneAddr_x                                            0xEC0948
#define pinstPlayerPath_x                                          0xF623F0
#define pinstTargetIndicator_x                                     0xF63D38
#define EQObject_Top_x                                             0xEB06DC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDFE7F4
#define pinstCAchievementsWnd_x                                    0xDFE7E4
#define pinstCActionsWnd_x                                         0xDFE7B4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDFE030
#define pinstCAdvancedLootWnd_x                                    0xDFDFE4
#define pinstCAdventureLeaderboardWnd_x                            0xF713C8
#define pinstCAdventureRequestWnd_x                                0xF71478
#define pinstCAdventureStatsWnd_x                                  0xF71528
#define pinstCAggroMeterWnd_x                                      0xDFE144
#define pinstCAlarmWnd_x                                           0xDFE858
#define pinstCAlertHistoryWnd_x                                    0xDFE02C
#define pinstCAlertStackWnd_x                                      0xDFE838
#define pinstCAlertWnd_x                                           0xDFE854
#define pinstCAltStorageWnd_x                                      0xF71888
#define pinstCAudioTriggersWindow_x                                0xCB2C08
#define pinstCAuraWnd_x                                            0xDFE064
#define pinstCAvaZoneWnd_x                                         0xDFE008
#define pinstCBandolierWnd_x                                       0xDFE0CC
#define pinstCBankWnd_x                                            0xDFE060
#define pinstCBarterMerchantWnd_x                                  0xF72AC8
#define pinstCBarterSearchWnd_x                                    0xF72B78
#define pinstCBarterWnd_x                                          0xF72C28
#define pinstCBazaarConfirmationWnd_x                              0xDFE810
#define pinstCBazaarSearchWnd_x                                    0xDFE58C
#define pinstCBazaarWnd_x                                          0xDFE834
#define pinstCBlockedBuffWnd_x                                     0xDFE06C
#define pinstCBlockedPetBuffWnd_x                                  0xDFE0C4
#define pinstCBodyTintWnd_x                                        0xDFE7C8
#define pinstCBookWnd_x                                            0xDFE564
#define pinstCBreathWnd_x                                          0xDFE80C
#define pinstCBuffWindowNORMAL_x                                   0xDFE04C
#define pinstCBuffWindowSHORT_x                                    0xDFE050
#define pinstCBugReportWnd_x                                       0xDFE058
#define pinstCButtonWnd_x                                          0x15F6398
#define pinstCCastingWnd_x                                         0xDFE558
#define pinstCCastSpellWnd_x                                       0xDFE808
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDFE840
#define pinstCChatWindowManager_x                                  0xF736E8
#define pinstCClaimWnd_x                                           0xF73840
#define pinstCColorPickerWnd_x                                     0xDFE7C0
#define pinstCCombatAbilityWnd_x                                   0xDFE850
#define pinstCCombatSkillsSelectWnd_x                              0xDFDFD0
#define pinstCCompassWnd_x                                         0xDFE7B8
#define pinstCConfirmationDialog_x                                 0xF78740
#define pinstCContainerMgr_x                                       0xDFE82C
#define pinstCContextMenuManager_x                                 0x15F60E8
#define pinstCCursorAttachment_x                                   0xDFE14C
#define pinstCDynamicZoneWnd_x                                     0xF73E08
#define pinstCEditLabelWnd_x                                       0xDFE03C
#define pinstCEQMainWnd_x                                          0xF74050
#define pinstCEventCalendarWnd_x                                   0xDFE0C8
#define pinstCExtendedTargetWnd_x                                  0xDFE0B4
#define pinstCFacePick_x                                           0xDFDFD8
#define pinstCFactionWnd_x                                         0xDFE824
#define pinstCFellowshipWnd_x                                      0xF74250
#define pinstCFileSelectionWnd_x                                   0xDFE554
#define pinstCFindItemWnd_x                                        0xDFE818
#define pinstCFindLocationWnd_x                                    0xF743A8
#define pinstCFriendsWnd_x                                         0xDFDFE0
#define pinstCGemsGameWnd_x                                        0xDFE820
#define pinstCGiveWnd_x                                            0xDFE85C
#define pinstCGroupSearchFiltersWnd_x                              0xDFE55C
#define pinstCGroupSearchWnd_x                                     0xF747A0
#define pinstCGroupWnd_x                                           0xF74850
#define pinstCGuildBankWnd_x                                       0xEC178C
#define pinstCGuildCreationWnd_x                                   0xF749B0
#define pinstCGuildMgmtWnd_x                                       0xF74A60
#define pinstCharacterCreation_x                                   0xDFDFD4
#define pinstCHelpWnd_x                                            0xDFE01C
#define pinstCHeritageSelectionWnd_x                               0xDFDFE8
#define pinstCHotButtonWnd_x                                       0xF76BB8
#define pinstCHotButtonWnd1_x                                      0xF76BB8
#define pinstCHotButtonWnd2_x                                      0xF76BBC
#define pinstCHotButtonWnd3_x                                      0xF76BC0
#define pinstCHotButtonWnd4_x                                      0xF76BC4
#define pinstCIconSelectionWnd_x                                   0xDFE148
#define pinstCInspectWnd_x                                         0xDFE018
#define pinstCInventoryWnd_x                                       0xDFDFEC
#define pinstCInvSlotMgr_x                                         0xDFE7EC
#define pinstCItemDisplayManager_x                                 0xF77148
#define pinstCItemExpTransferWnd_x                                 0xF77278
#define pinstCItemOverflowWnd_x                                    0xDFE590
#define pinstCJournalCatWnd_x                                      0xDFE56C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDFE0B8
#define pinstCKeyRingWnd_x                                         0xDFE038
#define pinstCLargeDialogWnd_x                                     0xF793C0
#define pinstCLayoutCopyWnd_x                                      0xF775C8
#define pinstCLFGuildWnd_x                                         0xF77678
#define pinstCLoadskinWnd_x                                        0xDFE830
#define pinstCLootFiltersCopyWnd_x                                 0xCCF208
#define pinstCLootFiltersWnd_x                                     0xDFE83C
#define pinstCLootSettingsWnd_x                                    0xDFDFC8
#define pinstCLootWnd_x                                            0xDFE570
#define pinstCMailAddressBookWnd_x                                 0xDFE7F8
#define pinstCMailCompositionWnd_x                                 0xDFE7DC
#define pinstCMailIgnoreListWnd_x                                  0xDFE7FC
#define pinstCMailWnd_x                                            0xDFE7B0
#define pinstCManageLootWnd_x                                      0xDFF6C0
#define pinstCMapToolbarWnd_x                                      0xDFE024
#define pinstCMapViewWnd_x                                         0xDFE000
#define pinstCMarketplaceWnd_x                                     0xDFE84C
#define pinstCMerchantWnd_x                                        0xDFE580
#define pinstCMIZoneSelectWnd_x                                    0xF77EB0
#define pinstCMusicPlayerWnd_x                                     0xDFE584
#define pinstCNameChangeMercWnd_x                                  0xDFE800
#define pinstCNameChangePetWnd_x                                   0xDFE7E8
#define pinstCNameChangeWnd_x                                      0xDFE814
#define pinstCNoteWnd_x                                            0xDFE00C
#define pinstCObjectPreviewWnd_x                                   0xDFE860
#define pinstCOptionsWnd_x                                         0xDFE010
#define pinstCPetInfoWnd_x                                         0xDFE59C
#define pinstCPetitionQWnd_x                                       0xDFE7C4
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDFE7CC
#define pinstCPlayerWnd_x                                          0xDFE5A0
#define pinstCPopupWndManager_x                                    0xF78740
#define pinstCProgressionSelectionWnd_x                            0xF787F0
#define pinstCPurchaseGroupWnd_x                                   0xDFDFF8
#define pinstCPurchaseWnd_x                                        0xDFDFDC
#define pinstCPvPLeaderboardWnd_x                                  0xF788A0
#define pinstCPvPStatsWnd_x                                        0xF78950
#define pinstCQuantityWnd_x                                        0xDFE0BC
#define pinstCRaceChangeWnd_x                                      0xDFE828
#define pinstCRaidOptionsWnd_x                                     0xDFE560
#define pinstCRaidWnd_x                                            0xDFE7E0
#define pinstCRealEstateItemsWnd_x                                 0xDFE7D8
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDFE568
#define pinstCRealEstateManageWnd_x                                0xDFE004
#define pinstCRealEstateNeighborhoodWnd_x                          0xDFE028
#define pinstCRealEstatePlotSearchWnd_x                            0xDFE040
#define pinstCRealEstatePurchaseWnd_x                              0xDFE098
#define pinstCRespawnWnd_x                                         0xDFE0B0
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDFE804
#define pinstCSendMoneyWnd_x                                       0xDFDFCC
#define pinstCServerListWnd_x                                      0xDFE0C0
#define pinstCSkillsSelectWnd_x                                    0xDFE844
#define pinstCSkillsWnd_x                                          0xDFE81C
#define pinstCSocialEditWnd_x                                      0xDFE034
#define pinstCSocialWnd_x                                          0xDFE7F0
#define pinstCSpellBookWnd_x                                       0xDFE848
#define pinstCStoryWnd_x                                           0xDFE7A8
#define pinstCTargetOfTargetWnd_x                                  0xF7A778
#define pinstCTargetWnd_x                                          0xDFE0AC
#define pinstCTaskOverlayWnd_x                                     0xDFDFF4
#define pinstCTaskSelectWnd_x                                      0xF7A8D0
#define pinstCTaskManager_x                                        0xCCFB48
#define pinstCTaskTemplateSelectWnd_x                              0xF7A980
#define pinstCTaskWnd_x                                            0xF7AA30
#define pinstCTextEntryWnd_x                                       0xDFE054
#define pinstCTimeLeftWnd_x                                        0xDFE594
#define pinstCTipWndCONTEXT_x                                      0xF7AC34
#define pinstCTipWndOFDAY_x                                        0xF7AC30
#define pinstCTitleWnd_x                                           0xF7ACE0
#define pinstCTrackingWnd_x                                        0xDFDFF0
#define pinstCTradeskillWnd_x                                      0xF7AE48
#define pinstCTradeWnd_x                                           0xDFE7D4
#define pinstCTrainWnd_x                                           0xDFE7D0
#define pinstCTributeBenefitWnd_x                                  0xF7B048
#define pinstCTributeMasterWnd_x                                   0xF7B0F8
#define pinstCTributeTrophyWnd_x                                   0xF7B1A8
#define pinstCVideoModesWnd_x                                      0xDFE598
#define pinstCVoiceMacroWnd_x                                      0xF644A0
#define pinstCVoteResultsWnd_x                                     0xDFE7BC
#define pinstCVoteWnd_x                                            0xDFE7AC
#define pinstCWebManager_x                                         0xF64B1C
#define pinstCZoneGuideWnd_x                                       0xDFDFFC
#define pinstCZonePathWnd_x                                        0xDFE014

#define pinstEQSuiteTextureLoader_x                                0xC9D080
#define pinstItemIconCache_x                                       0xF74008
#define pinstLootFiltersManager_x                                  0xCCF2B8
#define pinstRewardSelectionWnd_x                                  0xF79098

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5AECB0
#define __CastRay2_x                                               0x5AED00
#define __ConvertItemTags_x                                        0x5CA850
#define __CleanItemTags_x                                          0x47D120
#define __DoesFileExist_x                                          0x902D10
#define __EQGetTime_x                                              0x8FF6A0
#define __ExecuteCmd_x                                             0x5A7550
#define __FixHeading_x                                             0x99A530
#define __GameLoop_x                                               0x6BA760
#define __get_bearing_x                                            0x5AE820
#define __get_melee_range_x                                        0x5AEEF0
#define __GetAnimationCache_x                                      0x71F9B0
#define __GetGaugeValueFromEQ_x                                    0x8122A0
#define __GetLabelFromEQ_x                                         0x813D80
#define __GetXTargetType_x                                         0x99BFF0
#define __HandleMouseWheel_x                                       0x6BB620
#define __HeadingDiff_x                                            0x99A5A0
#define __HelpPath_x                                               0xF5F844
#define __LoadFrontEnd_x                                           0x6B7A80
#define __NewUIINI_x                                               0x811F70
#define __ProcessGameEvents_x                                      0x60EC40
#define __ProcessMouseEvent_x                                      0x60E400
#define __SaveColors_x                                             0x551330
#define __STMLToText_x                                             0x93D9E0
#define __ToggleKeyRingItem_x                                      0x514630
#define CMemoryMappedFile__SetFile_x                               0xA89890
#define CrashDetected_x                                            0x6B9520
#define DrawNetStatus_x                                            0x63A720
#define Expansion_HoT_x                                            0xEC1794
#define Teleport_Table_Size_x                                      0xEB07C8
#define Teleport_Table_x                                           0xEB0C30
#define Util__FastTime_x                                           0x8FF270

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490520
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499430
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499200
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493AC0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492F10

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x558EE0
#define AltAdvManager__IsAbilityReady_x                            0x557E10
#define AltAdvManager__GetAAById_x                                 0x558010
#define AltAdvManager__CanTrainAbility_x                           0x558080
#define AltAdvManager__CanSeeAbility_x                             0x5583E0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA370
#define CharacterZoneClient__HasSkill_x                            0x4D5260
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6980
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE690
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BACA0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D92F0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D93D0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D94B0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3480
#define CharacterZoneClient__BardCastBard_x                        0x4C5FE0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAD70
#define CharacterZoneClient__GetEffect_x                           0x4BABE0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C44D0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C45A0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C45F0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4740
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4910
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2B50
#define CharacterZoneClient__FindItemByGuid_x                      0x4D78E0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7360

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E1110
#define CBankWnd__WndNotification_x                                0x6E0EF0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EEA30

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61D1A0
#define CButtonWnd__CButtonWnd_x                                   0x939D90

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70EA90
#define CChatManager__InitContextMenu_x                            0x707BF0
#define CChatManager__FreeChatWindow_x                             0x70D5D0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E88A0
#define CChatManager__SetLockedActiveChatWindow_x                  0x70E710
#define CChatManager__CreateChatWindow_x                           0x70DC10

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E89B0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94E3E0
#define CContextMenu__dCContextMenu_x                              0x94E610
#define CContextMenu__AddMenuItem_x                                0x94E620
#define CContextMenu__RemoveMenuItem_x                             0x94E930
#define CContextMenu__RemoveAllMenuItems_x                         0x94E950
#define CContextMenu__CheckMenuItem_x                              0x94E9D0
#define CContextMenu__SetMenuItem_x                                0x94E850
#define CContextMenu__AddSeparator_x                               0x94E7B0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x94EF70
#define CContextMenuManager__RemoveMenu_x                          0x94EFE0
#define CContextMenuManager__PopupMenu_x                           0x94F0A0
#define CContextMenuManager__Flush_x                               0x94EF10
#define CContextMenuManager__GetMenu_x                             0x49B750
#define CContextMenuManager__CreateDefaultMenu_x                   0x71A0F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DB870
#define CChatService__GetFriendName_x                              0x8DB880

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70F300
#define CChatWindow__Clear_x                                       0x7105C0
#define CChatWindow__WndNotification_x                             0x710D50
#define CChatWindow__AddHistory_x                                  0x70FE80

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94B850
#define CComboWnd__Draw_x                                          0x94AD40
#define CComboWnd__GetCurChoice_x                                  0x94B690
#define CComboWnd__GetListRect_x                                   0x94B200
#define CComboWnd__GetTextRect_x                                   0x94B8C0
#define CComboWnd__InsertChoice_x                                  0x94B390
#define CComboWnd__SetColors_x                                     0x94B360
#define CComboWnd__SetChoice_x                                     0x94B660
#define CComboWnd__GetItemCount_x                                  0x94B6A0
#define CComboWnd__GetCurChoiceText_x                              0x94B6E0
#define CComboWnd__GetChoiceText_x                                 0x94B6B0
#define CComboWnd__InsertChoiceAtIndex_x                           0x94B420

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x717AE0
#define CContainerWnd__vftable_x                                   0xB1038C
#define CContainerWnd__SetContainer_x                              0x719040

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54BD70
#define CDisplay__PreZoneMainUI_x                                  0x54BD80
#define CDisplay__CleanGameUI_x                                    0x5510F0
#define CDisplay__GetClickedActor_x                                0x544090
#define CDisplay__GetUserDefinedColor_x                            0x53C750
#define CDisplay__GetWorldFilePath_x                               0x545B00
#define CDisplay__is3dON_x                                         0x540CF0
#define CDisplay__ReloadUI_x                                       0x54B200
#define CDisplay__WriteTextHD2_x                                   0x540AE0
#define CDisplay__TrueDistance_x                                   0x5477C0
#define CDisplay__SetViewActor_x                                   0x5439B0
#define CDisplay__GetFloorHeight_x                                 0x540DB0
#define CDisplay__SetRenderWindow_x                                0x53F710
#define CDisplay__ToggleScreenshotMode_x                           0x543480

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96E110

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x951950
#define CEditWnd__GetCharIndexPt_x                                 0x952880
#define CEditWnd__GetDisplayString_x                               0x952720
#define CEditWnd__GetHorzOffset_x                                  0x950F80
#define CEditWnd__GetLineForPrintableChar_x                        0x953A20
#define CEditWnd__GetSelStartPt_x                                  0x952B30
#define CEditWnd__GetSTMLSafeText_x                                0x952540
#define CEditWnd__PointFromPrintableChar_x                         0x953650
#define CEditWnd__SelectableCharFromPoint_x                        0x9537C0
#define CEditWnd__SetEditable_x                                    0x952C00
#define CEditWnd__SetWindowTextA_x                                 0x9522C0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FC8A0
#define CEverQuest__ClickedPlayer_x                                0x5EE8B0
#define CEverQuest__CreateTargetIndicator_x                        0x60BED0
#define CEverQuest__DeleteTargetIndicator_x                        0x60BF60
#define CEverQuest__DoTellWindow_x                                 0x4E8A90
#define CEverQuest__OutputTextToLog_x                              0x4E8D10
#define CEverQuest__DropHeldItemOnGround_x                         0x5E38F0
#define CEverQuest__dsp_chat_x                                     0x4E90A0
#define CEverQuest__trimName_x                                     0x6081B0
#define CEverQuest__Emote_x                                        0x5FD100
#define CEverQuest__EnterZone_x                                    0x5F7080
#define CEverQuest__GetBodyTypeDesc_x                              0x601A70
#define CEverQuest__GetClassDesc_x                                 0x6020B0
#define CEverQuest__GetClassThreeLetterCode_x                      0x6026B0
#define CEverQuest__GetDeityDesc_x                                 0x60A810
#define CEverQuest__GetLangDesc_x                                  0x602870
#define CEverQuest__GetRaceDesc_x                                  0x602090
#define CEverQuest__InterpretCmd_x                                 0x60ADE0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E7AF0
#define CEverQuest__LMouseUp_x                                     0x5E5E80
#define CEverQuest__RightClickedOnPlayer_x                         0x5E83D0
#define CEverQuest__RMouseUp_x                                     0x5E6E00
#define CEverQuest__SetGameState_x                                 0x5E3680
#define CEverQuest__UPCNotificationFlush_x                         0x6080B0
#define CEverQuest__IssuePetCommand_x                              0x603C70
#define CEverQuest__ReportSuccessfulHit_x                          0x5FE4F0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x729B00
#define CGaugeWnd__CalcLinesFillRect_x                             0x729B60
#define CGaugeWnd__Draw_x                                          0x729180

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF640
#define CGuild__GetGuildName_x                                     0x4AE720
#define CGuild__GetGuildIndex_x                                    0x4AEAB0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x744F40

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61D560

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x751F80
#define CInvSlotMgr__MoveItem_x                                    0x750C90
#define CInvSlotMgr__SelectSlot_x                                  0x752050

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74F500
#define CInvSlot__SliderComplete_x                                 0x74D260
#define CInvSlot__GetItemBase_x                                    0x74CBE0
#define CInvSlot__UpdateItem_x                                     0x74CD50

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x753AD0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x752C70
#define CInvSlotWnd__HandleLButtonUp_x                             0x753650

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80D590
#define CItemDisplayWnd__UpdateStrings_x                           0x762250
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75BF30
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75C460
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x762850
#define CItemDisplayWnd__AboutToShow_x                             0x761EA0
#define CItemDisplayWnd__WndNotification_x                         0x763940
#define CItemDisplayWnd__RequestConvertItem_x                      0x763400
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x760F00
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x761CC0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8461C0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x767E40

// CLabel 
#define CLabel__Draw_x                                             0x76D810

// CListWnd
#define CListWnd__CListWnd_x                                       0x923EA0
#define CListWnd__dCListWnd_x                                      0x9241C0
#define CListWnd__AddColumn_x                                      0x928640
#define CListWnd__AddColumn1_x                                     0x928690
#define CListWnd__AddLine_x                                        0x928A20
#define CListWnd__AddString_x                                      0x928820
#define CListWnd__CalculateFirstVisibleLine_x                      0x928400
#define CListWnd__CalculateVSBRange_x                              0x9281F0
#define CListWnd__ClearSel_x                                       0x929200
#define CListWnd__ClearAllSel_x                                    0x929260
#define CListWnd__CloseAndUpdateEditWindow_x                       0x929C80
#define CListWnd__Compare_x                                        0x927B20
#define CListWnd__Draw_x                                           0x9242F0
#define CListWnd__DrawColumnSeparators_x                           0x926AF0
#define CListWnd__DrawHeader_x                                     0x926F60
#define CListWnd__DrawItem_x                                       0x927460
#define CListWnd__DrawLine_x                                       0x926C60
#define CListWnd__DrawSeparator_x                                  0x926B90
#define CListWnd__EnableLine_x                                     0x9263C0
#define CListWnd__EnsureVisible_x                                  0x929BA0
#define CListWnd__ExtendSel_x                                      0x929130
#define CListWnd__GetColumnTooltip_x                               0x925F00
#define CListWnd__GetColumnMinWidth_x                              0x925F70
#define CListWnd__GetColumnWidth_x                                 0x925E70
#define CListWnd__GetCurSel_x                                      0x925800
#define CListWnd__GetItemAtPoint_x                                 0x926640
#define CListWnd__GetItemAtPoint1_x                                0x9266B0
#define CListWnd__GetItemData_x                                    0x925880
#define CListWnd__GetItemHeight_x                                  0x925C40
#define CListWnd__GetItemIcon_x                                    0x925A10
#define CListWnd__GetItemRect_x                                    0x9264B0
#define CListWnd__GetItemText_x                                    0x9258C0
#define CListWnd__GetSelList_x                                     0x9292B0
#define CListWnd__GetSeparatorRect_x                               0x9268F0
#define CListWnd__InsertLine_x                                     0x928E10
#define CListWnd__RemoveLine_x                                     0x928F60
#define CListWnd__SetColors_x                                      0x9281C0
#define CListWnd__SetColumnJustification_x                         0x927EF0
#define CListWnd__SetColumnWidth_x                                 0x927E10
#define CListWnd__SetCurSel_x                                      0x929070
#define CListWnd__SetItemColor_x                                   0x929850
#define CListWnd__SetItemData_x                                    0x929810
#define CListWnd__SetItemText_x                                    0x929420
#define CListWnd__ShiftColumnSeparator_x                           0x927FB0
#define CListWnd__Sort_x                                           0x927CA0
#define CListWnd__ToggleSel_x                                      0x9290A0
#define CListWnd__SetColumnsSizable_x                              0x928060
#define CListWnd__SetItemWnd_x                                     0x9296D0
#define CListWnd__GetItemWnd_x                                     0x925A60
#define CListWnd__SetItemIcon_x                                    0x9294A0
#define CListWnd__CalculateCustomWindowPositions_x                 0x928500
#define CListWnd__SetVScrollPos_x                                  0x927DF0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x782FD0
#define CMapViewWnd__GetWorldCoordinates_x                         0x7816E0
#define CMapViewWnd__HandleLButtonDown_x                           0x77E720

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A2EF0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A37D0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A3D00
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A6C90
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A1A50
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AC840
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A2B00

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A9210
#define CPacketScrambler__hton_x                                   0x8A9200

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x943020
#define CSidlManager__FindScreenPieceTemplate_x                    0x943430
#define CSidlManager__FindScreenPieceTemplate1_x                   0x943220
#define CSidlManager__CreateLabel_x                                0x8049E0
#define CSidlManager__CreateXWndFromTemplate_x                     0x946390
#define CSidlManager__CreateXWndFromTemplate1_x                    0x946560
#define CSidlManager__CreateXWnd_x                                 0x804910
#define CSidlManager__CreateHotButtonWnd_x                         0x804EC0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x93FAF0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x93F9F0
#define CSidlScreenWnd__ConvertToRes_x                             0x9650B0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x93F490
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x93F180
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x93F250
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x93F320
#define CSidlScreenWnd__DrawSidlPiece_x                            0x93FF90
#define CSidlScreenWnd__EnableIniStorage_x                         0x940460
#define CSidlScreenWnd__GetSidlPiece_x                             0x940180
#define CSidlScreenWnd__Init1_x                                    0x93ED80
#define CSidlScreenWnd__LoadIniInfo_x                              0x9404B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x941000
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93E190
#define CSidlScreenWnd__StoreIniInfo_x                             0x940B80
#define CSidlScreenWnd__StoreIniVis_x                              0x940EE0
#define CSidlScreenWnd__WndNotification_x                          0x93FEA0
#define CSidlScreenWnd__GetChildItem_x                             0x9403E0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x92FAB0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F5FB8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6818E0
#define CSkillMgr__GetSkillCap_x                                   0x681AC0
#define CSkillMgr__GetNameToken_x                                  0x681060
#define CSkillMgr__IsActivatedSkill_x                              0x6811A0
#define CSkillMgr__IsCombatSkill_x                                 0x6810E0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x94FD60
#define CSliderWnd__SetValue_x                                     0x94FBD0
#define CSliderWnd__SetNumTicks_x                                  0x94FC30

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80AA20

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x958580
#define CStmlWnd__CalculateHSBRange_x                              0x959660
#define CStmlWnd__CalculateVSBRange_x                              0x9595D0
#define CStmlWnd__CanBreakAtCharacter_x                            0x95D990
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95E620
#define CStmlWnd__ForceParseNow_x                                  0x958B20
#define CStmlWnd__GetNextTagPiece_x                                0x95D8F0
#define CStmlWnd__GetSTMLText_x                                    0x503ED0
#define CStmlWnd__GetVisibleText_x                                 0x958B40
#define CStmlWnd__InitializeWindowVariables_x                      0x95E470
#define CStmlWnd__MakeStmlColorTag_x                               0x957BF0
#define CStmlWnd__MakeWndNotificationTag_x                         0x957C60
#define CStmlWnd__SetSTMLText_x                                    0x956CA0
#define CStmlWnd__StripFirstSTMLLines_x                            0x95F720
#define CStmlWnd__UpdateHistoryString_x                            0x95E830

// CTabWnd 
#define CTabWnd__Draw_x                                            0x955DD0
#define CTabWnd__DrawCurrentPage_x                                 0x956500
#define CTabWnd__DrawTab_x                                         0x956220
#define CTabWnd__GetCurrentPage_x                                  0x9555E0
#define CTabWnd__GetPageInnerRect_x                                0x955820
#define CTabWnd__GetTabInnerRect_x                                 0x955760
#define CTabWnd__GetTabRect_x                                      0x955610
#define CTabWnd__InsertPage_x                                      0x955A30
#define CTabWnd__SetPage_x                                         0x9558A0
#define CTabWnd__SetPageRect_x                                     0x955D10
#define CTabWnd__UpdatePage_x                                      0x9560E0
#define CTabWnd__GetPageFromTabIndex_x                             0x956160
#define CTabWnd__GetCurrentTabIndex_x                              0x9555D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x768210
#define CPageWnd__SetTabText_x                                     0x955130

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A92E0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92C970
#define CTextureFont__GetTextExtent_x                              0x92CB30

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B4950
#define CHtmlComponentWnd__ValidateUri_x                           0x746930
#define CHtmlWnd__SetClientCallbacks_x                             0x6225C0
#define CHtmlWnd__AddObserver_x                                    0x6225E0
#define CHtmlWnd__RemoveObserver_x                                 0x622640
#define Window__getProgress_x                                      0x85E9E0
#define Window__getStatus_x                                        0x85EA00
#define Window__getURI_x                                           0x85EA10

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96AB60

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x919B00

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E86E0
#define CXStr__CXStr1_x                                            0x4FEFB0
#define CXStr__CXStr3_x                                            0x8FB7E0
#define CXStr__dCXStr_x                                            0x478670
#define CXStr__operator_equal_x                                    0x8FBA10
#define CXStr__operator_equal1_x                                   0x8FBA50
#define CXStr__operator_plus_equal1_x                              0x8FC4E0
#define CXStr__SetString_x                                         0x8FE3D0
#define CXStr__operator_char_p_x                                   0x8FBF20
#define CXStr__GetChar_x                                           0x8FDD00
#define CXStr__Delete_x                                            0x8FD5D0
#define CXStr__GetUnicode_x                                        0x8FDD70
#define CXStr__GetLength_x                                         0x47D4D0
#define CXStr__Mid_x                                               0x47D4E0
#define CXStr__Insert_x                                            0x8FDDD0
#define CXStr__FindNext_x                                          0x8FDA40

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94E000
#define CXWnd__BringToTop_x                                        0x933240
#define CXWnd__Center_x                                            0x932DC0
#define CXWnd__ClrFocus_x                                          0x932BD0
#define CXWnd__Destroy_x                                           0x932C80
#define CXWnd__DoAllDrawing_x                                      0x92F260
#define CXWnd__DrawChildren_x                                      0x92F230
#define CXWnd__DrawColoredRect_x                                   0x92F6A0
#define CXWnd__DrawTooltip_x                                       0x92DD90
#define CXWnd__DrawTooltipAtPoint_x                                0x92DE50
#define CXWnd__GetBorderFrame_x                                    0x92F500
#define CXWnd__GetChildWndAt_x                                     0x9332E0
#define CXWnd__GetClientClipRect_x                                 0x9314C0
#define CXWnd__GetScreenClipRect_x                                 0x931590
#define CXWnd__GetScreenRect_x                                     0x931760
#define CXWnd__GetTooltipRect_x                                    0x92F6F0
#define CXWnd__GetWindowTextA_x                                    0x49CE30
#define CXWnd__IsActive_x                                          0x92FE20
#define CXWnd__IsDescendantOf_x                                    0x932130
#define CXWnd__IsReallyVisible_x                                   0x932160
#define CXWnd__IsType_x                                            0x933940
#define CXWnd__Move_x                                              0x9321D0
#define CXWnd__Move1_x                                             0x932280
#define CXWnd__ProcessTransition_x                                 0x932D70
#define CXWnd__Refade_x                                            0x932550
#define CXWnd__Resize_x                                            0x9327E0
#define CXWnd__Right_x                                             0x933000
#define CXWnd__SetFocus_x                                          0x932B90
#define CXWnd__SetFont_x                                           0x932C00
#define CXWnd__SetKeyTooltip_x                                     0x933770
#define CXWnd__SetMouseOver_x                                      0x930650
#define CXWnd__StartFade_x                                         0x932010
#define CXWnd__GetChildItem_x                                      0x933450
#define CXWnd__SetParent_x                                         0x931F00
#define CXWnd__Minimize_x                                          0x932850

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x966130

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9361D0
#define CXWndManager__DrawWindows_x                                0x9361F0
#define CXWndManager__GetKeyboardFlags_x                           0x9389D0
#define CXWndManager__HandleKeyboardMsg_x                          0x938590
#define CXWndManager__RemoveWnd_x                                  0x938C20
#define CXWndManager__RemovePendingDeletionWnd_x                   0x939170

// CDBStr
#define CDBStr__GetString_x                                        0x53B720

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBC80
#define EQ_Character__Cur_HP_x                                     0x4D22A0
#define EQ_Character__Cur_Mana_x                                   0x4D99B0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BECE0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2790
#define EQ_Character__GetFocusRangeModifier_x                      0x4B28E0
#define EQ_Character__GetHPRegen_x                                 0x4DF750
#define EQ_Character__GetEnduranceRegen_x                          0x4DFD50
#define EQ_Character__GetManaRegen_x                               0x4E0190
#define EQ_Character__Max_Endurance_x                              0x648690
#define EQ_Character__Max_HP_x                                     0x4D20D0
#define EQ_Character__Max_Mana_x                                   0x648490
#define EQ_Character__doCombatAbility_x                            0x64AAF0
#define EQ_Character__UseSkill_x                                   0x4E1F70
#define EQ_Character__GetConLevel_x                                0x6416A0
#define EQ_Character__IsExpansionFlag_x                            0x5A5CF0
#define EQ_Character__TotalEffect_x                                0x4C5720
#define EQ_Character__GetPCSpellAffect_x                           0x4BFA30
#define EQ_Character__SpellDuration_x                              0x4BF560
#define EQ_Character__GetAdjustedSkill_x                           0x4D5020
#define EQ_Character__GetBaseSkill_x                               0x4D5FC0
#define EQ_Character__CanUseItem_x                                 0x4D9CC0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C8680

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65EBC0

//PcClient
#define PcClient__PcClient_x                                       0x63EDD0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B98E0
#define CCharacterListWnd__EnterWorld_x                            0x4B9320
#define CCharacterListWnd__Quit_x                                  0x4B9070
#define CCharacterListWnd__UpdateList_x                            0x4B94B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6237E0
#define EQ_Item__CreateItemTagString_x                             0x8A2B20
#define EQ_Item__IsStackable_x                                     0x8A7600
#define EQ_Item__GetImageNum_x                                     0x8A4560
#define EQ_Item__CreateItemClient_x                                0x6229C0
#define EQ_Item__GetItemValue_x                                    0x8A5860
#define EQ_Item__ValueSellMerchant_x                               0x8A8DF0
#define EQ_Item__IsKeyRingItem_x                                   0x8A6F20
#define EQ_Item__CanGoInBag_x                                      0x623900
#define EQ_Item__IsEmpty_x                                         0x8A6A80
#define EQ_Item__GetMaxItemCount_x                                 0x8A5C70
#define EQ_Item__GetHeldItem_x                                     0x8A4430
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A24B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x559C70
#define EQ_LoadingS__Array_x                                       0xC24B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x648FF0
#define EQ_PC__GetAlternateAbilityId_x                             0x8B1FF0
#define EQ_PC__GetCombatAbility_x                                  0x8B2660
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B26D0
#define EQ_PC__GetItemRecastTimer_x                                0x64B070
#define EQ_PC__HasLoreItem_x                                       0x641EB0
#define EQ_PC__AlertInventoryChanged_x                             0x640FD0
#define EQ_PC__GetPcZoneClient_x                                   0x66D670
#define EQ_PC__RemoveMyAffect_x                                    0x64E2A0
#define EQ_PC__GetKeyRingItems_x                                   0x8B2F60
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B2CF0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B3260

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AC280
#define EQItemList__add_object_x                                   0x5D90F0
#define EQItemList__add_item_x                                     0x5AC7E0
#define EQItemList__delete_item_x                                  0x5AC830
#define EQItemList__FreeItemList_x                                 0x5AC730

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x538250

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x660440
#define EQPlayer__dEQPlayer_x                                      0x653780
#define EQPlayer__DoAttack_x                                       0x668320
#define EQPlayer__EQPlayer_x                                       0x653E40
#define EQPlayer__SetNameSpriteState_x                             0x658120
#define EQPlayer__SetNameSpriteTint_x                              0x658FF0
#define PlayerBase__HasProperty_j_x                                0x998900
#define EQPlayer__IsTargetable_x                                   0x998DA0
#define EQPlayer__CanSee_x                                         0x998C00
#define EQPlayer__CanSee1_x                                        0x998CD0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9989C0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66B100
#define PlayerZoneClient__GetLevel_x                               0x66D6B0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DA260
#define PlayerZoneClient__LegalPlayerRace_x                        0x552F20

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x663220
#define EQPlayerManager__GetSpawnByName_x                          0x6632D0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x663360

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x626E00
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x626E80
#define KeypressHandler__AttachKeyToEqCommand_x                    0x626EC0
#define KeypressHandler__ClearCommandStateArray_x                  0x6282D0
#define KeypressHandler__HandleKeyDown_x                           0x6282F0
#define KeypressHandler__HandleKeyUp_x                             0x628390
#define KeypressHandler__SaveKeymapping_x                          0x6287E0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77EE40
#define MapViewMap__SaveEx_x                                       0x782200
#define MapViewMap__SetZoom_x                                      0x7868B0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C65A0

// StringTable 
#define StringTable__getString_x                                   0x8C1170

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64DF10
#define PcZoneClient__RemovePetEffect_x                            0x64E540
#define PcZoneClient__HasAlternateAbility_x                        0x6482C0
#define PcZoneClient__GetCurrentMod_x                              0x4E5030
#define PcZoneClient__GetModCap_x                                  0x4E4F30
#define PcZoneClient__CanEquipItem_x                               0x648990
#define PcZoneClient__GetItemByID_x                                0x64B4E0
#define PcZoneClient__GetItemByItemClass_x                         0x64B630
#define PcZoneClient__RemoveBuffEffect_x                           0x64E560
#define PcZoneClient__BandolierSwap_x                              0x6495B0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64B010

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DEDD0

//IconCache
#define IconCache__GetIcon_x                                       0x71F250

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x716C80
#define CContainerMgr__CloseContainer_x                            0x716F50
#define CContainerMgr__OpenExperimentContainer_x                   0x7179D0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D6E00

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61B990

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7752F0
#define CLootWnd__RequestLootSlot_x                                0x774520

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5796E0
#define EQ_Spell__SpellAffects_x                                   0x579B50
#define EQ_Spell__SpellAffectBase_x                                0x579910
#define EQ_Spell__IsStackable_x                                    0x4C9CF0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9B70
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6C60
#define EQ_Spell__IsSPAStacking_x                                  0x57A9A0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x579EB0
#define EQ_Spell__IsNoRemove_x                                     0x4C9CD0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57A9B0
#define __IsResEffectSpell_x                                       0x4C9160

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD3A0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D0CF0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81DCE0
#define CTargetWnd__WndNotification_x                              0x81D570
#define CTargetWnd__RefreshTargetBuffs_x                           0x81D840
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81C6E0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8222E0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x535CB0
#define CTaskManager__HandleMessage_x                              0x534140
#define CTaskManager__GetTaskStatus_x                              0x535D60
#define CTaskManager__GetElementDescription_x                      0x535DE0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x574C40
#define EqSoundManager__PlayScriptMp3_x                            0x574DA0
#define EqSoundManager__SoundAssistPlay_x                          0x685830
#define EqSoundManager__WaveInstancePlay_x                         0x684DA0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x529A00

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x954640

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x561690
#define CAltAbilityData__GetMercMaxRank_x                          0x561620
#define CAltAbilityData__GetMaxRank_x                              0x556C90

//CTargetRing
#define CTargetRing__Cast_x                                        0x619AB0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9B50
#define CharacterBase__CreateItemGlobalIndex_x                     0x510CD0
#define CharacterBase__CreateItemIndex_x                           0x621B80
#define CharacterBase__GetItemPossession_x                         0x4FC780
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D9300
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D9360
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FDE10
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FE640
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FE6F0

//messages
#define msg_spell_worn_off_x                                       0x59DFF0
#define msg_new_text_x                                             0x592D80
#define __msgTokenTextParam_x                                      0x5A0520
#define msgTokenText_x                                             0x5A0770

//SpellManager
#define SpellManager__vftable_x                                    0xAEA3E0
#define SpellManager__SpellManager_x                               0x688B60
#define Spellmanager__LoadTextSpells_x                             0x689450
#define SpellManager__GetSpellByGroupAndRank_x                     0x688D30

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99C8E0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x511320
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A42D0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63A580
#define ItemGlobalIndex__IsValidIndex_x                            0x511380

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D1690
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D1910

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76DB50

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71B3A0
#define CCursorAttachment__AttachToCursor1_x                       0x71B3E0
#define CCursorAttachment__Deactivate_x                            0x71C3D0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x947380
#define CSidlManagerBase__CreatePageWnd_x                          0x946B90
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x942E40
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x942DD0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9645C0
#define CEQSuiteTextureLoader__GetTexture_x                        0x964280

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50E270
#define CFindItemWnd__WndNotification_x                            0x50ED50
#define CFindItemWnd__Update_x                                     0x50F890
#define CFindItemWnd__PickupSelectedItem_x                         0x50DAB0

//IString
#define IString__Append_x                                          0x4FE070

//Camera
#define CDisplay__cameraType_x                                     0xDFE5A4
#define EverQuest__Cameras_x                                       0xEC1AE4

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5169D0
#define LootFiltersManager__GetItemFilterData_x                    0x5162D0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x516300
#define LootFiltersManager__SetItemLootFilter_x                    0x516520

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C4DE0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A2450
#define CResolutionHandler__GetWindowedStyle_x                     0x6804A0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x713A50

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E5E00
#define CDistillerInfo__Instance_x                                 0x8E5DA0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x733D10
#define CGroupWnd__UpdateDisplay_x                                 0x733070

//ItemBase
#define ItemBase__IsLore_x                                         0x8A6FD0
#define ItemBase__IsLoreEquipped_x                                 0x8A7040

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D9050
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D9190
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D91F0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x675D90
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x679730

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x504620

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F1FE0
#define FactionManagerClient__HandleFactionMessage_x               0x4F2650
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2C50
#define FactionManagerClient__GetMaxFaction_x                      0x4F2C6F
#define FactionManagerClient__GetMinFaction_x                      0x4F2C20

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FC750

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92B920

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C140

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FCA80

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x560B30

//CTargetManager
#define CTargetManager__Get_x                                      0x68C3B0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x675D90

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A90A0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AC6D0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF5F178

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
