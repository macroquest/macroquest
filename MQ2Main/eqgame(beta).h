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
#define __ExpectedVersionDate                                     "Dec  4 2017"
#define __ExpectedVersionTime                                     "04:17:25"
#define __ActualVersionDate_x                                      0xAE30D8
#define __ActualVersionTime_x                                      0xAE30E4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x5A9850
#define __MemChecker1_x                                            0x8A27F0
#define __MemChecker2_x                                            0x63FB20
#define __MemChecker3_x                                            0x63FA70
#define __MemChecker4_x                                            0x7F4090
#define __EncryptPad0_x                                            0xC3DFE8
#define __EncryptPad1_x                                            0xD17BA0
#define __EncryptPad2_x                                            0xC66ED0
#define __EncryptPad3_x                                            0xC66AD0
#define __EncryptPad4_x                                            0xD061A0
#define __EncryptPad5_x                                            0x10C12C0
#define __AC1_x                                                    0x7B2FD5
#define __AC2_x                                                    0x562AA7
#define __AC3_x                                                    0x560C20
#define __AC4_x                                                    0x572D61
#define __AC5_x                                                    0x586AAB
#define __AC6_x                                                    0x58A65E
#define __AC7_x                                                    0x5810AC
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
#define __do_loot_x                                                0x531A10
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
#define __CastRay_x                                                0x5492D0
#define __CastRay2_x                                               0x548C00
#define __HeadingDiff_x                                            0x932BD0
#define __FixHeading_x                                             0x932B60
#define __get_bearing_x                                            0x538B60
#define __ConvertItemTags_x                                        0x536630
#define __ExecuteCmd_x                                             0x520F30
#define __EQGetTime_x                                              0x8A2190
#define __get_melee_range_x                                        0x527BD0
#define __GetGaugeValueFromEQ_x                                    0x7B1B90
#define __GetLabelFromEQ_x                                         0x7B2F60
#define __ToggleKeyRingItem_x                                      0x48F930
#define __GetXTargetType_x                                         0x9347D0
#define __LoadFrontEnd_x                                           0x63F1F0
#define __NewUIINI_x                                               0x7B1560
#define __ProcessGameEvents_x                                      0x582E40
#define __ProcessMouseEvent_x                                      0x5825E0
#define CrashDetected_x                                            0x640BB0
#define wwsCrashReportCheckForUploader_x                           0x7FFF40
#define __AppCrashWrapper_x                                        0xC66AC4
#define __pCrashHandler_x                                          0x10D69E0
#define __CrashHandler_x                                           0x7FF9A0
#define wwsCrashReportPlatformLaunchUploader_x                     0x802140
#define DrawNetStatus_x                                            0x5B9400
#define Util__FastTime_x                                           0x8A1E30
#define Expansion_HoT_x                                            0xF307B0
#define __HelpPath_x                                               0xFB3F60
#define __STMLToText_x                                             0x8E8590
#define __GetAnimationCache_x                                      0x6AE9D0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4233D0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E030
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DE00

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D7BD0
#define AltAdvManager__IsAbilityReady_x                            0x4D7C40
#define AltAdvManager__GetAAById_x                                 0x4D8130
#define AltAdvManager__CanTrainAbility_x                           0x4D8D60
#define AltAdvManager__CanSeeAbility_x                             0x4D8920

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AE00
#define CharacterZoneClient__HasSkill_x                            0x466D10
#define CharacterZoneClient__MakeMeVisible_x                       0x46C970
#define CharacterZoneClient__IsStackBlocked_x                      0x44BE30
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B350
#define CharacterZoneClient__GetItemCountWorn_x                    0x465270
#define CharacterZoneClient__GetItemCountInInventory_x             0x465350
#define CharacterZoneClient__GetCursorItemCount_x                  0x465430
#define CharacterZoneClient__FindAffectSlot_x                      0x4514B0
#define CharacterZoneClient__BardCastBard_x                        0x44AAC0
#define CharacterZoneClient__GetMaxEffects_x                       0x449650
#define CharacterZoneClient__GetEffect_x                           0x44B580
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451310
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x4499A0
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FE60

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66EBB0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67CA50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x598020
#define CButtonWnd__CButtonWnd_x                                   0x8DC7C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x697B30
#define CChatManager__InitContextMenu_x                            0x698C80
#define CChatManager__FreeChatWindow_x                             0x6975E0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A0E30
#define CChatManager__SetLockedActiveChatWindow_x                  0x697B00

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E68F0
#define CContextMenu__dCContextMenu_x                              0x8E6B00
#define CContextMenu__AddMenuItem_x                                0x8E7010
#define CContextMenu__RemoveMenuItem_x                             0x8E6C70
#define CContextMenu__RemoveAllMenuItems_x                         0x8E6C90
#define CContextMenu__CheckMenuItem_x                              0x8E6D10
#define CContextMenu__SetMenuItem_x                                0x8E6BA0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D2D90
#define CContextMenuManager__RemoveMenu_x                          0x8D3130
#define CContextMenuManager__PopupMenu_x                           0x8D3580
#define CContextMenuManager__Flush_x                               0x8D2E00
#define CContextMenuManager__GetMenu_x                             0x419500

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x886290
#define CChatService__GetFriendName_x                              0x8862A0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69E900
#define CChatWindow__Clear_x                                       0x69E1E0
#define CChatWindow__WndNotification_x                             0x69F210

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D6C00
#define CComboWnd__Draw_x                                          0x8D6E10
#define CComboWnd__GetCurChoice_x                                  0x8D69B0
#define CComboWnd__GetListRect_x                                   0x8D70B0
#define CComboWnd__GetTextRect_x                                   0x8D6C70
#define CComboWnd__InsertChoice_x                                  0x8D7210
#define CComboWnd__SetColors_x                                     0x8D6940
#define CComboWnd__SetChoice_x                                     0x8D6970
#define CComboWnd__GetItemCount_x                                  0x8D69A0
#define CComboWnd__GetCurChoiceText_x                              0x8D69F0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A8B60
#define CContainerWnd__vftable_x                                   0xAEC9F0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C5B20
#define CDisplay__GetClickedActor_x                                0x4BE3E0
#define CDisplay__GetUserDefinedColor_x                            0x4BCFC0
#define CDisplay__GetWorldFilePath_x                               0x4BC410
#define CDisplay__is3dON_x                                         0x4BB8A0
#define CDisplay__ReloadUI_x                                       0x4CF8E0
#define CDisplay__WriteTextHD2_x                                   0x4C1EB0
#define CDisplay__TrueDistance_x                                   0x4BF010

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FDDD0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EAE40
#define CEditWnd__GetCharIndexPt_x                                 0x8EBF80
#define CEditWnd__GetDisplayString_x                               0x8EAFF0
#define CEditWnd__GetHorzOffset_x                                  0x8EB330
#define CEditWnd__GetLineForPrintableChar_x                        0x8EBA50
#define CEditWnd__GetSelStartPt_x                                  0x8EC230
#define CEditWnd__GetSTMLSafeText_x                                0x8EB4C0
#define CEditWnd__PointFromPrintableChar_x                         0x8EBB40
#define CEditWnd__SelectableCharFromPoint_x                        0x8EBCC0
#define CEditWnd__SetEditable_x                                    0x8EB490

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x569590
#define CEverQuest__ClickedPlayer_x                                0x5631F0
#define CEverQuest__CreateTargetIndicator_x                        0x5640F0
#define CEverQuest__DeleteTargetIndicator_x                        0x564170
#define CEverQuest__DoTellWindow_x                                 0x476080
#define CEverQuest__OutputTextToLog_x                              0x475CE0
#define CEverQuest__DropHeldItemOnGround_x                         0x579B00
#define CEverQuest__dsp_chat_x                                     0x4763C0
#define CEverQuest__trimName_x                                     0x55FB00
#define CEverQuest__Emote_x                                        0x577E10
#define CEverQuest__EnterZone_x                                    0x572EF0
#define CEverQuest__GetBodyTypeDesc_x                              0x55D540
#define CEverQuest__GetClassDesc_x                                 0x566A30
#define CEverQuest__GetClassThreeLetterCode_x                      0x567030
#define CEverQuest__GetDeityDesc_x                                 0x55DE20
#define CEverQuest__GetLangDesc_x                                  0x55D8D0
#define CEverQuest__GetRaceDesc_x                                  0x5671F0
#define CEverQuest__InterpretCmd_x                                 0x56AD10
#define CEverQuest__LeftClickedOnPlayer_x                          0x57F650
#define CEverQuest__LMouseUp_x                                     0x581600
#define CEverQuest__RightClickedOnPlayer_x                         0x580160
#define CEverQuest__RMouseUp_x                                     0x581060
#define CEverQuest__SetGameState_x                                 0x563AC0
#define CEverQuest__UPCNotificationFlush_x                         0x55BED0
#define CEverQuest__IssuePetCommand_x                              0x56B6F0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B9820
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B9880
#define CGaugeWnd__Draw_x                                          0x6B9CB0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B0B0
#define CGuild__GetGuildName_x                                     0x43B580
#define CGuild__GetGuildIndex_x                                    0x43C790

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D5D20

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E30C0
#define CInvSlotMgr__MoveItem_x                                    0x6E3880
#define CInvSlotMgr__SelectSlot_x                                  0x6E29B0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E1E10
#define CInvSlot__SliderComplete_x                                 0x6DF630
#define CInvSlot__GetItemBase_x                                    0x6DEAD0
#define CInvSlot__UpdateItem_x                                     0x6DF050

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E4CB0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E5DF0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AD9F0
#define CItemDisplayWnd__UpdateStrings_x                           0x6E6EE0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F37C0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F3CE0
#define CItemDisplayWnd__SetItem_x                                 0x6F9550

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E4C30

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6ED4B0

// CLabel 
#define CLabel__Draw_x                                             0x7003C0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C2890
#define CListWnd__dCListWnd_x                                      0x8C3B20
#define CListWnd__AddColumn_x                                      0x8C3AC0
#define CListWnd__AddColumn1_x                                     0x8C3160
#define CListWnd__AddLine_x                                        0x8C2B40
#define CListWnd__AddString_x                                      0x8C2D60
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BF9B0
#define CListWnd__CalculateVSBRange_x                              0x8C1D50
#define CListWnd__ClearSel_x                                       0x8BECD0
#define CListWnd__ClearAllSel_x                                    0x8BEC80
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C2720
#define CListWnd__Compare_x                                        0x8C06A0
#define CListWnd__Draw_x                                           0x8C1960
#define CListWnd__DrawColumnSeparators_x                           0x8C17F0
#define CListWnd__DrawHeader_x                                     0x8BEF90
#define CListWnd__DrawItem_x                                       0x8C0D30
#define CListWnd__DrawLine_x                                       0x8C1490
#define CListWnd__DrawSeparator_x                                  0x8C1890
#define CListWnd__EnableLine_x                                     0x8BEEB0
#define CListWnd__EnsureVisible_x                                  0x8BFB10
#define CListWnd__ExtendSel_x                                      0x8C0C40
#define CListWnd__GetColumnMinWidth_x                              0x8BE5C0
#define CListWnd__GetColumnWidth_x                                 0x8BE4F0
#define CListWnd__GetCurSel_x                                      0x8BDCC0
#define CListWnd__GetItemAtPoint_x                                 0x8BFDA0
#define CListWnd__GetItemAtPoint1_x                                0x8BFE10
#define CListWnd__GetItemData_x                                    0x8BE000
#define CListWnd__GetItemHeight_x                                  0x8BF610
#define CListWnd__GetItemIcon_x                                    0x8BE1F0
#define CListWnd__GetItemRect_x                                    0x8BFBE0
#define CListWnd__GetItemText_x                                    0x8BE0A0
#define CListWnd__GetSelList_x                                     0x8C3050
#define CListWnd__GetSeparatorRect_x                               0x8C05C0
#define CListWnd__InsertLine_x                                     0x8C2F40
#define CListWnd__RemoveLine_x                                     0x8C2F50
#define CListWnd__SetColors_x                                      0x8BDE10
#define CListWnd__SetColumnJustification_x                         0x8BE850
#define CListWnd__SetColumnWidth_x                                 0x8BE570
#define CListWnd__SetCurSel_x                                      0x8BDD00
#define CListWnd__SetItemColor_x                                   0x8C2410
#define CListWnd__SetItemData_x                                    0x8BED30
#define CListWnd__SetItemText_x                                    0x8C2250
#define CListWnd__ShiftColumnSeparator_x                           0x8C20E0
#define CListWnd__Sort_x                                           0x8C3C20
#define CListWnd__ToggleSel_x                                      0x8BEC00

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x719510

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73EA90
#define CMerchantWnd__RequestBuyItem_x                             0x746650
#define CMerchantWnd__RequestSellItem_x                            0x748C60
#define CMerchantWnd__SelectRecoverySlot_x                         0x73BD40
#define CMerchantWnd__SelectBuySellSlot_x                          0x739BC0
#define CMerchantWnd__ActualSelect_x                               0x740880

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8545E0
#define CPacketScrambler__hton_x                                   0x8545F0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E1800
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E18E0
#define CSidlManager__CreateLabel_x                                0x7A2A20
#define CSidlManager__CreateXWndFromTemplate_x                     0x8DFD90
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E1BC0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D8C30
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D8B20
#define CSidlScreenWnd__ConvertToRes_x                             0x8FDCB0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D9550
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DA720
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DA7D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D9CB0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D8F00
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8650
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D90F0
#define CSidlScreenWnd__Init1_x                                    0x8DA400
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D9610
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8810
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D9EF0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D82B0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8600
#define CSidlScreenWnd__WndNotification_x                          0x8DA180
#define CSidlScreenWnd__GetChildItem_x                             0x8D8720
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CBFB0
#define CSidlScreenWnd__m_layoutCopy_x                             0x172FE20

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x604790
#define CSkillMgr__GetSkillCap_x                                   0x604970
#define CSkillMgr__GetNameToken_x                                  0x604340

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FCF80
#define CSliderWnd__SetValue_x                                     0x8FD150
#define CSliderWnd__SetNumTicks_x                                  0x8FD8D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A8CE0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6870
#define CStmlWnd__CalculateHSBRange_x                              0x8EEDE0
#define CStmlWnd__CalculateVSBRange_x                              0x8EED50
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EEF60
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EF760
#define CStmlWnd__ForceParseNow_x                                  0x8F71F0
#define CStmlWnd__GetNextTagPiece_x                                0x8EF660
#define CStmlWnd__GetSTMLText_x                                    0x484280
#define CStmlWnd__GetVisibleText_x                                 0x8F01B0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2780
#define CStmlWnd__MakeStmlColorTag_x                               0x8EE030
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EE090
#define CStmlWnd__SetSTMLText_x                                    0x8F3FE0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6510
#define CStmlWnd__UpdateHistoryString_x                            0x8F10F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FA700
#define CTabWnd__DrawCurrentPage_x                                 0x8F9F90
#define CTabWnd__DrawTab_x                                         0x8F9D60
#define CTabWnd__GetCurrentPage_x                                  0x8FA340
#define CTabWnd__GetPageInnerRect_x                                0x8F9A50
#define CTabWnd__GetTabInnerRect_x                                 0x8F9C50
#define CTabWnd__GetTabRect_x                                      0x8F9B20
#define CTabWnd__InsertPage_x                                      0x8FA9F0
#define CTabWnd__SetPage_x                                         0x8FA370
#define CTabWnd__SetPageRect_x                                     0x8FA640
#define CTabWnd__UpdatePage_x                                      0x8FA990
#define CTabWnd__GetPageFromTabIndex_x                             0x8F9CB0
#define CTabWnd__GetCurrentTabIndex_x                              0x8F99E0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E5FA0
#define CPageWnd__SetTabText_x                                     0x907000

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436CC0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D65B0
#define CTextureFont__GetTextExtent_x                              0x8D6310

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63D490

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x903440

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BBF60

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029E0
#define CXStr__CXStr1_x                                            0x8BCEE0
#define CXStr__CXStr3_x                                            0x89F0C0
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x89F230
#define CXStr__operator_equal1_x                                   0x89F280
#define CXStr__operator_plus_equal1_x                              0x8A0380

// CXWnd
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D40A0
#define CXWnd__BringToTop_x                                        0x8CB1E0
#define CXWnd__Center_x                                            0x8D13A0
#define CXWnd__ClrFocus_x                                          0x8CADC0
#define CXWnd__Destroy_x                                           0x8D1E80
#define CXWnd__DoAllDrawing_x                                      0x8D0FF0
#define CXWnd__DrawChildren_x                                      0x8D1190
#define CXWnd__DrawColoredRect_x                                   0x8CB5A0
#define CXWnd__DrawTooltip_x                                       0x8CB850
#define CXWnd__DrawTooltipAtPoint_x                                0x8CFF50
#define CXWnd__GetBorderFrame_x                                    0x8CBC80
#define CXWnd__GetChildWndAt_x                                     0x8D1D60
#define CXWnd__GetClientClipRect_x                                 0x8CBA50
#define CXWnd__GetScreenClipRect_x                                 0x8D0640
#define CXWnd__GetScreenRect_x                                     0x8CBE50
#define CXWnd__GetTooltipRect_x                                    0x8CB6E0
#define CXWnd__GetWindowTextA_x                                    0x426FE0
#define CXWnd__IsActive_x                                          0x8C68D0
#define CXWnd__IsDescendantOf_x                                    0x8CBBC0
#define CXWnd__IsReallyVisible_x                                   0x8CEF80
#define CXWnd__IsType_x                                            0x8D1410
#define CScreenPieceTemplate__IsType_x                             0x8FFB50
#define CXWnd__Move_x                                              0x8CE690
#define CXWnd__Move1_x                                             0x8D0C90
#define CXWnd__ProcessTransition_x                                 0x8CB190
#define CXWnd__Refade_x                                            0x8CAF60
#define CXWnd__Resize_x                                            0x8CBF10
#define CXWnd__Right_x                                             0x8D0440
#define CXWnd__SetFocus_x                                          0x8CD800
#define CXWnd__SetFont_x                                           0x8CAE10
#define CXWnd__SetKeyTooltip_x                                     0x8CC180
#define CXWnd__SetMouseOver_x                                      0x8D0980
#define CXWnd__StartFade_x                                         0x8CB230
#define CXWnd__GetChildItem_x                                      0x8D08C0
#define CXWnd__SetParent_x                                         0x8D1D10

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C8190
#define CXWndManager__DrawWindows_x                                0x8C7DD0
#define CXWndManager__GetKeyboardFlags_x                           0x8C6400
#define CXWndManager__HandleKeyboardMsg_x                          0x8C6D70
#define CXWndManager__RemoveWnd_x                                  0x8C6A60

// CDBStr
#define CDBStr__GetString_x                                        0x4BA100

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452570
#define EQ_Character__Cur_HP_x                                     0x4668F0
#define EQ_Character__Cur_Mana_x                                   0x45B8D0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B660
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443610
#define EQ_Character__GetFocusRangeModifier_x                      0x443760
#define EQ_Character__GetHPRegen_x                                 0x46A490
#define EQ_Character__GetEnduranceRegen_x                          0x465F00
#define EQ_Character__GetManaRegen_x                               0x46AA30
#define EQ_Character__Max_Endurance_x                              0x5CAE50
#define EQ_Character__Max_HP_x                                     0x45E450
#define EQ_Character__Max_Mana_x                                   0x5CAC80
#define EQ_Character__doCombatAbility_x                            0x5C8350
#define EQ_Character__UseSkill_x                                   0x472820
#define EQ_Character__GetConLevel_x                                0x5BDA30
#define EQ_Character__IsExpansionFlag_x                            0x4B6480
#define EQ_Character__TotalEffect_x                                0x44F7A0
#define EQ_Character__GetPCSpellAffect_x                           0x44B9F0
#define EQ_Character__SpellDuration_x                              0x4499F0
#define EQ_Character__FindItemByRecord_x                           0x463F40
#define EQ_Character__GetAdjustedSkill_x                           0x466AC0
#define EQ_Character__GetBaseSkill_x                               0x45E330

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x872480

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D35C0

//PcClient
#define PcClient__PcClient_x                                       0x5BF890

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446B20
#define CCharacterSelect__EnterWorld_x                             0x4462F0
#define CCharacterSelect__Quit_x                                   0x444EB0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59D9F0
#define EQ_Item__CreateItemTagString_x                             0x852790
#define EQ_Item__IsStackable_x                                     0x847AD0
#define EQ_Item__GetImageNum_x                                     0x84A5C0
#define EQ_Item__CreateItemClient_x                                0x59EB20
#define EQ_Item__GetItemValue_x                                    0x851200
#define EQ_Item__ValueSellMerchant_x                               0x854230
#define EQ_Item__IsKeyRingItem_x                                   0x8485C0
#define EQ_Item__CanGoInBag_x                                      0x59DB80
#define EQ_Item__GetMaxItemCount_x                                 0x8479C0
#define EQ_Item__GetHeldItem_x                                     0x8493C0
#define EQ_Item__GetAugmentFitBySlot_x                             0x854060

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA1E0
#define EQ_LoadingS__Array_x                                       0xC0AC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CD380
#define EQ_PC__GetAlternateAbilityId_x                             0x85C6C0
#define EQ_PC__GetCombatAbility_x                                  0x85C750
#define EQ_PC__GetCombatAbilityTimer_x                             0x857290
#define EQ_PC__GetItemRecastTimer_x                                0x5C6B40
#define EQ_PC__HasLoreItem_x                                       0x5C1050
#define EQ_PC__AlertInventoryChanged_x                             0x5BD9E0
#define EQ_PC__GetPcZoneClient_x                                   0x5E7B80
#define EQ_PC__RemoveMyAffect_x                                    0x5C5F70
#define EQ_PC__GetKeyRingItems_x                                   0x8576B0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86A3F0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85E660

// EQItemList 
#define EQItemList__EQItemList_x                                   0x525C80
#define EQItemList__add_object_x                                   0x552DA0
#define EQItemList__add_item_x                                     0x525BC0
#define EQItemList__delete_item_x                                  0x526070
#define EQItemList__FreeItemList_x                                 0x525F70

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9400

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D3280
#define EQPlayer__dEQPlayer_x                                      0x5DBA40
#define EQPlayer__DoAttack_x                                       0x5ED360
#define EQPlayer__EQPlayer_x                                       0x5DE170
#define EQPlayer__SetNameSpriteState_x                             0x5D8870
#define EQPlayer__SetNameSpriteTint_x                              0x5D4780
#define PlayerBase__HasProperty_j_x                                0x930F90
#define EQPlayer__IsTargetable_x                                   0x931230
#define EQPlayer__CanSee_x                                         0x931790
#define PlayerZoneClient__ChangeHeight_x                           0x5ED220
#define EQPlayer__CanSee1_x                                        0x931880
#define PlayerBase__GetVisibilityLineSegment_x                     0x931520

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E7D30
#define PlayerZoneClient__IsValidTeleport_x                        0x553660
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D24D0


//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E21B0
#define EQPlayerManager__GetSpawnByName_x                          0x5E2610
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E21E0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A4090
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A40D0
#define KeypressHandler__ClearCommandStateArray_x                  0x5A3C80
#define KeypressHandler__HandleKeyDown_x                           0x5A25A0
#define KeypressHandler__HandleKeyUp_x                             0x5A28C0
#define KeypressHandler__SaveKeymapping_x                          0x5A3D50

// MapViewMap 
#define MapViewMap__Clear_x                                        0x711EA0
#define MapViewMap__SaveEx_x                                       0x7151D0
#define MapViewMap__SetZoom_x                                      0x711B00

#define PlayerPointManager__GetAltCurrency_x                       0x870500

// StringTable 
#define StringTable__getString_x                                   0x86A720

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CA8E0
#define PcZoneClient__RemovePetEffect_x                            0x5C7010
#define PcZoneClient__HasAlternateAbility_x                        0x5C79B0
#define PcZoneClient__GetCurrentMod_x                              0x45D900
#define PcZoneClient__GetModCap_x                                  0x45B030
#define PcZoneClient__CanEquipItem_x                               0x5C7E90
#define PcZoneClient__GetItemByID_x                                0x5CC6F0
#define PcZoneClient__GetItemByItemClass_x                         0x5CD2A0
#define PcZoneClient__RemoveBuffEffect_x                           0x5C6220

//Doors
#define EQSwitch__UseSwitch_x                                      0x55A780

//IconCache
#define IconCache__GetIcon_x                                       0x6AF000

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A5EE0
#define CContainerMgr__CloseContainer_x                            0x6A6700

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7729D0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x596A40

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4750
#define EQ_Spell__SpellAffects_x                                   0x4F1930
#define EQ_Spell__SpellAffectBase_x                                0x4F19A0
#define CharacterZoneClient__CalcAffectChange_x                    0x44B880
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44AB20
#define CLootWnd__LootAll_x                                        0x707760
#define CLootWnd__RequestLootSlot_x                                0x707F70
#define EQ_Spell__IsStackable_x                                    0x459070
#define EQ_Spell__GetSpellAffectBySlot_x                           0x4494C0
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EB60
#define EQ_Spell__IsSPAStacking_x                                  0x4F14A0
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F2540
#define EQ_Spell__IsNoRemove_x                                     0x434CF0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F14C0

#define __IsResEffectSpell_x                                       0x449540

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87C120

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BA660
#define CTargetWnd__WndNotification_x                              0x7BA150
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BA840

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7BF780

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED000
#define EqSoundManager__PlayScriptMp3_x                            0x4EEAA0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8590

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EA470
#define CSidlManager__FindAnimation1_x                             0x8DF7C0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E1A30
#define CAltAbilityData__GetMercMaxRank_x                          0x4E19E0
#define CAltAbilityData__GetMaxRank_x                              0x4D6280

//CTargetRing
#define CTargetRing__Cast_x                                        0x594680

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459330
#define CharacterBase__CreateItemGlobalIndex_x                     0x475250
#define CharacterBase__CreateItemIndex_x                           0x51F2A0
#define CharacterBase__GetItemPossession_x                         0x444380
#define CharacterBase__GetItemByGlobalIndex_x                      0x87FF70
#define CharacterBase__GetEffectId_x                               0x4592F0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68ED60
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68E4C0

//messages
#define msg_spell_worn_off_x                                       0x4FC250
#define msg_new_text_x                                             0x5059D0
#define msgTokenTextParam_x                                        0x5021D0

//SpellManager
#define SpellManager__vftable_x                                    0xAC8260
#define SpellManager__SpellManager_x                               0x47DE90
#define Spellmanager__LoadTextSpells_x                             0x60B720

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9352F0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487880
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EA70
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449210
#define ItemGlobalIndex__IsValidIndex_x                            0x458BB0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87DDE0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87CD20

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x700610

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AAC30
#define CCursorAttachment__Deactivate_x                            0x6AA170

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FC480
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FC600

//ScreenWndManager (has the size of CSidlScreenWnd__CSidlScreenWnd1_x
//and thats the reason I added it here, we dont actually call it. - eqmule
#define ScreenWndManager__RegisterManaged_x                        0x6032A0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C0F0

//IString
#define IString__Append_x                                          0x47EB10

//Camera
#define CDisplay__cameraType_x                                     0xE6E7C8
#define EverQuest__Cameras_x                                       0xF30AC8
