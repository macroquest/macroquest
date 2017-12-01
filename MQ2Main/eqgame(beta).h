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
#define __ExpectedVersionDate                                     "Dec  1 2017"
#define __ExpectedVersionTime                                     "04:16:43"
#define __ActualVersionDate_x                                      0xAE20F0
#define __ActualVersionTime_x                                      0xAE20FC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5A97C0
#define __MemChecker1_x                                            0x8A20D0
#define __MemChecker2_x                                            0x63F890
#define __MemChecker3_x                                            0x63F7E0
#define __MemChecker4_x                                            0x7F3C60
#define __EncryptPad0_x                                            0xC3CFE8
#define __EncryptPad1_x                                            0xD16BA0
#define __EncryptPad2_x                                            0xC65ED0
#define __EncryptPad3_x                                            0xC65AD0
#define __EncryptPad4_x                                            0xD051A0
#define __EncryptPad5_x                                            0x10C02C0
#define __AC1_x                                                    0x7B2A65
#define __AC2_x                                                    0x562AA7
#define __AC3_x                                                    0x560C20
#define __AC4_x                                                    0x572DF1
#define __AC5_x                                                    0x586B3B
#define __AC6_x                                                    0x58A6DE
#define __AC7_x                                                    0x58113C
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
#define __do_loot_x                                                0x531920
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
#define __CastRay_x                                                0x5492B0
#define __CastRay2_x                                               0x548BE0
#define __HeadingDiff_x                                            0x932380
#define __FixHeading_x                                             0x932310
#define __get_bearing_x                                            0x538A70
#define __ConvertItemTags_x                                        0x536540
#define __ExecuteCmd_x                                             0x520EA0
#define __EQGetTime_x                                              0x8A1A70
#define __get_melee_range_x                                        0x527B40
#define __GetGaugeValueFromEQ_x                                    0x7B1620
#define __GetLabelFromEQ_x                                         0x7B29F0
#define __ToggleKeyRingItem_x                                      0x48FA60
#define __GetXTargetType_x                                         0x933F80
#define __LoadFrontEnd_x                                           0x63EF60
#define __NewUIINI_x                                               0x7B1000
#define __ProcessGameEvents_x                                      0x582ED0
#define __ProcessMouseEvent_x                                      0x582670
#define CrashDetected_x                                            0x640920
#define wwsCrashReportCheckForUploader_x                           0x7FF720
#define __AppCrashWrapper_x                                        0xC65AC4
#define __pCrashHandler_x                                          0x10D59E0
#define __CrashHandler_x                                           0x7FF180
#define wwsCrashReportPlatformLaunchUploader_x                     0x801940
#define DrawNetStatus_x                                            0x5B9500
#define Util__FastTime_x                                           0x8A1710
#define Expansion_HoT_x                                            0xF2F7B0
#define __HelpPath_x                                               0xFB2F60
#define __STMLToText_x                                             0x8E7F40
#define __GetAnimationCache_x                                      0x6AE480

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423410
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E070
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DE40

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D7D50
#define AltAdvManager__IsAbilityReady_x                            0x4D7DC0
#define AltAdvManager__GetAAById_x                                 0x4D82B0
#define AltAdvManager__CanTrainAbility_x                           0x4D8EE0
#define AltAdvManager__CanSeeAbility_x                             0x4D8AA0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AE20
#define CharacterZoneClient__HasSkill_x                            0x466D30
#define CharacterZoneClient__MakeMeVisible_x                       0x46C990
#define CharacterZoneClient__IsStackBlocked_x                      0x44BE20
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B340
#define CharacterZoneClient__GetItemCountWorn_x                    0x465290
#define CharacterZoneClient__GetItemCountInInventory_x             0x465370
#define CharacterZoneClient__GetCursorItemCount_x                  0x465450
#define CharacterZoneClient__FindAffectSlot_x                      0x4514A0
#define CharacterZoneClient__BardCastBard_x                        0x44AAB0
#define CharacterZoneClient__GetMaxEffects_x                       0x449640
#define CharacterZoneClient__GetEffect_x                           0x44B570
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451300
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449990
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FE50

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66E7B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67C670

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x598040
#define CButtonWnd__CButtonWnd_x                                   0x8DC1B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x697630
#define CChatManager__InitContextMenu_x                            0x698780
#define CChatManager__FreeChatWindow_x                             0x6970E0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A08C0
#define CChatManager__SetLockedActiveChatWindow_x                  0x697600

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E6290
#define CContextMenu__dCContextMenu_x                              0x8E64A0
#define CContextMenu__AddMenuItem_x                                0x8E69C0
#define CContextMenu__RemoveMenuItem_x                             0x8E6620
#define CContextMenu__RemoveAllMenuItems_x                         0x8E6640
#define CContextMenu__CheckMenuItem_x                              0x8E66C0
#define CContextMenu__SetMenuItem_x                                0x8E6540

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D27C0
#define CContextMenuManager__RemoveMenu_x                          0x8D2B50
#define CContextMenuManager__PopupMenu_x                           0x8D2FA0
#define CContextMenuManager__Flush_x                               0x8D2830
#define CContextMenuManager__GetMenu_x                             0x419540

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x885B50
#define CChatService__GetFriendName_x                              0x885B60

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69E3B0
#define CChatWindow__Clear_x                                       0x69DC90
#define CChatWindow__WndNotification_x                             0x69ECB0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D65F0
#define CComboWnd__Draw_x                                          0x8D6800
#define CComboWnd__GetCurChoice_x                                  0x8D63A0
#define CComboWnd__GetListRect_x                                   0x8D6AA0
#define CComboWnd__GetTextRect_x                                   0x8D6660
#define CComboWnd__InsertChoice_x                                  0x8D6C00
#define CComboWnd__SetColors_x                                     0x8D6330
#define CComboWnd__SetChoice_x                                     0x8D6360
#define CComboWnd__GetItemCount_x                                  0x8D6390
#define CComboWnd__GetCurChoiceText_x                              0x8D63E0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A8630
#define CContainerWnd__vftable_x                                   0xAEBA08

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C5CB0
#define CDisplay__GetClickedActor_x                                0x4BE570
#define CDisplay__GetUserDefinedColor_x                            0x4BD150
#define CDisplay__GetWorldFilePath_x                               0x4BC5A0
#define CDisplay__is3dON_x                                         0x4BBA30
#define CDisplay__ReloadUI_x                                       0x4CFA70
#define CDisplay__WriteTextHD2_x                                   0x4C2040
#define CDisplay__TrueDistance_x                                   0x4BF1A0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FD640

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EA7F0
#define CEditWnd__GetCharIndexPt_x                                 0x8EB950
#define CEditWnd__GetDisplayString_x                               0x8EA9A0
#define CEditWnd__GetHorzOffset_x                                  0x8EACE0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EB410
#define CEditWnd__GetSelStartPt_x                                  0x8EBC10
#define CEditWnd__GetSTMLSafeText_x                                0x8EAE80
#define CEditWnd__PointFromPrintableChar_x                         0x8EB500
#define CEditWnd__SelectableCharFromPoint_x                        0x8EB680
#define CEditWnd__SetEditable_x                                    0x8EAE50

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x569620
#define CEverQuest__ClickedPlayer_x                                0x5631F0
#define CEverQuest__CreateTargetIndicator_x                        0x5640F0
#define CEverQuest__DeleteTargetIndicator_x                        0x564170
#define CEverQuest__DoTellWindow_x                                 0x476080
#define CEverQuest__OutputTextToLog_x                              0x475CE0
#define CEverQuest__DropHeldItemOnGround_x                         0x579B90
#define CEverQuest__dsp_chat_x                                     0x4763C0
#define CEverQuest__trimName_x                                     0x55FB00
#define CEverQuest__Emote_x                                        0x577EA0
#define CEverQuest__EnterZone_x                                    0x572F80
#define CEverQuest__GetBodyTypeDesc_x                              0x55D540
#define CEverQuest__GetClassDesc_x                                 0x566A30
#define CEverQuest__GetClassThreeLetterCode_x                      0x567030
#define CEverQuest__GetDeityDesc_x                                 0x55DE20
#define CEverQuest__GetLangDesc_x                                  0x55D8D0
#define CEverQuest__GetRaceDesc_x                                  0x5671F0
#define CEverQuest__InterpretCmd_x                                 0x56ADA0
#define CEverQuest__LeftClickedOnPlayer_x                          0x57F6E0
#define CEverQuest__LMouseUp_x                                     0x581690
#define CEverQuest__RightClickedOnPlayer_x                         0x5801F0
#define CEverQuest__RMouseUp_x                                     0x5810F0
#define CEverQuest__SetGameState_x                                 0x563AC0
#define CEverQuest__UPCNotificationFlush_x                         0x55BED0
#define CEverQuest__IssuePetCommand_x                              0x56B780

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B9330
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B9390
#define CGaugeWnd__Draw_x                                          0x6B97C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B150
#define CGuild__GetGuildName_x                                     0x43B620
#define CGuild__GetGuildIndex_x                                    0x43C830

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D57F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E2B80
#define CInvSlotMgr__MoveItem_x                                    0x6E3340
#define CInvSlotMgr__SelectSlot_x                                  0x6E2480

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E18D0
#define CInvSlot__SliderComplete_x                                 0x6DF0F0
#define CInvSlot__GetItemBase_x                                    0x6DE590
#define CInvSlot__UpdateItem_x                                     0x6DEB10

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E4770
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E58B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AD490
#define CItemDisplayWnd__UpdateStrings_x                           0x6E69C0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F3260
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F3760
#define CItemDisplayWnd__SetItem_x                                 0x6F8FE0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E4310

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6ECF60

// CLabel 
#define CLabel__Draw_x                                             0x6FFDA0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C22F0
#define CListWnd__dCListWnd_x                                      0x8C35A0
#define CListWnd__AddColumn_x                                      0x8C3540
#define CListWnd__AddColumn1_x                                     0x8C2BE0
#define CListWnd__AddLine_x                                        0x8C25C0
#define CListWnd__AddString_x                                      0x8C27E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BF3E0
#define CListWnd__CalculateVSBRange_x                              0x8C17B0
#define CListWnd__ClearSel_x                                       0x8BE6F0
#define CListWnd__ClearAllSel_x                                    0x8BE6A0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C2180
#define CListWnd__Compare_x                                        0x8C00E0
#define CListWnd__Draw_x                                           0x8C13B0
#define CListWnd__DrawColumnSeparators_x                           0x8C1240
#define CListWnd__DrawHeader_x                                     0x8BE9B0
#define CListWnd__DrawItem_x                                       0x8C0770
#define CListWnd__DrawLine_x                                       0x8C0EE0
#define CListWnd__DrawSeparator_x                                  0x8C12E0
#define CListWnd__EnableLine_x                                     0x8BE8D0
#define CListWnd__EnsureVisible_x                                  0x8BF540
#define CListWnd__ExtendSel_x                                      0x8C0680
#define CListWnd__GetColumnMinWidth_x                              0x8BDFE0
#define CListWnd__GetColumnWidth_x                                 0x8BDF10
#define CListWnd__GetCurSel_x                                      0x8BD6E0
#define CListWnd__GetItemAtPoint_x                                 0x8BF7E0
#define CListWnd__GetItemAtPoint1_x                                0x8BF850
#define CListWnd__GetItemData_x                                    0x8BDA20
#define CListWnd__GetItemHeight_x                                  0x8BF030
#define CListWnd__GetItemIcon_x                                    0x8BDC10
#define CListWnd__GetItemRect_x                                    0x8BF620
#define CListWnd__GetItemText_x                                    0x8BDAC0
#define CListWnd__GetSelList_x                                     0x8C2AD0
#define CListWnd__GetSeparatorRect_x                               0x8C0000
#define CListWnd__InsertLine_x                                     0x8C29C0
#define CListWnd__RemoveLine_x                                     0x8C29D0
#define CListWnd__SetColors_x                                      0x8BD830
#define CListWnd__SetColumnJustification_x                         0x8BE270
#define CListWnd__SetColumnWidth_x                                 0x8BDF90
#define CListWnd__SetCurSel_x                                      0x8BD720
#define CListWnd__SetItemColor_x                                   0x8C1E70
#define CListWnd__SetItemData_x                                    0x8BE750
#define CListWnd__SetItemText_x                                    0x8C1CB0
#define CListWnd__ShiftColumnSeparator_x                           0x8C1B40
#define CListWnd__Sort_x                                           0x8C36A0
#define CListWnd__ToggleSel_x                                      0x8BE620

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x718DA0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73E520
#define CMerchantWnd__RequestBuyItem_x                             0x746090
#define CMerchantWnd__RequestSellItem_x                            0x748690
#define CMerchantWnd__SelectRecoverySlot_x                         0x73B7E0
#define CMerchantWnd__SelectBuySellSlot_x                          0x7396C0
#define CMerchantWnd__ActualSelect_x                               0x7402F0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x853E60
#define CPacketScrambler__hton_x                                   0x853E70

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E1180
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1260
#define CSidlManager__CreateLabel_x                                0x7A2390
#define CSidlManager__CreateXWndFromTemplate_x                     0x8DF720
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E1540

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D8630
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D8530
#define CSidlScreenWnd__ConvertToRes_x                             0x8FD520
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D8F40
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DA0E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DA190
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D9660
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D88F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8060
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D8AE0
#define CSidlScreenWnd__Init1_x                                    0x8D9DB0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D8FF0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8220
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D98A0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D7CD0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8010
#define CSidlScreenWnd__WndNotification_x                          0x8D9B30
#define CSidlScreenWnd__GetChildItem_x                             0x8D8130
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CB9C0
#define CSidlScreenWnd__m_layoutCopy_x                             0x172EE20

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6048F0
#define CSkillMgr__GetSkillCap_x                                   0x604AD0
#define CSkillMgr__GetNameToken_x                                  0x6044A0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FC7E0
#define CSliderWnd__SetValue_x                                     0x8FC9B0
#define CSliderWnd__SetNumTicks_x                                  0x8FD130

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A8780

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F62B0
#define CStmlWnd__CalculateHSBRange_x                              0x8EE7F0
#define CStmlWnd__CalculateVSBRange_x                              0x8EE760
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EE970
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EF170
#define CStmlWnd__ForceParseNow_x                                  0x8F6C30
#define CStmlWnd__GetNextTagPiece_x                                0x8EF070
#define CStmlWnd__GetSTMLText_x                                    0x4842A0
#define CStmlWnd__GetVisibleText_x                                 0x8EFBC0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2190
#define CStmlWnd__MakeStmlColorTag_x                               0x8EDA40
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EDAA0
#define CStmlWnd__SetSTMLText_x                                    0x8F39F0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F5F50
#define CStmlWnd__UpdateHistoryString_x                            0x8F0B00

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FA140
#define CTabWnd__DrawCurrentPage_x                                 0x8F99D0
#define CTabWnd__DrawTab_x                                         0x8F9790
#define CTabWnd__GetCurrentPage_x                                  0x8F9D80
#define CTabWnd__GetPageInnerRect_x                                0x8F9480
#define CTabWnd__GetTabInnerRect_x                                 0x8F9680
#define CTabWnd__GetTabRect_x                                      0x8F9550
#define CTabWnd__InsertPage_x                                      0x8FA430
#define CTabWnd__SetPage_x                                         0x8F9DB0
#define CTabWnd__SetPageRect_x                                     0x8FA080
#define CTabWnd__UpdatePage_x                                      0x8FA3D0
#define CTabWnd__GetPageFromTabIndex_x                             0x8F96E0
#define CTabWnd__GetCurrentTabIndex_x                              0x8F9410

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E5A60
#define CPageWnd__SetTabText_x                                     0x906880

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436CC0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D5FA0
#define CTextureFont__GetTextExtent_x                              0x8D5D00

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63D1F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x902CC0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BB7F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029D0
#define CXStr__CXStr1_x                                            0x7E0190
#define CXStr__CXStr3_x                                            0x89E9A0
#define CXStr__dCXStr_x                                            0x7A2340
#define CXStr__operator_equal_x                                    0x89EB10
#define CXStr__operator_equal1_x                                   0x89EB60
#define CXStr__operator_plus_equal1_x                              0x89FC60

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D3AB0
#define CXWnd__BringToTop_x                                        0x8CAC20
#define CXWnd__Center_x                                            0x8D0D80
#define CXWnd__ClrFocus_x                                          0x8CA7E0
#define CXWnd__Destroy_x                                           0x8D1860
#define CXWnd__DoAllDrawing_x                                      0x8D09E0
#define CXWnd__DrawChildren_x                                      0x8D0B80
#define CXWnd__DrawColoredRect_x                                   0x8CAFF0
#define CXWnd__DrawTooltip_x                                       0x8CB2A0
#define CXWnd__DrawTooltipAtPoint_x                                0x8CF970
#define CXWnd__GetBorderFrame_x                                    0x8CB6B0
#define CXWnd__GetChildWndAt_x                                     0x8D1750
#define CXWnd__GetClientClipRect_x                                 0x8CB4C0
#define CXWnd__GetScreenClipRect_x                                 0x8D0070
#define CXWnd__GetScreenRect_x                                     0x8CB860
#define CXWnd__GetTooltipRect_x                                    0x8CB130
#define CXWnd__GetWindowTextA_x                                    0x426F70
#define CXWnd__IsActive_x                                          0x8C6310
#define CXWnd__IsDescendantOf_x                                    0x8CB600
#define CXWnd__IsReallyVisible_x                                   0x8CE9A0
#define CXWnd__IsType_x                                            0x8D0DF0
#define CScreenPieceTemplate__IsType_x                             0x8FF3D0
#define CXWnd__Move_x                                              0x8CE0B0
#define CXWnd__Move1_x                                             0x8D06A0
#define CXWnd__ProcessTransition_x                                 0x8CABC0
#define CXWnd__Refade_x                                            0x8CA990
#define CXWnd__Resize_x                                            0x8CB920
#define CXWnd__Right_x                                             0x8CFE70
#define CXWnd__SetFocus_x                                          0x8CD210
#define CXWnd__SetFont_x                                           0x8CA830
#define CXWnd__SetKeyTooltip_x                                     0x8CBB90
#define CXWnd__SetMouseOver_x                                      0x8D03B0
#define CXWnd__StartFade_x                                         0x8CAC70
#define CXWnd__GetChildItem_x                                      0x8D02F0
#define CXWnd__SetParent_x                                         0x8D1700

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C7BB0
#define CXWndManager__DrawWindows_x                                0x8C7800
#define CXWndManager__GetKeyboardFlags_x                           0x8C5E80
#define CXWndManager__HandleKeyboardMsg_x                          0x8C67B0
#define CXWndManager__RemoveWnd_x                                  0x8C64A0

// CDBStr
#define CDBStr__GetString_x                                        0x4BA2A0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452560
#define EQ_Character__Cur_HP_x                                     0x466910
#define EQ_Character__Cur_Mana_x                                   0x45B920
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B650
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443670
#define EQ_Character__GetFocusRangeModifier_x                      0x4437C0
#define EQ_Character__GetHPRegen_x                                 0x46A4B0
#define EQ_Character__GetEnduranceRegen_x                          0x465F20
#define EQ_Character__GetManaRegen_x                               0x46AA50
#define EQ_Character__Max_Endurance_x                              0x5CB350
#define EQ_Character__Max_HP_x                                     0x45E4A0
#define EQ_Character__Max_Mana_x                                   0x5CB180
#define EQ_Character__doCombatAbility_x                            0x5C8850
#define EQ_Character__UseSkill_x                                   0x472840
#define EQ_Character__GetConLevel_x                                0x5BDBA0
#define EQ_Character__IsExpansionFlag_x                            0x4B6630
#define EQ_Character__TotalEffect_x                                0x44F790
#define EQ_Character__GetPCSpellAffect_x                           0x44B9E0
#define EQ_Character__SpellDuration_x                              0x4499E0
#define EQ_Character__FindItemByRecord_x                           0x463F80
#define EQ_Character__GetAdjustedSkill_x                           0x466AE0
#define EQ_Character__GetBaseSkill_x                               0x45E380

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x871CF0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D39B0

//PcClient
#define PcClient__PcClient_x                                       0x5BF9E0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446B10
#define CCharacterSelect__EnterWorld_x                             0x4462E0
#define CCharacterSelect__Quit_x                                   0x444EA0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59DA00
#define EQ_Item__CreateItemTagString_x                             0x851FF0
#define EQ_Item__IsStackable_x                                     0x847390
#define EQ_Item__GetImageNum_x                                     0x849E30
#define EQ_Item__CreateItemClient_x                                0x59EB20
#define EQ_Item__GetItemValue_x                                    0x850A50
#define EQ_Item__ValueSellMerchant_x                               0x853AB0
#define EQ_Item__IsKeyRingItem_x                                   0x847E70
#define EQ_Item__CanGoInBag_x                                      0x59DB90
#define EQ_Item__GetMaxItemCount_x                                 0x847280
#define EQ_Item__GetHeldItem_x                                     0x848C50
#define EQ_Item__GetAugmentFitBySlot_x                             0x8538E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA2F0
#define EQ_LoadingS__Array_x                                       0xC09C68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CD880
#define EQ_PC__GetAlternateAbilityId_x                             0x85BED0
#define EQ_PC__GetCombatAbility_x                                  0x85BF60
#define EQ_PC__GetCombatAbilityTimer_x                             0x856B10
#define EQ_PC__GetItemRecastTimer_x                                0x5C7040
#define EQ_PC__HasLoreItem_x                                       0x5C11A0
#define EQ_PC__AlertInventoryChanged_x                             0x5BDB50
#define EQ_PC__GetPcZoneClient_x                                   0x5E7FC0
#define EQ_PC__RemoveMyAffect_x                                    0x5C6470
#define EQ_PC__GetKeyRingItems_x                                   0x856F30
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x869BB0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85DE40

// EQItemList 
#define EQItemList__EQItemList_x                                   0x525BC0
#define EQItemList__add_object_x                                   0x552D80
#define EQItemList__add_item_x                                     0x525B00
#define EQItemList__delete_item_x                                  0x525FB0
#define EQItemList__FreeItemList_x                                 0x525EB0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9560

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D3670
#define EQPlayer__dEQPlayer_x                                      0x5DBE00
#define EQPlayer__DoAttack_x                                       0x5ED770
#define EQPlayer__EQPlayer_x                                       0x5DE530
#define EQPlayer__SetNameSpriteState_x                             0x5D8C50
#define EQPlayer__SetNameSpriteTint_x                              0x5D4B70
#define PlayerBase__HasProperty_j_x                                0x930740
#define EQPlayer__IsTargetable_x                                   0x9309E0
#define EQPlayer__CanSee_x                                         0x930F40
#define PlayerZoneClient__ChangeHeight_x                           0x5ED630
#define EQPlayer__CanSee1_x                                        0x931030
#define PlayerBase__GetVisibilityLineSegment_x                     0x930CD0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E8170
#define PlayerZoneClient__IsValidTeleport_x                        0x553620
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2660


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E2600
#define EQPlayerManager__GetSpawnByName_x                          0x5E2A60
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E2630

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A4010
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A4050
#define KeypressHandler__ClearCommandStateArray_x                  0x5A3C00
#define KeypressHandler__HandleKeyDown_x                           0x5A2520
#define KeypressHandler__HandleKeyUp_x                             0x5A2840
#define KeypressHandler__SaveKeymapping_x                          0x5A3CD0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x711730
#define MapViewMap__SaveEx_x                                       0x714A60
#define MapViewMap__SetZoom_x                                      0x7113C0

#define PlayerPointManager__GetAltCurrency_x                       0x86FD80

// StringTable 
#define StringTable__getString_x                                   0x869EE0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CADE0
#define PcZoneClient__RemovePetEffect_x                            0x5C7510
#define PcZoneClient__HasAlternateAbility_x                        0x5C7EB0
#define PcZoneClient__GetCurrentMod_x                              0x45D950
#define PcZoneClient__GetModCap_x                                  0x45B080
#define PcZoneClient__CanEquipItem_x                               0x5C8390
#define PcZoneClient__GetItemByID_x                                0x5CCBF0
#define PcZoneClient__GetItemByItemClass_x                         0x5CD7A0
#define PcZoneClient__RemoveBuffEffect_x                           0x5C6720

//Doors
#define EQSwitch__UseSwitch_x                                      0x55A7A0

//IconCache
#define IconCache__GetIcon_x                                       0x6AEAB0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A59D0
#define CContainerMgr__CloseContainer_x                            0x6A61F0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x772320

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x596A70

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4940
#define EQ_Spell__SpellAffects_x                                   0x4F1B20
#define EQ_Spell__SpellAffectBase_x                                0x4F1B90
#define CharacterZoneClient__CalcAffectChange_x                    0x44B870
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AB10
#define CLootWnd__LootAll_x                                        0x706FE0
#define CLootWnd__RequestLootSlot_x                                0x7077F0
#define EQ_Spell__IsStackable_x                                    0x459040
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4494B0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EBC0
#define EQ_Spell__IsSPAStacking_x                                  0x4F1690
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2730
#define EQ_Spell__IsNoRemove_x                                     0x434CE0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F16B0

#define __IsResEffectSpell_x                                       0x449530

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87B9A0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BA0F0
#define CTargetWnd__WndNotification_x                              0x7B9BE0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BA2D0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7BF210

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED200
#define EqSoundManager__PlayScriptMp3_x                            0x4EECA0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8690

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E9E20
#define CSidlManager__FindAnimation1_x                             0x8DF150

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E1B70
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1B20
#define CAltAbilityData__GetMaxRank_x                              0x4D6400

//CTargetRing
#define CTargetRing__Cast_x                                        0x5946A0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459370
#define CharacterBase__CreateItemGlobalIndex_x                     0x475270
#define CharacterBase__CreateItemIndex_x                           0x51F1D0
#define CharacterBase__GetItemPossession_x                         0x444360
#define CharacterBase__GetItemByGlobalIndex_x                      0x87F7F0
#define CharacterBase__GetEffectId_x                               0x459330

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68E870
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68DFD0

//messages
#define msg_spell_worn_off_x                                       0x4FC430
#define msg_new_text_x                                             0x505BB0
#define msgTokenTextParam_x                                        0x5023B0

//SpellManager
#define SpellManager__vftable_x                                    0xAC7280
#define SpellManager__SpellManager_x                               0x47DF10
#define Spellmanager__LoadTextSpells_x                             0x60B7B0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x934AA0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487A80
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EAF0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4491F0
#define ItemGlobalIndex__IsValidIndex_x                            0x458B80

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87D660
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87C5A0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6FFFF0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AA6F0
#define CCursorAttachment__Deactivate_x                            0x6A9C40

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FBCE0
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FBE60

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x603460

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C2F0

//IString
#define IString__Append_x                                          0x47EB60

//Camera
#define CDisplay__cameraType_x                                     0xE6D7C8
#define EverQuest__Cameras_x                                       0xF2FAC8
