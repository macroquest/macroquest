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
#define __ExpectedVersionDate                                     "May 10 2013"
#define __ExpectedVersionTime                                     "23:30:08"
#define __ActualVersionDate_x                                      0x9DD250
#define __ActualVersionTime_x                                      0x9DD25C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5643F0
#define __MemChecker1_x                                            0x808CB0
#define __MemChecker2_x                                            0x5F97E0
#define __MemChecker3_x                                            0x5F9730
#define __MemChecker4_x                                            0x8CC050
#define __EncryptPad0_x                                            0xAE42D0
#define __EncryptPad1_x                                            0xB61908
#define __EncryptPad2_x                                            0xAFD970
#define __EncryptPad3_x                                            0xAFD570
#define __EncryptPad4_x                                            0xB670B8
#define __AC1_x                                                    0x7636B5
#define __AC2_x                                                    0x518957
#define __AC3_x                                                    0x52BD90
#define __AC4_x                                                    0x531E04
#define __AC5_x                                                    0x53DE5B
#define __AC6_x                                                    0x541792
#define __AC7_x                                                    0x537D7C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0xE67B48
#define DI8__Keyboard_x                                            0xE67B4C
#define DI8__Mouse_x                                               0xE67B50
#define __AltTimerReady_x                                          0xDD0A19
#define __Attack_x                                                 0xE635AA
#define __Autofire_x                                               0xE635AB
#define __BindList_x                                               0xACBEE8
#define __Clicks_x                                                 0xDDF734
#define __CommandList_x                                            0xACD5A8
#define __CurrentMapLabel_x                                        0xF73E00
#define __CurrentSocial_x                                          0xAB6A28
#define __DoAbilityList_x                                          0xE15E50
#define __do_loot_x                                                0x4E7880
#define __DrawHandler_x                                            0x15D46A4
#define __GroupCount_x                                             0xDD00F2

#define __Guilds_x                                                 0xDD5CF8
#define __gWorld_x                                                 0xDD25AC
#define __HotkeyPage_x                                             0xE5C850
#define __HWnd_x                                                   0xE678A0
#define __InChatMode_x                                             0xDDF66C
#define __LastTell_x                                               0xDE1558
#define __LMouseHeldTime_x                                         0xDDF7A0
#define __Mouse_x                                                  0xE67B54
#define __MouseLook_x                                              0xDDF702
#define __MouseEventTime_x                                         0xE639CC
#define __NetStatusToggle_x                                        0xDDF705
#define __PCNames_x                                                0xDE0BC8
#define __RangeAttackReady_x                                       0xDE0864
#define __RMouseHeldTime_x                                         0xDDF79C
#define __RunWalkState_x                                           0xDDF670
#define __ScreenMode_x                                             0xD1F3B8
#define __ScreenX_x                                                0xDDF624
#define __ScreenY_x                                                0xDDF620
#define __ScreenXMax_x                                             0xDDF628
#define __ScreenYMax_x                                             0xDDF62C
#define __ServerHost_x                                             0xDD003C
#define __ServerName_x                                             0xE15E10
#define __ShiftKeyDown_x                                           0xDDFD00
#define __ShowNames_x                                              0xDE0A70
#define __Socials_x                                                0xE15F10


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xDD2690
#define instEQZoneInfo_x                                           0xDDF8F0
#define instKeypressHandler_x                                      0xE639B0
#define pinstActiveBanker_x                                        0xDD2650
#define pinstActiveCorpse_x                                        0xDD2654
#define pinstActiveGMaster_x                                       0xDD2658
#define pinstActiveMerchant_x                                      0xDD264C
#define pinstAggroInfo_x                                           0xB79050
#define pinstAltAdvManager_x                                       0xD20358
#define pinstAuraMgr_x                                             0xB82950
#define pinstBandageTarget_x                                       0xDD2638
#define pinstCamActor_x                                            0xD1FD8C
#define pinstCDBStr_x                                              0xD1F380
#define pinstCDisplay_x                                            0xDD2660
#define pinstCEverQuest_x                                          0xE67CCC
#define pinstCharData_x                                            0xDD261C
#define pinstCharSpawn_x                                           0xDD2644
#define pinstControlledMissile_x                                   0xDD2618
#define pinstControlledPlayer_x                                    0xDD2644
#define pinstCSidlManager_x                                        0x15D3D08
#define pinstCXWndManager_x                                        0x15D3D00
#define instDynamicZone_x                                          0xDDF4D0
#define pinstDZMember_x                                            0xDDF5E0
#define pinstDZTimerInfo_x                                         0xDDF5E4
#define pinstEQItemList_x                                          0xDCF120
#define instEQMisc_x                                               0xABFCD0
#define pinstEQSoundManager_x                                      0xD20460
#define instExpeditionLeader_x                                     0xDDF51A
#define instExpeditionName_x                                       0xDDF55A
#define pinstGroup_x                                               0xDD00EE
#define pinstImeManager_x                                          0x15D3D0C
#define pinstLocalPlayer_x                                         0xDD2630
#define pinstMercenaryData_x                                       0xE63E90
#define pinstModelPlayer_x                                         0xDD265C
#define pinstPCData_x                                              0xDD261C
#define pinstSkillMgr_x                                            0xE64610
#define pinstSpawnManager_x                                        0xE641D0
#define pinstSpellManager_x                                        0xE646B0
#define pinstSpellSets_x                                           0xE5C8B4
#define pinstStringTable_x                                         0xDD25C4
#define pinstSwitchManager_x                                       0xDCFD00
#define pinstTarget_x                                              0xDD2648
#define pinstTargetObject_x                                        0xDD2620
#define pinstTargetSwitch_x                                        0xDD2624
#define pinstTaskMember_x                                          0xD1F314
#define pinstTrackTarget_x                                         0xDD263C
#define pinstTradeTarget_x                                         0xDD262C
#define instTributeActive_x                                        0xABFCF5
#define pinstViewActor_x                                           0xD1FD88
#define pinstWorldData_x                                           0xDD2600


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xB792A8
#define pinstCAudioTriggersWindow_x                                0xB791E0
#define pinstCCharacterSelect_x                                    0xD1FC34
#define pinstCFacePick_x                                           0xD1F9E4
#define pinstCNoteWnd_x                                            0xD1FBEC
#define pinstCBookWnd_x                                            0xD1FBF4
#define pinstCPetInfoWnd_x                                         0xD1FBF8
#define pinstCTrainWnd_x                                           0xD1FBFC
#define pinstCSkillsWnd_x                                          0xD1FC00
#define pinstCSkillsSelectWnd_x                                    0xD1FC04
#define pinstCCombatSkillSelectWnd_x                               0xD1FC08
#define pinstCFriendsWnd_x                                         0xD1FC0C
#define pinstCAuraWnd_x                                            0xD1FC10
#define pinstCRespawnWnd_x                                         0xD1FC14
#define pinstCBandolierWnd_x                                       0xD1FC18
#define pinstCPotionBeltWnd_x                                      0xD1FC1C
#define pinstCAAWnd_x                                              0xD1FC20
#define pinstCGroupSearchFiltersWnd_x                              0xD1FC24
#define pinstCLoadskinWnd_x                                        0xD1FC28
#define pinstCAlarmWnd_x                                           0xD1FC2C
#define pinstCMusicPlayerWnd_x                                     0xD1FC30
#define pinstCMailWnd_x                                            0xD1FC38
#define pinstCMailCompositionWnd_x                                 0xD1FC3C
#define pinstCMailAddressBookWnd_x                                 0xD1FC40
#define pinstCRaidWnd_x                                            0xD1FC48
#define pinstCRaidOptionsWnd_x                                     0xD1FC4C
#define pinstCBreathWnd_x                                          0xD1FC50
#define pinstCMapViewWnd_x                                         0xD1FC54
#define pinstCMapToolbarWnd_x                                      0xD1FC58
#define pinstCEditLabelWnd_x                                       0xD1FC5C
#define pinstCTargetWnd_x                                          0xD1FC60
#define pinstCColorPickerWnd_x                                     0xD1FC64
#define pinstCPlayerWnd_x                                          0xD1FC68
#define pinstCOptionsWnd_x                                         0xD1FC6C
#define pinstCBuffWindowNORMAL_x                                   0xD1FC70
#define pinstCBuffWindowSHORT_x                                    0xD1FC74
#define pinstCharacterCreation_x                                   0xD1FC78
#define pinstCCursorAttachment_x                                   0xD1FC7C
#define pinstCCastingWnd_x                                         0xD1FC80
#define pinstCCastSpellWnd_x                                       0xD1FC84
#define pinstCSpellBookWnd_x                                       0xD1FC88
#define pinstCInventoryWnd_x                                       0xD1FC8C
#define pinstCBankWnd_x                                            0xD1FC90
#define pinstCQuantityWnd_x                                        0xD1FC94
#define pinstCLootWnd_x                                            0xD1FC98
#define pinstCActionsWnd_x                                         0xD1FC9C
#define pinstCCombatAbilityWnd_x                                   0xD1FCA0
#define pinstCMerchantWnd_x                                        0xD1FCA4
#define pinstCTradeWnd_x                                           0xD1FCA8
#define pinstCSelectorWnd_x                                        0xD1FCAC
#define pinstCBazaarWnd_x                                          0xD1FCB0
#define pinstCBazaarSearchWnd_x                                    0xD1FCB4
#define pinstCGiveWnd_x                                            0xD1FCD0
#define pinstCTrackingWnd_x                                        0xD1FCD8
#define pinstCInspectWnd_x                                         0xD1FCDC
#define pinstCSocialEditWnd_x                                      0xD1FCE0
#define pinstCFeedbackWnd_x                                        0xD1FCE4
#define pinstCBugReportWnd_x                                       0xD1FCE8
#define pinstCVideoModesWnd_x                                      0xD1FCEC
#define pinstCTextEntryWnd_x                                       0xD1FCF4
#define pinstCFileSelectionWnd_x                                   0xD1FCF8
#define pinstCCompassWnd_x                                         0xD1FCFC
#define pinstCPlayerNotesWnd_x                                     0xD1FD00
#define pinstCGemsGameWnd_x                                        0xD1FD04
#define pinstCTimeLeftWnd_x                                        0xD1FD08
#define pinstCPetitionQWnd_x                                       0xD1FD1C
#define pinstCSoulmarkWnd_x                                        0xD1FD20
#define pinstCStoryWnd_x                                           0xD1FD24
#define pinstCJournalTextWnd_x                                     0xD1FD28
#define pinstCJournalCatWnd_x                                      0xD1FD2C
#define pinstCBodyTintWnd_x                                        0xD1FD30
#define pinstCServerListWnd_x                                      0xD1FD34
#define pinstCAvaZoneWnd_x                                         0xD1FD40
#define pinstCBlockedBuffWnd_x                                     0xD1FD44
#define pinstCBlockedPetBuffWnd_x                                  0xD1FD48
#define pinstCInvSlotMgr_x                                         0xD1FD80
#define pinstCContainerMgr_x                                       0xD1FD84
#define pinstCAdventureLeaderboardWnd_x                            0xF704C0
#define pinstCAdventureRequestWnd_x                                0xF70500
#define pinstCAltStorageWnd_x                                      0xF70690
#define pinstCAdventureStatsWnd_x                                  0xF70540
#define pinstCBarterMerchantWnd_x                                  0xF70C70
#define pinstCBarterSearchWnd_x                                    0xF70CB0
#define pinstCBarterWnd_x                                          0xF70CF0
#define pinstCChatManager_x                                        0xF71070
#define pinstCDynamicZoneWnd_x                                     0xF712E0
#define pinstCEQMainWnd_x                                          0xF713C0
#define pinstCFellowshipWnd_x                                      0xF712AC
#define pinstCFindLocationWnd_x                                    0xF71540
#define pinstCGroupSearchWnd_x                                     0xF716F0
#define pinstCGroupWnd_x                                           0xF71730
#define pinstCGuildBankWnd_x                                       0xF71770
#define pinstCGuildMgmtWnd_x                                       0xF737F0
#define pinstCHotButtonWnd_x                                       0xF73854
#define pinstCHotButtonWnd1_x                                      0xF73854
#define pinstCHotButtonWnd2_x                                      0xF73858
#define pinstCHotButtonWnd3_x                                      0xF7385C
#define pinstCHotButtonWnd4_x                                      0xF73880
#define pinstCItemDisplayManager_x                                 0xF73A28
#define pinstCItemExpTransferWnd_x                                 0xF73A6C
#define pinstCLFGuildWnd_x                                         0xF73C28
#define pinstCMIZoneSelectWnd_x                                    0xF73F78
#define pinstCConfirmationDialog_x                                 0xF74338
#define pinstCPopupWndManager_x                                    0xF74338
#define pinstCProgressionSelectionWnd_x                            0xF743B8
#define pinstCPvPStatsWnd_x                                        0xF74438
#define pinstCSystemInfoDialogBox_x                                0xF747F8
#define pinstCTaskTemplateSelectWnd_x                              0xF75750
#define pinstCTipWndOFDAY_x                                        0xF758C0
#define pinstCTipWndCONTEXT_x                                      0xF758C4
#define pinstCTitleWnd_x                                           0xF75908
#define pinstCContextMenuManager_x                                 0x15D391C
#define pinstCVoiceMacroWnd_x                                      0xE64A60
#define pinstCHtmlWnd_x                                            0xE64AE8


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x4FD1D0
#define __ConvertItemTags_x                                        0x4ED110
#define __ExecuteCmd_x                                             0x4D7230
#define __EQGetTime_x                                              0x809810
#define __get_melee_range_x                                        0x4DDEB0
#define __GetGaugeValueFromEQ_x                                    0x762410
#define __GetLabelFromEQ_x                                         0x763640
#define __GetXTargetType_x                                         0x8D3BE0
#define __LoadFrontEnd_x                                           0x5F8E90
#define __NewUIINI_x                                               0x761D40
#define __ProcessGameEvents_x                                      0x539E60
#define CrashDetected_x                                            0x5FB50B
#define DrawNetStatus_x                                            0x573620
#define Util__FastTime_x                                           0x808B50
#define Expansion_HoT_x                                            0xDE09D0
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A3840
#define AltAdvManager__IsAbilityReady_x                            0x4A3880
#define AltAdvManager__GetAltAbility_x                             0x4A3C60

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x44A1B0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x627C50

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x635530

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x54FBE0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6508A0
#define CChatManager__InitContextMenu_x                            0x6513C0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x7EFA80
#define CChatService__GetFriendName_x                              0x7EFA90

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x656100
#define CChatWindow__Clear_x                                       0x655CB0
#define CChatWindow__WndNotification_x                             0x656640

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x86A960
#define CComboWnd__Draw_x                                          0x86AB40
#define CComboWnd__GetCurChoice_x                                  0x86A780
#define CComboWnd__GetListRect_x                                   0x86ADE0
#define CComboWnd__GetTextRect_x                                   0x86A9C0
#define CComboWnd__InsertChoice_x                                  0x86AE50
#define CComboWnd__SetColors_x                                     0x86A710
#define CComboWnd__SetChoice_x                                     0x86A740

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x65F7B0
#define CContainerWnd__vftable_x                                   0x9E6758

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4936E0
#define CDisplay__GetClickedActor_x                                0x48B6B0
#define CDisplay__GetUserDefinedColor_x                            0x489F70
#define CDisplay__GetWorldFilePath_x                               0x489370
#define CDisplay__is3dON_x                                         0x488450
#define CDisplay__ReloadUI_x                                       0x49D6B0
#define CDisplay__WriteTextHD2_x                                   0x48EB40

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x88C0C0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x87B230
#define CEditWnd__GetCharIndexPt_x                                 0x87C260
#define CEditWnd__GetDisplayString_x                               0x87B3E0
#define CEditWnd__GetHorzOffset_x                                  0x87B720
#define CEditWnd__GetLineForPrintableChar_x                        0x87BD20
#define CEditWnd__GetSelStartPt_x                                  0x87C520
#define CEditWnd__GetSTMLSafeText_x                                0x87B8C0
#define CEditWnd__PointFromPrintableChar_x                         0x87BE10
#define CEditWnd__SelectableCharFromPoint_x                        0x87BF90
#define CEditWnd__SetEditable_x                                    0x87B890

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x5190A0
#define CEverQuest__DoTellWindow_x                                 0x51DA00
#define CEverQuest__DropHeldItemOnGround_x                         0x526290
#define CEverQuest__dsp_chat_x                                     0x51F1A0
#define CEverQuest__Emote_x                                        0x51F400
#define CEverQuest__EnterZone_x                                    0x531F90
#define CEverQuest__GetBodyTypeDesc_x                              0x515660
#define CEverQuest__GetClassDesc_x                                 0x514DC0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5153C0
#define CEverQuest__GetDeityDesc_x                                 0x515F70
#define CEverQuest__GetLangDesc_x                                  0x5159F0
#define CEverQuest__GetRaceDesc_x                                  0x515CE0
#define CEverQuest__InterpretCmd_x                                 0x51FCE0
#define CEverQuest__LeftClickedOnPlayer_x                          0x536310
#define CEverQuest__LMouseUp_x                                     0x5384D0
#define CEverQuest__RightClickedOnPlayer_x                         0x536D80
#define CEverQuest__RMouseUp_x                                     0x537D30
#define CEverQuest__SetGameState_x                                 0x519750
#define CEverQuest__UPCNotificationFlush_x                         0x520C70

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x66F7A0
#define CGaugeWnd__CalcLinesFillRect_x                             0x66F800
#define CGaugeWnd__Draw_x                                          0x66FC30

// CGuild
#define CGuild__FindMemberByName_x                                 0x423D70

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x68C8B0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x697E50
#define CInvSlotMgr__MoveItem_x                                    0x698D80

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x697250
#define CInvSlot__SliderComplete_x                                 0x695270
#define CInvSlot__GetItemBase_x                                    0x694780

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x699AD0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x75F060
#define CItemDisplayWnd__UpdateStrings_x                           0x69AE30

// CLabel 
#define CLabel__Draw_x                                             0x6B4D40

// CListWnd 
#define CListWnd__AddColumn_x                                      0x858C20
#define CListWnd__AddColumn1_x                                     0x858400
#define CListWnd__AddLine_x                                        0x857EB0
#define CListWnd__AddString_x                                      0x8580C0
#define CListWnd__CalculateFirstVisibleLine_x                      0x854F70
#define CListWnd__CalculateVSBRange_x                              0x8570B0
#define CListWnd__ClearAllSel_x                                    0x854220
#define CListWnd__CloseAndUpdateEditWindow_x                       0x857A90
#define CListWnd__Compare_x                                        0x855A80
#define CListWnd__Draw_x                                           0x856D10
#define CListWnd__DrawColumnSeparators_x                           0x856BA0
#define CListWnd__DrawHeader_x                                     0x854530
#define CListWnd__DrawItem_x                                       0x8560D0
#define CListWnd__DrawLine_x                                       0x856840
#define CListWnd__DrawSeparator_x                                  0x856C40
#define CListWnd__EnsureVisible_x                                  0x8550D0
#define CListWnd__ExtendSel_x                                      0x855FE0
#define CListWnd__GetColumnMinWidth_x                              0x853C40
#define CListWnd__GetColumnWidth_x                                 0x853B60
#define CListWnd__GetCurSel_x                                      0x853430
#define CListWnd__GetItemAtPoint_x                                 0x855370
#define CListWnd__GetItemAtPoint1_x                                0x8553E0
#define CListWnd__GetItemData_x                                    0x853680
#define CListWnd__GetItemHeight_x                                  0x854BC0
#define CListWnd__GetItemIcon_x                                    0x853860
#define CListWnd__GetItemRect_x                                    0x8551B0
#define CListWnd__GetItemText_x                                    0x853710
#define CListWnd__GetSelList_x                                     0x8582F0
#define CListWnd__GetSeparatorRect_x                               0x8559A0
#define CListWnd__RemoveLine_x                                     0x8582A0
#define CListWnd__SetColors_x                                      0x853490
#define CListWnd__SetColumnJustification_x                         0x853F10
#define CListWnd__SetColumnWidth_x                                 0x853BF0
#define CListWnd__SetCurSel_x                                      0x853470
#define CListWnd__SetItemColor_x                                   0x857770
#define CListWnd__SetItemData_x                                    0x8542D0
#define CListWnd__SetItemText_x                                    0x8575B0
#define CListWnd__ShiftColumnSeparator_x                           0x857440
#define CListWnd__Sort_x                                           0x858D80
#define CListWnd__ToggleSel_x                                      0x8541A0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6CFB70

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6EF750
#define CMerchantWnd__RequestBuyItem_x                             0x6F5BE0
#define CMerchantWnd__RequestSellItem_x                            0x71CCA0
#define CMerchantWnd__SelectBuySellSlot_x                          0x6EFA00

// CObfuscator
#define CObfuscator__doit_x                                        0x7D03C0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x870120
#define CSidlManager__CreateLabel_x                                0x7556F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x61EE40
#define CSidlScreenWnd__CalculateVSBRange_x                        0x61ED60
#define CSidlScreenWnd__ConvertToRes_x                             0x88BFA0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x85DCF0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x85F070
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x85F120
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x85E600
#define CSidlScreenWnd__DrawSidlPiece_x                            0x85D7D0
#define CSidlScreenWnd__EnableIniStorage_x                         0x85CF00
#define CSidlScreenWnd__GetSidlPiece_x                             0x85D9C0
#define CSidlScreenWnd__Init1_x                                    0x85ED50
#define CSidlScreenWnd__LoadIniInfo_x                              0x85DDA0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x85D0C0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x85E850
#define CSidlScreenWnd__StoreIniInfo_x                             0x85CA70
#define CSidlScreenWnd__StoreIniVis_x                              0x85CE90
#define CSidlScreenWnd__WndNotification_x                          0x85EAD0
#define CSidlScreenWnd__GetChildItem_x                             0x85CFD0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5BAE40
#define CSkillMgr__GetSkillCap_x                                   0x5BAEC0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x895FE0
#define CSliderWnd__SetValue_x                                     0x8961B0
#define CSliderWnd__SetNumTicks_x                                  0x896930

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x75CAC0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x886720
#define CStmlWnd__CalculateHSBRange_x                              0x87EE80
#define CStmlWnd__CalculateVSBRange_x                              0x87EF10
#define CStmlWnd__CanBreakAtCharacter_x                            0x87F090
#define CStmlWnd__FastForwardToEndOfTag_x                          0x87F970
#define CStmlWnd__ForceParseNow_x                                  0x887070
#define CStmlWnd__GetNextTagPiece_x                                0x87F870
#define CStmlWnd__GetSTMLText_x                                    0x655550
#define CStmlWnd__GetVisibleText_x                                 0x8803C0
#define CStmlWnd__InitializeWindowVariables_x                      0x8825A0
#define CStmlWnd__MakeStmlColorTag_x                               0x87E0D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x87E130
#define CStmlWnd__SetSTMLText_x                                    0x883E10
#define CStmlWnd__StripFirstSTMLLines_x                            0x8863C0
#define CStmlWnd__UpdateHistoryString_x                            0x881300

// CTabWnd 
#define CTabWnd__Draw_x                                            0x88D870
#define CTabWnd__DrawCurrentPage_x                                 0x88D0E0
#define CTabWnd__DrawTab_x                                         0x88CEA0
#define CTabWnd__GetCurrentPage_x                                  0x88D4B0
#define CTabWnd__GetPageInnerRect_x                                0x88CB90
#define CTabWnd__GetTabInnerRect_x                                 0x88CD90
#define CTabWnd__GetTabRect_x                                      0x88CC60
#define CTabWnd__InsertPage_x                                      0x88DB60
#define CTabWnd__SetPage_x                                         0x88D4E0
#define CTabWnd__SetPageRect_x                                     0x88D7B0
#define CTabWnd__UpdatePage_x                                      0x88DB00

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41F840

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x889B70

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8929A0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x851540

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x55CC70
#define CXStr__CXStr1_x                                            0x4DBB00
#define CXStr__CXStr3_x                                            0x805C20
#define CXStr__dCXStr_x                                            0x465AE0
#define CXStr__operator_equal_x                                    0x805D90
#define CXStr__operator_equal1_x                                   0x805DE0
#define CXStr__operator_plus_equal1_x                              0x806EC0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x862C50
#define CXWnd__Center_x                                            0x868DA0
#define CXWnd__ClrFocus_x                                          0x862820
#define CXWnd__DoAllDrawing_x                                      0x868A10
#define CXWnd__DrawChildren_x                                      0x868BA0
#define CXWnd__DrawColoredRect_x                                   0x863010
#define CXWnd__DrawTooltip_x                                       0x8632C0
#define CXWnd__DrawTooltipAtPoint_x                                0x8679B0
#define CXWnd__GetBorderFrame_x                                    0x863700
#define CXWnd__GetChildWndAt_x                                     0x866980
#define CXWnd__GetClientClipRect_x                                 0x8634D0
#define CXWnd__GetScreenClipRect_x                                 0x8680B0
#define CXWnd__GetScreenRect_x                                     0x8638D0
#define CXWnd__GetTooltipRect_x                                    0x863150
#define CXWnd__GetWindowTextA_x                                    0x411190
#define CXWnd__IsActive_x                                          0x8760A0
#define CXWnd__IsDescendantOf_x                                    0x863640
#define CXWnd__IsReallyVisible_x                                   0x866960
#define CXWnd__IsType_x                                            0x88F1E0
#define CXWnd__Move_x                                              0x8660E0
#define CXWnd__Move1_x                                             0x8686F0
#define CXWnd__ProcessTransition_x                                 0x862C00
#define CXWnd__Refade_x                                            0x8629D0
#define CXWnd__Resize_x                                            0x863990
#define CXWnd__Right_x                                             0x867EB0
#define CXWnd__SetFocus_x                                          0x865250
#define CXWnd__SetFont_x                                           0x862870
#define CXWnd__SetKeyTooltip_x                                     0x863C00
#define CXWnd__SetMouseOver_x                                      0x8683F0
#define CXWnd__StartFade_x                                         0x862CA0
#define CXWnd__GetChildItem_x                                      0x868330

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8779C0
#define CXWndManager__DrawWindows_x                                0x877600
#define CXWndManager__GetKeyboardFlags_x                           0x875BD0
#define CXWndManager__HandleKeyboardMsg_x                          0x876530
#define CXWndManager__RemoveWnd_x                                  0x876230

// CDBStr
#define CDBStr__GetString_x                                        0x4866C0

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8D0520
#define EQ_Character__CastSpell_x                                  0x43A830
#define EQ_Character__Cur_HP_x                                     0x449E00
#define EQ_Character__GetAACastingTimeModifier_x                   0x4336D0
#define EQ_Character__GetCharInfo2_x                               0x7DB210
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42C9A0
#define EQ_Character__GetFocusRangeModifier_x                      0x42CB80
#define EQ_Character__Max_Endurance_x                              0x582020
#define EQ_Character__Max_HP_x                                     0x443FA0
#define EQ_Character__Max_Mana_x                                   0x581E60
#define EQ_Character__doCombatAbility_x                            0x5808C0
#define EQ_Character__UseSkill_x                                   0x45B2D0
#define EQ_Character__GetConLevel_x                                0x577CB0
#define EQ_Character__IsExpansionFlag_x                            0x4106C0
#define EQ_Character__TotalEffect_x                                0x438990

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x554E50
#define EQ_Item__CreateItemTagString_x                             0x7BBC50
#define EQ_Item__IsStackable_x                                     0x7B0380

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A59A0
#define EQ_LoadingS__Array_x                                       0xAC6330

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5862F0
#define EQ_PC__GetAltAbilityIndex_x                                0x7C4460
#define EQ_PC__GetCombatAbility_x                                  0x7C44F0
#define EQ_PC__GetCombatAbilityTimer_x                             0x7C45A0
#define EQ_PC__GetItemTimerValue_x                                 0x580600
#define EQ_PC__HasLoreItem_x                                       0x57AE30

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4DBBD0
#define EQItemList__add_item_x                                     0x4DBB10
#define EQItemList__delete_item_x                                  0x4DBFD0
#define EQItemList__FreeItemList_x                                 0x4DBED0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x485B90

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x58BE90
#define EQPlayer__dEQPlayer_x                                      0x590A60
#define EQPlayer__DoAttack_x                                       0x5A5000
#define EQPlayer__EQPlayer_x                                       0x5961E0
#define EQPlayer__SetNameSpriteState_x                             0x58E2D0
#define EQPlayer__SetNameSpriteTint_x                              0x58BF00
#define EQPlayer__IsBodyType_j_x                                   0x8CFDC0
#define EQPlayer__IsTargetable_x                                   0x8D0090

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5996E0
#define EQPlayerManager__GetSpawnByName_x                          0x599B40

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x55AFA0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x55AFE0
#define KeypressHandler__ClearCommandStateArray_x                  0x55AB80
#define KeypressHandler__HandleKeyDown_x                           0x5594E0
#define KeypressHandler__HandleKeyUp_x                             0x559800
#define KeypressHandler__SaveKeymapping_x                          0x55AC50

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6C7FD0
#define MapViewMap__SaveEx_x                                       0x6CB880

#define PlayerPointManager__GetAltCurrency_x                       0x7D5350

// StringTable 
#define StringTable__getString_x                                   0x7D0660

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x584BE0
