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
#define __ExpectedVersionDate                                     "Jun 13 2014"
#define __ExpectedVersionTime                                     "18:39:10"
#define __ActualVersionDate_x                                      0xA48580
#define __ActualVersionTime_x                                      0xA4858C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x571D00
#define __MemChecker1_x                                            0x834030
#define __MemChecker2_x                                            0x608540
#define __MemChecker3_x                                            0x608490
#define __MemChecker4_x                                            0x7B8C90
#define __EncryptPad0_x                                            0xBB2000
#define __EncryptPad1_x                                            0xD29700
#define __EncryptPad2_x                                            0xBF8A50
#define __EncryptPad3_x                                            0xBF8650
#define __EncryptPad4_x                                            0xD07550
#define __AC1_x                                                    0x775EA5
#define __AC2_x                                                    0x528427
#define __AC3_x                                                    0x53CB10
#define __AC4_x                                                    0x542C40
#define __AC5_x                                                    0x54F271
#define __AC6_x                                                    0x552DB2
#define __AC7_x                                                    0x548D4C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10D8FD0
#define DI8__Keyboard_x                                            0x10D8FD4
#define DI8__Mouse_x                                               0x10D8FD8
#define __AltTimerReady_x                                          0xF38D79
#define __Attack_x                                                 0xFCBB7A
#define __Autofire_x                                               0xFCBB7B
#define __BindList_x                                               0xB76840
#define __Clicks_x                                                 0xF479C0
#define __CommandList_x                                            0xB7A8E0
#define __CurrentMapLabel_x                                        0x10DEC50
#define __CurrentSocial_x                                          0xB3CA50
#define __DoAbilityList_x                                          0xF7E128
#define __do_loot_x                                                0x4F0CB0
#define __DrawHandler_x                                            0x17411B4
#define __GroupCount_x                                             0xF38452

#define __Guilds_x                                                 0xF3DF40
#define __gWorld_x                                                 0xF3A90C
#define __HotkeyPage_x                                             0xFC4B28
#define __HWnd_x                                                   0xFD0ED8
#define __InChatMode_x                                             0xF478EC
#define __LastTell_x                                               0xF49830
#define __LMouseHeldTime_x                                         0xF47A2C
#define __Mouse_x                                                  0x10D8FDC
#define __MouseLook_x                                              0xF47986
#define __MouseEventTime_x                                         0xFCC364
#define __NetStatusToggle_x                                        0xF47989
#define __PCNames_x                                                0xF48E70
#define __RangeAttackReady_x                                       0xF48B08
#define __RMouseHeldTime_x                                         0xF47A28
#define __RunWalkState_x                                           0xF478F0
#define __ScreenMode_x                                             0xE86E50
#define __ScreenX_x                                                0xF478A4
#define __ScreenY_x                                                0xF478A0
#define __ScreenXMax_x                                             0xF478A8
#define __ScreenYMax_x                                             0xF478AC
#define __ServerHost_x                                             0xF3839C
#define __ServerName_x                                             0xF7E0E8
#define __ShiftKeyDown_x                                           0xF47F90
#define __ShowNames_x                                              0xF48D14
#define __Socials_x                                                0xF7E1E8
#define __SubscriptionType_x                                       0x1108988
#define __TargetAggroHolder_x                                      0x10E0E68
#define __GroupAggro_x                                             0x10E0EA8
#define __LoginName_x                                              0xFCFAB0
#define __Inviter_x                                                0xFCBAF8


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF3A9F8
#define instEQZoneInfo_x                                           0xF47B7C
#define instKeypressHandler_x                                      0xFCC348
#define pinstActiveBanker_x                                        0xF3A9B0
#define pinstActiveCorpse_x                                        0xF3A9B4
#define pinstActiveGMaster_x                                       0xF3A9B8
#define pinstActiveMerchant_x                                      0xF3A9AC
#define pinstAggroInfo_x                                           0xD4B438
#define pinstAltAdvManager_x                                       0xE87F20
#define pinstAuraMgr_x                                             0xD55300
#define pinstBandageTarget_x                                       0xF3A998
#define pinstCamActor_x                                            0xE8782C
#define pinstCDBStr_x                                              0xE86DE4
#define pinstCDisplay_x                                            0xF3A9C0
#define pinstCEverQuest_x                                          0x10D9154
#define pinstCharData_x                                            0xF3A97C
#define pinstCharSpawn_x                                           0xF3A9A4
#define pinstControlledMissile_x                                   0xF3A978
#define pinstControlledPlayer_x                                    0xF3A9A4
#define pinstCSidlManager_x                                        0x1740620
#define pinstCXWndManager_x                                        0x1740618
#define instDynamicZone_x                                          0xF47738
#define pinstDZMember_x                                            0xF47848
#define pinstDZTimerInfo_x                                         0xF4784C
#define pinstEQItemList_x                                          0xF370D4
#define instEQMisc_x                                               0xB58060
#define pinstEQSoundManager_x                                      0xE88220
#define instExpeditionLeader_x                                     0xF47782
#define instExpeditionName_x                                       0xF477C2
#define pinstGroup_x                                               0xF3844E
#define pinstImeManager_x                                          0x1740624
#define pinstLocalPlayer_x                                         0xF3A990
#define pinstMercenaryData_x                                       0xFCC998
#define pinstMercAltAbilities_x                                    0xE88140
#define pinstModelPlayer_x                                         0xF3A9BC
#define pinstPCData_x                                              0xF3A97C
#define pinstSkillMgr_x                                            0xFCD7D0
#define pinstSpawnManager_x                                        0xFCD0B8
#define pinstSpellManager_x                                        0xFCD918
#define pinstSpellSets_x                                           0xFC4B8C
#define pinstStringTable_x                                         0xF3A924
#define pinstSwitchManager_x                                       0xF37FE0
#define pinstTarget_x                                              0xF3A9A8
#define pinstTargetObject_x                                        0xF3A980
#define pinstTargetSwitch_x                                        0xF3A984
#define pinstTaskMember_x                                          0xE86D30
#define pinstTrackTarget_x                                         0xF3A99C
#define pinstTradeTarget_x                                         0xF3A98C
#define instTributeActive_x                                        0xB58085
#define pinstViewActor_x                                           0xE87828
#define pinstWorldData_x                                           0xF3A960


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD4B918
#define pinstCAudioTriggersWindow_x                                0xD4B7A8
#define pinstCCharacterSelect_x                                    0xE876D4
#define pinstCFacePick_x                                           0xE87484
#define pinstCNoteWnd_x                                            0xE8768C
#define pinstCBookWnd_x                                            0xE87694
#define pinstCPetInfoWnd_x                                         0xE87698
#define pinstCTrainWnd_x                                           0xE8769C
#define pinstCSkillsWnd_x                                          0xE876A0
#define pinstCSkillsSelectWnd_x                                    0xE876A4
#define pinstCCombatSkillSelectWnd_x                               0xE876A8
#define pinstCFriendsWnd_x                                         0xE876AC
#define pinstCAuraWnd_x                                            0xE876B0
#define pinstCRespawnWnd_x                                         0xE876B4
#define pinstCBandolierWnd_x                                       0xE876B8
#define pinstCPotionBeltWnd_x                                      0xE876BC
#define pinstCAAWnd_x                                              0xE876C0
#define pinstCGroupSearchFiltersWnd_x                              0xE876C4
#define pinstCLoadskinWnd_x                                        0xE876C8
#define pinstCAlarmWnd_x                                           0xE876CC
#define pinstCMusicPlayerWnd_x                                     0xE876D0
#define pinstCMailWnd_x                                            0xE876D8
#define pinstCMailCompositionWnd_x                                 0xE876DC
#define pinstCMailAddressBookWnd_x                                 0xE876E0
#define pinstCRaidWnd_x                                            0xE876E8
#define pinstCRaidOptionsWnd_x                                     0xE876EC
#define pinstCBreathWnd_x                                          0xE876F0
#define pinstCMapViewWnd_x                                         0xE876F4
#define pinstCMapToolbarWnd_x                                      0xE876F8
#define pinstCEditLabelWnd_x                                       0xE876FC
#define pinstCTargetWnd_x                                          0xE87700
#define pinstCColorPickerWnd_x                                     0xE87704
#define pinstCPlayerWnd_x                                          0xE87708
#define pinstCOptionsWnd_x                                         0xE8770C
#define pinstCBuffWindowNORMAL_x                                   0xE87710
#define pinstCBuffWindowSHORT_x                                    0xE87714
#define pinstCharacterCreation_x                                   0xE87718
#define pinstCCursorAttachment_x                                   0xE8771C
#define pinstCCastingWnd_x                                         0xE87720
#define pinstCCastSpellWnd_x                                       0xE87724
#define pinstCSpellBookWnd_x                                       0xE87728
#define pinstCInventoryWnd_x                                       0xE8772C
#define pinstCBankWnd_x                                            0xE87730
#define pinstCQuantityWnd_x                                        0xE87734
#define pinstCLootWnd_x                                            0xE87738
#define pinstCActionsWnd_x                                         0xE8773C
#define pinstCCombatAbilityWnd_x                                   0xE87740
#define pinstCMerchantWnd_x                                        0xE87744
#define pinstCTradeWnd_x                                           0xE87748
#define pinstCSelectorWnd_x                                        0xE8774C
#define pinstCBazaarWnd_x                                          0xE87750
#define pinstCBazaarSearchWnd_x                                    0xE87754
#define pinstCGiveWnd_x                                            0xE87770
#define pinstCTrackingWnd_x                                        0xE87778
#define pinstCInspectWnd_x                                         0xE8777C
#define pinstCSocialEditWnd_x                                      0xE87780
#define pinstCFeedbackWnd_x                                        0xE87784
#define pinstCBugReportWnd_x                                       0xE87788
#define pinstCVideoModesWnd_x                                      0xE8778C
#define pinstCTextEntryWnd_x                                       0xE87794
#define pinstCFileSelectionWnd_x                                   0xE87798
#define pinstCCompassWnd_x                                         0xE8779C
#define pinstCPlayerNotesWnd_x                                     0xE877A0
#define pinstCGemsGameWnd_x                                        0xE877A4
#define pinstCTimeLeftWnd_x                                        0xE877A8
#define pinstCPetitionQWnd_x                                       0xE877BC
#define pinstCSoulmarkWnd_x                                        0xE877C0
#define pinstCStoryWnd_x                                           0xE877C4
#define pinstCJournalTextWnd_x                                     0xE877C8
#define pinstCJournalCatWnd_x                                      0xE877CC
#define pinstCBodyTintWnd_x                                        0xE877D0
#define pinstCServerListWnd_x                                      0xE877D4
#define pinstCAvaZoneWnd_x                                         0xE877E0
#define pinstCBlockedBuffWnd_x                                     0xE877E4
#define pinstCBlockedPetBuffWnd_x                                  0xE877E8
#define pinstCInvSlotMgr_x                                         0xE87820
#define pinstCContainerMgr_x                                       0xE87824
#define pinstCAdventureLeaderboardWnd_x                            0x10D9D28
#define pinstCAdventureRequestWnd_x                                0x10D9DA0
#define pinstCAltStorageWnd_x                                      0x10DA080
#define pinstCAdventureStatsWnd_x                                  0x10D9E18
#define pinstCBarterMerchantWnd_x                                  0x10DAC68
#define pinstCBarterSearchWnd_x                                    0x10DACE0
#define pinstCBarterWnd_x                                          0x10DAD58
#define pinstCChatManager_x                                        0x10DB3E8
#define pinstCDynamicZoneWnd_x                                     0x10DB898
#define pinstCEQMainWnd_x                                          0x10DBA30
#define pinstCFellowshipWnd_x                                      0x10DB82C
#define pinstCFindLocationWnd_x                                    0x10DBD00
#define pinstCGroupSearchWnd_x                                     0x10DBFD0
#define pinstCGroupWnd_x                                           0x10DC048
#define pinstCGuildBankWnd_x                                       0x10DC0C0
#define pinstCGuildMgmtWnd_x                                       0x10DE1B0
#define pinstCHotButtonWnd_x                                       0x10DE27C
#define pinstCHotButtonWnd1_x                                      0x10DE27C
#define pinstCHotButtonWnd2_x                                      0x10DE280
#define pinstCHotButtonWnd3_x                                      0x10DE284
#define pinstCHotButtonWnd4_x                                      0x10DE2A8
#define pinstCItemDisplayManager_x                                 0x10DE5A0
#define pinstCItemExpTransferWnd_x                                 0x10DE61C
#define pinstCLFGuildWnd_x                                         0x10DE8F8
#define pinstCMIZoneSelectWnd_x                                    0x10DEEE0
#define pinstCConfirmationDialog_x                                 0x10DF5E8
#define pinstCPopupWndManager_x                                    0x10DF5E8
#define pinstCProgressionSelectionWnd_x                            0x10DF6D8
#define pinstCPvPStatsWnd_x                                        0x10DF7C8
#define pinstCSystemInfoDialogBox_x                                0x10DFED0
#define pinstCTaskWnd_x                                            0x10E1268
#define pinstCTaskTemplateSelectWnd_x                              0x10E11F0
#define pinstCTipWndOFDAY_x                                        0x10E14C0
#define pinstCTipWndCONTEXT_x                                      0x10E14C4
#define pinstCTitleWnd_x                                           0x10E1540
#define pinstCContextMenuManager_x                                 0x1740234
#define pinstCVoiceMacroWnd_x                                      0xFCDF80
#define pinstCHtmlWnd_x                                            0xFCE078
#define pinstIconCache_x                                           0x10DBA04
#define pinstCTradeskillWnd_x                                      0x10E1640

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5079F0
#define __ConvertItemTags_x                                        0x4F5970
#define __ExecuteCmd_x                                             0x4E05C0
#define __EQGetTime_x                                              0x834B90
#define __get_melee_range_x                                        0x4E71E0
#define __GetGaugeValueFromEQ_x                                    0x774C00
#define __GetLabelFromEQ_x                                         0x775E30
#define __GetXTargetType_x                                         0x8F1270
#define __LoadFrontEnd_x                                           0x607BF0
#define __NewUIINI_x                                               0x774540
#define __ProcessGameEvents_x                                      0x54AE90
#define CrashDetected_x                                            0x6096C0
#define DrawNetStatus_x                                            0x581560
#define Util__FastTime_x                                           0x833EA0
#define Expansion_HoT_x                                            0xF48C74
#define __HelpPath_x                                               0xFCC0D0
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A52F0
#define AltAdvManager__IsAbilityReady_x                            0x4A5360
#define AltAdvManager__GetAltAbility_x                             0x4A5720

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x452340

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6378C0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x645450

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x561530

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x660B20
#define CChatManager__InitContextMenu_x                            0x661640

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x81AB40
#define CChatService__GetFriendName_x                              0x81AB50

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6663E0
#define CChatWindow__Clear_x                                       0x665F90
#define CChatWindow__WndNotification_x                             0x666910

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x892F50
#define CComboWnd__Draw_x                                          0x893130
#define CComboWnd__GetCurChoice_x                                  0x892D70
#define CComboWnd__GetListRect_x                                   0x8933D0
#define CComboWnd__GetTextRect_x                                   0x892FB0
#define CComboWnd__InsertChoice_x                                  0x893440
#define CComboWnd__SetColors_x                                     0x892D00
#define CComboWnd__SetChoice_x                                     0x892D30

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x66FA90
#define CContainerWnd__vftable_x                                   0xA51D30

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x493CD0
#define CDisplay__GetClickedActor_x                                0x48C900
#define CDisplay__GetUserDefinedColor_x                            0x48B1C0
#define CDisplay__GetWorldFilePath_x                               0x48A5C0
#define CDisplay__is3dON_x                                         0x489990
#define CDisplay__ReloadUI_x                                       0x49F0A0
#define CDisplay__WriteTextHD2_x                                   0x490140

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8B49B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8A3930
#define CEditWnd__GetCharIndexPt_x                                 0x8A4960
#define CEditWnd__GetDisplayString_x                               0x8A3AE0
#define CEditWnd__GetHorzOffset_x                                  0x8A3E20
#define CEditWnd__GetLineForPrintableChar_x                        0x8A4420
#define CEditWnd__GetSelStartPt_x                                  0x8A4C20
#define CEditWnd__GetSTMLSafeText_x                                0x8A3FC0
#define CEditWnd__PointFromPrintableChar_x                         0x8A4510
#define CEditWnd__SelectableCharFromPoint_x                        0x8A4690
#define CEditWnd__SetEditable_x                                    0x8A3F90

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x528B70
#define CEverQuest__DoTellWindow_x                                 0x52E500
#define CEverQuest__DropHeldItemOnGround_x                         0x536F90
#define CEverQuest__dsp_chat_x                                     0x52FCA0
#define CEverQuest__Emote_x                                        0x52FF00
#define CEverQuest__EnterZone_x                                    0x542DD0
#define CEverQuest__GetBodyTypeDesc_x                              0x5254A0
#define CEverQuest__GetClassDesc_x                                 0x52B070
#define CEverQuest__GetClassThreeLetterCode_x                      0x52B670
#define CEverQuest__GetDeityDesc_x                                 0x525D80
#define CEverQuest__GetLangDesc_x                                  0x525830
#define CEverQuest__GetRaceDesc_x                                  0x52B830
#define CEverQuest__InterpretCmd_x                                 0x5307E0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5471C0
#define CEverQuest__LMouseUp_x                                     0x5494B0
#define CEverQuest__RightClickedOnPlayer_x                         0x547CC0
#define CEverQuest__RMouseUp_x                                     0x548D00
#define CEverQuest__SetGameState_x                                 0x529220
#define CEverQuest__UPCNotificationFlush_x                         0x531980

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6804E0
#define CGaugeWnd__CalcLinesFillRect_x                             0x680540
#define CGaugeWnd__Draw_x                                          0x680970

// CGuild
#define CGuild__FindMemberByName_x                                 0x4242E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69CCA0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6A8A30
#define CInvSlotMgr__MoveItem_x                                    0x6A9970
#define CInvSlotMgr__SelectSlot_x                                  0x6A8AE0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6A7D60
#define CInvSlot__SliderComplete_x                                 0x6A5BB0
#define CInvSlot__GetItemBase_x                                    0x6A5020

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6AA760

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x771870
#define CItemDisplayWnd__UpdateStrings_x                           0x6ABAD0

// CLabel 
#define CLabel__Draw_x                                             0x6C65D0

// CListWnd 
#define CListWnd__AddColumn_x                                      0x8810C0
#define CListWnd__AddColumn1_x                                     0x8808A0
#define CListWnd__AddLine_x                                        0x880350
#define CListWnd__AddString_x                                      0x880560
#define CListWnd__CalculateFirstVisibleLine_x                      0x87D410
#define CListWnd__CalculateVSBRange_x                              0x87F550
#define CListWnd__ClearAllSel_x                                    0x87C6D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x87FF30
#define CListWnd__Compare_x                                        0x87DF20
#define CListWnd__Draw_x                                           0x87F1B0
#define CListWnd__DrawColumnSeparators_x                           0x87F040
#define CListWnd__DrawHeader_x                                     0x87C9E0
#define CListWnd__DrawItem_x                                       0x87E570
#define CListWnd__DrawLine_x                                       0x87ECE0
#define CListWnd__DrawSeparator_x                                  0x87F0E0
#define CListWnd__EnsureVisible_x                                  0x87D570
#define CListWnd__ExtendSel_x                                      0x87E480
#define CListWnd__GetColumnMinWidth_x                              0x87C0F0
#define CListWnd__GetColumnWidth_x                                 0x87C010
#define CListWnd__GetCurSel_x                                      0x87B8E0
#define CListWnd__GetItemAtPoint_x                                 0x87D810
#define CListWnd__GetItemAtPoint1_x                                0x87D880
#define CListWnd__GetItemData_x                                    0x87BB20
#define CListWnd__GetItemHeight_x                                  0x87D070
#define CListWnd__GetItemIcon_x                                    0x87BD00
#define CListWnd__GetItemRect_x                                    0x87D650
#define CListWnd__GetItemText_x                                    0x87BBB0
#define CListWnd__GetSelList_x                                     0x880790
#define CListWnd__GetSeparatorRect_x                               0x87DE40
#define CListWnd__RemoveLine_x                                     0x880740
#define CListWnd__SetColors_x                                      0x87B940
#define CListWnd__SetColumnJustification_x                         0x87C3C0
#define CListWnd__SetColumnWidth_x                                 0x87C0A0
#define CListWnd__SetCurSel_x                                      0x87B920
#define CListWnd__SetItemColor_x                                   0x87FC10
#define CListWnd__SetItemData_x                                    0x87C780
#define CListWnd__SetItemText_x                                    0x87FA50
#define CListWnd__ShiftColumnSeparator_x                           0x87F8E0
#define CListWnd__Sort_x                                           0x88122D
#define CListWnd__ToggleSel_x                                      0x87C650

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6DF7F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7008A0
#define CMerchantWnd__RequestBuyItem_x                             0x707180
#define CMerchantWnd__RequestSellItem_x                            0x72ECF0
#define CMerchantWnd__SelectRecoverySlot_x                         0x700B50
#define CMerchantWnd__SelectBuySellSlot_x                          0x6FFDB0
#define CMerchantWnd__ActualSelect_x                               0x704580

// CObfuscator
#define CObfuscator__doit_x                                        0x7FB670

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8986D0
#define CSidlManager__CreateLabel_x                                0x767890

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x62EA50
#define CSidlScreenWnd__CalculateVSBRange_x                        0x62E970
#define CSidlScreenWnd__ConvertToRes_x                             0x8B4890
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x886230
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x887720
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8877D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x886C90
#define CSidlScreenWnd__DrawSidlPiece_x                            0x885D10
#define CSidlScreenWnd__EnableIniStorage_x                         0x885450
#define CSidlScreenWnd__GetSidlPiece_x                             0x885F00
#define CSidlScreenWnd__Init1_x                                    0x8873F0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8862E0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x885610
#define CSidlScreenWnd__LoadSidlScreen_x                           0x886EE0
#define CSidlScreenWnd__StoreIniInfo_x                             0x884F10
#define CSidlScreenWnd__StoreIniVis_x                              0x8853E0
#define CSidlScreenWnd__WndNotification_x                          0x887170
#define CSidlScreenWnd__GetChildItem_x                             0x885520
#define CSidlScreenWnd__HandleLButtonUp_x                          0x88C0B0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5C9D00
#define CSkillMgr__GetSkillCap_x                                   0x5C9EA0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8BE8A0
#define CSliderWnd__SetValue_x                                     0x8BEA70
#define CSliderWnd__SetNumTicks_x                                  0x8BF1F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x76F510

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8AF000
#define CStmlWnd__CalculateHSBRange_x                              0x8A7520
#define CStmlWnd__CalculateVSBRange_x                              0x8A75B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8A7730
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8A8010
#define CStmlWnd__ForceParseNow_x                                  0x8AF950
#define CStmlWnd__GetNextTagPiece_x                                0x8A7F10
#define CStmlWnd__GetSTMLText_x                                    0x665830
#define CStmlWnd__GetVisibleText_x                                 0x8A8A60
#define CStmlWnd__InitializeWindowVariables_x                      0x8AADF0
#define CStmlWnd__MakeStmlColorTag_x                               0x8A6820
#define CStmlWnd__MakeWndNotificationTag_x                         0x8A6880
#define CStmlWnd__SetSTMLText_x                                    0x8AC650
#define CStmlWnd__StripFirstSTMLLines_x                            0x8AECA0
#define CStmlWnd__UpdateHistoryString_x                            0x8A99A0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8B6090
#define CTabWnd__DrawCurrentPage_x                                 0x8B5900
#define CTabWnd__DrawTab_x                                         0x8B56C0
#define CTabWnd__GetCurrentPage_x                                  0x8B5CD0
#define CTabWnd__GetPageInnerRect_x                                0x8B53B0
#define CTabWnd__GetTabInnerRect_x                                 0x8B55B0
#define CTabWnd__GetTabRect_x                                      0x8B5480
#define CTabWnd__InsertPage_x                                      0x8B6380
#define CTabWnd__SetPage_x                                         0x8B5D00
#define CTabWnd__SetPageRect_x                                     0x8B5FD0
#define CTabWnd__UpdatePage_x                                      0x8B6320

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41FFC0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B2470

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8BB260

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x879B40

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x56E400
#define CXStr__CXStr1_x                                            0x42E7E0
#define CXStr__CXStr3_x                                            0x830F30
#define CXStr__dCXStr_x                                            0x7A5AF0
#define CXStr__operator_equal_x                                    0x8310A0
#define CXStr__operator_equal1_x                                   0x8310F0
#define CXStr__operator_plus_equal1_x                              0x8321D0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x88B300
#define CXWnd__Center_x                                            0x8913E0
#define CXWnd__ClrFocus_x                                          0x88AEE0
#define CXWnd__DoAllDrawing_x                                      0x891030
#define CXWnd__DrawChildren_x                                      0x8911D0
#define CXWnd__DrawColoredRect_x                                   0x88B6C0
#define CXWnd__DrawTooltip_x                                       0x88B970
#define CXWnd__DrawTooltipAtPoint_x                                0x88FFC0
#define CXWnd__GetBorderFrame_x                                    0x88BDB0
#define CXWnd__GetChildWndAt_x                                     0x88EFA0
#define CXWnd__GetClientClipRect_x                                 0x88BB70
#define CXWnd__GetScreenClipRect_x                                 0x8906C0
#define CXWnd__GetScreenRect_x                                     0x88BF60
#define CXWnd__GetTooltipRect_x                                    0x88B800
#define CXWnd__GetWindowTextA_x                                    0x4115A0
#define CXWnd__IsActive_x                                          0x89E690
#define CXWnd__IsDescendantOf_x                                    0x88BD00
#define CXWnd__IsReallyVisible_x                                   0x88EF80
#define CXWnd__IsType_x                                            0x8B7A40
#define CXWnd__Move_x                                              0x88E710
#define CXWnd__Move1_x                                             0x890D00
#define CXWnd__ProcessTransition_x                                 0x88B2A0
#define CXWnd__Refade_x                                            0x88B080
#define CXWnd__Resize_x                                            0x88C010
#define CXWnd__Right_x                                             0x8904C0
#define CXWnd__SetFocus_x                                          0x88D890
#define CXWnd__SetFont_x                                           0x88AF30
#define CXWnd__SetKeyTooltip_x                                     0x88C280
#define CXWnd__SetMouseOver_x                                      0x8909F0
#define CXWnd__StartFade_x                                         0x88B350
#define CXWnd__GetChildItem_x                                      0x890930

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x89FFC0
#define CXWndManager__DrawWindows_x                                0x89FC00
#define CXWndManager__GetKeyboardFlags_x                           0x89E1C0
#define CXWndManager__HandleKeyboardMsg_x                          0x89EB20
#define CXWndManager__RemoveWnd_x                                  0x89E820

// CDBStr
#define CDBStr__GetString_x                                        0x487DE0

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8EDB60
#define EQ_Character__CastSpell_x                                  0x43C030
#define EQ_Character__Cur_HP_x                                     0x451A00
#define EQ_Character__GetAACastingTimeModifier_x                   0x435100
#define EQ_Character__GetCharInfo2_x                               0x805770
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42D420
#define EQ_Character__GetFocusRangeModifier_x                      0x42D600
#define EQ_Character__Max_Endurance_x                              0x593120
#define EQ_Character__Max_HP_x                                     0x448030
#define EQ_Character__Max_Mana_x                                   0x592F50
#define EQ_Character__doCombatAbility_x                            0x590780
#define EQ_Character__UseSkill_x                                   0x45C540
#define EQ_Character__GetConLevel_x                                0x585B50
#define EQ_Character__IsExpansionFlag_x                            0x410AC0
#define EQ_Character__TotalEffect_x                                0x43A160

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x566530
#define EQ_Item__CreateItemTagString_x                             0x7E65A0
#define EQ_Item__IsStackable_x                                     0x7DA7E0
#define EQ_Item__GetImageNum_x                                     0x7DD420

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A73E0
#define EQ_LoadingS__Array_x                                       0xB65688

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x594780
#define EQ_PC__GetAltAbilityIndex_x                                0x7EE7E0
#define EQ_PC__GetCombatAbility_x                                  0x7EE870
#define EQ_PC__GetCombatAbilityTimer_x                             0x7EE920
#define EQ_PC__GetItemTimerValue_x                                 0x58E550
#define EQ_PC__HasLoreItem_x                                       0x588CF0
#define EQ_PC__AlertInventoryChanged_x                             0x585B20
#define EQ_PC__GetPcZoneClient_x                                   0x5AE560
// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E5190
#define EQItemList__add_item_x                                     0x4E50D0
#define EQItemList__delete_item_x                                  0x4E5590
#define EQItemList__FreeItemList_x                                 0x4E5490

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487210

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x599BA0
#define EQPlayer__dEQPlayer_x                                      0x5A2720
#define EQPlayer__DoAttack_x                                       0x5B4360
#define EQPlayer__EQPlayer_x                                       0x5A4B70
#define EQPlayer__SetNameSpriteState_x                             0x59F540
#define EQPlayer__SetNameSpriteTint_x                              0x59AED0
#define EQPlayer__IsBodyType_j_x                                   0x8ECE10
#define EQPlayer__IsTargetable_x                                   0x8ED640

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5A8AF0
#define EQPlayerManager__GetSpawnByName_x                          0x5A8F50

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56C730
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56C770
#define KeypressHandler__ClearCommandStateArray_x                  0x56C310
#define KeypressHandler__HandleKeyDown_x                           0x56AC60
#define KeypressHandler__HandleKeyUp_x                             0x56AF80
#define KeypressHandler__SaveKeymapping_x                          0x56C3E0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6D7BD0
#define MapViewMap__SaveEx_x                                       0x6DB4B0

#define PlayerPointManager__GetAltCurrency_x                       0x7FF950

// StringTable 
#define StringTable__getString_x                                   0x7FB910

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x592BD0

//Doors
#define EQSwitch__UseSwitch_x                                      0x522900

//IconCache
#define IconCache__GetIcon_x                                       0x675DC0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66CDC0
#define CContainerMgr__CloseContainer_x                            0x66D5D0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x737C70

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x560000

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B5A50
#define EQ_Spell__SpellAffects_x                                   0x4B5AF0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B5B20
#define CharacterZoneClient__CalcAffectChange_x                    0x436420
#define CLootWnd__LootAll_x                                        0x6CD760
#define CTargetWnd__GetBuffCaster_x                                0x77D1A0
