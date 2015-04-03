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
#include "eqgame-private(Test).h"
#endif

#define __ClientName                                              "eqgame"
#define __ExpectedVersionDate                                     "Mar 31 2015"
#define __ExpectedVersionTime                                     "15:46:50"
#define __ActualVersionDate_x                                      0xA7B118
#define __ActualVersionTime_x                                      0xA7B124

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5929A0
#define __MemChecker1_x                                            0x85ABB0
#define __MemChecker2_x                                            0x62A360
#define __MemChecker3_x                                            0x62A2B0
#define __MemChecker4_x                                            0x7DE750
#define __EncryptPad0_x                                            0xBF6978
#define __EncryptPad1_x                                            0xD7AC90
#define __EncryptPad2_x                                            0xC3F8F8
#define __EncryptPad3_x                                            0xC3F4F8
#define __EncryptPad4_x                                            0xD573B8
#define __AC1_x                                                    0x79BBF5
#define __AC2_x                                                    0x548C57
#define __AC3_x                                                    0x55D440
#define __AC4_x                                                    0x563880
#define __AC5_x                                                    0x56F64E
#define __AC6_x                                                    0x573112
#define __AC7_x                                                    0x569D1C
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
#define __do_loot_x                                                0x510690
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
#define pinstCSidlManager_x                                        0x17964FC
#define pinstCXWndManager_x                                        0x17964F4
#define instDynamicZone_x                                          0xF9AEB8
#define pinstDZMember_x                                            0xF9AFC8
#define pinstDZTimerInfo_x                                         0xF9AFCC
#define pinstEQItemList_x                                          0xF8A730
#define instEQMisc_x                                               0xB97110
#define pinstEQSoundManager_x                                      0xEDB878
#define instExpeditionLeader_x                                     0xF9AF02
#define instExpeditionName_x                                       0xF9AF42
#define pinstGroup_x                                               0xF8BAA6
#define pinstImeManager_x                                          0x1796500
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
#define pinstCContextMenuManager_x                                 0x179646C
#define pinstCVoiceMacroWnd_x                                      0x1021A10
#define pinstCHtmlWnd_x                                            0x1021B08
#define pinstIconCache_x                                           0x112F26C
#define pinstCTradeskillWnd_x                                      0x1134ED8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5280A0
#define __ConvertItemTags_x                                        0x515320
#define __ExecuteCmd_x                                             0x4FFCC0
#define __EQGetTime_x                                              0x85AED0
#define __get_melee_range_x                                        0x5069B0
#define __GetGaugeValueFromEQ_x                                    0x79A940
#define __GetLabelFromEQ_x                                         0x79BB80
#define __ToggleMount_x                                            0x6C4880
#define __GetXTargetType_x                                         0x919380
#define __LoadFrontEnd_x                                           0x629A10
#define __NewUIINI_x                                               0x79A240
#define __ProcessGameEvents_x                                      0x56BA80
#define __ProcessMouseEvent_x                                      0x56B220
#define CrashDetected_x                                            0x62B4E0
#define wwsCrashReportCheckForUploader_x                           0x7EFB30
#define DrawNetStatus_x                                            0x5A22E0
#define Util__FastTime_x                                           0x85AA20
#define Expansion_HoT_x                                            0xF9C3FC
#define __HelpPath_x                                               0x101FB60
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C0040
#define AltAdvManager__IsAbilityReady_x                            0x4C00B0
#define AltAdvManager__GetAltAbility_x                             0x4C0470

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x464110
#define CharacterZoneClient__MakeMeVisible_x                       0x4691D0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6591B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x667620

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x581B00

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x682460
#define CChatManager__InitContextMenu_x                            0x682F80

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8CAF70
#define CContextMenu__AddMenuItem_x                                0x8CB190
#define CContextMenu__dCContextMenu_x                              0x8CB180
#define CContextMenu__RemoveMenuItem_x                             0x8CB480
#define CContextMenu__RemoveAllMenuItems_x                         0x8CB4A0
#define CContextMenuManager__AddMenu_x                             0x8B70F0
#define CContextMenuManager__RemoveMenu_x                          0x8B7410
#define CContextMenuManager__PopupMenu_x                           0x8B7860
#define CContextMenuManager__Flush_x                               0x8B7160

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x7FF300
#define CChatService__GetFriendName_x                              0x841730

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x687FF0
#define CChatWindow__Clear_x                                       0x687BA0
#define CChatWindow__WndNotification_x                             0x688520

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BAFD0
#define CComboWnd__Draw_x                                          0x8BB1E0
#define CComboWnd__GetCurChoice_x                                  0x8BADA0
#define CComboWnd__GetListRect_x                                   0x8BB480
#define CComboWnd__GetTextRect_x                                   0x8BB040
#define CComboWnd__InsertChoice_x                                  0x8BB4F0
#define CComboWnd__SetColors_x                                     0x8BAD30
#define CComboWnd__SetChoice_x                                     0x8BAD60

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x691760
#define CContainerWnd__vftable_x                                   0xA84878

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4AE8C0
#define CDisplay__GetClickedActor_x                                0x4A7440
#define CDisplay__GetUserDefinedColor_x                            0x4A5D00
#define CDisplay__GetWorldFilePath_x                               0x4A5150
#define CDisplay__is3dON_x                                         0x4A4520
#define CDisplay__ReloadUI_x                                       0x4B9D30
#define CDisplay__WriteTextHD2_x                                   0x4AAC60

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E1670

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8CF9B0
#define CEditWnd__GetCharIndexPt_x                                 0x8D0A50
#define CEditWnd__GetDisplayString_x                               0x8CFB60
#define CEditWnd__GetHorzOffset_x                                  0x8CFEA0
#define CEditWnd__GetLineForPrintableChar_x                        0x8D0510
#define CEditWnd__GetSelStartPt_x                                  0x8D0D10
#define CEditWnd__GetSTMLSafeText_x                                0x8D0040
#define CEditWnd__PointFromPrintableChar_x                         0x8D0600
#define CEditWnd__SelectableCharFromPoint_x                        0x8D0780
#define CEditWnd__SetEditable_x                                    0x8D0010

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x5493A0
#define CEverQuest__DoTellWindow_x                                 0x54ED90
#define CEverQuest__DropHeldItemOnGround_x                         0x5578C0
#define CEverQuest__dsp_chat_x                                     0x550530
#define CEverQuest__Emote_x                                        0x550790
#define CEverQuest__EnterZone_x                                    0x5640A0
#define CEverQuest__GetBodyTypeDesc_x                              0x545C00
#define CEverQuest__GetClassDesc_x                                 0x54B910
#define CEverQuest__GetClassThreeLetterCode_x                      0x54BF10
#define CEverQuest__GetDeityDesc_x                                 0x5464E0
#define CEverQuest__GetLangDesc_x                                  0x545F90
#define CEverQuest__GetRaceDesc_x                                  0x54C0D0
#define CEverQuest__InterpretCmd_x                                 0x551070
#define CEverQuest__LeftClickedOnPlayer_x                          0x568180
#define CEverQuest__LMouseUp_x                                     0x56A270
#define CEverQuest__RightClickedOnPlayer_x                         0x568C80
#define CEverQuest__RMouseUp_x                                     0x569CD0
#define CEverQuest__SetGameState_x                                 0x549A50
#define CEverQuest__UPCNotificationFlush_x                         0x552210
#define CEverQuest__IssuePetCommand_x                              0x551D70

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A2250
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A22B0
#define CGaugeWnd__Draw_x                                          0x6A26E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x435A80

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6BF2C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CD080
#define CInvSlotMgr__MoveItem_x                                    0x6CDFC0
#define CInvSlotMgr__SelectSlot_x                                  0x6CD130

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CC520
#define CInvSlot__SliderComplete_x                                 0x6C9EF0
#define CInvSlot__GetItemBase_x                                    0x6C9390

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6CF150

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x797450
#define CItemDisplayWnd__UpdateStrings_x                           0x6D0490

// CLabel 
#define CLabel__Draw_x                                             0x6EB0A0

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8A6EB0
#define CListWnd__dCListWnd_x                                      0x8A7EE0
#define CListWnd__AddColumn_x                                      0x8A7E80
#define CListWnd__AddColumn1_x                                     0x8A76F0
#define CListWnd__AddLine_x                                        0x8A7170
#define CListWnd__AddString_x                                      0x8A7380
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A41E0
#define CListWnd__CalculateVSBRange_x                              0x8A6360
#define CListWnd__ClearAllSel_x                                    0x8A34A0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8A6D40
#define CListWnd__Compare_x                                        0x8A4CE0
#define CListWnd__Draw_x                                           0x8A5F70
#define CListWnd__DrawColumnSeparators_x                           0x8A5E00
#define CListWnd__DrawHeader_x                                     0x8A37B0
#define CListWnd__DrawItem_x                                       0x8A5330
#define CListWnd__DrawLine_x                                       0x8A5AA0
#define CListWnd__DrawSeparator_x                                  0x8A5EA0
#define CListWnd__EnsureVisible_x                                  0x8A4340
#define CListWnd__ExtendSel_x                                      0x8A5240
#define CListWnd__GetColumnMinWidth_x                              0x8A2E60
#define CListWnd__GetColumnWidth_x                                 0x8A2D80
#define CListWnd__GetCurSel_x                                      0x8A2560
#define CListWnd__GetItemAtPoint_x                                 0x8A45E0
#define CListWnd__GetItemAtPoint1_x                                0x8A4650
#define CListWnd__GetItemData_x                                    0x8A2890
#define CListWnd__GetItemHeight_x                                  0x8A3E40
#define CListWnd__GetItemIcon_x                                    0x8A2A70
#define CListWnd__GetItemRect_x                                    0x8A4420
#define CListWnd__GetItemText_x                                    0x8A2920
#define CListWnd__GetSelList_x                                     0x8A75E0
#define CListWnd__GetSeparatorRect_x                               0x8A4C10
#define CListWnd__RemoveLine_x                                     0x8A7560
#define CListWnd__SetColors_x                                      0x8A26B0
#define CListWnd__SetColumnJustification_x                         0x8A3130
#define CListWnd__SetColumnWidth_x                                 0x8A2E10
#define CListWnd__SetCurSel_x                                      0x8A25A0
#define CListWnd__SetItemColor_x                                   0x8A6A20
#define CListWnd__SetItemData_x                                    0x8A3550
#define CListWnd__SetItemText_x                                    0x8A6860
#define CListWnd__ShiftColumnSeparator_x                           0x8A66F0
#define CListWnd__Sort_x                                           0x8A7FE0
#define CListWnd__ToggleSel_x                                      0x8A3420

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x704560

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7255D0
#define CMerchantWnd__RequestBuyItem_x                             0x72C3D0
#define CMerchantWnd__RequestSellItem_x                            0x72CE20
#define CMerchantWnd__SelectRecoverySlot_x                         0x725880
#define CMerchantWnd__SelectBuySellSlot_x                          0x724AE0
#define CMerchantWnd__ActualSelect_x                               0x729310

// CObfuscator
#define CObfuscator__doit_x                                        0x821890

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8C5E40
#define CSidlManager__CreateLabel_x                                0x78D4A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x6504B0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6503D0
#define CSidlScreenWnd__ConvertToRes_x                             0x8E1550
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8BDC30
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8BF110
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8BF1C0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8BE680
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8BD600
#define CSidlScreenWnd__EnableIniStorage_x                         0x8BCD50
#define CSidlScreenWnd__GetSidlPiece_x                             0x8BD7F0
#define CSidlScreenWnd__Init1_x                                    0x8BEDE0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8BDCE0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8BCF10
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8BE8D0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8BC820
#define CSidlScreenWnd__StoreIniVis_x                              0x8BCCE0
#define CSidlScreenWnd__WndNotification_x                          0x8BEB60
#define CSidlScreenWnd__GetChildItem_x                             0x8BCE20
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B03D0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5EBAB0
#define CSkillMgr__GetSkillCap_x                                   0x5EBC50
#define CSkillMgr__GetNameToken_x                                  0x5EB720

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E0810
#define CSliderWnd__SetValue_x                                     0x8E09E0
#define CSliderWnd__SetNumTicks_x                                  0x8E1160

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7950F0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8DB1C0
#define CStmlWnd__CalculateHSBRange_x                              0x8D3790
#define CStmlWnd__CalculateVSBRange_x                              0x8D3700
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D3910
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D41F0
#define CStmlWnd__ForceParseNow_x                                  0x8DBB10
#define CStmlWnd__GetNextTagPiece_x                                0x8D40F0
#define CStmlWnd__GetSTMLText_x                                    0x687440
#define CStmlWnd__GetVisibleText_x                                 0x8D4C40
#define CStmlWnd__InitializeWindowVariables_x                      0x8D6FB0
#define CStmlWnd__MakeStmlColorTag_x                               0x8D2A00
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D2A60
#define CStmlWnd__SetSTMLText_x                                    0x8D8810
#define CStmlWnd__StripFirstSTMLLines_x                            0x8DAE60
#define CStmlWnd__UpdateHistoryString_x                            0x8D5B70

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E2D50
#define CTabWnd__DrawCurrentPage_x                                 0x8E25C0
#define CTabWnd__DrawTab_x                                         0x8E2380
#define CTabWnd__GetCurrentPage_x                                  0x8E2990
#define CTabWnd__GetPageInnerRect_x                                0x8E2070
#define CTabWnd__GetTabInnerRect_x                                 0x8E2270
#define CTabWnd__GetTabRect_x                                      0x8E2140
#define CTabWnd__InsertPage_x                                      0x8E3040
#define CTabWnd__SetPage_x                                         0x8E29C0
#define CTabWnd__SetPageRect_x                                     0x8E2C90
#define CTabWnd__UpdatePage_x                                      0x8E2FE0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431780

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BA9A0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8E7F10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A0810

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x58F030
#define CXStr__CXStr1_x                                            0x8954F0
#define CXStr__CXStr3_x                                            0x857AB0
#define CXStr__dCXStr_x                                            0x58F3A0
#define CXStr__operator_equal_x                                    0x857C20
#define CXStr__operator_equal1_x                                   0x857C70
#define CXStr__operator_plus_equal1_x                              0x858D50

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8AF650
#define CXWnd__Center_x                                            0x8B56F0
#define CXWnd__ClrFocus_x                                          0x8AF230
#define CXWnd__DoAllDrawing_x                                      0x8B5340
#define CXWnd__DrawChildren_x                                      0x8B54E0

#define CXWnd__DrawColoredRect_x                                   0x8AFA00
#define CXWnd__DrawTooltip_x                                       0x8AFCA0
#define CXWnd__DrawTooltipAtPoint_x                                0x8B42C0
#define CXWnd__GetBorderFrame_x                                    0x8B00D0
#define CXWnd__GetChildWndAt_x                                     0x8B60C0
#define CXWnd__GetClientClipRect_x                                 0x8AFEB0
#define CXWnd__GetScreenClipRect_x                                 0x8B49C0
#define CXWnd__GetScreenRect_x                                     0x8B0280
#define CXWnd__GetTooltipRect_x                                    0x8AFB30
#define CXWnd__GetWindowTextA_x                                    0x422C40
#define CXWnd__IsActive_x                                          0x8AAC80
#define CXWnd__IsDescendantOf_x                                    0x8B0020
#define CXWnd__IsReallyVisible_x                                   0x8B3320
#define CXWnd__IsType_x                                            0x8E4730
#define CXWnd__Move_x                                              0x8B2A90
#define CXWnd__Move1_x                                             0x8B5000
#define CXWnd__ProcessTransition_x                                 0x8AF600
#define CXWnd__Refade_x                                            0x8AF3D0
#define CXWnd__Resize_x                                            0x8B0330
#define CXWnd__Right_x                                             0x8B47C0
#define CXWnd__SetFocus_x                                          0x8B1C00
#define CXWnd__SetFont_x                                           0x8AF280
#define CXWnd__SetKeyTooltip_x                                     0x8B05A0
#define CXWnd__SetMouseOver_x                                      0x8B4CF0
#define CXWnd__StartFade_x                                         0x8AF6A0
#define CXWnd__GetChildItem_x                                      0x8B4C30

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8AC590
#define CXWndManager__DrawWindows_x                                0x8AC1D0
#define CXWndManager__GetKeyboardFlags_x                           0x8AA7F0
#define CXWndManager__HandleKeyboardMsg_x                          0x8AB120
#define CXWndManager__RemoveWnd_x                                  0x8AAE10

// CDBStr
#define CDBStr__GetString_x                                        0x4A2990

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44DA70
#define EQ_Character__Cur_HP_x                                     0x4637E0
#define EQ_Character__GetAACastingTimeModifier_x                   0x446B50
#define EQ_Character__GetCharInfo2_x                               0x82C140
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EEA0
#define EQ_Character__GetFocusRangeModifier_x                      0x43F080
#define EQ_Character__Max_Endurance_x                              0x5B4530
#define EQ_Character__Max_HP_x                                     0x459AE0
#define EQ_Character__Max_Mana_x                                   0x5B4360
#define EQ_Character__doCombatAbility_x                            0x5B1960
#define EQ_Character__UseSkill_x                                   0x46E300
#define EQ_Character__GetConLevel_x                                0x5A68D0
#define EQ_Character__IsExpansionFlag_x                            0x422180
#define EQ_Character__TotalEffect_x                                0x44BB80

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x5872A0
#define EQ_Item__CreateItemTagString_x                             0x80B640
#define EQ_Item__IsStackable_x                                     0x7FF7D0
#define EQ_Item__GetImageNum_x                                     0x802440

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C21B0
#define EQ_LoadingS__Array_x                                       0xBA4D10

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B5CC0
#define EQ_PC__GetAltAbilityIndex_x                                0x8145D0
#define EQ_PC__GetCombatAbility_x                                  0x814660
#define EQ_PC__GetCombatAbilityTimer_x                             0x814710
#define EQ_PC__GetItemTimerValue_x                                 0x5AF730
#define EQ_PC__HasLoreItem_x                                       0x5A9C20
#define EQ_PC__AlertInventoryChanged_x                             0x5A68A0
#define EQ_PC__GetPcZoneClient_x                                   0x5D00F0
#define EQ_PC__RemoveMyAffect_x                                    0x5AEC40

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5049B0
#define EQItemList__add_item_x                                     0x5048F0
#define EQItemList__delete_item_x                                  0x504DB0
#define EQItemList__FreeItemList_x                                 0x504CB0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A1B30

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BB160
#define EQPlayer__dEQPlayer_x                                      0x5C3F80
#define EQPlayer__DoAttack_x                                       0x5D5F50
#define EQPlayer__EQPlayer_x                                       0x5C63A0
#define EQPlayer__SetNameSpriteState_x                             0x5C0C50
#define EQPlayer__SetNameSpriteTint_x                              0x5BC530
#define EQPlayer__IsBodyType_j_x                                   0x915530
#define EQPlayer__IsTargetable_x                                   0x915DF0
#define EQPlayer__CanSee_x                                         0x916310

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CA6A0
#define EQPlayerManager__GetSpawnByName_x                          0x5CAB00

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x58D360
#define KeypressHandler__AttachKeyToEqCommand_x                    0x58D3A0
#define KeypressHandler__ClearCommandStateArray_x                  0x58CF40
#define KeypressHandler__HandleKeyDown_x                           0x58B8A0
#define KeypressHandler__HandleKeyUp_x                             0x58BBC0
#define KeypressHandler__SaveKeymapping_x                          0x58D010

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FC940
#define MapViewMap__SaveEx_x                                       0x700220

#define PlayerPointManager__GetAltCurrency_x                       0x827030

// StringTable 
#define StringTable__getString_x                                   0x821B30

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B3FE0

//Doors
#define EQSwitch__UseSwitch_x                                      0x543050

//IconCache
#define IconCache__GetIcon_x                                       0x697BC0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x68EA70
#define CContainerMgr__CloseContainer_x                            0x68F290

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x75D7E0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5805D0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D4AC0
#define EQ_Spell__SpellAffects_x                                   0x4D4B60
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D4B90
#define CharacterZoneClient__CalcAffectChange_x                    0x447E70
#define CLootWnd__LootAll_x                                        0x6F2390
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7476E0
#define CTargetWnd__WndNotification_x                              0x7A2A10

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7A80E0
