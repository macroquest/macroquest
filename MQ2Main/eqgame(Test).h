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
#define __ExpectedVersionDate                                     "Sep 16 2015"
#define __ExpectedVersionTime                                     "17:17:09"
#define __ActualVersionDate_x                                      0xACCA68
#define __ActualVersionTime_x                                      0xACCA74

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59ADD0
#define __MemChecker1_x                                            0x897E60
#define __MemChecker2_x                                            0x633D70
#define __MemChecker3_x                                            0x633CC0
#define __MemChecker4_x                                            0x7E9F40
#define __EncryptPad0_x                                            0xC62FE0
#define __EncryptPad1_x                                            0xDECB58
#define __EncryptPad2_x                                            0xCACAC8
#define __EncryptPad3_x                                            0xCAC6C8
#define __EncryptPad4_x                                            0xDC7240
#define __AC1_x                                                    0x7A6C45
#define __AC2_x                                                    0x550357
#define __AC3_x                                                    0x564B50
#define __AC4_x                                                    0x56B7D0
#define __AC5_x                                                    0x57764E
#define __AC6_x                                                    0x57B0F9
#define __AC7_x                                                    0x571CFC
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
#define __do_loot_x                                                0x517890
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
#define __CastRay_x                                                0x52F3B0
#define __ConvertItemTags_x                                        0x51C510
#define __ExecuteCmd_x                                             0x507010
#define __EQGetTime_x                                              0x8981C0
#define __get_melee_range_x                                        0x50DCD0
#define __GetGaugeValueFromEQ_x                                    0x7A5980
#define __GetLabelFromEQ_x                                         0x7A6BD0
#define __ToggleMount_x                                            0x6CEAF0
#define __GetXTargetType_x                                         0x928E50
#define __LoadFrontEnd_x                                           0x633420
#define __NewUIINI_x                                               0x7A5280
#define __ProcessGameEvents_x                                      0x573A60
#define __ProcessMouseEvent_x                                      0x573200
#define CrashDetected_x                                            0x634EF0
#define wwsCrashReportCheckForUploader_x                           0x7F9570
#define DrawNetStatus_x                                            0x5AA7F0
#define Util__FastTime_x                                           0x897B10
#define Expansion_HoT_x                                            0x100825C
#define __HelpPath_x                                               0x108B9C8
//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F020
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419E70

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C2FE0
#define AltAdvManager__IsAbilityReady_x                            0x4C3050
#define AltAdvManager__GetAltAbility_x                             0x4C3410

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x466070
#define CharacterZoneClient__MakeMeVisible_x                       0x46BA50
#define CharacterZoneClient__IsStackBlocked_x                      0x447E60

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x662EB0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x671290

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x589E10

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68C380
#define CChatManager__InitContextMenu_x                            0x68CF00

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DAC10
#define CContextMenu__AddMenuItem_x                                0x8DAE30
#define CContextMenu__dCContextMenu_x                              0x8DAE20
#define CContextMenu__RemoveMenuItem_x                             0x8DB120
#define CContextMenu__RemoveAllMenuItems_x                         0x8DB140
#define CContextMenuManager__AddMenu_x                             0x8C6B80
#define CContextMenuManager__RemoveMenu_x                          0x8C6EB0
#define CContextMenuManager__PopupMenu_x                           0x8C7300
#define CContextMenuManager__Flush_x                               0x8C6BF0
#define CContextMenuManager__GetMenu_x                             0x4154A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87E130
#define CChatService__GetFriendName_x                              0x87E140

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6921B0
#define CChatWindow__Clear_x                                       0x691D60
#define CChatWindow__WndNotification_x                             0x6926E0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CAA60
#define CComboWnd__Draw_x                                          0x8CAC70
#define CComboWnd__GetCurChoice_x                                  0x8CA830
#define CComboWnd__GetListRect_x                                   0x8CAF10
#define CComboWnd__GetTextRect_x                                   0x8CAAD0
#define CComboWnd__InsertChoice_x                                  0x8CAF80
#define CComboWnd__SetColors_x                                     0x8CA7C0
#define CComboWnd__SetChoice_x                                     0x8CA7F0
#define CComboWnd__GetItemCount_x                                  0x8CA820

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69B8F0
#define CContainerWnd__vftable_x                                   0xAD6400

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B12C0
#define CDisplay__GetClickedActor_x                                0x4A9E40
#define CDisplay__GetUserDefinedColor_x                            0x4A8700
#define CDisplay__GetWorldFilePath_x                               0x4A7B50
#define CDisplay__is3dON_x                                         0x4A6F20
#define CDisplay__ReloadUI_x                                       0x4BC7E0
#define CDisplay__WriteTextHD2_x                                   0x4AD660

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F1220

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DF5B0
#define CEditWnd__GetCharIndexPt_x                                 0x8E0650
#define CEditWnd__GetDisplayString_x                               0x8DF760
#define CEditWnd__GetHorzOffset_x                                  0x8DFAA0
#define CEditWnd__GetLineForPrintableChar_x                        0x8E0110
#define CEditWnd__GetSelStartPt_x                                  0x8E0910
#define CEditWnd__GetSTMLSafeText_x                                0x8DFC40
#define CEditWnd__PointFromPrintableChar_x                         0x8E0200
#define CEditWnd__SelectableCharFromPoint_x                        0x8E0380
#define CEditWnd__SetEditable_x                                    0x8DFC10

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x550AA0
#define CEverQuest__DoTellWindow_x                                 0x5564A0
#define CEverQuest__DropHeldItemOnGround_x                         0x55EFD0
#define CEverQuest__dsp_chat_x                                     0x557C40
#define CEverQuest__Emote_x                                        0x557EA0
#define CEverQuest__EnterZone_x                                    0x56BFF0
#define CEverQuest__GetBodyTypeDesc_x                              0x54D300
#define CEverQuest__GetClassDesc_x                                 0x553010
#define CEverQuest__GetClassThreeLetterCode_x                      0x553610
#define CEverQuest__GetDeityDesc_x                                 0x54DBE0
#define CEverQuest__GetLangDesc_x                                  0x54D690
#define CEverQuest__GetRaceDesc_x                                  0x5537D0
#define CEverQuest__InterpretCmd_x                                 0x558780
#define CEverQuest__LeftClickedOnPlayer_x                          0x570160
#define CEverQuest__LMouseUp_x                                     0x572250
#define CEverQuest__RightClickedOnPlayer_x                         0x570C60
#define CEverQuest__RMouseUp_x                                     0x571CB0
#define CEverQuest__SetGameState_x                                 0x551150
#define CEverQuest__UPCNotificationFlush_x                         0x559920
#define CEverQuest__IssuePetCommand_x                              0x559480

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AC460
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AC4C0
#define CGaugeWnd__Draw_x                                          0x6AC8F0

// CGuild
#define CGuild__FindMemberByName_x                                 0x436080

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C9520

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D7350
#define CInvSlotMgr__MoveItem_x                                    0x6D8290
#define CInvSlotMgr__SelectSlot_x                                  0x6D7400

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D67E0
#define CInvSlot__SliderComplete_x                                 0x6D41A0
#define CInvSlot__GetItemBase_x                                    0x6D3610

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D9410

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A2300
#define CItemDisplayWnd__UpdateStrings_x                           0x6DA750

// CLabel 
#define CLabel__Draw_x                                             0x6F54C0

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8B6A30
#define CListWnd__dCListWnd_x                                      0x8B7A60
#define CListWnd__AddColumn_x                                      0x8B7A00
#define CListWnd__AddColumn1_x                                     0x8B7270
#define CListWnd__AddLine_x                                        0x8B6CF0
#define CListWnd__AddString_x                                      0x8B6F00
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B3D70
#define CListWnd__CalculateVSBRange_x                              0x8B5EE0
#define CListWnd__ClearAllSel_x                                    0x8B3030
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B68C0
#define CListWnd__Compare_x                                        0x8B4870
#define CListWnd__Draw_x                                           0x8B5AF0
#define CListWnd__DrawColumnSeparators_x                           0x8B5980
#define CListWnd__DrawHeader_x                                     0x8B3340
#define CListWnd__DrawItem_x                                       0x8B4EB0
#define CListWnd__DrawLine_x                                       0x8B5620
#define CListWnd__DrawSeparator_x                                  0x8B5A20
#define CListWnd__EnsureVisible_x                                  0x8B3ED0
#define CListWnd__ExtendSel_x                                      0x8B4DC0
#define CListWnd__GetColumnMinWidth_x                              0x8B29F0
#define CListWnd__GetColumnWidth_x                                 0x8B2910
#define CListWnd__GetCurSel_x                                      0x8B20E0
#define CListWnd__GetItemAtPoint_x                                 0x8B4170
#define CListWnd__GetItemAtPoint1_x                                0x8B41E0
#define CListWnd__GetItemData_x                                    0x8B2420
#define CListWnd__GetItemHeight_x                                  0x8B39D0
#define CListWnd__GetItemIcon_x                                    0x8B2600
#define CListWnd__GetItemRect_x                                    0x8B3FB0
#define CListWnd__GetItemText_x                                    0x8B24B0
#define CListWnd__GetSelList_x                                     0x8B7160
#define CListWnd__GetSeparatorRect_x                               0x8B47A0
#define CListWnd__RemoveLine_x                                     0x8B70E0
#define CListWnd__SetColors_x                                      0x8B2230
#define CListWnd__SetColumnJustification_x                         0x8B2CC0
#define CListWnd__SetColumnWidth_x                                 0x8B29A0
#define CListWnd__SetCurSel_x                                      0x8B2120
#define CListWnd__SetItemColor_x                                   0x8B65A0
#define CListWnd__SetItemData_x                                    0x8B30E0
#define CListWnd__SetItemText_x                                    0x8B63E0
#define CListWnd__ShiftColumnSeparator_x                           0x8B6270
#define CListWnd__Sort_x                                           0x8B7B60
#define CListWnd__ToggleSel_x                                      0x8B2FB0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70E8F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72FC10
#define CMerchantWnd__RequestBuyItem_x                             0x736A40
#define CMerchantWnd__RequestSellItem_x                            0x737490
#define CMerchantWnd__SelectRecoverySlot_x                         0x72FEC0
#define CMerchantWnd__SelectBuySellSlot_x                          0x72F120
#define CMerchantWnd__ActualSelect_x                               0x733970

// CObfuscator
#define CObfuscator__doit_x                                        0x85E450

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D5B90
#define CSidlManager__CreateLabel_x                                0x798330

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65A150
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65A070
#define CSidlScreenWnd__ConvertToRes_x                             0x8F1100
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CD6E0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CEBD0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CEC80
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CE140
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CD090
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CC7F0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CD280
#define CSidlScreenWnd__Init1_x                                    0x8CE8A0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CD790
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CC9B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CE390
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CC2B0
#define CSidlScreenWnd__StoreIniVis_x                              0x8CC780
#define CSidlScreenWnd__WndNotification_x                          0x8CE620
#define CSidlScreenWnd__GetChildItem_x                             0x8CC8C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BFFA0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F5310
#define CSkillMgr__GetSkillCap_x                                   0x5F54D0
#define CSkillMgr__GetNameToken_x                                  0x5F4F30

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F03C0
#define CSliderWnd__SetValue_x                                     0x8F0590
#define CSliderWnd__SetNumTicks_x                                  0x8F0D10

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79FFB0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EADC0
#define CStmlWnd__CalculateHSBRange_x                              0x8E3300
#define CStmlWnd__CalculateVSBRange_x                              0x8E3390
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E3510
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E3DF0
#define CStmlWnd__ForceParseNow_x                                  0x8EB710
#define CStmlWnd__GetNextTagPiece_x                                0x8E3CF0
#define CStmlWnd__GetSTMLText_x                                    0x691600
#define CStmlWnd__GetVisibleText_x                                 0x8E4840
#define CStmlWnd__InitializeWindowVariables_x                      0x8E6BB0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E2600
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E2660
#define CStmlWnd__SetSTMLText_x                                    0x8E8410
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EAA60
#define CStmlWnd__UpdateHistoryString_x                            0x8E5770

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F2900
#define CTabWnd__DrawCurrentPage_x                                 0x8F2170
#define CTabWnd__DrawTab_x                                         0x8F1F30
#define CTabWnd__GetCurrentPage_x                                  0x8F2540
#define CTabWnd__GetPageInnerRect_x                                0x8F1C20
#define CTabWnd__GetTabInnerRect_x                                 0x8F1E20
#define CTabWnd__GetTabRect_x                                      0x8F1CF0
#define CTabWnd__InsertPage_x                                      0x8F2BF0
#define CTabWnd__SetPage_x                                         0x8F2570
#define CTabWnd__SetPageRect_x                                     0x8F2840
#define CTabWnd__UpdatePage_x                                      0x8F2B90

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431DD0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CA430

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F7B60

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B0240

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402290
#define CXStr__CXStr1_x                                            0x4DF040
#define CXStr__CXStr3_x                                            0x894BA0
#define CXStr__dCXStr_x                                            0x5976E0
#define CXStr__operator_equal_x                                    0x894D10
#define CXStr__operator_equal1_x                                   0x894D60
#define CXStr__operator_plus_equal1_x                              0x895E40

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BF220
#define CXWnd__Center_x                                            0x8C51A0
#define CXWnd__ClrFocus_x                                          0x8BEDE0
#define CXWnd__DoAllDrawing_x                                      0x8C4E00
#define CXWnd__DrawChildren_x                                      0x8C4FA0
#define CXWnd__DrawColoredRect_x                                   0x8BF5E0
#define CXWnd__DrawTooltip_x                                       0x8BF880
#define CXWnd__DrawTooltipAtPoint_x                                0x8C3D90
#define CXWnd__GetBorderFrame_x                                    0x8BFCE0
#define CXWnd__GetChildWndAt_x                                     0x8C5B50
#define CXWnd__GetClientClipRect_x                                 0x8BFAA0
#define CXWnd__GetScreenClipRect_x                                 0x8C4490
#define CXWnd__GetScreenRect_x                                     0x8BFE60
#define CXWnd__GetTooltipRect_x                                    0x8BF710
#define CXWnd__GetWindowTextA_x                                    0x423050
#define CXWnd__IsActive_x                                          0x8BA840
#define CXWnd__IsDescendantOf_x                                    0x8BFC30
#define CXWnd__IsReallyVisible_x                                   0x8C2E20
#define CXWnd__IsType_x                                            0x8F42F0
#define CXWnd__Move_x                                              0x8C25D0
#define CXWnd__Move1_x                                             0x8C4AE0
#define CXWnd__ProcessTransition_x                                 0x8BF1C0
#define CXWnd__Refade_x                                            0x8BEF90
#define CXWnd__Resize_x                                            0x8BFF10
#define CXWnd__Right_x                                             0x8C4290
#define CXWnd__SetFocus_x                                          0x8C1730
#define CXWnd__SetFont_x                                           0x8BEE30
#define CXWnd__SetKeyTooltip_x                                     0x8C0170
#define CXWnd__SetMouseOver_x                                      0x8C47D0
#define CXWnd__StartFade_x                                         0x8BF270
#define CXWnd__GetChildItem_x                                      0x8C4710

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BC170
#define CXWndManager__DrawWindows_x                                0x8BBDC0
#define CXWndManager__GetKeyboardFlags_x                           0x8BA3B0
#define CXWndManager__HandleKeyboardMsg_x                          0x8BACE0
#define CXWndManager__RemoveWnd_x                                  0x8BA9D0

// CDBStr
#define CDBStr__GetString_x                                        0x4A54C0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x450030
#define EQ_Character__Cur_HP_x                                     0x465740
#define EQ_Character__GetAACastingTimeModifier_x                   0x4479E0
#define EQ_Character__GetCharInfo2_x                               0x868D60
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F9C0
#define EQ_Character__GetFocusRangeModifier_x                      0x43FBB0
#define EQ_Character__Max_Endurance_x                              0x5BC820
#define EQ_Character__Max_HP_x                                     0x45B3B0
#define EQ_Character__Max_Mana_x                                   0x5BC650
#define EQ_Character__doCombatAbility_x                            0x5B9C30
#define EQ_Character__UseSkill_x                                   0x470C50
#define EQ_Character__GetConLevel_x                                0x5AEDD0
#define EQ_Character__IsExpansionFlag_x                            0x422590
#define EQ_Character__TotalEffect_x                                0x44CD60

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58F5D0
#define EQ_Item__CreateItemTagString_x                             0x8481A0
#define EQ_Item__IsStackable_x                                     0x83C700
#define EQ_Item__GetImageNum_x                                     0x83F400
#define EQ_Item__CreateItemClient_x                                0x5901C0
#define EQ_Item__GetItemValue_x                                    0x846E80
#define EQ_Item__ValueSellMerchant_x                               0x8494A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C5150
#define EQ_LoadingS__Array_x                                       0xC0DA30

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BDFC0
#define EQ_PC__GetAltAbilityIndex_x                                0x8511D0
#define EQ_PC__GetCombatAbility_x                                  0x851260
#define EQ_PC__GetCombatAbilityTimer_x                             0x84C210
#define EQ_PC__GetItemTimerValue_x                                 0x5B7A00
#define EQ_PC__HasLoreItem_x                                       0x5B2120
#define EQ_PC__AlertInventoryChanged_x                             0x5AEDA0
#define EQ_PC__GetPcZoneClient_x                                   0x5D8600
#define EQ_PC__RemoveMyAffect_x                                    0x5B6F10

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50BD30
#define EQItemList__add_item_x                                     0x50BC70
#define EQItemList__delete_item_x                                  0x50C130
#define EQItemList__FreeItemList_x                                 0x50C030

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A46E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C3570
#define EQPlayer__dEQPlayer_x                                      0x5CC3F0
#define EQPlayer__DoAttack_x                                       0x5DE520
#define EQPlayer__EQPlayer_x                                       0x5CE810
#define EQPlayer__SetNameSpriteState_x                             0x5C90C0
#define EQPlayer__SetNameSpriteTint_x                              0x5C4980
#define EQPlayer__IsBodyType_j_x                                   0x925060
#define EQPlayer__IsTargetable_x                                   0x925920
#define EQPlayer__CanSee_x                                         0x925E40

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D2B70
#define EQPlayerManager__GetSpawnByName_x                          0x5D2FD0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5956C0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x595700
#define KeypressHandler__ClearCommandStateArray_x                  0x5952A0
#define KeypressHandler__HandleKeyDown_x                           0x593C00
#define KeypressHandler__HandleKeyUp_x                             0x593F20
#define KeypressHandler__SaveKeymapping_x                          0x595370

// MapViewMap 
#define MapViewMap__Clear_x                                        0x706CD0
#define MapViewMap__SaveEx_x                                       0x70A5B0

#define PlayerPointManager__GetAltCurrency_x                       0x863C50

// StringTable 
#define StringTable__getString_x                                   0x85E6F0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BC2D0
#define PcZoneClient__RemovePetEffect_x                            0x5B7C30

//Doors
#define EQSwitch__UseSwitch_x                                      0x54A660

//IconCache
#define IconCache__GetIcon_x                                       0x6A1D40

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x698BE0
#define CContainerMgr__CloseContainer_x                            0x699400

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7684D0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5888D0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DADC0
#define EQ_Spell__SpellAffects_x                                   0x4DAE60
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DAE90
#define CharacterZoneClient__CalcAffectChange_x                    0x448DD0
#define CLootWnd__LootAll_x                                        0x6FC660
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7523B0
#define CTargetWnd__WndNotification_x                              0x7ADA10

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B3100

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D4630

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x495340

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DEBE0
#define CSidlManager__FindAnimation1_x                             0x8D3A90
