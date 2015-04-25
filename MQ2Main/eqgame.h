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
#define __ExpectedVersionDate                                     "Apr 22 2015"
#define __ExpectedVersionTime                                     "15:38:04"
#define __ActualVersionDate_x                                      0xA7CD78
#define __ActualVersionTime_x                                      0xA7CD84

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x593AC0
#define __MemChecker1_x                                            0x85C790
#define __MemChecker2_x                                            0x62B550
#define __MemChecker3_x                                            0x62B4A0
#define __MemChecker4_x                                            0x7E05B0
#define __EncryptPad0_x                                            0xBF8D80
#define __EncryptPad1_x                                            0xD7DA00
#define __EncryptPad2_x                                            0xC41EB0
#define __EncryptPad3_x                                            0xC41AB0
#define __EncryptPad4_x                                            0xD5A008
#define __AC1_x                                                    0x79D9A5
#define __AC2_x                                                    0x549A47
#define __AC3_x                                                    0x55E240
#define __AC4_x                                                    0x564680
#define __AC5_x                                                    0x57049E
#define __AC6_x                                                    0x573F62
#define __AC7_x                                                    0x56AB4C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x112F840
#define DI8__Keyboard_x                                            0x112F844
#define DI8__Mouse_x                                               0x112F848
#define __AltTimerReady_x                                          0xF8F1B1
#define __Attack_x                                                 0x10223CF
#define __Autofire_x                                               0x10223D0
#define __BindList_x                                               0xBBB640
#define __bCommandEnabled_x                                        0xF8D2C0
#define __Clicks_x                                                 0xF9DF20
#define __CommandList_x                                            0xBBF920
#define __CurrentMapLabel_x                                        0x1135298
#define __CurrentSocial_x                                          0xB78A44
#define __DoAbilityList_x                                          0xFD4684
#define __do_loot_x                                                0x511450
#define __DrawHandler_x                                            0x1799EA4
#define __GroupCount_x                                             0xF8E88A

#define __Guilds_x                                                 0xF944A0
#define __gWorld_x                                                 0xF90D44
#define __HotkeyPage_x                                             0x101B084
#define __HWnd_x                                                   0x1027748
#define __InChatMode_x                                             0xF9DE4C
#define __LastTell_x                                               0xF9FD8C
#define __LMouseHeldTime_x                                         0xF9DF8C
#define __Mouse_x                                                  0x112F84C
#define __MouseLook_x                                              0xF9DEE6
#define __MouseEventTime_x                                         0x1022BD4
#define __NetStatusToggle_x                                        0xF9DEE9
#define __PCNames_x                                                0xF9F3AC
#define __RangeAttackReady_x                                       0xF9F070
#define __RMouseHeldTime_x                                         0xF9DF88
#define __RunWalkState_x                                           0xF9DE50
#define __ScreenMode_x                                             0xEDD178
#define __ScreenX_x                                                0xF9DE04
#define __ScreenY_x                                                0xF9DE00
#define __ScreenXMax_x                                             0xF9DE08
#define __ScreenYMax_x                                             0xF9DE0C
#define __ServerHost_x                                             0xF8E7D4
#define __ServerName_x                                             0xFD4644
#define __ShiftKeyDown_x                                           0xF9E4F4
#define __ShowNames_x                                              0xF9F244
#define __Socials_x                                                0xFD4744
#define __SubscriptionType_x                                       0x1161628
#define __TargetAggroHolder_x                                      0x11374D4
#define __GroupAggro_x                                             0x1137514
#define __LoginName_x                                              0x1026320
#define __Inviter_x                                                0x102234C


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF90E30
#define instEQZoneInfo_x                                           0xF9E0DC
#define instKeypressHandler_x                                      0x1022BB8
#define pinstActiveBanker_x                                        0xF90DE8
#define pinstActiveCorpse_x                                        0xF90DEC
#define pinstActiveGMaster_x                                       0xF90DF0
#define pinstActiveMerchant_x                                      0xF90DE4
#define pinstAggroInfo_x                                           0xDA15F8
#define pinstAltAdvManager_x                                       0xEDE260
#define pinstAuraMgr_x                                             0xDAB4C0
#define pinstBandageTarget_x                                       0xF90DD0
#define pinstCamActor_x                                            0xEDDB6C
#define pinstCDBStr_x                                              0xEDD10C
#define pinstCDisplay_x                                            0xF90DF8
#define pinstCEverQuest_x                                          0x112F9C0
#define pinstCharData_x                                            0xF90DB4
#define pinstCharSpawn_x                                           0xF90DDC
#define pinstControlledMissile_x                                   0xF90DB0
#define pinstControlledPlayer_x                                    0xF90DDC
#define pinstCSidlManager_x                                        0x17992DC
#define pinstCXWndManager_x                                        0x17992D4
#define instDynamicZone_x                                          0xF9DC98
#define pinstDZMember_x                                            0xF9DDA8
#define pinstDZTimerInfo_x                                         0xF9DDAC
#define pinstEQItemList_x                                          0xF8D510
#define instEQMisc_x                                               0xB992C8
#define pinstEQSoundManager_x                                      0xEDE658
#define instExpeditionLeader_x                                     0xF9DCE2
#define instExpeditionName_x                                       0xF9DD22
#define pinstGroup_x                                               0xF8E886
#define pinstImeManager_x                                          0x17992E0
#define pinstLocalPlayer_x                                         0xF90DC8
#define pinstMercenaryData_x                                       0x1023208
#define pinstMercAltAbilities_x                                    0xEDE574
#define pinstModelPlayer_x                                         0xF90DF4
#define pinstPCData_x                                              0xF90DB4
#define pinstSkillMgr_x                                            0x1024040
#define pinstSpawnManager_x                                        0x1023928
#define pinstSpellManager_x                                        0x1024188
#define pinstSpellSets_x                                           0x101B0E8
#define pinstStringTable_x                                         0xF90D5C
#define pinstSwitchManager_x                                       0xF8E418
#define pinstTarget_x                                              0xF90DE0
#define pinstTargetObject_x                                        0xF90DB8
#define pinstTargetSwitch_x                                        0xF90DBC
#define pinstTaskMember_x                                          0xEDD058
#define pinstTrackTarget_x                                         0xF90DD4
#define pinstTradeTarget_x                                         0xF90DC4
#define instTributeActive_x                                        0xB992ED
#define pinstViewActor_x                                           0xEDDB68
#define pinstWorldData_x                                           0xF90D98


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xDA1AD8
#define pinstCAudioTriggersWindow_x                                0xDA1968
#define pinstCCharacterSelect_x                                    0xEDDA0C
#define pinstCFacePick_x                                           0xEDD7BC
#define pinstCNoteWnd_x                                            0xEDD9C4
#define pinstCBookWnd_x                                            0xEDD9CC
#define pinstCPetInfoWnd_x                                         0xEDD9D0
#define pinstCTrainWnd_x                                           0xEDD9D4
#define pinstCSkillsWnd_x                                          0xEDD9D8
#define pinstCSkillsSelectWnd_x                                    0xEDD9DC
#define pinstCCombatSkillSelectWnd_x                               0xEDD9E0
#define pinstCFriendsWnd_x                                         0xEDD9E4
#define pinstCAuraWnd_x                                            0xEDD9E8
#define pinstCRespawnWnd_x                                         0xEDD9EC
#define pinstCBandolierWnd_x                                       0xEDD9F0
#define pinstCPotionBeltWnd_x                                      0xEDD9F4
#define pinstCAAWnd_x                                              0xEDD9F8
#define pinstCGroupSearchFiltersWnd_x                              0xEDD9FC
#define pinstCLoadskinWnd_x                                        0xEDDA00
#define pinstCAlarmWnd_x                                           0xEDDA04
#define pinstCMusicPlayerWnd_x                                     0xEDDA08
#define pinstCMailWnd_x                                            0xEDDA10
#define pinstCMailCompositionWnd_x                                 0xEDDA14
#define pinstCMailAddressBookWnd_x                                 0xEDDA18
#define pinstCRaidWnd_x                                            0xEDDA20
#define pinstCRaidOptionsWnd_x                                     0xEDDA24
#define pinstCBreathWnd_x                                          0xEDDA28
#define pinstCMapViewWnd_x                                         0xEDDA2C
#define pinstCMapToolbarWnd_x                                      0xEDDA30
#define pinstCEditLabelWnd_x                                       0xEDDA34
#define pinstCTargetWnd_x                                          0xEDDA38
#define pinstCColorPickerWnd_x                                     0xEDDA3C
#define pinstCPlayerWnd_x                                          0xEDDA40
#define pinstCOptionsWnd_x                                         0xEDDA44
#define pinstCBuffWindowNORMAL_x                                   0xEDDA48
#define pinstCBuffWindowSHORT_x                                    0xEDDA4C
#define pinstCharacterCreation_x                                   0xEDDA50
#define pinstCCursorAttachment_x                                   0xEDDA54
#define pinstCCastingWnd_x                                         0xEDDA58
#define pinstCCastSpellWnd_x                                       0xEDDA5C
#define pinstCSpellBookWnd_x                                       0xEDDA60
#define pinstCInventoryWnd_x                                       0xEDDA64
#define pinstCBankWnd_x                                            0xEDDA68
#define pinstCQuantityWnd_x                                        0xEDDA6C
#define pinstCLootWnd_x                                            0xEDDA70
#define pinstCActionsWnd_x                                         0xEDDA74
#define pinstCCombatAbilityWnd_x                                   0xEDDA78
#define pinstCMerchantWnd_x                                        0xEDDA7C
#define pinstCTradeWnd_x                                           0xEDDA80
#define pinstCSelectorWnd_x                                        0xEDDA84
#define pinstCBazaarWnd_x                                          0xEDDA88
#define pinstCBazaarSearchWnd_x                                    0xEDDA8C
#define pinstCGiveWnd_x                                            0xEDDAA8
#define pinstCTrackingWnd_x                                        0xEDDAB0
#define pinstCInspectWnd_x                                         0xEDDAB4
#define pinstCSocialEditWnd_x                                      0xEDDAB8
#define pinstCFeedbackWnd_x                                        0xEDDABC
#define pinstCBugReportWnd_x                                       0xEDDAC0
#define pinstCVideoModesWnd_x                                      0xEDDAC4
#define pinstCTextEntryWnd_x                                       0xEDDACC
#define pinstCFileSelectionWnd_x                                   0xEDDAD0
#define pinstCCompassWnd_x                                         0xEDDAD4
#define pinstCPlayerNotesWnd_x                                     0xEDDAD8
#define pinstCGemsGameWnd_x                                        0xEDDADC
#define pinstCTimeLeftWnd_x                                        0xEDDAE0
#define pinstCPetitionQWnd_x                                       0xEDDAF4
#define pinstCSoulmarkWnd_x                                        0xEDDAF8
#define pinstCStoryWnd_x                                           0xEDDAFC
#define pinstCJournalTextWnd_x                                     0xEDDB00
#define pinstCJournalCatWnd_x                                      0xEDDB04
#define pinstCBodyTintWnd_x                                        0xEDDB08
#define pinstCServerListWnd_x                                      0xEDDB0C
#define pinstCAvaZoneWnd_x                                         0xEDDB18
#define pinstCBlockedBuffWnd_x                                     0xEDDB1C
#define pinstCBlockedPetBuffWnd_x                                  0xEDDB20
#define pinstCInvSlotMgr_x                                         0xEDDB60
#define pinstCContainerMgr_x                                       0xEDDB64
#define pinstCAdventureLeaderboardWnd_x                            0x1130370
#define pinstCAdventureRequestWnd_x                                0x11303E8
#define pinstCAltStorageWnd_x                                      0x11306C8
#define pinstCAdventureStatsWnd_x                                  0x1130460
#define pinstCBarterMerchantWnd_x                                  0x11312B0
#define pinstCBarterSearchWnd_x                                    0x1131328
#define pinstCBarterWnd_x                                          0x11313A0
#define pinstCChatManager_x                                        0x1131A30
#define pinstCDynamicZoneWnd_x                                     0x1131EE0
#define pinstCEQMainWnd_x                                          0x1132078
#define pinstCFellowshipWnd_x                                      0x1131E74
#define pinstCFindLocationWnd_x                                    0x1132348
#define pinstCGroupSearchWnd_x                                     0x1132618
#define pinstCGroupWnd_x                                           0x1132690
#define pinstCGuildBankWnd_x                                       0x1132708
#define pinstCGuildMgmtWnd_x                                       0x11347F8
#define pinstCHotButtonWnd_x                                       0x11348C4
#define pinstCHotButtonWnd1_x                                      0x11348C4
#define pinstCHotButtonWnd2_x                                      0x11348C8
#define pinstCHotButtonWnd3_x                                      0x11348CC
#define pinstCHotButtonWnd4_x                                      0x11348F0
#define pinstCItemDisplayManager_x                                 0x1134BE8
#define pinstCItemExpTransferWnd_x                                 0x1134C64
#define pinstCLFGuildWnd_x                                         0x1134F40
#define pinstCMIZoneSelectWnd_x                                    0x1135528
#define pinstCConfirmationDialog_x                                 0x1135C30
#define pinstCPopupWndManager_x                                    0x1135C30
#define pinstCProgressionSelectionWnd_x                            0x1135D20
#define pinstCPvPStatsWnd_x                                        0x1135E10
#define pinstCSystemInfoDialogBox_x                                0x1136518
#define pinstCTaskWnd_x                                            0x11378E0
#define pinstCTaskSomething_x                                      0xDABC00
#define pinstCTaskTemplateSelectWnd_x                              0x1137868
#define pinstCTipWndOFDAY_x                                        0x1137B38
#define pinstCTipWndCONTEXT_x                                      0x1137B3C
#define pinstCTitleWnd_x                                           0x1137BB8
#define pinstCContextMenuManager_x                                 0x179924C
#define pinstCVoiceMacroWnd_x                                      0x10247F0
#define pinstCHtmlWnd_x                                            0x10248E8
#define pinstIconCache_x                                           0x113204C
#define pinstCTradeskillWnd_x                                      0x1137CB8
#define pinstCAdvLootWnd_x                                         0xEDDB58
#define pinstRewardSelectionWnd_x                                  0x1136338

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x528E60
#define __ConvertItemTags_x                                        0x5160E0
#define __ExecuteCmd_x                                             0x500A40
#define __EQGetTime_x                                              0x85CAB0
#define __get_melee_range_x                                        0x507770
#define __GetGaugeValueFromEQ_x                                    0x79C6F0
#define __GetLabelFromEQ_x                                         0x79D930
#define __ToggleMount_x                                            0x6C5CB0
#define __GetXTargetType_x                                         0x91B3F0
#define __LoadFrontEnd_x                                           0x62AC00
#define __NewUIINI_x                                               0x79BFF0
#define __ProcessGameEvents_x                                      0x56C8B0
#define __ProcessMouseEvent_x                                      0x56C050
#define CrashDetected_x                                            0x62C6D0
#define wwsCrashReportCheckForUploader_x                           0x7F1AA0
#define DrawNetStatus_x                                            0x5A35C0
#define Util__FastTime_x                                           0x85C600
#define Expansion_HoT_x                                            0xF9F1DC
#define __HelpPath_x                                               0x1022940

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41ED50

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C0830
#define AltAdvManager__IsAbilityReady_x                            0x4C08A0
#define AltAdvManager__GetAltAbility_x                             0x4C0C60

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4646B0
#define CharacterZoneClient__MakeMeVisible_x                       0x4697E0
// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65A430

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x668380

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x582B10

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x683770
#define CChatManager__InitContextMenu_x                            0x684290

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8CD0F0
#define CContextMenu__dCContextMenu_x                              0x8CD300
#define CContextMenu__AddMenuItem_x                                0x8CD310
#define CContextMenu__RemoveMenuItem_x                             0x8CD600
#define CContextMenu__RemoveAllMenuItems_x                         0x8CD620
#define CContextMenuManager__AddMenu_x                             0x8B91F0
#define CContextMenuManager__RemoveMenu_x                          0x8B9530
#define CContextMenuManager__PopupMenu_x                           0x8B9980
#define CContextMenuManager__Flush_x                               0x8B9260

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x843390
#define CChatService__GetFriendName_x                              0x8433A0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x689300
#define CChatWindow__Clear_x                                       0x688EB0
#define CChatWindow__WndNotification_x                             0x689840

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BD0F0
#define CComboWnd__Draw_x                                          0x8BD300
#define CComboWnd__GetCurChoice_x                                  0x8BCEC0
#define CComboWnd__GetListRect_x                                   0x8BD5A0
#define CComboWnd__GetTextRect_x                                   0x8BD160
#define CComboWnd__InsertChoice_x                                  0x8BD610
#define CComboWnd__SetColors_x                                     0x8BCE50
#define CComboWnd__SetChoice_x                                     0x8BCE80
#define CComboWnd__GetItemCount_x                                  0x8BCEB0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x692A50
#define CContainerWnd__vftable_x                                   0xA864D8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4AEC10
#define CDisplay__GetClickedActor_x                                0x4A7790
#define CDisplay__GetUserDefinedColor_x                            0x4A6050
#define CDisplay__GetWorldFilePath_x                               0x4A54A0
#define CDisplay__is3dON_x                                         0x4A4870
#define CDisplay__ReloadUI_x                                       0x4BA080
#define CDisplay__WriteTextHD2_x                                   0x4AAFB0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E36D0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D1A40
#define CEditWnd__GetCharIndexPt_x                                 0x8D2AE0
#define CEditWnd__GetDisplayString_x                               0x8D1BF0
#define CEditWnd__GetHorzOffset_x                                  0x8D1F30
#define CEditWnd__GetLineForPrintableChar_x                        0x8D25A0
#define CEditWnd__GetSelStartPt_x                                  0x8D2DA0
#define CEditWnd__GetSTMLSafeText_x                                0x8D20D0
#define CEditWnd__PointFromPrintableChar_x                         0x8D2690
#define CEditWnd__SelectableCharFromPoint_x                        0x8D2810
#define CEditWnd__SetEditable_x                                    0x8D20A0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54A190
#define CEverQuest__DoTellWindow_x                                 0x54FB90
#define CEverQuest__DropHeldItemOnGround_x                         0x5586C0
#define CEverQuest__dsp_chat_x                                     0x551330
#define CEverQuest__Emote_x                                        0x551590
#define CEverQuest__EnterZone_x                                    0x564EA0
#define CEverQuest__GetBodyTypeDesc_x                              0x5469F0
#define CEverQuest__GetClassDesc_x                                 0x54C700
#define CEverQuest__GetClassThreeLetterCode_x                      0x54CD00
#define CEverQuest__GetDeityDesc_x                                 0x5472D0
#define CEverQuest__GetLangDesc_x                                  0x546D80
#define CEverQuest__GetRaceDesc_x                                  0x54CEC0
#define CEverQuest__InterpretCmd_x                                 0x551E70
#define CEverQuest__LeftClickedOnPlayer_x                          0x568FB0
#define CEverQuest__LMouseUp_x                                     0x56B0A0
#define CEverQuest__RightClickedOnPlayer_x                         0x569AB0
#define CEverQuest__RMouseUp_x                                     0x56AB00
#define CEverQuest__SetGameState_x                                 0x54A840
#define CEverQuest__UPCNotificationFlush_x                         0x553010
#define CEverQuest__IssuePetCommand_x                              0x552B70

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A3620
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A3680
#define CGaugeWnd__Draw_x                                          0x6A3AB0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4359E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C06F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CE500
#define CInvSlotMgr__MoveItem_x                                    0x6CF440
#define CInvSlotMgr__SelectSlot_x                                  0x6CE5B0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CD9A0
#define CInvSlot__SliderComplete_x                                 0x6CB360
#define CInvSlot__GetItemBase_x                                    0x6CA7D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D05C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7991F0
#define CItemDisplayWnd__UpdateStrings_x                           0x6D18F0

// CLabel 
#define CLabel__Draw_x                                             0x6EC6B0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8A8CE0
#define CListWnd__dCListWnd_x                                      0x8A9D00
#define CListWnd__AddColumn_x                                      0x8A9CA0
#define CListWnd__AddColumn1_x                                     0x8A9510
#define CListWnd__AddLine_x                                        0x8A8F90
#define CListWnd__AddString_x                                      0x8A91A0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A6000
#define CListWnd__CalculateVSBRange_x                              0x8A8190
#define CListWnd__ClearAllSel_x                                    0x8A52B0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8A8B70
#define CListWnd__Compare_x                                        0x8A6B10
#define CListWnd__Draw_x                                           0x8A7DA0
#define CListWnd__DrawColumnSeparators_x                           0x8A7C30
#define CListWnd__DrawHeader_x                                     0x8A55C0
#define CListWnd__DrawItem_x                                       0x8A7160
#define CListWnd__DrawLine_x                                       0x8A78D0
#define CListWnd__DrawSeparator_x                                  0x8A7CD0
#define CListWnd__EnsureVisible_x                                  0x8A6160
#define CListWnd__ExtendSel_x                                      0x8A7070
#define CListWnd__GetColumnMinWidth_x                              0x8A4C70
#define CListWnd__GetColumnWidth_x                                 0x8A4B90
#define CListWnd__GetCurSel_x                                      0x8A4350
#define CListWnd__GetItemAtPoint_x                                 0x8A6400
#define CListWnd__GetItemAtPoint1_x                                0x8A6470
#define CListWnd__GetItemData_x                                    0x8A46A0
#define CListWnd__GetItemHeight_x                                  0x8A5C50
#define CListWnd__GetItemIcon_x                                    0x8A4880
#define CListWnd__GetItemRect_x                                    0x8A6240
#define CListWnd__GetItemText_x                                    0x8A4730
#define CListWnd__GetSelList_x                                     0x8A9400
#define CListWnd__GetSeparatorRect_x                               0x8A6A30
#define CListWnd__RemoveLine_x                                     0x8A9380
#define CListWnd__SetColors_x                                      0x8A44A0
#define CListWnd__SetColumnJustification_x                         0x8A4F40
#define CListWnd__SetColumnWidth_x                                 0x8A4C20
#define CListWnd__SetCurSel_x                                      0x8A4390
#define CListWnd__SetItemColor_x                                   0x8A8850
#define CListWnd__SetItemData_x                                    0x8A5360
#define CListWnd__SetItemText_x                                    0x8A8690
#define CListWnd__ShiftColumnSeparator_x                           0x8A8520
#define CListWnd__Sort_x                                           0x8A9E00
#define CListWnd__ToggleSel_x                                      0x8A5230

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x705B10

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x726F30
#define CMerchantWnd__RequestBuyItem_x                             0x72DDA0
#define CMerchantWnd__RequestSellItem_x                            0x72E810
#define CMerchantWnd__SelectRecoverySlot_x                         0x7271E0
#define CMerchantWnd__SelectBuySellSlot_x                          0x726440
#define CMerchantWnd__ActualSelect_x                               0x72ACC0

// CObfuscator
#define CObfuscator__doit_x                                        0x823450

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8C8010
#define CSidlManager__CreateLabel_x                                0x78F200

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x651730
#define CSidlScreenWnd__CalculateVSBRange_x                        0x651650
#define CSidlScreenWnd__ConvertToRes_x                             0x8E35B0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8BFD80
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C1290
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C1340
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C0800
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8BF750
#define CSidlScreenWnd__EnableIniStorage_x                         0x8BEE80
#define CSidlScreenWnd__GetSidlPiece_x                             0x8BF940
#define CSidlScreenWnd__Init1_x                                    0x8C0F70
#define CSidlScreenWnd__LoadIniInfo_x                              0x8BFE30
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8BF040
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C0A50
#define CSidlScreenWnd__StoreIniInfo_x                             0x8BE940
#define CSidlScreenWnd__StoreIniVis_x                              0x8BEE10
#define CSidlScreenWnd__WndNotification_x                          0x8C0CF0
#define CSidlScreenWnd__GetChildItem_x                             0x8BEF50
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B23E0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5ECC40
#define CSkillMgr__GetSkillCap_x                                   0x5ECDE0
#define CSkillMgr__GetNameToken_x                                  0x5EC8B0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E2870
#define CSliderWnd__SetValue_x                                     0x8E2A40
#define CSliderWnd__SetNumTicks_x                                  0x8E31C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x796E90

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8DD260
#define CStmlWnd__CalculateHSBRange_x                              0x8D5780
#define CStmlWnd__CalculateVSBRange_x                              0x8D5810
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D5990
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D6270
#define CStmlWnd__ForceParseNow_x                                  0x8DDBB0
#define CStmlWnd__GetNextTagPiece_x                                0x8D6170
#define CStmlWnd__GetSTMLText_x                                    0x688750
#define CStmlWnd__GetVisibleText_x                                 0x8D6CC0
#define CStmlWnd__InitializeWindowVariables_x                      0x8D9050
#define CStmlWnd__MakeStmlColorTag_x                               0x8D4A80
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D4AE0
#define CStmlWnd__SetSTMLText_x                                    0x8DA8C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8DCF00
#define CStmlWnd__UpdateHistoryString_x                            0x8D7C00

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E4DB0
#define CTabWnd__DrawCurrentPage_x                                 0x8E4620
#define CTabWnd__DrawTab_x                                         0x8E43E0
#define CTabWnd__GetCurrentPage_x                                  0x8E49F0
#define CTabWnd__GetPageInnerRect_x                                0x8E40D0
#define CTabWnd__GetTabInnerRect_x                                 0x8E42D0
#define CTabWnd__GetTabRect_x                                      0x8E41A0
#define CTabWnd__InsertPage_x                                      0x8E50A0
#define CTabWnd__SetPage_x                                         0x8E4A20
#define CTabWnd__SetPageRect_x                                     0x8E4CF0
#define CTabWnd__UpdatePage_x                                      0x8E5040

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431760

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BCAC0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EA010

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A24F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5901C0
#define CXStr__CXStr1_x                                            0x738B40
#define CXStr__CXStr3_x                                            0x859690
#define CXStr__dCXStr_x                                            0x4C1FB0
#define CXStr__operator_equal_x                                    0x859800
#define CXStr__operator_equal1_x                                   0x859850
#define CXStr__operator_plus_equal1_x                              0x85A930

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B15F0
#define CXWnd__Center_x                                            0x8B7800
#define CXWnd__ClrFocus_x                                          0x8B11C0
#define CXWnd__DoAllDrawing_x                                      0x8B7430
#define CXWnd__DrawChildren_x                                      0x8B75E0
#define CXWnd__DrawColoredRect_x                                   0x8B19B0
#define CXWnd__DrawTooltip_x                                       0x8B1C60
#define CXWnd__DrawTooltipAtPoint_x                                0x8B6370
#define CXWnd__GetBorderFrame_x                                    0x8B20C0
#define CXWnd__GetChildWndAt_x                                     0x8B81C0
#define CXWnd__GetClientClipRect_x                                 0x8B1E70
#define CXWnd__GetScreenClipRect_x                                 0x8B6A70
#define CXWnd__GetScreenRect_x                                     0x8B2290
#define CXWnd__GetTooltipRect_x                                    0x8B1AF0
#define CXWnd__GetWindowTextA_x                                    0x422D30
#define CXWnd__IsActive_x                                          0x8ACB40
#define CXWnd__IsDescendantOf_x                                    0x8B2000
#define CXWnd__IsReallyVisible_x                                   0x8B53A0
#define CXWnd__IsType_x                                            0x8E6830
#define CXWnd__Move_x                                              0x8B4AE0
#define CXWnd__Move1_x                                             0x8B70D0
#define CXWnd__ProcessTransition_x                                 0x8B1590
#define CXWnd__Refade_x                                            0x8B1370
#define CXWnd__Resize_x                                            0x8B2350
#define CXWnd__Right_x                                             0x8B6870
#define CXWnd__SetFocus_x                                          0x8B3C40
#define CXWnd__SetFont_x                                           0x8B1210
#define CXWnd__SetKeyTooltip_x                                     0x8B25B0
#define CXWnd__SetMouseOver_x                                      0x8B6DB0
#define CXWnd__StartFade_x                                         0x8B1640
#define CXWnd__GetChildItem_x                                      0x8B6CF0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8AE480
#define CXWndManager__DrawWindows_x                                0x8AE0C0
#define CXWndManager__GetKeyboardFlags_x                           0x8AC670
#define CXWndManager__HandleKeyboardMsg_x                          0x8ACFE0
#define CXWndManager__RemoveWnd_x                                  0x8ACCD0

// CDBStr
#define CDBStr__GetString_x                                        0x4A2CE0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44EA60
#define EQ_Character__Cur_HP_x                                     0x463D80
#define EQ_Character__GetAACastingTimeModifier_x                   0x446BE0
#define EQ_Character__GetCharInfo2_x                               0x82DCA0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EDE0
#define EQ_Character__GetFocusRangeModifier_x                      0x43EFC0
#define EQ_Character__Max_Endurance_x                              0x5B5540
#define EQ_Character__Max_HP_x                                     0x45A060
#define EQ_Character__Max_Mana_x                                   0x5B5370
#define EQ_Character__doCombatAbility_x                            0x5B2970
#define EQ_Character__UseSkill_x                                   0x46E9E0
#define EQ_Character__GetConLevel_x                                0x5A7BD0
#define EQ_Character__IsExpansionFlag_x                            0x422280
#define EQ_Character__TotalEffect_x                                0x44BC10

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x5882D0
#define EQ_Item__CreateItemTagString_x                             0x80D1F0
#define EQ_Item__IsStackable_x                                     0x801710
#define EQ_Item__GetImageNum_x                                     0x804400

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C2950
#define EQ_LoadingS__Array_x                                       0xBA6F10

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B6CE0
#define EQ_PC__GetAltAbilityIndex_x                                0x816190
#define EQ_PC__GetCombatAbility_x                                  0x816220
#define EQ_PC__GetCombatAbilityTimer_x                             0x8162D0
#define EQ_PC__GetItemTimerValue_x                                 0x5B0740
#define EQ_PC__HasLoreItem_x                                       0x5AAF20
#define EQ_PC__AlertInventoryChanged_x                             0x5A7BA0
#define EQ_PC__GetPcZoneClient_x                                   0x5D11D0
#define EQ_PC__RemoveMyAffect_x									   0x5AFC50

// EQItemList 
#define EQItemList__EQItemList_x                                   0x505750
#define EQItemList__add_item_x                                     0x505690
#define EQItemList__delete_item_x                                  0x505B50
#define EQItemList__FreeItemList_x                                 0x505A50

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A1FD0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BC160
#define EQPlayer__dEQPlayer_x                                      0x5C4F80
#define EQPlayer__DoAttack_x                                       0x5D70A0
#define EQPlayer__EQPlayer_x                                       0x5C7380
#define EQPlayer__SetNameSpriteState_x                             0x5C1C50
#define EQPlayer__SetNameSpriteTint_x                              0x5BD530
#define EQPlayer__IsBodyType_j_x                                   0x9175B0
#define EQPlayer__IsTargetable_x                                   0x917E70
#define EQPlayer__CanSee_x                                         0x918390

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CB770
#define EQPlayerManager__GetSpawnByName_x                          0x5CBBD0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x58E4E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x58E520
#define KeypressHandler__ClearCommandStateArray_x                  0x58E0C0
#define KeypressHandler__HandleKeyDown_x                           0x58CA20
#define KeypressHandler__HandleKeyUp_x                             0x58CD40
#define KeypressHandler__SaveKeymapping_x                          0x58E190

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FDEF0
#define MapViewMap__SaveEx_x                                       0x7017D0

#define PlayerPointManager__GetAltCurrency_x                       0x828C60

// StringTable 
#define StringTable__getString_x                                   0x8236F0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B4FF0

//Doors
#define EQSwitch__UseSwitch_x                                      0x543E40

//IconCache
#define IconCache__GetIcon_x                                       0x698EB0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x68FD60
#define CContainerMgr__CloseContainer_x                            0x690580

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x75F4E0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5815D0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D5490
#define EQ_Spell__SpellAffects_x                                   0x4D5530
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D5560
#define CharacterZoneClient__CalcAffectChange_x                    0x447F00
#define CLootWnd__LootAll_x                                        0x6F3820

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A4CD0
#define CTargetWnd__WndNotification_x                              0x7A47C0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7A9EC0
