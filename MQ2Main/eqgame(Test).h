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
#define __ExpectedVersionDate                                     "Oct 27 2015"
#define __ExpectedVersionTime                                     "13:58:37"
#define __ActualVersionDate_x                                      0xAD1E48
#define __ActualVersionTime_x                                      0xAD1E54

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59A590
#define __MemChecker1_x                                            0x89B6E0
#define __MemChecker2_x                                            0x633000
#define __MemChecker3_x                                            0x632F50
#define __MemChecker4_x                                            0x7E8A10
#define __EncryptPad0_x                                            0xC68FE8
#define __EncryptPad1_x                                            0xDF2D98
#define __EncryptPad2_x                                            0xCB2AD0
#define __EncryptPad3_x                                            0xCB26D0
#define __EncryptPad4_x                                            0xDCD248
#define __EncryptPad5_x                                            0x119EB00
#define __AC1_x                                                    0x7A6025
#define __AC2_x                                                    0x54FCB7
#define __AC3_x                                                    0x564470
#define __AC4_x                                                    0x56B0F0
#define __AC5_x                                                    0x576F7E
#define __AC6_x                                                    0x57AA19
#define __AC7_x                                                    0x57162C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data                                                 0x845E8

// Direct Input
#define DI8__Main_x                                                0x119EAD8
#define DI8__Keyboard_x                                            0x119EADC
#define DI8__Mouse_x                                               0x119EAE0
#define DI8__Mouse_Copy_x                                          0x100D0F4
#define DI8__Mouse_Check_x                                         0x10969C4
#define __AltTimerReady_x                                          0xFFE441
#define __Attack_x                                                 0x1091663
#define __Autofire_x                                               0x1091664
#define __BindList_x                                               0xC2B0E0
#define __bCommandEnabled_x                                        0xFFC550
#define __Clicks_x                                                 0x100D1B0
#define __CommandList_x                                            0xC2F450
#define __CurrentMapLabel_x                                        0x11A4530
#define __CurrentSocial_x                                          0xBE4F44
#define __DoAbilityList_x                                          0x1043918
#define __do_loot_x                                                0x5172A0
#define __DrawHandler_x                                            0x180B27C
#define __GroupCount_x                                             0xFFDB1A

#define __Guilds_x                                                 0x1003730
#define __gWorld_x                                                 0xFFFFD4
#define __HotkeyPage_x                                             0x108A318
#define __HWnd_x                                                   0x10969E0
#define __InChatMode_x                                             0x100D0DC
#define __LastTell_x                                               0x100F020
#define __LMouseHeldTime_x                                         0x100D21C
#define __Mouse_x                                                  0x119EAE4
#define __MouseLook_x                                              0x100D176
#define __MouseEventTime_x                                         0x1091E6C
#define __gpbCommandEvent_x                                        0x100009C
#define __NetStatusToggle_x                                        0x100D179
#define __PCNames_x                                                0x100E640
#define __RangeAttackReady_x                                       0x100E300
#define __RMouseHeldTime_x                                         0x100D218
#define __RunWalkState_x                                           0x100D0E0
#define __ScreenMode_x                                             0xF4C308
#define __ScreenX_x                                                0x100D094
#define __ScreenY_x                                                0x100D090
#define __ScreenXMax_x                                             0x100D098
#define __ScreenYMax_x                                             0x100D09C
#define __ServerHost_x                                             0xFFDA64
#define __ServerName_x                                             0x10438D8
#define __ShiftKeyDown_x                                           0x100D784
#define __ShowNames_x                                              0x100E4D4
#define __Socials_x                                                0x10439D8
#define __SubscriptionType_x                                       0x11D2A60
#define __TargetAggroHolder_x                                      0x11A676C
#define __GroupAggro_x                                             0x11A67AC
#define __LoginName_x                                              0x10955B8
#define __Inviter_x                                                0x10915E0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x10000C0
#define instEQZoneInfo_x                                           0x100D36C
#define instKeypressHandler_x                                      0x1091E50
#define pinstActiveBanker_x                                        0x1000078
#define pinstActiveCorpse_x                                        0x100007C
#define pinstActiveGMaster_x                                       0x1000080
#define pinstActiveMerchant_x                                      0x1000074
#define pinstAggroInfo_x                                           0xE0E778
#define pinstAltAdvManager_x                                       0xF4D408
#define pinstAuraMgr_x                                             0xE1A648
#define pinstBandageTarget_x                                       0x1000060
#define pinstCamActor_x                                            0xF4CD10
#define pinstCDBStr_x                                              0xF4C29C
#define pinstCDisplay_x                                            0x1000088
#define pinstCEverQuest_x                                          0x119EC58
#define pinstCharData_x                                            0x1000044
#define pinstCharSpawn_x                                           0x100006C
#define pinstControlledMissile_x                                   0x1000040
#define pinstControlledPlayer_x                                    0x100006C
#define pinstCSidlManager_x                                        0x180A6B4
#define pinstCXWndManager_x                                        0x180A6AC
#define instDynamicZone_x                                          0x100CF28
#define pinstDZMember_x                                            0x100D038
#define pinstDZTimerInfo_x                                         0x100D03C
#define pinstEQItemList_x                                          0xFFC7A0
#define instEQMisc_x                                               0xC05C48
#define pinstEQSoundManager_x                                      0xF4D8E8
#define instExpeditionLeader_x                                     0x100CF72
#define instExpeditionName_x                                       0x100CFB2
#define pinstGroup_x                                               0xFFDB16
#define pinstImeManager_x                                          0x180A6B8
#define pinstLocalPlayer_x                                         0x1000058
#define pinstMercenaryData_x                                       0x10924A0
#define pinstMercenaryStats_x                                      0x11A68B8
#define pinstMercAltAbilities_x                                    0xF4D790
#define pinstModelPlayer_x                                         0x1000084
#define pinstPCData_x                                              0x1000044
#define pinstSkillMgr_x                                            0x10932D8
#define pinstSpawnManager_x                                        0x1092BC0
#define pinstSpellManager_x                                        0x1093420
#define pinstSpellSets_x                                           0x108A37C
#define pinstStringTable_x                                         0xFFFFEC
#define pinstSwitchManager_x                                       0xFFD6A8
#define pinstTarget_x                                              0x1000070
#define pinstTargetObject_x                                        0x1000048
#define pinstTargetSwitch_x                                        0x100004C
#define pinstTaskMember_x                                          0xF4C1E8
#define pinstTrackTarget_x                                         0x1000064
#define pinstTradeTarget_x                                         0x1000054
#define instTributeActive_x                                        0xC05C6D
#define pinstViewActor_x                                           0xF4CD0C
#define pinstWorldData_x                                           0x1000028
#define pinstZoneAddr_x                                            0x100D62C

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE0EC58
#define pinstCAudioTriggersWindow_x                                0xE0EAE8
#define pinstCCharacterSelect_x                                    0xF4CBA8
#define pinstCFacePick_x                                           0xF4CB58
#define pinstCNoteWnd_x                                            0xF4CB60
#define pinstCBookWnd_x                                            0xF4CB68
#define pinstCPetInfoWnd_x                                         0xF4CB6C
#define pinstCTrainWnd_x                                           0xF4CB70
#define pinstCSkillsWnd_x                                          0xF4CB74
#define pinstCSkillsSelectWnd_x                                    0xF4CB78
#define pinstCCombatSkillsSelectWnd_x                              0xF4CB7C
#define pinstCFriendsWnd_x                                         0xF4CB80
#define pinstCAuraWnd_x                                            0xF4CB84
#define pinstCRespawnWnd_x                                         0xF4CB88
#define pinstCBandolierWnd_x                                       0xF4CB8C
#define pinstCPotionBeltWnd_x                                      0xF4CB90
#define pinstCAAWnd_x                                              0xF4CB94
#define pinstCGroupSearchFiltersWnd_x                              0xF4CB98
#define pinstCLoadskinWnd_x                                        0xF4CB9C
#define pinstCAlarmWnd_x                                           0xF4CBA0
#define pinstCMusicPlayerWnd_x                                     0xF4CBA4
#define pinstCMailWnd_x                                            0xF4CBAC
#define pinstCMailCompositionWnd_x                                 0xF4CBB0
#define pinstCMailAddressBookWnd_x                                 0xF4CBB4
#define pinstCRaidWnd_x                                            0xF4CBBC
#define pinstCRaidOptionsWnd_x                                     0xF4CBC0
#define pinstCBreathWnd_x                                          0xF4CBC4
#define pinstCMapViewWnd_x                                         0xF4CBC8
#define pinstCMapToolbarWnd_x                                      0xF4CBCC
#define pinstCEditLabelWnd_x                                       0xF4CBD0
#define pinstCTargetWnd_x                                          0xF4CBD4
#define pinstCColorPickerWnd_x                                     0xF4CBD8
#define pinstCPlayerWnd_x                                          0xF4CBDC
#define pinstCOptionsWnd_x                                         0xF4CBE0
#define pinstCBuffWindowNORMAL_x                                   0xF4CBE4
#define pinstCBuffWindowSHORT_x                                    0xF4CBE8
#define pinstCharacterCreation_x                                   0xF4CBEC
#define pinstCCursorAttachment_x                                   0xF4CBF0
#define pinstCCastingWnd_x                                         0xF4CBF4
#define pinstCCastSpellWnd_x                                       0xF4CBF8
#define pinstCSpellBookWnd_x                                       0xF4CBFC
#define pinstCInventoryWnd_x                                       0xF4CC00
#define pinstCBankWnd_x                                            0xF4CC04
#define pinstCQuantityWnd_x                                        0xF4CC08
#define pinstCLootWnd_x                                            0xF4CC0C
#define pinstCActionsWnd_x                                         0xF4CC10
#define pinstCCombatAbilityWnd_x                                   0xF4CC14
#define pinstCMerchantWnd_x                                        0xF4CC18
#define pinstCTradeWnd_x                                           0xF4CC1C
#define pinstCSelectorWnd_x                                        0xF4CC20
#define pinstCBazaarWnd_x                                          0xF4CC24
#define pinstCBazaarSearchWnd_x                                    0xF4CC28
#define pinstCGiveWnd_x                                            0xF4CC44
#define pinstCTrackingWnd_x                                        0xF4CC4C
#define pinstCInspectWnd_x                                         0xF4CC50
#define pinstCSocialEditWnd_x                                      0xF4CC54
#define pinstCFeedbackWnd_x                                        0xF4CC58
#define pinstCBugReportWnd_x                                       0xF4CC5C
#define pinstCVideoModesWnd_x                                      0xF4CC60
#define pinstCTextEntryWnd_x                                       0xF4CC68
#define pinstCFileSelectionWnd_x                                   0xF4CC6C
#define pinstCCompassWnd_x                                         0xF4CC70
#define pinstCPlayerNotesWnd_x                                     0xF4CC74
#define pinstCGemsGameWnd_x                                        0xF4CC78
#define pinstCTimeLeftWnd_x                                        0xF4CC7C
#define pinstCPetitionQWnd_x                                       0xF4CC94
#define pinstCSoulmarkWnd_x                                        0xF4CC98
#define pinstCStoryWnd_x                                           0xF4CC9C
#define pinstCJournalTextWnd_x                                     0xF4CCA0
#define pinstCJournalCatWnd_x                                      0xF4CCA4
#define pinstCBodyTintWnd_x                                        0xF4CCA8
#define pinstCServerListWnd_x                                      0xF4CCAC
#define pinstCAvaZoneWnd_x                                         0xF4CCB8
#define pinstCBlockedBuffWnd_x                                     0xF4CCBC
#define pinstCBlockedPetBuffWnd_x                                  0xF4CCC0
#define pinstCInvSlotMgr_x                                         0xF4CD04
#define pinstCContainerMgr_x                                       0xF4CD08
#define pinstCAdventureLeaderboardWnd_x                            0x119F608
#define pinstCAdventureRequestWnd_x                                0x119F680
#define pinstCAltStorageWnd_x                                      0x119F960
#define pinstCAdventureStatsWnd_x                                  0x119F6F8
#define pinstCBarterMerchantWnd_x                                  0x11A0548
#define pinstCBarterSearchWnd_x                                    0x11A05C0
#define pinstCBarterWnd_x                                          0x11A0638
#define pinstCChatManager_x                                        0x11A0CC8
#define pinstCDynamicZoneWnd_x                                     0x11A1178
#define pinstCEQMainWnd_x                                          0x11A1310
#define pinstCFellowshipWnd_x                                      0x11A110C
#define pinstCFindLocationWnd_x                                    0x11A15E0
#define pinstCGroupSearchWnd_x                                     0x11A18B0
#define pinstCGroupWnd_x                                           0x11A1928
#define pinstCGuildBankWnd_x                                       0x11A19A0
#define pinstCGuildMgmtWnd_x                                       0x11A3A90
#define pinstCHotButtonWnd_x                                       0x11A3B5C
#define pinstCHotButtonWnd1_x                                      0x11A3B5C
#define pinstCHotButtonWnd2_x                                      0x11A3B60
#define pinstCHotButtonWnd3_x                                      0x11A3B64
#define pinstCHotButtonWnd4_x                                      0x11A3B88
#define pinstCItemDisplayManager_x                                 0x11A3E80
#define pinstCItemExpTransferWnd_x                                 0x11A3EFC
#define pinstCLFGuildWnd_x                                         0x11A41D8
#define pinstCMIZoneSelectWnd_x                                    0x11A47C0
#define pinstCConfirmationDialog_x                                 0x11A4EC8
#define pinstCPopupWndManager_x                                    0x11A4EC8
#define pinstCProgressionSelectionWnd_x                            0x11A4FB8
#define pinstCPvPStatsWnd_x                                        0x11A50A8
#define pinstCSystemInfoDialogBox_x                                0x11A57B0
#define pinstCTaskWnd_x                                            0x11A6B78
#define pinstCTaskSomething_x                                      0xE1AD90
#define pinstCTaskTemplateSelectWnd_x                              0x11A6B00
#define pinstCTipWndOFDAY_x                                        0x11A6DD0
#define pinstCTipWndCONTEXT_x                                      0x11A6DD4
#define pinstCTitleWnd_x                                           0x11A6E50
#define pinstCContextMenuManager_x                                 0x180A624
#define pinstCVoiceMacroWnd_x                                      0x1093A88
#define pinstCHtmlWnd_x                                            0x1093B80
#define pinstIconCache_x                                           0x11A12E4
#define pinstCTradeskillWnd_x                                      0x11A6F50
#define pinstCAdvancedLootWnd_x                                    0xF4CCF8
#define pinstRewardSelectionWnd_x                                  0x11A55D0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x52EDC0
#define __ConvertItemTags_x                                        0x51BF20
#define __ExecuteCmd_x                                             0x506A30
#define __EQGetTime_x                                              0x89BA40
#define __get_melee_range_x                                        0x50D6F0
#define __GetGaugeValueFromEQ_x                                    0x7A4D60
#define __GetLabelFromEQ_x                                         0x7A5FB0
#define __ToggleMount_x                                            0x6CDEC0
#define __GetXTargetType_x                                         0x92CB40
#define __LoadFrontEnd_x                                           0x6326B0
#define __NewUIINI_x                                               0x7A4670
#define __ProcessGameEvents_x                                      0x573390
#define __ProcessMouseEvent_x                                      0x572B30
#define CrashDetected_x                                            0x634180
#define wwsCrashReportCheckForUploader_x                           0x7F8850
#define DrawNetStatus_x                                            0x5A9E40
#define Util__FastTime_x                                           0x89B390
#define Expansion_HoT_x                                            0x100E46C
#define __HelpPath_x                                               0x1091BD8
#define __STMLToText_x                                             0x8E0420

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F050
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419EB0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C21C0
#define AltAdvManager__IsAbilityReady_x                            0x4C2230
#define AltAdvManager__GetAAById_x                                 0x4C25F0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4643E0
#define CharacterZoneClient__MakeMeVisible_x                       0x469DC0
#define CharacterZoneClient__IsStackBlocked_x                      0x4468C0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x662300

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6700A0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5895D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68B5A0
#define CChatManager__InitContextMenu_x                            0x68C120

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8DE780
#define CContextMenu__AddMenuItem_x                                0x8DE9A0
#define CContextMenu__dCContextMenu_x                              0x8DE990
#define CContextMenu__RemoveMenuItem_x                             0x8DEC90
#define CContextMenu__RemoveAllMenuItems_x                         0x8DECB0
#define CContextMenuManager__AddMenu_x                             0x8CA580
#define CContextMenuManager__RemoveMenu_x                          0x8CA8D0
#define CContextMenuManager__PopupMenu_x                           0x8CAD20
#define CContextMenuManager__Flush_x                               0x8CA5F0
#define CContextMenuManager__GetMenu_x                             0x415520

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x881720
#define CChatService__GetFriendName_x                              0x881730

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6913D0
#define CChatWindow__Clear_x                                       0x690F80
#define CChatWindow__WndNotification_x                             0x691910

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8CE460
#define CComboWnd__Draw_x                                          0x8CE670
#define CComboWnd__GetCurChoice_x                                  0x8CE230
#define CComboWnd__GetListRect_x                                   0x8CE910
#define CComboWnd__GetTextRect_x                                   0x8CE4D0
#define CComboWnd__InsertChoice_x                                  0x8CE980
#define CComboWnd__SetColors_x                                     0x8CE1C0
#define CComboWnd__SetChoice_x                                     0x8CE1F0
#define CComboWnd__GetItemCount_x                                  0x8CE220

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69AB80
#define CContainerWnd__vftable_x                                   0xADB7E0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B04E0
#define CDisplay__GetClickedActor_x                                0x4A9060
#define CDisplay__GetUserDefinedColor_x                            0x4A7920
#define CDisplay__GetWorldFilePath_x                               0x4A6D70
#define CDisplay__is3dON_x                                         0x4A6140
#define CDisplay__ReloadUI_x                                       0x4BBA00
#define CDisplay__WriteTextHD2_x                                   0x4AC880

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F4D90

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E3120
#define CEditWnd__GetCharIndexPt_x                                 0x8E41B0
#define CEditWnd__GetDisplayString_x                               0x8E32D0
#define CEditWnd__GetHorzOffset_x                                  0x8E3610
#define CEditWnd__GetLineForPrintableChar_x                        0x8E3C80
#define CEditWnd__GetSelStartPt_x                                  0x8E4460
#define CEditWnd__GetSTMLSafeText_x                                0x8E37B0
#define CEditWnd__PointFromPrintableChar_x                         0x8E3D70
#define CEditWnd__SelectableCharFromPoint_x                        0x8E3EF0
#define CEditWnd__SetEditable_x                                    0x8E3780

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x550400
#define CEverQuest__DoTellWindow_x                                 0x555E00
#define CEverQuest__DropHeldItemOnGround_x                         0x55E8F0
#define CEverQuest__dsp_chat_x                                     0x5575A0
#define CEverQuest__Emote_x                                        0x557800
#define CEverQuest__EnterZone_x                                    0x56B920
#define CEverQuest__GetBodyTypeDesc_x                              0x54CC60
#define CEverQuest__GetClassDesc_x                                 0x552970
#define CEverQuest__GetClassThreeLetterCode_x                      0x552F70
#define CEverQuest__GetDeityDesc_x                                 0x54D540
#define CEverQuest__GetLangDesc_x                                  0x54CFF0
#define CEverQuest__GetRaceDesc_x                                  0x553130
#define CEverQuest__InterpretCmd_x                                 0x5580E0
#define CEverQuest__LeftClickedOnPlayer_x                          0x56FA90
#define CEverQuest__LMouseUp_x                                     0x571B80
#define CEverQuest__RightClickedOnPlayer_x                         0x570590
#define CEverQuest__RMouseUp_x                                     0x5715E0
#define CEverQuest__SetGameState_x                                 0x550AB0
#define CEverQuest__UPCNotificationFlush_x                         0x559240
#define CEverQuest__IssuePetCommand_x                              0x558DA0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AB800
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AB860
#define CGaugeWnd__Draw_x                                          0x6ABC90

// CGuild
#define CGuild__FindMemberByName_x                                 0x4361A0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C8900

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D6700
#define CInvSlotMgr__MoveItem_x                                    0x6D7630
#define CInvSlotMgr__SelectSlot_x                                  0x6D67B0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D5B90
#define CInvSlot__SliderComplete_x                                 0x6D3550
#define CInvSlot__GetItemBase_x                                    0x6D29E0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D87B0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A16E0
#define CItemDisplayWnd__UpdateStrings_x                           0x6D9B20

// CLabel 
#define CLabel__Draw_x                                             0x6F47F0

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8BA190
#define CListWnd__dCListWnd_x                                      0x8BB1B0
#define CListWnd__AddColumn_x                                      0x8BB150
#define CListWnd__AddColumn1_x                                     0x8BA9D0
#define CListWnd__AddLine_x                                        0x8BA450
#define CListWnd__AddString_x                                      0x8BA660
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B74D0
#define CListWnd__CalculateVSBRange_x                              0x8B9640
#define CListWnd__ClearAllSel_x                                    0x8B6790
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BA020
#define CListWnd__Compare_x                                        0x8B7FC0
#define CListWnd__Draw_x                                           0x8B9250
#define CListWnd__DrawColumnSeparators_x                           0x8B90E0
#define CListWnd__DrawHeader_x                                     0x8B6AA0
#define CListWnd__DrawItem_x                                       0x8B8610
#define CListWnd__DrawLine_x                                       0x8B8D80
#define CListWnd__DrawSeparator_x                                  0x8B9180
#define CListWnd__EnsureVisible_x                                  0x8B7630
#define CListWnd__ExtendSel_x                                      0x8B8520
#define CListWnd__GetColumnMinWidth_x                              0x8B6150
#define CListWnd__GetColumnWidth_x                                 0x8B6070
#define CListWnd__GetCurSel_x                                      0x8B5850
#define CListWnd__GetItemAtPoint_x                                 0x8B78D0
#define CListWnd__GetItemAtPoint1_x                                0x8B7940
#define CListWnd__GetItemData_x                                    0x8B5B90
#define CListWnd__GetItemHeight_x                                  0x8B7130
#define CListWnd__GetItemIcon_x                                    0x8B5D70
#define CListWnd__GetItemRect_x                                    0x8B7710
#define CListWnd__GetItemText_x                                    0x8B5C20
#define CListWnd__GetSelList_x                                     0x8BA8C0
#define CListWnd__GetSeparatorRect_x                               0x8B7EF0
#define CListWnd__RemoveLine_x                                     0x8BA840
#define CListWnd__SetColors_x                                      0x8B59A0
#define CListWnd__SetColumnJustification_x                         0x8B6420
#define CListWnd__SetColumnWidth_x                                 0x8B6100
#define CListWnd__SetCurSel_x                                      0x8B5890
#define CListWnd__SetItemColor_x                                   0x8B9D00
#define CListWnd__SetItemData_x                                    0x8B6840
#define CListWnd__SetItemText_x                                    0x8B9B40
#define CListWnd__ShiftColumnSeparator_x                           0x8B99D0
#define CListWnd__Sort_x                                           0x8BB2B0
#define CListWnd__ToggleSel_x                                      0x8B6710

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70DF30

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72F080
#define CMerchantWnd__RequestBuyItem_x                             0x735E70
#define CMerchantWnd__RequestSellItem_x                            0x7368C0
#define CMerchantWnd__SelectRecoverySlot_x                         0x72F330
#define CMerchantWnd__SelectBuySellSlot_x                          0x72E590
#define CMerchantWnd__ActualSelect_x                               0x732DB0

// CObfuscator
#define CObfuscator__doit_x                                        0x861A60

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D9620
#define CSidlManager__CreateLabel_x                                0x7976A0

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6594A0
#define CSidlScreenWnd__CalculateHSBRange_x                        0x659580
#define CSidlScreenWnd__ConvertToRes_x                             0x8F4C70
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D1100
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D2610
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D26C0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D1B90
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D0AB0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D0200
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D0CA0
#define CSidlScreenWnd__Init1_x                                    0x8D22F0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D11B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D03C0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D1DE0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CFCC0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D0190
#define CSidlScreenWnd__WndNotification_x                          0x8D2070
#define CSidlScreenWnd__GetChildItem_x                             0x8D02D0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C37C0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F46B0
#define CSkillMgr__GetSkillCap_x                                   0x5F4870
#define CSkillMgr__GetNameToken_x                                  0x5F42D0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F3F10
#define CSliderWnd__SetValue_x                                     0x8F40E0
#define CSliderWnd__SetNumTicks_x                                  0x8F4860

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79F390

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EE910
#define CStmlWnd__CalculateHSBRange_x                              0x8E6E40
#define CStmlWnd__CalculateVSBRange_x                              0x8E6ED0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E7050
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E7930
#define CStmlWnd__ForceParseNow_x                                  0x8EF260
#define CStmlWnd__GetNextTagPiece_x                                0x8E7830
#define CStmlWnd__GetSTMLText_x                                    0x690820
#define CStmlWnd__GetVisibleText_x                                 0x8E8380
#define CStmlWnd__InitializeWindowVariables_x                      0x8EA6F0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E6140
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E61A0
#define CStmlWnd__SetSTMLText_x                                    0x8EBF50
#define CStmlWnd__StripFirstSTMLLines_x                            0x8EE5B0
#define CStmlWnd__UpdateHistoryString_x                            0x8E92B0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F6530
#define CTabWnd__DrawCurrentPage_x                                 0x8F5DA0
#define CTabWnd__DrawTab_x                                         0x8F5B60
#define CTabWnd__GetCurrentPage_x                                  0x8F6170
#define CTabWnd__GetPageInnerRect_x                                0x8F5850
#define CTabWnd__GetTabInnerRect_x                                 0x8F5A50
#define CTabWnd__GetTabRect_x                                      0x8F5920
#define CTabWnd__InsertPage_x                                      0x8F6820
#define CTabWnd__SetPage_x                                         0x8F61A0
#define CTabWnd__SetPageRect_x                                     0x8F6470
#define CTabWnd__UpdatePage_x                                      0x8F67C0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431F10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8CDE30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FB6F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B39B0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x596B10
#define CXStr__CXStr1_x                                            0x4DEBA0
#define CXStr__CXStr3_x                                            0x898420
#define CXStr__dCXStr_x                                            0x596E60
#define CXStr__operator_equal_x                                    0x898590
#define CXStr__operator_equal1_x                                   0x8985E0
#define CXStr__operator_plus_equal1_x                              0x8996C0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C29F0
#define CXWnd__Center_x                                            0x8C8BA0
#define CXWnd__ClrFocus_x                                          0x8C25E0
#define CXWnd__DoAllDrawing_x                                      0x8C87F0
#define CXWnd__DrawChildren_x                                      0x8C8990
#define CXWnd__DrawColoredRect_x                                   0x8C2DA0
#define CXWnd__DrawTooltip_x                                       0x8C3040
#define CXWnd__DrawTooltipAtPoint_x                                0x8C7750
#define CXWnd__GetBorderFrame_x                                    0x8C34A0
#define CXWnd__GetChildWndAt_x                                     0x8C9550
#define CXWnd__GetClientClipRect_x                                 0x8C3260
#define CXWnd__GetScreenClipRect_x                                 0x8C7E50
#define CXWnd__GetScreenRect_x                                     0x8C3650
#define CXWnd__GetTooltipRect_x                                    0x8C2ED0
#define CXWnd__GetWindowTextA_x                                    0x4230A0
#define CXWnd__IsActive_x                                          0x8BDF90
#define CXWnd__IsDescendantOf_x                                    0x8C33F0
#define CXWnd__IsReallyVisible_x                                   0x8C6790
#define CXWnd__IsType_x                                            0x8F7ED0
#define CXWnd__Move_x                                              0x8C5E80
#define CXWnd__Move1_x                                             0x8C8490
#define CXWnd__ProcessTransition_x                                 0x8C29A0
#define CXWnd__Refade_x                                            0x8C2780
#define CXWnd__Resize_x                                            0x8C3720
#define CXWnd__Right_x                                             0x8C7C50
#define CXWnd__SetFocus_x                                          0x8C4FF0
#define CXWnd__SetFont_x                                           0x8C2630
#define CXWnd__SetKeyTooltip_x                                     0x8C3990
#define CXWnd__SetMouseOver_x                                      0x8C8190
#define CXWnd__StartFade_x                                         0x8C2A40
#define CXWnd__GetChildItem_x                                      0x8C80E0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BF8B0
#define CXWndManager__DrawWindows_x                                0x8BF4F0
#define CXWndManager__GetKeyboardFlags_x                           0x8BDAC0
#define CXWndManager__HandleKeyboardMsg_x                          0x8BE420
#define CXWndManager__RemoveWnd_x                                  0x8BE120

// CDBStr
#define CDBStr__GetString_x                                        0x4A4670

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E520
#define EQ_Character__Cur_HP_x                                     0x463AB0
#define EQ_Character__GetAACastingTimeModifier_x                   0x446440
#define EQ_Character__GetCharInfo2_x                               0x86C310
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43E3C0
#define EQ_Character__GetFocusRangeModifier_x                      0x43E5B0
#define EQ_Character__Max_Endurance_x                              0x5BC290
#define EQ_Character__Max_HP_x                                     0x459730
#define EQ_Character__Max_Mana_x                                   0x5BC0C0
#define EQ_Character__doCombatAbility_x                            0x5B96A0
#define EQ_Character__UseSkill_x                                   0x46EFC0
#define EQ_Character__GetConLevel_x                                0x5AE4F0
#define EQ_Character__IsExpansionFlag_x                            0x4225E0
#define EQ_Character__TotalEffect_x                                0x44B7C0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58ED60
#define EQ_Item__CreateItemTagString_x                             0x84BD90
#define EQ_Item__IsStackable_x                                     0x8402C0
#define EQ_Item__GetImageNum_x                                     0x842FA0
#define EQ_Item__CreateItemClient_x                                0x58F950
#define EQ_Item__GetItemValue_x                                    0x84A9E0
#define EQ_Item__ValueSellMerchant_x                               0x84D090

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C42B0
#define EQ_LoadingS__Array_x                                       0xC13A20

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BDA30
#define EQ_PC__GetAlternateAbilityId_x                             0x854E40
#define EQ_PC__GetCombatAbility_x                                  0x854ED0
#define EQ_PC__GetCombatAbilityTimer_x                             0x84FFC0
#define EQ_PC__GetItemTimerValue_x                                 0x5B7470
#define EQ_PC__HasLoreItem_x                                       0x5B1840
#define EQ_PC__AlertInventoryChanged_x                             0x5AE4C0
#define EQ_PC__GetPcZoneClient_x                                   0x5D7FA0
#define EQ_PC__RemoveMyAffect_x                                    0x5B6980

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50B730
#define EQItemList__add_item_x                                     0x50B670
#define EQItemList__delete_item_x                                  0x50BB30
#define EQItemList__FreeItemList_x                                 0x50BA30

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A3950

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C2FC0
#define EQPlayer__dEQPlayer_x                                      0x5CBE30
#define EQPlayer__DoAttack_x                                       0x5DDEC0
#define EQPlayer__EQPlayer_x                                       0x5CE250
#define EQPlayer__SetNameSpriteState_x                             0x5C8B10
#define EQPlayer__SetNameSpriteTint_x                              0x5C43D0
#define EQPlayer__IsBodyType_j_x                                   0x928D10
#define EQPlayer__IsTargetable_x                                   0x929610
#define EQPlayer__CanSee_x                                         0x929B30
#define PlayerZoneClient__ChangeHeight_x                           0x5DDD80

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D2550
#define EQPlayerManager__GetSpawnByName_x                          0x5D29B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x594E40
#define KeypressHandler__AttachKeyToEqCommand_x                    0x594E80
#define KeypressHandler__ClearCommandStateArray_x                  0x594A20
#define KeypressHandler__HandleKeyDown_x                           0x593380
#define KeypressHandler__HandleKeyUp_x                             0x5936A0
#define KeypressHandler__SaveKeymapping_x                          0x594AF0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x706310
#define MapViewMap__SaveEx_x                                       0x709BF0

#define PlayerPointManager__GetAltCurrency_x                       0x867230

// StringTable 
#define StringTable__getString_x                                   0x861D00

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BBD40
#define PcZoneClient__RemovePetEffect_x                            0x5B76A0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54A050

//IconCache
#define IconCache__GetIcon_x                                       0x6A0FD0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x697E60
#define CContainerMgr__CloseContainer_x                            0x698680

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x767950

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x588090

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DA9A0
#define EQ_Spell__SpellAffects_x                                   0x4DAA40
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DAA70
#define CharacterZoneClient__CalcAffectChange_x                    0x447830
#define CLootWnd__LootAll_x                                        0x6FBB70

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7517C0
#define CTargetWnd__WndNotification_x                              0x7ACE60

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B2550

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D4290

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x493D10

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E2750
#define CSidlManager__FindAnimation1_x                             0x8D7510

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CB9D0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CB980
#define CAltAbilityData__GetMaxRank_x                              0x4C0860
