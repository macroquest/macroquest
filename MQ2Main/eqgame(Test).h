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
#define __ExpectedVersionDate                                     "Feb 19 2015"
#define __ExpectedVersionTime                                     "12:25:53"
#define __ActualVersionDate_x                                      0xA78090
#define __ActualVersionTime_x                                      0xA7809C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x58F5C0
#define __MemChecker1_x                                            0x857DC0
#define __MemChecker2_x                                            0x627190
#define __MemChecker3_x                                            0x6270E0
#define __MemChecker4_x                                            0x7DB9B0
#define __EncryptPad0_x                                            0xBF3ED0
#define __EncryptPad1_x                                            0xD781E8
#define __EncryptPad2_x                                            0xC3CE50
#define __EncryptPad3_x                                            0xC3CA50
#define __EncryptPad4_x                                            0xD54910
#define __AC1_x                                                    0x798F35
#define __AC2_x                                                    0x545787
#define __AC3_x                                                    0x559F80
#define __AC4_x                                                    0x5603C0
#define __AC5_x                                                    0x56C16E
#define __AC6_x                                                    0x56FCC2
#define __AC7_x                                                    0x56685C
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
#define __do_loot_x                                                0x50D230
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
#define __CastRay_x                                                0x524C20
#define __ConvertItemTags_x                                        0x511EB0
#define __ExecuteCmd_x                                             0x4FC890
#define __EQGetTime_x                                              0x8580E0
#define __get_melee_range_x                                        0x503560
#define __GetGaugeValueFromEQ_x                                    0x797C80
#define __GetLabelFromEQ_x                                         0x798EC0
#define __ToggleMount_x                                            0x6C17F0
#define __GetXTargetType_x                                         0x916990
#define __LoadFrontEnd_x                                           0x626840
#define __NewUIINI_x                                               0x797590
#define __ProcessGameEvents_x                                      0x5685C0
#define __ProcessMouseEvent_x                                      0x567D60
#define CrashDetected_x                                            0x628310
#define wwsCrashReportCheckForUploader_x                           0x7ECDF0
#define DrawNetStatus_x                                            0x59EEB0
#define Util__FastTime_x                                           0x857C30
#define Expansion_HoT_x                                            0xF9995C
#define __HelpPath_x                                               0x101D0C0
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4BD4D0
#define AltAdvManager__IsAbilityReady_x                            0x4BD540
#define AltAdvManager__GetAltAbility_x                             0x4BD900

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x461EC0
#define CharacterZoneClient__MakeMeVisible_x                       0x466F80

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x656040

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x664680

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x57E680

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x67F3E0
#define CChatManager__InitContextMenu_x                            0x67FF00

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8C7B20
#define CContextMenu__AddMenuItem_x                                0x8C7D40
#define CContextMenu__dCContextMenu_x                              0x8C7D30
#define CContextMenu__RemoveMenuItem_x                             0x8C8030
#define CContextMenu__RemoveAllMenuItems_x                         0x8C8050
#define CContextMenuManager__AddMenu_x                             0x8CAD20
#define CContextMenuManager__RemoveMenu_x                          0x8CB070
#define CContextMenuManager__PopupMenu_x                           0x8CB4C0
#define CContextMenuManager__Flush_x                               0x8CAD90

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x83E850
#define CChatService__GetFriendName_x                              0x83E860

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x684F60
#define CChatWindow__Clear_x                                       0x684B20
#define CChatWindow__WndNotification_x                             0x685490

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BB0F0
#define CComboWnd__Draw_x                                          0x8BB300
#define CComboWnd__GetCurChoice_x                                  0x8BAEC0
#define CComboWnd__GetListRect_x                                   0x8BB5A0
#define CComboWnd__GetTextRect_x                                   0x8BB160
#define CComboWnd__InsertChoice_x                                  0x8BB610
#define CComboWnd__SetColors_x                                     0x8BAE50
#define CComboWnd__SetChoice_x                                     0x8BAE80

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x68E660
#define CContainerWnd__vftable_x                                   0xA817E8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4ABDB0
#define CDisplay__GetClickedActor_x                                0x4A4940
#define CDisplay__GetUserDefinedColor_x                            0x4A3200
#define CDisplay__GetWorldFilePath_x                               0x4A2650
#define CDisplay__is3dON_x                                         0x4A1A20
#define CDisplay__ReloadUI_x                                       0x4B71B0
#define CDisplay__WriteTextHD2_x                                   0x4A8150

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8DECA0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8CD080
#define CEditWnd__GetCharIndexPt_x                                 0x8CE0B0
#define CEditWnd__GetDisplayString_x                               0x8CD230
#define CEditWnd__GetHorzOffset_x                                  0x8CD570
#define CEditWnd__GetLineForPrintableChar_x                        0x8CDB70
#define CEditWnd__GetSelStartPt_x                                  0x8CE370
#define CEditWnd__GetSTMLSafeText_x                                0x8CD710
#define CEditWnd__PointFromPrintableChar_x                         0x8CDC60
#define CEditWnd__SelectableCharFromPoint_x                        0x8CDDE0
#define CEditWnd__SetEditable_x                                    0x8CD6E0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x545ED0
#define CEverQuest__DoTellWindow_x                                 0x54B8D0
#define CEverQuest__DropHeldItemOnGround_x                         0x554400
#define CEverQuest__dsp_chat_x                                     0x54D070
#define CEverQuest__Emote_x                                        0x54D2D0
#define CEverQuest__EnterZone_x                                    0x560BE0
#define CEverQuest__GetBodyTypeDesc_x                              0x542730
#define CEverQuest__GetClassDesc_x                                 0x548440
#define CEverQuest__GetClassThreeLetterCode_x                      0x548A40
#define CEverQuest__GetDeityDesc_x                                 0x543010
#define CEverQuest__GetLangDesc_x                                  0x542AC0
#define CEverQuest__GetRaceDesc_x                                  0x548C00
#define CEverQuest__InterpretCmd_x                                 0x54DBB0
#define CEverQuest__LeftClickedOnPlayer_x                          0x564CC0
#define CEverQuest__LMouseUp_x                                     0x566DB0
#define CEverQuest__RightClickedOnPlayer_x                         0x5657C0
#define CEverQuest__RMouseUp_x                                     0x566810
#define CEverQuest__SetGameState_x                                 0x546580
#define CEverQuest__UPCNotificationFlush_x                         0x54ED50
#define CEverQuest__IssuePetCommand_x                              0x54E8B0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x69F170
#define CGaugeWnd__CalcLinesFillRect_x                             0x69F1D0
#define CGaugeWnd__Draw_x                                          0x69F600

// CGuild
#define CGuild__FindMemberByName_x                                 0x4338A0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6BC260

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6C9FE0
#define CInvSlotMgr__MoveItem_x                                    0x6CAF10
#define CInvSlotMgr__SelectSlot_x                                  0x6CA090

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6C9480
#define CInvSlot__SliderComplete_x                                 0x6C6E50
#define CInvSlot__GetItemBase_x                                    0x6C62F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6CC0A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x794790
#define CItemDisplayWnd__UpdateStrings_x                           0x6CD3D0

// CLabel 
#define CLabel__Draw_x                                             0x6E80C0

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8A4220
#define CListWnd__dCListWnd_x                                      0x8A52B0
#define CListWnd__AddColumn_x                                      0x8A5250
#define CListWnd__AddColumn1_x                                     0x8A4A30
#define CListWnd__AddLine_x                                        0x8A44E0
#define CListWnd__AddString_x                                      0x8A46F0
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A1560
#define CListWnd__CalculateVSBRange_x                              0x8A36E0
#define CListWnd__ClearAllSel_x                                    0x8A0810
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8A40B0
#define CListWnd__Compare_x                                        0x8A2070
#define CListWnd__Draw_x                                           0x8A32F0
#define CListWnd__DrawColumnSeparators_x                           0x8A3180
#define CListWnd__DrawHeader_x                                     0x8A0B20
#define CListWnd__DrawItem_x                                       0x8A26B0
#define CListWnd__DrawLine_x                                       0x8A2E20
#define CListWnd__DrawSeparator_x                                  0x8A3220
#define CListWnd__EnsureVisible_x                                  0x8A16C0
#define CListWnd__ExtendSel_x                                      0x8A25C0
#define CListWnd__GetColumnMinWidth_x                              0x8A0230
#define CListWnd__GetColumnWidth_x                                 0x8A0150
#define CListWnd__GetCurSel_x                                      0x89F910
#define CListWnd__GetItemAtPoint_x                                 0x8A1960
#define CListWnd__GetItemAtPoint1_x                                0x8A19D0
#define CListWnd__GetItemData_x                                    0x89FC60
#define CListWnd__GetItemHeight_x                                  0x8A11B0
#define CListWnd__GetItemIcon_x                                    0x89FE40
#define CListWnd__GetItemRect_x                                    0x8A17A0
#define CListWnd__GetItemText_x                                    0x89FCF0
#define CListWnd__GetSelList_x                                     0x8A4920
#define CListWnd__GetSeparatorRect_x                               0x8A1F90
#define CListWnd__RemoveLine_x                                     0x8A48D0
#define CListWnd__SetColors_x                                      0x89FA60
#define CListWnd__SetColumnJustification_x                         0x8A0500
#define CListWnd__SetColumnWidth_x                                 0x8A01E0
#define CListWnd__SetCurSel_x                                      0x89F950
#define CListWnd__SetItemColor_x                                   0x8A3D90
#define CListWnd__SetItemData_x                                    0x8A08C0
#define CListWnd__SetItemText_x                                    0x8A3BD0
#define CListWnd__ShiftColumnSeparator_x                           0x8A3A60
#define CListWnd__Sort_x                                           0x8A53B0
#define CListWnd__ToggleSel_x                                      0x8A0790

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x7014B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x722760
#define CMerchantWnd__RequestBuyItem_x                             0x729590
#define CMerchantWnd__RequestSellItem_x                            0x72A000
#define CMerchantWnd__SelectRecoverySlot_x                         0x722A10
#define CMerchantWnd__SelectBuySellSlot_x                          0x721C70
#define CMerchantWnd__ActualSelect_x                               0x7264C0

// CObfuscator
#define CObfuscator__doit_x                                        0x81EA50

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8C2A20
#define CSidlManager__CreateLabel_x                                0x78A7B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x64D1E0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x64D0C0
#define CSidlScreenWnd__ConvertToRes_x                             0x8DEB80
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8AE440
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8AF960
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8AFA10
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8AEEC0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8ADE10
#define CSidlScreenWnd__EnableIniStorage_x                         0x8AD560
#define CSidlScreenWnd__GetSidlPiece_x                             0x8AE000
#define CSidlScreenWnd__Init1_x                                    0x8AF630
#define CSidlScreenWnd__LoadIniInfo_x                              0x8AE4F0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8AD720
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8AF110
#define CSidlScreenWnd__StoreIniInfo_x                             0x8AD020
#define CSidlScreenWnd__StoreIniVis_x                              0x8AD4F0
#define CSidlScreenWnd__WndNotification_x                          0x8AF3B0
#define CSidlScreenWnd__GetChildItem_x                             0x8AD630
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B3A60

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5E8A00
#define CSkillMgr__GetSkillCap_x                                   0x5E8BA0
#define CSkillMgr__GetNameToken_x                                  0x5E8670

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8DDE20
#define CSliderWnd__SetValue_x                                     0x8DDFF0
#define CSliderWnd__SetNumTicks_x                                  0x8DE770

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x792430

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8D87C0
#define CStmlWnd__CalculateHSBRange_x                              0x8D0D60
#define CStmlWnd__CalculateVSBRange_x                              0x8D0CD0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D0EE0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D17C0
#define CStmlWnd__ForceParseNow_x                                  0x8D9110
#define CStmlWnd__GetNextTagPiece_x                                0x8D16C0
#define CStmlWnd__GetSTMLText_x                                    0x6843C0
#define CStmlWnd__GetVisibleText_x                                 0x8D2210
#define CStmlWnd__InitializeWindowVariables_x                      0x8D45A0
#define CStmlWnd__MakeStmlColorTag_x                               0x8CFFD0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D0030
#define CStmlWnd__SetSTMLText_x                                    0x8D5E00
#define CStmlWnd__StripFirstSTMLLines_x                            0x8D8460
#define CStmlWnd__UpdateHistoryString_x                            0x8D3150

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E0390
#define CTabWnd__DrawCurrentPage_x                                 0x8DFC00
#define CTabWnd__DrawTab_x                                         0x8DF9C0
#define CTabWnd__GetCurrentPage_x                                  0x8DFFD0
#define CTabWnd__GetPageInnerRect_x                                0x8DF6B0
#define CTabWnd__GetTabInnerRect_x                                 0x8DF8B0
#define CTabWnd__GetTabRect_x                                      0x8DF780
#define CTabWnd__InsertPage_x                                      0x8E0680
#define CTabWnd__SetPage_x                                         0x8E0000
#define CTabWnd__SetPageRect_x                                     0x8E02D0
#define CTabWnd__UpdatePage_x                                      0x8E0620

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x42F5C0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BAAC0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8E5560

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x89DA20

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x414DE0
#define CXStr__CXStr1_x                                            0x4D5EB0
#define CXStr__CXStr3_x                                            0x854CC0
#define CXStr__dCXStr_x                                            0x4BEC50
#define CXStr__operator_equal_x                                    0x854E30
#define CXStr__operator_equal1_x                                   0x854E80
#define CXStr__operator_plus_equal1_x                              0x855F60

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B2CA0
#define CXWnd__Center_x                                            0x8B8DC0
#define CXWnd__ClrFocus_x                                          0x8B2880
#define CXWnd__DoAllDrawing_x                                      0x8B8A10
#define CXWnd__DrawChildren_x                                      0x8B8BB0

#define CXWnd__DrawColoredRect_x                                   0x8B3040
#define CXWnd__DrawTooltip_x                                       0x8B32F0
#define CXWnd__DrawTooltipAtPoint_x                                0x8B7990
#define CXWnd__GetBorderFrame_x                                    0x8B3730
#define CXWnd__GetChildWndAt_x                                     0x8B9780
#define CXWnd__GetClientClipRect_x                                 0x8B3500
#define CXWnd__GetScreenClipRect_x                                 0x8B8090
#define CXWnd__GetScreenRect_x                                     0x8B3910
#define CXWnd__GetTooltipRect_x                                    0x8B3180
#define CXWnd__GetWindowTextA_x                                    0x420C10
#define CXWnd__IsActive_x                                          0x8A8090
#define CXWnd__IsDescendantOf_x                                    0x8B3670
#define CXWnd__IsReallyVisible_x                                   0x8B69B0
#define CXWnd__IsType_x                                            0x8E1D40
#define CXWnd__Move_x                                              0x8B6110
#define CXWnd__Move1_x                                             0x8B86C0
#define CXWnd__ProcessTransition_x                                 0x8B2C40
#define CXWnd__Refade_x                                            0x8B2A10
#define CXWnd__Resize_x                                            0x8B39D0
#define CXWnd__Right_x                                             0x8B7E90
#define CXWnd__SetFocus_x                                          0x8B5260
#define CXWnd__SetFont_x                                           0x8B28D0
#define CXWnd__SetKeyTooltip_x                                     0x8B3C30
#define CXWnd__SetMouseOver_x                                      0x8B83D0
#define CXWnd__StartFade_x                                         0x8B2CF0
#define CXWnd__GetChildItem_x                                      0x8B8310

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A99A0
#define CXWndManager__DrawWindows_x                                0x8A95F0
#define CXWndManager__GetKeyboardFlags_x                           0x8A7BC0
#define CXWndManager__HandleKeyboardMsg_x                          0x8A8520
#define CXWndManager__RemoveWnd_x                                  0x8A8220

// CDBStr
#define CDBStr__GetString_x                                        0x49FE80

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44B840
#define EQ_Character__Cur_HP_x                                     0x461590
#define EQ_Character__GetAACastingTimeModifier_x                   0x444940
#define EQ_Character__GetCharInfo2_x                               0x829240
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43CC80
#define EQ_Character__GetFocusRangeModifier_x                      0x43CE60
#define EQ_Character__Max_Endurance_x                              0x5B0CE0
#define EQ_Character__Max_HP_x                                     0x457890
#define EQ_Character__Max_Mana_x                                   0x5B0B10
#define EQ_Character__doCombatAbility_x                            0x5AE110
#define EQ_Character__UseSkill_x                                   0x46C0B0
#define EQ_Character__GetConLevel_x                                0x5A3580
#define EQ_Character__IsExpansionFlag_x                            0x420150
#define EQ_Character__TotalEffect_x                                0x449970

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x583E20
#define EQ_Item__CreateItemTagString_x                             0x808860
#define EQ_Item__IsStackable_x                                     0x7FC9F0
#define EQ_Item__GetImageNum_x                                     0x7FF670

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4BF5E0
#define EQ_LoadingS__Array_x                                       0xBA2280

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B2470
#define EQ_PC__GetAltAbilityIndex_x                                0x8117A0
#define EQ_PC__GetCombatAbility_x                                  0x811830
#define EQ_PC__GetCombatAbilityTimer_x                             0x8118E0
#define EQ_PC__GetItemTimerValue_x                                 0x5ABEE0
#define EQ_PC__HasLoreItem_x                                       0x5A68D0
#define EQ_PC__AlertInventoryChanged_x                             0x5A3550
#define EQ_PC__GetPcZoneClient_x                                   0x5CCA00
#define EQ_PC__RemoveMyAffect_x                                    0x5AB3F0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x501560
#define EQItemList__add_item_x                                     0x5014A0
#define EQItemList__delete_item_x                                  0x501960
#define EQItemList__FreeItemList_x                                 0x501860

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x49F160

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5B7910
#define EQPlayer__dEQPlayer_x                                      0x5C0720
#define EQPlayer__DoAttack_x                                       0x5D2870
#define EQPlayer__EQPlayer_x                                       0x5C2B40
#define EQPlayer__SetNameSpriteState_x                             0x5BD400
#define EQPlayer__SetNameSpriteTint_x                              0x5B8CE0
#define EQPlayer__IsBodyType_j_x                                   0x912BA0
#define EQPlayer__IsTargetable_x                                   0x913460
#define EQPlayer__CanSee_x                                         0x913980

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5C6F90
#define EQPlayerManager__GetSpawnByName_x                          0x5C73F0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x589FC0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x58A000
#define KeypressHandler__ClearCommandStateArray_x                  0x589BA0
#define KeypressHandler__HandleKeyDown_x                           0x588500
#define KeypressHandler__HandleKeyUp_x                             0x588820
#define KeypressHandler__SaveKeymapping_x                          0x589C70

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6F9890
#define MapViewMap__SaveEx_x                                       0x6FD170

#define PlayerPointManager__GetAltCurrency_x                       0x824210

// StringTable 
#define StringTable__getString_x                                   0x81ECF0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B0790

//Doors
#define EQSwitch__UseSwitch_x                                      0x53FB70

//IconCache
#define IconCache__GetIcon_x                                       0x694B10

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x68B970
#define CContainerMgr__CloseContainer_x                            0x68C190

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x75AA40

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x57D140

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D1CD0
#define EQ_Spell__SpellAffects_x                                   0x4D1D70
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D1DA0
#define CharacterZoneClient__CalcAffectChange_x                    0x445C60
#define CLootWnd__LootAll_x                                        0x6EF240
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A01F0
#define CTargetWnd__WndNotification_x                              0x79FCE0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7A53C0
