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
#define __ExpectedVersionDate                                     "Nov  8 2012"
#define __ExpectedVersionTime                                     "21:31:35"
#define __ActualVersionDate_x                                      0x9C1AD0
#define __ActualVersionTime_x                                      0x9C1ADC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x55B0F0
#define __MemChecker1_x                                            0x7F3A90
#define __MemChecker2_x                                            0x5EFC30
#define __MemChecker3_x                                            0x5EFB80
#define __MemChecker4_x                                            0x8B6D90
#define __EncryptPad0_x                                            0xAC29D8
#define __EncryptPad1_x                                            0xB3D068
#define __EncryptPad2_x                                            0xADB780
#define __EncryptPad3_x                                            0xADB380
#define __EncryptPad4_x                                            0xB42820
#define __AC1_x                                                    0x7537E0
#define __AC2_x                                                    0x510157
#define __AC3_x                                                    0x523410
#define __AC4_x                                                    0x5293D4
#define __AC5_x                                                    0x53512B
#define __AC6_x                                                    0x538A52
#define __AC7_x                                                    0x52F14C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0xDD58E0
#define DI8__Keyboard_x                                            0xDD58E4
#define DI8__Mouse_x                                               0xDD58E8
#define __AltTimerReady_x                                          0xD3EB29
#define __Attack_x                                                 0xDD169A
#define __Autofire_x                                               0xDD169B
#define __BindList_x                                               0xAAAE70
#define __Clicks_x                                                 0xD4D83C
#define __CommandList_x                                            0xAAC4C0
#define __CurrentMapLabel_x                                        0xEE1740
#define __CurrentSocial_x                                          0xA967DC
#define __DoAbilityList_x                                          0xD83F40
#define __do_loot_x                                                0x4DF630
#define __DrawHandler_x                                            0x153F564
#define __GroupCount_x                                             0xD3E202

#define __Guilds_x                                                 0xD43E08
#define __gWorld_x                                                 0xD406BC
#define __HotkeyPage_x                                             0xDCA940
#define __HWnd_x                                                   0xDD5638
#define __InChatMode_x                                             0xD4D774
#define __LastTell_x                                               0xD4F648
#define __LMouseHeldTime_x                                         0xD4D8A8
#define __Mouse_x                                                  0xDD58EC
#define __MouseLook_x                                              0xD4D80A
#define __MouseEventTime_x                                         0xDD19EC
#define __NetStatusToggle_x                                        0xD4D80D
#define __PCNames_x                                                0xD4ECC8
#define __RangeAttackReady_x                                       0xD4E960
#define __RMouseHeldTime_x                                         0xD4D8A4
#define __RunWalkState_x                                           0xD4D778
#define __ScreenMode_x                                             0xC8D620
#define __ScreenX_x                                                0xD4D72C
#define __ScreenY_x                                                0xD4D728
#define __ScreenXMax_x                                             0xD4D730
#define __ScreenYMax_x                                             0xD4D734
#define __ServerHost_x                                             0xD3E14C
#define __ServerName_x                                             0xD83F00
#define __ShiftKeyDown_x                                           0xD4DDFC
#define __ShowNames_x                                              0xD4EB6C
#define __Socials_x                                                0xD84000


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xD407A0
#define instEQZoneInfo_x                                           0xD4D9F4
#define instKeypressHandler_x                                      0xDD19D0
#define pinstActiveBanker_x                                        0xD40760
#define pinstActiveCorpse_x                                        0xD40764
#define pinstActiveGMaster_x                                       0xD40768
#define pinstActiveMerchant_x                                      0xD4075C
#define pinstAltAdvManager_x                                       0xC8E570
#define pinstAuraMgr_x                                             0xB5D810
#define pinstBandageTarget_x                                       0xD40748
#define pinstCamActor_x                                            0xC8DFDC
#define pinstCDBStr_x                                              0xC8D5F8
#define pinstCDisplay_x                                            0xD40770
#define pinstCEverQuest_x                                          0xDD5A64
#define pinstCharData_x                                            0xD4072C
#define pinstCharSpawn_x                                           0xD40754
#define pinstControlledMissile_x                                   0xD40728
#define pinstControlledPlayer_x                                    0xD40754
#define pinstCSidlManager_x                                        0x153EB70
#define pinstCXWndManager_x                                        0x153EB68
#define instDynamicZone_x                                          0xD4D5E0
#define pinstDZMember_x                                            0xD4D6F0
#define pinstDZTimerInfo_x                                         0xD4D6F4
#define pinstEQItemList_x                                          0xD3D2A8
#define instEQMisc_x                                               0xA9F6E8
#define pinstEQSoundManager_x                                      0xC8E618
#define instExpeditionLeader_x                                     0xD4D62A
#define instExpeditionName_x                                       0xD4D66A
#define pinstGroup_x                                               0xD3E1FE
#define pinstImeManager_x                                          0x153EB74
#define pinstLocalPlayer_x                                         0xD40740
#define pinstMercenaryData_x                                       0xDD1E48
#define pinstModelPlayer_x                                         0xD4076C
#define pinstPCData_x                                              0xD4072C
#define pinstSkillMgr_x                                            0xDD2478
#define pinstSpawnManager_x                                        0xDD20E8
#define pinstSpellManager_x                                        0xDD24F0
#define pinstSpellSets_x                                           0xDCA9A4
#define pinstStringTable_x                                         0xD406D4
#define pinstSwitchManager_x                                       0xD3DE18
#define pinstTarget_x                                              0xD40758
#define pinstTargetObject_x                                        0xD40730
#define pinstTargetSwitch_x                                        0xD40734
#define pinstTaskMember_x                                          0xC8D5A8
#define pinstTrackTarget_x                                         0xD4074C
#define pinstTradeTarget_x                                         0xD4073C
#define instTributeActive_x                                        0xA9F70D
#define pinstViewActor_x                                           0xC8DFD8
#define pinstWorldData_x                                           0xD40710


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xB54850
#define pinstCAudioTriggersWindow_x                                0xB547E8
#define pinstCCharacterSelect_x                                    0xC8DE8C
#define pinstCFacePick_x                                           0xC8DC3C
#define pinstCNoteWnd_x                                            0xC8DE44
#define pinstCBookWnd_x                                            0xC8DE4C
#define pinstCPetInfoWnd_x                                         0xC8DE50
#define pinstCTrainWnd_x                                           0xC8DE54
#define pinstCSkillsWnd_x                                          0xC8DE58
#define pinstCSkillsSelectWnd_x                                    0xC8DE5C
#define pinstCCombatSkillSelectWnd_x                               0xC8DE60
#define pinstCFriendsWnd_x                                         0xC8DE64
#define pinstCAuraWnd_x                                            0xC8DE68
#define pinstCRespawnWnd_x                                         0xC8DE6C
#define pinstCBandolierWnd_x                                       0xC8DE70
#define pinstCPotionBeltWnd_x                                      0xC8DE74
#define pinstCAAWnd_x                                              0xC8DE78
#define pinstCGroupSearchFiltersWnd_x                              0xC8DE7C
#define pinstCLoadskinWnd_x                                        0xC8DE80
#define pinstCAlarmWnd_x                                           0xC8DE84
#define pinstCMusicPlayerWnd_x                                     0xC8DE88
#define pinstCMailWnd_x                                            0xC8DE90
#define pinstCMailCompositionWnd_x                                 0xC8DE94
#define pinstCMailAddressBookWnd_x                                 0xC8DE98
#define pinstCRaidWnd_x                                            0xC8DEA0
#define pinstCRaidOptionsWnd_x                                     0xC8DEA4
#define pinstCBreathWnd_x                                          0xC8DEA8
#define pinstCMapViewWnd_x                                         0xC8DEAC
#define pinstCMapToolbarWnd_x                                      0xC8DEB0
#define pinstCEditLabelWnd_x                                       0xC8DEB4
#define pinstCTargetWnd_x                                          0xC8DEB8
#define pinstCColorPickerWnd_x                                     0xC8DEBC
#define pinstCPlayerWnd_x                                          0xC8DEC0
#define pinstCOptionsWnd_x                                         0xC8DEC4
#define pinstCBuffWindowNORMAL_x                                   0xC8DEC8
#define pinstCBuffWindowSHORT_x                                    0xC8DECC
#define pinstCharacterCreation_x                                   0xC8DED0
#define pinstCCursorAttachment_x                                   0xC8DED4
#define pinstCCastingWnd_x                                         0xC8DED8
#define pinstCCastSpellWnd_x                                       0xC8DEDC
#define pinstCSpellBookWnd_x                                       0xC8DEE0
#define pinstCInventoryWnd_x                                       0xC8DEE4
#define pinstCBankWnd_x                                            0xC8DEE8
#define pinstCQuantityWnd_x                                        0xC8DEEC
#define pinstCLootWnd_x                                            0xC8DEF0
#define pinstCActionsWnd_x                                         0xC8DEF4
#define pinstCCombatAbilityWnd_x                                   0xC8DEF8
#define pinstCMerchantWnd_x                                        0xC8DEFC
#define pinstCTradeWnd_x                                           0xC8DF00
#define pinstCSelectorWnd_x                                        0xC8DF04
#define pinstCBazaarWnd_x                                          0xC8DF08
#define pinstCBazaarSearchWnd_x                                    0xC8DF0C
#define pinstCGiveWnd_x                                            0xC8DF28
#define pinstCTrackingWnd_x                                        0xC8DF30
#define pinstCInspectWnd_x                                         0xC8DF34
#define pinstCSocialEditWnd_x                                      0xC8DF38
#define pinstCFeedbackWnd_x                                        0xC8DF3C
#define pinstCBugReportWnd_x                                       0xC8DF40
#define pinstCVideoModesWnd_x                                      0xC8DF44
#define pinstCTextEntryWnd_x                                       0xC8DF4C
#define pinstCFileSelectionWnd_x                                   0xC8DF50
#define pinstCCompassWnd_x                                         0xC8DF54
#define pinstCPlayerNotesWnd_x                                     0xC8DF58
#define pinstCGemsGameWnd_x                                        0xC8DF5C
#define pinstCTimeLeftWnd_x                                        0xC8DF60
#define pinstCPetitionQWnd_x                                       0xC8DF74
#define pinstCSoulmarkWnd_x                                        0xC8DF78
#define pinstCStoryWnd_x                                           0xC8DF7C
#define pinstCJournalTextWnd_x                                     0xC8DF80
#define pinstCJournalCatWnd_x                                      0xC8DF84
#define pinstCBodyTintWnd_x                                        0xC8DF88
#define pinstCServerListWnd_x                                      0xC8DF8C
#define pinstCAvaZoneWnd_x                                         0xC8DF94
#define pinstCBlockedBuffWnd_x                                     0xC8DF98
#define pinstCBlockedPetBuffWnd_x                                  0xC8DF9C
#define pinstCInvSlotMgr_x                                         0xC8DFD0
#define pinstCContainerMgr_x                                       0xC8DFD4
#define pinstCAdventureLeaderboardWnd_x                            0xEDE218
#define pinstCAdventureRequestWnd_x                                0xEDE200
#define pinstCAltStorageWnd_x                                      0xEDE358
#define pinstCAdventureStatsWnd_x                                  0xEDE218
#define pinstCBarterMerchantWnd_x                                  0xEDE7D8
#define pinstCBarterSearchWnd_x                                    0xEDE7F0
#define pinstCBarterWnd_x                                          0xEDE828
#define pinstCChatManager_x                                        0xEDEC40
#define pinstCDynamicZoneWnd_x                                     0xEDEE30
#define pinstCEQMainWnd_x                                          0xEDEEF0
#define pinstCFellowshipWnd_x                                      0xEDEE0C
#define pinstCFindLocationWnd_x                                    0xEDF020
#define pinstCGroupSearchWnd_x                                     0xEDF180
#define pinstCGroupWnd_x                                           0xEDF1B8
#define pinstCGuildBankWnd_x                                       0xEDF1D0
#define pinstCGuildMgmtWnd_x                                       0xEE1260
#define pinstCGuildTributeMasterWnd_x                              0xEE2ED0
#define pinstCHotButtonWnd_x                                       0xEE12B4
#define pinstCHotButtonWnd1_x                                      0xEE12B4
#define pinstCHotButtonWnd2_x                                      0xEE12B8
#define pinstCHotButtonWnd3_x                                      0xEE12BC
#define pinstCHotButtonWnd4_x                                      0xEE12E0
#define pinstCItemDisplayManager_x                                 0xEE1430
#define pinstCItemExpTransferWnd_x                                 0xEE146C
#define pinstCLeadershipWnd_x                                      0xEE15B0
#define pinstCLFGuildWnd_x                                         0xEE15D0
#define pinstCMIZoneSelectWnd_x                                    0xEE1870
#define pinstCAdventureMerchantWnd_x                               0xEE1B38
#define pinstCConfirmationDialog_x                                 0xEE1B58
#define pinstCPopupWndManager_x                                    0xEE1B58
#define pinstCProgressionSelectionWnd_x                            0xEE1BC0
#define pinstCPvPLeaderboardWnd_x                                  0xEE1C10
#define pinstCPvPStatsWnd_x                                        0xEE1C30
#define pinstCSystemInfoDialogBox_x                                0xEE1F18
#define pinstCTargetOfTargetWnd_x                                  0xEE2B48
#define pinstCTaskSelectWnd_x                                      0xEE1DD4
#define pinstCTaskTemplateSelectWnd_x                              0xEE2C08
#define pinstCTaskWnd_x                                            0xEE2C58
#define pinstCTipWndOFDAY_x                                        0xEE2D38
#define pinstCTipWndCONTEXT_x                                      0xEE2D3C
#define pinstCTitleWnd_x                                           0xEE2D70
#define pinstCTradeskillWnd_x                                      0xEE2DCC
#define pinstCTributeBenefitWnd_x                                  0xEE2E98
#define pinstCTributeMasterWnd_x                                   0xEE2ED0
#define pinstCContextMenuManager_x                                 0x153EC48
#define pinstCVoiceMacroWnd_x                                      0xDD2838
#define pinstCHtmlWnd_x                                            0xDD28B0


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x4F4B60
#define __ConvertItemTags_x                                        0x4E4EB0
#define __ExecuteCmd_x                                             0x4CF580
#define __EQGetTime_x                                              0x7F4ED0
#define __get_melee_range_x                                        0x4D60D0
#define __GetGaugeValueFromEQ_x                                    0x752400
#define __GetLabelFromEQ_x                                         0x753780
#define __GetXTargetType_x                                         0x8BE950
#define __LoadFrontEnd_x                                           0x5EF2E0
#define __NewUIINI_x                                               0x751FA0
#define __ProcessGameEvents_x                                      0x5311B0
#define CrashDetected_x                                            0x5F195B
#define DrawNetStatus_x                                            0x56A2C0
#define Util__FastTime_x                                           0x7F43B0
#define Expansion_HoT_x                                            0xD4EACC
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x49D9E0
#define AltAdvManager__IsAbilityReady_x                            0x49DA20
#define AltAdvManager__GetAltAbility_x                             0x49DDF0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x446780

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x61DC80

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6281B0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x546C90

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x643B30
#define CChatManager__InitContextMenu_x                            0x644620

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x7DB0F0
#define CChatService__GetFriendName_x                              0x7DB100

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x649370
#define CChatWindow__Clear_x                                       0x648F20
#define CChatWindow__WndNotification_x                             0x6498C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x855470
#define CComboWnd__Draw_x                                          0x855640
#define CComboWnd__GetCurChoice_x                                  0x855290
#define CComboWnd__GetListRect_x                                   0x8558E0
#define CComboWnd__GetTextRect_x                                   0x8554D0
#define CComboWnd__InsertChoice_x                                  0x855950
#define CComboWnd__SetColors_x                                     0x855220
#define CComboWnd__SetChoice_x                                     0x855250

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x652950
#define CContainerWnd__vftable_x                                   0x9CA830

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x48DBE0
#define CDisplay__GetClickedActor_x                                0x485D40
#define CDisplay__GetUserDefinedColor_x                            0x484610
#define CDisplay__GetWorldFilePath_x                               0x483A40
#define CDisplay__is3dON_x                                         0x482B20
#define CDisplay__ReloadUI_x                                       0x497950
#define CDisplay__WriteTextHD2_x                                   0x489150

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x87ABC0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x868FC0
#define CEditWnd__GetCharIndexPt_x                                 0x869FD0
#define CEditWnd__GetDisplayString_x                               0x869170
#define CEditWnd__GetHorzOffset_x                                  0x8694B0
#define CEditWnd__GetLineForPrintableChar_x                        0x869AA0
#define CEditWnd__GetSelStartPt_x                                  0x86A280
#define CEditWnd__GetSTMLSafeText_x                                0x869640
#define CEditWnd__PointFromPrintableChar_x                         0x869B90
#define CEditWnd__SelectableCharFromPoint_x                        0x869D10
#define CEditWnd__SetEditable_x                                    0x869610

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x5108A0
#define CEverQuest__DropHeldItemOnGround_x                         0x51D910
#define CEverQuest__dsp_chat_x                                     0x516890
#define CEverQuest__DoTellWindow_x                                 0x5150F0
#define CEverQuest__EnterZone_x                                    0x529560
#define CEverQuest__GetBodyTypeDesc_x                              0x50CEC0
#define CEverQuest__GetClassDesc_x                                 0x50C620
#define CEverQuest__GetClassThreeLetterCode_x                      0x50CC20
#define CEverQuest__GetDeityDesc_x                                 0x50D7D0
#define CEverQuest__GetLangDesc_x                                  0x50D250
#define CEverQuest__GetRaceDesc_x                                  0x50D540
#define CEverQuest__InterpretCmd_x                                 0x5173D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x52D6D0
#define CEverQuest__LMouseUp_x                                     0x52F8A0
#define CEverQuest__RightClickedOnPlayer_x                         0x52E140
#define CEverQuest__RMouseUp_x                                     0x52F100
#define CEverQuest__SetGameState_x                                 0x510F50
#define CEverQuest__Emote_x                                        0x516AF0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6624A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x662500
#define CGaugeWnd__Draw_x                                          0x662930

// CGuild
#define CGuild__FindMemberByName_x                                 0x420390

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x67F5C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x68A320
#define CInvSlotMgr__MoveItem_x                                    0x68B1C0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x689830
#define CInvSlot__SliderComplete_x                                 0x687C50
#define CInvSlot__GetItemBase_x                                    0x687260

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x68BEE0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x74F3B0
#define CItemDisplayWnd__UpdateStrings_x                           0x68D210

// CLabel 
#define CLabel__Draw_x                                             0x6A6BC0

// CListWnd 
#define CListWnd__AddColumn_x                                      0x844D40
#define CListWnd__AddColumn1_x                                     0x844540
#define CListWnd__AddLine_x                                        0x843FF0
#define CListWnd__AddString_x                                      0x844200
#define CListWnd__CalculateFirstVisibleLine_x                      0x8410D0
#define CListWnd__CalculateVSBRange_x                              0x8431E0
#define CListWnd__ClearAllSel_x                                    0x8403B0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x843BC0
#define CListWnd__Compare_x                                        0x841BC0
#define CListWnd__Draw_x                                           0x842E40
#define CListWnd__DrawColumnSeparators_x                           0x842CD0
#define CListWnd__DrawHeader_x                                     0x8406C0
#define CListWnd__DrawItem_x                                       0x842210
#define CListWnd__DrawLine_x                                       0x842970
#define CListWnd__DrawSeparator_x                                  0x842D70
#define CListWnd__EnsureVisible_x                                  0x841230
#define CListWnd__ExtendSel_x                                      0x842120
#define CListWnd__GetColumnMinWidth_x                              0x83FDD0
#define CListWnd__GetColumnWidth_x                                 0x83FCF0
#define CListWnd__GetCurSel_x                                      0x83F5C0
#define CListWnd__GetItemAtPoint_x                                 0x8414C0
#define CListWnd__GetItemAtPoint1_x                                0x841530
#define CListWnd__GetItemData_x                                    0x83F800
#define CListWnd__GetItemHeight_x                                  0x840D40
#define CListWnd__GetItemIcon_x                                    0x83F9E0
#define CListWnd__GetItemRect_x                                    0x841300
#define CListWnd__GetItemText_x                                    0x83F890
#define CListWnd__GetSelList_x                                     0x844430
#define CListWnd__GetSeparatorRect_x                               0x841AF0
#define CListWnd__RemoveLine_x                                     0x8443E0
#define CListWnd__SetColors_x                                      0x83F620
#define CListWnd__SetColumnJustification_x                         0x8400A0
#define CListWnd__SetColumnWidth_x                                 0x83FD80
#define CListWnd__SetCurSel_x                                      0x83F600
#define CListWnd__SetItemColor_x                                   0x8438A0
#define CListWnd__SetItemData_x                                    0x840460
#define CListWnd__SetItemText_x                                    0x8436E0
#define CListWnd__ShiftColumnSeparator_x                           0x843570
#define CListWnd__Sort_x                                           0x844EA0
#define CListWnd__ToggleSel_x                                      0x840330

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6C1950

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6E0D10
#define CMerchantWnd__RequestBuyItem_x                             0x6E6C10
#define CMerchantWnd__RequestSellItem_x                            0x70D230
#define CMerchantWnd__SelectBuySellSlot_x                          0x6E0FC0

// CObfuscator
#define CObfuscator__doit_x                                        0x7AC9F0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x85AC20
#define CSidlManager__CreateLabel_x                                0x745C40

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x614E20
#define CSidlScreenWnd__CalculateVSBRange_x                        0x614D40
#define CSidlScreenWnd__ConvertToRes_x                             0x87AAA0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x861500
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x862820
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8628D0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x861DB0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x860FE0
#define CSidlScreenWnd__EnableIniStorage_x                         0x860730
#define CSidlScreenWnd__GetSidlPiece_x                             0x8611D0
#define CSidlScreenWnd__Init1_x                                    0x8624F0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8615B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8608F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x862000
#define CSidlScreenWnd__StoreIniInfo_x                             0x8602E0
#define CSidlScreenWnd__StoreIniVis_x                              0x8606C0
#define CSidlScreenWnd__WndNotification_x                          0x862270
#define CSidlScreenWnd__GetChildItem_x                             0x860800

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5B14E0
#define CSkillMgr__GetSkillCap_x                                   0x5B1550

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x880F30
#define CSliderWnd__SetValue_x                                     0x881100
#define CSliderWnd__SetNumTicks_x                                  0x881880

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x74CE10

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x875CD0
#define CStmlWnd__CalculateHSBRange_x                              0x86DEF0
#define CStmlWnd__CalculateVSBRange_x                              0x86DF80
#define CStmlWnd__CanBreakAtCharacter_x                            0x86E100
#define CStmlWnd__FastForwardToEndOfTag_x                          0x86EA50
#define CStmlWnd__ForceParseNow_x                                  0x876320
#define CStmlWnd__GetNextTagPiece_x                                0x86E950
#define CStmlWnd__GetSTMLText_x                                    0x6487B0
#define CStmlWnd__GetVisibleText_x                                 0x86FC10
#define CStmlWnd__InitializeWindowVariables_x                      0x871480
#define CStmlWnd__MakeStmlColorTag_x                               0x86D140
#define CStmlWnd__MakeWndNotificationTag_x                         0x86D1A0
#define CStmlWnd__SetSTMLText_x                                    0x8715A0
#define CStmlWnd__StripFirstSTMLLines_x                            0x875970
#define CStmlWnd__UpdateHistoryString_x                            0x870530

// CTabWnd 
#define CTabWnd__Draw_x                                            0x87C290
#define CTabWnd__DrawCurrentPage_x                                 0x87BB00
#define CTabWnd__DrawTab_x                                         0x87B8D0
#define CTabWnd__GetCurrentPage_x                                  0x87BED0
#define CTabWnd__GetPageInnerRect_x                                0x87B5C0
#define CTabWnd__GetTabInnerRect_x                                 0x87B7C0
#define CTabWnd__GetTabRect_x                                      0x87B690
#define CTabWnd__InsertPage_x                                      0x87C580
#define CTabWnd__SetPage_x                                         0x87BF00
#define CTabWnd__SetPageRect_x                                     0x87C1D0
#define CTabWnd__UpdatePage_x                                      0x87C520

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41C040

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x862D30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x849690

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x83CA10

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5539D0
#define CXStr__CXStr1_x                                            0x46A060
#define CXStr__CXStr3_x                                            0x7F1290
#define CXStr__dCXStr_x                                            0x553D40
#define CXStr__operator_equal_x                                    0x7F1400
#define CXStr__operator_equal1_x                                   0x7F1450
#define CXStr__operator_plus_equal1_x                              0x7F2530

// CXWnd 
#define CXWnd__BringToTop_x                                        0x84D730
#define CXWnd__Center_x                                            0x8538A0
#define CXWnd__ClrFocus_x                                          0x84D380
#define CXWnd__DoAllDrawing_x                                      0x853500
#define CXWnd__DrawChildren_x                                      0x853690
#define CXWnd__DrawColoredRect_x                                   0x84DAD0
#define CXWnd__DrawTooltip_x                                       0x84DD70
#define CXWnd__DrawTooltipAtPoint_x                                0x852480
#define CXWnd__GetBorderFrame_x                                    0x84E1F0
#define CXWnd__GetChildWndAt_x                                     0x851460
#define CXWnd__GetClientClipRect_x                                 0x84DF80
#define CXWnd__GetScreenClipRect_x                                 0x852B60
#define CXWnd__GetScreenRect_x                                     0x84E330
#define CXWnd__GetTooltipRect_x                                    0x84DC00
#define CXWnd__GetWindowTextA_x                                    0x5457A0
#define CXWnd__IsActive_x                                          0x863F00
#define CXWnd__IsDescendantOf_x                                    0x84E0C0
#define CXWnd__IsReallyVisible_x                                   0x851440
#define CXWnd__IsType_x                                            0x87DC10
#define CXWnd__Move_x                                              0x850B50
#define CXWnd__Move1_x                                             0x8531B0
#define CXWnd__ProcessTransition_x                                 0x84D6D0
#define CXWnd__Refade_x                                            0x84D4A0
#define CXWnd__Resize_x                                            0x84E400
#define CXWnd__Right_x                                             0x852960
#define CXWnd__SetFocus_x                                          0x84FCB0
#define CXWnd__SetKeyTooltip_x                                     0x84E660
#define CXWnd__SetMouseOver_x                                      0x852EB0
#define CXWnd__StartFade_x                                         0x84D780
#define CXWnd__GetChildItem_x                                      0x852DF0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x865610
#define CXWndManager__DrawWindows_x                                0x865250
#define CXWndManager__GetKeyboardFlags_x                           0x863A30
#define CXWndManager__HandleKeyboardMsg_x                          0x8641B0
#define CXWndManager__RemoveWnd_x                                  0x864020

// CDBStr
#define CDBStr__GetString_x                                        0x480D80

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8BB280
#define EQ_Character__CastSpell_x                                  0x436CD0
#define EQ_Character__Cur_HP_x                                     0x4463D0
#define EQ_Character__GetAACastingTimeModifier_x                   0x42FC30
#define EQ_Character__GetCharInfo2_x                               0x7C6980
#define EQ_Character__GetFocusCastingTimeModifier_x                0x428FD0
#define EQ_Character__GetFocusRangeModifier_x                      0x4291B0
#define EQ_Character__Max_Endurance_x                              0x578900
#define EQ_Character__Max_HP_x                                     0x4405A0
#define EQ_Character__Max_Mana_x                                   0x578740
#define EQ_Character__doCombatAbility_x                            0x5771A0
#define EQ_Character__UseSkill_x                                   0x456CE0
#define EQ_Character__GetConLevel_x                                0x56E8F0
#define EQ_Character__IsExpansionFlag_x                            0x40EB20
#define EQ_Character__TotalEffect_x                                0x434EE0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x54BCC0
#define EQ_Item__CreateItemTagString_x                             0x7AB370
#define EQ_Item__IsStackable_x                                     0x79FC00

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x49F9D0
#define EQ_LoadingS__Array_x                                       0xAA5BA8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x57CAE0
#define EQ_PC__GetAltAbilityIndex_x                                0x7B7160
#define EQ_PC__GetCombatAbility_x                                  0x7B71F0
#define EQ_PC__GetCombatAbilityTimer_x                             0x7B72A0
#define EQ_PC__GetItemTimerValue_x                                 0x576EE0
#define EQ_PC__HasLoreItem_x                                       0x571A10

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4D3E50
#define EQItemList__add_item_x                                     0x4D3D90
#define EQItemList__delete_item_x                                  0x4D4260
#define EQItemList__FreeItemList_x                                 0x4D4150

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x480270

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x582530
#define EQPlayer__dEQPlayer_x                                      0x587000
#define EQPlayer__DoAttack_x                                       0x59B430
#define EQPlayer__EQPlayer_x                                       0x58C730
#define EQPlayer__SetNameSpriteState_x                             0x584960
#define EQPlayer__SetNameSpriteTint_x                              0x5825A0
#define EQPlayer__IsBodyType_j_x                                   0x8BAB20
#define EQPlayer__IsTargetable_x                                   0x8BADF0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x58FBD0
#define EQPlayerManager__GetSpawnByName_x                          0x590030

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x551CF0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x551D30
#define KeypressHandler__ClearCommandStateArray_x                  0x5518D0
#define KeypressHandler__HandleKeyDown_x                           0x550230
#define KeypressHandler__HandleKeyUp_x                             0x550550
#define KeypressHandler__SaveKeymapping_x                          0x5519A0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6B9F60
#define MapViewMap__SaveEx_x                                       0x6BD770

#define PlayerPointManager__GetAltCurrency_x                       0x7B1960

// StringTable 
#define StringTable__getString_x                                   0x7ACC90

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x57B3D0
