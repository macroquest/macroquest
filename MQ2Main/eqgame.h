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
#define __ExpectedVersionDate                                     "Mar 10 2017"
#define __ExpectedVersionTime                                     "09:33:14"
#define __ActualVersionDate_x                                      0xACACC8
#define __ActualVersionTime_x                                      0xACACD4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuest2Tray(Live)"
#define __MacroQuestWinName                                       "MacroQuest2(Live)"

// Memory Protection
#define __MemChecker0_x                                            0x599E80
#define __MemChecker1_x                                            0x8904F0
#define __MemChecker2_x                                            0x630130
#define __MemChecker3_x                                            0x630080
#define __MemChecker4_x                                            0x7E31E0
#define __EncryptPad0_x                                            0xC24328
#define __EncryptPad1_x                                            0xCFFC90
#define __EncryptPad2_x                                            0xC4D9A8
#define __EncryptPad3_x                                            0xC4D5A8
#define __EncryptPad4_x                                            0xCEE2B0
#define __EncryptPad5_x                                            0x10A8898
#define __AC1_x                                                    0x7A2B55
#define __AC2_x                                                    0x553F47
#define __AC3_x                                                    0x5520E0
#define __AC4_x                                                    0x5644A0
#define __AC5_x                                                    0x57725B
#define __AC6_x                                                    0x57AE0E
#define __AC7_x                                                    0x57185C
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
#define __do_loot_x                                                0x522B90
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
#define pinstCAlarmWnd_x                                           0xE5620C
#define pinstCGroupSearchFiltersWnd_x                              0xE56204
#define pinstCLoadskinWnd_x                                        0xE56208
#define pinstCLargeDialogWnd_x                                     0x10AF578
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
#define __CastRay_x                                                0x539E30
#define __ConvertItemTags_x                                        0x527690
#define __ExecuteCmd_x                                             0x511FB0
#define __EQGetTime_x                                              0x890180
#define __get_melee_range_x                                        0x518BF0
#define __GetGaugeValueFromEQ_x                                    0x7A1710
#define __GetLabelFromEQ_x                                         0x7A2AE0
#define __ToggleKeyRingItem_x                                      0x481F40
#define __GetXTargetType_x                                         0x920890
#define __LoadFrontEnd_x                                           0x62F800
#define __NewUIINI_x                                               0x7A10E0
#define __ProcessGameEvents_x                                      0x5735F0
#define __ProcessMouseEvent_x                                      0x572D90
#define CrashDetected_x                                            0x6311C0
#define wwsCrashReportCheckForUploader_x                           0x7EF1C0
#define __AppCrashWrapper_x                                        0xC4D59C
#define __pCrashHandler_x                                          0x10BDB08
#define __CrashHandler_x                                           0x7EEC20
#define wwsCrashReportPlatformLaunchUploader_x                     0x7F13C0
#define DrawNetStatus_x                                            0x5A9B10
#define Util__FastTime_x                                           0x88FE20
#define Expansion_HoT_x                                            0xF17FA8
#define __HelpPath_x                                               0xF9B6B0
#define __STMLToText_x                                             0x8D5E80

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420440
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B1E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41AFC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C9410
#define AltAdvManager__IsAbilityReady_x                            0x4C9480
#define AltAdvManager__GetAAById_x                                 0x4C9970
#define AltAdvManager__CanTrainAbility_x                           0x4CA5A0
#define AltAdvManager__CanSeeAbility_x                             0x4CA160

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4637B0
#define CharacterZoneClient__MakeMeVisible_x                       0x4681C0
#define CharacterZoneClient__IsStackBlocked_x                      0x447B80
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x447040
#define CharacterZoneClient__GetItemCountWorn_x                    0x461540
#define CharacterZoneClient__GetItemCountInInventory_x             0x461620
#define CharacterZoneClient__GetCursorItemCount_x                  0x461700
#define CharacterZoneClient__FindAffectSlot_x                      0x44D090

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65F0F0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66D4B0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x588DB0
#define CButtonWnd__CButtonWnd_x                                   0x8CA220

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x688520
#define CChatManager__InitContextMenu_x                            0x689670
#define CChatManager__FreeChatWindow_x                             0x688000
#define CChatManager__GetLockedActiveChatWindow_x                  0x690E00
#define CChatManager__SetLockedActiveChatWindow_x                  0x6884F0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D41E0
#define CContextMenu__dCContextMenu_x                              0x8D43F0
#define CContextMenu__AddMenuItem_x                                0x8D4400
#define CContextMenu__RemoveMenuItem_x                             0x8D46F0
#define CContextMenu__RemoveAllMenuItems_x                         0x8D4710
#define CContextMenu__CheckMenuItem_x                              0x8D4790

//CContextMenuManager
#define CContextMenuManager__AddMenu_x                             0x8C0770
#define CContextMenuManager__RemoveMenu_x                          0x8C0B10
#define CContextMenuManager__PopupMenu_x                           0x8C0F60
#define CContextMenuManager__Flush_x                               0x8C07E0
#define CContextMenuManager__GetMenu_x                             0x4168C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x874710
#define CChatService__GetFriendName_x                              0x874720

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68F170
#define CChatWindow__Clear_x                                       0x68EA50
#define CChatWindow__WndNotification_x                             0x68F6B0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C45C0
#define CComboWnd__Draw_x                                          0x8C47D0
#define CComboWnd__GetCurChoice_x                                  0x8C4370
#define CComboWnd__GetListRect_x                                   0x8C4A70
#define CComboWnd__GetTextRect_x                                   0x8C4630
#define CComboWnd__InsertChoice_x                                  0x8C4AE0
#define CComboWnd__SetColors_x                                     0x8C4300
#define CComboWnd__SetChoice_x                                     0x8C4330
#define CComboWnd__GetItemCount_x                                  0x8C4360
#define CComboWnd__GetCurChoiceText_x                              0x8C43B0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x698AA0
#define CContainerWnd__vftable_x                                   0xAD48B0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B77F0
#define CDisplay__GetClickedActor_x                                0x4B0120
#define CDisplay__GetUserDefinedColor_x                            0x4AED00
#define CDisplay__GetWorldFilePath_x                               0x4AE150
#define CDisplay__is3dON_x                                         0x4AD5E0
#define CDisplay__ReloadUI_x                                       0x4C2DC0
#define CDisplay__WriteTextHD2_x                                   0x4B3BB0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EA820

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D8730
#define CEditWnd__GetCharIndexPt_x                                 0x8D97C0
#define CEditWnd__GetDisplayString_x                               0x8D88E0
#define CEditWnd__GetHorzOffset_x                                  0x8D8C20
#define CEditWnd__GetLineForPrintableChar_x                        0x8D9290
#define CEditWnd__GetSelStartPt_x                                  0x8D9A70
#define CEditWnd__GetSTMLSafeText_x                                0x8D8DC0
#define CEditWnd__PointFromPrintableChar_x                         0x8D9380
#define CEditWnd__SelectableCharFromPoint_x                        0x8D9500
#define CEditWnd__SetEditable_x                                    0x8D8D90

// CEverQuest 
#define CEverQuest__DoPercentConvert_x                             0x55ACD0
#define CEverQuest__ClickedPlayer_x                                0x554690
#define CEverQuest__CreateTargetIndicator_x                        0x555580
#define CEverQuest__DeleteTargetIndicator_x                        0x555600
#define CEverQuest__DoTellWindow_x                                 0x472E10
#define CEverQuest__OutputTextToLog_x                              0x472A70
#define CEverQuest__DropHeldItemOnGround_x                         0x56B2F0
#define CEverQuest__dsp_chat_x                                     0x473150
#define CEverQuest__trimName_x                                     0x550FE0
#define CEverQuest__Emote_x                                        0x569640
#define CEverQuest__EnterZone_x                                    0x564630
#define CEverQuest__GetBodyTypeDesc_x                              0x54EA40
#define CEverQuest__GetClassDesc_x                                 0x557E10
#define CEverQuest__GetClassThreeLetterCode_x                      0x558410
#define CEverQuest__GetDeityDesc_x                                 0x54F320
#define CEverQuest__GetLangDesc_x                                  0x54EDD0
#define CEverQuest__GetRaceDesc_x                                  0x5585D0
#define CEverQuest__InterpretCmd_x                                 0x55C450
#define CEverQuest__LeftClickedOnPlayer_x                          0x56FCB0
#define CEverQuest__LMouseUp_x                                     0x571DB0
#define CEverQuest__RightClickedOnPlayer_x                         0x5707C0
#define CEverQuest__RMouseUp_x                                     0x571810
#define CEverQuest__SetGameState_x                                 0x554F50
#define CEverQuest__UPCNotificationFlush_x                         0x54C850
#define CEverQuest__IssuePetCommand_x                              0x55CE30

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A9640
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A96A0
#define CGaugeWnd__Draw_x                                          0x6A9AD0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4372E0
#define CGuild__GetGuildName_x                                     0x4377B0
#define CGuild__GetGuildIndex_x                                    0x438980

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C5BC0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D2D20
#define CInvSlotMgr__MoveItem_x                                    0x6D3BD0
#define CInvSlotMgr__SelectSlot_x                                  0x6D2DD0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D21D0
#define CInvSlot__SliderComplete_x                                 0x6CF9E0
#define CInvSlot__GetItemBase_x                                    0x6CEE80
#define CInvSlot__UpdateItem_x                                     0x6CF400

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D4FF0
#define CInvSlotWnd__CInvSlotWnd_x                                 0x6D6100

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79D100
#define CItemDisplayWnd__UpdateStrings_x                           0x6D7160
#define CItemDisplayWnd__InsertAugmentRequest_x                    0x6E3C80
#define CItemDisplayWnd__RemoveAugmentRequest_x                    0x6E41A0
#define CItemDisplayWnd__SetItem_x                                 0x6E9C10

//CWndDisplayManager
#define CWndDisplayManager__FindWindowA_x                          0x7D4500

//CItemDisplayManager
#define CItemDisplayManager__CreateWindowInstance_x                0x6DD790

// CLabel 
#define CLabel__Draw_x                                             0x6F08B0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B0200
#define CListWnd__dCListWnd_x                                      0x8B1430
#define CListWnd__AddColumn_x                                      0x8B13D0
#define CListWnd__AddColumn1_x                                     0x8B0A60
#define CListWnd__AddLine_x                                        0x8B04C0
#define CListWnd__AddString_x                                      0x8B06E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8AD490
#define CListWnd__CalculateVSBRange_x                              0x8AF6D0
#define CListWnd__ClearSel_x                                       0x8AC7A0
#define CListWnd__ClearAllSel_x                                    0x8AC750
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B0090
#define CListWnd__Compare_x                                        0x8AE000
#define CListWnd__Draw_x                                           0x8AF2D0
#define CListWnd__DrawColumnSeparators_x                           0x8AF160
#define CListWnd__DrawHeader_x                                     0x8ACA60
#define CListWnd__DrawItem_x                                       0x8AE690
#define CListWnd__DrawLine_x                                       0x8AEE00
#define CListWnd__DrawSeparator_x                                  0x8AF200
#define CListWnd__EnableLine_x                                     0x8AC980
#define CListWnd__EnsureVisible_x                                  0x8AD5F0
#define CListWnd__ExtendSel_x                                      0x8AE5A0
#define CListWnd__GetColumnMinWidth_x                              0x8AC150
#define CListWnd__GetColumnWidth_x                                 0x8AC080
#define CListWnd__GetCurSel_x                                      0x8AB850
#define CListWnd__GetItemAtPoint_x                                 0x8AD880
#define CListWnd__GetItemAtPoint1_x                                0x8AD8F0
#define CListWnd__GetItemData_x                                    0x8ABB90
#define CListWnd__GetItemHeight_x                                  0x8AD0E0
#define CListWnd__GetItemIcon_x                                    0x8ABD80
#define CListWnd__GetItemRect_x                                    0x8AD6C0
#define CListWnd__GetItemText_x                                    0x8ABC30
#define CListWnd__GetSelList_x                                     0x8B0950
#define CListWnd__GetSeparatorRect_x                               0x8ADF20
#define CListWnd__InsertLine_x                                     0x8B08C0
#define CListWnd__RemoveLine_x                                     0x8B08D0
#define CListWnd__SetColors_x                                      0x8AB9A0
#define CListWnd__SetColumnJustification_x                         0x8AC3E0
#define CListWnd__SetColumnWidth_x                                 0x8AC100
#define CListWnd__SetCurSel_x                                      0x8AB890
#define CListWnd__SetItemColor_x                                   0x8AFD80
#define CListWnd__SetItemData_x                                    0x8AC800
#define CListWnd__SetItemText_x                                    0x8AFBC0
#define CListWnd__ShiftColumnSeparator_x                           0x8AFA50
#define CListWnd__Sort_x                                           0x8B1530
#define CListWnd__ToggleSel_x                                      0x8AC6D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x709900

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72ADB0
#define CMerchantWnd__RequestBuyItem_x                             0x731E50
#define CMerchantWnd__RequestSellItem_x                            0x732920
#define CMerchantWnd__SelectRecoverySlot_x                         0x72B060
#define CMerchantWnd__SelectBuySellSlot_x                          0x72A260
#define CMerchantWnd__ActualSelect_x                               0x72ED30

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x842EF0
#define CPacketScrambler__hton_x                                   0x842F00

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate_x                    0x8CF0A0
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8CF180
#define CSidlManager__CreateLabel_x                                0x793000
#define CSidlManager__CreateXWndFromTemplate_x                     0x8CD640
#define CSidlManager__CreateXWndFromTemplate1_x                    0x8CF460

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x6564E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x656410
#define CSidlScreenWnd__ConvertToRes_x                             0x8EA700
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C6F60
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C8140
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C81F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C76C0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C6910
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C6090
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C6B00
#define CSidlScreenWnd__Init1_x                                    0x8C7E10
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C7010
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C6250
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C7900
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C5CE0
#define CSidlScreenWnd__StoreIniVis_x                              0x8C6040
#define CSidlScreenWnd__WndNotification_x                          0x8C7B90
#define CSidlScreenWnd__GetChildItem_x                             0x8C6160
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B9960
#define CSidlScreenWnd__m_layoutCopy_x                             0x17145E8

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F5030
#define CSkillMgr__GetSkillCap_x                                   0x5F5210
#define CSkillMgr__GetNameToken_x                                  0x5F4C50

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E99C0
#define CSliderWnd__SetValue_x                                     0x8E9B90
#define CSliderWnd__SetNumTicks_x                                  0x8EA310

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79AD60

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E5390
#define CStmlWnd__CalculateHSBRange_x                              0x8DD970
#define CStmlWnd__CalculateVSBRange_x                              0x8DD8E0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8DDAF0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8DE3D0
#define CStmlWnd__ForceParseNow_x                                  0x8E5CE0
#define CStmlWnd__GetNextTagPiece_x                                0x8DE2D0
#define CStmlWnd__GetSTMLText_x                                    0x690DC0
#define CStmlWnd__GetVisibleText_x                                 0x8DEE20
#define CStmlWnd__InitializeWindowVariables_x                      0x8E11A0
#define CStmlWnd__MakeStmlColorTag_x                               0x8DCBE0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8DCC40
#define CStmlWnd__SetSTMLText_x                                    0x8E29F0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E5030
#define CStmlWnd__UpdateHistoryString_x                            0x8DFD60

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8DC2F0
#define CTabWnd__DrawCurrentPage_x                                 0x8DBB80
#define CTabWnd__DrawTab_x                                         0x8DB940
#define CTabWnd__GetCurrentPage_x                                  0x8DBF30
#define CTabWnd__GetPageInnerRect_x                                0x8DB630
#define CTabWnd__GetTabInnerRect_x                                 0x8DB830
#define CTabWnd__GetTabRect_x                                      0x8DB700
#define CTabWnd__InsertPage_x                                      0x8DC5E0
#define CTabWnd__SetPage_x                                         0x8DBF60
#define CTabWnd__SetPageRect_x                                     0x8DC230
#define CTabWnd__UpdatePage_x                                      0x8DC580
#define CTabWnd__GetPageFromTabIndex_x                             0x8DB890
#define CTabWnd__GetCurrentTabIndex_x                              0x8DB5C0

// CPageWnd 
#define CPageWnd__GetTabText_x                                     0x6D62B0
#define CPageWnd__SetTabText_x                                     0x8F36E0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432F20

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C3F70
#define CTextureFont__GetTextExtent_x                              0x8C3CD0

//CWebManager
#define CWebManager__CreateHtmlWnd_x                               0x62DA80

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EFB20

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A9AA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x596320
#define CXStr__CXStr1_x                                            0x8AAA70
#define CXStr__CXStr3_x                                            0x88D0C0
#define CXStr__dCXStr_x                                            0x792FB0
#define CXStr__operator_equal_x                                    0x88D230
#define CXStr__operator_equal1_x                                   0x88D280
#define CXStr__operator_plus_equal1_x                              0x88E380

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B8B90
#define CXWnd__Center_x                                            0x8BED60
#define CXWnd__ClrFocus_x                                          0x8B8780
#define CXWnd__Destroy_x                                           0x8BF820
#define CXWnd__DoAllDrawing_x                                      0x8BE9B0
#define CXWnd__DrawChildren_x                                      0x8BEB50
#define CXWnd__DrawColoredRect_x                                   0x8B8F70
#define CXWnd__DrawTooltip_x                                       0x8B9210
#define CXWnd__DrawTooltipAtPoint_x                                0x8BD900
#define CXWnd__GetBorderFrame_x                                    0x8B9670
#define CXWnd__GetChildWndAt_x                                     0x8BF710
#define CXWnd__GetClientClipRect_x                                 0x8B9430
#define CXWnd__GetScreenClipRect_x                                 0x8BE000
#define CXWnd__GetScreenRect_x                                     0x8B9800
#define CXWnd__GetTooltipRect_x                                    0x8B90A0
#define CXWnd__GetWindowTextA_x                                    0x424520
#define CXWnd__IsActive_x                                          0x8B4200
#define CXWnd__IsDescendantOf_x                                    0x8B95C0
#define CXWnd__IsReallyVisible_x                                   0x8BC950
#define CXWnd__IsType_x                                            0x8EC360
#define CXWnd__Move_x                                              0x8BC030
#define CXWnd__Move1_x                                             0x8BE650
#define CXWnd__ProcessTransition_x                                 0x8B8B40
#define CXWnd__Refade_x                                            0x8B8920
#define CXWnd__Resize_x                                            0x8B98C0
#define CXWnd__Right_x                                             0x8BDE00
#define CXWnd__SetFocus_x                                          0x8BB1A0
#define CXWnd__SetFont_x                                           0x8B87D0
#define CXWnd__SetKeyTooltip_x                                     0x8B9B30
#define CXWnd__SetMouseOver_x                                      0x8BE340
#define CXWnd__StartFade_x                                         0x8B8BE0
#define CXWnd__GetChildItem_x                                      0x8BE280
#define CXWnd__SetParent_x                                         0x8BF6C0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B5A90
#define CXWndManager__DrawWindows_x                                0x8B56E0
#define CXWndManager__GetKeyboardFlags_x                           0x8B3D70
#define CXWndManager__HandleKeyboardMsg_x                          0x8B4690
#define CXWndManager__RemoveWnd_x                                  0x8B4390

// CDBStr
#define CDBStr__GetString_x                                        0x4ABAE0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E100
#define EQ_Character__Cur_HP_x                                     0x462DB0
#define EQ_Character__Cur_Mana_x                                   0x456860
#define EQ_Character__GetAACastingTimeModifier_x                   0x447350
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F5E0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F640
#define EQ_Character__GetHPRegen_x                                 0x465FC0
#define EQ_Character__GetEnduranceRegen_x                          0x4621D0
#define EQ_Character__GetManaRegen_x                               0x466560
#define EQ_Character__Max_Endurance_x                              0x5BB8E0
#define EQ_Character__Max_HP_x                                     0x4594E0
#define EQ_Character__Max_Mana_x                                   0x5BB710
#define EQ_Character__doCombatAbility_x                            0x5B8E00
#define EQ_Character__UseSkill_x                                   0x46D240
#define EQ_Character__GetConLevel_x                                0x5AE140
#define EQ_Character__IsExpansionFlag_x                            0x423A50
#define EQ_Character__TotalEffect_x                                0x44B3A0
#define EQ_Character__GetPCSpellAffect_x                           0x447750
#define EQ_Character__SpellDuration_x                              0x445650
#define EQ_Character__FindItemByRecord_x                           0x460210
#define EQ_Character__GetAdjustedSkill_x                           0x463560
#define EQ_Character__GetBaseSkill_x                               0x4593C0

//ProfileManager
#define ProfileManager__GetCurrentProfile_x                        0x860170

//PlayerClient (to us known as EQPlayer)
#define PlayerClient__GetPcClient_x                                0x5C3880

//CCharacterSelect
#define CCharacterSelect__SelectCharacter_x                        0x442930
#define CCharacterSelect__EnterWorld_x                             0x442100
#define CCharacterSelect__Quit_x                                   0x440CF0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58E630
#define EQ_Item__CreateItemTagString_x                             0x841880
#define EQ_Item__IsStackable_x                                     0x837120
#define EQ_Item__GetImageNum_x                                     0x839B60
#define EQ_Item__CreateItemClient_x                                0x58F210
#define EQ_Item__GetItemValue_x                                    0x8405E0
#define EQ_Item__ValueSellMerchant_x                               0x842B80
#define EQ_Item__IsKeyRingItem_x                                   0x837B60
#define EQ_Item__CanGoInBag_x                                      0x58E7C0
#define EQ_Item__GetMaxItemCount_x                                 0x837010
#define EQ_Item__GetHeldItem_x                                     0x838990
#define EQ_Item__GetAugmentFitBySlot_x                             0x8429B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4CB9F0
#define EQ_LoadingS__Array_x                                       0xBEFBB0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BDD70
#define EQ_PC__GetAlternateAbilityId_x                             0x84B000
#define EQ_PC__GetCombatAbility_x                                  0x84B090
#define EQ_PC__GetCombatAbilityTimer_x                             0x845D00
#define EQ_PC__GetItemRecastTimer_x                                0x5B74B0
#define EQ_PC__HasLoreItem_x                                       0x5B1770
#define EQ_PC__AlertInventoryChanged_x                             0x5AE110
#define EQ_PC__GetPcZoneClient_x                                   0x5D7D60
#define EQ_PC__RemoveMyAffect_x                                    0x5B6980
#define EQ_PC__GetKeyRingItems_x                                   0x846120
#define EQ_PC__GetItemContainedRealEstateIds_x                     0x8589F0
#define EQ_PC__GetNonArchivedOwnedRealEstates_x                    0x84CFA0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x516C80
#define EQItemList__add_object_x                                   0x5437E0
#define EQItemList__add_item_x                                     0x516BC0
#define EQItemList__delete_item_x                                  0x517070
#define EQItemList__FreeItemList_x                                 0x516F70

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4AADE0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C3620
#define EQPlayer__dEQPlayer_x                                      0x5CBBE0
#define EQPlayer__DoAttack_x                                       0x5DDC40
#define EQPlayer__EQPlayer_x                                       0x5CE2F0
#define EQPlayer__SetNameSpriteState_x                             0x5C8B30
#define EQPlayer__SetNameSpriteTint_x                              0x5C4A30
#define PlayerBase__HasProperty_j_x                                0x91D0E0
#define EQPlayer__IsTargetable_x                                   0x91D380
#define EQPlayer__CanSee_x                                         0x91D8E0
#define PlayerZoneClient__ChangeHeight_x                           0x5DDB00
#define EQPlayer__CanSeeTargetIndicator_x                          0x91D9D0
#define PlayerBase__GetVisibilityLineSegment_x                     0x91D670

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D23B0
#define EQPlayerManager__GetSpawnByName_x                          0x5D2810
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D23E0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5946C0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x594700
#define KeypressHandler__ClearCommandStateArray_x                  0x5942B0
#define KeypressHandler__HandleKeyDown_x                           0x592C10
#define KeypressHandler__HandleKeyUp_x                             0x592F30
#define KeypressHandler__SaveKeymapping_x                          0x594380

// MapViewMap 
#define MapViewMap__Clear_x                                        0x702290
#define MapViewMap__SaveEx_x                                       0x7055C0

#define PlayerPointManager__GetAltCurrency_x                       0x85E180

// StringTable 
#define StringTable__getString_x                                   0x858D20

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BB370
#define PcZoneClient__RemovePetEffect_x                            0x5B7980
#define PcZoneClient__HasAlternateAbility_x                        0x5B8320
#define PcZoneClient__GetCurrentMod_x                              0x458880
#define PcZoneClient__GetModCap_x                                  0x455FE0
#define PcZoneClient__CanEquipItem_x                               0x5B88D0
#define PcZoneClient__GetItemByID_x                                0x5BD160
#define PcZoneClient__GetItemByItemClass_x                         0x5BDC90

//Doors
#define EQSwitch__UseSwitch_x                                      0x54B0E0

//IconCache
#define IconCache__GetIcon_x                                       0x69EF50

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x695E50
#define CContainerMgr__CloseContainer_x                            0x696670

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x762FD0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x587820

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E5A60
#define EQ_Spell__SpellAffects_x                                   0x4E3110
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4E3180
#define CharacterZoneClient__CalcAffectChange_x                    0x446780
#define CLootWnd__LootAll_x                                        0x6F7B90
#define CLootWnd__RequestLootSlot_x                                0x6F83A0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AA030
#define CTargetWnd__WndNotification_x                              0x7A9B20
#define CTargetWnd__RefreshTargetBuffs_x                           0x7AA210

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AF120

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4DE7B0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x49A750

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8D7D60
#define CSidlManager__FindAnimation1_x                             0x8CD070

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4D30B0
#define CAltAbilityData__GetMercMaxRank_x                          0x4D3060
#define CAltAbilityData__GetMaxRank_x                              0x4C7AC0

//CTargetRing
#define CTargetRing__Cast_x                                        0x585100

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454F50
#define CharacterBase__CreateItemGlobalIndex_x                     0x472010
#define CharacterBase__CreateItemIndex_x                           0x510210
#define CharacterBase__GetItemPossession_x                         0x4401C0
#define CharacterBase__GetItemByGlobalIndex_x                      0x86E3E0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x67F660
#define CCastSpellWnd__IsBardSongPlaying_x                         0x67EDC0

//messages
#define msg_spell_worn_off_x                                       0x4ED5D0
#define msg_new_text_x                                             0x4F6B90
#define msgTokenTextParam_x                                        0x4F33F0

//SpellManager
#define SpellManager__vftable_x                                    0xAB1070
#define SpellManager__SpellManager_x                               0x47AD80
#define Spellmanager__CheckSpellRequirementAssociations_x          0x5FBEE0

//CCollisionInfoTargetVisibility
#define CCollisionInfoTargetVisibility__CCollisionInfoTargetVisibility_x   0x9213B0

//ItemGlobalIndex
#define ItemGlobalIndex__IsKeyRingLocation_x                       0x4E9B40
#define ItemGlobalIndex__ItemGlobalIndex_x                         0x43AD60
#define ItemGlobalIndex__IsEquippedLocation_x                      0x444FA0
#define ItemGlobalIndex__IsValidIndex_x                            0x454820

//ItemBaseContainer
#define ItemBaseContainer__ItemBaseContainer_x                     0x86C200
#define ItemBaseContainer__CreateItemGlobalIndex_x                 0x86B140

//CLargeDialogWnd
#define CLargeDialogWnd__Open_x                                    0x6F0B00

//CCursorAttachment
#define CCursorAttachment__AttachToCursor_x                        0x69AB40
#define CCursorAttachment__Deactivate_x                            0x69A090
