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
#define __ExpectedVersionDate                                     "Nov 26 2017"
#define __ExpectedVersionTime                                     "04:16:29"
#define __ActualVersionDate_x                                      0xAE3088
#define __ActualVersionTime_x                                      0xAE3094

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5AAB30
#define __MemChecker1_x                                            0x8A3160
#define __MemChecker2_x                                            0x640940
#define __MemChecker3_x                                            0x640890
#define __MemChecker4_x                                            0x7F4F80
#define __EncryptPad0_x                                            0xC3DFE8
#define __EncryptPad1_x                                            0xD17BA0
#define __EncryptPad2_x                                            0xC66ED0
#define __EncryptPad3_x                                            0xC66AD0
#define __EncryptPad4_x                                            0xD061A0
#define __EncryptPad5_x                                            0x10C12C0
#define __AC1_x                                                    0x7B3D05
#define __AC2_x                                                    0x563E97
#define __AC3_x                                                    0x562010
#define __AC4_x                                                    0x5741E1
#define __AC5_x                                                    0x587F3B
#define __AC6_x                                                    0x58BAEE
#define __AC7_x                                                    0x58253C
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
#define __do_loot_x                                                0x532E30
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
#define __CastRay_x                                                0x54A7B0
#define __CastRay2_x                                               0x54A0E0
#define __HeadingDiff_x                                            0x933110
#define __FixHeading_x                                             0x9330A0
#define __get_bearing_x                                            0x539F70
#define __ConvertItemTags_x                                        0x537A50
#define __ExecuteCmd_x                                             0x522380
#define __EQGetTime_x                                              0x8A2B00
#define __get_melee_range_x                                        0x529030
#define __GetGaugeValueFromEQ_x                                    0x7B28C0
#define __GetLabelFromEQ_x                                         0x7B3C90
#define __ToggleKeyRingItem_x                                      0x48FC00
#define __GetXTargetType_x                                         0x934D80
#define __LoadFrontEnd_x                                           0x640010
#define __NewUIINI_x                                               0x7B2290
#define __ProcessGameEvents_x                                      0x5842D0
#define __ProcessMouseEvent_x                                      0x583A70
#define CrashDetected_x                                            0x6419D0
#define wwsCrashReportCheckForUploader_x                           0x800C60
#define __AppCrashWrapper_x                                        0xC66AC4
#define __pCrashHandler_x                                          0x10D69E0
#define __CrashHandler_x                                           0x8006F0
#define wwsCrashReportPlatformLaunchUploader_x                     0x802EA0
#define DrawNetStatus_x                                            0x5BA690
#define Util__FastTime_x                                           0x8A27A0
#define Expansion_HoT_x                                            0xF307B0
#define __HelpPath_x                                               0xFB3F60
#define __STMLToText_x                                             0x8E9080
#define __GetAnimationCache_x                                      0x6AF5F0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423390
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DFF0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DDC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D7FD0
#define AltAdvManager__IsAbilityReady_x                            0x4D8040
#define AltAdvManager__GetAAById_x                                 0x4D8530
#define AltAdvManager__CanTrainAbility_x                           0x4D9160
#define AltAdvManager__CanSeeAbility_x                             0x4D8D20

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AFC0
#define CharacterZoneClient__HasSkill_x                            0x466ED0
#define CharacterZoneClient__MakeMeVisible_x                       0x46CB30
#define CharacterZoneClient__IsStackBlocked_x                      0x44BF50
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B470
#define CharacterZoneClient__GetItemCountWorn_x                    0x465430
#define CharacterZoneClient__GetItemCountInInventory_x             0x465510
#define CharacterZoneClient__GetCursorItemCount_x                  0x4655F0
#define CharacterZoneClient__FindAffectSlot_x                      0x4515E0
#define CharacterZoneClient__BardCastBard_x                        0x44ABE0
#define CharacterZoneClient__GetMaxEffects_x                       0x449770
#define CharacterZoneClient__GetEffect_x                           0x44B6A0
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451440
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449AC0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FF90

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66F8A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67D6E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x599400
#define CButtonWnd__CButtonWnd_x                                   0x8DD290

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x698840
#define CChatManager__InitContextMenu_x                            0x699990
#define CChatManager__FreeChatWindow_x                             0x6982F0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A1AD0
#define CChatManager__SetLockedActiveChatWindow_x                  0x698810

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E73F0
#define CContextMenu__dCContextMenu_x                              0x8E75F0
#define CContextMenu__AddMenuItem_x                                0x8E7B00
#define CContextMenu__RemoveMenuItem_x                             0x8E7760
#define CContextMenu__RemoveAllMenuItems_x                         0x8E7780
#define CContextMenu__CheckMenuItem_x                              0x8E7800
#define CContextMenu__SetMenuItem_x                                0x8E7690

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D3870
#define CContextMenuManager__RemoveMenu_x                          0x8D3C10
#define CContextMenuManager__PopupMenu_x                           0x8D4060
#define CContextMenuManager__Flush_x                               0x8D38E0
#define CContextMenuManager__GetMenu_x                             0x4194C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x886CA0
#define CChatService__GetFriendName_x                              0x886CB0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69F5C0
#define CChatWindow__Clear_x                                       0x69EEA0
#define CChatWindow__WndNotification_x                             0x69FEC0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D76D0
#define CComboWnd__Draw_x                                          0x8D78E0
#define CComboWnd__GetCurChoice_x                                  0x8D7480
#define CComboWnd__GetListRect_x                                   0x8D7B80
#define CComboWnd__GetTextRect_x                                   0x8D7740
#define CComboWnd__InsertChoice_x                                  0x8D7CE0
#define CComboWnd__SetColors_x                                     0x8D7410
#define CComboWnd__SetChoice_x                                     0x8D7440
#define CComboWnd__GetItemCount_x                                  0x8D7470
#define CComboWnd__GetCurChoiceText_x                              0x8D74C0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A97B0
#define CContainerWnd__vftable_x                                   0xAEC9A0

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
#define CEditBaseWnd__SetSel_x                                     0x8FE4C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EB930
#define CEditWnd__GetCharIndexPt_x                                 0x8ECA70
#define CEditWnd__GetDisplayString_x                               0x8EBAE0
#define CEditWnd__GetHorzOffset_x                                  0x8EBE20
#define CEditWnd__GetLineForPrintableChar_x                        0x8EC540
#define CEditWnd__GetSelStartPt_x                                  0x8ECD20
#define CEditWnd__GetSTMLSafeText_x                                0x8EBFB0
#define CEditWnd__PointFromPrintableChar_x                         0x8EC630
#define CEditWnd__SelectableCharFromPoint_x                        0x8EC7B0
#define CEditWnd__SetEditable_x                                    0x8EBF80

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56AA10
#define CEverQuest__ClickedPlayer_x                                0x5645E0
#define CEverQuest__CreateTargetIndicator_x                        0x5654E0
#define CEverQuest__DeleteTargetIndicator_x                        0x565560
#define CEverQuest__DoTellWindow_x                                 0x476210
#define CEverQuest__OutputTextToLog_x                              0x475E70
#define CEverQuest__DropHeldItemOnGround_x                         0x57AF80
#define CEverQuest__dsp_chat_x                                     0x476550
#define CEverQuest__trimName_x                                     0x560EF0
#define CEverQuest__Emote_x                                        0x579290
#define CEverQuest__EnterZone_x                                    0x574370
#define CEverQuest__GetBodyTypeDesc_x                              0x55E930
#define CEverQuest__GetClassDesc_x                                 0x567E20
#define CEverQuest__GetClassThreeLetterCode_x                      0x568420
#define CEverQuest__GetDeityDesc_x                                 0x55F210
#define CEverQuest__GetLangDesc_x                                  0x55ECC0
#define CEverQuest__GetRaceDesc_x                                  0x5685E0
#define CEverQuest__InterpretCmd_x                                 0x56C190
#define CEverQuest__LeftClickedOnPlayer_x                          0x580AE0
#define CEverQuest__LMouseUp_x                                     0x582A90
#define CEverQuest__RightClickedOnPlayer_x                         0x5815F0
#define CEverQuest__RMouseUp_x                                     0x5824F0
#define CEverQuest__SetGameState_x                                 0x564EB0
#define CEverQuest__UPCNotificationFlush_x                         0x55D2C0
#define CEverQuest__IssuePetCommand_x                              0x56CB70

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BA460
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BA4C0
#define CGaugeWnd__Draw_x                                          0x6BA8F0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B160
#define CGuild__GetGuildName_x                                     0x43B630
#define CGuild__GetGuildIndex_x                                    0x43C840

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D6960

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E3D00
#define CInvSlotMgr__MoveItem_x                                    0x6E44C0
#define CInvSlotMgr__SelectSlot_x                                  0x6E35F0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E2A50
#define CInvSlot__SliderComplete_x                                 0x6E0280
#define CInvSlot__GetItemBase_x                                    0x6DF710
#define CInvSlot__UpdateItem_x                                     0x6DFC90

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E5920
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E6A50

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AE710
#define CItemDisplayWnd__UpdateStrings_x                           0x6E7B70
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F43E0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F4910
#define CItemDisplayWnd__SetItem_x                                 0x6FA2A0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E57E0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EE0E0

// CLabel 
#define CLabel__Draw_x                                             0x7010D0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C3260
#define CListWnd__dCListWnd_x                                      0x8C4500
#define CListWnd__AddColumn_x                                      0x8C44A0
#define CListWnd__AddColumn1_x                                     0x8C3B40
#define CListWnd__AddLine_x                                        0x8C3520
#define CListWnd__AddString_x                                      0x8C3740
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C0390
#define CListWnd__CalculateVSBRange_x                              0x8C2720
#define CListWnd__ClearSel_x                                       0x8BF6D0
#define CListWnd__ClearAllSel_x                                    0x8BF680
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C30F0
#define CListWnd__Compare_x                                        0x8C1070
#define CListWnd__Draw_x                                           0x8C2330
#define CListWnd__DrawColumnSeparators_x                           0x8C21C0
#define CListWnd__DrawHeader_x                                     0x8BF990
#define CListWnd__DrawItem_x                                       0x8C1700
#define CListWnd__DrawLine_x                                       0x8C1E60
#define CListWnd__DrawSeparator_x                                  0x8C2260
#define CListWnd__EnableLine_x                                     0x8BF8B0
#define CListWnd__EnsureVisible_x                                  0x8C04F0
#define CListWnd__ExtendSel_x                                      0x8C1610
#define CListWnd__GetColumnMinWidth_x                              0x8BEFC0
#define CListWnd__GetColumnWidth_x                                 0x8BEEF0
#define CListWnd__GetCurSel_x                                      0x8BE6D0
#define CListWnd__GetItemAtPoint_x                                 0x8C0780
#define CListWnd__GetItemAtPoint1_x                                0x8C07F0
#define CListWnd__GetItemData_x                                    0x8BEA10
#define CListWnd__GetItemHeight_x                                  0x8C0000
#define CListWnd__GetItemIcon_x                                    0x8BEC00
#define CListWnd__GetItemRect_x                                    0x8C05C0
#define CListWnd__GetItemText_x                                    0x8BEAB0
#define CListWnd__GetSelList_x                                     0x8C3A30
#define CListWnd__GetSeparatorRect_x                               0x8C0FA0
#define CListWnd__InsertLine_x                                     0x8C3920
#define CListWnd__RemoveLine_x                                     0x8C3930
#define CListWnd__SetColors_x                                      0x8BE820
#define CListWnd__SetColumnJustification_x                         0x8BF250
#define CListWnd__SetColumnWidth_x                                 0x8BEF70
#define CListWnd__SetCurSel_x                                      0x8BE710
#define CListWnd__SetItemColor_x                                   0x8C2DE0
#define CListWnd__SetItemData_x                                    0x8BF730
#define CListWnd__SetItemText_x                                    0x8C2C20
#define CListWnd__ShiftColumnSeparator_x                           0x8C2AB0
#define CListWnd__Sort_x                                           0x8C4600
#define CListWnd__ToggleSel_x                                      0x8BF600

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71A0A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73F610
#define CMerchantWnd__RequestBuyItem_x                             0x7470E0
#define CMerchantWnd__RequestSellItem_x                            0x7496E0
#define CMerchantWnd__SelectRecoverySlot_x                         0x73C8D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x73A870
#define CMerchantWnd__ActualSelect_x                               0x7413B0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x854EB0
#define CPacketScrambler__hton_x                                   0x854EC0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E2260
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E2340
#define CSidlManager__CreateLabel_x                                0x7A36B0
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E0800
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E2620

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D9720
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D9610
#define CSidlScreenWnd__ConvertToRes_x                             0x8FE3A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8DA020
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DB1E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DB290
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DA760
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D99D0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D9140
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D9BC0
#define CSidlScreenWnd__Init1_x                                    0x8DAEB0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8DA0D0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D9300
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DA9A0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D8DA0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D90F0
#define CSidlScreenWnd__WndNotification_x                          0x8DAC30
#define CSidlScreenWnd__GetChildItem_x                             0x8D9210
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CCAC0
#define CSidlScreenWnd__m_layoutCopy_x                             0x172FE20

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x605970
#define CSkillMgr__GetSkillCap_x                                   0x605B50
#define CSkillMgr__GetNameToken_x                                  0x605520

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FD660
#define CSliderWnd__SetValue_x                                     0x8FD830
#define CSliderWnd__SetNumTicks_x                                  0x8FDFB0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A9A00

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F7350
#define CStmlWnd__CalculateHSBRange_x                              0x8EF8E0
#define CStmlWnd__CalculateVSBRange_x                              0x8EF850
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EFA60
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F0260
#define CStmlWnd__ForceParseNow_x                                  0x8F7CD0
#define CStmlWnd__GetNextTagPiece_x                                0x8F0160
#define CStmlWnd__GetSTMLText_x                                    0x4843F0
#define CStmlWnd__GetVisibleText_x                                 0x8F0CB0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F3260
#define CStmlWnd__MakeStmlColorTag_x                               0x8EEB30
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EEB90
#define CStmlWnd__SetSTMLText_x                                    0x8F4AB0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6FF0
#define CStmlWnd__UpdateHistoryString_x                            0x8F1BE0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FB1D0
#define CTabWnd__DrawCurrentPage_x                                 0x8FAA60
#define CTabWnd__DrawTab_x                                         0x8FA830
#define CTabWnd__GetCurrentPage_x                                  0x8FAE10
#define CTabWnd__GetPageInnerRect_x                                0x8FA520
#define CTabWnd__GetTabInnerRect_x                                 0x8FA720
#define CTabWnd__GetTabRect_x                                      0x8FA5F0
#define CTabWnd__InsertPage_x                                      0x8FB4C0
#define CTabWnd__SetPage_x                                         0x8FAE40
#define CTabWnd__SetPageRect_x                                     0x8FB110
#define CTabWnd__UpdatePage_x                                      0x8FB460
#define CTabWnd__GetPageFromTabIndex_x                             0x8FA780
#define CTabWnd__GetCurrentTabIndex_x                              0x8FA4B0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E6C00
#define CPageWnd__SetTabText_x                                     0x907730

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436D50

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D7080
#define CTextureFont__GetTextExtent_x                              0x8D6DE0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63E280

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x903B20

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BC980

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029D0
#define CXStr__CXStr1_x                                            0x8B2080
#define CXStr__CXStr3_x                                            0x89F9F0
#define CXStr__dCXStr_x                                            0x4D9C70
#define CXStr__operator_equal_x                                    0x89FB60
#define CXStr__operator_equal1_x                                   0x89FBB0
#define CXStr__operator_plus_equal1_x                              0x8A0CB0

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D4B70
#define CXWnd__BringToTop_x                                        0x8CBCE0
#define CXWnd__Center_x                                            0x8D1E50
#define CXWnd__ClrFocus_x                                          0x8CB8B0
#define CXWnd__Destroy_x                                           0x8D2930
#define CXWnd__DoAllDrawing_x                                      0x8D1AB0
#define CXWnd__DrawChildren_x                                      0x8D1C40
#define CXWnd__DrawColoredRect_x                                   0x8CC0C0
#define CXWnd__DrawTooltip_x                                       0x8CC360
#define CXWnd__DrawTooltipAtPoint_x                                0x8D0A50
#define CXWnd__GetBorderFrame_x                                    0x8CC7B0
#define CXWnd__GetChildWndAt_x                                     0x8D2820
#define CXWnd__GetClientClipRect_x                                 0x8CC570
#define CXWnd__GetScreenClipRect_x                                 0x8D1140
#define CXWnd__GetScreenRect_x                                     0x8CC960
#define CXWnd__GetTooltipRect_x                                    0x8CC1F0
#define CXWnd__GetWindowTextA_x                                    0x426EA0
#define CXWnd__IsActive_x                                          0x8C7270
#define CXWnd__IsDescendantOf_x                                    0x8CC700
#define CXWnd__IsReallyVisible_x                                   0x8CFA80
#define CXWnd__IsType_x                                            0x8D1EC0
#define CScreenPieceTemplate__IsType_x                             0x900230
#define CXWnd__Move_x                                              0x8CF160
#define CXWnd__Move1_x                                             0x8D1760
#define CXWnd__ProcessTransition_x                                 0x8CBC80
#define CXWnd__Refade_x                                            0x8CBA50
#define CXWnd__Resize_x                                            0x8CCA20
#define CXWnd__Right_x                                             0x8D0F40
#define CXWnd__SetFocus_x                                          0x8CE2E0
#define CXWnd__SetFont_x                                           0x8CB900
#define CXWnd__SetKeyTooltip_x                                     0x8CCC90
#define CXWnd__SetMouseOver_x                                      0x8D1450
#define CXWnd__StartFade_x                                         0x8CBD30
#define CXWnd__GetChildItem_x                                      0x8D1390
#define CXWnd__SetParent_x                                         0x8D27D0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C8B20
#define CXWndManager__DrawWindows_x                                0x8C8760
#define CXWndManager__GetKeyboardFlags_x                           0x8C6DE0
#define CXWndManager__HandleKeyboardMsg_x                          0x8C7710
#define CXWndManager__RemoveWnd_x                                  0x8C7400

// CDBStr
#define CDBStr__GetString_x                                        0x4BA510

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4526A0
#define EQ_Character__Cur_HP_x                                     0x466AB0
#define EQ_Character__Cur_Mana_x                                   0x45BA90
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B780
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443710
#define EQ_Character__GetFocusRangeModifier_x                      0x443860
#define EQ_Character__GetHPRegen_x                                 0x46A650
#define EQ_Character__GetEnduranceRegen_x                          0x4660C0
#define EQ_Character__GetManaRegen_x                               0x46ABF0
#define EQ_Character__Max_Endurance_x                              0x5CC0D0
#define EQ_Character__Max_HP_x                                     0x45E610
#define EQ_Character__Max_Mana_x                                   0x5CBF00
#define EQ_Character__doCombatAbility_x                            0x5C95D0
#define EQ_Character__UseSkill_x                                   0x4729E0
#define EQ_Character__GetConLevel_x                                0x5BEC70
#define EQ_Character__IsExpansionFlag_x                            0x4B67E0
#define EQ_Character__TotalEffect_x                                0x44F8D0
#define EQ_Character__GetPCSpellAffect_x                           0x44BB10
#define EQ_Character__SpellDuration_x                              0x449B10
#define EQ_Character__FindItemByRecord_x                           0x464100
#define EQ_Character__GetAdjustedSkill_x                           0x466C80
#define EQ_Character__GetBaseSkill_x                               0x45E4F0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x872E70

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D4780

//PcClient
#define PcClient__PcClient_x                                       0x5C0AC0

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446C20
#define CCharacterSelect__EnterWorld_x                             0x4463F0
#define CCharacterSelect__Quit_x                                   0x444FB0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59ED50
#define EQ_Item__CreateItemTagString_x                             0x8530C0
#define EQ_Item__IsStackable_x                                     0x848760
#define EQ_Item__GetImageNum_x                                     0x84B270
#define EQ_Item__CreateItemClient_x                                0x59FE90
#define EQ_Item__GetItemValue_x                                    0x851B70
#define EQ_Item__ValueSellMerchant_x                               0x854B10
#define EQ_Item__IsKeyRingItem_x                                   0x849240
#define EQ_Item__CanGoInBag_x                                      0x59EEE0
#define EQ_Item__GetMaxItemCount_x                                 0x848650
#define EQ_Item__GetHeldItem_x                                     0x84A090
#define EQ_Item__GetAugmentFitBySlot_x                             0x854930

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA600
#define EQ_LoadingS__Array_x                                       0xC0AC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CE5F0
#define EQ_PC__GetAlternateAbilityId_x                             0x85CF30
#define EQ_PC__GetCombatAbility_x                                  0x85CFC0
#define EQ_PC__GetCombatAbilityTimer_x                             0x857B60
#define EQ_PC__GetItemRecastTimer_x                                0x5C7DC0
#define EQ_PC__HasLoreItem_x                                       0x5C2280
#define EQ_PC__AlertInventoryChanged_x                             0x5BEC20
#define EQ_PC__GetPcZoneClient_x                                   0x5E8D10
#define EQ_PC__RemoveMyAffect_x                                    0x5C71F0
#define EQ_PC__GetKeyRingItems_x                                   0x857F80
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86AC40
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85EEB0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5270D0
#define EQItemList__add_object_x                                   0x554260
#define EQItemList__add_item_x                                     0x527010
#define EQItemList__delete_item_x                                  0x5274C0
#define EQItemList__FreeItemList_x                                 0x5273C0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B97F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D4440
#define EQPlayer__dEQPlayer_x                                      0x5DCBF0
#define EQPlayer__DoAttack_x                                       0x5EE4A0
#define EQPlayer__EQPlayer_x                                       0x5DF320
#define EQPlayer__SetNameSpriteState_x                             0x5D9A20
#define EQPlayer__SetNameSpriteTint_x                              0x5D5940
#define PlayerBase__HasProperty_j_x                                0x931510
#define EQPlayer__IsTargetable_x                                   0x9317B0
#define EQPlayer__CanSee_x                                         0x931D10
#define PlayerZoneClient__ChangeHeight_x                           0x5EE360
#define EQPlayer__CanSee1_x                                        0x931E00
#define PlayerBase__GetVisibilityLineSegment_x                     0x931AA0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E8EC0
#define PlayerZoneClient__IsValidTeleport_x                        0x554B00
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2920


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E3350
#define EQPlayerManager__GetSpawnByName_x                          0x5E37B0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E3380

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A5380
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A53C0
#define KeypressHandler__ClearCommandStateArray_x                  0x5A4F70
#define KeypressHandler__HandleKeyDown_x                           0x5A3890
#define KeypressHandler__HandleKeyUp_x                             0x5A3BB0
#define KeypressHandler__SaveKeymapping_x                          0x5A5040

// MapViewMap 
#define MapViewMap__Clear_x                                        0x712A30
#define MapViewMap__SaveEx_x                                       0x715D60
#define MapViewMap__SetZoom_x                                      0x7126C0

#define PlayerPointManager__GetAltCurrency_x                       0x870E50

// StringTable 
#define StringTable__getString_x                                   0x86AF70

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CBB60
#define PcZoneClient__RemovePetEffect_x                            0x5C8290
#define PcZoneClient__HasAlternateAbility_x                        0x5C8C30
#define PcZoneClient__GetCurrentMod_x                              0x45DAC0
#define PcZoneClient__GetModCap_x                                  0x45B1F0
#define PcZoneClient__CanEquipItem_x                               0x5C9110
#define PcZoneClient__GetItemByID_x                                0x5CD970
#define PcZoneClient__GetItemByItemClass_x                         0x5CE510
#define PcZoneClient__RemoveBuffEffect_x                           0x5C74A0

//Doors
#define EQSwitch__UseSwitch_x                                      0x55BB70

//IconCache
#define IconCache__GetIcon_x                                       0x6AFC20

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A6B50
#define CContainerMgr__CloseContainer_x                            0x6A7370

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x773570

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x597E30

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4D90
#define EQ_Spell__SpellAffects_x                                   0x4F1F70
#define EQ_Spell__SpellAffectBase_x                                0x4F1FE0
#define CharacterZoneClient__CalcAffectChange_x                    0x44B9A0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AC40
#define CLootWnd__LootAll_x                                        0x708300
#define CLootWnd__RequestLootSlot_x                                0x708B10
#define EQ_Spell__IsStackable_x                                    0x459170
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4495B0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EC60
#define EQ_Spell__IsSPAStacking_x                                  0x4F1AE0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2B80
#define EQ_Spell__IsNoRemove_x                                     0x434D90
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1B00

#define __IsResEffectSpell_x                                       0x449660

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87CB00

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BB320
#define CTargetWnd__WndNotification_x                              0x7BAE10
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BB500

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C0440

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED660
#define EqSoundManager__PlayScriptMp3_x                            0x4EF100

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8870

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EAF60
#define CSidlManager__FindAnimation1_x                             0x8E0230

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E1F10
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1EC0
#define CAltAbilityData__GetMaxRank_x                              0x4D6680

//CTargetRing
#define CTargetRing__Cast_x                                        0x595A70

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459480
#define CharacterBase__CreateItemGlobalIndex_x                     0x475400
#define CharacterBase__CreateItemIndex_x                           0x5206B0
#define CharacterBase__GetItemPossession_x                         0x444480
#define CharacterBase__GetItemByGlobalIndex_x                      0x880980
#define CharacterBase__GetEffectId_x                               0x459440

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68FA50
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68F1B0

//messages
#define msg_spell_worn_off_x                                       0x4FC960
#define msg_new_text_x                                             0x5060E0
#define msgTokenTextParam_x                                        0x5028E0

//SpellManager
#define SpellManager__vftable_x                                    0xAC8250
#define SpellManager__SpellManager_x                               0x47E040
#define Spellmanager__LoadTextSpells_x                             0x60C860

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9358A0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487CB0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EB70
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4492F0
#define ItemGlobalIndex__IsValidIndex_x                            0x458CB0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87E800
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87D740

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x701320

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AB850
#define CCursorAttachment__Deactivate_x                            0x6AADA0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FCB60
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FCCE0

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x604410

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C520

//IString
#define IString__Append_x                                          0x47ECF0

//Camera
#define CDisplay__cameraType_x                                     0xE6E7C8
#define EverQuest__Cameras_x                                       0xF30AC8
