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
#define __ExpectedVersionDate                                     "May 19 2015"
#define __ExpectedVersionTime                                     "04:21:38"
#define __ActualVersionDate_x                                      0xA7EF78
#define __ActualVersionTime_x                                      0xA7EF84

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x595090
#define __MemChecker1_x                                            0x85E8B0
#define __MemChecker2_x                                            0x62D770
#define __MemChecker3_x                                            0x62D6C0
#define __MemChecker4_x                                            0x7E2690
#define __EncryptPad0_x                                            0xBFD5A0
#define __EncryptPad1_x                                            0xD84F18
#define __EncryptPad2_x                                            0xC46EE8
#define __EncryptPad3_x                                            0xC46AE8
#define __EncryptPad4_x                                            0xD60F80
#define __AC1_x                                                    0x79FA75
#define __AC2_x                                                    0x54AF97
#define __AC3_x                                                    0x55F790
#define __AC4_x                                                    0x565B50
#define __AC5_x                                                    0x57197E
#define __AC6_x                                                    0x575429
#define __AC7_x                                                    0x56C02C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x1136FF8
#define DI8__Keyboard_x                                            0x1136FFC
#define DI8__Mouse_x                                               0x1137000
#define __AltTimerReady_x                                          0xF96969
#define __Attack_x                                                 0x1029B87
#define __Autofire_x                                               0x1029B88
#define __BindList_x                                               0xBBF818
#define __bCommandEnabled_x                                        0xF94A78
#define __Clicks_x                                                 0xFA56D8
#define __CommandList_x                                            0xBC3B70
#define __CurrentMapLabel_x                                        0x113CA50
#define __CurrentSocial_x                                          0xB7AE7C
#define __DoAbilityList_x                                          0xFDBE3C
#define __do_loot_x                                                0x512640
#define __DrawHandler_x                                            0x17A165C
#define __GroupCount_x                                             0xF96042

#define __Guilds_x                                                 0xF9BC58
#define __gWorld_x                                                 0xF984FC
#define __HotkeyPage_x                                             0x102283C
#define __HWnd_x                                                   0x102EF00
#define __InChatMode_x                                             0xFA5604
#define __LastTell_x                                               0xFA7544
#define __LMouseHeldTime_x                                         0xFA5744
#define __Mouse_x                                                  0x1137004
#define __MouseLook_x                                              0xFA569E
#define __MouseEventTime_x                                         0x102A38C
#define __gpbCommandEvent_x                                        0xF985C4
#define __NetStatusToggle_x                                        0xFA56A1
#define __PCNames_x                                                0xFA6B64
#define __RangeAttackReady_x                                       0xFA6828
#define __RMouseHeldTime_x                                         0xFA5740
#define __RunWalkState_x                                           0xFA5608
#define __ScreenMode_x                                             0xEE48B8
#define __ScreenX_x                                                0xFA55BC
#define __ScreenY_x                                                0xFA55B8
#define __ScreenXMax_x                                             0xFA55C0
#define __ScreenYMax_x                                             0xFA55C4
#define __ServerHost_x                                             0xF95F8C
#define __ServerName_x                                             0xFDBDFC
#define __ShiftKeyDown_x                                           0xFA5CAC
#define __ShowNames_x                                              0xFA69FC
#define __Socials_x                                                0xFDBEFC
#define __SubscriptionType_x                                       0x1168DE0
#define __TargetAggroHolder_x                                      0x113EC8C
#define __GroupAggro_x                                             0x113ECCC
#define __LoginName_x                                              0x102DAD8
#define __Inviter_x                                                0x1029B04


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF985E8
#define instEQZoneInfo_x                                           0xFA5894
#define instKeypressHandler_x                                      0x102A370
#define pinstActiveBanker_x                                        0xF985A0
#define pinstActiveCorpse_x                                        0xF985A4
#define pinstActiveGMaster_x                                       0xF985A8
#define pinstActiveMerchant_x                                      0xF9859C
#define pinstAggroInfo_x                                           0xDA8D38
#define pinstAltAdvManager_x                                       0xEE59A0
#define pinstAuraMgr_x                                             0xDB2C00
#define pinstBandageTarget_x                                       0xF98588
#define pinstCamActor_x                                            0xEE52AC
#define pinstCDBStr_x                                              0xEE484C
#define pinstCDisplay_x                                            0xF985B0
#define pinstCEverQuest_x                                          0x1137178
#define pinstCharData_x                                            0xF9856C
#define pinstCharSpawn_x                                           0xF98594
#define pinstControlledMissile_x                                   0xF98568
#define pinstControlledPlayer_x                                    0xF98594
#define pinstCSidlManager_x                                        0x17A0A94
#define pinstCXWndManager_x                                        0x17A0A8C
#define instDynamicZone_x                                          0xFA5450
#define pinstDZMember_x                                            0xFA5560
#define pinstDZTimerInfo_x                                         0xFA5564
#define pinstEQItemList_x                                          0xF94CC8
#define instEQMisc_x                                               0xB9BAC0
#define pinstEQSoundManager_x                                      0xEE5E10
#define instExpeditionLeader_x                                     0xFA549A
#define instExpeditionName_x                                       0xFA54DA
#define pinstGroup_x                                               0xF9603E
#define pinstImeManager_x                                          0x17A0A98
#define pinstLocalPlayer_x                                         0xF98580
#define pinstMercenaryData_x                                       0x102A9C0
#define pinstMercAltAbilities_x                                    0xEE5D2C
#define pinstModelPlayer_x                                         0xF985AC
#define pinstPCData_x                                              0xF9856C
#define pinstSkillMgr_x                                            0x102B7F8
#define pinstSpawnManager_x                                        0x102B0E0
#define pinstSpellManager_x                                        0x102B940
#define pinstSpellSets_x                                           0x10228A0
#define pinstStringTable_x                                         0xF98514
#define pinstSwitchManager_x                                       0xF95BD0
#define pinstTarget_x                                              0xF98598
#define pinstTargetObject_x                                        0xF98570
#define pinstTargetSwitch_x                                        0xF98574
#define pinstTaskMember_x                                          0xEE4798
#define pinstTrackTarget_x                                         0xF9858C
#define pinstTradeTarget_x                                         0xF9857C
#define instTributeActive_x                                        0xB9BAE5
#define pinstViewActor_x                                           0xEE52A8
#define pinstWorldData_x                                           0xF98550


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xDA9218
#define pinstCAudioTriggersWindow_x                                0xDA90A8
#define pinstCCharacterSelect_x                                    0xEE5148
#define pinstCFacePick_x                                           0xEE50F8
#define pinstCNoteWnd_x                                            0xEE5100
#define pinstCBookWnd_x                                            0xEE5108
#define pinstCPetInfoWnd_x                                         0xEE510C
#define pinstCTrainWnd_x                                           0xEE5110
#define pinstCSkillsWnd_x                                          0xEE5114
#define pinstCSkillsSelectWnd_x                                    0xEE5118
#define pinstCCombatSkillsSelectWnd_x                              0xEE511C
#define pinstCFriendsWnd_x                                         0xEE5120
#define pinstCAuraWnd_x                                            0xEE5124
#define pinstCRespawnWnd_x                                         0xEE5128
#define pinstCBandolierWnd_x                                       0xEE512C
#define pinstCPotionBeltWnd_x                                      0xEE5130
#define pinstCAAWnd_x                                              0xEE5134
#define pinstCGroupSearchFiltersWnd_x                              0xEE5138
#define pinstCLoadskinWnd_x                                        0xEE513C
#define pinstCAlarmWnd_x                                           0xEE5140
#define pinstCMusicPlayerWnd_x                                     0xEE5144
#define pinstCMailWnd_x                                            0xEE514C
#define pinstCMailCompositionWnd_x                                 0xEE5150
#define pinstCMailAddressBookWnd_x                                 0xEE5154
#define pinstCRaidWnd_x                                            0xEE515C
#define pinstCRaidOptionsWnd_x                                     0xEE5160
#define pinstCBreathWnd_x                                          0xEE5164
#define pinstCMapViewWnd_x                                         0xEE5168
#define pinstCMapToolbarWnd_x                                      0xEE516C
#define pinstCEditLabelWnd_x                                       0xEE5170
#define pinstCTargetWnd_x                                          0xEE5174
#define pinstCColorPickerWnd_x                                     0xEE5178
#define pinstCPlayerWnd_x                                          0xEE517C
#define pinstCOptionsWnd_x                                         0xEE5180
#define pinstCBuffWindowNORMAL_x                                   0xEE5184
#define pinstCBuffWindowSHORT_x                                    0xEE5188
#define pinstCharacterCreation_x                                   0xEE518C
#define pinstCCursorAttachment_x                                   0xEE5190
#define pinstCCastingWnd_x                                         0xEE5194
#define pinstCCastSpellWnd_x                                       0xEE5198
#define pinstCSpellBookWnd_x                                       0xEE519C
#define pinstCInventoryWnd_x                                       0xEE51A0
#define pinstCBankWnd_x                                            0xEE51A4
#define pinstCQuantityWnd_x                                        0xEE51A8
#define pinstCLootWnd_x                                            0xEE51AC
#define pinstCActionsWnd_x                                         0xEE51B0
#define pinstCCombatAbilityWnd_x                                   0xEE51B4
#define pinstCMerchantWnd_x                                        0xEE51B8
#define pinstCTradeWnd_x                                           0xEE51BC
#define pinstCSelectorWnd_x                                        0xEE51C0
#define pinstCBazaarWnd_x                                          0xEE51C4
#define pinstCBazaarSearchWnd_x                                    0xEE51C8
#define pinstCGiveWnd_x                                            0xEE51E4
#define pinstCTrackingWnd_x                                        0xEE51EC
#define pinstCInspectWnd_x                                         0xEE51F0
#define pinstCSocialEditWnd_x                                      0xEE51F4
#define pinstCFeedbackWnd_x                                        0xEE51F8
#define pinstCBugReportWnd_x                                       0xEE51FC
#define pinstCVideoModesWnd_x                                      0xEE5200
#define pinstCTextEntryWnd_x                                       0xEE5208
#define pinstCFileSelectionWnd_x                                   0xEE520C
#define pinstCCompassWnd_x                                         0xEE5210
#define pinstCPlayerNotesWnd_x                                     0xEE5214
#define pinstCGemsGameWnd_x                                        0xEE5218
#define pinstCTimeLeftWnd_x                                        0xEE521C
#define pinstCPetitionQWnd_x                                       0xEE5230
#define pinstCSoulmarkWnd_x                                        0xEE5234
#define pinstCStoryWnd_x                                           0xEE5238
#define pinstCJournalTextWnd_x                                     0xEE523C
#define pinstCJournalCatWnd_x                                      0xEE5240
#define pinstCBodyTintWnd_x                                        0xEE5244
#define pinstCServerListWnd_x                                      0xEE5248
#define pinstCAvaZoneWnd_x                                         0xEE5254
#define pinstCBlockedBuffWnd_x                                     0xEE5258
#define pinstCBlockedPetBuffWnd_x                                  0xEE525C
#define pinstCInvSlotMgr_x                                         0xEE52A0
#define pinstCContainerMgr_x                                       0xEE52A4
#define pinstCAdventureLeaderboardWnd_x                            0x1137B28
#define pinstCAdventureRequestWnd_x                                0x1137BA0
#define pinstCAltStorageWnd_x                                      0x1137E80
#define pinstCAdventureStatsWnd_x                                  0x1137C18
#define pinstCBarterMerchantWnd_x                                  0x1138A68
#define pinstCBarterSearchWnd_x                                    0x1138AE0
#define pinstCBarterWnd_x                                          0x1138B58
#define pinstCChatManager_x                                        0x11391E8
#define pinstCDynamicZoneWnd_x                                     0x1139698
#define pinstCEQMainWnd_x                                          0x1139830
#define pinstCFellowshipWnd_x                                      0x113962C
#define pinstCFindLocationWnd_x                                    0x1139B00
#define pinstCGroupSearchWnd_x                                     0x1139DD0
#define pinstCGroupWnd_x                                           0x1139E48
#define pinstCGuildBankWnd_x                                       0x1139EC0
#define pinstCGuildMgmtWnd_x                                       0x113BFB0
#define pinstCHotButtonWnd_x                                       0x113C07C
#define pinstCHotButtonWnd1_x                                      0x113C07C
#define pinstCHotButtonWnd2_x                                      0x113C080
#define pinstCHotButtonWnd3_x                                      0x113C084
#define pinstCHotButtonWnd4_x                                      0x113C0A8
#define pinstCItemDisplayManager_x                                 0x113C3A0
#define pinstCItemExpTransferWnd_x                                 0x113C41C
#define pinstCLFGuildWnd_x                                         0x113C6F8
#define pinstCMIZoneSelectWnd_x                                    0x113CCE0
#define pinstCConfirmationDialog_x                                 0x113D3E8
#define pinstCPopupWndManager_x                                    0x113D3E8
#define pinstCProgressionSelectionWnd_x                            0x113D4D8
#define pinstCPvPStatsWnd_x                                        0x113D5C8
#define pinstCSystemInfoDialogBox_x                                0x113DCD0
#define pinstCTaskWnd_x                                            0x113F098
#define pinstCTaskSomething_x                                      0xDB3340
#define pinstCTaskTemplateSelectWnd_x                              0x113F020
#define pinstCTipWndOFDAY_x                                        0x113F2F0
#define pinstCTipWndCONTEXT_x                                      0x113F2F4
#define pinstCTitleWnd_x                                           0x113F370
#define pinstCContextMenuManager_x                                 0x17A0A04
#define pinstCVoiceMacroWnd_x                                      0x102BFA8
#define pinstCHtmlWnd_x                                            0x102C0A0
#define pinstIconCache_x                                           0x1139804
#define pinstCTradeskillWnd_x                                      0x113F470
#define pinstCAdvancedLootWnd_x                                    0xEE5294
#define pinstRewardSelectionWnd_x                                  0x113DAF0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x52A040
#define __ConvertItemTags_x                                        0x5172C0
#define __ExecuteCmd_x                                             0x501C90
#define __EQGetTime_x                                              0x85EBD0
#define __get_melee_range_x                                        0x508960
#define __GetGaugeValueFromEQ_x                                    0x79E7C0
#define __GetLabelFromEQ_x                                         0x79FA00
#define __ToggleMount_x                                            0x6C7FB0
#define __GetXTargetType_x                                         0x91CE50
#define __LoadFrontEnd_x                                           0x62CE20
#define __NewUIINI_x                                               0x79E0C0
#define __ProcessGameEvents_x                                      0x56DD90
#define __ProcessMouseEvent_x                                      0x56D530
#define CrashDetected_x                                            0x62E8F0
#define wwsCrashReportCheckForUploader_x                           0x7F36C0
#define DrawNetStatus_x                                            0x5A4A60
#define Util__FastTime_x                                           0x85E720
#define Expansion_HoT_x                                            0xFA6994
#define __HelpPath_x                                               0x102A0F8

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41ED90
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419BE0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C0B60
#define AltAdvManager__IsAbilityReady_x                            0x4C0BD0
#define AltAdvManager__GetAltAbility_x                             0x4C0F90

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x464900
#define CharacterZoneClient__MakeMeVisible_x                       0x469A30
// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65C6D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66ADC0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x584000

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x685AF0
#define CChatManager__InitContextMenu_x                            0x686610

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8CECF0
#define CContextMenu__dCContextMenu_x                              0x8CEEF0
#define CContextMenu__AddMenuItem_x                                0x8CEF00
#define CContextMenu__RemoveMenuItem_x                             0x8CF1E0
#define CContextMenu__RemoveAllMenuItems_x                         0x8CF200
#define CContextMenuManager__AddMenu_x                             0x8BAC80
#define CContextMenuManager__RemoveMenu_x                          0x8BAFB0
#define CContextMenuManager__PopupMenu_x                           0x8BB400
#define CContextMenuManager__Flush_x                               0x8BACF0
#define CContextMenuManager__GetMenu_x                             0x415230

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x845280
#define CChatService__GetFriendName_x                              0x845290

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68B670
#define CChatWindow__Clear_x                                       0x68B230
#define CChatWindow__WndNotification_x                             0x68BBA0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BEB70
#define CComboWnd__Draw_x                                          0x8BED80
#define CComboWnd__GetCurChoice_x                                  0x8BE940
#define CComboWnd__GetListRect_x                                   0x8BF020
#define CComboWnd__GetTextRect_x                                   0x8BEBE0
#define CComboWnd__InsertChoice_x                                  0x8BF090
#define CComboWnd__SetColors_x                                     0x8BE8D0
#define CComboWnd__SetChoice_x                                     0x8BE900
#define CComboWnd__GetItemCount_x                                  0x8BE930

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x694D60
#define CContainerWnd__vftable_x                                   0xA886D8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4AEDE0
#define CDisplay__GetClickedActor_x                                0x4A7960
#define CDisplay__GetUserDefinedColor_x                            0x4A6220
#define CDisplay__GetWorldFilePath_x                               0x4A5670
#define CDisplay__is3dON_x                                         0x4A4A40
#define CDisplay__ReloadUI_x                                       0x4BA2B0
#define CDisplay__WriteTextHD2_x                                   0x4AB180

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E52C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8D3670
#define CEditWnd__GetCharIndexPt_x                                 0x8D46F0
#define CEditWnd__GetDisplayString_x                               0x8D3820
#define CEditWnd__GetHorzOffset_x                                  0x8D3B60
#define CEditWnd__GetLineForPrintableChar_x                        0x8D41C0
#define CEditWnd__GetSelStartPt_x                                  0x8D49A0
#define CEditWnd__GetSTMLSafeText_x                                0x8D3CF0
#define CEditWnd__PointFromPrintableChar_x                         0x8D42B0
#define CEditWnd__SelectableCharFromPoint_x                        0x8D4430
#define CEditWnd__SetEditable_x                                    0x8D3CC0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54B6E0
#define CEverQuest__DoTellWindow_x                                 0x5510E0
#define CEverQuest__DropHeldItemOnGround_x                         0x559C10
#define CEverQuest__dsp_chat_x                                     0x552880
#define CEverQuest__Emote_x                                        0x552AE0
#define CEverQuest__EnterZone_x                                    0x566370
#define CEverQuest__GetBodyTypeDesc_x                              0x547F40
#define CEverQuest__GetClassDesc_x                                 0x54DC50
#define CEverQuest__GetClassThreeLetterCode_x                      0x54E250
#define CEverQuest__GetDeityDesc_x                                 0x548820
#define CEverQuest__GetLangDesc_x                                  0x5482D0
#define CEverQuest__GetRaceDesc_x                                  0x54E410
#define CEverQuest__InterpretCmd_x                                 0x5533C0
#define CEverQuest__LeftClickedOnPlayer_x                          0x56A490
#define CEverQuest__LMouseUp_x                                     0x56C580
#define CEverQuest__RightClickedOnPlayer_x                         0x56AF90
#define CEverQuest__RMouseUp_x                                     0x56BFE0
#define CEverQuest__SetGameState_x                                 0x54BD90
#define CEverQuest__UPCNotificationFlush_x                         0x554560
#define CEverQuest__IssuePetCommand_x                              0x5540C0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A5900
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A5960
#define CGaugeWnd__Draw_x                                          0x6A5D90

// CGuild
#define CGuild__FindMemberByName_x                                 0x435A90

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C29E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D07E0
#define CInvSlotMgr__MoveItem_x                                    0x6D1720
#define CInvSlotMgr__SelectSlot_x                                  0x6D0890

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CFC80
#define CInvSlot__SliderComplete_x                                 0x6CD650
#define CInvSlot__GetItemBase_x                                    0x6CCAD0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D28E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79B2D0
#define CItemDisplayWnd__UpdateStrings_x                           0x6D3C40

// CLabel 
#define CLabel__Draw_x                                             0x6EE9B0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8AA940
#define CListWnd__dCListWnd_x                                      0x8AB970
#define CListWnd__AddColumn_x                                      0x8AB910
#define CListWnd__AddColumn1_x                                     0x8AB180
#define CListWnd__AddLine_x                                        0x8AAC00
#define CListWnd__AddString_x                                      0x8AAE10
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A7CA0
#define CListWnd__CalculateVSBRange_x                              0x8A9E00
#define CListWnd__ClearAllSel_x                                    0x8A6F60
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8AA7D0
#define CListWnd__Compare_x                                        0x8A8790
#define CListWnd__Draw_x                                           0x8A9A10
#define CListWnd__DrawColumnSeparators_x                           0x8A98A0
#define CListWnd__DrawHeader_x                                     0x8A7270
#define CListWnd__DrawItem_x                                       0x8A8DE0
#define CListWnd__DrawLine_x                                       0x8A9540
#define CListWnd__DrawSeparator_x                                  0x8A9940
#define CListWnd__EnsureVisible_x                                  0x8A7E00
#define CListWnd__ExtendSel_x                                      0x8A8CF0
#define CListWnd__GetColumnMinWidth_x                              0x8A6920
#define CListWnd__GetColumnWidth_x                                 0x8A6840
#define CListWnd__GetCurSel_x                                      0x8A6010
#define CListWnd__GetItemAtPoint_x                                 0x8A8090
#define CListWnd__GetItemAtPoint1_x                                0x8A8100
#define CListWnd__GetItemData_x                                    0x8A6350
#define CListWnd__GetItemHeight_x                                  0x8A7900
#define CListWnd__GetItemIcon_x                                    0x8A6530
#define CListWnd__GetItemRect_x                                    0x8A7ED0
#define CListWnd__GetItemText_x                                    0x8A63E0
#define CListWnd__GetSelList_x                                     0x8AB070
#define CListWnd__GetSeparatorRect_x                               0x8A86B0
#define CListWnd__RemoveLine_x                                     0x8AAFF0
#define CListWnd__SetColors_x                                      0x8A6160
#define CListWnd__SetColumnJustification_x                         0x8A6BF0
#define CListWnd__SetColumnWidth_x                                 0x8A68D0
#define CListWnd__SetCurSel_x                                      0x8A6050
#define CListWnd__SetItemColor_x                                   0x8AA4B0
#define CListWnd__SetItemData_x                                    0x8A7010
#define CListWnd__SetItemText_x                                    0x8AA2F0
#define CListWnd__ShiftColumnSeparator_x                           0x8AA180
#define CListWnd__Sort_x                                           0x8ABA70
#define CListWnd__ToggleSel_x                                      0x8A6EE0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x707FF0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x729170
#define CMerchantWnd__RequestBuyItem_x                             0x72FF60
#define CMerchantWnd__RequestSellItem_x                            0x7309B0
#define CMerchantWnd__SelectRecoverySlot_x                         0x729420
#define CMerchantWnd__SelectBuySellSlot_x                          0x728680
#define CMerchantWnd__ActualSelect_x                               0x72CEA0

// CObfuscator
#define CObfuscator__doit_x                                        0x8253D0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8C9C60
#define CSidlManager__CreateLabel_x                                0x7912E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x6538E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x653810
#define CSidlScreenWnd__ConvertToRes_x                             0x8E51A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8C1800
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8C2CF0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8C2DA0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8C2260
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C11B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C0900
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C13A0
#define CSidlScreenWnd__Init1_x                                    0x8C29C0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8C18B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C0AC0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8C24B0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C03C0
#define CSidlScreenWnd__StoreIniVis_x                              0x8C0890
#define CSidlScreenWnd__WndNotification_x                          0x8C2740
#define CSidlScreenWnd__GetChildItem_x                             0x8C09D0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B3FA0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5EEF40
#define CSkillMgr__GetSkillCap_x                                   0x5EF0E0
#define CSkillMgr__GetNameToken_x                                  0x5EEBB0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E4460
#define CSliderWnd__SetValue_x                                     0x8E4630
#define CSliderWnd__SetNumTicks_x                                  0x8E4DB0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x798F70

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8DEE40
#define CStmlWnd__CalculateHSBRange_x                              0x8D7370
#define CStmlWnd__CalculateVSBRange_x                              0x8D7400
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D7580
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D7E60
#define CStmlWnd__ForceParseNow_x                                  0x8DF790
#define CStmlWnd__GetNextTagPiece_x                                0x8D7D60
#define CStmlWnd__GetSTMLText_x                                    0x68AAD0
#define CStmlWnd__GetVisibleText_x                                 0x8D88B0
#define CStmlWnd__InitializeWindowVariables_x                      0x8DAC40
#define CStmlWnd__MakeStmlColorTag_x                               0x8D6670
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D66D0
#define CStmlWnd__SetSTMLText_x                                    0x8DC4A0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8DEAE0
#define CStmlWnd__UpdateHistoryString_x                            0x8D97F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E6990
#define CTabWnd__DrawCurrentPage_x                                 0x8E6200
#define CTabWnd__DrawTab_x                                         0x8E5FD0
#define CTabWnd__GetCurrentPage_x                                  0x8E65D0
#define CTabWnd__GetPageInnerRect_x                                0x8E5CC0
#define CTabWnd__GetTabInnerRect_x                                 0x8E5EC0
#define CTabWnd__GetTabRect_x                                      0x8E5D90
#define CTabWnd__InsertPage_x                                      0x8E6C80
#define CTabWnd__SetPage_x                                         0x8E6600
#define CTabWnd__SetPageRect_x                                     0x8E68D0
#define CTabWnd__UpdatePage_x                                      0x8E6C20

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431890

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BE540

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8EBBF0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A4170

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4022B0
#define CXStr__CXStr1_x                                            0x7DB870
#define CXStr__CXStr3_x                                            0x85B7B0
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x85B920
#define CXStr__operator_equal1_x                                   0x85B970
#define CXStr__operator_plus_equal1_x                              0x85CA50

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B31E0
#define CXWnd__Center_x                                            0x8B92B0
#define CXWnd__ClrFocus_x                                          0x8B2DD0
#define CXWnd__DoAllDrawing_x                                      0x8B8F00
#define CXWnd__DrawChildren_x                                      0x8B90A0
#define CXWnd__DrawColoredRect_x                                   0x8B3590
#define CXWnd__DrawTooltip_x                                       0x8B3840
#define CXWnd__DrawTooltipAtPoint_x                                0x8B7EA0
#define CXWnd__GetBorderFrame_x                                    0x8B3CA0
#define CXWnd__GetChildWndAt_x                                     0x8B9C70
#define CXWnd__GetClientClipRect_x                                 0x8B3A60
#define CXWnd__GetScreenClipRect_x                                 0x8B8590
#define CXWnd__GetScreenRect_x                                     0x8B3E40
#define CXWnd__GetTooltipRect_x                                    0x8B36D0
#define CXWnd__GetWindowTextA_x                                    0x422CD0
#define CXWnd__IsActive_x                                          0x8AE750
#define CXWnd__IsDescendantOf_x                                    0x8B3BF0
#define CXWnd__IsReallyVisible_x                                   0x8B6EC0
#define CXWnd__IsType_x                                            0x8E8320
#define CXWnd__Move_x                                              0x8B6630
#define CXWnd__Move1_x                                             0x8B8BE0
#define CXWnd__ProcessTransition_x                                 0x8B3190
#define CXWnd__Refade_x                                            0x8B2F70
#define CXWnd__Resize_x                                            0x8B3F00
#define CXWnd__Right_x                                             0x8B8390
#define CXWnd__SetFocus_x                                          0x8B57C0
#define CXWnd__SetFont_x                                           0x8B2E20
#define CXWnd__SetKeyTooltip_x                                     0x8B4170
#define CXWnd__SetMouseOver_x                                      0x8B88E0
#define CXWnd__StartFade_x                                         0x8B3230
#define CXWnd__GetChildItem_x                                      0x8B8820

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B0060
#define CXWndManager__DrawWindows_x                                0x8AFCA0
#define CXWndManager__GetKeyboardFlags_x                           0x8AE2C0
#define CXWndManager__HandleKeyboardMsg_x                          0x8AEBE0
#define CXWndManager__RemoveWnd_x                                  0x8AE8E0

// CDBStr
#define CDBStr__GetString_x                                        0x4A2EF0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44ECF0
#define EQ_Character__Cur_HP_x                                     0x463FD0
#define EQ_Character__GetAACastingTimeModifier_x                   0x446D60
#define EQ_Character__GetCharInfo2_x                               0x82FC70
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EEB0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F090
#define EQ_Character__Max_Endurance_x                              0x5B6AC0
#define EQ_Character__Max_HP_x                                     0x459C50
#define EQ_Character__Max_Mana_x                                   0x5B68F0
#define EQ_Character__doCombatAbility_x                            0x5B3EF0
#define EQ_Character__UseSkill_x                                   0x46EC20
#define EQ_Character__GetConLevel_x                                0x5A9110
#define EQ_Character__IsExpansionFlag_x                            0x422210
#define EQ_Character__TotalEffect_x                                0x44BE70

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x589800
#define EQ_Item__CreateItemTagString_x                             0x80F150
#define EQ_Item__IsStackable_x                                     0x803370
#define EQ_Item__GetImageNum_x                                     0x805FC0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C2CA0
#define EQ_LoadingS__Array_x                                       0xBA9848

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B8250
#define EQ_PC__GetAltAbilityIndex_x                                0x8180F0
#define EQ_PC__GetCombatAbility_x                                  0x818180
#define EQ_PC__GetCombatAbilityTimer_x                             0x818230
#define EQ_PC__GetItemTimerValue_x                                 0x5B1CD0
#define EQ_PC__HasLoreItem_x                                       0x5AC450
#define EQ_PC__AlertInventoryChanged_x                             0x5A90E0
#define EQ_PC__GetPcZoneClient_x                                   0x5D2800
#define EQ_PC__RemoveMyAffect_x									   0x5B11E0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x506960
#define EQItemList__add_item_x                                     0x5068A0
#define EQItemList__delete_item_x                                  0x506D60
#define EQItemList__FreeItemList_x                                 0x506C60

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A20D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BD820
#define EQPlayer__dEQPlayer_x                                      0x5C6650
#define EQPlayer__DoAttack_x                                       0x5D86C0
#define EQPlayer__EQPlayer_x                                       0x5C8A70
#define EQPlayer__SetNameSpriteState_x                             0x5C3320
#define EQPlayer__SetNameSpriteTint_x                              0x5BEBF0
#define EQPlayer__IsBodyType_j_x                                   0x919090
#define EQPlayer__IsTargetable_x                                   0x919950
#define EQPlayer__CanSee_x                                         0x919E70

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CCDF0
#define EQPlayerManager__GetSpawnByName_x                          0x5CD250

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x58F9A0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x58F9E0
#define KeypressHandler__ClearCommandStateArray_x                  0x58F580
#define KeypressHandler__HandleKeyDown_x                           0x58DEE0
#define KeypressHandler__HandleKeyUp_x                             0x58E200
#define KeypressHandler__SaveKeymapping_x                          0x58F650

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7003D0
#define MapViewMap__SaveEx_x                                       0x703CB0

#define PlayerPointManager__GetAltCurrency_x                       0x82AC10

// StringTable 
#define StringTable__getString_x                                   0x825670

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B6570

//Doors
#define EQSwitch__UseSwitch_x                                      0x5451A0

//IconCache
#define IconCache__GetIcon_x                                       0x69B1E0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x692080
#define CContainerMgr__CloseContainer_x                            0x6928A0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x761630

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x582AC0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D63C0
#define EQ_Spell__SpellAffects_x                                   0x4D6460
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D6490
#define CharacterZoneClient__CalcAffectChange_x                    0x448080
#define CLootWnd__LootAll_x                                        0x6F5CC0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A6DA0
#define CTargetWnd__WndNotification_x                              0x7A6890

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7ABF60
//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x0
