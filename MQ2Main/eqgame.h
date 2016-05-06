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
#define __ExpectedVersionDate                                     "Apr 21 2016"
#define __ExpectedVersionTime                                     "19:30:22"
#define __ActualVersionDate_x                                      0xACBFF8
#define __ActualVersionTime_x                                      0xACC004

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59C3D0
#define __MemChecker1_x                                            0x8958E0
#define __MemChecker2_x                                            0x632770
#define __MemChecker3_x                                            0x6326C0
#define __MemChecker4_x                                            0x7E3B20
#define __EncryptPad0_x                                            0xC6A828
#define __EncryptPad1_x                                            0xDF50A8
#define __EncryptPad2_x                                            0xCB32E8
#define __EncryptPad3_x                                            0xCB2EE8
#define __EncryptPad4_x                                            0xDCBEB8
#define __EncryptPad5_x                                            0x11A1070
#define __AC1_x                                                    0x7A3905
#define __AC2_x                                                    0x556657
#define __AC3_x                                                    0x5547F0
#define __AC4_x                                                    0x566FD0
#define __AC5_x                                                    0x579A6B
#define __AC6_x                                                    0x57D61E
#define __AC7_x                                                    0x57412C
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
#define __do_loot_x                                                0x51B230
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
#define __LoginName_x                                              0x1097B28
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
#define __ConvertItemTags_x                                        0x51FD90
#define __ExecuteCmd_x                                             0x50A6B0
#define __EQGetTime_x                                              0x895510
#define __get_melee_range_x                                        0x5112D0
#define __GetGaugeValueFromEQ_x                                    0x7A2640
#define __GetLabelFromEQ_x                                         0x7A3890
#define __ToggleKeyRingItem_x                                      0x47E690
#define __GetXTargetType_x                                         0x926130
#define __LoadFrontEnd_x                                           0x631E40
#define __NewUIINI_x                                               0x7A2010
#define __ProcessGameEvents_x                                      0x575E90
#define __ProcessMouseEvent_x                                      0x575630
#define CrashDetected_x                                            0x633800
#define wwsCrashReportCheckForUploader_x                           0x7F2130
#define DrawNetStatus_x                                            0x5AC1D0
#define Util__FastTime_x                                           0x895020
#define Expansion_HoT_x                                            0x1010AF8
#define __HelpPath_x                                               0x10941E8
#define __STMLToText_x                                             0x8DB080

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420660
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B4B0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B290

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C51F0
#define AltAdvManager__IsAbilityReady_x                            0x4C5260
#define AltAdvManager__GetAAById_x                                 0x4C5620
#define AltAdvManager__CanTrainAbility_x                           0x4C5EE0
#define AltAdvManager__CanSeeAbility_x                             0x4C5AE0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463160
#define CharacterZoneClient__MakeMeVisible_x                       0x468B70
#define CharacterZoneClient__IsStackBlocked_x                      0x4472D0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446790
#define CharacterZoneClient__GetItemCountWorn_x                    0x460AB0
#define CharacterZoneClient__GetItemCountInInventory_x             0x460B90
#define CharacterZoneClient__GetCursorItemCount_x                  0x460C70

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x661A00

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66F8F0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58B270
#define CButtonWnd__CButtonWnd_x                                   0x8CF360

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68ACF0
#define CChatManager__InitContextMenu_x                            0x68B870

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D93E0
#define CContextMenu__dCContextMenu_x                              0x8D95F0
#define CContextMenu__AddMenuItem_x                                0x8D9600
#define CContextMenu__RemoveMenuItem_x                             0x8D98F0
#define CContextMenu__RemoveAllMenuItems_x                         0x8D9910
#define CContextMenuManager__AddMenu_x                             0x8C5940
#define CContextMenuManager__RemoveMenu_x                          0x8C5C90
#define CContextMenuManager__PopupMenu_x                           0x8C60E0
#define CContextMenuManager__Flush_x                               0x8C59B0
#define CContextMenuManager__GetMenu_x                             0x416AF0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x879F80
#define CChatService__GetFriendName_x                              0x879F90

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x690AC0
#define CChatWindow__Clear_x                                       0x690690
#define CChatWindow__WndNotification_x                             0x691000

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C9730
#define CComboWnd__Draw_x                                          0x8C9940
#define CComboWnd__GetCurChoice_x                                  0x8C9500
#define CComboWnd__GetListRect_x                                   0x8C9BE0
#define CComboWnd__GetTextRect_x                                   0x8C97A0
#define CComboWnd__InsertChoice_x                                  0x8C9C50
#define CComboWnd__SetColors_x                                     0x8C9490
#define CComboWnd__SetChoice_x                                     0x8C94C0
#define CComboWnd__GetItemCount_x                                  0x8C94F0
#define CComboWnd__GetCurChoiceText_x                              0x8C9540


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69A010
#define CContainerWnd__vftable_x                                   0xAD59F0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B3730
#define CDisplay__GetClickedActor_x                                0x4ABFF0
#define CDisplay__GetUserDefinedColor_x                            0x4AABD0
#define CDisplay__GetWorldFilePath_x                               0x4AA020
#define CDisplay__is3dON_x                                         0x4A94B0
#define CDisplay__ReloadUI_x                                       0x4BEC20
#define CDisplay__WriteTextHD2_x                                   0x4AFA80

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EFAB0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DD910
#define CEditWnd__GetCharIndexPt_x                                 0x8DE9B0
#define CEditWnd__GetDisplayString_x                               0x8DDAC0
#define CEditWnd__GetHorzOffset_x                                  0x8DDE00
#define CEditWnd__GetLineForPrintableChar_x                        0x8DE470
#define CEditWnd__GetSelStartPt_x                                  0x8DEC70
#define CEditWnd__GetSTMLSafeText_x                                0x8DDFA0
#define CEditWnd__PointFromPrintableChar_x                         0x8DE560
#define CEditWnd__SelectableCharFromPoint_x                        0x8DE6E0
#define CEditWnd__SetEditable_x                                    0x8DDF70

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x556DA0
#define CEverQuest__CreateTargetIndicator_x                        0x557C90
#define CEverQuest__DeleteTargetIndicator_x                        0x557D10
#define CEverQuest__DoTellWindow_x                                 0x473930
#define CEverQuest__DropHeldItemOnGround_x                         0x56DDE0
#define CEverQuest__dsp_chat_x                                     0x473C70
#define CEverQuest__Emote_x                                        0x56C130
#define CEverQuest__EnterZone_x                                    0x567160
#define CEverQuest__GetBodyTypeDesc_x                              0x551150
#define CEverQuest__GetClassDesc_x                                 0x55AA20
#define CEverQuest__GetClassThreeLetterCode_x                      0x55B020
#define CEverQuest__GetDeityDesc_x                                 0x551A30
#define CEverQuest__GetLangDesc_x                                  0x5514E0
#define CEverQuest__GetRaceDesc_x                                  0x55B1E0
#define CEverQuest__InterpretCmd_x                                 0x55EFF0
#define CEverQuest__LeftClickedOnPlayer_x                          0x572580
#define CEverQuest__LMouseUp_x                                     0x574680
#define CEverQuest__RightClickedOnPlayer_x                         0x573090
#define CEverQuest__RMouseUp_x                                     0x5740E0
#define CEverQuest__SetGameState_x                                 0x557660
#define CEverQuest__UPCNotificationFlush_x                         0x54EF70
#define CEverQuest__IssuePetCommand_x                              0x55F9A0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AAC10
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AAC70
#define CGaugeWnd__Draw_x                                          0x6AB0A0

// CGuild
#define CGuild__FindMemberByName_x                                 0x437070

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C78F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D4060
#define CInvSlotMgr__MoveItem_x                                    0x6D4F10
#define CInvSlotMgr__SelectSlot_x                                  0x6D4110

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D3510
#define CInvSlot__SliderComplete_x                                 0x6D0D80
#define CInvSlot__GetItemBase_x                                    0x6D01E0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D6350

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79F0A0
#define CItemDisplayWnd__UpdateStrings_x                           0x6D84A0

// CLabel 
#define CLabel__Draw_x                                             0x6F2710

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B55A0
#define CListWnd__dCListWnd_x                                      0x8B65C0
#define CListWnd__AddColumn_x                                      0x8B6560
#define CListWnd__AddColumn1_x                                     0x8B5DE0
#define CListWnd__AddLine_x                                        0x8B5860
#define CListWnd__AddString_x                                      0x8B5A70
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B28D0
#define CListWnd__CalculateVSBRange_x                              0x8B4A50
#define CListWnd__ClearSel_x                                       0x8B1BD0
#define CListWnd__ClearAllSel_x                                    0x8B1B80
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B5430
#define CListWnd__Compare_x                                        0x8B33E0
#define CListWnd__Draw_x                                           0x8B4660
#define CListWnd__DrawColumnSeparators_x                           0x8B44F0
#define CListWnd__DrawHeader_x                                     0x8B1E90
#define CListWnd__DrawItem_x                                       0x8B3A20
#define CListWnd__DrawLine_x                                       0x8B4190
#define CListWnd__DrawSeparator_x                                  0x8B4590
#define CListWnd__EnsureVisible_x                                  0x8B2A30
#define CListWnd__ExtendSel_x                                      0x8B3930
#define CListWnd__GetColumnMinWidth_x                              0x8B1540
#define CListWnd__GetColumnWidth_x                                 0x8B1460
#define CListWnd__GetCurSel_x                                      0x8B0C40
#define CListWnd__GetItemAtPoint_x                                 0x8B2CD0
#define CListWnd__GetItemAtPoint1_x                                0x8B2D40
#define CListWnd__GetItemData_x                                    0x8B0F70
#define CListWnd__GetItemHeight_x                                  0x8B2520
#define CListWnd__GetItemIcon_x                                    0x8B1150
#define CListWnd__GetItemRect_x                                    0x8B2B10
#define CListWnd__GetItemText_x                                    0x8B1000
#define CListWnd__GetSelList_x                                     0x8B5CD0
#define CListWnd__GetSeparatorRect_x                               0x8B3300
#define CListWnd__RemoveLine_x                                     0x8B5C50
#define CListWnd__SetColors_x                                      0x8B0D90
#define CListWnd__SetColumnJustification_x                         0x8B1810
#define CListWnd__SetColumnWidth_x                                 0x8B14F0
#define CListWnd__SetCurSel_x                                      0x8B0C80
#define CListWnd__SetItemColor_x                                   0x8B5110
#define CListWnd__SetItemData_x                                    0x8B1C30
#define CListWnd__SetItemText_x                                    0x8B4F50
#define CListWnd__ShiftColumnSeparator_x                           0x8B4DE0
#define CListWnd__Sort_x                                           0x8B66C0
#define CListWnd__ToggleSel_x                                      0x8B1B00

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70B7B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72CA40
#define CMerchantWnd__RequestBuyItem_x                             0x733AD0
#define CMerchantWnd__RequestSellItem_x                            0x7345A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x72CCF0
#define CMerchantWnd__SelectBuySellSlot_x                          0x72BEF0
#define CMerchantWnd__ActualSelect_x                               0x7309B0

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x846DD0
#define CPacketScrambler__hton_x                                   0x846DE0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D43C0
#define CSidlManager__CreateLabel_x                                0x795000

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x658DE0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x658D00
#define CSidlScreenWnd__ConvertToRes_x                             0x8EF990
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CC0C0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CD290
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CD340
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CC810
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CBA70
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CB1D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CBC60
#define CSidlScreenWnd__Init1_x                                    0x8CCF60
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CC170
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CB390
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CCA50
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CAE30
#define CSidlScreenWnd__StoreIniVis_x                              0x8CB180
#define CSidlScreenWnd__WndNotification_x                          0x8CCCE0
#define CSidlScreenWnd__GetChildItem_x                             0x8CB2A0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BEB30

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F6AF0
#define CSkillMgr__GetSkillCap_x                                   0x5F6CB0
#define CSkillMgr__GetNameToken_x                                  0x5F6710

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EEC40
#define CSliderWnd__SetValue_x                                     0x8EEE10
#define CSliderWnd__SetNumTicks_x                                  0x8EF590

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79CD00

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EA5E0
#define CStmlWnd__CalculateHSBRange_x                              0x8E2B00
#define CStmlWnd__CalculateVSBRange_x                              0x8E2B90
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E2D10
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E35F0
#define CStmlWnd__ForceParseNow_x                                  0x8EAF30
#define CStmlWnd__GetNextTagPiece_x                                0x8E34F0
#define CStmlWnd__GetSTMLText_x                                    0x68FF30
#define CStmlWnd__GetVisibleText_x                                 0x8E4040
#define CStmlWnd__InitializeWindowVariables_x                      0x8E63D0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E1E00
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E1E60
#define CStmlWnd__SetSTMLText_x                                    0x8E7C30
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EA280
#define CStmlWnd__UpdateHistoryString_x                            0x8E4F80

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E1500
#define CTabWnd__DrawCurrentPage_x                                 0x8E0D90
#define CTabWnd__DrawTab_x                                         0x8E0B50
#define CTabWnd__GetCurrentPage_x                                  0x8E1140
#define CTabWnd__GetPageInnerRect_x                                0x8E0840
#define CTabWnd__GetTabInnerRect_x                                 0x8E0A40
#define CTabWnd__GetTabRect_x                                      0x8E0910
#define CTabWnd__InsertPage_x                                      0x8E17F0
#define CTabWnd__SetPage_x                                         0x8E1170
#define CTabWnd__SetPageRect_x                                     0x8E1440
#define CTabWnd__UpdatePage_x                                      0x8E1790

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432E80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C9100

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F4DB0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AECD0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5988D0
#define CXStr__CXStr1_x                                            0x8AFE60
#define CXStr__CXStr3_x                                            0x892110
#define CXStr__dCXStr_x                                            0x8EB9F0
#define CXStr__operator_equal_x                                    0x892280
#define CXStr__operator_equal1_x                                   0x8922D0
#define CXStr__operator_plus_equal1_x                              0x8933D0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BDD90
#define CXWnd__Center_x                                            0x8C3F10
#define CXWnd__ClrFocus_x                                          0x8BD950
#define CXWnd__DoAllDrawing_x                                      0x8C3B60
#define CXWnd__DrawChildren_x                                      0x8C3D00
#define CXWnd__DrawColoredRect_x                                   0x8BE150
#define CXWnd__DrawTooltip_x                                       0x8BE400
#define CXWnd__DrawTooltipAtPoint_x                                0x8C2AE0
#define CXWnd__GetBorderFrame_x                                    0x8BE800
#define CXWnd__GetChildWndAt_x                                     0x8C48C0
#define CXWnd__GetClientClipRect_x                                 0x8BE610
#define CXWnd__GetScreenClipRect_x                                 0x8C31E0
#define CXWnd__GetScreenRect_x                                     0x8BE9C0
#define CXWnd__GetTooltipRect_x                                    0x8BE290
#define CXWnd__GetWindowTextA_x                                    0x424660
#define CXWnd__IsActive_x                                          0x8B93C0
#define CXWnd__IsDescendantOf_x                                    0x8BE750
#define CXWnd__IsReallyVisible_x                                   0x8C1B10
#define CXWnd__IsType_x                                            0x8F15F0
#define CXWnd__Move_x                                              0x8C1200
#define CXWnd__Move1_x                                             0x8C3810
#define CXWnd__ProcessTransition_x                                 0x8BDD30
#define CXWnd__Refade_x                                            0x8BDB00
#define CXWnd__Resize_x                                            0x8BEA90
#define CXWnd__Right_x                                             0x8C2FE0
#define CXWnd__SetFocus_x                                          0x8C0330
#define CXWnd__SetFont_x                                           0x8BD9A0
#define CXWnd__SetKeyTooltip_x                                     0x8BED00
#define CXWnd__SetMouseOver_x                                      0x8C34F0
#define CXWnd__StartFade_x                                         0x8BDDE0
#define CXWnd__GetChildItem_x                                      0x8C3430

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BAC50
#define CXWndManager__DrawWindows_x                                0x8BA890
#define CXWndManager__GetKeyboardFlags_x                           0x8B8EF0
#define CXWndManager__HandleKeyboardMsg_x                          0x8B9840
#define CXWndManager__RemoveWnd_x                                  0x8B9550

// CDBStr
#define CDBStr__GetString_x                                        0x4A79A0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44D790
#define EQ_Character__Cur_HP_x                                     0x462850
#define EQ_Character__Cur_Mana_x                                   0x455D70
#define EQ_Character__GetAACastingTimeModifier_x                   0x446AA0
#define EQ_Character__GetCharInfo2_x                               0x866290
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43ECB0
#define EQ_Character__GetFocusRangeModifier_x                      0x43ED10
#define EQ_Character__Max_Endurance_x                              0x5BE620
#define EQ_Character__Max_HP_x                                     0x4588A0
#define EQ_Character__Max_Mana_x                                   0x5BE450
#define EQ_Character__doCombatAbility_x                            0x5BBB60
#define EQ_Character__UseSkill_x                                   0x46DDB0
#define EQ_Character__GetConLevel_x                                0x5B07E0
#define EQ_Character__IsExpansionFlag_x                            0x423BB0
#define EQ_Character__TotalEffect_x                                0x44A9E0
#define EQ_Character__GetPCSpellAffect_x                           0x446EA0
#define EQ_Character__SpellDuration_x                              0x444DA0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x590AE0
#define EQ_Item__CreateItemTagString_x                             0x845700
#define EQ_Item__IsStackable_x                                     0x839E30
#define EQ_Item__GetImageNum_x                                     0x83C8B0
#define EQ_Item__CreateItemClient_x                                0x5916D0
#define EQ_Item__GetItemValue_x                                    0x844430
#define EQ_Item__ValueSellMerchant_x                               0x846A20

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C7320
#define EQ_LoadingS__Array_x                                       0xC13530

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BFC70
#define EQ_PC__GetAlternateAbilityId_x                             0x84EC70
#define EQ_PC__GetCombatAbility_x                                  0x84ED00
#define EQ_PC__GetCombatAbilityTimer_x                             0x88DA50
#define EQ_PC__GetItemTimerValue_x                                 0x5B9680
#define EQ_PC__HasLoreItem_x                                       0x5B3CD0
#define EQ_PC__AlertInventoryChanged_x                             0x5B07B0
#define EQ_PC__GetPcZoneClient_x                                   0x5DA330
#define EQ_PC__RemoveMyAffect_x                                    0x5B8B30

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50F310
#define EQItemList__add_object_x                                   0x53B9C0
#define EQItemList__add_item_x                                     0x50F250
#define EQItemList__delete_item_x                                  0x50F700
#define EQItemList__FreeItemList_x                                 0x50F600

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A6C80

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C5220
#define EQPlayer__dEQPlayer_x                                      0x5CE080
#define EQPlayer__DoAttack_x                                       0x5E0040
#define EQPlayer__EQPlayer_x                                       0x5D04A0
#define EQPlayer__SetNameSpriteState_x                             0x5CB000
#define EQPlayer__SetNameSpriteTint_x                              0x5C6660
#define PlayerBase__HasProperty_j_x                                0x922380
#define EQPlayer__IsTargetable_x                                   0x922C80
#define EQPlayer__CanSee_x                                         0x9231A0
#define PlayerZoneClient__ChangeHeight_x                           0x5DFF00
#define EQPlayer__CanSeeTargetIndicator_x                          0x923290

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D47D0
#define EQPlayerManager__GetSpawnByName_x                          0x5D4C30
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D4800

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x596C70
#define KeypressHandler__AttachKeyToEqCommand_x                    0x596CB0
#define KeypressHandler__ClearCommandStateArray_x                  0x596860
#define KeypressHandler__HandleKeyDown_x                           0x5951C0
#define KeypressHandler__HandleKeyUp_x                             0x5954E0
#define KeypressHandler__SaveKeymapping_x                          0x596930

// MapViewMap 
#define MapViewMap__Clear_x                                        0x704140
#define MapViewMap__SaveEx_x                                       0x707470

#define PlayerPointManager__GetAltCurrency_x                       0x8612D0

// StringTable 
#define StringTable__getString_x                                   0x85BBC0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BE0D0
#define PcZoneClient__RemovePetEffect_x                            0x5B9B50
#define PcZoneClient__HasAlternateAbility_x                        0x5BA600

//Doors
#define EQSwitch__UseSwitch_x                                      0x54D7E0

//IconCache
#define IconCache__GetIcon_x                                       0x6A0560

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x697390
#define CContainerMgr__CloseContainer_x                            0x697BB0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7653A0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x589D00

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DEFB0
#define EQ_Spell__SpellAffects_x                                   0x4DC660
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DC6D0
#define CharacterZoneClient__CalcAffectChange_x                    0x445ED0
#define CLootWnd__LootAll_x                                        0x6F99E0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AAA50
#define CTargetWnd__WndNotification_x                              0x7AA540
#define CTargetWnd__UpdateBuffs_x                                  0x7AAC30

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AFC30

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D7F20

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x496E90

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DCF40
#define CSidlManager__FindAnimation1_x                             0x8D22C0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CE950
#define CAltAbilityData__GetMercMaxRank_x                          0x4CE900
#define CAltAbilityData__GetMaxRank_x                              0x4C38A0

//CTargetRing
#define CTargetRing__Cast_x                                        0x5875D0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454610

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x681DD0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x681590

//messages
#define msg_spell_worn_off_x                                       0x4E6A40
#define msg_new_text_x                                             0x4EFDC0
#define msgTokenTextParam_x                                        0x4EC8A0

//SpellManager
#define SpellManager__vftable_x                                    0xAB1DA8
#define SpellManager__SpellManager_x                               0x47B530
