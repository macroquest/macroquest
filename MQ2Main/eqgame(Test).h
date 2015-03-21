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
#define __ExpectedVersionDate                                     "Mar 18 2015"
#define __ExpectedVersionTime                                     "14:12:02"
#define __ActualVersionDate_x                                      0xA7B120
#define __ActualVersionTime_x                                      0xA7B12C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x592400
#define __MemChecker1_x                                            0x85A520
#define __MemChecker2_x                                            0x629C40
#define __MemChecker3_x                                            0x629B90
#define __MemChecker4_x                                            0x7DE2F0
#define __EncryptPad0_x                                            0xBF6978
#define __EncryptPad1_x                                            0xD7AC90
#define __EncryptPad2_x                                            0xC3F8F8
#define __EncryptPad3_x                                            0xC3F4F8
#define __EncryptPad4_x                                            0xD573B8
#define __AC1_x                                                    0x79B645
#define __AC2_x                                                    0x548637
#define __AC3_x                                                    0x55CE20
#define __AC4_x                                                    0x563260
#define __AC5_x                                                    0x56F02E
#define __AC6_x                                                    0x572AF2
#define __AC7_x                                                    0x5696FC
#define __AC1_Data                                                 0x11111111

// Direct Input
#define DI8__Main_x                                                0x112CA60
#define DI8__Keyboard_x                                            0x112CA64
#define DI8__Mouse_x                                               0x112CA68
#define __AltTimerReady_x                                          0xF8C3D1
#define __Attack_x                                                 0x101F5EB
#define __Autofire_x                                               0x101F5EC
#define __BindList_x                                               0xBB93C8
#define __bCommandEnabled_x                                        0xF8A4E0
#define __Clicks_x                                                 0xF9B140
#define __CommandList_x                                            0xBBD690
#define __CurrentMapLabel_x                                        0x11324B8
#define __CurrentSocial_x                                          0xB76950
#define __DoAbilityList_x                                          0xFD18A0
#define __do_loot_x                                                0x50FFC0
#define __DrawHandler_x                                            0x17970C4
#define __GroupCount_x                                             0xF8BAAA

#define __Guilds_x                                                 0xF916C0
#define __gWorld_x                                                 0xF8DF64
#define __HotkeyPage_x                                             0x10182A0
#define __HWnd_x                                                   0x1024968
#define __InChatMode_x                                             0xF9B06C
#define __LastTell_x                                               0xF9CFA8
#define __LMouseHeldTime_x                                         0xF9B1AC
#define __Mouse_x                                                  0x112CA6C
#define __MouseLook_x                                              0xF9B106
#define __MouseEventTime_x                                         0x101FDF4
#define __NetStatusToggle_x                                        0xF9B109
#define __PCNames_x                                                0xF9C5CC
#define __RangeAttackReady_x                                       0xF9C290
#define __RMouseHeldTime_x                                         0xF9B1A8
#define __RunWalkState_x                                           0xF9B070
#define __ScreenMode_x                                             0xEDA398
#define __ScreenX_x                                                0xF9B024
#define __ScreenY_x                                                0xF9B020
#define __ScreenXMax_x                                             0xF9B028
#define __ScreenYMax_x                                             0xF9B02C
#define __ServerHost_x                                             0xF8B9F4
#define __ServerName_x                                             0xFD1860
#define __ShiftKeyDown_x                                           0xF9B714
#define __ShowNames_x                                              0xF9C464
#define __Socials_x                                                0xFD1960
#define __SubscriptionType_x                                       0x115E848
#define __TargetAggroHolder_x                                      0x11346F4
#define __GroupAggro_x                                             0x1134734
#define __LoginName_x                                              0x1023540
#define __Inviter_x                                                0x101F568


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF8E050
#define instEQZoneInfo_x                                           0xF9B2FC
#define instKeypressHandler_x                                      0x101FDD8
#define pinstActiveBanker_x                                        0xF8E008
#define pinstActiveCorpse_x                                        0xF8E00C
#define pinstActiveGMaster_x                                       0xF8E010
#define pinstActiveMerchant_x                                      0xF8E004
#define pinstAggroInfo_x                                           0xD9E818
#define pinstAltAdvManager_x                                       0xEDB480
#define pinstAuraMgr_x                                             0xDA86E0
#define pinstBandageTarget_x                                       0xF8DFF0
#define pinstCamActor_x                                            0xEDAD88
#define pinstCDBStr_x                                              0xEDA32C
#define pinstCDisplay_x                                            0xF8E018
#define pinstCEverQuest_x                                          0x112CBE0
#define pinstCharData_x                                            0xF8DFD4
#define pinstCharSpawn_x                                           0xF8DFFC
#define pinstControlledMissile_x                                   0xF8DFD0
#define pinstControlledPlayer_x                                    0xF8DFFC
#define pinstCSidlManager_x                                        0x1796518
#define pinstCXWndManager_x                                        0x1796510
#define instDynamicZone_x                                          0xF9AEB8
#define pinstDZMember_x                                            0xF9AFC8
#define pinstDZTimerInfo_x                                         0xF9AFCC
#define pinstEQItemList_x                                          0xF8A730
#define instEQMisc_x                                               0xB97110
#define pinstEQSoundManager_x                                      0xEDB878
#define instExpeditionLeader_x                                     0xF9AF02
#define instExpeditionName_x                                       0xF9AF42
#define pinstGroup_x                                               0xF8BAA6
#define pinstImeManager_x                                          0x179651C
#define pinstLocalPlayer_x                                         0xF8DFE8
#define pinstMercenaryData_x                                       0x1020428
#define pinstMercAltAbilities_x                                    0xEDB794
#define pinstModelPlayer_x                                         0xF8E014
#define pinstPCData_x                                              0xF8DFD4
#define pinstSkillMgr_x                                            0x1021260
#define pinstSpawnManager_x                                        0x1020B48
#define pinstSpellManager_x                                        0x10213A8
#define pinstSpellSets_x                                           0x1018304
#define pinstStringTable_x                                         0xF8DF7C
#define pinstSwitchManager_x                                       0xF8B638
#define pinstTarget_x                                              0xF8E000
#define pinstTargetObject_x                                        0xF8DFD8
#define pinstTargetSwitch_x                                        0xF8DFDC
#define pinstTaskMember_x                                          0xEDA278
#define pinstTrackTarget_x                                         0xF8DFF4
#define pinstTradeTarget_x                                         0xF8DFE4
#define instTributeActive_x                                        0xB97135
#define pinstViewActor_x                                           0xEDAD84
#define pinstWorldData_x                                           0xF8DFB8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD9ECF8
#define pinstCAudioTriggersWindow_x                                0xD9EB88
#define pinstCCharacterSelect_x                                    0xEDAC28
#define pinstCFacePick_x                                           0xEDABD8
#define pinstCNoteWnd_x                                            0xEDABE0
#define pinstCBookWnd_x                                            0xEDABE8
#define pinstCPetInfoWnd_x                                         0xEDABEC
#define pinstCTrainWnd_x                                           0xEDABF0
#define pinstCSkillsWnd_x                                          0xEDABF4
#define pinstCSkillsSelectWnd_x                                    0xEDABF8
#define pinstCCombatSkillSelectWnd_x                               0xEDABFC
#define pinstCFriendsWnd_x                                         0xEDAC00
#define pinstCAuraWnd_x                                            0xEDAC04
#define pinstCRespawnWnd_x                                         0xEDAC08
#define pinstCBandolierWnd_x                                       0xEDAC0C
#define pinstCPotionBeltWnd_x                                      0xEDAC10
#define pinstCAAWnd_x                                              0xEDAC14
#define pinstCGroupSearchFiltersWnd_x                              0xEDAC18
#define pinstCLoadskinWnd_x                                        0xEDAC1C
#define pinstCAlarmWnd_x                                           0xEDAC20
#define pinstCMusicPlayerWnd_x                                     0xEDAC24
#define pinstCMailWnd_x                                            0xEDAC2C
#define pinstCMailCompositionWnd_x                                 0xEDAC30
#define pinstCMailAddressBookWnd_x                                 0xEDAC34
#define pinstCRaidWnd_x                                            0xEDAC3C
#define pinstCRaidOptionsWnd_x                                     0xEDAC40
#define pinstCBreathWnd_x                                          0xEDAC44
#define pinstCMapViewWnd_x                                         0xEDAC48
#define pinstCMapToolbarWnd_x                                      0xEDAC4C
#define pinstCEditLabelWnd_x                                       0xEDAC50
#define pinstCTargetWnd_x                                          0xEDAC54
#define pinstCColorPickerWnd_x                                     0xEDAC58
#define pinstCPlayerWnd_x                                          0xEDAC5C
#define pinstCOptionsWnd_x                                         0xEDAC60
#define pinstCBuffWindowNORMAL_x                                   0xEDAC64
#define pinstCBuffWindowSHORT_x                                    0xEDAC68
#define pinstCharacterCreation_x                                   0xEDAC6C
#define pinstCCursorAttachment_x                                   0xEDAC70
#define pinstCCastingWnd_x                                         0xEDAC74
#define pinstCCastSpellWnd_x                                       0xEDAC78
#define pinstCSpellBookWnd_x                                       0xEDAC7C
#define pinstCInventoryWnd_x                                       0xEDAC80
#define pinstCBankWnd_x                                            0xEDAC84
#define pinstCQuantityWnd_x                                        0xEDAC88
#define pinstCLootWnd_x                                            0xEDAC8C
#define pinstCActionsWnd_x                                         0xEDAC90
#define pinstCCombatAbilityWnd_x                                   0xEDAC94
#define pinstCMerchantWnd_x                                        0xEDAC98
#define pinstCTradeWnd_x                                           0xEDAC9C
#define pinstCSelectorWnd_x                                        0xEDACA0
#define pinstCBazaarWnd_x                                          0xEDACA4
#define pinstCBazaarSearchWnd_x                                    0xEDACA8
#define pinstCGiveWnd_x                                            0xEDACC4
#define pinstCTrackingWnd_x                                        0xEDACCC
#define pinstCInspectWnd_x                                         0xEDACD0
#define pinstCSocialEditWnd_x                                      0xEDACD4
#define pinstCFeedbackWnd_x                                        0xEDACD8
#define pinstCBugReportWnd_x                                       0xEDACDC
#define pinstCVideoModesWnd_x                                      0xEDACE0
#define pinstCTextEntryWnd_x                                       0xEDACE8
#define pinstCFileSelectionWnd_x                                   0xEDACEC
#define pinstCCompassWnd_x                                         0xEDACF0
#define pinstCPlayerNotesWnd_x                                     0xEDACF4
#define pinstCGemsGameWnd_x                                        0xEDACF8
#define pinstCTimeLeftWnd_x                                        0xEDACFC
#define pinstCPetitionQWnd_x                                       0xEDAD10
#define pinstCSoulmarkWnd_x                                        0xEDAD14
#define pinstCStoryWnd_x                                           0xEDAD18
#define pinstCJournalTextWnd_x                                     0xEDAD1C
#define pinstCJournalCatWnd_x                                      0xEDAD20
#define pinstCBodyTintWnd_x                                        0xEDAD24
#define pinstCServerListWnd_x                                      0xEDAD28
#define pinstCAvaZoneWnd_x                                         0xEDAD34
#define pinstCBlockedBuffWnd_x                                     0xEDAD38
#define pinstCBlockedPetBuffWnd_x                                  0xEDAD3C
#define pinstCInvSlotMgr_x                                         0xEDAD7C
#define pinstCContainerMgr_x                                       0xEDAD80
#define pinstCAdventureLeaderboardWnd_x                            0x112D590
#define pinstCAdventureRequestWnd_x                                0x112D608
#define pinstCAltStorageWnd_x                                      0x112D8E8
#define pinstCAdventureStatsWnd_x                                  0x112D680
#define pinstCBarterMerchantWnd_x                                  0x112E4D0
#define pinstCBarterSearchWnd_x                                    0x112E548
#define pinstCBarterWnd_x                                          0x112E5C0
#define pinstCChatManager_x                                        0x112EC50
#define pinstCDynamicZoneWnd_x                                     0x112F100
#define pinstCEQMainWnd_x                                          0x112F298
#define pinstCFellowshipWnd_x                                      0x112F094
#define pinstCFindLocationWnd_x                                    0x112F568
#define pinstCGroupSearchWnd_x                                     0x112F838
#define pinstCGroupWnd_x                                           0x112F8B0
#define pinstCGuildBankWnd_x                                       0x112F928
#define pinstCGuildMgmtWnd_x                                       0x1131A18
#define pinstCHotButtonWnd_x                                       0x1131AE4
#define pinstCHotButtonWnd1_x                                      0x1131AE4
#define pinstCHotButtonWnd2_x                                      0x1131AE8
#define pinstCHotButtonWnd3_x                                      0x1131AEC
#define pinstCHotButtonWnd4_x                                      0x1131B10
#define pinstCItemDisplayManager_x                                 0x1131E08
#define pinstCItemExpTransferWnd_x                                 0x1131E84
#define pinstCLFGuildWnd_x                                         0x1132160
#define pinstCMIZoneSelectWnd_x                                    0x1132748
#define pinstCConfirmationDialog_x                                 0x1132E50
#define pinstCPopupWndManager_x                                    0x1132E50
#define pinstCProgressionSelectionWnd_x                            0x1132F40
#define pinstCPvPStatsWnd_x                                        0x1133030
#define pinstCSystemInfoDialogBox_x                                0x1133738
#define pinstCTaskWnd_x                                            0x1134B00
#define pinstCTaskSomething_x                                      0xDA8E20
#define pinstCTaskTemplateSelectWnd_x                              0x1134A88
#define pinstCTipWndOFDAY_x                                        0x1134D58
#define pinstCTipWndCONTEXT_x                                      0x1134D5C
#define pinstCTitleWnd_x                                           0x1134DD8
#define pinstCContextMenuManager_x                                 0x17964F4
#define pinstCVoiceMacroWnd_x                                      0x1021A10
#define pinstCHtmlWnd_x                                            0x1021B08
#define pinstIconCache_x                                           0x112F26C
#define pinstCTradeskillWnd_x                                      0x1134ED8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5279D0
#define __ConvertItemTags_x                                        0x514C50
#define __ExecuteCmd_x                                             0x4FF600
#define __EQGetTime_x                                              0x85A840
#define __get_melee_range_x                                        0x5062E0
#define __GetGaugeValueFromEQ_x                                    0x79A390
#define __GetLabelFromEQ_x                                         0x79B5D0
#define __ToggleMount_x                                            0x6C42B0
#define __GetXTargetType_x                                         0x918E70
#define __LoadFrontEnd_x                                           0x6292F0
#define __NewUIINI_x                                               0x799C90
#define __ProcessGameEvents_x                                      0x56B460
#define __ProcessMouseEvent_x                                      0x56AC00
#define CrashDetected_x                                            0x62ADC0
#define wwsCrashReportCheckForUploader_x                           0x7EF4A0
#define DrawNetStatus_x                                            0x5A1DA0
#define Util__FastTime_x                                           0x85A390
#define Expansion_HoT_x                                            0xF9C3FC
#define __HelpPath_x                                               0x101FB60
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4BF8B0
#define AltAdvManager__IsAbilityReady_x                            0x4BF920
#define AltAdvManager__GetAltAbility_x                             0x4BFCE0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463970
#define CharacterZoneClient__MakeMeVisible_x                       0x468A30

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x658B40

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x666B50

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x581580

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x681DD0
#define CChatManager__InitContextMenu_x                            0x6828F0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8BE150
#define CContextMenu__AddMenuItem_x                                0x8BE370
#define CContextMenu__dCContextMenu_x                              0x8BE360
#define CContextMenu__RemoveMenuItem_x                             0x8BE660
#define CContextMenu__RemoveAllMenuItems_x                         0x8BE680
#define CContextMenuManager__AddMenu_x                             0x8BEA30
#define CContextMenuManager__RemoveMenu_x                          0x8BED50
#define CContextMenuManager__PopupMenu_x                           0x8BF1A0
#define CContextMenuManager__Flush_x                               0x8BEAA0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x7FEC50
#define CChatService__GetFriendName_x                              0x841100

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x687960
#define CChatWindow__Clear_x                                       0x687510
#define CChatWindow__WndNotification_x                             0x687E90

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BD500
#define CComboWnd__Draw_x                                          0x8BD710
#define CComboWnd__GetCurChoice_x                                  0x8BD2D0
#define CComboWnd__GetListRect_x                                   0x8BD9B0
#define CComboWnd__GetTextRect_x                                   0x8BD570
#define CComboWnd__InsertChoice_x                                  0x8BDA20
#define CComboWnd__SetColors_x                                     0x8BD260
#define CComboWnd__SetChoice_x                                     0x8BD290

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x691120
#define CContainerWnd__vftable_x                                   0xA84880

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4AE020
#define CDisplay__GetClickedActor_x                                0x4A6BA0
#define CDisplay__GetUserDefinedColor_x                            0x4A5460
#define CDisplay__GetWorldFilePath_x                               0x4A48B0
#define CDisplay__is3dON_x                                         0x4A3C80
#define CDisplay__ReloadUI_x                                       0x4B9480
#define CDisplay__WriteTextHD2_x                                   0x4AA3C0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E0FD0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8CF360
#define CEditWnd__GetCharIndexPt_x                                 0x8D0400
#define CEditWnd__GetDisplayString_x                               0x8CF510
#define CEditWnd__GetHorzOffset_x                                  0x8CF850
#define CEditWnd__GetLineForPrintableChar_x                        0x8CFEC0
#define CEditWnd__GetSelStartPt_x                                  0x8D06C0
#define CEditWnd__GetSTMLSafeText_x                                0x8CF9F0
#define CEditWnd__PointFromPrintableChar_x                         0x8CFFB0
#define CEditWnd__SelectableCharFromPoint_x                        0x8D0130
#define CEditWnd__SetEditable_x                                    0x8CF9C0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x548D80
#define CEverQuest__DoTellWindow_x                                 0x54E770
#define CEverQuest__DropHeldItemOnGround_x                         0x5572A0
#define CEverQuest__dsp_chat_x                                     0x54FF10
#define CEverQuest__Emote_x                                        0x550170
#define CEverQuest__EnterZone_x                                    0x563A80
#define CEverQuest__GetBodyTypeDesc_x                              0x5455E0
#define CEverQuest__GetClassDesc_x                                 0x54B2F0
#define CEverQuest__GetClassThreeLetterCode_x                      0x54B8F0
#define CEverQuest__GetDeityDesc_x                                 0x545EC0
#define CEverQuest__GetLangDesc_x                                  0x545970
#define CEverQuest__GetRaceDesc_x                                  0x54BAB0
#define CEverQuest__InterpretCmd_x                                 0x550A50
#define CEverQuest__LeftClickedOnPlayer_x                          0x567B60
#define CEverQuest__LMouseUp_x                                     0x569C50
#define CEverQuest__RightClickedOnPlayer_x                         0x568660
#define CEverQuest__RMouseUp_x                                     0x5696B0
#define CEverQuest__SetGameState_x                                 0x549430
#define CEverQuest__UPCNotificationFlush_x                         0x551BF0
#define CEverQuest__IssuePetCommand_x                              0x551750

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A1CC0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A1D20
#define CGaugeWnd__Draw_x                                          0x6A2150

// CGuild
#define CGuild__FindMemberByName_x                                 0x4352D0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6BED20

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CCAB0
#define CInvSlotMgr__MoveItem_x                                    0x6CD9F0
#define CInvSlotMgr__SelectSlot_x                                  0x6CCB60

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CBF50
#define CInvSlot__SliderComplete_x                                 0x6C9920
#define CInvSlot__GetItemBase_x                                    0x6C8DC0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6CEB80

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x796E90
#define CItemDisplayWnd__UpdateStrings_x                           0x6CFEE0

// CLabel 
#define CLabel__Draw_x                                             0x6EAAE0

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8A6780
#define CListWnd__dCListWnd_x                                      0x8A7810
#define CListWnd__AddColumn_x                                      0x8A77B0
#define CListWnd__AddColumn1_x                                     0x8A6F90
#define CListWnd__AddLine_x                                        0x8A6A40
#define CListWnd__AddString_x                                      0x8A6C50
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A3AB0
#define CListWnd__CalculateVSBRange_x                              0x8A5C30
#define CListWnd__ClearAllSel_x                                    0x8A2D70
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8A6610
#define CListWnd__Compare_x                                        0x8A45B0
#define CListWnd__Draw_x                                           0x8A5840
#define CListWnd__DrawColumnSeparators_x                           0x8A56D0
#define CListWnd__DrawHeader_x                                     0x8A3080
#define CListWnd__DrawItem_x                                       0x8A4C00
#define CListWnd__DrawLine_x                                       0x8A5370
#define CListWnd__DrawSeparator_x                                  0x8A5770
#define CListWnd__EnsureVisible_x                                  0x8A3C10
#define CListWnd__ExtendSel_x                                      0x8A4B10
#define CListWnd__GetColumnMinWidth_x                              0x8A2790
#define CListWnd__GetColumnWidth_x                                 0x8A26B0
#define CListWnd__GetCurSel_x                                      0x8A1E90
#define CListWnd__GetItemAtPoint_x                                 0x8A3EB0
#define CListWnd__GetItemAtPoint1_x                                0x8A3F20
#define CListWnd__GetItemData_x                                    0x8A21C0
#define CListWnd__GetItemHeight_x                                  0x8A3710
#define CListWnd__GetItemIcon_x                                    0x8A23A0
#define CListWnd__GetItemRect_x                                    0x8A3CF0
#define CListWnd__GetItemText_x                                    0x8A2250
#define CListWnd__GetSelList_x                                     0x8A6E80
#define CListWnd__GetSeparatorRect_x                               0x8A44E0
#define CListWnd__RemoveLine_x                                     0x8A6E30
#define CListWnd__SetColors_x                                      0x8A1FE0
#define CListWnd__SetColumnJustification_x                         0x8A2A60
#define CListWnd__SetColumnWidth_x                                 0x8A2740
#define CListWnd__SetCurSel_x                                      0x8A1ED0
#define CListWnd__SetItemColor_x                                   0x8A62F0
#define CListWnd__SetItemData_x                                    0x8A2E20
#define CListWnd__SetItemText_x                                    0x8A6130
#define CListWnd__ShiftColumnSeparator_x                           0x8A5FC0
#define CListWnd__Sort_x                                           0x8A7910
#define CListWnd__ToggleSel_x                                      0x8A2CF0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x703EC0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x725110
#define CMerchantWnd__RequestBuyItem_x                             0x72BF10
#define CMerchantWnd__RequestSellItem_x                            0x72C960
#define CMerchantWnd__SelectRecoverySlot_x                         0x7253C0
#define CMerchantWnd__SelectBuySellSlot_x                          0x724620
#define CMerchantWnd__ActualSelect_x                               0x728E50

// CObfuscator
#define CObfuscator__doit_x                                        0x8211C0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8C60A0
#define CSidlManager__CreateLabel_x                                0x78CED0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x64FD80
#define CSidlScreenWnd__CalculateVSBRange_x                        0x64FC60
#define CSidlScreenWnd__ConvertToRes_x                             0x8E0EB0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8B08C0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8B1DA0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8B1E50
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8B1310
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8B0290
#define CSidlScreenWnd__EnableIniStorage_x                         0x8AF9E0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8B0480
#define CSidlScreenWnd__Init1_x                                    0x8B1A70
#define CSidlScreenWnd__LoadIniInfo_x                              0x8B0970
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8AFBA0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8B1560
#define CSidlScreenWnd__StoreIniInfo_x                             0x8AF4B0
#define CSidlScreenWnd__StoreIniVis_x                              0x8AF970
#define CSidlScreenWnd__WndNotification_x                          0x8B17F0
#define CSidlScreenWnd__GetChildItem_x                             0x8AFAB0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B5E90

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5EB350
#define CSkillMgr__GetSkillCap_x                                   0x5EB4F0
#define CSkillMgr__GetNameToken_x                                  0x5EAFC0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E0170
#define CSliderWnd__SetValue_x                                     0x8E0340
#define CSliderWnd__SetNumTicks_x                                  0x8E0AC0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x794B30

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8DAB70
#define CStmlWnd__CalculateHSBRange_x                              0x8D3140
#define CStmlWnd__CalculateVSBRange_x                              0x8D30B0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D32C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D3BA0
#define CStmlWnd__ForceParseNow_x                                  0x8DB4C0
#define CStmlWnd__GetNextTagPiece_x                                0x8D3AA0
#define CStmlWnd__GetSTMLText_x                                    0x686DB0
#define CStmlWnd__GetVisibleText_x                                 0x8D45F0
#define CStmlWnd__InitializeWindowVariables_x                      0x8D6960
#define CStmlWnd__MakeStmlColorTag_x                               0x8D23B0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D2410
#define CStmlWnd__SetSTMLText_x                                    0x8D81C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8DA810
#define CStmlWnd__UpdateHistoryString_x                            0x8D5520

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E2780
#define CTabWnd__DrawCurrentPage_x                                 0x8E1FF0
#define CTabWnd__DrawTab_x                                         0x8E1DB0
#define CTabWnd__GetCurrentPage_x                                  0x8E23C0
#define CTabWnd__GetPageInnerRect_x                                0x8E1AA0
#define CTabWnd__GetTabInnerRect_x                                 0x8E1CA0
#define CTabWnd__GetTabRect_x                                      0x8E1B70
#define CTabWnd__InsertPage_x                                      0x8E2A70
#define CTabWnd__SetPage_x                                         0x8E23F0
#define CTabWnd__SetPageRect_x                                     0x8E26C0
#define CTabWnd__UpdatePage_x                                      0x8E2A10

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4310C0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BCED0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8E7970

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A0140

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402280
#define CXStr__CXStr1_x                                            0x43FB00
#define CXStr__CXStr3_x                                            0x857420
#define CXStr__dCXStr_x                                            0x58EE20
#define CXStr__operator_equal_x                                    0x857590
#define CXStr__operator_equal1_x                                   0x8575E0
#define CXStr__operator_plus_equal1_x                              0x8586C0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B5110
#define CXWnd__Center_x                                            0x8BB1B0
#define CXWnd__ClrFocus_x                                          0x8B4CF0
#define CXWnd__DoAllDrawing_x                                      0x8BAE00
#define CXWnd__DrawChildren_x                                      0x8BAFA0

#define CXWnd__DrawColoredRect_x                                   0x8B54C0
#define CXWnd__DrawTooltip_x                                       0x8B5760
#define CXWnd__DrawTooltipAtPoint_x                                0x8B9D80
#define CXWnd__GetBorderFrame_x                                    0x8B5B90
#define CXWnd__GetChildWndAt_x                                     0x8BBB80
#define CXWnd__GetClientClipRect_x                                 0x8B5970
#define CXWnd__GetScreenClipRect_x                                 0x8BA480
#define CXWnd__GetScreenRect_x                                     0x8B5D40
#define CXWnd__GetTooltipRect_x                                    0x8B55F0
#define CXWnd__GetWindowTextA_x                                    0x4225C0
#define CXWnd__IsActive_x                                          0x8AA5D0
#define CXWnd__IsDescendantOf_x                                    0x8B5AE0
#define CXWnd__IsReallyVisible_x                                   0x8B8DE0
#define CXWnd__IsType_x                                            0x8E4120
#define CXWnd__Move_x                                              0x8B8550
#define CXWnd__Move1_x                                             0x8BAAC0
#define CXWnd__ProcessTransition_x                                 0x8B50C0
#define CXWnd__Refade_x                                            0x8B4E90
#define CXWnd__Resize_x                                            0x8B5DF0
#define CXWnd__Right_x                                             0x8BA280
#define CXWnd__SetFocus_x                                          0x8B76C0
#define CXWnd__SetFont_x                                           0x8B4D40
#define CXWnd__SetKeyTooltip_x                                     0x8B6060
#define CXWnd__SetMouseOver_x                                      0x8BA7B0
#define CXWnd__StartFade_x                                         0x8B5160
#define CXWnd__GetChildItem_x                                      0x8BA6F0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8ABEE0
#define CXWndManager__DrawWindows_x                                0x8ABB20
#define CXWndManager__GetKeyboardFlags_x                           0x8AA140
#define CXWndManager__HandleKeyboardMsg_x                          0x8AAA70
#define CXWndManager__RemoveWnd_x                                  0x8AA760

// CDBStr
#define CDBStr__GetString_x                                        0x4A2100

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44D310
#define EQ_Character__Cur_HP_x                                     0x463040
#define EQ_Character__GetAACastingTimeModifier_x                   0x4463F0
#define EQ_Character__GetCharInfo2_x                               0x82BAE0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43E710
#define EQ_Character__GetFocusRangeModifier_x                      0x43E8F0
#define EQ_Character__Max_Endurance_x                              0x5B3CF0
#define EQ_Character__Max_HP_x                                     0x459340
#define EQ_Character__Max_Mana_x                                   0x5B3B20
#define EQ_Character__doCombatAbility_x                            0x5B1120
#define EQ_Character__UseSkill_x                                   0x46DB60
#define EQ_Character__GetConLevel_x                                0x5A63E0
#define EQ_Character__IsExpansionFlag_x                            0x421B00
#define EQ_Character__TotalEffect_x                                0x44B420

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x586D20
#define EQ_Item__CreateItemTagString_x                             0x80AF90
#define EQ_Item__IsStackable_x                                     0x7FF120
#define EQ_Item__GetImageNum_x                                     0x801D90

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C1A00
#define EQ_LoadingS__Array_x                                       0xBA4D10

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B5480
#define EQ_PC__GetAltAbilityIndex_x                                0x813F00
#define EQ_PC__GetCombatAbility_x                                  0x813F90
#define EQ_PC__GetCombatAbilityTimer_x                             0x814040
#define EQ_PC__GetItemTimerValue_x                                 0x5AEEF0
#define EQ_PC__HasLoreItem_x                                       0x5A9730
#define EQ_PC__AlertInventoryChanged_x                             0x5A63B0
#define EQ_PC__GetPcZoneClient_x                                   0x5CF890
#define EQ_PC__RemoveMyAffect_x                                    0x5AE400

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5042F0
#define EQItemList__add_item_x                                     0x504230
#define EQItemList__delete_item_x                                  0x5046F0
#define EQItemList__FreeItemList_x                                 0x5045F0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A1390

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BA930
#define EQPlayer__dEQPlayer_x                                      0x5C3750
#define EQPlayer__DoAttack_x                                       0x5D56F0
#define EQPlayer__EQPlayer_x                                       0x5C5B70
#define EQPlayer__SetNameSpriteState_x                             0x5C0420
#define EQPlayer__SetNameSpriteTint_x                              0x5BBD00
#define EQPlayer__IsBodyType_j_x                                   0x915020
#define EQPlayer__IsTargetable_x                                   0x9158E0
#define EQPlayer__CanSee_x                                         0x915E00

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5C9E80
#define EQPlayerManager__GetSpawnByName_x                          0x5CA2E0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x58CE30
#define KeypressHandler__AttachKeyToEqCommand_x                    0x58CE70
#define KeypressHandler__ClearCommandStateArray_x                  0x58CA10
#define KeypressHandler__HandleKeyDown_x                           0x58B370
#define KeypressHandler__HandleKeyUp_x                             0x58B690
#define KeypressHandler__SaveKeymapping_x                          0x58CAE0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FC2A0
#define MapViewMap__SaveEx_x                                       0x6FFB80

#define PlayerPointManager__GetAltCurrency_x                       0x8269D0

// StringTable 
#define StringTable__getString_x                                   0x821460

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B37A0

//Doors
#define EQSwitch__UseSwitch_x                                      0x542990

//IconCache
#define IconCache__GetIcon_x                                       0x697590

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x68E430
#define CContainerMgr__CloseContainer_x                            0x68EC50

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x75D3A0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x580050

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D4400
#define EQ_Spell__SpellAffects_x                                   0x4D44A0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D44D0
#define CharacterZoneClient__CalcAffectChange_x                    0x447710
#define CLootWnd__LootAll_x                                        0x6F1CA0
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A2900
#define CTargetWnd__WndNotification_x                              0x7A23F0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7A7AC0
