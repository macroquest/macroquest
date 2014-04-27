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
#define __ExpectedVersionDate                                     "Dec 10 2012"
#define __ExpectedVersionTime                                     "17:35:44"
#define __ActualVersionDate_x                                      0x9D16A0
#define __ActualVersionTime_x                                      0x9D16AC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x560DC0
#define __MemChecker1_x                                            0x8020B0
#define __MemChecker2_x                                            0x5F5AD0
#define __MemChecker3_x                                            0x5F5A20
#define __MemChecker4_x                                            0x8C4F40
#define __EncryptPad0_x                                            0xAD5B58
#define __EncryptPad1_x                                            0xB50AC8
#define __EncryptPad2_x                                            0xAEEAB8
#define __EncryptPad3_x                                            0xAEE6B8
#define __EncryptPad4_x                                            0xB56278
#define __AC1_x                                                    0x75D2B0
#define __AC2_x                                                    0x515BD7
#define __AC3_x                                                    0x528F30
#define __AC4_x                                                    0x52EF94
#define __AC5_x                                                    0x53AD3D
#define __AC6_x                                                    0x53E702
#define __AC7_x                                                    0x534D3C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0xDE9A50
#define DI8__Keyboard_x                                            0xDE9A54
#define DI8__Mouse_x                                               0xDE9A58
#define __AltTimerReady_x                                          0xD52C81
#define __Attack_x                                                 0xDE57FE
#define __Autofire_x                                               0xDE57FF
#define __BindList_x                                               0xABDE50
#define __Clicks_x                                                 0xD61994
#define __CommandList_x                                            0xABF49C
#define __CurrentMapLabel_x                                        0xEF5730
#define __CurrentSocial_x                                          0xAA9688
#define __DoAbilityList_x                                          0xD980A4
#define __do_loot_x                                                0x4E4E10
#define __DrawHandler_x                                            0x1555ADC
#define __GroupCount_x                                             0xD5235A

#define __Guilds_x                                                 0xD57F60
#define __gWorld_x                                                 0xD54814
#define __HotkeyPage_x                                             0xDDEAA4
#define __HWnd_x                                                   0xDE97A8
#define __InChatMode_x                                             0xD618CC
#define __LastTell_x                                               0xD637AC
#define __LMouseHeldTime_x                                         0xD61A00
#define __Mouse_x                                                  0xDE9A5C
#define __MouseLook_x                                              0xD61962
#define __MouseEventTime_x                                         0xDE5B4C
#define __NetStatusToggle_x                                        0xD61965
#define __PCNames_x                                                0xD62E20
#define __RangeAttackReady_x                                       0xD62ABC
#define __RMouseHeldTime_x                                         0xD619FC
#define __RunWalkState_x                                           0xD618D0
#define __ScreenMode_x                                             0xCA1758
#define __ScreenX_x                                                0xD61884
#define __ScreenY_x                                                0xD61880
#define __ScreenXMax_x                                             0xD61888
#define __ScreenYMax_x                                             0xD6188C
#define __ServerHost_x                                             0xD522A4
#define __ServerName_x                                             0xD98064
#define __ShiftKeyDown_x                                           0xD61F58
#define __ShowNames_x                                              0xD62CC8
#define __Socials_x                                                0xD98164


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xD548F8
#define instEQZoneInfo_x                                           0xD61B50
#define instKeypressHandler_x                                      0xDE5B30
#define pinstActiveBanker_x                                        0xD548B8
#define pinstActiveCorpse_x                                        0xD548BC
#define pinstActiveGMaster_x                                       0xD548C0
#define pinstActiveMerchant_x                                      0xD548B4
#define pinstAggroInfo_x                                           0xB68160
#define pinstAltAdvManager_x                                       0xCA26C0
#define pinstAuraMgr_x                                             0xB71948
#define pinstBandageTarget_x                                       0xD548A0
#define pinstCamActor_x                                            0xCA212C
#define pinstCDBStr_x                                              0xCA1730
#define pinstCDisplay_x                                            0xD548C8
#define pinstCEverQuest_x                                          0xDE9BD4
#define pinstCharData_x                                            0xD54884
#define pinstCharSpawn_x                                           0xD548AC
#define pinstControlledMissile_x                                   0xD54880
#define pinstControlledPlayer_x                                    0xD548AC
#define pinstCSidlManager_x                                        0x1555140
#define pinstCXWndManager_x                                        0x1555138
#define instDynamicZone_x                                          0xD61738
#define pinstDZMember_x                                            0xD61848
#define pinstDZTimerInfo_x                                         0xD6184C
#define pinstEQItemList_x                                          0xD51400
#define instEQMisc_x                                               0xAB2630
#define pinstEQSoundManager_x                                      0xCA2768
#define instExpeditionLeader_x                                     0xD61782
#define instExpeditionName_x                                       0xD617C2
#define pinstGroup_x                                               0xD52356
#define pinstImeManager_x                                          0x1555144
#define pinstLocalPlayer_x                                         0xD54898
#define pinstMercenaryData_x                                       0xDE5FA8
#define pinstModelPlayer_x                                         0xD548C4
#define pinstPCData_x                                              0xD54884
#define pinstSkillMgr_x                                            0xDE65E8
#define pinstSpawnManager_x                                        0xDE6248
#define pinstSpellManager_x                                        0xDE6660
#define pinstSpellSets_x                                           0xDDEB08
#define pinstStringTable_x                                         0xD5482C
#define pinstSwitchManager_x                                       0xD51F70
#define pinstTarget_x                                              0xD548B0
#define pinstTargetObject_x                                        0xD54888
#define pinstTargetSwitch_x                                        0xD5488C
#define pinstTaskMember_x                                          0xCA16E0
#define pinstTrackTarget_x                                         0xD548A4
#define pinstTradeTarget_x                                         0xD54894
#define instTributeActive_x                                        0xAB2655
#define pinstViewActor_x                                           0xCA2128
#define pinstWorldData_x                                           0xD54868


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xB68348
#define pinstCAudioTriggersWindow_x                                0xB682B0
#define pinstCCharacterSelect_x                                    0xCA1FD4
#define pinstCFacePick_x                                           0xCA1D84
#define pinstCNoteWnd_x                                            0xCA1F8C
#define pinstCBookWnd_x                                            0xCA1F94
#define pinstCPetInfoWnd_x                                         0xCA1F98
#define pinstCTrainWnd_x                                           0xCA1F9C
#define pinstCSkillsWnd_x                                          0xCA1FA0
#define pinstCSkillsSelectWnd_x                                    0xCA1FA4
#define pinstCCombatSkillSelectWnd_x                               0xCA1FA8
#define pinstCFriendsWnd_x                                         0xCA1FAC
#define pinstCAuraWnd_x                                            0xCA1FB0
#define pinstCRespawnWnd_x                                         0xCA1FB4
#define pinstCBandolierWnd_x                                       0xCA1FB8
#define pinstCPotionBeltWnd_x                                      0xCA1FBC
#define pinstCAAWnd_x                                              0xCA1FC0
#define pinstCGroupSearchFiltersWnd_x                              0xCA1FC4
#define pinstCLoadskinWnd_x                                        0xCA1FC8
#define pinstCAlarmWnd_x                                           0xCA1FCC
#define pinstCMusicPlayerWnd_x                                     0xCA1FD0
#define pinstCMailWnd_x                                            0xCA1FD8
#define pinstCMailCompositionWnd_x                                 0xCA1FDC
#define pinstCMailAddressBookWnd_x                                 0xCA1FE0
#define pinstCRaidWnd_x                                            0xCA1FE8
#define pinstCRaidOptionsWnd_x                                     0xCA1FEC
#define pinstCBreathWnd_x                                          0xCA1FF0
#define pinstCMapViewWnd_x                                         0xCA1FF4
#define pinstCMapToolbarWnd_x                                      0xCA1FF8
#define pinstCEditLabelWnd_x                                       0xCA1FFC
#define pinstCTargetWnd_x                                          0xCA2000
#define pinstCColorPickerWnd_x                                     0xCA2004
#define pinstCPlayerWnd_x                                          0xCA2008
#define pinstCOptionsWnd_x                                         0xCA200C
#define pinstCBuffWindowNORMAL_x                                   0xCA2010
#define pinstCBuffWindowSHORT_x                                    0xCA2014
#define pinstCharacterCreation_x                                   0xCA2018
#define pinstCCursorAttachment_x                                   0xCA201C
#define pinstCCastingWnd_x                                         0xCA2020
#define pinstCCastSpellWnd_x                                       0xCA2024
#define pinstCSpellBookWnd_x                                       0xCA2028
#define pinstCInventoryWnd_x                                       0xCA202C
#define pinstCBankWnd_x                                            0xCA2030
#define pinstCQuantityWnd_x                                        0xCA2034
#define pinstCLootWnd_x                                            0xCA2038
#define pinstCActionsWnd_x                                         0xCA203C
#define pinstCCombatAbilityWnd_x                                   0xCA2040
#define pinstCMerchantWnd_x                                        0xCA2044
#define pinstCTradeWnd_x                                           0xCA2048
#define pinstCSelectorWnd_x                                        0xCA204C
#define pinstCBazaarWnd_x                                          0xCA2050
#define pinstCBazaarSearchWnd_x                                    0xCA2054
#define pinstCGiveWnd_x                                            0xCA2070
#define pinstCTrackingWnd_x                                        0xCA2078
#define pinstCInspectWnd_x                                         0xCA207C
#define pinstCSocialEditWnd_x                                      0xCA2080
#define pinstCFeedbackWnd_x                                        0xCA2084
#define pinstCBugReportWnd_x                                       0xCA2088
#define pinstCVideoModesWnd_x                                      0xCA208C
#define pinstCTextEntryWnd_x                                       0xCA2094
#define pinstCFileSelectionWnd_x                                   0xCA2098
#define pinstCCompassWnd_x                                         0xCA209C
#define pinstCPlayerNotesWnd_x                                     0xCA20A0
#define pinstCGemsGameWnd_x                                        0xCA20A4
#define pinstCTimeLeftWnd_x                                        0xCA20A8
#define pinstCPetitionQWnd_x                                       0xCA20BC
#define pinstCSoulmarkWnd_x                                        0xCA20C0
#define pinstCStoryWnd_x                                           0xCA20C4
#define pinstCJournalTextWnd_x                                     0xCA20C8
#define pinstCJournalCatWnd_x                                      0xCA20CC
#define pinstCBodyTintWnd_x                                        0xCA20D0
#define pinstCServerListWnd_x                                      0xCA20D4
#define pinstCAvaZoneWnd_x                                         0xCA20E0
#define pinstCBlockedBuffWnd_x                                     0xCA20E4
#define pinstCBlockedPetBuffWnd_x                                  0xCA20E8
#define pinstCInvSlotMgr_x                                         0xCA2120
#define pinstCContainerMgr_x                                       0xCA2124
#define pinstCAdventureLeaderboardWnd_x                            0xEF2388
#define pinstCAdventureRequestWnd_x                                0xEF2370
#define pinstCAltStorageWnd_x                                      0xEF24C8
#define pinstCAdventureStatsWnd_x                                  0xEF2388
#define pinstCBarterMerchantWnd_x                                  0xEF2908
#define pinstCBarterSearchWnd_x                                    0xEF2920
#define pinstCBarterWnd_x                                          0xEF2958
#define pinstCChatManager_x                                        0xEF2C30
#define pinstCDynamicZoneWnd_x                                     0xEF2E20
#define pinstCEQMainWnd_x                                          0xEF2EE0
#define pinstCFellowshipWnd_x                                      0xEF2DFC
#define pinstCFindLocationWnd_x                                    0xEF3010
#define pinstCGroupSearchWnd_x                                     0xEF3170
#define pinstCGroupWnd_x                                           0xEF31A8
#define pinstCGuildBankWnd_x                                       0xEF31C0
#define pinstCGuildMgmtWnd_x                                       0xEF5250
#define pinstCGuildTributeMasterWnd_x                              0xEF6FF0
#define pinstCHotButtonWnd_x                                       0xEF52A4
#define pinstCHotButtonWnd1_x                                      0xEF52A4
#define pinstCHotButtonWnd2_x                                      0xEF52A8
#define pinstCHotButtonWnd3_x                                      0xEF52AC
#define pinstCHotButtonWnd4_x                                      0xEF52D0
#define pinstCItemDisplayManager_x                                 0xEF5420
#define pinstCItemExpTransferWnd_x                                 0xEF545C
#define pinstCLeadershipWnd_x                                      0xEF55A0
#define pinstCLFGuildWnd_x                                         0xEF55C0
#define pinstCMIZoneSelectWnd_x                                    0xEF5860
#define pinstCAdventureMerchantWnd_x                               0xEF5B28
#define pinstCConfirmationDialog_x                                 0xEF5B48
#define pinstCPopupWndManager_x                                    0xEF5B48
#define pinstCProgressionSelectionWnd_x                            0xEF5BB0
#define pinstCPvPLeaderboardWnd_x                                  0xEF5C00
#define pinstCPvPStatsWnd_x                                        0xEF5C20
#define pinstCSystemInfoDialogBox_x                                0xEF5F08
#define pinstCTargetOfTargetWnd_x                                  0xEF6C6C
#define pinstCTaskSelectWnd_x                                      0xEF5DC4
#define pinstCTaskTemplateSelectWnd_x                              0xEF6D28
#define pinstCTaskWnd_x                                            0xEF6D78
#define pinstCTipWndOFDAY_x                                        0xEF6E58
#define pinstCTipWndCONTEXT_x                                      0xEF6E5C
#define pinstCTitleWnd_x                                           0xEF6E90
#define pinstCTradeskillWnd_x                                      0xEF6EEC
#define pinstCTributeBenefitWnd_x                                  0xEF6FB8
#define pinstCTributeMasterWnd_x                                   0xEF6FF0
#define pinstCContextMenuManager_x                                 0x1554D54
#define pinstCVoiceMacroWnd_x                                      0xDE69A8
#define pinstCHtmlWnd_x                                            0xDE6A20


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x4FA650
#define __ConvertItemTags_x                                        0x4EA5B0
#define __ExecuteCmd_x                                             0x4D4B00
#define __EQGetTime_x                                              0x802C10
#define __get_melee_range_x                                        0x4DB6E0
#define __GetGaugeValueFromEQ_x                                    0x75C020
#define __GetLabelFromEQ_x                                         0x75D250
#define __GetXTargetType_x                                         0x8CCBD0
#define __LoadFrontEnd_x                                           0x5F5180
#define __NewUIINI_x                                               0x75B950
#define __ProcessGameEvents_x                                      0x536DA0
#define CrashDetected_x                                            0x5F77FB
#define DrawNetStatus_x                                            0x56FE90
#define Util__FastTime_x                                           0x801F50
#define Expansion_HoT_x                                            0xD62C28
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A1850
#define AltAdvManager__IsAbilityReady_x                            0x4A1890
#define AltAdvManager__GetAltAbility_x                             0x4A1C60

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x44A350

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x624070

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x631070

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x54C8D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x64BFE0
#define CChatManager__InitContextMenu_x                            0x64CAD0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x7E8F80
#define CChatService__GetFriendName_x                              0x7E8F90

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x651800
#define CChatWindow__Clear_x                                       0x6513C0
#define CChatWindow__WndNotification_x                             0x651D40

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x863B10
#define CComboWnd__Draw_x                                          0x863CF0
#define CComboWnd__GetCurChoice_x                                  0x863930
#define CComboWnd__GetListRect_x                                   0x863F90
#define CComboWnd__GetTextRect_x                                   0x863B70
#define CComboWnd__InsertChoice_x                                  0x864000
#define CComboWnd__SetColors_x                                     0x8638C0
#define CComboWnd__SetChoice_x                                     0x8638F0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x65AD20
#define CContainerWnd__vftable_x                                   0x9DA570

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x491810
#define CDisplay__GetClickedActor_x                                0x489930
#define CDisplay__GetUserDefinedColor_x                            0x488200
#define CDisplay__GetWorldFilePath_x                               0x4876A0
#define CDisplay__is3dON_x                                         0x486780
#define CDisplay__ReloadUI_x                                       0x49B850
#define CDisplay__WriteTextHD2_x                                   0x48CD40

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x885060

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8741D0
#define CEditWnd__GetCharIndexPt_x                                 0x8751F0
#define CEditWnd__GetDisplayString_x                               0x874380
#define CEditWnd__GetHorzOffset_x                                  0x8746C0
#define CEditWnd__GetLineForPrintableChar_x                        0x874CC0
#define CEditWnd__GetSelStartPt_x                                  0x8754A0
#define CEditWnd__GetSTMLSafeText_x                                0x874860
#define CEditWnd__PointFromPrintableChar_x                         0x874DB0
#define CEditWnd__SelectableCharFromPoint_x                        0x874F30
#define CEditWnd__SetEditable_x                                    0x874830

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x516320
#define CEverQuest__DoTellWindow_x                                 0x51ABB0
#define CEverQuest__DropHeldItemOnGround_x                         0x523430
#define CEverQuest__dsp_chat_x                                     0x51C350
#define CEverQuest__Emote_x                                        0x51C5B0
#define CEverQuest__EnterZone_x                                    0x52F120
#define CEverQuest__GetBodyTypeDesc_x                              0x5128F0
#define CEverQuest__GetClassDesc_x                                 0x512050
#define CEverQuest__GetClassThreeLetterCode_x                      0x512650
#define CEverQuest__GetDeityDesc_x                                 0x513200
#define CEverQuest__GetLangDesc_x                                  0x512C80
#define CEverQuest__GetRaceDesc_x                                  0x512F70
#define CEverQuest__InterpretCmd_x                                 0x51CE90
#define CEverQuest__LeftClickedOnPlayer_x                          0x5332D0
#define CEverQuest__LMouseUp_x                                     0x535490
#define CEverQuest__RightClickedOnPlayer_x                         0x533D40
#define CEverQuest__RMouseUp_x                                     0x534CF0
#define CEverQuest__SetGameState_x                                 0x5169D0
#define CEverQuest__UPCNotificationFlush_x                         0x51DE20

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x66A940
#define CGaugeWnd__CalcLinesFillRect_x                             0x66A9A0
#define CGaugeWnd__Draw_x                                          0x66ADD0

// CGuild
#define CGuild__FindMemberByName_x                                 0x423EF0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x687AD0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x692900
#define CInvSlotMgr__MoveItem_x                                    0x6937B0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x691DF0
#define CInvSlot__SliderComplete_x                                 0x690220
#define CInvSlot__GetItemBase_x                                    0x68F820

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6944F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x758CE0
#define CItemDisplayWnd__UpdateStrings_x                           0x695810

// CLabel 
#define CLabel__Draw_x                                             0x6AF670

// CListWnd 
#define CListWnd__AddColumn_x                                      0x851DF0
#define CListWnd__AddColumn1_x                                     0x8515D0
#define CListWnd__AddLine_x                                        0x851080
#define CListWnd__AddString_x                                      0x851290
#define CListWnd__CalculateFirstVisibleLine_x                      0x84E160
#define CListWnd__CalculateVSBRange_x                              0x850280
#define CListWnd__ClearAllSel_x                                    0x84D420
#define CListWnd__CloseAndUpdateEditWindow_x                       0x850C50
#define CListWnd__Compare_x                                        0x84EC60
#define CListWnd__Draw_x                                           0x84FEE0
#define CListWnd__DrawColumnSeparators_x                           0x84FD70
#define CListWnd__DrawHeader_x                                     0x84D730
#define CListWnd__DrawItem_x                                       0x84F2A0
#define CListWnd__DrawLine_x                                       0x84FA10
#define CListWnd__DrawSeparator_x                                  0x84FE10
#define CListWnd__EnsureVisible_x                                  0x84E2C0
#define CListWnd__ExtendSel_x                                      0x84F1B0
#define CListWnd__GetColumnMinWidth_x                              0x84CE40
#define CListWnd__GetColumnWidth_x                                 0x84CD60
#define CListWnd__GetCurSel_x                                      0x84C630
#define CListWnd__GetItemAtPoint_x                                 0x84E550
#define CListWnd__GetItemAtPoint1_x                                0x84E5C0
#define CListWnd__GetItemData_x                                    0x84C880
#define CListWnd__GetItemHeight_x                                  0x84DDC0
#define CListWnd__GetItemIcon_x                                    0x84CA60
#define CListWnd__GetItemRect_x                                    0x84E390
#define CListWnd__GetItemText_x                                    0x84C910
#define CListWnd__GetSelList_x                                     0x8514C0
#define CListWnd__GetSeparatorRect_x                               0x84EB80
#define CListWnd__RemoveLine_x                                     0x851470
#define CListWnd__SetColors_x                                      0x84C690
#define CListWnd__SetColumnJustification_x                         0x84D110
#define CListWnd__SetColumnWidth_x                                 0x84CDF0
#define CListWnd__SetCurSel_x                                      0x84C670
#define CListWnd__SetItemColor_x                                   0x850930
#define CListWnd__SetItemData_x                                    0x84D4D0
#define CListWnd__SetItemText_x                                    0x850770
#define CListWnd__ShiftColumnSeparator_x                           0x850600
#define CListWnd__Sort_x                                           0x851F50
#define CListWnd__ToggleSel_x                                      0x84D3A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6CA4A0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6E9DB0
#define CMerchantWnd__RequestBuyItem_x                             0x6EFF10
#define CMerchantWnd__RequestSellItem_x                            0x716D40
#define CMerchantWnd__SelectBuySellSlot_x                          0x6EA060

// CObfuscator
#define CObfuscator__doit_x                                        0x7C98D0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8692D0
#define CSidlManager__CreateLabel_x                                0x74F590

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x61B240
#define CSidlScreenWnd__CalculateVSBRange_x                        0x61B170
#define CSidlScreenWnd__ConvertToRes_x                             0x884F40
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x856E10
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x858130
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8581E0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8576C0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8568F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x856050
#define CSidlScreenWnd__GetSidlPiece_x                             0x856AE0
#define CSidlScreenWnd__Init1_x                                    0x857E00
#define CSidlScreenWnd__LoadIniInfo_x                              0x856EC0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x856210
#define CSidlScreenWnd__LoadSidlScreen_x                           0x857910
#define CSidlScreenWnd__StoreIniInfo_x                             0x855C00
#define CSidlScreenWnd__StoreIniVis_x                              0x855FE0
#define CSidlScreenWnd__WndNotification_x                          0x857B80
#define CSidlScreenWnd__GetChildItem_x                             0x856120

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5B7460
#define CSkillMgr__GetSkillCap_x                                   0x5B74D0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x88EF90
#define CSliderWnd__SetValue_x                                     0x88F160
#define CSliderWnd__SetNumTicks_x                                  0x88F8E0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x756750

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x87F660
#define CStmlWnd__CalculateHSBRange_x                              0x877DD0
#define CStmlWnd__CalculateVSBRange_x                              0x877E50
#define CStmlWnd__CanBreakAtCharacter_x                            0x877FD0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8788B0
#define CStmlWnd__ForceParseNow_x                                  0x880020
#define CStmlWnd__GetNextTagPiece_x                                0x8787B0
#define CStmlWnd__GetSTMLText_x                                    0x650C60
#define CStmlWnd__GetVisibleText_x                                 0x879300
#define CStmlWnd__InitializeWindowVariables_x                      0x87B4E0
#define CStmlWnd__MakeStmlColorTag_x                               0x877020
#define CStmlWnd__MakeWndNotificationTag_x                         0x877080
#define CStmlWnd__SetSTMLText_x                                    0x87CD40
#define CStmlWnd__StripFirstSTMLLines_x                            0x87F300
#define CStmlWnd__UpdateHistoryString_x                            0x87A240

// CTabWnd 
#define CTabWnd__Draw_x                                            0x886730
#define CTabWnd__DrawCurrentPage_x                                 0x885FA0
#define CTabWnd__DrawTab_x                                         0x885D60
#define CTabWnd__GetCurrentPage_x                                  0x886370
#define CTabWnd__GetPageInnerRect_x                                0x885A50
#define CTabWnd__GetTabInnerRect_x                                 0x885C50
#define CTabWnd__GetTabRect_x                                      0x885B20
#define CTabWnd__InsertPage_x                                      0x886A20
#define CTabWnd__SetPage_x                                         0x8863A0
#define CTabWnd__SetPageRect_x                                     0x886670
#define CTabWnd__UpdatePage_x                                      0x8869C0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41FA60

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x882B20

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x88B950

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x84A820

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x411080
#define CXStr__CXStr1_x                                            0x4D93A0
#define CXStr__CXStr3_x                                            0x7FF020
#define CXStr__dCXStr_x                                            0x404680
#define CXStr__operator_equal_x                                    0x7FF190
#define CXStr__operator_equal1_x                                   0x7FF1E0
#define CXStr__operator_plus_equal1_x                              0x8002C0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x85BCC0
#define CXWnd__Center_x                                            0x861F50
#define CXWnd__ClrFocus_x                                          0x85B8A0
#define CXWnd__DoAllDrawing_x                                      0x861BC0
#define CXWnd__DrawChildren_x                                      0x861D50
#define CXWnd__DrawColoredRect_x                                   0x85C080
#define CXWnd__DrawTooltip_x                                       0x85C320
#define CXWnd__DrawTooltipAtPoint_x                                0x860B00
#define CXWnd__GetBorderFrame_x                                    0x85C810
#define CXWnd__GetChildWndAt_x                                     0x85FAB0
#define CXWnd__GetClientClipRect_x                                 0x85C530
#define CXWnd__GetScreenClipRect_x                                 0x861200
#define CXWnd__GetScreenRect_x                                     0x85C960
#define CXWnd__GetTooltipRect_x                                    0x85C1B0
#define CXWnd__GetWindowTextA_x                                    0x4110C0
#define CXWnd__IsActive_x                                          0x86F1A0
#define CXWnd__IsDescendantOf_x                                    0x85C6C0
#define CXWnd__IsReallyVisible_x                                   0x85FA90
#define CXWnd__IsType_x                                            0x888160
#define CXWnd__Move_x                                              0x85F180
#define CXWnd__Move1_x                                             0x861860
#define CXWnd__ProcessTransition_x                                 0x85BC70
#define CXWnd__Refade_x                                            0x85BA50
#define CXWnd__Resize_x                                            0x85CA30
#define CXWnd__Right_x                                             0x861000
#define CXWnd__SetFocus_x                                          0x85E2E0
#define CXWnd__SetFont_x                                           0x85B8F0
#define CXWnd__SetKeyTooltip_x                                     0x85CCA0
#define CXWnd__SetMouseOver_x                                      0x861540
#define CXWnd__StartFade_x                                         0x85BD10
#define CXWnd__GetChildItem_x                                      0x861480

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8708C0
#define CXWndManager__DrawWindows_x                                0x870500
#define CXWndManager__GetKeyboardFlags_x                           0x86ECD0
#define CXWndManager__HandleKeyboardMsg_x                          0x86F450
#define CXWndManager__RemoveWnd_x                                  0x86F2C0

// CDBStr
#define CDBStr__GetString_x                                        0x484A00

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8C9570
#define EQ_Character__CastSpell_x                                  0x43A9D0
#define EQ_Character__Cur_HP_x                                     0x449FA0
#define EQ_Character__GetAACastingTimeModifier_x                   0x433900
#define EQ_Character__GetCharInfo2_x                               0x7D4780
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42CC50
#define EQ_Character__GetFocusRangeModifier_x                      0x42CE30
#define EQ_Character__Max_Endurance_x                              0x57EB10
#define EQ_Character__Max_HP_x                                     0x444140
#define EQ_Character__Max_Mana_x                                   0x57E950
#define EQ_Character__doCombatAbility_x                            0x57D3B0
#define EQ_Character__UseSkill_x                                   0x45A880
#define EQ_Character__GetConLevel_x                                0x574440
#define EQ_Character__IsExpansionFlag_x                            0x4105C0
#define EQ_Character__TotalEffect_x                                0x438BE0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x551850
#define EQ_Item__CreateItemTagString_x                             0x7B5320
#define EQ_Item__IsStackable_x                                     0x7A9BD0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A3850
#define EQ_LoadingS__Array_x                                       0xAB8B48

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x582DD0
#define EQ_PC__GetAltAbilityIndex_x                                0x7BDA70
#define EQ_PC__GetCombatAbility_x                                  0x7BDB00
#define EQ_PC__GetCombatAbilityTimer_x                             0x7BDBB0
#define EQ_PC__GetItemTimerValue_x                                 0x57D0F0
#define EQ_PC__HasLoreItem_x                                       0x5775A0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4D9470
#define EQItemList__add_item_x                                     0x4D93B0
#define EQItemList__delete_item_x                                  0x4D9880
#define EQItemList__FreeItemList_x                                 0x4D9770

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x483F30

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5889C0
#define EQPlayer__dEQPlayer_x                                      0x58D540
#define EQPlayer__DoAttack_x                                       0x5A1A30
#define EQPlayer__EQPlayer_x                                       0x592CD0
#define EQPlayer__SetNameSpriteState_x                             0x58ADF0
#define EQPlayer__SetNameSpriteTint_x                              0x588A30
#define EQPlayer__IsBodyType_j_x                                   0x8C8E10
#define EQPlayer__IsTargetable_x                                   0x8C90E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5961D0
#define EQPlayerManager__GetSpawnByName_x                          0x596630

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x557A20
#define KeypressHandler__AttachKeyToEqCommand_x                    0x557A60
#define KeypressHandler__ClearCommandStateArray_x                  0x557600
#define KeypressHandler__HandleKeyDown_x                           0x555F60
#define KeypressHandler__HandleKeyUp_x                             0x556280
#define KeypressHandler__SaveKeymapping_x                          0x5576D0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6C2900
#define MapViewMap__SaveEx_x                                       0x6C61B0

#define PlayerPointManager__GetAltCurrency_x                       0x7CE8B0

// StringTable 
#define StringTable__getString_x                                   0x7C9B70

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5816D0
