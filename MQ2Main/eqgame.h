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
#define __ExpectedVersionDate                                     "Apr 15 2013"
#define __ExpectedVersionTime                                     "16:53:55"
#define __ActualVersionDate_x                                      0x9DBF10
#define __ActualVersionTime_x                                      0x9DBF1C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x563570
#define __MemChecker1_x                                            0x807CD0
#define __MemChecker2_x                                            0x5F8A80
#define __MemChecker3_x                                            0x5F89D0
#define __MemChecker4_x                                            0x8CAD40
#define __EncryptPad0_x                                            0xAE3280
#define __EncryptPad1_x                                            0xB608B8
#define __EncryptPad2_x                                            0xAFC920
#define __EncryptPad3_x                                            0xAFC520
#define __EncryptPad4_x                                            0xB66068
#define __AC1_x                                                    0x762655
#define __AC2_x                                                    0x517B77
#define __AC3_x                                                    0x52AFB0
#define __AC4_x                                                    0x531024
#define __AC5_x                                                    0x53D02B
#define __AC6_x                                                    0x540962
#define __AC7_x                                                    0x536F4C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0xE66AE0
#define DI8__Keyboard_x                                            0xE66AE4
#define DI8__Mouse_x                                               0xE66AE8
#define __AltTimerReady_x                                          0xDCF9B9
#define __Attack_x                                                 0xE62546
#define __Autofire_x                                               0xE62547
#define __BindList_x                                               0xACAEE8
#define __Clicks_x                                                 0xDDE6D4
#define __CommandList_x                                            0xACC5A8
#define __CurrentMapLabel_x                                        0xF72D98
#define __CurrentSocial_x                                          0xAB5A28
#define __DoAbilityList_x                                          0xE14DEC
#define __do_loot_x                                                0x4E6960
#define __DrawHandler_x                                            0x15D363C
#define __GroupCount_x                                             0xDCF092

#define __Guilds_x                                                 0xDD4C98
#define __gWorld_x                                                 0xDD154C
#define __HotkeyPage_x                                             0xE5B7EC
#define __HWnd_x                                                   0xE66838
#define __InChatMode_x                                             0xDDE60C
#define __LastTell_x                                               0xDE04F4
#define __LMouseHeldTime_x                                         0xDDE740
#define __Mouse_x                                                  0xE66AEC
#define __MouseLook_x                                              0xDDE6A2
#define __MouseEventTime_x                                         0xE62964
#define __NetStatusToggle_x                                        0xDDE6A5
#define __PCNames_x                                                0xDDFB64
#define __RangeAttackReady_x                                       0xDDF800
#define __RMouseHeldTime_x                                         0xDDE73C
#define __RunWalkState_x                                           0xDDE610
#define __ScreenMode_x                                             0xD1E358
#define __ScreenX_x                                                0xDDE5C4
#define __ScreenY_x                                                0xDDE5C0
#define __ScreenXMax_x                                             0xDDE5C8
#define __ScreenYMax_x                                             0xDDE5CC
#define __ServerHost_x                                             0xDCEFDC
#define __ServerName_x                                             0xE14DAC
#define __ShiftKeyDown_x                                           0xDDEC9C
#define __ShowNames_x                                              0xDDFA0C
#define __Socials_x                                                0xE14EAC


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xDD1630
#define instEQZoneInfo_x                                           0xDDE890
#define instKeypressHandler_x                                      0xE62948
#define pinstActiveBanker_x                                        0xDD15F0
#define pinstActiveCorpse_x                                        0xDD15F4
#define pinstActiveGMaster_x                                       0xDD15F8
#define pinstActiveMerchant_x                                      0xDD15EC
#define pinstAggroInfo_x                                           0xB77FF0
#define pinstAltAdvManager_x                                       0xD1F2F8
#define pinstAuraMgr_x                                             0xB818F0
#define pinstBandageTarget_x                                       0xDD15D8
#define pinstCamActor_x                                            0xD1ED2C
#define pinstCDBStr_x                                              0xD1E320
#define pinstCDisplay_x                                            0xDD1600
#define pinstCEverQuest_x                                          0xE66C64
#define pinstCharData_x                                            0xDD15BC
#define pinstCharSpawn_x                                           0xDD15E4
#define pinstControlledMissile_x                                   0xDD15B8
#define pinstControlledPlayer_x                                    0xDD15E4
#define pinstCSidlManager_x                                        0x15D2CA0
#define pinstCXWndManager_x                                        0x15D2C98
#define instDynamicZone_x                                          0xDDE470
#define pinstDZMember_x                                            0xDDE580
#define pinstDZTimerInfo_x                                         0xDDE584
#define pinstEQItemList_x                                          0xDCE0C0
#define instEQMisc_x                                               0xABECD0
#define pinstEQSoundManager_x                                      0xD1F400
#define instExpeditionLeader_x                                     0xDDE4BA
#define instExpeditionName_x                                       0xDDE4FA
#define pinstGroup_x                                               0xDCF08E
#define pinstImeManager_x                                          0x15D2CA4
#define pinstLocalPlayer_x                                         0xDD15D0
#define pinstMercenaryData_x                                       0xE62E28
#define pinstModelPlayer_x                                         0xDD15FC
#define pinstPCData_x                                              0xDD15BC
#define pinstSkillMgr_x                                            0xE635A8
#define pinstSpawnManager_x                                        0xE63168
#define pinstSpellManager_x                                        0xE63648
#define pinstSpellSets_x                                           0xE5B850
#define pinstStringTable_x                                         0xDD1564
#define pinstSwitchManager_x                                       0xDCECA0
#define pinstTarget_x                                              0xDD15E8
#define pinstTargetObject_x                                        0xDD15C0
#define pinstTargetSwitch_x                                        0xDD15C4
#define pinstTaskMember_x                                          0xD1E2B4
#define pinstTrackTarget_x                                         0xDD15DC
#define pinstTradeTarget_x                                         0xDD15CC
#define instTributeActive_x                                        0xABECF5
#define pinstViewActor_x                                           0xD1ED28
#define pinstWorldData_x                                           0xDD15A0


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xB78248
#define pinstCAudioTriggersWindow_x                                0xB78180
#define pinstCCharacterSelect_x                                    0xD1EBD4
#define pinstCFacePick_x                                           0xD1E984
#define pinstCNoteWnd_x                                            0xD1EB8C
#define pinstCBookWnd_x                                            0xD1EB94
#define pinstCPetInfoWnd_x                                         0xD1EB98
#define pinstCTrainWnd_x                                           0xD1EB9C
#define pinstCSkillsWnd_x                                          0xD1EBA0
#define pinstCSkillsSelectWnd_x                                    0xD1EBA4
#define pinstCCombatSkillSelectWnd_x                               0xD1EBA8
#define pinstCFriendsWnd_x                                         0xD1EBAC
#define pinstCAuraWnd_x                                            0xD1EBB0
#define pinstCRespawnWnd_x                                         0xD1EBB4
#define pinstCBandolierWnd_x                                       0xD1EBB8
#define pinstCPotionBeltWnd_x                                      0xD1EBBC
#define pinstCAAWnd_x                                              0xD1EBC0
#define pinstCGroupSearchFiltersWnd_x                              0xD1EBC4
#define pinstCLoadskinWnd_x                                        0xD1EBC8
#define pinstCAlarmWnd_x                                           0xD1EBCC
#define pinstCMusicPlayerWnd_x                                     0xD1EBD0
#define pinstCMailWnd_x                                            0xD1EBD8
#define pinstCMailCompositionWnd_x                                 0xD1EBDC
#define pinstCMailAddressBookWnd_x                                 0xD1EBE0
#define pinstCRaidWnd_x                                            0xD1EBE8
#define pinstCRaidOptionsWnd_x                                     0xD1EBEC
#define pinstCBreathWnd_x                                          0xD1EBF0
#define pinstCMapViewWnd_x                                         0xD1EBF4
#define pinstCMapToolbarWnd_x                                      0xD1EBF8
#define pinstCEditLabelWnd_x                                       0xD1EBFC
#define pinstCTargetWnd_x                                          0xD1EC00
#define pinstCColorPickerWnd_x                                     0xD1EC04
#define pinstCPlayerWnd_x                                          0xD1EC08
#define pinstCOptionsWnd_x                                         0xD1EC0C
#define pinstCBuffWindowNORMAL_x                                   0xD1EC10
#define pinstCBuffWindowSHORT_x                                    0xD1EC14
#define pinstCharacterCreation_x                                   0xD1EC18
#define pinstCCursorAttachment_x                                   0xD1EC1C
#define pinstCCastingWnd_x                                         0xD1EC20
#define pinstCCastSpellWnd_x                                       0xD1EC24
#define pinstCSpellBookWnd_x                                       0xD1EC28
#define pinstCInventoryWnd_x                                       0xD1EC2C
#define pinstCBankWnd_x                                            0xD1EC30
#define pinstCQuantityWnd_x                                        0xD1EC34
#define pinstCLootWnd_x                                            0xD1EC38
#define pinstCActionsWnd_x                                         0xD1EC3C
#define pinstCCombatAbilityWnd_x                                   0xD1EC40
#define pinstCMerchantWnd_x                                        0xD1EC44
#define pinstCTradeWnd_x                                           0xD1EC48
#define pinstCSelectorWnd_x                                        0xD1EC4C
#define pinstCBazaarWnd_x                                          0xD1EC50
#define pinstCBazaarSearchWnd_x                                    0xD1EC54
#define pinstCGiveWnd_x                                            0xD1EC70
#define pinstCTrackingWnd_x                                        0xD1EC78
#define pinstCInspectWnd_x                                         0xD1EC7C
#define pinstCSocialEditWnd_x                                      0xD1EC80
#define pinstCFeedbackWnd_x                                        0xD1EC84
#define pinstCBugReportWnd_x                                       0xD1EC88
#define pinstCVideoModesWnd_x                                      0xD1EC8C
#define pinstCTextEntryWnd_x                                       0xD1EC94
#define pinstCFileSelectionWnd_x                                   0xD1EC98
#define pinstCCompassWnd_x                                         0xD1EC9C
#define pinstCPlayerNotesWnd_x                                     0xD1ECA0
#define pinstCGemsGameWnd_x                                        0xD1ECA4
#define pinstCTimeLeftWnd_x                                        0xD1ECA8
#define pinstCPetitionQWnd_x                                       0xD1ECBC
#define pinstCSoulmarkWnd_x                                        0xD1ECC0
#define pinstCStoryWnd_x                                           0xD1ECC4
#define pinstCJournalTextWnd_x                                     0xD1ECC8
#define pinstCJournalCatWnd_x                                      0xD1ECCC
#define pinstCBodyTintWnd_x                                        0xD1ECD0
#define pinstCServerListWnd_x                                      0xD1ECD4
#define pinstCAvaZoneWnd_x                                         0xD1ECE0
#define pinstCBlockedBuffWnd_x                                     0xD1ECE4
#define pinstCBlockedPetBuffWnd_x                                  0xD1ECE8
#define pinstCInvSlotMgr_x                                         0xD1ED20
#define pinstCContainerMgr_x                                       0xD1ED24
#define pinstCAdventureLeaderboardWnd_x                            0xF6F458
#define pinstCAdventureRequestWnd_x                                0xF6F498
#define pinstCAltStorageWnd_x                                      0xF6F628
#define pinstCAdventureStatsWnd_x                                  0xF6F4D8
#define pinstCBarterMerchantWnd_x                                  0xF6FC08
#define pinstCBarterSearchWnd_x                                    0xF6FC48
#define pinstCBarterWnd_x                                          0xF6FC88
#define pinstCChatManager_x                                        0xF70008
#define pinstCDynamicZoneWnd_x                                     0xF70278
#define pinstCEQMainWnd_x                                          0xF70358
#define pinstCFellowshipWnd_x                                      0xF70244
#define pinstCFindLocationWnd_x                                    0xF704D8
#define pinstCGroupSearchWnd_x                                     0xF70688
#define pinstCGroupWnd_x                                           0xF706C8
#define pinstCGuildBankWnd_x                                       0xF70708
#define pinstCGuildMgmtWnd_x                                       0xF72788
#define pinstCHotButtonWnd_x                                       0xF727EC
#define pinstCHotButtonWnd1_x                                      0xF727EC
#define pinstCHotButtonWnd2_x                                      0xF727F0
#define pinstCHotButtonWnd3_x                                      0xF727F4
#define pinstCHotButtonWnd4_x                                      0xF72818
#define pinstCItemDisplayManager_x                                 0xF729C0
#define pinstCItemExpTransferWnd_x                                 0xF72A04
#define pinstCLFGuildWnd_x                                         0xF72BC0
#define pinstCMIZoneSelectWnd_x                                    0xF72F10
#define pinstCConfirmationDialog_x                                 0xF732D0
#define pinstCPopupWndManager_x                                    0xF732D0
#define pinstCProgressionSelectionWnd_x                            0xF73350
#define pinstCPvPStatsWnd_x                                        0xF733D0
#define pinstCSystemInfoDialogBox_x                                0xF73790
#define pinstCTaskTemplateSelectWnd_x                              0xF746E8
#define pinstCTipWndOFDAY_x                                        0xF74858
#define pinstCTipWndCONTEXT_x                                      0xF7485C
#define pinstCTitleWnd_x                                           0xF748A0
#define pinstCContextMenuManager_x                                 0x15D28B4
#define pinstCVoiceMacroWnd_x                                      0xE639F8
#define pinstCHtmlWnd_x                                            0xE63A80


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x4FC2B0
#define __ConvertItemTags_x                                        0x4EC1F0
#define __ExecuteCmd_x                                             0x4D63B0
#define __EQGetTime_x                                              0x808830
#define __get_melee_range_x                                        0x4DCFE0
#define __GetGaugeValueFromEQ_x                                    0x7613B0
#define __GetLabelFromEQ_x                                         0x7625E0
#define __GetXTargetType_x                                         0x8D2980
#define __LoadFrontEnd_x                                           0x5F8130
#define __NewUIINI_x                                               0x760CF0
#define __ProcessGameEvents_x                                      0x539030
#define CrashDetected_x                                            0x5FA7AB
#define DrawNetStatus_x                                            0x5728E0
#define Util__FastTime_x                                           0x807B70
#define Expansion_HoT_x                                            0xDDF96C
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A2970
#define AltAdvManager__IsAbilityReady_x                            0x4A29B0
#define AltAdvManager__GetAltAbility_x                             0x4A2D90

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x44A2D0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x626F70

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x634F50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x54ED80

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x64FAE0
#define CChatManager__InitContextMenu_x                            0x650600

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x7EE8E0
#define CChatService__GetFriendName_x                              0x7EE8F0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x655330
#define CChatWindow__Clear_x                                       0x654EF0
#define CChatWindow__WndNotification_x                             0x655870

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8697A0
#define CComboWnd__Draw_x                                          0x869970
#define CComboWnd__GetCurChoice_x                                  0x8695C0
#define CComboWnd__GetListRect_x                                   0x869C10
#define CComboWnd__GetTextRect_x                                   0x869800
#define CComboWnd__InsertChoice_x                                  0x869C80
#define CComboWnd__SetColors_x                                     0x869550
#define CComboWnd__SetChoice_x                                     0x869580

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x65E960
#define CContainerWnd__vftable_x                                   0x9E5418

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4928C0
#define CDisplay__GetClickedActor_x                                0x48A9E0
#define CDisplay__GetUserDefinedColor_x                            0x4892B0
#define CDisplay__GetWorldFilePath_x                               0x4886B0
#define CDisplay__is3dON_x                                         0x487790
#define CDisplay__ReloadUI_x                                       0x49C890
#define CDisplay__WriteTextHD2_x                                   0x48DDF0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x88AF50

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x87A0F0
#define CEditWnd__GetCharIndexPt_x                                 0x87B120
#define CEditWnd__GetDisplayString_x                               0x87A2A0
#define CEditWnd__GetHorzOffset_x                                  0x87A5E0
#define CEditWnd__GetLineForPrintableChar_x                        0x87ABE0
#define CEditWnd__GetSelStartPt_x                                  0x87B3E0
#define CEditWnd__GetSTMLSafeText_x                                0x87A780
#define CEditWnd__PointFromPrintableChar_x                         0x87ACD0
#define CEditWnd__SelectableCharFromPoint_x                        0x87AE50
#define CEditWnd__SetEditable_x                                    0x87A750

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x5182C0
#define CEverQuest__DoTellWindow_x                                 0x51CC20
#define CEverQuest__DropHeldItemOnGround_x                         0x5254B0
#define CEverQuest__dsp_chat_x                                     0x51E3C0
#define CEverQuest__Emote_x                                        0x51E620
#define CEverQuest__EnterZone_x                                    0x5311B0
#define CEverQuest__GetBodyTypeDesc_x                              0x514880
#define CEverQuest__GetClassDesc_x                                 0x513FE0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5145E0
#define CEverQuest__GetDeityDesc_x                                 0x515190
#define CEverQuest__GetLangDesc_x                                  0x514C10
#define CEverQuest__GetRaceDesc_x                                  0x514F00
#define CEverQuest__InterpretCmd_x                                 0x51EF00
#define CEverQuest__LeftClickedOnPlayer_x                          0x5354E0
#define CEverQuest__LMouseUp_x                                     0x5376A0
#define CEverQuest__RightClickedOnPlayer_x                         0x535F50
#define CEverQuest__RMouseUp_x                                     0x536F00
#define CEverQuest__SetGameState_x                                 0x518970
#define CEverQuest__UPCNotificationFlush_x                         0x51FE90

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x66E8D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x66E930
#define CGaugeWnd__Draw_x                                          0x66ED60

// CGuild
#define CGuild__FindMemberByName_x                                 0x423D80

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x68BA10

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x696FC0
#define CInvSlotMgr__MoveItem_x                                    0x697EE0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6963B0
#define CInvSlot__SliderComplete_x                                 0x6943D0
#define CInvSlot__GetItemBase_x                                    0x6938D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x698C70

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x75E080
#define CItemDisplayWnd__UpdateStrings_x                           0x699FA0

// CLabel 
#define CLabel__Draw_x                                             0x6B3EE0

// CListWnd 
#define CListWnd__AddColumn_x                                      0x857A20
#define CListWnd__AddColumn1_x                                     0x857200
#define CListWnd__AddLine_x                                        0x856CB0
#define CListWnd__AddString_x                                      0x856EC0
#define CListWnd__CalculateFirstVisibleLine_x                      0x853D70
#define CListWnd__CalculateVSBRange_x                              0x855EB0
#define CListWnd__ClearAllSel_x                                    0x853020
#define CListWnd__CloseAndUpdateEditWindow_x                       0x856880
#define CListWnd__Compare_x                                        0x854880
#define CListWnd__Draw_x                                           0x855B10
#define CListWnd__DrawColumnSeparators_x                           0x8559A0
#define CListWnd__DrawHeader_x                                     0x853330
#define CListWnd__DrawItem_x                                       0x854ED0
#define CListWnd__DrawLine_x                                       0x855640
#define CListWnd__DrawSeparator_x                                  0x855A40
#define CListWnd__EnsureVisible_x                                  0x853ED0
#define CListWnd__ExtendSel_x                                      0x854DE0
#define CListWnd__GetColumnMinWidth_x                              0x852A40
#define CListWnd__GetColumnWidth_x                                 0x852960
#define CListWnd__GetCurSel_x                                      0x852230
#define CListWnd__GetItemAtPoint_x                                 0x854170
#define CListWnd__GetItemAtPoint1_x                                0x8541E0
#define CListWnd__GetItemData_x                                    0x852470
#define CListWnd__GetItemHeight_x                                  0x8539C0
#define CListWnd__GetItemIcon_x                                    0x852650
#define CListWnd__GetItemRect_x                                    0x853FB0
#define CListWnd__GetItemText_x                                    0x852500
#define CListWnd__GetSelList_x                                     0x8570F0
#define CListWnd__GetSeparatorRect_x                               0x8547A0
#define CListWnd__RemoveLine_x                                     0x8570A0
#define CListWnd__SetColors_x                                      0x852290
#define CListWnd__SetColumnJustification_x                         0x852D10
#define CListWnd__SetColumnWidth_x                                 0x8529F0
#define CListWnd__SetCurSel_x                                      0x852270
#define CListWnd__SetItemColor_x                                   0x856560
#define CListWnd__SetItemData_x                                    0x8530D0
#define CListWnd__SetItemText_x                                    0x8563A0
#define CListWnd__ShiftColumnSeparator_x                           0x856230
#define CListWnd__Sort_x                                           0x857B80
#define CListWnd__ToggleSel_x                                      0x852FA0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6CED40

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6EE9F0
#define CMerchantWnd__RequestBuyItem_x                             0x6F4E20
#define CMerchantWnd__RequestSellItem_x                            0x71BCF0
#define CMerchantWnd__SelectBuySellSlot_x                          0x6EECA0

// CObfuscator
#define CObfuscator__doit_x                                        0x7CF250

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x86EF20
#define CSidlManager__CreateLabel_x                                0x7546E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x61E100
#define CSidlScreenWnd__CalculateVSBRange_x                        0x61E030
#define CSidlScreenWnd__ConvertToRes_x                             0x88AE30
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x85CAB0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x85DE50
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x85DF00
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x85D3D0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x85C590
#define CSidlScreenWnd__EnableIniStorage_x                         0x85BCE0
#define CSidlScreenWnd__GetSidlPiece_x                             0x85C780
#define CSidlScreenWnd__Init1_x                                    0x85DB20
#define CSidlScreenWnd__LoadIniInfo_x                              0x85CB60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x85BEA0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x85D620
#define CSidlScreenWnd__StoreIniInfo_x                             0x85B850
#define CSidlScreenWnd__StoreIniVis_x                              0x85BC70
#define CSidlScreenWnd__WndNotification_x                          0x85D8A0
#define CSidlScreenWnd__GetChildItem_x                             0x85BDB0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5BA100
#define CSkillMgr__GetSkillCap_x                                   0x5BA180

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x894E00
#define CSliderWnd__SetValue_x                                     0x894FD0
#define CSliderWnd__SetNumTicks_x                                  0x895750

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x75BAE0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8855E0
#define CStmlWnd__CalculateHSBRange_x                              0x87DD40
#define CStmlWnd__CalculateVSBRange_x                              0x87DDD0
#define CStmlWnd__CanBreakAtCharacter_x                            0x87DF50
#define CStmlWnd__FastForwardToEndOfTag_x                          0x87E830
#define CStmlWnd__ForceParseNow_x                                  0x885F30
#define CStmlWnd__GetNextTagPiece_x                                0x87E730
#define CStmlWnd__GetSTMLText_x                                    0x654790
#define CStmlWnd__GetVisibleText_x                                 0x87F280
#define CStmlWnd__InitializeWindowVariables_x                      0x881460
#define CStmlWnd__MakeStmlColorTag_x                               0x87CF90
#define CStmlWnd__MakeWndNotificationTag_x                         0x87CFF0
#define CStmlWnd__SetSTMLText_x                                    0x882CC0
#define CStmlWnd__StripFirstSTMLLines_x                            0x885280
#define CStmlWnd__UpdateHistoryString_x                            0x8801C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x88C630
#define CTabWnd__DrawCurrentPage_x                                 0x88BEA0
#define CTabWnd__DrawTab_x                                         0x88BC60
#define CTabWnd__GetCurrentPage_x                                  0x88C270
#define CTabWnd__GetPageInnerRect_x                                0x88B950
#define CTabWnd__GetTabInnerRect_x                                 0x88BB50
#define CTabWnd__GetTabRect_x                                      0x88BA20
#define CTabWnd__InsertPage_x                                      0x88C920
#define CTabWnd__SetPage_x                                         0x88C2A0
#define CTabWnd__SetPageRect_x                                     0x88C570
#define CTabWnd__UpdatePage_x                                      0x88C8C0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41F920

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x888A10

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8917C0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x850240

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x55BE80
#define CXStr__CXStr1_x                                            0x4DAC50
#define CXStr__CXStr3_x                                            0x804C40
#define CXStr__dCXStr_x                                            0x55C1D0
#define CXStr__operator_equal_x                                    0x804DB0
#define CXStr__operator_equal1_x                                   0x804E00
#define CXStr__operator_plus_equal1_x                              0x805EE0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8619E0
#define CXWnd__Center_x                                            0x867BF0
#define CXWnd__ClrFocus_x                                          0x8615C0
#define CXWnd__DoAllDrawing_x                                      0x867860
#define CXWnd__DrawChildren_x                                      0x8679F0
#define CXWnd__DrawColoredRect_x                                   0x861D90
#define CXWnd__DrawTooltip_x                                       0x862040
#define CXWnd__DrawTooltipAtPoint_x                                0x8667D0
#define CXWnd__GetBorderFrame_x                                    0x862470
#define CXWnd__GetChildWndAt_x                                     0x8657A0
#define CXWnd__GetClientClipRect_x                                 0x862250
#define CXWnd__GetScreenClipRect_x                                 0x866ED0
#define CXWnd__GetScreenRect_x                                     0x862620
#define CXWnd__GetTooltipRect_x                                    0x861ED0
#define CXWnd__GetWindowTextA_x                                    0x411190
#define CXWnd__IsActive_x                                          0x874E30
#define CXWnd__IsDescendantOf_x                                    0x8623C0
#define CXWnd__IsReallyVisible_x                                   0x865780
#define CXWnd__IsType_x                                            0x88E000
#define CXWnd__Move_x                                              0x864E60
#define CXWnd__Move1_x                                             0x867500
#define CXWnd__ProcessTransition_x                                 0x861980
#define CXWnd__Refade_x                                            0x861760
#define CXWnd__Resize_x                                            0x8626F0
#define CXWnd__Right_x                                             0x866CD0
#define CXWnd__SetFocus_x                                          0x863FB0
#define CXWnd__SetFont_x                                           0x861610
#define CXWnd__SetKeyTooltip_x                                     0x862960
#define CXWnd__SetMouseOver_x                                      0x867200
#define CXWnd__StartFade_x                                         0x861A30
#define CXWnd__GetChildItem_x                                      0x867140

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x876700
#define CXWndManager__DrawWindows_x                                0x876350
#define CXWndManager__GetKeyboardFlags_x                           0x874970
#define CXWndManager__HandleKeyboardMsg_x                          0x8752B0
#define CXWndManager__RemoveWnd_x                                  0x874FC0

// CDBStr
#define CDBStr__GetString_x                                        0x485A00

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8CF2E0
#define EQ_Character__CastSpell_x                                  0x43A8E0
#define EQ_Character__Cur_HP_x                                     0x449F20
#define EQ_Character__GetAACastingTimeModifier_x                   0x433760
#define EQ_Character__GetCharInfo2_x                               0x7DA080
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42C9B0
#define EQ_Character__GetFocusRangeModifier_x                      0x42CB90
#define EQ_Character__Max_Endurance_x                              0x5810A0
#define EQ_Character__Max_HP_x                                     0x4440C0
#define EQ_Character__Max_Mana_x                                   0x580EE0
#define EQ_Character__doCombatAbility_x                            0x57F940
#define EQ_Character__UseSkill_x                                   0x45B3F0
#define EQ_Character__GetConLevel_x                                0x576F60
#define EQ_Character__IsExpansionFlag_x                            0x4106C0
#define EQ_Character__TotalEffect_x                                0x438A40

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x554060
#define EQ_Item__CreateItemTagString_x                             0x7BABD0
#define EQ_Item__IsStackable_x                                     0x7AF330

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A49E0
#define EQ_LoadingS__Array_x                                       0xAC5330

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x585370
#define EQ_PC__GetAltAbilityIndex_x                                0x7C3310
#define EQ_PC__GetCombatAbility_x                                  0x7C33A0
#define EQ_PC__GetCombatAbilityTimer_x                             0x7C3450
#define EQ_PC__GetItemTimerValue_x                                 0x57F680
#define EQ_PC__HasLoreItem_x                                       0x57A0F0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4DAD20
#define EQItemList__add_item_x                                     0x4DAC60
#define EQItemList__delete_item_x                                  0x4DB120
#define EQItemList__FreeItemList_x                                 0x4DB020

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x484EF0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x58AF40
#define EQPlayer__dEQPlayer_x                                      0x58FAC0
#define EQPlayer__DoAttack_x                                       0x5A4140
#define EQPlayer__EQPlayer_x                                       0x595240
#define EQPlayer__SetNameSpriteState_x                             0x58D380
#define EQPlayer__SetNameSpriteTint_x                              0x58AFB0
#define EQPlayer__IsBodyType_j_x                                   0x8CEB80
#define EQPlayer__IsTargetable_x                                   0x8CEE50

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x598750
#define EQPlayerManager__GetSpawnByName_x                          0x598BB0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x55A1B0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x55A1F0
#define KeypressHandler__ClearCommandStateArray_x                  0x559D90
#define KeypressHandler__HandleKeyDown_x                           0x5586F0
#define KeypressHandler__HandleKeyUp_x                             0x558A10
#define KeypressHandler__SaveKeymapping_x                          0x559E60

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6C71A0
#define MapViewMap__SaveEx_x                                       0x6CAA50

#define PlayerPointManager__GetAltCurrency_x                       0x7D4260

// StringTable 
#define StringTable__getString_x                                   0x7CF4F0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x583C60
