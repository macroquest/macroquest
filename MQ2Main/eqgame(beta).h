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
#define __ExpectedVersionDate                                     "Nov  9 2017"
#define __ExpectedVersionTime                                     "04:16:03"
#define __ActualVersionDate_x                                      0xAE30C8
#define __ActualVersionTime_x                                      0xAE30D4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5A9FC0
#define __MemChecker1_x                                            0x8A2D40
#define __MemChecker2_x                                            0x63F940
#define __MemChecker3_x                                            0x63F890
#define __MemChecker4_x                                            0x7F48F0
#define __EncryptPad0_x                                            0xC3DFE8
#define __EncryptPad1_x                                            0xD17BA0
#define __EncryptPad2_x                                            0xC66ED0
#define __EncryptPad3_x                                            0xC66AD0
#define __EncryptPad4_x                                            0xD061A0
#define __EncryptPad5_x                                            0x10C12C0
#define __AC1_x                                                    0x7B3845
#define __AC2_x                                                    0x563207
#define __AC3_x                                                    0x561380
#define __AC4_x                                                    0x573541
#define __AC5_x                                                    0x58729B
#define __AC6_x                                                    0x58AE3E
#define __AC7_x                                                    0x58189C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA4920

// Direct Input
#define DI8__Main_x                                                0x10C1298
#define DI8__Keyboard_x                                            0x10C129C
#define DI8__Mouse_x                                               0x10C12A0
#define DI8__Mouse_Copy_x                                          0xF2F454
#define DI8__Mouse_Check_x                                         0xFB8F84
#define __AutoSkillArray_x                                         0xF30368
#define __Attack_x                                                 0xFB3A5B
#define __Autofire_x                                               0xFB3A5C
#define __BindList_x                                               0xC1A368
#define g_eqCommandStates_x                                        0xF1E1A0
#define __Clicks_x                                                 0xF2F510
#define __CommandList_x                                            0xC1CA80
#define __CurrentMapLabel_x                                        0x10C7290
#define __CurrentSocial_x                                          0xBE98E8
#define __DoAbilityList_x                                          0xF65C20
#define __do_loot_x                                                0x5320A0
#define __DrawHandler_x                                            0x1730F0C
#define __GroupCount_x                                             0xF1FAAA

#define __Guilds_x                                                 0xF256C0
#define __gWorld_x                                                 0xF21F64
#define __HotkeyPage_x                                             0xFAC620
#define __HWnd_x                                                   0xFB90A0
#define __InChatMode_x                                             0xF2F43C
#define __LastTell_x                                               0xF3131C
#define __LMouseHeldTime_x                                         0xF2F57C
#define __Mouse_x                                                  0x10C12A4
#define __MouseLook_x                                              0xF2F4D6
#define __MouseEventTime_x                                         0xFB41F4
#define __gpbCommandEvent_x                                        0xF2202C
#define __NetStatusToggle_x                                        0xF2F4D9
#define __PCNames_x                                                0xF30924
#define __RangeAttackReady_x                                       0xF3064C
#define __RMouseHeldTime_x                                         0xF2F578
#define __RunWalkState_x                                           0xF2F440
#define __ScreenMode_x                                             0xE6DD80
#define __ScreenX_x                                                0xF2F3F4
#define __ScreenY_x                                                0xF2F3F0
#define __ScreenXMax_x                                             0xF2F3F8
#define __ScreenYMax_x                                             0xF2F3FC
#define __ServerHost_x                                             0xF1F9F4
#define __ServerName_x                                             0xF65BE0
#define __ShiftKeyDown_x                                           0xF2FAD0
#define __ShowNames_x                                              0xF30804
#define __Socials_x                                                0xF65CE0
#define __SubscriptionType_x                                       0x10F7A14
#define __TargetAggroHolder_x                                      0x10C93EC
#define __ZoneType_x                                               0xF2F8D4
#define __GroupAggro_x                                             0x10C942C
#define __LoginName_x                                              0xFB7B7C
#define __Inviter_x                                                0xFB39D8
#define __AttackOnAssist_x                                         0xF307C0
#define __UseTellWindows_x                                         0xF30ABC

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF22050
#define instEQZoneInfo_x                                           0xF2F6CC
#define instKeypressHandler_x                                      0xFB41D8
#define pinstActiveBanker_x                                        0xF22008
#define pinstActiveCorpse_x                                        0xF2200C
#define pinstActiveGMaster_x                                       0xF22010
#define pinstActiveMerchant_x                                      0xF22004
#define pinstAggroInfo_x                                           0xD2B3EC
#define pinstAltAdvManager_x                                       0xE6EEE8
#define pinstAuraMgr_x                                             0xD3BBF0
#define pinstBandageTarget_x                                       0xF21FF0
#define pinstCamActor_x                                            0xE6E7B8
#define pinstCDBStr_x                                              0xE6DD14
#define pinstCDisplay_x                                            0xF22018
#define pinstCEverQuest_x                                          0x10C1418
#define pinstEverQuestInfo_x                                       0xF2F3E8
#define pinstCharData_x                                            0xF21FD4
#define pinstCharSpawn_x                                           0xF21FFC
#define pinstControlledMissile_x                                   0xF21FD0
#define pinstControlledPlayer_x                                    0xF21FFC
#define pinstCSidlManager_x                                        0x172FE78
#define pinstCXWndManager_x                                        0x172FE70
#define instDynamicZone_x                                          0xF2F288
#define pinstDZMember_x                                            0xF2F398
#define pinstDZTimerInfo_x                                         0xF2F39C
#define pinstEQItemList_x                                          0xF1E478
#define pinstEQObjectList_x                                        0xF1F4A4
#define instEQMisc_x                                               0xC027A8
#define pinstEQSoundManager_x                                      0xE6F4B8
#define instExpeditionLeader_x                                     0xF2F2D2
#define instExpeditionName_x                                       0xF2F312
#define pinstGroup_x                                               0xF1FAA6
#define pinstImeManager_x                                          0x172FE7C
#define pinstLocalPlayer_x                                         0xF21FE8
#define pinstMercenaryData_x                                       0xFB4840
#define pinstMercenaryStats_x                                      0x10C9538
#define pinstMercAltAbilities_x                                    0xE6F270
#define pinstModelPlayer_x                                         0xF22014
#define pinstPCData_x                                              0xF21FD4
#define pinstSkillMgr_x                                            0xFB5838
#define pinstSpawnManager_x                                        0xFB5090
#define pinstSpellManager_x                                        0xFB5980
#define pinstSpellSets_x                                           0xFAC684
#define pinstStringTable_x                                         0xF21F7C
#define pinstSwitchManager_x                                       0xF1F638
#define pinstTarget_x                                              0xF22000
#define pinstTargetObject_x                                        0xF21FD8
#define pinstTargetSwitch_x                                        0xF21FDC
#define pinstTaskMember_x                                          0xE6DC60
#define pinstTrackTarget_x                                         0xF21FF4
#define pinstTradeTarget_x                                         0xF21FE4
#define instTributeActive_x                                        0xC027CD
#define pinstViewActor_x                                           0xE6E7B4
#define pinstWorldData_x                                           0xF21FB8
#define pinstZoneAddr_x                                            0xF2F96C
#define pinstPlayerPath_x                                          0xFB50F0
#define pinstTargetIndicator_x                                     0xFB5B18
#define pinstCTargetManager_x                                      0xFB5B78
#define EQObject_Top_x                                             0xF21FC8
#define pinstRealEstateItems_x                                     0xFB56A4
 
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE6E6D0
#define pinstCAchievementsWnd_x                                    0xE6E72C
#define pinstCTextOverlay_x                                        0xD2B980
#define pinstCAudioTriggersWindow_x                                0xD2B768
#define pinstCCharacterSelect_x                                    0xE6E63C
#define pinstCFacePick_x                                           0xE6E3EC
#define pinstCFindItemWnd_x                                        0xE6E6CC
#define pinstCNoteWnd_x                                            0xE6E5F4
#define pinstCBookWnd_x                                            0xE6E5FC
#define pinstCPetInfoWnd_x                                         0xE6E600
#define pinstCTrainWnd_x                                           0xE6E604
#define pinstCSkillsWnd_x                                          0xE6E608
#define pinstCSkillsSelectWnd_x                                    0xE6E60C
#define pinstCCombatSkillsSelectWnd_x                              0xE6E610
#define pinstCFriendsWnd_x                                         0xE6E614
#define pinstCAuraWnd_x                                            0xE6E618
#define pinstCRespawnWnd_x                                         0xE6E61C
#define pinstCBandolierWnd_x                                       0xE6E620
#define pinstCPotionBeltWnd_x                                      0xE6E624
#define pinstCAAWnd_x                                              0xE6E628
#define pinstCAlarmWnd_x                                           0xE6E634
#define pinstCGroupSearchFiltersWnd_x                              0xE6E62C
#define pinstCLoadskinWnd_x                                        0xE6E630
#define pinstCLargeDialogWnd_x                                     0x10C8498
#define pinstCMusicPlayerWnd_x                                     0xE6E638
#define pinstCMailWnd_x                                            0xE6E640
#define pinstCMailCompositionWnd_x                                 0xE6E644
#define pinstCMailAddressBookWnd_x                                 0xE6E648
#define pinstCRaidWnd_x                                            0xE6E650
#define pinstCRaidOptionsWnd_x                                     0xE6E654
#define pinstCBreathWnd_x                                          0xE6E658
#define pinstCMapViewWnd_x                                         0xE6E65C
#define pinstCMapToolbarWnd_x                                      0xE6E660
#define pinstCEditLabelWnd_x                                       0xE6E664
#define pinstCTargetWnd_x                                          0xE6E668
#define pinstCColorPickerWnd_x                                     0xE6E66C
#define pinstCPlayerWnd_x                                          0xE6E670
#define pinstCOptionsWnd_x                                         0xE6E674
#define pinstCBuffWindowNORMAL_x                                   0xE6E678
#define pinstCBuffWindowSHORT_x                                    0xE6E67C
#define pinstCharacterCreation_x                                   0xE6E680
#define pinstCCursorAttachment_x                                   0xE6E684
#define pinstCCastingWnd_x                                         0xE6E688
#define pinstCCastSpellWnd_x                                       0xE6E68C
#define pinstCSpellBookWnd_x                                       0xE6E690
#define pinstCInventoryWnd_x                                       0xE6E694
#define pinstCBankWnd_x                                            0xE6E69C
#define pinstCQuantityWnd_x                                        0xE6E6A0
#define pinstCLootWnd_x                                            0xE6E6A4
#define pinstCActionsWnd_x                                         0xE6E6A8
#define pinstCCombatAbilityWnd_x                                   0xE6E6B0
#define pinstCMerchantWnd_x                                        0xE6E6B4
#define pinstCTradeWnd_x                                           0xE6E6BC
#define pinstCSelectorWnd_x                                        0xE6E6C0
#define pinstCBazaarWnd_x                                          0xE6E6C4
#define pinstCBazaarSearchWnd_x                                    0xE6E6C8
#define pinstCGiveWnd_x                                            0xE6E6E8
#define pinstCTrackingWnd_x                                        0xE6E6F0
#define pinstCInspectWnd_x                                         0xE6E6F4
#define pinstCSocialEditWnd_x                                      0xE6E6F8
#define pinstCFeedbackWnd_x                                        0xE6E6FC
#define pinstCBugReportWnd_x                                       0xE6E700
#define pinstCVideoModesWnd_x                                      0xE6E704
#define pinstCTextEntryWnd_x                                       0xE6E70C
#define pinstCFileSelectionWnd_x                                   0xE6E710
#define pinstCCompassWnd_x                                         0xE6E714
#define pinstCPlayerNotesWnd_x                                     0xE6E718
#define pinstCGemsGameWnd_x                                        0xE6E71C
#define pinstCTimeLeftWnd_x                                        0xE6E738
#define pinstCPetitionQWnd_x                                       0xE6E73C
#define pinstCStoryWnd_x                                           0xE6E740
#define pinstCJournalTextWnd_x                                     0xE6E744
#define pinstCJournalCatWnd_x                                      0xE6E748
#define pinstCBodyTintWnd_x                                        0xE6E74C
#define pinstCServerListWnd_x                                      0xE6E750
#define pinstCAvaZoneWnd_x                                         0xE6E75C
#define pinstCBlockedBuffWnd_x                                     0xE6E760
#define pinstCBlockedPetBuffWnd_x                                  0xE6E764
#define pinstCInvSlotMgr_x                                         0xE6E7AC
#define pinstCContainerMgr_x                                       0xE6E7B0
#define pinstCAdventureLeaderboardWnd_x                            0x10C1DC8
#define pinstCAdventureRequestWnd_x                                0x10C1E40
#define pinstCAltStorageWnd_x                                      0x10C2120
#define pinstCAdventureStatsWnd_x                                  0x10C1EB8
#define pinstCBarterMerchantWnd_x                                  0x10C2E68
#define pinstCBarterSearchWnd_x                                    0x10C2EE0
#define pinstCBarterWnd_x                                          0x10C2F58
#define pinstCChatWindowManager_x                                  0x10C3768
#define pinstCDynamicZoneWnd_x                                     0x10C3C98
#define pinstCEQMainWnd_x                                          0x10C3E60
#define pinstCFellowshipWnd_x                                      0x10C3C2C
#define pinstCFindLocationWnd_x                                    0x10C4130
#define pinstCGroupSearchWnd_x                                     0x10C4400
#define pinstCGroupWnd_x                                           0x10C4478
#define pinstCGuildBankWnd_x                                       0x10C44F0
#define pinstCGuildMgmtWnd_x                                       0x10C65E0
#define pinstCHotButtonWnd_x                                       0x10C66DC
#define pinstCHotButtonWnd1_x                                      0x10C66DC
#define pinstCHotButtonWnd2_x                                      0x10C66E0
#define pinstCHotButtonWnd3_x                                      0x10C66E4
#define pinstCHotButtonWnd4_x                                      0x10C6708
#define pinstCItemDisplayManager_x                                 0x10C6B60
#define pinstCItemExpTransferWnd_x                                 0x10C6C5C
#define pinstCLFGuildWnd_x                                         0x10C6F38
#define pinstCMIZoneSelectWnd_x                                    0x10C7518
#define pinstCConfirmationDialog_x                                 0x10C7B30
#define pinstCPopupWndManager_x                                    0x10C7B30
#define pinstCProgressionSelectionWnd_x                            0x10C7C20
#define pinstCPvPStatsWnd_x                                        0x10C7D10
#define pinstCTaskWnd_x                                            0x10C9818
#define pinstCTaskSomething_x                                      0xD3C808
#define pinstCTaskTemplateSelectWnd_x                              0x10C97A0
#define pinstCTipWndOFDAY_x                                        0x10C9980
#define pinstCTipWndCONTEXT_x                                      0x10C9984
#define pinstCTitleWnd_x                                           0x10C9A00
#define pinstCContextMenuManager_x                                 0x172FD00
#define pinstCVoiceMacroWnd_x                                      0xFB5F50
#define pinstCHtmlWnd_x                                            0xFB6040
#define pinstItemIconCache_x                                       0x10C3E08
#define pinstCTradeskillWnd_x                                      0x10C9B00
#define pinstCAdvancedLootWnd_x                                    0xE6E7A0
#define pinstRewardSelectionWnd_x                                  0x10C8238
#define pinstEQSuiteTextureLoader_x                                0xD19A68

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x549A30
#define __CastRay2_x                                               0x549360
#define __HeadingDiff_x                                            0x932FD0
#define __FixHeading_x                                             0x932F60
#define __get_bearing_x                                            0x5391F0
#define __ConvertItemTags_x                                        0x536CC0
#define __ExecuteCmd_x                                             0x521630
#define __EQGetTime_x                                              0x8A26E0
#define __get_melee_range_x                                        0x5282C0
#define __GetGaugeValueFromEQ_x                                    0x7B2400
#define __GetLabelFromEQ_x                                         0x7B37D0
#define __ToggleKeyRingItem_x                                      0x48FA30
#define __GetXTargetType_x                                         0x934BD0
#define __LoadFrontEnd_x                                           0x63F010
#define __NewUIINI_x                                               0x7B1DE0
#define __ProcessGameEvents_x                                      0x583630
#define __ProcessMouseEvent_x                                      0x582DD0
#define CrashDetected_x                                            0x6409D0
#define wwsCrashReportCheckForUploader_x                           0x800400
#define __AppCrashWrapper_x                                        0xC66AC4
#define __pCrashHandler_x                                          0x10D69E0
#define __CrashHandler_x                                           0x7FFE90
#define wwsCrashReportPlatformLaunchUploader_x                     0x802640
#define DrawNetStatus_x                                            0x5B9A20
#define Util__FastTime_x                                           0x8A2380
#define Expansion_HoT_x                                            0xF307B0
#define __HelpPath_x                                               0xFB3F60
#define __STMLToText_x                                             0x8E8CC0
#define __GetAnimationCache_x                                      0x6AE750

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423390
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DFF0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DDC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D7D30
#define AltAdvManager__IsAbilityReady_x                            0x4D7DA0
#define AltAdvManager__GetAAById_x                                 0x4D8290
#define AltAdvManager__CanTrainAbility_x                           0x4D8EC0
#define AltAdvManager__CanSeeAbility_x                             0x4D8A80

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AF00
#define CharacterZoneClient__HasSkill_x                            0x466DE0
#define CharacterZoneClient__MakeMeVisible_x                       0x46CA70
#define CharacterZoneClient__IsStackBlocked_x                      0x44BDE0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B300
#define CharacterZoneClient__GetItemCountWorn_x                    0x465340
#define CharacterZoneClient__GetItemCountInInventory_x             0x465420
#define CharacterZoneClient__GetCursorItemCount_x                  0x465500
#define CharacterZoneClient__FindAffectSlot_x                      0x451490
#define CharacterZoneClient__BardCastBard_x                        0x44AA70
#define CharacterZoneClient__GetMaxEffects_x                       0x449600
#define CharacterZoneClient__GetEffect_x                           0x44B530
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4512F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449950
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FE40

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66E9E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67C6F0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x598710
#define CButtonWnd__CButtonWnd_x                                   0x8DCED0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x697930
#define CChatManager__InitContextMenu_x                            0x698A80
#define CChatManager__FreeChatWindow_x                             0x6973E0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A0BF0
#define CChatManager__SetLockedActiveChatWindow_x                  0x697900

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E7020
#define CContextMenu__dCContextMenu_x                              0x8E7230
#define CContextMenu__AddMenuItem_x                                0x8E7740
#define CContextMenu__RemoveMenuItem_x                             0x8E73A0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E73C0
#define CContextMenu__CheckMenuItem_x                              0x8E7440

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D3410
#define CContextMenuManager__RemoveMenu_x                          0x8D37C0
#define CContextMenuManager__PopupMenu_x                           0x8D3C10
#define CContextMenuManager__Flush_x                               0x8D3480
#define CContextMenuManager__GetMenu_x                             0x419510

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x848340
#define CChatService__GetFriendName_x                              0x886840

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69E6D0
#define CChatWindow__Clear_x                                       0x69DFC0
#define CChatWindow__WndNotification_x                             0x69EFD0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D7290
#define CComboWnd__Draw_x                                          0x8D74A0
#define CComboWnd__GetCurChoice_x                                  0x8D7040
#define CComboWnd__GetListRect_x                                   0x8D7740
#define CComboWnd__GetTextRect_x                                   0x8D7300
#define CComboWnd__InsertChoice_x                                  0x8D78A0
#define CComboWnd__SetColors_x                                     0x8D6FD0
#define CComboWnd__SetChoice_x                                     0x8D7000
#define CComboWnd__GetItemCount_x                                  0x8D7030
#define CComboWnd__GetCurChoiceText_x                              0x8D7080


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A88F0
#define CContainerWnd__vftable_x                                   0xAEC9E0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C5BD0
#define CDisplay__GetClickedActor_x                                0x4BE490
#define CDisplay__GetUserDefinedColor_x                            0x4BD070
#define CDisplay__GetWorldFilePath_x                               0x4BC4C0
#define CDisplay__is3dON_x                                         0x4BB950
#define CDisplay__ReloadUI_x                                       0x4CF990
#define CDisplay__WriteTextHD2_x                                   0x4C1F60
#define CDisplay__TrueDistance_x                                   0x4BF0C0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FE350

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EB570
#define CEditWnd__GetCharIndexPt_x                                 0x8EC6B0
#define CEditWnd__GetDisplayString_x                               0x8EB720
#define CEditWnd__GetHorzOffset_x                                  0x8EBA60
#define CEditWnd__GetLineForPrintableChar_x                        0x8EC180
#define CEditWnd__GetSelStartPt_x                                  0x8EC960
#define CEditWnd__GetSTMLSafeText_x                                0x8EBBF0
#define CEditWnd__PointFromPrintableChar_x                         0x8EC270
#define CEditWnd__SelectableCharFromPoint_x                        0x8EC3F0
#define CEditWnd__SetEditable_x                                    0x8EBBC0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x569D70
#define CEverQuest__ClickedPlayer_x                                0x563950
#define CEverQuest__CreateTargetIndicator_x                        0x564850
#define CEverQuest__DeleteTargetIndicator_x                        0x5648D0
#define CEverQuest__DoTellWindow_x                                 0x476170
#define CEverQuest__OutputTextToLog_x                              0x475DD0
#define CEverQuest__DropHeldItemOnGround_x                         0x57A2E0
#define CEverQuest__dsp_chat_x                                     0x4764B0
#define CEverQuest__trimName_x                                     0x560260
#define CEverQuest__Emote_x                                        0x5785F0
#define CEverQuest__EnterZone_x                                    0x5736D0
#define CEverQuest__GetBodyTypeDesc_x                              0x55DCA0
#define CEverQuest__GetClassDesc_x                                 0x567190
#define CEverQuest__GetClassThreeLetterCode_x                      0x567790
#define CEverQuest__GetDeityDesc_x                                 0x55E580
#define CEverQuest__GetLangDesc_x                                  0x55E030
#define CEverQuest__GetRaceDesc_x                                  0x567950
#define CEverQuest__InterpretCmd_x                                 0x56B4F0
#define CEverQuest__LeftClickedOnPlayer_x                          0x57FE40
#define CEverQuest__LMouseUp_x                                     0x581DF0
#define CEverQuest__RightClickedOnPlayer_x                         0x580950
#define CEverQuest__RMouseUp_x                                     0x581850
#define CEverQuest__SetGameState_x                                 0x564220
#define CEverQuest__UPCNotificationFlush_x                         0x55C630
#define CEverQuest__IssuePetCommand_x                              0x56BED0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B95C0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B9620
#define CGaugeWnd__Draw_x                                          0x6B9A50

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B0B0
#define CGuild__GetGuildName_x                                     0x43B580
#define CGuild__GetGuildIndex_x                                    0x43C790

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D5AC0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E2E70
#define CInvSlotMgr__MoveItem_x                                    0x6E3630
#define CInvSlotMgr__SelectSlot_x                                  0x6E2770

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E1BD0
#define CInvSlot__SliderComplete_x                                 0x6DF3F0
#define CInvSlot__GetItemBase_x                                    0x6DE850
#define CInvSlot__UpdateItem_x                                     0x6DEDD0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E4A90
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E5BC0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AE320
#define CItemDisplayWnd__UpdateStrings_x                           0x6E6D10
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F3910
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F3E20
#define CItemDisplayWnd__SetItem_x                                 0x6F9750

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E5340

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6ED2B0

// CLabel 
#define CLabel__Draw_x                                             0x700520

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C2FF0
#define CListWnd__dCListWnd_x                                      0x8C42A0
#define CListWnd__AddColumn_x                                      0x8C4240
#define CListWnd__AddColumn1_x                                     0x8C38D0
#define CListWnd__AddLine_x                                        0x8C32B0
#define CListWnd__AddString_x                                      0x8C34D0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C0120
#define CListWnd__CalculateVSBRange_x                              0x8C24C0
#define CListWnd__ClearSel_x                                       0x8BF440
#define CListWnd__ClearAllSel_x                                    0x8BF3F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C2E80
#define CListWnd__Compare_x                                        0x8C0E10
#define CListWnd__Draw_x                                           0x8C20D0
#define CListWnd__DrawColumnSeparators_x                           0x8C1F60
#define CListWnd__DrawHeader_x                                     0x8BF700
#define CListWnd__DrawItem_x                                       0x8C14A0
#define CListWnd__DrawLine_x                                       0x8C1C00
#define CListWnd__DrawSeparator_x                                  0x8C2000
#define CListWnd__EnableLine_x                                     0x8BF620
#define CListWnd__EnsureVisible_x                                  0x8C0280
#define CListWnd__ExtendSel_x                                      0x8C13B0
#define CListWnd__GetColumnMinWidth_x                              0x8BED30
#define CListWnd__GetColumnWidth_x                                 0x8BEC60
#define CListWnd__GetCurSel_x                                      0x8BE430
#define CListWnd__GetItemAtPoint_x                                 0x8C0510
#define CListWnd__GetItemAtPoint1_x                                0x8C0580
#define CListWnd__GetItemData_x                                    0x8BE770
#define CListWnd__GetItemHeight_x                                  0x8BFD80
#define CListWnd__GetItemIcon_x                                    0x8BE960
#define CListWnd__GetItemRect_x                                    0x8C0350
#define CListWnd__GetItemText_x                                    0x8BE810
#define CListWnd__GetSelList_x                                     0x8C37C0
#define CListWnd__GetSeparatorRect_x                               0x8C0D30
#define CListWnd__InsertLine_x                                     0x8C36B0
#define CListWnd__RemoveLine_x                                     0x8C36C0
#define CListWnd__SetColors_x                                      0x8BE580
#define CListWnd__SetColumnJustification_x                         0x8BEFC0
#define CListWnd__SetColumnWidth_x                                 0x8BECE0
#define CListWnd__SetCurSel_x                                      0x8BE470
#define CListWnd__SetItemColor_x                                   0x8C2B70
#define CListWnd__SetItemData_x                                    0x8BF4A0
#define CListWnd__SetItemText_x                                    0x8C29B0
#define CListWnd__ShiftColumnSeparator_x                           0x8C2840
#define CListWnd__Sort_x                                           0x8C43A0
#define CListWnd__ToggleSel_x                                      0x8BF370

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x719550

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73EC00
#define CMerchantWnd__RequestBuyItem_x                             0x746A50
#define CMerchantWnd__RequestSellItem_x                            0x749140
#define CMerchantWnd__SelectRecoverySlot_x                         0x73BF20
#define CMerchantWnd__SelectBuySellSlot_x                          0x739E70
#define CMerchantWnd__ActualSelect_x                               0x740990

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x854AA0
#define CPacketScrambler__hton_x                                   0x854AB0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E1ED0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1FB0
#define CSidlManager__CreateLabel_x                                0x7A3230
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E0480
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E2290

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D9300
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D9200
#define CSidlScreenWnd__ConvertToRes_x                             0x8FE230
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9C10
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DAE00
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DAEB0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DA380
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D95C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8D30
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D97B0
#define CSidlScreenWnd__Init1_x                                    0x8DAAD0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D9CD0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8EF0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DA5C0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D8980
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8CE0
#define CSidlScreenWnd__WndNotification_x                          0x8DA850
#define CSidlScreenWnd__GetChildItem_x                             0x8D8E00
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CC730
#define CSidlScreenWnd__m_layoutCopy_x                             0x172FE20

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6049A0
#define CSkillMgr__GetSkillCap_x                                   0x604B80
#define CSkillMgr__GetNameToken_x                                  0x604550

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FD4E0
#define CSliderWnd__SetValue_x                                     0x8FD6B0
#define CSliderWnd__SetNumTicks_x                                  0x8FDE30

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A9510

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6FB0
#define CStmlWnd__CalculateHSBRange_x                              0x8EF520
#define CStmlWnd__CalculateVSBRange_x                              0x8EF490
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EF6A0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EFEA0
#define CStmlWnd__ForceParseNow_x                                  0x8F7930
#define CStmlWnd__GetNextTagPiece_x                                0x8EFDA0
#define CStmlWnd__GetSTMLText_x                                    0x4843A0
#define CStmlWnd__GetVisibleText_x                                 0x8F08F0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2EC0
#define CStmlWnd__MakeStmlColorTag_x                               0x8EE770
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EE7D0
#define CStmlWnd__SetSTMLText_x                                    0x8F4710
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6C50
#define CStmlWnd__UpdateHistoryString_x                            0x8F1830

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FAE60
#define CTabWnd__DrawCurrentPage_x                                 0x8FA6F0
#define CTabWnd__DrawTab_x                                         0x8FA4C0
#define CTabWnd__GetCurrentPage_x                                  0x8FAAA0
#define CTabWnd__GetPageInnerRect_x                                0x8FA1B0
#define CTabWnd__GetTabInnerRect_x                                 0x8FA3B0
#define CTabWnd__GetTabRect_x                                      0x8FA280
#define CTabWnd__InsertPage_x                                      0x8FB150
#define CTabWnd__SetPage_x                                         0x8FAAD0
#define CTabWnd__SetPageRect_x                                     0x8FADA0
#define CTabWnd__UpdatePage_x                                      0x8FB0F0
#define CTabWnd__GetPageFromTabIndex_x                             0x8FA410
#define CTabWnd__GetCurrentTabIndex_x                              0x8FA140

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E5D70
#define CPageWnd__SetTabText_x                                     0x907570

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436CD0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D6C40
#define CTextureFont__GetTextExtent_x                              0x8D69A0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63D2B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x9039B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BC530

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5A6490
#define CXStr__CXStr1_x                                            0x8B1190
#define CXStr__CXStr3_x                                            0x89F610
#define CXStr__dCXStr_x                                            0x47C0D0
#define CXStr__operator_equal_x                                    0x89F780
#define CXStr__operator_equal1_x                                   0x89F7D0
#define CXStr__operator_plus_equal1_x                              0x8A08D0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D4750
#define CXWnd__BringToTop_x                                        0x8CB960
#define CXWnd__Center_x                                            0x8D1A40
#define CXWnd__ClrFocus_x                                          0x8CB550
#define CXWnd__Destroy_x                                           0x8D2500
#define CXWnd__DoAllDrawing_x                                      0x8D1690
#define CXWnd__DrawChildren_x                                      0x8D1830
#define CXWnd__DrawColoredRect_x                                   0x8CBD20
#define CXWnd__DrawTooltip_x                                       0x8CBFD0
#define CXWnd__DrawTooltipAtPoint_x                                0x8D0640
#define CXWnd__GetBorderFrame_x                                    0x8CC420
#define CXWnd__GetChildWndAt_x                                     0x8D23E0
#define CXWnd__GetClientClipRect_x                                 0x8CC1E0
#define CXWnd__GetScreenClipRect_x                                 0x8D0D30
#define CXWnd__GetScreenRect_x                                     0x8CC5D0
#define CXWnd__GetTooltipRect_x                                    0x8CBE60
#define CXWnd__GetWindowTextA_x                                    0x426F80
#define CXWnd__IsActive_x                                          0x8C7050
#define CXWnd__IsDescendantOf_x                                    0x8CC370
#define CXWnd__IsReallyVisible_x                                   0x8CF680
#define CXWnd__IsType_x                                            0x8D1AB0
#define CScreenPieceTemplate__IsType_x                             0x9000C0
#define CXWnd__Move_x                                              0x8CED80
#define CXWnd__Move1_x                                             0x8D1340
#define CXWnd__ProcessTransition_x                                 0x8CB910
#define CXWnd__Refade_x                                            0x8CB6E0
#define CXWnd__Resize_x                                            0x8CC690
#define CXWnd__Right_x                                             0x8D0B30
#define CXWnd__SetFocus_x                                          0x8CDEE0
#define CXWnd__SetFont_x                                           0x8CB5A0
#define CXWnd__SetKeyTooltip_x                                     0x8CC900
#define CXWnd__SetMouseOver_x                                      0x8D1050
#define CXWnd__StartFade_x                                         0x8CB9B0
#define CXWnd__GetChildItem_x                                      0x8D0F90
#define CXWnd__SetParent_x                                         0x8D2390

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C88E0
#define CXWndManager__DrawWindows_x                                0x8C8520
#define CXWndManager__GetKeyboardFlags_x                           0x8C6B80
#define CXWndManager__HandleKeyboardMsg_x                          0x8C74E0
#define CXWndManager__RemoveWnd_x                                  0x8C71E0

// CDBStr
#define CDBStr__GetString_x                                        0x4BA1C0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452550
#define EQ_Character__Cur_HP_x                                     0x4669C0
#define EQ_Character__Cur_Mana_x                                   0x45B9B0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B610
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443550
#define EQ_Character__GetFocusRangeModifier_x                      0x4436A0
#define EQ_Character__GetHPRegen_x                                 0x46A590
#define EQ_Character__GetEnduranceRegen_x                          0x465FD0
#define EQ_Character__GetManaRegen_x                               0x46AB30
#define EQ_Character__Max_Endurance_x                              0x5CB740
#define EQ_Character__Max_HP_x                                     0x45E530
#define EQ_Character__Max_Mana_x                                   0x5CB570
#define EQ_Character__doCombatAbility_x                            0x5C8C40
#define EQ_Character__UseSkill_x                                   0x4728A0
#define EQ_Character__GetConLevel_x                                0x5BE0A0
#define EQ_Character__IsExpansionFlag_x                            0x4B6590
#define EQ_Character__TotalEffect_x                                0x44F780
#define EQ_Character__GetPCSpellAffect_x                           0x44B9A0
#define EQ_Character__SpellDuration_x                              0x4499A0
#define EQ_Character__FindItemByRecord_x                           0x464010
#define EQ_Character__GetAdjustedSkill_x                           0x466B90
#define EQ_Character__GetBaseSkill_x                               0x45E410

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x872A50

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D3D80

//PcClient
#define PcClient__PcClient_x                                       0x5BFEF0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446A40
#define CCharacterSelect__EnterWorld_x                             0x446210
#define CCharacterSelect__Quit_x                                   0x444DD0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59E0D0
#define EQ_Item__CreateItemTagString_x                             0x852C30
#define EQ_Item__IsStackable_x                                     0x847F50
#define EQ_Item__GetImageNum_x                                     0x84AA10
#define EQ_Item__CreateItemClient_x                                0x59F1F0
#define EQ_Item__GetItemValue_x                                    0x851680
#define EQ_Item__ValueSellMerchant_x                               0x8546F0
#define EQ_Item__IsKeyRingItem_x                                   0x848A20
#define EQ_Item__CanGoInBag_x                                      0x59E260
#define EQ_Item__GetMaxItemCount_x                                 0x847E40
#define EQ_Item__GetHeldItem_x                                     0x849830
#define EQ_Item__GetAugmentFitBySlot_x                             0x854510

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA380
#define EQ_LoadingS__Array_x                                       0xC0AC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CDC70
#define EQ_PC__GetAlternateAbilityId_x                             0x85CB90
#define EQ_PC__GetCombatAbility_x                                  0x85CC20
#define EQ_PC__GetCombatAbilityTimer_x                             0x857750
#define EQ_PC__GetItemRecastTimer_x                                0x5C7430
#define EQ_PC__HasLoreItem_x                                       0x5C16B0
#define EQ_PC__AlertInventoryChanged_x                             0x5BE050
#define EQ_PC__GetPcZoneClient_x                                   0x5E82E0
#define EQ_PC__RemoveMyAffect_x                                    0x5C6890
#define EQ_PC__GetKeyRingItems_x                                   0x857B70
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86A8C0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85EB30

// EQItemList 
#define EQItemList__EQItemList_x                                   0x526350
#define EQItemList__add_object_x                                   0x553530
#define EQItemList__add_item_x                                     0x526290
#define EQItemList__delete_item_x                                  0x526740
#define EQItemList__FreeItemList_x                                 0x526640

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B94E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D3B20
#define EQPlayer__dEQPlayer_x                                      0x5DC1E0
#define EQPlayer__DoAttack_x                                       0x5EDA80
#define EQPlayer__EQPlayer_x                                       0x5DE910
#define EQPlayer__SetNameSpriteState_x                             0x5D9030
#define EQPlayer__SetNameSpriteTint_x                              0x5D4F40
#define PlayerBase__HasProperty_j_x                                0x931390
#define EQPlayer__IsTargetable_x                                   0x931630
#define EQPlayer__CanSee_x                                         0x931B90
#define PlayerZoneClient__ChangeHeight_x                           0x5ED940
#define EQPlayer__CanSee1_x                                        0x931C80
#define PlayerBase__GetVisibilityLineSegment_x                     0x931920

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E8490
#define PlayerZoneClient__IsValidTeleport_x                        0x553DD0
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2580


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E28D0
#define EQPlayerManager__GetSpawnByName_x                          0x5E2D30
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E2900

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A4820
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A4860
#define KeypressHandler__ClearCommandStateArray_x                  0x5A4410
#define KeypressHandler__HandleKeyDown_x                           0x5A2D30
#define KeypressHandler__HandleKeyUp_x                             0x5A3050
#define KeypressHandler__SaveKeymapping_x                          0x5A44E0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x711EE0
#define MapViewMap__SaveEx_x                                       0x715210
#define MapViewMap__SetZoom_x                                      0x711B60

#define PlayerPointManager__GetAltCurrency_x                       0x870B10

// StringTable 
#define StringTable__getString_x                                   0x86ABF0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CB1D0
#define PcZoneClient__RemovePetEffect_x                            0x5C7900
#define PcZoneClient__HasAlternateAbility_x                        0x5C82A0
#define PcZoneClient__GetCurrentMod_x                              0x45D9E0
#define PcZoneClient__GetModCap_x                                  0x45B110
#define PcZoneClient__CanEquipItem_x                               0x5C8780
#define PcZoneClient__GetItemByID_x                                0x5CCFE0
#define PcZoneClient__GetItemByItemClass_x                         0x5CDB90
#define PcZoneClient__RemoveBuffEffect_x                           0x5C6B40

//Doors
#define EQSwitch__UseSwitch_x                                      0x55AF00

//IconCache
#define IconCache__GetIcon_x                                       0x6AED80

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A5C70
#define CContainerMgr__CloseContainer_x                            0x6A6490

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x772FF0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x597130

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4940
#define EQ_Spell__SpellAffects_x                                   0x4F1B30
#define EQ_Spell__SpellAffectBase_x                           0x4F1BA0
#define CharacterZoneClient__CalcAffectChange_x                    0x44B830
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AAD0
#define CLootWnd__LootAll_x                                        0x707750
#define CLootWnd__RequestLootSlot_x                                0x707F60
#define EQ_Spell__IsStackable_x                                    0x4493B0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449460
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EB50
#define EQ_Spell__IsSPAStacking_x                                  0x4F16A0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2740
#define EQ_Spell__IsNoRemove_x                                     0x434D00
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F16C0

#define __IsResEffectSpell_x                                       0x4494F0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87C6D0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BAE50
#define CTargetWnd__WndNotification_x                              0x7BA940
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BB030

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7BFF80

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED170
#define EqSoundManager__PlayScriptMp3_x                            0x4EEC10

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8580

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EABA0
#define CSidlManager__FindAnimation1_x                             0x8DFEB0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E1C40
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1BF0
#define CAltAbilityData__GetMaxRank_x                              0x4D63E0

//CTargetRing
#define CTargetRing__Cast_x                                        0x594D80

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4592C0
#define CharacterBase__CreateItemGlobalIndex_x                     0x4752C0
#define CharacterBase__CreateItemIndex_x                           0x51F9C0
#define CharacterBase__GetItemPossession_x                         0x444290
#define CharacterBase__GetItemByGlobalIndex_x                      0x880520
#define CharacterBase__GetEffectId_x                               0x459280

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68EB70
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68E2D0

//messages
#define msg_spell_worn_off_x                                       0x4FC410
#define msg_new_text_x                                             0x505B90
#define msgTokenTextParam_x                                        0x502390

//SpellManager
#define SpellManager__vftable_x                                    0xAC8268
#define SpellManager__SpellManager_x                               0x47DFF0
#define Spellmanager__LoadTextSpells_x                             0x60B8A0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9356F0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487AB0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EA70
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449130
#define ItemGlobalIndex__IsValidIndex_x                            0x458B60

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87E390
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87D2D0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x700770

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AA9C0
#define CCursorAttachment__Deactivate_x                            0x6A9F00

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FC9E0
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FCB60

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x603550

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C310

//IString
#define IString__Append_x                                          0x47EC70

//Camera
#define CDisplay__cameraType_x                                     0xE6E7C8
#define EverQuest__Cameras_x                                       0xF30AC8
