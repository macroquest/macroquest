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
#define __ExpectedVersionDate                                     "Nov 20 2017"
#define __ExpectedVersionTime                                     "04:16:39"
#define __ActualVersionDate_x                                      0xAE3078
#define __ActualVersionTime_x                                      0xAE3084

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5A9B10
#define __MemChecker1_x                                            0x8A2600
#define __MemChecker2_x                                            0x63F9A0
#define __MemChecker3_x                                            0x63F8F0
#define __MemChecker4_x                                            0x7F4450
#define __EncryptPad0_x                                            0xC3DFE8
#define __EncryptPad1_x                                            0xD17BA0
#define __EncryptPad2_x                                            0xC66ED0
#define __EncryptPad3_x                                            0xC66AD0
#define __EncryptPad4_x                                            0xD061A0
#define __EncryptPad5_x                                            0x10C12C0
#define __AC1_x                                                    0x7B30C5
#define __AC2_x                                                    0x562E57
#define __AC3_x                                                    0x560FD0
#define __AC4_x                                                    0x573181
#define __AC5_x                                                    0x586EDB
#define __AC6_x                                                    0x58AA8E
#define __AC7_x                                                    0x5814DC
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
#define __do_loot_x                                                0x531CB0
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
#define __CastRay_x                                                0x549640
#define __CastRay2_x                                               0x548F70
#define __HeadingDiff_x                                            0x932B70
#define __FixHeading_x                                             0x932B00
#define __get_bearing_x                                            0x538E00
#define __ConvertItemTags_x                                        0x5368D0
#define __ExecuteCmd_x                                             0x521210
#define __EQGetTime_x                                              0x8A1F90
#define __get_melee_range_x                                        0x527EB0
#define __GetGaugeValueFromEQ_x                                    0x7B1C80
#define __GetLabelFromEQ_x                                         0x7B3050
#define __ToggleKeyRingItem_x                                      0x48F700
#define __GetXTargetType_x                                         0x934770
#define __LoadFrontEnd_x                                           0x63F070
#define __NewUIINI_x                                               0x7B1650
#define __ProcessGameEvents_x                                      0x583270
#define __ProcessMouseEvent_x                                      0x582A10
#define CrashDetected_x                                            0x640A30
#define wwsCrashReportCheckForUploader_x                           0x8000C0
#define __AppCrashWrapper_x                                        0xC66AC4
#define __pCrashHandler_x                                          0x10D69E0
#define __CrashHandler_x                                           0x7FFB50
#define wwsCrashReportPlatformLaunchUploader_x                     0x8022F0
#define DrawNetStatus_x                                            0x5B96C0
#define Util__FastTime_x                                           0x8A1C30
#define Expansion_HoT_x                                            0xF307B0
#define __HelpPath_x                                               0xFB3F60
#define __STMLToText_x                                             0x8E8310
#define __GetAnimationCache_x                                      0x6AE890

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423230
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DE90
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DC60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D7A00
#define AltAdvManager__IsAbilityReady_x                            0x4D7A70
#define AltAdvManager__GetAAById_x                                 0x4D7F60
#define AltAdvManager__CanTrainAbility_x                           0x4D8B90
#define AltAdvManager__CanSeeAbility_x                             0x4D8750

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AC10
#define CharacterZoneClient__HasSkill_x                            0x466B20
#define CharacterZoneClient__MakeMeVisible_x                       0x46C780
#define CharacterZoneClient__IsStackBlocked_x                      0x44BC10
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B130
#define CharacterZoneClient__GetItemCountWorn_x                    0x465080
#define CharacterZoneClient__GetItemCountInInventory_x             0x465160
#define CharacterZoneClient__GetCursorItemCount_x                  0x465240
#define CharacterZoneClient__FindAffectSlot_x                      0x4512A0
#define CharacterZoneClient__BardCastBard_x                        0x44A8A0
#define CharacterZoneClient__GetMaxEffects_x                       0x449430
#define CharacterZoneClient__GetEffect_x                           0x44B360
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451100
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449780
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FC50

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66EA80

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67C810

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x598320
#define CButtonWnd__CButtonWnd_x                                   0x8DC620

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x697A00
#define CChatManager__InitContextMenu_x                            0x698B50
#define CChatManager__FreeChatWindow_x                             0x6974B0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A0CF0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6979D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E6660
#define CContextMenu__dCContextMenu_x                              0x8E6870
#define CContextMenu__AddMenuItem_x                                0x8E6D90
#define CContextMenu__RemoveMenuItem_x                             0x8E69F0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E6A10
#define CContextMenu__CheckMenuItem_x                              0x8E6A90
#define CContextMenu__SetMenuItem_x                                0x8E6910

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D2BA0
#define CContextMenuManager__RemoveMenu_x                          0x8D2F50
#define CContextMenuManager__PopupMenu_x                           0x8D33A0
#define CContextMenuManager__Flush_x                               0x8D2C10
#define CContextMenuManager__GetMenu_x                             0x419360

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x886030
#define CChatService__GetFriendName_x                              0x886040

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69E7C0
#define CChatWindow__Clear_x                                       0x69E0A0
#define CChatWindow__WndNotification_x                             0x69F0D0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D6A10
#define CComboWnd__Draw_x                                          0x8D6C20
#define CComboWnd__GetCurChoice_x                                  0x8D67C0
#define CComboWnd__GetListRect_x                                   0x8D6EC0
#define CComboWnd__GetTextRect_x                                   0x8D6A80
#define CComboWnd__InsertChoice_x                                  0x8D7020
#define CComboWnd__SetColors_x                                     0x8D6750
#define CComboWnd__SetChoice_x                                     0x8D6780
#define CComboWnd__GetItemCount_x                                  0x8D67B0
#define CComboWnd__GetCurChoiceText_x                              0x8D6800


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A8A30
#define CContainerWnd__vftable_x                                   0xAEC990

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C5920
#define CDisplay__GetClickedActor_x                                0x4BE1E0
#define CDisplay__GetUserDefinedColor_x                            0x4BCDC0
#define CDisplay__GetWorldFilePath_x                               0x4BC210
#define CDisplay__is3dON_x                                         0x4BB6A0
#define CDisplay__ReloadUI_x                                       0x4CF6E0
#define CDisplay__WriteTextHD2_x                                   0x4C1CB0
#define CDisplay__TrueDistance_x                                   0x4BEE10

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FD9F0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EABC0
#define CEditWnd__GetCharIndexPt_x                                 0x8EBD20
#define CEditWnd__GetDisplayString_x                               0x8EAD70
#define CEditWnd__GetHorzOffset_x                                  0x8EB0B0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EB7E0
#define CEditWnd__GetSelStartPt_x                                  0x8EBFE0
#define CEditWnd__GetSTMLSafeText_x                                0x8EB250
#define CEditWnd__PointFromPrintableChar_x                         0x8EB8D0
#define CEditWnd__SelectableCharFromPoint_x                        0x8EBA50
#define CEditWnd__SetEditable_x                                    0x8EB220

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x5699D0
#define CEverQuest__ClickedPlayer_x                                0x5635A0
#define CEverQuest__CreateTargetIndicator_x                        0x5644A0
#define CEverQuest__DeleteTargetIndicator_x                        0x564520
#define CEverQuest__DoTellWindow_x                                 0x475E70
#define CEverQuest__OutputTextToLog_x                              0x475AD0
#define CEverQuest__DropHeldItemOnGround_x                         0x579F20
#define CEverQuest__dsp_chat_x                                     0x4761B0
#define CEverQuest__trimName_x                                     0x55FEB0
#define CEverQuest__Emote_x                                        0x578230
#define CEverQuest__EnterZone_x                                    0x573310
#define CEverQuest__GetBodyTypeDesc_x                              0x55D8F0
#define CEverQuest__GetClassDesc_x                                 0x566DE0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5673E0
#define CEverQuest__GetDeityDesc_x                                 0x55E1D0
#define CEverQuest__GetLangDesc_x                                  0x55DC80
#define CEverQuest__GetRaceDesc_x                                  0x5675A0
#define CEverQuest__InterpretCmd_x                                 0x56B150
#define CEverQuest__LeftClickedOnPlayer_x                          0x57FA80
#define CEverQuest__LMouseUp_x                                     0x581A30
#define CEverQuest__RightClickedOnPlayer_x                         0x580590
#define CEverQuest__RMouseUp_x                                     0x581490
#define CEverQuest__SetGameState_x                                 0x563E70
#define CEverQuest__UPCNotificationFlush_x                         0x55C280
#define CEverQuest__IssuePetCommand_x                              0x56BB30

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B9670
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B96D0
#define CGaugeWnd__Draw_x                                          0x6B9B00

// CGuild
#define CGuild__FindMemberByName_x                                 0x43AF10
#define CGuild__GetGuildName_x                                     0x43B3E0
#define CGuild__GetGuildIndex_x                                    0x43C5F0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D5B60

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E2F20
#define CInvSlotMgr__MoveItem_x                                    0x6E36E0
#define CInvSlotMgr__SelectSlot_x                                  0x6E2810

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E1C70
#define CInvSlot__SliderComplete_x                                 0x6DF490
#define CInvSlot__GetItemBase_x                                    0x6DE910
#define CInvSlot__UpdateItem_x                                     0x6DEE90

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E4B40
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E5C80

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7ADAC0
#define CItemDisplayWnd__UpdateStrings_x                           0x6E6D90
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F35E0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F3AF0
#define CItemDisplayWnd__SetItem_x                                 0x6F93E0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E4DA0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6ED2F0

// CLabel 
#define CLabel__Draw_x                                             0x700170

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C2510
#define CListWnd__dCListWnd_x                                      0x8C37B0
#define CListWnd__AddColumn_x                                      0x8C3750
#define CListWnd__AddColumn1_x                                     0x8C2DE0
#define CListWnd__AddLine_x                                        0x8C27C0
#define CListWnd__AddString_x                                      0x8C29E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BF610
#define CListWnd__CalculateVSBRange_x                              0x8C19D0
#define CListWnd__ClearSel_x                                       0x8BE930
#define CListWnd__ClearAllSel_x                                    0x8BE8E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C23A0
#define CListWnd__Compare_x                                        0x8C0300
#define CListWnd__Draw_x                                           0x8C15D0
#define CListWnd__DrawColumnSeparators_x                           0x8C1460
#define CListWnd__DrawHeader_x                                     0x8BEBF0
#define CListWnd__DrawItem_x                                       0x8C0990
#define CListWnd__DrawLine_x                                       0x8C1100
#define CListWnd__DrawSeparator_x                                  0x8C1500
#define CListWnd__EnableLine_x                                     0x8BEB10
#define CListWnd__EnsureVisible_x                                  0x8BF770
#define CListWnd__ExtendSel_x                                      0x8C08A0
#define CListWnd__GetColumnMinWidth_x                              0x8BE220
#define CListWnd__GetColumnWidth_x                                 0x8BE150
#define CListWnd__GetCurSel_x                                      0x8BD920
#define CListWnd__GetItemAtPoint_x                                 0x8BFA10
#define CListWnd__GetItemAtPoint1_x                                0x8BFA80
#define CListWnd__GetItemData_x                                    0x8BDC60
#define CListWnd__GetItemHeight_x                                  0x8BF270
#define CListWnd__GetItemIcon_x                                    0x8BDE50
#define CListWnd__GetItemRect_x                                    0x8BF850
#define CListWnd__GetItemText_x                                    0x8BDD00
#define CListWnd__GetSelList_x                                     0x8C2CD0
#define CListWnd__GetSeparatorRect_x                               0x8C0230
#define CListWnd__InsertLine_x                                     0x8C2BC0
#define CListWnd__RemoveLine_x                                     0x8C2BD0
#define CListWnd__SetColors_x                                      0x8BDA70
#define CListWnd__SetColumnJustification_x                         0x8BE4B0
#define CListWnd__SetColumnWidth_x                                 0x8BE1D0
#define CListWnd__SetCurSel_x                                      0x8BD960
#define CListWnd__SetItemColor_x                                   0x8C2090
#define CListWnd__SetItemData_x                                    0x8BE990
#define CListWnd__SetItemText_x                                    0x8C1ED0
#define CListWnd__ShiftColumnSeparator_x                           0x8C1D60
#define CListWnd__Sort_x                                           0x8C38B0
#define CListWnd__ToggleSel_x                                      0x8BE860

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7191C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73E860
#define CMerchantWnd__RequestBuyItem_x                             0x746330
#define CMerchantWnd__RequestSellItem_x                            0x748930
#define CMerchantWnd__SelectRecoverySlot_x                         0x73BB40
#define CMerchantWnd__SelectBuySellSlot_x                          0x739AE0
#define CMerchantWnd__ActualSelect_x                               0x7405F0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8543F0
#define CPacketScrambler__hton_x                                   0x854400

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E15B0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1690
#define CSidlManager__CreateLabel_x                                0x7A2A70
#define CSidlManager__CreateXWndFromTemplate_x                     0x8DFB40
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E1970

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D8A70
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D8960
#define CSidlScreenWnd__ConvertToRes_x                             0x8FD8D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9380
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DA570
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DA620
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D9AF0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D8D30
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8490
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D8F20
#define CSidlScreenWnd__Init1_x                                    0x8DA250
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D9440
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8650
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D9D30
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D80E0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8440
#define CSidlScreenWnd__WndNotification_x                          0x8D9FD0
#define CSidlScreenWnd__GetChildItem_x                             0x8D8560
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CBD90
#define CSidlScreenWnd__m_layoutCopy_x                             0x172FE20

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x604950
#define CSkillMgr__GetSkillCap_x                                   0x604B30
#define CSkillMgr__GetNameToken_x                                  0x604500

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FCBA0
#define CSliderWnd__SetValue_x                                     0x8FCD70
#define CSliderWnd__SetNumTicks_x                                  0x8FD4F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A8DA0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6620
#define CStmlWnd__CalculateHSBRange_x                              0x8EEBB0
#define CStmlWnd__CalculateVSBRange_x                              0x8EEB20
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EED30
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EF530
#define CStmlWnd__ForceParseNow_x                                  0x8F6FA0
#define CStmlWnd__GetNextTagPiece_x                                0x8EF430
#define CStmlWnd__GetSTMLText_x                                    0x484020
#define CStmlWnd__GetVisibleText_x                                 0x8EFF80
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2530
#define CStmlWnd__MakeStmlColorTag_x                               0x8EDE00
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EDE60
#define CStmlWnd__SetSTMLText_x                                    0x8F3D80
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F62C0
#define CStmlWnd__UpdateHistoryString_x                            0x8F0EB0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FA4C0
#define CTabWnd__DrawCurrentPage_x                                 0x8F9D50
#define CTabWnd__DrawTab_x                                         0x8F9B10
#define CTabWnd__GetCurrentPage_x                                  0x8FA100
#define CTabWnd__GetPageInnerRect_x                                0x8F9800
#define CTabWnd__GetTabInnerRect_x                                 0x8F9A00
#define CTabWnd__GetTabRect_x                                      0x8F98D0
#define CTabWnd__InsertPage_x                                      0x8FA7B0
#define CTabWnd__SetPage_x                                         0x8FA130
#define CTabWnd__SetPageRect_x                                     0x8FA400
#define CTabWnd__UpdatePage_x                                      0x8FA750
#define CTabWnd__GetPageFromTabIndex_x                             0x8F9A60
#define CTabWnd__GetCurrentTabIndex_x                              0x8F9790

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E5E30
#define CPageWnd__SetTabText_x                                     0x906BE0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436A90

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D63C0
#define CTextureFont__GetTextExtent_x                              0x8D6120

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63D300

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x903020

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BBB80

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029C0
#define CXStr__CXStr1_x                                            0x7501C0
#define CXStr__CXStr3_x                                            0x89EEC0
#define CXStr__dCXStr_x                                            0x6B9550
#define CXStr__operator_equal_x                                    0x89F030
#define CXStr__operator_equal1_x                                   0x89F080
#define CXStr__operator_plus_equal1_x                              0x8A0180

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D3EC0
#define CXWnd__BringToTop_x                                        0x8CAF90
#define CXWnd__Center_x                                            0x8D11B0
#define CXWnd__ClrFocus_x                                          0x8CAB60
#define CXWnd__Destroy_x                                           0x8D1C70
#define CXWnd__DoAllDrawing_x                                      0x8D0DE0
#define CXWnd__DrawChildren_x                                      0x8D0F90
#define CXWnd__DrawColoredRect_x                                   0x8CB370
#define CXWnd__DrawTooltip_x                                       0x8CB610
#define CXWnd__DrawTooltipAtPoint_x                                0x8CFD00
#define CXWnd__GetBorderFrame_x                                    0x8CBA70
#define CXWnd__GetChildWndAt_x                                     0x8D1B50
#define CXWnd__GetClientClipRect_x                                 0x8CB830
#define CXWnd__GetScreenClipRect_x                                 0x8D0400
#define CXWnd__GetScreenRect_x                                     0x8CBC30
#define CXWnd__GetTooltipRect_x                                    0x8CB4A0
#define CXWnd__GetWindowTextA_x                                    0x426CB0
#define CXWnd__IsActive_x                                          0x8C6590
#define CXWnd__IsDescendantOf_x                                    0x8CB9C0
#define CXWnd__IsReallyVisible_x                                   0x8CED60
#define CXWnd__IsType_x                                            0x8D1220
#define CScreenPieceTemplate__IsType_x                             0x8FF7B0
#define CXWnd__Move_x                                              0x8CE490
#define CXWnd__Move1_x                                             0x8D0A70
#define CXWnd__ProcessTransition_x                                 0x8CAF40
#define CXWnd__Refade_x                                            0x8CAD10
#define CXWnd__Resize_x                                            0x8CBD00
#define CXWnd__Right_x                                             0x8D0200
#define CXWnd__SetFocus_x                                          0x8CD5D0
#define CXWnd__SetFont_x                                           0x8CABB0
#define CXWnd__SetKeyTooltip_x                                     0x8CBF60
#define CXWnd__SetMouseOver_x                                      0x8D0750
#define CXWnd__StartFade_x                                         0x8CAFE0
#define CXWnd__GetChildItem_x                                      0x8D0690
#define CXWnd__SetParent_x                                         0x8D1B00

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C7E40
#define CXWndManager__DrawWindows_x                                0x8C7A80
#define CXWndManager__GetKeyboardFlags_x                           0x8C60C0
#define CXWndManager__HandleKeyboardMsg_x                          0x8C6A20
#define CXWndManager__RemoveWnd_x                                  0x8C6720

// CDBStr
#define CDBStr__GetString_x                                        0x4B9EC0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452360
#define EQ_Character__Cur_HP_x                                     0x466700
#define EQ_Character__Cur_Mana_x                                   0x45B700
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B440
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443430
#define EQ_Character__GetFocusRangeModifier_x                      0x443580
#define EQ_Character__GetHPRegen_x                                 0x46A2A0
#define EQ_Character__GetEnduranceRegen_x                          0x465D10
#define EQ_Character__GetManaRegen_x                               0x46A840
#define EQ_Character__Max_Endurance_x                              0x5CB2A0
#define EQ_Character__Max_HP_x                                     0x45E280
#define EQ_Character__Max_Mana_x                                   0x5CB0D0
#define EQ_Character__doCombatAbility_x                            0x5C87A0
#define EQ_Character__UseSkill_x                                   0x472630
#define EQ_Character__GetConLevel_x                                0x5BDCE0
#define EQ_Character__IsExpansionFlag_x                            0x4B6200
#define EQ_Character__TotalEffect_x                                0x44F590
#define EQ_Character__GetPCSpellAffect_x                           0x44B7D0
#define EQ_Character__SpellDuration_x                              0x4497D0
#define EQ_Character__FindItemByRecord_x                           0x463D60
#define EQ_Character__GetAdjustedSkill_x                           0x4668D0
#define EQ_Character__GetBaseSkill_x                               0x45E160

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x872210

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D39A0

//PcClient
#define PcClient__PcClient_x                                       0x5BFB30

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x4468F0
#define CCharacterSelect__EnterWorld_x                             0x4460C0
#define CCharacterSelect__Quit_x                                   0x444C80

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59DCE0
#define EQ_Item__CreateItemTagString_x                             0x852620
#define EQ_Item__IsStackable_x                                     0x847BD0
#define EQ_Item__GetImageNum_x                                     0x84A730
#define EQ_Item__CreateItemClient_x                                0x59EE10
#define EQ_Item__GetItemValue_x                                    0x851050
#define EQ_Item__ValueSellMerchant_x                               0x854080
#define EQ_Item__IsKeyRingItem_x                                   0x848750
#define EQ_Item__CanGoInBag_x                                      0x59DE70
#define EQ_Item__GetMaxItemCount_x                                 0x847AC0
#define EQ_Item__GetHeldItem_x                                     0x849540
#define EQ_Item__GetAugmentFitBySlot_x                             0x853EA0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4D9FB0
#define EQ_LoadingS__Array_x                                       0xC0AC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CD7D0
#define EQ_PC__GetAlternateAbilityId_x                             0x85C450
#define EQ_PC__GetCombatAbility_x                                  0x85C4E0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8570A0
#define EQ_PC__GetItemRecastTimer_x                                0x5C6FA0
#define EQ_PC__HasLoreItem_x                                       0x5C12F0
#define EQ_PC__AlertInventoryChanged_x                             0x5BDC90
#define EQ_PC__GetPcZoneClient_x                                   0x5E7F70
#define EQ_PC__RemoveMyAffect_x                                    0x5C6400
#define EQ_PC__GetKeyRingItems_x                                   0x8574C0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86A120
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85E3B0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x525F60
#define EQItemList__add_object_x                                   0x553200
#define EQItemList__add_item_x                                     0x525EA0
#define EQItemList__delete_item_x                                  0x526350
#define EQItemList__FreeItemList_x                                 0x526250

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9180

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D3660
#define EQPlayer__dEQPlayer_x                                      0x5DBE10
#define EQPlayer__DoAttack_x                                       0x5ED710
#define EQPlayer__EQPlayer_x                                       0x5DE540
#define EQPlayer__SetNameSpriteState_x                             0x5D8C40
#define EQPlayer__SetNameSpriteTint_x                              0x5D4B60
#define PlayerBase__HasProperty_j_x                                0x930F60
#define EQPlayer__IsTargetable_x                                   0x931200
#define EQPlayer__CanSee_x                                         0x931760
#define PlayerZoneClient__ChangeHeight_x                           0x5ED5D0
#define EQPlayer__CanSee1_x                                        0x931850
#define PlayerBase__GetVisibilityLineSegment_x                     0x9314F0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E8120
#define PlayerZoneClient__IsValidTeleport_x                        0x553AB0
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D22E0


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E25B0
#define EQPlayerManager__GetSpawnByName_x                          0x5E2A10
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E25E0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A4340
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A4380
#define KeypressHandler__ClearCommandStateArray_x                  0x5A3F30
#define KeypressHandler__HandleKeyDown_x                           0x5A2850
#define KeypressHandler__HandleKeyUp_x                             0x5A2B70
#define KeypressHandler__SaveKeymapping_x                          0x5A4000

// MapViewMap 
#define MapViewMap__Clear_x                                        0x711B50
#define MapViewMap__SaveEx_x                                       0x714E80
#define MapViewMap__SetZoom_x                                      0x7117D0

#define PlayerPointManager__GetAltCurrency_x                       0x8702D0

// StringTable 
#define StringTable__getString_x                                   0x86A450

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CAD30
#define PcZoneClient__RemovePetEffect_x                            0x5C7470
#define PcZoneClient__HasAlternateAbility_x                        0x5C7E10
#define PcZoneClient__GetCurrentMod_x                              0x45D730
#define PcZoneClient__GetModCap_x                                  0x45AE60
#define PcZoneClient__CanEquipItem_x                               0x5C82F0
#define PcZoneClient__GetItemByID_x                                0x5CCB40
#define PcZoneClient__GetItemByItemClass_x                         0x5CD6F0
#define PcZoneClient__RemoveBuffEffect_x                           0x5C66B0

//Doors
#define EQSwitch__UseSwitch_x                                      0x55ABE0

//IconCache
#define IconCache__GetIcon_x                                       0x6AEEC0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A5DB0
#define CContainerMgr__CloseContainer_x                            0x6A65D0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x772890

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x596D40

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4550
#define EQ_Spell__SpellAffects_x                                   0x4F1730
#define EQ_Spell__SpellAffectBase_x                                0x4F17A0
#define CharacterZoneClient__CalcAffectChange_x                    0x44B660
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44A900
#define CLootWnd__LootAll_x                                        0x707400
#define CLootWnd__RequestLootSlot_x                                0x707C10
#define EQ_Spell__IsStackable_x                                    0x458E40
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4492A0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43E980
#define EQ_Spell__IsSPAStacking_x                                  0x4F12A0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2340
#define EQ_Spell__IsNoRemove_x                                     0x434AC0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F12C0

#define __IsResEffectSpell_x                                       0x449320

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87BEB0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BA6E0
#define CTargetWnd__WndNotification_x                              0x7BA1D0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BA8C0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7BF810

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ECE20
#define EqSoundManager__PlayScriptMp3_x                            0x4EE8C0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A82F0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EA1F0
#define CSidlManager__FindAnimation1_x                             0x8DF570

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E1810
#define CAltAbilityData__GetMercMaxRank_x                          0x4E17C0
#define CAltAbilityData__GetMaxRank_x                              0x4D60B0

//CTargetRing
#define CTargetRing__Cast_x                                        0x594980

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459180
#define CharacterBase__CreateItemGlobalIndex_x                     0x475060
#define CharacterBase__CreateItemIndex_x                           0x51F550
#define CharacterBase__GetItemPossession_x                         0x444150
#define CharacterBase__GetItemByGlobalIndex_x                      0x87FD00
#define CharacterBase__GetEffectId_x                               0x459140

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68EC10
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68E370

//messages
#define msg_spell_worn_off_x                                       0x4FC0D0
#define msg_new_text_x                                             0x505850
#define msgTokenTextParam_x                                        0x502050

//SpellManager
#define SpellManager__vftable_x                                    0xAC8258
#define SpellManager__SpellManager_x                               0x47DC90
#define Spellmanager__LoadTextSpells_x                             0x60B890

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x935290

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487770
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43E8A0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x448FE0
#define ItemGlobalIndex__IsValidIndex_x                            0x458980

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87DB70
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87CAB0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7003C0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AAAF0
#define CCursorAttachment__Deactivate_x                            0x6AA030

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FC0A0
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FC220

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x603500

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48BFF0

//IString
#define IString__Append_x                                          0x47E8E0

//Camera
#define CDisplay__cameraType_x                                     0xE6E7C8
#define EverQuest__Cameras_x                                       0xF30AC8
