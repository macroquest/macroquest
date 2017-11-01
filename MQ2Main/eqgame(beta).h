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
#define __ExpectedVersionDate                                     "Nov  1 2017"
#define __ExpectedVersionTime                                     "04:17:50"
#define __ActualVersionDate_x                                      0xAED360
#define __ActualVersionTime_x                                      0xAED36C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AB110
#define __MemChecker1_x                                            0x8AA7F0
#define __MemChecker2_x                                            0x641510
#define __MemChecker3_x                                            0x641460
#define __MemChecker4_x                                            0x7FC280
#define __EncryptPad0_x                                            0xC4B6A0
#define __EncryptPad1_x                                            0xD278E8
#define __EncryptPad2_x                                            0xC75268
#define __EncryptPad3_x                                            0xC74E68
#define __EncryptPad4_x                                            0xD15EE8
#define __EncryptPad5_x                                            0x10D1210
#define __AC1_x                                                    0x7BB345
#define __AC2_x                                                    0x563D47
#define __AC3_x                                                    0x561EC0
#define __AC4_x                                                    0x5740E1
#define __AC5_x                                                    0x587E7B
#define __AC6_x                                                    0x58BA2E
#define __AC7_x                                                    0x58247C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA4BA0

// Direct Input
#define DI8__Main_x                                                0x10D11E8
#define DI8__Keyboard_x                                            0x10D11EC
#define DI8__Mouse_x                                               0x10D11F0
#define DI8__Mouse_Copy_x                                          0xF3F224
#define DI8__Mouse_Check_x                                         0xFC8ED4
#define __AutoSkillArray_x                                         0xF40138
#define __Attack_x                                                 0xFC382B
#define __Autofire_x                                               0xFC382C
#define __BindList_x                                               0xC26058
#define g_eqCommandStates_x                                        0xF2DF70
#define __Clicks_x                                                 0xF3F2E0
#define __CommandList_x                                            0xC28770
#define __CurrentMapLabel_x                                        0x10D71E0
#define __CurrentSocial_x                                          0xBF55D0
#define __DoAbilityList_x                                          0xF759F0
#define __do_loot_x                                                0x532950
#define __DrawHandler_x                                            0x1740F4C
#define __GroupCount_x                                             0xF2F87A

#define __Guilds_x                                                 0xF35490
#define __gWorld_x                                                 0xF31D34
#define __HotkeyPage_x                                             0xFBC3F0
#define __HWnd_x                                                   0xFC8FF0
#define __InChatMode_x                                             0xF3F20C
#define __LastTell_x                                               0xF410EC
#define __LMouseHeldTime_x                                         0xF3F34C
#define __Mouse_x                                                  0x10D11F4
#define __MouseLook_x                                              0xF3F2A6
#define __MouseEventTime_x                                         0xFC40B4
#define __gpbCommandEvent_x                                        0xF31DFC
#define __NetStatusToggle_x                                        0xF3F2A9
#define __PCNames_x                                                0xF406F4
#define __RangeAttackReady_x                                       0xF4041C
#define __RMouseHeldTime_x                                         0xF3F348
#define __RunWalkState_x                                           0xF3F210
#define __ScreenMode_x                                             0xE7DB50
#define __ScreenX_x                                                0xF3F1C4
#define __ScreenY_x                                                0xF3F1C0
#define __ScreenXMax_x                                             0xF3F1C8
#define __ScreenYMax_x                                             0xF3F1CC
#define __ServerHost_x                                             0xF2F7C4
#define __ServerName_x                                             0xF759B0
#define __ShiftKeyDown_x                                           0xF3F8A0
#define __ShowNames_x                                              0xF405D4
#define __Socials_x                                                0xF75AB0
#define __SubscriptionType_x                                       0x1107A54
#define __TargetAggroHolder_x                                      0x10D942C
#define __ZoneType_x                                               0xF3F6A4
#define __GroupAggro_x                                             0x10D946C
#define __LoginName_x                                              0xFC7ACC
#define __Inviter_x                                                0xFC37A8
#define __AttackOnAssist_x                                         0xF40590
#define __UseTellWindows_x                                         0xF4088C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF31E20
#define instEQZoneInfo_x                                           0xF3F49C
#define instKeypressHandler_x                                      0xFC4098
#define pinstActiveBanker_x                                        0xF31DD8
#define pinstActiveCorpse_x                                        0xF31DDC
#define pinstActiveGMaster_x                                       0xF31DE0
#define pinstActiveMerchant_x                                      0xF31DD4
#define pinstAggroInfo_x                                           0xD3B1A8
#define pinstAltAdvManager_x                                       0xE7ECB8
#define pinstAuraMgr_x                                             0xD4B9C0
#define pinstBandageTarget_x                                       0xF31DC0
#define pinstCamActor_x                                            0xE7E588
#define pinstCDBStr_x                                              0xE7DAE4
#define pinstCDisplay_x                                            0xF31DE8
#define pinstCEverQuest_x                                          0x10D1368
#define pinstEverQuestInfo_x                                       0xF3F1B8
#define pinstCharData_x                                            0xF31DA4
#define pinstCharSpawn_x                                           0xF31DCC
#define pinstControlledMissile_x                                   0xF31DA0
#define pinstControlledPlayer_x                                    0xF31DCC
#define pinstCSidlManager_x                                        0x173FEB8
#define pinstCXWndManager_x                                        0x173FEB0
#define instDynamicZone_x                                          0xF3F058
#define pinstDZMember_x                                            0xF3F168
#define pinstDZTimerInfo_x                                         0xF3F16C
#define pinstEQItemList_x                                          0xF2E248
#define pinstEQObjectList_x                                        0xF2F274
#define instEQMisc_x                                               0xC0E498
#define pinstEQSoundManager_x                                      0xE7F288
#define instExpeditionLeader_x                                     0xF3F0A2
#define instExpeditionName_x                                       0xF3F0E2
#define pinstGroup_x                                               0xF2F876
#define pinstImeManager_x                                          0x173FEBC
#define pinstLocalPlayer_x                                         0xF31DB8
#define pinstMercenaryData_x                                       0xFC4718
#define pinstMercenaryStats_x                                      0x10D9578
#define pinstMercAltAbilities_x                                    0xE7F040
#define pinstModelPlayer_x                                         0xF31DE4
#define pinstPCData_x                                              0xF31DA4
#define pinstSkillMgr_x                                            0xFC5788
#define pinstSpawnManager_x                                        0xFC4F68
#define pinstSpellManager_x                                        0xFC58D0
#define pinstSpellSets_x                                           0xFBC454
#define pinstStringTable_x                                         0xF31D4C
#define pinstSwitchManager_x                                       0xF2F408
#define pinstTarget_x                                              0xF31DD0
#define pinstTargetObject_x                                        0xF31DA8
#define pinstTargetSwitch_x                                        0xF31DAC
#define pinstTaskMember_x                                          0xE7DA30
#define pinstTrackTarget_x                                         0xF31DC4
#define pinstTradeTarget_x                                         0xF31DB4
#define instTributeActive_x                                        0xC0E4BD
#define pinstViewActor_x                                           0xE7E584
#define pinstWorldData_x                                           0xF31D88
#define pinstZoneAddr_x                                            0xF3F73C
#define pinstPlayerPath_x                                          0xFC4FC8
#define pinstTargetIndicator_x                                     0xFC5A68
#define pinstCTargetManager_x                                      0xFC5AC8
#define EQObject_Top_x                                             0xF31D98
#define pinstRealEstateItems_x                                     0xFC55F4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE7E4A0
#define pinstCAchievementsWnd_x                                    0xE7E4FC
#define pinstCTextOverlay_x                                        0xD3B750
#define pinstCAudioTriggersWindow_x                                0xD3B538
#define pinstCCharacterSelect_x                                    0xE7E40C
#define pinstCFacePick_x                                           0xE7E1BC
#define pinstCFindItemWnd_x                                        0xE7E49C
#define pinstCNoteWnd_x                                            0xE7E3C4
#define pinstCBookWnd_x                                            0xE7E3CC
#define pinstCPetInfoWnd_x                                         0xE7E3D0
#define pinstCTrainWnd_x                                           0xE7E3D4
#define pinstCSkillsWnd_x                                          0xE7E3D8
#define pinstCSkillsSelectWnd_x                                    0xE7E3DC
#define pinstCCombatSkillsSelectWnd_x                              0xE7E3E0
#define pinstCFriendsWnd_x                                         0xE7E3E4
#define pinstCAuraWnd_x                                            0xE7E3E8
#define pinstCRespawnWnd_x                                         0xE7E3EC
#define pinstCBandolierWnd_x                                       0xE7E3F0
#define pinstCPotionBeltWnd_x                                      0xE7E3F4
#define pinstCAAWnd_x                                              0xE7E3F8
#define pinstCAlarmWnd_x                                           0xE7E404
#define pinstCGroupSearchFiltersWnd_x                              0xE7E3FC
#define pinstCLoadskinWnd_x                                        0xE7E400
#define pinstCLargeDialogWnd_x                                     0x10D84D8
#define pinstCMusicPlayerWnd_x                                     0xE7E408
#define pinstCMailWnd_x                                            0xE7E410
#define pinstCMailCompositionWnd_x                                 0xE7E414
#define pinstCMailAddressBookWnd_x                                 0xE7E418
#define pinstCRaidWnd_x                                            0xE7E420
#define pinstCRaidOptionsWnd_x                                     0xE7E424
#define pinstCBreathWnd_x                                          0xE7E428
#define pinstCMapViewWnd_x                                         0xE7E42C
#define pinstCMapToolbarWnd_x                                      0xE7E430
#define pinstCEditLabelWnd_x                                       0xE7E434
#define pinstCTargetWnd_x                                          0xE7E438
#define pinstCColorPickerWnd_x                                     0xE7E43C
#define pinstCPlayerWnd_x                                          0xE7E440
#define pinstCOptionsWnd_x                                         0xE7E444
#define pinstCBuffWindowNORMAL_x                                   0xE7E448
#define pinstCBuffWindowSHORT_x                                    0xE7E44C
#define pinstCharacterCreation_x                                   0xE7E450
#define pinstCCursorAttachment_x                                   0xE7E454
#define pinstCCastingWnd_x                                         0xE7E458
#define pinstCCastSpellWnd_x                                       0xE7E45C
#define pinstCSpellBookWnd_x                                       0xE7E460
#define pinstCInventoryWnd_x                                       0xE7E464
#define pinstCBankWnd_x                                            0xE7E46C
#define pinstCQuantityWnd_x                                        0xE7E470
#define pinstCLootWnd_x                                            0xE7E474
#define pinstCActionsWnd_x                                         0xE7E478
#define pinstCCombatAbilityWnd_x                                   0xE7E480
#define pinstCMerchantWnd_x                                        0xE7E484
#define pinstCTradeWnd_x                                           0xE7E48C
#define pinstCSelectorWnd_x                                        0xE7E490
#define pinstCBazaarWnd_x                                          0xE7E494
#define pinstCBazaarSearchWnd_x                                    0xE7E498
#define pinstCGiveWnd_x                                            0xE7E4B8
#define pinstCTrackingWnd_x                                        0xE7E4C0
#define pinstCInspectWnd_x                                         0xE7E4C4
#define pinstCSocialEditWnd_x                                      0xE7E4C8
#define pinstCFeedbackWnd_x                                        0xE7E4CC
#define pinstCBugReportWnd_x                                       0xE7E4D0
#define pinstCVideoModesWnd_x                                      0xE7E4D4
#define pinstCTextEntryWnd_x                                       0xE7E4DC
#define pinstCFileSelectionWnd_x                                   0xE7E4E0
#define pinstCCompassWnd_x                                         0xE7E4E4
#define pinstCPlayerNotesWnd_x                                     0xE7E4E8
#define pinstCGemsGameWnd_x                                        0xE7E4EC
#define pinstCTimeLeftWnd_x                                        0xE7E508
#define pinstCPetitionQWnd_x                                       0xE7E50C
#define pinstCStoryWnd_x                                           0xE7E510
#define pinstCJournalTextWnd_x                                     0xE7E514
#define pinstCJournalCatWnd_x                                      0xE7E518
#define pinstCBodyTintWnd_x                                        0xE7E51C
#define pinstCServerListWnd_x                                      0xE7E520
#define pinstCAvaZoneWnd_x                                         0xE7E52C
#define pinstCBlockedBuffWnd_x                                     0xE7E530
#define pinstCBlockedPetBuffWnd_x                                  0xE7E534
#define pinstCInvSlotMgr_x                                         0xE7E57C
#define pinstCContainerMgr_x                                       0xE7E580
#define pinstCAdventureLeaderboardWnd_x                            0x10D1D18
#define pinstCAdventureRequestWnd_x                                0x10D1D90
#define pinstCAltStorageWnd_x                                      0x10D2070
#define pinstCAdventureStatsWnd_x                                  0x10D1E08
#define pinstCBarterMerchantWnd_x                                  0x10D2DB8
#define pinstCBarterSearchWnd_x                                    0x10D2E30
#define pinstCBarterWnd_x                                          0x10D2EA8
#define pinstCChatWindowManager_x                                  0x10D36B8
#define pinstCDynamicZoneWnd_x                                     0x10D3BE8
#define pinstCEQMainWnd_x                                          0x10D3DB0
#define pinstCFellowshipWnd_x                                      0x10D3B7C
#define pinstCFindLocationWnd_x                                    0x10D4080
#define pinstCGroupSearchWnd_x                                     0x10D4350
#define pinstCGroupWnd_x                                           0x10D43C8
#define pinstCGuildBankWnd_x                                       0x10D4440
#define pinstCGuildMgmtWnd_x                                       0x10D6530
#define pinstCHotButtonWnd_x                                       0x10D662C
#define pinstCHotButtonWnd1_x                                      0x10D662C
#define pinstCHotButtonWnd2_x                                      0x10D6630
#define pinstCHotButtonWnd3_x                                      0x10D6634
#define pinstCHotButtonWnd4_x                                      0x10D6658
#define pinstCItemDisplayManager_x                                 0x10D6AB0
#define pinstCItemExpTransferWnd_x                                 0x10D6BAC
#define pinstCLFGuildWnd_x                                         0x10D6E88
#define pinstCMIZoneSelectWnd_x                                    0x10D7468
#define pinstCConfirmationDialog_x                                 0x10D7B70
#define pinstCPopupWndManager_x                                    0x10D7B70
#define pinstCProgressionSelectionWnd_x                            0x10D7C60
#define pinstCPvPStatsWnd_x                                        0x10D7D50
#define pinstCTaskWnd_x                                            0x10D9858
#define pinstCTaskSomething_x                                      0xD4C5D8
#define pinstCTaskTemplateSelectWnd_x                              0x10D97E0
#define pinstCTipWndOFDAY_x                                        0x10D99C0
#define pinstCTipWndCONTEXT_x                                      0x10D99C4
#define pinstCTitleWnd_x                                           0x10D9A40
#define pinstCContextMenuManager_x                                 0x173FD40
#define pinstCVoiceMacroWnd_x                                      0xFC5EA0
#define pinstCHtmlWnd_x                                            0xFC5F90
#define pinstItemIconCache_x                                       0x10D3D58
#define pinstCTradeskillWnd_x                                      0x10D9B40
#define pinstCAdvancedLootWnd_x                                    0xE7E570
#define pinstRewardSelectionWnd_x                                  0x10D8278
#define pinstEQSuiteTextureLoader_x                                0xD297B0
#define pinstCPointMerchantWnd_x                                   0x10D7AF8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x54A460
#define __CastRay2_x                                               0x549D90
#define __HeadingDiff_x                                            0x93AAA0
#define __FixHeading_x                                             0x93AA30
#define __get_bearing_x                                            0x539AA0
#define __ConvertItemTags_x                                        0x537570
#define __ExecuteCmd_x                                             0x521E80
#define __EQGetTime_x                                              0x8AA190
#define __get_melee_range_x                                        0x528B50
#define __GetGaugeValueFromEQ_x                                    0x7B9F00
#define __GetLabelFromEQ_x                                         0x7BB2D0
#define __ToggleKeyRingItem_x                                      0x490130
#define __GetXTargetType_x                                         0x93C6A0
#define __LoadFrontEnd_x                                           0x640BE0
#define __NewUIINI_x                                               0x7B98D0
#define __ProcessGameEvents_x                                      0x584210
#define __ProcessMouseEvent_x                                      0x5839B0
#define CrashDetected_x                                            0x6425A0
#define wwsCrashReportCheckForUploader_x                           0x807EA0
#define __AppCrashWrapper_x                                        0xC74E5C
#define __pCrashHandler_x                                          0x10E6A20
#define __CrashHandler_x                                           0x807930
#define wwsCrashReportPlatformLaunchUploader_x                     0x80A0D0
#define DrawNetStatus_x                                            0x5BAC90
#define Util__FastTime_x                                           0x8A9E30
#define Expansion_HoT_x                                            0xF40580
#define __HelpPath_x                                               0xFC3E20
#define __STMLToText_x                                             0x8F0550
#define __GetAnimationCache_x                                      0x6B03C0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423400
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E070
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DE40

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8580
#define AltAdvManager__IsAbilityReady_x                            0x4D85F0
#define AltAdvManager__GetAAById_x                                 0x4D8AE0
#define AltAdvManager__CanTrainAbility_x                           0x4D9710
#define AltAdvManager__CanSeeAbility_x                             0x4D92D0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x469FA0
#define CharacterZoneClient__HasSkill_x                            0x466010
#define CharacterZoneClient__MakeMeVisible_x                       0x46BB10
#define CharacterZoneClient__IsStackBlocked_x                      0x44C160
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B680
#define CharacterZoneClient__GetItemCountWorn_x                    0x464570
#define CharacterZoneClient__GetItemCountInInventory_x             0x464650
#define CharacterZoneClient__GetCursorItemCount_x                  0x464730
#define CharacterZoneClient__FindAffectSlot_x                      0x451810
#define CharacterZoneClient__BardCastBard_x                        0x44ADF0
#define CharacterZoneClient__GetMaxEffects_x                       0x449980
#define CharacterZoneClient__GetEffect_x                           0x44B8B0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451670
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449CD0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x4501C0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6704F0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67E480

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5999F0
#define CButtonWnd__CButtonWnd_x                                   0x8E4820

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x699420
#define CChatManager__InitContextMenu_x                            0x69A570
#define CChatManager__FreeChatWindow_x                             0x698ED0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A2710
#define CChatManager__SetLockedActiveChatWindow_x                  0x6993F0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8EE8A0
#define CContextMenu__dCContextMenu_x                              0x8EEAB0
#define CContextMenu__AddMenuItem_x                                0x8EEFD0
#define CContextMenu__RemoveMenuItem_x                             0x8EEC30
#define CContextMenu__RemoveAllMenuItems_x                         0x8EEC50
#define CContextMenu__CheckMenuItem_x                              0x8EECD0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8DADB0
#define CContextMenuManager__RemoveMenu_x                          0x8DB160
#define CContextMenuManager__PopupMenu_x                           0x8DB5B0
#define CContextMenuManager__Flush_x                               0x8DAE20
#define CContextMenuManager__GetMenu_x                             0x419590

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x88E3A0
#define CChatService__GetFriendName_x                              0x88E3B0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6A01E0
#define CChatWindow__Clear_x                                       0x69FAC0
#define CChatWindow__WndNotification_x                             0x6A0AF0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8DEC30
#define CComboWnd__Draw_x                                          0x8DEE40
#define CComboWnd__GetCurChoice_x                                  0x8DE9E0
#define CComboWnd__GetListRect_x                                   0x8DF0E0
#define CComboWnd__GetTextRect_x                                   0x8DECA0
#define CComboWnd__InsertChoice_x                                  0x8DF240
#define CComboWnd__SetColors_x                                     0x8DE970
#define CComboWnd__SetChoice_x                                     0x8DE9A0
#define CComboWnd__GetItemCount_x                                  0x8DE9D0
#define CComboWnd__GetCurChoiceText_x                              0x8DEA20


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AA550
#define CContainerWnd__vftable_x                                   0xAF6C70

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C6300
#define CDisplay__GetClickedActor_x                                0x4BEBC0
#define CDisplay__GetUserDefinedColor_x                            0x4BD7A0
#define CDisplay__GetWorldFilePath_x                               0x4BCBF0
#define CDisplay__is3dON_x                                         0x4BC080
#define CDisplay__ReloadUI_x                                       0x4D02E0
#define CDisplay__WriteTextHD2_x                                   0x4C2690
#define CDisplay__TrueDistance_x                                   0x4BF7F0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x905C90

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8F2E00
#define CEditWnd__GetCharIndexPt_x                                 0x8F3F50
#define CEditWnd__GetDisplayString_x                               0x8F2FB0
#define CEditWnd__GetHorzOffset_x                                  0x8F32F0
#define CEditWnd__GetLineForPrintableChar_x                        0x8F3A20
#define CEditWnd__GetSelStartPt_x                                  0x8F4200
#define CEditWnd__GetSTMLSafeText_x                                0x8F3490
#define CEditWnd__PointFromPrintableChar_x                         0x8F3B10
#define CEditWnd__SelectableCharFromPoint_x                        0x8F3C90
#define CEditWnd__SetEditable_x                                    0x8F3460

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56A910
#define CEverQuest__ClickedPlayer_x                                0x564490
#define CEverQuest__CreateTargetIndicator_x                        0x565390
#define CEverQuest__DeleteTargetIndicator_x                        0x565410
#define CEverQuest__DoTellWindow_x                                 0x4767A0
#define CEverQuest__OutputTextToLog_x                              0x476400
#define CEverQuest__DropHeldItemOnGround_x                         0x57AE80
#define CEverQuest__dsp_chat_x                                     0x476AE0
#define CEverQuest__trimName_x                                     0x560DA0
#define CEverQuest__Emote_x                                        0x579190
#define CEverQuest__EnterZone_x                                    0x574270
#define CEverQuest__GetBodyTypeDesc_x                              0x55E7E0
#define CEverQuest__GetClassDesc_x                                 0x567D30
#define CEverQuest__GetClassThreeLetterCode_x                      0x568330
#define CEverQuest__GetDeityDesc_x                                 0x55F0C0
#define CEverQuest__GetLangDesc_x                                  0x55EB70
#define CEverQuest__GetRaceDesc_x                                  0x5684F0
#define CEverQuest__InterpretCmd_x                                 0x56C090
#define CEverQuest__LeftClickedOnPlayer_x                          0x5809E0
#define CEverQuest__LMouseUp_x                                     0x5829D0
#define CEverQuest__RightClickedOnPlayer_x                         0x5814F0
#define CEverQuest__RMouseUp_x                                     0x582430
#define CEverQuest__SetGameState_x                                 0x564D60
#define CEverQuest__UPCNotificationFlush_x                         0x55D170
#define CEverQuest__IssuePetCommand_x                              0x56CA70

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BB130
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BB190
#define CGaugeWnd__Draw_x                                          0x6BB5C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B620
#define CGuild__GetGuildName_x                                     0x43BAF0
#define CGuild__GetGuildIndex_x                                    0x43CD00

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D7630

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E4A70
#define CInvSlotMgr__MoveItem_x                                    0x6E5230
#define CInvSlotMgr__SelectSlot_x                                  0x6E4360

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E37C0
#define CInvSlot__SliderComplete_x                                 0x6E0F50
#define CInvSlot__GetItemBase_x                                    0x6E03E0
#define CInvSlot__UpdateItem_x                                     0x6E0960

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E6690
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E77D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7B5E20
#define CItemDisplayWnd__UpdateStrings_x                           0x6E88B0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F54A0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F59D0
#define CItemDisplayWnd__SetItem_x                                 0x6FB280

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7ECDE0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EEE30

// CLabel 
#define CLabel__Draw_x                                             0x702090

// CListWnd
#define CListWnd__CListWnd_x                                       0x8CA6B0
#define CListWnd__dCListWnd_x                                      0x8CB940
#define CListWnd__AddColumn_x                                      0x8CB8E0
#define CListWnd__AddColumn1_x                                     0x8CAF80
#define CListWnd__AddLine_x                                        0x8CA960
#define CListWnd__AddString_x                                      0x8CAB80
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C77C0
#define CListWnd__CalculateVSBRange_x                              0x8C9B70
#define CListWnd__ClearSel_x                                       0x8C6AE0
#define CListWnd__ClearAllSel_x                                    0x8C6A90
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8CA540
#define CListWnd__Compare_x                                        0x8C84A0
#define CListWnd__Draw_x                                           0x8C9770
#define CListWnd__DrawColumnSeparators_x                           0x8C9600
#define CListWnd__DrawHeader_x                                     0x8C6DA0
#define CListWnd__DrawItem_x                                       0x8C8B30
#define CListWnd__DrawLine_x                                       0x8C92A0
#define CListWnd__DrawSeparator_x                                  0x8C96A0
#define CListWnd__EnableLine_x                                     0x8C6CC0
#define CListWnd__EnsureVisible_x                                  0x8C7920
#define CListWnd__ExtendSel_x                                      0x8C8A40
#define CListWnd__GetColumnMinWidth_x                              0x8C63D0
#define CListWnd__GetColumnWidth_x                                 0x8C6300
#define CListWnd__GetCurSel_x                                      0x8C5AE0
#define CListWnd__GetItemAtPoint_x                                 0x8C7BC0
#define CListWnd__GetItemAtPoint1_x                                0x8C7C30
#define CListWnd__GetItemData_x                                    0x8C5E10
#define CListWnd__GetItemHeight_x                                  0x8C7420
#define CListWnd__GetItemIcon_x                                    0x8C6000
#define CListWnd__GetItemRect_x                                    0x8C7A00
#define CListWnd__GetItemText_x                                    0x8C5EB0
#define CListWnd__GetSelList_x                                     0x8CAE70
#define CListWnd__GetSeparatorRect_x                               0x8C83D0
#define CListWnd__InsertLine_x                                     0x8CAD60
#define CListWnd__RemoveLine_x                                     0x8CAD70
#define CListWnd__SetColors_x                                      0x8C5C30
#define CListWnd__SetColumnJustification_x                         0x8C6660
#define CListWnd__SetColumnWidth_x                                 0x8C6380
#define CListWnd__SetCurSel_x                                      0x8C5B20
#define CListWnd__SetItemColor_x                                   0x8CA230
#define CListWnd__SetItemData_x                                    0x8C6B40
#define CListWnd__SetItemText_x                                    0x8CA070
#define CListWnd__ShiftColumnSeparator_x                           0x8C9F00
#define CListWnd__Sort_x                                           0x8CBA40
#define CListWnd__ToggleSel_x                                      0x8C6A10

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71B0D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73E960
#define CMerchantWnd__RequestBuyItem_x                             0x747960
#define CMerchantWnd__RequestSellItem_x                            0x74A0E0
#define CMerchantWnd__SelectRecoverySlot_x                         0x73EEE0
#define CMerchantWnd__SelectBuySellSlot_x                          0x73BDA0
#define CMerchantWnd__ActualSelect_x                               0x73FD00

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x85C640
#define CPacketScrambler__hton_x                                   0x85C650

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E9820
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E9900
#define CSidlManager__CreateLabel_x                                0x7AAD70
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E7DB0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E9BE0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8E0C90
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8E0B80
#define CSidlScreenWnd__ConvertToRes_x                             0x905B70
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8E15A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8E2780
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8E2830
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8E1D10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8E0F50
#define CSidlScreenWnd__EnableIniStorage_x                         0x8E06B0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8E1140
#define CSidlScreenWnd__Init1_x                                    0x8E2470
#define CSidlScreenWnd__LoadIniInfo_x                              0x8E1660
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8E0870
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8E1F50
#define CSidlScreenWnd__StoreIniInfo_x                             0x8E0300
#define CSidlScreenWnd__StoreIniVis_x                              0x8E0660
#define CSidlScreenWnd__WndNotification_x                          0x8E21F0
#define CSidlScreenWnd__GetChildItem_x                             0x8E0780
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8D3F40
#define CSidlScreenWnd__m_layoutCopy_x                             0x173FE60

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x606470
#define CSkillMgr__GetSkillCap_x                                   0x606650
#define CSkillMgr__GetNameToken_x                                  0x606020

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x904E40
#define CSliderWnd__SetValue_x                                     0x905010
#define CSliderWnd__SetNumTicks_x                                  0x905790

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7B1070

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8FE830
#define CStmlWnd__CalculateHSBRange_x                              0x8F6DB0
#define CStmlWnd__CalculateVSBRange_x                              0x8F6D20
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F6F30
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F7730
#define CStmlWnd__ForceParseNow_x                                  0x8FF1B0
#define CStmlWnd__GetNextTagPiece_x                                0x8F7630
#define CStmlWnd__GetSTMLText_x                                    0x4849F0
#define CStmlWnd__GetVisibleText_x                                 0x8F8180
#define CStmlWnd__InitializeWindowVariables_x                      0x8FA730
#define CStmlWnd__MakeStmlColorTag_x                               0x8F6000
#define CStmlWnd__MakeWndNotificationTag_x                         0x8F6060
#define CStmlWnd__SetSTMLText_x                                    0x8FBF80
#define CStmlWnd__StripFirstSTMLLines_x                            0x8FE4D0
#define CStmlWnd__UpdateHistoryString_x                            0x8F90B0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x9026D0
#define CTabWnd__DrawCurrentPage_x                                 0x901F60
#define CTabWnd__DrawTab_x                                         0x901D20
#define CTabWnd__GetCurrentPage_x                                  0x902310
#define CTabWnd__GetPageInnerRect_x                                0x901A10
#define CTabWnd__GetTabInnerRect_x                                 0x901C10
#define CTabWnd__GetTabRect_x                                      0x901AE0
#define CTabWnd__InsertPage_x                                      0x9029C0
#define CTabWnd__SetPage_x                                         0x902340
#define CTabWnd__SetPageRect_x                                     0x902610
#define CTabWnd__UpdatePage_x                                      0x902960
#define CTabWnd__GetPageFromTabIndex_x                             0x901C70
#define CTabWnd__GetCurrentTabIndex_x                              0x9019A0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E7980
#define CPageWnd__SetTabText_x                                     0x90EE70

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x437200

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8DE5E0
#define CTextureFont__GetTextExtent_x                              0x8DE340

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63EE70

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x90B2B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8C3C40

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029F0
#define CXStr__CXStr1_x                                            0x909FB0
#define CXStr__CXStr3_x                                            0x8A70C0
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x8A7230
#define CXStr__operator_equal1_x                                   0x8A7280
#define CXStr__operator_plus_equal1_x                              0x8A8380

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8DC0D0
#define CXWnd__BringToTop_x                                        0x8D3150
#define CXWnd__Center_x                                            0x8D93C0
#define CXWnd__ClrFocus_x                                          0x8D2D10
#define CXWnd__Destroy_x                                           0x8D9EA0
#define CXWnd__DoAllDrawing_x                                      0x8D8FF0
#define CXWnd__DrawChildren_x                                      0x8D91A0
#define CXWnd__DrawColoredRect_x                                   0x8D3540
#define CXWnd__DrawTooltip_x                                       0x8D37E0
#define CXWnd__DrawTooltipAtPoint_x                                0x8D7F30
#define CXWnd__GetBorderFrame_x                                    0x8D3C00
#define CXWnd__GetChildWndAt_x                                     0x8D9D80
#define CXWnd__GetClientClipRect_x                                 0x8D3A00
#define CXWnd__GetScreenClipRect_x                                 0x8D8630
#define CXWnd__GetScreenRect_x                                     0x8D3DE0
#define CXWnd__GetTooltipRect_x                                    0x8D3670
#define CXWnd__GetWindowTextA_x                                    0x427340
#define CXWnd__IsActive_x                                          0x8CE780
#define CXWnd__IsDescendantOf_x                                    0x8D3B40
#define CXWnd__IsReallyVisible_x                                   0x8D6F70
#define CXWnd__IsType_x                                            0x8D9430
#define CScreenPieceTemplate__IsType_x                             0x9079F0
#define CXWnd__Move_x                                              0x8D6670
#define CXWnd__Move1_x                                             0x8D8C80
#define CXWnd__ProcessTransition_x                                 0x8D30F0
#define CXWnd__Refade_x                                            0x8D2EC0
#define CXWnd__Resize_x                                            0x8D3EB0
#define CXWnd__Right_x                                             0x8D8430
#define CXWnd__SetFocus_x                                          0x8D57B0
#define CXWnd__SetFont_x                                           0x8D2D60
#define CXWnd__SetKeyTooltip_x                                     0x8D4110
#define CXWnd__SetMouseOver_x                                      0x8D8960
#define CXWnd__StartFade_x                                         0x8D31A0
#define CXWnd__GetChildItem_x                                      0x8D88B0
#define CXWnd__SetParent_x                                         0x8D9D30

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8D0030
#define CXWndManager__DrawWindows_x                                0x8CFC70
#define CXWndManager__GetKeyboardFlags_x                           0x8CE2B0
#define CXWndManager__HandleKeyboardMsg_x                          0x8CEC10
#define CXWndManager__RemoveWnd_x                                  0x8CE910

// CDBStr
#define CDBStr__GetString_x                                        0x4BA8D0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4529D0
#define EQ_Character__Cur_HP_x                                     0x465BF0
#define EQ_Character__Cur_Mana_x                                   0x45B060
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B990
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443920
#define EQ_Character__GetFocusRangeModifier_x                      0x443A70
#define EQ_Character__GetHPRegen_x                                 0x469630
#define EQ_Character__GetEnduranceRegen_x                          0x465200
#define EQ_Character__GetManaRegen_x                               0x469BD0
#define EQ_Character__Max_Endurance_x                              0x5CC8A0
#define EQ_Character__Max_HP_x                                     0x45DBE0
#define EQ_Character__Max_Mana_x                                   0x5CC6D0
#define EQ_Character__doCombatAbility_x                            0x5C9DA0
#define EQ_Character__UseSkill_x                                   0x470BB0
#define EQ_Character__GetConLevel_x                                0x5BF330
#define EQ_Character__IsExpansionFlag_x                            0x426930
#define EQ_Character__TotalEffect_x                                0x44FB00
#define EQ_Character__GetPCSpellAffect_x                           0x44BD20
#define EQ_Character__SpellDuration_x                              0x449D20
#define EQ_Character__FindItemByRecord_x                           0x463260
#define EQ_Character__GetAdjustedSkill_x                           0x465DC0
#define EQ_Character__GetBaseSkill_x                               0x45DAC0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x87A5A0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D4E30

//PcClient
#define PcClient__PcClient_x                                       0x5C1170

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446DD0
#define CCharacterSelect__EnterWorld_x                             0x4465A0
#define CCharacterSelect__Quit_x                                   0x445160

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59F390
#define EQ_Item__CreateItemTagString_x                             0x85A800
#define EQ_Item__IsStackable_x                                     0x84FA30
#define EQ_Item__GetImageNum_x                                     0x8525A0
#define EQ_Item__CreateItemClient_x                                0x5A0440
#define EQ_Item__GetItemValue_x                                    0x859290
#define EQ_Item__ValueSellMerchant_x                               0x85C2D0
#define EQ_Item__IsKeyRingItem_x                                   0x850580
#define EQ_Item__CanGoInBag_x                                      0x59F520
#define EQ_Item__GetMaxItemCount_x                                 0x84F920
#define EQ_Item__GetHeldItem_x                                     0x8513B0
#define EQ_Item__GetAugmentFitBySlot_x                             0x85C0F0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DAB20
#define EQ_LoadingS__Array_x                                       0xC16958

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CEDC0
#define EQ_PC__GetAlternateAbilityId_x                             0x8647F0
#define EQ_PC__GetCombatAbility_x                                  0x864880
#define EQ_PC__GetCombatAbilityTimer_x                             0x85F2F0
#define EQ_PC__GetItemRecastTimer_x                                0x5C8550
#define EQ_PC__HasLoreItem_x                                       0x5C2930
#define EQ_PC__AlertInventoryChanged_x                             0x5BF2E0
#define EQ_PC__GetPcZoneClient_x                                   0x5E9440
#define EQ_PC__RemoveMyAffect_x                                    0x5C79B0
#define EQ_PC__GetKeyRingItems_x                                   0x85F710
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x872500
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x866790

// EQItemList 
#define EQItemList__EQItemList_x                                   0x526BD0
#define EQItemList__add_object_x                                   0x553F90
#define EQItemList__add_item_x                                     0x526B10
#define EQItemList__delete_item_x                                  0x526FC0
#define EQItemList__FreeItemList_x                                 0x526EC0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9BA0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D4BD0
#define EQPlayer__dEQPlayer_x                                      0x5DD2B0
#define EQPlayer__DoAttack_x                                       0x5EEDC0
#define EQPlayer__EQPlayer_x                                       0x5DF9D0
#define EQPlayer__SetNameSpriteState_x                             0x5DA0E0
#define EQPlayer__SetNameSpriteTint_x                              0x5D5FF0
#define PlayerBase__HasProperty_j_x                                0x938E50
#define EQPlayer__IsTargetable_x                                   0x9390F0
#define EQPlayer__CanSee_x                                         0x939650
#define PlayerZoneClient__ChangeHeight_x                           0x5EEC80
#define EQPlayer__CanSee1_x                                        0x939740
#define PlayerBase__GetVisibilityLineSegment_x                     0x9393E0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E95F0
#define PlayerZoneClient__IsValidTeleport_x                        0x554830
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2EE0


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E3A20
#define EQPlayerManager__GetSpawnByName_x                          0x5E3E80
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E3A50

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A59A0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A59E0
#define KeypressHandler__ClearCommandStateArray_x                  0x5A5590
#define KeypressHandler__HandleKeyDown_x                           0x5A3EB0
#define KeypressHandler__HandleKeyUp_x                             0x5A41D0
#define KeypressHandler__SaveKeymapping_x                          0x5A5660

// MapViewMap 
#define MapViewMap__Clear_x                                        0x713A60
#define MapViewMap__SaveEx_x                                       0x716D90

#define PlayerPointManager__GetAltCurrency_x                       0x878660

// StringTable 
#define StringTable__getString_x                                   0x872830

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CC330
#define PcZoneClient__RemovePetEffect_x                            0x5C8A20
#define PcZoneClient__HasAlternateAbility_x                        0x5C93C0
#define PcZoneClient__GetCurrentMod_x                              0x45D090
#define PcZoneClient__GetModCap_x                                  0x45A7C0
#define PcZoneClient__CanEquipItem_x                               0x5C98E0
#define PcZoneClient__GetItemByID_x                                0x5CE140
#define PcZoneClient__GetItemByItemClass_x                         0x5CECE0
#define PcZoneClient__RemoveBuffEffect_x                           0x5C7C60

//Doors
#define EQSwitch__UseSwitch_x                                      0x55B950

//IconCache
#define IconCache__GetIcon_x                                       0x6B09F0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A7820
#define CContainerMgr__CloseContainer_x                            0x6A8040

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x77AD70

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x598410

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5150
#define EQ_Spell__SpellAffects_x                                   0x4F2340
#define EQ_Spell__SpellAffectBase_x                           0x4F23B0
#define CharacterZoneClient__CalcAffectChange_x                    0x44BBB0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AE50
#define CLootWnd__LootAll_x                                        0x7092F0
#define CLootWnd__RequestLootSlot_x                                0x709B00
#define EQ_Spell__IsStackable_x                                    0x449740
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4497F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43F110
#define EQ_Spell__IsSPAStacking_x                                  0x4F1EB0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2F50
#define EQ_Spell__IsNoRemove_x                                     0x435230
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1ED0

#define __IsResEffectSpell_x                                       0x449870

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x884220

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7C29B0
#define CTargetWnd__WndNotification_x                              0x7C24A0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7C2B90

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C7AD0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED9C0
#define EqSoundManager__PlayScriptMp3_x                            0x4EF460

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8D40

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8F2430
#define CSidlManager__FindAnimation1_x                             0x8E77E0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E2420
#define CAltAbilityData__GetMercMaxRank_x                          0x4E23D0
#define CAltAbilityData__GetMaxRank_x                              0x4D6C30

//CTargetRing
#define CTargetRing__Cast_x                                        0x595CF0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459760
#define CharacterBase__CreateItemGlobalIndex_x                     0x475930
#define CharacterBase__CreateItemIndex_x                           0x5201A0
#define CharacterBase__GetItemPossession_x                         0x444610
#define CharacterBase__GetItemByGlobalIndex_x                      0x888080
#define CharacterBase__GetEffectId_x                               0x459720

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x690650
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68FDB0

//messages
#define msg_spell_worn_off_x                                       0x4FCC00
#define msg_new_text_x                                             0x5063B0
#define msgTokenTextParam_x                                        0x502B90

//SpellManager
#define SpellManager__vftable_x                                    0xAD2400
#define SpellManager__SpellManager_x                               0x47E590
#define Spellmanager__LoadTextSpells_x          0x60D350

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x93D1C0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x488040
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43F030
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4494C0
#define ItemGlobalIndex__IsValidIndex_x                            0x459020

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x885EE0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x884E20

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7022E0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AC630
#define CCursorAttachment__Deactivate_x                            0x6ABB70

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x904340
#define CEQSuiteTextureLoader__GetTexture_x                        0x9044C0

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                                0x604F60

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                                0x48C8E0

//IString
#define IString__Append_x                                           0x47F230
