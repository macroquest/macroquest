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
#define __ExpectedVersionDate                                     "Feb 20 2014"
#define __ExpectedVersionTime                                     "15:58:25"
#define __ActualVersionDate_x                                      0x9F15B8
#define __ActualVersionTime_x                                      0x9F15C4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x566C20
#define __MemChecker1_x                                            0x8250F0
#define __MemChecker2_x                                            0x5FC5F0
#define __MemChecker3_x                                            0x5FC540
#define __MemChecker4_x                                            0x7A97D0
#define __EncryptPad0_x                                            0xAFD5C8
#define __EncryptPad1_x                                            0xB83EF0
#define __EncryptPad2_x                                            0xB18520
#define __EncryptPad3_x                                            0xB18120
#define __EncryptPad4_x                                            0xB80130
#define __AC1_x                                                    0x767535
#define __AC2_x                                                    0x51EBB7
#define __AC3_x                                                    0x531FB0
#define __AC4_x                                                    0x537FC0
#define __AC5_x                                                    0x544431
#define __AC6_x                                                    0x547EE2
#define __AC7_x                                                    0x53DF4C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0xF25B60
#define DI8__Keyboard_x                                            0xF25B64
#define DI8__Mouse_x                                               0xF25B68
#define __AltTimerReady_x                                          0xD86781
#define __Attack_x                                                 0xE1941E
#define __Autofire_x                                               0xE1941F
#define __BindList_x                                               0xAE4548
#define __Clicks_x                                                 0xD95280
#define __CommandList_x                                            0xAE5D98
#define __CurrentMapLabel_x                                        0xF2A3D0
#define __CurrentSocial_x                                          0xACD6AC
#define __DoAbilityList_x                                          0xDCB9CC
#define __do_loot_x                                                0x4EC5A0
#define __DrawHandler_x                                            0x158B104
#define __GroupCount_x                                             0xD85E70

#define __Guilds_x                                                 0xD8B820
#define __gWorld_x                                                 0xD88314
#define __HotkeyPage_x                                             0xE123CC
#define __HWnd_x                                                   0xE1DA68
#define __InChatMode_x                                             0xD951AC
#define __LastTell_x                                               0xD970D4
#define __LMouseHeldTime_x                                         0xD952EC
#define __Mouse_x                                                  0xF25B6C
#define __MouseLook_x                                              0xD95246
#define __MouseEventTime_x                                         0xE19904
#define __NetStatusToggle_x                                        0xD95249
#define __PCNames_x                                                0xD96718
#define __RangeAttackReady_x                                       0xD963B4
#define __RMouseHeldTime_x                                         0xD952E8
#define __RunWalkState_x                                           0xD951B0
#define __ScreenMode_x                                             0xCD4EC0
#define __ScreenX_x                                                0xD95164
#define __ScreenY_x                                                0xD95160
#define __ScreenXMax_x                                             0xD95168
#define __ScreenYMax_x                                             0xD9516C
#define __ServerHost_x                                             0xD85DA4
#define __ServerName_x                                             0xDCB98C
#define __ShiftKeyDown_x                                           0xD9584C
#define __ShowNames_x                                              0xD965BC
#define __Socials_x                                                0xDCBA8C
#define __SubscriptionType_x                                       0xF53010
#define __TargetAggroHolder_x                                      0xF2BCF0
#define __GroupAggro_x                                             0xF2BD30
#define __LoginName_x                                              0xE1C640

//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xD883F8
#define instEQZoneInfo_x                                           0xD9543C
#define instKeypressHandler_x                                      0xE198E8
#define pinstActiveBanker_x                                        0xD883B8
#define pinstActiveCorpse_x                                        0xD883BC
#define pinstActiveGMaster_x                                       0xD883C0
#define pinstActiveMerchant_x                                      0xD883B4
#define pinstAggroInfo_x                                           0xB99BA0
#define pinstAltAdvManager_x                                       0xCD5EA8
#define pinstAuraMgr_x                                             0xBA3610
#define pinstBandageTarget_x                                       0xD883A0
#define pinstCamActor_x                                            0xCD5894
#define pinstCDBStr_x                                              0xCD4E80
#define pinstCDisplay_x                                            0xD883C8
#define pinstCEverQuest_x                                          0xF25CE4
#define pinstCharData_x                                            0xD88384
#define pinstCharSpawn_x                                           0xD883AC
#define pinstControlledMissile_x                                   0xD88380
#define pinstControlledPlayer_x                                    0xD883AC
#define pinstCSidlManager_x                                        0x158A7B8
#define pinstCXWndManager_x                                        0x158A7B0
#define instDynamicZone_x                                          0xD95000
#define pinstDZMember_x                                            0xD95110
#define pinstDZTimerInfo_x                                         0xD95114
#define pinstEQItemList_x                                          0xD84DA0
#define instEQMisc_x                                               0xAD7250
#define pinstEQSoundManager_x                                      0xCD6040
#define instExpeditionLeader_x                                     0xD9504A
#define instExpeditionName_x                                       0xD9508A
#define pinstGroup_x                                               0xD85E56
#define pinstImeManager_x                                          0x158A7BC
#define pinstLocalPlayer_x                                         0xD88398
#define pinstMercenaryData_x                                       0xE19DD0
#define pinstMercAltAbilities_x                                    0xCD5FBC
#define pinstModelPlayer_x                                         0xD883C4
#define pinstPCData_x                                              0xD88384
#define pinstSkillMgr_x                                            0xE1A6C8
#define pinstSpawnManager_x                                        0xE1A1F0
#define pinstSpellManager_x                                        0xE1A788
#define pinstSpellSets_x                                           0xE12430
#define pinstStringTable_x                                         0xD8832C
#define pinstSwitchManager_x                                       0xD85A40
#define pinstTarget_x                                              0xD883B0
#define pinstTargetObject_x                                        0xD88388
#define pinstTargetSwitch_x                                        0xD8838C
#define pinstTaskMember_x                                          0xCD4E08
#define pinstTrackTarget_x                                         0xD883A4
#define pinstTradeTarget_x                                         0xD88394
#define instTributeActive_x                                        0xAD7275
#define pinstViewActor_x                                           0xCD5890
#define pinstWorldData_x                                           0xD88368


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xB99E90
#define pinstCAudioTriggersWindow_x                                0xB99DB0
#define pinstCCharacterSelect_x                                    0xCD573C
#define pinstCFacePick_x                                           0xCD54EC
#define pinstCNoteWnd_x                                            0xCD56F4
#define pinstCBookWnd_x                                            0xCD56FC
#define pinstCPetInfoWnd_x                                         0xCD5700
#define pinstCTrainWnd_x                                           0xCD5704
#define pinstCSkillsWnd_x                                          0xCD5708
#define pinstCSkillsSelectWnd_x                                    0xCD570C
#define pinstCCombatSkillSelectWnd_x                               0xCD5710
#define pinstCFriendsWnd_x                                         0xCD5714
#define pinstCAuraWnd_x                                            0xCD5718
#define pinstCRespawnWnd_x                                         0xCD571C
#define pinstCBandolierWnd_x                                       0xCD5720
#define pinstCPotionBeltWnd_x                                      0xCD5724
#define pinstCAAWnd_x                                              0xCD5728
#define pinstCGroupSearchFiltersWnd_x                              0xCD572C
#define pinstCLoadskinWnd_x                                        0xCD5730
#define pinstCAlarmWnd_x                                           0xCD5734
#define pinstCMusicPlayerWnd_x                                     0xCD5738
#define pinstCMailWnd_x                                            0xCD5740
#define pinstCMailCompositionWnd_x                                 0xCD5744
#define pinstCMailAddressBookWnd_x                                 0xCD5748
#define pinstCRaidWnd_x                                            0xCD5750
#define pinstCRaidOptionsWnd_x                                     0xCD5754
#define pinstCBreathWnd_x                                          0xCD5758
#define pinstCMapViewWnd_x                                         0xCD575C
#define pinstCMapToolbarWnd_x                                      0xCD5760
#define pinstCEditLabelWnd_x                                       0xCD5764
#define pinstCTargetWnd_x                                          0xCD5768
#define pinstCColorPickerWnd_x                                     0xCD576C
#define pinstCPlayerWnd_x                                          0xCD5770
#define pinstCOptionsWnd_x                                         0xCD5774
#define pinstCBuffWindowNORMAL_x                                   0xCD5778
#define pinstCBuffWindowSHORT_x                                    0xCD577C
#define pinstCharacterCreation_x                                   0xCD5780
#define pinstCCursorAttachment_x                                   0xCD5784
#define pinstCCastingWnd_x                                         0xCD5788
#define pinstCCastSpellWnd_x                                       0xCD578C
#define pinstCSpellBookWnd_x                                       0xCD5790
#define pinstCInventoryWnd_x                                       0xCD5794
#define pinstCBankWnd_x                                            0xCD5798
#define pinstCQuantityWnd_x                                        0xCD579C
#define pinstCLootWnd_x                                            0xCD57A0
#define pinstCActionsWnd_x                                         0xCD57A4
#define pinstCCombatAbilityWnd_x                                   0xCD57A8
#define pinstCMerchantWnd_x                                        0xCD57AC
#define pinstCTradeWnd_x                                           0xCD57B0
#define pinstCSelectorWnd_x                                        0xCD57B4
#define pinstCBazaarWnd_x                                          0xCD57B8
#define pinstCBazaarSearchWnd_x                                    0xCD57BC
#define pinstCGiveWnd_x                                            0xCD57D8
#define pinstCTrackingWnd_x                                        0xCD57E0
#define pinstCInspectWnd_x                                         0xCD57E4
#define pinstCSocialEditWnd_x                                      0xCD57E8
#define pinstCFeedbackWnd_x                                        0xCD57EC
#define pinstCBugReportWnd_x                                       0xCD57F0
#define pinstCVideoModesWnd_x                                      0xCD57F4
#define pinstCTextEntryWnd_x                                       0xCD57FC
#define pinstCFileSelectionWnd_x                                   0xCD5800
#define pinstCCompassWnd_x                                         0xCD5804
#define pinstCPlayerNotesWnd_x                                     0xCD5808
#define pinstCGemsGameWnd_x                                        0xCD580C
#define pinstCTimeLeftWnd_x                                        0xCD5810
#define pinstCPetitionQWnd_x                                       0xCD5824
#define pinstCSoulmarkWnd_x                                        0xCD5828
#define pinstCStoryWnd_x                                           0xCD582C
#define pinstCJournalTextWnd_x                                     0xCD5830
#define pinstCJournalCatWnd_x                                      0xCD5834
#define pinstCBodyTintWnd_x                                        0xCD5838
#define pinstCServerListWnd_x                                      0xCD583C
#define pinstCAvaZoneWnd_x                                         0xCD5848
#define pinstCBlockedBuffWnd_x                                     0xCD584C
#define pinstCBlockedPetBuffWnd_x                                  0xCD5850
#define pinstCInvSlotMgr_x                                         0xCD5888
#define pinstCContainerMgr_x                                       0xCD588C
#define pinstCAdventureLeaderboardWnd_x                            0xF266E8
#define pinstCAdventureRequestWnd_x                                0xF26738
#define pinstCAltStorageWnd_x                                      0xF26908
#define pinstCAdventureStatsWnd_x                                  0xF26788
#define pinstCBarterMerchantWnd_x                                  0xF26FE8
#define pinstCBarterSearchWnd_x                                    0xF27038
#define pinstCBarterWnd_x                                          0xF27088
#define pinstCChatManager_x                                        0xF27488
#define pinstCDynamicZoneWnd_x                                     0xF27768
#define pinstCEQMainWnd_x                                          0xF27870
#define pinstCFellowshipWnd_x                                      0xF2772C
#define pinstCFindLocationWnd_x                                    0xF27A30
#define pinstCGroupSearchWnd_x                                     0xF27BE8
#define pinstCGroupWnd_x                                           0xF27C38
#define pinstCGuildBankWnd_x                                       0xF27C88
#define pinstCGuildMgmtWnd_x                                       0xF29D28
#define pinstCHotButtonWnd_x                                       0xF29D9C
#define pinstCHotButtonWnd1_x                                      0xF29D9C
#define pinstCHotButtonWnd2_x                                      0xF29DA0
#define pinstCHotButtonWnd3_x                                      0xF29DA4
#define pinstCHotButtonWnd4_x                                      0xF29DC8
#define pinstCItemDisplayManager_x                                 0xF29FA8
#define pinstCItemExpTransferWnd_x                                 0xF29FFC
#define pinstCLFGuildWnd_x                                         0xF2A1B8
#define pinstCMIZoneSelectWnd_x                                    0xF2A578
#define pinstCConfirmationDialog_x                                 0xF2A9C8
#define pinstCPopupWndManager_x                                    0xF2A9C8
#define pinstCProgressionSelectionWnd_x                            0xF2AA60
#define pinstCPvPStatsWnd_x                                        0xF2AB00
#define pinstCSystemInfoDialogBox_x                                0xF2AF50
#define pinstCTaskWnd_x                                            0xF2C010
#define pinstCTaskTemplateSelectWnd_x                              0xF2BFC0
#define pinstCTipWndOFDAY_x                                        0xF2C180
#define pinstCTipWndCONTEXT_x                                      0xF2C184
#define pinstCTitleWnd_x                                           0xF2C1D0
#define pinstCContextMenuManager_x                                 0x158A3CC
#define pinstCVoiceMacroWnd_x                                      0xE1ABF0
#define pinstCHtmlWnd_x                                            0xE1AC98
#define pinstIconCache_x                                           0xF27848


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5027F0
#define __ConvertItemTags_x                                        0x4F2150
#define __ExecuteCmd_x                                             0x4DBB00
#define __EQGetTime_x                                              0x825C50
#define __get_melee_range_x                                        0x4E28F0
#define __GetGaugeValueFromEQ_x                                    0x766290
#define __GetLabelFromEQ_x                                         0x7674C0
#define __GetXTargetType_x                                         0x8E1920
#define __LoadFrontEnd_x                                           0x5FBCA0
#define __NewUIINI_x                                               0x765BC0
#define __ProcessGameEvents_x                                      0x540090
#define CrashDetected_x                                            0x601470
#define DrawNetStatus_x                                            0x576420
#define Util__FastTime_x                                           0x824F90
#define Expansion_HoT_x                                            0xD9651C
#define __HelpPath_x                                               0xE19768
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A4330
#define AltAdvManager__IsAbilityReady_x                            0x4A43A0
#define AltAdvManager__GetAltAbility_x                             0x4A4760

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x44A760

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x62BCA0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x63A100

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x556450

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x654930
#define CChatManager__InitContextMenu_x                            0x655450

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x80BC70
#define CChatService__GetFriendName_x                              0x80BC80

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x65A170
#define CChatWindow__Clear_x                                       0x659D30
#define CChatWindow__WndNotification_x                             0x65A6A0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x883ED0
#define CComboWnd__Draw_x                                          0x8840B0
#define CComboWnd__GetCurChoice_x                                  0x883CF0
#define CComboWnd__GetListRect_x                                   0x884350
#define CComboWnd__GetTextRect_x                                   0x883F30
#define CComboWnd__InsertChoice_x                                  0x8843C0
#define CComboWnd__SetColors_x                                     0x883C80
#define CComboWnd__SetChoice_x                                     0x883CB0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x663880
#define CContainerWnd__vftable_x                                   0x9FA408

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x494160
#define CDisplay__GetClickedActor_x                                0x48BE50
#define CDisplay__GetUserDefinedColor_x                            0x48A710
#define CDisplay__GetWorldFilePath_x                               0x489B10
#define CDisplay__is3dON_x                                         0x488BE0
#define CDisplay__ReloadUI_x                                       0x49E070
#define CDisplay__WriteTextHD2_x                                   0x48F5B0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8A5740

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x894750
#define CEditWnd__GetCharIndexPt_x                                 0x895760
#define CEditWnd__GetDisplayString_x                               0x894900
#define CEditWnd__GetHorzOffset_x                                  0x894C40
#define CEditWnd__GetLineForPrintableChar_x                        0x895230
#define CEditWnd__GetSelStartPt_x                                  0x895A10
#define CEditWnd__GetSTMLSafeText_x                                0x894DD0
#define CEditWnd__PointFromPrintableChar_x                         0x895320
#define CEditWnd__SelectableCharFromPoint_x                        0x8954A0
#define CEditWnd__SetEditable_x                                    0x894DA0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x51F300
#define CEverQuest__DoTellWindow_x                                 0x523C30
#define CEverQuest__DropHeldItemOnGround_x                         0x52C4B0
#define CEverQuest__dsp_chat_x                                     0x5253D0
#define CEverQuest__Emote_x                                        0x525630
#define CEverQuest__EnterZone_x                                    0x538150
#define CEverQuest__GetBodyTypeDesc_x                              0x51B980
#define CEverQuest__GetClassDesc_x                                 0x51B0E0
#define CEverQuest__GetClassThreeLetterCode_x                      0x51B6E0
#define CEverQuest__GetDeityDesc_x                                 0x51C290
#define CEverQuest__GetLangDesc_x                                  0x51BD10
#define CEverQuest__GetRaceDesc_x                                  0x51C000
#define CEverQuest__InterpretCmd_x                                 0x525F10
#define CEverQuest__LeftClickedOnPlayer_x                          0x53C490
#define CEverQuest__LMouseUp_x                                     0x53E6B0
#define CEverQuest__RightClickedOnPlayer_x                         0x53CF50
#define CEverQuest__RMouseUp_x                                     0x53DF00
#define CEverQuest__SetGameState_x                                 0x51F9B0
#define CEverQuest__UPCNotificationFlush_x                         0x526ED0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x674280
#define CGaugeWnd__CalcLinesFillRect_x                             0x6742E0
#define CGaugeWnd__Draw_x                                          0x674710

// CGuild
#define CGuild__FindMemberByName_x                                 0x424020

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6908F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x69C340
#define CInvSlotMgr__MoveItem_x                                    0x69D280
#define CInvSlotMgr__SelectSlot_x                                  0x69C3F0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x69B670
#define CInvSlot__SliderComplete_x                                 0x6994C0
#define CInvSlot__GetItemBase_x                                    0x698940

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x69E050

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x762F00
#define CItemDisplayWnd__UpdateStrings_x                           0x69F390

// CLabel 
#define CLabel__Draw_x                                             0x6B9B40

// CListWnd 
#define CListWnd__AddColumn_x                                      0x872190
#define CListWnd__AddColumn1_x                                     0x871970
#define CListWnd__AddLine_x                                        0x871420
#define CListWnd__AddString_x                                      0x871630
#define CListWnd__CalculateFirstVisibleLine_x                      0x86E520
#define CListWnd__CalculateVSBRange_x                              0x870630
#define CListWnd__ClearAllSel_x                                    0x86D7E0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x871000
#define CListWnd__Compare_x                                        0x86F010
#define CListWnd__Draw_x                                           0x870290
#define CListWnd__DrawColumnSeparators_x                           0x870120
#define CListWnd__DrawHeader_x                                     0x86DAF0
#define CListWnd__DrawItem_x                                       0x86F660
#define CListWnd__DrawLine_x                                       0x86FDC0
#define CListWnd__DrawSeparator_x                                  0x8701C0
#define CListWnd__EnsureVisible_x                                  0x86E680
#define CListWnd__ExtendSel_x                                      0x86F570
#define CListWnd__GetColumnMinWidth_x                              0x86D200
#define CListWnd__GetColumnWidth_x                                 0x86D120
#define CListWnd__GetCurSel_x                                      0x86C9F0
#define CListWnd__GetItemAtPoint_x                                 0x86E910
#define CListWnd__GetItemAtPoint1_x                                0x86E980
#define CListWnd__GetItemData_x                                    0x86CC30
#define CListWnd__GetItemHeight_x                                  0x86E180
#define CListWnd__GetItemIcon_x                                    0x86CE10
#define CListWnd__GetItemRect_x                                    0x86E750
#define CListWnd__GetItemText_x                                    0x86CCC0
#define CListWnd__GetSelList_x                                     0x871860
#define CListWnd__GetSeparatorRect_x                               0x86EF30
#define CListWnd__RemoveLine_x                                     0x871810
#define CListWnd__SetColors_x                                      0x86CA50
#define CListWnd__SetColumnJustification_x                         0x86D4D0
#define CListWnd__SetColumnWidth_x                                 0x86D1B0
#define CListWnd__SetCurSel_x                                      0x86CA30
#define CListWnd__SetItemColor_x                                   0x870CE0
#define CListWnd__SetItemData_x                                    0x86D890
#define CListWnd__SetItemText_x                                    0x870B20
#define CListWnd__ShiftColumnSeparator_x                           0x8709B0
#define CListWnd__Sort_x                                           0x8722FD
#define CListWnd__ToggleSel_x                                      0x86D760

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6D2F10

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6F2FD0
#define CMerchantWnd__RequestBuyItem_x                             0x6F95A0
#define CMerchantWnd__RequestSellItem_x                            0x720970
#define CMerchantWnd__SelectRecoverySlot_x                         0x6F3280
#define CMerchantWnd__SelectBuySellSlot_x                          0x6F2490
#define CMerchantWnd__ActualSelect_x                               0x6F6A00

// CObfuscator
#define CObfuscator__doit_x                                        0x7EBD60

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8895C0
#define CSidlManager__CreateLabel_x                                0x7593E0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x622D80
#define CSidlScreenWnd__CalculateVSBRange_x                        0x622CB0
#define CSidlScreenWnd__ConvertToRes_x                             0x8A5620
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8771E0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x878590
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x878640
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x877B10
#define CSidlScreenWnd__DrawSidlPiece_x                            0x876CC0
#define CSidlScreenWnd__EnableIniStorage_x                         0x876410
#define CSidlScreenWnd__GetSidlPiece_x                             0x876EB0
#define CSidlScreenWnd__Init1_x                                    0x878260
#define CSidlScreenWnd__LoadIniInfo_x                              0x877290
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8765D0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x877D60
#define CSidlScreenWnd__StoreIniInfo_x                             0x875F80
#define CSidlScreenWnd__StoreIniVis_x                              0x8763A0
#define CSidlScreenWnd__WndNotification_x                          0x877FE0
#define CSidlScreenWnd__GetChildItem_x                             0x8764E0
#define CSidlScreenWnd__GetChildItem_x                             0x8764E0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x87CF50
// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5BDD50
#define CSkillMgr__GetSkillCap_x                                   0x5BDDD0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8AF650
#define CSliderWnd__SetValue_x                                     0x8AF820
#define CSliderWnd__SetNumTicks_x                                  0x8AFFA0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x760BB0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x89FDA0
#define CStmlWnd__CalculateHSBRange_x                              0x898410
#define CStmlWnd__CalculateVSBRange_x                              0x8984A0
#define CStmlWnd__CanBreakAtCharacter_x                            0x898620
#define CStmlWnd__FastForwardToEndOfTag_x                          0x898F00
#define CStmlWnd__ForceParseNow_x                                  0x8A06F0
#define CStmlWnd__GetNextTagPiece_x                                0x898E00
#define CStmlWnd__GetSTMLText_x                                    0x6595D0
#define CStmlWnd__GetVisibleText_x                                 0x899950
#define CStmlWnd__InitializeWindowVariables_x                      0x89BC00
#define CStmlWnd__MakeStmlColorTag_x                               0x8975F0
#define CStmlWnd__MakeWndNotificationTag_x                         0x897650
#define CStmlWnd__SetSTMLText_x                                    0x89D460
#define CStmlWnd__StripFirstSTMLLines_x                            0x89FA40
#define CStmlWnd__UpdateHistoryString_x                            0x89A890

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8A6E10
#define CTabWnd__DrawCurrentPage_x                                 0x8A6680
#define CTabWnd__DrawTab_x                                         0x8A6450
#define CTabWnd__GetCurrentPage_x                                  0x8A6A50
#define CTabWnd__GetPageInnerRect_x                                0x8A6140
#define CTabWnd__GetTabInnerRect_x                                 0x8A6340
#define CTabWnd__GetTabRect_x                                      0x8A6210
#define CTabWnd__InsertPage_x                                      0x8A7100
#define CTabWnd__SetPage_x                                         0x8A6A80
#define CTabWnd__SetPageRect_x                                     0x8A6D50
#define CTabWnd__UpdatePage_x                                      0x8A70A0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41FB10

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8A31E0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8AC010

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x86AA10

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x563350
#define CXStr__CXStr1_x                                            0x703FC0
#define CXStr__CXStr3_x                                            0x822020
#define CXStr__dCXStr_x                                            0x401000
#define CXStr__operator_equal_x                                    0x822190
#define CXStr__operator_equal1_x                                   0x8221E0
#define CXStr__operator_plus_equal1_x                              0x8232C0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x87C1A0
#define CXWnd__Center_x                                            0x882320
#define CXWnd__ClrFocus_x                                          0x87BD80
#define CXWnd__DoAllDrawing_x                                      0x881F90
#define CXWnd__DrawChildren_x                                      0x882120
#define CXWnd__DrawColoredRect_x                                   0x87C550
#define CXWnd__DrawTooltip_x                                       0x87C800
#define CXWnd__DrawTooltipAtPoint_x                                0x880F00
#define CXWnd__GetBorderFrame_x                                    0x87CC50
#define CXWnd__GetChildWndAt_x                                     0x87FEA0
#define CXWnd__GetClientClipRect_x                                 0x87CA10
#define CXWnd__GetScreenClipRect_x                                 0x8815F0
#define CXWnd__GetScreenRect_x                                     0x87CE00
#define CXWnd__GetTooltipRect_x                                    0x87C690
#define CXWnd__GetWindowTextA_x                                    0x411320
#define CXWnd__IsActive_x                                          0x88F4C0
#define CXWnd__IsDescendantOf_x                                    0x87CBA0
#define CXWnd__IsReallyVisible_x                                   0x87FE80
#define CXWnd__IsType_x                                            0x8A8780
#define CXWnd__Move_x                                              0x87F5A0
#define CXWnd__Move1_x                                             0x881C40
#define CXWnd__ProcessTransition_x                                 0x87C150
#define CXWnd__Refade_x                                            0x87BF20
#define CXWnd__Resize_x                                            0x87CEC0
#define CXWnd__Right_x                                             0x8813F0
#define CXWnd__SetFocus_x                                          0x87E710
#define CXWnd__SetFont_x                                           0x87BDD0
#define CXWnd__SetKeyTooltip_x                                     0x87D120
#define CXWnd__SetMouseOver_x                                      0x881930
#define CXWnd__StartFade_x                                         0x87C1F0
#define CXWnd__GetChildItem_x                                      0x881870

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x890DD0
#define CXWndManager__DrawWindows_x                                0x890A10
#define CXWndManager__GetKeyboardFlags_x                           0x88F030
#define CXWndManager__HandleKeyboardMsg_x                          0x88F950
#define CXWndManager__RemoveWnd_x                                  0x88F650

// CDBStr
#define CDBStr__GetString_x                                        0x486E10

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8DE210
#define EQ_Character__CastSpell_x                                  0x43AD50
#define EQ_Character__Cur_HP_x                                     0x44A3B0
#define EQ_Character__GetAACastingTimeModifier_x                   0x433A70
#define EQ_Character__GetCharInfo2_x                               0x7F6980
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42CC80
#define EQ_Character__GetFocusRangeModifier_x                      0x42CE60
#define EQ_Character__Max_Endurance_x                              0x584AF0
#define EQ_Character__Max_HP_x                                     0x444580
#define EQ_Character__Max_Mana_x                                   0x584970
#define EQ_Character__doCombatAbility_x                            0x583480
#define EQ_Character__UseSkill_x                                   0x45B7B0
#define EQ_Character__GetConLevel_x                                0x57A9F0
#define EQ_Character__IsExpansionFlag_x                            0x410860
#define EQ_Character__TotalEffect_x                                0x438EC0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x55B4A0
#define EQ_Item__CreateItemTagString_x                             0x7D6F00
#define EQ_Item__IsStackable_x                                     0x7CB460
#define EQ_Item__GetImageNum_x                                     0x7CE0D0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A6410
#define EQ_LoadingS__Array_x                                       0xADDCE8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5890E0
#define EQ_PC__GetAltAbilityIndex_x                                0x7DF8E0
#define EQ_PC__GetCombatAbility_x                                  0x7DF970
#define EQ_PC__GetCombatAbilityTimer_x                             0x7DFA20
#define EQ_PC__GetItemTimerValue_x                                 0x5831C0
#define EQ_PC__HasLoreItem_x                                       0x57DAC0
#define EQ_PC__AlertInventoryChanged_x                             0x57A9C0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E0650
#define EQItemList__add_item_x                                     0x4E0590
#define EQItemList__delete_item_x                                  0x4E0A50
#define EQItemList__FreeItemList_x                                 0x4E0950

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4860B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x58EE40
#define EQPlayer__dEQPlayer_x                                      0x593AD0
#define EQPlayer__DoAttack_x                                       0x5A7DF0
#define EQPlayer__EQPlayer_x                                       0x5992C0
#define EQPlayer__SetNameSpriteState_x                             0x5912E0
#define EQPlayer__SetNameSpriteTint_x                              0x58EEB0
#define EQPlayer__IsBodyType_j_x                                   0x8DDA80
#define EQPlayer__IsTargetable_x                                   0x8DDD50

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x59C7B0
#define EQPlayerManager__GetSpawnByName_x                          0x59CC10

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x561680
#define KeypressHandler__AttachKeyToEqCommand_x                    0x5616C0
#define KeypressHandler__ClearCommandStateArray_x                  0x561260
#define KeypressHandler__HandleKeyDown_x                           0x55FBA0
#define KeypressHandler__HandleKeyUp_x                             0x55FEC0
#define KeypressHandler__SaveKeymapping_x                          0x561330

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6CB330
#define MapViewMap__SaveEx_x                                       0x6CEC10

#define PlayerPointManager__GetAltCurrency_x                       0x7F0B50

// StringTable 
#define StringTable__getString_x                                   0x7EC000

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5879D0

//Doors
#define EQSwitch__UseSwitch_x                                      0x517F60

//IconCache
#define IconCache__GetIcon_x                                       0x669B90

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x660BC0
#define CContainerMgr__CloseContainer_x                            0x6613D0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7297B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x554F30
