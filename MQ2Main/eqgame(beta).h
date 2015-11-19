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
#define __ExpectedVersionDate                                     "Nov 17 2015"
#define __ExpectedVersionTime                                     "04:19:31"
#define __ActualVersionDate_x                                      0xADA610
#define __ActualVersionTime_x                                      0xADA61C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5A0800
#define __MemChecker1_x                                            0x8A2190
#define __MemChecker2_x                                            0x6399F0
#define __MemChecker3_x                                            0x639940
#define __MemChecker4_x                                            0x7EE780
#define __EncryptPad0_x                                            0xC75D08
#define __EncryptPad1_x                                            0xE00DE8
#define __EncryptPad2_x                                            0xCBF7F0
#define __EncryptPad3_x                                            0xCBF3F0
#define __EncryptPad4_x                                            0xDD9F78
#define __EncryptPad5_x                                            0x11ACC60
#define __AC1_x                                                    0x7AB795
#define __AC2_x                                                    0x554C17
#define __AC3_x                                                    0x5697D0
#define __AC4_x                                                    0x570310
#define __AC5_x                                                    0x57CA5E
#define __AC6_x                                                    0x5805A9
#define __AC7_x                                                    0x57710C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data                                                 0x845EC

// Direct Input
#define DI8__Main_x                                                0x11ACC38
#define DI8__Keyboard_x                                            0x11ACC3C
#define DI8__Mouse_x                                               0x11ACC40
#define DI8__Mouse_Copy_x                                          0x101B254
#define DI8__Mouse_Check_x                                         0x10A4B24
#define __AltTimerReady_x                                          0x100C5A1
#define __Attack_x                                                 0x109F7C7
#define __Autofire_x                                               0x109F7C8
#define __BindList_x                                               0xC37DD8
#define __bCommandEnabled_x                                        0x100A6B0
#define __Clicks_x                                                 0x101B310
#define __CommandList_x                                            0xC3C148
#define __CurrentMapLabel_x                                        0x11B2690
#define __CurrentSocial_x                                          0xBEEF44
#define __DoAbilityList_x                                          0x1051A7C
#define __do_loot_x                                                0x51C180
#define __DrawHandler_x                                            0x1819444
#define __GroupCount_x                                             0x100BC7A

#define __Guilds_x                                                 0x1011890
#define __gWorld_x                                                 0x100E134
#define __HotkeyPage_x                                             0x109847C
#define __HWnd_x                                                   0x10A4B40
#define __InChatMode_x                                             0x101B23C
#define __LastTell_x                                               0x101D180
#define __LMouseHeldTime_x                                         0x101B37C
#define __Mouse_x                                                  0x11ACC44
#define __MouseLook_x                                              0x101B2D6
#define __MouseEventTime_x                                         0x109FFCC
#define __gpbCommandEvent_x                                        0x100E1FC
#define __NetStatusToggle_x                                        0x101B2D9
#define __PCNames_x                                                0x101C7A0
#define __RangeAttackReady_x                                       0x101C460
#define __RMouseHeldTime_x                                         0x101B378
#define __RunWalkState_x                                           0x101B240
#define __ScreenMode_x                                             0xF5A3E0
#define __ScreenX_x                                                0x101B1F4
#define __ScreenY_x                                                0x101B1F0
#define __ScreenXMax_x                                             0x101B1F8
#define __ScreenYMax_x                                             0x101B1FC
#define __ServerHost_x                                             0x100BBC4
#define __ServerName_x                                             0x1051A3C
#define __ShiftKeyDown_x                                           0x101B8E4
#define __ShowNames_x                                              0x101C634
#define __Socials_x                                                0x1051B3C
#define __SubscriptionType_x                                       0x11E0BC0
#define __TargetAggroHolder_x                                      0x11B48CC
#define __GroupAggro_x                                             0x11B490C
#define __LoginName_x                                              0x10A3718
#define __Inviter_x                                                0x109F744


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x100E220
#define instEQZoneInfo_x                                           0x101B4CC
#define instKeypressHandler_x                                      0x109FFB0
#define pinstActiveBanker_x                                        0x100E1D8
#define pinstActiveCorpse_x                                        0x100E1DC
#define pinstActiveGMaster_x                                       0x100E1E0
#define pinstActiveMerchant_x                                      0x100E1D4
#define pinstAggroInfo_x                                           0xE1C7D8
#define pinstAltAdvManager_x                                       0xF5B4E8
#define pinstAuraMgr_x                                             0xE286A8
#define pinstBandageTarget_x                                       0x100E1C0
#define pinstCamActor_x                                            0xF5ADF0
#define pinstCDBStr_x                                              0xF5A374
#define pinstCDisplay_x                                            0x100E1E8
#define pinstCEverQuest_x                                          0x11ACDB8
#define pinstCharData_x                                            0x100E1A4
#define pinstCharSpawn_x                                           0x100E1CC
#define pinstControlledMissile_x                                   0x100E1A0
#define pinstControlledPlayer_x                                    0x100E1CC
#define pinstCSidlManager_x                                        0x181887C
#define pinstCXWndManager_x                                        0x1818874
#define instDynamicZone_x                                          0x101B088
#define pinstDZMember_x                                            0x101B198
#define pinstDZTimerInfo_x                                         0x101B19C
#define pinstEQItemList_x                                          0x100A900
#define instEQMisc_x                                               0xC112C8
#define pinstEQSoundManager_x                                      0xF5BA48
#define instExpeditionLeader_x                                     0x101B0D2
#define instExpeditionName_x                                       0x101B112
#define pinstGroup_x                                               0x100BC76
#define pinstImeManager_x                                          0x1818880
#define pinstLocalPlayer_x                                         0x100E1B8
#define pinstMercenaryData_x                                       0x10A0600
#define pinstMercenaryStats_x                                      0x11B4A18
#define pinstMercAltAbilities_x                                    0xF5B874
#define pinstModelPlayer_x                                         0x100E1E4
#define pinstPCData_x                                              0x100E1A4
#define pinstSkillMgr_x                                            0x10A1438
#define pinstSpawnManager_x                                        0x10A0D20
#define pinstSpellManager_x                                        0x10A1580
#define pinstSpellSets_x                                           0x10984E0
#define pinstStringTable_x                                         0x100E14C
#define pinstSwitchManager_x                                       0x100B808
#define pinstTarget_x                                              0x100E1D0
#define pinstTargetObject_x                                        0x100E1A8
#define pinstTargetSwitch_x                                        0x100E1AC
#define pinstTaskMember_x                                          0xF5A2C0
#define pinstTrackTarget_x                                         0x100E1C4
#define pinstTradeTarget_x                                         0x100E1B4
#define instTributeActive_x                                        0xC112ED
#define pinstViewActor_x                                           0xF5ADEC
#define pinstWorldData_x                                           0x100E188
#define pinstZoneAddr_x                                            0x101B78C
#define pinstPlayerPath_x                                          0x109CEA0
#define pinstTargetIndicator_x                                     0x109D838
#define pinstCTargetManager_x                                      0x10A1778

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE1CCB8
#define pinstCAudioTriggersWindow_x                                0xE1CB48
#define pinstCCharacterSelect_x                                    0xF5AC80
#define pinstCFacePick_x                                           0xF5AC30
#define pinstCNoteWnd_x                                            0xF5AC38
#define pinstCBookWnd_x                                            0xF5AC40
#define pinstCPetInfoWnd_x                                         0xF5AC44
#define pinstCTrainWnd_x                                           0xF5AC48
#define pinstCSkillsWnd_x                                          0xF5AC4C
#define pinstCSkillsSelectWnd_x                                    0xF5AC50
#define pinstCCombatSkillsSelectWnd_x                              0xF5AC54
#define pinstCFriendsWnd_x                                         0xF5AC58
#define pinstCAuraWnd_x                                            0xF5AC5C
#define pinstCRespawnWnd_x                                         0xF5AC60
#define pinstCBandolierWnd_x                                       0xF5AC64
#define pinstCPotionBeltWnd_x                                      0xF5AC68
#define pinstCAAWnd_x                                              0xF5AC6C
#define pinstCGroupSearchFiltersWnd_x                              0xF5AC70
#define pinstCLoadskinWnd_x                                        0xF5AC74
#define pinstCAlarmWnd_x                                           0xF5AC78
#define pinstCMusicPlayerWnd_x                                     0xF5AC7C
#define pinstCMailWnd_x                                            0xF5AC84
#define pinstCMailCompositionWnd_x                                 0xF5AC88
#define pinstCMailAddressBookWnd_x                                 0xF5AC8C
#define pinstCRaidWnd_x                                            0xF5AC94
#define pinstCRaidOptionsWnd_x                                     0xF5AC98
#define pinstCBreathWnd_x                                          0xF5AC9C
#define pinstCMapViewWnd_x                                         0xF5ACA0
#define pinstCMapToolbarWnd_x                                      0xF5ACA4
#define pinstCEditLabelWnd_x                                       0xF5ACA8
#define pinstCTargetWnd_x                                          0xF5ACAC
#define pinstCColorPickerWnd_x                                     0xF5ACB0
#define pinstCPlayerWnd_x                                          0xF5ACB4
#define pinstCOptionsWnd_x                                         0xF5ACB8
#define pinstCBuffWindowNORMAL_x                                   0xF5ACBC
#define pinstCBuffWindowSHORT_x                                    0xF5ACC0
#define pinstCharacterCreation_x                                   0xF5ACC4
#define pinstCCursorAttachment_x                                   0xF5ACC8
#define pinstCCastingWnd_x                                         0xF5ACCC
#define pinstCCastSpellWnd_x                                       0xF5ACD0
#define pinstCSpellBookWnd_x                                       0xF5ACD4
#define pinstCInventoryWnd_x                                       0xF5ACD8
#define pinstCBankWnd_x                                            0xF5ACE0
#define pinstCQuantityWnd_x                                        0xF5ACE4
#define pinstCLootWnd_x                                            0xF5ACE8
#define pinstCActionsWnd_x                                         0xF5ACEC
#define pinstCCombatAbilityWnd_x                                   0xF5ACF0
#define pinstCMerchantWnd_x                                        0xF5ACF4
#define pinstCTradeWnd_x                                           0xF5ACF8
#define pinstCSelectorWnd_x                                        0xF5ACFC
#define pinstCBazaarWnd_x                                          0xF5AD00
#define pinstCBazaarSearchWnd_x                                    0xF5AD04
#define pinstCGiveWnd_x                                            0xF5AD20
#define pinstCTrackingWnd_x                                        0xF5AD28
#define pinstCInspectWnd_x                                         0xF5AD2C
#define pinstCSocialEditWnd_x                                      0xF5AD30
#define pinstCFeedbackWnd_x                                        0xF5AD34
#define pinstCBugReportWnd_x                                       0xF5AD38
#define pinstCVideoModesWnd_x                                      0xF5AD3C
#define pinstCTextEntryWnd_x                                       0xF5AD44
#define pinstCFileSelectionWnd_x                                   0xF5AD48
#define pinstCCompassWnd_x                                         0xF5AD4C
#define pinstCPlayerNotesWnd_x                                     0xF5AD50
#define pinstCGemsGameWnd_x                                        0xF5AD54
#define pinstCTimeLeftWnd_x                                        0xF5AD58
#define pinstCPetitionQWnd_x                                       0xF5AD74
#define pinstCSoulmarkWnd_x                                        0xF5AD78
#define pinstCStoryWnd_x                                           0xF5AD7C
#define pinstCJournalTextWnd_x                                     0xF5AD80
#define pinstCJournalCatWnd_x                                      0xF5AD84
#define pinstCBodyTintWnd_x                                        0xF5AD88
#define pinstCServerListWnd_x                                      0xF5AD8C
#define pinstCAvaZoneWnd_x                                         0xF5AD98
#define pinstCBlockedBuffWnd_x                                     0xF5AD9C
#define pinstCBlockedPetBuffWnd_x                                  0xF5ADA0
#define pinstCInvSlotMgr_x                                         0xF5ADE4
#define pinstCContainerMgr_x                                       0xF5ADE8
#define pinstCAdventureLeaderboardWnd_x                            0x11AD768
#define pinstCAdventureRequestWnd_x                                0x11AD7E0
#define pinstCAltStorageWnd_x                                      0x11ADAC0
#define pinstCAdventureStatsWnd_x                                  0x11AD858
#define pinstCBarterMerchantWnd_x                                  0x11AE6A8
#define pinstCBarterSearchWnd_x                                    0x11AE720
#define pinstCBarterWnd_x                                          0x11AE798
#define pinstCChatManager_x                                        0x11AEE28
#define pinstCDynamicZoneWnd_x                                     0x11AF2D8
#define pinstCEQMainWnd_x                                          0x11AF470
#define pinstCFellowshipWnd_x                                      0x11AF26C
#define pinstCFindLocationWnd_x                                    0x11AF740
#define pinstCGroupSearchWnd_x                                     0x11AFA10
#define pinstCGroupWnd_x                                           0x11AFA88
#define pinstCGuildBankWnd_x                                       0x11AFB00
#define pinstCGuildMgmtWnd_x                                       0x11B1BF0
#define pinstCHotButtonWnd_x                                       0x11B1CBC
#define pinstCHotButtonWnd1_x                                      0x11B1CBC
#define pinstCHotButtonWnd2_x                                      0x11B1CC0
#define pinstCHotButtonWnd3_x                                      0x11B1CC4
#define pinstCHotButtonWnd4_x                                      0x11B1CE8
#define pinstCItemDisplayManager_x                                 0x11B1FE0
#define pinstCItemExpTransferWnd_x                                 0x11B205C
#define pinstCLFGuildWnd_x                                         0x11B2338
#define pinstCMIZoneSelectWnd_x                                    0x11B2920
#define pinstCConfirmationDialog_x                                 0x11B3028
#define pinstCPopupWndManager_x                                    0x11B3028
#define pinstCProgressionSelectionWnd_x                            0x11B3118
#define pinstCPvPStatsWnd_x                                        0x11B3208
#define pinstCSystemInfoDialogBox_x                                0x11B3910
#define pinstCTaskWnd_x                                            0x11B4CD8
#define pinstCTaskSomething_x                                      0xE28E68
#define pinstCTaskTemplateSelectWnd_x                              0x11B4C60
#define pinstCTipWndOFDAY_x                                        0x11B4F30
#define pinstCTipWndCONTEXT_x                                      0x11B4F34
#define pinstCTitleWnd_x                                           0x11B4FB0
#define pinstCContextMenuManager_x                                 0x18187EC
#define pinstCVoiceMacroWnd_x                                      0x10A1BE8
#define pinstCHtmlWnd_x                                            0x10A1CE0
#define pinstIconCache_x                                           0x11AF444
#define pinstCTradeskillWnd_x                                      0x11B50B0
#define pinstCAdvancedLootWnd_x                                    0xF5ADD8
#define pinstRewardSelectionWnd_x                                  0x11B3730

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x533CD0
#define __ConvertItemTags_x                                        0x520E00
#define __ExecuteCmd_x                                             0x50B920
#define __EQGetTime_x                                              0x8A24F0
#define __get_melee_range_x                                        0x5125C0
#define __GetGaugeValueFromEQ_x                                    0x7AA4D0
#define __GetLabelFromEQ_x                                         0x7AB720
#define __ToggleKeyRingItem_x                                      0x47E150
#define __GetXTargetType_x                                         0x933690
#define __LoadFrontEnd_x                                           0x6390A0
#define __NewUIINI_x                                               0x7A9DD0
#define __ProcessGameEvents_x                                      0x578E70
#define __ProcessMouseEvent_x                                      0x578610
#define CrashDetected_x                                            0x63AB70
#define wwsCrashReportCheckForUploader_x                           0x7FDF10
#define DrawNetStatus_x                                            0x5B0340
#define Util__FastTime_x                                           0x8A1E30
#define Expansion_HoT_x                                            0x101C5CC
#define __HelpPath_x                                               0x109FD38
#define __STMLToText_x                                             0x8E7070

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F160
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419FC0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C5460
#define AltAdvManager__IsAbilityReady_x                            0x4C54D0
#define AltAdvManager__GetAAById_x                                 0x4C5890

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x464280
#define CharacterZoneClient__MakeMeVisible_x                       0x469C60
#define CharacterZoneClient__IsStackBlocked_x                      0x446420

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x668A90

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x676E50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58F750
#define CButtonWnd__CButtonWnd_x                                   0x8DB2C0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x691D40
#define CChatManager__InitContextMenu_x                            0x6928C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E53E0
#define CContextMenu__dCContextMenu_x                              0x8E55F0
#define CContextMenu__AddMenuItem_x                                0x8E5600
#define CContextMenu__RemoveMenuItem_x                             0x8E58E0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E5900
#define CContextMenuManager__AddMenu_x                             0x8D1260
#define CContextMenuManager__RemoveMenu_x                          0x8D15A0
#define CContextMenuManager__PopupMenu_x                           0x8D19F0
#define CContextMenuManager__Flush_x                               0x8D12D0
#define CContextMenuManager__GetMenu_x                             0x415600

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x887710
#define CChatService__GetFriendName_x                              0x887720

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x697B70
#define CChatWindow__Clear_x                                       0x697720
#define CChatWindow__WndNotification_x                             0x6980B0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D5160
#define CComboWnd__Draw_x                                          0x8D5370
#define CComboWnd__GetCurChoice_x                                  0x8D4F30
#define CComboWnd__GetListRect_x                                   0x8D5610
#define CComboWnd__GetTextRect_x                                   0x8D51D0
#define CComboWnd__InsertChoice_x                                  0x8D5680
#define CComboWnd__SetColors_x                                     0x8D4EC0
#define CComboWnd__SetChoice_x                                     0x8D4EF0
#define CComboWnd__GetItemCount_x                                  0x8D4F20

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A12F0
#define CContainerWnd__vftable_x                                   0xAE3FD8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B35A0
#define CDisplay__GetClickedActor_x                                0x4AC120
#define CDisplay__GetUserDefinedColor_x                            0x4AA9E0
#define CDisplay__GetWorldFilePath_x                               0x4A9E30
#define CDisplay__is3dON_x                                         0x4A9200
#define CDisplay__ReloadUI_x                                       0x4BEB70
#define CDisplay__WriteTextHD2_x                                   0x4AF940

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FCEB0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E9D20
#define CEditWnd__GetCharIndexPt_x                                 0x8EADA0
#define CEditWnd__GetDisplayString_x                               0x8E9ED0
#define CEditWnd__GetHorzOffset_x                                  0x8EA210
#define CEditWnd__GetLineForPrintableChar_x                        0x8EA870
#define CEditWnd__GetSelStartPt_x                                  0x8EB050
#define CEditWnd__GetSTMLSafeText_x                                0x8EA3A0
#define CEditWnd__PointFromPrintableChar_x                         0x8EA960
#define CEditWnd__SelectableCharFromPoint_x                        0x8EAAE0
#define CEditWnd__SetEditable_x                                    0x8EA370

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x555360
#define CEverQuest__CreateTargetIndicator_x                        0x555F90
#define CEverQuest__DeleteTargetIndicator_x                        0x556010
#define CEverQuest__DoTellWindow_x                                 0x55AD50
#define CEverQuest__DropHeldItemOnGround_x                         0x563C50
#define CEverQuest__dsp_chat_x                                     0x55C700
#define CEverQuest__Emote_x                                        0x55C960
#define CEverQuest__EnterZone_x                                    0x570C60
#define CEverQuest__GetBodyTypeDesc_x                              0x551BC0
#define CEverQuest__GetClassDesc_x                                 0x5578D0
#define CEverQuest__GetClassThreeLetterCode_x                      0x557ED0
#define CEverQuest__GetDeityDesc_x                                 0x5524A0
#define CEverQuest__GetLangDesc_x                                  0x551F50
#define CEverQuest__GetRaceDesc_x                                  0x558090
#define CEverQuest__InterpretCmd_x                                 0x55D240
#define CEverQuest__LeftClickedOnPlayer_x                          0x575570
#define CEverQuest__LMouseUp_x                                     0x577660
#define CEverQuest__RightClickedOnPlayer_x                         0x576070
#define CEverQuest__RMouseUp_x                                     0x5770C0
#define CEverQuest__SetGameState_x                                 0x555A10
#define CEverQuest__UPCNotificationFlush_x                         0x55E5A0
#define CEverQuest__IssuePetCommand_x                              0x55DF00

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B2100
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B2160
#define CGaugeWnd__Draw_x                                          0x6B2590

// CGuild
#define CGuild__FindMemberByName_x                                 0x435D90

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CF210

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DB9C0
#define CInvSlotMgr__MoveItem_x                                    0x6DC900
#define CInvSlotMgr__SelectSlot_x                                  0x6DBA70

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DAE50
#define CInvSlot__SliderComplete_x                                 0x6D8680
#define CInvSlot__GetItemBase_x                                    0x6D7AD0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DDD00

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A6E70
#define CItemDisplayWnd__UpdateStrings_x                           0x6DF040

// CLabel 
#define CLabel__Draw_x                                             0x6FA030

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C0E30
#define CListWnd__dCListWnd_x                                      0x8C1E50
#define CListWnd__AddColumn_x                                      0x8C1DF0
#define CListWnd__AddColumn1_x                                     0x8C1660
#define CListWnd__AddLine_x                                        0x8C10E0
#define CListWnd__AddString_x                                      0x8C12F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BE170
#define CListWnd__CalculateVSBRange_x                              0x8C02E0
#define CListWnd__ClearAllSel_x                                    0x8BD430
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C0CC0
#define CListWnd__Compare_x                                        0x8BEC70
#define CListWnd__Draw_x                                           0x8BFEF0
#define CListWnd__DrawColumnSeparators_x                           0x8BFD80
#define CListWnd__DrawHeader_x                                     0x8BD740
#define CListWnd__DrawItem_x                                       0x8BF2C0
#define CListWnd__DrawLine_x                                       0x8BFA20
#define CListWnd__DrawSeparator_x                                  0x8BFE20
#define CListWnd__EnsureVisible_x                                  0x8BE2D0
#define CListWnd__ExtendSel_x                                      0x8BF1D0
#define CListWnd__GetColumnMinWidth_x                              0x8BCDF0
#define CListWnd__GetColumnWidth_x                                 0x8BCD10
#define CListWnd__GetCurSel_x                                      0x8BC4F0
#define CListWnd__GetItemAtPoint_x                                 0x8BE560
#define CListWnd__GetItemAtPoint1_x                                0x8BE5D0
#define CListWnd__GetItemData_x                                    0x8BC830
#define CListWnd__GetItemHeight_x                                  0x8BDDD0
#define CListWnd__GetItemIcon_x                                    0x8BCA10
#define CListWnd__GetItemRect_x                                    0x8BE3A0
#define CListWnd__GetItemText_x                                    0x8BC8C0
#define CListWnd__GetSelList_x                                     0x8C1550
#define CListWnd__GetSeparatorRect_x                               0x8BEB90
#define CListWnd__RemoveLine_x                                     0x8C14D0
#define CListWnd__SetColors_x                                      0x8BC640
#define CListWnd__SetColumnJustification_x                         0x8BD0C0
#define CListWnd__SetColumnWidth_x                                 0x8BCDA0
#define CListWnd__SetCurSel_x                                      0x8BC530
#define CListWnd__SetItemColor_x                                   0x8C09A0
#define CListWnd__SetItemData_x                                    0x8BD4E0
#define CListWnd__SetItemText_x                                    0x8C07E0
#define CListWnd__ShiftColumnSeparator_x                           0x8C0670
#define CListWnd__Sort_x                                           0x8C1F50
#define CListWnd__ToggleSel_x                                      0x8BD3B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x713510

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x734930
#define CMerchantWnd__RequestBuyItem_x                             0x73B790
#define CMerchantWnd__RequestSellItem_x                            0x73C200
#define CMerchantWnd__SelectRecoverySlot_x                         0x734BE0
#define CMerchantWnd__SelectBuySellSlot_x                          0x733E40
#define CMerchantWnd__ActualSelect_x                               0x7386B0

// CObfuscator
#define CObfuscator__doit_x                                        0x867940

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E0270
#define CSidlManager__CreateLabel_x                                0x79CE90

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65FDB0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65FCD0
#define CSidlScreenWnd__ConvertToRes_x                             0x8FCD90
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D7E10
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D9310
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D93C0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D8890
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D77C0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D6EF0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D79B0
#define CSidlScreenWnd__Init1_x                                    0x8D8FF0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D7EC0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D70B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D8AE0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D69B0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D6E80
#define CSidlScreenWnd__WndNotification_x                          0x8D8D70
#define CSidlScreenWnd__GetChildItem_x                             0x8D6FC0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CA4C0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FB120
#define CSkillMgr__GetSkillCap_x                                   0x5FB2E0
#define CSkillMgr__GetNameToken_x                                  0x5FAD40

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FC060
#define CSliderWnd__SetValue_x                                     0x8FC230
#define CSliderWnd__SetNumTicks_x                                  0x8FC9B0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A4B20

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F69F0
#define CStmlWnd__CalculateHSBRange_x                              0x8EEF20
#define CStmlWnd__CalculateVSBRange_x                              0x8EEFB0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EF130
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EFA10
#define CStmlWnd__ForceParseNow_x                                  0x8F7340
#define CStmlWnd__GetNextTagPiece_x                                0x8EF910
#define CStmlWnd__GetSTMLText_x                                    0x696FC0
#define CStmlWnd__GetVisibleText_x                                 0x8F0460
#define CStmlWnd__InitializeWindowVariables_x                      0x8F27F0
#define CStmlWnd__MakeStmlColorTag_x                               0x8EE220
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EE280
#define CStmlWnd__SetSTMLText_x                                    0x8F4060
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6690
#define CStmlWnd__UpdateHistoryString_x                            0x8F13A0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8ED8C0
#define CTabWnd__DrawCurrentPage_x                                 0x8ED130
#define CTabWnd__DrawTab_x                                         0x8ECF00
#define CTabWnd__GetCurrentPage_x                                  0x8ED500
#define CTabWnd__GetPageInnerRect_x                                0x8ECBF0
#define CTabWnd__GetTabInnerRect_x                                 0x8ECDF0
#define CTabWnd__GetTabRect_x                                      0x8ECCC0
#define CTabWnd__InsertPage_x                                      0x8EDBB0
#define CTabWnd__SetPage_x                                         0x8ED530
#define CTabWnd__SetPageRect_x                                     0x8ED800
#define CTabWnd__UpdatePage_x                                      0x8EDB50

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431BA0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D4B30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x902200

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BA540

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402290
#define CXStr__CXStr1_x                                            0x8AF2F0
#define CXStr__CXStr3_x                                            0x89EEC0
#define CXStr__dCXStr_x                                            0x8F7E00
#define CXStr__operator_equal_x                                    0x89F030
#define CXStr__operator_equal1_x                                   0x89F080
#define CXStr__operator_plus_equal1_x                              0x8A0160

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C96E0
#define CXWnd__Center_x                                            0x8CF8A0
#define CXWnd__ClrFocus_x                                          0x8C92B0
#define CXWnd__DoAllDrawing_x                                      0x8CF4F0
#define CXWnd__DrawChildren_x                                      0x8CF690
#define CXWnd__DrawColoredRect_x                                   0x8C9A80
#define CXWnd__DrawTooltip_x                                       0x8C9D30
#define CXWnd__DrawTooltipAtPoint_x                                0x8CE460
#define CXWnd__GetBorderFrame_x                                    0x8CA190
#define CXWnd__GetChildWndAt_x                                     0x8D0240
#define CXWnd__GetClientClipRect_x                                 0x8C9F50
#define CXWnd__GetScreenClipRect_x                                 0x8CEB50
#define CXWnd__GetScreenRect_x                                     0x8CA350
#define CXWnd__GetTooltipRect_x                                    0x8C9BC0
#define CXWnd__GetWindowTextA_x                                    0x423060
#define CXWnd__IsActive_x                                          0x8C4C30
#define CXWnd__IsDescendantOf_x                                    0x8CA0E0
#define CXWnd__IsReallyVisible_x                                   0x8CD490
#define CXWnd__IsType_x                                            0x8FE9E0
#define CXWnd__Move_x                                              0x8CCB60
#define CXWnd__Move1_x                                             0x8CF1A0
#define CXWnd__ProcessTransition_x                                 0x8C9680
#define CXWnd__Refade_x                                            0x8C9450
#define CXWnd__Resize_x                                            0x8CA420
#define CXWnd__Right_x                                             0x8CE950
#define CXWnd__SetFocus_x                                          0x8CBCD0
#define CXWnd__SetFont_x                                           0x8C9300
#define CXWnd__SetKeyTooltip_x                                     0x8CA690
#define CXWnd__SetMouseOver_x                                      0x8CEE90
#define CXWnd__StartFade_x                                         0x8C9730
#define CXWnd__GetChildItem_x                                      0x8CEDD0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C6550
#define CXWndManager__DrawWindows_x                                0x8C6190
#define CXWndManager__GetKeyboardFlags_x                           0x8C4760
#define CXWndManager__HandleKeyboardMsg_x                          0x8C50C0
#define CXWndManager__RemoveWnd_x                                  0x8C4DC0

// CDBStr
#define CDBStr__GetString_x                                        0x4A77A0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E0A0
#define EQ_Character__Cur_HP_x                                     0x463950
#define EQ_Character__GetAACastingTimeModifier_x                   0x445FA0
#define EQ_Character__GetCharInfo2_x                               0x872200
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43DF70
#define EQ_Character__GetFocusRangeModifier_x                      0x43E160
#define EQ_Character__Max_Endurance_x                              0x5C2A70
#define EQ_Character__Max_HP_x                                     0x459580
#define EQ_Character__Max_Mana_x                                   0x5C28A0
#define EQ_Character__doCombatAbility_x                            0x5BFEF0
#define EQ_Character__UseSkill_x                                   0x46EE50
#define EQ_Character__GetConLevel_x                                0x5B49D0
#define EQ_Character__IsExpansionFlag_x                            0x4225B0
#define EQ_Character__TotalEffect_x                                0x44B340

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x5950B0
#define EQ_Item__CreateItemTagString_x                             0x851500
#define EQ_Item__IsStackable_x                                     0x845A60
#define EQ_Item__GetImageNum_x                                     0x848760
#define EQ_Item__CreateItemClient_x                                0x595CA0
#define EQ_Item__GetItemValue_x                                    0x8501D0
#define EQ_Item__ValueSellMerchant_x                               0x852810

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C7550
#define EQ_LoadingS__Array_x                                       0xC1F0A0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C40C0
#define EQ_PC__GetAlternateAbilityId_x                             0x85A920
#define EQ_PC__GetCombatAbility_x                                  0x85A9B0
#define EQ_PC__GetCombatAbilityTimer_x                             0x855770
#define EQ_PC__GetItemTimerValue_x                                 0x5BDA00
#define EQ_PC__HasLoreItem_x                                       0x5B7EB0
#define EQ_PC__AlertInventoryChanged_x                             0x5B49A0
#define EQ_PC__GetPcZoneClient_x                                   0x5DE6F0
#define EQ_PC__RemoveMyAffect_x                                    0x5BCEC0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x510600
#define EQItemList__add_item_x                                     0x510540
#define EQItemList__delete_item_x                                  0x510A00
#define EQItemList__FreeItemList_x                                 0x510900

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A6970

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C9650
#define EQPlayer__dEQPlayer_x                                      0x5D24D0
#define EQPlayer__DoAttack_x                                       0x5E4600
#define EQPlayer__EQPlayer_x                                       0x5D48F0
#define EQPlayer__SetNameSpriteState_x                             0x5CF1A0
#define EQPlayer__SetNameSpriteTint_x                              0x5CAA60
#define EQPlayer__IsBodyType_j_x                                   0x92F880
#define EQPlayer__IsTargetable_x                                   0x930180
#define EQPlayer__CanSee_x                                         0x9306A0
#define PlayerZoneClient__ChangeHeight_x                           0x5E44C0
#define EQPlayer__CanSeeTargetIndicator_x                          0x930790

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D8C50
#define EQPlayerManager__GetSpawnByName_x                          0x5D90B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59B1A0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59B1E0
#define KeypressHandler__ClearCommandStateArray_x                  0x59AD80
#define KeypressHandler__HandleKeyDown_x                           0x5996E0
#define KeypressHandler__HandleKeyUp_x                             0x599A00
#define KeypressHandler__SaveKeymapping_x                          0x59AE50

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70B8F0
#define MapViewMap__SaveEx_x                                       0x70F1D0

#define PlayerPointManager__GetAltCurrency_x                       0x86D1B0

// StringTable 
#define StringTable__getString_x                                   0x867BE0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C2520
#define PcZoneClient__RemovePetEffect_x                            0x5BDEF0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54EF00

//IconCache
#define IconCache__GetIcon_x                                       0x6A7810

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69E600
#define CContainerMgr__CloseContainer_x                            0x69EE20

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76D270

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58E1F0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DF5D0
#define EQ_Spell__SpellAffects_x                                   0x4DF670
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DF6A0
#define CharacterZoneClient__CalcAffectChange_x                    0x447390
#define CLootWnd__LootAll_x                                        0x7011F0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B2A70
#define CTargetWnd__WndNotification_x                              0x7B2560

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B7C50

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D8E90

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x496E80

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E9350
#define CSidlManager__FindAnimation1_x                             0x8DE160

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CEBF0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CEBA0
#define CAltAbilityData__GetMaxRank_x                              0x4C3B20

//CTargetRing
#define CTargetRing__Cast_x                                        0x58BAB0
