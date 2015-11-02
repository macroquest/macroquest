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
#define __ExpectedVersionDate                                     "Nov  1 2015"
#define __ExpectedVersionTime                                     "03:25:30"
#define __ActualVersionDate_x                                      0xAD7580
#define __ActualVersionTime_x                                      0xAD758C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59EB40
#define __MemChecker1_x                                            0x89F6E0
#define __MemChecker2_x                                            0x637EF0
#define __MemChecker3_x                                            0x637E40
#define __MemChecker4_x                                            0x7EC8C0
#define __EncryptPad0_x                                            0xC71CF8
#define __EncryptPad1_x                                            0xDFBAC8
#define __EncryptPad2_x                                            0xCBB7E0
#define __EncryptPad3_x                                            0xCBB3E0
#define __EncryptPad4_x                                            0xDD5F68
#define __EncryptPad5_x                                            0x11A7938
#define __AC1_x                                                    0x7A9C05
#define __AC2_x                                                    0x553DC7
#define __AC3_x                                                    0x568790
#define __AC4_x                                                    0x56F2D0
#define __AC5_x                                                    0x57B17E
#define __AC6_x                                                    0x57EC29
#define __AC7_x                                                    0x57582C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data                                                 0x845E8

// Direct Input
#define DI8__Main_x                                                0x11A7910
#define DI8__Keyboard_x                                            0x11A7914
#define DI8__Mouse_x                                               0x11A7918
#define DI8__Mouse_Copy_x                                          0x1015F2C
#define DI8__Mouse_Check_x                                         0x109F7FC
#define __AltTimerReady_x                                          0x1007279
#define __Attack_x                                                 0x109A49B
#define __Autofire_x                                               0x109A49C
#define __BindList_x                                               0xC33DD0
#define __bCommandEnabled_x                                        0x1005388
#define __Clicks_x                                                 0x1015FE8
#define __CommandList_x                                            0xC38140
#define __CurrentMapLabel_x                                        0x11AD368
#define __CurrentSocial_x                                          0xBEAF44
#define __DoAbilityList_x                                          0x104C750
#define __do_loot_x                                                0x51B440
#define __DrawHandler_x                                            0x18140BC
#define __GroupCount_x                                             0x1006952

#define __Guilds_x                                                 0x100C568
#define __gWorld_x                                                 0x1008E0C
#define __HotkeyPage_x                                             0x1093150
#define __HWnd_x                                                   0x109F818
#define __InChatMode_x                                             0x1015F14
#define __LastTell_x                                               0x1017E58
#define __LMouseHeldTime_x                                         0x1016054
#define __Mouse_x                                                  0x11A791C
#define __MouseLook_x                                              0x1015FAE
#define __MouseEventTime_x                                         0x109ACA4
#define __gpbCommandEvent_x                                        0x1008ED4
#define __NetStatusToggle_x                                        0x1015FB1
#define __PCNames_x                                                0x1017478
#define __RangeAttackReady_x                                       0x1017138
#define __RMouseHeldTime_x                                         0x1016050
#define __RunWalkState_x                                           0x1015F18
#define __ScreenMode_x                                             0xF550C0
#define __ScreenX_x                                                0x1015ECC
#define __ScreenY_x                                                0x1015EC8
#define __ScreenXMax_x                                             0x1015ED0
#define __ScreenYMax_x                                             0x1015ED4
#define __ServerHost_x                                             0x100689C
#define __ServerName_x                                             0x104C710
#define __ShiftKeyDown_x                                           0x10165BC
#define __ShowNames_x                                              0x101730C
#define __Socials_x                                                0x104C810
#define __SubscriptionType_x                                       0x11DB898
#define __TargetAggroHolder_x                                      0x11AF5A4
#define __GroupAggro_x                                             0x11AF5E4
#define __LoginName_x                                              0x109E3F0
#define __Inviter_x                                                0x109A418


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x1008EF8
#define instEQZoneInfo_x                                           0x10161A4
#define instKeypressHandler_x                                      0x109AC88
#define pinstActiveBanker_x                                        0x1008EB0
#define pinstActiveCorpse_x                                        0x1008EB4
#define pinstActiveGMaster_x                                       0x1008EB8
#define pinstActiveMerchant_x                                      0x1008EAC
#define pinstAggroInfo_x                                           0xE174B8
#define pinstAltAdvManager_x                                       0xF561C8
#define pinstAuraMgr_x                                             0xE23388
#define pinstBandageTarget_x                                       0x1008E98
#define pinstCamActor_x                                            0xF55AD0
#define pinstCDBStr_x                                              0xF55054
#define pinstCDisplay_x                                            0x1008EC0
#define pinstCEverQuest_x                                          0x11A7A90
#define pinstCharData_x                                            0x1008E7C
#define pinstCharSpawn_x                                           0x1008EA4
#define pinstControlledMissile_x                                   0x1008E78
#define pinstControlledPlayer_x                                    0x1008EA4
#define pinstCSidlManager_x                                        0x18134F4
#define pinstCXWndManager_x                                        0x18134EC
#define instDynamicZone_x                                          0x1015D60
#define pinstDZMember_x                                            0x1015E70
#define pinstDZTimerInfo_x                                         0x1015E74
#define pinstEQItemList_x                                          0x10055D8
#define instEQMisc_x                                               0xC0D2C0
#define pinstEQSoundManager_x                                      0xF56720
#define instExpeditionLeader_x                                     0x1015DAA
#define instExpeditionName_x                                       0x1015DEA
#define pinstGroup_x                                               0x100694E
#define pinstImeManager_x                                          0x18134F8
#define pinstLocalPlayer_x                                         0x1008E90
#define pinstMercenaryData_x                                       0x109B2D8
#define pinstMercenaryStats_x                                      0x11AF6F0
#define pinstMercAltAbilities_x                                    0xF56550
#define pinstModelPlayer_x                                         0x1008EBC
#define pinstPCData_x                                              0x1008E7C
#define pinstSkillMgr_x                                            0x109C110
#define pinstSpawnManager_x                                        0x109B9F8
#define pinstSpellManager_x                                        0x109C258
#define pinstSpellSets_x                                           0x10931B4
#define pinstStringTable_x                                         0x1008E24
#define pinstSwitchManager_x                                       0x10064E0
#define pinstTarget_x                                              0x1008EA8
#define pinstTargetObject_x                                        0x1008E80
#define pinstTargetSwitch_x                                        0x1008E84
#define pinstTaskMember_x                                          0xF54FA0
#define pinstTrackTarget_x                                         0x1008E9C
#define pinstTradeTarget_x                                         0x1008E8C
#define instTributeActive_x                                        0xC0D2E5
#define pinstViewActor_x                                           0xF55ACC
#define pinstWorldData_x                                           0x1008E60
#define pinstZoneAddr_x                                            0x1016464

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE17998
#define pinstCAudioTriggersWindow_x                                0xE17828
#define pinstCCharacterSelect_x                                    0xF55960
#define pinstCFacePick_x                                           0xF55910
#define pinstCNoteWnd_x                                            0xF55918
#define pinstCBookWnd_x                                            0xF55920
#define pinstCPetInfoWnd_x                                         0xF55924
#define pinstCTrainWnd_x                                           0xF55928
#define pinstCSkillsWnd_x                                          0xF5592C
#define pinstCSkillsSelectWnd_x                                    0xF55930
#define pinstCCombatSkillsSelectWnd_x                              0xF55934
#define pinstCFriendsWnd_x                                         0xF55938
#define pinstCAuraWnd_x                                            0xF5593C
#define pinstCRespawnWnd_x                                         0xF55940
#define pinstCBandolierWnd_x                                       0xF55944
#define pinstCPotionBeltWnd_x                                      0xF55948
#define pinstCAAWnd_x                                              0xF5594C
#define pinstCGroupSearchFiltersWnd_x                              0xF55950
#define pinstCLoadskinWnd_x                                        0xF55954
#define pinstCAlarmWnd_x                                           0xF55958
#define pinstCMusicPlayerWnd_x                                     0xF5595C
#define pinstCMailWnd_x                                            0xF55964
#define pinstCMailCompositionWnd_x                                 0xF55968
#define pinstCMailAddressBookWnd_x                                 0xF5596C
#define pinstCRaidWnd_x                                            0xF55974
#define pinstCRaidOptionsWnd_x                                     0xF55978
#define pinstCBreathWnd_x                                          0xF5597C
#define pinstCMapViewWnd_x                                         0xF55980
#define pinstCMapToolbarWnd_x                                      0xF55984
#define pinstCEditLabelWnd_x                                       0xF55988
#define pinstCTargetWnd_x                                          0xF5598C
#define pinstCColorPickerWnd_x                                     0xF55990
#define pinstCPlayerWnd_x                                          0xF55994
#define pinstCOptionsWnd_x                                         0xF55998
#define pinstCBuffWindowNORMAL_x                                   0xF5599C
#define pinstCBuffWindowSHORT_x                                    0xF559A0
#define pinstCharacterCreation_x                                   0xF559A4
#define pinstCCursorAttachment_x                                   0xF559A8
#define pinstCCastingWnd_x                                         0xF559AC
#define pinstCCastSpellWnd_x                                       0xF559B0
#define pinstCSpellBookWnd_x                                       0xF559B4
#define pinstCInventoryWnd_x                                       0xF559B8
#define pinstCBankWnd_x                                            0xF559C0
#define pinstCQuantityWnd_x                                        0xF559C4
#define pinstCLootWnd_x                                            0xF559C8
#define pinstCActionsWnd_x                                         0xF559CC
#define pinstCCombatAbilityWnd_x                                   0xF559D0
#define pinstCMerchantWnd_x                                        0xF559D4
#define pinstCTradeWnd_x                                           0xF559D8
#define pinstCSelectorWnd_x                                        0xF559DC
#define pinstCBazaarWnd_x                                          0xF559E0
#define pinstCBazaarSearchWnd_x                                    0xF559E4
#define pinstCGiveWnd_x                                            0xF55A00
#define pinstCTrackingWnd_x                                        0xF55A08
#define pinstCInspectWnd_x                                         0xF55A0C
#define pinstCSocialEditWnd_x                                      0xF55A10
#define pinstCFeedbackWnd_x                                        0xF55A14
#define pinstCBugReportWnd_x                                       0xF55A18
#define pinstCVideoModesWnd_x                                      0xF55A1C
#define pinstCTextEntryWnd_x                                       0xF55A24
#define pinstCFileSelectionWnd_x                                   0xF55A28
#define pinstCCompassWnd_x                                         0xF55A2C
#define pinstCPlayerNotesWnd_x                                     0xF55A30
#define pinstCGemsGameWnd_x                                        0xF55A34
#define pinstCTimeLeftWnd_x                                        0xF55A38
#define pinstCPetitionQWnd_x                                       0xF55A54
#define pinstCSoulmarkWnd_x                                        0xF55A58
#define pinstCStoryWnd_x                                           0xF55A5C
#define pinstCJournalTextWnd_x                                     0xF55A60
#define pinstCJournalCatWnd_x                                      0xF55A64
#define pinstCBodyTintWnd_x                                        0xF55A68
#define pinstCServerListWnd_x                                      0xF55A6C
#define pinstCAvaZoneWnd_x                                         0xF55A78
#define pinstCBlockedBuffWnd_x                                     0xF55A7C
#define pinstCBlockedPetBuffWnd_x                                  0xF55A80
#define pinstCInvSlotMgr_x                                         0xF55AC4
#define pinstCContainerMgr_x                                       0xF55AC8
#define pinstCAdventureLeaderboardWnd_x                            0x11A8440
#define pinstCAdventureRequestWnd_x                                0x11A84B8
#define pinstCAltStorageWnd_x                                      0x11A8798
#define pinstCAdventureStatsWnd_x                                  0x11A8530
#define pinstCBarterMerchantWnd_x                                  0x11A9380
#define pinstCBarterSearchWnd_x                                    0x11A93F8
#define pinstCBarterWnd_x                                          0x11A9470
#define pinstCChatManager_x                                        0x11A9B00
#define pinstCDynamicZoneWnd_x                                     0x11A9FB0
#define pinstCEQMainWnd_x                                          0x11AA148
#define pinstCFellowshipWnd_x                                      0x11A9F44
#define pinstCFindLocationWnd_x                                    0x11AA418
#define pinstCGroupSearchWnd_x                                     0x11AA6E8
#define pinstCGroupWnd_x                                           0x11AA760
#define pinstCGuildBankWnd_x                                       0x11AA7D8
#define pinstCGuildMgmtWnd_x                                       0x11AC8C8
#define pinstCHotButtonWnd_x                                       0x11AC994
#define pinstCHotButtonWnd1_x                                      0x11AC994
#define pinstCHotButtonWnd2_x                                      0x11AC998
#define pinstCHotButtonWnd3_x                                      0x11AC99C
#define pinstCHotButtonWnd4_x                                      0x11AC9C0
#define pinstCItemDisplayManager_x                                 0x11ACCB8
#define pinstCItemExpTransferWnd_x                                 0x11ACD34
#define pinstCLFGuildWnd_x                                         0x11AD010
#define pinstCMIZoneSelectWnd_x                                    0x11AD5F8
#define pinstCConfirmationDialog_x                                 0x11ADD00
#define pinstCPopupWndManager_x                                    0x11ADD00
#define pinstCProgressionSelectionWnd_x                            0x11ADDF0
#define pinstCPvPStatsWnd_x                                        0x11ADEE0
#define pinstCSystemInfoDialogBox_x                                0x11AE5E8
#define pinstCTaskWnd_x                                            0x11AF9B0
#define pinstCTaskSomething_x                                      0xE23B48
#define pinstCTaskTemplateSelectWnd_x                              0x11AF938
#define pinstCTipWndOFDAY_x                                        0x11AFC08
#define pinstCTipWndCONTEXT_x                                      0x11AFC0C
#define pinstCTitleWnd_x                                           0x11AFC88
#define pinstCContextMenuManager_x                                 0x1813464
#define pinstCVoiceMacroWnd_x                                      0x109C8C0
#define pinstCHtmlWnd_x                                            0x109C9B8
#define pinstIconCache_x                                           0x11AA11C
#define pinstCTradeskillWnd_x                                      0x11AFD88
#define pinstCAdvancedLootWnd_x                                    0xF55AB8
#define pinstRewardSelectionWnd_x                                  0x11AE408

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x532F90
#define __ConvertItemTags_x                                        0x5200C0
#define __ExecuteCmd_x                                             0x50AC10
#define __EQGetTime_x                                              0x89FA40
#define __get_melee_range_x                                        0x511880
#define __GetGaugeValueFromEQ_x                                    0x7A8940
#define __GetLabelFromEQ_x                                         0x7A9B90
#define __ToggleMount_x                                            0x47DE80
#define __GetXTargetType_x                                         0x930BF0
#define __LoadFrontEnd_x                                           0x6375A0
#define __NewUIINI_x                                               0x7A8240
#define __ProcessGameEvents_x                                      0x577590
#define __ProcessMouseEvent_x                                      0x576D30
#define CrashDetected_x                                            0x639070
#define wwsCrashReportCheckForUploader_x                           0x7FC250
#define DrawNetStatus_x                                            0x5AE780
#define Util__FastTime_x                                           0x89F390
#define Expansion_HoT_x                                            0x10172A4
#define __HelpPath_x                                               0x109AA10
#define __STMLToText_x                                             0x8E4370

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F060
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419EC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C4ED0
#define AltAdvManager__IsAbilityReady_x                            0x4C4F40
#define AltAdvManager__GetAAById_x                                 0x4C5300

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463FC0
#define CharacterZoneClient__MakeMeVisible_x                       0x4699A0
#define CharacterZoneClient__IsStackBlocked_x                      0x446350

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6670E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x674F50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58D920
#define CButtonWnd__CButtonWnd_x                                   0x8D8640

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x690390
#define CChatManager__InitContextMenu_x                            0x690F10

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E26E0
#define CContextMenu__dCContextMenu_x                              0x8E28F0
#define CContextMenu__AddMenuItem_x                                0x8E2900
#define CContextMenu__RemoveMenuItem_x                             0x8E2BE0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E2C00
#define CContextMenuManager__AddMenu_x                             0x8CE600
#define CContextMenuManager__RemoveMenu_x                          0x8CE940
#define CContextMenuManager__PopupMenu_x                           0x8CED90
#define CContextMenuManager__Flush_x                               0x8CE670
#define CContextMenuManager__GetMenu_x                             0x415510

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8856A0
#define CChatService__GetFriendName_x                              0x8856B0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6961C0
#define CChatWindow__Clear_x                                       0x695D70
#define CChatWindow__WndNotification_x                             0x696700

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D24F0
#define CComboWnd__Draw_x                                          0x8D2700
#define CComboWnd__GetCurChoice_x                                  0x8D22C0
#define CComboWnd__GetListRect_x                                   0x8D29A0
#define CComboWnd__GetTextRect_x                                   0x8D2560
#define CComboWnd__InsertChoice_x                                  0x8D2A10
#define CComboWnd__SetColors_x                                     0x8D2250
#define CComboWnd__SetChoice_x                                     0x8D2280
#define CComboWnd__GetItemCount_x                                  0x8D22B0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69F900
#define CContainerWnd__vftable_x                                   0xAE0F48

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B2FB0
#define CDisplay__GetClickedActor_x                                0x4ABB30
#define CDisplay__GetUserDefinedColor_x                            0x4AA3F0
#define CDisplay__GetWorldFilePath_x                               0x4A9840
#define CDisplay__is3dON_x                                         0x4A8C10
#define CDisplay__ReloadUI_x                                       0x4BE580
#define CDisplay__WriteTextHD2_x                                   0x4AF350

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FA1B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E7070
#define CEditWnd__GetCharIndexPt_x                                 0x8E80F0
#define CEditWnd__GetDisplayString_x                               0x8E7220
#define CEditWnd__GetHorzOffset_x                                  0x8E7560
#define CEditWnd__GetLineForPrintableChar_x                        0x8E7BC0
#define CEditWnd__GetSelStartPt_x                                  0x8E83A0
#define CEditWnd__GetSTMLSafeText_x                                0x8E76F0
#define CEditWnd__PointFromPrintableChar_x                         0x8E7CB0
#define CEditWnd__SelectableCharFromPoint_x                        0x8E7E30
#define CEditWnd__SetEditable_x                                    0x8E76C0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x554510
#define CEverQuest__DoTellWindow_x                                 0x559F00
#define CEverQuest__DropHeldItemOnGround_x                         0x562C10
#define CEverQuest__dsp_chat_x                                     0x55B6A0
#define CEverQuest__Emote_x                                        0x55B900
#define CEverQuest__EnterZone_x                                    0x56FB10
#define CEverQuest__GetBodyTypeDesc_x                              0x550D70
#define CEverQuest__GetClassDesc_x                                 0x556A80
#define CEverQuest__GetClassThreeLetterCode_x                      0x557080
#define CEverQuest__GetDeityDesc_x                                 0x551650
#define CEverQuest__GetLangDesc_x                                  0x551100
#define CEverQuest__GetRaceDesc_x                                  0x557240
#define CEverQuest__InterpretCmd_x                                 0x55C1E0
#define CEverQuest__LeftClickedOnPlayer_x                          0x573C90
#define CEverQuest__LMouseUp_x                                     0x575D80
#define CEverQuest__RightClickedOnPlayer_x                         0x574790
#define CEverQuest__RMouseUp_x                                     0x5757E0
#define CEverQuest__SetGameState_x                                 0x554BC0
#define CEverQuest__UPCNotificationFlush_x                         0x55D560
#define CEverQuest__IssuePetCommand_x                              0x55CEA0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B0530
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B0590
#define CGaugeWnd__Draw_x                                          0x6B09C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x435CF0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CD610

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D9DC0
#define CInvSlotMgr__MoveItem_x                                    0x6DAD00
#define CInvSlotMgr__SelectSlot_x                                  0x6D9E70

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D9240
#define CInvSlot__SliderComplete_x                                 0x6D6A70
#define CInvSlot__GetItemBase_x                                    0x6D5EC0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DC100

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A52F0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DD430

// CLabel 
#define CLabel__Draw_x                                             0x6F83C0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8BE250
#define CListWnd__dCListWnd_x                                      0x8BF270
#define CListWnd__AddColumn_x                                      0x8BF210
#define CListWnd__AddColumn1_x                                     0x8BEA80
#define CListWnd__AddLine_x                                        0x8BE500
#define CListWnd__AddString_x                                      0x8BE710
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BB590
#define CListWnd__CalculateVSBRange_x                              0x8BD700
#define CListWnd__ClearAllSel_x                                    0x8BA850
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BE0E0
#define CListWnd__Compare_x                                        0x8BC090
#define CListWnd__Draw_x                                           0x8BD310
#define CListWnd__DrawColumnSeparators_x                           0x8BD1A0
#define CListWnd__DrawHeader_x                                     0x8BAB60
#define CListWnd__DrawItem_x                                       0x8BC6E0
#define CListWnd__DrawLine_x                                       0x8BCE40
#define CListWnd__DrawSeparator_x                                  0x8BD240
#define CListWnd__EnsureVisible_x                                  0x8BB6F0
#define CListWnd__ExtendSel_x                                      0x8BC5F0
#define CListWnd__GetColumnMinWidth_x                              0x8BA210
#define CListWnd__GetColumnWidth_x                                 0x8BA130
#define CListWnd__GetCurSel_x                                      0x8B9910
#define CListWnd__GetItemAtPoint_x                                 0x8BB980
#define CListWnd__GetItemAtPoint1_x                                0x8BB9F0
#define CListWnd__GetItemData_x                                    0x8B9C50
#define CListWnd__GetItemHeight_x                                  0x8BB1F0
#define CListWnd__GetItemIcon_x                                    0x8B9E30
#define CListWnd__GetItemRect_x                                    0x8BB7C0
#define CListWnd__GetItemText_x                                    0x8B9CE0
#define CListWnd__GetSelList_x                                     0x8BE970
#define CListWnd__GetSeparatorRect_x                               0x8BBFB0
#define CListWnd__RemoveLine_x                                     0x8BE8F0
#define CListWnd__SetColors_x                                      0x8B9A60
#define CListWnd__SetColumnJustification_x                         0x8BA4E0
#define CListWnd__SetColumnWidth_x                                 0x8BA1C0
#define CListWnd__SetCurSel_x                                      0x8B9950
#define CListWnd__SetItemColor_x                                   0x8BDDC0
#define CListWnd__SetItemData_x                                    0x8BA900
#define CListWnd__SetItemText_x                                    0x8BDC00
#define CListWnd__ShiftColumnSeparator_x                           0x8BDA90
#define CListWnd__Sort_x                                           0x8BF370
#define CListWnd__ToggleSel_x                                      0x8BA7D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7118A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x732B90
#define CMerchantWnd__RequestBuyItem_x                             0x7399F0
#define CMerchantWnd__RequestSellItem_x                            0x73A460
#define CMerchantWnd__SelectRecoverySlot_x                         0x732E40
#define CMerchantWnd__SelectBuySellSlot_x                          0x7320A0
#define CMerchantWnd__ActualSelect_x                               0x736910

// CObfuscator
#define CObfuscator__doit_x                                        0x8659C0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8DD5F0
#define CSidlManager__CreateLabel_x                                0x79B300

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65E330
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65E250
#define CSidlScreenWnd__ConvertToRes_x                             0x8FA090
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D5190
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D6690
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D6740
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D5C10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D4B40
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D4270
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D4D30
#define CSidlScreenWnd__Init1_x                                    0x8D6370
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D5240
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D4430
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D5E60
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D3D30
#define CSidlScreenWnd__StoreIniVis_x                              0x8D4200
#define CSidlScreenWnd__WndNotification_x                          0x8D60F0
#define CSidlScreenWnd__GetChildItem_x                             0x8D4340
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C7860

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F92F0
#define CSkillMgr__GetSkillCap_x                                   0x5F94B0
#define CSkillMgr__GetNameToken_x                                  0x5F8F10

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F9350
#define CSliderWnd__SetValue_x                                     0x8F9520
#define CSliderWnd__SetNumTicks_x                                  0x8F9CA0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A2FA0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F3D50
#define CStmlWnd__CalculateHSBRange_x                              0x8EC280
#define CStmlWnd__CalculateVSBRange_x                              0x8EC310
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EC490
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8ECD70
#define CStmlWnd__ForceParseNow_x                                  0x8F46A0
#define CStmlWnd__GetNextTagPiece_x                                0x8ECC70
#define CStmlWnd__GetSTMLText_x                                    0x695610
#define CStmlWnd__GetVisibleText_x                                 0x8ED7C0
#define CStmlWnd__InitializeWindowVariables_x                      0x8EFB50
#define CStmlWnd__MakeStmlColorTag_x                               0x8EB580
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EB5E0
#define CStmlWnd__SetSTMLText_x                                    0x8F13C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F39F0
#define CStmlWnd__UpdateHistoryString_x                            0x8EE700

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EAC10
#define CTabWnd__DrawCurrentPage_x                                 0x8EA480
#define CTabWnd__DrawTab_x                                         0x8EA250
#define CTabWnd__GetCurrentPage_x                                  0x8EA850
#define CTabWnd__GetPageInnerRect_x                                0x8E9F40
#define CTabWnd__GetTabInnerRect_x                                 0x8EA140
#define CTabWnd__GetTabRect_x                                      0x8EA010
#define CTabWnd__InsertPage_x                                      0x8EAF00
#define CTabWnd__SetPage_x                                         0x8EA880
#define CTabWnd__SetPageRect_x                                     0x8EAB50
#define CTabWnd__UpdatePage_x                                      0x8EAEA0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431A80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D1EC0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FF5B0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B7A60

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4022A0
#define CXStr__CXStr1_x                                            0x8B8B30
#define CXStr__CXStr3_x                                            0x89C420
#define CXStr__dCXStr_x                                            0x5FBF90
#define CXStr__operator_equal_x                                    0x89C590
#define CXStr__operator_equal1_x                                   0x89C5E0
#define CXStr__operator_plus_equal1_x                              0x89D6C0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C6A80
#define CXWnd__Center_x                                            0x8CCC40
#define CXWnd__ClrFocus_x                                          0x8C6650
#define CXWnd__DoAllDrawing_x                                      0x8CC890
#define CXWnd__DrawChildren_x                                      0x8CCA30
#define CXWnd__DrawColoredRect_x                                   0x8C6E20
#define CXWnd__DrawTooltip_x                                       0x8C70D0
#define CXWnd__DrawTooltipAtPoint_x                                0x8CB800
#define CXWnd__GetBorderFrame_x                                    0x8C7530
#define CXWnd__GetChildWndAt_x                                     0x8CD5E0
#define CXWnd__GetClientClipRect_x                                 0x8C72F0
#define CXWnd__GetScreenClipRect_x                                 0x8CBEF0
#define CXWnd__GetScreenRect_x                                     0x8C76F0
#define CXWnd__GetTooltipRect_x                                    0x8C6F60
#define CXWnd__GetWindowTextA_x                                    0x423010
#define CXWnd__IsActive_x                                          0x8C2050
#define CXWnd__IsDescendantOf_x                                    0x8C7480
#define CXWnd__IsReallyVisible_x                                   0x8CA830
#define CXWnd__IsType_x                                            0x8FBDB0
#define CXWnd__Move_x                                              0x8C9F00
#define CXWnd__Move1_x                                             0x8CC540
#define CXWnd__ProcessTransition_x                                 0x8C6A20
#define CXWnd__Refade_x                                            0x8C67F0
#define CXWnd__Resize_x                                            0x8C77C0
#define CXWnd__Right_x                                             0x8CBCF0
#define CXWnd__SetFocus_x                                          0x8C9070
#define CXWnd__SetFont_x                                           0x8C66A0
#define CXWnd__SetKeyTooltip_x                                     0x8C7A30
#define CXWnd__SetMouseOver_x                                      0x8CC230
#define CXWnd__StartFade_x                                         0x8C6AD0
#define CXWnd__GetChildItem_x                                      0x8CC170

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C3970
#define CXWndManager__DrawWindows_x                                0x8C35B0
#define CXWndManager__GetKeyboardFlags_x                           0x8C1B80
#define CXWndManager__HandleKeyboardMsg_x                          0x8C24E0
#define CXWndManager__RemoveWnd_x                                  0x8C21E0

// CDBStr
#define CDBStr__GetString_x                                        0x4A71B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44DFD0
#define EQ_Character__Cur_HP_x                                     0x463690
#define EQ_Character__GetAACastingTimeModifier_x                   0x445ED0
#define EQ_Character__GetCharInfo2_x                               0x8702B0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43DE70
#define EQ_Character__GetFocusRangeModifier_x                      0x43E060
#define EQ_Character__Max_Endurance_x                              0x5C0E50
#define EQ_Character__Max_HP_x                                     0x4592C0
#define EQ_Character__Max_Mana_x                                   0x5C0C80
#define EQ_Character__doCombatAbility_x                            0x5BE2D0
#define EQ_Character__UseSkill_x                                   0x46EB90
#define EQ_Character__GetConLevel_x                                0x5B2DC0
#define EQ_Character__IsExpansionFlag_x                            0x422550
#define EQ_Character__TotalEffect_x                                0x44B270

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x593210
#define EQ_Item__CreateItemTagString_x                             0x84F730
#define EQ_Item__IsStackable_x                                     0x843C90
#define EQ_Item__GetImageNum_x                                     0x846990
#define EQ_Item__CreateItemClient_x                                0x593E00
#define EQ_Item__GetItemValue_x                                    0x84E400
#define EQ_Item__ValueSellMerchant_x                               0x850A40

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C6FC0
#define EQ_LoadingS__Array_x                                       0xC1B098

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C24A0
#define EQ_PC__GetAlternateAbilityId_x                             0x8589A0
#define EQ_PC__GetCombatAbility_x                                  0x858A30
#define EQ_PC__GetCombatAbilityTimer_x                             0x8539A0
#define EQ_PC__GetItemTimerValue_x                                 0x5BBE60
#define EQ_PC__HasLoreItem_x                                       0x5B62A0
#define EQ_PC__AlertInventoryChanged_x                             0x5B2D90
#define EQ_PC__GetPcZoneClient_x                                   0x5DCA20
#define EQ_PC__RemoveMyAffect_x									   0x5BB320

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50F8F0
#define EQItemList__add_item_x                                     0x50F830
#define EQItemList__delete_item_x                                  0x50FCF0
#define EQItemList__FreeItemList_x                                 0x50FBF0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A63F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C7A20
#define EQPlayer__dEQPlayer_x                                      0x5D08A0
#define EQPlayer__DoAttack_x                                       0x5E2930
#define EQPlayer__EQPlayer_x                                       0x5D2CC0
#define EQPlayer__SetNameSpriteState_x                             0x5CD570
#define EQPlayer__SetNameSpriteTint_x                              0x5C8E30
#define EQPlayer__IsBodyType_j_x                                   0x92CD70
#define EQPlayer__IsTargetable_x                                   0x92D670
#define EQPlayer__CanSee_x                                         0x92DB90
#define PlayerZoneClient__ChangeHeight_x                           0x5E27F0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D6FC0
#define EQPlayerManager__GetSpawnByName_x                          0x5D7420

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5994D0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x599510
#define KeypressHandler__ClearCommandStateArray_x                  0x5990B0
#define KeypressHandler__HandleKeyDown_x                           0x597A10
#define KeypressHandler__HandleKeyUp_x                             0x597D30
#define KeypressHandler__SaveKeymapping_x                          0x599180

// MapViewMap 
#define MapViewMap__Clear_x                                        0x709C80
#define MapViewMap__SaveEx_x                                       0x70D560

#define PlayerPointManager__GetAltCurrency_x                       0x86B190

// StringTable 
#define StringTable__getString_x                                   0x865C60

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C0900
#define PcZoneClient__RemovePetEffect_x                            0x5BC2D0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54E1B0

//IconCache
#define IconCache__GetIcon_x                                       0x6A5E30

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69CC10
#define CContainerMgr__CloseContainer_x                            0x69D430

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76B510

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58C3C0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DEAE0
#define EQ_Spell__SpellAffects_x                                   0x4DEB80
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DEBB0
#define CharacterZoneClient__CalcAffectChange_x                    0x4472C0
#define CLootWnd__LootAll_x                                        0x6FF570

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B0F70
#define CTargetWnd__WndNotification_x                              0x7B0A60

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B6160

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D83B0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x496830

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E66A0
#define CSidlManager__FindAnimation1_x                             0x8DB4E0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CE4F0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CE4A0
#define CAltAbilityData__GetMaxRank_x                              0x4C3590
