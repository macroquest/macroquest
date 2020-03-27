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
#define __ExpectedVersionDate                                     "Mar 25 2020"
#define __ExpectedVersionTime                                     "16:58:04"
#define __ActualVersionDate_x                                      0xB19378
#define __ActualVersionTime_x                                      0xB1936C
#define __ActualVersionBuild_x                                     0xB050DC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x63CA10
#define __MemChecker1_x                                            0x910120
#define __MemChecker2_x                                            0x6CB200
#define __MemChecker3_x                                            0x6CB150
#define __MemChecker4_x                                            0x866290
#define __EncryptPad0_x                                            0xC514E8
#define __EncryptPad1_x                                            0xCAF650
#define __EncryptPad2_x                                            0xC61D80
#define __EncryptPad3_x                                            0xC61980
#define __EncryptPad4_x                                            0xC9FC00
#define __EncryptPad5_x                                            0xF707DC
#define __AC1_x                                                    0x823096
#define __AC2_x                                                    0x5F677F
#define __AC3_x                                                    0x5FDE7F
#define __AC4_x                                                    0x601E50
#define __AC5_x                                                    0x60815F
#define __AC6_x                                                    0x60C656
#define __AC7_x                                                    0x5F61F0
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x72178

// Direct Input
#define DI8__Main_x                                                0xF707FC
#define DI8__Keyboard_x                                            0xF70800
#define DI8__Mouse_x                                               0xF7081C
#define DI8__Mouse_Copy_x                                          0xECBE84
#define DI8__Mouse_Check_x                                         0xF712C8
#define __AutoSkillArray_x                                         0xECCD9C
#define __Attack_x                                                 0xF6ABC3
#define __Autofire_x                                               0xF6ABC4
#define __BindList_x                                               0xC3FF30
#define g_eqCommandStates_x                                        0xC40CB0
#define __Clicks_x                                                 0xECBF3C
#define __CommandList_x                                            0xC41870
#define __CurrentMapLabel_x                                        0xF8368C
#define __CurrentSocial_x                                          0xC297CC
#define __DoAbilityList_x                                          0xF026E4
#define __do_loot_x                                                0x5C2300
#define __DrawHandler_x                                            0x1602A08
#define __GroupCount_x                                             0xEC6A1A
#define __Guilds_x                                                 0xECADC8
#define __gWorld_x                                                 0xEC6C10
#define __HWnd_x                                                   0xF712A8
#define __heqmain_x                                                0xF7375C
#define __InChatMode_x                                             0xECBE6C
#define __LastTell_x                                               0xECDDE0
#define __LMouseHeldTime_x                                         0xECBFA8
#define __Mouse_x                                                  0xF707E8
#define __MouseLook_x                                              0xECBF02
#define __MouseEventTime_x                                         0xF6B6A4
#define __gpbCommandEvent_x                                        0xEC6C1C
#define __NetStatusToggle_x                                        0xECBF05
#define __PCNames_x                                                0xECD38C
#define __RangeAttackReady_x                                       0xECD080
#define __RMouseHeldTime_x                                         0xECBFA4
#define __RunWalkState_x                                           0xECBE70
#define __ScreenMode_x                                             0xE121A8
#define __ScreenX_x                                                0xECBE24
#define __ScreenY_x                                                0xECBE20
#define __ScreenXMax_x                                             0xECBE28
#define __ScreenYMax_x                                             0xECBE2C
#define __ServerHost_x                                             0xEC6E4B
#define __ServerName_x                                             0xF026A4
#define __ShiftKeyDown_x                                           0xECC4FC
#define __ShowNames_x                                              0xECD23C
#define EverQuestInfo__bSocialChanged_x                            0xF0272C
#define __Socials_x                                                0xF027A4
#define __SubscriptionType_x                                       0xFC7B98
#define __TargetAggroHolder_x                                      0xF86040
#define __ZoneType_x                                               0xECC300
#define __GroupAggro_x                                             0xF86080
#define __LoginName_x                                              0xF70F54
#define __Inviter_x                                                0xF6AB40
#define __AttackOnAssist_x                                         0xECD1F8
#define __UseTellWindows_x                                         0xECD528
#define __gfMaxZoomCameraDistance_x                                0xB0ECF0
#define __gfMaxCameraDistance_x                                    0xB3B07C
#define __pulAutoRun_x                                             0xECBF20
#define __pulForward_x                                             0xECD560
#define __pulBackward_x                                            0xECD564
#define __pulTurnRight_x                                           0xECD568
#define __pulTurnLeft_x                                            0xECD56C
#define __pulStrafeLeft_x                                          0xECD570
#define __pulStrafeRight_x                                         0xECD574

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEC7160
#define instEQZoneInfo_x                                           0xECC0F8
#define pinstActiveBanker_x                                        0xEC6CF8
#define pinstActiveCorpse_x                                        0xEC6CF0
#define pinstActiveGMaster_x                                       0xEC6CF4
#define pinstActiveMerchant_x                                      0xEC6CEC
#define pinstAltAdvManager_x                                       0xE13390
#define pinstBandageTarget_x                                       0xEC6D08
#define pinstCamActor_x                                            0xE12198
#define pinstCDBStr_x                                              0xE120AC
#define pinstCDisplay_x                                            0xEC6868
#define pinstCEverQuest_x                                          0xF70818
#define pinstEverQuestInfo_x                                       0xECBE18
#define pinstCharData_x                                            0xEC6A04
#define pinstCharSpawn_x                                           0xEC6D40
#define pinstControlledMissile_x                                   0xEC4854
#define pinstControlledPlayer_x                                    0xEC6D40
#define pinstCResolutionHandler_x                                  0x1602C38
#define pinstCSidlManager_x                                        0x1601BD0
#define pinstCXWndManager_x                                        0x1601BCC
#define instDynamicZone_x                                          0xECACA0
#define pinstDZMember_x                                            0xECADB0
#define pinstDZTimerInfo_x                                         0xECADB4
#define pinstEqLogin_x                                             0xF708A0
#define instEQMisc_x                                               0xE11FF0
#define pinstEQSoundManager_x                                      0xE14360
#define pinstEQSpellStrings_x                                      0xCD49F8
#define instExpeditionLeader_x                                     0xECACEA
#define instExpeditionName_x                                       0xECAD2A
#define pinstGroup_x                                               0xEC6A16
#define pinstImeManager_x                                          0x1601BC8
#define pinstLocalPlayer_x                                         0xEC6CE8
#define pinstMercenaryData_x                                       0xF6D19C
#define pinstMercenaryStats_x                                      0xF8618C
#define pinstModelPlayer_x                                         0xEC6D00
#define pinstPCData_x                                              0xEC6A04
#define pinstSkillMgr_x                                            0xF6F300
#define pinstSpawnManager_x                                        0xF6DDA8
#define pinstSpellManager_x                                        0xF6F540
#define pinstSpellSets_x                                           0xF637EC
#define pinstStringTable_x                                         0xEC6C08
#define pinstSwitchManager_x                                       0xEC4700
#define pinstTarget_x                                              0xEC6D3C
#define pinstTargetObject_x                                        0xEC6F54
#define pinstTargetSwitch_x                                        0xEC485C
#define pinstTaskMember_x                                          0xE11E80
#define pinstTrackTarget_x                                         0xEC6D44
#define pinstTradeTarget_x                                         0xEC6CFC
#define instTributeActive_x                                        0xE12011
#define pinstViewActor_x                                           0xE12194
#define pinstWorldData_x                                           0xEC6864
#define pinstZoneAddr_x                                            0xECC398
#define pinstPlayerPath_x                                          0xF6DE40
#define pinstTargetIndicator_x                                     0xF6F7A8
#define EQObject_Top_x                                             0xEC6CE4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE1247C
#define pinstCAchievementsWnd_x                                    0xE1298C
#define pinstCActionsWnd_x                                         0xE124D4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE121BC
#define pinstCAdvancedLootWnd_x                                    0xE12154
#define pinstCAdventureLeaderboardWnd_x                            0xF7CE60
#define pinstCAdventureRequestWnd_x                                0xF7CF10
#define pinstCAdventureStatsWnd_x                                  0xF7CFC0
#define pinstCAggroMeterWnd_x                                      0xE121C0
#define pinstCAlarmWnd_x                                           0xE129CC
#define pinstCAlertHistoryWnd_x                                    0xE12210
#define pinstCAlertStackWnd_x                                      0xE12158
#define pinstCAlertWnd_x                                           0xE12178
#define pinstCAltStorageWnd_x                                      0xF7D320
#define pinstCAudioTriggersWindow_x                                0xCC6D28
#define pinstCAuraWnd_x                                            0xE12164
#define pinstCAvaZoneWnd_x                                         0xE12214
#define pinstCBandolierWnd_x                                       0xE121B4
#define pinstCBankWnd_x                                            0xE121FC
#define pinstCBarterMerchantWnd_x                                  0xF7E560
#define pinstCBarterSearchWnd_x                                    0xF7E610
#define pinstCBarterWnd_x                                          0xF7E6C0
#define pinstCBazaarConfirmationWnd_x                              0xE129C8
#define pinstCBazaarSearchWnd_x                                    0xE12480
#define pinstCBazaarWnd_x                                          0xE129AC
#define pinstCBlockedBuffWnd_x                                     0xE12170
#define pinstCBlockedPetBuffWnd_x                                  0xE12190
#define pinstCBodyTintWnd_x                                        0xE12948
#define pinstCBookWnd_x                                            0xE121E8
#define pinstCBreathWnd_x                                          0xE12490
#define pinstCBuffWindowNORMAL_x                                   0xE12148
#define pinstCBuffWindowSHORT_x                                    0xE1214C
#define pinstCBugReportWnd_x                                       0xE121F8
#define pinstCButtonWnd_x                                          0x1601E38
#define pinstCCastingWnd_x                                         0xE121D4
#define pinstCCastSpellWnd_x                                       0xE12484
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE12960
#define pinstCChatWindowManager_x                                  0xF7F180
#define pinstCClaimWnd_x                                           0xF7F2D8
#define pinstCColorPickerWnd_x                                     0xE12248
#define pinstCCombatAbilityWnd_x                                   0xE129BC
#define pinstCCombatSkillsSelectWnd_x                              0xE12970
#define pinstCCompassWnd_x                                         0xE1253C
#define pinstCConfirmationDialog_x                                 0xF841D8
#define pinstCContainerMgr_x                                       0xE1295C
#define pinstCContextMenuManager_x                                 0x1601B88
#define pinstCCursorAttachment_x                                   0xE121C8
#define pinstCDynamicZoneWnd_x                                     0xF7F8A0
#define pinstCEditLabelWnd_x                                       0xE129E0
#define pinstCEQMainWnd_x                                          0xF7FAE8
#define pinstCEventCalendarWnd_x                                   0xE12474
#define pinstCExtendedTargetWnd_x                                  0xE1218C
#define pinstCFacePick_x                                           0xE12988
#define pinstCFactionWnd_x                                         0xE12998
#define pinstCFellowshipWnd_x                                      0xF7FCE8
#define pinstCFileSelectionWnd_x                                   0xE1223C
#define pinstCFindItemWnd_x                                        0xE12980
#define pinstCFindLocationWnd_x                                    0xF7FE40
#define pinstCFriendsWnd_x                                         0xE1297C
#define pinstCGemsGameWnd_x                                        0xE12994
#define pinstCGiveWnd_x                                            0xE129D4
#define pinstCGroupSearchFiltersWnd_x                              0xE121D8
#define pinstCGroupSearchWnd_x                                     0xF80238
#define pinstCGroupWnd_x                                           0xF802E8
#define pinstCGuildBankWnd_x                                       0xECD1DC
#define pinstCGuildCreationWnd_x                                   0xF80448
#define pinstCGuildMgmtWnd_x                                       0xF804F8
#define pinstCharacterCreation_x                                   0xE12978
#define pinstCHelpWnd_x                                            0xE129C4
#define pinstCHeritageSelectionWnd_x                               0xE1299C
#define pinstCHotButtonWnd_x                                       0xF82650
#define pinstCHotButtonWnd1_x                                      0xF82650
#define pinstCHotButtonWnd2_x                                      0xF82654
#define pinstCHotButtonWnd3_x                                      0xF82658
#define pinstCHotButtonWnd4_x                                      0xF8265C
#define pinstCIconSelectionWnd_x                                   0xE121C4
#define pinstCInspectWnd_x                                         0xE1219C
#define pinstCInventoryWnd_x                                       0xE1216C
#define pinstCInvSlotMgr_x                                         0xE1248C
#define pinstCItemDisplayManager_x                                 0xF82BE0
#define pinstCItemExpTransferWnd_x                                 0xF82D10
#define pinstCItemOverflowWnd_x                                    0xE12488
#define pinstCJournalCatWnd_x                                      0xE12460
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE12218
#define pinstCKeyRingWnd_x                                         0xE121D0
#define pinstCLargeDialogWnd_x                                     0xF84E58
#define pinstCLayoutCopyWnd_x                                      0xF83060
#define pinstCLFGuildWnd_x                                         0xF83110
#define pinstCLoadskinWnd_x                                        0xE129A8
#define pinstCLootFiltersCopyWnd_x                                 0xCE3388
#define pinstCLootFiltersWnd_x                                     0xE1215C
#define pinstCLootSettingsWnd_x                                    0xE12184
#define pinstCLootWnd_x                                            0xE12464
#define pinstCMailAddressBookWnd_x                                 0xE12494
#define pinstCMailCompositionWnd_x                                 0xE12478
#define pinstCMailIgnoreListWnd_x                                  0xE12498
#define pinstCMailWnd_x                                            0xE12250
#define pinstCManageLootWnd_x                                      0xE13840
#define pinstCMapToolbarWnd_x                                      0xE129D0
#define pinstCMapViewWnd_x                                         0xE129A0
#define pinstCMarketplaceWnd_x                                     0xE12160
#define pinstCMerchantWnd_x                                        0xE12470
#define pinstCMIZoneSelectWnd_x                                    0xF83948
#define pinstCMusicPlayerWnd_x                                     0xE12208
#define pinstCNameChangeMercWnd_x                                  0xE129B0
#define pinstCNameChangePetWnd_x                                   0xE12990
#define pinstCNameChangeWnd_x                                      0xE129D8
#define pinstCNoteWnd_x                                            0xE129B4
#define pinstCObjectPreviewWnd_x                                   0xE1217C
#define pinstCOptionsWnd_x                                         0xE129C0
#define pinstCPetInfoWnd_x                                         0xE12230
#define pinstCPetitionQWnd_x                                       0xE12964
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE12950
#define pinstCPlayerWnd_x                                          0xE12238
#define pinstCPopupWndManager_x                                    0xF841D8
#define pinstCProgressionSelectionWnd_x                            0xF84288
#define pinstCPurchaseGroupWnd_x                                   0xE121EC
#define pinstCPurchaseWnd_x                                        0xE121B8
#define pinstCPvPLeaderboardWnd_x                                  0xF84338
#define pinstCPvPStatsWnd_x                                        0xF843E8
#define pinstCQuantityWnd_x                                        0xE1221C
#define pinstCRaceChangeWnd_x                                      0xE12150
#define pinstCRaidOptionsWnd_x                                     0xE121E4
#define pinstCRaidWnd_x                                            0xE12468
#define pinstCRealEstateItemsWnd_x                                 0xE12984
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE124C0
#define pinstCRealEstateManageWnd_x                                0xE121F4
#define pinstCRealEstateNeighborhoodWnd_x                          0xE1220C
#define pinstCRealEstatePlotSearchWnd_x                            0xE1222C
#define pinstCRealEstatePurchaseWnd_x                              0xE12244
#define pinstCRespawnWnd_x                                         0xE12188
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE1296C
#define pinstCSendMoneyWnd_x                                       0xE129DC
#define pinstCServerListWnd_x                                      0xE12254
#define pinstCSkillsSelectWnd_x                                    0xE12958
#define pinstCSkillsWnd_x                                          0xE12944
#define pinstCSocialEditWnd_x                                      0xE121CC
#define pinstCSocialWnd_x                                          0xE129A4
#define pinstCSpellBookWnd_x                                       0xE129B8
#define pinstCStoryWnd_x                                           0xE124BC
#define pinstCTargetOfTargetWnd_x                                  0xF86210
#define pinstCTargetWnd_x                                          0xE12180
#define pinstCTaskOverlayWnd_x                                     0xE121E0
#define pinstCTaskSelectWnd_x                                      0xF86368
#define pinstCTaskManager_x                                        0xCE3CC8
#define pinstCTaskTemplateSelectWnd_x                              0xF86418
#define pinstCTaskWnd_x                                            0xF864C8
#define pinstCTextEntryWnd_x                                       0xE121DC
#define pinstCTimeLeftWnd_x                                        0xE1294C
#define pinstCTipWndCONTEXT_x                                      0xF866CC
#define pinstCTipWndOFDAY_x                                        0xF866C8
#define pinstCTitleWnd_x                                           0xF86778
#define pinstCTrackingWnd_x                                        0xE12174
#define pinstCTradeskillWnd_x                                      0xF868E0
#define pinstCTradeWnd_x                                           0xE12954
#define pinstCTrainWnd_x                                           0xE1245C
#define pinstCTributeBenefitWnd_x                                  0xF86AE0
#define pinstCTributeMasterWnd_x                                   0xF86B90
#define pinstCTributeTrophyWnd_x                                   0xF86C40
#define pinstCVideoModesWnd_x                                      0xE12240
#define pinstCVoiceMacroWnd_x                                      0xF6FF10
#define pinstCVoteResultsWnd_x                                     0xE12974
#define pinstCVoteWnd_x                                            0xE12968
#define pinstCWebManager_x                                         0xF7058C
#define pinstCZoneGuideWnd_x                                       0xE121F0
#define pinstCZonePathWnd_x                                        0xE12200

#define pinstEQSuiteTextureLoader_x                                0xCB1128
#define pinstItemIconCache_x                                       0xF7FAA0
#define pinstLootFiltersManager_x                                  0xCE3438
#define pinstRewardSelectionWnd_x                                  0xF84B30

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5BD6D0
#define __CastRay2_x                                               0x5BD720
#define __ConvertItemTags_x                                        0x5D92F0
#define __CleanItemTags_x                                          0x47D0D0
#define __DoesFileExist_x                                          0x913200
#define __EQGetTime_x                                              0x90FBF0
#define __ExecuteCmd_x                                             0x5B5F70
#define __FixHeading_x                                             0x9AB290
#define __GameLoop_x                                               0x6CA3D0
#define __get_bearing_x                                            0x5BD240
#define __get_melee_range_x                                        0x5BD910
#define __GetAnimationCache_x                                      0x72F890
#define __GetGaugeValueFromEQ_x                                    0x821540
#define __GetLabelFromEQ_x                                         0x823020
#define __GetXTargetType_x                                         0x9ACCE0
#define __HandleMouseWheel_x                                       0x6CB2B0
#define __HeadingDiff_x                                            0x9AB300
#define __HelpPath_x                                               0xF6B294
#define __LoadFrontEnd_x                                           0x6C76F0
#define __NewUIINI_x                                               0x821210
#define __ProcessGameEvents_x                                      0x61DF50
#define __ProcessMouseEvent_x                                      0x61D710
#define __SaveColors_x                                             0x5588E0
#define __STMLToText_x                                             0x94E7B0
#define __ToggleKeyRingItem_x                                      0x519600
#define CMemoryMappedFile__SetFile_x                               0xA9A490
#define CrashDetected_x                                            0x6C9190
#define DrawNetStatus_x                                            0x649CD0
#define Expansion_HoT_x                                            0xECD1E4
#define Teleport_Table_Size_x                                      0xEC6CA4
#define Teleport_Table_x                                           0xEC4860
#define Util__FastTime_x                                           0x90F7C0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490290
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499190
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498F60
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493830
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492C80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x560BA0
#define AltAdvManager__IsAbilityReady_x                            0x55F940
#define AltAdvManager__GetAAById_x                                 0x55FCD0
#define AltAdvManager__CanTrainAbility_x                           0x55FD40
#define AltAdvManager__CanSeeAbility_x                             0x5600A0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9E20
#define CharacterZoneClient__HasSkill_x                            0x4D4CA0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D63C0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE4B0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAAE0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8D50
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8E30
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8F10
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2BB0
#define CharacterZoneClient__BardCastBard_x                        0x4C5730
#define CharacterZoneClient__GetMaxEffects_x                       0x4BABB0
#define CharacterZoneClient__GetEffect_x                           0x4BAA20
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3C00
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3CD0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3D20
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3E70
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4040
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2940
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7320
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6DA0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6F0EA0
#define CBankWnd__WndNotification_x                                0x6F0C80

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6FE650

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x62C7D0
#define CButtonWnd__CButtonWnd_x                                   0x94AB70

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x71E940
#define CChatManager__InitContextMenu_x                            0x717A70
#define CChatManager__FreeChatWindow_x                             0x71D480
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8360
#define CChatManager__SetLockedActiveChatWindow_x                  0x71E5C0
#define CChatManager__CreateChatWindow_x                           0x71DAC0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8470

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x95F110
#define CContextMenu__dCContextMenu_x                              0x95F350
#define CContextMenu__AddMenuItem_x                                0x95F360
#define CContextMenu__RemoveMenuItem_x                             0x95F670
#define CContextMenu__RemoveAllMenuItems_x                         0x95F690
#define CContextMenu__CheckMenuItem_x                              0x95F710
#define CContextMenu__SetMenuItem_x                                0x95F590
#define CContextMenu__AddSeparator_x                               0x95F4F0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x95FCB0
#define CContextMenuManager__RemoveMenu_x                          0x95FD20
#define CContextMenuManager__PopupMenu_x                           0x95FDE0
#define CContextMenuManager__Flush_x                               0x95FC50
#define CContextMenuManager__GetMenu_x                             0x49B2A0
#define CContextMenuManager__CreateDefaultMenu_x                   0x72A090

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8EAE30
#define CChatService__GetFriendName_x                              0x8EAE40

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x71F170
#define CChatWindow__Clear_x                                       0x720430
#define CChatWindow__WndNotification_x                             0x720BC0
#define CChatWindow__AddHistory_x                                  0x71FCF0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x95C560
#define CComboWnd__Draw_x                                          0x95BA40
#define CComboWnd__GetCurChoice_x                                  0x95C3A0
#define CComboWnd__GetListRect_x                                   0x95BF00
#define CComboWnd__GetTextRect_x                                   0x95C5D0
#define CComboWnd__InsertChoice_x                                  0x95C090
#define CComboWnd__SetColors_x                                     0x95C060
#define CComboWnd__SetChoice_x                                     0x95C370
#define CComboWnd__GetItemCount_x                                  0x95C3B0
#define CComboWnd__GetCurChoiceText_x                              0x95C3F0
#define CComboWnd__GetChoiceText_x                                 0x95C3C0
#define CComboWnd__InsertChoiceAtIndex_x                           0x95C130

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x727A80
#define CContainerWnd__vftable_x                                   0xB22564
#define CContainerWnd__SetContainer_x                              0x728FF0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x553290
#define CDisplay__PreZoneMainUI_x                                  0x5532A0
#define CDisplay__CleanGameUI_x                                    0x5586A0
#define CDisplay__GetClickedActor_x                                0x54B590
#define CDisplay__GetUserDefinedColor_x                            0x543BF0
#define CDisplay__GetWorldFilePath_x                               0x54D000
#define CDisplay__is3dON_x                                         0x5481F0
#define CDisplay__ReloadUI_x                                       0x552710
#define CDisplay__WriteTextHD2_x                                   0x547FE0
#define CDisplay__TrueDistance_x                                   0x54ECC0
#define CDisplay__SetViewActor_x                                   0x54AEB0
#define CDisplay__GetFloorHeight_x                                 0x5482B0
#define CDisplay__SetRenderWindow_x                                0x546C10
#define CDisplay__ToggleScreenshotMode_x                           0x54A980

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x97ED60

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x962690
#define CEditWnd__EnsureCaretVisible_x                             0x964860
#define CEditWnd__GetCaretPt_x                                     0x963810
#define CEditWnd__GetCharIndexPt_x                                 0x9635C0
#define CEditWnd__GetDisplayString_x                               0x963460
#define CEditWnd__GetHorzOffset_x                                  0x961CC0
#define CEditWnd__GetLineForPrintableChar_x                        0x964760
#define CEditWnd__GetSelStartPt_x                                  0x963870
#define CEditWnd__GetSTMLSafeText_x                                0x963280
#define CEditWnd__PointFromPrintableChar_x                         0x964390
#define CEditWnd__SelectableCharFromPoint_x                        0x964500
#define CEditWnd__SetEditable_x                                    0x963940
#define CEditWnd__SetWindowTextA_x                                 0x963000
#define CEditWnd__ReplaceSelection_x                               0x964000
#define CEditWnd__ReplaceSelection1_x                              0x963F80

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60BB30
#define CEverQuest__ClickedPlayer_x                                0x5FDC60
#define CEverQuest__CreateTargetIndicator_x                        0x61B1F0
#define CEverQuest__DeleteTargetIndicator_x                        0x61B280
#define CEverQuest__DoTellWindow_x                                 0x4E8550
#define CEverQuest__OutputTextToLog_x                              0x4E8820
#define CEverQuest__DropHeldItemOnGround_x                         0x5F2CA0
#define CEverQuest__dsp_chat_x                                     0x4E8BB0
#define CEverQuest__trimName_x                                     0x617360
#define CEverQuest__Emote_x                                        0x60C390
#define CEverQuest__EnterZone_x                                    0x606430
#define CEverQuest__GetBodyTypeDesc_x                              0x610C50
#define CEverQuest__GetClassDesc_x                                 0x611290
#define CEverQuest__GetClassThreeLetterCode_x                      0x611890
#define CEverQuest__GetDeityDesc_x                                 0x619A40
#define CEverQuest__GetLangDesc_x                                  0x611A50
#define CEverQuest__GetRaceDesc_x                                  0x611270
#define CEverQuest__InterpretCmd_x                                 0x61A010
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F6EA0
#define CEverQuest__LMouseUp_x                                     0x5F5230
#define CEverQuest__RightClickedOnPlayer_x                         0x5F7780
#define CEverQuest__RMouseUp_x                                     0x5F61B0
#define CEverQuest__SetGameState_x                                 0x5F2A30
#define CEverQuest__UPCNotificationFlush_x                         0x617260
#define CEverQuest__IssuePetCommand_x                              0x612E50
#define CEverQuest__ReportSuccessfulHit_x                          0x60D6E0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x739A70
#define CGaugeWnd__CalcLinesFillRect_x                             0x739AD0
#define CGaugeWnd__Draw_x                                          0x7390F0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF300
#define CGuild__GetGuildName_x                                     0x4AE340
#define CGuild__GetGuildIndex_x                                    0x4AE780

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x753BD0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62CB90

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x760BD0
#define CInvSlotMgr__MoveItem_x                                    0x75F930
#define CInvSlotMgr__SelectSlot_x                                  0x760CA0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x75E170
#define CInvSlot__SliderComplete_x                                 0x75BED0
#define CInvSlot__GetItemBase_x                                    0x75B850
#define CInvSlot__UpdateItem_x                                     0x75B9C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x762730
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7618C0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7622B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x81C8E0
#define CItemDisplayWnd__UpdateStrings_x                           0x770E50
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76ABB0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76B0B0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x771450
#define CItemDisplayWnd__AboutToShow_x                             0x770AC0
#define CItemDisplayWnd__WndNotification_x                         0x772570
#define CItemDisplayWnd__RequestConvertItem_x                      0x771FF0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x76FB20
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7708E0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x855450

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x776A70

// CLabel 
#define CLabel__Draw_x                                             0x77C480

// CListWnd
#define CListWnd__CListWnd_x                                       0x934D50
#define CListWnd__dCListWnd_x                                      0x935070
#define CListWnd__AddColumn_x                                      0x9394B0
#define CListWnd__AddColumn1_x                                     0x939500
#define CListWnd__AddLine_x                                        0x939890
#define CListWnd__AddString_x                                      0x939690
#define CListWnd__CalculateFirstVisibleLine_x                      0x939280
#define CListWnd__CalculateVSBRange_x                              0x939060
#define CListWnd__ClearSel_x                                       0x93A070
#define CListWnd__ClearAllSel_x                                    0x93A0D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x93AAC0
#define CListWnd__Compare_x                                        0x938990
#define CListWnd__Draw_x                                           0x9351A0
#define CListWnd__DrawColumnSeparators_x                           0x937970
#define CListWnd__DrawHeader_x                                     0x937DD0
#define CListWnd__DrawItem_x                                       0x9382D0
#define CListWnd__DrawLine_x                                       0x937AD0
#define CListWnd__DrawSeparator_x                                  0x937A10
#define CListWnd__EnableLine_x                                     0x937260
#define CListWnd__EnsureVisible_x                                  0x93A9F0
#define CListWnd__ExtendSel_x                                      0x939FA0
#define CListWnd__GetColumnTooltip_x                               0x936DA0
#define CListWnd__GetColumnMinWidth_x                              0x936E10
#define CListWnd__GetColumnWidth_x                                 0x936D10
#define CListWnd__GetCurSel_x                                      0x9366A0
#define CListWnd__GetItemAtPoint_x                                 0x9374D0
#define CListWnd__GetItemAtPoint1_x                                0x937540
#define CListWnd__GetItemData_x                                    0x936720
#define CListWnd__GetItemHeight_x                                  0x936AE0
#define CListWnd__GetItemIcon_x                                    0x9368B0
#define CListWnd__GetItemRect_x                                    0x937350
#define CListWnd__GetItemText_x                                    0x936760
#define CListWnd__GetSelList_x                                     0x93A120
#define CListWnd__GetSeparatorRect_x                               0x937780
#define CListWnd__InsertLine_x                                     0x939C80
#define CListWnd__RemoveLine_x                                     0x939DD0
#define CListWnd__SetColors_x                                      0x939030
#define CListWnd__SetColumnJustification_x                         0x938D60
#define CListWnd__SetColumnLabel_x                                 0x939630
#define CListWnd__SetColumnWidth_x                                 0x938C80
#define CListWnd__SetCurSel_x                                      0x939EE0
#define CListWnd__SetItemColor_x                                   0x93A6B0
#define CListWnd__SetItemData_x                                    0x93A670
#define CListWnd__SetItemText_x                                    0x93A290
#define CListWnd__ShiftColumnSeparator_x                           0x938E20
#define CListWnd__Sort_x                                           0x938B10
#define CListWnd__ToggleSel_x                                      0x939F10
#define CListWnd__SetColumnsSizable_x                              0x938ED0
#define CListWnd__SetItemWnd_x                                     0x93A540
#define CListWnd__GetItemWnd_x                                     0x936900
#define CListWnd__SetItemIcon_x                                    0x93A310
#define CListWnd__CalculateCustomWindowPositions_x                 0x939370
#define CListWnd__SetVScrollPos_x                                  0x938C60

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x791D30
#define CMapViewWnd__GetWorldCoordinates_x                         0x790440
#define CMapViewWnd__HandleLButtonDown_x                           0x78D480

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B1F40
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B2820
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B2D50
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B5CC0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B0AA0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BB870
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B1B50

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8B8A80
#define CPacketScrambler__hton_x                                   0x8B8A70

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x953DA0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9541B0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x953FA0
#define CSidlManager__CreateLabel_x                                0x813B70
#define CSidlManager__CreateXWndFromTemplate_x                     0x957110
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9572F0
#define CSidlManager__CreateXWnd_x                                 0x813AA0
#define CSidlManager__CreateHotButtonWnd_x                         0x814060

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9508A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9507A0
#define CSidlScreenWnd__ConvertToRes_x                             0x9798B0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x950230
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x94FF20
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x94FFF0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9500C0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x950D20
#define CSidlScreenWnd__EnableIniStorage_x                         0x9511F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x950F10
#define CSidlScreenWnd__Init1_x                                    0x94FB40
#define CSidlScreenWnd__LoadIniInfo_x                              0x951240
#define CSidlScreenWnd__LoadIniListWnd_x                           0x951D80
#define CSidlScreenWnd__LoadSidlScreen_x                           0x94EF60
#define CSidlScreenWnd__StoreIniInfo_x                             0x951900
#define CSidlScreenWnd__StoreIniVis_x                              0x951C60
#define CSidlScreenWnd__WndNotification_x                          0x950C30
#define CSidlScreenWnd__GetChildItem_x                             0x951170
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9408E0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1601A58

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x691350
#define CSkillMgr__GetSkillCap_x                                   0x691530
#define CSkillMgr__GetNameToken_x                                  0x690AD0
#define CSkillMgr__IsActivatedSkill_x                              0x690C10
#define CSkillMgr__IsCombatSkill_x                                 0x690B50

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x960AA0
#define CSliderWnd__SetValue_x                                     0x960910
#define CSliderWnd__SetNumTicks_x                                  0x960970

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x819CB0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9692B0
#define CStmlWnd__ParseSTML_x                                      0x96A630
#define CStmlWnd__CalculateHSBRange_x                              0x96A410
#define CStmlWnd__CalculateVSBRange_x                              0x96A390
#define CStmlWnd__CanBreakAtCharacter_x                            0x96E740
#define CStmlWnd__FastForwardToEndOfTag_x                          0x96F3D0
#define CStmlWnd__ForceParseNow_x                                  0x9698F0
#define CStmlWnd__GetNextTagPiece_x                                0x96E6A0
#define CStmlWnd__GetSTMLText_x                                    0x509140
#define CStmlWnd__GetVisibleText_x                                 0x969910
#define CStmlWnd__InitializeWindowVariables_x                      0x96F220
#define CStmlWnd__MakeStmlColorTag_x                               0x968920
#define CStmlWnd__MakeWndNotificationTag_x                         0x968990
#define CStmlWnd__SetSTMLText_x                                    0x9679D0
#define CStmlWnd__StripFirstSTMLLines_x                            0x970490
#define CStmlWnd__UpdateHistoryString_x                            0x96F5E0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x966B20
#define CTabWnd__DrawCurrentPage_x                                 0x967250
#define CTabWnd__DrawTab_x                                         0x966F70
#define CTabWnd__GetCurrentPage_x                                  0x966320
#define CTabWnd__GetPageInnerRect_x                                0x966560
#define CTabWnd__GetTabInnerRect_x                                 0x9664A0
#define CTabWnd__GetTabRect_x                                      0x966350
#define CTabWnd__InsertPage_x                                      0x966770
#define CTabWnd__RemovePage_x                                      0x9668E0
#define CTabWnd__SetPage_x                                         0x9665E0
#define CTabWnd__SetPageRect_x                                     0x966A60
#define CTabWnd__UpdatePage_x                                      0x966E30
#define CTabWnd__GetPageFromTabIndex_x                             0x966EB0
#define CTabWnd__GetCurrentTabIndex_x                              0x966310

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x776E80
#define CPageWnd__SetTabText_x                                     0x965E60
#define CPageWnd__FlashTab_x                                       0x965EC0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8D40

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93D7A0
#define CTextureFont__GetTextExtent_x                              0x93D960

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C4560
#define CHtmlComponentWnd__ValidateUri_x                           0x7555C0
#define CHtmlWnd__SetClientCallbacks_x                             0x631C20
#define CHtmlWnd__AddObserver_x                                    0x631C40
#define CHtmlWnd__RemoveObserver_x                                 0x631CA0
#define Window__getProgress_x                                      0x86D8C0
#define Window__getStatus_x                                        0x86D8E0
#define Window__getURI_x                                           0x86D8F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9766C0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x92AA10

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8250
#define CXStr__CXStr1_x                                            0x4B63C0
#define CXStr__CXStr3_x                                            0x90BD50
#define CXStr__dCXStr_x                                            0x478800
#define CXStr__operator_equal_x                                    0x90BF80
#define CXStr__operator_equal1_x                                   0x90BFC0
#define CXStr__operator_plus_equal1_x                              0x90CA50
#define CXStr__SetString_x                                         0x90E940
#define CXStr__operator_char_p_x                                   0x90C490
#define CXStr__GetChar_x                                           0x90E290
#define CXStr__Delete_x                                            0x90DB40
#define CXStr__GetUnicode_x                                        0x90E300
#define CXStr__GetLength_x                                         0x4A8AF0
#define CXStr__Mid_x                                               0x47D480
#define CXStr__Insert_x                                            0x90E360
#define CXStr__FindNext_x                                          0x90DFB0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x95ED20
#define CXWnd__BringToTop_x                                        0x944080
#define CXWnd__Center_x                                            0x943C00
#define CXWnd__ClrFocus_x                                          0x943A10
#define CXWnd__Destroy_x                                           0x943AC0
#define CXWnd__DoAllDrawing_x                                      0x940070
#define CXWnd__DrawChildren_x                                      0x940040
#define CXWnd__DrawColoredRect_x                                   0x9404D0
#define CXWnd__DrawTooltip_x                                       0x93EB90
#define CXWnd__DrawTooltipAtPoint_x                                0x93EC50
#define CXWnd__GetBorderFrame_x                                    0x940330
#define CXWnd__GetChildWndAt_x                                     0x944120
#define CXWnd__GetClientClipRect_x                                 0x9422C0
#define CXWnd__GetScreenClipRect_x                                 0x942390
#define CXWnd__GetScreenRect_x                                     0x942550
#define CXWnd__GetRelativeRect_x                                   0x942610
#define CXWnd__GetTooltipRect_x                                    0x940520
#define CXWnd__GetWindowTextA_x                                    0x49C970
#define CXWnd__IsActive_x                                          0x940C60
#define CXWnd__IsDescendantOf_x                                    0x942F60
#define CXWnd__IsReallyVisible_x                                   0x942F90
#define CXWnd__IsType_x                                            0x944780
#define CXWnd__Move_x                                              0x942FF0
#define CXWnd__Move1_x                                             0x9430B0
#define CXWnd__ProcessTransition_x                                 0x943BB0
#define CXWnd__Refade_x                                            0x943390
#define CXWnd__Resize_x                                            0x943620
#define CXWnd__Right_x                                             0x943E40
#define CXWnd__SetFocus_x                                          0x9439D0
#define CXWnd__SetFont_x                                           0x943A40
#define CXWnd__SetKeyTooltip_x                                     0x944590
#define CXWnd__SetMouseOver_x                                      0x941490
#define CXWnd__StartFade_x                                         0x942E40
#define CXWnd__GetChildItem_x                                      0x944290
#define CXWnd__SetParent_x                                         0x942CF0
#define CXWnd__Minimize_x                                          0x943690

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x97A930

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x946FB0
#define CXWndManager__DrawWindows_x                                0x946FD0
#define CXWndManager__GetKeyboardFlags_x                           0x949760
#define CXWndManager__HandleKeyboardMsg_x                          0x949310
#define CXWndManager__RemoveWnd_x                                  0x949980
#define CXWndManager__RemovePendingDeletionWnd_x                   0x949EE0

// CDBStr
#define CDBStr__GetString_x                                        0x542BA0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBAC0
#define EQ_Character__Cur_HP_x                                     0x4D1CE0
#define EQ_Character__Cur_Mana_x                                   0x4D9410
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEB00
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2580
#define EQ_Character__GetFocusRangeModifier_x                      0x4B26D0
#define EQ_Character__GetHPRegen_x                                 0x4DF1B0
#define EQ_Character__GetEnduranceRegen_x                          0x4DF7B0
#define EQ_Character__GetManaRegen_x                               0x4DFBF0
#define EQ_Character__Max_Endurance_x                              0x6579C0
#define EQ_Character__Max_HP_x                                     0x4D1B10
#define EQ_Character__Max_Mana_x                                   0x6577C0
#define EQ_Character__doCombatAbility_x                            0x659E00
#define EQ_Character__UseSkill_x                                   0x4E19E0
#define EQ_Character__GetConLevel_x                                0x650CC0
#define EQ_Character__IsExpansionFlag_x                            0x5B4710
#define EQ_Character__TotalEffect_x                                0x4C4E70
#define EQ_Character__GetPCSpellAffect_x                           0x4BF850
#define EQ_Character__SpellDuration_x                              0x4BF380
#define EQ_Character__GetAdjustedSkill_x                           0x4D4A60
#define EQ_Character__GetBaseSkill_x                               0x4D5A00
#define EQ_Character__CanUseItem_x                                 0x4D9720

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8D7D60

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x66DEA0

//PcClient
#define PcClient__PcClient_x                                       0x64E400

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9700
#define CCharacterListWnd__EnterWorld_x                            0x4B9140
#define CCharacterListWnd__Quit_x                                  0x4B8E90
#define CCharacterListWnd__UpdateList_x                            0x4B92D0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x632DF0
#define EQ_Item__CreateItemTagString_x                             0x8B2010
#define EQ_Item__IsStackable_x                                     0x8B6C90
#define EQ_Item__GetImageNum_x                                     0x8B3AE0
#define EQ_Item__CreateItemClient_x                                0x632020
#define EQ_Item__GetItemValue_x                                    0x8B4EA0
#define EQ_Item__ValueSellMerchant_x                               0x8B8650
#define EQ_Item__IsKeyRingItem_x                                   0x8B6590
#define EQ_Item__CanGoInBag_x                                      0x632F10
#define EQ_Item__IsEmpty_x                                         0x8B60F0
#define EQ_Item__GetMaxItemCount_x                                 0x8B52C0
#define EQ_Item__GetHeldItem_x                                     0x8B39B0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8B1860

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x561870
#define EQ_LoadingS__Array_x                                       0xC38C60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x658300
#define EQ_PC__GetAlternateAbilityId_x                             0x8C1A90
#define EQ_PC__GetCombatAbility_x                                  0x8C2100
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C2170
#define EQ_PC__GetItemRecastTimer_x                                0x65A380
#define EQ_PC__HasLoreItem_x                                       0x6514D0
#define EQ_PC__AlertInventoryChanged_x                             0x6505F0
#define EQ_PC__GetPcZoneClient_x                                   0x67C8C0
#define EQ_PC__RemoveMyAffect_x                                    0x65D5B0
#define EQ_PC__GetKeyRingItems_x                                   0x8C2A00
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C2790
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C2D00

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BAC70
#define EQItemList__add_object_x                                   0x5E84C0
#define EQItemList__add_item_x                                     0x5BB1D0
#define EQItemList__delete_item_x                                  0x5BB220
#define EQItemList__FreeItemList_x                                 0x5BB120

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53F6A0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x66F720
#define EQPlayer__dEQPlayer_x                                      0x662A60
#define EQPlayer__DoAttack_x                                       0x677550
#define EQPlayer__EQPlayer_x                                       0x663120
#define EQPlayer__SetNameSpriteState_x                             0x667400
#define EQPlayer__SetNameSpriteTint_x                              0x6682D0
#define PlayerBase__HasProperty_j_x                                0x9A96A0
#define EQPlayer__IsTargetable_x                                   0x9A9B40
#define EQPlayer__CanSee_x                                         0x9A99A0
#define EQPlayer__CanSee1_x                                        0x9A9A70
#define PlayerBase__GetVisibilityLineSegment_x                     0x9A9760

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67A350
#define PlayerZoneClient__GetLevel_x                               0x67C900
#define PlayerZoneClient__IsValidTeleport_x                        0x5E9630
#define PlayerZoneClient__LegalPlayerRace_x                        0x55A590

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x672470
#define EQPlayerManager__GetSpawnByName_x                          0x672520
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6725B0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x636460
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6364E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x636520
#define KeypressHandler__ClearCommandStateArray_x                  0x637930
#define KeypressHandler__HandleKeyDown_x                           0x637950
#define KeypressHandler__HandleKeyUp_x                             0x6379F0
#define KeypressHandler__SaveKeymapping_x                          0x637E40

// MapViewMap 
#define MapViewMap__Clear_x                                        0x78DBA0
#define MapViewMap__SaveEx_x                                       0x790F60
#define MapViewMap__SetZoom_x                                      0x795620

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D5DC0

// StringTable 
#define StringTable__getString_x                                   0x8D0C80

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x65D220
#define PcZoneClient__RemovePetEffect_x                            0x65D850
#define PcZoneClient__HasAlternateAbility_x                        0x6575F0
#define PcZoneClient__GetCurrentMod_x                              0x4E4AA0
#define PcZoneClient__GetModCap_x                                  0x4E49A0
#define PcZoneClient__CanEquipItem_x                               0x657CA0
#define PcZoneClient__GetItemByID_x                                0x65A7F0
#define PcZoneClient__GetItemByItemClass_x                         0x65A940
#define PcZoneClient__RemoveBuffEffect_x                           0x65D870
#define PcZoneClient__BandolierSwap_x                              0x6588C0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65A320

//Doors
#define EQSwitch__UseSwitch_x                                      0x5EE0E0

//IconCache
#define IconCache__GetIcon_x                                       0x72F130

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x726C20
#define CContainerMgr__CloseContainer_x                            0x726EF0
#define CContainerMgr__OpenExperimentContainer_x                   0x727970

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E60A0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62AFC0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x783F50
#define CLootWnd__RequestLootSlot_x                                0x783180

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x588070
#define EQ_Spell__SpellAffects_x                                   0x5884E0
#define EQ_Spell__SpellAffectBase_x                                0x5882A0
#define EQ_Spell__IsStackable_x                                    0x4C9730
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9550
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6A80
#define EQ_Spell__IsSPAStacking_x                                  0x589330
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x588840
#define EQ_Spell__IsNoRemove_x                                     0x4C9710
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x589340
#define __IsResEffectSpell_x                                       0x4C88D0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACEB0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8E0300

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82D0A0
#define CTargetWnd__WndNotification_x                              0x82C8E0
#define CTargetWnd__RefreshTargetBuffs_x                           0x82CBB0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82BA40

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x8316E0
#define CTaskWnd__ConfirmAbandonTask_x                             0x834320

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53D110
#define CTaskManager__HandleMessage_x                              0x53B5A0
#define CTaskManager__GetTaskStatus_x                              0x53D1C0
#define CTaskManager__GetElementDescription_x                      0x53D240

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x583280
#define EqSoundManager__PlayScriptMp3_x                            0x583540
#define EqSoundManager__SoundAssistPlay_x                          0x695320
#define EqSoundManager__WaveInstancePlay_x                         0x694890

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52E7B0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x965370
#define CTextureAnimation__Draw_x                                  0x965570

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x961400

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x569320
#define CAltAbilityData__GetMercMaxRank_x                          0x5692B0
#define CAltAbilityData__GetMaxRank_x                              0x55E7C0

//CTargetRing
#define CTargetRing__Cast_x                                        0x6290E0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9530
#define CharacterBase__CreateItemGlobalIndex_x                     0x515CA0
#define CharacterBase__CreateItemIndex_x                           0x6311D0
#define CharacterBase__GetItemPossession_x                         0x5019A0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8E8950
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8E89B0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x70DC70
#define CCastSpellWnd__IsBardSongPlaying_x                         0x70E4A0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x70E550

//messages
#define msg_spell_worn_off_x                                       0x5ACC10
#define msg_new_text_x                                             0x5A15C0
#define __msgTokenTextParam_x                                      0x5AEEA0
#define msgTokenText_x                                             0x5AF0F0

//SpellManager
#define SpellManager__vftable_x                                    0xAFC138
#define SpellManager__SpellManager_x                               0x698650
#define Spellmanager__LoadTextSpells_x                             0x698F40
#define SpellManager__GetSpellByGroupAndRank_x                     0x698820

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9AD5D0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5162F0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B2B60
#define ItemGlobalIndex__IsEquippedLocation_x                      0x649B30
#define ItemGlobalIndex__IsValidIndex_x                            0x516350

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8E0CA0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8E0F20

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77C7C0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72B330
#define CCursorAttachment__AttachToCursor1_x                       0x72B370
#define CCursorAttachment__Deactivate_x                            0x72C360

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x958140
#define CSidlManagerBase__CreatePageWnd_x                          0x957940
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x953BC0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x953B50

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x975270
#define CEQSuiteTextureLoader__GetTexture_x                        0x974F30

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x513270
#define CFindItemWnd__WndNotification_x                            0x513D50
#define CFindItemWnd__Update_x                                     0x5148C0
#define CFindItemWnd__PickupSelectedItem_x                         0x512AC0

//IString
#define IString__Append_x                                          0x503280

//Camera
#define CDisplay__cameraType_x                                     0xE1224C
#define EverQuest__Cameras_x                                       0xECD534

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51B9A0
#define LootFiltersManager__GetItemFilterData_x                    0x51B2A0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51B2D0
#define LootFiltersManager__SetItemLootFilter_x                    0x51B4F0

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D3E80

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B31D0
#define CResolutionHandler__GetWindowedStyle_x                     0x68FC60

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7238D0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F6220
#define CDistillerInfo__Instance_x                                 0x8F61C0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7429E0
#define CGroupWnd__UpdateDisplay_x                                 0x741D30

//ItemBase
#define ItemBase__IsLore_x                                         0x8B6640
#define ItemBase__IsLoreEquipped_x                                 0x8B66C0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5E8420
#define EQPlacedItemManager__GetItemByGuid_x                       0x5E8560
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5E85C0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x684FE0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x688960

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x509740

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F5CE0
#define FactionManagerClient__HandleFactionMessage_x               0x4F6350
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F6950
#define FactionManagerClient__GetMaxFaction_x                      0x4F696F
#define FactionManagerClient__GetMinFaction_x                      0x4F6920

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x501970

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x93C760

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BC80

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x501C90

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x5687D0

//CTargetManager
#define CTargetManager__Get_x                                      0x69BE70

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x684FE0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8B00

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BB0C0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF6ABC8

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6D7600
#define CAAWnd__UpdateSelected_x                                   0x6D3E70
#define CAAWnd__Update_x                                           0x6D6920

//CXRect
#define CXRect__operator_and_x                                     0x739B30

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
