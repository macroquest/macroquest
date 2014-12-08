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
#define __ExpectedVersionDate                                     "Nov 18 2014"
#define __ExpectedVersionTime                                     "16:54:04"
#define __ActualVersionDate_x                                      0xA568A0
#define __ActualVersionTime_x                                      0xA568AC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x573D50
#define __MemChecker1_x                                            0x83B610
#define __MemChecker2_x                                            0x60B2D0
#define __MemChecker3_x                                            0x60B220
#define __MemChecker4_x                                            0x7BFA50
#define __EncryptPad0_x                                            0xBC2790
#define __EncryptPad1_x                                            0xD3DD00
#define __EncryptPad2_x                                            0xC09D40
#define __EncryptPad3_x                                            0xC09940
#define __EncryptPad4_x                                            0xD1B3E8
#define __AC1_x                                                    0x77CC55
#define __AC2_x                                                    0x529B87
#define __AC3_x                                                    0x53E250
#define __AC4_x                                                    0x544580
#define __AC5_x                                                    0x5509DE
#define __AC6_x                                                    0x554522
#define __AC7_x                                                    0x54B0CC
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10EF050
#define DI8__Keyboard_x                                            0x10EF054
#define DI8__Mouse_x                                               0x10EF058
#define __AltTimerReady_x                                          0xF4EAE1
#define __Attack_x                                                 0xFE1BF7
#define __Autofire_x                                               0xFE1BF8
#define __BindList_x                                               0xB866A8
#define __bCommandEnabled_x                                        0xF4CBF0
#define __Clicks_x                                                 0xF5D728
#define __CommandList_x                                            0xB8A7F0
#define __CurrentMapLabel_x                                        0x10F4AA8
#define __CurrentSocial_x                                          0xB4BFCC
#define __DoAbilityList_x                                          0xF93EAC
#define __do_loot_x                                                0x4F14E0
#define __DrawHandler_x                                            0x17596BC
#define __GroupCount_x                                             0xF4E1BA

#define __Guilds_x                                                 0xF53CA8
#define __gWorld_x                                                 0xF50674
#define __HotkeyPage_x                                             0xFDA8AC
#define __HWnd_x                                                   0xFE6F58
#define __InChatMode_x                                             0xF5D654
#define __LastTell_x                                               0xF5F5B4
#define __LMouseHeldTime_x                                         0xF5D794
#define __Mouse_x                                                  0x10EF05C
#define __MouseLook_x                                              0xF5D6EE
#define __MouseEventTime_x                                         0xFE23E4
#define __NetStatusToggle_x                                        0xF5D6F1
#define __PCNames_x                                                0xF5EBE4
#define __RangeAttackReady_x                                       0xF5E878
#define __RMouseHeldTime_x                                         0xF5D790
#define __RunWalkState_x                                           0xF5D658
#define __ScreenMode_x                                             0xE9CBB0
#define __ScreenX_x                                                0xF5D60C
#define __ScreenY_x                                                0xF5D608
#define __ScreenXMax_x                                             0xF5D610
#define __ScreenYMax_x                                             0xF5D614
#define __ServerHost_x                                             0xF4E104
#define __ServerName_x                                             0xF93E6C
#define __ShiftKeyDown_x                                           0xF5DCFC
#define __ShowNames_x                                              0xF5EA88
#define __Socials_x                                                0xF93F6C
#define __SubscriptionType_x                                       0x1120E38
#define __TargetAggroHolder_x                                      0x10F6CE4
#define __GroupAggro_x                                             0x10F6D24
#define __LoginName_x                                              0xFE5B30
#define __Inviter_x                                                0xFE1B74


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF50760
#define instEQZoneInfo_x                                           0xF5D8E4
#define instKeypressHandler_x                                      0xFE23C8
#define pinstActiveBanker_x                                        0xF50718
#define pinstActiveCorpse_x                                        0xF5071C
#define pinstActiveGMaster_x                                       0xF50720
#define pinstActiveMerchant_x                                      0xF50714
#define pinstAggroInfo_x                                           0xD61198
#define pinstAltAdvManager_x                                       0xE9DC88
#define pinstAuraMgr_x                                             0xD6B060
#define pinstBandageTarget_x                                       0xF50700
#define pinstCamActor_x                                            0xE9D594
#define pinstCDBStr_x                                              0xE9CB44
#define pinstCDisplay_x                                            0xF50728
#define pinstCEverQuest_x                                          0x10EF1D4
#define pinstCharData_x                                            0xF506E4
#define pinstCharSpawn_x                                           0xF5070C
#define pinstControlledMissile_x                                   0xF506E0
#define pinstControlledPlayer_x                                    0xF5070C
#define pinstCSidlManager_x                                        0x1758AD0
#define pinstCXWndManager_x                                        0x1758AC8
#define instDynamicZone_x                                          0xF5D4A0
#define pinstDZMember_x                                            0xF5D5B0
#define pinstDZTimerInfo_x                                         0xF5D5B4
#define pinstEQItemList_x                                          0xF4CE3C
#define instEQMisc_x                                               0xB67A68
#define pinstEQSoundManager_x                                      0xE9DF88
#define instExpeditionLeader_x                                     0xF5D4EA
#define instExpeditionName_x                                       0xF5D52A
#define pinstGroup_x                                               0xF4E1B6
#define pinstImeManager_x                                          0x1758AD4
#define pinstLocalPlayer_x                                         0xF506F8
#define pinstMercenaryData_x                                       0xFE2A18
#define pinstMercAltAbilities_x                                    0xE9DEA8
#define pinstModelPlayer_x                                         0xF50724
#define pinstPCData_x                                              0xF506E4
#define pinstSkillMgr_x                                            0xFE3850
#define pinstSpawnManager_x                                        0xFE3138
#define pinstSpellManager_x                                        0xFE3998
#define pinstSpellSets_x                                           0xFDA910
#define pinstStringTable_x                                         0xF5068C
#define pinstSwitchManager_x                                       0xF4DD48
#define pinstTarget_x                                              0xF50710
#define pinstTargetObject_x                                        0xF506E8
#define pinstTargetSwitch_x                                        0xF506EC
#define pinstTaskMember_x                                          0xE9CA90
#define pinstTrackTarget_x                                         0xF50704
#define pinstTradeTarget_x                                         0xF506F4
#define instTributeActive_x                                        0xB67A8D
#define pinstViewActor_x                                           0xE9D590
#define pinstWorldData_x                                           0xF506C8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD61678
#define pinstCAudioTriggersWindow_x                                0xD61508
#define pinstCCharacterSelect_x                                    0xE9D43C
#define pinstCFacePick_x                                           0xE9D1EC
#define pinstCNoteWnd_x                                            0xE9D3F4
#define pinstCBookWnd_x                                            0xE9D3FC
#define pinstCPetInfoWnd_x                                         0xE9D400
#define pinstCTrainWnd_x                                           0xE9D404
#define pinstCSkillsWnd_x                                          0xE9D408
#define pinstCSkillsSelectWnd_x                                    0xE9D40C
#define pinstCCombatSkillSelectWnd_x                               0xE9D410
#define pinstCFriendsWnd_x                                         0xE9D414
#define pinstCAuraWnd_x                                            0xE9D418
#define pinstCRespawnWnd_x                                         0xE9D41C
#define pinstCBandolierWnd_x                                       0xE9D420
#define pinstCPotionBeltWnd_x                                      0xE9D424
#define pinstCAAWnd_x                                              0xE9D428
#define pinstCGroupSearchFiltersWnd_x                              0xE9D42C
#define pinstCLoadskinWnd_x                                        0xE9D430
#define pinstCAlarmWnd_x                                           0xE9D434
#define pinstCMusicPlayerWnd_x                                     0xE9D438
#define pinstCMailWnd_x                                            0xE9D440
#define pinstCMailCompositionWnd_x                                 0xE9D444
#define pinstCMailAddressBookWnd_x                                 0xE9D448
#define pinstCRaidWnd_x                                            0xE9D450
#define pinstCRaidOptionsWnd_x                                     0xE9D454
#define pinstCBreathWnd_x                                          0xE9D458
#define pinstCMapViewWnd_x                                         0xE9D45C
#define pinstCMapToolbarWnd_x                                      0xE9D460
#define pinstCEditLabelWnd_x                                       0xE9D464
#define pinstCTargetWnd_x                                          0xE9D468
#define pinstCColorPickerWnd_x                                     0xE9D46C
#define pinstCPlayerWnd_x                                          0xE9D470
#define pinstCOptionsWnd_x                                         0xE9D474
#define pinstCBuffWindowNORMAL_x                                   0xE9D478
#define pinstCBuffWindowSHORT_x                                    0xE9D47C
#define pinstCharacterCreation_x                                   0xE9D480
#define pinstCCursorAttachment_x                                   0xE9D484
#define pinstCCastingWnd_x                                         0xE9D488
#define pinstCCastSpellWnd_x                                       0xE9D48C
#define pinstCSpellBookWnd_x                                       0xE9D490
#define pinstCInventoryWnd_x                                       0xE9D494
#define pinstCBankWnd_x                                            0xE9D498
#define pinstCQuantityWnd_x                                        0xE9D49C
#define pinstCLootWnd_x                                            0xE9D4A0
#define pinstCActionsWnd_x                                         0xE9D4A4
#define pinstCCombatAbilityWnd_x                                   0xE9D4A8
#define pinstCMerchantWnd_x                                        0xE9D4AC
#define pinstCTradeWnd_x                                           0xE9D4B0
#define pinstCSelectorWnd_x                                        0xE9D4B4
#define pinstCBazaarWnd_x                                          0xE9D4B8
#define pinstCBazaarSearchWnd_x                                    0xE9D4BC
#define pinstCGiveWnd_x                                            0xE9D4D8
#define pinstCTrackingWnd_x                                        0xE9D4E0
#define pinstCInspectWnd_x                                         0xE9D4E4
#define pinstCSocialEditWnd_x                                      0xE9D4E8
#define pinstCFeedbackWnd_x                                        0xE9D4EC
#define pinstCBugReportWnd_x                                       0xE9D4F0
#define pinstCVideoModesWnd_x                                      0xE9D4F4
#define pinstCTextEntryWnd_x                                       0xE9D4FC
#define pinstCFileSelectionWnd_x                                   0xE9D500
#define pinstCCompassWnd_x                                         0xE9D504
#define pinstCPlayerNotesWnd_x                                     0xE9D508
#define pinstCGemsGameWnd_x                                        0xE9D50C
#define pinstCTimeLeftWnd_x                                        0xE9D510
#define pinstCPetitionQWnd_x                                       0xE9D524
#define pinstCSoulmarkWnd_x                                        0xE9D528
#define pinstCStoryWnd_x                                           0xE9D52C
#define pinstCJournalTextWnd_x                                     0xE9D530
#define pinstCJournalCatWnd_x                                      0xE9D534
#define pinstCBodyTintWnd_x                                        0xE9D538
#define pinstCServerListWnd_x                                      0xE9D53C
#define pinstCAvaZoneWnd_x                                         0xE9D548
#define pinstCBlockedBuffWnd_x                                     0xE9D54C
#define pinstCBlockedPetBuffWnd_x                                  0xE9D550
#define pinstCInvSlotMgr_x                                         0xE9D588
#define pinstCContainerMgr_x                                       0xE9D58C
#define pinstCAdventureLeaderboardWnd_x                            0x10EFB80
#define pinstCAdventureRequestWnd_x                                0x10EFBF8
#define pinstCAltStorageWnd_x                                      0x10EFED8
#define pinstCAdventureStatsWnd_x                                  0x10EFC70
#define pinstCBarterMerchantWnd_x                                  0x10F0AC0
#define pinstCBarterSearchWnd_x                                    0x10F0B38
#define pinstCBarterWnd_x                                          0x10F0BB0
#define pinstCChatManager_x                                        0x10F1240
#define pinstCDynamicZoneWnd_x                                     0x10F16F0
#define pinstCEQMainWnd_x                                          0x10F1888
#define pinstCFellowshipWnd_x                                      0x10F1684
#define pinstCFindLocationWnd_x                                    0x10F1B58
#define pinstCGroupSearchWnd_x                                     0x10F1E28
#define pinstCGroupWnd_x                                           0x10F1EA0
#define pinstCGuildBankWnd_x                                       0x10F1F18
#define pinstCGuildMgmtWnd_x                                       0x10F4008
#define pinstCHotButtonWnd_x                                       0x10F40D4
#define pinstCHotButtonWnd1_x                                      0x10F40D4
#define pinstCHotButtonWnd2_x                                      0x10F40D8
#define pinstCHotButtonWnd3_x                                      0x10F40DC
#define pinstCHotButtonWnd4_x                                      0x10F4100
#define pinstCItemDisplayManager_x                                 0x10F43F8
#define pinstCItemExpTransferWnd_x                                 0x10F4474
#define pinstCLFGuildWnd_x                                         0x10F4750
#define pinstCMIZoneSelectWnd_x                                    0x10F4D38
#define pinstCConfirmationDialog_x                                 0x10F5440
#define pinstCPopupWndManager_x                                    0x10F5440
#define pinstCProgressionSelectionWnd_x                            0x10F5530
#define pinstCPvPStatsWnd_x                                        0x10F5620
#define pinstCSystemInfoDialogBox_x                                0x10F5D28
#define pinstCTaskWnd_x                                            0x10F70F0
#define pinstCTaskTemplateSelectWnd_x                              0x10F7078
#define pinstCTipWndOFDAY_x                                        0x10F7348
#define pinstCTipWndCONTEXT_x                                      0x10F734C
#define pinstCTitleWnd_x                                           0x10F73C8
#define pinstCContextMenuManager_x                                 0x17586E4
#define pinstCVoiceMacroWnd_x                                      0xFE4000
#define pinstCHtmlWnd_x                                            0xFE40F8
#define pinstIconCache_x                                           0x10F185C
#define pinstCTradeskillWnd_x                                      0x10F74C8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x508FF0
#define __ConvertItemTags_x                                        0x4F61A0
#define __ExecuteCmd_x                                             0x4E0CE0
#define __EQGetTime_x                                              0x83C170
#define __get_melee_range_x                                        0x4E79A0
#define __GetGaugeValueFromEQ_x                                    0x77B9A0
#define __GetLabelFromEQ_x                                         0x77CBE0
#define __GetXTargetType_x                                         0x8F9720
#define __LoadFrontEnd_x                                           0x60A980
#define __NewUIINI_x                                               0x77B2E0
#define __ProcessGameEvents_x                                      0x54CE30
#define __ProcessMouseEvent_x                                      0x54C5D0
#define CrashDetected_x                                            0x60C450
#define DrawNetStatus_x                                            0x5835F0
#define Util__FastTime_x                                           0x83B480
#define Expansion_HoT_x                                            0xF5E9E4
#define __HelpPath_x                                               0xFE2150
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A61E0
#define AltAdvManager__IsAbilityReady_x                            0x4A6250
#define AltAdvManager__GetAltAbility_x                             0x4A6610

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4530A0
#define CharacterZoneClient__MakeMeVisible_x                       0x458160

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x63A070

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x647F60

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x562DE0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x663410
#define CChatManager__InitContextMenu_x                            0x663F30

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x7E1970
#define CChatService__GetFriendName_x                              0x822050

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x668D80
#define CChatWindow__Clear_x                                       0x668930
#define CChatWindow__WndNotification_x                             0x6692C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x89A8C0
#define CComboWnd__Draw_x                                          0x89AAA0
#define CComboWnd__GetCurChoice_x                                  0x89A6E0
#define CComboWnd__GetListRect_x                                   0x89AD40
#define CComboWnd__GetTextRect_x                                   0x89A920
#define CComboWnd__InsertChoice_x                                  0x89ADB0
#define CComboWnd__SetColors_x                                     0x89A670
#define CComboWnd__SetChoice_x                                     0x89A6A0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6724E0
#define CContainerWnd__vftable_x                                   0xA60008

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x494AB0
#define CDisplay__GetClickedActor_x                                0x48D550
#define CDisplay__GetUserDefinedColor_x                            0x48BE10
#define CDisplay__GetWorldFilePath_x                               0x48B210
#define CDisplay__is3dON_x                                         0x48A5E0
#define CDisplay__ReloadUI_x                                       0x49FF10
#define CDisplay__WriteTextHD2_x                                   0x490DA0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8BC6E0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8AB2A0
#define CEditWnd__GetCharIndexPt_x                                 0x8AC2D0
#define CEditWnd__GetDisplayString_x                               0x8AB450
#define CEditWnd__GetHorzOffset_x                                  0x8AB790
#define CEditWnd__GetLineForPrintableChar_x                        0x8ABD90
#define CEditWnd__GetSelStartPt_x                                  0x8AC590
#define CEditWnd__GetSTMLSafeText_x                                0x8AB930
#define CEditWnd__PointFromPrintableChar_x                         0x8ABE80
#define CEditWnd__SelectableCharFromPoint_x                        0x8AC000
#define CEditWnd__SetEditable_x                                    0x8AB900

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x52A2D0
#define CEverQuest__DoTellWindow_x                                 0x52FC40
#define CEverQuest__DropHeldItemOnGround_x                         0x5386D0
#define CEverQuest__dsp_chat_x                                     0x5313E0
#define CEverQuest__Emote_x                                        0x531640
#define CEverQuest__EnterZone_x                                    0x544DA0
#define CEverQuest__GetBodyTypeDesc_x                              0x526C00
#define CEverQuest__GetClassDesc_x                                 0x52C7C0
#define CEverQuest__GetClassThreeLetterCode_x                      0x52CDC0
#define CEverQuest__GetDeityDesc_x                                 0x5274E0
#define CEverQuest__GetLangDesc_x                                  0x526F90
#define CEverQuest__GetRaceDesc_x                                  0x52CF80
#define CEverQuest__InterpretCmd_x                                 0x531F20
#define CEverQuest__LeftClickedOnPlayer_x                          0x549540
#define CEverQuest__LMouseUp_x                                     0x54B620
#define CEverQuest__RightClickedOnPlayer_x                         0x54A040
#define CEverQuest__RMouseUp_x                                     0x54B080
#define CEverQuest__SetGameState_x                                 0x52A970
#define CEverQuest__UPCNotificationFlush_x                         0x5330C0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x682FC0
#define CGaugeWnd__CalcLinesFillRect_x                             0x683020
#define CGaugeWnd__Draw_x                                          0x683450

// CGuild
#define CGuild__FindMemberByName_x                                 0x424990

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6A00F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6ADF20
#define CInvSlotMgr__MoveItem_x                                    0x6AEE60
#define CInvSlotMgr__SelectSlot_x                                  0x6ADFD0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6AD3C0
#define CInvSlot__SliderComplete_x                                 0x6AAD80
#define CInvSlot__GetItemBase_x                                    0x6AA210

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6B0000

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7784F0
#define CItemDisplayWnd__UpdateStrings_x                           0x6B1340

// CLabel 
#define CLabel__Draw_x                                             0x6CC080

// CListWnd 
#define CListWnd__AddColumn_x                                      0x888850
#define CListWnd__AddColumn1_x                                     0x888030
#define CListWnd__AddLine_x                                        0x887AE0
#define CListWnd__AddString_x                                      0x887CF0
#define CListWnd__CalculateFirstVisibleLine_x                      0x884BB0
#define CListWnd__CalculateVSBRange_x                              0x886CE0
#define CListWnd__ClearAllSel_x                                    0x883E70
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8876C0
#define CListWnd__Compare_x                                        0x8856B0
#define CListWnd__Draw_x                                           0x886940
#define CListWnd__DrawColumnSeparators_x                           0x8867D0
#define CListWnd__DrawHeader_x                                     0x884180
#define CListWnd__DrawItem_x                                       0x885D00
#define CListWnd__DrawLine_x                                       0x886470
#define CListWnd__DrawSeparator_x                                  0x886870
#define CListWnd__EnsureVisible_x                                  0x884D10
#define CListWnd__ExtendSel_x                                      0x885C10
#define CListWnd__GetColumnMinWidth_x                              0x883890
#define CListWnd__GetColumnWidth_x                                 0x8837B0
#define CListWnd__GetCurSel_x                                      0x882F90
#define CListWnd__GetItemAtPoint_x                                 0x884FB0
#define CListWnd__GetItemAtPoint1_x                                0x885020
#define CListWnd__GetItemData_x                                    0x8832C0
#define CListWnd__GetItemHeight_x                                  0x884810
#define CListWnd__GetItemIcon_x                                    0x8834A0
#define CListWnd__GetItemRect_x                                    0x884DF0
#define CListWnd__GetItemText_x                                    0x883350
#define CListWnd__GetSelList_x                                     0x887F20
#define CListWnd__GetSeparatorRect_x                               0x8855E0
#define CListWnd__RemoveLine_x                                     0x887ED0
#define CListWnd__SetColors_x                                      0x8830E0
#define CListWnd__SetColumnJustification_x                         0x883B60
#define CListWnd__SetColumnWidth_x                                 0x883840
#define CListWnd__SetCurSel_x                                      0x882FD0
#define CListWnd__SetItemColor_x                                   0x8873A0
#define CListWnd__SetItemData_x                                    0x883F20
#define CListWnd__SetItemText_x                                    0x8871E0
#define CListWnd__ShiftColumnSeparator_x                           0x887070
#define CListWnd__Sort_x                                           0x8889B0
#define CListWnd__ToggleSel_x                                      0x883DF0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6E5600

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x706840
#define CMerchantWnd__RequestBuyItem_x                             0x70D6B0
#define CMerchantWnd__RequestSellItem_x                            0x735810
#define CMerchantWnd__SelectRecoverySlot_x                         0x706AF0
#define CMerchantWnd__SelectBuySellSlot_x                          0x705D50
#define CMerchantWnd__ActualSelect_x                               0x70A5D0

// CObfuscator
#define CObfuscator__doit_x                                        0x8024E0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8A0000
#define CSidlManager__CreateLabel_x                                0x76E500

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x631380
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6312A0
#define CSidlScreenWnd__ConvertToRes_x                             0x8BC5C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x88D9A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x88EEB0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x88EF60
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x88E420
#define CSidlScreenWnd__DrawSidlPiece_x                            0x88D480
#define CSidlScreenWnd__EnableIniStorage_x                         0x88CBC0
#define CSidlScreenWnd__GetSidlPiece_x                             0x88D670
#define CSidlScreenWnd__Init1_x                                    0x88EB90
#define CSidlScreenWnd__LoadIniInfo_x                              0x88DA50
#define CSidlScreenWnd__LoadIniListWnd_x                           0x88CD80
#define CSidlScreenWnd__LoadSidlScreen_x                           0x88E670
#define CSidlScreenWnd__StoreIniInfo_x                             0x88C680
#define CSidlScreenWnd__StoreIniVis_x                              0x88CB50
#define CSidlScreenWnd__WndNotification_x                          0x88E910
#define CSidlScreenWnd__GetChildItem_x                             0x88CC90
#define CSidlScreenWnd__HandleLButtonUp_x                          0x893850

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5CC9F0
#define CSkillMgr__GetSkillCap_x                                   0x5CCB90
#define CSkillMgr__GetNameToken_x                                  0x5CC660

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8C65B0
#define CSliderWnd__SetValue_x                                     0x8C6780
#define CSliderWnd__SetNumTicks_x                                  0x8C6F00

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x776190

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8B69A0
#define CStmlWnd__CalculateHSBRange_x                              0x8AEEF0
#define CStmlWnd__CalculateVSBRange_x                              0x8AEF80
#define CStmlWnd__CanBreakAtCharacter_x                            0x8AF100
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8AF9E0
#define CStmlWnd__ForceParseNow_x                                  0x8B72F0
#define CStmlWnd__GetNextTagPiece_x                                0x8AF8E0
#define CStmlWnd__GetSTMLText_x                                    0x6681D0
#define CStmlWnd__GetVisibleText_x                                 0x8B0430
#define CStmlWnd__InitializeWindowVariables_x                      0x8B27A0
#define CStmlWnd__MakeStmlColorTag_x                               0x8AE1F0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8AE250
#define CStmlWnd__SetSTMLText_x                                    0x8B4000
#define CStmlWnd__StripFirstSTMLLines_x                            0x8B6640
#define CStmlWnd__UpdateHistoryString_x                            0x8B1360

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8BDDC0
#define CTabWnd__DrawCurrentPage_x                                 0x8BD630
#define CTabWnd__DrawTab_x                                         0x8BD3F0
#define CTabWnd__GetCurrentPage_x                                  0x8BDA00
#define CTabWnd__GetPageInnerRect_x                                0x8BD0E0
#define CTabWnd__GetTabInnerRect_x                                 0x8BD2E0
#define CTabWnd__GetTabRect_x                                      0x8BD1B0
#define CTabWnd__InsertPage_x                                      0x8BE0B0
#define CTabWnd__SetPage_x                                         0x8BDA30
#define CTabWnd__SetPageRect_x                                     0x8BDD00
#define CTabWnd__UpdatePage_x                                      0x8BE050

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x420760

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B9E10

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8C2F70

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x881030

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x411A00
#define CXStr__CXStr1_x                                            0x718240
#define CXStr__CXStr3_x                                            0x838510
#define CXStr__dCXStr_x                                            0x718250
#define CXStr__operator_equal_x                                    0x838680
#define CXStr__operator_equal1_x                                   0x8386D0
#define CXStr__operator_plus_equal1_x                              0x8397B0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x892A80
#define CXWnd__Center_x                                            0x898D00
#define CXWnd__ClrFocus_x                                          0x892660
#define CXWnd__DoAllDrawing_x                                      0x898950
#define CXWnd__DrawChildren_x                                      0x898AF0
#define CXWnd__DrawColoredRect_x                                   0x892E20
#define CXWnd__DrawTooltip_x                                       0x8930C0
#define CXWnd__DrawTooltipAtPoint_x                                0x8978A0
#define CXWnd__GetBorderFrame_x                                    0x893520
#define CXWnd__GetChildWndAt_x                                     0x896860
#define CXWnd__GetClientClipRect_x                                 0x8932D0
#define CXWnd__GetScreenClipRect_x                                 0x897FA0
#define CXWnd__GetScreenRect_x                                     0x8936F0
#define CXWnd__GetTooltipRect_x                                    0x892F50
#define CXWnd__GetWindowTextA_x                                    0x411A40
#define CXWnd__IsActive_x                                          0x8A6020
#define CXWnd__IsDescendantOf_x                                    0x893460
#define CXWnd__IsReallyVisible_x                                   0x896840
#define CXWnd__IsType_x                                            0x8BF750
#define CXWnd__Move_x                                              0x895F60
#define CXWnd__Move1_x                                             0x8985F0
#define CXWnd__ProcessTransition_x                                 0x892A30
#define CXWnd__Refade_x                                            0x892810
#define CXWnd__Resize_x                                            0x8937B0
#define CXWnd__Right_x                                             0x897DA0
#define CXWnd__SetFocus_x                                          0x8950B0
#define CXWnd__SetFont_x                                           0x8926B0
#define CXWnd__SetKeyTooltip_x                                     0x893A20
#define CXWnd__SetMouseOver_x                                      0x8982E0
#define CXWnd__StartFade_x                                         0x892AD0
#define CXWnd__GetChildItem_x                                      0x898220

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A7950
#define CXWndManager__DrawWindows_x                                0x8A7590
#define CXWndManager__GetKeyboardFlags_x                           0x8A5B50
#define CXWndManager__HandleKeyboardMsg_x                          0x8A64B0
#define CXWndManager__RemoveWnd_x                                  0x8A61B0

// CDBStr
#define CDBStr__GetString_x                                        0x488A60

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8F6740
#define EQ_Character__CastSpell_x                                  0x43CA10
#define EQ_Character__Cur_HP_x                                     0x452760
#define EQ_Character__GetAACastingTimeModifier_x                   0x435B10
#define EQ_Character__GetCharInfo2_x                               0x80CBC0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42DE10
#define EQ_Character__GetFocusRangeModifier_x                      0x42DFF0
#define EQ_Character__Max_Endurance_x                              0x5957C0
#define EQ_Character__Max_HP_x                                     0x448A50
#define EQ_Character__Max_Mana_x                                   0x5955F0
#define EQ_Character__doCombatAbility_x                            0x592BE0
#define EQ_Character__UseSkill_x                                   0x45D2A0
#define EQ_Character__GetConLevel_x                                0x587C50
#define EQ_Character__IsExpansionFlag_x                            0x410F20
#define EQ_Character__TotalEffect_x                                0x43AB40

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x5685B0
#define EQ_Item__CreateItemTagString_x                             0x7ED000
#define EQ_Item__IsStackable_x                                     0x7E1590
#define EQ_Item__GetImageNum_x                                     0x7E4200

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A8310
#define EQ_LoadingS__Array_x                                       0xB75258

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x596F60
#define EQ_PC__GetAltAbilityIndex_x                                0x7F5280
#define EQ_PC__GetCombatAbility_x                                  0x7F5310
#define EQ_PC__GetCombatAbilityTimer_x                             0x7F53C0
#define EQ_PC__GetItemTimerValue_x                                 0x5909D0
#define EQ_PC__HasLoreItem_x                                       0x58AF30
#define EQ_PC__AlertInventoryChanged_x                             0x587C20
#define EQ_PC__GetPcZoneClient_x                                   0x5B1330
#define EQ_PC__RemoveMyAffect_x									   0x58FEE0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E5970
#define EQItemList__add_item_x                                     0x4E58B0
#define EQItemList__delete_item_x                                  0x4E5D70
#define EQItemList__FreeItemList_x                                 0x4E5C70

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487F30

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x59C3D0
#define EQPlayer__dEQPlayer_x                                      0x5A5040
#define EQPlayer__DoAttack_x                                       0x5B7130
#define EQPlayer__EQPlayer_x                                       0x5A7490
#define EQPlayer__SetNameSpriteState_x                             0x5A1DF0
#define EQPlayer__SetNameSpriteTint_x                              0x59D760
#define EQPlayer__IsBodyType_j_x                                   0x8F59D0
#define EQPlayer__IsTargetable_x                                   0x8F6220

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5AB8B0
#define EQPlayerManager__GetSpawnByName_x                          0x5ABD10

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56E7F0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56E830
#define KeypressHandler__ClearCommandStateArray_x                  0x56E3D0
#define KeypressHandler__HandleKeyDown_x                           0x56CD20
#define KeypressHandler__HandleKeyUp_x                             0x56D040
#define KeypressHandler__SaveKeymapping_x                          0x56E4A0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6DD9E0
#define MapViewMap__SaveEx_x                                       0x6E12C0

#define PlayerPointManager__GetAltCurrency_x                       0x806D80

// StringTable 
#define StringTable__getString_x                                   0x802780

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x595270

//Doors
#define EQSwitch__UseSwitch_x                                      0x523FD0

//IconCache
#define IconCache__GetIcon_x                                       0x678950

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66F800
#define CContainerMgr__CloseContainer_x                            0x670010

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x73E870

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5618A0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B6B70
#define EQ_Spell__SpellAffects_x                                   0x4B6C10
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B6C40
#define CharacterZoneClient__CalcAffectChange_x                    0x436E30
#define CLootWnd__LootAll_x                                        0x6D33D0
#define CTargetWnd__GetBuffCaster_x                                0x783F10
