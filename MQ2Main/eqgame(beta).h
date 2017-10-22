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
#define __ExpectedVersionDate                                     "Oct 22 2017"
#define __ExpectedVersionTime                                     "04:21:03"
#define __ActualVersionDate_x                                      0xAEB368
#define __ActualVersionTime_x                                      0xAEB374

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5ABFA0
#define __MemChecker1_x                                            0x8A90E0
#define __MemChecker2_x                                            0x641F00
#define __MemChecker3_x                                            0x641E50
#define __MemChecker4_x                                            0x7FA9C0
#define __EncryptPad0_x                                            0xC496A0
#define __EncryptPad1_x                                            0xD258E8
#define __EncryptPad2_x                                            0xC73268
#define __EncryptPad3_x                                            0xC72E68
#define __EncryptPad4_x                                            0xD13EE8
#define __EncryptPad5_x                                            0x10CF218
#define __AC1_x                                                    0x7B9BF5
#define __AC2_x                                                    0x564A07
#define __AC3_x                                                    0x562B80
#define __AC4_x                                                    0x574DA1
#define __AC5_x                                                    0x588BCB
#define __AC6_x                                                    0x58C77E
#define __AC7_x                                                    0x5831CC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FBCBA0

// Direct Input
#define DI8__Main_x                                                0x10CF1F0
#define DI8__Keyboard_x                                            0x10CF1F4
#define DI8__Mouse_x                                               0x10CF1F8
#define DI8__Mouse_Copy_x                                          0xF3D224
#define DI8__Mouse_Check_x                                         0xFC6EDC
#define __AutoSkillArray_x                                         0xF3E138
#define __Attack_x                                                 0xFC1833
#define __Autofire_x                                               0xFC1834
#define __BindList_x                                               0xC24058
#define g_eqCommandStates_x                                        0xF2BF70
#define __Clicks_x                                                 0xF3D2E0
#define __CommandList_x                                            0xC26770
#define __CurrentMapLabel_x                                        0x10D51E8
#define __CurrentSocial_x                                          0xBF35D0
#define __DoAbilityList_x                                          0xF739F8
#define __do_loot_x                                                0x5336A0
#define __DrawHandler_x                                            0x173EF54
#define __GroupCount_x                                             0xF2D87A

#define __Guilds_x                                                 0xF33490
#define __gWorld_x                                                 0xF2FD34
#define __HotkeyPage_x                                             0xFBA3F8
#define __HWnd_x                                                   0xFC6FF8
#define __InChatMode_x                                             0xF3D20C
#define __LastTell_x                                               0xF3F0F4
#define __LMouseHeldTime_x                                         0xF3D34C
#define __Mouse_x                                                  0x10CF1FC
#define __MouseLook_x                                              0xF3D2A6
#define __MouseEventTime_x                                         0xFC20BC
#define __gpbCommandEvent_x                                        0xF2FDFC
#define __NetStatusToggle_x                                        0xF3D2A9
#define __PCNames_x                                                0xF3E6FC
#define __RangeAttackReady_x                                       0xF3E41C
#define __RMouseHeldTime_x                                         0xF3D348
#define __RunWalkState_x                                           0xF3D210
#define __ScreenMode_x                                             0xE7BB50
#define __ScreenX_x                                                0xF3D1C4
#define __ScreenY_x                                                0xF3D1C0
#define __ScreenXMax_x                                             0xF3D1C8
#define __ScreenYMax_x                                             0xF3D1CC
#define __ServerHost_x                                             0xF2D7C4
#define __ServerName_x                                             0xF739B8
#define __ShiftKeyDown_x                                           0xF3D8A0
#define __ShowNames_x                                              0xF3E5DC
#define __Socials_x                                                0xF73AB8
#define __SubscriptionType_x                                       0x1105A5C
#define __TargetAggroHolder_x                                      0x10D7434
#define __ZoneType_x                                               0xF3D6A4
#define __GroupAggro_x                                             0x10D7474
#define __LoginName_x                                              0xFC5AD4
#define __Inviter_x                                                0xFC17B0
#define __AttackOnAssist_x                                         0xF3E598
#define __UseTellWindows_x                                         0xF3E894

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF2FE20
#define instEQZoneInfo_x                                           0xF3D49C
#define instKeypressHandler_x                                      0xFC20A0
#define pinstActiveBanker_x                                        0xF2FDD8
#define pinstActiveCorpse_x                                        0xF2FDDC
#define pinstActiveGMaster_x                                       0xF2FDE0
#define pinstActiveMerchant_x                                      0xF2FDD4
#define pinstAggroInfo_x                                           0xD391A8
#define pinstAltAdvManager_x                                       0xE7CCB8
#define pinstAuraMgr_x                                             0xD499C0
#define pinstBandageTarget_x                                       0xF2FDC0
#define pinstCamActor_x                                            0xE7C588
#define pinstCDBStr_x                                              0xE7BAE4
#define pinstCDisplay_x                                            0xF2FDE8
#define pinstCEverQuest_x                                          0x10CF370
#define pinstEverQuestInfo_x                                       0xF3D1B8
#define pinstCharData_x                                            0xF2FDA4
#define pinstCharSpawn_x                                           0xF2FDCC
#define pinstControlledMissile_x                                   0xF2FDA0
#define pinstControlledPlayer_x                                    0xF2FDCC
#define pinstCSidlManager_x                                        0x173DEC0
#define pinstCXWndManager_x                                        0x173DEB8
#define instDynamicZone_x                                          0xF3D058
#define pinstDZMember_x                                            0xF3D168
#define pinstDZTimerInfo_x                                         0xF3D16C
#define pinstEQItemList_x                                          0xF2C248
#define pinstEQObjectList_x                                        0xF2D274
#define instEQMisc_x                                               0xC0C498
#define pinstEQSoundManager_x                                      0xE7D288
#define instExpeditionLeader_x                                     0xF3D0A2
#define instExpeditionName_x                                       0xF3D0E2
#define pinstGroup_x                                               0xF2D876
#define pinstImeManager_x                                          0x173DEC4
#define pinstLocalPlayer_x                                         0xF2FDB8
#define pinstMercenaryData_x                                       0xFC2720
#define pinstMercenaryStats_x                                      0x10D7580
#define pinstMercAltAbilities_x                                    0xE7D040
#define pinstModelPlayer_x                                         0xF2FDE4
#define pinstPCData_x                                              0xF2FDA4
#define pinstSkillMgr_x                                            0xFC3790
#define pinstSpawnManager_x                                        0xFC2F70
#define pinstSpellManager_x                                        0xFC38D8
#define pinstSpellSets_x                                           0xFBA45C
#define pinstStringTable_x                                         0xF2FD4C
#define pinstSwitchManager_x                                       0xF2D408
#define pinstTarget_x                                              0xF2FDD0
#define pinstTargetObject_x                                        0xF2FDA8
#define pinstTargetSwitch_x                                        0xF2FDAC
#define pinstTaskMember_x                                          0xE7BA30
#define pinstTrackTarget_x                                         0xF2FDC4
#define pinstTradeTarget_x                                         0xF2FDB4
#define instTributeActive_x                                        0xC0C4BD
#define pinstViewActor_x                                           0xE7C584
#define pinstWorldData_x                                           0xF2FD88
#define pinstZoneAddr_x                                            0xF3D73C
#define pinstPlayerPath_x                                          0xFC2FD0
#define pinstTargetIndicator_x                                     0xFC3A70
#define pinstCTargetManager_x                                      0xFC3AD0
#define EQObject_Top_x                                             0xF2FD98
#define pinstRealEstateItems_x                                     0xFC35FC
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE7C4A0
#define pinstCAchievementsWnd_x                                    0xE7C4FC
#define pinstCTextOverlay_x                                        0xD39750
#define pinstCAudioTriggersWindow_x                                0xD39538
#define pinstCCharacterSelect_x                                    0xE7C40C
#define pinstCFacePick_x                                           0xE7C1BC
#define pinstCFindItemWnd_x                                        0xE7C49C
#define pinstCNoteWnd_x                                            0xE7C3C4
#define pinstCBookWnd_x                                            0xE7C3CC
#define pinstCPetInfoWnd_x                                         0xE7C3D0
#define pinstCTrainWnd_x                                           0xE7C3D4
#define pinstCSkillsWnd_x                                          0xE7C3D8
#define pinstCSkillsSelectWnd_x                                    0xE7C3DC
#define pinstCCombatSkillsSelectWnd_x                              0xE7C3E0
#define pinstCFriendsWnd_x                                         0xE7C3E4
#define pinstCAuraWnd_x                                            0xE7C3E8
#define pinstCRespawnWnd_x                                         0xE7C3EC
#define pinstCBandolierWnd_x                                       0xE7C3F0
#define pinstCPotionBeltWnd_x                                      0xE7C3F4
#define pinstCAAWnd_x                                              0xE7C3F8
#define pinstCAlarmWnd_x                                           0xE7C404
#define pinstCGroupSearchFiltersWnd_x                              0xE7C3FC
#define pinstCLoadskinWnd_x                                        0xE7C400
#define pinstCLargeDialogWnd_x                                     0x10D64E0
#define pinstCMusicPlayerWnd_x                                     0xE7C408
#define pinstCMailWnd_x                                            0xE7C410
#define pinstCMailCompositionWnd_x                                 0xE7C414
#define pinstCMailAddressBookWnd_x                                 0xE7C418
#define pinstCRaidWnd_x                                            0xE7C420
#define pinstCRaidOptionsWnd_x                                     0xE7C424
#define pinstCBreathWnd_x                                          0xE7C428
#define pinstCMapViewWnd_x                                         0xE7C42C
#define pinstCMapToolbarWnd_x                                      0xE7C430
#define pinstCEditLabelWnd_x                                       0xE7C434
#define pinstCTargetWnd_x                                          0xE7C438
#define pinstCColorPickerWnd_x                                     0xE7C43C
#define pinstCPlayerWnd_x                                          0xE7C440
#define pinstCOptionsWnd_x                                         0xE7C444
#define pinstCBuffWindowNORMAL_x                                   0xE7C448
#define pinstCBuffWindowSHORT_x                                    0xE7C44C
#define pinstCharacterCreation_x                                   0xE7C450
#define pinstCCursorAttachment_x                                   0xE7C454
#define pinstCCastingWnd_x                                         0xE7C458
#define pinstCCastSpellWnd_x                                       0xE7C45C
#define pinstCSpellBookWnd_x                                       0xE7C460
#define pinstCInventoryWnd_x                                       0xE7C464
#define pinstCBankWnd_x                                            0xE7C46C
#define pinstCQuantityWnd_x                                        0xE7C470
#define pinstCLootWnd_x                                            0xE7C474
#define pinstCActionsWnd_x                                         0xE7C478
#define pinstCCombatAbilityWnd_x                                   0xE7C480
#define pinstCMerchantWnd_x                                        0xE7C484
#define pinstCTradeWnd_x                                           0xE7C48C
#define pinstCSelectorWnd_x                                        0xE7C490
#define pinstCBazaarWnd_x                                          0xE7C494
#define pinstCBazaarSearchWnd_x                                    0xE7C498
#define pinstCGiveWnd_x                                            0xE7C4B8
#define pinstCTrackingWnd_x                                        0xE7C4C0
#define pinstCInspectWnd_x                                         0xE7C4C4
#define pinstCSocialEditWnd_x                                      0xE7C4C8
#define pinstCFeedbackWnd_x                                        0xE7C4CC
#define pinstCBugReportWnd_x                                       0xE7C4D0
#define pinstCVideoModesWnd_x                                      0xE7C4D4
#define pinstCTextEntryWnd_x                                       0xE7C4DC
#define pinstCFileSelectionWnd_x                                   0xE7C4E0
#define pinstCCompassWnd_x                                         0xE7C4E4
#define pinstCPlayerNotesWnd_x                                     0xE7C4E8
#define pinstCGemsGameWnd_x                                        0xE7C4EC
#define pinstCTimeLeftWnd_x                                        0xE7C508
#define pinstCPetitionQWnd_x                                       0xE7C50C
#define pinstCStoryWnd_x                                           0xE7C510
#define pinstCJournalTextWnd_x                                     0xE7C514
#define pinstCJournalCatWnd_x                                      0xE7C518
#define pinstCBodyTintWnd_x                                        0xE7C51C
#define pinstCServerListWnd_x                                      0xE7C520
#define pinstCAvaZoneWnd_x                                         0xE7C52C
#define pinstCBlockedBuffWnd_x                                     0xE7C530
#define pinstCBlockedPetBuffWnd_x                                  0xE7C534
#define pinstCInvSlotMgr_x                                         0xE7C57C
#define pinstCContainerMgr_x                                       0xE7C580
#define pinstCAdventureLeaderboardWnd_x                            0x10CFD20
#define pinstCAdventureRequestWnd_x                                0x10CFD98
#define pinstCAltStorageWnd_x                                      0x10D0078
#define pinstCAdventureStatsWnd_x                                  0x10CFE10
#define pinstCBarterMerchantWnd_x                                  0x10D0DC0
#define pinstCBarterSearchWnd_x                                    0x10D0E38
#define pinstCBarterWnd_x                                          0x10D0EB0
#define pinstCChatWindowManager_x                                  0x10D16C0
#define pinstCDynamicZoneWnd_x                                     0x10D1BF0
#define pinstCEQMainWnd_x                                          0x10D1DB8
#define pinstCFellowshipWnd_x                                      0x10D1B84
#define pinstCFindLocationWnd_x                                    0x10D2088
#define pinstCGroupSearchWnd_x                                     0x10D2358
#define pinstCGroupWnd_x                                           0x10D23D0
#define pinstCGuildBankWnd_x                                       0x10D2448
#define pinstCGuildMgmtWnd_x                                       0x10D4538
#define pinstCHotButtonWnd_x                                       0x10D4634
#define pinstCHotButtonWnd1_x                                      0x10D4634
#define pinstCHotButtonWnd2_x                                      0x10D4638
#define pinstCHotButtonWnd3_x                                      0x10D463C
#define pinstCHotButtonWnd4_x                                      0x10D4660
#define pinstCItemDisplayManager_x                                 0x10D4AB8
#define pinstCItemExpTransferWnd_x                                 0x10D4BB4
#define pinstCLFGuildWnd_x                                         0x10D4E90
#define pinstCMIZoneSelectWnd_x                                    0x10D5470
#define pinstCConfirmationDialog_x                                 0x10D5B78
#define pinstCPopupWndManager_x                                    0x10D5B78
#define pinstCProgressionSelectionWnd_x                            0x10D5C68
#define pinstCPvPStatsWnd_x                                        0x10D5D58
#define pinstCTaskWnd_x                                            0x10D7860
#define pinstCTaskSomething_x                                      0xD4A5D8
#define pinstCTaskTemplateSelectWnd_x                              0x10D77E8
#define pinstCTipWndOFDAY_x                                        0x10D79C8
#define pinstCTipWndCONTEXT_x                                      0x10D79CC
#define pinstCTitleWnd_x                                           0x10D7A48
#define pinstCContextMenuManager_x                                 0x173DD48
#define pinstCVoiceMacroWnd_x                                      0xFC3EA8
#define pinstCHtmlWnd_x                                            0xFC3F98
#define pinstItemIconCache_x                                       0x10D1D60
#define pinstCTradeskillWnd_x                                      0x10D7B48
#define pinstCAdvancedLootWnd_x                                    0xE7C570
#define pinstRewardSelectionWnd_x                                  0x10D6280
#define pinstEQSuiteTextureLoader_x                                0xD277B0
#define pinstCPointMerchantWnd_x                                   0x10D5B00

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x54B1B0
#define __CastRay2_x                                               0x54AAE0
#define __HeadingDiff_x                                            0x939260
#define __FixHeading_x                                             0x9391F0
#define __get_bearing_x                                            0x53A7F0
#define __ConvertItemTags_x                                        0x5382C0
#define __ExecuteCmd_x                                             0x522B80
#define __EQGetTime_x                                              0x8A8A80
#define __get_melee_range_x                                        0x529840
#define __GetGaugeValueFromEQ_x                                    0x7B87B0
#define __GetLabelFromEQ_x                                         0x7B9B80
#define __ToggleKeyRingItem_x                                      0x490EB0
#define __GetXTargetType_x                                         0x93AE60
#define __LoadFrontEnd_x                                           0x6415D0
#define __NewUIINI_x                                               0x7B8180
#define __ProcessGameEvents_x                                      0x584F60
#define __ProcessMouseEvent_x                                      0x584700
#define CrashDetected_x                                            0x642F90
#define wwsCrashReportCheckForUploader_x                           0x806950
#define __AppCrashWrapper_x                                        0xC72E5C
#define __pCrashHandler_x                                          0x10E4A28
#define __CrashHandler_x                                           0x8063E0
#define wwsCrashReportPlatformLaunchUploader_x                     0x808B80
#define DrawNetStatus_x                                            0x5BBBA0
#define Util__FastTime_x                                           0x8A8720
#define Expansion_HoT_x                                            0xF3E588
#define __HelpPath_x                                               0xFC1E28
#define __STMLToText_x                                             0x8EF100
#define __GetAnimationCache_x                                      0x6B0FB0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4233D0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E070
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DE40

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D9350
#define AltAdvManager__IsAbilityReady_x                            0x4D93C0
#define AltAdvManager__GetAAById_x                                 0x4D98B0
#define AltAdvManager__CanTrainAbility_x                           0x4DA4E0
#define AltAdvManager__CanSeeAbility_x                             0x4DA0A0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AB40
#define CharacterZoneClient__HasSkill_x                            0x466410
#define CharacterZoneClient__MakeMeVisible_x                       0x46C6B0
#define CharacterZoneClient__IsStackBlocked_x                      0x44C000
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B4C0
#define CharacterZoneClient__GetItemCountWorn_x                    0x464970
#define CharacterZoneClient__GetItemCountInInventory_x             0x464A50
#define CharacterZoneClient__GetCursorItemCount_x                  0x464B30
#define CharacterZoneClient__FindAffectSlot_x                      0x451630
#define CharacterZoneClient__BardCastBard_x                        0x44AC40
#define CharacterZoneClient__GetMaxEffects_x                       0x4497D0
#define CharacterZoneClient__GetEffect_x                           0x44B6F0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451490
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449B20
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FFE0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x671050

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67F000

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x59A890
#define CButtonWnd__CButtonWnd_x                                   0x8E32A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x69A160
#define CChatManager__InitContextMenu_x                            0x69B2B0
#define CChatManager__FreeChatWindow_x                             0x699C10
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A3430
#define CChatManager__SetLockedActiveChatWindow_x                  0x69A130

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8ED450
#define CContextMenu__dCContextMenu_x                              0x8ED660
#define CContextMenu__AddMenuItem_x                                0x8EDB80
#define CContextMenu__RemoveMenuItem_x                             0x8ED7E0
#define CContextMenu__RemoveAllMenuItems_x                         0x8ED800
#define CContextMenu__CheckMenuItem_x                              0x8ED880

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D9810
#define CContextMenuManager__RemoveMenu_x                          0x8D9BA0
#define CContextMenuManager__PopupMenu_x                           0x8D9FF0
#define CContextMenuManager__Flush_x                               0x8D9880
#define CContextMenuManager__GetMenu_x                             0x4195E0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x88CBE0
#define CChatService__GetFriendName_x                              0x88CBF0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6A0F00
#define CChatWindow__Clear_x                                       0x6A07F0
#define CChatWindow__WndNotification_x                             0x6A1810

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8DD680
#define CComboWnd__Draw_x                                          0x8DD890
#define CComboWnd__GetCurChoice_x                                  0x8DD430
#define CComboWnd__GetListRect_x                                   0x8DDB30
#define CComboWnd__GetTextRect_x                                   0x8DD6F0
#define CComboWnd__InsertChoice_x                                  0x8DDC90
#define CComboWnd__SetColors_x                                     0x8DD3C0
#define CComboWnd__SetChoice_x                                     0x8DD3F0
#define CComboWnd__GetItemCount_x                                  0x8DD420
#define CComboWnd__GetCurChoiceText_x                              0x8DD470


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AB140
#define CContainerWnd__vftable_x                                   0xAF4C78

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C7040
#define CDisplay__GetClickedActor_x                                0x4BF900
#define CDisplay__GetUserDefinedColor_x                            0x4BE4E0
#define CDisplay__GetWorldFilePath_x                               0x4BD930
#define CDisplay__is3dON_x                                         0x4BCDC0
#define CDisplay__ReloadUI_x                                       0x4D1020
#define CDisplay__WriteTextHD2_x                                   0x4C33D0
#define CDisplay__TrueDistance_x                                   0x4C0530

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x904480

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8F19B0
#define CEditWnd__GetCharIndexPt_x                                 0x8F2B00
#define CEditWnd__GetDisplayString_x                               0x8F1B60
#define CEditWnd__GetHorzOffset_x                                  0x8F1EA0
#define CEditWnd__GetLineForPrintableChar_x                        0x8F25D0
#define CEditWnd__GetSelStartPt_x                                  0x8F2DB0
#define CEditWnd__GetSTMLSafeText_x                                0x8F2040
#define CEditWnd__PointFromPrintableChar_x                         0x8F26C0
#define CEditWnd__SelectableCharFromPoint_x                        0x8F2840
#define CEditWnd__SetEditable_x                                    0x8F2010

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56B5D0
#define CEverQuest__ClickedPlayer_x                                0x565150
#define CEverQuest__CreateTargetIndicator_x                        0x566050
#define CEverQuest__DeleteTargetIndicator_x                        0x5660D0
#define CEverQuest__DoTellWindow_x                                 0x477340
#define CEverQuest__OutputTextToLog_x                              0x476FA0
#define CEverQuest__DropHeldItemOnGround_x                         0x57BB40
#define CEverQuest__dsp_chat_x                                     0x477680
#define CEverQuest__trimName_x                                     0x561A60
#define CEverQuest__Emote_x                                        0x579E50
#define CEverQuest__EnterZone_x                                    0x574F30
#define CEverQuest__GetBodyTypeDesc_x                              0x55F4A0
#define CEverQuest__GetClassDesc_x                                 0x5689F0
#define CEverQuest__GetClassThreeLetterCode_x                      0x568FF0
#define CEverQuest__GetDeityDesc_x                                 0x55FD80
#define CEverQuest__GetLangDesc_x                                  0x55F830
#define CEverQuest__GetRaceDesc_x                                  0x5691B0
#define CEverQuest__InterpretCmd_x                                 0x56CD50
#define CEverQuest__LeftClickedOnPlayer_x                          0x5816A0
#define CEverQuest__LMouseUp_x                                     0x583720
#define CEverQuest__RightClickedOnPlayer_x                         0x5821B0
#define CEverQuest__RMouseUp_x                                     0x583180
#define CEverQuest__SetGameState_x                                 0x565A20
#define CEverQuest__UPCNotificationFlush_x                         0x55DE30
#define CEverQuest__IssuePetCommand_x                              0x56D730

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BBD80
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BBDE0
#define CGaugeWnd__Draw_x                                          0x6BC210

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B660
#define CGuild__GetGuildName_x                                     0x43BB30
#define CGuild__GetGuildIndex_x                                    0x43CD40

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D82F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E5750
#define CInvSlotMgr__MoveItem_x                                    0x6E5F10
#define CInvSlotMgr__SelectSlot_x                                  0x6E5040

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E4490
#define CInvSlot__SliderComplete_x                                 0x6E1C20
#define CInvSlot__GetItemBase_x                                    0x6E10B0
#define CInvSlot__UpdateItem_x                                     0x6E1630

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E7370
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E84A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7B4660
#define CItemDisplayWnd__UpdateStrings_x                           0x6E95A0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F6230
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F6760
#define CItemDisplayWnd__SetItem_x                                 0x6FC0E0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7EB6D0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EFBD0

// CLabel 
#define CLabel__Draw_x                                             0x702ED0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C9220
#define CListWnd__dCListWnd_x                                      0x8CA4D0
#define CListWnd__AddColumn_x                                      0x8CA470
#define CListWnd__AddColumn1_x                                     0x8C9B10
#define CListWnd__AddLine_x                                        0x8C94F0
#define CListWnd__AddString_x                                      0x8C9710
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C6340
#define CListWnd__CalculateVSBRange_x                              0x8C86F0
#define CListWnd__ClearSel_x                                       0x8C5650
#define CListWnd__ClearAllSel_x                                    0x8C5600
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C90B0
#define CListWnd__Compare_x                                        0x8C7020
#define CListWnd__Draw_x                                           0x8C82F0
#define CListWnd__DrawColumnSeparators_x                           0x8C8180
#define CListWnd__DrawHeader_x                                     0x8C5910
#define CListWnd__DrawItem_x                                       0x8C76B0
#define CListWnd__DrawLine_x                                       0x8C7E20
#define CListWnd__DrawSeparator_x                                  0x8C8220
#define CListWnd__EnableLine_x                                     0x8C5830
#define CListWnd__EnsureVisible_x                                  0x8C64A0
#define CListWnd__ExtendSel_x                                      0x8C75C0
#define CListWnd__GetColumnMinWidth_x                              0x8C4F40
#define CListWnd__GetColumnWidth_x                                 0x8C4E70
#define CListWnd__GetCurSel_x                                      0x8C4630
#define CListWnd__GetItemAtPoint_x                                 0x8C6730
#define CListWnd__GetItemAtPoint1_x                                0x8C67A0
#define CListWnd__GetItemData_x                                    0x8C4980
#define CListWnd__GetItemHeight_x                                  0x8C5F90
#define CListWnd__GetItemIcon_x                                    0x8C4B70
#define CListWnd__GetItemRect_x                                    0x8C6570
#define CListWnd__GetItemText_x                                    0x8C4A20
#define CListWnd__GetSelList_x                                     0x8C9A00
#define CListWnd__GetSeparatorRect_x                               0x8C6F40
#define CListWnd__InsertLine_x                                     0x8C98F0
#define CListWnd__RemoveLine_x                                     0x8C9900
#define CListWnd__SetColors_x                                      0x8C4780
#define CListWnd__SetColumnJustification_x                         0x8C51D0
#define CListWnd__SetColumnWidth_x                                 0x8C4EF0
#define CListWnd__SetCurSel_x                                      0x8C4670
#define CListWnd__SetItemColor_x                                   0x8C8DA0
#define CListWnd__SetItemData_x                                    0x8C56B0
#define CListWnd__SetItemText_x                                    0x8C8BE0
#define CListWnd__ShiftColumnSeparator_x                           0x8C8A70
#define CListWnd__Sort_x                                           0x8CA5D0
#define CListWnd__ToggleSel_x                                      0x8C5580

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71BEC0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73F270
#define CMerchantWnd__RequestBuyItem_x                             0x746E70
#define CMerchantWnd__RequestSellItem_x                            0x748440
#define CMerchantWnd__SelectRecoverySlot_x                         0x73F710
#define CMerchantWnd__SelectBuySellSlot_x                          0x73CB70
#define CMerchantWnd__ActualSelect_x                               0x73FE80

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x85AF50
#define CPacketScrambler__hton_x                                   0x85AF60

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E8250
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E8330
#define CSidlManager__CreateLabel_x                                0x7A96B0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E67E0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E8610

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8DF6E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8DF5E0
#define CSidlScreenWnd__ConvertToRes_x                             0x904360
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8E0000
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8E11D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8E1280
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8E0760
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8DF9B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8DF110
#define CSidlScreenWnd__GetSidlPiece_x                             0x8DFBA0
#define CSidlScreenWnd__Init1_x                                    0x8E0EB0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8E00C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8DF2D0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8E09A0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8DED60
#define CSidlScreenWnd__StoreIniVis_x                              0x8DF0C0
#define CSidlScreenWnd__WndNotification_x                          0x8E0C30
#define CSidlScreenWnd__GetChildItem_x                             0x8DF1E0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8D2A60
#define CSidlScreenWnd__m_layoutCopy_x                             0x173DE68

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x607090
#define CSkillMgr__GetSkillCap_x                                   0x607270
#define CSkillMgr__GetNameToken_x                                  0x606C40

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x903610
#define CSliderWnd__SetValue_x                                     0x9037E0
#define CSliderWnd__SetNumTicks_x                                  0x903F60

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7AF990

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8FD3F0
#define CStmlWnd__CalculateHSBRange_x                              0x8F5950
#define CStmlWnd__CalculateVSBRange_x                              0x8F58D0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F5AD0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F62D0
#define CStmlWnd__ForceParseNow_x                                  0x8FDDB0
#define CStmlWnd__GetNextTagPiece_x                                0x8F61D0
#define CStmlWnd__GetSTMLText_x                                    0x4854F0
#define CStmlWnd__GetVisibleText_x                                 0x8F6D20
#define CStmlWnd__InitializeWindowVariables_x                      0x8F92E0
#define CStmlWnd__MakeStmlColorTag_x                               0x8F4BB0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8F4C10
#define CStmlWnd__SetSTMLText_x                                    0x8FAB30
#define CStmlWnd__StripFirstSTMLLines_x                            0x8FD090
#define CStmlWnd__UpdateHistoryString_x                            0x8F7C60

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9012D0
#define CTabWnd__DrawCurrentPage_x                                 0x900B60
#define CTabWnd__DrawTab_x                                         0x900920
#define CTabWnd__GetCurrentPage_x                                  0x900F10
#define CTabWnd__GetPageInnerRect_x                                0x900610
#define CTabWnd__GetTabInnerRect_x                                 0x900810
#define CTabWnd__GetTabRect_x                                      0x9006E0
#define CTabWnd__InsertPage_x                                      0x9015C0
#define CTabWnd__SetPage_x                                         0x900F40
#define CTabWnd__SetPageRect_x                                     0x901210
#define CTabWnd__UpdatePage_x                                      0x901560
#define CTabWnd__GetPageFromTabIndex_x                             0x900870
#define CTabWnd__GetCurrentTabIndex_x                              0x9005A0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E8650
#define CPageWnd__SetTabText_x                                     0x90D6D0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x437260

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8DD030
#define CTextureFont__GetTextExtent_x                              0x8DCD90

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63F860

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x909B10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8C26D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029D0
#define CXStr__CXStr1_x                                            0x7F38E0
#define CXStr__CXStr3_x                                            0x8A59B0
#define CXStr__dCXStr_x                                            0x908800
#define CXStr__operator_equal_x                                    0x8A5B20
#define CXStr__operator_equal1_x                                   0x8A5B70
#define CXStr__operator_plus_equal1_x                              0x8A6C70

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8DAB10
#define CXWnd__BringToTop_x                                        0x8D1CA0
#define CXWnd__Center_x                                            0x8D7E10
#define CXWnd__ClrFocus_x                                          0x8D1870
#define CXWnd__Destroy_x                                           0x8D88F0
#define CXWnd__DoAllDrawing_x                                      0x8D7A60
#define CXWnd__DrawChildren_x                                      0x8D7C00
#define CXWnd__DrawColoredRect_x                                   0x8D2090
#define CXWnd__DrawTooltip_x                                       0x8D2330
#define CXWnd__DrawTooltipAtPoint_x                                0x8D69E0
#define CXWnd__GetBorderFrame_x                                    0x8D2740
#define CXWnd__GetChildWndAt_x                                     0x8D87D0
#define CXWnd__GetClientClipRect_x                                 0x8D2540
#define CXWnd__GetScreenClipRect_x                                 0x8D70E0
#define CXWnd__GetScreenRect_x                                     0x8D2910
#define CXWnd__GetTooltipRect_x                                    0x8D21C0
#define CXWnd__GetWindowTextA_x                                    0x4274F0
#define CXWnd__IsActive_x                                          0x8CD2C0
#define CXWnd__IsDescendantOf_x                                    0x8D2680
#define CXWnd__IsReallyVisible_x                                   0x8D5A20
#define CXWnd__IsType_x                                            0x8D7E80
#define CScreenPieceTemplate__IsType_x                             0x906240
#define CXWnd__Move_x                                              0x8D5160
#define CXWnd__Move1_x                                             0x8D7710
#define CXWnd__ProcessTransition_x                                 0x8D1C40
#define CXWnd__Refade_x                                            0x8D1A10
#define CXWnd__Resize_x                                            0x8D29D0
#define CXWnd__Right_x                                             0x8D6EE0
#define CXWnd__SetFocus_x                                          0x8D42B0
#define CXWnd__SetFont_x                                           0x8D18C0
#define CXWnd__SetKeyTooltip_x                                     0x8D2C30
#define CXWnd__SetMouseOver_x                                      0x8D7400
#define CXWnd__StartFade_x                                         0x8D1CF0
#define CXWnd__GetChildItem_x                                      0x8D7350
#define CXWnd__SetParent_x                                         0x8D8780

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8CEB70
#define CXWndManager__DrawWindows_x                                0x8CE7B0
#define CXWndManager__GetKeyboardFlags_x                           0x8CCDF0
#define CXWndManager__HandleKeyboardMsg_x                          0x8CD750
#define CXWndManager__RemoveWnd_x                                  0x8CD450

// CDBStr
#define CDBStr__GetString_x                                        0x4BB620

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4527F0
#define EQ_Character__Cur_HP_x                                     0x465FF0
#define EQ_Character__Cur_Mana_x                                   0x45AF40
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B7D0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4438F0
#define EQ_Character__GetFocusRangeModifier_x                      0x443950
#define EQ_Character__GetHPRegen_x                                 0x46A1D0
#define EQ_Character__GetEnduranceRegen_x                          0x465600
#define EQ_Character__GetManaRegen_x                               0x46A770
#define EQ_Character__Max_Endurance_x                              0x5CD550
#define EQ_Character__Max_HP_x                                     0x45DAC0
#define EQ_Character__Max_Mana_x                                   0x5CD380
#define EQ_Character__doCombatAbility_x                            0x5CAA50
#define EQ_Character__UseSkill_x                                   0x471740
#define EQ_Character__GetConLevel_x                                0x5C0210
#define EQ_Character__IsExpansionFlag_x                            0x426A10
#define EQ_Character__TotalEffect_x                                0x44F920
#define EQ_Character__GetPCSpellAffect_x                           0x44BBD0
#define EQ_Character__SpellDuration_x                              0x449B70
#define EQ_Character__FindItemByRecord_x                           0x463660
#define EQ_Character__GetAdjustedSkill_x                           0x4661C0
#define EQ_Character__GetBaseSkill_x                               0x45D9A0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x878E00

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D5AF0

//PcClient
#define PcClient__PcClient_x                                       0x5C2060

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446C60
#define CCharacterSelect__EnterWorld_x                             0x446430
#define CCharacterSelect__Quit_x                                   0x444FF0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5A0230
#define EQ_Item__CreateItemTagString_x                             0x859140
#define EQ_Item__IsStackable_x                                     0x84E420
#define EQ_Item__GetImageNum_x                                     0x850EE0
#define EQ_Item__CreateItemClient_x                                0x5A1250
#define EQ_Item__GetItemValue_x                                    0x857B10
#define EQ_Item__ValueSellMerchant_x                               0x85ABE0
#define EQ_Item__IsKeyRingItem_x                                   0x84EEE0
#define EQ_Item__CanGoInBag_x                                      0x5A03C0
#define EQ_Item__GetMaxItemCount_x                                 0x84E310
#define EQ_Item__GetHeldItem_x                                     0x84FD00
#define EQ_Item__GetAugmentFitBySlot_x                             0x85AA00

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DB8F0
#define EQ_LoadingS__Array_x                                       0xC14958

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CFA60
#define EQ_PC__GetAlternateAbilityId_x                             0x862EE0
#define EQ_PC__GetCombatAbility_x                                  0x862F70
#define EQ_PC__GetCombatAbilityTimer_x                             0x85DC00
#define EQ_PC__GetItemRecastTimer_x                                0x5C9200
#define EQ_PC__HasLoreItem_x                                       0x5C3820
#define EQ_PC__AlertInventoryChanged_x                             0x5C01C0
#define EQ_PC__GetPcZoneClient_x                                   0x5E9FB0
#define EQ_PC__RemoveMyAffect_x                                    0x5C8660
#define EQ_PC__GetKeyRingItems_x                                   0x85E020
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x870BC0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x864E50

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5278D0
#define EQItemList__add_object_x                                   0x554DA0
#define EQItemList__add_item_x                                     0x527810
#define EQItemList__delete_item_x                                  0x527CC0
#define EQItemList__FreeItemList_x                                 0x527BC0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4BA910

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D5890
#define EQPlayer__dEQPlayer_x                                      0x5DDED0
#define EQPlayer__DoAttack_x                                       0x5EF930
#define EQPlayer__EQPlayer_x                                       0x5E0600
#define EQPlayer__SetNameSpriteState_x                             0x5DAD90
#define EQPlayer__SetNameSpriteTint_x                              0x5D6CB0
#define PlayerBase__HasProperty_j_x                                0x937620
#define EQPlayer__IsTargetable_x                                   0x9378C0
#define EQPlayer__CanSee_x                                         0x937E20
#define PlayerZoneClient__ChangeHeight_x                           0x5EF7F0
#define EQPlayer__CanSee1_x                                        0x937F10
#define PlayerBase__GetVisibilityLineSegment_x                     0x937BB0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5EA160
#define PlayerZoneClient__IsValidTeleport_x                        0x555660
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D3C20


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E45F0
#define EQPlayerManager__GetSpawnByName_x                          0x5E4A50
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E4620

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A6810
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A6850
#define KeypressHandler__ClearCommandStateArray_x                  0x5A6400
#define KeypressHandler__HandleKeyDown_x                           0x5A4D20
#define KeypressHandler__HandleKeyUp_x                             0x5A5040
#define KeypressHandler__SaveKeymapping_x                          0x5A64D0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x714850
#define MapViewMap__SaveEx_x                                       0x717B80

#define PlayerPointManager__GetAltCurrency_x                       0x876E90

// StringTable 
#define StringTable__getString_x                                   0x870EF0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CCFE0
#define PcZoneClient__RemovePetEffect_x                            0x5C96D0
#define PcZoneClient__HasAlternateAbility_x                        0x5CA070
#define PcZoneClient__GetCurrentMod_x                              0x45CF70
#define PcZoneClient__GetModCap_x                                  0x45A6A0
#define PcZoneClient__CanEquipItem_x                               0x5CA590
#define PcZoneClient__GetItemByID_x                                0x5CEDE0
#define PcZoneClient__GetItemByItemClass_x                         0x5CF980
#define PcZoneClient__RemoveBuffEffect_x                           0x5C8910

//Doors
#define EQSwitch__UseSwitch_x                                      0x55C6B0

//IconCache
#define IconCache__GetIcon_x                                       0x6B15E0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A84C0
#define CContainerMgr__CloseContainer_x                            0x6A8CE0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7795F0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5992B0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5F40
#define EQ_Spell__SpellAffects_x                                   0x4F3160
#define EQ_Spell__SpellAffectBase_x                           0x4F31D0
#define CharacterZoneClient__CalcAffectChange_x                    0x44BA60
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44ACA0
#define CLootWnd__LootAll_x                                        0x70A100
#define CLootWnd__RequestLootSlot_x                                0x70A910
#define EQ_Spell__IsStackable_x                                    0x449590
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449640
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43F0F0
#define EQ_Spell__IsSPAStacking_x                                  0x4F2CD0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F3D40
#define EQ_Spell__IsNoRemove_x                                     0x435280
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F2CF0

#define __IsResEffectSpell_x                                       0x4496C0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x882A80

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7C1230
#define CTargetWnd__WndNotification_x                              0x7C0D20
#define CTargetWnd__RefreshTargetBuffs_x                           0x7C1410

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C6370

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4EE830
#define EqSoundManager__PlayScriptMp3_x                            0x4F02D0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A9950

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8F0FE0
#define CSidlManager__FindAnimation1_x                             0x8E6210

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E32A0
#define CAltAbilityData__GetMercMaxRank_x                          0x4E3250
#define CAltAbilityData__GetMaxRank_x                              0x4D7A00

//CTargetRing
#define CTargetRing__Cast_x                                        0x596B50

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459650
#define CharacterBase__CreateItemGlobalIndex_x                     0x4764C0
#define CharacterBase__CreateItemIndex_x                           0x520EE0
#define CharacterBase__GetItemPossession_x                         0x4444C0
#define CharacterBase__GetItemByGlobalIndex_x                      0x8868D0
#define CharacterBase__GetEffectId_x                               0x459610

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x691280
#define CCastSpellWnd__IsBardSongPlaying_x                         0x6909E0

//messages
#define msg_spell_worn_off_x                                       0x4FDA40
#define msg_new_text_x                                             0x507100
#define msgTokenTextParam_x                                        0x5038E0

//SpellManager
#define SpellManager__vftable_x                                    0xAD0418
#define SpellManager__SpellManager_x                               0x47F190
#define Spellmanager__LoadTextSpells_x          0x60DF70

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x93B980

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x488F20
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43F010
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449350
#define ItemGlobalIndex__IsValidIndex_x                            0x458E80

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x884740
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x883680

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x703120

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AD210
#define CCursorAttachment__Deactivate_x                            0x6AC750

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x902B10
#define CEQSuiteTextureLoader__GetTexture_x                        0x902C90

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                                0x605B30

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                                0x48D7C0
