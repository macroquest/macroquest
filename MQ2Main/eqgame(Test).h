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
#define __ExpectedVersionDate                                     "Nov 25 2015"
#define __ExpectedVersionTime                                     "11:29:06"
#define __ActualVersionDate_x                                      0xAD94E8
#define __ActualVersionTime_x                                      0xAD94F4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59F420
#define __MemChecker1_x                                            0x8A0D00
#define __MemChecker2_x                                            0x6384E0
#define __MemChecker3_x                                            0x638430
#define __MemChecker4_x                                            0x7ECB60
#define __EncryptPad0_x                                            0xC74D10
#define __EncryptPad1_x                                            0xDFFE98
#define __EncryptPad2_x                                            0xCBE7F8
#define __EncryptPad3_x                                            0xCBE3F8
#define __EncryptPad4_x                                            0xDD8F80
#define __EncryptPad5_x                                            0x11ABD08
#define __AC1_x                                                    0x7AA2B5
#define __AC2_x                                                    0x5536B7
#define __AC3_x                                                    0x568280
#define __AC4_x                                                    0x56EF00
#define __AC5_x                                                    0x57B6BE
#define __AC6_x                                                    0x57F269
#define __AC7_x                                                    0x575D6C
#define __AC1_Data                                                 0x11111111
#define __EP1_Data_x                                               0x1FB65C

// Direct Input
#define DI8__Main_x                                                0x11ABCE0
#define DI8__Keyboard_x                                            0x11ABCE4
#define DI8__Mouse_x                                               0x11ABCE8
#define DI8__Mouse_Copy_x                                          0x101A2F4
#define DI8__Mouse_Check_x                                         0x10A3BCC
#define __AltTimerReady_x                                          0x100B641
#define __Attack_x                                                 0x109E86F
#define __Autofire_x                                               0x109E870
#define __BindList_x                                               0xC36DE0
#define __bCommandEnabled_x                                        0x1009750
#define __Clicks_x                                                 0x101A3B0
#define __CommandList_x                                            0xC3B150
#define __CurrentMapLabel_x                                        0x11B1738
#define __CurrentSocial_x                                          0xBEDF44
#define __DoAbilityList_x                                          0x1050B24
#define __do_loot_x                                                0x51ABD0
#define __DrawHandler_x                                            0x18184EC
#define __GroupCount_x                                             0x100AD1A

#define __Guilds_x                                                 0x1010930
#define __gWorld_x                                                 0x100D1D4
#define __HotkeyPage_x                                             0x1097524
#define __HWnd_x                                                   0x10A3BE8
#define __InChatMode_x                                             0x101A2DC
#define __LastTell_x                                               0x101C220
#define __LMouseHeldTime_x                                         0x101A41C
#define __Mouse_x                                                  0x11ABCEC
#define __MouseLook_x                                              0x101A376
#define __MouseEventTime_x                                         0x109F074
#define __gpbCommandEvent_x                                        0x100D29C
#define __NetStatusToggle_x                                        0x101A379
#define __PCNames_x                                                0x101B840
#define __RangeAttackReady_x                                       0x101B500
#define __RMouseHeldTime_x                                         0x101A418
#define __RunWalkState_x                                           0x101A2E0
#define __ScreenMode_x                                             0xF59480
#define __ScreenX_x                                                0x101A294
#define __ScreenY_x                                                0x101A290
#define __ScreenXMax_x                                             0x101A298
#define __ScreenYMax_x                                             0x101A29C
#define __ServerHost_x                                             0x100AC64
#define __ServerName_x                                             0x1050AE4
#define __ShiftKeyDown_x                                           0x101A984
#define __ShowNames_x                                              0x101B6D4
#define __Socials_x                                                0x1050BE4
#define __SubscriptionType_x                                       0x11DFC68
#define __TargetAggroHolder_x                                      0x11B3974
#define __GroupAggro_x                                             0x11B39B4
#define __LoginName_x                                              0x10A27C0
#define __Inviter_x                                                0x109E7EC


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0x100D2C0
#define instEQZoneInfo_x                                           0x101A56C
#define instKeypressHandler_x                                      0x109F058
#define pinstActiveBanker_x                                        0x100D278
#define pinstActiveCorpse_x                                        0x100D27C
#define pinstActiveGMaster_x                                       0x100D280
#define pinstActiveMerchant_x                                      0x100D274
#define pinstAggroInfo_x                                           0xE1B878
#define pinstAltAdvManager_x                                       0xF5A588
#define pinstAuraMgr_x                                             0xE27748
#define pinstBandageTarget_x                                       0x100D260
#define pinstCamActor_x                                            0xF59E90
#define pinstCDBStr_x                                              0xF59414
#define pinstCDisplay_x                                            0x100D288
#define pinstCEverQuest_x                                          0x11ABE60
#define pinstCharData_x                                            0x100D244
#define pinstCharSpawn_x                                           0x100D26C
#define pinstControlledMissile_x                                   0x100D240
#define pinstControlledPlayer_x                                    0x100D26C
#define pinstCSidlManager_x                                        0x1817924
#define pinstCXWndManager_x                                        0x181791C
#define instDynamicZone_x                                          0x101A128
#define pinstDZMember_x                                            0x101A238
#define pinstDZTimerInfo_x                                         0x101A23C
#define pinstEQItemList_x                                          0x10099A0
#define instEQMisc_x                                               0xC102D0
#define pinstEQSoundManager_x                                      0xF5AAE8
#define instExpeditionLeader_x                                     0x101A172
#define instExpeditionName_x                                       0x101A1B2
#define pinstGroup_x                                               0x100AD16
#define pinstImeManager_x                                          0x1817928
#define pinstLocalPlayer_x                                         0x100D258
#define pinstMercenaryData_x                                       0x109F6A8
#define pinstMercenaryStats_x                                      0x11B3AC0
#define pinstMercAltAbilities_x                                    0xF5A914
#define pinstModelPlayer_x                                         0x100D284
#define pinstPCData_x                                              0x100D244
#define pinstSkillMgr_x                                            0x10A04E0
#define pinstSpawnManager_x                                        0x109FDC8
#define pinstSpellManager_x                                        0x10A0628
#define pinstSpellSets_x                                           0x1097588
#define pinstStringTable_x                                         0x100D1EC
#define pinstSwitchManager_x                                       0x100A8A8
#define pinstTarget_x                                              0x100D270
#define pinstTargetObject_x                                        0x100D248
#define pinstTargetSwitch_x                                        0x100D24C
#define pinstTaskMember_x                                          0xF59360
#define pinstTrackTarget_x                                         0x100D264
#define pinstTradeTarget_x                                         0x100D254
#define instTributeActive_x                                        0xC102F5
#define pinstViewActor_x                                           0xF59E8C
#define pinstWorldData_x                                           0x100D228
#define pinstZoneAddr_x                                            0x101A82C
#define pinstPlayerPath_x                                          0x109BF48
#define pinstTargetIndicator_x                                     0x109C8E0
#define pinstCTargetManager_x                                      0x10A0820

//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE1BD58
#define pinstCAudioTriggersWindow_x                                0xE1BBE8
#define pinstCCharacterSelect_x                                    0xF59D20
#define pinstCFacePick_x                                           0xF59CD0
#define pinstCNoteWnd_x                                            0xF59CD8
#define pinstCBookWnd_x                                            0xF59CE0
#define pinstCPetInfoWnd_x                                         0xF59CE4
#define pinstCTrainWnd_x                                           0xF59CE8
#define pinstCSkillsWnd_x                                          0xF59CEC
#define pinstCSkillsSelectWnd_x                                    0xF59CF0
#define pinstCCombatSkillsSelectWnd_x                              0xF59CF4
#define pinstCFriendsWnd_x                                         0xF59CF8
#define pinstCAuraWnd_x                                            0xF59CFC
#define pinstCRespawnWnd_x                                         0xF59D00
#define pinstCBandolierWnd_x                                       0xF59D04
#define pinstCPotionBeltWnd_x                                      0xF59D08
#define pinstCAAWnd_x                                              0xF59D0C
#define pinstCGroupSearchFiltersWnd_x                              0xF59D10
#define pinstCLoadskinWnd_x                                        0xF59D14
#define pinstCAlarmWnd_x                                           0xF59D18
#define pinstCMusicPlayerWnd_x                                     0xF59D1C
#define pinstCMailWnd_x                                            0xF59D24
#define pinstCMailCompositionWnd_x                                 0xF59D28
#define pinstCMailAddressBookWnd_x                                 0xF59D2C
#define pinstCRaidWnd_x                                            0xF59D34
#define pinstCRaidOptionsWnd_x                                     0xF59D38
#define pinstCBreathWnd_x                                          0xF59D3C
#define pinstCMapViewWnd_x                                         0xF59D40
#define pinstCMapToolbarWnd_x                                      0xF59D44
#define pinstCEditLabelWnd_x                                       0xF59D48
#define pinstCTargetWnd_x                                          0xF59D4C
#define pinstCColorPickerWnd_x                                     0xF59D50
#define pinstCPlayerWnd_x                                          0xF59D54
#define pinstCOptionsWnd_x                                         0xF59D58
#define pinstCBuffWindowNORMAL_x                                   0xF59D5C
#define pinstCBuffWindowSHORT_x                                    0xF59D60
#define pinstCharacterCreation_x                                   0xF59D64
#define pinstCCursorAttachment_x                                   0xF59D68
#define pinstCCastingWnd_x                                         0xF59D6C
#define pinstCCastSpellWnd_x                                       0xF59D70
#define pinstCSpellBookWnd_x                                       0xF59D74
#define pinstCInventoryWnd_x                                       0xF59D78
#define pinstCBankWnd_x                                            0xF59D80
#define pinstCQuantityWnd_x                                        0xF59D84
#define pinstCLootWnd_x                                            0xF59D88
#define pinstCActionsWnd_x                                         0xF59D8C
#define pinstCCombatAbilityWnd_x                                   0xF59D90
#define pinstCMerchantWnd_x                                        0xF59D94
#define pinstCTradeWnd_x                                           0xF59D98
#define pinstCSelectorWnd_x                                        0xF59D9C
#define pinstCBazaarWnd_x                                          0xF59DA0
#define pinstCBazaarSearchWnd_x                                    0xF59DA4
#define pinstCGiveWnd_x                                            0xF59DC0
#define pinstCTrackingWnd_x                                        0xF59DC8
#define pinstCInspectWnd_x                                         0xF59DCC
#define pinstCSocialEditWnd_x                                      0xF59DD0
#define pinstCFeedbackWnd_x                                        0xF59DD4
#define pinstCBugReportWnd_x                                       0xF59DD8
#define pinstCVideoModesWnd_x                                      0xF59DDC
#define pinstCTextEntryWnd_x                                       0xF59DE4
#define pinstCFileSelectionWnd_x                                   0xF59DE8
#define pinstCCompassWnd_x                                         0xF59DEC
#define pinstCPlayerNotesWnd_x                                     0xF59DF0
#define pinstCGemsGameWnd_x                                        0xF59DF4
#define pinstCTimeLeftWnd_x                                        0xF59DF8
#define pinstCPetitionQWnd_x                                       0xF59E14
#define pinstCSoulmarkWnd_x                                        0xF59E18
#define pinstCStoryWnd_x                                           0xF59E1C
#define pinstCJournalTextWnd_x                                     0xF59E20
#define pinstCJournalCatWnd_x                                      0xF59E24
#define pinstCBodyTintWnd_x                                        0xF59E28
#define pinstCServerListWnd_x                                      0xF59E2C
#define pinstCAvaZoneWnd_x                                         0xF59E38
#define pinstCBlockedBuffWnd_x                                     0xF59E3C
#define pinstCBlockedPetBuffWnd_x                                  0xF59E40
#define pinstCInvSlotMgr_x                                         0xF59E84
#define pinstCContainerMgr_x                                       0xF59E88
#define pinstCAdventureLeaderboardWnd_x                            0x11AC810
#define pinstCAdventureRequestWnd_x                                0x11AC888
#define pinstCAltStorageWnd_x                                      0x11ACB68
#define pinstCAdventureStatsWnd_x                                  0x11AC900
#define pinstCBarterMerchantWnd_x                                  0x11AD750
#define pinstCBarterSearchWnd_x                                    0x11AD7C8
#define pinstCBarterWnd_x                                          0x11AD840
#define pinstCChatManager_x                                        0x11ADED0
#define pinstCDynamicZoneWnd_x                                     0x11AE380
#define pinstCEQMainWnd_x                                          0x11AE518
#define pinstCFellowshipWnd_x                                      0x11AE314
#define pinstCFindLocationWnd_x                                    0x11AE7E8
#define pinstCGroupSearchWnd_x                                     0x11AEAB8
#define pinstCGroupWnd_x                                           0x11AEB30
#define pinstCGuildBankWnd_x                                       0x11AEBA8
#define pinstCGuildMgmtWnd_x                                       0x11B0C98
#define pinstCHotButtonWnd_x                                       0x11B0D64
#define pinstCHotButtonWnd1_x                                      0x11B0D64
#define pinstCHotButtonWnd2_x                                      0x11B0D68
#define pinstCHotButtonWnd3_x                                      0x11B0D6C
#define pinstCHotButtonWnd4_x                                      0x11B0D90
#define pinstCItemDisplayManager_x                                 0x11B1088
#define pinstCItemExpTransferWnd_x                                 0x11B1104
#define pinstCLFGuildWnd_x                                         0x11B13E0
#define pinstCMIZoneSelectWnd_x                                    0x11B19C8
#define pinstCConfirmationDialog_x                                 0x11B20D0
#define pinstCPopupWndManager_x                                    0x11B20D0
#define pinstCProgressionSelectionWnd_x                            0x11B21C0
#define pinstCPvPStatsWnd_x                                        0x11B22B0
#define pinstCSystemInfoDialogBox_x                                0x11B29B8
#define pinstCTaskWnd_x                                            0x11B3D80
#define pinstCTaskSomething_x                                      0xE27F08
#define pinstCTaskTemplateSelectWnd_x                              0x11B3D08
#define pinstCTipWndOFDAY_x                                        0x11B3FD8
#define pinstCTipWndCONTEXT_x                                      0x11B3FDC
#define pinstCTitleWnd_x                                           0x11B4058
#define pinstCContextMenuManager_x                                 0x1817894
#define pinstCVoiceMacroWnd_x                                      0x10A0C90
#define pinstCHtmlWnd_x                                            0x10A0D88
#define pinstIconCache_x                                           0x11AE4EC
#define pinstCTradeskillWnd_x                                      0x11B4158
#define pinstCAdvancedLootWnd_x                                    0xF59E78
#define pinstRewardSelectionWnd_x                                  0x11B27D8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x532720
#define __ConvertItemTags_x                                        0x51F850
#define __ExecuteCmd_x                                             0x50A3A0
#define __EQGetTime_x                                              0x8A1060
#define __get_melee_range_x                                        0x511010
#define __GetGaugeValueFromEQ_x                                    0x7A8FF0
#define __GetLabelFromEQ_x                                         0x7AA240
#define __ToggleKeyRingItem_x                                      0x47E3B0
#define __GetXTargetType_x                                         0x932900
#define __LoadFrontEnd_x                                           0x637B90
#define __NewUIINI_x                                               0x7A88F0
#define __ProcessGameEvents_x                                      0x577AD0
#define __ProcessMouseEvent_x                                      0x577270
#define CrashDetected_x                                            0x639660
#define wwsCrashReportCheckForUploader_x                           0x7FC700
#define DrawNetStatus_x                                            0x5AEF40
#define Util__FastTime_x                                           0x8A09B0
#define Expansion_HoT_x                                            0x101B66C
#define __HelpPath_x                                               0x109EDE0
#define __STMLToText_x                                             0x8E6280

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F040
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419EA0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C55E0
#define AltAdvManager__IsAbilityReady_x                            0x4C5650
#define AltAdvManager__GetAAById_x                                 0x4C5A10
#define AltAdvManager__CanTrainAbility_x                           0x4C62D0
#define AltAdvManager__CanSeeAbility_x                             0x4C5ED0


// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x464430
#define CharacterZoneClient__MakeMeVisible_x                       0x469E10
#define CharacterZoneClient__IsStackBlocked_x                      0x446570

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x667650

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x675D30

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x58E290
#define CButtonWnd__CButtonWnd_x                                   0x8DA410

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6909B0
#define CChatManager__InitContextMenu_x                            0x691530

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8E45E0
#define CContextMenu__dCContextMenu_x                              0x8E47F0
#define CContextMenu__AddMenuItem_x                                0x8E4800
#define CContextMenu__RemoveMenuItem_x                             0x8E4AF0
#define CContextMenu__RemoveAllMenuItems_x                         0x8E4B10
#define CContextMenuManager__AddMenu_x                             0x8D03A0
#define CContextMenuManager__RemoveMenu_x                          0x8D06D0
#define CContextMenuManager__PopupMenu_x                           0x8D0B20
#define CContextMenuManager__Flush_x                               0x8D0410
#define CContextMenuManager__GetMenu_x                             0x4154F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8860B0
#define CChatService__GetFriendName_x                              0x8860C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6967F0
#define CChatWindow__Clear_x                                       0x6963A0
#define CChatWindow__WndNotification_x                             0x696D20

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8D4290
#define CComboWnd__Draw_x                                          0x8D44A0
#define CComboWnd__GetCurChoice_x                                  0x8D4060
#define CComboWnd__GetListRect_x                                   0x8D4740
#define CComboWnd__GetTextRect_x                                   0x8D4300
#define CComboWnd__InsertChoice_x                                  0x8D47B0
#define CComboWnd__SetColors_x                                     0x8D3FF0
#define CComboWnd__SetChoice_x                                     0x8D4020
#define CComboWnd__GetItemCount_x                                  0x8D4050

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69FF90
#define CContainerWnd__vftable_x                                   0xAE2ED0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B3730
#define CDisplay__GetClickedActor_x                                0x4AC270
#define CDisplay__GetUserDefinedColor_x                            0x4AAB30
#define CDisplay__GetWorldFilePath_x                               0x4A9F80
#define CDisplay__is3dON_x                                         0x4A9350
#define CDisplay__ReloadUI_x                                       0x4BED00
#define CDisplay__WriteTextHD2_x                                   0x4AFA90

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8FC0E0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8E8F30
#define CEditWnd__GetCharIndexPt_x                                 0x8E9FC0
#define CEditWnd__GetDisplayString_x                               0x8E90E0
#define CEditWnd__GetHorzOffset_x                                  0x8E9420
#define CEditWnd__GetLineForPrintableChar_x                        0x8E9A90
#define CEditWnd__GetSelStartPt_x                                  0x8EA270
#define CEditWnd__GetSTMLSafeText_x                                0x8E95C0
#define CEditWnd__PointFromPrintableChar_x                         0x8E9B80
#define CEditWnd__SelectableCharFromPoint_x                        0x8E9D00
#define CEditWnd__SetEditable_x                                    0x8E9590

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x553E00
#define CEverQuest__CreateTargetIndicator_x                        0x554A30
#define CEverQuest__DeleteTargetIndicator_x                        0x554AB0
#define CEverQuest__DoTellWindow_x                                 0x559800
#define CEverQuest__DropHeldItemOnGround_x                         0x562700
#define CEverQuest__dsp_chat_x                                     0x55B1B0
#define CEverQuest__Emote_x                                        0x55B410
#define CEverQuest__EnterZone_x                                    0x56F850
#define CEverQuest__GetBodyTypeDesc_x                              0x550660
#define CEverQuest__GetClassDesc_x                                 0x556370
#define CEverQuest__GetClassThreeLetterCode_x                      0x556970
#define CEverQuest__GetDeityDesc_x                                 0x550F40
#define CEverQuest__GetLangDesc_x                                  0x5509F0
#define CEverQuest__GetRaceDesc_x                                  0x556B30
#define CEverQuest__InterpretCmd_x                                 0x55BCF0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5741D0
#define CEverQuest__LMouseUp_x                                     0x5762C0
#define CEverQuest__RightClickedOnPlayer_x                         0x574CD0
#define CEverQuest__RMouseUp_x                                     0x575D20
#define CEverQuest__SetGameState_x                                 0x5544B0
#define CEverQuest__UPCNotificationFlush_x                         0x55D050
#define CEverQuest__IssuePetCommand_x                              0x55C9B0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6B0B90
#define CGaugeWnd__CalcLinesFillRect_x                             0x6B0BF0
#define CGaugeWnd__Draw_x                                          0x6B1020

// CGuild
#define CGuild__FindMemberByName_x                                 0x435FA0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6CDC20

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6DA3B0
#define CInvSlotMgr__MoveItem_x                                    0x6DB2F0
#define CInvSlotMgr__SelectSlot_x                                  0x6DA460

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D9840
#define CInvSlot__SliderComplete_x                                 0x6D7070
#define CInvSlot__GetItemBase_x                                    0x6D64C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6DC6F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A59A0
#define CItemDisplayWnd__UpdateStrings_x                           0x6DDA20

// CLabel 
#define CLabel__Draw_x                                             0x6F88F0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8C0040
#define CListWnd__dCListWnd_x                                      0x8C1070
#define CListWnd__AddColumn_x                                      0x8C1010
#define CListWnd__AddColumn1_x                                     0x8C0880
#define CListWnd__AddLine_x                                        0x8C0300
#define CListWnd__AddString_x                                      0x8C0510
#define CListWnd__CalculateFirstVisibleLine_x                      0x8BD360
#define CListWnd__CalculateVSBRange_x                              0x8BF4F0
#define CListWnd__ClearAllSel_x                                    0x8BC620
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8BFED0
#define CListWnd__Compare_x                                        0x8BDE70
#define CListWnd__Draw_x                                           0x8BF100
#define CListWnd__DrawColumnSeparators_x                           0x8BEF90
#define CListWnd__DrawHeader_x                                     0x8BC930
#define CListWnd__DrawItem_x                                       0x8BE4C0
#define CListWnd__DrawLine_x                                       0x8BEC30
#define CListWnd__DrawSeparator_x                                  0x8BF030
#define CListWnd__EnsureVisible_x                                  0x8BD4C0
#define CListWnd__ExtendSel_x                                      0x8BE3D0
#define CListWnd__GetColumnMinWidth_x                              0x8BBFE0
#define CListWnd__GetColumnWidth_x                                 0x8BBF00
#define CListWnd__GetCurSel_x                                      0x8BB6E0
#define CListWnd__GetItemAtPoint_x                                 0x8BD760
#define CListWnd__GetItemAtPoint1_x                                0x8BD7D0
#define CListWnd__GetItemData_x                                    0x8BBA20
#define CListWnd__GetItemHeight_x                                  0x8BCFC0
#define CListWnd__GetItemIcon_x                                    0x8BBC00
#define CListWnd__GetItemRect_x                                    0x8BD5A0
#define CListWnd__GetItemText_x                                    0x8BBAB0
#define CListWnd__GetSelList_x                                     0x8C0770
#define CListWnd__GetSeparatorRect_x                               0x8BDD90
#define CListWnd__RemoveLine_x                                     0x8C06F0
#define CListWnd__SetColors_x                                      0x8BB830
#define CListWnd__SetColumnJustification_x                         0x8BC2B0
#define CListWnd__SetColumnWidth_x                                 0x8BBF90
#define CListWnd__SetCurSel_x                                      0x8BB720
#define CListWnd__SetItemColor_x                                   0x8BFBB0
#define CListWnd__SetItemData_x                                    0x8BC6D0
#define CListWnd__SetItemText_x                                    0x8BF9F0
#define CListWnd__ShiftColumnSeparator_x                           0x8BF880
#define CListWnd__Sort_x                                           0x8C1170
#define CListWnd__ToggleSel_x                                      0x8BC5A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x711D50

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7331C0
#define CMerchantWnd__RequestBuyItem_x                             0x739FF0
#define CMerchantWnd__RequestSellItem_x                            0x73AA40
#define CMerchantWnd__SelectRecoverySlot_x                         0x733470
#define CMerchantWnd__SelectBuySellSlot_x                          0x7326D0
#define CMerchantWnd__ActualSelect_x                               0x736F20

// CObfuscator
#define CObfuscator__doit_x                                        0x866490

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8DF3C0
#define CSidlManager__CreateLabel_x                                0x79B8F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x65E990
#define CSidlScreenWnd__CalculateVSBRange_x                        0x65E8B0
#define CSidlScreenWnd__ConvertToRes_x                             0x8FBFC0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8D6F30
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8D8440
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8D84F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8D79B0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8D68E0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8D6020
#define CSidlScreenWnd__GetSidlPiece_x                             0x8D6AD0
#define CSidlScreenWnd__Init1_x                                    0x8D8110
#define CSidlScreenWnd__LoadIniInfo_x                              0x8D6FE0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8D61E0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8D7C00
#define CSidlScreenWnd__StoreIniInfo_x                             0x8D5AE0
#define CSidlScreenWnd__StoreIniVis_x                              0x8D5FB0
#define CSidlScreenWnd__WndNotification_x                          0x8D7E90
#define CSidlScreenWnd__GetChildItem_x                             0x8D60F0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8C9600

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F9C50
#define CSkillMgr__GetSkillCap_x                                   0x5F9E10
#define CSkillMgr__GetNameToken_x                                  0x5F9870

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8FB280
#define CSliderWnd__SetValue_x                                     0x8FB450
#define CSliderWnd__SetNumTicks_x                                  0x8FBBD0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7A3650

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8F5C60
#define CStmlWnd__CalculateHSBRange_x                              0x8EE180
#define CStmlWnd__CalculateVSBRange_x                              0x8EE210
#define CStmlWnd__CanBreakAtCharacter_x                            0x8EE390
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8EEC70
#define CStmlWnd__ForceParseNow_x                                  0x8F65B0
#define CStmlWnd__GetNextTagPiece_x                                0x8EEB70
#define CStmlWnd__GetSTMLText_x                                    0x695C30
#define CStmlWnd__GetVisibleText_x                                 0x8EF6C0
#define CStmlWnd__InitializeWindowVariables_x                      0x8F1A50
#define CStmlWnd__MakeStmlColorTag_x                               0x8ED480
#define CStmlWnd__MakeWndNotificationTag_x                         0x8ED4E0
#define CStmlWnd__SetSTMLText_x                                    0x8F32B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8F5900
#define CStmlWnd__UpdateHistoryString_x                            0x8F0600

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8ECB10
#define CTabWnd__DrawCurrentPage_x                                 0x8EC380
#define CTabWnd__DrawTab_x                                         0x8EC140
#define CTabWnd__GetCurrentPage_x                                  0x8EC750
#define CTabWnd__GetPageInnerRect_x                                0x8EBE30
#define CTabWnd__GetTabInnerRect_x                                 0x8EC030
#define CTabWnd__GetTabRect_x                                      0x8EBF00
#define CTabWnd__InsertPage_x                                      0x8ECE00
#define CTabWnd__SetPage_x                                         0x8EC780
#define CTabWnd__SetPageRect_x                                     0x8ECA50
#define CTabWnd__UpdatePage_x                                      0x8ECDA0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431D00

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8D3C60

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x901430

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8B98D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x59B960
#define CXStr__CXStr1_x                                            0x7E5C80
#define CXStr__CXStr3_x                                            0x89DA40
#define CXStr__dCXStr_x                                            0x415470
#define CXStr__operator_equal_x                                    0x89DBB0
#define CXStr__operator_equal1_x                                   0x89DC00
#define CXStr__operator_plus_equal1_x                              0x89ECE0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8C8840
#define CXWnd__Center_x                                            0x8CE9A0
#define CXWnd__ClrFocus_x                                          0x8C8410
#define CXWnd__DoAllDrawing_x                                      0x8CE5F0
#define CXWnd__DrawChildren_x                                      0x8CE790
#define CXWnd__DrawColoredRect_x                                   0x8C8BF0
#define CXWnd__DrawTooltip_x                                       0x8C8EA0
#define CXWnd__DrawTooltipAtPoint_x                                0x8CD550
#define CXWnd__GetBorderFrame_x                                    0x8C9300
#define CXWnd__GetChildWndAt_x                                     0x8CF370
#define CXWnd__GetClientClipRect_x                                 0x8C90C0
#define CXWnd__GetScreenClipRect_x                                 0x8CDC50
#define CXWnd__GetScreenRect_x                                     0x8C94B0
#define CXWnd__GetTooltipRect_x                                    0x8C8D30
#define CXWnd__GetWindowTextA_x                                    0x422FF0
#define CXWnd__IsActive_x                                          0x8C3E70
#define CXWnd__IsDescendantOf_x                                    0x8C9250
#define CXWnd__IsReallyVisible_x                                   0x8CC590
#define CXWnd__IsType_x                                            0x8FDC50
#define CXWnd__Move_x                                              0x8CBCD0
#define CXWnd__Move1_x                                             0x8CE290
#define CXWnd__ProcessTransition_x                                 0x8C87E0
#define CXWnd__Refade_x                                            0x8C85B0
#define CXWnd__Resize_x                                            0x8C9570
#define CXWnd__Right_x                                             0x8CDA50
#define CXWnd__SetFocus_x                                          0x8CAE10
#define CXWnd__SetFont_x                                           0x8C8460
#define CXWnd__SetKeyTooltip_x                                     0x8C97D0
#define CXWnd__SetMouseOver_x                                      0x8CDF80
#define CXWnd__StartFade_x                                         0x8C8890
#define CXWnd__GetChildItem_x                                      0x8CDEC0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8C57B0
#define CXWndManager__DrawWindows_x                                0x8C53F0
#define CXWndManager__GetKeyboardFlags_x                           0x8C39E0
#define CXWndManager__HandleKeyboardMsg_x                          0x8C4310
#define CXWndManager__RemoveWnd_x                                  0x8C4000

// CDBStr
#define CDBStr__GetString_x                                        0x4A78B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44E200
#define EQ_Character__Cur_HP_x                                     0x463B00
#define EQ_Character__GetAACastingTimeModifier_x                   0x4460F0
#define EQ_Character__GetCharInfo2_x                               0x870CB0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43E170
#define EQ_Character__GetFocusRangeModifier_x                      0x43E360
#define EQ_Character__Max_Endurance_x                              0x5C16E0
#define EQ_Character__Max_HP_x                                     0x459720
#define EQ_Character__Max_Mana_x                                   0x5C1510
#define EQ_Character__doCombatAbility_x                            0x5BEB50
#define EQ_Character__UseSkill_x                                   0x46F010
#define EQ_Character__GetConLevel_x                                0x5B3620
#define EQ_Character__IsExpansionFlag_x                            0x422530
#define EQ_Character__TotalEffect_x                                0x44B4A0

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x593BF0
#define EQ_Item__CreateItemTagString_x                             0x850070
#define EQ_Item__IsStackable_x                                     0x844210
#define EQ_Item__GetImageNum_x                                     0x846EF0
#define EQ_Item__CreateItemClient_x                                0x5947B0
#define EQ_Item__GetItemValue_x                                    0x84ED20
#define EQ_Item__ValueSellMerchant_x                               0x8513D0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C7760
#define EQ_LoadingS__Array_x                                       0xC1E0A8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5C2D40
#define EQ_PC__GetAlternateAbilityId_x                             0x859440
#define EQ_PC__GetCombatAbility_x                                  0x8594D0
#define EQ_PC__GetCombatAbilityTimer_x                             0x854340
#define EQ_PC__GetItemTimerValue_x                                 0x5BC680
#define EQ_PC__HasLoreItem_x                                       0x5B6B00
#define EQ_PC__AlertInventoryChanged_x                             0x5B35F0
#define EQ_PC__GetPcZoneClient_x                                   0x5DD280
#define EQ_PC__RemoveMyAffect_x                                    0x5BBB40

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50F080
#define EQItemList__add_item_x                                     0x50EFC0
#define EQItemList__delete_item_x                                  0x50F480
#define EQItemList__FreeItemList_x                                 0x50F380

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A6B50

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C82F0
#define EQPlayer__dEQPlayer_x                                      0x5D1170
#define EQPlayer__DoAttack_x                                       0x5E31A0
#define EQPlayer__EQPlayer_x                                       0x5D3590
#define EQPlayer__SetNameSpriteState_x                             0x5CDE40
#define EQPlayer__SetNameSpriteTint_x                              0x5C9700
#define EQPlayer__IsBodyType_j_x                                   0x92EAD0
#define EQPlayer__IsTargetable_x                                   0x92F3D0
#define EQPlayer__CanSee_x                                         0x92F8F0
#define PlayerZoneClient__ChangeHeight_x                           0x5E3060
#define EQPlayer__CanSeeTargetIndicator_x                          0x92F9E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D7890
#define EQPlayerManager__GetSpawnByName_x                          0x5D7CF0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x599C90
#define KeypressHandler__AttachKeyToEqCommand_x                    0x599CD0
#define KeypressHandler__ClearCommandStateArray_x                  0x599870
#define KeypressHandler__HandleKeyDown_x                           0x5981D0
#define KeypressHandler__HandleKeyUp_x                             0x5984F0
#define KeypressHandler__SaveKeymapping_x                          0x599940

// MapViewMap 
#define MapViewMap__Clear_x                                        0x70A130
#define MapViewMap__SaveEx_x                                       0x70DA10

#define PlayerPointManager__GetAltCurrency_x                       0x86BC50

// StringTable 
#define StringTable__getString_x                                   0x866730

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5C1190
#define PcZoneClient__RemovePetEffect_x                            0x5BCB70
#define PcZoneClient__HasAlternateAbility_x                        0x5BD630

//Doors
#define EQSwitch__UseSwitch_x                                      0x54DA30

//IconCache
#define IconCache__GetIcon_x                                       0x6A64A0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x69D2B0
#define CContainerMgr__CloseContainer_x                            0x69DAD0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x76BB10

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x58CD40

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DEF00
#define EQ_Spell__SpellAffects_x                                   0x4DEFA0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DEFD0
#define CharacterZoneClient__CalcAffectChange_x                    0x4474E0
#define CLootWnd__LootAll_x                                        0x6FFA90

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7B1590
#define CTargetWnd__WndNotification_x                              0x7B1080

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B6760

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D87D0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x497030

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8E8560
#define CSidlManager__FindAnimation1_x                             0x8DD2C0

//CAltAbilityData
#define CAltAbilityData__GetMercCurrentRank_x                      0x4CED90
#define CAltAbilityData__GetMercMaxRank_x                          0x4CED40
#define CAltAbilityData__GetMaxRank_x                              0x4C3CA0

//CTargetRing
#define CTargetRing__Cast_x                                        0x58A630
