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
#define __ExpectedVersionDate                                     "Oct 29 2019"
#define __ExpectedVersionTime                                     "04:22:07"
#define __ActualVersionDate_x                                      0xB02E50
#define __ActualVersionTime_x                                      0xB02E44
#define __ActualVersionBuild_x                                     0xAEEAEC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62A460
#define __MemChecker1_x                                            0x8FCCE0
#define __MemChecker2_x                                            0x6B8D30
#define __MemChecker3_x                                            0x6B8C80
#define __MemChecker4_x                                            0x854940
#define __EncryptPad0_x                                            0xC383E8
#define __EncryptPad1_x                                            0xC965A8
#define __EncryptPad2_x                                            0xC48C80
#define __EncryptPad3_x                                            0xC48880
#define __EncryptPad4_x                                            0xC86C00
#define __EncryptPad5_x                                            0xF5FCF4
#define __AC1_x                                                    0x8116E6
#define __AC2_x                                                    0x5E421F
#define __AC3_x                                                    0x5EB91F
#define __AC4_x                                                    0x5EF8F0
#define __AC5_x                                                    0x5F5BFF
#define __AC6_x                                                    0x5FA216
#define __AC7_x                                                    0x5E3C90
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1AE728

// Direct Input
#define DI8__Main_x                                                0xF621D0
#define DI8__Keyboard_x                                            0xF621D4
#define DI8__Mouse_x                                               0xF621E8
#define DI8__Mouse_Copy_x                                          0xEBB3BC
#define DI8__Mouse_Check_x                                         0xF5FD1C
#define __AutoSkillArray_x                                         0xEBC2D4
#define __Attack_x                                                 0xF5A0FB
#define __Autofire_x                                               0xF5A0FC
#define __BindList_x                                               0xC26E20
#define g_eqCommandStates_x                                        0xC27BA0
#define __Clicks_x                                                 0xEBB474
#define __CommandList_x                                            0xC28760
#define __CurrentMapLabel_x                                        0xF72B7C
#define __CurrentSocial_x                                          0xC107CC
#define __DoAbilityList_x                                          0xEF1C1C
#define __do_loot_x                                                0x5B0520
#define __DrawHandler_x                                            0x15F1EF0
#define __GroupCount_x                                             0xEADC82
#define __Guilds_x                                                 0xEB1BC8
#define __gWorld_x                                                 0xEADB4C
#define __HWnd_x                                                   0xF621EC
#define __heqmain_x                                                0xF621C4
#define __InChatMode_x                                             0xEBB3A4
#define __LastTell_x                                               0xEBD318
#define __LMouseHeldTime_x                                         0xEBB4E0
#define __Mouse_x                                                  0xF621B0
#define __MouseLook_x                                              0xEBB43A
#define __MouseEventTime_x                                         0xF5ABDC
#define __gpbCommandEvent_x                                        0xEADE74
#define __NetStatusToggle_x                                        0xEBB43D
#define __PCNames_x                                                0xEBC8C4
#define __RangeAttackReady_x                                       0xEBC5B8
#define __RMouseHeldTime_x                                         0xEBB4DC
#define __RunWalkState_x                                           0xEBB3A8
#define __ScreenMode_x                                             0xDF9488
#define __ScreenX_x                                                0xEBB35C
#define __ScreenY_x                                                0xEBB358
#define __ScreenXMax_x                                             0xEBB360
#define __ScreenYMax_x                                             0xEBB364
#define __ServerHost_x                                             0xEAB79B
#define __ServerName_x                                             0xEF1BDC
#define __ShiftKeyDown_x                                           0xEBBA34
#define __ShowNames_x                                              0xEBC774
#define __Socials_x                                                0xEF1CDC
#define __SubscriptionType_x                                       0xFB7080
#define __TargetAggroHolder_x                                      0xF75530
#define __ZoneType_x                                               0xEBB838
#define __GroupAggro_x                                             0xF75570
#define __LoginName_x                                              0xF6292C
#define __Inviter_x                                                0xF5A078
#define __AttackOnAssist_x                                         0xEBC730
#define __UseTellWindows_x                                         0xEBCA60
#define __gfMaxZoomCameraDistance_x                                0xAF8760
#define __gfMaxCameraDistance_x                                    0xB24CB0
#define __pulAutoRun_x                                             0xEBB458
#define __pulForward_x                                             0xEBCA98
#define __pulBackward_x                                            0xEBCA9C
#define __pulTurnRight_x                                           0xEBCAA0
#define __pulTurnLeft_x                                            0xEBCAA4
#define __pulStrafeLeft_x                                          0xEBCAA8
#define __pulStrafeRight_x                                         0xEBCAAC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEADF60
#define instEQZoneInfo_x                                           0xEBB630
#define pinstActiveBanker_x                                        0xEADE8C
#define pinstActiveCorpse_x                                        0xEADE84
#define pinstActiveGMaster_x                                       0xEADE88
#define pinstActiveMerchant_x                                      0xEADE80
#define pinstAltAdvManager_x                                       0xDFA190
#define pinstBandageTarget_x                                       0xEADE9C
#define pinstCamActor_x                                            0xDF9478
#define pinstCDBStr_x                                              0xDF8EAC
#define pinstCDisplay_x                                            0xEADB30
#define pinstCEverQuest_x                                          0xF621F0
#define pinstEverQuestInfo_x                                       0xEBB350
#define pinstCharData_x                                            0xEADC60
#define pinstCharSpawn_x                                           0xEADF54
#define pinstControlledMissile_x                                   0xEABAAC
#define pinstControlledPlayer_x                                    0xEADF54
#define pinstCResolutionHandler_x                                  0x15F2120
#define pinstCSidlManager_x                                        0x15F10B8
#define pinstCXWndManager_x                                        0x15F10B4
#define instDynamicZone_x                                          0xEB1AA0
#define pinstDZMember_x                                            0xEB1BB0
#define pinstDZTimerInfo_x                                         0xEB1BB4
#define pinstEqLogin_x                                             0xF62278
#define instEQMisc_x                                               0xDF8DF0
#define pinstEQSoundManager_x                                      0xDFB160
#define pinstEQSpellStrings_x                                      0xCBB868
#define instExpeditionLeader_x                                     0xEB1AEA
#define instExpeditionName_x                                       0xEB1B2A
#define pinstGroup_x                                               0xEADC7E
#define pinstImeManager_x                                          0x15F10B0
#define pinstLocalPlayer_x                                         0xEADE7C
#define pinstMercenaryData_x                                       0xF5C6CC
#define pinstMercenaryStats_x                                      0xF7567C
#define pinstModelPlayer_x                                         0xEADE94
#define pinstPCData_x                                              0xEADC60
#define pinstSkillMgr_x                                            0xF5E838
#define pinstSpawnManager_x                                        0xF5D2E0
#define pinstSpellManager_x                                        0xF5EA58
#define pinstSpellSets_x                                           0xF52D24
#define pinstStringTable_x                                         0xEADC64
#define pinstSwitchManager_x                                       0xEAB500
#define pinstTarget_x                                              0xEADF50
#define pinstTargetObject_x                                        0xEAB650
#define pinstTargetSwitch_x                                        0xEADAD4
#define pinstTaskMember_x                                          0xDF8C80
#define pinstTrackTarget_x                                         0xEADF58
#define pinstTradeTarget_x                                         0xEADE90
#define instTributeActive_x                                        0xDF8E11
#define pinstViewActor_x                                           0xDF9474
#define pinstWorldData_x                                           0xEADAD0
#define pinstZoneAddr_x                                            0xEBB8D0
#define pinstPlayerPath_x                                          0xF5D378
#define pinstTargetIndicator_x                                     0xF5ECC0
#define EQObject_Top_x                                             0xEADE78
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDF973C
#define pinstCAchievementsWnd_x                                    0xDF94D4
#define pinstCActionsWnd_x                                         0xDF9500
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDF8F74
#define pinstCAdvancedLootWnd_x                                    0xDF97DC
#define pinstCAdventureLeaderboardWnd_x                            0xF6C350
#define pinstCAdventureRequestWnd_x                                0xF6C400
#define pinstCAdventureStatsWnd_x                                  0xF6C4B0
#define pinstCAggroMeterWnd_x                                      0xDF946C
#define pinstCAlarmWnd_x                                           0xDF97A0
#define pinstCAlertHistoryWnd_x                                    0xDF97D4
#define pinstCAlertStackWnd_x                                      0xDF9750
#define pinstCAlertWnd_x                                           0xDF9764
#define pinstCAltStorageWnd_x                                      0xF6C810
#define pinstCAudioTriggersWindow_x                                0xCADB98
#define pinstCAuraWnd_x                                            0xDF8FC8
#define pinstCAvaZoneWnd_x                                         0xDF8F4C
#define pinstCBandolierWnd_x                                       0xDF9468
#define pinstCBankWnd_x                                            0xDF8FC4
#define pinstCBarterMerchantWnd_x                                  0xF6DA50
#define pinstCBarterSearchWnd_x                                    0xF6DB00
#define pinstCBarterWnd_x                                          0xF6DBB0
#define pinstCBazaarConfirmationWnd_x                              0xDF9510
#define pinstCBazaarSearchWnd_x                                    0xDF94C8
#define pinstCBazaarWnd_x                                          0xDF978C
#define pinstCBlockedBuffWnd_x                                     0xDF8FCC
#define pinstCBlockedPetBuffWnd_x                                  0xDF8FFC
#define pinstCBodyTintWnd_x                                        0xDF9514
#define pinstCBookWnd_x                                            0xDF94A8
#define pinstCBreathWnd_x                                          0xDF975C
#define pinstCBuffWindowNORMAL_x                                   0xDF8F90
#define pinstCBuffWindowSHORT_x                                    0xDF8F98
#define pinstCBugReportWnd_x                                       0xDF8FA0
#define pinstCButtonWnd_x                                          0x15F1320
#define pinstCCastingWnd_x                                         0xDF9498
#define pinstCCastSpellWnd_x                                       0xDF9754
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDF9790
#define pinstCChatWindowManager_x                                  0xF6E670
#define pinstCClaimWnd_x                                           0xF6E7C8
#define pinstCColorPickerWnd_x                                     0xDF9508
#define pinstCCombatAbilityWnd_x                                   0xDF979C
#define pinstCCombatSkillsSelectWnd_x                              0xDF97BC
#define pinstCCompassWnd_x                                         0xDF9504
#define pinstCConfirmationDialog_x                                 0xF736C8
#define pinstCContainerMgr_x                                       0xDF9784
#define pinstCContextMenuManager_x                                 0x15F1070
#define pinstCCursorAttachment_x                                   0xDF947C
#define pinstCDynamicZoneWnd_x                                     0xF6ED90
#define pinstCEditLabelWnd_x                                       0xDF8F84
#define pinstCEQMainWnd_x                                          0xF6EFD8
#define pinstCEventCalendarWnd_x                                   0xDF8F8C
#define pinstCExtendedTargetWnd_x                                  0xDF8FE0
#define pinstCFacePick_x                                           0xDF97CC
#define pinstCFactionWnd_x                                         0xDF977C
#define pinstCFellowshipWnd_x                                      0xF6F1D8
#define pinstCFileSelectionWnd_x                                   0xDF9494
#define pinstCFindItemWnd_x                                        0xDF9770
#define pinstCFindLocationWnd_x                                    0xF6F330
#define pinstCFriendsWnd_x                                         0xDF97D8
#define pinstCGemsGameWnd_x                                        0xDF9778
#define pinstCGiveWnd_x                                            0xDF97A4
#define pinstCGroupSearchFiltersWnd_x                              0xDF94A0
#define pinstCGroupSearchWnd_x                                     0xF6F728
#define pinstCGroupWnd_x                                           0xF6F7D8
#define pinstCGuildBankWnd_x                                       0xEBC714
#define pinstCGuildCreationWnd_x                                   0xF6F938
#define pinstCGuildMgmtWnd_x                                       0xF6F9E8
#define pinstCharacterCreation_x                                   0xDF97C4
#define pinstCHelpWnd_x                                            0xDF8F6C
#define pinstCHeritageSelectionWnd_x                               0xDF97E0
#define pinstCHotButtonWnd_x                                       0xF71B40
#define pinstCHotButtonWnd1_x                                      0xF71B40
#define pinstCHotButtonWnd2_x                                      0xF71B44
#define pinstCHotButtonWnd3_x                                      0xF71B48
#define pinstCHotButtonWnd4_x                                      0xF71B4C
#define pinstCIconSelectionWnd_x                                   0xDF9470
#define pinstCInspectWnd_x                                         0xDF8F68
#define pinstCInventoryWnd_x                                       0xDF8F48
#define pinstCInvSlotMgr_x                                         0xDF9738
#define pinstCItemDisplayManager_x                                 0xF720D0
#define pinstCItemExpTransferWnd_x                                 0xF72200
#define pinstCItemOverflowWnd_x                                    0xDF94D0
#define pinstCJournalCatWnd_x                                      0xDF94B0
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDF8FE4
#define pinstCKeyRingWnd_x                                         0xDF8F80
#define pinstCLargeDialogWnd_x                                     0xF74348
#define pinstCLayoutCopyWnd_x                                      0xF72550
#define pinstCLFGuildWnd_x                                         0xF72600
#define pinstCLoadskinWnd_x                                        0xDF9788
#define pinstCLootFiltersCopyWnd_x                                 0xCCA188
#define pinstCLootFiltersWnd_x                                     0xDF9758
#define pinstCLootSettingsWnd_x                                    0xDF976C
#define pinstCLootWnd_x                                            0xDF94B4
#define pinstCMailAddressBookWnd_x                                 0xDF9744
#define pinstCMailCompositionWnd_x                                 0xDF9528
#define pinstCMailIgnoreListWnd_x                                  0xDF9748
#define pinstCMailWnd_x                                            0xDF94FC
#define pinstCManageLootWnd_x                                      0xDFA640
#define pinstCMapToolbarWnd_x                                      0xDF8F70
#define pinstCMapViewWnd_x                                         0xDF8F58
#define pinstCMarketplaceWnd_x                                     0xDF9760
#define pinstCMerchantWnd_x                                        0xDF94B8
#define pinstCMIZoneSelectWnd_x                                    0xF72E38
#define pinstCMusicPlayerWnd_x                                     0xDF94C0
#define pinstCNameChangeMercWnd_x                                  0xDF94F8
#define pinstCNameChangePetWnd_x                                   0xDF94D8
#define pinstCNameChangeWnd_x                                      0xDF9520
#define pinstCNoteWnd_x                                            0xDF8F5C
#define pinstCObjectPreviewWnd_x                                   0xDF9768
#define pinstCOptionsWnd_x                                         0xDF8F60
#define pinstCPetInfoWnd_x                                         0xDF94DC
#define pinstCPetitionQWnd_x                                       0xDF94C4
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDF9518
#define pinstCPlayerWnd_x                                          0xDF94E0
#define pinstCPopupWndManager_x                                    0xF736C8
#define pinstCProgressionSelectionWnd_x                            0xF73778
#define pinstCPurchaseGroupWnd_x                                   0xDF97AC
#define pinstCPurchaseWnd_x                                        0xDF9780
#define pinstCPvPLeaderboardWnd_x                                  0xF73828
#define pinstCPvPStatsWnd_x                                        0xF738D8
#define pinstCQuantityWnd_x                                        0xDF8FE8
#define pinstCRaceChangeWnd_x                                      0xDF9740
#define pinstCRaidOptionsWnd_x                                     0xDF94A4
#define pinstCRaidWnd_x                                            0xDF9530
#define pinstCRealEstateItemsWnd_x                                 0xDF94CC
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDF8FD4
#define pinstCRealEstateManageWnd_x                                0xDF97B4
#define pinstCRealEstateNeighborhoodWnd_x                          0xDF97D0
#define pinstCRealEstatePlotSearchWnd_x                            0xDF8F50
#define pinstCRealEstatePurchaseWnd_x                              0xDF8F64
#define pinstCRespawnWnd_x                                         0xDF8FD8
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDF974C
#define pinstCSendMoneyWnd_x                                       0xDF97B8
#define pinstCServerListWnd_x                                      0xDF8F88
#define pinstCSkillsSelectWnd_x                                    0xDF9794
#define pinstCSkillsWnd_x                                          0xDF9774
#define pinstCSocialEditWnd_x                                      0xDF8F7C
#define pinstCSocialWnd_x                                          0xDF94F4
#define pinstCSpellBookWnd_x                                       0xDF9798
#define pinstCStoryWnd_x                                           0xDF94E4
#define pinstCTargetOfTargetWnd_x                                  0xF75700
#define pinstCTargetWnd_x                                          0xDF8FD0
#define pinstCTaskOverlayWnd_x                                     0xDF97A8
#define pinstCTaskSelectWnd_x                                      0xF75858
#define pinstCTaskManager_x                                        0xCCAAC8
#define pinstCTaskTemplateSelectWnd_x                              0xF75908
#define pinstCTaskWnd_x                                            0xF759B8
#define pinstCTextEntryWnd_x                                       0xDF8F9C
#define pinstCTimeLeftWnd_x                                        0xDF949C
#define pinstCTipWndCONTEXT_x                                      0xF75BBC
#define pinstCTipWndOFDAY_x                                        0xF75BB8
#define pinstCTitleWnd_x                                           0xF75C68
#define pinstCTrackingWnd_x                                        0xDF8F54
#define pinstCTradeskillWnd_x                                      0xF75DD0
#define pinstCTradeWnd_x                                           0xDF9524
#define pinstCTrainWnd_x                                           0xDF951C
#define pinstCTributeBenefitWnd_x                                  0xF75FD0
#define pinstCTributeMasterWnd_x                                   0xF76080
#define pinstCTributeTrophyWnd_x                                   0xF76130
#define pinstCVideoModesWnd_x                                      0xDF952C
#define pinstCVoiceMacroWnd_x                                      0xF5F428
#define pinstCVoteResultsWnd_x                                     0xDF94BC
#define pinstCVoteWnd_x                                            0xDF94AC
#define pinstCWebManager_x                                         0xF5FAA4
#define pinstCZoneGuideWnd_x                                       0xDF97B0
#define pinstCZonePathWnd_x                                        0xDF97C0

#define pinstEQSuiteTextureLoader_x                                0xC98080
#define pinstItemIconCache_x                                       0xF6EF90
#define pinstLootFiltersManager_x                                  0xCCA238
#define pinstRewardSelectionWnd_x                                  0xF74020

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5AB980
#define __CastRay2_x                                               0x5AB9D0
#define __ConvertItemTags_x                                        0x5C7510
#define __CleanItemTags_x                                          0x47D1A0
#define __DoesFileExist_x                                          0x8FFDC0
#define __EQGetTime_x                                              0x8FC7B0
#define __ExecuteCmd_x                                             0x5A4250
#define __FixHeading_x                                             0x9969C0
#define __GameLoop_x                                               0x6B7F20
#define __get_bearing_x                                            0x5AB4F0
#define __get_melee_range_x                                        0x5ABBC0
#define __GetAnimationCache_x                                      0x71D220
#define __GetGaugeValueFromEQ_x                                    0x80FB90
#define __GetLabelFromEQ_x                                         0x811670
#define __GetXTargetType_x                                         0x9983A0
#define __HandleMouseWheel_x                                       0x6B8DE0
#define __HeadingDiff_x                                            0x996A30
#define __HelpPath_x                                               0xF5A7CC
#define __LoadFrontEnd_x                                           0x6B5240
#define __NewUIINI_x                                               0x80F860
#define __ProcessGameEvents_x                                      0x60BA90
#define __ProcessMouseEvent_x                                      0x60B250
#define __SaveColors_x                                             0x54FBC0
#define __STMLToText_x                                             0x93A030
#define __ToggleKeyRingItem_x                                      0x513560
#define CMemoryMappedFile__SetFile_x                               0xA85BD0
#define CrashDetected_x                                            0x6B6CE0
#define DrawNetStatus_x                                            0x637A10
#define Expansion_HoT_x                                            0xEBC71C
#define Teleport_Table_Size_x                                      0xEAB658
#define Teleport_Table_x                                           0xEABAD0
#define Util__FastTime_x                                           0x8FC380

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4903A0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x4992B0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499080
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493940
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D90

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x5576F0
#define AltAdvManager__IsAbilityReady_x                            0x556620
#define AltAdvManager__GetAAById_x                                 0x556820
#define AltAdvManager__CanTrainAbility_x                           0x556890
#define AltAdvManager__CanSeeAbility_x                             0x556BF0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA3B0
#define CharacterZoneClient__HasSkill_x                            0x4D52A0
#define CharacterZoneClient__MakeMeVisible_x                       0x4D69C0
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE580
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAB80
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9370
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9450
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9530
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3370
#define CharacterZoneClient__BardCastBard_x                        0x4C5ED0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAC50
#define CharacterZoneClient__GetEffect_x                           0x4BAAC0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C43C0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4490
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C44E0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4630
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4800
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2A10
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7920
#define CharacterZoneClient__FindItemByRecord_x                    0x4D73A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6DE9B0
#define CBankWnd__WndNotification_x                                0x6DE790

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EC010

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61A2D0
#define CButtonWnd__CButtonWnd_x                                   0x936400

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70C390
#define CChatManager__InitContextMenu_x                            0x7054E0
#define CChatManager__FreeChatWindow_x                             0x70AED0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8A40
#define CChatManager__SetLockedActiveChatWindow_x                  0x70C010
#define CChatManager__CreateChatWindow_x                           0x70B510

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8B50

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94AAA0
#define CContextMenu__dCContextMenu_x                              0x94ACD0
#define CContextMenu__AddMenuItem_x                                0x94ACE0
#define CContextMenu__RemoveMenuItem_x                             0x94AFE0
#define CContextMenu__RemoveAllMenuItems_x                         0x94B000
#define CContextMenu__CheckMenuItem_x                              0x94B080
#define CContextMenu__SetMenuItem_x                                0x94AF10
#define CContextMenu__AddSeparator_x                               0x94AE70

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x94B620
#define CContextMenuManager__RemoveMenu_x                          0x94B690
#define CContextMenuManager__PopupMenu_x                           0x94B750
#define CContextMenuManager__Flush_x                               0x94B5C0
#define CContextMenuManager__GetMenu_x                             0x49B4D0
#define CContextMenuManager__CreateDefaultMenu_x                   0x717A00

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D9210
#define CChatService__GetFriendName_x                              0x8D9220

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70CC00
#define CChatWindow__Clear_x                                       0x70DEC0
#define CChatWindow__WndNotification_x                             0x70E650
#define CChatWindow__AddHistory_x                                  0x70D780

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x947EF0
#define CComboWnd__Draw_x                                          0x9473F0
#define CComboWnd__GetCurChoice_x                                  0x947D30
#define CComboWnd__GetListRect_x                                   0x9478A0
#define CComboWnd__GetTextRect_x                                   0x947F50
#define CComboWnd__InsertChoice_x                                  0x947A30
#define CComboWnd__SetColors_x                                     0x947A00
#define CComboWnd__SetChoice_x                                     0x947D00
#define CComboWnd__GetItemCount_x                                  0x947D40
#define CComboWnd__GetCurChoiceText_x                              0x947D80
#define CComboWnd__GetChoiceText_x                                 0x947D50
#define CComboWnd__InsertChoiceAtIndex_x                           0x947AC0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7153E0
#define CContainerWnd__vftable_x                                   0xB0C034
#define CContainerWnd__SetContainer_x                              0x716950

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54A600
#define CDisplay__PreZoneMainUI_x                                  0x54A610
#define CDisplay__CleanGameUI_x                                    0x54F980
#define CDisplay__GetClickedActor_x                                0x542920
#define CDisplay__GetUserDefinedColor_x                            0x53AFE0
#define CDisplay__GetWorldFilePath_x                               0x544390
#define CDisplay__is3dON_x                                         0x53F580
#define CDisplay__ReloadUI_x                                       0x549A90
#define CDisplay__WriteTextHD2_x                                   0x53F370
#define CDisplay__TrueDistance_x                                   0x546050
#define CDisplay__SetViewActor_x                                   0x542240
#define CDisplay__GetFloorHeight_x                                 0x53F640
#define CDisplay__SetRenderWindow_x                                0x53DFA0
#define CDisplay__ToggleScreenshotMode_x                           0x541D10

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96A690

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x94DFF0
#define CEditWnd__GetCharIndexPt_x                                 0x94EF10
#define CEditWnd__GetDisplayString_x                               0x94EDB0
#define CEditWnd__GetHorzOffset_x                                  0x94D630
#define CEditWnd__GetLineForPrintableChar_x                        0x9500B0
#define CEditWnd__GetSelStartPt_x                                  0x94F1C0
#define CEditWnd__GetSTMLSafeText_x                                0x94EBD0
#define CEditWnd__PointFromPrintableChar_x                         0x94FCE0
#define CEditWnd__SelectableCharFromPoint_x                        0x94FE50
#define CEditWnd__SetEditable_x                                    0x94F290
#define CEditWnd__SetWindowTextA_x                                 0x94E950

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5F96F0
#define CEverQuest__ClickedPlayer_x                                0x5EB700
#define CEverQuest__CreateTargetIndicator_x                        0x608D20
#define CEverQuest__DeleteTargetIndicator_x                        0x608DB0
#define CEverQuest__DoTellWindow_x                                 0x4E8C30
#define CEverQuest__OutputTextToLog_x                              0x4E8EB0
#define CEverQuest__DropHeldItemOnGround_x                         0x5E0740
#define CEverQuest__dsp_chat_x                                     0x4E9240
#define CEverQuest__trimName_x                                     0x605000
#define CEverQuest__Emote_x                                        0x5F9F50
#define CEverQuest__EnterZone_x                                    0x5F3ED0
#define CEverQuest__GetBodyTypeDesc_x                              0x5FE8C0
#define CEverQuest__GetClassDesc_x                                 0x5FEF00
#define CEverQuest__GetClassThreeLetterCode_x                      0x5FF500
#define CEverQuest__GetDeityDesc_x                                 0x607660
#define CEverQuest__GetLangDesc_x                                  0x5FF6C0
#define CEverQuest__GetRaceDesc_x                                  0x5FEEE0
#define CEverQuest__InterpretCmd_x                                 0x607C30
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E4940
#define CEverQuest__LMouseUp_x                                     0x5E2CD0
#define CEverQuest__RightClickedOnPlayer_x                         0x5E5220
#define CEverQuest__RMouseUp_x                                     0x5E3C50
#define CEverQuest__SetGameState_x                                 0x5E04D0
#define CEverQuest__UPCNotificationFlush_x                         0x604F00
#define CEverQuest__IssuePetCommand_x                              0x600AC0
#define CEverQuest__ReportSuccessfulHit_x                          0x5FB340

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7274A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x727500
#define CGaugeWnd__Draw_x                                          0x726B20

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF460
#define CGuild__GetGuildName_x                                     0x4AE540
#define CGuild__GetGuildIndex_x                                    0x4AE8D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7429E0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61A690

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x74FA30
#define CInvSlotMgr__MoveItem_x                                    0x74E740
#define CInvSlotMgr__SelectSlot_x                                  0x74FB00

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x74CFB0
#define CInvSlot__SliderComplete_x                                 0x74AD00
#define CInvSlot__GetItemBase_x                                    0x74A680
#define CInvSlot__UpdateItem_x                                     0x74A7F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x751570
#define CInvSlotWnd__CInvSlotWnd_x                                 0x750720
#define CInvSlotWnd__HandleLButtonUp_x                             0x7510F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80AE60
#define CItemDisplayWnd__UpdateStrings_x                           0x75FCA0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x759970
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x759EA0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7602A0
#define CItemDisplayWnd__AboutToShow_x                             0x75F8E0
#define CItemDisplayWnd__WndNotification_x                         0x761390
#define CItemDisplayWnd__RequestConvertItem_x                      0x760E50
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x75E950
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x75F700

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x843970

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7658E0

// CLabel 
#define CLabel__Draw_x                                             0x76B2D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x9204B0
#define CListWnd__dCListWnd_x                                      0x9207C0
#define CListWnd__AddColumn_x                                      0x924C20
#define CListWnd__AddColumn1_x                                     0x924C70
#define CListWnd__AddLine_x                                        0x925000
#define CListWnd__AddString_x                                      0x924E00
#define CListWnd__CalculateFirstVisibleLine_x                      0x9249E0
#define CListWnd__CalculateVSBRange_x                              0x9247C0
#define CListWnd__ClearSel_x                                       0x9257E0
#define CListWnd__ClearAllSel_x                                    0x925840
#define CListWnd__CloseAndUpdateEditWindow_x                       0x926240
#define CListWnd__Compare_x                                        0x924100
#define CListWnd__Draw_x                                           0x9208F0
#define CListWnd__DrawColumnSeparators_x                           0x9230D0
#define CListWnd__DrawHeader_x                                     0x923540
#define CListWnd__DrawItem_x                                       0x923A40
#define CListWnd__DrawLine_x                                       0x923240
#define CListWnd__DrawSeparator_x                                  0x923170
#define CListWnd__EnableLine_x                                     0x9229B0
#define CListWnd__EnsureVisible_x                                  0x926170
#define CListWnd__ExtendSel_x                                      0x925710
#define CListWnd__GetColumnTooltip_x                               0x9224F0
#define CListWnd__GetColumnMinWidth_x                              0x922560
#define CListWnd__GetColumnWidth_x                                 0x922460
#define CListWnd__GetCurSel_x                                      0x921DF0
#define CListWnd__GetItemAtPoint_x                                 0x922C20
#define CListWnd__GetItemAtPoint1_x                                0x922C90
#define CListWnd__GetItemData_x                                    0x921E70
#define CListWnd__GetItemHeight_x                                  0x922230
#define CListWnd__GetItemIcon_x                                    0x922000
#define CListWnd__GetItemRect_x                                    0x922AA0
#define CListWnd__GetItemText_x                                    0x921EB0
#define CListWnd__GetSelList_x                                     0x925890
#define CListWnd__GetSeparatorRect_x                               0x922ED0
#define CListWnd__InsertLine_x                                     0x9253F0
#define CListWnd__RemoveLine_x                                     0x925540
#define CListWnd__SetColors_x                                      0x9247A0
#define CListWnd__SetColumnJustification_x                         0x9244D0
#define CListWnd__SetColumnWidth_x                                 0x9243F0
#define CListWnd__SetCurSel_x                                      0x925650
#define CListWnd__SetItemColor_x                                   0x925E30
#define CListWnd__SetItemData_x                                    0x925DF0
#define CListWnd__SetItemText_x                                    0x925A00
#define CListWnd__ShiftColumnSeparator_x                           0x924590
#define CListWnd__Sort_x                                           0x924280
#define CListWnd__ToggleSel_x                                      0x925680
#define CListWnd__SetColumnsSizable_x                              0x924640
#define CListWnd__SetItemWnd_x                                     0x925CB0
#define CListWnd__GetItemWnd_x                                     0x922050
#define CListWnd__SetItemIcon_x                                    0x925A80
#define CListWnd__CalculateCustomWindowPositions_x                 0x924AE0
#define CListWnd__SetVScrollPos_x                                  0x9243D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x780AD0
#define CMapViewWnd__GetWorldCoordinates_x                         0x77F1E0
#define CMapViewWnd__HandleLButtonDown_x                           0x77C220

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A0BA0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A1480
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A19B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A4940
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x79F710
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AA500
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A07C0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A6B40
#define CPacketScrambler__hton_x                                   0x8A6B30

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x93F680
#define CSidlManager__FindScreenPieceTemplate_x                    0x93FA90
#define CSidlManager__FindScreenPieceTemplate1_x                   0x93F880
#define CSidlManager__CreateLabel_x                                0x802310
#define CSidlManager__CreateXWndFromTemplate_x                     0x9429F0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x942BD0
#define CSidlManager__CreateXWnd_x                                 0x802240
#define CSidlManager__CreateHotButtonWnd_x                         0x802810

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x93C160
#define CSidlScreenWnd__CalculateVSBRange_x                        0x93C060
#define CSidlScreenWnd__ConvertToRes_x                             0x9616E0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x93BAF0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x93B7E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x93B8B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x93B980
#define CSidlScreenWnd__DrawSidlPiece_x                            0x93C600
#define CSidlScreenWnd__EnableIniStorage_x                         0x93CAD0
#define CSidlScreenWnd__GetSidlPiece_x                             0x93C7F0
#define CSidlScreenWnd__Init1_x                                    0x93B3E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x93CB20
#define CSidlScreenWnd__LoadIniListWnd_x                           0x93D660
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93A7E0
#define CSidlScreenWnd__StoreIniInfo_x                             0x93D1E0
#define CSidlScreenWnd__StoreIniVis_x                              0x93D540
#define CSidlScreenWnd__WndNotification_x                          0x93C510
#define CSidlScreenWnd__GetChildItem_x                             0x93CA50
#define CSidlScreenWnd__HandleLButtonUp_x                          0x92C0D0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F0F40

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x67EF20
#define CSkillMgr__GetSkillCap_x                                   0x67F100
#define CSkillMgr__GetNameToken_x                                  0x67E6A0
#define CSkillMgr__IsActivatedSkill_x                              0x67E7E0
#define CSkillMgr__IsCombatSkill_x                                 0x67E720

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x94C410
#define CSliderWnd__SetValue_x                                     0x94C280
#define CSliderWnd__SetNumTicks_x                                  0x94C2E0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x8082F0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x954C10
#define CStmlWnd__CalculateHSBRange_x                              0x955CF0
#define CStmlWnd__CalculateVSBRange_x                              0x955C60
#define CStmlWnd__CanBreakAtCharacter_x                            0x95A040
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95ACD0
#define CStmlWnd__ForceParseNow_x                                  0x9551B0
#define CStmlWnd__GetNextTagPiece_x                                0x959FA0
#define CStmlWnd__GetSTMLText_x                                    0x502DD0
#define CStmlWnd__GetVisibleText_x                                 0x9551D0
#define CStmlWnd__InitializeWindowVariables_x                      0x95AB20
#define CStmlWnd__MakeStmlColorTag_x                               0x954280
#define CStmlWnd__MakeWndNotificationTag_x                         0x9542F0
#define CStmlWnd__SetSTMLText_x                                    0x953330
#define CStmlWnd__StripFirstSTMLLines_x                            0x95BDD0
#define CStmlWnd__UpdateHistoryString_x                            0x95AEE0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x952470
#define CTabWnd__DrawCurrentPage_x                                 0x952BA0
#define CTabWnd__DrawTab_x                                         0x9528C0
#define CTabWnd__GetCurrentPage_x                                  0x951C70
#define CTabWnd__GetPageInnerRect_x                                0x951EB0
#define CTabWnd__GetTabInnerRect_x                                 0x951DF0
#define CTabWnd__GetTabRect_x                                      0x951CA0
#define CTabWnd__InsertPage_x                                      0x9520C0
#define CTabWnd__SetPage_x                                         0x951F30
#define CTabWnd__SetPageRect_x                                     0x9523B0
#define CTabWnd__UpdatePage_x                                      0x952780
#define CTabWnd__GetPageFromTabIndex_x                             0x952800
#define CTabWnd__GetCurrentTabIndex_x                              0x951C60

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x765CD0
#define CPageWnd__SetTabText_x                                     0x9517C0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A9090

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x928F30
#define CTextureFont__GetTextExtent_x                              0x9290F0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B20B0
#define CHtmlComponentWnd__ValidateUri_x                           0x7443D0
#define CHtmlWnd__SetClientCallbacks_x                             0x61F710
#define CHtmlWnd__AddObserver_x                                    0x61F730
#define CHtmlWnd__RemoveObserver_x                                 0x61F790
#define Window__getProgress_x                                      0x85BEE0
#define Window__getStatus_x                                        0x85BF00
#define Window__getURI_x                                           0x85BF10

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x967120

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x915FC0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8780
#define CXStr__CXStr1_x                                            0x91E9E0
#define CXStr__CXStr3_x                                            0x8F88F0
#define CXStr__dCXStr_x                                            0x4787E0
#define CXStr__operator_equal_x                                    0x8F8B20
#define CXStr__operator_equal1_x                                   0x8F8B60
#define CXStr__operator_plus_equal1_x                              0x8F95F0
#define CXStr__SetString_x                                         0x8FB4E0
#define CXStr__operator_char_p_x                                   0x8F9030
#define CXStr__GetChar_x                                           0x8FAE10
#define CXStr__Delete_x                                            0x8FA6E0
#define CXStr__GetUnicode_x                                        0x8FAE80
#define CXStr__GetLength_x                                         0x4A8E40
#define CXStr__Mid_x                                               0x47D550
#define CXStr__Insert_x                                            0x8FAEE0
#define CXStr__FindNext_x                                          0x8FAB50

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94A6A0
#define CXWnd__BringToTop_x                                        0x92F8B0
#define CXWnd__Center_x                                            0x92F430
#define CXWnd__ClrFocus_x                                          0x92F250
#define CXWnd__Destroy_x                                           0x92F2F0
#define CXWnd__DoAllDrawing_x                                      0x92B860
#define CXWnd__DrawChildren_x                                      0x92B830
#define CXWnd__DrawColoredRect_x                                   0x92BCC0
#define CXWnd__DrawTooltip_x                                       0x92A380
#define CXWnd__DrawTooltipAtPoint_x                                0x92A440
#define CXWnd__GetBorderFrame_x                                    0x92BB20
#define CXWnd__GetChildWndAt_x                                     0x92F950
#define CXWnd__GetClientClipRect_x                                 0x92DB50
#define CXWnd__GetScreenClipRect_x                                 0x92DC00
#define CXWnd__GetScreenRect_x                                     0x92DDB0
#define CXWnd__GetTooltipRect_x                                    0x92BD10
#define CXWnd__GetWindowTextA_x                                    0x49CBC0
#define CXWnd__IsActive_x                                          0x92C450
#define CXWnd__IsDescendantOf_x                                    0x92E790
#define CXWnd__IsReallyVisible_x                                   0x92E7C0
#define CXWnd__IsType_x                                            0x92FFD0
#define CXWnd__Move_x                                              0x92E830
#define CXWnd__Move1_x                                             0x92E8F0
#define CXWnd__ProcessTransition_x                                 0x92F3E0
#define CXWnd__Refade_x                                            0x92EBD0
#define CXWnd__Resize_x                                            0x92EE60
#define CXWnd__Right_x                                             0x92F670
#define CXWnd__SetFocus_x                                          0x92F210
#define CXWnd__SetFont_x                                           0x92F280
#define CXWnd__SetKeyTooltip_x                                     0x92FDE0
#define CXWnd__SetMouseOver_x                                      0x92CCA0
#define CXWnd__StartFade_x                                         0x92E670
#define CXWnd__GetChildItem_x                                      0x92FAC0
#define CXWnd__SetParent_x                                         0x92E560
#define CXWnd__Minimize_x                                          0x92EED0

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x962760

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x932880
#define CXWndManager__DrawWindows_x                                0x9328A0
#define CXWndManager__GetKeyboardFlags_x                           0x935090
#define CXWndManager__HandleKeyboardMsg_x                          0x934C40
#define CXWndManager__RemoveWnd_x                                  0x9352E0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x935840

// CDBStr
#define CDBStr__GetString_x                                        0x539FB0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBB60
#define EQ_Character__Cur_HP_x                                     0x4D22E0
#define EQ_Character__Cur_Mana_x                                   0x4D9A30
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEBD0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2650
#define EQ_Character__GetFocusRangeModifier_x                      0x4B27A0
#define EQ_Character__GetHPRegen_x                                 0x4DF800
#define EQ_Character__GetEnduranceRegen_x                          0x4DFE00
#define EQ_Character__GetManaRegen_x                               0x4E0240
#define EQ_Character__Max_Endurance_x                              0x645690
#define EQ_Character__Max_HP_x                                     0x4D2110
#define EQ_Character__Max_Mana_x                                   0x645490
#define EQ_Character__doCombatAbility_x                            0x647AF0
#define EQ_Character__UseSkill_x                                   0x4E2020
#define EQ_Character__GetConLevel_x                                0x63E970
#define EQ_Character__IsExpansionFlag_x                            0x5A29F0
#define EQ_Character__TotalEffect_x                                0x4C5610
#define EQ_Character__GetPCSpellAffect_x                           0x4BF920
#define EQ_Character__SpellDuration_x                              0x4BF450
#define EQ_Character__GetAdjustedSkill_x                           0x4D5060
#define EQ_Character__GetBaseSkill_x                               0x4D6000
#define EQ_Character__CanUseItem_x                                 0x4D9D40

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C6070

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65BBC0

//PcClient
#define PcClient__PcClient_x                                       0x63C0B0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B97C0
#define CCharacterListWnd__EnterWorld_x                            0x4B9200
#define CCharacterListWnd__Quit_x                                  0x4B8F50
#define CCharacterListWnd__UpdateList_x                            0x4B9390

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x620970
#define EQ_Item__CreateItemTagString_x                             0x8A0400
#define EQ_Item__IsStackable_x                                     0x8A4F30
#define EQ_Item__GetImageNum_x                                     0x8A1EB0
#define EQ_Item__CreateItemClient_x                                0x61FB30
#define EQ_Item__GetItemValue_x                                    0x8A3180
#define EQ_Item__ValueSellMerchant_x                               0x8A6720
#define EQ_Item__IsKeyRingItem_x                                   0x8A4840
#define EQ_Item__CanGoInBag_x                                      0x620A90
#define EQ_Item__IsEmpty_x                                         0x8A43A0
#define EQ_Item__GetMaxItemCount_x                                 0x8A35A0
#define EQ_Item__GetHeldItem_x                                     0x8A1D80
#define EQ_Item__GetAugmentFitBySlot_x                             0x89FD70

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x558400
#define EQ_LoadingS__Array_x                                       0xC1FB60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x645FF0
#define EQ_PC__GetAlternateAbilityId_x                             0x8AF910
#define EQ_PC__GetCombatAbility_x                                  0x8AFF80
#define EQ_PC__GetCombatAbilityTimer_x                             0x8AFFF0
#define EQ_PC__GetItemRecastTimer_x                                0x648070
#define EQ_PC__HasLoreItem_x                                       0x63F180
#define EQ_PC__AlertInventoryChanged_x                             0x63E2B0
#define EQ_PC__GetPcZoneClient_x                                   0x66A5D0
#define EQ_PC__RemoveMyAffect_x                                    0x64B2A0
#define EQ_PC__GetKeyRingItems_x                                   0x8B0880
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B0610
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B0B80

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5A8F80
#define EQItemList__add_object_x                                   0x5D5FB0
#define EQItemList__add_item_x                                     0x5A94E0
#define EQItemList__delete_item_x                                  0x5A9530
#define EQItemList__FreeItemList_x                                 0x5A9430

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x536AF0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x65D440
#define EQPlayer__dEQPlayer_x                                      0x650780
#define EQPlayer__DoAttack_x                                       0x665280
#define EQPlayer__EQPlayer_x                                       0x650E40
#define EQPlayer__SetNameSpriteState_x                             0x655120
#define EQPlayer__SetNameSpriteTint_x                              0x655FF0
#define PlayerBase__HasProperty_j_x                                0x994DA0
#define EQPlayer__IsTargetable_x                                   0x995240
#define EQPlayer__CanSee_x                                         0x9950A0
#define EQPlayer__CanSee1_x                                        0x995170
#define PlayerBase__GetVisibilityLineSegment_x                     0x994E60

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x668060
#define PlayerZoneClient__GetLevel_x                               0x66A610
#define PlayerZoneClient__IsValidTeleport_x                        0x5D7120
#define PlayerZoneClient__LegalPlayerRace_x                        0x551810

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x660190
#define EQPlayerManager__GetSpawnByName_x                          0x660240
#define EQPlayerManager__GetPlayerFromPartialName_x                0x6602D0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x623FA0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x624020
#define KeypressHandler__AttachKeyToEqCommand_x                    0x624060
#define KeypressHandler__ClearCommandStateArray_x                  0x625470
#define KeypressHandler__HandleKeyDown_x                           0x625490
#define KeypressHandler__HandleKeyUp_x                             0x625530
#define KeypressHandler__SaveKeymapping_x                          0x625980

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77C940
#define MapViewMap__SaveEx_x                                       0x77FD00
#define MapViewMap__SetZoom_x                                      0x7843C0

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C3EE0

// StringTable 
#define StringTable__getString_x                                   0x8BEBC0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64AF10
#define PcZoneClient__RemovePetEffect_x                            0x64B540
#define PcZoneClient__HasAlternateAbility_x                        0x6452C0
#define PcZoneClient__GetCurrentMod_x                              0x4E50E0
#define PcZoneClient__GetModCap_x                                  0x4E4FE0
#define PcZoneClient__CanEquipItem_x                               0x645990
#define PcZoneClient__GetItemByID_x                                0x6484E0
#define PcZoneClient__GetItemByItemClass_x                         0x648630
#define PcZoneClient__RemoveBuffEffect_x                           0x64B560
#define PcZoneClient__BandolierSwap_x                              0x6465B0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x648010

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DBC20

//IconCache
#define IconCache__GetIcon_x                                       0x71CAC0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x714580
#define CContainerMgr__CloseContainer_x                            0x714850
#define CContainerMgr__OpenExperimentContainer_x                   0x7152D0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D4950

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x618AA0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x772DA0
#define CLootWnd__RequestLootSlot_x                                0x771FD0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x5756E0
#define EQ_Spell__SpellAffects_x                                   0x575B50
#define EQ_Spell__SpellAffectBase_x                                0x575910
#define EQ_Spell__IsStackable_x                                    0x4C9D20
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9BA0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6B40
#define EQ_Spell__IsSPAStacking_x                                  0x5769A0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x575EB0
#define EQ_Spell__IsNoRemove_x                                     0x4C9D00
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x5769B0
#define __IsResEffectSpell_x                                       0x4C9050

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD1B0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8CE690

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81B600
#define CTargetWnd__WndNotification_x                              0x81AE90
#define CTargetWnd__RefreshTargetBuffs_x                           0x81B160
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81A010

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x81FC20

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x534500
#define CTaskManager__HandleMessage_x                              0x5329A0
#define CTaskManager__GetTaskStatus_x                              0x5345B0
#define CTaskManager__GetElementDescription_x                      0x534630

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x570C40
#define EqSoundManager__PlayScriptMp3_x                            0x570DA0
#define EqSoundManager__SoundAssistPlay_x                          0x682DE0
#define EqSoundManager__WaveInstancePlay_x                         0x682350

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x528260

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x950CD0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x55FD80
#define CAltAbilityData__GetMercMaxRank_x                          0x55FD10
#define CAltAbilityData__GetMaxRank_x                              0x5554A0

//CTargetRing
#define CTargetRing__Cast_x                                        0x616BC0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9B80
#define CharacterBase__CreateItemGlobalIndex_x                     0x50FBE0
#define CharacterBase__CreateItemIndex_x                           0x61ECC0
#define CharacterBase__GetItemPossession_x                         0x4FB870
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D6CA0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D6D00
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FB6E0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FBF10
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FBFC0

//messages
#define msg_spell_worn_off_x                                       0x59ACC0
#define msg_new_text_x                                             0x58FA50
#define __msgTokenTextParam_x                                      0x59D1F0
#define msgTokenText_x                                             0x59D440

//SpellManager
#define SpellManager__vftable_x                                    0xAE61A4
#define SpellManager__SpellManager_x                               0x686110
#define Spellmanager__LoadTextSpells_x                             0x686A00
#define SpellManager__GetSpellByGroupAndRank_x                     0x6862E0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x998C90

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x510260
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A0F90
#define ItemGlobalIndex__IsEquippedLocation_x                      0x637870
#define ItemGlobalIndex__IsValidIndex_x                            0x5102C0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8CF030
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8CF2B0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76B610

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x718CA0
#define CCursorAttachment__AttachToCursor1_x                       0x718CE0
#define CCursorAttachment__Deactivate_x                            0x719CD0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x943A30
#define CSidlManagerBase__CreatePageWnd_x                          0x943220
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x93F4A0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x93F430

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x960CD0
#define CEQSuiteTextureLoader__GetTexture_x                        0x960990

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50D150
#define CFindItemWnd__WndNotification_x                            0x50DC30
#define CFindItemWnd__Update_x                                     0x50E7A0
#define CFindItemWnd__PickupSelectedItem_x                         0x50C990

//IString
#define IString__Append_x                                          0x4FD060

//Camera
#define CDisplay__cameraType_x                                     0xDF9534
#define EverQuest__Cameras_x                                       0xEBCA6C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x515910
#define LootFiltersManager__GetItemFilterData_x                    0x515220
#define LootFiltersManager__RemoveItemLootFilter_x                 0x515250
#define LootFiltersManager__SetItemLootFilter_x                    0x515470

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C2960

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x99E8A0
#define CResolutionHandler__GetWindowedStyle_x                     0x67D850

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x711360

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E2DF0
#define CDistillerInfo__Instance_x                                 0x8E2D90

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x7316C0
#define CGroupWnd__UpdateDisplay_x                                 0x730A20

//ItemBase
#define ItemBase__IsLore_x                                         0x8A48E0
#define ItemBase__IsLoreEquipped_x                                 0x8A4960

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D5F10
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D6050
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D60B0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x672CE0
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x6766B0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x503470

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F2020
#define FactionManagerClient__HandleFactionMessage_x               0x4F2690
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2C90
#define FactionManagerClient__GetMaxFaction_x                      0x4F2CAF
#define FactionManagerClient__GetMinFaction_x                      0x4F2C60

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FB840

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x927EE0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BED0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FBA70

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x55F230

//CTargetManager
#define CTargetManager__Get_x                                      0x689960

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x672CE0

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8E50

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5A93D0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF5A100

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
