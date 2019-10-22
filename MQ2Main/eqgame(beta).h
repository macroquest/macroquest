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
#define __ExpectedVersionDate                                     "Oct 22 2019"
#define __ExpectedVersionTime                                     "04:22:46"
#define __ActualVersionDate_x                                      0xAFC9C0
#define __ActualVersionTime_x                                      0xAFC9B4
#define __ActualVersionBuild_x                                     0xAE8644

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Beta)"
#define __MacroQuestWinName                                       "MacroQuest2(Beta)"

// Memory Protection
#define __MemChecker0_x                                            0x624CC0
#define __MemChecker1_x                                            0x8F68D0
#define __MemChecker2_x                                            0x6B2C20
#define __MemChecker3_x                                            0x6B2B70
#define __MemChecker4_x                                            0x84EBA0
#define __EncryptPad0_x                                            0xC323F0
#define __EncryptPad1_x                                            0xC905B0
#define __EncryptPad2_x                                            0xC42C88
#define __EncryptPad3_x                                            0xC42888
#define __EncryptPad4_x                                            0xC80C08
#define __EncryptPad5_x                                            0xF59CA8
#define __AC1_x                                                    0x80B596
#define __AC2_x                                                    0x5DEB9F
#define __AC3_x                                                    0x5E629F
#define __AC4_x                                                    0x5EA260
#define __AC5_x                                                    0x5F056F
#define __AC6_x                                                    0x5F4B86
#define __AC7_x                                                    0x5DE610
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1B273C

// Direct Input
#define DI8__Main_x                                                0xF5C184
#define DI8__Keyboard_x                                            0xF5C188
#define DI8__Mouse_x                                               0xF5C1A0
#define DI8__Mouse_Copy_x                                          0xEB5374
#define DI8__Mouse_Check_x                                         0xF59CD0
#define __AutoSkillArray_x                                         0xEB628C
#define __Attack_x                                                 0xF540B3
#define __Autofire_x                                               0xF540B4
#define __BindList_x                                               0xC20E20
#define g_eqCommandStates_x                                        0xC21BA0
#define __Clicks_x                                                 0xEB542C
#define __CommandList_x                                            0xC22760
#define __CurrentMapLabel_x                                        0xF6CB34
#define __CurrentSocial_x                                          0xC0A7CC
#define __DoAbilityList_x                                          0xEEBBD4
#define __do_loot_x                                                0x5AAFE0
#define __DrawHandler_x                                            0x15EBEA8
#define __GroupCount_x                                             0xEA776A
#define __Guilds_x                                                 0xEABB80
#define __gWorld_x                                                 0xEA761C
#define __HWnd_x                                                   0xF5C1A4
#define __heqmain_x                                                0xF5C178
#define __InChatMode_x                                             0xEB535C
#define __LastTell_x                                               0xEB72D0
#define __LMouseHeldTime_x                                         0xEB5498
#define __Mouse_x                                                  0xF5C164
#define __MouseLook_x                                              0xEB53F2
#define __MouseEventTime_x                                         0xF54B94
#define __gpbCommandEvent_x                                        0xEA7960
#define __NetStatusToggle_x                                        0xEB53F5
#define __PCNames_x                                                0xEB687C
#define __RangeAttackReady_x                                       0xEB6570
#define __RMouseHeldTime_x                                         0xEB5494
#define __RunWalkState_x                                           0xEB5360
#define __ScreenMode_x                                             0xDF2F44
#define __ScreenX_x                                                0xEB5314
#define __ScreenY_x                                                0xEB5310
#define __ScreenXMax_x                                             0xEB5318
#define __ScreenYMax_x                                             0xEB531C
#define __ServerHost_x                                             0xEA7BBB
#define __ServerName_x                                             0xEEBB94
#define __ShiftKeyDown_x                                           0xEB59EC
#define __ShowNames_x                                              0xEB672C
#define __Socials_x                                                0xEEBC94
#define __SubscriptionType_x                                       0xFB1038
#define __TargetAggroHolder_x                                      0xF6F4E8
#define __ZoneType_x                                               0xEB57F0
#define __GroupAggro_x                                             0xF6F528
#define __LoginName_x                                              0xF5C8DC
#define __Inviter_x                                                0xF54030
#define __AttackOnAssist_x                                         0xEB66E8
#define __UseTellWindows_x                                         0xEB6A18
#define __gfMaxZoomCameraDistance_x                                0xAF22B8
#define __gfMaxCameraDistance_x                                    0xB1E83C
#define __pulAutoRun_x                                             0xEB5410
#define __pulForward_x                                             0xEB6A50
#define __pulBackward_x                                            0xEB6A54
#define __pulTurnRight_x                                           0xEB6A58
#define __pulTurnLeft_x                                            0xEB6A5C
#define __pulStrafeLeft_x                                          0xEB6A60
#define __pulStrafeRight_x                                         0xEB6A64

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xEA7F18
#define instEQZoneInfo_x                                           0xEB55E8
#define pinstActiveBanker_x                                        0xEA7978
#define pinstActiveCorpse_x                                        0xEA7970
#define pinstActiveGMaster_x                                       0xEA7974
#define pinstActiveMerchant_x                                      0xEA796C
#define pinstAltAdvManager_x                                       0xDF4148
#define pinstBandageTarget_x                                       0xEA7988
#define pinstCamActor_x                                            0xDF2F38
#define pinstCDBStr_x                                              0xDF2E64
#define pinstCDisplay_x                                            0xEA7620
#define pinstCEverQuest_x                                          0xF5C19C
#define pinstEverQuestInfo_x                                       0xEB5308
#define pinstCharData_x                                            0xEA774C
#define pinstCharSpawn_x                                           0xEA7A40
#define pinstControlledMissile_x                                   0xEA7F10
#define pinstControlledPlayer_x                                    0xEA7A40
#define pinstCResolutionHandler_x                                  0x15EC0D8
#define pinstCSidlManager_x                                        0x15EB070
#define pinstCXWndManager_x                                        0x15EB06C
#define instDynamicZone_x                                          0xEABA58
#define pinstDZMember_x                                            0xEABB68
#define pinstDZTimerInfo_x                                         0xEABB6C
#define pinstEqLogin_x                                             0xF5C228
#define instEQMisc_x                                               0xDF2DA8
#define pinstEQSoundManager_x                                      0xDF5118
#define pinstEQSpellStrings_x                                      0xCB5868
#define instExpeditionLeader_x                                     0xEABAA2
#define instExpeditionName_x                                       0xEABAE2
#define pinstGroup_x                                               0xEA7766
#define pinstImeManager_x                                          0x15EB068
#define pinstLocalPlayer_x                                         0xEA7968
#define pinstMercenaryData_x                                       0xF5668C
#define pinstMercenaryStats_x                                      0xF6F634
#define pinstModelPlayer_x                                         0xEA7980
#define pinstPCData_x                                              0xEA774C
#define pinstSkillMgr_x                                            0xF587F0
#define pinstSpawnManager_x                                        0xF57298
#define pinstSpellManager_x                                        0xF58A10
#define pinstSpellSets_x                                           0xF4CCDC
#define pinstStringTable_x                                         0xEA7750
#define pinstSwitchManager_x                                       0xEA54B8
#define pinstTarget_x                                              0xEA79A4
#define pinstTargetObject_x                                        0xEA7A48
#define pinstTargetSwitch_x                                        0xEA5614
#define pinstTaskMember_x                                          0xDF2C38
#define pinstTrackTarget_x                                         0xEA7A44
#define pinstTradeTarget_x                                         0xEA797C
#define instTributeActive_x                                        0xDF2DC9
#define pinstViewActor_x                                           0xDF2F34
#define pinstWorldData_x                                           0xEA5608
#define pinstZoneAddr_x                                            0xEB5888
#define pinstPlayerPath_x                                          0xF57330
#define pinstTargetIndicator_x                                     0xF58C78
#define EQObject_Top_x                                             0xEA7964
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xDF31F8
#define pinstCAchievementsWnd_x                                    0xDF2F90
#define pinstCActionsWnd_x                                         0xDF2FBC
#define pinstCAdvancedDisplayOptionsWnd_x                          0xDF376C
#define pinstCAdvancedLootWnd_x                                    0xDF32C4
#define pinstCAdventureLeaderboardWnd_x                            0xF66308
#define pinstCAdventureRequestWnd_x                                0xF663B8
#define pinstCAdventureStatsWnd_x                                  0xF66468
#define pinstCAggroMeterWnd_x                                      0xDF2F28
#define pinstCAlarmWnd_x                                           0xDF3264
#define pinstCAlertHistoryWnd_x                                    0xDF32BC
#define pinstCAlertStackWnd_x                                      0xDF320C
#define pinstCAlertWnd_x                                           0xDF3220
#define pinstCAltStorageWnd_x                                      0xF667C8
#define pinstCAudioTriggersWindow_x                                0xCA7B98
#define pinstCAuraWnd_x                                            0xDF3798
#define pinstCAvaZoneWnd_x                                         0xDF3224
#define pinstCBandolierWnd_x                                       0xDF2F24
#define pinstCBankWnd_x                                            0xDF3794
#define pinstCBarterMerchantWnd_x                                  0xF67A08
#define pinstCBarterSearchWnd_x                                    0xF67AB8
#define pinstCBarterWnd_x                                          0xF67B68
#define pinstCBazaarConfirmationWnd_x                              0xDF2FC8
#define pinstCBazaarSearchWnd_x                                    0xDF2F84
#define pinstCBazaarWnd_x                                          0xDF324C
#define pinstCBlockedBuffWnd_x                                     0xDF2F00
#define pinstCBlockedPetBuffWnd_x                                  0xDF2F20
#define pinstCBodyTintWnd_x                                        0xDF2FD0
#define pinstCBookWnd_x                                            0xDF2F64
#define pinstCBreathWnd_x                                          0xDF3218
#define pinstCBuffWindowNORMAL_x                                   0xDF3784
#define pinstCBuffWindowSHORT_x                                    0xDF3788
#define pinstCBugReportWnd_x                                       0xDF3790
#define pinstCButtonWnd_x                                          0x15EB2D8
#define pinstCCastingWnd_x                                         0xDF2F54
#define pinstCCastSpellWnd_x                                       0xDF3210
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xDF3250
#define pinstCChatWindowManager_x                                  0xF68628
#define pinstCClaimWnd_x                                           0xF68780
#define pinstCColorPickerWnd_x                                     0xDF2FC4
#define pinstCCombatAbilityWnd_x                                   0xDF325C
#define pinstCCombatSkillsSelectWnd_x                              0xDF3284
#define pinstCCompassWnd_x                                         0xDF2FC0
#define pinstCConfirmationDialog_x                                 0xF6D680
#define pinstCContainerMgr_x                                       0xDF3244
#define pinstCContextMenuManager_x                                 0x15EB028
#define pinstCCursorAttachment_x                                   0xDF2F30
#define pinstCDynamicZoneWnd_x                                     0xF68D48
#define pinstCEditLabelWnd_x                                       0xDF3778
#define pinstCEQMainWnd_x                                          0xF68F90
#define pinstCEventCalendarWnd_x                                   0xDF3780
#define pinstCExtendedTargetWnd_x                                  0xDF2F14
#define pinstCFacePick_x                                           0xDF32B4
#define pinstCFactionWnd_x                                         0xDF323C
#define pinstCFellowshipWnd_x                                      0xF69190
#define pinstCFileSelectionWnd_x                                   0xDF2F50
#define pinstCFindItemWnd_x                                        0xDF3230
#define pinstCFindLocationWnd_x                                    0xF692E8
#define pinstCFriendsWnd_x                                         0xDF32C0
#define pinstCGemsGameWnd_x                                        0xDF3238
#define pinstCGiveWnd_x                                            0xDF3268
#define pinstCGroupSearchFiltersWnd_x                              0xDF2F5C
#define pinstCGroupSearchWnd_x                                     0xF696E0
#define pinstCGroupWnd_x                                           0xF69790
#define pinstCGuildBankWnd_x                                       0xEB66CC
#define pinstCGuildCreationWnd_x                                   0xF698F0
#define pinstCGuildMgmtWnd_x                                       0xF699A0
#define pinstCharacterCreation_x                                   0xDF328C
#define pinstCHelpWnd_x                                            0xDF3764
#define pinstCHeritageSelectionWnd_x                               0xDF32C8
#define pinstCHotButtonWnd_x                                       0xF6BAF8
#define pinstCHotButtonWnd1_x                                      0xF6BAF8
#define pinstCHotButtonWnd2_x                                      0xF6BAFC
#define pinstCHotButtonWnd3_x                                      0xF6BB00
#define pinstCHotButtonWnd4_x                                      0xF6BB04
#define pinstCIconSelectionWnd_x                                   0xDF2F2C
#define pinstCInspectWnd_x                                         0xDF3760
#define pinstCInventoryWnd_x                                       0xDF32CC
#define pinstCInvSlotMgr_x                                         0xDF2FF4
#define pinstCItemDisplayManager_x                                 0xF6C088
#define pinstCItemExpTransferWnd_x                                 0xF6C1BC
#define pinstCItemOverflowWnd_x                                    0xDF2F8C
#define pinstCJournalCatWnd_x                                      0xDF2F6C
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xDF2F18
#define pinstCKeyRingWnd_x                                         0xDF3774
#define pinstCLargeDialogWnd_x                                     0xF6E300
#define pinstCLayoutCopyWnd_x                                      0xF6C508
#define pinstCLFGuildWnd_x                                         0xF6C5B8
#define pinstCLoadskinWnd_x                                        0xDF3248
#define pinstCLootFiltersCopyWnd_x                                 0xCC4140
#define pinstCLootFiltersWnd_x                                     0xDF3214
#define pinstCLootSettingsWnd_x                                    0xDF322C
#define pinstCLootWnd_x                                            0xDF2F70
#define pinstCMailAddressBookWnd_x                                 0xDF3200
#define pinstCMailCompositionWnd_x                                 0xDF2FE4
#define pinstCMailIgnoreListWnd_x                                  0xDF3204
#define pinstCMailWnd_x                                            0xDF2FB8
#define pinstCManageLootWnd_x                                      0xDF45F8
#define pinstCMapToolbarWnd_x                                      0xDF3768
#define pinstCMapViewWnd_x                                         0xDF32E8
#define pinstCMarketplaceWnd_x                                     0xDF321C
#define pinstCMerchantWnd_x                                        0xDF2F74
#define pinstCMIZoneSelectWnd_x                                    0xF6CDF0
#define pinstCMusicPlayerWnd_x                                     0xDF2F7C
#define pinstCNameChangeMercWnd_x                                  0xDF2FB4
#define pinstCNameChangePetWnd_x                                   0xDF2F94
#define pinstCNameChangeWnd_x                                      0xDF2FDC
#define pinstCNoteWnd_x                                            0xDF3354
#define pinstCObjectPreviewWnd_x                                   0xDF3228
#define pinstCOptionsWnd_x                                         0xDF3758
#define pinstCPetInfoWnd_x                                         0xDF2F98
#define pinstCPetitionQWnd_x                                       0xDF2F80
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xDF2FD4
#define pinstCPlayerWnd_x                                          0xDF2F9C
#define pinstCPopupWndManager_x                                    0xF6D680
#define pinstCProgressionSelectionWnd_x                            0xF6D730
#define pinstCPurchaseGroupWnd_x                                   0xDF3270
#define pinstCPurchaseWnd_x                                        0xDF3240
#define pinstCPvPLeaderboardWnd_x                                  0xF6D7E0
#define pinstCPvPStatsWnd_x                                        0xF6D890
#define pinstCQuantityWnd_x                                        0xDF2F1C
#define pinstCRaceChangeWnd_x                                      0xDF31FC
#define pinstCRaidOptionsWnd_x                                     0xDF2F60
#define pinstCRaidWnd_x                                            0xDF2FE8
#define pinstCRealEstateItemsWnd_x                                 0xDF2F88
#define pinstCRealEstateLayoutDetailsWnd_x                         0xDF2F08
#define pinstCRealEstateManageWnd_x                                0xDF3278
#define pinstCRealEstateNeighborhoodWnd_x                          0xDF32B8
#define pinstCRealEstatePlotSearchWnd_x                            0xDF32D0
#define pinstCRealEstatePurchaseWnd_x                              0xDF375C
#define pinstCRespawnWnd_x                                         0xDF2F0C
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xDF3208
#define pinstCSendMoneyWnd_x                                       0xDF3280
#define pinstCServerListWnd_x                                      0xDF377C
#define pinstCSkillsSelectWnd_x                                    0xDF3254
#define pinstCSkillsWnd_x                                          0xDF3234
#define pinstCSocialEditWnd_x                                      0xDF3770
#define pinstCSocialWnd_x                                          0xDF2FAC
#define pinstCSpellBookWnd_x                                       0xDF3258
#define pinstCStoryWnd_x                                           0xDF2FA0
#define pinstCTargetOfTargetWnd_x                                  0xF6F6B8
#define pinstCTargetWnd_x                                          0xDF2F04
#define pinstCTaskOverlayWnd_x                                     0xDF326C
#define pinstCTaskSelectWnd_x                                      0xF6F810
#define pinstCTaskManager_x                                        0xCC4A80
#define pinstCTaskTemplateSelectWnd_x                              0xF6F8C0
#define pinstCTaskWnd_x                                            0xF6F970
#define pinstCTextEntryWnd_x                                       0xDF378C
#define pinstCTimeLeftWnd_x                                        0xDF2F58
#define pinstCTipWndCONTEXT_x                                      0xF6FB74
#define pinstCTipWndOFDAY_x                                        0xF6FB70
#define pinstCTitleWnd_x                                           0xF6FC20
#define pinstCTrackingWnd_x                                        0xDF32D4
#define pinstCTradeskillWnd_x                                      0xF6FD88
#define pinstCTradeWnd_x                                           0xDF2FE0
#define pinstCTrainWnd_x                                           0xDF2FD8
#define pinstCTributeBenefitWnd_x                                  0xF6FF88
#define pinstCTributeMasterWnd_x                                   0xF70038
#define pinstCTributeTrophyWnd_x                                   0xF700E8
#define pinstCVideoModesWnd_x                                      0xDF2FEC
#define pinstCVoiceMacroWnd_x                                      0xF593E0
#define pinstCVoteResultsWnd_x                                     0xDF2F78
#define pinstCVoteWnd_x                                            0xDF2F68
#define pinstCWebManager_x                                         0xF59A5C
#define pinstCZoneGuideWnd_x                                       0xDF3274
#define pinstCZonePathWnd_x                                        0xDF3288

#define pinstEQSuiteTextureLoader_x                                0xC92088
#define pinstItemIconCache_x                                       0xF68F48
#define pinstLootFiltersManager_x                                  0xCC41F0
#define pinstRewardSelectionWnd_x                                  0xF6DFD8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5A6440
#define __CastRay2_x                                               0x5A6490
#define __ConvertItemTags_x                                        0x5C1FE0
#define __CleanItemTags_x                                          0x47D0A0
#define __DoesFileExist_x                                          0x8F99B0
#define __EQGetTime_x                                              0x8F63A0
#define __ExecuteCmd_x                                             0x59ECF0
#define __FixHeading_x                                             0x990AD0
#define __GameLoop_x                                               0x6B1E10
#define __get_bearing_x                                            0x5A5FB0
#define __get_melee_range_x                                        0x5A6680
#define __GetAnimationCache_x                                      0x716FC0
#define __GetGaugeValueFromEQ_x                                    0x809A40
#define __GetLabelFromEQ_x                                         0x80B520
#define __GetXTargetType_x                                         0x992660
#define __HandleMouseWheel_x                                       0x6B2CD0
#define __HeadingDiff_x                                            0x990B40
#define __HelpPath_x                                               0xF54784
#define __LoadFrontEnd_x                                           0x6AF130
#define __NewUIINI_x                                               0x809710
#define __ProcessGameEvents_x                                      0x6063F0
#define __ProcessMouseEvent_x                                      0x605BB0
#define __SaveColors_x                                             0x54CA50
#define __STMLToText_x                                             0x934080
#define __ToggleKeyRingItem_x                                      0x50FD90
#define CMemoryMappedFile__SetFile_x                               0xA7FF20
#define CrashDetected_x                                            0x6B0BD0
#define DrawNetStatus_x                                            0x631FB0
#define Expansion_HoT_x                                            0xEB66D4
#define Teleport_Table_Size_x                                      0xEA7A64
#define Teleport_Table_x                                           0xEA5618
#define Util__FastTime_x                                           0x8F5F70

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490380
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499270
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499040
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493910
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x492D60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x554520
#define AltAdvManager__IsAbilityReady_x                            0x553490
#define AltAdvManager__GetAAById_x                                 0x553690
#define AltAdvManager__CanTrainAbility_x                           0x553700
#define AltAdvManager__CanSeeAbility_x                             0x553A60

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4C9F30
#define CharacterZoneClient__HasSkill_x                            0x4D4E20
#define CharacterZoneClient__MakeMeVisible_x                       0x4D6540
#define CharacterZoneClient__IsStackBlocked_x                      0x4BE2D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BA8D0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4D8EC0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4D8FA0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4D9080
#define CharacterZoneClient__FindAffectSlot_x                      0x4C2F80
#define CharacterZoneClient__BardCastBard_x                        0x4C5AE0
#define CharacterZoneClient__GetMaxEffects_x                       0x4BA9A0
#define CharacterZoneClient__GetEffect_x                           0x4BA810
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C3FD0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C40A0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C40F0
#define CharacterZoneClient__CalcAffectChange_x                    0x4C4240
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C4410
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B27F0
#define CharacterZoneClient__FindItemByGuid_x                      0x4D74A0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D6F20

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6D8690
#define CBankWnd__WndNotification_x                                0x6D8470

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6E5DF0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x614BF0
#define CButtonWnd__CButtonWnd_x                                   0x930450

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x706000
#define CChatManager__InitContextMenu_x                            0x6FF150
#define CChatManager__FreeChatWindow_x                             0x704B40
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E8450
#define CChatManager__SetLockedActiveChatWindow_x                  0x705C80
#define CChatManager__CreateChatWindow_x                           0x705180

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E8560

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x944AA0
#define CContextMenu__dCContextMenu_x                              0x944CD0
#define CContextMenu__AddMenuItem_x                                0x944CE0
#define CContextMenu__RemoveMenuItem_x                             0x944FE0
#define CContextMenu__RemoveAllMenuItems_x                         0x945000
#define CContextMenu__CheckMenuItem_x                              0x945080
#define CContextMenu__SetMenuItem_x                                0x944F10
#define CContextMenu__AddSeparator_x                               0x944E70

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x945610
#define CContextMenuManager__RemoveMenu_x                          0x945680
#define CContextMenuManager__PopupMenu_x                           0x945740
#define CContextMenuManager__Flush_x                               0x9455B0
#define CContextMenuManager__GetMenu_x                             0x49B490
#define CContextMenuManager__CreateDefaultMenu_x                   0x7117E0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8D31B0
#define CChatService__GetFriendName_x                              0x8D31C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7068B0
#define CChatWindow__Clear_x                                       0x707B80
#define CChatWindow__WndNotification_x                             0x708310
#define CChatWindow__AddHistory_x                                  0x707440

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x941F10
#define CComboWnd__Draw_x                                          0x941420
#define CComboWnd__GetCurChoice_x                                  0x941D50
#define CComboWnd__GetListRect_x                                   0x9418C0
#define CComboWnd__GetTextRect_x                                   0x941F70
#define CComboWnd__InsertChoice_x                                  0x941A50
#define CComboWnd__SetColors_x                                     0x941A20
#define CComboWnd__SetChoice_x                                     0x941D20
#define CComboWnd__GetItemCount_x                                  0x941D60
#define CComboWnd__GetCurChoiceText_x                              0x941DA0
#define CComboWnd__GetChoiceText_x                                 0x941D70
#define CComboWnd__InsertChoiceAtIndex_x                           0x941AE0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x70F1D0
#define CContainerWnd__vftable_x                                   0xB05BA4
#define CContainerWnd__SetContainer_x                              0x710730

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x547490
#define CDisplay__PreZoneMainUI_x                                  0x5474A0
#define CDisplay__CleanGameUI_x                                    0x54C810
#define CDisplay__GetClickedActor_x                                0x53F7B0
#define CDisplay__GetUserDefinedColor_x                            0x537E70
#define CDisplay__GetWorldFilePath_x                               0x541220
#define CDisplay__is3dON_x                                         0x53C410
#define CDisplay__ReloadUI_x                                       0x546920
#define CDisplay__WriteTextHD2_x                                   0x53C200
#define CDisplay__TrueDistance_x                                   0x542EE0
#define CDisplay__SetViewActor_x                                   0x53F0D0
#define CDisplay__GetFloorHeight_x                                 0x53C4D0
#define CDisplay__SetRenderWindow_x                                0x53AE30
#define CDisplay__ToggleScreenshotMode_x                           0x53EBA0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9646D0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x947FE0
#define CEditWnd__GetCharIndexPt_x                                 0x948F00
#define CEditWnd__GetDisplayString_x                               0x948DA0
#define CEditWnd__GetHorzOffset_x                                  0x947610
#define CEditWnd__GetLineForPrintableChar_x                        0x94A0A0
#define CEditWnd__GetSelStartPt_x                                  0x9491B0
#define CEditWnd__GetSTMLSafeText_x                                0x948BC0
#define CEditWnd__PointFromPrintableChar_x                         0x949CD0
#define CEditWnd__SelectableCharFromPoint_x                        0x949E40
#define CEditWnd__SetEditable_x                                    0x949280
#define CEditWnd__SetWindowTextA_x                                 0x948940

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5F4060
#define CEverQuest__ClickedPlayer_x                                0x5E6080
#define CEverQuest__CreateTargetIndicator_x                        0x603690
#define CEverQuest__DeleteTargetIndicator_x                        0x603720
#define CEverQuest__DoTellWindow_x                                 0x4E8640
#define CEverQuest__OutputTextToLog_x                              0x4E88C0
#define CEverQuest__DropHeldItemOnGround_x                         0x5DB0C0
#define CEverQuest__dsp_chat_x                                     0x4E8C50
#define CEverQuest__trimName_x                                     0x5FF970
#define CEverQuest__Emote_x                                        0x5F48C0
#define CEverQuest__EnterZone_x                                    0x5EE840
#define CEverQuest__GetBodyTypeDesc_x                              0x5F9230
#define CEverQuest__GetClassDesc_x                                 0x5F9870
#define CEverQuest__GetClassThreeLetterCode_x                      0x5F9E70
#define CEverQuest__GetDeityDesc_x                                 0x601FD0
#define CEverQuest__GetLangDesc_x                                  0x5FA030
#define CEverQuest__GetRaceDesc_x                                  0x5F9850
#define CEverQuest__InterpretCmd_x                                 0x6025A0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5DF2C0
#define CEverQuest__LMouseUp_x                                     0x5DD650
#define CEverQuest__RightClickedOnPlayer_x                         0x5DFBA0
#define CEverQuest__RMouseUp_x                                     0x5DE5D0
#define CEverQuest__SetGameState_x                                 0x5DAE50
#define CEverQuest__UPCNotificationFlush_x                         0x5FF870
#define CEverQuest__IssuePetCommand_x                              0x5FB430
#define CEverQuest__ReportSuccessfulHit_x                          0x5F5CB0

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x7212A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x721300
#define CGaugeWnd__Draw_x                                          0x720920

// CGuild
#define CGuild__FindMemberByName_x                                 0x4AF200
#define CGuild__GetGuildName_x                                     0x4AE2E0
#define CGuild__GetGuildIndex_x                                    0x4AE670

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x73C730

//CHotButton
#define CHotButton__SetButtonSize_x                                0x614FB0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x7496E0
#define CInvSlotMgr__MoveItem_x                                    0x748440
#define CInvSlotMgr__SelectSlot_x                                  0x7497B0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x746CC0
#define CInvSlot__SliderComplete_x                                 0x744A20
#define CInvSlot__GetItemBase_x                                    0x7443B0
#define CInvSlot__UpdateItem_x                                     0x744520

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x74B200
#define CInvSlotWnd__CInvSlotWnd_x                                 0x74A3B0
#define CInvSlotWnd__HandleLButtonUp_x                             0x74AD80

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x804D80
#define CItemDisplayWnd__UpdateStrings_x                           0x759930
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x753690
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x753BB0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x759F30
#define CItemDisplayWnd__AboutToShow_x                             0x759590
#define CItemDisplayWnd__WndNotification_x                         0x75B000
#define CItemDisplayWnd__RequestConvertItem_x                      0x75AAD0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x7585F0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x7593B0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x83DA60

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x75F510

// CLabel 
#define CLabel__Draw_x                                             0x764F80

// CListWnd
#define CListWnd__CListWnd_x                                       0x91A7F0
#define CListWnd__dCListWnd_x                                      0x91AB10
#define CListWnd__AddColumn_x                                      0x91EF40
#define CListWnd__AddColumn1_x                                     0x91EF90
#define CListWnd__AddLine_x                                        0x91F320
#define CListWnd__AddString_x                                      0x91F120
#define CListWnd__CalculateFirstVisibleLine_x                      0x91ED00
#define CListWnd__CalculateVSBRange_x                              0x91EAE0
#define CListWnd__ClearSel_x                                       0x91FB00
#define CListWnd__ClearAllSel_x                                    0x91FB60
#define CListWnd__CloseAndUpdateEditWindow_x                       0x920560
#define CListWnd__Compare_x                                        0x91E410
#define CListWnd__Draw_x                                           0x91AC40
#define CListWnd__DrawColumnSeparators_x                           0x91D400
#define CListWnd__DrawHeader_x                                     0x91D860
#define CListWnd__DrawItem_x                                       0x91DD50
#define CListWnd__DrawLine_x                                       0x91D560
#define CListWnd__DrawSeparator_x                                  0x91D4A0
#define CListWnd__EnableLine_x                                     0x91CCF0
#define CListWnd__EnsureVisible_x                                  0x920490
#define CListWnd__ExtendSel_x                                      0x91FA30
#define CListWnd__GetColumnTooltip_x                               0x91C830
#define CListWnd__GetColumnMinWidth_x                              0x91C8A0
#define CListWnd__GetColumnWidth_x                                 0x91C7A0
#define CListWnd__GetCurSel_x                                      0x91C130
#define CListWnd__GetItemAtPoint_x                                 0x91CF60
#define CListWnd__GetItemAtPoint1_x                                0x91CFD0
#define CListWnd__GetItemData_x                                    0x91C1B0
#define CListWnd__GetItemHeight_x                                  0x91C570
#define CListWnd__GetItemIcon_x                                    0x91C340
#define CListWnd__GetItemRect_x                                    0x91CDE0
#define CListWnd__GetItemText_x                                    0x91C1F0
#define CListWnd__GetSelList_x                                     0x91FBB0
#define CListWnd__GetSeparatorRect_x                               0x91D210
#define CListWnd__InsertLine_x                                     0x91F710
#define CListWnd__RemoveLine_x                                     0x91F860
#define CListWnd__SetColors_x                                      0x91EAB0
#define CListWnd__SetColumnJustification_x                         0x91E7E0
#define CListWnd__SetColumnWidth_x                                 0x91E700
#define CListWnd__SetCurSel_x                                      0x91F970
#define CListWnd__SetItemColor_x                                   0x920150
#define CListWnd__SetItemData_x                                    0x920110
#define CListWnd__SetItemText_x                                    0x91FD20
#define CListWnd__ShiftColumnSeparator_x                           0x91E8A0
#define CListWnd__Sort_x                                           0x91E590
#define CListWnd__ToggleSel_x                                      0x91F9A0
#define CListWnd__SetColumnsSizable_x                              0x91E950
#define CListWnd__SetItemWnd_x                                     0x91FFD0
#define CListWnd__GetItemWnd_x                                     0x91C390
#define CListWnd__SetItemIcon_x                                    0x91FDA0
#define CListWnd__CalculateCustomWindowPositions_x                 0x91EE00
#define CListWnd__SetVScrollPos_x                                  0x91E6E0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x77A810
#define CMapViewWnd__GetWorldCoordinates_x                         0x778F20
#define CMapViewWnd__HandleLButtonDown_x                           0x775F60

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x79A940
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x79B220
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x79B750
#define CMerchantWnd__SelectRecoverySlot_x                         0x79E6D0
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7994B0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7A4280
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x79A560

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8A0B90
#define CPacketScrambler__hton_x                                   0x8A0B80

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x939680
#define CSidlManager__FindScreenPieceTemplate_x                    0x939A90
#define CSidlManager__FindScreenPieceTemplate1_x                   0x939880
#define CSidlManager__CreateLabel_x                                0x7FC210
#define CSidlManager__CreateXWndFromTemplate_x                     0x93C9F0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x93CBD0
#define CSidlManager__CreateXWnd_x                                 0x7FC140
#define CSidlManager__CreateHotButtonWnd_x                         0x7FC710

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x936180
#define CSidlScreenWnd__CalculateVSBRange_x                        0x936080
#define CSidlScreenWnd__ConvertToRes_x                             0x95B6D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x935B10
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x935800
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x9358D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x9359A0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x936600
#define CSidlScreenWnd__EnableIniStorage_x                         0x936AD0
#define CSidlScreenWnd__GetSidlPiece_x                             0x9367F0
#define CSidlScreenWnd__Init1_x                                    0x935420
#define CSidlScreenWnd__LoadIniInfo_x                              0x936B20
#define CSidlScreenWnd__LoadIniListWnd_x                           0x937660
#define CSidlScreenWnd__LoadSidlScreen_x                           0x934830
#define CSidlScreenWnd__StoreIniInfo_x                             0x9371E0
#define CSidlScreenWnd__StoreIniVis_x                              0x937540
#define CSidlScreenWnd__WndNotification_x                          0x936510
#define CSidlScreenWnd__GetChildItem_x                             0x936A50
#define CSidlScreenWnd__HandleLButtonUp_x                          0x926350
#define CSidlScreenWnd__m_layoutCopy_x                             0x15EAEF8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x679120
#define CSkillMgr__GetSkillCap_x                                   0x679300
#define CSkillMgr__GetNameToken_x                                  0x6788A0
#define CSkillMgr__IsActivatedSkill_x                              0x6789E0
#define CSkillMgr__IsCombatSkill_x                                 0x678920

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9463F0
#define CSliderWnd__SetValue_x                                     0x946260
#define CSliderWnd__SetNumTicks_x                                  0x9462C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x802210

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x94EBF0
#define CStmlWnd__CalculateHSBRange_x                              0x94FD10
#define CStmlWnd__CalculateVSBRange_x                              0x94FC80
#define CStmlWnd__CanBreakAtCharacter_x                            0x954040
#define CStmlWnd__FastForwardToEndOfTag_x                          0x954CD0
#define CStmlWnd__ForceParseNow_x                                  0x94F1E0
#define CStmlWnd__GetNextTagPiece_x                                0x953FA0
#define CStmlWnd__GetSTMLText_x                                    0x4FF5A0
#define CStmlWnd__GetVisibleText_x                                 0x94F200
#define CStmlWnd__InitializeWindowVariables_x                      0x954B20
#define CStmlWnd__MakeStmlColorTag_x                               0x94E260
#define CStmlWnd__MakeWndNotificationTag_x                         0x94E2D0
#define CStmlWnd__SetSTMLText_x                                    0x94D310
#define CStmlWnd__StripFirstSTMLLines_x                            0x955DA0
#define CStmlWnd__UpdateHistoryString_x                            0x954EE0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x94C460
#define CTabWnd__DrawCurrentPage_x                                 0x94CB90
#define CTabWnd__DrawTab_x                                         0x94C8B0
#define CTabWnd__GetCurrentPage_x                                  0x94BC60
#define CTabWnd__GetPageInnerRect_x                                0x94BEA0
#define CTabWnd__GetTabInnerRect_x                                 0x94BDE0
#define CTabWnd__GetTabRect_x                                      0x94BC90
#define CTabWnd__InsertPage_x                                      0x94C0B0
#define CTabWnd__SetPage_x                                         0x94BF20
#define CTabWnd__SetPageRect_x                                     0x94C3A0
#define CTabWnd__UpdatePage_x                                      0x94C770
#define CTabWnd__GetPageFromTabIndex_x                             0x94C7F0
#define CTabWnd__GetCurrentTabIndex_x                              0x94BC50

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x75F970
#define CPageWnd__SetTabText_x                                     0x94B7B0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A8E80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x923220
#define CTextureFont__GetTextExtent_x                              0x9233E0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6ABFA0
#define CHtmlComponentWnd__ValidateUri_x                           0x73E120
#define CHtmlWnd__SetClientCallbacks_x                             0x61A020
#define CHtmlWnd__AddObserver_x                                    0x61A040
#define CHtmlWnd__RemoveObserver_x                                 0x61A0A0
#define Window__getProgress_x                                      0x856190
#define Window__getStatus_x                                        0x8561B0
#define Window__getURI_x                                           0x8561C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x961120

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x910410

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E8290
#define CXStr__CXStr1_x                                            0x918E20
#define CXStr__CXStr3_x                                            0x8F24E0
#define CXStr__dCXStr_x                                            0x4786A0
#define CXStr__operator_equal_x                                    0x8F2710
#define CXStr__operator_equal1_x                                   0x8F2750
#define CXStr__operator_plus_equal1_x                              0x8F31E0
#define CXStr__SetString_x                                         0x8F50D0
#define CXStr__operator_char_p_x                                   0x8F2C50
#define CXStr__GetChar_x                                           0x8F4A20
#define CXStr__Delete_x                                            0x8F42D0
#define CXStr__GetUnicode_x                                        0x8F4A90
#define CXStr__GetLength_x                                         0x47D450
#define CXStr__Mid_x                                               0x47D460
#define CXStr__Insert_x                                            0x8F4AF0
#define CXStr__FindNext_x                                          0x8F4740

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9446C0
#define CXWnd__BringToTop_x                                        0x9299F0
#define CXWnd__Center_x                                            0x929570
#define CXWnd__ClrFocus_x                                          0x929390
#define CXWnd__Destroy_x                                           0x929430
#define CXWnd__DoAllDrawing_x                                      0x925AE0
#define CXWnd__DrawChildren_x                                      0x925AB0
#define CXWnd__DrawColoredRect_x                                   0x925F40
#define CXWnd__DrawTooltip_x                                       0x924630
#define CXWnd__DrawTooltipAtPoint_x                                0x9246F0
#define CXWnd__GetBorderFrame_x                                    0x925DA0
#define CXWnd__GetChildWndAt_x                                     0x929A90
#define CXWnd__GetClientClipRect_x                                 0x927CE0
#define CXWnd__GetScreenClipRect_x                                 0x927D90
#define CXWnd__GetScreenRect_x                                     0x927F10
#define CXWnd__GetTooltipRect_x                                    0x925F90
#define CXWnd__GetWindowTextA_x                                    0x49CB70
#define CXWnd__IsActive_x                                          0x9266D0
#define CXWnd__IsDescendantOf_x                                    0x9288E0
#define CXWnd__IsReallyVisible_x                                   0x928910
#define CXWnd__IsType_x                                            0x92A110
#define CXWnd__Move_x                                              0x928980
#define CXWnd__Move1_x                                             0x928A40
#define CXWnd__ProcessTransition_x                                 0x929520
#define CXWnd__Refade_x                                            0x928D20
#define CXWnd__Resize_x                                            0x928FB0
#define CXWnd__Right_x                                             0x9297B0
#define CXWnd__SetFocus_x                                          0x929350
#define CXWnd__SetFont_x                                           0x9293C0
#define CXWnd__SetKeyTooltip_x                                     0x929F20
#define CXWnd__SetMouseOver_x                                      0x926EC0
#define CXWnd__StartFade_x                                         0x9287C0
#define CXWnd__GetChildItem_x                                      0x929C00
#define CXWnd__SetParent_x                                         0x9286B0
#define CXWnd__Minimize_x                                          0x929020

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x95C750

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x92C990
#define CXWndManager__DrawWindows_x                                0x92C9B0
#define CXWndManager__GetKeyboardFlags_x                           0x92F0C0
#define CXWndManager__HandleKeyboardMsg_x                          0x92EC70
#define CXWndManager__RemoveWnd_x                                  0x92F310
#define CXWndManager__RemovePendingDeletionWnd_x                   0x92F870

// CDBStr
#define CDBStr__GetString_x                                        0x536E40

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4BB8B0
#define EQ_Character__Cur_HP_x                                     0x4D1E60
#define EQ_Character__Cur_Mana_x                                   0x4D9580
#define EQ_Character__GetCastingTimeModifier_x                     0x4BE920
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B2430
#define EQ_Character__GetFocusRangeModifier_x                      0x4B2580
#define EQ_Character__GetHPRegen_x                                 0x4DF320
#define EQ_Character__GetEnduranceRegen_x                          0x4DF920
#define EQ_Character__GetManaRegen_x                               0x4DFD60
#define EQ_Character__Max_Endurance_x                              0x63FED0
#define EQ_Character__Max_HP_x                                     0x4D1C90
#define EQ_Character__Max_Mana_x                                   0x63FCD0
#define EQ_Character__doCombatAbility_x                            0x642330
#define EQ_Character__UseSkill_x                                   0x4E1B40
#define EQ_Character__GetConLevel_x                                0x638F20
#define EQ_Character__IsExpansionFlag_x                            0x59D4B0
#define EQ_Character__TotalEffect_x                                0x4C5220
#define EQ_Character__GetPCSpellAffect_x                           0x4BF530
#define EQ_Character__SpellDuration_x                              0x4BF060
#define EQ_Character__GetAdjustedSkill_x                           0x4D4BE0
#define EQ_Character__GetBaseSkill_x                               0x4D5B80
#define EQ_Character__CanUseItem_x                                 0x4D9890

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8C0070

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x656400

//PcClient
#define PcClient__PcClient_x                                       0x636660

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4B9550
#define CCharacterListWnd__EnterWorld_x                            0x4B8F90
#define CCharacterListWnd__Quit_x                                  0x4B8CE0
#define CCharacterListWnd__UpdateList_x                            0x4B9120

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x61B260
#define EQ_Item__CreateItemTagString_x                             0x89A430
#define EQ_Item__IsStackable_x                                     0x89EF30
#define EQ_Item__GetImageNum_x                                     0x89BE60
#define EQ_Item__CreateItemClient_x                                0x61A420
#define EQ_Item__GetItemValue_x                                    0x89D160
#define EQ_Item__ValueSellMerchant_x                               0x8A0760
#define EQ_Item__IsKeyRingItem_x                                   0x89E840
#define EQ_Item__CanGoInBag_x                                      0x61B380
#define EQ_Item__IsEmpty_x                                         0x89E3A0
#define EQ_Item__GetMaxItemCount_x                                 0x89D580
#define EQ_Item__GetHeldItem_x                                     0x89BD30
#define EQ_Item__GetAugmentFitBySlot_x                             0x899DB0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x555200
#define EQ_LoadingS__Array_x                                       0xC19B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x640830
#define EQ_PC__GetAlternateAbilityId_x                             0x8A9940
#define EQ_PC__GetCombatAbility_x                                  0x8A9FB0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8AA020
#define EQ_PC__GetItemRecastTimer_x                                0x6428B0
#define EQ_PC__HasLoreItem_x                                       0x6396E0
#define EQ_PC__AlertInventoryChanged_x                             0x638860
#define EQ_PC__GetPcZoneClient_x                                   0x664E10
#define EQ_PC__RemoveMyAffect_x                                    0x645AE0
#define EQ_PC__GetKeyRingItems_x                                   0x8AA8B0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8AA640
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8AABB0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5A3A10
#define EQItemList__add_object_x                                   0x5D09A0
#define EQItemList__add_item_x                                     0x5A3F70
#define EQItemList__delete_item_x                                  0x5A3FC0
#define EQItemList__FreeItemList_x                                 0x5A3EC0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x533960

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x657C80
#define EQPlayer__dEQPlayer_x                                      0x64AFE0
#define EQPlayer__DoAttack_x                                       0x65FAD0
#define EQPlayer__EQPlayer_x                                       0x64B6A0
#define EQPlayer__SetNameSpriteState_x                             0x64F970
#define EQPlayer__SetNameSpriteTint_x                              0x650830
#define PlayerBase__HasProperty_j_x                                0x98EEB0
#define EQPlayer__IsTargetable_x                                   0x98F350
#define EQPlayer__CanSee_x                                         0x98F1B0
#define EQPlayer__CanSee1_x                                        0x98F280
#define PlayerBase__GetVisibilityLineSegment_x                     0x98EF70

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x6628A0
#define PlayerZoneClient__GetLevel_x                               0x664E50
#define PlayerZoneClient__IsValidTeleport_x                        0x5D1B10
#define PlayerZoneClient__LegalPlayerRace_x                        0x54E6A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x65A9E0
#define EQPlayerManager__GetSpawnByName_x                          0x65AA90
#define EQPlayerManager__GetPlayerFromPartialName_x                0x65AB20

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x61E880
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x61E900
#define KeypressHandler__AttachKeyToEqCommand_x                    0x61E940
#define KeypressHandler__ClearCommandStateArray_x                  0x61FD50
#define KeypressHandler__HandleKeyDown_x                           0x61FD70
#define KeypressHandler__HandleKeyUp_x                             0x61FE10
#define KeypressHandler__SaveKeymapping_x                          0x620260

// MapViewMap 
#define MapViewMap__Clear_x                                        0x776680
#define MapViewMap__SaveEx_x                                       0x779A40
#define MapViewMap__SetZoom_x                                      0x77E100

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8BDF90

// StringTable 
#define StringTable__getString_x                                   0x8B8B30

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x645750
#define PcZoneClient__RemovePetEffect_x                            0x645D80
#define PcZoneClient__HasAlternateAbility_x                        0x63FB00
#define PcZoneClient__GetCurrentMod_x                              0x4E4BF0
#define PcZoneClient__GetModCap_x                                  0x4E4AF0
#define PcZoneClient__CanEquipItem_x                               0x6401D0
#define PcZoneClient__GetItemByID_x                                0x642D20
#define PcZoneClient__GetItemByItemClass_x                         0x642E70
#define PcZoneClient__RemoveBuffEffect_x                           0x645DA0
#define PcZoneClient__BandolierSwap_x                              0x640DF0
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x642850

//Doors
#define EQSwitch__UseSwitch_x                                      0x5D65B0

//IconCache
#define IconCache__GetIcon_x                                       0x716860

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x70E370
#define CContainerMgr__CloseContainer_x                            0x70E640
#define CContainerMgr__OpenExperimentContainer_x                   0x70F0C0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7CE770

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x6133E0

//CLootWnd
#define CLootWnd__LootAll_x                                        0x76CA40
#define CLootWnd__RequestLootSlot_x                                0x76BC70

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x571190
#define EQ_Spell__SpellAffects_x                                   0x571600
#define EQ_Spell__SpellAffectBase_x                                0x5713C0
#define EQ_Spell__IsStackable_x                                    0x4C9870
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4C96F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B68E0
#define EQ_Spell__IsSPAStacking_x                                  0x572450
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x571960
#define EQ_Spell__IsNoRemove_x                                     0x4C9850
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x572460
#define __IsResEffectSpell_x                                       0x4C8BA0

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4ACF40

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8C8630

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x8154C0
#define CTargetWnd__WndNotification_x                              0x814D50
#define CTargetWnd__RefreshTargetBuffs_x                           0x815020
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x813EC0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x819AB0

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x5313A0
#define CTaskManager__HandleMessage_x                              0x52F840
#define CTaskManager__GetTaskStatus_x                              0x531450
#define CTaskManager__GetElementDescription_x                      0x5314D0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x56C700
#define EqSoundManager__PlayScriptMp3_x                            0x56C860
#define EqSoundManager__SoundAssistPlay_x                          0x67D040
#define EqSoundManager__WaveInstancePlay_x                         0x67C5B0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x525130

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x94ACC0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x55CCA0
#define CAltAbilityData__GetMercMaxRank_x                          0x55CC30
#define CAltAbilityData__GetMaxRank_x                              0x552350

//CTargetRing
#define CTargetRing__Cast_x                                        0x611500

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4C96D0
#define CharacterBase__CreateItemGlobalIndex_x                     0x50C370
#define CharacterBase__CreateItemIndex_x                           0x6195D0
#define CharacterBase__GetItemPossession_x                         0x4F7E20
#define CharacterBase__GetItemByGlobalIndex_x                      0x8D0C40
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8D0CA0
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6F53A0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6F5BD0
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x6F5C80

//messages
#define msg_spell_worn_off_x                                       0x595700
#define msg_new_text_x                                             0x58A4A0
#define __msgTokenTextParam_x                                      0x597C30
#define msgTokenText_x                                             0x597E80

//SpellManager
#define SpellManager__vftable_x                                    0xADFF34
#define SpellManager__SpellManager_x                               0x680370
#define Spellmanager__LoadTextSpells_x                             0x680C60
#define SpellManager__GetSpellByGroupAndRank_x                     0x680540

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x992F50

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x50C9C0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x59B9D0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x631E10
#define ItemGlobalIndex__IsValidIndex_x                            0x50CA20

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8C8FD0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8C9250

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7652C0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x712A70
#define CCursorAttachment__AttachToCursor1_x                       0x712AB0
#define CCursorAttachment__Deactivate_x                            0x713AA0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x93DA30
#define CSidlManagerBase__CreatePageWnd_x                          0x93D220
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9394A0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x939430

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x95AD00
#define CEQSuiteTextureLoader__GetTexture_x                        0x95A9C0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x509910
#define CFindItemWnd__WndNotification_x                            0x50A3F0
#define CFindItemWnd__Update_x                                     0x50AF60
#define CFindItemWnd__PickupSelectedItem_x                         0x509150

//IString
#define IString__Append_x                                          0x4F9640

//Camera
#define CDisplay__cameraType_x                                     0xDF2FF0
#define EverQuest__Cameras_x                                       0xEB6A24

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x512120
#define LootFiltersManager__GetItemFilterData_x                    0x511A30
#define LootFiltersManager__RemoveItemLootFilter_x                 0x511A60
#define LootFiltersManager__SetItemLootFilter_x                    0x511C80

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7BC730

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x998AB0
#define CResolutionHandler__GetWindowedStyle_x                     0x677C90

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x70B020

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x8DC9F0
#define CDistillerInfo__Instance_x                                 0x8DC990

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x72B4C0
#define CGroupWnd__UpdateDisplay_x                                 0x72A810

//ItemBase
#define ItemBase__IsLore_x                                         0x89E8E0
#define ItemBase__IsLoreEquipped_x                                 0x89E960

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5D0900
#define EQPlacedItemManager__GetItemByGuid_x                       0x5D0A40
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5D0AA0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x66D500
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x670E90

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x4FFC40

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4EE700
#define FactionManagerClient__HandleFactionMessage_x               0x4EED70
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4EF370
#define FactionManagerClient__GetMaxFaction_x                      0x4EF38F
#define FactionManagerClient__GetMinFaction_x                      0x4EF340

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x4F7DF0

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x9221D0

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49BE80

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x4F8050

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x55C130

//CTargetManager
#define CTargetManager__Get_x                                      0x683BD0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x66D500

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A8C40

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5A3E60

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF540B8

//patterns
//LoginController__GiveTime_x
// 56 8B F1 E8 ? FD FF FF 8B CE 5E E9 ? ? FF FF C7 01
//Feb 16 2018 Test
//IDA Style Sig: 56 8B F1 E8 ? ? ? ? 8B CE
static PBYTE lpPattern = (PBYTE)"\x56\x8B\xF1\xE8\x00\x00\x00\x00\x8B\xCE";
static char lpMask[] = "xxxx????xx";
