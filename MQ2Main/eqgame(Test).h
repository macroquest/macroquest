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
#define __ExpectedVersionDate                                     "Jan 10 2020"
#define __ExpectedVersionTime                                     "19:40:57"
#define __ActualVersionDate_x                                      0xB0B550
#define __ActualVersionTime_x                                      0xB0B544
#define __ActualVersionBuild_x                                     0xAF7254

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x630F10
#define __MemChecker1_x                                            0x9039A0
#define __MemChecker2_x                                            0x6BF300
#define __MemChecker3_x                                            0x6BF250
#define __MemChecker4_x                                            0x859EE0
#define __EncryptPad0_x                                            0xC423E8
#define __EncryptPad1_x                                            0xCA0650
#define __EncryptPad2_x                                            0xC52C80
#define __EncryptPad3_x                                            0xC52880
#define __EncryptPad4_x                                            0xC90C00
#define __EncryptPad5_x                                            0xF6CE10
#define __AC1_x                                                    0x816CD6
#define __AC2_x                                                    0x5EAD9F
#define __AC3_x                                                    0x5F249F
#define __AC4_x                                                    0x5F6470
#define __AC5_x                                                    0x5FC77F
#define __AC6_x                                                    0x600C76
#define __AC7_x                                                    0x5EA810
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x19739C

// Direct Input
#define DI8__Main_x                                                0xF6CE38
#define DI8__Keyboard_x                                            0xF6CE3C
#define DI8__Mouse_x                                               0xF6CE1C
#define DI8__Mouse_Copy_x                                          0xEC556C
#define DI8__Mouse_Check_x                                         0xF6A964
#define __AutoSkillArray_x                                         0xEC6484
#define __Attack_x                                                 0xF642AB
#define __Autofire_x                                               0xF642AC
#define __BindList_x                                               0xC30E20
#define g_eqCommandStates_x                                        0xC31BA0
#define __Clicks_x                                                 0xEC5624
#define __CommandList_x                                            0xC32760
#define __CurrentMapLabel_x                                        0xF7CD74
#define __CurrentSocial_x                                          0xC1A7C0
#define __DoAbilityList_x                                          0xEFBDCC
#define __do_loot_x                                                0x5B67E0
#define __DrawHandler_x                                            0x15FC0F0
#define __GroupCount_x                                             0xEB5822
#define __Guilds_x                                                 0xEBBD78
#define __gWorld_x                                                 0xEB5F68
#define __HWnd_x                                                   0xF6CE20
#define __heqmain_x                                                0xF6CDF8
#define __InChatMode_x                                             0xEC5554
#define __LastTell_x                                               0xEC74C8
#define __LMouseHeldTime_x                                         0xEC5690
#define __Mouse_x                                                  0xF6CE24
#define __MouseLook_x                                              0xEC55EA
#define __MouseEventTime_x                                         0xF64D8C
#define __gpbCommandEvent_x                                        0xEB5A24
#define __NetStatusToggle_x                                        0xEC55ED
#define __PCNames_x                                                0xEC6A74
#define __RangeAttackReady_x                                       0xEC6768
#define __RMouseHeldTime_x                                         0xEC568C
#define __RunWalkState_x                                           0xEC5558
#define __ScreenMode_x                                             0xE0323C
#define __ScreenX_x                                                0xEC550C
#define __ScreenY_x                                                0xEC5508
#define __ScreenXMax_x                                             0xEC5510
#define __ScreenYMax_x                                             0xEC5514
#define __ServerHost_x                                             0xEB5C53
#define __ServerName_x                                             0xEFBD8C
#define __ShiftKeyDown_x                                           0xEC5BE4
#define __ShowNames_x                                              0xEC6924
#define __Socials_x                                                0xEFBE8C
#define __SubscriptionType_x                                       0xFC1280
#define __TargetAggroHolder_x                                      0xF7F728
#define __ZoneType_x                                               0xEC59E8
#define __GroupAggro_x                                             0xF7F768
#define __LoginName_x                                              0xF6A5F4
#define __Inviter_x                                                0xF64228
#define __AttackOnAssist_x                                         0xEC68E0
#define __UseTellWindows_x                                         0xEC6C10
#define __gfMaxZoomCameraDistance_x                                0xB00EB0
#define __gfMaxCameraDistance_x                                    0xB2D264
#define __pulAutoRun_x                                             0xEC5608
#define __pulForward_x                                             0xEC6C48
#define __pulBackward_x                                            0xEC6C4C
#define __pulTurnRight_x                                           0xEC6C50
#define __pulTurnLeft_x                                            0xEC6C54
#define __pulStrafeLeft_x                                          0xEC6C58
#define __pulStrafeRight_x                                         0xEC6C5C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB8110
#define instEQZoneInfo_x                                           0xEC57E0
#define pinstActiveBanker_x                                        0xEB5A38
#define pinstActiveCorpse_x                                        0xEB5A30
#define pinstActiveGMaster_x                                       0xEB5A34
#define pinstActiveMerchant_x                                      0xEB5A2C
#define pinstAltAdvManager_x                                       0xE04340
#define pinstBandageTarget_x                                       0xEB5A48
#define pinstCamActor_x                                            0xE03230
#define pinstCDBStr_x                                              0xE0305C
#define pinstCDisplay_x                                            0xEB7F78
#define pinstCEverQuest_x                                          0xF69EB8
#define pinstEverQuestInfo_x                                       0xEC5500
#define pinstCharData_x                                            0xEB5804
#define pinstCharSpawn_x                                           0xEB5A80
#define pinstControlledMissile_x                                   0xEB5F64
#define pinstControlledPlayer_x                                    0xEB5A80
#define pinstCResolutionHandler_x                                  0x15FC320
#define pinstCSidlManager_x                                        0x15FB2B8
#define pinstCXWndManager_x                                        0x15FB2B4
#define instDynamicZone_x                                          0xEBBC50
#define pinstDZMember_x                                            0xEBBD60
#define pinstDZTimerInfo_x                                         0xEBBD64
#define pinstEqLogin_x                                             0xF69F40
#define instEQMisc_x                                               0xE02FA0
#define pinstEQSoundManager_x                                      0xE05310
#define pinstEQSpellStrings_x                                      0xCC59B8
#define instExpeditionLeader_x                                     0xEBBC9A
#define instExpeditionName_x                                       0xEBBCDA
#define pinstGroup_x                                               0xEB581E
#define pinstImeManager_x                                          0x15FB2B0
#define pinstLocalPlayer_x                                         0xEB5A28
#define pinstMercenaryData_x                                       0xF66880
#define pinstMercenaryStats_x                                      0xF7F874
#define pinstModelPlayer_x                                         0xEB5A40
#define pinstPCData_x                                              0xEB5804
#define pinstSkillMgr_x                                            0xF689E8
#define pinstSpawnManager_x                                        0xF67490
#define pinstSpellManager_x                                        0xF68C28
#define pinstSpellSets_x                                           0xF5CED4
#define pinstStringTable_x                                         0xEB5808
#define pinstSwitchManager_x                                       0xEB56B0
#define pinstTarget_x                                              0xEB5A7C
#define pinstTargetObject_x                                        0xEB5B08
#define pinstTargetSwitch_x                                        0xEB7F70
#define pinstTaskMember_x                                          0xE02E30
#define pinstTrackTarget_x                                         0xEB5A84
#define pinstTradeTarget_x                                         0xEB5A3C
#define instTributeActive_x                                        0xE02FC1
#define pinstViewActor_x                                           0xE0322C
#define pinstWorldData_x                                           0xEB5A14
#define pinstZoneAddr_x                                            0xEC5A80
#define pinstPlayerPath_x                                          0xF67528
#define pinstTargetIndicator_x                                     0xF68E90
#define EQObject_Top_x                                             0xEB5A20
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE03114
#define pinstCAchievementsWnd_x                                    0xE03170
#define pinstCActionsWnd_x                                         0xE0313C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE03268
#define pinstCAdvancedLootWnd_x                                    0xE03204
#define pinstCAdventureLeaderboardWnd_x                            0xF76548
#define pinstCAdventureRequestWnd_x                                0xF765F8
#define pinstCAdventureStatsWnd_x                                  0xF766A8
#define pinstCAggroMeterWnd_x                                      0xE03270
#define pinstCAlarmWnd_x                                           0xE031CC
#define pinstCAlertHistoryWnd_x                                    0xE03294
#define pinstCAlertStackWnd_x                                      0xE031DC
#define pinstCAlertWnd_x                                           0xE031EC
#define pinstCAltStorageWnd_x                                      0xF76A08
#define pinstCAudioTriggersWindow_x                                0xCB7CE8
#define pinstCAuraWnd_x                                            0xE0320C
#define pinstCAvaZoneWnd_x                                         0xE03220
#define pinstCBandolierWnd_x                                       0xE03264
#define pinstCBankWnd_x                                            0xE032B4
#define pinstCBarterMerchantWnd_x                                  0xF77C48
#define pinstCBarterSearchWnd_x                                    0xF77CF8
#define pinstCBarterWnd_x                                          0xF77DA8
#define pinstCBazaarConfirmationWnd_x                              0xE03198
#define pinstCBazaarSearchWnd_x                                    0xE03118
#define pinstCBazaarWnd_x                                          0xE031B4
#define pinstCBlockedBuffWnd_x                                     0xE03218
#define pinstCBlockedPetBuffWnd_x                                  0xE03258
#define pinstCBodyTintWnd_x                                        0xE0314C
#define pinstCBookWnd_x                                            0xE032A4
#define pinstCBreathWnd_x                                          0xE03128
#define pinstCBuffWindowNORMAL_x                                   0xE031FC
#define pinstCBuffWindowSHORT_x                                    0xE03200
#define pinstCBugReportWnd_x                                       0xE032AC
#define pinstCButtonWnd_x                                          0x15FB520
#define pinstCCastingWnd_x                                         0xE03290
#define pinstCCastSpellWnd_x                                       0xE03120
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE0316C
#define pinstCChatWindowManager_x                                  0xF78868
#define pinstCClaimWnd_x                                           0xF789C0
#define pinstCColorPickerWnd_x                                     0xE0378C
#define pinstCCombatAbilityWnd_x                                   0xE031C0
#define pinstCCombatSkillsSelectWnd_x                              0xE0317C
#define pinstCCompassWnd_x                                         0xE03140
#define pinstCConfirmationDialog_x                                 0xF7D8C0
#define pinstCContainerMgr_x                                       0xE03164
#define pinstCContextMenuManager_x                                 0x15FB270
#define pinstCCursorAttachment_x                                   0xE03278
#define pinstCDynamicZoneWnd_x                                     0xF78F88
#define pinstCEditLabelWnd_x                                       0xE031F0
#define pinstCEQMainWnd_x                                          0xF791D0
#define pinstCEventCalendarWnd_x                                   0xE03778
#define pinstCExtendedTargetWnd_x                                  0xE03248
#define pinstCFacePick_x                                           0xE03194
#define pinstCFactionWnd_x                                         0xE031A4
#define pinstCFellowshipWnd_x                                      0xF793D0
#define pinstCFileSelectionWnd_x                                   0xE03784
#define pinstCFindItemWnd_x                                        0xE0318C
#define pinstCFindLocationWnd_x                                    0xF79528
#define pinstCFriendsWnd_x                                         0xE03190
#define pinstCGemsGameWnd_x                                        0xE031A0
#define pinstCGiveWnd_x                                            0xE031D4
#define pinstCGroupSearchFiltersWnd_x                              0xE03298
#define pinstCGroupSearchWnd_x                                     0xF79920
#define pinstCGroupWnd_x                                           0xF799D0
#define pinstCGuildBankWnd_x                                       0xEC68C4
#define pinstCGuildCreationWnd_x                                   0xF79B30
#define pinstCGuildMgmtWnd_x                                       0xF79BE0
#define pinstCharacterCreation_x                                   0xE03184
#define pinstCHelpWnd_x                                            0xE031D0
#define pinstCHeritageSelectionWnd_x                               0xE031A8
#define pinstCHotButtonWnd_x                                       0xF7BD38
#define pinstCHotButtonWnd1_x                                      0xF7BD38
#define pinstCHotButtonWnd2_x                                      0xF7BD3C
#define pinstCHotButtonWnd3_x                                      0xF7BD40
#define pinstCHotButtonWnd4_x                                      0xF7BD44
#define pinstCIconSelectionWnd_x                                   0xE03274
#define pinstCInspectWnd_x                                         0xE0325C
#define pinstCInventoryWnd_x                                       0xE03210
#define pinstCInvSlotMgr_x                                         0xE03124
#define pinstCItemDisplayManager_x                                 0xF7C2C8
#define pinstCItemExpTransferWnd_x                                 0xF7C3F8
#define pinstCItemOverflowWnd_x                                    0xE0311C
#define pinstCJournalCatWnd_x                                      0xE030FC
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE032EC
#define pinstCKeyRingWnd_x                                         0xE03284
#define pinstCLargeDialogWnd_x                                     0xF7E540
#define pinstCLayoutCopyWnd_x                                      0xF7C748
#define pinstCLFGuildWnd_x                                         0xF7C7F8
#define pinstCLoadskinWnd_x                                        0xE031B0
#define pinstCLootFiltersCopyWnd_x                                 0xCD4338
#define pinstCLootFiltersWnd_x                                     0xE031E0
#define pinstCLootSettingsWnd_x                                    0xE031F8
#define pinstCLootWnd_x                                            0xE03100
#define pinstCMailAddressBookWnd_x                                 0xE0312C
#define pinstCMailCompositionWnd_x                                 0xE03110
#define pinstCMailIgnoreListWnd_x                                  0xE03130
#define pinstCMailWnd_x                                            0xE03990
#define pinstCManageLootWnd_x                                      0xE047F0
#define pinstCMapToolbarWnd_x                                      0xE031D8
#define pinstCMapViewWnd_x                                         0xE031AC
#define pinstCMarketplaceWnd_x                                     0xE031E4
#define pinstCMerchantWnd_x                                        0xE03108
#define pinstCMIZoneSelectWnd_x                                    0xF7D030
#define pinstCMusicPlayerWnd_x                                     0xE032B8
#define pinstCNameChangeMercWnd_x                                  0xE03188
#define pinstCNameChangePetWnd_x                                   0xE03174
#define pinstCNameChangeWnd_x                                      0xE0319C
#define pinstCNoteWnd_x                                            0xE031B8
#define pinstCObjectPreviewWnd_x                                   0xE031F4
#define pinstCOptionsWnd_x                                         0xE031C4
#define pinstCPetInfoWnd_x                                         0xE032F8
#define pinstCPetitionQWnd_x                                       0xE03158
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE03150
#define pinstCPlayerWnd_x                                          0xE0377C
#define pinstCPopupWndManager_x                                    0xF7D8C0
#define pinstCProgressionSelectionWnd_x                            0xF7D970
#define pinstCPurchaseGroupWnd_x                                   0xE03250
#define pinstCPurchaseWnd_x                                        0xE03214
#define pinstCPvPLeaderboardWnd_x                                  0xF7DA20
#define pinstCPvPStatsWnd_x                                        0xF7DAD0
#define pinstCQuantityWnd_x                                        0xE032F0
#define pinstCRaceChangeWnd_x                                      0xE031C8
#define pinstCRaidOptionsWnd_x                                     0xE032A0
#define pinstCRaidWnd_x                                            0xE03104
#define pinstCRealEstateItemsWnd_x                                 0xE03168
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE0310C
#define pinstCRealEstateManageWnd_x                                0xE03260
#define pinstCRealEstateNeighborhoodWnd_x                          0xE03288
#define pinstCRealEstatePlotSearchWnd_x                            0xE032B0
#define pinstCRealEstatePurchaseWnd_x                              0xE032E8
#define pinstCRespawnWnd_x                                         0xE03228
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE03178
#define pinstCSendMoneyWnd_x                                       0xE031E8
#define pinstCServerListWnd_x                                      0xE0330C
#define pinstCSkillsSelectWnd_x                                    0xE03160
#define pinstCSkillsWnd_x                                          0xE03144
#define pinstCSocialEditWnd_x                                      0xE0327C
#define pinstCSocialWnd_x                                          0xE03180
#define pinstCSpellBookWnd_x                                       0xE031BC
#define pinstCStoryWnd_x                                           0xE03134
#define pinstCTargetOfTargetWnd_x                                  0xF7F8F8
#define pinstCTargetWnd_x                                          0xE03224
#define pinstCTaskOverlayWnd_x                                     0xE0324C
#define pinstCTaskSelectWnd_x                                      0xF7FA50
#define pinstCTaskManager_x                                        0xCD4C78
#define pinstCTaskTemplateSelectWnd_x                              0xF7FB00
#define pinstCTaskWnd_x                                            0xF7FBB0
#define pinstCTextEntryWnd_x                                       0xE0329C
#define pinstCTimeLeftWnd_x                                        0xE03138
#define pinstCTipWndCONTEXT_x                                      0xF7FDB4
#define pinstCTipWndOFDAY_x                                        0xF7FDB0
#define pinstCTitleWnd_x                                           0xF7FE60
#define pinstCTrackingWnd_x                                        0xE0321C
#define pinstCTradeskillWnd_x                                      0xF7FFC8
#define pinstCTradeWnd_x                                           0xE03154
#define pinstCTrainWnd_x                                           0xE030F8
#define pinstCTributeBenefitWnd_x                                  0xF801C8
#define pinstCTributeMasterWnd_x                                   0xF80278
#define pinstCTributeTrophyWnd_x                                   0xF80328
#define pinstCVideoModesWnd_x                                      0xE03780
#define pinstCVoiceMacroWnd_x                                      0xF695F8
#define pinstCVoteResultsWnd_x                                     0xE0315C
#define pinstCVoteWnd_x                                            0xE03148
#define pinstCWebManager_x                                         0xF69C74
#define pinstCZoneGuideWnd_x                                       0xE03254
#define pinstCZonePathWnd_x                                        0xE0326C

#define pinstEQSuiteTextureLoader_x                                0xCA2128
#define pinstItemIconCache_x                                       0xF79188
#define pinstLootFiltersManager_x                                  0xCD43E8
#define pinstRewardSelectionWnd_x                                  0xF7E218

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5B1C40
#define __CastRay2_x                                               0x5B1C90
#define __ConvertItemTags_x                                        0x5CD7F0
#define __CleanItemTags_x                                          0x47D0C0
#define __DoesFileExist_x                                          0x9069D0
#define __EQGetTime_x                                              0x903470
#define __ExecuteCmd_x                                             0x5AA490
#define __FixHeading_x                                             0x99E030
#define __GameLoop_x                                               0x6BE4F0
#define __get_bearing_x                                            0x5B17B0
#define __get_melee_range_x                                        0x5B1E80
#define __GetAnimationCache_x                                      0x723890
#define __GetGaugeValueFromEQ_x                                    0x815180
#define __GetLabelFromEQ_x                                         0x816C60
#define __GetXTargetType_x                                         0x99FA80
#define __HandleMouseWheel_x                                       0x6BF3B0
#define __HeadingDiff_x                                            0x99E0A0
#define __HelpPath_x                                               0xF6497C
#define __LoadFrontEnd_x                                           0x6BB810
#define __NewUIINI_x                                               0x814E50
#define __ProcessGameEvents_x                                      0x612440
#define __ProcessMouseEvent_x                                      0x611C00
#define __SaveColors_x                                             0x5536F0
#define __STMLToText_x                                             0x9413C0
#define __ToggleKeyRingItem_x                                      0x516340
#define CMemoryMappedFile__SetFile_x                               0xA8D240
#define CrashDetected_x                                            0x6BD2B0
#define DrawNetStatus_x                                            0x63E280
#define Expansion_HoT_x                                            0xEC68CC
#define Teleport_Table_Size_x                                      0xEB5B10
#define Teleport_Table_x                                           0xEB5F70
#define Util__FastTime_x                                           0x903040

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
#define AltAdvManager__GetCalculatedTimer_x                        0x55B230
#define AltAdvManager__IsAbilityReady_x                            0x55A160
#define AltAdvManager__GetAAById_x                                 0x55A360
#define AltAdvManager__CanTrainAbility_x                           0x55A3D0
#define AltAdvManager__CanSeeAbility_x                             0x55A730

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9CD0
#define CharacterZoneClient__HasSkill_x                            0x4D4BC0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D62E0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE640
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAC70
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8C70
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8D50
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D8E30
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2E50
#define CharacterZoneClient__BardCastBard_x                        0x4C59B0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAD40
#define CharacterZoneClient__GetEffect_x                           0x4BABB0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3EA0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3F70
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3FC0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4110
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C42E0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2AF0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7240
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6CC0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E4FF0
#define CBankWnd__WndNotification_x                                0x6E4DD0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F2830

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x620D20
#define CButtonWnd__CButtonWnd_x                                   0x93D790

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7129C0
#define CChatManager__InitContextMenu_x                            0x70BB10
#define CChatManager__FreeChatWindow_x                             0x711500
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8220
#define CChatManager__SetLockedActiveChatWindow_x                  0x712640
#define CChatManager__CreateChatWindow_x                           0x711B40

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8330

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x951E40
#define CContextMenu__dCContextMenu_x                              0x952080
#define CContextMenu__AddMenuItem_x                                0x952090
#define CContextMenu__RemoveMenuItem_x                             0x9523A0
#define CContextMenu__RemoveAllMenuItems_x                         0x9523C0
#define CContextMenu__CheckMenuItem_x                              0x952440
#define CContextMenu__SetMenuItem_x                                0x9522C0
#define CContextMenu__AddSeparator_x                               0x952220

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9529E0
#define CContextMenuManager__RemoveMenu_x                          0x952A50
#define CContextMenuManager__PopupMenu_x                           0x952B10
#define CContextMenuManager__Flush_x                               0x952980
#define CContextMenuManager__GetMenu_x                             0x49B410
#define CContextMenuManager__CreateDefaultMenu_x                   0x71E060

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DE9D0
#define CChatService__GetFriendName_x                              0x8DE9E0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x713230
#define CChatWindow__Clear_x                                       0x714500
#define CChatWindow__WndNotification_x                             0x714C90
#define CChatWindow__AddHistory_x                                  0x713DC0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94F290
#define CComboWnd__Draw_x                                          0x94E770
#define CComboWnd__GetCurChoice_x                                  0x94F0D0
#define CComboWnd__GetListRect_x                                   0x94EC30
#define CComboWnd__GetTextRect_x                                   0x94F300
#define CComboWnd__InsertChoice_x                                  0x94EDC0
#define CComboWnd__SetColors_x                                     0x94ED90
#define CComboWnd__SetChoice_x                                     0x94F0A0
#define CComboWnd__GetItemCount_x                                  0x94F0E0
#define CComboWnd__GetCurChoiceText_x                              0x94F120
#define CComboWnd__GetChoiceText_x                                 0x94F0F0
#define CComboWnd__InsertChoiceAtIndex_x                           0x94EE60

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71BA40
#define CContainerWnd__vftable_x                                   0xB1474C
#define CContainerWnd__SetContainer_x                              0x71CFA0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54E120
#define CDisplay__PreZoneMainUI_x                                  0x54E130
#define CDisplay__CleanGameUI_x                                    0x5534B0
#define CDisplay__GetClickedActor_x                                0x546440
#define CDisplay__GetUserDefinedColor_x                            0x53EAA0
#define CDisplay__GetWorldFilePath_x                               0x547EB0
#define CDisplay__is3dON_x                                         0x5430A0
#define CDisplay__ReloadUI_x                                       0x54D5B0
#define CDisplay__WriteTextHD2_x                                   0x542E90
#define CDisplay__TrueDistance_x                                   0x549B70
#define CDisplay__SetViewActor_x                                   0x545D60
#define CDisplay__GetFloorHeight_x                                 0x543160
#define CDisplay__SetRenderWindow_x                                0x541AC0
#define CDisplay__ToggleScreenshotMode_x                           0x545830

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x971BC0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9553B0
#define CEditWnd__EnsureCaretVisible_x                             0x957580
#define CEditWnd__GetCaretPt_x                                     0x956530
#define CEditWnd__GetCharIndexPt_x                                 0x9562E0
#define CEditWnd__GetDisplayString_x                               0x956180
#define CEditWnd__GetHorzOffset_x                                  0x9549E0
#define CEditWnd__GetLineForPrintableChar_x                        0x957480
#define CEditWnd__GetSelStartPt_x                                  0x956590
#define CEditWnd__GetSTMLSafeText_x                                0x955FA0
#define CEditWnd__PointFromPrintableChar_x                         0x9570B0
#define CEditWnd__SelectableCharFromPoint_x                        0x957220
#define CEditWnd__SetEditable_x                                    0x956660
#define CEditWnd__SetWindowTextA_x                                 0x955D20
#define CEditWnd__ReplaceSelection_x                               0x956D20
#define CEditWnd__ReplaceSelection1_x                              0x956CA0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x600150
#define CEverQuest__ClickedPlayer_x                                0x5F2280
#define CEverQuest__CreateTargetIndicator_x                        0x60F6D0
#define CEverQuest__DeleteTargetIndicator_x                        0x60F760
#define CEverQuest__DoTellWindow_x                                 0x4E8410
#define CEverQuest__OutputTextToLog_x                              0x4E86E0
#define CEverQuest__DropHeldItemOnGround_x                         0x5E72C0
#define CEverQuest__dsp_chat_x                                     0x4E8A70
#define CEverQuest__trimName_x                                     0x60B9B0
#define CEverQuest__Emote_x                                        0x6009B0
#define CEverQuest__EnterZone_x                                    0x5FAA50
#define CEverQuest__GetBodyTypeDesc_x                              0x605270
#define CEverQuest__GetClassDesc_x                                 0x6058B0
#define CEverQuest__GetClassThreeLetterCode_x                      0x605EB0
#define CEverQuest__GetDeityDesc_x                                 0x60E010
#define CEverQuest__GetLangDesc_x                                  0x606070
#define CEverQuest__GetRaceDesc_x                                  0x605890
#define CEverQuest__InterpretCmd_x                                 0x60E5E0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EB4C0
#define CEverQuest__LMouseUp_x                                     0x5E9850
#define CEverQuest__RightClickedOnPlayer_x                         0x5EBDA0
#define CEverQuest__RMouseUp_x                                     0x5EA7D0
#define CEverQuest__SetGameState_x                                 0x5E7050
#define CEverQuest__UPCNotificationFlush_x                         0x60B8B0
#define CEverQuest__IssuePetCommand_x                              0x607470
#define CEverQuest__ReportSuccessfulHit_x                          0x601D00

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72D8F0
#define CGaugeWnd__CalcLinesFillRect_x                             0x72D950
#define CGaugeWnd__Draw_x                                          0x72CF80

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF590
#define CGuild__GetGuildName_x                                     0x4AE5B0
#define CGuild__GetGuildIndex_x                                    0x4AEA00

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x747AF0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x6210E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x754B50
#define CInvSlotMgr__MoveItem_x                                    0x753870
#define CInvSlotMgr__SelectSlot_x                                  0x754C20

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7520B0
#define CInvSlot__SliderComplete_x                                 0x74FE10
#define CInvSlot__GetItemBase_x                                    0x74F780
#define CInvSlot__UpdateItem_x                                     0x74F8F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7566B0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x755840
#define CInvSlotWnd__HandleLButtonUp_x                             0x756230

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x8104F0
#define CItemDisplayWnd__UpdateStrings_x                           0x764EB0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75EB20
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75F050
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7654C0
#define CItemDisplayWnd__AboutToShow_x                             0x764B00
#define CItemDisplayWnd__WndNotification_x                         0x7665B0
#define CItemDisplayWnd__RequestConvertItem_x                      0x766070
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x763B60
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x764920

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x848E70

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76AAF0

// CLabel 
#define CLabel__Draw_x                                             0x770540

// CListWnd
#define CListWnd__CListWnd_x                                       0x9279C0
#define CListWnd__dCListWnd_x                                      0x927CE0
#define CListWnd__AddColumn_x                                      0x92C130
#define CListWnd__AddColumn1_x                                     0x92C180
#define CListWnd__AddLine_x                                        0x92C510
#define CListWnd__AddString_x                                      0x92C310
#define CListWnd__CalculateFirstVisibleLine_x                      0x92BF00
#define CListWnd__CalculateVSBRange_x                              0x92BCF0
#define CListWnd__ClearSel_x                                       0x92CCF0
#define CListWnd__ClearAllSel_x                                    0x92CD50
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92D750
#define CListWnd__Compare_x                                        0x92B620
#define CListWnd__Draw_x                                           0x927E10
#define CListWnd__DrawColumnSeparators_x                           0x92A5F0
#define CListWnd__DrawHeader_x                                     0x92AA60
#define CListWnd__DrawItem_x                                       0x92AF60
#define CListWnd__DrawLine_x                                       0x92A760
#define CListWnd__DrawSeparator_x                                  0x92A690
#define CListWnd__EnableLine_x                                     0x929ED0
#define CListWnd__EnsureVisible_x                                  0x92D680
#define CListWnd__ExtendSel_x                                      0x92CC20
#define CListWnd__GetColumnTooltip_x                               0x929A10
#define CListWnd__GetColumnMinWidth_x                              0x929A80
#define CListWnd__GetColumnWidth_x                                 0x929980
#define CListWnd__GetCurSel_x                                      0x929310
#define CListWnd__GetItemAtPoint_x                                 0x92A140
#define CListWnd__GetItemAtPoint1_x                                0x92A1B0
#define CListWnd__GetItemData_x                                    0x929390
#define CListWnd__GetItemHeight_x                                  0x929750
#define CListWnd__GetItemIcon_x                                    0x929520
#define CListWnd__GetItemRect_x                                    0x929FC0
#define CListWnd__GetItemText_x                                    0x9293D0
#define CListWnd__GetSelList_x                                     0x92CDA0
#define CListWnd__GetSeparatorRect_x                               0x92A3F0
#define CListWnd__InsertLine_x                                     0x92C900
#define CListWnd__RemoveLine_x                                     0x92CA50
#define CListWnd__SetColors_x                                      0x92BCC0
#define CListWnd__SetColumnJustification_x                         0x92B9F0
#define CListWnd__SetColumnLabel_x                                 0x92C2B0
#define CListWnd__SetColumnWidth_x                                 0x92B910
#define CListWnd__SetCurSel_x                                      0x92CB60
#define CListWnd__SetItemColor_x                                   0x92D340
#define CListWnd__SetItemData_x                                    0x92D300
#define CListWnd__SetItemText_x                                    0x92CF10
#define CListWnd__ShiftColumnSeparator_x                           0x92BAB0
#define CListWnd__Sort_x                                           0x92B7A0
#define CListWnd__ToggleSel_x                                      0x92CB90
#define CListWnd__SetColumnsSizable_x                              0x92BB60
#define CListWnd__SetItemWnd_x                                     0x92D1C0
#define CListWnd__GetItemWnd_x                                     0x929570
#define CListWnd__SetItemIcon_x                                    0x92CF90
#define CListWnd__CalculateCustomWindowPositions_x                 0x92BFF0
#define CListWnd__SetVScrollPos_x                                  0x92B8F0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x785C00
#define CMapViewWnd__GetWorldCoordinates_x                         0x784310
#define CMapViewWnd__HandleLButtonDown_x                           0x781350

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A5D90
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A6670
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A6BA0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A9B20
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A4900
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AF6D0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A59A0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AC590
#define CPacketScrambler__hton_x                                   0x8AC580

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9469E0
#define CSidlManager__FindScreenPieceTemplate_x                    0x946DF0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x946BE0
#define CSidlManager__CreateLabel_x                                0x807720
#define CSidlManager__CreateXWndFromTemplate_x                     0x949D50
#define CSidlManager__CreateXWndFromTemplate1_x                    0x949F30
#define CSidlManager__CreateXWnd_x                                 0x807650
#define CSidlManager__CreateHotButtonWnd_x                         0x807C20

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x9434E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x9433F0
#define CSidlScreenWnd__ConvertToRes_x                             0x968BD0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x942E80
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x942B70
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x942C40
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x942D10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x943980
#define CSidlScreenWnd__EnableIniStorage_x                         0x943E50
#define CSidlScreenWnd__GetSidlPiece_x                             0x943B70
#define CSidlScreenWnd__Init1_x                                    0x942770
#define CSidlScreenWnd__LoadIniInfo_x                              0x943EA0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x9449C0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x941B70
#define CSidlScreenWnd__StoreIniInfo_x                             0x944540
#define CSidlScreenWnd__StoreIniVis_x                              0x9448A0
#define CSidlScreenWnd__WndNotification_x                          0x943890
#define CSidlScreenWnd__GetChildItem_x                             0x943DD0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9334F0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FB140

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6857A0
#define CSkillMgr__GetSkillCap_x                                   0x685980
#define CSkillMgr__GetNameToken_x                                  0x684F20
#define CSkillMgr__IsActivatedSkill_x                              0x685060
#define CSkillMgr__IsCombatSkill_x                                 0x684FA0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9537C0
#define CSliderWnd__SetValue_x                                     0x953630
#define CSliderWnd__SetNumTicks_x                                  0x953690

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80D870

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95BFB0
#define CStmlWnd__ParseSTML_x                                      0x95D2E0
#define CStmlWnd__CalculateHSBRange_x                              0x95D0B0
#define CStmlWnd__CalculateVSBRange_x                              0x95D030
#define CStmlWnd__CanBreakAtCharacter_x                            0x9613F0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x962080
#define CStmlWnd__ForceParseNow_x                                  0x95C590
#define CStmlWnd__GetNextTagPiece_x                                0x961350
#define CStmlWnd__GetSTMLText_x                                    0x505C00
#define CStmlWnd__GetVisibleText_x                                 0x95C5B0
#define CStmlWnd__InitializeWindowVariables_x                      0x961ED0
#define CStmlWnd__MakeStmlColorTag_x                               0x95B620
#define CStmlWnd__MakeWndNotificationTag_x                         0x95B690
#define CStmlWnd__SetSTMLText_x                                    0x95A6D0
#define CStmlWnd__StripFirstSTMLLines_x                            0x963170
#define CStmlWnd__UpdateHistoryString_x                            0x962290

// CTabWnd 
#define CTabWnd__Draw_x                                            0x959820
#define CTabWnd__DrawCurrentPage_x                                 0x959F50
#define CTabWnd__DrawTab_x                                         0x959C70
#define CTabWnd__GetCurrentPage_x                                  0x959020
#define CTabWnd__GetPageInnerRect_x                                0x959260
#define CTabWnd__GetTabInnerRect_x                                 0x9591A0
#define CTabWnd__GetTabRect_x                                      0x959050
#define CTabWnd__InsertPage_x                                      0x959470
#define CTabWnd__SetPage_x                                         0x9592E0
#define CTabWnd__SetPageRect_x                                     0x959760
#define CTabWnd__UpdatePage_x                                      0x959B30
#define CTabWnd__GetPageFromTabIndex_x                             0x959BB0
#define CTabWnd__GetCurrentTabIndex_x                              0x959010

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76AEC0
#define CPageWnd__SetTabText_x                                     0x958B70

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9060

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x930390
#define CTextureFont__GetTextExtent_x                              0x930550

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B8670
#define CHtmlComponentWnd__ValidateUri_x                           0x7494E0
#define CHtmlWnd__SetClientCallbacks_x                             0x626170
#define CHtmlWnd__AddObserver_x                                    0x626190
#define CHtmlWnd__RemoveObserver_x                                 0x6261F0
#define Window__getProgress_x                                      0x861520
#define Window__getStatus_x                                        0x861540
#define Window__getURI_x                                           0x861550

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96E610

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91D680

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8060
#define CXStr__CXStr1_x                                            0x500CD0
#define CXStr__CXStr3_x                                            0x8FF5B0
#define CXStr__dCXStr_x                                            0x4787D0
#define CXStr__operator_equal_x                                    0x8FF7E0
#define CXStr__operator_equal1_x                                   0x8FF820
#define CXStr__operator_plus_equal1_x                              0x9002B0
#define CXStr__SetString_x                                         0x9021A0
#define CXStr__operator_char_p_x                                   0x8FFCF0
#define CXStr__GetChar_x                                           0x901AD0
#define CXStr__Delete_x                                            0x9013A0
#define CXStr__GetUnicode_x                                        0x901B40
#define CXStr__GetLength_x                                         0x4A8E10
#define CXStr__Mid_x                                               0x47D470
#define CXStr__Insert_x                                            0x901BA0
#define CXStr__FindNext_x                                          0x901810

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x951A50
#define CXWnd__BringToTop_x                                        0x936CD0
#define CXWnd__Center_x                                            0x936850
#define CXWnd__ClrFocus_x                                          0x936660
#define CXWnd__Destroy_x                                           0x936710
#define CXWnd__DoAllDrawing_x                                      0x932C80
#define CXWnd__DrawChildren_x                                      0x932C50
#define CXWnd__DrawColoredRect_x                                   0x9330E0
#define CXWnd__DrawTooltip_x                                       0x931790
#define CXWnd__DrawTooltipAtPoint_x                                0x931850
#define CXWnd__GetBorderFrame_x                                    0x932F40
#define CXWnd__GetChildWndAt_x                                     0x936D70
#define CXWnd__GetClientClipRect_x                                 0x934F40
#define CXWnd__GetScreenClipRect_x                                 0x935010
#define CXWnd__GetScreenRect_x                                     0x9351E0
#define CXWnd__GetTooltipRect_x                                    0x933130
#define CXWnd__GetWindowTextA_x                                    0x49CAF0
#define CXWnd__IsActive_x                                          0x933860
#define CXWnd__IsDescendantOf_x                                    0x935BB0
#define CXWnd__IsReallyVisible_x                                   0x935BE0
#define CXWnd__IsType_x                                            0x9373D0
#define CXWnd__Move_x                                              0x935C50
#define CXWnd__Move1_x                                             0x935D00
#define CXWnd__ProcessTransition_x                                 0x936800
#define CXWnd__Refade_x                                            0x935FC0
#define CXWnd__Resize_x                                            0x936290
#define CXWnd__Right_x                                             0x936A90
#define CXWnd__SetFocus_x                                          0x936620
#define CXWnd__SetFont_x                                           0x936690
#define CXWnd__SetKeyTooltip_x                                     0x9371F0
#define CXWnd__SetMouseOver_x                                      0x934090
#define CXWnd__StartFade_x                                         0x935A90
#define CXWnd__GetChildItem_x                                      0x936EE0
#define CXWnd__SetParent_x                                         0x935940
#define CXWnd__Minimize_x                                          0x936300

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x969C50

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x939C00
#define CXWndManager__DrawWindows_x                                0x939C20
#define CXWndManager__GetKeyboardFlags_x                           0x93C420
#define CXWndManager__HandleKeyboardMsg_x                          0x93BFD0
#define CXWndManager__RemoveWnd_x                                  0x93C650
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93CBD0

// CDBStr
#define CDBStr__GetString_x                                        0x53D980

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBC50
#define EQ_Character__Cur_HP_x                                     0x4D1C00
#define EQ_Character__Cur_Mana_x                                   0x4D9330
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEC90
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2730
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2880
#define EQ_Character__GetHPRegen_x                                 0x4DF100
#define EQ_Character__GetEnduranceRegen_x                          0x4DF700
#define EQ_Character__GetManaRegen_x                               0x4DFB40
#define EQ_Character__Max_Endurance_x                              0x64C370
#define EQ_Character__Max_HP_x                                     0x4D1A30
#define EQ_Character__Max_Mana_x                                   0x64C170
#define EQ_Character__doCombatAbility_x                            0x64E7C0
#define EQ_Character__UseSkill_x                                   0x4E1910
#define EQ_Character__GetConLevel_x                                0x645160
#define EQ_Character__IsExpansionFlag_x                            0x5A8C10
#define EQ_Character__TotalEffect_x                                0x4C50F0
#define EQ_Character__GetPCSpellAffect_x                           0x4BF9E0
#define EQ_Character__SpellDuration_x                              0x4BF510
#define EQ_Character__GetAdjustedSkill_x                           0x4D4980
#define EQ_Character__GetBaseSkill_x                               0x4D5920
#define EQ_Character__CanUseItem_x                                 0x4D9640

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CB720

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x6628F0

//PcClient
#define PcClient__PcClient_x                                       0x6428A0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B98B0
#define CCharacterListWnd__EnterWorld_x                            0x4B92F0
#define CCharacterListWnd__Quit_x                                  0x4B9040
#define CCharacterListWnd__UpdateList_x                            0x4B9480

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x627340
#define EQ_Item__CreateItemTagString_x                             0x8A5AC0
#define EQ_Item__IsStackable_x                                     0x8AA7E0
#define EQ_Item__GetImageNum_x                                     0x8A75C0
#define EQ_Item__CreateItemClient_x                                0x626590
#define EQ_Item__GetItemValue_x                                    0x8A89C0
#define EQ_Item__ValueSellMerchant_x                               0x8AC170
#define EQ_Item__IsKeyRingItem_x                                   0x8AA100
#define EQ_Item__CanGoInBag_x                                      0x627460
#define EQ_Item__IsEmpty_x                                         0x8A9C40
#define EQ_Item__GetMaxItemCount_x                                 0x8A8DD0
#define EQ_Item__GetHeldItem_x                                     0x8A7490
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A5400

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55BF00
#define EQ_LoadingS__Array_x                                       0xC29B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64CCD0
#define EQ_PC__GetAlternateAbilityId_x                             0x8B5390
#define EQ_PC__GetCombatAbility_x                                  0x8B5A00
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B5A70
#define EQ_PC__GetItemRecastTimer_x                                0x64ED40
#define EQ_PC__HasLoreItem_x                                       0x645920
#define EQ_PC__AlertInventoryChanged_x                             0x644AA0
#define EQ_PC__GetPcZoneClient_x                                   0x6713A0
#define EQ_PC__RemoveMyAffect_x                                    0x651F70
#define EQ_PC__GetKeyRingItems_x                                   0x8B6300
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B6090
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B6600

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AF1C0
#define EQItemList__add_object_x                                   0x5DCAD0
#define EQItemList__add_item_x                                     0x5AF720
#define EQItemList__delete_item_x                                  0x5AF770
#define EQItemList__FreeItemList_x                                 0x5AF670

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53A470

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x664170
#define EQPlayer__dEQPlayer_x                                      0x6574D0
#define EQPlayer__DoAttack_x                                       0x66C040
#define EQPlayer__EQPlayer_x                                       0x657B90
#define EQPlayer__SetNameSpriteState_x                             0x65BE50
#define EQPlayer__SetNameSpriteTint_x                              0x65CD20
#define PlayerBase__HasProperty_j_x                                0x99C440
#define EQPlayer__IsTargetable_x                                   0x99C8E0
#define EQPlayer__CanSee_x                                         0x99C740
#define EQPlayer__CanSee1_x                                        0x99C810
#define PlayerBase__GetVisibilityLineSegment_x                     0x99C500

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66EE40
#define PlayerZoneClient__GetLevel_x                               0x6713E0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DDC40
#define PlayerZoneClient__LegalPlayerRace_x                        0x555340

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x666F30
#define EQPlayerManager__GetSpawnByName_x                          0x666FE0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x667070

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x62AAC0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x62AB40
#define KeypressHandler__AttachKeyToEqCommand_x                    0x62AB80
#define KeypressHandler__ClearCommandStateArray_x                  0x62BF90
#define KeypressHandler__HandleKeyDown_x                           0x62BFB0
#define KeypressHandler__HandleKeyUp_x                             0x62C050
#define KeypressHandler__SaveKeymapping_x                          0x62C4A0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x781A70
#define MapViewMap__SaveEx_x                                       0x784E30
#define MapViewMap__SetZoom_x                                      0x7894F0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C9640

// StringTable 
#define StringTable__getString_x                                   0x8C45A0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x651BE0
#define PcZoneClient__RemovePetEffect_x                            0x652210
#define PcZoneClient__HasAlternateAbility_x                        0x64BFA0
#define PcZoneClient__GetCurrentMod_x                              0x4E49D0
#define PcZoneClient__GetModCap_x                                  0x4E48D0
#define PcZoneClient__CanEquipItem_x                               0x64C670
#define PcZoneClient__GetItemByID_x                                0x64F1B0
#define PcZoneClient__GetItemByItemClass_x                         0x64F300
#define PcZoneClient__RemoveBuffEffect_x                           0x652230
#define PcZoneClient__BandolierSwap_x                              0x64D280
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64ECE0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E27D0

//IconCache
#define IconCache__GetIcon_x                                       0x723130

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x71ABD0
#define CContainerMgr__CloseContainer_x                            0x71AEA0
#define CContainerMgr__OpenExperimentContainer_x                   0x71B920

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D9DA0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61F4D0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x778010
#define CLootWnd__RequestLootSlot_x                                0x777240

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57C840
#define EQ_Spell__SpellAffects_x                                   0x57CCB0
#define EQ_Spell__SpellAffectBase_x                                0x57CA70
#define EQ_Spell__IsStackable_x                                    0x4C9640
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C94F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6C00
#define EQ_Spell__IsSPAStacking_x                                  0x57DB00
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57D010
#define EQ_Spell__IsNoRemove_x                                     0x4C9620
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57DB10
#define __IsResEffectSpell_x                                       0x4C8B30

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD150

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D3DA0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x820C20
#define CTargetWnd__WndNotification_x                              0x8204B0
#define CTargetWnd__RefreshTargetBuffs_x                           0x820780
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81F610

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x825220

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x537EF0
#define CTaskManager__HandleMessage_x                              0x5363A0
#define CTaskManager__GetTaskStatus_x                              0x537FA0
#define CTaskManager__GetElementDescription_x                      0x538020

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x577950
#define EqSoundManager__PlayScriptMp3_x                            0x577C10
#define EqSoundManager__SoundAssistPlay_x                          0x689750
#define EqSoundManager__WaveInstancePlay_x                         0x688CC0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52B790

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x958080

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x563A10
#define CAltAbilityData__GetMercMaxRank_x                          0x5639A0
#define CAltAbilityData__GetMaxRank_x                              0x558FE0

//CTargetRing
#define CTargetRing__Cast_x                                        0x61D5F0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C94D0
#define CharacterBase__CreateItemGlobalIndex_x                     0x512980
#define CharacterBase__CreateItemIndex_x                           0x625720
#define CharacterBase__GetItemPossession_x                         0x4FE640
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DC390
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DC3F0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x701D90
#define CCastSpellWnd__IsBardSongPlaying_x                         0x7025C0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x702670

//messages
#define msg_spell_worn_off_x                                       0x5A0D30
#define msg_new_text_x                                             0x595AC0
#define __msgTokenTextParam_x                                      0x5A3260
#define msgTokenText_x                                             0x5A34B0

//SpellManager
#define SpellManager__vftable_x                                    0xAEE584
#define SpellManager__SpellManager_x                               0x68CA80
#define Spellmanager__LoadTextSpells_x                             0x68D370
#define SpellManager__GetSpellByGroupAndRank_x                     0x68CC50

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9A0370

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x513000
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A7030
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63E0E0
#define ItemGlobalIndex__IsValidIndex_x                            0x513060

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D4740
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D49C0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x770880

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71F300
#define CCursorAttachment__AttachToCursor1_x                       0x71F340
#define CCursorAttachment__Deactivate_x                            0x720330

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94AD90
#define CSidlManagerBase__CreatePageWnd_x                          0x94A580
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x946800
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x946790

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x967DE0
#define CEQSuiteTextureLoader__GetTexture_x                        0x967AA0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50FF20
#define CFindItemWnd__WndNotification_x                            0x510A00
#define CFindItemWnd__Update_x                                     0x511570
#define CFindItemWnd__PickupSelectedItem_x                         0x50F760

//IString
#define IString__Append_x                                          0x4F0FB0

//Camera
#define CDisplay__cameraType_x                                     0xE03788
#define EverQuest__Cameras_x                                       0xEC6C1C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x5186E0
#define LootFiltersManager__GetItemFilterData_x                    0x517FE0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x518010
#define LootFiltersManager__SetItemLootFilter_x                    0x518230

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C7D50

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A5EC0
#define CResolutionHandler__GetWindowedStyle_x                     0x684030

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7179A0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E9B00
#define CDistillerInfo__Instance_x                                 0x8E9AA0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7368C0
#define CGroupWnd__UpdateDisplay_x                                 0x735C10

//ItemBase
#define ItemBase__IsLore_x                                         0x8AA1B0
#define ItemBase__IsLoreEquipped_x                                 0x8AA220

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DCA30
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DCB70
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DCBD0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x679AC0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67D430

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x506200

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F2F40
#define FactionManagerClient__HandleFactionMessage_x               0x4F35B0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F3B70
#define FactionManagerClient__GetMaxFaction_x                      0x4F3B8F
#define FactionManagerClient__GetMinFaction_x                      0x4F3B40

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FE610

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92F3F0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE00

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FE890

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x562EB0

//CTargetManager
#define CTargetManager__Get_x                                      0x6902D0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x679AC0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8E20

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AF610

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF642B0

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
