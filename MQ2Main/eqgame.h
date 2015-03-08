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
#define __ExpectedVersionDate                                     "Feb 20 2015"
#define __ExpectedVersionTime                                     "15:14:15"
#define __ActualVersionDate_x                                      0xA567E8
#define __ActualVersionTime_x                                      0xA567F4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5739C0
#define __MemChecker1_x                                            0x83B150
#define __MemChecker2_x                                            0x60AD70
#define __MemChecker3_x                                            0x60ACC0
#define __MemChecker4_x                                            0x7BF660
#define __EncryptPad0_x                                            0xBC5648
#define __EncryptPad1_x                                            0xD488D8
#define __EncryptPad2_x                                            0xC0E2B8
#define __EncryptPad3_x                                            0xC0DEB8
#define __EncryptPad4_x                                            0xD25000
#define __AC1_x                                                    0x77C705
#define __AC2_x                                                    0x52A017
#define __AC3_x                                                    0x53E770
#define __AC4_x                                                    0x544AA0
#define __AC5_x                                                    0x55080E
#define __AC6_x                                                    0x554342
#define __AC7_x                                                    0x54AEFC
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10FA1F8
#define DI8__Keyboard_x                                            0x10FA1FC
#define DI8__Mouse_x                                               0x10FA200
#define __AltTimerReady_x                                          0xF59CC1
#define __Attack_x                                                 0xFECD9B
#define __Autofire_x                                               0xFECD9C
#define __BindList_x                                               0xB88388
#define __bCommandEnabled_x                                        0xF57DD0
#define __Clicks_x                                                 0xF68908
#define __CommandList_x                                            0xB8C620
#define __CurrentMapLabel_x                                        0x10FFC50
#define __CurrentSocial_x                                          0xB4CABC
#define __DoAbilityList_x                                          0xF9F050
#define __do_loot_x                                                0x4F19E0
#define __DrawHandler_x                                            0x176484C
#define __GroupCount_x                                             0xF5939A

#define __Guilds_x                                                 0xF5EE88
#define __gWorld_x                                                 0xF5B854
#define __HotkeyPage_x                                             0xFE5A50
#define __HWnd_x                                                   0xFF2100
#define __InChatMode_x                                             0xF68834
#define __LastTell_x                                               0xF6A758
#define __LMouseHeldTime_x                                         0xF68974
#define __Mouse_x                                                  0x10FA204
#define __MouseLook_x                                              0xF688CE
#define __MouseEventTime_x                                         0xFED58C
#define __NetStatusToggle_x                                        0xF688D1
#define __PCNames_x                                                0xF69D88
#define __RangeAttackReady_x                                       0xF69A58
#define __RMouseHeldTime_x                                         0xF68970
#define __RunWalkState_x                                           0xF68838
#define __ScreenMode_x                                             0xEA7D90
#define __ScreenX_x                                                0xF687EC
#define __ScreenY_x                                                0xF687E8
#define __ScreenXMax_x                                             0xF687F0
#define __ScreenYMax_x                                             0xF687F4
#define __ServerHost_x                                             0xF592E4
#define __ServerName_x                                             0xF9F010
#define __ShiftKeyDown_x                                           0xF68EDC
#define __ShowNames_x                                              0xF69C2C
#define __Socials_x                                                0xF9F110
#define __SubscriptionType_x                                       0x112BFE0
#define __TargetAggroHolder_x                                      0x1101E8C
#define __GroupAggro_x                                             0x1101ECC
#define __LoginName_x                                              0xFF0CD8
#define __Inviter_x                                                0xFECD18


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF5B940
#define instEQZoneInfo_x                                           0xF68AC4
#define instKeypressHandler_x                                      0xFED570
#define pinstActiveBanker_x                                        0xF5B8F8
#define pinstActiveCorpse_x                                        0xF5B8FC
#define pinstActiveGMaster_x                                       0xF5B900
#define pinstActiveMerchant_x                                      0xF5B8F4
#define pinstAggroInfo_x                                           0xD6C378
#define pinstAltAdvManager_x                                       0xEA8E68
#define pinstAuraMgr_x                                             0xD76240
#define pinstBandageTarget_x                                       0xF5B8E0
#define pinstCamActor_x                                            0xEA8774
#define pinstCDBStr_x                                              0xEA7D24
#define pinstCDisplay_x                                            0xF5B908
#define pinstCEverQuest_x                                          0x10FA378
#define pinstCharData_x                                            0xF5B8C4
#define pinstCharSpawn_x                                           0xF5B8EC
#define pinstControlledMissile_x                                   0xF5B8C0
#define pinstControlledPlayer_x                                    0xF5B8EC
#define pinstCSidlManager_x                                        0x1763C78
#define pinstCXWndManager_x                                        0x1763C70
#define instDynamicZone_x                                          0xF68680
#define pinstDZMember_x                                            0xF68790
#define pinstDZTimerInfo_x                                         0xF68794
#define pinstEQItemList_x                                          0xF5801C
#define instEQMisc_x                                               0xB68E88
#define pinstEQSoundManager_x                                      0xEA9168
#define instExpeditionLeader_x                                     0xF686CA
#define instExpeditionName_x                                       0xF6870A
#define pinstGroup_x                                               0xF59396
#define pinstImeManager_x                                          0x1763C7C
#define pinstLocalPlayer_x                                         0xF5B8D8
#define pinstMercenaryData_x                                       0xFEDBC0
#define pinstMercAltAbilities_x                                    0xEA9088
#define pinstModelPlayer_x                                         0xF5B904
#define pinstPCData_x                                              0xF5B8C4
#define pinstSkillMgr_x                                            0xFEE9F8
#define pinstSpawnManager_x                                        0xFEE2E0
#define pinstSpellManager_x                                        0xFEEB40
#define pinstSpellSets_x                                           0xFE5AB4
#define pinstStringTable_x                                         0xF5B86C
#define pinstSwitchManager_x                                       0xF58F28
#define pinstTarget_x                                              0xF5B8F0
#define pinstTargetObject_x                                        0xF5B8C8
#define pinstTargetSwitch_x                                        0xF5B8CC
#define pinstTaskMember_x                                          0xEA7C70
#define pinstTrackTarget_x                                         0xF5B8E4
#define pinstTradeTarget_x                                         0xF5B8D4
#define instTributeActive_x                                        0xB68EAD
#define pinstViewActor_x                                           0xEA8770
#define pinstWorldData_x                                           0xF5B8A8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD6C858
#define pinstCAudioTriggersWindow_x                                0xD6C6E8
#define pinstCCharacterSelect_x                                    0xEA861C
#define pinstCFacePick_x                                           0xEA83CC
#define pinstCNoteWnd_x                                            0xEA85D4
#define pinstCBookWnd_x                                            0xEA85DC
#define pinstCPetInfoWnd_x                                         0xEA85E0
#define pinstCTrainWnd_x                                           0xEA85E4
#define pinstCSkillsWnd_x                                          0xEA85E8
#define pinstCSkillsSelectWnd_x                                    0xEA85EC
#define pinstCCombatSkillSelectWnd_x                               0xEA85F0
#define pinstCFriendsWnd_x                                         0xEA85F4
#define pinstCAuraWnd_x                                            0xEA85F8
#define pinstCRespawnWnd_x                                         0xEA85FC
#define pinstCBandolierWnd_x                                       0xEA8600
#define pinstCPotionBeltWnd_x                                      0xEA8604
#define pinstCAAWnd_x                                              0xEA8608
#define pinstCGroupSearchFiltersWnd_x                              0xEA860C
#define pinstCLoadskinWnd_x                                        0xEA8610
#define pinstCAlarmWnd_x                                           0xEA8614
#define pinstCMusicPlayerWnd_x                                     0xEA8618
#define pinstCMailWnd_x                                            0xEA8620
#define pinstCMailCompositionWnd_x                                 0xEA8624
#define pinstCMailAddressBookWnd_x                                 0xEA8628
#define pinstCRaidWnd_x                                            0xEA8630
#define pinstCRaidOptionsWnd_x                                     0xEA8634
#define pinstCBreathWnd_x                                          0xEA8638
#define pinstCMapViewWnd_x                                         0xEA863C
#define pinstCMapToolbarWnd_x                                      0xEA8640
#define pinstCEditLabelWnd_x                                       0xEA8644
#define pinstCTargetWnd_x                                          0xEA8648
#define pinstCColorPickerWnd_x                                     0xEA864C
#define pinstCPlayerWnd_x                                          0xEA8650
#define pinstCOptionsWnd_x                                         0xEA8654
#define pinstCBuffWindowNORMAL_x                                   0xEA8658
#define pinstCBuffWindowSHORT_x                                    0xEA865C
#define pinstCharacterCreation_x                                   0xEA8660
#define pinstCCursorAttachment_x                                   0xEA8664
#define pinstCCastingWnd_x                                         0xEA8668
#define pinstCCastSpellWnd_x                                       0xEA866C
#define pinstCSpellBookWnd_x                                       0xEA8670
#define pinstCInventoryWnd_x                                       0xEA8674
#define pinstCBankWnd_x                                            0xEA8678
#define pinstCQuantityWnd_x                                        0xEA867C
#define pinstCLootWnd_x                                            0xEA8680
#define pinstCActionsWnd_x                                         0xEA8684
#define pinstCCombatAbilityWnd_x                                   0xEA8688
#define pinstCMerchantWnd_x                                        0xEA868C
#define pinstCTradeWnd_x                                           0xEA8690
#define pinstCSelectorWnd_x                                        0xEA8694
#define pinstCBazaarWnd_x                                          0xEA8698
#define pinstCBazaarSearchWnd_x                                    0xEA869C
#define pinstCGiveWnd_x                                            0xEA86B8
#define pinstCTrackingWnd_x                                        0xEA86C0
#define pinstCInspectWnd_x                                         0xEA86C4
#define pinstCSocialEditWnd_x                                      0xEA86C8
#define pinstCFeedbackWnd_x                                        0xEA86CC
#define pinstCBugReportWnd_x                                       0xEA86D0
#define pinstCVideoModesWnd_x                                      0xEA86D4
#define pinstCTextEntryWnd_x                                       0xEA86DC
#define pinstCFileSelectionWnd_x                                   0xEA86E0
#define pinstCCompassWnd_x                                         0xEA86E4
#define pinstCPlayerNotesWnd_x                                     0xEA86E8
#define pinstCGemsGameWnd_x                                        0xEA86EC
#define pinstCTimeLeftWnd_x                                        0xEA86F0
#define pinstCPetitionQWnd_x                                       0xEA8704
#define pinstCSoulmarkWnd_x                                        0xEA8708
#define pinstCStoryWnd_x                                           0xEA870C
#define pinstCJournalTextWnd_x                                     0xEA8710
#define pinstCJournalCatWnd_x                                      0xEA8714
#define pinstCBodyTintWnd_x                                        0xEA8718
#define pinstCServerListWnd_x                                      0xEA871C
#define pinstCAvaZoneWnd_x                                         0xEA8728
#define pinstCBlockedBuffWnd_x                                     0xEA872C
#define pinstCBlockedPetBuffWnd_x                                  0xEA8730
#define pinstCInvSlotMgr_x                                         0xEA8768
#define pinstCContainerMgr_x                                       0xEA876C
#define pinstCAdventureLeaderboardWnd_x                            0x10FAD28
#define pinstCAdventureRequestWnd_x                                0x10FADA0
#define pinstCAltStorageWnd_x                                      0x10FB080
#define pinstCAdventureStatsWnd_x                                  0x10FAE18
#define pinstCBarterMerchantWnd_x                                  0x10FBC68
#define pinstCBarterSearchWnd_x                                    0x10FBCE0
#define pinstCBarterWnd_x                                          0x10FBD58
#define pinstCChatManager_x                                        0x10FC3E8
#define pinstCDynamicZoneWnd_x                                     0x10FC898
#define pinstCEQMainWnd_x                                          0x10FCA30
#define pinstCFellowshipWnd_x                                      0x10FC82C
#define pinstCFindLocationWnd_x                                    0x10FCD00
#define pinstCGroupSearchWnd_x                                     0x10FCFD0
#define pinstCGroupWnd_x                                           0x10FD048
#define pinstCGuildBankWnd_x                                       0x10FD0C0
#define pinstCGuildMgmtWnd_x                                       0x10FF1B0
#define pinstCHotButtonWnd_x                                       0x10FF27C
#define pinstCHotButtonWnd1_x                                      0x10FF27C
#define pinstCHotButtonWnd2_x                                      0x10FF280
#define pinstCHotButtonWnd3_x                                      0x10FF284
#define pinstCHotButtonWnd4_x                                      0x10FF2A8
#define pinstCItemDisplayManager_x                                 0x10FF5A0
#define pinstCItemExpTransferWnd_x                                 0x10FF61C
#define pinstCLFGuildWnd_x                                         0x10FF8F8
#define pinstCMIZoneSelectWnd_x                                    0x10FFEE0
#define pinstCConfirmationDialog_x                                 0x11005E8
#define pinstCPopupWndManager_x                                    0x11005E8
#define pinstCProgressionSelectionWnd_x                            0x11006D8
#define pinstCPvPStatsWnd_x                                        0x11007C8
#define pinstCSystemInfoDialogBox_x                                0x1100ED0
#define pinstCTaskWnd_x                                            0x1102298
#define pinstCTaskSomething_x                                      0xD76818
#define pinstCTaskTemplateSelectWnd_x                              0x1102220
#define pinstCTipWndOFDAY_x                                        0x11024F0
#define pinstCTipWndCONTEXT_x                                      0x11024F4
#define pinstCTitleWnd_x                                           0x1102570
#define pinstCContextMenuManager_x                                 0x176388C
#define pinstCVoiceMacroWnd_x                                      0xFEF1A8
#define pinstCHtmlWnd_x                                            0xFEF2A0
#define pinstIconCache_x                                           0x10FCA04
#define pinstCTradeskillWnd_x                                      0x1102670

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x509350
#define __ConvertItemTags_x                                        0x4F65D0
#define __ExecuteCmd_x                                             0x4E11D0
#define __EQGetTime_x                                              0x83BCB0
#define __get_melee_range_x                                        0x4E7EA0
#define __GetGaugeValueFromEQ_x                                    0x77B450
#define __GetLabelFromEQ_x                                         0x77C690
#define __ToggleMount_x                                            0x6A5070
#define __GetXTargetType_x                                         0x8F9710
#define __LoadFrontEnd_x                                           0x60A420
#define __NewUIINI_x                                               0x77AD50
#define __ProcessGameEvents_x                                      0x54CC60
#define __ProcessMouseEvent_x                                      0x54C400
#define CrashDetected_x                                            0x60BEF0
#define wwsCrashReportCheckForUploader_x                           0x7D06F0
#define DrawNetStatus_x                                            0x5832A0
#define Util__FastTime_x                                           0x83AFC0
#define Expansion_HoT_x                                            0xF69BC4
#define __HelpPath_x                                               0xFED2F8

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A62D0
#define AltAdvManager__IsAbilityReady_x                            0x4A6340
#define AltAdvManager__GetAltAbility_x                             0x4A6700

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4532F0
#define CharacterZoneClient__MakeMeVisible_x                       0x4583B0
// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x639BA0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x647F00

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x562BD0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x662D70
#define CChatManager__InitContextMenu_x                            0x663890

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x88AED0
#define CContextMenu__dCContextMenu_x                              0x88B0E0
#define CContextMenu__AddMenuItem_x                                0x88B0F0
#define CContextMenu__RemoveMenuItem_x                             0x88B3E0
#define CContextMenu__RemoveAllMenuItems_x                         0x88B400
#define CContextMenuManager__AddMenu_x                             0x8916D0
#define CContextMenuManager__RemoveMenu_x                          0x891A10
#define CContextMenuManager__PopupMenu_x                           0x891E60
#define CContextMenuManager__Flush_x                               0x891740

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x821D30
#define CChatService__GetFriendName_x                              0x821D40

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6686E0
#define CChatWindow__Clear_x                                       0x668290
#define CChatWindow__WndNotification_x                             0x668C10

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x89A690
#define CComboWnd__Draw_x                                          0x89A890
#define CComboWnd__GetCurChoice_x                                  0x89A4B0
#define CComboWnd__GetListRect_x                                   0x89AB30
#define CComboWnd__GetTextRect_x                                   0x89A6F0
#define CComboWnd__InsertChoice_x                                  0x89ABA0
#define CComboWnd__SetColors_x                                     0x89A440
#define CComboWnd__SetChoice_x                                     0x89A470

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x671DE0
#define CContainerWnd__vftable_x                                   0xA5FF60

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x494D50
#define CDisplay__GetClickedActor_x                                0x48D8D0
#define CDisplay__GetUserDefinedColor_x                            0x48C190
#define CDisplay__GetWorldFilePath_x                               0x48B5E0
#define CDisplay__is3dON_x                                         0x48A9B0
#define CDisplay__ReloadUI_x                                       0x49FFD0
#define CDisplay__WriteTextHD2_x                                   0x4910F0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8BC540

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8AB0C0
#define CEditWnd__GetCharIndexPt_x                                 0x8AC0F0
#define CEditWnd__GetDisplayString_x                               0x8AB270
#define CEditWnd__GetHorzOffset_x                                  0x8AB5B0
#define CEditWnd__GetLineForPrintableChar_x                        0x8ABBB0
#define CEditWnd__GetSelStartPt_x                                  0x8AC3B0
#define CEditWnd__GetSTMLSafeText_x                                0x8AB750
#define CEditWnd__PointFromPrintableChar_x                         0x8ABCA0
#define CEditWnd__SelectableCharFromPoint_x                        0x8ABE20
#define CEditWnd__SetEditable_x                                    0x8AB720

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x52A760
#define CEverQuest__DoTellWindow_x                                 0x530160
#define CEverQuest__DropHeldItemOnGround_x                         0x538BF0
#define CEverQuest__dsp_chat_x                                     0x531900
#define CEverQuest__Emote_x                                        0x531B60
#define CEverQuest__EnterZone_x                                    0x5452C0
#define CEverQuest__GetBodyTypeDesc_x                              0x527090
#define CEverQuest__GetClassDesc_x                                 0x52CCD0
#define CEverQuest__GetClassThreeLetterCode_x                      0x52D2D0
#define CEverQuest__GetDeityDesc_x                                 0x527970
#define CEverQuest__GetLangDesc_x                                  0x527420
#define CEverQuest__GetRaceDesc_x                                  0x52D490
#define CEverQuest__InterpretCmd_x                                 0x532440
#define CEverQuest__LeftClickedOnPlayer_x                          0x549360
#define CEverQuest__LMouseUp_x                                     0x54B450
#define CEverQuest__RightClickedOnPlayer_x                         0x549E60
#define CEverQuest__RMouseUp_x                                     0x54AEB0
#define CEverQuest__SetGameState_x                                 0x52AE10
#define CEverQuest__UPCNotificationFlush_x                         0x5335E0
#define CEverQuest__IssuePetCommand_x                              0x533140

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6829E0
#define CGaugeWnd__CalcLinesFillRect_x                             0x682A40
#define CGaugeWnd__Draw_x                                          0x682E70

// CGuild
#define CGuild__FindMemberByName_x                                 0x424C30

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69FAE0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6AD880
#define CInvSlotMgr__MoveItem_x                                    0x6AE7C0
#define CInvSlotMgr__SelectSlot_x                                  0x6AD930

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6ACD20
#define CInvSlot__SliderComplete_x                                 0x6AA6F0
#define CInvSlot__GetItemBase_x                                    0x6A9B70

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6AF960

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x777F40
#define CItemDisplayWnd__UpdateStrings_x                           0x6B0C90

// CLabel 
#define CLabel__Draw_x                                             0x6CB9A0

// CListWnd
#define CListWnd__CListWnd_x                                       0x887540
#define CListWnd__dCListWnd_x                                      0x8885C0
#define CListWnd__AddColumn_x                                      0x888560
#define CListWnd__AddColumn1_x                                     0x887D50
#define CListWnd__AddLine_x                                        0x887800
#define CListWnd__AddString_x                                      0x887A10
#define CListWnd__CalculateFirstVisibleLine_x                      0x884870
#define CListWnd__CalculateVSBRange_x                              0x8869F0
#define CListWnd__ClearAllSel_x                                    0x883B30
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8873D0
#define CListWnd__Compare_x                                        0x885370
#define CListWnd__Draw_x                                           0x886600
#define CListWnd__DrawColumnSeparators_x                           0x886490
#define CListWnd__DrawHeader_x                                     0x883E40
#define CListWnd__DrawItem_x                                       0x8859C0
#define CListWnd__DrawLine_x                                       0x886130
#define CListWnd__DrawSeparator_x                                  0x886530
#define CListWnd__EnsureVisible_x                                  0x8849D0
#define CListWnd__ExtendSel_x                                      0x8858D0
#define CListWnd__GetColumnMinWidth_x                              0x883550
#define CListWnd__GetColumnWidth_x                                 0x883470
#define CListWnd__GetCurSel_x                                      0x882C50
#define CListWnd__GetItemAtPoint_x                                 0x884C70
#define CListWnd__GetItemAtPoint1_x                                0x884CE0
#define CListWnd__GetItemData_x                                    0x882F90
#define CListWnd__GetItemHeight_x                                  0x8844D0
#define CListWnd__GetItemIcon_x                                    0x883170
#define CListWnd__GetItemRect_x                                    0x884AB0
#define CListWnd__GetItemText_x                                    0x883020
#define CListWnd__GetSelList_x                                     0x887C40
#define CListWnd__GetSeparatorRect_x                               0x885290
#define CListWnd__RemoveLine_x                                     0x887BF0
#define CListWnd__SetColors_x                                      0x882DA0
#define CListWnd__SetColumnJustification_x                         0x883820
#define CListWnd__SetColumnWidth_x                                 0x883500
#define CListWnd__SetCurSel_x                                      0x882C90
#define CListWnd__SetItemColor_x                                   0x8870B0
#define CListWnd__SetItemData_x                                    0x883BE0
#define CListWnd__SetItemText_x                                    0x886EF0
#define CListWnd__ShiftColumnSeparator_x                           0x886D80
#define CListWnd__Sort_x                                           0x8886C0
#define CListWnd__ToggleSel_x                                      0x883AB0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6E4EE0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x706100
#define CMerchantWnd__RequestBuyItem_x                             0x70CF60
#define CMerchantWnd__RequestSellItem_x                            0x70D9D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7063B0
#define CMerchantWnd__SelectBuySellSlot_x                          0x705610
#define CMerchantWnd__ActualSelect_x                               0x709E80

// CObfuscator
#define CObfuscator__doit_x                                        0x8020A0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x89FE40
#define CSidlManager__CreateLabel_x                                0x76DF60

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x630EC0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x630CC0
#define CSidlScreenWnd__ConvertToRes_x                             0x8BC420
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x88D6D0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x88EBB0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x88EC60
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x88E130
#define CSidlScreenWnd__DrawSidlPiece_x                            0x88D1B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x88C8F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x88D3A0
#define CSidlScreenWnd__Init1_x                                    0x88E890
#define CSidlScreenWnd__LoadIniInfo_x                              0x88D780
#define CSidlScreenWnd__LoadIniListWnd_x                           0x88CAB0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x88E380
#define CSidlScreenWnd__StoreIniInfo_x                             0x88C3C0
#define CSidlScreenWnd__StoreIniVis_x                              0x88C880
#define CSidlScreenWnd__WndNotification_x                          0x88E610
#define CSidlScreenWnd__GetChildItem_x                             0x88C9C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x893660

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5CC740
#define CSkillMgr__GetSkillCap_x                                   0x5CC8E0
#define CSkillMgr__GetNameToken_x                                  0x5CC3B0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8C6510
#define CSliderWnd__SetValue_x                                     0x8C66E0
#define CSliderWnd__SetNumTicks_x                                  0x8C6E60

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x775BE0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8B6810
#define CStmlWnd__CalculateHSBRange_x                              0x8AED20
#define CStmlWnd__CalculateVSBRange_x                              0x8AEDB0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8AEF30
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8AF810
#define CStmlWnd__ForceParseNow_x                                  0x8B7160
#define CStmlWnd__GetNextTagPiece_x                                0x8AF710
#define CStmlWnd__GetSTMLText_x                                    0x667B30
#define CStmlWnd__GetVisibleText_x                                 0x8B0260
#define CStmlWnd__InitializeWindowVariables_x                      0x8B25F0
#define CStmlWnd__MakeStmlColorTag_x                               0x8AE020
#define CStmlWnd__MakeWndNotificationTag_x                         0x8AE080
#define CStmlWnd__SetSTMLText_x                                    0x8B3E50
#define CStmlWnd__StripFirstSTMLLines_x                            0x8B64B0
#define CStmlWnd__UpdateHistoryString_x                            0x8B11A0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8BDCF0
#define CTabWnd__DrawCurrentPage_x                                 0x8BD560
#define CTabWnd__DrawTab_x                                         0x8BD320
#define CTabWnd__GetCurrentPage_x                                  0x8BD930
#define CTabWnd__GetPageInnerRect_x                                0x8BD010
#define CTabWnd__GetTabInnerRect_x                                 0x8BD210
#define CTabWnd__GetTabRect_x                                      0x8BD0E0
#define CTabWnd__InsertPage_x                                      0x8BDFE0
#define CTabWnd__SetPage_x                                         0x8BD960
#define CTabWnd__SetPageRect_x                                     0x8BDC30
#define CTabWnd__UpdatePage_x                                      0x8BDF80

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4209B0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B9C80

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8C2ED0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x880CA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x411980
#define CXStr__CXStr1_x                                            0x4027D0
#define CXStr__CXStr3_x                                            0x838050
#define CXStr__dCXStr_x                                            0x778FF0
#define CXStr__operator_equal_x                                    0x8381C0
#define CXStr__operator_equal1_x                                   0x838210
#define CXStr__operator_plus_equal1_x                              0x8392F0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x892890
#define CXWnd__Center_x                                            0x898990
#define CXWnd__ClrFocus_x                                          0x892460
#define CXWnd__DoAllDrawing_x                                      0x8985E0
#define CXWnd__DrawChildren_x                                      0x898780
#define CXWnd__DrawColoredRect_x                                   0x892C50
#define CXWnd__DrawTooltip_x                                       0x892F00
#define CXWnd__DrawTooltipAtPoint_x                                0x897580
#define CXWnd__GetBorderFrame_x                                    0x893350
#define CXWnd__GetChildWndAt_x                                     0x899340
#define CXWnd__GetClientClipRect_x                                 0x893110
#define CXWnd__GetScreenClipRect_x                                 0x897C80
#define CXWnd__GetScreenRect_x                                     0x893500
#define CXWnd__GetTooltipRect_x                                    0x892D90
#define CXWnd__GetWindowTextA_x                                    0x4119C0
#define CXWnd__IsActive_x                                          0x8A5D90
#define CXWnd__IsDescendantOf_x                                    0x8932A0
#define CXWnd__IsReallyVisible_x                                   0x8965C0
#define CXWnd__IsType_x                                            0x8BF6B0
#define CXWnd__Move_x                                              0x895D30
#define CXWnd__Move1_x                                             0x8982B0
#define CXWnd__ProcessTransition_x                                 0x892840
#define CXWnd__Refade_x                                            0x892610
#define CXWnd__Resize_x                                            0x8935C0
#define CXWnd__Right_x                                             0x897A80
#define CXWnd__SetFocus_x                                          0x894E80
#define CXWnd__SetFont_x                                           0x8924B0
#define CXWnd__SetKeyTooltip_x                                     0x893830
#define CXWnd__SetMouseOver_x                                      0x897FB0
#define CXWnd__StartFade_x                                         0x8928E0
#define CXWnd__GetChildItem_x                                      0x897F00

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A76C0
#define CXWndManager__DrawWindows_x                                0x8A7300
#define CXWndManager__GetKeyboardFlags_x                           0x8A58C0
#define CXWndManager__HandleKeyboardMsg_x                          0x8A6220
#define CXWndManager__RemoveWnd_x                                  0x8A5F20

// CDBStr
#define CDBStr__GetString_x                                        0x488DE0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x43CCB0
#define EQ_Character__Cur_HP_x                                     0x4529C0
#define EQ_Character__GetAACastingTimeModifier_x                   0x435D80
#define EQ_Character__GetCharInfo2_x                               0x80C750
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42E050
#define EQ_Character__GetFocusRangeModifier_x                      0x42E230
#define EQ_Character__Max_Endurance_x                              0x595200
#define EQ_Character__Max_HP_x                                     0x448CB0
#define EQ_Character__Max_Mana_x                                   0x595030
#define EQ_Character__doCombatAbility_x                            0x592620
#define EQ_Character__UseSkill_x                                   0x45D4E0
#define EQ_Character__GetConLevel_x                                0x587970
#define EQ_Character__IsExpansionFlag_x                            0x410EC0
#define EQ_Character__TotalEffect_x                                0x43ADE0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x568320
#define EQ_Item__CreateItemTagString_x                             0x7ECAE0
#define EQ_Item__IsStackable_x                                     0x7E1030
#define EQ_Item__GetImageNum_x                                     0x7E3D70

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A8400
#define EQ_LoadingS__Array_x                                       0xB769F8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x596990
#define EQ_PC__GetAltAbilityIndex_x                                0x7F4E30
#define EQ_PC__GetCombatAbility_x                                  0x7F4EC0
#define EQ_PC__GetCombatAbilityTimer_x                             0x7F4F70
#define EQ_PC__GetItemTimerValue_x                                 0x590410
#define EQ_PC__HasLoreItem_x                                       0x58AC60
#define EQ_PC__AlertInventoryChanged_x                             0x587940
#define EQ_PC__GetPcZoneClient_x                                   0x5B0D80
#define EQ_PC__RemoveMyAffect_x									   0x58F920

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E5E50
#define EQItemList__add_item_x                                     0x4E5D90
#define EQItemList__delete_item_x                                  0x4E6250
#define EQItemList__FreeItemList_x                                 0x4E6150

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x488040

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x59BE30
#define EQPlayer__dEQPlayer_x                                      0x5A4BF0
#define EQPlayer__DoAttack_x                                       0x5B6B80
#define EQPlayer__EQPlayer_x                                       0x5A7010
#define EQPlayer__SetNameSpriteState_x                             0x5A1920
#define EQPlayer__SetNameSpriteTint_x                              0x59D200
#define EQPlayer__IsBodyType_j_x                                   0x8F5940
#define EQPlayer__IsTargetable_x                                   0x8F6200
#define EQPlayer__CanSee_x                                         0x8F6720

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5AB2F0
#define EQPlayerManager__GetSpawnByName_x                          0x5AB750

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56E410
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56E450
#define KeypressHandler__ClearCommandStateArray_x                  0x56DFF0
#define KeypressHandler__HandleKeyDown_x                           0x56C950
#define KeypressHandler__HandleKeyUp_x                             0x56CC70
#define KeypressHandler__SaveKeymapping_x                          0x56E0C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6DD2C0
#define MapViewMap__SaveEx_x                                       0x6E0BA0

#define PlayerPointManager__GetAltCurrency_x                       0x8068F0

// StringTable 
#define StringTable__getString_x                                   0x802340

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x594CB0

//Doors
#define EQSwitch__UseSwitch_x                                      0x524440

//IconCache
#define IconCache__GetIcon_x                                       0x678250

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66F0E0
#define CContainerMgr__CloseContainer_x                            0x66F900

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x73E3D0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x561690

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B6B40
#define EQ_Spell__SpellAffects_x                                   0x4B6BE0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B6C10
#define CharacterZoneClient__CalcAffectChange_x                    0x4370A0
#define CLootWnd__LootAll_x                                        0x6D2CA0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x783A30
#define CTargetWnd__WndNotification_x                              0x783520

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x788BF0
