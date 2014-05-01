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
#define __ExpectedVersionDate                                     "Apr 24 2014"
#define __ExpectedVersionTime                                     "20:16:26"
#define __ActualVersionDate_x                                      0xA3E4A0
#define __ActualVersionTime_x                                      0xA3E4AC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x571910
#define __MemChecker1_x                                            0x832410
#define __MemChecker2_x                                            0x608060
#define __MemChecker3_x                                            0x607FB0
#define __MemChecker4_x                                            0x7B6E60
#define __EncryptPad0_x                                            0xBA5930
#define __EncryptPad1_x                                            0xD1BE50
#define __EncryptPad2_x                                            0xBEC040
#define __EncryptPad3_x                                            0xBEBC40
#define __EncryptPad4_x                                            0xCF9EE0
#define __AC1_x                                                    0x774885
#define __AC2_x                                                    0x5280C7
#define __AC3_x                                                    0x53C820
#define __AC4_x                                                    0x542950
#define __AC5_x                                                    0x54EF61
#define __AC6_x                                                    0x552A82
#define __AC7_x                                                    0x548A3C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10CA5A8
#define DI8__Keyboard_x                                            0x10CA5AC
#define DI8__Mouse_x                                               0x10CA5B0
#define __AltTimerReady_x                                          0xF2A359
#define __Attack_x                                                 0xFBD152
#define __Autofire_x                                               0xFBD153
#define __BindList_x                                               0xB6A418
#define __Clicks_x                                                 0xF38FA0
#define __CommandList_x                                            0xB6E488
#define __CurrentMapLabel_x                                        0x10D0228
#define __CurrentSocial_x                                          0xB308C0
#define __DoAbilityList_x                                          0xF6F700
#define __do_loot_x                                                0x4F0A40
#define __DrawHandler_x                                            0x1732784
#define __GroupCount_x                                             0xF29A32

#define __Guilds_x                                                 0xF2F520
#define __gWorld_x                                                 0xF2BEEC
#define __HotkeyPage_x                                             0xFB6100
#define __HWnd_x                                                   0xFC24B0
#define __InChatMode_x                                             0xF38ECC
#define __LastTell_x                                               0xF3AE08
#define __LMouseHeldTime_x                                         0xF3900C
#define __Mouse_x                                                  0x10CA5B4
#define __MouseLook_x                                              0xF38F66
#define __MouseEventTime_x                                         0xFBD93C
#define __NetStatusToggle_x                                        0xF38F69
#define __PCNames_x                                                0xF3A448
#define __RangeAttackReady_x                                       0xF3A0E0
#define __RMouseHeldTime_x                                         0xF39008
#define __RunWalkState_x                                           0xF38ED0
#define __ScreenMode_x                                             0xE78430
#define __ScreenX_x                                                0xF38E84
#define __ScreenY_x                                                0xF38E80
#define __ScreenXMax_x                                             0xF38E88
#define __ScreenYMax_x                                             0xF38E8C
#define __ServerHost_x                                             0xF2997C
#define __ServerName_x                                             0xF6F6C0
#define __ShiftKeyDown_x                                           0xF39570
#define __ShowNames_x                                              0xF3A2EC
#define __Socials_x                                                0xF6F7C0
#define __SubscriptionType_x                                       0x10F9F58
#define __TargetAggroHolder_x                                      0x10D2440
#define __GroupAggro_x                                             0x10D2480
#define __LoginName_x                                              0xFC1088
#define __Inviter_x                                                0xFBD0D0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF2BFD8
#define instEQZoneInfo_x                                           0xF3915C
#define instKeypressHandler_x                                      0xFBD920
#define pinstActiveBanker_x                                        0xF2BF90
#define pinstActiveCorpse_x                                        0xF2BF94
#define pinstActiveGMaster_x                                       0xF2BF98
#define pinstActiveMerchant_x                                      0xF2BF8C
#define pinstAggroInfo_x                                           0xD3CA18
#define pinstAltAdvManager_x                                       0xE79500
#define pinstAuraMgr_x                                             0xD468E0
#define pinstBandageTarget_x                                       0xF2BF78
#define pinstCamActor_x                                            0xE78E0C
#define pinstCDBStr_x                                              0xE783C4
#define pinstCDisplay_x                                            0xF2BFA0
#define pinstCEverQuest_x                                          0x10CA72C
#define pinstCharData_x                                            0xF2BF5C
#define pinstCharSpawn_x                                           0xF2BF84
#define pinstControlledMissile_x                                   0xF2BF58
#define pinstControlledPlayer_x                                    0xF2BF84
#define pinstCSidlManager_x                                        0x1731BF0
#define pinstCXWndManager_x                                        0x1731BE8
#define instDynamicZone_x                                          0xF38D18
#define pinstDZMember_x                                            0xF38E28
#define pinstDZTimerInfo_x                                         0xF38E2C
#define pinstEQItemList_x                                          0xF286B4
#define instEQMisc_x                                               0xB4BD80
#define pinstEQSoundManager_x                                      0xE79800
#define instExpeditionLeader_x                                     0xF38D62
#define instExpeditionName_x                                       0xF38DA2
#define pinstGroup_x                                               0xF29A2E
#define pinstImeManager_x                                          0x1731BF4
#define pinstLocalPlayer_x                                         0xF2BF70
#define pinstMercenaryData_x                                       0xFBDF70
#define pinstMercAltAbilities_x                                    0xE79720
#define pinstModelPlayer_x                                         0xF2BF9C
#define pinstPCData_x                                              0xF2BF5C
#define pinstSkillMgr_x                                            0xFBEDA8
#define pinstSpawnManager_x                                        0xFBE690
#define pinstSpellManager_x                                        0xFBEEF0
#define pinstSpellSets_x                                           0xFB6164
#define pinstStringTable_x                                         0xF2BF04
#define pinstSwitchManager_x                                       0xF295C0
#define pinstTarget_x                                              0xF2BF88
#define pinstTargetObject_x                                        0xF2BF60
#define pinstTargetSwitch_x                                        0xF2BF64
#define pinstTaskMember_x                                          0xE78310
#define pinstTrackTarget_x                                         0xF2BF7C
#define pinstTradeTarget_x                                         0xF2BF6C
#define instTributeActive_x                                        0xB4BDA5
#define pinstViewActor_x                                           0xE78E08
#define pinstWorldData_x                                           0xF2BF40


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD3CEF8
#define pinstCAudioTriggersWindow_x                                0xD3CD88
#define pinstCCharacterSelect_x                                    0xE78CB4
#define pinstCFacePick_x                                           0xE78A64
#define pinstCNoteWnd_x                                            0xE78C6C
#define pinstCBookWnd_x                                            0xE78C74
#define pinstCPetInfoWnd_x                                         0xE78C78
#define pinstCTrainWnd_x                                           0xE78C7C
#define pinstCSkillsWnd_x                                          0xE78C80
#define pinstCSkillsSelectWnd_x                                    0xE78C84
#define pinstCCombatSkillSelectWnd_x                               0xE78C88
#define pinstCFriendsWnd_x                                         0xE78C8C
#define pinstCAuraWnd_x                                            0xE78C90
#define pinstCRespawnWnd_x                                         0xE78C94
#define pinstCBandolierWnd_x                                       0xE78C98
#define pinstCPotionBeltWnd_x                                      0xE78C9C
#define pinstCAAWnd_x                                              0xE78CA0
#define pinstCGroupSearchFiltersWnd_x                              0xE78CA4
#define pinstCLoadskinWnd_x                                        0xE78CA8
#define pinstCAlarmWnd_x                                           0xE78CAC
#define pinstCMusicPlayerWnd_x                                     0xE78CB0
#define pinstCMailWnd_x                                            0xE78CB8
#define pinstCMailCompositionWnd_x                                 0xE78CBC
#define pinstCMailAddressBookWnd_x                                 0xE78CC0
#define pinstCRaidWnd_x                                            0xE78CC8
#define pinstCRaidOptionsWnd_x                                     0xE78CCC
#define pinstCBreathWnd_x                                          0xE78CD0
#define pinstCMapViewWnd_x                                         0xE78CD4
#define pinstCMapToolbarWnd_x                                      0xE78CD8
#define pinstCEditLabelWnd_x                                       0xE78CDC
#define pinstCTargetWnd_x                                          0xE78CE0
#define pinstCColorPickerWnd_x                                     0xE78CE4
#define pinstCPlayerWnd_x                                          0xE78CE8
#define pinstCOptionsWnd_x                                         0xE78CEC
#define pinstCBuffWindowNORMAL_x                                   0xE78CF0
#define pinstCBuffWindowSHORT_x                                    0xE78CF4
#define pinstCharacterCreation_x                                   0xE78CF8
#define pinstCCursorAttachment_x                                   0xE78CFC
#define pinstCCastingWnd_x                                         0xE78D00
#define pinstCCastSpellWnd_x                                       0xE78D04
#define pinstCSpellBookWnd_x                                       0xE78D08
#define pinstCInventoryWnd_x                                       0xE78D0C
#define pinstCBankWnd_x                                            0xE78D10
#define pinstCQuantityWnd_x                                        0xE78D14
#define pinstCLootWnd_x                                            0xE78D18
#define pinstCActionsWnd_x                                         0xE78D1C
#define pinstCCombatAbilityWnd_x                                   0xE78D20
#define pinstCMerchantWnd_x                                        0xE78D24
#define pinstCTradeWnd_x                                           0xE78D28
#define pinstCSelectorWnd_x                                        0xE78D2C
#define pinstCBazaarWnd_x                                          0xE78D30
#define pinstCBazaarSearchWnd_x                                    0xE78D34
#define pinstCGiveWnd_x                                            0xE78D50
#define pinstCTrackingWnd_x                                        0xE78D58
#define pinstCInspectWnd_x                                         0xE78D5C
#define pinstCSocialEditWnd_x                                      0xE78D60
#define pinstCFeedbackWnd_x                                        0xE78D64
#define pinstCBugReportWnd_x                                       0xE78D68
#define pinstCVideoModesWnd_x                                      0xE78D6C
#define pinstCTextEntryWnd_x                                       0xE78D74
#define pinstCFileSelectionWnd_x                                   0xE78D78
#define pinstCCompassWnd_x                                         0xE78D7C
#define pinstCPlayerNotesWnd_x                                     0xE78D80
#define pinstCGemsGameWnd_x                                        0xE78D84
#define pinstCTimeLeftWnd_x                                        0xE78D88
#define pinstCPetitionQWnd_x                                       0xE78D9C
#define pinstCSoulmarkWnd_x                                        0xE78DA0
#define pinstCStoryWnd_x                                           0xE78DA4
#define pinstCJournalTextWnd_x                                     0xE78DA8
#define pinstCJournalCatWnd_x                                      0xE78DAC
#define pinstCBodyTintWnd_x                                        0xE78DB0
#define pinstCServerListWnd_x                                      0xE78DB4
#define pinstCAvaZoneWnd_x                                         0xE78DC0
#define pinstCBlockedBuffWnd_x                                     0xE78DC4
#define pinstCBlockedPetBuffWnd_x                                  0xE78DC8
#define pinstCInvSlotMgr_x                                         0xE78E00
#define pinstCContainerMgr_x                                       0xE78E04
#define pinstCAdventureLeaderboardWnd_x                            0x10CB300
#define pinstCAdventureRequestWnd_x                                0x10CB378
#define pinstCAltStorageWnd_x                                      0x10CB658
#define pinstCAdventureStatsWnd_x                                  0x10CB3F0
#define pinstCBarterMerchantWnd_x                                  0x10CC240
#define pinstCBarterSearchWnd_x                                    0x10CC2B8
#define pinstCBarterWnd_x                                          0x10CC330
#define pinstCChatManager_x                                        0x10CC9C0
#define pinstCDynamicZoneWnd_x                                     0x10CCE70
#define pinstCEQMainWnd_x                                          0x10CD008
#define pinstCFellowshipWnd_x                                      0x10CCE04
#define pinstCFindLocationWnd_x                                    0x10CD2D8
#define pinstCGroupSearchWnd_x                                     0x10CD5A8
#define pinstCGroupWnd_x                                           0x10CD620
#define pinstCGuildBankWnd_x                                       0x10CD698
#define pinstCGuildMgmtWnd_x                                       0x10CF788
#define pinstCHotButtonWnd_x                                       0x10CF854
#define pinstCHotButtonWnd1_x                                      0x10CF854
#define pinstCHotButtonWnd2_x                                      0x10CF858
#define pinstCHotButtonWnd3_x                                      0x10CF85C
#define pinstCHotButtonWnd4_x                                      0x10CF880
#define pinstCItemDisplayManager_x                                 0x10CFB78
#define pinstCItemExpTransferWnd_x                                 0x10CFBF4
#define pinstCLFGuildWnd_x                                         0x10CFED0
#define pinstCMIZoneSelectWnd_x                                    0x10D04B8
#define pinstCConfirmationDialog_x                                 0x10D0BC0
#define pinstCPopupWndManager_x                                    0x10D0BC0
#define pinstCProgressionSelectionWnd_x                            0x10D0CB0
#define pinstCPvPStatsWnd_x                                        0x10D0DA0
#define pinstCSystemInfoDialogBox_x                                0x10D14A8
#define pinstCTaskWnd_x                                            0x10D2838
#define pinstCTaskTemplateSelectWnd_x                              0x10D27C0
#define pinstCTipWndOFDAY_x                                        0x10D2A90
#define pinstCTipWndCONTEXT_x                                      0x10D2A94
#define pinstCTitleWnd_x                                           0x10D2B10
#define pinstCContextMenuManager_x                                 0x1731804
#define pinstCVoiceMacroWnd_x                                      0xFBF558
#define pinstCHtmlWnd_x                                            0xFBF650
#define pinstIconCache_x                                           0x10CCFDC
#define pinstCTradeskillWnd_x                                      0x10D2C10

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x507680
#define __ConvertItemTags_x                                        0x4F5700
#define __ExecuteCmd_x                                             0x4E04B0
#define __EQGetTime_x                                              0x832F70
#define __get_melee_range_x                                        0x4E70E0
#define __GetGaugeValueFromEQ_x                                    0x7735E0
#define __GetLabelFromEQ_x                                         0x774810
#define __GetXTargetType_x                                         0x8EF5D0
#define __LoadFrontEnd_x                                           0x607710
#define __NewUIINI_x                                               0x772F10
#define __ProcessGameEvents_x                                      0x54AB80
#define CrashDetected_x                                            0x6091E0
#define DrawNetStatus_x                                            0x5810C0
#define Util__FastTime_x                                           0x832280
#define Expansion_HoT_x                                            0xF3A24C
#define __HelpPath_x                                               0xFBD6A8
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A4F80
#define AltAdvManager__IsAbilityReady_x                            0x4A4FF0
#define AltAdvManager__GetAltAbility_x                             0x4A53B0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x452220

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x637200

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6456E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5612A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x660270
#define CChatManager__InitContextMenu_x                            0x660D90

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x7D9280
#define CChatService__GetFriendName_x                              0x818FC0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x665B30
#define CChatWindow__Clear_x                                       0x6656E0
#define CChatWindow__WndNotification_x                             0x666070

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x891320
#define CComboWnd__Draw_x                                          0x891500
#define CComboWnd__GetCurChoice_x                                  0x891140
#define CComboWnd__GetListRect_x                                   0x8917A0
#define CComboWnd__GetTextRect_x                                   0x891380
#define CComboWnd__InsertChoice_x                                  0x891810
#define CComboWnd__SetColors_x                                     0x8910D0
#define CComboWnd__SetChoice_x                                     0x891100

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x66F260
#define CContainerWnd__vftable_x                                   0xA47C50

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x493960
#define CDisplay__GetClickedActor_x                                0x48C590
#define CDisplay__GetUserDefinedColor_x                            0x48AE50
#define CDisplay__GetWorldFilePath_x                               0x48A250
#define CDisplay__is3dON_x                                         0x489620
#define CDisplay__ReloadUI_x                                       0x49ED30
#define CDisplay__WriteTextHD2_x                                   0x48FDD0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8B2C70

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8A1C30
#define CEditWnd__GetCharIndexPt_x                                 0x8A2C50
#define CEditWnd__GetDisplayString_x                               0x8A1DE0
#define CEditWnd__GetHorzOffset_x                                  0x8A2120
#define CEditWnd__GetLineForPrintableChar_x                        0x8A2720
#define CEditWnd__GetSelStartPt_x                                  0x8A2F00
#define CEditWnd__GetSTMLSafeText_x                                0x8A22C0
#define CEditWnd__PointFromPrintableChar_x                         0x8A2810
#define CEditWnd__SelectableCharFromPoint_x                        0x8A2990
#define CEditWnd__SetEditable_x                                    0x8A2290

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x528810
#define CEverQuest__DoTellWindow_x                                 0x52E200
#define CEverQuest__DropHeldItemOnGround_x                         0x536CA0
#define CEverQuest__dsp_chat_x                                     0x52F9A0
#define CEverQuest__Emote_x                                        0x52FC00
#define CEverQuest__EnterZone_x                                    0x542AE0
#define CEverQuest__GetBodyTypeDesc_x                              0x525140
#define CEverQuest__GetClassDesc_x                                 0x52AD70
#define CEverQuest__GetClassThreeLetterCode_x                      0x52B370
#define CEverQuest__GetDeityDesc_x                                 0x525A20
#define CEverQuest__GetLangDesc_x                                  0x5254D0
#define CEverQuest__GetRaceDesc_x                                  0x52B530
#define CEverQuest__InterpretCmd_x                                 0x5304E0
#define CEverQuest__LeftClickedOnPlayer_x                          0x546EB0
#define CEverQuest__LMouseUp_x                                     0x5491A0
#define CEverQuest__RightClickedOnPlayer_x                         0x5479B0
#define CEverQuest__RMouseUp_x                                     0x5489F0
#define CEverQuest__SetGameState_x                                 0x528EC0
#define CEverQuest__UPCNotificationFlush_x                         0x531680

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x67FD40
#define CGaugeWnd__CalcLinesFillRect_x                             0x67FDA0
#define CGaugeWnd__Draw_x                                          0x6801D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x424370

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69C4F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6A8250
#define CInvSlotMgr__MoveItem_x                                    0x6A9190
#define CInvSlotMgr__SelectSlot_x                                  0x6A8300

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6A7580
#define CInvSlot__SliderComplete_x                                 0x6A53D0
#define CInvSlot__GetItemBase_x                                    0x6A4860

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6A9F40

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x770220
#define CItemDisplayWnd__UpdateStrings_x                           0x6AB270

// CLabel 
#define CLabel__Draw_x                                             0x6C5C10

// CListWnd 
#define CListWnd__AddColumn_x                                      0x87F2C0
#define CListWnd__AddColumn1_x                                     0x87EAB0
#define CListWnd__AddLine_x                                        0x87E560
#define CListWnd__AddString_x                                      0x87E770
#define CListWnd__CalculateFirstVisibleLine_x                      0x87B640
#define CListWnd__CalculateVSBRange_x                              0x87D760
#define CListWnd__ClearAllSel_x                                    0x87A8F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x87E130
#define CListWnd__Compare_x                                        0x87C130
#define CListWnd__Draw_x                                           0x87D3C0
#define CListWnd__DrawColumnSeparators_x                           0x87D250
#define CListWnd__DrawHeader_x                                     0x87AC00
#define CListWnd__DrawItem_x                                       0x87C780
#define CListWnd__DrawLine_x                                       0x87CEF0
#define CListWnd__DrawSeparator_x                                  0x87D2F0
#define CListWnd__EnsureVisible_x                                  0x87B7A0
#define CListWnd__ExtendSel_x                                      0x87C690
#define CListWnd__GetColumnMinWidth_x                              0x87A310
#define CListWnd__GetColumnWidth_x                                 0x87A230
#define CListWnd__GetCurSel_x                                      0x879AF0
#define CListWnd__GetItemAtPoint_x                                 0x87BA30
#define CListWnd__GetItemAtPoint1_x                                0x87BAA0
#define CListWnd__GetItemData_x                                    0x879D40
#define CListWnd__GetItemHeight_x                                  0x87B290
#define CListWnd__GetItemIcon_x                                    0x879F20
#define CListWnd__GetItemRect_x                                    0x87B870
#define CListWnd__GetItemText_x                                    0x879DD0
#define CListWnd__GetSelList_x                                     0x87E9A0
#define CListWnd__GetSeparatorRect_x                               0x87C050
#define CListWnd__RemoveLine_x                                     0x87E950
#define CListWnd__SetColors_x                                      0x879B50
#define CListWnd__SetColumnJustification_x                         0x87A5E0
#define CListWnd__SetColumnWidth_x                                 0x87A2C0
#define CListWnd__SetCurSel_x                                      0x879B30
#define CListWnd__SetItemColor_x                                   0x87DE10
#define CListWnd__SetItemData_x                                    0x87A9A0
#define CListWnd__SetItemText_x                                    0x87DC50
#define CListWnd__ShiftColumnSeparator_x                           0x87DAE0
#define CListWnd__Sort_x                                           0x87F42D
#define CListWnd__ToggleSel_x                                      0x87A870

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6DEF30

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6FFC70
#define CMerchantWnd__RequestBuyItem_x                             0x7061C0
#define CMerchantWnd__RequestSellItem_x                            0x72DBF0
#define CMerchantWnd__SelectRecoverySlot_x                         0x6FFF20
#define CMerchantWnd__SelectBuySellSlot_x                          0x6FF130
#define CMerchantWnd__ActualSelect_x                               0x703640

// CObfuscator
#define CObfuscator__doit_x                                        0x7F9A70

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x896AA0
#define CSidlManager__CreateLabel_x                                0x7666E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x62E3B0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x62E2E0
#define CSidlScreenWnd__ConvertToRes_x                             0x8B2B50
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8844A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x885990
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x885A40
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x884F10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x883F80
#define CSidlScreenWnd__EnableIniStorage_x                         0x8836C0
#define CSidlScreenWnd__GetSidlPiece_x                             0x884170
#define CSidlScreenWnd__Init1_x                                    0x885670
#define CSidlScreenWnd__LoadIniInfo_x                              0x884550
#define CSidlScreenWnd__LoadIniListWnd_x                           0x883880
#define CSidlScreenWnd__LoadSidlScreen_x                           0x885160
#define CSidlScreenWnd__StoreIniInfo_x                             0x883180
#define CSidlScreenWnd__StoreIniVis_x                              0x883650
#define CSidlScreenWnd__WndNotification_x                          0x8853F0
#define CSidlScreenWnd__GetChildItem_x                             0x883790
#define CSidlScreenWnd__HandleLButtonUp_x                          0x88A340

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5C9690
#define CSkillMgr__GetSkillCap_x                                   0x5C9830

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8BCB70
#define CSliderWnd__SetValue_x                                     0x8BCD40
#define CSliderWnd__SetNumTicks_x                                  0x8BD4C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x76DEC0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8AD2D0
#define CStmlWnd__CalculateHSBRange_x                              0x8A5900
#define CStmlWnd__CalculateVSBRange_x                              0x8A5990
#define CStmlWnd__CanBreakAtCharacter_x                            0x8A5B10
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8A63F0
#define CStmlWnd__ForceParseNow_x                                  0x8ADC20
#define CStmlWnd__GetNextTagPiece_x                                0x8A62F0
#define CStmlWnd__GetSTMLText_x                                    0x664F80
#define CStmlWnd__GetVisibleText_x                                 0x8A6E40
#define CStmlWnd__InitializeWindowVariables_x                      0x8A90F0
#define CStmlWnd__MakeStmlColorTag_x                               0x8A4AE0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8A4B40
#define CStmlWnd__SetSTMLText_x                                    0x8AA950
#define CStmlWnd__StripFirstSTMLLines_x                            0x8ACF70
#define CStmlWnd__UpdateHistoryString_x                            0x8A7D80

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8B4350
#define CTabWnd__DrawCurrentPage_x                                 0x8B3BC0
#define CTabWnd__DrawTab_x                                         0x8B3980
#define CTabWnd__GetCurrentPage_x                                  0x8B3F90
#define CTabWnd__GetPageInnerRect_x                                0x8B3670
#define CTabWnd__GetTabInnerRect_x                                 0x8B3870
#define CTabWnd__GetTabRect_x                                      0x8B3740
#define CTabWnd__InsertPage_x                                      0x8B4640
#define CTabWnd__SetPage_x                                         0x8B3FC0
#define CTabWnd__SetPageRect_x                                     0x8B4290
#define CTabWnd__UpdatePage_x                                      0x8B45E0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x420100

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B0720

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8B9530

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x877C00

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x411750
#define CXStr__CXStr1_x                                            0x7B01D0
#define CXStr__CXStr3_x                                            0x82F310
#define CXStr__dCXStr_x                                            0x481160
#define CXStr__operator_equal_x                                    0x82F480
#define CXStr__operator_equal1_x                                   0x82F4D0
#define CXStr__operator_plus_equal1_x                              0x8305B0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x889540
#define CXWnd__Center_x                                            0x88F760
#define CXWnd__ClrFocus_x                                          0x889110
#define CXWnd__DoAllDrawing_x                                      0x88F390
#define CXWnd__DrawChildren_x                                      0x88F540
#define CXWnd__DrawColoredRect_x                                   0x889900
#define CXWnd__DrawTooltip_x                                       0x889BA0
#define CXWnd__DrawTooltipAtPoint_x                                0x88E370
#define CXWnd__GetBorderFrame_x                                    0x88A010
#define CXWnd__GetChildWndAt_x                                     0x88D320
#define CXWnd__GetClientClipRect_x                                 0x889DC0
#define CXWnd__GetScreenClipRect_x                                 0x88EA70
#define CXWnd__GetScreenRect_x                                     0x88A1E0
#define CXWnd__GetTooltipRect_x                                    0x889A30
#define CXWnd__GetWindowTextA_x                                    0x411790
#define CXWnd__IsActive_x                                          0x89C9F0
#define CXWnd__IsDescendantOf_x                                    0x889F50
#define CXWnd__IsReallyVisible_x                                   0x88D300
#define CXWnd__IsType_x                                            0x8B5D10
#define CXWnd__Move_x                                              0x88CA70
#define CXWnd__Move1_x                                             0x88F060
#define CXWnd__ProcessTransition_x                                 0x8894E0
#define CXWnd__Refade_x                                            0x8892C0
#define CXWnd__Resize_x                                            0x88A2A0
#define CXWnd__Right_x                                             0x88E870
#define CXWnd__SetFocus_x                                          0x88BBC0
#define CXWnd__SetFont_x                                           0x889160
#define CXWnd__SetKeyTooltip_x                                     0x88A510
#define CXWnd__SetMouseOver_x                                      0x88ED60
#define CXWnd__StartFade_x                                         0x889590
#define CXWnd__GetChildItem_x                                      0x88ECB0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x89E310
#define CXWndManager__DrawWindows_x                                0x89DF50
#define CXWndManager__GetKeyboardFlags_x                           0x89C520
#define CXWndManager__HandleKeyboardMsg_x                          0x89CE70
#define CXWndManager__RemoveWnd_x                                  0x89CB80

// CDBStr
#define CDBStr__GetString_x                                        0x487A60

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8EBE80
#define EQ_Character__CastSpell_x                                  0x43C000
#define EQ_Character__Cur_HP_x                                     0x4518E0
#define EQ_Character__GetAACastingTimeModifier_x                   0x435160
#define EQ_Character__GetCharInfo2_x                               0x803C10
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42D480
#define EQ_Character__GetFocusRangeModifier_x                      0x42D660
#define EQ_Character__Max_Endurance_x                              0x592A10
#define EQ_Character__Max_HP_x                                     0x447FD0
#define EQ_Character__Max_Mana_x                                   0x592840
#define EQ_Character__doCombatAbility_x                            0x590070
#define EQ_Character__UseSkill_x                                   0x45C420
#define EQ_Character__GetConLevel_x                                0x585700
#define EQ_Character__IsExpansionFlag_x                            0x410C90
#define EQ_Character__TotalEffect_x                                0x43A130

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x5662C0
#define EQ_Item__CreateItemTagString_x                             0x7E49C0
#define EQ_Item__IsStackable_x                                     0x7D8C00
#define EQ_Item__GetImageNum_x                                     0x7DB850

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A70D0
#define EQ_LoadingS__Array_x                                       0xB59320

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x594070
#define EQ_PC__GetAltAbilityIndex_x                                0x7ECC40
#define EQ_PC__GetCombatAbility_x                                  0x7ECCD0
#define EQ_PC__GetCombatAbilityTimer_x                             0x7ECD80
#define EQ_PC__GetItemTimerValue_x                                 0x58DE50
#define EQ_PC__HasLoreItem_x                                       0x588890
#define EQ_PC__AlertInventoryChanged_x                             0x5856D0
#define EQ_PC__GetPcZoneClient_x                                   0x5ADAD0
// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E5070
#define EQItemList__add_item_x                                     0x4E4FB0
#define EQItemList__delete_item_x                                  0x4E5470
#define EQItemList__FreeItemList_x                                 0x4E5370

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x486F30

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x599480
#define EQPlayer__dEQPlayer_x                                      0x5A1F80
#define EQPlayer__DoAttack_x                                       0x5B3900
#define EQPlayer__EQPlayer_x                                       0x5A43D0
#define EQPlayer__SetNameSpriteState_x                             0x59EDA0
#define EQPlayer__SetNameSpriteTint_x                              0x59A7B0
#define EQPlayer__IsBodyType_j_x                                   0x8EB190
#define EQPlayer__IsTargetable_x                                   0x8EB960

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5A8050
#define EQPlayerManager__GetSpawnByName_x                          0x5A84B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56C3B0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56C3F0
#define KeypressHandler__ClearCommandStateArray_x                  0x56BF90
#define KeypressHandler__HandleKeyDown_x                           0x56A8E0
#define KeypressHandler__HandleKeyUp_x                             0x56AC00
#define KeypressHandler__SaveKeymapping_x                          0x56C060

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6D7350
#define MapViewMap__SaveEx_x                                       0x6DAC30

#define PlayerPointManager__GetAltCurrency_x                       0x7FDE00

// StringTable 
#define StringTable__getString_x                                   0x7F9D10

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5924C0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5224D0

//IconCache
#define IconCache__GetIcon_x                                       0x675560

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66C590
#define CContainerMgr__CloseContainer_x                            0x66CDA0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x736B80

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x55FD80

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B55A0
#define EQ_Spell__SpellAffects_x                                   0x4B5640
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B5670
#define CharacterZoneClient__CalcAffectChange_x                    0x436480
#define CLootWnd__LootAll_x                                        0x6CCF50
#define CTargetWnd__GetBuffCaster_x                                0x77BA00
