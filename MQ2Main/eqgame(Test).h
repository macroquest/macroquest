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
#define __ExpectedVersionDate                                     "Oct 24 2014"
#define __ExpectedVersionTime                                     "09:35:47"
#define __ActualVersionDate_x                                      0xA51878
#define __ActualVersionTime_x                                      0xA51884

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x573CA0
#define __MemChecker1_x                                            0x83B300
#define __MemChecker2_x                                            0x60B120
#define __MemChecker3_x                                            0x60B070
#define __MemChecker4_x                                            0x7BF190
#define __EncryptPad0_x                                            0xBBD760
#define __EncryptPad1_x                                            0xD38B98
#define __EncryptPad2_x                                            0xC04CE8
#define __EncryptPad3_x                                            0xC048E8
#define __EncryptPad4_x                                            0xD16320
#define __AC1_x                                                    0x77C585
#define __AC2_x                                                    0x529CE7
#define __AC3_x                                                    0x53E3D0
#define __AC4_x                                                    0x544500
#define __AC5_x                                                    0x550B5E
#define __AC6_x                                                    0x554692
#define __AC7_x                                                    0x54A60C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10E97D0
#define DI8__Keyboard_x                                            0x10E97D4
#define DI8__Mouse_x                                               0x10E97D8
#define __AltTimerReady_x                                          0xF49261
#define __Attack_x                                                 0xFDC377
#define __Autofire_x                                               0xFDC378
#define __BindList_x                                               0xB81688
#define __bCommandEnabled_x                                        0xF47370
#define __Clicks_x                                                 0xF57EA8
#define __CommandList_x                                            0xB857D0
#define __CurrentMapLabel_x                                        0x10EF228
#define __CurrentSocial_x                                          0xB46FBC
#define __DoAbilityList_x                                          0xF8E62C
#define __do_loot_x                                                0x4F1540
#define __DrawHandler_x                                            0x1753E3C
#define __GroupCount_x                                             0xF4893A

#define __Guilds_x                                                 0xF4E428
#define __gWorld_x                                                 0xF4ADF4
#define __HotkeyPage_x                                             0xFD502C
#define __HWnd_x                                                   0xFE16D8
#define __InChatMode_x                                             0xF57DD4
#define __LastTell_x                                               0xF59D34
#define __LMouseHeldTime_x                                         0xF57F14
#define __Mouse_x                                                  0x10E97DC
#define __MouseLook_x                                              0xF57E6E
#define __MouseEventTime_x                                         0xFDCB64
#define __NetStatusToggle_x                                        0xF57E71
#define __PCNames_x                                                0xF59364
#define __RangeAttackReady_x                                       0xF58FF8
#define __RMouseHeldTime_x                                         0xF57F10
#define __RunWalkState_x                                           0xF57DD8
#define __ScreenMode_x                                             0xE97330
#define __ScreenX_x                                                0xF57D8C
#define __ScreenY_x                                                0xF57D88
#define __ScreenXMax_x                                             0xF57D90
#define __ScreenYMax_x                                             0xF57D94
#define __ServerHost_x                                             0xF48884
#define __ServerName_x                                             0xF8E5EC
#define __ShiftKeyDown_x                                           0xF5847C
#define __ShowNames_x                                              0xF59208
#define __Socials_x                                                0xF8E6EC
#define __SubscriptionType_x                                       0x111B5B8
#define __TargetAggroHolder_x                                      0x10F1464
#define __GroupAggro_x                                             0x10F14A4
#define __LoginName_x                                              0xFE02B0
#define __Inviter_x                                                0xFDC2F4


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF4AEE0
#define instEQZoneInfo_x                                           0xF58064
#define instKeypressHandler_x                                      0xFDCB48
#define pinstActiveBanker_x                                        0xF4AE98
#define pinstActiveCorpse_x                                        0xF4AE9C
#define pinstActiveGMaster_x                                       0xF4AEA0
#define pinstActiveMerchant_x                                      0xF4AE94
#define pinstAggroInfo_x                                           0xD5B918
#define pinstAltAdvManager_x                                       0xE98408
#define pinstAuraMgr_x                                             0xD657E0
#define pinstBandageTarget_x                                       0xF4AE80
#define pinstCamActor_x                                            0xE97D10
#define pinstCDBStr_x                                              0xE972C4
#define pinstCDisplay_x                                            0xF4AEA8
#define pinstCEverQuest_x                                          0x10E9954
#define pinstCharData_x                                            0xF4AE64
#define pinstCharSpawn_x                                           0xF4AE8C
#define pinstControlledMissile_x                                   0xF4AE60
#define pinstControlledPlayer_x                                    0xF4AE8C
#define pinstCSidlManager_x                                        0x1753250
#define pinstCXWndManager_x                                        0x1753248
#define instDynamicZone_x                                          0xF57C20
#define pinstDZMember_x                                            0xF57D30
#define pinstDZTimerInfo_x                                         0xF57D34
#define pinstEQItemList_x                                          0xF475BC
#define instEQMisc_x                                               0xB62A48
#define pinstEQSoundManager_x                                      0xE98708
#define instExpeditionLeader_x                                     0xF57C6A
#define instExpeditionName_x                                       0xF57CAA
#define pinstGroup_x                                               0xF48936
#define pinstImeManager_x                                          0x1753254
#define pinstLocalPlayer_x                                         0xF4AE78
#define pinstMercenaryData_x                                       0xFDD198
#define pinstMercAltAbilities_x                                    0xE98628
#define pinstModelPlayer_x                                         0xF4AEA4
#define pinstPCData_x                                              0xF4AE64
#define pinstSkillMgr_x                                            0xFDDFD0
#define pinstSpawnManager_x                                        0xFDD8B8
#define pinstSpellManager_x                                        0xFDE118
#define pinstSpellSets_x                                           0xFD5090
#define pinstStringTable_x                                         0xF4AE0C
#define pinstSwitchManager_x                                       0xF484C8
#define pinstTarget_x                                              0xF4AE90
#define pinstTargetObject_x                                        0xF4AE68
#define pinstTargetSwitch_x                                        0xF4AE6C
#define pinstTaskMember_x                                          0xE97210
#define pinstTrackTarget_x                                         0xF4AE84
#define pinstTradeTarget_x                                         0xF4AE74
#define instTributeActive_x                                        0xB62A6D
#define pinstViewActor_x                                           0xE97D0C
#define pinstWorldData_x                                           0xF4AE48


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD5BDF8
#define pinstCAudioTriggersWindow_x                                0xD5BC88
#define pinstCCharacterSelect_x                                    0xE97BB8
#define pinstCFacePick_x                                           0xE97B68
#define pinstCNoteWnd_x                                            0xE97B70
#define pinstCBookWnd_x                                            0xE97B78
#define pinstCPetInfoWnd_x                                         0xE97B7C
#define pinstCTrainWnd_x                                           0xE97B80
#define pinstCSkillsWnd_x                                          0xE97B84
#define pinstCSkillsSelectWnd_x                                    0xE97B88
#define pinstCCombatSkillSelectWnd_x                               0xE97B8C
#define pinstCFriendsWnd_x                                         0xE97B90
#define pinstCAuraWnd_x                                            0xE97B94
#define pinstCRespawnWnd_x                                         0xE97B98
#define pinstCBandolierWnd_x                                       0xE97B9C
#define pinstCPotionBeltWnd_x                                      0xE97BA0
#define pinstCAAWnd_x                                              0xE97BA4
#define pinstCGroupSearchFiltersWnd_x                              0xE97BA8
#define pinstCLoadskinWnd_x                                        0xE97BAC
#define pinstCAlarmWnd_x                                           0xE97BB0
#define pinstCMusicPlayerWnd_x                                     0xE97BB4
#define pinstCMailWnd_x                                            0xE97BBC
#define pinstCMailCompositionWnd_x                                 0xE97BC0
#define pinstCMailAddressBookWnd_x                                 0xE97BC4
#define pinstCRaidWnd_x                                            0xE97BCC
#define pinstCRaidOptionsWnd_x                                     0xE97BD0
#define pinstCBreathWnd_x                                          0xE97BD4
#define pinstCMapViewWnd_x                                         0xE97BD8
#define pinstCMapToolbarWnd_x                                      0xE97BDC
#define pinstCEditLabelWnd_x                                       0xE97BE0
#define pinstCTargetWnd_x                                          0xE97BE4
#define pinstCColorPickerWnd_x                                     0xE97BE8
#define pinstCPlayerWnd_x                                          0xE97BEC
#define pinstCOptionsWnd_x                                         0xE97BF0
#define pinstCBuffWindowNORMAL_x                                   0xE97BF4
#define pinstCBuffWindowSHORT_x                                    0xE97BF8
#define pinstCharacterCreation_x                                   0xE97BFC
#define pinstCCursorAttachment_x                                   0xE97C00
#define pinstCCastingWnd_x                                         0xE97C04
#define pinstCCastSpellWnd_x                                       0xE97C08
#define pinstCSpellBookWnd_x                                       0xE97C0C
#define pinstCInventoryWnd_x                                       0xE97C10
#define pinstCBankWnd_x                                            0xE97C14
#define pinstCQuantityWnd_x                                        0xE97C18
#define pinstCLootWnd_x                                            0xE97C1C
#define pinstCActionsWnd_x                                         0xE97C20
#define pinstCCombatAbilityWnd_x                                   0xE97C24
#define pinstCMerchantWnd_x                                        0xE97C28
#define pinstCTradeWnd_x                                           0xE97C2C
#define pinstCSelectorWnd_x                                        0xE97C30
#define pinstCBazaarWnd_x                                          0xE97C34
#define pinstCBazaarSearchWnd_x                                    0xE97C38
#define pinstCGiveWnd_x                                            0xE97C54
#define pinstCTrackingWnd_x                                        0xE97C5C
#define pinstCInspectWnd_x                                         0xE97C60
#define pinstCSocialEditWnd_x                                      0xE97C64
#define pinstCFeedbackWnd_x                                        0xE97C68
#define pinstCBugReportWnd_x                                       0xE97C6C
#define pinstCVideoModesWnd_x                                      0xE97C70
#define pinstCTextEntryWnd_x                                       0xE97C78
#define pinstCFileSelectionWnd_x                                   0xE97C7C
#define pinstCCompassWnd_x                                         0xE97C80
#define pinstCPlayerNotesWnd_x                                     0xE97C84
#define pinstCGemsGameWnd_x                                        0xE97C88
#define pinstCTimeLeftWnd_x                                        0xE97C8C
#define pinstCPetitionQWnd_x                                       0xE97CA0
#define pinstCSoulmarkWnd_x                                        0xE97CA4
#define pinstCStoryWnd_x                                           0xE97CA8
#define pinstCJournalTextWnd_x                                     0xE97CAC
#define pinstCJournalCatWnd_x                                      0xE97CB0
#define pinstCBodyTintWnd_x                                        0xE97CB4
#define pinstCServerListWnd_x                                      0xE97CB8
#define pinstCAvaZoneWnd_x                                         0xE97CC4
#define pinstCBlockedBuffWnd_x                                     0xE97CC8
#define pinstCBlockedPetBuffWnd_x                                  0xE97CCC
#define pinstCInvSlotMgr_x                                         0xE97D04
#define pinstCContainerMgr_x                                       0xE97D08
#define pinstCAdventureLeaderboardWnd_x                            0x10EA300
#define pinstCAdventureRequestWnd_x                                0x10EA378
#define pinstCAltStorageWnd_x                                      0x10EA658
#define pinstCAdventureStatsWnd_x                                  0x10EA3F0
#define pinstCBarterMerchantWnd_x                                  0x10EB240
#define pinstCBarterSearchWnd_x                                    0x10EB2B8
#define pinstCBarterWnd_x                                          0x10EB330
#define pinstCChatManager_x                                        0x10EB9C0
#define pinstCDynamicZoneWnd_x                                     0x10EBE70
#define pinstCEQMainWnd_x                                          0x10EC008
#define pinstCFellowshipWnd_x                                      0x10EBE04
#define pinstCFindLocationWnd_x                                    0x10EC2D8
#define pinstCGroupSearchWnd_x                                     0x10EC5A8
#define pinstCGroupWnd_x                                           0x10EC620
#define pinstCGuildBankWnd_x                                       0x10EC698
#define pinstCGuildMgmtWnd_x                                       0x10EE788
#define pinstCHotButtonWnd_x                                       0x10EE854
#define pinstCHotButtonWnd1_x                                      0x10EE854
#define pinstCHotButtonWnd2_x                                      0x10EE858
#define pinstCHotButtonWnd3_x                                      0x10EE85C
#define pinstCHotButtonWnd4_x                                      0x10EE880
#define pinstCItemDisplayManager_x                                 0x10EEB78
#define pinstCItemExpTransferWnd_x                                 0x10EEBF4
#define pinstCLFGuildWnd_x                                         0x10EEED0
#define pinstCMIZoneSelectWnd_x                                    0x10EF4B8
#define pinstCConfirmationDialog_x                                 0x10EFBC0
#define pinstCPopupWndManager_x                                    0x10EFBC0
#define pinstCProgressionSelectionWnd_x                            0x10EFCB0
#define pinstCPvPStatsWnd_x                                        0x10EFDA0
#define pinstCSystemInfoDialogBox_x                                0x10F04A8
#define pinstCTaskWnd_x                                            0x10F1870
#define pinstCTaskTemplateSelectWnd_x                              0x10F17F8
#define pinstCTipWndOFDAY_x                                        0x10F1AC8
#define pinstCTipWndCONTEXT_x                                      0x10F1ACC
#define pinstCTitleWnd_x                                           0x10F1B48
#define pinstCContextMenuManager_x                                 0x1752E64
#define pinstCVoiceMacroWnd_x                                      0xFDE780
#define pinstCHtmlWnd_x                                            0xFDE878
#define pinstIconCache_x                                           0x10EBFDC
#define pinstCTradeskillWnd_x                                      0x10F1C48

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x509050
#define __ConvertItemTags_x                                        0x4F6200
#define __ExecuteCmd_x                                             0x4E0D40
#define __EQGetTime_x                                              0x83BE60
#define __get_melee_range_x                                        0x4E7A20
#define __GetGaugeValueFromEQ_x                                    0x77B2D0
#define __GetLabelFromEQ_x                                         0x77C510
#define __GetXTargetType_x                                         0x8F9370
#define __LoadFrontEnd_x                                           0x60A7D0
#define __NewUIINI_x                                               0x77AC10
#define __ProcessGameEvents_x                                      0x54CFB0
#define __ProcessMouseEvent_x                                      0x54C750
#define CrashDetected_x                                            0x60C2A0
#define DrawNetStatus_x                                            0x583280
#define Util__FastTime_x                                           0x83B170
#define Expansion_HoT_x                                            0xF59164
#define __HelpPath_x                                               0xFDC8D0
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A5F80
#define AltAdvManager__IsAbilityReady_x                            0x4A5FF0
#define AltAdvManager__GetAltAbility_x                             0x4A63B0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x452E70
#define CharacterZoneClient__MakeMeVisible_x                       0x457F30

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x639F50

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6483C0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x562FA0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6631A0
#define CChatManager__InitContextMenu_x                            0x663CC0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x821DB0
#define CChatService__GetFriendName_x                              0x821DC0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x668AA0
#define CChatWindow__Clear_x                                       0x668650
#define CChatWindow__WndNotification_x                             0x668FD0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x89A5B0
#define CComboWnd__Draw_x                                          0x89A790
#define CComboWnd__GetCurChoice_x                                  0x89A3D0
#define CComboWnd__GetListRect_x                                   0x89AA30
#define CComboWnd__GetTextRect_x                                   0x89A610
#define CComboWnd__InsertChoice_x                                  0x89AAA0
#define CComboWnd__SetColors_x                                     0x89A360
#define CComboWnd__SetChoice_x                                     0x89A390

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x672150
#define CContainerWnd__vftable_x                                   0xA5AFE8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x494720
#define CDisplay__GetClickedActor_x                                0x48D1C0
#define CDisplay__GetUserDefinedColor_x                            0x48BA80
#define CDisplay__GetWorldFilePath_x                               0x48AE80
#define CDisplay__is3dON_x                                         0x48A250
#define CDisplay__ReloadUI_x                                       0x49FB80
#define CDisplay__WriteTextHD2_x                                   0x490A10

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8BC3B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8AAFA0
#define CEditWnd__GetCharIndexPt_x                                 0x8ABFB0
#define CEditWnd__GetDisplayString_x                               0x8AB150
#define CEditWnd__GetHorzOffset_x                                  0x8AB490
#define CEditWnd__GetLineForPrintableChar_x                        0x8ABA80
#define CEditWnd__GetSelStartPt_x                                  0x8AC260
#define CEditWnd__GetSTMLSafeText_x                                0x8AB620
#define CEditWnd__PointFromPrintableChar_x                         0x8ABB70
#define CEditWnd__SelectableCharFromPoint_x                        0x8ABCF0
#define CEditWnd__SetEditable_x                                    0x8AB5F0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x52A430
#define CEverQuest__DoTellWindow_x                                 0x52FDC0
#define CEverQuest__DropHeldItemOnGround_x                         0x538850
#define CEverQuest__dsp_chat_x                                     0x531560
#define CEverQuest__Emote_x                                        0x5317C0
#define CEverQuest__EnterZone_x                                    0x544690
#define CEverQuest__GetBodyTypeDesc_x                              0x526D60
#define CEverQuest__GetClassDesc_x                                 0x52C930
#define CEverQuest__GetClassThreeLetterCode_x                      0x52CF30
#define CEverQuest__GetDeityDesc_x                                 0x527640
#define CEverQuest__GetLangDesc_x                                  0x5270F0
#define CEverQuest__GetRaceDesc_x                                  0x52D0F0
#define CEverQuest__InterpretCmd_x                                 0x5320A0
#define CEverQuest__LeftClickedOnPlayer_x                          0x548A80
#define CEverQuest__LMouseUp_x                                     0x54AD70
#define CEverQuest__RightClickedOnPlayer_x                         0x549580
#define CEverQuest__RMouseUp_x                                     0x54A5C0
#define CEverQuest__SetGameState_x                                 0x52AAE0
#define CEverQuest__UPCNotificationFlush_x                         0x533240

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x682D40
#define CGaugeWnd__CalcLinesFillRect_x                             0x682DA0
#define CGaugeWnd__Draw_x                                          0x6831D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4247C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69FE10

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6ADC40
#define CInvSlotMgr__MoveItem_x                                    0x6AEB80
#define CInvSlotMgr__SelectSlot_x                                  0x6ADCF0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6AD0E0
#define CInvSlot__SliderComplete_x                                 0x6AAAA0
#define CInvSlot__GetItemBase_x                                    0x6A9F30

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6AFD00

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x777DF0
#define CItemDisplayWnd__UpdateStrings_x                           0x6B1040

// CLabel 
#define CLabel__Draw_x                                             0x6CBC90

// CListWnd 
#define CListWnd__AddColumn_x                                      0x8885B0
#define CListWnd__AddColumn1_x                                     0x887D90
#define CListWnd__AddLine_x                                        0x887840
#define CListWnd__AddString_x                                      0x887A50
#define CListWnd__CalculateFirstVisibleLine_x                      0x884920
#define CListWnd__CalculateVSBRange_x                              0x886A40
#define CListWnd__ClearAllSel_x                                    0x883BE0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x887420
#define CListWnd__Compare_x                                        0x885420
#define CListWnd__Draw_x                                           0x8866A0
#define CListWnd__DrawColumnSeparators_x                           0x886530
#define CListWnd__DrawHeader_x                                     0x883EF0
#define CListWnd__DrawItem_x                                       0x885A70
#define CListWnd__DrawLine_x                                       0x8861D0
#define CListWnd__DrawSeparator_x                                  0x8865D0
#define CListWnd__EnsureVisible_x                                  0x884A80
#define CListWnd__ExtendSel_x                                      0x885980
#define CListWnd__GetColumnMinWidth_x                              0x883600
#define CListWnd__GetColumnWidth_x                                 0x883520
#define CListWnd__GetCurSel_x                                      0x882D10
#define CListWnd__GetItemAtPoint_x                                 0x884D10
#define CListWnd__GetItemAtPoint1_x                                0x884D80
#define CListWnd__GetItemData_x                                    0x883040
#define CListWnd__GetItemHeight_x                                  0x884580
#define CListWnd__GetItemIcon_x                                    0x883220
#define CListWnd__GetItemRect_x                                    0x884B50
#define CListWnd__GetItemText_x                                    0x8830D0
#define CListWnd__GetSelList_x                                     0x887C80
#define CListWnd__GetSeparatorRect_x                               0x885340
#define CListWnd__RemoveLine_x                                     0x887C30
#define CListWnd__SetColors_x                                      0x882E60
#define CListWnd__SetColumnJustification_x                         0x8838D0
#define CListWnd__SetColumnWidth_x                                 0x8835B0
#define CListWnd__SetCurSel_x                                      0x882D50
#define CListWnd__SetItemColor_x                                   0x887100
#define CListWnd__SetItemData_x                                    0x883C90
#define CListWnd__SetItemText_x                                    0x886F40
#define CListWnd__ShiftColumnSeparator_x                           0x886DD0
#define CListWnd__Sort_x                                           0x888710
#define CListWnd__ToggleSel_x                                      0x883B60

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6E4FA0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x706220
#define CMerchantWnd__RequestBuyItem_x                             0x70D050
#define CMerchantWnd__RequestSellItem_x                            0x735120
#define CMerchantWnd__SelectRecoverySlot_x                         0x7064D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x705730
#define CMerchantWnd__ActualSelect_x                               0x709F80

// CObfuscator
#define CObfuscator__doit_x                                        0x8021D0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x89FD80
#define CSidlManager__CreateLabel_x                                0x76DDC0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x631250
#define CSidlScreenWnd__CalculateVSBRange_x                        0x631170
#define CSidlScreenWnd__ConvertToRes_x                             0x8BC290
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x88D6C0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x88EBC0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x88EC70
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x88E130
#define CSidlScreenWnd__DrawSidlPiece_x                            0x88D1A0
#define CSidlScreenWnd__EnableIniStorage_x                         0x88C8E0
#define CSidlScreenWnd__GetSidlPiece_x                             0x88D390
#define CSidlScreenWnd__Init1_x                                    0x88E890
#define CSidlScreenWnd__LoadIniInfo_x                              0x88D770
#define CSidlScreenWnd__LoadIniListWnd_x                           0x88CAA0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x88E380
#define CSidlScreenWnd__StoreIniInfo_x                             0x88C3A0
#define CSidlScreenWnd__StoreIniVis_x                              0x88C870
#define CSidlScreenWnd__WndNotification_x                          0x88E610
#define CSidlScreenWnd__GetChildItem_x                             0x88C9B0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x893510

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5CC6E0
#define CSkillMgr__GetSkillCap_x                                   0x5CC880
#define CSkillMgr__GetNameToken_x                                  0x5CC350

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8C6290
#define CSliderWnd__SetValue_x                                     0x8C6460
#define CSliderWnd__SetNumTicks_x                                  0x8C6BE0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x775A90

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8B6690
#define CStmlWnd__CalculateHSBRange_x                              0x8AEC40
#define CStmlWnd__CalculateVSBRange_x                              0x8AEBB0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8AEDC0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8AF6A0
#define CStmlWnd__ForceParseNow_x                                  0x8B6FE0
#define CStmlWnd__GetNextTagPiece_x                                0x8AF5A0
#define CStmlWnd__GetSTMLText_x                                    0x667EF0
#define CStmlWnd__GetVisibleText_x                                 0x8B00F0
#define CStmlWnd__InitializeWindowVariables_x                      0x8B2480
#define CStmlWnd__MakeStmlColorTag_x                               0x8ADEB0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8ADF10
#define CStmlWnd__SetSTMLText_x                                    0x8B3CF0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8B6330
#define CStmlWnd__UpdateHistoryString_x                            0x8B1030

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8BDA80
#define CTabWnd__DrawCurrentPage_x                                 0x8BD2F0
#define CTabWnd__DrawTab_x                                         0x8BD0C0
#define CTabWnd__GetCurrentPage_x                                  0x8BD6C0
#define CTabWnd__GetPageInnerRect_x                                0x8BCDB0
#define CTabWnd__GetTabInnerRect_x                                 0x8BCFB0
#define CTabWnd__GetTabRect_x                                      0x8BCE80
#define CTabWnd__InsertPage_x                                      0x8BDD70
#define CTabWnd__SetPage_x                                         0x8BD6F0
#define CTabWnd__SetPageRect_x                                     0x8BD9C0
#define CTabWnd__UpdatePage_x                                      0x8BDD10

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4204E0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B9AF0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8C2C50

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x880E80

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5703C0
#define CXStr__CXStr1_x                                            0x875AC0
#define CXStr__CXStr3_x                                            0x838200
#define CXStr__dCXStr_x                                            0x8C1970
#define CXStr__operator_equal_x                                    0x838370
#define CXStr__operator_equal1_x                                   0x8383C0
#define CXStr__operator_plus_equal1_x                              0x8394A0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x892790
#define CXWnd__Center_x                                            0x8989A0
#define CXWnd__ClrFocus_x                                          0x892360
#define CXWnd__DoAllDrawing_x                                      0x8985F0
#define CXWnd__DrawChildren_x                                      0x898790
#define CXWnd__DrawColoredRect_x                                   0x892B40
#define CXWnd__DrawTooltip_x                                       0x892DF0
#define CXWnd__DrawTooltipAtPoint_x                                0x897590
#define CXWnd__GetBorderFrame_x                                    0x893200
#define CXWnd__GetChildWndAt_x                                     0x896530
#define CXWnd__GetClientClipRect_x                                 0x893010
#define CXWnd__GetScreenClipRect_x                                 0x897C80
#define CXWnd__GetScreenRect_x                                     0x8933B0
#define CXWnd__GetTooltipRect_x                                    0x892C80
#define CXWnd__GetWindowTextA_x                                    0x4118E0
#define CXWnd__IsActive_x                                          0x8A5D30
#define CXWnd__IsDescendantOf_x                                    0x893150
#define CXWnd__IsReallyVisible_x                                   0x896510
#define CXWnd__IsType_x                                            0x8BF410
#define CXWnd__Move_x                                              0x895BF0
#define CXWnd__Move1_x                                             0x8982B0
#define CXWnd__ProcessTransition_x                                 0x892730
#define CXWnd__Refade_x                                            0x892500
#define CXWnd__Resize_x                                            0x893470
#define CXWnd__Right_x                                             0x897A80
#define CXWnd__SetFocus_x                                          0x894D60
#define CXWnd__SetFont_x                                           0x8923B0
#define CXWnd__SetKeyTooltip_x                                     0x8936E0
#define CXWnd__SetMouseOver_x                                      0x897FB0
#define CXWnd__StartFade_x                                         0x8927E0
#define CXWnd__GetChildItem_x                                      0x897EF0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A7650
#define CXWndManager__DrawWindows_x                                0x8A7290
#define CXWndManager__GetKeyboardFlags_x                           0x8A58A0
#define CXWndManager__HandleKeyboardMsg_x                          0x8A61C0
#define CXWndManager__RemoveWnd_x                                  0x8A5EC0

// CDBStr
#define CDBStr__GetString_x                                        0x488710

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8F6380
#define EQ_Character__CastSpell_x                                  0x43C7F0
#define EQ_Character__Cur_HP_x                                     0x452530
#define EQ_Character__GetAACastingTimeModifier_x                   0x4358F0
#define EQ_Character__GetCharInfo2_x                               0x80C7F0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42DC20
#define EQ_Character__GetFocusRangeModifier_x                      0x42DE00
#define EQ_Character__Max_Endurance_x                              0x594E50
#define EQ_Character__Max_HP_x                                     0x448820
#define EQ_Character__Max_Mana_x                                   0x594C80
#define EQ_Character__doCombatAbility_x                            0x592270
#define EQ_Character__UseSkill_x                                   0x45D070
#define EQ_Character__GetConLevel_x                                0x5878E0
#define EQ_Character__IsExpansionFlag_x                            0x410E20
#define EQ_Character__TotalEffect_x                                0x43A920

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x568610
#define EQ_Item__CreateItemTagString_x                             0x7ECCB0
#define EQ_Item__IsStackable_x                                     0x7E0EA0
#define EQ_Item__GetImageNum_x                                     0x7E3B30

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A80B0
#define EQ_LoadingS__Array_x                                       0xB70238

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5965F0
#define EQ_PC__GetAltAbilityIndex_x                                0x7F4F50
#define EQ_PC__GetCombatAbility_x                                  0x7F4FE0
#define EQ_PC__GetCombatAbilityTimer_x                             0x7F5090
#define EQ_PC__GetItemTimerValue_x                                 0x590060
#define EQ_PC__HasLoreItem_x                                       0x58ABB0
#define EQ_PC__AlertInventoryChanged_x                             0x5878B0
#define EQ_PC__GetPcZoneClient_x                                   0x5B0870
#define EQ_PC__RemoveMyAffect_x									   0x58F570

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E59D0
#define EQItemList__add_item_x                                     0x4E5910
#define EQItemList__delete_item_x                                  0x4E5DD0
#define EQItemList__FreeItemList_x                                 0x4E5CD0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487BE0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x59BAD0
#define EQPlayer__dEQPlayer_x                                      0x5A4730
#define EQPlayer__DoAttack_x                                       0x5B6670
#define EQPlayer__EQPlayer_x                                       0x5A6B80
#define EQPlayer__SetNameSpriteState_x                             0x5A14E0
#define EQPlayer__SetNameSpriteTint_x                              0x59CE60
#define EQPlayer__IsBodyType_j_x                                   0x8F5630
#define EQPlayer__IsTargetable_x                                   0x8F5E60

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5AAE50
#define EQPlayerManager__GetSpawnByName_x                          0x5AB2B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56E6F0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56E730
#define KeypressHandler__ClearCommandStateArray_x                  0x56E2D0
#define KeypressHandler__HandleKeyDown_x                           0x56CC20
#define KeypressHandler__HandleKeyUp_x                             0x56CF40
#define KeypressHandler__SaveKeymapping_x                          0x56E3A0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6DD380
#define MapViewMap__SaveEx_x                                       0x6E0C60

#define PlayerPointManager__GetAltCurrency_x                       0x8069B0

// StringTable 
#define StringTable__getString_x                                   0x802470

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x594900

//Doors
#define EQSwitch__UseSwitch_x                                      0x5240E0

//IconCache
#define IconCache__GetIcon_x                                       0x678630

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66F480
#define CContainerMgr__CloseContainer_x                            0x66FC90

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x73E0B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x561A60

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B6930
#define EQ_Spell__SpellAffects_x                                   0x4B69D0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B6A00
#define CharacterZoneClient__CalcAffectChange_x                    0x436C10
#define CLootWnd__LootAll_x                                        0x6D2E20
#define CTargetWnd__GetBuffCaster_x                                0x7838B0
