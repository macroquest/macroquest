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
#define __ExpectedVersionDate                                     "Nov 11 2015"
#define __ExpectedVersionTime                                     "04:17:14"
#define __ActualVersionDate_x                                      0xAD9658
#define __ActualVersionTime_x                                      0xAD9664

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59FFE0
#define __MemChecker1_x                                            0x8A1DF0
#define __MemChecker2_x                                            0x639360
#define __MemChecker3_x                                            0x6392B0
#define __MemChecker4_x                                            0x7EE190
#define __EncryptPad0_x                                            0xC74D08
#define __EncryptPad1_x                                            0xDFFDE8
#define __EncryptPad2_x                                            0xCBE7F0
#define __EncryptPad3_x                                            0xCBE3F0
#define __EncryptPad4_x                                            0xDD8F78
#define __EncryptPad5_x                                            0x11ABC60
#define __AC1_x                                                    0x7AB3C5
#define __AC2_x                                                    0x554447
#define __AC3_x                                                    0x569000
#define __AC4_x                                                    0x56FB40
#define __AC5_x                                                    0x57C28E
#define __AC6_x                                                    0x57FDD9
#define __AC7_x                                                    0x57693C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data                                                 0x845E8

// Direct Input
#define DI8__Main_x                                                0x11ABC38
#define DI8__Keyboard_x                                            0x11ABC3C
#define DI8__Mouse_x                                               0x11ABC40
#define DI8__Mouse_Copy_x                                          0x101A254
#define DI8__Mouse_Check_x                                         0x10A3B24
#define __AltTimerReady_x                                          0x100B5A1
#define __Attack_x                                                 0x109E7C7
#define __Autofire_x                                               0x109E7C8
#define __BindList_x                                               0xC36DD8
#define __bCommandEnabled_x                                        0x10096B0
#define __Clicks_x                                                 0x101A310
#define __CommandList_x                                            0xC3B148
#define __CurrentMapLabel_x                                        0x11B1690
#define __CurrentSocial_x                                          0xBEDF44
#define __DoAbilityList_x                                          0x1050A7C
#define __do_loot_x                                                0x51B8E0
#define __DrawHandler_x                                            0x1818444
#define __GroupCount_x                                             0x100AC7A

#define __Guilds_x                                                 0x1010890
#define __gWorld_x                                                 0x100D134
#define __HotkeyPage_x                                             0x109747C
#define __HWnd_x                                                   0x10A3B40
#define __InChatMode_x                                             0x101A23C
#define __LastTell_x                                               0x101C180
#define __LMouseHeldTime_x                                         0x101A37C
#define __Mouse_x                                                  0x11ABC44
#define __MouseLook_x                                              0x101A2D6
#define __MouseEventTime_x                                         0x109EFCC
#define __gpbCommandEvent_x                                        0x100D1FC
#define __NetStatusToggle_x                                        0x101A2D9
#define __PCNames_x                                                0x101B7A0
#define __RangeAttackReady_x                                       0x101B460
#define __RMouseHeldTime_x                                         0x101A378
#define __RunWalkState_x                                           0x101A240
#define __ScreenMode_x                                             0xF593E0
#define __ScreenX_x                                                0x101A1F4
#define __ScreenY_x                                                0x101A1F0
#define __ScreenXMax_x                                             0x101A1F8
#define __ScreenYMax_x                                             0x101A1FC
#define __ServerHost_x                                             0x100ABC4
#define __ServerName_x                                             0x1050A3C
#define __ShiftKeyDown_x                                           0x101A8E4
#define __ShowNames_x                                              0x101B634
#define __Socials_x                                                0x1050B3C
#define __SubscriptionType_x                                       0x11DFBC0
#define __TargetAggroHolder_x                                      0x11B38CC
#define __GroupAggro_x                                             0x11B390C
#define __LoginName_x                                              0x10A2718
#define __Inviter_x                                                0x109E744


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x100D220
#define instEQZoneInfo_x                                           0x101A4CC
#define instKeypressHandler_x                                      0x109EFB0
#define pinstActiveBanker_x                                        0x100D1D8
#define pinstActiveCorpse_x                                        0x100D1DC
#define pinstActiveGMaster_x                                       0x100D1E0
#define pinstActiveMerchant_x                                      0x100D1D4
#define pinstAggroInfo_x                                           0xE1B7D8
#define pinstAltAdvManager_x                                       0xF5A4E8
#define pinstAuraMgr_x                                             0xE276A8
#define pinstBandageTarget_x                                       0x100D1C0
#define pinstCamActor_x                                            0xF59DF0
#define pinstCDBStr_x                                              0xF59374
#define pinstCDisplay_x                                            0x100D1E8
#define pinstCEverQuest_x                                          0x11ABDB8
#define pinstCharData_x                                            0x100D1A4
#define pinstCharSpawn_x                                           0x100D1CC
#define pinstControlledMissile_x                                   0x100D1A0
#define pinstControlledPlayer_x                                    0x100D1CC
#define pinstCSidlManager_x                                        0x181787C
#define pinstCXWndManager_x                                        0x1817874
#define instDynamicZone_x                                          0x101A088
#define pinstDZMember_x                                            0x101A198
#define pinstDZTimerInfo_x                                         0x101A19C
#define pinstEQItemList_x                                          0x1009900
#define instEQMisc_x                                               0xC102C8
#define pinstEQSoundManager_x                                      0xF5AA48
#define instExpeditionLeader_x                                     0x101A0D2
#define instExpeditionName_x                                       0x101A112
#define pinstGroup_x                                               0x100AC76
#define pinstImeManager_x                                          0x1817880
#define pinstLocalPlayer_x                                         0x100D1B8
#define pinstMercenaryData_x                                       0x109F600
#define pinstMercenaryStats_x                                      0x11B3A18
#define pinstMercAltAbilities_x                                    0xF5A874
#define pinstModelPlayer_x                                         0x100D1E4
#define pinstPCData_x                                              0x100D1A4
#define pinstSkillMgr_x                                            0x10A0438
#define pinstSpawnManager_x                                        0x109FD20
#define pinstSpellManager_x                                        0x10A0580
#define pinstSpellSets_x                                           0x10974E0
#define pinstStringTable_x                                         0x100D14C
#define pinstSwitchManager_x                                       0x100A808
#define pinstTarget_x                                              0x100D1D0
#define pinstTargetObject_x                                        0x100D1A8
#define pinstTargetSwitch_x                                        0x100D1AC
#define pinstTaskMember_x                                          0xF592C0
#define pinstTrackTarget_x                                         0x100D1C4
#define pinstTradeTarget_x                                         0x100D1B4
#define instTributeActive_x                                        0xC102ED
#define pinstViewActor_x                                           0xF59DEC
#define pinstWorldData_x                                           0x100D188
#define pinstZoneAddr_x                                            0x101A78C
#define pinstPlayerPath_x                                          0x109BEA0
#define pinstTargetIndicator_x                                     0x109C838
#define pinstCTargetManager_x                                      0x10A0778

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE1BCB8
#define pinstCAudioTriggersWindow_x                                0xE1BB48
#define pinstCCharacterSelect_x                                    0xF59C80
#define pinstCFacePick_x                                           0xF59C30
#define pinstCNoteWnd_x                                            0xF59C38
#define pinstCBookWnd_x                                            0xF59C40
#define pinstCPetInfoWnd_x                                         0xF59C44
#define pinstCTrainWnd_x                                           0xF59C48
#define pinstCSkillsWnd_x                                          0xF59C4C
#define pinstCSkillsSelectWnd_x                                    0xF59C50
#define pinstCCombatSkillsSelectWnd_x                              0xF59C54
#define pinstCFriendsWnd_x                                         0xF59C58
#define pinstCAuraWnd_x                                            0xF59C5C
#define pinstCRespawnWnd_x                                         0xF59C60
#define pinstCBandolierWnd_x                                       0xF59C64
#define pinstCPotionBeltWnd_x                                      0xF59C68
#define pinstCAAWnd_x                                              0xF59C6C
#define pinstCGroupSearchFiltersWnd_x                              0xF59C70
#define pinstCLoadskinWnd_x                                        0xF59C74
#define pinstCAlarmWnd_x                                           0xF59C78
#define pinstCMusicPlayerWnd_x                                     0xF59C7C
#define pinstCMailWnd_x                                            0xF59C84
#define pinstCMailCompositionWnd_x                                 0xF59C88
#define pinstCMailAddressBookWnd_x                                 0xF59C8C
#define pinstCRaidWnd_x                                            0xF59C94
#define pinstCRaidOptionsWnd_x                                     0xF59C98
#define pinstCBreathWnd_x                                          0xF59C9C
#define pinstCMapViewWnd_x                                         0xF59CA0
#define pinstCMapToolbarWnd_x                                      0xF59CA4
#define pinstCEditLabelWnd_x                                       0xF59CA8
#define pinstCTargetWnd_x                                          0xF59CAC
#define pinstCColorPickerWnd_x                                     0xF59CB0
#define pinstCPlayerWnd_x                                          0xF59CB4
#define pinstCOptionsWnd_x                                         0xF59CB8
#define pinstCBuffWindowNORMAL_x                                   0xF59CBC
#define pinstCBuffWindowSHORT_x                                    0xF59CC0
#define pinstCharacterCreation_x                                   0xF59CC4
#define pinstCCursorAttachment_x                                   0xF59CC8
#define pinstCCastingWnd_x                                         0xF59CCC
#define pinstCCastSpellWnd_x                                       0xF59CD0
#define pinstCSpellBookWnd_x                                       0xF59CD4
#define pinstCInventoryWnd_x                                       0xF59CD8
#define pinstCBankWnd_x                                            0xF59CE0
#define pinstCQuantityWnd_x                                        0xF59CE4
#define pinstCLootWnd_x                                            0xF59CE8
#define pinstCActionsWnd_x                                         0xF59CEC
#define pinstCCombatAbilityWnd_x                                   0xF59CF0
#define pinstCMerchantWnd_x                                        0xF59CF4
#define pinstCTradeWnd_x                                           0xF59CF8
#define pinstCSelectorWnd_x                                        0xF59CFC
#define pinstCBazaarWnd_x                                          0xF59D00
#define pinstCBazaarSearchWnd_x                                    0xF59D04
#define pinstCGiveWnd_x                                            0xF59D20
#define pinstCTrackingWnd_x                                        0xF59D28
#define pinstCInspectWnd_x                                         0xF59D2C
#define pinstCSocialEditWnd_x                                      0xF59D30
#define pinstCFeedbackWnd_x                                        0xF59D34
#define pinstCBugReportWnd_x                                       0xF59D38
#define pinstCVideoModesWnd_x                                      0xF59D3C
#define pinstCTextEntryWnd_x                                       0xF59D44
#define pinstCFileSelectionWnd_x                                   0xF59D48
#define pinstCCompassWnd_x                                         0xF59D4C
#define pinstCPlayerNotesWnd_x                                     0xF59D50
#define pinstCGemsGameWnd_x                                        0xF59D54
#define pinstCTimeLeftWnd_x                                        0xF59D58
#define pinstCPetitionQWnd_x                                       0xF59D74
#define pinstCSoulmarkWnd_x                                        0xF59D78
#define pinstCStoryWnd_x                                           0xF59D7C
#define pinstCJournalTextWnd_x                                     0xF59D80
#define pinstCJournalCatWnd_x                                      0xF59D84
#define pinstCBodyTintWnd_x                                        0xF59D88
#define pinstCServerListWnd_x                                      0xF59D8C
#define pinstCAvaZoneWnd_x                                         0xF59D98
#define pinstCBlockedBuffWnd_x                                     0xF59D9C
#define pinstCBlockedPetBuffWnd_x                                  0xF59DA0
#define pinstCInvSlotMgr_x                                         0xF59DE4
#define pinstCContainerMgr_x                                       0xF59DE8
#define pinstCAdventureLeaderboardWnd_x                            0x11AC768
#define pinstCAdventureRequestWnd_x                                0x11AC7E0
#define pinstCAltStorageWnd_x                                      0x11ACAC0
#define pinstCAdventureStatsWnd_x                                  0x11AC858
#define pinstCBarterMerchantWnd_x                                  0x11AD6A8
#define pinstCBarterSearchWnd_x                                    0x11AD720
#define pinstCBarterWnd_x                                          0x11AD798
#define pinstCChatManager_x                                        0x11ADE28
#define pinstCDynamicZoneWnd_x                                     0x11AE2D8
#define pinstCEQMainWnd_x                                          0x11AE470
#define pinstCFellowshipWnd_x                                      0x11AE26C
#define pinstCFindLocationWnd_x                                    0x11AE740
#define pinstCGroupSearchWnd_x                                     0x11AEA10
#define pinstCGroupWnd_x                                           0x11AEA88
#define pinstCGuildBankWnd_x                                       0x11AEB00
#define pinstCGuildMgmtWnd_x                                       0x11B0BF0
#define pinstCHotButtonWnd_x                                       0x11B0CBC
#define pinstCHotButtonWnd1_x                                      0x11B0CBC
#define pinstCHotButtonWnd2_x                                      0x11B0CC0
#define pinstCHotButtonWnd3_x                                      0x11B0CC4
#define pinstCHotButtonWnd4_x                                      0x11B0CE8
#define pinstCItemDisplayManager_x                                 0x11B0FE0
#define pinstCItemExpTransferWnd_x                                 0x11B105C
#define pinstCLFGuildWnd_x                                         0x11B1338
#define pinstCMIZoneSelectWnd_x                                    0x11B1920
#define pinstCConfirmationDialog_x                                 0x11B2028
#define pinstCPopupWndManager_x                                    0x11B2028
#define pinstCProgressionSelectionWnd_x                            0x11B2118
#define pinstCPvPStatsWnd_x                                        0x11B2208
#define pinstCSystemInfoDialogBox_x                                0x11B2910
#define pinstCTaskWnd_x                                            0x11B3CD8
#define pinstCTaskSomething_x                                      0xE27E68
#define pinstCTaskTemplateSelectWnd_x                              0x11B3C60
#define pinstCTipWndOFDAY_x                                        0x11B3F30
#define pinstCTipWndCONTEXT_x                                      0x11B3F34
#define pinstCTitleWnd_x                                           0x11B3FB0
#define pinstCContextMenuManager_x                                 0x18177EC
#define pinstCVoiceMacroWnd_x                                      0x10A0BE8
#define pinstCHtmlWnd_x                                            0x10A0CE0
#define pinstIconCache_x                                           0x11AE444
#define pinstCTradeskillWnd_x                                      0x11B40B0
#define pinstCAdvancedLootWnd_x                                    0xF59DD8
#define pinstRewardSelectionWnd_x                                  0x11B2730

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x533430
#define __ConvertItemTags_x                                        0x520560
#define __ExecuteCmd_x                                             0x50B0B0
#define __EQGetTime_x                                              0x8A2150
#define __get_melee_range_x                                        0x511D20
#define __GetGaugeValueFromEQ_x                                    0x7AA100
#define __GetLabelFromEQ_x                                         0x7AB350
#define __ToggleMount_x                                            0x47E0F0
#define __GetXTargetType_x                                         0x933290
#define __LoadFrontEnd_x                                           0x638A10
#define __NewUIINI_x                                               0x7A9A00
#define __ProcessGameEvents_x                                      0x5786A0
#define __ProcessMouseEvent_x                                      0x577E40
#define CrashDetected_x                                            0x63A4E0
#define wwsCrashReportCheckForUploader_x                           0x7FDCA0
#define DrawNetStatus_x                                            0x5AFC90
#define Util__FastTime_x                                           0x8A1AA0
#define Expansion_HoT_x                                            0x101B5CC
#define __HelpPath_x                                               0x109ED38
#define __STMLToText_x                                             0x8E6BC0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F110
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419F70

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C5000
#define AltAdvManager__IsAbilityReady_x                            0x4C5070
#define AltAdvManager__GetAAById_x                                 0x4C5430

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x464180
#define CharacterZoneClient__MakeMeVisible_x                       0x469B60
#define CharacterZoneClient__IsStackBlocked_x                      0x446380

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x668430

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x676B70

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58EF70
#define CButtonWnd__CButtonWnd_x                                   0x8DAE60

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x691690
#define CChatManager__InitContextMenu_x                            0x692210

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E4F30
#define CContextMenu__dCContextMenu_x                              0x8E5140
#define CContextMenu__AddMenuItem_x                                0x8E5150
#define CContextMenu__RemoveMenuItem_x                             0x8E5430
#define CContextMenu__RemoveAllMenuItems_x                         0x8E5450
#define CContextMenuManager__AddMenu_x                             0x8D0E20
#define CContextMenuManager__RemoveMenu_x                          0x8D1160
#define CContextMenuManager__PopupMenu_x                           0x8D15B0
#define CContextMenuManager__Flush_x                               0x8D0E90
#define CContextMenuManager__GetMenu_x                             0x4155C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8873A0
#define CChatService__GetFriendName_x                              0x8873B0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6974C0
#define CChatWindow__Clear_x                                       0x697070
#define CChatWindow__WndNotification_x                             0x697A00

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D4D10
#define CComboWnd__Draw_x                                          0x8D4F20
#define CComboWnd__GetCurChoice_x                                  0x8D4AE0
#define CComboWnd__GetListRect_x                                   0x8D51C0
#define CComboWnd__GetTextRect_x                                   0x8D4D80
#define CComboWnd__InsertChoice_x                                  0x8D5230
#define CComboWnd__SetColors_x                                     0x8D4A70
#define CComboWnd__SetChoice_x                                     0x8D4AA0
#define CComboWnd__GetItemCount_x                                  0x8D4AD0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A0C00
#define CContainerWnd__vftable_x                                   0xAE3020

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B31F0
#define CDisplay__GetClickedActor_x                                0x4ABD70
#define CDisplay__GetUserDefinedColor_x                            0x4AA630
#define CDisplay__GetWorldFilePath_x                               0x4A9A80
#define CDisplay__is3dON_x                                         0x4A8E50
#define CDisplay__ReloadUI_x                                       0x4BE7C0
#define CDisplay__WriteTextHD2_x                                   0x4AF590

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FC9F0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E98C0
#define CEditWnd__GetCharIndexPt_x                                 0x8EA940
#define CEditWnd__GetDisplayString_x                               0x8E9A70
#define CEditWnd__GetHorzOffset_x                                  0x8E9DB0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EA410
#define CEditWnd__GetSelStartPt_x                                  0x8EABF0
#define CEditWnd__GetSTMLSafeText_x                                0x8E9F40
#define CEditWnd__PointFromPrintableChar_x                         0x8EA500
#define CEditWnd__SelectableCharFromPoint_x                        0x8EA680
#define CEditWnd__SetEditable_x                                    0x8E9F10

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x554B90
#define CEverQuest__CreateTargetIndicator_x                        0x5557C0
#define CEverQuest__DeleteTargetIndicator_x                        0x555840
#define CEverQuest__DoTellWindow_x                                 0x55A580
#define CEverQuest__DropHeldItemOnGround_x                         0x563480
#define CEverQuest__dsp_chat_x                                     0x55BF30
#define CEverQuest__Emote_x                                        0x55C190
#define CEverQuest__EnterZone_x                                    0x570490
#define CEverQuest__GetBodyTypeDesc_x                              0x5513F0
#define CEverQuest__GetClassDesc_x                                 0x557100
#define CEverQuest__GetClassThreeLetterCode_x                      0x557700
#define CEverQuest__GetDeityDesc_x                                 0x551CD0
#define CEverQuest__GetLangDesc_x                                  0x551780
#define CEverQuest__GetRaceDesc_x                                  0x5578C0
#define CEverQuest__InterpretCmd_x                                 0x55CA70
#define CEverQuest__LeftClickedOnPlayer_x                          0x574DA0
#define CEverQuest__LMouseUp_x                                     0x576E90
#define CEverQuest__RightClickedOnPlayer_x                         0x5758A0
#define CEverQuest__RMouseUp_x                                     0x5768F0
#define CEverQuest__SetGameState_x                                 0x555240
#define CEverQuest__UPCNotificationFlush_x                         0x55DDD0
#define CEverQuest__IssuePetCommand_x                              0x55D730

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B1A10
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B1A70
#define CGaugeWnd__Draw_x                                          0x6B1EA0

// CGuild
#define CGuild__FindMemberByName_x                                 0x435D50

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CEB20

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DB2D0
#define CInvSlotMgr__MoveItem_x                                    0x6DC210
#define CInvSlotMgr__SelectSlot_x                                  0x6DB380

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DA760
#define CInvSlot__SliderComplete_x                                 0x6D7F90
#define CInvSlot__GetItemBase_x                                    0x6D73E0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DD610

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A6A90
#define CItemDisplayWnd__UpdateStrings_x                           0x6DE950

// CLabel 
#define CLabel__Draw_x                                             0x6F9960

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C09F0
#define CListWnd__dCListWnd_x                                      0x8C1A10
#define CListWnd__AddColumn_x                                      0x8C19B0
#define CListWnd__AddColumn1_x                                     0x8C1220
#define CListWnd__AddLine_x                                        0x8C0CA0
#define CListWnd__AddString_x                                      0x8C0EB0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BDD30
#define CListWnd__CalculateVSBRange_x                              0x8BFEA0
#define CListWnd__ClearAllSel_x                                    0x8BCFF0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C0880
#define CListWnd__Compare_x                                        0x8BE830
#define CListWnd__Draw_x                                           0x8BFAB0
#define CListWnd__DrawColumnSeparators_x                           0x8BF940
#define CListWnd__DrawHeader_x                                     0x8BD300
#define CListWnd__DrawItem_x                                       0x8BEE80
#define CListWnd__DrawLine_x                                       0x8BF5E0
#define CListWnd__DrawSeparator_x                                  0x8BF9E0
#define CListWnd__EnsureVisible_x                                  0x8BDE90
#define CListWnd__ExtendSel_x                                      0x8BED90
#define CListWnd__GetColumnMinWidth_x                              0x8BC9B0
#define CListWnd__GetColumnWidth_x                                 0x8BC8D0
#define CListWnd__GetCurSel_x                                      0x8BC0B0
#define CListWnd__GetItemAtPoint_x                                 0x8BE120
#define CListWnd__GetItemAtPoint1_x                                0x8BE190
#define CListWnd__GetItemData_x                                    0x8BC3F0
#define CListWnd__GetItemHeight_x                                  0x8BD990
#define CListWnd__GetItemIcon_x                                    0x8BC5D0
#define CListWnd__GetItemRect_x                                    0x8BDF60
#define CListWnd__GetItemText_x                                    0x8BC480
#define CListWnd__GetSelList_x                                     0x8C1110
#define CListWnd__GetSeparatorRect_x                               0x8BE750
#define CListWnd__RemoveLine_x                                     0x8C1090
#define CListWnd__SetColors_x                                      0x8BC200
#define CListWnd__SetColumnJustification_x                         0x8BCC80
#define CListWnd__SetColumnWidth_x                                 0x8BC960
#define CListWnd__SetCurSel_x                                      0x8BC0F0
#define CListWnd__SetItemColor_x                                   0x8C0560
#define CListWnd__SetItemData_x                                    0x8BD0A0
#define CListWnd__SetItemText_x                                    0x8C03A0
#define CListWnd__ShiftColumnSeparator_x                           0x8C0230
#define CListWnd__Sort_x                                           0x8C1B10
#define CListWnd__ToggleSel_x                                      0x8BCF70

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x712D50

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7341F0
#define CMerchantWnd__RequestBuyItem_x                             0x73B050
#define CMerchantWnd__RequestSellItem_x                            0x73BAC0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7344A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x733700
#define CMerchantWnd__ActualSelect_x                               0x737F70

// CObfuscator
#define CObfuscator__doit_x                                        0x8675A0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8DFDD0
#define CSidlManager__CreateLabel_x                                0x79CA90

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65F740
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65F660
#define CSidlScreenWnd__ConvertToRes_x                             0x8FC8D0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D79B0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D8EB0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D8F60
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D8430
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D7360
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D6A90
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D7550
#define CSidlScreenWnd__Init1_x                                    0x8D8B90
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D7A60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D6C50
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D8680
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D6550
#define CSidlScreenWnd__StoreIniVis_x                              0x8D6A20
#define CSidlScreenWnd__WndNotification_x                          0x8D8910
#define CSidlScreenWnd__GetChildItem_x                             0x8D6B60
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CA080

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FA960
#define CSkillMgr__GetSkillCap_x                                   0x5FAB20
#define CSkillMgr__GetNameToken_x                                  0x5FA580

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FBB90
#define CSliderWnd__SetValue_x                                     0x8FBD60
#define CSliderWnd__SetNumTicks_x                                  0x8FC4E0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A4730

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6590
#define CStmlWnd__CalculateHSBRange_x                              0x8EEAC0
#define CStmlWnd__CalculateVSBRange_x                              0x8EEB50
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EECD0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EF5B0
#define CStmlWnd__ForceParseNow_x                                  0x8F6EE0
#define CStmlWnd__GetNextTagPiece_x                                0x8EF4B0
#define CStmlWnd__GetSTMLText_x                                    0x696910
#define CStmlWnd__GetVisibleText_x                                 0x8F0000
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2390
#define CStmlWnd__MakeStmlColorTag_x                               0x8EDDC0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EDE20
#define CStmlWnd__SetSTMLText_x                                    0x8F3C00
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6230
#define CStmlWnd__UpdateHistoryString_x                            0x8F0F40

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8ED460
#define CTabWnd__DrawCurrentPage_x                                 0x8ECCD0
#define CTabWnd__DrawTab_x                                         0x8ECAA0
#define CTabWnd__GetCurrentPage_x                                  0x8ED0A0
#define CTabWnd__GetPageInnerRect_x                                0x8EC790
#define CTabWnd__GetTabInnerRect_x                                 0x8EC990
#define CTabWnd__GetTabRect_x                                      0x8EC860
#define CTabWnd__InsertPage_x                                      0x8ED750
#define CTabWnd__SetPage_x                                         0x8ED0D0
#define CTabWnd__SetPageRect_x                                     0x8ED3A0
#define CTabWnd__UpdatePage_x                                      0x8ED6F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431B70

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D46E0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x901E10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BA250

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402290
#define CXStr__CXStr1_x                                            0x8AF950
#define CXStr__CXStr3_x                                            0x89EB30
#define CXStr__dCXStr_x                                            0x4A0AA0
#define CXStr__operator_equal_x                                    0x89ECA0
#define CXStr__operator_equal1_x                                   0x89ECF0
#define CXStr__operator_plus_equal1_x                              0x89FDD0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C92A0
#define CXWnd__Center_x                                            0x8CF460
#define CXWnd__ClrFocus_x                                          0x8C8E70
#define CXWnd__DoAllDrawing_x                                      0x8CF0B0
#define CXWnd__DrawChildren_x                                      0x8CF250
#define CXWnd__DrawColoredRect_x                                   0x8C9640
#define CXWnd__DrawTooltip_x                                       0x8C98F0
#define CXWnd__DrawTooltipAtPoint_x                                0x8CE020
#define CXWnd__GetBorderFrame_x                                    0x8C9D50
#define CXWnd__GetChildWndAt_x                                     0x8CFE00
#define CXWnd__GetClientClipRect_x                                 0x8C9B10
#define CXWnd__GetScreenClipRect_x                                 0x8CE710
#define CXWnd__GetScreenRect_x                                     0x8C9F10
#define CXWnd__GetTooltipRect_x                                    0x8C9780
#define CXWnd__GetWindowTextA_x                                    0x423140
#define CXWnd__IsActive_x                                          0x8C47F0
#define CXWnd__IsDescendantOf_x                                    0x8C9CA0
#define CXWnd__IsReallyVisible_x                                   0x8CD050
#define CXWnd__IsType_x                                            0x8FE5F0
#define CXWnd__Move_x                                              0x8CC720
#define CXWnd__Move1_x                                             0x8CED60
#define CXWnd__ProcessTransition_x                                 0x8C9240
#define CXWnd__Refade_x                                            0x8C9010
#define CXWnd__Resize_x                                            0x8C9FE0
#define CXWnd__Right_x                                             0x8CE510
#define CXWnd__SetFocus_x                                          0x8CB890
#define CXWnd__SetFont_x                                           0x8C8EC0
#define CXWnd__SetKeyTooltip_x                                     0x8CA250
#define CXWnd__SetMouseOver_x                                      0x8CEA50
#define CXWnd__StartFade_x                                         0x8C92F0
#define CXWnd__GetChildItem_x                                      0x8CE990

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C6110
#define CXWndManager__DrawWindows_x                                0x8C5D50
#define CXWndManager__GetKeyboardFlags_x                           0x8C4320
#define CXWndManager__HandleKeyboardMsg_x                          0x8C4C80
#define CXWndManager__RemoveWnd_x                                  0x8C4980

// CDBStr
#define CDBStr__GetString_x                                        0x4A7400

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E000
#define EQ_Character__Cur_HP_x                                     0x463850
#define EQ_Character__GetAACastingTimeModifier_x                   0x445F00
#define EQ_Character__GetCharInfo2_x                               0x871E70
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43DED0
#define EQ_Character__GetFocusRangeModifier_x                      0x43E0C0
#define EQ_Character__Max_Endurance_x                              0x5C2690
#define EQ_Character__Max_HP_x                                     0x459480
#define EQ_Character__Max_Mana_x                                   0x5C24C0
#define EQ_Character__doCombatAbility_x                            0x5BFB10
#define EQ_Character__UseSkill_x                                   0x46ED50
#define EQ_Character__GetConLevel_x                                0x5B4380
#define EQ_Character__IsExpansionFlag_x                            0x422670
#define EQ_Character__TotalEffect_x                                0x44B2A0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x594860
#define EQ_Item__CreateItemTagString_x                             0x851110
#define EQ_Item__IsStackable_x                                     0x845660
#define EQ_Item__GetImageNum_x                                     0x848370
#define EQ_Item__CreateItemClient_x                                0x595450
#define EQ_Item__GetItemValue_x                                    0x84FDE0
#define EQ_Item__ValueSellMerchant_x                               0x852420

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C70F0
#define EQ_LoadingS__Array_x                                       0xC1E0A0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C3CE0
#define EQ_PC__GetAlternateAbilityId_x                             0x85A580
#define EQ_PC__GetCombatAbility_x                                  0x85A610
#define EQ_PC__GetCombatAbilityTimer_x                             0x855380
#define EQ_PC__GetItemTimerValue_x                                 0x5BD620
#define EQ_PC__HasLoreItem_x                                       0x5B7860
#define EQ_PC__AlertInventoryChanged_x                             0x5B4350
#define EQ_PC__GetPcZoneClient_x                                   0x5DE2F0
#define EQ_PC__RemoveMyAffect_x                                    0x5BCAE0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50FD90
#define EQItemList__add_item_x                                     0x50FCD0
#define EQItemList__delete_item_x                                  0x510190
#define EQItemList__FreeItemList_x                                 0x510090

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A6730

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C9280
#define EQPlayer__dEQPlayer_x                                      0x5D2100
#define EQPlayer__DoAttack_x                                       0x5E4200
#define EQPlayer__EQPlayer_x                                       0x5D4520
#define EQPlayer__SetNameSpriteState_x                             0x5CEDD0
#define EQPlayer__SetNameSpriteTint_x                              0x5CA690
#define EQPlayer__IsBodyType_j_x                                   0x92F480
#define EQPlayer__IsTargetable_x                                   0x92FD80
#define EQPlayer__CanSee_x                                         0x9302A0
#define PlayerZoneClient__ChangeHeight_x                           0x5E40C0
#define EQPlayer__CanSeeTargetIndicator_x                          0x930390

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D8890
#define EQPlayerManager__GetSpawnByName_x                          0x5D8CF0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59A960
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59A9A0
#define KeypressHandler__ClearCommandStateArray_x                  0x59A540
#define KeypressHandler__HandleKeyDown_x                           0x598EA0
#define KeypressHandler__HandleKeyUp_x                             0x5991C0
#define KeypressHandler__SaveKeymapping_x                          0x59A610

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70B130
#define MapViewMap__SaveEx_x                                       0x70EA10

#define PlayerPointManager__GetAltCurrency_x                       0x86CE10

// StringTable 
#define StringTable__getString_x                                   0x867840

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C2140
#define PcZoneClient__RemovePetEffect_x                            0x5BDB10

//Doors
#define EQSwitch__UseSwitch_x                                      0x54E710

//IconCache
#define IconCache__GetIcon_x                                       0x6A7120

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69DF10
#define CContainerMgr__CloseContainer_x                            0x69E730

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76CDA0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58DA10

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DEE70
#define EQ_Spell__SpellAffects_x                                   0x4DEF10
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DEF40
#define CharacterZoneClient__CalcAffectChange_x                    0x4472F0
#define CLootWnd__LootAll_x                                        0x700AD0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B26A0
#define CTargetWnd__WndNotification_x                              0x7B2190

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B7880

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D8750

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x496C90

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E8EF0
#define CSidlManager__FindAnimation1_x                             0x8DDCC0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CE7C0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CE770
#define CAltAbilityData__GetMaxRank_x                              0x4C36C0

//CTargetRing
#define CTargetRing__Cast_x                                        0x58B300
