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
#define __ExpectedVersionDate                                     "Oct 16 2015"
#define __ExpectedVersionTime                                     "19:22:38"
#define __ActualVersionDate_x                                      0xAD0E58
#define __ActualVersionTime_x                                      0xAD0E64

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x598950
#define __MemChecker1_x                                            0x899FB0
#define __MemChecker2_x                                            0x631AD0
#define __MemChecker3_x                                            0x631A20
#define __MemChecker4_x                                            0x7E76E0
#define __EncryptPad0_x                                            0xC67FE8
#define __EncryptPad1_x                                            0xDF1D98
#define __EncryptPad2_x                                            0xCB1AD0
#define __EncryptPad3_x                                            0xCB16D0
#define __EncryptPad4_x                                            0xDCC248
#define __EncryptPad5_x                                            0x119E008
#define __AC1_x                                                    0x7A49C5
#define __AC2_x                                                    0x54E117
#define __AC3_x                                                    0x5628D0
#define __AC4_x                                                    0x569550
#define __AC5_x                                                    0x5753EE
#define __AC6_x                                                    0x578E99
#define __AC7_x                                                    0x56FA9C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data                                                 0x91A2B

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
#define __do_loot_x                                                0x5156E0
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
#define pinstCamActor_x                                            0xF4BD14
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
#define pinstViewActor_x                                           0xF4BD10
#define pinstWorldData_x                                           0xFFF530


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE0DC58
#define pinstCAudioTriggersWindow_x                                0xE0DAE8
#define pinstCCharacterSelect_x                                    0xF4BBAC
#define pinstCFacePick_x                                           0xF4B95C
#define pinstCNoteWnd_x                                            0xF4BB64
#define pinstCBookWnd_x                                            0xF4BB6C
#define pinstCPetInfoWnd_x                                         0xF4BB70
#define pinstCTrainWnd_x                                           0xF4BB74
#define pinstCSkillsWnd_x                                          0xF4BB78
#define pinstCSkillsSelectWnd_x                                    0xF4BB7C
#define pinstCCombatSkillsSelectWnd_x                              0xF4BB80
#define pinstCFriendsWnd_x                                         0xF4BB84
#define pinstCAuraWnd_x                                            0xF4BB88
#define pinstCRespawnWnd_x                                         0xF4BB8C
#define pinstCBandolierWnd_x                                       0xF4BB90
#define pinstCPotionBeltWnd_x                                      0xF4BB94
#define pinstCAAWnd_x                                              0xF4BB98
#define pinstCGroupSearchFiltersWnd_x                              0xF4BB9C
#define pinstCLoadskinWnd_x                                        0xF4BBA0
#define pinstCAlarmWnd_x                                           0xF4BBA4
#define pinstCMusicPlayerWnd_x                                     0xF4BBA8
#define pinstCMailWnd_x                                            0xF4BBB0
#define pinstCMailCompositionWnd_x                                 0xF4BBB4
#define pinstCMailAddressBookWnd_x                                 0xF4BBB8
#define pinstCRaidWnd_x                                            0xF4BBC0
#define pinstCRaidOptionsWnd_x                                     0xF4BBC4
#define pinstCBreathWnd_x                                          0xF4BBC8
#define pinstCMapViewWnd_x                                         0xF4BBCC
#define pinstCMapToolbarWnd_x                                      0xF4BBD0
#define pinstCEditLabelWnd_x                                       0xF4BBD4
#define pinstCTargetWnd_x                                          0xF4BBD8
#define pinstCColorPickerWnd_x                                     0xF4BBDC
#define pinstCPlayerWnd_x                                          0xF4BBE0
#define pinstCOptionsWnd_x                                         0xF4BBE4
#define pinstCBuffWindowNORMAL_x                                   0xF4BBE8
#define pinstCBuffWindowSHORT_x                                    0xF4BBEC
#define pinstCharacterCreation_x                                   0xF4BBF0
#define pinstCCursorAttachment_x                                   0xF4BBF4
#define pinstCCastingWnd_x                                         0xF4BBF8
#define pinstCCastSpellWnd_x                                       0xF4BBFC
#define pinstCSpellBookWnd_x                                       0xF4BC00
#define pinstCInventoryWnd_x                                       0xF4BC04
#define pinstCBankWnd_x                                            0xF4BC08
#define pinstCQuantityWnd_x                                        0xF4BC0C
#define pinstCLootWnd_x                                            0xF4BC10
#define pinstCActionsWnd_x                                         0xF4BC14
#define pinstCCombatAbilityWnd_x                                   0xF4BC18
#define pinstCMerchantWnd_x                                        0xF4BC1C
#define pinstCTradeWnd_x                                           0xF4BC20
#define pinstCSelectorWnd_x                                        0xF4BC24
#define pinstCBazaarWnd_x                                          0xF4BC28
#define pinstCBazaarSearchWnd_x                                    0xF4BC2C
#define pinstCGiveWnd_x                                            0xF4BC48
#define pinstCTrackingWnd_x                                        0xF4BC50
#define pinstCInspectWnd_x                                         0xF4BC54
#define pinstCSocialEditWnd_x                                      0xF4BC58
#define pinstCFeedbackWnd_x                                        0xF4BC5C
#define pinstCBugReportWnd_x                                       0xF4BC60
#define pinstCVideoModesWnd_x                                      0xF4BC64
#define pinstCTextEntryWnd_x                                       0xF4BC6C
#define pinstCFileSelectionWnd_x                                   0xF4BC70
#define pinstCCompassWnd_x                                         0xF4BC74
#define pinstCPlayerNotesWnd_x                                     0xF4BC78
#define pinstCGemsGameWnd_x                                        0xF4BC7C
#define pinstCTimeLeftWnd_x                                        0xF4BC80
#define pinstCPetitionQWnd_x                                       0xF4BC98
#define pinstCSoulmarkWnd_x                                        0xF4BC9C
#define pinstCStoryWnd_x                                           0xF4BCA0
#define pinstCJournalTextWnd_x                                     0xF4BCA4
#define pinstCJournalCatWnd_x                                      0xF4BCA8
#define pinstCBodyTintWnd_x                                        0xF4BCAC
#define pinstCServerListWnd_x                                      0xF4BCB0
#define pinstCAvaZoneWnd_x                                         0xF4BCBC
#define pinstCBlockedBuffWnd_x                                     0xF4BCC0
#define pinstCBlockedPetBuffWnd_x                                  0xF4BCC4
#define pinstCInvSlotMgr_x                                         0xF4BD08
#define pinstCContainerMgr_x                                       0xF4BD0C
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
#define pinstCAdvancedLootWnd_x                                    0xF4BCFC
#define pinstRewardSelectionWnd_x                                  0x11A4AD8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x52D200
#define __ConvertItemTags_x                                        0x51A360
#define __ExecuteCmd_x                                             0x504E70
#define __EQGetTime_x                                              0x89A310
#define __get_melee_range_x                                        0x50BB20
#define __GetGaugeValueFromEQ_x                                    0x7A3700
#define __GetLabelFromEQ_x                                         0x7A4950
#define __ToggleMount_x                                            0x6CC640
#define __GetXTargetType_x                                         0x92B640
#define __LoadFrontEnd_x                                           0x631180
#define __NewUIINI_x                                               0x7A3000
#define __ProcessGameEvents_x                                      0x571800
#define __ProcessMouseEvent_x                                      0x570FA0
#define CrashDetected_x                                            0x632C50
#define wwsCrashReportCheckForUploader_x                           0x7F6DE0
#define DrawNetStatus_x                                            0x5A84C0
#define Util__FastTime_x                                           0x899C60
#define Expansion_HoT_x                                            0x100D974
#define __HelpPath_x                                               0x10910E0
#define __STMLToText_x                                             0x8DEEF0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F0B0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419F00

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C2140
#define AltAdvManager__IsAbilityReady_x                            0x4C21B0
#define AltAdvManager__GetAAById_x                                 0x4C2570

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x464130
#define CharacterZoneClient__MakeMeVisible_x                       0x469B10
#define CharacterZoneClient__IsStackBlocked_x                      0x446630

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x660B20

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66EF10

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x587AF0
#define CButtonWnd__CButtonWnd_x                                   0x8D3190

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x689DC0
#define CChatManager__InitContextMenu_x                            0x68A940

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DD250
#define CContextMenu__dCContextMenu_x                              0x8DD460
#define CContextMenu__AddMenuItem_x                                0x8DD470
#define CContextMenu__RemoveMenuItem_x                             0x8DD760
#define CContextMenu__RemoveAllMenuItems_x                         0x8DD780
#define CContextMenuManager__AddMenu_x                             0x8C9100
#define CContextMenuManager__RemoveMenu_x                          0x8C9450
#define CContextMenuManager__PopupMenu_x                           0x8C98A0
#define CContextMenuManager__Flush_x                               0x8C9170
#define CContextMenuManager__GetMenu_x                             0x415550

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x880230
#define CChatService__GetFriendName_x                              0x880240

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x68FBE0
#define CChatWindow__Clear_x                                       0x68F7A0
#define CChatWindow__WndNotification_x                             0x690120

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CD010
#define CComboWnd__Draw_x                                          0x8CD220
#define CComboWnd__GetCurChoice_x                                  0x8CCDE0
#define CComboWnd__GetListRect_x                                   0x8CD4C0
#define CComboWnd__GetTextRect_x                                   0x8CD080
#define CComboWnd__InsertChoice_x                                  0x8CD530
#define CComboWnd__SetColors_x                                     0x8CCD70
#define CComboWnd__SetChoice_x                                     0x8CCDA0
#define CComboWnd__GetItemCount_x                                  0x8CCDD0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6993B0
#define CContainerWnd__vftable_x                                   0xADA7F0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B0380
#define CDisplay__GetClickedActor_x                                0x4A8F00
#define CDisplay__GetUserDefinedColor_x                            0x4A77C0
#define CDisplay__GetWorldFilePath_x                               0x4A6C10
#define CDisplay__is3dON_x                                         0x4A5FE0
#define CDisplay__ReloadUI_x                                       0x4BB8A0
#define CDisplay__WriteTextHD2_x                                   0x4AC720

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F38C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E1BF0
#define CEditWnd__GetCharIndexPt_x                                 0x8E2C90
#define CEditWnd__GetDisplayString_x                               0x8E1DA0
#define CEditWnd__GetHorzOffset_x                                  0x8E20E0
#define CEditWnd__GetLineForPrintableChar_x                        0x8E2750
#define CEditWnd__GetSelStartPt_x                                  0x8E2F50
#define CEditWnd__GetSTMLSafeText_x                                0x8E2280
#define CEditWnd__PointFromPrintableChar_x                         0x8E2840
#define CEditWnd__SelectableCharFromPoint_x                        0x8E29C0
#define CEditWnd__SetEditable_x                                    0x8E2250

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54E860
#define CEverQuest__DoTellWindow_x                                 0x554260
#define CEverQuest__DropHeldItemOnGround_x                         0x55CD50
#define CEverQuest__dsp_chat_x                                     0x555A00
#define CEverQuest__Emote_x                                        0x555C60
#define CEverQuest__EnterZone_x                                    0x569D80
#define CEverQuest__GetBodyTypeDesc_x                              0x54B0C0
#define CEverQuest__GetClassDesc_x                                 0x550DD0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5513D0
#define CEverQuest__GetDeityDesc_x                                 0x54B9A0
#define CEverQuest__GetLangDesc_x                                  0x54B450
#define CEverQuest__GetRaceDesc_x                                  0x551590
#define CEverQuest__InterpretCmd_x                                 0x556540
#define CEverQuest__LeftClickedOnPlayer_x                          0x56DF00
#define CEverQuest__LMouseUp_x                                     0x56FFF0
#define CEverQuest__RightClickedOnPlayer_x                         0x56EA00
#define CEverQuest__RMouseUp_x                                     0x56FA50
#define CEverQuest__SetGameState_x                                 0x54EF10
#define CEverQuest__UPCNotificationFlush_x                         0x5576A0
#define CEverQuest__IssuePetCommand_x                              0x557200

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A9F40
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A9FA0
#define CGaugeWnd__Draw_x                                          0x6AA3D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x435FE0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C7060

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D4E80
#define CInvSlotMgr__MoveItem_x                                    0x6D5DC0
#define CInvSlotMgr__SelectSlot_x                                  0x6D4F30

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D4310
#define CInvSlot__SliderComplete_x                                 0x6D1CE0
#define CInvSlot__GetItemBase_x                                    0x6D1160

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D6F70

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A00A0
#define CItemDisplayWnd__UpdateStrings_x                           0x6D82C0

// CLabel 
#define CLabel__Draw_x                                             0x6F3130

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B8C30
#define CListWnd__dCListWnd_x                                      0x8B9C60
#define CListWnd__AddColumn_x                                      0x8B9C00
#define CListWnd__AddColumn1_x                                     0x8B9470
#define CListWnd__AddLine_x                                        0x8B8EF0
#define CListWnd__AddString_x                                      0x8B9100
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B5F60
#define CListWnd__CalculateVSBRange_x                              0x8B80F0
#define CListWnd__ClearAllSel_x                                    0x8B5210
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B8AC0
#define CListWnd__Compare_x                                        0x8B6A70
#define CListWnd__Draw_x                                           0x8B7D00
#define CListWnd__DrawColumnSeparators_x                           0x8B7B90
#define CListWnd__DrawHeader_x                                     0x8B5520
#define CListWnd__DrawItem_x                                       0x8B70C0
#define CListWnd__DrawLine_x                                       0x8B7830
#define CListWnd__DrawSeparator_x                                  0x8B7C30
#define CListWnd__EnsureVisible_x                                  0x8B60C0
#define CListWnd__ExtendSel_x                                      0x8B6FD0
#define CListWnd__GetColumnMinWidth_x                              0x8B4BD0
#define CListWnd__GetColumnWidth_x                                 0x8B4AF0
#define CListWnd__GetCurSel_x                                      0x8B42C0
#define CListWnd__GetItemAtPoint_x                                 0x8B6360
#define CListWnd__GetItemAtPoint1_x                                0x8B63D0
#define CListWnd__GetItemData_x                                    0x8B4610
#define CListWnd__GetItemHeight_x                                  0x8B5BB0
#define CListWnd__GetItemIcon_x                                    0x8B47F0
#define CListWnd__GetItemRect_x                                    0x8B61A0
#define CListWnd__GetItemText_x                                    0x8B46A0
#define CListWnd__GetSelList_x                                     0x8B9360
#define CListWnd__GetSeparatorRect_x                               0x8B6990
#define CListWnd__RemoveLine_x                                     0x8B92E0
#define CListWnd__SetColors_x                                      0x8B4410
#define CListWnd__SetColumnJustification_x                         0x8B4EA0
#define CListWnd__SetColumnWidth_x                                 0x8B4B80
#define CListWnd__SetCurSel_x                                      0x8B4300
#define CListWnd__SetItemColor_x                                   0x8B87A0
#define CListWnd__SetItemData_x                                    0x8B52C0
#define CListWnd__SetItemText_x                                    0x8B85E0
#define CListWnd__ShiftColumnSeparator_x                           0x8B8470
#define CListWnd__Sort_x                                           0x8B9D60
#define CListWnd__ToggleSel_x                                      0x8B5190

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70C5E0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72D930
#define CMerchantWnd__RequestBuyItem_x                             0x734750
#define CMerchantWnd__RequestSellItem_x                            0x7351A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x72DBE0
#define CMerchantWnd__SelectBuySellSlot_x                          0x72CE40
#define CMerchantWnd__ActualSelect_x                               0x731680

// CObfuscator
#define CObfuscator__doit_x                                        0x8604F0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D8150
#define CSidlManager__CreateLabel_x                                0x795FF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x657E50
#define CSidlScreenWnd__CalculateVSBRange_x                        0x657D80
#define CSidlScreenWnd__ConvertToRes_x                             0x8F37A0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CFCC0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D11C0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D1270
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D0730
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CF670
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CEDB0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CF860
#define CSidlScreenWnd__Init1_x                                    0x8D0E90
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CFD70
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CEF70
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D0980
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CE880
#define CSidlScreenWnd__StoreIniVis_x                              0x8CED40
#define CSidlScreenWnd__WndNotification_x                          0x8D0C10
#define CSidlScreenWnd__GetChildItem_x                             0x8CEE80
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C22D0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F2DF0
#define CSkillMgr__GetSkillCap_x                                   0x5F2FB0
#define CSkillMgr__GetNameToken_x                                  0x5F2A10

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F2A50
#define CSliderWnd__SetValue_x                                     0x8F2C20
#define CSliderWnd__SetNumTicks_x                                  0x8F33A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79DD50

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8ED420
#define CStmlWnd__CalculateHSBRange_x                              0x8E5930
#define CStmlWnd__CalculateVSBRange_x                              0x8E59C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E5B40
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E6420
#define CStmlWnd__ForceParseNow_x                                  0x8EDD70
#define CStmlWnd__GetNextTagPiece_x                                0x8E6320
#define CStmlWnd__GetSTMLText_x                                    0x68F040
#define CStmlWnd__GetVisibleText_x                                 0x8E6E70
#define CStmlWnd__InitializeWindowVariables_x                      0x8E9200
#define CStmlWnd__MakeStmlColorTag_x                               0x8E4C30
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E4C90
#define CStmlWnd__SetSTMLText_x                                    0x8EAA60
#define CStmlWnd__StripFirstSTMLLines_x                            0x8ED0C0
#define CStmlWnd__UpdateHistoryString_x                            0x8E7DB0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F4FA0
#define CTabWnd__DrawCurrentPage_x                                 0x8F4810
#define CTabWnd__DrawTab_x                                         0x8F45D0
#define CTabWnd__GetCurrentPage_x                                  0x8F4BE0
#define CTabWnd__GetPageInnerRect_x                                0x8F42C0
#define CTabWnd__GetTabInnerRect_x                                 0x8F44C0
#define CTabWnd__GetTabRect_x                                      0x8F4390
#define CTabWnd__InsertPage_x                                      0x8F5290
#define CTabWnd__SetPage_x                                         0x8F4C10
#define CTabWnd__SetPageRect_x                                     0x8F4EE0
#define CTabWnd__UpdatePage_x                                      0x8F5230

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431D30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CC9E0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FA180

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B2270

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4022A0
#define CXStr__CXStr1_x                                            0x73F890
#define CXStr__CXStr3_x                                            0x896CF0
#define CXStr__dCXStr_x                                            0x6A9E20
#define CXStr__operator_equal_x                                    0x896E60
#define CXStr__operator_equal1_x                                   0x896EB0
#define CXStr__operator_plus_equal1_x                              0x897F90

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C14E0
#define CXWnd__Center_x                                            0x8C76C0
#define CXWnd__ClrFocus_x                                          0x8C10D0
#define CXWnd__DoAllDrawing_x                                      0x8C7310
#define CXWnd__DrawChildren_x                                      0x8C74B0
#define CXWnd__DrawColoredRect_x                                   0x8C18A0
#define CXWnd__DrawTooltip_x                                       0x8C1B50
#define CXWnd__DrawTooltipAtPoint_x                                0x8C6290
#define CXWnd__GetBorderFrame_x                                    0x8C1FA0
#define CXWnd__GetChildWndAt_x                                     0x8C8080
#define CXWnd__GetClientClipRect_x                                 0x8C1D70
#define CXWnd__GetScreenClipRect_x                                 0x8C6990
#define CXWnd__GetScreenRect_x                                     0x8C2170
#define CXWnd__GetTooltipRect_x                                    0x8C19E0
#define CXWnd__GetWindowTextA_x                                    0x423100
#define CXWnd__IsActive_x                                          0x8BCA70
#define CXWnd__IsDescendantOf_x                                    0x8C1EE0
#define CXWnd__IsReallyVisible_x                                   0x8C52A0
#define CXWnd__IsType_x                                            0x8F69A0
#define CXWnd__Move_x                                              0x8C49C0
#define CXWnd__Move1_x                                             0x8C6FB0
#define CXWnd__ProcessTransition_x                                 0x8C1490
#define CXWnd__Refade_x                                            0x8C1270
#define CXWnd__Resize_x                                            0x8C2240
#define CXWnd__Right_x                                             0x8C6790
#define CXWnd__SetFocus_x                                          0x8C3B00
#define CXWnd__SetFont_x                                           0x8C1120
#define CXWnd__SetKeyTooltip_x                                     0x8C24A0
#define CXWnd__SetMouseOver_x                                      0x8C6C90
#define CXWnd__StartFade_x                                         0x8C1530
#define CXWnd__GetChildItem_x                                      0x8C6BD0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BE3B0
#define CXWndManager__DrawWindows_x                                0x8BDFF0
#define CXWndManager__GetKeyboardFlags_x                           0x8BC5A0
#define CXWndManager__HandleKeyboardMsg_x                          0x8BCF10
#define CXWndManager__RemoveWnd_x                                  0x8BCC00

// CDBStr
#define CDBStr__GetString_x                                        0x4A4510

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E2C0
#define EQ_Character__Cur_HP_x                                     0x463800
#define EQ_Character__GetAACastingTimeModifier_x                   0x4461B0
#define EQ_Character__GetCharInfo2_x                               0x86AD80
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43E140
#define EQ_Character__GetFocusRangeModifier_x                      0x43E330
#define EQ_Character__Max_Endurance_x                              0x5BA6D0
#define EQ_Character__Max_HP_x                                     0x459490
#define EQ_Character__Max_Mana_x                                   0x5BA500
#define EQ_Character__doCombatAbility_x                            0x5B7AE0
#define EQ_Character__UseSkill_x                                   0x46ED00
#define EQ_Character__GetConLevel_x                                0x5ACB90
#define EQ_Character__IsExpansionFlag_x                            0x422620
#define EQ_Character__TotalEffect_x                                0x44B560

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58D220
#define EQ_Item__CreateItemTagString_x                             0x84A5A0
#define EQ_Item__IsStackable_x                                     0x83E9B0
#define EQ_Item__GetImageNum_x                                     0x841660
#define EQ_Item__CreateItemClient_x                                0x58DDC0
#define EQ_Item__GetItemValue_x                                    0x849250
#define EQ_Item__ValueSellMerchant_x                               0x84B900

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C4230
#define EQ_LoadingS__Array_x                                       0xC12A20

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BBE60
#define EQ_PC__GetAlternateAbilityId_x                             0x853880
#define EQ_PC__GetCombatAbility_x                                  0x853910
#define EQ_PC__GetCombatAbilityTimer_x                             0x84E870
#define EQ_PC__GetItemTimerValue_x                                 0x5B58C0
#define EQ_PC__HasLoreItem_x                                       0x5AFEE0
#define EQ_PC__AlertInventoryChanged_x                             0x5ACB60
#define EQ_PC__GetPcZoneClient_x                                   0x5D63F0
#define EQ_PC__RemoveMyAffect_x									   0x5B4DD0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x509B90
#define EQItemList__add_item_x                                     0x509AD0
#define EQItemList__delete_item_x                                  0x509F90
#define EQItemList__FreeItemList_x                                 0x509E90

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A3740

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C13F0
#define EQPlayer__dEQPlayer_x                                      0x5CA270
#define EQPlayer__DoAttack_x                                       0x5DC300
#define EQPlayer__EQPlayer_x                                       0x5CC690
#define EQPlayer__SetNameSpriteState_x                             0x5C6F40
#define EQPlayer__SetNameSpriteTint_x                              0x5C2800
#define EQPlayer__IsBodyType_j_x                                   0x927830
#define EQPlayer__IsTargetable_x                                   0x928130
#define EQPlayer__CanSee_x                                         0x928650
#define PlayerZoneClient__ChangeHeight_x                           0x5DC1C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D09A0
#define EQPlayerManager__GetSpawnByName_x                          0x5D0E00

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x593290
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5932D0
#define KeypressHandler__ClearCommandStateArray_x                  0x592E70
#define KeypressHandler__HandleKeyDown_x                           0x5917D0
#define KeypressHandler__HandleKeyUp_x                             0x591AF0
#define KeypressHandler__SaveKeymapping_x                          0x592F40

// MapViewMap 
#define MapViewMap__Clear_x                                        0x7049C0
#define MapViewMap__SaveEx_x                                       0x7082A0

#define PlayerPointManager__GetAltCurrency_x                       0x865D10

// StringTable 
#define StringTable__getString_x                                   0x860790

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BA180
#define PcZoneClient__RemovePetEffect_x                            0x5B5AF0

//Doors
#define EQSwitch__UseSwitch_x                                      0x548440

//IconCache
#define IconCache__GetIcon_x                                       0x69F840

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x6966B0
#define CContainerMgr__CloseContainer_x                            0x696ED0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x766200

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5865B0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DA270
#define EQ_Spell__SpellAffects_x                                   0x4DA310
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DA340
#define CharacterZoneClient__CalcAffectChange_x                    0x4475A0
#define CLootWnd__LootAll_x                                        0x6FA2F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7ABCA0
#define CTargetWnd__WndNotification_x                              0x7AB790

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B0E70

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D3B60

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x493A40

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E1220
#define CSidlManager__FindAnimation1_x                             0x8D6040

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CB7D0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CB780
#define CAltAbilityData__GetMaxRank_x                              0x4C0800
