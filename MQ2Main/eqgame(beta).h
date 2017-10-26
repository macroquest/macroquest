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
#define __ExpectedVersionDate                                     "Oct 26 2017"
#define __ExpectedVersionTime                                     "04:15:33"
#define __ActualVersionDate_x                                      0xAEE368
#define __ActualVersionTime_x                                      0xAEE374

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AC210
#define __MemChecker1_x                                            0x8AB850
#define __MemChecker2_x                                            0x642200
#define __MemChecker3_x                                            0x642150
#define __MemChecker4_x                                            0x7FD330
#define __EncryptPad0_x                                            0xC4C6A0
#define __EncryptPad1_x                                            0xD288E8
#define __EncryptPad2_x                                            0xC76268
#define __EncryptPad3_x                                            0xC75E68
#define __EncryptPad4_x                                            0xD16EE8
#define __EncryptPad5_x                                            0x10D2218
#define __AC1_x                                                    0x7BC165
#define __AC2_x                                                    0x564CD7
#define __AC3_x                                                    0x562E50
#define __AC4_x                                                    0x575071
#define __AC5_x                                                    0x588E4B
#define __AC6_x                                                    0x58C9FE
#define __AC7_x                                                    0x58344C
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
#define __do_loot_x                                                0x533A60
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
#define __CastRay_x                                                0x54B570
#define __CastRay2_x                                               0x54AEA0
#define __HeadingDiff_x                                            0x93C160
#define __FixHeading_x                                             0x93C0F0
#define __get_bearing_x                                            0x53ABB0
#define __ConvertItemTags_x                                        0x538680
#define __ExecuteCmd_x                                             0x522F60
#define __EQGetTime_x                                              0x8AB1F0
#define __get_melee_range_x                                        0x529C00
#define __GetGaugeValueFromEQ_x                                    0x7BAD20
#define __GetLabelFromEQ_x                                         0x7BC0F0
#define __ToggleKeyRingItem_x                                      0x490D00
#define __GetXTargetType_x                                         0x93DD60
#define __LoadFrontEnd_x                                           0x6418D0
#define __NewUIINI_x                                               0x7BA6F0
#define __ProcessGameEvents_x                                      0x5851E0
#define __ProcessMouseEvent_x                                      0x584980
#define CrashDetected_x                                            0x643290
#define wwsCrashReportCheckForUploader_x                           0x808F70
#define __AppCrashWrapper_x                                        0xC75E5C
#define __pCrashHandler_x                                          0x10E7A28
#define __CrashHandler_x                                           0x8089D0
#define wwsCrashReportPlatformLaunchUploader_x                     0x80B170
#define DrawNetStatus_x                                            0x5BBE00
#define Util__FastTime_x                                           0x8AAE90
#define Expansion_HoT_x                                            0xF41588
#define __HelpPath_x                                               0xFC4E28
#define __STMLToText_x                                             0x8F19E0
#define __GetAnimationCache_x                                      0x6B10E0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423360
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DFF0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DDC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D9070
#define AltAdvManager__IsAbilityReady_x                            0x4D90E0
#define AltAdvManager__GetAAById_x                                 0x4D95D0
#define AltAdvManager__CanTrainAbility_x                           0x4DA200
#define AltAdvManager__CanSeeAbility_x                             0x4D9DC0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46ACA0
#define CharacterZoneClient__HasSkill_x                            0x466570
#define CharacterZoneClient__MakeMeVisible_x                       0x46C810
#define CharacterZoneClient__IsStackBlocked_x                      0x44C170
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B630
#define CharacterZoneClient__GetItemCountWorn_x                    0x464AD0
#define CharacterZoneClient__GetItemCountInInventory_x             0x464BB0
#define CharacterZoneClient__GetCursorItemCount_x                  0x464C90
#define CharacterZoneClient__FindAffectSlot_x                      0x451760
#define CharacterZoneClient__BardCastBard_x                        0x44ADB0
#define CharacterZoneClient__GetMaxEffects_x                       0x449940
#define CharacterZoneClient__GetEffect_x                           0x44B860
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4515C0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449C90
#define CharacterZoneClient__GetLastEffectSlot_x                   0x450110

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x671240

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67EF50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x59AA70
#define CButtonWnd__CButtonWnd_x                                   0x8E5C00

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x69A260
#define CChatManager__InitContextMenu_x                            0x69B3B0
#define CChatManager__FreeChatWindow_x                             0x699D10
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A3550
#define CChatManager__SetLockedActiveChatWindow_x                  0x69A230

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8EFD30
#define CContextMenu__dCContextMenu_x                              0x8EFF40
#define CContextMenu__AddMenuItem_x                                0x8F0460
#define CContextMenu__RemoveMenuItem_x                             0x8F00C0
#define CContextMenu__RemoveAllMenuItems_x                         0x8F00E0
#define CContextMenu__CheckMenuItem_x                              0x8F0160

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8DC160
#define CContextMenuManager__RemoveMenu_x                          0x8DC500
#define CContextMenuManager__PopupMenu_x                           0x8DC950
#define CContextMenuManager__Flush_x                               0x8DC1D0
#define CContextMenuManager__GetMenu_x                             0x419530

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x88F3D0
#define CChatService__GetFriendName_x                              0x88F3E0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6A1020
#define CChatWindow__Clear_x                                       0x6A0900
#define CChatWindow__WndNotification_x                             0x6A1930

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8DFFC0
#define CComboWnd__Draw_x                                          0x8E01D0
#define CComboWnd__GetCurChoice_x                                  0x8DFD70
#define CComboWnd__GetListRect_x                                   0x8E0470
#define CComboWnd__GetTextRect_x                                   0x8E0030
#define CComboWnd__InsertChoice_x                                  0x8E05D0
#define CComboWnd__SetColors_x                                     0x8DFD00
#define CComboWnd__SetChoice_x                                     0x8DFD30
#define CComboWnd__GetItemCount_x                                  0x8DFD60
#define CComboWnd__GetCurChoiceText_x                              0x8DFDB0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AB270
#define CContainerWnd__vftable_x                                   0xAF7C78

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C6DD0
#define CDisplay__GetClickedActor_x                                0x4BF690
#define CDisplay__GetUserDefinedColor_x                            0x4BE270
#define CDisplay__GetWorldFilePath_x                               0x4BD6C0
#define CDisplay__is3dON_x                                         0x4BCB50
#define CDisplay__ReloadUI_x                                       0x4D0DB0
#define CDisplay__WriteTextHD2_x                                   0x4C3160
#define CDisplay__TrueDistance_x                                   0x4C02C0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x907270

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8F4290
#define CEditWnd__GetCharIndexPt_x                                 0x8F53F0
#define CEditWnd__GetDisplayString_x                               0x8F4440
#define CEditWnd__GetHorzOffset_x                                  0x8F4780
#define CEditWnd__GetLineForPrintableChar_x                        0x8F4EB0
#define CEditWnd__GetSelStartPt_x                                  0x8F56B0
#define CEditWnd__GetSTMLSafeText_x                                0x8F4920
#define CEditWnd__PointFromPrintableChar_x                         0x8F4FA0
#define CEditWnd__SelectableCharFromPoint_x                        0x8F5120
#define CEditWnd__SetEditable_x                                    0x8F48F0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56B8A0
#define CEverQuest__ClickedPlayer_x                                0x565420
#define CEverQuest__CreateTargetIndicator_x                        0x566320
#define CEverQuest__DeleteTargetIndicator_x                        0x5663A0
#define CEverQuest__DoTellWindow_x                                 0x477400
#define CEverQuest__OutputTextToLog_x                              0x477060
#define CEverQuest__DropHeldItemOnGround_x                         0x57BE10
#define CEverQuest__dsp_chat_x                                     0x477740
#define CEverQuest__trimName_x                                     0x561D30
#define CEverQuest__Emote_x                                        0x57A120
#define CEverQuest__EnterZone_x                                    0x575200
#define CEverQuest__GetBodyTypeDesc_x                              0x55F770
#define CEverQuest__GetClassDesc_x                                 0x568CC0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5692C0
#define CEverQuest__GetDeityDesc_x                                 0x560050
#define CEverQuest__GetLangDesc_x                                  0x55FB00
#define CEverQuest__GetRaceDesc_x                                  0x569480
#define CEverQuest__InterpretCmd_x                                 0x56D020
#define CEverQuest__LeftClickedOnPlayer_x                          0x581960
#define CEverQuest__LMouseUp_x                                     0x5839A0
#define CEverQuest__RightClickedOnPlayer_x                         0x582470
#define CEverQuest__RMouseUp_x                                     0x583400
#define CEverQuest__SetGameState_x                                 0x565CF0
#define CEverQuest__UPCNotificationFlush_x                         0x55E100
#define CEverQuest__IssuePetCommand_x                              0x56DA00

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BC010
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BC070
#define CGaugeWnd__Draw_x                                          0x6BC4A0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B6D0
#define CGuild__GetGuildName_x                                     0x43BBA0
#define CGuild__GetGuildIndex_x                                    0x43CDB0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D84E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E5910
#define CInvSlotMgr__MoveItem_x                                    0x6E60D0
#define CInvSlotMgr__SelectSlot_x                                  0x6E5200

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E4650
#define CInvSlot__SliderComplete_x                                 0x6E1DE0
#define CInvSlot__GetItemBase_x                                    0x6E1280
#define CInvSlot__UpdateItem_x                                     0x6E1800

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E7500
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E8640

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7B6BB0
#define CItemDisplayWnd__UpdateStrings_x                           0x6E9740
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F6360
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F6880
#define CItemDisplayWnd__SetItem_x                                 0x6FC120

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7EDCA0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EFD00

// CLabel 
#define CLabel__Draw_x                                             0x702ED0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8CBA40
#define CListWnd__dCListWnd_x                                      0x8CCD00
#define CListWnd__AddColumn_x                                      0x8CCCA0
#define CListWnd__AddColumn1_x                                     0x8CC330
#define CListWnd__AddLine_x                                        0x8CBD10
#define CListWnd__AddString_x                                      0x8CBF30
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C8B30
#define CListWnd__CalculateVSBRange_x                              0x8CAF00
#define CListWnd__ClearSel_x                                       0x8C7E40
#define CListWnd__ClearAllSel_x                                    0x8C7DF0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8CB8D0
#define CListWnd__Compare_x                                        0x8C9830
#define CListWnd__Draw_x                                           0x8CAB00
#define CListWnd__DrawColumnSeparators_x                           0x8CA990
#define CListWnd__DrawHeader_x                                     0x8C8100
#define CListWnd__DrawItem_x                                       0x8C9EC0
#define CListWnd__DrawLine_x                                       0x8CA630
#define CListWnd__DrawSeparator_x                                  0x8CAA30
#define CListWnd__EnableLine_x                                     0x8C8020
#define CListWnd__EnsureVisible_x                                  0x8C8C90
#define CListWnd__ExtendSel_x                                      0x8C9DD0
#define CListWnd__GetColumnMinWidth_x                              0x8C7730
#define CListWnd__GetColumnWidth_x                                 0x8C7660
#define CListWnd__GetCurSel_x                                      0x8C6E20
#define CListWnd__GetItemAtPoint_x                                 0x8C8F30
#define CListWnd__GetItemAtPoint1_x                                0x8C8FA0
#define CListWnd__GetItemData_x                                    0x8C7170
#define CListWnd__GetItemHeight_x                                  0x8C8780
#define CListWnd__GetItemIcon_x                                    0x8C7360
#define CListWnd__GetItemRect_x                                    0x8C8D70
#define CListWnd__GetItemText_x                                    0x8C7210
#define CListWnd__GetSelList_x                                     0x8CC220
#define CListWnd__GetSeparatorRect_x                               0x8C9750
#define CListWnd__InsertLine_x                                     0x8CC110
#define CListWnd__RemoveLine_x                                     0x8CC120
#define CListWnd__SetColors_x                                      0x8C6F70
#define CListWnd__SetColumnJustification_x                         0x8C79C0
#define CListWnd__SetColumnWidth_x                                 0x8C76E0
#define CListWnd__SetCurSel_x                                      0x8C6E60
#define CListWnd__SetItemColor_x                                   0x8CB5C0
#define CListWnd__SetItemData_x                                    0x8C7EA0
#define CListWnd__SetItemText_x                                    0x8CB400
#define CListWnd__ShiftColumnSeparator_x                           0x8CB290
#define CListWnd__Sort_x                                           0x8CCE00
#define CListWnd__ToggleSel_x                                      0x8C7D70

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71BFB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73F520
#define CMerchantWnd__RequestBuyItem_x                             0x748430
#define CMerchantWnd__RequestSellItem_x                            0x74AB30
#define CMerchantWnd__SelectRecoverySlot_x                         0x73FAA0
#define CMerchantWnd__SelectBuySellSlot_x                          0x73CAD0
#define CMerchantWnd__ActualSelect_x                               0x7408C0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x85D5E0
#define CPacketScrambler__hton_x                                   0x85D5F0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8EABE0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8EACC0
#define CSidlManager__CreateLabel_x                                0x7ABAB0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E9170
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8EAFA0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8E2030
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8E1F20
#define CSidlScreenWnd__ConvertToRes_x                             0x907150
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8E2950
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8E3B30
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8E3BE0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8E30B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8E2300
#define CSidlScreenWnd__EnableIniStorage_x                         0x8E1A50
#define CSidlScreenWnd__GetSidlPiece_x                             0x8E24F0
#define CSidlScreenWnd__Init1_x                                    0x8E3800
#define CSidlScreenWnd__LoadIniInfo_x                              0x8E2A10
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8E1C10
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8E32F0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8E16A0
#define CSidlScreenWnd__StoreIniVis_x                              0x8E1A00
#define CSidlScreenWnd__WndNotification_x                          0x8E3580
#define CSidlScreenWnd__GetChildItem_x                             0x8E1B20
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8D5300
#define CSidlScreenWnd__m_layoutCopy_x                             0x1740E68

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x607310
#define CSkillMgr__GetSkillCap_x                                   0x6074F0
#define CSkillMgr__GetNameToken_x                                  0x606EC0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x906400
#define CSliderWnd__SetValue_x                                     0x9065D0
#define CSliderWnd__SetNumTicks_x                                  0x906D50

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7B1E90

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8FFD60
#define CStmlWnd__CalculateHSBRange_x                              0x8F82A0
#define CStmlWnd__CalculateVSBRange_x                              0x8F8210
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F8420
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F8C20
#define CStmlWnd__ForceParseNow_x                                  0x9006E0
#define CStmlWnd__GetNextTagPiece_x                                0x8F8B20
#define CStmlWnd__GetSTMLText_x                                    0x485600
#define CStmlWnd__GetVisibleText_x                                 0x8F9670
#define CStmlWnd__InitializeWindowVariables_x                      0x8FBC40
#define CStmlWnd__MakeStmlColorTag_x                               0x8F74F0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8F7550
#define CStmlWnd__SetSTMLText_x                                    0x8FD4A0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8FFA00
#define CStmlWnd__UpdateHistoryString_x                            0x8FA5B0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x903C00
#define CTabWnd__DrawCurrentPage_x                                 0x903490
#define CTabWnd__DrawTab_x                                         0x903250
#define CTabWnd__GetCurrentPage_x                                  0x903840
#define CTabWnd__GetPageInnerRect_x                                0x902F40
#define CTabWnd__GetTabInnerRect_x                                 0x903140
#define CTabWnd__GetTabRect_x                                      0x903010
#define CTabWnd__InsertPage_x                                      0x903EF0
#define CTabWnd__SetPage_x                                         0x903870
#define CTabWnd__SetPageRect_x                                     0x903B40
#define CTabWnd__UpdatePage_x                                      0x903E90
#define CTabWnd__GetPageFromTabIndex_x                             0x9031A0
#define CTabWnd__GetCurrentTabIndex_x                              0x902ED0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E87F0
#define CPageWnd__SetTabText_x                                     0x910520

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x437230

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8DF970
#define CTextureFont__GetTextExtent_x                              0x8DF6D0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63FB30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x90C910

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8C4E60

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5A8660
#define CXStr__CXStr1_x                                            0x8C6040
#define CXStr__CXStr3_x                                            0x8A8120
#define CXStr__dCXStr_x                                            0x90B5C0
#define CXStr__operator_equal_x                                    0x8A8290
#define CXStr__operator_equal1_x                                   0x8A82E0
#define CXStr__operator_plus_equal1_x                              0x8A93E0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8DD470
#define CXWnd__BringToTop_x                                        0x8D44E0
#define CXWnd__Center_x                                            0x8DA700
#define CXWnd__ClrFocus_x                                          0x8D40B0
#define CXWnd__Destroy_x                                           0x8DB1F0
#define CXWnd__DoAllDrawing_x                                      0x8DA350
#define CXWnd__DrawChildren_x                                      0x8DA4F0
#define CXWnd__DrawColoredRect_x                                   0x8D48D0
#define CXWnd__DrawTooltip_x                                       0x8D4B80
#define CXWnd__DrawTooltipAtPoint_x                                0x8D92C0
#define CXWnd__GetBorderFrame_x                                    0x8D4FE0
#define CXWnd__GetChildWndAt_x                                     0x8DB0D0
#define CXWnd__GetClientClipRect_x                                 0x8D4D90
#define CXWnd__GetScreenClipRect_x                                 0x8D99C0
#define CXWnd__GetScreenRect_x                                     0x8D51A0
#define CXWnd__GetTooltipRect_x                                    0x8D4A10
#define CXWnd__GetWindowTextA_x                                    0x4273C0
#define CXWnd__IsActive_x                                          0x8CFAD0
#define CXWnd__IsDescendantOf_x                                    0x8D4F20
#define CXWnd__IsReallyVisible_x                                   0x8D82F0
#define CXWnd__IsType_x                                            0x8DA770
#define CScreenPieceTemplate__IsType_x                             0x909000
#define CXWnd__Move_x                                              0x8D79D0
#define CXWnd__Move1_x                                             0x8DA000
#define CXWnd__ProcessTransition_x                                 0x8D4480
#define CXWnd__Refade_x                                            0x8D4250
#define CXWnd__Resize_x                                            0x8D5260
#define CXWnd__Right_x                                             0x8D97C0
#define CXWnd__SetFocus_x                                          0x8D6B40
#define CXWnd__SetFont_x                                           0x8D4100
#define CXWnd__SetKeyTooltip_x                                     0x8D54D0
#define CXWnd__SetMouseOver_x                                      0x8D9CF0
#define CXWnd__StartFade_x                                         0x8D4530
#define CXWnd__GetChildItem_x                                      0x8D9C30
#define CXWnd__SetParent_x                                         0x8DB080

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8D1390
#define CXWndManager__DrawWindows_x                                0x8D0FD0
#define CXWndManager__GetKeyboardFlags_x                           0x8CF600
#define CXWndManager__HandleKeyboardMsg_x                          0x8CFF70
#define CXWndManager__RemoveWnd_x                                  0x8CFC60

// CDBStr
#define CDBStr__GetString_x                                        0x4BB3B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452920
#define EQ_Character__Cur_HP_x                                     0x466150
#define EQ_Character__Cur_Mana_x                                   0x45B0A0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B940
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443970
#define EQ_Character__GetFocusRangeModifier_x                      0x4439D0
#define EQ_Character__GetHPRegen_x                                 0x46A330
#define EQ_Character__GetEnduranceRegen_x                          0x465760
#define EQ_Character__GetManaRegen_x                               0x46A8D0
#define EQ_Character__Max_Endurance_x                              0x5CDE20
#define EQ_Character__Max_HP_x                                     0x45DC20
#define EQ_Character__Max_Mana_x                                   0x5CDC50
#define EQ_Character__doCombatAbility_x                            0x5CB320
#define EQ_Character__UseSkill_x                                   0x4718A0
#define EQ_Character__GetConLevel_x                                0x5C0470
#define EQ_Character__IsExpansionFlag_x                            0x4268F0
#define EQ_Character__TotalEffect_x                                0x44FA50
#define EQ_Character__GetPCSpellAffect_x                           0x44BD40
#define EQ_Character__SpellDuration_x                              0x449CE0
#define EQ_Character__FindItemByRecord_x                           0x4637C0
#define EQ_Character__GetAdjustedSkill_x                           0x466320
#define EQ_Character__GetBaseSkill_x                               0x45DB00

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x87B5E0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D6380

//PcClient
#define PcClient__PcClient_x                                       0x5C22B0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446D70
#define CCharacterSelect__EnterWorld_x                             0x446540
#define CCharacterSelect__Quit_x                                   0x445100

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5A0420
#define EQ_Item__CreateItemTagString_x                             0x85B790
#define EQ_Item__IsStackable_x                                     0x850BF0
#define EQ_Item__GetImageNum_x                                     0x853620
#define EQ_Item__CreateItemClient_x                                0x5A14D0
#define EQ_Item__GetItemValue_x                                    0x85A230
#define EQ_Item__ValueSellMerchant_x                               0x85D240
#define EQ_Item__IsKeyRingItem_x                                   0x8516A0
#define EQ_Item__CanGoInBag_x                                      0x5A05B0
#define EQ_Item__GetMaxItemCount_x                                 0x850AE0
#define EQ_Item__GetHeldItem_x                                     0x852480
#define EQ_Item__GetAugmentFitBySlot_x                             0x85D070

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DB640
#define EQ_LoadingS__Array_x                                       0xC17958

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5D0340
#define EQ_PC__GetAlternateAbilityId_x                             0x865700
#define EQ_PC__GetCombatAbility_x                                  0x865790
#define EQ_PC__GetCombatAbilityTimer_x                             0x860290
#define EQ_PC__GetItemRecastTimer_x                                0x5C9AD0
#define EQ_PC__HasLoreItem_x                                       0x5C3A70
#define EQ_PC__AlertInventoryChanged_x                             0x5C0420
#define EQ_PC__GetPcZoneClient_x                                   0x5EA8B0
#define EQ_PC__RemoveMyAffect_x                                    0x5C8F30
#define EQ_PC__GetKeyRingItems_x                                   0x8606B0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8733E0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x867670

// EQItemList 
#define EQItemList__EQItemList_x                                   0x527CB0
#define EQItemList__add_object_x                                   0x555140
#define EQItemList__add_item_x                                     0x527BF0
#define EQItemList__delete_item_x                                  0x5280A0
#define EQItemList__FreeItemList_x                                 0x527FA0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4BA680

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D6120
#define EQPlayer__dEQPlayer_x                                      0x5DE770
#define EQPlayer__DoAttack_x                                       0x5F0240
#define EQPlayer__EQPlayer_x                                       0x5E0E90
#define EQPlayer__SetNameSpriteState_x                             0x5DB630
#define EQPlayer__SetNameSpriteTint_x                              0x5D7540
#define PlayerBase__HasProperty_j_x                                0x93A570
#define EQPlayer__IsTargetable_x                                   0x93A810
#define EQPlayer__CanSee_x                                         0x93AD70
#define PlayerZoneClient__ChangeHeight_x                           0x5F0100
#define EQPlayer__CanSee1_x                                        0x93AE60
#define PlayerBase__GetVisibilityLineSegment_x                     0x93AB00

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5EAA60
#define PlayerZoneClient__IsValidTeleport_x                        0x5559E0
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D39B0


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E4EF0
#define EQPlayerManager__GetSpawnByName_x                          0x5E5350
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E4F20

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A69F0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A6A30
#define KeypressHandler__ClearCommandStateArray_x                  0x5A65E0
#define KeypressHandler__HandleKeyDown_x                           0x5A4F00
#define KeypressHandler__HandleKeyUp_x                             0x5A5220
#define KeypressHandler__SaveKeymapping_x                          0x5A66B0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x714940
#define MapViewMap__SaveEx_x                                       0x717C70

#define PlayerPointManager__GetAltCurrency_x                       0x8795F0

// StringTable 
#define StringTable__getString_x                                   0x873710

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CD8B0
#define PcZoneClient__RemovePetEffect_x                            0x5C9FA0
#define PcZoneClient__HasAlternateAbility_x                        0x5CA940
#define PcZoneClient__GetCurrentMod_x                              0x45D0D0
#define PcZoneClient__GetModCap_x                                  0x45A800
#define PcZoneClient__CanEquipItem_x                               0x5CAE60
#define PcZoneClient__GetItemByID_x                                0x5CF6B0
#define PcZoneClient__GetItemByItemClass_x                         0x5D0260
#define PcZoneClient__RemoveBuffEffect_x                           0x5C91E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x55CA30

//IconCache
#define IconCache__GetIcon_x                                       0x6B1710

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A85F0
#define CContainerMgr__CloseContainer_x                            0x6A8E10

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x77B990

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x599490

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5C10
#define EQ_Spell__SpellAffects_x                                   0x4F2E30
#define EQ_Spell__SpellAffectBase_x                           0x4F2EA0
#define CharacterZoneClient__CalcAffectChange_x                    0x44BBD0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AE10
#define CLootWnd__LootAll_x                                        0x70A2C0
#define CLootWnd__RequestLootSlot_x                                0x70AAD0
#define EQ_Spell__IsStackable_x                                    0x449700
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4497B0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43F170
#define EQ_Spell__IsSPAStacking_x                                  0x4F29A0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F3A10
#define EQ_Spell__IsNoRemove_x                                     0x435260
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F29C0

#define __IsResEffectSpell_x                                       0x449830

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x885270

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7C3770
#define CTargetWnd__WndNotification_x                              0x7C3260
#define CTargetWnd__RefreshTargetBuffs_x                           0x7C3950

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C88C0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4EE580
#define EqSoundManager__PlayScriptMp3_x                            0x4F0020

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A97F0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8F38C0
#define CSidlManager__FindAnimation1_x                             0x8E8BA0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E2F80
#define CAltAbilityData__GetMercMaxRank_x                          0x4E2F30
#define CAltAbilityData__GetMaxRank_x                              0x4D7720

//CTargetRing
#define CTargetRing__Cast_x                                        0x596D40

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459710
#define CharacterBase__CreateItemGlobalIndex_x                     0x476620
#define CharacterBase__CreateItemIndex_x                           0x5212F0
#define CharacterBase__GetItemPossession_x                         0x4445D0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8890D0
#define CharacterBase__GetEffectId_x                               0x4596D0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x691390
#define CCastSpellWnd__IsBardSongPlaying_x                         0x690AF0

//messages
#define msg_spell_worn_off_x                                       0x4FD6C0
#define msg_new_text_x                                             0x506E20
#define msgTokenTextParam_x                                        0x503600

//SpellManager
#define SpellManager__vftable_x                                    0xAD3418
#define SpellManager__SpellManager_x                               0x47F260
#define Spellmanager__LoadTextSpells_x          0x60E1A0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x93E880

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x488C10
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43F0A0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449470
#define ItemGlobalIndex__IsValidIndex_x                            0x458FB0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x886F30
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x885E70

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x703120

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AD340
#define CCursorAttachment__Deactivate_x                            0x6AC880

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x905900
#define CEQSuiteTextureLoader__GetTexture_x                        0x905A80

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                                0x605F30

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                                0x48D4A0

//IString
#define IString__Append_x                                           0x47FE90
