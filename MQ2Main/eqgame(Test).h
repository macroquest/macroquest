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
#if defined(TEST)
#include "eqgame-private(test).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Jan  3 2018"
#define __ExpectedVersionTime                                     "11:01:03"
#define __ActualVersionDate_x                                      0xAE3090
#define __ActualVersionTime_x                                      0xAE309C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5A9BF0
#define __MemChecker1_x                                            0x8A2A80
#define __MemChecker2_x                                            0x63FB70
#define __MemChecker3_x                                            0x63FAC0
#define __MemChecker4_x                                            0x7F43D0
#define __EncryptPad0_x                                            0xC3DFE8
#define __EncryptPad1_x                                            0xD17BA0
#define __EncryptPad2_x                                            0xC66ED0
#define __EncryptPad3_x                                            0xC66AD0
#define __EncryptPad4_x                                            0xD061A0
#define __EncryptPad5_x                                            0x10C12C0
#define __AC1_x                                                    0x7B3165
#define __AC2_x                                                    0x562CB7
#define __AC3_x                                                    0x560E30
#define __AC4_x                                                    0x573001
#define __AC5_x                                                    0x586DAB
#define __AC6_x                                                    0x58A94E
#define __AC7_x                                                    0x5813AC
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
#define __do_loot_x                                                0x531C70
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
#define pinstCGroupSearchFiltersWnd_x                              0xE6E62C
#define pinstCLoadskinWnd_x                                        0xE6E630
#define pinstCAlarmWnd_x                                           0xE6E634
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
#define pinstCLargeDialogWnd_x                                     0x10C8498
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
#define __CastRay_x                                                0x549530
#define __CastRay2_x                                               0x548E60
#define __HeadingDiff_x                                            0x932A50
#define __FixHeading_x                                             0x9329E0
#define __get_bearing_x                                            0x538DC0
#define __ConvertItemTags_x                                        0x536890
#define __ExecuteCmd_x                                             0x5211D0
#define __EQGetTime_x                                              0x8A2420
#define __get_melee_range_x                                        0x527E50
#define __GetGaugeValueFromEQ_x                                    0x7B1D20
#define __GetLabelFromEQ_x                                         0x7B30F0
#define __ToggleKeyRingItem_x                                      0x48FB10
#define __GetXTargetType_x                                         0x934650
#define __LoadFrontEnd_x                                           0x63F240
#define __NewUIINI_x                                               0x7B1700
#define __ProcessGameEvents_x                                      0x583140
#define __ProcessMouseEvent_x                                      0x5828E0
#define CrashDetected_x                                            0x640C00
#define wwsCrashReportCheckForUploader_x                           0x800100
#define __AppCrashWrapper_x                                        0xC66AC4
#define __pCrashHandler_x                                          0x10D69E0
#define __CrashHandler_x                                           0x7FFB80
#define wwsCrashReportPlatformLaunchUploader_x                     0x802330
#define DrawNetStatus_x                                            0x5B97E0
#define Util__FastTime_x                                           0x8A20C0
#define Expansion_HoT_x                                            0xF307B0
#define __HelpPath_x                                               0xFB3F60
#define __STMLToText_x                                             0x8E8940
#define __GetAnimationCache_x                                      0x6AEAF0
#define Teleport_Table_x                                           0xF1FC98
#define Teleport_Table_Size_x                                      0xF21F6C

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4233E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E040
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DE10

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D7EB0
#define AltAdvManager__IsAbilityReady_x                            0x4D7F20
#define AltAdvManager__GetAAById_x                                 0x4D8410
#define AltAdvManager__CanTrainAbility_x                           0x4D9040
#define AltAdvManager__CanSeeAbility_x                             0x4D8C00

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AF20
#define CharacterZoneClient__HasSkill_x                            0x466E30
#define CharacterZoneClient__MakeMeVisible_x                       0x46CA90
#define CharacterZoneClient__IsStackBlocked_x                      0x44BEF0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B410
#define CharacterZoneClient__GetItemCountWorn_x                    0x465390
#define CharacterZoneClient__GetItemCountInInventory_x             0x465470
#define CharacterZoneClient__GetCursorItemCount_x                  0x465550
#define CharacterZoneClient__FindAffectSlot_x                      0x451570
#define CharacterZoneClient__BardCastBard_x                        0x44AB80
#define CharacterZoneClient__GetMaxEffects_x                       0x449710
#define CharacterZoneClient__GetEffect_x                           0x44B640
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4513D0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449A60
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FF20

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x66EBD0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67CA90

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5983B0
#define CButtonWnd__CButtonWnd_x                                   0x8DCB90

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x697C60
#define CChatManager__InitContextMenu_x                            0x698DB0
#define CChatManager__FreeChatWindow_x                             0x697710
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A0F50
#define CChatManager__SetLockedActiveChatWindow_x                  0x697C30

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E6CA0
#define CContextMenu__dCContextMenu_x                              0x8E6EB0
#define CContextMenu__AddMenuItem_x                                0x8E73C0
#define CContextMenu__RemoveMenuItem_x                             0x8E7020
#define CContextMenu__RemoveAllMenuItems_x                         0x8E7040
#define CContextMenu__CheckMenuItem_x                              0x8E70C0
#define CContextMenu__SetMenuItem_x                                0x8E6F50

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D3100
#define CContextMenuManager__RemoveMenu_x                          0x8D34B0
#define CContextMenuManager__PopupMenu_x                           0x8D3900
#define CContextMenuManager__Flush_x                               0x8D3170
#define CContextMenuManager__GetMenu_x                             0x419510

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x886420
#define CChatService__GetFriendName_x                              0x886430

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x69EA20
#define CChatWindow__Clear_x                                       0x69E300
#define CChatWindow__WndNotification_x                             0x69F330

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D6F70
#define CComboWnd__Draw_x                                          0x8D7180
#define CComboWnd__GetCurChoice_x                                  0x8D6D20
#define CComboWnd__GetListRect_x                                   0x8D7420
#define CComboWnd__GetTextRect_x                                   0x8D6FE0
#define CComboWnd__InsertChoice_x                                  0x8D7580
#define CComboWnd__SetColors_x                                     0x8D6CB0
#define CComboWnd__SetChoice_x                                     0x8D6CE0
#define CComboWnd__GetItemCount_x                                  0x8D6D10
#define CComboWnd__GetCurChoiceText_x                              0x8D6D60

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A8C80
#define CContainerWnd__vftable_x                                   0xAEC9A8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C5E70
#define CDisplay__GetClickedActor_x                                0x4BE730
#define CDisplay__GetUserDefinedColor_x                            0x4BD310
#define CDisplay__GetWorldFilePath_x                               0x4BC760
#define CDisplay__is3dON_x                                         0x4BBBF0
#define CDisplay__ReloadUI_x                                       0x4CFC30
#define CDisplay__WriteTextHD2_x                                   0x4C2200
#define CDisplay__TrueDistance_x                                   0x4BF360

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FDDB0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EB1F0
#define CEditWnd__GetCharIndexPt_x                                 0x8EC330
#define CEditWnd__GetDisplayString_x                               0x8EB3A0
#define CEditWnd__GetHorzOffset_x                                  0x8EB6E0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EBE00
#define CEditWnd__GetSelStartPt_x                                  0x8EC5E0
#define CEditWnd__GetSTMLSafeText_x                                0x8EB870
#define CEditWnd__PointFromPrintableChar_x                         0x8EBEF0
#define CEditWnd__SelectableCharFromPoint_x                        0x8EC070
#define CEditWnd__SetEditable_x                                    0x8EB840

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x569830
#define CEverQuest__ClickedPlayer_x                                0x563400
#define CEverQuest__CreateTargetIndicator_x                        0x564300
#define CEverQuest__DeleteTargetIndicator_x                        0x564380
#define CEverQuest__DoTellWindow_x                                 0x476170
#define CEverQuest__OutputTextToLog_x                              0x475DD0
#define CEverQuest__DropHeldItemOnGround_x                         0x579DA0
#define CEverQuest__dsp_chat_x                                     0x4764B0
#define CEverQuest__trimName_x                                     0x55FD10
#define CEverQuest__Emote_x                                        0x5780B0
#define CEverQuest__EnterZone_x                                    0x573190
#define CEverQuest__GetBodyTypeDesc_x                              0x55D750
#define CEverQuest__GetClassDesc_x                                 0x566C40
#define CEverQuest__GetClassThreeLetterCode_x                      0x567240
#define CEverQuest__GetDeityDesc_x                                 0x55E030
#define CEverQuest__GetLangDesc_x                                  0x55DAE0
#define CEverQuest__GetRaceDesc_x                                  0x567400
#define CEverQuest__InterpretCmd_x                                 0x56AFB0
#define CEverQuest__LeftClickedOnPlayer_x                          0x57F950
#define CEverQuest__LMouseUp_x                                     0x581900
#define CEverQuest__RightClickedOnPlayer_x                         0x580460
#define CEverQuest__RMouseUp_x                                     0x581360
#define CEverQuest__SetGameState_x                                 0x563CD0
#define CEverQuest__UPCNotificationFlush_x                         0x55C0E0
#define CEverQuest__IssuePetCommand_x                              0x56B990
#define CEverQuest__ReportSuccessfulHit_x                          0x5748E0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B97A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B9800
#define CGaugeWnd__Draw_x                                          0x6B9C30

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B1A0
#define CGuild__GetGuildName_x                                     0x43B670
#define CGuild__GetGuildIndex_x                                    0x43C880

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D5C70

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E3000
#define CInvSlotMgr__MoveItem_x                                    0x6E37C0
#define CInvSlotMgr__SelectSlot_x                                  0x6E2900

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E1D60
#define CInvSlot__SliderComplete_x                                 0x6DF590
#define CInvSlot__GetItemBase_x                                    0x6DEA10
#define CInvSlot__UpdateItem_x                                     0x6DEF90

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E4BD0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E5D00

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7ADB90
#define CItemDisplayWnd__UpdateStrings_x                           0x6E6E20
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F36E0
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F3C00
#define CItemDisplayWnd__SetItem_x                                 0x6F94B0

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E4D60

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6ED3E0

// CLabel 
#define CLabel__Draw_x                                             0x7002B0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C2A40
#define CListWnd__dCListWnd_x                                      0x8C3CF0
#define CListWnd__AddColumn_x                                      0x8C3C90
#define CListWnd__AddColumn1_x                                     0x8C3320
#define CListWnd__AddLine_x                                        0x8C2D00
#define CListWnd__AddString_x                                      0x8C2F20
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BFB60
#define CListWnd__CalculateVSBRange_x                              0x8C1F00
#define CListWnd__ClearSel_x                                       0x8BEE80
#define CListWnd__ClearAllSel_x                                    0x8BEE30
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C28D0
#define CListWnd__Compare_x                                        0x8C0850
#define CListWnd__Draw_x                                           0x8C1B10
#define CListWnd__DrawColumnSeparators_x                           0x8C19A0
#define CListWnd__DrawHeader_x                                     0x8BF140
#define CListWnd__DrawItem_x                                       0x8C0EE0
#define CListWnd__DrawLine_x                                       0x8C1640
#define CListWnd__DrawSeparator_x                                  0x8C1A40
#define CListWnd__EnableLine_x                                     0x8BF060
#define CListWnd__EnsureVisible_x                                  0x8BFCC0
#define CListWnd__ExtendSel_x                                      0x8C0DF0
#define CListWnd__GetColumnMinWidth_x                              0x8BE770
#define CListWnd__GetColumnWidth_x                                 0x8BE6A0
#define CListWnd__GetCurSel_x                                      0x8BDE60
#define CListWnd__GetItemAtPoint_x                                 0x8BFF50
#define CListWnd__GetItemAtPoint1_x                                0x8BFFC0
#define CListWnd__GetItemData_x                                    0x8BE1B0
#define CListWnd__GetItemHeight_x                                  0x8BF7C0
#define CListWnd__GetItemIcon_x                                    0x8BE3A0
#define CListWnd__GetItemRect_x                                    0x8BFD90
#define CListWnd__GetItemText_x                                    0x8BE250
#define CListWnd__GetSelList_x                                     0x8C3210
#define CListWnd__GetSeparatorRect_x                               0x8C0770
#define CListWnd__InsertLine_x                                     0x8C3100
#define CListWnd__RemoveLine_x                                     0x8C3110
#define CListWnd__SetColors_x                                      0x8BDFB0
#define CListWnd__SetColumnJustification_x                         0x8BEA00
#define CListWnd__SetColumnWidth_x                                 0x8BE720
#define CListWnd__SetCurSel_x                                      0x8BDEA0
#define CListWnd__SetItemColor_x                                   0x8C25C0
#define CListWnd__SetItemData_x                                    0x8BEEE0
#define CListWnd__SetItemText_x                                    0x8C2400
#define CListWnd__ShiftColumnSeparator_x                           0x8C2290
#define CListWnd__Sort_x                                           0x8C3DF0
#define CListWnd__ToggleSel_x                                      0x8BEDB0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x719210

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73E960
#define CMerchantWnd__RequestBuyItem_x                             0x746500
#define CMerchantWnd__RequestSellItem_x                            0x748B70
#define CMerchantWnd__SelectRecoverySlot_x                         0x73BC20
#define CMerchantWnd__SelectBuySellSlot_x                          0x739AB0
#define CMerchantWnd__ActualSelect_x                               0x740740

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8547F0
#define CPacketScrambler__hton_x                                   0x854800

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E1B50
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1C30
#define CSidlManager__CreateLabel_x                                0x7A2B20
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E00F0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E1F10

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8D8FC0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8D8EB0
#define CSidlScreenWnd__ConvertToRes_x                             0x8FDC90
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D98D0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DAAC0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DAB70
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DA030
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D9280
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D89E0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D9470
#define CSidlScreenWnd__Init1_x                                    0x8DA790
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D9990
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8BA0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DA270
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D8640
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8990
#define CSidlScreenWnd__WndNotification_x                          0x8DA510
#define CSidlScreenWnd__GetChildItem_x                             0x8D8AB0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CC2D0
#define CSidlScreenWnd__m_layoutCopy_x                             0x172FE20

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x604980
#define CSkillMgr__GetSkillCap_x                                   0x604B60
#define CSkillMgr__GetNameToken_x                                  0x604530

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FCF40
#define CSliderWnd__SetValue_x                                     0x8FD110
#define CSliderWnd__SetNumTicks_x                                  0x8FD890

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A8E70

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6C50
#define CStmlWnd__CalculateHSBRange_x                              0x8EF1B0
#define CStmlWnd__CalculateVSBRange_x                              0x8EF120
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EF330
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EFB30
#define CStmlWnd__ForceParseNow_x                                  0x8F75D0
#define CStmlWnd__GetNextTagPiece_x                                0x8EFA30
#define CStmlWnd__GetSTMLText_x                                    0x484250
#define CStmlWnd__GetVisibleText_x                                 0x8F0580
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2B50
#define CStmlWnd__MakeStmlColorTag_x                               0x8EE400
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EE460
#define CStmlWnd__SetSTMLText_x                                    0x8F43B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F68F0
#define CStmlWnd__UpdateHistoryString_x                            0x8F14C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FAB00
#define CTabWnd__DrawCurrentPage_x                                 0x8FA390
#define CTabWnd__DrawTab_x                                         0x8FA160
#define CTabWnd__GetCurrentPage_x                                  0x8FA740
#define CTabWnd__GetPageInnerRect_x                                0x8F9E50
#define CTabWnd__GetTabInnerRect_x                                 0x8FA050
#define CTabWnd__GetTabRect_x                                      0x8F9F20
#define CTabWnd__InsertPage_x                                      0x8FADF0
#define CTabWnd__SetPage_x                                         0x8FA770
#define CTabWnd__SetPageRect_x                                     0x8FAA40
#define CTabWnd__UpdatePage_x                                      0x8FAD90
#define CTabWnd__GetPageFromTabIndex_x                             0x8FA0B0
#define CTabWnd__GetCurrentTabIndex_x                              0x8F9DE0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E5EB0
#define CPageWnd__SetTabText_x                                     0x906FE0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436D10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D6920
#define CTextureFont__GetTextExtent_x                              0x8D6680

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63D4D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x903420

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BC0C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402A30
#define CXStr__CXStr1_x                                            0x403800
#define CXStr__CXStr3_x                                            0x89F340
#define CXStr__dCXStr_x                                            0x8F80B0
#define CXStr__operator_equal_x                                    0x89F4B0
#define CXStr__operator_equal1_x                                   0x89F500
#define CXStr__operator_plus_equal1_x                              0x8A0600

// CXWnd 
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D4420
#define CXWnd__BringToTop_x                                        0x8CB4B0
#define CXWnd__Center_x                                            0x8D16D0
#define CXWnd__ClrFocus_x                                          0x8CB090
#define CXWnd__Destroy_x                                           0x8D21C0
#define CXWnd__DoAllDrawing_x                                      0x8D1320
#define CXWnd__DrawChildren_x                                      0x8D14C0
#define CXWnd__DrawColoredRect_x                                   0x8CB880
#define CXWnd__DrawTooltip_x                                       0x8CBB30
#define CXWnd__DrawTooltipAtPoint_x                                0x8D0280
#define CXWnd__GetBorderFrame_x                                    0x8CBFA0
#define CXWnd__GetChildWndAt_x                                     0x8D20A0
#define CXWnd__GetClientClipRect_x                                 0x8CBD50
#define CXWnd__GetScreenClipRect_x                                 0x8D0970
#define CXWnd__GetScreenRect_x                                     0x8CC170
#define CXWnd__GetTooltipRect_x                                    0x8CB9C0
#define CXWnd__GetWindowTextA_x                                    0x426E80
#define CXWnd__IsActive_x                                          0x8C6AC0
#define CXWnd__IsDescendantOf_x                                    0x8CBEE0
#define CXWnd__IsReallyVisible_x                                   0x8CF2B0
#define CXWnd__IsType_x                                            0x8D1740
#define CScreenPieceTemplate__IsType_x                             0x8FFB30
#define CXWnd__Move_x                                              0x8CE9C0
#define CXWnd__Move1_x                                             0x8D0FC0
#define CXWnd__ProcessTransition_x                                 0x8CB450
#define CXWnd__Refade_x                                            0x8CB230
#define CXWnd__Resize_x                                            0x8CC240
#define CXWnd__Right_x                                             0x8D0770
#define CXWnd__SetFocus_x                                          0x8CDB30
#define CXWnd__SetFont_x                                           0x8CB0E0
#define CXWnd__SetKeyTooltip_x                                     0x8CC4A0
#define CXWnd__SetMouseOver_x                                      0x8D0CC0
#define CXWnd__StartFade_x                                         0x8CB500
#define CXWnd__GetChildItem_x                                      0x8D0C00
#define CXWnd__SetParent_x                                         0x8D2050

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C8380
#define CXWndManager__DrawWindows_x                                0x8C7FC0
#define CXWndManager__GetKeyboardFlags_x                           0x8C6600
#define CXWndManager__HandleKeyboardMsg_x                          0x8C6F60
#define CXWndManager__RemoveWnd_x                                  0x8C6C50

// CDBStr
#define CDBStr__GetString_x                                        0x4BA460

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452630
#define EQ_Character__Cur_HP_x                                     0x466A10
#define EQ_Character__Cur_Mana_x                                   0x45B9F0
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B720
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4436E0
#define EQ_Character__GetFocusRangeModifier_x                      0x443830
#define EQ_Character__GetHPRegen_x                                 0x46A5B0
#define EQ_Character__GetEnduranceRegen_x                          0x466020
#define EQ_Character__GetManaRegen_x                               0x46AB50
#define EQ_Character__Max_Endurance_x                              0x5CB160
#define EQ_Character__Max_HP_x                                     0x45E570
#define EQ_Character__Max_Mana_x                                   0x5CAF90
#define EQ_Character__doCombatAbility_x                            0x5C8660
#define EQ_Character__UseSkill_x                                   0x472940
#define EQ_Character__GetConLevel_x                                0x5BDE30
#define EQ_Character__IsExpansionFlag_x                            0x4B6610
#define EQ_Character__TotalEffect_x                                0x44F860
#define EQ_Character__GetPCSpellAffect_x                           0x44BAB0
#define EQ_Character__SpellDuration_x                              0x449AB0
#define EQ_Character__FindItemByRecord_x                           0x464060
#define EQ_Character__GetAdjustedSkill_x                           0x466BE0
#define EQ_Character__GetBaseSkill_x                               0x45E450

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x872620

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D3870

//PcClient
#define PcClient__PcClient_x                                       0x5BFC80

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446BD0
#define CCharacterSelect__EnterWorld_x                             0x4463A0
#define CCharacterSelect__Quit_x                                   0x444F60

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59DCF0
#define EQ_Item__CreateItemTagString_x                             0x852980
#define EQ_Item__IsStackable_x                                     0x847CA0
#define EQ_Item__GetImageNum_x                                     0x84A7B0
#define EQ_Item__CreateItemClient_x                                0x59EE30
#define EQ_Item__GetItemValue_x                                    0x8513E0
#define EQ_Item__ValueSellMerchant_x                               0x854440
#define EQ_Item__IsKeyRingItem_x                                   0x848790
#define EQ_Item__CanGoInBag_x                                      0x59DE80
#define EQ_Item__GetMaxItemCount_x                                 0x847B90
#define EQ_Item__GetHeldItem_x                                     0x8495E0
#define EQ_Item__GetAugmentFitBySlot_x                             0x854270

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA450
#define EQ_LoadingS__Array_x                                       0xC0AC68

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CD680
#define EQ_PC__GetAlternateAbilityId_x                             0x85C860
#define EQ_PC__GetCombatAbility_x                                  0x85C8F0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8574A0
#define EQ_PC__GetItemRecastTimer_x                                0x5C6E50
#define EQ_PC__HasLoreItem_x                                       0x5C1440
#define EQ_PC__AlertInventoryChanged_x                             0x5BDDE0
#define EQ_PC__GetPcZoneClient_x                                   0x5E7DE0
#define EQ_PC__RemoveMyAffect_x                                    0x5C6280
#define EQ_PC__GetKeyRingItems_x                                   0x8578C0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86A5B0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x85E800

// EQItemList 
#define EQItemList__EQItemList_x                                   0x525EF0
#define EQItemList__add_object_x                                   0x553070
#define EQItemList__add_item_x                                     0x525E30
#define EQItemList__delete_item_x                                  0x5262E0
#define EQItemList__FreeItemList_x                                 0x5261E0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B9610

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D3530
#define EQPlayer__dEQPlayer_x                                      0x5DBCD0
#define EQPlayer__DoAttack_x                                       0x5ED580
#define EQPlayer__EQPlayer_x                                       0x5DE3F0
#define EQPlayer__SetNameSpriteState_x                             0x5D8B20
#define EQPlayer__SetNameSpriteTint_x                              0x5D4A30
#define PlayerBase__HasProperty_j_x                                0x930E50
#define EQPlayer__IsTargetable_x                                   0x9310F0
#define EQPlayer__CanSee_x                                         0x931650
#define PlayerZoneClient__ChangeHeight_x                           0x5ED440
#define EQPlayer__CanSee1_x                                        0x931740
#define PlayerBase__GetVisibilityLineSegment_x                     0x9313E0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E7F90
#define PlayerZoneClient__IsValidTeleport_x                        0x553910
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D2820

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E2420
#define EQPlayerManager__GetSpawnByName_x                          0x5E2880
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E2450

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A4400
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A4440
#define KeypressHandler__ClearCommandStateArray_x                  0x5A3FF0
#define KeypressHandler__HandleKeyDown_x                           0x5A2910
#define KeypressHandler__HandleKeyUp_x                             0x5A2C30
#define KeypressHandler__SaveKeymapping_x                          0x5A40C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x711BA0
#define MapViewMap__SaveEx_x                                       0x714ED0
#define MapViewMap__SetZoom_x                                      0x711820

#define PlayerPointManager__GetAltCurrency_x                       0x8706D0

// StringTable 
#define StringTable__getString_x                                   0x86A8E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CABF0
#define PcZoneClient__RemovePetEffect_x                            0x5C7320
#define PcZoneClient__HasAlternateAbility_x                        0x5C7CC0
#define PcZoneClient__GetCurrentMod_x                              0x45DA20
#define PcZoneClient__GetModCap_x                                  0x45B150
#define PcZoneClient__CanEquipItem_x                               0x5C81A0
#define PcZoneClient__GetItemByID_x                                0x5CCA00
#define PcZoneClient__GetItemByItemClass_x                         0x5CD5A0
#define PcZoneClient__RemoveBuffEffect_x                           0x5C6530

//Doors
#define EQSwitch__UseSwitch_x                                      0x55AA30

//IconCache
#define IconCache__GetIcon_x                                       0x6AF120

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A6010
#define CContainerMgr__CloseContainer_x                            0x6A6830

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x772AC0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x596DD0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4A00
#define EQ_Spell__SpellAffects_x                                   0x4F1BE0
#define EQ_Spell__SpellAffectBase_x                                0x4F1C50
#define CharacterZoneClient__CalcAffectChange_x                    0x44B940
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44ABE0
#define CLootWnd__LootAll_x                                        0x7074D0
#define CLootWnd__RequestLootSlot_x                                0x707CE0
#define EQ_Spell__IsStackable_x                                    0x459140
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449570
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EC30
#define EQ_Spell__IsSPAStacking_x                                  0x4F1750
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F27F0
#define EQ_Spell__IsNoRemove_x                                     0x434D50
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1770

#define __IsResEffectSpell_x                                       0x449600

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87C2D0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BA7A0
#define CTargetWnd__WndNotification_x                              0x7BA290
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BA980

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7BF8D0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED2D0
#define EqSoundManager__PlayScriptMp3_x                            0x4EED70

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8690

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EA820
#define CSidlManager__FindAnimation1_x                             0x8DFB20

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E1D10
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1CC0
#define CAltAbilityData__GetMaxRank_x                              0x4D6560

//CTargetRing
#define CTargetRing__Cast_x                                        0x594A20

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459450
#define CharacterBase__CreateItemGlobalIndex_x                     0x475370
#define CharacterBase__CreateItemIndex_x                           0x51F510
#define CharacterBase__GetItemPossession_x                         0x444400
#define CharacterBase__GetItemByGlobalIndex_x                      0x880110
#define CharacterBase__GetEffectId_x                               0x459410

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x68ED40
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68E4A0

//messages
#define msg_spell_worn_off_x                                       0x4FC4C0
#define msg_new_text_x                                             0x505C50
#define msgTokenTextParam_x                                        0x502450

//SpellManager
#define SpellManager__vftable_x                                    0xAC8268
#define SpellManager__SpellManager_x                               0x47DF20
#define Spellmanager__LoadTextSpells_x                             0x60B8A0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x935170

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487B10
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43EB40
#define ItemGlobalIndex__IsEquippedLocation_x                      0x4492C0
#define ItemGlobalIndex__IsValidIndex_x                            0x458C40

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87DF90
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87CED0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x700500

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AAD50
#define CCursorAttachment__Deactivate_x                            0x6AA290

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FC440
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FC5C0

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C360

//IString
#define IString__Append_x                                          0x47EB50

//Camera
#define CDisplay__cameraType_x                                     0xE6E7C8
#define EverQuest__Cameras_x                                       0xF30AC8
