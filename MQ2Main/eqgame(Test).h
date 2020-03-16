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
#define __ExpectedVersionDate                                     "Mar  9 2020"
#define __ExpectedVersionTime                                     "11:52:24"
#define __ActualVersionDate_x                                      0xB19388
#define __ActualVersionTime_x                                      0xB1937C
#define __ActualVersionBuild_x                                     0xB050EC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x63CE40
#define __MemChecker1_x                                            0x9104B0
#define __MemChecker2_x                                            0x6CB3D0
#define __MemChecker3_x                                            0x6CB320
#define __MemChecker4_x                                            0x8666E0
#define __EncryptPad0_x                                            0xC514E8
#define __EncryptPad1_x                                            0xCAF650
#define __EncryptPad2_x                                            0xC61D80
#define __EncryptPad3_x                                            0xC61980
#define __EncryptPad4_x                                            0xC9FC00
#define __EncryptPad5_x                                            0xF707DC
#define __AC1_x                                                    0x8233C6
#define __AC2_x                                                    0x5F693F
#define __AC3_x                                                    0x5FE03F
#define __AC4_x                                                    0x602010
#define __AC5_x                                                    0x60831F
#define __AC6_x                                                    0x60C816
#define __AC7_x                                                    0x5F63B0
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
#define __do_loot_x                                                0x5C2400
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
#define __gfMaxZoomCameraDistance_x                                0xB0ED00
#define __gfMaxCameraDistance_x                                    0xB3B084
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
#define pinstCamActor_x                                            0xE1219C
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
#define pinstViewActor_x                                           0xE12198
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
#define pinstCInspectWnd_x                                         0xE12194
#define pinstCInventoryWnd_x                                       0xE12168
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
#define pinstCMailIgnoreListWnd_x                                  0xE1249C
#define pinstCMailWnd_x                                            0xE1224C
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
#define pinstCRealEstatePurchaseWnd_x                              0xE12240
#define pinstCRespawnWnd_x                                         0xE12188
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE1296C
#define pinstCSendMoneyWnd_x                                       0xE129DC
#define pinstCServerListWnd_x                                      0xE12250
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
#define pinstCTrainWnd_x                                           0xE1225C
#define pinstCTributeBenefitWnd_x                                  0xF86AE0
#define pinstCTributeMasterWnd_x                                   0xF86B90
#define pinstCTributeTrophyWnd_x                                   0xF86C40
#define pinstCVideoModesWnd_x                                      0xE12244
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
#define __CastRay_x                                                0x5BD7D0
#define __CastRay2_x                                               0x5BD820
#define __ConvertItemTags_x                                        0x5D93E0
#define __CleanItemTags_x                                          0x47D110
#define __DoesFileExist_x                                          0x9134E0
#define __EQGetTime_x                                              0x90FF80
#define __ExecuteCmd_x                                             0x5B6070
#define __FixHeading_x                                             0x9AB570
#define __GameLoop_x                                               0x6CA5A0
#define __get_bearing_x                                            0x5BD340
#define __get_melee_range_x                                        0x5BDA10
#define __GetAnimationCache_x                                      0x72FA10
#define __GetGaugeValueFromEQ_x                                    0x821870
#define __GetLabelFromEQ_x                                         0x823350
#define __GetXTargetType_x                                         0x9AD0A0
#define __HandleMouseWheel_x                                       0x6CB480
#define __HeadingDiff_x                                            0x9AB5E0
#define __HelpPath_x                                               0xF6B294
#define __LoadFrontEnd_x                                           0x6C78C0
#define __NewUIINI_x                                               0x821540
#define __ProcessGameEvents_x                                      0x61E120
#define __ProcessMouseEvent_x                                      0x61D8E0
#define __SaveColors_x                                             0x558D80
#define __STMLToText_x                                             0x94EAB0
#define __ToggleKeyRingItem_x                                      0x519810
#define CMemoryMappedFile__SetFile_x                               0xA9AB00
#define CrashDetected_x                                            0x6C9360
#define DrawNetStatus_x                                            0x64A300
#define Expansion_HoT_x                                            0xECD1E4
#define Teleport_Table_Size_x                                      0xEC6CA4
#define Teleport_Table_x                                           0xEC4860
#define Util__FastTime_x                                           0x90FB50

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490290
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4991A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498F70
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493830
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492C80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x560F70
#define AltAdvManager__IsAbilityReady_x                            0x55FD10
#define AltAdvManager__GetAAById_x                                 0x5600A0
#define AltAdvManager__CanTrainAbility_x                           0x560110
#define AltAdvManager__CanSeeAbility_x                             0x560470

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9D60
#define CharacterZoneClient__HasSkill_x                            0x4D4BE0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6300
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE360
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA990
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8C80
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8D60
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8E40
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2A60
#define CharacterZoneClient__BardCastBard_x                        0x4C55E0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAA60
#define CharacterZoneClient__GetEffect_x                           0x4BA8D0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3AB0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3B80
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3BD0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3D20
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C3EF0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2820
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7260
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6CE0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6F1000
#define CBankWnd__WndNotification_x                                0x6F0DE0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6FE760

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x62CA50
#define CButtonWnd__CButtonWnd_x                                   0x94AE80

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x71EA70
#define CChatManager__InitContextMenu_x                            0x717BA0
#define CChatManager__FreeChatWindow_x                             0x71D5B0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E83B0
#define CChatManager__SetLockedActiveChatWindow_x                  0x71E6F0
#define CChatManager__CreateChatWindow_x                           0x71DBF0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E84C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x95F550
#define CContextMenu__dCContextMenu_x                              0x95F790
#define CContextMenu__AddMenuItem_x                                0x95F7A0
#define CContextMenu__RemoveMenuItem_x                             0x95FAB0
#define CContextMenu__RemoveAllMenuItems_x                         0x95FAD0
#define CContextMenu__CheckMenuItem_x                              0x95FB50
#define CContextMenu__SetMenuItem_x                                0x95F9D0
#define CContextMenu__AddSeparator_x                               0x95F930

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9600F0
#define CContextMenuManager__RemoveMenu_x                          0x960160
#define CContextMenuManager__PopupMenu_x                           0x960220
#define CContextMenuManager__Flush_x                               0x960090
#define CContextMenuManager__GetMenu_x                             0x49B2A0
#define CContextMenuManager__CreateDefaultMenu_x                   0x72A220

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8B59A0
#define CChatService__GetFriendName_x                              0x8EB2D0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x71F2E0
#define CChatWindow__Clear_x                                       0x7205A0
#define CChatWindow__WndNotification_x                             0x720D30
#define CChatWindow__AddHistory_x                                  0x71FE60

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x95C9A0
#define CComboWnd__Draw_x                                          0x95BE80
#define CComboWnd__GetCurChoice_x                                  0x95C7E0
#define CComboWnd__GetListRect_x                                   0x95C340
#define CComboWnd__GetTextRect_x                                   0x95CA10
#define CComboWnd__InsertChoice_x                                  0x95C4D0
#define CComboWnd__SetColors_x                                     0x95C4A0
#define CComboWnd__SetChoice_x                                     0x95C7B0
#define CComboWnd__GetItemCount_x                                  0x95C7F0
#define CComboWnd__GetCurChoiceText_x                              0x95C830
#define CComboWnd__GetChoiceText_x                                 0x95C800
#define CComboWnd__InsertChoiceAtIndex_x                           0x95C570

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x727BF0
#define CContainerWnd__vftable_x                                   0xB2256C
#define CContainerWnd__SetContainer_x                              0x729160

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x553730
#define CDisplay__PreZoneMainUI_x                                  0x553740
#define CDisplay__CleanGameUI_x                                    0x558B40
#define CDisplay__GetClickedActor_x                                0x54BA30
#define CDisplay__GetUserDefinedColor_x                            0x544090
#define CDisplay__GetWorldFilePath_x                               0x54D4A0
#define CDisplay__is3dON_x                                         0x548690
#define CDisplay__ReloadUI_x                                       0x552BB0
#define CDisplay__WriteTextHD2_x                                   0x548480
#define CDisplay__TrueDistance_x                                   0x54F160
#define CDisplay__SetViewActor_x                                   0x54B350
#define CDisplay__GetFloorHeight_x                                 0x548750
#define CDisplay__SetRenderWindow_x                                0x5470B0
#define CDisplay__ToggleScreenshotMode_x                           0x54AE20

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x97F1E0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x962AA0
#define CEditWnd__EnsureCaretVisible_x                             0x964C70
#define CEditWnd__GetCaretPt_x                                     0x963C20
#define CEditWnd__GetCharIndexPt_x                                 0x9639D0
#define CEditWnd__GetDisplayString_x                               0x963870
#define CEditWnd__GetHorzOffset_x                                  0x9620D0
#define CEditWnd__GetLineForPrintableChar_x                        0x964B70
#define CEditWnd__GetSelStartPt_x                                  0x963C80
#define CEditWnd__GetSTMLSafeText_x                                0x963690
#define CEditWnd__PointFromPrintableChar_x                         0x9647A0
#define CEditWnd__SelectableCharFromPoint_x                        0x964910
#define CEditWnd__SetEditable_x                                    0x963D50
#define CEditWnd__SetWindowTextA_x                                 0x963410
#define CEditWnd__ReplaceSelection_x                               0x964410
#define CEditWnd__ReplaceSelection1_x                              0x964390

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60BCF0
#define CEverQuest__ClickedPlayer_x                                0x5FDE20
#define CEverQuest__CreateTargetIndicator_x                        0x61B3B0
#define CEverQuest__DeleteTargetIndicator_x                        0x61B440
#define CEverQuest__DoTellWindow_x                                 0x4E85A0
#define CEverQuest__OutputTextToLog_x                              0x4E8870
#define CEverQuest__DropHeldItemOnGround_x                         0x5F2E60
#define CEverQuest__dsp_chat_x                                     0x4E8C00
#define CEverQuest__trimName_x                                     0x617520
#define CEverQuest__Emote_x                                        0x60C550
#define CEverQuest__EnterZone_x                                    0x6065F0
#define CEverQuest__GetBodyTypeDesc_x                              0x610E10
#define CEverQuest__GetClassDesc_x                                 0x611450
#define CEverQuest__GetClassThreeLetterCode_x                      0x611A50
#define CEverQuest__GetDeityDesc_x                                 0x619C00
#define CEverQuest__GetLangDesc_x                                  0x611C10
#define CEverQuest__GetRaceDesc_x                                  0x611430
#define CEverQuest__InterpretCmd_x                                 0x61A1D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F7060
#define CEverQuest__LMouseUp_x                                     0x5F53F0
#define CEverQuest__RightClickedOnPlayer_x                         0x5F7940
#define CEverQuest__RMouseUp_x                                     0x5F6370
#define CEverQuest__SetGameState_x                                 0x5F2BF0
#define CEverQuest__UPCNotificationFlush_x                         0x617420
#define CEverQuest__IssuePetCommand_x                              0x613010
#define CEverQuest__ReportSuccessfulHit_x                          0x60D8A0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x739AD0
#define CGaugeWnd__CalcLinesFillRect_x                             0x739B30
#define CGaugeWnd__Draw_x                                          0x739160

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF300
#define CGuild__GetGuildName_x                                     0x4AE340
#define CGuild__GetGuildIndex_x                                    0x4AE780

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x753CD0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62CE10

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x760CE0
#define CInvSlotMgr__MoveItem_x                                    0x75F9F0
#define CInvSlotMgr__SelectSlot_x                                  0x760DB0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x75E270
#define CInvSlot__SliderComplete_x                                 0x75BFD0
#define CInvSlot__GetItemBase_x                                    0x75B950
#define CInvSlot__UpdateItem_x                                     0x75BAC0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x762830
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7619D0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7623B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x81CC20
#define CItemDisplayWnd__UpdateStrings_x                           0x771030
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76ACB0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76B1E0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x771630
#define CItemDisplayWnd__AboutToShow_x                             0x770C80
#define CItemDisplayWnd__WndNotification_x                         0x772770
#define CItemDisplayWnd__RequestConvertItem_x                      0x7721E0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x76FCF0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x770AA0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x855900

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x776C80

// CLabel 
#define CLabel__Draw_x                                             0x77C730

// CListWnd
#define CListWnd__CListWnd_x                                       0x9351C0
#define CListWnd__dCListWnd_x                                      0x9354E0
#define CListWnd__AddColumn_x                                      0x939960
#define CListWnd__AddColumn1_x                                     0x9399B0
#define CListWnd__AddLine_x                                        0x939D40
#define CListWnd__AddString_x                                      0x939B40
#define CListWnd__CalculateFirstVisibleLine_x                      0x939720
#define CListWnd__CalculateVSBRange_x                              0x939500
#define CListWnd__ClearSel_x                                       0x93A520
#define CListWnd__ClearAllSel_x                                    0x93A580
#define CListWnd__CloseAndUpdateEditWindow_x                       0x93AFA0
#define CListWnd__Compare_x                                        0x938E30
#define CListWnd__Draw_x                                           0x935610
#define CListWnd__DrawColumnSeparators_x                           0x937E00
#define CListWnd__DrawHeader_x                                     0x938270
#define CListWnd__DrawItem_x                                       0x938770
#define CListWnd__DrawLine_x                                       0x937F70
#define CListWnd__DrawSeparator_x                                  0x937EA0
#define CListWnd__EnableLine_x                                     0x9376D0
#define CListWnd__EnsureVisible_x                                  0x93AEC0
#define CListWnd__ExtendSel_x                                      0x93A450
#define CListWnd__GetColumnTooltip_x                               0x937210
#define CListWnd__GetColumnMinWidth_x                              0x937280
#define CListWnd__GetColumnWidth_x                                 0x937180
#define CListWnd__GetCurSel_x                                      0x936B10
#define CListWnd__GetItemAtPoint_x                                 0x937950
#define CListWnd__GetItemAtPoint1_x                                0x9379C0
#define CListWnd__GetItemData_x                                    0x936B90
#define CListWnd__GetItemHeight_x                                  0x936F50
#define CListWnd__GetItemIcon_x                                    0x936D20
#define CListWnd__GetItemRect_x                                    0x9377C0
#define CListWnd__GetItemText_x                                    0x936BD0
#define CListWnd__GetSelList_x                                     0x93A5D0
#define CListWnd__GetSeparatorRect_x                               0x937C00
#define CListWnd__InsertLine_x                                     0x93A130
#define CListWnd__RemoveLine_x                                     0x93A280
#define CListWnd__SetColors_x                                      0x9394D0
#define CListWnd__SetColumnJustification_x                         0x939200
#define CListWnd__SetColumnLabel_x                                 0x939AE0
#define CListWnd__SetColumnWidth_x                                 0x939120
#define CListWnd__SetCurSel_x                                      0x93A390
#define CListWnd__SetItemColor_x                                   0x93AB70
#define CListWnd__SetItemData_x                                    0x93AB30
#define CListWnd__SetItemText_x                                    0x93A740
#define CListWnd__ShiftColumnSeparator_x                           0x9392C0
#define CListWnd__Sort_x                                           0x938FB0
#define CListWnd__ToggleSel_x                                      0x93A3C0
#define CListWnd__SetColumnsSizable_x                              0x939370
#define CListWnd__SetItemWnd_x                                     0x93A9F0
#define CListWnd__GetItemWnd_x                                     0x936D70
#define CListWnd__SetItemIcon_x                                    0x93A7C0
#define CListWnd__CalculateCustomWindowPositions_x                 0x939820
#define CListWnd__SetVScrollPos_x                                  0x939100

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x791F70
#define CMapViewWnd__GetWorldCoordinates_x                         0x790680
#define CMapViewWnd__HandleLButtonDown_x                           0x78D6C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B2310
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B2BF0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B3120
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B60B0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B0E80
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BBC70
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B1F30

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8B8D90
#define CPacketScrambler__hton_x                                   0x8B8D80

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9540C0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9544D0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9542C0
#define CSidlManager__CreateLabel_x                                0x813E10
#define CSidlManager__CreateXWndFromTemplate_x                     0x957430
#define CSidlManager__CreateXWndFromTemplate1_x                    0x957610
#define CSidlManager__CreateXWnd_x                                 0x813D40
#define CSidlManager__CreateHotButtonWnd_x                         0x814310

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x950BE0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x950AE0
#define CSidlScreenWnd__ConvertToRes_x                             0x979CE0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x950570
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x950260
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x950330
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x950400
#define CSidlScreenWnd__DrawSidlPiece_x                            0x951080
#define CSidlScreenWnd__EnableIniStorage_x                         0x951550
#define CSidlScreenWnd__GetSidlPiece_x                             0x951270
#define CSidlScreenWnd__Init1_x                                    0x94FE60
#define CSidlScreenWnd__LoadIniInfo_x                              0x9515A0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9520A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x94F270
#define CSidlScreenWnd__StoreIniInfo_x                             0x951C30
#define CSidlScreenWnd__StoreIniVis_x                              0x951F80
#define CSidlScreenWnd__WndNotification_x                          0x950F90
#define CSidlScreenWnd__GetChildItem_x                             0x9514D0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x940D70
#define CSidlScreenWnd__m_layoutCopy_x                             0x1601A58

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x691940
#define CSkillMgr__GetSkillCap_x                                   0x691B20
#define CSkillMgr__GetNameToken_x                                  0x6910C0
#define CSkillMgr__IsActivatedSkill_x                              0x691200
#define CSkillMgr__IsCombatSkill_x                                 0x691140

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x960EB0
#define CSliderWnd__SetValue_x                                     0x960D20
#define CSliderWnd__SetNumTicks_x                                  0x960D80

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x819FF0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x9696D0
#define CStmlWnd__ParseSTML_x                                      0x96AA20
#define CStmlWnd__CalculateHSBRange_x                              0x96A7F0
#define CStmlWnd__CalculateVSBRange_x                              0x96A770
#define CStmlWnd__CanBreakAtCharacter_x                            0x96EB30
#define CStmlWnd__FastForwardToEndOfTag_x                          0x96F7C0
#define CStmlWnd__ForceParseNow_x                                  0x969CC0
#define CStmlWnd__GetNextTagPiece_x                                0x96EA90
#define CStmlWnd__GetSTMLText_x                                    0x508FB0
#define CStmlWnd__GetVisibleText_x                                 0x969CE0
#define CStmlWnd__InitializeWindowVariables_x                      0x96F610
#define CStmlWnd__MakeStmlColorTag_x                               0x968D40
#define CStmlWnd__MakeWndNotificationTag_x                         0x968DB0
#define CStmlWnd__SetSTMLText_x                                    0x967DF0
#define CStmlWnd__StripFirstSTMLLines_x                            0x9708C0
#define CStmlWnd__UpdateHistoryString_x                            0x96F9D0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x966F40
#define CTabWnd__DrawCurrentPage_x                                 0x967670
#define CTabWnd__DrawTab_x                                         0x967390
#define CTabWnd__GetCurrentPage_x                                  0x966740
#define CTabWnd__GetPageInnerRect_x                                0x966980
#define CTabWnd__GetTabInnerRect_x                                 0x9668C0
#define CTabWnd__GetTabRect_x                                      0x966770
#define CTabWnd__InsertPage_x                                      0x966B90
#define CTabWnd__RemovePage_x                                      0x966D00
#define CTabWnd__SetPage_x                                         0x966A00
#define CTabWnd__SetPageRect_x                                     0x966E80
#define CTabWnd__UpdatePage_x                                      0x967250
#define CTabWnd__GetPageFromTabIndex_x                             0x9672D0
#define CTabWnd__GetCurrentTabIndex_x                              0x966730

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7770C0
#define CPageWnd__SetTabText_x                                     0x966280
#define CPageWnd__FlashTab_x                                       0x9662E0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8D20

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93DBF0
#define CTextureFont__GetTextExtent_x                              0x93DDB0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C4730
#define CHtmlComponentWnd__ValidateUri_x                           0x7556C0
#define CHtmlWnd__SetClientCallbacks_x                             0x631E80
#define CHtmlWnd__AddObserver_x                                    0x631EA0
#define CHtmlWnd__RemoveObserver_x                                 0x631F00
#define Window__getProgress_x                                      0x86DD00
#define Window__getStatus_x                                        0x86DD20
#define Window__getURI_x                                           0x86DD30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x976AB0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x92ADF0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E81F0
#define CXStr__CXStr1_x                                            0x85E7E0
#define CXStr__CXStr3_x                                            0x90C120
#define CXStr__dCXStr_x                                            0x478770
#define CXStr__operator_equal_x                                    0x90C350
#define CXStr__operator_equal1_x                                   0x90C390
#define CXStr__operator_plus_equal1_x                              0x90CE20
#define CXStr__SetString_x                                         0x90ED10
#define CXStr__operator_char_p_x                                   0x90C860
#define CXStr__GetChar_x                                           0x90E640
#define CXStr__Delete_x                                            0x90DF10
#define CXStr__GetUnicode_x                                        0x90E6B0
#define CXStr__GetLength_x                                         0x47D4C0
#define CXStr__Mid_x                                               0x47D4D0
#define CXStr__Insert_x                                            0x90E710
#define CXStr__FindNext_x                                          0x90E380

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x95F160
#define CXWnd__BringToTop_x                                        0x9444C0
#define CXWnd__Center_x                                            0x944040
#define CXWnd__ClrFocus_x                                          0x943E50
#define CXWnd__Destroy_x                                           0x943F00
#define CXWnd__DoAllDrawing_x                                      0x940500
#define CXWnd__DrawChildren_x                                      0x9404D0
#define CXWnd__DrawColoredRect_x                                   0x940960
#define CXWnd__DrawTooltip_x                                       0x93F010
#define CXWnd__DrawTooltipAtPoint_x                                0x93F0D0
#define CXWnd__GetBorderFrame_x                                    0x9407C0
#define CXWnd__GetChildWndAt_x                                     0x944560
#define CXWnd__GetClientClipRect_x                                 0x9427C0
#define CXWnd__GetScreenClipRect_x                                 0x942890
#define CXWnd__GetScreenRect_x                                     0x942A30
#define CXWnd__GetRelativeRect_x                                   0x942AF0
#define CXWnd__GetTooltipRect_x                                    0x9409B0
#define CXWnd__GetWindowTextA_x                                    0x49CA30
#define CXWnd__IsActive_x                                          0x9410E0
#define CXWnd__IsDescendantOf_x                                    0x9433F0
#define CXWnd__IsReallyVisible_x                                   0x943420
#define CXWnd__IsType_x                                            0x944BE0
#define CXWnd__Move_x                                              0x943490
#define CXWnd__Move1_x                                             0x943540
#define CXWnd__ProcessTransition_x                                 0x943FF0
#define CXWnd__Refade_x                                            0x9437F0
#define CXWnd__Resize_x                                            0x943A80
#define CXWnd__Right_x                                             0x944280
#define CXWnd__SetFocus_x                                          0x943E10
#define CXWnd__SetFont_x                                           0x943E80
#define CXWnd__SetKeyTooltip_x                                     0x9449F0
#define CXWnd__SetMouseOver_x                                      0x941910
#define CXWnd__StartFade_x                                         0x9432E0
#define CXWnd__GetChildItem_x                                      0x9446D0
#define CXWnd__SetParent_x                                         0x943190
#define CXWnd__Minimize_x                                          0x943AF0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x97AD60

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9473F0
#define CXWndManager__DrawWindows_x                                0x947410
#define CXWndManager__GetKeyboardFlags_x                           0x949B30
#define CXWndManager__HandleKeyboardMsg_x                          0x9496E0
#define CXWndManager__RemoveWnd_x                                  0x949D50
#define CXWndManager__RemovePendingDeletionWnd_x                   0x94A2B0

// CDBStr
#define CDBStr__GetString_x                                        0x543020

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB970
#define EQ_Character__Cur_HP_x                                     0x4D1C20
#define EQ_Character__Cur_Mana_x                                   0x4D9340
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE9B0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2460
#define EQ_Character__GetFocusRangeModifier_x                      0x4B25B0
#define EQ_Character__GetHPRegen_x                                 0x4DF0E0
#define EQ_Character__GetEnduranceRegen_x                          0x4DF6E0
#define EQ_Character__GetManaRegen_x                               0x4DFB20
#define EQ_Character__Max_Endurance_x                              0x658300
#define EQ_Character__Max_HP_x                                     0x4D1A50
#define EQ_Character__Max_Mana_x                                   0x658100
#define EQ_Character__doCombatAbility_x                            0x65A740
#define EQ_Character__UseSkill_x                                   0x4E1910
#define EQ_Character__GetConLevel_x                                0x651200
#define EQ_Character__IsExpansionFlag_x                            0x5B4840
#define EQ_Character__TotalEffect_x                                0x4C4D20
#define EQ_Character__GetPCSpellAffect_x                           0x4BF700
#define EQ_Character__SpellDuration_x                              0x4BF230
#define EQ_Character__GetAdjustedSkill_x                           0x4D49A0
#define EQ_Character__GetBaseSkill_x                               0x4D5940
#define EQ_Character__CanUseItem_x                                 0x4D9650

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8D81C0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x66E860

//PcClient
#define PcClient__PcClient_x                                       0x64E950

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B95B0
#define CCharacterListWnd__EnterWorld_x                            0x4B8FF0
#define CCharacterListWnd__Quit_x                                  0x4B8D40
#define CCharacterListWnd__UpdateList_x                            0x4B9180

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x633060
#define EQ_Item__CreateItemTagString_x                             0x8B23C0
#define EQ_Item__IsStackable_x                                     0x8B6FF0
#define EQ_Item__GetImageNum_x                                     0x8B3E40
#define EQ_Item__CreateItemClient_x                                0x6322A0
#define EQ_Item__GetItemValue_x                                    0x8B5210
#define EQ_Item__ValueSellMerchant_x                               0x8B8970
#define EQ_Item__IsKeyRingItem_x                                   0x8B68F0
#define EQ_Item__CanGoInBag_x                                      0x633180
#define EQ_Item__IsEmpty_x                                         0x8B6450
#define EQ_Item__GetMaxItemCount_x                                 0x8B5630
#define EQ_Item__GetHeldItem_x                                     0x8B3D10
#define EQ_Item__GetAugmentFitBySlot_x                             0x8B1C10

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x561CC0
#define EQ_LoadingS__Array_x                                       0xC38C60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x658C40
#define EQ_PC__GetAlternateAbilityId_x                             0x8C1D90
#define EQ_PC__GetCombatAbility_x                                  0x8C2400
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C2470
#define EQ_PC__GetItemRecastTimer_x                                0x65ACC0
#define EQ_PC__HasLoreItem_x                                       0x651A10
#define EQ_PC__AlertInventoryChanged_x                             0x650B40
#define EQ_PC__GetPcZoneClient_x                                   0x67D2C0
#define EQ_PC__RemoveMyAffect_x                                    0x65DEF0
#define EQ_PC__GetKeyRingItems_x                                   0x8C2D00
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C2A90
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C3000

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BAD70
#define EQItemList__add_object_x                                   0x5E8680
#define EQItemList__add_item_x                                     0x5BB2D0
#define EQItemList__delete_item_x                                  0x5BB320
#define EQItemList__FreeItemList_x                                 0x5BB220

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53FB30

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x6700E0
#define EQPlayer__dEQPlayer_x                                      0x6633E0
#define EQPlayer__DoAttack_x                                       0x677F50
#define EQPlayer__EQPlayer_x                                       0x663AA0
#define EQPlayer__SetNameSpriteState_x                             0x667DC0
#define EQPlayer__SetNameSpriteTint_x                              0x668C90
#define PlayerBase__HasProperty_j_x                                0x9A9980
#define EQPlayer__IsTargetable_x                                   0x9A9E20
#define EQPlayer__CanSee_x                                         0x9A9C80
#define EQPlayer__CanSee1_x                                        0x9A9D50
#define PlayerBase__GetVisibilityLineSegment_x                     0x9A9A40

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67AD50
#define PlayerZoneClient__GetLevel_x                               0x67D300
#define PlayerZoneClient__IsValidTeleport_x                        0x5E97F0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55AA00

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x672E10
#define EQPlayerManager__GetSpawnByName_x                          0x672EC0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x672F50

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x636820
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6368A0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6368E0
#define KeypressHandler__ClearCommandStateArray_x                  0x637CF0
#define KeypressHandler__HandleKeyDown_x                           0x637D10
#define KeypressHandler__HandleKeyUp_x                             0x637DB0
#define KeypressHandler__SaveKeymapping_x                          0x638200

// MapViewMap 
#define MapViewMap__Clear_x                                        0x78DDE0
#define MapViewMap__SaveEx_x                                       0x7911A0
#define MapViewMap__SetZoom_x                                      0x795860

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D6220

// StringTable 
#define StringTable__getString_x                                   0x8D0FE0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x65DB60
#define PcZoneClient__RemovePetEffect_x                            0x65E190
#define PcZoneClient__HasAlternateAbility_x                        0x657F30
#define PcZoneClient__GetCurrentMod_x                              0x4E49D0
#define PcZoneClient__GetModCap_x                                  0x4E48D0
#define PcZoneClient__CanEquipItem_x                               0x6585E0
#define PcZoneClient__GetItemByID_x                                0x65B130
#define PcZoneClient__GetItemByItemClass_x                         0x65B280
#define PcZoneClient__RemoveBuffEffect_x                           0x65E1B0
#define PcZoneClient__BandolierSwap_x                              0x659200
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65AC60

//Doors
#define EQSwitch__UseSwitch_x                                      0x5EE360

//IconCache
#define IconCache__GetIcon_x                                       0x72F2B0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x726D90
#define CContainerMgr__CloseContainer_x                            0x727060
#define CContainerMgr__OpenExperimentContainer_x                   0x727AE0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E62D0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62B230

//CLootWnd
#define CLootWnd__LootAll_x                                        0x784220
#define CLootWnd__RequestLootSlot_x                                0x783450

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x588240
#define EQ_Spell__SpellAffects_x                                   0x5886B0
#define EQ_Spell__SpellAffectBase_x                                0x588470
#define EQ_Spell__IsStackable_x                                    0x4C9660
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9480
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6930
#define EQ_Spell__IsSPAStacking_x                                  0x589500
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x588A10
#define EQ_Spell__IsNoRemove_x                                     0x4C9640
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x589510
#define __IsResEffectSpell_x                                       0x4C87A0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACE80

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8E0820

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82D350
#define CTargetWnd__WndNotification_x                              0x82CB90
#define CTargetWnd__RefreshTargetBuffs_x                           0x82CE60
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82BD10

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x831990
#define CTaskWnd__ConfirmAbandonTask_x                             0x8345D0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53D540
#define CTaskManager__HandleMessage_x                              0x53B9D0
#define CTaskManager__GetTaskStatus_x                              0x53D5F0
#define CTaskManager__GetElementDescription_x                      0x53D670

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x5833C0
#define EqSoundManager__PlayScriptMp3_x                            0x583680
#define EqSoundManager__SoundAssistPlay_x                          0x695800
#define EqSoundManager__WaveInstancePlay_x                         0x694D70

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52EC90

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x965790

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x569760
#define CAltAbilityData__GetMercMaxRank_x                          0x5696F0
#define CAltAbilityData__GetMaxRank_x                              0x55EB90

//CTargetRing
#define CTargetRing__Cast_x                                        0x629360

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9460
#define CharacterBase__CreateItemGlobalIndex_x                     0x515DF0
#define CharacterBase__CreateItemIndex_x                           0x631430
#define CharacterBase__GetItemPossession_x                         0x501A40
#define CharacterBase__GetItemByGlobalIndex_x                      0x8E8E80
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8E8EE0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x70DE30
#define CCastSpellWnd__IsBardSongPlaying_x                         0x70E660
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x70E710

//messages
#define msg_spell_worn_off_x                                       0x5ACEB0
#define msg_new_text_x                                             0x5A1840
#define __msgTokenTextParam_x                                      0x5AF150
#define msgTokenText_x                                             0x5AF3A0

//SpellManager
#define SpellManager__vftable_x                                    0xAFC170
#define SpellManager__SpellManager_x                               0x698B30
#define Spellmanager__LoadTextSpells_x                             0x699420
#define SpellManager__GetSpellByGroupAndRank_x                     0x698D00

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9AD990

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x516440
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B2E10
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64A160
#define ItemGlobalIndex__IsValidIndex_x                            0x5164A0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8E11C0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8E1440

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77CA70

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72B4B0
#define CCursorAttachment__AttachToCursor1_x                       0x72B4F0
#define CCursorAttachment__Deactivate_x                            0x72C4E0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x958470
#define CSidlManagerBase__CreatePageWnd_x                          0x957C60
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x953EE0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x953E70

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x975510
#define CEQSuiteTextureLoader__GetTexture_x                        0x9751D0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x513490
#define CFindItemWnd__WndNotification_x                            0x513F70
#define CFindItemWnd__Update_x                                     0x514AE0
#define CFindItemWnd__PickupSelectedItem_x                         0x512CD0

//IString
#define IString__Append_x                                          0x503250

//Camera
#define CDisplay__cameraType_x                                     0xE12258
#define EverQuest__Cameras_x                                       0xECD534

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51BBA0
#define LootFiltersManager__GetItemFilterData_x                    0x51B4B0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51B4E0
#define LootFiltersManager__SetItemLootFilter_x                    0x51B700

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D40C0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B35B0
#define CResolutionHandler__GetWindowedStyle_x                     0x6901D0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x723A40

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F66D0
#define CDistillerInfo__Instance_x                                 0x8F6670

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x742AB0
#define CGroupWnd__UpdateDisplay_x                                 0x741E00

//ItemBase
#define ItemBase__IsLore_x                                         0x8B69A0
#define ItemBase__IsLoreEquipped_x                                 0x8B6A20

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5E85E0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5E8720
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5E8780

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6859D0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x689370

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x5097D0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F5F60
#define FactionManagerClient__HandleFactionMessage_x               0x4F65D0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F6B90
#define FactionManagerClient__GetMaxFaction_x                      0x4F6BAF
#define FactionManagerClient__GetMinFaction_x                      0x4F6B60

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x501A10

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x93CC40

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BD10

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x501C70

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x568C20

//CTargetManager
#define CTargetManager__Get_x                                      0x69C370

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6859D0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8AE0

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BB1C0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF6ABC8

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6D7810

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
