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
#define __ExpectedVersionDate                                     "Jan 14 2015"
#define __ExpectedVersionTime                                     "09:58:12"
#define __ActualVersionDate_x                                      0xA567E8
#define __ActualVersionTime_x                                      0xA567F4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x573670
#define __MemChecker1_x                                            0x83B3E0
#define __MemChecker2_x                                            0x60B290
#define __MemChecker3_x                                            0x60B1E0
#define __MemChecker4_x                                            0x7BF660
#define __EncryptPad0_x                                            0xBC4208
#define __EncryptPad1_x                                            0xD43DC0
#define __EncryptPad2_x                                            0xC0C490
#define __EncryptPad3_x                                            0xC0C090
#define __EncryptPad4_x                                            0xD20C48
#define __AC1_x                                                    0x77CB25
#define __AC2_x                                                    0x529B27
#define __AC3_x                                                    0x53E270
#define __AC4_x                                                    0x5445A0
#define __AC5_x                                                    0x55030E
#define __AC6_x                                                    0x553E42
#define __AC7_x                                                    0x54A9FC
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
#define __do_loot_x                                                0x4F16B0
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
#define pinstCamActor_x                                            0xEA3970
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
#define pinstViewActor_x                                           0xEA396C
#define pinstWorldData_x                                           0xF56AA8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD67A58
#define pinstCAudioTriggersWindow_x                                0xD678E8
#define pinstCCharacterSelect_x                                    0xEA3818
#define pinstCFacePick_x                                           0xEA37C8
#define pinstCNoteWnd_x                                            0xEA37D0
#define pinstCBookWnd_x                                            0xEA37D8
#define pinstCPetInfoWnd_x                                         0xEA37DC
#define pinstCTrainWnd_x                                           0xEA37E0
#define pinstCSkillsWnd_x                                          0xEA37E4
#define pinstCSkillsSelectWnd_x                                    0xEA37E8
#define pinstCCombatSkillSelectWnd_x                               0xEA37EC
#define pinstCFriendsWnd_x                                         0xEA37F0
#define pinstCAuraWnd_x                                            0xEA37F4
#define pinstCRespawnWnd_x                                         0xEA37F8
#define pinstCBandolierWnd_x                                       0xEA37FC
#define pinstCPotionBeltWnd_x                                      0xEA3800
#define pinstCAAWnd_x                                              0xEA3804
#define pinstCGroupSearchFiltersWnd_x                              0xEA3808
#define pinstCLoadskinWnd_x                                        0xEA380C
#define pinstCAlarmWnd_x                                           0xEA3810
#define pinstCMusicPlayerWnd_x                                     0xEA3814
#define pinstCMailWnd_x                                            0xEA381C
#define pinstCMailCompositionWnd_x                                 0xEA3820
#define pinstCMailAddressBookWnd_x                                 0xEA3824
#define pinstCRaidWnd_x                                            0xEA382C
#define pinstCRaidOptionsWnd_x                                     0xEA3830
#define pinstCBreathWnd_x                                          0xEA3834
#define pinstCMapViewWnd_x                                         0xEA3838
#define pinstCMapToolbarWnd_x                                      0xEA383C
#define pinstCEditLabelWnd_x                                       0xEA3840
#define pinstCTargetWnd_x                                          0xEA3844
#define pinstCColorPickerWnd_x                                     0xEA3848
#define pinstCPlayerWnd_x                                          0xEA384C
#define pinstCOptionsWnd_x                                         0xEA3850
#define pinstCBuffWindowNORMAL_x                                   0xEA3854
#define pinstCBuffWindowSHORT_x                                    0xEA3858
#define pinstCharacterCreation_x                                   0xEA385C
#define pinstCCursorAttachment_x                                   0xEA3860
#define pinstCCastingWnd_x                                         0xEA3864
#define pinstCCastSpellWnd_x                                       0xEA3868
#define pinstCSpellBookWnd_x                                       0xEA386C
#define pinstCInventoryWnd_x                                       0xEA3870
#define pinstCBankWnd_x                                            0xEA3874
#define pinstCQuantityWnd_x                                        0xEA3878
#define pinstCLootWnd_x                                            0xEA387C
#define pinstCActionsWnd_x                                         0xEA3880
#define pinstCCombatAbilityWnd_x                                   0xEA3884
#define pinstCMerchantWnd_x                                        0xEA3888
#define pinstCTradeWnd_x                                           0xEA388C
#define pinstCSelectorWnd_x                                        0xEA3890
#define pinstCBazaarWnd_x                                          0xEA3894
#define pinstCBazaarSearchWnd_x                                    0xEA3898
#define pinstCGiveWnd_x                                            0xEA38B4
#define pinstCTrackingWnd_x                                        0xEA38BC
#define pinstCInspectWnd_x                                         0xEA38C0
#define pinstCSocialEditWnd_x                                      0xEA38C4
#define pinstCFeedbackWnd_x                                        0xEA38C8
#define pinstCBugReportWnd_x                                       0xEA38CC
#define pinstCVideoModesWnd_x                                      0xEA38D0
#define pinstCTextEntryWnd_x                                       0xEA38D8
#define pinstCFileSelectionWnd_x                                   0xEA38DC
#define pinstCCompassWnd_x                                         0xEA38E0
#define pinstCPlayerNotesWnd_x                                     0xEA38E4
#define pinstCGemsGameWnd_x                                        0xEA38E8
#define pinstCTimeLeftWnd_x                                        0xEA38EC
#define pinstCPetitionQWnd_x                                       0xEA3900
#define pinstCSoulmarkWnd_x                                        0xEA3904
#define pinstCStoryWnd_x                                           0xEA3908
#define pinstCJournalTextWnd_x                                     0xEA390C
#define pinstCJournalCatWnd_x                                      0xEA3910
#define pinstCBodyTintWnd_x                                        0xEA3914
#define pinstCServerListWnd_x                                      0xEA3918
#define pinstCAvaZoneWnd_x                                         0xEA3924
#define pinstCBlockedBuffWnd_x                                     0xEA3928
#define pinstCBlockedPetBuffWnd_x                                  0xEA392C
#define pinstCInvSlotMgr_x                                         0xEA3964
#define pinstCContainerMgr_x                                       0xEA3968
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
#define __CastRay_x                                                0x509010
#define __ConvertItemTags_x                                        0x4F62A0
#define __ExecuteCmd_x                                             0x4E0E60
#define __EQGetTime_x                                              0x83BF40
#define __get_melee_range_x                                        0x4E7B70
#define __GetGaugeValueFromEQ_x                                    0x77B870
#define __GetLabelFromEQ_x                                         0x77CAB0
#define __ToggleMount_x                                            0x6A57F0
#define __GetXTargetType_x                                         0x8F9490
#define __LoadFrontEnd_x                                           0x60A940
#define __NewUIINI_x                                               0x77B170
#define __ProcessGameEvents_x                                      0x54C760
#define __ProcessMouseEvent_x                                      0x54BF00
#define CrashDetected_x                                            0x60C410
#define wwsCrashReportCheckForUploader_x                           0x7D0A40
#define DrawNetStatus_x                                            0x583280
#define Util__FastTime_x                                           0x83B250
#define Expansion_HoT_x                                            0xF64DC4
#define __HelpPath_x                                               0xFE84F8
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A5F90
#define AltAdvManager__IsAbilityReady_x                            0x4A6000
#define AltAdvManager__GetAltAbility_x                             0x4A63C0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x452EA0
#define CharacterZoneClient__MakeMeVisible_x                       0x457F60

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x63A2D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x648070

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x562780

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6634B0
#define CChatManager__InitContextMenu_x                            0x663FD0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x88B0A0
#define CContextMenu__AddMenuItem_x                                0x88B2C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x822040
#define CChatService__GetFriendName_x                              0x822050

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x668E20
#define CChatWindow__Clear_x                                       0x6689D0
#define CChatWindow__WndNotification_x                             0x669350

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x89A760
#define CComboWnd__Draw_x                                          0x89A960
#define CComboWnd__GetCurChoice_x                                  0x89A580
#define CComboWnd__GetListRect_x                                   0x89AC00
#define CComboWnd__GetTextRect_x                                   0x89A7C0
#define CComboWnd__InsertChoice_x                                  0x89AC70
#define CComboWnd__SetColors_x                                     0x89A510
#define CComboWnd__SetChoice_x                                     0x89A540

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x672630
#define CContainerWnd__vftable_x                                   0xA5FF60

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x494960
#define CDisplay__GetClickedActor_x                                0x48D4F0
#define CDisplay__GetUserDefinedColor_x                            0x48BDB0
#define CDisplay__GetWorldFilePath_x                               0x48B200
#define CDisplay__is3dON_x                                         0x48A5D0
#define CDisplay__ReloadUI_x                                       0x49FBE0
#define CDisplay__WriteTextHD2_x                                   0x490D00

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8BC5A0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8AB150
#define CEditWnd__GetCharIndexPt_x                                 0x8AC170
#define CEditWnd__GetDisplayString_x                               0x8AB300
#define CEditWnd__GetHorzOffset_x                                  0x8AB640
#define CEditWnd__GetLineForPrintableChar_x                        0x8ABC40
#define CEditWnd__GetSelStartPt_x                                  0x8AC420
#define CEditWnd__GetSTMLSafeText_x                                0x8AB7E0
#define CEditWnd__PointFromPrintableChar_x                         0x8ABD30
#define CEditWnd__SelectableCharFromPoint_x                        0x8ABEB0
#define CEditWnd__SetEditable_x                                    0x8AB7B0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x52A270
#define CEverQuest__DoTellWindow_x                                 0x52FC60
#define CEverQuest__DropHeldItemOnGround_x                         0x5386F0
#define CEverQuest__dsp_chat_x                                     0x531400
#define CEverQuest__Emote_x                                        0x531660
#define CEverQuest__EnterZone_x                                    0x544DC0
#define CEverQuest__GetBodyTypeDesc_x                              0x526BA0
#define CEverQuest__GetClassDesc_x                                 0x52C7E0
#define CEverQuest__GetClassThreeLetterCode_x                      0x52CDE0
#define CEverQuest__GetDeityDesc_x                                 0x527480
#define CEverQuest__GetLangDesc_x                                  0x526F30
#define CEverQuest__GetRaceDesc_x                                  0x52CFA0
#define CEverQuest__InterpretCmd_x                                 0x531F40
#define CEverQuest__LeftClickedOnPlayer_x                          0x548E60
#define CEverQuest__LMouseUp_x                                     0x54AF50
#define CEverQuest__RightClickedOnPlayer_x                         0x549960
#define CEverQuest__RMouseUp_x                                     0x54A9B0
#define CEverQuest__SetGameState_x                                 0x52A920
#define CEverQuest__UPCNotificationFlush_x                         0x5330E0
#define CEverQuest__IssuePetCommand_x                              0x532C40

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x683180
#define CGaugeWnd__CalcLinesFillRect_x                             0x6831E0
#define CGaugeWnd__Draw_x                                          0x683610

// CGuild
#define CGuild__FindMemberByName_x                                 0x424860

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6A0230

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6AE020
#define CInvSlotMgr__MoveItem_x                                    0x6AEF60
#define CInvSlotMgr__SelectSlot_x                                  0x6AE0D0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6AD4C0
#define CInvSlot__SliderComplete_x                                 0x6AAE80
#define CInvSlot__GetItemBase_x                                    0x6AA300

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6B0120

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x778350
#define CItemDisplayWnd__UpdateStrings_x                           0x6B1460

// CLabel 
#define CLabel__Draw_x                                             0x6CC080

// CListWnd 
#define CListWnd__AddColumn_x                                      0x888770
#define CListWnd__AddColumn1_x                                     0x887F50
#define CListWnd__AddLine_x                                        0x887A00
#define CListWnd__AddString_x                                      0x887C10
#define CListWnd__CalculateFirstVisibleLine_x                      0x884A60
#define CListWnd__CalculateVSBRange_x                              0x886BF0
#define CListWnd__ClearAllSel_x                                    0x883D10
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8875D0
#define CListWnd__Compare_x                                        0x885570
#define CListWnd__Draw_x                                           0x886800
#define CListWnd__DrawColumnSeparators_x                           0x886690
#define CListWnd__DrawHeader_x                                     0x884020
#define CListWnd__DrawItem_x                                       0x885BC0
#define CListWnd__DrawLine_x                                       0x886330
#define CListWnd__DrawSeparator_x                                  0x886730
#define CListWnd__EnsureVisible_x                                  0x884BC0
#define CListWnd__ExtendSel_x                                      0x885AD0
#define CListWnd__GetColumnMinWidth_x                              0x883730
#define CListWnd__GetColumnWidth_x                                 0x883650
#define CListWnd__GetCurSel_x                                      0x882E20
#define CListWnd__GetItemAtPoint_x                                 0x884E60
#define CListWnd__GetItemAtPoint1_x                                0x884ED0
#define CListWnd__GetItemData_x                                    0x883160
#define CListWnd__GetItemHeight_x                                  0x8846B0
#define CListWnd__GetItemIcon_x                                    0x883340
#define CListWnd__GetItemRect_x                                    0x884CA0
#define CListWnd__GetItemText_x                                    0x8831F0
#define CListWnd__GetSelList_x                                     0x887E40
#define CListWnd__GetSeparatorRect_x                               0x885490
#define CListWnd__RemoveLine_x                                     0x887DF0
#define CListWnd__SetColors_x                                      0x882F70
#define CListWnd__SetColumnJustification_x                         0x883A00
#define CListWnd__SetColumnWidth_x                                 0x8836E0
#define CListWnd__SetCurSel_x                                      0x882E60
#define CListWnd__SetItemColor_x                                   0x8872B0
#define CListWnd__SetItemData_x                                    0x883DC0
#define CListWnd__SetItemText_x                                    0x8870F0
#define CListWnd__ShiftColumnSeparator_x                           0x886F80
#define CListWnd__Sort_x                                           0x8888D0
#define CListWnd__ToggleSel_x                                      0x883C90

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6E5570

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7067F0
#define CMerchantWnd__RequestBuyItem_x                             0x70D5E0
#define CMerchantWnd__RequestSellItem_x                            0x70E030
#define CMerchantWnd__SelectRecoverySlot_x                         0x706AA0
#define CMerchantWnd__SelectBuySellSlot_x                          0x705D00
#define CMerchantWnd__ActualSelect_x                               0x70A520

// CObfuscator
#define CObfuscator__doit_x                                        0x802500

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x89FF10
#define CSidlManager__CreateLabel_x                                0x76E310

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x631590
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6314B0
#define CSidlScreenWnd__ConvertToRes_x                             0x8BC480
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x88D8A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x88EDA0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x88EE50
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x88E300
#define CSidlScreenWnd__DrawSidlPiece_x                            0x88D380
#define CSidlScreenWnd__EnableIniStorage_x                         0x88CAB0
#define CSidlScreenWnd__GetSidlPiece_x                             0x88D570
#define CSidlScreenWnd__Init1_x                                    0x88EA70
#define CSidlScreenWnd__LoadIniInfo_x                              0x88D950
#define CSidlScreenWnd__LoadIniListWnd_x                           0x88CC70
#define CSidlScreenWnd__LoadSidlScreen_x                           0x88E550
#define CSidlScreenWnd__StoreIniInfo_x                             0x88C580
#define CSidlScreenWnd__StoreIniVis_x                              0x88CA40
#define CSidlScreenWnd__WndNotification_x                          0x88E7F0
#define CSidlScreenWnd__GetChildItem_x                             0x88CB80
#define CSidlScreenWnd__HandleLButtonUp_x                          0x893740

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5CCA10
#define CSkillMgr__GetSkillCap_x                                   0x5CCBB0
#define CSkillMgr__GetNameToken_x                                  0x5CC680

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8C6450
#define CSliderWnd__SetValue_x                                     0x8C6620
#define CSliderWnd__SetNumTicks_x                                  0x8C6DA0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x775FF0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8B6870
#define CStmlWnd__CalculateHSBRange_x                              0x8AEE00
#define CStmlWnd__CalculateVSBRange_x                              0x8AED70
#define CStmlWnd__CanBreakAtCharacter_x                            0x8AEF80
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8AF860
#define CStmlWnd__ForceParseNow_x                                  0x8B71C0
#define CStmlWnd__GetNextTagPiece_x                                0x8AF760
#define CStmlWnd__GetSTMLText_x                                    0x668270
#define CStmlWnd__GetVisibleText_x                                 0x8B02B0
#define CStmlWnd__InitializeWindowVariables_x                      0x8B2640
#define CStmlWnd__MakeStmlColorTag_x                               0x8AE070
#define CStmlWnd__MakeWndNotificationTag_x                         0x8AE0D0
#define CStmlWnd__SetSTMLText_x                                    0x8B3EB0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8B6510
#define CStmlWnd__UpdateHistoryString_x                            0x8B11F0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8BDC70
#define CTabWnd__DrawCurrentPage_x                                 0x8BD4E0
#define CTabWnd__DrawTab_x                                         0x8BD2A0
#define CTabWnd__GetCurrentPage_x                                  0x8BD8B0
#define CTabWnd__GetPageInnerRect_x                                0x8BCF90
#define CTabWnd__GetTabInnerRect_x                                 0x8BD190
#define CTabWnd__GetTabRect_x                                      0x8BD060
#define CTabWnd__InsertPage_x                                      0x8BDF60
#define CTabWnd__SetPage_x                                         0x8BD8E0
#define CTabWnd__SetPageRect_x                                     0x8BDBB0
#define CTabWnd__UpdatePage_x                                      0x8BDF00

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x420570

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B9CE0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8C2E10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x880F30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4118F0
#define CXStr__CXStr1_x                                            0x875D00
#define CXStr__CXStr3_x                                            0x8382E0
#define CXStr__dCXStr_x                                            0x779410
#define CXStr__operator_equal_x                                    0x838450
#define CXStr__operator_equal1_x                                   0x8384A0
#define CXStr__operator_plus_equal1_x                              0x839580

// CXWnd 
#define CXWnd__BringToTop_x                                        0x892960
#define CXWnd__Center_x                                            0x898B80
#define CXWnd__ClrFocus_x                                          0x892550
#define CXWnd__DoAllDrawing_x                                      0x8987E0
#define CXWnd__DrawChildren_x                                      0x898980
#define CXWnd__DrawColoredRect_x                                   0x892D20
#define CXWnd__DrawTooltip_x                                       0x892FD0
#define CXWnd__DrawTooltipAtPoint_x                                0x897750
#define CXWnd__GetBorderFrame_x                                    0x893420
#define CXWnd__GetChildWndAt_x                                     0x896700
#define CXWnd__GetClientClipRect_x                                 0x8931D0
#define CXWnd__GetScreenClipRect_x                                 0x897E50
#define CXWnd__GetScreenRect_x                                     0x8935F0
#define CXWnd__GetTooltipRect_x                                    0x892E60
#define CXWnd__GetWindowTextA_x                                    0x411930
#define CXWnd__IsActive_x                                          0x8A5ED0
#define CXWnd__IsDescendantOf_x                                    0x893360
#define CXWnd__IsReallyVisible_x                                   0x8966E0
#define CXWnd__IsType_x                                            0x8BF610
#define CXWnd__Move_x                                              0x895E30
#define CXWnd__Move1_x                                             0x898490
#define CXWnd__ProcessTransition_x                                 0x892900
#define CXWnd__Refade_x                                            0x8926E0
#define CXWnd__Resize_x                                            0x8936B0
#define CXWnd__Right_x                                             0x897C50
#define CXWnd__SetFocus_x                                          0x894F90
#define CXWnd__SetFont_x                                           0x8925A0
#define CXWnd__SetKeyTooltip_x                                     0x893910
#define CXWnd__SetMouseOver_x                                      0x898180
#define CXWnd__StartFade_x                                         0x8929B0
#define CXWnd__GetChildItem_x                                      0x8980C0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A7800
#define CXWndManager__DrawWindows_x                                0x8A7440
#define CXWndManager__GetKeyboardFlags_x                           0x8A5A00
#define CXWndManager__HandleKeyboardMsg_x                          0x8A6370
#define CXWndManager__RemoveWnd_x                                  0x8A6060

// CDBStr
#define CDBStr__GetString_x                                        0x4889E0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x43C860
#define EQ_Character__Cur_HP_x                                     0x452560
#define EQ_Character__GetAACastingTimeModifier_x                   0x435930
#define EQ_Character__GetCharInfo2_x                               0x80CB50
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42DCA0
#define EQ_Character__GetFocusRangeModifier_x                      0x42DE80
#define EQ_Character__Max_Endurance_x                              0x5950B0
#define EQ_Character__Max_HP_x                                     0x448860
#define EQ_Character__Max_Mana_x                                   0x594EE0
#define EQ_Character__doCombatAbility_x                            0x5924D0
#define EQ_Character__UseSkill_x                                   0x45D0A0
#define EQ_Character__GetConLevel_x                                0x587890
#define EQ_Character__IsExpansionFlag_x                            0x410E40
#define EQ_Character__TotalEffect_x                                0x43A990

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x567F20
#define EQ_Item__CreateItemTagString_x                             0x7ECF20
#define EQ_Item__IsStackable_x                                     0x7E1390
#define EQ_Item__GetImageNum_x                                     0x7E3FD0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A80E0
#define EQ_LoadingS__Array_x                                       0xB75FB8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x596850
#define EQ_PC__GetAltAbilityIndex_x                                0x7F52B0
#define EQ_PC__GetCombatAbility_x                                  0x7F5340
#define EQ_PC__GetCombatAbilityTimer_x                             0x7F53F0
#define EQ_PC__GetItemTimerValue_x                                 0x5902A0
#define EQ_PC__HasLoreItem_x                                       0x58AB60
#define EQ_PC__AlertInventoryChanged_x                             0x587860
#define EQ_PC__GetPcZoneClient_x                                   0x5B0D30
#define EQ_PC__RemoveMyAffect_x                                    0x58F7B0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E5AF0
#define EQItemList__add_item_x                                     0x4E5A30
#define EQItemList__delete_item_x                                  0x4E5EF0
#define EQItemList__FreeItemList_x                                 0x4E5DF0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487DA0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x59BD10
#define EQPlayer__dEQPlayer_x                                      0x5A4AA0
#define EQPlayer__DoAttack_x                                       0x5B6B40
#define EQPlayer__EQPlayer_x                                       0x5A6EC0
#define EQPlayer__SetNameSpriteState_x                             0x5A17D0
#define EQPlayer__SetNameSpriteTint_x                              0x59D0E0
#define EQPlayer__IsBodyType_j_x                                   0x8F5760
#define EQPlayer__IsTargetable_x                                   0x8F5FD0
#define EQPlayer__CanSee_x                                         0x8F64F0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5AB2E0
#define EQPlayerManager__GetSpawnByName_x                          0x5AB740

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56E0B0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56E0F0
#define KeypressHandler__ClearCommandStateArray_x                  0x56DC90
#define KeypressHandler__HandleKeyDown_x                           0x56C5F0
#define KeypressHandler__HandleKeyUp_x                             0x56C910
#define KeypressHandler__SaveKeymapping_x                          0x56DD60

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6DD950
#define MapViewMap__SaveEx_x                                       0x6E1230

#define PlayerPointManager__GetAltCurrency_x                       0x806D30

// StringTable 
#define StringTable__getString_x                                   0x8027A0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x594B60

//Doors
#define EQSwitch__UseSwitch_x                                      0x523F20

//IconCache
#define IconCache__GetIcon_x                                       0x678AA0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66F940
#define CContainerMgr__CloseContainer_x                            0x670160

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x73E850

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x561240

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B6620
#define EQ_Spell__SpellAffects_x                                   0x4B66C0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B66F0
#define CharacterZoneClient__CalcAffectChange_x                    0x436C50
#define CLootWnd__LootAll_x                                        0x6D3220
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x783E50
#define CTargetWnd__WndNotification_x                              0x783940
