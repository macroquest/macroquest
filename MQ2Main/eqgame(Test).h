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
#define __ExpectedVersionDate                                     "Mar  6 2015"
#define __ExpectedVersionTime                                     "14:30:04"
#define __ActualVersionDate_x                                      0xA77098
#define __ActualVersionTime_x                                      0xA770A4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x58F2C0
#define __MemChecker1_x                                            0x857460
#define __MemChecker2_x                                            0x626B60
#define __MemChecker3_x                                            0x626AB0
#define __MemChecker4_x                                            0x7DB480
#define __EncryptPad0_x                                            0xBF2960
#define __EncryptPad1_x                                            0xD76C78
#define __EncryptPad2_x                                            0xC3B8E0
#define __EncryptPad3_x                                            0xC3B4E0
#define __EncryptPad4_x                                            0xD533A0
#define __AC1_x                                                    0x798795
#define __AC2_x                                                    0x5454C7
#define __AC3_x                                                    0x559CC0
#define __AC4_x                                                    0x560100
#define __AC5_x                                                    0x56BEAE
#define __AC6_x                                                    0x56FA02
#define __AC7_x                                                    0x56659C
#define __AC1_Data                                                 0x11111111

// Direct Input
#define DI8__Main_x                                                0x1128A40
#define DI8__Keyboard_x                                            0x1128A44
#define DI8__Mouse_x                                               0x1128A48
#define __AltTimerReady_x                                          0xF883B1
#define __Attack_x                                                 0x101B5CB
#define __Autofire_x                                               0x101B5CC
#define __BindList_x                                               0xBB53C8
#define __bCommandEnabled_x                                        0xF864C0
#define __Clicks_x                                                 0xF97120
#define __CommandList_x                                            0xBB9690
#define __CurrentMapLabel_x                                        0x112E498
#define __CurrentSocial_x                                          0xB72950
#define __DoAbilityList_x                                          0xFCD880
#define __do_loot_x                                                0x50CD90
#define __DrawHandler_x                                            0x17930A4
#define __GroupCount_x                                             0xF87A8A

#define __Guilds_x                                                 0xF8D6A0
#define __gWorld_x                                                 0xF89F44
#define __HotkeyPage_x                                             0x1014280
#define __HWnd_x                                                   0x1020948
#define __InChatMode_x                                             0xF9704C
#define __LastTell_x                                               0xF98F88
#define __LMouseHeldTime_x                                         0xF9718C
#define __Mouse_x                                                  0x1128A4C
#define __MouseLook_x                                              0xF970E6
#define __MouseEventTime_x                                         0x101BDD4
#define __NetStatusToggle_x                                        0xF970E9
#define __PCNames_x                                                0xF985AC
#define __RangeAttackReady_x                                       0xF98270
#define __RMouseHeldTime_x                                         0xF97188
#define __RunWalkState_x                                           0xF97050
#define __ScreenMode_x                                             0xED6378
#define __ScreenX_x                                                0xF97004
#define __ScreenY_x                                                0xF97000
#define __ScreenXMax_x                                             0xF97008
#define __ScreenYMax_x                                             0xF9700C
#define __ServerHost_x                                             0xF879D4
#define __ServerName_x                                             0xFCD840
#define __ShiftKeyDown_x                                           0xF976F4
#define __ShowNames_x                                              0xF98444
#define __Socials_x                                                0xFCD940
#define __SubscriptionType_x                                       0x115A828
#define __TargetAggroHolder_x                                      0x11306D4
#define __GroupAggro_x                                             0x1130714
#define __LoginName_x                                              0x101F520
#define __Inviter_x                                                0x101B548


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF8A030
#define instEQZoneInfo_x                                           0xF972DC
#define instKeypressHandler_x                                      0x101BDB8
#define pinstActiveBanker_x                                        0xF89FE8
#define pinstActiveCorpse_x                                        0xF89FEC
#define pinstActiveGMaster_x                                       0xF89FF0
#define pinstActiveMerchant_x                                      0xF89FE4
#define pinstAggroInfo_x                                           0xD9A7F8
#define pinstAltAdvManager_x                                       0xED7460
#define pinstAuraMgr_x                                             0xDA46C0
#define pinstBandageTarget_x                                       0xF89FD0
#define pinstCamActor_x                                            0xED6D68
#define pinstCDBStr_x                                              0xED630C
#define pinstCDisplay_x                                            0xF89FF8
#define pinstCEverQuest_x                                          0x1128BC0
#define pinstCharData_x                                            0xF89FB4
#define pinstCharSpawn_x                                           0xF89FDC
#define pinstControlledMissile_x                                   0xF89FB0
#define pinstControlledPlayer_x                                    0xF89FDC
#define pinstCSidlManager_x                                        0x17924C4
#define pinstCXWndManager_x                                        0x17924BC
#define instDynamicZone_x                                          0xF96E98
#define pinstDZMember_x                                            0xF96FA8
#define pinstDZTimerInfo_x                                         0xF96FAC
#define pinstEQItemList_x                                          0xF86710
#define instEQMisc_x                                               0xB93110
#define pinstEQSoundManager_x                                      0xED7858
#define instExpeditionLeader_x                                     0xF96EE2
#define instExpeditionName_x                                       0xF96F22
#define pinstGroup_x                                               0xF87A86
#define pinstImeManager_x                                          0x17924C8
#define pinstLocalPlayer_x                                         0xF89FC8
#define pinstMercenaryData_x                                       0x101C408
#define pinstMercAltAbilities_x                                    0xED7774
#define pinstModelPlayer_x                                         0xF89FF4
#define pinstPCData_x                                              0xF89FB4
#define pinstSkillMgr_x                                            0x101D240
#define pinstSpawnManager_x                                        0x101CB28
#define pinstSpellManager_x                                        0x101D388
#define pinstSpellSets_x                                           0x10142E4
#define pinstStringTable_x                                         0xF89F5C
#define pinstSwitchManager_x                                       0xF87618
#define pinstTarget_x                                              0xF89FE0
#define pinstTargetObject_x                                        0xF89FB8
#define pinstTargetSwitch_x                                        0xF89FBC
#define pinstTaskMember_x                                          0xED6258
#define pinstTrackTarget_x                                         0xF89FD4
#define pinstTradeTarget_x                                         0xF89FC4
#define instTributeActive_x                                        0xB93135
#define pinstViewActor_x                                           0xED6D64
#define pinstWorldData_x                                           0xF89F98


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD9ACD8
#define pinstCAudioTriggersWindow_x                                0xD9AB68
#define pinstCCharacterSelect_x                                    0xED6C08
#define pinstCFacePick_x                                           0xED6BB8
#define pinstCNoteWnd_x                                            0xED6BC0
#define pinstCBookWnd_x                                            0xED6BC8
#define pinstCPetInfoWnd_x                                         0xED6BCC
#define pinstCTrainWnd_x                                           0xED6BD0
#define pinstCSkillsWnd_x                                          0xED6BD4
#define pinstCSkillsSelectWnd_x                                    0xED6BD8
#define pinstCCombatSkillSelectWnd_x                               0xED6BDC
#define pinstCFriendsWnd_x                                         0xED6BE0
#define pinstCAuraWnd_x                                            0xED6BE4
#define pinstCRespawnWnd_x                                         0xED6BE8
#define pinstCBandolierWnd_x                                       0xED6BEC
#define pinstCPotionBeltWnd_x                                      0xED6BF0
#define pinstCAAWnd_x                                              0xED6BF4
#define pinstCGroupSearchFiltersWnd_x                              0xED6BF8
#define pinstCLoadskinWnd_x                                        0xED6BFC
#define pinstCAlarmWnd_x                                           0xED6C00
#define pinstCMusicPlayerWnd_x                                     0xED6C04
#define pinstCMailWnd_x                                            0xED6C0C
#define pinstCMailCompositionWnd_x                                 0xED6C10
#define pinstCMailAddressBookWnd_x                                 0xED6C14
#define pinstCRaidWnd_x                                            0xED6C1C
#define pinstCRaidOptionsWnd_x                                     0xED6C20
#define pinstCBreathWnd_x                                          0xED6C24
#define pinstCMapViewWnd_x                                         0xED6C28
#define pinstCMapToolbarWnd_x                                      0xED6C2C
#define pinstCEditLabelWnd_x                                       0xED6C30
#define pinstCTargetWnd_x                                          0xED6C34
#define pinstCColorPickerWnd_x                                     0xED6C38
#define pinstCPlayerWnd_x                                          0xED6C3C
#define pinstCOptionsWnd_x                                         0xED6C40
#define pinstCBuffWindowNORMAL_x                                   0xED6C44
#define pinstCBuffWindowSHORT_x                                    0xED6C48
#define pinstCharacterCreation_x                                   0xED6C4C
#define pinstCCursorAttachment_x                                   0xED6C50
#define pinstCCastingWnd_x                                         0xED6C54
#define pinstCCastSpellWnd_x                                       0xED6C58
#define pinstCSpellBookWnd_x                                       0xED6C5C
#define pinstCInventoryWnd_x                                       0xED6C60
#define pinstCBankWnd_x                                            0xED6C64
#define pinstCQuantityWnd_x                                        0xED6C68
#define pinstCLootWnd_x                                            0xED6C6C
#define pinstCActionsWnd_x                                         0xED6C70
#define pinstCCombatAbilityWnd_x                                   0xED6C74
#define pinstCMerchantWnd_x                                        0xED6C78
#define pinstCTradeWnd_x                                           0xED6C7C
#define pinstCSelectorWnd_x                                        0xED6C80
#define pinstCBazaarWnd_x                                          0xED6C84
#define pinstCBazaarSearchWnd_x                                    0xED6C88
#define pinstCGiveWnd_x                                            0xED6CA4
#define pinstCTrackingWnd_x                                        0xED6CAC
#define pinstCInspectWnd_x                                         0xED6CB0
#define pinstCSocialEditWnd_x                                      0xED6CB4
#define pinstCFeedbackWnd_x                                        0xED6CB8
#define pinstCBugReportWnd_x                                       0xED6CBC
#define pinstCVideoModesWnd_x                                      0xED6CC0
#define pinstCTextEntryWnd_x                                       0xED6CC8
#define pinstCFileSelectionWnd_x                                   0xED6CCC
#define pinstCCompassWnd_x                                         0xED6CD0
#define pinstCPlayerNotesWnd_x                                     0xED6CD4
#define pinstCGemsGameWnd_x                                        0xED6CD8
#define pinstCTimeLeftWnd_x                                        0xED6CDC
#define pinstCPetitionQWnd_x                                       0xED6CF0
#define pinstCSoulmarkWnd_x                                        0xED6CF4
#define pinstCStoryWnd_x                                           0xED6CF8
#define pinstCJournalTextWnd_x                                     0xED6CFC
#define pinstCJournalCatWnd_x                                      0xED6D00
#define pinstCBodyTintWnd_x                                        0xED6D04
#define pinstCServerListWnd_x                                      0xED6D08
#define pinstCAvaZoneWnd_x                                         0xED6D14
#define pinstCBlockedBuffWnd_x                                     0xED6D18
#define pinstCBlockedPetBuffWnd_x                                  0xED6D1C
#define pinstCInvSlotMgr_x                                         0xED6D5C
#define pinstCContainerMgr_x                                       0xED6D60
#define pinstCAdventureLeaderboardWnd_x                            0x1129570
#define pinstCAdventureRequestWnd_x                                0x11295E8
#define pinstCAltStorageWnd_x                                      0x11298C8
#define pinstCAdventureStatsWnd_x                                  0x1129660
#define pinstCBarterMerchantWnd_x                                  0x112A4B0
#define pinstCBarterSearchWnd_x                                    0x112A528
#define pinstCBarterWnd_x                                          0x112A5A0
#define pinstCChatManager_x                                        0x112AC30
#define pinstCDynamicZoneWnd_x                                     0x112B0E0
#define pinstCEQMainWnd_x                                          0x112B278
#define pinstCFellowshipWnd_x                                      0x112B074
#define pinstCFindLocationWnd_x                                    0x112B548
#define pinstCGroupSearchWnd_x                                     0x112B818
#define pinstCGroupWnd_x                                           0x112B890
#define pinstCGuildBankWnd_x                                       0x112B908
#define pinstCGuildMgmtWnd_x                                       0x112D9F8
#define pinstCHotButtonWnd_x                                       0x112DAC4
#define pinstCHotButtonWnd1_x                                      0x112DAC4
#define pinstCHotButtonWnd2_x                                      0x112DAC8
#define pinstCHotButtonWnd3_x                                      0x112DACC
#define pinstCHotButtonWnd4_x                                      0x112DAF0
#define pinstCItemDisplayManager_x                                 0x112DDE8
#define pinstCItemExpTransferWnd_x                                 0x112DE64
#define pinstCLFGuildWnd_x                                         0x112E140
#define pinstCMIZoneSelectWnd_x                                    0x112E728
#define pinstCConfirmationDialog_x                                 0x112EE30
#define pinstCPopupWndManager_x                                    0x112EE30
#define pinstCProgressionSelectionWnd_x                            0x112EF20
#define pinstCPvPStatsWnd_x                                        0x112F010
#define pinstCSystemInfoDialogBox_x                                0x112F718
#define pinstCTaskWnd_x                                            0x1130AE0
#define pinstCTaskSomething_x                                      0xDA4E00
#define pinstCTaskTemplateSelectWnd_x                              0x1130A68
#define pinstCTipWndOFDAY_x                                        0x1130D38
#define pinstCTipWndCONTEXT_x                                      0x1130D3C
#define pinstCTitleWnd_x                                           0x1130DB8
#define pinstCContextMenuManager_x                                 0x1792530
#define pinstCVoiceMacroWnd_x                                      0x101D9F0
#define pinstCHtmlWnd_x                                            0x101DAE8
#define pinstIconCache_x                                           0x112B24C
#define pinstCTradeskillWnd_x                                      0x1130EB8

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5247A0
#define __ConvertItemTags_x                                        0x511A20
#define __ExecuteCmd_x                                             0x4FC3D0
#define __EQGetTime_x                                              0x857780
#define __get_melee_range_x                                        0x5030C0
#define __GetGaugeValueFromEQ_x                                    0x7974E0
#define __GetLabelFromEQ_x                                         0x798720
#define __ToggleMount_x                                            0x6C11F0
#define __GetXTargetType_x                                         0x915D20
#define __LoadFrontEnd_x                                           0x626210
#define __NewUIINI_x                                               0x796DF0
#define __ProcessGameEvents_x                                      0x568300
#define __ProcessMouseEvent_x                                      0x567AA0
#define CrashDetected_x                                            0x627CE0
#define wwsCrashReportCheckForUploader_x                           0x7EC710
#define DrawNetStatus_x                                            0x59ED60
#define Util__FastTime_x                                           0x8572D0
#define Expansion_HoT_x                                            0xF983DC
#define __HelpPath_x                                               0x101BB40
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4BD400
#define AltAdvManager__IsAbilityReady_x                            0x4BD470
#define AltAdvManager__GetAltAbility_x                             0x4BD830

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x461E80
#define CharacterZoneClient__MakeMeVisible_x                       0x466F40

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x655A80

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6636E0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x57E420

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x67EE00
#define CChatManager__InitContextMenu_x                            0x67F920

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8C6E00
#define CContextMenu__AddMenuItem_x                                0x8C7020
#define CContextMenu__dCContextMenu_x                              0x8C7010
#define CContextMenu__RemoveMenuItem_x                             0x8C7310
#define CContextMenu__RemoveAllMenuItems_x                         0x8C7330
#define CContextMenuManager__AddMenu_x                             0x8C76E0
#define CContextMenuManager__RemoveMenu_x                          0x8C7A20
#define CContextMenuManager__PopupMenu_x                           0x8C7E70
#define CContextMenuManager__Flush_x                               0x8C7750

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x83DEA0
#define CChatService__GetFriendName_x                              0x83DEB0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x684990
#define CChatWindow__Clear_x                                       0x684540
#define CChatWindow__WndNotification_x                             0x684ED0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BA4D0
#define CComboWnd__Draw_x                                          0x8BA6E0
#define CComboWnd__GetCurChoice_x                                  0x8BA2A0
#define CComboWnd__GetListRect_x                                   0x8BA980
#define CComboWnd__GetTextRect_x                                   0x8BA540
#define CComboWnd__InsertChoice_x                                  0x8BA9F0
#define CComboWnd__SetColors_x                                     0x8BA230
#define CComboWnd__SetChoice_x                                     0x8BA260

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x68E0B0
#define CContainerWnd__vftable_x                                   0xA807F8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4ABC10
#define CDisplay__GetClickedActor_x                                0x4A4790
#define CDisplay__GetUserDefinedColor_x                            0x4A3050
#define CDisplay__GetWorldFilePath_x                               0x4A24A0
#define CDisplay__is3dON_x                                         0x4A1870
#define CDisplay__ReloadUI_x                                       0x4B7010
#define CDisplay__WriteTextHD2_x                                   0x4A7FB0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8DDEE0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8CC310
#define CEditWnd__GetCharIndexPt_x                                 0x8CD330
#define CEditWnd__GetDisplayString_x                               0x8CC4C0
#define CEditWnd__GetHorzOffset_x                                  0x8CC800
#define CEditWnd__GetLineForPrintableChar_x                        0x8CCE00
#define CEditWnd__GetSelStartPt_x                                  0x8CD5E0
#define CEditWnd__GetSTMLSafeText_x                                0x8CC9A0
#define CEditWnd__PointFromPrintableChar_x                         0x8CCEF0
#define CEditWnd__SelectableCharFromPoint_x                        0x8CD070
#define CEditWnd__SetEditable_x                                    0x8CC970

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x545C10
#define CEverQuest__DoTellWindow_x                                 0x54B610
#define CEverQuest__DropHeldItemOnGround_x                         0x554140
#define CEverQuest__dsp_chat_x                                     0x54CDB0
#define CEverQuest__Emote_x                                        0x54D010
#define CEverQuest__EnterZone_x                                    0x560920
#define CEverQuest__GetBodyTypeDesc_x                              0x542470
#define CEverQuest__GetClassDesc_x                                 0x548180
#define CEverQuest__GetClassThreeLetterCode_x                      0x548780
#define CEverQuest__GetDeityDesc_x                                 0x542D50
#define CEverQuest__GetLangDesc_x                                  0x542800
#define CEverQuest__GetRaceDesc_x                                  0x548940
#define CEverQuest__InterpretCmd_x                                 0x54D8F0
#define CEverQuest__LeftClickedOnPlayer_x                          0x564A00
#define CEverQuest__LMouseUp_x                                     0x566AF0
#define CEverQuest__RightClickedOnPlayer_x                         0x565500
#define CEverQuest__RMouseUp_x                                     0x566550
#define CEverQuest__SetGameState_x                                 0x5462C0
#define CEverQuest__UPCNotificationFlush_x                         0x54EA90
#define CEverQuest__IssuePetCommand_x                              0x54E5F0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x69EC00
#define CGaugeWnd__CalcLinesFillRect_x                             0x69EC60
#define CGaugeWnd__Draw_x                                          0x69F090

// CGuild
#define CGuild__FindMemberByName_x                                 0x433860

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6BBC60

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6C9A20
#define CInvSlotMgr__MoveItem_x                                    0x6CA950
#define CInvSlotMgr__SelectSlot_x                                  0x6C9AD0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6C8EC0
#define CInvSlot__SliderComplete_x                                 0x6C6880
#define CInvSlot__GetItemBase_x                                    0x6C5D10

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6CBAC0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x793FE0
#define CItemDisplayWnd__UpdateStrings_x                           0x6CCDF0

// CLabel 
#define CLabel__Draw_x                                             0x6E79D0

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8A3690
#define CListWnd__dCListWnd_x                                      0x8A4720
#define CListWnd__AddColumn_x                                      0x8A46C0
#define CListWnd__AddColumn1_x                                     0x8A3EA0
#define CListWnd__AddLine_x                                        0x8A3950
#define CListWnd__AddString_x                                      0x8A3B60
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A09E0
#define CListWnd__CalculateVSBRange_x                              0x8A2B50
#define CListWnd__ClearAllSel_x                                    0x89FCA0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8A3520
#define CListWnd__Compare_x                                        0x8A14E0
#define CListWnd__Draw_x                                           0x8A2760
#define CListWnd__DrawColumnSeparators_x                           0x8A25F0
#define CListWnd__DrawHeader_x                                     0x89FFB0
#define CListWnd__DrawItem_x                                       0x8A1B20
#define CListWnd__DrawLine_x                                       0x8A2290
#define CListWnd__DrawSeparator_x                                  0x8A2690
#define CListWnd__EnsureVisible_x                                  0x8A0B40
#define CListWnd__ExtendSel_x                                      0x8A1A30
#define CListWnd__GetColumnMinWidth_x                              0x89F6C0
#define CListWnd__GetColumnWidth_x                                 0x89F5E0
#define CListWnd__GetCurSel_x                                      0x89EDB0
#define CListWnd__GetItemAtPoint_x                                 0x8A0DD0
#define CListWnd__GetItemAtPoint1_x                                0x8A0E40
#define CListWnd__GetItemData_x                                    0x89F0F0
#define CListWnd__GetItemHeight_x                                  0x8A0640
#define CListWnd__GetItemIcon_x                                    0x89F2D0
#define CListWnd__GetItemRect_x                                    0x8A0C10
#define CListWnd__GetItemText_x                                    0x89F180
#define CListWnd__GetSelList_x                                     0x8A3D90
#define CListWnd__GetSeparatorRect_x                               0x8A1400
#define CListWnd__RemoveLine_x                                     0x8A3D40
#define CListWnd__SetColors_x                                      0x89EF00
#define CListWnd__SetColumnJustification_x                         0x89F990
#define CListWnd__SetColumnWidth_x                                 0x89F670
#define CListWnd__SetCurSel_x                                      0x89EDF0
#define CListWnd__SetItemColor_x                                   0x8A3200
#define CListWnd__SetItemData_x                                    0x89FD50
#define CListWnd__SetItemText_x                                    0x8A3040
#define CListWnd__ShiftColumnSeparator_x                           0x8A2ED0
#define CListWnd__Sort_x                                           0x8A4820
#define CListWnd__ToggleSel_x                                      0x89FC20

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x700E20

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x722080
#define CMerchantWnd__RequestBuyItem_x                             0x728EA0
#define CMerchantWnd__RequestSellItem_x                            0x729910
#define CMerchantWnd__SelectRecoverySlot_x                         0x722330
#define CMerchantWnd__SelectBuySellSlot_x                          0x721590
#define CMerchantWnd__ActualSelect_x                               0x725DD0

// CObfuscator
#define CObfuscator__doit_x                                        0x81E080

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8C1CD0
#define CSidlManager__CreateLabel_x                                0x789FB0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x64CCB0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x64CB90
#define CSidlScreenWnd__ConvertToRes_x                             0x8DDDC0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8AD8A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8AEDC0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8AEE70
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8AE320
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8AD270
#define CSidlScreenWnd__EnableIniStorage_x                         0x8AC9D0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8AD460
#define CSidlScreenWnd__Init1_x                                    0x8AEA90
#define CSidlScreenWnd__LoadIniInfo_x                              0x8AD950
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8ACB90
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8AE570
#define CSidlScreenWnd__StoreIniInfo_x                             0x8AC490
#define CSidlScreenWnd__StoreIniVis_x                              0x8AC960
#define CSidlScreenWnd__WndNotification_x                          0x8AE810
#define CSidlScreenWnd__GetChildItem_x                             0x8ACAA0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B2EB0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5E8280
#define CSkillMgr__GetSkillCap_x                                   0x5E8420
#define CSkillMgr__GetNameToken_x                                  0x5E7EF0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8DD070
#define CSliderWnd__SetValue_x                                     0x8DD240
#define CSliderWnd__SetNumTicks_x                                  0x8DD9C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x791C80

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8D7A10
#define CStmlWnd__CalculateHSBRange_x                              0x8CFFC0
#define CStmlWnd__CalculateVSBRange_x                              0x8CFF30
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D0140
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D0A20
#define CStmlWnd__ForceParseNow_x                                  0x8D8360
#define CStmlWnd__GetNextTagPiece_x                                0x8D0920
#define CStmlWnd__GetSTMLText_x                                    0x683DE0
#define CStmlWnd__GetVisibleText_x                                 0x8D1470
#define CStmlWnd__InitializeWindowVariables_x                      0x8D37F0
#define CStmlWnd__MakeStmlColorTag_x                               0x8CF230
#define CStmlWnd__MakeWndNotificationTag_x                         0x8CF290
#define CStmlWnd__SetSTMLText_x                                    0x8D5050
#define CStmlWnd__StripFirstSTMLLines_x                            0x8D76B0
#define CStmlWnd__UpdateHistoryString_x                            0x8D23B0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8DF5C0
#define CTabWnd__DrawCurrentPage_x                                 0x8DEE30
#define CTabWnd__DrawTab_x                                         0x8DEBF0
#define CTabWnd__GetCurrentPage_x                                  0x8DF200
#define CTabWnd__GetPageInnerRect_x                                0x8DE8E0
#define CTabWnd__GetTabInnerRect_x                                 0x8DEAE0
#define CTabWnd__GetTabRect_x                                      0x8DE9B0
#define CTabWnd__InsertPage_x                                      0x8DF8B0
#define CTabWnd__SetPage_x                                         0x8DF230
#define CTabWnd__SetPageRect_x                                     0x8DF500
#define CTabWnd__UpdatePage_x                                      0x8DF850

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x42F650

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B9EA0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8E4790

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x89D060

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x4148D0
#define CXStr__CXStr1_x                                            0x892750
#define CXStr__CXStr3_x                                            0x854360
#define CXStr__dCXStr_x                                            0x4767C0
#define CXStr__operator_equal_x                                    0x8544D0
#define CXStr__operator_equal1_x                                   0x854520
#define CXStr__operator_plus_equal1_x                              0x855600

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B20F0
#define CXWnd__Center_x                                            0x8B81B0
#define CXWnd__ClrFocus_x                                          0x8B1CE0
#define CXWnd__DoAllDrawing_x                                      0x8B7E00
#define CXWnd__DrawChildren_x                                      0x8B7FA0

#define CXWnd__DrawColoredRect_x                                   0x8B24A0
#define CXWnd__DrawTooltip_x                                       0x8B2740
#define CXWnd__DrawTooltipAtPoint_x                                0x8B6D90
#define CXWnd__GetBorderFrame_x                                    0x8B2B90
#define CXWnd__GetChildWndAt_x                                     0x8B8B70
#define CXWnd__GetClientClipRect_x                                 0x8B2950
#define CXWnd__GetScreenClipRect_x                                 0x8B7490
#define CXWnd__GetScreenRect_x                                     0x8B2D50
#define CXWnd__GetTooltipRect_x                                    0x8B25D0
#define CXWnd__GetWindowTextA_x                                    0x420CA0
#define CXWnd__IsActive_x                                          0x8A7520
#define CXWnd__IsDescendantOf_x                                    0x8B2AD0
#define CXWnd__IsReallyVisible_x                                   0x8B5DD0
#define CXWnd__IsType_x                                            0x8E0FB0
#define CXWnd__Move_x                                              0x8B54F0
#define CXWnd__Move1_x                                             0x8B7AC0
#define CXWnd__ProcessTransition_x                                 0x8B20A0
#define CXWnd__Refade_x                                            0x8B1E80
#define CXWnd__Resize_x                                            0x8B2E10
#define CXWnd__Right_x                                             0x8B7290
#define CXWnd__SetFocus_x                                          0x8B4670
#define CXWnd__SetFont_x                                           0x8B1D30
#define CXWnd__SetKeyTooltip_x                                     0x8B3080
#define CXWnd__SetMouseOver_x                                      0x8B77D0
#define CXWnd__StartFade_x                                         0x8B2140
#define CXWnd__GetChildItem_x                                      0x8B7710

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A8E40
#define CXWndManager__DrawWindows_x                                0x8A8A90
#define CXWndManager__GetKeyboardFlags_x                           0x8A7050
#define CXWndManager__HandleKeyboardMsg_x                          0x8A79C0
#define CXWndManager__RemoveWnd_x                                  0x8A76B0

// CDBStr
#define CDBStr__GetString_x                                        0x49FD10

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44B7C0
#define EQ_Character__Cur_HP_x                                     0x461550
#define EQ_Character__GetAACastingTimeModifier_x                   0x4448C0
#define EQ_Character__GetCharInfo2_x                               0x828890
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43CC80
#define EQ_Character__GetFocusRangeModifier_x                      0x43CE60
#define EQ_Character__Max_Endurance_x                              0x5B0F20
#define EQ_Character__Max_HP_x                                     0x457850
#define EQ_Character__Max_Mana_x                                   0x5B0D50
#define EQ_Character__doCombatAbility_x                            0x5AE340
#define EQ_Character__UseSkill_x                                   0x46C070
#define EQ_Character__GetConLevel_x                                0x5A3380
#define EQ_Character__IsExpansionFlag_x                            0x4201F0
#define EQ_Character__TotalEffect_x                                0x4498F0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x583BA0
#define EQ_Item__CreateItemTagString_x                             0x807E00
#define EQ_Item__IsStackable_x                                     0x7FC3B0
#define EQ_Item__GetImageNum_x                                     0x7FF030

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4BF4F0
#define EQ_LoadingS__Array_x                                       0xBA0D10

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B26B0
#define EQ_PC__GetAltAbilityIndex_x                                0x810DE0
#define EQ_PC__GetCombatAbility_x                                  0x810E70
#define EQ_PC__GetCombatAbilityTimer_x                             0x810F20
#define EQ_PC__GetItemTimerValue_x                                 0x5AC110
#define EQ_PC__HasLoreItem_x                                       0x5A66D0
#define EQ_PC__AlertInventoryChanged_x                             0x5A3350
#define EQ_PC__GetPcZoneClient_x                                   0x5CCAF0
#define EQ_PC__RemoveMyAffect_x                                    0x5AB620

// EQItemList 
#define EQItemList__EQItemList_x                                   0x5010A0
#define EQItemList__add_item_x                                     0x500FE0
#define EQItemList__delete_item_x                                  0x5014A0
#define EQItemList__FreeItemList_x                                 0x5013A0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x49EFC0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5B7B60
#define EQPlayer__dEQPlayer_x                                      0x5C0970
#define EQPlayer__DoAttack_x                                       0x5D2960
#define EQPlayer__EQPlayer_x                                       0x5C2D90
#define EQPlayer__SetNameSpriteState_x                             0x5BD650
#define EQPlayer__SetNameSpriteTint_x                              0x5B8F30
#define EQPlayer__IsBodyType_j_x                                   0x911F60
#define EQPlayer__IsTargetable_x                                   0x912820
#define EQPlayer__CanSee_x                                         0x912D40

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5C70F0
#define EQPlayerManager__GetSpawnByName_x                          0x5C7550

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x589D10
#define KeypressHandler__AttachKeyToEqCommand_x                    0x589D50
#define KeypressHandler__ClearCommandStateArray_x                  0x5898F0
#define KeypressHandler__HandleKeyDown_x                           0x588250
#define KeypressHandler__HandleKeyUp_x                             0x588570
#define KeypressHandler__SaveKeymapping_x                          0x5899C0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6F9200
#define MapViewMap__SaveEx_x                                       0x6FCAE0

#define PlayerPointManager__GetAltCurrency_x                       0x823850

// StringTable 
#define StringTable__getString_x                                   0x81E320

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B09D0

//Doors
#define EQSwitch__UseSwitch_x                                      0x53F840

//IconCache
#define IconCache__GetIcon_x                                       0x694540

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x68B3B0
#define CContainerMgr__CloseContainer_x                            0x68BBD0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x75A3A0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x57CEE0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D1D40
#define EQ_Spell__SpellAffects_x                                   0x4D1DE0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D1E10
#define CharacterZoneClient__CalcAffectChange_x                    0x445BE0
#define CLootWnd__LootAll_x                                        0x6EEB60
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x79FAC0
#define CTargetWnd__WndNotification_x                              0x79F5B0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7A4C80
