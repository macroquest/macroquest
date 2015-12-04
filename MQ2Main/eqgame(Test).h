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
#define __ExpectedVersionDate                                     "Dec  2 2015"
#define __ExpectedVersionTime                                     "14:13:36"
#define __ActualVersionDate_x                                      0xADB5C8
#define __ActualVersionTime_x                                      0xADB5D4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5A0BE0
#define __MemChecker1_x                                            0x8A3050
#define __MemChecker2_x                                            0x63A030
#define __MemChecker3_x                                            0x639F80
#define __MemChecker4_x                                            0x7EEBD0
#define __EncryptPad0_x                                            0xC78388
#define __EncryptPad1_x                                            0xE03508
#define __EncryptPad2_x                                            0xCC1E70
#define __EncryptPad3_x                                            0xCC1A70
#define __EncryptPad4_x                                            0xDDC5F8
#define __EncryptPad5_x                                            0x11AF3D0
#define __AC1_x                                                    0x7AB9E5
#define __AC2_x                                                    0x554ED7
#define __AC3_x                                                    0x569A90
#define __AC4_x                                                    0x570710
#define __AC5_x                                                    0x57CEBE
#define __AC6_x                                                    0x580A69
#define __AC7_x                                                    0x57756C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FB27C

// Direct Input
#define DI8__Main_x                                                0x11AF3A8
#define DI8__Keyboard_x                                            0x11AF3AC
#define DI8__Mouse_x                                               0x11AF3B0
#define DI8__Mouse_Copy_x                                          0x101D9BC
#define DI8__Mouse_Check_x                                         0x10A7294
#define __AltTimerReady_x                                          0x100ED09
#define __Attack_x                                                 0x10A1F37
#define __Autofire_x                                               0x10A1F38
#define __BindList_x                                               0xC3A458
#define __bCommandEnabled_x                                        0x100CE18
#define __Clicks_x                                                 0x101DA78
#define __CommandList_x                                            0xC3E7C8
#define __CurrentMapLabel_x                                        0x11B4E00
#define __CurrentSocial_x                                          0xBF15BC
#define __DoAbilityList_x                                          0x10541EC
#define __do_loot_x                                                0x51C4E0
#define __DrawHandler_x                                            0x181BBB4
#define __GroupCount_x                                             0x100E3E2

#define __Guilds_x                                                 0x1013FF8
#define __gWorld_x                                                 0x101089C
#define __HotkeyPage_x                                             0x109ABEC
#define __HWnd_x                                                   0x10A72B0
#define __InChatMode_x                                             0x101D9A4
#define __LastTell_x                                               0x101F8E8
#define __LMouseHeldTime_x                                         0x101DAE4
#define __Mouse_x                                                  0x11AF3B4
#define __MouseLook_x                                              0x101DA3E
#define __MouseEventTime_x                                         0x10A273C
#define __gpbCommandEvent_x                                        0x1010964
#define __NetStatusToggle_x                                        0x101DA41
#define __PCNames_x                                                0x101EF08
#define __RangeAttackReady_x                                       0x101EBC8
#define __RMouseHeldTime_x                                         0x101DAE0
#define __RunWalkState_x                                           0x101D9A8
#define __ScreenMode_x                                             0xF5CB48
#define __ScreenX_x                                                0x101D95C
#define __ScreenY_x                                                0x101D958
#define __ScreenXMax_x                                             0x101D960
#define __ScreenYMax_x                                             0x101D964
#define __ServerHost_x                                             0x100E32C
#define __ServerName_x                                             0x10541AC
#define __ShiftKeyDown_x                                           0x101E04C
#define __ShowNames_x                                              0x101ED9C
#define __Socials_x                                                0x10542AC
#define __SubscriptionType_x                                       0x11E3330
#define __TargetAggroHolder_x                                      0x11B703C
#define __GroupAggro_x                                             0x11B707C
#define __LoginName_x                                              0x10A5E88
#define __Inviter_x                                                0x10A1EB4


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x1010988
#define instEQZoneInfo_x                                           0x101DC34
#define instKeypressHandler_x                                      0x10A2720
#define pinstActiveBanker_x                                        0x1010940
#define pinstActiveCorpse_x                                        0x1010944
#define pinstActiveGMaster_x                                       0x1010948
#define pinstActiveMerchant_x                                      0x101093C
#define pinstAggroInfo_x                                           0xE1EF40
#define pinstAltAdvManager_x                                       0xF5DC50
#define pinstAuraMgr_x                                             0xE2AE10
#define pinstBandageTarget_x                                       0x1010928
#define pinstCamActor_x                                            0xF5D558
#define pinstCDBStr_x                                              0xF5CADC
#define pinstCDisplay_x                                            0x1010950
#define pinstCEverQuest_x                                          0x11AF528
#define pinstCharData_x                                            0x101090C
#define pinstCharSpawn_x                                           0x1010934
#define pinstControlledMissile_x                                   0x1010908
#define pinstControlledPlayer_x                                    0x1010934
#define pinstCSidlManager_x                                        0x181B0F4
#define pinstCXWndManager_x                                        0x181B0EC
#define instDynamicZone_x                                          0x101D7F0
#define pinstDZMember_x                                            0x101D900
#define pinstDZTimerInfo_x                                         0x101D904
#define pinstEQItemList_x                                          0x100D068
#define instEQMisc_x                                               0xC13948
#define pinstEQSoundManager_x                                      0xF5E1B0
#define instExpeditionLeader_x                                     0x101D83A
#define instExpeditionName_x                                       0x101D87A
#define pinstGroup_x                                               0x100E3DE
#define pinstImeManager_x                                          0x181B0F8
#define pinstLocalPlayer_x                                         0x1010920
#define pinstMercenaryData_x                                       0x10A2D70
#define pinstMercenaryStats_x                                      0x11B7188
#define pinstMercAltAbilities_x                                    0xF5DFDC
#define pinstModelPlayer_x                                         0x101094C
#define pinstPCData_x                                              0x101090C
#define pinstSkillMgr_x                                            0x10A3BA8
#define pinstSpawnManager_x                                        0x10A3490
#define pinstSpellManager_x                                        0x10A3CF0
#define pinstSpellSets_x                                           0x109AC50
#define pinstStringTable_x                                         0x10108B4
#define pinstSwitchManager_x                                       0x100DF70
#define pinstTarget_x                                              0x1010938
#define pinstTargetObject_x                                        0x1010910
#define pinstTargetSwitch_x                                        0x1010914
#define pinstTaskMember_x                                          0xF5CA28
#define pinstTrackTarget_x                                         0x101092C
#define pinstTradeTarget_x                                         0x101091C
#define instTributeActive_x                                        0xC1396D
#define pinstViewActor_x                                           0xF5D554
#define pinstWorldData_x                                           0x10108F0
#define pinstZoneAddr_x                                            0x101DEF4
#define pinstPlayerPath_x                                          0x109F610
#define pinstTargetIndicator_x                                     0x109FFA8
#define pinstCTargetManager_x                                      0x10A3EE8

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE1F420
#define pinstCAudioTriggersWindow_x                                0xE1F2B0
#define pinstCCharacterSelect_x                                    0xF5D3E8
#define pinstCFacePick_x                                           0xF5D398
#define pinstCNoteWnd_x                                            0xF5D3A0
#define pinstCBookWnd_x                                            0xF5D3A8
#define pinstCPetInfoWnd_x                                         0xF5D3AC
#define pinstCTrainWnd_x                                           0xF5D3B0
#define pinstCSkillsWnd_x                                          0xF5D3B4
#define pinstCSkillsSelectWnd_x                                    0xF5D3B8
#define pinstCCombatSkillsSelectWnd_x                              0xF5D3BC
#define pinstCFriendsWnd_x                                         0xF5D3C0
#define pinstCAuraWnd_x                                            0xF5D3C4
#define pinstCRespawnWnd_x                                         0xF5D3C8
#define pinstCBandolierWnd_x                                       0xF5D3CC
#define pinstCPotionBeltWnd_x                                      0xF5D3D0
#define pinstCAAWnd_x                                              0xF5D3D4
#define pinstCGroupSearchFiltersWnd_x                              0xF5D3D8
#define pinstCLoadskinWnd_x                                        0xF5D3DC
#define pinstCAlarmWnd_x                                           0xF5D3E0
#define pinstCMusicPlayerWnd_x                                     0xF5D3E4
#define pinstCMailWnd_x                                            0xF5D3EC
#define pinstCMailCompositionWnd_x                                 0xF5D3F0
#define pinstCMailAddressBookWnd_x                                 0xF5D3F4
#define pinstCRaidWnd_x                                            0xF5D3FC
#define pinstCRaidOptionsWnd_x                                     0xF5D400
#define pinstCBreathWnd_x                                          0xF5D404
#define pinstCMapViewWnd_x                                         0xF5D408
#define pinstCMapToolbarWnd_x                                      0xF5D40C
#define pinstCEditLabelWnd_x                                       0xF5D410
#define pinstCTargetWnd_x                                          0xF5D414
#define pinstCColorPickerWnd_x                                     0xF5D418
#define pinstCPlayerWnd_x                                          0xF5D41C
#define pinstCOptionsWnd_x                                         0xF5D420
#define pinstCBuffWindowNORMAL_x                                   0xF5D424
#define pinstCBuffWindowSHORT_x                                    0xF5D428
#define pinstCharacterCreation_x                                   0xF5D42C
#define pinstCCursorAttachment_x                                   0xF5D430
#define pinstCCastingWnd_x                                         0xF5D434
#define pinstCCastSpellWnd_x                                       0xF5D438
#define pinstCSpellBookWnd_x                                       0xF5D43C
#define pinstCInventoryWnd_x                                       0xF5D440
#define pinstCBankWnd_x                                            0xF5D448
#define pinstCQuantityWnd_x                                        0xF5D44C
#define pinstCLootWnd_x                                            0xF5D450
#define pinstCActionsWnd_x                                         0xF5D454
#define pinstCCombatAbilityWnd_x                                   0xF5D458
#define pinstCMerchantWnd_x                                        0xF5D45C
#define pinstCTradeWnd_x                                           0xF5D460
#define pinstCSelectorWnd_x                                        0xF5D464
#define pinstCBazaarWnd_x                                          0xF5D468
#define pinstCBazaarSearchWnd_x                                    0xF5D46C
#define pinstCGiveWnd_x                                            0xF5D488
#define pinstCTrackingWnd_x                                        0xF5D490
#define pinstCInspectWnd_x                                         0xF5D494
#define pinstCSocialEditWnd_x                                      0xF5D498
#define pinstCFeedbackWnd_x                                        0xF5D49C
#define pinstCBugReportWnd_x                                       0xF5D4A0
#define pinstCVideoModesWnd_x                                      0xF5D4A4
#define pinstCTextEntryWnd_x                                       0xF5D4AC
#define pinstCFileSelectionWnd_x                                   0xF5D4B0
#define pinstCCompassWnd_x                                         0xF5D4B4
#define pinstCPlayerNotesWnd_x                                     0xF5D4B8
#define pinstCGemsGameWnd_x                                        0xF5D4BC
#define pinstCTimeLeftWnd_x                                        0xF5D4C0
#define pinstCPetitionQWnd_x                                       0xF5D4DC
#define pinstCSoulmarkWnd_x                                        0xF5D4E0
#define pinstCStoryWnd_x                                           0xF5D4E4
#define pinstCJournalTextWnd_x                                     0xF5D4E8
#define pinstCJournalCatWnd_x                                      0xF5D4EC
#define pinstCBodyTintWnd_x                                        0xF5D4F0
#define pinstCServerListWnd_x                                      0xF5D4F4
#define pinstCAvaZoneWnd_x                                         0xF5D500
#define pinstCBlockedBuffWnd_x                                     0xF5D504
#define pinstCBlockedPetBuffWnd_x                                  0xF5D508
#define pinstCInvSlotMgr_x                                         0xF5D54C
#define pinstCContainerMgr_x                                       0xF5D550
#define pinstCAdventureLeaderboardWnd_x                            0x11AFED8
#define pinstCAdventureRequestWnd_x                                0x11AFF50
#define pinstCAltStorageWnd_x                                      0x11B0230
#define pinstCAdventureStatsWnd_x                                  0x11AFFC8
#define pinstCBarterMerchantWnd_x                                  0x11B0E18
#define pinstCBarterSearchWnd_x                                    0x11B0E90
#define pinstCBarterWnd_x                                          0x11B0F08
#define pinstCChatManager_x                                        0x11B1598
#define pinstCDynamicZoneWnd_x                                     0x11B1A48
#define pinstCEQMainWnd_x                                          0x11B1BE0
#define pinstCFellowshipWnd_x                                      0x11B19DC
#define pinstCFindLocationWnd_x                                    0x11B1EB0
#define pinstCGroupSearchWnd_x                                     0x11B2180
#define pinstCGroupWnd_x                                           0x11B21F8
#define pinstCGuildBankWnd_x                                       0x11B2270
#define pinstCGuildMgmtWnd_x                                       0x11B4360
#define pinstCHotButtonWnd_x                                       0x11B442C
#define pinstCHotButtonWnd1_x                                      0x11B442C
#define pinstCHotButtonWnd2_x                                      0x11B4430
#define pinstCHotButtonWnd3_x                                      0x11B4434
#define pinstCHotButtonWnd4_x                                      0x11B4458
#define pinstCItemDisplayManager_x                                 0x11B4750
#define pinstCItemExpTransferWnd_x                                 0x11B47CC
#define pinstCLFGuildWnd_x                                         0x11B4AA8
#define pinstCMIZoneSelectWnd_x                                    0x11B5090
#define pinstCConfirmationDialog_x                                 0x11B5798
#define pinstCPopupWndManager_x                                    0x11B5798
#define pinstCProgressionSelectionWnd_x                            0x11B5888
#define pinstCPvPStatsWnd_x                                        0x11B5978
#define pinstCSystemInfoDialogBox_x                                0x11B6080
#define pinstCTaskWnd_x                                            0x11B7448
#define pinstCTaskSomething_x                                      0xE2B5D0
#define pinstCTaskTemplateSelectWnd_x                              0x11B73D0
#define pinstCTipWndOFDAY_x                                        0x11B76A0
#define pinstCTipWndCONTEXT_x                                      0x11B76A4
#define pinstCTitleWnd_x                                           0x11B7720
#define pinstCContextMenuManager_x                                 0x181B064
#define pinstCVoiceMacroWnd_x                                      0x10A4358
#define pinstCHtmlWnd_x                                            0x10A4450
#define pinstIconCache_x                                           0x11B1BB4
#define pinstCTradeskillWnd_x                                      0x11B7820
#define pinstCAdvancedLootWnd_x                                    0xF5D540
#define pinstRewardSelectionWnd_x                                  0x11B5EA0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x534030
#define __ConvertItemTags_x                                        0x521160
#define __ExecuteCmd_x                                             0x50BC80
#define __EQGetTime_x                                              0x8A2C80
#define __get_melee_range_x                                        0x512930
#define __GetGaugeValueFromEQ_x                                    0x7AA720
#define __GetLabelFromEQ_x                                         0x7AB970
#define __ToggleKeyRingItem_x                                      0x47EF00
#define __GetXTargetType_x                                         0x934430
#define __LoadFrontEnd_x                                           0x6396E0
#define __NewUIINI_x                                               0x7AA030
#define __ProcessGameEvents_x                                      0x5792D0
#define __ProcessMouseEvent_x                                      0x578A70
#define CrashDetected_x                                            0x63B1B0
#define wwsCrashReportCheckForUploader_x                           0x7FE3B0
#define DrawNetStatus_x                                            0x5B0640
#define Util__FastTime_x                                           0x8A2790
#define Expansion_HoT_x                                            0x101ED34
#define __HelpPath_x                                               0x10A24A8
#define __STMLToText_x                                             0x8E8BB0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41FDF0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41AC60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C5CD0
#define AltAdvManager__IsAbilityReady_x                            0x4C5D40
#define AltAdvManager__GetAAById_x                                 0x4C6100
#define AltAdvManager__CanTrainAbility_x                           0x4C69C0
#define AltAdvManager__CanSeeAbility_x                             0x4C65C0


// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465100
#define CharacterZoneClient__MakeMeVisible_x                       0x46AAE0
#define CharacterZoneClient__IsStackBlocked_x                      0x446F40

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6692A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6779D0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58FB30
#define CButtonWnd__CButtonWnd_x                                   0x8DCED0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x692510
#define CChatManager__InitContextMenu_x                            0x693090

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E6F20
#define CContextMenu__dCContextMenu_x                              0x8E7130
#define CContextMenu__AddMenuItem_x                                0x8E7140
#define CContextMenu__RemoveMenuItem_x                             0x8E7420
#define CContextMenu__RemoveAllMenuItems_x                         0x8E7440
#define CContextMenuManager__AddMenu_x                             0x8D2E80
#define CContextMenuManager__RemoveMenu_x                          0x8D31D0
#define CContextMenuManager__PopupMenu_x                           0x8D3620
#define CContextMenuManager__Flush_x                               0x8D2EF0
#define CContextMenuManager__GetMenu_x                             0x4162C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x887EC0
#define CChatService__GetFriendName_x                              0x887ED0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x698330
#define CChatWindow__Clear_x                                       0x697EF0
#define CChatWindow__WndNotification_x                             0x698860

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D6D80
#define CComboWnd__Draw_x                                          0x8D6F90
#define CComboWnd__GetCurChoice_x                                  0x8D6B50
#define CComboWnd__GetListRect_x                                   0x8D7230
#define CComboWnd__GetTextRect_x                                   0x8D6DF0
#define CComboWnd__InsertChoice_x                                  0x8D72A0
#define CComboWnd__SetColors_x                                     0x8D6AE0
#define CComboWnd__SetChoice_x                                     0x8D6B10
#define CComboWnd__GetItemCount_x                                  0x8D6B40

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A1A50
#define CContainerWnd__vftable_x                                   0xAE4FB0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B3F40
#define CDisplay__GetClickedActor_x                                0x4ACA80
#define CDisplay__GetUserDefinedColor_x                            0x4AB340
#define CDisplay__GetWorldFilePath_x                               0x4AA790
#define CDisplay__is3dON_x                                         0x4A9B60
#define CDisplay__ReloadUI_x                                       0x4BF510
#define CDisplay__WriteTextHD2_x                                   0x4B02A0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FDAA0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8EB890
#define CEditWnd__GetCharIndexPt_x                                 0x8EC910
#define CEditWnd__GetDisplayString_x                               0x8EBA40
#define CEditWnd__GetHorzOffset_x                                  0x8EBD80
#define CEditWnd__GetLineForPrintableChar_x                        0x8EC3E0
#define CEditWnd__GetSelStartPt_x                                  0x8ECBC0
#define CEditWnd__GetSTMLSafeText_x                                0x8EBF10
#define CEditWnd__PointFromPrintableChar_x                         0x8EC4D0
#define CEditWnd__SelectableCharFromPoint_x                        0x8EC650
#define CEditWnd__SetEditable_x                                    0x8EBEE0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x555620
#define CEverQuest__CreateTargetIndicator_x                        0x556250
#define CEverQuest__DeleteTargetIndicator_x                        0x5562D0
#define CEverQuest__DoTellWindow_x                                 0x55B020
#define CEverQuest__DropHeldItemOnGround_x                         0x563F10
#define CEverQuest__dsp_chat_x                                     0x55C9D0
#define CEverQuest__Emote_x                                        0x55CC30
#define CEverQuest__EnterZone_x                                    0x571060
#define CEverQuest__GetBodyTypeDesc_x                              0x551E80
#define CEverQuest__GetClassDesc_x                                 0x557B90
#define CEverQuest__GetClassThreeLetterCode_x                      0x558190
#define CEverQuest__GetDeityDesc_x                                 0x552760
#define CEverQuest__GetLangDesc_x                                  0x552210
#define CEverQuest__GetRaceDesc_x                                  0x558350
#define CEverQuest__InterpretCmd_x                                 0x55D510
#define CEverQuest__LeftClickedOnPlayer_x                          0x5759D0
#define CEverQuest__LMouseUp_x                                     0x577AC0
#define CEverQuest__RightClickedOnPlayer_x                         0x5764D0
#define CEverQuest__RMouseUp_x                                     0x577520
#define CEverQuest__SetGameState_x                                 0x555CD0
#define CEverQuest__UPCNotificationFlush_x                         0x55E870
#define CEverQuest__IssuePetCommand_x                              0x55E1D0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B2660
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B26C0
#define CGaugeWnd__Draw_x                                          0x6B2AF0

// CGuild
#define CGuild__FindMemberByName_x                                 0x436BF0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CF6B0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DBE30
#define CInvSlotMgr__MoveItem_x                                    0x6DCD60
#define CInvSlotMgr__SelectSlot_x                                  0x6DBEE0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DB2C0
#define CInvSlot__SliderComplete_x                                 0x6D8AF0
#define CInvSlot__GetItemBase_x                                    0x6D7F60

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DE120

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A70C0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DF460

// CLabel 
#define CLabel__Draw_x                                             0x6FA2E0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C2AD0
#define CListWnd__dCListWnd_x                                      0x8C3AF0
#define CListWnd__AddColumn_x                                      0x8C3A90
#define CListWnd__AddColumn1_x                                     0x8C3310
#define CListWnd__AddLine_x                                        0x8C2D90
#define CListWnd__AddString_x                                      0x8C2FA0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BFE50
#define CListWnd__CalculateVSBRange_x                              0x8C1FA0
#define CListWnd__ClearAllSel_x                                    0x8BF120
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C2960
#define CListWnd__Compare_x                                        0x8C0930
#define CListWnd__Draw_x                                           0x8C1BB0
#define CListWnd__DrawColumnSeparators_x                           0x8C1A40
#define CListWnd__DrawHeader_x                                     0x8BF430
#define CListWnd__DrawItem_x                                       0x8C0F80
#define CListWnd__DrawLine_x                                       0x8C16E0
#define CListWnd__DrawSeparator_x                                  0x8C1AE0
#define CListWnd__EnsureVisible_x                                  0x8BFFB0
#define CListWnd__ExtendSel_x                                      0x8C0E90
#define CListWnd__GetColumnMinWidth_x                              0x8BEAE0
#define CListWnd__GetColumnWidth_x                                 0x8BEA00
#define CListWnd__GetCurSel_x                                      0x8BE1D0
#define CListWnd__GetItemAtPoint_x                                 0x8C0230
#define CListWnd__GetItemAtPoint1_x                                0x8C02A0
#define CListWnd__GetItemData_x                                    0x8BE510
#define CListWnd__GetItemHeight_x                                  0x8BFAC0
#define CListWnd__GetItemIcon_x                                    0x8BE6F0
#define CListWnd__GetItemRect_x                                    0x8C0070
#define CListWnd__GetItemText_x                                    0x8BE5A0
#define CListWnd__GetSelList_x                                     0x8C3200
#define CListWnd__GetSeparatorRect_x                               0x8C0850
#define CListWnd__RemoveLine_x                                     0x8C3180
#define CListWnd__SetColors_x                                      0x8BE320
#define CListWnd__SetColumnJustification_x                         0x8BEDB0
#define CListWnd__SetColumnWidth_x                                 0x8BEA90
#define CListWnd__SetCurSel_x                                      0x8BE210
#define CListWnd__SetItemColor_x                                   0x8C2640
#define CListWnd__SetItemData_x                                    0x8BF1D0
#define CListWnd__SetItemText_x                                    0x8C2480
#define CListWnd__ShiftColumnSeparator_x                           0x8C2310
#define CListWnd__Sort_x                                           0x8C3BF0
#define CListWnd__ToggleSel_x                                      0x8BF0A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7137F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x734A60
#define CMerchantWnd__RequestBuyItem_x                             0x73B8A0
#define CMerchantWnd__RequestSellItem_x                            0x73C310
#define CMerchantWnd__SelectRecoverySlot_x                         0x734D10
#define CMerchantWnd__SelectBuySellSlot_x                          0x733F70
#define CMerchantWnd__ActualSelect_x                               0x7387D0

// CObfuscator
#define CObfuscator__doit_x                                        0x8534F0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E1EA0
#define CSidlManager__CreateLabel_x                                0x79D120

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x6604D0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x660400
#define CSidlScreenWnd__ConvertToRes_x                             0x8FD980
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D99F0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8DAEF0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8DAFA0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8DA470
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D93A0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D8B10
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D9590
#define CSidlScreenWnd__Init1_x                                    0x8DABD0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D9AA0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D8CD0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8DA6C0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D85D0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D8AA0
#define CSidlScreenWnd__WndNotification_x                          0x8DA950
#define CSidlScreenWnd__GetChildItem_x                             0x8D8BE0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CC140

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FB620
#define CSkillMgr__GetSkillCap_x                                   0x5FB7E0
#define CSkillMgr__GetNameToken_x                                  0x5FB240

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FCC30
#define CSliderWnd__SetValue_x                                     0x8FCE00
#define CSliderWnd__SetNumTicks_x                                  0x8FD580

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A4D70

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F8550
#define CStmlWnd__CalculateHSBRange_x                              0x8F0A90
#define CStmlWnd__CalculateVSBRange_x                              0x8F0B10
#define CStmlWnd__CanBreakAtCharacter_x                            0x8F0C90
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8F1570
#define CStmlWnd__ForceParseNow_x                                  0x8F8F10
#define CStmlWnd__GetNextTagPiece_x                                0x8F1470
#define CStmlWnd__GetSTMLText_x                                    0x697790
#define CStmlWnd__GetVisibleText_x                                 0x8F1FC0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F4340
#define CStmlWnd__MakeStmlColorTag_x                               0x8EFD90
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EFDF0
#define CStmlWnd__SetSTMLText_x                                    0x8F5BA0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F81F0
#define CStmlWnd__UpdateHistoryString_x                            0x8F2F00

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8EF420
#define CTabWnd__DrawCurrentPage_x                                 0x8EEC90
#define CTabWnd__DrawTab_x                                         0x8EEA60
#define CTabWnd__GetCurrentPage_x                                  0x8EF060
#define CTabWnd__GetPageInnerRect_x                                0x8EE750
#define CTabWnd__GetTabInnerRect_x                                 0x8EE950
#define CTabWnd__GetTabRect_x                                      0x8EE820
#define CTabWnd__InsertPage_x                                      0x8EF710
#define CTabWnd__SetPage_x                                         0x8EF090
#define CTabWnd__SetPageRect_x                                     0x8EF360
#define CTabWnd__UpdatePage_x                                      0x8EF6B0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432A10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D6750

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x902E40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BC480

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402270
#define CXStr__CXStr1_x                                            0x440340
#define CXStr__CXStr3_x                                            0x89F820
#define CXStr__dCXStr_x                                            0x901B60
#define CXStr__operator_equal_x                                    0x89F990
#define CXStr__operator_equal1_x                                   0x89F9E0
#define CXStr__operator_plus_equal1_x                              0x8A0AC0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8CB370
#define CXWnd__Center_x                                            0x8D14D0
#define CXWnd__ClrFocus_x                                          0x8CAF50
#define CXWnd__DoAllDrawing_x                                      0x8D1120
#define CXWnd__DrawChildren_x                                      0x8D12C0
#define CXWnd__DrawColoredRect_x                                   0x8CB700
#define CXWnd__DrawTooltip_x                                       0x8CB9A0
#define CXWnd__DrawTooltipAtPoint_x                                0x8D00C0
#define CXWnd__GetBorderFrame_x                                    0x8CBE10
#define CXWnd__GetChildWndAt_x                                     0x8D1E90
#define CXWnd__GetClientClipRect_x                                 0x8CBBC0
#define CXWnd__GetScreenClipRect_x                                 0x8D07B0
#define CXWnd__GetScreenRect_x                                     0x8CBFE0
#define CXWnd__GetTooltipRect_x                                    0x8CB830
#define CXWnd__GetWindowTextA_x                                    0x423E70
#define CXWnd__IsActive_x                                          0x8C69C0
#define CXWnd__IsDescendantOf_x                                    0x8CBD50
#define CXWnd__IsReallyVisible_x                                   0x8CF0E0
#define CXWnd__IsType_x                                            0x8FF600
#define CXWnd__Move_x                                              0x8CE810
#define CXWnd__Move1_x                                             0x8D0DD0
#define CXWnd__ProcessTransition_x                                 0x8CB320
#define CXWnd__Refade_x                                            0x8CB0F0
#define CXWnd__Resize_x                                            0x8CC0B0
#define CXWnd__Right_x                                             0x8D05B0
#define CXWnd__SetFocus_x                                          0x8CD960
#define CXWnd__SetFont_x                                           0x8CAFA0
#define CXWnd__SetKeyTooltip_x                                     0x8CC310
#define CXWnd__SetMouseOver_x                                      0x8D0AE0
#define CXWnd__StartFade_x                                         0x8CB3C0
#define CXWnd__GetChildItem_x                                      0x8D0A30

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C82C0
#define CXWndManager__DrawWindows_x                                0x8C7F00
#define CXWndManager__GetKeyboardFlags_x                           0x8C64F0
#define CXWndManager__HandleKeyboardMsg_x                          0x8C6E50
#define CXWndManager__RemoveWnd_x                                  0x8C6B50

// CDBStr
#define CDBStr__GetString_x                                        0x4A8090

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44EB90
#define EQ_Character__Cur_HP_x                                     0x4647D0
#define EQ_Character__GetAACastingTimeModifier_x                   0x446AC0
#define EQ_Character__GetCharInfo2_x                               0x872A80
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EE20
#define EQ_Character__GetFocusRangeModifier_x                      0x43F010
#define EQ_Character__Max_Endurance_x                              0x5C3150
#define EQ_Character__Max_HP_x                                     0x45A420
#define EQ_Character__Max_Mana_x                                   0x5C2F80
#define EQ_Character__doCombatAbility_x                            0x5C05C0
#define EQ_Character__UseSkill_x                                   0x46FCE0
#define EQ_Character__GetConLevel_x                                0x5B4CA0
#define EQ_Character__IsExpansionFlag_x                            0x4233C0
#define EQ_Character__TotalEffect_x                                0x44BE40

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5953E0
#define EQ_Item__CreateItemTagString_x                             0x851DB0
#define EQ_Item__IsStackable_x                                     0x845F20
#define EQ_Item__GetImageNum_x                                     0x848C20
#define EQ_Item__CreateItemClient_x                                0x595FA0
#define EQ_Item__GetItemValue_x                                    0x850A50
#define EQ_Item__ValueSellMerchant_x                               0x853130

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C7DC0
#define EQ_LoadingS__Array_x                                       0xC21720

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C47B0
#define EQ_PC__GetAlternateAbilityId_x                             0x85B350
#define EQ_PC__GetCombatAbility_x                                  0x85B3E0
#define EQ_PC__GetCombatAbilityTimer_x                             0x856270
#define EQ_PC__GetItemTimerValue_x                                 0x5BE0E0
#define EQ_PC__HasLoreItem_x                                       0x5B8170
#define EQ_PC__AlertInventoryChanged_x                             0x5B4C70
#define EQ_PC__GetPcZoneClient_x                                   0x5DEED0
#define EQ_PC__RemoveMyAffect_x                                    0x5BD5A0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x510960
#define EQItemList__add_item_x                                     0x5108A0
#define EQItemList__delete_item_x                                  0x510D60
#define EQItemList__FreeItemList_x                                 0x510C60

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A7270

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C9D40
#define EQPlayer__dEQPlayer_x                                      0x5D2BB0
#define EQPlayer__DoAttack_x                                       0x5E4DD0
#define EQPlayer__EQPlayer_x                                       0x5D4FD0
#define EQPlayer__SetNameSpriteState_x                             0x5CF890
#define EQPlayer__SetNameSpriteTint_x                              0x5CB150
#define EQPlayer__IsBodyType_j_x                                   0x930620
#define EQPlayer__IsTargetable_x                                   0x930F20
#define EQPlayer__CanSee_x                                         0x931440
#define PlayerZoneClient__ChangeHeight_x                           0x5E4C90
#define EQPlayer__CanSeeTargetIndicator_x                          0x931530

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D9420
#define EQPlayerManager__GetSpawnByName_x                          0x5D9880

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59B560
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59B5A0
#define KeypressHandler__ClearCommandStateArray_x                  0x59B140
#define KeypressHandler__HandleKeyDown_x                           0x599AA0
#define KeypressHandler__HandleKeyUp_x                             0x599DC0
#define KeypressHandler__SaveKeymapping_x                          0x59B210

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70BBD0
#define MapViewMap__SaveEx_x                                       0x70F4B0

#define PlayerPointManager__GetAltCurrency_x                       0x86DA50

// StringTable 
#define StringTable__getString_x                                   0x868430

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C2C00
#define PcZoneClient__RemovePetEffect_x                            0x5BE5D0
#define PcZoneClient__HasAlternateAbility_x                        0x5BF090

//Doors
#define EQSwitch__UseSwitch_x                                      0x54F1C0

//IconCache
#define IconCache__GetIcon_x                                       0x6A7FA0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69ED60
#define CContainerMgr__CloseContainer_x                            0x69F580

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76D4D0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58E5D0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DF4E0
#define EQ_Spell__SpellAffects_x                                   0x4DF580
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DF5B0
#define CharacterZoneClient__CalcAffectChange_x                    0x447EB0
#define CLootWnd__LootAll_x                                        0x7015C0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B2CC0
#define CTargetWnd__WndNotification_x                              0x7B27B0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B7EC0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D8DB0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x497960

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8EAEC0
#define CSidlManager__FindAnimation1_x                             0x8DFDA0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CF3B0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CF360
#define CAltAbilityData__GetMaxRank_x                              0x4C4390

//CTargetRing
#define CTargetRing__Cast_x                                        0x58BEE0
