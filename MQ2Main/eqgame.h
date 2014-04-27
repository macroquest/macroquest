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
#define __ExpectedVersionDate                                     "Apr  3 2014"
#define __ExpectedVersionTime                                     "16:37:33"
#define __ActualVersionDate_x                                      0xA3A3C0
#define __ActualVersionTime_x                                      0xA3A3CC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x56F990
#define __MemChecker1_x                                            0x82E0D0
#define __MemChecker2_x                                            0x605CB0
#define __MemChecker3_x                                            0x605C00
#define __MemChecker4_x                                            0x7B3350
#define __EncryptPad0_x                                            0xBA1910
#define __EncryptPad1_x                                            0xD17E28
#define __EncryptPad2_x                                            0xBE8020
#define __EncryptPad3_x                                            0xBE7C20
#define __EncryptPad4_x                                            0xCF5EB8
#define __AC1_x                                                    0x7711E5
#define __AC2_x                                                    0x526477
#define __AC3_x                                                    0x53A950
#define __AC4_x                                                    0x540A80
#define __AC5_x                                                    0x54D07B
#define __AC6_x                                                    0x550B62
#define __AC7_x                                                    0x546B4C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10C6570
#define DI8__Keyboard_x                                            0x10C6574
#define DI8__Mouse_x                                               0x10C6578
#define __AltTimerReady_x                                          0xF26331
#define __Attack_x                                                 0xFB9116
#define __Autofire_x                                               0xFB9117
#define __BindList_x                                               0xB66418
#define __Clicks_x                                                 0xF34F70
#define __CommandList_x                                            0xB6A488
#define __CurrentMapLabel_x                                        0x10CC1F0
#define __CurrentSocial_x                                          0xB2C8C0
#define __DoAbilityList_x                                          0xF6B6C4
#define __do_loot_x                                                0x4EEF60
#define __DrawHandler_x                                            0x172E754
#define __GroupCount_x                                             0xF25A0A

#define __Guilds_x                                                 0xF2B4F0
#define __gWorld_x                                                 0xF27EC4
#define __HotkeyPage_x                                             0xFB20C4
#define __HWnd_x                                                   0xFBE478
#define __InChatMode_x                                             0xF34E9C
#define __LastTell_x                                               0xF36DCC
#define __LMouseHeldTime_x                                         0xF34FDC
#define __Mouse_x                                                  0x10C657C
#define __MouseLook_x                                              0xF34F36
#define __MouseEventTime_x                                         0xFB9904
#define __NetStatusToggle_x                                        0xF34F39
#define __PCNames_x                                                0xF3640C
#define __RangeAttackReady_x                                       0xF360A8
#define __RMouseHeldTime_x                                         0xF34FD8
#define __RunWalkState_x                                           0xF34EA0
#define __ScreenMode_x                                             0xE74410
#define __ScreenX_x                                                0xF34E54
#define __ScreenY_x                                                0xF34E50
#define __ScreenXMax_x                                             0xF34E58
#define __ScreenYMax_x                                             0xF34E5C
#define __ServerHost_x                                             0xF25954
#define __ServerName_x                                             0xF6B684
#define __ShiftKeyDown_x                                           0xF3553C
#define __ShowNames_x                                              0xF362B0
#define __Socials_x                                                0xF6B784
#define __SubscriptionType_x                                       0x10F5F20
#define __TargetAggroHolder_x                                      0x10CE408
#define __GroupAggro_x                                             0x10CE448
#define __LoginName_x                                              0xFBD050
#define __Inviter_x                                                0xFB9094


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF27FA8
#define instEQZoneInfo_x                                           0xF3512C
#define instKeypressHandler_x                                      0xFB98E8
#define pinstActiveBanker_x                                        0xF27F68
#define pinstActiveCorpse_x                                        0xF27F6C
#define pinstActiveGMaster_x                                       0xF27F70
#define pinstActiveMerchant_x                                      0xF27F64
#define pinstAggroInfo_x                                           0xD389F8
#define pinstAltAdvManager_x                                       0xE754D8
#define pinstAuraMgr_x                                             0xD428C0
#define pinstBandageTarget_x                                       0xF27F50
#define pinstCamActor_x                                            0xE74DE4
#define pinstCDBStr_x                                              0xE743A4
#define pinstCDisplay_x                                            0xF27F78
#define pinstCEverQuest_x                                          0x10C66F4
#define pinstCharData_x                                            0xF27F34
#define pinstCharSpawn_x                                           0xF27F5C
#define pinstControlledMissile_x                                   0xF27F30
#define pinstControlledPlayer_x                                    0xF27F5C
#define pinstCSidlManager_x                                        0x172DBC0
#define pinstCXWndManager_x                                        0x172DBB8
#define instDynamicZone_x                                          0xF34CE8
#define pinstDZMember_x                                            0xF34DF8
#define pinstDZTimerInfo_x                                         0xF34DFC
#define pinstEQItemList_x                                          0xF2468C
#define instEQMisc_x                                               0xB47D80
#define pinstEQSoundManager_x                                      0xE757D8
#define instExpeditionLeader_x                                     0xF34D32
#define instExpeditionName_x                                       0xF34D72
#define pinstGroup_x                                               0xF25A06
#define pinstImeManager_x                                          0x172DBC4
#define pinstLocalPlayer_x                                         0xF27F48
#define pinstMercenaryData_x                                       0xFB9F38
#define pinstMercAltAbilities_x                                    0xE756F8
#define pinstModelPlayer_x                                         0xF27F74
#define pinstPCData_x                                              0xF27F34
#define pinstSkillMgr_x                                            0xFBAD70
#define pinstSpawnManager_x                                        0xFBA658
#define pinstSpellManager_x                                        0xFBAEB8
#define pinstSpellSets_x                                           0xFB2128
#define pinstStringTable_x                                         0xF27EDC
#define pinstSwitchManager_x                                       0xF25598
#define pinstTarget_x                                              0xF27F60
#define pinstTargetObject_x                                        0xF27F38
#define pinstTargetSwitch_x                                        0xF27F3C
#define pinstTaskMember_x                                          0xE742F0
#define pinstTrackTarget_x                                         0xF27F54
#define pinstTradeTarget_x                                         0xF27F44
#define instTributeActive_x                                        0xB47DA5
#define pinstViewActor_x                                           0xE74DE0
#define pinstWorldData_x                                           0xF27F18


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD38ED8
#define pinstCAudioTriggersWindow_x                                0xD38D68
#define pinstCCharacterSelect_x                                    0xE74C8C
#define pinstCFacePick_x                                           0xE74A3C
#define pinstCNoteWnd_x                                            0xE74C44
#define pinstCBookWnd_x                                            0xE74C4C
#define pinstCPetInfoWnd_x                                         0xE74C50
#define pinstCTrainWnd_x                                           0xE74C54
#define pinstCSkillsWnd_x                                          0xE74C58
#define pinstCSkillsSelectWnd_x                                    0xE74C5C
#define pinstCCombatSkillSelectWnd_x                               0xE74C60
#define pinstCFriendsWnd_x                                         0xE74C64
#define pinstCAuraWnd_x                                            0xE74C68
#define pinstCRespawnWnd_x                                         0xE74C6C
#define pinstCBandolierWnd_x                                       0xE74C70
#define pinstCPotionBeltWnd_x                                      0xE74C74
#define pinstCAAWnd_x                                              0xE74C78
#define pinstCGroupSearchFiltersWnd_x                              0xE74C7C
#define pinstCLoadskinWnd_x                                        0xE74C80
#define pinstCAlarmWnd_x                                           0xE74C84
#define pinstCMusicPlayerWnd_x                                     0xE74C88
#define pinstCMailWnd_x                                            0xE74C90
#define pinstCMailCompositionWnd_x                                 0xE74C94
#define pinstCMailAddressBookWnd_x                                 0xE74C98
#define pinstCRaidWnd_x                                            0xE74CA0
#define pinstCRaidOptionsWnd_x                                     0xE74CA4
#define pinstCBreathWnd_x                                          0xE74CA8
#define pinstCMapViewWnd_x                                         0xE74CAC
#define pinstCMapToolbarWnd_x                                      0xE74CB0
#define pinstCEditLabelWnd_x                                       0xE74CB4
#define pinstCTargetWnd_x                                          0xE74CB8
#define pinstCColorPickerWnd_x                                     0xE74CBC
#define pinstCPlayerWnd_x                                          0xE74CC0
#define pinstCOptionsWnd_x                                         0xE74CC4
#define pinstCBuffWindowNORMAL_x                                   0xE74CC8
#define pinstCBuffWindowSHORT_x                                    0xE74CCC
#define pinstCharacterCreation_x                                   0xE74CD0
#define pinstCCursorAttachment_x                                   0xE74CD4
#define pinstCCastingWnd_x                                         0xE74CD8
#define pinstCCastSpellWnd_x                                       0xE74CDC
#define pinstCSpellBookWnd_x                                       0xE74CE0
#define pinstCInventoryWnd_x                                       0xE74CE4
#define pinstCBankWnd_x                                            0xE74CE8
#define pinstCQuantityWnd_x                                        0xE74CEC
#define pinstCLootWnd_x                                            0xE74CF0
#define pinstCActionsWnd_x                                         0xE74CF4
#define pinstCCombatAbilityWnd_x                                   0xE74CF8
#define pinstCMerchantWnd_x                                        0xE74CFC
#define pinstCTradeWnd_x                                           0xE74D00
#define pinstCSelectorWnd_x                                        0xE74D04
#define pinstCBazaarWnd_x                                          0xE74D08
#define pinstCBazaarSearchWnd_x                                    0xE74D0C
#define pinstCGiveWnd_x                                            0xE74D28
#define pinstCTrackingWnd_x                                        0xE74D30
#define pinstCInspectWnd_x                                         0xE74D34
#define pinstCSocialEditWnd_x                                      0xE74D38
#define pinstCFeedbackWnd_x                                        0xE74D3C
#define pinstCBugReportWnd_x                                       0xE74D40
#define pinstCVideoModesWnd_x                                      0xE74D44
#define pinstCTextEntryWnd_x                                       0xE74D4C
#define pinstCFileSelectionWnd_x                                   0xE74D50
#define pinstCCompassWnd_x                                         0xE74D54
#define pinstCPlayerNotesWnd_x                                     0xE74D58
#define pinstCGemsGameWnd_x                                        0xE74D5C
#define pinstCTimeLeftWnd_x                                        0xE74D60
#define pinstCPetitionQWnd_x                                       0xE74D74
#define pinstCSoulmarkWnd_x                                        0xE74D78
#define pinstCStoryWnd_x                                           0xE74D7C
#define pinstCJournalTextWnd_x                                     0xE74D80
#define pinstCJournalCatWnd_x                                      0xE74D84
#define pinstCBodyTintWnd_x                                        0xE74D88
#define pinstCServerListWnd_x                                      0xE74D8C
#define pinstCAvaZoneWnd_x                                         0xE74D98
#define pinstCBlockedBuffWnd_x                                     0xE74D9C
#define pinstCBlockedPetBuffWnd_x                                  0xE74DA0
#define pinstCInvSlotMgr_x                                         0xE74DD8
#define pinstCContainerMgr_x                                       0xE74DDC
#define pinstCAdventureLeaderboardWnd_x                            0x10C72C8
#define pinstCAdventureRequestWnd_x                                0x10C7340
#define pinstCAltStorageWnd_x                                      0x10C7620
#define pinstCAdventureStatsWnd_x                                  0x10C73B8
#define pinstCBarterMerchantWnd_x                                  0x10C8208
#define pinstCBarterSearchWnd_x                                    0x10C8280
#define pinstCBarterWnd_x                                          0x10C82F8
#define pinstCChatManager_x                                        0x10C8988
#define pinstCDynamicZoneWnd_x                                     0x10C8E38
#define pinstCEQMainWnd_x                                          0x10C8FD0
#define pinstCFellowshipWnd_x                                      0x10C8DCC
#define pinstCFindLocationWnd_x                                    0x10C92A0
#define pinstCGroupSearchWnd_x                                     0x10C9570
#define pinstCGroupWnd_x                                           0x10C95E8
#define pinstCGuildBankWnd_x                                       0x10C9660
#define pinstCGuildMgmtWnd_x                                       0x10CB750
#define pinstCHotButtonWnd_x                                       0x10CB81C
#define pinstCHotButtonWnd1_x                                      0x10CB81C
#define pinstCHotButtonWnd2_x                                      0x10CB820
#define pinstCHotButtonWnd3_x                                      0x10CB824
#define pinstCHotButtonWnd4_x                                      0x10CB848
#define pinstCItemDisplayManager_x                                 0x10CBB40
#define pinstCItemExpTransferWnd_x                                 0x10CBBBC
#define pinstCLFGuildWnd_x                                         0x10CBE98
#define pinstCMIZoneSelectWnd_x                                    0x10CC480
#define pinstCConfirmationDialog_x                                 0x10CCB88
#define pinstCPopupWndManager_x                                    0x10CCB88
#define pinstCProgressionSelectionWnd_x                            0x10CCC78
#define pinstCPvPStatsWnd_x                                        0x10CCD68
#define pinstCSystemInfoDialogBox_x                                0x10CD470
#define pinstCTaskWnd_x                                            0x10CE800
#define pinstCTaskTemplateSelectWnd_x                              0x10CE788
#define pinstCTipWndOFDAY_x                                        0x10CEA58
#define pinstCTipWndCONTEXT_x                                      0x10CEA5C
#define pinstCTitleWnd_x                                           0x10CEAD8
#define pinstCContextMenuManager_x                                 0x172D7D4
#define pinstCVoiceMacroWnd_x                                      0xFBB520
#define pinstCHtmlWnd_x                                            0xFBB618
#define pinstIconCache_x                                           0x10C8FA4
#define pinstCTradeskillWnd_x                                      0x10CEBD8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x505B10
#define __ConvertItemTags_x                                        0x4F3C70
#define __ExecuteCmd_x                                             0x4DEB80
#define __EQGetTime_x                                              0x82EC30
#define __get_melee_range_x                                        0x4E57C0
#define __GetGaugeValueFromEQ_x                                    0x76FF40
#define __GetLabelFromEQ_x                                         0x771170
#define __GetXTargetType_x                                         0x8EB070
#define __LoadFrontEnd_x                                           0x605360
#define __NewUIINI_x                                               0x76F870
#define __ProcessGameEvents_x                                      0x548C90
#define CrashDetected_x                                            0x606E20
#define DrawNetStatus_x                                            0x57EF70
#define Util__FastTime_x                                           0x82DF70
#define Expansion_HoT_x                                            0xF36210
#define __HelpPath_x                                               0xFB9670
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A4C90
#define AltAdvManager__IsAbilityReady_x                            0x4A4D00
#define AltAdvManager__GetAltAbility_x                             0x4A50C0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x451E50

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x634D80

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x643310

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x55F2F0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x65DED0
#define CChatManager__InitContextMenu_x                            0x65E9F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x814D40
#define CChatService__GetFriendName_x                              0x814D50

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x663730
#define CChatWindow__Clear_x                                       0x6632E0
#define CChatWindow__WndNotification_x                             0x663C60

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x88CFB0
#define CComboWnd__Draw_x                                          0x88D190
#define CComboWnd__GetCurChoice_x                                  0x88CDD0
#define CComboWnd__GetListRect_x                                   0x88D430
#define CComboWnd__GetTextRect_x                                   0x88D010
#define CComboWnd__InsertChoice_x                                  0x88D4A0
#define CComboWnd__SetColors_x                                     0x88CD60
#define CComboWnd__SetChoice_x                                     0x88CD90

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x66CE00
#define CContainerWnd__vftable_x                                   0xA43B48

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x493610
#define CDisplay__GetClickedActor_x                                0x48C250
#define CDisplay__GetUserDefinedColor_x                            0x48AB10
#define CDisplay__GetWorldFilePath_x                               0x489F10
#define CDisplay__is3dON_x                                         0x4892E0
#define CDisplay__ReloadUI_x                                       0x49E9E0
#define CDisplay__WriteTextHD2_x                                   0x48FA90

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8AE970

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x89D8D0
#define CEditWnd__GetCharIndexPt_x                                 0x89E900
#define CEditWnd__GetDisplayString_x                               0x89DA80
#define CEditWnd__GetHorzOffset_x                                  0x89DDC0
#define CEditWnd__GetLineForPrintableChar_x                        0x89E3C0
#define CEditWnd__GetSelStartPt_x                                  0x89EBC0
#define CEditWnd__GetSTMLSafeText_x                                0x89DF60
#define CEditWnd__PointFromPrintableChar_x                         0x89E4B0
#define CEditWnd__SelectableCharFromPoint_x                        0x89E630
#define CEditWnd__SetEditable_x                                    0x89DF30

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x526BC0
#define CEverQuest__DoTellWindow_x                                 0x52C330
#define CEverQuest__DropHeldItemOnGround_x                         0x534DD0
#define CEverQuest__dsp_chat_x                                     0x52DAD0
#define CEverQuest__Emote_x                                        0x52DD30
#define CEverQuest__EnterZone_x                                    0x540C10
#define CEverQuest__GetBodyTypeDesc_x                              0x523580
#define CEverQuest__GetClassDesc_x                                 0x528EA0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5294A0
#define CEverQuest__GetDeityDesc_x                                 0x523E60
#define CEverQuest__GetLangDesc_x                                  0x523910
#define CEverQuest__GetRaceDesc_x                                  0x529660
#define CEverQuest__InterpretCmd_x                                 0x52E610
#define CEverQuest__LeftClickedOnPlayer_x                          0x544FC0
#define CEverQuest__LMouseUp_x                                     0x5472B0
#define CEverQuest__RightClickedOnPlayer_x                         0x545AC0
#define CEverQuest__RMouseUp_x                                     0x546B00
#define CEverQuest__SetGameState_x                                 0x527270
#define CEverQuest__UPCNotificationFlush_x                         0x52F7B0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x67D9A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x67DA00
#define CGaugeWnd__Draw_x                                          0x67DE30

// CGuild
#define CGuild__FindMemberByName_x                                 0x423F30

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69A170

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6A5F20
#define CInvSlotMgr__MoveItem_x                                    0x6A6E60
#define CInvSlotMgr__SelectSlot_x                                  0x6A5FD0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6A5250
#define CInvSlot__SliderComplete_x                                 0x6A30A0
#define CInvSlot__GetItemBase_x                                    0x6A2500

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6A7C30

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x76CB70
#define CItemDisplayWnd__UpdateStrings_x                           0x6A8F90

// CLabel 
#define CLabel__Draw_x                                             0x6C3A60

// CListWnd 
#define CListWnd__AddColumn_x                                      0x87B070
#define CListWnd__AddColumn1_x                                     0x87A860
#define CListWnd__AddLine_x                                        0x87A310
#define CListWnd__AddString_x                                      0x87A520
#define CListWnd__CalculateFirstVisibleLine_x                      0x8773C0
#define CListWnd__CalculateVSBRange_x                              0x879500
#define CListWnd__ClearAllSel_x                                    0x876670
#define CListWnd__CloseAndUpdateEditWindow_x                       0x879EE0
#define CListWnd__Compare_x                                        0x877ED0
#define CListWnd__Draw_x                                           0x879160
#define CListWnd__DrawColumnSeparators_x                           0x878FF0
#define CListWnd__DrawHeader_x                                     0x876980
#define CListWnd__DrawItem_x                                       0x878520
#define CListWnd__DrawLine_x                                       0x878C90
#define CListWnd__DrawSeparator_x                                  0x879090
#define CListWnd__EnsureVisible_x                                  0x877520
#define CListWnd__ExtendSel_x                                      0x878430
#define CListWnd__GetColumnMinWidth_x                              0x876090
#define CListWnd__GetColumnWidth_x                                 0x875FB0
#define CListWnd__GetCurSel_x                                      0x875890
#define CListWnd__GetItemAtPoint_x                                 0x8777C0
#define CListWnd__GetItemAtPoint1_x                                0x877830
#define CListWnd__GetItemData_x                                    0x875AC0
#define CListWnd__GetItemHeight_x                                  0x877010
#define CListWnd__GetItemIcon_x                                    0x875CA0
#define CListWnd__GetItemRect_x                                    0x877600
#define CListWnd__GetItemText_x                                    0x875B50
#define CListWnd__GetSelList_x                                     0x87A750
#define CListWnd__GetSeparatorRect_x                               0x877DF0
#define CListWnd__RemoveLine_x                                     0x87A700
#define CListWnd__SetColors_x                                      0x8758F0
#define CListWnd__SetColumnJustification_x                         0x876360
#define CListWnd__SetColumnWidth_x                                 0x876040
#define CListWnd__SetCurSel_x                                      0x8758D0
#define CListWnd__SetItemColor_x                                   0x879BC0
#define CListWnd__SetItemData_x                                    0x876720
#define CListWnd__SetItemText_x                                    0x879A00
#define CListWnd__ShiftColumnSeparator_x                           0x879890
#define CListWnd__Sort_x                                           0x87B1DD
#define CListWnd__ToggleSel_x                                      0x8765F0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6DCCF0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6FCC00
#define CMerchantWnd__RequestBuyItem_x                             0x703190
#define CMerchantWnd__RequestSellItem_x                            0x72A540
#define CMerchantWnd__SelectRecoverySlot_x                         0x6FCEB0
#define CMerchantWnd__SelectBuySellSlot_x                          0x6FC0C0
#define CMerchantWnd__ActualSelect_x                               0x700610

// CObfuscator
#define CObfuscator__doit_x                                        0x7F5840

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x892720
#define CSidlManager__CreateLabel_x                                0x762F80

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x62BF50
#define CSidlScreenWnd__CalculateVSBRange_x                        0x62BE70
#define CSidlScreenWnd__ConvertToRes_x                             0x8AE850
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8801A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x881690
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x881740
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x880C00
#define CSidlScreenWnd__DrawSidlPiece_x                            0x87FC80
#define CSidlScreenWnd__EnableIniStorage_x                         0x87F3B0
#define CSidlScreenWnd__GetSidlPiece_x                             0x87FE70
#define CSidlScreenWnd__Init1_x                                    0x881360
#define CSidlScreenWnd__LoadIniInfo_x                              0x880250
#define CSidlScreenWnd__LoadIniListWnd_x                           0x87F570
#define CSidlScreenWnd__LoadSidlScreen_x                           0x880E50
#define CSidlScreenWnd__StoreIniInfo_x                             0x87EE80
#define CSidlScreenWnd__StoreIniVis_x                              0x87F340
#define CSidlScreenWnd__WndNotification_x                          0x8810E0
#define CSidlScreenWnd__GetChildItem_x                             0x87F480
#define CSidlScreenWnd__HandleLButtonUp_x                          0x886020

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5C7400
#define CSkillMgr__GetSkillCap_x                                   0x5C75A0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8B8910
#define CSliderWnd__SetValue_x                                     0x8B8AE0
#define CSliderWnd__SetNumTicks_x                                  0x8B9260

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x76A810

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8A8FB0
#define CStmlWnd__CalculateHSBRange_x                              0x8A15E0
#define CStmlWnd__CalculateVSBRange_x                              0x8A1670
#define CStmlWnd__CanBreakAtCharacter_x                            0x8A17F0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8A20D0
#define CStmlWnd__ForceParseNow_x                                  0x8A9900
#define CStmlWnd__GetNextTagPiece_x                                0x8A1FD0
#define CStmlWnd__GetSTMLText_x                                    0x662B80
#define CStmlWnd__GetVisibleText_x                                 0x8A2B20
#define CStmlWnd__InitializeWindowVariables_x                      0x8A4DD0
#define CStmlWnd__MakeStmlColorTag_x                               0x8A07C0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8A0820
#define CStmlWnd__SetSTMLText_x                                    0x8A6640
#define CStmlWnd__StripFirstSTMLLines_x                            0x8A8C50
#define CStmlWnd__UpdateHistoryString_x                            0x8A3A60

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8B0050
#define CTabWnd__DrawCurrentPage_x                                 0x8AF8C0
#define CTabWnd__DrawTab_x                                         0x8AF680
#define CTabWnd__GetCurrentPage_x                                  0x8AFC90
#define CTabWnd__GetPageInnerRect_x                                0x8AF370
#define CTabWnd__GetTabInnerRect_x                                 0x8AF570
#define CTabWnd__GetTabRect_x                                      0x8AF440
#define CTabWnd__InsertPage_x                                      0x8B0340
#define CTabWnd__SetPage_x                                         0x8AFCC0
#define CTabWnd__SetPageRect_x                                     0x8AFF90
#define CTabWnd__UpdatePage_x                                      0x8B02E0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41FCC0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8AC420

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8B52D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x873A80

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x56C0D0
#define CXStr__CXStr1_x                                            0x8B3F50
#define CXStr__CXStr3_x                                            0x82B000
#define CXStr__dCXStr_x                                            0x8AA3A0
#define CXStr__operator_equal_x                                    0x82B170
#define CXStr__operator_equal1_x                                   0x82B1C0
#define CXStr__operator_plus_equal1_x                              0x82C2A0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x885270
#define CXWnd__Center_x                                            0x88B400
#define CXWnd__ClrFocus_x                                          0x884E50
#define CXWnd__DoAllDrawing_x                                      0x88B050
#define CXWnd__DrawChildren_x                                      0x88B1F0
#define CXWnd__DrawColoredRect_x                                   0x885620
#define CXWnd__DrawTooltip_x                                       0x8858D0
#define CXWnd__DrawTooltipAtPoint_x                                0x889FC0
#define CXWnd__GetBorderFrame_x                                    0x885D20
#define CXWnd__GetChildWndAt_x                                     0x888F80
#define CXWnd__GetClientClipRect_x                                 0x885AE0
#define CXWnd__GetScreenClipRect_x                                 0x88A6C0
#define CXWnd__GetScreenRect_x                                     0x885EC0
#define CXWnd__GetTooltipRect_x                                    0x885760
#define CXWnd__GetWindowTextA_x                                    0x411430
#define CXWnd__IsActive_x                                          0x898670
#define CXWnd__IsDescendantOf_x                                    0x885C70
#define CXWnd__IsReallyVisible_x                                   0x888F60
#define CXWnd__IsType_x                                            0x8B1A00
#define CXWnd__Move_x                                              0x8886D0
#define CXWnd__Move1_x                                             0x88AD10
#define CXWnd__ProcessTransition_x                                 0x885210
#define CXWnd__Refade_x                                            0x884FF0
#define CXWnd__Resize_x                                            0x885F80
#define CXWnd__Right_x                                             0x88A4C0
#define CXWnd__SetFocus_x                                          0x887840
#define CXWnd__SetFont_x                                           0x884EA0
#define CXWnd__SetKeyTooltip_x                                     0x8861F0
#define CXWnd__SetMouseOver_x                                      0x88AA00
#define CXWnd__StartFade_x                                         0x8852C0
#define CXWnd__GetChildItem_x                                      0x88A940

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x899FA0
#define CXWndManager__DrawWindows_x                                0x899BE0
#define CXWndManager__GetKeyboardFlags_x                           0x8981A0
#define CXWndManager__HandleKeyboardMsg_x                          0x898B00
#define CXWndManager__RemoveWnd_x                                  0x898800

// CDBStr
#define CDBStr__GetString_x                                        0x487710

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8E7880
#define EQ_Character__CastSpell_x                                  0x43BC00
#define EQ_Character__Cur_HP_x                                     0x451510
#define EQ_Character__GetAACastingTimeModifier_x                   0x434D30
#define EQ_Character__GetCharInfo2_x                               0x7FF9C0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42D060
#define EQ_Character__GetFocusRangeModifier_x                      0x42D240
#define EQ_Character__Max_Endurance_x                              0x590720
#define EQ_Character__Max_HP_x                                     0x447C10
#define EQ_Character__Max_Mana_x                                   0x590550
#define EQ_Character__doCombatAbility_x                            0x58DD80
#define EQ_Character__UseSkill_x                                   0x45C040
#define EQ_Character__GetConLevel_x                                0x5835C0
#define EQ_Character__IsExpansionFlag_x                            0x410950
#define EQ_Character__TotalEffect_x                                0x439D30

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x5642F0
#define EQ_Item__CreateItemTagString_x                             0x7E0820
#define EQ_Item__IsStackable_x                                     0x7D4DA0
#define EQ_Item__GetImageNum_x                                     0x7D7AA0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A6D80
#define EQ_LoadingS__Array_x                                       0xB55320

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x591D70
#define EQ_PC__GetAltAbilityIndex_x                                0x7E8A30
#define EQ_PC__GetCombatAbility_x                                  0x7E8AC0
#define EQ_PC__GetCombatAbilityTimer_x                             0x7E8B70
#define EQ_PC__GetItemTimerValue_x                                 0x58BB70
#define EQ_PC__HasLoreItem_x                                       0x586770
#define EQ_PC__AlertInventoryChanged_x                             0x583590
#define EQ_PC__GetPcZoneClient_x                                   0x5AB660
// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E3770
#define EQItemList__add_item_x                                     0x4E36B0
#define EQItemList__delete_item_x                                  0x4E3B70
#define EQItemList__FreeItemList_x                                 0x4E3A70

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x486BB0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5971B0
#define EQPlayer__dEQPlayer_x                                      0x59FCE0
#define EQPlayer__DoAttack_x                                       0x5B1470
#define EQPlayer__EQPlayer_x                                       0x5A2170
#define EQPlayer__SetNameSpriteState_x                             0x59CA90
#define EQPlayer__SetNameSpriteTint_x                              0x5984E0
#define EQPlayer__IsBodyType_j_x                                   0x8E6B90
#define EQPlayer__IsTargetable_x                                   0x8E7360

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5A5C50
#define EQPlayerManager__GetSpawnByName_x                          0x5A60B0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56A400
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56A440
#define KeypressHandler__ClearCommandStateArray_x                  0x569FE0
#define KeypressHandler__HandleKeyDown_x                           0x568920
#define KeypressHandler__HandleKeyUp_x                             0x568C40
#define KeypressHandler__SaveKeymapping_x                          0x56A0B0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6D5110
#define MapViewMap__SaveEx_x                                       0x6D89F0

#define PlayerPointManager__GetAltCurrency_x                       0x7F9B00

// StringTable 
#define StringTable__getString_x                                   0x7F5AE0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5901D0

//Doors
#define EQSwitch__UseSwitch_x                                      0x520850

//IconCache
#define IconCache__GetIcon_x                                       0x6730E0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66A130
#define CContainerMgr__CloseContainer_x                            0x66A940

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7334B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x55DDD0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B5230
#define EQ_Spell__SpellAffects_x                                   0x4B52D0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B5300
#define CharacterZoneClient__CalcAffectChange_x                    0x436050
#define CLootWnd__LootAll_x                                        0x6CAC30
#define CTargetWnd__GetBuffCaster_x                                0x778370
