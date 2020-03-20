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
#define __ExpectedVersionDate                                     "Mar 16 2020"
#define __ExpectedVersionTime                                     "19:52:24"
#define __ActualVersionDate_x                                      0xB18378
#define __ActualVersionTime_x                                      0xB1836C
#define __ActualVersionBuild_x                                     0xB040DC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x63C9D0
#define __MemChecker1_x                                            0x90FE20
#define __MemChecker2_x                                            0x6CAFF0
#define __MemChecker3_x                                            0x6CAF40
#define __MemChecker4_x                                            0x8665A0
#define __EncryptPad0_x                                            0xC504E8
#define __EncryptPad1_x                                            0xCAE650
#define __EncryptPad2_x                                            0xC60D80
#define __EncryptPad3_x                                            0xC60980
#define __EncryptPad4_x                                            0xC9EC00
#define __EncryptPad5_x                                            0xF6F7DC
#define __AC1_x                                                    0x822CB6
#define __AC2_x                                                    0x5F66EF
#define __AC3_x                                                    0x5FDDEF
#define __AC4_x                                                    0x601DC0
#define __AC5_x                                                    0x6080CF
#define __AC6_x                                                    0x60C5C6
#define __AC7_x                                                    0x5F6160
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x6E178

// Direct Input
#define DI8__Main_x                                                0xF6F7FC
#define DI8__Keyboard_x                                            0xF6F800
#define DI8__Mouse_x                                               0xF6F81C
#define DI8__Mouse_Copy_x                                          0xECAE84
#define DI8__Mouse_Check_x                                         0xF702C8
#define __AutoSkillArray_x                                         0xECBD9C
#define __Attack_x                                                 0xF69BC3
#define __Autofire_x                                               0xF69BC4
#define __BindList_x                                               0xC3EF30
#define g_eqCommandStates_x                                        0xC3FCB0
#define __Clicks_x                                                 0xECAF3C
#define __CommandList_x                                            0xC40870
#define __CurrentMapLabel_x                                        0xF8268C
#define __CurrentSocial_x                                          0xC287CC
#define __DoAbilityList_x                                          0xF016E4
#define __do_loot_x                                                0x5C2150
#define __DrawHandler_x                                            0x1601A08
#define __GroupCount_x                                             0xEC5A1A
#define __Guilds_x                                                 0xEC9DC8
#define __gWorld_x                                                 0xEC5C10
#define __HWnd_x                                                   0xF702A8
#define __heqmain_x                                                0xF7275C
#define __InChatMode_x                                             0xECAE6C
#define __LastTell_x                                               0xECCDE0
#define __LMouseHeldTime_x                                         0xECAFA8
#define __Mouse_x                                                  0xF6F7E8
#define __MouseLook_x                                              0xECAF02
#define __MouseEventTime_x                                         0xF6A6A4
#define __gpbCommandEvent_x                                        0xEC5C1C
#define __NetStatusToggle_x                                        0xECAF05
#define __PCNames_x                                                0xECC38C
#define __RangeAttackReady_x                                       0xECC080
#define __RMouseHeldTime_x                                         0xECAFA4
#define __RunWalkState_x                                           0xECAE70
#define __ScreenMode_x                                             0xE111A8
#define __ScreenX_x                                                0xECAE24
#define __ScreenY_x                                                0xECAE20
#define __ScreenXMax_x                                             0xECAE28
#define __ScreenYMax_x                                             0xECAE2C
#define __ServerHost_x                                             0xEC5E4B
#define __ServerName_x                                             0xF016A4
#define __ShiftKeyDown_x                                           0xECB4FC
#define __ShowNames_x                                              0xECC23C
#define EverQuestInfo__bSocialChanged_x                            0xF0172C
#define __Socials_x                                                0xF017A4
#define __SubscriptionType_x                                       0xFC6B98
#define __TargetAggroHolder_x                                      0xF85040
#define __ZoneType_x                                               0xECB300
#define __GroupAggro_x                                             0xF85080
#define __LoginName_x                                              0xF6FF54
#define __Inviter_x                                                0xF69B40
#define __AttackOnAssist_x                                         0xECC1F8
#define __UseTellWindows_x                                         0xECC528
#define __gfMaxZoomCameraDistance_x                                0xB0DCF0
#define __gfMaxCameraDistance_x                                    0xB3A08C
#define __pulAutoRun_x                                             0xECAF20
#define __pulForward_x                                             0xECC560
#define __pulBackward_x                                            0xECC564
#define __pulTurnRight_x                                           0xECC568
#define __pulTurnLeft_x                                            0xECC56C
#define __pulStrafeLeft_x                                          0xECC570
#define __pulStrafeRight_x                                         0xECC574

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEC6160
#define instEQZoneInfo_x                                           0xECB0F8
#define pinstActiveBanker_x                                        0xEC5CF8
#define pinstActiveCorpse_x                                        0xEC5CF0
#define pinstActiveGMaster_x                                       0xEC5CF4
#define pinstActiveMerchant_x                                      0xEC5CEC
#define pinstAltAdvManager_x                                       0xE12390
#define pinstBandageTarget_x                                       0xEC5D08
#define pinstCamActor_x                                            0xE11198
#define pinstCDBStr_x                                              0xE110AC
#define pinstCDisplay_x                                            0xEC5868
#define pinstCEverQuest_x                                          0xF6F818
#define pinstEverQuestInfo_x                                       0xECAE18
#define pinstCharData_x                                            0xEC5A04
#define pinstCharSpawn_x                                           0xEC5D40
#define pinstControlledMissile_x                                   0xEC3854
#define pinstControlledPlayer_x                                    0xEC5D40
#define pinstCResolutionHandler_x                                  0x1601C38
#define pinstCSidlManager_x                                        0x1600BD0
#define pinstCXWndManager_x                                        0x1600BCC
#define instDynamicZone_x                                          0xEC9CA0
#define pinstDZMember_x                                            0xEC9DB0
#define pinstDZTimerInfo_x                                         0xEC9DB4
#define pinstEqLogin_x                                             0xF6F8A0
#define instEQMisc_x                                               0xE10FF0
#define pinstEQSoundManager_x                                      0xE13360
#define pinstEQSpellStrings_x                                      0xCD39F8
#define instExpeditionLeader_x                                     0xEC9CEA
#define instExpeditionName_x                                       0xEC9D2A
#define pinstGroup_x                                               0xEC5A16
#define pinstImeManager_x                                          0x1600BC8
#define pinstLocalPlayer_x                                         0xEC5CE8
#define pinstMercenaryData_x                                       0xF6C19C
#define pinstMercenaryStats_x                                      0xF8518C
#define pinstModelPlayer_x                                         0xEC5D00
#define pinstPCData_x                                              0xEC5A04
#define pinstSkillMgr_x                                            0xF6E300
#define pinstSpawnManager_x                                        0xF6CDA8
#define pinstSpellManager_x                                        0xF6E540
#define pinstSpellSets_x                                           0xF627EC
#define pinstStringTable_x                                         0xEC5C08
#define pinstSwitchManager_x                                       0xEC3700
#define pinstTarget_x                                              0xEC5D3C
#define pinstTargetObject_x                                        0xEC5F54
#define pinstTargetSwitch_x                                        0xEC385C
#define pinstTaskMember_x                                          0xE10E80
#define pinstTrackTarget_x                                         0xEC5D44
#define pinstTradeTarget_x                                         0xEC5CFC
#define instTributeActive_x                                        0xE11011
#define pinstViewActor_x                                           0xE11194
#define pinstWorldData_x                                           0xEC5864
#define pinstZoneAddr_x                                            0xECB398
#define pinstPlayerPath_x                                          0xF6CE40
#define pinstTargetIndicator_x                                     0xF6E7A8
#define EQObject_Top_x                                             0xEC5CE4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE1147C
#define pinstCAchievementsWnd_x                                    0xE1198C
#define pinstCActionsWnd_x                                         0xE114D4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE111BC
#define pinstCAdvancedLootWnd_x                                    0xE11154
#define pinstCAdventureLeaderboardWnd_x                            0xF7BE60
#define pinstCAdventureRequestWnd_x                                0xF7BF10
#define pinstCAdventureStatsWnd_x                                  0xF7BFC0
#define pinstCAggroMeterWnd_x                                      0xE111C0
#define pinstCAlarmWnd_x                                           0xE119CC
#define pinstCAlertHistoryWnd_x                                    0xE11210
#define pinstCAlertStackWnd_x                                      0xE11158
#define pinstCAlertWnd_x                                           0xE11178
#define pinstCAltStorageWnd_x                                      0xF7C320
#define pinstCAudioTriggersWindow_x                                0xCC5D28
#define pinstCAuraWnd_x                                            0xE11164
#define pinstCAvaZoneWnd_x                                         0xE11214
#define pinstCBandolierWnd_x                                       0xE111B4
#define pinstCBankWnd_x                                            0xE111FC
#define pinstCBarterMerchantWnd_x                                  0xF7D560
#define pinstCBarterSearchWnd_x                                    0xF7D610
#define pinstCBarterWnd_x                                          0xF7D6C0
#define pinstCBazaarConfirmationWnd_x                              0xE119C8
#define pinstCBazaarSearchWnd_x                                    0xE11480
#define pinstCBazaarWnd_x                                          0xE119AC
#define pinstCBlockedBuffWnd_x                                     0xE11170
#define pinstCBlockedPetBuffWnd_x                                  0xE11190
#define pinstCBodyTintWnd_x                                        0xE11948
#define pinstCBookWnd_x                                            0xE111E8
#define pinstCBreathWnd_x                                          0xE11490
#define pinstCBuffWindowNORMAL_x                                   0xE11148
#define pinstCBuffWindowSHORT_x                                    0xE1114C
#define pinstCBugReportWnd_x                                       0xE111F8
#define pinstCButtonWnd_x                                          0x1600E38
#define pinstCCastingWnd_x                                         0xE111D4
#define pinstCCastSpellWnd_x                                       0xE11484
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE11960
#define pinstCChatWindowManager_x                                  0xF7E180
#define pinstCClaimWnd_x                                           0xF7E2D8
#define pinstCColorPickerWnd_x                                     0xE11248
#define pinstCCombatAbilityWnd_x                                   0xE119BC
#define pinstCCombatSkillsSelectWnd_x                              0xE11970
#define pinstCCompassWnd_x                                         0xE1153C
#define pinstCConfirmationDialog_x                                 0xF831D8
#define pinstCContainerMgr_x                                       0xE1195C
#define pinstCContextMenuManager_x                                 0x1600B88
#define pinstCCursorAttachment_x                                   0xE111C8
#define pinstCDynamicZoneWnd_x                                     0xF7E8A0
#define pinstCEditLabelWnd_x                                       0xE119E0
#define pinstCEQMainWnd_x                                          0xF7EAE8
#define pinstCEventCalendarWnd_x                                   0xE11474
#define pinstCExtendedTargetWnd_x                                  0xE1118C
#define pinstCFacePick_x                                           0xE11988
#define pinstCFactionWnd_x                                         0xE11998
#define pinstCFellowshipWnd_x                                      0xF7ECE8
#define pinstCFileSelectionWnd_x                                   0xE1123C
#define pinstCFindItemWnd_x                                        0xE11980
#define pinstCFindLocationWnd_x                                    0xF7EE40
#define pinstCFriendsWnd_x                                         0xE1197C
#define pinstCGemsGameWnd_x                                        0xE11994
#define pinstCGiveWnd_x                                            0xE119D4
#define pinstCGroupSearchFiltersWnd_x                              0xE111D8
#define pinstCGroupSearchWnd_x                                     0xF7F238
#define pinstCGroupWnd_x                                           0xF7F2E8
#define pinstCGuildBankWnd_x                                       0xECC1DC
#define pinstCGuildCreationWnd_x                                   0xF7F448
#define pinstCGuildMgmtWnd_x                                       0xF7F4F8
#define pinstCharacterCreation_x                                   0xE11978
#define pinstCHelpWnd_x                                            0xE119C4
#define pinstCHeritageSelectionWnd_x                               0xE1199C
#define pinstCHotButtonWnd_x                                       0xF81650
#define pinstCHotButtonWnd1_x                                      0xF81650
#define pinstCHotButtonWnd2_x                                      0xF81654
#define pinstCHotButtonWnd3_x                                      0xF81658
#define pinstCHotButtonWnd4_x                                      0xF8165C
#define pinstCIconSelectionWnd_x                                   0xE111C4
#define pinstCInspectWnd_x                                         0xE1119C
#define pinstCInventoryWnd_x                                       0xE1116C
#define pinstCInvSlotMgr_x                                         0xE1148C
#define pinstCItemDisplayManager_x                                 0xF81BE0
#define pinstCItemExpTransferWnd_x                                 0xF81D10
#define pinstCItemOverflowWnd_x                                    0xE11488
#define pinstCJournalCatWnd_x                                      0xE11460
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE11218
#define pinstCKeyRingWnd_x                                         0xE111D0
#define pinstCLargeDialogWnd_x                                     0xF83E58
#define pinstCLayoutCopyWnd_x                                      0xF82060
#define pinstCLFGuildWnd_x                                         0xF82110
#define pinstCLoadskinWnd_x                                        0xE119A8
#define pinstCLootFiltersCopyWnd_x                                 0xCE2388
#define pinstCLootFiltersWnd_x                                     0xE1115C
#define pinstCLootSettingsWnd_x                                    0xE11184
#define pinstCLootWnd_x                                            0xE11464
#define pinstCMailAddressBookWnd_x                                 0xE11494
#define pinstCMailCompositionWnd_x                                 0xE11478
#define pinstCMailIgnoreListWnd_x                                  0xE1149C
#define pinstCMailWnd_x                                            0xE11250
#define pinstCManageLootWnd_x                                      0xE12840
#define pinstCMapToolbarWnd_x                                      0xE119D0
#define pinstCMapViewWnd_x                                         0xE119A0
#define pinstCMarketplaceWnd_x                                     0xE11160
#define pinstCMerchantWnd_x                                        0xE11470
#define pinstCMIZoneSelectWnd_x                                    0xF82948
#define pinstCMusicPlayerWnd_x                                     0xE11208
#define pinstCNameChangeMercWnd_x                                  0xE119B0
#define pinstCNameChangePetWnd_x                                   0xE11990
#define pinstCNameChangeWnd_x                                      0xE119D8
#define pinstCNoteWnd_x                                            0xE119B4
#define pinstCObjectPreviewWnd_x                                   0xE1117C
#define pinstCOptionsWnd_x                                         0xE119C0
#define pinstCPetInfoWnd_x                                         0xE11230
#define pinstCPetitionQWnd_x                                       0xE11964
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE11950
#define pinstCPlayerWnd_x                                          0xE11238
#define pinstCPopupWndManager_x                                    0xF831D8
#define pinstCProgressionSelectionWnd_x                            0xF83288
#define pinstCPurchaseGroupWnd_x                                   0xE111EC
#define pinstCPurchaseWnd_x                                        0xE111B8
#define pinstCPvPLeaderboardWnd_x                                  0xF83338
#define pinstCPvPStatsWnd_x                                        0xF833E8
#define pinstCQuantityWnd_x                                        0xE1121C
#define pinstCRaceChangeWnd_x                                      0xE11150
#define pinstCRaidOptionsWnd_x                                     0xE111E4
#define pinstCRaidWnd_x                                            0xE11468
#define pinstCRealEstateItemsWnd_x                                 0xE11984
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE114C0
#define pinstCRealEstateManageWnd_x                                0xE111F4
#define pinstCRealEstateNeighborhoodWnd_x                          0xE1120C
#define pinstCRealEstatePlotSearchWnd_x                            0xE1122C
#define pinstCRealEstatePurchaseWnd_x                              0xE11244
#define pinstCRespawnWnd_x                                         0xE11188
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE1196C
#define pinstCSendMoneyWnd_x                                       0xE119DC
#define pinstCServerListWnd_x                                      0xE11254
#define pinstCSkillsSelectWnd_x                                    0xE11958
#define pinstCSkillsWnd_x                                          0xE11944
#define pinstCSocialEditWnd_x                                      0xE111CC
#define pinstCSocialWnd_x                                          0xE119A4
#define pinstCSpellBookWnd_x                                       0xE119B8
#define pinstCStoryWnd_x                                           0xE114BC
#define pinstCTargetOfTargetWnd_x                                  0xF85210
#define pinstCTargetWnd_x                                          0xE11180
#define pinstCTaskOverlayWnd_x                                     0xE111E0
#define pinstCTaskSelectWnd_x                                      0xF85368
#define pinstCTaskManager_x                                        0xCE2CC8
#define pinstCTaskTemplateSelectWnd_x                              0xF85418
#define pinstCTaskWnd_x                                            0xF854C8
#define pinstCTextEntryWnd_x                                       0xE111DC
#define pinstCTimeLeftWnd_x                                        0xE1194C
#define pinstCTipWndCONTEXT_x                                      0xF856CC
#define pinstCTipWndOFDAY_x                                        0xF856C8
#define pinstCTitleWnd_x                                           0xF85778
#define pinstCTrackingWnd_x                                        0xE11174
#define pinstCTradeskillWnd_x                                      0xF858E0
#define pinstCTradeWnd_x                                           0xE11954
#define pinstCTrainWnd_x                                           0xE1125C
#define pinstCTributeBenefitWnd_x                                  0xF85AE0
#define pinstCTributeMasterWnd_x                                   0xF85B90
#define pinstCTributeTrophyWnd_x                                   0xF85C40
#define pinstCVideoModesWnd_x                                      0xE11240
#define pinstCVoiceMacroWnd_x                                      0xF6EF10
#define pinstCVoteResultsWnd_x                                     0xE11974
#define pinstCVoteWnd_x                                            0xE11968
#define pinstCWebManager_x                                         0xF6F58C
#define pinstCZoneGuideWnd_x                                       0xE111F0
#define pinstCZonePathWnd_x                                        0xE11200

#define pinstEQSuiteTextureLoader_x                                0xCB0128
#define pinstItemIconCache_x                                       0xF7EAA0
#define pinstLootFiltersManager_x                                  0xCE2438
#define pinstRewardSelectionWnd_x                                  0xF83B30

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5BD520
#define __CastRay2_x                                               0x5BD570
#define __ConvertItemTags_x                                        0x5D9140
#define __CleanItemTags_x                                          0x47D050
#define __DoesFileExist_x                                          0x912EA0
#define __EQGetTime_x                                              0x90F8F0
#define __ExecuteCmd_x                                             0x5B5DB0
#define __FixHeading_x                                             0x9AA6F0
#define __GameLoop_x                                               0x6CA1C0
#define __get_bearing_x                                            0x5BD090
#define __get_melee_range_x                                        0x5BD760
#define __GetAnimationCache_x                                      0x72F680
#define __GetGaugeValueFromEQ_x                                    0x821160
#define __GetLabelFromEQ_x                                         0x822C40
#define __GetXTargetType_x                                         0x9AC220
#define __HandleMouseWheel_x                                       0x6CB0A0
#define __HeadingDiff_x                                            0x9AA760
#define __HelpPath_x                                               0xF6A294
#define __LoadFrontEnd_x                                           0x6C74E0
#define __NewUIINI_x                                               0x820E30
#define __ProcessGameEvents_x                                      0x61DED0
#define __ProcessMouseEvent_x                                      0x61D690
#define __SaveColors_x                                             0x5588A0
#define __STMLToText_x                                             0x94DD10
#define __ToggleKeyRingItem_x                                      0x519890
#define CMemoryMappedFile__SetFile_x                               0xA999F0
#define CrashDetected_x                                            0x6C8F80
#define DrawNetStatus_x                                            0x649BD0
#define Expansion_HoT_x                                            0xECC1E4
#define Teleport_Table_Size_x                                      0xEC5CA4
#define Teleport_Table_x                                           0xEC3860
#define Util__FastTime_x                                           0x90F4C0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490330
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499230
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499000
#define CAdvancedLootWnd__AddPlayerToList_x                        0x4938C0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D10

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x560AC0
#define AltAdvManager__IsAbilityReady_x                            0x55F860
#define AltAdvManager__GetAAById_x                                 0x55FBF0
#define AltAdvManager__CanTrainAbility_x                           0x55FC60
#define AltAdvManager__CanSeeAbility_x                             0x55FFC0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9D60
#define CharacterZoneClient__HasSkill_x                            0x4D4BE0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6300
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE4B0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAAE0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8C80
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8D60
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8E40
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2BB0
#define CharacterZoneClient__BardCastBard_x                        0x4C5730
#define CharacterZoneClient__GetMaxEffects_x                       0x4BABB0
#define CharacterZoneClient__GetEffect_x                           0x4BAA20
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3C00
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3CD0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3D20
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3E70
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4040
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B29E0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7260
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6CE0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6F0CA0
#define CBankWnd__WndNotification_x                                0x6F0A80

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6FE3F0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x62C750
#define CButtonWnd__CButtonWnd_x                                   0x94A0F0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x71E6A0
#define CChatManager__InitContextMenu_x                            0x7177E0
#define CChatManager__FreeChatWindow_x                             0x71D1E0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8390
#define CChatManager__SetLockedActiveChatWindow_x                  0x71E320
#define CChatManager__CreateChatWindow_x                           0x71D820

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E84A0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x95E780
#define CContextMenu__dCContextMenu_x                              0x95E9B0
#define CContextMenu__AddMenuItem_x                                0x95E9C0
#define CContextMenu__RemoveMenuItem_x                             0x95ECD0
#define CContextMenu__RemoveAllMenuItems_x                         0x95ECF0
#define CContextMenu__CheckMenuItem_x                              0x95ED70
#define CContextMenu__SetMenuItem_x                                0x95EBF0
#define CContextMenu__AddSeparator_x                               0x95EB50

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x95F310
#define CContextMenuManager__RemoveMenu_x                          0x95F380
#define CContextMenuManager__PopupMenu_x                           0x95F440
#define CContextMenuManager__Flush_x                               0x95F2B0
#define CContextMenuManager__GetMenu_x                             0x49B3A0
#define CContextMenuManager__CreateDefaultMenu_x                   0x729EA0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8EAC60
#define CChatService__GetFriendName_x                              0x8EAC70

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x71EEE0
#define CChatWindow__Clear_x                                       0x7201A0
#define CChatWindow__WndNotification_x                             0x720930
#define CChatWindow__AddHistory_x                                  0x71FA60

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x95BC00
#define CComboWnd__Draw_x                                          0x95B100
#define CComboWnd__GetCurChoice_x                                  0x95BA40
#define CComboWnd__GetListRect_x                                   0x95B5B0
#define CComboWnd__GetTextRect_x                                   0x95BC70
#define CComboWnd__InsertChoice_x                                  0x95B740
#define CComboWnd__SetColors_x                                     0x95B710
#define CComboWnd__SetChoice_x                                     0x95BA10
#define CComboWnd__GetItemCount_x                                  0x95BA50
#define CComboWnd__GetCurChoiceText_x                              0x95BA90
#define CComboWnd__GetChoiceText_x                                 0x95BA60
#define CComboWnd__InsertChoiceAtIndex_x                           0x95B7D0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x727890
#define CContainerWnd__vftable_x                                   0xB21564
#define CContainerWnd__SetContainer_x                              0x728DF0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x553250
#define CDisplay__PreZoneMainUI_x                                  0x553260
#define CDisplay__CleanGameUI_x                                    0x558660
#define CDisplay__GetClickedActor_x                                0x54B550
#define CDisplay__GetUserDefinedColor_x                            0x543BB0
#define CDisplay__GetWorldFilePath_x                               0x54CFC0
#define CDisplay__is3dON_x                                         0x5481B0
#define CDisplay__ReloadUI_x                                       0x5526D0
#define CDisplay__WriteTextHD2_x                                   0x547FA0
#define CDisplay__TrueDistance_x                                   0x54EC80
#define CDisplay__SetViewActor_x                                   0x54AE70
#define CDisplay__GetFloorHeight_x                                 0x548270
#define CDisplay__SetRenderWindow_x                                0x546BD0
#define CDisplay__ToggleScreenshotMode_x                           0x54A940

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x97E330

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x961CE0
#define CEditWnd__EnsureCaretVisible_x                             0x963EB0
#define CEditWnd__GetCaretPt_x                                     0x962E60
#define CEditWnd__GetCharIndexPt_x                                 0x962C10
#define CEditWnd__GetDisplayString_x                               0x962AB0
#define CEditWnd__GetHorzOffset_x                                  0x961310
#define CEditWnd__GetLineForPrintableChar_x                        0x963DB0
#define CEditWnd__GetSelStartPt_x                                  0x962EC0
#define CEditWnd__GetSTMLSafeText_x                                0x9628D0
#define CEditWnd__PointFromPrintableChar_x                         0x9639E0
#define CEditWnd__SelectableCharFromPoint_x                        0x963B50
#define CEditWnd__SetEditable_x                                    0x962F90
#define CEditWnd__SetWindowTextA_x                                 0x962650
#define CEditWnd__ReplaceSelection_x                               0x963650
#define CEditWnd__ReplaceSelection1_x                              0x9635D0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60BAA0
#define CEverQuest__ClickedPlayer_x                                0x5FDBD0
#define CEverQuest__CreateTargetIndicator_x                        0x61B160
#define CEverQuest__DeleteTargetIndicator_x                        0x61B1F0
#define CEverQuest__DoTellWindow_x                                 0x4E8580
#define CEverQuest__OutputTextToLog_x                              0x4E8850
#define CEverQuest__DropHeldItemOnGround_x                         0x5F2C10
#define CEverQuest__dsp_chat_x                                     0x4E8BE0
#define CEverQuest__trimName_x                                     0x6172D0
#define CEverQuest__Emote_x                                        0x60C300
#define CEverQuest__EnterZone_x                                    0x6063A0
#define CEverQuest__GetBodyTypeDesc_x                              0x610BC0
#define CEverQuest__GetClassDesc_x                                 0x611200
#define CEverQuest__GetClassThreeLetterCode_x                      0x611800
#define CEverQuest__GetDeityDesc_x                                 0x6199B0
#define CEverQuest__GetLangDesc_x                                  0x6119C0
#define CEverQuest__GetRaceDesc_x                                  0x6111E0
#define CEverQuest__InterpretCmd_x                                 0x619F80
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F6E10
#define CEverQuest__LMouseUp_x                                     0x5F51A0
#define CEverQuest__RightClickedOnPlayer_x                         0x5F76F0
#define CEverQuest__RMouseUp_x                                     0x5F6120
#define CEverQuest__SetGameState_x                                 0x5F29A0
#define CEverQuest__UPCNotificationFlush_x                         0x6171D0
#define CEverQuest__IssuePetCommand_x                              0x612DC0
#define CEverQuest__ReportSuccessfulHit_x                          0x60D650

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x739770
#define CGaugeWnd__CalcLinesFillRect_x                             0x7397D0
#define CGaugeWnd__Draw_x                                          0x738DF0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF4A0
#define CGuild__GetGuildName_x                                     0x4AE4E0
#define CGuild__GetGuildIndex_x                                    0x4AE920

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x753930

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62CB10

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x760940
#define CInvSlotMgr__MoveItem_x                                    0x75F660
#define CInvSlotMgr__SelectSlot_x                                  0x760A10

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x75DEA0
#define CInvSlot__SliderComplete_x                                 0x75BC10
#define CInvSlot__GetItemBase_x                                    0x75B590
#define CInvSlot__UpdateItem_x                                     0x75B700

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x762480
#define CInvSlotWnd__CInvSlotWnd_x                                 0x761610
#define CInvSlotWnd__HandleLButtonUp_x                             0x762000

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x81C4F0
#define CItemDisplayWnd__UpdateStrings_x                           0x770C40
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76A8C0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76ADF0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x771240
#define CItemDisplayWnd__AboutToShow_x                             0x7708A0
#define CItemDisplayWnd__WndNotification_x                         0x772380
#define CItemDisplayWnd__RequestConvertItem_x                      0x771DF0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x76F900
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7706C0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8551D0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x776880

// CLabel 
#define CLabel__Draw_x                                             0x77C340

// CListWnd
#define CListWnd__CListWnd_x                                       0x934390
#define CListWnd__dCListWnd_x                                      0x9346B0
#define CListWnd__AddColumn_x                                      0x938B10
#define CListWnd__AddColumn1_x                                     0x938B60
#define CListWnd__AddLine_x                                        0x938EF0
#define CListWnd__AddString_x                                      0x938CF0
#define CListWnd__CalculateFirstVisibleLine_x                      0x9388E0
#define CListWnd__CalculateVSBRange_x                              0x9386D0
#define CListWnd__ClearSel_x                                       0x9396D0
#define CListWnd__ClearAllSel_x                                    0x939730
#define CListWnd__CloseAndUpdateEditWindow_x                       0x93A130
#define CListWnd__Compare_x                                        0x938000
#define CListWnd__Draw_x                                           0x9347E0
#define CListWnd__DrawColumnSeparators_x                           0x936FD0
#define CListWnd__DrawHeader_x                                     0x937440
#define CListWnd__DrawItem_x                                       0x937940
#define CListWnd__DrawLine_x                                       0x937140
#define CListWnd__DrawSeparator_x                                  0x937070
#define CListWnd__EnableLine_x                                     0x9368B0
#define CListWnd__EnsureVisible_x                                  0x93A060
#define CListWnd__ExtendSel_x                                      0x939600
#define CListWnd__GetColumnTooltip_x                               0x9363F0
#define CListWnd__GetColumnMinWidth_x                              0x936460
#define CListWnd__GetColumnWidth_x                                 0x936360
#define CListWnd__GetCurSel_x                                      0x935CF0
#define CListWnd__GetItemAtPoint_x                                 0x936B20
#define CListWnd__GetItemAtPoint1_x                                0x936B90
#define CListWnd__GetItemData_x                                    0x935D70
#define CListWnd__GetItemHeight_x                                  0x936130
#define CListWnd__GetItemIcon_x                                    0x935F00
#define CListWnd__GetItemRect_x                                    0x9369A0
#define CListWnd__GetItemText_x                                    0x935DB0
#define CListWnd__GetSelList_x                                     0x939780
#define CListWnd__GetSeparatorRect_x                               0x936DD0
#define CListWnd__InsertLine_x                                     0x9392E0
#define CListWnd__RemoveLine_x                                     0x939430
#define CListWnd__SetColors_x                                      0x9386A0
#define CListWnd__SetColumnJustification_x                         0x9383D0
#define CListWnd__SetColumnLabel_x                                 0x938C90
#define CListWnd__SetColumnWidth_x                                 0x9382F0
#define CListWnd__SetCurSel_x                                      0x939540
#define CListWnd__SetItemColor_x                                   0x939D20
#define CListWnd__SetItemData_x                                    0x939CE0
#define CListWnd__SetItemText_x                                    0x9398F0
#define CListWnd__ShiftColumnSeparator_x                           0x938490
#define CListWnd__Sort_x                                           0x938180
#define CListWnd__ToggleSel_x                                      0x939570
#define CListWnd__SetColumnsSizable_x                              0x938540
#define CListWnd__SetItemWnd_x                                     0x939BA0
#define CListWnd__GetItemWnd_x                                     0x935F50
#define CListWnd__SetItemIcon_x                                    0x939970
#define CListWnd__CalculateCustomWindowPositions_x                 0x9389D0
#define CListWnd__SetVScrollPos_x                                  0x9382D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x791A80
#define CMapViewWnd__GetWorldCoordinates_x                         0x790190
#define CMapViewWnd__HandleLButtonDown_x                           0x78D1D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B1BE0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B24C0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B29F0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B5970
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B0750
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BB520
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B17F0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8B87A0
#define CPacketScrambler__hton_x                                   0x8B8790

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x953350
#define CSidlManager__FindScreenPieceTemplate_x                    0x953760
#define CSidlManager__FindScreenPieceTemplate1_x                   0x953550
#define CSidlManager__CreateLabel_x                                0x8136C0
#define CSidlManager__CreateXWndFromTemplate_x                     0x9566C0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x956890
#define CSidlManager__CreateXWnd_x                                 0x8135F0
#define CSidlManager__CreateHotButtonWnd_x                         0x813BA0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x94FE20
#define CSidlScreenWnd__CalculateVSBRange_x                        0x94FD20
#define CSidlScreenWnd__ConvertToRes_x                             0x978E80
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x94F7C0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x94F4B0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x94F580
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x94F650
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9502B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x950780
#define CSidlScreenWnd__GetSidlPiece_x                             0x9504A0
#define CSidlScreenWnd__Init1_x                                    0x94F0B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x9507D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x951330
#define CSidlScreenWnd__LoadSidlScreen_x                           0x94E4C0
#define CSidlScreenWnd__StoreIniInfo_x                             0x950EA0
#define CSidlScreenWnd__StoreIniVis_x                              0x951210
#define CSidlScreenWnd__WndNotification_x                          0x9501C0
#define CSidlScreenWnd__GetChildItem_x                             0x950700
#define CSidlScreenWnd__HandleLButtonUp_x                          0x93FF20
#define CSidlScreenWnd__m_layoutCopy_x                             0x1600A58

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x691020
#define CSkillMgr__GetSkillCap_x                                   0x691200
#define CSkillMgr__GetNameToken_x                                  0x6907A0
#define CSkillMgr__IsActivatedSkill_x                              0x6908E0
#define CSkillMgr__IsCombatSkill_x                                 0x690820

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9600F0
#define CSliderWnd__SetValue_x                                     0x95FF60
#define CSliderWnd__SetNumTicks_x                                  0x95FFC0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x819820

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9688E0
#define CStmlWnd__ParseSTML_x                                      0x969C50
#define CStmlWnd__CalculateHSBRange_x                              0x969A40
#define CStmlWnd__CalculateVSBRange_x                              0x9699C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x96DD60
#define CStmlWnd__FastForwardToEndOfTag_x                          0x96E9F0
#define CStmlWnd__ForceParseNow_x                                  0x968F20
#define CStmlWnd__GetNextTagPiece_x                                0x96DCC0
#define CStmlWnd__GetSTMLText_x                                    0x5092B0
#define CStmlWnd__GetVisibleText_x                                 0x968F40
#define CStmlWnd__InitializeWindowVariables_x                      0x96E840
#define CStmlWnd__MakeStmlColorTag_x                               0x967F50
#define CStmlWnd__MakeWndNotificationTag_x                         0x967FC0
#define CStmlWnd__SetSTMLText_x                                    0x967000
#define CStmlWnd__StripFirstSTMLLines_x                            0x96FAE0
#define CStmlWnd__UpdateHistoryString_x                            0x96EC00

// CTabWnd 
#define CTabWnd__Draw_x                                            0x966150
#define CTabWnd__DrawCurrentPage_x                                 0x966880
#define CTabWnd__DrawTab_x                                         0x9665A0
#define CTabWnd__GetCurrentPage_x                                  0x965960
#define CTabWnd__GetPageInnerRect_x                                0x965BA0
#define CTabWnd__GetTabInnerRect_x                                 0x965AE0
#define CTabWnd__GetTabRect_x                                      0x965990
#define CTabWnd__InsertPage_x                                      0x965DB0
#define CTabWnd__RemovePage_x                                      0x965F20
#define CTabWnd__SetPage_x                                         0x965C20
#define CTabWnd__SetPageRect_x                                     0x966090
#define CTabWnd__UpdatePage_x                                      0x966460
#define CTabWnd__GetPageFromTabIndex_x                             0x9664E0
#define CTabWnd__GetCurrentTabIndex_x                              0x965950

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x776CC0
#define CPageWnd__SetTabText_x                                     0x9654B0
#define CPageWnd__FlashTab_x                                       0x965510

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8EF0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93CE10
#define CTextureFont__GetTextExtent_x                              0x93CFD0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C4380
#define CHtmlComponentWnd__ValidateUri_x                           0x755320
#define CHtmlWnd__SetClientCallbacks_x                             0x631B80
#define CHtmlWnd__AddObserver_x                                    0x631BA0
#define CHtmlWnd__RemoveObserver_x                                 0x631C00
#define Window__getProgress_x                                      0x86DB40
#define Window__getStatus_x                                        0x86DB60
#define Window__getURI_x                                           0x86DB70

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x975C90

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x929FA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E80D0
#define CXStr__CXStr1_x                                            0x5044B0
#define CXStr__CXStr3_x                                            0x90BA90
#define CXStr__dCXStr_x                                            0x478680
#define CXStr__operator_equal_x                                    0x90BCC0
#define CXStr__operator_equal1_x                                   0x90BD00
#define CXStr__operator_plus_equal1_x                              0x90C790
#define CXStr__SetString_x                                         0x90E680
#define CXStr__operator_char_p_x                                   0x90C1D0
#define CXStr__GetChar_x                                           0x90DFD0
#define CXStr__Delete_x                                            0x90D880
#define CXStr__GetUnicode_x                                        0x90E040
#define CXStr__GetLength_x                                         0x4A8CA0
#define CXStr__Mid_x                                               0x47D400
#define CXStr__Insert_x                                            0x90E0A0
#define CXStr__FindNext_x                                          0x90DCF0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x95E3A0
#define CXWnd__BringToTop_x                                        0x943690
#define CXWnd__Center_x                                            0x943210
#define CXWnd__ClrFocus_x                                          0x943030
#define CXWnd__Destroy_x                                           0x9430D0
#define CXWnd__DoAllDrawing_x                                      0x93F6D0
#define CXWnd__DrawChildren_x                                      0x93F6A0
#define CXWnd__DrawColoredRect_x                                   0x93FB10
#define CXWnd__DrawTooltip_x                                       0x93E1F0
#define CXWnd__DrawTooltipAtPoint_x                                0x93E2B0
#define CXWnd__GetBorderFrame_x                                    0x93F970
#define CXWnd__GetChildWndAt_x                                     0x943730
#define CXWnd__GetClientClipRect_x                                 0x941920
#define CXWnd__GetScreenClipRect_x                                 0x9419F0
#define CXWnd__GetScreenRect_x                                     0x941BB0
#define CXWnd__GetRelativeRect_x                                   0x941C70
#define CXWnd__GetTooltipRect_x                                    0x93FB60
#define CXWnd__GetWindowTextA_x                                    0x49CAB0
#define CXWnd__IsActive_x                                          0x940290
#define CXWnd__IsDescendantOf_x                                    0x9425A0
#define CXWnd__IsReallyVisible_x                                   0x9425D0
#define CXWnd__IsType_x                                            0x943D60
#define CXWnd__Move_x                                              0x942650
#define CXWnd__Move1_x                                             0x942700
#define CXWnd__ProcessTransition_x                                 0x9431C0
#define CXWnd__Refade_x                                            0x9429D0
#define CXWnd__Resize_x                                            0x942C50
#define CXWnd__Right_x                                             0x943450
#define CXWnd__SetFocus_x                                          0x942FF0
#define CXWnd__SetFont_x                                           0x943060
#define CXWnd__SetKeyTooltip_x                                     0x943B90
#define CXWnd__SetMouseOver_x                                      0x940AC0
#define CXWnd__StartFade_x                                         0x942480
#define CXWnd__GetChildItem_x                                      0x943890
#define CXWnd__SetParent_x                                         0x942340
#define CXWnd__Minimize_x                                          0x942CC0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x979F00

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x946590
#define CXWndManager__DrawWindows_x                                0x9465B0
#define CXWndManager__GetKeyboardFlags_x                           0x948D80
#define CXWndManager__HandleKeyboardMsg_x                          0x948940
#define CXWndManager__RemoveWnd_x                                  0x948FA0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x949510

// CDBStr
#define CDBStr__GetString_x                                        0x542B70

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBAC0
#define EQ_Character__Cur_HP_x                                     0x4D1C20
#define EQ_Character__Cur_Mana_x                                   0x4D9340
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEB00
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2620
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2770
#define EQ_Character__GetHPRegen_x                                 0x4DF0E0
#define EQ_Character__GetEnduranceRegen_x                          0x4DF6E0
#define EQ_Character__GetManaRegen_x                               0x4DFB20
#define EQ_Character__Max_Endurance_x                              0x657D00
#define EQ_Character__Max_HP_x                                     0x4D1A50
#define EQ_Character__Max_Mana_x                                   0x657B00
#define EQ_Character__doCombatAbility_x                            0x65A130
#define EQ_Character__UseSkill_x                                   0x4E1900
#define EQ_Character__GetConLevel_x                                0x650AA0
#define EQ_Character__IsExpansionFlag_x                            0x5B4540
#define EQ_Character__TotalEffect_x                                0x4C4E70
#define EQ_Character__GetPCSpellAffect_x                           0x4BF850
#define EQ_Character__SpellDuration_x                              0x4BF380
#define EQ_Character__GetAdjustedSkill_x                           0x4D49A0
#define EQ_Character__GetBaseSkill_x                               0x4D5940
#define EQ_Character__CanUseItem_x                                 0x4D9650

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8D7B40

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x66E240

//PcClient
#define PcClient__PcClient_x                                       0x64E1F0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9730
#define CCharacterListWnd__EnterWorld_x                            0x4B9170
#define CCharacterListWnd__Quit_x                                  0x4B8EC0
#define CCharacterListWnd__UpdateList_x                            0x4B9300

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x632D50
#define EQ_Item__CreateItemTagString_x                             0x8B1D90
#define EQ_Item__IsStackable_x                                     0x8B69E0
#define EQ_Item__GetImageNum_x                                     0x8B3800
#define EQ_Item__CreateItemClient_x                                0x631F80
#define EQ_Item__GetItemValue_x                                    0x8B4BE0
#define EQ_Item__ValueSellMerchant_x                               0x8B8380
#define EQ_Item__IsKeyRingItem_x                                   0x8B6300
#define EQ_Item__CanGoInBag_x                                      0x632E70
#define EQ_Item__IsEmpty_x                                         0x8B5E40
#define EQ_Item__GetMaxItemCount_x                                 0x8B4FF0
#define EQ_Item__GetHeldItem_x                                     0x8B36D0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8B1600

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x561810
#define EQ_LoadingS__Array_x                                       0xC37C60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x658640
#define EQ_PC__GetAlternateAbilityId_x                             0x8C17E0
#define EQ_PC__GetCombatAbility_x                                  0x8C1E50
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C1EC0
#define EQ_PC__GetItemRecastTimer_x                                0x65A6B0
#define EQ_PC__HasLoreItem_x                                       0x651260
#define EQ_PC__AlertInventoryChanged_x                             0x6503E0
#define EQ_PC__GetPcZoneClient_x                                   0x67CCF0
#define EQ_PC__RemoveMyAffect_x                                    0x65D8E0
#define EQ_PC__GetKeyRingItems_x                                   0x8C2750
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C24E0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C2A50

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BAA90
#define EQItemList__add_object_x                                   0x5E8390
#define EQItemList__add_item_x                                     0x5BAFF0
#define EQItemList__delete_item_x                                  0x5BB040
#define EQItemList__FreeItemList_x                                 0x5BAF40

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53F730

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x66FAC0
#define EQPlayer__dEQPlayer_x                                      0x662E10
#define EQPlayer__DoAttack_x                                       0x677990
#define EQPlayer__EQPlayer_x                                       0x6634D0
#define EQPlayer__SetNameSpriteState_x                             0x6677B0
#define EQPlayer__SetNameSpriteTint_x                              0x668670
#define PlayerBase__HasProperty_j_x                                0x9A8AF0
#define EQPlayer__IsTargetable_x                                   0x9A8F90
#define EQPlayer__CanSee_x                                         0x9A8DF0
#define EQPlayer__CanSee1_x                                        0x9A8EC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x9A8BB0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67A790
#define PlayerZoneClient__GetLevel_x                               0x67CD30
#define PlayerZoneClient__IsValidTeleport_x                        0x5E9500
#define PlayerZoneClient__LegalPlayerRace_x                        0x55A520

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x6728A0
#define EQPlayerManager__GetSpawnByName_x                          0x672950
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6729E0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6363E0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x636460
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6364A0
#define KeypressHandler__ClearCommandStateArray_x                  0x6378B0
#define KeypressHandler__HandleKeyDown_x                           0x6378D0
#define KeypressHandler__HandleKeyUp_x                             0x637970
#define KeypressHandler__SaveKeymapping_x                          0x637DC0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x78D8F0
#define MapViewMap__SaveEx_x                                       0x790CB0
#define MapViewMap__SetZoom_x                                      0x795370

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D5BA0

// StringTable 
#define StringTable__getString_x                                   0x8D0A00

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x65D550
#define PcZoneClient__RemovePetEffect_x                            0x65DB80
#define PcZoneClient__HasAlternateAbility_x                        0x657930
#define PcZoneClient__GetCurrentMod_x                              0x4E49B0
#define PcZoneClient__GetModCap_x                                  0x4E48B0
#define PcZoneClient__CanEquipItem_x                               0x657FE0
#define PcZoneClient__GetItemByID_x                                0x65AB20
#define PcZoneClient__GetItemByItemClass_x                         0x65AC70
#define PcZoneClient__RemoveBuffEffect_x                           0x65DBA0
#define PcZoneClient__BandolierSwap_x                              0x658BF0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65A650

//Doors
#define EQSwitch__UseSwitch_x                                      0x5EE0E0

//IconCache
#define IconCache__GetIcon_x                                       0x72EF20

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x726980
#define CContainerMgr__CloseContainer_x                            0x726C50
#define CContainerMgr__OpenExperimentContainer_x                   0x7276D0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E5C90

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62AF40

//CLootWnd
#define CLootWnd__LootAll_x                                        0x783E00
#define CLootWnd__RequestLootSlot_x                                0x783030

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x587F20
#define EQ_Spell__SpellAffects_x                                   0x588390
#define EQ_Spell__SpellAffectBase_x                                0x588150
#define EQ_Spell__IsStackable_x                                    0x4C9680
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9470
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6AF0
#define EQ_Spell__IsSPAStacking_x                                  0x5891E0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5886F0
#define EQ_Spell__IsNoRemove_x                                     0x4C9660
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5891F0
#define __IsResEffectSpell_x                                       0x4C88F0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD070

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8E01C0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82CC20
#define CTargetWnd__WndNotification_x                              0x82C460
#define CTargetWnd__RefreshTargetBuffs_x                           0x82C730
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82B5D0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x831260
#define CTaskWnd__ConfirmAbandonTask_x                             0x833E90

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53D150
#define CTaskManager__HandleMessage_x                              0x53B5C0
#define CTaskManager__GetTaskStatus_x                              0x53D200
#define CTaskManager__GetElementDescription_x                      0x53D280

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5830D0
#define EqSoundManager__PlayScriptMp3_x                            0x583390
#define EqSoundManager__SoundAssistPlay_x                          0x694F60
#define EqSoundManager__WaveInstancePlay_x                         0x6944D0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52E830

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9649C0
#define CTextureAnimation__Draw_x                                  0x964BC0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x960A50

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5692D0
#define CAltAbilityData__GetMercMaxRank_x                          0x569260
#define CAltAbilityData__GetMaxRank_x                              0x55E6E0

//CTargetRing
#define CTargetRing__Cast_x                                        0x629060

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9450
#define CharacterBase__CreateItemGlobalIndex_x                     0x515E80
#define CharacterBase__CreateItemIndex_x                           0x631130
#define CharacterBase__GetItemPossession_x                         0x501DA0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8E8810
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8E8870
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x70DA20
#define CCastSpellWnd__IsBardSongPlaying_x                         0x70E250
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x70E300

//messages
#define msg_spell_worn_off_x                                       0x5ACBD0
#define msg_new_text_x                                             0x5A1580
#define __msgTokenTextParam_x                                      0x5AEE70
#define msgTokenText_x                                             0x5AF0C0

//SpellManager
#define SpellManager__vftable_x                                    0xAFB160
#define SpellManager__SpellManager_x                               0x698280
#define Spellmanager__LoadTextSpells_x                             0x698B70
#define SpellManager__GetSpellByGroupAndRank_x                     0x698450

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9ACB10

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x516500
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B2B00
#define ItemGlobalIndex__IsEquippedLocation_x                      0x649A30
#define ItemGlobalIndex__IsValidIndex_x                            0x516560

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8E0B60
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8E0DE0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77C680

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72B130
#define CCursorAttachment__AttachToCursor1_x                       0x72B170
#define CCursorAttachment__Deactivate_x                            0x72C160

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x9576B0
#define CSidlManagerBase__CreatePageWnd_x                          0x956EC0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x953170
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x953100

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9748B0
#define CEQSuiteTextureLoader__GetTexture_x                        0x974570

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x513520
#define CFindItemWnd__WndNotification_x                            0x514000
#define CFindItemWnd__Update_x                                     0x514B40
#define CFindItemWnd__PickupSelectedItem_x                         0x512D60

//IString
#define IString__Append_x                                          0x5035C0

//Camera
#define CDisplay__cameraType_x                                     0xE1124C
#define EverQuest__Cameras_x                                       0xECC534

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51BC40
#define LootFiltersManager__GetItemFilterData_x                    0x51B540
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51B570
#define LootFiltersManager__SetItemLootFilter_x                    0x51B790

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D3AF0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B26A0
#define CResolutionHandler__GetWindowedStyle_x                     0x68F9D0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x723630

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F60E0
#define CDistillerInfo__Instance_x                                 0x8F6080

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x742730
#define CGroupWnd__UpdateDisplay_x                                 0x741A90

//ItemBase
#define ItemBase__IsLore_x                                         0x8B63B0
#define ItemBase__IsLoreEquipped_x                                 0x8B6420

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5E82F0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5E8430
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5E8490

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6853F0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x688DA0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x5098B0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F5F80
#define FactionManagerClient__HandleFactionMessage_x               0x4F65F0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F6BB0
#define FactionManagerClient__GetMaxFaction_x                      0x4F6BCF
#define FactionManagerClient__GetMinFaction_x                      0x4F6B80

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x501D70

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x93BDD0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BD90

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x501FD0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x568770

//CTargetManager
#define CTargetManager__Get_x                                      0x69BAD0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6853F0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8CB0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BAEE0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF69BC8

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6D73D0

//CXRect
#define CXRect__operator_and_x                                     0x739830

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
