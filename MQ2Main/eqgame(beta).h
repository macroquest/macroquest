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
#define __ExpectedVersionDate                                     "Oct 28 2015"
#define __ExpectedVersionTime                                     "04:21:28"
#define __ActualVersionDate_x                                      0xAD52F8
#define __ActualVersionTime_x                                      0xAD5304

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59D350
#define __MemChecker1_x                                            0x89E1F0
#define __MemChecker2_x                                            0x636700
#define __MemChecker3_x                                            0x636650
#define __MemChecker4_x                                            0x7EB2B0
#define __EncryptPad0_x                                            0xC6E680
#define __EncryptPad1_x                                            0xDF8450
#define __EncryptPad2_x                                            0xCB8168
#define __EncryptPad3_x                                            0xCB7D68
#define __EncryptPad4_x                                            0xDD28F0
#define __EncryptPad5_x                                            0x11A4238
#define __AC1_x                                                    0x7A8435
#define __AC2_x                                                    0x5526F7
#define __AC3_x                                                    0x5670C0
#define __AC4_x                                                    0x56DC00
#define __AC5_x                                                    0x579AAE
#define __AC6_x                                                    0x57D559
#define __AC7_x                                                    0x57415C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data                                                 0x845E8

// Direct Input
#define DI8__Main_x                                                0x11A4210
#define DI8__Keyboard_x                                            0x11A4214
#define DI8__Mouse_x                                               0x11A4218
#define DI8__Mouse_Copy_x                                          0x101282C
#define DI8__Mouse_Check_x                                         0x109C0FC
#define __AltTimerReady_x                                          0x1003B79
#define __Attack_x                                                 0x1096D9B
#define __Autofire_x                                               0x1096D9C
#define __BindList_x                                               0xC30758
#define __bCommandEnabled_x                                        0x1001C88
#define __Clicks_x                                                 0x10128E8
#define __CommandList_x                                            0xC34AC8
#define __CurrentMapLabel_x                                        0x11A9C68
#define __CurrentSocial_x                                          0xBE8F44
#define __DoAbilityList_x                                          0x1049050
#define __do_loot_x                                                0x519DF0
#define __DrawHandler_x                                            0x18109BC
#define __GroupCount_x                                             0x1003252

#define __Guilds_x                                                 0x1008E68
#define __gWorld_x                                                 0x100570C
#define __HotkeyPage_x                                             0x108FA50
#define __HWnd_x                                                   0x109C118
#define __InChatMode_x                                             0x1012814
#define __LastTell_x                                               0x1014758
#define __LMouseHeldTime_x                                         0x1012954
#define __Mouse_x                                                  0x11A421C
#define __MouseLook_x                                              0x10128AE
#define __MouseEventTime_x                                         0x10975A4
#define __gpbCommandEvent_x                                        0x10057D4
#define __NetStatusToggle_x                                        0x10128B1
#define __PCNames_x                                                0x1013D78
#define __RangeAttackReady_x                                       0x1013A38
#define __RMouseHeldTime_x                                         0x1012950
#define __RunWalkState_x                                           0x1012818
#define __ScreenMode_x                                             0xF51A40
#define __ScreenX_x                                                0x10127CC
#define __ScreenY_x                                                0x10127C8
#define __ScreenXMax_x                                             0x10127D0
#define __ScreenYMax_x                                             0x10127D4
#define __ServerHost_x                                             0x100319C
#define __ServerName_x                                             0x1049010
#define __ShiftKeyDown_x                                           0x1012EBC
#define __ShowNames_x                                              0x1013C0C
#define __Socials_x                                                0x1049110
#define __SubscriptionType_x                                       0x11D8198
#define __TargetAggroHolder_x                                      0x11ABEA4
#define __GroupAggro_x                                             0x11ABEE4
#define __LoginName_x                                              0x109ACF0
#define __Inviter_x                                                0x1096D18


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x10057F8
#define instEQZoneInfo_x                                           0x1012AA4
#define instKeypressHandler_x                                      0x1097588
#define pinstActiveBanker_x                                        0x10057B0
#define pinstActiveCorpse_x                                        0x10057B4
#define pinstActiveGMaster_x                                       0x10057B8
#define pinstActiveMerchant_x                                      0x10057AC
#define pinstAggroInfo_x                                           0xE13E38
#define pinstAltAdvManager_x                                       0xF52B40
#define pinstAuraMgr_x                                             0xE1FD08
#define pinstBandageTarget_x                                       0x1005798
#define pinstCamActor_x                                            0xF5244C
#define pinstCDBStr_x                                              0xF519D4
#define pinstCDisplay_x                                            0x10057C0
#define pinstCEverQuest_x                                          0x11A4390
#define pinstCharData_x                                            0x100577C
#define pinstCharSpawn_x                                           0x10057A4
#define pinstControlledMissile_x                                   0x1005778
#define pinstControlledPlayer_x                                    0x10057A4
#define pinstCSidlManager_x                                        0x180FDF4
#define pinstCXWndManager_x                                        0x180FDEC
#define instDynamicZone_x                                          0x1012660
#define pinstDZMember_x                                            0x1012770
#define pinstDZTimerInfo_x                                         0x1012774
#define pinstEQItemList_x                                          0x1001ED8
#define instEQMisc_x                                               0xC0B2C0
#define pinstEQSoundManager_x                                      0xF53020
#define instExpeditionLeader_x                                     0x10126AA
#define instExpeditionName_x                                       0x10126EA
#define pinstGroup_x                                               0x100324E
#define pinstImeManager_x                                          0x180FDF8
#define pinstLocalPlayer_x                                         0x1005790
#define pinstMercenaryData_x                                       0x1097BD8
#define pinstMercenaryStats_x                                      0x11ABFF0
#define pinstMercAltAbilities_x                                    0xF52EC8
#define pinstModelPlayer_x                                         0x10057BC
#define pinstPCData_x                                              0x100577C
#define pinstSkillMgr_x                                            0x1098A10
#define pinstSpawnManager_x                                        0x10982F8
#define pinstSpellManager_x                                        0x1098B58
#define pinstSpellSets_x                                           0x108FAB4
#define pinstStringTable_x                                         0x1005724
#define pinstSwitchManager_x                                       0x1002DE0
#define pinstTarget_x                                              0x10057A8
#define pinstTargetObject_x                                        0x1005780
#define pinstTargetSwitch_x                                        0x1005784
#define pinstTaskMember_x                                          0xF51920
#define pinstTrackTarget_x                                         0x100579C
#define pinstTradeTarget_x                                         0x100578C
#define instTributeActive_x                                        0xC0B2E5
#define pinstViewActor_x                                           0xF52448
#define pinstWorldData_x                                           0x1005760
#define pinstZoneAddr_x                                            0x1012D64

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE14318
#define pinstCAudioTriggersWindow_x                                0xE141A8
#define pinstCCharacterSelect_x                                    0xF522E0
#define pinstCFacePick_x                                           0xF52290
#define pinstCNoteWnd_x                                            0xF52298
#define pinstCBookWnd_x                                            0xF522A0
#define pinstCPetInfoWnd_x                                         0xF522A4
#define pinstCTrainWnd_x                                           0xF522A8
#define pinstCSkillsWnd_x                                          0xF522AC
#define pinstCSkillsSelectWnd_x                                    0xF522B0
#define pinstCCombatSkillsSelectWnd_x                              0xF522B4
#define pinstCFriendsWnd_x                                         0xF522B8
#define pinstCAuraWnd_x                                            0xF522BC
#define pinstCRespawnWnd_x                                         0xF522C0
#define pinstCBandolierWnd_x                                       0xF522C4
#define pinstCPotionBeltWnd_x                                      0xF522C8
#define pinstCAAWnd_x                                              0xF522CC
#define pinstCGroupSearchFiltersWnd_x                              0xF522D0
#define pinstCLoadskinWnd_x                                        0xF522D4
#define pinstCAlarmWnd_x                                           0xF522D8
#define pinstCMusicPlayerWnd_x                                     0xF522DC
#define pinstCMailWnd_x                                            0xF522E4
#define pinstCMailCompositionWnd_x                                 0xF522E8
#define pinstCMailAddressBookWnd_x                                 0xF522EC
#define pinstCRaidWnd_x                                            0xF522F4
#define pinstCRaidOptionsWnd_x                                     0xF522F8
#define pinstCBreathWnd_x                                          0xF522FC
#define pinstCMapViewWnd_x                                         0xF52300
#define pinstCMapToolbarWnd_x                                      0xF52304
#define pinstCEditLabelWnd_x                                       0xF52308
#define pinstCTargetWnd_x                                          0xF5230C
#define pinstCColorPickerWnd_x                                     0xF52310
#define pinstCPlayerWnd_x                                          0xF52314
#define pinstCOptionsWnd_x                                         0xF52318
#define pinstCBuffWindowNORMAL_x                                   0xF5231C
#define pinstCBuffWindowSHORT_x                                    0xF52320
#define pinstCharacterCreation_x                                   0xF52324
#define pinstCCursorAttachment_x                                   0xF52328
#define pinstCCastingWnd_x                                         0xF5232C
#define pinstCCastSpellWnd_x                                       0xF52330
#define pinstCSpellBookWnd_x                                       0xF52334
#define pinstCInventoryWnd_x                                       0xF52338
#define pinstCBankWnd_x                                            0xF52340
#define pinstCQuantityWnd_x                                        0xF52344
#define pinstCLootWnd_x                                            0xF52348
#define pinstCActionsWnd_x                                         0xF5234C
#define pinstCCombatAbilityWnd_x                                   0xF52350
#define pinstCMerchantWnd_x                                        0xF52354
#define pinstCTradeWnd_x                                           0xF52358
#define pinstCSelectorWnd_x                                        0xF5235C
#define pinstCBazaarWnd_x                                          0xF52360
#define pinstCBazaarSearchWnd_x                                    0xF52364
#define pinstCGiveWnd_x                                            0xF52380
#define pinstCTrackingWnd_x                                        0xF52388
#define pinstCInspectWnd_x                                         0xF5238C
#define pinstCSocialEditWnd_x                                      0xF52390
#define pinstCFeedbackWnd_x                                        0xF52394
#define pinstCBugReportWnd_x                                       0xF52398
#define pinstCVideoModesWnd_x                                      0xF5239C
#define pinstCTextEntryWnd_x                                       0xF523A4
#define pinstCFileSelectionWnd_x                                   0xF523A8
#define pinstCCompassWnd_x                                         0xF523AC
#define pinstCPlayerNotesWnd_x                                     0xF523B0
#define pinstCGemsGameWnd_x                                        0xF523B4
#define pinstCTimeLeftWnd_x                                        0xF523B8
#define pinstCPetitionQWnd_x                                       0xF523D0
#define pinstCSoulmarkWnd_x                                        0xF523D4
#define pinstCStoryWnd_x                                           0xF523D8
#define pinstCJournalTextWnd_x                                     0xF523DC
#define pinstCJournalCatWnd_x                                      0xF523E0
#define pinstCBodyTintWnd_x                                        0xF523E4
#define pinstCServerListWnd_x                                      0xF523E8
#define pinstCAvaZoneWnd_x                                         0xF523F4
#define pinstCBlockedBuffWnd_x                                     0xF523F8
#define pinstCBlockedPetBuffWnd_x                                  0xF523FC
#define pinstCInvSlotMgr_x                                         0xF52440
#define pinstCContainerMgr_x                                       0xF52444
#define pinstCAdventureLeaderboardWnd_x                            0x11A4D40
#define pinstCAdventureRequestWnd_x                                0x11A4DB8
#define pinstCAltStorageWnd_x                                      0x11A5098
#define pinstCAdventureStatsWnd_x                                  0x11A4E30
#define pinstCBarterMerchantWnd_x                                  0x11A5C80
#define pinstCBarterSearchWnd_x                                    0x11A5CF8
#define pinstCBarterWnd_x                                          0x11A5D70
#define pinstCChatManager_x                                        0x11A6400
#define pinstCDynamicZoneWnd_x                                     0x11A68B0
#define pinstCEQMainWnd_x                                          0x11A6A48
#define pinstCFellowshipWnd_x                                      0x11A6844
#define pinstCFindLocationWnd_x                                    0x11A6D18
#define pinstCGroupSearchWnd_x                                     0x11A6FE8
#define pinstCGroupWnd_x                                           0x11A7060
#define pinstCGuildBankWnd_x                                       0x11A70D8
#define pinstCGuildMgmtWnd_x                                       0x11A91C8
#define pinstCHotButtonWnd_x                                       0x11A9294
#define pinstCHotButtonWnd1_x                                      0x11A9294
#define pinstCHotButtonWnd2_x                                      0x11A9298
#define pinstCHotButtonWnd3_x                                      0x11A929C
#define pinstCHotButtonWnd4_x                                      0x11A92C0
#define pinstCItemDisplayManager_x                                 0x11A95B8
#define pinstCItemExpTransferWnd_x                                 0x11A9634
#define pinstCLFGuildWnd_x                                         0x11A9910
#define pinstCMIZoneSelectWnd_x                                    0x11A9EF8
#define pinstCConfirmationDialog_x                                 0x11AA600
#define pinstCPopupWndManager_x                                    0x11AA600
#define pinstCProgressionSelectionWnd_x                            0x11AA6F0
#define pinstCPvPStatsWnd_x                                        0x11AA7E0
#define pinstCSystemInfoDialogBox_x                                0x11AAEE8
#define pinstCTaskWnd_x                                            0x11AC2B0
#define pinstCTaskSomething_x                                      0xE204C8
#define pinstCTaskTemplateSelectWnd_x                              0x11AC238
#define pinstCTipWndOFDAY_x                                        0x11AC508
#define pinstCTipWndCONTEXT_x                                      0x11AC50C
#define pinstCTitleWnd_x                                           0x11AC588
#define pinstCContextMenuManager_x                                 0x180FD64
#define pinstCVoiceMacroWnd_x                                      0x10991C0
#define pinstCHtmlWnd_x                                            0x10992B8
#define pinstIconCache_x                                           0x11A6A1C
#define pinstCTradeskillWnd_x                                      0x11AC688
#define pinstCAdvancedLootWnd_x                                    0xF52434
#define pinstRewardSelectionWnd_x                                  0x11AAD08

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x531940
#define __ConvertItemTags_x                                        0x51EA70
#define __ExecuteCmd_x                                             0x509590
#define __EQGetTime_x                                              0x89E550
#define __get_melee_range_x                                        0x510230
#define __GetGaugeValueFromEQ_x                                    0x7A7170
#define __GetLabelFromEQ_x                                         0x7A83C0
#define __ToggleMount_x                                            0x47DE70
#define __GetXTargetType_x                                         0x92F600
#define __LoadFrontEnd_x                                           0x635DB0
#define __NewUIINI_x                                               0x7A6A70
#define __ProcessGameEvents_x                                      0x575EC0
#define __ProcessMouseEvent_x                                      0x575660
#define CrashDetected_x                                            0x637880
#define wwsCrashReportCheckForUploader_x                           0x7FAD90
#define DrawNetStatus_x                                            0x5ACCF0
#define Util__FastTime_x                                           0x89DEA0
#define Expansion_HoT_x                                            0x1013BA4
#define __HelpPath_x                                               0x1097310
#define __STMLToText_x                                             0x8E2E40

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F030
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419E90

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C4CB0
#define AltAdvManager__IsAbilityReady_x                            0x4C4D20
#define AltAdvManager__GetAAById_x                                 0x4C50E0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4640B0
#define CharacterZoneClient__MakeMeVisible_x                       0x469A90
#define CharacterZoneClient__IsStackBlocked_x                      0x446560

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x665780

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x673E50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58C190
#define CButtonWnd__CButtonWnd_x                                   0x8D70B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68EB10
#define CChatManager__InitContextMenu_x                            0x68F690

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E11B0
#define CContextMenu__dCContextMenu_x                              0x8E13C0
#define CContextMenu__AddMenuItem_x                                0x8E13D0
#define CContextMenu__RemoveMenuItem_x                             0x8E16B0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E16D0
#define CContextMenuManager__AddMenu_x                             0x8CD060
#define CContextMenuManager__RemoveMenu_x                          0x8CD3A0
#define CContextMenuManager__PopupMenu_x                           0x8CD7F0
#define CContextMenuManager__Flush_x                               0x8CD0D0
#define CContextMenuManager__GetMenu_x                             0x4154E0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8842E0
#define CChatService__GetFriendName_x                              0x8842F0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x694940
#define CChatWindow__Clear_x                                       0x6944F0
#define CChatWindow__WndNotification_x                             0x694E80

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D0F60
#define CComboWnd__Draw_x                                          0x8D1170
#define CComboWnd__GetCurChoice_x                                  0x8D0D30
#define CComboWnd__GetListRect_x                                   0x8D1410
#define CComboWnd__GetTextRect_x                                   0x8D0FD0
#define CComboWnd__InsertChoice_x                                  0x8D1480
#define CComboWnd__SetColors_x                                     0x8D0CC0
#define CComboWnd__SetChoice_x                                     0x8D0CF0
#define CComboWnd__GetItemCount_x                                  0x8D0D20

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69E0B0
#define CContainerWnd__vftable_x                                   0xADECC0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B2F00
#define CDisplay__GetClickedActor_x                                0x4ABA80
#define CDisplay__GetUserDefinedColor_x                            0x4AA340
#define CDisplay__GetWorldFilePath_x                               0x4A9790
#define CDisplay__is3dON_x                                         0x4A8B60
#define CDisplay__ReloadUI_x                                       0x4BE480
#define CDisplay__WriteTextHD2_x                                   0x4AF2A0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F8C70

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E5B40
#define CEditWnd__GetCharIndexPt_x                                 0x8E6BC0
#define CEditWnd__GetDisplayString_x                               0x8E5CF0
#define CEditWnd__GetHorzOffset_x                                  0x8E6030
#define CEditWnd__GetLineForPrintableChar_x                        0x8E6690
#define CEditWnd__GetSelStartPt_x                                  0x8E6E70
#define CEditWnd__GetSTMLSafeText_x                                0x8E61C0
#define CEditWnd__PointFromPrintableChar_x                         0x8E6780
#define CEditWnd__SelectableCharFromPoint_x                        0x8E6900
#define CEditWnd__SetEditable_x                                    0x8E6190

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x552E40
#define CEverQuest__DoTellWindow_x                                 0x558830
#define CEverQuest__DropHeldItemOnGround_x                         0x561540
#define CEverQuest__dsp_chat_x                                     0x559FD0
#define CEverQuest__Emote_x                                        0x55A230
#define CEverQuest__EnterZone_x                                    0x56E440
#define CEverQuest__GetBodyTypeDesc_x                              0x54F6A0
#define CEverQuest__GetClassDesc_x                                 0x5553B0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5559B0
#define CEverQuest__GetDeityDesc_x                                 0x54FF80
#define CEverQuest__GetLangDesc_x                                  0x54FA30
#define CEverQuest__GetRaceDesc_x                                  0x555B70
#define CEverQuest__InterpretCmd_x                                 0x55AB10
#define CEverQuest__LeftClickedOnPlayer_x                          0x5725C0
#define CEverQuest__LMouseUp_x                                     0x5746B0
#define CEverQuest__RightClickedOnPlayer_x                         0x5730C0
#define CEverQuest__RMouseUp_x                                     0x574110
#define CEverQuest__SetGameState_x                                 0x5534F0
#define CEverQuest__UPCNotificationFlush_x                         0x55BE90
#define CEverQuest__IssuePetCommand_x                              0x55B7D0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AEC70
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AECD0
#define CGaugeWnd__Draw_x                                          0x6AF100

// CGuild
#define CGuild__FindMemberByName_x                                 0x435EA0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CBD70

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D8580
#define CInvSlotMgr__MoveItem_x                                    0x6D94C0
#define CInvSlotMgr__SelectSlot_x                                  0x6D8630

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D7A10
#define CInvSlot__SliderComplete_x                                 0x6D51F0
#define CInvSlot__GetItemBase_x                                    0x6D4640

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DA8E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A3B20
#define CItemDisplayWnd__UpdateStrings_x                           0x6DBC10

// CLabel 
#define CLabel__Draw_x                                             0x6F6B30

// CListWnd
#define CListWnd__CListWnd_x                                       0x8BCC90
#define CListWnd__dCListWnd_x                                      0x8BDCB0
#define CListWnd__AddColumn_x                                      0x8BDC50
#define CListWnd__AddColumn1_x                                     0x8BD4C0
#define CListWnd__AddLine_x                                        0x8BCF40
#define CListWnd__AddString_x                                      0x8BD150
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B9FD0
#define CListWnd__CalculateVSBRange_x                              0x8BC140
#define CListWnd__ClearAllSel_x                                    0x8B9290
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BCB20
#define CListWnd__Compare_x                                        0x8BAAD0
#define CListWnd__Draw_x                                           0x8BBD50
#define CListWnd__DrawColumnSeparators_x                           0x8BBBE0
#define CListWnd__DrawHeader_x                                     0x8B95A0
#define CListWnd__DrawItem_x                                       0x8BB120
#define CListWnd__DrawLine_x                                       0x8BB880
#define CListWnd__DrawSeparator_x                                  0x8BBC80
#define CListWnd__EnsureVisible_x                                  0x8BA130
#define CListWnd__ExtendSel_x                                      0x8BB030
#define CListWnd__GetColumnMinWidth_x                              0x8B8C50
#define CListWnd__GetColumnWidth_x                                 0x8B8B70
#define CListWnd__GetCurSel_x                                      0x8B8350
#define CListWnd__GetItemAtPoint_x                                 0x8BA3C0
#define CListWnd__GetItemAtPoint1_x                                0x8BA430
#define CListWnd__GetItemData_x                                    0x8B8690
#define CListWnd__GetItemHeight_x                                  0x8B9C30
#define CListWnd__GetItemIcon_x                                    0x8B8870
#define CListWnd__GetItemRect_x                                    0x8BA200
#define CListWnd__GetItemText_x                                    0x8B8720
#define CListWnd__GetSelList_x                                     0x8BD3B0
#define CListWnd__GetSeparatorRect_x                               0x8BA9F0
#define CListWnd__RemoveLine_x                                     0x8BD330
#define CListWnd__SetColors_x                                      0x8B84A0
#define CListWnd__SetColumnJustification_x                         0x8B8F20
#define CListWnd__SetColumnWidth_x                                 0x8B8C00
#define CListWnd__SetCurSel_x                                      0x8B8390
#define CListWnd__SetItemColor_x                                   0x8BC800
#define CListWnd__SetItemData_x                                    0x8B9340
#define CListWnd__SetItemText_x                                    0x8BC640
#define CListWnd__ShiftColumnSeparator_x                           0x8BC4D0
#define CListWnd__Sort_x                                           0x8BDDB0
#define CListWnd__ToggleSel_x                                      0x8B9210

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x710130

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7312B0
#define CMerchantWnd__RequestBuyItem_x                             0x738110
#define CMerchantWnd__RequestSellItem_x                            0x738B80
#define CMerchantWnd__SelectRecoverySlot_x                         0x731560
#define CMerchantWnd__SelectBuySellSlot_x                          0x7307C0
#define CMerchantWnd__ActualSelect_x                               0x735030

// CObfuscator
#define CObfuscator__doit_x                                        0x8646B0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8DC0A0
#define CSidlManager__CreateLabel_x                                0x799AF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65CA60
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65C980
#define CSidlScreenWnd__ConvertToRes_x                             0x8F8B50
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D3C00
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D5100
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D51B0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D4680
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D35B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D2CE0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D37A0
#define CSidlScreenWnd__Init1_x                                    0x8D4DE0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D3CB0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D2EA0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D48D0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D27A0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D2C70
#define CSidlScreenWnd__WndNotification_x                          0x8D4B60
#define CSidlScreenWnd__GetChildItem_x                             0x8D2DB0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C62C0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F7A40
#define CSkillMgr__GetSkillCap_x                                   0x5F7C00
#define CSkillMgr__GetNameToken_x                                  0x5F7660

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F7E20
#define CSliderWnd__SetValue_x                                     0x8F7FF0
#define CSliderWnd__SetNumTicks_x                                  0x8F8770

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A17D0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F2810
#define CStmlWnd__CalculateHSBRange_x                              0x8EAD40
#define CStmlWnd__CalculateVSBRange_x                              0x8EADD0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EAF50
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EB830
#define CStmlWnd__ForceParseNow_x                                  0x8F3160
#define CStmlWnd__GetNextTagPiece_x                                0x8EB730
#define CStmlWnd__GetSTMLText_x                                    0x693D90
#define CStmlWnd__GetVisibleText_x                                 0x8EC280
#define CStmlWnd__InitializeWindowVariables_x                      0x8EE610
#define CStmlWnd__MakeStmlColorTag_x                               0x8EA040
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EA0A0
#define CStmlWnd__SetSTMLText_x                                    0x8EFE80
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F24B0
#define CStmlWnd__UpdateHistoryString_x                            0x8ED1C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E96E0
#define CTabWnd__DrawCurrentPage_x                                 0x8E8F50
#define CTabWnd__DrawTab_x                                         0x8E8D20
#define CTabWnd__GetCurrentPage_x                                  0x8E9320
#define CTabWnd__GetPageInnerRect_x                                0x8E8A10
#define CTabWnd__GetTabInnerRect_x                                 0x8E8C10
#define CTabWnd__GetTabRect_x                                      0x8E8AE0
#define CTabWnd__InsertPage_x                                      0x8E99D0
#define CTabWnd__SetPage_x                                         0x8E9350
#define CTabWnd__SetPageRect_x                                     0x8E9620
#define CTabWnd__UpdatePage_x                                      0x8E9970

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431BF0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D0930

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FDFD0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B6600

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x599920
#define CXStr__CXStr1_x                                            0x8ABD00
#define CXStr__CXStr3_x                                            0x89AF30
#define CXStr__dCXStr_x                                            0x4797A0
#define CXStr__operator_equal_x                                    0x89B0A0
#define CXStr__operator_equal1_x                                   0x89B0F0
#define CXStr__operator_plus_equal1_x                              0x89C1D0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C54E0
#define CXWnd__Center_x                                            0x8CB6A0
#define CXWnd__ClrFocus_x                                          0x8C50B0
#define CXWnd__DoAllDrawing_x                                      0x8CB2F0
#define CXWnd__DrawChildren_x                                      0x8CB490
#define CXWnd__DrawColoredRect_x                                   0x8C5880
#define CXWnd__DrawTooltip_x                                       0x8C5B30
#define CXWnd__DrawTooltipAtPoint_x                                0x8CA260
#define CXWnd__GetBorderFrame_x                                    0x8C5F90
#define CXWnd__GetChildWndAt_x                                     0x8CC040
#define CXWnd__GetClientClipRect_x                                 0x8C5D50
#define CXWnd__GetScreenClipRect_x                                 0x8CA950
#define CXWnd__GetScreenRect_x                                     0x8C6150
#define CXWnd__GetTooltipRect_x                                    0x8C59C0
#define CXWnd__GetWindowTextA_x                                    0x4230A0
#define CXWnd__IsActive_x                                          0x8C0AB0
#define CXWnd__IsDescendantOf_x                                    0x8C5EE0
#define CXWnd__IsReallyVisible_x                                   0x8C9290
#define CXWnd__IsType_x                                            0x8FA7B0
#define CXWnd__Move_x                                              0x8C8960
#define CXWnd__Move1_x                                             0x8CAFA0
#define CXWnd__ProcessTransition_x                                 0x8C5480
#define CXWnd__Refade_x                                            0x8C5250
#define CXWnd__Resize_x                                            0x8C6220
#define CXWnd__Right_x                                             0x8CA750
#define CXWnd__SetFocus_x                                          0x8C7AD0
#define CXWnd__SetFont_x                                           0x8C5100
#define CXWnd__SetKeyTooltip_x                                     0x8C6490
#define CXWnd__SetMouseOver_x                                      0x8CAC90
#define CXWnd__StartFade_x                                         0x8C5530
#define CXWnd__GetChildItem_x                                      0x8CABD0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C23D0
#define CXWndManager__DrawWindows_x                                0x8C2010
#define CXWndManager__GetKeyboardFlags_x                           0x8C05E0
#define CXWndManager__HandleKeyboardMsg_x                          0x8C0F40
#define CXWndManager__RemoveWnd_x                                  0x8C0C40

// CDBStr
#define CDBStr__GetString_x                                        0x4A70C0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E1E0
#define EQ_Character__Cur_HP_x                                     0x463780
#define EQ_Character__GetAACastingTimeModifier_x                   0x4460E0
#define EQ_Character__GetCharInfo2_x                               0x86EEF0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43E020
#define EQ_Character__GetFocusRangeModifier_x                      0x43E210
#define EQ_Character__Max_Endurance_x                              0x5BF480
#define EQ_Character__Max_HP_x                                     0x4593B0
#define EQ_Character__Max_Mana_x                                   0x5BF2B0
#define EQ_Character__doCombatAbility_x                            0x5BC900
#define EQ_Character__UseSkill_x                                   0x46EC80
#define EQ_Character__GetConLevel_x                                0x5B1370
#define EQ_Character__IsExpansionFlag_x                            0x4225D0
#define EQ_Character__TotalEffect_x                                0x44B480

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x591A90
#define EQ_Item__CreateItemTagString_x                             0x84E320
#define EQ_Item__IsStackable_x                                     0x8427D0
#define EQ_Item__GetImageNum_x                                     0x845580
#define EQ_Item__CreateItemClient_x                                0x592680
#define EQ_Item__GetItemValue_x                                    0x84CFF0
#define EQ_Item__ValueSellMerchant_x                               0x84F630

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C6DB0
#define EQ_LoadingS__Array_x                                       0xC19098

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C0AD0
#define EQ_PC__GetAlternateAbilityId_x                             0x857680
#define EQ_PC__GetCombatAbility_x                                  0x857710
#define EQ_PC__GetCombatAbilityTimer_x                             0x852590
#define EQ_PC__GetItemTimerValue_x                                 0x5BA490
#define EQ_PC__HasLoreItem_x                                       0x5B4850
#define EQ_PC__AlertInventoryChanged_x                             0x5B1340
#define EQ_PC__GetPcZoneClient_x                                   0x5DB060
#define EQ_PC__RemoveMyAffect_x									   0x5B9950

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50E270
#define EQItemList__add_item_x                                     0x50E1B0
#define EQItemList__delete_item_x                                  0x50E670
#define EQItemList__FreeItemList_x                                 0x50E570

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A63A0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C6040
#define EQPlayer__dEQPlayer_x                                      0x5CEEC0
#define EQPlayer__DoAttack_x                                       0x5E0F70
#define EQPlayer__EQPlayer_x                                       0x5D12E0
#define EQPlayer__SetNameSpriteState_x                             0x5CBB90
#define EQPlayer__SetNameSpriteTint_x                              0x5C7450
#define EQPlayer__IsBodyType_j_x                                   0x92B7D0
#define EQPlayer__IsTargetable_x                                   0x92C0D0
#define EQPlayer__CanSee_x                                         0x92C5F0
#define PlayerZoneClient__ChangeHeight_x                           0x5E0E30

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D55F0
#define EQPlayerManager__GetSpawnByName_x                          0x5D5A50

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x597C50
#define KeypressHandler__AttachKeyToEqCommand_x                    0x597C90
#define KeypressHandler__ClearCommandStateArray_x                  0x597830
#define KeypressHandler__HandleKeyDown_x                           0x596190
#define KeypressHandler__HandleKeyUp_x                             0x5964B0
#define KeypressHandler__SaveKeymapping_x                          0x597900

// MapViewMap 
#define MapViewMap__Clear_x                                        0x708510
#define MapViewMap__SaveEx_x                                       0x70BDF0

#define PlayerPointManager__GetAltCurrency_x                       0x869E80

// StringTable 
#define StringTable__getString_x                                   0x864950

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BEF30
#define PcZoneClient__RemovePetEffect_x                            0x5BA900

//Doors
#define EQSwitch__UseSwitch_x                                      0x54CAD0

//IconCache
#define IconCache__GetIcon_x                                       0x6A45D0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69B3A0
#define CContainerMgr__CloseContainer_x                            0x69BBC0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x769CC0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58AC30

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DD510
#define EQ_Spell__SpellAffects_x                                   0x4DD5B0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DD5E0
#define CharacterZoneClient__CalcAffectChange_x                    0x4474D0
#define CLootWnd__LootAll_x                                        0x6FDEC0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AF710
#define CTargetWnd__WndNotification_x                              0x7AF200

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B4900

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D6E00

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x496790

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E5170
#define CSidlManager__FindAnimation1_x                             0x8D9F90

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CE530
#define CAltAbilityData__GetMercMaxRank_x                          0x4CE4E0
#define CAltAbilityData__GetMaxRank_x                              0x4C3370
