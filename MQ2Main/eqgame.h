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
#define __ExpectedVersionDate                                     "Mar 31 2015"
#define __ExpectedVersionTime                                     "16:22:32"
#define __ActualVersionDate_x                                      0xA7B138
#define __ActualVersionTime_x                                      0xA7B144

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x592500
#define __MemChecker1_x                                            0x85AB90
#define __MemChecker2_x                                            0x629E60
#define __MemChecker3_x                                            0x629DB0
#define __MemChecker4_x                                            0x7DE7B0
#define __EncryptPad0_x                                            0xBF6978
#define __EncryptPad1_x                                            0xD7AC90
#define __EncryptPad2_x                                            0xC3F8F8
#define __EncryptPad3_x                                            0xC3F4F8
#define __EncryptPad4_x                                            0xD573B8
#define __AC1_x                                                    0x79BDB5
#define __AC2_x                                                    0x5484C7
#define __AC3_x                                                    0x55CCC0
#define __AC4_x                                                    0x563100
#define __AC5_x                                                    0x56EEDE
#define __AC6_x                                                    0x5729A2
#define __AC7_x                                                    0x5695AC
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
#define __do_loot_x                                                0x50FE80
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
#define pinstCContextMenuManager_x                                 0x179646C
#define pinstCVoiceMacroWnd_x                                      0x1021A10
#define pinstCHtmlWnd_x                                            0x1021B08
#define pinstIconCache_x                                           0x112F26C
#define pinstCTradeskillWnd_x                                      0x1134ED8
#define pinstCAdvLootWnd_x                                         0xEDAD78

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x527890
#define __ConvertItemTags_x                                        0x514B10
#define __ExecuteCmd_x                                             0x4FF4C0
#define __EQGetTime_x                                              0x85AEB0
#define __get_melee_range_x                                        0x5061A0
#define __GetGaugeValueFromEQ_x                                    0x79AB00
#define __GetLabelFromEQ_x                                         0x79BD40
#define __ToggleMount_x                                            0x6C45F0
#define __GetXTargetType_x                                         0x9191E0
#define __LoadFrontEnd_x                                           0x629510
#define __NewUIINI_x                                               0x79A400
#define __ProcessGameEvents_x                                      0x56B310
#define __ProcessMouseEvent_x                                      0x56AAB0
#define CrashDetected_x                                            0x62AFE0
#define wwsCrashReportCheckForUploader_x                           0x7EFDF0
#define DrawNetStatus_x                                            0x5A1F40
#define Util__FastTime_x                                           0x85AA00
#define Expansion_HoT_x                                            0xF9C3FC
#define __HelpPath_x                                               0x101FB60

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41EEA0

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C0080
#define AltAdvManager__IsAbilityReady_x                            0x4C00F0
#define AltAdvManager__GetAltAbility_x                             0x4C04B0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x464260
#define CharacterZoneClient__MakeMeVisible_x                       0x469320
// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x658D10

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6674B0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x581430

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x682000
#define CChatManager__InitContextMenu_x                            0x682B20

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8CB010
#define CContextMenu__dCContextMenu_x                              0x8CB220
#define CContextMenu__AddMenuItem_x                                0x8CB230
#define CContextMenu__RemoveMenuItem_x                             0x8CB510
#define CContextMenu__RemoveAllMenuItems_x                         0x8CB530
#define CContextMenuManager__AddMenu_x                             0x8B7110
#define CContextMenuManager__RemoveMenu_x                          0x8B7450
#define CContextMenuManager__PopupMenu_x                           0x8B78A0
#define CContextMenuManager__Flush_x                               0x8B7180

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8416A0
#define CChatService__GetFriendName_x                              0x8416B0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x687B90
#define CChatWindow__Clear_x                                       0x687740
#define CChatWindow__WndNotification_x                             0x6880D0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BB010
#define CComboWnd__Draw_x                                          0x8BB220
#define CComboWnd__GetCurChoice_x                                  0x8BADE0
#define CComboWnd__GetListRect_x                                   0x8BB4C0
#define CComboWnd__GetTextRect_x                                   0x8BB080
#define CComboWnd__InsertChoice_x                                  0x8BB530
#define CComboWnd__SetColors_x                                     0x8BAD70
#define CComboWnd__SetChoice_x                                     0x8BADA0
#define CComboWnd__GetItemCount_x                                  0x8BADD0 

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x691360
#define CContainerWnd__vftable_x                                   0xA84890

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4AE900
#define CDisplay__GetClickedActor_x                                0x4A7480
#define CDisplay__GetUserDefinedColor_x                            0x4A5D40
#define CDisplay__GetWorldFilePath_x                               0x4A5190
#define CDisplay__is3dON_x                                         0x4A4560
#define CDisplay__ReloadUI_x                                       0x4B9D70
#define CDisplay__WriteTextHD2_x                                   0x4AACA0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E16E0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8CFA90
#define CEditWnd__GetCharIndexPt_x                                 0x8D0B00
#define CEditWnd__GetDisplayString_x                               0x8CFC40
#define CEditWnd__GetHorzOffset_x                                  0x8CFF80
#define CEditWnd__GetLineForPrintableChar_x                        0x8D05E0
#define CEditWnd__GetSelStartPt_x                                  0x8D0DB0
#define CEditWnd__GetSTMLSafeText_x                                0x8D0110
#define CEditWnd__PointFromPrintableChar_x                         0x8D06D0
#define CEditWnd__SelectableCharFromPoint_x                        0x8D0840
#define CEditWnd__SetEditable_x                                    0x8D00E0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x548C10
#define CEverQuest__DoTellWindow_x                                 0x54E610
#define CEverQuest__DropHeldItemOnGround_x                         0x557140
#define CEverQuest__dsp_chat_x                                     0x54FDB0
#define CEverQuest__Emote_x                                        0x550010
#define CEverQuest__EnterZone_x                                    0x563920
#define CEverQuest__GetBodyTypeDesc_x                              0x545470
#define CEverQuest__GetClassDesc_x                                 0x54B180
#define CEverQuest__GetClassThreeLetterCode_x                      0x54B780
#define CEverQuest__GetDeityDesc_x                                 0x545D50
#define CEverQuest__GetLangDesc_x                                  0x545800
#define CEverQuest__GetRaceDesc_x                                  0x54B940
#define CEverQuest__InterpretCmd_x                                 0x5508F0
#define CEverQuest__LeftClickedOnPlayer_x                          0x567A10
#define CEverQuest__LMouseUp_x                                     0x569B00
#define CEverQuest__RightClickedOnPlayer_x                         0x568510
#define CEverQuest__RMouseUp_x                                     0x569560
#define CEverQuest__SetGameState_x                                 0x5492C0
#define CEverQuest__UPCNotificationFlush_x                         0x551A90
#define CEverQuest__IssuePetCommand_x                              0x5515F0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A1F70
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A1FD0
#define CGaugeWnd__Draw_x                                          0x6A2400

// CGuild
#define CGuild__FindMemberByName_x                                 0x435B40

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6BF020

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CCE40
#define CInvSlotMgr__MoveItem_x                                    0x6CDD80
#define CInvSlotMgr__SelectSlot_x                                  0x6CCEF0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CC2E0
#define CInvSlot__SliderComplete_x                                 0x6C9CA0
#define CInvSlot__GetItemBase_x                                    0x6C9110

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6CEF40

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x797610
#define CItemDisplayWnd__UpdateStrings_x                           0x6D0290

// CLabel 
#define CLabel__Draw_x                                             0x6EAF70

// CListWnd
#define CListWnd__CListWnd_x                                       0x8A6BF0
#define CListWnd__dCListWnd_x                                      0x8A7C10
#define CListWnd__AddColumn_x                                      0x8A7BB0
#define CListWnd__AddColumn1_x                                     0x8A7420
#define CListWnd__AddLine_x                                        0x8A6EA0
#define CListWnd__AddString_x                                      0x8A70B0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A3F30
#define CListWnd__CalculateVSBRange_x                              0x8A60A0
#define CListWnd__ClearAllSel_x                                    0x8A3200
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8A6A80
#define CListWnd__Compare_x                                        0x8A4A30
#define CListWnd__Draw_x                                           0x8A5CB0
#define CListWnd__DrawColumnSeparators_x                           0x8A5B40
#define CListWnd__DrawHeader_x                                     0x8A3510
#define CListWnd__DrawItem_x                                       0x8A5080
#define CListWnd__DrawLine_x                                       0x8A57E0
#define CListWnd__DrawSeparator_x                                  0x8A5BE0
#define CListWnd__EnsureVisible_x                                  0x8A4090
#define CListWnd__ExtendSel_x                                      0x8A4F90
#define CListWnd__GetColumnMinWidth_x                              0x8A2BC0
#define CListWnd__GetColumnWidth_x                                 0x8A2AE0
#define CListWnd__GetCurSel_x                                      0x8A22A0
#define CListWnd__GetItemAtPoint_x                                 0x8A4320
#define CListWnd__GetItemAtPoint1_x                                0x8A4390
#define CListWnd__GetItemData_x                                    0x8A25F0
#define CListWnd__GetItemHeight_x                                  0x8A3BA0
#define CListWnd__GetItemIcon_x                                    0x8A27D0
#define CListWnd__GetItemRect_x                                    0x8A4160
#define CListWnd__GetItemText_x                                    0x8A2680
#define CListWnd__GetSelList_x                                     0x8A7310
#define CListWnd__GetSeparatorRect_x                               0x8A4950
#define CListWnd__RemoveLine_x                                     0x8A7290
#define CListWnd__SetColors_x                                      0x8A23F0
#define CListWnd__SetColumnJustification_x                         0x8A2E90
#define CListWnd__SetColumnWidth_x                                 0x8A2B70
#define CListWnd__SetCurSel_x                                      0x8A22E0
#define CListWnd__SetItemColor_x                                   0x8A6760
#define CListWnd__SetItemData_x                                    0x8A32B0
#define CListWnd__SetItemText_x                                    0x8A65A0
#define CListWnd__ShiftColumnSeparator_x                           0x8A6430
#define CListWnd__Sort_x                                           0x8A7D10
#define CListWnd__ToggleSel_x                                      0x8A3180

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x704560

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x725650
#define CMerchantWnd__RequestBuyItem_x                             0x72C4C0
#define CMerchantWnd__RequestSellItem_x                            0x72CF30
#define CMerchantWnd__SelectRecoverySlot_x                         0x725900
#define CMerchantWnd__SelectBuySellSlot_x                          0x724B60
#define CMerchantWnd__ActualSelect_x                               0x7293E0

// CObfuscator
#define CObfuscator__doit_x                                        0x821740

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8C5EE0
#define CSidlManager__CreateLabel_x                                0x78D620

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x650020
#define CSidlScreenWnd__CalculateVSBRange_x                        0x64FF40
#define CSidlScreenWnd__ConvertToRes_x                             0x8E15C0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8BDC80
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8BF190
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8BF240
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8BE700
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8BD650
#define CSidlScreenWnd__EnableIniStorage_x                         0x8BCD90
#define CSidlScreenWnd__GetSidlPiece_x                             0x8BD840
#define CSidlScreenWnd__Init1_x                                    0x8BEE70
#define CSidlScreenWnd__LoadIniInfo_x                              0x8BDD30
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8BCF50
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8BE950
#define CSidlScreenWnd__StoreIniInfo_x                             0x8BC850
#define CSidlScreenWnd__StoreIniVis_x                              0x8BCD20
#define CSidlScreenWnd__WndNotification_x                          0x8BEBF0
#define CSidlScreenWnd__GetChildItem_x                             0x8BCE60
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B02F0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5EB6C0
#define CSkillMgr__GetSkillCap_x                                   0x5EB860
#define CSkillMgr__GetNameToken_x                                  0x5EB330

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E0880
#define CSliderWnd__SetValue_x                                     0x8E0A50
#define CSliderWnd__SetNumTicks_x                                  0x8E11D0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x7952B0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8DB230
#define CStmlWnd__CalculateHSBRange_x                              0x8D3770
#define CStmlWnd__CalculateVSBRange_x                              0x8D3800
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D3980
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D4260
#define CStmlWnd__ForceParseNow_x                                  0x8DBB80
#define CStmlWnd__GetNextTagPiece_x                                0x8D4160
#define CStmlWnd__GetSTMLText_x                                    0x686FE0
#define CStmlWnd__GetVisibleText_x                                 0x8D4CB0
#define CStmlWnd__InitializeWindowVariables_x                      0x8D7040
#define CStmlWnd__MakeStmlColorTag_x                               0x8D2A70
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D2AD0
#define CStmlWnd__SetSTMLText_x                                    0x8D88A0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8DAED0
#define CStmlWnd__UpdateHistoryString_x                            0x8D5BF0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E2DA0
#define CTabWnd__DrawCurrentPage_x                                 0x8E2610
#define CTabWnd__DrawTab_x                                         0x8E23E0
#define CTabWnd__GetCurrentPage_x                                  0x8E29E0
#define CTabWnd__GetPageInnerRect_x                                0x8E20D0
#define CTabWnd__GetTabInnerRect_x                                 0x8E22D0
#define CTabWnd__GetTabRect_x                                      0x8E21A0
#define CTabWnd__InsertPage_x                                      0x8E3090
#define CTabWnd__SetPage_x                                         0x8E2A10
#define CTabWnd__SetPageRect_x                                     0x8E2CE0
#define CTabWnd__UpdatePage_x                                      0x8E3030

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431950

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BA9E0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8E7F30

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A04F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4022C0
#define CXStr__CXStr1_x                                            0x7CB940
#define CXStr__CXStr3_x                                            0x857A90
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x857C00
#define CXStr__operator_equal1_x                                   0x857C50
#define CXStr__operator_plus_equal1_x                              0x858D30

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8AF4E0
#define CXWnd__Center_x                                            0x8B5750
#define CXWnd__ClrFocus_x                                          0x8AF0D0
#define CXWnd__DoAllDrawing_x                                      0x8B5380
#define CXWnd__DrawChildren_x                                      0x8B5530
#define CXWnd__DrawColoredRect_x                                   0x8AF8A0
#define CXWnd__DrawTooltip_x                                       0x8AFB50
#define CXWnd__DrawTooltipAtPoint_x                                0x8B42D0
#define CXWnd__GetBorderFrame_x                                    0x8AFFC0
#define CXWnd__GetChildWndAt_x                                     0x8B6110
#define CXWnd__GetClientClipRect_x                                 0x8AFD70
#define CXWnd__GetScreenClipRect_x                                 0x8B49C0
#define CXWnd__GetScreenRect_x                                     0x8B0190
#define CXWnd__GetTooltipRect_x                                    0x8AF9E0
#define CXWnd__GetWindowTextA_x                                    0x422E90
#define CXWnd__IsActive_x                                          0x8AAA30
#define CXWnd__IsDescendantOf_x                                    0x8AFF00
#define CXWnd__IsReallyVisible_x                                   0x8B32E0
#define CXWnd__IsType_x                                            0x8E4710
#define CXWnd__Move_x                                              0x8B29C0
#define CXWnd__Move1_x                                             0x8B5020
#define CXWnd__ProcessTransition_x                                 0x8AF490
#define CXWnd__Refade_x                                            0x8AF270
#define CXWnd__Resize_x                                            0x8B0260
#define CXWnd__Right_x                                             0x8B47C0
#define CXWnd__SetFocus_x                                          0x8B1B10
#define CXWnd__SetFont_x                                           0x8AF120
#define CXWnd__SetKeyTooltip_x                                     0x8B04C0
#define CXWnd__SetMouseOver_x                                      0x8B4D10
#define CXWnd__StartFade_x                                         0x8AF530
#define CXWnd__GetChildItem_x                                      0x8B4C50

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8AC350
#define CXWndManager__DrawWindows_x                                0x8ABF90
#define CXWndManager__GetKeyboardFlags_x                           0x8AA560
#define CXWndManager__HandleKeyboardMsg_x                          0x8AAED0
#define CXWndManager__RemoveWnd_x                                  0x8AABC0

// CDBStr
#define CDBStr__GetString_x                                        0x4A29E0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44DB70
#define EQ_Character__Cur_HP_x                                     0x463930
#define EQ_Character__GetAACastingTimeModifier_x                   0x446C30
#define EQ_Character__GetCharInfo2_x                               0x82C040
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EF60
#define EQ_Character__GetFocusRangeModifier_x                      0x43F140
#define EQ_Character__Max_Endurance_x                              0x5B4040
#define EQ_Character__Max_HP_x                                     0x459C20
#define EQ_Character__Max_Mana_x                                   0x5B3E70
#define EQ_Character__doCombatAbility_x                            0x5B1460
#define EQ_Character__UseSkill_x                                   0x46E460
#define EQ_Character__GetConLevel_x                                0x5A6600
#define EQ_Character__IsExpansionFlag_x                            0x4223E0
#define EQ_Character__TotalEffect_x                                0x44BC90

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x586C60
#define EQ_Item__CreateItemTagString_x                             0x80B510
#define EQ_Item__IsStackable_x                                     0x7FFA10
#define EQ_Item__GetImageNum_x                                     0x8026F0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C21A0
#define EQ_LoadingS__Array_x                                       0xBA4D10

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B57E0
#define EQ_PC__GetAltAbilityIndex_x                                0x814490
#define EQ_PC__GetCombatAbility_x                                  0x814520
#define EQ_PC__GetCombatAbilityTimer_x                             0x8145D0
#define EQ_PC__GetItemTimerValue_x                                 0x5AF230
#define EQ_PC__HasLoreItem_x                                       0x5A9940
#define EQ_PC__AlertInventoryChanged_x                             0x5A65D0
#define EQ_PC__GetPcZoneClient_x                                   0x5CFBF0
#define EQ_PC__RemoveMyAffect_x									   0x5AE740

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5041B0
#define EQItemList__add_item_x                                     0x5040F0
#define EQItemList__delete_item_x                                  0x5045B0
#define EQItemList__FreeItemList_x                                 0x5044B0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A1BB0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BAC50
#define EQPlayer__dEQPlayer_x                                      0x5C3A70
#define EQPlayer__DoAttack_x                                       0x5D5A60
#define EQPlayer__EQPlayer_x                                       0x5C5E90
#define EQPlayer__SetNameSpriteState_x                             0x5C0740
#define EQPlayer__SetNameSpriteTint_x                              0x5BC020
#define EQPlayer__IsBodyType_j_x                                   0x915410
#define EQPlayer__IsTargetable_x                                   0x915CD0
#define EQPlayer__CanSee_x                                         0x9161F0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CA190
#define EQPlayerManager__GetSpawnByName_x                          0x5CA5F0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x58CF40
#define KeypressHandler__AttachKeyToEqCommand_x                    0x58CF80
#define KeypressHandler__ClearCommandStateArray_x                  0x58CB20
#define KeypressHandler__HandleKeyDown_x                           0x58B480
#define KeypressHandler__HandleKeyUp_x                             0x58B7A0
#define KeypressHandler__SaveKeymapping_x                          0x58CBF0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FC940
#define MapViewMap__SaveEx_x                                       0x700220

#define PlayerPointManager__GetAltCurrency_x                       0x826F20

// StringTable 
#define StringTable__getString_x                                   0x8219E0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B3AF0

//Doors
#define EQSwitch__UseSwitch_x                                      0x5427D0

//IconCache
#define IconCache__GetIcon_x                                       0x6977C0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x68E670
#define CContainerMgr__CloseContainer_x                            0x68EE90

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x75D930

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x57FEE0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D4B40
#define EQ_Spell__SpellAffects_x                                   0x4D4BE0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D4C10
#define CharacterZoneClient__CalcAffectChange_x                    0x447F50
#define CLootWnd__LootAll_x                                        0x6F2320

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A3070
#define CTargetWnd__WndNotification_x                              0x7A2B60

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7A8230
