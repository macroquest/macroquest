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
#define __ExpectedVersionDate                                     "Dec  8 2017"
#define __ExpectedVersionTime                                     "04:16:10"
#define __ActualVersionDate_x                                      0xAE3098
#define __ActualVersionTime_x                                      0xAE30A4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AA0F0
#define __MemChecker1_x                                            0x8A1FD0
#define __MemChecker2_x                                            0x63F9A0
#define __MemChecker3_x                                            0x63F8F0
#define __MemChecker4_x                                            0x7F3BB0
#define __EncryptPad0_x                                            0xC3DFE8
#define __EncryptPad1_x                                            0xD17BA0
#define __EncryptPad2_x                                            0xC66ED0
#define __EncryptPad3_x                                            0xC66AD0
#define __EncryptPad4_x                                            0xD061A0
#define __EncryptPad5_x                                            0x10C12E0
#define __AC1_x                                                    0x7B3155
#define __AC2_x                                                    0x563437
#define __AC3_x                                                    0x5615B0
#define __AC4_x                                                    0x573781
#define __AC5_x                                                    0x5874CB
#define __AC6_x                                                    0x58B06E
#define __AC7_x                                                    0x581ACC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA4EE0

// Direct Input
#define DI8__Main_x                                                0x10C12B8
#define DI8__Keyboard_x                                            0x10C12BC
#define DI8__Mouse_x                                               0x10C12C0
#define DI8__Mouse_Copy_x                                          0xF2F474
#define DI8__Mouse_Check_x                                         0xFB8FA4
#define __AutoSkillArray_x                                         0xF30388
#define __Attack_x                                                 0xFB3A7B
#define __Autofire_x                                               0xFB3A7C
#define __BindList_x                                               0xC1A368
#define g_eqCommandStates_x                                        0xF1E1C0
#define __Clicks_x                                                 0xF2F530
#define __CommandList_x                                            0xC1CA80
#define __CurrentMapLabel_x                                        0x10C72B0
#define __CurrentSocial_x                                          0xBE98E8
#define __DoAbilityList_x                                          0xF65C40
#define __do_loot_x                                                0x5322D0
#define __DrawHandler_x                                            0x1730F2C
#define __GroupCount_x                                             0xF1FACA

#define __Guilds_x                                                 0xF256E0
#define __gWorld_x                                                 0xF21F84
#define __HotkeyPage_x                                             0xFAC640
#define __HWnd_x                                                   0xFB90C0
#define __InChatMode_x                                             0xF2F45C
#define __LastTell_x                                               0xF3133C
#define __LMouseHeldTime_x                                         0xF2F59C
#define __Mouse_x                                                  0x10C12C4
#define __MouseLook_x                                              0xF2F4F6
#define __MouseEventTime_x                                         0xFB4214
#define __gpbCommandEvent_x                                        0xF2204C
#define __NetStatusToggle_x                                        0xF2F4F9
#define __PCNames_x                                                0xF30944
#define __RangeAttackReady_x                                       0xF3066C
#define __RMouseHeldTime_x                                         0xF2F598
#define __RunWalkState_x                                           0xF2F460
#define __ScreenMode_x                                             0xE6DDA0
#define __ScreenX_x                                                0xF2F414
#define __ScreenY_x                                                0xF2F410
#define __ScreenXMax_x                                             0xF2F418
#define __ScreenYMax_x                                             0xF2F41C
#define __ServerHost_x                                             0xF1FA14
#define __ServerName_x                                             0xF65C00
#define __ShiftKeyDown_x                                           0xF2FAF0
#define __ShowNames_x                                              0xF30824
#define __Socials_x                                                0xF65D00
#define __SubscriptionType_x                                       0x10F7A34
#define __TargetAggroHolder_x                                      0x10C940C
#define __ZoneType_x                                               0xF2F8F4
#define __GroupAggro_x                                             0x10C944C
#define __LoginName_x                                              0xFB7B9C
#define __Inviter_x                                                0xFB39F8
#define __AttackOnAssist_x                                         0xF307E0
#define __UseTellWindows_x                                         0xF30ADC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF22070
#define instEQZoneInfo_x                                           0xF2F6EC
#define instKeypressHandler_x                                      0xFB41F8
#define pinstActiveBanker_x                                        0xF22028
#define pinstActiveCorpse_x                                        0xF2202C
#define pinstActiveGMaster_x                                       0xF22030
#define pinstActiveMerchant_x                                      0xF22024
#define pinstAggroInfo_x                                           0xD2B40C
#define pinstAltAdvManager_x                                       0xE6EF08
#define pinstAuraMgr_x                                             0xD3BC10
#define pinstBandageTarget_x                                       0xF22010
#define pinstCamActor_x                                            0xE6E7D8
#define pinstCDBStr_x                                              0xE6DD34
#define pinstCDisplay_x                                            0xF22038
#define pinstCEverQuest_x                                          0x10C1438
#define pinstEverQuestInfo_x                                       0xF2F408
#define pinstCharData_x                                            0xF21FF4
#define pinstCharSpawn_x                                           0xF2201C
#define pinstControlledMissile_x                                   0xF21FF0
#define pinstControlledPlayer_x                                    0xF2201C
#define pinstCSidlManager_x                                        0x172FE98
#define pinstCXWndManager_x                                        0x172FE90
#define instDynamicZone_x                                          0xF2F2A8
#define pinstDZMember_x                                            0xF2F3B8
#define pinstDZTimerInfo_x                                         0xF2F3BC
#define pinstEQItemList_x                                          0xF1E498
#define pinstEQObjectList_x                                        0xF1F4C4
#define instEQMisc_x                                               0xC027A8
#define pinstEQSoundManager_x                                      0xE6F4D8
#define instExpeditionLeader_x                                     0xF2F2F2
#define instExpeditionName_x                                       0xF2F332
#define pinstGroup_x                                               0xF1FAC6
#define pinstImeManager_x                                          0x172FE9C
#define pinstLocalPlayer_x                                         0xF22008
#define pinstMercenaryData_x                                       0xFB4860
#define pinstMercenaryStats_x                                      0x10C9558
#define pinstMercAltAbilities_x                                    0xE6F290
#define pinstModelPlayer_x                                         0xF22034
#define pinstPCData_x                                              0xF21FF4
#define pinstSkillMgr_x                                            0xFB5858
#define pinstSpawnManager_x                                        0xFB50B0
#define pinstSpellManager_x                                        0xFB59A0
#define pinstSpellSets_x                                           0xFAC6A4
#define pinstStringTable_x                                         0xF21F9C
#define pinstSwitchManager_x                                       0xF1F658
#define pinstTarget_x                                              0xF22020
#define pinstTargetObject_x                                        0xF21FF8
#define pinstTargetSwitch_x                                        0xF21FFC
#define pinstTaskMember_x                                          0xE6DC80
#define pinstTrackTarget_x                                         0xF22014
#define pinstTradeTarget_x                                         0xF22004
#define instTributeActive_x                                        0xC027CD
#define pinstViewActor_x                                           0xE6E7D4
#define pinstWorldData_x                                           0xF21FD8
#define pinstZoneAddr_x                                            0xF2F98C
#define pinstPlayerPath_x                                          0xFB5110
#define pinstTargetIndicator_x                                     0xFB5B38
#define pinstCTargetManager_x                                      0xFB5B98
#define EQObject_Top_x                                             0xF21FE8
#define pinstRealEstateItems_x                                     0xFB56C4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE6E6F0
#define pinstCAchievementsWnd_x                                    0xE6E74C
#define pinstCTextOverlay_x                                        0xD2B9A0
#define pinstCAudioTriggersWindow_x                                0xD2B788
#define pinstCCharacterSelect_x                                    0xE6E65C
#define pinstCFacePick_x                                           0xE6E40C
#define pinstCFindItemWnd_x                                        0xE6E6EC
#define pinstCNoteWnd_x                                            0xE6E614
#define pinstCBookWnd_x                                            0xE6E61C
#define pinstCPetInfoWnd_x                                         0xE6E620
#define pinstCTrainWnd_x                                           0xE6E624
#define pinstCSkillsWnd_x                                          0xE6E628
#define pinstCSkillsSelectWnd_x                                    0xE6E62C
#define pinstCCombatSkillsSelectWnd_x                              0xE6E630
#define pinstCFriendsWnd_x                                         0xE6E634
#define pinstCAuraWnd_x                                            0xE6E638
#define pinstCRespawnWnd_x                                         0xE6E63C
#define pinstCBandolierWnd_x                                       0xE6E640
#define pinstCPotionBeltWnd_x                                      0xE6E644
#define pinstCAAWnd_x                                              0xE6E648
#define pinstCAlarmWnd_x                                           0xE6E654
#define pinstCGroupSearchFiltersWnd_x                              0xE6E64C
#define pinstCLoadskinWnd_x                                        0xE6E650
#define pinstCLargeDialogWnd_x                                     0x10C84B8
#define pinstCMusicPlayerWnd_x                                     0xE6E658
#define pinstCMailWnd_x                                            0xE6E660
#define pinstCMailCompositionWnd_x                                 0xE6E664
#define pinstCMailAddressBookWnd_x                                 0xE6E668
#define pinstCRaidWnd_x                                            0xE6E670
#define pinstCRaidOptionsWnd_x                                     0xE6E674
#define pinstCBreathWnd_x                                          0xE6E678
#define pinstCMapViewWnd_x                                         0xE6E67C
#define pinstCMapToolbarWnd_x                                      0xE6E680
#define pinstCEditLabelWnd_x                                       0xE6E684
#define pinstCTargetWnd_x                                          0xE6E688
#define pinstCColorPickerWnd_x                                     0xE6E68C
#define pinstCPlayerWnd_x                                          0xE6E690
#define pinstCOptionsWnd_x                                         0xE6E694
#define pinstCBuffWindowNORMAL_x                                   0xE6E698
#define pinstCBuffWindowSHORT_x                                    0xE6E69C
#define pinstCharacterCreation_x                                   0xE6E6A0
#define pinstCCursorAttachment_x                                   0xE6E6A4
#define pinstCCastingWnd_x                                         0xE6E6A8
#define pinstCCastSpellWnd_x                                       0xE6E6AC
#define pinstCSpellBookWnd_x                                       0xE6E6B0
#define pinstCInventoryWnd_x                                       0xE6E6B4
#define pinstCBankWnd_x                                            0xE6E6BC
#define pinstCQuantityWnd_x                                        0xE6E6C0
#define pinstCLootWnd_x                                            0xE6E6C4
#define pinstCActionsWnd_x                                         0xE6E6C8
#define pinstCCombatAbilityWnd_x                                   0xE6E6D0
#define pinstCMerchantWnd_x                                        0xE6E6D4
#define pinstCTradeWnd_x                                           0xE6E6DC
#define pinstCSelectorWnd_x                                        0xE6E6E0
#define pinstCBazaarWnd_x                                          0xE6E6E4
#define pinstCBazaarSearchWnd_x                                    0xE6E6E8
#define pinstCGiveWnd_x                                            0xE6E708
#define pinstCTrackingWnd_x                                        0xE6E710
#define pinstCInspectWnd_x                                         0xE6E714
#define pinstCSocialEditWnd_x                                      0xE6E718
#define pinstCFeedbackWnd_x                                        0xE6E71C
#define pinstCBugReportWnd_x                                       0xE6E720
#define pinstCVideoModesWnd_x                                      0xE6E724
#define pinstCTextEntryWnd_x                                       0xE6E72C
#define pinstCFileSelectionWnd_x                                   0xE6E730
#define pinstCCompassWnd_x                                         0xE6E734
#define pinstCPlayerNotesWnd_x                                     0xE6E738
#define pinstCGemsGameWnd_x                                        0xE6E73C
#define pinstCTimeLeftWnd_x                                        0xE6E758
#define pinstCPetitionQWnd_x                                       0xE6E75C
#define pinstCStoryWnd_x                                           0xE6E760
#define pinstCJournalTextWnd_x                                     0xE6E764
#define pinstCJournalCatWnd_x                                      0xE6E768
#define pinstCBodyTintWnd_x                                        0xE6E76C
#define pinstCServerListWnd_x                                      0xE6E770
#define pinstCAvaZoneWnd_x                                         0xE6E77C
#define pinstCBlockedBuffWnd_x                                     0xE6E780
#define pinstCBlockedPetBuffWnd_x                                  0xE6E784
#define pinstCInvSlotMgr_x                                         0xE6E7CC
#define pinstCContainerMgr_x                                       0xE6E7D0
#define pinstCAdventureLeaderboardWnd_x                            0x10C1DE8
#define pinstCAdventureRequestWnd_x                                0x10C1E60
#define pinstCAltStorageWnd_x                                      0x10C2140
#define pinstCAdventureStatsWnd_x                                  0x10C1ED8
#define pinstCBarterMerchantWnd_x                                  0x10C2E88
#define pinstCBarterSearchWnd_x                                    0x10C2F00
#define pinstCBarterWnd_x                                          0x10C2F78
#define pinstCChatWindowManager_x                                  0x10C3788
#define pinstCDynamicZoneWnd_x                                     0x10C3CB8
#define pinstCEQMainWnd_x                                          0x10C3E80
#define pinstCFellowshipWnd_x                                      0x10C3C4C
#define pinstCFindLocationWnd_x                                    0x10C4150
#define pinstCGroupSearchWnd_x                                     0x10C4420
#define pinstCGroupWnd_x                                           0x10C4498
#define pinstCGuildBankWnd_x                                       0x10C4510
#define pinstCGuildMgmtWnd_x                                       0x10C6600
#define pinstCHotButtonWnd_x                                       0x10C66FC
#define pinstCHotButtonWnd1_x                                      0x10C66FC
#define pinstCHotButtonWnd2_x                                      0x10C6700
#define pinstCHotButtonWnd3_x                                      0x10C6704
#define pinstCHotButtonWnd4_x                                      0x10C6728
#define pinstCItemDisplayManager_x                                 0x10C6B80
#define pinstCItemExpTransferWnd_x                                 0x10C6C7C
#define pinstCLFGuildWnd_x                                         0x10C6F58
#define pinstCMIZoneSelectWnd_x                                    0x10C7538
#define pinstCConfirmationDialog_x                                 0x10C7B50
#define pinstCPopupWndManager_x                                    0x10C7B50
#define pinstCProgressionSelectionWnd_x                            0x10C7C40
#define pinstCPvPStatsWnd_x                                        0x10C7D30
#define pinstCTaskWnd_x                                            0x10C9838
#define pinstCTaskSomething_x                                      0xD3C828
#define pinstCTaskTemplateSelectWnd_x                              0x10C97C0
#define pinstCTipWndOFDAY_x                                        0x10C99A0
#define pinstCTipWndCONTEXT_x                                      0x10C99A4
#define pinstCTitleWnd_x                                           0x10C9A20
#define pinstCContextMenuManager_x                                 0x172FD20
#define pinstCVoiceMacroWnd_x                                      0xFB5F70
#define pinstCHtmlWnd_x                                            0xFB6060
#define pinstItemIconCache_x                                       0x10C3E28
#define pinstCTradeskillWnd_x                                      0x10C9B20
#define pinstCAdvancedLootWnd_x                                    0xE6E7C0
#define pinstRewardSelectionWnd_x                                  0x10C8258
#define pinstEQSuiteTextureLoader_x                                0xD19A88

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x549B70
#define __CastRay2_x                                               0x5494A0
#define __HeadingDiff_x                                            0x932B80
#define __FixHeading_x                                             0x932B10
#define __get_bearing_x                                            0x539410
#define __ConvertItemTags_x                                        0x536EF0
#define __ExecuteCmd_x                                             0x521820
#define __EQGetTime_x                                              0x8A1970
#define __get_melee_range_x                                        0x5284B0
#define __GetGaugeValueFromEQ_x                                    0x7B1D10
#define __GetLabelFromEQ_x                                         0x7B30E0
#define __ToggleKeyRingItem_x                                      0x48FB00
#define __GetXTargetType_x                                         0x934780
#define __LoadFrontEnd_x                                           0x63F070
#define __NewUIINI_x                                               0x7B16F0
#define __ProcessGameEvents_x                                      0x583860
#define __ProcessMouseEvent_x                                      0x583000
#define CrashDetected_x                                            0x640A30
#define wwsCrashReportCheckForUploader_x                           0x7FFB10
#define __AppCrashWrapper_x                                        0xC66AC4
#define __pCrashHandler_x                                          0x10D6A00
#define __CrashHandler_x                                           0x7FF5A0
#define wwsCrashReportPlatformLaunchUploader_x                     0x801D40
#define DrawNetStatus_x                                            0x5B9B20
#define Util__FastTime_x                                           0x8A1610
#define Expansion_HoT_x                                            0xF307D0
#define __HelpPath_x                                               0xFB3F80
#define __STMLToText_x                                             0x8E8170
#define __GetAnimationCache_x                                      0x6AE860

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423460
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E0D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DEA0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D7E80
#define AltAdvManager__IsAbilityReady_x                            0x4D7EF0
#define AltAdvManager__GetAAById_x                                 0x4D83E0
#define AltAdvManager__CanTrainAbility_x                           0x4D9010
#define AltAdvManager__CanSeeAbility_x                             0x4D8BD0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AFC0
#define CharacterZoneClient__HasSkill_x                            0x466ED0
#define CharacterZoneClient__MakeMeVisible_x                       0x46CB30
#define CharacterZoneClient__IsStackBlocked_x                      0x44BFC0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B4E0
#define CharacterZoneClient__GetItemCountWorn_x                    0x465430
#define CharacterZoneClient__GetItemCountInInventory_x             0x465510
#define CharacterZoneClient__GetCursorItemCount_x                  0x4655F0
#define CharacterZoneClient__FindAffectSlot_x                      0x451630
#define CharacterZoneClient__BardCastBard_x                        0x44AC50
#define CharacterZoneClient__GetMaxEffects_x                       0x4497E0
#define CharacterZoneClient__GetEffect_x                           0x44B710
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451490
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449B30
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FFE0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66E9D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67CA20

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x598930
#define CButtonWnd__CButtonWnd_x                                   0x8DC400

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x697A30
#define CChatManager__InitContextMenu_x                            0x698B80
#define CChatManager__FreeChatWindow_x                             0x6974E0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A0D20
#define CChatManager__SetLockedActiveChatWindow_x                  0x697A00

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E64C0
#define CContextMenu__dCContextMenu_x                              0x8E66D0
#define CContextMenu__AddMenuItem_x                                0x8E6BF0
#define CContextMenu__RemoveMenuItem_x                             0x8E6850
#define CContextMenu__RemoveAllMenuItems_x                         0x8E6870
#define CContextMenu__CheckMenuItem_x                              0x8E68F0
#define CContextMenu__SetMenuItem_x                                0x8E6770

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D29B0
#define CContextMenuManager__RemoveMenu_x                          0x8D2D60
#define CContextMenuManager__PopupMenu_x                           0x8D31B0
#define CContextMenuManager__Flush_x                               0x8D2A20
#define CContextMenuManager__GetMenu_x                             0x4195A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x885B80
#define CChatService__GetFriendName_x                              0x885B90

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69E7F0
#define CChatWindow__Clear_x                                       0x69E0D0
#define CChatWindow__WndNotification_x                             0x69F100

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D6810
#define CComboWnd__Draw_x                                          0x8D6A20
#define CComboWnd__GetCurChoice_x                                  0x8D65C0
#define CComboWnd__GetListRect_x                                   0x8D6CC0
#define CComboWnd__GetTextRect_x                                   0x8D6880
#define CComboWnd__InsertChoice_x                                  0x8D6E20
#define CComboWnd__SetColors_x                                     0x8D6550
#define CComboWnd__SetChoice_x                                     0x8D6580
#define CComboWnd__GetItemCount_x                                  0x8D65B0
#define CComboWnd__GetCurChoiceText_x                              0x8D6600


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A8A20
#define CContainerWnd__vftable_x                                   0xAEC9B0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C5DC0
#define CDisplay__GetClickedActor_x                                0x4BE680
#define CDisplay__GetUserDefinedColor_x                            0x4BD260
#define CDisplay__GetWorldFilePath_x                               0x4BC6B0
#define CDisplay__is3dON_x                                         0x4BBB40
#define CDisplay__ReloadUI_x                                       0x4CFB80
#define CDisplay__WriteTextHD2_x                                   0x4C2150
#define CDisplay__TrueDistance_x                                   0x4BF2B0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FD960

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EAA20
#define CEditWnd__GetCharIndexPt_x                                 0x8EBB70
#define CEditWnd__GetDisplayString_x                               0x8EABD0
#define CEditWnd__GetHorzOffset_x                                  0x8EAF10
#define CEditWnd__GetLineForPrintableChar_x                        0x8EB640
#define CEditWnd__GetSelStartPt_x                                  0x8EBE20
#define CEditWnd__GetSTMLSafeText_x                                0x8EB0B0
#define CEditWnd__PointFromPrintableChar_x                         0x8EB730
#define CEditWnd__SelectableCharFromPoint_x                        0x8EB8B0
#define CEditWnd__SetEditable_x                                    0x8EB080

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x569FB0
#define CEverQuest__ClickedPlayer_x                                0x563B80
#define CEverQuest__CreateTargetIndicator_x                        0x564A80
#define CEverQuest__DeleteTargetIndicator_x                        0x564B00
#define CEverQuest__DoTellWindow_x                                 0x476240
#define CEverQuest__OutputTextToLog_x                              0x475EA0
#define CEverQuest__DropHeldItemOnGround_x                         0x57A520
#define CEverQuest__dsp_chat_x                                     0x476580
#define CEverQuest__trimName_x                                     0x560490
#define CEverQuest__Emote_x                                        0x578830
#define CEverQuest__EnterZone_x                                    0x573910
#define CEverQuest__GetBodyTypeDesc_x                              0x55DED0
#define CEverQuest__GetClassDesc_x                                 0x5673C0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5679C0
#define CEverQuest__GetDeityDesc_x                                 0x55E7B0
#define CEverQuest__GetLangDesc_x                                  0x55E260
#define CEverQuest__GetRaceDesc_x                                  0x567B80
#define CEverQuest__InterpretCmd_x                                 0x56B730
#define CEverQuest__LeftClickedOnPlayer_x                          0x580070
#define CEverQuest__LMouseUp_x                                     0x582020
#define CEverQuest__RightClickedOnPlayer_x                         0x580B80
#define CEverQuest__RMouseUp_x                                     0x581A80
#define CEverQuest__SetGameState_x                                 0x564450
#define CEverQuest__UPCNotificationFlush_x                         0x55C860
#define CEverQuest__IssuePetCommand_x                              0x56C110

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B95E0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B9640
#define CGaugeWnd__Draw_x                                          0x6B9A70

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B300
#define CGuild__GetGuildName_x                                     0x43B7D0
#define CGuild__GetGuildIndex_x                                    0x43C9E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D5AF0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E2E70
#define CInvSlotMgr__MoveItem_x                                    0x6E3630
#define CInvSlotMgr__SelectSlot_x                                  0x6E2770

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E1BD0
#define CInvSlot__SliderComplete_x                                 0x6DF400
#define CInvSlot__GetItemBase_x                                    0x6DE8A0
#define CInvSlot__UpdateItem_x                                     0x6DEE20

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E4A50
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E5B90

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7ADB90
#define CItemDisplayWnd__UpdateStrings_x                           0x6E6CC0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F3520
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F3A40
#define CItemDisplayWnd__SetItem_x                                 0x6F9360

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E4A80

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6ED230

// CLabel 
#define CLabel__Draw_x                                             0x700160

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C22F0
#define CListWnd__dCListWnd_x                                      0x8C35A0
#define CListWnd__AddColumn_x                                      0x8C3540
#define CListWnd__AddColumn1_x                                     0x8C2BE0
#define CListWnd__AddLine_x                                        0x8C25C0
#define CListWnd__AddString_x                                      0x8C27E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BF3F0
#define CListWnd__CalculateVSBRange_x                              0x8C17B0
#define CListWnd__ClearSel_x                                       0x8BE700
#define CListWnd__ClearAllSel_x                                    0x8BE6B0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C2180
#define CListWnd__Compare_x                                        0x8C00E0
#define CListWnd__Draw_x                                           0x8C13B0
#define CListWnd__DrawColumnSeparators_x                           0x8C1240
#define CListWnd__DrawHeader_x                                     0x8BE9C0
#define CListWnd__DrawItem_x                                       0x8C0770
#define CListWnd__DrawLine_x                                       0x8C0EE0
#define CListWnd__DrawSeparator_x                                  0x8C12E0
#define CListWnd__EnableLine_x                                     0x8BE8E0
#define CListWnd__EnsureVisible_x                                  0x8BF550
#define CListWnd__ExtendSel_x                                      0x8C0680
#define CListWnd__GetColumnMinWidth_x                              0x8BDFF0
#define CListWnd__GetColumnWidth_x                                 0x8BDF20
#define CListWnd__GetCurSel_x                                      0x8BD6E0
#define CListWnd__GetItemAtPoint_x                                 0x8BF7F0
#define CListWnd__GetItemAtPoint1_x                                0x8BF860
#define CListWnd__GetItemData_x                                    0x8BDA30
#define CListWnd__GetItemHeight_x                                  0x8BF040
#define CListWnd__GetItemIcon_x                                    0x8BDC20
#define CListWnd__GetItemRect_x                                    0x8BF630
#define CListWnd__GetItemText_x                                    0x8BDAD0
#define CListWnd__GetSelList_x                                     0x8C2AD0
#define CListWnd__GetSeparatorRect_x                               0x8C0000
#define CListWnd__InsertLine_x                                     0x8C29C0
#define CListWnd__RemoveLine_x                                     0x8C29D0
#define CListWnd__SetColors_x                                      0x8BD830
#define CListWnd__SetColumnJustification_x                         0x8BE280
#define CListWnd__SetColumnWidth_x                                 0x8BDFA0
#define CListWnd__SetCurSel_x                                      0x8BD720
#define CListWnd__SetItemColor_x                                   0x8C1E70
#define CListWnd__SetItemData_x                                    0x8BE760
#define CListWnd__SetItemText_x                                    0x8C1CB0
#define CListWnd__ShiftColumnSeparator_x                           0x8C1B40
#define CListWnd__Sort_x                                           0x8C36A0
#define CListWnd__ToggleSel_x                                      0x8BE630

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x719310

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73E960
#define CMerchantWnd__RequestBuyItem_x                             0x746500
#define CMerchantWnd__RequestSellItem_x                            0x748B60
#define CMerchantWnd__SelectRecoverySlot_x                         0x73BC20
#define CMerchantWnd__SelectBuySellSlot_x                          0x739AB0
#define CMerchantWnd__ActualSelect_x                               0x740740

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x853EA0
#define CPacketScrambler__hton_x                                   0x853EB0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E13E0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E14C0
#define CSidlManager__CreateLabel_x                                0x7A2B90
#define CSidlManager__CreateXWndFromTemplate_x                     0x8DF970
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E17A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D8860
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D8750
#define CSidlScreenWnd__ConvertToRes_x                             0x8FD840
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9170
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DA340
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DA3F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D98D0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D8B20
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8280
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D8D10
#define CSidlScreenWnd__Init1_x                                    0x8DA020
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D9230
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8440
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D9B10
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D7EE0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8230
#define CSidlScreenWnd__WndNotification_x                          0x8D9DA0
#define CSidlScreenWnd__GetChildItem_x                             0x8D8350
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CBB60
#define CSidlScreenWnd__m_layoutCopy_x                             0x172FE40

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x604B50
#define CSkillMgr__GetSkillCap_x                                   0x604D30
#define CSkillMgr__GetNameToken_x                                  0x604700

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FCAF0
#define CSliderWnd__SetValue_x                                     0x8FCCC0
#define CSliderWnd__SetNumTicks_x                                  0x8FD440

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A8E70

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F64C0
#define CStmlWnd__CalculateHSBRange_x                              0x8EEA00
#define CStmlWnd__CalculateVSBRange_x                              0x8EE970
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EEB80
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EF380
#define CStmlWnd__ForceParseNow_x                                  0x8F6E40
#define CStmlWnd__GetNextTagPiece_x                                0x8EF280
#define CStmlWnd__GetSTMLText_x                                    0x4844A0
#define CStmlWnd__GetVisibleText_x                                 0x8EFDD0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F23A0
#define CStmlWnd__MakeStmlColorTag_x                               0x8EDC50
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EDCB0
#define CStmlWnd__SetSTMLText_x                                    0x8F3C00
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6160
#define CStmlWnd__UpdateHistoryString_x                            0x8F0D10

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FA360
#define CTabWnd__DrawCurrentPage_x                                 0x8F9BF0
#define CTabWnd__DrawTab_x                                         0x8F99B0
#define CTabWnd__GetCurrentPage_x                                  0x8F9FA0
#define CTabWnd__GetPageInnerRect_x                                0x8F96A0
#define CTabWnd__GetTabInnerRect_x                                 0x8F98A0
#define CTabWnd__GetTabRect_x                                      0x8F9770
#define CTabWnd__InsertPage_x                                      0x8FA650
#define CTabWnd__SetPage_x                                         0x8F9FD0
#define CTabWnd__SetPageRect_x                                     0x8FA2A0
#define CTabWnd__UpdatePage_x                                      0x8FA5F0
#define CTabWnd__GetPageFromTabIndex_x                             0x8F9900
#define CTabWnd__GetCurrentTabIndex_x                              0x8F9630

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E5D40
#define CPageWnd__SetTabText_x                                     0x906B60

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436F10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D61C0
#define CTextureFont__GetTextExtent_x                              0x8D5F20

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63D2F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x902FA0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BB730

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029E0
#define CXStr__CXStr1_x                                            0x4F90E0
#define CXStr__CXStr3_x                                            0x89E8A0
#define CXStr__dCXStr_x                                            0x402A20
#define CXStr__operator_equal_x                                    0x89EA10
#define CXStr__operator_equal1_x                                   0x89EA60
#define CXStr__operator_plus_equal1_x                              0x89FB60

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D3CD0
#define CXWnd__BringToTop_x                                        0x8CAD20
#define CXWnd__Center_x                                            0x8D0F90
#define CXWnd__ClrFocus_x                                          0x8CA900
#define CXWnd__Destroy_x                                           0x8D1A80
#define CXWnd__DoAllDrawing_x                                      0x8D0BE0
#define CXWnd__DrawChildren_x                                      0x8D0D80
#define CXWnd__DrawColoredRect_x                                   0x8CB100
#define CXWnd__DrawTooltip_x                                       0x8CB3B0
#define CXWnd__DrawTooltipAtPoint_x                                0x8CFB50
#define CXWnd__GetBorderFrame_x                                    0x8CB820
#define CXWnd__GetChildWndAt_x                                     0x8D1960
#define CXWnd__GetClientClipRect_x                                 0x8CB5D0
#define CXWnd__GetScreenClipRect_x                                 0x8D0250
#define CXWnd__GetScreenRect_x                                     0x8CB9F0
#define CXWnd__GetTooltipRect_x                                    0x8CB240
#define CXWnd__GetWindowTextA_x                                    0x426EA0
#define CXWnd__IsActive_x                                          0x8C6340
#define CXWnd__IsDescendantOf_x                                    0x8CB760
#define CXWnd__IsReallyVisible_x                                   0x8CEB80
#define CXWnd__IsType_x                                            0x8D1000
#define CScreenPieceTemplate__IsType_x                             0x8FF6B0
#define CXWnd__Move_x                                              0x8CE250
#define CXWnd__Move1_x                                             0x8D0880
#define CXWnd__ProcessTransition_x                                 0x8CACD0
#define CXWnd__Refade_x                                            0x8CAAA0
#define CXWnd__Resize_x                                            0x8CBAC0
#define CXWnd__Right_x                                             0x8D0050
#define CXWnd__SetFocus_x                                          0x8CD3C0
#define CXWnd__SetFont_x                                           0x8CA950
#define CXWnd__SetKeyTooltip_x                                     0x8CBD30
#define CXWnd__SetMouseOver_x                                      0x8D0580
#define CXWnd__StartFade_x                                         0x8CAD70
#define CXWnd__GetChildItem_x                                      0x8D04D0
#define CXWnd__SetParent_x                                         0x8D1910

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C7BF0
#define CXWndManager__DrawWindows_x                                0x8C7830
#define CXWndManager__GetKeyboardFlags_x                           0x8C5E80
#define CXWndManager__HandleKeyboardMsg_x                          0x8C67E0
#define CXWndManager__RemoveWnd_x                                  0x8C64D0

// CDBStr
#define CDBStr__GetString_x                                        0x4BA380

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4526F0
#define EQ_Character__Cur_HP_x                                     0x466AB0
#define EQ_Character__Cur_Mana_x                                   0x45BA90
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B7F0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443840
#define EQ_Character__GetFocusRangeModifier_x                      0x443990
#define EQ_Character__GetHPRegen_x                                 0x46A650
#define EQ_Character__GetEnduranceRegen_x                          0x4660C0
#define EQ_Character__GetManaRegen_x                               0x46ABF0
#define EQ_Character__Max_Endurance_x                              0x5CBA50
#define EQ_Character__Max_HP_x                                     0x45E610
#define EQ_Character__Max_Mana_x                                   0x5CB880
#define EQ_Character__doCombatAbility_x                            0x5C8F50
#define EQ_Character__UseSkill_x                                   0x4729E0
#define EQ_Character__GetConLevel_x                                0x5BE180
#define EQ_Character__IsExpansionFlag_x                            0x4B66A0
#define EQ_Character__TotalEffect_x                                0x44F920
#define EQ_Character__GetPCSpellAffect_x                           0x44BB80
#define EQ_Character__SpellDuration_x                              0x449B80
#define EQ_Character__FindItemByRecord_x                           0x464100
#define EQ_Character__GetAdjustedSkill_x                           0x466C80
#define EQ_Character__GetBaseSkill_x                               0x45E4F0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x871CB0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D40F0

//PcClient
#define PcClient__PcClient_x                                       0x5BFFD0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446CD0
#define CCharacterSelect__EnterWorld_x                             0x4464A0
#define CCharacterSelect__Quit_x                                   0x445060

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59E2F0
#define EQ_Item__CreateItemTagString_x                             0x8520C0
#define EQ_Item__IsStackable_x                                     0x847710
#define EQ_Item__GetImageNum_x                                     0x84A2B0
#define EQ_Item__CreateItemClient_x                                0x59F430
#define EQ_Item__GetItemValue_x                                    0x850B80
#define EQ_Item__ValueSellMerchant_x                               0x853B00
#define EQ_Item__IsKeyRingItem_x                                   0x8482A0
#define EQ_Item__CanGoInBag_x                                      0x59E480
#define EQ_Item__GetMaxItemCount_x                                 0x847600
#define EQ_Item__GetHeldItem_x                                     0x8490D0
#define EQ_Item__GetAugmentFitBySlot_x                             0x853930

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA4E0
#define EQ_LoadingS__Array_x                                       0xC0AC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CDF70
#define EQ_PC__GetAlternateAbilityId_x                             0x85BF30
#define EQ_PC__GetCombatAbility_x                                  0x85BFC0
#define EQ_PC__GetCombatAbilityTimer_x                             0x856B50
#define EQ_PC__GetItemRecastTimer_x                                0x5C7750
#define EQ_PC__HasLoreItem_x                                       0x5C1790
#define EQ_PC__AlertInventoryChanged_x                             0x5BE130
#define EQ_PC__GetPcZoneClient_x                                   0x5E8690
#define EQ_PC__RemoveMyAffect_x                                    0x5C6B80
#define EQ_PC__GetKeyRingItems_x                                   0x856F70
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x869CB0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85DF10

// EQItemList 
#define EQItemList__EQItemList_x                                   0x526540
#define EQItemList__add_object_x                                   0x553710
#define EQItemList__add_item_x                                     0x526480
#define EQItemList__delete_item_x                                  0x526930
#define EQItemList__FreeItemList_x                                 0x526830

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9670

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D3DB0
#define EQPlayer__dEQPlayer_x                                      0x5DC540
#define EQPlayer__DoAttack_x                                       0x5EDE50
#define EQPlayer__EQPlayer_x                                       0x5DEC70
#define EQPlayer__SetNameSpriteState_x                             0x5D9390
#define EQPlayer__SetNameSpriteTint_x                              0x5D52B0
#define PlayerBase__HasProperty_j_x                                0x930F80
#define EQPlayer__IsTargetable_x                                   0x931220
#define EQPlayer__CanSee_x                                         0x931780
#define PlayerZoneClient__ChangeHeight_x                           0x5EDD10
#define EQPlayer__CanSee1_x                                        0x931870
#define PlayerBase__GetVisibilityLineSegment_x                     0x931510

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E8840
#define PlayerZoneClient__IsValidTeleport_x                        0x553FB0
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2770


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E2CD0
#define EQPlayerManager__GetSpawnByName_x                          0x5E3130
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E2D00

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A4930
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A4970
#define KeypressHandler__ClearCommandStateArray_x                  0x5A4520
#define KeypressHandler__HandleKeyDown_x                           0x5A2E40
#define KeypressHandler__HandleKeyUp_x                             0x5A3160
#define KeypressHandler__SaveKeymapping_x                          0x5A45F0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x711CA0
#define MapViewMap__SaveEx_x                                       0x714FD0
#define MapViewMap__SetZoom_x                                      0x7118F0

#define PlayerPointManager__GetAltCurrency_x                       0x86FD70

// StringTable 
#define StringTable__getString_x                                   0x869FE0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CB4E0
#define PcZoneClient__RemovePetEffect_x                            0x5C7C20
#define PcZoneClient__HasAlternateAbility_x                        0x5C85C0
#define PcZoneClient__GetCurrentMod_x                              0x45DAC0
#define PcZoneClient__GetModCap_x                                  0x45B1F0
#define PcZoneClient__CanEquipItem_x                               0x5C8AA0
#define PcZoneClient__GetItemByID_x                                0x5CD2F0
#define PcZoneClient__GetItemByItemClass_x                         0x5CDE90
#define PcZoneClient__RemoveBuffEffect_x                           0x5C6E30

//Doors
#define EQSwitch__UseSwitch_x                                      0x55B0D0

//IconCache
#define IconCache__GetIcon_x                                       0x6AEE90

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A5DB0
#define CContainerMgr__CloseContainer_x                            0x6A65D0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x772B30

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x597350

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5010
#define EQ_Spell__SpellAffects_x                                   0x4F21F0
#define EQ_Spell__SpellAffectBase_x                                0x4F2260
#define CharacterZoneClient__CalcAffectChange_x                    0x44BA10
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44ACB0
#define CLootWnd__LootAll_x                                        0x707530
#define CLootWnd__RequestLootSlot_x                                0x707D40
#define EQ_Spell__IsStackable_x                                    0x4591C0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449650
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43ED90
#define EQ_Spell__IsSPAStacking_x                                  0x4F1D60
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2E00
#define EQ_Spell__IsNoRemove_x                                     0x434F30
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1D80

#define __IsResEffectSpell_x                                       0x4496D0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87B930

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BA770
#define CTargetWnd__WndNotification_x                              0x7BA260
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BA950

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7BF8D0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED860
#define EqSoundManager__PlayScriptMp3_x                            0x4EF300

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8730

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EA050
#define CSidlManager__FindAnimation1_x                             0x8DF3A0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E1F90
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1F40
#define CAltAbilityData__GetMaxRank_x                              0x4D6530

//CTargetRing
#define CTargetRing__Cast_x                                        0x594FB0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459500
#define CharacterBase__CreateItemGlobalIndex_x                     0x475410
#define CharacterBase__CreateItemIndex_x                           0x51FB50
#define CharacterBase__GetItemPossession_x                         0x444500
#define CharacterBase__GetItemByGlobalIndex_x                      0x87F770
#define CharacterBase__GetEffectId_x                               0x4594C0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68EC40
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68E3A0

//messages
#define msg_spell_worn_off_x                                       0x4FCAA0
#define msg_new_text_x                                             0x506220
#define msgTokenTextParam_x                                        0x502A20

//SpellManager
#define SpellManager__vftable_x                                    0xAC8258
#define SpellManager__SpellManager_x                               0x47E040
#define Spellmanager__LoadTextSpells_x                             0x60BA50

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9352A0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487AD0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43ECB0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4493B0
#define ItemGlobalIndex__IsValidIndex_x                            0x458D00

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87D5F0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87C530

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7003B0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AAAE0
#define CCursorAttachment__Deactivate_x                            0x6AA020

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FBFF0
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FC170

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x603720

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C350

//IString
#define IString__Append_x                                          0x47ECE0

//Camera
#define CDisplay__cameraType_x                                     0xE6E7E8
#define EverQuest__Cameras_x                                       0xF30AE8
