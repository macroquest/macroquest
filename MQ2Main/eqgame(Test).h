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
#define __ExpectedVersionDate                                     "Mar  2 2021"
#define __ExpectedVersionTime                                     "09:23:16"
#define __ActualVersionDate_x                                      0xB46EE4
#define __ActualVersionTime_x                                      0xB46ED8
#define __ActualVersionBuild_x                                     0xB370C4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x664CF0
#define __MemChecker1_x                                            0x945B40
#define __MemChecker2_x                                            0x6DEC30
#define __MemChecker3_x                                            0x6DEBA0
#define __MemChecker4_x                                            0x898F50
#define __EncryptPad0_x                                            0xE47F40
#define __EncryptPad1_x                                            0xEA2740
#define __EncryptPad2_x                                            0xE57158
#define __EncryptPad3_x                                            0xE56D58
#define __EncryptPad4_x                                            0xE93550
#define __EncryptPad5_x                                            0xF96020
#define __AC1_x                                                    0x853BA0
#define __AC2_x                                                    0x619BBF
#define __AC3_x                                                    0x620FA1
#define __AC4_x                                                    0x625110
#define __AC5_x                                                    0x62B9CF
#define __AC6_x                                                    0x630116
#define __AC7_x                                                    0x619620
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x24F588

// Direct Input
#define DI8__Main_x                                                0xF960CC
#define DI8__Keyboard_x                                            0xF960D0
#define DI8__Mouse_x                                               0xF9602C
#define DI8__Mouse_Copy_x                                          0xDA2D7C
#define DI8__Mouse_Check_x                                         0xF93B74
#define __AutoSkillArray_x                                         0xDA3C98
#define __Attack_x                                                 0xE41AC7
#define __Autofire_x                                               0xE41AC8
#define __BindList_x                                               0xD98448
#define g_eqCommandStates_x                                        0xD991B0
#define __Clicks_x                                                 0xDA2E34
#define __CommandList_x                                            0xD99D38
#define __CurrentMapLabel_x                                        0xFA6ACC
#define __CurrentSocial_x                                          0xC5346C
#define __DoAbilityList_x                                          0xDD95E8
#define __do_loot_x                                                0x5E2750
#define __DrawHandler_x                                            0x1615820
#define __GroupCount_x                                             0xF8913A
#define __Guilds_x                                                 0xF8D610
#define __gWorld_x                                                 0xF8934C
#define __HWnd_x                                                   0xF96030
#define __heqmain_x                                                0xF96008
#define __InChatMode_x                                             0xDA2D64
#define __LastTell_x                                               0xDA4CE4
#define __LMouseHeldTime_x                                         0xDA2EA0
#define __Mouse_x                                                  0xF960B8
#define __MouseLook_x                                              0xDA2DFA
#define __MouseEventTime_x                                         0xF8F03C
#define __gpbCommandEvent_x                                        0xF89458
#define __NetStatusToggle_x                                        0xDA2DFD
#define __PCNames_x                                                0xDA4294
#define __RangeAttackReady_x                                       0xDA3F7C
#define __RMouseHeldTime_x                                         0xDA2E9C
#define __RunWalkState_x                                           0xDA2D68
#define __ScreenMode_x                                             0xED545C
#define __ScreenX_x                                                0xDA2D1C
#define __ScreenY_x                                                0xDA2D18
#define __ScreenXMax_x                                             0xDA2D20
#define __ScreenYMax_x                                             0xDA2D24
#define __ServerHost_x                                             0xF89623
#define __ServerName_x                                             0xDD95A8
#define __ShiftKeyDown_x                                           0xDA33F8
#define __ShowNames_x                                              0xDA4138
#define EverQuestInfo__bSocialChanged_x                            0xDD9630
#define __Socials_x                                                0xDD96A8
#define __SubscriptionType_x                                       0xFDABA8
#define __TargetAggroHolder_x                                      0xFA9480
#define __ZoneType_x                                               0xDA31F8
#define __GroupAggro_x                                             0xFA94C0
#define __LoginName_x                                              0xF9679C
#define __Inviter_x                                                0xE41A44
#define __AttackOnAssist_x                                         0xDA40F4
#define __UseTellWindows_x                                         0xDA442C
#define __gfMaxZoomCameraDistance_x                                0xB3EDC4
#define __gfMaxCameraDistance_x                                    0xB67504
#define __pulAutoRun_x                                             0xDA2E18
#define __pulForward_x                                             0xDA4464
#define __pulBackward_x                                            0xDA4468
#define __pulTurnRight_x                                           0xDA446C
#define __pulTurnLeft_x                                            0xDA4470
#define __pulStrafeLeft_x                                          0xDA4474
#define __pulStrafeRight_x                                         0xDA4478

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF899A8
#define instEQZoneInfo_x                                           0xDA2FF0
#define pinstActiveBanker_x                                        0xF89944
#define pinstActiveCorpse_x                                        0xF8993C
#define pinstActiveGMaster_x                                       0xF89940
#define pinstActiveMerchant_x                                      0xF89938
#define pinstAltAdvManager_x                                       0xED62A0
#define pinstBandageTarget_x                                       0xF89954
#define pinstCamActor_x                                            0xED5450
#define pinstCDBStr_x                                              0xED5028
#define pinstCDisplay_x                                            0xF870B4
#define pinstCEverQuest_x                                          0xF96034
#define pinstEverQuestInfo_x                                       0xDA2D10
#define pinstCharData_x                                            0xF870A4
#define pinstCharSpawn_x                                           0xF8998C
#define pinstControlledMissile_x                                   0xF89998
#define pinstControlledPlayer_x                                    0xF8998C
#define pinstCResolutionHandler_x                                  0x1615A48
#define pinstCSidlManager_x                                        0x16149E4
#define pinstCXWndManager_x                                        0x16149DC
#define instDynamicZone_x                                          0xF8D4E8
#define pinstDZMember_x                                            0xF8D5F8
#define pinstDZTimerInfo_x                                         0xF8D5FC
#define pinstEqLogin_x                                             0xF960E8
#define instEQMisc_x                                               0xD8C8D8
#define pinstEQSoundManager_x                                      0xED6BB0
#define pinstEQSpellStrings_x                                      0xEC5CC8
#define instExpeditionLeader_x                                     0xF8D532
#define instExpeditionName_x                                       0xF8D572
#define pinstGroup_x                                               0xF89136
#define pinstImeManager_x                                          0x16149E0
#define pinstLocalPlayer_x                                         0xF89934
#define pinstMercenaryData_x                                       0xF90B34
#define pinstMercenaryStats_x                                      0xFA954C
#define pinstModelPlayer_x                                         0xF8994C
#define pinstPCData_x                                              0xF870A4
#define pinstSkillMgr_x                                            0xF92C20
#define pinstSpawnManager_x                                        0xF916F8
#define pinstSpellManager_x                                        0xF92E60
#define pinstSpellSets_x                                           0xE3A6F0
#define pinstStringTable_x                                         0xF870AC
#define pinstSwitchManager_x                                       0xF86F48
#define pinstTarget_x                                              0xF89988
#define pinstTargetObject_x                                        0xF8709C
#define pinstTargetSwitch_x                                        0xF870A0
#define pinstTaskMember_x                                          0xD8C420
#define pinstTrackTarget_x                                         0xF89990
#define pinstTradeTarget_x                                         0xF89948
#define instTributeActive_x                                        0xD8C8F9
#define pinstViewActor_x                                           0xED544C
#define pinstWorldData_x                                           0xF870B0
#define pinstZoneAddr_x                                            0xDA3290
#define pinstPlayerPath_x                                          0xF91790
#define pinstTargetIndicator_x                                     0xF930C8
#define EQObject_Top_x                                             0xF87098
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xED5490
#define pinstCAchievementsWnd_x                                    0xED5120
#define pinstCActionsWnd_x                                         0xED5420
#define pinstCAdvancedDisplayOptionsWindow_x                       0xED542C
#define pinstCAdvancedLootWnd_x                                    0xED5424
#define pinstCAdventureLeaderboardWnd_x                            0xFA02F0
#define pinstCAdventureRequestWnd_x                                0xFA03A0
#define pinstCAdventureStatsWnd_x                                  0xFA0450
#define pinstCAggroMeterWnd_x                                      0xED51A8
#define pinstCAlarmWnd_x                                           0xED5488
#define pinstCAlertHistoryWnd_x                                    0xED520C
#define pinstCAlertStackWnd_x                                      0xED51DC
#define pinstCAlertWnd_x                                           0xED51E0
#define pinstCAltStorageWnd_x                                      0xFA07B0
#define pinstCAudioTriggersWindow_x                                0xEB7FF8
#define pinstCAuraWnd_x                                            0xED5468
#define pinstCAvaZoneWnd_x                                         0xED5108
#define pinstCBandolierWnd_x                                       0xED5478
#define pinstCBankWnd_x                                            0xED51E8
#define pinstCBarterMerchantWnd_x                                  0xFA19F0
#define pinstCBarterSearchWnd_x                                    0xFA1AA0
#define pinstCBarterWnd_x                                          0xFA1B50
#define pinstCBazaarConfirmationWnd_x                              0xED54A8
#define pinstCBazaarSearchWnd_x                                    0xED5130
#define pinstCBazaarWnd_x                                          0xED50E8
#define pinstCBlockedBuffWnd_x                                     0xED516C
#define pinstCBlockedPetBuffWnd_x                                  0xED5174
#define pinstCBodyTintWnd_x                                        0xED54BC
#define pinstCBookWnd_x                                            0xED5200
#define pinstCBreathWnd_x                                          0xED5494
#define pinstCBuffWindowNORMAL_x                                   0xED5164
#define pinstCBuffWindowSHORT_x                                    0xED5168
#define pinstCBugReportWnd_x                                       0xED511C
#define pinstCButtonWnd_x                                          0x1614C48
#define pinstCCastingWnd_x                                         0xED51A4
#define pinstCCastSpellWnd_x                                       0xED51B4
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xED5148
#define pinstCChatWindowManager_x                                  0xFA25F8
#define pinstCClaimWnd_x                                           0xFA2750
#define pinstCColorPickerWnd_x                                     0xED515C
#define pinstCCombatAbilityWnd_x                                   0xED5438
#define pinstCCombatSkillsSelectWnd_x                              0xED543C
#define pinstCCompassWnd_x                                         0xED546C
#define pinstCConfirmationDialog_x                                 0xFA7618
#define pinstCContainerMgr_x                                       0xED549C
#define pinstCContextMenuManager_x                                 0x1614998
#define pinstCCursorAttachment_x                                   0xED519C
#define pinstCDynamicZoneWnd_x                                     0xFA2D18
#define pinstCEditLabelWnd_x                                       0xED50FC
#define pinstCEQMainWnd_x                                          0xFA2F60
#define pinstCEventCalendarWnd_x                                   0xED548C
#define pinstCExtendedTargetWnd_x                                  0xED51A0
#define pinstCPlayerCustomizationWnd_x                             0xED514C
#define pinstCFactionWnd_x                                         0xED51B0
#define pinstCFellowshipWnd_x                                      0xFA3160
#define pinstCFileSelectionWnd_x                                   0xED5444
#define pinstCFindItemWnd_x                                        0xED54C8
#define pinstCFindLocationWnd_x                                    0xFA32B8
#define pinstCFriendsWnd_x                                         0xED5440
#define pinstCGemsGameWnd_x                                        0xED5480
#define pinstCGiveWnd_x                                            0xED50F0
#define pinstCGroupSearchFiltersWnd_x                              0xED517C
#define pinstCGroupSearchWnd_x                                     0xFA36B0
#define pinstCGroupWnd_x                                           0xFA3760
#define pinstCGuildBankWnd_x                                       0xFA3810
#define pinstCGuildCreationWnd_x                                   0xFA38C0
#define pinstCGuildMgmtWnd_x                                       0xFA3970
#define pinstCharacterCreation_x                                   0xED5198
#define pinstCHelpWnd_x                                            0xED51D8
#define pinstCHeritageSelectionWnd_x                               0xED5150
#define pinstCHotButtonWnd_x                                       0xFA5AC8
#define pinstCHotButtonWnd1_x                                      0xFA5AC8
#define pinstCHotButtonWnd2_x                                      0xFA5ACC
#define pinstCHotButtonWnd3_x                                      0xFA5AD0
#define pinstCHotButtonWnd4_x                                      0xFA5AD4
#define pinstCIconSelectionWnd_x                                   0xED5118
#define pinstCInspectWnd_x                                         0xED5110
#define pinstCInventoryWnd_x                                       0xED51D4
#define pinstCInvSlotMgr_x                                         0xED5498
#define pinstCItemDisplayManager_x                                 0xFA6020
#define pinstCItemExpTransferWnd_x                                 0xFA6154
#define pinstCItemOverflowWnd_x                                    0xED50D0
#define pinstCJournalCatWnd_x                                      0xED54AC
//these are the same should probably rename to pinstCJournalNPCWnd at some point
#define pinstCJournalNPCWnd_x                                      0xED54A4
#define pinstCJournalTextWnd_x                                     0xED54A4
#define pinstCKeyRingWnd_x                                         0xED51E4
#define pinstCLargeDialogWnd_x                                     0xFA8298
#define pinstCLayoutCopyWnd_x                                      0xFA64A0
#define pinstCLFGuildWnd_x                                         0xFA6550
#define pinstCLoadskinWnd_x                                        0xED5484
#define pinstCLootFiltersCopyWnd_x                                 0xED4538
#define pinstCLootFiltersWnd_x                                     0xED54B0
#define pinstCLootSettingsWnd_x                                    0xED54B4
#define pinstCLootWnd_x                                            0xED5214
#define pinstCMailAddressBookWnd_x                                 0xED5140
#define pinstCMailCompositionWnd_x                                 0xED513C
#define pinstCMailIgnoreListWnd_x                                  0xED5144
#define pinstCMailWnd_x                                            0xED5138
#define pinstCManageLootWnd_x                                      0xED6720
#define pinstCMapToolbarWnd_x                                      0xED50F4
#define pinstCMapViewWnd_x                                         0xED50EC
#define pinstCMarketplaceWnd_x                                     0xED50D4
#define pinstCMerchantWnd_x                                        0xED50CC
#define pinstCMIZoneSelectWnd_x                                    0xFA6D88
#define pinstCMusicPlayerWnd_x                                     0xED547C
#define pinstCNameChangeMercWnd_x                                  0xED51CC
#define pinstCNameChangePetWnd_x                                   0xED51C8
#define pinstCNameChangeWnd_x                                      0xED5128
#define pinstCNoteWnd_x                                            0xED51D0
#define pinstCObjectPreviewWnd_x                                   0xED5134
#define pinstCOptionsWnd_x                                         0xED5160
#define pinstCOverseerWnd_x                                        0xED50C8
#define pinstCPetInfoWnd_x                                         0xED5418
#define pinstCPetitionQWnd_x                                       0xED5184
#define pinstCPlayerNotesWnd_x                                     0xED5474
#define pinstCPlayerWnd_x                                          0xED54CC
#define pinstCPopupWndManager_x                                    0xFA7618
#define pinstCProgressionSelectionWnd_x                            0xFA76C8
#define pinstCPurchaseGroupWnd_x                                   0xED50E0
#define pinstCPurchaseWnd_x                                        0xED50DC
#define pinstCPvPLeaderboardWnd_x                                  0xFA7778
#define pinstCPvPStatsWnd_x                                        0xFA7828
#define pinstCQuantityWnd_x                                        0xED51FC
#define pinstCRaceChangeWnd_x                                      0xED512C
#define pinstCRaidOptionsWnd_x                                     0xED51AC
#define pinstCRaidWnd_x                                            0xED51B8
#define pinstCRealEstateItemsWnd_x                                 0xED5158
#define pinstCRealEstateLayoutDetailsWnd_x                         0xED5194
#define pinstCRealEstateManageWnd_x                                0xED5180
#define pinstCRealEstateNeighborhoodWnd_x                          0xED5188
#define pinstCRealEstatePlotSearchWnd_x                            0xED518C
#define pinstCRealEstatePurchaseWnd_x                              0xED5190
#define pinstCRespawnWnd_x                                         0xED5470
#define pinstCRewardSelectionWnd_x                                 0xFA7F70
#define pinstCSelectorWnd_x                                        0xED50E4
#define pinstCSendMoneyWnd_x                                       0xED50F8
#define pinstCServerListWnd_x                                      0xED5448
#define pinstCSkillsSelectWnd_x                                    0xED5430
#define pinstCSkillsWnd_x                                          0xED5428
#define pinstCSocialEditWnd_x                                      0xED5114
#define pinstCSocialWnd_x                                          0xED54A0
#define pinstCSpellBookWnd_x                                       0xED51C4
#define pinstCStoryWnd_x                                           0xED54B8
#define pinstCTargetOfTargetWnd_x                                  0xFA95D0
#define pinstCTargetWnd_x                                          0xED510C
#define pinstCTaskOverlayWnd_x                                     0xED54C0
#define pinstCTaskSelectWnd_x                                      0xFA9728
#define pinstCTaskManager_x                                        0xC5E268
#define pinstCTaskTemplateSelectWnd_x                              0xFA97D8
#define pinstCTaskWnd_x                                            0xFA9888
#define pinstCTextEntryWnd_x                                       0xED5434
#define pinstCTimeLeftWnd_x                                        0xED5178
#define pinstCTipWndCONTEXT_x                                      0xFA9A8C
#define pinstCTipWndOFDAY_x                                        0xFA9A88
#define pinstCTitleWnd_x                                           0xFA9B38
#define pinstCTrackingWnd_x                                        0xED5100
#define pinstCTradeskillWnd_x                                      0xFA9CA0
#define pinstCTradeWnd_x                                           0xED50D8
#define pinstCTrainWnd_x                                           0xED541C
#define pinstCTributeBenefitWnd_x                                  0xFA9EA0
#define pinstCTributeMasterWnd_x                                   0xFA9F50
#define pinstCTributeTrophyWnd_x                                   0xFAA000
#define pinstCVideoModesWnd_x                                      0xED5124
#define pinstCVoiceMacroWnd_x                                      0xF934E0
#define pinstCVoteResultsWnd_x                                     0xED51C0
#define pinstCVoteWnd_x                                            0xED51BC
#define pinstCZoneGuideWnd_x                                       0xED51F8
#define pinstCZonePathWnd_x                                        0xED5204

#define pinstEQSuiteTextureLoader_x                                0xEA2D00
#define pinstItemIconCache_x                                       0xFA2F18
#define pinstLootFiltersManager_x                                  0xED45E8
#define pinstRewardSelectionWnd_x                                  0xFA7F70

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5DDA10
//it has no refs but we can possibly call it still 
#define __CastRay2_x                                               0x5DDCA0
#define __ConvertItemTags_x                                        0x5FAD10
#define __CleanItemTags_x                                          0x47DA70
#define __DoesFileExist_x                                          0x948AD0
#define __EQGetTime_x                                              0x9457B0
#define __ExecuteCmd_x                                             0x5D5E90
#define __FixHeading_x                                             0x9E2730
#define __FlushDxKeyboard_x                                        0x6D9F30
#define __GameLoop_x                                               0x6DD830
#define __get_bearing_x                                            0x5DD5B0
#define __get_melee_range_x                                        0x5DDEE0
#define __GetAnimationCache_x                                      0x74C410
#define __GetGaugeValueFromEQ_x                                    0x851FE0
#define __GetLabelFromEQ_x                                         0x853B20
#define __GetXTargetType_x                                         0x9E4AA0
#define __HandleMouseWheel_x                                       0x6DECC0
#define __HeadingDiff_x                                            0x9E2790
#define __HelpPath_x                                               0xF8ECFC
#define __ExecuteFrontEnd_x                                        0x6DA710
#define __NewUIINI_x                                               0x851CB0
#define __ProcessGameEvents_x                                      0x643DE0
#define __ProcessMouseEvent_x                                      0x6434E0
#define __SaveColors_x                                             0x570FD0
#define __STMLToText_x                                             0x980600
#define __ToggleKeyRingItem_x                                      0x52A790
#define CMemoryMappedFile__SetFile_x                               0xAD2ED0
#define CrashDetected_x                                            0x6DC440
#define DrawNetStatus_x                                            0x673230
#define Expansion_HoT_x                                            0xDA40E0
#define Teleport_Table_Size_x                                      0xF894E0
#define Teleport_Table_x                                           0xF870B8
#define Util__FastTime_x                                           0x945370
#define __CopyLayout_x                                             0x65FF80
#define __WndProc_x                                                0x6DC940
#define __ProcessKeyboardEvent_x                                   0x6DBE80

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4919C0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x49B1A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x49B020
#define CAdvancedLootWnd__AddPlayerToList_x                        0x495700
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x494940

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x579FD0
#define AltAdvManager__IsAbilityReady_x                            0x578BC0
#define AltAdvManager__GetAAById_x                                 0x578F60
#define AltAdvManager__CanTrainAbility_x                           0x578FD0
#define AltAdvManager__CanSeeAbility_x                             0x579360

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4D11A0
#define CharacterZoneClient__HasSkill_x                            0x4DC910
#define CharacterZoneClient__MakeMeVisible_x                       0x4DE050
#define CharacterZoneClient__IsStackBlocked_x                      0x4C85F0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4C0DB0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4E0F20
#define CharacterZoneClient__GetItemCountInInventory_x             0x4E1020
#define CharacterZoneClient__GetCursorItemCount_x                  0x4E1120
#define CharacterZoneClient__FindAffectSlot_x                      0x4CA830
#define CharacterZoneClient__BardCastBard_x                        0x4CD840
#define CharacterZoneClient__GetMaxEffects_x                       0x4C4CF0
#define CharacterZoneClient__GetEffect_x                           0x4C0CF0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4CBE40
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4CBEF0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4CBF90
#define CharacterZoneClient__CalcAffectChange_x                    0x4CC150
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4CC330
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B85C0
#define CharacterZoneClient__FindItemByGuid_x                      0x4DF1F0
#define CharacterZoneClient__FindItemByRecord_x                    0x4DEB40

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x707960
#define CBankWnd__WndNotification_x                                0x707700

//CBarterWnd
#define CBarterWnd__WndNotification_x                              0x712370

//CBarterSearchWnd
#define CBarterSearchWnd__WndNotification_x                        0x70CFD0
#define CBarterSearchWnd__UpdateInventoryList_x                    0x70AFA0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x7169A0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x97DBA0
#define CButtonWnd__CButtonWnd_x                                   0x97C550

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x739BB0
#define CChatManager__InitContextMenu_x                            0x732AA0
#define CChatManager__FreeChatWindow_x                             0x738780
#define CChatManager__SetLockedActiveChatWindow_x                  0x739890
#define CChatManager__CreateChatWindow_x                           0x738DB0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4F1F80

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x993940
#define CContextMenu__dCContextMenu_x                              0x993B80
#define CContextMenu__AddMenuItem_x                                0x993B90
#define CContextMenu__RemoveMenuItem_x                             0x993EA0
#define CContextMenu__RemoveAllMenuItems_x                         0x993EC0
#define CContextMenu__CheckMenuItem_x                              0x993F20
#define CContextMenu__SetMenuItem_x                                0x993DC0
#define CContextMenu__AddSeparator_x                               0x993D20

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x9944B0
#define CContextMenuManager__RemoveMenu_x                          0x994520
#define CContextMenuManager__PopupMenu_x                           0x9945E0
#define CContextMenuManager__Flush_x                               0x994450
#define CContextMenuManager__GetMenu_x                             0x49D4D0
#define CContextMenuManager__CreateDefaultMenu_x                   0x7463E0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8E9710
#define CChatService__GetFriendName_x                              0x91FEE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x73A510
#define CChatWindow__Clear_x                                       0x73B960
#define CChatWindow__WndNotification_x                             0x73C0E0
#define CChatWindow__AddHistory_x                                  0x73B1C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x990A10
#define CComboWnd__Draw_x                                          0x98FEB0
#define CComboWnd__GetCurChoice_x                                  0x9907E0
#define CComboWnd__GetListRect_x                                   0x990360
#define CComboWnd__GetTextRect_x                                   0x990A80
#define CComboWnd__InsertChoice_x                                  0x9904F0
#define CComboWnd__SetColors_x                                     0x9904C0
#define CComboWnd__SetChoice_x                                     0x9907C0
#define CComboWnd__GetItemCount_x                                  0x9907F0
#define CComboWnd__GetCurChoiceText_x                              0x990820
#define CComboWnd__GetChoiceText_x                                 0x990800
#define CComboWnd__InsertChoiceAtIndex_x                           0x990580

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x743A60
#define CContainerWnd__vftable_x                                   0xB50104
#define CContainerWnd__SetContainer_x                              0x7452A0

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x56BBA0
#define CDisplay__PreZoneMainUI_x                                  0x56BBB0
#define CDisplay__CleanGameUI_x                                    0x570DB0
#define CDisplay__GetClickedActor_x                                0x563A80
#define CDisplay__GetUserDefinedColor_x                            0x55B7F0
//well they inlined it in jan 25 2021 test but the function is still left in exe so for now we can probably just call it...
#define CDisplay__GetWorldFilePath_x                               0x565590
#define CDisplay__is3dON_x                                         0x560310
#define CDisplay__ReloadUI_x                                       0x56AEC0
#define CDisplay__WriteTextHD2_x                                   0x560100
#define CDisplay__TrueDistance_x                                   0x567460
#define CDisplay__SetViewActor_x                                   0x5633A0
#define CDisplay__GetFloorHeight_x                                 0x5603D0
#define CDisplay__SetRenderWindow_x                                0x55ED50
#define CDisplay__ToggleScreenshotMode_x                           0x562E70

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9B5F80

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x9973E0
#define CEditWnd__EnsureCaretVisible_x                             0x999730
#define CEditWnd__GetCaretPt_x                                     0x9985B0
#define CEditWnd__GetCharIndexPt_x                                 0x998360
#define CEditWnd__GetDisplayString_x                               0x998210
#define CEditWnd__GetHorzOffset_x                                  0x996980
#define CEditWnd__GetLineForPrintableChar_x                        0x999640
#define CEditWnd__GetSelStartPt_x                                  0x998610
#define CEditWnd__GetSTMLSafeText_x                                0x998020
#define CEditWnd__PointFromPrintableChar_x                         0x9992A0
#define CEditWnd__SelectableCharFromPoint_x                        0x999400
#define CEditWnd__SetEditable_x                                    0x9986E0
#define CEditWnd__SetWindowTextA_x                                 0x997D70
#define CEditWnd__ReplaceSelection_x                               0x998E60
#define CEditWnd__ReplaceSelection1_x                              0x998DE0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x62F790
#define CEverQuest__ClickedPlayer_x                                0x620D80
#define CEverQuest__CreateTargetIndicator_x                        0x640D60
#define CEverQuest__DeleteTargetIndicator_x                        0x640DF0
#define CEverQuest__DoTellWindow_x                                 0x4F2080
#define CEverQuest__OutputTextToLog_x                              0x4F2350
#define CEverQuest__DropHeldItemOnGround_x                         0x615D70
#define CEverQuest__dsp_chat_x                                     0x4F26E0
#define CEverQuest__trimName_x                                     0x63C560
#define CEverQuest__Emote_x                                        0x62FE50
#define CEverQuest__EnterZone_x                                    0x629B90
#define CEverQuest__GetBodyTypeDesc_x                              0x6352B0
#define CEverQuest__GetClassDesc_x                                 0x6358F0
#define CEverQuest__GetClassThreeLetterCode_x                      0x635EF0
#define CEverQuest__GetDeityDesc_x                                 0x63F510
#define CEverQuest__GetLangDesc_x                                  0x6360B0
#define CEverQuest__GetRaceDesc_x                                  0x6358D0
#define CEverQuest__InterpretCmd_x                                 0x63FB80
#define CEverQuest__LeftClickedOnPlayer_x                          0x61A2F0
#define CEverQuest__LMouseUp_x                                     0x618320
#define CEverQuest__RightClickedOnPlayer_x                         0x61AEE0
#define CEverQuest__RMouseUp_x                                     0x6195E0
#define CEverQuest__SetGameState_x                                 0x615AF0
#define CEverQuest__UPCNotificationFlush_x                         0x63C480
#define CEverQuest__IssuePetCommand_x                              0x6376B0
#define CEverQuest__ReportSuccessfulHit_x                          0x631760

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x757380
#define CGaugeWnd__CalcLinesFillRect_x                             0x7573E0
#define CGaugeWnd__Draw_x                                          0x756990

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B43E0
#define CGuild__GetGuildName_x                                     0x4B2C00
#define CGuild__GetGuildIndex_x                                    0x4B3320

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x774800

//CHotButton
#define CHotButton__SetCheck_x                                     0x6543D0
#define CHotButton__SetButtonSize_x                                0x654790

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7817A0
#define CInvSlotMgr__MoveItem_x                                    0x780380
#define CInvSlotMgr__SelectSlot_x                                  0x781860

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x77EBD0
#define CInvSlot__SliderComplete_x                                 0x77C0D0
#define CInvSlot__GetItemBase_x                                    0x77B9A0
#define CInvSlot__UpdateItem_x                                     0x77BB90

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7834A0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x782690
#define CInvSlotWnd__HandleLButtonUp_x                             0x783020

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x84C2E0
#define CItemDisplayWnd__UpdateStrings_x                           0x792530
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x78BF50
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x78C4C0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x792B20
#define CItemDisplayWnd__AboutToShow_x                             0x792180
#define CItemDisplayWnd__WndNotification_x                         0x794080
#define CItemDisplayWnd__RequestConvertItem_x                      0x793950
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7911A0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x791FA0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x8814F0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7989D0
#define CItemDisplayManager__ShowItem_x                            0x797FB0

// CLabel 
#define CLabel__UpdateText_x                                       0x79F0F0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9645A0
#define CListWnd__dCListWnd_x                                      0x9648A0
#define CListWnd__AddColumn_x                                      0x9692B0
#define CListWnd__AddColumn1_x                                     0x9693D0
#define CListWnd__AddLine_x                                        0x969740
#define CListWnd__AddString_x                                      0x969540
#define CListWnd__CalculateFirstVisibleLine_x                      0x969060
#define CListWnd__CalculateVSBRange_x                              0x968E40
#define CListWnd__ClearSel_x                                       0x96A030
#define CListWnd__ClearAllSel_x                                    0x96A080
#define CListWnd__CloseAndUpdateEditWindow_x                       0x96AB20
#define CListWnd__Compare_x                                        0x968780
#define CListWnd__Draw_x                                           0x964A60
#define CListWnd__DrawColumnSeparators_x                           0x967580
#define CListWnd__DrawHeader_x                                     0x9679E0
#define CListWnd__DrawItem_x                                       0x968020
#define CListWnd__DrawLine_x                                       0x9676F0
#define CListWnd__DrawSeparator_x                                  0x967620
#define CListWnd__EnableLine_x                                     0x966E40
#define CListWnd__EnsureVisible_x                                  0x96AA50
//no references in jan 25 2021 test exe we can probably still call it
#define CListWnd__ExtendSel_x                                      0x969F70
#define CListWnd__GetColumnTooltip_x                               0x9669C0
#define CListWnd__GetColumnMinWidth_x                              0x966A30
#define CListWnd__GetColumnWidth_x                                 0x966940
#define CListWnd__GetCurSel_x                                      0x9662F0
#define CListWnd__GetItemAtPoint_x                                 0x9670B0
//no references in jan 25 2021 test exe we can probably still call it
#define CListWnd__GetItemAtPoint1_x                                0x967120
#define CListWnd__GetItemData_x                                    0x966370
#define CListWnd__GetItemHeight_x                                  0x966710
#define CListWnd__GetItemIcon_x                                    0x9664F0
#define CListWnd__GetItemRect_x                                    0x966F30
#define CListWnd__GetItemText_x                                    0x9663B0
#define CListWnd__GetSelList_x                                     0x96A0D0
#define CListWnd__GetSeparatorRect_x                               0x967390
#define CListWnd__InsertLine_x                                     0x969BA0
#define CListWnd__RemoveLine_x                                     0x969DC0
#define CListWnd__SetColors_x                                      0x968E20
#define CListWnd__SetColumnJustification_x                         0x968B50
#define CListWnd__SetColumnLabel_x                                 0x9694E0
#define CListWnd__SetColumnWidth_x                                 0x968A60
#define CListWnd__SetCurSel_x                                      0x969EC0
#define CListWnd__SetItemColor_x                                   0x96A710
#define CListWnd__SetItemData_x                                    0x96A6D0
#define CListWnd__SetItemText_x                                    0x96A2F0
#define CListWnd__ShiftColumnSeparator_x                           0x968C10
#define CListWnd__Sort_x                                           0x968910
#define CListWnd__ToggleSel_x                                      0x969EF0
#define CListWnd__SetColumnsSizable_x                              0x968CB0
#define CListWnd__SetItemWnd_x                                     0x96A590
#define CListWnd__GetItemWnd_x                                     0x966540
#define CListWnd__SetItemIcon_x                                    0x96A370
#define CListWnd__CalculateCustomWindowPositions_x                 0x969160
#define CListWnd__SetVScrollPos_x                                  0x968A40

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7B6550
#define CMapViewWnd__GetWorldCoordinates_x                         0x7B4B70
#define CMapViewWnd__HandleLButtonDown_x                           0x7B1A00

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7D9720
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7DA080
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7DA6C0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7DD880
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7D81B0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7E39F0
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7D9370

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8ECFC0
#define CPacketScrambler__hton_x                                   0x8ECFB0

// CSidlManagerbase we should rename at some point
#define CSidlManager__FindAnimation1_x                             0x986C40
#define CSidlManager__FindScreenPieceTemplate_x                    0x987010
#define CSidlManager__FindScreenPieceTemplate1_x                   0x986E40
#define CSidlManager__CreateXWndFromTemplate_x                     0x98A4C0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x98A750
#define CSidlManagerbase__CreateXWnd_x                             0x98A790

//inlined since jan 25 2021 test but they left the function intact
#define CSidlManager__CreateHotButtonWnd_x                         0x842460
#define CSidlManager__CreateLabel_x                                0x842040

//CSidlManager
#define CSidlManager__CreateXWnd_x                                 0x841AC0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x982990
#define CSidlScreenWnd__CalculateVSBRange_x                        0x982890
#define CSidlScreenWnd__ConvertToRes_x                             0x9B01D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x982210
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x981F00
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x981FD0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9820A0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x983230
#define CSidlScreenWnd__EnableIniStorage_x                         0x983710
#define CSidlScreenWnd__GetSidlPiece_x                             0x983420
#define CSidlScreenWnd__Init1_x                                    0x9819D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x983760
#define CSidlScreenWnd__LoadIniListWnd_x                           0x984330
#define CSidlScreenWnd__LoadSidlScreen_x                           0x980DD0
#define CSidlScreenWnd__StoreIniInfo_x                             0x983EB0
#define CSidlScreenWnd__StoreIniVis_x                              0x984220
#define CSidlScreenWnd__WndNotification_x                          0x983100
#define CSidlScreenWnd__GetChildItem_x                             0x983690
#define CSidlScreenWnd__HandleLButtonUp_x                          0x971C40
#define CSidlScreenWnd__m_layoutCopy_x                             0x1614868

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6C1BF0
#define CSkillMgr__GetSkillCap_x                                   0x6C1DC0
#define CSkillMgr__GetNameToken_x                                  0x6C1430
#define CSkillMgr__IsActivatedSkill_x                              0x6C1520
#define CSkillMgr__IsCombatSkill_x                                 0x6C1490

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x995580
#define CSliderWnd__SetValue_x                                     0x9953B0
#define CSliderWnd__SetNumTicks_x                                  0x995410

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x848CC0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x99E8F0
#define CStmlWnd__ParseSTML_x                                      0x99FA90
#define CStmlWnd__CalculateHSBRange_x                              0x99F850
#define CStmlWnd__CalculateVSBRange_x                              0x99F7D0
#define CStmlWnd__CanBreakAtCharacter_x                            0x9A46C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x9A5360
#define CStmlWnd__ForceParseNow_x                                  0x99EE60
#define CStmlWnd__GetNextTagPiece_x                                0x9A4620
#define CStmlWnd__GetVisibleText_x                                 0x99EE80
#define CStmlWnd__InitializeWindowVariables_x                      0x9A51B0
#define CStmlWnd__MakeStmlColorTag_x                               0x99DF90
#define CStmlWnd__MakeWndNotificationTag_x                         0x99E000
#define CStmlWnd__SetSTMLText_x                                    0x99CD70
#define CStmlWnd__StripFirstSTMLLines_x                            0x9A6580
#define CStmlWnd__UpdateHistoryString_x                            0x9A5560

// CTabWnd 
#define CTabWnd__Draw_x                                            0x99BCC0
#define CTabWnd__DrawCurrentPage_x                                 0x99C650
#define CTabWnd__DrawTab_x                                         0x99C240
#define CTabWnd__GetCurrentPage_x                                  0x99B420
#define CTabWnd__GetPageInnerRect_x                                0x99B650
#define CTabWnd__GetTabInnerRect_x                                 0x99B590
#define CTabWnd__GetTabRect_x                                      0x99B450
#define CTabWnd__InsertPage_x                                      0x99B840
#define CTabWnd__RemovePage_x                                      0x99B990
#define CTabWnd__SetPage_x                                         0x99B6D0
//inlined but we can probably call it jan 25 2021
#define CTabWnd__SetPageRect_x                                     0x99C030
#define CTabWnd__UpdatePage_x                                      0x99C030
#define CTabWnd__GetPageFromTabIndex_x                             0x99C180
#define CTabWnd__GetCurrentTabIndex_x                              0x99B410

// CPageWnd
//inlined in Jan 25 2021 test
//#define CPageWnd__GetTabText_x                                     0x479340
#define CPageWnd__SetTabText_x                                     0x99ADE0
#define CPageWnd__FlashTab_x                                       0x99AE40

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4AC490

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x96E090
#define CTextureFont__GetTextExtent_x                              0x96E390

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9ACC80

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x95A050

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5441D0
#define CXStr__CXStr1_x                                            0x482740
#define CXStr__CXStr3_x                                            0x941700
#define CXStr__dCXStr_x                                            0x478F60
#define CXStr__operator_equal_x                                    0x941940
#define CXStr__operator_equal1_x                                   0x941980
#define CXStr__operator_plus_equal1_x                              0x9423E0
#define CXStr__SetString_x                                         0x944280
#define CXStr__operator_char_p_x                                   0x941E30
#define CXStr__GetChar_x                                           0x943BE0
#define CXStr__Delete_x                                            0x9434B0
#define CXStr__GetUnicode_x                                        0x943C50
#define CXStr__Insert_x                                            0x943CB0
#define CXStr__FindNext_x                                          0x943900
#define CXStr__Copy_x                                              0x9432C0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9935A0
#define CXWnd__BringToTop_x                                        0x9756F0
#define CXWnd__ClrFocus_x                                          0x975070
#define CXWnd__Destroy_x                                           0x975120
#define CXWnd__DoAllDrawing_x                                      0x9712C0
//inlined in jan 25 2021 we can probably still call it
#define CXWnd__DrawChildren_x                                      0x971290
#define CXWnd__DrawColoredRect_x                                   0x971840
#define CXWnd__DrawTooltip_x                                       0x96F7E0
#define CXWnd__DrawTooltipAtPoint_x                                0x96F8A0
#define CXWnd__GetBorderFrame_x                                    0x9714E0
#define CXWnd__GetChildWndAt_x                                     0x975790
#define CXWnd__GetClientClipRect_x                                 0x9738B0
#define CXWnd__GetScreenClipRect_x                                 0x973980
#define CXWnd__GetScreenRect_x                                     0x973B50
#define CXWnd__GetRelativeRect_x                                   0x973C10
#define CXWnd__GetTooltipRect_x                                    0x971890
#define CXWnd__GetWindowTextA_x                                    0x4F1F20
#define CXWnd__IsActive_x                                          0x971FC0
#define CXWnd__IsDescendantOf_x                                    0x9745C0
#define CXWnd__IsReallyVisible_x                                   0x9745F0
#define CXWnd__IsType_x                                            0x975F10
#define CXWnd__Move_x                                              0x974660
#define CXWnd__Move1_x                                             0x974760
#define CXWnd__ProcessTransition_x                                 0x975200
#define CXWnd__Refade_x                                            0x974A30
#define CXWnd__Resize_x                                            0x974CC0
#define CXWnd__Right_x                                             0x9754E0
#define CXWnd__SetFocus_x                                          0x975030
#define CXWnd__SetFont_x                                           0x9750A0
#define CXWnd__SetKeyTooltip_x                                     0x975CE0
#define CXWnd__SetMouseOver_x                                      0x972960
#define CXWnd__StartFade_x                                         0x9744B0
#define CXWnd__GetChildItem_x                                      0x975910
#define CXWnd__SetParent_x                                         0x9742E0
#define CXWnd__Minimize_x                                          0x974D20

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9B1220

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x978760
#define CXWndManager__DrawWindows_x                                0x9788B0
#define CXWndManager__GetKeyboardFlags_x                           0x97B180
#define CXWndManager__HandleKeyboardMsg_x                          0x97AD60
#define CXWndManager__RemoveWnd_x                                  0x97B450
#define CXWndManager__RemovePendingDeletionWnd_x                   0x97B910

// CDBStr
#define CDBStr__GetString_x                                        0x55A320

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4C5670
#define EQ_Character__Cur_HP_x                                     0x4D9580
#define EQ_Character__Cur_Mana_x                                   0x4E1650
#define EQ_Character__GetCastingTimeModifier_x                     0x4C8CE0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B81D0
#define EQ_Character__GetFocusRangeModifier_x                      0x4B8320
#define EQ_Character__GetHPRegen_x                                 0x4E8030
#define EQ_Character__GetEnduranceRegen_x                          0x4E85F0
#define EQ_Character__GetManaRegen_x                               0x4E8A30
#define EQ_Character__Max_Endurance_x                              0x682D80
#define EQ_Character__Max_HP_x                                     0x4D93B0
#define EQ_Character__Max_Mana_x                                   0x682B70
#define EQ_Character__doCombatAbility_x                            0x6856B0
#define EQ_Character__UseSkill_x                                   0x4EAA30
#define EQ_Character__GetConLevel_x                                0x67AE80
#define EQ_Character__IsExpansionFlag_x                            0x5D46D0
#define EQ_Character__TotalEffect_x                                0x4CD150
#define EQ_Character__GetPCSpellAffect_x                           0x4C9B10
#define EQ_Character__SpellDuration_x                              0x4C9550
#define EQ_Character__MySpellDuration_x                            0x4B6890
#define EQ_Character__GetAdjustedSkill_x                           0x4DC6D0
#define EQ_Character__GetBaseSkill_x                               0x4DD670
#define EQ_Character__CanUseItem_x                                 0x4E1980

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x90D360

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x69A7C0

//PcClient
#define PcClient__vftable_x                                        0xB43C5C
#define PcClient__PcClient_x                                       0x6780F0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BFC80
#define CCharacterListWnd__EnterWorld_x                            0x4BF650
#define CCharacterListWnd__Quit_x                                  0x4BF370
#define CCharacterListWnd__UpdateList_x                            0x4BF840

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x65A5A0
#define EQ_Item__CreateItemTagString_x                             0x8E5FC0
#define EQ_Item__IsStackable_x                                     0x8EB010
#define EQ_Item__GetImageNum_x                                     0x8E7CC0
#define EQ_Item__CreateItemClient_x                                0x659540
#define EQ_Item__GetItemValue_x                                    0x8E8F80
#define EQ_Item__ValueSellMerchant_x                               0x8ECCF0
#define EQ_Item__IsKeyRingItem_x                                   0x8EA7D0
#define EQ_Item__CanGoInBag_x                                      0x65A6C0
#define EQ_Item__IsEmpty_x                                         0x8EA290
#define EQ_Item__GetMaxItemCount_x                                 0x8E9390
#define EQ_Item__GetHeldItem_x                                     0x8E7B80
#define EQ_Item__CanGemFitInSlot_x                                 0x8E57A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x57ADD0
#define EQ_LoadingS__Array_x                                       0xD90D00

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x683870
#define EQ_PC__GetAlternateAbilityId_x                             0x8F6C50
#define EQ_PC__GetCombatAbility_x                                  0x8F71D0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8F7240
#define EQ_PC__GetItemRecastTimer_x                                0x685CB0
#define EQ_PC__HasLoreItem_x                                       0x67B840
#define EQ_PC__AlertInventoryChanged_x                             0x67A740
#define EQ_PC__GetPcZoneClient_x                                   0x6AAEA0
#define EQ_PC__RemoveMyAffect_x                                    0x6891D0
#define EQ_PC__GetKeyRingItems_x                                   0x8F7CD0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8F7830
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8F7E20

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5DAA80
#define EQItemList__add_object_x                                   0x60AC10
#define EQItemList__add_item_x                                     0x5DB060
#define EQItemList__delete_item_x                                  0x5DB0B0
#define EQItemList__FreeItemList_x                                 0x5DAFC0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x556440

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x69C1F0
#define EQPlayer__dEQPlayer_x                                      0x68EA80
#define EQPlayer__DoAttack_x                                       0x6A4BE0
#define EQPlayer__EQPlayer_x                                       0x68F2D0
#define EQPlayer__SetNameSpriteState_x                             0x6938A0
#define EQPlayer__SetNameSpriteTint_x                              0x694770
#define PlayerBase__HasProperty_j_x                                0x9E0B00
#define EQPlayer__IsTargetable_x                                   0x9E1060
#define EQPlayer__CanSee_x                                         0x9E0E50
#define EQPlayer__CanSee1_x                                        0x9E0F20
#define PlayerBase__GetVisibilityLineSegment_x                     0x9E0BC0

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6A89A0
#define PlayerZoneClient__GetLevel_x                               0x6AAEE0
#define PlayerZoneClient__IsValidTeleport_x                        0x60C0B0
#define PlayerZoneClient__LegalPlayerRace_x                        0x572D90

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x69F390
#define EQPlayerManager__GetSpawnByName_x                          0x69F440
#define EQPlayerManager__GetPlayerFromPartialName_x                0x69F4D0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x65DF40
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x65E010
#define KeypressHandler__AttachKeyToEqCommand_x                    0x65E050
#define KeypressHandler__ClearCommandStateArray_x                  0x65F510
#define KeypressHandler__HandleKeyDown_x                           0x65F530
#define KeypressHandler__HandleKeyUp_x                             0x65F5D0
#define KeypressHandler__SaveKeymapping_x                          0x65FB80

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7B2200
#define MapViewMap__SaveEx_x                                       0x7B573F
#define MapViewMap__SetZoom_x                                      0x7BB380

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x90B1F0

// StringTable 
#define StringTable__getString_x                                   0x9060D0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x688E20
#define PcZoneClient__RemovePetEffect_x                            0x689480
#define PcZoneClient__HasAlternateAbility_x                        0x6829D0
#define PcZoneClient__GetCurrentMod_x                              0x4EE1C0
#define PcZoneClient__GetModCap_x                                  0x4EE0C0
#define PcZoneClient__CanEquipItem_x                               0x683080
#define PcZoneClient__GetItemByID_x                                0x686180
#define PcZoneClient__GetItemByItemClass_x                         0x6862C0
#define PcZoneClient__RemoveBuffEffect_x                           0x689530
#define PcZoneClient__BandolierSwap_x                              0x683E20
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x685C50

//Doors
#define EQSwitch__UseSwitch_x                                      0x610C00

//IconCache
#define IconCache__GetIcon_x                                       0x74BDB0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x742970
#define CContainerMgr__CloseContainer_x                            0x742C50
#define CContainerMgr__OpenExperimentContainer_x                   0x7437B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x811640

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x652B50

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7A7410
#define CLootWnd__RequestLootSlot_x                                0x7A6650

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5A52B0
#define EQ_Spell__SpellAffects_x                                   0x5A57B0
#define EQ_Spell__SpellAffectBase_x                                0x5A54D0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4D0B40
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4D0AF0
#define EQ_Spell__IsSPAStacking_x                                  0x5A66C0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x5A5B10
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5A66D0
#define EQ_Spell__IsLullSpell_x                                    0x5A5F00
#define __IsResEffectSpell_x                                       0x4D02F0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4B11A0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x915C70

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x85DF00
#define CTargetWnd__WndNotification_x                              0x85D690
#define CTargetWnd__RefreshTargetBuffs_x                           0x85D9F0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x85C490

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x862A80
#define CTaskWnd__ConfirmAbandonTask_x                             0x865B50

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x554010
#define CTaskManager__HandleMessage_x                              0x551EF0
#define CTaskManager__GetTaskStatus_x                              0x5540C0
#define CTaskManager__GetElementDescription_x                      0x554140

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x59FEE0
#define EqSoundManager__PlayScriptMp3_x                            0x5A00E0
#define EqSoundManager__SoundAssistPlay_x                          0x6C60B0
#define EqSoundManager__WaveInstancePlay_x                         0x6C55A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x543E80

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x99A2A0
#define CTextureAnimation__Draw_x                                  0x99A4E0
#define CTextureAnimation__AddBlankFrame_x                         0x99A0C0

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x996060

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5833A0
#define CAltAbilityData__GetMercMaxRank_x                          0x583330
#define CAltAbilityData__GetMaxRank_x                              0x577740

//CTargetRing
#define CTargetRing__Cast_x                                        0x650360

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x659390
#define CharacterBase__CreateItemGlobalIndex_x                     0x646A50
//this is a guess testing is needed
#define CharacterBase__GetItemPossession_x                         0x659370
#define CharacterBase__GetItemByGlobalIndex_x                      0x91D7E0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x91D830
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x727830
#define CCastSpellWnd__IsBardSongPlaying_x                         0x7280F0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x7281A0

//messages
#define msg_spell_worn_off_x                                       0x5CC020
#define msg_new_text_x                                             0x5BFE20
#define __msgTokenTextParam_x                                      0x5CE490
#define msgTokenText_x                                             0x5CE8A0

//SpellManager
#define SpellManager__vftable_x                                    0xB2E2FC
#define SpellManager__SpellManager_x                               0x6C9CE0
#define Spellmanager__LoadTextSpells_x                             0x6CA5E0
#define SpellManager__GetSpellByGroupAndRank_x                     0x6C9EB0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9E5350

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5D4720
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5D2C00
#define ItemGlobalIndex__IsEquippedLocation_x                      0x672FD0
#define ItemGlobalIndex__IsValidIndex_x                            0x5D48B0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x916670
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x9169C0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x79F560

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x747660
#define CCursorAttachment__AttachToCursor1_x                       0x7476A0
#define CCursorAttachment__Deactivate_x                            0x748C30

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x98BCD0
#define CSidlManagerBase__CreatePageWnd_x                          0x98B4D0
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9869C0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x986950

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x9AB850
#define CEQSuiteTextureLoader__GetTexture_x                        0x9AB4D0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x524160
#define CFindItemWnd__WndNotification_x                            0x525020
#define CFindItemWnd__Update_x                                     0x525BE0
#define CFindItemWnd__PickupSelectedItem_x                         0x523860

//IString
#define IString__Append_x                                          0x5134B0

//Camera
#define CDisplay__cameraType_x                                     0xED5210
#define EverQuest__Cameras_x                                       0xDA4438

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x52ECD0
#define LootFiltersManager__GetItemFilterData_x                    0x52E610
#define LootFiltersManager__RemoveItemLootFilter_x                 0x52E640
#define LootFiltersManager__SetItemLootFilter_x                    0x52E850

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7FE130

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9EB020
#define CResolutionHandler__GetWindowedStyle_x                     0x6C0530

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x73F300

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x921B30
#define CDistillerInfo__Instance_x                                 0x921A70

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x761FB0
#define CGroupWnd__UpdateDisplay_x                                 0x761200

//ItemBase
#define ItemBase__IsLore_x                                         0x8EA870
#define ItemBase__IsLoreEquipped_x                                 0x8EA8F0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x60AB70
#define EQPlacedItemManager__GetItemByGuid_x                       0x60ACB0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x60AD10

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6B4C70
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6B9550

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x519C50

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x504A10
#define FactionManagerClient__HandleFactionMessage_x               0x505230
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x505A50
#define FactionManagerClient__GetMaxFaction_x                      0x505A6F
#define FactionManagerClient__GetMinFaction_x                      0x505A20

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x511640

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x96CD20

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49DEF0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x5118B0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x582550

//CTargetManager
#define CTargetManager__Get_x                                      0x6CDC60

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x6B4C70

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4AC250

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5DAF60

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xE41ACC

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6EB390
#define CAAWnd__UpdateSelected_x                                   0x6E7A30
#define CAAWnd__Update_x                                           0x6EA6C0

//CXRect
#define CXRect__operator_and_x                                     0x757440

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x47D230

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
//static PBYTE efPattern = (PBYTE)"\xE8\x00\x00\x00\x00\x83\xC4\x08\x89\x45\xA0";
//static char efMask[] = "x????xxxxxx";
//Jan 25 2021 Test
//E8 ? ? ? ? 8B D8 53
static PBYTE efPattern = (PBYTE)"\xE8\x00\x00\x00\x00\x8B\xD8\x53";
static char efMask[] = "x????xxx";

