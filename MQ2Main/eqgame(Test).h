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
#define __ExpectedVersionDate                                     "Oct 14 2015"
#define __ExpectedVersionTime                                     "17:15:05"
#define __ActualVersionDate_x                                      0xAD0E50
#define __ActualVersionTime_x                                      0xAD0E5C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x598DC0
#define __MemChecker1_x                                            0x89AA70
#define __MemChecker2_x                                            0x631F60
#define __MemChecker3_x                                            0x631EB0
#define __MemChecker4_x                                            0x7E7B70
#define __EncryptPad0_x                                            0xC67FE8
#define __EncryptPad1_x                                            0xDF1D98
#define __EncryptPad2_x                                            0xCB1AD0
#define __EncryptPad3_x                                            0xCB16D0
#define __EncryptPad4_x                                            0xDCC248
#define __EncryptPad5_x                                            0x119E008
#define __AC1_x                                                    0x7A4F55
#define __AC2_x                                                    0x54E3A7
#define __AC3_x                                                    0x562B60
#define __AC4_x                                                    0x5697E0
#define __AC5_x                                                    0x57566E
#define __AC6_x                                                    0x579119
#define __AC7_x                                                    0x56FD1C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data                                                 0x845E8

// Direct Input
#define DI8__Main_x                                                0x119DFE0
#define DI8__Keyboard_x                                            0x119DFE4
#define DI8__Mouse_x                                               0x119DFE8
#define DI8__Mouse_Copy_x                                          0x100C5FC
#define DI8__Mouse_Check_x                                         0x1095ECC
#define __AltTimerReady_x                                          0xFFD949
#define __Attack_x                                                 0x1090B6B
#define __Autofire_x                                               0x1090B6C
#define __BindList_x                                               0xC2A0E0
#define __bCommandEnabled_x                                        0xFFBA58
#define __Clicks_x                                                 0x100C6B8
#define __CommandList_x                                            0xC2E450
#define __CurrentMapLabel_x                                        0x11A3A38
#define __CurrentSocial_x                                          0xBE3F44
#define __DoAbilityList_x                                          0x1042E20
#define __do_loot_x                                                0x5159E0
#define __DrawHandler_x                                            0x180A784
#define __GroupCount_x                                             0xFFD022

#define __Guilds_x                                                 0x1002C38
#define __gWorld_x                                                 0xFFF4DC
#define __HotkeyPage_x                                             0x1089820
#define __HWnd_x                                                   0x1095EE8
#define __InChatMode_x                                             0x100C5E4
#define __LastTell_x                                               0x100E528
#define __LMouseHeldTime_x                                         0x100C724
#define __Mouse_x                                                  0x119DFEC
#define __MouseLook_x                                              0x100C67E
#define __MouseEventTime_x                                         0x1091374
#define __gpbCommandEvent_x                                        0xFFF5A4
#define __NetStatusToggle_x                                        0x100C681
#define __PCNames_x                                                0x100DB48
#define __RangeAttackReady_x                                       0x100D808
#define __RMouseHeldTime_x                                         0x100C720
#define __RunWalkState_x                                           0x100C5E8
#define __ScreenMode_x                                             0xF4B308
#define __ScreenX_x                                                0x100C59C
#define __ScreenY_x                                                0x100C598
#define __ScreenXMax_x                                             0x100C5A0
#define __ScreenYMax_x                                             0x100C5A4
#define __ServerHost_x                                             0xFFCF6C
#define __ServerName_x                                             0x1042DE0
#define __ShiftKeyDown_x                                           0x100CC8C
#define __ShowNames_x                                              0x100D9DC
#define __Socials_x                                                0x1042EE0
#define __SubscriptionType_x                                       0x11D1F68
#define __TargetAggroHolder_x                                      0x11A5C74
#define __GroupAggro_x                                             0x11A5CB4
#define __LoginName_x                                              0x1094AC0
#define __Inviter_x                                                0x1090AE8


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xFFF5C8
#define instEQZoneInfo_x                                           0x100C874
#define instKeypressHandler_x                                      0x1091358
#define pinstActiveBanker_x                                        0xFFF580
#define pinstActiveCorpse_x                                        0xFFF584
#define pinstActiveGMaster_x                                       0xFFF588
#define pinstActiveMerchant_x                                      0xFFF57C
#define pinstAggroInfo_x                                           0xE0D778
#define pinstAltAdvManager_x                                       0xF4C408
#define pinstAuraMgr_x                                             0xE19648
#define pinstBandageTarget_x                                       0xFFF568
#define pinstCamActor_x                                            0xF4BD10
#define pinstCDBStr_x                                              0xF4B29C
#define pinstCDisplay_x                                            0xFFF590
#define pinstCEverQuest_x                                          0x119E160
#define pinstCharData_x                                            0xFFF54C
#define pinstCharSpawn_x                                           0xFFF574
#define pinstControlledMissile_x                                   0xFFF548
#define pinstControlledPlayer_x                                    0xFFF574
#define pinstCSidlManager_x                                        0x1809BBC
#define pinstCXWndManager_x                                        0x1809BB4
#define instDynamicZone_x                                          0x100C430
#define pinstDZMember_x                                            0x100C540
#define pinstDZTimerInfo_x                                         0x100C544
#define pinstEQItemList_x                                          0xFFBCA8
#define instEQMisc_x                                               0xC04C48
#define pinstEQSoundManager_x                                      0xF4CDF0
#define instExpeditionLeader_x                                     0x100C47A
#define instExpeditionName_x                                       0x100C4BA
#define pinstGroup_x                                               0xFFD01E
#define pinstImeManager_x                                          0x1809BC0
#define pinstLocalPlayer_x                                         0xFFF560
#define pinstMercenaryData_x                                       0x10919A8
#define pinstMercenaryStats_x                                      0x11A5DC0
#define pinstMercAltAbilities_x                                    0xF4C790
#define pinstModelPlayer_x                                         0xFFF58C
#define pinstPCData_x                                              0xFFF54C
#define pinstSkillMgr_x                                            0x10927E0
#define pinstSpawnManager_x                                        0x10920C8
#define pinstSpellManager_x                                        0x1092928
#define pinstSpellSets_x                                           0x1089884
#define pinstStringTable_x                                         0xFFF4F4
#define pinstSwitchManager_x                                       0xFFCBB0
#define pinstTarget_x                                              0xFFF578
#define pinstTargetObject_x                                        0xFFF550
#define pinstTargetSwitch_x                                        0xFFF554
#define pinstTaskMember_x                                          0xF4B1E8
#define pinstTrackTarget_x                                         0xFFF56C
#define pinstTradeTarget_x                                         0xFFF55C
#define instTributeActive_x                                        0xC04C6D
#define pinstViewActor_x                                           0xF4BD0C
#define pinstWorldData_x                                           0xFFF530


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE0DC58
#define pinstCAudioTriggersWindow_x                                0xE0DAE8
#define pinstCCharacterSelect_x                                    0xF4BBA8
#define pinstCFacePick_x                                           0xF4BB58
#define pinstCNoteWnd_x                                            0xF4BB60
#define pinstCBookWnd_x                                            0xF4BB68
#define pinstCPetInfoWnd_x                                         0xF4BB6C
#define pinstCTrainWnd_x                                           0xF4BB70
#define pinstCSkillsWnd_x                                          0xF4BB74
#define pinstCSkillsSelectWnd_x                                    0xF4BB78
#define pinstCCombatSkillsSelectWnd_x                              0xF4BB7C
#define pinstCFriendsWnd_x                                         0xF4BB80
#define pinstCAuraWnd_x                                            0xF4BB84
#define pinstCRespawnWnd_x                                         0xF4BB88
#define pinstCBandolierWnd_x                                       0xF4BB8C
#define pinstCPotionBeltWnd_x                                      0xF4BB90
#define pinstCAAWnd_x                                              0xF4BB94
#define pinstCGroupSearchFiltersWnd_x                              0xF4BB98
#define pinstCLoadskinWnd_x                                        0xF4BB9C
#define pinstCAlarmWnd_x                                           0xF4BBA0
#define pinstCMusicPlayerWnd_x                                     0xF4BBA4
#define pinstCMailWnd_x                                            0xF4BBAC
#define pinstCMailCompositionWnd_x                                 0xF4BBB0
#define pinstCMailAddressBookWnd_x                                 0xF4BBB4
#define pinstCRaidWnd_x                                            0xF4BBBC
#define pinstCRaidOptionsWnd_x                                     0xF4BBC0
#define pinstCBreathWnd_x                                          0xF4BBC4
#define pinstCMapViewWnd_x                                         0xF4BBC8
#define pinstCMapToolbarWnd_x                                      0xF4BBCC
#define pinstCEditLabelWnd_x                                       0xF4BBD0
#define pinstCTargetWnd_x                                          0xF4BBD4
#define pinstCColorPickerWnd_x                                     0xF4BBD8
#define pinstCPlayerWnd_x                                          0xF4BBDC
#define pinstCOptionsWnd_x                                         0xF4BBE0
#define pinstCBuffWindowNORMAL_x                                   0xF4BBE4
#define pinstCBuffWindowSHORT_x                                    0xF4BBE8
#define pinstCharacterCreation_x                                   0xF4BBEC
#define pinstCCursorAttachment_x                                   0xF4BBF0
#define pinstCCastingWnd_x                                         0xF4BBF4
#define pinstCCastSpellWnd_x                                       0xF4BBF8
#define pinstCSpellBookWnd_x                                       0xF4BBFC
#define pinstCInventoryWnd_x                                       0xF4BC00
#define pinstCBankWnd_x                                            0xF4BC04
#define pinstCQuantityWnd_x                                        0xF4BC08
#define pinstCLootWnd_x                                            0xF4BC0C
#define pinstCActionsWnd_x                                         0xF4BC10
#define pinstCCombatAbilityWnd_x                                   0xF4BC14
#define pinstCMerchantWnd_x                                        0xF4BC18
#define pinstCTradeWnd_x                                           0xF4BC1C
#define pinstCSelectorWnd_x                                        0xF4BC20
#define pinstCBazaarWnd_x                                          0xF4BC24
#define pinstCBazaarSearchWnd_x                                    0xF4BC28
#define pinstCGiveWnd_x                                            0xF4BC44
#define pinstCTrackingWnd_x                                        0xF4BC4C
#define pinstCInspectWnd_x                                         0xF4BC50
#define pinstCSocialEditWnd_x                                      0xF4BC54
#define pinstCFeedbackWnd_x                                        0xF4BC58
#define pinstCBugReportWnd_x                                       0xF4BC5C
#define pinstCVideoModesWnd_x                                      0xF4BC60
#define pinstCTextEntryWnd_x                                       0xF4BC68
#define pinstCFileSelectionWnd_x                                   0xF4BC6C
#define pinstCCompassWnd_x                                         0xF4BC70
#define pinstCPlayerNotesWnd_x                                     0xF4BC74
#define pinstCGemsGameWnd_x                                        0xF4BC78
#define pinstCTimeLeftWnd_x                                        0xF4BC7C
#define pinstCPetitionQWnd_x                                       0xF4BC94
#define pinstCSoulmarkWnd_x                                        0xF4BC98
#define pinstCStoryWnd_x                                           0xF4BC9C
#define pinstCJournalTextWnd_x                                     0xF4BCA0
#define pinstCJournalCatWnd_x                                      0xF4BCA4
#define pinstCBodyTintWnd_x                                        0xF4BCA8
#define pinstCServerListWnd_x                                      0xF4BCAC
#define pinstCAvaZoneWnd_x                                         0xF4BCB8
#define pinstCBlockedBuffWnd_x                                     0xF4BCBC
#define pinstCBlockedPetBuffWnd_x                                  0xF4BCC0
#define pinstCInvSlotMgr_x                                         0xF4BD04
#define pinstCContainerMgr_x                                       0xF4BD08
#define pinstCAdventureLeaderboardWnd_x                            0x119EB10
#define pinstCAdventureRequestWnd_x                                0x119EB88
#define pinstCAltStorageWnd_x                                      0x119EE68
#define pinstCAdventureStatsWnd_x                                  0x119EC00
#define pinstCBarterMerchantWnd_x                                  0x119FA50
#define pinstCBarterSearchWnd_x                                    0x119FAC8
#define pinstCBarterWnd_x                                          0x119FB40
#define pinstCChatManager_x                                        0x11A01D0
#define pinstCDynamicZoneWnd_x                                     0x11A0680
#define pinstCEQMainWnd_x                                          0x11A0818
#define pinstCFellowshipWnd_x                                      0x11A0614
#define pinstCFindLocationWnd_x                                    0x11A0AE8
#define pinstCGroupSearchWnd_x                                     0x11A0DB8
#define pinstCGroupWnd_x                                           0x11A0E30
#define pinstCGuildBankWnd_x                                       0x11A0EA8
#define pinstCGuildMgmtWnd_x                                       0x11A2F98
#define pinstCHotButtonWnd_x                                       0x11A3064
#define pinstCHotButtonWnd1_x                                      0x11A3064
#define pinstCHotButtonWnd2_x                                      0x11A3068
#define pinstCHotButtonWnd3_x                                      0x11A306C
#define pinstCHotButtonWnd4_x                                      0x11A3090
#define pinstCItemDisplayManager_x                                 0x11A3388
#define pinstCItemExpTransferWnd_x                                 0x11A3404
#define pinstCLFGuildWnd_x                                         0x11A36E0
#define pinstCMIZoneSelectWnd_x                                    0x11A3CC8
#define pinstCConfirmationDialog_x                                 0x11A43D0
#define pinstCPopupWndManager_x                                    0x11A43D0
#define pinstCProgressionSelectionWnd_x                            0x11A44C0
#define pinstCPvPStatsWnd_x                                        0x11A45B0
#define pinstCSystemInfoDialogBox_x                                0x11A4CB8
#define pinstCTaskWnd_x                                            0x11A6080
#define pinstCTaskSomething_x                                      0xE19D90
#define pinstCTaskTemplateSelectWnd_x                              0x11A6008
#define pinstCTipWndOFDAY_x                                        0x11A62D8
#define pinstCTipWndCONTEXT_x                                      0x11A62DC
#define pinstCTitleWnd_x                                           0x11A6358
#define pinstCContextMenuManager_x                                 0x1809B2C
#define pinstCVoiceMacroWnd_x                                      0x1092F90
#define pinstCHtmlWnd_x                                            0x1093088
#define pinstIconCache_x                                           0x11A07EC
#define pinstCTradeskillWnd_x                                      0x11A6458
#define pinstCAdvancedLootWnd_x                                    0xF4BCF8
#define pinstRewardSelectionWnd_x                                  0x11A4AD8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x52D500
#define __ConvertItemTags_x                                        0x51A660
#define __ExecuteCmd_x                                             0x505140
#define __EQGetTime_x                                              0x89ADD0
#define __get_melee_range_x                                        0x50BE20
#define __GetGaugeValueFromEQ_x                                    0x7A3C90
#define __GetLabelFromEQ_x                                         0x7A4EE0
#define __ToggleMount_x                                            0x6CCD40
#define __GetXTargetType_x                                         0x92C0D0
#define __LoadFrontEnd_x                                           0x631610
#define __NewUIINI_x                                               0x7A3590
#define __ProcessGameEvents_x                                      0x571A80
#define __ProcessMouseEvent_x                                      0x571220
#define CrashDetected_x                                            0x6330E0
#define wwsCrashReportCheckForUploader_x                           0x7F78B0
#define DrawNetStatus_x                                            0x5A8930
#define Util__FastTime_x                                           0x89A720
#define Expansion_HoT_x                                            0x100D974
#define __HelpPath_x                                               0x10910E0
#define __STMLToText_x                                             0x8DF840

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F060
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419EB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C1BC0
#define AltAdvManager__IsAbilityReady_x                            0x4C1C30
#define AltAdvManager__GetAAById_x                                 0x4C1FF0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463F30
#define CharacterZoneClient__MakeMeVisible_x                       0x469910
#define CharacterZoneClient__IsStackBlocked_x                      0x4463F0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6611A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66F790

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x587DC0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68A580
#define CChatManager__InitContextMenu_x                            0x68B100

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DDBA0
#define CContextMenu__AddMenuItem_x                                0x8DDDC0
#define CContextMenu__dCContextMenu_x                              0x8DDDB0
#define CContextMenu__RemoveMenuItem_x                             0x8DE0B0
#define CContextMenu__RemoveAllMenuItems_x                         0x8DE0D0
#define CContextMenuManager__AddMenu_x                             0x8C9A90
#define CContextMenuManager__RemoveMenu_x                          0x8C9DD0
#define CContextMenuManager__PopupMenu_x                           0x8CA220
#define CContextMenuManager__Flush_x                               0x8C9B00
#define CContextMenuManager__GetMenu_x                             0x415500

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x880D60
#define CChatService__GetFriendName_x                              0x880D70

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6903B0
#define CChatWindow__Clear_x                                       0x68FF60
#define CChatWindow__WndNotification_x                             0x6908F0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CD980
#define CComboWnd__Draw_x                                          0x8CDB90
#define CComboWnd__GetCurChoice_x                                  0x8CD750
#define CComboWnd__GetListRect_x                                   0x8CDE30
#define CComboWnd__GetTextRect_x                                   0x8CD9F0
#define CComboWnd__InsertChoice_x                                  0x8CDEA0
#define CComboWnd__SetColors_x                                     0x8CD6E0
#define CComboWnd__SetChoice_x                                     0x8CD710
#define CComboWnd__GetItemCount_x                                  0x8CD740

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x699BE0
#define CContainerWnd__vftable_x                                   0xADA7E8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4AFE80
#define CDisplay__GetClickedActor_x                                0x4A8A00
#define CDisplay__GetUserDefinedColor_x                            0x4A72C0
#define CDisplay__GetWorldFilePath_x                               0x4A6710
#define CDisplay__is3dON_x                                         0x4A5AE0
#define CDisplay__ReloadUI_x                                       0x4BB3A0
#define CDisplay__WriteTextHD2_x                                   0x4AC220

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F4200

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E2540
#define CEditWnd__GetCharIndexPt_x                                 0x8E35E0
#define CEditWnd__GetDisplayString_x                               0x8E26F0
#define CEditWnd__GetHorzOffset_x                                  0x8E2A30
#define CEditWnd__GetLineForPrintableChar_x                        0x8E30A0
#define CEditWnd__GetSelStartPt_x                                  0x8E38A0
#define CEditWnd__GetSTMLSafeText_x                                0x8E2BD0
#define CEditWnd__PointFromPrintableChar_x                         0x8E3190
#define CEditWnd__SelectableCharFromPoint_x                        0x8E3310
#define CEditWnd__SetEditable_x                                    0x8E2BA0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54EAF0
#define CEverQuest__DoTellWindow_x                                 0x5544F0
#define CEverQuest__DropHeldItemOnGround_x                         0x55CFE0
#define CEverQuest__dsp_chat_x                                     0x555C90
#define CEverQuest__Emote_x                                        0x555EF0
#define CEverQuest__EnterZone_x                                    0x56A010
#define CEverQuest__GetBodyTypeDesc_x                              0x54B350
#define CEverQuest__GetClassDesc_x                                 0x551060
#define CEverQuest__GetClassThreeLetterCode_x                      0x551660
#define CEverQuest__GetDeityDesc_x                                 0x54BC30
#define CEverQuest__GetLangDesc_x                                  0x54B6E0
#define CEverQuest__GetRaceDesc_x                                  0x551820
#define CEverQuest__InterpretCmd_x                                 0x5567D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x56E180
#define CEverQuest__LMouseUp_x                                     0x570270
#define CEverQuest__RightClickedOnPlayer_x                         0x56EC80
#define CEverQuest__RMouseUp_x                                     0x56FCD0
#define CEverQuest__SetGameState_x                                 0x54F1A0
#define CEverQuest__UPCNotificationFlush_x                         0x557930
#define CEverQuest__IssuePetCommand_x                              0x557490

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AA6B0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AA710
#define CGaugeWnd__Draw_x                                          0x6AAB40

// CGuild
#define CGuild__FindMemberByName_x                                 0x435D90

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C7790

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D5580
#define CInvSlotMgr__MoveItem_x                                    0x6D64C0
#define CInvSlotMgr__SelectSlot_x                                  0x6D5630

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D4A10
#define CInvSlot__SliderComplete_x                                 0x6D23D0
#define CInvSlot__GetItemBase_x                                    0x6D1860

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D7640

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A0630
#define CItemDisplayWnd__UpdateStrings_x                           0x6D8960

// CLabel 
#define CLabel__Draw_x                                             0x6F3700

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8B95F0
#define CListWnd__dCListWnd_x                                      0x8BA610
#define CListWnd__AddColumn_x                                      0x8BA5B0
#define CListWnd__AddColumn1_x                                     0x8B9E20
#define CListWnd__AddLine_x                                        0x8B98A0
#define CListWnd__AddString_x                                      0x8B9AB0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B6920
#define CListWnd__CalculateVSBRange_x                              0x8B8AA0
#define CListWnd__ClearAllSel_x                                    0x8B5BD0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B9480
#define CListWnd__Compare_x                                        0x8B7430
#define CListWnd__Draw_x                                           0x8B86B0
#define CListWnd__DrawColumnSeparators_x                           0x8B8540
#define CListWnd__DrawHeader_x                                     0x8B5EE0
#define CListWnd__DrawItem_x                                       0x8B7A70
#define CListWnd__DrawLine_x                                       0x8B81E0
#define CListWnd__DrawSeparator_x                                  0x8B85E0
#define CListWnd__EnsureVisible_x                                  0x8B6A80
#define CListWnd__ExtendSel_x                                      0x8B7980
#define CListWnd__GetColumnMinWidth_x                              0x8B5590
#define CListWnd__GetColumnWidth_x                                 0x8B54B0
#define CListWnd__GetCurSel_x                                      0x8B4C70
#define CListWnd__GetItemAtPoint_x                                 0x8B6D20
#define CListWnd__GetItemAtPoint1_x                                0x8B6D90
#define CListWnd__GetItemData_x                                    0x8B4FC0
#define CListWnd__GetItemHeight_x                                  0x8B6570
#define CListWnd__GetItemIcon_x                                    0x8B51A0
#define CListWnd__GetItemRect_x                                    0x8B6B60
#define CListWnd__GetItemText_x                                    0x8B5050
#define CListWnd__GetSelList_x                                     0x8B9D10
#define CListWnd__GetSeparatorRect_x                               0x8B7350
#define CListWnd__RemoveLine_x                                     0x8B9C90
#define CListWnd__SetColors_x                                      0x8B4DC0
#define CListWnd__SetColumnJustification_x                         0x8B5860
#define CListWnd__SetColumnWidth_x                                 0x8B5540
#define CListWnd__SetCurSel_x                                      0x8B4CB0
#define CListWnd__SetItemColor_x                                   0x8B9160
#define CListWnd__SetItemData_x                                    0x8B5C80
#define CListWnd__SetItemText_x                                    0x8B8FA0
#define CListWnd__ShiftColumnSeparator_x                           0x8B8E30
#define CListWnd__Sort_x                                           0x8BA710
#define CListWnd__ToggleSel_x                                      0x8B5B50

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70CB10

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72DE60
#define CMerchantWnd__RequestBuyItem_x                             0x734C50
#define CMerchantWnd__RequestSellItem_x                            0x7356A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x72E110
#define CMerchantWnd__SelectBuySellSlot_x                          0x72D370
#define CMerchantWnd__ActualSelect_x                               0x731B90

// CObfuscator
#define CObfuscator__doit_x                                        0x861120

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D8AA0
#define CSidlManager__CreateLabel_x                                0x796640

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6583E0
#define CSidlScreenWnd__CalculateHSBRange_x                        0x6584C0
#define CSidlScreenWnd__ConvertToRes_x                             0x8F40E0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D0610
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D1B00
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D1BB0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D1080
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CFFC0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CF700
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D01B0
#define CSidlScreenWnd__Init1_x                                    0x8D17E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D06C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CF8C0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D12D0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CF1D0
#define CSidlScreenWnd__StoreIniVis_x                              0x8CF690
#define CSidlScreenWnd__WndNotification_x                          0x8D1560
#define CSidlScreenWnd__GetChildItem_x                             0x8CF7D0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C2CA0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F3180
#define CSkillMgr__GetSkillCap_x                                   0x5F3340
#define CSkillMgr__GetNameToken_x                                  0x5F2DA0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F33B0
#define CSliderWnd__SetValue_x                                     0x8F3580
#define CSliderWnd__SetNumTicks_x                                  0x8F3D00

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79E2D0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EDD60
#define CStmlWnd__CalculateHSBRange_x                              0x8E6280
#define CStmlWnd__CalculateVSBRange_x                              0x8E6310
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E6490
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E6D70
#define CStmlWnd__ForceParseNow_x                                  0x8EE6B0
#define CStmlWnd__GetNextTagPiece_x                                0x8E6C70
#define CStmlWnd__GetSTMLText_x                                    0x68F800
#define CStmlWnd__GetVisibleText_x                                 0x8E77C0
#define CStmlWnd__InitializeWindowVariables_x                      0x8E9B50
#define CStmlWnd__MakeStmlColorTag_x                               0x8E5580
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E55E0
#define CStmlWnd__SetSTMLText_x                                    0x8EB3C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EDA00
#define CStmlWnd__UpdateHistoryString_x                            0x8E8700

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F58E0
#define CTabWnd__DrawCurrentPage_x                                 0x8F5150
#define CTabWnd__DrawTab_x                                         0x8F4F10
#define CTabWnd__GetCurrentPage_x                                  0x8F5520
#define CTabWnd__GetPageInnerRect_x                                0x8F4C00
#define CTabWnd__GetTabInnerRect_x                                 0x8F4E00
#define CTabWnd__GetTabRect_x                                      0x8F4CD0
#define CTabWnd__InsertPage_x                                      0x8F5BD0
#define CTabWnd__SetPage_x                                         0x8F5550
#define CTabWnd__SetPageRect_x                                     0x8F5820
#define CTabWnd__UpdatePage_x                                      0x8F5B70

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431B70

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CD350

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FAA80

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B2DD0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x595340
#define CXStr__CXStr1_x                                            0x402280
#define CXStr__CXStr3_x                                            0x8977B0
#define CXStr__dCXStr_x                                            0x7965F0
#define CXStr__operator_equal_x                                    0x897920
#define CXStr__operator_equal1_x                                   0x897970
#define CXStr__operator_plus_equal1_x                              0x898A50

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C1E80
#define CXWnd__Center_x                                            0x8C80A0
#define CXWnd__ClrFocus_x                                          0x8C1A70
#define CXWnd__DoAllDrawing_x                                      0x8C7CE0
#define CXWnd__DrawChildren_x                                      0x8C7E90
#define CXWnd__DrawColoredRect_x                                   0x8C2240
#define CXWnd__DrawTooltip_x                                       0x8C24F0
#define CXWnd__DrawTooltipAtPoint_x                                0x8C6C40
#define CXWnd__GetBorderFrame_x                                    0x8C2960
#define CXWnd__GetChildWndAt_x                                     0x8C8A60
#define CXWnd__GetClientClipRect_x                                 0x8C2710
#define CXWnd__GetScreenClipRect_x                                 0x8C7340
#define CXWnd__GetScreenRect_x                                     0x8C2B30
#define CXWnd__GetTooltipRect_x                                    0x8C2380
#define CXWnd__GetWindowTextA_x                                    0x423060
#define CXWnd__IsActive_x                                          0x8BD400
#define CXWnd__IsDescendantOf_x                                    0x8C28A0
#define CXWnd__IsReallyVisible_x                                   0x8C5C60
#define CXWnd__IsType_x                                            0x8F72A0
#define CXWnd__Move_x                                              0x8C5370
#define CXWnd__Move1_x                                             0x8C7990
#define CXWnd__ProcessTransition_x                                 0x8C1E30
#define CXWnd__Refade_x                                            0x8C1C10
#define CXWnd__Resize_x                                            0x8C2C00
#define CXWnd__Right_x                                             0x8C7140
#define CXWnd__SetFocus_x                                          0x8C44B0
#define CXWnd__SetFont_x                                           0x8C1AC0
#define CXWnd__SetKeyTooltip_x                                     0x8C2E70
#define CXWnd__SetMouseOver_x                                      0x8C7680
#define CXWnd__StartFade_x                                         0x8C1ED0
#define CXWnd__GetChildItem_x                                      0x8C75C0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BED30
#define CXWndManager__DrawWindows_x                                0x8BE970
#define CXWndManager__GetKeyboardFlags_x                           0x8BCF30
#define CXWndManager__HandleKeyboardMsg_x                          0x8BD890
#define CXWndManager__RemoveWnd_x                                  0x8BD590

// CDBStr
#define CDBStr__GetString_x                                        0x4A4090

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E050
#define EQ_Character__Cur_HP_x                                     0x463600
#define EQ_Character__GetAACastingTimeModifier_x                   0x445F70
#define EQ_Character__GetCharInfo2_x                               0x86B860
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43DF40
#define EQ_Character__GetFocusRangeModifier_x                      0x43E130
#define EQ_Character__Max_Endurance_x                              0x5BADF0
#define EQ_Character__Max_HP_x                                     0x459280
#define EQ_Character__Max_Mana_x                                   0x5BAC20
#define EQ_Character__doCombatAbility_x                            0x5B8200
#define EQ_Character__UseSkill_x                                   0x46EB10
#define EQ_Character__GetConLevel_x                                0x5ACF70
#define EQ_Character__IsExpansionFlag_x                            0x4225B0
#define EQ_Character__TotalEffect_x                                0x44B2F0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58D5C0
#define EQ_Item__CreateItemTagString_x                             0x84B170
#define EQ_Item__IsStackable_x                                     0x83F280
#define EQ_Item__GetImageNum_x                                     0x841FC0
#define EQ_Item__CreateItemClient_x                                0x58E1A0
#define EQ_Item__GetItemValue_x                                    0x849E00
#define EQ_Item__ValueSellMerchant_x                               0x84C4F0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C3CB0
#define EQ_LoadingS__Array_x                                       0xC12A20

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BC590
#define EQ_PC__GetAlternateAbilityId_x                             0x8544E0
#define EQ_PC__GetCombatAbility_x                                  0x854570
#define EQ_PC__GetCombatAbilityTimer_x                             0x84F460
#define EQ_PC__GetItemTimerValue_x                                 0x5B5FE0
#define EQ_PC__HasLoreItem_x                                       0x5B02C0
#define EQ_PC__AlertInventoryChanged_x                             0x5ACF40
#define EQ_PC__GetPcZoneClient_x                                   0x5D6BE0
#define EQ_PC__RemoveMyAffect_x                                    0x5B54F0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x509E60
#define EQItemList__add_item_x                                     0x509DA0
#define EQItemList__delete_item_x                                  0x50A260
#define EQItemList__FreeItemList_x                                 0x50A160

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A3360

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C1B30
#define EQPlayer__dEQPlayer_x                                      0x5CA9B0
#define EQPlayer__DoAttack_x                                       0x5DCB00
#define EQPlayer__EQPlayer_x                                       0x5CCDD0
#define EQPlayer__SetNameSpriteState_x                             0x5C7680
#define EQPlayer__SetNameSpriteTint_x                              0x5C2F40
#define EQPlayer__IsBodyType_j_x                                   0x928260
#define EQPlayer__IsTargetable_x                                   0x928B60
#define EQPlayer__CanSee_x                                         0x929080
#define PlayerZoneClient__ChangeHeight_x                           0x5DC9C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D11C0
#define EQPlayerManager__GetSpawnByName_x                          0x5D1620

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x593670
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5936B0
#define KeypressHandler__ClearCommandStateArray_x                  0x593250
#define KeypressHandler__HandleKeyDown_x                           0x591BB0
#define KeypressHandler__HandleKeyUp_x                             0x591ED0
#define KeypressHandler__SaveKeymapping_x                          0x593320

// MapViewMap 
#define MapViewMap__Clear_x                                        0x704EF0
#define MapViewMap__SaveEx_x                                       0x7087D0

#define PlayerPointManager__GetAltCurrency_x                       0x866830

// StringTable 
#define StringTable__getString_x                                   0x8613C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BA8A0
#define PcZoneClient__RemovePetEffect_x                            0x5B6210

//Doors
#define EQSwitch__UseSwitch_x                                      0x548700

//IconCache
#define IconCache__GetIcon_x                                       0x6A0050

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x696EF0
#define CContainerMgr__CloseContainer_x                            0x697710

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x766860

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x586880

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D9E50
#define EQ_Spell__SpellAffects_x                                   0x4D9EF0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D9F20
#define CharacterZoneClient__CalcAffectChange_x                    0x447360
#define CLootWnd__LootAll_x                                        0x6FA880

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7506D0
#define CTargetWnd__WndNotification_x                              0x7ABD90

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B1480

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D36A0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x493700

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E1B70
#define CSidlManager__FindAnimation1_x                             0x8D6980

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CB2F0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CB2A0
#define CAltAbilityData__GetMaxRank_x                              0x4C0280
