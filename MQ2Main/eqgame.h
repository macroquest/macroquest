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
#define __ExpectedVersionDate                                     "May 13 2014"
#define __ExpectedVersionTime                                     "15:08:56"
#define __ActualVersionDate_x                                      0x9DE500
#define __ActualVersionTime_x                                      0x9DE50C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x571650
#define __MemChecker1_x                                            0x8320A0
#define __MemChecker2_x                                            0x607B50
#define __MemChecker3_x                                            0x607AA0
#define __MemChecker4_x                                            0x7B69E0
#define __EncryptPad0_x                                            0xB26930
#define __EncryptPad1_x                                            0xC9CE50
#define __EncryptPad2_x                                            0xB6D040
#define __EncryptPad3_x                                            0xB6CC40
#define __EncryptPad4_x                                            0xC7AEE0
#define __AC1_x                                                    0x774605
#define __AC2_x                                                    0x527D97
#define __AC3_x                                                    0x53C4F0
#define __AC4_x                                                    0x542620
#define __AC5_x                                                    0x54EC31
#define __AC6_x                                                    0x552752
#define __AC7_x                                                    0x54870C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x103D488
#define DI8__Keyboard_x                                            0x103D48C
#define DI8__Mouse_x                                               0x103D490
#define __AltTimerReady_x                                          0xE9D239
#define __Attack_x                                                 0xF30032
#define __Autofire_x                                               0xF30033
#define __BindList_x                                               0xAEB418
#define __Clicks_x                                                 0xEABE80
#define __CommandList_x                                            0xAEF488
#define __CurrentMapLabel_x                                        0x1043108
#define __CurrentSocial_x                                          0xAB18C0
#define __DoAbilityList_x                                          0xEE25E0
#define __do_loot_x                                                0x4F08D0
#define __DrawHandler_x                                            0x16A5664
#define __GroupCount_x                                             0xE9C912

#define __Guilds_x                                                 0xEA2400
#define __gWorld_x                                                 0xE9EDCC
#define __HotkeyPage_x                                             0xF28FE0
#define __HWnd_x                                                   0xF35390
#define __InChatMode_x                                             0xEABDAC
#define __LastTell_x                                               0xEADCE8
#define __LMouseHeldTime_x                                         0xEABEEC
#define __Mouse_x                                                  0x103D494
#define __MouseLook_x                                              0xEABE46
#define __MouseEventTime_x                                         0xF3081C
#define __NetStatusToggle_x                                        0xEABE49
#define __PCNames_x                                                0xEAD328
#define __RangeAttackReady_x                                       0xEACFC0
#define __RMouseHeldTime_x                                         0xEABEE8
#define __RunWalkState_x                                           0xEABDB0
#define __ScreenMode_x                                             0xDEB310
#define __ScreenX_x                                                0xEABD64
#define __ScreenY_x                                                0xEABD60
#define __ScreenXMax_x                                             0xEABD68
#define __ScreenYMax_x                                             0xEABD6C
#define __ServerHost_x                                             0xE9C85C
#define __ServerName_x                                             0xEE25A0
#define __ShiftKeyDown_x                                           0xEAC450
#define __ShowNames_x                                              0xEAD1CC
#define __Socials_x                                                0xEE26A0
#define __SubscriptionType_x                                       0x106CE38
#define __TargetAggroHolder_x                                      0x1045320
#define __GroupAggro_x                                             0x1045360
#define __LoginName_x                                              0xF33F68
#define __Inviter_x                                                0xF2FFB0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xE9EEB8
#define instEQZoneInfo_x                                           0xEAC03C
#define instKeypressHandler_x                                      0xF30800
#define pinstActiveBanker_x                                        0xE9EE70
#define pinstActiveCorpse_x                                        0xE9EE74
#define pinstActiveGMaster_x                                       0xE9EE78
#define pinstActiveMerchant_x                                      0xE9EE6C
#define pinstAggroInfo_x                                           0xCAF8F8
#define pinstAltAdvManager_x                                       0xDEC3E0
#define pinstAuraMgr_x                                             0xCB97C0
#define pinstBandageTarget_x                                       0xE9EE58
#define pinstCamActor_x                                            0xDEBCEC
#define pinstCDBStr_x                                              0xDEB2A4
#define pinstCDisplay_x                                            0xE9EE80
#define pinstCEverQuest_x                                          0x103D60C
#define pinstCharData_x                                            0xE9EE3C
#define pinstCharSpawn_x                                           0xE9EE64
#define pinstControlledMissile_x                                   0xE9EE38
#define pinstControlledPlayer_x                                    0xE9EE64
#define pinstCSidlManager_x                                        0x16A4AD0
#define pinstCXWndManager_x                                        0x16A4AC8
#define instDynamicZone_x                                          0xEABBF8
#define pinstDZMember_x                                            0xEABD08
#define pinstDZTimerInfo_x                                         0xEABD0C
#define pinstEQItemList_x                                          0xE9B594
#define instEQMisc_x                                               0xACCD80
#define pinstEQSoundManager_x                                      0xDEC6E0
#define instExpeditionLeader_x                                     0xEABC42
#define instExpeditionName_x                                       0xEABC82
#define pinstGroup_x                                               0xE9C90E
#define pinstImeManager_x                                          0x16A4AD4
#define pinstLocalPlayer_x                                         0xE9EE50
#define pinstMercenaryData_x                                       0xF30E50
#define pinstMercAltAbilities_x                                    0xDEC600
#define pinstModelPlayer_x                                         0xE9EE7C
#define pinstPCData_x                                              0xE9EE3C
#define pinstSkillMgr_x                                            0xF31C88
#define pinstSpawnManager_x                                        0xF31570
#define pinstSpellManager_x                                        0xF31DD0
#define pinstSpellSets_x                                           0xF29044
#define pinstStringTable_x                                         0xE9EDE4
#define pinstSwitchManager_x                                       0xE9C4A0
#define pinstTarget_x                                              0xE9EE68
#define pinstTargetObject_x                                        0xE9EE40
#define pinstTargetSwitch_x                                        0xE9EE44
#define pinstTaskMember_x                                          0xDEB1F0
#define pinstTrackTarget_x                                         0xE9EE5C
#define pinstTradeTarget_x                                         0xE9EE4C
#define instTributeActive_x                                        0xACCDA5
#define pinstViewActor_x                                           0xDEBCE8
#define pinstWorldData_x                                           0xE9EE20


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xCAFDD8
#define pinstCAudioTriggersWindow_x                                0xCAFC68
#define pinstCCharacterSelect_x                                    0xDEBB94
#define pinstCFacePick_x                                           0xDEB944
#define pinstCNoteWnd_x                                            0xDEBB4C
#define pinstCBookWnd_x                                            0xDEBB54
#define pinstCPetInfoWnd_x                                         0xDEBB58
#define pinstCTrainWnd_x                                           0xDEBB5C
#define pinstCSkillsWnd_x                                          0xDEBB60
#define pinstCSkillsSelectWnd_x                                    0xDEBB64
#define pinstCCombatSkillSelectWnd_x                               0xDEBB68
#define pinstCFriendsWnd_x                                         0xDEBB6C
#define pinstCAuraWnd_x                                            0xDEBB70
#define pinstCRespawnWnd_x                                         0xDEBB74
#define pinstCBandolierWnd_x                                       0xDEBB78
#define pinstCPotionBeltWnd_x                                      0xDEBB7C
#define pinstCAAWnd_x                                              0xDEBB80
#define pinstCGroupSearchFiltersWnd_x                              0xDEBB84
#define pinstCLoadskinWnd_x                                        0xDEBB88
#define pinstCAlarmWnd_x                                           0xDEBB8C
#define pinstCMusicPlayerWnd_x                                     0xDEBB90
#define pinstCMailWnd_x                                            0xDEBB98
#define pinstCMailCompositionWnd_x                                 0xDEBB9C
#define pinstCMailAddressBookWnd_x                                 0xDEBBA0
#define pinstCRaidWnd_x                                            0xDEBBA8
#define pinstCRaidOptionsWnd_x                                     0xDEBBAC
#define pinstCBreathWnd_x                                          0xDEBBB0
#define pinstCMapViewWnd_x                                         0xDEBBB4
#define pinstCMapToolbarWnd_x                                      0xDEBBB8
#define pinstCEditLabelWnd_x                                       0xDEBBBC
#define pinstCTargetWnd_x                                          0xDEBBC0
#define pinstCColorPickerWnd_x                                     0xDEBBC4
#define pinstCPlayerWnd_x                                          0xDEBBC8
#define pinstCOptionsWnd_x                                         0xDEBBCC
#define pinstCBuffWindowNORMAL_x                                   0xDEBBD0
#define pinstCBuffWindowSHORT_x                                    0xDEBBD4
#define pinstCharacterCreation_x                                   0xDEBBD8
#define pinstCCursorAttachment_x                                   0xDEBBDC
#define pinstCCastingWnd_x                                         0xDEBBE0
#define pinstCCastSpellWnd_x                                       0xDEBBE4
#define pinstCSpellBookWnd_x                                       0xDEBBE8
#define pinstCInventoryWnd_x                                       0xDEBBEC
#define pinstCBankWnd_x                                            0xDEBBF0
#define pinstCQuantityWnd_x                                        0xDEBBF4
#define pinstCLootWnd_x                                            0xDEBBF8
#define pinstCActionsWnd_x                                         0xDEBBFC
#define pinstCCombatAbilityWnd_x                                   0xDEBC00
#define pinstCMerchantWnd_x                                        0xDEBC04
#define pinstCTradeWnd_x                                           0xDEBC08
#define pinstCSelectorWnd_x                                        0xDEBC0C
#define pinstCBazaarWnd_x                                          0xDEBC10
#define pinstCBazaarSearchWnd_x                                    0xDEBC14
#define pinstCGiveWnd_x                                            0xDEBC30
#define pinstCTrackingWnd_x                                        0xDEBC38
#define pinstCInspectWnd_x                                         0xDEBC3C
#define pinstCSocialEditWnd_x                                      0xDEBC40
#define pinstCFeedbackWnd_x                                        0xDEBC44
#define pinstCBugReportWnd_x                                       0xDEBC48
#define pinstCVideoModesWnd_x                                      0xDEBC4C
#define pinstCTextEntryWnd_x                                       0xDEBC54
#define pinstCFileSelectionWnd_x                                   0xDEBC58
#define pinstCCompassWnd_x                                         0xDEBC5C
#define pinstCPlayerNotesWnd_x                                     0xDEBC60
#define pinstCGemsGameWnd_x                                        0xDEBC64
#define pinstCTimeLeftWnd_x                                        0xDEBC68
#define pinstCPetitionQWnd_x                                       0xDEBC7C
#define pinstCSoulmarkWnd_x                                        0xDEBC80
#define pinstCStoryWnd_x                                           0xDEBC84
#define pinstCJournalTextWnd_x                                     0xDEBC88
#define pinstCJournalCatWnd_x                                      0xDEBC8C
#define pinstCBodyTintWnd_x                                        0xDEBC90
#define pinstCServerListWnd_x                                      0xDEBC94
#define pinstCAvaZoneWnd_x                                         0xDEBCA0
#define pinstCBlockedBuffWnd_x                                     0xDEBCA4
#define pinstCBlockedPetBuffWnd_x                                  0xDEBCA8
#define pinstCInvSlotMgr_x                                         0xDEBCE0
#define pinstCContainerMgr_x                                       0xDEBCE4
#define pinstCAdventureLeaderboardWnd_x                            0x103E1E0
#define pinstCAdventureRequestWnd_x                                0x103E258
#define pinstCAltStorageWnd_x                                      0x103E538
#define pinstCAdventureStatsWnd_x                                  0x103E2D0
#define pinstCBarterMerchantWnd_x                                  0x103F120
#define pinstCBarterSearchWnd_x                                    0x103F198
#define pinstCBarterWnd_x                                          0x103F210
#define pinstCChatManager_x                                        0x103F8A0
#define pinstCDynamicZoneWnd_x                                     0x103FD50
#define pinstCEQMainWnd_x                                          0x103FEE8
#define pinstCFellowshipWnd_x                                      0x103FCE4
#define pinstCFindLocationWnd_x                                    0x10401B8
#define pinstCGroupSearchWnd_x                                     0x1040488
#define pinstCGroupWnd_x                                           0x1040500
#define pinstCGuildBankWnd_x                                       0x1040578
#define pinstCGuildMgmtWnd_x                                       0x1042668
#define pinstCHotButtonWnd_x                                       0x1042734
#define pinstCHotButtonWnd1_x                                      0x1042734
#define pinstCHotButtonWnd2_x                                      0x1042738
#define pinstCHotButtonWnd3_x                                      0x104273C
#define pinstCHotButtonWnd4_x                                      0x1042760
#define pinstCItemDisplayManager_x                                 0x1042A58
#define pinstCItemExpTransferWnd_x                                 0x1042AD4
#define pinstCLFGuildWnd_x                                         0x1042DB0
#define pinstCMIZoneSelectWnd_x                                    0x1043398
#define pinstCConfirmationDialog_x                                 0x1043AA0
#define pinstCPopupWndManager_x                                    0x1043AA0
#define pinstCProgressionSelectionWnd_x                            0x1043B90
#define pinstCPvPStatsWnd_x                                        0x1043C80
#define pinstCSystemInfoDialogBox_x                                0x1044388
#define pinstCTaskWnd_x                                            0x1045718
#define pinstCTaskTemplateSelectWnd_x                              0x10456A0
#define pinstCTipWndOFDAY_x                                        0x1045970
#define pinstCTipWndCONTEXT_x                                      0x1045974
#define pinstCTitleWnd_x                                           0x10459F0
#define pinstCContextMenuManager_x                                 0x16A46E4
#define pinstCVoiceMacroWnd_x                                      0xF32438
#define pinstCHtmlWnd_x                                            0xF32530
#define pinstIconCache_x                                           0x103FEBC
#define pinstCTradeskillWnd_x                                      0x1045AF0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x507510
#define __ConvertItemTags_x                                        0x4F5590
#define __ExecuteCmd_x                                             0x4E0330
#define __EQGetTime_x                                              0x832C00
#define __get_melee_range_x                                        0x4E6F70
#define __GetGaugeValueFromEQ_x                                    0x773360
#define __GetLabelFromEQ_x                                         0x774590
#define __GetXTargetType_x                                         0x8EF5B0
#define __LoadFrontEnd_x                                           0x607200
#define __NewUIINI_x                                               0x772C90
#define __ProcessGameEvents_x                                      0x54A850
#define CrashDetected_x                                            0x608CD0
#define DrawNetStatus_x                                            0x580DA0
#define Util__FastTime_x                                           0x831F10
#define Expansion_HoT_x                                            0xEAD12C
#define __HelpPath_x                                               0xF30588
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A4D50
#define AltAdvManager__IsAbilityReady_x                            0x4A4DC0
#define AltAdvManager__GetAltAbility_x                             0x4A5180

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x452000

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x636DD0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x645190

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x560F20

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x65FF50
#define CChatManager__InitContextMenu_x                            0x660A70

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x7D8F30
#define CChatService__GetFriendName_x                              0x818DB0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x665810
#define CChatWindow__Clear_x                                       0x6653C0
#define CChatWindow__WndNotification_x                             0x665D50

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x891260
#define CComboWnd__Draw_x                                          0x891440
#define CComboWnd__GetCurChoice_x                                  0x891080
#define CComboWnd__GetListRect_x                                   0x8916E0
#define CComboWnd__GetTextRect_x                                   0x8912C0
#define CComboWnd__InsertChoice_x                                  0x891750
#define CComboWnd__SetColors_x                                     0x891010
#define CComboWnd__SetChoice_x                                     0x891040

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x66EE80
#define CContainerWnd__vftable_x                                   0x9E7CB0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x493780
#define CDisplay__GetClickedActor_x                                0x48C3B0
#define CDisplay__GetUserDefinedColor_x                            0x48AC70
#define CDisplay__GetWorldFilePath_x                               0x48A070
#define CDisplay__is3dON_x                                         0x489440
#define CDisplay__ReloadUI_x                                       0x49EB50
#define CDisplay__WriteTextHD2_x                                   0x48FBF0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8B2D70

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8A1CE0
#define CEditWnd__GetCharIndexPt_x                                 0x8A2D00
#define CEditWnd__GetDisplayString_x                               0x8A1E90
#define CEditWnd__GetHorzOffset_x                                  0x8A21D0
#define CEditWnd__GetLineForPrintableChar_x                        0x8A27D0
#define CEditWnd__GetSelStartPt_x                                  0x8A2FB0
#define CEditWnd__GetSTMLSafeText_x                                0x8A2370
#define CEditWnd__PointFromPrintableChar_x                         0x8A28C0
#define CEditWnd__SelectableCharFromPoint_x                        0x8A2A40
#define CEditWnd__SetEditable_x                                    0x8A2340

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x5284E0
#define CEverQuest__DoTellWindow_x                                 0x52DED0
#define CEverQuest__DropHeldItemOnGround_x                         0x536970
#define CEverQuest__dsp_chat_x                                     0x52F670
#define CEverQuest__Emote_x                                        0x52F8D0
#define CEverQuest__EnterZone_x                                    0x5427B0
#define CEverQuest__GetBodyTypeDesc_x                              0x524E10
#define CEverQuest__GetClassDesc_x                                 0x52AA40
#define CEverQuest__GetClassThreeLetterCode_x                      0x52B040
#define CEverQuest__GetDeityDesc_x                                 0x5256F0
#define CEverQuest__GetLangDesc_x                                  0x5251A0
#define CEverQuest__GetRaceDesc_x                                  0x52B200
#define CEverQuest__InterpretCmd_x                                 0x5301B0
#define CEverQuest__LeftClickedOnPlayer_x                          0x546B80
#define CEverQuest__LMouseUp_x                                     0x548E70
#define CEverQuest__RightClickedOnPlayer_x                         0x547680
#define CEverQuest__RMouseUp_x                                     0x5486C0
#define CEverQuest__SetGameState_x                                 0x528B90
#define CEverQuest__UPCNotificationFlush_x                         0x531350

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x67F850
#define CGaugeWnd__CalcLinesFillRect_x                             0x67F8B0
#define CGaugeWnd__Draw_x                                          0x67FCE0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4240C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69C050

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6A7DC0
#define CInvSlotMgr__MoveItem_x                                    0x6A8D00
#define CInvSlotMgr__SelectSlot_x                                  0x6A7E70

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6A70F0
#define CInvSlot__SliderComplete_x                                 0x6A4F40
#define CInvSlot__GetItemBase_x                                    0x6A43D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6A9AB0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x76FFB0
#define CItemDisplayWnd__UpdateStrings_x                           0x6AADE0

// CLabel 
#define CLabel__Draw_x                                             0x6C5780

// CListWnd 
#define CListWnd__AddColumn_x                                      0x87F160
#define CListWnd__AddColumn1_x                                     0x87E950
#define CListWnd__AddLine_x                                        0x87E400
#define CListWnd__AddString_x                                      0x87E610
#define CListWnd__CalculateFirstVisibleLine_x                      0x87B4E0
#define CListWnd__CalculateVSBRange_x                              0x87D600
#define CListWnd__ClearAllSel_x                                    0x87A790
#define CListWnd__CloseAndUpdateEditWindow_x                       0x87DFD0
#define CListWnd__Compare_x                                        0x87BFD0
#define CListWnd__Draw_x                                           0x87D260
#define CListWnd__DrawColumnSeparators_x                           0x87D0F0
#define CListWnd__DrawHeader_x                                     0x87AAA0
#define CListWnd__DrawItem_x                                       0x87C620
#define CListWnd__DrawLine_x                                       0x87CD90
#define CListWnd__DrawSeparator_x                                  0x87D190
#define CListWnd__EnsureVisible_x                                  0x87B640
#define CListWnd__ExtendSel_x                                      0x87C530
#define CListWnd__GetColumnMinWidth_x                              0x87A1B0
#define CListWnd__GetColumnWidth_x                                 0x87A0D0
#define CListWnd__GetCurSel_x                                      0x879990
#define CListWnd__GetItemAtPoint_x                                 0x87B8D0
#define CListWnd__GetItemAtPoint1_x                                0x87B940
#define CListWnd__GetItemData_x                                    0x879BE0
#define CListWnd__GetItemHeight_x                                  0x87B130
#define CListWnd__GetItemIcon_x                                    0x879DC0
#define CListWnd__GetItemRect_x                                    0x87B710
#define CListWnd__GetItemText_x                                    0x879C70
#define CListWnd__GetSelList_x                                     0x87E840
#define CListWnd__GetSeparatorRect_x                               0x87BEF0
#define CListWnd__RemoveLine_x                                     0x87E7F0
#define CListWnd__SetColors_x                                      0x8799F0
#define CListWnd__SetColumnJustification_x                         0x87A480
#define CListWnd__SetColumnWidth_x                                 0x87A160
#define CListWnd__SetCurSel_x                                      0x8799D0
#define CListWnd__SetItemColor_x                                   0x87DCB0
#define CListWnd__SetItemData_x                                    0x87A840
#define CListWnd__SetItemText_x                                    0x87DAF0
#define CListWnd__ShiftColumnSeparator_x                           0x87D980
#define CListWnd__Sort_x                                           0x87F2CD
#define CListWnd__ToggleSel_x                                      0x87A710

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6DEA20

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6FF8D0
#define CMerchantWnd__RequestBuyItem_x                             0x705E20
#define CMerchantWnd__RequestSellItem_x                            0x72D760
#define CMerchantWnd__SelectRecoverySlot_x                         0x6FFB80
#define CMerchantWnd__SelectBuySellSlot_x                          0x6FED90
#define CMerchantWnd__ActualSelect_x                               0x7032A0

// CObfuscator
#define CObfuscator__doit_x                                        0x7F9770

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x896A50
#define CSidlManager__CreateLabel_x                                0x766460

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x62DF80
#define CSidlScreenWnd__CalculateVSBRange_x                        0x62DEB0
#define CSidlScreenWnd__ConvertToRes_x                             0x8B2C50
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x884290
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x885780
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x885830
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x884D00
#define CSidlScreenWnd__DrawSidlPiece_x                            0x883D70
#define CSidlScreenWnd__EnableIniStorage_x                         0x8834B0
#define CSidlScreenWnd__GetSidlPiece_x                             0x883F60
#define CSidlScreenWnd__Init1_x                                    0x885460
#define CSidlScreenWnd__LoadIniInfo_x                              0x884340
#define CSidlScreenWnd__LoadIniListWnd_x                           0x883670
#define CSidlScreenWnd__LoadSidlScreen_x                           0x884F50
#define CSidlScreenWnd__StoreIniInfo_x                             0x882F70
#define CSidlScreenWnd__StoreIniVis_x                              0x883440
#define CSidlScreenWnd__WndNotification_x                          0x8851E0
#define CSidlScreenWnd__GetChildItem_x                             0x883580
#define CSidlScreenWnd__HandleLButtonUp_x                          0x88A280

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5C9350
#define CSkillMgr__GetSkillCap_x                                   0x5C94F0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8BCC50
#define CSliderWnd__SetValue_x                                     0x8BCE20
#define CSliderWnd__SetNumTicks_x                                  0x8BD5A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x76DC50

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8AD380
#define CStmlWnd__CalculateHSBRange_x                              0x8A59B0
#define CStmlWnd__CalculateVSBRange_x                              0x8A5A40
#define CStmlWnd__CanBreakAtCharacter_x                            0x8A5BC0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8A64A0
#define CStmlWnd__ForceParseNow_x                                  0x8ADCD0
#define CStmlWnd__GetNextTagPiece_x                                0x8A63A0
#define CStmlWnd__GetSTMLText_x                                    0x664C60
#define CStmlWnd__GetVisibleText_x                                 0x8A6EF0
#define CStmlWnd__InitializeWindowVariables_x                      0x8A91A0
#define CStmlWnd__MakeStmlColorTag_x                               0x8A4B90
#define CStmlWnd__MakeWndNotificationTag_x                         0x8A4BF0
#define CStmlWnd__SetSTMLText_x                                    0x8AAA00
#define CStmlWnd__StripFirstSTMLLines_x                            0x8AD020
#define CStmlWnd__UpdateHistoryString_x                            0x8A7E30

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8B4450
#define CTabWnd__DrawCurrentPage_x                                 0x8B3CC0
#define CTabWnd__DrawTab_x                                         0x8B3A80
#define CTabWnd__GetCurrentPage_x                                  0x8B4090
#define CTabWnd__GetPageInnerRect_x                                0x8B3770
#define CTabWnd__GetTabInnerRect_x                                 0x8B3970
#define CTabWnd__GetTabRect_x                                      0x8B3840
#define CTabWnd__InsertPage_x                                      0x8B4740
#define CTabWnd__SetPage_x                                         0x8B40C0
#define CTabWnd__SetPageRect_x                                     0x8B4390
#define CTabWnd__UpdatePage_x                                      0x8B46E0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41FE30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B0820

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8B9610

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x877B80

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x56DDB0
#define CXStr__CXStr1_x                                            0x42E5E0
#define CXStr__CXStr3_x                                            0x82EFA0
#define CXStr__dCXStr_x                                            0x5CC030
#define CXStr__operator_equal_x                                    0x82F110
#define CXStr__operator_equal1_x                                   0x82F160
#define CXStr__operator_plus_equal1_x                              0x830240

// CXWnd 
#define CXWnd__BringToTop_x                                        0x889480
#define CXWnd__Center_x                                            0x88F6A0
#define CXWnd__ClrFocus_x                                          0x889050
#define CXWnd__DoAllDrawing_x                                      0x88F2D0
#define CXWnd__DrawChildren_x                                      0x88F480
#define CXWnd__DrawColoredRect_x                                   0x889840
#define CXWnd__DrawTooltip_x                                       0x889AE0
#define CXWnd__DrawTooltipAtPoint_x                                0x88E2B0
#define CXWnd__GetBorderFrame_x                                    0x889F50
#define CXWnd__GetChildWndAt_x                                     0x88D260
#define CXWnd__GetClientClipRect_x                                 0x889D00
#define CXWnd__GetScreenClipRect_x                                 0x88E9B0
#define CXWnd__GetScreenRect_x                                     0x88A120
#define CXWnd__GetTooltipRect_x                                    0x889970
#define CXWnd__GetWindowTextA_x                                    0x411650
#define CXWnd__IsActive_x                                          0x89CA20
#define CXWnd__IsDescendantOf_x                                    0x889E90
#define CXWnd__IsReallyVisible_x                                   0x88D240
#define CXWnd__IsType_x                                            0x8B5E10
#define CXWnd__Move_x                                              0x88C9B0
#define CXWnd__Move1_x                                             0x88EFA0
#define CXWnd__ProcessTransition_x                                 0x889420
#define CXWnd__Refade_x                                            0x889200
#define CXWnd__Resize_x                                            0x88A1E0
#define CXWnd__Right_x                                             0x88E7B0
#define CXWnd__SetFocus_x                                          0x88BB00
#define CXWnd__SetFont_x                                           0x8890A0
#define CXWnd__SetKeyTooltip_x                                     0x88A450
#define CXWnd__SetMouseOver_x                                      0x88ECA0
#define CXWnd__StartFade_x                                         0x8894D0
#define CXWnd__GetChildItem_x                                      0x88EBF0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x89E340
#define CXWndManager__DrawWindows_x                                0x89DF80
#define CXWndManager__GetKeyboardFlags_x                           0x89C550
#define CXWndManager__HandleKeyboardMsg_x                          0x89CEA0
#define CXWndManager__RemoveWnd_x                                  0x89CBB0

// CDBStr
#define CDBStr__GetString_x                                        0x487830

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8EBE60
#define EQ_Character__CastSpell_x                                  0x43BDE0
#define EQ_Character__Cur_HP_x                                     0x4516C0
#define EQ_Character__GetAACastingTimeModifier_x                   0x434F40
#define EQ_Character__GetCharInfo2_x                               0x803A10
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42D220
#define EQ_Character__GetFocusRangeModifier_x                      0x42D400
#define EQ_Character__Max_Endurance_x                              0x592470
#define EQ_Character__Max_HP_x                                     0x447DB0
#define EQ_Character__Max_Mana_x                                   0x5922A0
#define EQ_Character__doCombatAbility_x                            0x58FAD0
#define EQ_Character__UseSkill_x                                   0x45C200
#define EQ_Character__GetConLevel_x                                0x5853B0
#define EQ_Character__IsExpansionFlag_x                            0x410B80
#define EQ_Character__TotalEffect_x                                0x439F10

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x565F20
#define EQ_Item__CreateItemTagString_x                             0x7E4670
#define EQ_Item__IsStackable_x                                     0x7D88B0
#define EQ_Item__GetImageNum_x                                     0x7DB500

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A6E50
#define EQ_LoadingS__Array_x                                       0xADA320

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x593AD0
#define EQ_PC__GetAltAbilityIndex_x                                0x7EC930
#define EQ_PC__GetCombatAbility_x                                  0x7EC9C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x7ECA70
#define EQ_PC__GetItemTimerValue_x                                 0x58D8B0
#define EQ_PC__HasLoreItem_x                                       0x588540
#define EQ_PC__AlertInventoryChanged_x                             0x585380
#define EQ_PC__GetPcZoneClient_x                                   0x5AD560
// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E4EF0
#define EQItemList__add_item_x                                     0x4E4E30
#define EQItemList__delete_item_x                                  0x4E52F0
#define EQItemList__FreeItemList_x                                 0x4E51F0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x486D20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x598F10
#define EQPlayer__dEQPlayer_x                                      0x5A1A10
#define EQPlayer__DoAttack_x                                       0x5B3390
#define EQPlayer__EQPlayer_x                                       0x5A3E60
#define EQPlayer__SetNameSpriteState_x                             0x59E830
#define EQPlayer__SetNameSpriteTint_x                              0x59A240
#define EQPlayer__IsBodyType_j_x                                   0x8EB170
#define EQPlayer__IsTargetable_x                                   0x8EB940

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5A7AE0
#define EQPlayerManager__GetSpawnByName_x                          0x5A7F40

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56C0E0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56C120
#define KeypressHandler__ClearCommandStateArray_x                  0x56BCC0
#define KeypressHandler__HandleKeyDown_x                           0x56A610
#define KeypressHandler__HandleKeyUp_x                             0x56A930
#define KeypressHandler__SaveKeymapping_x                          0x56BD90

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6D6E40
#define MapViewMap__SaveEx_x                                       0x6DA720

#define PlayerPointManager__GetAltCurrency_x                       0x7FDB00

// StringTable 
#define StringTable__getString_x                                   0x7F9A10

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x591F20

//Doors
#define EQSwitch__UseSwitch_x                                      0x5221E0

//IconCache
#define IconCache__GetIcon_x                                       0x675170

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66C1B0
#define CContainerMgr__CloseContainer_x                            0x66C9C0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7367B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x55FA00

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B5380
#define EQ_Spell__SpellAffects_x                                   0x4B5420
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B5450
#define CharacterZoneClient__CalcAffectChange_x                    0x436260
#define CLootWnd__LootAll_x                                        0x6CC950
#define CTargetWnd__GetBuffCaster_x                                0x77B7F0
