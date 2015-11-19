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
#define __ExpectedVersionDate                                     "Nov 16 2015"
#define __ExpectedVersionTime                                     "17:50:20"
#define __ActualVersionDate_x                                      0xADA670
#define __ActualVersionTime_x                                      0xADA67C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5A0260
#define __MemChecker1_x                                            0x8A20A0
#define __MemChecker2_x                                            0x639640
#define __MemChecker3_x                                            0x639590
#define __MemChecker4_x                                            0x7EE310
#define __EncryptPad0_x                                            0xC75D08
#define __EncryptPad1_x                                            0xE00DE8
#define __EncryptPad2_x                                            0xCBF7F0
#define __EncryptPad3_x                                            0xCBF3F0
#define __EncryptPad4_x                                            0xDD9F78
#define __EncryptPad5_x                                            0x11ACC60
#define __AC1_x                                                    0x7AB4A5
#define __AC2_x                                                    0x554407
#define __AC3_x                                                    0x568FD0
#define __AC4_x                                                    0x56FC50
#define __AC5_x                                                    0x57C39E
#define __AC6_x                                                    0x57FEF9
#define __AC7_x                                                    0x576A4C
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
#define __do_loot_x                                                0x51B850
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
#define pinstCamActor_x                                            0xF5ADF4
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
#define pinstViewActor_x                                           0xF5ADF0
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
#define pinstCCharacterSelect_x                                    0xF5AC84
#define pinstCFacePick_x                                           0xF5AA34
#define pinstCNoteWnd_x                                            0xF5AC3C
#define pinstCBookWnd_x                                            0xF5AC44
#define pinstCPetInfoWnd_x                                         0xF5AC48
#define pinstCTrainWnd_x                                           0xF5AC4C
#define pinstCSkillsWnd_x                                          0xF5AC50
#define pinstCSkillsSelectWnd_x                                    0xF5AC54
#define pinstCCombatSkillsSelectWnd_x                              0xF5AC58
#define pinstCFriendsWnd_x                                         0xF5AC5C
#define pinstCAuraWnd_x                                            0xF5AC60
#define pinstCRespawnWnd_x                                         0xF5AC64
#define pinstCBandolierWnd_x                                       0xF5AC68
#define pinstCPotionBeltWnd_x                                      0xF5AC6C
#define pinstCAAWnd_x                                              0xF5AC70
#define pinstCGroupSearchFiltersWnd_x                              0xF5AC74
#define pinstCLoadskinWnd_x                                        0xF5AC78
#define pinstCAlarmWnd_x                                           0xF5AC7C
#define pinstCMusicPlayerWnd_x                                     0xF5AC80
#define pinstCMailWnd_x                                            0xF5AC88
#define pinstCMailCompositionWnd_x                                 0xF5AC8C
#define pinstCMailAddressBookWnd_x                                 0xF5AC90
#define pinstCRaidWnd_x                                            0xF5AC98
#define pinstCRaidOptionsWnd_x                                     0xF5AC9C
#define pinstCBreathWnd_x                                          0xF5ACA0
#define pinstCMapViewWnd_x                                         0xF5ACA4
#define pinstCMapToolbarWnd_x                                      0xF5ACA8
#define pinstCEditLabelWnd_x                                       0xF5ACAC
#define pinstCTargetWnd_x                                          0xF5ACB0
#define pinstCColorPickerWnd_x                                     0xF5ACB4
#define pinstCPlayerWnd_x                                          0xF5ACB8
#define pinstCOptionsWnd_x                                         0xF5ACBC
#define pinstCBuffWindowNORMAL_x                                   0xF5ACC0
#define pinstCBuffWindowSHORT_x                                    0xF5ACC4
#define pinstCharacterCreation_x                                   0xF5ACC8
#define pinstCCursorAttachment_x                                   0xF5ACCC
#define pinstCCastingWnd_x                                         0xF5ACD0
#define pinstCCastSpellWnd_x                                       0xF5ACD4
#define pinstCSpellBookWnd_x                                       0xF5ACD8
#define pinstCInventoryWnd_x                                       0xF5ACDC
#define pinstCBankWnd_x                                            0xF5ACE4
#define pinstCQuantityWnd_x                                        0xF5ACE8
#define pinstCLootWnd_x                                            0xF5ACEC
#define pinstCActionsWnd_x                                         0xF5ACF0
#define pinstCCombatAbilityWnd_x                                   0xF5ACF4
#define pinstCMerchantWnd_x                                        0xF5ACF8
#define pinstCTradeWnd_x                                           0xF5ACFC
#define pinstCSelectorWnd_x                                        0xF5AD00
#define pinstCBazaarWnd_x                                          0xF5AD04
#define pinstCBazaarSearchWnd_x                                    0xF5AD08
#define pinstCGiveWnd_x                                            0xF5AD24
#define pinstCTrackingWnd_x                                        0xF5AD2C
#define pinstCInspectWnd_x                                         0xF5AD30
#define pinstCSocialEditWnd_x                                      0xF5AD34
#define pinstCFeedbackWnd_x                                        0xF5AD38
#define pinstCBugReportWnd_x                                       0xF5AD3C
#define pinstCVideoModesWnd_x                                      0xF5AD40
#define pinstCTextEntryWnd_x                                       0xF5AD48
#define pinstCFileSelectionWnd_x                                   0xF5AD4C
#define pinstCCompassWnd_x                                         0xF5AD50
#define pinstCPlayerNotesWnd_x                                     0xF5AD54
#define pinstCGemsGameWnd_x                                        0xF5AD58
#define pinstCTimeLeftWnd_x                                        0xF5AD5C
#define pinstCPetitionQWnd_x                                       0xF5AD78
#define pinstCSoulmarkWnd_x                                        0xF5AD7C
#define pinstCStoryWnd_x                                           0xF5AD80
#define pinstCJournalTextWnd_x                                     0xF5AD84
#define pinstCJournalCatWnd_x                                      0xF5AD88
#define pinstCBodyTintWnd_x                                        0xF5AD8C
#define pinstCServerListWnd_x                                      0xF5AD90
#define pinstCAvaZoneWnd_x                                         0xF5AD9C
#define pinstCBlockedBuffWnd_x                                     0xF5ADA0
#define pinstCBlockedPetBuffWnd_x                                  0xF5ADA4
#define pinstCInvSlotMgr_x                                         0xF5ADE8
#define pinstCContainerMgr_x                                       0xF5ADEC
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
#define pinstCAdvancedLootWnd_x                                    0xF5ADDC
#define pinstRewardSelectionWnd_x                                  0x11B3730

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5333A0
#define __ConvertItemTags_x                                        0x5204D0
#define __ExecuteCmd_x                                             0x50B000
#define __EQGetTime_x                                              0x8A2400
#define __get_melee_range_x                                        0x511C90
#define __GetGaugeValueFromEQ_x                                    0x7AA1E0
#define __GetLabelFromEQ_x                                         0x7AB430
#define __ToggleKeyRingItem_x                                      0x47E1D0
#define __GetXTargetType_x                                         0x933540
#define __LoadFrontEnd_x                                           0x638CF0
#define __NewUIINI_x                                               0x7A9AE0
#define __ProcessGameEvents_x                                      0x5787B0
#define __ProcessMouseEvent_x                                      0x577F50
#define CrashDetected_x                                            0x63A7C0
#define wwsCrashReportCheckForUploader_x                           0x7FDCF0
#define DrawNetStatus_x                                            0x5AFDD0
#define Util__FastTime_x                                           0x8A1D50
#define Expansion_HoT_x                                            0x101C5CC
#define __HelpPath_x                                               0x109FD38
#define __STMLToText_x                                             0x8E6EE0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41EF00
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419D60

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C5120
#define AltAdvManager__IsAbilityReady_x                            0x4C5190
#define AltAdvManager__GetAAById_x                                 0x4C5550

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4642F0
#define CharacterZoneClient__MakeMeVisible_x                       0x469CD0
#define CharacterZoneClient__IsStackBlocked_x                      0x4464E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x668710

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x676C10

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58EFF0
#define CButtonWnd__CButtonWnd_x                                   0x8DB160

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x691AF0
#define CChatManager__InitContextMenu_x                            0x692670

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E5240
#define CContextMenu__dCContextMenu_x                              0x8E5450
#define CContextMenu__AddMenuItem_x                                0x8E5460
#define CContextMenu__RemoveMenuItem_x                             0x8E5750
#define CContextMenu__RemoveAllMenuItems_x                         0x8E5770
#define CContextMenuManager__AddMenu_x                             0x8D10E0
#define CContextMenuManager__RemoveMenu_x                          0x8D1430
#define CContextMenuManager__PopupMenu_x                           0x8D1880
#define CContextMenuManager__Flush_x                               0x8D1150
#define CContextMenuManager__GetMenu_x                             0x4153D0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x887510
#define CChatService__GetFriendName_x                              0x887520

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x697920
#define CChatWindow__Clear_x                                       0x6974D0
#define CChatWindow__WndNotification_x                             0x697E60

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D4FF0
#define CComboWnd__Draw_x                                          0x8D5200
#define CComboWnd__GetCurChoice_x                                  0x8D4DC0
#define CComboWnd__GetListRect_x                                   0x8D54A0
#define CComboWnd__GetTextRect_x                                   0x8D5060
#define CComboWnd__InsertChoice_x                                  0x8D5510
#define CComboWnd__SetColors_x                                     0x8D4D50
#define CComboWnd__SetChoice_x                                     0x8D4D80
#define CComboWnd__GetItemCount_x                                  0x8D4DB0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A1110
#define CContainerWnd__vftable_x                                   0xAE4038

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B3320
#define CDisplay__GetClickedActor_x                                0x4ABEA0
#define CDisplay__GetUserDefinedColor_x                            0x4AA760
#define CDisplay__GetWorldFilePath_x                               0x4A9BB0
#define CDisplay__is3dON_x                                         0x4A8F80
#define CDisplay__ReloadUI_x                                       0x4BE8F0
#define CDisplay__WriteTextHD2_x                                   0x4AF6C0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FCDE0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E9C40
#define CEditWnd__GetCharIndexPt_x                                 0x8EACD0
#define CEditWnd__GetDisplayString_x                               0x8E9DF0
#define CEditWnd__GetHorzOffset_x                                  0x8EA130
#define CEditWnd__GetLineForPrintableChar_x                        0x8EA7A0
#define CEditWnd__GetSelStartPt_x                                  0x8EAF80
#define CEditWnd__GetSTMLSafeText_x                                0x8EA2D0
#define CEditWnd__PointFromPrintableChar_x                         0x8EA890
#define CEditWnd__SelectableCharFromPoint_x                        0x8EAA10
#define CEditWnd__SetEditable_x                                    0x8EA2A0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x554B50
#define CEverQuest__CreateTargetIndicator_x                        0x555780
#define CEverQuest__DeleteTargetIndicator_x                        0x555800
#define CEverQuest__DoTellWindow_x                                 0x55A550
#define CEverQuest__DropHeldItemOnGround_x                         0x563450
#define CEverQuest__dsp_chat_x                                     0x55BF00
#define CEverQuest__Emote_x                                        0x55C160
#define CEverQuest__EnterZone_x                                    0x5705A0
#define CEverQuest__GetBodyTypeDesc_x                              0x5513B0
#define CEverQuest__GetClassDesc_x                                 0x5570C0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5576C0
#define CEverQuest__GetDeityDesc_x                                 0x551C90
#define CEverQuest__GetLangDesc_x                                  0x551740
#define CEverQuest__GetRaceDesc_x                                  0x557880
#define CEverQuest__InterpretCmd_x                                 0x55CA40
#define CEverQuest__LeftClickedOnPlayer_x                          0x574EB0
#define CEverQuest__LMouseUp_x                                     0x576FA0
#define CEverQuest__RightClickedOnPlayer_x                         0x5759B0
#define CEverQuest__RMouseUp_x                                     0x576A00
#define CEverQuest__SetGameState_x                                 0x555200
#define CEverQuest__UPCNotificationFlush_x                         0x55DDA0
#define CEverQuest__IssuePetCommand_x                              0x55D700

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B1DE0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B1E40
#define CGaugeWnd__Draw_x                                          0x6B2270

// CGuild
#define CGuild__FindMemberByName_x                                 0x435DB0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CEEC0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DB610
#define CInvSlotMgr__MoveItem_x                                    0x6DC550
#define CInvSlotMgr__SelectSlot_x                                  0x6DB6C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DAA90
#define CInvSlot__SliderComplete_x                                 0x6D82C0
#define CInvSlot__GetItemBase_x                                    0x6D7740

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DD940

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A6B60
#define CItemDisplayWnd__UpdateStrings_x                           0x6DEC70

// CLabel 
#define CLabel__Draw_x                                             0x6F9BC0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C0C60
#define CListWnd__dCListWnd_x                                      0x8C1C80
#define CListWnd__AddColumn_x                                      0x8C1C20
#define CListWnd__AddColumn1_x                                     0x8C14A0
#define CListWnd__AddLine_x                                        0x8C0F20
#define CListWnd__AddString_x                                      0x8C1130
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BDFB0
#define CListWnd__CalculateVSBRange_x                              0x8C0120
#define CListWnd__ClearAllSel_x                                    0x8BD270
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C0AF0
#define CListWnd__Compare_x                                        0x8BEAA0
#define CListWnd__Draw_x                                           0x8BFD30
#define CListWnd__DrawColumnSeparators_x                           0x8BFBC0
#define CListWnd__DrawHeader_x                                     0x8BD580
#define CListWnd__DrawItem_x                                       0x8BF0F0
#define CListWnd__DrawLine_x                                       0x8BF860
#define CListWnd__DrawSeparator_x                                  0x8BFC60
#define CListWnd__EnsureVisible_x                                  0x8BE110
#define CListWnd__ExtendSel_x                                      0x8BF000
#define CListWnd__GetColumnMinWidth_x                              0x8BCC30
#define CListWnd__GetColumnWidth_x                                 0x8BCB50
#define CListWnd__GetCurSel_x                                      0x8BC320
#define CListWnd__GetItemAtPoint_x                                 0x8BE3A0
#define CListWnd__GetItemAtPoint1_x                                0x8BE410
#define CListWnd__GetItemData_x                                    0x8BC660
#define CListWnd__GetItemHeight_x                                  0x8BDC10
#define CListWnd__GetItemIcon_x                                    0x8BC840
#define CListWnd__GetItemRect_x                                    0x8BE1E0
#define CListWnd__GetItemText_x                                    0x8BC6F0
#define CListWnd__GetSelList_x                                     0x8C1390
#define CListWnd__GetSeparatorRect_x                               0x8BE9C0
#define CListWnd__RemoveLine_x                                     0x8C1310
#define CListWnd__SetColors_x                                      0x8BC470
#define CListWnd__SetColumnJustification_x                         0x8BCF00
#define CListWnd__SetColumnWidth_x                                 0x8BCBE0
#define CListWnd__SetCurSel_x                                      0x8BC360
#define CListWnd__SetItemColor_x                                   0x8C07D0
#define CListWnd__SetItemData_x                                    0x8BD320
#define CListWnd__SetItemText_x                                    0x8C0610
#define CListWnd__ShiftColumnSeparator_x                           0x8C04A0
#define CListWnd__Sort_x                                           0x8C1D80
#define CListWnd__ToggleSel_x                                      0x8BD1F0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x713040

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7343E0
#define CMerchantWnd__RequestBuyItem_x                             0x73B220
#define CMerchantWnd__RequestSellItem_x                            0x73BC90
#define CMerchantWnd__SelectRecoverySlot_x                         0x734690
#define CMerchantWnd__SelectBuySellSlot_x                          0x7338F0
#define CMerchantWnd__ActualSelect_x                               0x738150

// CObfuscator
#define CObfuscator__doit_x                                        0x8677A0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E01A0
#define CSidlManager__CreateLabel_x                                0x79CB70

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65FA00
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65F930
#define CSidlScreenWnd__ConvertToRes_x                             0x8FCCC0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D7C80
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D9170
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D9220
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D86F0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D7630
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D6D80
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D7820
#define CSidlScreenWnd__Init1_x                                    0x8D8E50
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D7D30
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D6F40
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D8940
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D6850
#define CSidlScreenWnd__StoreIniVis_x                              0x8D6D10
#define CSidlScreenWnd__WndNotification_x                          0x8D8BD0
#define CSidlScreenWnd__GetChildItem_x                             0x8D6E50
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CA3E0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FAB20
#define CSkillMgr__GetSkillCap_x                                   0x5FACE0
#define CSkillMgr__GetNameToken_x                                  0x5FA740

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FBF70
#define CSliderWnd__SetValue_x                                     0x8FC140
#define CSliderWnd__SetNumTicks_x                                  0x8FC8C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A4810

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6960
#define CStmlWnd__CalculateHSBRange_x                              0x8EEE80
#define CStmlWnd__CalculateVSBRange_x                              0x8EEF10
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EF090
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EF970
#define CStmlWnd__ForceParseNow_x                                  0x8F72B0
#define CStmlWnd__GetNextTagPiece_x                                0x8EF870
#define CStmlWnd__GetSTMLText_x                                    0x696D70
#define CStmlWnd__GetVisibleText_x                                 0x8F03C0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2740
#define CStmlWnd__MakeStmlColorTag_x                               0x8EE180
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EE1E0
#define CStmlWnd__SetSTMLText_x                                    0x8F3FA0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6600
#define CStmlWnd__UpdateHistoryString_x                            0x8F1300

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8ED810
#define CTabWnd__DrawCurrentPage_x                                 0x8ED080
#define CTabWnd__DrawTab_x                                         0x8ECE40
#define CTabWnd__GetCurrentPage_x                                  0x8ED450
#define CTabWnd__GetPageInnerRect_x                                0x8ECB30
#define CTabWnd__GetTabInnerRect_x                                 0x8ECD30
#define CTabWnd__GetTabRect_x                                      0x8ECC00
#define CTabWnd__InsertPage_x                                      0x8EDB00
#define CTabWnd__SetPage_x                                         0x8ED480
#define CTabWnd__SetPageRect_x                                     0x8ED750
#define CTabWnd__UpdatePage_x                                      0x8EDAA0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431BB0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D49C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x902160

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BA430

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59C760
#define CXStr__CXStr1_x                                            0x7DB060
#define CXStr__CXStr3_x                                            0x89EDE0
#define CXStr__dCXStr_x                                            0x4A0B60
#define CXStr__operator_equal_x                                    0x89EF50
#define CXStr__operator_equal1_x                                   0x89EFA0
#define CXStr__operator_plus_equal1_x                              0x8A0080

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C9630
#define CXWnd__Center_x                                            0x8CF730
#define CXWnd__ClrFocus_x                                          0x8C9210
#define CXWnd__DoAllDrawing_x                                      0x8CF380
#define CXWnd__DrawChildren_x                                      0x8CF520
#define CXWnd__DrawColoredRect_x                                   0x8C99F0
#define CXWnd__DrawTooltip_x                                       0x8C9C90
#define CXWnd__DrawTooltipAtPoint_x                                0x8CE310
#define CXWnd__GetBorderFrame_x                                    0x8CA0D0
#define CXWnd__GetChildWndAt_x                                     0x8D00E0
#define CXWnd__GetClientClipRect_x                                 0x8C9E90
#define CXWnd__GetScreenClipRect_x                                 0x8CEA10
#define CXWnd__GetScreenRect_x                                     0x8CA280
#define CXWnd__GetTooltipRect_x                                    0x8C9B20
#define CXWnd__GetWindowTextA_x                                    0x422EB0
#define CXWnd__IsActive_x                                          0x8C4B10
#define CXWnd__IsDescendantOf_x                                    0x8CA020
#define CXWnd__IsReallyVisible_x                                   0x8CD370
#define CXWnd__IsType_x                                            0x8FE940
#define CXWnd__Move_x                                              0x8CCA50
#define CXWnd__Move1_x                                             0x8CF020
#define CXWnd__ProcessTransition_x                                 0x8C95D0
#define CXWnd__Refade_x                                            0x8C93B0
#define CXWnd__Resize_x                                            0x8CA340
#define CXWnd__Right_x                                             0x8CE810
#define CXWnd__SetFocus_x                                          0x8CBBB0
#define CXWnd__SetFont_x                                           0x8C9260
#define CXWnd__SetKeyTooltip_x                                     0x8CA5B0
#define CXWnd__SetMouseOver_x                                      0x8CED00
#define CXWnd__StartFade_x                                         0x8C9680
#define CXWnd__GetChildItem_x                                      0x8CEC50

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C6450
#define CXWndManager__DrawWindows_x                                0x8C6090
#define CXWndManager__GetKeyboardFlags_x                           0x8C4640
#define CXWndManager__HandleKeyboardMsg_x                          0x8C4FB0
#define CXWndManager__RemoveWnd_x                                  0x8C4CA0

// CDBStr
#define CDBStr__GetString_x                                        0x4A7510

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E170
#define EQ_Character__Cur_HP_x                                     0x4639C0
#define EQ_Character__GetAACastingTimeModifier_x                   0x446060
#define EQ_Character__GetCharInfo2_x                               0x871FA0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43E010
#define EQ_Character__GetFocusRangeModifier_x                      0x43E200
#define EQ_Character__Max_Endurance_x                              0x5C24F0
#define EQ_Character__Max_HP_x                                     0x459600
#define EQ_Character__Max_Mana_x                                   0x5C2320
#define EQ_Character__doCombatAbility_x                            0x5BF960
#define EQ_Character__UseSkill_x                                   0x46EED0
#define EQ_Character__GetConLevel_x                                0x5B4430
#define EQ_Character__IsExpansionFlag_x                            0x4223F0
#define EQ_Character__TotalEffect_x                                0x44B410

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x594920
#define EQ_Item__CreateItemTagString_x                             0x8513C0
#define EQ_Item__IsStackable_x                                     0x8457D0
#define EQ_Item__GetImageNum_x                                     0x8484B0
#define EQ_Item__CreateItemClient_x                                0x5954F0
#define EQ_Item__GetItemValue_x                                    0x850070
#define EQ_Item__ValueSellMerchant_x                               0x852740

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C7250
#define EQ_LoadingS__Array_x                                       0xC1F0A0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C3B50
#define EQ_PC__GetAlternateAbilityId_x                             0x85A790
#define EQ_PC__GetCombatAbility_x                                  0x85A820
#define EQ_PC__GetCombatAbilityTimer_x                             0x8556B0
#define EQ_PC__GetItemTimerValue_x                                 0x5BD470
#define EQ_PC__HasLoreItem_x                                       0x5B7910
#define EQ_PC__AlertInventoryChanged_x                             0x5B4400
#define EQ_PC__GetPcZoneClient_x                                   0x5DE170
#define EQ_PC__RemoveMyAffect_x                                    0x5BC930

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50FCE0
#define EQItemList__add_item_x                                     0x50FC20
#define EQItemList__delete_item_x                                  0x5100E0
#define EQItemList__FreeItemList_x                                 0x50FFE0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A67F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C9100
#define EQPlayer__dEQPlayer_x                                      0x5D1F80
#define EQPlayer__DoAttack_x                                       0x5E4090
#define EQPlayer__EQPlayer_x                                       0x5D43A0
#define EQPlayer__SetNameSpriteState_x                             0x5CEC50
#define EQPlayer__SetNameSpriteTint_x                              0x5CA510
#define EQPlayer__IsBodyType_j_x                                   0x92F750
#define EQPlayer__IsTargetable_x                                   0x930050
#define EQPlayer__CanSee_x                                         0x930570
#define PlayerZoneClient__ChangeHeight_x                           0x5E3F50
#define EQPlayer__CanSeeTargetIndicator_x                          0x930660

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D8700
#define EQPlayerManager__GetSpawnByName_x                          0x5D8B60

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59AA90
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59AAD0
#define KeypressHandler__ClearCommandStateArray_x                  0x59A670
#define KeypressHandler__HandleKeyDown_x                           0x598FD0
#define KeypressHandler__HandleKeyUp_x                             0x5992F0
#define KeypressHandler__SaveKeymapping_x                          0x59A740

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70B420
#define MapViewMap__SaveEx_x                                       0x70ED00

#define PlayerPointManager__GetAltCurrency_x                       0x86CF60

// StringTable 
#define StringTable__getString_x                                   0x867A40

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C1FA0
#define PcZoneClient__RemovePetEffect_x                            0x5BD960

//Doors
#define EQSwitch__UseSwitch_x                                      0x54E6D0

//IconCache
#define IconCache__GetIcon_x                                       0x6A7640

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69E420
#define CContainerMgr__CloseContainer_x                            0x69EC40

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76CE10

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58DA90

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DF280
#define EQ_Spell__SpellAffects_x                                   0x4DF320
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DF350
#define CharacterZoneClient__CalcAffectChange_x                    0x447450
#define CLootWnd__LootAll_x                                        0x700D40

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B27F0
#define CTargetWnd__WndNotification_x                              0x7B22E0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B79D0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D8AF0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x496D30

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E9270
#define CSidlManager__FindAnimation1_x                             0x8DE090

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CE8A0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CE850
#define CAltAbilityData__GetMaxRank_x                              0x4C37E0

//CTargetRing
#define CTargetRing__Cast_x                                        0x58B370
