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
#define __ExpectedVersionDate                                     "Feb 12 2015"
#define __ExpectedVersionTime                                     "13:46:31"
#define __ActualVersionDate_x                                      0xA78058
#define __ActualVersionTime_x                                      0xA78064

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x58EB40
#define __MemChecker1_x                                            0x857390
#define __MemChecker2_x                                            0x626810
#define __MemChecker3_x                                            0x626760
#define __MemChecker4_x                                            0x7DB4C0
#define __EncryptPad0_x                                            0xBF2ED0
#define __EncryptPad1_x                                            0xD771C0
#define __EncryptPad2_x                                            0xC3BE50
#define __EncryptPad3_x                                            0xC3BA50
#define __EncryptPad4_x                                            0xD538E8
#define __AC1_x                                                    0x7986B5
#define __AC2_x                                                    0x544EC7
#define __AC3_x                                                    0x5596C0
#define __AC4_x                                                    0x55FB00
#define __AC5_x                                                    0x56B8AE
#define __AC6_x                                                    0x56F402
#define __AC7_x                                                    0x565F9C
#define __AC1_Data                                                 0x11111111

// Direct Input
#define DI8__Main_x                                                0x1128F90
#define DI8__Keyboard_x                                            0x1128F94
#define DI8__Mouse_x                                               0x1128F98
#define __AltTimerReady_x                                          0xF88911
#define __Attack_x                                                 0x101BB1F
#define __Autofire_x                                               0x101BB20
#define __BindList_x                                               0xBB5938
#define __bCommandEnabled_x                                        0xF86A20
#define __Clicks_x                                                 0xF97680
#define __CommandList_x                                            0xBB9C00
#define __CurrentMapLabel_x                                        0x112E9E8
#define __CurrentSocial_x                                          0xB72EC0
#define __DoAbilityList_x                                          0xFCDDD4
#define __do_loot_x                                                0x50C850
#define __DrawHandler_x                                            0x17935F4
#define __GroupCount_x                                             0xF87FEA

#define __Guilds_x                                                 0xF8DC00
#define __gWorld_x                                                 0xF8A4A4
#define __HotkeyPage_x                                             0x10147D4
#define __HWnd_x                                                   0x1020E98
#define __InChatMode_x                                             0xF975AC
#define __LastTell_x                                               0xF994DC
#define __LMouseHeldTime_x                                         0xF976EC
#define __Mouse_x                                                  0x1128F9C
#define __MouseLook_x                                              0xF97646
#define __MouseEventTime_x                                         0x101C324
#define __NetStatusToggle_x                                        0xF97649
#define __PCNames_x                                                0xF98B00
#define __RangeAttackReady_x                                       0xF987D0
#define __RMouseHeldTime_x                                         0xF976E8
#define __RunWalkState_x                                           0xF975B0
#define __ScreenMode_x                                             0xED68D8
#define __ScreenX_x                                                0xF97564
#define __ScreenY_x                                                0xF97560
#define __ScreenXMax_x                                             0xF97568
#define __ScreenYMax_x                                             0xF9756C
#define __ServerHost_x                                             0xF87F34
#define __ServerName_x                                             0xFCDD94
#define __ShiftKeyDown_x                                           0xF97C54
#define __ShowNames_x                                              0xF989A4
#define __Socials_x                                                0xFCDE94
#define __SubscriptionType_x                                       0x115AD78
#define __TargetAggroHolder_x                                      0x1130C24
#define __GroupAggro_x                                             0x1130C64
#define __LoginName_x                                              0x101FA70
#define __Inviter_x                                                0x101BA9C


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF8A590
#define instEQZoneInfo_x                                           0xF9783C
#define instKeypressHandler_x                                      0x101C308
#define pinstActiveBanker_x                                        0xF8A548
#define pinstActiveCorpse_x                                        0xF8A54C
#define pinstActiveGMaster_x                                       0xF8A550
#define pinstActiveMerchant_x                                      0xF8A544
#define pinstAggroInfo_x                                           0xD9AD58
#define pinstAltAdvManager_x                                       0xED79C0
#define pinstAuraMgr_x                                             0xDA4C20
#define pinstBandageTarget_x                                       0xF8A530
#define pinstCamActor_x                                            0xED72C8
#define pinstCDBStr_x                                              0xED686C
#define pinstCDisplay_x                                            0xF8A558
#define pinstCEverQuest_x                                          0x1129110
#define pinstCharData_x                                            0xF8A514
#define pinstCharSpawn_x                                           0xF8A53C
#define pinstControlledMissile_x                                   0xF8A510
#define pinstControlledPlayer_x                                    0xF8A53C
#define pinstCSidlManager_x                                        0x1792A14
#define pinstCXWndManager_x                                        0x1792A0C
#define instDynamicZone_x                                          0xF973F8
#define pinstDZMember_x                                            0xF97508
#define pinstDZTimerInfo_x                                         0xF9750C
#define pinstEQItemList_x                                          0xF86C70
#define instEQMisc_x                                               0xB93680
#define pinstEQSoundManager_x                                      0xED7DB8
#define instExpeditionLeader_x                                     0xF97442
#define instExpeditionName_x                                       0xF97482
#define pinstGroup_x                                               0xF87FE6
#define pinstImeManager_x                                          0x1792A18
#define pinstLocalPlayer_x                                         0xF8A528
#define pinstMercenaryData_x                                       0x101C958
#define pinstMercAltAbilities_x                                    0xED7CD4
#define pinstModelPlayer_x                                         0xF8A554
#define pinstPCData_x                                              0xF8A514
#define pinstSkillMgr_x                                            0x101D790
#define pinstSpawnManager_x                                        0x101D078
#define pinstSpellManager_x                                        0x101D8D8
#define pinstSpellSets_x                                           0x1014838
#define pinstStringTable_x                                         0xF8A4BC
#define pinstSwitchManager_x                                       0xF87B78
#define pinstTarget_x                                              0xF8A540
#define pinstTargetObject_x                                        0xF8A518
#define pinstTargetSwitch_x                                        0xF8A51C
#define pinstTaskMember_x                                          0xED67B8
#define pinstTrackTarget_x                                         0xF8A534
#define pinstTradeTarget_x                                         0xF8A524
#define instTributeActive_x                                        0xB936A5
#define pinstViewActor_x                                           0xED72C4
#define pinstWorldData_x                                           0xF8A4F8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD9B238
#define pinstCAudioTriggersWindow_x                                0xD9B0C8
#define pinstCCharacterSelect_x                                    0xED7168
#define pinstCFacePick_x                                           0xED7118
#define pinstCNoteWnd_x                                            0xED7120
#define pinstCBookWnd_x                                            0xED7128
#define pinstCPetInfoWnd_x                                         0xED712C
#define pinstCTrainWnd_x                                           0xED7130
#define pinstCSkillsWnd_x                                          0xED7134
#define pinstCSkillsSelectWnd_x                                    0xED7138
#define pinstCCombatSkillSelectWnd_x                               0xED713C
#define pinstCFriendsWnd_x                                         0xED7140
#define pinstCAuraWnd_x                                            0xED7144
#define pinstCRespawnWnd_x                                         0xED7148
#define pinstCBandolierWnd_x                                       0xED714C
#define pinstCPotionBeltWnd_x                                      0xED7150
#define pinstCAAWnd_x                                              0xED7154
#define pinstCGroupSearchFiltersWnd_x                              0xED7158
#define pinstCLoadskinWnd_x                                        0xED715C
#define pinstCAlarmWnd_x                                           0xED7160
#define pinstCMusicPlayerWnd_x                                     0xED7164
#define pinstCMailWnd_x                                            0xED716C
#define pinstCMailCompositionWnd_x                                 0xED7170
#define pinstCMailAddressBookWnd_x                                 0xED7174
#define pinstCRaidWnd_x                                            0xED717C
#define pinstCRaidOptionsWnd_x                                     0xED7180
#define pinstCBreathWnd_x                                          0xED7184
#define pinstCMapViewWnd_x                                         0xED7188
#define pinstCMapToolbarWnd_x                                      0xED718C
#define pinstCEditLabelWnd_x                                       0xED7190
#define pinstCTargetWnd_x                                          0xED7194
#define pinstCColorPickerWnd_x                                     0xED7198
#define pinstCPlayerWnd_x                                          0xED719C
#define pinstCOptionsWnd_x                                         0xED71A0
#define pinstCBuffWindowNORMAL_x                                   0xED71A4
#define pinstCBuffWindowSHORT_x                                    0xED71A8
#define pinstCharacterCreation_x                                   0xED71AC
#define pinstCCursorAttachment_x                                   0xED71B0
#define pinstCCastingWnd_x                                         0xED71B4
#define pinstCCastSpellWnd_x                                       0xED71B8
#define pinstCSpellBookWnd_x                                       0xED71BC
#define pinstCInventoryWnd_x                                       0xED71C0
#define pinstCBankWnd_x                                            0xED71C4
#define pinstCQuantityWnd_x                                        0xED71C8
#define pinstCLootWnd_x                                            0xED71CC
#define pinstCActionsWnd_x                                         0xED71D0
#define pinstCCombatAbilityWnd_x                                   0xED71D4
#define pinstCMerchantWnd_x                                        0xED71D8
#define pinstCTradeWnd_x                                           0xED71DC
#define pinstCSelectorWnd_x                                        0xED71E0
#define pinstCBazaarWnd_x                                          0xED71E4
#define pinstCBazaarSearchWnd_x                                    0xED71E8
#define pinstCGiveWnd_x                                            0xED7204
#define pinstCTrackingWnd_x                                        0xED720C
#define pinstCInspectWnd_x                                         0xED7210
#define pinstCSocialEditWnd_x                                      0xED7214
#define pinstCFeedbackWnd_x                                        0xED7218
#define pinstCBugReportWnd_x                                       0xED721C
#define pinstCVideoModesWnd_x                                      0xED7220
#define pinstCTextEntryWnd_x                                       0xED7228
#define pinstCFileSelectionWnd_x                                   0xED722C
#define pinstCCompassWnd_x                                         0xED7230
#define pinstCPlayerNotesWnd_x                                     0xED7234
#define pinstCGemsGameWnd_x                                        0xED7238
#define pinstCTimeLeftWnd_x                                        0xED723C
#define pinstCPetitionQWnd_x                                       0xED7250
#define pinstCSoulmarkWnd_x                                        0xED7254
#define pinstCStoryWnd_x                                           0xED7258
#define pinstCJournalTextWnd_x                                     0xED725C
#define pinstCJournalCatWnd_x                                      0xED7260
#define pinstCBodyTintWnd_x                                        0xED7264
#define pinstCServerListWnd_x                                      0xED7268
#define pinstCAvaZoneWnd_x                                         0xED7274
#define pinstCBlockedBuffWnd_x                                     0xED7278
#define pinstCBlockedPetBuffWnd_x                                  0xED727C
#define pinstCInvSlotMgr_x                                         0xED72BC
#define pinstCContainerMgr_x                                       0xED72C0
#define pinstCAdventureLeaderboardWnd_x                            0x1129AC0
#define pinstCAdventureRequestWnd_x                                0x1129B38
#define pinstCAltStorageWnd_x                                      0x1129E18
#define pinstCAdventureStatsWnd_x                                  0x1129BB0
#define pinstCBarterMerchantWnd_x                                  0x112AA00
#define pinstCBarterSearchWnd_x                                    0x112AA78
#define pinstCBarterWnd_x                                          0x112AAF0
#define pinstCChatManager_x                                        0x112B180
#define pinstCDynamicZoneWnd_x                                     0x112B630
#define pinstCEQMainWnd_x                                          0x112B7C8
#define pinstCFellowshipWnd_x                                      0x112B5C4
#define pinstCFindLocationWnd_x                                    0x112BA98
#define pinstCGroupSearchWnd_x                                     0x112BD68
#define pinstCGroupWnd_x                                           0x112BDE0
#define pinstCGuildBankWnd_x                                       0x112BE58
#define pinstCGuildMgmtWnd_x                                       0x112DF48
#define pinstCHotButtonWnd_x                                       0x112E014
#define pinstCHotButtonWnd1_x                                      0x112E014
#define pinstCHotButtonWnd2_x                                      0x112E018
#define pinstCHotButtonWnd3_x                                      0x112E01C
#define pinstCHotButtonWnd4_x                                      0x112E040
#define pinstCItemDisplayManager_x                                 0x112E338
#define pinstCItemExpTransferWnd_x                                 0x112E3B4
#define pinstCLFGuildWnd_x                                         0x112E690
#define pinstCMIZoneSelectWnd_x                                    0x112EC78
#define pinstCConfirmationDialog_x                                 0x112F380
#define pinstCPopupWndManager_x                                    0x112F380
#define pinstCProgressionSelectionWnd_x                            0x112F470
#define pinstCPvPStatsWnd_x                                        0x112F560
#define pinstCSystemInfoDialogBox_x                                0x112FC68
#define pinstCTaskWnd_x                                            0x1131030
#define pinstCTaskSomething_x                                      0xDA5360
#define pinstCTaskTemplateSelectWnd_x                              0x1130FB8
#define pinstCTipWndOFDAY_x                                        0x1131288
#define pinstCTipWndCONTEXT_x                                      0x113128C
#define pinstCTitleWnd_x                                           0x1131308
#define pinstCContextMenuManager_x                                 0x1792A98
#define pinstCVoiceMacroWnd_x                                      0x101DF40
#define pinstCHtmlWnd_x                                            0x101E038
#define pinstIconCache_x                                           0x112B79C
#define pinstCTradeskillWnd_x                                      0x1131408

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x524250
#define __ConvertItemTags_x                                        0x5114D0
#define __ExecuteCmd_x                                             0x4FBE80
#define __EQGetTime_x                                              0x8576B0
#define __get_melee_range_x                                        0x502B70
#define __GetGaugeValueFromEQ_x                                    0x797400
#define __GetLabelFromEQ_x                                         0x798640
#define __ToggleMount_x                                            0x6C1090
#define __GetXTargetType_x                                         0x916030
#define __LoadFrontEnd_x                                           0x625EC0
#define __NewUIINI_x                                               0x796D00
#define __ProcessGameEvents_x                                      0x567D00
#define __ProcessMouseEvent_x                                      0x5674A0
#define CrashDetected_x                                            0x627990
#define wwsCrashReportCheckForUploader_x                           0x7EC490
#define DrawNetStatus_x                                            0x59E6C0
#define Util__FastTime_x                                           0x857200
#define Expansion_HoT_x                                            0xF9893C
#define __HelpPath_x                                               0x101C090
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4BD4E0
#define AltAdvManager__IsAbilityReady_x                            0x4BD550
#define AltAdvManager__GetAltAbility_x                             0x4BD910

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x461DE0
#define CharacterZoneClient__MakeMeVisible_x                       0x466EA0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x655820

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x663F20

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x57DD90

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x67EB80
#define CChatManager__InitContextMenu_x                            0x67F6A0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8C7140
#define CContextMenu__AddMenuItem_x                                0x8C7360
#define CContextMenu__dCContextMenu_x                              0x8C7350
#define CContextMenu__RemoveMenuItem_x                             0x8C7650
#define CContextMenu__RemoveAllMenuItems_x                         0x8C7670
#define CContextMenuManager__AddMenu_x                             0x8CA200
#define CContextMenuManager__RemoveMenu_x                          0x8CA550
#define CContextMenuManager__PopupMenu_x                           0x8CA9A0
#define CContextMenuManager__Flush_x                               0x8CA270

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x83DE70
#define CChatService__GetFriendName_x                              0x83DE80

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x684700
#define CChatWindow__Clear_x                                       0x6842C0
#define CChatWindow__WndNotification_x                             0x684C30

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BA760
#define CComboWnd__Draw_x                                          0x8BA970
#define CComboWnd__GetCurChoice_x                                  0x8BA530
#define CComboWnd__GetListRect_x                                   0x8BAC10
#define CComboWnd__GetTextRect_x                                   0x8BA7D0
#define CComboWnd__InsertChoice_x                                  0x8BAC80
#define CComboWnd__SetColors_x                                     0x8BA4C0
#define CComboWnd__SetChoice_x                                     0x8BA4F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x68DE10
#define CContainerWnd__vftable_x                                   0xA817B0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4ABD80
#define CDisplay__GetClickedActor_x                                0x4A4900
#define CDisplay__GetUserDefinedColor_x                            0x4A31C0
#define CDisplay__GetWorldFilePath_x                               0x4A2610
#define CDisplay__is3dON_x                                         0x4A19E0
#define CDisplay__ReloadUI_x                                       0x4B7180
#define CDisplay__WriteTextHD2_x                                   0x4A8120

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8DE190

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8CC560
#define CEditWnd__GetCharIndexPt_x                                 0x8CD590
#define CEditWnd__GetDisplayString_x                               0x8CC710
#define CEditWnd__GetHorzOffset_x                                  0x8CCA50
#define CEditWnd__GetLineForPrintableChar_x                        0x8CD050
#define CEditWnd__GetSelStartPt_x                                  0x8CD850
#define CEditWnd__GetSTMLSafeText_x                                0x8CCBF0
#define CEditWnd__PointFromPrintableChar_x                         0x8CD140
#define CEditWnd__SelectableCharFromPoint_x                        0x8CD2C0
#define CEditWnd__SetEditable_x                                    0x8CCBC0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x545610
#define CEverQuest__DoTellWindow_x                                 0x54B010
#define CEverQuest__DropHeldItemOnGround_x                         0x553B40
#define CEverQuest__dsp_chat_x                                     0x54C7B0
#define CEverQuest__Emote_x                                        0x54CA10
#define CEverQuest__EnterZone_x                                    0x560320
#define CEverQuest__GetBodyTypeDesc_x                              0x541E70
#define CEverQuest__GetClassDesc_x                                 0x547B80
#define CEverQuest__GetClassThreeLetterCode_x                      0x548180
#define CEverQuest__GetDeityDesc_x                                 0x542750
#define CEverQuest__GetLangDesc_x                                  0x542200
#define CEverQuest__GetRaceDesc_x                                  0x548340
#define CEverQuest__InterpretCmd_x                                 0x54D2F0
#define CEverQuest__LeftClickedOnPlayer_x                          0x564400
#define CEverQuest__LMouseUp_x                                     0x5664F0
#define CEverQuest__RightClickedOnPlayer_x                         0x564F00
#define CEverQuest__RMouseUp_x                                     0x565F50
#define CEverQuest__SetGameState_x                                 0x545CC0
#define CEverQuest__UPCNotificationFlush_x                         0x54E490
#define CEverQuest__IssuePetCommand_x                              0x54DFF0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x69E9D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x69EA30
#define CGaugeWnd__Draw_x                                          0x69EE60

// CGuild
#define CGuild__FindMemberByName_x                                 0x433760

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6BBAE0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6C98B0
#define CInvSlotMgr__MoveItem_x                                    0x6CA7F0
#define CInvSlotMgr__SelectSlot_x                                  0x6C9960

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6C8D50
#define CInvSlot__SliderComplete_x                                 0x6C6710
#define CInvSlot__GetItemBase_x                                    0x6C5BA0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6CB970

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x793F20
#define CItemDisplayWnd__UpdateStrings_x                           0x6CCCA0

// CLabel 
#define CLabel__Draw_x                                             0x6E7910

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8A3920
#define CListWnd__dCListWnd_x                                      0x8A49A0
#define CListWnd__AddColumn_x                                      0x8A4940
#define CListWnd__AddColumn1_x                                     0x8A4130
#define CListWnd__AddLine_x                                        0x8A3BE0
#define CListWnd__AddString_x                                      0x8A3DF0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A0C60
#define CListWnd__CalculateVSBRange_x                              0x8A2DE0
#define CListWnd__ClearAllSel_x                                    0x89FF10
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8A37B0
#define CListWnd__Compare_x                                        0x8A1760
#define CListWnd__Draw_x                                           0x8A29F0
#define CListWnd__DrawColumnSeparators_x                           0x8A2880
#define CListWnd__DrawHeader_x                                     0x8A0220
#define CListWnd__DrawItem_x                                       0x8A1DB0
#define CListWnd__DrawLine_x                                       0x8A2520
#define CListWnd__DrawSeparator_x                                  0x8A2920
#define CListWnd__EnsureVisible_x                                  0x8A0DC0
#define CListWnd__ExtendSel_x                                      0x8A1CC0
#define CListWnd__GetColumnMinWidth_x                              0x89F930
#define CListWnd__GetColumnWidth_x                                 0x89F850
#define CListWnd__GetCurSel_x                                      0x89F010
#define CListWnd__GetItemAtPoint_x                                 0x8A1060
#define CListWnd__GetItemAtPoint1_x                                0x8A10D0
#define CListWnd__GetItemData_x                                    0x89F360
#define CListWnd__GetItemHeight_x                                  0x8A08B0
#define CListWnd__GetItemIcon_x                                    0x89F540
#define CListWnd__GetItemRect_x                                    0x8A0EA0
#define CListWnd__GetItemText_x                                    0x89F3F0
#define CListWnd__GetSelList_x                                     0x8A4020
#define CListWnd__GetSeparatorRect_x                               0x8A1680
#define CListWnd__RemoveLine_x                                     0x8A3FD0
#define CListWnd__SetColors_x                                      0x89F160
#define CListWnd__SetColumnJustification_x                         0x89FC00
#define CListWnd__SetColumnWidth_x                                 0x89F8E0
#define CListWnd__SetCurSel_x                                      0x89F050
#define CListWnd__SetItemColor_x                                   0x8A3490
#define CListWnd__SetItemData_x                                    0x89FFC0
#define CListWnd__SetItemText_x                                    0x8A32D0
#define CListWnd__ShiftColumnSeparator_x                           0x8A3160
#define CListWnd__Sort_x                                           0x8A4AA0
#define CListWnd__ToggleSel_x                                      0x89FE90

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x700EC0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x721F50
#define CMerchantWnd__RequestBuyItem_x                             0x728D70
#define CMerchantWnd__RequestSellItem_x                            0x7297C0
#define CMerchantWnd__SelectRecoverySlot_x                         0x722200
#define CMerchantWnd__SelectBuySellSlot_x                          0x721460
#define CMerchantWnd__ActualSelect_x                               0x725CA0

// CObfuscator
#define CObfuscator__doit_x                                        0x81DEA0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8C20A0
#define CSidlManager__CreateLabel_x                                0x789E00

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x64CA6F
#define CSidlScreenWnd__CalculateVSBRange_x                        0x64C9A0
#define CSidlScreenWnd__ConvertToRes_x                             0x8DE070
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8ADB40
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8AF030
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8AF0E0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8AE5B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8AD510
#define CSidlScreenWnd__EnableIniStorage_x                         0x8ACC50
#define CSidlScreenWnd__GetSidlPiece_x                             0x8AD700
#define CSidlScreenWnd__Init1_x                                    0x8AED10
#define CSidlScreenWnd__LoadIniInfo_x                              0x8ADBF0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8ACE10
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8AE800
#define CSidlScreenWnd__StoreIniInfo_x                             0x8AC710
#define CSidlScreenWnd__StoreIniVis_x                              0x8ACBE0
#define CSidlScreenWnd__WndNotification_x                          0x8AEA90
#define CSidlScreenWnd__GetChildItem_x                             0x8ACD20
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B3150

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5E7E90
#define CSkillMgr__GetSkillCap_x                                   0x5E8030
#define CSkillMgr__GetNameToken_x                                  0x5E7B00

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8DD310
#define CSliderWnd__SetValue_x                                     0x8DD4E0
#define CSliderWnd__SetNumTicks_x                                  0x8DDC60

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x791BC0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8D7CA0
#define CStmlWnd__CalculateHSBRange_x                              0x8D0240
#define CStmlWnd__CalculateVSBRange_x                              0x8D01B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D03C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D0CA0
#define CStmlWnd__ForceParseNow_x                                  0x8D85F0
#define CStmlWnd__GetNextTagPiece_x                                0x8D0BA0
#define CStmlWnd__GetSTMLText_x                                    0x683B60
#define CStmlWnd__GetVisibleText_x                                 0x8D16F0
#define CStmlWnd__InitializeWindowVariables_x                      0x8D3A80
#define CStmlWnd__MakeStmlColorTag_x                               0x8CF4B0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8CF510
#define CStmlWnd__SetSTMLText_x                                    0x8D52E0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8D7940
#define CStmlWnd__UpdateHistoryString_x                            0x8D2630

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8DF870
#define CTabWnd__DrawCurrentPage_x                                 0x8DF0E0
#define CTabWnd__DrawTab_x                                         0x8DEEA0
#define CTabWnd__GetCurrentPage_x                                  0x8DF4B0
#define CTabWnd__GetPageInnerRect_x                                0x8DEB90
#define CTabWnd__GetTabInnerRect_x                                 0x8DED90
#define CTabWnd__GetTabRect_x                                      0x8DEC60
#define CTabWnd__InsertPage_x                                      0x8DFB60
#define CTabWnd__SetPage_x                                         0x8DF4E0
#define CTabWnd__SetPageRect_x                                     0x8DF7B0
#define CTabWnd__UpdatePage_x                                      0x8DFB00

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x42F500

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BA130

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8E4A50

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x89D0C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x58B2D0
#define CXStr__CXStr1_x                                            0x43DF50
#define CXStr__CXStr3_x                                            0x854290
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x854400
#define CXStr__operator_equal1_x                                   0x854450
#define CXStr__operator_plus_equal1_x                              0x855530

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B23C0
#define CXWnd__Center_x                                            0x8B8420
#define CXWnd__ClrFocus_x                                          0x8B1FA0
#define CXWnd__DoAllDrawing_x                                      0x8B8050
#define CXWnd__DrawChildren_x                                      0x8B8200
#define CXWnd__DrawColoredRect_x                                   0x8B2780
#define CXWnd__DrawTooltip_x                                       0x8B2A30
#define CXWnd__DrawTooltipAtPoint_x                                0x8B7000
#define CXWnd__GetBorderFrame_x                                    0x8B2E40
#define CXWnd__GetChildWndAt_x                                     0x8B8DE0
#define CXWnd__GetClientClipRect_x                                 0x8B2C40
#define CXWnd__GetScreenClipRect_x                                 0x8B7700
#define CXWnd__GetScreenRect_x                                     0x8B3000
#define CXWnd__GetTooltipRect_x                                    0x8B28C0
#define CXWnd__GetWindowTextA_x                                    0x420A90
#define CXWnd__IsActive_x                                          0x8A7780
#define CXWnd__IsDescendantOf_x                                    0x8B2D80
#define CXWnd__IsReallyVisible_x                                   0x8B6030
#define CXWnd__IsType_x                                            0x8E1270
#define CXWnd__Move_x                                              0x8B57E0
#define CXWnd__Move1_x                                             0x8B7D30
#define CXWnd__ProcessTransition_x                                 0x8B2370
#define CXWnd__Refade_x                                            0x8B2150
#define CXWnd__Resize_x                                            0x8B30B0
#define CXWnd__Right_x                                             0x8B7500
#define CXWnd__SetFocus_x                                          0x8B4960
#define CXWnd__SetFont_x                                           0x8B1FF0
#define CXWnd__SetKeyTooltip_x                                     0x8B3320
#define CXWnd__SetMouseOver_x                                      0x8B7A20
#define CXWnd__StartFade_x                                         0x8B2410
#define CXWnd__GetChildItem_x                                      0x8B7970

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A90B0
#define CXWndManager__DrawWindows_x                                0x8A8CF0
#define CXWndManager__GetKeyboardFlags_x                           0x8A72B0
#define CXWndManager__HandleKeyboardMsg_x                          0x8A7C10
#define CXWndManager__RemoveWnd_x                                  0x8A7910

// CDBStr
#define CDBStr__GetString_x                                        0x49FE10

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44B790
#define EQ_Character__Cur_HP_x                                     0x4614A0
#define EQ_Character__GetAACastingTimeModifier_x                   0x444890
#define EQ_Character__GetCharInfo2_x                               0x828770
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43CB60
#define EQ_Character__GetFocusRangeModifier_x                      0x43CD40
#define EQ_Character__Max_Endurance_x                              0x5B0480
#define EQ_Character__Max_HP_x                                     0x457790
#define EQ_Character__Max_Mana_x                                   0x5B02B0
#define EQ_Character__doCombatAbility_x                            0x5AD8A0
#define EQ_Character__UseSkill_x                                   0x46BFD0
#define EQ_Character__GetConLevel_x                                0x5A2D40
#define EQ_Character__IsExpansionFlag_x                            0x41FFD0
#define EQ_Character__TotalEffect_x                                0x4498C0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x5834E0
#define EQ_Item__CreateItemTagString_x                             0x807D50
#define EQ_Item__IsStackable_x                                     0x7FC110
#define EQ_Item__GetImageNum_x                                     0x7FEDA0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4BF5D0
#define EQ_LoadingS__Array_x                                       0xBA1280

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B1C10
#define EQ_PC__GetAltAbilityIndex_x                                0x810BB0
#define EQ_PC__GetCombatAbility_x                                  0x810C40
#define EQ_PC__GetCombatAbilityTimer_x                             0x810CF0
#define EQ_PC__GetItemTimerValue_x                                 0x5AB670
#define EQ_PC__HasLoreItem_x                                       0x5A6070
#define EQ_PC__AlertInventoryChanged_x                             0x5A2D10
#define EQ_PC__GetPcZoneClient_x                                   0x5CC080
#define EQ_PC__RemoveMyAffect_x                                    0x5AAB80

// EQItemList 
#define EQItemList__EQItemList_x                                   0x500B70
#define EQItemList__add_item_x                                     0x500AB0
#define EQItemList__delete_item_x                                  0x500F70
#define EQItemList__FreeItemList_x                                 0x500E70

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x49F0A0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5B70C0
#define EQPlayer__dEQPlayer_x                                      0x5BFEE0
#define EQPlayer__DoAttack_x                                       0x5D1EF0
#define EQPlayer__EQPlayer_x                                       0x5C2300
#define EQPlayer__SetNameSpriteState_x                             0x5BCBB0
#define EQPlayer__SetNameSpriteTint_x                              0x5B8490
#define EQPlayer__IsBodyType_j_x                                   0x912230
#define EQPlayer__IsTargetable_x                                   0x912B10
#define EQPlayer__CanSee_x                                         0x913030

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5C6620
#define EQPlayerManager__GetSpawnByName_x                          0x5C6A80

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x589600
#define KeypressHandler__AttachKeyToEqCommand_x                    0x589640
#define KeypressHandler__ClearCommandStateArray_x                  0x5891E0
#define KeypressHandler__HandleKeyDown_x                           0x587B40
#define KeypressHandler__HandleKeyUp_x                             0x587E60
#define KeypressHandler__SaveKeymapping_x                          0x5892B0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6F92A0
#define MapViewMap__SaveEx_x                                       0x6FCB80

#define PlayerPointManager__GetAltCurrency_x                       0x823690

// StringTable 
#define StringTable__getString_x                                   0x81E140

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5AFF30

//Doors
#define EQSwitch__UseSwitch_x                                      0x53F240

//IconCache
#define IconCache__GetIcon_x                                       0x694290

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x68B120
#define CContainerMgr__CloseContainer_x                            0x68B940

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x75A1B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x57C850

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D1A10
#define EQ_Spell__SpellAffects_x                                   0x4D1AB0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D1AE0
#define CharacterZoneClient__CalcAffectChange_x                    0x445BB0
#define CLootWnd__LootAll_x                                        0x6EEC60
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x79F9E0
#define CTargetWnd__WndNotification_x                              0x79F4D0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7A4B90
