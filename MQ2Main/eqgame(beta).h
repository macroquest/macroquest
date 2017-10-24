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
#if defined(LIVE)
#include "eqgame-private(live).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Oct 24 2017"
#define __ExpectedVersionTime                                     "04:17:45"
#define __ActualVersionDate_x                                      0xAEE3D0
#define __ActualVersionTime_x                                      0xAEE3DC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5ABEA0
#define __MemChecker1_x                                            0x8AB040
#define __MemChecker2_x                                            0x642010
#define __MemChecker3_x                                            0x641F60
#define __MemChecker4_x                                            0x7FCD30
#define __EncryptPad0_x                                            0xC4C6A0
#define __EncryptPad1_x                                            0xD288E8
#define __EncryptPad2_x                                            0xC76268
#define __EncryptPad3_x                                            0xC75E68
#define __EncryptPad4_x                                            0xD16EE8
#define __EncryptPad5_x                                            0x10D2218
#define __AC1_x                                                    0x7BBF05
#define __AC2_x                                                    0x564937
#define __AC3_x                                                    0x562AB0
#define __AC4_x                                                    0x574CD1
#define __AC5_x                                                    0x588AAB
#define __AC6_x                                                    0x58C65E
#define __AC7_x                                                    0x5830AC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA4BA0

// Direct Input
#define DI8__Main_x                                                0x10D21F0
#define DI8__Keyboard_x                                            0x10D21F4
#define DI8__Mouse_x                                               0x10D21F8
#define DI8__Mouse_Copy_x                                          0xF40224
#define DI8__Mouse_Check_x                                         0xFC9EDC
#define __AutoSkillArray_x                                         0xF41138
#define __Attack_x                                                 0xFC4833
#define __Autofire_x                                               0xFC4834
#define __BindList_x                                               0xC27058
#define g_eqCommandStates_x                                        0xF2EF70
#define __Clicks_x                                                 0xF402E0
#define __CommandList_x                                            0xC29770
#define __CurrentMapLabel_x                                        0x10D81E8
#define __CurrentSocial_x                                          0xBF65D0
#define __DoAbilityList_x                                          0xF769F8
#define __do_loot_x                                                0x5335F0
#define __DrawHandler_x                                            0x1741F54
#define __GroupCount_x                                             0xF3087A

#define __Guilds_x                                                 0xF36490
#define __gWorld_x                                                 0xF32D34
#define __HotkeyPage_x                                             0xFBD3F8
#define __HWnd_x                                                   0xFC9FF8
#define __InChatMode_x                                             0xF4020C
#define __LastTell_x                                               0xF420F4
#define __LMouseHeldTime_x                                         0xF4034C
#define __Mouse_x                                                  0x10D21FC
#define __MouseLook_x                                              0xF402A6
#define __MouseEventTime_x                                         0xFC50BC
#define __gpbCommandEvent_x                                        0xF32DFC
#define __NetStatusToggle_x                                        0xF402A9
#define __PCNames_x                                                0xF416FC
#define __RangeAttackReady_x                                       0xF4141C
#define __RMouseHeldTime_x                                         0xF40348
#define __RunWalkState_x                                           0xF40210
#define __ScreenMode_x                                             0xE7EB50
#define __ScreenX_x                                                0xF401C4
#define __ScreenY_x                                                0xF401C0
#define __ScreenXMax_x                                             0xF401C8
#define __ScreenYMax_x                                             0xF401CC
#define __ServerHost_x                                             0xF307C4
#define __ServerName_x                                             0xF769B8
#define __ShiftKeyDown_x                                           0xF408A0
#define __ShowNames_x                                              0xF415DC
#define __Socials_x                                                0xF76AB8
#define __SubscriptionType_x                                       0x1108A5C
#define __TargetAggroHolder_x                                      0x10DA434
#define __ZoneType_x                                               0xF406A4
#define __GroupAggro_x                                             0x10DA474
#define __LoginName_x                                              0xFC8AD4
#define __Inviter_x                                                0xFC47B0
#define __AttackOnAssist_x                                         0xF41598
#define __UseTellWindows_x                                         0xF41894

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF32E20
#define instEQZoneInfo_x                                           0xF4049C
#define instKeypressHandler_x                                      0xFC50A0
#define pinstActiveBanker_x                                        0xF32DD8
#define pinstActiveCorpse_x                                        0xF32DDC
#define pinstActiveGMaster_x                                       0xF32DE0
#define pinstActiveMerchant_x                                      0xF32DD4
#define pinstAggroInfo_x                                           0xD3C1A8
#define pinstAltAdvManager_x                                       0xE7FCB8
#define pinstAuraMgr_x                                             0xD4C9C0
#define pinstBandageTarget_x                                       0xF32DC0
#define pinstCamActor_x                                            0xE7F588
#define pinstCDBStr_x                                              0xE7EAE4
#define pinstCDisplay_x                                            0xF32DE8
#define pinstCEverQuest_x                                          0x10D2370
#define pinstEverQuestInfo_x                                       0xF401B8
#define pinstCharData_x                                            0xF32DA4
#define pinstCharSpawn_x                                           0xF32DCC
#define pinstControlledMissile_x                                   0xF32DA0
#define pinstControlledPlayer_x                                    0xF32DCC
#define pinstCSidlManager_x                                        0x1740EC0
#define pinstCXWndManager_x                                        0x1740EB8
#define instDynamicZone_x                                          0xF40058
#define pinstDZMember_x                                            0xF40168
#define pinstDZTimerInfo_x                                         0xF4016C
#define pinstEQItemList_x                                          0xF2F248
#define pinstEQObjectList_x                                        0xF30274
#define instEQMisc_x                                               0xC0F498
#define pinstEQSoundManager_x                                      0xE80288
#define instExpeditionLeader_x                                     0xF400A2
#define instExpeditionName_x                                       0xF400E2
#define pinstGroup_x                                               0xF30876
#define pinstImeManager_x                                          0x1740EC4
#define pinstLocalPlayer_x                                         0xF32DB8
#define pinstMercenaryData_x                                       0xFC5720
#define pinstMercenaryStats_x                                      0x10DA580
#define pinstMercAltAbilities_x                                    0xE80040
#define pinstModelPlayer_x                                         0xF32DE4
#define pinstPCData_x                                              0xF32DA4
#define pinstSkillMgr_x                                            0xFC6790
#define pinstSpawnManager_x                                        0xFC5F70
#define pinstSpellManager_x                                        0xFC68D8
#define pinstSpellSets_x                                           0xFBD45C
#define pinstStringTable_x                                         0xF32D4C
#define pinstSwitchManager_x                                       0xF30408
#define pinstTarget_x                                              0xF32DD0
#define pinstTargetObject_x                                        0xF32DA8
#define pinstTargetSwitch_x                                        0xF32DAC
#define pinstTaskMember_x                                          0xE7EA30
#define pinstTrackTarget_x                                         0xF32DC4
#define pinstTradeTarget_x                                         0xF32DB4
#define instTributeActive_x                                        0xC0F4BD
#define pinstViewActor_x                                           0xE7F584
#define pinstWorldData_x                                           0xF32D88
#define pinstZoneAddr_x                                            0xF4073C
#define pinstPlayerPath_x                                          0xFC5FD0
#define pinstTargetIndicator_x                                     0xFC6A70
#define pinstCTargetManager_x                                      0xFC6AD0
#define EQObject_Top_x                                             0xF32D98
#define pinstRealEstateItems_x                                     0xFC65FC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE7F4A0
#define pinstCAchievementsWnd_x                                    0xE7F4FC
#define pinstCTextOverlay_x                                        0xD3C750
#define pinstCAudioTriggersWindow_x                                0xD3C538
#define pinstCCharacterSelect_x                                    0xE7F40C
#define pinstCFacePick_x                                           0xE7F1BC
#define pinstCFindItemWnd_x                                        0xE7F49C
#define pinstCNoteWnd_x                                            0xE7F3C4
#define pinstCBookWnd_x                                            0xE7F3CC
#define pinstCPetInfoWnd_x                                         0xE7F3D0
#define pinstCTrainWnd_x                                           0xE7F3D4
#define pinstCSkillsWnd_x                                          0xE7F3D8
#define pinstCSkillsSelectWnd_x                                    0xE7F3DC
#define pinstCCombatSkillsSelectWnd_x                              0xE7F3E0
#define pinstCFriendsWnd_x                                         0xE7F3E4
#define pinstCAuraWnd_x                                            0xE7F3E8
#define pinstCRespawnWnd_x                                         0xE7F3EC
#define pinstCBandolierWnd_x                                       0xE7F3F0
#define pinstCPotionBeltWnd_x                                      0xE7F3F4
#define pinstCAAWnd_x                                              0xE7F3F8
#define pinstCAlarmWnd_x                                           0xE7F404
#define pinstCGroupSearchFiltersWnd_x                              0xE7F3FC
#define pinstCLoadskinWnd_x                                        0xE7F400
#define pinstCLargeDialogWnd_x                                     0x10D94E0
#define pinstCMusicPlayerWnd_x                                     0xE7F408
#define pinstCMailWnd_x                                            0xE7F410
#define pinstCMailCompositionWnd_x                                 0xE7F414
#define pinstCMailAddressBookWnd_x                                 0xE7F418
#define pinstCRaidWnd_x                                            0xE7F420
#define pinstCRaidOptionsWnd_x                                     0xE7F424
#define pinstCBreathWnd_x                                          0xE7F428
#define pinstCMapViewWnd_x                                         0xE7F42C
#define pinstCMapToolbarWnd_x                                      0xE7F430
#define pinstCEditLabelWnd_x                                       0xE7F434
#define pinstCTargetWnd_x                                          0xE7F438
#define pinstCColorPickerWnd_x                                     0xE7F43C
#define pinstCPlayerWnd_x                                          0xE7F440
#define pinstCOptionsWnd_x                                         0xE7F444
#define pinstCBuffWindowNORMAL_x                                   0xE7F448
#define pinstCBuffWindowSHORT_x                                    0xE7F44C
#define pinstCharacterCreation_x                                   0xE7F450
#define pinstCCursorAttachment_x                                   0xE7F454
#define pinstCCastingWnd_x                                         0xE7F458
#define pinstCCastSpellWnd_x                                       0xE7F45C
#define pinstCSpellBookWnd_x                                       0xE7F460
#define pinstCInventoryWnd_x                                       0xE7F464
#define pinstCBankWnd_x                                            0xE7F46C
#define pinstCQuantityWnd_x                                        0xE7F470
#define pinstCLootWnd_x                                            0xE7F474
#define pinstCActionsWnd_x                                         0xE7F478
#define pinstCCombatAbilityWnd_x                                   0xE7F480
#define pinstCMerchantWnd_x                                        0xE7F484
#define pinstCTradeWnd_x                                           0xE7F48C
#define pinstCSelectorWnd_x                                        0xE7F490
#define pinstCBazaarWnd_x                                          0xE7F494
#define pinstCBazaarSearchWnd_x                                    0xE7F498
#define pinstCGiveWnd_x                                            0xE7F4B8
#define pinstCTrackingWnd_x                                        0xE7F4C0
#define pinstCInspectWnd_x                                         0xE7F4C4
#define pinstCSocialEditWnd_x                                      0xE7F4C8
#define pinstCFeedbackWnd_x                                        0xE7F4CC
#define pinstCBugReportWnd_x                                       0xE7F4D0
#define pinstCVideoModesWnd_x                                      0xE7F4D4
#define pinstCTextEntryWnd_x                                       0xE7F4DC
#define pinstCFileSelectionWnd_x                                   0xE7F4E0
#define pinstCCompassWnd_x                                         0xE7F4E4
#define pinstCPlayerNotesWnd_x                                     0xE7F4E8
#define pinstCGemsGameWnd_x                                        0xE7F4EC
#define pinstCTimeLeftWnd_x                                        0xE7F508
#define pinstCPetitionQWnd_x                                       0xE7F50C
#define pinstCStoryWnd_x                                           0xE7F510
#define pinstCJournalTextWnd_x                                     0xE7F514
#define pinstCJournalCatWnd_x                                      0xE7F518
#define pinstCBodyTintWnd_x                                        0xE7F51C
#define pinstCServerListWnd_x                                      0xE7F520
#define pinstCAvaZoneWnd_x                                         0xE7F52C
#define pinstCBlockedBuffWnd_x                                     0xE7F530
#define pinstCBlockedPetBuffWnd_x                                  0xE7F534
#define pinstCInvSlotMgr_x                                         0xE7F57C
#define pinstCContainerMgr_x                                       0xE7F580
#define pinstCAdventureLeaderboardWnd_x                            0x10D2D20
#define pinstCAdventureRequestWnd_x                                0x10D2D98
#define pinstCAltStorageWnd_x                                      0x10D3078
#define pinstCAdventureStatsWnd_x                                  0x10D2E10
#define pinstCBarterMerchantWnd_x                                  0x10D3DC0
#define pinstCBarterSearchWnd_x                                    0x10D3E38
#define pinstCBarterWnd_x                                          0x10D3EB0
#define pinstCChatWindowManager_x                                  0x10D46C0
#define pinstCDynamicZoneWnd_x                                     0x10D4BF0
#define pinstCEQMainWnd_x                                          0x10D4DB8
#define pinstCFellowshipWnd_x                                      0x10D4B84
#define pinstCFindLocationWnd_x                                    0x10D5088
#define pinstCGroupSearchWnd_x                                     0x10D5358
#define pinstCGroupWnd_x                                           0x10D53D0
#define pinstCGuildBankWnd_x                                       0x10D5448
#define pinstCGuildMgmtWnd_x                                       0x10D7538
#define pinstCHotButtonWnd_x                                       0x10D7634
#define pinstCHotButtonWnd1_x                                      0x10D7634
#define pinstCHotButtonWnd2_x                                      0x10D7638
#define pinstCHotButtonWnd3_x                                      0x10D763C
#define pinstCHotButtonWnd4_x                                      0x10D7660
#define pinstCItemDisplayManager_x                                 0x10D7AB8
#define pinstCItemExpTransferWnd_x                                 0x10D7BB4
#define pinstCLFGuildWnd_x                                         0x10D7E90
#define pinstCMIZoneSelectWnd_x                                    0x10D8470
#define pinstCConfirmationDialog_x                                 0x10D8B78
#define pinstCPopupWndManager_x                                    0x10D8B78
#define pinstCProgressionSelectionWnd_x                            0x10D8C68
#define pinstCPvPStatsWnd_x                                        0x10D8D58
#define pinstCTaskWnd_x                                            0x10DA860
#define pinstCTaskSomething_x                                      0xD4D5D8
#define pinstCTaskTemplateSelectWnd_x                              0x10DA7E8
#define pinstCTipWndOFDAY_x                                        0x10DA9C8
#define pinstCTipWndCONTEXT_x                                      0x10DA9CC
#define pinstCTitleWnd_x                                           0x10DAA48
#define pinstCContextMenuManager_x                                 0x1740D48
#define pinstCVoiceMacroWnd_x                                      0xFC6EA8
#define pinstCHtmlWnd_x                                            0xFC6F98
#define pinstItemIconCache_x                                       0x10D4D60
#define pinstCTradeskillWnd_x                                      0x10DAB48
#define pinstCAdvancedLootWnd_x                                    0xE7F570
#define pinstRewardSelectionWnd_x                                  0x10D9280
#define pinstEQSuiteTextureLoader_x                                0xD2A7B0
#define pinstCPointMerchantWnd_x                                   0x10D8B00

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x54B100
#define __CastRay2_x                                               0x54AA30
#define __HeadingDiff_x                                            0x93B540
#define __FixHeading_x                                             0x93B4D0
#define __get_bearing_x                                            0x53A740
#define __ConvertItemTags_x                                        0x538210
#define __ExecuteCmd_x                                             0x522AC0
#define __EQGetTime_x                                              0x8AA9E0
#define __get_melee_range_x                                        0x529790
#define __GetGaugeValueFromEQ_x                                    0x7BAAC0
#define __GetLabelFromEQ_x                                         0x7BBE90
#define __ToggleKeyRingItem_x                                      0x490930
#define __GetXTargetType_x                                         0x93D140
#define __LoadFrontEnd_x                                           0x6416E0
#define __NewUIINI_x                                               0x7BA490
#define __ProcessGameEvents_x                                      0x584E40
#define __ProcessMouseEvent_x                                      0x5845E0
#define CrashDetected_x                                            0x6430A0
#define wwsCrashReportCheckForUploader_x                           0x808CA0
#define __AppCrashWrapper_x                                        0xC75E5C
#define __pCrashHandler_x                                          0x10E7A28
#define __CrashHandler_x                                           0x808730
#define wwsCrashReportPlatformLaunchUploader_x                     0x80AED0
#define DrawNetStatus_x                                            0x5BB9C0
#define Util__FastTime_x                                           0x8AA680
#define Expansion_HoT_x                                            0xF41588
#define __HelpPath_x                                               0xFC4E28
#define __STMLToText_x                                             0x8F0F60
#define __GetAnimationCache_x                                      0x6B0F90

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4232E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DF70
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DD40

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8DC0
#define AltAdvManager__IsAbilityReady_x                            0x4D8E30
#define AltAdvManager__GetAAById_x                                 0x4D9320
#define AltAdvManager__CanTrainAbility_x                           0x4D9F50
#define AltAdvManager__CanSeeAbility_x                             0x4D9B10

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AA30
#define CharacterZoneClient__HasSkill_x                            0x466300
#define CharacterZoneClient__MakeMeVisible_x                       0x46C5A0
#define CharacterZoneClient__IsStackBlocked_x                      0x44BFF0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B4B0
#define CharacterZoneClient__GetItemCountWorn_x                    0x464860
#define CharacterZoneClient__GetItemCountInInventory_x             0x464940
#define CharacterZoneClient__GetCursorItemCount_x                  0x464A20
#define CharacterZoneClient__FindAffectSlot_x                      0x4515E0
#define CharacterZoneClient__BardCastBard_x                        0x44AC30
#define CharacterZoneClient__GetMaxEffects_x                       0x4497C0
#define CharacterZoneClient__GetEffect_x                           0x44B6E0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451440
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449B10
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FF90

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x671200

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67F1D0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x59A630
#define CButtonWnd__CButtonWnd_x                                   0x8E51A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x69A160
#define CChatManager__InitContextMenu_x                            0x69B2B0
#define CChatManager__FreeChatWindow_x                             0x699C10
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A3430
#define CChatManager__SetLockedActiveChatWindow_x                  0x69A130

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8EF2C0
#define CContextMenu__dCContextMenu_x                              0x8EF4D0
#define CContextMenu__AddMenuItem_x                                0x8EF9E0
#define CContextMenu__RemoveMenuItem_x                             0x8EF640
#define CContextMenu__RemoveAllMenuItems_x                         0x8EF660
#define CContextMenu__CheckMenuItem_x                              0x8EF6E0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8DB730
#define CContextMenuManager__RemoveMenu_x                          0x8DBAC0
#define CContextMenuManager__PopupMenu_x                           0x8DBF10
#define CContextMenuManager__Flush_x                               0x8DB7A0
#define CContextMenuManager__GetMenu_x                             0x4194D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x88EC40
#define CChatService__GetFriendName_x                              0x88EC50

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6A0F00
#define CChatWindow__Clear_x                                       0x6A07F0
#define CChatWindow__WndNotification_x                             0x6A1810

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8DF580
#define CComboWnd__Draw_x                                          0x8DF790
#define CComboWnd__GetCurChoice_x                                  0x8DF330
#define CComboWnd__GetListRect_x                                   0x8DFA30
#define CComboWnd__GetTextRect_x                                   0x8DF5F0
#define CComboWnd__InsertChoice_x                                  0x8DFB90
#define CComboWnd__SetColors_x                                     0x8DF2C0
#define CComboWnd__SetChoice_x                                     0x8DF2F0
#define CComboWnd__GetItemCount_x                                  0x8DF320
#define CComboWnd__GetCurChoiceText_x                              0x8DF370


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AB130
#define CContainerWnd__vftable_x                                   0xAF7CE0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C6B40
#define CDisplay__GetClickedActor_x                                0x4BF400
#define CDisplay__GetUserDefinedColor_x                            0x4BDFE0
#define CDisplay__GetWorldFilePath_x                               0x4BD430
#define CDisplay__is3dON_x                                         0x4BC8C0
#define CDisplay__ReloadUI_x                                       0x4D0B20
#define CDisplay__WriteTextHD2_x                                   0x4C2ED0
#define CDisplay__TrueDistance_x                                   0x4C0030

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x906720

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8F3810
#define CEditWnd__GetCharIndexPt_x                                 0x8F4950
#define CEditWnd__GetDisplayString_x                               0x8F39C0
#define CEditWnd__GetHorzOffset_x                                  0x8F3D00
#define CEditWnd__GetLineForPrintableChar_x                        0x8F4420
#define CEditWnd__GetSelStartPt_x                                  0x8F4C00
#define CEditWnd__GetSTMLSafeText_x                                0x8F3E90
#define CEditWnd__PointFromPrintableChar_x                         0x8F4510
#define CEditWnd__SelectableCharFromPoint_x                        0x8F4690
#define CEditWnd__SetEditable_x                                    0x8F3E60

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56B500
#define CEverQuest__ClickedPlayer_x                                0x565080
#define CEverQuest__CreateTargetIndicator_x                        0x565F80
#define CEverQuest__DeleteTargetIndicator_x                        0x566000
#define CEverQuest__DoTellWindow_x                                 0x4771E0
#define CEverQuest__OutputTextToLog_x                              0x476E40
#define CEverQuest__DropHeldItemOnGround_x                         0x57BA70
#define CEverQuest__dsp_chat_x                                     0x477520
#define CEverQuest__trimName_x                                     0x561990
#define CEverQuest__Emote_x                                        0x579D80
#define CEverQuest__EnterZone_x                                    0x574E60
#define CEverQuest__GetBodyTypeDesc_x                              0x55F3D0
#define CEverQuest__GetClassDesc_x                                 0x568920
#define CEverQuest__GetClassThreeLetterCode_x                      0x568F20
#define CEverQuest__GetDeityDesc_x                                 0x55FCB0
#define CEverQuest__GetLangDesc_x                                  0x55F760
#define CEverQuest__GetRaceDesc_x                                  0x5690E0
#define CEverQuest__InterpretCmd_x                                 0x56CC80
#define CEverQuest__LeftClickedOnPlayer_x                          0x5815C0
#define CEverQuest__LMouseUp_x                                     0x583600
#define CEverQuest__RightClickedOnPlayer_x                         0x5820D0
#define CEverQuest__RMouseUp_x                                     0x583060
#define CEverQuest__SetGameState_x                                 0x565950
#define CEverQuest__UPCNotificationFlush_x                         0x55DD60
#define CEverQuest__IssuePetCommand_x                              0x56D660

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BBD20
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BBD80
#define CGaugeWnd__Draw_x                                          0x6BC1B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B580
#define CGuild__GetGuildName_x                                     0x43BA50
#define CGuild__GetGuildIndex_x                                    0x43CC60

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D8210

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E5670
#define CInvSlotMgr__MoveItem_x                                    0x6E5E30
#define CInvSlotMgr__SelectSlot_x                                  0x6E4F60

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E43C0
#define CInvSlot__SliderComplete_x                                 0x6E1B50
#define CInvSlot__GetItemBase_x                                    0x6E0FD0
#define CInvSlot__UpdateItem_x                                     0x6E1550

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E7250
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E8380

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7B69A0
#define CItemDisplayWnd__UpdateStrings_x                           0x6E94A0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F60D0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F65F0
#define CItemDisplayWnd__SetItem_x                                 0x6FBED0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7ED8B0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EFA70

// CLabel 
#define CLabel__Draw_x                                             0x702C70

// CListWnd
#define CListWnd__CListWnd_x                                       0x8CB1A0
#define CListWnd__dCListWnd_x                                      0x8CC450
#define CListWnd__AddColumn_x                                      0x8CC3F0
#define CListWnd__AddColumn1_x                                     0x8CBA80
#define CListWnd__AddLine_x                                        0x8CB460
#define CListWnd__AddString_x                                      0x8CB680
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C82D0
#define CListWnd__CalculateVSBRange_x                              0x8CA670
#define CListWnd__ClearSel_x                                       0x8C75F0
#define CListWnd__ClearAllSel_x                                    0x8C75A0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8CB030
#define CListWnd__Compare_x                                        0x8C8FC0
#define CListWnd__Draw_x                                           0x8CA280
#define CListWnd__DrawColumnSeparators_x                           0x8CA110
#define CListWnd__DrawHeader_x                                     0x8C78B0
#define CListWnd__DrawItem_x                                       0x8C9650
#define CListWnd__DrawLine_x                                       0x8C9DB0
#define CListWnd__DrawSeparator_x                                  0x8CA1B0
#define CListWnd__EnableLine_x                                     0x8C77D0
#define CListWnd__EnsureVisible_x                                  0x8C8430
#define CListWnd__ExtendSel_x                                      0x8C9560
#define CListWnd__GetColumnMinWidth_x                              0x8C6EE0
#define CListWnd__GetColumnWidth_x                                 0x8C6E10
#define CListWnd__GetCurSel_x                                      0x8C65D0
#define CListWnd__GetItemAtPoint_x                                 0x8C86C0
#define CListWnd__GetItemAtPoint1_x                                0x8C8730
#define CListWnd__GetItemData_x                                    0x8C6920
#define CListWnd__GetItemHeight_x                                  0x8C7F30
#define CListWnd__GetItemIcon_x                                    0x8C6B10
#define CListWnd__GetItemRect_x                                    0x8C8500
#define CListWnd__GetItemText_x                                    0x8C69C0
#define CListWnd__GetSelList_x                                     0x8CB970
#define CListWnd__GetSeparatorRect_x                               0x8C8EE0
#define CListWnd__InsertLine_x                                     0x8CB860
#define CListWnd__RemoveLine_x                                     0x8CB870
#define CListWnd__SetColors_x                                      0x8C6720
#define CListWnd__SetColumnJustification_x                         0x8C7170
#define CListWnd__SetColumnWidth_x                                 0x8C6E90
#define CListWnd__SetCurSel_x                                      0x8C6610
#define CListWnd__SetItemColor_x                                   0x8CAD20
#define CListWnd__SetItemData_x                                    0x8C7650
#define CListWnd__SetItemText_x                                    0x8CAB60
#define CListWnd__ShiftColumnSeparator_x                           0x8CA9F0
#define CListWnd__Sort_x                                           0x8CC550
#define CListWnd__ToggleSel_x                                      0x8C7520

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71BCD0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73F510
#define CMerchantWnd__RequestBuyItem_x                             0x748320
#define CMerchantWnd__RequestSellItem_x                            0x74A9C0
#define CMerchantWnd__SelectRecoverySlot_x                         0x73FA30
#define CMerchantWnd__SelectBuySellSlot_x                          0x73CAA0
#define CMerchantWnd__ActualSelect_x                               0x740810

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x85CE40
#define CPacketScrambler__hton_x                                   0x85CE50

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8EA160
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8EA240
#define CSidlManager__CreateLabel_x                                0x7AB9D0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E8700
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8EA520

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8E15C0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8E14C0
#define CSidlScreenWnd__ConvertToRes_x                             0x906600
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8E1EE0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8E30D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8E3180
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8E2640
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8E1890
#define CSidlScreenWnd__EnableIniStorage_x                         0x8E0FF0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8E1A80
#define CSidlScreenWnd__Init1_x                                    0x8E2DA0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8E1FA0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8E11B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8E2880
#define CSidlScreenWnd__StoreIniInfo_x                             0x8E0C50
#define CSidlScreenWnd__StoreIniVis_x                              0x8E0FA0
#define CSidlScreenWnd__WndNotification_x                          0x8E2B20
#define CSidlScreenWnd__GetChildItem_x                             0x8E10C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8D4900
#define CSidlScreenWnd__m_layoutCopy_x                             0x1740E68

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6070A0
#define CSkillMgr__GetSkillCap_x                                   0x607280
#define CSkillMgr__GetNameToken_x                                  0x606C50

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9058B0
#define CSliderWnd__SetValue_x                                     0x905A80
#define CSliderWnd__SetNumTicks_x                                  0x906200

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7B1CE0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8FF250
#define CStmlWnd__CalculateHSBRange_x                              0x8F77C0
#define CStmlWnd__CalculateVSBRange_x                              0x8F7730
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F7940
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F8140
#define CStmlWnd__ForceParseNow_x                                  0x8FFBD0
#define CStmlWnd__GetNextTagPiece_x                                0x8F8040
#define CStmlWnd__GetSTMLText_x                                    0x485360
#define CStmlWnd__GetVisibleText_x                                 0x8F8B90
#define CStmlWnd__InitializeWindowVariables_x                      0x8FB160
#define CStmlWnd__MakeStmlColorTag_x                               0x8F6A10
#define CStmlWnd__MakeWndNotificationTag_x                         0x8F6A70
#define CStmlWnd__SetSTMLText_x                                    0x8FC9B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8FEEF0
#define CStmlWnd__UpdateHistoryString_x                            0x8F9AD0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9030E0
#define CTabWnd__DrawCurrentPage_x                                 0x902970
#define CTabWnd__DrawTab_x                                         0x902740
#define CTabWnd__GetCurrentPage_x                                  0x902D20
#define CTabWnd__GetPageInnerRect_x                                0x902430
#define CTabWnd__GetTabInnerRect_x                                 0x902630
#define CTabWnd__GetTabRect_x                                      0x902500
#define CTabWnd__InsertPage_x                                      0x9033D0
#define CTabWnd__SetPage_x                                         0x902D50
#define CTabWnd__SetPageRect_x                                     0x903020
#define CTabWnd__UpdatePage_x                                      0x903370
#define CTabWnd__GetPageFromTabIndex_x                             0x902690
#define CTabWnd__GetCurrentTabIndex_x                              0x9023C0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E8530
#define CPageWnd__SetTabText_x                                     0x90F930

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x437110

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8DEF30
#define CTextureFont__GetTextExtent_x                              0x8DEC90

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63F970

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x90BD70

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8C47C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029C0
#define CXStr__CXStr1_x                                            0x7E9600
#define CXStr__CXStr3_x                                            0x8A7910
#define CXStr__dCXStr_x                                            0x7AB980
#define CXStr__operator_equal_x                                    0x8A7A80
#define CXStr__operator_equal1_x                                   0x8A7AD0
#define CXStr__operator_plus_equal1_x                              0x8A8BD0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8DCA30
#define CXWnd__BringToTop_x                                        0x8D3B00
#define CXWnd__Center_x                                            0x8D9D40
#define CXWnd__ClrFocus_x                                          0x8D36D0
#define CXWnd__Destroy_x                                           0x8DA820
#define CXWnd__DoAllDrawing_x                                      0x8D9990
#define CXWnd__DrawChildren_x                                      0x8D9B30
#define CXWnd__DrawColoredRect_x                                   0x8D3EF0
#define CXWnd__DrawTooltip_x                                       0x8D41A0
#define CXWnd__DrawTooltipAtPoint_x                                0x8D8900
#define CXWnd__GetBorderFrame_x                                    0x8D45C0
#define CXWnd__GetChildWndAt_x                                     0x8DA700
#define CXWnd__GetClientClipRect_x                                 0x8D43C0
#define CXWnd__GetScreenClipRect_x                                 0x8D8FF0
#define CXWnd__GetScreenRect_x                                     0x8D4790
#define CXWnd__GetTooltipRect_x                                    0x8D4030
#define CXWnd__GetWindowTextA_x                                    0x4273E0
#define CXWnd__IsActive_x                                          0x8CF230
#define CXWnd__IsDescendantOf_x                                    0x8D4500
#define CXWnd__IsReallyVisible_x                                   0x8D7910
#define CXWnd__IsType_x                                            0x8D9DB0
#define CScreenPieceTemplate__IsType_x                             0x908480
#define CXWnd__Move_x                                              0x8D6FF0
#define CXWnd__Move1_x                                             0x8D9630
#define CXWnd__ProcessTransition_x                                 0x8D3AA0
#define CXWnd__Refade_x                                            0x8D3870
#define CXWnd__Resize_x                                            0x8D4860
#define CXWnd__Right_x                                             0x8D8DF0
#define CXWnd__SetFocus_x                                          0x8D6130
#define CXWnd__SetFont_x                                           0x8D3720
#define CXWnd__SetKeyTooltip_x                                     0x8D4AD0
#define CXWnd__SetMouseOver_x                                      0x8D9320
#define CXWnd__StartFade_x                                         0x8D3B50
#define CXWnd__GetChildItem_x                                      0x8D9260
#define CXWnd__SetParent_x                                         0x8DA6B0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8D0AD0
#define CXWndManager__DrawWindows_x                                0x8D0710
#define CXWndManager__GetKeyboardFlags_x                           0x8CED70
#define CXWndManager__HandleKeyboardMsg_x                          0x8CF6B0
#define CXWndManager__RemoveWnd_x                                  0x8CF3C0

// CDBStr
#define CDBStr__GetString_x                                        0x4BB120

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4527A0
#define EQ_Character__Cur_HP_x                                     0x465EE0
#define EQ_Character__Cur_Mana_x                                   0x45AE10
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B7C0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443820
#define EQ_Character__GetFocusRangeModifier_x                      0x443880
#define EQ_Character__GetHPRegen_x                                 0x46A0C0
#define EQ_Character__GetEnduranceRegen_x                          0x4654F0
#define EQ_Character__GetManaRegen_x                               0x46A660
#define EQ_Character__Max_Endurance_x                              0x5CD930
#define EQ_Character__Max_HP_x                                     0x45D990
#define EQ_Character__Max_Mana_x                                   0x5CD760
#define EQ_Character__doCombatAbility_x                            0x5CAE30
#define EQ_Character__UseSkill_x                                   0x471630
#define EQ_Character__GetConLevel_x                                0x5C0070
#define EQ_Character__IsExpansionFlag_x                            0x426920
#define EQ_Character__TotalEffect_x                                0x44F8D0
#define EQ_Character__GetPCSpellAffect_x                           0x44BBC0
#define EQ_Character__SpellDuration_x                              0x449B60
#define EQ_Character__FindItemByRecord_x                           0x463530
#define EQ_Character__GetAdjustedSkill_x                           0x4660B0
#define EQ_Character__GetBaseSkill_x                               0x45D870

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x87AE00

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D5F40

//PcClient
#define PcClient__PcClient_x                                       0x5C1ED0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446C10
#define CCharacterSelect__EnterWorld_x                             0x4463E0
#define CCharacterSelect__Quit_x                                   0x444FA0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59FF80
#define EQ_Item__CreateItemTagString_x                             0x85B080
#define EQ_Item__IsStackable_x                                     0x850700
#define EQ_Item__GetImageNum_x                                     0x8531B0
#define EQ_Item__CreateItemClient_x                                0x5A1090
#define EQ_Item__GetItemValue_x                                    0x859AC0
#define EQ_Item__ValueSellMerchant_x                               0x85CAD0
#define EQ_Item__IsKeyRingItem_x                                   0x8511C0
#define EQ_Item__CanGoInBag_x                                      0x5A0110
#define EQ_Item__GetMaxItemCount_x                                 0x8505F0
#define EQ_Item__GetHeldItem_x                                     0x851FC0
#define EQ_Item__GetAugmentFitBySlot_x                             0x85C900

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DB360
#define EQ_LoadingS__Array_x                                       0xC17958

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CFE50
#define EQ_PC__GetAlternateAbilityId_x                             0x865010
#define EQ_PC__GetCombatAbility_x                                  0x8650A0
#define EQ_PC__GetCombatAbilityTimer_x                             0x85FAF0
#define EQ_PC__GetItemRecastTimer_x                                0x5C95F0
#define EQ_PC__HasLoreItem_x                                       0x5C3690
#define EQ_PC__AlertInventoryChanged_x                             0x5C0020
#define EQ_PC__GetPcZoneClient_x                                   0x5EA460
#define EQ_PC__RemoveMyAffect_x                                    0x5C8A50
#define EQ_PC__GetKeyRingItems_x                                   0x85FF10
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x872D00
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x866F90

// EQItemList 
#define EQItemList__EQItemList_x                                   0x527810
#define EQItemList__add_object_x                                   0x554CD0
#define EQItemList__add_item_x                                     0x527750
#define EQItemList__delete_item_x                                  0x527C00
#define EQItemList__FreeItemList_x                                 0x527B00

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4BA3D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D5CE0
#define EQPlayer__dEQPlayer_x                                      0x5DE320
#define EQPlayer__DoAttack_x                                       0x5EFDF0
#define EQPlayer__EQPlayer_x                                       0x5E0A50
#define EQPlayer__SetNameSpriteState_x                             0x5DB1E0
#define EQPlayer__SetNameSpriteTint_x                              0x5D7100
#define PlayerBase__HasProperty_j_x                                0x939900
#define EQPlayer__IsTargetable_x                                   0x939BA0
#define EQPlayer__CanSee_x                                         0x93A100
#define PlayerZoneClient__ChangeHeight_x                           0x5EFCB0
#define EQPlayer__CanSee1_x                                        0x93A1F0
#define PlayerBase__GetVisibilityLineSegment_x                     0x939E90

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5EA610
#define PlayerZoneClient__IsValidTeleport_x                        0x555570
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D3720


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E4AA0
#define EQPlayerManager__GetSpawnByName_x                          0x5E4F00
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E4AD0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A66E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A6720
#define KeypressHandler__ClearCommandStateArray_x                  0x5A62D0
#define KeypressHandler__HandleKeyDown_x                           0x5A4BF0
#define KeypressHandler__HandleKeyUp_x                             0x5A4F10
#define KeypressHandler__SaveKeymapping_x                          0x5A63A0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x714660
#define MapViewMap__SaveEx_x                                       0x717990

#define PlayerPointManager__GetAltCurrency_x                       0x878EC0

// StringTable 
#define StringTable__getString_x                                   0x873030

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CD3C0
#define PcZoneClient__RemovePetEffect_x                            0x5C9AC0
#define PcZoneClient__HasAlternateAbility_x                        0x5CA460
#define PcZoneClient__GetCurrentMod_x                              0x45CE40
#define PcZoneClient__GetModCap_x                                  0x45A570
#define PcZoneClient__CanEquipItem_x                               0x5CA980
#define PcZoneClient__GetItemByID_x                                0x5CF1C0
#define PcZoneClient__GetItemByItemClass_x                         0x5CFD70
#define PcZoneClient__RemoveBuffEffect_x                           0x5C8D00

//Doors
#define EQSwitch__UseSwitch_x                                      0x55C690

//IconCache
#define IconCache__GetIcon_x                                       0x6B15C0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A84C0
#define CContainerMgr__CloseContainer_x                            0x6A8CE0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x77B840

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x599050

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5A40
#define EQ_Spell__SpellAffects_x                                   0x4F2C60
#define EQ_Spell__SpellAffectBase_x                           0x4F2CD0
#define CharacterZoneClient__CalcAffectChange_x                    0x44BA50
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AC90
#define CLootWnd__LootAll_x                                        0x709EA0
#define CLootWnd__RequestLootSlot_x                                0x70A6B0
#define EQ_Spell__IsStackable_x                                    0x449580
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449630
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43F020
#define EQ_Spell__IsSPAStacking_x                                  0x4F27D0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F3840
#define EQ_Spell__IsNoRemove_x                                     0x435160
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F27F0

#define __IsResEffectSpell_x                                       0x4496B0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x884A80

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7C3500
#define CTargetWnd__WndNotification_x                              0x7C2FF0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7C36E0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C8620

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4EE300
#define EqSoundManager__PlayScriptMp3_x                            0x4EFDA0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A9540

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8F2E40
#define CSidlManager__FindAnimation1_x                             0x8E8130

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E2D50
#define CAltAbilityData__GetMercMaxRank_x                          0x4E2D00
#define CAltAbilityData__GetMaxRank_x                              0x4D7470

//CTargetRing
#define CTargetRing__Cast_x                                        0x596910

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459570
#define CharacterBase__CreateItemGlobalIndex_x                     0x4763B0
#define CharacterBase__CreateItemIndex_x                           0x520DD0
#define CharacterBase__GetItemPossession_x                         0x444450
#define CharacterBase__GetItemByGlobalIndex_x                      0x8888E0
#define CharacterBase__GetEffectId_x                               0x459530

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x691380
#define CCastSpellWnd__IsBardSongPlaying_x                         0x690AE0

//messages
#define msg_spell_worn_off_x                                       0x4FD530
#define msg_new_text_x                                             0x506C90
#define msgTokenTextParam_x                                        0x503470

//SpellManager
#define SpellManager__vftable_x                                    0xAD3410
#define SpellManager__SpellManager_x                               0x47EFE0
#define Spellmanager__LoadTextSpells_x          0x60DF30

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x93DC60

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4888D0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EF40
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449300
#define ItemGlobalIndex__IsValidIndex_x                            0x458E30

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x886740
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x885680

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x702EC0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AD1F0
#define CCursorAttachment__Deactivate_x                            0x6AC730

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x904DB0
#define CEQSuiteTextureLoader__GetTexture_x                        0x904F30

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                                0x605BC0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                                0x48D140

//IString
#define IString__Append_x                                           0x47FC10
