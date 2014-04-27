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
#define __ExpectedVersionDate                                     "Nov 26 2012"
#define __ExpectedVersionTime                                     "17:10:20"
#define __ActualVersionDate_x                                      0x9CF740
#define __ActualVersionTime_x                                      0x9CF74C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x55FE20
#define __MemChecker1_x                                            0x800CA0
#define __MemChecker2_x                                            0x5F4F10
#define __MemChecker3_x                                            0x5F4E60
#define __MemChecker4_x                                            0x8C37E0
#define __EncryptPad0_x                                            0xAD3B70
#define __EncryptPad1_x                                            0xB4EAE0
#define __EncryptPad2_x                                            0xAECAD0
#define __EncryptPad3_x                                            0xAEC6D0
#define __EncryptPad4_x                                            0xB54290
#define __AC1_x                                                    0x75BF80
#define __AC2_x                                                    0x514B77
#define __AC3_x                                                    0x527EA0
#define __AC4_x                                                    0x52DF04
#define __AC5_x                                                    0x539CBD
#define __AC6_x                                                    0x53D6B2
#define __AC7_x                                                    0x533CAC
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0xDE7A78
#define DI8__Keyboard_x                                            0xDE7A7C
#define DI8__Mouse_x                                               0xDE7A80
#define __AltTimerReady_x                                          0xD50CA1
#define __Attack_x                                                 0xDE3822
#define __Autofire_x                                               0xDE3823
#define __BindList_x                                               0xABBE50
#define __Clicks_x                                                 0xD5F9B4
#define __CommandList_x                                            0xABD49C
#define __CurrentMapLabel_x                                        0xEF3758
#define __CurrentSocial_x                                          0xAA7688
#define __DoAbilityList_x                                          0xD960C8
#define __do_loot_x                                                0x4E3CB0
#define __DrawHandler_x                                            0x1553B04
#define __GroupCount_x                                             0xD5037A

#define __Guilds_x                                                 0xD55F80
#define __gWorld_x                                                 0xD52834
#define __HotkeyPage_x                                             0xDDCAC8
#define __HWnd_x                                                   0xDE77D0
#define __InChatMode_x                                             0xD5F8EC
#define __LastTell_x                                               0xD617D0
#define __LMouseHeldTime_x                                         0xD5FA20
#define __Mouse_x                                                  0xDE7A84
#define __MouseLook_x                                              0xD5F982
#define __MouseEventTime_x                                         0xDE3B74
#define __NetStatusToggle_x                                        0xD5F985
#define __PCNames_x                                                0xD60E44
#define __RangeAttackReady_x                                       0xD60ADC
#define __RMouseHeldTime_x                                         0xD5FA1C
#define __RunWalkState_x                                           0xD5F8F0
#define __ScreenMode_x                                             0xC9F778
#define __ScreenX_x                                                0xD5F8A4
#define __ScreenY_x                                                0xD5F8A0
#define __ScreenXMax_x                                             0xD5F8A8
#define __ScreenYMax_x                                             0xD5F8AC
#define __ServerHost_x                                             0xD502C4
#define __ServerName_x                                             0xD96088
#define __ShiftKeyDown_x                                           0xD5FF78
#define __ShowNames_x                                              0xD60CE8
#define __Socials_x                                                0xD96188


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xD52918
#define instEQZoneInfo_x                                           0xD5FB70
#define instKeypressHandler_x                                      0xDE3B58
#define pinstActiveBanker_x                                        0xD528D8
#define pinstActiveCorpse_x                                        0xD528DC
#define pinstActiveGMaster_x                                       0xD528E0
#define pinstActiveMerchant_x                                      0xD528D4
#define pinstAggroInfo_x                                           0xB66180
#define pinstAltAdvManager_x                                       0xCA06E0
#define pinstAuraMgr_x                                             0xB6F968
#define pinstBandageTarget_x                                       0xD528C0
#define pinstCamActor_x                                            0xCA014C
#define pinstCDBStr_x                                              0xC9F750
#define pinstCDisplay_x                                            0xD528E8
#define pinstCEverQuest_x                                          0xDE7BFC
#define pinstCharData_x                                            0xD528A4
#define pinstCharSpawn_x                                           0xD528CC
#define pinstControlledMissile_x                                   0xD528A0
#define pinstControlledPlayer_x                                    0xD528CC
#define pinstCSidlManager_x                                        0x1553180
#define pinstCXWndManager_x                                        0x1553178
#define instDynamicZone_x                                          0xD5F758
#define pinstDZMember_x                                            0xD5F868
#define pinstDZTimerInfo_x                                         0xD5F86C
#define pinstEQItemList_x                                          0xD4F420
#define instEQMisc_x                                               0xAB0630
#define pinstEQSoundManager_x                                      0xCA0788
#define instExpeditionLeader_x                                     0xD5F7A2
#define instExpeditionName_x                                       0xD5F7E2
#define pinstGroup_x                                               0xD50376
#define pinstImeManager_x                                          0x1553184
#define pinstLocalPlayer_x                                         0xD528B8
#define pinstMercenaryData_x                                       0xDE3FD0
#define pinstModelPlayer_x                                         0xD528E4
#define pinstPCData_x                                              0xD528A4
#define pinstSkillMgr_x                                            0xDE4610
#define pinstSpawnManager_x                                        0xDE4270
#define pinstSpellManager_x                                        0xDE4688
#define pinstSpellSets_x                                           0xDDCB2C
#define pinstStringTable_x                                         0xD5284C
#define pinstSwitchManager_x                                       0xD4FF90
#define pinstTarget_x                                              0xD528D0
#define pinstTargetObject_x                                        0xD528A8
#define pinstTargetSwitch_x                                        0xD528AC
#define pinstTaskMember_x                                          0xC9F700
#define pinstTrackTarget_x                                         0xD528C4
#define pinstTradeTarget_x                                         0xD528B4
#define instTributeActive_x                                        0xAB0655
#define pinstViewActor_x                                           0xCA0148
#define pinstWorldData_x                                           0xD52888


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xB66368
#define pinstCAudioTriggersWindow_x                                0xB662D0
#define pinstCCharacterSelect_x                                    0xC9FFF4
#define pinstCFacePick_x                                           0xC9FDA4
#define pinstCNoteWnd_x                                            0xC9FFAC
#define pinstCBookWnd_x                                            0xC9FFB4
#define pinstCPetInfoWnd_x                                         0xC9FFB8
#define pinstCTrainWnd_x                                           0xC9FFBC
#define pinstCSkillsWnd_x                                          0xC9FFC0
#define pinstCSkillsSelectWnd_x                                    0xC9FFC4
#define pinstCCombatSkillSelectWnd_x                               0xC9FFC8
#define pinstCFriendsWnd_x                                         0xC9FFCC
#define pinstCAuraWnd_x                                            0xC9FFD0
#define pinstCRespawnWnd_x                                         0xC9FFD4
#define pinstCBandolierWnd_x                                       0xC9FFD8
#define pinstCPotionBeltWnd_x                                      0xC9FFDC
#define pinstCAAWnd_x                                              0xC9FFE0
#define pinstCGroupSearchFiltersWnd_x                              0xC9FFE4
#define pinstCLoadskinWnd_x                                        0xC9FFE8
#define pinstCAlarmWnd_x                                           0xC9FFEC
#define pinstCMusicPlayerWnd_x                                     0xC9FFF0
#define pinstCMailWnd_x                                            0xC9FFF8
#define pinstCMailCompositionWnd_x                                 0xC9FFFC
#define pinstCMailAddressBookWnd_x                                 0xCA0000
#define pinstCRaidWnd_x                                            0xCA0008
#define pinstCRaidOptionsWnd_x                                     0xCA000C
#define pinstCBreathWnd_x                                          0xCA0010
#define pinstCMapViewWnd_x                                         0xCA0014
#define pinstCMapToolbarWnd_x                                      0xCA0018
#define pinstCEditLabelWnd_x                                       0xCA001C
#define pinstCTargetWnd_x                                          0xCA0020
#define pinstCColorPickerWnd_x                                     0xCA0024
#define pinstCPlayerWnd_x                                          0xCA0028
#define pinstCOptionsWnd_x                                         0xCA002C
#define pinstCBuffWindowNORMAL_x                                   0xCA0030
#define pinstCBuffWindowSHORT_x                                    0xCA0034
#define pinstCharacterCreation_x                                   0xCA0038
#define pinstCCursorAttachment_x                                   0xCA003C
#define pinstCCastingWnd_x                                         0xCA0040
#define pinstCCastSpellWnd_x                                       0xCA0044
#define pinstCSpellBookWnd_x                                       0xCA0048
#define pinstCInventoryWnd_x                                       0xCA004C
#define pinstCBankWnd_x                                            0xCA0050
#define pinstCQuantityWnd_x                                        0xCA0054
#define pinstCLootWnd_x                                            0xCA0058
#define pinstCActionsWnd_x                                         0xCA005C
#define pinstCCombatAbilityWnd_x                                   0xCA0060
#define pinstCMerchantWnd_x                                        0xCA0064
#define pinstCTradeWnd_x                                           0xCA0068
#define pinstCSelectorWnd_x                                        0xCA006C
#define pinstCBazaarWnd_x                                          0xCA0070
#define pinstCBazaarSearchWnd_x                                    0xCA0074
#define pinstCGiveWnd_x                                            0xCA0090
#define pinstCTrackingWnd_x                                        0xCA0098
#define pinstCInspectWnd_x                                         0xCA009C
#define pinstCSocialEditWnd_x                                      0xCA00A0
#define pinstCFeedbackWnd_x                                        0xCA00A4
#define pinstCBugReportWnd_x                                       0xCA00A8
#define pinstCVideoModesWnd_x                                      0xCA00AC
#define pinstCTextEntryWnd_x                                       0xCA00B4
#define pinstCFileSelectionWnd_x                                   0xCA00B8
#define pinstCCompassWnd_x                                         0xCA00BC
#define pinstCPlayerNotesWnd_x                                     0xCA00C0
#define pinstCGemsGameWnd_x                                        0xCA00C4
#define pinstCTimeLeftWnd_x                                        0xCA00C8
#define pinstCPetitionQWnd_x                                       0xCA00DC
#define pinstCSoulmarkWnd_x                                        0xCA00E0
#define pinstCStoryWnd_x                                           0xCA00E4
#define pinstCJournalTextWnd_x                                     0xCA00E8
#define pinstCJournalCatWnd_x                                      0xCA00EC
#define pinstCBodyTintWnd_x                                        0xCA00F0
#define pinstCServerListWnd_x                                      0xCA00F4
#define pinstCAvaZoneWnd_x                                         0xCA0100
#define pinstCBlockedBuffWnd_x                                     0xCA0104
#define pinstCBlockedPetBuffWnd_x                                  0xCA0108
#define pinstCInvSlotMgr_x                                         0xCA0140
#define pinstCContainerMgr_x                                       0xCA0144
#define pinstCAdventureLeaderboardWnd_x                            0xEF03B0
#define pinstCAdventureRequestWnd_x                                0xEF0398
#define pinstCAltStorageWnd_x                                      0xEF04F0
#define pinstCAdventureStatsWnd_x                                  0xEF03B0
#define pinstCBarterMerchantWnd_x                                  0xEF0930
#define pinstCBarterSearchWnd_x                                    0xEF0948
#define pinstCBarterWnd_x                                          0xEF0980
#define pinstCChatManager_x                                        0xEF0C58
#define pinstCDynamicZoneWnd_x                                     0xEF0E48
#define pinstCEQMainWnd_x                                          0xEF0F08
#define pinstCFellowshipWnd_x                                      0xEF0E24
#define pinstCFindLocationWnd_x                                    0xEF1038
#define pinstCGroupSearchWnd_x                                     0xEF1198
#define pinstCGroupWnd_x                                           0xEF11D0
#define pinstCGuildBankWnd_x                                       0xEF11E8
#define pinstCGuildMgmtWnd_x                                       0xEF3278
#define pinstCGuildTributeMasterWnd_x                              0xEF5018
#define pinstCHotButtonWnd_x                                       0xEF32CC
#define pinstCHotButtonWnd1_x                                      0xEF32CC
#define pinstCHotButtonWnd2_x                                      0xEF32D0
#define pinstCHotButtonWnd3_x                                      0xEF32D4
#define pinstCHotButtonWnd4_x                                      0xEF32F8
#define pinstCItemDisplayManager_x                                 0xEF3448
#define pinstCItemExpTransferWnd_x                                 0xEF3484
#define pinstCLeadershipWnd_x                                      0xEF35C8
#define pinstCLFGuildWnd_x                                         0xEF35E8
#define pinstCMIZoneSelectWnd_x                                    0xEF3888
#define pinstCAdventureMerchantWnd_x                               0xEF3B50
#define pinstCConfirmationDialog_x                                 0xEF3B70
#define pinstCPopupWndManager_x                                    0xEF3B70
#define pinstCProgressionSelectionWnd_x                            0xEF3BD8
#define pinstCPvPLeaderboardWnd_x                                  0xEF3C28
#define pinstCPvPStatsWnd_x                                        0xEF3C48
#define pinstCSystemInfoDialogBox_x                                0xEF3F30
#define pinstCTargetOfTargetWnd_x                                  0xEF4C94
#define pinstCTaskSelectWnd_x                                      0xEF3DEC
#define pinstCTaskTemplateSelectWnd_x                              0xEF4D50
#define pinstCTaskWnd_x                                            0xEF4DA0
#define pinstCTipWndOFDAY_x                                        0xEF4E80
#define pinstCTipWndCONTEXT_x                                      0xEF4E84
#define pinstCTitleWnd_x                                           0xEF4EB8
#define pinstCTradeskillWnd_x                                      0xEF4F14
#define pinstCTributeBenefitWnd_x                                  0xEF4FE0
#define pinstCTributeMasterWnd_x                                   0xEF5018
#define pinstCContextMenuManager_x                                 0x1552D7C
#define pinstCVoiceMacroWnd_x                                      0xDE49D0
#define pinstCHtmlWnd_x                                            0xDE4A48


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x4F95C0
#define __ConvertItemTags_x                                        0x4E9530
#define __ExecuteCmd_x                                             0x4D39C0
#define __EQGetTime_x                                              0x801800
#define __get_melee_range_x                                        0x4DA590
#define __GetGaugeValueFromEQ_x                                    0x75ACF0
#define __GetLabelFromEQ_x                                         0x75BF20
#define __GetXTargetType_x                                         0x8CB320
#define __LoadFrontEnd_x                                           0x5F45C0
#define __NewUIINI_x                                               0x75A630
#define __ProcessGameEvents_x                                      0x535D20
#define CrashDetected_x                                            0x5F6C3B
#define DrawNetStatus_x                                            0x56F020
#define Util__FastTime_x                                           0x800B40
#define Expansion_HoT_x                                            0xD60C48
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A1350
#define AltAdvManager__IsAbilityReady_x                            0x4A1390
#define AltAdvManager__GetAltAbility_x                             0x4A1760

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x449FB0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6233A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x630500

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x54B990

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x64B580
#define CChatManager__InitContextMenu_x                            0x64C070

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x7A8AA0
#define CChatService__GetFriendName_x                              0x7E7AA0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x650DB0
#define CChatWindow__Clear_x                                       0x650960
#define CChatWindow__WndNotification_x                             0x651300

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8669D0
#define CComboWnd__Draw_x                                          0x866BA0
#define CComboWnd__GetCurChoice_x                                  0x8667F0
#define CComboWnd__GetListRect_x                                   0x866E40
#define CComboWnd__GetTextRect_x                                   0x866A30
#define CComboWnd__InsertChoice_x                                  0x866EB0
#define CComboWnd__SetColors_x                                     0x866780
#define CComboWnd__SetChoice_x                                     0x8667B0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x65A3C0
#define CContainerWnd__vftable_x                                   0x9D86B8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4914E0
#define CDisplay__GetClickedActor_x                                0x489640
#define CDisplay__GetUserDefinedColor_x                            0x487F10
#define CDisplay__GetWorldFilePath_x                               0x487340
#define CDisplay__is3dON_x                                         0x486420
#define CDisplay__ReloadUI_x                                       0x49B340
#define CDisplay__WriteTextHD2_x                                   0x48CA50

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x887460

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x876B80
#define CEditWnd__GetCharIndexPt_x                                 0x877B90
#define CEditWnd__GetDisplayString_x                               0x876D30
#define CEditWnd__GetHorzOffset_x                                  0x877070
#define CEditWnd__GetLineForPrintableChar_x                        0x877660
#define CEditWnd__GetSelStartPt_x                                  0x877E40
#define CEditWnd__GetSTMLSafeText_x                                0x877200
#define CEditWnd__PointFromPrintableChar_x                         0x877750
#define CEditWnd__SelectableCharFromPoint_x                        0x8778D0
#define CEditWnd__SetEditable_x                                    0x8771D0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x5152C0
#define CEverQuest__DoTellWindow_x                                 0x519B20
#define CEverQuest__DropHeldItemOnGround_x                         0x5223A0
#define CEverQuest__dsp_chat_x                                     0x51B2C0
#define CEverQuest__Emote_x                                        0x51B520
#define CEverQuest__EnterZone_x                                    0x52E090
#define CEverQuest__GetBodyTypeDesc_x                              0x511890
#define CEverQuest__GetClassDesc_x                                 0x510FF0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5115F0
#define CEverQuest__GetDeityDesc_x                                 0x5121A0
#define CEverQuest__GetLangDesc_x                                  0x511C20
#define CEverQuest__GetRaceDesc_x                                  0x511F10
#define CEverQuest__InterpretCmd_x                                 0x51BE00
#define CEverQuest__LeftClickedOnPlayer_x                          0x532240
#define CEverQuest__LMouseUp_x                                     0x534400
#define CEverQuest__RightClickedOnPlayer_x                         0x532CB0
#define CEverQuest__RMouseUp_x                                     0x533C60
#define CEverQuest__SetGameState_x                                 0x515970
#define CEverQuest__UPCNotificationFlush_x                         0x51CD90

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x669F20
#define CGaugeWnd__CalcLinesFillRect_x                             0x669F80
#define CGaugeWnd__Draw_x                                          0x66A3B0

// CGuild
#define CGuild__FindMemberByName_x                                 0x423CE0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x687100

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x691E60
#define CInvSlotMgr__MoveItem_x                                    0x692D00

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x691370
#define CInvSlot__SliderComplete_x                                 0x68F790
#define CInvSlot__GetItemBase_x                                    0x68EDA0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x693A20

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7579D0
#define CItemDisplayWnd__UpdateStrings_x                           0x694D40

// CLabel 
#define CLabel__Draw_x                                             0x6AE730

// CListWnd 
#define CListWnd__AddColumn_x                                      0x850730
#define CListWnd__AddColumn1_x                                     0x84FF30
#define CListWnd__AddLine_x                                        0x84F9E0
#define CListWnd__AddString_x                                      0x84FBF0
#define CListWnd__CalculateFirstVisibleLine_x                      0x84CAC0
#define CListWnd__CalculateVSBRange_x                              0x84EBD0
#define CListWnd__ClearAllSel_x                                    0x84BDA0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x84F5B0
#define CListWnd__Compare_x                                        0x84D5B0
#define CListWnd__Draw_x                                           0x84E830
#define CListWnd__DrawColumnSeparators_x                           0x84E6C0
#define CListWnd__DrawHeader_x                                     0x84C0B0
#define CListWnd__DrawItem_x                                       0x84DC00
#define CListWnd__DrawLine_x                                       0x84E360
#define CListWnd__DrawSeparator_x                                  0x84E760
#define CListWnd__EnsureVisible_x                                  0x84CC20
#define CListWnd__ExtendSel_x                                      0x84DB10
#define CListWnd__GetColumnMinWidth_x                              0x84B7C0
#define CListWnd__GetColumnWidth_x                                 0x84B6E0
#define CListWnd__GetCurSel_x                                      0x84AFB0
#define CListWnd__GetItemAtPoint_x                                 0x84CEB0
#define CListWnd__GetItemAtPoint1_x                                0x84CF20
#define CListWnd__GetItemData_x                                    0x84B1F0
#define CListWnd__GetItemHeight_x                                  0x84C730
#define CListWnd__GetItemIcon_x                                    0x84B3D0
#define CListWnd__GetItemRect_x                                    0x84CCF0
#define CListWnd__GetItemText_x                                    0x84B280
#define CListWnd__GetSelList_x                                     0x84FE20
#define CListWnd__GetSeparatorRect_x                               0x84D4E0
#define CListWnd__RemoveLine_x                                     0x84FDD0
#define CListWnd__SetColors_x                                      0x84B010
#define CListWnd__SetColumnJustification_x                         0x84BA90
#define CListWnd__SetColumnWidth_x                                 0x84B770
#define CListWnd__SetCurSel_x                                      0x84AFF0
#define CListWnd__SetItemColor_x                                   0x84F290
#define CListWnd__SetItemData_x                                    0x84BE50
#define CListWnd__SetItemText_x                                    0x84F0D0
#define CListWnd__ShiftColumnSeparator_x                           0x84EF60
#define CListWnd__Sort_x                                           0x850890
#define CListWnd__ToggleSel_x                                      0x84BD20

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6C9540

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6E88C0
#define CMerchantWnd__RequestBuyItem_x                             0x6EEAA0
#define CMerchantWnd__RequestSellItem_x                            0x715880
#define CMerchantWnd__SelectBuySellSlot_x                          0x6E8B70

// CObfuscator
#define CObfuscator__doit_x                                        0x7C8370

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x86C170
#define CSidlManager__CreateLabel_x                                0x74E1E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x61A610
#define CSidlScreenWnd__CalculateVSBRange_x                        0x61A530
#define CSidlScreenWnd__ConvertToRes_x                             0x887340
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x855780
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x856AA0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x856B50
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x856030
#define CSidlScreenWnd__DrawSidlPiece_x                            0x855260
#define CSidlScreenWnd__EnableIniStorage_x                         0x8549B0
#define CSidlScreenWnd__GetSidlPiece_x                             0x855450
#define CSidlScreenWnd__Init1_x                                    0x856770
#define CSidlScreenWnd__LoadIniInfo_x                              0x855830
#define CSidlScreenWnd__LoadIniListWnd_x                           0x854B70
#define CSidlScreenWnd__LoadSidlScreen_x                           0x856280
#define CSidlScreenWnd__StoreIniInfo_x                             0x854560
#define CSidlScreenWnd__StoreIniVis_x                              0x854940
#define CSidlScreenWnd__WndNotification_x                          0x8564F0
#define CSidlScreenWnd__GetChildItem_x                             0x854A80

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5B6470
#define CSkillMgr__GetSkillCap_x                                   0x5B64E0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x88D8D0
#define CSliderWnd__SetValue_x                                     0x88DAA0
#define CSliderWnd__SetNumTicks_x                                  0x88E220

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x755430

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x882560
#define CStmlWnd__CalculateHSBRange_x                              0x87A780
#define CStmlWnd__CalculateVSBRange_x                              0x87A810
#define CStmlWnd__CanBreakAtCharacter_x                            0x87A990
#define CStmlWnd__FastForwardToEndOfTag_x                          0x87B2E0
#define CStmlWnd__ForceParseNow_x                                  0x882BB0
#define CStmlWnd__GetNextTagPiece_x                                0x87B1E0
#define CStmlWnd__GetSTMLText_x                                    0x650200
#define CStmlWnd__GetVisibleText_x                                 0x87C4A0
#define CStmlWnd__InitializeWindowVariables_x                      0x87DD10
#define CStmlWnd__MakeStmlColorTag_x                               0x8799D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x879A30
#define CStmlWnd__SetSTMLText_x                                    0x87DE30
#define CStmlWnd__StripFirstSTMLLines_x                            0x882200
#define CStmlWnd__UpdateHistoryString_x                            0x87CDC0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x888C00
#define CTabWnd__DrawCurrentPage_x                                 0x888470
#define CTabWnd__DrawTab_x                                         0x888240
#define CTabWnd__GetCurrentPage_x                                  0x888840
#define CTabWnd__GetPageInnerRect_x                                0x887F30
#define CTabWnd__GetTabInnerRect_x                                 0x888130
#define CTabWnd__GetTabRect_x                                      0x888000
#define CTabWnd__InsertPage_x                                      0x888EF0
#define CTabWnd__SetPage_x                                         0x888870
#define CTabWnd__SetPageRect_x                                     0x888B40
#define CTabWnd__UpdatePage_x                                      0x888E90

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41F880

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x862460

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x862CF0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x849260

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x558690
#define CXStr__CXStr1_x                                            0x4B0390
#define CXStr__CXStr3_x                                            0x7FDBD0
#define CXStr__dCXStr_x                                            0x41CBC0
#define CXStr__operator_equal_x                                    0x7FDD40
#define CXStr__operator_equal1_x                                   0x7FDD90
#define CXStr__operator_plus_equal1_x                              0x7FEE70

// CXWnd 
#define CXWnd__BringToTop_x                                        0x85A6B0
#define CXWnd__Center_x                                            0x860830
#define CXWnd__ClrFocus_x                                          0x85A300
#define CXWnd__DoAllDrawing_x                                      0x860490
#define CXWnd__DrawChildren_x                                      0x860620
#define CXWnd__DrawColoredRect_x                                   0x85AA50
#define CXWnd__DrawTooltip_x                                       0x85ACF0
#define CXWnd__DrawTooltipAtPoint_x                                0x85F400
#define CXWnd__GetBorderFrame_x                                    0x85B170
#define CXWnd__GetChildWndAt_x                                     0x85E3E0
#define CXWnd__GetClientClipRect_x                                 0x85AF00
#define CXWnd__GetScreenClipRect_x                                 0x85FAF0
#define CXWnd__GetScreenRect_x                                     0x85B2B0
#define CXWnd__GetTooltipRect_x                                    0x85AB80
#define CXWnd__GetWindowTextA_x                                    0x410F90
#define CXWnd__IsActive_x                                          0x871B70
#define CXWnd__IsDescendantOf_x                                    0x85B040
#define CXWnd__IsReallyVisible_x                                   0x85E3C0
#define CXWnd__IsType_x                                            0x88A5C0
#define CXWnd__Move_x                                              0x85DAD0
#define CXWnd__Move1_x                                             0x860140
#define CXWnd__ProcessTransition_x                                 0x85A650
#define CXWnd__Refade_x                                            0x85A420
#define CXWnd__Resize_x                                            0x85B380
#define CXWnd__Right_x                                             0x85F8F0
#define CXWnd__SetFocus_x                                          0x85CC30
#define CXWnd__SetKeyTooltip_x                                     0x85B5E0
#define CXWnd__SetMouseOver_x                                      0x85FE40
#define CXWnd__StartFade_x                                         0x85A700
#define CXWnd__GetChildItem_x                                      0x85FD80

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x873280
#define CXWndManager__DrawWindows_x                                0x872EC0
#define CXWndManager__GetKeyboardFlags_x                           0x8716A0
#define CXWndManager__HandleKeyboardMsg_x                          0x871E20
#define CXWndManager__RemoveWnd_x                                  0x871C90

// CDBStr
#define CDBStr__GetString_x                                        0x484620

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8C7C70
#define EQ_Character__CastSpell_x                                  0x43A630
#define EQ_Character__Cur_HP_x                                     0x449C00
#define EQ_Character__GetAACastingTimeModifier_x                   0x433590
#define EQ_Character__GetCharInfo2_x                               0x7D3230
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42C900
#define EQ_Character__GetFocusRangeModifier_x                      0x42CAE0
#define EQ_Character__Max_Endurance_x                              0x57DBB0
#define EQ_Character__Max_HP_x                                     0x443DA0
#define EQ_Character__Max_Mana_x                                   0x57D9F0
#define EQ_Character__doCombatAbility_x                            0x57C450
#define EQ_Character__UseSkill_x                                   0x45A510
#define EQ_Character__GetConLevel_x                                0x5735C0
#define EQ_Character__IsExpansionFlag_x                            0x4104D0
#define EQ_Character__TotalEffect_x                                0x438840

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x550940
#define EQ_Item__CreateItemTagString_x                             0x7B3DF0
#define EQ_Item__IsStackable_x                                     0x7A86D0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A3340
#define EQ_LoadingS__Array_x                                       0xAB6B48

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x581EA0
#define EQ_PC__GetAltAbilityIndex_x                                0x7BC4D0
#define EQ_PC__GetCombatAbility_x                                  0x7BC560
#define EQ_PC__GetCombatAbilityTimer_x                             0x7BC610
#define EQ_PC__GetItemTimerValue_x                                 0x57C190
#define EQ_PC__HasLoreItem_x                                       0x576730

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4D8310
#define EQItemList__add_item_x                                     0x4D8250
#define EQItemList__delete_item_x                                  0x4D8720
#define EQItemList__FreeItemList_x                                 0x4D8610

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x483AB0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x587A40
#define EQPlayer__dEQPlayer_x                                      0x58C5B0
#define EQPlayer__DoAttack_x                                       0x5A0A40
#define EQPlayer__EQPlayer_x                                       0x591D00
#define EQPlayer__SetNameSpriteState_x                             0x589E70
#define EQPlayer__SetNameSpriteTint_x                              0x587AB0
#define EQPlayer__IsBodyType_j_x                                   0x8C7510
#define EQPlayer__IsTargetable_x                                   0x8C77E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5951A0
#define EQPlayerManager__GetSpawnByName_x                          0x595600

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5569C0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x556A00
#define KeypressHandler__ClearCommandStateArray_x                  0x5565A0
#define KeypressHandler__HandleKeyDown_x                           0x554F00
#define KeypressHandler__HandleKeyUp_x                             0x555220
#define KeypressHandler__SaveKeymapping_x                          0x556670

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6C1B50
#define MapViewMap__SaveEx_x                                       0x6C5360

#define PlayerPointManager__GetAltCurrency_x                       0x7CD380

// StringTable 
#define StringTable__getString_x                                   0x7C8610

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x580790
