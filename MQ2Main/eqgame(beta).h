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
#define __ExpectedVersionDate                                     "Nov 13 2017"
#define __ExpectedVersionTime                                     "04:16:25"
#define __ActualVersionDate_x                                      0xAE3090
#define __ActualVersionTime_x                                      0xAE309C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AA0E0
#define __MemChecker1_x                                            0x8A2870
#define __MemChecker2_x                                            0x63FB70
#define __MemChecker3_x                                            0x63FAC0
#define __MemChecker4_x                                            0x7F46B0
#define __EncryptPad0_x                                            0xC3DFE8
#define __EncryptPad1_x                                            0xD17BA0
#define __EncryptPad2_x                                            0xC66ED0
#define __EncryptPad3_x                                            0xC66AD0
#define __EncryptPad4_x                                            0xD061A0
#define __EncryptPad5_x                                            0x10C12C0
#define __AC1_x                                                    0x7B38A5
#define __AC2_x                                                    0x5634D7
#define __AC3_x                                                    0x561650
#define __AC4_x                                                    0x573801
#define __AC5_x                                                    0x58755B
#define __AC6_x                                                    0x58B11E
#define __AC7_x                                                    0x581B5C
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
#define __do_loot_x                                                0x5323B0
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
#define __CastRay_x                                                0x549D40
#define __CastRay2_x                                               0x549670
#define __HeadingDiff_x                                            0x932670
#define __FixHeading_x                                             0x932600
#define __get_bearing_x                                            0x539500
#define __ConvertItemTags_x                                        0x536FD0
#define __ExecuteCmd_x                                             0x521910
#define __EQGetTime_x                                              0x8A2210
#define __get_melee_range_x                                        0x5285B0
#define __GetGaugeValueFromEQ_x                                    0x7B2460
#define __GetLabelFromEQ_x                                         0x7B3830
#define __ToggleKeyRingItem_x                                      0x490110
#define __GetXTargetType_x                                         0x934270
#define __LoadFrontEnd_x                                           0x63F240
#define __NewUIINI_x                                               0x7B1E30
#define __ProcessGameEvents_x                                      0x5838F0
#define __ProcessMouseEvent_x                                      0x583090
#define CrashDetected_x                                            0x640C00
#define wwsCrashReportCheckForUploader_x                           0x800210
#define __AppCrashWrapper_x                                        0xC66AC4
#define __pCrashHandler_x                                          0x10D69E0
#define __CrashHandler_x                                           0x7FFCA0
#define wwsCrashReportPlatformLaunchUploader_x                     0x802440
#define DrawNetStatus_x                                            0x5B9C50
#define Util__FastTime_x                                           0x8A1EB0
#define Expansion_HoT_x                                            0xF307B0
#define __HelpPath_x                                               0xFB3F60
#define __STMLToText_x                                             0x8E85E0
#define __GetAnimationCache_x                                      0x6AEA40

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423430
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E090
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DE60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D83B0
#define AltAdvManager__IsAbilityReady_x                            0x4D8420
#define AltAdvManager__GetAAById_x                                 0x4D8910
#define AltAdvManager__CanTrainAbility_x                           0x4D9540
#define AltAdvManager__CanSeeAbility_x                             0x4D9100

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46B110
#define CharacterZoneClient__HasSkill_x                            0x466FF0
#define CharacterZoneClient__MakeMeVisible_x                       0x46CC80
#define CharacterZoneClient__IsStackBlocked_x                      0x44C0D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B5F0
#define CharacterZoneClient__GetItemCountWorn_x                    0x465550
#define CharacterZoneClient__GetItemCountInInventory_x             0x465630
#define CharacterZoneClient__GetCursorItemCount_x                  0x465710
#define CharacterZoneClient__FindAffectSlot_x                      0x451760
#define CharacterZoneClient__BardCastBard_x                        0x44AD60
#define CharacterZoneClient__GetMaxEffects_x                       0x4498F0
#define CharacterZoneClient__GetEffect_x                           0x44B820
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4515C0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449C40
#define CharacterZoneClient__GetLastEffectSlot_x                   0x450110

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66EBD0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67CA00

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x598980
#define CButtonWnd__CButtonWnd_x                                   0x8DC890

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x697BD0
#define CChatManager__InitContextMenu_x                            0x698D20
#define CChatManager__FreeChatWindow_x                             0x697680
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A0EC0
#define CChatManager__SetLockedActiveChatWindow_x                  0x697BA0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E6940
#define CContextMenu__dCContextMenu_x                              0x8E6B50
#define CContextMenu__AddMenuItem_x                                0x8E7060
#define CContextMenu__RemoveMenuItem_x                             0x8E6CC0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E6CE0
#define CContextMenu__CheckMenuItem_x                              0x8E6D60

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D2E90
#define CContextMenuManager__RemoveMenu_x                          0x8D3220
#define CContextMenuManager__PopupMenu_x                           0x8D3670
#define CContextMenuManager__Flush_x                               0x8D2F00
#define CContextMenuManager__GetMenu_x                             0x4195B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8862B0
#define CChatService__GetFriendName_x                              0x8862C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69E990
#define CChatWindow__Clear_x                                       0x69E270
#define CChatWindow__WndNotification_x                             0x69F2A0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D6CF0
#define CComboWnd__Draw_x                                          0x8D6F00
#define CComboWnd__GetCurChoice_x                                  0x8D6AA0
#define CComboWnd__GetListRect_x                                   0x8D71A0
#define CComboWnd__GetTextRect_x                                   0x8D6D60
#define CComboWnd__InsertChoice_x                                  0x8D7300
#define CComboWnd__SetColors_x                                     0x8D6A30
#define CComboWnd__SetChoice_x                                     0x8D6A60
#define CComboWnd__GetItemCount_x                                  0x8D6A90
#define CComboWnd__GetCurChoiceText_x                              0x8D6AE0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A8BD0
#define CContainerWnd__vftable_x                                   0xAEC9A8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C61B0
#define CDisplay__GetClickedActor_x                                0x4BEA70
#define CDisplay__GetUserDefinedColor_x                            0x4BD650
#define CDisplay__GetWorldFilePath_x                               0x4BCAA0
#define CDisplay__is3dON_x                                         0x4BBF30
#define CDisplay__ReloadUI_x                                       0x4CFF70
#define CDisplay__WriteTextHD2_x                                   0x4C2540
#define CDisplay__TrueDistance_x                                   0x4BF6A0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FD930

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EAE90
#define CEditWnd__GetCharIndexPt_x                                 0x8EBFD0
#define CEditWnd__GetDisplayString_x                               0x8EB040
#define CEditWnd__GetHorzOffset_x                                  0x8EB380
#define CEditWnd__GetLineForPrintableChar_x                        0x8EBAA0
#define CEditWnd__GetSelStartPt_x                                  0x8EC280
#define CEditWnd__GetSTMLSafeText_x                                0x8EB510
#define CEditWnd__PointFromPrintableChar_x                         0x8EBB90
#define CEditWnd__SelectableCharFromPoint_x                        0x8EBD10
#define CEditWnd__SetEditable_x                                    0x8EB4E0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56A030
#define CEverQuest__ClickedPlayer_x                                0x563C20
#define CEverQuest__CreateTargetIndicator_x                        0x564B20
#define CEverQuest__DeleteTargetIndicator_x                        0x564BA0
#define CEverQuest__DoTellWindow_x                                 0x476350
#define CEverQuest__OutputTextToLog_x                              0x475FB0
#define CEverQuest__DropHeldItemOnGround_x                         0x57A5A0
#define CEverQuest__dsp_chat_x                                     0x476690
#define CEverQuest__trimName_x                                     0x560530
#define CEverQuest__Emote_x                                        0x5788B0
#define CEverQuest__EnterZone_x                                    0x573990
#define CEverQuest__GetBodyTypeDesc_x                              0x55DF70
#define CEverQuest__GetClassDesc_x                                 0x567460
#define CEverQuest__GetClassThreeLetterCode_x                      0x567A60
#define CEverQuest__GetDeityDesc_x                                 0x55E850
#define CEverQuest__GetLangDesc_x                                  0x55E300
#define CEverQuest__GetRaceDesc_x                                  0x567C20
#define CEverQuest__InterpretCmd_x                                 0x56B7B0
#define CEverQuest__LeftClickedOnPlayer_x                          0x580100
#define CEverQuest__LMouseUp_x                                     0x5820B0
#define CEverQuest__RightClickedOnPlayer_x                         0x580C10
#define CEverQuest__RMouseUp_x                                     0x581B10
#define CEverQuest__SetGameState_x                                 0x5644F0
#define CEverQuest__UPCNotificationFlush_x                         0x55C900
#define CEverQuest__IssuePetCommand_x                              0x56C190

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B97A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B9800
#define CGaugeWnd__Draw_x                                          0x6B9C30

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B350
#define CGuild__GetGuildName_x                                     0x43B820
#define CGuild__GetGuildIndex_x                                    0x43CA30

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D5D40

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E30E0
#define CInvSlotMgr__MoveItem_x                                    0x6E38A0
#define CInvSlotMgr__SelectSlot_x                                  0x6E29D0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E1E30
#define CInvSlot__SliderComplete_x                                 0x6DF660
#define CInvSlot__GetItemBase_x                                    0x6DEAF0
#define CInvSlot__UpdateItem_x                                     0x6DF070

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E4D00
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E5E40

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AE360
#define CItemDisplayWnd__UpdateStrings_x                           0x6E6F40
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F37C0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F3CF0
#define CItemDisplayWnd__SetItem_x                                 0x6F9690

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E5390

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6ED4C0

// CLabel 
#define CLabel__Draw_x                                             0x700450

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C2950
#define CListWnd__dCListWnd_x                                      0x8C3BF0
#define CListWnd__AddColumn_x                                      0x8C3B90
#define CListWnd__AddColumn1_x                                     0x8C3230
#define CListWnd__AddLine_x                                        0x8C2C10
#define CListWnd__AddString_x                                      0x8C2E30
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BFAB0
#define CListWnd__CalculateVSBRange_x                              0x8C1E20
#define CListWnd__ClearSel_x                                       0x8BEDF0
#define CListWnd__ClearAllSel_x                                    0x8BEDA0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C27E0
#define CListWnd__Compare_x                                        0x8C0770
#define CListWnd__Draw_x                                           0x8C1A30
#define CListWnd__DrawColumnSeparators_x                           0x8C18C0
#define CListWnd__DrawHeader_x                                     0x8BF0B0
#define CListWnd__DrawItem_x                                       0x8C0E00
#define CListWnd__DrawLine_x                                       0x8C1560
#define CListWnd__DrawSeparator_x                                  0x8C1960
#define CListWnd__EnableLine_x                                     0x8BEFD0
#define CListWnd__EnsureVisible_x                                  0x8BFC10
#define CListWnd__ExtendSel_x                                      0x8C0D10
#define CListWnd__GetColumnMinWidth_x                              0x8BE6E0
#define CListWnd__GetColumnWidth_x                                 0x8BE610
#define CListWnd__GetCurSel_x                                      0x8BDDE0
#define CListWnd__GetItemAtPoint_x                                 0x8BFE80
#define CListWnd__GetItemAtPoint1_x                                0x8BFEF0
#define CListWnd__GetItemData_x                                    0x8BE120
#define CListWnd__GetItemHeight_x                                  0x8BF720
#define CListWnd__GetItemIcon_x                                    0x8BE310
#define CListWnd__GetItemRect_x                                    0x8BFCD0
#define CListWnd__GetItemText_x                                    0x8BE1C0
#define CListWnd__GetSelList_x                                     0x8C3120
#define CListWnd__GetSeparatorRect_x                               0x8C06A0
#define CListWnd__InsertLine_x                                     0x8C3010
#define CListWnd__RemoveLine_x                                     0x8C3020
#define CListWnd__SetColors_x                                      0x8BDF30
#define CListWnd__SetColumnJustification_x                         0x8BE970
#define CListWnd__SetColumnWidth_x                                 0x8BE690
#define CListWnd__SetCurSel_x                                      0x8BDE20
#define CListWnd__SetItemColor_x                                   0x8C24D0
#define CListWnd__SetItemData_x                                    0x8BEE50
#define CListWnd__SetItemText_x                                    0x8C2310
#define CListWnd__ShiftColumnSeparator_x                           0x8C21A0
#define CListWnd__Sort_x                                           0x8C3CF0
#define CListWnd__ToggleSel_x                                      0x8BED20

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x719450

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73EA50
#define CMerchantWnd__RequestBuyItem_x                             0x7468A0
#define CMerchantWnd__RequestSellItem_x                            0x748F90
#define CMerchantWnd__SelectRecoverySlot_x                         0x73BD70
#define CMerchantWnd__SelectBuySellSlot_x                          0x739CD0
#define CMerchantWnd__ActualSelect_x                               0x7407D0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8546B0
#define CPacketScrambler__hton_x                                   0x8546C0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E1850
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1930
#define CSidlManager__CreateLabel_x                                0x7A30F0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8DFDF0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E1C10

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D8D30
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D8C30
#define CSidlScreenWnd__ConvertToRes_x                             0x8FD810
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9630
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DA7E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DA890
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D9D60
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D8FE0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8760
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D91D0
#define CSidlScreenWnd__Init1_x                                    0x8DA4B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D96F0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8920
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D9FA0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D83D0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8710
#define CSidlScreenWnd__WndNotification_x                          0x8DA230
#define CSidlScreenWnd__GetChildItem_x                             0x8D8830
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CC100
#define CSidlScreenWnd__m_layoutCopy_x                             0x172FE20

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x604C80
#define CSkillMgr__GetSkillCap_x                                   0x604E60
#define CSkillMgr__GetNameToken_x                                  0x604830

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FCAC0
#define CSliderWnd__SetValue_x                                     0x8FCC90
#define CSliderWnd__SetNumTicks_x                                  0x8FD410

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A95A0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F68A0
#define CStmlWnd__CalculateHSBRange_x                              0x8EEE40
#define CStmlWnd__CalculateVSBRange_x                              0x8EEDB0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EEFB0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EF7B0
#define CStmlWnd__ForceParseNow_x                                  0x8F7260
#define CStmlWnd__GetNextTagPiece_x                                0x8EF6B0
#define CStmlWnd__GetSTMLText_x                                    0x484630
#define CStmlWnd__GetVisibleText_x                                 0x8F0200
#define CStmlWnd__InitializeWindowVariables_x                      0x8F27B0
#define CStmlWnd__MakeStmlColorTag_x                               0x8EE090
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EE0F0
#define CStmlWnd__SetSTMLText_x                                    0x8F4000
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6540
#define CStmlWnd__UpdateHistoryString_x                            0x8F1130

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FA770
#define CTabWnd__DrawCurrentPage_x                                 0x8FA000
#define CTabWnd__DrawTab_x                                         0x8F9DD0
#define CTabWnd__GetCurrentPage_x                                  0x8FA3B0
#define CTabWnd__GetPageInnerRect_x                                0x8F9AC0
#define CTabWnd__GetTabInnerRect_x                                 0x8F9CC0
#define CTabWnd__GetTabRect_x                                      0x8F9B90
#define CTabWnd__InsertPage_x                                      0x8FAA60
#define CTabWnd__SetPage_x                                         0x8FA3E0
#define CTabWnd__SetPageRect_x                                     0x8FA6B0
#define CTabWnd__UpdatePage_x                                      0x8FAA00
#define CTabWnd__GetPageFromTabIndex_x                             0x8F9D20
#define CTabWnd__GetCurrentTabIndex_x                              0x8F9A50

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E5FF0
#define CPageWnd__SetTabText_x                                     0x906B50

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436E90

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D66A0
#define CTextureFont__GetTextExtent_x                              0x8D6400

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63D4E0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x902F90

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BBE80

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029D0
#define CXStr__CXStr1_x                                            0x403740
#define CXStr__CXStr3_x                                            0x89F100
#define CXStr__dCXStr_x                                            0x7507C0
#define CXStr__operator_equal_x                                    0x89F270
#define CXStr__operator_equal1_x                                   0x89F2C0
#define CXStr__operator_plus_equal1_x                              0x8A03C0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D4190
#define CXWnd__BringToTop_x                                        0x8CB310
#define CXWnd__Center_x                                            0x8D1460
#define CXWnd__ClrFocus_x                                          0x8CAEF0
#define CXWnd__Destroy_x                                           0x8D1F50
#define CXWnd__DoAllDrawing_x                                      0x8D10B0
#define CXWnd__DrawChildren_x                                      0x8D1250
#define CXWnd__DrawColoredRect_x                                   0x8CB700
#define CXWnd__DrawTooltip_x                                       0x8CB990
#define CXWnd__DrawTooltipAtPoint_x                                0x8D0020
#define CXWnd__GetBorderFrame_x                                    0x8CBDF0
#define CXWnd__GetChildWndAt_x                                     0x8D1E30
#define CXWnd__GetClientClipRect_x                                 0x8CBBA0
#define CXWnd__GetScreenClipRect_x                                 0x8D0710
#define CXWnd__GetScreenRect_x                                     0x8CBFC0
#define CXWnd__GetTooltipRect_x                                    0x8CB820
#define CXWnd__GetWindowTextA_x                                    0x426FC0
#define CXWnd__IsActive_x                                          0x8C69E0
#define CXWnd__IsDescendantOf_x                                    0x8CBD30
#define CXWnd__IsReallyVisible_x                                   0x8CF080
#define CXWnd__IsType_x                                            0x8D14D0
#define CScreenPieceTemplate__IsType_x                             0x8FF6C0
#define CXWnd__Move_x                                              0x8CE810
#define CXWnd__Move1_x                                             0x8D0D70
#define CXWnd__ProcessTransition_x                                 0x8CB2B0
#define CXWnd__Refade_x                                            0x8CB080
#define CXWnd__Resize_x                                            0x8CC070
#define CXWnd__Right_x                                             0x8D0510
#define CXWnd__SetFocus_x                                          0x8CD960
#define CXWnd__SetFont_x                                           0x8CAF40
#define CXWnd__SetKeyTooltip_x                                     0x8CC2D0
#define CXWnd__SetMouseOver_x                                      0x8D0A60
#define CXWnd__StartFade_x                                         0x8CB360
#define CXWnd__GetChildItem_x                                      0x8D09A0
#define CXWnd__SetParent_x                                         0x8D1DE0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C82A0
#define CXWndManager__DrawWindows_x                                0x8C7EE0
#define CXWndManager__GetKeyboardFlags_x                           0x8C6510
#define CXWndManager__HandleKeyboardMsg_x                          0x8C6E80
#define CXWndManager__RemoveWnd_x                                  0x8C6B70

// CDBStr
#define CDBStr__GetString_x                                        0x4BA780

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452820
#define EQ_Character__Cur_HP_x                                     0x466BD0
#define EQ_Character__Cur_Mana_x                                   0x45BBB0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B900
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4438A0
#define EQ_Character__GetFocusRangeModifier_x                      0x4439F0
#define EQ_Character__GetHPRegen_x                                 0x46A7A0
#define EQ_Character__GetEnduranceRegen_x                          0x4661E0
#define EQ_Character__GetManaRegen_x                               0x46AD40
#define EQ_Character__Max_Endurance_x                              0x5CBAE0
#define EQ_Character__Max_HP_x                                     0x45E730
#define EQ_Character__Max_Mana_x                                   0x5CB910
#define EQ_Character__doCombatAbility_x                            0x5C8FE0
#define EQ_Character__UseSkill_x                                   0x472B30
#define EQ_Character__GetConLevel_x                                0x5BE210
#define EQ_Character__IsExpansionFlag_x                            0x4B6B10
#define EQ_Character__TotalEffect_x                                0x44FA50
#define EQ_Character__GetPCSpellAffect_x                           0x44BC90
#define EQ_Character__SpellDuration_x                              0x449C90
#define EQ_Character__FindItemByRecord_x                           0x464220
#define EQ_Character__GetAdjustedSkill_x                           0x466DA0
#define EQ_Character__GetBaseSkill_x                               0x45E610

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x872480

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D41E0

//PcClient
#define PcClient__PcClient_x                                       0x5C0050

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446D90
#define CCharacterSelect__EnterWorld_x                             0x446560
#define CCharacterSelect__Quit_x                                   0x445120

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59E2D0
#define EQ_Item__CreateItemTagString_x                             0x852870
#define EQ_Item__IsStackable_x                                     0x847DF0
#define EQ_Item__GetImageNum_x                                     0x84A990
#define EQ_Item__CreateItemClient_x                                0x59F410
#define EQ_Item__GetItemValue_x                                    0x851310
#define EQ_Item__ValueSellMerchant_x                               0x854310
#define EQ_Item__IsKeyRingItem_x                                   0x848970
#define EQ_Item__CanGoInBag_x                                      0x59E460
#define EQ_Item__GetMaxItemCount_x                                 0x847CE0
#define EQ_Item__GetHeldItem_x                                     0x8497A0
#define EQ_Item__GetAugmentFitBySlot_x                             0x854130

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA950
#define EQ_LoadingS__Array_x                                       0xC0AC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CE000
#define EQ_PC__GetAlternateAbilityId_x                             0x85C700
#define EQ_PC__GetCombatAbility_x                                  0x85C790
#define EQ_PC__GetCombatAbilityTimer_x                             0x857360
#define EQ_PC__GetItemRecastTimer_x                                0x5C77D0
#define EQ_PC__HasLoreItem_x                                       0x5C1810
#define EQ_PC__AlertInventoryChanged_x                             0x5BE1C0
#define EQ_PC__GetPcZoneClient_x                                   0x5E8720
#define EQ_PC__RemoveMyAffect_x                                    0x5C6C30
#define EQ_PC__GetKeyRingItems_x                                   0x857780
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86A410
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85E680

// EQItemList 
#define EQItemList__EQItemList_x                                   0x526660
#define EQItemList__add_object_x                                   0x553890
#define EQItemList__add_item_x                                     0x5265A0
#define EQItemList__delete_item_x                                  0x526A50
#define EQItemList__FreeItemList_x                                 0x526950

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9A70

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D3EA0
#define EQPlayer__dEQPlayer_x                                      0x5DC650
#define EQPlayer__DoAttack_x                                       0x5EDEB0
#define EQPlayer__EQPlayer_x                                       0x5DED70
#define EQPlayer__SetNameSpriteState_x                             0x5D9480
#define EQPlayer__SetNameSpriteTint_x                              0x5D53A0
#define PlayerBase__HasProperty_j_x                                0x930A80
#define EQPlayer__IsTargetable_x                                   0x930D20
#define EQPlayer__CanSee_x                                         0x931280
#define PlayerZoneClient__ChangeHeight_x                           0x5EDD70
#define EQPlayer__CanSee1_x                                        0x931370
#define PlayerBase__GetVisibilityLineSegment_x                     0x931010

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E88D0
#define PlayerZoneClient__IsValidTeleport_x                        0x554130
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2B60


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E2D50
#define EQPlayerManager__GetSpawnByName_x                          0x5E31B0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E2D80

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A4920
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A4960
#define KeypressHandler__ClearCommandStateArray_x                  0x5A4510
#define KeypressHandler__HandleKeyDown_x                           0x5A2E30
#define KeypressHandler__HandleKeyUp_x                             0x5A3150
#define KeypressHandler__SaveKeymapping_x                          0x5A45E0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x711DE0
#define MapViewMap__SaveEx_x                                       0x715110
#define MapViewMap__SetZoom_x                                      0x711A50

#define PlayerPointManager__GetAltCurrency_x                       0x870510

// StringTable 
#define StringTable__getString_x                                   0x86A740

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CB570
#define PcZoneClient__RemovePetEffect_x                            0x5C7CA0
#define PcZoneClient__HasAlternateAbility_x                        0x5C8640
#define PcZoneClient__GetCurrentMod_x                              0x45DBE0
#define PcZoneClient__GetModCap_x                                  0x45B310
#define PcZoneClient__CanEquipItem_x                               0x5C8B20
#define PcZoneClient__GetItemByID_x                                0x5CD380
#define PcZoneClient__GetItemByItemClass_x                         0x5CDF20
#define PcZoneClient__RemoveBuffEffect_x                           0x5C6EE0

//Doors
#define EQSwitch__UseSwitch_x                                      0x55B250

//IconCache
#define IconCache__GetIcon_x                                       0x6AF070

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A5F50
#define CContainerMgr__CloseContainer_x                            0x6A6770

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x772E90

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5973A0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4F30
#define EQ_Spell__SpellAffects_x                                   0x4F2110
#define EQ_Spell__SpellAffectBase_x                                0x4F2180
#define CharacterZoneClient__CalcAffectChange_x                    0x44BB20
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44ADC0
#define CLootWnd__LootAll_x                                        0x7076C0
#define CLootWnd__RequestLootSlot_x                                0x707ED0
#define EQ_Spell__IsStackable_x                                    0x459330
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449740
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EDF0
#define EQ_Spell__IsSPAStacking_x                                  0x4F1C80
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2D20
#define EQ_Spell__IsNoRemove_x                                     0x434EA0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1CA0

#define __IsResEffectSpell_x                                       0x4497E0

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87C120

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BAF30
#define CTargetWnd__WndNotification_x                              0x7BAA20
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BB110

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C0060

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED7E0
#define EqSoundManager__PlayScriptMp3_x                            0x4EF280

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8BD0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EA4C0
#define CSidlManager__FindAnimation1_x                             0x8DF820

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E2220
#define CAltAbilityData__GetMercMaxRank_x                          0x4E21D0
#define CAltAbilityData__GetMaxRank_x                              0x4D6A60

//CTargetRing
#define CTargetRing__Cast_x                                        0x594FE0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459610
#define CharacterBase__CreateItemGlobalIndex_x                     0x475560
#define CharacterBase__CreateItemIndex_x                           0x51FC40
#define CharacterBase__GetItemPossession_x                         0x4445F0
#define CharacterBase__GetItemByGlobalIndex_x                      0x87FF60
#define CharacterBase__GetEffectId_x                               0x4595D0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68ED40
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68E4A0

//messages
#define msg_spell_worn_off_x                                       0x4FCA00
#define msg_new_text_x                                             0x506180
#define msgTokenTextParam_x                                        0x502980

//SpellManager
#define SpellManager__vftable_x                                    0xAC8268
#define SpellManager__SpellManager_x                               0x47E1E0
#define Spellmanager__LoadTextSpells_x                             0x60BB90

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x934D90

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x488120
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43ED00
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449480
#define ItemGlobalIndex__IsValidIndex_x                            0x458E30

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87DDE0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87CD20

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x7006A0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AACA0
#define CCursorAttachment__Deactivate_x                            0x6AA1E0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FBFC0
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FC140

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x603850

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C990

//IString
#define IString__Append_x                                          0x47EE60

//Camera
#define CDisplay__cameraType_x                                     0xE6E7C8
#define EverQuest__Cameras_x                                       0xF30AC8
