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
#define __ExpectedVersionDate                                     "Nov 22 2017"
#define __ExpectedVersionTime                                     "04:21:18"
#define __ActualVersionDate_x                                      0xAE30E0
#define __ActualVersionTime_x                                      0xAE30EC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AA060
#define __MemChecker1_x                                            0x8A2A80
#define __MemChecker2_x                                            0x63FF30
#define __MemChecker3_x                                            0x63FE80
#define __MemChecker4_x                                            0x7F47D0
#define __EncryptPad0_x                                            0xC3DFE8
#define __EncryptPad1_x                                            0xD17BA0
#define __EncryptPad2_x                                            0xC66ED0
#define __EncryptPad3_x                                            0xC66AD0
#define __EncryptPad4_x                                            0xD061A0
#define __EncryptPad5_x                                            0x10C12C0
#define __AC1_x                                                    0x7B3965
#define __AC2_x                                                    0x563317
#define __AC3_x                                                    0x561490
#define __AC4_x                                                    0x573661
#define __AC5_x                                                    0x5873BB
#define __AC6_x                                                    0x58AF5E
#define __AC7_x                                                    0x5819BC
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
#define __do_loot_x                                                0x532360
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
#define __CastRay_x                                                0x549CF0
#define __CastRay2_x                                               0x549620
#define __HeadingDiff_x                                            0x933150
#define __FixHeading_x                                             0x9330E0
#define __get_bearing_x                                            0x5394B0
#define __ConvertItemTags_x                                        0x536F80
#define __ExecuteCmd_x                                             0x5218A0
#define __EQGetTime_x                                              0x8A2420
#define __get_melee_range_x                                        0x528560
#define __GetGaugeValueFromEQ_x                                    0x7B2520
#define __GetLabelFromEQ_x                                         0x7B38F0
#define __ToggleKeyRingItem_x                                      0x48FE00
#define __GetXTargetType_x                                         0x934D50
#define __LoadFrontEnd_x                                           0x63F600
#define __NewUIINI_x                                               0x7B1EF0
#define __ProcessGameEvents_x                                      0x583750
#define __ProcessMouseEvent_x                                      0x582EF0
#define CrashDetected_x                                            0x640FC0
#define wwsCrashReportCheckForUploader_x                           0x800490
#define __AppCrashWrapper_x                                        0xC66AC4
#define __pCrashHandler_x                                          0x10D69E0
#define __CrashHandler_x                                           0x7FFEF0
#define wwsCrashReportPlatformLaunchUploader_x                     0x802690
#define DrawNetStatus_x                                            0x5B9C40
#define Util__FastTime_x                                           0x8A20C0
#define Expansion_HoT_x                                            0xF307B0
#define __HelpPath_x                                               0xFB3F60
#define __STMLToText_x                                             0x8E8B80
#define __GetAnimationCache_x                                      0x6AEE00

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423670
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E2D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41E0A0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8070
#define AltAdvManager__IsAbilityReady_x                            0x4D80E0
#define AltAdvManager__GetAAById_x                                 0x4D85D0
#define AltAdvManager__CanTrainAbility_x                           0x4D9200
#define AltAdvManager__CanSeeAbility_x                             0x4D8DC0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46B260
#define CharacterZoneClient__HasSkill_x                            0x467170
#define CharacterZoneClient__MakeMeVisible_x                       0x46CDD0
#define CharacterZoneClient__IsStackBlocked_x                      0x44C220
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B740
#define CharacterZoneClient__GetItemCountWorn_x                    0x4656D0
#define CharacterZoneClient__GetItemCountInInventory_x             0x4657B0
#define CharacterZoneClient__GetCursorItemCount_x                  0x465890
#define CharacterZoneClient__FindAffectSlot_x                      0x4518B0
#define CharacterZoneClient__BardCastBard_x                        0x44AEB0
#define CharacterZoneClient__GetMaxEffects_x                       0x449A40
#define CharacterZoneClient__GetEffect_x                           0x44B970
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451710
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449D90
#define CharacterZoneClient__GetLastEffectSlot_x                   0x450260

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66EFD0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67D010

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5987C0
#define CButtonWnd__CButtonWnd_x                                   0x8DCE70

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x697FB0
#define CChatManager__InitContextMenu_x                            0x699100
#define CChatManager__FreeChatWindow_x                             0x697A60
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A12A0
#define CChatManager__SetLockedActiveChatWindow_x                  0x697F80

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E6ED0
#define CContextMenu__dCContextMenu_x                              0x8E70E0
#define CContextMenu__AddMenuItem_x                                0x8E7600
#define CContextMenu__RemoveMenuItem_x                             0x8E7260
#define CContextMenu__RemoveAllMenuItems_x                         0x8E7280
#define CContextMenu__CheckMenuItem_x                              0x8E7300
#define CContextMenu__SetMenuItem_x                                0x8E7180

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D3420
#define CContextMenuManager__RemoveMenu_x                          0x8D37C0
#define CContextMenuManager__PopupMenu_x                           0x8D3C10
#define CContextMenuManager__Flush_x                               0x8D3490
#define CContextMenuManager__GetMenu_x                             0x4197A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x886540
#define CChatService__GetFriendName_x                              0x886550

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69ED70
#define CChatWindow__Clear_x                                       0x69E650
#define CChatWindow__WndNotification_x                             0x69F680

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D7280
#define CComboWnd__Draw_x                                          0x8D7490
#define CComboWnd__GetCurChoice_x                                  0x8D7030
#define CComboWnd__GetListRect_x                                   0x8D7730
#define CComboWnd__GetTextRect_x                                   0x8D72F0
#define CComboWnd__InsertChoice_x                                  0x8D7890
#define CComboWnd__SetColors_x                                     0x8D6FC0
#define CComboWnd__SetChoice_x                                     0x8D6FF0
#define CComboWnd__GetItemCount_x                                  0x8D7020
#define CComboWnd__GetCurChoiceText_x                              0x8D7070


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A8F90
#define CContainerWnd__vftable_x                                   0xAEC9F8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C5F60
#define CDisplay__GetClickedActor_x                                0x4BE820
#define CDisplay__GetUserDefinedColor_x                            0x4BD400
#define CDisplay__GetWorldFilePath_x                               0x4BC850
#define CDisplay__is3dON_x                                         0x4BBCE0
#define CDisplay__ReloadUI_x                                       0x4CFD20
#define CDisplay__WriteTextHD2_x                                   0x4C22F0
#define CDisplay__TrueDistance_x                                   0x4BF450

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FE250

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EB430
#define CEditWnd__GetCharIndexPt_x                                 0x8EC590
#define CEditWnd__GetDisplayString_x                               0x8EB5E0
#define CEditWnd__GetHorzOffset_x                                  0x8EB920
#define CEditWnd__GetLineForPrintableChar_x                        0x8EC050
#define CEditWnd__GetSelStartPt_x                                  0x8EC850
#define CEditWnd__GetSTMLSafeText_x                                0x8EBAC0
#define CEditWnd__PointFromPrintableChar_x                         0x8EC140
#define CEditWnd__SelectableCharFromPoint_x                        0x8EC2C0
#define CEditWnd__SetEditable_x                                    0x8EBA90

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x569E90
#define CEverQuest__ClickedPlayer_x                                0x563A60
#define CEverQuest__CreateTargetIndicator_x                        0x564960
#define CEverQuest__DeleteTargetIndicator_x                        0x5649E0
#define CEverQuest__DoTellWindow_x                                 0x476480
#define CEverQuest__OutputTextToLog_x                              0x4760E0
#define CEverQuest__DropHeldItemOnGround_x                         0x57A400
#define CEverQuest__dsp_chat_x                                     0x4767C0
#define CEverQuest__trimName_x                                     0x560370
#define CEverQuest__Emote_x                                        0x578710
#define CEverQuest__EnterZone_x                                    0x5737F0
#define CEverQuest__GetBodyTypeDesc_x                              0x55DDB0
#define CEverQuest__GetClassDesc_x                                 0x5672A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5678A0
#define CEverQuest__GetDeityDesc_x                                 0x55E690
#define CEverQuest__GetLangDesc_x                                  0x55E140
#define CEverQuest__GetRaceDesc_x                                  0x567A60
#define CEverQuest__InterpretCmd_x                                 0x56B610
#define CEverQuest__LeftClickedOnPlayer_x                          0x57FF60
#define CEverQuest__LMouseUp_x                                     0x581F10
#define CEverQuest__RightClickedOnPlayer_x                         0x580A70
#define CEverQuest__RMouseUp_x                                     0x581970
#define CEverQuest__SetGameState_x                                 0x564330
#define CEverQuest__UPCNotificationFlush_x                         0x55C740
#define CEverQuest__IssuePetCommand_x                              0x56BFF0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B9BA0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B9C00
#define CGaugeWnd__Draw_x                                          0x6BA030

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B3D0
#define CGuild__GetGuildName_x                                     0x43B8A0
#define CGuild__GetGuildIndex_x                                    0x43CAB0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D6070

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E3420
#define CInvSlotMgr__MoveItem_x                                    0x6E3BE0
#define CInvSlotMgr__SelectSlot_x                                  0x6E2D10

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E2170
#define CInvSlot__SliderComplete_x                                 0x6DF990
#define CInvSlot__GetItemBase_x                                    0x6DEE10
#define CInvSlot__UpdateItem_x                                     0x6DF390

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E5040
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E6180

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AE360
#define CItemDisplayWnd__UpdateStrings_x                           0x6E72B0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F3B20
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F4050
#define CItemDisplayWnd__SetItem_x                                 0x6F99A0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E54B0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6ED810

// CLabel 
#define CLabel__Draw_x                                             0x700790

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C2CC0
#define CListWnd__dCListWnd_x                                      0x8C3F60
#define CListWnd__AddColumn_x                                      0x8C3F00
#define CListWnd__AddColumn1_x                                     0x8C3590
#define CListWnd__AddLine_x                                        0x8C2F70
#define CListWnd__AddString_x                                      0x8C3190
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BFDB0
#define CListWnd__CalculateVSBRange_x                              0x8C2180
#define CListWnd__ClearSel_x                                       0x8BF0D0
#define CListWnd__ClearAllSel_x                                    0x8BF080
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C2B50
#define CListWnd__Compare_x                                        0x8C0AB0
#define CListWnd__Draw_x                                           0x8C1D80
#define CListWnd__DrawColumnSeparators_x                           0x8C1C10
#define CListWnd__DrawHeader_x                                     0x8BF390
#define CListWnd__DrawItem_x                                       0x8C1140
#define CListWnd__DrawLine_x                                       0x8C18B0
#define CListWnd__DrawSeparator_x                                  0x8C1CB0
#define CListWnd__EnableLine_x                                     0x8BF2B0
#define CListWnd__EnsureVisible_x                                  0x8BFF10
#define CListWnd__ExtendSel_x                                      0x8C1050
#define CListWnd__GetColumnMinWidth_x                              0x8BE9C0
#define CListWnd__GetColumnWidth_x                                 0x8BE8F0
#define CListWnd__GetCurSel_x                                      0x8BE0B0
#define CListWnd__GetItemAtPoint_x                                 0x8C01B0
#define CListWnd__GetItemAtPoint1_x                                0x8C0220
#define CListWnd__GetItemData_x                                    0x8BE400
#define CListWnd__GetItemHeight_x                                  0x8BFA10
#define CListWnd__GetItemIcon_x                                    0x8BE5F0
#define CListWnd__GetItemRect_x                                    0x8BFFF0
#define CListWnd__GetItemText_x                                    0x8BE4A0
#define CListWnd__GetSelList_x                                     0x8C3480
#define CListWnd__GetSeparatorRect_x                               0x8C09D0
#define CListWnd__InsertLine_x                                     0x8C3370
#define CListWnd__RemoveLine_x                                     0x8C3380
#define CListWnd__SetColors_x                                      0x8BE200
#define CListWnd__SetColumnJustification_x                         0x8BEC50
#define CListWnd__SetColumnWidth_x                                 0x8BE970
#define CListWnd__SetCurSel_x                                      0x8BE0F0
#define CListWnd__SetItemColor_x                                   0x8C2840
#define CListWnd__SetItemData_x                                    0x8BF130
#define CListWnd__SetItemText_x                                    0x8C2680
#define CListWnd__ShiftColumnSeparator_x                           0x8C2510
#define CListWnd__Sort_x                                           0x8C4060
#define CListWnd__ToggleSel_x                                      0x8BF000

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x719900

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73EF50
#define CMerchantWnd__RequestBuyItem_x                             0x746A40
#define CMerchantWnd__RequestSellItem_x                            0x749050
#define CMerchantWnd__SelectRecoverySlot_x                         0x73C200
#define CMerchantWnd__SelectBuySellSlot_x                          0x73A1A0
#define CMerchantWnd__ActualSelect_x                               0x740D00

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x854930
#define CPacketScrambler__hton_x                                   0x854940

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E1DB0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1E90
#define CSidlManager__CreateLabel_x                                0x7A3240
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E0350
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E2170

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D92E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D91D0
#define CSidlScreenWnd__ConvertToRes_x                             0x8FE130
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9BF0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DADD0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DAE80
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DA360
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D95A0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8D00
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D9790
#define CSidlScreenWnd__Init1_x                                    0x8DAAB0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D9CB0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8EC0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DA5A0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D8950
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8CB0
#define CSidlScreenWnd__WndNotification_x                          0x8DA830
#define CSidlScreenWnd__GetChildItem_x                             0x8D8DD0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CC5B0
#define CSidlScreenWnd__m_layoutCopy_x                             0x172FE20

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x604EF0
#define CSkillMgr__GetSkillCap_x                                   0x6050D0
#define CSkillMgr__GetNameToken_x                                  0x604AA0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FD3F0
#define CSliderWnd__SetValue_x                                     0x8FD5C0
#define CSliderWnd__SetNumTicks_x                                  0x8FDD40

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A95D0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6EC0
#define CStmlWnd__CalculateHSBRange_x                              0x8EF420
#define CStmlWnd__CalculateVSBRange_x                              0x8EF390
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EF5A0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EFDA0
#define CStmlWnd__ForceParseNow_x                                  0x8F7840
#define CStmlWnd__GetNextTagPiece_x                                0x8EFCA0
#define CStmlWnd__GetSTMLText_x                                    0x484720
#define CStmlWnd__GetVisibleText_x                                 0x8F07F0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2DC0
#define CStmlWnd__MakeStmlColorTag_x                               0x8EE670
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EE6D0
#define CStmlWnd__SetSTMLText_x                                    0x8F4610
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6B60
#define CStmlWnd__UpdateHistoryString_x                            0x8F1730

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FAD60
#define CTabWnd__DrawCurrentPage_x                                 0x8FA5F0
#define CTabWnd__DrawTab_x                                         0x8FA3B0
#define CTabWnd__GetCurrentPage_x                                  0x8FA9A0
#define CTabWnd__GetPageInnerRect_x                                0x8FA0A0
#define CTabWnd__GetTabInnerRect_x                                 0x8FA2A0
#define CTabWnd__GetTabRect_x                                      0x8FA170
#define CTabWnd__InsertPage_x                                      0x8FB050
#define CTabWnd__SetPage_x                                         0x8FA9D0
#define CTabWnd__SetPageRect_x                                     0x8FACA0
#define CTabWnd__UpdatePage_x                                      0x8FAFF0
#define CTabWnd__GetPageFromTabIndex_x                             0x8FA300
#define CTabWnd__GetCurrentTabIndex_x                              0x8FA030

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E6330
#define CPageWnd__SetTabText_x                                     0x907450

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436F30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D6C30
#define CTextureFont__GetTextExtent_x                              0x8D6990

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63D890

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x903890

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BC2A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029C0
#define CXStr__CXStr1_x                                            0x403700
#define CXStr__CXStr3_x                                            0x89F350
#define CXStr__dCXStr_x                                            0x7A31F0
#define CXStr__operator_equal_x                                    0x89F4C0
#define CXStr__operator_equal1_x                                   0x89F510
#define CXStr__operator_plus_equal1_x                              0x8A0610

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D4730
#define CXWnd__BringToTop_x                                        0x8CB770
#define CXWnd__Center_x                                            0x8D1A40
#define CXWnd__ClrFocus_x                                          0x8CB340
#define CXWnd__Destroy_x                                           0x8D2520
#define CXWnd__DoAllDrawing_x                                      0x8D1670
#define CXWnd__DrawChildren_x                                      0x8D1820
#define CXWnd__DrawColoredRect_x                                   0x8CBB50
#define CXWnd__DrawTooltip_x                                       0x8CBE00
#define CXWnd__DrawTooltipAtPoint_x                                0x8D05A0
#define CXWnd__GetBorderFrame_x                                    0x8CC270
#define CXWnd__GetChildWndAt_x                                     0x8D2400
#define CXWnd__GetClientClipRect_x                                 0x8CC020
#define CXWnd__GetScreenClipRect_x                                 0x8D0CA0
#define CXWnd__GetScreenRect_x                                     0x8CC450
#define CXWnd__GetTooltipRect_x                                    0x8CBC90
#define CXWnd__GetWindowTextA_x                                    0x427160
#define CXWnd__IsActive_x                                          0x8C6D40
#define CXWnd__IsDescendantOf_x                                    0x8CC1B0
#define CXWnd__IsReallyVisible_x                                   0x8CF5D0
#define CXWnd__IsType_x                                            0x8D1AB0
#define CScreenPieceTemplate__IsType_x                             0x8FFFC0
#define CXWnd__Move_x                                              0x8CECD0
#define CXWnd__Move1_x                                             0x8D1300
#define CXWnd__ProcessTransition_x                                 0x8CB710
#define CXWnd__Refade_x                                            0x8CB4F0
#define CXWnd__Resize_x                                            0x8CC520
#define CXWnd__Right_x                                             0x8D0AA0
#define CXWnd__SetFocus_x                                          0x8CDE10
#define CXWnd__SetFont_x                                           0x8CB390
#define CXWnd__SetKeyTooltip_x                                     0x8CC780
#define CXWnd__SetMouseOver_x                                      0x8D0FE0
#define CXWnd__StartFade_x                                         0x8CB7C0
#define CXWnd__GetChildItem_x                                      0x8D0F20
#define CXWnd__SetParent_x                                         0x8D23B0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C85F0
#define CXWndManager__DrawWindows_x                                0x8C8230
#define CXWndManager__GetKeyboardFlags_x                           0x8C6870
#define CXWndManager__HandleKeyboardMsg_x                          0x8C71D0
#define CXWndManager__RemoveWnd_x                                  0x8C6ED0

// CDBStr
#define CDBStr__GetString_x                                        0x4BA540

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452970
#define EQ_Character__Cur_HP_x                                     0x466D50
#define EQ_Character__Cur_Mana_x                                   0x45BD30
#define EQ_Character__GetAACastingTimeModifier_x                   0x44BA50
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4439C0
#define EQ_Character__GetFocusRangeModifier_x                      0x443B10
#define EQ_Character__GetHPRegen_x                                 0x46A8F0
#define EQ_Character__GetEnduranceRegen_x                          0x466360
#define EQ_Character__GetManaRegen_x                               0x46AE90
#define EQ_Character__Max_Endurance_x                              0x5CB620
#define EQ_Character__Max_HP_x                                     0x45E8B0
#define EQ_Character__Max_Mana_x                                   0x5CB450
#define EQ_Character__doCombatAbility_x                            0x5C8B20
#define EQ_Character__UseSkill_x                                   0x472C80
#define EQ_Character__GetConLevel_x                                0x5BE2C0
#define EQ_Character__IsExpansionFlag_x                            0x4B68F0
#define EQ_Character__TotalEffect_x                                0x44FBA0
#define EQ_Character__GetPCSpellAffect_x                           0x44BDE0
#define EQ_Character__SpellDuration_x                              0x449DE0
#define EQ_Character__FindItemByRecord_x                           0x4643A0
#define EQ_Character__GetAdjustedSkill_x                           0x466F20
#define EQ_Character__GetBaseSkill_x                               0x45E790

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x872740

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D3D30

//PcClient
#define PcClient__PcClient_x                                       0x5C0120

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446EB0
#define CCharacterSelect__EnterWorld_x                             0x446680
#define CCharacterSelect__Quit_x                                   0x445240

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59E1A0
#define EQ_Item__CreateItemTagString_x                             0x852B20
#define EQ_Item__IsStackable_x                                     0x8481A0
#define EQ_Item__GetImageNum_x                                     0x84AC90
#define EQ_Item__CreateItemClient_x                                0x59F2E0
#define EQ_Item__GetItemValue_x                                    0x8515E0
#define EQ_Item__ValueSellMerchant_x                               0x854580
#define EQ_Item__IsKeyRingItem_x                                   0x848C70
#define EQ_Item__CanGoInBag_x                                      0x59E330
#define EQ_Item__GetMaxItemCount_x                                 0x848090
#define EQ_Item__GetHeldItem_x                                     0x849A80
#define EQ_Item__GetAugmentFitBySlot_x                             0x8543A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA650
#define EQ_LoadingS__Array_x                                       0xC0AC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CDB50
#define EQ_PC__GetAlternateAbilityId_x                             0x85C980
#define EQ_PC__GetCombatAbility_x                                  0x85CA10
#define EQ_PC__GetCombatAbilityTimer_x                             0x8575E0
#define EQ_PC__GetItemRecastTimer_x                                0x5C7310
#define EQ_PC__HasLoreItem_x                                       0x5C18E0
#define EQ_PC__AlertInventoryChanged_x                             0x5BE270
#define EQ_PC__GetPcZoneClient_x                                   0x5E82E0
#define EQ_PC__RemoveMyAffect_x                                    0x5C6740
#define EQ_PC__GetKeyRingItems_x                                   0x857A00
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86A690
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85E900

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5265F0
#define EQItemList__add_object_x                                   0x5537A0
#define EQItemList__add_item_x                                     0x526530
#define EQItemList__delete_item_x                                  0x5269E0
#define EQItemList__FreeItemList_x                                 0x5268E0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9860

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D39F0
#define EQPlayer__dEQPlayer_x                                      0x5DC1A0
#define EQPlayer__DoAttack_x                                       0x5EDA90
#define EQPlayer__EQPlayer_x                                       0x5DE8D0
#define EQPlayer__SetNameSpriteState_x                             0x5D8FD0
#define EQPlayer__SetNameSpriteTint_x                              0x5D4EF0
#define PlayerBase__HasProperty_j_x                                0x931500
#define EQPlayer__IsTargetable_x                                   0x9317A0
#define EQPlayer__CanSee_x                                         0x931D00
#define PlayerZoneClient__ChangeHeight_x                           0x5ED950
#define EQPlayer__CanSee1_x                                        0x931DF0
#define PlayerBase__GetVisibilityLineSegment_x                     0x931A90

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E8490
#define PlayerZoneClient__IsValidTeleport_x                        0x554040
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2910


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E2910
#define EQPlayerManager__GetSpawnByName_x                          0x5E2D70
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E2940

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A4830
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A4870
#define KeypressHandler__ClearCommandStateArray_x                  0x5A4420
#define KeypressHandler__HandleKeyDown_x                           0x5A2D40
#define KeypressHandler__HandleKeyUp_x                             0x5A3060
#define KeypressHandler__SaveKeymapping_x                          0x5A44F0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x712290
#define MapViewMap__SaveEx_x                                       0x7155C0
#define MapViewMap__SetZoom_x                                      0x711F00

#define PlayerPointManager__GetAltCurrency_x                       0x8707F0

// StringTable 
#define StringTable__getString_x                                   0x86A9C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CB0B0
#define PcZoneClient__RemovePetEffect_x                            0x5C77E0
#define PcZoneClient__HasAlternateAbility_x                        0x5C8180
#define PcZoneClient__GetCurrentMod_x                              0x45DD60
#define PcZoneClient__GetModCap_x                                  0x45B490
#define PcZoneClient__CanEquipItem_x                               0x5C8660
#define PcZoneClient__GetItemByID_x                                0x5CCEC0
#define PcZoneClient__GetItemByItemClass_x                         0x5CDA70
#define PcZoneClient__RemoveBuffEffect_x                           0x5C69F0

//Doors
#define EQSwitch__UseSwitch_x                                      0x55B080

//IconCache
#define IconCache__GetIcon_x                                       0x6AF430

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A6320
#define CContainerMgr__CloseContainer_x                            0x6A6B40

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x772F50

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5971E0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4CC0
#define EQ_Spell__SpellAffects_x                                   0x4F1EA0
#define EQ_Spell__SpellAffectBase_x                                0x4F1F10
#define CharacterZoneClient__CalcAffectChange_x                    0x44BC70
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AF10
#define CLootWnd__LootAll_x                                        0x707B40
#define CLootWnd__RequestLootSlot_x                                0x708350
#define EQ_Spell__IsStackable_x                                    0x459450
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449890
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EF10
#define EQ_Spell__IsSPAStacking_x                                  0x4F1A10
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2AB0
#define EQ_Spell__IsNoRemove_x                                     0x434F60
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1A30

#define __IsResEffectSpell_x                                       0x449930

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87C3E0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BAFF0
#define CTargetWnd__WndNotification_x                              0x7BAAE0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BB1D0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C0120

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED510
#define EqSoundManager__PlayScriptMp3_x                            0x4EEFB0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A89E0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EAA60
#define CSidlManager__FindAnimation1_x                             0x8DFD80

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E1E60
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1E10
#define CAltAbilityData__GetMaxRank_x                              0x4D6720

//CTargetRing
#define CTargetRing__Cast_x                                        0x594E20

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459750
#define CharacterBase__CreateItemGlobalIndex_x                     0x4756B0
#define CharacterBase__CreateItemIndex_x                           0x51FC20
#define CharacterBase__GetItemPossession_x                         0x4446E0
#define CharacterBase__GetItemByGlobalIndex_x                      0x880230
#define CharacterBase__GetEffectId_x                               0x459710

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68F1C0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68E920

//messages
#define msg_spell_worn_off_x                                       0x4FC7A0
#define msg_new_text_x                                             0x505F20
#define msgTokenTextParam_x                                        0x502720

//SpellManager
#define SpellManager__vftable_x                                    0xAC8278
#define SpellManager__SpellManager_x                               0x47E320
#define Spellmanager__LoadTextSpells_x                             0x60BE70

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x935870

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487E30
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EE20
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4495A0
#define ItemGlobalIndex__IsValidIndex_x                            0x458F90

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87E0A0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87CFE0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7009E0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AB060
#define CCursorAttachment__Deactivate_x                            0x6AA5A0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FC8F0
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FCA70

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x603B00

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C6C0

//IString
#define IString__Append_x                                          0x47EFD0

//Camera
#define CDisplay__cameraType_x                                     0xE6E7C8
#define EverQuest__Cameras_x                                       0xF30AC8
