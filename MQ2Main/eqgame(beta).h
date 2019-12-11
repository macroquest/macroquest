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
#define __ExpectedVersionDate                                     "Dec 11 2019"
#define __ExpectedVersionTime                                     "04:23:21"
#define __ActualVersionDate_x                                      0xB0C66C
#define __ActualVersionTime_x                                      0xB0C660
#define __ActualVersionBuild_x                                     0xAF833C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x630AE0
#define __MemChecker1_x                                            0x904990
#define __MemChecker2_x                                            0x6BF5E0
#define __MemChecker3_x                                            0x6BF530
#define __MemChecker4_x                                            0x85B720
#define __EncryptPad0_x                                            0xC433E8
#define __EncryptPad1_x                                            0xCA15E8
#define __EncryptPad2_x                                            0xC53C80
#define __EncryptPad3_x                                            0xC53880
#define __EncryptPad4_x                                            0xC91C00
#define __EncryptPad5_x                                            0xF6D210
#define __AC1_x                                                    0x818276
#define __AC2_x                                                    0x5EA94F
#define __AC3_x                                                    0x5F204F
#define __AC4_x                                                    0x5F6020
#define __AC5_x                                                    0x5FC32F
#define __AC6_x                                                    0x600946
#define __AC7_x                                                    0x5EA3C0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x191E2C

// Direct Input
#define DI8__Main_x                                                0xF6D238
#define DI8__Keyboard_x                                            0xF6D23C
#define DI8__Mouse_x                                               0xF6D21C
#define DI8__Mouse_Copy_x                                          0xEC641C
#define DI8__Mouse_Check_x                                         0xF6AD64
#define __AutoSkillArray_x                                         0xEC7334
#define __Attack_x                                                 0xF6515B
#define __Autofire_x                                               0xF6515C
#define __BindList_x                                               0xC31E20
#define g_eqCommandStates_x                                        0xC32BA0
#define __Clicks_x                                                 0xEC64D4
#define __CommandList_x                                            0xC33760
#define __CurrentMapLabel_x                                        0xF7DBDC
#define __CurrentSocial_x                                          0xC1B7CC
#define __DoAbilityList_x                                          0xEFCC7C
#define __do_loot_x                                                0x5B6310
#define __DrawHandler_x                                            0x15FCF50
#define __GroupCount_x                                             0xEB8DD2
#define __Guilds_x                                                 0xEBCC28
#define __gWorld_x                                                 0xEB8C88
#define __HWnd_x                                                   0xF6D220
#define __heqmain_x                                                0xF6D1F8
#define __InChatMode_x                                             0xEC6404
#define __LastTell_x                                               0xEC8378
#define __LMouseHeldTime_x                                         0xEC6540
#define __Mouse_x                                                  0xF6D224
#define __MouseLook_x                                              0xEC649A
#define __MouseEventTime_x                                         0xF65C3C
#define __gpbCommandEvent_x                                        0xEB66C0
#define __NetStatusToggle_x                                        0xEC649D
#define __PCNames_x                                                0xEC7924
#define __RangeAttackReady_x                                       0xEC7618
#define __RMouseHeldTime_x                                         0xEC653C
#define __RunWalkState_x                                           0xEC6408
#define __ScreenMode_x                                             0xE040A0
#define __ScreenX_x                                                0xEC63BC
#define __ScreenY_x                                                0xEC63B8
#define __ScreenXMax_x                                             0xEC63C0
#define __ScreenYMax_x                                             0xEC63C4
#define __ServerHost_x                                             0xEB68F3
#define __ServerName_x                                             0xEFCC3C
#define __ShiftKeyDown_x                                           0xEC6A94
#define __ShowNames_x                                              0xEC77D4
#define __Socials_x                                                0xEFCD3C
#define __SubscriptionType_x                                       0xFC20E0
#define __TargetAggroHolder_x                                      0xF80590
#define __ZoneType_x                                               0xEC6898
#define __GroupAggro_x                                             0xF805D0
#define __LoginName_x                                              0xF6D98C
#define __Inviter_x                                                0xF650D8
#define __AttackOnAssist_x                                         0xEC7790
#define __UseTellWindows_x                                         0xEC7AC0
#define __gfMaxZoomCameraDistance_x                                0xB01FD0
#define __gfMaxCameraDistance_x                                    0xB2E524
#define __pulAutoRun_x                                             0xEC64B8
#define __pulForward_x                                             0xEC7AF8
#define __pulBackward_x                                            0xEC7AFC
#define __pulTurnRight_x                                           0xEC7B00
#define __pulTurnLeft_x                                            0xEC7B04
#define __pulStrafeLeft_x                                          0xEC7B08
#define __pulStrafeRight_x                                         0xEC7B0C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB8FC8
#define instEQZoneInfo_x                                           0xEC6690
#define pinstActiveBanker_x                                        0xEB66D8
#define pinstActiveCorpse_x                                        0xEB66D0
#define pinstActiveGMaster_x                                       0xEB66D4
#define pinstActiveMerchant_x                                      0xEB66CC
#define pinstAltAdvManager_x                                       0xE05200
#define pinstBandageTarget_x                                       0xEB66E8
#define pinstCamActor_x                                            0xE04094
#define pinstCDBStr_x                                              0xE03F1C
#define pinstCDisplay_x                                            0xEB8C84
#define pinstCEverQuest_x                                          0xF6D250
#define pinstEverQuestInfo_x                                       0xEC63B0
#define pinstCharData_x                                            0xEB8DB4
#define pinstCharSpawn_x                                           0xEB6720
#define pinstControlledMissile_x                                   0xEB6C0C
#define pinstControlledPlayer_x                                    0xEB6720
#define pinstCResolutionHandler_x                                  0x15FD180
#define pinstCSidlManager_x                                        0x15FC118
#define pinstCXWndManager_x                                        0x15FC114
#define instDynamicZone_x                                          0xEBCB00
#define pinstDZMember_x                                            0xEBCC10
#define pinstDZTimerInfo_x                                         0xEBCC14
#define pinstEqLogin_x                                             0xF6D2D8
#define instEQMisc_x                                               0xE03E60
#define pinstEQSoundManager_x                                      0xE061D0
#define pinstEQSpellStrings_x                                      0xCC6878
#define instExpeditionLeader_x                                     0xEBCB4A
#define instExpeditionName_x                                       0xEBCB8A
#define pinstGroup_x                                               0xEB8DCE
#define pinstImeManager_x                                          0x15FC110
#define pinstLocalPlayer_x                                         0xEB66C8
#define pinstMercenaryData_x                                       0xF6772C
#define pinstMercenaryStats_x                                      0xF806DC
#define pinstModelPlayer_x                                         0xEB66E0
#define pinstPCData_x                                              0xEB8DB4
#define pinstSkillMgr_x                                            0xF69898
#define pinstSpawnManager_x                                        0xF68340
#define pinstSpellManager_x                                        0xF69AB8
#define pinstSpellSets_x                                           0xF5DD84
#define pinstStringTable_x                                         0xEB8DB8
#define pinstSwitchManager_x                                       0xEB6568
#define pinstTarget_x                                              0xEB671C
#define pinstTargetObject_x                                        0xEB67A8
#define pinstTargetSwitch_x                                        0xEB8C28
#define pinstTaskMember_x                                          0xE03CF0
#define pinstTrackTarget_x                                         0xEB6724
#define pinstTradeTarget_x                                         0xEB66DC
#define instTributeActive_x                                        0xE03E81
#define pinstViewActor_x                                           0xE04090
#define pinstWorldData_x                                           0xEB6C08
#define pinstZoneAddr_x                                            0xEC6930
#define pinstPlayerPath_x                                          0xF683D8
#define pinstTargetIndicator_x                                     0xF69D20
#define EQObject_Top_x                                             0xEB66C4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE047F0
#define pinstCAchievementsWnd_x                                    0xE047EC
#define pinstCActionsWnd_x                                         0xE047B4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE04024
#define pinstCAdvancedLootWnd_x                                    0xE03FE4
#define pinstCAdventureLeaderboardWnd_x                            0xF773B0
#define pinstCAdventureRequestWnd_x                                0xF77460
#define pinstCAdventureStatsWnd_x                                  0xF77510
#define pinstCAggroMeterWnd_x                                      0xE04144
#define pinstCAlarmWnd_x                                           0xE0484C
#define pinstCAlertHistoryWnd_x                                    0xE04044
#define pinstCAlertStackWnd_x                                      0xE03FB8
#define pinstCAlertWnd_x                                           0xE03FC8
#define pinstCAltStorageWnd_x                                      0xF77870
#define pinstCAudioTriggersWindow_x                                0xCB8BA8
#define pinstCAuraWnd_x                                            0xE04068
#define pinstCAvaZoneWnd_x                                         0xE03FFC
#define pinstCBandolierWnd_x                                       0xE0413C
#define pinstCBankWnd_x                                            0xE04064
#define pinstCBarterMerchantWnd_x                                  0xF78AB0
#define pinstCBarterSearchWnd_x                                    0xF78B60
#define pinstCBarterWnd_x                                          0xF78C10
#define pinstCBazaarConfirmationWnd_x                              0xE04818
#define pinstCBazaarSearchWnd_x                                    0xE0458C
#define pinstCBazaarWnd_x                                          0xE04834
#define pinstCBlockedBuffWnd_x                                     0xE0406C
#define pinstCBlockedPetBuffWnd_x                                  0xE040C4
#define pinstCBodyTintWnd_x                                        0xE047C4
#define pinstCBookWnd_x                                            0xE04568
#define pinstCBreathWnd_x                                          0xE04808
#define pinstCBuffWindowNORMAL_x                                   0xE04048
#define pinstCBuffWindowSHORT_x                                    0xE0404C
#define pinstCBugReportWnd_x                                       0xE0405C
#define pinstCButtonWnd_x                                          0x15FC380
#define pinstCCastingWnd_x                                         0xE0455C
#define pinstCCastSpellWnd_x                                       0xE04804
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE04838
#define pinstCChatWindowManager_x                                  0xF796D0
#define pinstCClaimWnd_x                                           0xF79828
#define pinstCColorPickerWnd_x                                     0xE047BC
#define pinstCCombatAbilityWnd_x                                   0xE04844
#define pinstCCombatSkillsSelectWnd_x                              0xE03FCC
#define pinstCCompassWnd_x                                         0xE047B8
#define pinstCConfirmationDialog_x                                 0xF7E728
#define pinstCContainerMgr_x                                       0xE0482C
#define pinstCContextMenuManager_x                                 0x15FC0D0
#define pinstCCursorAttachment_x                                   0xE04550
#define pinstCDynamicZoneWnd_x                                     0xF79DF0
#define pinstCEditLabelWnd_x                                       0xE04040
#define pinstCEQMainWnd_x                                          0xF7A038
#define pinstCEventCalendarWnd_x                                   0xE04554
#define pinstCExtendedTargetWnd_x                                  0xE040B8
#define pinstCFacePick_x                                           0xE03FDC
#define pinstCFactionWnd_x                                         0xE04828
#define pinstCFellowshipWnd_x                                      0xF7A238
#define pinstCFileSelectionWnd_x                                   0xE04558
#define pinstCFindItemWnd_x                                        0xE04814
#define pinstCFindLocationWnd_x                                    0xF7A390
#define pinstCFriendsWnd_x                                         0xE03FE0
#define pinstCGemsGameWnd_x                                        0xE04824
#define pinstCGiveWnd_x                                            0xE04850
#define pinstCGroupSearchFiltersWnd_x                              0xE04560
#define pinstCGroupSearchWnd_x                                     0xF7A788
#define pinstCGroupWnd_x                                           0xF7A838
#define pinstCGuildBankWnd_x                                       0xEC7774
#define pinstCGuildCreationWnd_x                                   0xF7A998
#define pinstCGuildMgmtWnd_x                                       0xF7AA48
#define pinstCharacterCreation_x                                   0xE03FD4
#define pinstCHelpWnd_x                                            0xE04018
#define pinstCHeritageSelectionWnd_x                               0xE03FE8
#define pinstCHotButtonWnd_x                                       0xF7CBA0
#define pinstCHotButtonWnd1_x                                      0xF7CBA0
#define pinstCHotButtonWnd2_x                                      0xF7CBA4
#define pinstCHotButtonWnd3_x                                      0xF7CBA8
#define pinstCHotButtonWnd4_x                                      0xF7CBAC
#define pinstCIconSelectionWnd_x                                   0xE0454C
#define pinstCInspectWnd_x                                         0xE04014
#define pinstCInventoryWnd_x                                       0xE03FEC
#define pinstCInvSlotMgr_x                                         0xE047E8
#define pinstCItemDisplayManager_x                                 0xF7D130
#define pinstCItemExpTransferWnd_x                                 0xF7D260
#define pinstCItemOverflowWnd_x                                    0xE04590
#define pinstCJournalCatWnd_x                                      0xE0456C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE040BC
#define pinstCKeyRingWnd_x                                         0xE04034
#define pinstCLargeDialogWnd_x                                     0xF7F3A8
#define pinstCLayoutCopyWnd_x                                      0xF7D5B0
#define pinstCLFGuildWnd_x                                         0xF7D660
#define pinstCLoadskinWnd_x                                        0xE04830
#define pinstCLootFiltersCopyWnd_x                                 0xCD51F8
#define pinstCLootFiltersWnd_x                                     0xE03FBC
#define pinstCLootSettingsWnd_x                                    0xE03FD8
#define pinstCLootWnd_x                                            0xE04570
#define pinstCMailAddressBookWnd_x                                 0xE047F4
#define pinstCMailCompositionWnd_x                                 0xE047D4
#define pinstCMailIgnoreListWnd_x                                  0xE047F8
#define pinstCMailWnd_x                                            0xE047B0
#define pinstCManageLootWnd_x                                      0xE056B0
#define pinstCMapToolbarWnd_x                                      0xE04020
#define pinstCMapViewWnd_x                                         0xE03FF8
#define pinstCMarketplaceWnd_x                                     0xE03FC0
#define pinstCMerchantWnd_x                                        0xE04574
#define pinstCMIZoneSelectWnd_x                                    0xF7DE98
#define pinstCMusicPlayerWnd_x                                     0xE04588
#define pinstCNameChangeMercWnd_x                                  0xE04810
#define pinstCNameChangePetWnd_x                                   0xE047FC
#define pinstCNameChangeWnd_x                                      0xE04820
#define pinstCNoteWnd_x                                            0xE04000
#define pinstCObjectPreviewWnd_x                                   0xE03FD0
#define pinstCOptionsWnd_x                                         0xE04004
#define pinstCPetInfoWnd_x                                         0xE04598
#define pinstCPetitionQWnd_x                                       0xE047DC
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE047C8
#define pinstCPlayerWnd_x                                          0xE0459C
#define pinstCPopupWndManager_x                                    0xF7E728
#define pinstCProgressionSelectionWnd_x                            0xF7E7D8
#define pinstCPurchaseGroupWnd_x                                   0xE0400C
#define pinstCPurchaseWnd_x                                        0xE03FF0
#define pinstCPvPLeaderboardWnd_x                                  0xF7E888
#define pinstCPvPStatsWnd_x                                        0xF7E938
#define pinstCQuantityWnd_x                                        0xE040C0
#define pinstCRaceChangeWnd_x                                      0xE04848
#define pinstCRaidOptionsWnd_x                                     0xE04564
#define pinstCRaidWnd_x                                            0xE047D8
#define pinstCRealEstateItemsWnd_x                                 0xE047E4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE04578
#define pinstCRealEstateManageWnd_x                                0xE0401C
#define pinstCRealEstateNeighborhoodWnd_x                          0xE04038
#define pinstCRealEstatePlotSearchWnd_x                            0xE04060
#define pinstCRealEstatePurchaseWnd_x                              0xE040B4
#define pinstCRespawnWnd_x                                         0xE040B0
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE04800
#define pinstCSendMoneyWnd_x                                       0xE03FC4
#define pinstCServerListWnd_x                                      0xE04140
#define pinstCSkillsSelectWnd_x                                    0xE0483C
#define pinstCSkillsWnd_x                                          0xE0481C
#define pinstCSocialEditWnd_x                                      0xE0402C
#define pinstCSocialWnd_x                                          0xE0480C
#define pinstCSpellBookWnd_x                                       0xE04840
#define pinstCStoryWnd_x                                           0xE045A4
#define pinstCTargetOfTargetWnd_x                                  0xF80760
#define pinstCTargetWnd_x                                          0xE040AC
#define pinstCTaskOverlayWnd_x                                     0xE04008
#define pinstCTaskSelectWnd_x                                      0xF808B8
#define pinstCTaskManager_x                                        0xCD5B38
#define pinstCTaskTemplateSelectWnd_x                              0xF80968
#define pinstCTaskWnd_x                                            0xF80A18
#define pinstCTextEntryWnd_x                                       0xE04050
#define pinstCTimeLeftWnd_x                                        0xE045AC
#define pinstCTipWndCONTEXT_x                                      0xF80C1C
#define pinstCTipWndOFDAY_x                                        0xF80C18
#define pinstCTitleWnd_x                                           0xF80CC8
#define pinstCTrackingWnd_x                                        0xE03FF4
#define pinstCTradeskillWnd_x                                      0xF80E30
#define pinstCTradeWnd_x                                           0xE047D0
#define pinstCTrainWnd_x                                           0xE047CC
#define pinstCTributeBenefitWnd_x                                  0xF81030
#define pinstCTributeMasterWnd_x                                   0xF810E0
#define pinstCTributeTrophyWnd_x                                   0xF81190
#define pinstCVideoModesWnd_x                                      0xE045A0
#define pinstCVoiceMacroWnd_x                                      0xF6A488
#define pinstCVoteResultsWnd_x                                     0xE047E0
#define pinstCVoteWnd_x                                            0xE047C0
#define pinstCWebManager_x                                         0xF6AB04
#define pinstCZoneGuideWnd_x                                       0xE04010
#define pinstCZonePathWnd_x                                        0xE04028

#define pinstEQSuiteTextureLoader_x                                0xCA30C0
#define pinstItemIconCache_x                                       0xF79FF0
#define pinstLootFiltersManager_x                                  0xCD52A8
#define pinstRewardSelectionWnd_x                                  0xF7F080

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5B1770
#define __CastRay2_x                                               0x5B17C0
#define __ConvertItemTags_x                                        0x5CD320
#define __CleanItemTags_x                                          0x47D050
#define __DoesFileExist_x                                          0x907A20
#define __EQGetTime_x                                              0x904460
#define __ExecuteCmd_x                                             0x5A9FC0
#define __FixHeading_x                                             0x99F120
#define __GameLoop_x                                               0x6BE7D0
#define __get_bearing_x                                            0x5B12E0
#define __get_melee_range_x                                        0x5B19B0
#define __GetAnimationCache_x                                      0x7239A0
#define __GetGaugeValueFromEQ_x                                    0x816720
#define __GetLabelFromEQ_x                                         0x818200
#define __GetXTargetType_x                                         0x9A0BE0
#define __HandleMouseWheel_x                                       0x6BF690
#define __HeadingDiff_x                                            0x99F190
#define __HelpPath_x                                               0xF6582C
#define __LoadFrontEnd_x                                           0x6BBAF0
#define __NewUIINI_x                                               0x8163F0
#define __ProcessGameEvents_x                                      0x612110
#define __ProcessMouseEvent_x                                      0x6118D0
#define __SaveColors_x                                             0x5538F0
#define __STMLToText_x                                             0x942610
#define __ToggleKeyRingItem_x                                      0x516A90
#define CMemoryMappedFile__SetFile_x                               0xA8E7A0
#define CrashDetected_x                                            0x6BD590
#define DrawNetStatus_x                                            0x63DF30
#define Expansion_HoT_x                                            0xEC777C
#define Teleport_Table_Size_x                                      0xEB67B0
#define Teleport_Table_x                                           0xEB6C28
#define Util__FastTime_x                                           0x904030

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4902E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4991F0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498FC0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493880
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492CD0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x55B470
#define AltAdvManager__IsAbilityReady_x                            0x55A3A0
#define AltAdvManager__GetAAById_x                                 0x55A5A0
#define AltAdvManager__CanTrainAbility_x                           0x55A610
#define AltAdvManager__CanSeeAbility_x                             0x55A970

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA1D0
#define CharacterZoneClient__HasSkill_x                            0x4D50C0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D67E0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE3A0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA9A0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D91A0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9280
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9360
#define CharacterZoneClient__FindAffectSlot_x                      0x4C31A0
#define CharacterZoneClient__BardCastBard_x                        0x4C5D00
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAA70
#define CharacterZoneClient__GetEffect_x                           0x4BA8E0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C41F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C42C0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4310
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4460
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4630
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B27F0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7740
#define CharacterZoneClient__FindItemByRecord_x                    0x4D71C0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E5110
#define CBankWnd__WndNotification_x                                0x6E4EF0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F29F0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x6208C0
#define CButtonWnd__CButtonWnd_x                                   0x93EA10

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x712AA0
#define CChatManager__InitContextMenu_x                            0x70BBF0
#define CChatManager__FreeChatWindow_x                             0x7115E0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E88B0
#define CChatManager__SetLockedActiveChatWindow_x                  0x712720
#define CChatManager__CreateChatWindow_x                           0x711C20

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E89C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x953030
#define CContextMenu__dCContextMenu_x                              0x953270
#define CContextMenu__AddMenuItem_x                                0x953280
#define CContextMenu__RemoveMenuItem_x                             0x953590
#define CContextMenu__RemoveAllMenuItems_x                         0x9535B0
#define CContextMenu__CheckMenuItem_x                              0x953630
#define CContextMenu__SetMenuItem_x                                0x9534B0
#define CContextMenu__AddSeparator_x                               0x953410

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x953BD0
#define CContextMenuManager__RemoveMenu_x                          0x953C40
#define CContextMenuManager__PopupMenu_x                           0x953D00
#define CContextMenuManager__Flush_x                               0x953B70
#define CContextMenuManager__GetMenu_x                             0x49B340
#define CContextMenuManager__CreateDefaultMenu_x                   0x71E1A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DFBF0
#define CChatService__GetFriendName_x                              0x8DFC00

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x713310
#define CChatWindow__Clear_x                                       0x7145D0
#define CChatWindow__WndNotification_x                             0x714D60
#define CChatWindow__AddHistory_x                                  0x713E90

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x950490
#define CComboWnd__Draw_x                                          0x94F980
#define CComboWnd__GetCurChoice_x                                  0x9502D0
#define CComboWnd__GetListRect_x                                   0x94FE30
#define CComboWnd__GetTextRect_x                                   0x950500
#define CComboWnd__InsertChoice_x                                  0x94FFC0
#define CComboWnd__SetColors_x                                     0x94FF90
#define CComboWnd__SetChoice_x                                     0x9502A0
#define CComboWnd__GetItemCount_x                                  0x9502E0
#define CComboWnd__GetCurChoiceText_x                              0x950320
#define CComboWnd__GetChoiceText_x                                 0x9502F0
#define CComboWnd__InsertChoiceAtIndex_x                           0x950060

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71BB90
#define CContainerWnd__vftable_x                                   0xB15864
#define CContainerWnd__SetContainer_x                              0x71D0F0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54E320
#define CDisplay__PreZoneMainUI_x                                  0x54E330
#define CDisplay__CleanGameUI_x                                    0x5536B0
#define CDisplay__GetClickedActor_x                                0x546640
#define CDisplay__GetUserDefinedColor_x                            0x53ED00
#define CDisplay__GetWorldFilePath_x                               0x5480B0
#define CDisplay__is3dON_x                                         0x5432A0
#define CDisplay__ReloadUI_x                                       0x54D7B0
#define CDisplay__WriteTextHD2_x                                   0x543090
#define CDisplay__TrueDistance_x                                   0x549D70
#define CDisplay__SetViewActor_x                                   0x545F60
#define CDisplay__GetFloorHeight_x                                 0x543360
#define CDisplay__SetRenderWindow_x                                0x541CC0
#define CDisplay__ToggleScreenshotMode_x                           0x545A30

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x972D30

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9565A0
#define CEditWnd__GetCharIndexPt_x                                 0x9574D0
#define CEditWnd__GetDisplayString_x                               0x957370
#define CEditWnd__GetHorzOffset_x                                  0x955BD0
#define CEditWnd__GetLineForPrintableChar_x                        0x958670
#define CEditWnd__GetSelStartPt_x                                  0x957780
#define CEditWnd__GetSTMLSafeText_x                                0x957190
#define CEditWnd__PointFromPrintableChar_x                         0x9582A0
#define CEditWnd__SelectableCharFromPoint_x                        0x958410
#define CEditWnd__SetEditable_x                                    0x957850
#define CEditWnd__SetWindowTextA_x                                 0x956F10
#define CEditWnd__ReplaceSelection_x                               0x957F10
#define CEditWnd__ReplaceSelection1_x                              0x957E90

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FFE20
#define CEverQuest__ClickedPlayer_x                                0x5F1E30
#define CEverQuest__CreateTargetIndicator_x                        0x60F3A0
#define CEverQuest__DeleteTargetIndicator_x                        0x60F430
#define CEverQuest__DoTellWindow_x                                 0x4E8AA0
#define CEverQuest__OutputTextToLog_x                              0x4E8D20
#define CEverQuest__DropHeldItemOnGround_x                         0x5E6E70
#define CEverQuest__dsp_chat_x                                     0x4E90B0
#define CEverQuest__trimName_x                                     0x60B680
#define CEverQuest__Emote_x                                        0x600680
#define CEverQuest__EnterZone_x                                    0x5FA600
#define CEverQuest__GetBodyTypeDesc_x                              0x604F40
#define CEverQuest__GetClassDesc_x                                 0x605580
#define CEverQuest__GetClassThreeLetterCode_x                      0x605B80
#define CEverQuest__GetDeityDesc_x                                 0x60DCE0
#define CEverQuest__GetLangDesc_x                                  0x605D40
#define CEverQuest__GetRaceDesc_x                                  0x605560
#define CEverQuest__InterpretCmd_x                                 0x60E2B0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EB070
#define CEverQuest__LMouseUp_x                                     0x5E9400
#define CEverQuest__RightClickedOnPlayer_x                         0x5EB950
#define CEverQuest__RMouseUp_x                                     0x5EA380
#define CEverQuest__SetGameState_x                                 0x5E6C00
#define CEverQuest__UPCNotificationFlush_x                         0x60B580
#define CEverQuest__IssuePetCommand_x                              0x607140
#define CEverQuest__ReportSuccessfulHit_x                          0x6019D0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72DAC0
#define CGaugeWnd__CalcLinesFillRect_x                             0x72DB20
#define CGaugeWnd__Draw_x                                          0x72D140

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF300
#define CGuild__GetGuildName_x                                     0x4AE3E0
#define CGuild__GetGuildIndex_x                                    0x4AE770

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x748F30

//CHotButton
#define CHotButton__SetButtonSize_x                                0x620C80

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x755F60
#define CInvSlotMgr__MoveItem_x                                    0x754C70
#define CInvSlotMgr__SelectSlot_x                                  0x756030

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7534F0
#define CInvSlot__SliderComplete_x                                 0x751240
#define CInvSlot__GetItemBase_x                                    0x750BB0
#define CInvSlot__UpdateItem_x                                     0x750D20

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x757AB0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x756C50
#define CInvSlotWnd__HandleLButtonUp_x                             0x757630

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x811AD0
#define CItemDisplayWnd__UpdateStrings_x                           0x766280
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75FF70
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x7604A0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x766890
#define CItemDisplayWnd__AboutToShow_x                             0x765EE0
#define CItemDisplayWnd__WndNotification_x                         0x767980
#define CItemDisplayWnd__RequestConvertItem_x                      0x767440
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x764F40
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x765D00

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x84A5A0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76BEC0

// CLabel 
#define CLabel__Draw_x                                             0x771910

// CListWnd
#define CListWnd__CListWnd_x                                       0x928DA0
#define CListWnd__dCListWnd_x                                      0x9290C0
#define CListWnd__AddColumn_x                                      0x92D500
#define CListWnd__AddColumn1_x                                     0x92D550
#define CListWnd__AddLine_x                                        0x92D8E0
#define CListWnd__AddString_x                                      0x92D6E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x92D2D0
#define CListWnd__CalculateVSBRange_x                              0x92D0D0
#define CListWnd__ClearSel_x                                       0x92E0C0
#define CListWnd__ClearAllSel_x                                    0x92E120
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92EB10
#define CListWnd__Compare_x                                        0x92CA00
#define CListWnd__Draw_x                                           0x9291F0
#define CListWnd__DrawColumnSeparators_x                           0x92B9D0
#define CListWnd__DrawHeader_x                                     0x92BE40
#define CListWnd__DrawItem_x                                       0x92C340
#define CListWnd__DrawLine_x                                       0x92BB40
#define CListWnd__DrawSeparator_x                                  0x92BA70
#define CListWnd__EnableLine_x                                     0x92B2C0
#define CListWnd__EnsureVisible_x                                  0x92EA40
#define CListWnd__ExtendSel_x                                      0x92DFF0
#define CListWnd__GetColumnTooltip_x                               0x92AE00
#define CListWnd__GetColumnMinWidth_x                              0x92AE70
#define CListWnd__GetColumnWidth_x                                 0x92AD70
#define CListWnd__GetCurSel_x                                      0x92A700
#define CListWnd__GetItemAtPoint_x                                 0x92B530
#define CListWnd__GetItemAtPoint1_x                                0x92B5A0
#define CListWnd__GetItemData_x                                    0x92A780
#define CListWnd__GetItemHeight_x                                  0x92AB40
#define CListWnd__GetItemIcon_x                                    0x92A910
#define CListWnd__GetItemRect_x                                    0x92B3B0
#define CListWnd__GetItemText_x                                    0x92A7C0
#define CListWnd__GetSelList_x                                     0x92E170
#define CListWnd__GetSeparatorRect_x                               0x92B7E0
#define CListWnd__InsertLine_x                                     0x92DCD0
#define CListWnd__RemoveLine_x                                     0x92DE20
#define CListWnd__SetColors_x                                      0x92D0A0
#define CListWnd__SetColumnJustification_x                         0x92CDD0
#define CListWnd__SetColumnWidth_x                                 0x92CCF0
#define CListWnd__SetCurSel_x                                      0x92DF30
#define CListWnd__SetItemColor_x                                   0x92E700
#define CListWnd__SetItemData_x                                    0x92E6C0
#define CListWnd__SetItemText_x                                    0x92E2E0
#define CListWnd__ShiftColumnSeparator_x                           0x92CE90
#define CListWnd__Sort_x                                           0x92CB80
#define CListWnd__ToggleSel_x                                      0x92DF60
#define CListWnd__SetColumnsSizable_x                              0x92CF40
#define CListWnd__SetItemWnd_x                                     0x92E590
#define CListWnd__GetItemWnd_x                                     0x92A960
#define CListWnd__SetItemIcon_x                                    0x92E360
#define CListWnd__CalculateCustomWindowPositions_x                 0x92D3C0
#define CListWnd__SetVScrollPos_x                                  0x92CCD0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x787100
#define CMapViewWnd__GetWorldCoordinates_x                         0x785810
#define CMapViewWnd__HandleLButtonDown_x                           0x782850

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A7300
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A7BE0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A8110
#define CMerchantWnd__SelectRecoverySlot_x                         0x7AB0A0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A5E60
#define CMerchantWnd__SelectBuySellSlot_x                          0x7B0C60
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A6F10

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AD620
#define CPacketScrambler__hton_x                                   0x8AD610

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x947C10
#define CSidlManager__FindScreenPieceTemplate_x                    0x948020
#define CSidlManager__FindScreenPieceTemplate1_x                   0x947E10
#define CSidlManager__CreateLabel_x                                0x808E60
#define CSidlManager__CreateXWndFromTemplate_x                     0x94AF80
#define CSidlManager__CreateXWndFromTemplate1_x                    0x94B160
#define CSidlManager__CreateXWnd_x                                 0x808D90
#define CSidlManager__CreateHotButtonWnd_x                         0x809350

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x944720
#define CSidlScreenWnd__CalculateVSBRange_x                        0x944630
#define CSidlScreenWnd__ConvertToRes_x                             0x969D80
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9440C0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x943DB0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x943E80
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x943F50
#define CSidlScreenWnd__DrawSidlPiece_x                            0x944BB0
#define CSidlScreenWnd__EnableIniStorage_x                         0x945080
#define CSidlScreenWnd__GetSidlPiece_x                             0x944DA0
#define CSidlScreenWnd__Init1_x                                    0x9439B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x9450D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x945BF0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x942DC0
#define CSidlScreenWnd__StoreIniInfo_x                             0x945770
#define CSidlScreenWnd__StoreIniVis_x                              0x945AD0
#define CSidlScreenWnd__WndNotification_x                          0x944AC0
#define CSidlScreenWnd__GetChildItem_x                             0x945000
#define CSidlScreenWnd__HandleLButtonUp_x                          0x934880
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FBFA0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x685230
#define CSkillMgr__GetSkillCap_x                                   0x685410
#define CSkillMgr__GetNameToken_x                                  0x6849B0
#define CSkillMgr__IsActivatedSkill_x                              0x684AF0
#define CSkillMgr__IsCombatSkill_x                                 0x684A30

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9549A0
#define CSliderWnd__SetValue_x                                     0x954810
#define CSliderWnd__SetNumTicks_x                                  0x954870

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80EF30

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95D1D0
#define CStmlWnd__CalculateHSBRange_x                              0x95E320
#define CStmlWnd__CalculateVSBRange_x                              0x95E2A0
#define CStmlWnd__CanBreakAtCharacter_x                            0x962650
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9632E0
#define CStmlWnd__ForceParseNow_x                                  0x95D800
#define CStmlWnd__GetNextTagPiece_x                                0x9625B0
#define CStmlWnd__GetSTMLText_x                                    0x506300
#define CStmlWnd__GetVisibleText_x                                 0x95D820
#define CStmlWnd__InitializeWindowVariables_x                      0x963130
#define CStmlWnd__MakeStmlColorTag_x                               0x95C840
#define CStmlWnd__MakeWndNotificationTag_x                         0x95C8B0
#define CStmlWnd__SetSTMLText_x                                    0x95B8F0
#define CStmlWnd__StripFirstSTMLLines_x                            0x9643D0
#define CStmlWnd__UpdateHistoryString_x                            0x9634F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x95AA20
#define CTabWnd__DrawCurrentPage_x                                 0x95B150
#define CTabWnd__DrawTab_x                                         0x95AE70
#define CTabWnd__GetCurrentPage_x                                  0x95A220
#define CTabWnd__GetPageInnerRect_x                                0x95A460
#define CTabWnd__GetTabInnerRect_x                                 0x95A3A0
#define CTabWnd__GetTabRect_x                                      0x95A250
#define CTabWnd__InsertPage_x                                      0x95A670
#define CTabWnd__SetPage_x                                         0x95A4E0
#define CTabWnd__SetPageRect_x                                     0x95A960
#define CTabWnd__UpdatePage_x                                      0x95AD30
#define CTabWnd__GetPageFromTabIndex_x                             0x95ADB0
#define CTabWnd__GetCurrentTabIndex_x                              0x95A210

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76C290
#define CPageWnd__SetTabText_x                                     0x959D60

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8FE0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x931750
#define CTextureFont__GetTextExtent_x                              0x931910

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B8690
#define CHtmlComponentWnd__ValidateUri_x                           0x74A920
#define CHtmlWnd__SetClientCallbacks_x                             0x625D30
#define CHtmlWnd__AddObserver_x                                    0x625D50
#define CHtmlWnd__RemoveObserver_x                                 0x625DB0
#define Window__getProgress_x                                      0x862D00
#define Window__getStatus_x                                        0x862D20
#define Window__getURI_x                                           0x862D30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96F7C0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91E9F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E85F0
#define CXStr__CXStr1_x                                            0x4B6270
#define CXStr__CXStr3_x                                            0x9005A0
#define CXStr__dCXStr_x                                            0x4786A0
#define CXStr__operator_equal_x                                    0x9007D0
#define CXStr__operator_equal1_x                                   0x900810
#define CXStr__operator_plus_equal1_x                              0x9012A0
#define CXStr__SetString_x                                         0x903190
#define CXStr__operator_char_p_x                                   0x900D10
#define CXStr__GetChar_x                                           0x902AE0
#define CXStr__Delete_x                                            0x902390
#define CXStr__GetUnicode_x                                        0x902B50
#define CXStr__GetLength_x                                         0x47D400
#define CXStr__Mid_x                                               0x47D410
#define CXStr__Insert_x                                            0x902BB0
#define CXStr__FindNext_x                                          0x902800

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x952C50
#define CXWnd__BringToTop_x                                        0x937F50
#define CXWnd__Center_x                                            0x937AD0
#define CXWnd__ClrFocus_x                                          0x9378E0
#define CXWnd__Destroy_x                                           0x937990
#define CXWnd__DoAllDrawing_x                                      0x934010
#define CXWnd__DrawChildren_x                                      0x933FE0
#define CXWnd__DrawColoredRect_x                                   0x934470
#define CXWnd__DrawTooltip_x                                       0x932B20
#define CXWnd__DrawTooltipAtPoint_x                                0x932BE0
#define CXWnd__GetBorderFrame_x                                    0x9342D0
#define CXWnd__GetChildWndAt_x                                     0x937FF0
#define CXWnd__GetClientClipRect_x                                 0x936210
#define CXWnd__GetScreenClipRect_x                                 0x9362E0
#define CXWnd__GetScreenRect_x                                     0x9364A0
#define CXWnd__GetTooltipRect_x                                    0x9344C0
#define CXWnd__GetWindowTextA_x                                    0x49CA20
#define CXWnd__IsActive_x                                          0x934BF0
#define CXWnd__IsDescendantOf_x                                    0x936E90
#define CXWnd__IsReallyVisible_x                                   0x936EC0
#define CXWnd__IsType_x                                            0x938640
#define CXWnd__Move_x                                              0x936F20
#define CXWnd__Move1_x                                             0x936FD0
#define CXWnd__ProcessTransition_x                                 0x937A80
#define CXWnd__Refade_x                                            0x937290
#define CXWnd__Resize_x                                            0x937520
#define CXWnd__Right_x                                             0x937D10
#define CXWnd__SetFocus_x                                          0x9378A0
#define CXWnd__SetFont_x                                           0x937910
#define CXWnd__SetKeyTooltip_x                                     0x938460
#define CXWnd__SetMouseOver_x                                      0x9353F0
#define CXWnd__StartFade_x                                         0x936D70
#define CXWnd__GetChildItem_x                                      0x938160
#define CXWnd__SetParent_x                                         0x936C30
#define CXWnd__Minimize_x                                          0x937590

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x96AE00

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x93AE30
#define CXWndManager__DrawWindows_x                                0x93AE50
#define CXWndManager__GetKeyboardFlags_x                           0x93D640
#define CXWndManager__HandleKeyboardMsg_x                          0x93D1F0
#define CXWndManager__RemoveWnd_x                                  0x93D870
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93DDE0

// CDBStr
#define CDBStr__GetString_x                                        0x53DCA0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB980
#define EQ_Character__Cur_HP_x                                     0x4D2100
#define EQ_Character__Cur_Mana_x                                   0x4D9860
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE9F0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2430
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2580
#define EQ_Character__GetHPRegen_x                                 0x4DF630
#define EQ_Character__GetEnduranceRegen_x                          0x4DFC30
#define EQ_Character__GetManaRegen_x                               0x4E0070
#define EQ_Character__Max_Endurance_x                              0x64C0A0
#define EQ_Character__Max_HP_x                                     0x4D1F30
#define EQ_Character__Max_Mana_x                                   0x64BEA0
#define EQ_Character__doCombatAbility_x                            0x64E500
#define EQ_Character__UseSkill_x                                   0x4E1E50
#define EQ_Character__GetConLevel_x                                0x644E70
#define EQ_Character__IsExpansionFlag_x                            0x5A8750
#define EQ_Character__TotalEffect_x                                0x4C5440
#define EQ_Character__GetPCSpellAffect_x                           0x4BF740
#define EQ_Character__SpellDuration_x                              0x4BF270
#define EQ_Character__GetAdjustedSkill_x                           0x4D4E80
#define EQ_Character__GetBaseSkill_x                               0x4D5E20
#define EQ_Character__CanUseItem_x                                 0x4D9B70

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CCAE0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6625C0

//PcClient
#define PcClient__PcClient_x                                       0x6425B0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B95B0
#define CCharacterListWnd__EnterWorld_x                            0x4B8FF0
#define CCharacterListWnd__Quit_x                                  0x4B8D40
#define CCharacterListWnd__UpdateList_x                            0x4B9180

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x626F60
#define EQ_Item__CreateItemTagString_x                             0x8A6E30
#define EQ_Item__IsStackable_x                                     0x8AB9D0
#define EQ_Item__GetImageNum_x                                     0x8A88C0
#define EQ_Item__CreateItemClient_x                                0x626130
#define EQ_Item__GetItemValue_x                                    0x8A9BF0
#define EQ_Item__ValueSellMerchant_x                               0x8AD200
#define EQ_Item__IsKeyRingItem_x                                   0x8AB2F0
#define EQ_Item__CanGoInBag_x                                      0x627080
#define EQ_Item__IsEmpty_x                                         0x8AAE20
#define EQ_Item__GetMaxItemCount_x                                 0x8AA000
#define EQ_Item__GetHeldItem_x                                     0x8A8790
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A67B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55C140
#define EQ_LoadingS__Array_x                                       0xC2AB60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64CA00
#define EQ_PC__GetAlternateAbilityId_x                             0x8B6400
#define EQ_PC__GetCombatAbility_x                                  0x8B6A70
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B6AE0
#define EQ_PC__GetItemRecastTimer_x                                0x64EA80
#define EQ_PC__HasLoreItem_x                                       0x645630
#define EQ_PC__AlertInventoryChanged_x                             0x6447B0
#define EQ_PC__GetPcZoneClient_x                                   0x671070
#define EQ_PC__RemoveMyAffect_x                                    0x651CB0
#define EQ_PC__GetKeyRingItems_x                                   0x8B7370
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B7100
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B7670

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AECF0
#define EQItemList__add_object_x                                   0x5DC650
#define EQItemList__add_item_x                                     0x5AF250
#define EQItemList__delete_item_x                                  0x5AF2A0
#define EQItemList__FreeItemList_x                                 0x5AF1A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53A800

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x663E40
#define EQPlayer__dEQPlayer_x                                      0x657180
#define EQPlayer__DoAttack_x                                       0x66BD00
#define EQPlayer__EQPlayer_x                                       0x657840
#define EQPlayer__SetNameSpriteState_x                             0x65BB20
#define EQPlayer__SetNameSpriteTint_x                              0x65C9F0
#define PlayerBase__HasProperty_j_x                                0x99D530
#define EQPlayer__IsTargetable_x                                   0x99D9D0
#define EQPlayer__CanSee_x                                         0x99D830
#define EQPlayer__CanSee1_x                                        0x99D900
#define PlayerBase__GetVisibilityLineSegment_x                     0x99D5F0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66EB00
#define PlayerZoneClient__GetLevel_x                               0x6710B0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DD7C0
#define PlayerZoneClient__LegalPlayerRace_x                        0x555540

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x666C20
#define EQPlayerManager__GetSpawnByName_x                          0x666CD0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x666D60

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x62A6E0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x62A760
#define KeypressHandler__AttachKeyToEqCommand_x                    0x62A7A0
#define KeypressHandler__ClearCommandStateArray_x                  0x62BBB0
#define KeypressHandler__HandleKeyDown_x                           0x62BBD0
#define KeypressHandler__HandleKeyUp_x                             0x62BC70
#define KeypressHandler__SaveKeymapping_x                          0x62C0C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x782F70
#define MapViewMap__SaveEx_x                                       0x786330
#define MapViewMap__SetZoom_x                                      0x78A9F0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8CA950

// StringTable 
#define StringTable__getString_x                                   0x8C5770

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x651920
#define PcZoneClient__RemovePetEffect_x                            0x651F50
#define PcZoneClient__HasAlternateAbility_x                        0x64BCD0
#define PcZoneClient__GetCurrentMod_x                              0x4E4F10
#define PcZoneClient__GetModCap_x                                  0x4E4E10
#define PcZoneClient__CanEquipItem_x                               0x64C3A0
#define PcZoneClient__GetItemByID_x                                0x64EEF0
#define PcZoneClient__GetItemByItemClass_x                         0x64F040
#define PcZoneClient__RemoveBuffEffect_x                           0x651F70
#define PcZoneClient__BandolierSwap_x                              0x64CFC0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64EA20

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E2280

//IconCache
#define IconCache__GetIcon_x                                       0x723240

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x71AD30
#define CContainerMgr__CloseContainer_x                            0x71B000
#define CContainerMgr__OpenExperimentContainer_x                   0x71BA80

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7DB2B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61F090

//CLootWnd
#define CLootWnd__LootAll_x                                        0x779400
#define CLootWnd__RequestLootSlot_x                                0x778630

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57C230
#define EQ_Spell__SpellAffects_x                                   0x57C6A0
#define EQ_Spell__SpellAffectBase_x                                0x57C460
#define EQ_Spell__IsStackable_x                                    0x4C9B20
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9970
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6910
#define EQ_Spell__IsSPAStacking_x                                  0x57D4F0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57CA00
#define EQ_Spell__IsNoRemove_x                                     0x4C9B00
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57D500
#define __IsResEffectSpell_x                                       0x4C8E80

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD020

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D5070

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x822200
#define CTargetWnd__WndNotification_x                              0x821A90
#define CTargetWnd__RefreshTargetBuffs_x                           0x821D60
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x820C00

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x826800

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x538240
#define CTaskManager__HandleMessage_x                              0x5366E0
#define CTaskManager__GetTaskStatus_x                              0x5382F0
#define CTaskManager__GetElementDescription_x                      0x538370

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5777A0
#define EqSoundManager__PlayScriptMp3_x                            0x577900
#define EqSoundManager__SoundAssistPlay_x                          0x689150
#define EqSoundManager__WaveInstancePlay_x                         0x6886C0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52BAB0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x959270

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x563B00
#define CAltAbilityData__GetMercMaxRank_x                          0x563A90
#define CAltAbilityData__GetMaxRank_x                              0x559220

//CTargetRing
#define CTargetRing__Cast_x                                        0x61D1B0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9950
#define CharacterBase__CreateItemGlobalIndex_x                     0x5130E0
#define CharacterBase__CreateItemIndex_x                           0x6252E0
#define CharacterBase__GetItemPossession_x                         0x4FEC90
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DD680
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DD6E0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x701E80
#define CCastSpellWnd__IsBardSongPlaying_x                         0x7026B0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x702760

//messages
#define msg_spell_worn_off_x                                       0x5A08F0
#define msg_new_text_x                                             0x595660
#define __msgTokenTextParam_x                                      0x5A2E20
#define msgTokenText_x                                             0x5A3070

//SpellManager
#define SpellManager__vftable_x                                    0xAEF68C
#define SpellManager__SpellManager_x                               0x68C480
#define Spellmanager__LoadTextSpells_x                             0x68CD70
#define SpellManager__GetSpellByGroupAndRank_x                     0x68C650

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9A14D0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x513760
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A6C10
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63DD90
#define ItemGlobalIndex__IsValidIndex_x                            0x5137C0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D5A10
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D5C90

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x771C50

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71F440
#define CCursorAttachment__AttachToCursor1_x                       0x71F480
#define CCursorAttachment__Deactivate_x                            0x720470

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94BFB0
#define CSidlManagerBase__CreatePageWnd_x                          0x94B7B0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x947A30
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x9479C0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9691B0
#define CEQSuiteTextureLoader__GetTexture_x                        0x968E70

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x510680
#define CFindItemWnd__WndNotification_x                            0x511160
#define CFindItemWnd__Update_x                                     0x511CD0
#define CFindItemWnd__PickupSelectedItem_x                         0x50FEC0

//IString
#define IString__Append_x                                          0x4F15A0

//Camera
#define CDisplay__cameraType_x                                     0xE045A8
#define EverQuest__Cameras_x                                       0xEC7ACC

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x518E30
#define LootFiltersManager__GetItemFilterData_x                    0x518730
#define LootFiltersManager__RemoveItemLootFilter_x                 0x518760
#define LootFiltersManager__SetItemLootFilter_x                    0x518980

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C9180

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A71F0
#define CResolutionHandler__GetWindowedStyle_x                     0x683DB0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x717A70

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8EAC40
#define CDistillerInfo__Instance_x                                 0x8EABE0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x737CF0
#define CGroupWnd__UpdateDisplay_x                                 0x737040

//ItemBase
#define ItemBase__IsLore_x                                         0x8AB3A0
#define ItemBase__IsLoreEquipped_x                                 0x8AB410

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DC5B0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DC6F0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DC750

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6797A0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67D140

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x506900

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F3490
#define FactionManagerClient__HandleFactionMessage_x               0x4F3B00
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F40C0
#define FactionManagerClient__GetMaxFaction_x                      0x4F40DF
#define FactionManagerClient__GetMinFaction_x                      0x4F4090

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FEC60

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x9307B0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BD30

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FEEF0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x562FA0

//CTargetManager
#define CTargetManager__Get_x                                      0x68FCE0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6797A0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8DA0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AF140

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF65160

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
