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
#include "eqgame-private(Test).h"
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Sep 18 2015"
#define __ExpectedVersionTime                                     "14:47:52"
#define __ActualVersionDate_x                                      0xACCAB0
#define __ActualVersionTime_x                                      0xACCABC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59A1A0
#define __MemChecker1_x                                            0x8976C0
#define __MemChecker2_x                                            0x6330D0
#define __MemChecker3_x                                            0x633020
#define __MemChecker4_x                                            0x7E8FC0
#define __EncryptPad0_x                                            0xC62FE0
#define __EncryptPad1_x                                            0xDECB58
#define __EncryptPad2_x                                            0xCACAC8
#define __EncryptPad3_x                                            0xCAC6C8
#define __EncryptPad4_x                                            0xDC7240
#define __AC1_x                                                    0x7A6405
#define __AC2_x                                                    0x54F727
#define __AC3_x                                                    0x563F20
#define __AC4_x                                                    0x56ABA0
#define __AC5_x                                                    0x576A2E
#define __AC6_x                                                    0x57A4D9
#define __AC7_x                                                    0x5710DC
#define __AC1_Data                                                 0x11111111

// Direct Input
#define DI8__Main_x                                                0x11988C8
#define DI8__Keyboard_x                                            0x11988CC
#define DI8__Mouse_x                                               0x11988D0
#define DI8__Mouse_Copy_x                                          0x1006EE4
#define DI8__Mouse_Check_x                                         0x10907B4
#define __AltTimerReady_x                                          0xFF8231
#define __Attack_x                                                 0x108B453
#define __Autofire_x                                               0x108B454
#define __BindList_x                                               0xC250F0
#define __bCommandEnabled_x                                        0xFF6340
#define __Clicks_x                                                 0x1006FA0
#define __CommandList_x                                            0xC29460
#define __CurrentMapLabel_x                                        0x119E320
#define __CurrentSocial_x                                          0xBDEF54
#define __DoAbilityList_x                                          0x103D708
#define __do_loot_x                                                0x516CF0
#define __DrawHandler_x                                            0x180500C
#define __GroupCount_x                                             0xFF790A

#define __Guilds_x                                                 0xFFD520
#define __gWorld_x                                                 0xFF9DC4
#define __HotkeyPage_x                                             0x1084108
#define __HWnd_x                                                   0x10907D0
#define __InChatMode_x                                             0x1006ECC
#define __LastTell_x                                               0x1008E10
#define __LMouseHeldTime_x                                         0x100700C
#define __Mouse_x                                                  0x11988D4
#define __MouseLook_x                                              0x1006F66
#define __MouseEventTime_x                                         0x108BC5C
#define __gpbCommandEvent_x                                        0xFF9E8C
#define __NetStatusToggle_x                                        0x1006F69
#define __PCNames_x                                                0x1008430
#define __RangeAttackReady_x                                       0x10080F0
#define __RMouseHeldTime_x                                         0x1007008
#define __RunWalkState_x                                           0x1006ED0
#define __ScreenMode_x                                             0xF460F0
#define __ScreenX_x                                                0x1006E84
#define __ScreenY_x                                                0x1006E80
#define __ScreenXMax_x                                             0x1006E88
#define __ScreenYMax_x                                             0x1006E8C
#define __ServerHost_x                                             0xFF7854
#define __ServerName_x                                             0x103D6C8
#define __ShiftKeyDown_x                                           0x1007574
#define __ShowNames_x                                              0x10082C4
#define __Socials_x                                                0x103D7C8
#define __SubscriptionType_x                                       0x11CC7F0
#define __TargetAggroHolder_x                                      0x11A055C
#define __GroupAggro_x                                             0x11A059C
#define __LoginName_x                                              0x108F3A8
#define __Inviter_x                                                0x108B3D0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xFF9EB0
#define instEQZoneInfo_x                                           0x100715C
#define instKeypressHandler_x                                      0x108BC40
#define pinstActiveBanker_x                                        0xFF9E68
#define pinstActiveCorpse_x                                        0xFF9E6C
#define pinstActiveGMaster_x                                       0xFF9E70
#define pinstActiveMerchant_x                                      0xFF9E64
#define pinstAggroInfo_x                                           0xE08538
#define pinstAltAdvManager_x                                       0xF471F0
#define pinstAuraMgr_x                                             0xE14438
#define pinstBandageTarget_x                                       0xFF9E50
#define pinstCamActor_x                                            0xF46AF8
#define pinstCDBStr_x                                              0xF46084
#define pinstCDisplay_x                                            0xFF9E78
#define pinstCEverQuest_x                                          0x1198A48
#define pinstCharData_x                                            0xFF9E34
#define pinstCharSpawn_x                                           0xFF9E5C
#define pinstControlledMissile_x                                   0xFF9E30
#define pinstControlledPlayer_x                                    0xFF9E5C
#define pinstCSidlManager_x                                        0x1804444
#define pinstCXWndManager_x                                        0x180443C
#define instDynamicZone_x                                          0x1006D18
#define pinstDZMember_x                                            0x1006E28
#define pinstDZTimerInfo_x                                         0x1006E2C
#define pinstEQItemList_x                                          0xFF6590
#define instEQMisc_x                                               0xBFFC58
#define pinstEQSoundManager_x                                      0xF476D8
#define instExpeditionLeader_x                                     0x1006D62
#define instExpeditionName_x                                       0x1006DA2
#define pinstGroup_x                                               0xFF7906
#define pinstImeManager_x                                          0x1804448
#define pinstLocalPlayer_x                                         0xFF9E48
#define pinstMercenaryData_x                                       0x108C290
#define pinstMercenaryStats_x                                      0x11A06A8
#define pinstMercAltAbilities_x                                    0xF4757C
#define pinstModelPlayer_x                                         0xFF9E74
#define pinstPCData_x                                              0xFF9E34
#define pinstSkillMgr_x                                            0x108D0C8
#define pinstSpawnManager_x                                        0x108C9B0
#define pinstSpellManager_x                                        0x108D210
#define pinstSpellSets_x                                           0x108416C
#define pinstStringTable_x                                         0xFF9DDC
#define pinstSwitchManager_x                                       0xFF7498
#define pinstTarget_x                                              0xFF9E60
#define pinstTargetObject_x                                        0xFF9E38
#define pinstTargetSwitch_x                                        0xFF9E3C
#define pinstTaskMember_x                                          0xF45FD0
#define pinstTrackTarget_x                                         0xFF9E54
#define pinstTradeTarget_x                                         0xFF9E44
#define instTributeActive_x                                        0xBFFC7D
#define pinstViewActor_x                                           0xF46AF4
#define pinstWorldData_x                                           0xFF9E18


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE08A18
#define pinstCAudioTriggersWindow_x                                0xE088A8
#define pinstCCharacterSelect_x                                    0xF46990
#define pinstCFacePick_x                                           0xF46940
#define pinstCNoteWnd_x                                            0xF46948
#define pinstCBookWnd_x                                            0xF46950
#define pinstCPetInfoWnd_x                                         0xF46954
#define pinstCTrainWnd_x                                           0xF46958
#define pinstCSkillsWnd_x                                          0xF4695C
#define pinstCSkillsSelectWnd_x                                    0xF46960
#define pinstCCombatSkillsSelectWnd_x                              0xF46964
#define pinstCFriendsWnd_x                                         0xF46968
#define pinstCAuraWnd_x                                            0xF4696C
#define pinstCRespawnWnd_x                                         0xF46970
#define pinstCBandolierWnd_x                                       0xF46974
#define pinstCPotionBeltWnd_x                                      0xF46978
#define pinstCAAWnd_x                                              0xF4697C
#define pinstCGroupSearchFiltersWnd_x                              0xF46980
#define pinstCLoadskinWnd_x                                        0xF46984
#define pinstCAlarmWnd_x                                           0xF46988
#define pinstCMusicPlayerWnd_x                                     0xF4698C
#define pinstCMailWnd_x                                            0xF46994
#define pinstCMailCompositionWnd_x                                 0xF46998
#define pinstCMailAddressBookWnd_x                                 0xF4699C
#define pinstCRaidWnd_x                                            0xF469A4
#define pinstCRaidOptionsWnd_x                                     0xF469A8
#define pinstCBreathWnd_x                                          0xF469AC
#define pinstCMapViewWnd_x                                         0xF469B0
#define pinstCMapToolbarWnd_x                                      0xF469B4
#define pinstCEditLabelWnd_x                                       0xF469B8
#define pinstCTargetWnd_x                                          0xF469BC
#define pinstCColorPickerWnd_x                                     0xF469C0
#define pinstCPlayerWnd_x                                          0xF469C4
#define pinstCOptionsWnd_x                                         0xF469C8
#define pinstCBuffWindowNORMAL_x                                   0xF469CC
#define pinstCBuffWindowSHORT_x                                    0xF469D0
#define pinstCharacterCreation_x                                   0xF469D4
#define pinstCCursorAttachment_x                                   0xF469D8
#define pinstCCastingWnd_x                                         0xF469DC
#define pinstCCastSpellWnd_x                                       0xF469E0
#define pinstCSpellBookWnd_x                                       0xF469E4
#define pinstCInventoryWnd_x                                       0xF469E8
#define pinstCBankWnd_x                                            0xF469EC
#define pinstCQuantityWnd_x                                        0xF469F0
#define pinstCLootWnd_x                                            0xF469F4
#define pinstCActionsWnd_x                                         0xF469F8
#define pinstCCombatAbilityWnd_x                                   0xF469FC
#define pinstCMerchantWnd_x                                        0xF46A00
#define pinstCTradeWnd_x                                           0xF46A04
#define pinstCSelectorWnd_x                                        0xF46A08
#define pinstCBazaarWnd_x                                          0xF46A0C
#define pinstCBazaarSearchWnd_x                                    0xF46A10
#define pinstCGiveWnd_x                                            0xF46A2C
#define pinstCTrackingWnd_x                                        0xF46A34
#define pinstCInspectWnd_x                                         0xF46A38
#define pinstCSocialEditWnd_x                                      0xF46A3C
#define pinstCFeedbackWnd_x                                        0xF46A40
#define pinstCBugReportWnd_x                                       0xF46A44
#define pinstCVideoModesWnd_x                                      0xF46A48
#define pinstCTextEntryWnd_x                                       0xF46A50
#define pinstCFileSelectionWnd_x                                   0xF46A54
#define pinstCCompassWnd_x                                         0xF46A58
#define pinstCPlayerNotesWnd_x                                     0xF46A5C
#define pinstCGemsGameWnd_x                                        0xF46A60
#define pinstCTimeLeftWnd_x                                        0xF46A64
#define pinstCPetitionQWnd_x                                       0xF46A7C
#define pinstCSoulmarkWnd_x                                        0xF46A80
#define pinstCStoryWnd_x                                           0xF46A84
#define pinstCJournalTextWnd_x                                     0xF46A88
#define pinstCJournalCatWnd_x                                      0xF46A8C
#define pinstCBodyTintWnd_x                                        0xF46A90
#define pinstCServerListWnd_x                                      0xF46A94
#define pinstCAvaZoneWnd_x                                         0xF46AA0
#define pinstCBlockedBuffWnd_x                                     0xF46AA4
#define pinstCBlockedPetBuffWnd_x                                  0xF46AA8
#define pinstCInvSlotMgr_x                                         0xF46AEC
#define pinstCContainerMgr_x                                       0xF46AF0
#define pinstCAdventureLeaderboardWnd_x                            0x11993F8
#define pinstCAdventureRequestWnd_x                                0x1199470
#define pinstCAltStorageWnd_x                                      0x1199750
#define pinstCAdventureStatsWnd_x                                  0x11994E8
#define pinstCBarterMerchantWnd_x                                  0x119A338
#define pinstCBarterSearchWnd_x                                    0x119A3B0
#define pinstCBarterWnd_x                                          0x119A428
#define pinstCChatManager_x                                        0x119AAB8
#define pinstCDynamicZoneWnd_x                                     0x119AF68
#define pinstCEQMainWnd_x                                          0x119B100
#define pinstCFellowshipWnd_x                                      0x119AEFC
#define pinstCFindLocationWnd_x                                    0x119B3D0
#define pinstCGroupSearchWnd_x                                     0x119B6A0
#define pinstCGroupWnd_x                                           0x119B718
#define pinstCGuildBankWnd_x                                       0x119B790
#define pinstCGuildMgmtWnd_x                                       0x119D880
#define pinstCHotButtonWnd_x                                       0x119D94C
#define pinstCHotButtonWnd1_x                                      0x119D94C
#define pinstCHotButtonWnd2_x                                      0x119D950
#define pinstCHotButtonWnd3_x                                      0x119D954
#define pinstCHotButtonWnd4_x                                      0x119D978
#define pinstCItemDisplayManager_x                                 0x119DC70
#define pinstCItemExpTransferWnd_x                                 0x119DCEC
#define pinstCLFGuildWnd_x                                         0x119DFC8
#define pinstCMIZoneSelectWnd_x                                    0x119E5B0
#define pinstCConfirmationDialog_x                                 0x119ECB8
#define pinstCPopupWndManager_x                                    0x119ECB8
#define pinstCProgressionSelectionWnd_x                            0x119EDA8
#define pinstCPvPStatsWnd_x                                        0x119EE98
#define pinstCSystemInfoDialogBox_x                                0x119F5A0
#define pinstCTaskWnd_x                                            0x11A0968
#define pinstCTaskSomething_x                                      0xE14B78
#define pinstCTaskTemplateSelectWnd_x                              0x11A08F0
#define pinstCTipWndOFDAY_x                                        0x11A0BC0
#define pinstCTipWndCONTEXT_x                                      0x11A0BC4
#define pinstCTitleWnd_x                                           0x11A0C40
#define pinstCContextMenuManager_x                                 0x18043B4
#define pinstCVoiceMacroWnd_x                                      0x108D878
#define pinstCHtmlWnd_x                                            0x108D970
#define pinstIconCache_x                                           0x119B0D4
#define pinstCTradeskillWnd_x                                      0x11A0D40
#define pinstCAdvancedLootWnd_x                                    0xF46AE0
#define pinstRewardSelectionWnd_x                                  0x119F3C0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x52E810
#define __ConvertItemTags_x                                        0x51B970
#define __ExecuteCmd_x                                             0x506480
#define __EQGetTime_x                                              0x897A20
#define __get_melee_range_x                                        0x50D130
#define __GetGaugeValueFromEQ_x                                    0x7A5140
#define __GetLabelFromEQ_x                                         0x7A6390
#define __ToggleMount_x                                            0x6CDF00
#define __GetXTargetType_x                                         0x928CF0
#define __LoadFrontEnd_x                                           0x632780
#define __NewUIINI_x                                               0x7A4A40
#define __ProcessGameEvents_x                                      0x572E40
#define __ProcessMouseEvent_x                                      0x5725E0
#define CrashDetected_x                                            0x634250
#define wwsCrashReportCheckForUploader_x                           0x7F8E40
#define DrawNetStatus_x                                            0x5A9BD0
#define Util__FastTime_x                                           0x897370
#define Expansion_HoT_x                                            0x100825C
#define __HelpPath_x                                               0x108B9C8
//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F010
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419E70

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C2760
#define AltAdvManager__IsAbilityReady_x                            0x4C27D0
#define AltAdvManager__GetAltAbility_x                             0x4C2B90

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465640
#define CharacterZoneClient__MakeMeVisible_x                       0x46B020
#define CharacterZoneClient__IsStackBlocked_x                      0x447C00

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x662370

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x670770

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5891A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68B6E0
#define CChatManager__InitContextMenu_x                            0x68C260

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DA950
#define CContextMenu__AddMenuItem_x                                0x8DAB70
#define CContextMenu__dCContextMenu_x                              0x8DAB60
#define CContextMenu__RemoveMenuItem_x                             0x8DAE60
#define CContextMenu__RemoveAllMenuItems_x                         0x8DAE80
#define CContextMenuManager__AddMenu_x                             0x8C66E0
#define CContextMenuManager__RemoveMenu_x                          0x8C6A30
#define CContextMenuManager__PopupMenu_x                           0x8C6E80
#define CContextMenuManager__Flush_x                               0x8C6750
#define CContextMenuManager__GetMenu_x                             0x4154A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87D8C0
#define CChatService__GetFriendName_x                              0x87D8D0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x691500
#define CChatWindow__Clear_x                                       0x6910C0
#define CChatWindow__WndNotification_x                             0x691A40

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CA610
#define CComboWnd__Draw_x                                          0x8CA820
#define CComboWnd__GetCurChoice_x                                  0x8CA3E0
#define CComboWnd__GetListRect_x                                   0x8CAAC0
#define CComboWnd__GetTextRect_x                                   0x8CA680
#define CComboWnd__InsertChoice_x                                  0x8CAB30
#define CComboWnd__SetColors_x                                     0x8CA370
#define CComboWnd__SetChoice_x                                     0x8CA3A0
#define CComboWnd__GetItemCount_x                                  0x8CA3D0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69AC60
#define CContainerWnd__vftable_x                                   0xAD6448

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B0900
#define CDisplay__GetClickedActor_x                                0x4A9480
#define CDisplay__GetUserDefinedColor_x                            0x4A7D40
#define CDisplay__GetWorldFilePath_x                               0x4A7190
#define CDisplay__is3dON_x                                         0x4A6560
#define CDisplay__ReloadUI_x                                       0x4BBE20
#define CDisplay__WriteTextHD2_x                                   0x4ACCA0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F1050

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DF3A0
#define CEditWnd__GetCharIndexPt_x                                 0x8E0430
#define CEditWnd__GetDisplayString_x                               0x8DF550
#define CEditWnd__GetHorzOffset_x                                  0x8DF890
#define CEditWnd__GetLineForPrintableChar_x                        0x8DFF00
#define CEditWnd__GetSelStartPt_x                                  0x8E06E0
#define CEditWnd__GetSTMLSafeText_x                                0x8DFA30
#define CEditWnd__PointFromPrintableChar_x                         0x8DFFF0
#define CEditWnd__SelectableCharFromPoint_x                        0x8E0170
#define CEditWnd__SetEditable_x                                    0x8DFA00

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54FE70
#define CEverQuest__DoTellWindow_x                                 0x555870
#define CEverQuest__DropHeldItemOnGround_x                         0x55E3A0
#define CEverQuest__dsp_chat_x                                     0x557010
#define CEverQuest__Emote_x                                        0x557270
#define CEverQuest__EnterZone_x                                    0x56B3C0
#define CEverQuest__GetBodyTypeDesc_x                              0x54C6D0
#define CEverQuest__GetClassDesc_x                                 0x5523E0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5529E0
#define CEverQuest__GetDeityDesc_x                                 0x54CFB0
#define CEverQuest__GetLangDesc_x                                  0x54CA60
#define CEverQuest__GetRaceDesc_x                                  0x552BA0
#define CEverQuest__InterpretCmd_x                                 0x557B50
#define CEverQuest__LeftClickedOnPlayer_x                          0x56F540
#define CEverQuest__LMouseUp_x                                     0x571630
#define CEverQuest__RightClickedOnPlayer_x                         0x570040
#define CEverQuest__RMouseUp_x                                     0x571090
#define CEverQuest__SetGameState_x                                 0x550520
#define CEverQuest__UPCNotificationFlush_x                         0x558CF0
#define CEverQuest__IssuePetCommand_x                              0x558850

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AB800
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AB860
#define CGaugeWnd__Draw_x                                          0x6ABC90

// CGuild
#define CGuild__FindMemberByName_x                                 0x435E40

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C8940

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D6780
#define CInvSlotMgr__MoveItem_x                                    0x6D76C0
#define CInvSlotMgr__SelectSlot_x                                  0x6D6830

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D5C10
#define CInvSlot__SliderComplete_x                                 0x6D35D0
#define CInvSlot__GetItemBase_x                                    0x6D2A20

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D8890

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A1AD0
#define CItemDisplayWnd__UpdateStrings_x                           0x6D9BD0

// CLabel 
#define CLabel__Draw_x                                             0x6F49F0

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8B61D0
#define CListWnd__dCListWnd_x                                      0x8B7200
#define CListWnd__AddColumn_x                                      0x8B71A0
#define CListWnd__AddColumn1_x                                     0x8B6A10
#define CListWnd__AddLine_x                                        0x8B6490
#define CListWnd__AddString_x                                      0x8B66A0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B3500
#define CListWnd__CalculateVSBRange_x                              0x8B5690
#define CListWnd__ClearAllSel_x                                    0x8B27B0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B6060
#define CListWnd__Compare_x                                        0x8B4010
#define CListWnd__Draw_x                                           0x8B52A0
#define CListWnd__DrawColumnSeparators_x                           0x8B5130
#define CListWnd__DrawHeader_x                                     0x8B2AC0
#define CListWnd__DrawItem_x                                       0x8B4660
#define CListWnd__DrawLine_x                                       0x8B4DD0
#define CListWnd__DrawSeparator_x                                  0x8B51D0
#define CListWnd__EnsureVisible_x                                  0x8B3660
#define CListWnd__ExtendSel_x                                      0x8B4570
#define CListWnd__GetColumnMinWidth_x                              0x8B2170
#define CListWnd__GetColumnWidth_x                                 0x8B2090
#define CListWnd__GetCurSel_x                                      0x8B1850
#define CListWnd__GetItemAtPoint_x                                 0x8B3900
#define CListWnd__GetItemAtPoint1_x                                0x8B3970
#define CListWnd__GetItemData_x                                    0x8B1BA0
#define CListWnd__GetItemHeight_x                                  0x8B3150
#define CListWnd__GetItemIcon_x                                    0x8B1D80
#define CListWnd__GetItemRect_x                                    0x8B3740
#define CListWnd__GetItemText_x                                    0x8B1C30
#define CListWnd__GetSelList_x                                     0x8B6900
#define CListWnd__GetSeparatorRect_x                               0x8B3F30
#define CListWnd__RemoveLine_x                                     0x8B6880
#define CListWnd__SetColors_x                                      0x8B19A0
#define CListWnd__SetColumnJustification_x                         0x8B2440
#define CListWnd__SetColumnWidth_x                                 0x8B2120
#define CListWnd__SetCurSel_x                                      0x8B1890
#define CListWnd__SetItemColor_x                                   0x8B5D40
#define CListWnd__SetItemData_x                                    0x8B2860
#define CListWnd__SetItemText_x                                    0x8B5B80
#define CListWnd__ShiftColumnSeparator_x                           0x8B5A10
#define CListWnd__Sort_x                                           0x8B7300
#define CListWnd__ToggleSel_x                                      0x8B2730

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70E000

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72F270
#define CMerchantWnd__RequestBuyItem_x                             0x7360E0
#define CMerchantWnd__RequestSellItem_x                            0x736B50
#define CMerchantWnd__SelectRecoverySlot_x                         0x72F520
#define CMerchantWnd__SelectBuySellSlot_x                          0x72E780
#define CMerchantWnd__ActualSelect_x                               0x733000

// CObfuscator
#define CObfuscator__doit_x                                        0x85DC40

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D5820
#define CSidlManager__CreateLabel_x                                0x797AD0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x6595F0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x659520
#define CSidlScreenWnd__ConvertToRes_x                             0x8F0F30
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CD2C0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CE7D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CE880
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CDD40
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CCC70
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CC3B0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CCE60
#define CSidlScreenWnd__Init1_x                                    0x8CE4A0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CD370
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CC570
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CDF90
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CBE70
#define CSidlScreenWnd__StoreIniVis_x                              0x8CC340
#define CSidlScreenWnd__WndNotification_x                          0x8CE220
#define CSidlScreenWnd__GetChildItem_x                             0x8CC480
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BF8F0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F4590
#define CSkillMgr__GetSkillCap_x                                   0x5F4750
#define CSkillMgr__GetNameToken_x                                  0x5F41B0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F01E0
#define CSliderWnd__SetValue_x                                     0x8F03B0
#define CSliderWnd__SetNumTicks_x                                  0x8F0B30

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79F770

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EABC0
#define CStmlWnd__CalculateHSBRange_x                              0x8E3160
#define CStmlWnd__CalculateVSBRange_x                              0x8E30D0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E32E0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E3BC0
#define CStmlWnd__ForceParseNow_x                                  0x8EB510
#define CStmlWnd__GetNextTagPiece_x                                0x8E3AC0
#define CStmlWnd__GetSTMLText_x                                    0x690960
#define CStmlWnd__GetVisibleText_x                                 0x8E4610
#define CStmlWnd__InitializeWindowVariables_x                      0x8E69A0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E23D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E2430
#define CStmlWnd__SetSTMLText_x                                    0x8E8200
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EA860
#define CStmlWnd__UpdateHistoryString_x                            0x8E5550

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F2720
#define CTabWnd__DrawCurrentPage_x                                 0x8F1F90
#define CTabWnd__DrawTab_x                                         0x8F1D50
#define CTabWnd__GetCurrentPage_x                                  0x8F2360
#define CTabWnd__GetPageInnerRect_x                                0x8F1A40
#define CTabWnd__GetTabInnerRect_x                                 0x8F1C40
#define CTabWnd__GetTabRect_x                                      0x8F1B10
#define CTabWnd__InsertPage_x                                      0x8F2A10
#define CTabWnd__SetPage_x                                         0x8F2390
#define CTabWnd__SetPageRect_x                                     0x8F2660
#define CTabWnd__UpdatePage_x                                      0x8F29B0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431BD0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C9FE0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F78E0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AF8A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x596760
#define CXStr__CXStr1_x                                            0x440C90
#define CXStr__CXStr3_x                                            0x894400
#define CXStr__dCXStr_x                                            0x4C3FB0
#define CXStr__operator_equal_x                                    0x894570
#define CXStr__operator_equal1_x                                   0x8945C0
#define CXStr__operator_plus_equal1_x                              0x8956A0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BEAF0
#define CXWnd__Center_x                                            0x8C4CD0
#define CXWnd__ClrFocus_x                                          0x8BE6C0
#define CXWnd__DoAllDrawing_x                                      0x8C4900
#define CXWnd__DrawChildren_x                                      0x8C4AB0
#define CXWnd__DrawColoredRect_x                                   0x8BEEB0
#define CXWnd__DrawTooltip_x                                       0x8BF160
#define CXWnd__DrawTooltipAtPoint_x                                0x8C38A0
#define CXWnd__GetBorderFrame_x                                    0x8BF5C0
#define CXWnd__GetChildWndAt_x                                     0x8C5690
#define CXWnd__GetClientClipRect_x                                 0x8BF370
#define CXWnd__GetScreenClipRect_x                                 0x8C3FA0
#define CXWnd__GetScreenRect_x                                     0x8BF790
#define CXWnd__GetTooltipRect_x                                    0x8BEFF0
#define CXWnd__GetWindowTextA_x                                    0x4230B0
#define CXWnd__IsActive_x                                          0x8BA050
#define CXWnd__IsDescendantOf_x                                    0x8BF500
#define CXWnd__IsReallyVisible_x                                   0x8C28C0
#define CXWnd__IsType_x                                            0x8F4100
#define CXWnd__Move_x                                              0x8C1FB0
#define CXWnd__Move1_x                                             0x8C45B0
#define CXWnd__ProcessTransition_x                                 0x8BEA90
#define CXWnd__Refade_x                                            0x8BE870
#define CXWnd__Resize_x                                            0x8BF850
#define CXWnd__Right_x                                             0x8C3DA0
#define CXWnd__SetFocus_x                                          0x8C1140
#define CXWnd__SetFont_x                                           0x8BE710
#define CXWnd__SetKeyTooltip_x                                     0x8BFAC0
#define CXWnd__SetMouseOver_x                                      0x8C42A0
#define CXWnd__StartFade_x                                         0x8BEB40
#define CXWnd__GetChildItem_x                                      0x8C41E0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BB980
#define CXWndManager__DrawWindows_x                                0x8BB5C0
#define CXWndManager__GetKeyboardFlags_x                           0x8B9B80
#define CXWndManager__HandleKeyboardMsg_x                          0x8BA4F0
#define CXWndManager__RemoveWnd_x                                  0x8BA1E0

// CDBStr
#define CDBStr__GetString_x                                        0x4A4B10

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44F880
#define EQ_Character__Cur_HP_x                                     0x464D10
#define EQ_Character__GetAACastingTimeModifier_x                   0x447780
#define EQ_Character__GetCharInfo2_x                               0x868510
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F770
#define EQ_Character__GetFocusRangeModifier_x                      0x43F960
#define EQ_Character__Max_Endurance_x                              0x5BC180
#define EQ_Character__Max_HP_x                                     0x45A980
#define EQ_Character__Max_Mana_x                                   0x5BBFB0
#define EQ_Character__doCombatAbility_x                            0x5B95A0
#define EQ_Character__UseSkill_x                                   0x470220
#define EQ_Character__GetConLevel_x                                0x5AE230
#define EQ_Character__IsExpansionFlag_x                            0x422600
#define EQ_Character__TotalEffect_x                                0x44CB20

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58E8F0
#define EQ_Item__CreateItemTagString_x                             0x8478D0
#define EQ_Item__IsStackable_x                                     0x83BE10
#define EQ_Item__GetImageNum_x                                     0x83EB00
#define EQ_Item__CreateItemClient_x                                0x58F4D0
#define EQ_Item__GetItemValue_x                                    0x846530
#define EQ_Item__ValueSellMerchant_x                               0x848BD0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C4950
#define EQ_LoadingS__Array_x                                       0xC0DA30

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BD920
#define EQ_PC__GetAltAbilityIndex_x                                0x8509C0
#define EQ_PC__GetCombatAbility_x                                  0x850A50
#define EQ_PC__GetCombatAbilityTimer_x                             0x84B900
#define EQ_PC__GetItemTimerValue_x                                 0x5B7390
#define EQ_PC__HasLoreItem_x                                       0x5B1590
#define EQ_PC__AlertInventoryChanged_x                             0x5AE200
#define EQ_PC__GetPcZoneClient_x                                   0x5D7EB0
#define EQ_PC__RemoveMyAffect_x                                    0x5B68A0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50B1A0
#define EQItemList__add_item_x                                     0x50B0E0
#define EQItemList__delete_item_x                                  0x50B5A0
#define EQItemList__FreeItemList_x                                 0x50B4A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A3E30

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C2EB0
#define EQPlayer__dEQPlayer_x                                      0x5CBD30
#define EQPlayer__DoAttack_x                                       0x5DDDD0
#define EQPlayer__EQPlayer_x                                       0x5CE150
#define EQPlayer__SetNameSpriteState_x                             0x5C8A00
#define EQPlayer__SetNameSpriteTint_x                              0x5C42C0
#define EQPlayer__IsBodyType_j_x                                   0x924F30
#define EQPlayer__IsTargetable_x                                   0x925830
#define EQPlayer__CanSee_x                                         0x925D50

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D24C0
#define EQPlayerManager__GetSpawnByName_x                          0x5D2920

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x594A90
#define KeypressHandler__AttachKeyToEqCommand_x                    0x594AD0
#define KeypressHandler__ClearCommandStateArray_x                  0x594670
#define KeypressHandler__HandleKeyDown_x                           0x592FD0
#define KeypressHandler__HandleKeyUp_x                             0x5932F0
#define KeypressHandler__SaveKeymapping_x                          0x594740

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7063E0
#define MapViewMap__SaveEx_x                                       0x709CC0

#define PlayerPointManager__GetAltCurrency_x                       0x8634B0

// StringTable 
#define StringTable__getString_x                                   0x85DEE0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BBC30
#define PcZoneClient__RemovePetEffect_x                            0x5B75C0

//Doors
#define EQSwitch__UseSwitch_x                                      0x549B20

//IconCache
#define IconCache__GetIcon_x                                       0x6A10D0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x697F60
#define CContainerMgr__CloseContainer_x                            0x698780

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x767D10

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x587C60

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DA6E0
#define EQ_Spell__SpellAffects_x                                   0x4DA780
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DA7B0
#define CharacterZoneClient__CalcAffectChange_x                    0x448B70
#define CLootWnd__LootAll_x                                        0x6FBCD0
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x751A70
#define CTargetWnd__WndNotification_x                              0x7AD250

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B2940

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D3F30

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x4949E0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DE9D0
#define CSidlManager__FindAnimation1_x                             0x8D3720
