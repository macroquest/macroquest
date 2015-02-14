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
#define __ExpectedVersionDate                                     "Feb  9 2015"
#define __ExpectedVersionTime                                     "11:05:49"
#define __ActualVersionDate_x                                      0xA567F0
#define __ActualVersionTime_x                                      0xA567FC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x573180
#define __MemChecker1_x                                            0x83B040
#define __MemChecker2_x                                            0x60A880
#define __MemChecker3_x                                            0x60A7D0
#define __MemChecker4_x                                            0x7BF3D0
#define __EncryptPad0_x                                            0xBC4208
#define __EncryptPad1_x                                            0xD43DC0
#define __EncryptPad2_x                                            0xC0C490
#define __EncryptPad3_x                                            0xC0C090
#define __EncryptPad4_x                                            0xD20C48
#define __AC1_x                                                    0x77C705
#define __AC2_x                                                    0x529667
#define __AC3_x                                                    0x53DDC0
#define __AC4_x                                                    0x5440F0
#define __AC5_x                                                    0x54FE4E
#define __AC6_x                                                    0x553982
#define __AC7_x                                                    0x54A53C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10F53F8
#define DI8__Keyboard_x                                            0x10F53FC
#define DI8__Mouse_x                                               0x10F5400
#define __AltTimerReady_x                                          0xF54EC1
#define __Attack_x                                                 0xFE7F9B
#define __Autofire_x                                               0xFE7F9C
#define __BindList_x                                               0xB87708
#define __bCommandEnabled_x                                        0xF52FD0
#define __Clicks_x                                                 0xF63B08
#define __CommandList_x                                            0xB8B910
#define __CurrentMapLabel_x                                        0x10FAE50
#define __CurrentSocial_x                                          0xB4C5FC
#define __DoAbilityList_x                                          0xF9A250
#define __do_loot_x                                                0x4F1190
#define __DrawHandler_x                                            0x175FA4C
#define __GroupCount_x                                             0xF5459A

#define __Guilds_x                                                 0xF5A088
#define __gWorld_x                                                 0xF56A54
#define __HotkeyPage_x                                             0xFE0C50
#define __HWnd_x                                                   0xFED300
#define __InChatMode_x                                             0xF63A34
#define __LastTell_x                                               0xF65958
#define __LMouseHeldTime_x                                         0xF63B74
#define __Mouse_x                                                  0x10F5404
#define __MouseLook_x                                              0xF63ACE
#define __MouseEventTime_x                                         0xFE878C
#define __NetStatusToggle_x                                        0xF63AD1
#define __PCNames_x                                                0xF64F88
#define __RangeAttackReady_x                                       0xF64C58
#define __RMouseHeldTime_x                                         0xF63B70
#define __RunWalkState_x                                           0xF63A38
#define __ScreenMode_x                                             0xEA2F90
#define __ScreenX_x                                                0xF639EC
#define __ScreenY_x                                                0xF639E8
#define __ScreenXMax_x                                             0xF639F0
#define __ScreenYMax_x                                             0xF639F4
#define __ServerHost_x                                             0xF544E4
#define __ServerName_x                                             0xF9A210
#define __ShiftKeyDown_x                                           0xF640DC
#define __ShowNames_x                                              0xF64E2C
#define __Socials_x                                                0xF9A310
#define __SubscriptionType_x                                       0x11271E0
#define __TargetAggroHolder_x                                      0x10FD08C
#define __GroupAggro_x                                             0x10FD0CC
#define __LoginName_x                                              0xFEBED8
#define __Inviter_x                                                0xFE7F18


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF56B40
#define instEQZoneInfo_x                                           0xF63CC4
#define instKeypressHandler_x                                      0xFE8770
#define pinstActiveBanker_x                                        0xF56AF8
#define pinstActiveCorpse_x                                        0xF56AFC
#define pinstActiveGMaster_x                                       0xF56B00
#define pinstActiveMerchant_x                                      0xF56AF4
#define pinstAggroInfo_x                                           0xD67578
#define pinstAltAdvManager_x                                       0xEA4068
#define pinstAuraMgr_x                                             0xD71440
#define pinstBandageTarget_x                                       0xF56AE0
#define pinstCamActor_x                                            0xEA3974
#define pinstCDBStr_x                                              0xEA2F24
#define pinstCDisplay_x                                            0xF56B08
#define pinstCEverQuest_x                                          0x10F5578
#define pinstCharData_x                                            0xF56AC4
#define pinstCharSpawn_x                                           0xF56AEC
#define pinstControlledMissile_x                                   0xF56AC0
#define pinstControlledPlayer_x                                    0xF56AEC
#define pinstCSidlManager_x                                        0x175EE78
#define pinstCXWndManager_x                                        0x175EE70
#define instDynamicZone_x                                          0xF63880
#define pinstDZMember_x                                            0xF63990
#define pinstDZTimerInfo_x                                         0xF63994
#define pinstEQItemList_x                                          0xF5321C
#define instEQMisc_x                                               0xB685C8
#define pinstEQSoundManager_x                                      0xEA4368
#define instExpeditionLeader_x                                     0xF638CA
#define instExpeditionName_x                                       0xF6390A
#define pinstGroup_x                                               0xF54596
#define pinstImeManager_x                                          0x175EE7C
#define pinstLocalPlayer_x                                         0xF56AD8
#define pinstMercenaryData_x                                       0xFE8DC0
#define pinstMercAltAbilities_x                                    0xEA4288
#define pinstModelPlayer_x                                         0xF56B04
#define pinstPCData_x                                              0xF56AC4
#define pinstSkillMgr_x                                            0xFE9BF8
#define pinstSpawnManager_x                                        0xFE94E0
#define pinstSpellManager_x                                        0xFE9D40
#define pinstSpellSets_x                                           0xFE0CB4
#define pinstStringTable_x                                         0xF56A6C
#define pinstSwitchManager_x                                       0xF54128
#define pinstTarget_x                                              0xF56AF0
#define pinstTargetObject_x                                        0xF56AC8
#define pinstTargetSwitch_x                                        0xF56ACC
#define pinstTaskMember_x                                          0xEA2E70
#define pinstTrackTarget_x                                         0xF56AE4
#define pinstTradeTarget_x                                         0xF56AD4
#define instTributeActive_x                                        0xB685ED
#define pinstViewActor_x                                           0xEA3970
#define pinstWorldData_x                                           0xF56AA8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD67A58
#define pinstCAudioTriggersWindow_x                                0xD678E8
#define pinstCCharacterSelect_x                                    0xEA381C
#define pinstCFacePick_x                                           0xEA35CC
#define pinstCNoteWnd_x                                            0xEA37D4
#define pinstCBookWnd_x                                            0xEA37DC
#define pinstCPetInfoWnd_x                                         0xEA37E0
#define pinstCTrainWnd_x                                           0xEA37E4
#define pinstCSkillsWnd_x                                          0xEA37E8
#define pinstCSkillsSelectWnd_x                                    0xEA37EC
#define pinstCCombatSkillSelectWnd_x                               0xEA37F0
#define pinstCFriendsWnd_x                                         0xEA37F4
#define pinstCAuraWnd_x                                            0xEA37F8
#define pinstCRespawnWnd_x                                         0xEA37FC
#define pinstCBandolierWnd_x                                       0xEA3800
#define pinstCPotionBeltWnd_x                                      0xEA3804
#define pinstCAAWnd_x                                              0xEA3808
#define pinstCGroupSearchFiltersWnd_x                              0xEA380C
#define pinstCLoadskinWnd_x                                        0xEA3810
#define pinstCAlarmWnd_x                                           0xEA3814
#define pinstCMusicPlayerWnd_x                                     0xEA3818
#define pinstCMailWnd_x                                            0xEA3820
#define pinstCMailCompositionWnd_x                                 0xEA3824
#define pinstCMailAddressBookWnd_x                                 0xEA3828
#define pinstCRaidWnd_x                                            0xEA3830
#define pinstCRaidOptionsWnd_x                                     0xEA3834
#define pinstCBreathWnd_x                                          0xEA3838
#define pinstCMapViewWnd_x                                         0xEA383C
#define pinstCMapToolbarWnd_x                                      0xEA3840
#define pinstCEditLabelWnd_x                                       0xEA3844
#define pinstCTargetWnd_x                                          0xEA3848
#define pinstCColorPickerWnd_x                                     0xEA384C
#define pinstCPlayerWnd_x                                          0xEA3850
#define pinstCOptionsWnd_x                                         0xEA3854
#define pinstCBuffWindowNORMAL_x                                   0xEA3858
#define pinstCBuffWindowSHORT_x                                    0xEA385C
#define pinstCharacterCreation_x                                   0xEA3860
#define pinstCCursorAttachment_x                                   0xEA3864
#define pinstCCastingWnd_x                                         0xEA3868
#define pinstCCastSpellWnd_x                                       0xEA386C
#define pinstCSpellBookWnd_x                                       0xEA3870
#define pinstCInventoryWnd_x                                       0xEA3874
#define pinstCBankWnd_x                                            0xEA3878
#define pinstCQuantityWnd_x                                        0xEA387C
#define pinstCLootWnd_x                                            0xEA3880
#define pinstCActionsWnd_x                                         0xEA3884
#define pinstCCombatAbilityWnd_x                                   0xEA3888
#define pinstCMerchantWnd_x                                        0xEA388C
#define pinstCTradeWnd_x                                           0xEA3890
#define pinstCSelectorWnd_x                                        0xEA3894
#define pinstCBazaarWnd_x                                          0xEA3898
#define pinstCBazaarSearchWnd_x                                    0xEA389C
#define pinstCGiveWnd_x                                            0xEA38B8
#define pinstCTrackingWnd_x                                        0xEA38C0
#define pinstCInspectWnd_x                                         0xEA38C4
#define pinstCSocialEditWnd_x                                      0xEA38C8
#define pinstCFeedbackWnd_x                                        0xEA38CC
#define pinstCBugReportWnd_x                                       0xEA38D0
#define pinstCVideoModesWnd_x                                      0xEA38D4
#define pinstCTextEntryWnd_x                                       0xEA38DC
#define pinstCFileSelectionWnd_x                                   0xEA38E0
#define pinstCCompassWnd_x                                         0xEA38E4
#define pinstCPlayerNotesWnd_x                                     0xEA38E8
#define pinstCGemsGameWnd_x                                        0xEA38EC
#define pinstCTimeLeftWnd_x                                        0xEA38F0
#define pinstCPetitionQWnd_x                                       0xEA3904
#define pinstCSoulmarkWnd_x                                        0xEA3908
#define pinstCStoryWnd_x                                           0xEA390C
#define pinstCJournalTextWnd_x                                     0xEA3910
#define pinstCJournalCatWnd_x                                      0xEA3914
#define pinstCBodyTintWnd_x                                        0xEA3918
#define pinstCServerListWnd_x                                      0xEA391C
#define pinstCAvaZoneWnd_x                                         0xEA3928
#define pinstCBlockedBuffWnd_x                                     0xEA392C
#define pinstCBlockedPetBuffWnd_x                                  0xEA3930
#define pinstCInvSlotMgr_x                                         0xEA3968
#define pinstCContainerMgr_x                                       0xEA396C
#define pinstCAdventureLeaderboardWnd_x                            0x10F5F28
#define pinstCAdventureRequestWnd_x                                0x10F5FA0
#define pinstCAltStorageWnd_x                                      0x10F6280
#define pinstCAdventureStatsWnd_x                                  0x10F6018
#define pinstCBarterMerchantWnd_x                                  0x10F6E68
#define pinstCBarterSearchWnd_x                                    0x10F6EE0
#define pinstCBarterWnd_x                                          0x10F6F58
#define pinstCChatManager_x                                        0x10F75E8
#define pinstCDynamicZoneWnd_x                                     0x10F7A98
#define pinstCEQMainWnd_x                                          0x10F7C30
#define pinstCFellowshipWnd_x                                      0x10F7A2C
#define pinstCFindLocationWnd_x                                    0x10F7F00
#define pinstCGroupSearchWnd_x                                     0x10F81D0
#define pinstCGroupWnd_x                                           0x10F8248
#define pinstCGuildBankWnd_x                                       0x10F82C0
#define pinstCGuildMgmtWnd_x                                       0x10FA3B0
#define pinstCHotButtonWnd_x                                       0x10FA47C
#define pinstCHotButtonWnd1_x                                      0x10FA47C
#define pinstCHotButtonWnd2_x                                      0x10FA480
#define pinstCHotButtonWnd3_x                                      0x10FA484
#define pinstCHotButtonWnd4_x                                      0x10FA4A8
#define pinstCItemDisplayManager_x                                 0x10FA7A0
#define pinstCItemExpTransferWnd_x                                 0x10FA81C
#define pinstCLFGuildWnd_x                                         0x10FAAF8
#define pinstCMIZoneSelectWnd_x                                    0x10FB0E0
#define pinstCConfirmationDialog_x                                 0x10FB7E8
#define pinstCPopupWndManager_x                                    0x10FB7E8
#define pinstCProgressionSelectionWnd_x                            0x10FB8D8
#define pinstCPvPStatsWnd_x                                        0x10FB9C8
#define pinstCSystemInfoDialogBox_x                                0x10FC0D0
#define pinstCTaskWnd_x                                            0x10FD498
#define pinstCTaskSomething_x                                      0xD71A18
#define pinstCTaskTemplateSelectWnd_x                              0x10FD420
#define pinstCTipWndOFDAY_x                                        0x10FD6F0
#define pinstCTipWndCONTEXT_x                                      0x10FD6F4
#define pinstCTitleWnd_x                                           0x10FD770
#define pinstCContextMenuManager_x                                 0x175EA8C
#define pinstCVoiceMacroWnd_x                                      0xFEA3A8
#define pinstCHtmlWnd_x                                            0xFEA4A0
#define pinstIconCache_x                                           0x10F7C04
#define pinstCTradeskillWnd_x                                      0x10FD870

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x508AF0
#define __ConvertItemTags_x                                        0x4F5D80
#define __ExecuteCmd_x                                             0x4E0980
#define __EQGetTime_x                                              0x83BBA0
#define __get_melee_range_x                                        0x4E7650
#define __GetGaugeValueFromEQ_x                                    0x77B450
#define __GetLabelFromEQ_x                                         0x77C690
#define __ToggleMount_x                                            0x6A4E20
#define __GetXTargetType_x                                         0x8F9450
#define __LoadFrontEnd_x                                           0x609F30
#define __NewUIINI_x                                               0x77AD50
#define __ProcessGameEvents_x                                      0x54C2A0
#define __ProcessMouseEvent_x                                      0x54BA40
#define CrashDetected_x                                            0x60BA00
#define wwsCrashReportCheckForUploader_x                           0x7D0240
#define DrawNetStatus_x                                            0x582C90
#define Util__FastTime_x                                           0x83AEB0
#define Expansion_HoT_x                                            0xF64DC4
#define __HelpPath_x                                               0xFE84F8

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A5C80
#define AltAdvManager__IsAbilityReady_x                            0x4A5CF0
#define AltAdvManager__GetAltAbility_x                             0x4A60B0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x452EB0
#define CharacterZoneClient__MakeMeVisible_x                       0x457F70
// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x639650

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6477D0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x562290

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x662A00
#define CChatManager__InitContextMenu_x                            0x663520

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x88AD80
#define CContextMenu__dCContextMenu_x                              0x88AF90
#define CContextMenu__AddMenuItem_x                                0x88AFA0
#define CContextMenu__RemoveMenuItem_x                             0x88B290
#define CContextMenu__RemoveAllMenuItems_x                         0x88B2B0
#define CContextMenuManager__AddMenu_x                             0x891490
#define CContextMenuManager__RemoveMenu_x                          0x8917D0
#define CContextMenuManager__PopupMenu_x                           0x891C20
#define CContextMenuManager__Flush_x                               0x891500

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x821C90
#define CChatService__GetFriendName_x                              0x821CA0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x668360
#define CChatWindow__Clear_x                                       0x667F20
#define CChatWindow__WndNotification_x                             0x6688A0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x89A450
#define CComboWnd__Draw_x                                          0x89A650
#define CComboWnd__GetCurChoice_x                                  0x89A270
#define CComboWnd__GetListRect_x                                   0x89A8F0
#define CComboWnd__GetTextRect_x                                   0x89A4B0
#define CComboWnd__InsertChoice_x                                  0x89A960
#define CComboWnd__SetColors_x                                     0x89A200
#define CComboWnd__SetChoice_x                                     0x89A230

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x671B10
#define CContainerWnd__vftable_x                                   0xA5FF70

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4946F0
#define CDisplay__GetClickedActor_x                                0x48D280
#define CDisplay__GetUserDefinedColor_x                            0x48BB40
#define CDisplay__GetWorldFilePath_x                               0x48AF90
#define CDisplay__is3dON_x                                         0x48A360
#define CDisplay__ReloadUI_x                                       0x49F970
#define CDisplay__WriteTextHD2_x                                   0x490A90

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8BC190

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8AAD40
#define CEditWnd__GetCharIndexPt_x                                 0x8ABD60
#define CEditWnd__GetDisplayString_x                               0x8AAEF0
#define CEditWnd__GetHorzOffset_x                                  0x8AB230
#define CEditWnd__GetLineForPrintableChar_x                        0x8AB830
#define CEditWnd__GetSelStartPt_x                                  0x8AC010
#define CEditWnd__GetSTMLSafeText_x                                0x8AB3D0
#define CEditWnd__PointFromPrintableChar_x                         0x8AB920
#define CEditWnd__SelectableCharFromPoint_x                        0x8ABAA0
#define CEditWnd__SetEditable_x                                    0x8AB3A0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x529DB0
#define CEverQuest__DoTellWindow_x                                 0x52F7B0
#define CEverQuest__DropHeldItemOnGround_x                         0x538240
#define CEverQuest__dsp_chat_x                                     0x530F50
#define CEverQuest__Emote_x                                        0x5311B0
#define CEverQuest__EnterZone_x                                    0x544910
#define CEverQuest__GetBodyTypeDesc_x                              0x5266E0
#define CEverQuest__GetClassDesc_x                                 0x52C320
#define CEverQuest__GetClassThreeLetterCode_x                      0x52C920
#define CEverQuest__GetDeityDesc_x                                 0x526FC0
#define CEverQuest__GetLangDesc_x                                  0x526A70
#define CEverQuest__GetRaceDesc_x                                  0x52CAE0
#define CEverQuest__InterpretCmd_x                                 0x531A90
#define CEverQuest__LeftClickedOnPlayer_x                          0x5489A0
#define CEverQuest__LMouseUp_x                                     0x54AA90
#define CEverQuest__RightClickedOnPlayer_x                         0x5494A0
#define CEverQuest__RMouseUp_x                                     0x54A4F0
#define CEverQuest__SetGameState_x                                 0x52A460
#define CEverQuest__UPCNotificationFlush_x                         0x532C30
#define CEverQuest__IssuePetCommand_x                              0x532790

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6827C0
#define CGaugeWnd__CalcLinesFillRect_x                             0x682820
#define CGaugeWnd__Draw_x                                          0x682C50

// CGuild
#define CGuild__FindMemberByName_x                                 0x4247C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69F880

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6AD660
#define CInvSlotMgr__MoveItem_x                                    0x6AE5A0
#define CInvSlotMgr__SelectSlot_x                                  0x6AD710

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6ACB00
#define CInvSlot__SliderComplete_x                                 0x6AA4C0
#define CInvSlot__GetItemBase_x                                    0x6A9920

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6AF750

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x777F60
#define CItemDisplayWnd__UpdateStrings_x                           0x6B0AB0

// CLabel 
#define CLabel__Draw_x                                             0x6CB900

// CListWnd
#define CListWnd__CListWnd_x                                       0x887420
#define CListWnd__dCListWnd_x                                      0x8884B0
#define CListWnd__AddColumn_x                                      0x888450
#define CListWnd__AddColumn1_x                                     0x887C30
#define CListWnd__AddLine_x                                        0x8876E0
#define CListWnd__AddString_x                                      0x8878F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x884760
#define CListWnd__CalculateVSBRange_x                              0x8868E0
#define CListWnd__ClearAllSel_x                                    0x883A10
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8872B0
#define CListWnd__Compare_x                                        0x885270
#define CListWnd__Draw_x                                           0x8864F0
#define CListWnd__DrawColumnSeparators_x                           0x886380
#define CListWnd__DrawHeader_x                                     0x883D20
#define CListWnd__DrawItem_x                                       0x8858B0
#define CListWnd__DrawLine_x                                       0x886020
#define CListWnd__DrawSeparator_x                                  0x886420
#define CListWnd__EnsureVisible_x                                  0x8848C0
#define CListWnd__ExtendSel_x                                      0x8857C0
#define CListWnd__GetColumnMinWidth_x                              0x883430
#define CListWnd__GetColumnWidth_x                                 0x883350
#define CListWnd__GetCurSel_x                                      0x882B10
#define CListWnd__GetItemAtPoint_x                                 0x884B60
#define CListWnd__GetItemAtPoint1_x                                0x884BD0
#define CListWnd__GetItemData_x                                    0x882E60
#define CListWnd__GetItemHeight_x                                  0x8843B0
#define CListWnd__GetItemIcon_x                                    0x883040
#define CListWnd__GetItemRect_x                                    0x8849A0
#define CListWnd__GetItemText_x                                    0x882EF0
#define CListWnd__GetSelList_x                                     0x887B20
#define CListWnd__GetSeparatorRect_x                               0x885190
#define CListWnd__RemoveLine_x                                     0x887AD0
#define CListWnd__SetColors_x                                      0x882C60
#define CListWnd__SetColumnJustification_x                         0x883700
#define CListWnd__SetColumnWidth_x                                 0x8833E0
#define CListWnd__SetCurSel_x                                      0x882B50
#define CListWnd__SetItemColor_x                                   0x886F90
#define CListWnd__SetItemData_x                                    0x883AC0
#define CListWnd__SetItemText_x                                    0x886DD0
#define CListWnd__ShiftColumnSeparator_x                           0x886C60
#define CListWnd__Sort_x                                           0x8885B0
#define CListWnd__ToggleSel_x                                      0x883990

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6E4CA0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x706090
#define CMerchantWnd__RequestBuyItem_x                             0x70CF00
#define CMerchantWnd__RequestSellItem_x                            0x70D970
#define CMerchantWnd__SelectRecoverySlot_x                         0x706340
#define CMerchantWnd__SelectBuySellSlot_x                          0x7055A0
#define CMerchantWnd__ActualSelect_x                               0x709E20

// CObfuscator
#define CObfuscator__doit_x                                        0x801F90

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x89FB70
#define CSidlManager__CreateLabel_x                                0x76DF00

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x630880
#define CSidlScreenWnd__CalculateVSBRange_x                        0x630760
#define CSidlScreenWnd__ConvertToRes_x                             0x8BC070
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x88D560
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x88EA70
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x88EB20
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x88DFE0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x88D040
#define CSidlScreenWnd__EnableIniStorage_x                         0x88C790
#define CSidlScreenWnd__GetSidlPiece_x                             0x88D230
#define CSidlScreenWnd__Init1_x                                    0x88E740
#define CSidlScreenWnd__LoadIniInfo_x                              0x88D610
#define CSidlScreenWnd__LoadIniListWnd_x                           0x88C950
#define CSidlScreenWnd__LoadSidlScreen_x                           0x88E230
#define CSidlScreenWnd__StoreIniInfo_x                             0x88C250
#define CSidlScreenWnd__StoreIniVis_x                              0x88C720
#define CSidlScreenWnd__WndNotification_x                          0x88E4C0
#define CSidlScreenWnd__GetChildItem_x                             0x88C860
#define CSidlScreenWnd__HandleLButtonUp_x                          0x893460

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5CC030
#define CSkillMgr__GetSkillCap_x                                   0x5CC1D0
#define CSkillMgr__GetNameToken_x                                  0x5CBCA0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8C6140
#define CSliderWnd__SetValue_x                                     0x8C6310
#define CSliderWnd__SetNumTicks_x                                  0x8C6A90

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x775C00

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8B6460
#define CStmlWnd__CalculateHSBRange_x                              0x8AE970
#define CStmlWnd__CalculateVSBRange_x                              0x8AEA00
#define CStmlWnd__CanBreakAtCharacter_x                            0x8AEB80
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8AF460
#define CStmlWnd__ForceParseNow_x                                  0x8B6DB0
#define CStmlWnd__GetNextTagPiece_x                                0x8AF360
#define CStmlWnd__GetSTMLText_x                                    0x6677C0
#define CStmlWnd__GetVisibleText_x                                 0x8AFEB0
#define CStmlWnd__InitializeWindowVariables_x                      0x8B2240
#define CStmlWnd__MakeStmlColorTag_x                               0x8ADC70
#define CStmlWnd__MakeWndNotificationTag_x                         0x8ADCD0
#define CStmlWnd__SetSTMLText_x                                    0x8B3AA0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8B6100
#define CStmlWnd__UpdateHistoryString_x                            0x8B0DF0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8BD930
#define CTabWnd__DrawCurrentPage_x                                 0x8BD1A0
#define CTabWnd__DrawTab_x                                         0x8BCF60
#define CTabWnd__GetCurrentPage_x                                  0x8BD570
#define CTabWnd__GetPageInnerRect_x                                0x8BCC50
#define CTabWnd__GetTabInnerRect_x                                 0x8BCE50
#define CTabWnd__GetTabRect_x                                      0x8BCD20
#define CTabWnd__InsertPage_x                                      0x8BDC20
#define CTabWnd__SetPage_x                                         0x8BD5A0
#define CTabWnd__SetPageRect_x                                     0x8BD870
#define CTabWnd__UpdatePage_x                                      0x8BDBC0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4205B0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B98D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8C2B00

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x880B60

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x56F820
#define CXStr__CXStr1_x                                            0x7B8670
#define CXStr__CXStr3_x                                            0x837F40
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x8380B0
#define CXStr__operator_equal1_x                                   0x838100
#define CXStr__operator_plus_equal1_x                              0x8391E0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x892640
#define CXWnd__Center_x                                            0x898890
#define CXWnd__ClrFocus_x                                          0x892220
#define CXWnd__DoAllDrawing_x                                      0x8984E0
#define CXWnd__DrawChildren_x                                      0x898680
#define CXWnd__DrawColoredRect_x                                   0x892A00
#define CXWnd__DrawTooltip_x                                       0x892CB0
#define CXWnd__DrawTooltipAtPoint_x                                0x897470
#define CXWnd__GetBorderFrame_x                                    0x893120
#define CXWnd__GetChildWndAt_x                                     0x896400
#define CXWnd__GetClientClipRect_x                                 0x892ED0
#define CXWnd__GetScreenClipRect_x                                 0x897B70
#define CXWnd__GetScreenRect_x                                     0x8932F0
#define CXWnd__GetTooltipRect_x                                    0x892B40
#define CXWnd__GetWindowTextA_x                                    0x4119A0
#define CXWnd__IsActive_x                                          0x8A5B50
#define CXWnd__IsDescendantOf_x                                    0x893060
#define CXWnd__IsReallyVisible_x                                   0x8963E0
#define CXWnd__IsType_x                                            0x8BF320
#define CXWnd__Move_x                                              0x895AD0
#define CXWnd__Move1_x                                             0x8981A0
#define CXWnd__ProcessTransition_x                                 0x8925F0
#define CXWnd__Refade_x                                            0x8923C0
#define CXWnd__Resize_x                                            0x8933C0
#define CXWnd__Right_x                                             0x897970
#define CXWnd__SetFocus_x                                          0x894C30
#define CXWnd__SetFont_x                                           0x892270
#define CXWnd__SetKeyTooltip_x                                     0x893630
#define CXWnd__SetMouseOver_x                                      0x897EA0
#define CXWnd__StartFade_x                                         0x892690
#define CXWnd__GetChildItem_x                                      0x897DE0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A7450
#define CXWndManager__DrawWindows_x                                0x8A70A0
#define CXWndManager__GetKeyboardFlags_x                           0x8A5690
#define CXWndManager__HandleKeyboardMsg_x                          0x8A5FD0
#define CXWndManager__RemoveWnd_x                                  0x8A5CE0

// CDBStr
#define CDBStr__GetString_x                                        0x488780

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x43C840
#define EQ_Character__Cur_HP_x                                     0x452570
#define EQ_Character__GetAACastingTimeModifier_x                   0x435920
#define EQ_Character__GetCharInfo2_x                               0x80C6C0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42DBE0
#define EQ_Character__GetFocusRangeModifier_x                      0x42DDC0
#define EQ_Character__Max_Endurance_x                              0x594C30
#define EQ_Character__Max_HP_x                                     0x448860
#define EQ_Character__Max_Mana_x                                   0x594A60
#define EQ_Character__doCombatAbility_x                            0x592050
#define EQ_Character__UseSkill_x                                   0x45D0B0
#define EQ_Character__GetConLevel_x                                0x587310
#define EQ_Character__IsExpansionFlag_x                            0x410ED0
#define EQ_Character__TotalEffect_x                                0x43A970

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x567A50
#define EQ_Item__CreateItemTagString_x                             0x7EC9C0
#define EQ_Item__IsStackable_x                                     0x7E0B80
#define EQ_Item__GetImageNum_x                                     0x7E3830

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A7D70
#define EQ_LoadingS__Array_x                                       0xB75FB8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5963D0
#define EQ_PC__GetAltAbilityIndex_x                                0x7F4D20
#define EQ_PC__GetCombatAbility_x                                  0x7F4DB0
#define EQ_PC__GetCombatAbilityTimer_x                             0x7F4E60
#define EQ_PC__GetItemTimerValue_x                                 0x58FE20
#define EQ_PC__HasLoreItem_x                                       0x58A5F0
#define EQ_PC__AlertInventoryChanged_x                             0x5872E0
#define EQ_PC__GetPcZoneClient_x                                   0x5B0750
#define EQ_PC__RemoveMyAffect_x									   0x58F330

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E5600
#define EQItemList__add_item_x                                     0x4E5540
#define EQItemList__delete_item_x                                  0x4E5A00
#define EQItemList__FreeItemList_x                                 0x4E5900

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487A40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x59B870
#define EQPlayer__dEQPlayer_x                                      0x5A4600
#define EQPlayer__DoAttack_x                                       0x5B6560
#define EQPlayer__EQPlayer_x                                       0x5A6A20
#define EQPlayer__SetNameSpriteState_x                             0x5A1330
#define EQPlayer__SetNameSpriteTint_x                              0x59CC40
#define EQPlayer__IsBodyType_j_x                                   0x8F5660
#define EQPlayer__IsTargetable_x                                   0x8F5ED0
#define EQPlayer__CanSee_x                                         0x8F63F0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5AAD60
#define EQPlayerManager__GetSpawnByName_x                          0x5AB1C0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56DB50
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56DB90
#define KeypressHandler__ClearCommandStateArray_x                  0x56D730
#define KeypressHandler__HandleKeyDown_x                           0x56C090
#define KeypressHandler__HandleKeyUp_x                             0x56C3B0
#define KeypressHandler__SaveKeymapping_x                          0x56D800

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6DD080
#define MapViewMap__SaveEx_x                                       0x6E0960

#define PlayerPointManager__GetAltCurrency_x                       0x806860

// StringTable 
#define StringTable__getString_x                                   0x802230

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5946E0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5239A0

//IconCache
#define IconCache__GetIcon_x                                       0x677FE0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66EE30
#define CContainerMgr__CloseContainer_x                            0x66F650

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x73E290

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x560D40

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B63F0
#define EQ_Spell__SpellAffects_x                                   0x4B6490
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B64C0
#define CharacterZoneClient__CalcAffectChange_x                    0x436C40
#define CLootWnd__LootAll_x                                        0x6D2A90

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7839D0
#define CTargetWnd__WndNotification_x                              0x7834C0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x788B90
