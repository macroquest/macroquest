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
#define __ExpectedVersionDate                                     "Jan 22 2015"
#define __ExpectedVersionTime                                     "16:48:34"
#define __ActualVersionDate_x                                      0xA567C8
#define __ActualVersionTime_x                                      0xA567D4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x572E20
#define __MemChecker1_x                                            0x83AF20
#define __MemChecker2_x                                            0x60A7E0
#define __MemChecker3_x                                            0x60A730
#define __MemChecker4_x                                            0x7BECD0
#define __EncryptPad0_x                                            0xBC4208
#define __EncryptPad1_x                                            0xD43DC0
#define __EncryptPad2_x                                            0xC0C490
#define __EncryptPad3_x                                            0xC0C090
#define __EncryptPad4_x                                            0xD20C48
#define __AC1_x                                                    0x77C1A5
#define __AC2_x                                                    0x529317
#define __AC3_x                                                    0x53DA70
#define __AC4_x                                                    0x543DA0
#define __AC5_x                                                    0x54FAFE
#define __AC6_x                                                    0x553632
#define __AC7_x                                                    0x54A1EC
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
#define __do_loot_x                                                0x4F0D50
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
#define __CastRay_x                                                0x5086B0
#define __ConvertItemTags_x                                        0x4F5940
#define __ExecuteCmd_x                                             0x4E0540
#define __EQGetTime_x                                              0x83BA80
#define __get_melee_range_x                                        0x4E7210
#define __GetGaugeValueFromEQ_x                                    0x77AEF0
#define __GetLabelFromEQ_x                                         0x77C130
#define __ToggleMount_x                                            0x6A4DA0
#define __GetXTargetType_x                                         0x8F9210
#define __LoadFrontEnd_x                                           0x609E90
#define __NewUIINI_x                                               0x77A7F0
#define __ProcessGameEvents_x                                      0x54BF50
#define __ProcessMouseEvent_x                                      0x54B6F0
#define CrashDetected_x                                            0x60B960
#define wwsCrashReportCheckForUploader_x                           0x7D0130
#define DrawNetStatus_x                                            0x582850
#define Util__FastTime_x                                           0x83AD90
#define Expansion_HoT_x                                            0xF64DC4
#define __HelpPath_x                                               0xFE84F8

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A5EA0
#define AltAdvManager__IsAbilityReady_x                            0x4A5F10
#define AltAdvManager__GetAltAbility_x                             0x4A62D0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x452E80
#define CharacterZoneClient__MakeMeVisible_x                       0x457F40
// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x639650

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6474D0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x561F80

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6629C0
#define CChatManager__InitContextMenu_x                            0x6634E0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x88A9D0
#define CContextMenu__dCContextMenu_x                              0x88ABE0
#define CContextMenu__AddMenuItem_x                                0x88ABF0
#define CContextMenu__RemoveMenuItem_x                             0x88AED0
#define CContextMenu__RemoveAllMenuItems_x                         0x88AEF0
#define CContextMenuManager__AddMenu_x                             0x891080
#define CContextMenuManager__RemoveMenu_x                          0x8913C0
#define CContextMenuManager__PopupMenu_x                           0x891810
#define CContextMenuManager__Flush_x                               0x8910F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x821B40
#define CChatService__GetFriendName_x                              0x821B50

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x668330
#define CChatWindow__Clear_x                                       0x667EE0
#define CChatWindow__WndNotification_x                             0x668870

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x89A170
#define CComboWnd__Draw_x                                          0x89A370
#define CComboWnd__GetCurChoice_x                                  0x899F90
#define CComboWnd__GetListRect_x                                   0x89A610
#define CComboWnd__GetTextRect_x                                   0x89A1D0
#define CComboWnd__InsertChoice_x                                  0x89A680
#define CComboWnd__SetColors_x                                     0x899F20
#define CComboWnd__SetChoice_x                                     0x899F50

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x671AE0
#define CContainerWnd__vftable_x                                   0xA5FF48

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x494760
#define CDisplay__GetClickedActor_x                                0x48D2E0
#define CDisplay__GetUserDefinedColor_x                            0x48BBA0
#define CDisplay__GetWorldFilePath_x                               0x48AFF0
#define CDisplay__is3dON_x                                         0x48A3C0
#define CDisplay__ReloadUI_x                                       0x49F9E0
#define CDisplay__WriteTextHD2_x                                   0x490B00

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8BBFB0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8AAB70
#define CEditWnd__GetCharIndexPt_x                                 0x8ABB80
#define CEditWnd__GetDisplayString_x                               0x8AAD20
#define CEditWnd__GetHorzOffset_x                                  0x8AB060
#define CEditWnd__GetLineForPrintableChar_x                        0x8AB650
#define CEditWnd__GetSelStartPt_x                                  0x8ABE30
#define CEditWnd__GetSTMLSafeText_x                                0x8AB1F0
#define CEditWnd__PointFromPrintableChar_x                         0x8AB740
#define CEditWnd__SelectableCharFromPoint_x                        0x8AB8C0
#define CEditWnd__SetEditable_x                                    0x8AB1C0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x529A60
#define CEverQuest__DoTellWindow_x                                 0x52F460
#define CEverQuest__DropHeldItemOnGround_x                         0x537EF0
#define CEverQuest__dsp_chat_x                                     0x530C00
#define CEverQuest__Emote_x                                        0x530E60
#define CEverQuest__EnterZone_x                                    0x5445C0
#define CEverQuest__GetBodyTypeDesc_x                              0x526390
#define CEverQuest__GetClassDesc_x                                 0x52BFD0
#define CEverQuest__GetClassThreeLetterCode_x                      0x52C5D0
#define CEverQuest__GetDeityDesc_x                                 0x526C70
#define CEverQuest__GetLangDesc_x                                  0x526720
#define CEverQuest__GetRaceDesc_x                                  0x52C790
#define CEverQuest__InterpretCmd_x                                 0x531740
#define CEverQuest__LeftClickedOnPlayer_x                          0x548650
#define CEverQuest__LMouseUp_x                                     0x54A740
#define CEverQuest__RightClickedOnPlayer_x                         0x549150
#define CEverQuest__RMouseUp_x                                     0x54A1A0
#define CEverQuest__SetGameState_x                                 0x52A110
#define CEverQuest__UPCNotificationFlush_x                         0x5328E0
#define CEverQuest__IssuePetCommand_x                              0x532440

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x682680
#define CGaugeWnd__CalcLinesFillRect_x                             0x6826E0
#define CGaugeWnd__Draw_x                                          0x682B10

// CGuild
#define CGuild__FindMemberByName_x                                 0x424800

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69F810

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6AD5C0
#define CInvSlotMgr__MoveItem_x                                    0x6AE500
#define CInvSlotMgr__SelectSlot_x                                  0x6AD670

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6ACA50
#define CInvSlot__SliderComplete_x                                 0x6AA420
#define CInvSlot__GetItemBase_x                                    0x6A98B0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6AF690

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7779F0
#define CItemDisplayWnd__UpdateStrings_x                           0x6B09C0

// CLabel 
#define CLabel__Draw_x                                             0x6CB6A0

// CListWnd
#define CListWnd__CListWnd_x                                       0x887080
#define CListWnd__dCListWnd_x                                      0x888100
#define CListWnd__AddColumn_x                                      0x8880A0
#define CListWnd__AddColumn1_x                                     0x887890
#define CListWnd__AddLine_x                                        0x887340
#define CListWnd__AddString_x                                      0x887550
#define CListWnd__CalculateFirstVisibleLine_x                      0x8843D0
#define CListWnd__CalculateVSBRange_x                              0x886530
#define CListWnd__ClearAllSel_x                                    0x883690
#define CListWnd__CloseAndUpdateEditWindow_x                       0x886F10
#define CListWnd__Compare_x                                        0x884EC0
#define CListWnd__Draw_x                                           0x886140
#define CListWnd__DrawColumnSeparators_x                           0x885FD0
#define CListWnd__DrawHeader_x                                     0x8839A0
#define CListWnd__DrawItem_x                                       0x885510
#define CListWnd__DrawLine_x                                       0x885C70
#define CListWnd__DrawSeparator_x                                  0x886070
#define CListWnd__EnsureVisible_x                                  0x884530
#define CListWnd__ExtendSel_x                                      0x885420
#define CListWnd__GetColumnMinWidth_x                              0x8830B0
#define CListWnd__GetColumnWidth_x                                 0x882FD0
#define CListWnd__GetCurSel_x                                      0x8827A0
#define CListWnd__GetItemAtPoint_x                                 0x8847C0
#define CListWnd__GetItemAtPoint1_x                                0x884830
#define CListWnd__GetItemData_x                                    0x882AE0
#define CListWnd__GetItemHeight_x                                  0x884030
#define CListWnd__GetItemIcon_x                                    0x882CC0
#define CListWnd__GetItemRect_x                                    0x884600
#define CListWnd__GetItemText_x                                    0x882B70
#define CListWnd__GetSelList_x                                     0x887780
#define CListWnd__GetSeparatorRect_x                               0x884DE0
#define CListWnd__RemoveLine_x                                     0x887730
#define CListWnd__SetColors_x                                      0x8828F0
#define CListWnd__SetColumnJustification_x                         0x883380
#define CListWnd__SetColumnWidth_x                                 0x883060
#define CListWnd__SetCurSel_x                                      0x8827E0
#define CListWnd__SetItemColor_x                                   0x886BF0
#define CListWnd__SetItemData_x                                    0x883740
#define CListWnd__SetItemText_x                                    0x886A30
#define CListWnd__ShiftColumnSeparator_x                           0x8868C0
#define CListWnd__Sort_x                                           0x888200
#define CListWnd__ToggleSel_x                                      0x883610

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6E4C40

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x705DF0
#define CMerchantWnd__RequestBuyItem_x                             0x70CC50
#define CMerchantWnd__RequestSellItem_x                            0x70D6C0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7060A0
#define CMerchantWnd__SelectBuySellSlot_x                          0x705300
#define CMerchantWnd__ActualSelect_x                               0x709B70

// CObfuscator
#define CObfuscator__doit_x                                        0x801E10

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x89F860
#define CSidlManager__CreateLabel_x                                0x76DA20

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x630880
#define CSidlScreenWnd__CalculateVSBRange_x                        0x630760
#define CSidlScreenWnd__ConvertToRes_x                             0x8BBE90
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x88D1C0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x88E6B0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x88E760
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x88DC30
#define CSidlScreenWnd__DrawSidlPiece_x                            0x88CCA0
#define CSidlScreenWnd__EnableIniStorage_x                         0x88C3D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x88CE90
#define CSidlScreenWnd__Init1_x                                    0x88E390
#define CSidlScreenWnd__LoadIniInfo_x                              0x88D270
#define CSidlScreenWnd__LoadIniListWnd_x                           0x88C590
#define CSidlScreenWnd__LoadSidlScreen_x                           0x88DE80
#define CSidlScreenWnd__StoreIniInfo_x                             0x88BEA0
#define CSidlScreenWnd__StoreIniVis_x                              0x88C360
#define CSidlScreenWnd__WndNotification_x                          0x88E110
#define CSidlScreenWnd__GetChildItem_x                             0x88C4A0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x893060

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5CBE20
#define CSkillMgr__GetSkillCap_x                                   0x5CBFC0
#define CSkillMgr__GetNameToken_x                                  0x5CBA90

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8C5F60
#define CSliderWnd__SetValue_x                                     0x8C6130
#define CSliderWnd__SetNumTicks_x                                  0x8C68B0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x775690

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8B6260
#define CStmlWnd__CalculateHSBRange_x                              0x8AE770
#define CStmlWnd__CalculateVSBRange_x                              0x8AE800
#define CStmlWnd__CanBreakAtCharacter_x                            0x8AE980
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8AF260
#define CStmlWnd__ForceParseNow_x                                  0x8B6BB0
#define CStmlWnd__GetNextTagPiece_x                                0x8AF160
#define CStmlWnd__GetSTMLText_x                                    0x667780
#define CStmlWnd__GetVisibleText_x                                 0x8AFCB0
#define CStmlWnd__InitializeWindowVariables_x                      0x8B2040
#define CStmlWnd__MakeStmlColorTag_x                               0x8ADA70
#define CStmlWnd__MakeWndNotificationTag_x                         0x8ADAD0
#define CStmlWnd__SetSTMLText_x                                    0x8B38B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8B5F00
#define CStmlWnd__UpdateHistoryString_x                            0x8B0BF0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8BD680
#define CTabWnd__DrawCurrentPage_x                                 0x8BCEF0
#define CTabWnd__DrawTab_x                                         0x8BCCC0
#define CTabWnd__GetCurrentPage_x                                  0x8BD2C0
#define CTabWnd__GetPageInnerRect_x                                0x8BC9B0
#define CTabWnd__GetTabInnerRect_x                                 0x8BCBB0
#define CTabWnd__GetTabRect_x                                      0x8BCA80
#define CTabWnd__InsertPage_x                                      0x8BD970
#define CTabWnd__SetPage_x                                         0x8BD2F0
#define CTabWnd__SetPageRect_x                                     0x8BD5C0
#define CTabWnd__UpdatePage_x                                      0x8BD910

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x420540

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B96F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8C28D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x880A50

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4117B0
#define CXStr__CXStr1_x                                            0x7ABE70
#define CXStr__CXStr3_x                                            0x837E20
#define CXStr__dCXStr_x                                            0x891B40
#define CXStr__operator_equal_x                                    0x837F90
#define CXStr__operator_equal1_x                                   0x837FE0
#define CXStr__operator_plus_equal1_x                              0x8390C0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x892250
#define CXWnd__Center_x                                            0x898550
#define CXWnd__ClrFocus_x                                          0x891E30
#define CXWnd__DoAllDrawing_x                                      0x8981A0
#define CXWnd__DrawChildren_x                                      0x898340
#define CXWnd__DrawColoredRect_x                                   0x892610
#define CXWnd__DrawTooltip_x                                       0x8928C0
#define CXWnd__DrawTooltipAtPoint_x                                0x897120
#define CXWnd__GetBorderFrame_x                                    0x892D20
#define CXWnd__GetChildWndAt_x                                     0x8960B0
#define CXWnd__GetClientClipRect_x                                 0x892AD0
#define CXWnd__GetScreenClipRect_x                                 0x897810
#define CXWnd__GetScreenRect_x                                     0x892EF0
#define CXWnd__GetTooltipRect_x                                    0x892750
#define CXWnd__GetWindowTextA_x                                    0x4117F0
#define CXWnd__IsActive_x                                          0x8A5910
#define CXWnd__IsDescendantOf_x                                    0x892C60
#define CXWnd__IsReallyVisible_x                                   0x896090
#define CXWnd__IsType_x                                            0x8BF060
#define CXWnd__Move_x                                              0x895760
#define CXWnd__Move1_x                                             0x897E50
#define CXWnd__ProcessTransition_x                                 0x8921F0
#define CXWnd__Refade_x                                            0x891FC0
#define CXWnd__Resize_x                                            0x892FC0
#define CXWnd__Right_x                                             0x897610
#define CXWnd__SetFocus_x                                          0x8948A0
#define CXWnd__SetFont_x                                           0x891E80
#define CXWnd__SetKeyTooltip_x                                     0x893230
#define CXWnd__SetMouseOver_x                                      0x897B40
#define CXWnd__StartFade_x                                         0x8922A0
#define CXWnd__GetChildItem_x                                      0x897A90

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A7240
#define CXWndManager__DrawWindows_x                                0x8A6E80
#define CXWndManager__GetKeyboardFlags_x                           0x8A5440
#define CXWndManager__HandleKeyboardMsg_x                          0x8A5DB0
#define CXWndManager__RemoveWnd_x                                  0x8A5AA0

// CDBStr
#define CDBStr__GetString_x                                        0x488850

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x43C810
#define EQ_Character__Cur_HP_x                                     0x452540
#define EQ_Character__GetAACastingTimeModifier_x                   0x435910
#define EQ_Character__GetCharInfo2_x                               0x80C570
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42DC50
#define EQ_Character__GetFocusRangeModifier_x                      0x42DE30
#define EQ_Character__Max_Endurance_x                              0x5946D0
#define EQ_Character__Max_HP_x                                     0x448840
#define EQ_Character__Max_Mana_x                                   0x594500
#define EQ_Character__doCombatAbility_x                            0x591AF0
#define EQ_Character__UseSkill_x                                   0x45D070
#define EQ_Character__GetConLevel_x                                0x586F40
#define EQ_Character__IsExpansionFlag_x                            0x410CF0
#define EQ_Character__TotalEffect_x                                0x43A940

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x567740
#define EQ_Item__CreateItemTagString_x                             0x7EC840
#define EQ_Item__IsStackable_x                                     0x7E0A60
#define EQ_Item__GetImageNum_x                                     0x7E36E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A8010
#define EQ_LoadingS__Array_x                                       0xB75FB8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x595E60
#define EQ_PC__GetAltAbilityIndex_x                                0x7F4BA0
#define EQ_PC__GetCombatAbility_x                                  0x7F4C30
#define EQ_PC__GetCombatAbilityTimer_x                             0x7F4CE0
#define EQ_PC__GetItemTimerValue_x                                 0x58F8D0
#define EQ_PC__HasLoreItem_x                                       0x58A210
#define EQ_PC__AlertInventoryChanged_x                             0x586F10
#define EQ_PC__GetPcZoneClient_x                                   0x5B01F0
#define EQ_PC__RemoveMyAffect_x									   0x58EDE0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E51C0
#define EQItemList__add_item_x                                     0x4E5100
#define EQItemList__delete_item_x                                  0x4E55C0
#define EQItemList__FreeItemList_x                                 0x4E54C0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487A70

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x59B320
#define EQPlayer__dEQPlayer_x                                      0x5A40B0
#define EQPlayer__DoAttack_x                                       0x5B5FF0
#define EQPlayer__EQPlayer_x                                       0x5A64D0
#define EQPlayer__SetNameSpriteState_x                             0x5A0DE0
#define EQPlayer__SetNameSpriteTint_x                              0x59C6F0
#define EQPlayer__IsBodyType_j_x                                   0x8F5480
#define EQPlayer__IsTargetable_x                                   0x8F5CF0
#define EQPlayer__CanSee_x                                         0x8F6210

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5AA7A0
#define EQPlayerManager__GetSpawnByName_x                          0x5AAC00

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56D860
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56D8A0
#define KeypressHandler__ClearCommandStateArray_x                  0x56D440
#define KeypressHandler__HandleKeyDown_x                           0x56BDA0
#define KeypressHandler__HandleKeyUp_x                             0x56C0C0
#define KeypressHandler__SaveKeymapping_x                          0x56D510

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6DD020
#define MapViewMap__SaveEx_x                                       0x6E0900

#define PlayerPointManager__GetAltCurrency_x                       0x806760

// StringTable 
#define StringTable__getString_x                                   0x8020B0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x594180

//Doors
#define EQSwitch__UseSwitch_x                                      0x5237C0

//IconCache
#define IconCache__GetIcon_x                                       0x677F70

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66EDF0
#define CContainerMgr__CloseContainer_x                            0x66F610

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x73DEF0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x560A40

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B6490
#define EQ_Spell__SpellAffects_x                                   0x4B6530
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B6560
#define CharacterZoneClient__CalcAffectChange_x                    0x436C30
#define CLootWnd__LootAll_x                                        0x6D29D0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7834D0
#define CTargetWnd__WndNotification_x                              0x782FC0
