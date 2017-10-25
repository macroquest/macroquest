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
#define __ExpectedVersionDate                                     "Oct 25 2017"
#define __ExpectedVersionTime                                     "04:17:31"
#define __ActualVersionDate_x                                      0xAEE3C0
#define __ActualVersionTime_x                                      0xAEE3CC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AC610
#define __MemChecker1_x                                            0x8AB330
#define __MemChecker2_x                                            0x6428A0
#define __MemChecker3_x                                            0x6427F0
#define __MemChecker4_x                                            0x7FD070
#define __EncryptPad0_x                                            0xC4C6A0
#define __EncryptPad1_x                                            0xD288E8
#define __EncryptPad2_x                                            0xC76268
#define __EncryptPad3_x                                            0xC75E68
#define __EncryptPad4_x                                            0xD16EE8
#define __EncryptPad5_x                                            0x10D2218
#define __AC1_x                                                    0x7BC505
#define __AC2_x                                                    0x565167
#define __AC3_x                                                    0x5632E0
#define __AC4_x                                                    0x575501
#define __AC5_x                                                    0x5892DB
#define __AC6_x                                                    0x58CE7E
#define __AC7_x                                                    0x5838DC
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
#define __do_loot_x                                                0x533DC0
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
#define __CastRay_x                                                0x54B8D0
#define __CastRay2_x                                               0x54B200
#define __HeadingDiff_x                                            0x93B650
#define __FixHeading_x                                             0x93B5E0
#define __get_bearing_x                                            0x53AF10
#define __ConvertItemTags_x                                        0x5389E0
#define __ExecuteCmd_x                                             0x5232E0
#define __EQGetTime_x                                              0x8AACD0
#define __get_melee_range_x                                        0x529F80
#define __GetGaugeValueFromEQ_x                                    0x7BB0C0
#define __GetLabelFromEQ_x                                         0x7BC490
#define __ToggleKeyRingItem_x                                      0x490FC0
#define __GetXTargetType_x                                         0x93D250
#define __LoadFrontEnd_x                                           0x641F70
#define __NewUIINI_x                                               0x7BAAA0
#define __ProcessGameEvents_x                                      0x585670
#define __ProcessMouseEvent_x                                      0x584E10
#define CrashDetected_x                                            0x643930
#define wwsCrashReportCheckForUploader_x                           0x808F00
#define __AppCrashWrapper_x                                        0xC75E5C
#define __pCrashHandler_x                                          0x10E7A28
#define __CrashHandler_x                                           0x808990
#define wwsCrashReportPlatformLaunchUploader_x                     0x80B130
#define DrawNetStatus_x                                            0x5BC320
#define Util__FastTime_x                                           0x8AA970
#define Expansion_HoT_x                                            0xF41588
#define __HelpPath_x                                               0xFC4E28
#define __STMLToText_x                                             0x8F1140
#define __GetAnimationCache_x                                      0x6B1610

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423440
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E0D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DEA0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D9430
#define AltAdvManager__IsAbilityReady_x                            0x4D94A0
#define AltAdvManager__GetAAById_x                                 0x4D9990
#define AltAdvManager__CanTrainAbility_x                           0x4DA5C0
#define AltAdvManager__CanSeeAbility_x                             0x4DA180

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AEE0
#define CharacterZoneClient__HasSkill_x                            0x4667B0
#define CharacterZoneClient__MakeMeVisible_x                       0x46CA50
#define CharacterZoneClient__IsStackBlocked_x                      0x44C4A0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B960
#define CharacterZoneClient__GetItemCountWorn_x                    0x464D10
#define CharacterZoneClient__GetItemCountInInventory_x             0x464DF0
#define CharacterZoneClient__GetCursorItemCount_x                  0x464ED0
#define CharacterZoneClient__FindAffectSlot_x                      0x451A90
#define CharacterZoneClient__BardCastBard_x                        0x44B0E0
#define CharacterZoneClient__GetMaxEffects_x                       0x449C70
#define CharacterZoneClient__GetEffect_x                           0x44BB90
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4518F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449FC0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x450440

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x671830

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67F6B0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x59AEE0
#define CButtonWnd__CButtonWnd_x                                   0x8E52D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x69A7F0
#define CChatManager__InitContextMenu_x                            0x69B940
#define CChatManager__FreeChatWindow_x                             0x69A2A0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A3AE0
#define CChatManager__SetLockedActiveChatWindow_x                  0x69A7C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8EF490
#define CContextMenu__dCContextMenu_x                              0x8EF6A0
#define CContextMenu__AddMenuItem_x                                0x8EFBC0
#define CContextMenu__RemoveMenuItem_x                             0x8EF820
#define CContextMenu__RemoveAllMenuItems_x                         0x8EF840
#define CContextMenu__CheckMenuItem_x                              0x8EF8C0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8DB890
#define CContextMenuManager__RemoveMenu_x                          0x8DBC20
#define CContextMenuManager__PopupMenu_x                           0x8DC070
#define CContextMenuManager__Flush_x                               0x8DB900
#define CContextMenuManager__GetMenu_x                             0x419650

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x88EDD0
#define CChatService__GetFriendName_x                              0x88EDE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6A15B0
#define CChatWindow__Clear_x                                       0x6A0E90
#define CChatWindow__WndNotification_x                             0x6A1EC0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8DF6E0
#define CComboWnd__Draw_x                                          0x8DF8F0
#define CComboWnd__GetCurChoice_x                                  0x8DF490
#define CComboWnd__GetListRect_x                                   0x8DFB90
#define CComboWnd__GetTextRect_x                                   0x8DF750
#define CComboWnd__InsertChoice_x                                  0x8DFCF0
#define CComboWnd__SetColors_x                                     0x8DF420
#define CComboWnd__SetChoice_x                                     0x8DF450
#define CComboWnd__GetItemCount_x                                  0x8DF480
#define CComboWnd__GetCurChoiceText_x                              0x8DF4D0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AB7C0
#define CContainerWnd__vftable_x                                   0xAF7CD0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C7030
#define CDisplay__GetClickedActor_x                                0x4BF8F0
#define CDisplay__GetUserDefinedColor_x                            0x4BE4D0
#define CDisplay__GetWorldFilePath_x                               0x4BD920
#define CDisplay__is3dON_x                                         0x4BCDB0
#define CDisplay__ReloadUI_x                                       0x4D1010
#define CDisplay__WriteTextHD2_x                                   0x4C33C0
#define CDisplay__TrueDistance_x                                   0x4C0520

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x906880

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8F39F0
#define CEditWnd__GetCharIndexPt_x                                 0x8F4B50
#define CEditWnd__GetDisplayString_x                               0x8F3BA0
#define CEditWnd__GetHorzOffset_x                                  0x8F3EE0
#define CEditWnd__GetLineForPrintableChar_x                        0x8F4610
#define CEditWnd__GetSelStartPt_x                                  0x8F4E10
#define CEditWnd__GetSTMLSafeText_x                                0x8F4080
#define CEditWnd__PointFromPrintableChar_x                         0x8F4700
#define CEditWnd__SelectableCharFromPoint_x                        0x8F4880
#define CEditWnd__SetEditable_x                                    0x8F4050

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56BD30
#define CEverQuest__ClickedPlayer_x                                0x5658B0
#define CEverQuest__CreateTargetIndicator_x                        0x5667B0
#define CEverQuest__DeleteTargetIndicator_x                        0x566830
#define CEverQuest__DoTellWindow_x                                 0x477680
#define CEverQuest__OutputTextToLog_x                              0x4772E0
#define CEverQuest__DropHeldItemOnGround_x                         0x57C2A0
#define CEverQuest__dsp_chat_x                                     0x4779C0
#define CEverQuest__trimName_x                                     0x5621C0
#define CEverQuest__Emote_x                                        0x57A5B0
#define CEverQuest__EnterZone_x                                    0x575690
#define CEverQuest__GetBodyTypeDesc_x                              0x55FC00
#define CEverQuest__GetClassDesc_x                                 0x569150
#define CEverQuest__GetClassThreeLetterCode_x                      0x569750
#define CEverQuest__GetDeityDesc_x                                 0x5604E0
#define CEverQuest__GetLangDesc_x                                  0x55FF90
#define CEverQuest__GetRaceDesc_x                                  0x569910
#define CEverQuest__InterpretCmd_x                                 0x56D4B0
#define CEverQuest__LeftClickedOnPlayer_x                          0x581DF0
#define CEverQuest__LMouseUp_x                                     0x583E30
#define CEverQuest__RightClickedOnPlayer_x                         0x582900
#define CEverQuest__RMouseUp_x                                     0x583890
#define CEverQuest__SetGameState_x                                 0x566180
#define CEverQuest__UPCNotificationFlush_x                         0x55E590
#define CEverQuest__IssuePetCommand_x                              0x56DE90

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BC520
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BC580
#define CGaugeWnd__Draw_x                                          0x6BC9B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B930
#define CGuild__GetGuildName_x                                     0x43BE00
#define CGuild__GetGuildIndex_x                                    0x43D010

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D89D0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E5DF0
#define CInvSlotMgr__MoveItem_x                                    0x6E65B0
#define CInvSlotMgr__SelectSlot_x                                  0x6E56F0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E4B50
#define CInvSlot__SliderComplete_x                                 0x6E22D0
#define CInvSlot__GetItemBase_x                                    0x6E1770
#define CInvSlot__UpdateItem_x                                     0x6E1CF0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E79E0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E8B10

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7B6F50
#define CItemDisplayWnd__UpdateStrings_x                           0x6E9C20
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F6820
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F6D20
#define CItemDisplayWnd__SetItem_x                                 0x6FC600

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7EDF10

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6F01C0

// CLabel 
#define CLabel__Draw_x                                             0x7033A0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8CB3A0
#define CListWnd__dCListWnd_x                                      0x8CC660
#define CListWnd__AddColumn_x                                      0x8CC600
#define CListWnd__AddColumn1_x                                     0x8CBC90
#define CListWnd__AddLine_x                                        0x8CB670
#define CListWnd__AddString_x                                      0x8CB890
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C84A0
#define CListWnd__CalculateVSBRange_x                              0x8CA860
#define CListWnd__ClearSel_x                                       0x8C77C0
#define CListWnd__ClearAllSel_x                                    0x8C7770
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8CB230
#define CListWnd__Compare_x                                        0x8C91A0
#define CListWnd__Draw_x                                           0x8CA460
#define CListWnd__DrawColumnSeparators_x                           0x8CA2F0
#define CListWnd__DrawHeader_x                                     0x8C7A80
#define CListWnd__DrawItem_x                                       0x8C9820
#define CListWnd__DrawLine_x                                       0x8C9F90
#define CListWnd__DrawSeparator_x                                  0x8CA390
#define CListWnd__EnableLine_x                                     0x8C79A0
#define CListWnd__EnsureVisible_x                                  0x8C8600
#define CListWnd__ExtendSel_x                                      0x8C9730
#define CListWnd__GetColumnMinWidth_x                              0x8C70B0
#define CListWnd__GetColumnWidth_x                                 0x8C6FE0
#define CListWnd__GetCurSel_x                                      0x8C67B0
#define CListWnd__GetItemAtPoint_x                                 0x8C88A0
#define CListWnd__GetItemAtPoint1_x                                0x8C8910
#define CListWnd__GetItemData_x                                    0x8C6B00
#define CListWnd__GetItemHeight_x                                  0x8C8100
#define CListWnd__GetItemIcon_x                                    0x8C6CF0
#define CListWnd__GetItemRect_x                                    0x8C86E0
#define CListWnd__GetItemText_x                                    0x8C6BA0
#define CListWnd__GetSelList_x                                     0x8CBB80
#define CListWnd__GetSeparatorRect_x                               0x8C90C0
#define CListWnd__InsertLine_x                                     0x8CBA70
#define CListWnd__RemoveLine_x                                     0x8CBA80
#define CListWnd__SetColors_x                                      0x8C6900
#define CListWnd__SetColumnJustification_x                         0x8C7340
#define CListWnd__SetColumnWidth_x                                 0x8C7060
#define CListWnd__SetCurSel_x                                      0x8C67F0
#define CListWnd__SetItemColor_x                                   0x8CAF20
#define CListWnd__SetItemData_x                                    0x8C7820
#define CListWnd__SetItemText_x                                    0x8CAD60
#define CListWnd__ShiftColumnSeparator_x                           0x8CABF0
#define CListWnd__Sort_x                                           0x8CC760
#define CListWnd__ToggleSel_x                                      0x8C76F0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71C440

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73FAC0
#define CMerchantWnd__RequestBuyItem_x                             0x7489D0
#define CMerchantWnd__RequestSellItem_x                            0x74B0B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x740040
#define CMerchantWnd__SelectBuySellSlot_x                          0x73D080
#define CMerchantWnd__ActualSelect_x                               0x740E70

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x85D1E0
#define CPacketScrambler__hton_x                                   0x85D1F0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8EA2F0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8EA3D0
#define CSidlManager__CreateLabel_x                                0x7ABF50
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E8880
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8EA6B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8E1720
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8E1620
#define CSidlScreenWnd__ConvertToRes_x                             0x906760
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8E2030
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8E3220
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8E32D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8E2790
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8E19E0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8E1150
#define CSidlScreenWnd__GetSidlPiece_x                             0x8E1BD0
#define CSidlScreenWnd__Init1_x                                    0x8E2EF0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8E20F0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8E1310
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8E29D0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8E0DB0
#define CSidlScreenWnd__StoreIniVis_x                              0x8E1100
#define CSidlScreenWnd__WndNotification_x                          0x8E2C70
#define CSidlScreenWnd__GetChildItem_x                             0x8E1220
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8D4BB0
#define CSidlScreenWnd__m_layoutCopy_x                             0x1740E68

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x607950
#define CSkillMgr__GetSkillCap_x                                   0x607B30
#define CSkillMgr__GetNameToken_x                                  0x607500

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x905A10
#define CSliderWnd__SetValue_x                                     0x905BE0
#define CSliderWnd__SetNumTicks_x                                  0x906360

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7B22B0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8FF4A0
#define CStmlWnd__CalculateHSBRange_x                              0x8F79F0
#define CStmlWnd__CalculateVSBRange_x                              0x8F7960
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F7B70
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F8370
#define CStmlWnd__ForceParseNow_x                                  0x8FFE20
#define CStmlWnd__GetNextTagPiece_x                                0x8F8270
#define CStmlWnd__GetSTMLText_x                                    0x4858A0
#define CStmlWnd__GetVisibleText_x                                 0x8F8DC0
#define CStmlWnd__InitializeWindowVariables_x                      0x8FB390
#define CStmlWnd__MakeStmlColorTag_x                               0x8F6C40
#define CStmlWnd__MakeWndNotificationTag_x                         0x8F6CA0
#define CStmlWnd__SetSTMLText_x                                    0x8FCBE0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8FF140
#define CStmlWnd__UpdateHistoryString_x                            0x8F9D00

// CTabWnd 
#define CTabWnd__Draw_x                                            0x903340
#define CTabWnd__DrawCurrentPage_x                                 0x902BD0
#define CTabWnd__DrawTab_x                                         0x902990
#define CTabWnd__GetCurrentPage_x                                  0x902F80
#define CTabWnd__GetPageInnerRect_x                                0x902680
#define CTabWnd__GetTabInnerRect_x                                 0x902880
#define CTabWnd__GetTabRect_x                                      0x902750
#define CTabWnd__InsertPage_x                                      0x903630
#define CTabWnd__SetPage_x                                         0x902FB0
#define CTabWnd__SetPageRect_x                                     0x903280
#define CTabWnd__UpdatePage_x                                      0x9035D0
#define CTabWnd__GetPageFromTabIndex_x                             0x9028E0
#define CTabWnd__GetCurrentTabIndex_x                              0x902610

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E8CC0
#define CPageWnd__SetTabText_x                                     0x90FAB0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4374B0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8DF090
#define CTextureFont__GetTextExtent_x                              0x8DEDF0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x640210

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x90BEF0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8C4910

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5A8AC0
#define CXStr__CXStr1_x                                            0x90ABB0
#define CXStr__CXStr3_x                                            0x8A7BC0
#define CXStr__dCXStr_x                                            0x6BC400
#define CXStr__operator_equal_x                                    0x8A7D30
#define CXStr__operator_equal1_x                                   0x8A7D80
#define CXStr__operator_plus_equal1_x                              0x8A8E80

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8DCBA0
#define CXWnd__BringToTop_x                                        0x8D3DB0
#define CXWnd__Center_x                                            0x8D9EC0
#define CXWnd__ClrFocus_x                                          0x8D39A0
#define CXWnd__Destroy_x                                           0x8DA9A0
#define CXWnd__DoAllDrawing_x                                      0x8D9B10
#define CXWnd__DrawChildren_x                                      0x8D9CB0
#define CXWnd__DrawColoredRect_x                                   0x8D4170
#define CXWnd__DrawTooltip_x                                       0x8D4420
#define CXWnd__DrawTooltipAtPoint_x                                0x8D8AB0
#define CXWnd__GetBorderFrame_x                                    0x8D4880
#define CXWnd__GetChildWndAt_x                                     0x8DA880
#define CXWnd__GetClientClipRect_x                                 0x8D4630
#define CXWnd__GetScreenClipRect_x                                 0x8D91B0
#define CXWnd__GetScreenRect_x                                     0x8D4A50
#define CXWnd__GetTooltipRect_x                                    0x8D42B0
#define CXWnd__GetWindowTextA_x                                    0x4274D0
#define CXWnd__IsActive_x                                          0x8CF440
#define CXWnd__IsDescendantOf_x                                    0x8D47C0
#define CXWnd__IsReallyVisible_x                                   0x8D7AE0
#define CXWnd__IsType_x                                            0x8D9F30
#define CScreenPieceTemplate__IsType_x                             0x9085F0
#define CXWnd__Move_x                                              0x8D7200
#define CXWnd__Move1_x                                             0x8D97D0
#define CXWnd__ProcessTransition_x                                 0x8D3D60
#define CXWnd__Refade_x                                            0x8D3B40
#define CXWnd__Resize_x                                            0x8D4B10
#define CXWnd__Right_x                                             0x8D8FB0
#define CXWnd__SetFocus_x                                          0x8D6380
#define CXWnd__SetFont_x                                           0x8D39F0
#define CXWnd__SetKeyTooltip_x                                     0x8D4D80
#define CXWnd__SetMouseOver_x                                      0x8D94F0
#define CXWnd__StartFade_x                                         0x8D3E00
#define CXWnd__GetChildItem_x                                      0x8D9430
#define CXWnd__SetParent_x                                         0x8DA830

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8D0CD0
#define CXWndManager__DrawWindows_x                                0x8D0920
#define CXWndManager__GetKeyboardFlags_x                           0x8CEF80
#define CXWndManager__HandleKeyboardMsg_x                          0x8CF8C0
#define CXWndManager__RemoveWnd_x                                  0x8CF5D0

// CDBStr
#define CDBStr__GetString_x                                        0x4BB620

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452C50
#define EQ_Character__Cur_HP_x                                     0x466390
#define EQ_Character__Cur_Mana_x                                   0x45B2D0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44BC70
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443C80
#define EQ_Character__GetFocusRangeModifier_x                      0x443CE0
#define EQ_Character__GetHPRegen_x                                 0x46A570
#define EQ_Character__GetEnduranceRegen_x                          0x4659A0
#define EQ_Character__GetManaRegen_x                               0x46AB10
#define EQ_Character__Max_Endurance_x                              0x5CDED0
#define EQ_Character__Max_HP_x                                     0x45DE50
#define EQ_Character__Max_Mana_x                                   0x5CDD00
#define EQ_Character__doCombatAbility_x                            0x5CB3D0
#define EQ_Character__UseSkill_x                                   0x471AE0
#define EQ_Character__GetConLevel_x                                0x5C0970
#define EQ_Character__IsExpansionFlag_x                            0x4269E0
#define EQ_Character__TotalEffect_x                                0x44FD80
#define EQ_Character__GetPCSpellAffect_x                           0x44C070
#define EQ_Character__SpellDuration_x                              0x44A010
#define EQ_Character__FindItemByRecord_x                           0x463A00
#define EQ_Character__GetAdjustedSkill_x                           0x466560
#define EQ_Character__GetBaseSkill_x                               0x45DD30

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x87AFF0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D6420

//PcClient
#define PcClient__PcClient_x                                       0x5C27B0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x4470F0
#define CCharacterSelect__EnterWorld_x                             0x4468C0
#define CCharacterSelect__Quit_x                                   0x445480

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5A0890
#define EQ_Item__CreateItemTagString_x                             0x85B400
#define EQ_Item__IsStackable_x                                     0x850B20
#define EQ_Item__GetImageNum_x                                     0x8535A0
#define EQ_Item__CreateItemClient_x                                0x5A1950
#define EQ_Item__GetItemValue_x                                    0x859ED0
#define EQ_Item__ValueSellMerchant_x                               0x85CE40
#define EQ_Item__IsKeyRingItem_x                                   0x8515D0
#define EQ_Item__CanGoInBag_x                                      0x5A0A20
#define EQ_Item__GetMaxItemCount_x                                 0x850A10
#define EQ_Item__GetHeldItem_x                                     0x8523B0
#define EQ_Item__GetAugmentFitBySlot_x                             0x85CC70

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DB9D0
#define EQ_LoadingS__Array_x                                       0xC17958

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5D03F0
#define EQ_PC__GetAlternateAbilityId_x                             0x8652B0
#define EQ_PC__GetCombatAbility_x                                  0x865340
#define EQ_PC__GetCombatAbilityTimer_x                             0x85FE90
#define EQ_PC__GetItemRecastTimer_x                                0x5C9B80
#define EQ_PC__HasLoreItem_x                                       0x5C3F70
#define EQ_PC__AlertInventoryChanged_x                             0x5C0920
#define EQ_PC__GetPcZoneClient_x                                   0x5EA8E0
#define EQ_PC__RemoveMyAffect_x                                    0x5C8FE0
#define EQ_PC__GetKeyRingItems_x                                   0x8602B0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x872F90
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x867200

// EQItemList 
#define EQItemList__EQItemList_x                                   0x528000
#define EQItemList__add_object_x                                   0x5554A0
#define EQItemList__add_item_x                                     0x527F40
#define EQItemList__delete_item_x                                  0x5283F0
#define EQItemList__FreeItemList_x                                 0x5282F0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4BA8F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D61C0
#define EQPlayer__dEQPlayer_x                                      0x5DE7F0
#define EQPlayer__DoAttack_x                                       0x5F0270
#define EQPlayer__EQPlayer_x                                       0x5E0F20
#define EQPlayer__SetNameSpriteState_x                             0x5DB6D0
#define EQPlayer__SetNameSpriteTint_x                              0x5D75E0
#define PlayerBase__HasProperty_j_x                                0x939A50
#define EQPlayer__IsTargetable_x                                   0x939CF0
#define EQPlayer__CanSee_x                                         0x93A250
#define PlayerZoneClient__ChangeHeight_x                           0x5F0130
#define EQPlayer__CanSee1_x                                        0x93A340
#define PlayerBase__GetVisibilityLineSegment_x                     0x939FE0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5EAA90
#define PlayerZoneClient__IsValidTeleport_x                        0x555D40
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D3C20


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E4F10
#define EQPlayerManager__GetSpawnByName_x                          0x5E5370
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E4F40

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A6E50
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A6E90
#define KeypressHandler__ClearCommandStateArray_x                  0x5A6A40
#define KeypressHandler__HandleKeyDown_x                           0x5A5360
#define KeypressHandler__HandleKeyUp_x                             0x5A5680
#define KeypressHandler__SaveKeymapping_x                          0x5A6B10

// MapViewMap 
#define MapViewMap__Clear_x                                        0x714DD0
#define MapViewMap__SaveEx_x                                       0x718100

#define PlayerPointManager__GetAltCurrency_x                       0x8790B0

// StringTable 
#define StringTable__getString_x                                   0x8732C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CD960
#define PcZoneClient__RemovePetEffect_x                            0x5CA050
#define PcZoneClient__HasAlternateAbility_x                        0x5CA9F0
#define PcZoneClient__GetCurrentMod_x                              0x45D300
#define PcZoneClient__GetModCap_x                                  0x45AA30
#define PcZoneClient__CanEquipItem_x                               0x5CAF10
#define PcZoneClient__GetItemByID_x                                0x5CF760
#define PcZoneClient__GetItemByItemClass_x                         0x5D0310
#define PcZoneClient__RemoveBuffEffect_x                           0x5C9290

//Doors
#define EQSwitch__UseSwitch_x                                      0x55CEB0

//IconCache
#define IconCache__GetIcon_x                                       0x6B1C40

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A8B60
#define CContainerMgr__CloseContainer_x                            0x6A9380

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x77BE80

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x599900

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5DA0
#define EQ_Spell__SpellAffects_x                                   0x4F2FC0
#define EQ_Spell__SpellAffectBase_x                           0x4F3030
#define CharacterZoneClient__CalcAffectChange_x                    0x44BF00
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44B140
#define CLootWnd__LootAll_x                                        0x70A630
#define CLootWnd__RequestLootSlot_x                                0x70AE40
#define EQ_Spell__IsStackable_x                                    0x449A30
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449AE0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43F480
#define EQ_Spell__IsSPAStacking_x                                  0x4F2B30
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F3BA0
#define EQ_Spell__IsNoRemove_x                                     0x4354B0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F2B50

#define __IsResEffectSpell_x                                       0x449B60

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x884C60

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7C3B00
#define CTargetWnd__WndNotification_x                              0x7C35F0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7C3CE0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C8C30

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4EE700
#define EqSoundManager__PlayScriptMp3_x                            0x4F01A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A9AB0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8F3020
#define CSidlManager__FindAnimation1_x                             0x8E82B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E3250
#define CAltAbilityData__GetMercMaxRank_x                          0x4E3200
#define CAltAbilityData__GetMaxRank_x                              0x4D7AE0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5971D0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459A20
#define CharacterBase__CreateItemGlobalIndex_x                     0x476870
#define CharacterBase__CreateItemIndex_x                           0x521610
#define CharacterBase__GetItemPossession_x                         0x444900
#define CharacterBase__GetItemByGlobalIndex_x                      0x888AC0
#define CharacterBase__GetEffectId_x                               0x4599E0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x691970
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6910D0

//messages
#define msg_spell_worn_off_x                                       0x4FD840
#define msg_new_text_x                                             0x506FB0
#define msgTokenTextParam_x                                        0x503790

//SpellManager
#define SpellManager__vftable_x                                    0xAD3400
#define SpellManager__SpellManager_x                               0x47F540
#define Spellmanager__LoadTextSpells_x          0x60E840

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x93DD70

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x488FD0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43F3A0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4497C0
#define ItemGlobalIndex__IsValidIndex_x                            0x4592E0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x886920
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x885860

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7035F0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AD880
#define CCursorAttachment__Deactivate_x                            0x6ACDD0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x904F10
#define CEQSuiteTextureLoader__GetTexture_x                        0x905090

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                                0x606550

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                                0x48D860

//IString
#define IString__Append_x                                           0x480170
