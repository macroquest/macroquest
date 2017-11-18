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
#define __ExpectedVersionDate                                     "Nov 18 2017"
#define __ExpectedVersionTime                                     "04:17:24"
#define __ActualVersionDate_x                                      0xAE3080
#define __ActualVersionTime_x                                      0xAE308C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AA3E0
#define __MemChecker1_x                                            0x8A2E80
#define __MemChecker2_x                                            0x640200
#define __MemChecker3_x                                            0x640150
#define __MemChecker4_x                                            0x7F4700
#define __EncryptPad0_x                                            0xC3DFE8
#define __EncryptPad1_x                                            0xD17BA0
#define __EncryptPad2_x                                            0xC66ED0
#define __EncryptPad3_x                                            0xC66AD0
#define __EncryptPad4_x                                            0xD061A0
#define __EncryptPad5_x                                            0x10C12C0
#define __AC1_x                                                    0x7B3625
#define __AC2_x                                                    0x563687
#define __AC3_x                                                    0x561800
#define __AC4_x                                                    0x5739D1
#define __AC5_x                                                    0x58772B
#define __AC6_x                                                    0x58B2DE
#define __AC7_x                                                    0x581D2C
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
#define __do_loot_x                                                0x5325D0
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
#define __CastRay_x                                                0x549F60
#define __CastRay2_x                                               0x549890
#define __HeadingDiff_x                                            0x932B10
#define __FixHeading_x                                             0x932AA0
#define __get_bearing_x                                            0x539720
#define __ConvertItemTags_x                                        0x5371F0
#define __ExecuteCmd_x                                             0x521B10
#define __EQGetTime_x                                              0x8A2820
#define __get_melee_range_x                                        0x5287D0
#define __GetGaugeValueFromEQ_x                                    0x7B21E0
#define __GetLabelFromEQ_x                                         0x7B35B0
#define __ToggleKeyRingItem_x                                      0x48FF00
#define __GetXTargetType_x                                         0x934710
#define __LoadFrontEnd_x                                           0x63F8D0
#define __NewUIINI_x                                               0x7B1BB0
#define __ProcessGameEvents_x                                      0x583AC0
#define __ProcessMouseEvent_x                                      0x583260
#define CrashDetected_x                                            0x641290
#define wwsCrashReportCheckForUploader_x                           0x8006B0
#define __AppCrashWrapper_x                                        0xC66AC4
#define __pCrashHandler_x                                          0x10D69E0
#define __CrashHandler_x                                           0x800140
#define wwsCrashReportPlatformLaunchUploader_x                     0x8028F0
#define DrawNetStatus_x                                            0x5BA210
#define Util__FastTime_x                                           0x8A24C0
#define Expansion_HoT_x                                            0xF307B0
#define __HelpPath_x                                               0xFB3F60
#define __STMLToText_x                                             0x8E8A50
#define __GetAnimationCache_x                                      0x6AF070

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423330
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DF90
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DD60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D8200
#define AltAdvManager__IsAbilityReady_x                            0x4D8270
#define AltAdvManager__GetAAById_x                                 0x4D8760
#define AltAdvManager__CanTrainAbility_x                           0x4D9390
#define AltAdvManager__CanSeeAbility_x                             0x4D8F50

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AFC0
#define CharacterZoneClient__HasSkill_x                            0x466EA0
#define CharacterZoneClient__MakeMeVisible_x                       0x46CB30
#define CharacterZoneClient__IsStackBlocked_x                      0x44BF30
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B450
#define CharacterZoneClient__GetItemCountWorn_x                    0x465400
#define CharacterZoneClient__GetItemCountInInventory_x             0x4654E0
#define CharacterZoneClient__GetCursorItemCount_x                  0x4655C0
#define CharacterZoneClient__FindAffectSlot_x                      0x4515E0
#define CharacterZoneClient__BardCastBard_x                        0x44ABC0
#define CharacterZoneClient__GetMaxEffects_x                       0x449750
#define CharacterZoneClient__GetEffect_x                           0x44B680
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451440
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449AA0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FF90

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66F220

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67D0D0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x598C40
#define CButtonWnd__CButtonWnd_x                                   0x8DCCD0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6982A0
#define CChatManager__InitContextMenu_x                            0x6993F0
#define CChatManager__FreeChatWindow_x                             0x697D50
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A1530
#define CChatManager__SetLockedActiveChatWindow_x                  0x698270

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E6DB0
#define CContextMenu__dCContextMenu_x                              0x8E6FB0
#define CContextMenu__AddMenuItem_x                                0x8E74D0
#define CContextMenu__RemoveMenuItem_x                             0x8E7130
#define CContextMenu__RemoveAllMenuItems_x                         0x8E7150
#define CContextMenu__CheckMenuItem_x                              0x8E71D0
#define CContextMenu__SetMenuItem_x                                0x8E7050

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D32D0
#define CContextMenuManager__RemoveMenu_x                          0x8D3650
#define CContextMenuManager__PopupMenu_x                           0x8D3AA0
#define CContextMenuManager__Flush_x                               0x8D3340
#define CContextMenuManager__GetMenu_x                             0x419460

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x886980
#define CChatService__GetFriendName_x                              0x886990

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69F020
#define CChatWindow__Clear_x                                       0x69E900
#define CChatWindow__WndNotification_x                             0x69F920

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D7100
#define CComboWnd__Draw_x                                          0x8D7310
#define CComboWnd__GetCurChoice_x                                  0x8D6EB0
#define CComboWnd__GetListRect_x                                   0x8D75B0
#define CComboWnd__GetTextRect_x                                   0x8D7170
#define CComboWnd__InsertChoice_x                                  0x8D7710
#define CComboWnd__SetColors_x                                     0x8D6E40
#define CComboWnd__SetChoice_x                                     0x8D6E70
#define CComboWnd__GetItemCount_x                                  0x8D6EA0
#define CComboWnd__GetCurChoiceText_x                              0x8D6EF0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A9200
#define CContainerWnd__vftable_x                                   0xAEC998

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C6160
#define CDisplay__GetClickedActor_x                                0x4BEA30
#define CDisplay__GetUserDefinedColor_x                            0x4BD610
#define CDisplay__GetWorldFilePath_x                               0x4BCA60
#define CDisplay__is3dON_x                                         0x4BBEF0
#define CDisplay__ReloadUI_x                                       0x4CFF20
#define CDisplay__WriteTextHD2_x                                   0x4C24F0
#define CDisplay__TrueDistance_x                                   0x4BF660

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FDDF0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EB300
#define CEditWnd__GetCharIndexPt_x                                 0x8EC460
#define CEditWnd__GetDisplayString_x                               0x8EB4B0
#define CEditWnd__GetHorzOffset_x                                  0x8EB7F0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EBF20
#define CEditWnd__GetSelStartPt_x                                  0x8EC720
#define CEditWnd__GetSTMLSafeText_x                                0x8EB990
#define CEditWnd__PointFromPrintableChar_x                         0x8EC010
#define CEditWnd__SelectableCharFromPoint_x                        0x8EC190
#define CEditWnd__SetEditable_x                                    0x8EB960

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56A200
#define CEverQuest__ClickedPlayer_x                                0x563DD0
#define CEverQuest__CreateTargetIndicator_x                        0x564CD0
#define CEverQuest__DeleteTargetIndicator_x                        0x564D50
#define CEverQuest__DoTellWindow_x                                 0x476240
#define CEverQuest__OutputTextToLog_x                              0x475EA0
#define CEverQuest__DropHeldItemOnGround_x                         0x57A770
#define CEverQuest__dsp_chat_x                                     0x476580
#define CEverQuest__trimName_x                                     0x5606E0
#define CEverQuest__Emote_x                                        0x578A80
#define CEverQuest__EnterZone_x                                    0x573B60
#define CEverQuest__GetBodyTypeDesc_x                              0x55E120
#define CEverQuest__GetClassDesc_x                                 0x567610
#define CEverQuest__GetClassThreeLetterCode_x                      0x567C10
#define CEverQuest__GetDeityDesc_x                                 0x55EA00
#define CEverQuest__GetLangDesc_x                                  0x55E4B0
#define CEverQuest__GetRaceDesc_x                                  0x567DD0
#define CEverQuest__InterpretCmd_x                                 0x56B980
#define CEverQuest__LeftClickedOnPlayer_x                          0x5802D0
#define CEverQuest__LMouseUp_x                                     0x582280
#define CEverQuest__RightClickedOnPlayer_x                         0x580DE0
#define CEverQuest__RMouseUp_x                                     0x581CE0
#define CEverQuest__SetGameState_x                                 0x5646A0
#define CEverQuest__UPCNotificationFlush_x                         0x55CAB0
#define CEverQuest__IssuePetCommand_x                              0x56C360

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B9F30
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B9F90
#define CGaugeWnd__Draw_x                                          0x6BA3C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B160
#define CGuild__GetGuildName_x                                     0x43B630
#define CGuild__GetGuildIndex_x                                    0x43C840

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D6410

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E37E0
#define CInvSlotMgr__MoveItem_x                                    0x6E3FA0
#define CInvSlotMgr__SelectSlot_x                                  0x6E30D0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E2530
#define CInvSlot__SliderComplete_x                                 0x6DFD50
#define CInvSlot__GetItemBase_x                                    0x6DF1B0
#define CInvSlot__UpdateItem_x                                     0x6DF730

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E53F0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E6520

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AE050
#define CItemDisplayWnd__UpdateStrings_x                           0x6E7620
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F3EA0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F43B0
#define CItemDisplayWnd__SetItem_x                                 0x6F9C00

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E51E0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EDBA0

// CLabel 
#define CLabel__Draw_x                                             0x7009A0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C2E40
#define CListWnd__dCListWnd_x                                      0x8C40E0
#define CListWnd__AddColumn_x                                      0x8C4080
#define CListWnd__AddColumn1_x                                     0x8C3720
#define CListWnd__AddLine_x                                        0x8C3100
#define CListWnd__AddString_x                                      0x8C3320
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BFF50
#define CListWnd__CalculateVSBRange_x                              0x8C2300
#define CListWnd__ClearSel_x                                       0x8BF270
#define CListWnd__ClearAllSel_x                                    0x8BF220
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C2CD0
#define CListWnd__Compare_x                                        0x8C0C40
#define CListWnd__Draw_x                                           0x8C1F00
#define CListWnd__DrawColumnSeparators_x                           0x8C1D90
#define CListWnd__DrawHeader_x                                     0x8BF530
#define CListWnd__DrawItem_x                                       0x8C12C0
#define CListWnd__DrawLine_x                                       0x8C1A30
#define CListWnd__DrawSeparator_x                                  0x8C1E30
#define CListWnd__EnableLine_x                                     0x8BF450
#define CListWnd__EnsureVisible_x                                  0x8C00B0
#define CListWnd__ExtendSel_x                                      0x8C11D0
#define CListWnd__GetColumnMinWidth_x                              0x8BEB60
#define CListWnd__GetColumnWidth_x                                 0x8BEA90
#define CListWnd__GetCurSel_x                                      0x8BE270
#define CListWnd__GetItemAtPoint_x                                 0x8C0350
#define CListWnd__GetItemAtPoint1_x                                0x8C03C0
#define CListWnd__GetItemData_x                                    0x8BE5A0
#define CListWnd__GetItemHeight_x                                  0x8BFBB0
#define CListWnd__GetItemIcon_x                                    0x8BE790
#define CListWnd__GetItemRect_x                                    0x8C0190
#define CListWnd__GetItemText_x                                    0x8BE640
#define CListWnd__GetSelList_x                                     0x8C3610
#define CListWnd__GetSeparatorRect_x                               0x8C0B70
#define CListWnd__InsertLine_x                                     0x8C3500
#define CListWnd__RemoveLine_x                                     0x8C3510
#define CListWnd__SetColors_x                                      0x8BE3C0
#define CListWnd__SetColumnJustification_x                         0x8BEDF0
#define CListWnd__SetColumnWidth_x                                 0x8BEB10
#define CListWnd__SetCurSel_x                                      0x8BE2B0
#define CListWnd__SetItemColor_x                                   0x8C29C0
#define CListWnd__SetItemData_x                                    0x8BF2D0
#define CListWnd__SetItemText_x                                    0x8C2800
#define CListWnd__ShiftColumnSeparator_x                           0x8C2690
#define CListWnd__Sort_x                                           0x8C41E0
#define CListWnd__ToggleSel_x                                      0x8BF1A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x719BB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73F080
#define CMerchantWnd__RequestBuyItem_x                             0x746B00
#define CMerchantWnd__RequestSellItem_x                            0x749100
#define CMerchantWnd__SelectRecoverySlot_x                         0x73C360
#define CMerchantWnd__SelectBuySellSlot_x                          0x73A300
#define CMerchantWnd__ActualSelect_x                               0x740E20

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x854C00
#define CPacketScrambler__hton_x                                   0x854C10

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E1C90
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1D70
#define CSidlManager__CreateLabel_x                                0x7A3000
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E0240
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E2050

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D9130
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D9030
#define CSidlScreenWnd__ConvertToRes_x                             0x8FDCD0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9A30
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DAC00
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DACB0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DA180
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D93E0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8B60
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D95D0
#define CSidlScreenWnd__Init1_x                                    0x8DA8D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D9AE0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8D20
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DA3C0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D87C0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8B10
#define CSidlScreenWnd__WndNotification_x                          0x8DA650
#define CSidlScreenWnd__GetChildItem_x                             0x8D8C30
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CC560
#define CSidlScreenWnd__m_layoutCopy_x                             0x172FE20

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x605260
#define CSkillMgr__GetSkillCap_x                                   0x605440
#define CSkillMgr__GetNameToken_x                                  0x604E10

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FCF90
#define CSliderWnd__SetValue_x                                     0x8FD160
#define CSliderWnd__SetNumTicks_x                                  0x8FD8E0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A9340

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6D90
#define CStmlWnd__CalculateHSBRange_x                              0x8EF300
#define CStmlWnd__CalculateVSBRange_x                              0x8EF270
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EF480
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EFC80
#define CStmlWnd__ForceParseNow_x                                  0x8F7710
#define CStmlWnd__GetNextTagPiece_x                                0x8EFB80
#define CStmlWnd__GetSTMLText_x                                    0x484430
#define CStmlWnd__GetVisibleText_x                                 0x8F06D0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2C80
#define CStmlWnd__MakeStmlColorTag_x                               0x8EE550
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EE5B0
#define CStmlWnd__SetSTMLText_x                                    0x8F44D0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6A30
#define CStmlWnd__UpdateHistoryString_x                            0x8F1600

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FAC20
#define CTabWnd__DrawCurrentPage_x                                 0x8FA4B0
#define CTabWnd__DrawTab_x                                         0x8FA270
#define CTabWnd__GetCurrentPage_x                                  0x8FA860
#define CTabWnd__GetPageInnerRect_x                                0x8F9F60
#define CTabWnd__GetTabInnerRect_x                                 0x8FA160
#define CTabWnd__GetTabRect_x                                      0x8FA030
#define CTabWnd__InsertPage_x                                      0x8FAF10
#define CTabWnd__SetPage_x                                         0x8FA890
#define CTabWnd__SetPageRect_x                                     0x8FAB60
#define CTabWnd__UpdatePage_x                                      0x8FAEB0
#define CTabWnd__GetPageFromTabIndex_x                             0x8FA1C0
#define CTabWnd__GetCurrentTabIndex_x                              0x8F9EF0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E66D0
#define CPageWnd__SetTabText_x                                     0x907080

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436D80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D6AB0
#define CTextureFont__GetTextExtent_x                              0x8D6810

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63DB30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x903470

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BC460

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5A6840
#define CXStr__CXStr1_x                                            0x8B1290
#define CXStr__CXStr3_x                                            0x89F710
#define CXStr__dCXStr_x                                            0x6B9E10
#define CXStr__operator_equal_x                                    0x89F880
#define CXStr__operator_equal1_x                                   0x89F8D0
#define CXStr__operator_plus_equal1_x                              0x8A09D0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D45C0
#define CXWnd__BringToTop_x                                        0x8CB7A0
#define CXWnd__Center_x                                            0x8D18A0
#define CXWnd__ClrFocus_x                                          0x8CB380
#define CXWnd__Destroy_x                                           0x8D2380
#define CXWnd__DoAllDrawing_x                                      0x8D1500
#define CXWnd__DrawChildren_x                                      0x8D16A0
#define CXWnd__DrawColoredRect_x                                   0x8CBB80
#define CXWnd__DrawTooltip_x                                       0x8CBE20
#define CXWnd__DrawTooltipAtPoint_x                                0x8D04A0
#define CXWnd__GetBorderFrame_x                                    0x8CC260
#define CXWnd__GetChildWndAt_x                                     0x8D2270
#define CXWnd__GetClientClipRect_x                                 0x8CC040
#define CXWnd__GetScreenClipRect_x                                 0x8D0BA0
#define CXWnd__GetScreenRect_x                                     0x8CC400
#define CXWnd__GetTooltipRect_x                                    0x8CBCB0
#define CXWnd__GetWindowTextA_x                                    0x426E40
#define CXWnd__IsActive_x                                          0x8C6EA0
#define CXWnd__IsDescendantOf_x                                    0x8CC1B0
#define CXWnd__IsReallyVisible_x                                   0x8CF4F0
#define CXWnd__IsType_x                                            0x8D1910
#define CScreenPieceTemplate__IsType_x                             0x8FFB80
#define CXWnd__Move_x                                              0x8CEBE0
#define CXWnd__Move1_x                                             0x8D11D0
#define CXWnd__ProcessTransition_x                                 0x8CB750
#define CXWnd__Refade_x                                            0x8CB530
#define CXWnd__Resize_x                                            0x8CC4C0
#define CXWnd__Right_x                                             0x8D09A0
#define CXWnd__SetFocus_x                                          0x8CDD40
#define CXWnd__SetFont_x                                           0x8CB3D0
#define CXWnd__SetKeyTooltip_x                                     0x8CC730
#define CXWnd__SetMouseOver_x                                      0x8D0EC0
#define CXWnd__StartFade_x                                         0x8CB7F0
#define CXWnd__GetChildItem_x                                      0x8D0E00
#define CXWnd__SetParent_x                                         0x8D2220

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C8740
#define CXWndManager__DrawWindows_x                                0x8C8390
#define CXWndManager__GetKeyboardFlags_x                           0x8C6A10
#define CXWndManager__HandleKeyboardMsg_x                          0x8C7330
#define CXWndManager__RemoveWnd_x                                  0x8C7030

// CDBStr
#define CDBStr__GetString_x                                        0x4BA750

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4526A0
#define EQ_Character__Cur_HP_x                                     0x466A80
#define EQ_Character__Cur_Mana_x                                   0x45BA60
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B760
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4436F0
#define EQ_Character__GetFocusRangeModifier_x                      0x443840
#define EQ_Character__GetHPRegen_x                                 0x46A650
#define EQ_Character__GetEnduranceRegen_x                          0x466090
#define EQ_Character__GetManaRegen_x                               0x46ABF0
#define EQ_Character__Max_Endurance_x                              0x5CBDC0
#define EQ_Character__Max_HP_x                                     0x45E5E0
#define EQ_Character__Max_Mana_x                                   0x5CBBF0
#define EQ_Character__doCombatAbility_x                            0x5C92C0
#define EQ_Character__UseSkill_x                                   0x4729E0
#define EQ_Character__GetConLevel_x                                0x5BE860
#define EQ_Character__IsExpansionFlag_x                            0x4B6A60
#define EQ_Character__TotalEffect_x                                0x44F8D0
#define EQ_Character__GetPCSpellAffect_x                           0x44BAF0
#define EQ_Character__SpellDuration_x                              0x449AF0
#define EQ_Character__FindItemByRecord_x                           0x4640D0
#define EQ_Character__GetAdjustedSkill_x                           0x466C50
#define EQ_Character__GetBaseSkill_x                               0x45E4C0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x872B70

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D4420

//PcClient
#define PcClient__PcClient_x                                       0x5C06B0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446BE0
#define CCharacterSelect__EnterWorld_x                             0x4463B0
#define CCharacterSelect__Quit_x                                   0x444F70

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59E580
#define EQ_Item__CreateItemTagString_x                             0x852DA0
#define EQ_Item__IsStackable_x                                     0x8480F0
#define EQ_Item__GetImageNum_x                                     0x84ABB0
#define EQ_Item__CreateItemClient_x                                0x59F6A0
#define EQ_Item__GetItemValue_x                                    0x851800
#define EQ_Item__ValueSellMerchant_x                               0x854850
#define EQ_Item__IsKeyRingItem_x                                   0x848BD0
#define EQ_Item__CanGoInBag_x                                      0x59E710
#define EQ_Item__GetMaxItemCount_x                                 0x847FE0
#define EQ_Item__GetHeldItem_x                                     0x8499D0
#define EQ_Item__GetAugmentFitBySlot_x                             0x854670

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA7E0
#define EQ_LoadingS__Array_x                                       0xC0AC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CE2F0
#define EQ_PC__GetAlternateAbilityId_x                             0x85CD10
#define EQ_PC__GetCombatAbility_x                                  0x85CDA0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8578B0
#define EQ_PC__GetItemRecastTimer_x                                0x5C7AB0
#define EQ_PC__HasLoreItem_x                                       0x5C1E70
#define EQ_PC__AlertInventoryChanged_x                             0x5BE810
#define EQ_PC__GetPcZoneClient_x                                   0x5E8960
#define EQ_PC__RemoveMyAffect_x                                    0x5C6F10
#define EQ_PC__GetKeyRingItems_x                                   0x857CD0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86AA40
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85ECB0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x526860
#define EQItemList__add_object_x                                   0x553A30
#define EQItemList__add_item_x                                     0x5267A0
#define EQItemList__delete_item_x                                  0x526C50
#define EQItemList__FreeItemList_x                                 0x526B50

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9A20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D40E0
#define EQPlayer__dEQPlayer_x                                      0x5DC890
#define EQPlayer__DoAttack_x                                       0x5EE110
#define EQPlayer__EQPlayer_x                                       0x5DEFB0
#define EQPlayer__SetNameSpriteState_x                             0x5D96C0
#define EQPlayer__SetNameSpriteTint_x                              0x5D55E0
#define PlayerBase__HasProperty_j_x                                0x930F00
#define EQPlayer__IsTargetable_x                                   0x9311A0
#define EQPlayer__CanSee_x                                         0x931700
#define PlayerZoneClient__ChangeHeight_x                           0x5EDFD0
#define EQPlayer__CanSee1_x                                        0x9317F0
#define PlayerBase__GetVisibilityLineSegment_x                     0x931490

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E8B10
#define PlayerZoneClient__IsValidTeleport_x                        0x5542D0
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2B10


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E2FA0
#define EQPlayerManager__GetSpawnByName_x                          0x5E3400
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E2FD0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A4BD0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A4C10
#define KeypressHandler__ClearCommandStateArray_x                  0x5A47C0
#define KeypressHandler__HandleKeyDown_x                           0x5A30E0
#define KeypressHandler__HandleKeyUp_x                             0x5A3400
#define KeypressHandler__SaveKeymapping_x                          0x5A4890

// MapViewMap 
#define MapViewMap__Clear_x                                        0x712540
#define MapViewMap__SaveEx_x                                       0x715870
#define MapViewMap__SetZoom_x                                      0x7121C0

#define PlayerPointManager__GetAltCurrency_x                       0x870C30

// StringTable 
#define StringTable__getString_x                                   0x86AD70

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CB850
#define PcZoneClient__RemovePetEffect_x                            0x5C7F80
#define PcZoneClient__HasAlternateAbility_x                        0x5C8920
#define PcZoneClient__GetCurrentMod_x                              0x45DA90
#define PcZoneClient__GetModCap_x                                  0x45B1C0
#define PcZoneClient__CanEquipItem_x                               0x5C8E00
#define PcZoneClient__GetItemByID_x                                0x5CD660
#define PcZoneClient__GetItemByItemClass_x                         0x5CE210
#define PcZoneClient__RemoveBuffEffect_x                           0x5C71C0

//Doors
#define EQSwitch__UseSwitch_x                                      0x55B340

//IconCache
#define IconCache__GetIcon_x                                       0x6AF6A0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A65B0
#define CContainerMgr__CloseContainer_x                            0x6A6DD0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x772EA0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x597670

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4C70
#define EQ_Spell__SpellAffects_x                                   0x4F1E50
#define EQ_Spell__SpellAffectBase_x                                0x4F1EC0
#define CharacterZoneClient__CalcAffectChange_x                    0x44B980
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AC20
#define CLootWnd__LootAll_x                                        0x707D60
#define CLootWnd__RequestLootSlot_x                                0x708570
#define EQ_Spell__IsStackable_x                                    0x4591D0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4495B0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EC40
#define EQ_Spell__IsSPAStacking_x                                  0x4F19C0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2A60
#define EQ_Spell__IsNoRemove_x                                     0x434DD0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F19E0

#define __IsResEffectSpell_x                                       0x449640

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87C800

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BAC40
#define CTargetWnd__WndNotification_x                              0x7BA730
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BAE20

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7BFD70

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED4C0
#define EqSoundManager__PlayScriptMp3_x                            0x4EEF60

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8AD0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EA930
#define CSidlManager__FindAnimation1_x                             0x8DFC70

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E20A0
#define CAltAbilityData__GetMercMaxRank_x                          0x4E2050
#define CAltAbilityData__GetMaxRank_x                              0x4D68B0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5952B0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4594C0
#define CharacterBase__CreateItemGlobalIndex_x                     0x475410
#define CharacterBase__CreateItemIndex_x                           0x51FE20
#define CharacterBase__GetItemPossession_x                         0x444410
#define CharacterBase__GetItemByGlobalIndex_x                      0x880650
#define CharacterBase__GetEffectId_x                               0x459480

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68F3E0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68EB40

//messages
#define msg_spell_worn_off_x                                       0x4FC740
#define msg_new_text_x                                             0x505ED0
#define msgTokenTextParam_x                                        0x5026D0

//SpellManager
#define SpellManager__vftable_x                                    0xAC8258
#define SpellManager__SpellManager_x                               0x47E090
#define Spellmanager__LoadTextSpells_x                             0x60C1D0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x935230

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487F40
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EB60
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4492E0
#define ItemGlobalIndex__IsValidIndex_x                            0x458CD0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87E4C0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87D400

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x700BF0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AB2C0
#define CCursorAttachment__Deactivate_x                            0x6AA810

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FC490
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FC610

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x603E30

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C7A0

//IString
#define IString__Append_x                                          0x47ED30

//Camera
#define CDisplay__cameraType_x                                     0xE6E7C8
#define EverQuest__Cameras_x                                       0xF30AC8
