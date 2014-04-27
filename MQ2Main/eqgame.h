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
#define __ExpectedVersionDate                                     "Dec 10 2013"
#define __ExpectedVersionTime                                     "12:57:31"
#define __ActualVersionDate_x                                      0x9EEBC0
#define __ActualVersionTime_x                                      0x9EEBCC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x56B7E0
#define __MemChecker1_x                                            0x826F40
#define __MemChecker2_x                                            0x601090
#define __MemChecker3_x                                            0x600FE0
#define __MemChecker4_x                                            0x7AF760
#define __EncryptPad0_x                                            0xAF9A20
#define __EncryptPad1_x                                            0xB7E328
#define __EncryptPad2_x                                            0xB14020
#define __EncryptPad3_x                                            0xB13C20
#define __EncryptPad4_x                                            0xB7A778
#define __AC1_x                                                    0x76D065
#define __AC2_x                                                    0x51F757
#define __AC3_x                                                    0x532BB0
#define __AC4_x                                                    0x538BA4
#define __AC5_x                                                    0x545081
#define __AC6_x                                                    0x548B32
#define __AC7_x                                                    0x53EB9C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0xF20100
#define DI8__Keyboard_x                                            0xF20104
#define DI8__Mouse_x                                               0xF20108
#define __AltTimerReady_x                                          0xD80AB9
#define __Attack_x                                                 0xE13962
#define __Autofire_x                                               0xE13963
#define __BindList_x                                               0xAE0970
#define __Clicks_x                                                 0xD8F7F0
#define __CommandList_x                                            0xAE2130
#define __CurrentMapLabel_x                                        0xF24A10
#define __CurrentSocial_x                                          0xACA1E0
#define __DoAbilityList_x                                          0xDC5F10
#define __do_loot_x                                                0x4ED5B0
#define __DrawHandler_x                                            0x1585B34
#define __GroupCount_x                                             0xD80192

#define __Guilds_x                                                 0xD85D98
#define __gWorld_x                                                 0xD8264C
#define __HotkeyPage_x                                             0xE0C910
#define __HWnd_x                                                   0xE18008
#define __InChatMode_x                                             0xD8F71C
#define __LastTell_x                                               0xD91618
#define __LMouseHeldTime_x                                         0xD8F85C
#define __Mouse_x                                                  0xF2010C
#define __MouseLook_x                                              0xD8F7B6
#define __MouseEventTime_x                                         0xE13E4C
#define __NetStatusToggle_x                                        0xD8F7B9
#define __PCNames_x                                                0xD90C84
#define __RangeAttackReady_x                                       0xD90924
#define __RMouseHeldTime_x                                         0xD8F858
#define __RunWalkState_x                                           0xD8F720
#define __ScreenMode_x                                             0xCCF200
#define __ScreenX_x                                                0xD8F6D4
#define __ScreenY_x                                                0xD8F6D0
#define __ScreenXMax_x                                             0xD8F6D8
#define __ScreenYMax_x                                             0xD8F6DC
#define __ServerHost_x                                             0xD800DC
#define __ServerName_x                                             0xDC5ED0
#define __ShiftKeyDown_x                                           0xD8FDBC
#define __ShowNames_x                                              0xD90B2C
#define __Socials_x                                                0xDC5FD0
#define __SubscriptionType_x                                       0xF4D620
#define __TargetAggroHolder_x                                      0xF26330
#define __GroupAggro_x                                             0xF26370


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xD82730
#define instEQZoneInfo_x                                           0xD8F9AC
#define instKeypressHandler_x                                      0xE13E30
#define pinstActiveBanker_x                                        0xD826F0
#define pinstActiveCorpse_x                                        0xD826F4
#define pinstActiveGMaster_x                                       0xD826F8
#define pinstActiveMerchant_x                                      0xD826EC
#define pinstAggroInfo_x                                           0xB93EE0
#define pinstAltAdvManager_x                                       0xCD01E8
#define pinstAuraMgr_x                                             0xB9D950
#define pinstBandageTarget_x                                       0xD826D8
#define pinstCamActor_x                                            0xCCFBD4
#define pinstCDBStr_x                                              0xCCF1C0
#define pinstCDisplay_x                                            0xD82700
#define pinstCEverQuest_x                                          0xF20284
#define pinstCharData_x                                            0xD826BC
#define pinstCharSpawn_x                                           0xD826E4
#define pinstControlledMissile_x                                   0xD826B8
#define pinstControlledPlayer_x                                    0xD826E4
#define pinstCSidlManager_x                                        0x15851E8
#define pinstCXWndManager_x                                        0x15851E0
#define instDynamicZone_x                                          0xD8F570
#define pinstDZMember_x                                            0xD8F680
#define pinstDZTimerInfo_x                                         0xD8F684
#define pinstEQItemList_x                                          0xD7F0D8
#define instEQMisc_x                                               0xAD3A00
#define pinstEQSoundManager_x                                      0xCD0380
#define instExpeditionLeader_x                                     0xD8F5BA
#define instExpeditionName_x                                       0xD8F5FA
#define pinstGroup_x                                               0xD8018E
#define pinstImeManager_x                                          0x15851EC
#define pinstLocalPlayer_x                                         0xD826D0
#define pinstMercenaryData_x                                       0xE14370
#define pinstMercAltAbilities_x                                    0xCD02FC
#define pinstModelPlayer_x                                         0xD826FC
#define pinstPCData_x                                              0xD826BC
#define pinstSkillMgr_x                                            0xE14C68
#define pinstSpawnManager_x                                        0xE14790
#define pinstSpellManager_x                                        0xE14D28
#define pinstSpellSets_x                                           0xE0C974
#define pinstStringTable_x                                         0xD82664
#define pinstSwitchManager_x                                       0xD7FD78
#define pinstTarget_x                                              0xD826E8
#define pinstTargetObject_x                                        0xD826C0
#define pinstTargetSwitch_x                                        0xD826C4
#define pinstTaskMember_x                                          0xCCF148
#define pinstTrackTarget_x                                         0xD826DC
#define pinstTradeTarget_x                                         0xD826CC
#define instTributeActive_x                                        0xAD3A25
#define pinstViewActor_x                                           0xCCFBD0
#define pinstWorldData_x                                           0xD826A0


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xB941D0
#define pinstCAudioTriggersWindow_x                                0xB940F0
#define pinstCCharacterSelect_x                                    0xCCFA7C
#define pinstCFacePick_x                                           0xCCF82C
#define pinstCNoteWnd_x                                            0xCCFA34
#define pinstCBookWnd_x                                            0xCCFA3C
#define pinstCPetInfoWnd_x                                         0xCCFA40
#define pinstCTrainWnd_x                                           0xCCFA44
#define pinstCSkillsWnd_x                                          0xCCFA48
#define pinstCSkillsSelectWnd_x                                    0xCCFA4C
#define pinstCCombatSkillSelectWnd_x                               0xCCFA50
#define pinstCFriendsWnd_x                                         0xCCFA54
#define pinstCAuraWnd_x                                            0xCCFA58
#define pinstCRespawnWnd_x                                         0xCCFA5C
#define pinstCBandolierWnd_x                                       0xCCFA60
#define pinstCPotionBeltWnd_x                                      0xCCFA64
#define pinstCAAWnd_x                                              0xCCFA68
#define pinstCGroupSearchFiltersWnd_x                              0xCCFA6C
#define pinstCLoadskinWnd_x                                        0xCCFA70
#define pinstCAlarmWnd_x                                           0xCCFA74
#define pinstCMusicPlayerWnd_x                                     0xCCFA78
#define pinstCMailWnd_x                                            0xCCFA80
#define pinstCMailCompositionWnd_x                                 0xCCFA84
#define pinstCMailAddressBookWnd_x                                 0xCCFA88
#define pinstCRaidWnd_x                                            0xCCFA90
#define pinstCRaidOptionsWnd_x                                     0xCCFA94
#define pinstCBreathWnd_x                                          0xCCFA98
#define pinstCMapViewWnd_x                                         0xCCFA9C
#define pinstCMapToolbarWnd_x                                      0xCCFAA0
#define pinstCEditLabelWnd_x                                       0xCCFAA4
#define pinstCTargetWnd_x                                          0xCCFAA8
#define pinstCColorPickerWnd_x                                     0xCCFAAC
#define pinstCPlayerWnd_x                                          0xCCFAB0
#define pinstCOptionsWnd_x                                         0xCCFAB4
#define pinstCBuffWindowNORMAL_x                                   0xCCFAB8
#define pinstCBuffWindowSHORT_x                                    0xCCFABC
#define pinstCharacterCreation_x                                   0xCCFAC0
#define pinstCCursorAttachment_x                                   0xCCFAC4
#define pinstCCastingWnd_x                                         0xCCFAC8
#define pinstCCastSpellWnd_x                                       0xCCFACC
#define pinstCSpellBookWnd_x                                       0xCCFAD0
#define pinstCInventoryWnd_x                                       0xCCFAD4
#define pinstCBankWnd_x                                            0xCCFAD8
#define pinstCQuantityWnd_x                                        0xCCFADC
#define pinstCLootWnd_x                                            0xCCFAE0
#define pinstCActionsWnd_x                                         0xCCFAE4
#define pinstCCombatAbilityWnd_x                                   0xCCFAE8
#define pinstCMerchantWnd_x                                        0xCCFAEC
#define pinstCTradeWnd_x                                           0xCCFAF0
#define pinstCSelectorWnd_x                                        0xCCFAF4
#define pinstCBazaarWnd_x                                          0xCCFAF8
#define pinstCBazaarSearchWnd_x                                    0xCCFAFC
#define pinstCGiveWnd_x                                            0xCCFB18
#define pinstCTrackingWnd_x                                        0xCCFB20
#define pinstCInspectWnd_x                                         0xCCFB24
#define pinstCSocialEditWnd_x                                      0xCCFB28
#define pinstCFeedbackWnd_x                                        0xCCFB2C
#define pinstCBugReportWnd_x                                       0xCCFB30
#define pinstCVideoModesWnd_x                                      0xCCFB34
#define pinstCTextEntryWnd_x                                       0xCCFB3C
#define pinstCFileSelectionWnd_x                                   0xCCFB40
#define pinstCCompassWnd_x                                         0xCCFB44
#define pinstCPlayerNotesWnd_x                                     0xCCFB48
#define pinstCGemsGameWnd_x                                        0xCCFB4C
#define pinstCTimeLeftWnd_x                                        0xCCFB50
#define pinstCPetitionQWnd_x                                       0xCCFB64
#define pinstCSoulmarkWnd_x                                        0xCCFB68
#define pinstCStoryWnd_x                                           0xCCFB6C
#define pinstCJournalTextWnd_x                                     0xCCFB70
#define pinstCJournalCatWnd_x                                      0xCCFB74
#define pinstCBodyTintWnd_x                                        0xCCFB78
#define pinstCServerListWnd_x                                      0xCCFB7C
#define pinstCAvaZoneWnd_x                                         0xCCFB88
#define pinstCBlockedBuffWnd_x                                     0xCCFB8C
#define pinstCBlockedPetBuffWnd_x                                  0xCCFB90
#define pinstCInvSlotMgr_x                                         0xCCFBC8
#define pinstCContainerMgr_x                                       0xCCFBCC
#define pinstCAdventureLeaderboardWnd_x                            0xF20C88
#define pinstCAdventureRequestWnd_x                                0xF20CD8
#define pinstCAltStorageWnd_x                                      0xF20EA8
#define pinstCAdventureStatsWnd_x                                  0xF20D28
#define pinstCBarterMerchantWnd_x                                  0xF21588
#define pinstCBarterSearchWnd_x                                    0xF215D8
#define pinstCBarterWnd_x                                          0xF21628
#define pinstCChatManager_x                                        0xF21A28
#define pinstCDynamicZoneWnd_x                                     0xF21D08
#define pinstCEQMainWnd_x                                          0xF21E10
#define pinstCFellowshipWnd_x                                      0xF21CCC
#define pinstCFindLocationWnd_x                                    0xF21FD0
#define pinstCGroupSearchWnd_x                                     0xF221D8
#define pinstCGroupWnd_x                                           0xF22228
#define pinstCGuildBankWnd_x                                       0xF22278
#define pinstCGuildMgmtWnd_x                                       0xF24318
#define pinstCHotButtonWnd_x                                       0xF2438C
#define pinstCHotButtonWnd1_x                                      0xF2438C
#define pinstCHotButtonWnd2_x                                      0xF24390
#define pinstCHotButtonWnd3_x                                      0xF24394
#define pinstCHotButtonWnd4_x                                      0xF243B8
#define pinstCItemDisplayManager_x                                 0xF24598
#define pinstCItemExpTransferWnd_x                                 0xF245EC
#define pinstCLFGuildWnd_x                                         0xF247F8
#define pinstCMIZoneSelectWnd_x                                    0xF24BB8
#define pinstCConfirmationDialog_x                                 0xF25008
#define pinstCPopupWndManager_x                                    0xF25008
#define pinstCProgressionSelectionWnd_x                            0xF250A0
#define pinstCPvPStatsWnd_x                                        0xF25140
#define pinstCSystemInfoDialogBox_x                                0xF25590
#define pinstCTaskTemplateSelectWnd_x                              0xF26600
#define pinstCTipWndOFDAY_x                                        0xF267C0
#define pinstCTipWndCONTEXT_x                                      0xF267C4
#define pinstCTitleWnd_x                                           0xF26810
#define pinstCContextMenuManager_x                                 0x1584DFC
#define pinstCVoiceMacroWnd_x                                      0xE15190
#define pinstCHtmlWnd_x                                            0xE15238


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x503240
#define __ConvertItemTags_x                                        0x4F30B0
#define __ExecuteCmd_x                                             0x4DCC30
#define __EQGetTime_x                                              0x827AA0
#define __get_melee_range_x                                        0x4E38E0
#define __GetGaugeValueFromEQ_x                                    0x76BD90
#define __GetLabelFromEQ_x                                         0x76CFF0
#define __GetXTargetType_x                                         0x8E34B0
#define __LoadFrontEnd_x                                           0x600740
#define __NewUIINI_x                                               0x76B6C0
#define __ProcessGameEvents_x                                      0x540CE0
#define CrashDetected_x                                            0x604590
#define DrawNetStatus_x                                            0x57AF30
#define Util__FastTime_x                                           0x826DE0
#define Expansion_HoT_x                                            0xD90A8C
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A43C0
#define AltAdvManager__IsAbilityReady_x                            0x4A4430
#define AltAdvManager__GetAltAbility_x                             0x4A47F0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x44A5A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x630280

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x63E1B0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x556F80

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x658DD0
#define CChatManager__InitContextMenu_x                            0x6598F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x80D9D0
#define CChatService__GetFriendName_x                              0x80D9E0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x65E620
#define CChatWindow__Clear_x                                       0x65E1D0
#define CChatWindow__WndNotification_x                             0x65EB50

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x885BD0
#define CComboWnd__Draw_x                                          0x885DB0
#define CComboWnd__GetCurChoice_x                                  0x8859F0
#define CComboWnd__GetListRect_x                                   0x886050
#define CComboWnd__GetTextRect_x                                   0x885C30
#define CComboWnd__InsertChoice_x                                  0x8860C0
#define CComboWnd__SetColors_x                                     0x885980
#define CComboWnd__SetChoice_x                                     0x8859B0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x667CB0
#define CContainerWnd__vftable_x                                   0x9F81D8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x494120
#define CDisplay__GetClickedActor_x                                0x48BE10
#define CDisplay__GetUserDefinedColor_x                            0x48A6D0
#define CDisplay__GetWorldFilePath_x                               0x489AD0
#define CDisplay__is3dON_x                                         0x488BA0
#define CDisplay__ReloadUI_x                                       0x49E0F0
#define CDisplay__WriteTextHD2_x                                   0x48F570

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8A73A0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8963F0
#define CEditWnd__GetCharIndexPt_x                                 0x897400
#define CEditWnd__GetDisplayString_x                               0x8965A0
#define CEditWnd__GetHorzOffset_x                                  0x8968E0
#define CEditWnd__GetLineForPrintableChar_x                        0x896ED0
#define CEditWnd__GetSelStartPt_x                                  0x8976B0
#define CEditWnd__GetSTMLSafeText_x                                0x896A70
#define CEditWnd__PointFromPrintableChar_x                         0x896FC0
#define CEditWnd__SelectableCharFromPoint_x                        0x897140
#define CEditWnd__SetEditable_x                                    0x896A40

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x51FEA0
#define CEverQuest__DoTellWindow_x                                 0x5247D0
#define CEverQuest__DropHeldItemOnGround_x                         0x52D0B0
#define CEverQuest__dsp_chat_x                                     0x525F70
#define CEverQuest__Emote_x                                        0x5261D0
#define CEverQuest__EnterZone_x                                    0x538D50
#define CEverQuest__GetBodyTypeDesc_x                              0x51C520
#define CEverQuest__GetClassDesc_x                                 0x51BC80
#define CEverQuest__GetClassThreeLetterCode_x                      0x51C280
#define CEverQuest__GetDeityDesc_x                                 0x51CE30
#define CEverQuest__GetLangDesc_x                                  0x51C8B0
#define CEverQuest__GetRaceDesc_x                                  0x51CBA0
#define CEverQuest__InterpretCmd_x                                 0x526AB0
#define CEverQuest__LeftClickedOnPlayer_x                          0x53D0E0
#define CEverQuest__LMouseUp_x                                     0x53F300
#define CEverQuest__RightClickedOnPlayer_x                         0x53DBA0
#define CEverQuest__RMouseUp_x                                     0x53EB50
#define CEverQuest__SetGameState_x                                 0x520550
#define CEverQuest__UPCNotificationFlush_x                         0x527A60

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x677C30
#define CGaugeWnd__CalcLinesFillRect_x                             0x677C90
#define CGaugeWnd__Draw_x                                          0x6780C0

// CGuild
#define CGuild__FindMemberByName_x                                 0x423F60

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x694D60

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6A0770
#define CInvSlotMgr__MoveItem_x                                    0x6A16B0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x69FAA0
#define CInvSlot__SliderComplete_x                                 0x69D8F0
#define CInvSlot__GetItemBase_x                                    0x69CD70

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6A2470

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7689B0
#define CItemDisplayWnd__UpdateStrings_x                           0x6A37B0

// CLabel 
#define CLabel__Draw_x                                             0x6BDFA0

// CListWnd 
#define CListWnd__AddColumn_x                                      0x873F80
#define CListWnd__AddColumn1_x                                     0x873770
#define CListWnd__AddLine_x                                        0x873220
#define CListWnd__AddString_x                                      0x873430
#define CListWnd__CalculateFirstVisibleLine_x                      0x870330
#define CListWnd__CalculateVSBRange_x                              0x872440
#define CListWnd__ClearAllSel_x                                    0x86F5F0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x872E10
#define CListWnd__Compare_x                                        0x870E20
#define CListWnd__Draw_x                                           0x8720A0
#define CListWnd__DrawColumnSeparators_x                           0x871F30
#define CListWnd__DrawHeader_x                                     0x86F900
#define CListWnd__DrawItem_x                                       0x871470
#define CListWnd__DrawLine_x                                       0x871BD0
#define CListWnd__DrawSeparator_x                                  0x871FD0
#define CListWnd__EnsureVisible_x                                  0x870490
#define CListWnd__ExtendSel_x                                      0x871380
#define CListWnd__GetColumnMinWidth_x                              0x86F010
#define CListWnd__GetColumnWidth_x                                 0x86EF30
#define CListWnd__GetCurSel_x                                      0x86E800
#define CListWnd__GetItemAtPoint_x                                 0x870710
#define CListWnd__GetItemAtPoint1_x                                0x870780
#define CListWnd__GetItemData_x                                    0x86EA40
#define CListWnd__GetItemHeight_x                                  0x86FF90
#define CListWnd__GetItemIcon_x                                    0x86EC20
#define CListWnd__GetItemRect_x                                    0x870550
#define CListWnd__GetItemText_x                                    0x86EAD0
#define CListWnd__GetSelList_x                                     0x873660
#define CListWnd__GetSeparatorRect_x                               0x870D40
#define CListWnd__RemoveLine_x                                     0x873610
#define CListWnd__SetColors_x                                      0x86E860
#define CListWnd__SetColumnJustification_x                         0x86F2E0
#define CListWnd__SetColumnWidth_x                                 0x86EFC0
#define CListWnd__SetCurSel_x                                      0x86E840
#define CListWnd__SetItemColor_x                                   0x872AF0
#define CListWnd__SetItemData_x                                    0x86F6A0
#define CListWnd__SetItemText_x                                    0x872930
#define CListWnd__ShiftColumnSeparator_x                           0x8727C0
#define CListWnd__Sort_x                                           0x8740E0
#define CListWnd__ToggleSel_x                                      0x86F570

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6D8DB0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6F8C90
#define CMerchantWnd__RequestBuyItem_x                             0x6FF200
#define CMerchantWnd__RequestSellItem_x                            0x726480
#define CMerchantWnd__SelectBuySellSlot_x                          0x6F8F40

// CObfuscator
#define CObfuscator__doit_x                                        0x7ED6C0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x88B300
#define CSidlManager__CreateLabel_x                                0x75EE80

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x627410
#define CSidlScreenWnd__CalculateVSBRange_x                        0x627340
#define CSidlScreenWnd__ConvertToRes_x                             0x8A7280
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x878FC0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x87A340
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x87A3F0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8798E0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x878AA0
#define CSidlScreenWnd__EnableIniStorage_x                         0x878200
#define CSidlScreenWnd__GetSidlPiece_x                             0x878C90
#define CSidlScreenWnd__Init1_x                                    0x87A020
#define CSidlScreenWnd__LoadIniInfo_x                              0x879070
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8783C0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x879B30
#define CSidlScreenWnd__StoreIniInfo_x                             0x877D70
#define CSidlScreenWnd__StoreIniVis_x                              0x878190
#define CSidlScreenWnd__WndNotification_x                          0x879DA0
#define CSidlScreenWnd__GetChildItem_x                             0x8782D0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5C28B0
#define CSkillMgr__GetSkillCap_x                                   0x5C2930

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8B1200
#define CSliderWnd__SetValue_x                                     0x8B13D0
#define CSliderWnd__SetNumTicks_x                                  0x8B1B50

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x766650

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8A1A10
#define CStmlWnd__CalculateHSBRange_x                              0x89A0A0
#define CStmlWnd__CalculateVSBRange_x                              0x89A130
#define CStmlWnd__CanBreakAtCharacter_x                            0x89A2B0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x89AB90
#define CStmlWnd__ForceParseNow_x                                  0x8A2360
#define CStmlWnd__GetNextTagPiece_x                                0x89AA90
#define CStmlWnd__GetSTMLText_x                                    0x65DA70
#define CStmlWnd__GetVisibleText_x                                 0x89B5E0
#define CStmlWnd__InitializeWindowVariables_x                      0x89D880
#define CStmlWnd__MakeStmlColorTag_x                               0x899280
#define CStmlWnd__MakeWndNotificationTag_x                         0x8992E0
#define CStmlWnd__SetSTMLText_x                                    0x89F0E0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8A16B0
#define CStmlWnd__UpdateHistoryString_x                            0x89C520

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8A8A70
#define CTabWnd__DrawCurrentPage_x                                 0x8A82E0
#define CTabWnd__DrawTab_x                                         0x8A80B0
#define CTabWnd__GetCurrentPage_x                                  0x8A86B0
#define CTabWnd__GetPageInnerRect_x                                0x8A7DA0
#define CTabWnd__GetTabInnerRect_x                                 0x8A7FA0
#define CTabWnd__GetTabRect_x                                      0x8A7E70
#define CTabWnd__InsertPage_x                                      0x8A8D60
#define CTabWnd__SetPage_x                                         0x8A86E0
#define CTabWnd__SetPageRect_x                                     0x8A89B0
#define CTabWnd__UpdatePage_x                                      0x8A8D00

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41FAE0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8A4E50

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8ADBC0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x86C910

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x411220
#define CXStr__CXStr1_x                                            0x79C2D0
#define CXStr__CXStr3_x                                            0x823E70
#define CXStr__dCXStr_x                                            0x41CE70
#define CXStr__operator_equal_x                                    0x823FE0
#define CXStr__operator_equal1_x                                   0x824030
#define CXStr__operator_plus_equal1_x                              0x825110

// CXWnd 
#define CXWnd__BringToTop_x                                        0x87DFE0
#define CXWnd__Center_x                                            0x884080
#define CXWnd__ClrFocus_x                                          0x87DBB0
#define CXWnd__DoAllDrawing_x                                      0x883D00
#define CXWnd__DrawChildren_x                                      0x883E80
#define CXWnd__DrawColoredRect_x                                   0x87E380
#define CXWnd__DrawTooltip_x                                       0x87E620
#define CXWnd__DrawTooltipAtPoint_x                                0x882CA0
#define CXWnd__GetBorderFrame_x                                    0x87EA30
#define CXWnd__GetChildWndAt_x                                     0x881CB0
#define CXWnd__GetClientClipRect_x                                 0x87E810
#define CXWnd__GetScreenClipRect_x                                 0x883390
#define CXWnd__GetScreenRect_x                                     0x87EBB0
#define CXWnd__GetTooltipRect_x                                    0x87E4B0
#define CXWnd__GetWindowTextA_x                                    0x411260
#define CXWnd__IsActive_x                                          0x8911D0
#define CXWnd__IsDescendantOf_x                                    0x87E980
#define CXWnd__IsReallyVisible_x                                   0x881C90
#define CXWnd__IsType_x                                            0x8AA3C0
#define CXWnd__Move_x                                              0x881380
#define CXWnd__Move1_x                                             0x8839D0
#define CXWnd__ProcessTransition_x                                 0x87DF80
#define CXWnd__Refade_x                                            0x87DD50
#define CXWnd__Resize_x                                            0x87EC70
#define CXWnd__Right_x                                             0x883190
#define CXWnd__SetFocus_x                                          0x880510
#define CXWnd__SetFont_x                                           0x87DC00
#define CXWnd__SetKeyTooltip_x                                     0x87EEE0
#define CXWnd__SetMouseOver_x                                      0x8836D0
#define CXWnd__StartFade_x                                         0x87E030
#define CXWnd__GetChildItem_x                                      0x883610

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x892AF0
#define CXWndManager__DrawWindows_x                                0x892730
#define CXWndManager__GetKeyboardFlags_x                           0x890D40
#define CXWndManager__HandleKeyboardMsg_x                          0x891660
#define CXWndManager__RemoveWnd_x                                  0x891360

// CDBStr
#define CDBStr__GetString_x                                        0x486DB0

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8DFD80
#define EQ_Character__CastSpell_x                                  0x43ABB0
#define EQ_Character__Cur_HP_x                                     0x44A1F0
#define EQ_Character__GetAACastingTimeModifier_x                   0x4339B0
#define EQ_Character__GetCharInfo2_x                               0x7F8530
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42CB90
#define EQ_Character__GetFocusRangeModifier_x                      0x42CD70
#define EQ_Character__Max_Endurance_x                              0x589BA0
#define EQ_Character__Max_HP_x                                     0x444360
#define EQ_Character__Max_Mana_x                                   0x5899E0
#define EQ_Character__doCombatAbility_x                            0x5884F0
#define EQ_Character__UseSkill_x                                   0x45B690
#define EQ_Character__GetConLevel_x                                0x57F4E0
#define EQ_Character__IsExpansionFlag_x                            0x410760
#define EQ_Character__TotalEffect_x                                0x438D10

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x55C290
#define EQ_Item__CreateItemTagString_x                             0x7D8220
#define EQ_Item__IsStackable_x                                     0x7CC7D0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A6530
#define EQ_LoadingS__Array_x                                       0xADA2F0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x58E1B0
#define EQ_PC__GetAltAbilityIndex_x                                0x7E0F00
#define EQ_PC__GetCombatAbility_x                                  0x7E0F90
#define EQ_PC__GetCombatAbilityTimer_x                             0x7E1040
#define EQ_PC__GetItemTimerValue_x                                 0x588230
#define EQ_PC__HasLoreItem_x                                       0x5826A0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E1600
#define EQItemList__add_item_x                                     0x4E1540
#define EQItemList__delete_item_x                                  0x4E1A00
#define EQItemList__FreeItemList_x                                 0x4E1900

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4861D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x593F20
#define EQPlayer__dEQPlayer_x                                      0x598BA0
#define EQPlayer__DoAttack_x                                       0x5ACF60
#define EQPlayer__EQPlayer_x                                       0x59E390
#define EQPlayer__SetNameSpriteState_x                             0x5963B0
#define EQPlayer__SetNameSpriteTint_x                              0x593F90
#define EQPlayer__IsBodyType_j_x                                   0x8DF5F0
#define EQPlayer__IsTargetable_x                                   0x8DF8C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5A1880
#define EQPlayerManager__GetSpawnByName_x                          0x5A1CE0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x562420
#define KeypressHandler__AttachKeyToEqCommand_x                    0x562460
#define KeypressHandler__ClearCommandStateArray_x                  0x562000
#define KeypressHandler__HandleKeyDown_x                           0x560960
#define KeypressHandler__HandleKeyUp_x                             0x560C80
#define KeypressHandler__SaveKeymapping_x                          0x5620D0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6D11D0
#define MapViewMap__SaveEx_x                                       0x6D4AB0

#define PlayerPointManager__GetAltCurrency_x                       0x7F2700

// StringTable 
#define StringTable__getString_x                                   0x7ED960

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x58CAB0

//Doors
#define EQSwitch__UseSwitch_x                                      0x518A90
