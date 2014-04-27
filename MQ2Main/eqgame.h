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
#define __ExpectedVersionDate                                     "Oct  9 2013"
#define __ExpectedVersionTime                                     "21:03:42"
#define __ActualVersionDate_x                                      0x9F5CB0
#define __ActualVersionTime_x                                      0x9F5CBC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5698A0
#define __MemChecker1_x                                            0x829980
#define __MemChecker2_x                                            0x5FF820
#define __MemChecker3_x                                            0x5FF770
#define __MemChecker4_x                                            0x7AD9D0
#define __EncryptPad0_x                                            0xB02690
#define __EncryptPad1_x                                            0xB868E8
#define __EncryptPad2_x                                            0xB1CA88
#define __EncryptPad3_x                                            0xB1C688
#define __EncryptPad4_x                                            0xB82B68
#define __AC1_x                                                    0x76B675
#define __AC2_x                                                    0x51D767
#define __AC3_x                                                    0x530BA0
#define __AC4_x                                                    0x536C04
#define __AC5_x                                                    0x5430A1
#define __AC6_x                                                    0x546B62
#define __AC7_x                                                    0x53CBCC
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0xE20920
#define DI8__Keyboard_x                                            0xE20924
#define DI8__Mouse_x                                               0xE20928
#define __AltTimerReady_x                                          0xD89139
#define __Attack_x                                                 0xE1BFD6
#define __Autofire_x                                               0xE1BFD7
#define __BindList_x                                               0xAE9748
#define __Clicks_x                                                 0xD97E68
#define __CommandList_x                                            0xAEAEF0
#define __CurrentMapLabel_x                                        0xF2D080
#define __CurrentSocial_x                                          0xAD30FC
#define __DoAbilityList_x                                          0xDCE584
#define __do_loot_x                                                0x4EBA40
#define __DrawHandler_x                                            0x158E1D4
#define __GroupCount_x                                             0xD88812

#define __Guilds_x                                                 0xD8E418
#define __gWorld_x                                                 0xD8ACCC
#define __HotkeyPage_x                                             0xE14F84
#define __HWnd_x                                                   0xE20678
#define __InChatMode_x                                             0xD97D9C
#define __LastTell_x                                               0xD99C8C
#define __LMouseHeldTime_x                                         0xD97ED4
#define __Mouse_x                                                  0xE2092C
#define __MouseLook_x                                              0xD97E36
#define __MouseEventTime_x                                         0xE1C4BC
#define __NetStatusToggle_x                                        0xD97E39
#define __PCNames_x                                                0xD992FC
#define __RangeAttackReady_x                                       0xD98F9C
#define __RMouseHeldTime_x                                         0xD97ED0
#define __RunWalkState_x                                           0xD97DA0
#define __ScreenMode_x                                             0xCD7880
#define __ScreenX_x                                                0xD97D54
#define __ScreenY_x                                                0xD97D50
#define __ScreenXMax_x                                             0xD97D58
#define __ScreenYMax_x                                             0xD97D5C
#define __ServerHost_x                                             0xD8875C
#define __ServerName_x                                             0xDCE544
#define __ShiftKeyDown_x                                           0xD98434
#define __ShowNames_x                                              0xD991A4
#define __Socials_x                                                0xDCE644


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xD8ADB0
#define instEQZoneInfo_x                                           0xD98024
#define instKeypressHandler_x                                      0xE1C4A0
#define pinstActiveBanker_x                                        0xD8AD70
#define pinstActiveCorpse_x                                        0xD8AD74
#define pinstActiveGMaster_x                                       0xD8AD78
#define pinstActiveMerchant_x                                      0xD8AD6C
#define pinstAggroInfo_x                                           0xB9C560
#define pinstAltAdvManager_x                                       0xCD8868
#define pinstAuraMgr_x                                             0xBA5FD0
#define pinstBandageTarget_x                                       0xD8AD58
#define pinstCamActor_x                                            0xCD8254
#define pinstCDBStr_x                                              0xCD7840
#define pinstCDisplay_x                                            0xD8AD80
#define pinstCEverQuest_x                                          0xE20AA4
#define pinstCharData_x                                            0xD8AD3C
#define pinstCharSpawn_x                                           0xD8AD64
#define pinstControlledMissile_x                                   0xD8AD38
#define pinstControlledPlayer_x                                    0xD8AD64
#define pinstCSidlManager_x                                        0x158D888
#define pinstCXWndManager_x                                        0x158D880
#define instDynamicZone_x                                          0xD97BF0
#define pinstDZMember_x                                            0xD97D00
#define pinstDZTimerInfo_x                                         0xD97D04
#define pinstEQItemList_x                                          0xD87758
#define instEQMisc_x                                               0xADC878
#define pinstEQSoundManager_x                                      0xCD8A00
#define instExpeditionLeader_x                                     0xD97C3A
#define instExpeditionName_x                                       0xD97C7A
#define pinstGroup_x                                               0xD8880E
#define pinstImeManager_x                                          0x158D88C
#define pinstLocalPlayer_x                                         0xD8AD50
#define pinstMercenaryData_x                                       0xE1C9E0
#define pinstMercAltAbilities_x									   0xCD897C
#define pinstModelPlayer_x                                         0xD8AD7C
#define pinstPCData_x                                              0xD8AD3C
#define pinstSkillMgr_x                                            0xE1D2D8
#define pinstSpawnManager_x                                        0xE1CE00
#define pinstSpellManager_x                                        0xE1D398
#define pinstSpellSets_x                                           0xE14FE8
#define pinstStringTable_x                                         0xD8ACE4
#define pinstSwitchManager_x                                       0xD883F8
#define pinstTarget_x                                              0xD8AD68
#define pinstTargetObject_x                                        0xD8AD40
#define pinstTargetSwitch_x                                        0xD8AD44
#define pinstTaskMember_x                                          0xCD77C8
#define pinstTrackTarget_x                                         0xD8AD5C
#define pinstTradeTarget_x                                         0xD8AD4C
#define instTributeActive_x                                        0xADC89D
#define pinstViewActor_x                                           0xCD8250
#define pinstWorldData_x                                           0xD8AD20


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xB9C850
#define pinstCAudioTriggersWindow_x                                0xB9C770
#define pinstCCharacterSelect_x                                    0xCD80FC
#define pinstCFacePick_x                                           0xCD7EAC
#define pinstCNoteWnd_x                                            0xCD80B4
#define pinstCBookWnd_x                                            0xCD80BC
#define pinstCPetInfoWnd_x                                         0xCD80C0
#define pinstCTrainWnd_x                                           0xCD80C4
#define pinstCSkillsWnd_x                                          0xCD80C8
#define pinstCSkillsSelectWnd_x                                    0xCD80CC
#define pinstCCombatSkillSelectWnd_x                               0xCD80D0
#define pinstCFriendsWnd_x                                         0xCD80D4
#define pinstCAuraWnd_x                                            0xCD80D8
#define pinstCRespawnWnd_x                                         0xCD80DC
#define pinstCBandolierWnd_x                                       0xCD80E0
#define pinstCPotionBeltWnd_x                                      0xCD80E4
#define pinstCAAWnd_x                                              0xCD80E8
#define pinstCGroupSearchFiltersWnd_x                              0xCD80EC
#define pinstCLoadskinWnd_x                                        0xCD80F0
#define pinstCAlarmWnd_x                                           0xCD80F4
#define pinstCMusicPlayerWnd_x                                     0xCD80F8
#define pinstCMailWnd_x                                            0xCD8100
#define pinstCMailCompositionWnd_x                                 0xCD8104
#define pinstCMailAddressBookWnd_x                                 0xCD8108
#define pinstCRaidWnd_x                                            0xCD8110
#define pinstCRaidOptionsWnd_x                                     0xCD8114
#define pinstCBreathWnd_x                                          0xCD8118
#define pinstCMapViewWnd_x                                         0xCD811C
#define pinstCMapToolbarWnd_x                                      0xCD8120
#define pinstCEditLabelWnd_x                                       0xCD8124
#define pinstCTargetWnd_x                                          0xCD8128
#define pinstCColorPickerWnd_x                                     0xCD812C
#define pinstCPlayerWnd_x                                          0xCD8130
#define pinstCOptionsWnd_x                                         0xCD8134
#define pinstCBuffWindowNORMAL_x                                   0xCD8138
#define pinstCBuffWindowSHORT_x                                    0xCD813C
#define pinstCharacterCreation_x                                   0xCD8140
#define pinstCCursorAttachment_x                                   0xCD8144
#define pinstCCastingWnd_x                                         0xCD8148
#define pinstCCastSpellWnd_x                                       0xCD814C
#define pinstCSpellBookWnd_x                                       0xCD8150
#define pinstCInventoryWnd_x                                       0xCD8154
#define pinstCBankWnd_x                                            0xCD8158
#define pinstCQuantityWnd_x                                        0xCD815C
#define pinstCLootWnd_x                                            0xCD8160
#define pinstCActionsWnd_x                                         0xCD8164
#define pinstCCombatAbilityWnd_x                                   0xCD8168
#define pinstCMerchantWnd_x                                        0xCD816C
#define pinstCTradeWnd_x                                           0xCD8170
#define pinstCSelectorWnd_x                                        0xCD8174
#define pinstCBazaarWnd_x                                          0xCD8178
#define pinstCBazaarSearchWnd_x                                    0xCD817C
#define pinstCGiveWnd_x                                            0xCD8198
#define pinstCTrackingWnd_x                                        0xCD81A0
#define pinstCInspectWnd_x                                         0xCD81A4
#define pinstCSocialEditWnd_x                                      0xCD81A8
#define pinstCFeedbackWnd_x                                        0xCD81AC
#define pinstCBugReportWnd_x                                       0xCD81B0
#define pinstCVideoModesWnd_x                                      0xCD81B4
#define pinstCTextEntryWnd_x                                       0xCD81BC
#define pinstCFileSelectionWnd_x                                   0xCD81C0
#define pinstCCompassWnd_x                                         0xCD81C4
#define pinstCPlayerNotesWnd_x                                     0xCD81C8
#define pinstCGemsGameWnd_x                                        0xCD81CC
#define pinstCTimeLeftWnd_x                                        0xCD81D0
#define pinstCPetitionQWnd_x                                       0xCD81E4
#define pinstCSoulmarkWnd_x                                        0xCD81E8
#define pinstCStoryWnd_x                                           0xCD81EC
#define pinstCJournalTextWnd_x                                     0xCD81F0
#define pinstCJournalCatWnd_x                                      0xCD81F4
#define pinstCBodyTintWnd_x                                        0xCD81F8
#define pinstCServerListWnd_x                                      0xCD81FC
#define pinstCAvaZoneWnd_x                                         0xCD8208
#define pinstCBlockedBuffWnd_x                                     0xCD820C
#define pinstCBlockedPetBuffWnd_x                                  0xCD8210
#define pinstCInvSlotMgr_x                                         0xCD8248
#define pinstCContainerMgr_x                                       0xCD824C
#define pinstCAdventureLeaderboardWnd_x                            0xF292F8
#define pinstCAdventureRequestWnd_x                                0xF29348
#define pinstCAltStorageWnd_x                                      0xF29518
#define pinstCAdventureStatsWnd_x                                  0xF29398
#define pinstCBarterMerchantWnd_x                                  0xF29BF8
#define pinstCBarterSearchWnd_x                                    0xF29C48
#define pinstCBarterWnd_x                                          0xF29C98
#define pinstCChatManager_x                                        0xF2A098
#define pinstCDynamicZoneWnd_x                                     0xF2A378
#define pinstCEQMainWnd_x                                          0xF2A480
#define pinstCFellowshipWnd_x                                      0xF2A33C
#define pinstCFindLocationWnd_x                                    0xF2A640
#define pinstCGroupSearchWnd_x                                     0xF2A848
#define pinstCGroupWnd_x                                           0xF2A898
#define pinstCGuildBankWnd_x                                       0xF2A8E8
#define pinstCGuildMgmtWnd_x                                       0xF2C988
#define pinstCHotButtonWnd_x                                       0xF2C9FC
#define pinstCHotButtonWnd1_x                                      0xF2C9FC
#define pinstCHotButtonWnd2_x                                      0xF2CA00
#define pinstCHotButtonWnd3_x                                      0xF2CA04
#define pinstCHotButtonWnd4_x                                      0xF2CA28
#define pinstCItemDisplayManager_x                                 0xF2CC08
#define pinstCItemExpTransferWnd_x                                 0xF2CC5C
#define pinstCLFGuildWnd_x                                         0xF2CE68
#define pinstCMIZoneSelectWnd_x                                    0xF2D228
#define pinstCConfirmationDialog_x                                 0xF2D678
#define pinstCPopupWndManager_x                                    0xF2D678
#define pinstCProgressionSelectionWnd_x                            0xF2D710
#define pinstCPvPStatsWnd_x                                        0xF2D7B0
#define pinstCSystemInfoDialogBox_x                                0xF2DC00
#define pinstCTaskTemplateSelectWnd_x                              0xF2EC70
#define pinstCTipWndOFDAY_x                                        0xF2EE30
#define pinstCTipWndCONTEXT_x                                      0xF2EE34
#define pinstCTitleWnd_x                                           0xF2EE80
#define pinstCContextMenuManager_x                                 0x158D49C
#define pinstCVoiceMacroWnd_x                                      0xE1D800
#define pinstCHtmlWnd_x                                            0xE1D8A8


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5016D0
#define __ConvertItemTags_x                                        0x4F1530
#define __ExecuteCmd_x                                             0x4DB110
#define __EQGetTime_x                                              0x82A4E0
#define __get_melee_range_x                                        0x4E1D70
#define __GetGaugeValueFromEQ_x                                    0x76A3A0
#define __GetLabelFromEQ_x                                         0x76B600
#define __GetXTargetType_x                                         0x8E67A0
#define __LoadFrontEnd_x                                           0x5FEED0
#define __NewUIINI_x                                               0x769CD0
#define __ProcessGameEvents_x                                      0x53ED00
#define CrashDetected_x                                            0x60154B
#define DrawNetStatus_x                                            0x578F20
#define Util__FastTime_x                                           0x829820
#define Expansion_HoT_x                                            0xD99104
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A4320
#define AltAdvManager__IsAbilityReady_x                            0x4A4390
#define AltAdvManager__GetAltAbility_x                             0x4A4750

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x44A5A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x62EB60

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x63CA90

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x554FA0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6577A0
#define CChatManager__InitContextMenu_x                            0x6582C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x810810
#define CChatService__GetFriendName_x                              0x810820

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x65D000
#define CChatWindow__Clear_x                                       0x65CBB0
#define CChatWindow__WndNotification_x                             0x65D540

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x888A70
#define CComboWnd__Draw_x                                          0x888C50
#define CComboWnd__GetCurChoice_x                                  0x888890
#define CComboWnd__GetListRect_x                                   0x888EF0
#define CComboWnd__GetTextRect_x                                   0x888AD0
#define CComboWnd__InsertChoice_x                                  0x888F60
#define CComboWnd__SetColors_x                                     0x888820
#define CComboWnd__SetChoice_x                                     0x888850

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6666B0
#define CContainerWnd__vftable_x                                   0x9FF2A0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x494060
#define CDisplay__GetClickedActor_x                                0x48BD50
#define CDisplay__GetUserDefinedColor_x                            0x48A610
#define CDisplay__GetWorldFilePath_x                               0x489A10
#define CDisplay__is3dON_x                                         0x488AE0
#define CDisplay__ReloadUI_x                                       0x49E030
#define CDisplay__WriteTextHD2_x                                   0x48F4B0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8AA510

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8994B0
#define CEditWnd__GetCharIndexPt_x                                 0x89A4E0
#define CEditWnd__GetDisplayString_x                               0x899660
#define CEditWnd__GetHorzOffset_x                                  0x8999A0
#define CEditWnd__GetLineForPrintableChar_x                        0x899FA0
#define CEditWnd__GetSelStartPt_x                                  0x89A7A0
#define CEditWnd__GetSTMLSafeText_x                                0x899B40
#define CEditWnd__PointFromPrintableChar_x                         0x89A090
#define CEditWnd__SelectableCharFromPoint_x                        0x89A210
#define CEditWnd__SetEditable_x                                    0x899B10

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x51DEB0
#define CEverQuest__DoTellWindow_x                                 0x5227E0
#define CEverQuest__DropHeldItemOnGround_x                         0x52B0A0
#define CEverQuest__dsp_chat_x                                     0x523F80
#define CEverQuest__Emote_x                                        0x5241E0
#define CEverQuest__EnterZone_x                                    0x536D90
#define CEverQuest__GetBodyTypeDesc_x                              0x51A530
#define CEverQuest__GetClassDesc_x                                 0x519C90
#define CEverQuest__GetClassThreeLetterCode_x                      0x51A290
#define CEverQuest__GetDeityDesc_x                                 0x51AE40
#define CEverQuest__GetLangDesc_x                                  0x51A8C0
#define CEverQuest__GetRaceDesc_x                                  0x51ABB0
#define CEverQuest__InterpretCmd_x                                 0x524AC0
#define CEverQuest__LeftClickedOnPlayer_x                          0x53B110
#define CEverQuest__LMouseUp_x                                     0x53D320
#define CEverQuest__RightClickedOnPlayer_x                         0x53BBD0
#define CEverQuest__RMouseUp_x                                     0x53CB80
#define CEverQuest__SetGameState_x                                 0x51E560
#define CEverQuest__UPCNotificationFlush_x                         0x525A50

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x676680
#define CGaugeWnd__CalcLinesFillRect_x                             0x6766E0
#define CGaugeWnd__Draw_x                                          0x676B10

// CGuild
#define CGuild__FindMemberByName_x                                 0x424020

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6937F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x69F140
#define CInvSlotMgr__MoveItem_x                                    0x6A0080

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x69E530
#define CInvSlot__SliderComplete_x                                 0x69C380
#define CInvSlot__GetItemBase_x                                    0x69B810

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6A0E30

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x766FD0
#define CItemDisplayWnd__UpdateStrings_x                           0x6A2180

// CLabel 
#define CLabel__Draw_x                                             0x6BC8F0

// CListWnd 
#define CListWnd__AddColumn_x                                      0x876CE0
#define CListWnd__AddColumn1_x                                     0x8764C0
#define CListWnd__AddLine_x                                        0x875F70
#define CListWnd__AddString_x                                      0x876180
#define CListWnd__CalculateFirstVisibleLine_x                      0x873020
#define CListWnd__CalculateVSBRange_x                              0x875160
#define CListWnd__ClearAllSel_x                                    0x8722E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x875B40
#define CListWnd__Compare_x                                        0x873B30
#define CListWnd__Draw_x                                           0x874DC0
#define CListWnd__DrawColumnSeparators_x                           0x874C50
#define CListWnd__DrawHeader_x                                     0x8725F0
#define CListWnd__DrawItem_x                                       0x874180
#define CListWnd__DrawLine_x                                       0x8748F0
#define CListWnd__DrawSeparator_x                                  0x874CF0
#define CListWnd__EnsureVisible_x                                  0x873180
#define CListWnd__ExtendSel_x                                      0x874090
#define CListWnd__GetColumnMinWidth_x                              0x871D00
#define CListWnd__GetColumnWidth_x                                 0x871C20
#define CListWnd__GetCurSel_x                                      0x8714F0
#define CListWnd__GetItemAtPoint_x                                 0x873420
#define CListWnd__GetItemAtPoint1_x                                0x873490
#define CListWnd__GetItemData_x                                    0x871740
#define CListWnd__GetItemHeight_x                                  0x872C80
#define CListWnd__GetItemIcon_x                                    0x871920
#define CListWnd__GetItemRect_x                                    0x873260
#define CListWnd__GetItemText_x                                    0x8717D0
#define CListWnd__GetSelList_x                                     0x8763B0
#define CListWnd__GetSeparatorRect_x                               0x873A50
#define CListWnd__RemoveLine_x                                     0x876360
#define CListWnd__SetColors_x                                      0x871550
#define CListWnd__SetColumnJustification_x                         0x871FD0
#define CListWnd__SetColumnWidth_x                                 0x871CB0
#define CListWnd__SetCurSel_x                                      0x871530
#define CListWnd__SetItemColor_x                                   0x875820
#define CListWnd__SetItemData_x                                    0x872390
#define CListWnd__SetItemText_x                                    0x875660
#define CListWnd__ShiftColumnSeparator_x                           0x8754F0
#define CListWnd__Sort_x                                           0x876E40
#define CListWnd__ToggleSel_x                                      0x872260

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6D7670

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6F74A0
#define CMerchantWnd__RequestBuyItem_x                             0x6FDA50
#define CMerchantWnd__RequestSellItem_x                            0x724CC0
#define CMerchantWnd__SelectBuySellSlot_x                          0x6F7750

// CObfuscator
#define CObfuscator__doit_x                                        0x7F04B0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x88E230
#define CSidlManager__CreateLabel_x                                0x75D660

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x625D00
#define CSidlScreenWnd__CalculateVSBRange_x                        0x625C20
#define CSidlScreenWnd__ConvertToRes_x                             0x8AA3F0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x87BD60
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x87D100
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x87D1B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x87C680
#define CSidlScreenWnd__DrawSidlPiece_x                            0x87B840
#define CSidlScreenWnd__EnableIniStorage_x                         0x87AF80
#define CSidlScreenWnd__GetSidlPiece_x                             0x87BA30
#define CSidlScreenWnd__Init1_x                                    0x87CDD0
#define CSidlScreenWnd__LoadIniInfo_x                              0x87BE10
#define CSidlScreenWnd__LoadIniListWnd_x                           0x87B140
#define CSidlScreenWnd__LoadSidlScreen_x                           0x87C8D0
#define CSidlScreenWnd__StoreIniInfo_x                             0x87AAF0
#define CSidlScreenWnd__StoreIniVis_x                              0x87AF10
#define CSidlScreenWnd__WndNotification_x                          0x87CB50
#define CSidlScreenWnd__GetChildItem_x                             0x87B050

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5C0F40
#define CSkillMgr__GetSkillCap_x                                   0x5C0FC0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8B43A0
#define CSliderWnd__SetValue_x                                     0x8B4570
#define CSliderWnd__SetNumTicks_x                                  0x8B4CF0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x764A90

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8A4B80
#define CStmlWnd__CalculateHSBRange_x                              0x89D1C0
#define CStmlWnd__CalculateVSBRange_x                              0x89D250
#define CStmlWnd__CanBreakAtCharacter_x                            0x89D3D0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x89DCB0
#define CStmlWnd__ForceParseNow_x                                  0x8A54D0
#define CStmlWnd__GetNextTagPiece_x                                0x89DBB0
#define CStmlWnd__GetSTMLText_x                                    0x65C450
#define CStmlWnd__GetVisibleText_x                                 0x89E700
#define CStmlWnd__InitializeWindowVariables_x                      0x8A09B0
#define CStmlWnd__MakeStmlColorTag_x                               0x89C3A0
#define CStmlWnd__MakeWndNotificationTag_x                         0x89C400
#define CStmlWnd__SetSTMLText_x                                    0x8A2210
#define CStmlWnd__StripFirstSTMLLines_x                            0x8A4820
#define CStmlWnd__UpdateHistoryString_x                            0x89F640

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8ABBF0
#define CTabWnd__DrawCurrentPage_x                                 0x8AB460
#define CTabWnd__DrawTab_x                                         0x8AB220
#define CTabWnd__GetCurrentPage_x                                  0x8AB830
#define CTabWnd__GetPageInnerRect_x                                0x8AAF10
#define CTabWnd__GetTabInnerRect_x                                 0x8AB110
#define CTabWnd__GetTabRect_x                                      0x8AAFE0
#define CTabWnd__InsertPage_x                                      0x8ABEE0
#define CTabWnd__SetPage_x                                         0x8AB860
#define CTabWnd__SetPageRect_x                                     0x8ABB30
#define CTabWnd__UpdatePage_x                                      0x8ABE80

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41FAF0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8A7FD0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8B0D60

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x86F7A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4113E0
#define CXStr__CXStr1_x                                            0x42DF50
#define CXStr__CXStr3_x                                            0x8268B0
#define CXStr__dCXStr_x                                            0x404670
#define CXStr__operator_equal_x                                    0x826A20
#define CXStr__operator_equal1_x                                   0x826A70
#define CXStr__operator_plus_equal1_x                              0x827B50

// CXWnd 
#define CXWnd__BringToTop_x                                        0x880C60
#define CXWnd__Center_x                                            0x886ED0
#define CXWnd__ClrFocus_x                                          0x880860
#define CXWnd__DoAllDrawing_x                                      0x886B40
#define CXWnd__DrawChildren_x                                      0x886CD0
#define CXWnd__DrawColoredRect_x                                   0x881010
#define CXWnd__DrawTooltip_x                                       0x8812C0
#define CXWnd__DrawTooltipAtPoint_x                                0x885A80
#define CXWnd__GetBorderFrame_x                                    0x881720
#define CXWnd__GetChildWndAt_x                                     0x884A40
#define CXWnd__GetClientClipRect_x                                 0x8814D0
#define CXWnd__GetScreenClipRect_x                                 0x886180
#define CXWnd__GetScreenRect_x                                     0x8818F0
#define CXWnd__GetTooltipRect_x                                    0x881150
#define CXWnd__GetWindowTextA_x                                    0x411420
#define CXWnd__IsActive_x                                          0x894190
#define CXWnd__IsDescendantOf_x                                    0x881660
#define CXWnd__IsReallyVisible_x                                   0x884A20
#define CXWnd__IsType_x                                            0x8AD580
#define CXWnd__Move_x                                              0x884110
#define CXWnd__Move1_x                                             0x8867E0
#define CXWnd__ProcessTransition_x                                 0x880C10
#define CXWnd__Refade_x                                            0x880A00
#define CXWnd__Resize_x                                            0x8819C0
#define CXWnd__Right_x                                             0x885F80
#define CXWnd__SetFocus_x                                          0x883270
#define CXWnd__SetFont_x                                           0x8808B0
#define CXWnd__SetKeyTooltip_x                                     0x881C30
#define CXWnd__SetMouseOver_x                                      0x8864D0
#define CXWnd__StartFade_x                                         0x880CB0
#define CXWnd__GetChildItem_x                                      0x886410

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x895A90
#define CXWndManager__DrawWindows_x                                0x8956D0
#define CXWndManager__GetKeyboardFlags_x                           0x893CC0
#define CXWndManager__HandleKeyboardMsg_x                          0x894620
#define CXWndManager__RemoveWnd_x                                  0x894320

// CDBStr
#define CDBStr__GetString_x                                        0x486CE0

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8E3040
#define EQ_Character__CastSpell_x                                  0x43AB20
#define EQ_Character__Cur_HP_x                                     0x44A1F0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4339C0
#define EQ_Character__GetCharInfo2_x                               0x7FB380
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42CC20
#define EQ_Character__GetFocusRangeModifier_x                      0x42CE00
#define EQ_Character__Max_Endurance_x                              0x587A30
#define EQ_Character__Max_HP_x                                     0x444360
#define EQ_Character__Max_Mana_x                                   0x587870
#define EQ_Character__doCombatAbility_x                            0x5862E0
#define EQ_Character__UseSkill_x                                   0x45B6A0
#define EQ_Character__GetConLevel_x                                0x57D5D0
#define EQ_Character__IsExpansionFlag_x                            0x410910
#define EQ_Character__TotalEffect_x                                0x438C80

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x55A230
#define EQ_Item__CreateItemTagString_x                             0x7DB050
#define EQ_Item__IsStackable_x                                     0x7CF5F0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A6490
#define EQ_LoadingS__Array_x                                       0xAE3118

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x58C040
#define EQ_PC__GetAltAbilityIndex_x                                0x7E3CA0
#define EQ_PC__GetCombatAbility_x                                  0x7E3D30
#define EQ_PC__GetCombatAbilityTimer_x                             0x7E3DE0
#define EQ_PC__GetItemTimerValue_x                                 0x586020
#define EQ_PC__HasLoreItem_x                                       0x580780

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4DFAB0
#define EQItemList__add_item_x                                     0x4DF9F0
#define EQItemList__delete_item_x                                  0x4DFEB0
#define EQItemList__FreeItemList_x                                 0x4DFDB0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4861B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x591D30
#define EQPlayer__dEQPlayer_x                                      0x5969A0
#define EQPlayer__DoAttack_x                                       0x5AB0D0
#define EQPlayer__EQPlayer_x                                       0x59C190
#define EQPlayer__SetNameSpriteState_x                             0x5941B0
#define EQPlayer__SetNameSpriteTint_x                              0x591DA0
#define EQPlayer__IsBodyType_j_x                                   0x8E28B0
#define EQPlayer__IsTargetable_x                                   0x8E2B80

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x59F700
#define EQPlayerManager__GetSpawnByName_x                          0x59FB60

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5604C0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x560500
#define KeypressHandler__ClearCommandStateArray_x                  0x5600A0
#define KeypressHandler__HandleKeyDown_x                           0x55EA00
#define KeypressHandler__HandleKeyUp_x                             0x55ED20
#define KeypressHandler__SaveKeymapping_x                          0x560170

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6CFAC0
#define MapViewMap__SaveEx_x                                       0x6D3370

#define PlayerPointManager__GetAltCurrency_x                       0x7F5560

// StringTable 
#define StringTable__getString_x                                   0x7F0750

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x58A940
