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
#define __ExpectedVersionDate                                     "Nov  7 2017"
#define __ExpectedVersionTime                                     "14:07:25"
#define __ActualVersionDate_x                                      0xAE5078
#define __ActualVersionTime_x                                      0xAE5084

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x5AB2B0
#define __MemChecker1_x                                            0x8A4600
#define __MemChecker2_x                                            0x641150
#define __MemChecker3_x                                            0x6410A0
#define __MemChecker4_x                                            0x7F6490
#define __EncryptPad0_x                                            0xC3FC10
#define __EncryptPad1_x                                            0xD19050
#define __EncryptPad2_x                                            0xC68978
#define __EncryptPad3_x                                            0xC68578
#define __EncryptPad4_x                                            0xD07650
#define __EncryptPad5_x                                            0x10C2668
#define __AC1_x                                                    0x7B4F65
#define __AC2_x                                                    0x5645F7
#define __AC3_x                                                    0x562770
#define __AC4_x                                                    0x574931
#define __AC5_x                                                    0x58868B
#define __AC6_x                                                    0x58C23E
#define __AC7_x                                                    0x582C8C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FA5610

// Direct Input
#define DI8__Main_x                                                0x10C2640
#define DI8__Keyboard_x                                            0x10C2644
#define DI8__Mouse_x                                               0x10C2648
#define DI8__Mouse_Copy_x                                          0xF308F4
#define DI8__Mouse_Check_x                                         0xFBA32C
#define __AutoSkillArray_x                                         0xF31808
#define __Attack_x                                                 0xFB4E03
#define __Autofire_x                                               0xFB4E04
#define __BindList_x                                               0xC1C0C8
#define g_eqCommandStates_x                                        0xF1F640
#define __Clicks_x                                                 0xF309B0
#define __CommandList_x                                            0xC1E7C8
#define __CurrentMapLabel_x                                        0x10C8638
#define __CurrentSocial_x                                          0xBEB800
#define __DoAbilityList_x                                          0xF670B8
#define __do_loot_x                                                0x533360
#define __DrawHandler_x                                            0x172FACC
#define __GroupCount_x                                             0xF20F4A

#define __Guilds_x                                                 0xF26B60
#define __gWorld_x                                                 0xF23404
#define __HotkeyPage_x                                             0xFADAB8
#define __HWnd_x                                                   0xFBA448
#define __InChatMode_x                                             0xF308DC
#define __LastTell_x                                               0xF327B4
#define __LMouseHeldTime_x                                         0xF30A1C
#define __Mouse_x                                                  0x10C264C
#define __MouseLook_x                                              0xF30976
#define __MouseEventTime_x                                         0xFB559C
#define __gpbCommandEvent_x                                        0xF234CC
#define __NetStatusToggle_x                                        0xF30979
#define __PCNames_x                                                0xF31DC4
#define __RangeAttackReady_x                                       0xF31AEC
#define __RMouseHeldTime_x                                         0xF30A18
#define __RunWalkState_x                                           0xF308E0
#define __ScreenMode_x                                             0xE6F220
#define __ScreenX_x                                                0xF30894
#define __ScreenY_x                                                0xF30890
#define __ScreenXMax_x                                             0xF30898
#define __ScreenYMax_x                                             0xF3089C
#define __ServerHost_x                                             0xF20E94
#define __ServerName_x                                             0xF67078
#define __ShiftKeyDown_x                                           0xF30F70
#define __ShowNames_x                                              0xF31CA4
#define __Socials_x                                                0xF67178
#define __SubscriptionType_x                                       0x10F65D4
#define __TargetAggroHolder_x                                      0x10CA794
#define __ZoneType_x                                               0xF30D74
#define __GroupAggro_x                                             0x10CA7D4
#define __LoginName_x                                              0xFB8F24
#define __Inviter_x                                                0xFB4D80
#define __AttackOnAssist_x                                         0xF31C60
#define __UseTellWindows_x                                         0xF31F5C

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF234F0
#define instEQZoneInfo_x                                           0xF30B6C
#define instKeypressHandler_x                                      0xFB5580
#define pinstActiveBanker_x                                        0xF234A8
#define pinstActiveCorpse_x                                        0xF234AC
#define pinstActiveGMaster_x                                       0xF234B0
#define pinstActiveMerchant_x                                      0xF234A4
#define pinstAggroInfo_x                                           0xD2C88C
#define pinstAltAdvManager_x                                       0xE70388
#define pinstAuraMgr_x                                             0xD3D090
#define pinstBandageTarget_x                                       0xF23490
#define pinstCamActor_x                                            0xE6FC58
#define pinstCDBStr_x                                              0xE6F1B4
#define pinstCDisplay_x                                            0xF234B8
#define pinstCEverQuest_x                                          0x10C27C0
#define pinstEverQuestInfo_x                                       0xF30888
#define pinstCharData_x                                            0xF23474
#define pinstCharSpawn_x                                           0xF2349C
#define pinstControlledMissile_x                                   0xF23470
#define pinstControlledPlayer_x                                    0xF2349C
#define pinstCSidlManager_x                                        0x172EA38
#define pinstCXWndManager_x                                        0x172EA30
#define instDynamicZone_x                                          0xF30728
#define pinstDZMember_x                                            0xF30838
#define pinstDZTimerInfo_x                                         0xF3083C
#define pinstEQItemList_x                                          0xF1F918
#define pinstEQObjectList_x                                        0xF20944
#define instEQMisc_x                                               0xC045D0
#define pinstEQSoundManager_x                                      0xE70958
#define instExpeditionLeader_x                                     0xF30772
#define instExpeditionName_x                                       0xF307B2
#define pinstGroup_x                                               0xF20F46
#define pinstImeManager_x                                          0x172EA3C
#define pinstLocalPlayer_x                                         0xF23488
#define pinstMercenaryData_x                                       0xFB5BE8
#define pinstMercenaryStats_x                                      0x10CA8E0
#define pinstMercAltAbilities_x                                    0xE70710
#define pinstModelPlayer_x                                         0xF234B4
#define pinstPCData_x                                              0xF23474
#define pinstSkillMgr_x                                            0xFB6BE0
#define pinstSpawnManager_x                                        0xFB6438
#define pinstSpellManager_x                                        0xFB6D28
#define pinstSpellSets_x                                           0xFADB1C
#define pinstStringTable_x                                         0xF2341C
#define pinstSwitchManager_x                                       0xF20AD8
#define pinstTarget_x                                              0xF234A0
#define pinstTargetObject_x                                        0xF23478
#define pinstTargetSwitch_x                                        0xF2347C
#define pinstTaskMember_x                                          0xE6F100
#define pinstTrackTarget_x                                         0xF23494
#define pinstTradeTarget_x                                         0xF23484
#define instTributeActive_x                                        0xC045F5
#define pinstViewActor_x                                           0xE6FC54
#define pinstWorldData_x                                           0xF23458
#define pinstZoneAddr_x                                            0xF30E0C
#define pinstPlayerPath_x                                          0xFB6498
#define pinstTargetIndicator_x                                     0xFB6EC0
#define pinstCTargetManager_x                                      0xFB6F20
#define EQObject_Top_x                                             0xF23468
#define pinstRealEstateItems_x                                     0xFB6A4C

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE6FB70
#define pinstCAchievementsWnd_x                                    0xE6FBCC
#define pinstCTextOverlay_x                                        0xD2CE20
#define pinstCAudioTriggersWindow_x                                0xD2CC08
#define pinstCCharacterSelect_x                                    0xE6FADC
#define pinstCFacePick_x                                           0xE6F88C
#define pinstCFindItemWnd_x                                        0xE6FB6C
#define pinstCNoteWnd_x                                            0xE6FA94
#define pinstCBookWnd_x                                            0xE6FA9C
#define pinstCPetInfoWnd_x                                         0xE6FAA0
#define pinstCTrainWnd_x                                           0xE6FAA4
#define pinstCSkillsWnd_x                                          0xE6FAA8
#define pinstCSkillsSelectWnd_x                                    0xE6FAAC
#define pinstCCombatSkillsSelectWnd_x                              0xE6FAB0
#define pinstCFriendsWnd_x                                         0xE6FAB4
#define pinstCAuraWnd_x                                            0xE6FAB8
#define pinstCRespawnWnd_x                                         0xE6FABC
#define pinstCBandolierWnd_x                                       0xE6FAC0
#define pinstCPotionBeltWnd_x                                      0xE6FAC4
#define pinstCAAWnd_x                                              0xE6FAC8
#define pinstCGroupSearchFiltersWnd_x                              0xE6FACC
#define pinstCLoadskinWnd_x                                        0xE6FAD0
#define pinstCAlarmWnd_x                                           0xE6FAD4
#define pinstCMusicPlayerWnd_x                                     0xE6FAD8
#define pinstCMailWnd_x                                            0xE6FAE0
#define pinstCMailCompositionWnd_x                                 0xE6FAE4
#define pinstCMailAddressBookWnd_x                                 0xE6FAE8
#define pinstCRaidWnd_x                                            0xE6FAF0
#define pinstCRaidOptionsWnd_x                                     0xE6FAF4
#define pinstCBreathWnd_x                                          0xE6FAF8
#define pinstCMapViewWnd_x                                         0xE6FAFC
#define pinstCMapToolbarWnd_x                                      0xE6FB00
#define pinstCEditLabelWnd_x                                       0xE6FB04
#define pinstCTargetWnd_x                                          0xE6FB08
#define pinstCColorPickerWnd_x                                     0xE6FB0C
#define pinstCPlayerWnd_x                                          0xE6FB10
#define pinstCOptionsWnd_x                                         0xE6FB14
#define pinstCBuffWindowNORMAL_x                                   0xE6FB18
#define pinstCBuffWindowSHORT_x                                    0xE6FB1C
#define pinstCharacterCreation_x                                   0xE6FB20
#define pinstCCursorAttachment_x                                   0xE6FB24
#define pinstCCastingWnd_x                                         0xE6FB28
#define pinstCCastSpellWnd_x                                       0xE6FB2C
#define pinstCSpellBookWnd_x                                       0xE6FB30
#define pinstCInventoryWnd_x                                       0xE6FB34
#define pinstCBankWnd_x                                            0xE6FB3C
#define pinstCQuantityWnd_x                                        0xE6FB40
#define pinstCLootWnd_x                                            0xE6FB44
#define pinstCActionsWnd_x                                         0xE6FB48
#define pinstCCombatAbilityWnd_x                                   0xE6FB50
#define pinstCMerchantWnd_x                                        0xE6FB54
#define pinstCTradeWnd_x                                           0xE6FB5C
#define pinstCSelectorWnd_x                                        0xE6FB60
#define pinstCBazaarWnd_x                                          0xE6FB64
#define pinstCBazaarSearchWnd_x                                    0xE6FB68
#define pinstCGiveWnd_x                                            0xE6FB88
#define pinstCTrackingWnd_x                                        0xE6FB90
#define pinstCInspectWnd_x                                         0xE6FB94
#define pinstCSocialEditWnd_x                                      0xE6FB98
#define pinstCFeedbackWnd_x                                        0xE6FB9C
#define pinstCBugReportWnd_x                                       0xE6FBA0
#define pinstCVideoModesWnd_x                                      0xE6FBA4
#define pinstCTextEntryWnd_x                                       0xE6FBAC
#define pinstCFileSelectionWnd_x                                   0xE6FBB0
#define pinstCCompassWnd_x                                         0xE6FBB4
#define pinstCPlayerNotesWnd_x                                     0xE6FBB8
#define pinstCGemsGameWnd_x                                        0xE6FBBC
#define pinstCTimeLeftWnd_x                                        0xE6FBD8
#define pinstCPetitionQWnd_x                                       0xE6FBDC
#define pinstCStoryWnd_x                                           0xE6FBE0
#define pinstCJournalTextWnd_x                                     0xE6FBE4
#define pinstCJournalCatWnd_x                                      0xE6FBE8
#define pinstCBodyTintWnd_x                                        0xE6FBEC
#define pinstCServerListWnd_x                                      0xE6FBF0
#define pinstCAvaZoneWnd_x                                         0xE6FBFC
#define pinstCBlockedBuffWnd_x                                     0xE6FC00
#define pinstCBlockedPetBuffWnd_x                                  0xE6FC04
#define pinstCInvSlotMgr_x                                         0xE6FC4C
#define pinstCContainerMgr_x                                       0xE6FC50
#define pinstCAdventureLeaderboardWnd_x                            0x10C3170
#define pinstCAdventureRequestWnd_x                                0x10C31E8
#define pinstCAltStorageWnd_x                                      0x10C34C8
#define pinstCAdventureStatsWnd_x                                  0x10C3260
#define pinstCBarterMerchantWnd_x                                  0x10C4210
#define pinstCBarterSearchWnd_x                                    0x10C4288
#define pinstCBarterWnd_x                                          0x10C4300
#define pinstCChatWindowManager_x                                  0x10C4B10
#define pinstCDynamicZoneWnd_x                                     0x10C5040
#define pinstCEQMainWnd_x                                          0x10C5208
#define pinstCFellowshipWnd_x                                      0x10C4FD4
#define pinstCFindLocationWnd_x                                    0x10C54D8
#define pinstCGroupSearchWnd_x                                     0x10C57A8
#define pinstCGroupWnd_x                                           0x10C5820
#define pinstCGuildBankWnd_x                                       0x10C5898
#define pinstCGuildMgmtWnd_x                                       0x10C7988
#define pinstCHotButtonWnd_x                                       0x10C7A84
#define pinstCHotButtonWnd1_x                                      0x10C7A84
#define pinstCHotButtonWnd2_x                                      0x10C7A88
#define pinstCHotButtonWnd3_x                                      0x10C7A8C
#define pinstCHotButtonWnd4_x                                      0x10C7AB0
#define pinstCItemDisplayManager_x                                 0x10C7F08
#define pinstCItemExpTransferWnd_x                                 0x10C8004
#define pinstCLFGuildWnd_x                                         0x10C82E0
#define pinstCMIZoneSelectWnd_x                                    0x10C88C0
#define pinstCConfirmationDialog_x                                 0x10C8ED8
#define pinstCPopupWndManager_x                                    0x10C8ED8
#define pinstCProgressionSelectionWnd_x                            0x10C8FC8
#define pinstCPvPStatsWnd_x                                        0x10C90B8
#define pinstCLargeDialogWnd_x                                     0x10C9840
#define pinstCTaskWnd_x                                            0x10CABC0
#define pinstCTaskSomething_x                                      0xD3DCA8
#define pinstCTaskTemplateSelectWnd_x                              0x10CAB48
#define pinstCTipWndOFDAY_x                                        0x10CAD28
#define pinstCTipWndCONTEXT_x                                      0x10CAD2C
#define pinstCTitleWnd_x                                           0x10CADA8
#define pinstCContextMenuManager_x                                 0x172E8C0
#define pinstCVoiceMacroWnd_x                                      0xFB72F8
#define pinstCHtmlWnd_x                                            0xFB73E8
#define pinstItemIconCache_x                                       0x10C51B0
#define pinstCTradeskillWnd_x                                      0x10CAEA8
#define pinstCAdvancedLootWnd_x                                    0xE6FC40
#define pinstRewardSelectionWnd_x                                  0x10C95E0
#define pinstEQSuiteTextureLoader_x                                0xD1AF18

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x54AE70
#define __CastRay2_x                                               0x54A7A0
#define __HeadingDiff_x                                            0x934760
#define __FixHeading_x                                             0x9346F0
#define __get_bearing_x                                            0x53A4B0
#define __ConvertItemTags_x                                        0x537F80
#define __ExecuteCmd_x                                             0x5228A0
#define __EQGetTime_x                                              0x8A3FA0
#define __get_melee_range_x                                        0x529560
#define __GetGaugeValueFromEQ_x                                    0x7B3B20
#define __GetLabelFromEQ_x                                         0x7B4EF0
#define __ToggleKeyRingItem_x                                      0x48FA40
#define __GetXTargetType_x                                         0x936360
#define __LoadFrontEnd_x                                           0x640820
#define __NewUIINI_x                                               0x7B34F0
#define __ProcessGameEvents_x                                      0x584A20
#define __ProcessMouseEvent_x                                      0x5841C0
#define CrashDetected_x                                            0x6421E0
#define wwsCrashReportCheckForUploader_x                           0x801FE0
#define __AppCrashWrapper_x                                        0xC6856C
#define __pCrashHandler_x                                          0x10D7D88
#define __CrashHandler_x                                           0x801A40
#define wwsCrashReportPlatformLaunchUploader_x                     0x8041E0
#define DrawNetStatus_x                                            0x5BB0A0
#define Util__FastTime_x                                           0x8A3C40
#define Expansion_HoT_x                                            0xF31C50
#define __HelpPath_x                                               0xFB5308
#define __STMLToText_x                                             0x8EA270
#define __GetAnimationCache_x                                      0x6B0150

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x423330
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41DFA0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41DD70

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4D7DA0
#define AltAdvManager__IsAbilityReady_x                            0x4D7E10
#define AltAdvManager__GetAAById_x                                 0x4D8300
#define AltAdvManager__CanTrainAbility_x                           0x4D8F30
#define AltAdvManager__CanSeeAbility_x                             0x4D8AF0

// CharacterZoneClient
#define CharacterZoneClient__CharacterZoneClient_x                 0x4699C0
#define CharacterZoneClient__HasSkill_x                            0x465A30
#define CharacterZoneClient__MakeMeVisible_x                       0x46B530
#define CharacterZoneClient__IsStackBlocked_x                      0x44BD00
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x44B220
#define CharacterZoneClient__GetItemCountWorn_x                    0x463F90
#define CharacterZoneClient__GetItemCountInInventory_x             0x464070
#define CharacterZoneClient__GetCursorItemCount_x                  0x464150
#define CharacterZoneClient__FindAffectSlot_x                      0x451390
#define CharacterZoneClient__BardCastBard_x                        0x44A990
#define CharacterZoneClient__GetMaxEffects_x                       0x449520
#define CharacterZoneClient__GetEffect_x                           0x44B450
#define CharacterZoneClient__GetOpenEffectSlot_x                   0x4511F0
#define CharacterZoneClient__GetFirstEffectSlot_x                  0x449870
#define CharacterZoneClient__GetLastEffectSlot_x                   0x44FD40

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x670190

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x67E010

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x599B30
#define CButtonWnd__CButtonWnd_x                                   0x8DE460

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x699310
#define CChatManager__InitContextMenu_x                            0x69A460
#define CChatManager__FreeChatWindow_x                             0x698DC0
#define CChatManager__GetLockedActiveChatWindow_x                  0x6A25E0
#define CChatManager__SetLockedActiveChatWindow_x                  0x6992E0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E85D0
#define CContextMenu__dCContextMenu_x                              0x8E87E0
#define CContextMenu__AddMenuItem_x                                0x8E8CF0
#define CContextMenu__RemoveMenuItem_x                             0x8E8950
#define CContextMenu__RemoveAllMenuItems_x                         0x8E8970
#define CContextMenu__CheckMenuItem_x                              0x8E89F0

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8D4A30
#define CContextMenuManager__RemoveMenu_x                          0x8D4DC0
#define CContextMenuManager__PopupMenu_x                           0x8D5210
#define CContextMenuManager__Flush_x                               0x8D4AA0
#define CContextMenuManager__GetMenu_x                             0x4194C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x888170
#define CChatService__GetFriendName_x                              0x888180

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6A00B0
#define CChatWindow__Clear_x                                       0x69F9A0
#define CChatWindow__WndNotification_x                             0x6A09C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D8870
#define CComboWnd__Draw_x                                          0x8D8A80
#define CComboWnd__GetCurChoice_x                                  0x8D8620
#define CComboWnd__GetListRect_x                                   0x8D8D20
#define CComboWnd__GetTextRect_x                                   0x8D88E0
#define CComboWnd__InsertChoice_x                                  0x8D8E80
#define CComboWnd__SetColors_x                                     0x8D85B0
#define CComboWnd__SetChoice_x                                     0x8D85E0
#define CComboWnd__GetItemCount_x                                  0x8D8610
#define CComboWnd__GetCurChoiceText_x                              0x8D8660

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6AA2E0
#define CContainerWnd__vftable_x                                   0xAEE990

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4C5D20
#define CDisplay__GetClickedActor_x                                0x4BE5F0
#define CDisplay__GetUserDefinedColor_x                            0x4BD1D0
#define CDisplay__GetWorldFilePath_x                               0x4BC620
#define CDisplay__is3dON_x                                         0x4BBAB0
#define CDisplay__ReloadUI_x                                       0x4CFAE0
#define CDisplay__WriteTextHD2_x                                   0x4C20B0
#define CDisplay__TrueDistance_x                                   0x4BF220

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FFA30

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8ECB20
#define CEditWnd__GetCharIndexPt_x                                 0x8EDC60
#define CEditWnd__GetDisplayString_x                               0x8ECCD0
#define CEditWnd__GetHorzOffset_x                                  0x8ED010
#define CEditWnd__GetLineForPrintableChar_x                        0x8ED730
#define CEditWnd__GetSelStartPt_x                                  0x8EDF10
#define CEditWnd__GetSTMLSafeText_x                                0x8ED1A0
#define CEditWnd__PointFromPrintableChar_x                         0x8ED820
#define CEditWnd__SelectableCharFromPoint_x                        0x8ED9A0
#define CEditWnd__SetEditable_x                                    0x8ED170

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x56B160
#define CEverQuest__ClickedPlayer_x                                0x564D40
#define CEverQuest__CreateTargetIndicator_x                        0x565C40
#define CEverQuest__DeleteTargetIndicator_x                        0x565CC0
#define CEverQuest__DoTellWindow_x                                 0x476170
#define CEverQuest__OutputTextToLog_x                              0x475DD0
#define CEverQuest__DropHeldItemOnGround_x                         0x57B6D0
#define CEverQuest__dsp_chat_x                                     0x4764B0
#define CEverQuest__trimName_x                                     0x561650
#define CEverQuest__Emote_x                                        0x5799E0
#define CEverQuest__EnterZone_x                                    0x574AC0
#define CEverQuest__GetBodyTypeDesc_x                              0x55F090
#define CEverQuest__GetClassDesc_x                                 0x568580
#define CEverQuest__GetClassThreeLetterCode_x                      0x568B80
#define CEverQuest__GetDeityDesc_x                                 0x55F970
#define CEverQuest__GetLangDesc_x                                  0x55F420
#define CEverQuest__GetRaceDesc_x                                  0x568D40
#define CEverQuest__InterpretCmd_x                                 0x56C8E0
#define CEverQuest__LeftClickedOnPlayer_x                          0x581230
#define CEverQuest__LMouseUp_x                                     0x5831E0
#define CEverQuest__RightClickedOnPlayer_x                         0x581D40
#define CEverQuest__RMouseUp_x                                     0x582C40
#define CEverQuest__SetGameState_x                                 0x565610
#define CEverQuest__UPCNotificationFlush_x                         0x55DA20
#define CEverQuest__IssuePetCommand_x                              0x56D2C0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6BAF30
#define CGaugeWnd__CalcLinesFillRect_x                             0x6BAF90
#define CGaugeWnd__Draw_x                                          0x6BB3C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x43AF80
#define CGuild__GetGuildName_x                                     0x43B450
#define CGuild__GetGuildIndex_x                                    0x43C660

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6D7470

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6E4830
#define CInvSlotMgr__MoveItem_x                                    0x6E4FF0
#define CInvSlotMgr__SelectSlot_x                                  0x6E4120

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6E3580
#define CInvSlot__SliderComplete_x                                 0x6E0DA0
#define CInvSlot__GetItemBase_x                                    0x6E0230
#define CInvSlot__UpdateItem_x                                     0x6E07B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6E6440
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6E7570

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7AFA30
#define CItemDisplayWnd__UpdateStrings_x                           0x6E8680
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6F5240
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6F5750
#define CItemDisplayWnd__SetItem_x                                 0x6FB040

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7E6B90

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6EEBE0

// CLabel 
#define CLabel__Draw_x                                             0x701DD0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C44B0
#define CListWnd__dCListWnd_x                                      0x8C5750
#define CListWnd__AddColumn_x                                      0x8C56F0
#define CListWnd__AddColumn1_x                                     0x8C4D90
#define CListWnd__AddLine_x                                        0x8C4770
#define CListWnd__AddString_x                                      0x8C4990
#define CListWnd__CalculateFirstVisibleLine_x                      0x8C1600
#define CListWnd__CalculateVSBRange_x                              0x8C3980
#define CListWnd__ClearSel_x                                       0x8C0920
#define CListWnd__ClearAllSel_x                                    0x8C08D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C4340
#define CListWnd__Compare_x                                        0x8C22E0
#define CListWnd__Draw_x                                           0x8C3590
#define CListWnd__DrawColumnSeparators_x                           0x8C3420
#define CListWnd__DrawHeader_x                                     0x8C0BE0
#define CListWnd__DrawItem_x                                       0x8C2960
#define CListWnd__DrawLine_x                                       0x8C30C0
#define CListWnd__DrawSeparator_x                                  0x8C34C0
#define CListWnd__EnableLine_x                                     0x8C0B00
#define CListWnd__EnsureVisible_x                                  0x8C1760
#define CListWnd__ExtendSel_x                                      0x8C2870
#define CListWnd__GetColumnMinWidth_x                              0x8C0210
#define CListWnd__GetColumnWidth_x                                 0x8C0140
#define CListWnd__GetCurSel_x                                      0x8BF900
#define CListWnd__GetItemAtPoint_x                                 0x8C19F0
#define CListWnd__GetItemAtPoint1_x                                0x8C1A60
#define CListWnd__GetItemData_x                                    0x8BFC50
#define CListWnd__GetItemHeight_x                                  0x8C1260
#define CListWnd__GetItemIcon_x                                    0x8BFE40
#define CListWnd__GetItemRect_x                                    0x8C1830
#define CListWnd__GetItemText_x                                    0x8BFCF0
#define CListWnd__GetSelList_x                                     0x8C4C80
#define CListWnd__GetSeparatorRect_x                               0x8C2200
#define CListWnd__InsertLine_x                                     0x8C4B70
#define CListWnd__RemoveLine_x                                     0x8C4B80
#define CListWnd__SetColors_x                                      0x8BFA50
#define CListWnd__SetColumnJustification_x                         0x8C04A0
#define CListWnd__SetColumnWidth_x                                 0x8C01C0
#define CListWnd__SetCurSel_x                                      0x8BF940
#define CListWnd__SetItemColor_x                                   0x8C4030
#define CListWnd__SetItemData_x                                    0x8C0980
#define CListWnd__SetItemText_x                                    0x8C3E70
#define CListWnd__ShiftColumnSeparator_x                           0x8C3D00
#define CListWnd__Sort_x                                           0x8C5850
#define CListWnd__ToggleSel_x                                      0x8C0850

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x71AF50

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x73E770
#define CMerchantWnd__RequestBuyItem_x                             0x748190
#define CMerchantWnd__RequestSellItem_x                            0x74A8B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x73ED00
#define CMerchantWnd__SelectBuySellSlot_x                          0x73B620
#define CMerchantWnd__ActualSelect_x                               0x73FDC0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x856460
#define CPacketScrambler__hton_x                                   0x856470

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8E3440
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E3520
#define CSidlManager__CreateLabel_x                                0x7A4920
#define CSidlManager__CreateXWndFromTemplate_x                     0x8E19D0
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8E3800

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x8DA8C0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x8DA7C0
#define CSidlScreenWnd__ConvertToRes_x                             0x8FF910
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8DB1D0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DC390
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DC440
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DB920
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8DAB80
#define CSidlScreenWnd__EnableIniStorage_x                         0x8DA2F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8DAD70
#define CSidlScreenWnd__Init1_x                                    0x8DC070
#define CSidlScreenWnd__LoadIniInfo_x                              0x8DB290
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8DA4B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DBB60
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D9F50
#define CSidlScreenWnd__StoreIniVis_x                              0x8DA2A0
#define CSidlScreenWnd__WndNotification_x                          0x8DBDF0
#define CSidlScreenWnd__GetChildItem_x                             0x8DA3C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CDC30
#define CSidlScreenWnd__m_layoutCopy_x                             0x172E9E0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x6061D0
#define CSkillMgr__GetSkillCap_x                                   0x6063B0
#define CSkillMgr__GetNameToken_x                                  0x605D80

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FEBB0
#define CSliderWnd__SetValue_x                                     0x8FED80
#define CSliderWnd__SetNumTicks_x                                  0x8FF500

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7AAC80

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F8560
#define CStmlWnd__CalculateHSBRange_x                              0x8F0AD0
#define CStmlWnd__CalculateVSBRange_x                              0x8F0A40
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F0C50
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F1450
#define CStmlWnd__ForceParseNow_x                                  0x8F8EE0
#define CStmlWnd__GetNextTagPiece_x                                0x8F1350
#define CStmlWnd__GetSTMLText_x                                    0x484360
#define CStmlWnd__GetVisibleText_x                                 0x8F1EA0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F4470
#define CStmlWnd__MakeStmlColorTag_x                               0x8EFD20
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EFD80
#define CStmlWnd__SetSTMLText_x                                    0x8F5CC0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F8200
#define CStmlWnd__UpdateHistoryString_x                            0x8F2DE0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8FC3F0
#define CTabWnd__DrawCurrentPage_x                                 0x8FBC80
#define CTabWnd__DrawTab_x                                         0x8FBA50
#define CTabWnd__GetCurrentPage_x                                  0x8FC030
#define CTabWnd__GetPageInnerRect_x                                0x8FB740
#define CTabWnd__GetTabInnerRect_x                                 0x8FB940
#define CTabWnd__GetTabRect_x                                      0x8FB810
#define CTabWnd__InsertPage_x                                      0x8FC6E0
#define CTabWnd__SetPage_x                                         0x8FC060
#define CTabWnd__SetPageRect_x                                     0x8FC330
#define CTabWnd__UpdatePage_x                                      0x8FC680
#define CTabWnd__GetPageFromTabIndex_x                             0x8FB9A0
#define CTabWnd__GetCurrentTabIndex_x                              0x8FB6D0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6E7720
#define CPageWnd__SetTabText_x                                     0x908C50

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x436B60

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D8220
#define CTextureFont__GetTextExtent_x                              0x8D7F80

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x63EAC0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x905090

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BDA60

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029D0
#define CXStr__CXStr1_x                                            0x903D50
#define CXStr__CXStr3_x                                            0x8A0ED0
#define CXStr__dCXStr_x                                            0x7A48D0
#define CXStr__operator_equal_x                                    0x8A1040
#define CXStr__operator_equal1_x                                   0x8A1090
#define CXStr__operator_plus_equal1_x                              0x8A2190

// CXWnd 
//CTileLayoutWnd__SetOriginalAutoStretchInfo_x is here because its where I lookup the actual CXWnd Size.
#define CTileLayoutWnd__SetOriginalAutoStretchInfo_x               0x8D5D30
#define CXWnd__BringToTop_x                                        0x8CCE30
#define CXWnd__Center_x                                            0x8D2FF0
#define CXWnd__ClrFocus_x                                          0x8CCA00
#define CXWnd__Destroy_x                                           0x8D3AD0
#define CXWnd__DoAllDrawing_x                                      0x8D2C40
#define CXWnd__DrawChildren_x                                      0x8D2DE0
#define CXWnd__DrawColoredRect_x                                   0x8CD220
#define CXWnd__DrawTooltip_x                                       0x8CD4D0
#define CXWnd__DrawTooltipAtPoint_x                                0x8D1BB0
#define CXWnd__GetBorderFrame_x                                    0x8CD8F0
#define CXWnd__GetChildWndAt_x                                     0x8D39B0
#define CXWnd__GetClientClipRect_x                                 0x8CD6F0
#define CXWnd__GetScreenClipRect_x                                 0x8D22A0
#define CXWnd__GetScreenRect_x                                     0x8CDAC0
#define CXWnd__GetTooltipRect_x                                    0x8CD360
#define CXWnd__GetWindowTextA_x                                    0x426E90
#define CXWnd__IsActive_x                                          0x8C8500
#define CXWnd__IsDescendantOf_x                                    0x8CD830
#define CXWnd__IsReallyVisible_x                                   0x8D0BE0
#define CXWnd__IsType_x                                            0x8D3060
#define CScreenPieceTemplate__IsType_x                             0x901790
#define CXWnd__Move_x                                              0x8D02E0
#define CXWnd__Move1_x                                             0x8D28F0
#define CXWnd__ProcessTransition_x                                 0x8CCDD0
#define CXWnd__Refade_x                                            0x8CCBA0
#define CXWnd__Resize_x                                            0x8CDB90
#define CXWnd__Right_x                                             0x8D20A0
#define CXWnd__SetFocus_x                                          0x8CF430
#define CXWnd__SetFont_x                                           0x8CCA50
#define CXWnd__SetKeyTooltip_x                                     0x8CDE00
#define CXWnd__SetMouseOver_x                                      0x8D25E0
#define CXWnd__StartFade_x                                         0x8CCE80
#define CXWnd__GetChildItem_x                                      0x8D2530
#define CXWnd__SetParent_x                                         0x8D3960

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C9D90
#define CXWndManager__DrawWindows_x                                0x8C99D0
#define CXWndManager__GetKeyboardFlags_x                           0x8C8030
#define CXWndManager__HandleKeyboardMsg_x                          0x8C8990
#define CXWndManager__RemoveWnd_x                                  0x8C8690

// CDBStr
#define CDBStr__GetString_x                                        0x4BA2F0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x452450
#define EQ_Character__Cur_HP_x                                     0x465610
#define EQ_Character__Cur_Mana_x                                   0x45AA50
#define EQ_Character__GetAACastingTimeModifier_x                   0x44B530
#define EQ_Character__GetFocusCastingTimeModifier_x                0x443420
#define EQ_Character__GetFocusRangeModifier_x                      0x443570
#define EQ_Character__GetHPRegen_x                                 0x469050
#define EQ_Character__GetEnduranceRegen_x                          0x464C20
#define EQ_Character__GetManaRegen_x                               0x4695F0
#define EQ_Character__Max_Endurance_x                              0x5CCFD0
#define EQ_Character__Max_HP_x                                     0x45D5D0
#define EQ_Character__Max_Mana_x                                   0x5CCE00
#define EQ_Character__doCombatAbility_x                            0x5CA4D0
#define EQ_Character__UseSkill_x                                   0x4705D0
#define EQ_Character__GetConLevel_x                                0x5BF700
#define EQ_Character__IsExpansionFlag_x                            0x4B6560
#define EQ_Character__TotalEffect_x                                0x44F680
#define EQ_Character__GetPCSpellAffect_x                           0x44B8C0
#define EQ_Character__SpellDuration_x                              0x4498C0
#define EQ_Character__FindItemByRecord_x                           0x462C60
#define EQ_Character__GetAdjustedSkill_x                           0x4657E0
#define EQ_Character__GetBaseSkill_x                               0x45D4B0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x874370

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5D55E0

//PcClient
#define PcClient__PcClient_x                                       0x5C1530

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x446960
#define CCharacterSelect__EnterWorld_x                             0x446130
#define CCharacterSelect__Quit_x                                   0x444CF0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x59F510
#define EQ_Item__CreateItemTagString_x                             0x854660
#define EQ_Item__IsStackable_x                                     0x849C90
#define EQ_Item__GetImageNum_x                                     0x84C7E0
#define EQ_Item__CreateItemClient_x                                0x5A05F0
#define EQ_Item__GetItemValue_x                                    0x853110
#define EQ_Item__ValueSellMerchant_x                               0x8560C0
#define EQ_Item__IsKeyRingItem_x                                   0x84A7F0
#define EQ_Item__CanGoInBag_x                                      0x59F6A0
#define EQ_Item__GetMaxItemCount_x                                 0x849B80
#define EQ_Item__GetHeldItem_x                                     0x84B5F0
#define EQ_Item__GetAugmentFitBySlot_x                             0x855EE0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4DA3A0
#define EQ_LoadingS__Array_x                                       0xC0CA50

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5CF500
#define EQ_PC__GetAlternateAbilityId_x                             0x85E560
#define EQ_PC__GetCombatAbility_x                                  0x85E5F0
#define EQ_PC__GetCombatAbilityTimer_x                             0x859110
#define EQ_PC__GetItemRecastTimer_x                                0x5C8C80
#define EQ_PC__HasLoreItem_x                                       0x5C2CF0
#define EQ_PC__AlertInventoryChanged_x                             0x5BF6B0
#define EQ_PC__GetPcZoneClient_x                                   0x5E9B40
#define EQ_PC__RemoveMyAffect_x                                    0x5C80E0
#define EQ_PC__GetKeyRingItems_x                                   0x859530
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x86C270
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x8604E0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5275F0
#define EQItemList__add_object_x                                   0x5548F0
#define EQItemList__add_item_x                                     0x527530
#define EQItemList__delete_item_x                                  0x5279E0
#define EQItemList__FreeItemList_x                                 0x5278E0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4B94E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5D5380
#define EQPlayer__dEQPlayer_x                                      0x5DDA50
#define EQPlayer__DoAttack_x                                       0x5EF4C0
#define EQPlayer__EQPlayer_x                                       0x5E0180
#define EQPlayer__SetNameSpriteState_x                             0x5DA880
#define EQPlayer__SetNameSpriteTint_x                              0x5D67A0
#define PlayerBase__HasProperty_j_x                                0x932B60
#define EQPlayer__IsTargetable_x                                   0x932E00
#define EQPlayer__CanSee_x                                         0x933360
#define PlayerZoneClient__ChangeHeight_x                           0x5EF380
#define EQPlayer__CanSee1_x                                        0x933450
#define PlayerBase__GetVisibilityLineSegment_x                     0x9330F0

//PlayerZoneClient
#define PlayerZoneClient__GetLevel_x                               0x5E9CF0
#define PlayerZoneClient__IsValidTeleport_x                        0x555190
#define PlayerZoneClient__LegalPlayerRace_x                        0x4D26D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5E4180
#define EQPlayerManager__GetSpawnByName_x                          0x5E45E0
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5E41B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5A5B00
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5A5B40
#define KeypressHandler__ClearCommandStateArray_x                  0x5A56F0
#define KeypressHandler__HandleKeyDown_x                           0x5A4040
#define KeypressHandler__HandleKeyUp_x                             0x5A4360
#define KeypressHandler__SaveKeymapping_x                          0x5A57C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7138E0
#define MapViewMap__SaveEx_x                                       0x716C10

#define PlayerPointManager__GetAltCurrency_x                       0x872430

// StringTable 
#define StringTable__getString_x                                   0x86C5A0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5CCA60
#define PcZoneClient__RemovePetEffect_x                            0x5C9150
#define PcZoneClient__HasAlternateAbility_x                        0x5C9AF0
#define PcZoneClient__GetCurrentMod_x                              0x45CA80
#define PcZoneClient__GetModCap_x                                  0x45A1B0
#define PcZoneClient__CanEquipItem_x                               0x5CA010
#define PcZoneClient__GetItemByID_x                                0x5CE870
#define PcZoneClient__GetItemByItemClass_x                         0x5CF420
#define PcZoneClient__RemoveBuffEffect_x                           0x5C8390

//Doors
#define EQSwitch__UseSwitch_x                                      0x55C2C0

//IconCache
#define IconCache__GetIcon_x                                       0x6B0780

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6A7660
#define CContainerMgr__CloseContainer_x                            0x6A7E80

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7746D0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x598550

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4F4AB0
#define EQ_Spell__SpellAffects_x                                   0x4F1CA0
#define EQ_Spell__SpellAffectBase_x                                0x4F1D10
#define CharacterZoneClient__CalcAffectChange_x                    0x44B750
#define CharacterZoneClient__CalcAffectChangeGeneric_x             0x44A9F0
#define CLootWnd__LootAll_x                                        0x7091C0
#define CLootWnd__RequestLootSlot_x                                0x7099D0
#define EQ_Spell__IsStackable_x                                    0x4492E0
#define EQ_Spell__GetSpellAffectBySlot_x                           0x449390
#define EQ_Spell__GetSpellAffectByIndex_x                          0x43EA20
#define EQ_Spell__IsSPAStacking_x                                  0x4F1810
#define EQ_Spell__IsSPAIgnoredByStacking_x                         0x4F28B0
#define EQ_Spell__IsNoRemove_x                                     0x434BA0
#define EQ_Spell__IsDegeneratingLevelMod_x                         0x4F1830

#define __IsResEffectSpell_x                                       0x449410

//EQ_Affect
#define EQ_Affect__GetAffectData_x                                 0x87E020

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7BC590
#define CTargetWnd__WndNotification_x                              0x7BC080
#define CTargetWnd__RefreshTargetBuffs_x                           0x7BC770

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7C16B0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4ED310
#define EqSoundManager__PlayScriptMp3_x                            0x4EEDB0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4A8600

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EC150
#define CSidlManager__FindAnimation1_x                             0x8E1400

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4E1CB0
#define CAltAbilityData__GetMercMaxRank_x                          0x4E1C60
#define CAltAbilityData__GetMaxRank_x                              0x4D6450

//CTargetRing
#define CTargetRing__Cast_x                                        0x596190

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x459190
#define CharacterBase__CreateItemGlobalIndex_x                     0x475350
#define CharacterBase__CreateItemIndex_x                           0x520BD0
#define CharacterBase__GetItemPossession_x                         0x4441C0
#define CharacterBase__GetItemByGlobalIndex_x                      0x881E70
#define CharacterBase__GetEffectId_x                               0x459150

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x690360
#define CCastSpellWnd__IsBardSongPlaying_x                         0x68FAC0

//messages
#define msg_spell_worn_off_x                                       0x4FC5D0
#define msg_new_text_x                                             0x505D60
#define msgTokenTextParam_x                                        0x502560

//SpellManager
#define SpellManager__vftable_x                                    0xACA260
#define SpellManager__SpellManager_x                               0x47DF60
#define Spellmanager__LoadTextSpells_x                             0x60D0B0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x936E80

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x487A20
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43E950
#define ItemGlobalIndex__IsEquippedLocation_x                      0x449050
#define ItemGlobalIndex__IsValidIndex_x                            0x458A80

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x87FCE0
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x87EC20

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x702020

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x6AC3A0
#define CCursorAttachment__Deactivate_x                            0x6AB8E0

//CEQSuiteTextureLoader
#define CEQSuiteTextureLoader__GetDefaultUIPath_x                  0x8FE0B0
#define CEQSuiteTextureLoader__GetTexture_x                        0x8FE230

//CFindItemWnd
#define CFindItemWnd__CFindItemWnd_x                               0x48C2A0

//IString
#define IString__Append_x                                          0x47EC10

//Camera
#define CDisplay__cameraType_x                                     0xE6FC68
#define EverQuest__Cameras_x                                       0xF31F68
