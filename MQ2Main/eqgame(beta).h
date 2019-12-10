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
#define __ExpectedVersionDate                                     "Dec 10 2019"
#define __ExpectedVersionTime                                     "04:22:54"
#define __ActualVersionDate_x                                      0xB0D6BC
#define __ActualVersionTime_x                                      0xB0D6B0
#define __ActualVersionBuild_x                                     0xAF932C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x630E80
#define __MemChecker1_x                                            0x904AB0
#define __MemChecker2_x                                            0x6BF6B0
#define __MemChecker3_x                                            0x6BF600
#define __MemChecker4_x                                            0x85B8F0
#define __EncryptPad0_x                                            0xC443E8
#define __EncryptPad1_x                                            0xCA25E8
#define __EncryptPad2_x                                            0xC54C80
#define __EncryptPad3_x                                            0xC54880
#define __EncryptPad4_x                                            0xC92C00
#define __EncryptPad5_x                                            0xF6E210
#define __AC1_x                                                    0x8183F6
#define __AC2_x                                                    0x5EAB8F
#define __AC3_x                                                    0x5F228F
#define __AC4_x                                                    0x5F6260
#define __AC5_x                                                    0x5FC56F
#define __AC6_x                                                    0x600B86
#define __AC7_x                                                    0x5EA600
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x193E2C

// Direct Input
#define DI8__Main_x                                                0xF6E238
#define DI8__Keyboard_x                                            0xF6E23C
#define DI8__Mouse_x                                               0xF6E21C
#define DI8__Mouse_Copy_x                                          0xEC741C
#define DI8__Mouse_Check_x                                         0xF6BD64
#define __AutoSkillArray_x                                         0xEC8334
#define __Attack_x                                                 0xF6615B
#define __Autofire_x                                               0xF6615C
#define __BindList_x                                               0xC32E20
#define g_eqCommandStates_x                                        0xC33BA0
#define __Clicks_x                                                 0xEC74D4
#define __CommandList_x                                            0xC34760
#define __CurrentMapLabel_x                                        0xF7EBDC
#define __CurrentSocial_x                                          0xC1C7CC
#define __DoAbilityList_x                                          0xEFDC7C
#define __do_loot_x                                                0x5B6560
#define __DrawHandler_x                                            0x15FDF50
#define __GroupCount_x                                             0xEB9DD2
#define __Guilds_x                                                 0xEBDC28
#define __gWorld_x                                                 0xEB9C88
#define __HWnd_x                                                   0xF6E220
#define __heqmain_x                                                0xF6E1F8
#define __InChatMode_x                                             0xEC7404
#define __LastTell_x                                               0xEC9378
#define __LMouseHeldTime_x                                         0xEC7540
#define __Mouse_x                                                  0xF6E224
#define __MouseLook_x                                              0xEC749A
#define __MouseEventTime_x                                         0xF66C3C
#define __gpbCommandEvent_x                                        0xEB76C0
#define __NetStatusToggle_x                                        0xEC749D
#define __PCNames_x                                                0xEC8924
#define __RangeAttackReady_x                                       0xEC8618
#define __RMouseHeldTime_x                                         0xEC753C
#define __RunWalkState_x                                           0xEC7408
#define __ScreenMode_x                                             0xE050A0
#define __ScreenX_x                                                0xEC73BC
#define __ScreenY_x                                                0xEC73B8
#define __ScreenXMax_x                                             0xEC73C0
#define __ScreenYMax_x                                             0xEC73C4
#define __ServerHost_x                                             0xEB78F3
#define __ServerName_x                                             0xEFDC3C
#define __ShiftKeyDown_x                                           0xEC7A94
#define __ShowNames_x                                              0xEC87D4
#define __Socials_x                                                0xEFDD3C
#define __SubscriptionType_x                                       0xFC30E0
#define __TargetAggroHolder_x                                      0xF81590
#define __ZoneType_x                                               0xEC7898
#define __GroupAggro_x                                             0xF815D0
#define __LoginName_x                                              0xF6E98C
#define __Inviter_x                                                0xF660D8
#define __AttackOnAssist_x                                         0xEC8790
#define __UseTellWindows_x                                         0xEC8AC0
#define __gfMaxZoomCameraDistance_x                                0xB02FC0
#define __gfMaxCameraDistance_x                                    0xB2F514
#define __pulAutoRun_x                                             0xEC74B8
#define __pulForward_x                                             0xEC8AF8
#define __pulBackward_x                                            0xEC8AFC
#define __pulTurnRight_x                                           0xEC8B00
#define __pulTurnLeft_x                                            0xEC8B04
#define __pulStrafeLeft_x                                          0xEC8B08
#define __pulStrafeRight_x                                         0xEC8B0C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEB9FC8
#define instEQZoneInfo_x                                           0xEC7690
#define pinstActiveBanker_x                                        0xEB76D8
#define pinstActiveCorpse_x                                        0xEB76D0
#define pinstActiveGMaster_x                                       0xEB76D4
#define pinstActiveMerchant_x                                      0xEB76CC
#define pinstAltAdvManager_x                                       0xE06200
#define pinstBandageTarget_x                                       0xEB76E8
#define pinstCamActor_x                                            0xE05094
#define pinstCDBStr_x                                              0xE04F1C
#define pinstCDisplay_x                                            0xEB9C84
#define pinstCEverQuest_x                                          0xF6E250
#define pinstEverQuestInfo_x                                       0xEC73B0
#define pinstCharData_x                                            0xEB9DB4
#define pinstCharSpawn_x                                           0xEB7720
#define pinstControlledMissile_x                                   0xEB7C0C
#define pinstControlledPlayer_x                                    0xEB7720
#define pinstCResolutionHandler_x                                  0x15FE180
#define pinstCSidlManager_x                                        0x15FD118
#define pinstCXWndManager_x                                        0x15FD114
#define instDynamicZone_x                                          0xEBDB00
#define pinstDZMember_x                                            0xEBDC10
#define pinstDZTimerInfo_x                                         0xEBDC14
#define pinstEqLogin_x                                             0xF6E2D8
#define instEQMisc_x                                               0xE04E60
#define pinstEQSoundManager_x                                      0xE071D0
#define pinstEQSpellStrings_x                                      0xCC7878
#define instExpeditionLeader_x                                     0xEBDB4A
#define instExpeditionName_x                                       0xEBDB8A
#define pinstGroup_x                                               0xEB9DCE
#define pinstImeManager_x                                          0x15FD110
#define pinstLocalPlayer_x                                         0xEB76C8
#define pinstMercenaryData_x                                       0xF6872C
#define pinstMercenaryStats_x                                      0xF816DC
#define pinstModelPlayer_x                                         0xEB76E0
#define pinstPCData_x                                              0xEB9DB4
#define pinstSkillMgr_x                                            0xF6A898
#define pinstSpawnManager_x                                        0xF69340
#define pinstSpellManager_x                                        0xF6AAB8
#define pinstSpellSets_x                                           0xF5ED84
#define pinstStringTable_x                                         0xEB9DB8
#define pinstSwitchManager_x                                       0xEB7568
#define pinstTarget_x                                              0xEB771C
#define pinstTargetObject_x                                        0xEB77A8
#define pinstTargetSwitch_x                                        0xEB9C28
#define pinstTaskMember_x                                          0xE04CF0
#define pinstTrackTarget_x                                         0xEB7724
#define pinstTradeTarget_x                                         0xEB76DC
#define instTributeActive_x                                        0xE04E81
#define pinstViewActor_x                                           0xE05090
#define pinstWorldData_x                                           0xEB7C08
#define pinstZoneAddr_x                                            0xEC7930
#define pinstPlayerPath_x                                          0xF693D8
#define pinstTargetIndicator_x                                     0xF6AD20
#define EQObject_Top_x                                             0xEB76C4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE057F0
#define pinstCAchievementsWnd_x                                    0xE057EC
#define pinstCActionsWnd_x                                         0xE057B4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE05024
#define pinstCAdvancedLootWnd_x                                    0xE04FE4
#define pinstCAdventureLeaderboardWnd_x                            0xF783B0
#define pinstCAdventureRequestWnd_x                                0xF78460
#define pinstCAdventureStatsWnd_x                                  0xF78510
#define pinstCAggroMeterWnd_x                                      0xE05144
#define pinstCAlarmWnd_x                                           0xE0584C
#define pinstCAlertHistoryWnd_x                                    0xE05044
#define pinstCAlertStackWnd_x                                      0xE04FB8
#define pinstCAlertWnd_x                                           0xE04FC8
#define pinstCAltStorageWnd_x                                      0xF78870
#define pinstCAudioTriggersWindow_x                                0xCB9BA8
#define pinstCAuraWnd_x                                            0xE05068
#define pinstCAvaZoneWnd_x                                         0xE04FFC
#define pinstCBandolierWnd_x                                       0xE0513C
#define pinstCBankWnd_x                                            0xE05064
#define pinstCBarterMerchantWnd_x                                  0xF79AB0
#define pinstCBarterSearchWnd_x                                    0xF79B60
#define pinstCBarterWnd_x                                          0xF79C10
#define pinstCBazaarConfirmationWnd_x                              0xE05818
#define pinstCBazaarSearchWnd_x                                    0xE0558C
#define pinstCBazaarWnd_x                                          0xE05834
#define pinstCBlockedBuffWnd_x                                     0xE0506C
#define pinstCBlockedPetBuffWnd_x                                  0xE050C4
#define pinstCBodyTintWnd_x                                        0xE057C4
#define pinstCBookWnd_x                                            0xE05568
#define pinstCBreathWnd_x                                          0xE05808
#define pinstCBuffWindowNORMAL_x                                   0xE05048
#define pinstCBuffWindowSHORT_x                                    0xE0504C
#define pinstCBugReportWnd_x                                       0xE0505C
#define pinstCButtonWnd_x                                          0x15FD380
#define pinstCCastingWnd_x                                         0xE0555C
#define pinstCCastSpellWnd_x                                       0xE05804
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE05838
#define pinstCChatWindowManager_x                                  0xF7A6D0
#define pinstCClaimWnd_x                                           0xF7A828
#define pinstCColorPickerWnd_x                                     0xE057BC
#define pinstCCombatAbilityWnd_x                                   0xE05844
#define pinstCCombatSkillsSelectWnd_x                              0xE04FCC
#define pinstCCompassWnd_x                                         0xE057B8
#define pinstCConfirmationDialog_x                                 0xF7F728
#define pinstCContainerMgr_x                                       0xE0582C
#define pinstCContextMenuManager_x                                 0x15FD0D0
#define pinstCCursorAttachment_x                                   0xE05550
#define pinstCDynamicZoneWnd_x                                     0xF7ADF0
#define pinstCEditLabelWnd_x                                       0xE05040
#define pinstCEQMainWnd_x                                          0xF7B038
#define pinstCEventCalendarWnd_x                                   0xE05554
#define pinstCExtendedTargetWnd_x                                  0xE050B8
#define pinstCFacePick_x                                           0xE04FDC
#define pinstCFactionWnd_x                                         0xE05828
#define pinstCFellowshipWnd_x                                      0xF7B238
#define pinstCFileSelectionWnd_x                                   0xE05558
#define pinstCFindItemWnd_x                                        0xE05814
#define pinstCFindLocationWnd_x                                    0xF7B390
#define pinstCFriendsWnd_x                                         0xE04FE0
#define pinstCGemsGameWnd_x                                        0xE05824
#define pinstCGiveWnd_x                                            0xE05850
#define pinstCGroupSearchFiltersWnd_x                              0xE05560
#define pinstCGroupSearchWnd_x                                     0xF7B788
#define pinstCGroupWnd_x                                           0xF7B838
#define pinstCGuildBankWnd_x                                       0xEC8774
#define pinstCGuildCreationWnd_x                                   0xF7B998
#define pinstCGuildMgmtWnd_x                                       0xF7BA48
#define pinstCharacterCreation_x                                   0xE04FD4
#define pinstCHelpWnd_x                                            0xE05018
#define pinstCHeritageSelectionWnd_x                               0xE04FE8
#define pinstCHotButtonWnd_x                                       0xF7DBA0
#define pinstCHotButtonWnd1_x                                      0xF7DBA0
#define pinstCHotButtonWnd2_x                                      0xF7DBA4
#define pinstCHotButtonWnd3_x                                      0xF7DBA8
#define pinstCHotButtonWnd4_x                                      0xF7DBAC
#define pinstCIconSelectionWnd_x                                   0xE0554C
#define pinstCInspectWnd_x                                         0xE05014
#define pinstCInventoryWnd_x                                       0xE04FEC
#define pinstCInvSlotMgr_x                                         0xE057E8
#define pinstCItemDisplayManager_x                                 0xF7E130
#define pinstCItemExpTransferWnd_x                                 0xF7E260
#define pinstCItemOverflowWnd_x                                    0xE05590
#define pinstCJournalCatWnd_x                                      0xE0556C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE050BC
#define pinstCKeyRingWnd_x                                         0xE05034
#define pinstCLargeDialogWnd_x                                     0xF803A8
#define pinstCLayoutCopyWnd_x                                      0xF7E5B0
#define pinstCLFGuildWnd_x                                         0xF7E660
#define pinstCLoadskinWnd_x                                        0xE05830
#define pinstCLootFiltersCopyWnd_x                                 0xCD61F8
#define pinstCLootFiltersWnd_x                                     0xE04FBC
#define pinstCLootSettingsWnd_x                                    0xE04FD8
#define pinstCLootWnd_x                                            0xE05570
#define pinstCMailAddressBookWnd_x                                 0xE057F4
#define pinstCMailCompositionWnd_x                                 0xE057D4
#define pinstCMailIgnoreListWnd_x                                  0xE057F8
#define pinstCMailWnd_x                                            0xE057B0
#define pinstCManageLootWnd_x                                      0xE066B0
#define pinstCMapToolbarWnd_x                                      0xE05020
#define pinstCMapViewWnd_x                                         0xE04FF8
#define pinstCMarketplaceWnd_x                                     0xE04FC0
#define pinstCMerchantWnd_x                                        0xE05574
#define pinstCMIZoneSelectWnd_x                                    0xF7EE98
#define pinstCMusicPlayerWnd_x                                     0xE05588
#define pinstCNameChangeMercWnd_x                                  0xE05810
#define pinstCNameChangePetWnd_x                                   0xE057FC
#define pinstCNameChangeWnd_x                                      0xE05820
#define pinstCNoteWnd_x                                            0xE05000
#define pinstCObjectPreviewWnd_x                                   0xE04FD0
#define pinstCOptionsWnd_x                                         0xE05004
#define pinstCPetInfoWnd_x                                         0xE05598
#define pinstCPetitionQWnd_x                                       0xE057DC
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE057C8
#define pinstCPlayerWnd_x                                          0xE0559C
#define pinstCPopupWndManager_x                                    0xF7F728
#define pinstCProgressionSelectionWnd_x                            0xF7F7D8
#define pinstCPurchaseGroupWnd_x                                   0xE0500C
#define pinstCPurchaseWnd_x                                        0xE04FF0
#define pinstCPvPLeaderboardWnd_x                                  0xF7F888
#define pinstCPvPStatsWnd_x                                        0xF7F938
#define pinstCQuantityWnd_x                                        0xE050C0
#define pinstCRaceChangeWnd_x                                      0xE05848
#define pinstCRaidOptionsWnd_x                                     0xE05564
#define pinstCRaidWnd_x                                            0xE057D8
#define pinstCRealEstateItemsWnd_x                                 0xE057E4
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE05578
#define pinstCRealEstateManageWnd_x                                0xE0501C
#define pinstCRealEstateNeighborhoodWnd_x                          0xE05038
#define pinstCRealEstatePlotSearchWnd_x                            0xE05060
#define pinstCRealEstatePurchaseWnd_x                              0xE050B4
#define pinstCRespawnWnd_x                                         0xE050B0
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE05800
#define pinstCSendMoneyWnd_x                                       0xE04FC4
#define pinstCServerListWnd_x                                      0xE05140
#define pinstCSkillsSelectWnd_x                                    0xE0583C
#define pinstCSkillsWnd_x                                          0xE0581C
#define pinstCSocialEditWnd_x                                      0xE0502C
#define pinstCSocialWnd_x                                          0xE0580C
#define pinstCSpellBookWnd_x                                       0xE05840
#define pinstCStoryWnd_x                                           0xE055A4
#define pinstCTargetOfTargetWnd_x                                  0xF81760
#define pinstCTargetWnd_x                                          0xE050AC
#define pinstCTaskOverlayWnd_x                                     0xE05008
#define pinstCTaskSelectWnd_x                                      0xF818B8
#define pinstCTaskManager_x                                        0xCD6B38
#define pinstCTaskTemplateSelectWnd_x                              0xF81968
#define pinstCTaskWnd_x                                            0xF81A18
#define pinstCTextEntryWnd_x                                       0xE05050
#define pinstCTimeLeftWnd_x                                        0xE055AC
#define pinstCTipWndCONTEXT_x                                      0xF81C1C
#define pinstCTipWndOFDAY_x                                        0xF81C18
#define pinstCTitleWnd_x                                           0xF81CC8
#define pinstCTrackingWnd_x                                        0xE04FF4
#define pinstCTradeskillWnd_x                                      0xF81E30
#define pinstCTradeWnd_x                                           0xE057D0
#define pinstCTrainWnd_x                                           0xE057CC
#define pinstCTributeBenefitWnd_x                                  0xF82030
#define pinstCTributeMasterWnd_x                                   0xF820E0
#define pinstCTributeTrophyWnd_x                                   0xF82190
#define pinstCVideoModesWnd_x                                      0xE055A0
#define pinstCVoiceMacroWnd_x                                      0xF6B488
#define pinstCVoteResultsWnd_x                                     0xE057E0
#define pinstCVoteWnd_x                                            0xE057C0
#define pinstCWebManager_x                                         0xF6BB04
#define pinstCZoneGuideWnd_x                                       0xE05010
#define pinstCZonePathWnd_x                                        0xE05028

#define pinstEQSuiteTextureLoader_x                                0xCA40C0
#define pinstItemIconCache_x                                       0xF7AFF0
#define pinstLootFiltersManager_x                                  0xCD62A8
#define pinstRewardSelectionWnd_x                                  0xF80080

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5B19C0
#define __CastRay2_x                                               0x5B1A10
#define __ConvertItemTags_x                                        0x5CD560
#define __CleanItemTags_x                                          0x47D120
#define __DoesFileExist_x                                          0x907B90
#define __EQGetTime_x                                              0x904580
#define __ExecuteCmd_x                                             0x5AA230
#define __FixHeading_x                                             0x99FA90
#define __GameLoop_x                                               0x6BE8A0
#define __get_bearing_x                                            0x5B1530
#define __get_melee_range_x                                        0x5B1C00
#define __GetAnimationCache_x                                      0x723DF0
#define __GetGaugeValueFromEQ_x                                    0x8168A0
#define __GetLabelFromEQ_x                                         0x818380
#define __GetXTargetType_x                                         0x9A14E0
#define __HandleMouseWheel_x                                       0x6BF760
#define __HeadingDiff_x                                            0x99FB00
#define __HelpPath_x                                               0xF6682C
#define __LoadFrontEnd_x                                           0x6BBBC0
#define __NewUIINI_x                                               0x816570
#define __ProcessGameEvents_x                                      0x612330
#define __ProcessMouseEvent_x                                      0x611AF0
#define __SaveColors_x                                             0x553660
#define __STMLToText_x                                             0x942F60
#define __ToggleKeyRingItem_x                                      0x516A50
#define CMemoryMappedFile__SetFile_x                               0xA8ED00
#define CrashDetected_x                                            0x6BD660
#define DrawNetStatus_x                                            0x63E120
#define Expansion_HoT_x                                            0xEC877C
#define Teleport_Table_Size_x                                      0xEB77B0
#define Teleport_Table_x                                           0xEB7C28
#define Util__FastTime_x                                           0x904150

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4904F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499410
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x4991E0
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493A90
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492EE0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x55B2E0
#define AltAdvManager__IsAbilityReady_x                            0x55A210
#define AltAdvManager__GetAAById_x                                 0x55A410
#define AltAdvManager__CanTrainAbility_x                           0x55A480
#define AltAdvManager__CanSeeAbility_x                             0x55A7E0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CA310
#define CharacterZoneClient__HasSkill_x                            0x4D5200
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6920
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE550
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BAB50
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D92E0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D93C0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D94A0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C3350
#define CharacterZoneClient__BardCastBard_x                        0x4C5EB0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BAC20
#define CharacterZoneClient__GetEffect_x                           0x4BAA90
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C43A0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C4470
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C44C0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4610
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C47E0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B29D0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D7880
#define CharacterZoneClient__FindItemByRecord_x                    0x4D7300

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6E5420
#define CBankWnd__WndNotification_x                                0x6E5200

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6F2AB0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x620C80
#define CButtonWnd__CButtonWnd_x                                   0x93F330

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x712EF0
#define CChatManager__InitContextMenu_x                            0x70C040
#define CChatManager__FreeChatWindow_x                             0x711A30
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E89B0
#define CChatManager__SetLockedActiveChatWindow_x                  0x712B70
#define CChatManager__CreateChatWindow_x                           0x712070

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8AC0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9539B0
#define CContextMenu__dCContextMenu_x                              0x953BE0
#define CContextMenu__AddMenuItem_x                                0x953BF0
#define CContextMenu__RemoveMenuItem_x                             0x953EF0
#define CContextMenu__RemoveAllMenuItems_x                         0x953F10
#define CContextMenu__CheckMenuItem_x                              0x953F90
#define CContextMenu__SetMenuItem_x                                0x953E20
#define CContextMenu__AddSeparator_x                               0x953D80

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x954530
#define CContextMenuManager__RemoveMenu_x                          0x9545A0
#define CContextMenuManager__PopupMenu_x                           0x954660
#define CContextMenuManager__Flush_x                               0x9544D0
#define CContextMenuManager__GetMenu_x                             0x49B530
#define CContextMenuManager__CreateDefaultMenu_x                   0x71E5E0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8DFBA0
#define CChatService__GetFriendName_x                              0x8DFBB0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7137A0
#define CChatWindow__Clear_x                                       0x714A70
#define CChatWindow__WndNotification_x                             0x715200
#define CChatWindow__AddHistory_x                                  0x714330

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x950E20
#define CComboWnd__Draw_x                                          0x950320
#define CComboWnd__GetCurChoice_x                                  0x950C60
#define CComboWnd__GetListRect_x                                   0x9507D0
#define CComboWnd__GetTextRect_x                                   0x950E80
#define CComboWnd__InsertChoice_x                                  0x950960
#define CComboWnd__SetColors_x                                     0x950930
#define CComboWnd__SetChoice_x                                     0x950C30
#define CComboWnd__GetItemCount_x                                  0x950C70
#define CComboWnd__GetCurChoiceText_x                              0x950CB0
#define CComboWnd__GetChoiceText_x                                 0x950C80
#define CComboWnd__InsertChoiceAtIndex_x                           0x9509F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x71BFD0
#define CContainerWnd__vftable_x                                   0xB168AC
#define CContainerWnd__SetContainer_x                              0x71D530

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x54E090
#define CDisplay__PreZoneMainUI_x                                  0x54E0A0
#define CDisplay__CleanGameUI_x                                    0x553420
#define CDisplay__GetClickedActor_x                                0x5463B0
#define CDisplay__GetUserDefinedColor_x                            0x53EA70
#define CDisplay__GetWorldFilePath_x                               0x547E20
#define CDisplay__is3dON_x                                         0x543010
#define CDisplay__ReloadUI_x                                       0x54D520
#define CDisplay__WriteTextHD2_x                                   0x542E00
#define CDisplay__TrueDistance_x                                   0x549AE0
#define CDisplay__SetViewActor_x                                   0x545CD0
#define CDisplay__GetFloorHeight_x                                 0x5430D0
#define CDisplay__SetRenderWindow_x                                0x541A30
#define CDisplay__ToggleScreenshotMode_x                           0x5457A0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x973770

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x956F10
#define CEditWnd__GetCharIndexPt_x                                 0x957E30
#define CEditWnd__GetDisplayString_x                               0x957CD0
#define CEditWnd__GetHorzOffset_x                                  0x956540
#define CEditWnd__GetLineForPrintableChar_x                        0x958FD0
#define CEditWnd__GetSelStartPt_x                                  0x9580E0
#define CEditWnd__GetSTMLSafeText_x                                0x957AF0
#define CEditWnd__PointFromPrintableChar_x                         0x958C00
#define CEditWnd__SelectableCharFromPoint_x                        0x958D70
#define CEditWnd__SetEditable_x                                    0x9581B0
#define CEditWnd__SetWindowTextA_x                                 0x957870

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x600060
#define CEverQuest__ClickedPlayer_x                                0x5F2070
#define CEverQuest__CreateTargetIndicator_x                        0x60F5C0
#define CEverQuest__DeleteTargetIndicator_x                        0x60F650
#define CEverQuest__DoTellWindow_x                                 0x4E8BA0
#define CEverQuest__OutputTextToLog_x                              0x4E8E20
#define CEverQuest__DropHeldItemOnGround_x                         0x5E70B0
#define CEverQuest__dsp_chat_x                                     0x4E91B0
#define CEverQuest__trimName_x                                     0x60B8B0
#define CEverQuest__Emote_x                                        0x6008C0
#define CEverQuest__EnterZone_x                                    0x5FA840
#define CEverQuest__GetBodyTypeDesc_x                              0x605180
#define CEverQuest__GetClassDesc_x                                 0x6057C0
#define CEverQuest__GetClassThreeLetterCode_x                      0x605DC0
#define CEverQuest__GetDeityDesc_x                                 0x60DF00
#define CEverQuest__GetLangDesc_x                                  0x605F80
#define CEverQuest__GetRaceDesc_x                                  0x6057A0
#define CEverQuest__InterpretCmd_x                                 0x60E4D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5EB2B0
#define CEverQuest__LMouseUp_x                                     0x5E9640
#define CEverQuest__RightClickedOnPlayer_x                         0x5EBB90
#define CEverQuest__RMouseUp_x                                     0x5EA5C0
#define CEverQuest__SetGameState_x                                 0x5E6E40
#define CEverQuest__UPCNotificationFlush_x                         0x60B7B0
#define CEverQuest__IssuePetCommand_x                              0x607380
#define CEverQuest__ReportSuccessfulHit_x                          0x601C10

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x72DF00
#define CGaugeWnd__CalcLinesFillRect_x                             0x72DF60
#define CGaugeWnd__Draw_x                                          0x72D590

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF430
#define CGuild__GetGuildName_x                                     0x4AE510
#define CGuild__GetGuildIndex_x                                    0x4AE8A0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x7493E0

//CHotButton
#define CHotButton__SetButtonSize_x                                0x621040

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x756410
#define CInvSlotMgr__MoveItem_x                                    0x755120
#define CInvSlotMgr__SelectSlot_x                                  0x7564E0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x7539A0
#define CInvSlot__SliderComplete_x                                 0x7516F0
#define CInvSlot__GetItemBase_x                                    0x751060
#define CInvSlot__UpdateItem_x                                     0x7511D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x757F60
#define CInvSlotWnd__CInvSlotWnd_x                                 0x757100
#define CInvSlotWnd__HandleLButtonUp_x                             0x757AE0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x811C40
#define CItemDisplayWnd__UpdateStrings_x                           0x766720
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x760400
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x760930
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x766D30
#define CItemDisplayWnd__AboutToShow_x                             0x766360
#define CItemDisplayWnd__WndNotification_x                         0x767E20
#define CItemDisplayWnd__RequestConvertItem_x                      0x7678E0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7653C0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x766180

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x84A5B0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x76C360

// CLabel 
#define CLabel__Draw_x                                             0x771ED0

// CListWnd
#define CListWnd__CListWnd_x                                       0x929560
#define CListWnd__dCListWnd_x                                      0x929880
#define CListWnd__AddColumn_x                                      0x92DCF0
#define CListWnd__AddColumn1_x                                     0x92DD40
#define CListWnd__AddLine_x                                        0x92E0D0
#define CListWnd__AddString_x                                      0x92DED0
#define CListWnd__CalculateFirstVisibleLine_x                      0x92DAB0
#define CListWnd__CalculateVSBRange_x                              0x92D890
#define CListWnd__ClearSel_x                                       0x92E8B0
#define CListWnd__ClearAllSel_x                                    0x92E910
#define CListWnd__CloseAndUpdateEditWindow_x                       0x92F310
#define CListWnd__Compare_x                                        0x92D1C0
#define CListWnd__Draw_x                                           0x9299B0
#define CListWnd__DrawColumnSeparators_x                           0x92C190
#define CListWnd__DrawHeader_x                                     0x92C600
#define CListWnd__DrawItem_x                                       0x92CB00
#define CListWnd__DrawLine_x                                       0x92C300
#define CListWnd__DrawSeparator_x                                  0x92C230
#define CListWnd__EnableLine_x                                     0x92BA70
#define CListWnd__EnsureVisible_x                                  0x92F240
#define CListWnd__ExtendSel_x                                      0x92E7E0
#define CListWnd__GetColumnTooltip_x                               0x92B5B0
#define CListWnd__GetColumnMinWidth_x                              0x92B620
#define CListWnd__GetColumnWidth_x                                 0x92B520
#define CListWnd__GetCurSel_x                                      0x92AEB0
#define CListWnd__GetItemAtPoint_x                                 0x92BCE0
#define CListWnd__GetItemAtPoint1_x                                0x92BD50
#define CListWnd__GetItemData_x                                    0x92AF30
#define CListWnd__GetItemHeight_x                                  0x92B2F0
#define CListWnd__GetItemIcon_x                                    0x92B0C0
#define CListWnd__GetItemRect_x                                    0x92BB60
#define CListWnd__GetItemText_x                                    0x92AF70
#define CListWnd__GetSelList_x                                     0x92E960
#define CListWnd__GetSeparatorRect_x                               0x92BF90
#define CListWnd__InsertLine_x                                     0x92E4C0
#define CListWnd__RemoveLine_x                                     0x92E610
#define CListWnd__SetColors_x                                      0x92D860
#define CListWnd__SetColumnJustification_x                         0x92D590
#define CListWnd__SetColumnWidth_x                                 0x92D4B0
#define CListWnd__SetCurSel_x                                      0x92E720
#define CListWnd__SetItemColor_x                                   0x92EF00
#define CListWnd__SetItemData_x                                    0x92EEC0
#define CListWnd__SetItemText_x                                    0x92EAD0
#define CListWnd__ShiftColumnSeparator_x                           0x92D650
#define CListWnd__Sort_x                                           0x92D340
#define CListWnd__ToggleSel_x                                      0x92E750
#define CListWnd__SetColumnsSizable_x                              0x92D700
#define CListWnd__SetItemWnd_x                                     0x92ED80
#define CListWnd__GetItemWnd_x                                     0x92B110
#define CListWnd__SetItemIcon_x                                    0x92EB50
#define CListWnd__CalculateCustomWindowPositions_x                 0x92DBB0
#define CListWnd__SetVScrollPos_x                                  0x92D490

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x787690
#define CMapViewWnd__GetWorldCoordinates_x                         0x785DA0
#define CMapViewWnd__HandleLButtonDown_x                           0x782DE0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7A7800
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7A80E0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7A8610
#define CMerchantWnd__SelectRecoverySlot_x                         0x7AB5A0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7A6360
#define CMerchantWnd__SelectBuySellSlot_x                          0x7B1160
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7A7410

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8AD720
#define CPacketScrambler__hton_x                                   0x8AD710

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9485A0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9489B0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9487A0
#define CSidlManager__CreateLabel_x                                0x8090D0
#define CSidlManager__CreateXWndFromTemplate_x                     0x94B910
#define CSidlManager__CreateXWndFromTemplate1_x                    0x94BAF0
#define CSidlManager__CreateXWnd_x                                 0x809000
#define CSidlManager__CreateHotButtonWnd_x                         0x8095D0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x945090
#define CSidlScreenWnd__CalculateVSBRange_x                        0x944F90
#define CSidlScreenWnd__ConvertToRes_x                             0x96A7B0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x944A20
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x944710
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9447E0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9448B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x945530
#define CSidlScreenWnd__EnableIniStorage_x                         0x945A00
#define CSidlScreenWnd__GetSidlPiece_x                             0x945720
#define CSidlScreenWnd__Init1_x                                    0x944310
#define CSidlScreenWnd__LoadIniInfo_x                              0x945A50
#define CSidlScreenWnd__LoadIniListWnd_x                           0x946570
#define CSidlScreenWnd__LoadSidlScreen_x                           0x943710
#define CSidlScreenWnd__StoreIniInfo_x                             0x9460F0
#define CSidlScreenWnd__StoreIniVis_x                              0x946450
#define CSidlScreenWnd__WndNotification_x                          0x945440
#define CSidlScreenWnd__GetChildItem_x                             0x945980
#define CSidlScreenWnd__HandleLButtonUp_x                          0x935080
#define CSidlScreenWnd__m_layoutCopy_x                             0x15FCFA0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x685720
#define CSkillMgr__GetSkillCap_x                                   0x685900
#define CSkillMgr__GetNameToken_x                                  0x684EA0
#define CSkillMgr__IsActivatedSkill_x                              0x684FE0
#define CSkillMgr__IsCombatSkill_x                                 0x684F20

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x955320
#define CSliderWnd__SetValue_x                                     0x955190
#define CSliderWnd__SetNumTicks_x                                  0x9551F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x80F0D0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x95DB20
#define CStmlWnd__CalculateHSBRange_x                              0x95EC00
#define CStmlWnd__CalculateVSBRange_x                              0x95EB70
#define CStmlWnd__CanBreakAtCharacter_x                            0x962F50
#define CStmlWnd__FastForwardToEndOfTag_x                          0x963BE0
#define CStmlWnd__ForceParseNow_x                                  0x95E0C0
#define CStmlWnd__GetNextTagPiece_x                                0x962EB0
#define CStmlWnd__GetSTMLText_x                                    0x506340
#define CStmlWnd__GetVisibleText_x                                 0x95E0E0
#define CStmlWnd__InitializeWindowVariables_x                      0x963A30
#define CStmlWnd__MakeStmlColorTag_x                               0x95D190
#define CStmlWnd__MakeWndNotificationTag_x                         0x95D200
#define CStmlWnd__SetSTMLText_x                                    0x95C240
#define CStmlWnd__StripFirstSTMLLines_x                            0x964CE0
#define CStmlWnd__UpdateHistoryString_x                            0x963DF0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x95B390
#define CTabWnd__DrawCurrentPage_x                                 0x95BAC0
#define CTabWnd__DrawTab_x                                         0x95B7E0
#define CTabWnd__GetCurrentPage_x                                  0x95AB90
#define CTabWnd__GetPageInnerRect_x                                0x95ADD0
#define CTabWnd__GetTabInnerRect_x                                 0x95AD10
#define CTabWnd__GetTabRect_x                                      0x95ABC0
#define CTabWnd__InsertPage_x                                      0x95AFE0
#define CTabWnd__SetPage_x                                         0x95AE50
#define CTabWnd__SetPageRect_x                                     0x95B2D0
#define CTabWnd__UpdatePage_x                                      0x95B6A0
#define CTabWnd__GetPageFromTabIndex_x                             0x95B720
#define CTabWnd__GetCurrentTabIndex_x                              0x95AB80

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x76C7A0
#define CPageWnd__SetTabText_x                                     0x95A6E0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A90D0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x931F30
#define CTextureFont__GetTextExtent_x                              0x9320F0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6B8A70
#define CHtmlComponentWnd__ValidateUri_x                           0x74ADD0
#define CHtmlWnd__SetClientCallbacks_x                             0x6260F0
#define CHtmlWnd__AddObserver_x                                    0x626110
#define CHtmlWnd__RemoveObserver_x                                 0x626170
#define Window__getProgress_x                                      0x862EE0
#define Window__getStatus_x                                        0x862F00
#define Window__getURI_x                                           0x862F10

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x970200

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x91F220

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E87F0
#define CXStr__CXStr1_x                                            0x501430
#define CXStr__CXStr3_x                                            0x900680
#define CXStr__dCXStr_x                                            0x4787B0
#define CXStr__operator_equal_x                                    0x9008B0
#define CXStr__operator_equal1_x                                   0x9008F0
#define CXStr__operator_plus_equal1_x                              0x901380
#define CXStr__SetString_x                                         0x903270
#define CXStr__operator_char_p_x                                   0x900DF0
#define CXStr__GetChar_x                                           0x902BA0
#define CXStr__Delete_x                                            0x902470
#define CXStr__GetUnicode_x                                        0x902C10
#define CXStr__GetLength_x                                         0x4A8E80
#define CXStr__Mid_x                                               0x47D4D0
#define CXStr__Insert_x                                            0x902C70
#define CXStr__FindNext_x                                          0x9028E0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9535D0
#define CXWnd__BringToTop_x                                        0x938810
#define CXWnd__Center_x                                            0x938390
#define CXWnd__ClrFocus_x                                          0x9381B0
#define CXWnd__Destroy_x                                           0x938250
#define CXWnd__DoAllDrawing_x                                      0x934810
#define CXWnd__DrawChildren_x                                      0x9347E0
#define CXWnd__DrawColoredRect_x                                   0x934C70
#define CXWnd__DrawTooltip_x                                       0x933330
#define CXWnd__DrawTooltipAtPoint_x                                0x9333F0
#define CXWnd__GetBorderFrame_x                                    0x934AD0
#define CXWnd__GetChildWndAt_x                                     0x9388B0
#define CXWnd__GetClientClipRect_x                                 0x936AD0
#define CXWnd__GetScreenClipRect_x                                 0x936BA0
#define CXWnd__GetScreenRect_x                                     0x936D70
#define CXWnd__GetTooltipRect_x                                    0x934CC0
#define CXWnd__GetWindowTextA_x                                    0x49CCA0
#define CXWnd__IsActive_x                                          0x935400
#define CXWnd__IsDescendantOf_x                                    0x937750
#define CXWnd__IsReallyVisible_x                                   0x937780
#define CXWnd__IsType_x                                            0x938F30
#define CXWnd__Move_x                                              0x9377F0
#define CXWnd__Move1_x                                             0x9378A0
#define CXWnd__ProcessTransition_x                                 0x938340
#define CXWnd__Refade_x                                            0x937B50
#define CXWnd__Resize_x                                            0x937DF0
#define CXWnd__Right_x                                             0x9385D0
#define CXWnd__SetFocus_x                                          0x938170
#define CXWnd__SetFont_x                                           0x9381E0
#define CXWnd__SetKeyTooltip_x                                     0x938D40
#define CXWnd__SetMouseOver_x                                      0x935C40
#define CXWnd__StartFade_x                                         0x937630
#define CXWnd__GetChildItem_x                                      0x938A20
#define CXWnd__SetParent_x                                         0x9374E0
#define CXWnd__Minimize_x                                          0x937E60

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x96B830

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x93B700
#define CXWndManager__DrawWindows_x                                0x93B720
#define CXWndManager__GetKeyboardFlags_x                           0x93DF10
#define CXWndManager__HandleKeyboardMsg_x                          0x93DAC0
#define CXWndManager__RemoveWnd_x                                  0x93E140
#define CXWndManager__RemovePendingDeletionWnd_x                   0x93E6C0

// CDBStr
#define CDBStr__GetString_x                                        0x53DA10

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BBB30
#define EQ_Character__Cur_HP_x                                     0x4D2240
#define EQ_Character__Cur_Mana_x                                   0x4D99A0
#define EQ_Character__GetCastingTimeModifier_x                     0x4BEBA0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2610
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2760
#define EQ_Character__GetHPRegen_x                                 0x4DF770
#define EQ_Character__GetEnduranceRegen_x                          0x4DFD70
#define EQ_Character__GetManaRegen_x                               0x4E01B0
#define EQ_Character__Max_Endurance_x                              0x64C000
#define EQ_Character__Max_HP_x                                     0x4D2070
#define EQ_Character__Max_Mana_x                                   0x64BE00
#define EQ_Character__doCombatAbility_x                            0x64E460
#define EQ_Character__UseSkill_x                                   0x4E1F90
#define EQ_Character__GetConLevel_x                                0x645090
#define EQ_Character__IsExpansionFlag_x                            0x5A8A00
#define EQ_Character__TotalEffect_x                                0x4C55F0
#define EQ_Character__GetPCSpellAffect_x                           0x4BF8F0
#define EQ_Character__SpellDuration_x                              0x4BF420
#define EQ_Character__GetAdjustedSkill_x                           0x4D4FC0
#define EQ_Character__GetBaseSkill_x                               0x4D5F60
#define EQ_Character__CanUseItem_x                                 0x4D9CB0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8CCA50

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x662570

//PcClient
#define PcClient__PcClient_x                                       0x6427C0

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B97A0
#define CCharacterListWnd__EnterWorld_x                            0x4B91E0
#define CCharacterListWnd__Quit_x                                  0x4B8F30
#define CCharacterListWnd__UpdateList_x                            0x4B9370

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x627350
#define EQ_Item__CreateItemTagString_x                             0x8A6F40
#define EQ_Item__IsStackable_x                                     0x8ABAD0
#define EQ_Item__GetImageNum_x                                     0x8A89D0
#define EQ_Item__CreateItemClient_x                                0x626510
#define EQ_Item__GetItemValue_x                                    0x8A9CE0
#define EQ_Item__ValueSellMerchant_x                               0x8AD300
#define EQ_Item__IsKeyRingItem_x                                   0x8AB3F0
#define EQ_Item__CanGoInBag_x                                      0x627470
#define EQ_Item__IsEmpty_x                                         0x8AAF20
#define EQ_Item__GetMaxItemCount_x                                 0x8AA0F0
#define EQ_Item__GetHeldItem_x                                     0x8A88A0
#define EQ_Item__GetAugmentFitBySlot_x                             0x8A68B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x55BFF0
#define EQ_LoadingS__Array_x                                       0xC2BB60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x64C960
#define EQ_PC__GetAlternateAbilityId_x                             0x8B6540
#define EQ_PC__GetCombatAbility_x                                  0x8B6BB0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8B6C20
#define EQ_PC__GetItemRecastTimer_x                                0x64E9E0
#define EQ_PC__HasLoreItem_x                                       0x6458A0
#define EQ_PC__AlertInventoryChanged_x                             0x6449C0
#define EQ_PC__GetPcZoneClient_x                                   0x671000
#define EQ_PC__RemoveMyAffect_x                                    0x651C10
#define EQ_PC__GetKeyRingItems_x                                   0x8B74B0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8B7240
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8B77B0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5AEF60
#define EQItemList__add_object_x                                   0x5DC8B0
#define EQItemList__add_item_x                                     0x5AF4C0
#define EQItemList__delete_item_x                                  0x5AF510
#define EQItemList__FreeItemList_x                                 0x5AF410

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x53A600

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x663DF0
#define EQPlayer__dEQPlayer_x                                      0x657140
#define EQPlayer__DoAttack_x                                       0x66BC90
#define EQPlayer__EQPlayer_x                                       0x657800
#define EQPlayer__SetNameSpriteState_x                             0x65BAD0
#define EQPlayer__SetNameSpriteTint_x                              0x65C9A0
#define PlayerBase__HasProperty_j_x                                0x99DE50
#define EQPlayer__IsTargetable_x                                   0x99E2F0
#define EQPlayer__CanSee_x                                         0x99E150
#define EQPlayer__CanSee1_x                                        0x99E220
#define PlayerBase__GetVisibilityLineSegment_x                     0x99DF10

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x66EA90
#define PlayerZoneClient__GetLevel_x                               0x671040
#define PlayerZoneClient__IsValidTeleport_x                        0x5DDA20
#define PlayerZoneClient__LegalPlayerRace_x                        0x555330

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x666BB0
#define EQPlayerManager__GetSpawnByName_x                          0x666C60
#define EQPlayerManager__GetPlayerFromPartialName_x                0x666CF0

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x62A9A0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x62AA20
#define KeypressHandler__AttachKeyToEqCommand_x                    0x62AA60
#define KeypressHandler__ClearCommandStateArray_x                  0x62BE70
#define KeypressHandler__HandleKeyDown_x                           0x62BE90
#define KeypressHandler__HandleKeyUp_x                             0x62BF30
#define KeypressHandler__SaveKeymapping_x                          0x62C380

// MapViewMap 
#define MapViewMap__Clear_x                                        0x783500
#define MapViewMap__SaveEx_x                                       0x7868C0
#define MapViewMap__SetZoom_x                                      0x78AF80

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8CA970

// StringTable 
#define StringTable__getString_x                                   0x8C5790

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x651880
#define PcZoneClient__RemovePetEffect_x                            0x651EB0
#define PcZoneClient__HasAlternateAbility_x                        0x64BC30
#define PcZoneClient__GetCurrentMod_x                              0x4E5050
#define PcZoneClient__GetModCap_x                                  0x4E4F50
#define PcZoneClient__CanEquipItem_x                               0x64C300
#define PcZoneClient__GetItemByID_x                                0x64EE50
#define PcZoneClient__GetItemByItemClass_x                         0x64EFA0
#define PcZoneClient__RemoveBuffEffect_x                           0x651ED0
#define PcZoneClient__BandolierSwap_x                              0x64CF20
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x64E980

//Doors
#define EQSwitch__UseSwitch_x                                      0x5E25A0

//IconCache
#define IconCache__GetIcon_x                                       0x723690

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x71B170
#define CContainerMgr__CloseContainer_x                            0x71B440
#define CContainerMgr__OpenExperimentContainer_x                   0x71BEC0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7DB640

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x61F440

//CLootWnd
#define CLootWnd__LootAll_x                                        0x7799D0
#define CLootWnd__RequestLootSlot_x                                0x778C00

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x57C300
#define EQ_Spell__SpellAffects_x                                   0x57C770
#define EQ_Spell__SpellAffectBase_x                                0x57C530
#define EQ_Spell__IsStackable_x                                    0x4C9C80
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C9B30
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B6AE0
#define EQ_Spell__IsSPAStacking_x                                  0x57D5C0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x57CAD0
#define EQ_Spell__IsNoRemove_x                                     0x4C9C60
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x57D5D0
#define __IsResEffectSpell_x                                       0x4C9030

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD1B0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8D5060

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x822320
#define CTargetWnd__WndNotification_x                              0x821BB0
#define CTargetWnd__RefreshTargetBuffs_x                           0x821E80
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x820D10

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x826920

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x538030
#define CTaskManager__HandleMessage_x                              0x5364E0
#define CTaskManager__GetTaskStatus_x                              0x5380E0
#define CTaskManager__GetElementDescription_x                      0x538160

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x577870
#define EqSoundManager__PlayScriptMp3_x                            0x5779D0
#define EqSoundManager__SoundAssistPlay_x                          0x6896C0
#define EqSoundManager__WaveInstancePlay_x                         0x688C30

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x52B930

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x959BF0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x5639D0
#define CAltAbilityData__GetMercMaxRank_x                          0x563960
#define CAltAbilityData__GetMaxRank_x                              0x559090

//CTargetRing
#define CTargetRing__Cast_x                                        0x61D560

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C9B10
#define CharacterBase__CreateItemGlobalIndex_x                     0x512FD0
#define CharacterBase__CreateItemIndex_x                           0x6256A0
#define CharacterBase__GetItemPossession_x                         0x4FECC0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8DD670
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8DD6D0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x7022D0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x702B00
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x702BB0

//messages
#define msg_spell_worn_off_x                                       0x5A0B60
#define msg_new_text_x                                             0x5958E0
#define __msgTokenTextParam_x                                      0x5A3090
#define msgTokenText_x                                             0x5A32E0

//SpellManager
#define SpellManager__vftable_x                                    0xAF068C
#define SpellManager__SpellManager_x                               0x68C9F0
#define Spellmanager__LoadTextSpells_x                             0x68D2E0
#define SpellManager__GetSpellByGroupAndRank_x                     0x68CBC0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9A1DD0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x513650
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5A6E30
#define ItemGlobalIndex__IsEquippedLocation_x                      0x63DF80
#define ItemGlobalIndex__IsValidIndex_x                            0x5136B0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8D5A00
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8D5C80

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x772210

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x71F880
#define CCursorAttachment__AttachToCursor1_x                       0x71F8C0
#define CCursorAttachment__Deactivate_x                            0x7208B0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x94C950
#define CSidlManagerBase__CreatePageWnd_x                          0x94C140
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9483C0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x948350

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x969DC0
#define CEQSuiteTextureLoader__GetTexture_x                        0x969A80

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x510570
#define CFindItemWnd__WndNotification_x                            0x511050
#define CFindItemWnd__Update_x                                     0x511BC0
#define CFindItemWnd__PickupSelectedItem_x                         0x50FDB0

//IString
#define IString__Append_x                                          0x4F1700

//Camera
#define CDisplay__cameraType_x                                     0xE055A8
#define EverQuest__Cameras_x                                       0xEC8ACC

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x518DF0
#define LootFiltersManager__GetItemFilterData_x                    0x5186F0
#define LootFiltersManager__RemoveItemLootFilter_x                 0x518720
#define LootFiltersManager__SetItemLootFilter_x                    0x518940

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7C95F0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9A7900
#define CResolutionHandler__GetWindowedStyle_x                     0x6840A0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x717F10

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8EACB0
#define CDistillerInfo__Instance_x                                 0x8EAC50

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x738140
#define CGroupWnd__UpdateDisplay_x                                 0x737490

//ItemBase
#define ItemBase__IsLore_x                                         0x8AB4A0
#define ItemBase__IsLoreEquipped_x                                 0x8AB510

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5DC810
#define EQPlacedItemManager__GetItemByGuid_x                       0x5DC950
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5DC9B0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x679790
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x67D130

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x506940

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F3600
#define FactionManagerClient__HandleFactionMessage_x               0x4F3C70
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F4270
#define FactionManagerClient__GetMaxFaction_x                      0x4F428F
#define FactionManagerClient__GetMinFaction_x                      0x4F4240

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4FEC90

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x930F80

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BFB0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4FEFF0

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x562E70

//CTargetManager
#define CTargetManager__Get_x                                      0x690240

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x679790

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8E90

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5AF3B0

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF66160

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
