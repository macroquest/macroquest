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
#define __ExpectedVersionDate                                     "Apr 20 2015"
#define __ExpectedVersionTime                                     "18:41:42"
#define __ActualVersionDate_x                                      0xA7CD88
#define __ActualVersionTime_x                                      0xA7CD94

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x594120
#define __MemChecker1_x                                            0x85CA50
#define __MemChecker2_x                                            0x62BB20
#define __MemChecker3_x                                            0x62BA70
#define __MemChecker4_x                                            0x7E0FA0
#define __EncryptPad0_x                                            0xBF8D80
#define __EncryptPad1_x                                            0xD7DA00
#define __EncryptPad2_x                                            0xC41EB0
#define __EncryptPad3_x                                            0xC41AB0
#define __EncryptPad4_x                                            0xD5A008
#define __AC1_x                                                    0x79E0E5
#define __AC2_x                                                    0x549FB7
#define __AC3_x                                                    0x55E7B0
#define __AC4_x                                                    0x564BF0
#define __AC5_x                                                    0x570A0E
#define __AC6_x                                                    0x5744D2
#define __AC7_x                                                    0x56B0BC
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
#define __do_loot_x                                                0x511840
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
#define __CastRay_x                                                0x529250
#define __ConvertItemTags_x                                        0x5164D0
#define __ExecuteCmd_x                                             0x500E30
#define __EQGetTime_x                                              0x85CD70
#define __get_melee_range_x                                        0x507B60
#define __GetGaugeValueFromEQ_x                                    0x79CE30
#define __GetLabelFromEQ_x                                         0x79E070
#define __ToggleMount_x                                            0x6C6280
#define __GetXTargetType_x                                         0x91B3C0
#define __LoadFrontEnd_x                                           0x62B1D0
#define __NewUIINI_x                                               0x79C730
#define __ProcessGameEvents_x                                      0x56CE20
#define __ProcessMouseEvent_x                                      0x56C5C0
#define CrashDetected_x                                            0x62CCA0
#define wwsCrashReportCheckForUploader_x                           0x7F1E10
#define DrawNetStatus_x                                            0x5A3A90
#define Util__FastTime_x                                           0x85C8C0
#define Expansion_HoT_x                                            0xF9F1DC
#define __HelpPath_x                                               0x1022940

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41EBE0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C0A10
#define AltAdvManager__IsAbilityReady_x                            0x4C0A80
#define AltAdvManager__GetAltAbility_x                             0x4C0E40

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x464990
#define CharacterZoneClient__MakeMeVisible_x                       0x469AC0
// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65A9C0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6690C0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x583120

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x683E40
#define CChatManager__InitContextMenu_x                            0x684960

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8CD3B0
#define CContextMenu__dCContextMenu_x                              0x8CD5C0
#define CContextMenu__AddMenuItem_x                                0x8CD5D0
#define CContextMenu__RemoveMenuItem_x                             0x8CD8C0
#define CContextMenu__RemoveAllMenuItems_x                         0x8CD8E0
#define CContextMenuManager__AddMenu_x                             0x8B93E0
#define CContextMenuManager__RemoveMenu_x                          0x8B9720
#define CContextMenuManager__PopupMenu_x                           0x8B9B70
#define CContextMenuManager__Flush_x                               0x8B9450

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x843450
#define CChatService__GetFriendName_x                              0x843460

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6899D0
#define CChatWindow__Clear_x                                       0x689580
#define CChatWindow__WndNotification_x                             0x689F10

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BD2E0
#define CComboWnd__Draw_x                                          0x8BD4F0
#define CComboWnd__GetCurChoice_x                                  0x8BD0B0
#define CComboWnd__GetListRect_x                                   0x8BD790
#define CComboWnd__GetTextRect_x                                   0x8BD350
#define CComboWnd__InsertChoice_x                                  0x8BD800
#define CComboWnd__SetColors_x                                     0x8BD040
#define CComboWnd__SetChoice_x                                     0x8BD070
#define CComboWnd__GetItemCount_x                                  0x8BD0A0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6930E0
#define CContainerWnd__vftable_x                                   0xA864E8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4AEE50
#define CDisplay__GetClickedActor_x                                0x4A79D0
#define CDisplay__GetUserDefinedColor_x                            0x4A6290
#define CDisplay__GetWorldFilePath_x                               0x4A56E0
#define CDisplay__is3dON_x                                         0x4A4AB0
#define CDisplay__ReloadUI_x                                       0x4BA2C0
#define CDisplay__WriteTextHD2_x                                   0x4AB1F0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E3980

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D1D00
#define CEditWnd__GetCharIndexPt_x                                 0x8D2DA0
#define CEditWnd__GetDisplayString_x                               0x8D1EB0
#define CEditWnd__GetHorzOffset_x                                  0x8D21F0
#define CEditWnd__GetLineForPrintableChar_x                        0x8D2860
#define CEditWnd__GetSelStartPt_x                                  0x8D3060
#define CEditWnd__GetSTMLSafeText_x                                0x8D2390
#define CEditWnd__PointFromPrintableChar_x                         0x8D2950
#define CEditWnd__SelectableCharFromPoint_x                        0x8D2AD0
#define CEditWnd__SetEditable_x                                    0x8D2360

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54A700
#define CEverQuest__DoTellWindow_x                                 0x550100
#define CEverQuest__DropHeldItemOnGround_x                         0x558C30
#define CEverQuest__dsp_chat_x                                     0x5518A0
#define CEverQuest__Emote_x                                        0x551B00
#define CEverQuest__EnterZone_x                                    0x565410
#define CEverQuest__GetBodyTypeDesc_x                              0x546F60
#define CEverQuest__GetClassDesc_x                                 0x54CC70
#define CEverQuest__GetClassThreeLetterCode_x                      0x54D270
#define CEverQuest__GetDeityDesc_x                                 0x547840
#define CEverQuest__GetLangDesc_x                                  0x5472F0
#define CEverQuest__GetRaceDesc_x                                  0x54D430
#define CEverQuest__InterpretCmd_x                                 0x5523E0
#define CEverQuest__LeftClickedOnPlayer_x                          0x569520
#define CEverQuest__LMouseUp_x                                     0x56B610
#define CEverQuest__RightClickedOnPlayer_x                         0x56A020
#define CEverQuest__RMouseUp_x                                     0x56B070
#define CEverQuest__SetGameState_x                                 0x54ADB0
#define CEverQuest__UPCNotificationFlush_x                         0x553580
#define CEverQuest__IssuePetCommand_x                              0x5530E0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A3C00
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A3C60
#define CGaugeWnd__Draw_x                                          0x6A4090

// CGuild
#define CGuild__FindMemberByName_x                                 0x435B90

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C0CB0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CEAE0
#define CInvSlotMgr__MoveItem_x                                    0x6CFA20
#define CInvSlotMgr__SelectSlot_x                                  0x6CEB90

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CDF80
#define CInvSlot__SliderComplete_x                                 0x6CB940
#define CInvSlot__GetItemBase_x                                    0x6CADB0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D0BA0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x799940
#define CItemDisplayWnd__UpdateStrings_x                           0x6D1ED0

// CLabel 
#define CLabel__Draw_x                                             0x6ECC90

// CListWnd
#define CListWnd__CListWnd_x                                       0x8A8F30
#define CListWnd__dCListWnd_x                                      0x8A9F50
#define CListWnd__AddColumn_x                                      0x8A9EF0
#define CListWnd__AddColumn1_x                                     0x8A9760
#define CListWnd__AddLine_x                                        0x8A91E0
#define CListWnd__AddString_x                                      0x8A93F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A6250
#define CListWnd__CalculateVSBRange_x                              0x8A83E0
#define CListWnd__ClearAllSel_x                                    0x8A5500
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8A8DC0
#define CListWnd__Compare_x                                        0x8A6D60
#define CListWnd__Draw_x                                           0x8A7FF0
#define CListWnd__DrawColumnSeparators_x                           0x8A7E80
#define CListWnd__DrawHeader_x                                     0x8A5810
#define CListWnd__DrawItem_x                                       0x8A73B0
#define CListWnd__DrawLine_x                                       0x8A7B20
#define CListWnd__DrawSeparator_x                                  0x8A7F20
#define CListWnd__EnsureVisible_x                                  0x8A63B0
#define CListWnd__ExtendSel_x                                      0x8A72C0
#define CListWnd__GetColumnMinWidth_x                              0x8A4EC0
#define CListWnd__GetColumnWidth_x                                 0x8A4DE0
#define CListWnd__GetCurSel_x                                      0x8A45A0
#define CListWnd__GetItemAtPoint_x                                 0x8A6650
#define CListWnd__GetItemAtPoint1_x                                0x8A66C0
#define CListWnd__GetItemData_x                                    0x8A48F0
#define CListWnd__GetItemHeight_x                                  0x8A5EA0
#define CListWnd__GetItemIcon_x                                    0x8A4AD0
#define CListWnd__GetItemRect_x                                    0x8A6490
#define CListWnd__GetItemText_x                                    0x8A4980
#define CListWnd__GetSelList_x                                     0x8A9650
#define CListWnd__GetSeparatorRect_x                               0x8A6C80
#define CListWnd__RemoveLine_x                                     0x8A95D0
#define CListWnd__SetColors_x                                      0x8A46F0
#define CListWnd__SetColumnJustification_x                         0x8A5190
#define CListWnd__SetColumnWidth_x                                 0x8A4E70
#define CListWnd__SetCurSel_x                                      0x8A45E0
#define CListWnd__SetItemColor_x                                   0x8A8AA0
#define CListWnd__SetItemData_x                                    0x8A55B0
#define CListWnd__SetItemText_x                                    0x8A88E0
#define CListWnd__ShiftColumnSeparator_x                           0x8A8770
#define CListWnd__Sort_x                                           0x8AA050
#define CListWnd__ToggleSel_x                                      0x8A5480

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x706280

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x727450
#define CMerchantWnd__RequestBuyItem_x                             0x72E2C0
#define CMerchantWnd__RequestSellItem_x                            0x72ED30
#define CMerchantWnd__SelectRecoverySlot_x                         0x727700
#define CMerchantWnd__SelectBuySellSlot_x                          0x726960
#define CMerchantWnd__ActualSelect_x                               0x72B1E0

// CObfuscator
#define CObfuscator__doit_x                                        0x823670

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8C8200
#define CSidlManager__CreateLabel_x                                0x78F8F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x651CD0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x651BF0
#define CSidlScreenWnd__ConvertToRes_x                             0x8E3860
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8BFF70
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C1480
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C1530
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C09F0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8BF940
#define CSidlScreenWnd__EnableIniStorage_x                         0x8BF070
#define CSidlScreenWnd__GetSidlPiece_x                             0x8BFB30
#define CSidlScreenWnd__Init1_x                                    0x8C1160
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C0020
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8BF230
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C0C40
#define CSidlScreenWnd__StoreIniInfo_x                             0x8BEB30
#define CSidlScreenWnd__StoreIniVis_x                              0x8BF000
#define CSidlScreenWnd__WndNotification_x                          0x8C0EE0
#define CSidlScreenWnd__GetChildItem_x                             0x8BF140
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B25D0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5ED360
#define CSkillMgr__GetSkillCap_x                                   0x5ED500
#define CSkillMgr__GetNameToken_x                                  0x5ECFD0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E2B20
#define CSliderWnd__SetValue_x                                     0x8E2CF0
#define CSliderWnd__SetNumTicks_x                                  0x8E3470

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7975E0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8DD520
#define CStmlWnd__CalculateHSBRange_x                              0x8D5A40
#define CStmlWnd__CalculateVSBRange_x                              0x8D5AD0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D5C50
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D6530
#define CStmlWnd__ForceParseNow_x                                  0x8DDE70
#define CStmlWnd__GetNextTagPiece_x                                0x8D6430
#define CStmlWnd__GetSTMLText_x                                    0x688E20
#define CStmlWnd__GetVisibleText_x                                 0x8D6F80
#define CStmlWnd__InitializeWindowVariables_x                      0x8D9310
#define CStmlWnd__MakeStmlColorTag_x                               0x8D4D40
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D4DA0
#define CStmlWnd__SetSTMLText_x                                    0x8DAB80
#define CStmlWnd__StripFirstSTMLLines_x                            0x8DD1C0
#define CStmlWnd__UpdateHistoryString_x                            0x8D7EC0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E5060
#define CTabWnd__DrawCurrentPage_x                                 0x8E48D0
#define CTabWnd__DrawTab_x                                         0x8E4690
#define CTabWnd__GetCurrentPage_x                                  0x8E4CA0
#define CTabWnd__GetPageInnerRect_x                                0x8E4380
#define CTabWnd__GetTabInnerRect_x                                 0x8E4580
#define CTabWnd__GetTabRect_x                                      0x8E4450
#define CTabWnd__InsertPage_x                                      0x8E5350
#define CTabWnd__SetPage_x                                         0x8E4CD0
#define CTabWnd__SetPageRect_x                                     0x8E4FA0
#define CTabWnd__UpdatePage_x                                      0x8E52F0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4319A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BCCB0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EA210

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A2850

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402280
#define CXStr__CXStr1_x                                            0x897F50
#define CXStr__CXStr3_x                                            0x859950
#define CXStr__dCXStr_x                                            0x590AE0
#define CXStr__operator_equal_x                                    0x859AC0
#define CXStr__operator_equal1_x                                   0x859B10
#define CXStr__operator_plus_equal1_x                              0x85ABF0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B17E0
#define CXWnd__Center_x                                            0x8B79F0
#define CXWnd__ClrFocus_x                                          0x8B13B0
#define CXWnd__DoAllDrawing_x                                      0x8B7620
#define CXWnd__DrawChildren_x                                      0x8B77D0
#define CXWnd__DrawColoredRect_x                                   0x8B1BA0
#define CXWnd__DrawTooltip_x                                       0x8B1E50
#define CXWnd__DrawTooltipAtPoint_x                                0x8B6560
#define CXWnd__GetBorderFrame_x                                    0x8B22B0
#define CXWnd__GetChildWndAt_x                                     0x8B83B0
#define CXWnd__GetClientClipRect_x                                 0x8B2060
#define CXWnd__GetScreenClipRect_x                                 0x8B6C60
#define CXWnd__GetScreenRect_x                                     0x8B2480
#define CXWnd__GetTooltipRect_x                                    0x8B1CE0
#define CXWnd__GetWindowTextA_x                                    0x422BD0
#define CXWnd__IsActive_x                                          0x8ACD30
#define CXWnd__IsDescendantOf_x                                    0x8B21F0
#define CXWnd__IsReallyVisible_x                                   0x8B5590
#define CXWnd__IsType_x                                            0x8E69F0
#define CXWnd__Move_x                                              0x8B4CD0
#define CXWnd__Move1_x                                             0x8B72C0
#define CXWnd__ProcessTransition_x                                 0x8B1780
#define CXWnd__Refade_x                                            0x8B1560
#define CXWnd__Resize_x                                            0x8B2540
#define CXWnd__Right_x                                             0x8B6A60
#define CXWnd__SetFocus_x                                          0x8B3E30
#define CXWnd__SetFont_x                                           0x8B1400
#define CXWnd__SetKeyTooltip_x                                     0x8B27A0
#define CXWnd__SetMouseOver_x                                      0x8B6FA0
#define CXWnd__StartFade_x                                         0x8B1830
#define CXWnd__GetChildItem_x                                      0x8B6EE0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8AE670
#define CXWndManager__DrawWindows_x                                0x8AE2B0
#define CXWndManager__GetKeyboardFlags_x                           0x8AC860
#define CXWndManager__HandleKeyboardMsg_x                          0x8AD1D0
#define CXWndManager__RemoveWnd_x                                  0x8ACEC0

// CDBStr
#define CDBStr__GetString_x                                        0x4A2EE0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44ECF0
#define EQ_Character__Cur_HP_x                                     0x464060
#define EQ_Character__GetAACastingTimeModifier_x                   0x446E70
#define EQ_Character__GetCharInfo2_x                               0x82DE50
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F040
#define EQ_Character__GetFocusRangeModifier_x                      0x43F220
#define EQ_Character__Max_Endurance_x                              0x5B5700
#define EQ_Character__Max_HP_x                                     0x45A340
#define EQ_Character__Max_Mana_x                                   0x5B5530
#define EQ_Character__doCombatAbility_x                            0x5B2B30
#define EQ_Character__UseSkill_x                                   0x46ECC0
#define EQ_Character__GetConLevel_x                                0x5A8130
#define EQ_Character__IsExpansionFlag_x                            0x422100
#define EQ_Character__TotalEffect_x                                0x44BEA0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x588950
#define EQ_Item__CreateItemTagString_x                             0x80D580
#define EQ_Item__IsStackable_x                                     0x801A10
#define EQ_Item__GetImageNum_x                                     0x804790

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C2B60
#define EQ_LoadingS__Array_x                                       0xBA6F10

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B6EA0
#define EQ_PC__GetAltAbilityIndex_x                                0x8163B0
#define EQ_PC__GetCombatAbility_x                                  0x816440
#define EQ_PC__GetCombatAbilityTimer_x                             0x8164F0
#define EQ_PC__GetItemTimerValue_x                                 0x5B0900
#define EQ_PC__HasLoreItem_x                                       0x5AB480
#define EQ_PC__AlertInventoryChanged_x                             0x5A8100
#define EQ_PC__GetPcZoneClient_x                                   0x5D1480
#define EQ_PC__RemoveMyAffect_x									   0x5AFE10

// EQItemList 
#define EQItemList__EQItemList_x                                   0x505B40
#define EQItemList__add_item_x                                     0x505A80
#define EQItemList__delete_item_x                                  0x505F40
#define EQItemList__FreeItemList_x                                 0x505E40

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A2180

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BC370
#define EQPlayer__dEQPlayer_x                                      0x5C5190
#define EQPlayer__DoAttack_x                                       0x5D7350
#define EQPlayer__EQPlayer_x                                       0x5C7590
#define EQPlayer__SetNameSpriteState_x                             0x5C1E60
#define EQPlayer__SetNameSpriteTint_x                              0x5BD740
#define EQPlayer__IsBodyType_j_x                                   0x917640
#define EQPlayer__IsTargetable_x                                   0x917F00
#define EQPlayer__CanSee_x                                         0x918420

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CBA10
#define EQPlayerManager__GetSpawnByName_x                          0x5CBE70

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x58EAF0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x58EB30
#define KeypressHandler__ClearCommandStateArray_x                  0x58E6D0
#define KeypressHandler__HandleKeyDown_x                           0x58D030
#define KeypressHandler__HandleKeyUp_x                             0x58D350
#define KeypressHandler__SaveKeymapping_x                          0x58E7A0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FE660
#define MapViewMap__SaveEx_x                                       0x701F40

#define PlayerPointManager__GetAltCurrency_x                       0x828E20

// StringTable 
#define StringTable__getString_x                                   0x823910

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B51B0

//Doors
#define EQSwitch__UseSwitch_x                                      0x544300

//IconCache
#define IconCache__GetIcon_x                                       0x699540

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6903F0
#define CContainerMgr__CloseContainer_x                            0x690C10

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x75FA80

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x581BE0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D5850
#define EQ_Spell__SpellAffects_x                                   0x4D58F0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D5920
#define CharacterZoneClient__CalcAffectChange_x                    0x448190
#define CLootWnd__LootAll_x                                        0x6F3F80

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A53A0
#define CTargetWnd__WndNotification_x                              0x7A4E90

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AA560
