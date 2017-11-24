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
#define __ExpectedVersionDate                                     "Nov 24 2017"
#define __ExpectedVersionTime                                     "04:15:21"
#define __ActualVersionDate_x                                      0xAE20D8
#define __ActualVersionTime_x                                      0xAE20E4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5A99D0
#define __MemChecker1_x                                            0x8A2360
#define __MemChecker2_x                                            0x63F580
#define __MemChecker3_x                                            0x63F4D0
#define __MemChecker4_x                                            0x7F3C20
#define __EncryptPad0_x                                            0xC3CFE8
#define __EncryptPad1_x                                            0xD16BA0
#define __EncryptPad2_x                                            0xC65ED0
#define __EncryptPad3_x                                            0xC65AD0
#define __EncryptPad4_x                                            0xD051A0
#define __EncryptPad5_x                                            0x10C02C0
#define __AC1_x                                                    0x7B2B45
#define __AC2_x                                                    0x562CF7
#define __AC3_x                                                    0x560E70
#define __AC4_x                                                    0x573041
#define __AC5_x                                                    0x586D8B
#define __AC6_x                                                    0x58A92E
#define __AC7_x                                                    0x58138C
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
#define __do_loot_x                                                0x531CE0
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
#define __CastRay_x                                                0x549670
#define __CastRay2_x                                               0x548FA0
#define __HeadingDiff_x                                            0x9321E0
#define __FixHeading_x                                             0x932170
#define __get_bearing_x                                            0x538E30
#define __ConvertItemTags_x                                        0x536900
#define __ExecuteCmd_x                                             0x521260
#define __EQGetTime_x                                              0x8A1D00
#define __get_melee_range_x                                        0x527F00
#define __GetGaugeValueFromEQ_x                                    0x7B1700
#define __GetLabelFromEQ_x                                         0x7B2AD0
#define __ToggleKeyRingItem_x                                      0x48FC90
#define __GetXTargetType_x                                         0x933DE0
#define __LoadFrontEnd_x                                           0x63EC50
#define __NewUIINI_x                                               0x7B10E0
#define __ProcessGameEvents_x                                      0x583120
#define __ProcessMouseEvent_x                                      0x5828C0
#define CrashDetected_x                                            0x640610
#define wwsCrashReportCheckForUploader_x                           0x7FFAF0
#define __AppCrashWrapper_x                                        0xC65AC4
#define __pCrashHandler_x                                          0x10D59E0
#define __CrashHandler_x                                           0x7FF580
#define wwsCrashReportPlatformLaunchUploader_x                     0x801D20
#define DrawNetStatus_x                                            0x5B94C0
#define Util__FastTime_x                                           0x8A19A0
#define Expansion_HoT_x                                            0xF2F7B0
#define __HelpPath_x                                               0xFB2F60
#define __STMLToText_x                                             0x8E8130
#define __GetAnimationCache_x                                      0x6AE480

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423520
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E180
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DF50

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D7F70
#define AltAdvManager__IsAbilityReady_x                            0x4D7FE0
#define AltAdvManager__GetAAById_x                                 0x4D84D0
#define AltAdvManager__CanTrainAbility_x                           0x4D9100
#define AltAdvManager__CanSeeAbility_x                             0x4D8CC0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AF70
#define CharacterZoneClient__HasSkill_x                            0x466E80
#define CharacterZoneClient__MakeMeVisible_x                       0x46CAE0
#define CharacterZoneClient__IsStackBlocked_x                      0x44BEF0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B410
#define CharacterZoneClient__GetItemCountWorn_x                    0x4653E0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4654C0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4655A0
#define CharacterZoneClient__FindAffectSlot_x                      0x4515A0
#define CharacterZoneClient__BardCastBard_x                        0x44AB80
#define CharacterZoneClient__GetMaxEffects_x                       0x449710
#define CharacterZoneClient__GetEffect_x                           0x44B640
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451400
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449A60
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FF50

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66E700

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67C5A0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5981F0
#define CButtonWnd__CButtonWnd_x                                   0x8DC2C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6976F0
#define CChatManager__InitContextMenu_x                            0x698840
#define CChatManager__FreeChatWindow_x                             0x6971A0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A0960
#define CChatManager__SetLockedActiveChatWindow_x                  0x6976C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E6480
#define CContextMenu__dCContextMenu_x                              0x8E6690
#define CContextMenu__AddMenuItem_x                                0x8E6BB0
#define CContextMenu__RemoveMenuItem_x                             0x8E6810
#define CContextMenu__RemoveAllMenuItems_x                         0x8E6830
#define CContextMenu__CheckMenuItem_x                              0x8E68B0
#define CContextMenu__SetMenuItem_x                                0x8E6730

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D28B0
#define CContextMenuManager__RemoveMenu_x                          0x8D2C30
#define CContextMenuManager__PopupMenu_x                           0x8D3080
#define CContextMenuManager__Flush_x                               0x8D2920
#define CContextMenuManager__GetMenu_x                             0x419650

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x885D30
#define CChatService__GetFriendName_x                              0x885D40

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69E450
#define CChatWindow__Clear_x                                       0x69DD40
#define CChatWindow__WndNotification_x                             0x69ED50

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D66D0
#define CComboWnd__Draw_x                                          0x8D68E0
#define CComboWnd__GetCurChoice_x                                  0x8D6480
#define CComboWnd__GetListRect_x                                   0x8D6B80
#define CComboWnd__GetTextRect_x                                   0x8D6740
#define CComboWnd__InsertChoice_x                                  0x8D6CE0
#define CComboWnd__SetColors_x                                     0x8D6410
#define CComboWnd__SetChoice_x                                     0x8D6440
#define CComboWnd__GetItemCount_x                                  0x8D6470
#define CComboWnd__GetCurChoiceText_x                              0x8D64C0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A8630
#define CContainerWnd__vftable_x                                   0xAEB9F0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C5EC0
#define CDisplay__GetClickedActor_x                                0x4BE780
#define CDisplay__GetUserDefinedColor_x                            0x4BD360
#define CDisplay__GetWorldFilePath_x                               0x4BC7B0
#define CDisplay__is3dON_x                                         0x4BBC40
#define CDisplay__ReloadUI_x                                       0x4CFC80
#define CDisplay__WriteTextHD2_x                                   0x4C2250
#define CDisplay__TrueDistance_x                                   0x4BF3B0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FD410

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EA9E0
#define CEditWnd__GetCharIndexPt_x                                 0x8EBB40
#define CEditWnd__GetDisplayString_x                               0x8EAB90
#define CEditWnd__GetHorzOffset_x                                  0x8EAED0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EB600
#define CEditWnd__GetSelStartPt_x                                  0x8EBE00
#define CEditWnd__GetSTMLSafeText_x                                0x8EB070
#define CEditWnd__PointFromPrintableChar_x                         0x8EB6F0
#define CEditWnd__SelectableCharFromPoint_x                        0x8EB870
#define CEditWnd__SetEditable_x                                    0x8EB040

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x569870
#define CEverQuest__ClickedPlayer_x                                0x563440
#define CEverQuest__CreateTargetIndicator_x                        0x564340
#define CEverQuest__DeleteTargetIndicator_x                        0x5643C0
#define CEverQuest__DoTellWindow_x                                 0x4761D0
#define CEverQuest__OutputTextToLog_x                              0x475E30
#define CEverQuest__DropHeldItemOnGround_x                         0x579DE0
#define CEverQuest__dsp_chat_x                                     0x476510
#define CEverQuest__trimName_x                                     0x55FD50
#define CEverQuest__Emote_x                                        0x5780F0
#define CEverQuest__EnterZone_x                                    0x5731D0
#define CEverQuest__GetBodyTypeDesc_x                              0x55D790
#define CEverQuest__GetClassDesc_x                                 0x566C80
#define CEverQuest__GetClassThreeLetterCode_x                      0x567280
#define CEverQuest__GetDeityDesc_x                                 0x55E070
#define CEverQuest__GetLangDesc_x                                  0x55DB20
#define CEverQuest__GetRaceDesc_x                                  0x567440
#define CEverQuest__InterpretCmd_x                                 0x56AFF0
#define CEverQuest__LeftClickedOnPlayer_x                          0x57F930
#define CEverQuest__LMouseUp_x                                     0x5818E0
#define CEverQuest__RightClickedOnPlayer_x                         0x580440
#define CEverQuest__RMouseUp_x                                     0x581340
#define CEverQuest__SetGameState_x                                 0x563D10
#define CEverQuest__UPCNotificationFlush_x                         0x55C120
#define CEverQuest__IssuePetCommand_x                              0x56B9D0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B9340
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B93A0
#define CGaugeWnd__Draw_x                                          0x6B97D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B190
#define CGuild__GetGuildName_x                                     0x43B660
#define CGuild__GetGuildIndex_x                                    0x43C870

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D5840

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E2BE0
#define CInvSlotMgr__MoveItem_x                                    0x6E33A0
#define CInvSlotMgr__SelectSlot_x                                  0x6E24E0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E1940
#define CInvSlot__SliderComplete_x                                 0x6DF160
#define CInvSlot__GetItemBase_x                                    0x6DE5D0
#define CInvSlot__UpdateItem_x                                     0x6DEB50

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E47F0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E5920

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AD540
#define CItemDisplayWnd__UpdateStrings_x                           0x6E6A40
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F32F0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F3820
#define CItemDisplayWnd__SetItem_x                                 0x6F91A0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E45E0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6ED000

// CLabel 
#define CLabel__Draw_x                                             0x6FFF90

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C24A0
#define CListWnd__dCListWnd_x                                      0x8C3760
#define CListWnd__AddColumn_x                                      0x8C3700
#define CListWnd__AddColumn1_x                                     0x8C2D90
#define CListWnd__AddLine_x                                        0x8C2770
#define CListWnd__AddString_x                                      0x8C2990
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BF5B0
#define CListWnd__CalculateVSBRange_x                              0x8C1970
#define CListWnd__ClearSel_x                                       0x8BE8C0
#define CListWnd__ClearAllSel_x                                    0x8BE870
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C2330
#define CListWnd__Compare_x                                        0x8C02A0
#define CListWnd__Draw_x                                           0x8C1570
#define CListWnd__DrawColumnSeparators_x                           0x8C1400
#define CListWnd__DrawHeader_x                                     0x8BEB80
#define CListWnd__DrawItem_x                                       0x8C0930
#define CListWnd__DrawLine_x                                       0x8C10A0
#define CListWnd__DrawSeparator_x                                  0x8C14A0
#define CListWnd__EnableLine_x                                     0x8BEAA0
#define CListWnd__EnsureVisible_x                                  0x8BF710
#define CListWnd__ExtendSel_x                                      0x8C0840
#define CListWnd__GetColumnMinWidth_x                              0x8BE1B0
#define CListWnd__GetColumnWidth_x                                 0x8BE0E0
#define CListWnd__GetCurSel_x                                      0x8BD8B0
#define CListWnd__GetItemAtPoint_x                                 0x8BF9B0
#define CListWnd__GetItemAtPoint1_x                                0x8BFA20
#define CListWnd__GetItemData_x                                    0x8BDBF0
#define CListWnd__GetItemHeight_x                                  0x8BF200
#define CListWnd__GetItemIcon_x                                    0x8BDDE0
#define CListWnd__GetItemRect_x                                    0x8BF7F0
#define CListWnd__GetItemText_x                                    0x8BDC90
#define CListWnd__GetSelList_x                                     0x8C2C80
#define CListWnd__GetSeparatorRect_x                               0x8C01C0
#define CListWnd__InsertLine_x                                     0x8C2B70
#define CListWnd__RemoveLine_x                                     0x8C2B80
#define CListWnd__SetColors_x                                      0x8BDA00
#define CListWnd__SetColumnJustification_x                         0x8BE440
#define CListWnd__SetColumnWidth_x                                 0x8BE160
#define CListWnd__SetCurSel_x                                      0x8BD8F0
#define CListWnd__SetItemColor_x                                   0x8C2020
#define CListWnd__SetItemData_x                                    0x8BE920
#define CListWnd__SetItemText_x                                    0x8C1E60
#define CListWnd__ShiftColumnSeparator_x                           0x8C1CF0
#define CListWnd__Sort_x                                           0x8C3860
#define CListWnd__ToggleSel_x                                      0x8BE7F0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x718F60

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73E610
#define CMerchantWnd__RequestBuyItem_x                             0x7460E0
#define CMerchantWnd__RequestSellItem_x                            0x7486E0
#define CMerchantWnd__SelectRecoverySlot_x                         0x73B8D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x739870
#define CMerchantWnd__ActualSelect_x                               0x7403B0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x854150
#define CPacketScrambler__hton_x                                   0x854160

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E1290
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1370
#define CSidlManager__CreateLabel_x                                0x7A2550
#define CSidlManager__CreateXWndFromTemplate_x                     0x8DF840
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E1650

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D8720
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D8620
#define CSidlScreenWnd__ConvertToRes_x                             0x8FD2F0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9030
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DA200
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DA2B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D9780
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D89E0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8150
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D8BD0
#define CSidlScreenWnd__Init1_x                                    0x8D9ED0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D90E0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8310
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D99C0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D7DB0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8100
#define CSidlScreenWnd__WndNotification_x                          0x8D9C50
#define CSidlScreenWnd__GetChildItem_x                             0x8D8220
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CBB90
#define CSidlScreenWnd__m_layoutCopy_x                             0x172EE20

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x604620
#define CSkillMgr__GetSkillCap_x                                   0x604800
#define CSkillMgr__GetNameToken_x                                  0x6041D0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FC5B0
#define CSliderWnd__SetValue_x                                     0x8FC780
#define CSliderWnd__SetNumTicks_x                                  0x8FCF00

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A8830

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6490
#define CStmlWnd__CalculateHSBRange_x                              0x8EE9E0
#define CStmlWnd__CalculateVSBRange_x                              0x8EE950
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EEB60
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EF360
#define CStmlWnd__ForceParseNow_x                                  0x8F6E10
#define CStmlWnd__GetNextTagPiece_x                                0x8EF260
#define CStmlWnd__GetSTMLText_x                                    0x4842C0
#define CStmlWnd__GetVisibleText_x                                 0x8EFDB0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2380
#define CStmlWnd__MakeStmlColorTag_x                               0x8EDC30
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EDC90
#define CStmlWnd__SetSTMLText_x                                    0x8F3BD0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6130
#define CStmlWnd__UpdateHistoryString_x                            0x8F0CF0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FA320
#define CTabWnd__DrawCurrentPage_x                                 0x8F9BB0
#define CTabWnd__DrawTab_x                                         0x8F9970
#define CTabWnd__GetCurrentPage_x                                  0x8F9F60
#define CTabWnd__GetPageInnerRect_x                                0x8F9660
#define CTabWnd__GetTabInnerRect_x                                 0x8F9860
#define CTabWnd__GetTabRect_x                                      0x8F9730
#define CTabWnd__InsertPage_x                                      0x8FA610
#define CTabWnd__SetPage_x                                         0x8F9F90
#define CTabWnd__SetPageRect_x                                     0x8FA260
#define CTabWnd__UpdatePage_x                                      0x8FA5B0
#define CTabWnd__GetPageFromTabIndex_x                             0x8F98C0
#define CTabWnd__GetCurrentTabIndex_x                              0x8F95F0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E5AD0
#define CPageWnd__SetTabText_x                                     0x906650

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436DA0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D6080
#define CTextureFont__GetTextExtent_x                              0x8D5DE0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63CEF0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x902A90

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BBA10

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029F0
#define CXStr__CXStr1_x                                            0x403740
#define CXStr__CXStr3_x                                            0x89EBF0
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x89ED60
#define CXStr__operator_equal1_x                                   0x89EDB0
#define CXStr__operator_plus_equal1_x                              0x89FEB0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D3B90
#define CXWnd__BringToTop_x                                        0x8CADD0
#define CXWnd__Center_x                                            0x8D0EB0
#define CXWnd__ClrFocus_x                                          0x8CA9B0
#define CXWnd__Destroy_x                                           0x8D1980
#define CXWnd__DoAllDrawing_x                                      0x8D0B00
#define CXWnd__DrawChildren_x                                      0x8D0CA0
#define CXWnd__DrawColoredRect_x                                   0x8CB190
#define CXWnd__DrawTooltip_x                                       0x8CB440
#define CXWnd__DrawTooltipAtPoint_x                                0x8CFAC0
#define CXWnd__GetBorderFrame_x                                    0x8CB880
#define CXWnd__GetChildWndAt_x                                     0x8D1870
#define CXWnd__GetClientClipRect_x                                 0x8CB650
#define CXWnd__GetScreenClipRect_x                                 0x8D01C0
#define CXWnd__GetScreenRect_x                                     0x8CBA30
#define CXWnd__GetTooltipRect_x                                    0x8CB2D0
#define CXWnd__GetWindowTextA_x                                    0x427020
#define CXWnd__IsActive_x                                          0x8C64D0
#define CXWnd__IsDescendantOf_x                                    0x8CB7D0
#define CXWnd__IsReallyVisible_x                                   0x8CEAE0
#define CXWnd__IsType_x                                            0x8D0F20
#define CScreenPieceTemplate__IsType_x                             0x8FF1A0
#define CXWnd__Move_x                                              0x8CE1F0
#define CXWnd__Move1_x                                             0x8D07D0
#define CXWnd__ProcessTransition_x                                 0x8CAD80
#define CXWnd__Refade_x                                            0x8CAB60
#define CXWnd__Resize_x                                            0x8CBAF0
#define CXWnd__Right_x                                             0x8CFFC0
#define CXWnd__SetFocus_x                                          0x8CD380
#define CXWnd__SetFont_x                                           0x8CAA00
#define CXWnd__SetKeyTooltip_x                                     0x8CBD60
#define CXWnd__SetMouseOver_x                                      0x8D04F0
#define CXWnd__StartFade_x                                         0x8CAE20
#define CXWnd__GetChildItem_x                                      0x8D0430
#define CXWnd__SetParent_x                                         0x8D1820

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C7D70
#define CXWndManager__DrawWindows_x                                0x8C79C0
#define CXWndManager__GetKeyboardFlags_x                           0x8C6040
#define CXWndManager__HandleKeyboardMsg_x                          0x8C6970
#define CXWndManager__RemoveWnd_x                                  0x8C6660

// CDBStr
#define CDBStr__GetString_x                                        0x4BA4B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452660
#define EQ_Character__Cur_HP_x                                     0x466A60
#define EQ_Character__Cur_Mana_x                                   0x45BA50
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B720
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4436E0
#define EQ_Character__GetFocusRangeModifier_x                      0x443830
#define EQ_Character__GetHPRegen_x                                 0x46A600
#define EQ_Character__GetEnduranceRegen_x                          0x466070
#define EQ_Character__GetManaRegen_x                               0x46ABA0
#define EQ_Character__Max_Endurance_x                              0x5CB0B0
#define EQ_Character__Max_HP_x                                     0x45E5D0
#define EQ_Character__Max_Mana_x                                   0x5CAEE0
#define EQ_Character__doCombatAbility_x                            0x5C85B0
#define EQ_Character__UseSkill_x                                   0x472990
#define EQ_Character__GetConLevel_x                                0x5BDB10
#define EQ_Character__IsExpansionFlag_x                            0x4B6790
#define EQ_Character__TotalEffect_x                                0x44F890
#define EQ_Character__GetPCSpellAffect_x                           0x44BAB0
#define EQ_Character__SpellDuration_x                              0x449AB0
#define EQ_Character__FindItemByRecord_x                           0x4640C0
#define EQ_Character__GetAdjustedSkill_x                           0x466C30
#define EQ_Character__GetBaseSkill_x                               0x45E4B0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x871F40

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D37D0

//PcClient
#define PcClient__PcClient_x                                       0x5BF950

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446BC0
#define CCharacterSelect__EnterWorld_x                             0x446390
#define CCharacterSelect__Quit_x                                   0x444F50

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59DB10
#define EQ_Item__CreateItemTagString_x                             0x8522F0
#define EQ_Item__IsStackable_x                                     0x847610
#define EQ_Item__GetImageNum_x                                     0x84A110
#define EQ_Item__CreateItemClient_x                                0x59EC40
#define EQ_Item__GetItemValue_x                                    0x850D50
#define EQ_Item__ValueSellMerchant_x                               0x853DA0
#define EQ_Item__IsKeyRingItem_x                                   0x8480F0
#define EQ_Item__CanGoInBag_x                                      0x59DCA0
#define EQ_Item__GetMaxItemCount_x                                 0x847500
#define EQ_Item__GetHeldItem_x                                     0x848F20
#define EQ_Item__GetAugmentFitBySlot_x                             0x853BC0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA510
#define EQ_LoadingS__Array_x                                       0xC09C68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CD5D0
#define EQ_PC__GetAlternateAbilityId_x                             0x85C1A0
#define EQ_PC__GetCombatAbility_x                                  0x85C230
#define EQ_PC__GetCombatAbilityTimer_x                             0x856E00
#define EQ_PC__GetItemRecastTimer_x                                0x5C6DA0
#define EQ_PC__HasLoreItem_x                                       0x5C1110
#define EQ_PC__AlertInventoryChanged_x                             0x5BDAC0
#define EQ_PC__GetPcZoneClient_x                                   0x5E7D50
#define EQ_PC__RemoveMyAffect_x                                    0x5C61D0
#define EQ_PC__GetKeyRingItems_x                                   0x857220
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x869EB0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85E120

// EQItemList 
#define EQItemList__EQItemList_x                                   0x525F80
#define EQItemList__add_object_x                                   0x553100
#define EQItemList__add_item_x                                     0x525EC0
#define EQItemList__delete_item_x                                  0x526370
#define EQItemList__FreeItemList_x                                 0x526270

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9770

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D3490
#define EQPlayer__dEQPlayer_x                                      0x5DBC20
#define EQPlayer__DoAttack_x                                       0x5ED4F0
#define EQPlayer__EQPlayer_x                                       0x5DE350
#define EQPlayer__SetNameSpriteState_x                             0x5D8A70
#define EQPlayer__SetNameSpriteTint_x                              0x5D4990
#define PlayerBase__HasProperty_j_x                                0x930590
#define EQPlayer__IsTargetable_x                                   0x930830
#define EQPlayer__CanSee_x                                         0x930D90
#define PlayerZoneClient__ChangeHeight_x                           0x5ED3B0
#define EQPlayer__CanSee1_x                                        0x930E80
#define PlayerBase__GetVisibilityLineSegment_x                     0x930B20

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E7F00
#define PlayerZoneClient__IsValidTeleport_x                        0x5539A0
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2870


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E2390
#define EQPlayerManager__GetSpawnByName_x                          0x5E27F0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E23C0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A4220
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A4260
#define KeypressHandler__ClearCommandStateArray_x                  0x5A3E10
#define KeypressHandler__HandleKeyDown_x                           0x5A2730
#define KeypressHandler__HandleKeyUp_x                             0x5A2A50
#define KeypressHandler__SaveKeymapping_x                          0x5A3EE0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7118F0
#define MapViewMap__SaveEx_x                                       0x714C20
#define MapViewMap__SetZoom_x                                      0x711580

#define PlayerPointManager__GetAltCurrency_x                       0x870000

// StringTable 
#define StringTable__getString_x                                   0x86A1E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CAB40
#define PcZoneClient__RemovePetEffect_x                            0x5C7270
#define PcZoneClient__HasAlternateAbility_x                        0x5C7C10
#define PcZoneClient__GetCurrentMod_x                              0x45DA80
#define PcZoneClient__GetModCap_x                                  0x45B1B0
#define PcZoneClient__CanEquipItem_x                               0x5C80F0
#define PcZoneClient__GetItemByID_x                                0x5CC950
#define PcZoneClient__GetItemByItemClass_x                         0x5CD4F0
#define PcZoneClient__RemoveBuffEffect_x                           0x5C6480

//Doors
#define EQSwitch__UseSwitch_x                                      0x55A9F0

//IconCache
#define IconCache__GetIcon_x                                       0x6AEAB0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A59E0
#define CContainerMgr__CloseContainer_x                            0x6A6200

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x772520

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x596C20

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4DD0
#define EQ_Spell__SpellAffects_x                                   0x4F1FB0
#define EQ_Spell__SpellAffectBase_x                                0x4F2020
#define CharacterZoneClient__CalcAffectChange_x                    0x44B940
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44ABE0
#define CLootWnd__LootAll_x                                        0x707210
#define CLootWnd__RequestLootSlot_x                                0x707A20
#define EQ_Spell__IsStackable_x                                    0x459150
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449570
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EC30
#define EQ_Spell__IsSPAStacking_x                                  0x4F1B20
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2BC0
#define EQ_Spell__IsNoRemove_x                                     0x434DC0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1B40

#define __IsResEffectSpell_x                                       0x449600

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87BBD0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BA160
#define CTargetWnd__WndNotification_x                              0x7B9C50
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BA340

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7BF280

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED600
#define EqSoundManager__PlayScriptMp3_x                            0x4EF0A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8860

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EA010
#define CSidlManager__FindAnimation1_x                             0x8DF270

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E1E90
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1E40
#define CAltAbilityData__GetMaxRank_x                              0x4D6620

//CTargetRing
#define CTargetRing__Cast_x                                        0x594860

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459440
#define CharacterBase__CreateItemGlobalIndex_x                     0x4753C0
#define CharacterBase__CreateItemIndex_x                           0x51F600
#define CharacterBase__GetItemPossession_x                         0x444420
#define CharacterBase__GetItemByGlobalIndex_x                      0x87FA10
#define CharacterBase__GetEffectId_x                               0x459400

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68E900
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68E060

//messages
#define msg_spell_worn_off_x                                       0x4FC8A0
#define msg_new_text_x                                             0x506030
#define msgTokenTextParam_x                                        0x502830

//SpellManager
#define SpellManager__vftable_x                                    0xAC7258
#define SpellManager__SpellManager_x                               0x47DF70
#define Spellmanager__LoadTextSpells_x                             0x60B4B0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x934900

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487CD0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EB50
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4492B0
#define ItemGlobalIndex__IsValidIndex_x                            0x458C90

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87D890
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87C7D0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7001E0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AA6F0
#define CCursorAttachment__Deactivate_x                            0x6A9C40

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FBAB0
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FBC30

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x6031F0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C520

//IString
#define IString__Append_x                                          0x47EBC0

//Camera
#define CDisplay__cameraType_x                                     0xE6D7C8
#define EverQuest__Cameras_x                                       0xF2FAC8
