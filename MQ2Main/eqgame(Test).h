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
#define __ExpectedVersionDate                                     "Aug 25 2015"
#define __ExpectedVersionTime                                     "15:50:26"
#define __ActualVersionDate_x                                      0xA84478
#define __ActualVersionTime_x                                      0xA84484

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x597DA0
#define __MemChecker1_x                                            0x8947E0
#define __MemChecker2_x                                            0x62E530
#define __MemChecker3_x                                            0x62E480
#define __MemChecker4_x                                            0x7E3FE0
#define __EncryptPad0_x                                            0xC045D0
#define __EncryptPad1_x                                            0xD8D8D0
#define __EncryptPad2_x                                            0xC4DF18
#define __EncryptPad3_x                                            0xC4DB18
#define __EncryptPad4_x                                            0xD68060
#define __AC1_x                                                    0x7A1475
#define __AC2_x                                                    0x54D317
#define __AC3_x                                                    0x561B10
#define __AC4_x                                                    0x568780
#define __AC5_x                                                    0x57460E
#define __AC6_x                                                    0x5780A9
#define __AC7_x                                                    0x56ECBC
#define __AC1_Data                                                 0x11111111

// Direct Input
#define DI8__Main_x                                                0x11402A8
#define DI8__Keyboard_x                                            0x11402AC
#define DI8__Mouse_x                                               0x11402B0
#define DI8__Mouse_Copy_x                                          0xFAE8C4
#define DI8__Mouse_Check_x                                         0x1038194
#define __AltTimerReady_x                                          0xF9FC11
#define __Attack_x                                                 0x1032E33
#define __Autofire_x                                               0x1032E34
#define __BindList_x                                               0xBC6828
#define __bCommandEnabled_x                                        0xF9DD20
#define __Clicks_x                                                 0xFAE980
#define __CommandList_x                                            0xBCAB80
#define __CurrentMapLabel_x                                        0x1145D00
#define __CurrentSocial_x                                          0xB81E7C
#define __DoAbilityList_x                                          0xFE50E8
#define __do_loot_x                                                0x514840
#define __DrawHandler_x                                            0x17ACA1C
#define __GroupCount_x                                             0xF9F2EA

#define __Guilds_x                                                 0xFA4F00
#define __gWorld_x                                                 0xFA17A4
#define __HotkeyPage_x                                             0x102BAE8
#define __HWnd_x                                                   0x10381B0
#define __InChatMode_x                                             0xFAE8AC
#define __LastTell_x                                               0xFB07F0
#define __LMouseHeldTime_x                                         0xFAE9EC
#define __Mouse_x                                                  0x11402B4
#define __MouseLook_x                                              0xFAE946
#define __MouseEventTime_x                                         0x103363C
#define __gpbCommandEvent_x                                        0xFA186C
#define __NetStatusToggle_x                                        0xFAE949
#define __PCNames_x                                                0xFAFE10
#define __RangeAttackReady_x                                       0xFAFAD0
#define __RMouseHeldTime_x                                         0xFAE9E8
#define __RunWalkState_x                                           0xFAE8B0
#define __ScreenMode_x                                             0xEEDB50
#define __ScreenX_x                                                0xFAE864
#define __ScreenY_x                                                0xFAE860
#define __ScreenXMax_x                                             0xFAE868
#define __ScreenYMax_x                                             0xFAE86C
#define __ServerHost_x                                             0xF9F234
#define __ServerName_x                                             0xFE50A8
#define __ShiftKeyDown_x                                           0xFAEF54
#define __ShowNames_x                                              0xFAFCA4
#define __Socials_x                                                0xFE51A8
#define __SubscriptionType_x                                       0x1174200
#define __TargetAggroHolder_x                                      0x1147F3C
#define __GroupAggro_x                                             0x1147F7C
#define __LoginName_x                                              0x1036D88
#define __Inviter_x                                                0x1032DB0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xFA1890
#define instEQZoneInfo_x                                           0xFAEB3C
#define instKeypressHandler_x                                      0x1033620
#define pinstActiveBanker_x                                        0xFA1848
#define pinstActiveCorpse_x                                        0xFA184C
#define pinstActiveGMaster_x                                       0xFA1850
#define pinstActiveMerchant_x                                      0xFA1844
#define pinstAggroInfo_x                                           0xDAFF98
#define pinstAltAdvManager_x                                       0xEEEC48
#define pinstAuraMgr_x                                             0xDBBE98
#define pinstBandageTarget_x                                       0xFA1830
#define pinstCamActor_x                                            0xEEE554
#define pinstCDBStr_x                                              0xEEDAE4
#define pinstCDisplay_x                                            0xFA1858
#define pinstCEverQuest_x                                          0x1140428
#define pinstCharData_x                                            0xFA1814
#define pinstCharSpawn_x                                           0xFA183C
#define pinstControlledMissile_x                                   0xFA1810
#define pinstControlledPlayer_x                                    0xFA183C
#define pinstCSidlManager_x                                        0x17ABE54
#define pinstCXWndManager_x                                        0x17ABE4C
#define instDynamicZone_x                                          0xFAE6F8
#define pinstDZMember_x                                            0xFAE808
#define pinstDZTimerInfo_x                                         0xFAE80C
#define pinstEQItemList_x                                          0xF9DF70
#define instEQMisc_x                                               0xBA2AC0
#define pinstEQSoundManager_x                                      0xEEF0B8
#define instExpeditionLeader_x                                     0xFAE742
#define instExpeditionName_x                                       0xFAE782
#define pinstGroup_x                                               0xF9F2E6
#define pinstImeManager_x                                          0x17ABE58
#define pinstLocalPlayer_x                                         0xFA1828
#define pinstMercenaryData_x                                       0x1033C70
#define pinstMercenaryStats_x                                      0x1148088
#define pinstMercAltAbilities_x                                    0xEEEFD4
#define pinstModelPlayer_x                                         0xFA1854
#define pinstPCData_x                                              0xFA1814
#define pinstSkillMgr_x                                            0x1034AA8
#define pinstSpawnManager_x                                        0x1034390
#define pinstSpellManager_x                                        0x1034BF0
#define pinstSpellSets_x                                           0x102BB4C
#define pinstStringTable_x                                         0xFA17BC
#define pinstSwitchManager_x                                       0xF9EE78
#define pinstTarget_x                                              0xFA1840
#define pinstTargetObject_x                                        0xFA1818
#define pinstTargetSwitch_x                                        0xFA181C
#define pinstTaskMember_x                                          0xEEDA30
#define pinstTrackTarget_x                                         0xFA1834
#define pinstTradeTarget_x                                         0xFA1824
#define instTributeActive_x                                        0xBA2AE5
#define pinstViewActor_x                                           0xEEE550
#define pinstWorldData_x                                           0xFA17F8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xDB0478
#define pinstCAudioTriggersWindow_x                                0xDB0308
#define pinstCCharacterSelect_x                                    0xEEE3F0
#define pinstCFacePick_x                                           0xEEE3A0
#define pinstCNoteWnd_x                                            0xEEE3A8
#define pinstCBookWnd_x                                            0xEEE3B0
#define pinstCPetInfoWnd_x                                         0xEEE3B4
#define pinstCTrainWnd_x                                           0xEEE3B8
#define pinstCSkillsWnd_x                                          0xEEE3BC
#define pinstCSkillsSelectWnd_x                                    0xEEE3C0
#define pinstCCombatSkillsSelectWnd_x                              0xEEE3C4
#define pinstCFriendsWnd_x                                         0xEEE3C8
#define pinstCAuraWnd_x                                            0xEEE3CC
#define pinstCRespawnWnd_x                                         0xEEE3D0
#define pinstCBandolierWnd_x                                       0xEEE3D4
#define pinstCPotionBeltWnd_x                                      0xEEE3D8
#define pinstCAAWnd_x                                              0xEEE3DC
#define pinstCGroupSearchFiltersWnd_x                              0xEEE3E0
#define pinstCLoadskinWnd_x                                        0xEEE3E4
#define pinstCAlarmWnd_x                                           0xEEE3E8
#define pinstCMusicPlayerWnd_x                                     0xEEE3EC
#define pinstCMailWnd_x                                            0xEEE3F4
#define pinstCMailCompositionWnd_x                                 0xEEE3F8
#define pinstCMailAddressBookWnd_x                                 0xEEE3FC
#define pinstCRaidWnd_x                                            0xEEE404
#define pinstCRaidOptionsWnd_x                                     0xEEE408
#define pinstCBreathWnd_x                                          0xEEE40C
#define pinstCMapViewWnd_x                                         0xEEE410
#define pinstCMapToolbarWnd_x                                      0xEEE414
#define pinstCEditLabelWnd_x                                       0xEEE418
#define pinstCTargetWnd_x                                          0xEEE41C
#define pinstCColorPickerWnd_x                                     0xEEE420
#define pinstCPlayerWnd_x                                          0xEEE424
#define pinstCOptionsWnd_x                                         0xEEE428
#define pinstCBuffWindowNORMAL_x                                   0xEEE42C
#define pinstCBuffWindowSHORT_x                                    0xEEE430
#define pinstCharacterCreation_x                                   0xEEE434
#define pinstCCursorAttachment_x                                   0xEEE438
#define pinstCCastingWnd_x                                         0xEEE43C
#define pinstCCastSpellWnd_x                                       0xEEE440
#define pinstCSpellBookWnd_x                                       0xEEE444
#define pinstCInventoryWnd_x                                       0xEEE448
#define pinstCBankWnd_x                                            0xEEE44C
#define pinstCQuantityWnd_x                                        0xEEE450
#define pinstCLootWnd_x                                            0xEEE454
#define pinstCActionsWnd_x                                         0xEEE458
#define pinstCCombatAbilityWnd_x                                   0xEEE45C
#define pinstCMerchantWnd_x                                        0xEEE460
#define pinstCTradeWnd_x                                           0xEEE464
#define pinstCSelectorWnd_x                                        0xEEE468
#define pinstCBazaarWnd_x                                          0xEEE46C
#define pinstCBazaarSearchWnd_x                                    0xEEE470
#define pinstCGiveWnd_x                                            0xEEE48C
#define pinstCTrackingWnd_x                                        0xEEE494
#define pinstCInspectWnd_x                                         0xEEE498
#define pinstCSocialEditWnd_x                                      0xEEE49C
#define pinstCFeedbackWnd_x                                        0xEEE4A0
#define pinstCBugReportWnd_x                                       0xEEE4A4
#define pinstCVideoModesWnd_x                                      0xEEE4A8
#define pinstCTextEntryWnd_x                                       0xEEE4B0
#define pinstCFileSelectionWnd_x                                   0xEEE4B4
#define pinstCCompassWnd_x                                         0xEEE4B8
#define pinstCPlayerNotesWnd_x                                     0xEEE4BC
#define pinstCGemsGameWnd_x                                        0xEEE4C0
#define pinstCTimeLeftWnd_x                                        0xEEE4C4
#define pinstCPetitionQWnd_x                                       0xEEE4D8
#define pinstCSoulmarkWnd_x                                        0xEEE4DC
#define pinstCStoryWnd_x                                           0xEEE4E0
#define pinstCJournalTextWnd_x                                     0xEEE4E4
#define pinstCJournalCatWnd_x                                      0xEEE4E8
#define pinstCBodyTintWnd_x                                        0xEEE4EC
#define pinstCServerListWnd_x                                      0xEEE4F0
#define pinstCAvaZoneWnd_x                                         0xEEE4FC
#define pinstCBlockedBuffWnd_x                                     0xEEE500
#define pinstCBlockedPetBuffWnd_x                                  0xEEE504
#define pinstCInvSlotMgr_x                                         0xEEE548
#define pinstCContainerMgr_x                                       0xEEE54C
#define pinstCAdventureLeaderboardWnd_x                            0x1140DD8
#define pinstCAdventureRequestWnd_x                                0x1140E50
#define pinstCAltStorageWnd_x                                      0x1141130
#define pinstCAdventureStatsWnd_x                                  0x1140EC8
#define pinstCBarterMerchantWnd_x                                  0x1141D18
#define pinstCBarterSearchWnd_x                                    0x1141D90
#define pinstCBarterWnd_x                                          0x1141E08
#define pinstCChatManager_x                                        0x1142498
#define pinstCDynamicZoneWnd_x                                     0x1142948
#define pinstCEQMainWnd_x                                          0x1142AE0
#define pinstCFellowshipWnd_x                                      0x11428DC
#define pinstCFindLocationWnd_x                                    0x1142DB0
#define pinstCGroupSearchWnd_x                                     0x1143080
#define pinstCGroupWnd_x                                           0x11430F8
#define pinstCGuildBankWnd_x                                       0x1143170
#define pinstCGuildMgmtWnd_x                                       0x1145260
#define pinstCHotButtonWnd_x                                       0x114532C
#define pinstCHotButtonWnd1_x                                      0x114532C
#define pinstCHotButtonWnd2_x                                      0x1145330
#define pinstCHotButtonWnd3_x                                      0x1145334
#define pinstCHotButtonWnd4_x                                      0x1145358
#define pinstCItemDisplayManager_x                                 0x1145650
#define pinstCItemExpTransferWnd_x                                 0x11456CC
#define pinstCLFGuildWnd_x                                         0x11459A8
#define pinstCMIZoneSelectWnd_x                                    0x1145F90
#define pinstCConfirmationDialog_x                                 0x1146698
#define pinstCPopupWndManager_x                                    0x1146698
#define pinstCProgressionSelectionWnd_x                            0x1146788
#define pinstCPvPStatsWnd_x                                        0x1146878
#define pinstCSystemInfoDialogBox_x                                0x1146F80
#define pinstCTaskWnd_x                                            0x1148348
#define pinstCTaskSomething_x                                      0xDBC5D8
#define pinstCTaskTemplateSelectWnd_x                              0x11482D0
#define pinstCTipWndOFDAY_x                                        0x11485A0
#define pinstCTipWndCONTEXT_x                                      0x11485A4
#define pinstCTitleWnd_x                                           0x1148620
#define pinstCContextMenuManager_x                                 0x17ABDC4
#define pinstCVoiceMacroWnd_x                                      0x1035258
#define pinstCHtmlWnd_x                                            0x1035350
#define pinstIconCache_x                                           0x1142AB4
#define pinstCTradeskillWnd_x                                      0x1148720
#define pinstCAdvancedLootWnd_x                                    0xEEE53C
#define pinstRewardSelectionWnd_x                                  0x1146DA0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x52C370
#define __ConvertItemTags_x                                        0x5194C0
#define __ExecuteCmd_x                                             0x503FD0
#define __EQGetTime_x                                              0x894B40
#define __get_melee_range_x                                        0x50ACA0
#define __GetGaugeValueFromEQ_x                                    0x7A01B0
#define __GetLabelFromEQ_x                                         0x7A1400
#define __ToggleMount_x                                            0x6C8F50
#define __GetXTargetType_x                                         0x925990
#define __LoadFrontEnd_x                                           0x62DBE0
#define __NewUIINI_x                                               0x79FAC0
#define __ProcessGameEvents_x                                      0x570A20
#define __ProcessMouseEvent_x                                      0x5701C0
#define CrashDetected_x                                            0x62F6B0
#define wwsCrashReportCheckForUploader_x                           0x7F5D10
#define DrawNetStatus_x                                            0x5A7670
#define Util__FastTime_x                                           0x894650
#define Expansion_HoT_x                                            0xFAFC3C
#define __HelpPath_x                                               0x10333A8
//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41EFA0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419DF0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C2B50
#define AltAdvManager__IsAbilityReady_x                            0x4C2BC0
#define AltAdvManager__GetAltAbility_x                             0x4C2F80

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465B00
#define CharacterZoneClient__MakeMeVisible_x                       0x46B530

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x65D560

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66B9C0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x586D50

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x686850
#define CChatManager__InitContextMenu_x                            0x6873D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D7860
#define CContextMenu__AddMenuItem_x                                0x8D7A80
#define CContextMenu__dCContextMenu_x                              0x8D7A70
#define CContextMenu__RemoveMenuItem_x                             0x8D7D60
#define CContextMenu__RemoveAllMenuItems_x                         0x8D7D80
#define CContextMenuManager__AddMenu_x                             0x8C37E0
#define CContextMenuManager__RemoveMenu_x                          0x8C3B30
#define CContextMenuManager__PopupMenu_x                           0x8C3F80
#define CContextMenuManager__Flush_x                               0x8C3850
#define CContextMenuManager__GetMenu_x                             0x415430

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87AA00
#define CChatService__GetFriendName_x                              0x87AA10

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68C670
#define CChatWindow__Clear_x                                       0x68C230
#define CChatWindow__WndNotification_x                             0x68CBA0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C76E0
#define CComboWnd__Draw_x                                          0x8C78F0
#define CComboWnd__GetCurChoice_x                                  0x8C74B0
#define CComboWnd__GetListRect_x                                   0x8C7B90
#define CComboWnd__GetTextRect_x                                   0x8C7750
#define CComboWnd__InsertChoice_x                                  0x8C7C00
#define CComboWnd__SetColors_x                                     0x8C7440
#define CComboWnd__SetChoice_x                                     0x8C7470
#define CComboWnd__GetItemCount_x                                  0x8C74A0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x695DA0
#define CContainerWnd__vftable_x                                   0xA8DE20

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B0DE0
#define CDisplay__GetClickedActor_x                                0x4A9960
#define CDisplay__GetUserDefinedColor_x                            0x4A8220
#define CDisplay__GetWorldFilePath_x                               0x4A7670
#define CDisplay__is3dON_x                                         0x4A6A40
#define CDisplay__ReloadUI_x                                       0x4BC2B0
#define CDisplay__WriteTextHD2_x                                   0x4AD180

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EDDB0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DC1A0
#define CEditWnd__GetCharIndexPt_x                                 0x8DD220
#define CEditWnd__GetDisplayString_x                               0x8DC350
#define CEditWnd__GetHorzOffset_x                                  0x8DC690
#define CEditWnd__GetLineForPrintableChar_x                        0x8DCCF0
#define CEditWnd__GetSelStartPt_x                                  0x8DD4D0
#define CEditWnd__GetSTMLSafeText_x                                0x8DC820
#define CEditWnd__PointFromPrintableChar_x                         0x8DCDE0
#define CEditWnd__SelectableCharFromPoint_x                        0x8DCF60
#define CEditWnd__SetEditable_x                                    0x8DC7F0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54DA60
#define CEverQuest__DoTellWindow_x                                 0x553460
#define CEverQuest__DropHeldItemOnGround_x                         0x55BF90
#define CEverQuest__dsp_chat_x                                     0x554C00
#define CEverQuest__Emote_x                                        0x554E60
#define CEverQuest__EnterZone_x                                    0x568FA0
#define CEverQuest__GetBodyTypeDesc_x                              0x54A2C0
#define CEverQuest__GetClassDesc_x                                 0x54FFD0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5505D0
#define CEverQuest__GetDeityDesc_x                                 0x54ABA0
#define CEverQuest__GetLangDesc_x                                  0x54A650
#define CEverQuest__GetRaceDesc_x                                  0x550790
#define CEverQuest__InterpretCmd_x                                 0x555740
#define CEverQuest__LeftClickedOnPlayer_x                          0x56D120
#define CEverQuest__LMouseUp_x                                     0x56F210
#define CEverQuest__RightClickedOnPlayer_x                         0x56DC20
#define CEverQuest__RMouseUp_x                                     0x56EC70
#define CEverQuest__SetGameState_x                                 0x54E110
#define CEverQuest__UPCNotificationFlush_x                         0x5568E0
#define CEverQuest__IssuePetCommand_x                              0x556440

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A6890
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A68F0
#define CGaugeWnd__Draw_x                                          0x6A6D20

// CGuild
#define CGuild__FindMemberByName_x                                 0x435F80

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C3980

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D17A0
#define CInvSlotMgr__MoveItem_x                                    0x6D26D0
#define CInvSlotMgr__SelectSlot_x                                  0x6D1850

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D0C30
#define CInvSlot__SliderComplete_x                                 0x6CE5F0
#define CInvSlot__GetItemBase_x                                    0x6CDA70

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D3890

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79CB40
#define CItemDisplayWnd__UpdateStrings_x                           0x6D4BC0

// CLabel 
#define CLabel__Draw_x                                             0x6EFA40

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8B32F0
#define CListWnd__dCListWnd_x                                      0x8B4300
#define CListWnd__AddColumn_x                                      0x8B42A0
#define CListWnd__AddColumn1_x                                     0x8B3B20
#define CListWnd__AddLine_x                                        0x8B35A0
#define CListWnd__AddString_x                                      0x8B37B0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B0640
#define CListWnd__CalculateVSBRange_x                              0x8B27B0
#define CListWnd__ClearAllSel_x                                    0x8AF910
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B3180
#define CListWnd__Compare_x                                        0x8B1140
#define CListWnd__Draw_x                                           0x8B23C0
#define CListWnd__DrawColumnSeparators_x                           0x8B2250
#define CListWnd__DrawHeader_x                                     0x8AFC20
#define CListWnd__DrawItem_x                                       0x8B1790
#define CListWnd__DrawLine_x                                       0x8B1EF0
#define CListWnd__DrawSeparator_x                                  0x8B22F0
#define CListWnd__EnsureVisible_x                                  0x8B07A0
#define CListWnd__ExtendSel_x                                      0x8B16A0
#define CListWnd__GetColumnMinWidth_x                              0x8AF2D0
#define CListWnd__GetColumnWidth_x                                 0x8AF1F0
#define CListWnd__GetCurSel_x                                      0x8AE9B0
#define CListWnd__GetItemAtPoint_x                                 0x8B0A30
#define CListWnd__GetItemAtPoint1_x                                0x8B0AA0
#define CListWnd__GetItemData_x                                    0x8AED00
#define CListWnd__GetItemHeight_x                                  0x8B02B0
#define CListWnd__GetItemIcon_x                                    0x8AEEE0
#define CListWnd__GetItemRect_x                                    0x8B0870
#define CListWnd__GetItemText_x                                    0x8AED90
#define CListWnd__GetSelList_x                                     0x8B3A10
#define CListWnd__GetSeparatorRect_x                               0x8B1060
#define CListWnd__RemoveLine_x                                     0x8B3990
#define CListWnd__SetColors_x                                      0x8AEB00
#define CListWnd__SetColumnJustification_x                         0x8AF5A0
#define CListWnd__SetColumnWidth_x                                 0x8AF280
#define CListWnd__SetCurSel_x                                      0x8AE9F0
#define CListWnd__SetItemColor_x                                   0x8B2E60
#define CListWnd__SetItemData_x                                    0x8AF9C0
#define CListWnd__SetItemText_x                                    0x8B2CA0
#define CListWnd__ShiftColumnSeparator_x                           0x8B2B30
#define CListWnd__Sort_x                                           0x8B4400
#define CListWnd__ToggleSel_x                                      0x8AF890

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x708E60

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72A260
#define CMerchantWnd__RequestBuyItem_x                             0x7310D0
#define CMerchantWnd__RequestSellItem_x                            0x731B40
#define CMerchantWnd__SelectRecoverySlot_x                         0x72A510
#define CMerchantWnd__SelectBuySellSlot_x                          0x729770
#define CMerchantWnd__ActualSelect_x                               0x72DFF0

// CObfuscator
#define CObfuscator__doit_x                                        0x85AC60

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D2810
#define CSidlManager__CreateLabel_x                                0x792B00

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x654880
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6547B0
#define CSidlScreenWnd__ConvertToRes_x                             0x8EDC90
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CA360
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CB860
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CB910
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CADE0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8C9D10
#define CSidlScreenWnd__EnableIniStorage_x                         0x8C9460
#define CSidlScreenWnd__GetSidlPiece_x                             0x8C9F00
#define CSidlScreenWnd__Init1_x                                    0x8CB540
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CA410
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8C9620
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CB030
#define CSidlScreenWnd__StoreIniInfo_x                             0x8C8F20
#define CSidlScreenWnd__StoreIniVis_x                              0x8C93F0
#define CSidlScreenWnd__WndNotification_x                          0x8CB2C0
#define CSidlScreenWnd__GetChildItem_x                             0x8C9530
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BC9A0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F1F80
#define CSkillMgr__GetSkillCap_x                                   0x5F2120
#define CSkillMgr__GetNameToken_x                                  0x5F1BF0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8ECF60
#define CSliderWnd__SetValue_x                                     0x8ED130
#define CSliderWnd__SetNumTicks_x                                  0x8ED8B0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79A7F0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8E7950
#define CStmlWnd__CalculateHSBRange_x                              0x8DFE90
#define CStmlWnd__CalculateVSBRange_x                              0x8DFF20
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E00A0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E0980
#define CStmlWnd__ForceParseNow_x                                  0x8E82A0
#define CStmlWnd__GetNextTagPiece_x                                0x8E0880
#define CStmlWnd__GetSTMLText_x                                    0x68BAD0
#define CStmlWnd__GetVisibleText_x                                 0x8E13D0
#define CStmlWnd__InitializeWindowVariables_x                      0x8E3760
#define CStmlWnd__MakeStmlColorTag_x                               0x8DF190
#define CStmlWnd__MakeWndNotificationTag_x                         0x8DF1F0
#define CStmlWnd__SetSTMLText_x                                    0x8E4FC0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E75F0
#define CStmlWnd__UpdateHistoryString_x                            0x8E2310

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EF480
#define CTabWnd__DrawCurrentPage_x                                 0x8EECF0
#define CTabWnd__DrawTab_x                                         0x8EEAC0
#define CTabWnd__GetCurrentPage_x                                  0x8EF0C0
#define CTabWnd__GetPageInnerRect_x                                0x8EE7B0
#define CTabWnd__GetTabInnerRect_x                                 0x8EE9B0
#define CTabWnd__GetTabRect_x                                      0x8EE880
#define CTabWnd__InsertPage_x                                      0x8EF770
#define CTabWnd__SetPage_x                                         0x8EF0F0
#define CTabWnd__SetPageRect_x                                     0x8EF3C0
#define CTabWnd__UpdatePage_x                                      0x8EF710

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431D00

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C70B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F4610

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8ACB10

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x594340
#define CXStr__CXStr1_x                                            0x402290
#define CXStr__CXStr3_x                                            0x8916E0
#define CXStr__dCXStr_x                                            0x5F4C30
#define CXStr__operator_equal_x                                    0x891850
#define CXStr__operator_equal1_x                                   0x8918A0
#define CXStr__operator_plus_equal1_x                              0x892980

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BBBB0
#define CXWnd__Center_x                                            0x8C1E10
#define CXWnd__ClrFocus_x                                          0x8BB790
#define CXWnd__DoAllDrawing_x                                      0x8C1A60
#define CXWnd__DrawChildren_x                                      0x8C1C00
#define CXWnd__DrawColoredRect_x                                   0x8BBF40
#define CXWnd__DrawTooltip_x                                       0x8BC1F0
#define CXWnd__DrawTooltipAtPoint_x                                0x8C09C0
#define CXWnd__GetBorderFrame_x                                    0x8BC660
#define CXWnd__GetChildWndAt_x                                     0x8C27C0
#define CXWnd__GetClientClipRect_x                                 0x8BC410
#define CXWnd__GetScreenClipRect_x                                 0x8C10B0
#define CXWnd__GetScreenRect_x                                     0x8BC830
#define CXWnd__GetTooltipRect_x                                    0x8BC080
#define CXWnd__GetWindowTextA_x                                    0x422FB0
#define CXWnd__IsActive_x                                          0x8B7190
#define CXWnd__IsDescendantOf_x                                    0x8BC5A0
#define CXWnd__IsReallyVisible_x                                   0x8BF9D0
#define CXWnd__IsType_x                                            0x8F0DF0
#define CXWnd__Move_x                                              0x8BF0A0
#define CXWnd__Move1_x                                             0x8C1700
#define CXWnd__ProcessTransition_x                                 0x8BBB50
#define CXWnd__Refade_x                                            0x8BB930
#define CXWnd__Resize_x                                            0x8BC900
#define CXWnd__Right_x                                             0x8C0EB0
#define CXWnd__SetFocus_x                                          0x8BE200
#define CXWnd__SetFont_x                                           0x8BB7E0
#define CXWnd__SetKeyTooltip_x                                     0x8BCB70
#define CXWnd__SetMouseOver_x                                      0x8C13F0
#define CXWnd__StartFade_x                                         0x8BBC00
#define CXWnd__GetChildItem_x                                      0x8C1330

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8B8AA0
#define CXWndManager__DrawWindows_x                                0x8B86E0
#define CXWndManager__GetKeyboardFlags_x                           0x8B6CC0
#define CXWndManager__HandleKeyboardMsg_x                          0x8B7610
#define CXWndManager__RemoveWnd_x                                  0x8B7320

// CDBStr
#define CDBStr__GetString_x                                        0x4A4FF0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44FB20
#define EQ_Character__Cur_HP_x                                     0x4651D0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4474A0
#define EQ_Character__GetCharInfo2_x                               0x865460
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F5D0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F7B0
#define EQ_Character__Max_Endurance_x                              0x5B9B30
#define EQ_Character__Max_HP_x                                     0x45AE50
#define EQ_Character__Max_Mana_x                                   0x5B9960
#define EQ_Character__doCombatAbility_x                            0x5B6F40
#define EQ_Character__UseSkill_x                                   0x470730
#define EQ_Character__GetConLevel_x                                0x5ABCD0
#define EQ_Character__IsExpansionFlag_x                            0x422500
#define EQ_Character__TotalEffect_x                                0x44C850

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x58C500
#define EQ_Item__CreateItemTagString_x                             0x8449C0
#define EQ_Item__IsStackable_x                                     0x838E00
#define EQ_Item__GetImageNum_x                                     0x83BA90

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C4C40
#define EQ_LoadingS__Array_x                                       0xBB0858

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BB2D0
#define EQ_PC__GetAltAbilityIndex_x                                0x84D9D0
#define EQ_PC__GetCombatAbility_x                                  0x84DA60
#define EQ_PC__GetCombatAbilityTimer_x                             0x848AA0
#define EQ_PC__GetItemTimerValue_x                                 0x5B4D30
#define EQ_PC__HasLoreItem_x                                       0x5AF040
#define EQ_PC__AlertInventoryChanged_x                             0x5ABCA0
#define EQ_PC__GetPcZoneClient_x                                   0x5D5970
#define EQ_PC__RemoveMyAffect_x                                    0x5B4240

// EQItemList 
#define EQItemList__EQItemList_x                                   0x508CD0
#define EQItemList__add_item_x                                     0x508C10
#define EQItemList__delete_item_x                                  0x5090D0
#define EQItemList__FreeItemList_x                                 0x508FD0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A42C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C0880
#define EQPlayer__dEQPlayer_x                                      0x5C96E0
#define EQPlayer__DoAttack_x                                       0x5DB880
#define EQPlayer__EQPlayer_x                                       0x5CBB00
#define EQPlayer__SetNameSpriteState_x                             0x5C63C0
#define EQPlayer__SetNameSpriteTint_x                              0x5C1C90
#define EQPlayer__IsBodyType_j_x                                   0x921BC0
#define EQPlayer__IsTargetable_x                                   0x922480
#define EQPlayer__CanSee_x                                         0x9229A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CFF00
#define EQPlayerManager__GetSpawnByName_x                          0x5D0360

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x592660
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5926A0
#define KeypressHandler__ClearCommandStateArray_x                  0x592240
#define KeypressHandler__HandleKeyDown_x                           0x590BA0
#define KeypressHandler__HandleKeyUp_x                             0x590EC0
#define KeypressHandler__SaveKeymapping_x                          0x592310

// MapViewMap 
#define MapViewMap__Clear_x                                        0x701240
#define MapViewMap__SaveEx_x                                       0x704B20

#define PlayerPointManager__GetAltCurrency_x                       0x860420

// StringTable 
#define StringTable__getString_x                                   0x85AF00

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B95E0
#define PcZoneClient__RemovePetEffect_x                            0x5B4F60

//Doors
#define EQSwitch__UseSwitch_x                                      0x547650

//IconCache
#define IconCache__GetIcon_x                                       0x69C200

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6930B0
#define CContainerMgr__CloseContainer_x                            0x6938D0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x762C60

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x585810

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D86D0
#define EQ_Spell__SpellAffects_x                                   0x4D8770
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D87A0
#define CharacterZoneClient__CalcAffectChange_x                    0x448890
#define CLootWnd__LootAll_x                                        0x6F6BB0
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x74CAF0
#define CTargetWnd__WndNotification_x                              0x7A8250

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7AD940

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D1FF0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x494F10
