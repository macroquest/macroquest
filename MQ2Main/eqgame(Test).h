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
#define __ExpectedVersionDate                                     "Nov 19 2015"
#define __ExpectedVersionTime                                     "13:52:06"
#define __ActualVersionDate_x                                      0xAD8618
#define __ActualVersionTime_x                                      0xAD8624

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59F620
#define __MemChecker1_x                                            0x8A1130
#define __MemChecker2_x                                            0x6388A0
#define __MemChecker3_x                                            0x6387F0
#define __MemChecker4_x                                            0x7ED700
#define __EncryptPad0_x                                            0xC73D08
#define __EncryptPad1_x                                            0xDFEDE8
#define __EncryptPad2_x                                            0xCBD7F0
#define __EncryptPad3_x                                            0xCBD3F0
#define __EncryptPad4_x                                            0xDD7F78
#define __EncryptPad5_x                                            0x11AAC60
#define __AC1_x                                                    0x7AA605
#define __AC2_x                                                    0x553917
#define __AC3_x                                                    0x5684D0
#define __AC4_x                                                    0x56F150
#define __AC5_x                                                    0x57B88E
#define __AC6_x                                                    0x57F3C9
#define __AC7_x                                                    0x575F3C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data                                                 0x845EC

// Direct Input
#define DI8__Main_x                                                0x11AAC38
#define DI8__Keyboard_x                                            0x11AAC3C
#define DI8__Mouse_x                                               0x11AAC40
#define DI8__Mouse_Copy_x                                          0x1019254
#define DI8__Mouse_Check_x                                         0x10A2B24
#define __AltTimerReady_x                                          0x100A5A1
#define __Attack_x                                                 0x109D7C7
#define __Autofire_x                                               0x109D7C8
#define __BindList_x                                               0xC35DD8
#define __bCommandEnabled_x                                        0x10086B0
#define __Clicks_x                                                 0x1019310
#define __CommandList_x                                            0xC3A148
#define __CurrentMapLabel_x                                        0x11B0690
#define __CurrentSocial_x                                          0xBECF44
#define __DoAbilityList_x                                          0x104FA7C
#define __do_loot_x                                                0x51AE70
#define __DrawHandler_x                                            0x1817444
#define __GroupCount_x                                             0x1009C7A

#define __Guilds_x                                                 0x100F890
#define __gWorld_x                                                 0x100C134
#define __HotkeyPage_x                                             0x109647C
#define __HWnd_x                                                   0x10A2B40
#define __InChatMode_x                                             0x101923C
#define __LastTell_x                                               0x101B180
#define __LMouseHeldTime_x                                         0x101937C
#define __Mouse_x                                                  0x11AAC44
#define __MouseLook_x                                              0x10192D6
#define __MouseEventTime_x                                         0x109DFCC
#define __gpbCommandEvent_x                                        0x100C1FC
#define __NetStatusToggle_x                                        0x10192D9
#define __PCNames_x                                                0x101A7A0
#define __RangeAttackReady_x                                       0x101A460
#define __RMouseHeldTime_x                                         0x1019378
#define __RunWalkState_x                                           0x1019240
#define __ScreenMode_x                                             0xF583E0
#define __ScreenX_x                                                0x10191F4
#define __ScreenY_x                                                0x10191F0
#define __ScreenXMax_x                                             0x10191F8
#define __ScreenYMax_x                                             0x10191FC
#define __ServerHost_x                                             0x1009BC4
#define __ServerName_x                                             0x104FA3C
#define __ShiftKeyDown_x                                           0x10198E4
#define __ShowNames_x                                              0x101A634
#define __Socials_x                                                0x104FB3C
#define __SubscriptionType_x                                       0x11DEBC0
#define __TargetAggroHolder_x                                      0x11B28CC
#define __GroupAggro_x                                             0x11B290C
#define __LoginName_x                                              0x10A1718
#define __Inviter_x                                                0x109D744


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x100C220
#define instEQZoneInfo_x                                           0x10194CC
#define instKeypressHandler_x                                      0x109DFB0
#define pinstActiveBanker_x                                        0x100C1D8
#define pinstActiveCorpse_x                                        0x100C1DC
#define pinstActiveGMaster_x                                       0x100C1E0
#define pinstActiveMerchant_x                                      0x100C1D4
#define pinstAggroInfo_x                                           0xE1A7D8
#define pinstAltAdvManager_x                                       0xF594E8
#define pinstAuraMgr_x                                             0xE266A8
#define pinstBandageTarget_x                                       0x100C1C0
#define pinstCamActor_x                                            0xF58DF0
#define pinstCDBStr_x                                              0xF58374
#define pinstCDisplay_x                                            0x100C1E8
#define pinstCEverQuest_x                                          0x11AADB8
#define pinstCharData_x                                            0x100C1A4
#define pinstCharSpawn_x                                           0x100C1CC
#define pinstControlledMissile_x                                   0x100C1A0
#define pinstControlledPlayer_x                                    0x100C1CC
#define pinstCSidlManager_x                                        0x181687C
#define pinstCXWndManager_x                                        0x1816874
#define instDynamicZone_x                                          0x1019088
#define pinstDZMember_x                                            0x1019198
#define pinstDZTimerInfo_x                                         0x101919C
#define pinstEQItemList_x                                          0x1008900
#define instEQMisc_x                                               0xC0F2C8
#define pinstEQSoundManager_x                                      0xF59A48
#define instExpeditionLeader_x                                     0x10190D2
#define instExpeditionName_x                                       0x1019112
#define pinstGroup_x                                               0x1009C76
#define pinstImeManager_x                                          0x1816880
#define pinstLocalPlayer_x                                         0x100C1B8
#define pinstMercenaryData_x                                       0x109E600
#define pinstMercenaryStats_x                                      0x11B2A18
#define pinstMercAltAbilities_x                                    0xF59874
#define pinstModelPlayer_x                                         0x100C1E4
#define pinstPCData_x                                              0x100C1A4
#define pinstSkillMgr_x                                            0x109F438
#define pinstSpawnManager_x                                        0x109ED20
#define pinstSpellManager_x                                        0x109F580
#define pinstSpellSets_x                                           0x10964E0
#define pinstStringTable_x                                         0x100C14C
#define pinstSwitchManager_x                                       0x1009808
#define pinstTarget_x                                              0x100C1D0
#define pinstTargetObject_x                                        0x100C1A8
#define pinstTargetSwitch_x                                        0x100C1AC
#define pinstTaskMember_x                                          0xF582C0
#define pinstTrackTarget_x                                         0x100C1C4
#define pinstTradeTarget_x                                         0x100C1B4
#define instTributeActive_x                                        0xC0F2ED
#define pinstViewActor_x                                           0xF58DEC
#define pinstWorldData_x                                           0x100C188
#define pinstZoneAddr_x                                            0x101978C
#define pinstPlayerPath_x                                          0x109AEA0
#define pinstTargetIndicator_x                                     0x109B838
#define pinstCTargetManager_x                                      0x109F778

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE1ACB8
#define pinstCAudioTriggersWindow_x                                0xE1AB48
#define pinstCCharacterSelect_x                                    0xF58C80
#define pinstCFacePick_x                                           0xF58C30
#define pinstCNoteWnd_x                                            0xF58C38
#define pinstCBookWnd_x                                            0xF58C40
#define pinstCPetInfoWnd_x                                         0xF58C44
#define pinstCTrainWnd_x                                           0xF58C48
#define pinstCSkillsWnd_x                                          0xF58C4C
#define pinstCSkillsSelectWnd_x                                    0xF58C50
#define pinstCCombatSkillsSelectWnd_x                              0xF58C54
#define pinstCFriendsWnd_x                                         0xF58C58
#define pinstCAuraWnd_x                                            0xF58C5C
#define pinstCRespawnWnd_x                                         0xF58C60
#define pinstCBandolierWnd_x                                       0xF58C64
#define pinstCPotionBeltWnd_x                                      0xF58C68
#define pinstCAAWnd_x                                              0xF58C6C
#define pinstCGroupSearchFiltersWnd_x                              0xF58C70
#define pinstCLoadskinWnd_x                                        0xF58C74
#define pinstCAlarmWnd_x                                           0xF58C78
#define pinstCMusicPlayerWnd_x                                     0xF58C7C
#define pinstCMailWnd_x                                            0xF58C84
#define pinstCMailCompositionWnd_x                                 0xF58C88
#define pinstCMailAddressBookWnd_x                                 0xF58C8C
#define pinstCRaidWnd_x                                            0xF58C94
#define pinstCRaidOptionsWnd_x                                     0xF58C98
#define pinstCBreathWnd_x                                          0xF58C9C
#define pinstCMapViewWnd_x                                         0xF58CA0
#define pinstCMapToolbarWnd_x                                      0xF58CA4
#define pinstCEditLabelWnd_x                                       0xF58CA8
#define pinstCTargetWnd_x                                          0xF58CAC
#define pinstCColorPickerWnd_x                                     0xF58CB0
#define pinstCPlayerWnd_x                                          0xF58CB4
#define pinstCOptionsWnd_x                                         0xF58CB8
#define pinstCBuffWindowNORMAL_x                                   0xF58CBC
#define pinstCBuffWindowSHORT_x                                    0xF58CC0
#define pinstCharacterCreation_x                                   0xF58CC4
#define pinstCCursorAttachment_x                                   0xF58CC8
#define pinstCCastingWnd_x                                         0xF58CCC
#define pinstCCastSpellWnd_x                                       0xF58CD0
#define pinstCSpellBookWnd_x                                       0xF58CD4
#define pinstCInventoryWnd_x                                       0xF58CD8
#define pinstCBankWnd_x                                            0xF58CE0
#define pinstCQuantityWnd_x                                        0xF58CE4
#define pinstCLootWnd_x                                            0xF58CE8
#define pinstCActionsWnd_x                                         0xF58CEC
#define pinstCCombatAbilityWnd_x                                   0xF58CF0
#define pinstCMerchantWnd_x                                        0xF58CF4
#define pinstCTradeWnd_x                                           0xF58CF8
#define pinstCSelectorWnd_x                                        0xF58CFC
#define pinstCBazaarWnd_x                                          0xF58D00
#define pinstCBazaarSearchWnd_x                                    0xF58D04
#define pinstCGiveWnd_x                                            0xF58D20
#define pinstCTrackingWnd_x                                        0xF58D28
#define pinstCInspectWnd_x                                         0xF58D2C
#define pinstCSocialEditWnd_x                                      0xF58D30
#define pinstCFeedbackWnd_x                                        0xF58D34
#define pinstCBugReportWnd_x                                       0xF58D38
#define pinstCVideoModesWnd_x                                      0xF58D3C
#define pinstCTextEntryWnd_x                                       0xF58D44
#define pinstCFileSelectionWnd_x                                   0xF58D48
#define pinstCCompassWnd_x                                         0xF58D4C
#define pinstCPlayerNotesWnd_x                                     0xF58D50
#define pinstCGemsGameWnd_x                                        0xF58D54
#define pinstCTimeLeftWnd_x                                        0xF58D58
#define pinstCPetitionQWnd_x                                       0xF58D74
#define pinstCSoulmarkWnd_x                                        0xF58D78
#define pinstCStoryWnd_x                                           0xF58D7C
#define pinstCJournalTextWnd_x                                     0xF58D80
#define pinstCJournalCatWnd_x                                      0xF58D84
#define pinstCBodyTintWnd_x                                        0xF58D88
#define pinstCServerListWnd_x                                      0xF58D8C
#define pinstCAvaZoneWnd_x                                         0xF58D98
#define pinstCBlockedBuffWnd_x                                     0xF58D9C
#define pinstCBlockedPetBuffWnd_x                                  0xF58DA0
#define pinstCInvSlotMgr_x                                         0xF58DE4
#define pinstCContainerMgr_x                                       0xF58DE8
#define pinstCAdventureLeaderboardWnd_x                            0x11AB768
#define pinstCAdventureRequestWnd_x                                0x11AB7E0
#define pinstCAltStorageWnd_x                                      0x11ABAC0
#define pinstCAdventureStatsWnd_x                                  0x11AB858
#define pinstCBarterMerchantWnd_x                                  0x11AC6A8
#define pinstCBarterSearchWnd_x                                    0x11AC720
#define pinstCBarterWnd_x                                          0x11AC798
#define pinstCChatManager_x                                        0x11ACE28
#define pinstCDynamicZoneWnd_x                                     0x11AD2D8
#define pinstCEQMainWnd_x                                          0x11AD470
#define pinstCFellowshipWnd_x                                      0x11AD26C
#define pinstCFindLocationWnd_x                                    0x11AD740
#define pinstCGroupSearchWnd_x                                     0x11ADA10
#define pinstCGroupWnd_x                                           0x11ADA88
#define pinstCGuildBankWnd_x                                       0x11ADB00
#define pinstCGuildMgmtWnd_x                                       0x11AFBF0
#define pinstCHotButtonWnd_x                                       0x11AFCBC
#define pinstCHotButtonWnd1_x                                      0x11AFCBC
#define pinstCHotButtonWnd2_x                                      0x11AFCC0
#define pinstCHotButtonWnd3_x                                      0x11AFCC4
#define pinstCHotButtonWnd4_x                                      0x11AFCE8
#define pinstCItemDisplayManager_x                                 0x11AFFE0
#define pinstCItemExpTransferWnd_x                                 0x11B005C
#define pinstCLFGuildWnd_x                                         0x11B0338
#define pinstCMIZoneSelectWnd_x                                    0x11B0920
#define pinstCConfirmationDialog_x                                 0x11B1028
#define pinstCPopupWndManager_x                                    0x11B1028
#define pinstCProgressionSelectionWnd_x                            0x11B1118
#define pinstCPvPStatsWnd_x                                        0x11B1208
#define pinstCSystemInfoDialogBox_x                                0x11B1910
#define pinstCTaskWnd_x                                            0x11B2CD8
#define pinstCTaskSomething_x                                      0xE26E68
#define pinstCTaskTemplateSelectWnd_x                              0x11B2C60
#define pinstCTipWndOFDAY_x                                        0x11B2F30
#define pinstCTipWndCONTEXT_x                                      0x11B2F34
#define pinstCTitleWnd_x                                           0x11B2FB0
#define pinstCContextMenuManager_x                                 0x18167EC
#define pinstCVoiceMacroWnd_x                                      0x109FBE8
#define pinstCHtmlWnd_x                                            0x109FCE0
#define pinstIconCache_x                                           0x11AD444
#define pinstCTradeskillWnd_x                                      0x11B30B0
#define pinstCAdvancedLootWnd_x                                    0xF58DD8
#define pinstRewardSelectionWnd_x                                  0x11B1730

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5329C0
#define __ConvertItemTags_x                                        0x51FAF0
#define __ExecuteCmd_x                                             0x50A620
#define __EQGetTime_x                                              0x8A1490
#define __get_melee_range_x                                        0x5112B0
#define __GetGaugeValueFromEQ_x                                    0x7A9340
#define __GetLabelFromEQ_x                                         0x7AA590
#define __ToggleKeyRingItem_x                                      0x47E240
#define __GetXTargetType_x                                         0x9322F0
#define __LoadFrontEnd_x                                           0x637F50
#define __NewUIINI_x                                               0x7A8C40
#define __ProcessGameEvents_x                                      0x577CA0
#define __ProcessMouseEvent_x                                      0x577440
#define CrashDetected_x                                            0x639A20
#define wwsCrashReportCheckForUploader_x                           0x7FCDC0
#define DrawNetStatus_x                                            0x5AF200
#define Util__FastTime_x                                           0x8A0DE0
#define Expansion_HoT_x                                            0x101A5CC
#define __HelpPath_x                                               0x109DD38
#define __STMLToText_x                                             0x8E5D20

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41EF10
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419D60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C5390
#define AltAdvManager__IsAbilityReady_x                            0x4C5400
#define AltAdvManager__GetAAById_x                                 0x4C57C0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x464410
#define CharacterZoneClient__MakeMeVisible_x                       0x469DF0
#define CharacterZoneClient__IsStackBlocked_x                      0x446570

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x667960

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6756A0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58E520
#define CButtonWnd__CButtonWnd_x                                   0x8D9F50

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x690C70
#define CChatManager__InitContextMenu_x                            0x6917F0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E4080
#define CContextMenu__dCContextMenu_x                              0x8E4290
#define CContextMenu__AddMenuItem_x                                0x8E42A0
#define CContextMenu__RemoveMenuItem_x                             0x8E4590
#define CContextMenu__RemoveAllMenuItems_x                         0x8E45B0
#define CContextMenuManager__AddMenu_x                             0x8CFF60
#define CContextMenuManager__RemoveMenu_x                          0x8D0280
#define CContextMenuManager__PopupMenu_x                           0x8D06D0
#define CContextMenuManager__Flush_x                               0x8CFFD0
#define CContextMenuManager__GetMenu_x                             0x4153B0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8865B0
#define CChatService__GetFriendName_x                              0x8865C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x696AA0
#define CChatWindow__Clear_x                                       0x696650
#define CChatWindow__WndNotification_x                             0x696FD0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D3E30
#define CComboWnd__Draw_x                                          0x8D4040
#define CComboWnd__GetCurChoice_x                                  0x8D3C00
#define CComboWnd__GetListRect_x                                   0x8D42E0
#define CComboWnd__GetTextRect_x                                   0x8D3EA0
#define CComboWnd__InsertChoice_x                                  0x8D4350
#define CComboWnd__SetColors_x                                     0x8D3B90
#define CComboWnd__SetChoice_x                                     0x8D3BC0
#define CComboWnd__GetItemCount_x                                  0x8D3BF0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A0250
#define CContainerWnd__vftable_x                                   0xAE1FE0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B34F0
#define CDisplay__GetClickedActor_x                                0x4AC080
#define CDisplay__GetUserDefinedColor_x                            0x4AA940
#define CDisplay__GetWorldFilePath_x                               0x4A9D90
#define CDisplay__is3dON_x                                         0x4A9160
#define CDisplay__ReloadUI_x                                       0x4BEAC0
#define CDisplay__WriteTextHD2_x                                   0x4AF890

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FBBE0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E8A20
#define CEditWnd__GetCharIndexPt_x                                 0x8E9AB0
#define CEditWnd__GetDisplayString_x                               0x8E8BD0
#define CEditWnd__GetHorzOffset_x                                  0x8E8F10
#define CEditWnd__GetLineForPrintableChar_x                        0x8E9580
#define CEditWnd__GetSelStartPt_x                                  0x8E9D60
#define CEditWnd__GetSTMLSafeText_x                                0x8E90B0
#define CEditWnd__PointFromPrintableChar_x                         0x8E9670
#define CEditWnd__SelectableCharFromPoint_x                        0x8E97F0
#define CEditWnd__SetEditable_x                                    0x8E9080

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x554060
#define CEverQuest__CreateTargetIndicator_x                        0x554C90
#define CEverQuest__DeleteTargetIndicator_x                        0x554D10
#define CEverQuest__DoTellWindow_x                                 0x559A60
#define CEverQuest__DropHeldItemOnGround_x                         0x562960
#define CEverQuest__dsp_chat_x                                     0x55B410
#define CEverQuest__Emote_x                                        0x55B670
#define CEverQuest__EnterZone_x                                    0x56FAA0
#define CEverQuest__GetBodyTypeDesc_x                              0x5508D0
#define CEverQuest__GetClassDesc_x                                 0x5565D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x556BD0
#define CEverQuest__GetDeityDesc_x                                 0x5511B0
#define CEverQuest__GetLangDesc_x                                  0x550C60
#define CEverQuest__GetRaceDesc_x                                  0x556D90
#define CEverQuest__InterpretCmd_x                                 0x55BF50
#define CEverQuest__LeftClickedOnPlayer_x                          0x5743B0
#define CEverQuest__LMouseUp_x                                     0x576490
#define CEverQuest__RightClickedOnPlayer_x                         0x574EB0
#define CEverQuest__RMouseUp_x                                     0x575EF0
#define CEverQuest__SetGameState_x                                 0x554710
#define CEverQuest__UPCNotificationFlush_x                         0x55D2B0
#define CEverQuest__IssuePetCommand_x                              0x55CC10

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B0EC0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B0F20
#define CGaugeWnd__Draw_x                                          0x6B1350

// CGuild
#define CGuild__FindMemberByName_x                                 0x435F10

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CDF90

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DA750
#define CInvSlotMgr__MoveItem_x                                    0x6DB690
#define CInvSlotMgr__SelectSlot_x                                  0x6DA800

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D9BE0
#define CInvSlot__SliderComplete_x                                 0x6D7410
#define CInvSlot__GetItemBase_x                                    0x6D6860

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DCAA0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A5CF0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DDE10

// CLabel 
#define CLabel__Draw_x                                             0x6F8C60

// CListWnd
#define CListWnd__CListWnd_x                                       0x8BFD10
#define CListWnd__dCListWnd_x                                      0x8C0D40
#define CListWnd__AddColumn_x                                      0x8C0CE0
#define CListWnd__AddColumn1_x                                     0x8C0550
#define CListWnd__AddLine_x                                        0x8BFFD0
#define CListWnd__AddString_x                                      0x8C01E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BD040
#define CListWnd__CalculateVSBRange_x                              0x8BF1C0
#define CListWnd__ClearAllSel_x                                    0x8BC2F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BFBA0
#define CListWnd__Compare_x                                        0x8BDB50
#define CListWnd__Draw_x                                           0x8BEDD0
#define CListWnd__DrawColumnSeparators_x                           0x8BEC60
#define CListWnd__DrawHeader_x                                     0x8BC600
#define CListWnd__DrawItem_x                                       0x8BE190
#define CListWnd__DrawLine_x                                       0x8BE900
#define CListWnd__DrawSeparator_x                                  0x8BED00
#define CListWnd__EnsureVisible_x                                  0x8BD1A0
#define CListWnd__ExtendSel_x                                      0x8BE0A0
#define CListWnd__GetColumnMinWidth_x                              0x8BBCB0
#define CListWnd__GetColumnWidth_x                                 0x8BBBD0
#define CListWnd__GetCurSel_x                                      0x8BB3B0
#define CListWnd__GetItemAtPoint_x                                 0x8BD440
#define CListWnd__GetItemAtPoint1_x                                0x8BD4B0
#define CListWnd__GetItemData_x                                    0x8BB6F0
#define CListWnd__GetItemHeight_x                                  0x8BCC90
#define CListWnd__GetItemIcon_x                                    0x8BB8D0
#define CListWnd__GetItemRect_x                                    0x8BD280
#define CListWnd__GetItemText_x                                    0x8BB780
#define CListWnd__GetSelList_x                                     0x8C0440
#define CListWnd__GetSeparatorRect_x                               0x8BDA70
#define CListWnd__RemoveLine_x                                     0x8C03C0
#define CListWnd__SetColors_x                                      0x8BB500
#define CListWnd__SetColumnJustification_x                         0x8BBF80
#define CListWnd__SetColumnWidth_x                                 0x8BBC60
#define CListWnd__SetCurSel_x                                      0x8BB3F0
#define CListWnd__SetItemColor_x                                   0x8BF880
#define CListWnd__SetItemData_x                                    0x8BC3A0
#define CListWnd__SetItemText_x                                    0x8BF6C0
#define CListWnd__ShiftColumnSeparator_x                           0x8BF550
#define CListWnd__Sort_x                                           0x8C0E40
#define CListWnd__ToggleSel_x                                      0x8BC270

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x712220

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x733450
#define CMerchantWnd__RequestBuyItem_x                             0x73A240
#define CMerchantWnd__RequestSellItem_x                            0x73AC90
#define CMerchantWnd__SelectRecoverySlot_x                         0x733700
#define CMerchantWnd__SelectBuySellSlot_x                          0x732960
#define CMerchantWnd__ActualSelect_x                               0x737180

// CObfuscator
#define CObfuscator__doit_x                                        0x8668E0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8DEEB0
#define CSidlManager__CreateLabel_x                                0x79BCA0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65EC40
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65EB60
#define CSidlScreenWnd__ConvertToRes_x                             0x8FBAC0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D6AA0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D7F90
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D8040
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D7500
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D6450
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D5BA0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D6640
#define CSidlScreenWnd__Init1_x                                    0x8D7C60
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D6B50
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D5D60
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D7750
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D5670
#define CSidlScreenWnd__StoreIniVis_x                              0x8D5B30
#define CSidlScreenWnd__WndNotification_x                          0x8D79E0
#define CSidlScreenWnd__GetChildItem_x                             0x8D5C70
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C92C0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F9D80
#define CSkillMgr__GetSkillCap_x                                   0x5F9F40
#define CSkillMgr__GetNameToken_x                                  0x5F99A0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FAD80
#define CSliderWnd__SetValue_x                                     0x8FAF50
#define CSliderWnd__SetNumTicks_x                                  0x8FB6D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A39A0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F5760
#define CStmlWnd__CalculateHSBRange_x                              0x8EDC70
#define CStmlWnd__CalculateVSBRange_x                              0x8EDD00
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EDE80
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EE760
#define CStmlWnd__ForceParseNow_x                                  0x8F60B0
#define CStmlWnd__GetNextTagPiece_x                                0x8EE660
#define CStmlWnd__GetSTMLText_x                                    0x695EF0
#define CStmlWnd__GetVisibleText_x                                 0x8EF1B0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F1540
#define CStmlWnd__MakeStmlColorTag_x                               0x8ECF70
#define CStmlWnd__MakeWndNotificationTag_x                         0x8ECFD0
#define CStmlWnd__SetSTMLText_x                                    0x8F2DB0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F5400
#define CStmlWnd__UpdateHistoryString_x                            0x8F00F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EC600
#define CTabWnd__DrawCurrentPage_x                                 0x8EBE70
#define CTabWnd__DrawTab_x                                         0x8EBC30
#define CTabWnd__GetCurrentPage_x                                  0x8EC240
#define CTabWnd__GetPageInnerRect_x                                0x8EB920
#define CTabWnd__GetTabInnerRect_x                                 0x8EBB20
#define CTabWnd__GetTabRect_x                                      0x8EB9F0
#define CTabWnd__InsertPage_x                                      0x8EC8F0
#define CTabWnd__SetPage_x                                         0x8EC270
#define CTabWnd__SetPageRect_x                                     0x8EC540
#define CTabWnd__UpdatePage_x                                      0x8EC890

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431C30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D3800

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x900F40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B9400

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59BBD0
#define CXStr__CXStr1_x                                            0x43F600
#define CXStr__CXStr3_x                                            0x89DE70
#define CXStr__dCXStr_x                                            0x8C7E30
#define CXStr__operator_equal_x                                    0x89DFE0
#define CXStr__operator_equal1_x                                   0x89E030
#define CXStr__operator_plus_equal1_x                              0x89F110

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C8540
#define CXWnd__Center_x                                            0x8CE5C0
#define CXWnd__ClrFocus_x                                          0x8C8120
#define CXWnd__DoAllDrawing_x                                      0x8CE220
#define CXWnd__DrawChildren_x                                      0x8CE3C0
#define CXWnd__DrawColoredRect_x                                   0x8C88D0
#define CXWnd__DrawTooltip_x                                       0x8C8B80
#define CXWnd__DrawTooltipAtPoint_x                                0x8CD1B0
#define CXWnd__GetBorderFrame_x                                    0x8C8FB0
#define CXWnd__GetChildWndAt_x                                     0x8CEF90
#define CXWnd__GetClientClipRect_x                                 0x8C8D90
#define CXWnd__GetScreenClipRect_x                                 0x8CD8B0
#define CXWnd__GetScreenRect_x                                     0x8C9160
#define CXWnd__GetTooltipRect_x                                    0x8C8A10
#define CXWnd__GetWindowTextA_x                                    0x422FB0
#define CXWnd__IsActive_x                                          0x8C3B20
#define CXWnd__IsDescendantOf_x                                    0x8C8F00
#define CXWnd__IsReallyVisible_x                                   0x8CC1F0
#define CXWnd__IsType_x                                            0x8FD720
#define CXWnd__Move_x                                              0x8CB900
#define CXWnd__Move1_x                                             0x8CDEF0
#define CXWnd__ProcessTransition_x                                 0x8C84F0
#define CXWnd__Refade_x                                            0x8C82C0
#define CXWnd__Resize_x                                            0x8C9220
#define CXWnd__Right_x                                             0x8CD6B0
#define CXWnd__SetFocus_x                                          0x8CAA80
#define CXWnd__SetFont_x                                           0x8C8170
#define CXWnd__SetKeyTooltip_x                                     0x8C9490
#define CXWnd__SetMouseOver_x                                      0x8CDBE0
#define CXWnd__StartFade_x                                         0x8C8590
#define CXWnd__GetChildItem_x                                      0x8CDB20

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C5440
#define CXWndManager__DrawWindows_x                                0x8C5090
#define CXWndManager__GetKeyboardFlags_x                           0x8C3690
#define CXWndManager__HandleKeyboardMsg_x                          0x8C3FB0
#define CXWndManager__RemoveWnd_x                                  0x8C3CB0

// CDBStr
#define CDBStr__GetString_x                                        0x4A7680

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E200
#define EQ_Character__Cur_HP_x                                     0x463AE0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4460F0
#define EQ_Character__GetCharInfo2_x                               0x871190
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43E0E0
#define EQ_Character__GetFocusRangeModifier_x                      0x43E2D0
#define EQ_Character__Max_Endurance_x                              0x5C1960
#define EQ_Character__Max_HP_x                                     0x459720
#define EQ_Character__Max_Mana_x                                   0x5C1790
#define EQ_Character__doCombatAbility_x                            0x5BEDE0
#define EQ_Character__UseSkill_x                                   0x46EFE0
#define EQ_Character__GetConLevel_x                                0x5B3860
#define EQ_Character__IsExpansionFlag_x                            0x4224F0
#define EQ_Character__TotalEffect_x                                0x44B4A0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x593D70
#define EQ_Item__CreateItemTagString_x                             0x850410
#define EQ_Item__IsStackable_x                                     0x844740
#define EQ_Item__GetImageNum_x                                     0x8474C0
#define EQ_Item__CreateItemClient_x                                0x594950
#define EQ_Item__GetItemValue_x                                    0x84F0C0
#define EQ_Item__ValueSellMerchant_x                               0x8517A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C7540
#define EQ_LoadingS__Array_x                                       0xC1D0A0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C2FC0
#define EQ_PC__GetAlternateAbilityId_x                             0x8598D0
#define EQ_PC__GetCombatAbility_x                                  0x859960
#define EQ_PC__GetCombatAbilityTimer_x                             0x854710
#define EQ_PC__GetItemTimerValue_x                                 0x5BC910
#define EQ_PC__HasLoreItem_x                                       0x5B6D20
#define EQ_PC__AlertInventoryChanged_x                             0x5B3830
#define EQ_PC__GetPcZoneClient_x                                   0x5DD510
#define EQ_PC__RemoveMyAffect_x                                    0x5BBDD0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50F300
#define EQItemList__add_item_x                                     0x50F240
#define EQItemList__delete_item_x                                  0x50F700
#define EQItemList__FreeItemList_x                                 0x50F600

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A6950

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C8520
#define EQPlayer__dEQPlayer_x                                      0x5D13A0
#define EQPlayer__DoAttack_x                                       0x5E3420
#define EQPlayer__EQPlayer_x                                       0x5D37C0
#define EQPlayer__SetNameSpriteState_x                             0x5CE070
#define EQPlayer__SetNameSpriteTint_x                              0x5C9930
#define EQPlayer__IsBodyType_j_x                                   0x92E4E0
#define EQPlayer__IsTargetable_x                                   0x92EDE0
#define EQPlayer__CanSee_x                                         0x92F300
#define PlayerZoneClient__ChangeHeight_x                           0x5E32E0
#define EQPlayer__CanSeeTargetIndicator_x                          0x92F3F0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D7AC0
#define EQPlayerManager__GetSpawnByName_x                          0x5D7F20

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x599F00
#define KeypressHandler__AttachKeyToEqCommand_x                    0x599F40
#define KeypressHandler__ClearCommandStateArray_x                  0x599AE0
#define KeypressHandler__HandleKeyDown_x                           0x598440
#define KeypressHandler__HandleKeyUp_x                             0x598760
#define KeypressHandler__SaveKeymapping_x                          0x599BB0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70A600
#define MapViewMap__SaveEx_x                                       0x70DEE0

#define PlayerPointManager__GetAltCurrency_x                       0x86C0B0

// StringTable 
#define StringTable__getString_x                                   0x866B80

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C1410
#define PcZoneClient__RemovePetEffect_x                            0x5BCE00

//Doors
#define EQSwitch__UseSwitch_x                                      0x54DCA0

//IconCache
#define IconCache__GetIcon_x                                       0x6A6780

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69D4D0
#define CContainerMgr__CloseContainer_x                            0x69DCF0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76BF10

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58CFC0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DF3A0
#define EQ_Spell__SpellAffects_x                                   0x4DF440
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DF470
#define CharacterZoneClient__CalcAffectChange_x                    0x4474E0
#define CLootWnd__LootAll_x                                        0x6FFF90

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B1950
#define CTargetWnd__WndNotification_x                              0x7B1440

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B6B20

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D8C80

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x496DD0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E8050
#define CSidlManager__FindAnimation1_x                             0x8DCDB0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CEAC0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CEA70
#define CAltAbilityData__GetMaxRank_x                              0x4C3A50

//CTargetRing
#define CTargetRing__Cast_x                                        0x58A8C0
