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
#define __ExpectedVersionDate                                     "Jun 13 2013"
#define __ExpectedVersionTime                                     "14:00:51"
#define __ActualVersionDate_x                                      0x9DE3C8
#define __ActualVersionTime_x                                      0x9DE3D4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5653F0
#define __MemChecker1_x                                            0x80A0F0
#define __MemChecker2_x                                            0x5FAB30
#define __MemChecker3_x                                            0x5FAA80
#define __MemChecker4_x                                            0x8CCFF0
#define __EncryptPad0_x                                            0xAE5300
#define __EncryptPad1_x                                            0xB62958
#define __EncryptPad2_x                                            0xAFE9B0
#define __EncryptPad3_x                                            0xAFE5B0
#define __EncryptPad4_x                                            0xB68108
#define __AC1_x                                                    0x764835
#define __AC2_x                                                    0x5199B7
#define __AC3_x                                                    0x52CE10
#define __AC4_x                                                    0x532E84
#define __AC5_x                                                    0x53EEEB
#define __AC6_x                                                    0x542822
#define __AC7_x                                                    0x538E0C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0xE68BB8
#define DI8__Keyboard_x                                            0xE68BBC
#define DI8__Mouse_x                                               0xE68BC0
#define __AltTimerReady_x                                          0xDD1A79
#define __Attack_x                                                 0xE6460A
#define __Autofire_x                                               0xE6460B
#define __BindList_x                                               0xACCEF8
#define __Clicks_x                                                 0xDE0794
#define __CommandList_x                                            0xACE5C0
#define __CurrentMapLabel_x                                        0xF74E70
#define __CurrentSocial_x                                          0xAB7A28
#define __DoAbilityList_x                                          0xE16EB0
#define __do_loot_x                                                0x4E7D50
#define __DrawHandler_x                                            0x15D5724
#define __GroupCount_x                                             0xDD1152

#define __Guilds_x                                                 0xDD6D58
#define __gWorld_x                                                 0xDD360C
#define __HotkeyPage_x                                             0xE5D8B0
#define __HWnd_x                                                   0xE68910
#define __InChatMode_x                                             0xDE06CC
#define __LastTell_x                                               0xDE25B8
#define __LMouseHeldTime_x                                         0xDE0800
#define __Mouse_x                                                  0xE68BC4
#define __MouseLook_x                                              0xDE0762
#define __MouseEventTime_x                                         0xE64A34
#define __NetStatusToggle_x                                        0xDE0765
#define __PCNames_x                                                0xDE1C28
#define __RangeAttackReady_x                                       0xDE18C4
#define __RMouseHeldTime_x                                         0xDE07FC
#define __RunWalkState_x                                           0xDE06D0
#define __ScreenMode_x                                             0xD203F8
#define __ScreenX_x                                                0xDE0684
#define __ScreenY_x                                                0xDE0680
#define __ScreenXMax_x                                             0xDE0688
#define __ScreenYMax_x                                             0xDE068C
#define __ServerHost_x                                             0xDD109C
#define __ServerName_x                                             0xE16E70
#define __ShiftKeyDown_x                                           0xDE0D60
#define __ShowNames_x                                              0xDE1AD0
#define __Socials_x                                                0xE16F70


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xDD36F0
#define instEQZoneInfo_x                                           0xDE0950
#define instKeypressHandler_x                                      0xE64A18
#define pinstActiveBanker_x                                        0xDD36B0
#define pinstActiveCorpse_x                                        0xDD36B4
#define pinstActiveGMaster_x                                       0xDD36B8
#define pinstActiveMerchant_x                                      0xDD36AC
#define pinstAggroInfo_x                                           0xB7A090
#define pinstAltAdvManager_x                                       0xD21398
#define pinstAuraMgr_x                                             0xB83990
#define pinstBandageTarget_x                                       0xDD3698
#define pinstCamActor_x                                            0xD20DCC
#define pinstCDBStr_x                                              0xD203C0
#define pinstCDisplay_x                                            0xDD36C0
#define pinstCEverQuest_x                                          0xE68D3C
#define pinstCharData_x                                            0xDD367C
#define pinstCharSpawn_x                                           0xDD36A4
#define pinstControlledMissile_x                                   0xDD3678
#define pinstControlledPlayer_x                                    0xDD36A4
#define pinstCSidlManager_x                                        0x15D4D88
#define pinstCXWndManager_x                                        0x15D4D80
#define instDynamicZone_x                                          0xDE0530
#define pinstDZMember_x                                            0xDE0640
#define pinstDZTimerInfo_x                                         0xDE0644
#define pinstEQItemList_x                                          0xDD0170
#define instEQMisc_x                                               0xAC0CD0
#define pinstEQSoundManager_x                                      0xD214A0
#define instExpeditionLeader_x                                     0xDE057A
#define instExpeditionName_x                                       0xDE05BA
#define pinstGroup_x                                               0xDD114E
#define pinstImeManager_x                                          0x15D4D8C
#define pinstLocalPlayer_x                                         0xDD3690
#define pinstMercenaryData_x                                       0xE64EF8
#define pinstModelPlayer_x                                         0xDD36BC
#define pinstPCData_x                                              0xDD367C
#define pinstSkillMgr_x                                            0xE65678
#define pinstSpawnManager_x                                        0xE65238
#define pinstSpellManager_x                                        0xE65718
#define pinstSpellSets_x                                           0xE5D914
#define pinstStringTable_x                                         0xDD3624
#define pinstSwitchManager_x                                       0xDD0D60
#define pinstTarget_x                                              0xDD36A8
#define pinstTargetObject_x                                        0xDD3680
#define pinstTargetSwitch_x                                        0xDD3684
#define pinstTaskMember_x                                          0xD20354
#define pinstTrackTarget_x                                         0xDD369C
#define pinstTradeTarget_x                                         0xDD368C
#define instTributeActive_x                                        0xAC0CF5
#define pinstViewActor_x                                           0xD20DC8
#define pinstWorldData_x                                           0xDD3660


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xB7A2E8
#define pinstCAudioTriggersWindow_x                                0xB7A220
#define pinstCCharacterSelect_x                                    0xD20C74
#define pinstCFacePick_x                                           0xD20A24
#define pinstCNoteWnd_x                                            0xD20C2C
#define pinstCBookWnd_x                                            0xD20C34
#define pinstCPetInfoWnd_x                                         0xD20C38
#define pinstCTrainWnd_x                                           0xD20C3C
#define pinstCSkillsWnd_x                                          0xD20C40
#define pinstCSkillsSelectWnd_x                                    0xD20C44
#define pinstCCombatSkillSelectWnd_x                               0xD20C48
#define pinstCFriendsWnd_x                                         0xD20C4C
#define pinstCAuraWnd_x                                            0xD20C50
#define pinstCRespawnWnd_x                                         0xD20C54
#define pinstCBandolierWnd_x                                       0xD20C58
#define pinstCPotionBeltWnd_x                                      0xD20C5C
#define pinstCAAWnd_x                                              0xD20C60
#define pinstCGroupSearchFiltersWnd_x                              0xD20C64
#define pinstCLoadskinWnd_x                                        0xD20C68
#define pinstCAlarmWnd_x                                           0xD20C6C
#define pinstCMusicPlayerWnd_x                                     0xD20C70
#define pinstCMailWnd_x                                            0xD20C78
#define pinstCMailCompositionWnd_x                                 0xD20C7C
#define pinstCMailAddressBookWnd_x                                 0xD20C80
#define pinstCRaidWnd_x                                            0xD20C88
#define pinstCRaidOptionsWnd_x                                     0xD20C8C
#define pinstCBreathWnd_x                                          0xD20C90
#define pinstCMapViewWnd_x                                         0xD20C94
#define pinstCMapToolbarWnd_x                                      0xD20C98
#define pinstCEditLabelWnd_x                                       0xD20C9C
#define pinstCTargetWnd_x                                          0xD20CA0
#define pinstCColorPickerWnd_x                                     0xD20CA4
#define pinstCPlayerWnd_x                                          0xD20CA8
#define pinstCOptionsWnd_x                                         0xD20CAC
#define pinstCBuffWindowNORMAL_x                                   0xD20CB0
#define pinstCBuffWindowSHORT_x                                    0xD20CB4
#define pinstCharacterCreation_x                                   0xD20CB8
#define pinstCCursorAttachment_x                                   0xD20CBC
#define pinstCCastingWnd_x                                         0xD20CC0
#define pinstCCastSpellWnd_x                                       0xD20CC4
#define pinstCSpellBookWnd_x                                       0xD20CC8
#define pinstCInventoryWnd_x                                       0xD20CCC
#define pinstCBankWnd_x                                            0xD20CD0
#define pinstCQuantityWnd_x                                        0xD20CD4
#define pinstCLootWnd_x                                            0xD20CD8
#define pinstCActionsWnd_x                                         0xD20CDC
#define pinstCCombatAbilityWnd_x                                   0xD20CE0
#define pinstCMerchantWnd_x                                        0xD20CE4
#define pinstCTradeWnd_x                                           0xD20CE8
#define pinstCSelectorWnd_x                                        0xD20CEC
#define pinstCBazaarWnd_x                                          0xD20CF0
#define pinstCBazaarSearchWnd_x                                    0xD20CF4
#define pinstCGiveWnd_x                                            0xD20D10
#define pinstCTrackingWnd_x                                        0xD20D18
#define pinstCInspectWnd_x                                         0xD20D1C
#define pinstCSocialEditWnd_x                                      0xD20D20
#define pinstCFeedbackWnd_x                                        0xD20D24
#define pinstCBugReportWnd_x                                       0xD20D28
#define pinstCVideoModesWnd_x                                      0xD20D2C
#define pinstCTextEntryWnd_x                                       0xD20D34
#define pinstCFileSelectionWnd_x                                   0xD20D38
#define pinstCCompassWnd_x                                         0xD20D3C
#define pinstCPlayerNotesWnd_x                                     0xD20D40
#define pinstCGemsGameWnd_x                                        0xD20D44
#define pinstCTimeLeftWnd_x                                        0xD20D48
#define pinstCPetitionQWnd_x                                       0xD20D5C
#define pinstCSoulmarkWnd_x                                        0xD20D60
#define pinstCStoryWnd_x                                           0xD20D64
#define pinstCJournalTextWnd_x                                     0xD20D68
#define pinstCJournalCatWnd_x                                      0xD20D6C
#define pinstCBodyTintWnd_x                                        0xD20D70
#define pinstCServerListWnd_x                                      0xD20D74
#define pinstCAvaZoneWnd_x                                         0xD20D80
#define pinstCBlockedBuffWnd_x                                     0xD20D84
#define pinstCBlockedPetBuffWnd_x                                  0xD20D88
#define pinstCInvSlotMgr_x                                         0xD20DC0
#define pinstCContainerMgr_x                                       0xD20DC4
#define pinstCAdventureLeaderboardWnd_x                            0xF71530
#define pinstCAdventureRequestWnd_x                                0xF71570
#define pinstCAltStorageWnd_x                                      0xF71700
#define pinstCAdventureStatsWnd_x                                  0xF715B0
#define pinstCBarterMerchantWnd_x                                  0xF71CE0
#define pinstCBarterSearchWnd_x                                    0xF71D20
#define pinstCBarterWnd_x                                          0xF71D60
#define pinstCChatManager_x                                        0xF720E0
#define pinstCDynamicZoneWnd_x                                     0xF72350
#define pinstCEQMainWnd_x                                          0xF72430
#define pinstCFellowshipWnd_x                                      0xF7231C
#define pinstCFindLocationWnd_x                                    0xF725B0
#define pinstCGroupSearchWnd_x                                     0xF72760
#define pinstCGroupWnd_x                                           0xF727A0
#define pinstCGuildBankWnd_x                                       0xF727E0
#define pinstCGuildMgmtWnd_x                                       0xF74860
#define pinstCHotButtonWnd_x                                       0xF748C4
#define pinstCHotButtonWnd1_x                                      0xF748C4
#define pinstCHotButtonWnd2_x                                      0xF748C8
#define pinstCHotButtonWnd3_x                                      0xF748CC
#define pinstCHotButtonWnd4_x                                      0xF748F0
#define pinstCItemDisplayManager_x                                 0xF74A98
#define pinstCItemExpTransferWnd_x                                 0xF74ADC
#define pinstCLFGuildWnd_x                                         0xF74C98
#define pinstCMIZoneSelectWnd_x                                    0xF74FE8
#define pinstCConfirmationDialog_x                                 0xF753A8
#define pinstCPopupWndManager_x                                    0xF753A8
#define pinstCProgressionSelectionWnd_x                            0xF75428
#define pinstCPvPStatsWnd_x                                        0xF754A8
#define pinstCSystemInfoDialogBox_x                                0xF75868
#define pinstCTaskTemplateSelectWnd_x                              0xF767D0
#define pinstCTipWndOFDAY_x                                        0xF76940
#define pinstCTipWndCONTEXT_x                                      0xF76944
#define pinstCTitleWnd_x                                           0xF76988
#define pinstCContextMenuManager_x                                 0x15D499C
#define pinstCVoiceMacroWnd_x                                      0xE65AD0
#define pinstCHtmlWnd_x                                            0xE65B58


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x4FDB30
#define __ConvertItemTags_x                                        0x4ED750
#define __ExecuteCmd_x                                             0x4D76F0
#define __EQGetTime_x                                              0x80AC50
#define __get_melee_range_x                                        0x4DE380
#define __GetGaugeValueFromEQ_x                                    0x763590
#define __GetLabelFromEQ_x                                         0x7647C0
#define __GetXTargetType_x                                         0x8D4C00
#define __LoadFrontEnd_x                                           0x5FA1E0
#define __NewUIINI_x                                               0x762EC0
#define __ProcessGameEvents_x                                      0x53AEF0
#define CrashDetected_x                                            0x5FC85B
#define DrawNetStatus_x                                            0x5747B0
#define Util__FastTime_x                                           0x809F90
#define Expansion_HoT_x                                            0xDE1A30
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A38D0
#define AltAdvManager__IsAbilityReady_x                            0x4A3910
#define AltAdvManager__GetAltAbility_x                             0x4A3CF0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x44A130

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6290C0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x637440

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x550C60

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x651C70
#define CChatManager__InitContextMenu_x                            0x652790

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x7F0DD0
#define CChatService__GetFriendName_x                              0x7F0DE0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6574B0
#define CChatWindow__Clear_x                                       0x657070
#define CChatWindow__WndNotification_x                             0x6579E0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x86BAE0
#define CComboWnd__Draw_x                                          0x86BCC0
#define CComboWnd__GetCurChoice_x                                  0x86B900
#define CComboWnd__GetListRect_x                                   0x86BF60
#define CComboWnd__GetTextRect_x                                   0x86BB40
#define CComboWnd__InsertChoice_x                                  0x86BFD0
#define CComboWnd__SetColors_x                                     0x86B890
#define CComboWnd__SetChoice_x                                     0x86B8C0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x660AA0
#define CContainerWnd__vftable_x                                   0x9E78D0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4938B0
#define CDisplay__GetClickedActor_x                                0x48B890
#define CDisplay__GetUserDefinedColor_x                            0x48A150
#define CDisplay__GetWorldFilePath_x                               0x489550
#define CDisplay__is3dON_x                                         0x488630
#define CDisplay__ReloadUI_x                                       0x49D880
#define CDisplay__WriteTextHD2_x                                   0x48ED10

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x88D170

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x87C330
#define CEditWnd__GetCharIndexPt_x                                 0x87D360
#define CEditWnd__GetDisplayString_x                               0x87C4E0
#define CEditWnd__GetHorzOffset_x                                  0x87C820
#define CEditWnd__GetLineForPrintableChar_x                        0x87CE20
#define CEditWnd__GetSelStartPt_x                                  0x87D620
#define CEditWnd__GetSTMLSafeText_x                                0x87C9C0
#define CEditWnd__PointFromPrintableChar_x                         0x87CF10
#define CEditWnd__SelectableCharFromPoint_x                        0x87D090
#define CEditWnd__SetEditable_x                                    0x87C990

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x51A100
#define CEverQuest__DoTellWindow_x                                 0x51EA50
#define CEverQuest__DropHeldItemOnGround_x                         0x527310
#define CEverQuest__dsp_chat_x                                     0x5201F0
#define CEverQuest__Emote_x                                        0x520450
#define CEverQuest__EnterZone_x                                    0x533010
#define CEverQuest__GetBodyTypeDesc_x                              0x5166C0
#define CEverQuest__GetClassDesc_x                                 0x515E20
#define CEverQuest__GetClassThreeLetterCode_x                      0x516420
#define CEverQuest__GetDeityDesc_x                                 0x516FD0
#define CEverQuest__GetLangDesc_x                                  0x516A50
#define CEverQuest__GetRaceDesc_x                                  0x516D40
#define CEverQuest__InterpretCmd_x                                 0x520D30
#define CEverQuest__LeftClickedOnPlayer_x                          0x5373A0
#define CEverQuest__LMouseUp_x                                     0x539560
#define CEverQuest__RightClickedOnPlayer_x                         0x537E10
#define CEverQuest__RMouseUp_x                                     0x538DC0
#define CEverQuest__SetGameState_x                                 0x51A7B0
#define CEverQuest__UPCNotificationFlush_x                         0x521CC0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x670910
#define CGaugeWnd__CalcLinesFillRect_x                             0x670970
#define CGaugeWnd__Draw_x                                          0x670DA0

// CGuild
#define CGuild__FindMemberByName_x                                 0x423CC0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x68DA40

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x699000
#define CInvSlotMgr__MoveItem_x                                    0x699F30

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6983F0
#define CInvSlot__SliderComplete_x                                 0x696410
#define CInvSlot__GetItemBase_x                                    0x695910

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x69ACB0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x760200
#define CItemDisplayWnd__UpdateStrings_x                           0x69BFE0

// CLabel 
#define CLabel__Draw_x                                             0x6B5E40

// CListWnd 
#define CListWnd__AddColumn_x                                      0x859D20
#define CListWnd__AddColumn1_x                                     0x859500
#define CListWnd__AddLine_x                                        0x858FB0
#define CListWnd__AddString_x                                      0x8591C0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8560A0
#define CListWnd__CalculateVSBRange_x                              0x8581D0
#define CListWnd__ClearAllSel_x                                    0x855350
#define CListWnd__CloseAndUpdateEditWindow_x                       0x858BA0
#define CListWnd__Compare_x                                        0x856BA0
#define CListWnd__Draw_x                                           0x857E30
#define CListWnd__DrawColumnSeparators_x                           0x857CC0
#define CListWnd__DrawHeader_x                                     0x855660
#define CListWnd__DrawItem_x                                       0x8571F0
#define CListWnd__DrawLine_x                                       0x857960
#define CListWnd__DrawSeparator_x                                  0x857D60
#define CListWnd__EnsureVisible_x                                  0x856200
#define CListWnd__ExtendSel_x                                      0x857100
#define CListWnd__GetColumnMinWidth_x                              0x854D70
#define CListWnd__GetColumnWidth_x                                 0x854C90
#define CListWnd__GetCurSel_x                                      0x854570
#define CListWnd__GetItemAtPoint_x                                 0x8564A0
#define CListWnd__GetItemAtPoint1_x                                0x856510
#define CListWnd__GetItemData_x                                    0x8547A0
#define CListWnd__GetItemHeight_x                                  0x855CF0
#define CListWnd__GetItemIcon_x                                    0x854980
#define CListWnd__GetItemRect_x                                    0x8562E0
#define CListWnd__GetItemText_x                                    0x854830
#define CListWnd__GetSelList_x                                     0x8593F0
#define CListWnd__GetSeparatorRect_x                               0x856AC0
#define CListWnd__RemoveLine_x                                     0x8593A0
#define CListWnd__SetColors_x                                      0x8545D0
#define CListWnd__SetColumnJustification_x                         0x855040
#define CListWnd__SetColumnWidth_x                                 0x854D20
#define CListWnd__SetCurSel_x                                      0x8545B0
#define CListWnd__SetItemColor_x                                   0x858880
#define CListWnd__SetItemData_x                                    0x855400
#define CListWnd__SetItemText_x                                    0x8586C0
#define CListWnd__ShiftColumnSeparator_x                           0x858550
#define CListWnd__Sort_x                                           0x859E80
#define CListWnd__ToggleSel_x                                      0x8552D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6D0AA0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6F0940
#define CMerchantWnd__RequestBuyItem_x                             0x6F6D90
#define CMerchantWnd__RequestSellItem_x                            0x71DF50
#define CMerchantWnd__SelectBuySellSlot_x                          0x6F0BF0

// CObfuscator
#define CObfuscator__doit_x                                        0x7D1640

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x871220
#define CSidlManager__CreateLabel_x                                0x756900

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x620260
#define CSidlScreenWnd__CalculateVSBRange_x                        0x620190
#define CSidlScreenWnd__ConvertToRes_x                             0x88D050
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x85ED80
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x860120
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8601D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x85F6B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x85E860
#define CSidlScreenWnd__EnableIniStorage_x                         0x85DFB0
#define CSidlScreenWnd__GetSidlPiece_x                             0x85EA50
#define CSidlScreenWnd__Init1_x                                    0x85FE00
#define CSidlScreenWnd__LoadIniInfo_x                              0x85EE30
#define CSidlScreenWnd__LoadIniListWnd_x                           0x85E170
#define CSidlScreenWnd__LoadSidlScreen_x                           0x85F900
#define CSidlScreenWnd__StoreIniInfo_x                             0x85DB20
#define CSidlScreenWnd__StoreIniVis_x                              0x85DF40
#define CSidlScreenWnd__WndNotification_x                          0x85FB80
#define CSidlScreenWnd__GetChildItem_x                             0x85E080

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5BC2E0
#define CSkillMgr__GetSkillCap_x                                   0x5BC360

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8970C0
#define CSliderWnd__SetValue_x                                     0x897290
#define CSliderWnd__SetNumTicks_x                                  0x897A10

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x75DC60

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8877F0
#define CStmlWnd__CalculateHSBRange_x                              0x87FF70
#define CStmlWnd__CalculateVSBRange_x                              0x880000
#define CStmlWnd__CanBreakAtCharacter_x                            0x880180
#define CStmlWnd__FastForwardToEndOfTag_x                          0x880A60
#define CStmlWnd__ForceParseNow_x                                  0x888140
#define CStmlWnd__GetNextTagPiece_x                                0x880960
#define CStmlWnd__GetSTMLText_x                                    0x656910
#define CStmlWnd__GetVisibleText_x                                 0x8814B0
#define CStmlWnd__InitializeWindowVariables_x                      0x883690
#define CStmlWnd__MakeStmlColorTag_x                               0x87F1C0
#define CStmlWnd__MakeWndNotificationTag_x                         0x87F220
#define CStmlWnd__SetSTMLText_x                                    0x884EF0
#define CStmlWnd__StripFirstSTMLLines_x                            0x887490
#define CStmlWnd__UpdateHistoryString_x                            0x8823F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x88E920
#define CTabWnd__DrawCurrentPage_x                                 0x88E190
#define CTabWnd__DrawTab_x                                         0x88DF50
#define CTabWnd__GetCurrentPage_x                                  0x88E560
#define CTabWnd__GetPageInnerRect_x                                0x88DC40
#define CTabWnd__GetTabInnerRect_x                                 0x88DE40
#define CTabWnd__GetTabRect_x                                      0x88DD10
#define CTabWnd__InsertPage_x                                      0x88EC10
#define CTabWnd__SetPage_x                                         0x88E590
#define CTabWnd__SetPageRect_x                                     0x88E860
#define CTabWnd__UpdatePage_x                                      0x88EBB0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41F7A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x88AC30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x893A80

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8525D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x411020
#define CXStr__CXStr1_x                                            0x4DBFC0
#define CXStr__CXStr3_x                                            0x807060
#define CXStr__dCXStr_x                                            0x888BB0
#define CXStr__operator_equal_x                                    0x8071D0
#define CXStr__operator_equal1_x                                   0x807220
#define CXStr__operator_plus_equal1_x                              0x808300

// CXWnd 
#define CXWnd__BringToTop_x                                        0x863D40
#define CXWnd__Center_x                                            0x869F60
#define CXWnd__ClrFocus_x                                          0x863920
#define CXWnd__DoAllDrawing_x                                      0x869BD0
#define CXWnd__DrawChildren_x                                      0x869D60
#define CXWnd__DrawColoredRect_x                                   0x8640E0
#define CXWnd__DrawTooltip_x                                       0x864390
#define CXWnd__DrawTooltipAtPoint_x                                0x868B30
#define CXWnd__GetBorderFrame_x                                    0x8647E0
#define CXWnd__GetChildWndAt_x                                     0x867AB0
#define CXWnd__GetClientClipRect_x                                 0x8645A0
#define CXWnd__GetScreenClipRect_x                                 0x869230
#define CXWnd__GetScreenRect_x                                     0x864980
#define CXWnd__GetTooltipRect_x                                    0x864220
#define CXWnd__GetWindowTextA_x                                    0x411060
#define CXWnd__IsActive_x                                          0x8771B0
#define CXWnd__IsDescendantOf_x                                    0x864730
#define CXWnd__IsReallyVisible_x                                   0x867A90
#define CXWnd__IsType_x                                            0x8902C0
#define CXWnd__Move_x                                              0x867180
#define CXWnd__Move1_x                                             0x869890
#define CXWnd__ProcessTransition_x                                 0x863CF0
#define CXWnd__Refade_x                                            0x863AD0
#define CXWnd__Resize_x                                            0x864A40
#define CXWnd__Right_x                                             0x869030
#define CXWnd__SetFocus_x                                          0x8662E0
#define CXWnd__SetFont_x                                           0x863970
#define CXWnd__SetKeyTooltip_x                                     0x864CB0
#define CXWnd__SetMouseOver_x                                      0x869580
#define CXWnd__StartFade_x                                         0x863D90
#define CXWnd__GetChildItem_x                                      0x8694C0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x878AD0
#define CXWndManager__DrawWindows_x                                0x878710
#define CXWndManager__GetKeyboardFlags_x                           0x876D20
#define CXWndManager__HandleKeyboardMsg_x                          0x877630
#define CXWndManager__RemoveWnd_x                                  0x877340

// CDBStr
#define CDBStr__GetString_x                                        0x4868A0

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8D14F0
#define EQ_Character__CastSpell_x                                  0x43A790
#define EQ_Character__Cur_HP_x                                     0x449D80
#define EQ_Character__GetAACastingTimeModifier_x                   0x433600
#define EQ_Character__GetCharInfo2_x                               0x7DC530
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42C8C0
#define EQ_Character__GetFocusRangeModifier_x                      0x42CAA0
#define EQ_Character__Max_Endurance_x                              0x582F60
#define EQ_Character__Max_HP_x                                     0x443F20
#define EQ_Character__Max_Mana_x                                   0x582DA0
#define EQ_Character__doCombatAbility_x                            0x581800
#define EQ_Character__UseSkill_x                                   0x45B250
#define EQ_Character__GetConLevel_x                                0x578DF0
#define EQ_Character__IsExpansionFlag_x                            0x410560
#define EQ_Character__TotalEffect_x                                0x4388F0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x555F60
#define EQ_Item__CreateItemTagString_x                             0x7BCE10
#define EQ_Item__IsStackable_x                                     0x7B1550

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A5950
#define EQ_LoadingS__Array_x                                       0xAC7330

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x587240
#define EQ_PC__GetAltAbilityIndex_x                                0x7C56F0
#define EQ_PC__GetCombatAbility_x                                  0x7C5780
#define EQ_PC__GetCombatAbilityTimer_x                             0x7C5830
#define EQ_PC__GetItemTimerValue_x                                 0x581540
#define EQ_PC__HasLoreItem_x                                       0x57BF70

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4DC090
#define EQItemList__add_item_x                                     0x4DBFD0
#define EQItemList__delete_item_x                                  0x4DC490
#define EQItemList__FreeItemList_x                                 0x4DC390

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x485C80

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x58CE00
#define EQPlayer__dEQPlayer_x                                      0x591A60
#define EQPlayer__DoAttack_x                                       0x5A60E0
#define EQPlayer__EQPlayer_x                                       0x597330
#define EQPlayer__SetNameSpriteState_x                             0x58F270
#define EQPlayer__SetNameSpriteTint_x                              0x58CE70
#define EQPlayer__IsBodyType_j_x                                   0x8D0D90
#define EQPlayer__IsTargetable_x                                   0x8D1060

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x59A800
#define EQPlayerManager__GetSpawnByName_x                          0x59AC60

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x55C060
#define KeypressHandler__AttachKeyToEqCommand_x                    0x55C0A0
#define KeypressHandler__ClearCommandStateArray_x                  0x55BC40
#define KeypressHandler__HandleKeyDown_x                           0x55A5A0
#define KeypressHandler__HandleKeyUp_x                             0x55A8C0
#define KeypressHandler__SaveKeymapping_x                          0x55BD10

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6C8F00
#define MapViewMap__SaveEx_x                                       0x6CC7B0

#define PlayerPointManager__GetAltCurrency_x                       0x7D6690

// StringTable 
#define StringTable__getString_x                                   0x7D18E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x585B30
