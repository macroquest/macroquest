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
#define __ExpectedVersionDate                                     "Jun 19 2014"
#define __ExpectedVersionTime                                     "17:24:59"
#define __ActualVersionDate_x                                      0xA49568
#define __ActualVersionTime_x                                      0xA49574

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x572520
#define __MemChecker1_x                                            0x834230
#define __MemChecker2_x                                            0x609320
#define __MemChecker3_x                                            0x609270
#define __MemChecker4_x                                            0x7B90B0
#define __EncryptPad0_x                                            0xBB3000
#define __EncryptPad1_x                                            0xD2A700
#define __EncryptPad2_x                                            0xBF9A50
#define __EncryptPad3_x                                            0xBF9650
#define __EncryptPad4_x                                            0xD08550
#define __AC1_x                                                    0x7769F5
#define __AC2_x                                                    0x528BD7
#define __AC3_x                                                    0x53D2C0
#define __AC4_x                                                    0x5433F0
#define __AC5_x                                                    0x54FA21
#define __AC6_x                                                    0x553552
#define __AC7_x                                                    0x5494FC
#define __AC1_Data                                                 0x11112111
// Direct Input
#define DI8__Main_x                                                0x10D9FD0
#define DI8__Keyboard_x                                            0x10D9FD4
#define DI8__Mouse_x                                               0x10D9FD8
#define __AltTimerReady_x                                          0xF39D79
#define __Attack_x                                                 0xFCCB7A
#define __Autofire_x                                               0xFCCB7B
#define __BindList_x                                               0xB77840
#define __Clicks_x                                                 0xF489C0
#define __CommandList_x                                            0xB7B8E0
#define __CurrentMapLabel_x                                        0x10DFC50
#define __CurrentSocial_x                                          0xB3DA50
#define __DoAbilityList_x                                          0xF7F128
#define __do_loot_x                                                0x4F1350
#define __DrawHandler_x                                            0x17421B4
#define __GroupCount_x                                             0xF39452

#define __Guilds_x                                                 0xF3EF40
#define __gWorld_x                                                 0xF3B90C
#define __HotkeyPage_x                                             0xFC5B28
#define __HWnd_x                                                   0xFD1ED8
#define __InChatMode_x                                             0xF488EC
#define __LastTell_x                                               0xF4A830
#define __LMouseHeldTime_x                                         0xF48A2C
#define __Mouse_x                                                  0x10D9FDC
#define __MouseLook_x                                              0xF48986
#define __MouseEventTime_x                                         0xFCD364
#define __NetStatusToggle_x                                        0xF48989
#define __PCNames_x                                                0xF49E70
#define __RangeAttackReady_x                                       0xF49B08
#define __RMouseHeldTime_x                                         0xF48A28
#define __RunWalkState_x                                           0xF488F0
#define __ScreenMode_x                                             0xE87E50
#define __ScreenX_x                                                0xF488A4
#define __ScreenY_x                                                0xF488A0
#define __ScreenXMax_x                                             0xF488A8
#define __ScreenYMax_x                                             0xF488AC
#define __ServerHost_x                                             0xF3939C
#define __ServerName_x                                             0xF7F0E8
#define __ShiftKeyDown_x                                           0xF48F90
#define __ShowNames_x                                              0xF49D14
#define __Socials_x                                                0xF7F1E8
#define __SubscriptionType_x                                       0x1109988
#define __TargetAggroHolder_x                                      0x10E1E68
#define __GroupAggro_x                                             0x10E1EA8
#define __LoginName_x                                              0xFD0AB0
#define __Inviter_x                                                0xFCCAF8


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF3B9F8
#define instEQZoneInfo_x                                           0xF48B7C
#define instKeypressHandler_x                                      0xFCD348
#define pinstActiveBanker_x                                        0xF3B9B0
#define pinstActiveCorpse_x                                        0xF3B9B4
#define pinstActiveGMaster_x                                       0xF3B9B8
#define pinstActiveMerchant_x                                      0xF3B9AC
#define pinstAggroInfo_x                                           0xD4C438
#define pinstAltAdvManager_x                                       0xE88F20
#define pinstAuraMgr_x                                             0xD56300
#define pinstBandageTarget_x                                       0xF3B998
#define pinstCamActor_x                                            0xE8882C
#define pinstCDBStr_x                                              0xE87DE4
#define pinstCDisplay_x                                            0xF3B9C0
#define pinstCEverQuest_x                                          0x10DA154
#define pinstCharData_x                                            0xF3B97C
#define pinstCharSpawn_x                                           0xF3B9A4
#define pinstControlledMissile_x                                   0xF3B978
#define pinstControlledPlayer_x                                    0xF3B9A4
#define pinstCSidlManager_x                                        0x1741620
#define pinstCXWndManager_x                                        0x1741618
#define instDynamicZone_x                                          0xF48738
#define pinstDZMember_x                                            0xF48848
#define pinstDZTimerInfo_x                                         0xF4884C
#define pinstEQItemList_x                                          0xF380D4
#define instEQMisc_x                                               0xB59060
#define pinstEQSoundManager_x                                      0xE89220
#define instExpeditionLeader_x                                     0xF48782
#define instExpeditionName_x                                       0xF487C2
#define pinstGroup_x                                               0xF3944E
#define pinstImeManager_x                                          0x1741624
#define pinstLocalPlayer_x                                         0xF3B990
#define pinstMercenaryData_x                                       0xFCD998
#define pinstMercAltAbilities_x                                    0xE89140
#define pinstModelPlayer_x                                         0xF3B9BC
#define pinstPCData_x                                              0xF3B97C
#define pinstSkillMgr_x                                            0xFCE7D0
#define pinstSpawnManager_x                                        0xFCE0B8
#define pinstSpellManager_x                                        0xFCE918
#define pinstSpellSets_x                                           0xFC5B8C
#define pinstStringTable_x                                         0xF3B924
#define pinstSwitchManager_x                                       0xF38FE0
#define pinstTarget_x                                              0xF3B9A8
#define pinstTargetObject_x                                        0xF3B980
#define pinstTargetSwitch_x                                        0xF3B984
#define pinstTaskMember_x                                          0xE87D30
#define pinstTrackTarget_x                                         0xF3B99C
#define pinstTradeTarget_x                                         0xF3B98C
#define instTributeActive_x                                        0xB59085
#define pinstViewActor_x                                           0xE88828
#define pinstWorldData_x                                           0xF3B960


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD4C918
#define pinstCAudioTriggersWindow_x                                0xD4C7A8
#define pinstCCharacterSelect_x                                    0xE886D4
#define pinstCFacePick_x                                           0xE88484
#define pinstCNoteWnd_x                                            0xE8868C
#define pinstCBookWnd_x                                            0xE88694
#define pinstCPetInfoWnd_x                                         0xE88698
#define pinstCTrainWnd_x                                           0xE8869C
#define pinstCSkillsWnd_x                                          0xE886A0
#define pinstCSkillsSelectWnd_x                                    0xE886A4
#define pinstCCombatSkillSelectWnd_x                               0xE886A8
#define pinstCFriendsWnd_x                                         0xE886AC
#define pinstCAuraWnd_x                                            0xE886B0
#define pinstCRespawnWnd_x                                         0xE886B4
#define pinstCBandolierWnd_x                                       0xE886B8
#define pinstCPotionBeltWnd_x                                      0xE886BC
#define pinstCAAWnd_x                                              0xE886C0
#define pinstCGroupSearchFiltersWnd_x                              0xE886C4
#define pinstCLoadskinWnd_x                                        0xE886C8
#define pinstCAlarmWnd_x                                           0xE886CC
#define pinstCMusicPlayerWnd_x                                     0xE886D0
#define pinstCMailWnd_x                                            0xE886D8
#define pinstCMailCompositionWnd_x                                 0xE886DC
#define pinstCMailAddressBookWnd_x                                 0xE886E0
#define pinstCRaidWnd_x                                            0xE886E8
#define pinstCRaidOptionsWnd_x                                     0xE886EC
#define pinstCBreathWnd_x                                          0xE886F0
#define pinstCMapViewWnd_x                                         0xE886F4
#define pinstCMapToolbarWnd_x                                      0xE886F8
#define pinstCEditLabelWnd_x                                       0xE886FC
#define pinstCTargetWnd_x                                          0xE88700
#define pinstCColorPickerWnd_x                                     0xE88704
#define pinstCPlayerWnd_x                                          0xE88708
#define pinstCOptionsWnd_x                                         0xE8870C
#define pinstCBuffWindowNORMAL_x                                   0xE88710
#define pinstCBuffWindowSHORT_x                                    0xE88714
#define pinstCharacterCreation_x                                   0xE88718
#define pinstCCursorAttachment_x                                   0xE8871C
#define pinstCCastingWnd_x                                         0xE88720
#define pinstCCastSpellWnd_x                                       0xE88724
#define pinstCSpellBookWnd_x                                       0xE88728
#define pinstCInventoryWnd_x                                       0xE8872C
#define pinstCBankWnd_x                                            0xE88730
#define pinstCQuantityWnd_x                                        0xE88734
#define pinstCLootWnd_x                                            0xE88738
#define pinstCActionsWnd_x                                         0xE8873C
#define pinstCCombatAbilityWnd_x                                   0xE88740
#define pinstCMerchantWnd_x                                        0xE88744
#define pinstCTradeWnd_x                                           0xE88748
#define pinstCSelectorWnd_x                                        0xE8874C
#define pinstCBazaarWnd_x                                          0xE88750
#define pinstCBazaarSearchWnd_x                                    0xE88754
#define pinstCGiveWnd_x                                            0xE88770
#define pinstCTrackingWnd_x                                        0xE88778
#define pinstCInspectWnd_x                                         0xE8877C
#define pinstCSocialEditWnd_x                                      0xE88780
#define pinstCFeedbackWnd_x                                        0xE88784
#define pinstCBugReportWnd_x                                       0xE88788
#define pinstCVideoModesWnd_x                                      0xE8878C
#define pinstCTextEntryWnd_x                                       0xE88794
#define pinstCFileSelectionWnd_x                                   0xE88798
#define pinstCCompassWnd_x                                         0xE8879C
#define pinstCPlayerNotesWnd_x                                     0xE887A0
#define pinstCGemsGameWnd_x                                        0xE887A4
#define pinstCTimeLeftWnd_x                                        0xE887A8
#define pinstCPetitionQWnd_x                                       0xE887BC
#define pinstCSoulmarkWnd_x                                        0xE887C0
#define pinstCStoryWnd_x                                           0xE887C4
#define pinstCJournalTextWnd_x                                     0xE887C8
#define pinstCJournalCatWnd_x                                      0xE887CC
#define pinstCBodyTintWnd_x                                        0xE887D0
#define pinstCServerListWnd_x                                      0xE887D4
#define pinstCAvaZoneWnd_x                                         0xE887E0
#define pinstCBlockedBuffWnd_x                                     0xE887E4
#define pinstCBlockedPetBuffWnd_x                                  0xE887E8
#define pinstCInvSlotMgr_x                                         0xE88820
#define pinstCContainerMgr_x                                       0xE88824
#define pinstCAdventureLeaderboardWnd_x                            0x10DAD28
#define pinstCAdventureRequestWnd_x                                0x10DADA0
#define pinstCAltStorageWnd_x                                      0x10DB080
#define pinstCAdventureStatsWnd_x                                  0x10DAE18
#define pinstCBarterMerchantWnd_x                                  0x10DBC68
#define pinstCBarterSearchWnd_x                                    0x10DBCE0
#define pinstCBarterWnd_x                                          0x10DBD58
#define pinstCChatManager_x                                        0x10DC3E8
#define pinstCDynamicZoneWnd_x                                     0x10DC898
#define pinstCEQMainWnd_x                                          0x10DCA30
#define pinstCFellowshipWnd_x                                      0x10DC82C
#define pinstCFindLocationWnd_x                                    0x10DCD00
#define pinstCGroupSearchWnd_x                                     0x10DCFD0
#define pinstCGroupWnd_x                                           0x10DD048
#define pinstCGuildBankWnd_x                                       0x10DD0C0
#define pinstCGuildMgmtWnd_x                                       0x10DF1B0
#define pinstCHotButtonWnd_x                                       0x10DF27C
#define pinstCHotButtonWnd1_x                                      0x10DF27C
#define pinstCHotButtonWnd2_x                                      0x10DF280
#define pinstCHotButtonWnd3_x                                      0x10DF284
#define pinstCHotButtonWnd4_x                                      0x10DF2A8
#define pinstCItemDisplayManager_x                                 0x10DF5A0
#define pinstCItemExpTransferWnd_x                                 0x10DF61C
#define pinstCLFGuildWnd_x                                         0x10DF8F8
#define pinstCMIZoneSelectWnd_x                                    0x10DFEE0
#define pinstCConfirmationDialog_x                                 0x10E05E8
#define pinstCPopupWndManager_x                                    0x10E05E8
#define pinstCProgressionSelectionWnd_x                            0x10E06D8
#define pinstCPvPStatsWnd_x                                        0x10E07C8
#define pinstCSystemInfoDialogBox_x                                0x10E0ED0
#define pinstCTaskWnd_x                                            0x10E2268
#define pinstCTaskTemplateSelectWnd_x                              0x10E21F0
#define pinstCTipWndOFDAY_x                                        0x10E24C0
#define pinstCTipWndCONTEXT_x                                      0x10E24C4
#define pinstCTitleWnd_x                                           0x10E2540
#define pinstCContextMenuManager_x                                 0x1741234
#define pinstCVoiceMacroWnd_x                                      0xFCEF80
#define pinstCHtmlWnd_x                                            0xFCF078
#define pinstIconCache_x                                           0x10DCA04
#define pinstCTradeskillWnd_x                                      0x10E2640

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x508090
#define __ConvertItemTags_x                                        0x4F6010
#define __ExecuteCmd_x                                             0x4E0C90
#define __EQGetTime_x                                              0x834D90
#define __get_melee_range_x                                        0x4E7890
#define __GetGaugeValueFromEQ_x                                    0x775750
#define __GetLabelFromEQ_x                                         0x776980
#define __GetXTargetType_x                                         0x8F1480
#define __LoadFrontEnd_x                                           0x6089D0
#define __NewUIINI_x                                               0x7750A0
#define __ProcessGameEvents_x                                      0x54B640
#define CrashDetected_x                                            0x60A4A0
#define DrawNetStatus_x                                            0x581CB0
#define Util__FastTime_x                                           0x8340A0
#define Expansion_HoT_x                                            0xF49C74
#define __HelpPath_x                                               0xFCD0D0
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A5340
#define AltAdvManager__IsAbilityReady_x                            0x4A53B0
#define AltAdvManager__GetAltAbility_x                             0x4A5770

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4523F0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6387E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6469E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x561D70

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x661920
#define CChatManager__InitContextMenu_x                            0x662440

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x81AC60
#define CChatService__GetFriendName_x                              0x81AC70

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6671E0
#define CChatWindow__Clear_x                                       0x666D90
#define CChatWindow__WndNotification_x                             0x667720

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8930C0
#define CComboWnd__Draw_x                                          0x893290
#define CComboWnd__GetCurChoice_x                                  0x892EE0
#define CComboWnd__GetListRect_x                                   0x893530
#define CComboWnd__GetTextRect_x                                   0x893120
#define CComboWnd__InsertChoice_x                                  0x8935A0
#define CComboWnd__SetColors_x                                     0x892E70
#define CComboWnd__SetChoice_x                                     0x892EA0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x670890
#define CContainerWnd__vftable_x                                   0xA52D18

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x493CC0
#define CDisplay__GetClickedActor_x                                0x48C8E0
#define CDisplay__GetUserDefinedColor_x                            0x48B1A0
#define CDisplay__GetWorldFilePath_x                               0x48A5A0
#define CDisplay__is3dON_x                                         0x489970
#define CDisplay__ReloadUI_x                                       0x49F090
#define CDisplay__WriteTextHD2_x                                   0x490130

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8B4BC0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8A3AB0
#define CEditWnd__GetCharIndexPt_x                                 0x8A4AC0
#define CEditWnd__GetDisplayString_x                               0x8A3C60
#define CEditWnd__GetHorzOffset_x                                  0x8A3FA0
#define CEditWnd__GetLineForPrintableChar_x                        0x8A4590
#define CEditWnd__GetSelStartPt_x                                  0x8A4D70
#define CEditWnd__GetSTMLSafeText_x                                0x8A4130
#define CEditWnd__PointFromPrintableChar_x                         0x8A4680
#define CEditWnd__SelectableCharFromPoint_x                        0x8A4800
#define CEditWnd__SetEditable_x                                    0x8A4100

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x529320
#define CEverQuest__DoTellWindow_x                                 0x52ECB0
#define CEverQuest__DropHeldItemOnGround_x                         0x537740
#define CEverQuest__dsp_chat_x                                     0x530450
#define CEverQuest__Emote_x                                        0x5306B0
#define CEverQuest__EnterZone_x                                    0x543580
#define CEverQuest__GetBodyTypeDesc_x                              0x525C50
#define CEverQuest__GetClassDesc_x                                 0x52B820
#define CEverQuest__GetClassThreeLetterCode_x                      0x52BE20
#define CEverQuest__GetDeityDesc_x                                 0x526530
#define CEverQuest__GetLangDesc_x                                  0x525FE0
#define CEverQuest__GetRaceDesc_x                                  0x52BFE0
#define CEverQuest__InterpretCmd_x                                 0x530F90
#define CEverQuest__LeftClickedOnPlayer_x                          0x547970
#define CEverQuest__LMouseUp_x                                     0x549C60
#define CEverQuest__RightClickedOnPlayer_x                         0x548470
#define CEverQuest__RMouseUp_x                                     0x5494B0
#define CEverQuest__SetGameState_x                                 0x5299D0
#define CEverQuest__UPCNotificationFlush_x                         0x532130

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x681340
#define CGaugeWnd__CalcLinesFillRect_x                             0x6813A0
#define CGaugeWnd__Draw_x                                          0x6817D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x424370

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69DAC0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6A9840
#define CInvSlotMgr__MoveItem_x                                    0x6AA770
#define CInvSlotMgr__SelectSlot_x                                  0x6A98F0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6A8B70
#define CInvSlot__SliderComplete_x                                 0x6A69C0
#define CInvSlot__GetItemBase_x                                    0x6A5E40

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6AB540

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7723E0
#define CItemDisplayWnd__UpdateStrings_x                           0x6AC880

// CLabel 
#define CLabel__Draw_x                                             0x6C7300

// CListWnd 
#define CListWnd__AddColumn_x                                      0x881110
#define CListWnd__AddColumn1_x                                     0x880900
#define CListWnd__AddLine_x                                        0x8803B0
#define CListWnd__AddString_x                                      0x8805C0
#define CListWnd__CalculateFirstVisibleLine_x                      0x87D480
#define CListWnd__CalculateVSBRange_x                              0x87F5A0
#define CListWnd__ClearAllSel_x                                    0x87C740
#define CListWnd__CloseAndUpdateEditWindow_x                       0x87FF80
#define CListWnd__Compare_x                                        0x87DF80
#define CListWnd__Draw_x                                           0x87F200
#define CListWnd__DrawColumnSeparators_x                           0x87F090
#define CListWnd__DrawHeader_x                                     0x87CA50
#define CListWnd__DrawItem_x                                       0x87E5D0
#define CListWnd__DrawLine_x                                       0x87ED30
#define CListWnd__DrawSeparator_x                                  0x87F130
#define CListWnd__EnsureVisible_x                                  0x87D5E0
#define CListWnd__ExtendSel_x                                      0x87E4E0
#define CListWnd__GetColumnMinWidth_x                              0x87C160
#define CListWnd__GetColumnWidth_x                                 0x87C080
#define CListWnd__GetCurSel_x                                      0x87B940
#define CListWnd__GetItemAtPoint_x                                 0x87D870
#define CListWnd__GetItemAtPoint1_x                                0x87D8E0
#define CListWnd__GetItemData_x                                    0x87BB90
#define CListWnd__GetItemHeight_x                                  0x87D0E0
#define CListWnd__GetItemIcon_x                                    0x87BD70
#define CListWnd__GetItemRect_x                                    0x87D6B0
#define CListWnd__GetItemText_x                                    0x87BC20
#define CListWnd__GetSelList_x                                     0x8807F0
#define CListWnd__GetSeparatorRect_x                               0x87DEA0
#define CListWnd__RemoveLine_x                                     0x8807A0
#define CListWnd__SetColors_x                                      0x87B9A0
#define CListWnd__SetColumnJustification_x                         0x87C430
#define CListWnd__SetColumnWidth_x                                 0x87C110
#define CListWnd__SetCurSel_x                                      0x87B980
#define CListWnd__SetItemColor_x                                   0x87FC60
#define CListWnd__SetItemData_x                                    0x87C7F0
#define CListWnd__SetItemText_x                                    0x87FAA0
#define CListWnd__ShiftColumnSeparator_x                           0x87F930
#define CListWnd__Sort_x                                           0x88127D
#define CListWnd__ToggleSel_x                                      0x87C6C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6E0670

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x701400
#define CMerchantWnd__RequestBuyItem_x                             0x707CF0
#define CMerchantWnd__RequestSellItem_x                            0x72F900
#define CMerchantWnd__SelectRecoverySlot_x                         0x7016B0
#define CMerchantWnd__SelectBuySellSlot_x                          0x700910
#define CMerchantWnd__ActualSelect_x                               0x7050F0

// CObfuscator
#define CObfuscator__doit_x                                        0x7FB770

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x898890
#define CSidlManager__CreateLabel_x                                0x7683B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x62F980
#define CSidlScreenWnd__CalculateVSBRange_x                        0x62F8A0
#define CSidlScreenWnd__ConvertToRes_x                             0x8B4AA0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x886250
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x887730
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8877E0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x886CA0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x885D30
#define CSidlScreenWnd__EnableIniStorage_x                         0x885470
#define CSidlScreenWnd__GetSidlPiece_x                             0x885F20
#define CSidlScreenWnd__Init1_x                                    0x887400
#define CSidlScreenWnd__LoadIniInfo_x                              0x886300
#define CSidlScreenWnd__LoadIniListWnd_x                           0x885630
#define CSidlScreenWnd__LoadSidlScreen_x                           0x886EF0
#define CSidlScreenWnd__StoreIniInfo_x                             0x884F40
#define CSidlScreenWnd__StoreIniVis_x                              0x885400
#define CSidlScreenWnd__WndNotification_x                          0x887180
#define CSidlScreenWnd__GetChildItem_x                             0x885540
#define CSidlScreenWnd__HandleLButtonUp_x                          0x88C0D0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5CA980
#define CSkillMgr__GetSkillCap_x                                   0x5CAB20

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8BEB00
#define CSliderWnd__SetValue_x                                     0x8BECD0
#define CSliderWnd__SetNumTicks_x                                  0x8BF450

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x770080

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8AF140
#define CStmlWnd__CalculateHSBRange_x                              0x8A7650
#define CStmlWnd__CalculateVSBRange_x                              0x8A76E0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8A7860
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8A8140
#define CStmlWnd__ForceParseNow_x                                  0x8AFA90
#define CStmlWnd__GetNextTagPiece_x                                0x8A8040
#define CStmlWnd__GetSTMLText_x                                    0x666630
#define CStmlWnd__GetVisibleText_x                                 0x8A8B90
#define CStmlWnd__InitializeWindowVariables_x                      0x8AAF20
#define CStmlWnd__MakeStmlColorTag_x                               0x8A6950
#define CStmlWnd__MakeWndNotificationTag_x                         0x8A69B0
#define CStmlWnd__SetSTMLText_x                                    0x8AC790
#define CStmlWnd__StripFirstSTMLLines_x                            0x8AEDE0
#define CStmlWnd__UpdateHistoryString_x                            0x8A9AD0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8B6290
#define CTabWnd__DrawCurrentPage_x                                 0x8B5B00
#define CTabWnd__DrawTab_x                                         0x8B58D0
#define CTabWnd__GetCurrentPage_x                                  0x8B5ED0
#define CTabWnd__GetPageInnerRect_x                                0x8B55C0
#define CTabWnd__GetTabInnerRect_x                                 0x8B57C0
#define CTabWnd__GetTabRect_x                                      0x8B5690
#define CTabWnd__InsertPage_x                                      0x8B6580
#define CTabWnd__SetPage_x                                         0x8B5F00
#define CTabWnd__SetPageRect_x                                     0x8B61D0
#define CTabWnd__UpdatePage_x                                      0x8B6520

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4200F0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B2640

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8BB4C0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x879A90

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x411770
#define CXStr__CXStr1_x                                            0x87AB60
#define CXStr__CXStr3_x                                            0x831130
#define CXStr__dCXStr_x                                            0x8B0570
#define CXStr__operator_equal_x                                    0x8312A0
#define CXStr__operator_equal1_x                                   0x8312F0
#define CXStr__operator_plus_equal1_x                              0x8323D0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x88B2E0
#define CXWnd__Center_x                                            0x8914D0
#define CXWnd__ClrFocus_x                                          0x88AEC0
#define CXWnd__DoAllDrawing_x                                      0x891120
#define CXWnd__DrawChildren_x                                      0x8912C0
#define CXWnd__DrawColoredRect_x                                   0x88B690
#define CXWnd__DrawTooltip_x                                       0x88B940
#define CXWnd__DrawTooltipAtPoint_x                                0x8900F0
#define CXWnd__GetBorderFrame_x                                    0x88BDB0
#define CXWnd__GetChildWndAt_x                                     0x88F090
#define CXWnd__GetClientClipRect_x                                 0x88BB60
#define CXWnd__GetScreenClipRect_x                                 0x8907E0
#define CXWnd__GetScreenRect_x                                     0x88BF70
#define CXWnd__GetTooltipRect_x                                    0x88B7D0
#define CXWnd__GetWindowTextA_x                                    0x4117B0
#define CXWnd__IsActive_x                                          0x89E7F0
#define CXWnd__IsDescendantOf_x                                    0x88BCF0
#define CXWnd__IsReallyVisible_x                                   0x88F070
#define CXWnd__IsType_x                                            0x8B7CE0
#define CXWnd__Move_x                                              0x88E7D0
#define CXWnd__Move1_x                                             0x890DE0
#define CXWnd__ProcessTransition_x                                 0x88B290
#define CXWnd__Refade_x                                            0x88B060
#define CXWnd__Resize_x                                            0x88C030
#define CXWnd__Right_x                                             0x8905E0
#define CXWnd__SetFocus_x                                          0x88D930
#define CXWnd__SetFont_x                                           0x88AF10
#define CXWnd__SetKeyTooltip_x                                     0x88C2A0
#define CXWnd__SetMouseOver_x                                      0x890AF0
#define CXWnd__StartFade_x                                         0x88B330
#define CXWnd__GetChildItem_x                                      0x890A30

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A00E0
#define CXWndManager__DrawWindows_x                                0x89FD30
#define CXWndManager__GetKeyboardFlags_x                           0x89E330
#define CXWndManager__HandleKeyboardMsg_x                          0x89EC80
#define CXWndManager__RemoveWnd_x                                  0x89E980

// CDBStr
#define CDBStr__GetString_x                                        0x487E30

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8EDCE0
#define EQ_Character__CastSpell_x                                  0x43C030
#define EQ_Character__Cur_HP_x                                     0x451AB0
#define EQ_Character__GetAACastingTimeModifier_x                   0x435100
#define EQ_Character__GetCharInfo2_x                               0x8059A0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42D480
#define EQ_Character__GetFocusRangeModifier_x                      0x42D660
#define EQ_Character__Max_Endurance_x                              0x5936F0
#define EQ_Character__Max_HP_x                                     0x4480D0
#define EQ_Character__Max_Mana_x                                   0x593520
#define EQ_Character__doCombatAbility_x                            0x590D50
#define EQ_Character__UseSkill_x                                   0x45C5E0
#define EQ_Character__GetConLevel_x                                0x586310
#define EQ_Character__IsExpansionFlag_x                            0x410CB0
#define EQ_Character__TotalEffect_x                                0x43A160

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x566D80
#define EQ_Item__CreateItemTagString_x                             0x7E6760
#define EQ_Item__IsStackable_x                                     0x7DACF0
#define EQ_Item__GetImageNum_x                                     0x7DD950

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A7430
#define EQ_LoadingS__Array_x                                       0xB66688

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x594D40
#define EQ_PC__GetAltAbilityIndex_x                                0x7EE8D0
#define EQ_PC__GetCombatAbility_x                                  0x7EE960
#define EQ_PC__GetCombatAbilityTimer_x                             0x7EEA10
#define EQ_PC__GetItemTimerValue_x                                 0x58EB20
#define EQ_PC__HasLoreItem_x                                       0x5894B0
#define EQ_PC__AlertInventoryChanged_x                             0x5862E0
#define EQ_PC__GetPcZoneClient_x                                   0x5AEE60
// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E5840
#define EQItemList__add_item_x                                     0x4E5780
#define EQItemList__delete_item_x                                  0x4E5C40
#define EQItemList__FreeItemList_x                                 0x4E5B40

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487340

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x59A190
#define EQPlayer__dEQPlayer_x                                      0x5A2D00
#define EQPlayer__DoAttack_x                                       0x5B4C40
#define EQPlayer__EQPlayer_x                                       0x5A5150
#define EQPlayer__SetNameSpriteState_x                             0x59FB30
#define EQPlayer__SetNameSpriteTint_x                              0x59B4C0
#define EQPlayer__IsBodyType_j_x                                   0x8ECF90
#define EQPlayer__IsTargetable_x                                   0x8ED7C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5A93F0
#define EQPlayerManager__GetSpawnByName_x                          0x5A9850

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56CFA0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56CFE0
#define KeypressHandler__ClearCommandStateArray_x                  0x56CB80
#define KeypressHandler__HandleKeyDown_x                           0x56B4D0
#define KeypressHandler__HandleKeyUp_x                             0x56B7F0
#define KeypressHandler__SaveKeymapping_x                          0x56CC50

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6D8A50
#define MapViewMap__SaveEx_x                                       0x6DC330

#define PlayerPointManager__GetAltCurrency_x                       0x7FFAC0

// StringTable 
#define StringTable__getString_x                                   0x7FBA10

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5931A0

//Doors
#define EQSwitch__UseSwitch_x                                      0x522FD0

//IconCache
#define IconCache__GetIcon_x                                       0x676B70

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66DBD0
#define CContainerMgr__CloseContainer_x                            0x66E3E0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x738890

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x560850

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B5B20
#define EQ_Spell__SpellAffects_x                                   0x4B5BC0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B5BF0
#define CharacterZoneClient__CalcAffectChange_x                    0x436420
#define CLootWnd__LootAll_x                                        0x6CE640
#define CTargetWnd__GetBuffCaster_x                                0x77DC80
