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
#define __ExpectedVersionDate                                     "Dec  3 2014"
#define __ExpectedVersionTime                                     "16:20:23"
#define __ActualVersionDate_x                                      0xA578D0
#define __ActualVersionTime_x                                      0xA578DC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x574280
#define __MemChecker1_x                                            0x83BD40
#define __MemChecker2_x                                            0x60B850
#define __MemChecker3_x                                            0x60B7A0
#define __MemChecker4_x                                            0x7BFCA0
#define __EncryptPad0_x                                            0xBC3790
#define __EncryptPad1_x                                            0xD3ED00
#define __EncryptPad2_x                                            0xC0AD40
#define __EncryptPad3_x                                            0xC0A940
#define __EncryptPad4_x                                            0xD1C3E8
#define __AC1_x                                                    0x77D155
#define __AC2_x                                                    0x52A107
#define __AC3_x                                                    0x53E7D0
#define __AC4_x                                                    0x544B00
#define __AC5_x                                                    0x550F6E
#define __AC6_x                                                    0x554AA2
#define __AC7_x                                                    0x54B65C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10F0050
#define DI8__Keyboard_x                                            0x10F0054
#define DI8__Mouse_x                                               0x10F0058
#define __AltTimerReady_x                                          0xF4FAE1
#define __Attack_x                                                 0xFE2BF7
#define __Autofire_x                                               0xFE2BF8
#define __BindList_x                                               0xB876A8
#define __bCommandEnabled_x                                        0xF4DBF0
#define __Clicks_x                                                 0xF5E728
#define __CommandList_x                                            0xB8B7F0
#define __CurrentMapLabel_x                                        0x10F5AA8
#define __CurrentSocial_x                                          0xB4CFCC
#define __DoAbilityList_x                                          0xF94EAC
#define __do_loot_x                                                0x4F1960
#define __DrawHandler_x                                            0x175A6BC
#define __GroupCount_x                                             0xF4F1BA

#define __Guilds_x                                                 0xF54CA8
#define __gWorld_x                                                 0xF51674
#define __HotkeyPage_x                                             0xFDB8AC
#define __HWnd_x                                                   0xFE7F58
#define __InChatMode_x                                             0xF5E654
#define __LastTell_x                                               0xF605B4
#define __LMouseHeldTime_x                                         0xF5E794
#define __Mouse_x                                                  0x10F005C
#define __MouseLook_x                                              0xF5E6EE
#define __MouseEventTime_x                                         0xFE33E4
#define __NetStatusToggle_x                                        0xF5E6F1
#define __PCNames_x                                                0xF5FBE4
#define __RangeAttackReady_x                                       0xF5F878
#define __RMouseHeldTime_x                                         0xF5E790
#define __RunWalkState_x                                           0xF5E658
#define __ScreenMode_x                                             0xE9DBB0
#define __ScreenX_x                                                0xF5E60C
#define __ScreenY_x                                                0xF5E608
#define __ScreenXMax_x                                             0xF5E610
#define __ScreenYMax_x                                             0xF5E614
#define __ServerHost_x                                             0xF4F104
#define __ServerName_x                                             0xF94E6C
#define __ShiftKeyDown_x                                           0xF5ECFC
#define __ShowNames_x                                              0xF5FA88
#define __Socials_x                                                0xF94F6C
#define __SubscriptionType_x                                       0x1121E38
#define __TargetAggroHolder_x                                      0x10F7CE4
#define __GroupAggro_x                                             0x10F7D24
#define __LoginName_x                                              0xFE6B30
#define __Inviter_x                                                0xFE2B74


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF51760
#define instEQZoneInfo_x                                           0xF5E8E4
#define instKeypressHandler_x                                      0xFE33C8
#define pinstActiveBanker_x                                        0xF51718
#define pinstActiveCorpse_x                                        0xF5171C
#define pinstActiveGMaster_x                                       0xF51720
#define pinstActiveMerchant_x                                      0xF51714
#define pinstAggroInfo_x                                           0xD62198
#define pinstAltAdvManager_x                                       0xE9EC88
#define pinstAuraMgr_x                                             0xD6C060
#define pinstBandageTarget_x                                       0xF51700
#define pinstCamActor_x                                            0xE9E594
#define pinstCDBStr_x                                              0xE9DB44
#define pinstCDisplay_x                                            0xF51728
#define pinstCEverQuest_x                                          0x10F01D4
#define pinstCharData_x                                            0xF516E4
#define pinstCharSpawn_x                                           0xF5170C
#define pinstControlledMissile_x                                   0xF516E0
#define pinstControlledPlayer_x                                    0xF5170C
#define pinstCSidlManager_x                                        0x1759AD0
#define pinstCXWndManager_x                                        0x1759AC8
#define instDynamicZone_x                                          0xF5E4A0
#define pinstDZMember_x                                            0xF5E5B0
#define pinstDZTimerInfo_x                                         0xF5E5B4
#define pinstEQItemList_x                                          0xF4DE3C
#define instEQMisc_x                                               0xB68A68
#define pinstEQSoundManager_x                                      0xE9EF88
#define instExpeditionLeader_x                                     0xF5E4EA
#define instExpeditionName_x                                       0xF5E52A
#define pinstGroup_x                                               0xF4F1B6
#define pinstImeManager_x                                          0x1759AD4
#define pinstLocalPlayer_x                                         0xF516F8
#define pinstMercenaryData_x                                       0xFE3A18
#define pinstMercAltAbilities_x                                    0xE9EEA8
#define pinstModelPlayer_x                                         0xF51724
#define pinstPCData_x                                              0xF516E4
#define pinstSkillMgr_x                                            0xFE4850
#define pinstSpawnManager_x                                        0xFE4138
#define pinstSpellManager_x                                        0xFE4998
#define pinstSpellSets_x                                           0xFDB910
#define pinstStringTable_x                                         0xF5168C
#define pinstSwitchManager_x                                       0xF4ED48
#define pinstTarget_x                                              0xF51710
#define pinstTargetObject_x                                        0xF516E8
#define pinstTargetSwitch_x                                        0xF516EC
#define pinstTaskMember_x                                          0xE9DA90
#define pinstTrackTarget_x                                         0xF51704
#define pinstTradeTarget_x                                         0xF516F4
#define instTributeActive_x                                        0xB68A8D
#define pinstViewActor_x                                           0xE9E590
#define pinstWorldData_x                                           0xF516C8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD62678
#define pinstCAudioTriggersWindow_x                                0xD62508
#define pinstCCharacterSelect_x                                    0xE9E43C
#define pinstCFacePick_x                                           0xE9E1EC
#define pinstCNoteWnd_x                                            0xE9E3F4
#define pinstCBookWnd_x                                            0xE9E3FC
#define pinstCPetInfoWnd_x                                         0xE9E400
#define pinstCTrainWnd_x                                           0xE9E404
#define pinstCSkillsWnd_x                                          0xE9E408
#define pinstCSkillsSelectWnd_x                                    0xE9E40C
#define pinstCCombatSkillSelectWnd_x                               0xE9E410
#define pinstCFriendsWnd_x                                         0xE9E414
#define pinstCAuraWnd_x                                            0xE9E418
#define pinstCRespawnWnd_x                                         0xE9E41C
#define pinstCBandolierWnd_x                                       0xE9E420
#define pinstCPotionBeltWnd_x                                      0xE9E424
#define pinstCAAWnd_x                                              0xE9E428
#define pinstCGroupSearchFiltersWnd_x                              0xE9E42C
#define pinstCLoadskinWnd_x                                        0xE9E430
#define pinstCAlarmWnd_x                                           0xE9E434
#define pinstCMusicPlayerWnd_x                                     0xE9E438
#define pinstCMailWnd_x                                            0xE9E440
#define pinstCMailCompositionWnd_x                                 0xE9E444
#define pinstCMailAddressBookWnd_x                                 0xE9E448
#define pinstCRaidWnd_x                                            0xE9E450
#define pinstCRaidOptionsWnd_x                                     0xE9E454
#define pinstCBreathWnd_x                                          0xE9E458
#define pinstCMapViewWnd_x                                         0xE9E45C
#define pinstCMapToolbarWnd_x                                      0xE9E460
#define pinstCEditLabelWnd_x                                       0xE9E464
#define pinstCTargetWnd_x                                          0xE9E468
#define pinstCColorPickerWnd_x                                     0xE9E46C
#define pinstCPlayerWnd_x                                          0xE9E470
#define pinstCOptionsWnd_x                                         0xE9E474
#define pinstCBuffWindowNORMAL_x                                   0xE9E478
#define pinstCBuffWindowSHORT_x                                    0xE9E47C
#define pinstCharacterCreation_x                                   0xE9E480
#define pinstCCursorAttachment_x                                   0xE9E484
#define pinstCCastingWnd_x                                         0xE9E488
#define pinstCCastSpellWnd_x                                       0xE9E48C
#define pinstCSpellBookWnd_x                                       0xE9E490
#define pinstCInventoryWnd_x                                       0xE9E494
#define pinstCBankWnd_x                                            0xE9E498
#define pinstCQuantityWnd_x                                        0xE9E49C
#define pinstCLootWnd_x                                            0xE9E4A0
#define pinstCActionsWnd_x                                         0xE9E4A4
#define pinstCCombatAbilityWnd_x                                   0xE9E4A8
#define pinstCMerchantWnd_x                                        0xE9E4AC
#define pinstCTradeWnd_x                                           0xE9E4B0
#define pinstCSelectorWnd_x                                        0xE9E4B4
#define pinstCBazaarWnd_x                                          0xE9E4B8
#define pinstCBazaarSearchWnd_x                                    0xE9E4BC
#define pinstCGiveWnd_x                                            0xE9E4D8
#define pinstCTrackingWnd_x                                        0xE9E4E0
#define pinstCInspectWnd_x                                         0xE9E4E4
#define pinstCSocialEditWnd_x                                      0xE9E4E8
#define pinstCFeedbackWnd_x                                        0xE9E4EC
#define pinstCBugReportWnd_x                                       0xE9E4F0
#define pinstCVideoModesWnd_x                                      0xE9E4F4
#define pinstCTextEntryWnd_x                                       0xE9E4FC
#define pinstCFileSelectionWnd_x                                   0xE9E500
#define pinstCCompassWnd_x                                         0xE9E504
#define pinstCPlayerNotesWnd_x                                     0xE9E508
#define pinstCGemsGameWnd_x                                        0xE9E50C
#define pinstCTimeLeftWnd_x                                        0xE9E510
#define pinstCPetitionQWnd_x                                       0xE9E524
#define pinstCSoulmarkWnd_x                                        0xE9E528
#define pinstCStoryWnd_x                                           0xE9E52C
#define pinstCJournalTextWnd_x                                     0xE9E530
#define pinstCJournalCatWnd_x                                      0xE9E534
#define pinstCBodyTintWnd_x                                        0xE9E538
#define pinstCServerListWnd_x                                      0xE9E53C
#define pinstCAvaZoneWnd_x                                         0xE9E548
#define pinstCBlockedBuffWnd_x                                     0xE9E54C
#define pinstCBlockedPetBuffWnd_x                                  0xE9E550
#define pinstCInvSlotMgr_x                                         0xE9E588
#define pinstCContainerMgr_x                                       0xE9E58C
#define pinstCAdventureLeaderboardWnd_x                            0x10F0B80
#define pinstCAdventureRequestWnd_x                                0x10F0BF8
#define pinstCAltStorageWnd_x                                      0x10F0ED8
#define pinstCAdventureStatsWnd_x                                  0x10F0C70
#define pinstCBarterMerchantWnd_x                                  0x10F1AC0
#define pinstCBarterSearchWnd_x                                    0x10F1B38
#define pinstCBarterWnd_x                                          0x10F1BB0
#define pinstCChatManager_x                                        0x10F2240
#define pinstCDynamicZoneWnd_x                                     0x10F26F0
#define pinstCEQMainWnd_x                                          0x10F2888
#define pinstCFellowshipWnd_x                                      0x10F2684
#define pinstCFindLocationWnd_x                                    0x10F2B58
#define pinstCGroupSearchWnd_x                                     0x10F2E28
#define pinstCGroupWnd_x                                           0x10F2EA0
#define pinstCGuildBankWnd_x                                       0x10F2F18
#define pinstCGuildMgmtWnd_x                                       0x10F5008
#define pinstCHotButtonWnd_x                                       0x10F50D4
#define pinstCHotButtonWnd1_x                                      0x10F50D4
#define pinstCHotButtonWnd2_x                                      0x10F50D8
#define pinstCHotButtonWnd3_x                                      0x10F50DC
#define pinstCHotButtonWnd4_x                                      0x10F5100
#define pinstCItemDisplayManager_x                                 0x10F53F8
#define pinstCItemExpTransferWnd_x                                 0x10F5474
#define pinstCLFGuildWnd_x                                         0x10F5750
#define pinstCMIZoneSelectWnd_x                                    0x10F5D38
#define pinstCConfirmationDialog_x                                 0x10F6440
#define pinstCPopupWndManager_x                                    0x10F6440
#define pinstCProgressionSelectionWnd_x                            0x10F6530
#define pinstCPvPStatsWnd_x                                        0x10F6620
#define pinstCSystemInfoDialogBox_x                                0x10F6D28
#define pinstCTaskWnd_x                                            0x10F80F0
#define pinstCTaskSomething_x                                      0xD6C638
#define pinstCTaskTemplateSelectWnd_x                              0x10F8078
#define pinstCTipWndOFDAY_x                                        0x10F8348
#define pinstCTipWndCONTEXT_x                                      0x10F834C
#define pinstCTitleWnd_x                                           0x10F83C8
#define pinstCContextMenuManager_x                                 0x17596E4
#define pinstCVoiceMacroWnd_x                                      0xFE5000
#define pinstCHtmlWnd_x                                            0xFE50F8
#define pinstIconCache_x                                           0x10F285C
#define pinstCTradeskillWnd_x                                      0x10F84C8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5094C0
#define __ConvertItemTags_x                                        0x4F6670
#define __ExecuteCmd_x                                             0x4E1140
#define __EQGetTime_x                                              0x83C8A0
#define __get_melee_range_x                                        0x4E7E20
#define __GetGaugeValueFromEQ_x                                    0x77BEA0
#define __GetLabelFromEQ_x                                         0x77D0E0
#define __ToggleMount_x                                            0x6A5BC0
#define __GetXTargetType_x                                         0x8F9C00
#define __LoadFrontEnd_x                                           0x60AF00
#define __NewUIINI_x                                               0x77B7E0
#define __ProcessGameEvents_x                                      0x54D3C0
#define __ProcessMouseEvent_x                                      0x54CB60
#define CrashDetected_x                                            0x60C9D0
#define wwsCrashReportCheckForUploader_x                           0x7D1050
#define DrawNetStatus_x                                            0x583B70
#define Util__FastTime_x                                           0x83BBB0
#define Expansion_HoT_x                                            0xF5F9E4
#define __HelpPath_x                                               0xFE3150

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A6130
#define AltAdvManager__IsAbilityReady_x                            0x4A61A0
#define AltAdvManager__GetAltAbility_x                             0x4A6560

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x453110
#define CharacterZoneClient__MakeMeVisible_x                       0x4581D0
// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x63A5B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x648860

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5633D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6637C0
#define CChatManager__InitContextMenu_x                            0x6642E0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x88B920
#define CContextMenu__dCContextMenu_x                              0x88BB30
#define CContextMenu__AddMenuItem_x                                0x88BB40
#define CContextMenu__RemoveMenuItem_x                             0x88BE50
#define CContextMenu__RemoveAllMenuItems_x                         0x88BE50
#define CContextMenuManager__AddMenu_x                             0x892080
#define CContextMenuManager__RemoveMenu_x                          0x8923B0
#define CContextMenuManager__PopupMenu_x                           0x892800
#define CContextMenuManager__Flush_x                               0x8920F0
// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8227D0
#define CChatService__GetFriendName_x                              0x8227E0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x669130
#define CChatWindow__Clear_x                                       0x668CE0
#define CChatWindow__WndNotification_x                             0x669660

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x89AF60
#define CComboWnd__Draw_x                                          0x89B160
#define CComboWnd__GetCurChoice_x                                  0x89AD80
#define CComboWnd__GetListRect_x                                   0x89B400
#define CComboWnd__GetTextRect_x                                   0x89AFC0
#define CComboWnd__InsertChoice_x                                  0x89B470
#define CComboWnd__SetColors_x                                     0x89AD10
#define CComboWnd__SetChoice_x                                     0x89AD40

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x672840
#define CContainerWnd__vftable_x                                   0xA61040

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4949C0
#define CDisplay__GetClickedActor_x                                0x48D460
#define CDisplay__GetUserDefinedColor_x                            0x48BD20
#define CDisplay__GetWorldFilePath_x                               0x48B120
#define CDisplay__is3dON_x                                         0x48A4F0
#define CDisplay__ReloadUI_x                                       0x49FE20
#define CDisplay__WriteTextHD2_x                                   0x490CB0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8BCC90

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8AB890
#define CEditWnd__GetCharIndexPt_x                                 0x8AC8B0
#define CEditWnd__GetDisplayString_x                               0x8ABA40
#define CEditWnd__GetHorzOffset_x                                  0x8ABD80
#define CEditWnd__GetLineForPrintableChar_x                        0x8AC380
#define CEditWnd__GetSelStartPt_x                                  0x8ACB60
#define CEditWnd__GetSTMLSafeText_x                                0x8ABF20
#define CEditWnd__PointFromPrintableChar_x                         0x8AC470
#define CEditWnd__SelectableCharFromPoint_x                        0x8AC5F0
#define CEditWnd__SetEditable_x                                    0x8ABEF0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x52A850
#define CEverQuest__DoTellWindow_x                                 0x5301D0
#define CEverQuest__DropHeldItemOnGround_x                         0x538C50
#define CEverQuest__dsp_chat_x                                     0x531970
#define CEverQuest__Emote_x                                        0x531BD0
#define CEverQuest__EnterZone_x                                    0x545320
#define CEverQuest__GetBodyTypeDesc_x                              0x527180
#define CEverQuest__GetClassDesc_x                                 0x52CD50
#define CEverQuest__GetClassThreeLetterCode_x                      0x52D350
#define CEverQuest__GetDeityDesc_x                                 0x527A60
#define CEverQuest__GetLangDesc_x                                  0x527510
#define CEverQuest__GetRaceDesc_x                                  0x52D510
#define CEverQuest__InterpretCmd_x                                 0x5324B0
#define CEverQuest__LeftClickedOnPlayer_x                          0x549AD0
#define CEverQuest__LMouseUp_x                                     0x54BBB0
#define CEverQuest__RightClickedOnPlayer_x                         0x54A5D0
#define CEverQuest__RMouseUp_x                                     0x54B610
#define CEverQuest__SetGameState_x                                 0x52AF00
#define CEverQuest__UPCNotificationFlush_x                         0x533650
#define CEverQuest__IssuePetCommand_x                              0x5331B0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6833B0
#define CGaugeWnd__CalcLinesFillRect_x                             0x683410
#define CGaugeWnd__Draw_x                                          0x683840

// CGuild
#define CGuild__FindMemberByName_x                                 0x4249F0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6A05C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6AE3E0
#define CInvSlotMgr__MoveItem_x                                    0x6AF320
#define CInvSlotMgr__SelectSlot_x                                  0x6AE490

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6AD880
#define CInvSlot__SliderComplete_x                                 0x6AB250
#define CInvSlot__GetItemBase_x                                    0x6AA6D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6B04E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x778A20
#define CItemDisplayWnd__UpdateStrings_x                           0x6B1820

// CLabel 
#define CLabel__Draw_x                                             0x6CC520

// CListWnd
#define CListWnd__CListWnd_x                                       0x887FD0
#define CListWnd__dCListWnd_x                                      0x889050
#define CListWnd__AddColumn_x                                      0x888FF0
#define CListWnd__AddColumn1_x                                     0x8887E0
#define CListWnd__AddLine_x                                        0x888290
#define CListWnd__AddString_x                                      0x8884A0
#define CListWnd__CalculateFirstVisibleLine_x                      0x885330
#define CListWnd__CalculateVSBRange_x                              0x887490
#define CListWnd__ClearAllSel_x                                    0x8845F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x887E60
#define CListWnd__Compare_x                                        0x885E10
#define CListWnd__Draw_x                                           0x8870A0
#define CListWnd__DrawColumnSeparators_x                           0x886F30
#define CListWnd__DrawHeader_x                                     0x884900
#define CListWnd__DrawItem_x                                       0x886460
#define CListWnd__DrawLine_x                                       0x886BD0
#define CListWnd__DrawSeparator_x                                  0x886FD0
#define CListWnd__EnsureVisible_x                                  0x885490
#define CListWnd__ExtendSel_x                                      0x886370
#define CListWnd__GetColumnMinWidth_x                              0x884010
#define CListWnd__GetColumnWidth_x                                 0x883F30
#define CListWnd__GetCurSel_x                                      0x883700
#define CListWnd__GetItemAtPoint_x                                 0x885720
#define CListWnd__GetItemAtPoint1_x                                0x885790
#define CListWnd__GetItemData_x                                    0x883A40
#define CListWnd__GetItemHeight_x                                  0x884F90
#define CListWnd__GetItemIcon_x                                    0x883C20
#define CListWnd__GetItemRect_x                                    0x885560
#define CListWnd__GetItemText_x                                    0x883AD0
#define CListWnd__GetSelList_x                                     0x8886D0
#define CListWnd__GetSeparatorRect_x                               0x885D40
#define CListWnd__RemoveLine_x                                     0x888680
#define CListWnd__SetColors_x                                      0x883850
#define CListWnd__SetColumnJustification_x                         0x8842E0
#define CListWnd__SetColumnWidth_x                                 0x883FC0
#define CListWnd__SetCurSel_x                                      0x883740
#define CListWnd__SetItemColor_x                                   0x887B40
#define CListWnd__SetItemData_x                                    0x8846A0
#define CListWnd__SetItemText_x                                    0x887980
#define CListWnd__ShiftColumnSeparator_x                           0x887810
#define CListWnd__Sort_x                                           0x889150
#define CListWnd__ToggleSel_x                                      0x884570

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6E5AB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x706CA0
#define CMerchantWnd__RequestBuyItem_x                             0x70DB00
#define CMerchantWnd__RequestSellItem_x                            0x70E570
#define CMerchantWnd__SelectRecoverySlot_x                         0x706F50
#define CMerchantWnd__SelectBuySellSlot_x                          0x7061B0
#define CMerchantWnd__ActualSelect_x                               0x70AA20

// CObfuscator
#define CObfuscator__doit_x                                        0x802CF0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8A0690
#define CSidlManager__CreateLabel_x                                0x76E9C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x631800
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6316E0
#define CSidlScreenWnd__ConvertToRes_x                             0x8BCB70
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x88E0F0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x88F5D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x88F680
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x88EB60
#define CSidlScreenWnd__DrawSidlPiece_x                            0x88DBD0
#define CSidlScreenWnd__EnableIniStorage_x                         0x88D330
#define CSidlScreenWnd__GetSidlPiece_x                             0x88DDC0
#define CSidlScreenWnd__Init1_x                                    0x88F2B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x88E1A0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x88D4F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x88EDB0
#define CSidlScreenWnd__StoreIniInfo_x                             0x88CE00
#define CSidlScreenWnd__StoreIniVis_x                              0x88D2C0
#define CSidlScreenWnd__WndNotification_x                          0x88F030
#define CSidlScreenWnd__GetChildItem_x                             0x88D400
#define CSidlScreenWnd__HandleLButtonUp_x                          0x893F40

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5CCDB0
#define CSkillMgr__GetSkillCap_x                                   0x5CCF50
#define CSkillMgr__GetNameToken_x                                  0x5CCA20

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8C6B80
#define CSliderWnd__SetValue_x                                     0x8C6D50
#define CSliderWnd__SetNumTicks_x                                  0x8C74D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7766C0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8B6F70
#define CStmlWnd__CalculateHSBRange_x                              0x8AF4B0
#define CStmlWnd__CalculateVSBRange_x                              0x8AF540
#define CStmlWnd__CanBreakAtCharacter_x                            0x8AF6C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8AFFA0
#define CStmlWnd__ForceParseNow_x                                  0x8B78C0
#define CStmlWnd__GetNextTagPiece_x                                0x8AFEA0
#define CStmlWnd__GetSTMLText_x                                    0x668570
#define CStmlWnd__GetVisibleText_x                                 0x8B09F0
#define CStmlWnd__InitializeWindowVariables_x                      0x8B2D60
#define CStmlWnd__MakeStmlColorTag_x                               0x8AE7B0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8AE810
#define CStmlWnd__SetSTMLText_x                                    0x8B45C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8B6C10
#define CStmlWnd__UpdateHistoryString_x                            0x8B1920

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8BE370
#define CTabWnd__DrawCurrentPage_x                                 0x8BDBE0
#define CTabWnd__DrawTab_x                                         0x8BD9A0
#define CTabWnd__GetCurrentPage_x                                  0x8BDFB0
#define CTabWnd__GetPageInnerRect_x                                0x8BD690
#define CTabWnd__GetTabInnerRect_x                                 0x8BD890
#define CTabWnd__GetTabRect_x                                      0x8BD760
#define CTabWnd__InsertPage_x                                      0x8BE660
#define CTabWnd__SetPage_x                                         0x8BDFE0
#define CTabWnd__SetPageRect_x                                     0x8BE2B0
#define CTabWnd__UpdatePage_x                                      0x8BE600

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x420690

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BA3D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8C3540

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8818F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x570950
#define CXStr__CXStr1_x                                            0x718790
#define CXStr__CXStr3_x                                            0x838C40
#define CXStr__dCXStr_x                                            0x7187A0
#define CXStr__operator_equal_x                                    0x838DB0
#define CXStr__operator_equal1_x                                   0x838E00
#define CXStr__operator_plus_equal1_x                              0x839EE0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x893210
#define CXWnd__Center_x                                            0x8993A0
#define CXWnd__ClrFocus_x                                          0x892E00
#define CXWnd__DoAllDrawing_x                                      0x898FF0
#define CXWnd__DrawChildren_x                                      0x899190
#define CXWnd__DrawColoredRect_x                                   0x8935C0
#define CXWnd__DrawTooltip_x                                       0x893850
#define CXWnd__DrawTooltipAtPoint_x                                0x897F50
#define CXWnd__GetBorderFrame_x                                    0x893C50
#define CXWnd__GetChildWndAt_x                                     0x896F40
#define CXWnd__GetClientClipRect_x                                 0x893A60
#define CXWnd__GetScreenClipRect_x                                 0x898650
#define CXWnd__GetScreenRect_x                                     0x893DE0
#define CXWnd__GetTooltipRect_x                                    0x8936E0
#define CXWnd__GetWindowTextA_x                                    0x411930
#define CXWnd__IsActive_x                                          0x8A65A0
#define CXWnd__IsDescendantOf_x                                    0x893BA0
#define CXWnd__IsReallyVisible_x                                   0x896F20
#define CXWnd__IsType_x                                            0x8BFD60
#define CXWnd__Move_x                                              0x896600
#define CXWnd__Move1_x                                             0x898C90
#define CXWnd__ProcessTransition_x                                 0x8931B0
#define CXWnd__Refade_x                                            0x892F90
#define CXWnd__Resize_x                                            0x893EA0
#define CXWnd__Right_x                                             0x898450
#define CXWnd__SetFocus_x                                          0x895750
#define CXWnd__SetFont_x                                           0x892E50
#define CXWnd__SetKeyTooltip_x                                     0x894110
#define CXWnd__SetMouseOver_x                                      0x898980
#define CXWnd__StartFade_x                                         0x893260
#define CXWnd__GetChildItem_x                                      0x8988D0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A7ED0
#define CXWndManager__DrawWindows_x                                0x8A7B10
#define CXWndManager__GetKeyboardFlags_x                           0x8A6110
#define CXWndManager__HandleKeyboardMsg_x                          0x8A6A30
#define CXWndManager__RemoveWnd_x                                  0x8A6730

// CDBStr
#define CDBStr__GetString_x                                        0x4889B0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x43CAA0
#define EQ_Character__Cur_HP_x                                     0x4527D0
#define EQ_Character__GetAACastingTimeModifier_x                   0x435B70
#define EQ_Character__GetCharInfo2_x                               0x80D370
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42DEA0
#define EQ_Character__GetFocusRangeModifier_x                      0x42E080
#define EQ_Character__Max_Endurance_x                              0x5956E0
#define EQ_Character__Max_HP_x                                     0x448AD0
#define EQ_Character__Max_Mana_x                                   0x595510
#define EQ_Character__doCombatAbility_x                            0x592B00
#define EQ_Character__UseSkill_x                                   0x45D300
#define EQ_Character__GetConLevel_x                                0x588180
#define EQ_Character__IsExpansionFlag_x                            0x410E60
#define EQ_Character__TotalEffect_x                                0x43ABD0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x568BA0
#define EQ_Item__CreateItemTagString_x                             0x7ED7D0
#define EQ_Item__IsStackable_x                                     0x7E19B0
#define EQ_Item__GetImageNum_x                                     0x7E46B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A8250
#define EQ_LoadingS__Array_x                                       0xB76258

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x596E70
#define EQ_PC__GetAltAbilityIndex_x                                0x7F5A70
#define EQ_PC__GetCombatAbility_x                                  0x7F5B00
#define EQ_PC__GetCombatAbilityTimer_x                             0x7F5BB0
#define EQ_PC__GetItemTimerValue_x                                 0x5908D0
#define EQ_PC__HasLoreItem_x                                       0x58B460
#define EQ_PC__AlertInventoryChanged_x                             0x588150
#define EQ_PC__GetPcZoneClient_x                                   0x5B1170
#define EQ_PC__RemoveMyAffect_x									   0x58FDE0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E5DD0
#define EQItemList__add_item_x                                     0x4E5D10
#define EQItemList__delete_item_x                                  0x4E61D0
#define EQItemList__FreeItemList_x                                 0x4E60D0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487EB0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x59C300
#define EQPlayer__dEQPlayer_x                                      0x5A4F70
#define EQPlayer__DoAttack_x                                       0x5B6F60
#define EQPlayer__EQPlayer_x                                       0x5A73C0
#define EQPlayer__SetNameSpriteState_x                             0x5A1D20
#define EQPlayer__SetNameSpriteTint_x                              0x59D690
#define EQPlayer__IsBodyType_j_x                                   0x8F5F00
#define EQPlayer__IsTargetable_x                                   0x8F6750
#define EQPlayer__CanSee_x                                         0x8F6C70

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5AB690
#define EQPlayerManager__GetSpawnByName_x                          0x5ABAF0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56EC80
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56ECC0
#define KeypressHandler__ClearCommandStateArray_x                  0x56E860
#define KeypressHandler__HandleKeyDown_x                           0x56D1B0
#define KeypressHandler__HandleKeyUp_x                             0x56D4D0
#define KeypressHandler__SaveKeymapping_x                          0x56E930

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6DDE90
#define MapViewMap__SaveEx_x                                       0x6E1770

#define PlayerPointManager__GetAltCurrency_x                       0x8074B0

// StringTable 
#define StringTable__getString_x                                   0x802F90

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x595190

//Doors
#define EQSwitch__UseSwitch_x                                      0x5245B0

//IconCache
#define IconCache__GetIcon_x                                       0x678CB0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66FB60
#define CContainerMgr__CloseContainer_x                            0x670370

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x73EDA0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x561EA0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B69F0
#define EQ_Spell__SpellAffects_x                                   0x4B6A90
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B6AC0
#define CharacterZoneClient__CalcAffectChange_x                    0x436E90
#define CLootWnd__LootAll_x                                        0x6D3880

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x784480
#define CTargetWnd__WndNotification_x                              0x783F70
