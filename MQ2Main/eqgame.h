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
#if defined(LIVE)
#include "eqgame-private(live).h"
#elif defined(TEST)
#include "eqgame-private(test).h"
#endif
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Jun 10 2016"
#define __ExpectedVersionTime                                     "11:09:34"
#define __ActualVersionDate_x                                      0xACD0B8
#define __ActualVersionTime_x                                      0xACD0C4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59CE60
#define __MemChecker1_x                                            0x8958E0
#define __MemChecker2_x                                            0x632F90
#define __MemChecker3_x                                            0x632EE0
#define __MemChecker4_x                                            0x7E4AF0
#define __EncryptPad0_x                                            0xC6B840
#define __EncryptPad1_x                                            0xDF6140
#define __EncryptPad2_x                                            0xCB4300
#define __EncryptPad3_x                                            0xCB3F00
#define __EncryptPad4_x                                            0xDCCED0
#define __EncryptPad5_x                                            0x11A6900
#define __AC1_x                                                    0x7A4935
#define __AC2_x                                                    0x556FE7
#define __AC3_x                                                    0x555180
#define __AC4_x                                                    0x567990
#define __AC5_x                                                    0x57A4DB
#define __AC6_x                                                    0x57E09E
#define __AC7_x                                                    0x574BAC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1EDE7C

// Direct Input
#define DI8__Main_x                                                0x11A68D8
#define DI8__Keyboard_x                                            0x11A68DC
#define DI8__Mouse_x                                               0x11A68E0
#define DI8__Mouse_Copy_x                                          0x101502C
#define DI8__Mouse_Check_x                                         0x109E7C4
#define __Attack_x                                                 0x1099507
#define __Autofire_x                                               0x1099508
#define __BindList_x                                               0xC2D480
#define g_eqCommandStates_x                                        0x1004490
#define __Clicks_x                                                 0x10150E8
#define __CommandList_x                                            0xC31850
#define __CurrentMapLabel_x                                        0x11AC330
#define __CurrentSocial_x                                          0xBE3FB8
#define __DoAbilityList_x                                          0x104B7BC
#define __do_loot_x                                                0x51BD40
#define __DrawHandler_x                                            0x1812D8C
#define __GroupCount_x                                             0x1005A5A

#define __Guilds_x                                                 0x100B670
#define __gWorld_x                                                 0x1007F14
#define __HotkeyPage_x                                             0x10921BC
#define __HWnd_x                                                   0x109E7E0
#define __InChatMode_x                                             0x1015014
#define __LastTell_x                                               0x1016EB8
#define __LMouseHeldTime_x                                         0x1015154
#define __Mouse_x                                                  0x11A68E4
#define __MouseLook_x                                              0x10150AE
#define __MouseEventTime_x                                         0x1099D0C
#define __gpbCommandEvent_x                                        0x1007FDC
#define __NetStatusToggle_x                                        0x10150B1
#define __PCNames_x                                                0x10164D8
#define __RangeAttackReady_x                                       0x1016214
#define __RMouseHeldTime_x                                         0x1015150
#define __RunWalkState_x                                           0x1015018
#define __ScreenMode_x                                             0xF54210
#define __ScreenX_x                                                0x1014FCC
#define __ScreenY_x                                                0x1014FC8
#define __ScreenXMax_x                                             0x1014FD0
#define __ScreenYMax_x                                             0x1014FD4
#define __ServerHost_x                                             0x10059A4
#define __ServerName_x                                             0x104B77C
#define __ShiftKeyDown_x                                           0x10156A0
#define __ShowNames_x                                              0x10163D4
#define __Socials_x                                                0x104B87C
#define __SubscriptionType_x                                       0x11DA3F0
#define __TargetAggroHolder_x                                      0x11AE56C
#define __ZoneType_x                                               0x10154AC
#define __GroupAggro_x                                             0x11AE5AC
#define __LoginName_x                                              0x109D3BC
#define __Inviter_x                                                0x1099484
#define __AttackOnAssist_x                                         0x1016390

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x1008000
#define instEQZoneInfo_x                                           0x10152A4
#define instKeypressHandler_x                                      0x1099CF0
#define pinstActiveBanker_x                                        0x1007FB8
#define pinstActiveCorpse_x                                        0x1007FBC
#define pinstActiveGMaster_x                                       0x1007FC0
#define pinstActiveMerchant_x                                      0x1007FB4
#define pinstAggroInfo_x                                           0xE11D68
#define pinstAltAdvManager_x                                       0xF552D0
#define pinstAuraMgr_x                                             0xE224D8
#define pinstBandageTarget_x                                       0x1007FA0
#define pinstCamActor_x                                            0xF54C24
#define pinstCDBStr_x                                              0xF541A4
#define pinstCDisplay_x                                            0x1007FC8
#define pinstCEverQuest_x                                          0x11A6A58
#define pinstCharData_x                                            0x1007F84
#define pinstCharSpawn_x                                           0x1007FAC
#define pinstControlledMissile_x                                   0x1007F80
#define pinstControlledPlayer_x                                    0x1007FAC
#define pinstCSidlManager_x                                        0x18122CC
#define pinstCXWndManager_x                                        0x18122C4
#define instDynamicZone_x                                          0x1014E60
#define pinstDZMember_x                                            0x1014F70
#define pinstDZTimerInfo_x                                         0x1014F74
#define pinstEQItemList_x                                          0x10046E0
#define pinstEQObjectList_x                                        0x1005454
#define instEQMisc_x                                               0xC07CF8
#define pinstEQSoundManager_x                                      0xF55828
#define instExpeditionLeader_x                                     0x1014EAA
#define instExpeditionName_x                                       0x1014EEA
#define pinstGroup_x                                               0x1005A56
#define pinstImeManager_x                                          0x18122D0
#define pinstLocalPlayer_x                                         0x1007F98
#define pinstMercenaryData_x                                       0x109A340
#define pinstMercenaryStats_x                                      0x11AE6B8
#define pinstMercAltAbilities_x                                    0xF55658
#define pinstModelPlayer_x                                         0x1007FC4
#define pinstPCData_x                                              0x1007F84
#define pinstSkillMgr_x                                            0x109B178
#define pinstSpawnManager_x                                        0x109AA60
#define pinstSpellManager_x                                        0x109B2C0
#define pinstSpellSets_x                                           0x1092220
#define pinstStringTable_x                                         0x1007F2C
#define pinstSwitchManager_x                                       0x10055E8
#define pinstTarget_x                                              0x1007FB0
#define pinstTargetObject_x                                        0x1007F88
#define pinstTargetSwitch_x                                        0x1007F8C
#define pinstTaskMember_x                                          0xF540F0
#define pinstTrackTarget_x                                         0x1007FA4
#define pinstTradeTarget_x                                         0x1007F94
#define instTributeActive_x                                        0xC07D1D
#define pinstViewActor_x                                           0xF54C20
#define pinstWorldData_x                                           0x1007F68
#define pinstZoneAddr_x                                            0x1015544
#define pinstPlayerPath_x                                          0x109AAC0
#define pinstTargetIndicator_x                                     0x109B458
#define pinstCTargetManager_x                                      0x109B4B8

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE12260
#define pinstCAudioTriggersWindow_x                                0xE120F0
#define pinstCCharacterSelect_x                                    0xF54AB4
#define pinstCFacePick_x                                           0xF54864
#define pinstCNoteWnd_x                                            0xF54A6C
#define pinstCBookWnd_x                                            0xF54A74
#define pinstCPetInfoWnd_x                                         0xF54A78
#define pinstCTrainWnd_x                                           0xF54A7C
#define pinstCSkillsWnd_x                                          0xF54A80
#define pinstCSkillsSelectWnd_x                                    0xF54A84
#define pinstCCombatSkillsSelectWnd_x                              0xF54A88
#define pinstCFriendsWnd_x                                         0xF54A8C
#define pinstCAuraWnd_x                                            0xF54A90
#define pinstCRespawnWnd_x                                         0xF54A94
#define pinstCBandolierWnd_x                                       0xF54A98
#define pinstCPotionBeltWnd_x                                      0xF54A9C
#define pinstCAAWnd_x                                              0xF54AA0
#define pinstCGroupSearchFiltersWnd_x                              0xF54AA4
#define pinstCLoadskinWnd_x                                        0xF54AA8
#define pinstCAlarmWnd_x                                           0xF54AAC
#define pinstCMusicPlayerWnd_x                                     0xF54AB0
#define pinstCMailWnd_x                                            0xF54AB8
#define pinstCMailCompositionWnd_x                                 0xF54ABC
#define pinstCMailAddressBookWnd_x                                 0xF54AC0
#define pinstCRaidWnd_x                                            0xF54AC8
#define pinstCRaidOptionsWnd_x                                     0xF54ACC
#define pinstCBreathWnd_x                                          0xF54AD0
#define pinstCMapViewWnd_x                                         0xF54AD4
#define pinstCMapToolbarWnd_x                                      0xF54AD8
#define pinstCEditLabelWnd_x                                       0xF54ADC
#define pinstCTargetWnd_x                                          0xF54AE0
#define pinstCColorPickerWnd_x                                     0xF54AE4
#define pinstCPlayerWnd_x                                          0xF54AE8
#define pinstCOptionsWnd_x                                         0xF54AEC
#define pinstCBuffWindowNORMAL_x                                   0xF54AF0
#define pinstCBuffWindowSHORT_x                                    0xF54AF4
#define pinstCharacterCreation_x                                   0xF54AF8
#define pinstCCursorAttachment_x                                   0xF54AFC
#define pinstCCastingWnd_x                                         0xF54B00
#define pinstCCastSpellWnd_x                                       0xF54B04
#define pinstCSpellBookWnd_x                                       0xF54B08
#define pinstCInventoryWnd_x                                       0xF54B0C
#define pinstCBankWnd_x                                            0xF54B14
#define pinstCQuantityWnd_x                                        0xF54B18
#define pinstCLootWnd_x                                            0xF54B1C
#define pinstCActionsWnd_x                                         0xF54B20
#define pinstCCombatAbilityWnd_x                                   0xF54B24
#define pinstCMerchantWnd_x                                        0xF54B28
#define pinstCTradeWnd_x                                           0xF54B2C
#define pinstCSelectorWnd_x                                        0xF54B30
#define pinstCBazaarWnd_x                                          0xF54B34
#define pinstCBazaarSearchWnd_x                                    0xF54B38
#define pinstCGiveWnd_x                                            0xF54B54
#define pinstCTrackingWnd_x                                        0xF54B5C
#define pinstCInspectWnd_x                                         0xF54B60
#define pinstCSocialEditWnd_x                                      0xF54B64
#define pinstCFeedbackWnd_x                                        0xF54B68
#define pinstCBugReportWnd_x                                       0xF54B6C
#define pinstCVideoModesWnd_x                                      0xF54B70
#define pinstCTextEntryWnd_x                                       0xF54B78
#define pinstCFileSelectionWnd_x                                   0xF54B7C
#define pinstCCompassWnd_x                                         0xF54B80
#define pinstCPlayerNotesWnd_x                                     0xF54B84
#define pinstCGemsGameWnd_x                                        0xF54B88
#define pinstCTimeLeftWnd_x                                        0xF54B8C
#define pinstCPetitionQWnd_x                                       0xF54BA8
#define pinstCSoulmarkWnd_x                                        0xF54BAC
#define pinstCStoryWnd_x                                           0xF54BB0
#define pinstCJournalTextWnd_x                                     0xF54BB4
#define pinstCJournalCatWnd_x                                      0xF54BB8
#define pinstCBodyTintWnd_x                                        0xF54BBC
#define pinstCServerListWnd_x                                      0xF54BC0
#define pinstCAvaZoneWnd_x                                         0xF54BCC
#define pinstCBlockedBuffWnd_x                                     0xF54BD0
#define pinstCBlockedPetBuffWnd_x                                  0xF54BD4
#define pinstCInvSlotMgr_x                                         0xF54C18
#define pinstCContainerMgr_x                                       0xF54C1C
#define pinstCAdventureLeaderboardWnd_x                            0x11A7408
#define pinstCAdventureRequestWnd_x                                0x11A7480
#define pinstCAltStorageWnd_x                                      0x11A7760
#define pinstCAdventureStatsWnd_x                                  0x11A74F8
#define pinstCBarterMerchantWnd_x                                  0x11A8348
#define pinstCBarterSearchWnd_x                                    0x11A83C0
#define pinstCBarterWnd_x                                          0x11A8438
#define pinstCChatManager_x                                        0x11A8AC8
#define pinstCDynamicZoneWnd_x                                     0x11A8F78
#define pinstCEQMainWnd_x                                          0x11A9110
#define pinstCFellowshipWnd_x                                      0x11A8F0C
#define pinstCFindLocationWnd_x                                    0x11A93E0
#define pinstCGroupSearchWnd_x                                     0x11A96B0
#define pinstCGroupWnd_x                                           0x11A9728
#define pinstCGuildBankWnd_x                                       0x11A97A0
#define pinstCGuildMgmtWnd_x                                       0x11AB890
#define pinstCHotButtonWnd_x                                       0x11AB95C
#define pinstCHotButtonWnd1_x                                      0x11AB95C
#define pinstCHotButtonWnd2_x                                      0x11AB960
#define pinstCHotButtonWnd3_x                                      0x11AB964
#define pinstCHotButtonWnd4_x                                      0x11AB988
#define pinstCItemDisplayManager_x                                 0x11ABC80
#define pinstCItemExpTransferWnd_x                                 0x11ABCFC
#define pinstCLFGuildWnd_x                                         0x11ABFD8
#define pinstCMIZoneSelectWnd_x                                    0x11AC5C0
#define pinstCConfirmationDialog_x                                 0x11ACCC8
#define pinstCPopupWndManager_x                                    0x11ACCC8
#define pinstCProgressionSelectionWnd_x                            0x11ACDB8
#define pinstCPvPStatsWnd_x                                        0x11ACEA8
#define pinstCSystemInfoDialogBox_x                                0x11AD5B0
#define pinstCTaskWnd_x                                            0x11AE978
#define pinstCTaskSomething_x                                      0xE22C98
#define pinstCTaskTemplateSelectWnd_x                              0x11AE900
#define pinstCTipWndOFDAY_x                                        0x11AEAE0
#define pinstCTipWndCONTEXT_x                                      0x11AEAE4
#define pinstCTitleWnd_x                                           0x11AEB60
#define pinstCContextMenuManager_x                                 0x181223C
#define pinstCVoiceMacroWnd_x                                      0x109B890
#define pinstCHtmlWnd_x                                            0x109B980
#define pinstIconCache_x                                           0x11A90E4
#define pinstCTradeskillWnd_x                                      0x11AEC60
#define pinstCAdvancedLootWnd_x                                    0xF54C0C
#define pinstRewardSelectionWnd_x                                  0x11AD3D0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x532EA0
#define __ConvertItemTags_x                                        0x5208A0
#define __ExecuteCmd_x                                             0x50B230
#define __EQGetTime_x                                              0x895510
#define __get_melee_range_x                                        0x511DF0
#define __GetGaugeValueFromEQ_x                                    0x7A3670
#define __GetLabelFromEQ_x                                         0x7A48C0
#define __ToggleKeyRingItem_x                                      0x47E2A0
#define __GetXTargetType_x                                         0x925FF0
#define __LoadFrontEnd_x                                           0x632660
#define __NewUIINI_x                                               0x7A3050
#define __ProcessGameEvents_x                                      0x576900
#define __ProcessMouseEvent_x                                      0x5760A0
#define CrashDetected_x                                            0x634020
#define wwsCrashReportCheckForUploader_x                           0x7F3470
#define DrawNetStatus_x                                            0x5ACB20
#define Util__FastTime_x                                           0x895020
#define Expansion_HoT_x                                            0x1016380
#define __HelpPath_x                                               0x1099A78
#define __STMLToText_x                                             0x8DAE00

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x420640
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B490
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41B270

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C52D0
#define AltAdvManager__IsAbilityReady_x                            0x4C5340
#define AltAdvManager__GetAAById_x                                 0x4C5700
#define AltAdvManager__CanTrainAbility_x                           0x4C5FC0
#define AltAdvManager__CanSeeAbility_x                             0x4C5BC0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463060
#define CharacterZoneClient__MakeMeVisible_x                       0x468960
#define CharacterZoneClient__IsStackBlocked_x                      0x4473E0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x4468A0
#define CharacterZoneClient__GetItemCountWorn_x                    0x460A80
#define CharacterZoneClient__GetItemCountInInventory_x             0x460B60
#define CharacterZoneClient__GetCursorItemCount_x                  0x460C40

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x662190

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x670110

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58BE60
#define CButtonWnd__CButtonWnd_x                                   0x8CF180

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68B530
#define CChatManager__InitContextMenu_x                            0x68C0B0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D9170
#define CContextMenu__dCContextMenu_x                              0x8D9380
#define CContextMenu__AddMenuItem_x                                0x8D9390
#define CContextMenu__RemoveMenuItem_x                             0x8D9670
#define CContextMenu__RemoveAllMenuItems_x                         0x8D9690
#define CContextMenuManager__AddMenu_x                             0x8C5800
#define CContextMenuManager__RemoveMenu_x                          0x8C5B50
#define CContextMenuManager__PopupMenu_x                           0x8C5FA0
#define CContextMenuManager__Flush_x                               0x8C5870
#define CContextMenuManager__GetMenu_x                             0x416AC0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87A0E0
#define CChatService__GetFriendName_x                              0x87A0F0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x691300
#define CChatWindow__Clear_x                                       0x690ED0
#define CChatWindow__WndNotification_x                             0x691830

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C95C0
#define CComboWnd__Draw_x                                          0x8C97D0
#define CComboWnd__GetCurChoice_x                                  0x8C9390
#define CComboWnd__GetListRect_x                                   0x8C9A70
#define CComboWnd__GetTextRect_x                                   0x8C9630
#define CComboWnd__InsertChoice_x                                  0x8C9AE0
#define CComboWnd__SetColors_x                                     0x8C9320
#define CComboWnd__SetChoice_x                                     0x8C9350
#define CComboWnd__GetItemCount_x                                  0x8C9380
#define CComboWnd__GetCurChoiceText_x                              0x8C93D0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69A840
#define CContainerWnd__vftable_x                                   0xAD6A90

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B36B0
#define CDisplay__GetClickedActor_x                                0x4ABF70
#define CDisplay__GetUserDefinedColor_x                            0x4AAB50
#define CDisplay__GetWorldFilePath_x                               0x4A9FA0
#define CDisplay__is3dON_x                                         0x4A9430
#define CDisplay__ReloadUI_x                                       0x4BEBA0
#define CDisplay__WriteTextHD2_x                                   0x4AFA00

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8EF7D0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DD690
#define CEditWnd__GetCharIndexPt_x                                 0x8DE710
#define CEditWnd__GetDisplayString_x                               0x8DD840
#define CEditWnd__GetHorzOffset_x                                  0x8DDB80
#define CEditWnd__GetLineForPrintableChar_x                        0x8DE1E0
#define CEditWnd__GetSelStartPt_x                                  0x8DE9C0
#define CEditWnd__GetSTMLSafeText_x                                0x8DDD10
#define CEditWnd__PointFromPrintableChar_x                         0x8DE2D0
#define CEditWnd__SelectableCharFromPoint_x                        0x8DE450
#define CEditWnd__SetEditable_x                                    0x8DDCE0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x557730
#define CEverQuest__CreateTargetIndicator_x                        0x558620
#define CEverQuest__DeleteTargetIndicator_x                        0x5586A0
#define CEverQuest__DoTellWindow_x                                 0x4735F0
#define CEverQuest__DropHeldItemOnGround_x                         0x56E7D0
#define CEverQuest__dsp_chat_x                                     0x473930
#define CEverQuest__trimName_x                                     0x554080
#define CEverQuest__Emote_x                                        0x56CB20
#define CEverQuest__EnterZone_x                                    0x567B20
#define CEverQuest__GetBodyTypeDesc_x                              0x551AE0
#define CEverQuest__GetClassDesc_x                                 0x55B3B0
#define CEverQuest__GetClassThreeLetterCode_x                      0x55B9B0
#define CEverQuest__GetDeityDesc_x                                 0x5523C0
#define CEverQuest__GetLangDesc_x                                  0x551E70
#define CEverQuest__GetRaceDesc_x                                  0x55BB70
#define CEverQuest__InterpretCmd_x                                 0x55F980
#define CEverQuest__LeftClickedOnPlayer_x                          0x573000
#define CEverQuest__LMouseUp_x                                     0x5750F0
#define CEverQuest__RightClickedOnPlayer_x                         0x573B10
#define CEverQuest__RMouseUp_x                                     0x574B60
#define CEverQuest__SetGameState_x                                 0x557FF0
#define CEverQuest__UPCNotificationFlush_x                         0x54F900
#define CEverQuest__IssuePetCommand_x                              0x560360

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AB410
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AB470
#define CGaugeWnd__Draw_x                                          0x6AB8A0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4371D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C77C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D4880
#define CInvSlotMgr__MoveItem_x                                    0x6D5720
#define CInvSlotMgr__SelectSlot_x                                  0x6D4930

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D3D30
#define CInvSlot__SliderComplete_x                                 0x6D15A0
#define CInvSlot__GetItemBase_x                                    0x6D0A30

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D6B70

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x79F070
#define CItemDisplayWnd__UpdateStrings_x                           0x6D8CA0

// CLabel 
#define CLabel__Draw_x                                             0x6F2320

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B5600
#define CListWnd__dCListWnd_x                                      0x8B6620
#define CListWnd__AddColumn_x                                      0x8B65C0
#define CListWnd__AddColumn1_x                                     0x8B5E30
#define CListWnd__AddLine_x                                        0x8B58B0
#define CListWnd__AddString_x                                      0x8B5AC0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B2970
#define CListWnd__CalculateVSBRange_x                              0x8B4AC0
#define CListWnd__ClearSel_x                                       0x8B1C80
#define CListWnd__ClearAllSel_x                                    0x8B1C30
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B5490
#define CListWnd__Compare_x                                        0x8B3460
#define CListWnd__Draw_x                                           0x8B46D0
#define CListWnd__DrawColumnSeparators_x                           0x8B4560
#define CListWnd__DrawHeader_x                                     0x8B1F40
#define CListWnd__DrawItem_x                                       0x8B3AA0
#define CListWnd__DrawLine_x                                       0x8B4200
#define CListWnd__DrawSeparator_x                                  0x8B4600
#define CListWnd__EnsureVisible_x                                  0x8B2AD0
#define CListWnd__ExtendSel_x                                      0x8B39B0
#define CListWnd__GetColumnMinWidth_x                              0x8B15F0
#define CListWnd__GetColumnWidth_x                                 0x8B1510
#define CListWnd__GetCurSel_x                                      0x8B0CE0
#define CListWnd__GetItemAtPoint_x                                 0x8B2D50
#define CListWnd__GetItemAtPoint1_x                                0x8B2DC0
#define CListWnd__GetItemData_x                                    0x8B1020
#define CListWnd__GetItemHeight_x                                  0x8B25D0
#define CListWnd__GetItemIcon_x                                    0x8B1200
#define CListWnd__GetItemRect_x                                    0x8B2B90
#define CListWnd__GetItemText_x                                    0x8B10B0
#define CListWnd__GetSelList_x                                     0x8B5D20
#define CListWnd__GetSeparatorRect_x                               0x8B3380
#define CListWnd__RemoveLine_x                                     0x8B5CA0
#define CListWnd__SetColors_x                                      0x8B0E30
#define CListWnd__SetColumnJustification_x                         0x8B18C0
#define CListWnd__SetColumnWidth_x                                 0x8B15A0
#define CListWnd__SetCurSel_x                                      0x8B0D20
#define CListWnd__SetItemColor_x                                   0x8B5170
#define CListWnd__SetItemData_x                                    0x8B1CE0
#define CListWnd__SetItemText_x                                    0x8B4FB0
#define CListWnd__ShiftColumnSeparator_x                           0x8B4E40
#define CListWnd__Sort_x                                           0x8B6720
#define CListWnd__ToggleSel_x                                      0x8B1BB0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70B2B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72C720
#define CMerchantWnd__RequestBuyItem_x                             0x733790
#define CMerchantWnd__RequestSellItem_x                            0x734260
#define CMerchantWnd__SelectRecoverySlot_x                         0x72C9D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x72BBD0
#define CMerchantWnd__ActualSelect_x                               0x730680

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x846920
#define CPacketScrambler__hton_x                                   0x846930

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D41A0
#define CSidlManager__CreateLabel_x                                0x794FD0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x659550
#define CSidlScreenWnd__CalculateVSBRange_x                        0x659480
#define CSidlScreenWnd__ConvertToRes_x                             0x8EF6B0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CBF10
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CD0D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CD180
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CC660
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CB8C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CB040
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CBAB0
#define CSidlScreenWnd__Init1_x                                    0x8CCDB0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CBFC0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CB200
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CC8A0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CACA0
#define CSidlScreenWnd__StoreIniVis_x                              0x8CAFF0
#define CSidlScreenWnd__WndNotification_x                          0x8CCB30
#define CSidlScreenWnd__GetChildItem_x                             0x8CB110
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BEAB0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F7370
#define CSkillMgr__GetSkillCap_x                                   0x5F7530
#define CSkillMgr__GetNameToken_x                                  0x5F6F90

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EE970
#define CSliderWnd__SetValue_x                                     0x8EEB40
#define CSliderWnd__SetNumTicks_x                                  0x8EF2C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79CCE0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EA310
#define CStmlWnd__CalculateHSBRange_x                              0x8E2880
#define CStmlWnd__CalculateVSBRange_x                              0x8E2910
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E2A90
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E3370
#define CStmlWnd__ForceParseNow_x                                  0x8EAC60
#define CStmlWnd__GetNextTagPiece_x                                0x8E3270
#define CStmlWnd__GetSTMLText_x                                    0x690770
#define CStmlWnd__GetVisibleText_x                                 0x8E3DC0
#define CStmlWnd__InitializeWindowVariables_x                      0x8E6140
#define CStmlWnd__MakeStmlColorTag_x                               0x8E1B80
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E1BE0
#define CStmlWnd__SetSTMLText_x                                    0x8E7990
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E9FB0
#define CStmlWnd__UpdateHistoryString_x                            0x8E4D00

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E1220
#define CTabWnd__DrawCurrentPage_x                                 0x8E0AB0
#define CTabWnd__DrawTab_x                                         0x8E0880
#define CTabWnd__GetCurrentPage_x                                  0x8E0E60
#define CTabWnd__GetPageInnerRect_x                                0x8E0570
#define CTabWnd__GetTabInnerRect_x                                 0x8E0770
#define CTabWnd__GetTabRect_x                                      0x8E0640
#define CTabWnd__InsertPage_x                                      0x8E1510
#define CTabWnd__SetPage_x                                         0x8E0E90
#define CTabWnd__SetPageRect_x                                     0x8E1160
#define CTabWnd__UpdatePage_x                                      0x8E14B0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432FD0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C8F90

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F4A90

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AED30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402A10
#define CXStr__CXStr1_x                                            0x403780
#define CXStr__CXStr3_x                                            0x892110
#define CXStr__dCXStr_x                                            0x4731F0
#define CXStr__operator_equal_x                                    0x892280
#define CXStr__operator_equal1_x                                   0x8922D0
#define CXStr__operator_plus_equal1_x                              0x8933D0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BDD60
#define CXWnd__Center_x                                            0x8C3E30
#define CXWnd__ClrFocus_x                                          0x8BD950
#define CXWnd__DoAllDrawing_x                                      0x8C3A80
#define CXWnd__DrawChildren_x                                      0x8C3C20
#define CXWnd__DrawColoredRect_x                                   0x8BE0F0
#define CXWnd__DrawTooltip_x                                       0x8BE390
#define CXWnd__DrawTooltipAtPoint_x                                0x8C29F0
#define CXWnd__GetBorderFrame_x                                    0x8BE7A0
#define CXWnd__GetChildWndAt_x                                     0x8C47E0
#define CXWnd__GetClientClipRect_x                                 0x8BE5B0
#define CXWnd__GetScreenClipRect_x                                 0x8C30E0
#define CXWnd__GetScreenRect_x                                     0x8BE950
#define CXWnd__GetTooltipRect_x                                    0x8BE220
#define CXWnd__GetWindowTextA_x                                    0x424670
#define CXWnd__IsActive_x                                          0x8B93F0
#define CXWnd__IsDescendantOf_x                                    0x8BE6F0
#define CXWnd__IsReallyVisible_x                                   0x8C1A10
#define CXWnd__IsType_x                                            0x8F12F0
#define CXWnd__Move_x                                              0x8C1150
#define CXWnd__Move1_x                                             0x8C3730
#define CXWnd__ProcessTransition_x                                 0x8BDD10
#define CXWnd__Refade_x                                            0x8BDAE0
#define CXWnd__Resize_x                                            0x8BEA20
#define CXWnd__Right_x                                             0x8C2EE0
#define CXWnd__SetFocus_x                                          0x8C02A0
#define CXWnd__SetFont_x                                           0x8BD9A0
#define CXWnd__SetKeyTooltip_x                                     0x8BEC80
#define CXWnd__SetMouseOver_x                                      0x8C3420
#define CXWnd__StartFade_x                                         0x8BDDB0
#define CXWnd__GetChildItem_x                                      0x8C3360

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BAC80
#define CXWndManager__DrawWindows_x                                0x8BA8D0
#define CXWndManager__GetKeyboardFlags_x                           0x8B8F30
#define CXWndManager__HandleKeyboardMsg_x                          0x8B9890
#define CXWndManager__RemoveWnd_x                                  0x8B9580

// CDBStr
#define CDBStr__GetString_x                                        0x4A7990

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44D880
#define EQ_Character__Cur_HP_x                                     0x462750
#define EQ_Character__Cur_Mana_x                                   0x455E70
#define EQ_Character__GetAACastingTimeModifier_x                   0x446BB0
#define EQ_Character__GetCharInfo2_x                               0x8663F0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EE60
#define EQ_Character__GetFocusRangeModifier_x                      0x43EEC0
#define EQ_Character__Max_Endurance_x                              0x5BEFA0
#define EQ_Character__Max_HP_x                                     0x458A90
#define EQ_Character__Max_Mana_x                                   0x5BEDD0
#define EQ_Character__doCombatAbility_x                            0x5BC500
#define EQ_Character__UseSkill_x                                   0x46D9E0
#define EQ_Character__GetConLevel_x                                0x5B1130
#define EQ_Character__IsExpansionFlag_x                            0x423BB0
#define EQ_Character__TotalEffect_x                                0x44AAD0
#define EQ_Character__GetPCSpellAffect_x                           0x446FB0
#define EQ_Character__SpellDuration_x                              0x444EB0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5916F0
#define EQ_Item__CreateItemTagString_x                             0x8452D0
#define EQ_Item__IsStackable_x                                     0x83AD10
#define EQ_Item__GetImageNum_x                                     0x83D7B0
#define EQ_Item__CreateItemClient_x                                0x5922D0
#define EQ_Item__GetItemValue_x                                    0x844040
#define EQ_Item__ValueSellMerchant_x                               0x846580

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C7440
#define EQ_LoadingS__Array_x                                       0xC14530

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C0610
#define EQ_PC__GetAlternateAbilityId_x                             0x84E920
#define EQ_PC__GetCombatAbility_x                                  0x84E9B0
#define EQ_PC__GetCombatAbilityTimer_x                             0x849730
#define EQ_PC__GetItemTimerValue_x                                 0x5BA030
#define EQ_PC__HasLoreItem_x                                       0x5B4610
#define EQ_PC__AlertInventoryChanged_x                             0x5B1100
#define EQ_PC__GetPcZoneClient_x                                   0x5DAC00
#define EQ_PC__RemoveMyAffect_x                                    0x5B94E0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50FE70
#define EQItemList__add_object_x                                   0x53C490
#define EQItemList__add_item_x                                     0x50FDB0
#define EQItemList__delete_item_x                                  0x510260
#define EQItemList__FreeItemList_x                                 0x510160

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A6B70

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C5BD0
#define EQPlayer__dEQPlayer_x                                      0x5CE9F0
#define EQPlayer__DoAttack_x                                       0x5E0910
#define EQPlayer__EQPlayer_x                                       0x5D0E10
#define EQPlayer__SetNameSpriteState_x                             0x5CB990
#define EQPlayer__SetNameSpriteTint_x                              0x5C7010
#define PlayerBase__HasProperty_j_x                                0x9221F0
#define EQPlayer__IsTargetable_x                                   0x922AF0
#define EQPlayer__CanSee_x                                         0x923010
#define PlayerZoneClient__ChangeHeight_x                           0x5E07D0
#define EQPlayer__CanSeeTargetIndicator_x                          0x923100

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D50E0
#define EQPlayerManager__GetSpawnByName_x                          0x5D5540
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D5110

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5977B0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5977F0
#define KeypressHandler__ClearCommandStateArray_x                  0x5973A0
#define KeypressHandler__HandleKeyDown_x                           0x595D00
#define KeypressHandler__HandleKeyUp_x                             0x596020
#define KeypressHandler__SaveKeymapping_x                          0x597470

// MapViewMap 
#define MapViewMap__Clear_x                                        0x703C40
#define MapViewMap__SaveEx_x                                       0x706F70

#define PlayerPointManager__GetAltCurrency_x                       0x8613F0

// StringTable 
#define StringTable__getString_x                                   0x85BC90

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BEA70
#define PcZoneClient__RemovePetEffect_x                            0x5BA500
#define PcZoneClient__HasAlternateAbility_x                        0x5BAFB0
#define PcZoneClient__GetCurrentMod_x                              0x457E30
#define PcZoneClient__GetModCap_x                                  0x455680

//Doors
#define EQSwitch__UseSwitch_x                                      0x54E1C0

//IconCache
#define IconCache__GetIcon_x                                       0x6A0DC0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x697BD0
#define CContainerMgr__CloseContainer_x                            0x6983F0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7650F0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58A900

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DF230
#define EQ_Spell__SpellAffects_x                                   0x4DC8E0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DC950
#define CharacterZoneClient__CalcAffectChange_x                    0x445FE0
#define CLootWnd__LootAll_x                                        0x6F9520

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7ABB30
#define CTargetWnd__WndNotification_x                              0x7AB620
#define CTargetWnd__UpdateBuffs_x                                  0x7ABD10

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B0D10

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D8140

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x496AA0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DCCC0
#define CSidlManager__FindAnimation1_x                             0x8D2090

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CEAB0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CEA60
#define CAltAbilityData__GetMaxRank_x                              0x4C3980

//CTargetRing
#define CTargetRing__Cast_x                                        0x5881D0

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x454720

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x682680
#define CCastSpellWnd__IsBardSongPlaying_x                         0x681DE0

//messages
#define msg_spell_worn_off_x                                       0x4E6CB0
#define msg_new_text_x                                             0x4F0000
#define msgTokenTextParam_x                                        0x4ECB10

//SpellManager
#define SpellManager__vftable_x                                    0xAB2DD8
#define SpellManager__SpellManager_x                               0x47B190
