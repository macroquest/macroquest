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
#define __ExpectedVersionDate                                     "Nov 21 2017"
#define __ExpectedVersionTime                                     "04:20:15"
#define __ActualVersionDate_x                                      0xAE3088
#define __ActualVersionTime_x                                      0xAE3094

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AA860
#define __MemChecker1_x                                            0x8A3070
#define __MemChecker2_x                                            0x640450
#define __MemChecker3_x                                            0x6403A0
#define __MemChecker4_x                                            0x7F4AA0
#define __EncryptPad0_x                                            0xC3CFE8
#define __EncryptPad1_x                                            0xD16BA0
#define __EncryptPad2_x                                            0xC65ED0
#define __EncryptPad3_x                                            0xC65AD0
#define __EncryptPad4_x                                            0xD051A0
#define __EncryptPad5_x                                            0x10C02C0
#define __AC1_x                                                    0x7B37E5
#define __AC2_x                                                    0x563A77
#define __AC3_x                                                    0x561BF0
#define __AC4_x                                                    0x573DC1
#define __AC5_x                                                    0x587B1B
#define __AC6_x                                                    0x58B6DE
#define __AC7_x                                                    0x58211C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA4920

// Direct Input
#define DI8__Main_x                                                0x10C0298
#define DI8__Keyboard_x                                            0x10C029C
#define DI8__Mouse_x                                               0x10C02A0
#define DI8__Mouse_Copy_x                                          0xF2E454
#define DI8__Mouse_Check_x                                         0xFB7F84
#define __AutoSkillArray_x                                         0xF2F368
#define __Attack_x                                                 0xFB2A5B
#define __Autofire_x                                               0xFB2A5C
#define __BindList_x                                               0xC19368
#define g_eqCommandStates_x                                        0xF1D1A0
#define __Clicks_x                                                 0xF2E510
#define __CommandList_x                                            0xC1BA80
#define __CurrentMapLabel_x                                        0x10C6290
#define __CurrentSocial_x                                          0xBE88E8
#define __DoAbilityList_x                                          0xF64C20
#define __do_loot_x                                                0x532950
#define __DrawHandler_x                                            0x172FF0C
#define __GroupCount_x                                             0xF1EAAA

#define __Guilds_x                                                 0xF246C0
#define __gWorld_x                                                 0xF20F64
#define __HotkeyPage_x                                             0xFAB620
#define __HWnd_x                                                   0xFB80A0
#define __InChatMode_x                                             0xF2E43C
#define __LastTell_x                                               0xF3031C
#define __LMouseHeldTime_x                                         0xF2E57C
#define __Mouse_x                                                  0x10C02A4
#define __MouseLook_x                                              0xF2E4D6
#define __MouseEventTime_x                                         0xFB31F4
#define __gpbCommandEvent_x                                        0xF2102C
#define __NetStatusToggle_x                                        0xF2E4D9
#define __PCNames_x                                                0xF2F924
#define __RangeAttackReady_x                                       0xF2F64C
#define __RMouseHeldTime_x                                         0xF2E578
#define __RunWalkState_x                                           0xF2E440
#define __ScreenMode_x                                             0xE6CD80
#define __ScreenX_x                                                0xF2E3F4
#define __ScreenY_x                                                0xF2E3F0
#define __ScreenXMax_x                                             0xF2E3F8
#define __ScreenYMax_x                                             0xF2E3FC
#define __ServerHost_x                                             0xF1E9F4
#define __ServerName_x                                             0xF64BE0
#define __ShiftKeyDown_x                                           0xF2EAD0
#define __ShowNames_x                                              0xF2F804
#define __Socials_x                                                0xF64CE0
#define __SubscriptionType_x                                       0x10F6A14
#define __TargetAggroHolder_x                                      0x10C83EC
#define __ZoneType_x                                               0xF2E8D4
#define __GroupAggro_x                                             0x10C842C
#define __LoginName_x                                              0xFB6B7C
#define __Inviter_x                                                0xFB29D8
#define __AttackOnAssist_x                                         0xF2F7C0
#define __UseTellWindows_x                                         0xF2FABC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF21050
#define instEQZoneInfo_x                                           0xF2E6CC
#define instKeypressHandler_x                                      0xFB31D8
#define pinstActiveBanker_x                                        0xF21008
#define pinstActiveCorpse_x                                        0xF2100C
#define pinstActiveGMaster_x                                       0xF21010
#define pinstActiveMerchant_x                                      0xF21004
#define pinstAggroInfo_x                                           0xD2A3EC
#define pinstAltAdvManager_x                                       0xE6DEE8
#define pinstAuraMgr_x                                             0xD3ABF0
#define pinstBandageTarget_x                                       0xF20FF0
#define pinstCamActor_x                                            0xE6D7B8
#define pinstCDBStr_x                                              0xE6CD14
#define pinstCDisplay_x                                            0xF21018
#define pinstCEverQuest_x                                          0x10C0418
#define pinstEverQuestInfo_x                                       0xF2E3E8
#define pinstCharData_x                                            0xF20FD4
#define pinstCharSpawn_x                                           0xF20FFC
#define pinstControlledMissile_x                                   0xF20FD0
#define pinstControlledPlayer_x                                    0xF20FFC
#define pinstCSidlManager_x                                        0x172EE78
#define pinstCXWndManager_x                                        0x172EE70
#define instDynamicZone_x                                          0xF2E288
#define pinstDZMember_x                                            0xF2E398
#define pinstDZTimerInfo_x                                         0xF2E39C
#define pinstEQItemList_x                                          0xF1D478
#define pinstEQObjectList_x                                        0xF1E4A4
#define instEQMisc_x                                               0xC017A8
#define pinstEQSoundManager_x                                      0xE6E4B8
#define instExpeditionLeader_x                                     0xF2E2D2
#define instExpeditionName_x                                       0xF2E312
#define pinstGroup_x                                               0xF1EAA6
#define pinstImeManager_x                                          0x172EE7C
#define pinstLocalPlayer_x                                         0xF20FE8
#define pinstMercenaryData_x                                       0xFB3840
#define pinstMercenaryStats_x                                      0x10C8538
#define pinstMercAltAbilities_x                                    0xE6E270
#define pinstModelPlayer_x                                         0xF21014
#define pinstPCData_x                                              0xF20FD4
#define pinstSkillMgr_x                                            0xFB4838
#define pinstSpawnManager_x                                        0xFB4090
#define pinstSpellManager_x                                        0xFB4980
#define pinstSpellSets_x                                           0xFAB684
#define pinstStringTable_x                                         0xF20F7C
#define pinstSwitchManager_x                                       0xF1E638
#define pinstTarget_x                                              0xF21000
#define pinstTargetObject_x                                        0xF20FD8
#define pinstTargetSwitch_x                                        0xF20FDC
#define pinstTaskMember_x                                          0xE6CC60
#define pinstTrackTarget_x                                         0xF20FF4
#define pinstTradeTarget_x                                         0xF20FE4
#define instTributeActive_x                                        0xC017CD
#define pinstViewActor_x                                           0xE6D7B4
#define pinstWorldData_x                                           0xF20FB8
#define pinstZoneAddr_x                                            0xF2E96C
#define pinstPlayerPath_x                                          0xFB40F0
#define pinstTargetIndicator_x                                     0xFB4B18
#define pinstCTargetManager_x                                      0xFB4B78
#define EQObject_Top_x                                             0xF20FC8
#define pinstRealEstateItems_x                                     0xFB46A4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE6D6D0
#define pinstCAchievementsWnd_x                                    0xE6D72C
#define pinstCTextOverlay_x                                        0xD2A980
#define pinstCAudioTriggersWindow_x                                0xD2A768
#define pinstCCharacterSelect_x                                    0xE6D63C
#define pinstCFacePick_x                                           0xE6D3EC
#define pinstCFindItemWnd_x                                        0xE6D6CC
#define pinstCNoteWnd_x                                            0xE6D5F4
#define pinstCBookWnd_x                                            0xE6D5FC
#define pinstCPetInfoWnd_x                                         0xE6D600
#define pinstCTrainWnd_x                                           0xE6D604
#define pinstCSkillsWnd_x                                          0xE6D608
#define pinstCSkillsSelectWnd_x                                    0xE6D60C
#define pinstCCombatSkillsSelectWnd_x                              0xE6D610
#define pinstCFriendsWnd_x                                         0xE6D614
#define pinstCAuraWnd_x                                            0xE6D618
#define pinstCRespawnWnd_x                                         0xE6D61C
#define pinstCBandolierWnd_x                                       0xE6D620
#define pinstCPotionBeltWnd_x                                      0xE6D624
#define pinstCAAWnd_x                                              0xE6D628
#define pinstCAlarmWnd_x                                           0xE6D634
#define pinstCGroupSearchFiltersWnd_x                              0xE6D62C
#define pinstCLoadskinWnd_x                                        0xE6D630
#define pinstCLargeDialogWnd_x                                     0x10C7498
#define pinstCMusicPlayerWnd_x                                     0xE6D638
#define pinstCMailWnd_x                                            0xE6D640
#define pinstCMailCompositionWnd_x                                 0xE6D644
#define pinstCMailAddressBookWnd_x                                 0xE6D648
#define pinstCRaidWnd_x                                            0xE6D650
#define pinstCRaidOptionsWnd_x                                     0xE6D654
#define pinstCBreathWnd_x                                          0xE6D658
#define pinstCMapViewWnd_x                                         0xE6D65C
#define pinstCMapToolbarWnd_x                                      0xE6D660
#define pinstCEditLabelWnd_x                                       0xE6D664
#define pinstCTargetWnd_x                                          0xE6D668
#define pinstCColorPickerWnd_x                                     0xE6D66C
#define pinstCPlayerWnd_x                                          0xE6D670
#define pinstCOptionsWnd_x                                         0xE6D674
#define pinstCBuffWindowNORMAL_x                                   0xE6D678
#define pinstCBuffWindowSHORT_x                                    0xE6D67C
#define pinstCharacterCreation_x                                   0xE6D680
#define pinstCCursorAttachment_x                                   0xE6D684
#define pinstCCastingWnd_x                                         0xE6D688
#define pinstCCastSpellWnd_x                                       0xE6D68C
#define pinstCSpellBookWnd_x                                       0xE6D690
#define pinstCInventoryWnd_x                                       0xE6D694
#define pinstCBankWnd_x                                            0xE6D69C
#define pinstCQuantityWnd_x                                        0xE6D6A0
#define pinstCLootWnd_x                                            0xE6D6A4
#define pinstCActionsWnd_x                                         0xE6D6A8
#define pinstCCombatAbilityWnd_x                                   0xE6D6B0
#define pinstCMerchantWnd_x                                        0xE6D6B4
#define pinstCTradeWnd_x                                           0xE6D6BC
#define pinstCSelectorWnd_x                                        0xE6D6C0
#define pinstCBazaarWnd_x                                          0xE6D6C4
#define pinstCBazaarSearchWnd_x                                    0xE6D6C8
#define pinstCGiveWnd_x                                            0xE6D6E8
#define pinstCTrackingWnd_x                                        0xE6D6F0
#define pinstCInspectWnd_x                                         0xE6D6F4
#define pinstCSocialEditWnd_x                                      0xE6D6F8
#define pinstCFeedbackWnd_x                                        0xE6D6FC
#define pinstCBugReportWnd_x                                       0xE6D700
#define pinstCVideoModesWnd_x                                      0xE6D704
#define pinstCTextEntryWnd_x                                       0xE6D70C
#define pinstCFileSelectionWnd_x                                   0xE6D710
#define pinstCCompassWnd_x                                         0xE6D714
#define pinstCPlayerNotesWnd_x                                     0xE6D718
#define pinstCGemsGameWnd_x                                        0xE6D71C
#define pinstCTimeLeftWnd_x                                        0xE6D738
#define pinstCPetitionQWnd_x                                       0xE6D73C
#define pinstCStoryWnd_x                                           0xE6D740
#define pinstCJournalTextWnd_x                                     0xE6D744
#define pinstCJournalCatWnd_x                                      0xE6D748
#define pinstCBodyTintWnd_x                                        0xE6D74C
#define pinstCServerListWnd_x                                      0xE6D750
#define pinstCAvaZoneWnd_x                                         0xE6D75C
#define pinstCBlockedBuffWnd_x                                     0xE6D760
#define pinstCBlockedPetBuffWnd_x                                  0xE6D764
#define pinstCInvSlotMgr_x                                         0xE6D7AC
#define pinstCContainerMgr_x                                       0xE6D7B0
#define pinstCAdventureLeaderboardWnd_x                            0x10C0DC8
#define pinstCAdventureRequestWnd_x                                0x10C0E40
#define pinstCAltStorageWnd_x                                      0x10C1120
#define pinstCAdventureStatsWnd_x                                  0x10C0EB8
#define pinstCBarterMerchantWnd_x                                  0x10C1E68
#define pinstCBarterSearchWnd_x                                    0x10C1EE0
#define pinstCBarterWnd_x                                          0x10C1F58
#define pinstCChatWindowManager_x                                  0x10C2768
#define pinstCDynamicZoneWnd_x                                     0x10C2C98
#define pinstCEQMainWnd_x                                          0x10C2E60
#define pinstCFellowshipWnd_x                                      0x10C2C2C
#define pinstCFindLocationWnd_x                                    0x10C3130
#define pinstCGroupSearchWnd_x                                     0x10C3400
#define pinstCGroupWnd_x                                           0x10C3478
#define pinstCGuildBankWnd_x                                       0x10C34F0
#define pinstCGuildMgmtWnd_x                                       0x10C55E0
#define pinstCHotButtonWnd_x                                       0x10C56DC
#define pinstCHotButtonWnd1_x                                      0x10C56DC
#define pinstCHotButtonWnd2_x                                      0x10C56E0
#define pinstCHotButtonWnd3_x                                      0x10C56E4
#define pinstCHotButtonWnd4_x                                      0x10C5708
#define pinstCItemDisplayManager_x                                 0x10C5B60
#define pinstCItemExpTransferWnd_x                                 0x10C5C5C
#define pinstCLFGuildWnd_x                                         0x10C5F38
#define pinstCMIZoneSelectWnd_x                                    0x10C6518
#define pinstCConfirmationDialog_x                                 0x10C6B30
#define pinstCPopupWndManager_x                                    0x10C6B30
#define pinstCProgressionSelectionWnd_x                            0x10C6C20
#define pinstCPvPStatsWnd_x                                        0x10C6D10
#define pinstCTaskWnd_x                                            0x10C8818
#define pinstCTaskSomething_x                                      0xD3B808
#define pinstCTaskTemplateSelectWnd_x                              0x10C87A0
#define pinstCTipWndOFDAY_x                                        0x10C8980
#define pinstCTipWndCONTEXT_x                                      0x10C8984
#define pinstCTitleWnd_x                                           0x10C8A00
#define pinstCContextMenuManager_x                                 0x172ED00
#define pinstCVoiceMacroWnd_x                                      0xFB4F50
#define pinstCHtmlWnd_x                                            0xFB5040
#define pinstItemIconCache_x                                       0x10C2E08
#define pinstCTradeskillWnd_x                                      0x10C8B00
#define pinstCAdvancedLootWnd_x                                    0xE6D7A0
#define pinstRewardSelectionWnd_x                                  0x10C7238
#define pinstEQSuiteTextureLoader_x                                0xD18A68

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x54A2E0
#define __CastRay2_x                                               0x549C10
#define __HeadingDiff_x                                            0x933210
#define __FixHeading_x                                             0x9331A0
#define __get_bearing_x                                            0x539AA0
#define __ConvertItemTags_x                                        0x537570
#define __ExecuteCmd_x                                             0x521EC0
#define __EQGetTime_x                                              0x8A2A10
#define __get_melee_range_x                                        0x528B60
#define __GetGaugeValueFromEQ_x                                    0x7B23A0
#define __GetLabelFromEQ_x                                         0x7B3770
#define __ToggleKeyRingItem_x                                      0x48FD30
#define __GetXTargetType_x                                         0x934E60
#define __LoadFrontEnd_x                                           0x63FB20
#define __NewUIINI_x                                               0x7B1D70
#define __ProcessGameEvents_x                                      0x583EB0
#define __ProcessMouseEvent_x                                      0x583650
#define CrashDetected_x                                            0x6414E0
#define wwsCrashReportCheckForUploader_x                           0x800730
#define __AppCrashWrapper_x                                        0xC65AC4
#define __pCrashHandler_x                                          0x10D59E0
#define __CrashHandler_x                                           0x8001C0
#define wwsCrashReportPlatformLaunchUploader_x                     0x802960
#define DrawNetStatus_x                                            0x5BA3D0
#define Util__FastTime_x                                           0x8A26B0
#define Expansion_HoT_x                                            0xF2F7B0
#define __HelpPath_x                                               0xFB2F60
#define __STMLToText_x                                             0x8E8F40
#define __GetAnimationCache_x                                      0x6AF180

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423540
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E1A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DF70

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8400
#define AltAdvManager__IsAbilityReady_x                            0x4D8470
#define AltAdvManager__GetAAById_x                                 0x4D8960
#define AltAdvManager__CanTrainAbility_x                           0x4D9590
#define AltAdvManager__CanSeeAbility_x                             0x4D9150

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46ADF0
#define CharacterZoneClient__HasSkill_x                            0x466D00
#define CharacterZoneClient__MakeMeVisible_x                       0x46C960
#define CharacterZoneClient__IsStackBlocked_x                      0x44BE60
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B380
#define CharacterZoneClient__GetItemCountWorn_x                    0x465260
#define CharacterZoneClient__GetItemCountInInventory_x             0x465340
#define CharacterZoneClient__GetCursorItemCount_x                  0x465420
#define CharacterZoneClient__FindAffectSlot_x                      0x451510
#define CharacterZoneClient__BardCastBard_x                        0x44AAF0
#define CharacterZoneClient__GetMaxEffects_x                       0x449680
#define CharacterZoneClient__GetEffect_x                           0x44B5B0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451370
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4499D0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FEC0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66F370

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67D040

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x599020
#define CButtonWnd__CButtonWnd_x                                   0x8DD180

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x698290
#define CChatManager__InitContextMenu_x                            0x6993E0
#define CChatManager__FreeChatWindow_x                             0x697D40
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A1580
#define CChatManager__SetLockedActiveChatWindow_x                  0x698260

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E7290
#define CContextMenu__dCContextMenu_x                              0x8E74A0
#define CContextMenu__AddMenuItem_x                                0x8E79C0
#define CContextMenu__RemoveMenuItem_x                             0x8E7620
#define CContextMenu__RemoveAllMenuItems_x                         0x8E7640
#define CContextMenu__CheckMenuItem_x                              0x8E76C0
#define CContextMenu__SetMenuItem_x                                0x8E7540

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D3730
#define CContextMenuManager__RemoveMenu_x                          0x8D3AC0
#define CContextMenuManager__PopupMenu_x                           0x8D3F10
#define CContextMenuManager__Flush_x                               0x8D37A0
#define CContextMenuManager__GetMenu_x                             0x419670

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x886B70
#define CChatService__GetFriendName_x                              0x886B80

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69F050
#define CChatWindow__Clear_x                                       0x69E930
#define CChatWindow__WndNotification_x                             0x69F960

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D7590
#define CComboWnd__Draw_x                                          0x8D77A0
#define CComboWnd__GetCurChoice_x                                  0x8D7340
#define CComboWnd__GetListRect_x                                   0x8D7A40
#define CComboWnd__GetTextRect_x                                   0x8D7600
#define CComboWnd__InsertChoice_x                                  0x8D7BA0
#define CComboWnd__SetColors_x                                     0x8D72D0
#define CComboWnd__SetChoice_x                                     0x8D7300
#define CComboWnd__GetItemCount_x                                  0x8D7330
#define CComboWnd__GetCurChoiceText_x                              0x8D7380


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A9300
#define CContainerWnd__vftable_x                                   0xAEC9A0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C61B0
#define CDisplay__GetClickedActor_x                                0x4BEA80
#define CDisplay__GetUserDefinedColor_x                            0x4BD660
#define CDisplay__GetWorldFilePath_x                               0x4BCAB0
#define CDisplay__is3dON_x                                         0x4BBF40
#define CDisplay__ReloadUI_x                                       0x4CFF70
#define CDisplay__WriteTextHD2_x                                   0x4C2540
#define CDisplay__TrueDistance_x                                   0x4BF6B0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FE230

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EB7F0
#define CEditWnd__GetCharIndexPt_x                                 0x8EC940
#define CEditWnd__GetDisplayString_x                               0x8EB9A0
#define CEditWnd__GetHorzOffset_x                                  0x8EBCE0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EC410
#define CEditWnd__GetSelStartPt_x                                  0x8ECBF0
#define CEditWnd__GetSTMLSafeText_x                                0x8EBE80
#define CEditWnd__PointFromPrintableChar_x                         0x8EC500
#define CEditWnd__SelectableCharFromPoint_x                        0x8EC680
#define CEditWnd__SetEditable_x                                    0x8EBE50

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56A5F0
#define CEverQuest__ClickedPlayer_x                                0x5641C0
#define CEverQuest__CreateTargetIndicator_x                        0x5650C0
#define CEverQuest__DeleteTargetIndicator_x                        0x565140
#define CEverQuest__DoTellWindow_x                                 0x476080
#define CEverQuest__OutputTextToLog_x                              0x475CE0
#define CEverQuest__DropHeldItemOnGround_x                         0x57AB60
#define CEverQuest__dsp_chat_x                                     0x4763C0
#define CEverQuest__trimName_x                                     0x560AD0
#define CEverQuest__Emote_x                                        0x578E70
#define CEverQuest__EnterZone_x                                    0x573F50
#define CEverQuest__GetBodyTypeDesc_x                              0x55E510
#define CEverQuest__GetClassDesc_x                                 0x567A00
#define CEverQuest__GetClassThreeLetterCode_x                      0x568000
#define CEverQuest__GetDeityDesc_x                                 0x55EDF0
#define CEverQuest__GetLangDesc_x                                  0x55E8A0
#define CEverQuest__GetRaceDesc_x                                  0x5681C0
#define CEverQuest__InterpretCmd_x                                 0x56BD70
#define CEverQuest__LeftClickedOnPlayer_x                          0x5806C0
#define CEverQuest__LMouseUp_x                                     0x582670
#define CEverQuest__RightClickedOnPlayer_x                         0x5811D0
#define CEverQuest__RMouseUp_x                                     0x5820D0
#define CEverQuest__SetGameState_x                                 0x564A90
#define CEverQuest__UPCNotificationFlush_x                         0x55CEA0
#define CEverQuest__IssuePetCommand_x                              0x56C750

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B9F50
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B9FB0
#define CGaugeWnd__Draw_x                                          0x6BA3E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B130
#define CGuild__GetGuildName_x                                     0x43B600
#define CGuild__GetGuildIndex_x                                    0x43C810

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D6450

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E3800
#define CInvSlotMgr__MoveItem_x                                    0x6E3FC0
#define CInvSlotMgr__SelectSlot_x                                  0x6E30F0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E2550
#define CInvSlot__SliderComplete_x                                 0x6DFD80
#define CInvSlot__GetItemBase_x                                    0x6DF200
#define CInvSlot__UpdateItem_x                                     0x6DF780

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E5420
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E6560

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AE210
#define CItemDisplayWnd__UpdateStrings_x                           0x6E7670
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F3F20
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F4430
#define CItemDisplayWnd__SetItem_x                                 0x6F9D70

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E5310

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EDC10

// CLabel 
#define CLabel__Draw_x                                             0x700B30

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C30F0
#define CListWnd__dCListWnd_x                                      0x8C43B0
#define CListWnd__AddColumn_x                                      0x8C4350
#define CListWnd__AddColumn1_x                                     0x8C39E0
#define CListWnd__AddLine_x                                        0x8C33C0
#define CListWnd__AddString_x                                      0x8C35E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C0200
#define CListWnd__CalculateVSBRange_x                              0x8C25C0
#define CListWnd__ClearSel_x                                       0x8BF520
#define CListWnd__ClearAllSel_x                                    0x8BF4D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C2F80
#define CListWnd__Compare_x                                        0x8C0EF0
#define CListWnd__Draw_x                                           0x8C21C0
#define CListWnd__DrawColumnSeparators_x                           0x8C2050
#define CListWnd__DrawHeader_x                                     0x8BF7E0
#define CListWnd__DrawItem_x                                       0x8C1580
#define CListWnd__DrawLine_x                                       0x8C1CF0
#define CListWnd__DrawSeparator_x                                  0x8C20F0
#define CListWnd__EnableLine_x                                     0x8BF700
#define CListWnd__EnsureVisible_x                                  0x8C0360
#define CListWnd__ExtendSel_x                                      0x8C1490
#define CListWnd__GetColumnMinWidth_x                              0x8BEE10
#define CListWnd__GetColumnWidth_x                                 0x8BED40
#define CListWnd__GetCurSel_x                                      0x8BE510
#define CListWnd__GetItemAtPoint_x                                 0x8C05F0
#define CListWnd__GetItemAtPoint1_x                                0x8C0660
#define CListWnd__GetItemData_x                                    0x8BE860
#define CListWnd__GetItemHeight_x                                  0x8BFE60
#define CListWnd__GetItemIcon_x                                    0x8BEA50
#define CListWnd__GetItemRect_x                                    0x8C0430
#define CListWnd__GetItemText_x                                    0x8BE900
#define CListWnd__GetSelList_x                                     0x8C38D0
#define CListWnd__GetSeparatorRect_x                               0x8C0E10
#define CListWnd__InsertLine_x                                     0x8C37C0
#define CListWnd__RemoveLine_x                                     0x8C37D0
#define CListWnd__SetColors_x                                      0x8BE660
#define CListWnd__SetColumnJustification_x                         0x8BF0A0
#define CListWnd__SetColumnWidth_x                                 0x8BEDC0
#define CListWnd__SetCurSel_x                                      0x8BE550
#define CListWnd__SetItemColor_x                                   0x8C2C70
#define CListWnd__SetItemData_x                                    0x8BF580
#define CListWnd__SetItemText_x                                    0x8C2AB0
#define CListWnd__ShiftColumnSeparator_x                           0x8C2940
#define CListWnd__Sort_x                                           0x8C44B0
#define CListWnd__ToggleSel_x                                      0x8BF450

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x719B60

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73F2E0
#define CMerchantWnd__RequestBuyItem_x                             0x746D80
#define CMerchantWnd__RequestSellItem_x                            0x749380
#define CMerchantWnd__SelectRecoverySlot_x                         0x73C5B0
#define CMerchantWnd__SelectBuySellSlot_x                          0x73A570
#define CMerchantWnd__ActualSelect_x                               0x741070

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x854E10
#define CPacketScrambler__hton_x                                   0x854E20

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E20F0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E21D0
#define CSidlManager__CreateLabel_x                                0x7A31E0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E0680
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E24B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D95F0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D94F0
#define CSidlScreenWnd__ConvertToRes_x                             0x8FE110
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9F00
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DB0E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DB190
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DA650
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D98B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D9020
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D9AA0
#define CSidlScreenWnd__Init1_x                                    0x8DADB0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D9FC0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D91E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DA890
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D8C70
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8FD0
#define CSidlScreenWnd__WndNotification_x                          0x8DAB30
#define CSidlScreenWnd__GetChildItem_x                             0x8D90F0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CC970
#define CSidlScreenWnd__m_layoutCopy_x                             0x172EE20

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6053F0
#define CSkillMgr__GetSkillCap_x                                   0x6055D0
#define CSkillMgr__GetNameToken_x                                  0x604FA0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FD3C0
#define CSliderWnd__SetValue_x                                     0x8FD590
#define CSliderWnd__SetNumTicks_x                                  0x8FDD10

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A94F0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F7250
#define CStmlWnd__CalculateHSBRange_x                              0x8EF7B0
#define CStmlWnd__CalculateVSBRange_x                              0x8EF720
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EF930
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F0130
#define CStmlWnd__ForceParseNow_x                                  0x8F7BD0
#define CStmlWnd__GetNextTagPiece_x                                0x8F0030
#define CStmlWnd__GetSTMLText_x                                    0x484280
#define CStmlWnd__GetVisibleText_x                                 0x8F0B80
#define CStmlWnd__InitializeWindowVariables_x                      0x8F3140
#define CStmlWnd__MakeStmlColorTag_x                               0x8EEA00
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EEA60
#define CStmlWnd__SetSTMLText_x                                    0x8F4990
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6EF0
#define CStmlWnd__UpdateHistoryString_x                            0x8F1AC0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FB110
#define CTabWnd__DrawCurrentPage_x                                 0x8FA9A0
#define CTabWnd__DrawTab_x                                         0x8FA760
#define CTabWnd__GetCurrentPage_x                                  0x8FAD50
#define CTabWnd__GetPageInnerRect_x                                0x8FA450
#define CTabWnd__GetTabInnerRect_x                                 0x8FA650
#define CTabWnd__GetTabRect_x                                      0x8FA520
#define CTabWnd__InsertPage_x                                      0x8FB400
#define CTabWnd__SetPage_x                                         0x8FAD80
#define CTabWnd__SetPageRect_x                                     0x8FB050
#define CTabWnd__UpdatePage_x                                      0x8FB3A0
#define CTabWnd__GetPageFromTabIndex_x                             0x8FA6B0
#define CTabWnd__GetCurrentTabIndex_x                              0x8FA3E0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E6710
#define CPageWnd__SetTabText_x                                     0x907480

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436D30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D6F40
#define CTextureFont__GetTextExtent_x                              0x8D6CA0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63DDC0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9038C0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BC5B0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5A6D00
#define CXStr__CXStr1_x                                            0x444000
#define CXStr__CXStr3_x                                            0x89F940
#define CXStr__dCXStr_x                                            0x8F86B0
#define CXStr__operator_equal_x                                    0x89FAB0
#define CXStr__operator_equal1_x                                   0x89FB00
#define CXStr__operator_plus_equal1_x                              0x8A0C00

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D4A30
#define CXWnd__BringToTop_x                                        0x8CBB50
#define CXWnd__Center_x                                            0x8D1CF0
#define CXWnd__ClrFocus_x                                          0x8CB720
#define CXWnd__Destroy_x                                           0x8D27E0
#define CXWnd__DoAllDrawing_x                                      0x8D1920
#define CXWnd__DrawChildren_x                                      0x8D1AD0
#define CXWnd__DrawColoredRect_x                                   0x8CBF40
#define CXWnd__DrawTooltip_x                                       0x8CC1E0
#define CXWnd__DrawTooltipAtPoint_x                                0x8D08C0
#define CXWnd__GetBorderFrame_x                                    0x8CC650
#define CXWnd__GetChildWndAt_x                                     0x8D26C0
#define CXWnd__GetClientClipRect_x                                 0x8CC400
#define CXWnd__GetScreenClipRect_x                                 0x8D0FC0
#define CXWnd__GetScreenRect_x                                     0x8CC810
#define CXWnd__GetTooltipRect_x                                    0x8CC070
#define CXWnd__GetWindowTextA_x                                    0x427050
#define CXWnd__IsActive_x                                          0x8C7160
#define CXWnd__IsDescendantOf_x                                    0x8CC590
#define CXWnd__IsReallyVisible_x                                   0x8CF8F0
#define CXWnd__IsType_x                                            0x8D1D60
#define CScreenPieceTemplate__IsType_x                             0x8FFFD0
#define CXWnd__Move_x                                              0x8CF050
#define CXWnd__Move1_x                                             0x8D15F0
#define CXWnd__ProcessTransition_x                                 0x8CBAF0
#define CXWnd__Refade_x                                            0x8CB8D0
#define CXWnd__Resize_x                                            0x8CC8D0
#define CXWnd__Right_x                                             0x8D0DC0
#define CXWnd__SetFocus_x                                          0x8CE1A0
#define CXWnd__SetFont_x                                           0x8CB770
#define CXWnd__SetKeyTooltip_x                                     0x8CCB40
#define CXWnd__SetMouseOver_x                                      0x8D12E0
#define CXWnd__StartFade_x                                         0x8CBBA0
#define CXWnd__GetChildItem_x                                      0x8D1220
#define CXWnd__SetParent_x                                         0x8D2670

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C8A20
#define CXWndManager__DrawWindows_x                                0x8C8660
#define CXWndManager__GetKeyboardFlags_x                           0x8C6C90
#define CXWndManager__HandleKeyboardMsg_x                          0x8C7600
#define CXWndManager__RemoveWnd_x                                  0x8C72F0

// CDBStr
#define CDBStr__GetString_x                                        0x4BA760

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4525D0
#define EQ_Character__Cur_HP_x                                     0x4668E0
#define EQ_Character__Cur_Mana_x                                   0x45B8F0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B690
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443680
#define EQ_Character__GetFocusRangeModifier_x                      0x4437D0
#define EQ_Character__GetHPRegen_x                                 0x46A480
#define EQ_Character__GetEnduranceRegen_x                          0x465EF0
#define EQ_Character__GetManaRegen_x                               0x46AA20
#define EQ_Character__Max_Endurance_x                              0x5CBD30
#define EQ_Character__Max_HP_x                                     0x45E470
#define EQ_Character__Max_Mana_x                                   0x5CBB60
#define EQ_Character__doCombatAbility_x                            0x5C9230
#define EQ_Character__UseSkill_x                                   0x472810
#define EQ_Character__GetConLevel_x                                0x5BE9C0
#define EQ_Character__IsExpansionFlag_x                            0x4B6980
#define EQ_Character__TotalEffect_x                                0x44F800
#define EQ_Character__GetPCSpellAffect_x                           0x44BA20
#define EQ_Character__SpellDuration_x                              0x449A20
#define EQ_Character__FindItemByRecord_x                           0x463F50
#define EQ_Character__GetAdjustedSkill_x                           0x466AB0
#define EQ_Character__GetBaseSkill_x                               0x45E350

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x872D60

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D43E0

//PcClient
#define PcClient__PcClient_x                                       0x5C0800

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446B80
#define CCharacterSelect__EnterWorld_x                             0x446350
#define CCharacterSelect__Quit_x                                   0x444F10

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59E950
#define EQ_Item__CreateItemTagString_x                             0x852F90
#define EQ_Item__IsStackable_x                                     0x848270
#define EQ_Item__GetImageNum_x                                     0x84AD90
#define EQ_Item__CreateItemClient_x                                0x59FA80
#define EQ_Item__GetItemValue_x                                    0x8519F0
#define EQ_Item__ValueSellMerchant_x                               0x854A60
#define EQ_Item__IsKeyRingItem_x                                   0x848D60
#define EQ_Item__CanGoInBag_x                                      0x59EAE0
#define EQ_Item__GetMaxItemCount_x                                 0x848160
#define EQ_Item__GetHeldItem_x                                     0x849B90
#define EQ_Item__GetAugmentFitBySlot_x                             0x854880

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA9F0
#define EQ_LoadingS__Array_x                                       0xC09C68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CE250
#define EQ_PC__GetAlternateAbilityId_x                             0x85CE70
#define EQ_PC__GetCombatAbility_x                                  0x85CF00
#define EQ_PC__GetCombatAbilityTimer_x                             0x857AC0
#define EQ_PC__GetItemRecastTimer_x                                0x5C7A20
#define EQ_PC__HasLoreItem_x                                       0x5C1FC0
#define EQ_PC__AlertInventoryChanged_x                             0x5BE970
#define EQ_PC__GetPcZoneClient_x                                   0x5E8930
#define EQ_PC__RemoveMyAffect_x                                    0x5C6E80
#define EQ_PC__GetKeyRingItems_x                                   0x857EE0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86ABB0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85EE40

// EQItemList 
#define EQItemList__EQItemList_x                                   0x526C10
#define EQItemList__add_object_x                                   0x553D30
#define EQItemList__add_item_x                                     0x526B50
#define EQItemList__delete_item_x                                  0x527000
#define EQItemList__FreeItemList_x                                 0x526F00

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9960

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D40A0
#define EQPlayer__dEQPlayer_x                                      0x5DC850
#define EQPlayer__DoAttack_x                                       0x5EE0D0
#define EQPlayer__EQPlayer_x                                       0x5DEF70
#define EQPlayer__SetNameSpriteState_x                             0x5D9680
#define EQPlayer__SetNameSpriteTint_x                              0x5D55A0
#define PlayerBase__HasProperty_j_x                                0x9315D0
#define EQPlayer__IsTargetable_x                                   0x931870
#define EQPlayer__CanSee_x                                         0x931DD0
#define PlayerZoneClient__ChangeHeight_x                           0x5EDF90
#define EQPlayer__CanSee1_x                                        0x931EC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x931B60

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E8AE0
#define PlayerZoneClient__IsValidTeleport_x                        0x5545D0
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2C10


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E2F60
#define EQPlayerManager__GetSpawnByName_x                          0x5E33C0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E2F90

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A5090
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A50D0
#define KeypressHandler__ClearCommandStateArray_x                  0x5A4C80
#define KeypressHandler__HandleKeyDown_x                           0x5A35A0
#define KeypressHandler__HandleKeyUp_x                             0x5A38C0
#define KeypressHandler__SaveKeymapping_x                          0x5A4D50

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7124F0
#define MapViewMap__SaveEx_x                                       0x715820
#define MapViewMap__SetZoom_x                                      0x712170

#define PlayerPointManager__GetAltCurrency_x                       0x870D30

// StringTable 
#define StringTable__getString_x                                   0x86AEE0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CB7C0
#define PcZoneClient__RemovePetEffect_x                            0x5C7EF0
#define PcZoneClient__HasAlternateAbility_x                        0x5C8890
#define PcZoneClient__GetCurrentMod_x                              0x45D920
#define PcZoneClient__GetModCap_x                                  0x45B050
#define PcZoneClient__CanEquipItem_x                               0x5C8D70
#define PcZoneClient__GetItemByID_x                                0x5CD5D0
#define PcZoneClient__GetItemByItemClass_x                         0x5CE170
#define PcZoneClient__RemoveBuffEffect_x                           0x5C7130

//Doors
#define EQSwitch__UseSwitch_x                                      0x55B750

//IconCache
#define IconCache__GetIcon_x                                       0x6AF7B0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A6680
#define CContainerMgr__CloseContainer_x                            0x6A6EA0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x773190

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x597A40

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5000
#define EQ_Spell__SpellAffects_x                                   0x4F21E0
#define EQ_Spell__SpellAffectBase_x                                0x4F2250
#define CharacterZoneClient__CalcAffectChange_x                    0x44B8B0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AB50
#define CLootWnd__LootAll_x                                        0x707D90
#define CLootWnd__RequestLootSlot_x                                0x7085A0
#define EQ_Spell__IsStackable_x                                    0x4590A0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4494F0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EBD0
#define EQ_Spell__IsSPAStacking_x                                  0x4F1D50
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2DF0
#define EQ_Spell__IsNoRemove_x                                     0x434D60
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1D70

#define __IsResEffectSpell_x                                       0x449570

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87CA00

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BAE70
#define CTargetWnd__WndNotification_x                              0x7BA960
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BB050

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7BFFB0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED840
#define EqSoundManager__PlayScriptMp3_x                            0x4EF2E0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A88E0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EAE20
#define CSidlManager__FindAnimation1_x                             0x8E00B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E2210
#define CAltAbilityData__GetMercMaxRank_x                          0x4E21C0
#define CAltAbilityData__GetMaxRank_x                              0x4D6AB0

//CTargetRing
#define CTargetRing__Cast_x                                        0x595680

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459390
#define CharacterBase__CreateItemGlobalIndex_x                     0x475240
#define CharacterBase__CreateItemIndex_x                           0x5201D0
#define CharacterBase__GetItemPossession_x                         0x4443B0
#define CharacterBase__GetItemByGlobalIndex_x                      0x880840
#define CharacterBase__GetEffectId_x                               0x459350

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68F4A0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68EC00

//messages
#define msg_spell_worn_off_x                                       0x4FCB20
#define msg_new_text_x                                             0x5062A0
#define msgTokenTextParam_x                                        0x502AA0

//SpellManager
#define SpellManager__vftable_x                                    0xAC8258
#define SpellManager__SpellManager_x                               0x47DF30
#define Spellmanager__LoadTextSpells_x                             0x60C360

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x935980

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487D80
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EAF0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449250
#define ItemGlobalIndex__IsValidIndex_x                            0x458BE0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87E6C0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87D600

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x700D80

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AB3D0
#define CCursorAttachment__Deactivate_x                            0x6AA910

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FC8C0
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FCA40

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x604000

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C5F0

//IString
#define IString__Append_x                                          0x47EB60

//Camera
#define CDisplay__cameraType_x                                     0xE6D7C8
#define EverQuest__Cameras_x                                       0xF2FAC8
