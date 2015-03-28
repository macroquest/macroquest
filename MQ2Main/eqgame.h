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
#define __ExpectedVersionDate                                     "Mar 26 2015"
#define __ExpectedVersionTime                                     "19:33:13"
#define __ActualVersionDate_x                                      0xA7B130
#define __ActualVersionTime_x                                      0xA7B13C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x592300
#define __MemChecker1_x                                            0x85A930
#define __MemChecker2_x                                            0x629DC0
#define __MemChecker3_x                                            0x629D10
#define __MemChecker4_x                                            0x7DEF30
#define __EncryptPad0_x                                            0xBF6978
#define __EncryptPad1_x                                            0xD7AC90
#define __EncryptPad2_x                                            0xC3F8F8
#define __EncryptPad3_x                                            0xC3F4F8
#define __EncryptPad4_x                                            0xD573B8
#define __AC1_x                                                    0x79C075
#define __AC2_x                                                    0x548367
#define __AC3_x                                                    0x55CB60
#define __AC4_x                                                    0x562FA0
#define __AC5_x                                                    0x56ED7E
#define __AC6_x                                                    0x572842
#define __AC7_x                                                    0x56944C
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
#define __do_loot_x                                                0x50FDF0
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
#define pinstCSidlManager_x                                        0x1796514
#define pinstCXWndManager_x                                        0x179650C
#define instDynamicZone_x                                          0xF9AEB8
#define pinstDZMember_x                                            0xF9AFC8
#define pinstDZTimerInfo_x                                         0xF9AFCC
#define pinstEQItemList_x                                          0xF8A730
#define instEQMisc_x                                               0xB97110
#define pinstEQSoundManager_x                                      0xEDB878
#define instExpeditionLeader_x                                     0xF9AF02
#define instExpeditionName_x                                       0xF9AF42
#define pinstGroup_x                                               0xF8BAA6
#define pinstImeManager_x                                          0x1796518
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
#define pinstCContextMenuManager_x                                 0x17964CC
#define pinstCVoiceMacroWnd_x                                      0x1021A10
#define pinstCHtmlWnd_x                                            0x1021B08
#define pinstIconCache_x                                           0x112F26C
#define pinstCTradeskillWnd_x                                      0x1134ED8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x527800
#define __ConvertItemTags_x                                        0x514A80
#define __ExecuteCmd_x                                             0x4FF420
#define __EQGetTime_x                                              0x85AC50
#define __get_melee_range_x                                        0x506110
#define __GetGaugeValueFromEQ_x                                    0x79ADC0
#define __GetLabelFromEQ_x                                         0x79C000
#define __ToggleMount_x                                            0x6C4540
#define __GetXTargetType_x                                         0x919180
#define __LoadFrontEnd_x                                           0x629470
#define __NewUIINI_x                                               0x79A6C0
#define __ProcessGameEvents_x                                      0x56B1B0
#define __ProcessMouseEvent_x                                      0x56A950
#define CrashDetected_x                                            0x62AF40
#define wwsCrashReportCheckForUploader_x                           0x7EFD50
#define DrawNetStatus_x                                            0x5A1EC0
#define Util__FastTime_x                                           0x85A7A0
#define Expansion_HoT_x                                            0xF9C3FC
#define __HelpPath_x                                               0x101FB60

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4BFF10
#define AltAdvManager__IsAbilityReady_x                            0x4BFF80
#define AltAdvManager__GetAltAbility_x                             0x4C0340

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x463F00
#define CharacterZoneClient__MakeMeVisible_x                       0x468FC0
// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x658D30

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x667240

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5812A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6820B0
#define CChatManager__InitContextMenu_x                            0x682BD0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8BB1A0
#define CContextMenu__dCContextMenu_x                              0x8BB3B0
#define CContextMenu__AddMenuItem_x                                0x8BB3C0
#define CContextMenu__RemoveMenuItem_x                             0x8BB6A0
#define CContextMenu__RemoveAllMenuItems_x                         0x8BB6C0
#define CContextMenuManager__AddMenu_x                             0x8BBA70
#define CContextMenuManager__RemoveMenu_x                          0x8BBDB0
#define CContextMenuManager__PopupMenu_x                           0x8BC200
#define CContextMenuManager__Flush_x                               0x8BBAE0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x841520
#define CChatService__GetFriendName_x                              0x841530

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x687C40
#define CChatWindow__Clear_x                                       0x6877F0
#define CChatWindow__WndNotification_x                             0x688180

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BA560
#define CComboWnd__Draw_x                                          0x8BA770
#define CComboWnd__GetCurChoice_x                                  0x8BA330
#define CComboWnd__GetListRect_x                                   0x8BAA10
#define CComboWnd__GetTextRect_x                                   0x8BA5D0
#define CComboWnd__InsertChoice_x                                  0x8BAA80
#define CComboWnd__SetColors_x                                     0x8BA2C0
#define CComboWnd__SetChoice_x                                     0x8BA2F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x691350
#define CContainerWnd__vftable_x                                   0xA84890

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4AE6B0
#define CDisplay__GetClickedActor_x                                0x4A7230
#define CDisplay__GetUserDefinedColor_x                            0x4A5AF0
#define CDisplay__GetWorldFilePath_x                               0x4A4F40
#define CDisplay__is3dON_x                                         0x4A4310
#define CDisplay__ReloadUI_x                                       0x4B9B20
#define CDisplay__WriteTextHD2_x                                   0x4AAA50

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8E1540

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8CF950
#define CEditWnd__GetCharIndexPt_x                                 0x8D09C0
#define CEditWnd__GetDisplayString_x                               0x8CFB00
#define CEditWnd__GetHorzOffset_x                                  0x8CFE40
#define CEditWnd__GetLineForPrintableChar_x                        0x8D04A0
#define CEditWnd__GetSelStartPt_x                                  0x8D0C70
#define CEditWnd__GetSTMLSafeText_x                                0x8CFFD0
#define CEditWnd__PointFromPrintableChar_x                         0x8D0590
#define CEditWnd__SelectableCharFromPoint_x                        0x8D0700
#define CEditWnd__SetEditable_x                                    0x8CFFA0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x548AB0
#define CEverQuest__DoTellWindow_x                                 0x54E4B0
#define CEverQuest__DropHeldItemOnGround_x                         0x556FE0
#define CEverQuest__dsp_chat_x                                     0x54FC50
#define CEverQuest__Emote_x                                        0x54FEB0
#define CEverQuest__EnterZone_x                                    0x5637C0
#define CEverQuest__GetBodyTypeDesc_x                              0x545310
#define CEverQuest__GetClassDesc_x                                 0x54B020
#define CEverQuest__GetClassThreeLetterCode_x                      0x54B620
#define CEverQuest__GetDeityDesc_x                                 0x545BF0
#define CEverQuest__GetLangDesc_x                                  0x5456A0
#define CEverQuest__GetRaceDesc_x                                  0x54B7E0
#define CEverQuest__InterpretCmd_x                                 0x550790
#define CEverQuest__LeftClickedOnPlayer_x                          0x5678B0
#define CEverQuest__LMouseUp_x                                     0x5699A0
#define CEverQuest__RightClickedOnPlayer_x                         0x5683B0
#define CEverQuest__RMouseUp_x                                     0x569400
#define CEverQuest__SetGameState_x                                 0x549160
#define CEverQuest__UPCNotificationFlush_x                         0x551930
#define CEverQuest__IssuePetCommand_x                              0x551490

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6A1EF0
#define CGaugeWnd__CalcLinesFillRect_x                             0x6A1F50
#define CGaugeWnd__Draw_x                                          0x6A2380

// CGuild
#define CGuild__FindMemberByName_x                                 0x4357C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6BEFA0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CCD90
#define CInvSlotMgr__MoveItem_x                                    0x6CDCD0
#define CInvSlotMgr__SelectSlot_x                                  0x6CCE40

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6CC230
#define CInvSlot__SliderComplete_x                                 0x6C9BF0
#define CInvSlot__GetItemBase_x                                    0x6C9060

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6CEE90

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7978B0
#define CItemDisplayWnd__UpdateStrings_x                           0x6D01C0

// CLabel 
#define CLabel__Draw_x                                             0x6EAEB0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8A6BA0
#define CListWnd__dCListWnd_x                                      0x8A7BC0
#define CListWnd__AddColumn_x                                      0x8A7B60
#define CListWnd__AddColumn1_x                                     0x8A73D0
#define CListWnd__AddLine_x                                        0x8A6E50
#define CListWnd__AddString_x                                      0x8A7060
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A3ED0
#define CListWnd__CalculateVSBRange_x                              0x8A6040
#define CListWnd__ClearAllSel_x                                    0x8A31A0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8A6A30
#define CListWnd__Compare_x                                        0x8A49D0
#define CListWnd__Draw_x                                           0x8A5C50
#define CListWnd__DrawColumnSeparators_x                           0x8A5AE0
#define CListWnd__DrawHeader_x                                     0x8A34B0
#define CListWnd__DrawItem_x                                       0x8A5020
#define CListWnd__DrawLine_x                                       0x8A5780
#define CListWnd__DrawSeparator_x                                  0x8A5B80
#define CListWnd__EnsureVisible_x                                  0x8A4030
#define CListWnd__ExtendSel_x                                      0x8A4F30
#define CListWnd__GetColumnMinWidth_x                              0x8A2B60
#define CListWnd__GetColumnWidth_x                                 0x8A2A80
#define CListWnd__GetCurSel_x                                      0x8A2240
#define CListWnd__GetItemAtPoint_x                                 0x8A42C0
#define CListWnd__GetItemAtPoint1_x                                0x8A4330
#define CListWnd__GetItemData_x                                    0x8A2590
#define CListWnd__GetItemHeight_x                                  0x8A3B40
#define CListWnd__GetItemIcon_x                                    0x8A2770
#define CListWnd__GetItemRect_x                                    0x8A4100
#define CListWnd__GetItemText_x                                    0x8A2620
#define CListWnd__GetSelList_x                                     0x8A72C0
#define CListWnd__GetSeparatorRect_x                               0x8A48F0
#define CListWnd__RemoveLine_x                                     0x8A7240
#define CListWnd__SetColors_x                                      0x8A2390
#define CListWnd__SetColumnJustification_x                         0x8A2E30
#define CListWnd__SetColumnWidth_x                                 0x8A2B10
#define CListWnd__SetCurSel_x                                      0x8A2280
#define CListWnd__SetItemColor_x                                   0x8A6710
#define CListWnd__SetItemData_x                                    0x8A3250
#define CListWnd__SetItemText_x                                    0x8A6540
#define CListWnd__ShiftColumnSeparator_x                           0x8A63D0
#define CListWnd__Sort_x                                           0x8A7CC0
#define CListWnd__ToggleSel_x                                      0x8A3120

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x704560

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x725660
#define CMerchantWnd__RequestBuyItem_x                             0x72C4D0
#define CMerchantWnd__RequestSellItem_x                            0x72CF40
#define CMerchantWnd__SelectRecoverySlot_x                         0x725910
#define CMerchantWnd__SelectBuySellSlot_x                          0x724B70
#define CMerchantWnd__ActualSelect_x                               0x7293F0

// CObfuscator
#define CObfuscator__doit_x                                        0x821690

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8C6780
#define CSidlManager__CreateLabel_x                                0x78D850

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x64FF80
#define CSidlScreenWnd__CalculateVSBRange_x                        0x64FD80
#define CSidlScreenWnd__ConvertToRes_x                             0x8E1420
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8BE560
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8BFA70
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8BFB20
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8BEFE0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8BDF30
#define CSidlScreenWnd__EnableIniStorage_x                         0x8BD670
#define CSidlScreenWnd__GetSidlPiece_x                             0x8BE120
#define CSidlScreenWnd__Init1_x                                    0x8BF750
#define CSidlScreenWnd__LoadIniInfo_x                              0x8BE610
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8BD830
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8BF230
#define CSidlScreenWnd__StoreIniInfo_x                             0x8BD130
#define CSidlScreenWnd__StoreIniVis_x                              0x8BD600
#define CSidlScreenWnd__WndNotification_x                          0x8BF4D0
#define CSidlScreenWnd__GetChildItem_x                             0x8BD740
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B02D0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5EB3B0
#define CSkillMgr__GetSkillCap_x                                   0x5EB550
#define CSkillMgr__GetNameToken_x                                  0x5EB020

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8E06F0
#define CSliderWnd__SetValue_x                                     0x8E08C0
#define CSliderWnd__SetNumTicks_x                                  0x8E1040

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x795550

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8DB0F0
#define CStmlWnd__CalculateHSBRange_x                              0x8D3630
#define CStmlWnd__CalculateVSBRange_x                              0x8D36C0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D3840
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D4120
#define CStmlWnd__ForceParseNow_x                                  0x8DBA40
#define CStmlWnd__GetNextTagPiece_x                                0x8D4020
#define CStmlWnd__GetSTMLText_x                                    0x687090
#define CStmlWnd__GetVisibleText_x                                 0x8D4B70
#define CStmlWnd__InitializeWindowVariables_x                      0x8D6F00
#define CStmlWnd__MakeStmlColorTag_x                               0x8D2930
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D2990
#define CStmlWnd__SetSTMLText_x                                    0x8D8760
#define CStmlWnd__StripFirstSTMLLines_x                            0x8DAD90
#define CStmlWnd__UpdateHistoryString_x                            0x8D5AB0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E2CD0
#define CTabWnd__DrawCurrentPage_x                                 0x8E2540
#define CTabWnd__DrawTab_x                                         0x8E2310
#define CTabWnd__GetCurrentPage_x                                  0x8E2910
#define CTabWnd__GetPageInnerRect_x                                0x8E2000
#define CTabWnd__GetTabInnerRect_x                                 0x8E2200
#define CTabWnd__GetTabRect_x                                      0x8E20D0
#define CTabWnd__InsertPage_x                                      0x8E2FC0
#define CTabWnd__SetPage_x                                         0x8E2940
#define CTabWnd__SetPageRect_x                                     0x8E2C10
#define CTabWnd__UpdatePage_x                                      0x8E2F60

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431590

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B9F30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8E7E60

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8A03E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x402290
#define CXStr__CXStr1_x                                            0x43FFD0
#define CXStr__CXStr3_x                                            0x857830
#define CXStr__dCXStr_x                                            0x49BD10
#define CXStr__operator_equal_x                                    0x8579A0
#define CXStr__operator_equal1_x                                   0x8579F0
#define CXStr__operator_plus_equal1_x                              0x858AD0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8AF4C0
#define CXWnd__Center_x                                            0x8B5730
#define CXWnd__ClrFocus_x                                          0x8AF0B0
#define CXWnd__DoAllDrawing_x                                      0x8B5360
#define CXWnd__DrawChildren_x                                      0x8B5510
#define CXWnd__DrawColoredRect_x                                   0x8AF880
#define CXWnd__DrawTooltip_x                                       0x8AFB30
#define CXWnd__DrawTooltipAtPoint_x                                0x8B42B0
#define CXWnd__GetBorderFrame_x                                    0x8AFFA0
#define CXWnd__GetChildWndAt_x                                     0x8B60F0
#define CXWnd__GetClientClipRect_x                                 0x8AFD50
#define CXWnd__GetScreenClipRect_x                                 0x8B49A0
#define CXWnd__GetScreenRect_x                                     0x8B0170
#define CXWnd__GetTooltipRect_x                                    0x8AF9C0
#define CXWnd__GetWindowTextA_x                                    0x422B00
#define CXWnd__IsActive_x                                          0x8AAA10
#define CXWnd__IsDescendantOf_x                                    0x8AFEE0
#define CXWnd__IsReallyVisible_x                                   0x8B32C0
#define CXWnd__IsType_x                                            0x8E4640
#define CXWnd__Move_x                                              0x8B29A0
#define CXWnd__Move1_x                                             0x8B5000
#define CXWnd__ProcessTransition_x                                 0x8AF470
#define CXWnd__Refade_x                                            0x8AF250
#define CXWnd__Resize_x                                            0x8B0240
#define CXWnd__Right_x                                             0x8B47A0
#define CXWnd__SetFocus_x                                          0x8B1AF0
#define CXWnd__SetFont_x                                           0x8AF100
#define CXWnd__SetKeyTooltip_x                                     0x8B04A0
#define CXWnd__SetMouseOver_x                                      0x8B4CF0
#define CXWnd__StartFade_x                                         0x8AF510
#define CXWnd__GetChildItem_x                                      0x8B4C30

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8AC330
#define CXWndManager__DrawWindows_x                                0x8ABF70
#define CXWndManager__GetKeyboardFlags_x                           0x8AA540
#define CXWndManager__HandleKeyboardMsg_x                          0x8AAEB0
#define CXWndManager__RemoveWnd_x                                  0x8AABA0

// CDBStr
#define CDBStr__GetString_x                                        0x4A2780

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44D840
#define EQ_Character__Cur_HP_x                                     0x4635D0
#define EQ_Character__GetAACastingTimeModifier_x                   0x446900
#define EQ_Character__GetCharInfo2_x                               0x82BF10
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43EBE0
#define EQ_Character__GetFocusRangeModifier_x                      0x43EDC0
#define EQ_Character__Max_Endurance_x                              0x5B3C70
#define EQ_Character__Max_HP_x                                     0x4598C0
#define EQ_Character__Max_Mana_x                                   0x5B3AA0
#define EQ_Character__doCombatAbility_x                            0x5B1090
#define EQ_Character__UseSkill_x                                   0x46E100
#define EQ_Character__GetConLevel_x                                0x5A6500
#define EQ_Character__IsExpansionFlag_x                            0x422040
#define EQ_Character__TotalEffect_x                                0x44B960

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x586AE0
#define EQ_Item__CreateItemTagString_x                             0x80B460
#define EQ_Item__IsStackable_x                                     0x7FF950
#define EQ_Item__GetImageNum_x                                     0x802640

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C2000
#define EQ_LoadingS__Array_x                                       0xBA4D10

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B5410
#define EQ_PC__GetAltAbilityIndex_x                                0x8143E0
#define EQ_PC__GetCombatAbility_x                                  0x814470
#define EQ_PC__GetCombatAbilityTimer_x                             0x814520
#define EQ_PC__GetItemTimerValue_x                                 0x5AEE60
#define EQ_PC__HasLoreItem_x                                       0x5A9840
#define EQ_PC__AlertInventoryChanged_x                             0x5A64D0
#define EQ_PC__GetPcZoneClient_x                                   0x5CF840
#define EQ_PC__RemoveMyAffect_x									   0x5AE370

// EQItemList 
#define EQItemList__EQItemList_x                                   0x504110
#define EQItemList__add_item_x                                     0x504050
#define EQItemList__delete_item_x                                  0x504510
#define EQItemList__FreeItemList_x                                 0x504410

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A1A20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5BA880
#define EQPlayer__dEQPlayer_x                                      0x5C36A0
#define EQPlayer__DoAttack_x                                       0x5D56B0
#define EQPlayer__EQPlayer_x                                       0x5C5AC0
#define EQPlayer__SetNameSpriteState_x                             0x5C0370
#define EQPlayer__SetNameSpriteTint_x                              0x5BBC50
#define EQPlayer__IsBodyType_j_x                                   0x915400
#define EQPlayer__IsTargetable_x                                   0x915CC0
#define EQPlayer__CanSee_x                                         0x9161E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5C9DB0
#define EQPlayerManager__GetSpawnByName_x                          0x5CA210

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x58CD10
#define KeypressHandler__AttachKeyToEqCommand_x                    0x58CD50
#define KeypressHandler__ClearCommandStateArray_x                  0x58C8F0
#define KeypressHandler__HandleKeyDown_x                           0x58B250
#define KeypressHandler__HandleKeyUp_x                             0x58B570
#define KeypressHandler__SaveKeymapping_x                          0x58C9C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FC940
#define MapViewMap__SaveEx_x                                       0x700220

#define PlayerPointManager__GetAltCurrency_x                       0x826EB0

// StringTable 
#define StringTable__getString_x                                   0x821930

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B3720

//Doors
#define EQSwitch__UseSwitch_x                                      0x5426D0

//IconCache
#define IconCache__GetIcon_x                                       0x6977F0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x68E660
#define CContainerMgr__CloseContainer_x                            0x68EE80

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x75DA30

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x57FD60

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D4910
#define EQ_Spell__SpellAffects_x                                   0x4D49B0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D49E0
#define CharacterZoneClient__CalcAffectChange_x                    0x447C20
#define CLootWnd__LootAll_x                                        0x6F2250

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A33A0
#define CTargetWnd__WndNotification_x                              0x7A2E90

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7A8560
