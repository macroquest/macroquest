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
#define __ExpectedVersionDate                                     "Apr 22 2016"
#define __ExpectedVersionTime                                     "12:02:59"
#define __ActualVersionDate_x                                      0xACCFF0
#define __ActualVersionTime_x                                      0xACCFFC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59D3F0
#define __MemChecker1_x                                            0x895D60
#define __MemChecker2_x                                            0x633850
#define __MemChecker3_x                                            0x6337A0
#define __MemChecker4_x                                            0x7E3F40
#define __EncryptPad0_x                                            0xC6B828
#define __EncryptPad1_x                                            0xDF60A8
#define __EncryptPad2_x                                            0xCB42E8
#define __EncryptPad3_x                                            0xCB3EE8
#define __EncryptPad4_x                                            0xDCCEB8
#define __EncryptPad5_x                                            0x11A2070
#define __AC1_x                                                    0x7A45B5
#define __AC2_x                                                    0x5577B7
#define __AC3_x                                                    0x555950
#define __AC4_x                                                    0x568130
#define __AC5_x                                                    0x57AB8B
#define __AC6_x                                                    0x57E73E
#define __AC7_x                                                    0x57524C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E4E80

// Direct Input
#define DI8__Main_x                                                0x11A2048
#define DI8__Keyboard_x                                            0x11A204C
#define DI8__Mouse_x                                               0x11A2050
#define DI8__Mouse_Copy_x                                          0x10107A4
#define DI8__Mouse_Check_x                                         0x1099F34
#define __Attack_x                                                 0x1094C7B
#define __Autofire_x                                               0x1094C7C
#define __BindList_x                                               0xC2D480
#define g_eqCommandStates_x                                        0xFFFC08
#define __Clicks_x                                                 0x1010860
#define __CommandList_x                                            0xC31850
#define __CurrentMapLabel_x                                        0x11A7AA0
#define __CurrentSocial_x                                          0xBE3FB8
#define __DoAbilityList_x                                          0x1046F30
#define __do_loot_x                                                0x51C2B0
#define __DrawHandler_x                                            0x180E4BC
#define __GroupCount_x                                             0x10011D2

#define __Guilds_x                                                 0x1006DE8
#define __gWorld_x                                                 0x100368C
#define __HotkeyPage_x                                             0x108D930
#define __HWnd_x                                                   0x1099F50
#define __InChatMode_x                                             0x101078C
#define __LastTell_x                                               0x101262C
#define __LMouseHeldTime_x                                         0x10108CC
#define __Mouse_x                                                  0x11A2054
#define __MouseLook_x                                              0x1010826
#define __MouseEventTime_x                                         0x109547C
#define __gpbCommandEvent_x                                        0x1003754
#define __NetStatusToggle_x                                        0x1010829
#define __PCNames_x                                                0x1011C50
#define __RangeAttackReady_x                                       0x101198C
#define __RMouseHeldTime_x                                         0x10108C8
#define __RunWalkState_x                                           0x1010790
#define __ScreenMode_x                                             0xF4F988
#define __ScreenX_x                                                0x1010744
#define __ScreenY_x                                                0x1010740
#define __ScreenXMax_x                                             0x1010748
#define __ScreenYMax_x                                             0x101074C
#define __ServerHost_x                                             0x100111C
#define __ServerName_x                                             0x1046EF0
#define __ShiftKeyDown_x                                           0x1010E18
#define __ShowNames_x                                              0x1011B4C
#define __Socials_x                                                0x1046FF0
#define __SubscriptionType_x                                       0x11D5B50
#define __TargetAggroHolder_x                                      0x11A9CDC
#define __ZoneType_x                                               0x1010C24
#define __GroupAggro_x                                             0x11A9D1C
#define __LoginName_x                                              0x1098B28
#define __Inviter_x                                                0x1094BF8
#define __AttackOnAssist_x                                         0x1011B08

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x1003778
#define instEQZoneInfo_x                                           0x1010A1C
#define instKeypressHandler_x                                      0x1095460
#define pinstActiveBanker_x                                        0x1003730
#define pinstActiveCorpse_x                                        0x1003734
#define pinstActiveGMaster_x                                       0x1003738
#define pinstActiveMerchant_x                                      0x100372C
#define pinstAggroInfo_x                                           0xE11CC8
#define pinstAltAdvManager_x                                       0xF50A48
#define pinstAuraMgr_x                                             0xE1DC50
#define pinstBandageTarget_x                                       0x1003718
#define pinstCamActor_x                                            0xF5039C
#define pinstCDBStr_x                                              0xF4F91C
#define pinstCDisplay_x                                            0x1003740
#define pinstCEverQuest_x                                          0x11A21C8
#define pinstCharData_x                                            0x10036FC
#define pinstCharSpawn_x                                           0x1003724
#define pinstControlledMissile_x                                   0x10036F8
#define pinstControlledPlayer_x                                    0x1003724
#define pinstCSidlManager_x                                        0x180D9FC
#define pinstCXWndManager_x                                        0x180D9F4
#define instDynamicZone_x                                          0x10105D8
#define pinstDZMember_x                                            0x10106E8
#define pinstDZTimerInfo_x                                         0x10106EC
#define pinstEQItemList_x                                          0xFFFE58
#define pinstEQObjectList_x                                        0x1000BCC
#define instEQMisc_x                                               0xC07CF8
#define pinstEQSoundManager_x                                      0xF50FA0
#define instExpeditionLeader_x                                     0x1010622
#define instExpeditionName_x                                       0x1010662
#define pinstGroup_x                                               0x10011CE
#define pinstImeManager_x                                          0x180DA00
#define pinstLocalPlayer_x                                         0x1003710
#define pinstMercenaryData_x                                       0x1095AB0
#define pinstMercenaryStats_x                                      0x11A9E28
#define pinstMercAltAbilities_x                                    0xF50DD0
#define pinstModelPlayer_x                                         0x100373C
#define pinstPCData_x                                              0x10036FC
#define pinstSkillMgr_x                                            0x10968E8
#define pinstSpawnManager_x                                        0x10961D0
#define pinstSpellManager_x                                        0x1096A30
#define pinstSpellSets_x                                           0x108D994
#define pinstStringTable_x                                         0x10036A4
#define pinstSwitchManager_x                                       0x1000D60
#define pinstTarget_x                                              0x1003728
#define pinstTargetObject_x                                        0x1003700
#define pinstTargetSwitch_x                                        0x1003704
#define pinstTaskMember_x                                          0xF4F868
#define pinstTrackTarget_x                                         0x100371C
#define pinstTradeTarget_x                                         0x100370C
#define instTributeActive_x                                        0xC07D1D
#define pinstViewActor_x                                           0xF50398
#define pinstWorldData_x                                           0x10036E0
#define pinstZoneAddr_x                                            0x1010CBC
#define pinstPlayerPath_x                                          0x1096230
#define pinstTargetIndicator_x                                     0x1096BC8
#define pinstCTargetManager_x                                      0x1096C28

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE121C0
#define pinstCAudioTriggersWindow_x                                0xE12050
#define pinstCCharacterSelect_x                                    0xF5022C
#define pinstCFacePick_x                                           0xF4FFDC
#define pinstCNoteWnd_x                                            0xF501E4
#define pinstCBookWnd_x                                            0xF501EC
#define pinstCPetInfoWnd_x                                         0xF501F0
#define pinstCTrainWnd_x                                           0xF501F4
#define pinstCSkillsWnd_x                                          0xF501F8
#define pinstCSkillsSelectWnd_x                                    0xF501FC
#define pinstCCombatSkillsSelectWnd_x                              0xF50200
#define pinstCFriendsWnd_x                                         0xF50204
#define pinstCAuraWnd_x                                            0xF50208
#define pinstCRespawnWnd_x                                         0xF5020C
#define pinstCBandolierWnd_x                                       0xF50210
#define pinstCPotionBeltWnd_x                                      0xF50214
#define pinstCAAWnd_x                                              0xF50218
#define pinstCGroupSearchFiltersWnd_x                              0xF5021C
#define pinstCLoadskinWnd_x                                        0xF50220
#define pinstCAlarmWnd_x                                           0xF50224
#define pinstCMusicPlayerWnd_x                                     0xF50228
#define pinstCMailWnd_x                                            0xF50230
#define pinstCMailCompositionWnd_x                                 0xF50234
#define pinstCMailAddressBookWnd_x                                 0xF50238
#define pinstCRaidWnd_x                                            0xF50240
#define pinstCRaidOptionsWnd_x                                     0xF50244
#define pinstCBreathWnd_x                                          0xF50248
#define pinstCMapViewWnd_x                                         0xF5024C
#define pinstCMapToolbarWnd_x                                      0xF50250
#define pinstCEditLabelWnd_x                                       0xF50254
#define pinstCTargetWnd_x                                          0xF50258
#define pinstCColorPickerWnd_x                                     0xF5025C
#define pinstCPlayerWnd_x                                          0xF50260
#define pinstCOptionsWnd_x                                         0xF50264
#define pinstCBuffWindowNORMAL_x                                   0xF50268
#define pinstCBuffWindowSHORT_x                                    0xF5026C
#define pinstCharacterCreation_x                                   0xF50270
#define pinstCCursorAttachment_x                                   0xF50274
#define pinstCCastingWnd_x                                         0xF50278
#define pinstCCastSpellWnd_x                                       0xF5027C
#define pinstCSpellBookWnd_x                                       0xF50280
#define pinstCInventoryWnd_x                                       0xF50284
#define pinstCBankWnd_x                                            0xF5028C
#define pinstCQuantityWnd_x                                        0xF50290
#define pinstCLootWnd_x                                            0xF50294
#define pinstCActionsWnd_x                                         0xF50298
#define pinstCCombatAbilityWnd_x                                   0xF5029C
#define pinstCMerchantWnd_x                                        0xF502A0
#define pinstCTradeWnd_x                                           0xF502A4
#define pinstCSelectorWnd_x                                        0xF502A8
#define pinstCBazaarWnd_x                                          0xF502AC
#define pinstCBazaarSearchWnd_x                                    0xF502B0
#define pinstCGiveWnd_x                                            0xF502CC
#define pinstCTrackingWnd_x                                        0xF502D4
#define pinstCInspectWnd_x                                         0xF502D8
#define pinstCSocialEditWnd_x                                      0xF502DC
#define pinstCFeedbackWnd_x                                        0xF502E0
#define pinstCBugReportWnd_x                                       0xF502E4
#define pinstCVideoModesWnd_x                                      0xF502E8
#define pinstCTextEntryWnd_x                                       0xF502F0
#define pinstCFileSelectionWnd_x                                   0xF502F4
#define pinstCCompassWnd_x                                         0xF502F8
#define pinstCPlayerNotesWnd_x                                     0xF502FC
#define pinstCGemsGameWnd_x                                        0xF50300
#define pinstCTimeLeftWnd_x                                        0xF50304
#define pinstCPetitionQWnd_x                                       0xF50320
#define pinstCSoulmarkWnd_x                                        0xF50324
#define pinstCStoryWnd_x                                           0xF50328
#define pinstCJournalTextWnd_x                                     0xF5032C
#define pinstCJournalCatWnd_x                                      0xF50330
#define pinstCBodyTintWnd_x                                        0xF50334
#define pinstCServerListWnd_x                                      0xF50338
#define pinstCAvaZoneWnd_x                                         0xF50344
#define pinstCBlockedBuffWnd_x                                     0xF50348
#define pinstCBlockedPetBuffWnd_x                                  0xF5034C
#define pinstCInvSlotMgr_x                                         0xF50390
#define pinstCContainerMgr_x                                       0xF50394
#define pinstCAdventureLeaderboardWnd_x                            0x11A2B78
#define pinstCAdventureRequestWnd_x                                0x11A2BF0
#define pinstCAltStorageWnd_x                                      0x11A2ED0
#define pinstCAdventureStatsWnd_x                                  0x11A2C68
#define pinstCBarterMerchantWnd_x                                  0x11A3AB8
#define pinstCBarterSearchWnd_x                                    0x11A3B30
#define pinstCBarterWnd_x                                          0x11A3BA8
#define pinstCChatManager_x                                        0x11A4238
#define pinstCDynamicZoneWnd_x                                     0x11A46E8
#define pinstCEQMainWnd_x                                          0x11A4880
#define pinstCFellowshipWnd_x                                      0x11A467C
#define pinstCFindLocationWnd_x                                    0x11A4B50
#define pinstCGroupSearchWnd_x                                     0x11A4E20
#define pinstCGroupWnd_x                                           0x11A4E98
#define pinstCGuildBankWnd_x                                       0x11A4F10
#define pinstCGuildMgmtWnd_x                                       0x11A7000
#define pinstCHotButtonWnd_x                                       0x11A70CC
#define pinstCHotButtonWnd1_x                                      0x11A70CC
#define pinstCHotButtonWnd2_x                                      0x11A70D0
#define pinstCHotButtonWnd3_x                                      0x11A70D4
#define pinstCHotButtonWnd4_x                                      0x11A70F8
#define pinstCItemDisplayManager_x                                 0x11A73F0
#define pinstCItemExpTransferWnd_x                                 0x11A746C
#define pinstCLFGuildWnd_x                                         0x11A7748
#define pinstCMIZoneSelectWnd_x                                    0x11A7D30
#define pinstCConfirmationDialog_x                                 0x11A8438
#define pinstCPopupWndManager_x                                    0x11A8438
#define pinstCProgressionSelectionWnd_x                            0x11A8528
#define pinstCPvPStatsWnd_x                                        0x11A8618
#define pinstCSystemInfoDialogBox_x                                0x11A8D20
#define pinstCTaskWnd_x                                            0x11AA0E8
#define pinstCTaskSomething_x                                      0xE1E410
#define pinstCTaskTemplateSelectWnd_x                              0x11AA070
#define pinstCTipWndOFDAY_x                                        0x11AA250
#define pinstCTipWndCONTEXT_x                                      0x11AA254
#define pinstCTitleWnd_x                                           0x11AA2D0
#define pinstCContextMenuManager_x                                 0x180D96C
#define pinstCVoiceMacroWnd_x                                      0x1097000
#define pinstCHtmlWnd_x                                            0x10970F0
#define pinstIconCache_x                                           0x11A4854
#define pinstCTradeskillWnd_x                                      0x11AA3D0
#define pinstCAdvancedLootWnd_x                                    0xF50384
#define pinstRewardSelectionWnd_x                                  0x11A8B40

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x533410
#define __ConvertItemTags_x                                        0x520E10
#define __ExecuteCmd_x                                             0x50B750
#define __EQGetTime_x                                              0x895990
#define __get_melee_range_x                                        0x512350
#define __GetGaugeValueFromEQ_x                                    0x7A32F0
#define __GetLabelFromEQ_x                                         0x7A4540
#define __ToggleKeyRingItem_x                                      0x47E6E0
#define __GetXTargetType_x                                         0x926890
#define __LoadFrontEnd_x                                           0x632F20
#define __NewUIINI_x                                               0x7A2CC0
#define __ProcessGameEvents_x                                      0x576FB0
#define __ProcessMouseEvent_x                                      0x576750
#define CrashDetected_x                                            0x6348E0
#define wwsCrashReportCheckForUploader_x                           0x7F2900
#define DrawNetStatus_x                                            0x5AD190
#define Util__FastTime_x                                           0x8954A0
#define Expansion_HoT_x                                            0x1011AF8
#define __HelpPath_x                                               0x10951E8
#define __STMLToText_x                                             0x8DB4F0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420540
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B3A0
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B180

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C5130
#define AltAdvManager__IsAbilityReady_x                            0x4C51A0
#define AltAdvManager__GetAAById_x                                 0x4C5560
#define AltAdvManager__CanTrainAbility_x                           0x4C5E20
#define AltAdvManager__CanSeeAbility_x                             0x4C5A20

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463120
#define CharacterZoneClient__MakeMeVisible_x                       0x468B30
#define CharacterZoneClient__IsStackBlocked_x                      0x447280
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x446740
#define CharacterZoneClient__GetItemCountWorn_x                    0x460A70
#define CharacterZoneClient__GetItemCountInInventory_x             0x460B50
#define CharacterZoneClient__GetCursorItemCount_x                  0x460C30

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6629A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6709B0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58C3C0
#define CButtonWnd__CButtonWnd_x                                   0x8CF860

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68BB60
#define CChatManager__InitContextMenu_x                            0x68C6E0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D9850
#define CContextMenu__dCContextMenu_x                              0x8D9A60
#define CContextMenu__AddMenuItem_x                                0x8D9A70
#define CContextMenu__RemoveMenuItem_x                             0x8D9D60
#define CContextMenu__RemoveAllMenuItems_x                         0x8D9D80
#define CContextMenuManager__AddMenu_x                             0x8C5E60
#define CContextMenuManager__RemoveMenu_x                          0x8C61A0
#define CContextMenuManager__PopupMenu_x                           0x8C65F0
#define CContextMenuManager__Flush_x                               0x8C5ED0
#define CContextMenuManager__GetMenu_x                             0x4169E0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87A500
#define CChatService__GetFriendName_x                              0x87A510

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x691940
#define CChatWindow__Clear_x                                       0x691510
#define CChatWindow__WndNotification_x                             0x691E80

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C9C40
#define CComboWnd__Draw_x                                          0x8C9E50
#define CComboWnd__GetCurChoice_x                                  0x8C9A10
#define CComboWnd__GetListRect_x                                   0x8CA0F0
#define CComboWnd__GetTextRect_x                                   0x8C9CB0
#define CComboWnd__InsertChoice_x                                  0x8CA160
#define CComboWnd__SetColors_x                                     0x8C99A0
#define CComboWnd__SetChoice_x                                     0x8C99D0
#define CComboWnd__GetItemCount_x                                  0x8C9A00
#define CComboWnd__GetCurChoiceText_x                              0x8C9A50

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69AF10
#define CContainerWnd__vftable_x                                   0xAD69E8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B35C0
#define CDisplay__GetClickedActor_x                                0x4ABE90
#define CDisplay__GetUserDefinedColor_x                            0x4AAA70
#define CDisplay__GetWorldFilePath_x                               0x4A9EC0
#define CDisplay__is3dON_x                                         0x4A9350
#define CDisplay__ReloadUI_x                                       0x4BEAB0
#define CDisplay__WriteTextHD2_x                                   0x4AF910

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EFF20

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DDD80
#define CEditWnd__GetCharIndexPt_x                                 0x8DEE20
#define CEditWnd__GetDisplayString_x                               0x8DDF30
#define CEditWnd__GetHorzOffset_x                                  0x8DE270
#define CEditWnd__GetLineForPrintableChar_x                        0x8DE8E0
#define CEditWnd__GetSelStartPt_x                                  0x8DF0E0
#define CEditWnd__GetSTMLSafeText_x                                0x8DE410
#define CEditWnd__PointFromPrintableChar_x                         0x8DE9D0
#define CEditWnd__SelectableCharFromPoint_x                        0x8DEB50
#define CEditWnd__SetEditable_x                                    0x8DE3E0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x557F00
#define CEverQuest__CreateTargetIndicator_x                        0x558DF0
#define CEverQuest__DeleteTargetIndicator_x                        0x558E70
#define CEverQuest__DoTellWindow_x                                 0x473940
#define CEverQuest__DropHeldItemOnGround_x                         0x56EF30
#define CEverQuest__dsp_chat_x                                     0x473C80
#define CEverQuest__Emote_x                                        0x56D290
#define CEverQuest__EnterZone_x                                    0x5682C0
#define CEverQuest__GetBodyTypeDesc_x                              0x5522B0
#define CEverQuest__GetClassDesc_x                                 0x55BB80
#define CEverQuest__GetClassThreeLetterCode_x                      0x55C180
#define CEverQuest__GetDeityDesc_x                                 0x552B90
#define CEverQuest__GetLangDesc_x                                  0x552640
#define CEverQuest__GetRaceDesc_x                                  0x55C340
#define CEverQuest__InterpretCmd_x                                 0x560150
#define CEverQuest__LeftClickedOnPlayer_x                          0x5736A0
#define CEverQuest__LMouseUp_x                                     0x5757A0
#define CEverQuest__RightClickedOnPlayer_x                         0x5741B0
#define CEverQuest__RMouseUp_x                                     0x575200
#define CEverQuest__SetGameState_x                                 0x5587C0
#define CEverQuest__UPCNotificationFlush_x                         0x5500D0
#define CEverQuest__IssuePetCommand_x                              0x560B00

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6ABAF0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6ABB50
#define CGaugeWnd__Draw_x                                          0x6ABF80

// CGuild
#define CGuild__FindMemberByName_x                                 0x437140

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C87D0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D4F30
#define CInvSlotMgr__MoveItem_x                                    0x6D5DE0
#define CInvSlotMgr__SelectSlot_x                                  0x6D4FE0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D43E0
#define CInvSlot__SliderComplete_x                                 0x6D1C50
#define CInvSlot__GetItemBase_x                                    0x6D10C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D7210

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79FD40
#define CItemDisplayWnd__UpdateStrings_x                           0x6D9350

// CLabel 
#define CLabel__Draw_x                                             0x6F34E0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B5B60
#define CListWnd__dCListWnd_x                                      0x8B6B90
#define CListWnd__AddColumn_x                                      0x8B6B30
#define CListWnd__AddColumn1_x                                     0x8B63A0
#define CListWnd__AddLine_x                                        0x8B5E20
#define CListWnd__AddString_x                                      0x8B6030
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B2E90
#define CListWnd__CalculateVSBRange_x                              0x8B5010
#define CListWnd__ClearSel_x                                       0x8B21A0
#define CListWnd__ClearAllSel_x                                    0x8B2150
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B59F0
#define CListWnd__Compare_x                                        0x8B3990
#define CListWnd__Draw_x                                           0x8B4C20
#define CListWnd__DrawColumnSeparators_x                           0x8B4AB0
#define CListWnd__DrawHeader_x                                     0x8B2460
#define CListWnd__DrawItem_x                                       0x8B3FE0
#define CListWnd__DrawLine_x                                       0x8B4750
#define CListWnd__DrawSeparator_x                                  0x8B4B50
#define CListWnd__EnsureVisible_x                                  0x8B2FF0
#define CListWnd__ExtendSel_x                                      0x8B3EF0
#define CListWnd__GetColumnMinWidth_x                              0x8B1B10
#define CListWnd__GetColumnWidth_x                                 0x8B1A30
#define CListWnd__GetCurSel_x                                      0x8B1200
#define CListWnd__GetItemAtPoint_x                                 0x8B3290
#define CListWnd__GetItemAtPoint1_x                                0x8B3300
#define CListWnd__GetItemData_x                                    0x8B1540
#define CListWnd__GetItemHeight_x                                  0x8B2AF0
#define CListWnd__GetItemIcon_x                                    0x8B1720
#define CListWnd__GetItemRect_x                                    0x8B30D0
#define CListWnd__GetItemText_x                                    0x8B15D0
#define CListWnd__GetSelList_x                                     0x8B6290
#define CListWnd__GetSeparatorRect_x                               0x8B38C0
#define CListWnd__RemoveLine_x                                     0x8B6210
#define CListWnd__SetColors_x                                      0x8B1350
#define CListWnd__SetColumnJustification_x                         0x8B1DE0
#define CListWnd__SetColumnWidth_x                                 0x8B1AC0
#define CListWnd__SetCurSel_x                                      0x8B1240
#define CListWnd__SetItemColor_x                                   0x8B56D0
#define CListWnd__SetItemData_x                                    0x8B2200
#define CListWnd__SetItemText_x                                    0x8B5510
#define CListWnd__ShiftColumnSeparator_x                           0x8B53A0
#define CListWnd__Sort_x                                           0x8B6C90
#define CListWnd__ToggleSel_x                                      0x8B20D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70C450

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72DA20
#define CMerchantWnd__RequestBuyItem_x                             0x734AA0
#define CMerchantWnd__RequestSellItem_x                            0x735570
#define CMerchantWnd__SelectRecoverySlot_x                         0x72DCD0
#define CMerchantWnd__SelectBuySellSlot_x                          0x72CED0
#define CMerchantWnd__ActualSelect_x                               0x731970

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x8472A0
#define CPacketScrambler__hton_x                                   0x8472B0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D4840
#define CSidlManager__CreateLabel_x                                0x795CF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x659DA0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x659CC0
#define CSidlScreenWnd__ConvertToRes_x                             0x8EFE00
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CC5D0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CD790
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CD840
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CCD10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CBF80
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CB6E0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CC170
#define CSidlScreenWnd__Init1_x                                    0x8CD460
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CC680
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CB8A0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CCF50
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CB340
#define CSidlScreenWnd__StoreIniVis_x                              0x8CB690
#define CSidlScreenWnd__WndNotification_x                          0x8CD1E0
#define CSidlScreenWnd__GetChildItem_x                             0x8CB7B0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BF020

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F7B70
#define CSkillMgr__GetSkillCap_x                                   0x5F7D30
#define CSkillMgr__GetNameToken_x                                  0x5F7790

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EF0B0
#define CSliderWnd__SetValue_x                                     0x8EF280
#define CSliderWnd__SetNumTicks_x                                  0x8EFA00

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79D9A0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EAA00
#define CStmlWnd__CalculateHSBRange_x                              0x8E2F60
#define CStmlWnd__CalculateVSBRange_x                              0x8E2FF0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E3160
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E3A40
#define CStmlWnd__ForceParseNow_x                                  0x8EB3C0
#define CStmlWnd__GetNextTagPiece_x                                0x8E3940
#define CStmlWnd__GetSTMLText_x                                    0x690DA0
#define CStmlWnd__GetVisibleText_x                                 0x8E4490
#define CStmlWnd__InitializeWindowVariables_x                      0x8E6800
#define CStmlWnd__MakeStmlColorTag_x                               0x8E2260
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E22C0
#define CStmlWnd__SetSTMLText_x                                    0x8E8050
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EA6A0
#define CStmlWnd__UpdateHistoryString_x                            0x8E53C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E1970
#define CTabWnd__DrawCurrentPage_x                                 0x8E1200
#define CTabWnd__DrawTab_x                                         0x8E0FC0
#define CTabWnd__GetCurrentPage_x                                  0x8E15B0
#define CTabWnd__GetPageInnerRect_x                                0x8E0CB0
#define CTabWnd__GetTabInnerRect_x                                 0x8E0EB0
#define CTabWnd__GetTabRect_x                                      0x8E0D80
#define CTabWnd__InsertPage_x                                      0x8E1C60
#define CTabWnd__SetPage_x                                         0x8E15E0
#define CTabWnd__SetPageRect_x                                     0x8E18B0
#define CTabWnd__UpdatePage_x                                      0x8E1C00

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432F70

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C9610

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F5250

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AF2A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029A0
#define CXStr__CXStr1_x                                            0x73FB00
#define CXStr__CXStr3_x                                            0x892590
#define CXStr__dCXStr_x                                            0x7D13D0
#define CXStr__operator_equal_x                                    0x892700
#define CXStr__operator_equal1_x                                   0x892750
#define CXStr__operator_plus_equal1_x                              0x893850

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BE260
#define CXWnd__Center_x                                            0x8C4470
#define CXWnd__ClrFocus_x                                          0x8BDE20
#define CXWnd__DoAllDrawing_x                                      0x8C40C0
#define CXWnd__DrawChildren_x                                      0x8C4260
#define CXWnd__DrawColoredRect_x                                   0x8BE620
#define CXWnd__DrawTooltip_x                                       0x8BE8C0
#define CXWnd__DrawTooltipAtPoint_x                                0x8C3030
#define CXWnd__GetBorderFrame_x                                    0x8BECE0
#define CXWnd__GetChildWndAt_x                                     0x8C4E40
#define CXWnd__GetClientClipRect_x                                 0x8BEAE0
#define CXWnd__GetScreenClipRect_x                                 0x8C3730
#define CXWnd__GetScreenRect_x                                     0x8BEEB0
#define CXWnd__GetTooltipRect_x                                    0x8BE750
#define CXWnd__GetWindowTextA_x                                    0x424660
#define CXWnd__IsActive_x                                          0x8B9960
#define CXWnd__IsDescendantOf_x                                    0x8BEC20
#define CXWnd__IsReallyVisible_x                                   0x8C2060
#define CXWnd__IsType_x                                            0x8F1AB0
#define CXWnd__Move_x                                              0x8C1720
#define CXWnd__Move1_x                                             0x8C3D60
#define CXWnd__ProcessTransition_x                                 0x8BE200
#define CXWnd__Refade_x                                            0x8BDFD0
#define CXWnd__Resize_x                                            0x8BEF80
#define CXWnd__Right_x                                             0x8C3530
#define CXWnd__SetFocus_x                                          0x8C0870
#define CXWnd__SetFont_x                                           0x8BDE70
#define CXWnd__SetKeyTooltip_x                                     0x8BF1F0
#define CXWnd__SetMouseOver_x                                      0x8C3A40
#define CXWnd__StartFade_x                                         0x8BE2B0
#define CXWnd__GetChildItem_x                                      0x8C3980

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BB200
#define CXWndManager__DrawWindows_x                                0x8BAE40
#define CXWndManager__GetKeyboardFlags_x                           0x8B94A0
#define CXWndManager__HandleKeyboardMsg_x                          0x8B9DF0
#define CXWndManager__RemoveWnd_x                                  0x8B9AF0

// CDBStr
#define CDBStr__GetString_x                                        0x4A78C0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44D710
#define EQ_Character__Cur_HP_x                                     0x462810
#define EQ_Character__Cur_Mana_x                                   0x455D50
#define EQ_Character__GetAACastingTimeModifier_x                   0x446A50
#define EQ_Character__GetCharInfo2_x                               0x866810
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EDB0
#define EQ_Character__GetFocusRangeModifier_x                      0x43EE10
#define EQ_Character__Max_Endurance_x                              0x5BF680
#define EQ_Character__Max_HP_x                                     0x458880
#define EQ_Character__Max_Mana_x                                   0x5BF4B0
#define EQ_Character__doCombatAbility_x                            0x5BCBC0
#define EQ_Character__UseSkill_x                                   0x46DD70
#define EQ_Character__GetConLevel_x                                0x5B1810
#define EQ_Character__IsExpansionFlag_x                            0x423BA0
#define EQ_Character__TotalEffect_x                                0x44A960
#define EQ_Character__GetPCSpellAffect_x                           0x446E50
#define EQ_Character__SpellDuration_x                              0x444D50

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x591C30
#define EQ_Item__CreateItemTagString_x                             0x845C60
#define EQ_Item__IsStackable_x                                     0x83A5B0
#define EQ_Item__GetImageNum_x                                     0x83CFD0
#define EQ_Item__CreateItemClient_x                                0x592810
#define EQ_Item__GetItemValue_x                                    0x8449E0
#define EQ_Item__ValueSellMerchant_x                               0x846F00

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C7220
#define EQ_LoadingS__Array_x                                       0xC14530

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C0CD0
#define EQ_PC__GetAlternateAbilityId_x                             0x84F1B0
#define EQ_PC__GetCombatAbility_x                                  0x84F240
#define EQ_PC__GetCombatAbilityTimer_x                             0x84A0B0
#define EQ_PC__GetItemTimerValue_x                                 0x5BA6E0
#define EQ_PC__HasLoreItem_x                                       0x5B4D00
#define EQ_PC__AlertInventoryChanged_x                             0x5B17E0
#define EQ_PC__GetPcZoneClient_x                                   0x5DB320
#define EQ_PC__RemoveMyAffect_x                                    0x5B9B90

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5103B0
#define EQItemList__add_object_x                                   0x53CAE0
#define EQItemList__add_item_x                                     0x5102F0
#define EQItemList__delete_item_x                                  0x5107A0
#define EQItemList__FreeItemList_x                                 0x5106A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A6BF0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C6280
#define EQPlayer__dEQPlayer_x                                      0x5CF0E0
#define EQPlayer__DoAttack_x                                       0x5E1040
#define EQPlayer__EQPlayer_x                                       0x5D1500
#define EQPlayer__SetNameSpriteState_x                             0x5CC060
#define EQPlayer__SetNameSpriteTint_x                              0x5C76C0
#define PlayerBase__HasProperty_j_x                                0x922A50
#define EQPlayer__IsTargetable_x                                   0x923350
#define EQPlayer__CanSee_x                                         0x923870
#define PlayerZoneClient__ChangeHeight_x                           0x5E0F00
#define EQPlayer__CanSeeTargetIndicator_x                          0x923960

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D5820
#define EQPlayerManager__GetSpawnByName_x                          0x5D5C80
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D5850

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x597D20
#define KeypressHandler__AttachKeyToEqCommand_x                    0x597D60
#define KeypressHandler__ClearCommandStateArray_x                  0x597910
#define KeypressHandler__HandleKeyDown_x                           0x596270
#define KeypressHandler__HandleKeyUp_x                             0x596590
#define KeypressHandler__SaveKeymapping_x                          0x5979E0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x704DE0
#define MapViewMap__SaveEx_x                                       0x708110

#define PlayerPointManager__GetAltCurrency_x                       0x861850

// StringTable 
#define StringTable__getString_x                                   0x85C0B0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BF130
#define PcZoneClient__RemovePetEffect_x                            0x5BABB0
#define PcZoneClient__HasAlternateAbility_x                        0x5BB660

//Doors
#define EQSwitch__UseSwitch_x                                      0x54E910

//IconCache
#define IconCache__GetIcon_x                                       0x6A1480

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6982A0
#define CContainerMgr__CloseContainer_x                            0x698AC0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7662C0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58AE60

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DEEA0
#define EQ_Spell__SpellAffects_x                                   0x4DC550
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DC5C0
#define CharacterZoneClient__CalcAffectChange_x                    0x445E80
#define CLootWnd__LootAll_x                                        0x6FA640

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AB770
#define CTargetWnd__WndNotification_x                              0x7AB260
#define CTargetWnd__UpdateBuffs_x                                  0x7AB950

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B0950

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D7DB0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x496DD0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DD3B0
#define CSidlManager__FindAnimation1_x                             0x8D2740

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CE770
#define CAltAbilityData__GetMercMaxRank_x                          0x4CE720
#define CAltAbilityData__GetMaxRank_x                              0x4C37C0

//CTargetRing
#define CTargetRing__Cast_x                                        0x588740

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4545E0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x682CB0
#define CCastSpellWnd__IsBardSongPlaying_x                         0x682470

//messages
#define msg_spell_worn_off_x                                       0x4E6870
#define msg_new_text_x                                             0x4EFC00
#define msgTokenTextParam_x                                        0x4EC6D0

//SpellManager
#define SpellManager__vftable_x                                    0xAB2DB0
#define SpellManager__SpellManager_x                               0x47B580

