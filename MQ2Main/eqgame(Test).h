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
#define __ExpectedVersionDate                                     "Mar 20 2015"
#define __ExpectedVersionTime                                     "18:36:33"
#define __ActualVersionDate_x                                      0xA7B178
#define __ActualVersionTime_x                                      0xA7B184

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x592360
#define __MemChecker1_x                                            0x85AB60
#define __MemChecker2_x                                            0x629D10
#define __MemChecker3_x                                            0x629C60
#define __MemChecker4_x                                            0x7DE810
#define __EncryptPad0_x                                            0xBF6978
#define __EncryptPad1_x                                            0xD7AC90
#define __EncryptPad2_x                                            0xC3F8F8
#define __EncryptPad3_x                                            0xC3F4F8
#define __EncryptPad4_x                                            0xD573B8
#define __AC1_x                                                    0x79BA25
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
#define __do_loot_x                                                0x510020
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
#define __CastRay_x                                                0x527A30
#define __ConvertItemTags_x                                        0x514CB0
#define __ExecuteCmd_x                                             0x4FF640
#define __EQGetTime_x                                              0x85AE80
#define __get_melee_range_x                                        0x506340
#define __GetGaugeValueFromEQ_x                                    0x79A770
#define __GetLabelFromEQ_x                                         0x79B9B0
#define __ToggleMount_x                                            0x6C44A0
#define __GetXTargetType_x                                         0x9191F0
#define __LoadFrontEnd_x                                           0x6293C0
#define __NewUIINI_x                                               0x79A070
#define __ProcessGameEvents_x                                      0x56B460
#define __ProcessMouseEvent_x                                      0x56AC00
#define CrashDetected_x                                            0x62AE90
#define wwsCrashReportCheckForUploader_x                           0x7EF960
#define DrawNetStatus_x                                            0x5A1E20
#define Util__FastTime_x                                           0x85A9D0
#define Expansion_HoT_x                                            0xF9C3FC
#define __HelpPath_x                                               0x101FB60
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4BFBF0
#define AltAdvManager__IsAbilityReady_x                            0x4BFC60
#define AltAdvManager__GetAltAbility_x                             0x4C0020

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463CC0
#define CharacterZoneClient__MakeMeVisible_x                       0x468D80

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x658C40

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x666AC0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5815B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x681F50
#define CChatManager__InitContextMenu_x                            0x682A70

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8BE740
#define CContextMenu__AddMenuItem_x                                0x8BE960
#define CContextMenu__dCContextMenu_x                              0x8BE950
#define CContextMenu__RemoveMenuItem_x                             0x8BEC50
#define CContextMenu__RemoveAllMenuItems_x                         0x8BEC70
#define CContextMenuManager__AddMenu_x                             0x8BF020
#define CContextMenuManager__RemoveMenu_x                          0x8BF340
#define CContextMenuManager__PopupMenu_x                           0x8BF790
#define CContextMenuManager__Flush_x                               0x8BF090

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8416C0
#define CChatService__GetFriendName_x                              0x8416D0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x687AE0
#define CChatWindow__Clear_x                                       0x687690
#define CChatWindow__WndNotification_x                             0x688010

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BDAF0
#define CComboWnd__Draw_x                                          0x8BDD00
#define CComboWnd__GetCurChoice_x                                  0x8BD8C0
#define CComboWnd__GetListRect_x                                   0x8BDFA0
#define CComboWnd__GetTextRect_x                                   0x8BDB60
#define CComboWnd__InsertChoice_x                                  0x8BE010
#define CComboWnd__SetColors_x                                     0x8BD850
#define CComboWnd__SetChoice_x                                     0x8BD880

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x6911F0
#define CContainerWnd__vftable_x                                   0xA848D0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4AE3A0
#define CDisplay__GetClickedActor_x                                0x4A6F20
#define CDisplay__GetUserDefinedColor_x                            0x4A57E0
#define CDisplay__GetWorldFilePath_x                               0x4A4C30
#define CDisplay__is3dON_x                                         0x4A4000
#define CDisplay__ReloadUI_x                                       0x4B9800
#define CDisplay__WriteTextHD2_x                                   0x4AA740

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E1560

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8CF8D0
#define CEditWnd__GetCharIndexPt_x                                 0x8D0970
#define CEditWnd__GetDisplayString_x                               0x8CFA80
#define CEditWnd__GetHorzOffset_x                                  0x8CFDC0
#define CEditWnd__GetLineForPrintableChar_x                        0x8D0430
#define CEditWnd__GetSelStartPt_x                                  0x8D0C30
#define CEditWnd__GetSTMLSafeText_x                                0x8CFF60
#define CEditWnd__PointFromPrintableChar_x                         0x8D0520
#define CEditWnd__SelectableCharFromPoint_x                        0x8D06A0
#define CEditWnd__SetEditable_x                                    0x8CFF30

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
#define CGaugeWnd__CalcFillRect_x                                  0x6A1E90
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A1EF0
#define CGaugeWnd__Draw_x                                          0x6A2320

// CGuild
#define CGuild__FindMemberByName_x                                 0x435590

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6BEF20

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CCCC0
#define CInvSlotMgr__MoveItem_x                                    0x6CDC00
#define CInvSlotMgr__SelectSlot_x                                  0x6CCD70

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CC160
#define CInvSlot__SliderComplete_x                                 0x6C9B30
#define CInvSlot__GetItemBase_x                                    0x6C8FD0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6CED90

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x797290
#define CItemDisplayWnd__UpdateStrings_x                           0x6D00D0

// CLabel 
#define CLabel__Draw_x                                             0x6EAD80

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8A6D70
#define CListWnd__dCListWnd_x                                      0x8A7E00
#define CListWnd__AddColumn_x                                      0x8A7DA0
#define CListWnd__AddColumn1_x                                     0x8A7580
#define CListWnd__AddLine_x                                        0x8A7030
#define CListWnd__AddString_x                                      0x8A7240
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A40A0
#define CListWnd__CalculateVSBRange_x                              0x8A6220
#define CListWnd__ClearAllSel_x                                    0x8A3360
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8A6C00
#define CListWnd__Compare_x                                        0x8A4BA0
#define CListWnd__Draw_x                                           0x8A5E30
#define CListWnd__DrawColumnSeparators_x                           0x8A5CC0
#define CListWnd__DrawHeader_x                                     0x8A3670
#define CListWnd__DrawItem_x                                       0x8A51F0
#define CListWnd__DrawLine_x                                       0x8A5960
#define CListWnd__DrawSeparator_x                                  0x8A5D60
#define CListWnd__EnsureVisible_x                                  0x8A4200
#define CListWnd__ExtendSel_x                                      0x8A5100
#define CListWnd__GetColumnMinWidth_x                              0x8A2D80
#define CListWnd__GetColumnWidth_x                                 0x8A2CA0
#define CListWnd__GetCurSel_x                                      0x8A2480
#define CListWnd__GetItemAtPoint_x                                 0x8A44A0
#define CListWnd__GetItemAtPoint1_x                                0x8A4510
#define CListWnd__GetItemData_x                                    0x8A27B0
#define CListWnd__GetItemHeight_x                                  0x8A3D00
#define CListWnd__GetItemIcon_x                                    0x8A2990
#define CListWnd__GetItemRect_x                                    0x8A42E0
#define CListWnd__GetItemText_x                                    0x8A2840
#define CListWnd__GetSelList_x                                     0x8A7470
#define CListWnd__GetSeparatorRect_x                               0x8A4AD0
#define CListWnd__RemoveLine_x                                     0x8A7420
#define CListWnd__SetColors_x                                      0x8A25D0
#define CListWnd__SetColumnJustification_x                         0x8A3050
#define CListWnd__SetColumnWidth_x                                 0x8A2D30
#define CListWnd__SetCurSel_x                                      0x8A24C0
#define CListWnd__SetItemColor_x                                   0x8A68E0
#define CListWnd__SetItemData_x                                    0x8A3410
#define CListWnd__SetItemText_x                                    0x8A6720
#define CListWnd__ShiftColumnSeparator_x                           0x8A65B0
#define CListWnd__Sort_x                                           0x8A7F00
#define CListWnd__ToggleSel_x                                      0x8A32E0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x704200

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7253C0
#define CMerchantWnd__RequestBuyItem_x                             0x72C1C0
#define CMerchantWnd__RequestSellItem_x                            0x72CC10
#define CMerchantWnd__SelectRecoverySlot_x                         0x725670
#define CMerchantWnd__SelectBuySellSlot_x                          0x7248D0
#define CMerchantWnd__ActualSelect_x                               0x729100

// CObfuscator
#define CObfuscator__doit_x                                        0x821790

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8C6690
#define CSidlManager__CreateLabel_x                                0x78D2E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x64FE20
#define CSidlScreenWnd__CalculateVSBRange_x                        0x64FD00
#define CSidlScreenWnd__ConvertToRes_x                             0x8E1440
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8B0ED0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8B23B0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8B2460
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8B1920
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8B08A0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8AFFF0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8B0A90
#define CSidlScreenWnd__Init1_x                                    0x8B2080
#define CSidlScreenWnd__LoadIniInfo_x                              0x8B0F80
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8B01B0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8B1B70
#define CSidlScreenWnd__StoreIniInfo_x                             0x8AFAC0
#define CSidlScreenWnd__StoreIniVis_x                              0x8AFF80
#define CSidlScreenWnd__WndNotification_x                          0x8B1E00
#define CSidlScreenWnd__GetChildItem_x                             0x8B00C0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B6480

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5EB5B0
#define CSkillMgr__GetSkillCap_x                                   0x5EB750
#define CSkillMgr__GetNameToken_x                                  0x5EB220

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E0700
#define CSliderWnd__SetValue_x                                     0x8E08D0
#define CSliderWnd__SetNumTicks_x                                  0x8E1050

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x794F30

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8DB0E0
#define CStmlWnd__CalculateHSBRange_x                              0x8D36B0
#define CStmlWnd__CalculateVSBRange_x                              0x8D3620
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D3830
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D4110
#define CStmlWnd__ForceParseNow_x                                  0x8DBA30
#define CStmlWnd__GetNextTagPiece_x                                0x8D4010
#define CStmlWnd__GetSTMLText_x                                    0x686F30
#define CStmlWnd__GetVisibleText_x                                 0x8D4B60
#define CStmlWnd__InitializeWindowVariables_x                      0x8D6ED0
#define CStmlWnd__MakeStmlColorTag_x                               0x8D2920
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D2980
#define CStmlWnd__SetSTMLText_x                                    0x8D8730
#define CStmlWnd__StripFirstSTMLLines_x                            0x8DAD80
#define CStmlWnd__UpdateHistoryString_x                            0x8D5A90

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E2C40
#define CTabWnd__DrawCurrentPage_x                                 0x8E24B0
#define CTabWnd__DrawTab_x                                         0x8E2270
#define CTabWnd__GetCurrentPage_x                                  0x8E2880
#define CTabWnd__GetPageInnerRect_x                                0x8E1F60
#define CTabWnd__GetTabInnerRect_x                                 0x8E2160
#define CTabWnd__GetTabRect_x                                      0x8E2030
#define CTabWnd__InsertPage_x                                      0x8E2F30
#define CTabWnd__SetPage_x                                         0x8E28B0
#define CTabWnd__SetPageRect_x                                     0x8E2B80
#define CTabWnd__UpdatePage_x                                      0x8E2ED0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4312C0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BD4C0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8E7E00

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A0730

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402290
#define CXStr__CXStr1_x                                            0x4D8720
#define CXStr__CXStr3_x                                            0x857A60
#define CXStr__dCXStr_x                                            0x5EE290
#define CXStr__operator_equal_x                                    0x857BD0
#define CXStr__operator_equal1_x                                   0x857C20
#define CXStr__operator_plus_equal1_x                              0x858D00

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B5700
#define CXWnd__Center_x                                            0x8BB7A0
#define CXWnd__ClrFocus_x                                          0x8B52E0
#define CXWnd__DoAllDrawing_x                                      0x8BB3F0
#define CXWnd__DrawChildren_x                                      0x8BB590

#define CXWnd__DrawColoredRect_x                                   0x8B5AB0
#define CXWnd__DrawTooltip_x                                       0x8B5D50
#define CXWnd__DrawTooltipAtPoint_x                                0x8BA370
#define CXWnd__GetBorderFrame_x                                    0x8B6180
#define CXWnd__GetChildWndAt_x                                     0x8BC170
#define CXWnd__GetClientClipRect_x                                 0x8B5F60
#define CXWnd__GetScreenClipRect_x                                 0x8BAA70
#define CXWnd__GetScreenRect_x                                     0x8B6330
#define CXWnd__GetTooltipRect_x                                    0x8B5BE0
#define CXWnd__GetWindowTextA_x                                    0x4227F0
#define CXWnd__IsActive_x                                          0x8AABE0
#define CXWnd__IsDescendantOf_x                                    0x8B60D0
#define CXWnd__IsReallyVisible_x                                   0x8B93D0
#define CXWnd__IsType_x                                            0x8E4620
#define CXWnd__Move_x                                              0x8B8B40
#define CXWnd__Move1_x                                             0x8BB0B0
#define CXWnd__ProcessTransition_x                                 0x8B56B0
#define CXWnd__Refade_x                                            0x8B5480
#define CXWnd__Resize_x                                            0x8B63E0
#define CXWnd__Right_x                                             0x8BA870
#define CXWnd__SetFocus_x                                          0x8B7CB0
#define CXWnd__SetFont_x                                           0x8B5330
#define CXWnd__SetKeyTooltip_x                                     0x8B6650
#define CXWnd__SetMouseOver_x                                      0x8BADA0
#define CXWnd__StartFade_x                                         0x8B5750
#define CXWnd__GetChildItem_x                                      0x8BACE0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8AC4F0
#define CXWndManager__DrawWindows_x                                0x8AC130
#define CXWndManager__GetKeyboardFlags_x                           0x8AA750
#define CXWndManager__HandleKeyboardMsg_x                          0x8AB080
#define CXWndManager__RemoveWnd_x                                  0x8AAD70

// CDBStr
#define CDBStr__GetString_x                                        0x4A24A0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44D630
#define EQ_Character__Cur_HP_x                                     0x463390
#define EQ_Character__GetAACastingTimeModifier_x                   0x446710
#define EQ_Character__GetCharInfo2_x                               0x82BF90
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43E9F0
#define EQ_Character__GetFocusRangeModifier_x                      0x43EBD0
#define EQ_Character__Max_Endurance_x                              0x5B3F50
#define EQ_Character__Max_HP_x                                     0x459690
#define EQ_Character__Max_Mana_x                                   0x5B3D80
#define EQ_Character__doCombatAbility_x                            0x5B1380
#define EQ_Character__UseSkill_x                                   0x46DEB0
#define EQ_Character__GetConLevel_x                                0x5A6450
#define EQ_Character__IsExpansionFlag_x                            0x421D30
#define EQ_Character__TotalEffect_x                                0x44B740

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x586CE0
#define EQ_Item__CreateItemTagString_x                             0x80B470
#define EQ_Item__IsStackable_x                                     0x7FF560
#define EQ_Item__GetImageNum_x                                     0x802270

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C1CF0
#define EQ_LoadingS__Array_x                                       0xBA4D10

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B56E0
#define EQ_PC__GetAltAbilityIndex_x                                0x8144C0
#define EQ_PC__GetCombatAbility_x                                  0x814550
#define EQ_PC__GetCombatAbilityTimer_x                             0x814600
#define EQ_PC__GetItemTimerValue_x                                 0x5AF150
#define EQ_PC__HasLoreItem_x                                       0x5A97A0
#define EQ_PC__AlertInventoryChanged_x                             0x5A6420
#define EQ_PC__GetPcZoneClient_x                                   0x5CFAA0
#define EQ_PC__RemoveMyAffect_x                                    0x5AE660

// EQItemList 
#define EQItemList__EQItemList_x                                   0x504330
#define EQItemList__add_item_x                                     0x504270
#define EQItemList__delete_item_x                                  0x504730
#define EQItemList__FreeItemList_x                                 0x504630

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A1700

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BAB70
#define EQPlayer__dEQPlayer_x                                      0x5C3990
#define EQPlayer__DoAttack_x                                       0x5D5900
#define EQPlayer__EQPlayer_x                                       0x5C5DB0
#define EQPlayer__SetNameSpriteState_x                             0x5C0660
#define EQPlayer__SetNameSpriteTint_x                              0x5BBF40
#define EQPlayer__IsBodyType_j_x                                   0x915470
#define EQPlayer__IsTargetable_x                                   0x915D30
#define EQPlayer__CanSee_x                                         0x916250

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5CA0B0
#define EQPlayerManager__GetSpawnByName_x                          0x5CA510

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x58CE00
#define KeypressHandler__AttachKeyToEqCommand_x                    0x58CE40
#define KeypressHandler__ClearCommandStateArray_x                  0x58C9E0
#define KeypressHandler__HandleKeyDown_x                           0x58B340
#define KeypressHandler__HandleKeyUp_x                             0x58B660
#define KeypressHandler__SaveKeymapping_x                          0x58CAB0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FC5E0
#define MapViewMap__SaveEx_x                                       0x6FFEC0

#define PlayerPointManager__GetAltCurrency_x                       0x826F00

// StringTable 
#define StringTable__getString_x                                   0x821A30

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B3A00

//Doors
#define EQSwitch__UseSwitch_x                                      0x542930

//IconCache
#define IconCache__GetIcon_x                                       0x697670

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x68E4E0
#define CContainerMgr__CloseContainer_x                            0x68ED00

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x75D760

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x580080

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D4470
#define EQ_Spell__SpellAffects_x                                   0x4D4510
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D4540
#define CharacterZoneClient__CalcAffectChange_x                    0x447A30
#define CLootWnd__LootAll_x                                        0x6F1FB0
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A2D50
#define CTargetWnd__WndNotification_x                              0x7A2840

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7A7F20
