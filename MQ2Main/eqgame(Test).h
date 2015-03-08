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
#define __ExpectedVersionDate                                     "Feb 26 2015"
#define __ExpectedVersionTime                                     "12:01:36"
#define __ActualVersionDate_x                                      0xA780A0
#define __ActualVersionTime_x                                      0xA780AC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x58FE20
#define __MemChecker1_x                                            0x8582B0
#define __MemChecker2_x                                            0x6277C0
#define __MemChecker3_x                                            0x627710
#define __MemChecker4_x                                            0x7DC100
#define __EncryptPad0_x                                            0xBF3ED0
#define __EncryptPad1_x                                            0xD781E8
#define __EncryptPad2_x                                            0xC3CE50
#define __EncryptPad3_x                                            0xC3CA50
#define __EncryptPad4_x                                            0xD54910
#define __AC1_x                                                    0x799695
#define __AC2_x                                                    0x545EC7
#define __AC3_x                                                    0x55A6C0
#define __AC4_x                                                    0x560B00
#define __AC5_x                                                    0x56C8BE
#define __AC6_x                                                    0x570412
#define __AC7_x                                                    0x566FAC
#define __AC1_Data                                                 0x11111111

// Direct Input
#define DI8__Main_x                                                0x1129FC0
#define DI8__Keyboard_x                                            0x1129FC4
#define DI8__Mouse_x                                               0x1129FC8
#define __AltTimerReady_x                                          0xF89931
#define __Attack_x                                                 0x101CB4B
#define __Autofire_x                                               0x101CB4C
#define __BindList_x                                               0xBB6938
#define __bCommandEnabled_x                                        0xF87A40
#define __Clicks_x                                                 0xF986A0
#define __CommandList_x                                            0xBBAC00
#define __CurrentMapLabel_x                                        0x112FA18
#define __CurrentSocial_x                                          0xB73EC0
#define __DoAbilityList_x                                          0xFCEE00
#define __do_loot_x                                                0x50D7C0
#define __DrawHandler_x                                            0x1794624
#define __GroupCount_x                                             0xF8900A

#define __Guilds_x                                                 0xF8EC20
#define __gWorld_x                                                 0xF8B4C4
#define __HotkeyPage_x                                             0x1015800
#define __HWnd_x                                                   0x1021EC8
#define __InChatMode_x                                             0xF985CC
#define __LastTell_x                                               0xF9A508
#define __LMouseHeldTime_x                                         0xF9870C
#define __Mouse_x                                                  0x1129FCC
#define __MouseLook_x                                              0xF98666
#define __MouseEventTime_x                                         0x101D354
#define __NetStatusToggle_x                                        0xF98669
#define __PCNames_x                                                0xF99B2C
#define __RangeAttackReady_x                                       0xF997F0
#define __RMouseHeldTime_x                                         0xF98708
#define __RunWalkState_x                                           0xF985D0
#define __ScreenMode_x                                             0xED78F8
#define __ScreenX_x                                                0xF98584
#define __ScreenY_x                                                0xF98580
#define __ScreenXMax_x                                             0xF98588
#define __ScreenYMax_x                                             0xF9858C
#define __ServerHost_x                                             0xF88F54
#define __ServerName_x                                             0xFCEDC0
#define __ShiftKeyDown_x                                           0xF98C74
#define __ShowNames_x                                              0xF999C4
#define __Socials_x                                                0xFCEEC0
#define __SubscriptionType_x                                       0x115BDA8
#define __TargetAggroHolder_x                                      0x1131C54
#define __GroupAggro_x                                             0x1131C94
#define __LoginName_x                                              0x1020AA0
#define __Inviter_x                                                0x101CAC8


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF8B5B0
#define instEQZoneInfo_x                                           0xF9885C
#define instKeypressHandler_x                                      0x101D338
#define pinstActiveBanker_x                                        0xF8B568
#define pinstActiveCorpse_x                                        0xF8B56C
#define pinstActiveGMaster_x                                       0xF8B570
#define pinstActiveMerchant_x                                      0xF8B564
#define pinstAggroInfo_x                                           0xD9BD78
#define pinstAltAdvManager_x                                       0xED89E0
#define pinstAuraMgr_x                                             0xDA5C40
#define pinstBandageTarget_x                                       0xF8B550
#define pinstCamActor_x                                            0xED82E8
#define pinstCDBStr_x                                              0xED788C
#define pinstCDisplay_x                                            0xF8B578
#define pinstCEverQuest_x                                          0x112A140
#define pinstCharData_x                                            0xF8B534
#define pinstCharSpawn_x                                           0xF8B55C
#define pinstControlledMissile_x                                   0xF8B530
#define pinstControlledPlayer_x                                    0xF8B55C
#define pinstCSidlManager_x                                        0x1793A44
#define pinstCXWndManager_x                                        0x1793A3C
#define instDynamicZone_x                                          0xF98418
#define pinstDZMember_x                                            0xF98528
#define pinstDZTimerInfo_x                                         0xF9852C
#define pinstEQItemList_x                                          0xF87C90
#define instEQMisc_x                                               0xB94680
#define pinstEQSoundManager_x                                      0xED8DD8
#define instExpeditionLeader_x                                     0xF98462
#define instExpeditionName_x                                       0xF984A2
#define pinstGroup_x                                               0xF89006
#define pinstImeManager_x                                          0x1793A48
#define pinstLocalPlayer_x                                         0xF8B548
#define pinstMercenaryData_x                                       0x101D988
#define pinstMercAltAbilities_x                                    0xED8CF4
#define pinstModelPlayer_x                                         0xF8B574
#define pinstPCData_x                                              0xF8B534
#define pinstSkillMgr_x                                            0x101E7C0
#define pinstSpawnManager_x                                        0x101E0A8
#define pinstSpellManager_x                                        0x101E908
#define pinstSpellSets_x                                           0x1015864
#define pinstStringTable_x                                         0xF8B4DC
#define pinstSwitchManager_x                                       0xF88B98
#define pinstTarget_x                                              0xF8B560
#define pinstTargetObject_x                                        0xF8B538
#define pinstTargetSwitch_x                                        0xF8B53C
#define pinstTaskMember_x                                          0xED77D8
#define pinstTrackTarget_x                                         0xF8B554
#define pinstTradeTarget_x                                         0xF8B544
#define instTributeActive_x                                        0xB946A5
#define pinstViewActor_x                                           0xED82E4
#define pinstWorldData_x                                           0xF8B518


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD9C258
#define pinstCAudioTriggersWindow_x                                0xD9C0E8
#define pinstCCharacterSelect_x                                    0xED8188
#define pinstCFacePick_x                                           0xED8138
#define pinstCNoteWnd_x                                            0xED8140
#define pinstCBookWnd_x                                            0xED8148
#define pinstCPetInfoWnd_x                                         0xED814C
#define pinstCTrainWnd_x                                           0xED8150
#define pinstCSkillsWnd_x                                          0xED8154
#define pinstCSkillsSelectWnd_x                                    0xED8158
#define pinstCCombatSkillSelectWnd_x                               0xED815C
#define pinstCFriendsWnd_x                                         0xED8160
#define pinstCAuraWnd_x                                            0xED8164
#define pinstCRespawnWnd_x                                         0xED8168
#define pinstCBandolierWnd_x                                       0xED816C
#define pinstCPotionBeltWnd_x                                      0xED8170
#define pinstCAAWnd_x                                              0xED8174
#define pinstCGroupSearchFiltersWnd_x                              0xED8178
#define pinstCLoadskinWnd_x                                        0xED817C
#define pinstCAlarmWnd_x                                           0xED8180
#define pinstCMusicPlayerWnd_x                                     0xED8184
#define pinstCMailWnd_x                                            0xED818C
#define pinstCMailCompositionWnd_x                                 0xED8190
#define pinstCMailAddressBookWnd_x                                 0xED8194
#define pinstCRaidWnd_x                                            0xED819C
#define pinstCRaidOptionsWnd_x                                     0xED81A0
#define pinstCBreathWnd_x                                          0xED81A4
#define pinstCMapViewWnd_x                                         0xED81A8
#define pinstCMapToolbarWnd_x                                      0xED81AC
#define pinstCEditLabelWnd_x                                       0xED81B0
#define pinstCTargetWnd_x                                          0xED81B4
#define pinstCColorPickerWnd_x                                     0xED81B8
#define pinstCPlayerWnd_x                                          0xED81BC
#define pinstCOptionsWnd_x                                         0xED81C0
#define pinstCBuffWindowNORMAL_x                                   0xED81C4
#define pinstCBuffWindowSHORT_x                                    0xED81C8
#define pinstCharacterCreation_x                                   0xED81CC
#define pinstCCursorAttachment_x                                   0xED81D0
#define pinstCCastingWnd_x                                         0xED81D4
#define pinstCCastSpellWnd_x                                       0xED81D8
#define pinstCSpellBookWnd_x                                       0xED81DC
#define pinstCInventoryWnd_x                                       0xED81E0
#define pinstCBankWnd_x                                            0xED81E4
#define pinstCQuantityWnd_x                                        0xED81E8
#define pinstCLootWnd_x                                            0xED81EC
#define pinstCActionsWnd_x                                         0xED81F0
#define pinstCCombatAbilityWnd_x                                   0xED81F4
#define pinstCMerchantWnd_x                                        0xED81F8
#define pinstCTradeWnd_x                                           0xED81FC
#define pinstCSelectorWnd_x                                        0xED8200
#define pinstCBazaarWnd_x                                          0xED8204
#define pinstCBazaarSearchWnd_x                                    0xED8208
#define pinstCGiveWnd_x                                            0xED8224
#define pinstCTrackingWnd_x                                        0xED822C
#define pinstCInspectWnd_x                                         0xED8230
#define pinstCSocialEditWnd_x                                      0xED8234
#define pinstCFeedbackWnd_x                                        0xED8238
#define pinstCBugReportWnd_x                                       0xED823C
#define pinstCVideoModesWnd_x                                      0xED8240
#define pinstCTextEntryWnd_x                                       0xED8248
#define pinstCFileSelectionWnd_x                                   0xED824C
#define pinstCCompassWnd_x                                         0xED8250
#define pinstCPlayerNotesWnd_x                                     0xED8254
#define pinstCGemsGameWnd_x                                        0xED8258
#define pinstCTimeLeftWnd_x                                        0xED825C
#define pinstCPetitionQWnd_x                                       0xED8270
#define pinstCSoulmarkWnd_x                                        0xED8274
#define pinstCStoryWnd_x                                           0xED8278
#define pinstCJournalTextWnd_x                                     0xED827C
#define pinstCJournalCatWnd_x                                      0xED8280
#define pinstCBodyTintWnd_x                                        0xED8284
#define pinstCServerListWnd_x                                      0xED8288
#define pinstCAvaZoneWnd_x                                         0xED8294
#define pinstCBlockedBuffWnd_x                                     0xED8298
#define pinstCBlockedPetBuffWnd_x                                  0xED829C
#define pinstCInvSlotMgr_x                                         0xED82DC
#define pinstCContainerMgr_x                                       0xED82E0
#define pinstCAdventureLeaderboardWnd_x                            0x112AAF0
#define pinstCAdventureRequestWnd_x                                0x112AB68
#define pinstCAltStorageWnd_x                                      0x112AE48
#define pinstCAdventureStatsWnd_x                                  0x112ABE0
#define pinstCBarterMerchantWnd_x                                  0x112BA30
#define pinstCBarterSearchWnd_x                                    0x112BAA8
#define pinstCBarterWnd_x                                          0x112BB20
#define pinstCChatManager_x                                        0x112C1B0
#define pinstCDynamicZoneWnd_x                                     0x112C660
#define pinstCEQMainWnd_x                                          0x112C7F8
#define pinstCFellowshipWnd_x                                      0x112C5F4
#define pinstCFindLocationWnd_x                                    0x112CAC8
#define pinstCGroupSearchWnd_x                                     0x112CD98
#define pinstCGroupWnd_x                                           0x112CE10
#define pinstCGuildBankWnd_x                                       0x112CE88
#define pinstCGuildMgmtWnd_x                                       0x112EF78
#define pinstCHotButtonWnd_x                                       0x112F044
#define pinstCHotButtonWnd1_x                                      0x112F044
#define pinstCHotButtonWnd2_x                                      0x112F048
#define pinstCHotButtonWnd3_x                                      0x112F04C
#define pinstCHotButtonWnd4_x                                      0x112F070
#define pinstCItemDisplayManager_x                                 0x112F368
#define pinstCItemExpTransferWnd_x                                 0x112F3E4
#define pinstCLFGuildWnd_x                                         0x112F6C0
#define pinstCMIZoneSelectWnd_x                                    0x112FCA8
#define pinstCConfirmationDialog_x                                 0x11303B0
#define pinstCPopupWndManager_x                                    0x11303B0
#define pinstCProgressionSelectionWnd_x                            0x11304A0
#define pinstCPvPStatsWnd_x                                        0x1130590
#define pinstCSystemInfoDialogBox_x                                0x1130C98
#define pinstCTaskWnd_x                                            0x1132060
#define pinstCTaskSomething_x                                      0xDA6380
#define pinstCTaskTemplateSelectWnd_x                              0x1131FE8
#define pinstCTipWndOFDAY_x                                        0x11322B8
#define pinstCTipWndCONTEXT_x                                      0x11322BC
#define pinstCTitleWnd_x                                           0x1132338
#define pinstCContextMenuManager_x                                 0x1793AC8
#define pinstCVoiceMacroWnd_x                                      0x101EF70
#define pinstCHtmlWnd_x                                            0x101F068
#define pinstIconCache_x                                           0x112C7CC
#define pinstCTradeskillWnd_x                                      0x1132438

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5251B0
#define __ConvertItemTags_x                                        0x512430
#define __ExecuteCmd_x                                             0x4FCDE0
#define __EQGetTime_x                                              0x8585D0
#define __get_melee_range_x                                        0x503AE0
#define __GetGaugeValueFromEQ_x                                    0x7983E0
#define __GetLabelFromEQ_x                                         0x799620
#define __ToggleMount_x                                            0x6C1D40
#define __GetXTargetType_x                                         0x916980
#define __LoadFrontEnd_x                                           0x626E70
#define __NewUIINI_x                                               0x797CE0
#define __ProcessGameEvents_x                                      0x568D10
#define __ProcessMouseEvent_x                                      0x5684B0
#define CrashDetected_x                                            0x628940
#define wwsCrashReportCheckForUploader_x                           0x7ED4A0
#define DrawNetStatus_x                                            0x59F810
#define Util__FastTime_x                                           0x858120
#define Expansion_HoT_x                                            0xF9995C
#define __HelpPath_x                                               0x101D0C0
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4BDAF0
#define AltAdvManager__IsAbilityReady_x                            0x4BDB60
#define AltAdvManager__GetAltAbility_x                             0x4BDF20

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x462330
#define CharacterZoneClient__MakeMeVisible_x                       0x4673F0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6565D0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x664330

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x57EE80

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x67F920
#define CChatManager__InitContextMenu_x                            0x680440

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8C7C80
#define CContextMenu__AddMenuItem_x                                0x8C7EA0
#define CContextMenu__dCContextMenu_x                              0x8C7E90
#define CContextMenu__RemoveMenuItem_x                             0x8C8190
#define CContextMenu__RemoveAllMenuItems_x                         0x8C81B0
#define CContextMenuManager__AddMenu_x                             0x8CAE90
#define CContextMenuManager__RemoveMenu_x                          0x8CB1E0
#define CContextMenuManager__PopupMenu_x                           0x8CB630
#define CContextMenuManager__Flush_x                               0x8CAF00

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x83ED10
#define CChatService__GetFriendName_x                              0x83ED20

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6854B0
#define CChatWindow__Clear_x                                       0x685060
#define CChatWindow__WndNotification_x                             0x6859F0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BB420
#define CComboWnd__Draw_x                                          0x8BB630
#define CComboWnd__GetCurChoice_x                                  0x8BB1F0
#define CComboWnd__GetListRect_x                                   0x8BB8D0
#define CComboWnd__GetTextRect_x                                   0x8BB490
#define CComboWnd__InsertChoice_x                                  0x8BB940
#define CComboWnd__SetColors_x                                     0x8BB180
#define CComboWnd__SetChoice_x                                     0x8BB1B0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x68EC40
#define CContainerWnd__vftable_x                                   0xA81800

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4AC2C0
#define CDisplay__GetClickedActor_x                                0x4A4E50
#define CDisplay__GetUserDefinedColor_x                            0x4A3710
#define CDisplay__GetWorldFilePath_x                               0x4A2B60
#define CDisplay__is3dON_x                                         0x4A1F30
#define CDisplay__ReloadUI_x                                       0x4B76C0
#define CDisplay__WriteTextHD2_x                                   0x4A8660

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8DED90

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8CD1F0
#define CEditWnd__GetCharIndexPt_x                                 0x8CE220
#define CEditWnd__GetDisplayString_x                               0x8CD3A0
#define CEditWnd__GetHorzOffset_x                                  0x8CD6E0
#define CEditWnd__GetLineForPrintableChar_x                        0x8CDCE0
#define CEditWnd__GetSelStartPt_x                                  0x8CE4E0
#define CEditWnd__GetSTMLSafeText_x                                0x8CD880
#define CEditWnd__PointFromPrintableChar_x                         0x8CDDD0
#define CEditWnd__SelectableCharFromPoint_x                        0x8CDF50
#define CEditWnd__SetEditable_x                                    0x8CD850

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x546610
#define CEverQuest__DoTellWindow_x                                 0x54C010
#define CEverQuest__DropHeldItemOnGround_x                         0x554B40
#define CEverQuest__dsp_chat_x                                     0x54D7B0
#define CEverQuest__Emote_x                                        0x54DA10
#define CEverQuest__EnterZone_x                                    0x561320
#define CEverQuest__GetBodyTypeDesc_x                              0x542E70
#define CEverQuest__GetClassDesc_x                                 0x548B80
#define CEverQuest__GetClassThreeLetterCode_x                      0x549180
#define CEverQuest__GetDeityDesc_x                                 0x543750
#define CEverQuest__GetLangDesc_x                                  0x543200
#define CEverQuest__GetRaceDesc_x                                  0x549340
#define CEverQuest__InterpretCmd_x                                 0x54E2F0
#define CEverQuest__LeftClickedOnPlayer_x                          0x565410
#define CEverQuest__LMouseUp_x                                     0x567500
#define CEverQuest__RightClickedOnPlayer_x                         0x565F10
#define CEverQuest__RMouseUp_x                                     0x566F60
#define CEverQuest__SetGameState_x                                 0x546CC0
#define CEverQuest__UPCNotificationFlush_x                         0x54F490
#define CEverQuest__IssuePetCommand_x                              0x54EFF0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x69F6E0
#define CGaugeWnd__CalcLinesFillRect_x                             0x69F740
#define CGaugeWnd__Draw_x                                          0x69FB70

// CGuild
#define CGuild__FindMemberByName_x                                 0x433CE0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6BC7A0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CA560
#define CInvSlotMgr__MoveItem_x                                    0x6CB4A0
#define CInvSlotMgr__SelectSlot_x                                  0x6CA610

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6C9A00
#define CInvSlot__SliderComplete_x                                 0x6C73C0
#define CInvSlot__GetItemBase_x                                    0x6C6840

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6CC660

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x794ED0
#define CItemDisplayWnd__UpdateStrings_x                           0x6CD9D0

// CLabel 
#define CLabel__Draw_x                                             0x6E8640

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8A43E0
#define CListWnd__dCListWnd_x                                      0x8A5460
#define CListWnd__AddColumn_x                                      0x8A5400
#define CListWnd__AddColumn1_x                                     0x8A4BE0
#define CListWnd__AddLine_x                                        0x8A4690
#define CListWnd__AddString_x                                      0x8A48A0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A1700
#define CListWnd__CalculateVSBRange_x                              0x8A3890
#define CListWnd__ClearAllSel_x                                    0x8A09C0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8A4270
#define CListWnd__Compare_x                                        0x8A2210
#define CListWnd__Draw_x                                           0x8A34A0
#define CListWnd__DrawColumnSeparators_x                           0x8A3330
#define CListWnd__DrawHeader_x                                     0x8A0CD0
#define CListWnd__DrawItem_x                                       0x8A2860
#define CListWnd__DrawLine_x                                       0x8A2FD0
#define CListWnd__DrawSeparator_x                                  0x8A33D0
#define CListWnd__EnsureVisible_x                                  0x8A1860
#define CListWnd__ExtendSel_x                                      0x8A2770
#define CListWnd__GetColumnMinWidth_x                              0x8A03E0
#define CListWnd__GetColumnWidth_x                                 0x8A0300
#define CListWnd__GetCurSel_x                                      0x89FAD0
#define CListWnd__GetItemAtPoint_x                                 0x8A1B00
#define CListWnd__GetItemAtPoint1_x                                0x8A1B70
#define CListWnd__GetItemData_x                                    0x89FE20
#define CListWnd__GetItemHeight_x                                  0x8A1360
#define CListWnd__GetItemIcon_x                                    0x8A0000
#define CListWnd__GetItemRect_x                                    0x8A1940
#define CListWnd__GetItemText_x                                    0x89FEB0
#define CListWnd__GetSelList_x                                     0x8A4AD0
#define CListWnd__GetSeparatorRect_x                               0x8A2130
#define CListWnd__RemoveLine_x                                     0x8A4A80
#define CListWnd__SetColors_x                                      0x89FC20
#define CListWnd__SetColumnJustification_x                         0x8A06B0
#define CListWnd__SetColumnWidth_x                                 0x8A0390
#define CListWnd__SetCurSel_x                                      0x89FB10
#define CListWnd__SetItemColor_x                                   0x8A3F50
#define CListWnd__SetItemData_x                                    0x8A0A70
#define CListWnd__SetItemText_x                                    0x8A3D90
#define CListWnd__ShiftColumnSeparator_x                           0x8A3C20
#define CListWnd__Sort_x                                           0x8A5560
#define CListWnd__ToggleSel_x                                      0x8A0940

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x701BC0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x722C90
#define CMerchantWnd__RequestBuyItem_x                             0x729AC0
#define CMerchantWnd__RequestSellItem_x                            0x72A510
#define CMerchantWnd__SelectRecoverySlot_x                         0x722F40
#define CMerchantWnd__SelectBuySellSlot_x                          0x7221A0
#define CMerchantWnd__ActualSelect_x                               0x7269F0

// CObfuscator
#define CObfuscator__doit_x                                        0x81EDD0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8C2C30
#define CSidlManager__CreateLabel_x                                0x78AEF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x64D7D0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x64D6B0
#define CSidlScreenWnd__ConvertToRes_x                             0x8DEC70
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8AE6C0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8AFBB0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8AFC60
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8AF120
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8AE090
#define CSidlScreenWnd__EnableIniStorage_x                         0x8AD7D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8AE280
#define CSidlScreenWnd__Init1_x                                    0x8AF890
#define CSidlScreenWnd__LoadIniInfo_x                              0x8AE770
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8AD990
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8AF370
#define CSidlScreenWnd__StoreIniInfo_x                             0x8AD2A0
#define CSidlScreenWnd__StoreIniVis_x                              0x8AD760
#define CSidlScreenWnd__WndNotification_x                          0x8AF610
#define CSidlScreenWnd__GetChildItem_x                             0x8AD8A0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B3D20

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5E8ED0
#define CSkillMgr__GetSkillCap_x                                   0x5E9070
#define CSkillMgr__GetNameToken_x                                  0x5E8B40

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8DDF40
#define CSliderWnd__SetValue_x                                     0x8DE110
#define CSliderWnd__SetNumTicks_x                                  0x8DE890

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x792B70

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8D8910
#define CStmlWnd__CalculateHSBRange_x                              0x8D0ED0
#define CStmlWnd__CalculateVSBRange_x                              0x8D0E40
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D1050
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D1930
#define CStmlWnd__ForceParseNow_x                                  0x8D9260
#define CStmlWnd__GetNextTagPiece_x                                0x8D1830
#define CStmlWnd__GetSTMLText_x                                    0x684900
#define CStmlWnd__GetVisibleText_x                                 0x8D2380
#define CStmlWnd__InitializeWindowVariables_x                      0x8D4710
#define CStmlWnd__MakeStmlColorTag_x                               0x8D0140
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D01A0
#define CStmlWnd__SetSTMLText_x                                    0x8D5F70
#define CStmlWnd__StripFirstSTMLLines_x                            0x8D85B0
#define CStmlWnd__UpdateHistoryString_x                            0x8D32C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E0470
#define CTabWnd__DrawCurrentPage_x                                 0x8DFCE0
#define CTabWnd__DrawTab_x                                         0x8DFAA0
#define CTabWnd__GetCurrentPage_x                                  0x8E00B0
#define CTabWnd__GetPageInnerRect_x                                0x8DF790
#define CTabWnd__GetTabInnerRect_x                                 0x8DF990
#define CTabWnd__GetTabRect_x                                      0x8DF860
#define CTabWnd__InsertPage_x                                      0x8E0760
#define CTabWnd__SetPage_x                                         0x8E00E0
#define CTabWnd__SetPageRect_x                                     0x8E03B0
#define CTabWnd__UpdatePage_x                                      0x8E0700

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x42FAB0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BADF0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8E5620

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x89DC30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x58C4C0
#define CXStr__CXStr1_x                                            0x893330
#define CXStr__CXStr3_x                                            0x8551B0
#define CXStr__dCXStr_x                                            0x58C810
#define CXStr__operator_equal_x                                    0x855320
#define CXStr__operator_equal1_x                                   0x855370
#define CXStr__operator_plus_equal1_x                              0x856450

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B2F20
#define CXWnd__Center_x                                            0x8B90F0
#define CXWnd__ClrFocus_x                                          0x8B2AF0
#define CXWnd__DoAllDrawing_x                                      0x8B8D40
#define CXWnd__DrawChildren_x                                      0x8B8EE0

#define CXWnd__DrawColoredRect_x                                   0x8B32E0
#define CXWnd__DrawTooltip_x                                       0x8B3590
#define CXWnd__DrawTooltipAtPoint_x                                0x8B7CA0
#define CXWnd__GetBorderFrame_x                                    0x8B3A00
#define CXWnd__GetChildWndAt_x                                     0x8B9AB0
#define CXWnd__GetClientClipRect_x                                 0x8B37B0
#define CXWnd__GetScreenClipRect_x                                 0x8B83A0
#define CXWnd__GetScreenRect_x                                     0x8B3BC0
#define CXWnd__GetTooltipRect_x                                    0x8B3420
#define CXWnd__GetWindowTextA_x                                    0x420C20
#define CXWnd__IsActive_x                                          0x8A8240
#define CXWnd__IsDescendantOf_x                                    0x8B3940
#define CXWnd__IsReallyVisible_x                                   0x8B6CD0
#define CXWnd__IsType_x                                            0x8E1E00
#define CXWnd__Move_x                                              0x8B6430
#define CXWnd__Move1_x                                             0x8B8A00
#define CXWnd__ProcessTransition_x                                 0x8B2EC0
#define CXWnd__Refade_x                                            0x8B2CA0
#define CXWnd__Resize_x                                            0x8B3C80
#define CXWnd__Right_x                                             0x8B81A0
#define CXWnd__SetFocus_x                                          0x8B5580
#define CXWnd__SetFont_x                                           0x8B2B40
#define CXWnd__SetKeyTooltip_x                                     0x8B3EF0
#define CXWnd__SetMouseOver_x                                      0x8B86F0
#define CXWnd__StartFade_x                                         0x8B2F70
#define CXWnd__GetChildItem_x                                      0x8B8630

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A9B80
#define CXWndManager__DrawWindows_x                                0x8A97C0
#define CXWndManager__GetKeyboardFlags_x                           0x8A7D70
#define CXWndManager__HandleKeyboardMsg_x                          0x8A86E0
#define CXWndManager__RemoveWnd_x                                  0x8A83D0

// CDBStr
#define CDBStr__GetString_x                                        0x4A03F0

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44BCA0
#define EQ_Character__Cur_HP_x                                     0x461A00
#define EQ_Character__GetAACastingTimeModifier_x                   0x444D70
#define EQ_Character__GetCharInfo2_x                               0x829700
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43D0D0
#define EQ_Character__GetFocusRangeModifier_x                      0x43D2B0
#define EQ_Character__Max_Endurance_x                              0x5B1810
#define EQ_Character__Max_HP_x                                     0x457CE0
#define EQ_Character__Max_Mana_x                                   0x5B1640
#define EQ_Character__doCombatAbility_x                            0x5AEC30
#define EQ_Character__UseSkill_x                                   0x46C530
#define EQ_Character__GetConLevel_x                                0x5A3ED0
#define EQ_Character__IsExpansionFlag_x                            0x420160
#define EQ_Character__TotalEffect_x                                0x449DD0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x5845D0
#define EQ_Item__CreateItemTagString_x                             0x808B00
#define EQ_Item__IsStackable_x                                     0x7FD0C0
#define EQ_Item__GetImageNum_x                                     0x7FFD70

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4BFCA0
#define EQ_LoadingS__Array_x                                       0xBA2280

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B2FB0
#define EQ_PC__GetAltAbilityIndex_x                                0x811B00
#define EQ_PC__GetCombatAbility_x                                  0x811B90
#define EQ_PC__GetCombatAbilityTimer_x                             0x811C40
#define EQ_PC__GetItemTimerValue_x                                 0x5ACA00
#define EQ_PC__HasLoreItem_x                                       0x5A7210
#define EQ_PC__AlertInventoryChanged_x                             0x5A3EA0
#define EQ_PC__GetPcZoneClient_x                                   0x5CD3F0
#define EQ_PC__RemoveMyAffect_x                                    0x5ABF10

// EQItemList 
#define EQItemList__EQItemList_x                                   0x501AD0
#define EQItemList__add_item_x                                     0x501A10
#define EQItemList__delete_item_x                                  0x501ED0
#define EQItemList__FreeItemList_x                                 0x501DD0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x49F6E0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5B8450
#define EQPlayer__dEQPlayer_x                                      0x5C1270
#define EQPlayer__DoAttack_x                                       0x5D3270
#define EQPlayer__EQPlayer_x                                       0x5C3690
#define EQPlayer__SetNameSpriteState_x                             0x5BDF40
#define EQPlayer__SetNameSpriteTint_x                              0x5B9820
#define EQPlayer__IsBodyType_j_x                                   0x912C10
#define EQPlayer__IsTargetable_x                                   0x9134D0
#define EQPlayer__CanSee_x                                         0x9139F0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5C7990
#define EQPlayerManager__GetSpawnByName_x                          0x5C7DF0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x58A7F0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x58A830
#define KeypressHandler__ClearCommandStateArray_x                  0x58A3D0
#define KeypressHandler__HandleKeyDown_x                           0x588D30
#define KeypressHandler__HandleKeyUp_x                             0x589050
#define KeypressHandler__SaveKeymapping_x                          0x58A4A0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6F9FA0
#define MapViewMap__SaveEx_x                                       0x6FD880

#define PlayerPointManager__GetAltCurrency_x                       0x8246A0

// StringTable 
#define StringTable__getString_x                                   0x81F070

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B12C0

//Doors
#define EQSwitch__UseSwitch_x                                      0x540200

//IconCache
#define IconCache__GetIcon_x                                       0x6950B0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x68BF50
#define CContainerMgr__CloseContainer_x                            0x68C770

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x75B020

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x57D930

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D25D0
#define EQ_Spell__SpellAffects_x                                   0x4D2670
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D26A0
#define CharacterZoneClient__CalcAffectChange_x                    0x446090
#define CLootWnd__LootAll_x                                        0x6EF980
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A0950
#define CTargetWnd__WndNotification_x                              0x7A0440

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7A5B10
