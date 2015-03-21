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
#define __ExpectedVersionDate                                     "Mar 10 2015"
#define __ExpectedVersionTime                                     "13:35:05"
#define __ActualVersionDate_x                                      0xA770A0
#define __ActualVersionTime_x                                      0xA770AC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x58F760
#define __MemChecker1_x                                            0x857AB0
#define __MemChecker2_x                                            0x6271A0
#define __MemChecker3_x                                            0x6270F0
#define __MemChecker4_x                                            0x7DB800
#define __EncryptPad0_x                                            0xBF2960
#define __EncryptPad1_x                                            0xD76C78
#define __EncryptPad2_x                                            0xC3B8E0
#define __EncryptPad3_x                                            0xC3B4E0
#define __EncryptPad4_x                                            0xD533A0
#define __AC1_x                                                    0x798E25
#define __AC2_x                                                    0x5459F7
#define __AC3_x                                                    0x55A1F0
#define __AC4_x                                                    0x560630
#define __AC5_x                                                    0x56C3EE
#define __AC6_x                                                    0x56FF42
#define __AC7_x                                                    0x566ADC
#define __AC1_Data                                                 0x11111111

// Direct Input
#define DI8__Main_x                                                0x1128A40
#define DI8__Keyboard_x                                            0x1128A44
#define DI8__Mouse_x                                               0x1128A48
#define __AltTimerReady_x                                          0xF883B1
#define __Attack_x                                                 0x101B5CB
#define __Autofire_x                                               0x101B5CC
#define __BindList_x                                               0xBB53C8
#define __bCommandEnabled_x                                        0xF864C0
#define __Clicks_x                                                 0xF97120
#define __CommandList_x                                            0xBB9690
#define __CurrentMapLabel_x                                        0x112E498
#define __CurrentSocial_x                                          0xB72950
#define __DoAbilityList_x                                          0xFCD880
#define __do_loot_x                                                0x50D300
#define __DrawHandler_x                                            0x17930A4
#define __GroupCount_x                                             0xF87A8A

#define __Guilds_x                                                 0xF8D6A0
#define __gWorld_x                                                 0xF89F44
#define __HotkeyPage_x                                             0x1014280
#define __HWnd_x                                                   0x1020948
#define __InChatMode_x                                             0xF9704C
#define __LastTell_x                                               0xF98F88
#define __LMouseHeldTime_x                                         0xF9718C
#define __Mouse_x                                                  0x1128A4C
#define __MouseLook_x                                              0xF970E6
#define __MouseEventTime_x                                         0x101BDD4
#define __NetStatusToggle_x                                        0xF970E9
#define __PCNames_x                                                0xF985AC
#define __RangeAttackReady_x                                       0xF98270
#define __RMouseHeldTime_x                                         0xF97188
#define __RunWalkState_x                                           0xF97050
#define __ScreenMode_x                                             0xED6378
#define __ScreenX_x                                                0xF97004
#define __ScreenY_x                                                0xF97000
#define __ScreenXMax_x                                             0xF97008
#define __ScreenYMax_x                                             0xF9700C
#define __ServerHost_x                                             0xF879D4
#define __ServerName_x                                             0xFCD840
#define __ShiftKeyDown_x                                           0xF976F4
#define __ShowNames_x                                              0xF98444
#define __Socials_x                                                0xFCD940
#define __SubscriptionType_x                                       0x115A828
#define __TargetAggroHolder_x                                      0x11306D4
#define __GroupAggro_x                                             0x1130714
#define __LoginName_x                                              0x101F520
#define __Inviter_x                                                0x101B548


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF8A030
#define instEQZoneInfo_x                                           0xF972DC
#define instKeypressHandler_x                                      0x101BDB8
#define pinstActiveBanker_x                                        0xF89FE8
#define pinstActiveCorpse_x                                        0xF89FEC
#define pinstActiveGMaster_x                                       0xF89FF0
#define pinstActiveMerchant_x                                      0xF89FE4
#define pinstAggroInfo_x                                           0xD9A7F8
#define pinstAltAdvManager_x                                       0xED7460
#define pinstAuraMgr_x                                             0xDA46C0
#define pinstBandageTarget_x                                       0xF89FD0
#define pinstCamActor_x                                            0xED6D68
#define pinstCDBStr_x                                              0xED630C
#define pinstCDisplay_x                                            0xF89FF8
#define pinstCEverQuest_x                                          0x1128BC0
#define pinstCharData_x                                            0xF89FB4
#define pinstCharSpawn_x                                           0xF89FDC
#define pinstControlledMissile_x                                   0xF89FB0
#define pinstControlledPlayer_x                                    0xF89FDC
#define pinstCSidlManager_x                                        0x17924C4
#define pinstCXWndManager_x                                        0x17924BC
#define instDynamicZone_x                                          0xF96E98
#define pinstDZMember_x                                            0xF96FA8
#define pinstDZTimerInfo_x                                         0xF96FAC
#define pinstEQItemList_x                                          0xF86710
#define instEQMisc_x                                               0xB93110
#define pinstEQSoundManager_x                                      0xED7858
#define instExpeditionLeader_x                                     0xF96EE2
#define instExpeditionName_x                                       0xF96F22
#define pinstGroup_x                                               0xF87A86
#define pinstImeManager_x                                          0x17924C8
#define pinstLocalPlayer_x                                         0xF89FC8
#define pinstMercenaryData_x                                       0x101C408
#define pinstMercAltAbilities_x                                    0xED7774
#define pinstModelPlayer_x                                         0xF89FF4
#define pinstPCData_x                                              0xF89FB4
#define pinstSkillMgr_x                                            0x101D240
#define pinstSpawnManager_x                                        0x101CB28
#define pinstSpellManager_x                                        0x101D388
#define pinstSpellSets_x                                           0x10142E4
#define pinstStringTable_x                                         0xF89F5C
#define pinstSwitchManager_x                                       0xF87618
#define pinstTarget_x                                              0xF89FE0
#define pinstTargetObject_x                                        0xF89FB8
#define pinstTargetSwitch_x                                        0xF89FBC
#define pinstTaskMember_x                                          0xED6258
#define pinstTrackTarget_x                                         0xF89FD4
#define pinstTradeTarget_x                                         0xF89FC4
#define instTributeActive_x                                        0xB93135
#define pinstViewActor_x                                           0xED6D64
#define pinstWorldData_x                                           0xF89F98


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD9ACD8
#define pinstCAudioTriggersWindow_x                                0xD9AB68
#define pinstCCharacterSelect_x                                    0xED6C08
#define pinstCFacePick_x                                           0xED6BB8
#define pinstCNoteWnd_x                                            0xED6BC0
#define pinstCBookWnd_x                                            0xED6BC8
#define pinstCPetInfoWnd_x                                         0xED6BCC
#define pinstCTrainWnd_x                                           0xED6BD0
#define pinstCSkillsWnd_x                                          0xED6BD4
#define pinstCSkillsSelectWnd_x                                    0xED6BD8
#define pinstCCombatSkillSelectWnd_x                               0xED6BDC
#define pinstCFriendsWnd_x                                         0xED6BE0
#define pinstCAuraWnd_x                                            0xED6BE4
#define pinstCRespawnWnd_x                                         0xED6BE8
#define pinstCBandolierWnd_x                                       0xED6BEC
#define pinstCPotionBeltWnd_x                                      0xED6BF0
#define pinstCAAWnd_x                                              0xED6BF4
#define pinstCGroupSearchFiltersWnd_x                              0xED6BF8
#define pinstCLoadskinWnd_x                                        0xED6BFC
#define pinstCAlarmWnd_x                                           0xED6C00
#define pinstCMusicPlayerWnd_x                                     0xED6C04
#define pinstCMailWnd_x                                            0xED6C0C
#define pinstCMailCompositionWnd_x                                 0xED6C10
#define pinstCMailAddressBookWnd_x                                 0xED6C14
#define pinstCRaidWnd_x                                            0xED6C1C
#define pinstCRaidOptionsWnd_x                                     0xED6C20
#define pinstCBreathWnd_x                                          0xED6C24
#define pinstCMapViewWnd_x                                         0xED6C28
#define pinstCMapToolbarWnd_x                                      0xED6C2C
#define pinstCEditLabelWnd_x                                       0xED6C30
#define pinstCTargetWnd_x                                          0xED6C34
#define pinstCColorPickerWnd_x                                     0xED6C38
#define pinstCPlayerWnd_x                                          0xED6C3C
#define pinstCOptionsWnd_x                                         0xED6C40
#define pinstCBuffWindowNORMAL_x                                   0xED6C44
#define pinstCBuffWindowSHORT_x                                    0xED6C48
#define pinstCharacterCreation_x                                   0xED6C4C
#define pinstCCursorAttachment_x                                   0xED6C50
#define pinstCCastingWnd_x                                         0xED6C54
#define pinstCCastSpellWnd_x                                       0xED6C58
#define pinstCSpellBookWnd_x                                       0xED6C5C
#define pinstCInventoryWnd_x                                       0xED6C60
#define pinstCBankWnd_x                                            0xED6C64
#define pinstCQuantityWnd_x                                        0xED6C68
#define pinstCLootWnd_x                                            0xED6C6C
#define pinstCActionsWnd_x                                         0xED6C70
#define pinstCCombatAbilityWnd_x                                   0xED6C74
#define pinstCMerchantWnd_x                                        0xED6C78
#define pinstCTradeWnd_x                                           0xED6C7C
#define pinstCSelectorWnd_x                                        0xED6C80
#define pinstCBazaarWnd_x                                          0xED6C84
#define pinstCBazaarSearchWnd_x                                    0xED6C88
#define pinstCGiveWnd_x                                            0xED6CA4
#define pinstCTrackingWnd_x                                        0xED6CAC
#define pinstCInspectWnd_x                                         0xED6CB0
#define pinstCSocialEditWnd_x                                      0xED6CB4
#define pinstCFeedbackWnd_x                                        0xED6CB8
#define pinstCBugReportWnd_x                                       0xED6CBC
#define pinstCVideoModesWnd_x                                      0xED6CC0
#define pinstCTextEntryWnd_x                                       0xED6CC8
#define pinstCFileSelectionWnd_x                                   0xED6CCC
#define pinstCCompassWnd_x                                         0xED6CD0
#define pinstCPlayerNotesWnd_x                                     0xED6CD4
#define pinstCGemsGameWnd_x                                        0xED6CD8
#define pinstCTimeLeftWnd_x                                        0xED6CDC
#define pinstCPetitionQWnd_x                                       0xED6CF0
#define pinstCSoulmarkWnd_x                                        0xED6CF4
#define pinstCStoryWnd_x                                           0xED6CF8
#define pinstCJournalTextWnd_x                                     0xED6CFC
#define pinstCJournalCatWnd_x                                      0xED6D00
#define pinstCBodyTintWnd_x                                        0xED6D04
#define pinstCServerListWnd_x                                      0xED6D08
#define pinstCAvaZoneWnd_x                                         0xED6D14
#define pinstCBlockedBuffWnd_x                                     0xED6D18
#define pinstCBlockedPetBuffWnd_x                                  0xED6D1C
#define pinstCInvSlotMgr_x                                         0xED6D5C
#define pinstCContainerMgr_x                                       0xED6D60
#define pinstCAdventureLeaderboardWnd_x                            0x1129570
#define pinstCAdventureRequestWnd_x                                0x11295E8
#define pinstCAltStorageWnd_x                                      0x11298C8
#define pinstCAdventureStatsWnd_x                                  0x1129660
#define pinstCBarterMerchantWnd_x                                  0x112A4B0
#define pinstCBarterSearchWnd_x                                    0x112A528
#define pinstCBarterWnd_x                                          0x112A5A0
#define pinstCChatManager_x                                        0x112AC30
#define pinstCDynamicZoneWnd_x                                     0x112B0E0
#define pinstCEQMainWnd_x                                          0x112B278
#define pinstCFellowshipWnd_x                                      0x112B074
#define pinstCFindLocationWnd_x                                    0x112B548
#define pinstCGroupSearchWnd_x                                     0x112B818
#define pinstCGroupWnd_x                                           0x112B890
#define pinstCGuildBankWnd_x                                       0x112B908
#define pinstCGuildMgmtWnd_x                                       0x112D9F8
#define pinstCHotButtonWnd_x                                       0x112DAC4
#define pinstCHotButtonWnd1_x                                      0x112DAC4
#define pinstCHotButtonWnd2_x                                      0x112DAC8
#define pinstCHotButtonWnd3_x                                      0x112DACC
#define pinstCHotButtonWnd4_x                                      0x112DAF0
#define pinstCItemDisplayManager_x                                 0x112DDE8
#define pinstCItemExpTransferWnd_x                                 0x112DE64
#define pinstCLFGuildWnd_x                                         0x112E140
#define pinstCMIZoneSelectWnd_x                                    0x112E728
#define pinstCConfirmationDialog_x                                 0x112EE30
#define pinstCPopupWndManager_x                                    0x112EE30
#define pinstCProgressionSelectionWnd_x                            0x112EF20
#define pinstCPvPStatsWnd_x                                        0x112F010
#define pinstCSystemInfoDialogBox_x                                0x112F718
#define pinstCTaskWnd_x                                            0x1130AE0
#define pinstCTaskSomething_x                                      0xDA4E00
#define pinstCTaskTemplateSelectWnd_x                              0x1130A68
#define pinstCTipWndOFDAY_x                                        0x1130D38
#define pinstCTipWndCONTEXT_x                                      0x1130D3C
#define pinstCTitleWnd_x                                           0x1130DB8
#define pinstCContextMenuManager_x                                 0x1792530
#define pinstCVoiceMacroWnd_x                                      0x101D9F0
#define pinstCHtmlWnd_x                                            0x101DAE8
#define pinstIconCache_x                                           0x112B24C
#define pinstCTradeskillWnd_x                                      0x1130EB8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x524D10
#define __ConvertItemTags_x                                        0x511F90
#define __ExecuteCmd_x                                             0x4FC960
#define __EQGetTime_x                                              0x857DD0
#define __get_melee_range_x                                        0x503630
#define __GetGaugeValueFromEQ_x                                    0x797B70
#define __GetLabelFromEQ_x                                         0x798DB0
#define __ToggleMount_x                                            0x6C17D0
#define __GetXTargetType_x                                         0x915CD0
#define __LoadFrontEnd_x                                           0x626850
#define __NewUIINI_x                                               0x797480
#define __ProcessGameEvents_x                                      0x568840
#define __ProcessMouseEvent_x                                      0x567FE0
#define CrashDetected_x                                            0x628320
#define wwsCrashReportCheckForUploader_x                           0x7ECB60
#define DrawNetStatus_x                                            0x59F200
#define Util__FastTime_x                                           0x857920
#define Expansion_HoT_x                                            0xF983DC
#define __HelpPath_x                                               0x101BB40
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4BD580
#define AltAdvManager__IsAbilityReady_x                            0x4BD5F0
#define AltAdvManager__GetAltAbility_x                             0x4BD9B0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x461FD0
#define CharacterZoneClient__MakeMeVisible_x                       0x467090

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x656030

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x664660

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x57E940

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x67F250
#define CChatManager__InitContextMenu_x                            0x67FD70

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8C7270
#define CContextMenu__AddMenuItem_x                                0x8C7480
#define CContextMenu__dCContextMenu_x                              0x8C7470
#define CContextMenu__RemoveMenuItem_x                             0x8C7760
#define CContextMenu__RemoveAllMenuItems_x                         0x8C7780
#define CContextMenuManager__AddMenu_x                             0x8C7B30
#define CContextMenuManager__RemoveMenu_x                          0x8C7E60
#define CContextMenuManager__PopupMenu_x                           0x8C82B0
#define CContextMenuManager__Flush_x                               0x8C7BA0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x83E5D0
#define CChatService__GetFriendName_x                              0x83E5E0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x684DE0
#define CChatWindow__Clear_x                                       0x684990
#define CChatWindow__WndNotification_x                             0x685310

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BA8F0
#define CComboWnd__Draw_x                                          0x8BAB00
#define CComboWnd__GetCurChoice_x                                  0x8BA6C0
#define CComboWnd__GetListRect_x                                   0x8BADA0
#define CComboWnd__GetTextRect_x                                   0x8BA960
#define CComboWnd__InsertChoice_x                                  0x8BAE10
#define CComboWnd__SetColors_x                                     0x8BA650
#define CComboWnd__SetChoice_x                                     0x8BA680

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x68E4B0
#define CContainerWnd__vftable_x                                   0xA80800

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4ABE40
#define CDisplay__GetClickedActor_x                                0x4A49C0
#define CDisplay__GetUserDefinedColor_x                            0x4A3280
#define CDisplay__GetWorldFilePath_x                               0x4A26D0
#define CDisplay__is3dON_x                                         0x4A1AA0
#define CDisplay__ReloadUI_x                                       0x4B7240
#define CDisplay__WriteTextHD2_x                                   0x4A81E0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8DE1E0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8CC6C0
#define CEditWnd__GetCharIndexPt_x                                 0x8CD6D0
#define CEditWnd__GetDisplayString_x                               0x8CC870
#define CEditWnd__GetHorzOffset_x                                  0x8CCBB0
#define CEditWnd__GetLineForPrintableChar_x                        0x8CD1A0
#define CEditWnd__GetSelStartPt_x                                  0x8CD980
#define CEditWnd__GetSTMLSafeText_x                                0x8CCD40
#define CEditWnd__PointFromPrintableChar_x                         0x8CD290
#define CEditWnd__SelectableCharFromPoint_x                        0x8CD410
#define CEditWnd__SetEditable_x                                    0x8CCD10

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x546140
#define CEverQuest__DoTellWindow_x                                 0x54BB40
#define CEverQuest__DropHeldItemOnGround_x                         0x554670
#define CEverQuest__dsp_chat_x                                     0x54D2E0
#define CEverQuest__Emote_x                                        0x54D540
#define CEverQuest__EnterZone_x                                    0x560E50
#define CEverQuest__GetBodyTypeDesc_x                              0x5429A0
#define CEverQuest__GetClassDesc_x                                 0x5486B0
#define CEverQuest__GetClassThreeLetterCode_x                      0x548CB0
#define CEverQuest__GetDeityDesc_x                                 0x543280
#define CEverQuest__GetLangDesc_x                                  0x542D30
#define CEverQuest__GetRaceDesc_x                                  0x548E70
#define CEverQuest__InterpretCmd_x                                 0x54DE20
#define CEverQuest__LeftClickedOnPlayer_x                          0x564F40
#define CEverQuest__LMouseUp_x                                     0x567030
#define CEverQuest__RightClickedOnPlayer_x                         0x565A40
#define CEverQuest__RMouseUp_x                                     0x566A90
#define CEverQuest__SetGameState_x                                 0x5467F0
#define CEverQuest__UPCNotificationFlush_x                         0x54EFC0
#define CEverQuest__IssuePetCommand_x                              0x54EB20

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x69F150
#define CGaugeWnd__CalcLinesFillRect_x                             0x69F1B0
#define CGaugeWnd__Draw_x                                          0x69F5E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x433920

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6BC230

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6C9FE0
#define CInvSlotMgr__MoveItem_x                                    0x6CAF10
#define CInvSlotMgr__SelectSlot_x                                  0x6CA090

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6C9480
#define CInvSlot__SliderComplete_x                                 0x6C6E50
#define CInvSlot__GetItemBase_x                                    0x6C62D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6CC0D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x794680
#define CItemDisplayWnd__UpdateStrings_x                           0x6CD400

// CLabel 
#define CLabel__Draw_x                                             0x6E8010

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8A3C80
#define CListWnd__dCListWnd_x                                      0x8A4CE0
#define CListWnd__AddColumn_x                                      0x8A4C80
#define CListWnd__AddColumn1_x                                     0x8A4470
#define CListWnd__AddLine_x                                        0x8A3F20
#define CListWnd__AddString_x                                      0x8A4130
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A0FE0
#define CListWnd__CalculateVSBRange_x                              0x8A3130
#define CListWnd__ClearAllSel_x                                    0x8A02B0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8A3B10
#define CListWnd__Compare_x                                        0x8A1AD0
#define CListWnd__Draw_x                                           0x8A2D40
#define CListWnd__DrawColumnSeparators_x                           0x8A2BD0
#define CListWnd__DrawHeader_x                                     0x8A05C0
#define CListWnd__DrawItem_x                                       0x8A2110
#define CListWnd__DrawLine_x                                       0x8A2870
#define CListWnd__DrawSeparator_x                                  0x8A2C70
#define CListWnd__EnsureVisible_x                                  0x8A1140
#define CListWnd__ExtendSel_x                                      0x8A2020
#define CListWnd__GetColumnMinWidth_x                              0x89FCD0
#define CListWnd__GetColumnWidth_x                                 0x89FBF0
#define CListWnd__GetCurSel_x                                      0x89F3D0
#define CListWnd__GetItemAtPoint_x                                 0x8A13D0
#define CListWnd__GetItemAtPoint1_x                                0x8A1440
#define CListWnd__GetItemData_x                                    0x89F700
#define CListWnd__GetItemHeight_x                                  0x8A0C50
#define CListWnd__GetItemIcon_x                                    0x89F8E0
#define CListWnd__GetItemRect_x                                    0x8A1210
#define CListWnd__GetItemText_x                                    0x89F790
#define CListWnd__GetSelList_x                                     0x8A4360
#define CListWnd__GetSeparatorRect_x                               0x8A19F0
#define CListWnd__RemoveLine_x                                     0x8A4310
#define CListWnd__SetColors_x                                      0x89F520
#define CListWnd__SetColumnJustification_x                         0x89FFA0
#define CListWnd__SetColumnWidth_x                                 0x89FC80
#define CListWnd__SetCurSel_x                                      0x89F410
#define CListWnd__SetItemColor_x                                   0x8A37F0
#define CListWnd__SetItemData_x                                    0x8A0360
#define CListWnd__SetItemText_x                                    0x8A3630
#define CListWnd__ShiftColumnSeparator_x                           0x8A34C0
#define CListWnd__Sort_x                                           0x8A4DE0
#define CListWnd__ToggleSel_x                                      0x8A0230

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x701400

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x722740
#define CMerchantWnd__RequestBuyItem_x                             0x729560
#define CMerchantWnd__RequestSellItem_x                            0x729FB0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7229F0
#define CMerchantWnd__SelectBuySellSlot_x                          0x721C50
#define CMerchantWnd__ActualSelect_x                               0x726490

// CObfuscator
#define CObfuscator__doit_x                                        0x81E5B0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8C20C0
#define CSidlManager__CreateLabel_x                                0x78A640

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x64D230
#define CSidlScreenWnd__CalculateVSBRange_x                        0x64D110
#define CSidlScreenWnd__ConvertToRes_x                             0x8DE0C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8ADDC0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8AF2A0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8AF350
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8AE840
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8AD790
#define CSidlScreenWnd__EnableIniStorage_x                         0x8ACEF0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8AD980
#define CSidlScreenWnd__Init1_x                                    0x8AEFA0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8ADE70
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8AD0B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8AEA90
#define CSidlScreenWnd__StoreIniInfo_x                             0x8AC9B0
#define CSidlScreenWnd__StoreIniVis_x                              0x8ACE80
#define CSidlScreenWnd__WndNotification_x                          0x8AED20
#define CSidlScreenWnd__GetChildItem_x                             0x8ACFC0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B3360

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5E8810
#define CSkillMgr__GetSkillCap_x                                   0x5E89B0
#define CSkillMgr__GetNameToken_x                                  0x5E8480

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8DD390
#define CSliderWnd__SetValue_x                                     0x8DD560
#define CSliderWnd__SetNumTicks_x                                  0x8DDCE0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x792320

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8D7D60
#define CStmlWnd__CalculateHSBRange_x                              0x8D0340
#define CStmlWnd__CalculateVSBRange_x                              0x8D02B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D04C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D0DA0
#define CStmlWnd__ForceParseNow_x                                  0x8D86B0
#define CStmlWnd__GetNextTagPiece_x                                0x8D0CA0
#define CStmlWnd__GetSTMLText_x                                    0x684230
#define CStmlWnd__GetVisibleText_x                                 0x8D17F0
#define CStmlWnd__InitializeWindowVariables_x                      0x8D3B80
#define CStmlWnd__MakeStmlColorTag_x                               0x8CF5B0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8CF610
#define CStmlWnd__SetSTMLText_x                                    0x8D53E0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8D7A00
#define CStmlWnd__UpdateHistoryString_x                            0x8D2730

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8DF8B0
#define CTabWnd__DrawCurrentPage_x                                 0x8DF120
#define CTabWnd__DrawTab_x                                         0x8DEEF0
#define CTabWnd__GetCurrentPage_x                                  0x8DF4F0
#define CTabWnd__GetPageInnerRect_x                                0x8DEBE0
#define CTabWnd__GetTabInnerRect_x                                 0x8DEDE0
#define CTabWnd__GetTabRect_x                                      0x8DECB0
#define CTabWnd__InsertPage_x                                      0x8DFBA0
#define CTabWnd__SetPage_x                                         0x8DF520
#define CTabWnd__SetPageRect_x                                     0x8DF7F0
#define CTabWnd__UpdatePage_x                                      0x8DFB40

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x42F700

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BA2C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8E4A50

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x89D320

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x58BE60
#define CXStr__CXStr1_x                                            0x8E3780
#define CXStr__CXStr3_x                                            0x8549B0
#define CXStr__dCXStr_x                                            0x69F030
#define CXStr__operator_equal_x                                    0x854B20
#define CXStr__operator_equal1_x                                   0x854B70
#define CXStr__operator_plus_equal1_x                              0x855C50

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B25E0
#define CXWnd__Center_x                                            0x8B8610
#define CXWnd__ClrFocus_x                                          0x8B21B0
#define CXWnd__DoAllDrawing_x                                      0x8B8260
#define CXWnd__DrawChildren_x                                      0x8B8400

#define CXWnd__DrawColoredRect_x                                   0x8B2960
#define CXWnd__DrawTooltip_x                                       0x8B2C10
#define CXWnd__DrawTooltipAtPoint_x                                0x8B7230
#define CXWnd__GetBorderFrame_x                                    0x8B3060
#define CXWnd__GetChildWndAt_x                                     0x8B8FC0
#define CXWnd__GetClientClipRect_x                                 0x8B2E20
#define CXWnd__GetScreenClipRect_x                                 0x8B7920
#define CXWnd__GetScreenRect_x                                     0x8B3200
#define CXWnd__GetTooltipRect_x                                    0x8B2AA0
#define CXWnd__GetWindowTextA_x                                    0x420CA0
#define CXWnd__IsActive_x                                          0x8A7AC0
#define CXWnd__IsDescendantOf_x                                    0x8B2FB0
#define CXWnd__IsReallyVisible_x                                   0x8B6260
#define CXWnd__IsType_x                                            0x8E1220
#define CXWnd__Move_x                                              0x8B5970
#define CXWnd__Move1_x                                             0x8B7F30
#define CXWnd__ProcessTransition_x                                 0x8B2580
#define CXWnd__Refade_x                                            0x8B2350
#define CXWnd__Resize_x                                            0x8B32C0
#define CXWnd__Right_x                                             0x8B7720
#define CXWnd__SetFocus_x                                          0x8B4B00
#define CXWnd__SetFont_x                                           0x8B2200
#define CXWnd__SetKeyTooltip_x                                     0x8B3530
#define CXWnd__SetMouseOver_x                                      0x8B7C50
#define CXWnd__StartFade_x                                         0x8B2630
#define CXWnd__GetChildItem_x                                      0x8B7BA0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A93E0
#define CXWndManager__DrawWindows_x                                0x8A9030
#define CXWndManager__GetKeyboardFlags_x                           0x8A7630
#define CXWndManager__HandleKeyboardMsg_x                          0x8A7F60
#define CXWndManager__RemoveWnd_x                                  0x8A7C50

// CDBStr
#define CDBStr__GetString_x                                        0x49FEC0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44B9C0
#define EQ_Character__Cur_HP_x                                     0x4616A0
#define EQ_Character__GetAACastingTimeModifier_x                   0x444A90
#define EQ_Character__GetCharInfo2_x                               0x828F90
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43CDC0
#define EQ_Character__GetFocusRangeModifier_x                      0x43CFA0
#define EQ_Character__Max_Endurance_x                              0x5B1030
#define EQ_Character__Max_HP_x                                     0x4579A0
#define EQ_Character__Max_Mana_x                                   0x5B0E60
#define EQ_Character__doCombatAbility_x                            0x5AE460
#define EQ_Character__UseSkill_x                                   0x46C1C0
#define EQ_Character__GetConLevel_x                                0x5A3860
#define EQ_Character__IsExpansionFlag_x                            0x4201E0
#define EQ_Character__TotalEffect_x                                0x449AF0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x584100
#define EQ_Item__CreateItemTagString_x                             0x808390
#define EQ_Item__IsStackable_x                                     0x7FC800
#define EQ_Item__GetImageNum_x                                     0x7FF470

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4BF670
#define EQ_LoadingS__Array_x                                       0xBA0D10

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B27C0
#define EQ_PC__GetAltAbilityIndex_x                                0x8112E0
#define EQ_PC__GetCombatAbility_x                                  0x811370
#define EQ_PC__GetCombatAbilityTimer_x                             0x811420
#define EQ_PC__GetItemTimerValue_x                                 0x5AC230
#define EQ_PC__HasLoreItem_x                                       0x5A6BA0
#define EQ_PC__AlertInventoryChanged_x                             0x5A3830
#define EQ_PC__GetPcZoneClient_x                                   0x5CCC50
#define EQ_PC__RemoveMyAffect_x                                    0x5AB740

// EQItemList 
#define EQItemList__EQItemList_x                                   0x501630
#define EQItemList__add_item_x                                     0x501570
#define EQItemList__delete_item_x                                  0x501A30
#define EQItemList__FreeItemList_x                                 0x501930

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x49F1C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5B7C60
#define EQPlayer__dEQPlayer_x                                      0x5C0A70
#define EQPlayer__DoAttack_x                                       0x5D2AC0
#define EQPlayer__EQPlayer_x                                       0x5C2E90
#define EQPlayer__SetNameSpriteState_x                             0x5BD750
#define EQPlayer__SetNameSpriteTint_x                              0x5B9030
#define EQPlayer__IsBodyType_j_x                                   0x911EF0
#define EQPlayer__IsTargetable_x                                   0x9127B0
#define EQPlayer__CanSee_x                                         0x912CD0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5C7200
#define EQPlayerManager__GetSpawnByName_x                          0x5C7660

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x58A190
#define KeypressHandler__AttachKeyToEqCommand_x                    0x58A1D0
#define KeypressHandler__ClearCommandStateArray_x                  0x589D70
#define KeypressHandler__HandleKeyDown_x                           0x5886D0
#define KeypressHandler__HandleKeyUp_x                             0x5889F0
#define KeypressHandler__SaveKeymapping_x                          0x589E40

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6F97E0
#define MapViewMap__SaveEx_x                                       0x6FD0C0

#define PlayerPointManager__GetAltCurrency_x                       0x823E80

// StringTable 
#define StringTable__getString_x                                   0x81E850

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B0AE0

//Doors
#define EQSwitch__UseSwitch_x                                      0x53FD30

//IconCache
#define IconCache__GetIcon_x                                       0x694900

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x68B7D0
#define CContainerMgr__CloseContainer_x                            0x68BFF0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x75A9B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x57D400

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D1D20
#define EQ_Spell__SpellAffects_x                                   0x4D1DC0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D1DF0
#define CharacterZoneClient__CalcAffectChange_x                    0x445DB0
#define CLootWnd__LootAll_x                                        0x6EF1C0
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A0150
#define CTargetWnd__WndNotification_x                              0x79FC40

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7A5300
