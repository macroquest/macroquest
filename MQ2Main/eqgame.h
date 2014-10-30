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
#define __ExpectedVersionDate                                     "Oct 23 2014"
#define __ExpectedVersionTime                                     "19:09:15"
#define __ActualVersionDate_x                                      0xA51880
#define __ActualVersionTime_x                                      0xA5188C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x574780
#define __MemChecker1_x                                            0x83BB50
#define __MemChecker2_x                                            0x60BEF0
#define __MemChecker3_x                                            0x60BE40
#define __MemChecker4_x                                            0x7BFF50
#define __EncryptPad0_x                                            0xBBD760
#define __EncryptPad1_x                                            0xD38B98
#define __EncryptPad2_x                                            0xC04CE8
#define __EncryptPad3_x                                            0xC048E8
#define __EncryptPad4_x                                            0xD16320
#define __AC1_x                                                    0x77D855
#define __AC2_x                                                    0x52A5A7
#define __AC3_x                                                    0x53EC80
#define __AC4_x                                                    0x544DB0
#define __AC5_x                                                    0x55141E
#define __AC6_x                                                    0x554F52
#define __AC7_x                                                    0x54AECC
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
#define __do_loot_x                                                0x4F1E70
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
#define pinstCamActor_x                                            0xE97D14
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
#define pinstViewActor_x                                           0xE97D10
#define pinstWorldData_x                                           0xF4AE48


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD5BDF8
#define pinstCAudioTriggersWindow_x                                0xD5BC88
#define pinstCCharacterSelect_x                                    0xE97BBC
#define pinstCFacePick_x                                           0xE9796C
#define pinstCNoteWnd_x                                            0xE97B74
#define pinstCBookWnd_x                                            0xE97B7C
#define pinstCPetInfoWnd_x                                         0xE97B80
#define pinstCTrainWnd_x                                           0xE97B84
#define pinstCSkillsWnd_x                                          0xE97B88
#define pinstCSkillsSelectWnd_x                                    0xE97B8C
#define pinstCCombatSkillSelectWnd_x                               0xE97B90
#define pinstCFriendsWnd_x                                         0xE97B94
#define pinstCAuraWnd_x                                            0xE97B98
#define pinstCRespawnWnd_x                                         0xE97B9C
#define pinstCBandolierWnd_x                                       0xE97BA0
#define pinstCPotionBeltWnd_x                                      0xE97BA4
#define pinstCAAWnd_x                                              0xE97BA8
#define pinstCGroupSearchFiltersWnd_x                              0xE97BAC
#define pinstCLoadskinWnd_x                                        0xE97BB0
#define pinstCAlarmWnd_x                                           0xE97BB4
#define pinstCMusicPlayerWnd_x                                     0xE97BB8
#define pinstCMailWnd_x                                            0xE97BC0
#define pinstCMailCompositionWnd_x                                 0xE97BC4
#define pinstCMailAddressBookWnd_x                                 0xE97BC8
#define pinstCRaidWnd_x                                            0xE97BD0
#define pinstCRaidOptionsWnd_x                                     0xE97BD4
#define pinstCBreathWnd_x                                          0xE97BD8
#define pinstCMapViewWnd_x                                         0xE97BDC
#define pinstCMapToolbarWnd_x                                      0xE97BE0
#define pinstCEditLabelWnd_x                                       0xE97BE4
#define pinstCTargetWnd_x                                          0xE97BE8
#define pinstCColorPickerWnd_x                                     0xE97BEC
#define pinstCPlayerWnd_x                                          0xE97BF0
#define pinstCOptionsWnd_x                                         0xE97BF4
#define pinstCBuffWindowNORMAL_x                                   0xE97BF8
#define pinstCBuffWindowSHORT_x                                    0xE97BFC
#define pinstCharacterCreation_x                                   0xE97C00
#define pinstCCursorAttachment_x                                   0xE97C04
#define pinstCCastingWnd_x                                         0xE97C08
#define pinstCCastSpellWnd_x                                       0xE97C0C
#define pinstCSpellBookWnd_x                                       0xE97C10
#define pinstCInventoryWnd_x                                       0xE97C14
#define pinstCBankWnd_x                                            0xE97C18
#define pinstCQuantityWnd_x                                        0xE97C1C
#define pinstCLootWnd_x                                            0xE97C20
#define pinstCActionsWnd_x                                         0xE97C24
#define pinstCCombatAbilityWnd_x                                   0xE97C28
#define pinstCMerchantWnd_x                                        0xE97C2C
#define pinstCTradeWnd_x                                           0xE97C30
#define pinstCSelectorWnd_x                                        0xE97C34
#define pinstCBazaarWnd_x                                          0xE97C38
#define pinstCBazaarSearchWnd_x                                    0xE97C3C
#define pinstCGiveWnd_x                                            0xE97C58
#define pinstCTrackingWnd_x                                        0xE97C60
#define pinstCInspectWnd_x                                         0xE97C64
#define pinstCSocialEditWnd_x                                      0xE97C68
#define pinstCFeedbackWnd_x                                        0xE97C6C
#define pinstCBugReportWnd_x                                       0xE97C70
#define pinstCVideoModesWnd_x                                      0xE97C74
#define pinstCTextEntryWnd_x                                       0xE97C7C
#define pinstCFileSelectionWnd_x                                   0xE97C80
#define pinstCCompassWnd_x                                         0xE97C84
#define pinstCPlayerNotesWnd_x                                     0xE97C88
#define pinstCGemsGameWnd_x                                        0xE97C8C
#define pinstCTimeLeftWnd_x                                        0xE97C90
#define pinstCPetitionQWnd_x                                       0xE97CA4
#define pinstCSoulmarkWnd_x                                        0xE97CA8
#define pinstCStoryWnd_x                                           0xE97CAC
#define pinstCJournalTextWnd_x                                     0xE97CB0
#define pinstCJournalCatWnd_x                                      0xE97CB4
#define pinstCBodyTintWnd_x                                        0xE97CB8
#define pinstCServerListWnd_x                                      0xE97CBC
#define pinstCAvaZoneWnd_x                                         0xE97CC8
#define pinstCBlockedBuffWnd_x                                     0xE97CCC
#define pinstCBlockedPetBuffWnd_x                                  0xE97CD0
#define pinstCInvSlotMgr_x                                         0xE97D08
#define pinstCContainerMgr_x                                       0xE97D0C
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
#define __CastRay_x                                                0x509980
#define __ConvertItemTags_x                                        0x4F6B30
#define __ExecuteCmd_x                                             0x4E1680
#define __EQGetTime_x                                              0x83C6B0
#define __get_melee_range_x                                        0x4E8350
#define __GetGaugeValueFromEQ_x                                    0x77C5A0
#define __GetLabelFromEQ_x                                         0x77D7E0
#define __GetXTargetType_x                                         0x8F9B00
#define __LoadFrontEnd_x                                           0x60B5A0
#define __NewUIINI_x                                               0x77BEE0
#define __ProcessGameEvents_x                                      0x54D870
#define __ProcessMouseEvent_x                                      0x54D010
#define CrashDetected_x                                            0x60D070
#define DrawNetStatus_x                                            0x583F80
#define Util__FastTime_x                                           0x83B9C0
#define Expansion_HoT_x                                            0xF59164
#define __HelpPath_x                                               0xFDC8D0
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A6070
#define AltAdvManager__IsAbilityReady_x                            0x4A60E0
#define AltAdvManager__GetAltAbility_x                             0x4A64A0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x452DE0
#define CharacterZoneClient__MakeMeVisible_x                       0x457EA0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x63ACC0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x648E50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x563810

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x663FD0
#define CChatManager__InitContextMenu_x                            0x664AF0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x822570
#define CChatService__GetFriendName_x                              0x822580

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6698E0
#define CChatWindow__Clear_x                                       0x669490
#define CChatWindow__WndNotification_x                             0x669E20

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x89AF20
#define CComboWnd__Draw_x                                          0x89B100
#define CComboWnd__GetCurChoice_x                                  0x89AD40
#define CComboWnd__GetListRect_x                                   0x89B3A0
#define CComboWnd__GetTextRect_x                                   0x89AF80
#define CComboWnd__InsertChoice_x                                  0x89B410
#define CComboWnd__SetColors_x                                     0x89ACD0
#define CComboWnd__SetChoice_x                                     0x89AD00

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x672FB0
#define CContainerWnd__vftable_x                                   0xA5AFE8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4949A0
#define CDisplay__GetClickedActor_x                                0x48D440
#define CDisplay__GetUserDefinedColor_x                            0x48BD00
#define CDisplay__GetWorldFilePath_x                               0x48B100
#define CDisplay__is3dON_x                                         0x48A4D0
#define CDisplay__ReloadUI_x                                       0x49FE00
#define CDisplay__WriteTextHD2_x                                   0x490C90

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8BCCE0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8AB870
#define CEditWnd__GetCharIndexPt_x                                 0x8AC8A0
#define CEditWnd__GetDisplayString_x                               0x8ABA20
#define CEditWnd__GetHorzOffset_x                                  0x8ABD60
#define CEditWnd__GetLineForPrintableChar_x                        0x8AC360
#define CEditWnd__GetSelStartPt_x                                  0x8ACB60
#define CEditWnd__GetSTMLSafeText_x                                0x8ABF00
#define CEditWnd__PointFromPrintableChar_x                         0x8AC450
#define CEditWnd__SelectableCharFromPoint_x                        0x8AC5D0
#define CEditWnd__SetEditable_x                                    0x8ABED0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x52ACF0
#define CEverQuest__DoTellWindow_x                                 0x530670
#define CEverQuest__DropHeldItemOnGround_x                         0x539100
#define CEverQuest__dsp_chat_x                                     0x531E10
#define CEverQuest__Emote_x                                        0x532070
#define CEverQuest__EnterZone_x                                    0x544F40
#define CEverQuest__GetBodyTypeDesc_x                              0x527620
#define CEverQuest__GetClassDesc_x                                 0x52D1F0
#define CEverQuest__GetClassThreeLetterCode_x                      0x52D7F0
#define CEverQuest__GetDeityDesc_x                                 0x527F00
#define CEverQuest__GetLangDesc_x                                  0x5279B0
#define CEverQuest__GetRaceDesc_x                                  0x52D9B0
#define CEverQuest__InterpretCmd_x                                 0x532950
#define CEverQuest__LeftClickedOnPlayer_x                          0x549340
#define CEverQuest__LMouseUp_x                                     0x54B630
#define CEverQuest__RightClickedOnPlayer_x                         0x549E40
#define CEverQuest__RMouseUp_x                                     0x54AE80
#define CEverQuest__SetGameState_x                                 0x52B3A0
#define CEverQuest__UPCNotificationFlush_x                         0x533AF0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x683B50
#define CGaugeWnd__CalcLinesFillRect_x                             0x683BB0
#define CGaugeWnd__Draw_x                                          0x683FE0

// CGuild
#define CGuild__FindMemberByName_x                                 0x424690

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6A0C10

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6AEA90
#define CInvSlotMgr__MoveItem_x                                    0x6AF9D0
#define CInvSlotMgr__SelectSlot_x                                  0x6AEB40

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6ADF30
#define CInvSlot__SliderComplete_x                                 0x6AB900
#define CInvSlot__GetItemBase_x                                    0x6AAD50

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6B0B80

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7790A0
#define CItemDisplayWnd__UpdateStrings_x                           0x6B1EF0

// CLabel 
#define CLabel__Draw_x                                             0x6CCC70

// CListWnd 
#define CListWnd__AddColumn_x                                      0x888D80
#define CListWnd__AddColumn1_x                                     0x888560
#define CListWnd__AddLine_x                                        0x888010
#define CListWnd__AddString_x                                      0x888220
#define CListWnd__CalculateFirstVisibleLine_x                      0x8850D0
#define CListWnd__CalculateVSBRange_x                              0x887210
#define CListWnd__ClearAllSel_x                                    0x884380
#define CListWnd__CloseAndUpdateEditWindow_x                       0x887BF0
#define CListWnd__Compare_x                                        0x885BE0
#define CListWnd__Draw_x                                           0x886E70
#define CListWnd__DrawColumnSeparators_x                           0x886D00
#define CListWnd__DrawHeader_x                                     0x884690
#define CListWnd__DrawItem_x                                       0x886230
#define CListWnd__DrawLine_x                                       0x8869A0
#define CListWnd__DrawSeparator_x                                  0x886DA0
#define CListWnd__EnsureVisible_x                                  0x885230
#define CListWnd__ExtendSel_x                                      0x886140
#define CListWnd__GetColumnMinWidth_x                              0x883DA0
#define CListWnd__GetColumnWidth_x                                 0x883CC0
#define CListWnd__GetCurSel_x                                      0x883490
#define CListWnd__GetItemAtPoint_x                                 0x8854D0
#define CListWnd__GetItemAtPoint1_x                                0x885540
#define CListWnd__GetItemData_x                                    0x8837D0
#define CListWnd__GetItemHeight_x                                  0x884D20
#define CListWnd__GetItemIcon_x                                    0x8839B0
#define CListWnd__GetItemRect_x                                    0x885310
#define CListWnd__GetItemText_x                                    0x883860
#define CListWnd__GetSelList_x                                     0x888450
#define CListWnd__GetSeparatorRect_x                               0x885B00
#define CListWnd__RemoveLine_x                                     0x888400
#define CListWnd__SetColors_x                                      0x8835E0
#define CListWnd__SetColumnJustification_x                         0x884070
#define CListWnd__SetColumnWidth_x                                 0x883D50
#define CListWnd__SetCurSel_x                                      0x8834D0
#define CListWnd__SetItemColor_x                                   0x8878D0
#define CListWnd__SetItemData_x                                    0x884430
#define CListWnd__SetItemText_x                                    0x887710
#define CListWnd__ShiftColumnSeparator_x                           0x8875A0
#define CListWnd__Sort_x                                           0x888EE0
#define CListWnd__ToggleSel_x                                      0x884300

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6E6250

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x707370
#define CMerchantWnd__RequestBuyItem_x                             0x70E1A0
#define CMerchantWnd__RequestSellItem_x                            0x7363D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x707620
#define CMerchantWnd__SelectBuySellSlot_x                          0x706880
#define CMerchantWnd__ActualSelect_x                               0x70B0D0

// CObfuscator
#define CObfuscator__doit_x                                        0x802A60

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8A0620
#define CSidlManager__CreateLabel_x                                0x76F010

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x631FD0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x631EF0
#define CSidlScreenWnd__ConvertToRes_x                             0x8BCBC0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x88DEE0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x88F3D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x88F480
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x88E950
#define CSidlScreenWnd__DrawSidlPiece_x                            0x88D9C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x88D0F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x88DBB0
#define CSidlScreenWnd__Init1_x                                    0x88F0B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x88DF90
#define CSidlScreenWnd__LoadIniListWnd_x                           0x88D2B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x88EBA0
#define CSidlScreenWnd__StoreIniInfo_x                             0x88CBB0
#define CSidlScreenWnd__StoreIniVis_x                              0x88D080
#define CSidlScreenWnd__WndNotification_x                          0x88EE30
#define CSidlScreenWnd__GetChildItem_x                             0x88D1C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x893E60

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5CD430
#define CSkillMgr__GetSkillCap_x                                   0x5CD5D0
#define CSkillMgr__GetNameToken_x                                  0x5CD0A0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8C6B70
#define CSliderWnd__SetValue_x                                     0x8C6D40
#define CSliderWnd__SetNumTicks_x                                  0x8C74C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x776D40

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8B6FB0
#define CStmlWnd__CalculateHSBRange_x                              0x8AF4D0
#define CStmlWnd__CalculateVSBRange_x                              0x8AF560
#define CStmlWnd__CanBreakAtCharacter_x                            0x8AF6E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8AFFC0
#define CStmlWnd__ForceParseNow_x                                  0x8B7900
#define CStmlWnd__GetNextTagPiece_x                                0x8AFEC0
#define CStmlWnd__GetSTMLText_x                                    0x668D30
#define CStmlWnd__GetVisibleText_x                                 0x8B0A10
#define CStmlWnd__InitializeWindowVariables_x                      0x8B2DA0
#define CStmlWnd__MakeStmlColorTag_x                               0x8AE7D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8AE830
#define CStmlWnd__SetSTMLText_x                                    0x8B4610
#define CStmlWnd__StripFirstSTMLLines_x                            0x8B6C50
#define CStmlWnd__UpdateHistoryString_x                            0x8B1950

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8BE3C0
#define CTabWnd__DrawCurrentPage_x                                 0x8BDC30
#define CTabWnd__DrawTab_x                                         0x8BD9F0
#define CTabWnd__GetCurrentPage_x                                  0x8BE000
#define CTabWnd__GetPageInnerRect_x                                0x8BD6E0
#define CTabWnd__GetTabInnerRect_x                                 0x8BD8E0
#define CTabWnd__GetTabRect_x                                      0x8BD7B0
#define CTabWnd__InsertPage_x                                      0x8BE6B0
#define CTabWnd__SetPage_x                                         0x8BE030
#define CTabWnd__SetPageRect_x                                     0x8BE300
#define CTabWnd__UpdatePage_x                                      0x8BE650

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x420380

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BA420

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8C3530

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x881600

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x570E20
#define CXStr__CXStr1_x                                            0x42EED0
#define CXStr__CXStr3_x                                            0x838A50
#define CXStr__dCXStr_x                                            0x41D7E0
#define CXStr__operator_equal_x                                    0x838BC0
#define CXStr__operator_equal1_x                                   0x838C10
#define CXStr__operator_plus_equal1_x                              0x839CF0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x893080
#define CXWnd__Center_x                                            0x899350
#define CXWnd__ClrFocus_x                                          0x892C50
#define CXWnd__DoAllDrawing_x                                      0x898FA0
#define CXWnd__DrawChildren_x                                      0x899140
#define CXWnd__DrawColoredRect_x                                   0x893440
#define CXWnd__DrawTooltip_x                                       0x8936F0
#define CXWnd__DrawTooltipAtPoint_x                                0x897EF0
#define CXWnd__GetBorderFrame_x                                    0x893B30
#define CXWnd__GetChildWndAt_x                                     0x896EA0
#define CXWnd__GetClientClipRect_x                                 0x893900
#define CXWnd__GetScreenClipRect_x                                 0x8985F0
#define CXWnd__GetScreenRect_x                                     0x893D00
#define CXWnd__GetTooltipRect_x                                    0x893580
#define CXWnd__GetWindowTextA_x                                    0x411990
#define CXWnd__IsActive_x                                          0x8A65E0
#define CXWnd__IsDescendantOf_x                                    0x893A70
#define CXWnd__IsReallyVisible_x                                   0x896E80
#define CXWnd__IsType_x                                            0x8BFD50
#define CXWnd__Move_x                                              0x896580
#define CXWnd__Move1_x                                             0x898C40
#define CXWnd__ProcessTransition_x                                 0x893030
#define CXWnd__Refade_x                                            0x892E00
#define CXWnd__Resize_x                                            0x893DC0
#define CXWnd__Right_x                                             0x8983F0
#define CXWnd__SetFocus_x                                          0x8956D0
#define CXWnd__SetFont_x                                           0x892CA0
#define CXWnd__SetKeyTooltip_x                                     0x894030
#define CXWnd__SetMouseOver_x                                      0x898920
#define CXWnd__StartFade_x                                         0x8930D0
#define CXWnd__GetChildItem_x                                      0x898860

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A7F20
#define CXWndManager__DrawWindows_x                                0x8A7B60
#define CXWndManager__GetKeyboardFlags_x                           0x8A6110
#define CXWndManager__HandleKeyboardMsg_x                          0x8A6A80
#define CXWndManager__RemoveWnd_x                                  0x8A6770

// CDBStr
#define CDBStr__GetString_x                                        0x488900

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8F6B70
#define EQ_Character__CastSpell_x                                  0x43C790
#define EQ_Character__Cur_HP_x                                     0x4524A0
#define EQ_Character__GetAACastingTimeModifier_x                   0x435860
#define EQ_Character__GetCharInfo2_x                               0x80D110
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42DAE0
#define EQ_Character__GetFocusRangeModifier_x                      0x42DCC0
#define EQ_Character__Max_Endurance_x                              0x595EB0
#define EQ_Character__Max_HP_x                                     0x4487B0
#define EQ_Character__Max_Mana_x                                   0x595CE0
#define EQ_Character__doCombatAbility_x                            0x5932D0
#define EQ_Character__UseSkill_x                                   0x45CFD0
#define EQ_Character__GetConLevel_x                                0x588570
#define EQ_Character__IsExpansionFlag_x                            0x410EC0
#define EQ_Character__TotalEffect_x                                0x43A8C0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x568E60
#define EQ_Item__CreateItemTagString_x                             0x7ED6C0
#define EQ_Item__IsStackable_x                                     0x7E1B70
#define EQ_Item__GetImageNum_x                                     0x7E48A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A81E0
#define EQ_LoadingS__Array_x                                       0xB70238

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x597640
#define EQ_PC__GetAltAbilityIndex_x                                0x7F5830
#define EQ_PC__GetCombatAbility_x                                  0x7F58C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x7F5970
#define EQ_PC__GetItemTimerValue_x                                 0x5910A0
#define EQ_PC__HasLoreItem_x                                       0x58B860
#define EQ_PC__AlertInventoryChanged_x                             0x588540
#define EQ_PC__GetPcZoneClient_x                                   0x5B1950
#define EQ_PC__RemoveMyAffect_x									   0x5905B0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E6310
#define EQItemList__add_item_x                                     0x4E6250
#define EQItemList__delete_item_x                                  0x4E6710
#define EQItemList__FreeItemList_x                                 0x4E6610

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487C80

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x59CB00
#define EQPlayer__dEQPlayer_x                                      0x5A5760
#define EQPlayer__DoAttack_x                                       0x5B7740
#define EQPlayer__EQPlayer_x                                       0x5A7BB0
#define EQPlayer__SetNameSpriteState_x                             0x5A2510
#define EQPlayer__SetNameSpriteTint_x                              0x59DE90
#define EQPlayer__IsBodyType_j_x                                   0x8F5E20
#define EQPlayer__IsTargetable_x                                   0x8F6650

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5ABEE0
#define EQPlayerManager__GetSpawnByName_x                          0x5AC340

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56F150
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56F190
#define KeypressHandler__ClearCommandStateArray_x                  0x56ED30
#define KeypressHandler__HandleKeyDown_x                           0x56D680
#define KeypressHandler__HandleKeyUp_x                             0x56D9A0
#define KeypressHandler__SaveKeymapping_x                          0x56EE00

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6DE630
#define MapViewMap__SaveEx_x                                       0x6E1F10

#define PlayerPointManager__GetAltCurrency_x                       0x807210

// StringTable 
#define StringTable__getString_x                                   0x802D00

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x595960

//Doors
#define EQSwitch__UseSwitch_x                                      0x524A60

//IconCache
#define IconCache__GetIcon_x                                       0x679430

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6702D0
#define CContainerMgr__CloseContainer_x                            0x670AE0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x73F380

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5622D0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B66B0
#define EQ_Spell__SpellAffects_x                                   0x4B6750
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B6780
#define CharacterZoneClient__CalcAffectChange_x                    0x436B80
#define CLootWnd__LootAll_x                                        0x6D3FC0
#define CTargetWnd__GetBuffCaster_x                                0x784B90
