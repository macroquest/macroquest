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
#define __ExpectedVersionDate                                     "Nov 19 2015"
#define __ExpectedVersionTime                                     "14:43:06"
#define __ActualVersionDate_x                                      0xAD9618
#define __ActualVersionTime_x                                      0xAD9624

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59F760
#define __MemChecker1_x                                            0x8A1A00
#define __MemChecker2_x                                            0x638A50
#define __MemChecker3_x                                            0x6389A0
#define __MemChecker4_x                                            0x7EDB90
#define __EncryptPad0_x                                            0xC74D08
#define __EncryptPad1_x                                            0xDFFDE8
#define __EncryptPad2_x                                            0xCBE7F0
#define __EncryptPad3_x                                            0xCBE3F0
#define __EncryptPad4_x                                            0xDD8F78
#define __EncryptPad5_x                                            0x11ABC60
#define __AC1_x                                                    0x7AA995
#define __AC2_x                                                    0x5539D7
#define __AC3_x                                                    0x568590
#define __AC4_x                                                    0x56F210
#define __AC5_x                                                    0x57B95E
#define __AC6_x                                                    0x57F4A9
#define __AC7_x                                                    0x57600C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data                                                 0x1FB65C

// Direct Input
#define DI8__Main_x                                                0x11ABC38
#define DI8__Keyboard_x                                            0x11ABC3C
#define DI8__Mouse_x                                               0x11ABC40
#define DI8__Mouse_Copy_x                                          0x101A254
#define DI8__Mouse_Check_x                                         0x10A3B24
#define __AltTimerReady_x                                          0x100B5A1
#define __Attack_x                                                 0x109E7C7
#define __Autofire_x                                               0x109E7C8
#define __BindList_x                                               0xC36DD8
#define __bCommandEnabled_x                                        0x10096B0
#define __Clicks_x                                                 0x101A310
#define __CommandList_x                                            0xC3B148
#define __CurrentMapLabel_x                                        0x11B1690
#define __CurrentSocial_x                                          0xBEDF44
#define __DoAbilityList_x                                          0x1050A7C
#define __do_loot_x                                                0x51AE70
#define __DrawHandler_x                                            0x1818444
#define __GroupCount_x                                             0x100AC7A

#define __Guilds_x                                                 0x1010890
#define __gWorld_x                                                 0x100D134
#define __HotkeyPage_x                                             0x109747C
#define __HWnd_x                                                   0x10A3B40
#define __InChatMode_x                                             0x101A23C
#define __LastTell_x                                               0x101C180
#define __LMouseHeldTime_x                                         0x101A37C
#define __Mouse_x                                                  0x11ABC44
#define __MouseLook_x                                              0x101A2D6
#define __MouseEventTime_x                                         0x109EFCC
#define __gpbCommandEvent_x                                        0x100D1FC
#define __NetStatusToggle_x                                        0x101A2D9
#define __PCNames_x                                                0x101B7A0
#define __RangeAttackReady_x                                       0x101B460
#define __RMouseHeldTime_x                                         0x101A378
#define __RunWalkState_x                                           0x101A240
#define __ScreenMode_x                                             0xF593E0
#define __ScreenX_x                                                0x101A1F4
#define __ScreenY_x                                                0x101A1F0
#define __ScreenXMax_x                                             0x101A1F8
#define __ScreenYMax_x                                             0x101A1FC
#define __ServerHost_x                                             0x100ABC4
#define __ServerName_x                                             0x1050A3C
#define __ShiftKeyDown_x                                           0x101A8E4
#define __ShowNames_x                                              0x101B634
#define __Socials_x                                                0x1050B3C
#define __SubscriptionType_x                                       0x11DFBC0
#define __TargetAggroHolder_x                                      0x11B38CC
#define __GroupAggro_x                                             0x11B390C
#define __LoginName_x                                              0x10A2718
#define __Inviter_x                                                0x109E744


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x100D220
#define instEQZoneInfo_x                                           0x101A4CC
#define instKeypressHandler_x                                      0x109EFB0
#define pinstActiveBanker_x                                        0x100D1D8
#define pinstActiveCorpse_x                                        0x100D1DC
#define pinstActiveGMaster_x                                       0x100D1E0
#define pinstActiveMerchant_x                                      0x100D1D4
#define pinstAggroInfo_x                                           0xE1B7D8
#define pinstAltAdvManager_x                                       0xF5A4E8
#define pinstAuraMgr_x                                             0xE276A8
#define pinstBandageTarget_x                                       0x100D1C0
#define pinstCamActor_x                                            0xF59DF4
#define pinstCDBStr_x                                              0xF59374
#define pinstCDisplay_x                                            0x100D1E8
#define pinstCEverQuest_x                                          0x11ABDB8
#define pinstCharData_x                                            0x100D1A4
#define pinstCharSpawn_x                                           0x100D1CC
#define pinstControlledMissile_x                                   0x100D1A0
#define pinstControlledPlayer_x                                    0x100D1CC
#define pinstCSidlManager_x                                        0x181787C
#define pinstCXWndManager_x                                        0x1817874
#define instDynamicZone_x                                          0x101A088
#define pinstDZMember_x                                            0x101A198
#define pinstDZTimerInfo_x                                         0x101A19C
#define pinstEQItemList_x                                          0x1009900
#define instEQMisc_x                                               0xC102C8
#define pinstEQSoundManager_x                                      0xF5AA48
#define instExpeditionLeader_x                                     0x101A0D2
#define instExpeditionName_x                                       0x101A112
#define pinstGroup_x                                               0x100AC76
#define pinstImeManager_x                                          0x1817880
#define pinstLocalPlayer_x                                         0x100D1B8
#define pinstMercenaryData_x                                       0x109F600
#define pinstMercenaryStats_x                                      0x11B3A18
#define pinstMercAltAbilities_x                                    0xF5A874
#define pinstModelPlayer_x                                         0x100D1E4
#define pinstPCData_x                                              0x100D1A4
#define pinstSkillMgr_x                                            0x10A0438
#define pinstSpawnManager_x                                        0x109FD20
#define pinstSpellManager_x                                        0x10A0580
#define pinstSpellSets_x                                           0x10974E0
#define pinstStringTable_x                                         0x100D14C
#define pinstSwitchManager_x                                       0x100A808
#define pinstTarget_x                                              0x100D1D0
#define pinstTargetObject_x                                        0x100D1A8
#define pinstTargetSwitch_x                                        0x100D1AC
#define pinstTaskMember_x                                          0xF592C0
#define pinstTrackTarget_x                                         0x100D1C4
#define pinstTradeTarget_x                                         0x100D1B4
#define instTributeActive_x                                        0xC102ED
#define pinstViewActor_x                                           0xF59DF0
#define pinstWorldData_x                                           0x100D188
#define pinstZoneAddr_x                                            0x101A78C
#define pinstPlayerPath_x                                          0x109BEA0
#define pinstTargetIndicator_x                                     0x109C838
#define pinstCTargetManager_x                                      0x10A0778

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE1BCB8
#define pinstCAudioTriggersWindow_x                                0xE1BB48
#define pinstCCharacterSelect_x                                    0xF59C84
#define pinstCFacePick_x                                           0xF59A34
#define pinstCNoteWnd_x                                            0xF59C3C
#define pinstCBookWnd_x                                            0xF59C44
#define pinstCPetInfoWnd_x                                         0xF59C48
#define pinstCTrainWnd_x                                           0xF59C4C
#define pinstCSkillsWnd_x                                          0xF59C50
#define pinstCSkillsSelectWnd_x                                    0xF59C54
#define pinstCCombatSkillsSelectWnd_x                              0xF59C58
#define pinstCFriendsWnd_x                                         0xF59C5C
#define pinstCAuraWnd_x                                            0xF59C60
#define pinstCRespawnWnd_x                                         0xF59C64
#define pinstCBandolierWnd_x                                       0xF59C68
#define pinstCPotionBeltWnd_x                                      0xF59C6C
#define pinstCAAWnd_x                                              0xF59C70
#define pinstCGroupSearchFiltersWnd_x                              0xF59C74
#define pinstCLoadskinWnd_x                                        0xF59C78
#define pinstCAlarmWnd_x                                           0xF59C7C
#define pinstCMusicPlayerWnd_x                                     0xF59C80
#define pinstCMailWnd_x                                            0xF59C88
#define pinstCMailCompositionWnd_x                                 0xF59C8C
#define pinstCMailAddressBookWnd_x                                 0xF59C90
#define pinstCRaidWnd_x                                            0xF59C98
#define pinstCRaidOptionsWnd_x                                     0xF59C9C
#define pinstCBreathWnd_x                                          0xF59CA0
#define pinstCMapViewWnd_x                                         0xF59CA4
#define pinstCMapToolbarWnd_x                                      0xF59CA8
#define pinstCEditLabelWnd_x                                       0xF59CAC
#define pinstCTargetWnd_x                                          0xF59CB0
#define pinstCColorPickerWnd_x                                     0xF59CB4
#define pinstCPlayerWnd_x                                          0xF59CB8
#define pinstCOptionsWnd_x                                         0xF59CBC
#define pinstCBuffWindowNORMAL_x                                   0xF59CC0
#define pinstCBuffWindowSHORT_x                                    0xF59CC4
#define pinstCharacterCreation_x                                   0xF59CC8
#define pinstCCursorAttachment_x                                   0xF59CCC
#define pinstCCastingWnd_x                                         0xF59CD0
#define pinstCCastSpellWnd_x                                       0xF59CD4
#define pinstCSpellBookWnd_x                                       0xF59CD8
#define pinstCInventoryWnd_x                                       0xF59CDC
#define pinstCBankWnd_x                                            0xF59CE4
#define pinstCQuantityWnd_x                                        0xF59CE8
#define pinstCLootWnd_x                                            0xF59CEC
#define pinstCActionsWnd_x                                         0xF59CF0
#define pinstCCombatAbilityWnd_x                                   0xF59CF4
#define pinstCMerchantWnd_x                                        0xF59CF8
#define pinstCTradeWnd_x                                           0xF59CFC
#define pinstCSelectorWnd_x                                        0xF59D00
#define pinstCBazaarWnd_x                                          0xF59D04
#define pinstCBazaarSearchWnd_x                                    0xF59D08
#define pinstCGiveWnd_x                                            0xF59D24
#define pinstCTrackingWnd_x                                        0xF59D2C
#define pinstCInspectWnd_x                                         0xF59D30
#define pinstCSocialEditWnd_x                                      0xF59D34
#define pinstCFeedbackWnd_x                                        0xF59D38
#define pinstCBugReportWnd_x                                       0xF59D3C
#define pinstCVideoModesWnd_x                                      0xF59D40
#define pinstCTextEntryWnd_x                                       0xF59D48
#define pinstCFileSelectionWnd_x                                   0xF59D4C
#define pinstCCompassWnd_x                                         0xF59D50
#define pinstCPlayerNotesWnd_x                                     0xF59D54
#define pinstCGemsGameWnd_x                                        0xF59D58
#define pinstCTimeLeftWnd_x                                        0xF59D5C
#define pinstCPetitionQWnd_x                                       0xF59D78
#define pinstCSoulmarkWnd_x                                        0xF59D7C
#define pinstCStoryWnd_x                                           0xF59D80
#define pinstCJournalTextWnd_x                                     0xF59D84
#define pinstCJournalCatWnd_x                                      0xF59D88
#define pinstCBodyTintWnd_x                                        0xF59D8C
#define pinstCServerListWnd_x                                      0xF59D90
#define pinstCAvaZoneWnd_x                                         0xF59D9C
#define pinstCBlockedBuffWnd_x                                     0xF59DA0
#define pinstCBlockedPetBuffWnd_x                                  0xF59DA4
#define pinstCInvSlotMgr_x                                         0xF59DE8
#define pinstCContainerMgr_x                                       0xF59DEC
#define pinstCAdventureLeaderboardWnd_x                            0x11AC768
#define pinstCAdventureRequestWnd_x                                0x11AC7E0
#define pinstCAltStorageWnd_x                                      0x11ACAC0
#define pinstCAdventureStatsWnd_x                                  0x11AC858
#define pinstCBarterMerchantWnd_x                                  0x11AD6A8
#define pinstCBarterSearchWnd_x                                    0x11AD720
#define pinstCBarterWnd_x                                          0x11AD798
#define pinstCChatManager_x                                        0x11ADE28
#define pinstCDynamicZoneWnd_x                                     0x11AE2D8
#define pinstCEQMainWnd_x                                          0x11AE470
#define pinstCFellowshipWnd_x                                      0x11AE26C
#define pinstCFindLocationWnd_x                                    0x11AE740
#define pinstCGroupSearchWnd_x                                     0x11AEA10
#define pinstCGroupWnd_x                                           0x11AEA88
#define pinstCGuildBankWnd_x                                       0x11AEB00
#define pinstCGuildMgmtWnd_x                                       0x11B0BF0
#define pinstCHotButtonWnd_x                                       0x11B0CBC
#define pinstCHotButtonWnd1_x                                      0x11B0CBC
#define pinstCHotButtonWnd2_x                                      0x11B0CC0
#define pinstCHotButtonWnd3_x                                      0x11B0CC4
#define pinstCHotButtonWnd4_x                                      0x11B0CE8
#define pinstCItemDisplayManager_x                                 0x11B0FE0
#define pinstCItemExpTransferWnd_x                                 0x11B105C
#define pinstCLFGuildWnd_x                                         0x11B1338
#define pinstCMIZoneSelectWnd_x                                    0x11B1920
#define pinstCConfirmationDialog_x                                 0x11B2028
#define pinstCPopupWndManager_x                                    0x11B2028
#define pinstCProgressionSelectionWnd_x                            0x11B2118
#define pinstCPvPStatsWnd_x                                        0x11B2208
#define pinstCSystemInfoDialogBox_x                                0x11B2910
#define pinstCTaskWnd_x                                            0x11B3CD8
#define pinstCTaskSomething_x                                      0xE27E68
#define pinstCTaskTemplateSelectWnd_x                              0x11B3C60
#define pinstCTipWndOFDAY_x                                        0x11B3F30
#define pinstCTipWndCONTEXT_x                                      0x11B3F34
#define pinstCTitleWnd_x                                           0x11B3FB0
#define pinstCContextMenuManager_x                                 0x18177EC
#define pinstCVoiceMacroWnd_x                                      0x10A0BE8
#define pinstCHtmlWnd_x                                            0x10A0CE0
#define pinstIconCache_x                                           0x11AE444
#define pinstCTradeskillWnd_x                                      0x11B40B0
#define pinstCAdvancedLootWnd_x                                    0xF59DDC
#define pinstRewardSelectionWnd_x                                  0x11B2730

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5329C0
#define __ConvertItemTags_x                                        0x51FAF0
#define __ExecuteCmd_x                                             0x50A620
#define __EQGetTime_x                                              0x8A1D60
#define __get_melee_range_x                                        0x5112B0
#define __GetGaugeValueFromEQ_x                                    0x7A96D0
#define __GetLabelFromEQ_x                                         0x7AA920
#define __ToggleKeyRingItem_x                                      0x47E000
#define __GetXTargetType_x                                         0x932D50
#define __LoadFrontEnd_x                                           0x638100
#define __NewUIINI_x                                               0x7A8FD0
#define __ProcessGameEvents_x                                      0x577D70
#define __ProcessMouseEvent_x                                      0x577510
#define CrashDetected_x                                            0x639BD0
#define wwsCrashReportCheckForUploader_x                           0x7FD410
#define DrawNetStatus_x                                            0x5AF1B0
#define Util__FastTime_x                                           0x8A16B0
#define Expansion_HoT_x                                            0x101B5CC
#define __HelpPath_x                                               0x109ED38
#define __STMLToText_x                                             0x8E67E0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41EFC0
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419E10

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C51A0
#define AltAdvManager__IsAbilityReady_x                            0x4C5210
#define AltAdvManager__GetAAById_x                                 0x4C55D0
#define AltAdvManager__CanTrainAbility_x                           0x4C5E90
#define AltAdvManager__CanSeeAbility_x                             0x4C5A90

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x464200
#define CharacterZoneClient__MakeMeVisible_x                       0x469BE0
#define CharacterZoneClient__IsStackBlocked_x                      0x446380

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x667BE0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x675690

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58E600
#define CButtonWnd__CButtonWnd_x                                   0x8DAA00

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x691090
#define CChatManager__InitContextMenu_x                            0x691C10

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E4B60
#define CContextMenu__dCContextMenu_x                              0x8E4D60
#define CContextMenu__AddMenuItem_x                                0x8E4D70
#define CContextMenu__RemoveMenuItem_x                             0x8E5050
#define CContextMenu__RemoveAllMenuItems_x                         0x8E5070
#define CContextMenuManager__AddMenu_x                             0x8D09A0
#define CContextMenuManager__RemoveMenu_x                          0x8D0CD0
#define CContextMenuManager__PopupMenu_x                           0x8D1120
#define CContextMenuManager__Flush_x                               0x8D0A10
#define CContextMenuManager__GetMenu_x                             0x415460

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x845310
#define CChatService__GetFriendName_x                              0x886E40

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x696EC0
#define CChatWindow__Clear_x                                       0x696A70
#define CChatWindow__WndNotification_x                             0x6973F0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D4890
#define CComboWnd__Draw_x                                          0x8D4AA0
#define CComboWnd__GetCurChoice_x                                  0x8D4660
#define CComboWnd__GetListRect_x                                   0x8D4D40
#define CComboWnd__GetTextRect_x                                   0x8D4900
#define CComboWnd__InsertChoice_x                                  0x8D4DB0
#define CComboWnd__SetColors_x                                     0x8D45F0
#define CComboWnd__SetChoice_x                                     0x8D4620
#define CComboWnd__GetItemCount_x                                  0x8D4650

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6A05D0
#define CContainerWnd__vftable_x                                   0xAE2FE0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B3240
#define CDisplay__GetClickedActor_x                                0x4ABDC0
#define CDisplay__GetUserDefinedColor_x                            0x4AA680
#define CDisplay__GetWorldFilePath_x                               0x4A9AD0
#define CDisplay__is3dON_x                                         0x4A8EA0
#define CDisplay__ReloadUI_x                                       0x4BE810
#define CDisplay__WriteTextHD2_x                                   0x4AF5E0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FC610

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E9490
#define CEditWnd__GetCharIndexPt_x                                 0x8EA510
#define CEditWnd__GetDisplayString_x                               0x8E9640
#define CEditWnd__GetHorzOffset_x                                  0x8E9980
#define CEditWnd__GetLineForPrintableChar_x                        0x8E9FE0
#define CEditWnd__GetSelStartPt_x                                  0x8EA7C0
#define CEditWnd__GetSTMLSafeText_x                                0x8E9B10
#define CEditWnd__PointFromPrintableChar_x                         0x8EA0D0
#define CEditWnd__SelectableCharFromPoint_x                        0x8EA250
#define CEditWnd__SetEditable_x                                    0x8E9AE0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x554120
#define CEverQuest__CreateTargetIndicator_x                        0x554D50
#define CEverQuest__DeleteTargetIndicator_x                        0x554DD0
#define CEverQuest__DoTellWindow_x                                 0x559B20
#define CEverQuest__DropHeldItemOnGround_x                         0x562A10
#define CEverQuest__dsp_chat_x                                     0x55B4D0
#define CEverQuest__Emote_x                                        0x55B730
#define CEverQuest__EnterZone_x                                    0x56FB60
#define CEverQuest__GetBodyTypeDesc_x                              0x550980
#define CEverQuest__GetClassDesc_x                                 0x556690
#define CEverQuest__GetClassThreeLetterCode_x                      0x556C90
#define CEverQuest__GetDeityDesc_x                                 0x551260
#define CEverQuest__GetLangDesc_x                                  0x550D10
#define CEverQuest__GetRaceDesc_x                                  0x556E50
#define CEverQuest__InterpretCmd_x                                 0x55C000
#define CEverQuest__LeftClickedOnPlayer_x                          0x574470
#define CEverQuest__LMouseUp_x                                     0x576560
#define CEverQuest__RightClickedOnPlayer_x                         0x574F70
#define CEverQuest__RMouseUp_x                                     0x575FC0
#define CEverQuest__SetGameState_x                                 0x5547D0
#define CEverQuest__UPCNotificationFlush_x                         0x55D360
#define CEverQuest__IssuePetCommand_x                              0x55CCC0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B1240
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B12A0
#define CGaugeWnd__Draw_x                                          0x6B16D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x435CE0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CE2F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DAA50
#define CInvSlotMgr__MoveItem_x                                    0x6DB990
#define CInvSlotMgr__SelectSlot_x                                  0x6DAB00

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D9EE0
#define CInvSlot__SliderComplete_x                                 0x6D7710
#define CInvSlot__GetItemBase_x                                    0x6D6B90

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DCD80

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A6030
#define CItemDisplayWnd__UpdateStrings_x                           0x6DE0B0

// CLabel 
#define CLabel__Draw_x                                             0x6F8FD0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C0650
#define CListWnd__dCListWnd_x                                      0x8C1670
#define CListWnd__AddColumn_x                                      0x8C1610
#define CListWnd__AddColumn1_x                                     0x8C0E90
#define CListWnd__AddLine_x                                        0x8C0910
#define CListWnd__AddString_x                                      0x8C0B20
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BD990
#define CListWnd__CalculateVSBRange_x                              0x8BFB00
#define CListWnd__ClearAllSel_x                                    0x8BCC50
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8C04E0
#define CListWnd__Compare_x                                        0x8BE490
#define CListWnd__Draw_x                                           0x8BF710
#define CListWnd__DrawColumnSeparators_x                           0x8BF5A0
#define CListWnd__DrawHeader_x                                     0x8BCF60
#define CListWnd__DrawItem_x                                       0x8BEAE0
#define CListWnd__DrawLine_x                                       0x8BF240
#define CListWnd__DrawSeparator_x                                  0x8BF640
#define CListWnd__EnsureVisible_x                                  0x8BDAF0
#define CListWnd__ExtendSel_x                                      0x8BE9F0
#define CListWnd__GetColumnMinWidth_x                              0x8BC610
#define CListWnd__GetColumnWidth_x                                 0x8BC530
#define CListWnd__GetCurSel_x                                      0x8BBD20
#define CListWnd__GetItemAtPoint_x                                 0x8BDD80
#define CListWnd__GetItemAtPoint1_x                                0x8BDDF0
#define CListWnd__GetItemData_x                                    0x8BC050
#define CListWnd__GetItemHeight_x                                  0x8BD5F0
#define CListWnd__GetItemIcon_x                                    0x8BC230
#define CListWnd__GetItemRect_x                                    0x8BDBC0
#define CListWnd__GetItemText_x                                    0x8BC0E0
#define CListWnd__GetSelList_x                                     0x8C0D80
#define CListWnd__GetSeparatorRect_x                               0x8BE3B0
#define CListWnd__RemoveLine_x                                     0x8C0D00
#define CListWnd__SetColors_x                                      0x8BBE70
#define CListWnd__SetColumnJustification_x                         0x8BC8E0
#define CListWnd__SetColumnWidth_x                                 0x8BC5C0
#define CListWnd__SetCurSel_x                                      0x8BBD60
#define CListWnd__SetItemColor_x                                   0x8C01C0
#define CListWnd__SetItemData_x                                    0x8BCD00
#define CListWnd__SetItemText_x                                    0x8C0000
#define CListWnd__ShiftColumnSeparator_x                           0x8BFE90
#define CListWnd__Sort_x                                           0x8C1770
#define CListWnd__ToggleSel_x                                      0x8BCBD0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x712520

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7338B0
#define CMerchantWnd__RequestBuyItem_x                             0x73A710
#define CMerchantWnd__RequestSellItem_x                            0x73B180
#define CMerchantWnd__SelectRecoverySlot_x                         0x733B60
#define CMerchantWnd__SelectBuySellSlot_x                          0x732DC0
#define CMerchantWnd__ActualSelect_x                               0x737630

// CObfuscator
#define CObfuscator__doit_x                                        0x8671E0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8DFA00
#define CSidlManager__CreateLabel_x                                0x79C030

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65EF20
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65EE40
#define CSidlScreenWnd__ConvertToRes_x                             0x8FC4F0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D7530
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D8A40
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D8AF0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D7FB0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D6EE0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D6620
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D70D0
#define CSidlScreenWnd__Init1_x                                    0x8D8710
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D75E0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D67E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D8200
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D60E0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D65B0
#define CSidlScreenWnd__WndNotification_x                          0x8D8490
#define CSidlScreenWnd__GetChildItem_x                             0x8D66F0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C9C50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5FA0E0
#define CSkillMgr__GetSkillCap_x                                   0x5FA2A0
#define CSkillMgr__GetNameToken_x                                  0x5F9D00

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FB7B0
#define CSliderWnd__SetValue_x                                     0x8FB980
#define CSliderWnd__SetNumTicks_x                                  0x8FC100

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A3CE0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F6190
#define CStmlWnd__CalculateHSBRange_x                              0x8EE6B0
#define CStmlWnd__CalculateVSBRange_x                              0x8EE740
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EE8C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EF1A0
#define CStmlWnd__ForceParseNow_x                                  0x8F6AE0
#define CStmlWnd__GetNextTagPiece_x                                0x8EF0A0
#define CStmlWnd__GetSTMLText_x                                    0x696310
#define CStmlWnd__GetVisibleText_x                                 0x8EFBF0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F1F80
#define CStmlWnd__MakeStmlColorTag_x                               0x8ED9B0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8EDA10
#define CStmlWnd__SetSTMLText_x                                    0x8F37F0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F5E30
#define CStmlWnd__UpdateHistoryString_x                            0x8F0B30

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8ED040
#define CTabWnd__DrawCurrentPage_x                                 0x8EC8B0
#define CTabWnd__DrawTab_x                                         0x8EC680
#define CTabWnd__GetCurrentPage_x                                  0x8ECC80
#define CTabWnd__GetPageInnerRect_x                                0x8EC370
#define CTabWnd__GetTabInnerRect_x                                 0x8EC570
#define CTabWnd__GetTabRect_x                                      0x8EC440
#define CTabWnd__InsertPage_x                                      0x8ED330
#define CTabWnd__SetPage_x                                         0x8ECCB0
#define CTabWnd__SetPageRect_x                                     0x8ECF80
#define CTabWnd__UpdatePage_x                                      0x8ED2D0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431A50

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D4260

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x901970

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B9D70

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59BCF0
#define CXStr__CXStr1_x                                            0x7DA500
#define CXStr__CXStr3_x                                            0x89E740
#define CXStr__dCXStr_x                                            0x59C040
#define CXStr__operator_equal_x                                    0x89E8B0
#define CXStr__operator_equal1_x                                   0x89E900
#define CXStr__operator_plus_equal1_x                              0x89F9E0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C8ED0
#define CXWnd__Center_x                                            0x8CEFD0
#define CXWnd__ClrFocus_x                                          0x8C8AA0
#define CXWnd__DoAllDrawing_x                                      0x8CEC20
#define CXWnd__DrawChildren_x                                      0x8CEDC0
#define CXWnd__DrawColoredRect_x                                   0x8C9290
#define CXWnd__DrawTooltip_x                                       0x8C9540
#define CXWnd__DrawTooltipAtPoint_x                                0x8CDBC0
#define CXWnd__GetBorderFrame_x                                    0x8C9950
#define CXWnd__GetChildWndAt_x                                     0x8CF9A0
#define CXWnd__GetClientClipRect_x                                 0x8C9760
#define CXWnd__GetScreenClipRect_x                                 0x8CE2B0
#define CXWnd__GetScreenRect_x                                     0x8C9B00
#define CXWnd__GetTooltipRect_x                                    0x8C93D0
#define CXWnd__GetWindowTextA_x                                    0x422F40
#define CXWnd__IsActive_x                                          0x8C4450
#define CXWnd__IsDescendantOf_x                                    0x8C98A0
#define CXWnd__IsReallyVisible_x                                   0x8CCBE0
#define CXWnd__IsType_x                                            0x8FE150
#define CXWnd__Move_x                                              0x8CC310
#define CXWnd__Move1_x                                             0x8CE8E0
#define CXWnd__ProcessTransition_x                                 0x8C8E70
#define CXWnd__Refade_x                                            0x8C8C40
#define CXWnd__Resize_x                                            0x8C9BC0
#define CXWnd__Right_x                                             0x8CE0B0
#define CXWnd__SetFocus_x                                          0x8CB460
#define CXWnd__SetFont_x                                           0x8C8AF0
#define CXWnd__SetKeyTooltip_x                                     0x8C9E20
#define CXWnd__SetMouseOver_x                                      0x8CE5E0
#define CXWnd__StartFade_x                                         0x8C8F20
#define CXWnd__GetChildItem_x                                      0x8CE520

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C5D80
#define CXWndManager__DrawWindows_x                                0x8C59C0
#define CXWndManager__GetKeyboardFlags_x                           0x8C3FC0
#define CXWndManager__HandleKeyboardMsg_x                          0x8C48E0
#define CXWndManager__RemoveWnd_x                                  0x8C45E0

// CDBStr
#define CDBStr__GetString_x                                        0x4A7450

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E010
#define EQ_Character__Cur_HP_x                                     0x4638D0
#define EQ_Character__GetAACastingTimeModifier_x                   0x445F00
#define EQ_Character__GetCharInfo2_x                               0x871A10
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43DF10
#define EQ_Character__GetFocusRangeModifier_x                      0x43E100
#define EQ_Character__Max_Endurance_x                              0x5C1670
#define EQ_Character__Max_HP_x                                     0x459500
#define EQ_Character__Max_Mana_x                                   0x5C14A0
#define EQ_Character__doCombatAbility_x                            0x5BEAE0
#define EQ_Character__UseSkill_x                                   0x46EDD0
#define EQ_Character__GetConLevel_x                                0x5B3870
#define EQ_Character__IsExpansionFlag_x                            0x422490
#define EQ_Character__TotalEffect_x                                0x44B2B0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x593F60
#define EQ_Item__CreateItemTagString_x                             0x850D60
#define EQ_Item__IsStackable_x                                     0x844F20
#define EQ_Item__GetImageNum_x                                     0x847C00
#define EQ_Item__CreateItemClient_x                                0x594B40
#define EQ_Item__GetItemValue_x                                    0x84FA10
#define EQ_Item__ValueSellMerchant_x                               0x8520C0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C72A0
#define EQ_LoadingS__Array_x                                       0xC1E0A0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C2CC0
#define EQ_PC__GetAlternateAbilityId_x                             0x85A1A0
#define EQ_PC__GetCombatAbility_x                                  0x85A230
#define EQ_PC__GetCombatAbilityTimer_x                             0x855030
#define EQ_PC__GetItemTimerValue_x                                 0x5BC5F0
#define EQ_PC__HasLoreItem_x                                       0x5B6D40
#define EQ_PC__AlertInventoryChanged_x                             0x5B3840
#define EQ_PC__GetPcZoneClient_x                                   0x5DD260
#define EQ_PC__RemoveMyAffect_x                                    0x5BBAB0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50F300
#define EQItemList__add_item_x                                     0x50F240
#define EQItemList__delete_item_x                                  0x50F700
#define EQItemList__FreeItemList_x                                 0x50F600

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A66C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C8230
#define EQPlayer__dEQPlayer_x                                      0x5D10B0
#define EQPlayer__DoAttack_x                                       0x5E3170
#define EQPlayer__EQPlayer_x                                       0x5D34D0
#define EQPlayer__SetNameSpriteState_x                             0x5CDD80
#define EQPlayer__SetNameSpriteTint_x                              0x5C9640
#define EQPlayer__IsBodyType_j_x                                   0x92EF20
#define EQPlayer__IsTargetable_x                                   0x92F820
#define EQPlayer__CanSee_x                                         0x92FD40
#define PlayerZoneClient__ChangeHeight_x                           0x5E3030
#define EQPlayer__CanSeeTargetIndicator_x                          0x92FE30

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D77F0
#define EQPlayerManager__GetSpawnByName_x                          0x5D7C50

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x59A020
#define KeypressHandler__AttachKeyToEqCommand_x                    0x59A060
#define KeypressHandler__ClearCommandStateArray_x                  0x599C00
#define KeypressHandler__HandleKeyDown_x                           0x598560
#define KeypressHandler__HandleKeyUp_x                             0x598880
#define KeypressHandler__SaveKeymapping_x                          0x599CD0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70A900
#define MapViewMap__SaveEx_x                                       0x70E1E0

#define PlayerPointManager__GetAltCurrency_x                       0x86C930

// StringTable 
#define StringTable__getString_x                                   0x867480

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C1120
#define PcZoneClient__RemovePetEffect_x                            0x5BCAE0
#define PcZoneClient__HasAlternateAbility_x                        0x5BD5A0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54DD40

//IconCache
#define IconCache__GetIcon_x                                       0x6A6B10

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69D8F0
#define CContainerMgr__CloseContainer_x                            0x69E110

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76C250

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58D090

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DF190
#define EQ_Spell__SpellAffects_x                                   0x4DF230
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DF260
#define CharacterZoneClient__CalcAffectChange_x                    0x4472F0
#define CLootWnd__LootAll_x                                        0x7001B0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B1CE0
#define CTargetWnd__WndNotification_x                              0x7B17D0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B6EC0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D8A80

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x496C30

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E8AC0
#define CSidlManager__FindAnimation1_x                             0x8DD900

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CE820
#define CAltAbilityData__GetMercMaxRank_x                          0x4CE7D0
#define CAltAbilityData__GetMaxRank_x                              0x4C3860

//CTargetRing
#define CTargetRing__Cast_x                                        0x58A980
