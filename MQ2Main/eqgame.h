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
#define __ExpectedVersionDate                                     "Mar 13 2013"
#define __ExpectedVersionTime                                     "10:48:43"
#define __ActualVersionDate_x                                      0x9DAE98
#define __ActualVersionTime_x                                      0x9DAEA4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x563430
#define __MemChecker1_x                                            0x806E60
#define __MemChecker2_x                                            0x5F8590
#define __MemChecker3_x                                            0x5F84E0
#define __MemChecker4_x                                            0x8C9C70
#define __EncryptPad0_x                                            0xAE1840
#define __EncryptPad1_x                                            0xB5D5F8
#define __EncryptPad2_x                                            0xAFAA28
#define __EncryptPad3_x                                            0xAFA628
#define __EncryptPad4_x                                            0xB62DA8
#define __AC1_x                                                    0x761B75
#define __AC2_x                                                    0x517A97
#define __AC3_x                                                    0x52AED0
#define __AC4_x                                                    0x530F44
#define __AC5_x                                                    0x53CE6B
#define __AC6_x                                                    0x5407A2
#define __AC7_x                                                    0x536D8C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0xE63798
#define DI8__Keyboard_x                                            0xE6379C
#define DI8__Mouse_x                                               0xE637A0
#define __AltTimerReady_x                                          0xDCC679
#define __Attack_x                                                 0xE5F1FE
#define __Autofire_x                                               0xE5F1FF
#define __BindList_x                                               0xAC9900
#define __Clicks_x                                                 0xDDB394
#define __CommandList_x                                            0xACAF78
#define __CurrentMapLabel_x                                        0xF6FA50
#define __CurrentSocial_x                                          0xAB47B8
#define __DoAbilityList_x                                          0xE11AA4
#define __do_loot_x                                                0x4E68E0
#define __DrawHandler_x                                            0x15D02F4
#define __GroupCount_x                                             0xDCBD52

#define __Guilds_x                                                 0xDD1958
#define __gWorld_x                                                 0xDCE20C
#define __HotkeyPage_x                                             0xE584A4
#define __HWnd_x                                                   0xE634F0
#define __InChatMode_x                                             0xDDB2CC
#define __LastTell_x                                               0xDDD1AC
#define __LMouseHeldTime_x                                         0xDDB400
#define __Mouse_x                                                  0xE637A4
#define __MouseLook_x                                              0xDDB362
#define __MouseEventTime_x                                         0xE5F61C
#define __NetStatusToggle_x                                        0xDDB365
#define __PCNames_x                                                0xDDC820
#define __RangeAttackReady_x                                       0xDDC4BC
#define __RMouseHeldTime_x                                         0xDDB3FC
#define __RunWalkState_x                                           0xDDB2D0
#define __ScreenMode_x                                             0xD1B018
#define __ScreenX_x                                                0xDDB284
#define __ScreenY_x                                                0xDDB280
#define __ScreenXMax_x                                             0xDDB288
#define __ScreenYMax_x                                             0xDDB28C
#define __ServerHost_x                                             0xDCBC9C
#define __ServerName_x                                             0xE11A64
#define __ShiftKeyDown_x                                           0xDDB958
#define __ShowNames_x                                              0xDDC6C8
#define __Socials_x                                                0xE11B64


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xDCE2F0
#define instEQZoneInfo_x                                           0xDDB550
#define instKeypressHandler_x                                      0xE5F600
#define pinstActiveBanker_x                                        0xDCE2B0
#define pinstActiveCorpse_x                                        0xDCE2B4
#define pinstActiveGMaster_x                                       0xDCE2B8
#define pinstActiveMerchant_x                                      0xDCE2AC
#define pinstAggroInfo_x                                           0xB74CB0
#define pinstAltAdvManager_x                                       0xD1BFB8
#define pinstAuraMgr_x                                             0xB7E5B0
#define pinstBandageTarget_x                                       0xDCE298
#define pinstCamActor_x                                            0xD1B9EC
#define pinstCDBStr_x                                              0xD1AFE0
#define pinstCDisplay_x                                            0xDCE2C0
#define pinstCEverQuest_x                                          0xE6391C
#define pinstCharData_x                                            0xDCE27C
#define pinstCharSpawn_x                                           0xDCE2A4
#define pinstControlledMissile_x                                   0xDCE278
#define pinstControlledPlayer_x                                    0xDCE2A4
#define pinstCSidlManager_x                                        0x15CF958
#define pinstCXWndManager_x                                        0x15CF950
#define instDynamicZone_x                                          0xDDB130
#define pinstDZMember_x                                            0xDDB240
#define pinstDZTimerInfo_x                                         0xDDB244
#define pinstEQItemList_x                                          0xDCAD80
#define instEQMisc_x                                               0xABD898
#define pinstEQSoundManager_x                                      0xD1C0C0
#define instExpeditionLeader_x                                     0xDDB17A
#define instExpeditionName_x                                       0xDDB1BA
#define pinstGroup_x                                               0xDCBD4E
#define pinstImeManager_x                                          0x15CF95C
#define pinstLocalPlayer_x                                         0xDCE290
#define pinstMercenaryData_x                                       0xE5FAE0
#define pinstModelPlayer_x                                         0xDCE2BC
#define pinstPCData_x                                              0xDCE27C
#define pinstSkillMgr_x                                            0xE60260
#define pinstSpawnManager_x                                        0xE5FE20
#define pinstSpellManager_x                                        0xE60300
#define pinstSpellSets_x                                           0xE58508
#define pinstStringTable_x                                         0xDCE224
#define pinstSwitchManager_x                                       0xDCB960
#define pinstTarget_x                                              0xDCE2A8
#define pinstTargetObject_x                                        0xDCE280
#define pinstTargetSwitch_x                                        0xDCE284
#define pinstTaskMember_x                                          0xD1AF74
#define pinstTrackTarget_x                                         0xDCE29C
#define pinstTradeTarget_x                                         0xDCE28C
#define instTributeActive_x                                        0xABD8BD
#define pinstViewActor_x                                           0xD1B9E8
#define pinstWorldData_x                                           0xDCE260


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xB74F08
#define pinstCAudioTriggersWindow_x                                0xB74E40
#define pinstCCharacterSelect_x                                    0xD1B894
#define pinstCFacePick_x                                           0xD1B644
#define pinstCNoteWnd_x                                            0xD1B84C
#define pinstCBookWnd_x                                            0xD1B854
#define pinstCPetInfoWnd_x                                         0xD1B858
#define pinstCTrainWnd_x                                           0xD1B85C
#define pinstCSkillsWnd_x                                          0xD1B860
#define pinstCSkillsSelectWnd_x                                    0xD1B864
#define pinstCCombatSkillSelectWnd_x                               0xD1B868
#define pinstCFriendsWnd_x                                         0xD1B86C
#define pinstCAuraWnd_x                                            0xD1B870
#define pinstCRespawnWnd_x                                         0xD1B874
#define pinstCBandolierWnd_x                                       0xD1B878
#define pinstCPotionBeltWnd_x                                      0xD1B87C
#define pinstCAAWnd_x                                              0xD1B880
#define pinstCGroupSearchFiltersWnd_x                              0xD1B884
#define pinstCLoadskinWnd_x                                        0xD1B888
#define pinstCAlarmWnd_x                                           0xD1B88C
#define pinstCMusicPlayerWnd_x                                     0xD1B890
#define pinstCMailWnd_x                                            0xD1B898
#define pinstCMailCompositionWnd_x                                 0xD1B89C
#define pinstCMailAddressBookWnd_x                                 0xD1B8A0
#define pinstCRaidWnd_x                                            0xD1B8A8
#define pinstCRaidOptionsWnd_x                                     0xD1B8AC
#define pinstCBreathWnd_x                                          0xD1B8B0
#define pinstCMapViewWnd_x                                         0xD1B8B4
#define pinstCMapToolbarWnd_x                                      0xD1B8B8
#define pinstCEditLabelWnd_x                                       0xD1B8BC
#define pinstCTargetWnd_x                                          0xD1B8C0
#define pinstCColorPickerWnd_x                                     0xD1B8C4
#define pinstCPlayerWnd_x                                          0xD1B8C8
#define pinstCOptionsWnd_x                                         0xD1B8CC
#define pinstCBuffWindowNORMAL_x                                   0xD1B8D0
#define pinstCBuffWindowSHORT_x                                    0xD1B8D4
#define pinstCharacterCreation_x                                   0xD1B8D8
#define pinstCCursorAttachment_x                                   0xD1B8DC
#define pinstCCastingWnd_x                                         0xD1B8E0
#define pinstCCastSpellWnd_x                                       0xD1B8E4
#define pinstCSpellBookWnd_x                                       0xD1B8E8
#define pinstCInventoryWnd_x                                       0xD1B8EC
#define pinstCBankWnd_x                                            0xD1B8F0
#define pinstCQuantityWnd_x                                        0xD1B8F4
#define pinstCLootWnd_x                                            0xD1B8F8
#define pinstCActionsWnd_x                                         0xD1B8FC
#define pinstCCombatAbilityWnd_x                                   0xD1B900
#define pinstCMerchantWnd_x                                        0xD1B904
#define pinstCTradeWnd_x                                           0xD1B908
#define pinstCSelectorWnd_x                                        0xD1B90C
#define pinstCBazaarWnd_x                                          0xD1B910
#define pinstCBazaarSearchWnd_x                                    0xD1B914
#define pinstCGiveWnd_x                                            0xD1B930
#define pinstCTrackingWnd_x                                        0xD1B938
#define pinstCInspectWnd_x                                         0xD1B93C
#define pinstCSocialEditWnd_x                                      0xD1B940
#define pinstCFeedbackWnd_x                                        0xD1B944
#define pinstCBugReportWnd_x                                       0xD1B948
#define pinstCVideoModesWnd_x                                      0xD1B94C
#define pinstCTextEntryWnd_x                                       0xD1B954
#define pinstCFileSelectionWnd_x                                   0xD1B958
#define pinstCCompassWnd_x                                         0xD1B95C
#define pinstCPlayerNotesWnd_x                                     0xD1B960
#define pinstCGemsGameWnd_x                                        0xD1B964
#define pinstCTimeLeftWnd_x                                        0xD1B968
#define pinstCPetitionQWnd_x                                       0xD1B97C
#define pinstCSoulmarkWnd_x                                        0xD1B980
#define pinstCStoryWnd_x                                           0xD1B984
#define pinstCJournalTextWnd_x                                     0xD1B988
#define pinstCJournalCatWnd_x                                      0xD1B98C
#define pinstCBodyTintWnd_x                                        0xD1B990
#define pinstCServerListWnd_x                                      0xD1B994
#define pinstCAvaZoneWnd_x                                         0xD1B9A0
#define pinstCBlockedBuffWnd_x                                     0xD1B9A4
#define pinstCBlockedPetBuffWnd_x                                  0xD1B9A8
#define pinstCInvSlotMgr_x                                         0xD1B9E0
#define pinstCContainerMgr_x                                       0xD1B9E4
#define pinstCAdventureLeaderboardWnd_x                            0xF6C110
#define pinstCAdventureRequestWnd_x                                0xF6C150
#define pinstCAltStorageWnd_x                                      0xF6C2E0
#define pinstCAdventureStatsWnd_x                                  0xF6C190
#define pinstCBarterMerchantWnd_x                                  0xF6C8C0
#define pinstCBarterSearchWnd_x                                    0xF6C900
#define pinstCBarterWnd_x                                          0xF6C940
#define pinstCChatManager_x                                        0xF6CCC0
#define pinstCDynamicZoneWnd_x                                     0xF6CF30
#define pinstCEQMainWnd_x                                          0xF6D010
#define pinstCFellowshipWnd_x                                      0xF6CEFC
#define pinstCFindLocationWnd_x                                    0xF6D190
#define pinstCGroupSearchWnd_x                                     0xF6D340
#define pinstCGroupWnd_x                                           0xF6D380
#define pinstCGuildBankWnd_x                                       0xF6D3C0
#define pinstCGuildMgmtWnd_x                                       0xF6F440
#define pinstCHotButtonWnd_x                                       0xF6F4A4
#define pinstCHotButtonWnd1_x                                      0xF6F4A4
#define pinstCHotButtonWnd2_x                                      0xF6F4A8
#define pinstCHotButtonWnd3_x                                      0xF6F4AC
#define pinstCHotButtonWnd4_x                                      0xF6F4D0
#define pinstCItemDisplayManager_x                                 0xF6F678
#define pinstCItemExpTransferWnd_x                                 0xF6F6BC
#define pinstCLFGuildWnd_x                                         0xF6F878
#define pinstCMIZoneSelectWnd_x                                    0xF6FBC8
#define pinstCConfirmationDialog_x                                 0xF6FF88
#define pinstCPopupWndManager_x                                    0xF6FF88
#define pinstCProgressionSelectionWnd_x                            0xF70008
#define pinstCPvPStatsWnd_x                                        0xF70088
#define pinstCSystemInfoDialogBox_x                                0xF70448
#define pinstCTaskTemplateSelectWnd_x                              0xF713A0
#define pinstCTipWndOFDAY_x                                        0xF71510
#define pinstCTipWndCONTEXT_x                                      0xF71514
#define pinstCTitleWnd_x                                           0xF71558
#define pinstCContextMenuManager_x                                 0x15CF56C
#define pinstCVoiceMacroWnd_x                                      0xE606B0
#define pinstCHtmlWnd_x                                            0xE60738


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x4FC200
#define __ConvertItemTags_x                                        0x4EC170
#define __ExecuteCmd_x                                             0x4D6570
#define __EQGetTime_x                                              0x8079C0
#define __get_melee_range_x                                        0x4DD1B0
#define __GetGaugeValueFromEQ_x                                    0x7608D0
#define __GetLabelFromEQ_x                                         0x761B00
#define __GetXTargetType_x                                         0x8D17C0
#define __LoadFrontEnd_x                                           0x5F7C40
#define __NewUIINI_x                                               0x760200
#define __ProcessGameEvents_x                                      0x538E70
#define CrashDetected_x                                            0x5FA2BB
#define DrawNetStatus_x                                            0x5726A0
#define Util__FastTime_x                                           0x806D00
#define Expansion_HoT_x                                            0xDDC628
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A2890
#define AltAdvManager__IsAbilityReady_x                            0x4A28D0
#define AltAdvManager__GetAltAbility_x                             0x4A2CB0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x44A000

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x626A50

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6346C0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x54EC60

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x64F320
#define CChatManager__InitContextMenu_x                            0x64FE40

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x7EDAF0
#define CChatService__GetFriendName_x                              0x7EDB00

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x654B80
#define CChatWindow__Clear_x                                       0x654730
#define CChatWindow__WndNotification_x                             0x6550C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x868790
#define CComboWnd__Draw_x                                          0x868970
#define CComboWnd__GetCurChoice_x                                  0x8685B0
#define CComboWnd__GetListRect_x                                   0x868C10
#define CComboWnd__GetTextRect_x                                   0x8687F0
#define CComboWnd__InsertChoice_x                                  0x868C80
#define CComboWnd__SetColors_x                                     0x868540
#define CComboWnd__SetChoice_x                                     0x868570

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x65E0C0
#define CContainerWnd__vftable_x                                   0x9E43A0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x492760
#define CDisplay__GetClickedActor_x                                0x48A880
#define CDisplay__GetUserDefinedColor_x                            0x489150
#define CDisplay__GetWorldFilePath_x                               0x488550
#define CDisplay__is3dON_x                                         0x487630
#define CDisplay__ReloadUI_x                                       0x49C730
#define CDisplay__WriteTextHD2_x                                   0x48DC90

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x889F20

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x879090
#define CEditWnd__GetCharIndexPt_x                                 0x87A0C0
#define CEditWnd__GetDisplayString_x                               0x879240
#define CEditWnd__GetHorzOffset_x                                  0x879580
#define CEditWnd__GetLineForPrintableChar_x                        0x879B80
#define CEditWnd__GetSelStartPt_x                                  0x87A380
#define CEditWnd__GetSTMLSafeText_x                                0x879720
#define CEditWnd__PointFromPrintableChar_x                         0x879C70
#define CEditWnd__SelectableCharFromPoint_x                        0x879DF0
#define CEditWnd__SetEditable_x                                    0x8796F0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x5181E0
#define CEverQuest__DoTellWindow_x                                 0x51CB40
#define CEverQuest__DropHeldItemOnGround_x                         0x5253D0
#define CEverQuest__dsp_chat_x                                     0x51E2E0
#define CEverQuest__Emote_x                                        0x51E540
#define CEverQuest__EnterZone_x                                    0x5310D0
#define CEverQuest__GetBodyTypeDesc_x                              0x5147A0
#define CEverQuest__GetClassDesc_x                                 0x513F00
#define CEverQuest__GetClassThreeLetterCode_x                      0x514500
#define CEverQuest__GetDeityDesc_x                                 0x5150B0
#define CEverQuest__GetLangDesc_x                                  0x514B30
#define CEverQuest__GetRaceDesc_x                                  0x514E20
#define CEverQuest__InterpretCmd_x                                 0x51EE20
#define CEverQuest__LeftClickedOnPlayer_x                          0x535320
#define CEverQuest__LMouseUp_x                                     0x5374E0
#define CEverQuest__RightClickedOnPlayer_x                         0x535D90
#define CEverQuest__RMouseUp_x                                     0x536D40
#define CEverQuest__SetGameState_x                                 0x518890
#define CEverQuest__UPCNotificationFlush_x                         0x51FDB0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x66DE40
#define CGaugeWnd__CalcLinesFillRect_x                             0x66DEA0
#define CGaugeWnd__Draw_x                                          0x66E2D0

// CGuild
#define CGuild__FindMemberByName_x                                 0x423BB0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x68AFC0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6963D0
#define CInvSlotMgr__MoveItem_x                                    0x697300

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x695830
#define CInvSlot__SliderComplete_x                                 0x6939B0
#define CInvSlot__GetItemBase_x                                    0x692EB0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x698090

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x75D590
#define CItemDisplayWnd__UpdateStrings_x                           0x6993F0

// CLabel 
#define CLabel__Draw_x                                             0x6B3380

// CListWnd 
#define CListWnd__AddColumn_x                                      0x856C00
#define CListWnd__AddColumn1_x                                     0x8563F0
#define CListWnd__AddLine_x                                        0x855EA0
#define CListWnd__AddString_x                                      0x8560B0
#define CListWnd__CalculateFirstVisibleLine_x                      0x852F60
#define CListWnd__CalculateVSBRange_x                              0x855090
#define CListWnd__ClearAllSel_x                                    0x852210
#define CListWnd__CloseAndUpdateEditWindow_x                       0x855A70
#define CListWnd__Compare_x                                        0x853A60
#define CListWnd__Draw_x                                           0x854CF0
#define CListWnd__DrawColumnSeparators_x                           0x854B80
#define CListWnd__DrawHeader_x                                     0x852520
#define CListWnd__DrawItem_x                                       0x8540B0
#define CListWnd__DrawLine_x                                       0x854820
#define CListWnd__DrawSeparator_x                                  0x854C20
#define CListWnd__EnsureVisible_x                                  0x8530C0
#define CListWnd__ExtendSel_x                                      0x853FC0
#define CListWnd__GetColumnMinWidth_x                              0x851C30
#define CListWnd__GetColumnWidth_x                                 0x851B50
#define CListWnd__GetCurSel_x                                      0x851430
#define CListWnd__GetItemAtPoint_x                                 0x853360
#define CListWnd__GetItemAtPoint1_x                                0x8533D0
#define CListWnd__GetItemData_x                                    0x851660
#define CListWnd__GetItemHeight_x                                  0x852BB0
#define CListWnd__GetItemIcon_x                                    0x851840
#define CListWnd__GetItemRect_x                                    0x8531A0
#define CListWnd__GetItemText_x                                    0x8516F0
#define CListWnd__GetSelList_x                                     0x8562E0
#define CListWnd__GetSeparatorRect_x                               0x853980
#define CListWnd__RemoveLine_x                                     0x856290
#define CListWnd__SetColors_x                                      0x851490
#define CListWnd__SetColumnJustification_x                         0x851F00
#define CListWnd__SetColumnWidth_x                                 0x851BE0
#define CListWnd__SetCurSel_x                                      0x851470
#define CListWnd__SetItemColor_x                                   0x855750
#define CListWnd__SetItemData_x                                    0x8522C0
#define CListWnd__SetItemText_x                                    0x855590
#define CListWnd__ShiftColumnSeparator_x                           0x855420
#define CListWnd__Sort_x                                           0x856D60
#define CListWnd__ToggleSel_x                                      0x852190

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6CE260

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6EDF00
#define CMerchantWnd__RequestBuyItem_x                             0x6F4330
#define CMerchantWnd__RequestSellItem_x                            0x71B200
#define CMerchantWnd__SelectBuySellSlot_x                          0x6EE1B0

// CObfuscator
#define CObfuscator__doit_x                                        0x7CE530

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x86DF40
#define CSidlManager__CreateLabel_x                                0x753BE0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x61DC01
#define CSidlScreenWnd__CalculateVSBRange_x                        0x61DB20
#define CSidlScreenWnd__ConvertToRes_x                             0x889E00
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x85BC80
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x85CF80
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x85D030
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x85C530
#define CSidlScreenWnd__DrawSidlPiece_x                            0x85B760
#define CSidlScreenWnd__EnableIniStorage_x                         0x85AE90
#define CSidlScreenWnd__GetSidlPiece_x                             0x85B950
#define CSidlScreenWnd__Init1_x                                    0x85CC60
#define CSidlScreenWnd__LoadIniInfo_x                              0x85BD30
#define CSidlScreenWnd__LoadIniListWnd_x                           0x85B050
#define CSidlScreenWnd__LoadSidlScreen_x                           0x85C780
#define CSidlScreenWnd__StoreIniInfo_x                             0x85AA40
#define CSidlScreenWnd__StoreIniVis_x                              0x85AE20
#define CSidlScreenWnd__WndNotification_x                          0x85C9E0
#define CSidlScreenWnd__GetChildItem_x                             0x85AF60

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5B9D60
#define CSkillMgr__GetSkillCap_x                                   0x5B9DD0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x893E50
#define CSliderWnd__SetValue_x                                     0x894020
#define CSliderWnd__SetNumTicks_x                                  0x8947A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x75AFF0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x884590
#define CStmlWnd__CalculateHSBRange_x                              0x87CCE0
#define CStmlWnd__CalculateVSBRange_x                              0x87CD70
#define CStmlWnd__CanBreakAtCharacter_x                            0x87CEF0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x87D7D0
#define CStmlWnd__ForceParseNow_x                                  0x884EE0
#define CStmlWnd__GetNextTagPiece_x                                0x87D6D0
#define CStmlWnd__GetSTMLText_x                                    0x653FD0
#define CStmlWnd__GetVisibleText_x                                 0x87E220
#define CStmlWnd__InitializeWindowVariables_x                      0x880400
#define CStmlWnd__MakeStmlColorTag_x                               0x87BF30
#define CStmlWnd__MakeWndNotificationTag_x                         0x87BF90
#define CStmlWnd__SetSTMLText_x                                    0x881C70
#define CStmlWnd__StripFirstSTMLLines_x                            0x884230
#define CStmlWnd__UpdateHistoryString_x                            0x87F160

// CTabWnd 
#define CTabWnd__Draw_x                                            0x88B600
#define CTabWnd__DrawCurrentPage_x                                 0x88AE70
#define CTabWnd__DrawTab_x                                         0x88AC30
#define CTabWnd__GetCurrentPage_x                                  0x88B240
#define CTabWnd__GetPageInnerRect_x                                0x88A920
#define CTabWnd__GetTabInnerRect_x                                 0x88AB20
#define CTabWnd__GetTabRect_x                                      0x88A9F0
#define CTabWnd__InsertPage_x                                      0x88B8F0
#define CTabWnd__SetPage_x                                         0x88B270
#define CTabWnd__SetPageRect_x                                     0x88B540
#define CTabWnd__UpdatePage_x                                      0x88B890

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41F6E0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8879E0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x890810

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x84F5E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x55BCD0
#define CXStr__CXStr1_x                                            0x505190
#define CXStr__CXStr3_x                                            0x803DD0
#define CXStr__dCXStr_x                                            0x753B90
#define CXStr__operator_equal_x                                    0x803F40
#define CXStr__operator_equal1_x                                   0x803F90
#define CXStr__operator_plus_equal1_x                              0x805070

// CXWnd 
#define CXWnd__BringToTop_x                                        0x860AE0
#define CXWnd__Center_x                                            0x866C10
#define CXWnd__ClrFocus_x                                          0x8606E0
#define CXWnd__DoAllDrawing_x                                      0x866880
#define CXWnd__DrawChildren_x                                      0x866A10
#define CXWnd__DrawColoredRect_x                                   0x860EA0
#define CXWnd__DrawTooltip_x                                       0x861150
#define CXWnd__DrawTooltipAtPoint_x                                0x865800
#define CXWnd__GetBorderFrame_x                                    0x861570
#define CXWnd__GetChildWndAt_x                                     0x8647F0
#define CXWnd__GetClientClipRect_x                                 0x861340
#define CXWnd__GetScreenClipRect_x                                 0x865F00
#define CXWnd__GetScreenRect_x                                     0x861720
#define CXWnd__GetTooltipRect_x                                    0x860FE0
#define CXWnd__GetWindowTextA_x                                    0x411030
#define CXWnd__IsActive_x                                          0x873EE0
#define CXWnd__IsDescendantOf_x                                    0x8614C0
#define CXWnd__IsReallyVisible_x                                   0x8647D0
#define CXWnd__IsType_x                                            0x88CF90
#define CXWnd__Move_x                                              0x863EF0
#define CXWnd__Move1_x                                             0x866530
#define CXWnd__ProcessTransition_x                                 0x860A90
#define CXWnd__Refade_x                                            0x860860
#define CXWnd__Resize_x                                            0x8617E0
#define CXWnd__Right_x                                             0x865D00
#define CXWnd__SetFocus_x                                          0x863050
#define CXWnd__SetFont_x                                           0x860730
#define CXWnd__SetKeyTooltip_x                                     0x861A50
#define CXWnd__SetMouseOver_x                                      0x866220
#define CXWnd__StartFade_x                                         0x860B30
#define CXWnd__GetChildItem_x                                      0x866170

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x875820
#define CXWndManager__DrawWindows_x                                0x875460
#define CXWndManager__GetKeyboardFlags_x                           0x873A10
#define CXWndManager__HandleKeyboardMsg_x                          0x874380
#define CXWndManager__RemoveWnd_x                                  0x874070

// CDBStr
#define CDBStr__GetString_x                                        0x485890

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8CE120
#define EQ_Character__CastSpell_x                                  0x43A690
#define EQ_Character__Cur_HP_x                                     0x449C50
#define EQ_Character__GetAACastingTimeModifier_x                   0x433510
#define EQ_Character__GetCharInfo2_x                               0x7D92D0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42C810
#define EQ_Character__GetFocusRangeModifier_x                      0x42C9F0
#define EQ_Character__Max_Endurance_x                              0x580FB0
#define EQ_Character__Max_HP_x                                     0x443DF0
#define EQ_Character__Max_Mana_x                                   0x580DF0
#define EQ_Character__doCombatAbility_x                            0x57F850
#define EQ_Character__UseSkill_x                                   0x45B120
#define EQ_Character__GetConLevel_x                                0x576C30
#define EQ_Character__IsExpansionFlag_x                            0x410550
#define EQ_Character__TotalEffect_x                                0x4387F0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x553FC0
#define EQ_Item__CreateItemTagString_x                             0x7B9E30
#define EQ_Item__IsStackable_x                                     0x7AE520

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A4900
#define EQ_LoadingS__Array_x                                       0xAC3E20

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x585280
#define EQ_PC__GetAltAbilityIndex_x                                0x7C2600
#define EQ_PC__GetCombatAbility_x                                  0x7C2690
#define EQ_PC__GetCombatAbilityTimer_x                             0x7C2740
#define EQ_PC__GetItemTimerValue_x                                 0x57F590
#define EQ_PC__HasLoreItem_x                                       0x579DB0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4DAEE0
#define EQItemList__add_item_x                                     0x4DAE20
#define EQItemList__delete_item_x                                  0x4DB2E0
#define EQItemList__FreeItemList_x                                 0x4DB1E0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x484D40

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x58AE20
#define EQPlayer__dEQPlayer_x                                      0x58F9B0
#define EQPlayer__DoAttack_x                                       0x5A3ED0
#define EQPlayer__EQPlayer_x                                       0x595140
#define EQPlayer__SetNameSpriteState_x                             0x58D260
#define EQPlayer__SetNameSpriteTint_x                              0x58AE90
#define EQPlayer__IsBodyType_j_x                                   0x8CD9C0
#define EQPlayer__IsTargetable_x                                   0x8CDC90

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5985D0
#define EQPlayerManager__GetSpawnByName_x                          0x598A30

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x55A000
#define KeypressHandler__AttachKeyToEqCommand_x                    0x55A040
#define KeypressHandler__ClearCommandStateArray_x                  0x559BE0
#define KeypressHandler__HandleKeyDown_x                           0x558540
#define KeypressHandler__HandleKeyUp_x                             0x558860
#define KeypressHandler__SaveKeymapping_x                          0x559CB0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6C66C0
#define MapViewMap__SaveEx_x                                       0x6C9F70

#define PlayerPointManager__GetAltCurrency_x                       0x7D34A0

// StringTable 
#define StringTable__getString_x                                   0x7CE7D0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x583B70
