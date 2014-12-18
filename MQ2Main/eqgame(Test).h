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
#define __ExpectedVersionDate                                     "Dec  2 2014"
#define __ExpectedVersionTime                                     "12:10:25"
#define __ActualVersionDate_x                                      0xA57878
#define __ActualVersionTime_x                                      0xA57884

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x574340
#define __MemChecker1_x                                            0x83C200
#define __MemChecker2_x                                            0x60BD90
#define __MemChecker3_x                                            0x60BCE0
#define __MemChecker4_x                                            0x7C04F0
#define __EncryptPad0_x                                            0xBC3790
#define __EncryptPad1_x                                            0xD3ED00
#define __EncryptPad2_x                                            0xC0AD40
#define __EncryptPad3_x                                            0xC0A940
#define __EncryptPad4_x                                            0xD1C3E8
#define __AC1_x                                                    0x77D885
#define __AC2_x                                                    0x52A097
#define __AC3_x                                                    0x53E770
#define __AC4_x                                                    0x544AA0
#define __AC5_x                                                    0x550F0E
#define __AC6_x                                                    0x554A52
#define __AC7_x                                                    0x54B5FC
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
#define __do_loot_x                                                0x4F17C0
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
#define pinstCamActor_x                                            0xE9E590
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
#define pinstViewActor_x                                           0xE9E58C
#define pinstWorldData_x                                           0xF516C8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD62678
#define pinstCAudioTriggersWindow_x                                0xD62508
#define pinstCCharacterSelect_x                                    0xE9E438
#define pinstCFacePick_x                                           0xE9E3E8
#define pinstCNoteWnd_x                                            0xE9E3F0
#define pinstCBookWnd_x                                            0xE9E3F8
#define pinstCPetInfoWnd_x                                         0xE9E3FC
#define pinstCTrainWnd_x                                           0xE9E400
#define pinstCSkillsWnd_x                                          0xE9E404
#define pinstCSkillsSelectWnd_x                                    0xE9E408
#define pinstCCombatSkillSelectWnd_x                               0xE9E40C
#define pinstCFriendsWnd_x                                         0xE9E410
#define pinstCAuraWnd_x                                            0xE9E414
#define pinstCRespawnWnd_x                                         0xE9E418
#define pinstCBandolierWnd_x                                       0xE9E41C
#define pinstCPotionBeltWnd_x                                      0xE9E420
#define pinstCAAWnd_x                                              0xE9E424
#define pinstCGroupSearchFiltersWnd_x                              0xE9E428
#define pinstCLoadskinWnd_x                                        0xE9E42C
#define pinstCAlarmWnd_x                                           0xE9E430
#define pinstCMusicPlayerWnd_x                                     0xE9E434
#define pinstCMailWnd_x                                            0xE9E43C
#define pinstCMailCompositionWnd_x                                 0xE9E440
#define pinstCMailAddressBookWnd_x                                 0xE9E444
#define pinstCRaidWnd_x                                            0xE9E44C
#define pinstCRaidOptionsWnd_x                                     0xE9E450
#define pinstCBreathWnd_x                                          0xE9E454
#define pinstCMapViewWnd_x                                         0xE9E458
#define pinstCMapToolbarWnd_x                                      0xE9E45C
#define pinstCEditLabelWnd_x                                       0xE9E460
#define pinstCTargetWnd_x                                          0xE9E464
#define pinstCColorPickerWnd_x                                     0xE9E468
#define pinstCPlayerWnd_x                                          0xE9E46C
#define pinstCOptionsWnd_x                                         0xE9E470
#define pinstCBuffWindowNORMAL_x                                   0xE9E474
#define pinstCBuffWindowSHORT_x                                    0xE9E478
#define pinstCharacterCreation_x                                   0xE9E47C
#define pinstCCursorAttachment_x                                   0xE9E480
#define pinstCCastingWnd_x                                         0xE9E484
#define pinstCCastSpellWnd_x                                       0xE9E488
#define pinstCSpellBookWnd_x                                       0xE9E48C
#define pinstCInventoryWnd_x                                       0xE9E490
#define pinstCBankWnd_x                                            0xE9E494
#define pinstCQuantityWnd_x                                        0xE9E498
#define pinstCLootWnd_x                                            0xE9E49C
#define pinstCActionsWnd_x                                         0xE9E4A0
#define pinstCCombatAbilityWnd_x                                   0xE9E4A4
#define pinstCMerchantWnd_x                                        0xE9E4A8
#define pinstCTradeWnd_x                                           0xE9E4AC
#define pinstCSelectorWnd_x                                        0xE9E4B0
#define pinstCBazaarWnd_x                                          0xE9E4B4
#define pinstCBazaarSearchWnd_x                                    0xE9E4B8
#define pinstCGiveWnd_x                                            0xE9E4D4
#define pinstCTrackingWnd_x                                        0xE9E4DC
#define pinstCInspectWnd_x                                         0xE9E4E0
#define pinstCSocialEditWnd_x                                      0xE9E4E4
#define pinstCFeedbackWnd_x                                        0xE9E4E8
#define pinstCBugReportWnd_x                                       0xE9E4EC
#define pinstCVideoModesWnd_x                                      0xE9E4F0
#define pinstCTextEntryWnd_x                                       0xE9E4F8
#define pinstCFileSelectionWnd_x                                   0xE9E4FC
#define pinstCCompassWnd_x                                         0xE9E500
#define pinstCPlayerNotesWnd_x                                     0xE9E504
#define pinstCGemsGameWnd_x                                        0xE9E508
#define pinstCTimeLeftWnd_x                                        0xE9E50C
#define pinstCPetitionQWnd_x                                       0xE9E520
#define pinstCSoulmarkWnd_x                                        0xE9E524
#define pinstCStoryWnd_x                                           0xE9E528
#define pinstCJournalTextWnd_x                                     0xE9E52C
#define pinstCJournalCatWnd_x                                      0xE9E530
#define pinstCBodyTintWnd_x                                        0xE9E534
#define pinstCServerListWnd_x                                      0xE9E538
#define pinstCAvaZoneWnd_x                                         0xE9E544
#define pinstCBlockedBuffWnd_x                                     0xE9E548
#define pinstCBlockedPetBuffWnd_x                                  0xE9E54C
#define pinstCInvSlotMgr_x                                         0xE9E584
#define pinstCContainerMgr_x                                       0xE9E588
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
#define __CastRay_x                                                0x509320
#define __ConvertItemTags_x                                        0x4F64D0
#define __ExecuteCmd_x                                             0x4E1000
#define __EQGetTime_x                                              0x83CD60
#define __get_melee_range_x                                        0x4E7C90
#define __GetGaugeValueFromEQ_x                                    0x77C5D0
#define __GetLabelFromEQ_x                                         0x77D810
#define __ToggleMount_x                                            0x6A6250
#define __GetXTargetType_x                                         0x8F9EF0
#define __LoadFrontEnd_x                                           0x60B440
#define __NewUIINI_x                                               0x77BF20
#define __ProcessGameEvents_x                                      0x54D360
#define __ProcessMouseEvent_x                                      0x54CB00
#define CrashDetected_x                                            0x60CF10
#define DrawNetStatus_x                                            0x583EE0
#define Util__FastTime_x                                           0x83C070
#define Expansion_HoT_x                                            0xF5F9E4
#define __HelpPath_x                                               0xFE3150
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A6070
#define AltAdvManager__IsAbilityReady_x                            0x4A60E0
#define AltAdvManager__GetAltAbility_x                             0x4A64A0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x453020
#define CharacterZoneClient__MakeMeVisible_x                       0x4580E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x63AB30

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6491E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x563380

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x663E60
#define CChatManager__InitContextMenu_x                            0x664980

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x822BE0
#define CChatService__GetFriendName_x                              0x822BF0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6697D0
#define CChatWindow__Clear_x                                       0x669380
#define CChatWindow__WndNotification_x                             0x669D10

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x89B280
#define CComboWnd__Draw_x                                          0x89B470
#define CComboWnd__GetCurChoice_x                                  0x89B0A0
#define CComboWnd__GetListRect_x                                   0x89B710
#define CComboWnd__GetTextRect_x                                   0x89B2E0
#define CComboWnd__InsertChoice_x                                  0x89B780
#define CComboWnd__SetColors_x                                     0x89B030
#define CComboWnd__SetChoice_x                                     0x89B060

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x672F10
#define CContainerWnd__vftable_x                                   0xA60FE0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4949A0
#define CDisplay__GetClickedActor_x                                0x48D440
#define CDisplay__GetUserDefinedColor_x                            0x48BD00
#define CDisplay__GetWorldFilePath_x                               0x48B100
#define CDisplay__is3dON_x                                         0x48A4D0
#define CDisplay__ReloadUI_x                                       0x49FE00
#define CDisplay__WriteTextHD2_x                                   0x490C90

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8BD0E0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8ABC70
#define CEditWnd__GetCharIndexPt_x                                 0x8ACCA0
#define CEditWnd__GetDisplayString_x                               0x8ABE20
#define CEditWnd__GetHorzOffset_x                                  0x8AC160
#define CEditWnd__GetLineForPrintableChar_x                        0x8AC760
#define CEditWnd__GetSelStartPt_x                                  0x8ACF60
#define CEditWnd__GetSTMLSafeText_x                                0x8AC300
#define CEditWnd__PointFromPrintableChar_x                         0x8AC850
#define CEditWnd__SelectableCharFromPoint_x                        0x8AC9D0
#define CEditWnd__SetEditable_x                                    0x8AC2D0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x52A7E0
#define CEverQuest__DoTellWindow_x                                 0x530170
#define CEverQuest__DropHeldItemOnGround_x                         0x538BF0
#define CEverQuest__dsp_chat_x                                     0x531900
#define CEverQuest__Emote_x                                        0x531B60
#define CEverQuest__EnterZone_x                                    0x5452C0
#define CEverQuest__GetBodyTypeDesc_x                              0x527110
#define CEverQuest__GetClassDesc_x                                 0x52CCE0
#define CEverQuest__GetClassThreeLetterCode_x                      0x52D2E0
#define CEverQuest__GetDeityDesc_x                                 0x5279F0
#define CEverQuest__GetLangDesc_x                                  0x5274A0
#define CEverQuest__GetRaceDesc_x                                  0x52D4A0
#define CEverQuest__InterpretCmd_x                                 0x532440
#define CEverQuest__LeftClickedOnPlayer_x                          0x549A70
#define CEverQuest__LMouseUp_x                                     0x54BB50
#define CEverQuest__RightClickedOnPlayer_x                         0x54A570
#define CEverQuest__RMouseUp_x                                     0x54B5B0
#define CEverQuest__SetGameState_x                                 0x52AE90
#define CEverQuest__UPCNotificationFlush_x                         0x5335E0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x683B50
#define CGaugeWnd__CalcLinesFillRect_x                             0x683BB0
#define CGaugeWnd__Draw_x                                          0x683FE0

// CGuild
#define CGuild__FindMemberByName_x                                 0x424920

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6A0C50

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6AEAA0
#define CInvSlotMgr__MoveItem_x                                    0x6AF9D0
#define CInvSlotMgr__SelectSlot_x                                  0x6AEB50

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6ADF40
#define CInvSlot__SliderComplete_x                                 0x6AB900
#define CInvSlot__GetItemBase_x                                    0x6AAD80

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6B0B90

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x779110
#define CItemDisplayWnd__UpdateStrings_x                           0x6B1F00

// CLabel 
#define CLabel__Draw_x                                             0x6CCC00

// CListWnd 
#define CListWnd__AddColumn_x                                      0x889320
#define CListWnd__AddColumn1_x                                     0x888B00
#define CListWnd__AddLine_x                                        0x8885B0
#define CListWnd__AddString_x                                      0x8887C0
#define CListWnd__CalculateFirstVisibleLine_x                      0x885630
#define CListWnd__CalculateVSBRange_x                              0x8877B0
#define CListWnd__ClearAllSel_x                                    0x8848F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x888190
#define CListWnd__Compare_x                                        0x886140
#define CListWnd__Draw_x                                           0x8873C0
#define CListWnd__DrawColumnSeparators_x                           0x887250
#define CListWnd__DrawHeader_x                                     0x884C00
#define CListWnd__DrawItem_x                                       0x886780
#define CListWnd__DrawLine_x                                       0x886EF0
#define CListWnd__DrawSeparator_x                                  0x8872F0
#define CListWnd__EnsureVisible_x                                  0x885790
#define CListWnd__ExtendSel_x                                      0x886690
#define CListWnd__GetColumnMinWidth_x                              0x884310
#define CListWnd__GetColumnWidth_x                                 0x884230
#define CListWnd__GetCurSel_x                                      0x8839F0
#define CListWnd__GetItemAtPoint_x                                 0x885A30
#define CListWnd__GetItemAtPoint1_x                                0x885AA0
#define CListWnd__GetItemData_x                                    0x883D40
#define CListWnd__GetItemHeight_x                                  0x885290
#define CListWnd__GetItemIcon_x                                    0x883F20
#define CListWnd__GetItemRect_x                                    0x885870
#define CListWnd__GetItemText_x                                    0x883DD0
#define CListWnd__GetSelList_x                                     0x8889F0
#define CListWnd__GetSeparatorRect_x                               0x886060
#define CListWnd__RemoveLine_x                                     0x8889A0
#define CListWnd__SetColors_x                                      0x883B40
#define CListWnd__SetColumnJustification_x                         0x8845E0
#define CListWnd__SetColumnWidth_x                                 0x8842C0
#define CListWnd__SetCurSel_x                                      0x883A30
#define CListWnd__SetItemColor_x                                   0x887E70
#define CListWnd__SetItemData_x                                    0x8849A0
#define CListWnd__SetItemText_x                                    0x887CB0
#define CListWnd__ShiftColumnSeparator_x                           0x887B40
#define CListWnd__Sort_x                                           0x889480
#define CListWnd__ToggleSel_x                                      0x884870

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6E6190

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7073C0
#define CMerchantWnd__RequestBuyItem_x                             0x70E230
#define CMerchantWnd__RequestSellItem_x                            0x70ECA0
#define CMerchantWnd__SelectRecoverySlot_x                         0x707670
#define CMerchantWnd__SelectBuySellSlot_x                          0x7068D0
#define CMerchantWnd__ActualSelect_x                               0x70B150

// CObfuscator
#define CObfuscator__doit_x                                        0x803040

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8A0AA0
#define CSidlManager__CreateLabel_x                                0x76F110

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x631E60
#define CSidlScreenWnd__CalculateVSBRange_x                        0x631D80
#define CSidlScreenWnd__ConvertToRes_x                             0x8BCFC0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x88E440
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x88F950
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x88FA00
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x88EEC0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x88DF20
#define CSidlScreenWnd__EnableIniStorage_x                         0x88D670
#define CSidlScreenWnd__GetSidlPiece_x                             0x88E110
#define CSidlScreenWnd__Init1_x                                    0x88F630
#define CSidlScreenWnd__LoadIniInfo_x                              0x88E4F0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x88D830
#define CSidlScreenWnd__LoadSidlScreen_x                           0x88F110
#define CSidlScreenWnd__StoreIniInfo_x                             0x88D130
#define CSidlScreenWnd__StoreIniVis_x                              0x88D600
#define CSidlScreenWnd__WndNotification_x                          0x88F3B0
#define CSidlScreenWnd__GetChildItem_x                             0x88D740
#define CSidlScreenWnd__HandleLButtonUp_x                          0x894320

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5CD2D0
#define CSkillMgr__GetSkillCap_x                                   0x5CD470
#define CSkillMgr__GetNameToken_x                                  0x5CCF40

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8C6F80
#define CSliderWnd__SetValue_x                                     0x8C7150
#define CSliderWnd__SetNumTicks_x                                  0x8C78D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x776DB0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8B7390
#define CStmlWnd__CalculateHSBRange_x                              0x8AF950
#define CStmlWnd__CalculateVSBRange_x                              0x8AF8C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8AFAD0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8B03B0
#define CStmlWnd__ForceParseNow_x                                  0x8B7CE0
#define CStmlWnd__GetNextTagPiece_x                                0x8B02B0
#define CStmlWnd__GetSTMLText_x                                    0x668C20
#define CStmlWnd__GetVisibleText_x                                 0x8B0E00
#define CStmlWnd__InitializeWindowVariables_x                      0x8B3190
#define CStmlWnd__MakeStmlColorTag_x                               0x8AEBC0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8AEC20
#define CStmlWnd__SetSTMLText_x                                    0x8B49F0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8B7030
#define CStmlWnd__UpdateHistoryString_x                            0x8B1D40

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8BE7C0
#define CTabWnd__DrawCurrentPage_x                                 0x8BE030
#define CTabWnd__DrawTab_x                                         0x8BDDF0
#define CTabWnd__GetCurrentPage_x                                  0x8BE400
#define CTabWnd__GetPageInnerRect_x                                0x8BDAE0
#define CTabWnd__GetTabInnerRect_x                                 0x8BDCE0
#define CTabWnd__GetTabRect_x                                      0x8BDBB0
#define CTabWnd__InsertPage_x                                      0x8BEAB0
#define CTabWnd__SetPage_x                                         0x8BE430
#define CTabWnd__SetPageRect_x                                     0x8BE700
#define CTabWnd__UpdatePage_x                                      0x8BEA50

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4206A0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BA820

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8C3940

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x881CA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4118B0
#define CXStr__CXStr1_x                                            0x7AD450
#define CXStr__CXStr3_x                                            0x839100
#define CXStr__dCXStr_x                                            0x718E10
#define CXStr__operator_equal_x                                    0x839270
#define CXStr__operator_equal1_x                                   0x8392C0
#define CXStr__operator_plus_equal1_x                              0x83A3A0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x893540
#define CXWnd__Center_x                                            0x8996F0
#define CXWnd__ClrFocus_x                                          0x893110
#define CXWnd__DoAllDrawing_x                                      0x899340
#define CXWnd__DrawChildren_x                                      0x8994E0
#define CXWnd__DrawColoredRect_x                                   0x8938E0
#define CXWnd__DrawTooltip_x                                       0x893B90
#define CXWnd__DrawTooltipAtPoint_x                                0x898300
#define CXWnd__GetBorderFrame_x                                    0x893FF0
#define CXWnd__GetChildWndAt_x                                     0x8972D0
#define CXWnd__GetClientClipRect_x                                 0x893DA0
#define CXWnd__GetScreenClipRect_x                                 0x898A00
#define CXWnd__GetScreenRect_x                                     0x8941C0
#define CXWnd__GetTooltipRect_x                                    0x893A20
#define CXWnd__GetWindowTextA_x                                    0x4118F0
#define CXWnd__IsActive_x                                          0x8A6AF0
#define CXWnd__IsDescendantOf_x                                    0x893F30
#define CXWnd__IsReallyVisible_x                                   0x8972A0
#define CXWnd__IsType_x                                            0x8C0140
#define CXWnd__Move_x                                              0x8969B0
#define CXWnd__Move1_x                                             0x899000
#define CXWnd__ProcessTransition_x                                 0x8934F0
#define CXWnd__Refade_x                                            0x8932C0
#define CXWnd__Resize_x                                            0x894280
#define CXWnd__Right_x                                             0x898800
#define CXWnd__SetFocus_x                                          0x895B30
#define CXWnd__SetFont_x                                           0x893160
#define CXWnd__SetKeyTooltip_x                                     0x8944F0
#define CXWnd__SetMouseOver_x                                      0x898D10
#define CXWnd__StartFade_x                                         0x893590
#define CXWnd__GetChildItem_x                                      0x898C50

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A8400
#define CXWndManager__DrawWindows_x                                0x8A8050
#define CXWndManager__GetKeyboardFlags_x                           0x8A6620
#define CXWndManager__HandleKeyboardMsg_x                          0x8A6F80
#define CXWndManager__RemoveWnd_x                                  0x8A6C80

// CDBStr
#define CDBStr__GetString_x                                        0x4888D0

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8F6EF0
#define EQ_Character__CastSpell_x                                  0x43C9E0
#define EQ_Character__Cur_HP_x                                     0x4526E0
#define EQ_Character__GetAACastingTimeModifier_x                   0x435AB0
#define EQ_Character__GetCharInfo2_x                               0x80D750
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42DDD0
#define EQ_Character__GetFocusRangeModifier_x                      0x42DFB0
#define EQ_Character__Max_Endurance_x                              0x595C20
#define EQ_Character__Max_HP_x                                     0x4489E0
#define EQ_Character__Max_Mana_x                                   0x595A50
#define EQ_Character__doCombatAbility_x                            0x593040
#define EQ_Character__UseSkill_x                                   0x45D220
#define EQ_Character__GetConLevel_x                                0x5885B0
#define EQ_Character__IsExpansionFlag_x                            0x410DD0
#define EQ_Character__TotalEffect_x                                0x43AB10

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x568B50
#define EQ_Item__CreateItemTagString_x                             0x7EDB50
#define EQ_Item__IsStackable_x                                     0x7E2140
#define EQ_Item__GetImageNum_x                                     0x7E4DE0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A81E0
#define EQ_LoadingS__Array_x                                       0xB76258

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5973C0
#define EQ_PC__GetAltAbilityIndex_x                                0x7F5DE0
#define EQ_PC__GetCombatAbility_x                                  0x7F5E70
#define EQ_PC__GetCombatAbilityTimer_x                             0x7F5F20
#define EQ_PC__GetItemTimerValue_x                                 0x590E10
#define EQ_PC__HasLoreItem_x                                       0x58B880
#define EQ_PC__AlertInventoryChanged_x                             0x588580
#define EQ_PC__GetPcZoneClient_x                                   0x5B1620
#define EQ_PC__RemoveMyAffect_x                                    0x590320

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E5C60
#define EQItemList__add_item_x                                     0x4E5BA0
#define EQItemList__delete_item_x                                  0x4E6060
#define EQItemList__FreeItemList_x                                 0x4E5F60

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487E20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x59C850
#define EQPlayer__dEQPlayer_x                                      0x5A54B0
#define EQPlayer__DoAttack_x                                       0x5B7420
#define EQPlayer__EQPlayer_x                                       0x5A7900
#define EQPlayer__SetNameSpriteState_x                             0x5A2270
#define EQPlayer__SetNameSpriteTint_x                              0x59DBE0
#define EQPlayer__IsBodyType_j_x                                   0x8F6180
#define EQPlayer__IsTargetable_x                                   0x8F69D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5ABC30
#define EQPlayerManager__GetSpawnByName_x                          0x5AC090

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56ED80
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56EDC0
#define KeypressHandler__ClearCommandStateArray_x                  0x56E960
#define KeypressHandler__HandleKeyDown_x                           0x56D2B0
#define KeypressHandler__HandleKeyUp_x                             0x56D5D0
#define KeypressHandler__SaveKeymapping_x                          0x56EA30

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6DE570
#define MapViewMap__SaveEx_x                                       0x6E1E50

#define PlayerPointManager__GetAltCurrency_x                       0x807890

// StringTable 
#define StringTable__getString_x                                   0x8032E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5956D0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5243C0

//IconCache
#define IconCache__GetIcon_x                                       0x679370

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x670230
#define CContainerMgr__CloseContainer_x                            0x670A40

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x73F460

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x561E40

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B6850
#define EQ_Spell__SpellAffects_x                                   0x4B68F0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B6920
#define CharacterZoneClient__CalcAffectChange_x                    0x436DD0
#define CLootWnd__LootAll_x                                        0x6D3F10
#define CTargetWnd__GetBuffCaster_x                                0x784BB0
