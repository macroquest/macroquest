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
#define __ExpectedVersionDate                                     "Oct 28 2017"
#define __ExpectedVersionTime                                     "04:19:01"
#define __ActualVersionDate_x                                      0xAEE358
#define __ActualVersionTime_x                                      0xAEE364

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5ABD60
#define __MemChecker1_x                                            0x8AAEE0
#define __MemChecker2_x                                            0x641DB0
#define __MemChecker3_x                                            0x641D00
#define __MemChecker4_x                                            0x7FCDF0
#define __EncryptPad0_x                                            0xC4C6A0
#define __EncryptPad1_x                                            0xD288E8
#define __EncryptPad2_x                                            0xC76268
#define __EncryptPad3_x                                            0xC75E68
#define __EncryptPad4_x                                            0xD16EE8
#define __EncryptPad5_x                                            0x10D2218
#define __AC1_x                                                    0x7BBE45
#define __AC2_x                                                    0x564807
#define __AC3_x                                                    0x562980
#define __AC4_x                                                    0x574BA1
#define __AC5_x                                                    0x58898B
#define __AC6_x                                                    0x58C53E
#define __AC7_x                                                    0x582F8C
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
#define __do_loot_x                                                0x5334E0
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
#define __CastRay_x                                                0x54AFF0
#define __CastRay2_x                                               0x54A920
#define __HeadingDiff_x                                            0x93B310
#define __FixHeading_x                                             0x93B2A0
#define __get_bearing_x                                            0x53A630
#define __ConvertItemTags_x                                        0x538100
#define __ExecuteCmd_x                                             0x522A40
#define __EQGetTime_x                                              0x8AA880
#define __get_melee_range_x                                        0x5296E0
#define __GetGaugeValueFromEQ_x                                    0x7BAA00
#define __GetLabelFromEQ_x                                         0x7BBDD0
#define __ToggleKeyRingItem_x                                      0x490D00
#define __GetXTargetType_x                                         0x93CF10
#define __LoadFrontEnd_x                                           0x641480
#define __NewUIINI_x                                               0x7BA3D0
#define __ProcessGameEvents_x                                      0x584D20
#define __ProcessMouseEvent_x                                      0x5844C0
#define CrashDetected_x                                            0x642E40
#define wwsCrashReportCheckForUploader_x                           0x808A00
#define __AppCrashWrapper_x                                        0xC75E5C
#define __pCrashHandler_x                                          0x10E7A28
#define __CrashHandler_x                                           0x808490
#define wwsCrashReportPlatformLaunchUploader_x                     0x80AC30
#define DrawNetStatus_x                                            0x5BB840
#define Util__FastTime_x                                           0x8AA520
#define Expansion_HoT_x                                            0xF41588
#define __HelpPath_x                                               0xFC4E28
#define __STMLToText_x                                             0x8F0CD0
#define __GetAnimationCache_x                                      0x6B0D20

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423480
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E0E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DEB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D9380
#define AltAdvManager__IsAbilityReady_x                            0x4D93F0
#define AltAdvManager__GetAAById_x                                 0x4D98E0
#define AltAdvManager__CanTrainAbility_x                           0x4DA510
#define AltAdvManager__CanSeeAbility_x                             0x4DA0D0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46ACE0
#define CharacterZoneClient__HasSkill_x                            0x4665B0
#define CharacterZoneClient__MakeMeVisible_x                       0x46C850
#define CharacterZoneClient__IsStackBlocked_x                      0x44C2A0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B7D0
#define CharacterZoneClient__GetItemCountWorn_x                    0x464B10
#define CharacterZoneClient__GetItemCountInInventory_x             0x464BF0
#define CharacterZoneClient__GetCursorItemCount_x                  0x464CD0
#define CharacterZoneClient__FindAffectSlot_x                      0x4518C0
#define CharacterZoneClient__BardCastBard_x                        0x44AF40
#define CharacterZoneClient__GetMaxEffects_x                       0x449AD0
#define CharacterZoneClient__GetEffect_x                           0x44BA00
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451720
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449E20
#define CharacterZoneClient__GetLastEffectSlot_x                   0x450270

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x670DC0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67ED20

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x59A5E0
#define CButtonWnd__CButtonWnd_x                                   0x8E4FA0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x699F60
#define CChatManager__InitContextMenu_x                            0x69B0B0
#define CChatManager__FreeChatWindow_x                             0x699A10
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A31F0
#define CChatManager__SetLockedActiveChatWindow_x                  0x699F30

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8EF020
#define CContextMenu__dCContextMenu_x                              0x8EF230
#define CContextMenu__AddMenuItem_x                                0x8EF750
#define CContextMenu__RemoveMenuItem_x                             0x8EF3B0
#define CContextMenu__RemoveAllMenuItems_x                         0x8EF3D0
#define CContextMenu__CheckMenuItem_x                              0x8EF450

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8DB570
#define CContextMenuManager__RemoveMenu_x                          0x8DB910
#define CContextMenuManager__PopupMenu_x                           0x8DBD60
#define CContextMenuManager__Flush_x                               0x8DB5E0
#define CContextMenuManager__GetMenu_x                             0x419600

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x88E9C0
#define CChatService__GetFriendName_x                              0x88E9D0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6A0CE0
#define CChatWindow__Clear_x                                       0x6A05C0
#define CChatWindow__WndNotification_x                             0x6A15E0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8DF3C0
#define CComboWnd__Draw_x                                          0x8DF5D0
#define CComboWnd__GetCurChoice_x                                  0x8DF170
#define CComboWnd__GetListRect_x                                   0x8DF870
#define CComboWnd__GetTextRect_x                                   0x8DF430
#define CComboWnd__InsertChoice_x                                  0x8DF9D0
#define CComboWnd__SetColors_x                                     0x8DF100
#define CComboWnd__SetChoice_x                                     0x8DF130
#define CComboWnd__GetItemCount_x                                  0x8DF160
#define CComboWnd__GetCurChoiceText_x                              0x8DF1B0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AAED0
#define CContainerWnd__vftable_x                                   0xAF7C68

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C6F00
#define CDisplay__GetClickedActor_x                                0x4BF7C0
#define CDisplay__GetUserDefinedColor_x                            0x4BE3A0
#define CDisplay__GetWorldFilePath_x                               0x4BD7F0
#define CDisplay__is3dON_x                                         0x4BCC80
#define CDisplay__ReloadUI_x                                       0x4D0EE0
#define CDisplay__WriteTextHD2_x                                   0x4C3290
#define CDisplay__TrueDistance_x                                   0x4C03F0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x9064E0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8F3580
#define CEditWnd__GetCharIndexPt_x                                 0x8F46D0
#define CEditWnd__GetDisplayString_x                               0x8F3730
#define CEditWnd__GetHorzOffset_x                                  0x8F3A70
#define CEditWnd__GetLineForPrintableChar_x                        0x8F41A0
#define CEditWnd__GetSelStartPt_x                                  0x8F4980
#define CEditWnd__GetSTMLSafeText_x                                0x8F3C10
#define CEditWnd__PointFromPrintableChar_x                         0x8F4290
#define CEditWnd__SelectableCharFromPoint_x                        0x8F4410
#define CEditWnd__SetEditable_x                                    0x8F3BE0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56B3D0
#define CEverQuest__ClickedPlayer_x                                0x564F50
#define CEverQuest__CreateTargetIndicator_x                        0x565E50
#define CEverQuest__DeleteTargetIndicator_x                        0x565ED0
#define CEverQuest__DoTellWindow_x                                 0x477470
#define CEverQuest__OutputTextToLog_x                              0x4770D0
#define CEverQuest__DropHeldItemOnGround_x                         0x57B940
#define CEverQuest__dsp_chat_x                                     0x4777B0
#define CEverQuest__trimName_x                                     0x561860
#define CEverQuest__Emote_x                                        0x579C50
#define CEverQuest__EnterZone_x                                    0x574D30
#define CEverQuest__GetBodyTypeDesc_x                              0x55F2A0
#define CEverQuest__GetClassDesc_x                                 0x5687F0
#define CEverQuest__GetClassThreeLetterCode_x                      0x568DF0
#define CEverQuest__GetDeityDesc_x                                 0x55FB80
#define CEverQuest__GetLangDesc_x                                  0x55F630
#define CEverQuest__GetRaceDesc_x                                  0x568FB0
#define CEverQuest__InterpretCmd_x                                 0x56CB50
#define CEverQuest__LeftClickedOnPlayer_x                          0x5814A0
#define CEverQuest__LMouseUp_x                                     0x5834E0
#define CEverQuest__RightClickedOnPlayer_x                         0x581FB0
#define CEverQuest__RMouseUp_x                                     0x582F40
#define CEverQuest__SetGameState_x                                 0x565820
#define CEverQuest__UPCNotificationFlush_x                         0x55DC30
#define CEverQuest__IssuePetCommand_x                              0x56D530

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BBA50
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BBAB0
#define CGaugeWnd__Draw_x                                          0x6BBEE0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B720
#define CGuild__GetGuildName_x                                     0x43BBF0
#define CGuild__GetGuildIndex_x                                    0x43CE00

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D7F30

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E5390
#define CInvSlotMgr__MoveItem_x                                    0x6E5B50
#define CInvSlotMgr__SelectSlot_x                                  0x6E4C80

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E40E0
#define CInvSlot__SliderComplete_x                                 0x6E1870
#define CInvSlot__GetItemBase_x                                    0x6E0D00
#define CInvSlot__UpdateItem_x                                     0x6E1280

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E6FA0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E80E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7B6920
#define CItemDisplayWnd__UpdateStrings_x                           0x6E91E0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F5DB0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F62D0
#define CItemDisplayWnd__SetItem_x                                 0x6FBC40

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7ED910

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EF740

// CLabel 
#define CLabel__Draw_x                                             0x7029E0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8CB060
#define CListWnd__dCListWnd_x                                      0x8CC320
#define CListWnd__AddColumn_x                                      0x8CC2C0
#define CListWnd__AddColumn1_x                                     0x8CB950
#define CListWnd__AddLine_x                                        0x8CB330
#define CListWnd__AddString_x                                      0x8CB550
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C8170
#define CListWnd__CalculateVSBRange_x                              0x8CA530
#define CListWnd__ClearSel_x                                       0x8C7480
#define CListWnd__ClearAllSel_x                                    0x8C7430
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8CAEF0
#define CListWnd__Compare_x                                        0x8C8E60
#define CListWnd__Draw_x                                           0x8CA130
#define CListWnd__DrawColumnSeparators_x                           0x8C9FC0
#define CListWnd__DrawHeader_x                                     0x8C7740
#define CListWnd__DrawItem_x                                       0x8C94F0
#define CListWnd__DrawLine_x                                       0x8C9C60
#define CListWnd__DrawSeparator_x                                  0x8CA060
#define CListWnd__EnableLine_x                                     0x8C7660
#define CListWnd__EnsureVisible_x                                  0x8C82D0
#define CListWnd__ExtendSel_x                                      0x8C9400
#define CListWnd__GetColumnMinWidth_x                              0x8C6D70
#define CListWnd__GetColumnWidth_x                                 0x8C6CA0
#define CListWnd__GetCurSel_x                                      0x8C6470
#define CListWnd__GetItemAtPoint_x                                 0x8C8560
#define CListWnd__GetItemAtPoint1_x                                0x8C85D0
#define CListWnd__GetItemData_x                                    0x8C67B0
#define CListWnd__GetItemHeight_x                                  0x8C7DC0
#define CListWnd__GetItemIcon_x                                    0x8C69A0
#define CListWnd__GetItemRect_x                                    0x8C83A0
#define CListWnd__GetItemText_x                                    0x8C6850
#define CListWnd__GetSelList_x                                     0x8CB840
#define CListWnd__GetSeparatorRect_x                               0x8C8D80
#define CListWnd__InsertLine_x                                     0x8CB730
#define CListWnd__RemoveLine_x                                     0x8CB740
#define CListWnd__SetColors_x                                      0x8C65C0
#define CListWnd__SetColumnJustification_x                         0x8C7000
#define CListWnd__SetColumnWidth_x                                 0x8C6D20
#define CListWnd__SetCurSel_x                                      0x8C64B0
#define CListWnd__SetItemColor_x                                   0x8CABE0
#define CListWnd__SetItemData_x                                    0x8C74E0
#define CListWnd__SetItemText_x                                    0x8CAA20
#define CListWnd__ShiftColumnSeparator_x                           0x8CA8B0
#define CListWnd__Sort_x                                           0x8CC420
#define CListWnd__ToggleSel_x                                      0x8C73B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71BB90

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73F240
#define CMerchantWnd__RequestBuyItem_x                             0x748270
#define CMerchantWnd__RequestSellItem_x                            0x74A9D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x73F7F0
#define CMerchantWnd__SelectBuySellSlot_x                          0x73C7C0
#define CMerchantWnd__ActualSelect_x                               0x740600

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x85CDF0
#define CPacketScrambler__hton_x                                   0x85CE00

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E9F70
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8EA050
#define CSidlManager__CreateLabel_x                                0x7AB870
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E8510
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8EA330

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8E1410
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8E1310
#define CSidlScreenWnd__ConvertToRes_x                             0x9063C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8E1D10
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8E2ED0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8E2F80
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8E2450
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8E16C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8E0E40
#define CSidlScreenWnd__GetSidlPiece_x                             0x8E18B0
#define CSidlScreenWnd__Init1_x                                    0x8E2BA0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8E1DC0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8E1000
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8E2690
#define CSidlScreenWnd__StoreIniInfo_x                             0x8E0AA0
#define CSidlScreenWnd__StoreIniVis_x                              0x8E0DF0
#define CSidlScreenWnd__WndNotification_x                          0x8E2920
#define CSidlScreenWnd__GetChildItem_x                             0x8E0F10
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8D4840
#define CSidlScreenWnd__m_layoutCopy_x                             0x1740E68

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x606DE0
#define CSkillMgr__GetSkillCap_x                                   0x606FC0
#define CSkillMgr__GetNameToken_x                                  0x606990

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x905680
#define CSliderWnd__SetValue_x                                     0x905850
#define CSliderWnd__SetNumTicks_x                                  0x905FD0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7B1B70

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8FEFE0
#define CStmlWnd__CalculateHSBRange_x                              0x8F7550
#define CStmlWnd__CalculateVSBRange_x                              0x8F74C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F76D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F7ED0
#define CStmlWnd__ForceParseNow_x                                  0x8FF960
#define CStmlWnd__GetNextTagPiece_x                                0x8F7DD0
#define CStmlWnd__GetSTMLText_x                                    0x485670
#define CStmlWnd__GetVisibleText_x                                 0x8F8920
#define CStmlWnd__InitializeWindowVariables_x                      0x8FAEE0
#define CStmlWnd__MakeStmlColorTag_x                               0x8F67A0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8F6800
#define CStmlWnd__SetSTMLText_x                                    0x8FC730
#define CStmlWnd__StripFirstSTMLLines_x                            0x8FEC80
#define CStmlWnd__UpdateHistoryString_x                            0x8F9860

// CTabWnd 
#define CTabWnd__Draw_x                                            0x902EB0
#define CTabWnd__DrawCurrentPage_x                                 0x902740
#define CTabWnd__DrawTab_x                                         0x902500
#define CTabWnd__GetCurrentPage_x                                  0x902AF0
#define CTabWnd__GetPageInnerRect_x                                0x9021F0
#define CTabWnd__GetTabInnerRect_x                                 0x9023F0
#define CTabWnd__GetTabRect_x                                      0x9022C0
#define CTabWnd__InsertPage_x                                      0x9031A0
#define CTabWnd__SetPage_x                                         0x902B20
#define CTabWnd__SetPageRect_x                                     0x902DF0
#define CTabWnd__UpdatePage_x                                      0x903140
#define CTabWnd__GetPageFromTabIndex_x                             0x902450
#define CTabWnd__GetCurrentTabIndex_x                              0x902180

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E8290
#define CPageWnd__SetTabText_x                                     0x90F6F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4372A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8DED70
#define CTextureFont__GetTextExtent_x                              0x8DEAD0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63F700

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x90BB30

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8C45D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029C0
#define CXStr__CXStr1_x                                            0x8B9CD0
#define CXStr__CXStr3_x                                            0x8A77B0
#define CXStr__dCXStr_x                                            0x900430
#define CXStr__operator_equal_x                                    0x8A7920
#define CXStr__operator_equal1_x                                   0x8A7970
#define CXStr__operator_plus_equal1_x                              0x8A8A70

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8DC870
#define CXWnd__BringToTop_x                                        0x8D3A90
#define CXWnd__Center_x                                            0x8D9B60
#define CXWnd__ClrFocus_x                                          0x8D3660
#define CXWnd__Destroy_x                                           0x8DA620
#define CXWnd__DoAllDrawing_x                                      0x8D97B0
#define CXWnd__DrawChildren_x                                      0x8D9950
#define CXWnd__DrawColoredRect_x                                   0x8D3E70
#define CXWnd__DrawTooltip_x                                       0x8D4110
#define CXWnd__DrawTooltipAtPoint_x                                0x8D8720
#define CXWnd__GetBorderFrame_x                                    0x8D4560
#define CXWnd__GetChildWndAt_x                                     0x8DA510
#define CXWnd__GetClientClipRect_x                                 0x8D4320
#define CXWnd__GetScreenClipRect_x                                 0x8D8E20
#define CXWnd__GetScreenRect_x                                     0x8D46F0
#define CXWnd__GetTooltipRect_x                                    0x8D3FA0
#define CXWnd__GetWindowTextA_x                                    0x427560
#define CXWnd__IsActive_x                                          0x8CF0C0
#define CXWnd__IsDescendantOf_x                                    0x8D44B0
#define CXWnd__IsReallyVisible_x                                   0x8D7790
#define CXWnd__IsType_x                                            0x8D9BD0
#define CScreenPieceTemplate__IsType_x                             0x9082A0
#define CXWnd__Move_x                                              0x8D6EC0
#define CXWnd__Move1_x                                             0x8D9450
#define CXWnd__ProcessTransition_x                                 0x8D3A30
#define CXWnd__Refade_x                                            0x8D3800
#define CXWnd__Resize_x                                            0x8D47B0
#define CXWnd__Right_x                                             0x8D8C20
#define CXWnd__SetFocus_x                                          0x8D6030
#define CXWnd__SetFont_x                                           0x8D36B0
#define CXWnd__SetKeyTooltip_x                                     0x8D4A10
#define CXWnd__SetMouseOver_x                                      0x8D9140
#define CXWnd__StartFade_x                                         0x8D3AE0
#define CXWnd__GetChildItem_x                                      0x8D9080
#define CXWnd__SetParent_x                                         0x8DA4C0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8D0960
#define CXWndManager__DrawWindows_x                                0x8D05A0
#define CXWndManager__GetKeyboardFlags_x                           0x8CEC30
#define CXWndManager__HandleKeyboardMsg_x                          0x8CF550
#define CXWndManager__RemoveWnd_x                                  0x8CF250

// CDBStr
#define CDBStr__GetString_x                                        0x4BB4E0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452A80
#define EQ_Character__Cur_HP_x                                     0x466190
#define EQ_Character__Cur_Mana_x                                   0x45B0C0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44BAE0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443A10
#define EQ_Character__GetFocusRangeModifier_x                      0x443B60
#define EQ_Character__GetHPRegen_x                                 0x46A370
#define EQ_Character__GetEnduranceRegen_x                          0x4657A0
#define EQ_Character__GetManaRegen_x                               0x46A910
#define EQ_Character__Max_Endurance_x                              0x5CD860
#define EQ_Character__Max_HP_x                                     0x45DC40
#define EQ_Character__Max_Mana_x                                   0x5CD690
#define EQ_Character__doCombatAbility_x                            0x5CAD60
#define EQ_Character__UseSkill_x                                   0x4718E0
#define EQ_Character__GetConLevel_x                                0x5BFF20
#define EQ_Character__IsExpansionFlag_x                            0x426AA0
#define EQ_Character__TotalEffect_x                                0x44FBB0
#define EQ_Character__GetPCSpellAffect_x                           0x44BE70
#define EQ_Character__SpellDuration_x                              0x449E70
#define EQ_Character__FindItemByRecord_x                           0x4637E0
#define EQ_Character__GetAdjustedSkill_x                           0x466360
#define EQ_Character__GetBaseSkill_x                               0x45DB20

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x87ABF0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D5DC0

//PcClient
#define PcClient__PcClient_x                                       0x5C1D70

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446F20
#define CCharacterSelect__EnterWorld_x                             0x4466F0
#define CCharacterSelect__Quit_x                                   0x4452B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59FFA0
#define EQ_Item__CreateItemTagString_x                             0x85B030
#define EQ_Item__IsStackable_x                                     0x850740
#define EQ_Item__GetImageNum_x                                     0x853200
#define EQ_Item__CreateItemClient_x                                0x5A1040
#define EQ_Item__GetItemValue_x                                    0x859AF0
#define EQ_Item__ValueSellMerchant_x                               0x85CA50
#define EQ_Item__IsKeyRingItem_x                                   0x8511D0
#define EQ_Item__CanGoInBag_x                                      0x5A0130
#define EQ_Item__GetMaxItemCount_x                                 0x850630
#define EQ_Item__GetHeldItem_x                                     0x852020
#define EQ_Item__GetAugmentFitBySlot_x                             0x85C880

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DB930
#define EQ_LoadingS__Array_x                                       0xC17958

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CFD70
#define EQ_PC__GetAlternateAbilityId_x                             0x864DF0
#define EQ_PC__GetCombatAbility_x                                  0x864E80
#define EQ_PC__GetCombatAbilityTimer_x                             0x85FAA0
#define EQ_PC__GetItemRecastTimer_x                                0x5C9520
#define EQ_PC__HasLoreItem_x                                       0x5C3530
#define EQ_PC__AlertInventoryChanged_x                             0x5BFED0
#define EQ_PC__GetPcZoneClient_x                                   0x5EA260
#define EQ_PC__RemoveMyAffect_x                                    0x5C8980
#define EQ_PC__GetKeyRingItems_x                                   0x85FEC0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x872AF0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x866D70

// EQItemList 
#define EQItemList__EQItemList_x                                   0x527790
#define EQItemList__add_object_x                                   0x554B90
#define EQItemList__add_item_x                                     0x5276D0
#define EQItemList__delete_item_x                                  0x527B80
#define EQItemList__FreeItemList_x                                 0x527A80

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4BA770

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D5B60
#define EQPlayer__dEQPlayer_x                                      0x5DE1A0
#define EQPlayer__DoAttack_x                                       0x5EFBE0
#define EQPlayer__EQPlayer_x                                       0x5E08D0
#define EQPlayer__SetNameSpriteState_x                             0x5DB060
#define EQPlayer__SetNameSpriteTint_x                              0x5D6F80
#define PlayerBase__HasProperty_j_x                                0x939720
#define EQPlayer__IsTargetable_x                                   0x9399C0
#define EQPlayer__CanSee_x                                         0x939F20
#define PlayerZoneClient__ChangeHeight_x                           0x5EFAA0
#define EQPlayer__CanSee1_x                                        0x93A010
#define PlayerBase__GetVisibilityLineSegment_x                     0x939CB0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5EA410
#define PlayerZoneClient__IsValidTeleport_x                        0x555440
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D3B90


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E48A0
#define EQPlayerManager__GetSpawnByName_x                          0x5E4D00
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E48D0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A6540
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A6580
#define KeypressHandler__ClearCommandStateArray_x                  0x5A6130
#define KeypressHandler__HandleKeyDown_x                           0x5A4A50
#define KeypressHandler__HandleKeyUp_x                             0x5A4D70
#define KeypressHandler__SaveKeymapping_x                          0x5A6200

// MapViewMap 
#define MapViewMap__Clear_x                                        0x714520
#define MapViewMap__SaveEx_x                                       0x717850

#define PlayerPointManager__GetAltCurrency_x                       0x878C00

// StringTable 
#define StringTable__getString_x                                   0x872E20

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CD2F0
#define PcZoneClient__RemovePetEffect_x                            0x5C99F0
#define PcZoneClient__HasAlternateAbility_x                        0x5CA390
#define PcZoneClient__GetCurrentMod_x                              0x45D0F0
#define PcZoneClient__GetModCap_x                                  0x45A820
#define PcZoneClient__CanEquipItem_x                               0x5CA8B0
#define PcZoneClient__GetItemByID_x                                0x5CF0F0
#define PcZoneClient__GetItemByItemClass_x                         0x5CFC90
#define PcZoneClient__RemoveBuffEffect_x                           0x5C8C30

//Doors
#define EQSwitch__UseSwitch_x                                      0x55C570

//IconCache
#define IconCache__GetIcon_x                                       0x6B1350

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A8270
#define CContainerMgr__CloseContainer_x                            0x6A8A90

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x77B810

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x599010

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5EE0
#define EQ_Spell__SpellAffects_x                                   0x4F30D0
#define EQ_Spell__SpellAffectBase_x                           0x4F3140
#define CharacterZoneClient__CalcAffectChange_x                    0x44BD00
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AFA0
#define CLootWnd__LootAll_x                                        0x709D90
#define CLootWnd__RequestLootSlot_x                                0x70A5A0
#define EQ_Spell__IsStackable_x                                    0x449870
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449920
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43F210
#define EQ_Spell__IsSPAStacking_x                                  0x4F2C40
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F3CE0
#define EQ_Spell__IsNoRemove_x                                     0x4352C0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F2C60

#define __IsResEffectSpell_x                                       0x4499C0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x884860

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7C3440
#define CTargetWnd__WndNotification_x                              0x7C2F30
#define CTargetWnd__RefreshTargetBuffs_x                           0x7C3620

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C8560

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4EE7B0
#define EqSoundManager__PlayScriptMp3_x                            0x4F0250

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A9860

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8F2BB0
#define CSidlManager__FindAnimation1_x                             0x8E7F40

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E3240
#define CAltAbilityData__GetMercMaxRank_x                          0x4E31F0
#define CAltAbilityData__GetMaxRank_x                              0x4D7A10

//CTargetRing
#define CTargetRing__Cast_x                                        0x5968D0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459810
#define CharacterBase__CreateItemGlobalIndex_x                     0x476660
#define CharacterBase__CreateItemIndex_x                           0x520DE0
#define CharacterBase__GetItemPossession_x                         0x4447B0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8886B0
#define CharacterBase__GetEffectId_x                               0x4597D0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x690FD0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x690730

//messages
#define msg_spell_worn_off_x                                       0x4FD900
#define msg_new_text_x                                             0x507060
#define msgTokenTextParam_x                                        0x503840

//SpellManager
#define SpellManager__vftable_x                                    0xAD3410
#define SpellManager__SpellManager_x                               0x47F2E0
#define Spellmanager__LoadTextSpells_x          0x60DD10

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x93DA30

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x488CC0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43F130
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449620
#define ItemGlobalIndex__IsValidIndex_x                            0x459100

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x886520
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x885460

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x702C30

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6ACF70
#define CCursorAttachment__Deactivate_x                            0x6AC4C0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x904B80
#define CEQSuiteTextureLoader__GetTexture_x                        0x904D00

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                                0x605970

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                                0x48D550

//IString
#define IString__Append_x                                           0x47FF30
