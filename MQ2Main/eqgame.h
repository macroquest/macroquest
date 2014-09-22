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
#define __ExpectedVersionDate                                     "Sep 18 2014"
#define __ExpectedVersionTime                                     "17:07:51"
#define __ActualVersionDate_x                                      0xA4D840
#define __ActualVersionTime_x                                      0xA4D84C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x574000
#define __MemChecker1_x                                            0x837D40
#define __MemChecker2_x                                            0x60AF10
#define __MemChecker3_x                                            0x60AE60
#define __MemChecker4_x                                            0x7BC990
#define __EncryptPad0_x                                            0xBB9090
#define __EncryptPad1_x                                            0xD33378
#define __EncryptPad2_x                                            0xC002F0
#define __EncryptPad3_x                                            0xBFFEF0
#define __EncryptPad4_x                                            0xD10CA8
#define __AC1_x                                                    0x779EE5
#define __AC2_x                                                    0x52A797
#define __AC3_x                                                    0x53EE80
#define __AC4_x                                                    0x544FB0
#define __AC5_x                                                    0x5515FE
#define __AC6_x                                                    0x555132
#define __AC7_x                                                    0x54B0BC
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10E3F08
#define DI8__Keyboard_x                                            0x10E3F0C
#define DI8__Mouse_x                                               0x10E3F10
#define __AltTimerReady_x                                          0xF439A1
#define __Attack_x                                                 0xFD6AAB
#define __Autofire_x                                               0xFD6AAC
#define __BindList_x                                               0xB7D260
#define __bCommandEnabled_x                                        0xF41AB0
#define __Clicks_x                                                 0xF525E8
#define __CommandList_x                                            0xB81378
#define __CurrentMapLabel_x                                        0x10E9B88
#define __CurrentSocial_x                                          0xB42E28
#define __DoAbilityList_x                                          0xF88D60
#define __do_loot_x                                                0x4F1FB0
#define __DrawHandler_x                                            0x174C144
#define __GroupCount_x                                             0xF4307A

#define __Guilds_x                                                 0xF48B68
#define __gWorld_x                                                 0xF45534
#define __HotkeyPage_x                                             0xFCF760
#define __HWnd_x                                                   0xFDBE10
#define __InChatMode_x                                             0xF52514
#define __LastTell_x                                               0xF54468
#define __LMouseHeldTime_x                                         0xF52654
#define __Mouse_x                                                  0x10E3F14
#define __MouseLook_x                                              0xF525AE
#define __MouseEventTime_x                                         0xFD729C
#define __NetStatusToggle_x                                        0xF525B1
#define __PCNames_x                                                0xF53A9C
#define __RangeAttackReady_x                                       0xF53734
#define __RMouseHeldTime_x                                         0xF52650
#define __RunWalkState_x                                           0xF52518
#define __ScreenMode_x                                             0xE91A70
#define __ScreenX_x                                                0xF524CC
#define __ScreenY_x                                                0xF524C8
#define __ScreenXMax_x                                             0xF524D0
#define __ScreenYMax_x                                             0xF524D4
#define __ServerHost_x                                             0xF42FC4
#define __ServerName_x                                             0xF88D20
#define __ShiftKeyDown_x                                           0xF52BB8
#define __ShowNames_x                                              0xF53940
#define __Socials_x                                                0xF88E20
#define __SubscriptionType_x                                       0x11138C0
#define __TargetAggroHolder_x                                      0x10EBDA0
#define __GroupAggro_x                                             0x10EBDE0
#define __LoginName_x                                              0xFDA9E8
#define __Inviter_x                                                0xFD6A28


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF45620
#define instEQZoneInfo_x                                           0xF527A4
#define instKeypressHandler_x                                      0xFD7280
#define pinstActiveBanker_x                                        0xF455D8
#define pinstActiveCorpse_x                                        0xF455DC
#define pinstActiveGMaster_x                                       0xF455E0
#define pinstActiveMerchant_x                                      0xF455D4
#define pinstAggroInfo_x                                           0xD56058
#define pinstAltAdvManager_x                                       0xE92B48
#define pinstAuraMgr_x                                             0xD5FF20
#define pinstBandageTarget_x                                       0xF455C0
#define pinstCamActor_x                                            0xE92454
#define pinstCDBStr_x                                              0xE91A04
#define pinstCDisplay_x                                            0xF455E8
#define pinstCEverQuest_x                                          0x10E408C
#define pinstCharData_x                                            0xF455A4
#define pinstCharSpawn_x                                           0xF455CC
#define pinstControlledMissile_x                                   0xF455A0
#define pinstControlledPlayer_x                                    0xF455CC
#define pinstCSidlManager_x                                        0x174B558
#define pinstCXWndManager_x                                        0x174B550
#define instDynamicZone_x                                          0xF52360
#define pinstDZMember_x                                            0xF52470
#define pinstDZTimerInfo_x                                         0xF52474
#define pinstEQItemList_x                                          0xF41CFC
#define instEQMisc_x                                               0xB5E770
#define pinstEQSoundManager_x                                      0xE92E48
#define instExpeditionLeader_x                                     0xF523AA
#define instExpeditionName_x                                       0xF523EA
#define pinstGroup_x                                               0xF43076
#define pinstImeManager_x                                          0x174B55C
#define pinstLocalPlayer_x                                         0xF455B8
#define pinstMercenaryData_x                                       0xFD78D0
#define pinstMercAltAbilities_x                                    0xE92D68
#define pinstModelPlayer_x                                         0xF455E4
#define pinstPCData_x                                              0xF455A4
#define pinstSkillMgr_x                                            0xFD8708
#define pinstSpawnManager_x                                        0xFD7FF0
#define pinstSpellManager_x                                        0xFD8850
#define pinstSpellSets_x                                           0xFCF7C4
#define pinstStringTable_x                                         0xF4554C
#define pinstSwitchManager_x                                       0xF42C08
#define pinstTarget_x                                              0xF455D0
#define pinstTargetObject_x                                        0xF455A8
#define pinstTargetSwitch_x                                        0xF455AC
#define pinstTaskMember_x                                          0xE91950
#define pinstTrackTarget_x                                         0xF455C4
#define pinstTradeTarget_x                                         0xF455B4
#define instTributeActive_x                                        0xB5E795
#define pinstViewActor_x                                           0xE92450
#define pinstWorldData_x                                           0xF45588


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD56538
#define pinstCAudioTriggersWindow_x                                0xD563C8
#define pinstCCharacterSelect_x                                    0xE922FC
#define pinstCFacePick_x                                           0xE920AC
#define pinstCNoteWnd_x                                            0xE922B4
#define pinstCBookWnd_x                                            0xE922BC
#define pinstCPetInfoWnd_x                                         0xE922C0
#define pinstCTrainWnd_x                                           0xE922C4
#define pinstCSkillsWnd_x                                          0xE922C8
#define pinstCSkillsSelectWnd_x                                    0xE922CC
#define pinstCCombatSkillSelectWnd_x                               0xE922D0
#define pinstCFriendsWnd_x                                         0xE922D4
#define pinstCAuraWnd_x                                            0xE922D8
#define pinstCRespawnWnd_x                                         0xE922DC
#define pinstCBandolierWnd_x                                       0xE922E0
#define pinstCPotionBeltWnd_x                                      0xE922E4
#define pinstCAAWnd_x                                              0xE922E8
#define pinstCGroupSearchFiltersWnd_x                              0xE922EC
#define pinstCLoadskinWnd_x                                        0xE922F0
#define pinstCAlarmWnd_x                                           0xE922F4
#define pinstCMusicPlayerWnd_x                                     0xE922F8
#define pinstCMailWnd_x                                            0xE92300
#define pinstCMailCompositionWnd_x                                 0xE92304
#define pinstCMailAddressBookWnd_x                                 0xE92308
#define pinstCRaidWnd_x                                            0xE92310
#define pinstCRaidOptionsWnd_x                                     0xE92314
#define pinstCBreathWnd_x                                          0xE92318
#define pinstCMapViewWnd_x                                         0xE9231C
#define pinstCMapToolbarWnd_x                                      0xE92320
#define pinstCEditLabelWnd_x                                       0xE92324
#define pinstCTargetWnd_x                                          0xE92328
#define pinstCColorPickerWnd_x                                     0xE9232C
#define pinstCPlayerWnd_x                                          0xE92330
#define pinstCOptionsWnd_x                                         0xE92334
#define pinstCBuffWindowNORMAL_x                                   0xE92338
#define pinstCBuffWindowSHORT_x                                    0xE9233C
#define pinstCharacterCreation_x                                   0xE92340
#define pinstCCursorAttachment_x                                   0xE92344
#define pinstCCastingWnd_x                                         0xE92348
#define pinstCCastSpellWnd_x                                       0xE9234C
#define pinstCSpellBookWnd_x                                       0xE92350
#define pinstCInventoryWnd_x                                       0xE92354
#define pinstCBankWnd_x                                            0xE92358
#define pinstCQuantityWnd_x                                        0xE9235C
#define pinstCLootWnd_x                                            0xE92360
#define pinstCActionsWnd_x                                         0xE92364
#define pinstCCombatAbilityWnd_x                                   0xE92368
#define pinstCMerchantWnd_x                                        0xE9236C
#define pinstCTradeWnd_x                                           0xE92370
#define pinstCSelectorWnd_x                                        0xE92374
#define pinstCBazaarWnd_x                                          0xE92378
#define pinstCBazaarSearchWnd_x                                    0xE9237C
#define pinstCGiveWnd_x                                            0xE92398
#define pinstCTrackingWnd_x                                        0xE923A0
#define pinstCInspectWnd_x                                         0xE923A4
#define pinstCSocialEditWnd_x                                      0xE923A8
#define pinstCFeedbackWnd_x                                        0xE923AC
#define pinstCBugReportWnd_x                                       0xE923B0
#define pinstCVideoModesWnd_x                                      0xE923B4
#define pinstCTextEntryWnd_x                                       0xE923BC
#define pinstCFileSelectionWnd_x                                   0xE923C0
#define pinstCCompassWnd_x                                         0xE923C4
#define pinstCPlayerNotesWnd_x                                     0xE923C8
#define pinstCGemsGameWnd_x                                        0xE923CC
#define pinstCTimeLeftWnd_x                                        0xE923D0
#define pinstCPetitionQWnd_x                                       0xE923E4
#define pinstCSoulmarkWnd_x                                        0xE923E8
#define pinstCStoryWnd_x                                           0xE923EC
#define pinstCJournalTextWnd_x                                     0xE923F0
#define pinstCJournalCatWnd_x                                      0xE923F4
#define pinstCBodyTintWnd_x                                        0xE923F8
#define pinstCServerListWnd_x                                      0xE923FC
#define pinstCAvaZoneWnd_x                                         0xE92408
#define pinstCBlockedBuffWnd_x                                     0xE9240C
#define pinstCBlockedPetBuffWnd_x                                  0xE92410
#define pinstCInvSlotMgr_x                                         0xE92448
#define pinstCContainerMgr_x                                       0xE9244C
#define pinstCAdventureLeaderboardWnd_x                            0x10E4C60
#define pinstCAdventureRequestWnd_x                                0x10E4CD8
#define pinstCAltStorageWnd_x                                      0x10E4FB8
#define pinstCAdventureStatsWnd_x                                  0x10E4D50
#define pinstCBarterMerchantWnd_x                                  0x10E5BA0
#define pinstCBarterSearchWnd_x                                    0x10E5C18
#define pinstCBarterWnd_x                                          0x10E5C90
#define pinstCChatManager_x                                        0x10E6320
#define pinstCDynamicZoneWnd_x                                     0x10E67D0
#define pinstCEQMainWnd_x                                          0x10E6968
#define pinstCFellowshipWnd_x                                      0x10E6764
#define pinstCFindLocationWnd_x                                    0x10E6C38
#define pinstCGroupSearchWnd_x                                     0x10E6F08
#define pinstCGroupWnd_x                                           0x10E6F80
#define pinstCGuildBankWnd_x                                       0x10E6FF8
#define pinstCGuildMgmtWnd_x                                       0x10E90E8
#define pinstCHotButtonWnd_x                                       0x10E91B4
#define pinstCHotButtonWnd1_x                                      0x10E91B4
#define pinstCHotButtonWnd2_x                                      0x10E91B8
#define pinstCHotButtonWnd3_x                                      0x10E91BC
#define pinstCHotButtonWnd4_x                                      0x10E91E0
#define pinstCItemDisplayManager_x                                 0x10E94D8
#define pinstCItemExpTransferWnd_x                                 0x10E9554
#define pinstCLFGuildWnd_x                                         0x10E9830
#define pinstCMIZoneSelectWnd_x                                    0x10E9E18
#define pinstCConfirmationDialog_x                                 0x10EA520
#define pinstCPopupWndManager_x                                    0x10EA520
#define pinstCProgressionSelectionWnd_x                            0x10EA610
#define pinstCPvPStatsWnd_x                                        0x10EA700
#define pinstCSystemInfoDialogBox_x                                0x10EAE08
#define pinstCTaskWnd_x                                            0x10EC1A0
#define pinstCTaskTemplateSelectWnd_x                              0x10EC128
#define pinstCTipWndOFDAY_x                                        0x10EC3F8
#define pinstCTipWndCONTEXT_x                                      0x10EC3FC
#define pinstCTitleWnd_x                                           0x10EC478
#define pinstCContextMenuManager_x                                 0x174B16C
#define pinstCVoiceMacroWnd_x                                      0xFD8EB8
#define pinstCHtmlWnd_x                                            0xFD8FB0
#define pinstIconCache_x                                           0x10E693C
#define pinstCTradeskillWnd_x                                      0x10EC578

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x509AC0
#define __ConvertItemTags_x                                        0x4F6C70
#define __ExecuteCmd_x                                             0x4E18A0
#define __EQGetTime_x                                              0x8388A0
#define __get_melee_range_x                                        0x4E84E0
#define __GetGaugeValueFromEQ_x                                    0x778C40
#define __GetLabelFromEQ_x                                         0x779E70
#define __GetXTargetType_x                                         0x8F5E50
#define __LoadFrontEnd_x                                           0x60A5C0
#define __NewUIINI_x                                               0x778580
#define __ProcessGameEvents_x                                      0x54D1F0
#define CrashDetected_x                                            0x60C090
#define DrawNetStatus_x                                            0x5838E0
#define Util__FastTime_x                                           0x837BB0
#define Expansion_HoT_x                                            0xF538A0
#define __HelpPath_x                                               0xFD7008
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A5DF0
#define AltAdvManager__IsAbilityReady_x                            0x4A5E60
#define AltAdvManager__GetAltAbility_x                             0x4A6220

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x452CE0
#define CharacterZoneClient__MakeMeVisible_x                       0x457C80

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x63A3B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6487D0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5639A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6634F0
#define CChatManager__InitContextMenu_x                            0x664010

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x81E740
#define CChatService__GetFriendName_x                              0x81E750

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x668E00
#define CChatWindow__Clear_x                                       0x6689B0
#define CChatWindow__WndNotification_x                             0x669340

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x896F90
#define CComboWnd__Draw_x                                          0x897170
#define CComboWnd__GetCurChoice_x                                  0x896DB0
#define CComboWnd__GetListRect_x                                   0x897410
#define CComboWnd__GetTextRect_x                                   0x896FF0
#define CComboWnd__InsertChoice_x                                  0x897480
#define CComboWnd__SetColors_x                                     0x896D40
#define CComboWnd__SetChoice_x                                     0x896D70

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6724B0
#define CContainerWnd__vftable_x                                   0xA57010

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x494650
#define CDisplay__GetClickedActor_x                                0x48D0F0
#define CDisplay__GetUserDefinedColor_x                            0x48B9B0
#define CDisplay__GetWorldFilePath_x                               0x48ADB0
#define CDisplay__is3dON_x                                         0x48A180
#define CDisplay__ReloadUI_x                                       0x49FA70
#define CDisplay__WriteTextHD2_x                                   0x490940

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8B8D70

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8A78C0
#define CEditWnd__GetCharIndexPt_x                                 0x8A88D0
#define CEditWnd__GetDisplayString_x                               0x8A7A70
#define CEditWnd__GetHorzOffset_x                                  0x8A7DB0
#define CEditWnd__GetLineForPrintableChar_x                        0x8A83A0
#define CEditWnd__GetSelStartPt_x                                  0x8A8B80
#define CEditWnd__GetSTMLSafeText_x                                0x8A7F40
#define CEditWnd__PointFromPrintableChar_x                         0x8A8490
#define CEditWnd__SelectableCharFromPoint_x                        0x8A8610
#define CEditWnd__SetEditable_x                                    0x8A7F10

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x52AEE0
#define CEverQuest__DoTellWindow_x                                 0x530870
#define CEverQuest__DropHeldItemOnGround_x                         0x539300
#define CEverQuest__dsp_chat_x                                     0x532010
#define CEverQuest__Emote_x                                        0x532270
#define CEverQuest__EnterZone_x                                    0x545140
#define CEverQuest__GetBodyTypeDesc_x                              0x527810
#define CEverQuest__GetClassDesc_x                                 0x52D3E0
#define CEverQuest__GetClassThreeLetterCode_x                      0x52D9E0
#define CEverQuest__GetDeityDesc_x                                 0x5280F0
#define CEverQuest__GetLangDesc_x                                  0x527BA0
#define CEverQuest__GetRaceDesc_x                                  0x52DBA0
#define CEverQuest__InterpretCmd_x                                 0x532B50
#define CEverQuest__LeftClickedOnPlayer_x                          0x549530
#define CEverQuest__LMouseUp_x                                     0x54B820
#define CEverQuest__RightClickedOnPlayer_x                         0x54A030
#define CEverQuest__RMouseUp_x                                     0x54B070
#define CEverQuest__SetGameState_x                                 0x52B590
#define CEverQuest__UPCNotificationFlush_x                         0x533CF0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x682F70
#define CGaugeWnd__CalcLinesFillRect_x                             0x682FD0
#define CGaugeWnd__Draw_x                                          0x683400

// CGuild
#define CGuild__FindMemberByName_x                                 0x424830

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6A0020

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6ABDC0
#define CInvSlotMgr__MoveItem_x                                    0x6ACD00
#define CInvSlotMgr__SelectSlot_x                                  0x6ABE70

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6AB0E0
#define CInvSlot__SliderComplete_x                                 0x6A8F30
#define CInvSlot__GetItemBase_x                                    0x6A83C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6ADAA0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7758B0
#define CItemDisplayWnd__UpdateStrings_x                           0x6AEDD0

// CLabel 
#define CLabel__Draw_x                                             0x6C98A0

// CListWnd 
#define CListWnd__AddColumn_x                                      0x884F80
#define CListWnd__AddColumn1_x                                     0x884760
#define CListWnd__AddLine_x                                        0x884210
#define CListWnd__AddString_x                                      0x884420
#define CListWnd__CalculateFirstVisibleLine_x                      0x881320
#define CListWnd__CalculateVSBRange_x                              0x883410
#define CListWnd__ClearAllSel_x                                    0x880600
#define CListWnd__CloseAndUpdateEditWindow_x                       0x883DE0
#define CListWnd__Compare_x                                        0x881DF0
#define CListWnd__Draw_x                                           0x883070
#define CListWnd__DrawColumnSeparators_x                           0x882F00
#define CListWnd__DrawHeader_x                                     0x880910
#define CListWnd__DrawItem_x                                       0x882440
#define CListWnd__DrawLine_x                                       0x882BA0
#define CListWnd__DrawSeparator_x                                  0x882FA0
#define CListWnd__EnsureVisible_x                                  0x881480
#define CListWnd__ExtendSel_x                                      0x882350
#define CListWnd__GetColumnMinWidth_x                              0x880020
#define CListWnd__GetColumnWidth_x                                 0x87FF40
#define CListWnd__GetCurSel_x                                      0x87F720
#define CListWnd__GetItemAtPoint_x                                 0x8816F0
#define CListWnd__GetItemAtPoint1_x                                0x881760
#define CListWnd__GetItemData_x                                    0x87FA50
#define CListWnd__GetItemHeight_x                                  0x880F90
#define CListWnd__GetItemIcon_x                                    0x87FC30
#define CListWnd__GetItemRect_x                                    0x881540
#define CListWnd__GetItemText_x                                    0x87FAE0
#define CListWnd__GetSelList_x                                     0x884650
#define CListWnd__GetSeparatorRect_x                               0x881D20
#define CListWnd__RemoveLine_x                                     0x884600
#define CListWnd__SetColors_x                                      0x87F870
#define CListWnd__SetColumnJustification_x                         0x8802F0
#define CListWnd__SetColumnWidth_x                                 0x87FFD0
#define CListWnd__SetCurSel_x                                      0x87F760
#define CListWnd__SetItemColor_x                                   0x883AC0
#define CListWnd__SetItemData_x                                    0x8806B0
#define CListWnd__SetItemText_x                                    0x883900
#define CListWnd__ShiftColumnSeparator_x                           0x883790
#define CListWnd__Sort_x                                           0x8850E0
#define CListWnd__ToggleSel_x                                      0x880580

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6E2B00

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x703DD0
#define CMerchantWnd__RequestBuyItem_x                             0x70AC30
#define CMerchantWnd__RequestSellItem_x                            0x732DE0
#define CMerchantWnd__SelectRecoverySlot_x                         0x704080
#define CMerchantWnd__SelectBuySellSlot_x                          0x7032E0
#define CMerchantWnd__ActualSelect_x                               0x707B50

// CObfuscator
#define CObfuscator__doit_x                                        0x7FEDD0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x89C6D0
#define CSidlManager__CreateLabel_x                                0x76B8C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x631560
#define CSidlScreenWnd__CalculateVSBRange_x                        0x631490
#define CSidlScreenWnd__ConvertToRes_x                             0x8B8C50
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x88A080
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x88B5A0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x88B650
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x88AB00
#define CSidlScreenWnd__DrawSidlPiece_x                            0x889B60
#define CSidlScreenWnd__EnableIniStorage_x                         0x8892C0
#define CSidlScreenWnd__GetSidlPiece_x                             0x889D50
#define CSidlScreenWnd__Init1_x                                    0x88B270
#define CSidlScreenWnd__LoadIniInfo_x                              0x88A130
#define CSidlScreenWnd__LoadIniListWnd_x                           0x889480
#define CSidlScreenWnd__LoadSidlScreen_x                           0x88AD50
#define CSidlScreenWnd__StoreIniInfo_x                             0x888D80
#define CSidlScreenWnd__StoreIniVis_x                              0x889250
#define CSidlScreenWnd__WndNotification_x                          0x88AFF0
#define CSidlScreenWnd__GetChildItem_x                             0x889390
#define CSidlScreenWnd__HandleLButtonUp_x                          0x88FFA0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5CC4A0
#define CSkillMgr__GetSkillCap_x                                   0x5CC640
#define CSkillMgr__GetNameToken_x                                  0x5CC110

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8C2C50
#define CSliderWnd__SetValue_x                                     0x8C2E20
#define CSliderWnd__SetNumTicks_x                                  0x8C35A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x773550

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8B2F80
#define CStmlWnd__CalculateHSBRange_x                              0x8AB4D0
#define CStmlWnd__CalculateVSBRange_x                              0x8AB560
#define CStmlWnd__CanBreakAtCharacter_x                            0x8AB6D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8ABFB0
#define CStmlWnd__ForceParseNow_x                                  0x8B3940
#define CStmlWnd__GetNextTagPiece_x                                0x8ABEB0
#define CStmlWnd__GetSTMLText_x                                    0x668250
#define CStmlWnd__GetVisibleText_x                                 0x8ACA00
#define CStmlWnd__InitializeWindowVariables_x                      0x8AED70
#define CStmlWnd__MakeStmlColorTag_x                               0x8AA7D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8AA830
#define CStmlWnd__SetSTMLText_x                                    0x8B05D0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8B2C20
#define CStmlWnd__UpdateHistoryString_x                            0x8AD930

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8BA450
#define CTabWnd__DrawCurrentPage_x                                 0x8B9CC0
#define CTabWnd__DrawTab_x                                         0x8B9A90
#define CTabWnd__GetCurrentPage_x                                  0x8BA090
#define CTabWnd__GetPageInnerRect_x                                0x8B9780
#define CTabWnd__GetTabInnerRect_x                                 0x8B9980
#define CTabWnd__GetTabRect_x                                      0x8B9850
#define CTabWnd__InsertPage_x                                      0x8BA740
#define CTabWnd__SetPage_x                                         0x8BA0C0
#define CTabWnd__SetPageRect_x                                     0x8BA390
#define CTabWnd__UpdatePage_x                                      0x8BA6E0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4205C0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B64B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8BF610

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x87D980

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x570710
#define CXStr__CXStr1_x                                            0x872650
#define CXStr__CXStr3_x                                            0x834C40
#define CXStr__dCXStr_x                                            0x682E50
#define CXStr__operator_equal_x                                    0x834DB0
#define CXStr__operator_equal1_x                                   0x834E00
#define CXStr__operator_plus_equal1_x                              0x835EE0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x88F200
#define CXWnd__Center_x                                            0x8953F0
#define CXWnd__ClrFocus_x                                          0x88EDF0
#define CXWnd__DoAllDrawing_x                                      0x895020
#define CXWnd__DrawChildren_x                                      0x8951D0
#define CXWnd__DrawColoredRect_x                                   0x88F5B0
#define CXWnd__DrawTooltip_x                                       0x88F840
#define CXWnd__DrawTooltipAtPoint_x                                0x893F70
#define CXWnd__GetBorderFrame_x                                    0x88FCA0
#define CXWnd__GetChildWndAt_x                                     0x892F50
#define CXWnd__GetClientClipRect_x                                 0x88FA60
#define CXWnd__GetScreenClipRect_x                                 0x894660
#define CXWnd__GetScreenRect_x                                     0x88FE50
#define CXWnd__GetTooltipRect_x                                    0x88F6D0
#define CXWnd__GetWindowTextA_x                                    0x4117E0
#define CXWnd__IsActive_x                                          0x8A2680
#define CXWnd__IsDescendantOf_x                                    0x88FBF0
#define CXWnd__IsReallyVisible_x                                   0x892F30
#define CXWnd__IsType_x                                            0x8BBDF0
#define CXWnd__Move_x                                              0x892630
#define CXWnd__Move1_x                                             0x894CC0
#define CXWnd__ProcessTransition_x                                 0x88F1B0
#define CXWnd__Refade_x                                            0x88EF80
#define CXWnd__Resize_x                                            0x88FF10
#define CXWnd__Right_x                                             0x894460
#define CXWnd__SetFocus_x                                          0x891790
#define CXWnd__SetFont_x                                           0x88EE40
#define CXWnd__SetKeyTooltip_x                                     0x890170
#define CXWnd__SetMouseOver_x                                      0x8949A0
#define CXWnd__StartFade_x                                         0x88F250
#define CXWnd__GetChildItem_x                                      0x8948E0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A3FB0
#define CXWndManager__DrawWindows_x                                0x8A3BF0
#define CXWndManager__GetKeyboardFlags_x                           0x8A21B0
#define CXWndManager__HandleKeyboardMsg_x                          0x8A2B10
#define CXWndManager__RemoveWnd_x                                  0x8A2810

// CDBStr
#define CDBStr__GetString_x                                        0x488600

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8F2EC0
#define EQ_Character__CastSpell_x                                  0x43C950
#define EQ_Character__Cur_HP_x                                     0x4523A0
#define EQ_Character__GetAACastingTimeModifier_x                   0x435A50
#define EQ_Character__GetCharInfo2_x                               0x809480
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42DD80
#define EQ_Character__GetFocusRangeModifier_x                      0x42DF60
#define EQ_Character__Max_Endurance_x                              0x595420
#define EQ_Character__Max_HP_x                                     0x4489C0
#define EQ_Character__Max_Mana_x                                   0x595250
#define EQ_Character__doCombatAbility_x                            0x592A80
#define EQ_Character__UseSkill_x                                   0x45CED0
#define EQ_Character__GetConLevel_x                                0x587FB0
#define EQ_Character__IsExpansionFlag_x                            0x410D10
#define EQ_Character__TotalEffect_x                                0x43AA80

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x568940
#define EQ_Item__CreateItemTagString_x                             0x7E9E30
#define EQ_Item__IsStackable_x                                     0x7DE2D0
#define EQ_Item__GetImageNum_x                                     0x7E0F10

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A7EE0
#define EQ_LoadingS__Array_x                                       0xB6BED8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x596A70
#define EQ_PC__GetAltAbilityIndex_x                                0x7F1FE0
#define EQ_PC__GetCombatAbility_x                                  0x7F2070
#define EQ_PC__GetCombatAbilityTimer_x                             0x7F2120
#define EQ_PC__GetItemTimerValue_x                                 0x590850
#define EQ_PC__HasLoreItem_x                                       0x58B120
#define EQ_PC__AlertInventoryChanged_x                             0x587F80
#define EQ_PC__GetPcZoneClient_x                                   0x5B0CC0
#define EQ_PC__RemoveMyAffect_x									   0x58FDA0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E64A0
#define EQItemList__add_item_x                                     0x4E63E0
#define EQItemList__delete_item_x                                  0x4E68A0
#define EQItemList__FreeItemList_x                                 0x4E67A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487B20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x59BED0
#define EQPlayer__dEQPlayer_x                                      0x5A4B30
#define EQPlayer__DoAttack_x                                       0x5B6AB0
#define EQPlayer__EQPlayer_x                                       0x5A6F80
#define EQPlayer__SetNameSpriteState_x                             0x5A18E0
#define EQPlayer__SetNameSpriteTint_x                              0x59D260
#define EQPlayer__IsBodyType_j_x                                   0x8F2170
#define EQPlayer__IsTargetable_x                                   0x8F29A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5AB2B0
#define EQPlayerManager__GetSpawnByName_x                          0x5AB710

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56EA40
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56EA80
#define KeypressHandler__ClearCommandStateArray_x                  0x56E620
#define KeypressHandler__HandleKeyDown_x                           0x56CF70
#define KeypressHandler__HandleKeyUp_x                             0x56D290
#define KeypressHandler__SaveKeymapping_x                          0x56E6F0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6DAEE0
#define MapViewMap__SaveEx_x                                       0x6DE7C0

#define PlayerPointManager__GetAltCurrency_x                       0x803670

// StringTable 
#define StringTable__getString_x                                   0x7FF070

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x594ED0

//Doors
#define EQSwitch__UseSwitch_x                                      0x524BA0

//IconCache
#define IconCache__GetIcon_x                                       0x6787C0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66F7E0
#define CContainerMgr__CloseContainer_x                            0x66FFF0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x73BD60

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x562480

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B64E0
#define EQ_Spell__SpellAffects_x                                   0x4B6580
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B65B0
#define CharacterZoneClient__CalcAffectChange_x                    0x436D70
#define CLootWnd__LootAll_x                                        0x6D0A70
#define CTargetWnd__GetBuffCaster_x                                0x781170
