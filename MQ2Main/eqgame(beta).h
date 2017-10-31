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
#define __ExpectedVersionDate                                     "Oct 31 2017"
#define __ExpectedVersionTime                                     "04:16:52"
#define __ActualVersionDate_x                                      0xAEE3B0
#define __ActualVersionTime_x                                      0xAEE3BC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5ABCC0
#define __MemChecker1_x                                            0x8AB490
#define __MemChecker2_x                                            0x642010
#define __MemChecker3_x                                            0x641F60
#define __MemChecker4_x                                            0x7FCE60
#define __EncryptPad0_x                                            0xC4C6A0
#define __EncryptPad1_x                                            0xD288E8
#define __EncryptPad2_x                                            0xC76268
#define __EncryptPad3_x                                            0xC75E68
#define __EncryptPad4_x                                            0xD16EE8
#define __EncryptPad5_x                                            0x10D2218
#define __AC1_x                                                    0x7BBD85
#define __AC2_x                                                    0x564827
#define __AC3_x                                                    0x5629A0
#define __AC4_x                                                    0x574BC1
#define __AC5_x                                                    0x58894B
#define __AC6_x                                                    0x58C4EE
#define __AC7_x                                                    0x582F4C
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
#define __do_loot_x                                                0x5336D0
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
#define __CastRay_x                                                0x54B1E0
#define __CastRay2_x                                               0x54AB10
#define __HeadingDiff_x                                            0x93B7E0
#define __FixHeading_x                                             0x93B770
#define __get_bearing_x                                            0x53A820
#define __ConvertItemTags_x                                        0x5382F0
#define __ExecuteCmd_x                                             0x522C40
#define __EQGetTime_x                                              0x8AAE30
#define __get_melee_range_x                                        0x5298F0
#define __GetGaugeValueFromEQ_x                                    0x7BA940
#define __GetLabelFromEQ_x                                         0x7BBD10
#define __ToggleKeyRingItem_x                                      0x4900F0
#define __GetXTargetType_x                                         0x93D3E0
#define __LoadFrontEnd_x                                           0x6416E0
#define __NewUIINI_x                                               0x7BA320
#define __ProcessGameEvents_x                                      0x584CE0
#define __ProcessMouseEvent_x                                      0x584480
#define CrashDetected_x                                            0x6430A0
#define wwsCrashReportCheckForUploader_x                           0x808AC0
#define __AppCrashWrapper_x                                        0xC75E5C
#define __pCrashHandler_x                                          0x10E7A28
#define __CrashHandler_x                                           0x808520
#define wwsCrashReportPlatformLaunchUploader_x                     0x80ACC0
#define DrawNetStatus_x                                            0x5BB750
#define Util__FastTime_x                                           0x8AAAD0
#define Expansion_HoT_x                                            0xF41588
#define __HelpPath_x                                               0xFC4E28
#define __STMLToText_x                                             0x8F1290
#define __GetAnimationCache_x                                      0x6B0DB0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4233F0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E050
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DE20

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8660
#define AltAdvManager__IsAbilityReady_x                            0x4D86D0
#define AltAdvManager__GetAAById_x                                 0x4D8BC0
#define AltAdvManager__CanTrainAbility_x                           0x4D97F0
#define AltAdvManager__CanSeeAbility_x                             0x4D93B0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x469F70
#define CharacterZoneClient__HasSkill_x                            0x465FE0
#define CharacterZoneClient__MakeMeVisible_x                       0x46BAE0
#define CharacterZoneClient__IsStackBlocked_x                      0x44C0C0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B5F0
#define CharacterZoneClient__GetItemCountWorn_x                    0x464540
#define CharacterZoneClient__GetItemCountInInventory_x             0x464620
#define CharacterZoneClient__GetCursorItemCount_x                  0x464700
#define CharacterZoneClient__FindAffectSlot_x                      0x451730
#define CharacterZoneClient__BardCastBard_x                        0x44AD60
#define CharacterZoneClient__GetMaxEffects_x                       0x4498F0
#define CharacterZoneClient__GetEffect_x                           0x44B820
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451590
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449C40
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4500E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6710B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67EE80

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x59A500
#define CButtonWnd__CButtonWnd_x                                   0x8E55D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x699F30
#define CChatManager__InitContextMenu_x                            0x69B080
#define CChatManager__FreeChatWindow_x                             0x6999E0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A3220
#define CChatManager__SetLockedActiveChatWindow_x                  0x699F00

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8EF5D0
#define CContextMenu__dCContextMenu_x                              0x8EF7E0
#define CContextMenu__AddMenuItem_x                                0x8EFD00
#define CContextMenu__RemoveMenuItem_x                             0x8EF960
#define CContextMenu__RemoveAllMenuItems_x                         0x8EF980
#define CContextMenu__CheckMenuItem_x                              0x8EFA00

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8DBBC0
#define CContextMenuManager__RemoveMenu_x                          0x8DBF50
#define CContextMenuManager__PopupMenu_x                           0x8DC3A0
#define CContextMenuManager__Flush_x                               0x8DBC30
#define CContextMenuManager__GetMenu_x                             0x419570

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x88EFD0
#define CChatService__GetFriendName_x                              0x88EFE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6A0CF0
#define CChatWindow__Clear_x                                       0x6A05D0
#define CChatWindow__WndNotification_x                             0x6A1600

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8DFA10
#define CComboWnd__Draw_x                                          0x8DFC20
#define CComboWnd__GetCurChoice_x                                  0x8DF7C0
#define CComboWnd__GetListRect_x                                   0x8DFEC0
#define CComboWnd__GetTextRect_x                                   0x8DFA80
#define CComboWnd__InsertChoice_x                                  0x8E0020
#define CComboWnd__SetColors_x                                     0x8DF750
#define CComboWnd__SetChoice_x                                     0x8DF780
#define CComboWnd__GetItemCount_x                                  0x8DF7B0
#define CComboWnd__GetCurChoiceText_x                              0x8DF800


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AAF50
#define CContainerWnd__vftable_x                                   0xAF7CC0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C6390
#define CDisplay__GetClickedActor_x                                0x4BEC50
#define CDisplay__GetUserDefinedColor_x                            0x4BD830
#define CDisplay__GetWorldFilePath_x                               0x4BCC80
#define CDisplay__is3dON_x                                         0x4BC110
#define CDisplay__ReloadUI_x                                       0x4D0370
#define CDisplay__WriteTextHD2_x                                   0x4C2720
#define CDisplay__TrueDistance_x                                   0x4BF880

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x906840

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8F3B50
#define CEditWnd__GetCharIndexPt_x                                 0x8F4CA0
#define CEditWnd__GetDisplayString_x                               0x8F3D00
#define CEditWnd__GetHorzOffset_x                                  0x8F4040
#define CEditWnd__GetLineForPrintableChar_x                        0x8F4770
#define CEditWnd__GetSelStartPt_x                                  0x8F4F50
#define CEditWnd__GetSTMLSafeText_x                                0x8F41E0
#define CEditWnd__PointFromPrintableChar_x                         0x8F4860
#define CEditWnd__SelectableCharFromPoint_x                        0x8F49E0
#define CEditWnd__SetEditable_x                                    0x8F41B0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56B3F0
#define CEverQuest__ClickedPlayer_x                                0x564F70
#define CEverQuest__CreateTargetIndicator_x                        0x565E70
#define CEverQuest__DeleteTargetIndicator_x                        0x565EF0
#define CEverQuest__DoTellWindow_x                                 0x4766F0
#define CEverQuest__OutputTextToLog_x                              0x476350
#define CEverQuest__DropHeldItemOnGround_x                         0x57B960
#define CEverQuest__dsp_chat_x                                     0x476A30
#define CEverQuest__trimName_x                                     0x561880
#define CEverQuest__Emote_x                                        0x579C70
#define CEverQuest__EnterZone_x                                    0x574D50
#define CEverQuest__GetBodyTypeDesc_x                              0x55F2C0
#define CEverQuest__GetClassDesc_x                                 0x568810
#define CEverQuest__GetClassThreeLetterCode_x                      0x568E10
#define CEverQuest__GetDeityDesc_x                                 0x55FBA0
#define CEverQuest__GetLangDesc_x                                  0x55F650
#define CEverQuest__GetRaceDesc_x                                  0x568FD0
#define CEverQuest__InterpretCmd_x                                 0x56CB70
#define CEverQuest__LeftClickedOnPlayer_x                          0x5814B0
#define CEverQuest__LMouseUp_x                                     0x5834A0
#define CEverQuest__RightClickedOnPlayer_x                         0x581FC0
#define CEverQuest__RMouseUp_x                                     0x582F00
#define CEverQuest__SetGameState_x                                 0x565840
#define CEverQuest__UPCNotificationFlush_x                         0x55DC50
#define CEverQuest__IssuePetCommand_x                              0x56D550

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BBAB0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BBB10
#define CGaugeWnd__Draw_x                                          0x6BBF40

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B610
#define CGuild__GetGuildName_x                                     0x43BAE0
#define CGuild__GetGuildIndex_x                                    0x43CCF0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D7F60

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E53A0
#define CInvSlotMgr__MoveItem_x                                    0x6E5B60
#define CInvSlotMgr__SelectSlot_x                                  0x6E4CA0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E4100
#define CInvSlot__SliderComplete_x                                 0x6E1880
#define CInvSlot__GetItemBase_x                                    0x6E0D00
#define CInvSlot__UpdateItem_x                                     0x6E1280

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E6FA0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E80D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7B6880
#define CItemDisplayWnd__UpdateStrings_x                           0x6E91B0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F5DC0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F62C0
#define CItemDisplayWnd__SetItem_x                                 0x6FBB20

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7ED8A0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EF750

// CLabel 
#define CLabel__Draw_x                                             0x7028D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8CB510
#define CListWnd__dCListWnd_x                                      0x8CC7D0
#define CListWnd__AddColumn_x                                      0x8CC770
#define CListWnd__AddColumn1_x                                     0x8CBE00
#define CListWnd__AddLine_x                                        0x8CB7E0
#define CListWnd__AddString_x                                      0x8CBA00
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C8620
#define CListWnd__CalculateVSBRange_x                              0x8CA9E0
#define CListWnd__ClearSel_x                                       0x8C7930
#define CListWnd__ClearAllSel_x                                    0x8C78E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8CB3A0
#define CListWnd__Compare_x                                        0x8C9310
#define CListWnd__Draw_x                                           0x8CA5E0
#define CListWnd__DrawColumnSeparators_x                           0x8CA470
#define CListWnd__DrawHeader_x                                     0x8C7BF0
#define CListWnd__DrawItem_x                                       0x8C99A0
#define CListWnd__DrawLine_x                                       0x8CA110
#define CListWnd__DrawSeparator_x                                  0x8CA510
#define CListWnd__EnableLine_x                                     0x8C7B10
#define CListWnd__EnsureVisible_x                                  0x8C8780
#define CListWnd__ExtendSel_x                                      0x8C98B0
#define CListWnd__GetColumnMinWidth_x                              0x8C7220
#define CListWnd__GetColumnWidth_x                                 0x8C7150
#define CListWnd__GetCurSel_x                                      0x8C6920
#define CListWnd__GetItemAtPoint_x                                 0x8C8A10
#define CListWnd__GetItemAtPoint1_x                                0x8C8A80
#define CListWnd__GetItemData_x                                    0x8C6C70
#define CListWnd__GetItemHeight_x                                  0x8C8270
#define CListWnd__GetItemIcon_x                                    0x8C6E60
#define CListWnd__GetItemRect_x                                    0x8C8850
#define CListWnd__GetItemText_x                                    0x8C6D10
#define CListWnd__GetSelList_x                                     0x8CBCF0
#define CListWnd__GetSeparatorRect_x                               0x8C9230
#define CListWnd__InsertLine_x                                     0x8CBBE0
#define CListWnd__RemoveLine_x                                     0x8CBBF0
#define CListWnd__SetColors_x                                      0x8C6A70
#define CListWnd__SetColumnJustification_x                         0x8C74B0
#define CListWnd__SetColumnWidth_x                                 0x8C71D0
#define CListWnd__SetCurSel_x                                      0x8C6960
#define CListWnd__SetItemColor_x                                   0x8CB090
#define CListWnd__SetItemData_x                                    0x8C7990
#define CListWnd__SetItemText_x                                    0x8CAED0
#define CListWnd__ShiftColumnSeparator_x                           0x8CAD60
#define CListWnd__Sort_x                                           0x8CC8D0
#define CListWnd__ToggleSel_x                                      0x8C7860

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71BAD0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73F1A0
#define CMerchantWnd__RequestBuyItem_x                             0x748270
#define CMerchantWnd__RequestSellItem_x                            0x74A9D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x73F720
#define CMerchantWnd__SelectBuySellSlot_x                          0x73C6E0
#define CMerchantWnd__ActualSelect_x                               0x740570

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x85D260
#define CPacketScrambler__hton_x                                   0x85D270

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8EA520
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8EA600
#define CSidlManager__CreateLabel_x                                0x7AB7C0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E8AC0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8EA8E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8E1A60
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8E1960
#define CSidlScreenWnd__ConvertToRes_x                             0x906720
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8E2360
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8E3540
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8E35F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8E2AC0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8E1D10
#define CSidlScreenWnd__EnableIniStorage_x                         0x8E1490
#define CSidlScreenWnd__GetSidlPiece_x                             0x8E1F00
#define CSidlScreenWnd__Init1_x                                    0x8E3210
#define CSidlScreenWnd__LoadIniInfo_x                              0x8E2420
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8E1650
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8E2D00
#define CSidlScreenWnd__StoreIniInfo_x                             0x8E10F0
#define CSidlScreenWnd__StoreIniVis_x                              0x8E1440
#define CSidlScreenWnd__WndNotification_x                          0x8E2F90
#define CSidlScreenWnd__GetChildItem_x                             0x8E1560
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8D4D30
#define CSidlScreenWnd__m_layoutCopy_x                             0x1740E68

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x606E80
#define CSkillMgr__GetSkillCap_x                                   0x607060
#define CSkillMgr__GetNameToken_x                                  0x606A30

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x9059D0
#define CSliderWnd__SetValue_x                                     0x905BA0
#define CSliderWnd__SetNumTicks_x                                  0x906320

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7B1AC0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8FF5B0
#define CStmlWnd__CalculateHSBRange_x                              0x8F7B10
#define CStmlWnd__CalculateVSBRange_x                              0x8F7A80
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F7C90
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F8490
#define CStmlWnd__ForceParseNow_x                                  0x8FFF30
#define CStmlWnd__GetNextTagPiece_x                                0x8F8390
#define CStmlWnd__GetSTMLText_x                                    0x484930
#define CStmlWnd__GetVisibleText_x                                 0x8F8EE0
#define CStmlWnd__InitializeWindowVariables_x                      0x8FB4A0
#define CStmlWnd__MakeStmlColorTag_x                               0x8F6D60
#define CStmlWnd__MakeWndNotificationTag_x                         0x8F6DC0
#define CStmlWnd__SetSTMLText_x                                    0x8FCCF0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8FF250
#define CStmlWnd__UpdateHistoryString_x                            0x8F9E20

// CTabWnd 
#define CTabWnd__Draw_x                                            0x903450
#define CTabWnd__DrawCurrentPage_x                                 0x902CE0
#define CTabWnd__DrawTab_x                                         0x902AA0
#define CTabWnd__GetCurrentPage_x                                  0x903090
#define CTabWnd__GetPageInnerRect_x                                0x902790
#define CTabWnd__GetTabInnerRect_x                                 0x902990
#define CTabWnd__GetTabRect_x                                      0x902860
#define CTabWnd__InsertPage_x                                      0x903740
#define CTabWnd__SetPage_x                                         0x9030C0
#define CTabWnd__SetPageRect_x                                     0x903390
#define CTabWnd__UpdatePage_x                                      0x9036E0
#define CTabWnd__GetPageFromTabIndex_x                             0x9029F0
#define CTabWnd__GetCurrentTabIndex_x                              0x902720

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E8280
#define CPageWnd__SetTabText_x                                     0x90FA40

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x437180

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8DF3C0
#define CTextureFont__GetTextExtent_x                              0x8DF120

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63F970

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x90BE80

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8C4A80

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5A8140
#define CXStr__CXStr1_x                                            0x4F93C0
#define CXStr__CXStr3_x                                            0x8A7D60
#define CXStr__dCXStr_x                                            0x5A8520
#define CXStr__operator_equal_x                                    0x8A7ED0
#define CXStr__operator_equal1_x                                   0x8A7F20
#define CXStr__operator_plus_equal1_x                              0x8A9020

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8DCEC0
#define CXWnd__BringToTop_x                                        0x8D3F60
#define CXWnd__Center_x                                            0x8DA160
#define CXWnd__ClrFocus_x                                          0x8D3B50
#define CXWnd__Destroy_x                                           0x8DAC50
#define CXWnd__DoAllDrawing_x                                      0x8D9DB0
#define CXWnd__DrawChildren_x                                      0x8D9F50
#define CXWnd__DrawColoredRect_x                                   0x8D4330
#define CXWnd__DrawTooltip_x                                       0x8D45D0
#define CXWnd__DrawTooltipAtPoint_x                                0x8D8D20
#define CXWnd__GetBorderFrame_x                                    0x8D49F0
#define CXWnd__GetChildWndAt_x                                     0x8DAB30
#define CXWnd__GetClientClipRect_x                                 0x8D47F0
#define CXWnd__GetScreenClipRect_x                                 0x8D9420
#define CXWnd__GetScreenRect_x                                     0x8D4BC0
#define CXWnd__GetTooltipRect_x                                    0x8D4460
#define CXWnd__GetWindowTextA_x                                    0x427450
#define CXWnd__IsActive_x                                          0x8CF580
#define CXWnd__IsDescendantOf_x                                    0x8D4930
#define CXWnd__IsReallyVisible_x                                   0x8D7D50
#define CXWnd__IsType_x                                            0x8DA1D0
#define CScreenPieceTemplate__IsType_x                             0x908590
#define CXWnd__Move_x                                              0x8D7430
#define CXWnd__Move1_x                                             0x8D9A60
#define CXWnd__ProcessTransition_x                                 0x8D3F10
#define CXWnd__Refade_x                                            0x8D3CF0
#define CXWnd__Resize_x                                            0x8D4C90
#define CXWnd__Right_x                                             0x8D9220
#define CXWnd__SetFocus_x                                          0x8D6570
#define CXWnd__SetFont_x                                           0x8D3BA0
#define CXWnd__SetKeyTooltip_x                                     0x8D4F00
#define CXWnd__SetMouseOver_x                                      0x8D9760
#define CXWnd__StartFade_x                                         0x8D3FB0
#define CXWnd__GetChildItem_x                                      0x8D96A0
#define CXWnd__SetParent_x                                         0x8DAAE0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8D0E20
#define CXWndManager__DrawWindows_x                                0x8D0A60
#define CXWndManager__GetKeyboardFlags_x                           0x8CF0B0
#define CXWndManager__HandleKeyboardMsg_x                          0x8CFA20
#define CXWndManager__RemoveWnd_x                                  0x8CF710

// CDBStr
#define CDBStr__GetString_x                                        0x4BA950

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4528F0
#define EQ_Character__Cur_HP_x                                     0x465BC0
#define EQ_Character__Cur_Mana_x                                   0x45B020
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B900
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4438B0
#define EQ_Character__GetFocusRangeModifier_x                      0x443A00
#define EQ_Character__GetHPRegen_x                                 0x469600
#define EQ_Character__GetEnduranceRegen_x                          0x4651D0
#define EQ_Character__GetManaRegen_x                               0x469BA0
#define EQ_Character__Max_Endurance_x                              0x5CD270
#define EQ_Character__Max_HP_x                                     0x45DBA0
#define EQ_Character__Max_Mana_x                                   0x5CD0A0
#define EQ_Character__doCombatAbility_x                            0x5CA770
#define EQ_Character__UseSkill_x                                   0x470B80
#define EQ_Character__GetConLevel_x                                0x5BFD40
#define EQ_Character__IsExpansionFlag_x                            0x426970
#define EQ_Character__TotalEffect_x                                0x44FA20
#define EQ_Character__GetPCSpellAffect_x                           0x44BC90
#define EQ_Character__SpellDuration_x                              0x449C90
#define EQ_Character__FindItemByRecord_x                           0x463230
#define EQ_Character__GetAdjustedSkill_x                           0x465D90
#define EQ_Character__GetBaseSkill_x                               0x45DA80

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x87B1E0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D58A0

//PcClient
#define PcClient__PcClient_x                                       0x5C1B80

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446D70
#define CCharacterSelect__EnterWorld_x                             0x446540
#define CCharacterSelect__Quit_x                                   0x445100

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59FE30
#define EQ_Item__CreateItemTagString_x                             0x85B3E0
#define EQ_Item__IsStackable_x                                     0x850760
#define EQ_Item__GetImageNum_x                                     0x853200
#define EQ_Item__CreateItemClient_x                                0x5A0EF0
#define EQ_Item__GetItemValue_x                                    0x859E40
#define EQ_Item__ValueSellMerchant_x                               0x85CEB0
#define EQ_Item__IsKeyRingItem_x                                   0x851220
#define EQ_Item__CanGoInBag_x                                      0x59FFC0
#define EQ_Item__GetMaxItemCount_x                                 0x850650
#define EQ_Item__GetHeldItem_x                                     0x852010
#define EQ_Item__GetAugmentFitBySlot_x                             0x85CCE0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DAC40
#define EQ_LoadingS__Array_x                                       0xC17958

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CF7A0
#define EQ_PC__GetAlternateAbilityId_x                             0x865360
#define EQ_PC__GetCombatAbility_x                                  0x8653F0
#define EQ_PC__GetCombatAbilityTimer_x                             0x85FF10
#define EQ_PC__GetItemRecastTimer_x                                0x5C8F20
#define EQ_PC__HasLoreItem_x                                       0x5C3340
#define EQ_PC__AlertInventoryChanged_x                             0x5BFCF0
#define EQ_PC__GetPcZoneClient_x                                   0x5E9E70
#define EQ_PC__RemoveMyAffect_x                                    0x5C8380
#define EQ_PC__GetKeyRingItems_x                                   0x860330
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x873060
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8672D0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x527960
#define EQItemList__add_object_x                                   0x554C80
#define EQItemList__add_item_x                                     0x5278A0
#define EQItemList__delete_item_x                                  0x527D50
#define EQItemList__FreeItemList_x                                 0x527C50

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9C20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D5640
#define EQPlayer__dEQPlayer_x                                      0x5DDD00
#define EQPlayer__DoAttack_x                                       0x5EF7F0
#define EQPlayer__EQPlayer_x                                       0x5E0430
#define EQPlayer__SetNameSpriteState_x                             0x5DAB50
#define EQPlayer__SetNameSpriteTint_x                              0x5D6A60
#define PlayerBase__HasProperty_j_x                                0x939BA0
#define EQPlayer__IsTargetable_x                                   0x939E40
#define EQPlayer__CanSee_x                                         0x93A3A0
#define PlayerZoneClient__ChangeHeight_x                           0x5EF6B0
#define EQPlayer__CanSee1_x                                        0x93A490
#define PlayerBase__GetVisibilityLineSegment_x                     0x93A130

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5EA020
#define PlayerZoneClient__IsValidTeleport_x                        0x555520
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2F70


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E4490
#define EQPlayerManager__GetSpawnByName_x                          0x5E48F0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E44C0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A64D0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A6510
#define KeypressHandler__ClearCommandStateArray_x                  0x5A60C0
#define KeypressHandler__HandleKeyDown_x                           0x5A49E0
#define KeypressHandler__HandleKeyUp_x                             0x5A4D00
#define KeypressHandler__SaveKeymapping_x                          0x5A6190

// MapViewMap 
#define MapViewMap__Clear_x                                        0x714460
#define MapViewMap__SaveEx_x                                       0x717790

#define PlayerPointManager__GetAltCurrency_x                       0x879270

// StringTable 
#define StringTable__getString_x                                   0x873390

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CCD00
#define PcZoneClient__RemovePetEffect_x                            0x5C93F0
#define PcZoneClient__HasAlternateAbility_x                        0x5C9D90
#define PcZoneClient__GetCurrentMod_x                              0x45D050
#define PcZoneClient__GetModCap_x                                  0x45A780
#define PcZoneClient__CanEquipItem_x                               0x5CA2B0
#define PcZoneClient__GetItemByID_x                                0x5CEB10
#define PcZoneClient__GetItemByItemClass_x                         0x5CF6C0
#define PcZoneClient__RemoveBuffEffect_x                           0x5C8630

//Doors
#define EQSwitch__UseSwitch_x                                      0x55C5B0

//IconCache
#define IconCache__GetIcon_x                                       0x6B13E0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A82E0
#define CContainerMgr__CloseContainer_x                            0x6A8B00

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x77B730

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x598F20

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F51F0
#define EQ_Spell__SpellAffects_x                                   0x4F23E0
#define EQ_Spell__SpellAffectBase_x                           0x4F2450
#define CharacterZoneClient__CalcAffectChange_x                    0x44BB20
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44ADC0
#define CLootWnd__LootAll_x                                        0x709C80
#define CLootWnd__RequestLootSlot_x                                0x70A490
#define EQ_Spell__IsStackable_x                                    0x4496B0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449760
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43F0B0
#define EQ_Spell__IsSPAStacking_x                                  0x4F1F50
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2FF0
#define EQ_Spell__IsNoRemove_x                                     0x4351C0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1F70

#define __IsResEffectSpell_x                                       0x4497E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x884E60

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7C33F0
#define CTargetWnd__WndNotification_x                              0x7C2EE0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7C35D0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C8520

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4EDAE0
#define EqSoundManager__PlayScriptMp3_x                            0x4EF580

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8DA0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8F3170
#define CSidlManager__FindAnimation1_x                             0x8E84F0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E2550
#define CAltAbilityData__GetMercMaxRank_x                          0x4E2500
#define CAltAbilityData__GetMaxRank_x                              0x4D6D10

//CTargetRing
#define CTargetRing__Cast_x                                        0x5967E0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459730
#define CharacterBase__CreateItemGlobalIndex_x                     0x475910
#define CharacterBase__CreateItemIndex_x                           0x520FC0
#define CharacterBase__GetItemPossession_x                         0x4445D0
#define CharacterBase__GetItemByGlobalIndex_x                      0x888CC0
#define CharacterBase__GetEffectId_x                               0x4596F0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x691180
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6908E0

//messages
#define msg_spell_worn_off_x                                       0x4FCD60
#define msg_new_text_x                                             0x506510
#define msgTokenTextParam_x                                        0x502CF0

//SpellManager
#define SpellManager__vftable_x                                    0xAD3410
#define SpellManager__SpellManager_x                               0x47E5E0
#define Spellmanager__LoadTextSpells_x          0x60DDA0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x93DF00

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4881A0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EFD0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449440
#define ItemGlobalIndex__IsValidIndex_x                            0x458F60

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x886B20
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x885A60

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x702B20

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AD020
#define CCursorAttachment__Deactivate_x                            0x6AC560

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x904ED0
#define CEQSuiteTextureLoader__GetTexture_x                        0x905050

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                                0x605950

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                                0x48CA10

//IString
#define IString__Append_x                                           0x47F210
