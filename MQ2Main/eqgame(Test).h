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
#define __ExpectedVersionDate                                     "Feb 25 2020"
#define __ExpectedVersionTime                                     "16:51:51"
#define __ActualVersionDate_x                                      0xB17690
#define __ActualVersionTime_x                                      0xB17684
#define __ActualVersionBuild_x                                     0xB033DC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x63C090
#define __MemChecker1_x                                            0x90F9A0
#define __MemChecker2_x                                            0x6CAC70
#define __MemChecker3_x                                            0x6CABC0
#define __MemChecker4_x                                            0x866420
#define __EncryptPad0_x                                            0xC4F4E8
#define __EncryptPad1_x                                            0xCAD650
#define __EncryptPad2_x                                            0xC5FD80
#define __EncryptPad3_x                                            0xC5F980
#define __EncryptPad4_x                                            0xC9DC00
#define __EncryptPad5_x                                            0xF6E7D4
#define __AC1_x                                                    0x822D36
#define __AC2_x                                                    0x5F5F0F
#define __AC3_x                                                    0x5FD60F
#define __AC4_x                                                    0x6015E0
#define __AC5_x                                                    0x6078EF
#define __AC6_x                                                    0x60BDE6
#define __AC7_x                                                    0x5F5980
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x6E148

// Direct Input
#define DI8__Main_x                                                0xF6E7F4
#define DI8__Keyboard_x                                            0xF6E7F8
#define DI8__Mouse_x                                               0xF6E814
#define DI8__Mouse_Copy_x                                          0xEC9E7C
#define DI8__Mouse_Check_x                                         0xF6F2C0
#define __AutoSkillArray_x                                         0xECAD94
#define __Attack_x                                                 0xF68BBB
#define __Autofire_x                                               0xF68BBC
#define __BindList_x                                               0xC3DF30
#define g_eqCommandStates_x                                        0xC3ECB0
#define __Clicks_x                                                 0xEC9F34
#define __CommandList_x                                            0xC3F870
#define __CurrentMapLabel_x                                        0xF81684
#define __CurrentSocial_x                                          0xC277CC
#define __DoAbilityList_x                                          0xF006DC
#define __do_loot_x                                                0x5C19F0
#define __DrawHandler_x                                            0x1600A00
#define __GroupCount_x                                             0xEC49C2
#define __Guilds_x                                                 0xEC8DC0
#define __gWorld_x                                                 0xEC4C08
#define __HWnd_x                                                   0xF6F2A0
#define __heqmain_x                                                0xF71754
#define __InChatMode_x                                             0xEC9E64
#define __LastTell_x                                               0xECBDD8
#define __LMouseHeldTime_x                                         0xEC9FA0
#define __Mouse_x                                                  0xF6E7E0
#define __MouseLook_x                                              0xEC9EFA
#define __MouseEventTime_x                                         0xF6969C
#define __gpbCommandEvent_x                                        0xEC4C10
#define __NetStatusToggle_x                                        0xEC9EFD
#define __PCNames_x                                                0xECB384
#define __RangeAttackReady_x                                       0xECB078
#define __RMouseHeldTime_x                                         0xEC9F9C
#define __RunWalkState_x                                           0xEC9E68
#define __ScreenMode_x                                             0xE10194
#define __ScreenX_x                                                0xEC9E1C
#define __ScreenY_x                                                0xEC9E18
#define __ScreenXMax_x                                             0xEC9E20
#define __ScreenYMax_x                                             0xEC9E24
#define __ServerHost_x                                             0xEC4E43
#define __ServerName_x                                             0xF0069C
#define __ShiftKeyDown_x                                           0xECA4F4
#define __ShowNames_x                                              0xECB234
#define EverQuestInfo__bSocialChanged_x                            0xF00724
#define __Socials_x                                                0xF0079C
#define __SubscriptionType_x                                       0xFC5B90
#define __TargetAggroHolder_x                                      0xF84038
#define __ZoneType_x                                               0xECA2F8
#define __GroupAggro_x                                             0xF84078
#define __LoginName_x                                              0xF6EF4C
#define __Inviter_x                                                0xF68B38
#define __AttackOnAssist_x                                         0xECB1F0
#define __UseTellWindows_x                                         0xECB520
#define __gfMaxZoomCameraDistance_x                                0xB0D000
#define __gfMaxCameraDistance_x                                    0xB393AC
#define __pulAutoRun_x                                             0xEC9F18
#define __pulForward_x                                             0xECB558
#define __pulBackward_x                                            0xECB55C
#define __pulTurnRight_x                                           0xECB560
#define __pulTurnLeft_x                                            0xECB564
#define __pulStrafeLeft_x                                          0xECB568
#define __pulStrafeRight_x                                         0xECB56C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEC5158
#define instEQZoneInfo_x                                           0xECA0F0
#define pinstActiveBanker_x                                        0xEC4CF0
#define pinstActiveCorpse_x                                        0xEC4CE8
#define pinstActiveGMaster_x                                       0xEC4CEC
#define pinstActiveMerchant_x                                      0xEC4CE4
#define pinstAltAdvManager_x                                       0xE11388
#define pinstBandageTarget_x                                       0xEC4D00
#define pinstCamActor_x                                            0xE10188
#define pinstCDBStr_x                                              0xE100A4
#define pinstCDisplay_x                                            0xEC485C
#define pinstCEverQuest_x                                          0xF6E810
#define pinstEverQuestInfo_x                                       0xEC9E10
#define pinstCharData_x                                            0xEC4BFC
#define pinstCharSpawn_x                                           0xEC4D38
#define pinstControlledMissile_x                                   0xEC284C
#define pinstControlledPlayer_x                                    0xEC4D38
#define pinstCResolutionHandler_x                                  0x1600C30
#define pinstCSidlManager_x                                        0x15FFBC8
#define pinstCXWndManager_x                                        0x15FFBC4
#define instDynamicZone_x                                          0xEC8C98
#define pinstDZMember_x                                            0xEC8DA8
#define pinstDZTimerInfo_x                                         0xEC8DAC
#define pinstEqLogin_x                                             0xF6E898
#define instEQMisc_x                                               0xE0FFE8
#define pinstEQSoundManager_x                                      0xE12358
#define pinstEQSpellStrings_x                                      0xCD29F8
#define instExpeditionLeader_x                                     0xEC8CE2
#define instExpeditionName_x                                       0xEC8D22
#define pinstGroup_x                                               0xEC49BE
#define pinstImeManager_x                                          0x15FFBC0
#define pinstLocalPlayer_x                                         0xEC4CE0
#define pinstMercenaryData_x                                       0xF6B194
#define pinstMercenaryStats_x                                      0xF84184
#define pinstModelPlayer_x                                         0xEC4CF8
#define pinstPCData_x                                              0xEC4BFC
#define pinstSkillMgr_x                                            0xF6D2F8
#define pinstSpawnManager_x                                        0xF6BDA0
#define pinstSpellManager_x                                        0xF6D538
#define pinstSpellSets_x                                           0xF617E4
#define pinstStringTable_x                                         0xEC4C00
#define pinstSwitchManager_x                                       0xEC26F8
#define pinstTarget_x                                              0xEC4D34
#define pinstTargetObject_x                                        0xEC4F4C
#define pinstTargetSwitch_x                                        0xEC2854
#define pinstTaskMember_x                                          0xE0FE78
#define pinstTrackTarget_x                                         0xEC4D3C
#define pinstTradeTarget_x                                         0xEC4CF4
#define instTributeActive_x                                        0xE10009
#define pinstViewActor_x                                           0xE10184
#define pinstWorldData_x                                           0xEC4860
#define pinstZoneAddr_x                                            0xECA390
#define pinstPlayerPath_x                                          0xF6BE38
#define pinstTargetIndicator_x                                     0xF6D7A0
#define EQObject_Top_x                                             0xEC4CDC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE1045C
#define pinstCAchievementsWnd_x                                    0xE1096C
#define pinstCActionsWnd_x                                         0xE1049C
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE10180
#define pinstCAdvancedLootWnd_x                                    0xE109D0
#define pinstCAdventureLeaderboardWnd_x                            0xF7AE58
#define pinstCAdventureRequestWnd_x                                0xF7AF08
#define pinstCAdventureStatsWnd_x                                  0xF7AFB8
#define pinstCAggroMeterWnd_x                                      0xE1019C
#define pinstCAlarmWnd_x                                           0xE109AC
#define pinstCAlertHistoryWnd_x                                    0xE101F0
#define pinstCAlertStackWnd_x                                      0xE109D4
#define pinstCAlertWnd_x                                           0xE10154
#define pinstCAltStorageWnd_x                                      0xF7B318
#define pinstCAudioTriggersWindow_x                                0xCC4D28
#define pinstCAuraWnd_x                                            0xE10144
#define pinstCAvaZoneWnd_x                                         0xE10210
#define pinstCBandolierWnd_x                                       0xE10178
#define pinstCBankWnd_x                                            0xE101DC
#define pinstCBarterMerchantWnd_x                                  0xF7C558
#define pinstCBarterSearchWnd_x                                    0xF7C608
#define pinstCBarterWnd_x                                          0xF7C6B8
#define pinstCBazaarConfirmationWnd_x                              0xE109A8
#define pinstCBazaarSearchWnd_x                                    0xE10460
#define pinstCBazaarWnd_x                                          0xE1098C
#define pinstCBlockedBuffWnd_x                                     0xE1014C
#define pinstCBlockedPetBuffWnd_x                                  0xE10170
#define pinstCBodyTintWnd_x                                        0xE104C0
#define pinstCBookWnd_x                                            0xE101C8
#define pinstCBreathWnd_x                                          0xE10470
#define pinstCBuffWindowNORMAL_x                                   0xE109C4
#define pinstCBuffWindowSHORT_x                                    0xE109C8
#define pinstCBugReportWnd_x                                       0xE101D8
#define pinstCButtonWnd_x                                          0x15FFE30
#define pinstCCastingWnd_x                                         0xE101B4
#define pinstCCastSpellWnd_x                                       0xE10464
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE10940
#define pinstCChatWindowManager_x                                  0xF7D178
#define pinstCClaimWnd_x                                           0xF7D2D0
#define pinstCColorPickerWnd_x                                     0xE10224
#define pinstCCombatAbilityWnd_x                                   0xE1099C
#define pinstCCombatSkillsSelectWnd_x                              0xE10950
#define pinstCCompassWnd_x                                         0xE104A8
#define pinstCConfirmationDialog_x                                 0xF821D0
#define pinstCContainerMgr_x                                       0xE1093C
#define pinstCContextMenuManager_x                                 0x15FFB80
#define pinstCCursorAttachment_x                                   0xE101A8
#define pinstCDynamicZoneWnd_x                                     0xF7D898
#define pinstCEditLabelWnd_x                                       0xE109C0
#define pinstCEQMainWnd_x                                          0xF7DAE0
#define pinstCEventCalendarWnd_x                                   0xE10450
#define pinstCExtendedTargetWnd_x                                  0xE1016C
#define pinstCFacePick_x                                           0xE10968
#define pinstCFactionWnd_x                                         0xE10978
#define pinstCFellowshipWnd_x                                      0xF7DCE0
#define pinstCFileSelectionWnd_x                                   0xE10218
#define pinstCFindItemWnd_x                                        0xE10960
#define pinstCFindLocationWnd_x                                    0xF7DE38
#define pinstCFriendsWnd_x                                         0xE1095C
#define pinstCGemsGameWnd_x                                        0xE10974
#define pinstCGiveWnd_x                                            0xE109B4
#define pinstCGroupSearchFiltersWnd_x                              0xE101B8
#define pinstCGroupSearchWnd_x                                     0xF7E230
#define pinstCGroupWnd_x                                           0xF7E2E0
#define pinstCGuildBankWnd_x                                       0xECB1D4
#define pinstCGuildCreationWnd_x                                   0xF7E440
#define pinstCGuildMgmtWnd_x                                       0xF7E4F0
#define pinstCharacterCreation_x                                   0xE10958
#define pinstCHelpWnd_x                                            0xE109A4
#define pinstCHeritageSelectionWnd_x                               0xE1097C
#define pinstCHotButtonWnd_x                                       0xF80648
#define pinstCHotButtonWnd1_x                                      0xF80648
#define pinstCHotButtonWnd2_x                                      0xF8064C
#define pinstCHotButtonWnd3_x                                      0xF80650
#define pinstCHotButtonWnd4_x                                      0xF80654
#define pinstCIconSelectionWnd_x                                   0xE101A0
#define pinstCInspectWnd_x                                         0xE10174
#define pinstCInventoryWnd_x                                       0xE10148
#define pinstCInvSlotMgr_x                                         0xE1046C
#define pinstCItemDisplayManager_x                                 0xF80BD8
#define pinstCItemExpTransferWnd_x                                 0xF80D08
#define pinstCItemOverflowWnd_x                                    0xE10468
#define pinstCJournalCatWnd_x                                      0xE10238
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE101F4
#define pinstCKeyRingWnd_x                                         0xE101B0
#define pinstCLargeDialogWnd_x                                     0xF82E50
#define pinstCLayoutCopyWnd_x                                      0xF81058
#define pinstCLFGuildWnd_x                                         0xF81108
#define pinstCLoadskinWnd_x                                        0xE10988
#define pinstCLootFiltersCopyWnd_x                                 0xCE1380
#define pinstCLootFiltersWnd_x                                     0xE109D8
#define pinstCLootSettingsWnd_x                                    0xE10164
#define pinstCLootWnd_x                                            0xE10440
#define pinstCMailAddressBookWnd_x                                 0xE10474
#define pinstCMailCompositionWnd_x                                 0xE10454
#define pinstCMailIgnoreListWnd_x                                  0xE10478
#define pinstCMailWnd_x                                            0xE10228
#define pinstCManageLootWnd_x                                      0xE11838
#define pinstCMapToolbarWnd_x                                      0xE109B0
#define pinstCMapViewWnd_x                                         0xE10980
#define pinstCMarketplaceWnd_x                                     0xE10140
#define pinstCMerchantWnd_x                                        0xE1044C
#define pinstCMIZoneSelectWnd_x                                    0xF81940
#define pinstCMusicPlayerWnd_x                                     0xE101E8
#define pinstCNameChangeMercWnd_x                                  0xE10990
#define pinstCNameChangePetWnd_x                                   0xE10970
#define pinstCNameChangeWnd_x                                      0xE109B8
#define pinstCNoteWnd_x                                            0xE10994
#define pinstCObjectPreviewWnd_x                                   0xE1015C
#define pinstCOptionsWnd_x                                         0xE109A0
#define pinstCPetInfoWnd_x                                         0xE10200
#define pinstCPetitionQWnd_x                                       0xE10944
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE1052C
#define pinstCPlayerWnd_x                                          0xE10214
#define pinstCPopupWndManager_x                                    0xF821D0
#define pinstCProgressionSelectionWnd_x                            0xF82280
#define pinstCPurchaseGroupWnd_x                                   0xE101CC
#define pinstCPurchaseWnd_x                                        0xE1017C
#define pinstCPvPLeaderboardWnd_x                                  0xF82330
#define pinstCPvPStatsWnd_x                                        0xF823E0
#define pinstCQuantityWnd_x                                        0xE101F8
#define pinstCRaceChangeWnd_x                                      0xE109CC
#define pinstCRaidOptionsWnd_x                                     0xE101C4
#define pinstCRaidWnd_x                                            0xE10444
#define pinstCRealEstateItemsWnd_x                                 0xE10964
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE10480
#define pinstCRealEstateManageWnd_x                                0xE101D4
#define pinstCRealEstateNeighborhoodWnd_x                          0xE101EC
#define pinstCRealEstatePlotSearchWnd_x                            0xE101FC
#define pinstCRealEstatePurchaseWnd_x                              0xE1021C
#define pinstCRespawnWnd_x                                         0xE10168
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE1094C
#define pinstCSendMoneyWnd_x                                       0xE109BC
#define pinstCServerListWnd_x                                      0xE1022C
#define pinstCSkillsSelectWnd_x                                    0xE10938
#define pinstCSkillsWnd_x                                          0xE104AC
#define pinstCSocialEditWnd_x                                      0xE101AC
#define pinstCSocialWnd_x                                          0xE10984
#define pinstCSpellBookWnd_x                                       0xE10998
#define pinstCStoryWnd_x                                           0xE1047C
#define pinstCTargetOfTargetWnd_x                                  0xF84208
#define pinstCTargetWnd_x                                          0xE10160
#define pinstCTaskOverlayWnd_x                                     0xE101C0
#define pinstCTaskSelectWnd_x                                      0xF84360
#define pinstCTaskManager_x                                        0xCE1CC0
#define pinstCTaskTemplateSelectWnd_x                              0xF84410
#define pinstCTaskWnd_x                                            0xF844C0
#define pinstCTextEntryWnd_x                                       0xE101BC
#define pinstCTimeLeftWnd_x                                        0xE104C4
#define pinstCTipWndCONTEXT_x                                      0xF846C4
#define pinstCTipWndOFDAY_x                                        0xF846C0
#define pinstCTitleWnd_x                                           0xF84770
#define pinstCTrackingWnd_x                                        0xE10150
#define pinstCTradeskillWnd_x                                      0xF848D8
#define pinstCTradeWnd_x                                           0xE10530
#define pinstCTrainWnd_x                                           0xE10230
#define pinstCTributeBenefitWnd_x                                  0xF84AD8
#define pinstCTributeMasterWnd_x                                   0xF84B88
#define pinstCTributeTrophyWnd_x                                   0xF84C38
#define pinstCVideoModesWnd_x                                      0xE10234
#define pinstCVoiceMacroWnd_x                                      0xF6DF08
#define pinstCVoteResultsWnd_x                                     0xE10954
#define pinstCVoteWnd_x                                            0xE10948
#define pinstCWebManager_x                                         0xF6E584
#define pinstCZoneGuideWnd_x                                       0xE101D0
#define pinstCZonePathWnd_x                                        0xE101E0

#define pinstEQSuiteTextureLoader_x                                0xCAF128
#define pinstItemIconCache_x                                       0xF7DA98
#define pinstLootFiltersManager_x                                  0xCE1430
#define pinstRewardSelectionWnd_x                                  0xF82B28

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5BCE50
#define __CastRay2_x                                               0x5BCEA0
#define __ConvertItemTags_x                                        0x5D89E0
#define __CleanItemTags_x                                          0x47CFF0
#define __DoesFileExist_x                                          0x912A20
#define __EQGetTime_x                                              0x90F470
#define __ExecuteCmd_x                                             0x5B56A0
#define __FixHeading_x                                             0x9A9B50
#define __GameLoop_x                                               0x6C9E40
#define __get_bearing_x                                            0x5BC9C0
#define __get_melee_range_x                                        0x5BD090
#define __GetAnimationCache_x                                      0x72F3A0
#define __GetGaugeValueFromEQ_x                                    0x8211E0
#define __GetLabelFromEQ_x                                         0x822CC0
#define __GetXTargetType_x                                         0x9AB5A0
#define __HandleMouseWheel_x                                       0x6CAD20
#define __HeadingDiff_x                                            0x9A9BC0
#define __HelpPath_x                                               0xF6928C
#define __LoadFrontEnd_x                                           0x6C7160
#define __NewUIINI_x                                               0x820EB0
#define __ProcessGameEvents_x                                      0x61D5B0
#define __ProcessMouseEvent_x                                      0x61CD70
#define __SaveColors_x                                             0x558660
#define __STMLToText_x                                             0x94CF40
#define __ToggleKeyRingItem_x                                      0x519560
#define CMemoryMappedFile__SetFile_x                               0xA99060
#define CrashDetected_x                                            0x6C8C00
#define DrawNetStatus_x                                            0x6494F0
#define Expansion_HoT_x                                            0xECB1DC
#define Teleport_Table_Size_x                                      0xEC4C9C
#define Teleport_Table_x                                           0xEC2858
#define Util__FastTime_x                                           0x90F040

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4901E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4990F0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x498EC0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493780
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492BD0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x560860
#define AltAdvManager__IsAbilityReady_x                            0x55F600
#define AltAdvManager__GetAAById_x                                 0x55F990
#define AltAdvManager__CanTrainAbility_x                           0x55FA00
#define AltAdvManager__CanSeeAbility_x                             0x55FD60

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9EE0
#define CharacterZoneClient__HasSkill_x                            0x4D4D60
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6480
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE620
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAC50
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8E40
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8F20
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9000
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2D20
#define CharacterZoneClient__BardCastBard_x                        0x4C5880
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAD20
#define CharacterZoneClient__GetEffect_x                           0x4BAB90
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3D70
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C3E40
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C3E90
#define CharacterZoneClient__CalcAffectChange_x                    0x4C3FE0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C41B0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2A90
#define CharacterZoneClient__FindItemByGuid_x                      0x4D73E0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6E60

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6F0A40
#define CBankWnd__WndNotification_x                                0x6F0820

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6FE4A0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x62BD20
#define CButtonWnd__CButtonWnd_x                                   0x9492F0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x71E440
#define CChatManager__InitContextMenu_x                            0x717570
#define CChatManager__FreeChatWindow_x                             0x71CF80
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8360
#define CChatManager__SetLockedActiveChatWindow_x                  0x71E0C0
#define CChatManager__CreateChatWindow_x                           0x71D5C0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8470

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x95DAB0
#define CContextMenu__dCContextMenu_x                              0x95DCE0
#define CContextMenu__AddMenuItem_x                                0x95DCF0
#define CContextMenu__RemoveMenuItem_x                             0x95DFF0
#define CContextMenu__RemoveAllMenuItems_x                         0x95E010
#define CContextMenu__CheckMenuItem_x                              0x95E090
#define CContextMenu__SetMenuItem_x                                0x95DF20
#define CContextMenu__AddSeparator_x                               0x95DE80

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x95E620
#define CContextMenuManager__RemoveMenu_x                          0x95E690
#define CContextMenuManager__PopupMenu_x                           0x95E750
#define CContextMenuManager__Flush_x                               0x95E5C0
#define CContextMenuManager__GetMenu_x                             0x49B380
#define CContextMenuManager__CreateDefaultMenu_x                   0x729BA0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8B2FA0
#define CChatService__GetFriendName_x                              0x8EA7F0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x71EC70
#define CChatWindow__Clear_x                                       0x71FF30
#define CChatWindow__WndNotification_x                             0x7206C0
#define CChatWindow__AddHistory_x                                  0x71F7F0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x95AF10
#define CComboWnd__Draw_x                                          0x95A420
#define CComboWnd__GetCurChoice_x                                  0x95AD50
#define CComboWnd__GetListRect_x                                   0x95A8C0
#define CComboWnd__GetTextRect_x                                   0x95AF70
#define CComboWnd__InsertChoice_x                                  0x95AA50
#define CComboWnd__SetColors_x                                     0x95AA20
#define CComboWnd__SetChoice_x                                     0x95AD20
#define CComboWnd__GetItemCount_x                                  0x95AD60
#define CComboWnd__GetCurChoiceText_x                              0x95ADA0
#define CComboWnd__GetChoiceText_x                                 0x95AD70
#define CComboWnd__InsertChoiceAtIndex_x                           0x95AAE0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x727580
#define CContainerWnd__vftable_x                                   0xB20884
#define CContainerWnd__SetContainer_x                              0x728AE0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x553010
#define CDisplay__PreZoneMainUI_x                                  0x553020
#define CDisplay__CleanGameUI_x                                    0x558420
#define CDisplay__GetClickedActor_x                                0x54B310
#define CDisplay__GetUserDefinedColor_x                            0x543970
#define CDisplay__GetWorldFilePath_x                               0x54CD80
#define CDisplay__is3dON_x                                         0x547F70
#define CDisplay__ReloadUI_x                                       0x552490
#define CDisplay__WriteTextHD2_x                                   0x547D60
#define CDisplay__TrueDistance_x                                   0x54EA40
#define CDisplay__SetViewActor_x                                   0x54AC30
#define CDisplay__GetFloorHeight_x                                 0x548030
#define CDisplay__SetRenderWindow_x                                0x546990
#define CDisplay__ToggleScreenshotMode_x                           0x54A700

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x97D740

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x960FF0
#define CEditWnd__EnsureCaretVisible_x                             0x9631B0
#define CEditWnd__GetCaretPt_x                                     0x962160
#define CEditWnd__GetCharIndexPt_x                                 0x961F10
#define CEditWnd__GetDisplayString_x                               0x961DB0
#define CEditWnd__GetHorzOffset_x                                  0x960620
#define CEditWnd__GetLineForPrintableChar_x                        0x9630B0
#define CEditWnd__GetSelStartPt_x                                  0x9621C0
#define CEditWnd__GetSTMLSafeText_x                                0x961BD0
#define CEditWnd__PointFromPrintableChar_x                         0x962CE0
#define CEditWnd__SelectableCharFromPoint_x                        0x962E50
#define CEditWnd__SetEditable_x                                    0x962290
#define CEditWnd__SetWindowTextA_x                                 0x961950
#define CEditWnd__ReplaceSelection_x                               0x962950
#define CEditWnd__ReplaceSelection1_x                              0x9628D0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60B2C0
#define CEverQuest__ClickedPlayer_x                                0x5FD3F0
#define CEverQuest__CreateTargetIndicator_x                        0x61A840
#define CEverQuest__DeleteTargetIndicator_x                        0x61A8D0
#define CEverQuest__DoTellWindow_x                                 0x4E8550
#define CEverQuest__OutputTextToLog_x                              0x4E8820
#define CEverQuest__DropHeldItemOnGround_x                         0x5F2430
#define CEverQuest__dsp_chat_x                                     0x4E8BB0
#define CEverQuest__trimName_x                                     0x616A30
#define CEverQuest__Emote_x                                        0x60BB20
#define CEverQuest__EnterZone_x                                    0x605BC0
#define CEverQuest__GetBodyTypeDesc_x                              0x6103E0
#define CEverQuest__GetClassDesc_x                                 0x610A20
#define CEverQuest__GetClassThreeLetterCode_x                      0x611020
#define CEverQuest__GetDeityDesc_x                                 0x619090
#define CEverQuest__GetLangDesc_x                                  0x6111E0
#define CEverQuest__GetRaceDesc_x                                  0x610A00
#define CEverQuest__InterpretCmd_x                                 0x619660
#define CEverQuest__LeftClickedOnPlayer_x                          0x5F6630
#define CEverQuest__LMouseUp_x                                     0x5F49C0
#define CEverQuest__RightClickedOnPlayer_x                         0x5F6F10
#define CEverQuest__RMouseUp_x                                     0x5F5940
#define CEverQuest__SetGameState_x                                 0x5F21C0
#define CEverQuest__UPCNotificationFlush_x                         0x616930
#define CEverQuest__IssuePetCommand_x                              0x6125E0
#define CEverQuest__ReportSuccessfulHit_x                          0x60CE70

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7394C0
#define CGaugeWnd__CalcLinesFillRect_x                             0x739520
#define CGaugeWnd__Draw_x                                          0x738B40

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF570
#define CGuild__GetGuildName_x                                     0x4AE5B0
#define CGuild__GetGuildIndex_x                                    0x4AE9F0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x753710

//CHotButton
#define CHotButton__SetButtonSize_x                                0x62C0E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x760730
#define CInvSlotMgr__MoveItem_x                                    0x75F440
#define CInvSlotMgr__SelectSlot_x                                  0x760800

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x75DCC0
#define CInvSlot__SliderComplete_x                                 0x75BA10
#define CInvSlot__GetItemBase_x                                    0x75B390
#define CInvSlot__UpdateItem_x                                     0x75B500

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x762280
#define CInvSlotWnd__CInvSlotWnd_x                                 0x761420
#define CInvSlotWnd__HandleLButtonUp_x                             0x761E00

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x81C580
#define CItemDisplayWnd__UpdateStrings_x                           0x770940
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76A670
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76AB80
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x770F50
#define CItemDisplayWnd__AboutToShow_x                             0x770590
#define CItemDisplayWnd__WndNotification_x                         0x772090
#define CItemDisplayWnd__RequestConvertItem_x                      0x771B00
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x76F600
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7703B0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x855190

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7765C0

// CLabel 
#define CLabel__Draw_x                                             0x77BFB0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9334D0
#define CListWnd__dCListWnd_x                                      0x9337F0
#define CListWnd__AddColumn_x                                      0x937C60
#define CListWnd__AddColumn1_x                                     0x937CB0
#define CListWnd__AddLine_x                                        0x938040
#define CListWnd__AddString_x                                      0x937E40
#define CListWnd__CalculateFirstVisibleLine_x                      0x937A20
#define CListWnd__CalculateVSBRange_x                              0x937800
#define CListWnd__ClearSel_x                                       0x938820
#define CListWnd__ClearAllSel_x                                    0x938880
#define CListWnd__CloseAndUpdateEditWindow_x                       0x939280
#define CListWnd__Compare_x                                        0x937130
#define CListWnd__Draw_x                                           0x933920
#define CListWnd__DrawColumnSeparators_x                           0x936100
#define CListWnd__DrawHeader_x                                     0x936570
#define CListWnd__DrawItem_x                                       0x936A70
#define CListWnd__DrawLine_x                                       0x936270
#define CListWnd__DrawSeparator_x                                  0x9361A0
#define CListWnd__EnableLine_x                                     0x9359E0
#define CListWnd__EnsureVisible_x                                  0x9391B0
#define CListWnd__ExtendSel_x                                      0x938750
#define CListWnd__GetColumnTooltip_x                               0x935520
#define CListWnd__GetColumnMinWidth_x                              0x935590
#define CListWnd__GetColumnWidth_x                                 0x935490
#define CListWnd__GetCurSel_x                                      0x934E20
#define CListWnd__GetItemAtPoint_x                                 0x935C50
#define CListWnd__GetItemAtPoint1_x                                0x935CC0
#define CListWnd__GetItemData_x                                    0x934EA0
#define CListWnd__GetItemHeight_x                                  0x935260
#define CListWnd__GetItemIcon_x                                    0x935030
#define CListWnd__GetItemRect_x                                    0x935AD0
#define CListWnd__GetItemText_x                                    0x934EE0
#define CListWnd__GetSelList_x                                     0x9388D0
#define CListWnd__GetSeparatorRect_x                               0x935F00
#define CListWnd__InsertLine_x                                     0x938430
#define CListWnd__RemoveLine_x                                     0x938580
#define CListWnd__SetColors_x                                      0x9377D0
#define CListWnd__SetColumnJustification_x                         0x937500
#define CListWnd__SetColumnLabel_x                                 0x937DE0
#define CListWnd__SetColumnWidth_x                                 0x937420
#define CListWnd__SetCurSel_x                                      0x938690
#define CListWnd__SetItemColor_x                                   0x938E70
#define CListWnd__SetItemData_x                                    0x938E30
#define CListWnd__SetItemText_x                                    0x938A40
#define CListWnd__ShiftColumnSeparator_x                           0x9375C0
#define CListWnd__Sort_x                                           0x9372B0
#define CListWnd__ToggleSel_x                                      0x9386C0
#define CListWnd__SetColumnsSizable_x                              0x937670
#define CListWnd__SetItemWnd_x                                     0x938CF0
#define CListWnd__GetItemWnd_x                                     0x935080
#define CListWnd__SetItemIcon_x                                    0x938AC0
#define CListWnd__CalculateCustomWindowPositions_x                 0x937B20
#define CListWnd__SetVScrollPos_x                                  0x937400

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7916B0
#define CMapViewWnd__GetWorldCoordinates_x                         0x78FDC0
#define CMapViewWnd__HandleLButtonDown_x                           0x78CE00

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B1A90
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B2370
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B28A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B5830
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B05F0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BB3E0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B16A0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8B86A0
#define CPacketScrambler__hton_x                                   0x8B8690

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9525A0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9529B0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9527A0
#define CSidlManager__CreateLabel_x                                0x8137F0
#define CSidlManager__CreateXWndFromTemplate_x                     0x955910
#define CSidlManager__CreateXWndFromTemplate1_x                    0x955AF0
#define CSidlManager__CreateXWnd_x                                 0x813720
#define CSidlManager__CreateHotButtonWnd_x                         0x813CF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x94F080
#define CSidlScreenWnd__CalculateVSBRange_x                        0x94EF80
#define CSidlScreenWnd__ConvertToRes_x                             0x978230
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x94EA10
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x94E700
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x94E7D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x94E8A0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x94F520
#define CSidlScreenWnd__EnableIniStorage_x                         0x94F9F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x94F710
#define CSidlScreenWnd__Init1_x                                    0x94E300
#define CSidlScreenWnd__LoadIniInfo_x                              0x94FA40
#define CSidlScreenWnd__LoadIniListWnd_x                           0x950580
#define CSidlScreenWnd__LoadSidlScreen_x                           0x94D700
#define CSidlScreenWnd__StoreIniInfo_x                             0x950100
#define CSidlScreenWnd__StoreIniVis_x                              0x950460
#define CSidlScreenWnd__WndNotification_x                          0x94F430
#define CSidlScreenWnd__GetChildItem_x                             0x94F970
#define CSidlScreenWnd__HandleLButtonUp_x                          0x93F060
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FFA50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x690990
#define CSkillMgr__GetSkillCap_x                                   0x690B70
#define CSkillMgr__GetNameToken_x                                  0x690110
#define CSkillMgr__IsActivatedSkill_x                              0x690250
#define CSkillMgr__IsCombatSkill_x                                 0x690190

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x95F400
#define CSliderWnd__SetValue_x                                     0x95F270
#define CSliderWnd__SetNumTicks_x                                  0x95F2D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x819950

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x967C20
#define CStmlWnd__ParseSTML_x                                      0x968F30
#define CStmlWnd__CalculateHSBRange_x                              0x968D00
#define CStmlWnd__CalculateVSBRange_x                              0x968C70
#define CStmlWnd__CanBreakAtCharacter_x                            0x96D040
#define CStmlWnd__FastForwardToEndOfTag_x                          0x96DCD0
#define CStmlWnd__ForceParseNow_x                                  0x9681C0
#define CStmlWnd__GetNextTagPiece_x                                0x96CFA0
#define CStmlWnd__GetSTMLText_x                                    0x508BC0
#define CStmlWnd__GetVisibleText_x                                 0x9681E0
#define CStmlWnd__InitializeWindowVariables_x                      0x96DB20
#define CStmlWnd__MakeStmlColorTag_x                               0x967290
#define CStmlWnd__MakeWndNotificationTag_x                         0x967300
#define CStmlWnd__SetSTMLText_x                                    0x966340
#define CStmlWnd__StripFirstSTMLLines_x                            0x96EDD0
#define CStmlWnd__UpdateHistoryString_x                            0x96DEE0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x965470
#define CTabWnd__DrawCurrentPage_x                                 0x965BA0
#define CTabWnd__DrawTab_x                                         0x9658C0
#define CTabWnd__GetCurrentPage_x                                  0x964C70
#define CTabWnd__GetPageInnerRect_x                                0x964EB0
#define CTabWnd__GetTabInnerRect_x                                 0x964DF0
#define CTabWnd__GetTabRect_x                                      0x964CA0
#define CTabWnd__InsertPage_x                                      0x9650C0
#define CTabWnd__SetPage_x                                         0x964F30
#define CTabWnd__SetPageRect_x                                     0x9653B0
#define CTabWnd__UpdatePage_x                                      0x965780
#define CTabWnd__GetPageFromTabIndex_x                             0x965800
#define CTabWnd__GetCurrentTabIndex_x                              0x964C60

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x7769B0
#define CPageWnd__SetTabText_x                                     0x9647C0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A90D0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x93BF40
#define CTextureFont__GetTextExtent_x                              0x93C100

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C3D20
#define CHtmlComponentWnd__ValidateUri_x                           0x755100
#define CHtmlWnd__SetClientCallbacks_x                             0x631190
#define CHtmlWnd__AddObserver_x                                    0x6311B0
#define CHtmlWnd__RemoveObserver_x                                 0x631210
#define Window__getProgress_x                                      0x86DA00
#define Window__getStatus_x                                        0x86DA20
#define Window__getURI_x                                           0x86DA30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x975040

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x929240

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8250
#define CXStr__CXStr1_x                                            0xA00440
#define CXStr__CXStr3_x                                            0x90B5D0
#define CXStr__dCXStr_x                                            0x4786A0
#define CXStr__operator_equal_x                                    0x90B800
#define CXStr__operator_equal1_x                                   0x90B840
#define CXStr__operator_plus_equal1_x                              0x90C2D0
#define CXStr__SetString_x                                         0x90E1C0
#define CXStr__operator_char_p_x                                   0x90BD40
#define CXStr__GetChar_x                                           0x90DAF0
#define CXStr__Delete_x                                            0x90D3C0
#define CXStr__GetUnicode_x                                        0x90DB60
#define CXStr__GetLength_x                                         0x4A8E80
#define CXStr__Mid_x                                               0x47D3A0
#define CXStr__Insert_x                                            0x90DBC0
#define CXStr__FindNext_x                                          0x90D830

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x95D6C0
#define CXWnd__BringToTop_x                                        0x942860
#define CXWnd__Center_x                                            0x9423E0
#define CXWnd__ClrFocus_x                                          0x942200
#define CXWnd__Destroy_x                                           0x9422A0
#define CXWnd__DoAllDrawing_x                                      0x93E810
#define CXWnd__DrawChildren_x                                      0x93E7E0
#define CXWnd__DrawColoredRect_x                                   0x93EC70
#define CXWnd__DrawTooltip_x                                       0x93D350
#define CXWnd__DrawTooltipAtPoint_x                                0x93D410
#define CXWnd__GetBorderFrame_x                                    0x93EAD0
#define CXWnd__GetChildWndAt_x                                     0x942900
#define CXWnd__GetClientClipRect_x                                 0x940A60
#define CXWnd__GetScreenClipRect_x                                 0x940B30
#define CXWnd__GetScreenRect_x                                     0x940CE0
#define CXWnd__GetRelativeRect_x                                   0x940DB0
#define CXWnd__GetTooltipRect_x                                    0x93ECC0
#define CXWnd__GetWindowTextA_x                                    0x49CAF0
#define CXWnd__IsActive_x                                          0x93F3E0
#define CXWnd__IsDescendantOf_x                                    0x941700
#define CXWnd__IsReallyVisible_x                                   0x941730
#define CXWnd__IsType_x                                            0x942F80
#define CXWnd__Move_x                                              0x9417A0
#define CXWnd__Move1_x                                             0x941860
#define CXWnd__ProcessTransition_x                                 0x942390
#define CXWnd__Refade_x                                            0x941B40
#define CXWnd__Resize_x                                            0x941E10
#define CXWnd__Right_x                                             0x942620
#define CXWnd__SetFocus_x                                          0x9421C0
#define CXWnd__SetFont_x                                           0x942230
#define CXWnd__SetKeyTooltip_x                                     0x942D90
#define CXWnd__SetMouseOver_x                                      0x93FC00
#define CXWnd__StartFade_x                                         0x9415E0
#define CXWnd__GetChildItem_x                                      0x942A70
#define CXWnd__SetParent_x                                         0x9414A0
#define CXWnd__Minimize_x                                          0x941E80

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9792B0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x9457A0
#define CXWndManager__DrawWindows_x                                0x9457C0
#define CXWndManager__GetKeyboardFlags_x                           0x947F40
#define CXWndManager__HandleKeyboardMsg_x                          0x947AF0
#define CXWndManager__RemoveWnd_x                                  0x948160
#define CXWndManager__RemovePendingDeletionWnd_x                   0x9486C0

// CDBStr
#define CDBStr__GetString_x                                        0x542930

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBC30
#define EQ_Character__Cur_HP_x                                     0x4D1DA0
#define EQ_Character__Cur_Mana_x                                   0x4D9500
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEC70
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B26D0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2820
#define EQ_Character__GetHPRegen_x                                 0x4DF2D0
#define EQ_Character__GetEnduranceRegen_x                          0x4DF8D0
#define EQ_Character__GetManaRegen_x                               0x4DFD10
#define EQ_Character__Max_Endurance_x                              0x6570E0
#define EQ_Character__Max_HP_x                                     0x4D1BD0
#define EQ_Character__Max_Mana_x                                   0x656EE0
#define EQ_Character__doCombatAbility_x                            0x659520
#define EQ_Character__UseSkill_x                                   0x4E1AF0
#define EQ_Character__GetConLevel_x                                0x650430
#define EQ_Character__IsExpansionFlag_x                            0x5B3E50
#define EQ_Character__TotalEffect_x                                0x4C4FC0
#define EQ_Character__GetPCSpellAffect_x                           0x4BF9C0
#define EQ_Character__SpellDuration_x                              0x4BF4F0
#define EQ_Character__GetAdjustedSkill_x                           0x4D4B20
#define EQ_Character__GetBaseSkill_x                               0x4D5AC0
#define EQ_Character__CanUseItem_x                                 0x4D9810

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8D7700

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x66D670

//PcClient
#define PcClient__PcClient_x                                       0x64DB80

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B98A0
#define CCharacterListWnd__EnterWorld_x                            0x4B92E0
#define CCharacterListWnd__Quit_x                                  0x4B9030
#define CCharacterListWnd__UpdateList_x                            0x4B9470

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x632350
#define EQ_Item__CreateItemTagString_x                             0x8B1C80
#define EQ_Item__IsStackable_x                                     0x8B6900
#define EQ_Item__GetImageNum_x                                     0x8B3730
#define EQ_Item__CreateItemClient_x                                0x631590
#define EQ_Item__GetItemValue_x                                    0x8B4B20
#define EQ_Item__ValueSellMerchant_x                               0x8B8280
#define EQ_Item__IsKeyRingItem_x                                   0x8B6220
#define EQ_Item__CanGoInBag_x                                      0x632470
#define EQ_Item__IsEmpty_x                                         0x8B5D50
#define EQ_Item__GetMaxItemCount_x                                 0x8B4F30
#define EQ_Item__GetHeldItem_x                                     0x8B3600
#define EQ_Item__GetAugmentFitBySlot_x                             0x8B14E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x561530
#define EQ_LoadingS__Array_x                                       0xC36C60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x657A20
#define EQ_PC__GetAlternateAbilityId_x                             0x8C1490
#define EQ_PC__GetCombatAbility_x                                  0x8C1B00
#define EQ_PC__GetCombatAbilityTimer_x                             0x8C1B70
#define EQ_PC__GetItemRecastTimer_x                                0x659AA0
#define EQ_PC__HasLoreItem_x                                       0x650BF0
#define EQ_PC__AlertInventoryChanged_x                             0x64FD70
#define EQ_PC__GetPcZoneClient_x                                   0x67C1A0
#define EQ_PC__RemoveMyAffect_x                                    0x65CCD0
#define EQ_PC__GetKeyRingItems_x                                   0x8C2400
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8C2190
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8C2700

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BA3A0
#define EQItemList__add_object_x                                   0x5E7C60
#define EQItemList__add_item_x                                     0x5BA900
#define EQItemList__delete_item_x                                  0x5BA950
#define EQItemList__FreeItemList_x                                 0x5BA850

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53F4C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x66EEF0
#define EQPlayer__dEQPlayer_x                                      0x6621F0
#define EQPlayer__DoAttack_x                                       0x676E30
#define EQPlayer__EQPlayer_x                                       0x6628B0
#define EQPlayer__SetNameSpriteState_x                             0x666BD0
#define EQPlayer__SetNameSpriteTint_x                              0x667AA0
#define PlayerBase__HasProperty_j_x                                0x9A7F50
#define EQPlayer__IsTargetable_x                                   0x9A83F0
#define EQPlayer__CanSee_x                                         0x9A8250
#define EQPlayer__CanSee1_x                                        0x9A8320
#define PlayerBase__GetVisibilityLineSegment_x                     0x9A8010

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x679C30
#define PlayerZoneClient__GetLevel_x                               0x67C1E0
#define PlayerZoneClient__IsValidTeleport_x                        0x5E8DD0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55A2B0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x671D40
#define EQPlayerManager__GetSpawnByName_x                          0x671DF0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x671E80

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6359E0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x635A60
#define KeypressHandler__AttachKeyToEqCommand_x                    0x635AA0
#define KeypressHandler__ClearCommandStateArray_x                  0x636EB0
#define KeypressHandler__HandleKeyDown_x                           0x636ED0
#define KeypressHandler__HandleKeyUp_x                             0x636F70
#define KeypressHandler__SaveKeymapping_x                          0x6373C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x78D520
#define MapViewMap__SaveEx_x                                       0x7908E0
#define MapViewMap__SetZoom_x                                      0x794FA0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8D5760

// StringTable 
#define StringTable__getString_x                                   0x8D0610

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x65C940
#define PcZoneClient__RemovePetEffect_x                            0x65CF70
#define PcZoneClient__HasAlternateAbility_x                        0x656D10
#define PcZoneClient__GetCurrentMod_x                              0x4E4BB0
#define PcZoneClient__GetModCap_x                                  0x4E4AB0
#define PcZoneClient__CanEquipItem_x                               0x6573C0
#define PcZoneClient__GetItemByID_x                                0x659F10
#define PcZoneClient__GetItemByItemClass_x                         0x65A060
#define PcZoneClient__RemoveBuffEffect_x                           0x65CF90
#define PcZoneClient__BandolierSwap_x                              0x657FE0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x659A40

//Doors
#define EQSwitch__UseSwitch_x                                      0x5ED870

//IconCache
#define IconCache__GetIcon_x                                       0x72EC40

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x726720
#define CContainerMgr__CloseContainer_x                            0x7269F0
#define CContainerMgr__OpenExperimentContainer_x                   0x727470

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7E5B10

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62A4E0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x783A80
#define CLootWnd__RequestLootSlot_x                                0x782CB0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x587900
#define EQ_Spell__SpellAffects_x                                   0x587D70
#define EQ_Spell__SpellAffectBase_x                                0x587B30
#define EQ_Spell__IsStackable_x                                    0x4C97D0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9650
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6BC0
#define EQ_Spell__IsSPAStacking_x                                  0x588BC0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5880D0
#define EQ_Spell__IsNoRemove_x                                     0x4C97B0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x588BD0
#define __IsResEffectSpell_x                                       0x4C8A00

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD130

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8DFD90

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x82CD10
#define CTargetWnd__WndNotification_x                              0x82C550
#define CTargetWnd__RefreshTargetBuffs_x                           0x82C820
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x82B6C0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x831350

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53CF00
#define CTaskManager__HandleMessage_x                              0x53B380
#define CTaskManager__GetTaskStatus_x                              0x53CFB0
#define CTaskManager__GetElementDescription_x                      0x53D030

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x582A50
#define EqSoundManager__PlayScriptMp3_x                            0x582D10
#define EqSoundManager__SoundAssistPlay_x                          0x6948C0
#define EqSoundManager__WaveInstancePlay_x                         0x693E30

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52E640

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x963CD0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5690E0
#define CAltAbilityData__GetMercMaxRank_x                          0x569070
#define CAltAbilityData__GetMaxRank_x                              0x55E480

//CTargetRing
#define CTargetRing__Cast_x                                        0x628600

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9630
#define CharacterBase__CreateItemGlobalIndex_x                     0x515BB0
#define CharacterBase__CreateItemIndex_x                           0x630740
#define CharacterBase__GetItemPossession_x                         0x501430
#define CharacterBase__GetItemByGlobalIndex_x                      0x8E83E0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8E8440
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x70D7B0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x70DFE0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x70E090

//messages
#define msg_spell_worn_off_x                                       0x5AC180
#define msg_new_text_x                                             0x5A0F80
#define __msgTokenTextParam_x                                      0x5AE6B0
#define msgTokenText_x                                             0x5AE900

//SpellManager
#define SpellManager__vftable_x                                    0xAFA290
#define SpellManager__SpellManager_x                               0x697BF0
#define Spellmanager__LoadTextSpells_x                             0x6984E0
#define SpellManager__GetSpellByGroupAndRank_x                     0x697DC0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9ABE90

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x516240
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B2350
#define ItemGlobalIndex__IsEquippedLocation_x                      0x649350
#define ItemGlobalIndex__IsValidIndex_x                            0x5162A0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8E0730
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8E09B0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x77C2F0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72AE40
#define CCursorAttachment__AttachToCursor1_x                       0x72AE80
#define CCursorAttachment__Deactivate_x                            0x72BE70

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x956950
#define CSidlManagerBase__CreatePageWnd_x                          0x956140
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9523C0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x952350

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x973A30
#define CEQSuiteTextureLoader__GetTexture_x                        0x9736F0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x513220
#define CFindItemWnd__WndNotification_x                            0x513D00
#define CFindItemWnd__Update_x                                     0x514870
#define CFindItemWnd__PickupSelectedItem_x                         0x512A70

//IString
#define IString__Append_x                                          0x4F2900

//Camera
#define CDisplay__cameraType_x                                     0xE1023C
#define EverQuest__Cameras_x                                       0xECB52C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51B920
#define LootFiltersManager__GetItemFilterData_x                    0x51B220
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51B250
#define LootFiltersManager__SetItemLootFilter_x                    0x51B470

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D38F0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B1A40
#define CResolutionHandler__GetWindowedStyle_x                     0x68F4A0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x7233D0

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8F5AF0
#define CDistillerInfo__Instance_x                                 0x8F5A90

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7424A0
#define CGroupWnd__UpdateDisplay_x                                 0x7417F0

//ItemBase
#define ItemBase__IsLore_x                                         0x8B62D0
#define ItemBase__IsLoreEquipped_x                                 0x8B6340

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5E7BC0
#define EQPlacedItemManager__GetItemByGuid_x                       0x5E7D00
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5E7D60

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6848D0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x688220

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x5095D0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F5B80
#define FactionManagerClient__HandleFactionMessage_x               0x4F61F0
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F67F0
#define FactionManagerClient__GetMaxFaction_x                      0x4F680F
#define FactionManagerClient__GetMinFaction_x                      0x4F67C0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x501400

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x93AEF0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE00

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x501710

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x568590

//CTargetManager
#define CTargetManager__Get_x                                      0x69B420

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6848D0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8E90

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BA7F0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF68BC0

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6D7100

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
