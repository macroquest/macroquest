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
#define __ExpectedVersionDate                                     "Oct 13 2017"
#define __ExpectedVersionTime                                     "12:22:49"
#define __ActualVersionDate_x                                      0xAE7350
#define __ActualVersionTime_x                                      0xAE735C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5ABF90
#define __MemChecker1_x                                            0x8A4710
#define __MemChecker2_x                                            0x642070
#define __MemChecker3_x                                            0x641FC0
#define __MemChecker4_x                                            0x7F5F40
#define __EncryptPad0_x                                            0xC442B0
#define __EncryptPad1_x                                            0xD1FD68
#define __EncryptPad2_x                                            0xC6DCF0
#define __EncryptPad3_x                                            0xC6D8F0
#define __EncryptPad4_x                                            0xD0E368
#define __EncryptPad5_x                                            0x10C95A0
#define __AC1_x                                                    0x7B5285
#define __AC2_x                                                    0x564B87
#define __AC3_x                                                    0x562D00
#define __AC4_x                                                    0x574F21
#define __AC5_x                                                    0x588DCB
#define __AC6_x                                                    0x58C97E
#define __AC7_x                                                    0x5833CC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA4B90

// Direct Input
#define DI8__Main_x                                                0x10C9578
#define DI8__Keyboard_x                                            0x10C957C
#define DI8__Mouse_x                                               0x10C9580
#define DI8__Mouse_Copy_x                                          0xF376A4
#define DI8__Mouse_Check_x                                         0xFC1264
#define __AutoSkillArray_x                                         0xF385B8
#define __Attack_x                                                 0xFBBBBB
#define __Autofire_x                                               0xFBBBBC
#define __BindList_x                                               0xC1EDB0
#define g_eqCommandStates_x                                        0xF263F0
#define __Clicks_x                                                 0xF37760
#define __CommandList_x                                            0xC214B0
#define __CurrentMapLabel_x                                        0x10CF570
#define __CurrentSocial_x                                          0xBEE4E0
#define __DoAbilityList_x                                          0xF6DE70
#define __do_loot_x                                                0x5337A0
#define __DrawHandler_x                                            0x1736AF4
#define __GroupCount_x                                             0xF27CFA

#define __Guilds_x                                                 0xF2D910
#define __gWorld_x                                                 0xF2A1B4
#define __HotkeyPage_x                                             0xFB4870
#define __HWnd_x                                                   0xFC1380
#define __InChatMode_x                                             0xF3768C
#define __LastTell_x                                               0xF3956C
#define __LMouseHeldTime_x                                         0xF377CC
#define __Mouse_x                                                  0x10C9584
#define __MouseLook_x                                              0xF37726
#define __MouseEventTime_x                                         0xFBC444
#define __gpbCommandEvent_x                                        0xF2A27C
#define __NetStatusToggle_x                                        0xF37729
#define __PCNames_x                                                0xF38B7C
#define __RangeAttackReady_x                                       0xF3889C
#define __RMouseHeldTime_x                                         0xF377C8
#define __RunWalkState_x                                           0xF37690
#define __ScreenMode_x                                             0xE75FD0
#define __ScreenX_x                                                0xF37644
#define __ScreenY_x                                                0xF37640
#define __ScreenXMax_x                                             0xF37648
#define __ScreenYMax_x                                             0xF3764C
#define __ServerHost_x                                             0xF27C44
#define __ServerName_x                                             0xF6DE30
#define __ShiftKeyDown_x                                           0xF37D20
#define __ShowNames_x                                              0xF38A5C
#define __Socials_x                                                0xF6DF30
#define __SubscriptionType_x                                       0x10FD5FC
#define __TargetAggroHolder_x                                      0x10D17BC
#define __ZoneType_x                                               0xF37B24
#define __GroupAggro_x                                             0x10D17FC
#define __LoginName_x                                              0xFBFE5C
#define __Inviter_x                                                0xFBBB38
#define __AttackOnAssist_x                                         0xF38A18
#define __UseTellWindows_x                                         0xF38D14

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF2A2A0
#define instEQZoneInfo_x                                           0xF3791C
#define instKeypressHandler_x                                      0xFBC428
#define pinstActiveBanker_x                                        0xF2A258
#define pinstActiveCorpse_x                                        0xF2A25C
#define pinstActiveGMaster_x                                       0xF2A260
#define pinstActiveMerchant_x                                      0xF2A254
#define pinstAggroInfo_x                                           0xD33628
#define pinstAltAdvManager_x                                       0xE77138
#define pinstAuraMgr_x                                             0xD43E40
#define pinstBandageTarget_x                                       0xF2A240
#define pinstCamActor_x                                            0xE76A08
#define pinstCDBStr_x                                              0xE75F64
#define pinstCDisplay_x                                            0xF2A268
#define pinstCEverQuest_x                                          0x10C96F8
#define pinstEverQuestInfo_x                                       0xF37638
#define pinstCharData_x                                            0xF2A224
#define pinstCharSpawn_x                                           0xF2A24C
#define pinstControlledMissile_x                                   0xF2A220
#define pinstControlledPlayer_x                                    0xF2A24C
#define pinstCSidlManager_x                                        0x1735A60
#define pinstCXWndManager_x                                        0x1735A58
#define instDynamicZone_x                                          0xF374D8
#define pinstDZMember_x                                            0xF375E8
#define pinstDZTimerInfo_x                                         0xF375EC
#define pinstEQItemList_x                                          0xF266C8
#define pinstEQObjectList_x                                        0xF276F4
#define instEQMisc_x                                               0xC072B8
#define pinstEQSoundManager_x                                      0xE77708
#define instExpeditionLeader_x                                     0xF37522
#define instExpeditionName_x                                       0xF37562
#define pinstGroup_x                                               0xF27CF6
#define pinstImeManager_x                                          0x1735A64
#define pinstLocalPlayer_x                                         0xF2A238
#define pinstMercenaryData_x                                       0xFBCAA8
#define pinstMercenaryStats_x                                      0x10D1908
#define pinstMercAltAbilities_x                                    0xE774C0
#define pinstModelPlayer_x                                         0xF2A264
#define pinstPCData_x                                              0xF2A224
#define pinstSkillMgr_x                                            0xFBDB18
#define pinstSpawnManager_x                                        0xFBD2F8
#define pinstSpellManager_x                                        0xFBDC60
#define pinstSpellSets_x                                           0xFB48D4
#define pinstStringTable_x                                         0xF2A1CC
#define pinstSwitchManager_x                                       0xF27888
#define pinstTarget_x                                              0xF2A250
#define pinstTargetObject_x                                        0xF2A228
#define pinstTargetSwitch_x                                        0xF2A22C
#define pinstTaskMember_x                                          0xE75EB0
#define pinstTrackTarget_x                                         0xF2A244
#define pinstTradeTarget_x                                         0xF2A234
#define instTributeActive_x                                        0xC072DD
#define pinstViewActor_x                                           0xE76A04
#define pinstWorldData_x                                           0xF2A208
#define pinstZoneAddr_x                                            0xF37BBC
#define pinstPlayerPath_x                                          0xFBD358
#define pinstTargetIndicator_x                                     0xFBDDF8
#define pinstCTargetManager_x                                      0xFBDE58
#define EQObject_Top_x                                             0xF2A218
#define pinstRealEstateItems_x                                     0xFBD984

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE76920
#define pinstCAchievementsWnd_x                                    0xE7697C
#define pinstCTextOverlay_x                                        0xD33BD0
#define pinstCAudioTriggersWindow_x                                0xD339B8
#define pinstCCharacterSelect_x                                    0xE7688C
#define pinstCFacePick_x                                           0xE7663C
#define pinstCFindItemWnd_x                                        0xE7691C
#define pinstCNoteWnd_x                                            0xE76844
#define pinstCBookWnd_x                                            0xE7684C
#define pinstCPetInfoWnd_x                                         0xE76850
#define pinstCTrainWnd_x                                           0xE76854
#define pinstCSkillsWnd_x                                          0xE76858
#define pinstCSkillsSelectWnd_x                                    0xE7685C
#define pinstCCombatSkillsSelectWnd_x                              0xE76860
#define pinstCFriendsWnd_x                                         0xE76864
#define pinstCAuraWnd_x                                            0xE76868
#define pinstCRespawnWnd_x                                         0xE7686C
#define pinstCBandolierWnd_x                                       0xE76870
#define pinstCPotionBeltWnd_x                                      0xE76874
#define pinstCAAWnd_x                                              0xE76878
#define pinstCGroupSearchFiltersWnd_x                              0xE7687C
#define pinstCLoadskinWnd_x                                        0xE76880
#define pinstCAlarmWnd_x                                           0xE76884
#define pinstCMusicPlayerWnd_x                                     0xE76888
#define pinstCMailWnd_x                                            0xE76890
#define pinstCMailCompositionWnd_x                                 0xE76894
#define pinstCMailAddressBookWnd_x                                 0xE76898
#define pinstCRaidWnd_x                                            0xE768A0
#define pinstCRaidOptionsWnd_x                                     0xE768A4
#define pinstCBreathWnd_x                                          0xE768A8
#define pinstCMapViewWnd_x                                         0xE768AC
#define pinstCMapToolbarWnd_x                                      0xE768B0
#define pinstCEditLabelWnd_x                                       0xE768B4
#define pinstCTargetWnd_x                                          0xE768B8
#define pinstCColorPickerWnd_x                                     0xE768BC
#define pinstCPlayerWnd_x                                          0xE768C0
#define pinstCOptionsWnd_x                                         0xE768C4
#define pinstCBuffWindowNORMAL_x                                   0xE768C8
#define pinstCBuffWindowSHORT_x                                    0xE768CC
#define pinstCharacterCreation_x                                   0xE768D0
#define pinstCCursorAttachment_x                                   0xE768D4
#define pinstCCastingWnd_x                                         0xE768D8
#define pinstCCastSpellWnd_x                                       0xE768DC
#define pinstCSpellBookWnd_x                                       0xE768E0
#define pinstCInventoryWnd_x                                       0xE768E4
#define pinstCBankWnd_x                                            0xE768EC
#define pinstCQuantityWnd_x                                        0xE768F0
#define pinstCLootWnd_x                                            0xE768F4
#define pinstCActionsWnd_x                                         0xE768F8
#define pinstCCombatAbilityWnd_x                                   0xE76900
#define pinstCMerchantWnd_x                                        0xE76904
#define pinstCTradeWnd_x                                           0xE7690C
#define pinstCSelectorWnd_x                                        0xE76910
#define pinstCBazaarWnd_x                                          0xE76914
#define pinstCBazaarSearchWnd_x                                    0xE76918
#define pinstCGiveWnd_x                                            0xE76938
#define pinstCTrackingWnd_x                                        0xE76940
#define pinstCInspectWnd_x                                         0xE76944
#define pinstCSocialEditWnd_x                                      0xE76948
#define pinstCFeedbackWnd_x                                        0xE7694C
#define pinstCBugReportWnd_x                                       0xE76950
#define pinstCVideoModesWnd_x                                      0xE76954
#define pinstCTextEntryWnd_x                                       0xE7695C
#define pinstCFileSelectionWnd_x                                   0xE76960
#define pinstCCompassWnd_x                                         0xE76964
#define pinstCPlayerNotesWnd_x                                     0xE76968
#define pinstCGemsGameWnd_x                                        0xE7696C
#define pinstCTimeLeftWnd_x                                        0xE76988
#define pinstCPetitionQWnd_x                                       0xE7698C
#define pinstCStoryWnd_x                                           0xE76990
#define pinstCJournalTextWnd_x                                     0xE76994
#define pinstCJournalCatWnd_x                                      0xE76998
#define pinstCBodyTintWnd_x                                        0xE7699C
#define pinstCServerListWnd_x                                      0xE769A0
#define pinstCAvaZoneWnd_x                                         0xE769AC
#define pinstCBlockedBuffWnd_x                                     0xE769B0
#define pinstCBlockedPetBuffWnd_x                                  0xE769B4
#define pinstCInvSlotMgr_x                                         0xE769FC
#define pinstCContainerMgr_x                                       0xE76A00
#define pinstCAdventureLeaderboardWnd_x                            0x10CA0A8
#define pinstCAdventureRequestWnd_x                                0x10CA120
#define pinstCAltStorageWnd_x                                      0x10CA400
#define pinstCAdventureStatsWnd_x                                  0x10CA198
#define pinstCBarterMerchantWnd_x                                  0x10CB148
#define pinstCBarterSearchWnd_x                                    0x10CB1C0
#define pinstCBarterWnd_x                                          0x10CB238
#define pinstCChatWindowManager_x                                  0x10CBA48
#define pinstCDynamicZoneWnd_x                                     0x10CBF78
#define pinstCEQMainWnd_x                                          0x10CC140
#define pinstCFellowshipWnd_x                                      0x10CBF0C
#define pinstCFindLocationWnd_x                                    0x10CC410
#define pinstCGroupSearchWnd_x                                     0x10CC6E0
#define pinstCGroupWnd_x                                           0x10CC758
#define pinstCGuildBankWnd_x                                       0x10CC7D0
#define pinstCGuildMgmtWnd_x                                       0x10CE8C0
#define pinstCHotButtonWnd_x                                       0x10CE9BC
#define pinstCHotButtonWnd1_x                                      0x10CE9BC
#define pinstCHotButtonWnd2_x                                      0x10CE9C0
#define pinstCHotButtonWnd3_x                                      0x10CE9C4
#define pinstCHotButtonWnd4_x                                      0x10CE9E8
#define pinstCItemDisplayManager_x                                 0x10CEE40
#define pinstCItemExpTransferWnd_x                                 0x10CEF3C
#define pinstCLFGuildWnd_x                                         0x10CF218
#define pinstCMIZoneSelectWnd_x                                    0x10CF7F8
#define pinstCConfirmationDialog_x                                 0x10CFF00
#define pinstCPopupWndManager_x                                    0x10CFF00
#define pinstCProgressionSelectionWnd_x                            0x10CFFF0
#define pinstCPvPStatsWnd_x                                        0x10D00E0
#define pinstCLargeDialogWnd_x                                     0x10D0868
#define pinstCTaskWnd_x                                            0x10D1BE8
#define pinstCTaskSomething_x                                      0xD44A58
#define pinstCTaskTemplateSelectWnd_x                              0x10D1B70
#define pinstCTipWndOFDAY_x                                        0x10D1D50
#define pinstCTipWndCONTEXT_x                                      0x10D1D54
#define pinstCTitleWnd_x                                           0x10D1DD0
#define pinstCContextMenuManager_x                                 0x17358E8
#define pinstCVoiceMacroWnd_x                                      0xFBE230
#define pinstCHtmlWnd_x                                            0xFBE320
#define pinstItemIconCache_x                                       0x10CC0E8
#define pinstCTradeskillWnd_x                                      0x10D1ED0
#define pinstCAdvancedLootWnd_x                                    0xE769F0
#define pinstRewardSelectionWnd_x                                  0x10D0608
#define pinstEQSuiteTextureLoader_x                                0xD21C30
#define pinstCPointMerchantWnd_x                                   0x10CFE88

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x54B2B0
#define __CastRay2_x                                               0x54ABE0
#define __HeadingDiff_x                                            0x934730
#define __FixHeading_x                                             0x9346C0
#define __get_bearing_x                                            0x53A8F0
#define __ConvertItemTags_x                                        0x5383C0
#define __ExecuteCmd_x                                             0x522C90
#define __EQGetTime_x                                              0x8A40B0
#define __get_melee_range_x                                        0x529940
#define __GetGaugeValueFromEQ_x                                    0x7B3E40
#define __GetLabelFromEQ_x                                         0x7B5210
#define __ToggleKeyRingItem_x                                      0x490C80
#define __GetXTargetType_x                                         0x936330
#define __LoadFrontEnd_x                                           0x641740
#define __NewUIINI_x                                               0x7B3810
#define __ProcessGameEvents_x                                      0x585160
#define __ProcessMouseEvent_x                                      0x584900
#define CrashDetected_x                                            0x643100
#define wwsCrashReportCheckForUploader_x                           0x801DC0
#define __AppCrashWrapper_x                                        0xC6D8E4
#define __pCrashHandler_x                                          0x10DEDB0
#define __CrashHandler_x                                           0x801850
#define wwsCrashReportPlatformLaunchUploader_x                     0x803FF0
#define DrawNetStatus_x                                            0x5BBB00
#define Util__FastTime_x                                           0x8A3D50
#define Expansion_HoT_x                                            0xF38A08
#define __HelpPath_x                                               0xFBC1B0
#define __STMLToText_x                                             0x8EA3C0
#define __GetAnimationCache_x                                      0x6B0DA0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4234A0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41E150
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DF20

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D9200
#define AltAdvManager__IsAbilityReady_x                            0x4D9270
#define AltAdvManager__GetAAById_x                                 0x4D9760
#define AltAdvManager__CanTrainAbility_x                           0x4DA390
#define AltAdvManager__CanSeeAbility_x                             0x4D9F50

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x46AB60
#define CharacterZoneClient__HasSkill_x                            0x466430
#define CharacterZoneClient__MakeMeVisible_x                       0x46C6D0
#define CharacterZoneClient__IsStackBlocked_x                      0x44C040
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B500
#define CharacterZoneClient__GetItemCountWorn_x                    0x464990
#define CharacterZoneClient__GetItemCountInInventory_x             0x464A70
#define CharacterZoneClient__GetCursorItemCount_x                  0x464B50
#define CharacterZoneClient__FindAffectSlot_x                      0x451630
#define CharacterZoneClient__BardCastBard_x                        0x44AC80
#define CharacterZoneClient__GetMaxEffects_x                       0x449810
#define CharacterZoneClient__GetEffect_x                           0x44B730
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x451490
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449B60
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FFE0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x671060

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67EFF0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x59AAA0
#define CButtonWnd__CButtonWnd_x                                   0x8DE620

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x699FD0
#define CChatManager__InitContextMenu_x                            0x69B120
#define CChatManager__FreeChatWindow_x                             0x699A80
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A3240
#define CChatManager__SetLockedActiveChatWindow_x                  0x699FA0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E8710
#define CContextMenu__dCContextMenu_x                              0x8E8920
#define CContextMenu__AddMenuItem_x                                0x8E8E40
#define CContextMenu__RemoveMenuItem_x                             0x8E8AA0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E8AC0
#define CContextMenu__CheckMenuItem_x                              0x8E8B40

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D4BF0
#define CContextMenuManager__RemoveMenu_x                          0x8D4F80
#define CContextMenuManager__PopupMenu_x                           0x8D53D0
#define CContextMenuManager__Flush_x                               0x8D4C60
#define CContextMenuManager__GetMenu_x                             0x4196C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x888210
#define CChatService__GetFriendName_x                              0x888220

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6A0D30
#define CChatWindow__Clear_x                                       0x6A0620
#define CChatWindow__WndNotification_x                             0x6A1630

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D8A40
#define CComboWnd__Draw_x                                          0x8D8C50
#define CComboWnd__GetCurChoice_x                                  0x8D87F0
#define CComboWnd__GetListRect_x                                   0x8D8EF0
#define CComboWnd__GetTextRect_x                                   0x8D8AB0
#define CComboWnd__InsertChoice_x                                  0x8D9050
#define CComboWnd__SetColors_x                                     0x8D8780
#define CComboWnd__SetChoice_x                                     0x8D87B0
#define CComboWnd__GetItemCount_x                                  0x8D87E0
#define CComboWnd__GetCurChoiceText_x                              0x8D8830

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AAF20
#define CContainerWnd__vftable_x                                   0xAF0C60

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C6E50
#define CDisplay__GetClickedActor_x                                0x4BF710
#define CDisplay__GetUserDefinedColor_x                            0x4BE2F0
#define CDisplay__GetWorldFilePath_x                               0x4BD740
#define CDisplay__is3dON_x                                         0x4BCBD0
#define CDisplay__ReloadUI_x                                       0x4D0E30
#define CDisplay__WriteTextHD2_x                                   0x4C31E0
#define CDisplay__TrueDistance_x                                   0x4C0340

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FFA70

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8ECC70
#define CEditWnd__GetCharIndexPt_x                                 0x8EDDD0
#define CEditWnd__GetDisplayString_x                               0x8ECE20
#define CEditWnd__GetHorzOffset_x                                  0x8ED160
#define CEditWnd__GetLineForPrintableChar_x                        0x8ED890
#define CEditWnd__GetSelStartPt_x                                  0x8EE090
#define CEditWnd__GetSTMLSafeText_x                                0x8ED300
#define CEditWnd__PointFromPrintableChar_x                         0x8ED980
#define CEditWnd__SelectableCharFromPoint_x                        0x8EDB00
#define CEditWnd__SetEditable_x                                    0x8ED2D0

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56B750
#define CEverQuest__ClickedPlayer_x                                0x5652D0
#define CEverQuest__CreateTargetIndicator_x                        0x5661D0
#define CEverQuest__DeleteTargetIndicator_x                        0x566250
#define CEverQuest__DoTellWindow_x                                 0x477330
#define CEverQuest__OutputTextToLog_x                              0x476F90
#define CEverQuest__DropHeldItemOnGround_x                         0x57BCC0
#define CEverQuest__dsp_chat_x                                     0x477670
#define CEverQuest__trimName_x                                     0x561BE0
#define CEverQuest__Emote_x                                        0x579FD0
#define CEverQuest__EnterZone_x                                    0x5750B0
#define CEverQuest__GetBodyTypeDesc_x                              0x55F620
#define CEverQuest__GetClassDesc_x                                 0x568B70
#define CEverQuest__GetClassThreeLetterCode_x                      0x569170
#define CEverQuest__GetDeityDesc_x                                 0x55FF00
#define CEverQuest__GetLangDesc_x                                  0x55F9B0
#define CEverQuest__GetRaceDesc_x                                  0x569330
#define CEverQuest__InterpretCmd_x                                 0x56CED0
#define CEverQuest__LeftClickedOnPlayer_x                          0x581810
#define CEverQuest__LMouseUp_x                                     0x583920
#define CEverQuest__RightClickedOnPlayer_x                         0x582320
#define CEverQuest__RMouseUp_x                                     0x583380
#define CEverQuest__SetGameState_x                                 0x565BA0
#define CEverQuest__UPCNotificationFlush_x                         0x55DFB0
#define CEverQuest__IssuePetCommand_x                              0x56D8B0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BBC00
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BBC60
#define CGaugeWnd__Draw_x                                          0x6BC090

// CGuild
#define CGuild__FindMemberByName_x                                 0x43B720
#define CGuild__GetGuildName_x                                     0x43BBF0
#define CGuild__GetGuildIndex_x                                    0x43CE00

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D80B0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E54E0
#define CInvSlotMgr__MoveItem_x                                    0x6E5CA0
#define CInvSlotMgr__SelectSlot_x                                  0x6E4DD0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E4230
#define CInvSlot__SliderComplete_x                                 0x6E19B0
#define CInvSlot__GetItemBase_x                                    0x6E0E50
#define CInvSlot__UpdateItem_x                                     0x6E13D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E70D0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E8210

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AF840
#define CItemDisplayWnd__UpdateStrings_x                           0x6E9310
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F5F50
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F6470
#define CItemDisplayWnd__SetItem_x                                 0x6FBD10

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E6EB0

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EF8F0

// CLabel 
#define CLabel__Draw_x                                             0x702AB0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C4700
#define CListWnd__dCListWnd_x                                      0x8C59B0
#define CListWnd__AddColumn_x                                      0x8C5950
#define CListWnd__AddColumn1_x                                     0x8C4FF0
#define CListWnd__AddLine_x                                        0x8C49D0
#define CListWnd__AddString_x                                      0x8C4BF0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C1820
#define CListWnd__CalculateVSBRange_x                              0x8C3BD0
#define CListWnd__ClearSel_x                                       0x8C0B30
#define CListWnd__ClearAllSel_x                                    0x8C0AE0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C4590
#define CListWnd__Compare_x                                        0x8C2500
#define CListWnd__Draw_x                                           0x8C37D0
#define CListWnd__DrawColumnSeparators_x                           0x8C3660
#define CListWnd__DrawHeader_x                                     0x8C0DF0
#define CListWnd__DrawItem_x                                       0x8C2B90
#define CListWnd__DrawLine_x                                       0x8C3300
#define CListWnd__DrawSeparator_x                                  0x8C3700
#define CListWnd__EnableLine_x                                     0x8C0D10
#define CListWnd__EnsureVisible_x                                  0x8C1980
#define CListWnd__ExtendSel_x                                      0x8C2AA0
#define CListWnd__GetColumnMinWidth_x                              0x8C0420
#define CListWnd__GetColumnWidth_x                                 0x8C0350
#define CListWnd__GetCurSel_x                                      0x8BFB20
#define CListWnd__GetItemAtPoint_x                                 0x8C1C20
#define CListWnd__GetItemAtPoint1_x                                0x8C1C90
#define CListWnd__GetItemData_x                                    0x8BFE60
#define CListWnd__GetItemHeight_x                                  0x8C1470
#define CListWnd__GetItemIcon_x                                    0x8C0050
#define CListWnd__GetItemRect_x                                    0x8C1A60
#define CListWnd__GetItemText_x                                    0x8BFF00
#define CListWnd__GetSelList_x                                     0x8C4EE0
#define CListWnd__GetSeparatorRect_x                               0x8C2420
#define CListWnd__InsertLine_x                                     0x8C4DD0
#define CListWnd__RemoveLine_x                                     0x8C4DE0
#define CListWnd__SetColors_x                                      0x8BFC70
#define CListWnd__SetColumnJustification_x                         0x8C06B0
#define CListWnd__SetColumnWidth_x                                 0x8C03D0
#define CListWnd__SetCurSel_x                                      0x8BFB60
#define CListWnd__SetItemColor_x                                   0x8C4280
#define CListWnd__SetItemData_x                                    0x8C0B90
#define CListWnd__SetItemText_x                                    0x8C40C0
#define CListWnd__ShiftColumnSeparator_x                           0x8C3F50
#define CListWnd__Sort_x                                           0x8C5AB0
#define CListWnd__ToggleSel_x                                      0x8C0A60

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71BB30

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73D080
#define CMerchantWnd__RequestBuyItem_x                             0x744190
#define CMerchantWnd__RequestSellItem_x                            0x744C60
#define CMerchantWnd__SelectRecoverySlot_x                         0x73D330
#define CMerchantWnd__SelectBuySellSlot_x                          0x73C530
#define CMerchantWnd__ActualSelect_x                               0x741040

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x856410
#define CPacketScrambler__hton_x                                   0x856420

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E35F0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E36D0
#define CSidlManager__CreateLabel_x                                0x7A5830
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E1B90
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E39B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8DAA90
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8DA990
#define CSidlScreenWnd__ConvertToRes_x                             0x8FF950
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8DB3A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DC550
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DC600
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DBAE0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8DAD50
#define CSidlScreenWnd__EnableIniStorage_x                         0x8DA4C0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8DAF40
#define CSidlScreenWnd__Init1_x                                    0x8DC230
#define CSidlScreenWnd__LoadIniInfo_x                              0x8DB450
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8DA680
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DBD20
#define CSidlScreenWnd__StoreIniInfo_x                             0x8DA120
#define CSidlScreenWnd__StoreIniVis_x                              0x8DA470
#define CSidlScreenWnd__WndNotification_x                          0x8DBFB0
#define CSidlScreenWnd__GetChildItem_x                             0x8DA590
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CDE70
#define CSidlScreenWnd__m_layoutCopy_x                             0x1735A08

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x606FF0
#define CSkillMgr__GetSkillCap_x                                   0x6071D0
#define CSkillMgr__GetNameToken_x                                  0x606BA0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FEC10
#define CSliderWnd__SetValue_x                                     0x8FEDE0
#define CSliderWnd__SetNumTicks_x                                  0x8FF560

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7ABB20

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F8720
#define CStmlWnd__CalculateHSBRange_x                              0x8F0C70
#define CStmlWnd__CalculateVSBRange_x                              0x8F0BE0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F0DF0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F15F0
#define CStmlWnd__ForceParseNow_x                                  0x8F90A0
#define CStmlWnd__GetNextTagPiece_x                                0x8F14F0
#define CStmlWnd__GetSTMLText_x                                    0x485530
#define CStmlWnd__GetVisibleText_x                                 0x8F2040
#define CStmlWnd__InitializeWindowVariables_x                      0x8F4610
#define CStmlWnd__MakeStmlColorTag_x                               0x8EFEC0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EFF20
#define CStmlWnd__SetSTMLText_x                                    0x8F5E60
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F83C0
#define CStmlWnd__UpdateHistoryString_x                            0x8F2F80

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FC5F0
#define CTabWnd__DrawCurrentPage_x                                 0x8FBE80
#define CTabWnd__DrawTab_x                                         0x8FBC40
#define CTabWnd__GetCurrentPage_x                                  0x8FC230
#define CTabWnd__GetPageInnerRect_x                                0x8FB930
#define CTabWnd__GetTabInnerRect_x                                 0x8FBB30
#define CTabWnd__GetTabRect_x                                      0x8FBA00
#define CTabWnd__InsertPage_x                                      0x8FC8E0
#define CTabWnd__SetPage_x                                         0x8FC260
#define CTabWnd__SetPageRect_x                                     0x8FC530
#define CTabWnd__UpdatePage_x                                      0x8FC880
#define CTabWnd__GetPageFromTabIndex_x                             0x8FBB90
#define CTabWnd__GetCurrentTabIndex_x                              0x8FB8C0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E83C0
#define CPageWnd__SetTabText_x                                     0x908D20

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x437320

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D83F0
#define CTextureFont__GetTextExtent_x                              0x8D8150

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63F9D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x905110

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BDC30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402A20
#define CXStr__CXStr1_x                                            0x7EF0A0
#define CXStr__CXStr3_x                                            0x8A0FA0
#define CXStr__dCXStr_x                                            0x6BBAE0
#define CXStr__operator_equal_x                                    0x8A1110
#define CXStr__operator_equal1_x                                   0x8A1160
#define CXStr__operator_plus_equal1_x                              0x8A2260

// CXWnd 
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D5EE0
#define CXWnd__BringToTop_x                                        0x8CD060
#define CXWnd__Center_x                                            0x8D3200
#define CXWnd__ClrFocus_x                                          0x8CCC20
#define CXWnd__Destroy_x                                           0x8D3CD0
#define CXWnd__DoAllDrawing_x                                      0x8D2E50
#define CXWnd__DrawChildren_x                                      0x8D2FF0
#define CXWnd__DrawColoredRect_x                                   0x8CD450
#define CXWnd__DrawTooltip_x                                       0x8CD700
#define CXWnd__DrawTooltipAtPoint_x                                0x8D1DD0
#define CXWnd__GetBorderFrame_x                                    0x8CDB60
#define CXWnd__GetChildWndAt_x                                     0x8D3BC0
#define CXWnd__GetClientClipRect_x                                 0x8CD920
#define CXWnd__GetScreenClipRect_x                                 0x8D24D0
#define CXWnd__GetScreenRect_x                                     0x8CDD10
#define CXWnd__GetTooltipRect_x                                    0x8CD590
#define CXWnd__GetWindowTextA_x                                    0x4274F0
#define CXWnd__IsActive_x                                          0x8C8720
#define CXWnd__IsDescendantOf_x                                    0x8CDAB0
#define CXWnd__IsReallyVisible_x                                   0x8D0DF0
#define CXWnd__IsType_x                                            0x8D3270
#define CScreenPieceTemplate__IsType_x                             0x901820
#define CXWnd__Move_x                                              0x8D0530
#define CXWnd__Move1_x                                             0x8D2B10
#define CXWnd__ProcessTransition_x                                 0x8CD000
#define CXWnd__Refade_x                                            0x8CCDD0
#define CXWnd__Resize_x                                            0x8CDDD0
#define CXWnd__Right_x                                             0x8D22D0
#define CXWnd__SetFocus_x                                          0x8CF6A0
#define CXWnd__SetFont_x                                           0x8CCC70
#define CXWnd__SetKeyTooltip_x                                     0x8CE040
#define CXWnd__SetMouseOver_x                                      0x8D2800
#define CXWnd__StartFade_x                                         0x8CD0B0
#define CXWnd__GetChildItem_x                                      0x8D2750
#define CXWnd__SetParent_x                                         0x8D3B70

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C9FE0
#define CXWndManager__DrawWindows_x                                0x8C9C20
#define CXWndManager__GetKeyboardFlags_x                           0x8C8290
#define CXWndManager__HandleKeyboardMsg_x                          0x8C8BC0
#define CXWndManager__RemoveWnd_x                                  0x8C88B0

// CDBStr
#define CDBStr__GetString_x                                        0x4BB3F0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x4527F0
#define EQ_Character__Cur_HP_x                                     0x466010
#define EQ_Character__Cur_Mana_x                                   0x45AF30
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B810
#define EQ_Character__GetFocusCastingTimeModifier_x                0x4439B0
#define EQ_Character__GetFocusRangeModifier_x                      0x443A10
#define EQ_Character__GetHPRegen_x                                 0x46A1F0
#define EQ_Character__GetEnduranceRegen_x                          0x465620
#define EQ_Character__GetManaRegen_x                               0x46A790
#define EQ_Character__Max_Endurance_x                              0x5CD6A0
#define EQ_Character__Max_HP_x                                     0x45DAB0
#define EQ_Character__Max_Mana_x                                   0x5CD4D0
#define EQ_Character__doCombatAbility_x                            0x5CABA0
#define EQ_Character__UseSkill_x                                   0x471760
#define EQ_Character__GetConLevel_x                                0x5C0130
#define EQ_Character__IsExpansionFlag_x                            0x426A20
#define EQ_Character__TotalEffect_x                                0x44F920
#define EQ_Character__GetPCSpellAffect_x                           0x44BC10
#define EQ_Character__SpellDuration_x                              0x449BB0
#define EQ_Character__FindItemByRecord_x                           0x463660
#define EQ_Character__GetAdjustedSkill_x                           0x4661E0
#define EQ_Character__GetBaseSkill_x                               0x45D990

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x874420

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D5C40

//PcClient
#define PcClient__PcClient_x                                       0x5C1F70

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446CA0
#define CCharacterSelect__EnterWorld_x                             0x446470
#define CCharacterSelect__Quit_x                                   0x445030

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5A04C0
#define EQ_Item__CreateItemTagString_x                             0x8545B0
#define EQ_Item__IsStackable_x                                     0x849B40
#define EQ_Item__GetImageNum_x                                     0x84C5D0
#define EQ_Item__CreateItemClient_x                                0x5A10B0
#define EQ_Item__GetItemValue_x                                    0x853050
#define EQ_Item__ValueSellMerchant_x                               0x856060
#define EQ_Item__IsKeyRingItem_x                                   0x84A600
#define EQ_Item__CanGoInBag_x                                      0x5A0650
#define EQ_Item__GetMaxItemCount_x                                 0x849A30
#define EQ_Item__GetHeldItem_x                                     0x84B410
#define EQ_Item__GetAugmentFitBySlot_x                             0x855E90

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DB800
#define EQ_LoadingS__Array_x                                       0xC0F738

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CFBC0
#define EQ_PC__GetAlternateAbilityId_x                             0x85E5A0
#define EQ_PC__GetCombatAbility_x                                  0x85E630
#define EQ_PC__GetCombatAbilityTimer_x                             0x8590C0
#define EQ_PC__GetItemRecastTimer_x                                0x5C9350
#define EQ_PC__HasLoreItem_x                                       0x5C3730
#define EQ_PC__AlertInventoryChanged_x                             0x5C00E0
#define EQ_PC__GetPcZoneClient_x                                   0x5EA150
#define EQ_PC__RemoveMyAffect_x                                    0x5C87B0
#define EQ_PC__GetKeyRingItems_x                                   0x8594E0
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86C330
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8605A0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5279E0
#define EQItemList__add_object_x                                   0x554EB0
#define EQItemList__add_item_x                                     0x527920
#define EQItemList__delete_item_x                                  0x527DD0
#define EQItemList__FreeItemList_x                                 0x527CD0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4BA700

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D59E0
#define EQPlayer__dEQPlayer_x                                      0x5DE020
#define EQPlayer__DoAttack_x                                       0x5EFAD0
#define EQPlayer__EQPlayer_x                                       0x5E0740
#define EQPlayer__SetNameSpriteState_x                             0x5DAEE0
#define EQPlayer__SetNameSpriteTint_x                              0x5D6E00
#define PlayerBase__HasProperty_j_x                                0x932B20
#define EQPlayer__IsTargetable_x                                   0x932DC0
#define EQPlayer__CanSee_x                                         0x933320
#define PlayerZoneClient__ChangeHeight_x                           0x5EF990
#define EQPlayer__CanSee1_x                                        0x933410
#define PlayerBase__GetVisibilityLineSegment_x                     0x9330B0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5EA300
#define PlayerZoneClient__IsValidTeleport_x                        0x555750
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D3A20

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E4790
#define EQPlayerManager__GetSpawnByName_x                          0x5E4BF0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E47C0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A6770
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A67B0
#define KeypressHandler__ClearCommandStateArray_x                  0x5A6360
#define KeypressHandler__HandleKeyDown_x                           0x5A4CB0
#define KeypressHandler__HandleKeyUp_x                             0x5A4FD0
#define KeypressHandler__SaveKeymapping_x                          0x5A6430

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7144C0
#define MapViewMap__SaveEx_x                                       0x7177F0

#define PlayerPointManager__GetAltCurrency_x                       0x8724E0

// StringTable 
#define StringTable__getString_x                                   0x86C660

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CD130
#define PcZoneClient__RemovePetEffect_x                            0x5C9820
#define PcZoneClient__HasAlternateAbility_x                        0x5CA1C0
#define PcZoneClient__GetCurrentMod_x                              0x45CF60
#define PcZoneClient__GetModCap_x                                  0x45A690
#define PcZoneClient__CanEquipItem_x                               0x5CA6E0
#define PcZoneClient__GetItemByID_x                                0x5CEF30
#define PcZoneClient__GetItemByItemClass_x                         0x5CFAE0
#define PcZoneClient__RemoveBuffEffect_x                           0x5C8A60

//Doors
#define EQSwitch__UseSwitch_x                                      0x55C870

//IconCache
#define IconCache__GetIcon_x                                       0x6B13D0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A82C0
#define CContainerMgr__CloseContainer_x                            0x6A8AE0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7757E0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5994D0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F5DB0
#define EQ_Spell__SpellAffects_x                                   0x4F2FD0
#define EQ_Spell__SpellAffectBase_x                                0x4F3040
#define CharacterZoneClient__CalcAffectChange_x                    0x44BAA0
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44ACE0
#define CLootWnd__LootAll_x                                        0x709CE0
#define CLootWnd__RequestLootSlot_x                                0x70A4F0
#define EQ_Spell__IsStackable_x                                    0x4495D0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449680
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43F1B0
#define EQ_Spell__IsSPAStacking_x                                  0x4F2B40
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F3BB0
#define EQ_Spell__IsNoRemove_x                                     0x435360
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F2B60

#define __IsResEffectSpell_x                                       0x449700

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87E090

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BC8F0
#define CTargetWnd__WndNotification_x                              0x7BC3E0
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BCAD0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C1A10

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4EE700
#define EqSoundManager__PlayScriptMp3_x                            0x4F01A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A97F0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EC2A0
#define CSidlManager__FindAnimation1_x                             0x8E15C0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E3060
#define CAltAbilityData__GetMercMaxRank_x                          0x4E3010
#define CAltAbilityData__GetMaxRank_x                              0x4D78B0

//CTargetRing
#define CTargetRing__Cast_x                                        0x596D90

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459630
#define CharacterBase__CreateItemGlobalIndex_x                     0x4764E0
#define CharacterBase__CreateItemIndex_x                           0x521040
#define CharacterBase__GetItemPossession_x                         0x444530
#define CharacterBase__GetItemByGlobalIndex_x                      0x881EE0
#define CharacterBase__GetEffectId_x                               0x4595F0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x6911F0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x690950

//messages
#define msg_spell_worn_off_x                                       0x4FD940
#define msg_new_text_x                                             0x506FF0
#define msgTokenTextParam_x                                        0x5037D0

//SpellManager
#define SpellManager__vftable_x                                    0xACC400
#define SpellManager__SpellManager_x                               0x47F180
#define Spellmanager__LoadTextSpells_x                             0x60DF00

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x936E50

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x488C10
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43F0D0
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449390
#define ItemGlobalIndex__IsValidIndex_x                            0x458E80

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87FD50
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87EC90

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x702D00

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6ACFF0
#define CCursorAttachment__Deactivate_x                            0x6AC540

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FE110
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FE290

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48D4A0
