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
#define __ExpectedVersionDate                                     "Mar  7 2017"
#define __ExpectedVersionTime                                     "15:21:51"
#define __ActualVersionDate_x                                      0xACACC0
#define __ActualVersionTime_x                                      0xACACCC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Test)"
#define __MacroQuestWinName                                       "MacroQuest2(Test)"

// Memory Protection
#define __MemChecker0_x                                            0x59A1E0
#define __MemChecker1_x                                            0x890560
#define __MemChecker2_x                                            0x6302D0
#define __MemChecker3_x                                            0x630220
#define __MemChecker4_x                                            0x7E3850
#define __EncryptPad0_x                                            0xC24328
#define __EncryptPad1_x                                            0xCFFC90
#define __EncryptPad2_x                                            0xC4D9A8
#define __EncryptPad3_x                                            0xC4D5A8
#define __EncryptPad4_x                                            0xCEE2B0
#define __EncryptPad5_x                                            0x10A8898
#define __AC1_x                                                    0x7A2B25
#define __AC2_x                                                    0x5543B7
#define __AC3_x                                                    0x552550
#define __AC4_x                                                    0x564910
#define __AC5_x                                                    0x5776BB
#define __AC6_x                                                    0x57B25E
#define __AC7_x                                                    0x571CBC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FE5B2C

// Direct Input
#define DI8__Main_x                                                0x10A8870
#define DI8__Keyboard_x                                            0x10A8874
#define DI8__Mouse_x                                               0x10A8878
#define DI8__Mouse_Copy_x                                          0xF16C4C
#define DI8__Mouse_Check_x                                         0xFA055C
#define __Attack_x                                                 0xF9B13F
#define __Autofire_x                                               0xF9B140
#define __BindList_x                                               0xBFF108
#define g_eqCommandStates_x                                        0xF05C70
#define __Clicks_x                                                 0xF16D08
#define __CommandList_x                                            0xC01768
#define __CurrentMapLabel_x                                        0x10AE2F8
#define __CurrentSocial_x                                          0xBD1348
#define __DoAbilityList_x                                          0xF4D3F4
#define __do_loot_x                                                0x523000
#define __DrawHandler_x                                            0x1715224
#define __GroupCount_x                                             0xF072A2

#define __Guilds_x                                                 0xF0CEB8
#define __gWorld_x                                                 0xF0975C
#define __HotkeyPage_x                                             0xF93DF4
#define __HWnd_x                                                   0xFA0678
#define __InChatMode_x                                             0xF16C34
#define __LastTell_x                                               0xF18AF0
#define __LMouseHeldTime_x                                         0xF16D74
#define __Mouse_x                                                  0x10A887C
#define __MouseLook_x                                              0xF16CCE
#define __MouseEventTime_x                                         0xF9B944
#define __gpbCommandEvent_x                                        0xF09824
#define __NetStatusToggle_x                                        0xF16CD1
#define __PCNames_x                                                0xF18108
#define __RangeAttackReady_x                                       0xF17E3C
#define __RMouseHeldTime_x                                         0xF16D70
#define __RunWalkState_x                                           0xF16C38
#define __ScreenMode_x                                             0xE55968
#define __ScreenX_x                                                0xF16BEC
#define __ScreenY_x                                                0xF16BE8
#define __ScreenXMax_x                                             0xF16BF0
#define __ScreenYMax_x                                             0xF16BF4
#define __ServerHost_x                                             0xF071EC
#define __ServerName_x                                             0xF4D3B4
#define __ShiftKeyDown_x                                           0xF172C8
#define __ShowNames_x                                              0xF17FFC
#define __Socials_x                                                0xF4D4B4
#define __SubscriptionType_x                                       0x10DC334
#define __TargetAggroHolder_x                                      0x10B0544
#define __ZoneType_x                                               0xF170CC
#define __GroupAggro_x                                             0x10B0584
#define __LoginName_x                                              0xF9F154
#define __Inviter_x                                                0xF9B0BC
#define __AttackOnAssist_x                                         0xF17FB8
#define __UseTellWindows_x                                         0xF182A0

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF09848
#define instEQZoneInfo_x                                           0xF16EC4
#define instKeypressHandler_x                                      0xF9B928
#define pinstActiveBanker_x                                        0xF09800
#define pinstActiveCorpse_x                                        0xF09804
#define pinstActiveGMaster_x                                       0xF09808
#define pinstActiveMerchant_x                                      0xF097FC
#define pinstAggroInfo_x                                           0xD13348
#define pinstAltAdvManager_x                                       0xE56A38
#define pinstAuraMgr_x                                             0xD23AB8
#define pinstBandageTarget_x                                       0xF097E8
#define pinstCamActor_x                                            0xE5638C
#define pinstCDBStr_x                                              0xE558FC
#define pinstCDisplay_x                                            0xF09810
#define pinstCEverQuest_x                                          0x10A89F0
#define pinstEverQuestInfo_x                                       0xF16BE0
#define pinstCharData_x                                            0xF097CC
#define pinstCharSpawn_x                                           0xF097F4
#define pinstControlledMissile_x                                   0xF097C8
#define pinstControlledPlayer_x                                    0xF097F4
#define pinstCSidlManager_x                                        0x1714614
#define pinstCXWndManager_x                                        0x171460C
#define instDynamicZone_x                                          0xF16A80
#define pinstDZMember_x                                            0xF16B90
#define pinstDZTimerInfo_x                                         0xF16B94
#define pinstEQItemList_x                                          0xF05EC4
#define pinstEQObjectList_x                                        0xF06C9C
#define instEQMisc_x                                               0xBE7808
#define pinstEQSoundManager_x                                      0xE57008
#define instExpeditionLeader_x                                     0xF16ACA
#define instExpeditionName_x                                       0xF16B0A
#define pinstGroup_x                                               0xF0729E
#define pinstImeManager_x                                          0x1714618
#define pinstLocalPlayer_x                                         0xF097E0
#define pinstMercenaryData_x                                       0xF9BFA8
#define pinstMercenaryStats_x                                      0x10B0690
#define pinstMercAltAbilities_x                                    0xE56DC0
#define pinstModelPlayer_x                                         0xF0980C
#define pinstPCData_x                                              0xF097CC
#define pinstSkillMgr_x                                            0xF9CE10
#define pinstSpawnManager_x                                        0xF9C6F8
#define pinstSpellManager_x                                        0xF9CF58
#define pinstSpellSets_x                                           0xF93E58
#define pinstStringTable_x                                         0xF09774
#define pinstSwitchManager_x                                       0xF06E30
#define pinstTarget_x                                              0xF097F8
#define pinstTargetObject_x                                        0xF097D0
#define pinstTargetSwitch_x                                        0xF097D4
#define pinstTaskMember_x                                          0xE55848
#define pinstTrackTarget_x                                         0xF097EC
#define pinstTradeTarget_x                                         0xF097DC
#define instTributeActive_x                                        0xBE782D
#define pinstViewActor_x                                           0xE56388
#define pinstWorldData_x                                           0xF097B0
#define pinstZoneAddr_x                                            0xF17164
#define pinstPlayerPath_x                                          0xF9C758
#define pinstTargetIndicator_x                                     0xF9D0F0
#define pinstCTargetManager_x                                      0xF9D150
#define EQObject_Top_x                                             0xF097C0
#define pinstRealEstateItems_x                                     0xF9CCFC

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCRealEstateItemsWnd_x                                 0xE562A4
#define pinstCAchievementsWnd_x                                    0xE56300
#define pinstCTextOverlay_x                                        0xD13840
#define pinstCAudioTriggersWindow_x                                0xD136D0
#define pinstCCharacterSelect_x                                    0xE56214
#define pinstCFacePick_x                                           0xE55FC4
#define pinstCNoteWnd_x                                            0xE561CC
#define pinstCBookWnd_x                                            0xE561D4
#define pinstCPetInfoWnd_x                                         0xE561D8
#define pinstCTrainWnd_x                                           0xE561DC
#define pinstCSkillsWnd_x                                          0xE561E0
#define pinstCSkillsSelectWnd_x                                    0xE561E4
#define pinstCCombatSkillsSelectWnd_x                              0xE561E8
#define pinstCFriendsWnd_x                                         0xE561EC
#define pinstCAuraWnd_x                                            0xE561F0
#define pinstCRespawnWnd_x                                         0xE561F4
#define pinstCBandolierWnd_x                                       0xE561F8
#define pinstCPotionBeltWnd_x                                      0xE561FC
#define pinstCAAWnd_x                                              0xE56200
#define pinstCGroupSearchFiltersWnd_x                              0xE56204
#define pinstCLoadskinWnd_x                                        0xE56208
#define pinstCAlarmWnd_x                                           0xE5620C
#define pinstCMusicPlayerWnd_x                                     0xE56210
#define pinstCMailWnd_x                                            0xE56218
#define pinstCMailCompositionWnd_x                                 0xE5621C
#define pinstCMailAddressBookWnd_x                                 0xE56220
#define pinstCRaidWnd_x                                            0xE56228
#define pinstCRaidOptionsWnd_x                                     0xE5622C
#define pinstCBreathWnd_x                                          0xE56230
#define pinstCMapViewWnd_x                                         0xE56234
#define pinstCMapToolbarWnd_x                                      0xE56238
#define pinstCEditLabelWnd_x                                       0xE5623C
#define pinstCTargetWnd_x                                          0xE56240
#define pinstCColorPickerWnd_x                                     0xE56244
#define pinstCPlayerWnd_x                                          0xE56248
#define pinstCOptionsWnd_x                                         0xE5624C
#define pinstCBuffWindowNORMAL_x                                   0xE56250
#define pinstCBuffWindowSHORT_x                                    0xE56254
#define pinstCharacterCreation_x                                   0xE56258
#define pinstCCursorAttachment_x                                   0xE5625C
#define pinstCCastingWnd_x                                         0xE56260
#define pinstCCastSpellWnd_x                                       0xE56264
#define pinstCSpellBookWnd_x                                       0xE56268
#define pinstCInventoryWnd_x                                       0xE5626C
#define pinstCBankWnd_x                                            0xE56274
#define pinstCQuantityWnd_x                                        0xE56278
#define pinstCLootWnd_x                                            0xE5627C
#define pinstCActionsWnd_x                                         0xE56280
#define pinstCCombatAbilityWnd_x                                   0xE56288
#define pinstCMerchantWnd_x                                        0xE5628C
#define pinstCTradeWnd_x                                           0xE56294
#define pinstCSelectorWnd_x                                        0xE56298
#define pinstCBazaarWnd_x                                          0xE5629C
#define pinstCBazaarSearchWnd_x                                    0xE562A0
#define pinstCGiveWnd_x                                            0xE562BC
#define pinstCTrackingWnd_x                                        0xE562C4
#define pinstCInspectWnd_x                                         0xE562C8
#define pinstCSocialEditWnd_x                                      0xE562CC
#define pinstCFeedbackWnd_x                                        0xE562D0
#define pinstCBugReportWnd_x                                       0xE562D4
#define pinstCVideoModesWnd_x                                      0xE562D8
#define pinstCTextEntryWnd_x                                       0xE562E0
#define pinstCFileSelectionWnd_x                                   0xE562E4
#define pinstCCompassWnd_x                                         0xE562E8
#define pinstCPlayerNotesWnd_x                                     0xE562EC
#define pinstCGemsGameWnd_x                                        0xE562F0
#define pinstCTimeLeftWnd_x                                        0xE562F4
#define pinstCPetitionQWnd_x                                       0xE56310
#define pinstCSoulmarkWnd_x                                        0xE56314
#define pinstCStoryWnd_x                                           0xE56318
#define pinstCJournalTextWnd_x                                     0xE5631C
#define pinstCJournalCatWnd_x                                      0xE56320
#define pinstCBodyTintWnd_x                                        0xE56324
#define pinstCServerListWnd_x                                      0xE56328
#define pinstCAvaZoneWnd_x                                         0xE56334
#define pinstCBlockedBuffWnd_x                                     0xE56338
#define pinstCBlockedPetBuffWnd_x                                  0xE5633C
#define pinstCInvSlotMgr_x                                         0xE56380
#define pinstCContainerMgr_x                                       0xE56384
#define pinstCAdventureLeaderboardWnd_x                            0x10A93A0
#define pinstCAdventureRequestWnd_x                                0x10A9418
#define pinstCAltStorageWnd_x                                      0x10A96F8
#define pinstCAdventureStatsWnd_x                                  0x10A9490
#define pinstCBarterMerchantWnd_x                                  0x10AA2E0
#define pinstCBarterSearchWnd_x                                    0x10AA358
#define pinstCBarterWnd_x                                          0x10AA3D0
#define pinstCChatWindowManager_x                                  0x10AAA60
#define pinstCDynamicZoneWnd_x                                     0x10AAF10
#define pinstCEQMainWnd_x                                          0x10AB0A8
#define pinstCFellowshipWnd_x                                      0x10AAEA4
#define pinstCFindLocationWnd_x                                    0x10AB378
#define pinstCGroupSearchWnd_x                                     0x10AB648
#define pinstCGroupWnd_x                                           0x10AB6C0
#define pinstCGuildBankWnd_x                                       0x10AB738
#define pinstCGuildMgmtWnd_x                                       0x10AD828
#define pinstCHotButtonWnd_x                                       0x10AD924
#define pinstCHotButtonWnd1_x                                      0x10AD924
#define pinstCHotButtonWnd2_x                                      0x10AD928
#define pinstCHotButtonWnd3_x                                      0x10AD92C
#define pinstCHotButtonWnd4_x                                      0x10AD950
#define pinstCItemDisplayManager_x                                 0x10ADC48
#define pinstCItemExpTransferWnd_x                                 0x10ADCC4
#define pinstCLFGuildWnd_x                                         0x10ADFA0
#define pinstCMIZoneSelectWnd_x                                    0x10AE588
#define pinstCConfirmationDialog_x                                 0x10AEC90
#define pinstCPopupWndManager_x                                    0x10AEC90
#define pinstCProgressionSelectionWnd_x                            0x10AED80
#define pinstCPvPStatsWnd_x                                        0x10AEE70
#define pinstCLargeDialogWnd_x                                     0x10AF578
#define pinstCTaskWnd_x                                            0x10B0970
#define pinstCTaskSomething_x                                      0xD243F0
#define pinstCTaskTemplateSelectWnd_x                              0x10B08F8
#define pinstCTipWndOFDAY_x                                        0x10B0AD8
#define pinstCTipWndCONTEXT_x                                      0x10B0ADC
#define pinstCTitleWnd_x                                           0x10B0B58
#define pinstCContextMenuManager_x                                 0x1714584
#define pinstCVoiceMacroWnd_x                                      0xF9D528
#define pinstCHtmlWnd_x                                            0xF9D618
#define pinstIconCache_x                                           0x10AB07C
#define pinstCTradeskillWnd_x                                      0x10B0C58
#define pinstCAdvancedLootWnd_x                                    0xE56374
#define pinstRewardSelectionWnd_x                                  0x10AF398

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x53A2A0
#define __ConvertItemTags_x                                        0x527B00
#define __ExecuteCmd_x                                             0x512450
#define __EQGetTime_x                                              0x8901F0
#define __get_melee_range_x                                        0x519070
#define __GetGaugeValueFromEQ_x                                    0x7A16E0
#define __GetLabelFromEQ_x                                         0x7A2AB0
#define __ToggleKeyRingItem_x                                      0x481E70
#define __GetXTargetType_x                                         0x920AC0
#define __LoadFrontEnd_x                                           0x62F9A0
#define __NewUIINI_x                                               0x7A10C0
#define __ProcessGameEvents_x                                      0x573A50
#define __ProcessMouseEvent_x                                      0x5731F0
#define CrashDetected_x                                            0x631360
#define wwsCrashReportCheckForUploader_x                           0x7EF500
#define __AppCrashWrapper_x                                        0xC4D59C
#define __pCrashHandler_x                                          0x10BDB08
#define __CrashHandler_x                                           0x7EEF60
#define wwsCrashReportPlatformLaunchUploader_x                     0x7F1710
#define DrawNetStatus_x                                            0x5A9CC0
#define Util__FastTime_x                                           0x88FE90
#define Expansion_HoT_x                                            0xF17FA8
#define __HelpPath_x                                               0xF9B6B0
#define __STMLToText_x                                             0x8D6000

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420630
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B3D0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B1B0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C9330
#define AltAdvManager__IsAbilityReady_x                            0x4C93A0
#define AltAdvManager__GetAAById_x                                 0x4C9890
#define AltAdvManager__CanTrainAbility_x                           0x4CA4C0
#define AltAdvManager__CanSeeAbility_x                             0x4CA080

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463690
#define CharacterZoneClient__MakeMeVisible_x                       0x4680A0
#define CharacterZoneClient__IsStackBlocked_x                      0x447A10
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446ED0
#define CharacterZoneClient__GetItemCountWorn_x                    0x461420
#define CharacterZoneClient__GetItemCountInInventory_x             0x461500
#define CharacterZoneClient__GetCursorItemCount_x                  0x4615E0
#define CharacterZoneClient__FindAffectSlot_x                      0x44CF20

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65F1E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66D4A0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5890D0
#define CButtonWnd__CButtonWnd_x                                   0x8CA370

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x688490
#define CChatManager__InitContextMenu_x                            0x6895E0
#define CChatManager__FreeChatWindow_x                             0x687F70
#define CChatManager__GetLockedActiveChatWindow_x                  0x690D90
#define CChatManager__SetLockedActiveChatWindow_x                  0x688460
// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D4360
#define CContextMenu__dCContextMenu_x                              0x8D4570
#define CContextMenu__AddMenuItem_x                                0x8D4580
#define CContextMenu__RemoveMenuItem_x                             0x8D4870
#define CContextMenu__RemoveAllMenuItems_x                         0x8D4890
#define CContextMenuManager__AddMenu_x                             0x8C0940
#define CContextMenuManager__RemoveMenu_x                          0x8C0CD0
#define CContextMenuManager__PopupMenu_x                           0x8C1120
#define CContextMenuManager__Flush_x                               0x8C09B0
#define CContextMenuManager__GetMenu_x                             0x416AB0
#define CContextMenu__CheckMenuItem_x                              0x8D4910

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8745D0
#define CChatService__GetFriendName_x                              0x8745E0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68F100
#define CChatWindow__Clear_x                                       0x68E9E0
#define CChatWindow__WndNotification_x                             0x68F640

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C4780
#define CComboWnd__Draw_x                                          0x8C4990
#define CComboWnd__GetCurChoice_x                                  0x8C4530
#define CComboWnd__GetListRect_x                                   0x8C4C30
#define CComboWnd__GetTextRect_x                                   0x8C47F0
#define CComboWnd__InsertChoice_x                                  0x8C4CA0
#define CComboWnd__SetColors_x                                     0x8C44C0
#define CComboWnd__SetChoice_x                                     0x8C44F0
#define CComboWnd__GetItemCount_x                                  0x8C4520
#define CComboWnd__GetCurChoiceText_x                              0x8C4570

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x698A60
#define CContainerWnd__vftable_x                                   0xAD48A8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B7760
#define CDisplay__GetClickedActor_x                                0x4B00A0
#define CDisplay__GetUserDefinedColor_x                            0x4AEC80
#define CDisplay__GetWorldFilePath_x                               0x4AE0D0
#define CDisplay__is3dON_x                                         0x4AD560
#define CDisplay__ReloadUI_x                                       0x4C2D30
#define CDisplay__WriteTextHD2_x                                   0x4B3B20

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EA990

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D88B0
#define CEditWnd__GetCharIndexPt_x                                 0x8D9950
#define CEditWnd__GetDisplayString_x                               0x8D8A60
#define CEditWnd__GetHorzOffset_x                                  0x8D8DA0
#define CEditWnd__GetLineForPrintableChar_x                        0x8D9410
#define CEditWnd__GetSelStartPt_x                                  0x8D9C10
#define CEditWnd__GetSTMLSafeText_x                                0x8D8F40
#define CEditWnd__PointFromPrintableChar_x                         0x8D9500
#define CEditWnd__SelectableCharFromPoint_x                        0x8D9680
#define CEditWnd__SetEditable_x                                    0x8D8F10

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x55B140
#define CEverQuest__ClickedPlayer_x                                0x554B00
#define CEverQuest__CreateTargetIndicator_x                        0x5559F0
#define CEverQuest__DeleteTargetIndicator_x                        0x555A70
#define CEverQuest__DoTellWindow_x                                 0x472D00
#define CEverQuest__OutputTextToLog_x                              0x472960
#define CEverQuest__DropHeldItemOnGround_x                         0x56B750
#define CEverQuest__dsp_chat_x                                     0x473040
#define CEverQuest__trimName_x                                     0x551450
#define CEverQuest__Emote_x                                        0x569AB0
#define CEverQuest__EnterZone_x                                    0x564AA0
#define CEverQuest__GetBodyTypeDesc_x                              0x54EEB0
#define CEverQuest__GetClassDesc_x                                 0x558280
#define CEverQuest__GetClassThreeLetterCode_x                      0x558880
#define CEverQuest__GetDeityDesc_x                                 0x54F790
#define CEverQuest__GetLangDesc_x                                  0x54F240
#define CEverQuest__GetRaceDesc_x                                  0x558A40
#define CEverQuest__InterpretCmd_x                                 0x55C8C0
#define CEverQuest__LeftClickedOnPlayer_x                          0x570110
#define CEverQuest__LMouseUp_x                                     0x572210
#define CEverQuest__RightClickedOnPlayer_x                         0x570C20
#define CEverQuest__RMouseUp_x                                     0x571C70
#define CEverQuest__SetGameState_x                                 0x5553C0
#define CEverQuest__UPCNotificationFlush_x                         0x54CCC0
#define CEverQuest__IssuePetCommand_x                              0x55D2A0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A95F0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A9650
#define CGaugeWnd__Draw_x                                          0x6A9A80

// CGuild
#define CGuild__FindMemberByName_x                                 0x437290
#define CGuild__GetGuildName_x                                     0x437760
#define CGuild__GetGuildIndex_x                                    0x438930

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C5AD0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D2C50
#define CInvSlotMgr__MoveItem_x                                    0x6D3AF0
#define CInvSlotMgr__SelectSlot_x                                  0x6D2D00

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D2100
#define CInvSlot__SliderComplete_x                                 0x6CF910
#define CInvSlot__GetItemBase_x                                    0x6CEDB0
#define CInvSlot__UpdateItem_x                                     0x6CF330

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D4F20
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6D6040

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79D0E0
#define CItemDisplayWnd__UpdateStrings_x                           0x6D70C0
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6E3B70
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6E40A0
#define CItemDisplayWnd__SetItem_x                                 0x6E9B10

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7D4460

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6DD670

// CLabel 
#define CLabel__Draw_x                                             0x6F0890

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B03A0
#define CListWnd__dCListWnd_x                                      0x8B15C0
#define CListWnd__AddColumn_x                                      0x8B1560
#define CListWnd__AddColumn1_x                                     0x8B0BF0
#define CListWnd__AddLine_x                                        0x8B0650
#define CListWnd__AddString_x                                      0x8B0870
#define CListWnd__CalculateFirstVisibleLine_x                      0x8AD630
#define CListWnd__CalculateVSBRange_x                              0x8AF860
#define CListWnd__ClearSel_x                                       0x8AC950
#define CListWnd__ClearAllSel_x                                    0x8AC900
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B0230
#define CListWnd__Compare_x                                        0x8AE1A0
#define CListWnd__Draw_x                                           0x8AF460
#define CListWnd__DrawColumnSeparators_x                           0x8AF2F0
#define CListWnd__DrawHeader_x                                     0x8ACC10
#define CListWnd__DrawItem_x                                       0x8AE820
#define CListWnd__DrawLine_x                                       0x8AEF90
#define CListWnd__DrawSeparator_x                                  0x8AF390
#define CListWnd__EnableLine_x                                     0x8ACB30
#define CListWnd__EnsureVisible_x                                  0x8AD790
#define CListWnd__ExtendSel_x                                      0x8AE730
#define CListWnd__GetColumnMinWidth_x                              0x8AC300
#define CListWnd__GetColumnWidth_x                                 0x8AC230
#define CListWnd__GetCurSel_x                                      0x8ABA00
#define CListWnd__GetItemAtPoint_x                                 0x8ADA30
#define CListWnd__GetItemAtPoint1_x                                0x8ADAA0
#define CListWnd__GetItemData_x                                    0x8ABD40
#define CListWnd__GetItemHeight_x                                  0x8AD290
#define CListWnd__GetItemIcon_x                                    0x8ABF30
#define CListWnd__GetItemRect_x                                    0x8AD870
#define CListWnd__GetItemText_x                                    0x8ABDE0
#define CListWnd__GetSelList_x                                     0x8B0AE0
#define CListWnd__GetSeparatorRect_x                               0x8AE0D0
#define CListWnd__InsertLine_x                                     0x8B0A50
#define CListWnd__RemoveLine_x                                     0x8B0A60
#define CListWnd__SetColors_x                                      0x8ABB50
#define CListWnd__SetColumnJustification_x                         0x8AC590
#define CListWnd__SetColumnWidth_x                                 0x8AC2B0
#define CListWnd__SetCurSel_x                                      0x8ABA40
#define CListWnd__SetItemColor_x                                   0x8AFF20
#define CListWnd__SetItemData_x                                    0x8AC9B0
#define CListWnd__SetItemText_x                                    0x8AFD60
#define CListWnd__ShiftColumnSeparator_x                           0x8AFBF0
#define CListWnd__Sort_x                                           0x8B16C0
#define CListWnd__ToggleSel_x                                      0x8AC880

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7097A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72ADF0
#define CMerchantWnd__RequestBuyItem_x                             0x731E80
#define CMerchantWnd__RequestSellItem_x                            0x732950
#define CMerchantWnd__SelectRecoverySlot_x                         0x72B0A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x72A2A0
#define CMerchantWnd__ActualSelect_x                               0x72ED60

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x842F50
#define CPacketScrambler__hton_x                                   0x842F60

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8CF2E0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8CF3C0
#define CSidlManager__CreateLabel_x                                0x793040
#define CSidlManager__CreateXWndFromTemplate_x                     0x8CD880
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8CF6A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x656560
#define CSidlScreenWnd__CalculateVSBRange_x                        0x656480
#define CSidlScreenWnd__ConvertToRes_x                             0x8EA870
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C7100
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C82C0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C8370
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C7850
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C6AB0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C6230
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C6CA0
#define CSidlScreenWnd__Init1_x                                    0x8C7FA0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C71B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C63F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C7A90
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C5E90
#define CSidlScreenWnd__StoreIniVis_x                              0x8C61E0
#define CSidlScreenWnd__WndNotification_x                          0x8C7D20
#define CSidlScreenWnd__GetChildItem_x                             0x8C6300
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B9B70
#define CSidlScreenWnd__m_layoutCopy_x                             0x17145E8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F5330
#define CSkillMgr__GetSkillCap_x                                   0x5F5510
#define CSkillMgr__GetNameToken_x                                  0x5F4F50

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E9B40
#define CSliderWnd__SetValue_x                                     0x8E9D10
#define CSliderWnd__SetNumTicks_x                                  0x8EA490

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79AD50

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E5510
#define CStmlWnd__CalculateHSBRange_x                              0x8DDB10
#define CStmlWnd__CalculateVSBRange_x                              0x8DDA80
#define CStmlWnd__CanBreakAtCharacter_x                            0x8DDC90
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8DE570
#define CStmlWnd__ForceParseNow_x                                  0x8E5E60
#define CStmlWnd__GetNextTagPiece_x                                0x8DE470
#define CStmlWnd__GetSTMLText_x                                    0x690D50
#define CStmlWnd__GetVisibleText_x                                 0x8DEFC0
#define CStmlWnd__InitializeWindowVariables_x                      0x8E1330
#define CStmlWnd__MakeStmlColorTag_x                               0x8DCD80
#define CStmlWnd__MakeWndNotificationTag_x                         0x8DCDE0
#define CStmlWnd__SetSTMLText_x                                    0x8E2B80
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E51B0
#define CStmlWnd__UpdateHistoryString_x                            0x8DFEF0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8DC4A0
#define CTabWnd__DrawCurrentPage_x                                 0x8DBD30
#define CTabWnd__DrawTab_x                                         0x8DBAF0
#define CTabWnd__GetCurrentPage_x                                  0x8DC0E0
#define CTabWnd__GetPageInnerRect_x                                0x8DB7E0
#define CTabWnd__GetTabInnerRect_x                                 0x8DB9E0
#define CTabWnd__GetTabRect_x                                      0x8DB8B0
#define CTabWnd__InsertPage_x                                      0x8DC790
#define CTabWnd__SetPage_x                                         0x8DC110
#define CTabWnd__SetPageRect_x                                     0x8DC3E0
#define CTabWnd__UpdatePage_x                                      0x8DC730
#define CTabWnd__GetPageFromTabIndex_x                             0x8DBA40
#define CTabWnd__GetCurrentTabIndex_x                              0x8DB770

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6D61F0
#define CPageWnd__SetTabText_x                                     0x8F3880

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432EA0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C4130
#define CTextureFont__GetTextExtent_x                              0x8C3E90

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x62DC30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EFC70

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A9B60

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402A00
#define CXStr__CXStr1_x                                            0x4037E0
#define CXStr__CXStr3_x                                            0x88D130
#define CXStr__dCXStr_x                                            0x792FF0
#define CXStr__operator_equal_x                                    0x88D2A0
#define CXStr__operator_equal1_x                                   0x88D2F0
#define CXStr__operator_plus_equal1_x                              0x88E3F0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B8D40
#define CXWnd__Center_x                                            0x8BEF30
#define CXWnd__ClrFocus_x                                          0x8B8910
#define CXWnd__Destroy_x                                           0x8BFA10
#define CXWnd__DoAllDrawing_x                                      0x8BEB80
#define CXWnd__DrawChildren_x                                      0x8BED20
#define CXWnd__DrawColoredRect_x                                   0x8B9120
#define CXWnd__DrawTooltip_x                                       0x8B93C0
#define CXWnd__DrawTooltipAtPoint_x                                0x8BDB00
#define CXWnd__GetBorderFrame_x                                    0x8B9830
#define CXWnd__GetChildWndAt_x                                     0x8BF8F0
#define CXWnd__GetClientClipRect_x                                 0x8B95E0
#define CXWnd__GetScreenClipRect_x                                 0x8BE200
#define CXWnd__GetScreenRect_x                                     0x8B9A00
#define CXWnd__GetTooltipRect_x                                    0x8B9250
#define CXWnd__GetWindowTextA_x                                    0x424600
#define CXWnd__IsActive_x                                          0x8B43A0
#define CXWnd__IsDescendantOf_x                                    0x8B9770
#define CXWnd__IsReallyVisible_x                                   0x8BCB30
#define CXWnd__IsType_x                                            0x8EC4B0
#define CXWnd__Move_x                                              0x8BC230
#define CXWnd__Move1_x                                             0x8BE830
#define CXWnd__ProcessTransition_x                                 0x8B8CF0
#define CXWnd__Refade_x                                            0x8B8AC0
#define CXWnd__Resize_x                                            0x8B9AD0
#define CXWnd__Right_x                                             0x8BE000
#define CXWnd__SetFocus_x                                          0x8BB370
#define CXWnd__SetFont_x                                           0x8B8960
#define CXWnd__SetKeyTooltip_x                                     0x8B9D40
#define CXWnd__SetMouseOver_x                                      0x8BE530
#define CXWnd__StartFade_x                                         0x8B8D90
#define CXWnd__GetChildItem_x                                      0x8BE470
#define CXWnd__SetParent_x                                         0x8BF8A0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B5C40
#define CXWndManager__DrawWindows_x                                0x8B5890
#define CXWndManager__GetKeyboardFlags_x                           0x8B3ED0
#define CXWndManager__HandleKeyboardMsg_x                          0x8B4840
#define CXWndManager__RemoveWnd_x                                  0x8B4530

// CDBStr
#define CDBStr__GetString_x                                        0x4ABB20

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44DF90
#define EQ_Character__Cur_HP_x                                     0x462C90
#define EQ_Character__Cur_Mana_x                                   0x456760
#define EQ_Character__GetAACastingTimeModifier_x                   0x4471E0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F4B0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F510
#define EQ_Character__GetHPRegen_x                                 0x465EA0
#define EQ_Character__GetEnduranceRegen_x                          0x4620B0
#define EQ_Character__GetManaRegen_x                               0x466440
#define EQ_Character__Max_Endurance_x                              0x5BB820
#define EQ_Character__Max_HP_x                                     0x4593E0
#define EQ_Character__Max_Mana_x                                   0x5BB650
#define EQ_Character__doCombatAbility_x                            0x5B8D40
#define EQ_Character__UseSkill_x                                   0x46D120
#define EQ_Character__GetConLevel_x                                0x5AE2F0
#define EQ_Character__IsExpansionFlag_x                            0x423B50
#define EQ_Character__TotalEffect_x                                0x44B230
#define EQ_Character__GetPCSpellAffect_x                           0x4475E0
#define EQ_Character__SpellDuration_x                              0x4454E0
#define EQ_Character__FindItemByRecord_x                           0x460110
#define EQ_Character__GetAdjustedSkill_x                           0x463440
#define EQ_Character__GetBaseSkill_x                               0x4592C0

//ProfileManager_
#define ProfileManager__GetCurrentProfile_x                        0x85FFE0

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5C3800

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442810
#define CCharacterSelect__EnterWorld_x                             0x441FE0
#define CCharacterSelect__Quit_x                                   0x440BC0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58E940
#define EQ_Item__CreateItemTagString_x                             0x841940
#define EQ_Item__IsStackable_x                                     0x8373A0
#define EQ_Item__GetImageNum_x                                     0x839DA0
#define EQ_Item__CreateItemClient_x                                0x58F540
#define EQ_Item__GetItemValue_x                                    0x840620
#define EQ_Item__ValueSellMerchant_x                               0x842BE0
#define EQ_Item__IsKeyRingItem_x                                   0x837DD0
#define EQ_Item__CanGoInBag_x                                      0x58EAD0
#define EQ_Item__GetMaxItemCount_x                                 0x837290
#define EQ_Item__GetHeldItem_x                                     0x838BB0
#define EQ_Item__GetAugmentFitBySlot_x                             0x842A10

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4CB930
#define EQ_LoadingS__Array_x                                       0xBEFBB0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BDCB0
#define EQ_PC__GetAlternateAbilityId_x                             0x84B060
#define EQ_PC__GetCombatAbility_x                                  0x84B0F0
#define EQ_PC__GetCombatAbilityTimer_x                             0x845D70
#define EQ_PC__GetItemRecastTimer_x                                0x5B73F0
#define EQ_PC__HasLoreItem_x                                       0x5B1900
#define EQ_PC__AlertInventoryChanged_x                             0x5AE2C0
#define EQ_PC__GetPcZoneClient_x                                   0x5D7C60
#define EQ_PC__RemoveMyAffect_x                                    0x5B68C0
#define EQ_PC__GetKeyRingItems_x                                   0x846190
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x858A00
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x84CFB0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x517100
#define EQItemList__add_object_x                                   0x543C60
#define EQItemList__add_item_x                                     0x517040
#define EQItemList__delete_item_x                                  0x5174F0
#define EQItemList__FreeItemList_x                                 0x5173F0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4AADD0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C35A0
#define EQPlayer__dEQPlayer_x                                      0x5CBB40
#define EQPlayer__DoAttack_x                                       0x5DDB60
#define EQPlayer__EQPlayer_x                                       0x5CE250
#define EQPlayer__SetNameSpriteState_x                             0x5C8AB0
#define EQPlayer__SetNameSpriteTint_x                              0x5C49B0
#define PlayerBase__HasProperty_j_x                                0x91D2D0
#define EQPlayer__IsTargetable_x                                   0x91D570
#define EQPlayer__CanSee_x                                         0x91DAD0
#define PlayerZoneClient__ChangeHeight_x                           0x5DDA20
#define EQPlayer__CanSeeTargetIndicator_x                          0x91DBC0
#define PlayerBase__GetVisibilityLineSegment_x                     0x91D860

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D22B0
#define EQPlayerManager__GetSpawnByName_x                          0x5D2710
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D22E0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x594AF0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x594B30
#define KeypressHandler__ClearCommandStateArray_x                  0x5946E0
#define KeypressHandler__HandleKeyDown_x                           0x593040
#define KeypressHandler__HandleKeyUp_x                             0x593360
#define KeypressHandler__SaveKeymapping_x                          0x5947B0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x702130
#define MapViewMap__SaveEx_x                                       0x705460

#define PlayerPointManager__GetAltCurrency_x                       0x85E0D0

// StringTable 
#define StringTable__getString_x                                   0x858D30

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BB2B0
#define PcZoneClient__RemovePetEffect_x                            0x5B78C0
#define PcZoneClient__HasAlternateAbility_x                        0x5B8260
#define PcZoneClient__GetCurrentMod_x                              0x458780
#define PcZoneClient__GetModCap_x                                  0x455EE0
#define PcZoneClient__CanEquipItem_x                               0x5B8810
#define PcZoneClient__GetItemByID_x                                0x5BD0A0
#define PcZoneClient__GetItemByItemClass_x                         0x5BDBD0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54B550

//IconCache
#define IconCache__GetIcon_x                                       0x69EF10

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x695DE0
#define CContainerMgr__CloseContainer_x                            0x696600

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x763020

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x587B30

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E5E20
#define EQ_Spell__SpellAffects_x                                   0x4E34D0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E3540
#define CharacterZoneClient__CalcAffectChange_x                    0x446610
#define CLootWnd__LootAll_x                                        0x6F7AD0
#define CLootWnd__RequestLootSlot_x                                0x6F82E0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AA070
#define CTargetWnd__WndNotification_x                              0x7A9B60
#define CTargetWnd__RefreshTargetBuffs_x                           0x7AA250

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AF170

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DEB90

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x49A7B0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8D7EE0
#define CSidlManager__FindAnimation1_x                             0x8CD2B0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D32F0
#define CAltAbilityData__GetMercMaxRank_x                          0x4D32A0
#define CAltAbilityData__GetMaxRank_x                              0x4C79E0

//CTargetRing
#define CTargetRing__Cast_x                                        0x585410

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454E00
#define CharacterBase__CreateItemGlobalIndex_x                     0x471EF0
#define CharacterBase__CreateItemIndex_x                           0x510700
#define CharacterBase__GetItemPossession_x                         0x4400C0
#define CharacterBase__GetItemByGlobalIndex_x                      0x86E270

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x67F700
#define CCastSpellWnd__IsBardSongPlaying_x                         0x67EE60

//messages
#define msg_spell_worn_off_x                                       0x4ED990
#define msg_new_text_x                                             0x4F6F50
#define msgTokenTextParam_x                                        0x4F37B0

//SpellManager
#define SpellManager__vftable_x                                    0xAB1070
#define SpellManager__SpellManager_x                               0x47AD90
#define Spellmanager__CheckSpellRequirementAssociations_x          0x5FC230

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x921610

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E9EF0
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43AC30
#define ItemGlobalIndex__IsEquippedLocation_x                      0x444E80
#define ItemGlobalIndex__IsValidIndex_x                            0x4546D0

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x86C080
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x86AFC0

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F0AE0

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x69AB20
#define CCursorAttachment__Deactivate_x                            0x69A060
