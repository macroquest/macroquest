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
#define __ExpectedVersionDate                                     "Oct 23 2015"
#define __ExpectedVersionTime                                     "04:26:54"
#define __ActualVersionDate_x                                      0xAD52A0
#define __ActualVersionTime_x                                      0xAD52AC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59D160
#define __MemChecker1_x                                            0x89DF10
#define __MemChecker2_x                                            0x636320
#define __MemChecker3_x                                            0x636270
#define __MemChecker4_x                                            0x7EAD60
#define __EncryptPad0_x                                            0xC6E680
#define __EncryptPad1_x                                            0xDF8450
#define __EncryptPad2_x                                            0xCB8168
#define __EncryptPad3_x                                            0xCB7D68
#define __EncryptPad4_x                                            0xDD28F0
#define __EncryptPad5_x                                            0x11A4740
#define __AC1_x                                                    0x7A80C5
#define __AC2_x                                                    0x5527E7
#define __AC3_x                                                    0x566F90
#define __AC4_x                                                    0x56DAD0
#define __AC5_x                                                    0x57996E
#define __AC6_x                                                    0x57D419
#define __AC7_x                                                    0x57401C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data                                                 0x845E8

// Direct Input
#define DI8__Main_x                                                0x11A4718
#define DI8__Keyboard_x                                            0x11A471C
#define DI8__Mouse_x                                               0x11A4720
#define DI8__Mouse_Copy_x                                          0x1012D34
#define DI8__Mouse_Check_x                                         0x109C604
#define __AltTimerReady_x                                          0x1004081
#define __Attack_x                                                 0x10972A3
#define __Autofire_x                                               0x10972A4
#define __BindList_x                                               0xC30758
#define __bCommandEnabled_x                                        0x1002190
#define __Clicks_x                                                 0x1012DF0
#define __CommandList_x                                            0xC34AC8
#define __CurrentMapLabel_x                                        0x11AA170
#define __CurrentSocial_x                                          0xBE8F44
#define __DoAbilityList_x                                          0x1049558
#define __do_loot_x                                                0x519C90
#define __DrawHandler_x                                            0x1810EC4
#define __GroupCount_x                                             0x100375A

#define __Guilds_x                                                 0x1009370
#define __gWorld_x                                                 0x1005C14
#define __HotkeyPage_x                                             0x108FF58
#define __HWnd_x                                                   0x109C620
#define __InChatMode_x                                             0x1012D1C
#define __LastTell_x                                               0x1014C60
#define __LMouseHeldTime_x                                         0x1012E5C
#define __Mouse_x                                                  0x11A4724
#define __MouseLook_x                                              0x1012DB6
#define __MouseEventTime_x                                         0x1097AAC
#define __gpbCommandEvent_x                                        0x1005CDC
#define __NetStatusToggle_x                                        0x1012DB9
#define __PCNames_x                                                0x1014280
#define __RangeAttackReady_x                                       0x1013F40
#define __RMouseHeldTime_x                                         0x1012E58
#define __RunWalkState_x                                           0x1012D20
#define __ScreenMode_x                                             0xF51A40
#define __ScreenX_x                                                0x1012CD4
#define __ScreenY_x                                                0x1012CD0
#define __ScreenXMax_x                                             0x1012CD8
#define __ScreenYMax_x                                             0x1012CDC
#define __ServerHost_x                                             0x10036A4
#define __ServerName_x                                             0x1049518
#define __ShiftKeyDown_x                                           0x10133C4
#define __ShowNames_x                                              0x1014114
#define __Socials_x                                                0x1049618
#define __SubscriptionType_x                                       0x11D86A0
#define __TargetAggroHolder_x                                      0x11AC3AC
#define __GroupAggro_x                                             0x11AC3EC
#define __LoginName_x                                              0x109B1F8
#define __Inviter_x                                                0x1097220


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x1005D00
#define instEQZoneInfo_x                                           0x1012FAC
#define instKeypressHandler_x                                      0x1097A90
#define pinstActiveBanker_x                                        0x1005CB8
#define pinstActiveCorpse_x                                        0x1005CBC
#define pinstActiveGMaster_x                                       0x1005CC0
#define pinstActiveMerchant_x                                      0x1005CB4
#define pinstAggroInfo_x                                           0xE13E38
#define pinstAltAdvManager_x                                       0xF52B40
#define pinstAuraMgr_x                                             0xE1FD08
#define pinstBandageTarget_x                                       0x1005CA0
#define pinstCamActor_x                                            0xF5244C
#define pinstCDBStr_x                                              0xF519D4
#define pinstCDisplay_x                                            0x1005CC8
#define pinstCEverQuest_x                                          0x11A4898
#define pinstCharData_x                                            0x1005C84
#define pinstCharSpawn_x                                           0x1005CAC
#define pinstControlledMissile_x                                   0x1005C80
#define pinstControlledPlayer_x                                    0x1005CAC
#define pinstCSidlManager_x                                        0x18102FC
#define pinstCXWndManager_x                                        0x18102F4
#define instDynamicZone_x                                          0x1012B68
#define pinstDZMember_x                                            0x1012C78
#define pinstDZTimerInfo_x                                         0x1012C7C
#define pinstEQItemList_x                                          0x10023E0
#define instEQMisc_x                                               0xC0B2C0
#define pinstEQSoundManager_x                                      0xF53528
#define instExpeditionLeader_x                                     0x1012BB2
#define instExpeditionName_x                                       0x1012BF2
#define pinstGroup_x                                               0x1003756
#define pinstImeManager_x                                          0x1810300
#define pinstLocalPlayer_x                                         0x1005C98
#define pinstMercenaryData_x                                       0x10980E0
#define pinstMercenaryStats_x                                      0x11AC4F8
#define pinstMercAltAbilities_x                                    0xF52EC8
#define pinstModelPlayer_x                                         0x1005CC4
#define pinstPCData_x                                              0x1005C84
#define pinstSkillMgr_x                                            0x1098F18
#define pinstSpawnManager_x                                        0x1098800
#define pinstSpellManager_x                                        0x1099060
#define pinstSpellSets_x                                           0x108FFBC
#define pinstStringTable_x                                         0x1005C2C
#define pinstSwitchManager_x                                       0x10032E8
#define pinstTarget_x                                              0x1005CB0
#define pinstTargetObject_x                                        0x1005C88
#define pinstTargetSwitch_x                                        0x1005C8C
#define pinstTaskMember_x                                          0xF51920
#define pinstTrackTarget_x                                         0x1005CA4
#define pinstTradeTarget_x                                         0x1005C94
#define instTributeActive_x                                        0xC0B2E5
#define pinstViewActor_x                                           0xF52448
#define pinstWorldData_x                                           0x1005C68
#define pinstZoneAddr_x                                            0x101326C

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE14318
#define pinstCAudioTriggersWindow_x                                0xE141A8
#define pinstCCharacterSelect_x                                    0xF522E0
#define pinstCFacePick_x                                           0xF52290
#define pinstCNoteWnd_x                                            0xF52298
#define pinstCBookWnd_x                                            0xF522A0
#define pinstCPetInfoWnd_x                                         0xF522A4
#define pinstCTrainWnd_x                                           0xF522A8
#define pinstCSkillsWnd_x                                          0xF522AC
#define pinstCSkillsSelectWnd_x                                    0xF522B0
#define pinstCCombatSkillsSelectWnd_x                              0xF522B4
#define pinstCFriendsWnd_x                                         0xF522B8
#define pinstCAuraWnd_x                                            0xF522BC
#define pinstCRespawnWnd_x                                         0xF522C0
#define pinstCBandolierWnd_x                                       0xF522C4
#define pinstCPotionBeltWnd_x                                      0xF522C8
#define pinstCAAWnd_x                                              0xF522CC
#define pinstCGroupSearchFiltersWnd_x                              0xF522D0
#define pinstCLoadskinWnd_x                                        0xF522D4
#define pinstCAlarmWnd_x                                           0xF522D8
#define pinstCMusicPlayerWnd_x                                     0xF522DC
#define pinstCMailWnd_x                                            0xF522E4
#define pinstCMailCompositionWnd_x                                 0xF522E8
#define pinstCMailAddressBookWnd_x                                 0xF522EC
#define pinstCRaidWnd_x                                            0xF522F4
#define pinstCRaidOptionsWnd_x                                     0xF522F8
#define pinstCBreathWnd_x                                          0xF522FC
#define pinstCMapViewWnd_x                                         0xF52300
#define pinstCMapToolbarWnd_x                                      0xF52304
#define pinstCEditLabelWnd_x                                       0xF52308
#define pinstCTargetWnd_x                                          0xF5230C
#define pinstCColorPickerWnd_x                                     0xF52310
#define pinstCPlayerWnd_x                                          0xF52314
#define pinstCOptionsWnd_x                                         0xF52318
#define pinstCBuffWindowNORMAL_x                                   0xF5231C
#define pinstCBuffWindowSHORT_x                                    0xF52320
#define pinstCharacterCreation_x                                   0xF52324
#define pinstCCursorAttachment_x                                   0xF52328
#define pinstCCastingWnd_x                                         0xF5232C
#define pinstCCastSpellWnd_x                                       0xF52330
#define pinstCSpellBookWnd_x                                       0xF52334
#define pinstCInventoryWnd_x                                       0xF52338
#define pinstCBankWnd_x                                            0xF52340
#define pinstCQuantityWnd_x                                        0xF52344
#define pinstCLootWnd_x                                            0xF52348
#define pinstCActionsWnd_x                                         0xF5234C
#define pinstCCombatAbilityWnd_x                                   0xF52350
#define pinstCMerchantWnd_x                                        0xF52354
#define pinstCTradeWnd_x                                           0xF52358
#define pinstCSelectorWnd_x                                        0xF5235C
#define pinstCBazaarWnd_x                                          0xF52360
#define pinstCBazaarSearchWnd_x                                    0xF52364
#define pinstCGiveWnd_x                                            0xF52380
#define pinstCTrackingWnd_x                                        0xF52388
#define pinstCInspectWnd_x                                         0xF5238C
#define pinstCSocialEditWnd_x                                      0xF52390
#define pinstCFeedbackWnd_x                                        0xF52394
#define pinstCBugReportWnd_x                                       0xF52398
#define pinstCVideoModesWnd_x                                      0xF5239C
#define pinstCTextEntryWnd_x                                       0xF523A4
#define pinstCFileSelectionWnd_x                                   0xF523A8
#define pinstCCompassWnd_x                                         0xF523AC
#define pinstCPlayerNotesWnd_x                                     0xF523B0
#define pinstCGemsGameWnd_x                                        0xF523B4
#define pinstCTimeLeftWnd_x                                        0xF523B8
#define pinstCPetitionQWnd_x                                       0xF523D0
#define pinstCSoulmarkWnd_x                                        0xF523D4
#define pinstCStoryWnd_x                                           0xF523D8
#define pinstCJournalTextWnd_x                                     0xF523DC
#define pinstCJournalCatWnd_x                                      0xF523E0
#define pinstCBodyTintWnd_x                                        0xF523E4
#define pinstCServerListWnd_x                                      0xF523E8
#define pinstCAvaZoneWnd_x                                         0xF523F4
#define pinstCBlockedBuffWnd_x                                     0xF523F8
#define pinstCBlockedPetBuffWnd_x                                  0xF523FC
#define pinstCInvSlotMgr_x                                         0xF52440
#define pinstCContainerMgr_x                                       0xF52444
#define pinstCAdventureLeaderboardWnd_x                            0x11A5248
#define pinstCAdventureRequestWnd_x                                0x11A52C0
#define pinstCAltStorageWnd_x                                      0x11A55A0
#define pinstCAdventureStatsWnd_x                                  0x11A5338
#define pinstCBarterMerchantWnd_x                                  0x11A6188
#define pinstCBarterSearchWnd_x                                    0x11A6200
#define pinstCBarterWnd_x                                          0x11A6278
#define pinstCChatManager_x                                        0x11A6908
#define pinstCDynamicZoneWnd_x                                     0x11A6DB8
#define pinstCEQMainWnd_x                                          0x11A6F50
#define pinstCFellowshipWnd_x                                      0x11A6D4C
#define pinstCFindLocationWnd_x                                    0x11A7220
#define pinstCGroupSearchWnd_x                                     0x11A74F0
#define pinstCGroupWnd_x                                           0x11A7568
#define pinstCGuildBankWnd_x                                       0x11A75E0
#define pinstCGuildMgmtWnd_x                                       0x11A96D0
#define pinstCHotButtonWnd_x                                       0x11A979C
#define pinstCHotButtonWnd1_x                                      0x11A979C
#define pinstCHotButtonWnd2_x                                      0x11A97A0
#define pinstCHotButtonWnd3_x                                      0x11A97A4
#define pinstCHotButtonWnd4_x                                      0x11A97C8
#define pinstCItemDisplayManager_x                                 0x11A9AC0
#define pinstCItemExpTransferWnd_x                                 0x11A9B3C
#define pinstCLFGuildWnd_x                                         0x11A9E18
#define pinstCMIZoneSelectWnd_x                                    0x11AA400
#define pinstCConfirmationDialog_x                                 0x11AAB08
#define pinstCPopupWndManager_x                                    0x11AAB08
#define pinstCProgressionSelectionWnd_x                            0x11AABF8
#define pinstCPvPStatsWnd_x                                        0x11AACE8
#define pinstCSystemInfoDialogBox_x                                0x11AB3F0
#define pinstCTaskWnd_x                                            0x11AC7B8
#define pinstCTaskSomething_x                                      0xE204C8
#define pinstCTaskTemplateSelectWnd_x                              0x11AC740
#define pinstCTipWndOFDAY_x                                        0x11ACA10
#define pinstCTipWndCONTEXT_x                                      0x11ACA14
#define pinstCTitleWnd_x                                           0x11ACA90
#define pinstCContextMenuManager_x                                 0x181026C
#define pinstCVoiceMacroWnd_x                                      0x10996C8
#define pinstCHtmlWnd_x                                            0x10997C0
#define pinstIconCache_x                                           0x11A6F24
#define pinstCTradeskillWnd_x                                      0x11ACB90
#define pinstCAdvancedLootWnd_x                                    0xF52434
#define pinstRewardSelectionWnd_x                                  0x11AB210

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5317E0
#define __ConvertItemTags_x                                        0x51E910
#define __ExecuteCmd_x                                             0x509450
#define __EQGetTime_x                                              0x89E270
#define __get_melee_range_x                                        0x5100D0
#define __GetGaugeValueFromEQ_x                                    0x7A6E00
#define __GetLabelFromEQ_x                                         0x7A8050
#define __ToggleMount_x                                            0x47DFA0
#define __GetXTargetType_x                                         0x92F420
#define __LoadFrontEnd_x                                           0x6359D0
#define __NewUIINI_x                                               0x7A6700
#define __ProcessGameEvents_x                                      0x575D80
#define __ProcessMouseEvent_x                                      0x575520
#define CrashDetected_x                                            0x6374A0
#define wwsCrashReportCheckForUploader_x                           0x7FA990
#define DrawNetStatus_x                                            0x5ACC70
#define Util__FastTime_x                                           0x89DBC0
#define Expansion_HoT_x                                            0x10140AC
#define __HelpPath_x                                               0x1097818
#define __STMLToText_x                                             0x8E2BB0

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F010
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419E70

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C50A0
#define AltAdvManager__IsAbilityReady_x                            0x4C5110
#define AltAdvManager__GetAAById_x                                 0x4C54D0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x464140
#define CharacterZoneClient__MakeMeVisible_x                       0x469B20
#define CharacterZoneClient__IsStackBlocked_x                      0x446560

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x665350

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x673150

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58C120
#define CButtonWnd__CButtonWnd_x                                   0x8D6E10

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68E6F0
#define CChatManager__InitContextMenu_x                            0x68F270

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E0F20
#define CContextMenu__dCContextMenu_x                              0x8E1130
#define CContextMenu__AddMenuItem_x                                0x8E1140
#define CContextMenu__RemoveMenuItem_x                             0x8E1420
#define CContextMenu__RemoveAllMenuItems_x                         0x8E1440
#define CContextMenuManager__AddMenu_x                             0x8CCDB0
#define CContextMenuManager__RemoveMenu_x                          0x8CD0F0
#define CContextMenuManager__PopupMenu_x                           0x8CD540
#define CContextMenuManager__Flush_x                               0x8CCE20
#define CContextMenuManager__GetMenu_x                             0x4154A0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x883F90
#define CChatService__GetFriendName_x                              0x883FA0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x694530
#define CChatWindow__Clear_x                                       0x6940E0
#define CChatWindow__WndNotification_x                             0x694A70

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D0CC0
#define CComboWnd__Draw_x                                          0x8D0ED0
#define CComboWnd__GetCurChoice_x                                  0x8D0A90
#define CComboWnd__GetListRect_x                                   0x8D1170
#define CComboWnd__GetTextRect_x                                   0x8D0D30
#define CComboWnd__InsertChoice_x                                  0x8D11E0
#define CComboWnd__SetColors_x                                     0x8D0A20
#define CComboWnd__SetChoice_x                                     0x8D0A50
#define CComboWnd__GetItemCount_x                                  0x8D0A80

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69DC70
#define CContainerWnd__vftable_x                                   0xADEC68

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B31F0
#define CDisplay__GetClickedActor_x                                0x4ABD70
#define CDisplay__GetUserDefinedColor_x                            0x4AA630
#define CDisplay__GetWorldFilePath_x                               0x4A9A80
#define CDisplay__is3dON_x                                         0x4A8E50
#define CDisplay__ReloadUI_x                                       0x4BE770
#define CDisplay__WriteTextHD2_x                                   0x4AF590

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F89B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E5870
#define CEditWnd__GetCharIndexPt_x                                 0x8E68F0
#define CEditWnd__GetDisplayString_x                               0x8E5A20
#define CEditWnd__GetHorzOffset_x                                  0x8E5D60
#define CEditWnd__GetLineForPrintableChar_x                        0x8E63C0
#define CEditWnd__GetSelStartPt_x                                  0x8E6BA0
#define CEditWnd__GetSTMLSafeText_x                                0x8E5EF0
#define CEditWnd__PointFromPrintableChar_x                         0x8E64B0
#define CEditWnd__SelectableCharFromPoint_x                        0x8E6630
#define CEditWnd__SetEditable_x                                    0x8E5EC0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x552F30
#define CEverQuest__DoTellWindow_x                                 0x558920
#define CEverQuest__DropHeldItemOnGround_x                         0x561410
#define CEverQuest__dsp_chat_x                                     0x55A0C0
#define CEverQuest__Emote_x                                        0x55A320
#define CEverQuest__EnterZone_x                                    0x56E300
#define CEverQuest__GetBodyTypeDesc_x                              0x54F790
#define CEverQuest__GetClassDesc_x                                 0x5554A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x555AA0
#define CEverQuest__GetDeityDesc_x                                 0x550070
#define CEverQuest__GetLangDesc_x                                  0x54FB20
#define CEverQuest__GetRaceDesc_x                                  0x555C60
#define CEverQuest__InterpretCmd_x                                 0x55AC00
#define CEverQuest__LeftClickedOnPlayer_x                          0x572480
#define CEverQuest__LMouseUp_x                                     0x574570
#define CEverQuest__RightClickedOnPlayer_x                         0x572F80
#define CEverQuest__RMouseUp_x                                     0x573FD0
#define CEverQuest__SetGameState_x                                 0x5535E0
#define CEverQuest__UPCNotificationFlush_x                         0x55BD60
#define CEverQuest__IssuePetCommand_x                              0x55B8C0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AE840
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AE8A0
#define CGaugeWnd__Draw_x                                          0x6AECD0

// CGuild
#define CGuild__FindMemberByName_x                                 0x435F90

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CB950

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D8160
#define CInvSlotMgr__MoveItem_x                                    0x6D90A0
#define CInvSlotMgr__SelectSlot_x                                  0x6D8210

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D75F0
#define CInvSlot__SliderComplete_x                                 0x6D4DD0
#define CInvSlot__GetItemBase_x                                    0x6D4220

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DA4C0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A3790
#define CItemDisplayWnd__UpdateStrings_x                           0x6DB7F0

// CLabel 
#define CLabel__Draw_x                                             0x6F6700

// CListWnd
#define CListWnd__CListWnd_x                                       0x8BCA00
#define CListWnd__dCListWnd_x                                      0x8BDA20
#define CListWnd__AddColumn_x                                      0x8BD9C0
#define CListWnd__AddColumn1_x                                     0x8BD230
#define CListWnd__AddLine_x                                        0x8BCCB0
#define CListWnd__AddString_x                                      0x8BCEC0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B9D40
#define CListWnd__CalculateVSBRange_x                              0x8BBEB0
#define CListWnd__ClearAllSel_x                                    0x8B9000
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BC890
#define CListWnd__Compare_x                                        0x8BA840
#define CListWnd__Draw_x                                           0x8BBAC0
#define CListWnd__DrawColumnSeparators_x                           0x8BB950
#define CListWnd__DrawHeader_x                                     0x8B9310
#define CListWnd__DrawItem_x                                       0x8BAE90
#define CListWnd__DrawLine_x                                       0x8BB5F0
#define CListWnd__DrawSeparator_x                                  0x8BB9F0
#define CListWnd__EnsureVisible_x                                  0x8B9EA0
#define CListWnd__ExtendSel_x                                      0x8BADA0
#define CListWnd__GetColumnMinWidth_x                              0x8B89C0
#define CListWnd__GetColumnWidth_x                                 0x8B88E0
#define CListWnd__GetCurSel_x                                      0x8B80C0
#define CListWnd__GetItemAtPoint_x                                 0x8BA130
#define CListWnd__GetItemAtPoint1_x                                0x8BA1A0
#define CListWnd__GetItemData_x                                    0x8B8400
#define CListWnd__GetItemHeight_x                                  0x8B99A0
#define CListWnd__GetItemIcon_x                                    0x8B85E0
#define CListWnd__GetItemRect_x                                    0x8B9F70
#define CListWnd__GetItemText_x                                    0x8B8490
#define CListWnd__GetSelList_x                                     0x8BD120
#define CListWnd__GetSeparatorRect_x                               0x8BA760
#define CListWnd__RemoveLine_x                                     0x8BD0A0
#define CListWnd__SetColors_x                                      0x8B8210
#define CListWnd__SetColumnJustification_x                         0x8B8C90
#define CListWnd__SetColumnWidth_x                                 0x8B8970
#define CListWnd__SetCurSel_x                                      0x8B8100
#define CListWnd__SetItemColor_x                                   0x8BC570
#define CListWnd__SetItemData_x                                    0x8B90B0
#define CListWnd__SetItemText_x                                    0x8BC3B0
#define CListWnd__ShiftColumnSeparator_x                           0x8BC240
#define CListWnd__Sort_x                                           0x8BDB20
#define CListWnd__ToggleSel_x                                      0x8B8F80

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70FD80

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x730F70
#define CMerchantWnd__RequestBuyItem_x                             0x737DD0
#define CMerchantWnd__RequestSellItem_x                            0x738840
#define CMerchantWnd__SelectRecoverySlot_x                         0x731220
#define CMerchantWnd__SelectBuySellSlot_x                          0x730480
#define CMerchantWnd__ActualSelect_x                               0x734CF0

// CObfuscator
#define CObfuscator__doit_x                                        0x864380

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8DBE20
#define CSidlManager__CreateLabel_x                                0x7997C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65C670
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65C590
#define CSidlScreenWnd__ConvertToRes_x                             0x8F8890
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D3960
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D4E60
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D4F10
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D43E0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D3310
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D2A40
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D3500
#define CSidlScreenWnd__Init1_x                                    0x8D4B40
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D3A10
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D2C00
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D4630
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D2500
#define CSidlScreenWnd__StoreIniVis_x                              0x8D29D0
#define CSidlScreenWnd__WndNotification_x                          0x8D48C0
#define CSidlScreenWnd__GetChildItem_x                             0x8D2B10
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C6010

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F7960
#define CSkillMgr__GetSkillCap_x                                   0x5F7B20
#define CSkillMgr__GetNameToken_x                                  0x5F7580

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8F7B60
#define CSliderWnd__SetValue_x                                     0x8F7D30
#define CSliderWnd__SetNumTicks_x                                  0x8F84B0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A1440

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F2540
#define CStmlWnd__CalculateHSBRange_x                              0x8EAA70
#define CStmlWnd__CalculateVSBRange_x                              0x8EAB00
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EAC80
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EB560
#define CStmlWnd__ForceParseNow_x                                  0x8F2E90
#define CStmlWnd__GetNextTagPiece_x                                0x8EB460
#define CStmlWnd__GetSTMLText_x                                    0x693970
#define CStmlWnd__GetVisibleText_x                                 0x8EBFB0
#define CStmlWnd__InitializeWindowVariables_x                      0x8EE340
#define CStmlWnd__MakeStmlColorTag_x                               0x8E9D70
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E9DD0
#define CStmlWnd__SetSTMLText_x                                    0x8EFBB0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F21E0
#define CStmlWnd__UpdateHistoryString_x                            0x8ECEF0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E9410
#define CTabWnd__DrawCurrentPage_x                                 0x8E8C80
#define CTabWnd__DrawTab_x                                         0x8E8A50
#define CTabWnd__GetCurrentPage_x                                  0x8E9050
#define CTabWnd__GetPageInnerRect_x                                0x8E8740
#define CTabWnd__GetTabInnerRect_x                                 0x8E8940
#define CTabWnd__GetTabRect_x                                      0x8E8810
#define CTabWnd__InsertPage_x                                      0x8E9700
#define CTabWnd__SetPage_x                                         0x8E9080
#define CTabWnd__SetPageRect_x                                     0x8E9350
#define CTabWnd__UpdatePage_x                                      0x8E96A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431D80

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D0680

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8FDD10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B6110

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4022B0
#define CXStr__CXStr1_x                                            0x7D7C80
#define CXStr__CXStr3_x                                            0x89AC50
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x89ADC0
#define CXStr__operator_equal1_x                                   0x89AE10
#define CXStr__operator_plus_equal1_x                              0x89BEF0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C5230
#define CXWnd__Center_x                                            0x8CB3F0
#define CXWnd__ClrFocus_x                                          0x8C4E00
#define CXWnd__DoAllDrawing_x                                      0x8CB040
#define CXWnd__DrawChildren_x                                      0x8CB1E0
#define CXWnd__DrawColoredRect_x                                   0x8C55D0
#define CXWnd__DrawTooltip_x                                       0x8C5880
#define CXWnd__DrawTooltipAtPoint_x                                0x8C9FB0
#define CXWnd__GetBorderFrame_x                                    0x8C5CE0
#define CXWnd__GetChildWndAt_x                                     0x8CBD90
#define CXWnd__GetClientClipRect_x                                 0x8C5AA0
#define CXWnd__GetScreenClipRect_x                                 0x8CA6A0
#define CXWnd__GetScreenRect_x                                     0x8C5EA0
#define CXWnd__GetTooltipRect_x                                    0x8C5710
#define CXWnd__GetWindowTextA_x                                    0x4230A0
#define CXWnd__IsActive_x                                          0x8C0800
#define CXWnd__IsDescendantOf_x                                    0x8C5C30
#define CXWnd__IsReallyVisible_x                                   0x8C8FE0
#define CXWnd__IsType_x                                            0x8FA4F0
#define CXWnd__Move_x                                              0x8C86B0
#define CXWnd__Move1_x                                             0x8CACF0
#define CXWnd__ProcessTransition_x                                 0x8C51D0
#define CXWnd__Refade_x                                            0x8C4FA0
#define CXWnd__Resize_x                                            0x8C5F70
#define CXWnd__Right_x                                             0x8CA4A0
#define CXWnd__SetFocus_x                                          0x8C7820
#define CXWnd__SetFont_x                                           0x8C4E50
#define CXWnd__SetKeyTooltip_x                                     0x8C61E0
#define CXWnd__SetMouseOver_x                                      0x8CA9E0
#define CXWnd__StartFade_x                                         0x8C5280
#define CXWnd__GetChildItem_x                                      0x8CA920

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C2120
#define CXWndManager__DrawWindows_x                                0x8C1D60
#define CXWndManager__GetKeyboardFlags_x                           0x8C0330
#define CXWndManager__HandleKeyboardMsg_x                          0x8C0C90
#define CXWndManager__RemoveWnd_x                                  0x8C0990

// CDBStr
#define CDBStr__GetString_x                                        0x4A7390

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E1E0
#define EQ_Character__Cur_HP_x                                     0x463810
#define EQ_Character__GetAACastingTimeModifier_x                   0x4460E0
#define EQ_Character__GetCharInfo2_x                               0x86EBB0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43E110
#define EQ_Character__GetFocusRangeModifier_x                      0x43E300
#define EQ_Character__Max_Endurance_x                              0x5BF060
#define EQ_Character__Max_HP_x                                     0x459440
#define EQ_Character__Max_Mana_x                                   0x5BEE90
#define EQ_Character__doCombatAbility_x                            0x5BC4E0
#define EQ_Character__UseSkill_x                                   0x46ED10
#define EQ_Character__GetConLevel_x                                0x5B1270
#define EQ_Character__IsExpansionFlag_x                            0x4225E0
#define EQ_Character__TotalEffect_x                                0x44B480

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x591A10
#define EQ_Item__CreateItemTagString_x                             0x84DF20
#define EQ_Item__IsStackable_x                                     0x842480
#define EQ_Item__GetImageNum_x                                     0x845180
#define EQ_Item__CreateItemClient_x                                0x592600
#define EQ_Item__GetItemValue_x                                    0x84CBF0
#define EQ_Item__ValueSellMerchant_x                               0x84F230

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C71E0
#define EQ_LoadingS__Array_x                                       0xC19098

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C06B0
#define EQ_PC__GetAlternateAbilityId_x                             0x857360
#define EQ_PC__GetCombatAbility_x                                  0x8573F0
#define EQ_PC__GetCombatAbilityTimer_x                             0x852190
#define EQ_PC__GetItemTimerValue_x                                 0x5BA070
#define EQ_PC__HasLoreItem_x                                       0x5B4750
#define EQ_PC__AlertInventoryChanged_x                             0x5B1240
#define EQ_PC__GetPcZoneClient_x                                   0x5DACD0
#define EQ_PC__RemoveMyAffect_x									   0x5B9530

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50E130
#define EQItemList__add_item_x                                     0x50E070
#define EQItemList__delete_item_x                                  0x50E530
#define EQItemList__FreeItemList_x                                 0x50E430

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A65C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C5C40
#define EQPlayer__dEQPlayer_x                                      0x5CEAC0
#define EQPlayer__DoAttack_x                                       0x5E0BE0
#define EQPlayer__EQPlayer_x                                       0x5D0EE0
#define EQPlayer__SetNameSpriteState_x                             0x5CB790
#define EQPlayer__SetNameSpriteTint_x                              0x5C7050
#define EQPlayer__IsBodyType_j_x                                   0x92B5F0
#define EQPlayer__IsTargetable_x                                   0x92BEF0
#define EQPlayer__CanSee_x                                         0x92C410
#define PlayerZoneClient__ChangeHeight_x                           0x5E0AA0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D51F0
#define EQPlayerManager__GetSpawnByName_x                          0x5D5650

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x597B00
#define KeypressHandler__AttachKeyToEqCommand_x                    0x597B40
#define KeypressHandler__ClearCommandStateArray_x                  0x5976E0
#define KeypressHandler__HandleKeyDown_x                           0x596040
#define KeypressHandler__HandleKeyUp_x                             0x596360
#define KeypressHandler__SaveKeymapping_x                          0x5977B0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x708160
#define MapViewMap__SaveEx_x                                       0x70BA40

#define PlayerPointManager__GetAltCurrency_x                       0x869B50

// StringTable 
#define StringTable__getString_x                                   0x864620

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BEB10
#define PcZoneClient__RemovePetEffect_x                            0x5BA4E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x54CB20

//IconCache
#define IconCache__GetIcon_x                                       0x6A4190

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69AF80
#define CContainerMgr__CloseContainer_x                            0x69B7A0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x769950

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58ABC0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DD3E0
#define EQ_Spell__SpellAffects_x                                   0x4DD480
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DD4B0
#define CharacterZoneClient__CalcAffectChange_x                    0x4474D0
#define CLootWnd__LootAll_x                                        0x6FDA90

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AF410
#define CTargetWnd__WndNotification_x                              0x7AEF00

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B45F0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D6C30

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x496940

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E4E90
#define CSidlManager__FindAnimation1_x                             0x8D9D10

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CE800
#define CAltAbilityData__GetMercMaxRank_x                          0x4CE7B0
#define CAltAbilityData__GetMaxRank_x                              0x4C3740
