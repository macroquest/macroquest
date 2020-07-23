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
#define __ExpectedVersionDate                                     "Jul 22 2020"
#define __ExpectedVersionTime                                     "10:13:14"
#define __ActualVersionDate_x                                      0xB1D664
#define __ActualVersionTime_x                                      0xB1D658
#define __ActualVersionBuild_x                                     0xB09334

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x640040
#define __MemChecker1_x                                            0x91A4A0
#define __MemChecker2_x                                            0x6CF2B0
#define __MemChecker3_x                                            0x6CF200
#define __MemChecker4_x                                            0x870F70
#define __EncryptPad0_x                                            0xC58520
#define __EncryptPad1_x                                            0xCB6700
#define __EncryptPad2_x                                            0xC68DB8
#define __EncryptPad3_x                                            0xC689B8
#define __EncryptPad4_x                                            0xCA6C90
#define __EncryptPad5_x                                            0xF78BD0
#define __AC1_x                                                    0x8277E6
#define __AC2_x                                                    0x5F9AEF
#define __AC3_x                                                    0x60113F
#define __AC4_x                                                    0x605100
#define __AC5_x                                                    0x60B3BF
#define __AC6_x                                                    0x60F8C6
#define __AC7_x                                                    0x5F9560
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x70E0C

// Direct Input
#define DI8__Main_x                                                0xF78BF0
#define DI8__Keyboard_x                                            0xF78BF4
#define DI8__Mouse_x                                               0xF78C0C
#define DI8__Mouse_Copy_x                                          0xED1DBC
#define DI8__Mouse_Check_x                                         0xF76724
#define __AutoSkillArray_x                                         0xED2CD4
#define __Attack_x                                                 0xF70AFB
#define __Autofire_x                                               0xF70AFC
#define __BindList_x                                               0xC46F38
#define g_eqCommandStates_x                                        0xC47CB8
#define __Clicks_x                                                 0xED1E74
#define __CommandList_x                                            0xC48878
#define __CurrentMapLabel_x                                        0xF895C4
#define __CurrentSocial_x                                          0xC307C8
#define __DoAbilityList_x                                          0xF0861C
#define __do_loot_x                                                0x5C57A0
#define __DrawHandler_x                                            0x1608668
#define __GroupCount_x                                             0xECCE92
#define __Guilds_x                                                 0xED0CF8
#define __gWorld_x                                                 0xECCD1C
#define __HWnd_x                                                   0xF78C10
#define __heqmain_x                                                0xF78BB8
#define __InChatMode_x                                             0xED1DA4
#define __LastTell_x                                               0xED3D18
#define __LMouseHeldTime_x                                         0xED1EE0
#define __Mouse_x                                                  0xF78BDC
#define __MouseLook_x                                              0xED1E3A
#define __MouseEventTime_x                                         0xF715DC
#define __gpbCommandEvent_x                                        0xECA78C
#define __NetStatusToggle_x                                        0xED1E3D
#define __PCNames_x                                                0xED32C4
#define __RangeAttackReady_x                                       0xED2FB8
#define __RMouseHeldTime_x                                         0xED1EDC
#define __RunWalkState_x                                           0xED1DA8
#define __ScreenMode_x                                             0xE18134
#define __ScreenX_x                                                0xED1D5C
#define __ScreenY_x                                                0xED1D58
#define __ScreenXMax_x                                             0xED1D60
#define __ScreenYMax_x                                             0xED1D64
#define __ServerHost_x                                             0xECA973
#define __ServerName_x                                             0xF085DC
#define __ShiftKeyDown_x                                           0xED2434
#define __ShowNames_x                                              0xED3174
#define EverQuestInfo__bSocialChanged_x                            0xF08664
#define __Socials_x                                                0xF086DC
#define __SubscriptionType_x                                       0xFCD938
#define __TargetAggroHolder_x                                      0xF8BF78
#define __ZoneType_x                                               0xED2238
#define __GroupAggro_x                                             0xF8BFB8
#define __LoginName_x                                              0xF7934C
#define __Inviter_x                                                0xF70A78
#define __AttackOnAssist_x                                         0xED3130
#define __UseTellWindows_x                                         0xED3460
#define __gfMaxZoomCameraDistance_x                                0xB12F98
#define __gfMaxCameraDistance_x                                    0xB3F408
#define __pulAutoRun_x                                             0xED1E58
#define __pulForward_x                                             0xED3498
#define __pulBackward_x                                            0xED349C
#define __pulTurnRight_x                                           0xED34A0
#define __pulTurnLeft_x                                            0xED34A4
#define __pulStrafeLeft_x                                          0xED34A8
#define __pulStrafeRight_x                                         0xED34AC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xECD090
#define instEQZoneInfo_x                                           0xED2030
#define pinstActiveBanker_x                                        0xECA868
#define pinstActiveCorpse_x                                        0xECA860
#define pinstActiveGMaster_x                                       0xECA864
#define pinstActiveMerchant_x                                      0xECA85C
#define pinstAltAdvManager_x                                       0xE192C0
#define pinstBandageTarget_x                                       0xECAC88
#define pinstCamActor_x                                            0xE18120
#define pinstCDBStr_x                                              0xE17FDC
#define pinstCDisplay_x                                            0xECCCE0
#define pinstCEverQuest_x                                          0xF78C08
#define pinstEverQuestInfo_x                                       0xED1D50
#define pinstCharData_x                                            0xECCE7C
#define pinstCharSpawn_x                                           0xECACC0
#define pinstControlledMissile_x                                   0xECACD0
#define pinstControlledPlayer_x                                    0xECACC0
#define pinstCResolutionHandler_x                                  0x1608898
#define pinstCSidlManager_x                                        0x1607830
#define pinstCXWndManager_x                                        0x160782C
#define instDynamicZone_x                                          0xED0BD0
#define pinstDZMember_x                                            0xED0CE0
#define pinstDZTimerInfo_x                                         0xED0CE4
#define pinstEqLogin_x                                             0xF78C98
#define instEQMisc_x                                               0xE17F20
#define pinstEQSoundManager_x                                      0xE1A290
#define pinstEQSpellStrings_x                                      0xCDA938
#define instExpeditionLeader_x                                     0xED0C1A
#define instExpeditionName_x                                       0xED0C5A
#define pinstGroup_x                                               0xECCE8E
#define pinstImeManager_x                                          0x1607828
#define pinstLocalPlayer_x                                         0xECA858
#define pinstMercenaryData_x                                       0xF730D4
#define pinstMercenaryStats_x                                      0xF8C044
#define pinstModelPlayer_x                                         0xECAA7C
#define pinstPCData_x                                              0xECCE7C
#define pinstSkillMgr_x                                            0xF75238
#define pinstSpawnManager_x                                        0xF73CE0
#define pinstSpellManager_x                                        0xF75478
#define pinstSpellSets_x                                           0xF69724
#define pinstStringTable_x                                         0xECD084
#define pinstSwitchManager_x                                       0xECA630
#define pinstTarget_x                                              0xECACBC
#define pinstTargetObject_x                                        0xECACC8
#define pinstTargetSwitch_x                                        0xECCCD8
#define pinstTaskMember_x                                          0xE17DB0
#define pinstTrackTarget_x                                         0xECACC4
#define pinstTradeTarget_x                                         0xECA86C
#define instTributeActive_x                                        0xE17F41
#define pinstViewActor_x                                           0xE1811C
#define pinstWorldData_x                                           0xECD088
#define pinstZoneAddr_x                                            0xED22D0
#define pinstPlayerPath_x                                          0xF73D78
#define pinstTargetIndicator_x                                     0xF756E0
#define EQObject_Top_x                                             0xECA854
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCAAWnd_x                                              0xE18444
#define pinstCAchievementsWnd_x                                    0xE180B4
#define pinstCActionsWnd_x                                         0xE188E4
#define pinstCAdvancedDisplayOptionsWnd_x                          0xE18164
#define pinstCAdvancedLootWnd_x                                    0xE18100
#define pinstCAdventureLeaderboardWnd_x                            0xF82D98
#define pinstCAdventureRequestWnd_x                                0xF82E48
#define pinstCAdventureStatsWnd_x                                  0xF82EF8
#define pinstCAggroMeterWnd_x                                      0xE18168
#define pinstCAlarmWnd_x                                           0xE180CC
#define pinstCAlertHistoryWnd_x                                    0xE181DC
#define pinstCAlertStackWnd_x                                      0xE18124
#define pinstCAlertWnd_x                                           0xE18154
#define pinstCAltStorageWnd_x                                      0xF83258
#define pinstCAudioTriggersWindow_x                                0xCCCC68
#define pinstCAuraWnd_x                                            0xE18104
#define pinstCAvaZoneWnd_x                                         0xE1819C
#define pinstCBandolierWnd_x                                       0xE1815C
#define pinstCBankWnd_x                                            0xE18198
#define pinstCBarterMerchantWnd_x                                  0xF84498
#define pinstCBarterSearchWnd_x                                    0xF84548
#define pinstCBarterWnd_x                                          0xF845F8
#define pinstCBazaarConfirmationWnd_x                              0xE180EC
#define pinstCBazaarSearchWnd_x                                    0xE18448
#define pinstCBazaarWnd_x                                          0xE180AC
#define pinstCBlockedBuffWnd_x                                     0xE18110
#define pinstCBlockedPetBuffWnd_x                                  0xE1814C
#define pinstCBodyTintWnd_x                                        0xE188F0
#define pinstCBookWnd_x                                            0xE1818C
#define pinstCBreathWnd_x                                          0xE184CC
#define pinstCBuffWindowNORMAL_x                                   0xE180F0
#define pinstCBuffWindowSHORT_x                                    0xE180F8
#define pinstCBugReportWnd_x                                       0xE18194
#define pinstCButtonWnd_x                                          0x1607A98
#define pinstCCastingWnd_x                                         0xE1817C
#define pinstCCastSpellWnd_x                                       0xE18454
//#define pinstCCharacterCreationWnd_x                             0xDA8EBC
#define pinstCCharacterListWnd_x                                   0xE1890C
#define pinstCChatWindowManager_x                                  0xF850B8
#define pinstCClaimWnd_x                                           0xF85210
#define pinstCColorPickerWnd_x                                     0xE183F8
#define pinstCCombatAbilityWnd_x                                   0xE180C4
#define pinstCCombatSkillsSelectWnd_x                              0xE18078
#define pinstCCompassWnd_x                                         0xE188E8
#define pinstCConfirmationDialog_x                                 0xF8A110
#define pinstCContainerMgr_x                                       0xE18904
#define pinstCContextMenuManager_x                                 0x16077E8
#define pinstCCursorAttachment_x                                   0xE18170
#define pinstCDynamicZoneWnd_x                                     0xF857D8
#define pinstCEditLabelWnd_x                                       0xE180E8
#define pinstCEQMainWnd_x                                          0xF85A20
#define pinstCEventCalendarWnd_x                                   0xE184D0
#define pinstCExtendedTargetWnd_x                                  0xE18148
#define pinstCFacePick_x                                           0xE18090
#define pinstCFactionWnd_x                                         0xE1809C
#define pinstCFellowshipWnd_x                                      0xF85C20
#define pinstCFileSelectionWnd_x                                   0xE183F0
#define pinstCFindItemWnd_x                                        0xE18088
#define pinstCFindLocationWnd_x                                    0xF85D78
#define pinstCFriendsWnd_x                                         0xE1808C
#define pinstCGemsGameWnd_x                                        0xE18098
#define pinstCGiveWnd_x                                            0xE180D4
#define pinstCGroupSearchFiltersWnd_x                              0xE18180
#define pinstCGroupSearchWnd_x                                     0xF86170
#define pinstCGroupWnd_x                                           0xF86220
#define pinstCGuildBankWnd_x                                       0xED3114
#define pinstCGuildCreationWnd_x                                   0xF86380
#define pinstCGuildMgmtWnd_x                                       0xF86430
#define pinstCharacterCreation_x                                   0xE18080
#define pinstCHelpWnd_x                                            0xE180D0
#define pinstCHeritageSelectionWnd_x                               0xE180A0
#define pinstCHotButtonWnd_x                                       0xF88588
#define pinstCHotButtonWnd1_x                                      0xF88588
#define pinstCHotButtonWnd2_x                                      0xF8858C
#define pinstCHotButtonWnd3_x                                      0xF88590
#define pinstCHotButtonWnd4_x                                      0xF88594
#define pinstCIconSelectionWnd_x                                   0xE1816C
#define pinstCInspectWnd_x                                         0xE18150
#define pinstCInventoryWnd_x                                       0xE18108
#define pinstCInvSlotMgr_x                                         0xE18450
#define pinstCItemDisplayManager_x                                 0xF88B18
#define pinstCItemExpTransferWnd_x                                 0xF88C48
#define pinstCItemOverflowWnd_x                                    0xE1844C
#define pinstCJournalCatWnd_x                                      0xE18408
//#define pinstCJournalNPCWnd_x                                    0xDA93B0
#define pinstCJournalTextWnd_x                                     0xE181C4
#define pinstCKeyRingWnd_x                                         0xE18178
#define pinstCLargeDialogWnd_x                                     0xF8AD90
#define pinstCLayoutCopyWnd_x                                      0xF88F98
#define pinstCLFGuildWnd_x                                         0xF89048
#define pinstCLoadskinWnd_x                                        0xE180B0
#define pinstCLootFiltersCopyWnd_x                                 0xCE92B8
#define pinstCLootFiltersWnd_x                                     0xE18138
#define pinstCLootSettingsWnd_x                                    0xE18160
#define pinstCLootWnd_x                                            0xE1840C
#define pinstCMailAddressBookWnd_x                                 0xE184D4
#define pinstCMailCompositionWnd_x                                 0xE18420
#define pinstCMailIgnoreListWnd_x                                  0xE184D8
#define pinstCMailWnd_x                                            0xE183FC
#define pinstCManageLootWnd_x                                      0xE19770
#define pinstCMapToolbarWnd_x                                      0xE180D8
#define pinstCMapViewWnd_x                                         0xE180A4
#define pinstCMarketplaceWnd_x                                     0xE18144
#define pinstCMerchantWnd_x                                        0xE18418
#define pinstCMIZoneSelectWnd_x                                    0xF89880
#define pinstCMusicPlayerWnd_x                                     0xE181E4
#define pinstCNameChangeMercWnd_x                                  0xE180E0
#define pinstCNameChangePetWnd_x                                   0xE180BC
#define pinstCNameChangeWnd_x                                      0xE180F4
#define pinstCNoteWnd_x                                            0xE180B8
#define pinstCObjectPreviewWnd_x                                   0xE18158
#define pinstCOptionsWnd_x                                         0xE180C8
#define pinstCPetInfoWnd_x                                         0xE181D8
#define pinstCPetitionQWnd_x                                       0xE1807C
//#define pinstCPlayerCustomizationWnd_x                           0xDA8E24
#define pinstCPlayerNotesWnd_x                                     0xE188F8
#define pinstCPlayerWnd_x                                          0xE181E8
#define pinstCPopupWndManager_x                                    0xF8A110
#define pinstCProgressionSelectionWnd_x                            0xF8A1C0
#define pinstCPurchaseGroupWnd_x                                   0xE181A8
#define pinstCPurchaseWnd_x                                        0xE18190
#define pinstCPvPLeaderboardWnd_x                                  0xF8A270
#define pinstCPvPStatsWnd_x                                        0xF8A320
#define pinstCQuantityWnd_x                                        0xE181C0
#define pinstCRaceChangeWnd_x                                      0xE18114
#define pinstCRaidOptionsWnd_x                                     0xE18188
#define pinstCRaidWnd_x                                            0xE18410
#define pinstCRealEstateItemsWnd_x                                 0xE180A8
#define pinstCRealEstateLayoutDetailsWnd_x                         0xE188F4
#define pinstCRealEstateManageWnd_x                                0xE181BC
#define pinstCRealEstateNeighborhoodWnd_x                          0xE181D4
#define pinstCRealEstatePlotSearchWnd_x                            0xE183F4
#define pinstCRealEstatePurchaseWnd_x                              0xE18414
#define pinstCRespawnWnd_x                                         0xE18128
//#define pinstCRewardSelectionWnd_x                               0x10205B0
#define pinstCSelectorWnd_x                                        0xE18910
#define pinstCSendMoneyWnd_x                                       0xE180E4
#define pinstCServerListWnd_x                                      0xE1841C
#define pinstCSkillsSelectWnd_x                                    0xE18900
#define pinstCSkillsWnd_x                                          0xE188EC
#define pinstCSocialEditWnd_x                                      0xE18174
#define pinstCSocialWnd_x                                          0xE180DC
#define pinstCSpellBookWnd_x                                       0xE180C0
#define pinstCStoryWnd_x                                           0xE188E0
#define pinstCTargetOfTargetWnd_x                                  0xF8C0C8
#define pinstCTargetWnd_x                                          0xE18118
#define pinstCTaskOverlayWnd_x                                     0xE181A0
#define pinstCTaskSelectWnd_x                                      0xF8C220
#define pinstCTaskManager_x                                        0xCE9BF8
#define pinstCTaskTemplateSelectWnd_x                              0xF8C2D0
#define pinstCTaskWnd_x                                            0xF8C380
#define pinstCTextEntryWnd_x                                       0xE18184
#define pinstCTimeLeftWnd_x                                        0xE18908
#define pinstCTipWndCONTEXT_x                                      0xF8C584
#define pinstCTipWndOFDAY_x                                        0xF8C580
#define pinstCTitleWnd_x                                           0xF8C630
#define pinstCTrackingWnd_x                                        0xE1810C
#define pinstCTradeskillWnd_x                                      0xF8C798
#define pinstCTradeWnd_x                                           0xE188FC
#define pinstCTrainWnd_x                                           0xE18404
#define pinstCTributeBenefitWnd_x                                  0xF8C998
#define pinstCTributeMasterWnd_x                                   0xF8CA48
#define pinstCTributeTrophyWnd_x                                   0xF8CAF8
#define pinstCVideoModesWnd_x                                      0xE181E0
#define pinstCVoiceMacroWnd_x                                      0xF75E48
#define pinstCVoteResultsWnd_x                                     0xE18094
#define pinstCVoteWnd_x                                            0xE18084
#define pinstCWebManager_x                                         0xF764C4
#define pinstCZoneGuideWnd_x                                       0xE181A4
#define pinstCZonePathWnd_x                                        0xE181C8

#define pinstEQSuiteTextureLoader_x                                0xCB7020
#define pinstItemIconCache_x                                       0xF859D8
#define pinstLootFiltersManager_x                                  0xCE9368
#define pinstRewardSelectionWnd_x                                  0xF8AA68

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5C0B70
#define __CastRay2_x                                               0x5C0BC0
#define __ConvertItemTags_x                                        0x5DCA30
#define __CleanItemTags_x                                          0x47D630
#define __DoesFileExist_x                                          0x91D4D0
#define __EQGetTime_x                                              0x919F70
#define __ExecuteCmd_x                                             0x5B9400
#define __FixHeading_x                                             0x9AF8B0
#define __FlushDxKeyboard_x                                        0x6CB150
#define __GameLoop_x                                               0x6CE480
#define __get_bearing_x                                            0x5C06D0
#define __get_melee_range_x                                        0x5C0DB0
#define __GetAnimationCache_x                                      0x733810
#define __GetGaugeValueFromEQ_x                                    0x825C90
#define __GetLabelFromEQ_x                                         0x827770
#define __GetXTargetType_x                                         0x9B1290
#define __HandleMouseWheel_x                                       0x6CF360
#define __HeadingDiff_x                                            0x9AF920
#define __HelpPath_x                                               0xF711CC
#define __LoadFrontEnd_x                                           0x6CB790
#define __NewUIINI_x                                               0x825960
#define __ProcessGameEvents_x                                      0x6214C0
#define __ProcessMouseEvent_x                                      0x620C50
#define __SaveColors_x                                             0x55AF60
#define __STMLToText_x                                             0x952CC0
#define __ToggleKeyRingItem_x                                      0x519870
#define CMemoryMappedFile__SetFile_x                               0xA9E9D0
#define CrashDetected_x                                            0x6CD240
#define DrawNetStatus_x                                            0x64D660
#define Expansion_HoT_x                                            0xED311C
#define Teleport_Table_Size_x                                      0xECA814
#define Teleport_Table_x                                           0xECACD8
#define Util__FastTime_x                                           0x919B40
#define __CopyLayout_x                                             0x63B770
#define __WndProc_x                                                0x6CD740
#define __ProcessKeyboardEvent_x                                   0x6CCCE0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x490950
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x499950
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x499720
#define CAdvancedLootWnd__AddPlayerToList_x                        0x493EF0
#define CAdvancedLootWnd__UpdateMasterLooter_x                     0x493340

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x563120
#define AltAdvManager__IsAbilityReady_x                            0x561EC0
#define AltAdvManager__GetAAById_x                                 0x562250
#define AltAdvManager__CanTrainAbility_x                           0x5622C0
#define AltAdvManager__CanSeeAbility_x                             0x562620

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4CB5B0
#define CharacterZoneClient__HasSkill_x                            0x4D6430
#define CharacterZoneClient__MakeMeVisible_x                       0x4D7B50
#define CharacterZoneClient__IsStackBlocked_x                      0x4C2E30
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4BC2C0
#define CharacterZoneClient__GetItemCountWorn_x                    0x4DA4F0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4DA5D0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4DA6B0
#define CharacterZoneClient__FindAffectSlot_x                      0x4C4F10
#define CharacterZoneClient__BardCastBard_x                        0x4C7920
#define CharacterZoneClient__GetMaxEffects_x                       0x4BFCE0
#define CharacterZoneClient__GetEffect_x                           0x4BC200
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4C5F60
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4C6030
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4C6080
#define CharacterZoneClient__CalcAffectChange_x                    0x4C61D0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x4C63B0
#define CharacterZoneClient__GetFocusReuseMod_x                    0x4B4020
#define CharacterZoneClient__FindItemByGuid_x                      0x4D8AB0
#define CharacterZoneClient__FindItemByRecord_x                    0x4D8530

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6F4E40
#define CBankWnd__WndNotification_x                                0x6F4C20

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x7026D0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x62FC80
#define CButtonWnd__CButtonWnd_x                                   0x94F090

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x7228A0
#define CChatManager__InitContextMenu_x                            0x71B9D0
#define CChatManager__FreeChatWindow_x                             0x7213E0
#define CChatManager__GetLockedActiveChatWindow_x                  0x4E9D30
#define CChatManager__SetLockedActiveChatWindow_x                  0x722520
#define CChatManager__CreateChatWindow_x                           0x721A20

//ChatManagerClient
#define ChatManagerClient__Instance_x                              0x4E9E40

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x9636E0
#define CContextMenu__dCContextMenu_x                              0x963920
#define CContextMenu__AddMenuItem_x                                0x963930
#define CContextMenu__RemoveMenuItem_x                             0x963C40
#define CContextMenu__RemoveAllMenuItems_x                         0x963C60
#define CContextMenu__CheckMenuItem_x                              0x963CE0
#define CContextMenu__SetMenuItem_x                                0x963B60
#define CContextMenu__AddSeparator_x                               0x963AC0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x964280
#define CContextMenuManager__RemoveMenu_x                          0x9642F0
#define CContextMenuManager__PopupMenu_x                           0x9643B0
#define CContextMenuManager__Flush_x                               0x964220
#define CContextMenuManager__GetMenu_x                             0x49BC20
#define CContextMenuManager__CreateDefaultMenu_x                   0x72DFD0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8F4E30
#define CChatService__GetFriendName_x                              0x8F4E40

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x7230D0
#define CChatWindow__Clear_x                                       0x7243A0
#define CChatWindow__WndNotification_x                             0x724B30
#define CChatWindow__AddHistory_x                                  0x723C60

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x960B30
#define CComboWnd__Draw_x                                          0x960020
#define CComboWnd__GetCurChoice_x                                  0x960970
#define CComboWnd__GetListRect_x                                   0x9604D0
#define CComboWnd__GetTextRect_x                                   0x960BA0
#define CComboWnd__InsertChoice_x                                  0x960660
#define CComboWnd__SetColors_x                                     0x960630
#define CComboWnd__SetChoice_x                                     0x960940
#define CComboWnd__GetItemCount_x                                  0x960980
#define CComboWnd__GetCurChoiceText_x                              0x9609C0
#define CComboWnd__GetChoiceText_x                                 0x960990
#define CComboWnd__InsertChoiceAtIndex_x                           0x960700

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x72B9F0
#define CContainerWnd__vftable_x                                   0xB26854
#define CContainerWnd__SetContainer_x                              0x72CF40

// CDisplay
#define CDisplay__ZoneMainUI_x                                     0x555910
#define CDisplay__PreZoneMainUI_x                                  0x555920
#define CDisplay__CleanGameUI_x                                    0x55AD20
#define CDisplay__GetClickedActor_x                                0x54DCE0
#define CDisplay__GetUserDefinedColor_x                            0x546360
#define CDisplay__GetWorldFilePath_x                               0x54F750
#define CDisplay__is3dON_x                                         0x54A940
#define CDisplay__ReloadUI_x                                       0x554D90
#define CDisplay__WriteTextHD2_x                                   0x54A730
#define CDisplay__TrueDistance_x                                   0x551410
#define CDisplay__SetViewActor_x                                   0x54D600
#define CDisplay__GetFloorHeight_x                                 0x54AA00
#define CDisplay__SetRenderWindow_x                                0x549380
#define CDisplay__ToggleScreenshotMode_x                           0x54D0D0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x983450

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x966BE0
#define CEditWnd__EnsureCaretVisible_x                             0x968DB0
#define CEditWnd__GetCaretPt_x                                     0x967D60
#define CEditWnd__GetCharIndexPt_x                                 0x967B10
#define CEditWnd__GetDisplayString_x                               0x9679B0
#define CEditWnd__GetHorzOffset_x                                  0x966280
#define CEditWnd__GetLineForPrintableChar_x                        0x968CB0
#define CEditWnd__GetSelStartPt_x                                  0x967DC0
#define CEditWnd__GetSTMLSafeText_x                                0x9677D0
#define CEditWnd__PointFromPrintableChar_x                         0x9688E0
#define CEditWnd__SelectableCharFromPoint_x                        0x968A50
#define CEditWnd__SetEditable_x                                    0x967E90
#define CEditWnd__SetWindowTextA_x                                 0x967550
#define CEditWnd__ReplaceSelection_x                               0x968550
#define CEditWnd__ReplaceSelection1_x                              0x9684D0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x60EDA0
#define CEverQuest__ClickedPlayer_x                                0x600F20
#define CEverQuest__CreateTargetIndicator_x                        0x61E650
#define CEverQuest__DeleteTargetIndicator_x                        0x61E6E0
#define CEverQuest__DoTellWindow_x                                 0x4E9F20
#define CEverQuest__OutputTextToLog_x                              0x4EA1F0
#define CEverQuest__DropHeldItemOnGround_x                         0x5F6080
#define CEverQuest__dsp_chat_x                                     0x4EA580
#define CEverQuest__trimName_x                                     0x61A860
#define CEverQuest__Emote_x                                        0x60F600
#define CEverQuest__EnterZone_x                                    0x609690
#define CEverQuest__GetBodyTypeDesc_x                              0x613E00
#define CEverQuest__GetClassDesc_x                                 0x614440
#define CEverQuest__GetClassThreeLetterCode_x                      0x614A40
#define CEverQuest__GetDeityDesc_x                                 0x61CEA0
#define CEverQuest__GetLangDesc_x                                  0x614C00
#define CEverQuest__GetRaceDesc_x                                  0x614420
#define CEverQuest__InterpretCmd_x                                 0x61D470
#define CEverQuest__LeftClickedOnPlayer_x                          0x5FA210
#define CEverQuest__LMouseUp_x                                     0x5F85A0
#define CEverQuest__RightClickedOnPlayer_x                         0x5FAAF0
#define CEverQuest__RMouseUp_x                                     0x5F9520
#define CEverQuest__SetGameState_x                                 0x5F5E10
#define CEverQuest__UPCNotificationFlush_x                         0x61A760
#define CEverQuest__IssuePetCommand_x                              0x616000
#define CEverQuest__ReportSuccessfulHit_x                          0x610950

// CGaugeWnd 
//not sure, need to call it to see if its correct CGaugeWnd__CalcFillRect_x
#define CGaugeWnd__CalcFillRect_x                                  0x73DA60
#define CGaugeWnd__CalcLinesFillRect_x                             0x73DAC0
#define CGaugeWnd__Draw_x                                          0x73D0E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4B03A0
#define CGuild__GetGuildName_x                                     0x4AEE50
#define CGuild__GetGuildIndex_x                                    0x4AF450

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x757C90

//CHotButton
#define CHotButton__SetButtonSize_x                                0x630040

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x764D90
#define CInvSlotMgr__MoveItem_x                                    0x763A60
#define CInvSlotMgr__SelectSlot_x                                  0x764E60

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x762250
#define CInvSlot__SliderComplete_x                                 0x75FF90
#define CInvSlot__GetItemBase_x                                    0x75F900
#define CInvSlot__UpdateItem_x                                     0x75FA70

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x7668F0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x765A80
#define CInvSlotWnd__HandleLButtonUp_x                             0x766470

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x821030
#define CItemDisplayWnd__UpdateStrings_x                           0x7750F0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x76ED70
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x76F2A0
//only 1 arg now? need to check
#define CItemDisplayWnd__SetItem_x                                 0x775700
#define CItemDisplayWnd__AboutToShow_x                             0x774D50
#define CItemDisplayWnd__WndNotification_x                         0x776840
#define CItemDisplayWnd__RequestConvertItem_x                      0x7762B0
#define CItemDisplayWnd__CItemDisplayWnd_x                         0x773DB0
#define CItemDisplayWnd__dCItemDisplayWnd_x                        0x774B70

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x859AD0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x77AD80

// CLabel 
#define CLabel__Draw_x                                             0x7807F0

// CListWnd
#define CListWnd__CListWnd_x                                       0x939310
#define CListWnd__dCListWnd_x                                      0x939630
#define CListWnd__AddColumn_x                                      0x93DAA0
#define CListWnd__AddColumn1_x                                     0x93DAF0
#define CListWnd__AddLine_x                                        0x93DE80
#define CListWnd__AddString_x                                      0x93DC80
#define CListWnd__CalculateFirstVisibleLine_x                      0x93D860
#define CListWnd__CalculateVSBRange_x                              0x93D650
#define CListWnd__ClearSel_x                                       0x93E660
#define CListWnd__ClearAllSel_x                                    0x93E6C0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x93F0E0
#define CListWnd__Compare_x                                        0x93CF80
#define CListWnd__Draw_x                                           0x939760
#define CListWnd__DrawColumnSeparators_x                           0x93BF50
#define CListWnd__DrawHeader_x                                     0x93C3C0
#define CListWnd__DrawItem_x                                       0x93C8C0
#define CListWnd__DrawLine_x                                       0x93C0C0
#define CListWnd__DrawSeparator_x                                  0x93BFF0
#define CListWnd__EnableLine_x                                     0x93B830
#define CListWnd__EnsureVisible_x                                  0x93F000
#define CListWnd__ExtendSel_x                                      0x93E590
#define CListWnd__GetColumnTooltip_x                               0x93B370
#define CListWnd__GetColumnMinWidth_x                              0x93B3E0
#define CListWnd__GetColumnWidth_x                                 0x93B2E0
#define CListWnd__GetCurSel_x                                      0x93AC70
#define CListWnd__GetItemAtPoint_x                                 0x93BAB0
#define CListWnd__GetItemAtPoint1_x                                0x93BB20
#define CListWnd__GetItemData_x                                    0x93ACF0
#define CListWnd__GetItemHeight_x                                  0x93B0B0
#define CListWnd__GetItemIcon_x                                    0x93AE80
#define CListWnd__GetItemRect_x                                    0x93B920
#define CListWnd__GetItemText_x                                    0x93AD30
#define CListWnd__GetSelList_x                                     0x93E710
#define CListWnd__GetSeparatorRect_x                               0x93BD60
#define CListWnd__InsertLine_x                                     0x93E270
#define CListWnd__RemoveLine_x                                     0x93E3C0
#define CListWnd__SetColors_x                                      0x93D620
#define CListWnd__SetColumnJustification_x                         0x93D350
#define CListWnd__SetColumnLabel_x                                 0x93DC20
#define CListWnd__SetColumnWidth_x                                 0x93D270
#define CListWnd__SetCurSel_x                                      0x93E4D0
#define CListWnd__SetItemColor_x                                   0x93ECB0
#define CListWnd__SetItemData_x                                    0x93EC70
#define CListWnd__SetItemText_x                                    0x93E880
#define CListWnd__ShiftColumnSeparator_x                           0x93D410
#define CListWnd__Sort_x                                           0x93D100
#define CListWnd__ToggleSel_x                                      0x93E500
#define CListWnd__SetColumnsSizable_x                              0x93D4C0
#define CListWnd__SetItemWnd_x                                     0x93EB30
#define CListWnd__GetItemWnd_x                                     0x93AED0
#define CListWnd__SetItemIcon_x                                    0x93E900
#define CListWnd__CalculateCustomWindowPositions_x                 0x93D960
#define CListWnd__SetVScrollPos_x                                  0x93D250

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x795E50
#define CMapViewWnd__GetWorldCoordinates_x                         0x794560
#define CMapViewWnd__HandleLButtonDown_x                           0x7915A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7B61F0
#define CMerchantWnd__PurchasePageHandler__RequestGetItem_x        0x7B6AD0
#define CMerchantWnd__PurchasePageHandler__RequestPutItem_x        0x7B7000
#define CMerchantWnd__SelectRecoverySlot_x                         0x7B9F80
#define CMerchantWnd__MerchantPageHandler__SelectBuySellSlot_x     0x7B4D60
#define CMerchantWnd__SelectBuySellSlot_x                          0x7BFB40
#define CMerchantWnd__PurchasePageHandler__UpdateList_x            0x7B5E00

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8C2CF0
#define CPacketScrambler__hton_x                                   0x8C2CE0

// CSidlManager 
#define CSidlManager__FindAnimation1_x                             0x9582B0
#define CSidlManager__FindScreenPieceTemplate_x                    0x9586C0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x9584B0
#define CSidlManager__CreateLabel_x                                0x818280
#define CSidlManager__CreateXWndFromTemplate_x                     0x95B620
#define CSidlManager__CreateXWndFromTemplate1_x                    0x95B7F0
#define CSidlManager__CreateXWnd_x                                 0x8181B0
#define CSidlManager__CreateHotButtonWnd_x                         0x818770

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x954D90
#define CSidlScreenWnd__CalculateVSBRange_x                        0x954C90
#define CSidlScreenWnd__ConvertToRes_x                             0x97DF40
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x954780
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x954470
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x954540
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x954610
#define CSidlScreenWnd__DrawSidlPiece_x                            0x955230
#define CSidlScreenWnd__EnableIniStorage_x                         0x955700
#define CSidlScreenWnd__GetSidlPiece_x                             0x955420
#define CSidlScreenWnd__Init1_x                                    0x954070
#define CSidlScreenWnd__LoadIniInfo_x                              0x955750
#define CSidlScreenWnd__LoadIniListWnd_x                           0x956290
#define CSidlScreenWnd__LoadSidlScreen_x                           0x953490
#define CSidlScreenWnd__StoreIniInfo_x                             0x955E10
#define CSidlScreenWnd__StoreIniVis_x                              0x956170
#define CSidlScreenWnd__WndNotification_x                          0x955140
#define CSidlScreenWnd__GetChildItem_x                             0x955680
#define CSidlScreenWnd__HandleLButtonUp_x                          0x944E40
#define CSidlScreenWnd__m_layoutCopy_x                             0x16076B8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x695540
#define CSkillMgr__GetSkillCap_x                                   0x695720
#define CSkillMgr__GetNameToken_x                                  0x694CC0
#define CSkillMgr__IsActivatedSkill_x                              0x694E00
#define CSkillMgr__IsCombatSkill_x                                 0x694D40

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x965060
#define CSliderWnd__SetValue_x                                     0x964ED0
#define CSliderWnd__SetNumTicks_x                                  0x964F30

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x81E3C0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x96D9C0
#define CStmlWnd__ParseSTML_x                                      0x96ED10
#define CStmlWnd__CalculateHSBRange_x                              0x96EAF0
#define CStmlWnd__CalculateVSBRange_x                              0x96EA60
#define CStmlWnd__CanBreakAtCharacter_x                            0x972E20
#define CStmlWnd__FastForwardToEndOfTag_x                          0x973AB0
#define CStmlWnd__ForceParseNow_x                                  0x96DFB0
#define CStmlWnd__GetNextTagPiece_x                                0x972D80
#define CStmlWnd__GetSTMLText_x                                    0x50AC50
#define CStmlWnd__GetVisibleText_x                                 0x96DFD0
#define CStmlWnd__InitializeWindowVariables_x                      0x973900
#define CStmlWnd__MakeStmlColorTag_x                               0x96D030
#define CStmlWnd__MakeWndNotificationTag_x                         0x96D0A0
#define CStmlWnd__SetSTMLText_x                                    0x96C0E0
#define CStmlWnd__StripFirstSTMLLines_x                            0x974BB0
#define CStmlWnd__UpdateHistoryString_x                            0x973CC0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x96B220
#define CTabWnd__DrawCurrentPage_x                                 0x96B950
#define CTabWnd__DrawTab_x                                         0x96B670
#define CTabWnd__GetCurrentPage_x                                  0x96AA20
#define CTabWnd__GetPageInnerRect_x                                0x96AC60
#define CTabWnd__GetTabInnerRect_x                                 0x96ABA0
#define CTabWnd__GetTabRect_x                                      0x96AA50
#define CTabWnd__InsertPage_x                                      0x96AE70
#define CTabWnd__RemovePage_x                                      0x96AFE0
#define CTabWnd__SetPage_x                                         0x96ACE0
#define CTabWnd__SetPageRect_x                                     0x96B160
#define CTabWnd__UpdatePage_x                                      0x96B530
#define CTabWnd__GetPageFromTabIndex_x                             0x96B5B0
#define CTabWnd__GetCurrentTabIndex_x                              0x96AA10

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x77B170
#define CPageWnd__SetTabText_x                                     0x96A560
#define CPageWnd__FlashTab_x                                       0x96A5C0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4A96D0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x941D00
#define CTextureFont__GetTextExtent_x                              0x941EC0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x6C8610
#define CHtmlComponentWnd__ValidateUri_x                           0x759680
#define CHtmlWnd__SetClientCallbacks_x                             0x6350E0
#define CHtmlWnd__AddObserver_x                                    0x635100
#define CHtmlWnd__RemoveObserver_x                                 0x635160
#define Window__getProgress_x                                      0x8785A0
#define Window__getStatus_x                                        0x8785C0
#define Window__getURI_x                                           0x8785D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x97AD50

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x92EF30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4E9C20
#define CXStr__CXStr1_x                                            0xA05E10
#define CXStr__CXStr3_x                                            0x915F30
#define CXStr__dCXStr_x                                            0x478800
#define CXStr__operator_equal_x                                    0x916160
#define CXStr__operator_equal1_x                                   0x9161A0
#define CXStr__operator_plus_equal1_x                              0x916C30
#define CXStr__SetString_x                                         0x918B20
#define CXStr__operator_char_p_x                                   0x916670
#define CXStr__GetChar_x                                           0x918470
#define CXStr__Delete_x                                            0x917D20
#define CXStr__GetUnicode_x                                        0x9184E0
#define CXStr__GetLength_x                                         0x4A9480
#define CXStr__Mid_x                                               0x47D9E0
#define CXStr__Insert_x                                            0x918540
#define CXStr__FindNext_x                                          0x918190

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x9632F0
#define CXWnd__BringToTop_x                                        0x948620
#define CXWnd__Center_x                                            0x9481A0
#define CXWnd__ClrFocus_x                                          0x947FC0
#define CXWnd__Destroy_x                                           0x948060
#define CXWnd__DoAllDrawing_x                                      0x9445D0
#define CXWnd__DrawChildren_x                                      0x9445A0
#define CXWnd__DrawColoredRect_x                                   0x944A30
#define CXWnd__DrawTooltip_x                                       0x9430E0
#define CXWnd__DrawTooltipAtPoint_x                                0x9431A0
#define CXWnd__GetBorderFrame_x                                    0x944890
#define CXWnd__GetChildWndAt_x                                     0x9486C0
#define CXWnd__GetClientClipRect_x                                 0x946840
#define CXWnd__GetScreenClipRect_x                                 0x946910
#define CXWnd__GetScreenRect_x                                     0x946AE0
#define CXWnd__GetRelativeRect_x                                   0x946BB0
#define CXWnd__GetTooltipRect_x                                    0x944A80
#define CXWnd__GetWindowTextA_x                                    0x49D3A0
#define CXWnd__IsActive_x                                          0x9451C0
#define CXWnd__IsDescendantOf_x                                    0x947510
#define CXWnd__IsReallyVisible_x                                   0x947540
#define CXWnd__IsType_x                                            0x948D30
#define CXWnd__Move_x                                              0x9475A0
#define CXWnd__Move1_x                                             0x947650
#define CXWnd__ProcessTransition_x                                 0x948150
#define CXWnd__Refade_x                                            0x947930
#define CXWnd__Resize_x                                            0x947BD0
#define CXWnd__Right_x                                             0x9483E0
#define CXWnd__SetFocus_x                                          0x947F80
#define CXWnd__SetFont_x                                           0x947FF0
#define CXWnd__SetKeyTooltip_x                                     0x948B50
#define CXWnd__SetMouseOver_x                                      0x945A00
#define CXWnd__StartFade_x                                         0x9473F0
#define CXWnd__GetChildItem_x                                      0x948830
#define CXWnd__SetParent_x                                         0x9472A0
#define CXWnd__Minimize_x                                          0x947C40

// CScreenPieceTemplate
#define CScreenPieceTemplate__IsType_x                             0x97EFC0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x94B570
#define CXWndManager__DrawWindows_x                                0x94B590
#define CXWndManager__GetKeyboardFlags_x                           0x94DCB0
#define CXWndManager__HandleKeyboardMsg_x                          0x94D860
#define CXWndManager__RemoveWnd_x                                  0x94DEE0
#define CXWndManager__RemovePendingDeletionWnd_x                   0x94E460

// CDBStr
#define CDBStr__GetString_x                                        0x545300

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4C0440
#define EQ_Character__Cur_HP_x                                     0x4D3470
#define EQ_Character__Cur_Mana_x                                   0x4DABB0
#define EQ_Character__GetCastingTimeModifier_x                     0x4C3490
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4B3C60
#define EQ_Character__GetFocusRangeModifier_x                      0x4B3DB0
#define EQ_Character__GetHPRegen_x                                 0x4E09F0
#define EQ_Character__GetEnduranceRegen_x                          0x4E0FF0
#define EQ_Character__GetManaRegen_x                               0x4E1430
#define EQ_Character__Max_Endurance_x                              0x65B9B0
#define EQ_Character__Max_HP_x                                     0x4D32A0
#define EQ_Character__Max_Mana_x                                   0x65B7B0
#define EQ_Character__doCombatAbility_x                            0x65DD90
#define EQ_Character__UseSkill_x                                   0x4E3220
#define EQ_Character__GetConLevel_x                                0x6545F0
#define EQ_Character__IsExpansionFlag_x                            0x5B7BE0
#define EQ_Character__TotalEffect_x                                0x4C7210
#define EQ_Character__GetPCSpellAffect_x                           0x4C41E0
#define EQ_Character__SpellDuration_x                              0x4C3D10
#define EQ_Character__MySpellDuration_x                            0x4B2590
#define EQ_Character__GetAdjustedSkill_x                           0x4D61F0
#define EQ_Character__GetBaseSkill_x                               0x4D7190
#define EQ_Character__CanUseItem_x                                 0x4DAEC0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x8E1DF0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x671D10

//PcClient
#define PcClient__vftable_x                                        0xB1800C
#define PcClient__PcClient_x                                       0x651D50

//CCharacterListWnd
#define CCharacterListWnd__SelectCharacter_x                       0x4BAE60
#define CCharacterListWnd__EnterWorld_x                            0x4BA840
#define CCharacterListWnd__Quit_x                                  0x4BA590
#define CCharacterListWnd__UpdateList_x                            0x4BAA30

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x6362C0
#define EQ_Item__CreateItemTagString_x                             0x8BC310
#define EQ_Item__IsStackable_x                                     0x8C0F80
#define EQ_Item__GetImageNum_x                                     0x8BDE90
#define EQ_Item__CreateItemClient_x                                0x635500
#define EQ_Item__GetItemValue_x                                    0x8BF190
#define EQ_Item__ValueSellMerchant_x                               0x8C28D0
#define EQ_Item__IsKeyRingItem_x                                   0x8C08A0
#define EQ_Item__CanGoInBag_x                                      0x6363E0
#define EQ_Item__IsEmpty_x                                         0x8C03E0
#define EQ_Item__GetMaxItemCount_x                                 0x8BF5A0
#define EQ_Item__GetHeldItem_x                                     0x8BDD60
#define EQ_Item__GetAugmentFitBySlot_x                             0x8BBC50

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x563DF0
#define EQ_LoadingS__Array_x                                       0xC3FC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x65C2B0
#define EQ_PC__GetAlternateAbilityId_x                             0x8CB8C0
#define EQ_PC__GetCombatAbility_x                                  0x8CBF30
#define EQ_PC__GetCombatAbilityTimer_x                             0x8CBFA0
#define EQ_PC__GetItemRecastTimer_x                                0x65E310
#define EQ_PC__HasLoreItem_x                                       0x654E00
#define EQ_PC__AlertInventoryChanged_x                             0x653F20
#define EQ_PC__GetPcZoneClient_x                                   0x680E10
#define EQ_PC__RemoveMyAffect_x                                    0x661540
#define EQ_PC__GetKeyRingItems_x                                   0x8CC830
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8CC5C0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8CCB30

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5BE0D0
#define EQItemList__add_object_x                                   0x5EB730
#define EQItemList__add_item_x                                     0x5BE630
#define EQItemList__delete_item_x                                  0x5BE680
#define EQItemList__FreeItemList_x                                 0x5BE580

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x541E30

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x673610
#define EQPlayer__dEQPlayer_x                                      0x6669B0
#define EQPlayer__DoAttack_x                                       0x67B5B0
#define EQPlayer__EQPlayer_x                                       0x667070
#define EQPlayer__SetNameSpriteState_x                             0x66B340
#define EQPlayer__SetNameSpriteTint_x                              0x66C220
#define PlayerBase__HasProperty_j_x                                0x9ADCB0
#define EQPlayer__IsTargetable_x                                   0x9AE150
#define EQPlayer__CanSee_x                                         0x9ADFB0
#define EQPlayer__CanSee1_x                                        0x9AE080
#define PlayerBase__GetVisibilityLineSegment_x                     0x9ADD70

//PlayerZoneClient
#define PlayerZoneClient__ChangeHeight_x                           0x67E8B0
#define PlayerZoneClient__GetLevel_x                               0x680E50
#define PlayerZoneClient__IsValidTeleport_x                        0x5EC8A0
#define PlayerZoneClient__LegalPlayerRace_x                        0x55CC30

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x676450
#define EQPlayerManager__GetSpawnByName_x                          0x676500
#define EQPlayerManager__GetPlayerFromPartialName_x                0x676590

// KeyPressHandler
#define KeypressHandler__Get_x                                     0x6399B0
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x639A30
#define KeypressHandler__AttachKeyToEqCommand_x                    0x639A70
#define KeypressHandler__ClearCommandStateArray_x                  0x63AE80
#define KeypressHandler__HandleKeyDown_x                           0x63AEA0
#define KeypressHandler__HandleKeyUp_x                             0x63AF40
#define KeypressHandler__SaveKeymapping_x                          0x63B390

// MapViewMap 
#define MapViewMap__Clear_x                                        0x791CC0
#define MapViewMap__SaveEx_x                                       0x795080
#define MapViewMap__SetZoom_x                                      0x799740

// PlayerPointManager
#define PlayerPointManager__GetAltCurrency_x                       0x8DFDA0

// StringTable 
#define StringTable__getString_x                                   0x8DAB90

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x6611B0
#define PcZoneClient__RemovePetEffect_x                            0x6617E0
#define PcZoneClient__HasAlternateAbility_x                        0x65B5E0
#define PcZoneClient__GetCurrentMod_x                              0x4E62E0
#define PcZoneClient__GetModCap_x                                  0x4E61E0
#define PcZoneClient__CanEquipItem_x                               0x65BC90
#define PcZoneClient__GetItemByID_x                                0x65E780
#define PcZoneClient__GetItemByItemClass_x                         0x65E8D0
#define PcZoneClient__RemoveBuffEffect_x                           0x661800
#define PcZoneClient__BandolierSwap_x                              0x65C860
#define PcZoneClient__GetLinkedSpellReuseTimer_x                   0x65E2B0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5F14E0

//IconCache
#define IconCache__GetIcon_x                                       0x7330B0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x72AB90
#define CContainerMgr__CloseContainer_x                            0x72AE60
#define CContainerMgr__OpenExperimentContainer_x                   0x72B8E0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7EA3C0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x62E440

//CLootWnd
#define CLootWnd__LootAll_x                                        0x788280
#define CLootWnd__RequestLootSlot_x                                0x787560

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x58AB80
#define EQ_Spell__SpellAffects_x                                   0x58AFF0
#define EQ_Spell__SpellAffectBase_x                                0x58ADB0
#define EQ_Spell__IsStackable_x                                    0x4CAEA0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4CAC90
#define EQ_Spell__GetSpellAffectByIndex_x                          0x4B8150
#define EQ_Spell__IsSPAStacking_x                                  0x58BE40
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x58B350
#define EQ_Spell__IsNoRemove_x                                     0x4CAE80
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x58BE50
#define __IsResEffectSpell_x                                       0x4CA150

//EQSpellStrings
#define EQSpellStrings__GetString_x                                0x4AD8C0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x8EA490

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x831690
#define CTargetWnd__WndNotification_x                              0x830ED0
#define CTargetWnd__RefreshTargetBuffs_x                           0x8311A0
#define CTargetWnd__HandleBuffRemoveRequest_x                      0x830030

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x835CD0
#define CTaskWnd__ConfirmAbandonTask_x                             0x838910

//CTaskManager
#define CTaskManager__GetEntry_x                                   0x53F8B0
#define CTaskManager__HandleMessage_x                              0x53DD60
#define CTaskManager__GetTaskStatus_x                              0x53F960
#define CTaskManager__GetElementDescription_x                      0x53F9E0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x585BD0
#define EqSoundManager__PlayScriptMp3_x                            0x585E90
#define EqSoundManager__SoundAssistPlay_x                          0x699520
#define EqSoundManager__WaveInstancePlay_x                         0x698A90

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x530E40

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x969A70
#define CTextureAnimation__Draw_x                                  0x969C70

//CTAFrameDraw
#define CTAFrameDraw__Draw_x                                       0x9659C0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x56B9A0
#define CAltAbilityData__GetMercMaxRank_x                          0x56B930
#define CAltAbilityData__GetMaxRank_x                              0x560D40

//CTargetRing
#define CTargetRing__Cast_x                                        0x62C560

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4CAC70
#define CharacterBase__CreateItemGlobalIndex_x                     0x517A50
#define CharacterBase__CreateItemIndex_x                           0x634690
#define CharacterBase__GetItemPossession_x                         0x503550
#define CharacterBase__GetItemByGlobalIndex_x                      0x8F2AE0
#define CharacterBase__GetItemByGlobalIndex1_x                     0x8F2B40
//#define CharacterBase__GetEffectId_x                               

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x711C60
#define CCastSpellWnd__IsBardSongPlaying_x                         0x712490
#define CCastSpellWnd__RefreshSpellGemButtons_x                    0x712540

//messages
#define msg_spell_worn_off_x                                       0x5AFC90
#define msg_new_text_x                                             0x5A4620
#define __msgTokenTextParam_x                                      0x5B1F30
#define msgTokenText_x                                             0x5B2180

//SpellManager
#define SpellManager__vftable_x                                    0xB00304
#define SpellManager__SpellManager_x                               0x69C860
#define Spellmanager__LoadTextSpells_x                             0x69D150
#define SpellManager__GetSpellByGroupAndRank_x                     0x69CA30

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9B1B80

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x5180D0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x5B6110
#define ItemGlobalIndex__IsEquippedLocation_x                      0x64D4C0
#define ItemGlobalIndex__IsValidIndex_x                            0x518160

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x8EAE30
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x8EB0B0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x780B30

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x72F270
#define CCursorAttachment__AttachToCursor1_x                       0x72F2B0
#define CCursorAttachment__Deactivate_x                            0x7302A0

//CSidlManagerBase
#define CSidlManagerBase__CreateTabWnd_x                           0x95C640
#define CSidlManagerBase__CreatePageWnd_x                          0x95BE40
//int
#define CSidlManagerBase__FindButtonDrawTemplate_x                 0x9580D0
//CXStr
#define CSidlManagerBase__FindButtonDrawTemplate1_x                0x958060

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x979710
#define CEQSuiteTextureLoader__GetTexture_x                        0x9793D0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x514FD0
#define CFindItemWnd__WndNotification_x                            0x515AB0
#define CFindItemWnd__Update_x                                     0x516620
#define CFindItemWnd__PickupSelectedItem_x                         0x5147F0

//IString
#define IString__Append_x                                          0x504D70

//Camera
#define CDisplay__cameraType_x                                     0xE181EC
#define EverQuest__Cameras_x                                       0xED346C

//LootFiltersManager
#define LootFiltersManager__AddItemLootFilter_x                    0x51DA10
#define LootFiltersManager__GetItemFilterData_x                    0x51D310
#define LootFiltersManager__RemoveItemLootFilter_x                 0x51D340
#define LootFiltersManager__SetItemLootFilter_x                    0x51D560

//COptionsWnd
#define COptionsWnd__FillChatFilterList_x                          0x7D81A0

//CResolutionHandler__UpdateResolution_x
#define CResolutionHandler__UpdateResolution_x                     0x9B76C0
#define CResolutionHandler__GetWindowedStyle_x                     0x6940A0

//CColorPickerWnd
#define CColorPickerWnd__Open_x                                    0x727840

//CDistillerInfo
#define CDistillerInfo__GetIDFromRecordNum_x                       0x900410
#define CDistillerInfo__Instance_x                                 0x9003B0

//CGroupWnd
#define CGroupWnd__WndNotification_x                               0x746A40
#define CGroupWnd__UpdateDisplay_x                                 0x745D90

//ItemBase
#define ItemBase__IsLore_x                                         0x8C0950
#define ItemBase__IsLoreEquipped_x                                 0x8C09C0

//EQPlacedItemManager
#define EQPlacedItemManager__Instance_x                            0x5EB690
#define EQPlacedItemManager__GetItemByGuid_x                       0x5EB7D0
#define EQPlacedItemManager__GetItemByRealEstateAndRealEstateItemIds_x 0x5EB830

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x689590
#define RealEstateManagerClient__GetItemByRealEstateAndItemIds_x   0x68CF20

//CFactionWnd
#define CFactionWnd__CFactionWnd_x                                 0x50B250

//FactionManagerClient
#define FactionManagerClient__Instance_x                           0x4F74A0
#define FactionManagerClient__HandleFactionMessage_x               0x4F7B10
//work in progress, these needs to be investigated
#define FactionManagerClient__GetFactionStanding_x                 0x4F8110
#define FactionManagerClient__GetMaxFaction_x                      0x4F812F
#define FactionManagerClient__GetMinFaction_x                      0x4F80E0

//BaseProfile (PCHARINFO2)
#define BaseProfile__GetItemPossession_x                           0x503520

//ArrayClass
#define ArrayClass__DeleteElement_x                                0x940D50

//AggroMeterManagerClient
#define AggroMeterManagerClient__Instance_x                        0x49C6B0

//ClientSOIManager
#define ClientSOIManager__GetSingleton_x                           0x503780

//MercenaryAlternateAdvancementManagerClient
#define MercenaryAlternateAdvancementManagerClient__Instance_x     0x56AE40

//CTargetManager
#define CTargetManager__Get_x                                      0x6A00A0

//RealEstateManagerClient
#define RealEstateManagerClient__Instance_x                        0x689590

//CBroadcast (returns what we called pinstCTextOverlay_x)
#define CBroadcast__Get_x                                          0x4A9490

//EQGroundItemListManager
#define EQGroundItemListManager__Instance_x                        0x5BE520

//EverQuestinfo
#define EverQuestinfo__IsItemPending_x                             0xF70B00

//CAAWnd
#define CAAWnd__ShowAbility_x                                      0x6DB6B0
#define CAAWnd__UpdateSelected_x                                   0x6D7F20
#define CAAWnd__Update_x                                           0x6DA9D0

//CXRect
#define CXRect__operator_and_x                                     0x73DB20

//CUnSerializeBuffer
#define CUnSerializeBuffer__GetString_x                            0x4836B0

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
