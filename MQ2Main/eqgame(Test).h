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
#define __ExpectedVersionDate                                     "Nov 18 2015"
#define __ExpectedVersionTime                                     "12:16:52"
#define __ActualVersionDate_x                                      0xADA618
#define __ActualVersionTime_x                                      0xADA624

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59FFC0
#define __MemChecker1_x                                            0x8A2100
#define __MemChecker2_x                                            0x6395E0
#define __MemChecker3_x                                            0x639530
#define __MemChecker4_x                                            0x7EE8E0
#define __EncryptPad0_x                                            0xC75D08
#define __EncryptPad1_x                                            0xE00DE8
#define __EncryptPad2_x                                            0xCBF7F0
#define __EncryptPad3_x                                            0xCBF3F0
#define __EncryptPad4_x                                            0xDD9F78
#define __EncryptPad5_x                                            0x11ACC60
#define __AC1_x                                                    0x7AB725
#define __AC2_x                                                    0x5541F7
#define __AC3_x                                                    0x568DB0
#define __AC4_x                                                    0x56FA30
#define __AC5_x                                                    0x57C17E
#define __AC6_x                                                    0x57FCC9
#define __AC7_x                                                    0x57682C
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
#define __do_loot_x                                                0x51B810
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
#define __CastRay_x                                                0x533360
#define __ConvertItemTags_x                                        0x520490
#define __ExecuteCmd_x                                             0x50AFE0
#define __EQGetTime_x                                              0x8A2460
#define __get_melee_range_x                                        0x511C50
#define __GetGaugeValueFromEQ_x                                    0x7AA460
#define __GetLabelFromEQ_x                                         0x7AB6B0
#define __ToggleKeyRingItem_x                                      0x47E1B0
#define __GetXTargetType_x                                         0x9335B0
#define __LoadFrontEnd_x                                           0x638C90
#define __NewUIINI_x                                               0x7A9D60
#define __ProcessGameEvents_x                                      0x578590
#define __ProcessMouseEvent_x                                      0x577D30
#define CrashDetected_x                                            0x63A760
#define wwsCrashReportCheckForUploader_x                           0x7FDFC0
#define DrawNetStatus_x                                            0x5AFC40
#define Util__FastTime_x                                           0x8A1DB0
#define Expansion_HoT_x                                            0x101C5CC
#define __HelpPath_x                                               0x109FD38
#define __STMLToText_x                                             0x8E6EF0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F080
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419EE0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C5320
#define AltAdvManager__IsAbilityReady_x                            0x4C5390
#define AltAdvManager__GetAAById_x                                 0x4C5750

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4641F0
#define CharacterZoneClient__MakeMeVisible_x                       0x469BD0
#define CharacterZoneClient__IsStackBlocked_x                      0x446380

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x668790

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6766F0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58EE00
#define CButtonWnd__CButtonWnd_x                                   0x8DB020

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x691B50
#define CChatManager__InitContextMenu_x                            0x6926D0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E5250
#define CContextMenu__dCContextMenu_x                              0x8E5460
#define CContextMenu__AddMenuItem_x                                0x8E5470
#define CContextMenu__RemoveMenuItem_x                             0x8E5760
#define CContextMenu__RemoveAllMenuItems_x                         0x8E5780
#define CContextMenuManager__AddMenu_x                             0x8D0F90
#define CContextMenuManager__RemoveMenu_x                          0x8D12E0
#define CContextMenuManager__PopupMenu_x                           0x8D1730
#define CContextMenuManager__Flush_x                               0x8D1000
#define CContextMenuManager__GetMenu_x                             0x415550

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x887590
#define CChatService__GetFriendName_x                              0x8875A0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x697980
#define CChatWindow__Clear_x                                       0x697530
#define CChatWindow__WndNotification_x                             0x697EC0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D4EA0
#define CComboWnd__Draw_x                                          0x8D50B0
#define CComboWnd__GetCurChoice_x                                  0x8D4C70
#define CComboWnd__GetListRect_x                                   0x8D5350
#define CComboWnd__GetTextRect_x                                   0x8D4F10
#define CComboWnd__InsertChoice_x                                  0x8D53C0
#define CComboWnd__SetColors_x                                     0x8D4C00
#define CComboWnd__SetChoice_x                                     0x8D4C30
#define CComboWnd__GetItemCount_x                                  0x8D4C60

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A10B0
#define CContainerWnd__vftable_x                                   0xAE3FE0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B3520
#define CDisplay__GetClickedActor_x                                0x4AC0A0
#define CDisplay__GetUserDefinedColor_x                            0x4AA960
#define CDisplay__GetWorldFilePath_x                               0x4A9DB0
#define CDisplay__is3dON_x                                         0x4A9180
#define CDisplay__ReloadUI_x                                       0x4BEAF0
#define CDisplay__WriteTextHD2_x                                   0x4AF8C0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FCDF0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E9BF0
#define CEditWnd__GetCharIndexPt_x                                 0x8EAC90
#define CEditWnd__GetDisplayString_x                               0x8E9DA0
#define CEditWnd__GetHorzOffset_x                                  0x8EA0E0
#define CEditWnd__GetLineForPrintableChar_x                        0x8EA750
#define CEditWnd__GetSelStartPt_x                                  0x8EAF50
#define CEditWnd__GetSTMLSafeText_x                                0x8EA280
#define CEditWnd__PointFromPrintableChar_x                         0x8EA840
#define CEditWnd__SelectableCharFromPoint_x                        0x8EA9C0
#define CEditWnd__SetEditable_x                                    0x8EA250

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x554940
#define CEverQuest__CreateTargetIndicator_x                        0x555570
#define CEverQuest__DeleteTargetIndicator_x                        0x5555F0
#define CEverQuest__DoTellWindow_x                                 0x55A330
#define CEverQuest__DropHeldItemOnGround_x                         0x563230
#define CEverQuest__dsp_chat_x                                     0x55BCE0
#define CEverQuest__Emote_x                                        0x55BF40
#define CEverQuest__EnterZone_x                                    0x570380
#define CEverQuest__GetBodyTypeDesc_x                              0x5511A0
#define CEverQuest__GetClassDesc_x                                 0x556EB0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5574B0
#define CEverQuest__GetDeityDesc_x                                 0x551A80
#define CEverQuest__GetLangDesc_x                                  0x551530
#define CEverQuest__GetRaceDesc_x                                  0x557670
#define CEverQuest__InterpretCmd_x                                 0x55C820
#define CEverQuest__LeftClickedOnPlayer_x                          0x574C90
#define CEverQuest__LMouseUp_x                                     0x576D80
#define CEverQuest__RightClickedOnPlayer_x                         0x575790
#define CEverQuest__RMouseUp_x                                     0x5767E0
#define CEverQuest__SetGameState_x                                 0x554FF0
#define CEverQuest__UPCNotificationFlush_x                         0x55DB80
#define CEverQuest__IssuePetCommand_x                              0x55D4E0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B1D40
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B1DA0
#define CGaugeWnd__Draw_x                                          0x6B21D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x435CF0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CEEF0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DB640
#define CInvSlotMgr__MoveItem_x                                    0x6DC580
#define CInvSlotMgr__SelectSlot_x                                  0x6DB6F0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6DAAD0
#define CInvSlot__SliderComplete_x                                 0x6D8300
#define CInvSlot__GetItemBase_x                                    0x6D7780

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DD990

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A6DE0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DECC0

// CLabel 
#define CLabel__Draw_x                                             0x6F9C00

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C0C60
#define CListWnd__dCListWnd_x                                      0x8C1C80
#define CListWnd__AddColumn_x                                      0x8C1C20
#define CListWnd__AddColumn1_x                                     0x8C14A0
#define CListWnd__AddLine_x                                        0x8C0F20
#define CListWnd__AddString_x                                      0x8C1130
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BDF90
#define CListWnd__CalculateVSBRange_x                              0x8C0110
#define CListWnd__ClearAllSel_x                                    0x8BD240
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C0AF0
#define CListWnd__Compare_x                                        0x8BEA90
#define CListWnd__Draw_x                                           0x8BFD20
#define CListWnd__DrawColumnSeparators_x                           0x8BFBB0
#define CListWnd__DrawHeader_x                                     0x8BD550
#define CListWnd__DrawItem_x                                       0x8BF0E0
#define CListWnd__DrawLine_x                                       0x8BF850
#define CListWnd__DrawSeparator_x                                  0x8BFC50
#define CListWnd__EnsureVisible_x                                  0x8BE0F0
#define CListWnd__ExtendSel_x                                      0x8BEFF0
#define CListWnd__GetColumnMinWidth_x                              0x8BCC00
#define CListWnd__GetColumnWidth_x                                 0x8BCB20
#define CListWnd__GetCurSel_x                                      0x8BC2E0
#define CListWnd__GetItemAtPoint_x                                 0x8BE390
#define CListWnd__GetItemAtPoint1_x                                0x8BE400
#define CListWnd__GetItemData_x                                    0x8BC630
#define CListWnd__GetItemHeight_x                                  0x8BDBE0
#define CListWnd__GetItemIcon_x                                    0x8BC810
#define CListWnd__GetItemRect_x                                    0x8BE1D0
#define CListWnd__GetItemText_x                                    0x8BC6C0
#define CListWnd__GetSelList_x                                     0x8C1390
#define CListWnd__GetSeparatorRect_x                               0x8BE9B0
#define CListWnd__RemoveLine_x                                     0x8C1310
#define CListWnd__SetColors_x                                      0x8BC430
#define CListWnd__SetColumnJustification_x                         0x8BCED0
#define CListWnd__SetColumnWidth_x                                 0x8BCBB0
#define CListWnd__SetCurSel_x                                      0x8BC320
#define CListWnd__SetItemColor_x                                   0x8C07D0
#define CListWnd__SetItemData_x                                    0x8BD2F0
#define CListWnd__SetItemText_x                                    0x8C0610
#define CListWnd__ShiftColumnSeparator_x                           0x8C04A0
#define CListWnd__Sort_x                                           0x8C1D80
#define CListWnd__ToggleSel_x                                      0x8BD1C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7132A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x734490
#define CMerchantWnd__RequestBuyItem_x                             0x73B300
#define CMerchantWnd__RequestSellItem_x                            0x73BD70
#define CMerchantWnd__SelectRecoverySlot_x                         0x734740
#define CMerchantWnd__SelectBuySellSlot_x                          0x7339A0
#define CMerchantWnd__ActualSelect_x                               0x738220

// CObfuscator
#define CObfuscator__doit_x                                        0x8678C0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8E0070
#define CSidlManager__CreateLabel_x                                0x79CDD0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65FA70
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65F990
#define CSidlScreenWnd__ConvertToRes_x                             0x8FCCD0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D7B40
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D9030
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D90E0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D85B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D74F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D6C20
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D76E0
#define CSidlScreenWnd__Init1_x                                    0x8D8D10
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D7BF0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D6DE0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D8800
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D66F0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D6BB0
#define CSidlScreenWnd__WndNotification_x                          0x8D8A90
#define CSidlScreenWnd__GetChildItem_x                             0x8D6CF0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8CA1B0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FA9E0
#define CSkillMgr__GetSkillCap_x                                   0x5FABA0
#define CSkillMgr__GetNameToken_x                                  0x5FA600

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FBF80
#define CSliderWnd__SetValue_x                                     0x8FC150
#define CSliderWnd__SetNumTicks_x                                  0x8FC8D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A4A90

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6970
#define CStmlWnd__CalculateHSBRange_x                              0x8EEE70
#define CStmlWnd__CalculateVSBRange_x                              0x8EEF00
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EF080
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EF960
#define CStmlWnd__ForceParseNow_x                                  0x8F72C0
#define CStmlWnd__GetNextTagPiece_x                                0x8EF860
#define CStmlWnd__GetSTMLText_x                                    0x696DD0
#define CStmlWnd__GetVisibleText_x                                 0x8F03B0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F2740
#define CStmlWnd__MakeStmlColorTag_x                               0x8EE170
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EE1D0
#define CStmlWnd__SetSTMLText_x                                    0x8F3FB0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F6610
#define CStmlWnd__UpdateHistoryString_x                            0x8F12F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8ED800
#define CTabWnd__DrawCurrentPage_x                                 0x8ED070
#define CTabWnd__DrawTab_x                                         0x8ECE30
#define CTabWnd__GetCurrentPage_x                                  0x8ED440
#define CTabWnd__GetPageInnerRect_x                                0x8ECB20
#define CTabWnd__GetTabInnerRect_x                                 0x8ECD20
#define CTabWnd__GetTabRect_x                                      0x8ECBF0
#define CTabWnd__InsertPage_x                                      0x8EDAF0
#define CTabWnd__SetPage_x                                         0x8ED470
#define CTabWnd__SetPageRect_x                                     0x8ED740
#define CTabWnd__UpdatePage_x                                      0x8EDA90

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431A30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D4870

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x902160

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8BA3F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59C540
#define CXStr__CXStr1_x                                            0x8AF1A0
#define CXStr__CXStr3_x                                            0x89EE40
#define CXStr__dCXStr_x                                            0x4C6AD0
#define CXStr__operator_equal_x                                    0x89EFB0
#define CXStr__operator_equal1_x                                   0x89F000
#define CXStr__operator_plus_equal1_x                              0x8A00E0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C9430
#define CXWnd__Center_x                                            0x8CF560
#define CXWnd__ClrFocus_x                                          0x8C8FF0
#define CXWnd__DoAllDrawing_x                                      0x8CF1B0
#define CXWnd__DrawChildren_x                                      0x8CF350
#define CXWnd__DrawColoredRect_x                                   0x8C97D0
#define CXWnd__DrawTooltip_x                                       0x8C9A80
#define CXWnd__DrawTooltipAtPoint_x                                0x8CE110
#define CXWnd__GetBorderFrame_x                                    0x8C9E90
#define CXWnd__GetChildWndAt_x                                     0x8CFF30
#define CXWnd__GetClientClipRect_x                                 0x8C9C90
#define CXWnd__GetScreenClipRect_x                                 0x8CE810
#define CXWnd__GetScreenRect_x                                     0x8CA060
#define CXWnd__GetTooltipRect_x                                    0x8C9910
#define CXWnd__GetWindowTextA_x                                    0x422F90
#define CXWnd__IsActive_x                                          0x8C4A50
#define CXWnd__IsDescendantOf_x                                    0x8C9DD0
#define CXWnd__IsReallyVisible_x                                   0x8CD140
#define CXWnd__IsType_x                                            0x8FE960
#define CXWnd__Move_x                                              0x8CC870
#define CXWnd__Move1_x                                             0x8CEE60
#define CXWnd__ProcessTransition_x                                 0x8C93D0
#define CXWnd__Refade_x                                            0x8C91A0
#define CXWnd__Resize_x                                            0x8CA120
#define CXWnd__Right_x                                             0x8CE610
#define CXWnd__SetFocus_x                                          0x8CB9E0
#define CXWnd__SetFont_x                                           0x8C9040
#define CXWnd__SetKeyTooltip_x                                     0x8CA380
#define CXWnd__SetMouseOver_x                                      0x8CEB40
#define CXWnd__StartFade_x                                         0x8C9480
#define CXWnd__GetChildItem_x                                      0x8CEA90

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C6390
#define CXWndManager__DrawWindows_x                                0x8C5FD0
#define CXWndManager__GetKeyboardFlags_x                           0x8C4590
#define CXWndManager__HandleKeyboardMsg_x                          0x8C4EF0
#define CXWndManager__RemoveWnd_x                                  0x8C4BE0

// CDBStr
#define CDBStr__GetString_x                                        0x4A7730

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E000
#define EQ_Character__Cur_HP_x                                     0x4638C0
#define EQ_Character__GetAACastingTimeModifier_x                   0x445F00
#define EQ_Character__GetCharInfo2_x                               0x8720B0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43DEC0
#define EQ_Character__GetFocusRangeModifier_x                      0x43E0B0
#define EQ_Character__Max_Endurance_x                              0x5C21B0
#define EQ_Character__Max_HP_x                                     0x4594E0
#define EQ_Character__Max_Mana_x                                   0x5C1FE0
#define EQ_Character__doCombatAbility_x                            0x5BF630
#define EQ_Character__UseSkill_x                                   0x46EDD0
#define EQ_Character__GetConLevel_x                                0x5B4250
#define EQ_Character__IsExpansionFlag_x                            0x4224D0
#define EQ_Character__TotalEffect_x                                0x44B2A0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x594770
#define EQ_Item__CreateItemTagString_x                             0x851400
#define EQ_Item__IsStackable_x                                     0x845920
#define EQ_Item__GetImageNum_x                                     0x848640
#define EQ_Item__CreateItemClient_x                                0x595360
#define EQ_Item__GetItemValue_x                                    0x8500C0
#define EQ_Item__ValueSellMerchant_x                               0x852710

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C7470
#define EQ_LoadingS__Array_x                                       0xC1F0A0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C3810
#define EQ_PC__GetAlternateAbilityId_x                             0x85A8A0
#define EQ_PC__GetCombatAbility_x                                  0x85A930
#define EQ_PC__GetCombatAbilityTimer_x                             0x855680
#define EQ_PC__GetItemTimerValue_x                                 0x5BD140
#define EQ_PC__HasLoreItem_x                                       0x5B7720
#define EQ_PC__AlertInventoryChanged_x                             0x5B4220
#define EQ_PC__GetPcZoneClient_x                                   0x5DDDE0
#define EQ_PC__RemoveMyAffect_x                                    0x5BC600

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50FCC0
#define EQItemList__add_item_x                                     0x50FC00
#define EQItemList__delete_item_x                                  0x5100C0
#define EQItemList__FreeItemList_x                                 0x50FFC0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A6A00

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C8DE0
#define EQPlayer__dEQPlayer_x                                      0x5D1C60
#define EQPlayer__DoAttack_x                                       0x5E3D00
#define EQPlayer__EQPlayer_x                                       0x5D4080
#define EQPlayer__SetNameSpriteState_x                             0x5CE930
#define EQPlayer__SetNameSpriteTint_x                              0x5CA1F0
#define EQPlayer__IsBodyType_j_x                                   0x92F800
#define EQPlayer__IsTargetable_x                                   0x930100
#define EQPlayer__CanSee_x                                         0x930620
#define PlayerZoneClient__ChangeHeight_x                           0x5E3BC0
#define EQPlayer__CanSeeTargetIndicator_x                          0x930710

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D83F0
#define EQPlayerManager__GetSpawnByName_x                          0x5D8850

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59A870
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59A8B0
#define KeypressHandler__ClearCommandStateArray_x                  0x59A450
#define KeypressHandler__HandleKeyDown_x                           0x598DB0
#define KeypressHandler__HandleKeyUp_x                             0x5990D0
#define KeypressHandler__SaveKeymapping_x                          0x59A520

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70B680
#define MapViewMap__SaveEx_x                                       0x70EF60

#define PlayerPointManager__GetAltCurrency_x                       0x86D080

// StringTable 
#define StringTable__getString_x                                   0x867B60

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C1C60
#define PcZoneClient__RemovePetEffect_x                            0x5BD630

//Doors
#define EQSwitch__UseSwitch_x                                      0x54E560

//IconCache
#define IconCache__GetIcon_x                                       0x6A75E0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69E3D0
#define CContainerMgr__CloseContainer_x                            0x69EBF0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76CF00

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58D890

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DF430
#define EQ_Spell__SpellAffects_x                                   0x4DF4D0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DF500
#define CharacterZoneClient__CalcAffectChange_x                    0x4472F0
#define CLootWnd__LootAll_x                                        0x700F40

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B2A00
#define CTargetWnd__WndNotification_x                              0x7B24F0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B7BE0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D8C80

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x496EE0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E9220
#define CSidlManager__FindAnimation1_x                             0x8DDF50

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CEAF0
#define CAltAbilityData__GetMercMaxRank_x                          0x4CEAA0
#define CAltAbilityData__GetMaxRank_x                              0x4C39E0

//CTargetRing
#define CTargetRing__Cast_x                                        0x58B180
