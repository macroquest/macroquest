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
#include "eqgame-private.h"
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Oct 26 2015"
#define __ExpectedVersionTime                                     "11:12:40"
#define __ActualVersionDate_x                                      0xAD0EA8
#define __ActualVersionTime_x                                      0xAD0EB4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x598AB0
#define __MemChecker1_x                                            0x89A6B0
#define __MemChecker2_x                                            0x631B60
#define __MemChecker3_x                                            0x631AB0
#define __MemChecker4_x                                            0x7E7DE0
#define __EncryptPad0_x                                            0xC67FE8
#define __EncryptPad1_x                                            0xDF1D98
#define __EncryptPad2_x                                            0xCB1AD0
#define __EncryptPad3_x                                            0xCB16D0
#define __EncryptPad4_x                                            0xDCC248
#define __EncryptPad5_x                                            0x119DB00
#define __AC1_x                                                    0x7A5085
#define __AC2_x                                                    0x54E057
#define __AC3_x                                                    0x562810
#define __AC4_x                                                    0x569490
#define __AC5_x                                                    0x57532E
#define __AC6_x                                                    0x578DD9
#define __AC7_x                                                    0x56F9DC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data                                                 0x845E8

// Direct Input
#define DI8__Main_x                                                0x119DAD8
#define DI8__Keyboard_x                                            0x119DADC
#define DI8__Mouse_x                                               0x119DAE0
#define DI8__Mouse_Copy_x                                          0x100C0F4
#define DI8__Mouse_Check_x                                         0x10959C4
#define __AltTimerReady_x                                          0xFFD441
#define __Attack_x                                                 0x1090663
#define __Autofire_x                                               0x1090664
#define __BindList_x                                               0xC2A0E0
#define __bCommandEnabled_x                                        0xFFB550
#define __Clicks_x                                                 0x100C1B0
#define __CommandList_x                                            0xC2E450
#define __CurrentMapLabel_x                                        0x11A3530
#define __CurrentSocial_x                                          0xBE3F44
#define __DoAbilityList_x                                          0x1042918
#define __do_loot_x                                                0x515540
#define __DrawHandler_x                                            0x180A27C
#define __GroupCount_x                                             0xFFCB1A

#define __Guilds_x                                                 0x1002730
#define __gWorld_x                                                 0xFFEFD4
#define __HotkeyPage_x                                             0x1089318
#define __HWnd_x                                                   0x10959E0
#define __InChatMode_x                                             0x100C0DC
#define __LastTell_x                                               0x100E020
#define __LMouseHeldTime_x                                         0x100C21C
#define __Mouse_x                                                  0x119DAE4
#define __MouseLook_x                                              0x100C176
#define __MouseEventTime_x                                         0x1090E6C
#define __gpbCommandEvent_x                                        0xFFF09C
#define __NetStatusToggle_x                                        0x100C179
#define __PCNames_x                                                0x100D640
#define __RangeAttackReady_x                                       0x100D300
#define __RMouseHeldTime_x                                         0x100C218
#define __RunWalkState_x                                           0x100C0E0
#define __ScreenMode_x                                             0xF4B308
#define __ScreenX_x                                                0x100C094
#define __ScreenY_x                                                0x100C090
#define __ScreenXMax_x                                             0x100C098
#define __ScreenYMax_x                                             0x100C09C
#define __ServerHost_x                                             0xFFCA64
#define __ServerName_x                                             0x10428D8
#define __ShiftKeyDown_x                                           0x100C784
#define __ShowNames_x                                              0x100D4D4
#define __Socials_x                                                0x10429D8
#define __SubscriptionType_x                                       0x11D1A60
#define __TargetAggroHolder_x                                      0x11A576C
#define __GroupAggro_x                                             0x11A57AC
#define __LoginName_x                                              0x10945B8
#define __Inviter_x                                                0x10905E0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xFFF0C0
#define instEQZoneInfo_x                                           0x100C36C
#define instKeypressHandler_x                                      0x1090E50
#define pinstActiveBanker_x                                        0xFFF078
#define pinstActiveCorpse_x                                        0xFFF07C
#define pinstActiveGMaster_x                                       0xFFF080
#define pinstActiveMerchant_x                                      0xFFF074
#define pinstAggroInfo_x                                           0xE0D778
#define pinstAltAdvManager_x                                       0xF4C408
#define pinstAuraMgr_x                                             0xE19648
#define pinstBandageTarget_x                                       0xFFF060
#define pinstCamActor_x                                            0xF4BD14
#define pinstCDBStr_x                                              0xF4B29C
#define pinstCDisplay_x                                            0xFFF088
#define pinstCEverQuest_x                                          0x119DC58
#define pinstCharData_x                                            0xFFF044
#define pinstCharSpawn_x                                           0xFFF06C
#define pinstControlledMissile_x                                   0xFFF040
#define pinstControlledPlayer_x                                    0xFFF06C
#define pinstCSidlManager_x                                        0x18096B4
#define pinstCXWndManager_x                                        0x18096AC
#define instDynamicZone_x                                          0x100BF28
#define pinstDZMember_x                                            0x100C038
#define pinstDZTimerInfo_x                                         0x100C03C
#define pinstEQItemList_x                                          0xFFB7A0
#define instEQMisc_x                                               0xC04C48
#define pinstEQSoundManager_x                                      0xF4C8E8
#define instExpeditionLeader_x                                     0x100BF72
#define instExpeditionName_x                                       0x100BFB2
#define pinstGroup_x                                               0xFFCB16
#define pinstImeManager_x                                          0x18096B8
#define pinstLocalPlayer_x                                         0xFFF058
#define pinstMercenaryData_x                                       0x10914A0
#define pinstMercenaryStats_x                                      0x11A58B8
#define pinstMercAltAbilities_x                                    0xF4C790
#define pinstModelPlayer_x                                         0xFFF084
#define pinstPCData_x                                              0xFFF044
#define pinstSkillMgr_x                                            0x10922D8
#define pinstSpawnManager_x                                        0x1091BC0
#define pinstSpellManager_x                                        0x1092420
#define pinstSpellSets_x                                           0x108937C
#define pinstStringTable_x                                         0xFFEFEC
#define pinstSwitchManager_x                                       0xFFC6A8
#define pinstTarget_x                                              0xFFF070
#define pinstTargetObject_x                                        0xFFF048
#define pinstTargetSwitch_x                                        0xFFF04C
#define pinstTaskMember_x                                          0xF4B1E8
#define pinstTrackTarget_x                                         0xFFF064
#define pinstTradeTarget_x                                         0xFFF054
#define instTributeActive_x                                        0xC04C6D
#define pinstViewActor_x                                           0xF4BD10
#define pinstWorldData_x                                           0xFFF028
#define pinstZoneAddr_x                                            0x100C62C
#define pinstPlayerPath_x                                          0x1091C20
#define pinstTargetIndicator_x                                     0x10925B8
#define pinstCTargetManager_x                                      0x1092618
//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE0DC58
#define pinstCAudioTriggersWindow_x                                0xE0DAE8
#define pinstCCharacterSelect_x                                    0xF4BBAC
#define pinstCFacePick_x                                           0xF4B95C
#define pinstCNoteWnd_x                                            0xF4BB64
#define pinstCBookWnd_x                                            0xF4BB6C
#define pinstCPetInfoWnd_x                                         0xF4BB70
#define pinstCTrainWnd_x                                           0xF4BB74
#define pinstCSkillsWnd_x                                          0xF4BB78
#define pinstCSkillsSelectWnd_x                                    0xF4BB7C
#define pinstCCombatSkillsSelectWnd_x                              0xF4BB80
#define pinstCFriendsWnd_x                                         0xF4BB84
#define pinstCAuraWnd_x                                            0xF4BB88
#define pinstCRespawnWnd_x                                         0xF4BB8C
#define pinstCBandolierWnd_x                                       0xF4BB90
#define pinstCPotionBeltWnd_x                                      0xF4BB94
#define pinstCAAWnd_x                                              0xF4BB98
#define pinstCGroupSearchFiltersWnd_x                              0xF4BB9C
#define pinstCLoadskinWnd_x                                        0xF4BBA0
#define pinstCAlarmWnd_x                                           0xF4BBA4
#define pinstCMusicPlayerWnd_x                                     0xF4BBA8
#define pinstCMailWnd_x                                            0xF4BBB0
#define pinstCMailCompositionWnd_x                                 0xF4BBB4
#define pinstCMailAddressBookWnd_x                                 0xF4BBB8
#define pinstCRaidWnd_x                                            0xF4BBC0
#define pinstCRaidOptionsWnd_x                                     0xF4BBC4
#define pinstCBreathWnd_x                                          0xF4BBC8
#define pinstCMapViewWnd_x                                         0xF4BBCC
#define pinstCMapToolbarWnd_x                                      0xF4BBD0
#define pinstCEditLabelWnd_x                                       0xF4BBD4
#define pinstCTargetWnd_x                                          0xF4BBD8
#define pinstCColorPickerWnd_x                                     0xF4BBDC
#define pinstCPlayerWnd_x                                          0xF4BBE0
#define pinstCOptionsWnd_x                                         0xF4BBE4
#define pinstCBuffWindowNORMAL_x                                   0xF4BBE8
#define pinstCBuffWindowSHORT_x                                    0xF4BBEC
#define pinstCharacterCreation_x                                   0xF4BBF0
#define pinstCCursorAttachment_x                                   0xF4BBF4
#define pinstCCastingWnd_x                                         0xF4BBF8
#define pinstCCastSpellWnd_x                                       0xF4BBFC
#define pinstCSpellBookWnd_x                                       0xF4BC00
#define pinstCInventoryWnd_x                                       0xF4BC04
#define pinstCBankWnd_x                                            0xF4BC08
#define pinstCQuantityWnd_x                                        0xF4BC0C
#define pinstCLootWnd_x                                            0xF4BC10
#define pinstCActionsWnd_x                                         0xF4BC14
#define pinstCCombatAbilityWnd_x                                   0xF4BC18
#define pinstCMerchantWnd_x                                        0xF4BC1C
#define pinstCTradeWnd_x                                           0xF4BC20
#define pinstCSelectorWnd_x                                        0xF4BC24
#define pinstCBazaarWnd_x                                          0xF4BC28
#define pinstCBazaarSearchWnd_x                                    0xF4BC2C
#define pinstCGiveWnd_x                                            0xF4BC48
#define pinstCTrackingWnd_x                                        0xF4BC50
#define pinstCInspectWnd_x                                         0xF4BC54
#define pinstCSocialEditWnd_x                                      0xF4BC58
#define pinstCFeedbackWnd_x                                        0xF4BC5C
#define pinstCBugReportWnd_x                                       0xF4BC60
#define pinstCVideoModesWnd_x                                      0xF4BC64
#define pinstCTextEntryWnd_x                                       0xF4BC6C
#define pinstCFileSelectionWnd_x                                   0xF4BC70
#define pinstCCompassWnd_x                                         0xF4BC74
#define pinstCPlayerNotesWnd_x                                     0xF4BC78
#define pinstCGemsGameWnd_x                                        0xF4BC7C
#define pinstCTimeLeftWnd_x                                        0xF4BC80
#define pinstCPetitionQWnd_x                                       0xF4BC98
#define pinstCSoulmarkWnd_x                                        0xF4BC9C
#define pinstCStoryWnd_x                                           0xF4BCA0
#define pinstCJournalTextWnd_x                                     0xF4BCA4
#define pinstCJournalCatWnd_x                                      0xF4BCA8
#define pinstCBodyTintWnd_x                                        0xF4BCAC
#define pinstCServerListWnd_x                                      0xF4BCB0
#define pinstCAvaZoneWnd_x                                         0xF4BCBC
#define pinstCBlockedBuffWnd_x                                     0xF4BCC0
#define pinstCBlockedPetBuffWnd_x                                  0xF4BCC4
#define pinstCInvSlotMgr_x                                         0xF4BD08
#define pinstCContainerMgr_x                                       0xF4BD0C
#define pinstCAdventureLeaderboardWnd_x                            0x119E608
#define pinstCAdventureRequestWnd_x                                0x119E680
#define pinstCAltStorageWnd_x                                      0x119E960
#define pinstCAdventureStatsWnd_x                                  0x119E6F8
#define pinstCBarterMerchantWnd_x                                  0x119F548
#define pinstCBarterSearchWnd_x                                    0x119F5C0
#define pinstCBarterWnd_x                                          0x119F638
#define pinstCChatManager_x                                        0x119FCC8
#define pinstCDynamicZoneWnd_x                                     0x11A0178
#define pinstCEQMainWnd_x                                          0x11A0310
#define pinstCFellowshipWnd_x                                      0x11A010C
#define pinstCFindLocationWnd_x                                    0x11A05E0
#define pinstCGroupSearchWnd_x                                     0x11A08B0
#define pinstCGroupWnd_x                                           0x11A0928
#define pinstCGuildBankWnd_x                                       0x11A09A0
#define pinstCGuildMgmtWnd_x                                       0x11A2A90
#define pinstCHotButtonWnd_x                                       0x11A2B5C
#define pinstCHotButtonWnd1_x                                      0x11A2B5C
#define pinstCHotButtonWnd2_x                                      0x11A2B60
#define pinstCHotButtonWnd3_x                                      0x11A2B64
#define pinstCHotButtonWnd4_x                                      0x11A2B88
#define pinstCItemDisplayManager_x                                 0x11A2E80
#define pinstCItemExpTransferWnd_x                                 0x11A2EFC
#define pinstCLFGuildWnd_x                                         0x11A31D8
#define pinstCMIZoneSelectWnd_x                                    0x11A37C0
#define pinstCConfirmationDialog_x                                 0x11A3EC8
#define pinstCPopupWndManager_x                                    0x11A3EC8
#define pinstCProgressionSelectionWnd_x                            0x11A3FB8
#define pinstCPvPStatsWnd_x                                        0x11A40A8
#define pinstCSystemInfoDialogBox_x                                0x11A47B0
#define pinstCTaskWnd_x                                            0x11A5B78
#define pinstCTaskSomething_x                                      0xE19D90
#define pinstCTaskTemplateSelectWnd_x                              0x11A5B00
#define pinstCTipWndOFDAY_x                                        0x11A5DD0
#define pinstCTipWndCONTEXT_x                                      0x11A5DD4
#define pinstCTitleWnd_x                                           0x11A5E50
#define pinstCContextMenuManager_x                                 0x1809624
#define pinstCVoiceMacroWnd_x                                      0x1092A88
#define pinstCHtmlWnd_x                                            0x1092B80
#define pinstIconCache_x                                           0x11A02E4
#define pinstCTradeskillWnd_x                                      0x11A5F50
#define pinstCAdvancedLootWnd_x                                    0xF4BCFC
#define pinstRewardSelectionWnd_x                                  0x11A45D0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x52D060
#define __ConvertItemTags_x                                        0x51A1C0
#define __ExecuteCmd_x                                             0x504CC0
#define __EQGetTime_x                                              0x89AA10
#define __get_melee_range_x                                        0x50B980
#define __GetGaugeValueFromEQ_x                                    0x7A3DC0
#define __GetLabelFromEQ_x                                         0x7A5010
#define __ToggleMount_x                                            0x6CCCE0
#define __GetXTargetType_x                                         0x92BBF0
#define __LoadFrontEnd_x                                           0x631210
#define __NewUIINI_x                                               0x7A36C0
#define __ProcessGameEvents_x                                      0x571740
#define __ProcessMouseEvent_x                                      0x570EE0
#define CrashDetected_x                                            0x632CE0
#define wwsCrashReportCheckForUploader_x                           0x7F78E0
#define DrawNetStatus_x                                            0x5A8520
#define Util__FastTime_x                                           0x89A360
#define Expansion_HoT_x                                            0x100D46C
#define __HelpPath_x                                               0x1090BD8
#define __STMLToText_x                                             0x8DF510

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41EFF0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419E40

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C19C0
#define AltAdvManager__IsAbilityReady_x                            0x4C1A30
#define AltAdvManager__GetAAById_x                                 0x4C1DF0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463D10
#define CharacterZoneClient__MakeMeVisible_x                       0x4696F0
#define CharacterZoneClient__IsStackBlocked_x                      0x4461D0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x660DC0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66F250

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x587B00
#define CButtonWnd__CButtonWnd_x                                   0x8D37B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68A290
#define CChatManager__InitContextMenu_x                            0x68AE10

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DD870
#define CContextMenu__dCContextMenu_x                              0x8DDA80
#define CContextMenu__AddMenuItem_x                                0x8DDA90
#define CContextMenu__RemoveMenuItem_x                             0x8DDD80
#define CContextMenu__RemoveAllMenuItems_x                         0x8DDDA0
#define CContextMenuManager__AddMenu_x                             0x8C9720
#define CContextMenuManager__RemoveMenu_x                          0x8C9A70
#define CContextMenuManager__PopupMenu_x                           0x8C9EC0
#define CContextMenuManager__Flush_x                               0x8C9790
#define CContextMenuManager__GetMenu_x                             0x415490

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x880810
#define CChatService__GetFriendName_x                              0x880820

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6900B0
#define CChatWindow__Clear_x                                       0x68FC70
#define CChatWindow__WndNotification_x                             0x6905F0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CD640
#define CComboWnd__Draw_x                                          0x8CD850
#define CComboWnd__GetCurChoice_x                                  0x8CD410
#define CComboWnd__GetListRect_x                                   0x8CDAF0
#define CComboWnd__GetTextRect_x                                   0x8CD6B0
#define CComboWnd__InsertChoice_x                                  0x8CDB60
#define CComboWnd__SetColors_x                                     0x8CD3A0
#define CComboWnd__SetChoice_x                                     0x8CD3D0
#define CComboWnd__GetItemCount_x                                  0x8CD400

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x699870
#define CContainerWnd__vftable_x                                   0xADA840

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4AFCC0
#define CDisplay__GetClickedActor_x                                0x4A8840
#define CDisplay__GetUserDefinedColor_x                            0x4A7100
#define CDisplay__GetWorldFilePath_x                               0x4A6550
#define CDisplay__is3dON_x                                         0x4A5920
#define CDisplay__ReloadUI_x                                       0x4BB1E0
#define CDisplay__WriteTextHD2_x                                   0x4AC060

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F3F40

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E2280
#define CEditWnd__GetCharIndexPt_x                                 0x8E3320
#define CEditWnd__GetDisplayString_x                               0x8E2430
#define CEditWnd__GetHorzOffset_x                                  0x8E2770
#define CEditWnd__GetLineForPrintableChar_x                        0x8E2DE0
#define CEditWnd__GetSelStartPt_x                                  0x8E35E0
#define CEditWnd__GetSTMLSafeText_x                                0x8E2910
#define CEditWnd__PointFromPrintableChar_x                         0x8E2ED0
#define CEditWnd__SelectableCharFromPoint_x                        0x8E3050
#define CEditWnd__SetEditable_x                                    0x8E28E0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54E7A0
#define CEverQuest__CreateTargetIndicator_x                        0x54F3D0
#define CEverQuest__DeleteTargetIndicator_x                        0x54F450
#define CEverQuest__DoTellWindow_x                                 0x5541A0
#define CEverQuest__DropHeldItemOnGround_x                         0x55CC90
#define CEverQuest__dsp_chat_x                                     0x555940
#define CEverQuest__Emote_x                                        0x555BA0
#define CEverQuest__EnterZone_x                                    0x569CC0
#define CEverQuest__GetBodyTypeDesc_x                              0x54B000
#define CEverQuest__GetClassDesc_x                                 0x550D10
#define CEverQuest__GetClassThreeLetterCode_x                      0x551310
#define CEverQuest__GetDeityDesc_x                                 0x54B8E0
#define CEverQuest__GetLangDesc_x                                  0x54B390
#define CEverQuest__GetRaceDesc_x                                  0x5514D0
#define CEverQuest__InterpretCmd_x                                 0x556480
#define CEverQuest__LeftClickedOnPlayer_x                          0x56DE40
#define CEverQuest__LMouseUp_x                                     0x56FF30
#define CEverQuest__RightClickedOnPlayer_x                         0x56E940
#define CEverQuest__RMouseUp_x                                     0x56F990
#define CEverQuest__SetGameState_x                                 0x54EE50
#define CEverQuest__UPCNotificationFlush_x                         0x5575E0
#define CEverQuest__IssuePetCommand_x                              0x557140

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AA5D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AA630
#define CGaugeWnd__Draw_x                                          0x6AAA60

// CGuild
#define CGuild__FindMemberByName_x                                 0x435C30

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C7700

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D5520
#define CInvSlotMgr__MoveItem_x                                    0x6D6460
#define CInvSlotMgr__SelectSlot_x                                  0x6D55D0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D49B0
#define CInvSlot__SliderComplete_x                                 0x6D2380
#define CInvSlot__GetItemBase_x                                    0x6D1800

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D7610

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A0760
#define CItemDisplayWnd__UpdateStrings_x                           0x6D8940

// CLabel 
#define CLabel__Draw_x                                             0x6F3780

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B9220
#define CListWnd__dCListWnd_x                                      0x8BA250
#define CListWnd__AddColumn_x                                      0x8BA1F0
#define CListWnd__AddColumn1_x                                     0x8B9A60
#define CListWnd__AddLine_x                                        0x8B94E0
#define CListWnd__AddString_x                                      0x8B96F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B6550
#define CListWnd__CalculateVSBRange_x                              0x8B86E0
#define CListWnd__ClearAllSel_x                                    0x8B5800
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B90B0
#define CListWnd__Compare_x                                        0x8B7060
#define CListWnd__Draw_x                                           0x8B82F0
#define CListWnd__DrawColumnSeparators_x                           0x8B8180
#define CListWnd__DrawHeader_x                                     0x8B5B10
#define CListWnd__DrawItem_x                                       0x8B76B0
#define CListWnd__DrawLine_x                                       0x8B7E20
#define CListWnd__DrawSeparator_x                                  0x8B8220
#define CListWnd__EnsureVisible_x                                  0x8B66B0
#define CListWnd__ExtendSel_x                                      0x8B75C0
#define CListWnd__GetColumnMinWidth_x                              0x8B51C0
#define CListWnd__GetColumnWidth_x                                 0x8B50E0
#define CListWnd__GetCurSel_x                                      0x8B48B0
#define CListWnd__GetItemAtPoint_x                                 0x8B6950
#define CListWnd__GetItemAtPoint1_x                                0x8B69C0
#define CListWnd__GetItemData_x                                    0x8B4C00
#define CListWnd__GetItemHeight_x                                  0x8B61A0
#define CListWnd__GetItemIcon_x                                    0x8B4DE0
#define CListWnd__GetItemRect_x                                    0x8B6790
#define CListWnd__GetItemText_x                                    0x8B4C90
#define CListWnd__GetSelList_x                                     0x8B9950
#define CListWnd__GetSeparatorRect_x                               0x8B6F80
#define CListWnd__RemoveLine_x                                     0x8B98D0
#define CListWnd__SetColors_x                                      0x8B4A00
#define CListWnd__SetColumnJustification_x                         0x8B5490
#define CListWnd__SetColumnWidth_x                                 0x8B5170
#define CListWnd__SetCurSel_x                                      0x8B48F0
#define CListWnd__SetItemColor_x                                   0x8B8D90
#define CListWnd__SetItemData_x                                    0x8B58B0
#define CListWnd__SetItemText_x                                    0x8B8BD0
#define CListWnd__ShiftColumnSeparator_x                           0x8B8A60
#define CListWnd__Sort_x                                           0x8BA350
#define CListWnd__ToggleSel_x                                      0x8B5780

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70CE20

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72DF90
#define CMerchantWnd__RequestBuyItem_x                             0x734DB0
#define CMerchantWnd__RequestSellItem_x                            0x735800
#define CMerchantWnd__SelectRecoverySlot_x                         0x72E240
#define CMerchantWnd__SelectBuySellSlot_x                          0x72D4A0
#define CMerchantWnd__ActualSelect_x                               0x731CE0

// CObfuscator
#define CObfuscator__doit_x                                        0x860BD0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D87F0
#define CSidlManager__CreateLabel_x                                0x796780

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x657FD0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x657F00
#define CSidlScreenWnd__ConvertToRes_x                             0x8F3E20
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D02E0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D17E0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D1890
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D0D50
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CFC90
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CF3D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CFE80
#define CSidlScreenWnd__Init1_x                                    0x8D14B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D0390
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CF590
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D0FA0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CEEA0
#define CSidlScreenWnd__StoreIniVis_x                              0x8CF360
#define CSidlScreenWnd__WndNotification_x                          0x8D1230
#define CSidlScreenWnd__GetChildItem_x                             0x8CF4A0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C28F0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F2E70
#define CSkillMgr__GetSkillCap_x                                   0x5F3030
#define CSkillMgr__GetNameToken_x                                  0x5F2A90

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F30D0
#define CSliderWnd__SetValue_x                                     0x8F32A0
#define CSliderWnd__SetNumTicks_x                                  0x8F3A20

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79E410

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EDAB0
#define CStmlWnd__CalculateHSBRange_x                              0x8E5FC0
#define CStmlWnd__CalculateVSBRange_x                              0x8E6050
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E61D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E6AB0
#define CStmlWnd__ForceParseNow_x                                  0x8EE400
#define CStmlWnd__GetNextTagPiece_x                                0x8E69B0
#define CStmlWnd__GetSTMLText_x                                    0x68F510
#define CStmlWnd__GetVisibleText_x                                 0x8E7500
#define CStmlWnd__InitializeWindowVariables_x                      0x8E9890
#define CStmlWnd__MakeStmlColorTag_x                               0x8E52C0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E5320
#define CStmlWnd__SetSTMLText_x                                    0x8EB0F0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8ED750
#define CStmlWnd__UpdateHistoryString_x                            0x8E8440

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F5670
#define CTabWnd__DrawCurrentPage_x                                 0x8F4EE0
#define CTabWnd__DrawTab_x                                         0x8F4CA0
#define CTabWnd__GetCurrentPage_x                                  0x8F52B0
#define CTabWnd__GetPageInnerRect_x                                0x8F4990
#define CTabWnd__GetTabInnerRect_x                                 0x8F4B90
#define CTabWnd__GetTabRect_x                                      0x8F4A60
#define CTabWnd__InsertPage_x                                      0x8F5960
#define CTabWnd__SetPage_x                                         0x8F52E0
#define CTabWnd__SetPageRect_x                                     0x8F55B0
#define CTabWnd__UpdatePage_x                                      0x8F5900

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4319B0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CD010

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FA850

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B2B10

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x595060
#define CXStr__CXStr1_x                                            0x402280
#define CXStr__CXStr3_x                                            0x8973F0
#define CXStr__dCXStr_x                                            0x479400
#define CXStr__operator_equal_x                                    0x897560
#define CXStr__operator_equal1_x                                   0x8975B0
#define CXStr__operator_plus_equal1_x                              0x898690

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C1B00
#define CXWnd__Center_x                                            0x8C7CE0
#define CXWnd__ClrFocus_x                                          0x8C16F0
#define CXWnd__DoAllDrawing_x                                      0x8C7930
#define CXWnd__DrawChildren_x                                      0x8C7AD0
#define CXWnd__DrawColoredRect_x                                   0x8C1EC0
#define CXWnd__DrawTooltip_x                                       0x8C2170
#define CXWnd__DrawTooltipAtPoint_x                                0x8C68B0
#define CXWnd__GetBorderFrame_x                                    0x8C25C0
#define CXWnd__GetChildWndAt_x                                     0x8C86A0
#define CXWnd__GetClientClipRect_x                                 0x8C2390
#define CXWnd__GetScreenClipRect_x                                 0x8C6FB0
#define CXWnd__GetScreenRect_x                                     0x8C2790
#define CXWnd__GetTooltipRect_x                                    0x8C2000
#define CXWnd__GetWindowTextA_x                                    0x422F10
#define CXWnd__IsActive_x                                          0x8BD090
#define CXWnd__IsDescendantOf_x                                    0x8C2500
#define CXWnd__IsReallyVisible_x                                   0x8C58C0
#define CXWnd__IsType_x                                            0x8F7030
#define CXWnd__Move_x                                              0x8C4FE0
#define CXWnd__Move1_x                                             0x8C75D0
#define CXWnd__ProcessTransition_x                                 0x8C1AB0
#define CXWnd__Refade_x                                            0x8C1890
#define CXWnd__Resize_x                                            0x8C2860
#define CXWnd__Right_x                                             0x8C6DB0
#define CXWnd__SetFocus_x                                          0x8C4120
#define CXWnd__SetFont_x                                           0x8C1740
#define CXWnd__SetKeyTooltip_x                                     0x8C2AC0
#define CXWnd__SetMouseOver_x                                      0x8C72B0
#define CXWnd__StartFade_x                                         0x8C1B50
#define CXWnd__GetChildItem_x                                      0x8C71F0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BE9D0
#define CXWndManager__DrawWindows_x                                0x8BE610
#define CXWndManager__GetKeyboardFlags_x                           0x8BCBC0
#define CXWndManager__HandleKeyboardMsg_x                          0x8BD530
#define CXWndManager__RemoveWnd_x                                  0x8BD220

// CDBStr
#define CDBStr__GetString_x                                        0x4A3E70

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44DE60
#define EQ_Character__Cur_HP_x                                     0x4633E0
#define EQ_Character__GetAACastingTimeModifier_x                   0x445D50
#define EQ_Character__GetCharInfo2_x                               0x86B3C0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43DDB0
#define EQ_Character__GetFocusRangeModifier_x                      0x43DFA0
#define EQ_Character__Max_Endurance_x                              0x5BA560
#define EQ_Character__Max_HP_x                                     0x459070
#define EQ_Character__Max_Mana_x                                   0x5BA390
#define EQ_Character__doCombatAbility_x                            0x5B7970
#define EQ_Character__UseSkill_x                                   0x46E8E0
#define EQ_Character__GetConLevel_x                                0x5ACB80
#define EQ_Character__IsExpansionFlag_x                            0x422450
#define EQ_Character__TotalEffect_x                                0x44B100

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58D2D0
#define EQ_Item__CreateItemTagString_x                             0x84AD00
#define EQ_Item__IsStackable_x                                     0x83F100
#define EQ_Item__GetImageNum_x                                     0x841DB0
#define EQ_Item__CreateItemClient_x                                0x58DE70
#define EQ_Item__GetItemValue_x                                    0x8499A0
#define EQ_Item__ValueSellMerchant_x                               0x84C060

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C3AF0
#define EQ_LoadingS__Array_x                                       0xC12A20

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BBCF0
#define EQ_PC__GetAlternateAbilityId_x                             0x853F70
#define EQ_PC__GetCombatAbility_x                                  0x854000
#define EQ_PC__GetCombatAbilityTimer_x                             0x84EFD0
#define EQ_PC__GetItemTimerValue_x                                 0x5B5750
#define EQ_PC__HasLoreItem_x                                       0x5AFED0
#define EQ_PC__AlertInventoryChanged_x                             0x5ACB50
#define EQ_PC__GetPcZoneClient_x                                   0x5D6360
#define EQ_PC__RemoveMyAffect_x									   0x5B4C60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5099E0
#define EQItemList__add_item_x                                     0x509920
#define EQItemList__delete_item_x                                  0x509DE0
#define EQItemList__FreeItemList_x                                 0x509CE0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A3180

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C1280
#define EQPlayer__dEQPlayer_x                                      0x5CA100
#define EQPlayer__DoAttack_x                                       0x5DC270
#define EQPlayer__EQPlayer_x                                       0x5CC520
#define EQPlayer__SetNameSpriteState_x                             0x5C6DD0
#define EQPlayer__SetNameSpriteTint_x                              0x5C2690
#define EQPlayer__IsBodyType_j_x                                   0x927E30
#define EQPlayer__IsTargetable_x                                   0x928730
#define EQPlayer__CanSee_x                                         0x928C50
#define PlayerZoneClient__ChangeHeight_x                           0x5DC130
#define EQPlayer__CanSeeTargetIndicator_x                          0x928D40

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D0890
#define EQPlayerManager__GetSpawnByName_x                          0x5D0CF0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x593390
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5933D0
#define KeypressHandler__ClearCommandStateArray_x                  0x592F70
#define KeypressHandler__HandleKeyDown_x                           0x5918D0
#define KeypressHandler__HandleKeyUp_x                             0x591BF0
#define KeypressHandler__SaveKeymapping_x                          0x593040

// MapViewMap 
#define MapViewMap__Clear_x                                        0x705200
#define MapViewMap__SaveEx_x                                       0x708AE0

#define PlayerPointManager__GetAltCurrency_x                       0x866390

// StringTable 
#define StringTable__getString_x                                   0x860E70

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BA010
#define PcZoneClient__RemovePetEffect_x                            0x5B5980

//Doors
#define EQSwitch__UseSwitch_x                                      0x548440

//IconCache
#define IconCache__GetIcon_x                                       0x69FCE0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x696B80
#define CContainerMgr__CloseContainer_x                            0x6973A0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7669F0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5865C0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DA210
#define EQ_Spell__SpellAffects_x                                   0x4DA2B0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DA2E0
#define CharacterZoneClient__CalcAffectChange_x                    0x447140
#define CLootWnd__LootAll_x                                        0x6FAA90

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AC360
#define CTargetWnd__WndNotification_x                              0x7ABE50

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B1540

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D3A60

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4934E0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E18B0
#define CSidlManager__FindAnimation1_x                             0x8D66E0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CB250
#define CAltAbilityData__GetMercMaxRank_x                          0x4CB200
#define CAltAbilityData__GetMaxRank_x                              0x4C0080

//CTargetRing
#define CTargetRing__Cast_x 0x583EB0