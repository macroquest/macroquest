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
#define __ExpectedVersionDate                                     "Mar 23 2015"
#define __ExpectedVersionTime                                     "11:31:09"
#define __ActualVersionDate_x                                      0xA7B188
#define __ActualVersionTime_x                                      0xA7B194

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x591D00
#define __MemChecker1_x                                            0x85A870
#define __MemChecker2_x                                            0x629970
#define __MemChecker3_x                                            0x6298C0
#define __MemChecker4_x                                            0x7DE610
#define __EncryptPad0_x                                            0xBF6978
#define __EncryptPad1_x                                            0xD7AC90
#define __EncryptPad2_x                                            0xC3F8F8
#define __EncryptPad3_x                                            0xC3F4F8
#define __EncryptPad4_x                                            0xD573B8
#define __AC1_x                                                    0x79BBA5
#define __AC2_x                                                    0x547DE7
#define __AC3_x                                                    0x55C5E0
#define __AC4_x                                                    0x562A20
#define __AC5_x                                                    0x56E7FE
#define __AC6_x                                                    0x5722C2
#define __AC7_x                                                    0x568ECC
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
#define __do_loot_x                                                0x50F650
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
#define pinstCamActor_x                                            0xEDAD8C
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
#define pinstViewActor_x                                           0xEDAD88
#define pinstWorldData_x                                           0xF8DFB8


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD9ECF8
#define pinstCAudioTriggersWindow_x                                0xD9EB88
#define pinstCCharacterSelect_x                                    0xEDAC2C
#define pinstCFacePick_x                                           0xEDA9DC
#define pinstCNoteWnd_x                                            0xEDABE4
#define pinstCBookWnd_x                                            0xEDABEC
#define pinstCPetInfoWnd_x                                         0xEDABF0
#define pinstCTrainWnd_x                                           0xEDABF4
#define pinstCSkillsWnd_x                                          0xEDABF8
#define pinstCSkillsSelectWnd_x                                    0xEDABFC
#define pinstCCombatSkillSelectWnd_x                               0xEDAC00
#define pinstCFriendsWnd_x                                         0xEDAC04
#define pinstCAuraWnd_x                                            0xEDAC08
#define pinstCRespawnWnd_x                                         0xEDAC0C
#define pinstCBandolierWnd_x                                       0xEDAC10
#define pinstCPotionBeltWnd_x                                      0xEDAC14
#define pinstCAAWnd_x                                              0xEDAC18
#define pinstCGroupSearchFiltersWnd_x                              0xEDAC1C
#define pinstCLoadskinWnd_x                                        0xEDAC20
#define pinstCAlarmWnd_x                                           0xEDAC24
#define pinstCMusicPlayerWnd_x                                     0xEDAC28
#define pinstCMailWnd_x                                            0xEDAC30
#define pinstCMailCompositionWnd_x                                 0xEDAC34
#define pinstCMailAddressBookWnd_x                                 0xEDAC38
#define pinstCRaidWnd_x                                            0xEDAC40
#define pinstCRaidOptionsWnd_x                                     0xEDAC44
#define pinstCBreathWnd_x                                          0xEDAC48
#define pinstCMapViewWnd_x                                         0xEDAC4C
#define pinstCMapToolbarWnd_x                                      0xEDAC50
#define pinstCEditLabelWnd_x                                       0xEDAC54
#define pinstCTargetWnd_x                                          0xEDAC58
#define pinstCColorPickerWnd_x                                     0xEDAC5C
#define pinstCPlayerWnd_x                                          0xEDAC60
#define pinstCOptionsWnd_x                                         0xEDAC64
#define pinstCBuffWindowNORMAL_x                                   0xEDAC68
#define pinstCBuffWindowSHORT_x                                    0xEDAC6C
#define pinstCharacterCreation_x                                   0xEDAC70
#define pinstCCursorAttachment_x                                   0xEDAC74
#define pinstCCastingWnd_x                                         0xEDAC78
#define pinstCCastSpellWnd_x                                       0xEDAC7C
#define pinstCSpellBookWnd_x                                       0xEDAC80
#define pinstCInventoryWnd_x                                       0xEDAC84
#define pinstCBankWnd_x                                            0xEDAC88
#define pinstCQuantityWnd_x                                        0xEDAC8C
#define pinstCLootWnd_x                                            0xEDAC90
#define pinstCActionsWnd_x                                         0xEDAC94
#define pinstCCombatAbilityWnd_x                                   0xEDAC98
#define pinstCMerchantWnd_x                                        0xEDAC9C
#define pinstCTradeWnd_x                                           0xEDACA0
#define pinstCSelectorWnd_x                                        0xEDACA4
#define pinstCBazaarWnd_x                                          0xEDACA8
#define pinstCBazaarSearchWnd_x                                    0xEDACAC
#define pinstCGiveWnd_x                                            0xEDACC8
#define pinstCTrackingWnd_x                                        0xEDACD0
#define pinstCInspectWnd_x                                         0xEDACD4
#define pinstCSocialEditWnd_x                                      0xEDACD8
#define pinstCFeedbackWnd_x                                        0xEDACDC
#define pinstCBugReportWnd_x                                       0xEDACE0
#define pinstCVideoModesWnd_x                                      0xEDACE4
#define pinstCTextEntryWnd_x                                       0xEDACEC
#define pinstCFileSelectionWnd_x                                   0xEDACF0
#define pinstCCompassWnd_x                                         0xEDACF4
#define pinstCPlayerNotesWnd_x                                     0xEDACF8
#define pinstCGemsGameWnd_x                                        0xEDACFC
#define pinstCTimeLeftWnd_x                                        0xEDAD00
#define pinstCPetitionQWnd_x                                       0xEDAD14
#define pinstCSoulmarkWnd_x                                        0xEDAD18
#define pinstCStoryWnd_x                                           0xEDAD1C
#define pinstCJournalTextWnd_x                                     0xEDAD20
#define pinstCJournalCatWnd_x                                      0xEDAD24
#define pinstCBodyTintWnd_x                                        0xEDAD28
#define pinstCServerListWnd_x                                      0xEDAD2C
#define pinstCAvaZoneWnd_x                                         0xEDAD38
#define pinstCBlockedBuffWnd_x                                     0xEDAD3C
#define pinstCBlockedPetBuffWnd_x                                  0xEDAD40
#define pinstCInvSlotMgr_x                                         0xEDAD80
#define pinstCContainerMgr_x                                       0xEDAD84
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
#define __CastRay_x                                                0x527060
#define __ConvertItemTags_x                                        0x5142E0
#define __ExecuteCmd_x                                             0x4FEC70
#define __EQGetTime_x                                              0x85AB90
#define __get_melee_range_x                                        0x505970
#define __GetGaugeValueFromEQ_x                                    0x79A8F0
#define __GetLabelFromEQ_x                                         0x79BB30
#define __ToggleMount_x                                            0x6C40A0
#define __GetXTargetType_x                                         0x919100
#define __LoadFrontEnd_x                                           0x629020
#define __NewUIINI_x                                               0x79A1F0
#define __ProcessGameEvents_x                                      0x56AC30
#define __ProcessMouseEvent_x                                      0x56A3D0
#define CrashDetected_x                                            0x62AAF0
#define wwsCrashReportCheckForUploader_x                           0x7EFAC0
#define DrawNetStatus_x                                            0x5A1860
#define Util__FastTime_x                                           0x85A6E0
#define Expansion_HoT_x                                            0xF9C3FC
#define __HelpPath_x                                               0x101FB60

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4BF910
#define AltAdvManager__IsAbilityReady_x                            0x4BF980
#define AltAdvManager__GetAltAbility_x                             0x4BFD40

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463A80
#define CharacterZoneClient__MakeMeVisible_x                       0x468B40
// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6587D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x666630

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x580DA0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x681AA0
#define CChatManager__InitContextMenu_x                            0x6825C0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8BE6A0
#define CContextMenu__dCContextMenu_x                              0x8BE8B0
#define CContextMenu__AddMenuItem_x                                0x8BE8C0
#define CContextMenu__RemoveMenuItem_x                             0x8BEBA0
#define CContextMenu__RemoveAllMenuItems_x                         0x8BEBC0
#define CContextMenuManager__AddMenu_x                             0x8BEF70
#define CContextMenuManager__RemoveMenu_x                          0x8BF2B0
#define CContextMenuManager__PopupMenu_x                           0x8BF700
#define CContextMenuManager__Flush_x                               0x8BEFE0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8412B0
#define CChatService__GetFriendName_x                              0x8412C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x687630
#define CChatWindow__Clear_x                                       0x6871E0
#define CChatWindow__WndNotification_x                             0x687B70

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BDA60
#define CComboWnd__Draw_x                                          0x8BDC70
#define CComboWnd__GetCurChoice_x                                  0x8BD830
#define CComboWnd__GetListRect_x                                   0x8BDF10
#define CComboWnd__GetTextRect_x                                   0x8BDAD0
#define CComboWnd__InsertChoice_x                                  0x8BDF80
#define CComboWnd__SetColors_x                                     0x8BD7C0
#define CComboWnd__SetChoice_x                                     0x8BD7F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x690E70
#define CContainerWnd__vftable_x                                   0xA848E0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4AE190
#define CDisplay__GetClickedActor_x                                0x4A6D10
#define CDisplay__GetUserDefinedColor_x                            0x4A55D0
#define CDisplay__GetWorldFilePath_x                               0x4A4A20
#define CDisplay__is3dON_x                                         0x4A3DF0
#define CDisplay__ReloadUI_x                                       0x4B95F0
#define CDisplay__WriteTextHD2_x                                   0x4AA530

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E14B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8CF8A0
#define CEditWnd__GetCharIndexPt_x                                 0x8D0910
#define CEditWnd__GetDisplayString_x                               0x8CFA50
#define CEditWnd__GetHorzOffset_x                                  0x8CFD90
#define CEditWnd__GetLineForPrintableChar_x                        0x8D03F0
#define CEditWnd__GetSelStartPt_x                                  0x8D0BC0
#define CEditWnd__GetSTMLSafeText_x                                0x8CFF20
#define CEditWnd__PointFromPrintableChar_x                         0x8D04E0
#define CEditWnd__SelectableCharFromPoint_x                        0x8D0650
#define CEditWnd__SetEditable_x                                    0x8CFEF0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x548530
#define CEverQuest__DoTellWindow_x                                 0x54DF30
#define CEverQuest__DropHeldItemOnGround_x                         0x556A60
#define CEverQuest__dsp_chat_x                                     0x54F6D0
#define CEverQuest__Emote_x                                        0x54F930
#define CEverQuest__EnterZone_x                                    0x563240
#define CEverQuest__GetBodyTypeDesc_x                              0x544D90
#define CEverQuest__GetClassDesc_x                                 0x54AAA0
#define CEverQuest__GetClassThreeLetterCode_x                      0x54B0A0
#define CEverQuest__GetDeityDesc_x                                 0x545670
#define CEverQuest__GetLangDesc_x                                  0x545120
#define CEverQuest__GetRaceDesc_x                                  0x54B260
#define CEverQuest__InterpretCmd_x                                 0x550210
#define CEverQuest__LeftClickedOnPlayer_x                          0x567330
#define CEverQuest__LMouseUp_x                                     0x569420
#define CEverQuest__RightClickedOnPlayer_x                         0x567E30
#define CEverQuest__RMouseUp_x                                     0x568E80
#define CEverQuest__SetGameState_x                                 0x548BE0
#define CEverQuest__UPCNotificationFlush_x                         0x5513B0
#define CEverQuest__IssuePetCommand_x                              0x550F10

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A1A40
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A1AA0
#define CGaugeWnd__Draw_x                                          0x6A1ED0

// CGuild
#define CGuild__FindMemberByName_x                                 0x435310

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6BEB00

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CC8F0
#define CInvSlotMgr__MoveItem_x                                    0x6CD830
#define CInvSlotMgr__SelectSlot_x                                  0x6CC9A0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CBD90
#define CInvSlot__SliderComplete_x                                 0x6C9750
#define CInvSlot__GetItemBase_x                                    0x6C8BC0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6CE9F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7973D0
#define CItemDisplayWnd__UpdateStrings_x                           0x6CFD30

// CLabel 
#define CLabel__Draw_x                                             0x6EAA90

// CListWnd
#define CListWnd__CListWnd_x                                       0x8A69A0
#define CListWnd__dCListWnd_x                                      0x8A7A20
#define CListWnd__AddColumn_x                                      0x8A79C0
#define CListWnd__AddColumn1_x                                     0x8A71A0
#define CListWnd__AddLine_x                                        0x8A6C50
#define CListWnd__AddString_x                                      0x8A6E60
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A3CE0
#define CListWnd__CalculateVSBRange_x                              0x8A5E50
#define CListWnd__ClearAllSel_x                                    0x8A2FB0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8A6830
#define CListWnd__Compare_x                                        0x8A47E0
#define CListWnd__Draw_x                                           0x8A5A60
#define CListWnd__DrawColumnSeparators_x                           0x8A58F0
#define CListWnd__DrawHeader_x                                     0x8A32C0
#define CListWnd__DrawItem_x                                       0x8A4E30
#define CListWnd__DrawLine_x                                       0x8A5590
#define CListWnd__DrawSeparator_x                                  0x8A5990
#define CListWnd__EnsureVisible_x                                  0x8A3E40
#define CListWnd__ExtendSel_x                                      0x8A4D40
#define CListWnd__GetColumnMinWidth_x                              0x8A29D0
#define CListWnd__GetColumnWidth_x                                 0x8A28F0
#define CListWnd__GetCurSel_x                                      0x8A20B0
#define CListWnd__GetItemAtPoint_x                                 0x8A40D0
#define CListWnd__GetItemAtPoint1_x                                0x8A4140
#define CListWnd__GetItemData_x                                    0x8A2400
#define CListWnd__GetItemHeight_x                                  0x8A3950
#define CListWnd__GetItemIcon_x                                    0x8A25E0
#define CListWnd__GetItemRect_x                                    0x8A3F10
#define CListWnd__GetItemText_x                                    0x8A2490
#define CListWnd__GetSelList_x                                     0x8A7090
#define CListWnd__GetSeparatorRect_x                               0x8A4700
#define CListWnd__RemoveLine_x                                     0x8A7040
#define CListWnd__SetColors_x                                      0x8A2200
#define CListWnd__SetColumnJustification_x                         0x8A2CA0
#define CListWnd__SetColumnWidth_x                                 0x8A2980
#define CListWnd__SetCurSel_x                                      0x8A20F0
#define CListWnd__SetItemColor_x                                   0x8A6510
#define CListWnd__SetItemData_x                                    0x8A3060
#define CListWnd__SetItemText_x                                    0x8A6350
#define CListWnd__ShiftColumnSeparator_x                           0x8A61E0
#define CListWnd__Sort_x                                           0x8A7B20
#define CListWnd__ToggleSel_x                                      0x8A2F30

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7040E0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7252B0
#define CMerchantWnd__RequestBuyItem_x                             0x72C120
#define CMerchantWnd__RequestSellItem_x                            0x72CB90
#define CMerchantWnd__SelectRecoverySlot_x                         0x725560
#define CMerchantWnd__SelectBuySellSlot_x                          0x7247C0
#define CMerchantWnd__ActualSelect_x                               0x729040

// CObfuscator
#define CObfuscator__doit_x                                        0x8213D0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8C6630
#define CSidlManager__CreateLabel_x                                0x78D3A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x64FAE0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x64F8E0
#define CSidlScreenWnd__ConvertToRes_x                             0x8E1390
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8B0C70
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8B2180
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8B2230
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8B16F0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8B0640
#define CSidlScreenWnd__EnableIniStorage_x                         0x8AFD80
#define CSidlScreenWnd__GetSidlPiece_x                             0x8B0830
#define CSidlScreenWnd__Init1_x                                    0x8B1E60
#define CSidlScreenWnd__LoadIniInfo_x                              0x8B0D20
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8AFF40
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8B1940
#define CSidlScreenWnd__StoreIniInfo_x                             0x8AF840
#define CSidlScreenWnd__StoreIniVis_x                              0x8AFD10
#define CSidlScreenWnd__WndNotification_x                          0x8B1BE0
#define CSidlScreenWnd__GetChildItem_x                             0x8AFE50
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B62F0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5EB0E0
#define CSkillMgr__GetSkillCap_x                                   0x5EB280
#define CSkillMgr__GetNameToken_x                                  0x5EAD50

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E0660
#define CSliderWnd__SetValue_x                                     0x8E0830
#define CSliderWnd__SetNumTicks_x                                  0x8E0FB0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x795060

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8DB040
#define CStmlWnd__CalculateHSBRange_x                              0x8D3580
#define CStmlWnd__CalculateVSBRange_x                              0x8D3610
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D3790
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D4070
#define CStmlWnd__ForceParseNow_x                                  0x8DB990
#define CStmlWnd__GetNextTagPiece_x                                0x8D3F70
#define CStmlWnd__GetSTMLText_x                                    0x686A80
#define CStmlWnd__GetVisibleText_x                                 0x8D4AC0
#define CStmlWnd__InitializeWindowVariables_x                      0x8D6E50
#define CStmlWnd__MakeStmlColorTag_x                               0x8D2880
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D28E0
#define CStmlWnd__SetSTMLText_x                                    0x8D86B0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8DACE0
#define CStmlWnd__UpdateHistoryString_x                            0x8D5A00

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E2B80
#define CTabWnd__DrawCurrentPage_x                                 0x8E23F0
#define CTabWnd__DrawTab_x                                         0x8E21C0
#define CTabWnd__GetCurrentPage_x                                  0x8E27C0
#define CTabWnd__GetPageInnerRect_x                                0x8E1EB0
#define CTabWnd__GetTabInnerRect_x                                 0x8E20B0
#define CTabWnd__GetTabRect_x                                      0x8E1F80
#define CTabWnd__InsertPage_x                                      0x8E2E70
#define CTabWnd__SetPage_x                                         0x8E27F0
#define CTabWnd__SetPageRect_x                                     0x8E2AC0
#define CTabWnd__UpdatePage_x                                      0x8E2E10

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431100

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BD430

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8E7D00

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A0210

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x58E3C0
#define CXStr__CXStr1_x                                            0x4D84B0
#define CXStr__CXStr3_x                                            0x857770
#define CXStr__dCXStr_x                                            0x8E6AA0
#define CXStr__operator_equal_x                                    0x8578E0
#define CXStr__operator_equal1_x                                   0x857930
#define CXStr__operator_plus_equal1_x                              0x858A10

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B54E0
#define CXWnd__Center_x                                            0x8BB750
#define CXWnd__ClrFocus_x                                          0x8B50D0
#define CXWnd__DoAllDrawing_x                                      0x8BB380
#define CXWnd__DrawChildren_x                                      0x8BB530
#define CXWnd__DrawColoredRect_x                                   0x8B58A0
#define CXWnd__DrawTooltip_x                                       0x8B5B50
#define CXWnd__DrawTooltipAtPoint_x                                0x8BA2D0
#define CXWnd__GetBorderFrame_x                                    0x8B5FC0
#define CXWnd__GetChildWndAt_x                                     0x8BC110
#define CXWnd__GetClientClipRect_x                                 0x8B5D70
#define CXWnd__GetScreenClipRect_x                                 0x8BA9C0
#define CXWnd__GetScreenRect_x                                     0x8B6190
#define CXWnd__GetTooltipRect_x                                    0x8B59E0
#define CXWnd__GetWindowTextA_x                                    0x422780
#define CXWnd__IsActive_x                                          0x8AA870
#define CXWnd__IsDescendantOf_x                                    0x8B5F00
#define CXWnd__IsReallyVisible_x                                   0x8B92E0
#define CXWnd__IsType_x                                            0x8E4540
#define CXWnd__Move_x                                              0x8B89C0
#define CXWnd__Move1_x                                             0x8BB020
#define CXWnd__ProcessTransition_x                                 0x8B5490
#define CXWnd__Refade_x                                            0x8B5270
#define CXWnd__Resize_x                                            0x8B6260
#define CXWnd__Right_x                                             0x8BA7C0
#define CXWnd__SetFocus_x                                          0x8B7B10
#define CXWnd__SetFont_x                                           0x8B5120
#define CXWnd__SetKeyTooltip_x                                     0x8B64C0
#define CXWnd__SetMouseOver_x                                      0x8BAD10
#define CXWnd__StartFade_x                                         0x8B5530
#define CXWnd__GetChildItem_x                                      0x8BAC50

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8AC190
#define CXWndManager__DrawWindows_x                                0x8ABDD0
#define CXWndManager__GetKeyboardFlags_x                           0x8AA3A0
#define CXWndManager__HandleKeyboardMsg_x                          0x8AAD10
#define CXWndManager__RemoveWnd_x                                  0x8AAA00

// CDBStr
#define CDBStr__GetString_x                                        0x4A21F0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44D3C0
#define EQ_Character__Cur_HP_x                                     0x463150
#define EQ_Character__GetAACastingTimeModifier_x                   0x446480
#define EQ_Character__GetCharInfo2_x                               0x82BC10
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43E7B0
#define EQ_Character__GetFocusRangeModifier_x                      0x43E990
#define EQ_Character__Max_Endurance_x                              0x5B3780
#define EQ_Character__Max_HP_x                                     0x459440
#define EQ_Character__Max_Mana_x                                   0x5B35B0
#define EQ_Character__doCombatAbility_x                            0x5B0BA0
#define EQ_Character__UseSkill_x                                   0x46DC80
#define EQ_Character__GetConLevel_x                                0x5A5F10
#define EQ_Character__IsExpansionFlag_x                            0x421CC0
#define EQ_Character__TotalEffect_x                                0x44B4E0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x586500
#define EQ_Item__CreateItemTagString_x                             0x80B250
#define EQ_Item__IsStackable_x                                     0x7FF740
#define EQ_Item__GetImageNum_x                                     0x802430

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C1A00
#define EQ_LoadingS__Array_x                                       0xBA4D10

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B4F20
#define EQ_PC__GetAltAbilityIndex_x                                0x814120
#define EQ_PC__GetCombatAbility_x                                  0x8141B0
#define EQ_PC__GetCombatAbilityTimer_x                             0x814260
#define EQ_PC__GetItemTimerValue_x                                 0x5AE970
#define EQ_PC__HasLoreItem_x                                       0x5A9250
#define EQ_PC__AlertInventoryChanged_x                             0x5A5EE0
#define EQ_PC__GetPcZoneClient_x                                   0x5CF410
#define EQ_PC__RemoveMyAffect_x									   0x5ADE80

// EQItemList 
#define EQItemList__EQItemList_x                                   0x503960
#define EQItemList__add_item_x                                     0x5038A0
#define EQItemList__delete_item_x                                  0x503D60
#define EQItemList__FreeItemList_x                                 0x503C60

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A14C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BA3A0
#define EQPlayer__dEQPlayer_x                                      0x5C31C0
#define EQPlayer__DoAttack_x                                       0x5D5280
#define EQPlayer__EQPlayer_x                                       0x5C55E0
#define EQPlayer__SetNameSpriteState_x                             0x5BFE90
#define EQPlayer__SetNameSpriteTint_x                              0x5BB770
#define EQPlayer__IsBodyType_j_x                                   0x9152C0
#define EQPlayer__IsTargetable_x                                   0x915B80
#define EQPlayer__CanSee_x                                         0x9160A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5C9A20
#define EQPlayerManager__GetSpawnByName_x                          0x5C9E80

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x58C6F0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x58C730
#define KeypressHandler__ClearCommandStateArray_x                  0x58C2D0
#define KeypressHandler__HandleKeyDown_x                           0x58AC30
#define KeypressHandler__HandleKeyUp_x                             0x58AF50
#define KeypressHandler__SaveKeymapping_x                          0x58C3A0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FC4C0
#define MapViewMap__SaveEx_x                                       0x6FFDA0

#define PlayerPointManager__GetAltCurrency_x                       0x826BB0

// StringTable 
#define StringTable__getString_x                                   0x821670

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B3230

//Doors
#define EQSwitch__UseSwitch_x                                      0x542050

//IconCache
#define IconCache__GetIcon_x                                       0x6972E0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x68E0D0
#define CContainerMgr__CloseContainer_x                            0x68E8F0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x75D670

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x57F860

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D4270
#define EQ_Spell__SpellAffects_x                                   0x4D4310
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D4340
#define CharacterZoneClient__CalcAffectChange_x                    0x4477A0
#define CLootWnd__LootAll_x                                        0x6F1DC0

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A2E60
#define CTargetWnd__WndNotification_x                              0x7A2950

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7A8020
