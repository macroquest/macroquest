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
#define __ExpectedVersionDate                                     "Dec  5 2019"
#define __ExpectedVersionTime                                     "04:23:32"
#define __ActualVersionDate_x                                      0xB0C4DC
#define __ActualVersionTime_x                                      0xB0C4D0
#define __ActualVersionBuild_x                                     0xAF8194

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x630EF0
#define __MemChecker1_x                                            0x9049B0
#define __MemChecker2_x                                            0x6BF250
#define __MemChecker3_x                                            0x6BF1A0
#define __MemChecker4_x                                            0x85B270
#define __EncryptPad0_x                                            0xC433E8
#define __EncryptPad1_x                                            0xCA15E8
#define __EncryptPad2_x                                            0xC53C80
#define __EncryptPad3_x                                            0xC53880
#define __EncryptPad4_x                                            0xC91C00
#define __EncryptPad5_x                                            0xF6D1D8
#define __AC1_x                                                    0x8180C6
#define __AC2_x                                                    0x5EAC2F
#define __AC3_x                                                    0x5F232F
#define __AC4_x                                                    0x5F6300
#define __AC5_x                                                    0x5FC60F
#define __AC6_x                                                    0x600C16
#define __AC7_x                                                    0x5EA6A0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x191DDC

// Direct Input
#define DI8__Main_x                                                0xF6D200
#define DI8__Keyboard_x                                            0xF6D204
#define DI8__Mouse_x                                               0xF6D1E4
#define DI8__Mouse_Copy_x                                          0xEC63E4
#define DI8__Mouse_Check_x                                         0xF6AD2C
#define __AutoSkillArray_x                                         0xEC72FC
#define __Attack_x                                                 0xF65123
#define __Autofire_x                                               0xF65124
#define __BindList_x                                               0xC31E20
#define g_eqCommandStates_x                                        0xC32BA0
#define __Clicks_x                                                 0xEC649C
#define __CommandList_x                                            0xC33760
#define __CurrentMapLabel_x                                        0xF7DBA4
#define __CurrentSocial_x                                          0xC1B7CC
#define __DoAbilityList_x                                          0xEFCC44
#define __do_loot_x                                                0x5B6540
#define __DrawHandler_x                                            0x15FCF18
#define __GroupCount_x                                             0xEB8D9A
#define __Guilds_x                                                 0xEBCBF0
#define __gWorld_x                                                 0xEB8C50
#define __HWnd_x                                                   0xF6D1E8
#define __heqmain_x                                                0xF6D1C0
#define __InChatMode_x                                             0xEC63CC
#define __LastTell_x                                               0xEC8340
#define __LMouseHeldTime_x                                         0xEC6508
#define __Mouse_x                                                  0xF6D1EC
#define __MouseLook_x                                              0xEC6462
#define __MouseEventTime_x                                         0xF65C04
#define __gpbCommandEvent_x                                        0xEB6688
#define __NetStatusToggle_x                                        0xEC6465
#define __PCNames_x                                                0xEC78EC
#define __RangeAttackReady_x                                       0xEC75E0
#define __RMouseHeldTime_x                                         0xEC6504
#define __RunWalkState_x                                           0xEC63D0
#define __ScreenMode_x                                             0xE044D8
#define __ScreenX_x                                                0xEC6384
#define __ScreenY_x                                                0xEC6380
#define __ScreenXMax_x                                             0xEC6388
#define __ScreenYMax_x                                             0xEC638C
#define __ServerHost_x                                             0xEB6923
#define __ServerName_x                                             0xEFCC04
#define __ShiftKeyDown_x                                           0xEC6A5C
#define __ShowNames_x                                              0xEC779C
#define __Socials_x                                                0xEFCD04
#define __SubscriptionType_x                                       0xFC20A8
#define __TargetAggroHolder_x                                      0xF80558
#define __ZoneType_x                                               0xEC6860
#define __GroupAggro_x                                             0xF80598
#define __LoginName_x                                              0xF6D954
#define __Inviter_x                                                0xF650A0
#define __AttackOnAssist_x                                         0xEC7758
#define __UseTellWindows_x                                         0xEC7A88
#define __gfMaxZoomCameraDistance_x                                0xB01E28
#define __gfMaxCameraDistance_x                                    0xB2E384
#define __pulAutoRun_x                                             0xEC6480
#define __pulForward_x                                             0xEC7AC0
#define __pulBackward_x                                            0xEC7AC4
#define __pulTurnRight_x                                           0xEC7AC8
#define __pulTurnLeft_x                                            0xEC7ACC
#define __pulStrafeLeft_x                                          0xEC7AD0
#define __pulStrafeRight_x                                         0xEC7AD4

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB8F90
#define instEQZoneInfo_x                                           0xEC6658
#define pinstActiveBanker_x                                        0xEB66A0
#define pinstActiveCorpse_x                                        0xEB6698
#define pinstActiveGMaster_x                                       0xEB669C
#define pinstActiveMerchant_x                                      0xEB6694
#define pinstAltAdvManager_x                                       0xE051C8
#define pinstBandageTarget_x                                       0xEB66B0
#define pinstCamActor_x                                            0xE044CC
#define pinstCDBStr_x                                              0xE03EE4
#define pinstCDisplay_x                                            0xEB8C4C
#define pinstCEverQuest_x                                          0xF6D218
#define pinstEverQuestInfo_x                                       0xEC6378
#define pinstCharData_x                                            0xEB8D7C
#define pinstCharSpawn_x                                           0xEB66FC
#define pinstControlledMissile_x                                   0xEB6C3C
#define pinstControlledPlayer_x                                    0xEB66FC
#define pinstCResolutionHandler_x                                  0x15FD148
#define pinstCSidlManager_x                                        0x15FC0E0
#define pinstCXWndManager_x                                        0x15FC0DC
#define instDynamicZone_x                                          0xEBCAC8
#define pinstDZMember_x                                            0xEBCBD8
#define pinstDZTimerInfo_x                                         0xEBCBDC
#define pinstEqLogin_x                                             0xF6D2A0
#define instEQMisc_x                                               0xE03E28
#define pinstEQSoundManager_x                                      0xE06198
#define pinstEQSpellStrings_x                                      0xCC6878
#define instExpeditionLeader_x                                     0xEBCB12
#define instExpeditionName_x                                       0xEBCB52
#define pinstGroup_x                                               0xEB8D96
#define pinstImeManager_x                                          0x15FC0D8
#define pinstLocalPlayer_x                                         0xEB6690
#define pinstMercenaryData_x                                       0xF676F4
#define pinstMercenaryStats_x                                      0xF806A4
#define pinstModelPlayer_x                                         0xEB66A8
#define pinstPCData_x                                              0xEB8D7C
#define pinstSkillMgr_x                                            0xF69860
#define pinstSpawnManager_x                                        0xF68308
#define pinstSpellManager_x                                        0xF69A80
#define pinstSpellSets_x                                           0xF5DD4C
#define pinstStringTable_x                                         0xEB8D80
#define pinstSwitchManager_x                                       0xEB6530
#define pinstTarget_x                                              0xEB66F8
#define pinstTargetObject_x                                        0xEB6704
#define pinstTargetSwitch_x                                        0xEB6C44
#define pinstTaskMember_x                                          0xE03CB8
#define pinstTrackTarget_x                                         0xEB6700
#define pinstTradeTarget_x                                         0xEB66A4
#define instTributeActive_x                                        0xE03E49
#define pinstViewActor_x                                           0xE044C8
#define pinstWorldData_x                                           0xEB6C38
#define pinstZoneAddr_x                                            0xEC68F8
#define pinstPlayerPath_x                                          0xF683A0
#define pinstTargetIndicator_x                                     0xF69CE8
#define EQObject_Top_x                                             0xEB668C
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE047B0
#define pinstCAchievementsWnd_x                                    0xE047AC
#define pinstCActionsWnd_x                                         0xE04774
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE04484
#define pinstCAdvancedLootWnd_x                                    0xE03FB0
#define pinstCAdventureLeaderboardWnd_x                            0xF77378
#define pinstCAdventureRequestWnd_x                                0xF77428
#define pinstCAdventureStatsWnd_x                                  0xF774D8
#define pinstCAggroMeterWnd_x                                      0xE04508
#define pinstCAlarmWnd_x                                           0xE04810
#define pinstCAlertHistoryWnd_x                                    0xE044A0
#define pinstCAlertStackWnd_x                                      0xE04818
#define pinstCAlertWnd_x                                           0xE03F90
#define pinstCAltStorageWnd_x                                      0xF77838
#define pinstCAudioTriggersWindow_x                                0xCB8BA8
#define pinstCAuraWnd_x                                            0xE044C0
#define pinstCAvaZoneWnd_x                                         0xE047E8
#define pinstCBandolierWnd_x                                       0xE04500
#define pinstCBankWnd_x                                            0xE044BC
#define pinstCBarterMerchantWnd_x                                  0xF78A78
#define pinstCBarterSearchWnd_x                                    0xF78B28
#define pinstCBarterWnd_x                                          0xF78BD8
#define pinstCBazaarConfirmationWnd_x                              0xE047D8
#define pinstCBazaarSearchWnd_x                                    0xE0454C
#define pinstCBazaarWnd_x                                          0xE047F8
#define pinstCBlockedBuffWnd_x                                     0xE044C4
#define pinstCBlockedPetBuffWnd_x                                  0xE044FC
#define pinstCBodyTintWnd_x                                        0xE04784
#define pinstCBookWnd_x                                            0xE04528
#define pinstCBreathWnd_x                                          0xE047C8
#define pinstCBuffWindowNORMAL_x                                   0xE044A4
#define pinstCBuffWindowSHORT_x                                    0xE044A8
#define pinstCBugReportWnd_x                                       0xE044B4
#define pinstCButtonWnd_x                                          0x15FC348
#define pinstCCastingWnd_x                                         0xE0451C
#define pinstCCastSpellWnd_x                                       0xE047C4
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE047FC
#define pinstCChatWindowManager_x                                  0xF79698
#define pinstCClaimWnd_x                                           0xF797F0
#define pinstCColorPickerWnd_x                                     0xE0477C
#define pinstCCombatAbilityWnd_x                                   0xE04808
#define pinstCCombatSkillsSelectWnd_x                              0xE03F94
#define pinstCCompassWnd_x                                         0xE04778
#define pinstCConfirmationDialog_x                                 0xF7E6F0
#define pinstCContainerMgr_x                                       0xE047F0
#define pinstCContextMenuManager_x                                 0x15FC098
#define pinstCCursorAttachment_x                                   0xE04510
#define pinstCDynamicZoneWnd_x                                     0xF79DB8
#define pinstCEditLabelWnd_x                                       0xE0449C
#define pinstCEQMainWnd_x                                          0xF7A000
#define pinstCEventCalendarWnd_x                                   0xE04514
#define pinstCExtendedTargetWnd_x                                  0xE044F0
#define pinstCFacePick_x                                           0xE03FA4
#define pinstCFactionWnd_x                                         0xE047EC
#define pinstCFellowshipWnd_x                                      0xF7A200
#define pinstCFileSelectionWnd_x                                   0xE04518
#define pinstCFindItemWnd_x                                        0xE047D4
#define pinstCFindLocationWnd_x                                    0xF7A358
#define pinstCFriendsWnd_x                                         0xE03FAC
#define pinstCGemsGameWnd_x                                        0xE047E4
#define pinstCGiveWnd_x                                            0xE04814
#define pinstCGroupSearchFiltersWnd_x                              0xE04520
#define pinstCGroupSearchWnd_x                                     0xF7A750
#define pinstCGroupWnd_x                                           0xF7A800
#define pinstCGuildBankWnd_x                                       0xEC773C
#define pinstCGuildCreationWnd_x                                   0xF7A960
#define pinstCGuildMgmtWnd_x                                       0xF7AA10
#define pinstCharacterCreation_x                                   0xE03F9C
#define pinstCHelpWnd_x                                            0xE04074
#define pinstCHeritageSelectionWnd_x                               0xE03FB4
#define pinstCHotButtonWnd_x                                       0xF7CB68
#define pinstCHotButtonWnd1_x                                      0xF7CB68
#define pinstCHotButtonWnd2_x                                      0xF7CB6C
#define pinstCHotButtonWnd3_x                                      0xF7CB70
#define pinstCHotButtonWnd4_x                                      0xF7CB74
#define pinstCIconSelectionWnd_x                                   0xE0450C
#define pinstCInspectWnd_x                                         0xE0400C
#define pinstCInventoryWnd_x                                       0xE03FD8
#define pinstCInvSlotMgr_x                                         0xE047A8
#define pinstCItemDisplayManager_x                                 0xF7D0F8
#define pinstCItemExpTransferWnd_x                                 0xF7D228
#define pinstCItemOverflowWnd_x                                    0xE04550
#define pinstCJournalCatWnd_x                                      0xE0452C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE044F4
#define pinstCKeyRingWnd_x                                         0xE04494
#define pinstCLargeDialogWnd_x                                     0xF7F370
#define pinstCLayoutCopyWnd_x                                      0xF7D578
#define pinstCLFGuildWnd_x                                         0xF7D628
#define pinstCLoadskinWnd_x                                        0xE047F4
#define pinstCLootFiltersCopyWnd_x                                 0xCD51C0
#define pinstCLootFiltersWnd_x                                     0xE03F80
#define pinstCLootSettingsWnd_x                                    0xE03FA0
#define pinstCLootWnd_x                                            0xE04530
#define pinstCMailAddressBookWnd_x                                 0xE047B4
#define pinstCMailCompositionWnd_x                                 0xE04794
#define pinstCMailIgnoreListWnd_x                                  0xE047B8
#define pinstCMailWnd_x                                            0xE04770
#define pinstCManageLootWnd_x                                      0xE05678
#define pinstCMapToolbarWnd_x                                      0xE0407C
#define pinstCMapViewWnd_x                                         0xE03FE4
#define pinstCMarketplaceWnd_x                                     0xE03F84
#define pinstCMerchantWnd_x                                        0xE04534
#define pinstCMIZoneSelectWnd_x                                    0xF7DE60
#define pinstCMusicPlayerWnd_x                                     0xE0453C
#define pinstCNameChangeMercWnd_x                                  0xE047D0
#define pinstCNameChangePetWnd_x                                   0xE047BC
#define pinstCNameChangeWnd_x                                      0xE047E0
#define pinstCNoteWnd_x                                            0xE03FE8
#define pinstCObjectPreviewWnd_x                                   0xE03F98
#define pinstCOptionsWnd_x                                         0xE03FEC
#define pinstCPetInfoWnd_x                                         0xE04558
#define pinstCPetitionQWnd_x                                       0xE0479C
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE04788
#define pinstCPlayerWnd_x                                          0xE0455C
#define pinstCPopupWndManager_x                                    0xF7E6F0
#define pinstCProgressionSelectionWnd_x                            0xF7E7A0
#define pinstCPurchaseGroupWnd_x                                   0xE03FF4
#define pinstCPurchaseWnd_x                                        0xE03FDC
#define pinstCPvPLeaderboardWnd_x                                  0xF7E850
#define pinstCPvPStatsWnd_x                                        0xF7E900
#define pinstCQuantityWnd_x                                        0xE044F8
#define pinstCRaceChangeWnd_x                                      0xE0480C
#define pinstCRaidOptionsWnd_x                                     0xE04524
#define pinstCRaidWnd_x                                            0xE04798
#define pinstCRealEstateItemsWnd_x                                 0xE047A4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE04538
#define pinstCRealEstateManageWnd_x                                0xE04078
#define pinstCRealEstateNeighborhoodWnd_x                          0xE04498
#define pinstCRealEstatePlotSearchWnd_x                            0xE044B8
#define pinstCRealEstatePurchaseWnd_x                              0xE044EC
#define pinstCRespawnWnd_x                                         0xE044E8
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE047C0
#define pinstCSendMoneyWnd_x                                       0xE03F8C
#define pinstCServerListWnd_x                                      0xE04504
#define pinstCSkillsSelectWnd_x                                    0xE04800
#define pinstCSkillsWnd_x                                          0xE047DC
#define pinstCSocialEditWnd_x                                      0xE0448C
#define pinstCSocialWnd_x                                          0xE047CC
#define pinstCSpellBookWnd_x                                       0xE04804
#define pinstCStoryWnd_x                                           0xE04560
#define pinstCTargetOfTargetWnd_x                                  0xF80728
#define pinstCTargetWnd_x                                          0xE044E4
#define pinstCTaskOverlayWnd_x                                     0xE03FF0
#define pinstCTaskSelectWnd_x                                      0xF80880
#define pinstCTaskManager_x                                        0xCD5B00
#define pinstCTaskTemplateSelectWnd_x                              0xF80930
#define pinstCTaskWnd_x                                            0xF809E0
#define pinstCTextEntryWnd_x                                       0xE044AC
#define pinstCTimeLeftWnd_x                                        0xE0456C
#define pinstCTipWndCONTEXT_x                                      0xF80BE4
#define pinstCTipWndOFDAY_x                                        0xF80BE0
#define pinstCTitleWnd_x                                           0xF80C90
#define pinstCTrackingWnd_x                                        0xE03FE0
#define pinstCTradeskillWnd_x                                      0xF80DF8
#define pinstCTradeWnd_x                                           0xE04790
#define pinstCTrainWnd_x                                           0xE0478C
#define pinstCTributeBenefitWnd_x                                  0xF80FF8
#define pinstCTributeMasterWnd_x                                   0xF810A8
#define pinstCTributeTrophyWnd_x                                   0xF81158
#define pinstCVideoModesWnd_x                                      0xE04564
#define pinstCVoiceMacroWnd_x                                      0xF6A450
#define pinstCVoteResultsWnd_x                                     0xE047A0
#define pinstCVoteWnd_x                                            0xE04780
#define pinstCWebManager_x                                         0xF6AACC
#define pinstCZoneGuideWnd_x                                       0xE03FF8
#define pinstCZonePathWnd_x                                        0xE04488

#define pinstEQSuiteTextureLoader_x                                0xCA30C0
#define pinstItemIconCache_x                                       0xF79FB8
#define pinstLootFiltersManager_x                                  0xCD5270
#define pinstRewardSelectionWnd_x                                  0xF7F048

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5B19A0
#define __CastRay2_x                                               0x5B19F0
#define __ConvertItemTags_x                                        0x5CD540
#define __CleanItemTags_x                                          0x47D060
#define __DoesFileExist_x                                          0x907A40
#define __EQGetTime_x                                              0x904480
#define __ExecuteCmd_x                                             0x5AA1D0
#define __FixHeading_x                                             0x99EC90
#define __GameLoop_x                                               0x6BE440
#define __get_bearing_x                                            0x5B1510
#define __get_melee_range_x                                        0x5B1BE0
#define __GetAnimationCache_x                                      0x723990
#define __GetGaugeValueFromEQ_x                                    0x816570
#define __GetLabelFromEQ_x                                         0x818050
#define __GetXTargetType_x                                         0x9A06F0
#define __HandleMouseWheel_x                                       0x6BF300
#define __HeadingDiff_x                                            0x99ED00
#define __HelpPath_x                                               0xF657F4
#define __LoadFrontEnd_x                                           0x6BB760
#define __NewUIINI_x                                               0x816240
#define __ProcessGameEvents_x                                      0x6123F0
#define __ProcessMouseEvent_x                                      0x611BB0
#define __SaveColors_x                                             0x552920
#define __STMLToText_x                                             0x941FD0
#define __ToggleKeyRingItem_x                                      0x515BC0
#define CMemoryMappedFile__SetFile_x                               0xA8DCF0
#define CrashDetected_x                                            0x6BD200
#define DrawNetStatus_x                                            0x63E0D0
#define Expansion_HoT_x                                            0xEC7744
#define Teleport_Table_Size_x                                      0xEB678C
#define Teleport_Table_x                                           0xEB6C48
#define Util__FastTime_x                                           0x904050

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4903A0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4992C0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499090
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493940
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D90

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x55A460
#define AltAdvManager__IsAbilityReady_x                            0x559390
#define AltAdvManager__GetAAById_x                                 0x559590
#define AltAdvManager__CanTrainAbility_x                           0x559600
#define AltAdvManager__CanSeeAbility_x                             0x559960

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA210
#define CharacterZoneClient__HasSkill_x                            0x4D5100
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6820
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE4C0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAAC0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D91C0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D92A0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9380
#define CharacterZoneClient__FindAffectSlot_x                      0x4C32C0
#define CharacterZoneClient__BardCastBard_x                        0x4C5E20
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAB90
#define CharacterZoneClient__GetEffect_x                           0x4BAA00
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4310
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C43E0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4430
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4580
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4750
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2910
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7780
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7200

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E4F30
#define CBankWnd__WndNotification_x                                0x6E4D10

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F26D0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x620C30
#define CButtonWnd__CButtonWnd_x                                   0x93E3C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7129E0
#define CChatManager__InitContextMenu_x                            0x70BB30
#define CChatManager__FreeChatWindow_x                             0x711520
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E88C0
#define CChatManager__SetLockedActiveChatWindow_x                  0x712660
#define CChatManager__CreateChatWindow_x                           0x711B60

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E89D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x952AC0
#define CContextMenu__dCContextMenu_x                              0x952D00
#define CContextMenu__AddMenuItem_x                                0x952D10
#define CContextMenu__RemoveMenuItem_x                             0x953020
#define CContextMenu__RemoveAllMenuItems_x                         0x953040
#define CContextMenu__CheckMenuItem_x                              0x9530C0
#define CContextMenu__SetMenuItem_x                                0x952F40
#define CContextMenu__AddSeparator_x                               0x952EA0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x953660
#define CContextMenuManager__RemoveMenu_x                          0x9536D0
#define CContextMenuManager__PopupMenu_x                           0x953790
#define CContextMenuManager__Flush_x                               0x953600
#define CContextMenuManager__GetMenu_x                             0x49B3A0
#define CContextMenuManager__CreateDefaultMenu_x                   0x71E0E0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DFA90
#define CChatService__GetFriendName_x                              0x8DFAA0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x713250
#define CChatWindow__Clear_x                                       0x714510
#define CChatWindow__WndNotification_x                             0x714CA0
#define CChatWindow__AddHistory_x                                  0x713DD0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94FF20
#define CComboWnd__Draw_x                                          0x94F410
#define CComboWnd__GetCurChoice_x                                  0x94FD60
#define CComboWnd__GetListRect_x                                   0x94F8C0
#define CComboWnd__GetTextRect_x                                   0x94FF90
#define CComboWnd__InsertChoice_x                                  0x94FA50
#define CComboWnd__SetColors_x                                     0x94FA20
#define CComboWnd__SetChoice_x                                     0x94FD30
#define CComboWnd__GetItemCount_x                                  0x94FD70
#define CComboWnd__GetCurChoiceText_x                              0x94FDB0
#define CComboWnd__GetChoiceText_x                                 0x94FD80
#define CComboWnd__InsertChoiceAtIndex_x                           0x94FAF0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71BAC0
#define CContainerWnd__vftable_x                                   0xB156CC
#define CContainerWnd__SetContainer_x                              0x71D020

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54D350
#define CDisplay__PreZoneMainUI_x                                  0x54D360
#define CDisplay__CleanGameUI_x                                    0x5526E0
#define CDisplay__GetClickedActor_x                                0x545670
#define CDisplay__GetUserDefinedColor_x                            0x53DD30
#define CDisplay__GetWorldFilePath_x                               0x5470E0
#define CDisplay__is3dON_x                                         0x5422D0
#define CDisplay__ReloadUI_x                                       0x54C7E0
#define CDisplay__WriteTextHD2_x                                   0x5420C0
#define CDisplay__TrueDistance_x                                   0x548DA0
#define CDisplay__SetViewActor_x                                   0x544F90
#define CDisplay__GetFloorHeight_x                                 0x542390
#define CDisplay__SetRenderWindow_x                                0x540CF0
#define CDisplay__ToggleScreenshotMode_x                           0x544A60

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9728E0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x95600F
#define CEditWnd__GetCharIndexPt_x                                 0x956F50
#define CEditWnd__GetDisplayString_x                               0x956DF0
#define CEditWnd__GetHorzOffset_x                                  0x955650
#define CEditWnd__GetLineForPrintableChar_x                        0x9580F0
#define CEditWnd__GetSelStartPt_x                                  0x957200
#define CEditWnd__GetSTMLSafeText_x                                0x956C10
#define CEditWnd__PointFromPrintableChar_x                         0x957D20
#define CEditWnd__SelectableCharFromPoint_x                        0x957E90
#define CEditWnd__SetEditable_x                                    0x9572D0
#define CEditWnd__SetWindowTextA_x                                 0x956990

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x6000F0
#define CEverQuest__ClickedPlayer_x                                0x5F2110
#define CEverQuest__CreateTargetIndicator_x                        0x60F680
#define CEverQuest__DeleteTargetIndicator_x                        0x60F710
#define CEverQuest__DoTellWindow_x                                 0x4E8AB0
#define CEverQuest__OutputTextToLog_x                              0x4E8D30
#define CEverQuest__DropHeldItemOnGround_x                         0x5E7150
#define CEverQuest__dsp_chat_x                                     0x4E90C0
#define CEverQuest__trimName_x                                     0x60B960
#define CEverQuest__Emote_x                                        0x600950
#define CEverQuest__EnterZone_x                                    0x5FA8E0
#define CEverQuest__GetBodyTypeDesc_x                              0x605220
#define CEverQuest__GetClassDesc_x                                 0x605860
#define CEverQuest__GetClassThreeLetterCode_x                      0x605E60
#define CEverQuest__GetDeityDesc_x                                 0x60DFC0
#define CEverQuest__GetLangDesc_x                                  0x606020
#define CEverQuest__GetRaceDesc_x                                  0x605840
#define CEverQuest__InterpretCmd_x                                 0x60E590
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EB350
#define CEverQuest__LMouseUp_x                                     0x5E96E0
#define CEverQuest__RightClickedOnPlayer_x                         0x5EBC30
#define CEverQuest__RMouseUp_x                                     0x5EA660
#define CEverQuest__SetGameState_x                                 0x5E6EE0
#define CEverQuest__UPCNotificationFlush_x                         0x60B860
#define CEverQuest__IssuePetCommand_x                              0x607420
#define CEverQuest__ReportSuccessfulHit_x                          0x601CA0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72DC40
#define CGaugeWnd__CalcLinesFillRect_x                             0x72DCA0
#define CGaugeWnd__Draw_x                                          0x72D2C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF310
#define CGuild__GetGuildName_x                                     0x4AE3F0
#define CGuild__GetGuildIndex_x                                    0x4AE780

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7490B0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x620FF0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7560F0
#define CInvSlotMgr__MoveItem_x                                    0x754E00
#define CInvSlotMgr__SelectSlot_x                                  0x7561C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x753680
#define CInvSlot__SliderComplete_x                                 0x7513D0
#define CInvSlot__GetItemBase_x                                    0x750D40
#define CInvSlot__UpdateItem_x                                     0x750EB0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x757C40
#define CInvSlotWnd__CInvSlotWnd_x                                 0x756DE0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7577C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x811900
#define CItemDisplayWnd__UpdateStrings_x                           0x766360
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x760040
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x760570
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x766970
#define CItemDisplayWnd__AboutToShow_x                             0x765FB0
#define CItemDisplayWnd__WndNotification_x                         0x767A60
#define CItemDisplayWnd__RequestConvertItem_x                      0x767520
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x765010
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x765DD0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x84A280

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76BFA0

// CLabel 
#define CLabel__Draw_x                                             0x771980

// CListWnd
#define CListWnd__CListWnd_x                                       0x928470
#define CListWnd__dCListWnd_x                                      0x928790
#define CListWnd__AddColumn_x                                      0x92CC00
#define CListWnd__AddColumn1_x                                     0x92CC50
#define CListWnd__AddLine_x                                        0x92CFE0
#define CListWnd__AddString_x                                      0x92CDE0
#define CListWnd__CalculateFirstVisibleLine_x                      0x92C9C0
#define CListWnd__CalculateVSBRange_x                              0x92C7A0
#define CListWnd__ClearSel_x                                       0x92D7C0
#define CListWnd__ClearAllSel_x                                    0x92D820
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92E240
#define CListWnd__Compare_x                                        0x92C0D0
#define CListWnd__Draw_x                                           0x9288C0
#define CListWnd__DrawColumnSeparators_x                           0x92B0B0
#define CListWnd__DrawHeader_x                                     0x92B510
#define CListWnd__DrawItem_x                                       0x92BA10
#define CListWnd__DrawLine_x                                       0x92B210
#define CListWnd__DrawSeparator_x                                  0x92B150
#define CListWnd__EnableLine_x                                     0x92A990
#define CListWnd__EnsureVisible_x                                  0x92E160
#define CListWnd__ExtendSel_x                                      0x92D6F0
#define CListWnd__GetColumnTooltip_x                               0x92A4D0
#define CListWnd__GetColumnMinWidth_x                              0x92A540
#define CListWnd__GetColumnWidth_x                                 0x92A440
#define CListWnd__GetCurSel_x                                      0x929DD0
#define CListWnd__GetItemAtPoint_x                                 0x92AC00
#define CListWnd__GetItemAtPoint1_x                                0x92AC70
#define CListWnd__GetItemData_x                                    0x929E50
#define CListWnd__GetItemHeight_x                                  0x92A210
#define CListWnd__GetItemIcon_x                                    0x929FE0
#define CListWnd__GetItemRect_x                                    0x92AA80
#define CListWnd__GetItemText_x                                    0x929E90
#define CListWnd__GetSelList_x                                     0x92D870
#define CListWnd__GetSeparatorRect_x                               0x92AEB0
#define CListWnd__InsertLine_x                                     0x92D3D0
#define CListWnd__RemoveLine_x                                     0x92D520
#define CListWnd__SetColors_x                                      0x92C770
#define CListWnd__SetColumnJustification_x                         0x92C4A0
#define CListWnd__SetColumnWidth_x                                 0x92C3C0
#define CListWnd__SetCurSel_x                                      0x92D630
#define CListWnd__SetItemColor_x                                   0x92DE10
#define CListWnd__SetItemData_x                                    0x92DDD0
#define CListWnd__SetItemText_x                                    0x92D9E0
#define CListWnd__ShiftColumnSeparator_x                           0x92C560
#define CListWnd__Sort_x                                           0x92C250
#define CListWnd__ToggleSel_x                                      0x92D660
#define CListWnd__SetColumnsSizable_x                              0x92C610
#define CListWnd__SetItemWnd_x                                     0x92DC90
#define CListWnd__GetItemWnd_x                                     0x92A030
#define CListWnd__SetItemIcon_x                                    0x92DA60
#define CListWnd__CalculateCustomWindowPositions_x                 0x92CAC0
#define CListWnd__SetVScrollPos_x                                  0x92C3A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x787160
#define CMapViewWnd__GetWorldCoordinates_x                         0x785870
#define CMapViewWnd__HandleLButtonDown_x                           0x7828B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A7260
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A7B40
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A8070
#define CMerchantWnd__SelectRecoverySlot_x                         0x7AB000
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A5DD0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7B0BC0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A6E80

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AD580
#define CPacketScrambler__hton_x                                   0x8AD570

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x947640
#define CSidlManager__FindScreenPieceTemplate_x                    0x947A50
#define CSidlManager__FindScreenPieceTemplate1_x                   0x947840
#define CSidlManager__CreateLabel_x                                0x808D20
#define CSidlManager__CreateXWndFromTemplate_x                     0x94A9B0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x94AB90
#define CSidlManager__CreateXWnd_x                                 0x808C50
#define CSidlManager__CreateHotButtonWnd_x                         0x809220

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x944100
#define CSidlScreenWnd__CalculateVSBRange_x                        0x944000
#define CSidlScreenWnd__ConvertToRes_x                             0x969920
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x943A90
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x943780
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x943850
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x943920
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9445A0
#define CSidlScreenWnd__EnableIniStorage_x                         0x944A70
#define CSidlScreenWnd__GetSidlPiece_x                             0x944790
#define CSidlScreenWnd__Init1_x                                    0x943380
#define CSidlScreenWnd__LoadIniInfo_x                              0x944AC0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x945620
#define CSidlScreenWnd__LoadSidlScreen_x                           0x942780
#define CSidlScreenWnd__StoreIniInfo_x                             0x945190
#define CSidlScreenWnd__StoreIniVis_x                              0x945500
#define CSidlScreenWnd__WndNotification_x                          0x9444B0
#define CSidlScreenWnd__GetChildItem_x                             0x9449F0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9340A0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FBF68

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x685620
#define CSkillMgr__GetSkillCap_x                                   0x685800
#define CSkillMgr__GetNameToken_x                                  0x684DA0
#define CSkillMgr__IsActivatedSkill_x                              0x684EE0
#define CSkillMgr__IsCombatSkill_x                                 0x684E20

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x954430
#define CSliderWnd__SetValue_x                                     0x9542A0
#define CSliderWnd__SetNumTicks_x                                  0x954300

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80ED90

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95CC50
#define CStmlWnd__CalculateHSBRange_x                              0x95DDB0
#define CStmlWnd__CalculateVSBRange_x                              0x95DD30
#define CStmlWnd__CanBreakAtCharacter_x                            0x9620E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x962D70
#define CStmlWnd__ForceParseNow_x                                  0x95D290
#define CStmlWnd__GetNextTagPiece_x                                0x962040
#define CStmlWnd__GetSTMLText_x                                    0x505500
#define CStmlWnd__GetVisibleText_x                                 0x95D2B0
#define CStmlWnd__InitializeWindowVariables_x                      0x962BC0
#define CStmlWnd__MakeStmlColorTag_x                               0x95C2C0
#define CStmlWnd__MakeWndNotificationTag_x                         0x95C330
#define CStmlWnd__SetSTMLText_x                                    0x95B370
#define CStmlWnd__StripFirstSTMLLines_x                            0x963E40
#define CStmlWnd__UpdateHistoryString_x                            0x962F80

// CTabWnd 
#define CTabWnd__Draw_x                                            0x95A4B0
#define CTabWnd__DrawCurrentPage_x                                 0x95ABE0
#define CTabWnd__DrawTab_x                                         0x95A900
#define CTabWnd__GetCurrentPage_x                                  0x959CB0
#define CTabWnd__GetPageInnerRect_x                                0x959EF0
#define CTabWnd__GetTabInnerRect_x                                 0x959E30
#define CTabWnd__GetTabRect_x                                      0x959CE0
#define CTabWnd__InsertPage_x                                      0x95A100
#define CTabWnd__SetPage_x                                         0x959F70
#define CTabWnd__SetPageRect_x                                     0x95A3F0
#define CTabWnd__UpdatePage_x                                      0x95A7C0
#define CTabWnd__GetPageFromTabIndex_x                             0x95A840
#define CTabWnd__GetCurrentTabIndex_x                              0x959CA0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76C370
#define CPageWnd__SetTabText_x                                     0x959800

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9020

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x930F30
#define CTextureFont__GetTextExtent_x                              0x9310F0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B8300
#define CHtmlComponentWnd__ValidateUri_x                           0x74AAA0
#define CHtmlWnd__SetClientCallbacks_x                             0x626090
#define CHtmlWnd__AddObserver_x                                    0x6260B0
#define CHtmlWnd__RemoveObserver_x                                 0x626110
#define Window__getProgress_x                                      0x862880
#define Window__getStatus_x                                        0x8628A0
#define Window__getURI_x                                           0x8628B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96F370

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91E030

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8600
#define CXStr__CXStr1_x                                            0x4B6390
#define CXStr__CXStr3_x                                            0x9005C0
#define CXStr__dCXStr_x                                            0x4787D0
#define CXStr__operator_equal_x                                    0x9007F0
#define CXStr__operator_equal1_x                                   0x900830
#define CXStr__operator_plus_equal1_x                              0x9012C0
#define CXStr__SetString_x                                         0x9031B0
#define CXStr__operator_char_p_x                                   0x900D00
#define CXStr__GetChar_x                                           0x902B00
#define CXStr__Delete_x                                            0x9023B0
#define CXStr__GetUnicode_x                                        0x902B70
#define CXStr__GetLength_x                                         0x47D410
#define CXStr__Mid_x                                               0x47D420
#define CXStr__Insert_x                                            0x902BD0
#define CXStr__FindNext_x                                          0x902820

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9526E0
#define CXWnd__BringToTop_x                                        0x9378C0
#define CXWnd__Center_x                                            0x937440
#define CXWnd__ClrFocus_x                                          0x937260
#define CXWnd__Destroy_x                                           0x937300
#define CXWnd__DoAllDrawing_x                                      0x933830
#define CXWnd__DrawChildren_x                                      0x933800
#define CXWnd__DrawColoredRect_x                                   0x933C90
#define CXWnd__DrawTooltip_x                                       0x932340
#define CXWnd__DrawTooltipAtPoint_x                                0x932400
#define CXWnd__GetBorderFrame_x                                    0x933AF0
#define CXWnd__GetChildWndAt_x                                     0x937960
#define CXWnd__GetClientClipRect_x                                 0x935AF0
#define CXWnd__GetScreenClipRect_x                                 0x935BC0
#define CXWnd__GetScreenRect_x                                     0x935D80
#define CXWnd__GetTooltipRect_x                                    0x933CE0
#define CXWnd__GetWindowTextA_x                                    0x49CA90
#define CXWnd__IsActive_x                                          0x934410
#define CXWnd__IsDescendantOf_x                                    0x9367A0
#define CXWnd__IsReallyVisible_x                                   0x9367D0
#define CXWnd__IsType_x                                            0x937FD0
#define CXWnd__Move_x                                              0x936840
#define CXWnd__Move1_x                                             0x936900
#define CXWnd__ProcessTransition_x                                 0x9373F0
#define CXWnd__Refade_x                                            0x936BE0
#define CXWnd__Resize_x                                            0x936E80
#define CXWnd__Right_x                                             0x937680
#define CXWnd__SetFocus_x                                          0x937220
#define CXWnd__SetFont_x                                           0x937290
#define CXWnd__SetKeyTooltip_x                                     0x937DE0
#define CXWnd__SetMouseOver_x                                      0x934C40
#define CXWnd__StartFade_x                                         0x936680
#define CXWnd__GetChildItem_x                                      0x937AD0
#define CXWnd__SetParent_x                                         0x936530
#define CXWnd__Minimize_x                                          0x936EF0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x96A9A0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x93A840
#define CXWndManager__DrawWindows_x                                0x93A860
#define CXWndManager__GetKeyboardFlags_x                           0x93D050
#define CXWndManager__HandleKeyboardMsg_x                          0x93CC00
#define CXWndManager__RemoveWnd_x                                  0x93D280
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93D800

// CDBStr
#define CDBStr__GetString_x                                        0x53CCC0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBAA0
#define EQ_Character__Cur_HP_x                                     0x4D2140
#define EQ_Character__Cur_Mana_x                                   0x4D9880
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEB10
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2550
#define EQ_Character__GetFocusRangeModifier_x                      0x4B26A0
#define EQ_Character__GetHPRegen_x                                 0x4DF650
#define EQ_Character__GetEnduranceRegen_x                          0x4DFC50
#define EQ_Character__GetManaRegen_x                               0x4E0090
#define EQ_Character__Max_Endurance_x                              0x64BDB0
#define EQ_Character__Max_HP_x                                     0x4D1F70
#define EQ_Character__Max_Mana_x                                   0x64BBB0
#define EQ_Character__doCombatAbility_x                            0x64E210
#define EQ_Character__UseSkill_x                                   0x4E1E70
#define EQ_Character__GetConLevel_x                                0x644FB0
#define EQ_Character__IsExpansionFlag_x                            0x5A8980
#define EQ_Character__TotalEffect_x                                0x4C5560
#define EQ_Character__GetPCSpellAffect_x                           0x4BF860
#define EQ_Character__SpellDuration_x                              0x4BF390
#define EQ_Character__GetAdjustedSkill_x                           0x4D4EC0
#define EQ_Character__GetBaseSkill_x                               0x4D5E60
#define EQ_Character__CanUseItem_x                                 0x4D9B90

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CC8E0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x662300

//PcClient
#define PcClient__PcClient_x                                       0x6426F0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9710
#define CCharacterListWnd__EnterWorld_x                            0x4B9150
#define CCharacterListWnd__Quit_x                                  0x4B8EA0
#define CCharacterListWnd__UpdateList_x                            0x4B92E0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6272E0
#define EQ_Item__CreateItemTagString_x                             0x8A6DA0
#define EQ_Item__IsStackable_x                                     0x8AB950
#define EQ_Item__GetImageNum_x                                     0x8A8830
#define EQ_Item__CreateItemClient_x                                0x6264B0
#define EQ_Item__GetItemValue_x                                    0x8A9B60
#define EQ_Item__ValueSellMerchant_x                               0x8AD160
#define EQ_Item__IsKeyRingItem_x                                   0x8AB270
#define EQ_Item__CanGoInBag_x                                      0x627400
#define EQ_Item__IsEmpty_x                                         0x8AADA0
#define EQ_Item__GetMaxItemCount_x                                 0x8A9F70
#define EQ_Item__GetHeldItem_x                                     0x8A8700
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A6710

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55B170
#define EQ_LoadingS__Array_x                                       0xC2AB60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64C710
#define EQ_PC__GetAlternateAbilityId_x                             0x8B6360
#define EQ_PC__GetCombatAbility_x                                  0x8B69D0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B6A40
#define EQ_PC__GetItemRecastTimer_x                                0x64E790
#define EQ_PC__HasLoreItem_x                                       0x6457C0
#define EQ_PC__AlertInventoryChanged_x                             0x6448F0
#define EQ_PC__GetPcZoneClient_x                                   0x670DB0
#define EQ_PC__RemoveMyAffect_x                                    0x6519C0
#define EQ_PC__GetKeyRingItems_x                                   0x8B72D0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B7060
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B75D0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AEF00
#define EQItemList__add_object_x                                   0x5DC8E0
#define EQItemList__add_item_x                                     0x5AF460
#define EQItemList__delete_item_x                                  0x5AF4B0
#define EQItemList__FreeItemList_x                                 0x5AF3B0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x539770

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x663B80
#define EQPlayer__dEQPlayer_x                                      0x656EE0
#define EQPlayer__DoAttack_x                                       0x66BA40
#define EQPlayer__EQPlayer_x                                       0x6575A0
#define EQPlayer__SetNameSpriteState_x                             0x65B860
#define EQPlayer__SetNameSpriteTint_x                              0x65C730
#define PlayerBase__HasProperty_j_x                                0x99D0A0
#define EQPlayer__IsTargetable_x                                   0x99D540
#define EQPlayer__CanSee_x                                         0x99D3A0
#define EQPlayer__CanSee1_x                                        0x99D470
#define PlayerBase__GetVisibilityLineSegment_x                     0x99D160

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66E840
#define PlayerZoneClient__GetLevel_x                               0x670DF0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DDA50
#define PlayerZoneClient__LegalPlayerRace_x                        0x554570

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x666950
#define EQPlayerManager__GetSpawnByName_x                          0x666A00
#define EQPlayerManager__GetPlayerFromPartialName_x                0x666A90

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x62A9F0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x62AA70
#define KeypressHandler__AttachKeyToEqCommand_x                    0x62AAB0
#define KeypressHandler__ClearCommandStateArray_x                  0x62BEC0
#define KeypressHandler__HandleKeyDown_x                           0x62BEE0
#define KeypressHandler__HandleKeyUp_x                             0x62BF80
#define KeypressHandler__SaveKeymapping_x                          0x62C3D0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x782FD0
#define MapViewMap__SaveEx_x                                       0x786390
#define MapViewMap__SetZoom_x                                      0x78AA50

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8CA800

// StringTable 
#define StringTable__getString_x                                   0x8C56D0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x651630
#define PcZoneClient__RemovePetEffect_x                            0x651C60
#define PcZoneClient__HasAlternateAbility_x                        0x64B9E0
#define PcZoneClient__GetCurrentMod_x                              0x4E4F30
#define PcZoneClient__GetModCap_x                                  0x4E4E30
#define PcZoneClient__CanEquipItem_x                               0x64C0B0
#define PcZoneClient__GetItemByID_x                                0x64EC00
#define PcZoneClient__GetItemByItemClass_x                         0x64ED50
#define PcZoneClient__RemoveBuffEffect_x                           0x651C80
#define PcZoneClient__BandolierSwap_x                              0x64CCD0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64E730

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E25C0

//IconCache
#define IconCache__GetIcon_x                                       0x723230

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x71AC60
#define CContainerMgr__CloseContainer_x                            0x71AF30
#define CContainerMgr__OpenExperimentContainer_x                   0x71B9B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7DB2B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61F3E0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7794C0
#define CLootWnd__RequestLootSlot_x                                0x7786F0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57B720
#define EQ_Spell__SpellAffects_x                                   0x57BB90
#define EQ_Spell__SpellAffectBase_x                                0x57B950
#define EQ_Spell__IsStackable_x                                    0x4C9B90
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9A70
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6A30
#define EQ_Spell__IsSPAStacking_x                                  0x57C9E0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57BEF0
#define EQ_Spell__IsNoRemove_x                                     0x4C9B70
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57C9F0
#define __IsResEffectSpell_x                                       0x4C8FA0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD050

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D4E40

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x822060
#define CTargetWnd__WndNotification_x                              0x8218F0
#define CTargetWnd__RefreshTargetBuffs_x                           0x821BC0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x820A50

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x826670

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5371E0
#define CTaskManager__HandleMessage_x                              0x535660
#define CTaskManager__GetTaskStatus_x                              0x537290
#define CTaskManager__GetElementDescription_x                      0x537310

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x576BF0
#define EqSoundManager__PlayScriptMp3_x                            0x576D50
#define EqSoundManager__SoundAssistPlay_x                          0x689580
#define EqSoundManager__WaveInstancePlay_x                         0x688AF0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52AFE0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x958D10

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x562C70
#define CAltAbilityData__GetMercMaxRank_x                          0x562C00
#define CAltAbilityData__GetMaxRank_x                              0x558210

//CTargetRing
#define CTargetRing__Cast_x                                        0x61D500

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9A50
#define CharacterBase__CreateItemGlobalIndex_x                     0x512260
#define CharacterBase__CreateItemIndex_x                           0x625640
#define CharacterBase__GetItemPossession_x                         0x4FDFC0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DD450
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DD4B0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x701D40
#define CCastSpellWnd__IsBardSongPlaying_x                         0x702570
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x702620

//messages
#define msg_spell_worn_off_x                                       0x5A0B80
#define msg_new_text_x                                             0x595900
#define __msgTokenTextParam_x                                      0x5A30B0
#define msgTokenText_x                                             0x5A3300

//SpellManager
#define SpellManager__vftable_x                                    0xAEF4E4
#define SpellManager__SpellManager_x                               0x68C8B0
#define Spellmanager__LoadTextSpells_x                             0x68D1A0
#define SpellManager__GetSpellByGroupAndRank_x                     0x68CA80

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9A0FE0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5128B0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A6E80
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63DF30
#define ItemGlobalIndex__IsValidIndex_x                            0x512910

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D57E0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D5A60

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x771CC0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71F380
#define CCursorAttachment__AttachToCursor1_x                       0x71F3C0
#define CCursorAttachment__Deactivate_x                            0x7203B0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94B9F0
#define CSidlManagerBase__CreatePageWnd_x                          0x94B1E0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x947460
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9473F0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x968EC0
#define CEQSuiteTextureLoader__GetTexture_x                        0x968B80

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50F7D0
#define CFindItemWnd__WndNotification_x                            0x5102B0
#define CFindItemWnd__Update_x                                     0x510E20
#define CFindItemWnd__PickupSelectedItem_x                         0x50F010

//IString
#define IString__Append_x                                          0x4F0B10

//Camera
#define CDisplay__cameraType_x                                     0xE04568
#define EverQuest__Cameras_x                                       0xEC7A94

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x517F50
#define LootFiltersManager__GetItemFilterData_x                    0x517860
#define LootFiltersManager__RemoveItemLootFilter_x                 0x517890
#define LootFiltersManager__SetItemLootFilter_x                    0x517AB0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C9270

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A6AB0
#define CResolutionHandler__GetWindowedStyle_x                     0x684020

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7179B0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8EAB10
#define CDistillerInfo__Instance_x                                 0x8EAAB0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x737E70
#define CGroupWnd__UpdateDisplay_x                                 0x7371C0

//ItemBase
#define ItemBase__IsLore_x                                         0x8AB320
#define ItemBase__IsLoreEquipped_x                                 0x8AB390

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DC840
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DC980
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DC9E0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6794C0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67CE40

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x505B70

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F2830
#define FactionManagerClient__HandleFactionMessage_x               0x4F2EA0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F3490
#define FactionManagerClient__GetMaxFaction_x                      0x4F34AF
#define FactionManagerClient__GetMinFaction_x                      0x4F3460

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FDF90

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92FEE0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BDA0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FE220

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x562120

//CTargetManager
#define CTargetManager__Get_x                                      0x6900F0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6794C0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8DE0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AF350

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF65128

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
