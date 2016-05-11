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
#elif defined(TEST)
#include "eqgame-private(test).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "May  6 2016"
#define __ExpectedVersionTime                                     "17:12:17"
#define __ActualVersionDate_x                                      0xACBFE8
#define __ActualVersionTime_x                                      0xACBFF4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59C3E0
#define __MemChecker1_x                                            0x8950F0
#define __MemChecker2_x                                            0x632790
#define __MemChecker3_x                                            0x6326E0
#define __MemChecker4_x                                            0x7E44B0
#define __EncryptPad0_x                                            0xC6A828
#define __EncryptPad1_x                                            0xDF50A8
#define __EncryptPad2_x                                            0xCB32E8
#define __EncryptPad3_x                                            0xCB2EE8
#define __EncryptPad4_x                                            0xDCBEB8
#define __EncryptPad5_x                                            0x11A1070
#define __AC1_x                                                    0x7A41E5
#define __AC2_x                                                    0x556517
#define __AC3_x                                                    0x5546B0
#define __AC4_x                                                    0x566EC0
#define __AC5_x                                                    0x57998B
#define __AC6_x                                                    0x57D53E
#define __AC7_x                                                    0x57404C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E4E80

// Direct Input
#define DI8__Main_x                                                0x11A1048
#define DI8__Keyboard_x                                            0x11A104C
#define DI8__Mouse_x                                               0x11A1050
#define DI8__Mouse_Copy_x                                          0x100F7A4
#define DI8__Mouse_Check_x                                         0x1098F34
#define __Attack_x                                                 0x1093C7B
#define __Autofire_x                                               0x1093C7C
#define __BindList_x                                               0xC2C480
#define g_eqCommandStates_x                                        0xFFEC08
#define __Clicks_x                                                 0x100F860
#define __CommandList_x                                            0xC30850
#define __CurrentMapLabel_x                                        0x11A6AA0
#define __CurrentSocial_x                                          0xBE2FB8
#define __DoAbilityList_x                                          0x1045F30
#define __do_loot_x                                                0x51B240
#define __DrawHandler_x                                            0x180D4BC
#define __GroupCount_x                                             0x10001D2

#define __Guilds_x                                                 0x1005DE8
#define __gWorld_x                                                 0x100268C
#define __HotkeyPage_x                                             0x108C930
#define __HWnd_x                                                   0x1098F50
#define __InChatMode_x                                             0x100F78C
#define __LastTell_x                                               0x101162C
#define __LMouseHeldTime_x                                         0x100F8CC
#define __Mouse_x                                                  0x11A1054
#define __MouseLook_x                                              0x100F826
#define __MouseEventTime_x                                         0x109447C
#define __gpbCommandEvent_x                                        0x1002754
#define __NetStatusToggle_x                                        0x100F829
#define __PCNames_x                                                0x1010C50
#define __RangeAttackReady_x                                       0x101098C
#define __RMouseHeldTime_x                                         0x100F8C8
#define __RunWalkState_x                                           0x100F790
#define __ScreenMode_x                                             0xF4E988
#define __ScreenX_x                                                0x100F744
#define __ScreenY_x                                                0x100F740
#define __ScreenXMax_x                                             0x100F748
#define __ScreenYMax_x                                             0x100F74C
#define __ServerHost_x                                             0x100011C
#define __ServerName_x                                             0x1045EF0
#define __ShiftKeyDown_x                                           0x100FE18
#define __ShowNames_x                                              0x1010B4C
#define __Socials_x                                                0x1045FF0
#define __SubscriptionType_x                                       0x11D4B50
#define __TargetAggroHolder_x                                      0x11A8CDC
#define __ZoneType_x                                               0x100FC24
#define __GroupAggro_x                                             0x11A8D1C
#define __LoginName_x                                              0x1097B2C
#define __Inviter_x                                                0x1093BF8
#define __AttackOnAssist_x                                         0x1010B08

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x1002778
#define instEQZoneInfo_x                                           0x100FA1C
#define instKeypressHandler_x                                      0x1094460
#define pinstActiveBanker_x                                        0x1002730
#define pinstActiveCorpse_x                                        0x1002734
#define pinstActiveGMaster_x                                       0x1002738
#define pinstActiveMerchant_x                                      0x100272C
#define pinstAggroInfo_x                                           0xE10CC8
#define pinstAltAdvManager_x                                       0xF4FA48
#define pinstAuraMgr_x                                             0xE1CC50
#define pinstBandageTarget_x                                       0x1002718
#define pinstCamActor_x                                            0xF4F39C
#define pinstCDBStr_x                                              0xF4E91C
#define pinstCDisplay_x                                            0x1002740
#define pinstCEverQuest_x                                          0x11A11C8
#define pinstCharData_x                                            0x10026FC
#define pinstCharSpawn_x                                           0x1002724
#define pinstControlledMissile_x                                   0x10026F8
#define pinstControlledPlayer_x                                    0x1002724
#define pinstCSidlManager_x                                        0x180C9FC
#define pinstCXWndManager_x                                        0x180C9F4
#define instDynamicZone_x                                          0x100F5D8
#define pinstDZMember_x                                            0x100F6E8
#define pinstDZTimerInfo_x                                         0x100F6EC
#define pinstEQItemList_x                                          0xFFEE58
#define pinstEQObjectList_x                                        0xFFFBCC
#define instEQMisc_x                                               0xC06CF8
#define pinstEQSoundManager_x                                      0xF4FFA0
#define instExpeditionLeader_x                                     0x100F622
#define instExpeditionName_x                                       0x100F662
#define pinstGroup_x                                               0x10001CE
#define pinstImeManager_x                                          0x180CA00
#define pinstLocalPlayer_x                                         0x1002710
#define pinstMercenaryData_x                                       0x1094AB0
#define pinstMercenaryStats_x                                      0x11A8E28
#define pinstMercAltAbilities_x                                    0xF4FDD0
#define pinstModelPlayer_x                                         0x100273C
#define pinstPCData_x                                              0x10026FC
#define pinstSkillMgr_x                                            0x10958E8
#define pinstSpawnManager_x                                        0x10951D0
#define pinstSpellManager_x                                        0x1095A30
#define pinstSpellSets_x                                           0x108C994
#define pinstStringTable_x                                         0x10026A4
#define pinstSwitchManager_x                                       0xFFFD60
#define pinstTarget_x                                              0x1002728
#define pinstTargetObject_x                                        0x1002700
#define pinstTargetSwitch_x                                        0x1002704
#define pinstTaskMember_x                                          0xF4E868
#define pinstTrackTarget_x                                         0x100271C
#define pinstTradeTarget_x                                         0x100270C
#define instTributeActive_x                                        0xC06D1D
#define pinstViewActor_x                                           0xF4F398
#define pinstWorldData_x                                           0x10026E0
#define pinstZoneAddr_x                                            0x100FCBC
#define pinstPlayerPath_x                                          0x1095230
#define pinstTargetIndicator_x                                     0x1095BC8
#define pinstCTargetManager_x                                      0x1095C28

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE111C0
#define pinstCAudioTriggersWindow_x                                0xE11050
#define pinstCCharacterSelect_x                                    0xF4F22C
#define pinstCFacePick_x                                           0xF4EFDC
#define pinstCNoteWnd_x                                            0xF4F1E4
#define pinstCBookWnd_x                                            0xF4F1EC
#define pinstCPetInfoWnd_x                                         0xF4F1F0
#define pinstCTrainWnd_x                                           0xF4F1F4
#define pinstCSkillsWnd_x                                          0xF4F1F8
#define pinstCSkillsSelectWnd_x                                    0xF4F1FC
#define pinstCCombatSkillsSelectWnd_x                              0xF4F200
#define pinstCFriendsWnd_x                                         0xF4F204
#define pinstCAuraWnd_x                                            0xF4F208
#define pinstCRespawnWnd_x                                         0xF4F20C
#define pinstCBandolierWnd_x                                       0xF4F210
#define pinstCPotionBeltWnd_x                                      0xF4F214
#define pinstCAAWnd_x                                              0xF4F218
#define pinstCGroupSearchFiltersWnd_x                              0xF4F21C
#define pinstCLoadskinWnd_x                                        0xF4F220
#define pinstCAlarmWnd_x                                           0xF4F224
#define pinstCMusicPlayerWnd_x                                     0xF4F228
#define pinstCMailWnd_x                                            0xF4F230
#define pinstCMailCompositionWnd_x                                 0xF4F234
#define pinstCMailAddressBookWnd_x                                 0xF4F238
#define pinstCRaidWnd_x                                            0xF4F240
#define pinstCRaidOptionsWnd_x                                     0xF4F244
#define pinstCBreathWnd_x                                          0xF4F248
#define pinstCMapViewWnd_x                                         0xF4F24C
#define pinstCMapToolbarWnd_x                                      0xF4F250
#define pinstCEditLabelWnd_x                                       0xF4F254
#define pinstCTargetWnd_x                                          0xF4F258
#define pinstCColorPickerWnd_x                                     0xF4F25C
#define pinstCPlayerWnd_x                                          0xF4F260
#define pinstCOptionsWnd_x                                         0xF4F264
#define pinstCBuffWindowNORMAL_x                                   0xF4F268
#define pinstCBuffWindowSHORT_x                                    0xF4F26C
#define pinstCharacterCreation_x                                   0xF4F270
#define pinstCCursorAttachment_x                                   0xF4F274
#define pinstCCastingWnd_x                                         0xF4F278
#define pinstCCastSpellWnd_x                                       0xF4F27C
#define pinstCSpellBookWnd_x                                       0xF4F280
#define pinstCInventoryWnd_x                                       0xF4F284
#define pinstCBankWnd_x                                            0xF4F28C
#define pinstCQuantityWnd_x                                        0xF4F290
#define pinstCLootWnd_x                                            0xF4F294
#define pinstCActionsWnd_x                                         0xF4F298
#define pinstCCombatAbilityWnd_x                                   0xF4F29C
#define pinstCMerchantWnd_x                                        0xF4F2A0
#define pinstCTradeWnd_x                                           0xF4F2A4
#define pinstCSelectorWnd_x                                        0xF4F2A8
#define pinstCBazaarWnd_x                                          0xF4F2AC
#define pinstCBazaarSearchWnd_x                                    0xF4F2B0
#define pinstCGiveWnd_x                                            0xF4F2CC
#define pinstCTrackingWnd_x                                        0xF4F2D4
#define pinstCInspectWnd_x                                         0xF4F2D8
#define pinstCSocialEditWnd_x                                      0xF4F2DC
#define pinstCFeedbackWnd_x                                        0xF4F2E0
#define pinstCBugReportWnd_x                                       0xF4F2E4
#define pinstCVideoModesWnd_x                                      0xF4F2E8
#define pinstCTextEntryWnd_x                                       0xF4F2F0
#define pinstCFileSelectionWnd_x                                   0xF4F2F4
#define pinstCCompassWnd_x                                         0xF4F2F8
#define pinstCPlayerNotesWnd_x                                     0xF4F2FC
#define pinstCGemsGameWnd_x                                        0xF4F300
#define pinstCTimeLeftWnd_x                                        0xF4F304
#define pinstCPetitionQWnd_x                                       0xF4F320
#define pinstCSoulmarkWnd_x                                        0xF4F324
#define pinstCStoryWnd_x                                           0xF4F328
#define pinstCJournalTextWnd_x                                     0xF4F32C
#define pinstCJournalCatWnd_x                                      0xF4F330
#define pinstCBodyTintWnd_x                                        0xF4F334
#define pinstCServerListWnd_x                                      0xF4F338
#define pinstCAvaZoneWnd_x                                         0xF4F344
#define pinstCBlockedBuffWnd_x                                     0xF4F348
#define pinstCBlockedPetBuffWnd_x                                  0xF4F34C
#define pinstCInvSlotMgr_x                                         0xF4F390
#define pinstCContainerMgr_x                                       0xF4F394
#define pinstCAdventureLeaderboardWnd_x                            0x11A1B78
#define pinstCAdventureRequestWnd_x                                0x11A1BF0
#define pinstCAltStorageWnd_x                                      0x11A1ED0
#define pinstCAdventureStatsWnd_x                                  0x11A1C68
#define pinstCBarterMerchantWnd_x                                  0x11A2AB8
#define pinstCBarterSearchWnd_x                                    0x11A2B30
#define pinstCBarterWnd_x                                          0x11A2BA8
#define pinstCChatManager_x                                        0x11A3238
#define pinstCDynamicZoneWnd_x                                     0x11A36E8
#define pinstCEQMainWnd_x                                          0x11A3880
#define pinstCFellowshipWnd_x                                      0x11A367C
#define pinstCFindLocationWnd_x                                    0x11A3B50
#define pinstCGroupSearchWnd_x                                     0x11A3E20
#define pinstCGroupWnd_x                                           0x11A3E98
#define pinstCGuildBankWnd_x                                       0x11A3F10
#define pinstCGuildMgmtWnd_x                                       0x11A6000
#define pinstCHotButtonWnd_x                                       0x11A60CC
#define pinstCHotButtonWnd1_x                                      0x11A60CC
#define pinstCHotButtonWnd2_x                                      0x11A60D0
#define pinstCHotButtonWnd3_x                                      0x11A60D4
#define pinstCHotButtonWnd4_x                                      0x11A60F8
#define pinstCItemDisplayManager_x                                 0x11A63F0
#define pinstCItemExpTransferWnd_x                                 0x11A646C
#define pinstCLFGuildWnd_x                                         0x11A6748
#define pinstCMIZoneSelectWnd_x                                    0x11A6D30
#define pinstCConfirmationDialog_x                                 0x11A7438
#define pinstCPopupWndManager_x                                    0x11A7438
#define pinstCProgressionSelectionWnd_x                            0x11A7528
#define pinstCPvPStatsWnd_x                                        0x11A7618
#define pinstCSystemInfoDialogBox_x                                0x11A7D20
#define pinstCTaskWnd_x                                            0x11A90E8
#define pinstCTaskSomething_x                                      0xE1D410
#define pinstCTaskTemplateSelectWnd_x                              0x11A9070
#define pinstCTipWndOFDAY_x                                        0x11A9250
#define pinstCTipWndCONTEXT_x                                      0x11A9254
#define pinstCTitleWnd_x                                           0x11A92D0
#define pinstCContextMenuManager_x                                 0x180C96C
#define pinstCVoiceMacroWnd_x                                      0x1096000
#define pinstCHtmlWnd_x                                            0x10960F0
#define pinstIconCache_x                                           0x11A3854
#define pinstCTradeskillWnd_x                                      0x11A93D0
#define pinstCAdvancedLootWnd_x                                    0xF4F384
#define pinstRewardSelectionWnd_x                                  0x11A7B40

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x532390
#define __ConvertItemTags_x                                        0x51FDA0
#define __ExecuteCmd_x                                             0x50A6B0
#define __EQGetTime_x                                              0x894D20
#define __get_melee_range_x                                        0x5112E0
#define __GetGaugeValueFromEQ_x                                    0x7A2F20
#define __GetLabelFromEQ_x                                         0x7A4170
#define __ToggleKeyRingItem_x                                      0x47E000
#define __GetXTargetType_x                                         0x9259C0
#define __LoadFrontEnd_x                                           0x631E60
#define __NewUIINI_x                                               0x7A28F0
#define __ProcessGameEvents_x                                      0x575DB0
#define __ProcessMouseEvent_x                                      0x575550
#define CrashDetected_x                                            0x633820
#define wwsCrashReportCheckForUploader_x                           0x7F2B30
#define DrawNetStatus_x                                            0x5ABF70
#define Util__FastTime_x                                           0x894830
#define Expansion_HoT_x                                            0x1010AF8
#define __HelpPath_x                                               0x10941E8
#define __STMLToText_x                                             0x8DA9E0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420570
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B3E0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B1C0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C4BB0
#define AltAdvManager__IsAbilityReady_x                            0x4C4C20
#define AltAdvManager__GetAAById_x                                 0x4C4FE0
#define AltAdvManager__CanTrainAbility_x                           0x4C58A0
#define AltAdvManager__CanSeeAbility_x                             0x4C54A0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x462D20
#define CharacterZoneClient__MakeMeVisible_x                       0x468620
#define CharacterZoneClient__IsStackBlocked_x                      0x4470A0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446560
#define CharacterZoneClient__GetItemCountWorn_x                    0x460740
#define CharacterZoneClient__GetItemCountInInventory_x             0x460820
#define CharacterZoneClient__GetCursorItemCount_x                  0x460900

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x661940

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66FB10

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58B2A0
#define CButtonWnd__CButtonWnd_x                                   0x8CEC70

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68AD60
#define CChatManager__InitContextMenu_x                            0x68B8E0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D8D40
#define CContextMenu__dCContextMenu_x                              0x8D8F50
#define CContextMenu__AddMenuItem_x                                0x8D8F60
#define CContextMenu__RemoveMenuItem_x                             0x8D9250
#define CContextMenu__RemoveAllMenuItems_x                         0x8D9270
#define CContextMenuManager__AddMenu_x                             0x8C52A0
#define CContextMenuManager__RemoveMenu_x                          0x8C5600
#define CContextMenuManager__PopupMenu_x                           0x8C5A50
#define CContextMenuManager__Flush_x                               0x8C5310
#define CContextMenuManager__GetMenu_x                             0x416A40

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8798D0
#define CChatService__GetFriendName_x                              0x8798E0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x690B30
#define CChatWindow__Clear_x                                       0x690700
#define CChatWindow__WndNotification_x                             0x691070

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C90A0
#define CComboWnd__Draw_x                                          0x8C92B0
#define CComboWnd__GetCurChoice_x                                  0x8C8E70
#define CComboWnd__GetListRect_x                                   0x8C9550
#define CComboWnd__GetTextRect_x                                   0x8C9110
#define CComboWnd__InsertChoice_x                                  0x8C95C0
#define CComboWnd__SetColors_x                                     0x8C8E00
#define CComboWnd__SetChoice_x                                     0x8C8E30
#define CComboWnd__GetItemCount_x                                  0x8C8E60
#define CComboWnd__GetCurChoiceText_x                              0x8C8EB0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69A080
#define CContainerWnd__vftable_x                                   0xAD59C0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B2FE0
#define CDisplay__GetClickedActor_x                                0x4AB8A0
#define CDisplay__GetUserDefinedColor_x                            0x4AA480
#define CDisplay__GetWorldFilePath_x                               0x4A98D0
#define CDisplay__is3dON_x                                         0x4A8D60
#define CDisplay__ReloadUI_x                                       0x4BE4D0
#define CDisplay__WriteTextHD2_x                                   0x4AF330

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EF320

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DD270
#define CEditWnd__GetCharIndexPt_x                                 0x8DE300
#define CEditWnd__GetDisplayString_x                               0x8DD420
#define CEditWnd__GetHorzOffset_x                                  0x8DD760
#define CEditWnd__GetLineForPrintableChar_x                        0x8DDDD0
#define CEditWnd__GetSelStartPt_x                                  0x8DE5B0
#define CEditWnd__GetSTMLSafeText_x                                0x8DD900
#define CEditWnd__PointFromPrintableChar_x                         0x8DDEC0
#define CEditWnd__SelectableCharFromPoint_x                        0x8DE040
#define CEditWnd__SetEditable_x                                    0x8DD8D0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x556C60
#define CEverQuest__CreateTargetIndicator_x                        0x557B50
#define CEverQuest__DeleteTargetIndicator_x                        0x557BD0
#define CEverQuest__DoTellWindow_x                                 0x4732B0
#define CEverQuest__DropHeldItemOnGround_x                         0x56DD00
#define CEverQuest__dsp_chat_x                                     0x4735F0
#define CEverQuest__Emote_x                                        0x56C050
#define CEverQuest__EnterZone_x                                    0x567050
#define CEverQuest__GetBodyTypeDesc_x                              0x551010
#define CEverQuest__GetClassDesc_x                                 0x55A8E0
#define CEverQuest__GetClassThreeLetterCode_x                      0x55AEE0
#define CEverQuest__GetDeityDesc_x                                 0x5518F0
#define CEverQuest__GetLangDesc_x                                  0x5513A0
#define CEverQuest__GetRaceDesc_x                                  0x55B0A0
#define CEverQuest__InterpretCmd_x                                 0x55EEB0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5724A0
#define CEverQuest__LMouseUp_x                                     0x5745A0
#define CEverQuest__RightClickedOnPlayer_x                         0x572FB0
#define CEverQuest__RMouseUp_x                                     0x574000
#define CEverQuest__SetGameState_x                                 0x557520
#define CEverQuest__UPCNotificationFlush_x                         0x54EE30
#define CEverQuest__IssuePetCommand_x                              0x55F890

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AADD0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AAE30
#define CGaugeWnd__Draw_x                                          0x6AB260

// CGuild
#define CGuild__FindMemberByName_x                                 0x436FD0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C7190

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D4240
#define CInvSlotMgr__MoveItem_x                                    0x6D50F0
#define CInvSlotMgr__SelectSlot_x                                  0x6D42F0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D36F0
#define CInvSlot__SliderComplete_x                                 0x6D0F60
#define CInvSlot__GetItemBase_x                                    0x6D03F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D6540

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79E910
#define CItemDisplayWnd__UpdateStrings_x                           0x6D8650

// CLabel 
#define CLabel__Draw_x                                             0x6F1E10

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B4EA0
#define CListWnd__dCListWnd_x                                      0x8B5EB0
#define CListWnd__AddColumn_x                                      0x8B5E50
#define CListWnd__AddColumn1_x                                     0x8B56D0
#define CListWnd__AddLine_x                                        0x8B5150
#define CListWnd__AddString_x                                      0x8B5360
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B2200
#define CListWnd__CalculateVSBRange_x                              0x8B4360
#define CListWnd__ClearSel_x                                       0x8B1500
#define CListWnd__ClearAllSel_x                                    0x8B14B0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B4D30
#define CListWnd__Compare_x                                        0x8B2CF0
#define CListWnd__Draw_x                                           0x8B3F70
#define CListWnd__DrawColumnSeparators_x                           0x8B3E00
#define CListWnd__DrawHeader_x                                     0x8B17C0
#define CListWnd__DrawItem_x                                       0x8B3330
#define CListWnd__DrawLine_x                                       0x8B3AA0
#define CListWnd__DrawSeparator_x                                  0x8B3EA0
#define CListWnd__EnsureVisible_x                                  0x8B2360
#define CListWnd__ExtendSel_x                                      0x8B3240
#define CListWnd__GetColumnMinWidth_x                              0x8B0E70
#define CListWnd__GetColumnWidth_x                                 0x8B0D90
#define CListWnd__GetCurSel_x                                      0x8B0570
#define CListWnd__GetItemAtPoint_x                                 0x8B25F0
#define CListWnd__GetItemAtPoint1_x                                0x8B2660
#define CListWnd__GetItemData_x                                    0x8B08B0
#define CListWnd__GetItemHeight_x                                  0x8B1E50
#define CListWnd__GetItemIcon_x                                    0x8B0A90
#define CListWnd__GetItemRect_x                                    0x8B2430
#define CListWnd__GetItemText_x                                    0x8B0940
#define CListWnd__GetSelList_x                                     0x8B55C0
#define CListWnd__GetSeparatorRect_x                               0x8B2C10
#define CListWnd__RemoveLine_x                                     0x8B5540
#define CListWnd__SetColors_x                                      0x8B06C0
#define CListWnd__SetColumnJustification_x                         0x8B1140
#define CListWnd__SetColumnWidth_x                                 0x8B0E20
#define CListWnd__SetCurSel_x                                      0x8B05B0
#define CListWnd__SetItemColor_x                                   0x8B4A10
#define CListWnd__SetItemData_x                                    0x8B1560
#define CListWnd__SetItemText_x                                    0x8B4850
#define CListWnd__ShiftColumnSeparator_x                           0x8B46E0
#define CListWnd__Sort_x                                           0x8B5FB0
#define CListWnd__ToggleSel_x                                      0x8B1430

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70AD50

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72C120
#define CMerchantWnd__RequestBuyItem_x                             0x7331B0
#define CMerchantWnd__RequestSellItem_x                            0x733C80
#define CMerchantWnd__SelectRecoverySlot_x                         0x72C3D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x72B5D0
#define CMerchantWnd__ActualSelect_x                               0x730090

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x846690
#define CPacketScrambler__hton_x                                   0x8466A0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D3C50
#define CSidlManager__CreateLabel_x                                0x7948C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x658D10
#define CSidlScreenWnd__CalculateVSBRange_x                        0x658C40
#define CSidlScreenWnd__ConvertToRes_x                             0x8EF200
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CBA20
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CCBF0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CCCA0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CC180
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CB3D0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CAB40
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CB5C0
#define CSidlScreenWnd__Init1_x                                    0x8CC8E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CBAD0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CAD00
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CC3C0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CA790
#define CSidlScreenWnd__StoreIniVis_x                              0x8CAAF0
#define CSidlScreenWnd__WndNotification_x                          0x8CC660
#define CSidlScreenWnd__GetChildItem_x                             0x8CAC10
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BE4A0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F6650
#define CSkillMgr__GetSkillCap_x                                   0x5F6810
#define CSkillMgr__GetNameToken_x                                  0x5F6270

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EE4D0
#define CSliderWnd__SetValue_x                                     0x8EE6A0
#define CSliderWnd__SetNumTicks_x                                  0x8EEE20

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79C570

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E9EA0
#define CStmlWnd__CalculateHSBRange_x                              0x8E2400
#define CStmlWnd__CalculateVSBRange_x                              0x8E2490
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E2610
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E2EF0
#define CStmlWnd__ForceParseNow_x                                  0x8EA7F0
#define CStmlWnd__GetNextTagPiece_x                                0x8E2DF0
#define CStmlWnd__GetSTMLText_x                                    0x68FFA0
#define CStmlWnd__GetVisibleText_x                                 0x8E3940
#define CStmlWnd__InitializeWindowVariables_x                      0x8E5CC0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E1700
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E1760
#define CStmlWnd__SetSTMLText_x                                    0x8E7510
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E9B40
#define CStmlWnd__UpdateHistoryString_x                            0x8E4880

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E0E10
#define CTabWnd__DrawCurrentPage_x                                 0x8E06A0
#define CTabWnd__DrawTab_x                                         0x8E0460
#define CTabWnd__GetCurrentPage_x                                  0x8E0A50
#define CTabWnd__GetPageInnerRect_x                                0x8E0150
#define CTabWnd__GetTabInnerRect_x                                 0x8E0350
#define CTabWnd__GetTabRect_x                                      0x8E0220
#define CTabWnd__InsertPage_x                                      0x8E1100
#define CTabWnd__SetPage_x                                         0x8E0A80
#define CTabWnd__SetPageRect_x                                     0x8E0D50
#define CTabWnd__UpdatePage_x                                      0x8E10A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432DA0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C8A70

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F4600

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AE6D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402A60
#define CXStr__CXStr1_x                                            0x8A3DD0
#define CXStr__CXStr3_x                                            0x891960
#define CXStr__dCXStr_x                                            0x8BCF70
#define CXStr__operator_equal_x                                    0x891AD0
#define CXStr__operator_equal1_x                                   0x891B20
#define CXStr__operator_plus_equal1_x                              0x892C20

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BD680
#define CXWnd__Center_x                                            0x8C38C0
#define CXWnd__ClrFocus_x                                          0x8BD260
#define CXWnd__DoAllDrawing_x                                      0x8C3520
#define CXWnd__DrawChildren_x                                      0x8C36C0
#define CXWnd__DrawColoredRect_x                                   0x8BDA40
#define CXWnd__DrawTooltip_x                                       0x8BDCE0
#define CXWnd__DrawTooltipAtPoint_x                                0x8C2480
#define CXWnd__GetBorderFrame_x                                    0x8BE150
#define CXWnd__GetChildWndAt_x                                     0x8C4280
#define CXWnd__GetClientClipRect_x                                 0x8BDF00
#define CXWnd__GetScreenClipRect_x                                 0x8C2B80
#define CXWnd__GetScreenRect_x                                     0x8BE330
#define CXWnd__GetTooltipRect_x                                    0x8BDB70
#define CXWnd__GetWindowTextA_x                                    0x424530
#define CXWnd__IsActive_x                                          0x8B8C90
#define CXWnd__IsDescendantOf_x                                    0x8BE090
#define CXWnd__IsReallyVisible_x                                   0x8C14B0
#define CXWnd__IsType_x                                            0x8F0E40
#define CXWnd__Move_x                                              0x8C0BA0
#define CXWnd__Move1_x                                             0x8C31C0
#define CXWnd__ProcessTransition_x                                 0x8BD630
#define CXWnd__Refade_x                                            0x8BD410
#define CXWnd__Resize_x                                            0x8BE400
#define CXWnd__Right_x                                             0x8C2980
#define CXWnd__SetFocus_x                                          0x8BFCF0
#define CXWnd__SetFont_x                                           0x8BD2B0
#define CXWnd__SetKeyTooltip_x                                     0x8BE670
#define CXWnd__SetMouseOver_x                                      0x8C2EA0
#define CXWnd__StartFade_x                                         0x8BD6D0
#define CXWnd__GetChildItem_x                                      0x8C2DF0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BA530
#define CXWndManager__DrawWindows_x                                0x8BA170
#define CXWndManager__GetKeyboardFlags_x                           0x8B87C0
#define CXWndManager__HandleKeyboardMsg_x                          0x8B9120
#define CXWndManager__RemoveWnd_x                                  0x8B8E20

// CDBStr
#define CDBStr__GetString_x                                        0x4A7290

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44D560
#define EQ_Character__Cur_HP_x                                     0x462410
#define EQ_Character__Cur_Mana_x                                   0x455B20
#define EQ_Character__GetAACastingTimeModifier_x                   0x446870
#define EQ_Character__GetCharInfo2_x                               0x865C20
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EBF0
#define EQ_Character__GetFocusRangeModifier_x                      0x43EC50
#define EQ_Character__Max_Endurance_x                              0x5BE760
#define EQ_Character__Max_HP_x                                     0x458760
#define EQ_Character__Max_Mana_x                                   0x5BE590
#define EQ_Character__doCombatAbility_x                            0x5BBCA0
#define EQ_Character__UseSkill_x                                   0x46D6A0
#define EQ_Character__GetConLevel_x                                0x5B0580
#define EQ_Character__IsExpansionFlag_x                            0x423A60
#define EQ_Character__TotalEffect_x                                0x44A7B0
#define EQ_Character__GetPCSpellAffect_x                           0x446C70
#define EQ_Character__SpellDuration_x                              0x444B70

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x590B90
#define EQ_Item__CreateItemTagString_x                             0x844FE0
#define EQ_Item__IsStackable_x                                     0x83A700
#define EQ_Item__GetImageNum_x                                     0x83D160
#define EQ_Item__CreateItemClient_x                                0x591760
#define EQ_Item__GetItemValue_x                                    0x843CF0
#define EQ_Item__ValueSellMerchant_x                               0x8462E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C6CA0
#define EQ_LoadingS__Array_x                                       0xC13530

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BFDB0
#define EQ_PC__GetAlternateAbilityId_x                             0x84E540
#define EQ_PC__GetCombatAbility_x                                  0x84E5D0
#define EQ_PC__GetCombatAbilityTimer_x                             0x8494B0
#define EQ_PC__GetItemTimerValue_x                                 0x5B97C0
#define EQ_PC__HasLoreItem_x                                       0x5B3A70
#define EQ_PC__AlertInventoryChanged_x                             0x5B0550
#define EQ_PC__GetPcZoneClient_x                                   0x5DA3F0
#define EQ_PC__RemoveMyAffect_x                                    0x5B8C70

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50F310
#define EQItemList__add_object_x                                   0x53BA40
#define EQItemList__add_item_x                                     0x50F250
#define EQItemList__delete_item_x                                  0x50F700
#define EQItemList__FreeItemList_x                                 0x50F600

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A6580

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C5360
#define EQPlayer__dEQPlayer_x                                      0x5CE1A0
#define EQPlayer__DoAttack_x                                       0x5E0100
#define EQPlayer__EQPlayer_x                                       0x5D05C0
#define EQPlayer__SetNameSpriteState_x                             0x5CB120
#define EQPlayer__SetNameSpriteTint_x                              0x5C67A0
#define PlayerBase__HasProperty_j_x                                0x921B90
#define EQPlayer__IsTargetable_x                                   0x922490
#define EQPlayer__CanSee_x                                         0x9229B0
#define PlayerZoneClient__ChangeHeight_x                           0x5DFFC0
#define EQPlayer__CanSeeTargetIndicator_x                          0x922AA0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D4900
#define EQPlayerManager__GetSpawnByName_x                          0x5D4D60
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D4930

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x596CD0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x596D10
#define KeypressHandler__ClearCommandStateArray_x                  0x5968C0
#define KeypressHandler__HandleKeyDown_x                           0x595220
#define KeypressHandler__HandleKeyUp_x                             0x595540
#define KeypressHandler__SaveKeymapping_x                          0x596990

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7036E0
#define MapViewMap__SaveEx_x                                       0x706A10

#define PlayerPointManager__GetAltCurrency_x                       0x860C60

// StringTable 
#define StringTable__getString_x                                   0x85B470

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BE210
#define PcZoneClient__RemovePetEffect_x                            0x5B9C90
#define PcZoneClient__HasAlternateAbility_x                        0x5BA740

//Doors
#define EQSwitch__UseSwitch_x                                      0x54D760

//IconCache
#define IconCache__GetIcon_x                                       0x6A0630

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x697400
#define CContainerMgr__CloseContainer_x                            0x697C20

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x764B10

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x589D40

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DEBA0
#define EQ_Spell__SpellAffects_x                                   0x4DC250
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DC2C0
#define CharacterZoneClient__CalcAffectChange_x                    0x445CA0
#define CLootWnd__LootAll_x                                        0x6F9070

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AB3E0
#define CTargetWnd__WndNotification_x                              0x7AAED0
#define CTargetWnd__UpdateBuffs_x                                  0x7AB5C0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B05C0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D7AB0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x496720

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DC8A0
#define CSidlManager__FindAnimation1_x                             0x8D1B40

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CE3E0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CE390
#define CAltAbilityData__GetMaxRank_x                              0x4C3260

//CTargetRing
#define CTargetRing__Cast_x                                        0x587620

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4543F0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x681DA0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x681500

//messages
#define msg_spell_worn_off_x                                       0x4E6610
#define msg_new_text_x                                             0x4EF960
#define msgTokenTextParam_x                                        0x4EC470

//SpellManager
#define SpellManager__vftable_x                                    0xAB1DA8
#define SpellManager__SpellManager_x                               0x47AEA0

