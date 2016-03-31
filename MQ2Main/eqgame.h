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
#define __ExpectedVersionDate                                     "Mar 18 2016"
#define __ExpectedVersionTime                                     "18:08:46"
#define __ActualVersionDate_x                                      0xAD5368
#define __ActualVersionTime_x                                      0xAD5374

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59E0B0
#define __MemChecker1_x                                            0x89D300
#define __MemChecker2_x                                            0x637900
#define __MemChecker3_x                                            0x637850
#define __MemChecker4_x                                            0x7EAEB0
#define __EncryptPad0_x                                            0xC72378
#define __EncryptPad1_x                                            0xDFDD08
#define __EncryptPad2_x                                            0xCBBE68
#define __EncryptPad3_x                                            0xCBBA68
#define __EncryptPad4_x                                            0xDD5EF8
#define __EncryptPad5_x                                            0x11A9B78
#define __AC1_x                                                    0x7A8245
#define __AC2_x                                                    0x554517
#define __AC3_x                                                    0x569140
#define __AC4_x                                                    0x56FE90
#define __AC5_x                                                    0x57B6AE
#define __AC6_x                                                    0x57F279
#define __AC7_x                                                    0x575DAC
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1E7220

// Direct Input
#define DI8__Main_x                                                0x11A9B50
#define DI8__Keyboard_x                                            0x11A9B54
#define DI8__Mouse_x                                               0x11A9B58
#define DI8__Mouse_Copy_x                                          0x10181E4
#define DI8__Mouse_Check_x                                         0x10A1A3C
#define __Attack_x                                                 0x109C6E3
#define __Autofire_x                                               0x109C6E4
#define __BindList_x                                               0xC34478
#define __bCommandEnabled_x                                        0x1007648
#define __Clicks_x                                                 0x10182A0
#define __CommandList_x                                            0xC387E8
#define __CurrentMapLabel_x                                        0x11AF5A8
#define __CurrentSocial_x                                          0xBEB5B8
#define __DoAbilityList_x                                          0x104E998
#define __do_loot_x                                                0x51BD50
#define __DrawHandler_x                                            0x18163D4
#define __GroupCount_x                                             0x1008C12

#define __Guilds_x                                                 0x100E828
#define __gWorld_x                                                 0x100B0CC
#define __HotkeyPage_x                                             0x1095398
#define __HWnd_x                                                   0x10A1A58
#define __InChatMode_x                                             0x10181CC
#define __LastTell_x                                               0x101A094
#define __LMouseHeldTime_x                                         0x101830C
#define __Mouse_x                                                  0x11A9B5C
#define __MouseLook_x                                              0x1018266
#define __MouseEventTime_x                                         0x109CEEC
#define __gpbCommandEvent_x                                        0x100B194
#define __NetStatusToggle_x                                        0x1018269
#define __PCNames_x                                                0x10196B8
#define __RangeAttackReady_x                                       0x10193F4
#define __RMouseHeldTime_x                                         0x1018308
#define __RunWalkState_x                                           0x10181D0
#define __ScreenMode_x                                             0xF573C0
#define __ScreenX_x                                                0x1018184
#define __ScreenY_x                                                0x1018180
#define __ScreenXMax_x                                             0x1018188
#define __ScreenYMax_x                                             0x101818C
#define __ServerHost_x                                             0x1008B5C
#define __ServerName_x                                             0x104E958
#define __ShiftKeyDown_x                                           0x1018878
#define __ShowNames_x                                              0x10195B4
#define __Socials_x                                                0x104EA58
#define __SubscriptionType_x                                       0x11DDAD8
#define __TargetAggroHolder_x                                      0x11B17E4
#define __GroupAggro_x                                             0x11B1824
#define __LoginName_x                                              0x10A0630
#define __Inviter_x                                                0x109C660
#define __AttackOnAssist_x                                         0x1019570

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x100B1B8
#define instEQZoneInfo_x                                           0x101845C
#define instKeypressHandler_x                                      0x109CED0
#define pinstActiveBanker_x                                        0x100B170
#define pinstActiveCorpse_x                                        0x100B174
#define pinstActiveGMaster_x                                       0x100B178
#define pinstActiveMerchant_x                                      0x100B16C
#define pinstAggroInfo_x                                           0xE19720
#define pinstAltAdvManager_x                                       0xF58480
#define pinstAuraMgr_x                                             0xE25688
#define pinstBandageTarget_x                                       0x100B158
#define pinstCamActor_x                                            0xF57DD4
#define pinstCDBStr_x                                              0xF57354
#define pinstCDisplay_x                                            0x100B180
#define pinstCEverQuest_x                                          0x11A9CD0
#define pinstCharData_x                                            0x100B13C
#define pinstCharSpawn_x                                           0x100B164
#define pinstControlledMissile_x                                   0x100B138
#define pinstControlledPlayer_x                                    0x100B164
#define pinstCSidlManager_x                                        0x1815914
#define pinstCXWndManager_x                                        0x181590C
#define instDynamicZone_x                                          0x1018018
#define pinstDZMember_x                                            0x1018128
#define pinstDZTimerInfo_x                                         0x101812C
#define pinstEQItemList_x                                          0x1007898
#define instEQMisc_x                                               0xC0EFD0
#define pinstEQSoundManager_x                                      0xF589E0
#define instExpeditionLeader_x                                     0x1018062
#define instExpeditionName_x                                       0x10180A2
#define pinstGroup_x                                               0x1008C0E
#define pinstImeManager_x                                          0x1815918
#define pinstLocalPlayer_x                                         0x100B150
#define pinstMercenaryData_x                                       0x109D520
#define pinstMercenaryStats_x                                      0x11B1930
#define pinstMercAltAbilities_x                                    0xF5880C
#define pinstModelPlayer_x                                         0x100B17C
#define pinstPCData_x                                              0x100B13C
#define pinstSkillMgr_x                                            0x109E358
#define pinstSpawnManager_x                                        0x109DC40
#define pinstSpellManager_x                                        0x109E4A0
#define pinstSpellSets_x                                           0x10953FC
#define pinstStringTable_x                                         0x100B0E4
#define pinstSwitchManager_x                                       0x10087A0
#define pinstTarget_x                                              0x100B168
#define pinstTargetObject_x                                        0x100B140
#define pinstTargetSwitch_x                                        0x100B144
#define pinstTaskMember_x                                          0xF572A0
#define pinstTrackTarget_x                                         0x100B15C
#define pinstTradeTarget_x                                         0x100B14C
#define instTributeActive_x                                        0xC0EFF5
#define pinstViewActor_x                                           0xF57DD0
#define pinstWorldData_x                                           0x100B120
#define pinstZoneAddr_x                                            0x101871C
#define pinstPlayerPath_x                                          0x109DCA0
#define pinstTargetIndicator_x                                     0x109E638
#define pinstCTargetManager_x                                      0x109E698

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE19C18
#define pinstCAudioTriggersWindow_x                                0xE19AA8
#define pinstCCharacterSelect_x                                    0xF57C64
#define pinstCFacePick_x                                           0xF57A14
#define pinstCNoteWnd_x                                            0xF57C1C
#define pinstCBookWnd_x                                            0xF57C24
#define pinstCPetInfoWnd_x                                         0xF57C28
#define pinstCTrainWnd_x                                           0xF57C2C
#define pinstCSkillsWnd_x                                          0xF57C30
#define pinstCSkillsSelectWnd_x                                    0xF57C34
#define pinstCCombatSkillsSelectWnd_x                              0xF57C38
#define pinstCFriendsWnd_x                                         0xF57C3C
#define pinstCAuraWnd_x                                            0xF57C40
#define pinstCRespawnWnd_x                                         0xF57C44
#define pinstCBandolierWnd_x                                       0xF57C48
#define pinstCPotionBeltWnd_x                                      0xF57C4C
#define pinstCAAWnd_x                                              0xF57C50
#define pinstCGroupSearchFiltersWnd_x                              0xF57C54
#define pinstCLoadskinWnd_x                                        0xF57C58
#define pinstCAlarmWnd_x                                           0xF57C5C
#define pinstCMusicPlayerWnd_x                                     0xF57C60
#define pinstCMailWnd_x                                            0xF57C68
#define pinstCMailCompositionWnd_x                                 0xF57C6C
#define pinstCMailAddressBookWnd_x                                 0xF57C70
#define pinstCRaidWnd_x                                            0xF57C78
#define pinstCRaidOptionsWnd_x                                     0xF57C7C
#define pinstCBreathWnd_x                                          0xF57C80
#define pinstCMapViewWnd_x                                         0xF57C84
#define pinstCMapToolbarWnd_x                                      0xF57C88
#define pinstCEditLabelWnd_x                                       0xF57C8C
#define pinstCTargetWnd_x                                          0xF57C90
#define pinstCColorPickerWnd_x                                     0xF57C94
#define pinstCPlayerWnd_x                                          0xF57C98
#define pinstCOptionsWnd_x                                         0xF57C9C
#define pinstCBuffWindowNORMAL_x                                   0xF57CA0
#define pinstCBuffWindowSHORT_x                                    0xF57CA4
#define pinstCharacterCreation_x                                   0xF57CA8
#define pinstCCursorAttachment_x                                   0xF57CAC
#define pinstCCastingWnd_x                                         0xF57CB0
#define pinstCCastSpellWnd_x                                       0xF57CB4
#define pinstCSpellBookWnd_x                                       0xF57CB8
#define pinstCInventoryWnd_x                                       0xF57CBC
#define pinstCBankWnd_x                                            0xF57CC4
#define pinstCQuantityWnd_x                                        0xF57CC8
#define pinstCLootWnd_x                                            0xF57CCC
#define pinstCActionsWnd_x                                         0xF57CD0
#define pinstCCombatAbilityWnd_x                                   0xF57CD4
#define pinstCMerchantWnd_x                                        0xF57CD8
#define pinstCTradeWnd_x                                           0xF57CDC
#define pinstCSelectorWnd_x                                        0xF57CE0
#define pinstCBazaarWnd_x                                          0xF57CE4
#define pinstCBazaarSearchWnd_x                                    0xF57CE8
#define pinstCGiveWnd_x                                            0xF57D04
#define pinstCTrackingWnd_x                                        0xF57D0C
#define pinstCInspectWnd_x                                         0xF57D10
#define pinstCSocialEditWnd_x                                      0xF57D14
#define pinstCFeedbackWnd_x                                        0xF57D18
#define pinstCBugReportWnd_x                                       0xF57D1C
#define pinstCVideoModesWnd_x                                      0xF57D20
#define pinstCTextEntryWnd_x                                       0xF57D28
#define pinstCFileSelectionWnd_x                                   0xF57D2C
#define pinstCCompassWnd_x                                         0xF57D30
#define pinstCPlayerNotesWnd_x                                     0xF57D34
#define pinstCGemsGameWnd_x                                        0xF57D38
#define pinstCTimeLeftWnd_x                                        0xF57D3C
#define pinstCPetitionQWnd_x                                       0xF57D58
#define pinstCSoulmarkWnd_x                                        0xF57D5C
#define pinstCStoryWnd_x                                           0xF57D60
#define pinstCJournalTextWnd_x                                     0xF57D64
#define pinstCJournalCatWnd_x                                      0xF57D68
#define pinstCBodyTintWnd_x                                        0xF57D6C
#define pinstCServerListWnd_x                                      0xF57D70
#define pinstCAvaZoneWnd_x                                         0xF57D7C
#define pinstCBlockedBuffWnd_x                                     0xF57D80
#define pinstCBlockedPetBuffWnd_x                                  0xF57D84
#define pinstCInvSlotMgr_x                                         0xF57DC8
#define pinstCContainerMgr_x                                       0xF57DCC
#define pinstCAdventureLeaderboardWnd_x                            0x11AA680
#define pinstCAdventureRequestWnd_x                                0x11AA6F8
#define pinstCAltStorageWnd_x                                      0x11AA9D8
#define pinstCAdventureStatsWnd_x                                  0x11AA770
#define pinstCBarterMerchantWnd_x                                  0x11AB5C0
#define pinstCBarterSearchWnd_x                                    0x11AB638
#define pinstCBarterWnd_x                                          0x11AB6B0
#define pinstCChatManager_x                                        0x11ABD40
#define pinstCDynamicZoneWnd_x                                     0x11AC1F0
#define pinstCEQMainWnd_x                                          0x11AC388
#define pinstCFellowshipWnd_x                                      0x11AC184
#define pinstCFindLocationWnd_x                                    0x11AC658
#define pinstCGroupSearchWnd_x                                     0x11AC928
#define pinstCGroupWnd_x                                           0x11AC9A0
#define pinstCGuildBankWnd_x                                       0x11ACA18
#define pinstCGuildMgmtWnd_x                                       0x11AEB08
#define pinstCHotButtonWnd_x                                       0x11AEBD4
#define pinstCHotButtonWnd1_x                                      0x11AEBD4
#define pinstCHotButtonWnd2_x                                      0x11AEBD8
#define pinstCHotButtonWnd3_x                                      0x11AEBDC
#define pinstCHotButtonWnd4_x                                      0x11AEC00
#define pinstCItemDisplayManager_x                                 0x11AEEF8
#define pinstCItemExpTransferWnd_x                                 0x11AEF74
#define pinstCLFGuildWnd_x                                         0x11AF250
#define pinstCMIZoneSelectWnd_x                                    0x11AF838
#define pinstCConfirmationDialog_x                                 0x11AFF40
#define pinstCPopupWndManager_x                                    0x11AFF40
#define pinstCProgressionSelectionWnd_x                            0x11B0030
#define pinstCPvPStatsWnd_x                                        0x11B0120
#define pinstCSystemInfoDialogBox_x                                0x11B0828
#define pinstCTaskWnd_x                                            0x11B1BF0
#define pinstCTaskSomething_x                                      0xE25E48
#define pinstCTaskTemplateSelectWnd_x                              0x11B1B78
#define pinstCTipWndOFDAY_x                                        0x11B1E48
#define pinstCTipWndCONTEXT_x                                      0x11B1E4C
#define pinstCTitleWnd_x                                           0x11B1EC8
#define pinstCContextMenuManager_x                                 0x1815884
#define pinstCVoiceMacroWnd_x                                      0x109EB08
#define pinstCHtmlWnd_x                                            0x109EBF8
#define pinstIconCache_x                                           0x11AC35C
#define pinstCTradeskillWnd_x                                      0x11B1FC8
#define pinstCAdvancedLootWnd_x                                    0xF57DBC
#define pinstRewardSelectionWnd_x                                  0x11B0648

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x533330
#define __ConvertItemTags_x                                        0x520740
#define __ExecuteCmd_x                                             0x50B4E0
#define __EQGetTime_x                                              0x89CF30
#define __get_melee_range_x                                        0x512140
#define __GetGaugeValueFromEQ_x                                    0x7A6F80
#define __GetLabelFromEQ_x                                         0x7A81D0
#define __ToggleKeyRingItem_x                                      0x47F840
#define __GetXTargetType_x                                         0x92E170
#define __LoadFrontEnd_x                                           0x636FD0
#define __NewUIINI_x                                               0x7A6950
#define __ProcessGameEvents_x                                      0x577B10
#define __ProcessMouseEvent_x                                      0x5772B0
#define CrashDetected_x                                            0x638990
#define wwsCrashReportCheckForUploader_x                           0x7FA8D0
#define DrawNetStatus_x                                            0x5ADB60
#define Util__FastTime_x                                           0x89CA40
#define Expansion_HoT_x                                            0x1019560
#define __HelpPath_x                                               0x109CC58
#define __STMLToText_x                                             0x8E2D50

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x4202E0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x41B130
#define CAdvancedLootWnd__DoSharedAdvLootAction_x                  0x41AF10

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C6080
#define AltAdvManager__IsAbilityReady_x                            0x4C60F0
#define AltAdvManager__GetAAById_x                                 0x4C64B0
#define AltAdvManager__CanTrainAbility_x                           0x4C6D70
#define AltAdvManager__CanSeeAbility_x                             0x4C6970

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465400
#define CharacterZoneClient__MakeMeVisible_x                       0x46AF30
#define CharacterZoneClient__IsStackBlocked_x                      0x448FD0
#define CharacterZoneClient__CanUseMemorizedSpellSlot_x            0x448490
#define CharacterZoneClient__GetItemCountWorn_x                    0x462CA0
#define CharacterZoneClient__GetItemCountInInventory_x             0x462D90
#define CharacterZoneClient__GetCursorItemCount_x                  0x462E90

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6668D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x674FE0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58CEE0
#define CButtonWnd__CButtonWnd_x                                   0x8D6FB0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68FC40
#define CChatManager__InitContextMenu_x                            0x6907C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E10D0
#define CContextMenu__dCContextMenu_x                              0x8E12D0
#define CContextMenu__AddMenuItem_x                                0x8E12E0
#define CContextMenu__RemoveMenuItem_x                             0x8E15C0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E15E0
#define CContextMenuManager__AddMenu_x                             0x8CD550
#define CContextMenuManager__RemoveMenu_x                          0x8CD870
#define CContextMenuManager__PopupMenu_x                           0x8CDCC0
#define CContextMenuManager__Flush_x                               0x8CD5C0
#define CContextMenuManager__GetMenu_x                             0x416780

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8821B0
#define CChatService__GetFriendName_x                              0x8821C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x695A10
#define CChatWindow__Clear_x                                       0x6955E0
#define CChatWindow__WndNotification_x                             0x695F40

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D13A0
#define CComboWnd__Draw_x                                          0x8D15B0
#define CComboWnd__GetCurChoice_x                                  0x8D1170
#define CComboWnd__GetListRect_x                                   0x8D1850
#define CComboWnd__GetTextRect_x                                   0x8D1410
#define CComboWnd__InsertChoice_x                                  0x8D18C0
#define CComboWnd__SetColors_x                                     0x8D1100
#define CComboWnd__SetChoice_x                                     0x8D1130
#define CComboWnd__GetItemCount_x                                  0x8D1160
#define CComboWnd__GetCurChoiceText_x                              0x8D11B0


// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69F000
#define CContainerWnd__vftable_x                                   0xADED60

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B4420
#define CDisplay__GetClickedActor_x                                0x4ACD00
#define CDisplay__GetUserDefinedColor_x                            0x4AB8E0
#define CDisplay__GetWorldFilePath_x                               0x4AAD30
#define CDisplay__is3dON_x                                         0x4AA1B0
#define CDisplay__ReloadUI_x                                       0x4BFA00
#define CDisplay__WriteTextHD2_x                                   0x4B0770

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F7780

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E55D0
#define CEditWnd__GetCharIndexPt_x                                 0x8E6650
#define CEditWnd__GetDisplayString_x                               0x8E5780
#define CEditWnd__GetHorzOffset_x                                  0x8E5AC0
#define CEditWnd__GetLineForPrintableChar_x                        0x8E6120
#define CEditWnd__GetSelStartPt_x                                  0x8E6900
#define CEditWnd__GetSTMLSafeText_x                                0x8E5C50
#define CEditWnd__PointFromPrintableChar_x                         0x8E6210
#define CEditWnd__SelectableCharFromPoint_x                        0x8E6390
#define CEditWnd__SetEditable_x                                    0x8E5C20

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x554C60
#define CEverQuest__CreateTargetIndicator_x                        0x555890
#define CEverQuest__DeleteTargetIndicator_x                        0x555910
#define CEverQuest__DoTellWindow_x                                 0x55A660
#define CEverQuest__DropHeldItemOnGround_x                         0x5635C0
#define CEverQuest__dsp_chat_x                                     0x55C100
#define CEverQuest__Emote_x                                        0x55C360
#define CEverQuest__EnterZone_x                                    0x5707D0
#define CEverQuest__GetBodyTypeDesc_x                              0x5513F0
#define CEverQuest__GetClassDesc_x                                 0x5571D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5577D0
#define CEverQuest__GetDeityDesc_x                                 0x551CD0
#define CEverQuest__GetLangDesc_x                                  0x551780
#define CEverQuest__GetRaceDesc_x                                  0x557990
#define CEverQuest__InterpretCmd_x                                 0x55CC40
#define CEverQuest__LeftClickedOnPlayer_x                          0x574210
#define CEverQuest__LMouseUp_x                                     0x576300
#define CEverQuest__RightClickedOnPlayer_x                         0x574D10
#define CEverQuest__RMouseUp_x                                     0x575D60
#define CEverQuest__SetGameState_x                                 0x555310
#define CEverQuest__UPCNotificationFlush_x                         0x55DFA0
#define CEverQuest__IssuePetCommand_x                              0x55D900

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AFD20
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AFD80
#define CGaugeWnd__Draw_x                                          0x6B01B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x436DA0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CC7F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D8F00
#define CInvSlotMgr__MoveItem_x                                    0x6D9E40
#define CInvSlotMgr__SelectSlot_x                                  0x6D8FB0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D8390
#define CInvSlot__SliderComplete_x                                 0x6D5BD0
#define CInvSlot__GetItemBase_x                                    0x6D5050

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DB230

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A39E0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DC580

// CLabel 
#define CLabel__Draw_x                                             0x6F7350

// CListWnd
#define CListWnd__CListWnd_x                                       0x8BD2B0
#define CListWnd__dCListWnd_x                                      0x8BE2E0
#define CListWnd__AddColumn_x                                      0x8BE280
#define CListWnd__AddColumn1_x                                     0x8BDAF0
#define CListWnd__AddLine_x                                        0x8BD570
#define CListWnd__AddString_x                                      0x8BD780
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BA610
#define CListWnd__CalculateVSBRange_x                              0x8BC770
#define CListWnd__ClearSel_x                                       0x8B9920
#define CListWnd__ClearAllSel_x                                    0x8B98D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BD140
#define CListWnd__Compare_x                                        0x8BB100
#define CListWnd__Draw_x                                           0x8BC380
#define CListWnd__DrawColumnSeparators_x                           0x8BC210
#define CListWnd__DrawHeader_x                                     0x8B9BE0
#define CListWnd__DrawItem_x                                       0x8BB750
#define CListWnd__DrawLine_x                                       0x8BBEB0
#define CListWnd__DrawSeparator_x                                  0x8BC2B0
#define CListWnd__EnsureVisible_x                                  0x8BA770
#define CListWnd__ExtendSel_x                                      0x8BB660
#define CListWnd__GetColumnMinWidth_x                              0x8B9290
#define CListWnd__GetColumnWidth_x                                 0x8B91B0
#define CListWnd__GetCurSel_x                                      0x8B8980
#define CListWnd__GetItemAtPoint_x                                 0x8BA9F0
#define CListWnd__GetItemAtPoint1_x                                0x8BAA60
#define CListWnd__GetItemData_x                                    0x8B8CC0
#define CListWnd__GetItemHeight_x                                  0x8BA270
#define CListWnd__GetItemIcon_x                                    0x8B8EA0
#define CListWnd__GetItemRect_x                                    0x8BA830
#define CListWnd__GetItemText_x                                    0x8B8D50
#define CListWnd__GetSelList_x                                     0x8BD9E0
#define CListWnd__GetSeparatorRect_x                               0x8BB020
#define CListWnd__RemoveLine_x                                     0x8BD960
#define CListWnd__SetColors_x                                      0x8B8AD0
#define CListWnd__SetColumnJustification_x                         0x8B9560
#define CListWnd__SetColumnWidth_x                                 0x8B9240
#define CListWnd__SetCurSel_x                                      0x8B89C0
#define CListWnd__SetItemColor_x                                   0x8BCE20
#define CListWnd__SetItemData_x                                    0x8B9980
#define CListWnd__SetItemText_x                                    0x8BCC60
#define CListWnd__ShiftColumnSeparator_x                           0x8BCAF0
#define CListWnd__Sort_x                                           0x8BE3E0
#define CListWnd__ToggleSel_x                                      0x8B9850

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7102F0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x731600
#define CMerchantWnd__RequestBuyItem_x                             0x738430
#define CMerchantWnd__RequestSellItem_x                            0x738EA0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7318B0
#define CMerchantWnd__SelectBuySellSlot_x                          0x730B10
#define CMerchantWnd__ActualSelect_x                               0x735370

// CPacketScrambler
#define CPacketScrambler__ntoh_x                                   0x84F0C0
#define CPacketScrambler__hton_x                                   0x84F0D0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8DBF70
#define CSidlManager__CreateLabel_x                                0x7999C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65DC00
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65DB30
#define CSidlScreenWnd__ConvertToRes_x                             0x8F7660
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D3D00
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D4EE0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D4F90
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D4450
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D36B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D2E30
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D38A0
#define CSidlScreenWnd__Init1_x                                    0x8D4BB0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D3DB0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D2FF0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D46A0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D2A90
#define CSidlScreenWnd__StoreIniVis_x                              0x8D2DE0
#define CSidlScreenWnd__WndNotification_x                          0x8D4930
#define CSidlScreenWnd__GetChildItem_x                             0x8D2F00
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C6770

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F8BD0
#define CSkillMgr__GetSkillCap_x                                   0x5F8D90
#define CSkillMgr__GetNameToken_x                                  0x5F87F0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F6920
#define CSliderWnd__SetValue_x                                     0x8F6AF0
#define CSliderWnd__SetNumTicks_x                                  0x8F7270

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A1690

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F22B0
#define CStmlWnd__CalculateHSBRange_x                              0x8EA7F0
#define CStmlWnd__CalculateVSBRange_x                              0x8EA880
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EAA00
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EB2E0
#define CStmlWnd__ForceParseNow_x                                  0x8F2C00
#define CStmlWnd__GetNextTagPiece_x                                0x8EB1E0
#define CStmlWnd__GetSTMLText_x                                    0x694E80
#define CStmlWnd__GetVisibleText_x                                 0x8EBD30
#define CStmlWnd__InitializeWindowVariables_x                      0x8EE0B0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E9AF0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E9B50
#define CStmlWnd__SetSTMLText_x                                    0x8EF910
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F1F50
#define CStmlWnd__UpdateHistoryString_x                            0x8ECC70

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E9180
#define CTabWnd__DrawCurrentPage_x                                 0x8E89F0
#define CTabWnd__DrawTab_x                                         0x8E87C0
#define CTabWnd__GetCurrentPage_x                                  0x8E8DC0
#define CTabWnd__GetPageInnerRect_x                                0x8E84B0
#define CTabWnd__GetTabInnerRect_x                                 0x8E86B0
#define CTabWnd__GetTabRect_x                                      0x8E8580
#define CTabWnd__InsertPage_x                                      0x8E9470
#define CTabWnd__SetPage_x                                         0x8E8DF0
#define CTabWnd__SetPageRect_x                                     0x8E90C0
#define CTabWnd__UpdatePage_x                                      0x8E9410

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x432C20

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D0D70

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FCAE0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B6B40

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4029D0
#define CXStr__CXStr1_x                                            0x8AB7A0
#define CXStr__CXStr3_x                                            0x899B00
#define CXStr__dCXStr_x                                            0x59A950
#define CXStr__operator_equal_x                                    0x899C70
#define CXStr__operator_equal1_x                                   0x899CC0
#define CXStr__operator_plus_equal1_x                              0x89ADE0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C59B0
#define CXWnd__Center_x                                            0x8CBB50
#define CXWnd__ClrFocus_x                                          0x8C5590
#define CXWnd__DoAllDrawing_x                                      0x8CB7A0
#define CXWnd__DrawChildren_x                                      0x8CB940
#define CXWnd__DrawColoredRect_x                                   0x8C5D60
#define CXWnd__DrawTooltip_x                                       0x8C6000
#define CXWnd__DrawTooltipAtPoint_x                                0x8CA710
#define CXWnd__GetBorderFrame_x                                    0x8C6460
#define CXWnd__GetChildWndAt_x                                     0x8CC520
#define CXWnd__GetClientClipRect_x                                 0x8C6220
#define CXWnd__GetScreenClipRect_x                                 0x8CAE00
#define CXWnd__GetScreenRect_x                                     0x8C6610
#define CXWnd__GetTooltipRect_x                                    0x8C5E90
#define CXWnd__GetWindowTextA_x                                    0x424280
#define CXWnd__IsActive_x                                          0x8C1080
#define CXWnd__IsDescendantOf_x                                    0x8C63B0
#define CXWnd__IsReallyVisible_x                                   0x8C9740
#define CXWnd__IsType_x                                            0x8F9300
#define CXWnd__Move_x                                              0x8C8E30
#define CXWnd__Move1_x                                             0x8CB450
#define CXWnd__ProcessTransition_x                                 0x8C5950
#define CXWnd__Refade_x                                            0x8C5720
#define CXWnd__Resize_x                                            0x8C66D0
#define CXWnd__Right_x                                             0x8CAC00
#define CXWnd__SetFocus_x                                          0x8C7F90
#define CXWnd__SetFont_x                                           0x8C55E0
#define CXWnd__SetKeyTooltip_x                                     0x8C6940
#define CXWnd__SetMouseOver_x                                      0x8CB140
#define CXWnd__StartFade_x                                         0x8C5A00
#define CXWnd__GetChildItem_x                                      0x8CB080

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C2900
#define CXWndManager__DrawWindows_x                                0x8C2540
#define CXWndManager__GetKeyboardFlags_x                           0x8C0BF0
#define CXWndManager__HandleKeyboardMsg_x                          0x8C1510
#define CXWndManager__RemoveWnd_x                                  0x8C1210

// CDBStr
#define CDBStr__GetString_x                                        0x4A86D0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44F580
#define EQ_Character__Cur_HP_x                                     0x464AD0
#define EQ_Character__Cur_Mana_x                                   0x457B20
#define EQ_Character__GetAACastingTimeModifier_x                   0x4487A0
#define EQ_Character__GetCharInfo2_x                               0x86E3D0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F930
#define EQ_Character__GetFocusRangeModifier_x                      0x43FB80
#define EQ_Character__Max_Endurance_x                              0x5C0320
#define EQ_Character__Max_HP_x                                     0x45A720
#define EQ_Character__Max_Mana_x                                   0x5C0150
#define EQ_Character__doCombatAbility_x                            0x5BD790
#define EQ_Character__UseSkill_x                                   0x470110
#define EQ_Character__GetConLevel_x                                0x5B21D0
#define EQ_Character__IsExpansionFlag_x                            0x4237D0
#define EQ_Character__TotalEffect_x                                0x44C7C0
#define EQ_Character__GetPCSpellAffect_x                           0x448BA0
#define EQ_Character__SpellDuration_x                              0x446AC0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5927C0
#define EQ_Item__CreateItemTagString_x                             0x84DA40
#define EQ_Item__IsStackable_x                                     0x8422A0
#define EQ_Item__GetImageNum_x                                     0x844D40
#define EQ_Item__CreateItemClient_x                                0x593390
#define EQ_Item__GetItemValue_x                                    0x84C7A0
#define EQ_Item__ValueSellMerchant_x                               0x84ED20

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C8170
#define EQ_LoadingS__Array_x                                       0xC1B738

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C1970
#define EQ_PC__GetAlternateAbilityId_x                             0x856F10
#define EQ_PC__GetCombatAbility_x                                  0x856FA0
#define EQ_PC__GetCombatAbilityTimer_x                             0x851EB0
#define EQ_PC__GetItemTimerValue_x                                 0x5BB230
#define EQ_PC__HasLoreItem_x                                       0x5B56B0
#define EQ_PC__AlertInventoryChanged_x                             0x5B21A0
#define EQ_PC__GetPcZoneClient_x                                   0x5DBFE0
#define EQ_PC__RemoveMyAffect_x                                    0x5BA6E0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x510160
#define EQItemList__add_item_x                                     0x5100A0
#define EQItemList__delete_item_x                                  0x510560
#define EQItemList__FreeItemList_x                                 0x510460

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A79B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C6EF0
#define EQPlayer__dEQPlayer_x                                      0x5CFDD0
#define EQPlayer__DoAttack_x                                       0x5E1F60
#define EQPlayer__EQPlayer_x                                       0x5D21F0
#define EQPlayer__SetNameSpriteState_x                             0x5CCCA0
#define EQPlayer__SetNameSpriteTint_x                              0x5C8320
#define PlayerBase__HasProperty_j_x                                0x92A3C0
#define EQPlayer__IsTargetable_x                                   0x92ACC0
#define EQPlayer__CanSee_x                                         0x92B1E0
#define PlayerZoneClient__ChangeHeight_x                           0x5E1E20
#define EQPlayer__CanSeeTargetIndicator_x                          0x92B2D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D6530
#define EQPlayerManager__GetSpawnByName_x                          0x5D6990
#define EQPlayerManager__GetPlayerFromPartialName_x                0x5D6560

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x598950
#define KeypressHandler__AttachKeyToEqCommand_x                    0x598990
#define KeypressHandler__ClearCommandStateArray_x                  0x598540
#define KeypressHandler__HandleKeyDown_x                           0x596EA0
#define KeypressHandler__HandleKeyUp_x                             0x5971C0
#define KeypressHandler__SaveKeymapping_x                          0x598610

// MapViewMap 
#define MapViewMap__Clear_x                                        0x708CA0
#define MapViewMap__SaveEx_x                                       0x70BFB0

#define PlayerPointManager__GetAltCurrency_x                       0x8693D0

// StringTable 
#define StringTable__getString_x                                   0x863F10

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BFDD0
#define PcZoneClient__RemovePetEffect_x                            0x5BB720
#define PcZoneClient__HasAlternateAbility_x                        0x5BC1E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54E6A0

//IconCache
#define IconCache__GetIcon_x                                       0x6A5510

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69C330
#define CContainerMgr__CloseContainer_x                            0x69CB50

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x769D40

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58B980

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4E0170
#define EQ_Spell__SpellAffects_x                                   0x4DD820
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DD890
#define CharacterZoneClient__CalcAffectChange_x                    0x447BE0
#define CLootWnd__LootAll_x                                        0x6FE660

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AF400
#define CTargetWnd__WndNotification_x                              0x7AEEF0
#define CTargetWnd__UpdateBuffs_x                                  0x7AF5E0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B45D0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D9190

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x498030

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E4C00
#define CSidlManager__FindAnimation1_x                             0x8D9E70

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CF7C0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CF770
#define CAltAbilityData__GetMaxRank_x                              0x4C4740

//CTargetRing
#define CTargetRing__Cast_x                                        0x589260

//CharacterBase
#define CharacterBase__GetMemorizedSpell_x                         0x4564D0

//CCastSpellWnd
#define CCastSpellWnd__ForgetMemorizedSpell_x                      0x686D80
#define CCastSpellWnd__IsBardSongPlaying_x                         0x686540

//messages
#define msg_spell_worn_off_x                                       0x4E7B80
#define msg_new_text_x                                             0x4F0FB0
#define msgTokenTextParam_x                                        0x4ED970
