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
#define __ExpectedVersionDate                                     "Oct 29 2014"
#define __ExpectedVersionTime                                     "17:35:14"
#define __ActualVersionDate_x                                      0xA56888
#define __ActualVersionTime_x                                      0xA56894

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x573EF0
#define __MemChecker1_x                                            0x83B550
#define __MemChecker2_x                                            0x60B250
#define __MemChecker3_x                                            0x60B1A0
#define __MemChecker4_x                                            0x7BF270
#define __EncryptPad0_x                                            0xBC2760
#define __EncryptPad1_x                                            0xD3DB98
#define __EncryptPad2_x                                            0xC09CE8
#define __EncryptPad3_x                                            0xC098E8
#define __EncryptPad4_x                                            0xD1B320
#define __AC1_x                                                    0x77C745
#define __AC2_x                                                    0x529DF7
#define __AC3_x                                                    0x53E4E0
#define __AC4_x                                                    0x544610
#define __AC5_x                                                    0x550C6E
#define __AC6_x                                                    0x5547A2
#define __AC7_x                                                    0x54A71C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10EEE90
#define DI8__Keyboard_x                                            0x10EEE94
#define DI8__Mouse_x                                               0x10EEE98
#define __AltTimerReady_x                                          0xF4E921
#define __Attack_x                                                 0xFE1A37
#define __Autofire_x                                               0xFE1A38
#define __BindList_x                                               0xB86688
#define __bCommandEnabled_x                                        0xF4CA30
#define __Clicks_x                                                 0xF5D568
#define __CommandList_x                                            0xB8A7D0
#define __CurrentMapLabel_x                                        0x10F48E8
#define __CurrentSocial_x                                          0xB4BFBC
#define __DoAbilityList_x                                          0xF93CEC
#define __do_loot_x                                                0x4F1830
#define __DrawHandler_x                                            0x17594FC
#define __GroupCount_x                                             0xF4DFFA

#define __Guilds_x                                                 0xF53AE8
#define __gWorld_x                                                 0xF504B4
#define __HotkeyPage_x                                             0xFDA6EC
#define __HWnd_x                                                   0xFE6D98
#define __InChatMode_x                                             0xF5D494
#define __LastTell_x                                               0xF5F3F4
#define __LMouseHeldTime_x                                         0xF5D5D4
#define __Mouse_x                                                  0x10EEE9C
#define __MouseLook_x                                              0xF5D52E
#define __MouseEventTime_x                                         0xFE2224
#define __NetStatusToggle_x                                        0xF5D531
#define __PCNames_x                                                0xF5EA24
#define __RangeAttackReady_x                                       0xF5E6B8
#define __RMouseHeldTime_x                                         0xF5D5D0
#define __RunWalkState_x                                           0xF5D498
#define __ScreenMode_x                                             0xE9C9F0
#define __ScreenX_x                                                0xF5D44C
#define __ScreenY_x                                                0xF5D448
#define __ScreenXMax_x                                             0xF5D450
#define __ScreenYMax_x                                             0xF5D454
#define __ServerHost_x                                             0xF4DF44
#define __ServerName_x                                             0xF93CAC
#define __ShiftKeyDown_x                                           0xF5DB3C
#define __ShowNames_x                                              0xF5E8C8
#define __Socials_x                                                0xF93DAC
#define __SubscriptionType_x                                       0x1120C78
#define __TargetAggroHolder_x                                      0x10F6B24
#define __GroupAggro_x                                             0x10F6B64
#define __LoginName_x                                              0xFE5970
#define __Inviter_x                                                0xFE19B4


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF505A0
#define instEQZoneInfo_x                                           0xF5D724
#define instKeypressHandler_x                                      0xFE2208
#define pinstActiveBanker_x                                        0xF50558
#define pinstActiveCorpse_x                                        0xF5055C
#define pinstActiveGMaster_x                                       0xF50560
#define pinstActiveMerchant_x                                      0xF50554
#define pinstAggroInfo_x                                           0xD60FD8
#define pinstAltAdvManager_x                                       0xE9DAC8
#define pinstAuraMgr_x                                             0xD6AEA0
#define pinstBandageTarget_x                                       0xF50540
#define pinstCamActor_x                                            0xE9D3D0
#define pinstCDBStr_x                                              0xE9C984
#define pinstCDisplay_x                                            0xF50568
#define pinstCEverQuest_x                                          0x10EF014
#define pinstCharData_x                                            0xF50524
#define pinstCharSpawn_x                                           0xF5054C
#define pinstControlledMissile_x                                   0xF50520
#define pinstControlledPlayer_x                                    0xF5054C
#define pinstCSidlManager_x                                        0x1758910
#define pinstCXWndManager_x                                        0x1758908
#define instDynamicZone_x                                          0xF5D2E0
#define pinstDZMember_x                                            0xF5D3F0
#define pinstDZTimerInfo_x                                         0xF5D3F4
#define pinstEQItemList_x                                          0xF4CC7C
#define instEQMisc_x                                               0xB67A48
#define pinstEQSoundManager_x                                      0xE9DDC8
#define instExpeditionLeader_x                                     0xF5D32A
#define instExpeditionName_x                                       0xF5D36A
#define pinstGroup_x                                               0xF4DFF6
#define pinstImeManager_x                                          0x1758914
#define pinstLocalPlayer_x                                         0xF50538
#define pinstMercenaryData_x                                       0xFE2858
#define pinstMercAltAbilities_x                                    0xE9DCE8
#define pinstModelPlayer_x                                         0xF50564
#define pinstPCData_x                                              0xF50524
#define pinstSkillMgr_x                                            0xFE3690
#define pinstSpawnManager_x                                        0xFE2F78
#define pinstSpellManager_x                                        0xFE37D8
#define pinstSpellSets_x                                           0xFDA750
#define pinstStringTable_x                                         0xF504CC
#define pinstSwitchManager_x                                       0xF4DB88
#define pinstTarget_x                                              0xF50550
#define pinstTargetObject_x                                        0xF50528
#define pinstTargetSwitch_x                                        0xF5052C
#define pinstTaskMember_x                                          0xE9C8D0
#define pinstTrackTarget_x                                         0xF50544
#define pinstTradeTarget_x                                         0xF50534
#define instTributeActive_x                                        0xB67A6D
#define pinstViewActor_x                                           0xE9D3CC
#define pinstWorldData_x                                           0xF50508


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD614B8
#define pinstCAudioTriggersWindow_x                                0xD61348
#define pinstCCharacterSelect_x                                    0xE9D278
#define pinstCFacePick_x                                           0xE9D228
#define pinstCNoteWnd_x                                            0xE9D230
#define pinstCBookWnd_x                                            0xE9D238
#define pinstCPetInfoWnd_x                                         0xE9D23C
#define pinstCTrainWnd_x                                           0xE9D240
#define pinstCSkillsWnd_x                                          0xE9D244
#define pinstCSkillsSelectWnd_x                                    0xE9D248
#define pinstCCombatSkillSelectWnd_x                               0xE9D24C
#define pinstCFriendsWnd_x                                         0xE9D250
#define pinstCAuraWnd_x                                            0xE9D254
#define pinstCRespawnWnd_x                                         0xE9D258
#define pinstCBandolierWnd_x                                       0xE9D25C
#define pinstCPotionBeltWnd_x                                      0xE9D260
#define pinstCAAWnd_x                                              0xE9D264
#define pinstCGroupSearchFiltersWnd_x                              0xE9D268
#define pinstCLoadskinWnd_x                                        0xE9D26C
#define pinstCAlarmWnd_x                                           0xE9D270
#define pinstCMusicPlayerWnd_x                                     0xE9D274
#define pinstCMailWnd_x                                            0xE9D27C
#define pinstCMailCompositionWnd_x                                 0xE9D280
#define pinstCMailAddressBookWnd_x                                 0xE9D284
#define pinstCRaidWnd_x                                            0xE9D28C
#define pinstCRaidOptionsWnd_x                                     0xE9D290
#define pinstCBreathWnd_x                                          0xE9D294
#define pinstCMapViewWnd_x                                         0xE9D298
#define pinstCMapToolbarWnd_x                                      0xE9D29C
#define pinstCEditLabelWnd_x                                       0xE9D2A0
#define pinstCTargetWnd_x                                          0xE9D2A4
#define pinstCColorPickerWnd_x                                     0xE9D2A8
#define pinstCPlayerWnd_x                                          0xE9D2AC
#define pinstCOptionsWnd_x                                         0xE9D2B0
#define pinstCBuffWindowNORMAL_x                                   0xE9D2B4
#define pinstCBuffWindowSHORT_x                                    0xE9D2B8
#define pinstCharacterCreation_x                                   0xE9D2BC
#define pinstCCursorAttachment_x                                   0xE9D2C0
#define pinstCCastingWnd_x                                         0xE9D2C4
#define pinstCCastSpellWnd_x                                       0xE9D2C8
#define pinstCSpellBookWnd_x                                       0xE9D2CC
#define pinstCInventoryWnd_x                                       0xE9D2D0
#define pinstCBankWnd_x                                            0xE9D2D4
#define pinstCQuantityWnd_x                                        0xE9D2D8
#define pinstCLootWnd_x                                            0xE9D2DC
#define pinstCActionsWnd_x                                         0xE9D2E0
#define pinstCCombatAbilityWnd_x                                   0xE9D2E4
#define pinstCMerchantWnd_x                                        0xE9D2E8
#define pinstCTradeWnd_x                                           0xE9D2EC
#define pinstCSelectorWnd_x                                        0xE9D2F0
#define pinstCBazaarWnd_x                                          0xE9D2F4
#define pinstCBazaarSearchWnd_x                                    0xE9D2F8
#define pinstCGiveWnd_x                                            0xE9D314
#define pinstCTrackingWnd_x                                        0xE9D31C
#define pinstCInspectWnd_x                                         0xE9D320
#define pinstCSocialEditWnd_x                                      0xE9D324
#define pinstCFeedbackWnd_x                                        0xE9D328
#define pinstCBugReportWnd_x                                       0xE9D32C
#define pinstCVideoModesWnd_x                                      0xE9D330
#define pinstCTextEntryWnd_x                                       0xE9D338
#define pinstCFileSelectionWnd_x                                   0xE9D33C
#define pinstCCompassWnd_x                                         0xE9D340
#define pinstCPlayerNotesWnd_x                                     0xE9D344
#define pinstCGemsGameWnd_x                                        0xE9D348
#define pinstCTimeLeftWnd_x                                        0xE9D34C
#define pinstCPetitionQWnd_x                                       0xE9D360
#define pinstCSoulmarkWnd_x                                        0xE9D364
#define pinstCStoryWnd_x                                           0xE9D368
#define pinstCJournalTextWnd_x                                     0xE9D36C
#define pinstCJournalCatWnd_x                                      0xE9D370
#define pinstCBodyTintWnd_x                                        0xE9D374
#define pinstCServerListWnd_x                                      0xE9D378
#define pinstCAvaZoneWnd_x                                         0xE9D384
#define pinstCBlockedBuffWnd_x                                     0xE9D388
#define pinstCBlockedPetBuffWnd_x                                  0xE9D38C
#define pinstCInvSlotMgr_x                                         0xE9D3C4
#define pinstCContainerMgr_x                                       0xE9D3C8
#define pinstCAdventureLeaderboardWnd_x                            0x10EF9C0
#define pinstCAdventureRequestWnd_x                                0x10EFA38
#define pinstCAltStorageWnd_x                                      0x10EFD18
#define pinstCAdventureStatsWnd_x                                  0x10EFAB0
#define pinstCBarterMerchantWnd_x                                  0x10F0900
#define pinstCBarterSearchWnd_x                                    0x10F0978
#define pinstCBarterWnd_x                                          0x10F09F0
#define pinstCChatManager_x                                        0x10F1080
#define pinstCDynamicZoneWnd_x                                     0x10F1530
#define pinstCEQMainWnd_x                                          0x10F16C8
#define pinstCFellowshipWnd_x                                      0x10F14C4
#define pinstCFindLocationWnd_x                                    0x10F1998
#define pinstCGroupSearchWnd_x                                     0x10F1C68
#define pinstCGroupWnd_x                                           0x10F1CE0
#define pinstCGuildBankWnd_x                                       0x10F1D58
#define pinstCGuildMgmtWnd_x                                       0x10F3E48
#define pinstCHotButtonWnd_x                                       0x10F3F14
#define pinstCHotButtonWnd1_x                                      0x10F3F14
#define pinstCHotButtonWnd2_x                                      0x10F3F18
#define pinstCHotButtonWnd3_x                                      0x10F3F1C
#define pinstCHotButtonWnd4_x                                      0x10F3F40
#define pinstCItemDisplayManager_x                                 0x10F4238
#define pinstCItemExpTransferWnd_x                                 0x10F42B4
#define pinstCLFGuildWnd_x                                         0x10F4590
#define pinstCMIZoneSelectWnd_x                                    0x10F4B78
#define pinstCConfirmationDialog_x                                 0x10F5280
#define pinstCPopupWndManager_x                                    0x10F5280
#define pinstCProgressionSelectionWnd_x                            0x10F5370
#define pinstCPvPStatsWnd_x                                        0x10F5460
#define pinstCSystemInfoDialogBox_x                                0x10F5B68
#define pinstCTaskWnd_x                                            0x10F6F30
#define pinstCTaskTemplateSelectWnd_x                              0x10F6EB8
#define pinstCTipWndOFDAY_x                                        0x10F7188
#define pinstCTipWndCONTEXT_x                                      0x10F718C
#define pinstCTitleWnd_x                                           0x10F7208
#define pinstCContextMenuManager_x                                 0x1758524
#define pinstCVoiceMacroWnd_x                                      0xFE3E40
#define pinstCHtmlWnd_x                                            0xFE3F38
#define pinstIconCache_x                                           0x10F169C
#define pinstCTradeskillWnd_x                                      0x10F7308

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x509340
#define __ConvertItemTags_x                                        0x4F64F0
#define __ExecuteCmd_x                                             0x4E1030
#define __EQGetTime_x                                              0x83C0B0
#define __get_melee_range_x                                        0x4E7D10
#define __GetGaugeValueFromEQ_x                                    0x77B490
#define __GetLabelFromEQ_x                                         0x77C6D0
#define __GetXTargetType_x                                         0x8F9320
#define __LoadFrontEnd_x                                           0x60A900
#define __NewUIINI_x                                               0x77ADD0
#define __ProcessGameEvents_x                                      0x54D0C0
#define __ProcessMouseEvent_x                                      0x54C860
#define CrashDetected_x                                            0x60C3D0
#define DrawNetStatus_x                                            0x5835E0
#define Util__FastTime_x                                           0x83B3C0
#define Expansion_HoT_x                                            0xF5E824
#define __HelpPath_x                                               0xFE1F90
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A6310
#define AltAdvManager__IsAbilityReady_x                            0x4A6380
#define AltAdvManager__GetAltAbility_x                             0x4A6740

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x453190
#define CharacterZoneClient__MakeMeVisible_x                       0x458250

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x639FB0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x648580

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x563060

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6631B0
#define CChatManager__InitContextMenu_x                            0x663CD0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x822170
#define CChatService__GetFriendName_x                              0x822180

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x668AB0
#define CChatWindow__Clear_x                                       0x668660
#define CChatWindow__WndNotification_x                             0x668FE0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x89A600
#define CComboWnd__Draw_x                                          0x89A7E0
#define CComboWnd__GetCurChoice_x                                  0x89A420
#define CComboWnd__GetListRect_x                                   0x89AA80
#define CComboWnd__GetTextRect_x                                   0x89A660
#define CComboWnd__InsertChoice_x                                  0x89AAF0
#define CComboWnd__SetColors_x                                     0x89A3B0
#define CComboWnd__SetChoice_x                                     0x89A3E0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6721F0
#define CContainerWnd__vftable_x                                   0xA5FFF8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x494B90
#define CDisplay__GetClickedActor_x                                0x48D630
#define CDisplay__GetUserDefinedColor_x                            0x48BEF0
#define CDisplay__GetWorldFilePath_x                               0x48B2F0
#define CDisplay__is3dON_x                                         0x48A6C0
#define CDisplay__ReloadUI_x                                       0x49FFF0
#define CDisplay__WriteTextHD2_x                                   0x490E80

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8BC3C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8AAFB0
#define CEditWnd__GetCharIndexPt_x                                 0x8ABFC0
#define CEditWnd__GetDisplayString_x                               0x8AB160
#define CEditWnd__GetHorzOffset_x                                  0x8AB4A0
#define CEditWnd__GetLineForPrintableChar_x                        0x8ABA90
#define CEditWnd__GetSelStartPt_x                                  0x8AC270
#define CEditWnd__GetSTMLSafeText_x                                0x8AB630
#define CEditWnd__PointFromPrintableChar_x                         0x8ABB80
#define CEditWnd__SelectableCharFromPoint_x                        0x8ABD00
#define CEditWnd__SetEditable_x                                    0x8AB600

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x52A540
#define CEverQuest__DoTellWindow_x                                 0x52FED0
#define CEverQuest__DropHeldItemOnGround_x                         0x538960
#define CEverQuest__dsp_chat_x                                     0x531670
#define CEverQuest__Emote_x                                        0x5318D0
#define CEverQuest__EnterZone_x                                    0x5447A0
#define CEverQuest__GetBodyTypeDesc_x                              0x526E70
#define CEverQuest__GetClassDesc_x                                 0x52CA40
#define CEverQuest__GetClassThreeLetterCode_x                      0x52D040
#define CEverQuest__GetDeityDesc_x                                 0x527750
#define CEverQuest__GetLangDesc_x                                  0x527200
#define CEverQuest__GetRaceDesc_x                                  0x52D200
#define CEverQuest__InterpretCmd_x                                 0x5321B0
#define CEverQuest__LeftClickedOnPlayer_x                          0x548B90
#define CEverQuest__LMouseUp_x                                     0x54AE80
#define CEverQuest__RightClickedOnPlayer_x                         0x549690
#define CEverQuest__RMouseUp_x                                     0x54A6D0
#define CEverQuest__SetGameState_x                                 0x52ABF0
#define CEverQuest__UPCNotificationFlush_x                         0x533350

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x682D60
#define CGaugeWnd__CalcLinesFillRect_x                             0x682DC0
#define CGaugeWnd__Draw_x                                          0x6831F0

// CGuild
#define CGuild__FindMemberByName_x                                 0x424A90

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69FE00

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6ADC20
#define CInvSlotMgr__MoveItem_x                                    0x6AEB60
#define CInvSlotMgr__SelectSlot_x                                  0x6ADCD0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6AD0C0
#define CInvSlot__SliderComplete_x                                 0x6AAA80
#define CInvSlot__GetItemBase_x                                    0x6A9F10

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6AFCE0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x777FE0
#define CItemDisplayWnd__UpdateStrings_x                           0x6B1040

// CLabel 
#define CLabel__Draw_x                                             0x6CBC90

// CListWnd 
#define CListWnd__AddColumn_x                                      0x8885D0
#define CListWnd__AddColumn1_x                                     0x887DB0
#define CListWnd__AddLine_x                                        0x887860
#define CListWnd__AddString_x                                      0x887A70
#define CListWnd__CalculateFirstVisibleLine_x                      0x884940
#define CListWnd__CalculateVSBRange_x                              0x886A60
#define CListWnd__ClearAllSel_x                                    0x883C00
#define CListWnd__CloseAndUpdateEditWindow_x                       0x887440
#define CListWnd__Compare_x                                        0x885440
#define CListWnd__Draw_x                                           0x8866C0
#define CListWnd__DrawColumnSeparators_x                           0x886550
#define CListWnd__DrawHeader_x                                     0x883F10
#define CListWnd__DrawItem_x                                       0x885A90
#define CListWnd__DrawLine_x                                       0x8861F0
#define CListWnd__DrawSeparator_x                                  0x8865F0
#define CListWnd__EnsureVisible_x                                  0x884AA0
#define CListWnd__ExtendSel_x                                      0x8859A0
#define CListWnd__GetColumnMinWidth_x                              0x883620
#define CListWnd__GetColumnWidth_x                                 0x883540
#define CListWnd__GetCurSel_x                                      0x882D30
#define CListWnd__GetItemAtPoint_x                                 0x884D30
#define CListWnd__GetItemAtPoint1_x                                0x884DA0
#define CListWnd__GetItemData_x                                    0x883060
#define CListWnd__GetItemHeight_x                                  0x8845A0
#define CListWnd__GetItemIcon_x                                    0x883240
#define CListWnd__GetItemRect_x                                    0x884B70
#define CListWnd__GetItemText_x                                    0x8830F0
#define CListWnd__GetSelList_x                                     0x887CA0
#define CListWnd__GetSeparatorRect_x                               0x885360
#define CListWnd__RemoveLine_x                                     0x887C50
#define CListWnd__SetColors_x                                      0x882E80
#define CListWnd__SetColumnJustification_x                         0x8838F0
#define CListWnd__SetColumnWidth_x                                 0x8835D0
#define CListWnd__SetCurSel_x                                      0x882D70
#define CListWnd__SetItemColor_x                                   0x887120
#define CListWnd__SetItemData_x                                    0x883CB0
#define CListWnd__SetItemText_x                                    0x886F60
#define CListWnd__ShiftColumnSeparator_x                           0x886DF0
#define CListWnd__Sort_x                                           0x888730
#define CListWnd__ToggleSel_x                                      0x883B80

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6E5000

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x706350
#define CMerchantWnd__RequestBuyItem_x                             0x70D180
#define CMerchantWnd__RequestSellItem_x                            0x7352D0
#define CMerchantWnd__SelectRecoverySlot_x                         0x706600
#define CMerchantWnd__SelectBuySellSlot_x                          0x705860
#define CMerchantWnd__ActualSelect_x                               0x70A0B0

// CObfuscator
#define CObfuscator__doit_x                                        0x802540

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x89FCB0
#define CSidlManager__CreateLabel_x                                0x76E000

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x6312A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6311C0
#define CSidlScreenWnd__ConvertToRes_x                             0x8BC2A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x88D6E0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x88EBE0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x88EC90
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x88E150
#define CSidlScreenWnd__DrawSidlPiece_x                            0x88D1C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x88C900
#define CSidlScreenWnd__GetSidlPiece_x                             0x88D3B0
#define CSidlScreenWnd__Init1_x                                    0x88E8B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x88D790
#define CSidlScreenWnd__LoadIniListWnd_x                           0x88CAC0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x88E3A0
#define CSidlScreenWnd__StoreIniInfo_x                             0x88C3C0
#define CSidlScreenWnd__StoreIniVis_x                              0x88C890
#define CSidlScreenWnd__WndNotification_x                          0x88E630
#define CSidlScreenWnd__GetChildItem_x                             0x88C9D0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x893560

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5CC7F0
#define CSkillMgr__GetSkillCap_x                                   0x5CC990
#define CSkillMgr__GetNameToken_x                                  0x5CC460

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8C6280
#define CSliderWnd__SetValue_x                                     0x8C6450
#define CSliderWnd__SetNumTicks_x                                  0x8C6BD0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x775C80

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8B66A0
#define CStmlWnd__CalculateHSBRange_x                              0x8AEC50
#define CStmlWnd__CalculateVSBRange_x                              0x8AEBC0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8AEDD0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8AF6B0
#define CStmlWnd__ForceParseNow_x                                  0x8B6FF0
#define CStmlWnd__GetNextTagPiece_x                                0x8AF5B0
#define CStmlWnd__GetSTMLText_x                                    0x667F00
#define CStmlWnd__GetVisibleText_x                                 0x8B0100
#define CStmlWnd__InitializeWindowVariables_x                      0x8B2490
#define CStmlWnd__MakeStmlColorTag_x                               0x8ADEC0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8ADF20
#define CStmlWnd__SetSTMLText_x                                    0x8B3D00
#define CStmlWnd__StripFirstSTMLLines_x                            0x8B6340
#define CStmlWnd__UpdateHistoryString_x                            0x8B1040

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8BDA90
#define CTabWnd__DrawCurrentPage_x                                 0x8BD300
#define CTabWnd__DrawTab_x                                         0x8BD0D0
#define CTabWnd__GetCurrentPage_x                                  0x8BD6D0
#define CTabWnd__GetPageInnerRect_x                                0x8BCDC0
#define CTabWnd__GetTabInnerRect_x                                 0x8BCFC0
#define CTabWnd__GetTabRect_x                                      0x8BCE90
#define CTabWnd__InsertPage_x                                      0x8BDD80
#define CTabWnd__SetPage_x                                         0x8BD700
#define CTabWnd__SetPageRect_x                                     0x8BD9D0
#define CTabWnd__UpdatePage_x                                      0x8BDD20

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x420790

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B9B00

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8C2C40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x880F20

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x411A60
#define CXStr__CXStr1_x                                            0x7AC300
#define CXStr__CXStr3_x                                            0x838450
#define CXStr__dCXStr_x                                            0x404880
#define CXStr__operator_equal_x                                    0x8385C0
#define CXStr__operator_equal1_x                                   0x838610
#define CXStr__operator_plus_equal1_x                              0x8396F0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8927E0
#define CXWnd__Center_x                                            0x8989F0
#define CXWnd__ClrFocus_x                                          0x8923B0
#define CXWnd__DoAllDrawing_x                                      0x898640
#define CXWnd__DrawChildren_x                                      0x8987E0
#define CXWnd__DrawColoredRect_x                                   0x892B90
#define CXWnd__DrawTooltip_x                                       0x892E40
#define CXWnd__DrawTooltipAtPoint_x                                0x8975E0
#define CXWnd__GetBorderFrame_x                                    0x893250
#define CXWnd__GetChildWndAt_x                                     0x896580
#define CXWnd__GetClientClipRect_x                                 0x893060
#define CXWnd__GetScreenClipRect_x                                 0x897CD0
#define CXWnd__GetScreenRect_x                                     0x893400
#define CXWnd__GetTooltipRect_x                                    0x892CD0
#define CXWnd__GetWindowTextA_x                                    0x411AA0
#define CXWnd__IsActive_x                                          0x8A5D40
#define CXWnd__IsDescendantOf_x                                    0x8931A0
#define CXWnd__IsReallyVisible_x                                   0x896560
#define CXWnd__IsType_x                                            0x8BF420
#define CXWnd__Move_x                                              0x895C40
#define CXWnd__Move1_x                                             0x898300
#define CXWnd__ProcessTransition_x                                 0x892780
#define CXWnd__Refade_x                                            0x892550
#define CXWnd__Resize_x                                            0x8934C0
#define CXWnd__Right_x                                             0x897AD0
#define CXWnd__SetFocus_x                                          0x894DB0
#define CXWnd__SetFont_x                                           0x892400
#define CXWnd__SetKeyTooltip_x                                     0x893730
#define CXWnd__SetMouseOver_x                                      0x898000
#define CXWnd__StartFade_x                                         0x892830
#define CXWnd__GetChildItem_x                                      0x897F40

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A7660
#define CXWndManager__DrawWindows_x                                0x8A72A0
#define CXWndManager__GetKeyboardFlags_x                           0x8A58B0
#define CXWndManager__HandleKeyboardMsg_x                          0x8A61D0
#define CXWndManager__RemoveWnd_x                                  0x8A5ED0

// CDBStr
#define CDBStr__GetString_x                                        0x488AD0

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8F6380
#define EQ_Character__CastSpell_x                                  0x43CB10
#define EQ_Character__Cur_HP_x                                     0x452850
#define EQ_Character__GetAACastingTimeModifier_x                   0x435C10
#define EQ_Character__GetCharInfo2_x                               0x80CCE0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42DF40
#define EQ_Character__GetFocusRangeModifier_x                      0x42E120
#define EQ_Character__Max_Endurance_x                              0x595180
#define EQ_Character__Max_HP_x                                     0x448B40
#define EQ_Character__Max_Mana_x                                   0x594FB0
#define EQ_Character__doCombatAbility_x                            0x5925A0
#define EQ_Character__UseSkill_x                                   0x45D390
#define EQ_Character__GetConLevel_x                                0x587C60
#define EQ_Character__IsExpansionFlag_x                            0x410FB0
#define EQ_Character__TotalEffect_x                                0x43AC40

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x5686D0
#define EQ_Item__CreateItemTagString_x                             0x7ECE40
#define EQ_Item__IsStackable_x                                     0x7E1030
#define EQ_Item__GetImageNum_x                                     0x7E3CC0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A8400
#define EQ_LoadingS__Array_x                                       0xB75238

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x596920
#define EQ_PC__GetAltAbilityIndex_x                                0x7F52A0
#define EQ_PC__GetCombatAbility_x                                  0x7F5330
#define EQ_PC__GetCombatAbilityTimer_x                             0x7F53E0
#define EQ_PC__GetItemTimerValue_x                                 0x590390
#define EQ_PC__HasLoreItem_x                                       0x58AF30
#define EQ_PC__AlertInventoryChanged_x                             0x587C30
#define EQ_PC__GetPcZoneClient_x                                   0x5B0CA0
#define EQ_PC__RemoveMyAffect_x									   0x58F8A0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E5CC0
#define EQItemList__add_item_x                                     0x4E5C00
#define EQItemList__delete_item_x                                  0x4E60C0
#define EQItemList__FreeItemList_x                                 0x4E5FC0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487F90

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x59BE10
#define EQPlayer__dEQPlayer_x                                      0x5A4A70
#define EQPlayer__DoAttack_x                                       0x5B6AA0
#define EQPlayer__EQPlayer_x                                       0x5A6EC0
#define EQPlayer__SetNameSpriteState_x                             0x5A1820
#define EQPlayer__SetNameSpriteTint_x                              0x59D1A0
#define EQPlayer__IsBodyType_j_x                                   0x8F5630
#define EQPlayer__IsTargetable_x                                   0x8F5E60

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5AB1F0
#define EQPlayerManager__GetSpawnByName_x                          0x5AB650

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56E970
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56E9B0
#define KeypressHandler__ClearCommandStateArray_x                  0x56E550
#define KeypressHandler__HandleKeyDown_x                           0x56CEA0
#define KeypressHandler__HandleKeyUp_x                             0x56D1C0
#define KeypressHandler__SaveKeymapping_x                          0x56E620

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6DD3E0
#define MapViewMap__SaveEx_x                                       0x6E0CC0

#define PlayerPointManager__GetAltCurrency_x                       0x806E90

// StringTable 
#define StringTable__getString_x                                   0x8027E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x594C30

//Doors
#define EQSwitch__UseSwitch_x                                      0x5242B0

//IconCache
#define IconCache__GetIcon_x                                       0x678680

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66F520
#define CContainerMgr__CloseContainer_x                            0x66FD30

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x73E350

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x561B20

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B6C40
#define EQ_Spell__SpellAffects_x                                   0x4B6CE0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B6D10
#define CharacterZoneClient__CalcAffectChange_x                    0x436F30
#define CLootWnd__LootAll_x                                        0x6D2E80
#define CTargetWnd__GetBuffCaster_x                                0x783A00
