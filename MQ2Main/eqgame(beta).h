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
#define __ExpectedVersionDate                                     "Nov 11 2019"
#define __ExpectedVersionTime                                     "04:21:08"
#define __ActualVersionDate_x                                      0xB09244
#define __ActualVersionTime_x                                      0xB09238
#define __ActualVersionBuild_x                                     0xAF4F34

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x62D8B0
#define __MemChecker1_x                                            0x900B70
#define __MemChecker2_x                                            0x6BC080
#define __MemChecker3_x                                            0x6BBFD0
#define __MemChecker4_x                                            0x8580F0
#define __EncryptPad0_x                                            0xC3F3E8
#define __EncryptPad1_x                                            0xC9D5A8
#define __EncryptPad2_x                                            0xC4FC80
#define __EncryptPad3_x                                            0xC4F880
#define __EncryptPad4_x                                            0xC8DC00
#define __EncryptPad5_x                                            0xF69240
#define __AC1_x                                                    0x814AB6
#define __AC2_x                                                    0x5E78CF
#define __AC3_x                                                    0x5EEFCF
#define __AC4_x                                                    0x5F2FA0
#define __AC5_x                                                    0x5F92AF
#define __AC6_x                                                    0x5FD8C6
#define __AC7_x                                                    0x5E7340
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x191E2C

// Direct Input
#define DI8__Main_x                                                0xF69268
#define DI8__Keyboard_x                                            0xF6926C
#define DI8__Mouse_x                                               0xF6924C
#define DI8__Mouse_Copy_x                                          0xEC244C
#define DI8__Mouse_Check_x                                         0xF66D94
#define __AutoSkillArray_x                                         0xEC3364
#define __Attack_x                                                 0xF6118B
#define __Autofire_x                                               0xF6118C
#define __BindList_x                                               0xC2DE20
#define g_eqCommandStates_x                                        0xC2EBA0
#define __Clicks_x                                                 0xEC2504
#define __CommandList_x                                            0xC2F760
#define __CurrentMapLabel_x                                        0xF79C0C
#define __CurrentSocial_x                                          0xC177CC
#define __DoAbilityList_x                                          0xEF8CAC
#define __do_loot_x                                                0x5B3E10
#define __DrawHandler_x                                            0x15F8F80
#define __GroupCount_x                                             0xEB4E02
#define __Guilds_x                                                 0xEB8C58
#define __gWorld_x                                                 0xEB4C50
#define __HWnd_x                                                   0xF69250
#define __heqmain_x                                                0xF69228
#define __InChatMode_x                                             0xEC2434
#define __LastTell_x                                               0xEC43A8
#define __LMouseHeldTime_x                                         0xEC2570
#define __Mouse_x                                                  0xF69254
#define __MouseLook_x                                              0xEC24CA
#define __MouseEventTime_x                                         0xF61C6C
#define __gpbCommandEvent_x                                        0xEB26F0
#define __NetStatusToggle_x                                        0xEC24CD
#define __PCNames_x                                                0xEC3954
#define __RangeAttackReady_x                                       0xEC3648
#define __RMouseHeldTime_x                                         0xEC256C
#define __RunWalkState_x                                           0xEC2438
#define __ScreenMode_x                                             0xE000A4
#define __ScreenX_x                                                0xEC23EC
#define __ScreenY_x                                                0xEC23E8
#define __ScreenXMax_x                                             0xEC23F0
#define __ScreenYMax_x                                             0xEC23F4
#define __ServerHost_x                                             0xEB292B
#define __ServerName_x                                             0xEF8C6C
#define __ShiftKeyDown_x                                           0xEC2AC4
#define __ShowNames_x                                              0xEC3804
#define __Socials_x                                                0xEF8D6C
#define __SubscriptionType_x                                       0xFBE110
#define __TargetAggroHolder_x                                      0xF7C5C0
#define __ZoneType_x                                               0xEC28C8
#define __GroupAggro_x                                             0xF7C600
#define __LoginName_x                                              0xF699BC
#define __Inviter_x                                                0xF61108
#define __AttackOnAssist_x                                         0xEC37C0
#define __UseTellWindows_x                                         0xEC3AF0
#define __gfMaxZoomCameraDistance_x                                0xAFEBA8
#define __gfMaxCameraDistance_x                                    0xB2B0F4
#define __pulAutoRun_x                                             0xEC24E8
#define __pulForward_x                                             0xEC3B28
#define __pulBackward_x                                            0xEC3B2C
#define __pulTurnRight_x                                           0xEC3B30
#define __pulTurnLeft_x                                            0xEC3B34
#define __pulStrafeLeft_x                                          0xEC3B38
#define __pulStrafeRight_x                                         0xEC3B3C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB4FF8
#define instEQZoneInfo_x                                           0xEC26C0
#define pinstActiveBanker_x                                        0xEB2708
#define pinstActiveCorpse_x                                        0xEB2700
#define pinstActiveGMaster_x                                       0xEB2704
#define pinstActiveMerchant_x                                      0xEB26FC
#define pinstAltAdvManager_x                                       0xE01228
#define pinstBandageTarget_x                                       0xEB2718
#define pinstCamActor_x                                            0xE00098
#define pinstCDBStr_x                                              0xDFFF44
#define pinstCDisplay_x                                            0xEB4C4C
#define pinstCEverQuest_x                                          0xF69280
#define pinstEverQuestInfo_x                                       0xEC23E0
#define pinstCharData_x                                            0xEB4DE4
#define pinstCharSpawn_x                                           0xEB27D0
#define pinstControlledMissile_x                                   0xEB2C3C
#define pinstControlledPlayer_x                                    0xEB27D0
#define pinstCResolutionHandler_x                                  0x15F91B0
#define pinstCSidlManager_x                                        0x15F8148
#define pinstCXWndManager_x                                        0x15F8144
#define instDynamicZone_x                                          0xEB8B30
#define pinstDZMember_x                                            0xEB8C40
#define pinstDZTimerInfo_x                                         0xEB8C44
#define pinstEqLogin_x                                             0xF69308
#define instEQMisc_x                                               0xDFFE88
#define pinstEQSoundManager_x                                      0xE021F8
#define pinstEQSpellStrings_x                                      0xCC28F8
#define instExpeditionLeader_x                                     0xEB8B7A
#define instExpeditionName_x                                       0xEB8BBA
#define pinstGroup_x                                               0xEB4DFE
#define pinstImeManager_x                                          0x15F8140
#define pinstLocalPlayer_x                                         0xEB26F8
#define pinstMercenaryData_x                                       0xF6375C
#define pinstMercenaryStats_x                                      0xF7C70C
#define pinstModelPlayer_x                                         0xEB2710
#define pinstPCData_x                                              0xEB4DE4
#define pinstSkillMgr_x                                            0xF658C8
#define pinstSpawnManager_x                                        0xF64370
#define pinstSpellManager_x                                        0xF65AE8
#define pinstSpellSets_x                                           0xF59DB4
#define pinstStringTable_x                                         0xEB4DE8
#define pinstSwitchManager_x                                       0xEB2598
#define pinstTarget_x                                              0xEB274C
#define pinstTargetObject_x                                        0xEB27D8
#define pinstTargetSwitch_x                                        0xEB2C44
#define pinstTaskMember_x                                          0xDFFD18
#define pinstTrackTarget_x                                         0xEB27D4
#define pinstTradeTarget_x                                         0xEB270C
#define instTributeActive_x                                        0xDFFEA9
#define pinstViewActor_x                                           0xE00094
#define pinstWorldData_x                                           0xEB2824
#define pinstZoneAddr_x                                            0xEC2960
#define pinstPlayerPath_x                                          0xF64408
#define pinstTargetIndicator_x                                     0xF65D50
#define EQObject_Top_x                                             0xEB26F4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE00830
#define pinstCAchievementsWnd_x                                    0xE0082C
#define pinstCActionsWnd_x                                         0xE007F4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE00064
#define pinstCAdvancedLootWnd_x                                    0xE00024
#define pinstCAdventureLeaderboardWnd_x                            0xF733E0
#define pinstCAdventureRequestWnd_x                                0xF73490
#define pinstCAdventureStatsWnd_x                                  0xF73540
#define pinstCAggroMeterWnd_x                                      0xE00110
#define pinstCAlarmWnd_x                                           0xDFFFF0
#define pinstCAlertHistoryWnd_x                                    0xE00084
#define pinstCAlertStackWnd_x                                      0xDFFFF8
#define pinstCAlertWnd_x                                           0xE00004
#define pinstCAltStorageWnd_x                                      0xF738A0
#define pinstCAudioTriggersWindow_x                                0xCB4C28
#define pinstCAuraWnd_x                                            0xE000BC
#define pinstCAvaZoneWnd_x                                         0xE00060
#define pinstCBandolierWnd_x                                       0xE00108
#define pinstCBankWnd_x                                            0xE000B8
#define pinstCBarterMerchantWnd_x                                  0xF74AE0
#define pinstCBarterSearchWnd_x                                    0xF74B90
#define pinstCBarterWnd_x                                          0xF74C40
#define pinstCBazaarConfirmationWnd_x                              0xE00858
#define pinstCBazaarSearchWnd_x                                    0xE005D8
#define pinstCBazaarWnd_x                                          0xE00874
#define pinstCBlockedBuffWnd_x                                     0xE000C4
#define pinstCBlockedPetBuffWnd_x                                  0xE000E4
#define pinstCBodyTintWnd_x                                        0xE00804
#define pinstCBookWnd_x                                            0xE0013C
#define pinstCBreathWnd_x                                          0xE00848
#define pinstCBuffWindowNORMAL_x                                   0xE00088
#define pinstCBuffWindowSHORT_x                                    0xE0008C
#define pinstCBugReportWnd_x                                       0xE000B0
#define pinstCButtonWnd_x                                          0x15F83B0
#define pinstCCastingWnd_x                                         0xE00124
#define pinstCCastSpellWnd_x                                       0xE00844
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE00878
#define pinstCChatWindowManager_x                                  0xF75700
#define pinstCClaimWnd_x                                           0xF75858
#define pinstCColorPickerWnd_x                                     0xE007FC
#define pinstCCombatAbilityWnd_x                                   0xDFFFE8
#define pinstCCombatSkillsSelectWnd_x                              0xE0000C
#define pinstCCompassWnd_x                                         0xE007F8
#define pinstCConfirmationDialog_x                                 0xF7A758
#define pinstCContainerMgr_x                                       0xE0086C
#define pinstCContextMenuManager_x                                 0x15F8100
#define pinstCCursorAttachment_x                                   0xE00118
#define pinstCDynamicZoneWnd_x                                     0xF75E20
#define pinstCEditLabelWnd_x                                       0xE00080
#define pinstCEQMainWnd_x                                          0xF76068
#define pinstCEventCalendarWnd_x                                   0xE0011C
#define pinstCExtendedTargetWnd_x                                  0xE000D8
#define pinstCFacePick_x                                           0xE0001C
#define pinstCFactionWnd_x                                         0xE00868
#define pinstCFellowshipWnd_x                                      0xF76268
#define pinstCFileSelectionWnd_x                                   0xE00120
#define pinstCFindItemWnd_x                                        0xE00854
#define pinstCFindLocationWnd_x                                    0xF763C0
#define pinstCFriendsWnd_x                                         0xE00020
#define pinstCGemsGameWnd_x                                        0xE00864
#define pinstCGiveWnd_x                                            0xDFFFF4
#define pinstCGroupSearchFiltersWnd_x                              0xE00128
#define pinstCGroupSearchWnd_x                                     0xF767B8
#define pinstCGroupWnd_x                                           0xF76868
#define pinstCGuildBankWnd_x                                       0xEC37A4
#define pinstCGuildCreationWnd_x                                   0xF769C8
#define pinstCGuildMgmtWnd_x                                       0xF76A78
#define pinstCharacterCreation_x                                   0xE00014
#define pinstCHelpWnd_x                                            0xE00058
#define pinstCHeritageSelectionWnd_x                               0xE00028
#define pinstCHotButtonWnd_x                                       0xF78BD0
#define pinstCHotButtonWnd1_x                                      0xF78BD0
#define pinstCHotButtonWnd2_x                                      0xF78BD4
#define pinstCHotButtonWnd3_x                                      0xF78BD8
#define pinstCHotButtonWnd4_x                                      0xF78BDC
#define pinstCIconSelectionWnd_x                                   0xE00114
#define pinstCInspectWnd_x                                         0xE00054
#define pinstCInventoryWnd_x                                       0xE0002C
#define pinstCInvSlotMgr_x                                         0xE00828
#define pinstCItemDisplayManager_x                                 0xF79160
#define pinstCItemExpTransferWnd_x                                 0xF79294
#define pinstCItemOverflowWnd_x                                    0xE005DC
#define pinstCJournalCatWnd_x                                      0xE005B8
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE000DC
#define pinstCKeyRingWnd_x                                         0xE0007C
#define pinstCLargeDialogWnd_x                                     0xF7B3D8
#define pinstCLayoutCopyWnd_x                                      0xF795E0
#define pinstCLFGuildWnd_x                                         0xF79690
#define pinstCLoadskinWnd_x                                        0xE00870
#define pinstCLootFiltersCopyWnd_x                                 0xCD1220
#define pinstCLootFiltersWnd_x                                     0xDFFFFC
#define pinstCLootSettingsWnd_x                                    0xE00018
#define pinstCLootWnd_x                                            0xE005BC
#define pinstCMailAddressBookWnd_x                                 0xE00838
#define pinstCMailCompositionWnd_x                                 0xE00814
#define pinstCMailIgnoreListWnd_x                                  0xE0083C
#define pinstCMailWnd_x                                            0xE007F0
#define pinstCManageLootWnd_x                                      0xE016D8
#define pinstCMapToolbarWnd_x                                      0xE0005C
#define pinstCMapViewWnd_x                                         0xE00038
#define pinstCMarketplaceWnd_x                                     0xE00000
#define pinstCMerchantWnd_x                                        0xE005C0
#define pinstCMIZoneSelectWnd_x                                    0xF79EC8
#define pinstCMusicPlayerWnd_x                                     0xE005CC
#define pinstCNameChangeMercWnd_x                                  0xE00850
#define pinstCNameChangePetWnd_x                                   0xE00834
#define pinstCNameChangeWnd_x                                      0xE00860
#define pinstCNoteWnd_x                                            0xE0003C
#define pinstCObjectPreviewWnd_x                                   0xE00010
#define pinstCOptionsWnd_x                                         0xE00044
#define pinstCPetInfoWnd_x                                         0xE007E0
#define pinstCPetitionQWnd_x                                       0xE00820
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE00808
#define pinstCPlayerWnd_x                                          0xE007E4
#define pinstCPopupWndManager_x                                    0xF7A758
#define pinstCProgressionSelectionWnd_x                            0xF7A808
#define pinstCPurchaseGroupWnd_x                                   0xE00048
#define pinstCPurchaseWnd_x                                        0xE00030
#define pinstCPvPLeaderboardWnd_x                                  0xF7A8B8
#define pinstCPvPStatsWnd_x                                        0xF7A968
#define pinstCQuantityWnd_x                                        0xE000E0
#define pinstCRaceChangeWnd_x                                      0xDFFFEC
#define pinstCRaidOptionsWnd_x                                     0xE00130
#define pinstCRaidWnd_x                                            0xE0081C
#define pinstCRealEstateItemsWnd_x                                 0xE00824
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE005C4
#define pinstCRealEstateManageWnd_x                                0xE00050
#define pinstCRealEstateNeighborhoodWnd_x                          0xE00078
#define pinstCRealEstatePlotSearchWnd_x                            0xE000B4
#define pinstCRealEstatePurchaseWnd_x                              0xE000F4
#define pinstCRespawnWnd_x                                         0xE000CC
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE00840
#define pinstCSendMoneyWnd_x                                       0xE00008
#define pinstCServerListWnd_x                                      0xE0010C
#define pinstCSkillsSelectWnd_x                                    0xDFFFE0
#define pinstCSkillsWnd_x                                          0xE0085C
#define pinstCSocialEditWnd_x                                      0xE00074
#define pinstCSocialWnd_x                                          0xE0084C
#define pinstCSpellBookWnd_x                                       0xDFFFE4
#define pinstCStoryWnd_x                                           0xE007E8
#define pinstCTargetOfTargetWnd_x                                  0xF7C790
#define pinstCTargetWnd_x                                          0xE000C8
#define pinstCTaskOverlayWnd_x                                     0xE00040
#define pinstCTaskSelectWnd_x                                      0xF7C8E8
#define pinstCTaskManager_x                                        0xCD1B60
#define pinstCTaskTemplateSelectWnd_x                              0xF7C998
#define pinstCTaskWnd_x                                            0xF7CA48
#define pinstCTextEntryWnd_x                                       0xE00090
#define pinstCTimeLeftWnd_x                                        0xE007EC
#define pinstCTipWndCONTEXT_x                                      0xF7CC4C
#define pinstCTipWndOFDAY_x                                        0xF7CC48
#define pinstCTitleWnd_x                                           0xF7CCF8
#define pinstCTrackingWnd_x                                        0xE00034
#define pinstCTradeskillWnd_x                                      0xF7CE60
#define pinstCTradeWnd_x                                           0xE00810
#define pinstCTrainWnd_x                                           0xE0080C
#define pinstCTributeBenefitWnd_x                                  0xF7D060
#define pinstCTributeMasterWnd_x                                   0xF7D110
#define pinstCTributeTrophyWnd_x                                   0xF7D1C0
#define pinstCVideoModesWnd_x                                      0xE005D0
#define pinstCVoiceMacroWnd_x                                      0xF664B8
#define pinstCVoteResultsWnd_x                                     0xE00818
#define pinstCVoteWnd_x                                            0xE00800
#define pinstCWebManager_x                                         0xF66B34
#define pinstCZoneGuideWnd_x                                       0xE0004C
#define pinstCZonePathWnd_x                                        0xE0006C

#define pinstEQSuiteTextureLoader_x                                0xC9F080
#define pinstItemIconCache_x                                       0xF76020
#define pinstLootFiltersManager_x                                  0xCD12D0
#define pinstRewardSelectionWnd_x                                  0xF7B0B0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5AF270
#define __CastRay2_x                                               0x5AF2C0
#define __ConvertItemTags_x                                        0x5CAE20
#define __CleanItemTags_x                                          0x47D190
#define __DoesFileExist_x                                          0x903CB0
#define __EQGetTime_x                                              0x900640
#define __ExecuteCmd_x                                             0x5A7B60
#define __FixHeading_x                                             0x99B980
#define __GameLoop_x                                               0x6BB270
#define __get_bearing_x                                            0x5AEDE0
#define __get_melee_range_x                                        0x5AF4B0
#define __GetAnimationCache_x                                      0x7205E0
#define __GetGaugeValueFromEQ_x                                    0x812F60
#define __GetLabelFromEQ_x                                         0x814A40
#define __GetXTargetType_x                                         0x99D360
#define __HandleMouseWheel_x                                       0x6BC130
#define __HeadingDiff_x                                            0x99B9F0
#define __HelpPath_x                                               0xF6185C
#define __LoadFrontEnd_x                                           0x6B8590
#define __NewUIINI_x                                               0x812C30
#define __ProcessGameEvents_x                                      0x60F120
#define __ProcessMouseEvent_x                                      0x60E8E0
#define __SaveColors_x                                             0x551400
#define __STMLToText_x                                             0x93EE40
#define __ToggleKeyRingItem_x                                      0x514B90
#define CMemoryMappedFile__SetFile_x                               0xA8AD40
#define CrashDetected_x                                            0x6BA030
#define DrawNetStatus_x                                            0x63AC00
#define Expansion_HoT_x                                            0xEC37AC
#define Teleport_Table_Size_x                                      0xEB27E0
#define Teleport_Table_x                                           0xEB2C48
#define Util__FastTime_x                                           0x900210

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4903A0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499290
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499060
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493920
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D70

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x559000
#define AltAdvManager__IsAbilityReady_x                            0x557F30
#define AltAdvManager__GetAAById_x                                 0x558130
#define AltAdvManager__CanTrainAbility_x                           0x5581A0
#define AltAdvManager__CanSeeAbility_x                             0x558500

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA070
#define CharacterZoneClient__HasSkill_x                            0x4D4F60
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6680
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE200
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA800
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D9020
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D9100
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D91E0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2FF0
#define CharacterZoneClient__BardCastBard_x                        0x4C5B50
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA8D0
#define CharacterZoneClient__GetEffect_x                           0x4BA740
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C4040
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4110
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C4160
#define CharacterZoneClient__CalcAffectChange_x                    0x4C42B0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4480
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B2700
#define CharacterZoneClient__FindItemByGuid_x                      0x4D75E0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7060

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E1BC0
#define CBankWnd__WndNotification_x                                0x6E19A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6EF5A0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x61D690
#define CButtonWnd__CButtonWnd_x                                   0x93B200

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x70F760
#define CChatManager__InitContextMenu_x                            0x7088B0
#define CChatManager__FreeChatWindow_x                             0x70E2A0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8690
#define CChatManager__SetLockedActiveChatWindow_x                  0x70F3E0
#define CChatManager__CreateChatWindow_x                           0x70E8E0

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E87A0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x94F780
#define CContextMenu__dCContextMenu_x                              0x94F9B0
#define CContextMenu__AddMenuItem_x                                0x94F9C0
#define CContextMenu__RemoveMenuItem_x                             0x94FCC0
#define CContextMenu__RemoveAllMenuItems_x                         0x94FCE0
#define CContextMenu__CheckMenuItem_x                              0x94FD60
#define CContextMenu__SetMenuItem_x                                0x94FBF0
#define CContextMenu__AddSeparator_x                               0x94FB50

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x950300
#define CContextMenuManager__RemoveMenu_x                          0x950370
#define CContextMenuManager__PopupMenu_x                           0x950430
#define CContextMenuManager__Flush_x                               0x9502A0
#define CContextMenuManager__GetMenu_x                             0x49B3A0
#define CContextMenuManager__CreateDefaultMenu_x                   0x71AE00

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DC630
#define CChatService__GetFriendName_x                              0x8DC640

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x70FFD0
#define CChatWindow__Clear_x                                       0x7112A0
#define CChatWindow__WndNotification_x                             0x711A30
#define CChatWindow__AddHistory_x                                  0x710B60

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x94CBF0
#define CComboWnd__Draw_x                                          0x94C0F0
#define CComboWnd__GetCurChoice_x                                  0x94CA30
#define CComboWnd__GetListRect_x                                   0x94C5A0
#define CComboWnd__GetTextRect_x                                   0x94CC50
#define CComboWnd__InsertChoice_x                                  0x94C730
#define CComboWnd__SetColors_x                                     0x94C700
#define CComboWnd__SetChoice_x                                     0x94CA00
#define CComboWnd__GetItemCount_x                                  0x94CA40
#define CComboWnd__GetCurChoiceText_x                              0x94CA80
#define CComboWnd__GetChoiceText_x                                 0x94CA50
#define CComboWnd__InsertChoiceAtIndex_x                           0x94C7C0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x7187D0
#define CContainerWnd__vftable_x                                   0xB12434
#define CContainerWnd__SetContainer_x                              0x719D40

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54BE40
#define CDisplay__PreZoneMainUI_x                                  0x54BE50
#define CDisplay__CleanGameUI_x                                    0x5511C0
#define CDisplay__GetClickedActor_x                                0x544160
#define CDisplay__GetUserDefinedColor_x                            0x53C820
#define CDisplay__GetWorldFilePath_x                               0x545BD0
#define CDisplay__is3dON_x                                         0x540DC0
#define CDisplay__ReloadUI_x                                       0x54B2D0
#define CDisplay__WriteTextHD2_x                                   0x540BB0
#define CDisplay__TrueDistance_x                                   0x547890
#define CDisplay__SetViewActor_x                                   0x543A80
#define CDisplay__GetFloorHeight_x                                 0x540E80
#define CDisplay__SetRenderWindow_x                                0x53F7E0
#define CDisplay__ToggleScreenshotMode_x                           0x543550

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x96F630

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x952CC0
#define CEditWnd__GetCharIndexPt_x                                 0x953BE0
#define CEditWnd__GetDisplayString_x                               0x953A80
#define CEditWnd__GetHorzOffset_x                                  0x9522F0
#define CEditWnd__GetLineForPrintableChar_x                        0x954D80
#define CEditWnd__GetSelStartPt_x                                  0x953E90
#define CEditWnd__GetSTMLSafeText_x                                0x9538A0
#define CEditWnd__PointFromPrintableChar_x                         0x9549B0
#define CEditWnd__SelectableCharFromPoint_x                        0x954B20
#define CEditWnd__SetEditable_x                                    0x953F60
#define CEditWnd__SetWindowTextA_x                                 0x953620

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5FCDA0
#define CEverQuest__ClickedPlayer_x                                0x5EEDB0
#define CEverQuest__CreateTargetIndicator_x                        0x60C3C0
#define CEverQuest__DeleteTargetIndicator_x                        0x60C450
#define CEverQuest__DoTellWindow_x                                 0x4E8880
#define CEverQuest__OutputTextToLog_x                              0x4E8B00
#define CEverQuest__DropHeldItemOnGround_x                         0x5E3DF0
#define CEverQuest__dsp_chat_x                                     0x4E8E90
#define CEverQuest__trimName_x                                     0x6086B0
#define CEverQuest__Emote_x                                        0x5FD600
#define CEverQuest__EnterZone_x                                    0x5F7580
#define CEverQuest__GetBodyTypeDesc_x                              0x601F70
#define CEverQuest__GetClassDesc_x                                 0x6025B0
#define CEverQuest__GetClassThreeLetterCode_x                      0x602BB0
#define CEverQuest__GetDeityDesc_x                                 0x60AD00
#define CEverQuest__GetLangDesc_x                                  0x602D70
#define CEverQuest__GetRaceDesc_x                                  0x602590
#define CEverQuest__InterpretCmd_x                                 0x60B2D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5E7FF0
#define CEverQuest__LMouseUp_x                                     0x5E6380
#define CEverQuest__RightClickedOnPlayer_x                         0x5E88D0
#define CEverQuest__RMouseUp_x                                     0x5E7300
#define CEverQuest__SetGameState_x                                 0x5E3B80
#define CEverQuest__UPCNotificationFlush_x                         0x6085B0
#define CEverQuest__IssuePetCommand_x                              0x604170
#define CEverQuest__ReportSuccessfulHit_x                          0x5FE9F0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72A620
#define CGaugeWnd__CalcLinesFillRect_x                             0x72A680
#define CGaugeWnd__Draw_x                                          0x729CA0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF220
#define CGuild__GetGuildName_x                                     0x4AE300
#define CGuild__GetGuildIndex_x                                    0x4AE690

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x745A60

//CHotButton
#define CHotButton__SetButtonSize_x                                0x61DA50

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x752A20
#define CInvSlotMgr__MoveItem_x                                    0x751780
#define CInvSlotMgr__SelectSlot_x                                  0x752AF0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x750000
#define CInvSlot__SliderComplete_x                                 0x74DD50
#define CInvSlot__GetItemBase_x                                    0x74D6E0
#define CInvSlot__UpdateItem_x                                     0x74D850

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x754550
#define CInvSlotWnd__CInvSlotWnd_x                                 0x7536F0
#define CInvSlotWnd__HandleLButtonUp_x                             0x7540D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x80E2B0
#define CItemDisplayWnd__UpdateStrings_x                           0x762CA0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x75CA10
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x75CF30
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x7632B0
#define CItemDisplayWnd__AboutToShow_x                             0x762900
#define CItemDisplayWnd__WndNotification_x                         0x764380
#define CItemDisplayWnd__RequestConvertItem_x                      0x763E50
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x761970
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x762720

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x846D10

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x7688D0

// CLabel 
#define CLabel__Draw_x                                             0x76E310

// CListWnd
#define CListWnd__CListWnd_x                                       0x925590
#define CListWnd__dCListWnd_x                                      0x9258B0
#define CListWnd__AddColumn_x                                      0x929D10
#define CListWnd__AddColumn1_x                                     0x929D60
#define CListWnd__AddLine_x                                        0x92A0F0
#define CListWnd__AddString_x                                      0x929EF0
#define CListWnd__CalculateFirstVisibleLine_x                      0x929AD0
#define CListWnd__CalculateVSBRange_x                              0x9298B0
#define CListWnd__ClearSel_x                                       0x92A8D0
#define CListWnd__ClearAllSel_x                                    0x92A930
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92B330
#define CListWnd__Compare_x                                        0x9291E0
#define CListWnd__Draw_x                                           0x9259E0
#define CListWnd__DrawColumnSeparators_x                           0x9281B0
#define CListWnd__DrawHeader_x                                     0x928620
#define CListWnd__DrawItem_x                                       0x928B20
#define CListWnd__DrawLine_x                                       0x928320
#define CListWnd__DrawSeparator_x                                  0x928250
#define CListWnd__EnableLine_x                                     0x927AA0
#define CListWnd__EnsureVisible_x                                  0x92B260
#define CListWnd__ExtendSel_x                                      0x92A800
#define CListWnd__GetColumnTooltip_x                               0x9275E0
#define CListWnd__GetColumnMinWidth_x                              0x927650
#define CListWnd__GetColumnWidth_x                                 0x927550
#define CListWnd__GetCurSel_x                                      0x926EE0
#define CListWnd__GetItemAtPoint_x                                 0x927D10
#define CListWnd__GetItemAtPoint1_x                                0x927D80
#define CListWnd__GetItemData_x                                    0x926F60
#define CListWnd__GetItemHeight_x                                  0x927320
#define CListWnd__GetItemIcon_x                                    0x9270F0
#define CListWnd__GetItemRect_x                                    0x927B90
#define CListWnd__GetItemText_x                                    0x926FA0
#define CListWnd__GetSelList_x                                     0x92A980
#define CListWnd__GetSeparatorRect_x                               0x927FC0
#define CListWnd__InsertLine_x                                     0x92A4E0
#define CListWnd__RemoveLine_x                                     0x92A630
#define CListWnd__SetColors_x                                      0x929880
#define CListWnd__SetColumnJustification_x                         0x9295B0
#define CListWnd__SetColumnWidth_x                                 0x9294D0
#define CListWnd__SetCurSel_x                                      0x92A740
#define CListWnd__SetItemColor_x                                   0x92AF20
#define CListWnd__SetItemData_x                                    0x92AEE0
#define CListWnd__SetItemText_x                                    0x92AAF0
#define CListWnd__ShiftColumnSeparator_x                           0x929670
#define CListWnd__Sort_x                                           0x929360
#define CListWnd__ToggleSel_x                                      0x92A770
#define CListWnd__SetColumnsSizable_x                              0x929720
#define CListWnd__SetItemWnd_x                                     0x92ADA0
#define CListWnd__GetItemWnd_x                                     0x927140
#define CListWnd__SetItemIcon_x                                    0x92AB70
#define CListWnd__CalculateCustomWindowPositions_x                 0x929BD0
#define CListWnd__SetVScrollPos_x                                  0x9294B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x783B90
#define CMapViewWnd__GetWorldCoordinates_x                         0x7822A0
#define CMapViewWnd__HandleLButtonDown_x                           0x77F2E0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A3D20
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A4600
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A4B30
#define CMerchantWnd__SelectRecoverySlot_x                         0x7A7AB0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A2880
#define CMerchantWnd__SelectBuySellSlot_x                          0x7AD660
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A3930

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A9ED0
#define CPacketScrambler__hton_x                                   0x8A9EC0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x944470
#define CSidlManager__FindScreenPieceTemplate_x                    0x944880
#define CSidlManager__FindScreenPieceTemplate1_x                   0x944670
#define CSidlManager__CreateLabel_x                                0x8056D0
#define CSidlManager__CreateXWndFromTemplate_x                     0x9477E0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x9479C0
#define CSidlManager__CreateXWnd_x                                 0x805600
#define CSidlManager__CreateHotButtonWnd_x                         0x805BD0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x940F50
#define CSidlScreenWnd__CalculateVSBRange_x                        0x940E50
#define CSidlScreenWnd__ConvertToRes_x                             0x966530
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x9408E0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x9405D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9406A0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x940770
#define CSidlScreenWnd__DrawSidlPiece_x                            0x9413F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x9418C0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9415E0
#define CSidlScreenWnd__Init1_x                                    0x9401D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x941910
#define CSidlScreenWnd__LoadIniListWnd_x                           0x942450
#define CSidlScreenWnd__LoadSidlScreen_x                           0x93F5F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x941FD0
#define CSidlScreenWnd__StoreIniVis_x                              0x942330
#define CSidlScreenWnd__WndNotification_x                          0x941300
#define CSidlScreenWnd__GetChildItem_x                             0x941840
#define CSidlScreenWnd__HandleLButtonUp_x                          0x9310B0
#define CSidlScreenWnd__m_layoutCopy_x                             0x15F7FD0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6821D0
#define CSkillMgr__GetSkillCap_x                                   0x6823B0
#define CSkillMgr__GetNameToken_x                                  0x681950
#define CSkillMgr__IsActivatedSkill_x                              0x681A90
#define CSkillMgr__IsCombatSkill_x                                 0x6819D0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9510D0
#define CSliderWnd__SetValue_x                                     0x950F40
#define CSliderWnd__SetNumTicks_x                                  0x950FA0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80B740

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x959900
#define CStmlWnd__CalculateHSBRange_x                              0x95A9E0
#define CStmlWnd__CalculateVSBRange_x                              0x95A950
#define CStmlWnd__CanBreakAtCharacter_x                            0x95ED30
#define CStmlWnd__FastForwardToEndOfTag_x                          0x95F9C0
#define CStmlWnd__ForceParseNow_x                                  0x959EA0
#define CStmlWnd__GetNextTagPiece_x                                0x95EC90
#define CStmlWnd__GetSTMLText_x                                    0x5044D0
#define CStmlWnd__GetVisibleText_x                                 0x959EC0
#define CStmlWnd__InitializeWindowVariables_x                      0x95F810
#define CStmlWnd__MakeStmlColorTag_x                               0x958F70
#define CStmlWnd__MakeWndNotificationTag_x                         0x958FE0
#define CStmlWnd__SetSTMLText_x                                    0x958020
#define CStmlWnd__StripFirstSTMLLines_x                            0x960AC0
#define CStmlWnd__UpdateHistoryString_x                            0x95FBD0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x957140
#define CTabWnd__DrawCurrentPage_x                                 0x957870
#define CTabWnd__DrawTab_x                                         0x957590
#define CTabWnd__GetCurrentPage_x                                  0x956940
#define CTabWnd__GetPageInnerRect_x                                0x956B80
#define CTabWnd__GetTabInnerRect_x                                 0x956AC0
#define CTabWnd__GetTabRect_x                                      0x956970
#define CTabWnd__InsertPage_x                                      0x956D90
#define CTabWnd__SetPage_x                                         0x956C00
#define CTabWnd__SetPageRect_x                                     0x957080
#define CTabWnd__UpdatePage_x                                      0x957450
#define CTabWnd__GetPageFromTabIndex_x                             0x9574D0
#define CTabWnd__GetCurrentTabIndex_x                              0x956930

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x768D10
#define CPageWnd__SetTabText_x                                     0x956490

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8E80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x92DF50
#define CTextureFont__GetTextExtent_x                              0x92E110

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B5440
#define CHtmlComponentWnd__ValidateUri_x                           0x747460
#define CHtmlWnd__SetClientCallbacks_x                             0x622AF0
#define CHtmlWnd__AddObserver_x                                    0x622B10
#define CHtmlWnd__RemoveObserver_x                                 0x622B70
#define Window__getProgress_x                                      0x85F6C0
#define Window__getStatus_x                                        0x85F6E0
#define Window__getURI_x                                           0x85F6F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x96C080

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91B1D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E84D0
#define CXStr__CXStr1_x                                            0x9F20F0
#define CXStr__CXStr3_x                                            0x8FC740
#define CXStr__dCXStr_x                                            0x478790
#define CXStr__operator_equal_x                                    0x8FC970
#define CXStr__operator_equal1_x                                   0x8FC9B0
#define CXStr__operator_plus_equal1_x                              0x8FD440
#define CXStr__SetString_x                                         0x8FF330
#define CXStr__operator_char_p_x                                   0x8FCE80
#define CXStr__GetChar_x                                           0x8FEC80
#define CXStr__Delete_x                                            0x8FE530
#define CXStr__GetUnicode_x                                        0x8FECF0
#define CXStr__GetLength_x                                         0x47D540
#define CXStr__Mid_x                                               0x47D550
#define CXStr__Insert_x                                            0x8FED50
#define CXStr__FindNext_x                                          0x8FE9A0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x94F3A0
#define CXWnd__BringToTop_x                                        0x934800
#define CXWnd__Center_x                                            0x934380
#define CXWnd__ClrFocus_x                                          0x9341A0
#define CXWnd__Destroy_x                                           0x934240
#define CXWnd__DoAllDrawing_x                                      0x930840
#define CXWnd__DrawChildren_x                                      0x930810
#define CXWnd__DrawColoredRect_x                                   0x930CA0
#define CXWnd__DrawTooltip_x                                       0x92F370
#define CXWnd__DrawTooltipAtPoint_x                                0x92F430
#define CXWnd__GetBorderFrame_x                                    0x930B00
#define CXWnd__GetChildWndAt_x                                     0x9348A0
#define CXWnd__GetClientClipRect_x                                 0x932AB0
#define CXWnd__GetScreenClipRect_x                                 0x932B80
#define CXWnd__GetScreenRect_x                                     0x932D50
#define CXWnd__GetTooltipRect_x                                    0x930CF0
#define CXWnd__GetWindowTextA_x                                    0x49CAA0
#define CXWnd__IsActive_x                                          0x931430
#define CXWnd__IsDescendantOf_x                                    0x933730
#define CXWnd__IsReallyVisible_x                                   0x933760
#define CXWnd__IsType_x                                            0x934F20
#define CXWnd__Move_x                                              0x9337D0
#define CXWnd__Move1_x                                             0x933890
#define CXWnd__ProcessTransition_x                                 0x934330
#define CXWnd__Refade_x                                            0x933B70
#define CXWnd__Resize_x                                            0x933E10
#define CXWnd__Right_x                                             0x9345C0
#define CXWnd__SetFocus_x                                          0x934160
#define CXWnd__SetFont_x                                           0x9341D0
#define CXWnd__SetKeyTooltip_x                                     0x934D30
#define CXWnd__SetMouseOver_x                                      0x931C40
#define CXWnd__StartFade_x                                         0x933610
#define CXWnd__GetChildItem_x                                      0x934A10
#define CXWnd__SetParent_x                                         0x933500
#define CXWnd__Minimize_x                                          0x933E70

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x9675B0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x937790
#define CXWndManager__DrawWindows_x                                0x9377B0
#define CXWndManager__GetKeyboardFlags_x                           0x939EA0
#define CXWndManager__HandleKeyboardMsg_x                          0x939A50
#define CXWndManager__RemoveWnd_x                                  0x93A0F0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93A620

// CDBStr
#define CDBStr__GetString_x                                        0x53B7B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB7E0
#define EQ_Character__Cur_HP_x                                     0x4D1FA0
#define EQ_Character__Cur_Mana_x                                   0x4D96E0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE850
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2340
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2490
#define EQ_Character__GetHPRegen_x                                 0x4DF4A0
#define EQ_Character__GetEnduranceRegen_x                          0x4DFAA0
#define EQ_Character__GetManaRegen_x                               0x4DFEE0
#define EQ_Character__Max_Endurance_x                              0x648BC0
#define EQ_Character__Max_HP_x                                     0x4D1DD0
#define EQ_Character__Max_Mana_x                                   0x6489C0
#define EQ_Character__doCombatAbility_x                            0x64B020
#define EQ_Character__UseSkill_x                                   0x4E1CC0
#define EQ_Character__GetConLevel_x                                0x641BD0
#define EQ_Character__IsExpansionFlag_x                            0x5A6340
#define EQ_Character__TotalEffect_x                                0x4C5290
#define EQ_Character__GetPCSpellAffect_x                           0x4BF5A0
#define EQ_Character__SpellDuration_x                              0x4BF0D0
#define EQ_Character__GetAdjustedSkill_x                           0x4D4D20
#define EQ_Character__GetBaseSkill_x                               0x4D5CC0
#define EQ_Character__CanUseItem_x                                 0x4D99F0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C9440

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x65F0C0

//PcClient
#define PcClient__PcClient_x                                       0x63F310

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9450
#define CCharacterListWnd__EnterWorld_x                            0x4B8E90
#define CCharacterListWnd__Quit_x                                  0x4B8BE0
#define CCharacterListWnd__UpdateList_x                            0x4B9020

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x623D40
#define EQ_Item__CreateItemTagString_x                             0x8A36E0
#define EQ_Item__IsStackable_x                                     0x8A8280
#define EQ_Item__GetImageNum_x                                     0x8A5160
#define EQ_Item__CreateItemClient_x                                0x622F10
#define EQ_Item__GetItemValue_x                                    0x8A6460
#define EQ_Item__ValueSellMerchant_x                               0x8A9AA0
#define EQ_Item__IsKeyRingItem_x                                   0x8A7B80
#define EQ_Item__CanGoInBag_x                                      0x623E60
#define EQ_Item__IsEmpty_x                                         0x8A76D0
#define EQ_Item__GetMaxItemCount_x                                 0x8A6880
#define EQ_Item__GetHeldItem_x                                     0x8A5030
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A3040

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x559D10
#define EQ_LoadingS__Array_x                                       0xC26B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x649520
#define EQ_PC__GetAlternateAbilityId_x                             0x8B2CC0
#define EQ_PC__GetCombatAbility_x                                  0x8B3330
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B33A0
#define EQ_PC__GetItemRecastTimer_x                                0x64B5A0
#define EQ_PC__HasLoreItem_x                                       0x642390
#define EQ_PC__AlertInventoryChanged_x                             0x641510
#define EQ_PC__GetPcZoneClient_x                                   0x66DB80
#define EQ_PC__RemoveMyAffect_x                                    0x64E7E0
#define EQ_PC__GetKeyRingItems_x                                   0x8B3C30
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B39C0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B3F30

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AC870
#define EQItemList__add_object_x                                   0x5D96F0
#define EQItemList__add_item_x                                     0x5ACDD0
#define EQItemList__delete_item_x                                  0x5ACE20
#define EQItemList__FreeItemList_x                                 0x5ACD20

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x5381F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x660940
#define EQPlayer__dEQPlayer_x                                      0x653CA0
#define EQPlayer__DoAttack_x                                       0x668830
#define EQPlayer__EQPlayer_x                                       0x654360
#define EQPlayer__SetNameSpriteState_x                             0x658630
#define EQPlayer__SetNameSpriteTint_x                              0x6594F0
#define PlayerBase__HasProperty_j_x                                0x999D70
#define EQPlayer__IsTargetable_x                                   0x99A210
#define EQPlayer__CanSee_x                                         0x99A070
#define EQPlayer__CanSee1_x                                        0x99A140
#define PlayerBase__GetVisibilityLineSegment_x                     0x999E30

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66B610
#define PlayerZoneClient__GetLevel_x                               0x66DBC0
#define PlayerZoneClient__IsValidTeleport_x                        0x5DA860
#define PlayerZoneClient__LegalPlayerRace_x                        0x552FF0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x663720
#define EQPlayerManager__GetSpawnByName_x                          0x6637D0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x663860

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x627430
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x6274B0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x6274F0
#define KeypressHandler__ClearCommandStateArray_x                  0x628900
#define KeypressHandler__HandleKeyDown_x                           0x628920
#define KeypressHandler__HandleKeyUp_x                             0x6289C0
#define KeypressHandler__SaveKeymapping_x                          0x628E10

// MapViewMap 
#define MapViewMap__Clear_x                                        0x77FA00
#define MapViewMap__SaveEx_x                                       0x782DC0
#define MapViewMap__SetZoom_x                                      0x787480

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8C7360

// StringTable 
#define StringTable__getString_x                                   0x8C1F60

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x64E450
#define PcZoneClient__RemovePetEffect_x                            0x64EA80
#define PcZoneClient__HasAlternateAbility_x                        0x6487F0
#define PcZoneClient__GetCurrentMod_x                              0x4E4D70
#define PcZoneClient__GetModCap_x                                  0x4E4C70
#define PcZoneClient__CanEquipItem_x                               0x648EC0
#define PcZoneClient__GetItemByID_x                                0x64BA20
#define PcZoneClient__GetItemByItemClass_x                         0x64BB70
#define PcZoneClient__RemoveBuffEffect_x                           0x64EAA0
#define PcZoneClient__BandolierSwap_x                              0x649AE0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64B540

//Doors
#define EQSwitch__UseSwitch_x                                      0x5DF300

//IconCache
#define IconCache__GetIcon_x                                       0x71FE80

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x717960
#define CContainerMgr__CloseContainer_x                            0x717C30
#define CContainerMgr__OpenExperimentContainer_x                   0x7186B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7D7C60

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61BE60

//CLootWnd
#define CLootWnd__LootAll_x                                        0x775DD0
#define CLootWnd__RequestLootSlot_x                                0x775000

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x579900
#define EQ_Spell__SpellAffects_x                                   0x579D70
#define EQ_Spell__SpellAffectBase_x                                0x579B30
#define EQ_Spell__IsStackable_x                                    0x4C99D0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9820
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6810
#define EQ_Spell__IsSPAStacking_x                                  0x57ABC0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57A0D0
#define EQ_Spell__IsNoRemove_x                                     0x4C99B0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57ABD0
#define __IsResEffectSpell_x                                       0x4C8CB0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACF70

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D1AE0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x81EA30
#define CTargetWnd__WndNotification_x                              0x81E2C0
#define CTargetWnd__RefreshTargetBuffs_x                           0x81E590
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x81D430

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x823030

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x535C60
#define CTaskManager__HandleMessage_x                              0x5340E0
#define CTaskManager__GetTaskStatus_x                              0x535D10
#define CTaskManager__GetElementDescription_x                      0x535D90

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x574E40
#define EqSoundManager__PlayScriptMp3_x                            0x574FA0
#define EqSoundManager__SoundAssistPlay_x                          0x686090
#define EqSoundManager__WaveInstancePlay_x                         0x685600

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x5299A0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x9559A0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5616E0
#define CAltAbilityData__GetMercMaxRank_x                          0x561670
#define CAltAbilityData__GetMaxRank_x                              0x556DB0

//CTargetRing
#define CTargetRing__Cast_x                                        0x619F70

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9800
#define CharacterBase__CreateItemGlobalIndex_x                     0x5111F0
#define CharacterBase__CreateItemIndex_x                           0x6220A0
#define CharacterBase__GetItemPossession_x                         0x4FCC30
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DA100
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DA160
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6FE980
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6FF1B0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6FF260

//messages
#define msg_spell_worn_off_x                                       0x59E630
#define msg_new_text_x                                             0x5933D0
#define __msgTokenTextParam_x                                      0x5A0B60
#define msgTokenText_x                                             0x5A0DB0

//SpellManager
#define SpellManager__vftable_x                                    0xAEC490
#define SpellManager__SpellManager_x                               0x6893C0
#define Spellmanager__LoadTextSpells_x                             0x689CB0
#define SpellManager__GetSpellByGroupAndRank_x                     0x689590

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x99DC50

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x511870
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A48F0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63AA60
#define ItemGlobalIndex__IsValidIndex_x                            0x5118D0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D2480
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D2700

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x76E650

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71C090
#define CCursorAttachment__AttachToCursor1_x                       0x71C0D0
#define CCursorAttachment__Deactivate_x                            0x71D0C0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x948820
#define CSidlManagerBase__CreatePageWnd_x                          0x948010
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x944290
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x944220

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x965650
#define CEQSuiteTextureLoader__GetTexture_x                        0x965310

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x50E760
#define CFindItemWnd__WndNotification_x                            0x50F240
#define CFindItemWnd__Update_x                                     0x50FDB0
#define CFindItemWnd__PickupSelectedItem_x                         0x50DFA0

//IString
#define IString__Append_x                                          0x4FE620

//Camera
#define CDisplay__cameraType_x                                     0xE005D4
#define EverQuest__Cameras_x                                       0xEC3AFC

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x516F40
#define LootFiltersManager__GetItemFilterData_x                    0x516840
#define LootFiltersManager__RemoveItemLootFilter_x                 0x516870
#define LootFiltersManager__SetItemLootFilter_x                    0x516A90

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C5C60

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A3830
#define CResolutionHandler__GetWindowedStyle_x                     0x680BA0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x714740

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8E6D80
#define CDistillerInfo__Instance_x                                 0x8E6D20

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x734820
#define CGroupWnd__UpdateDisplay_x                                 0x733B70

//ItemBase
#define ItemBase__IsLore_x                                         0x8A7C30
#define ItemBase__IsLoreEquipped_x                                 0x8A7CB0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D9650
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D9790
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D97F0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x676290
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x679BF0

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x504AD0

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F1F00
#define FactionManagerClient__HandleFactionMessage_x               0x4F2570
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F2B70
#define FactionManagerClient__GetMaxFaction_x                      0x4F2B8F
#define FactionManagerClient__GetMinFaction_x                      0x4F2B40

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FCC00

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x92CFA0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BDB0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FD030

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x560B80

//CTargetManager
#define CTargetManager__Get_x                                      0x68CC20

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x676290

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8C40

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5ACCC0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF61190

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
