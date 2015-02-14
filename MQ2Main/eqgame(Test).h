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
#define __ExpectedVersionDate                                     "Feb  6 2015"
#define __ExpectedVersionTime                                     "14:20:02"
#define __ActualVersionDate_x                                      0xA78FF8
#define __ActualVersionTime_x                                      0xA79004

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5901E0
#define __MemChecker1_x                                            0x858BB0
#define __MemChecker2_x                                            0x627B30
#define __MemChecker3_x                                            0x627A80
#define __MemChecker4_x                                            0x7DC2D0
#define __EncryptPad0_x                                            0xBF2648
#define __EncryptPad1_x                                            0xD72B60
#define __EncryptPad2_x                                            0xC3AA70
#define __EncryptPad3_x                                            0xC3A670
#define __EncryptPad4_x                                            0xD4F9E8
#define __AC1_x                                                    0x799C85
#define __AC2_x                                                    0x5461A7
#define __AC3_x                                                    0x55A9A0
#define __AC4_x                                                    0x560DE0
#define __AC5_x                                                    0x56CB9E
#define __AC6_x                                                    0x5706F2
#define __AC7_x                                                    0x56728C
#define __AC1_Data                                                 0x11111111

// Direct Input
#define DI8__Main_x                                                0x1124628
#define DI8__Keyboard_x                                            0x112462C
#define DI8__Mouse_x                                               0x1124630
#define __AltTimerReady_x                                          0xF83FA9
#define __Attack_x                                                 0x10171B7
#define __Autofire_x                                               0x10171B8
#define __BindList_x                                               0xBB5978
#define __bCommandEnabled_x                                        0xF820B8
#define __Clicks_x                                                 0xF92D18
#define __CommandList_x                                            0xBB9B98
#define __CurrentMapLabel_x                                        0x112A080
#define __CurrentSocial_x                                          0xB738F0
#define __DoAbilityList_x                                          0xFC946C
#define __do_loot_x                                                0x50DD10
#define __DrawHandler_x                                            0x178EC8C
#define __GroupCount_x                                             0xF83682

#define __Guilds_x                                                 0xF89298
#define __gWorld_x                                                 0xF85B3C
#define __HotkeyPage_x                                             0x100FE6C
#define __HWnd_x                                                   0x101C530
#define __InChatMode_x                                             0xF92C44
#define __LastTell_x                                               0xF94B74
#define __LMouseHeldTime_x                                         0xF92D84
#define __Mouse_x                                                  0x1124634
#define __MouseLook_x                                              0xF92CDE
#define __MouseEventTime_x                                         0x10179BC
#define __NetStatusToggle_x                                        0xF92CE1
#define __PCNames_x                                                0xF94198
#define __RangeAttackReady_x                                       0xF93E68
#define __RMouseHeldTime_x                                         0xF92D80
#define __RunWalkState_x                                           0xF92C48
#define __ScreenMode_x                                             0xED1F78
#define __ScreenX_x                                                0xF92BFC
#define __ScreenY_x                                                0xF92BF8
#define __ScreenXMax_x                                             0xF92C00
#define __ScreenYMax_x                                             0xF92C04
#define __ServerHost_x                                             0xF835CC
#define __ServerName_x                                             0xFC942C
#define __ShiftKeyDown_x                                           0xF932EC
#define __ShowNames_x                                              0xF9403C
#define __Socials_x                                                0xFC952C
#define __SubscriptionType_x                                       0x1156410
#define __TargetAggroHolder_x                                      0x112C2BC
#define __GroupAggro_x                                             0x112C2FC
#define __LoginName_x                                              0x101B108
#define __Inviter_x                                                0x1017134


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF85C28
#define instEQZoneInfo_x                                           0xF92ED4
#define instKeypressHandler_x                                      0x10179A0
#define pinstActiveBanker_x                                        0xF85BE0
#define pinstActiveCorpse_x                                        0xF85BE4
#define pinstActiveGMaster_x                                       0xF85BE8
#define pinstActiveMerchant_x                                      0xF85BDC
#define pinstAggroInfo_x                                           0xD963F8
#define pinstAltAdvManager_x                                       0xED3058
#define pinstAuraMgr_x                                             0xDA02C0
#define pinstBandageTarget_x                                       0xF85BC8
#define pinstCamActor_x                                            0xED2960
#define pinstCDBStr_x                                              0xED1F0C
#define pinstCDisplay_x                                            0xF85BF0
#define pinstCEverQuest_x                                          0x11247A8
#define pinstCharData_x                                            0xF85BAC
#define pinstCharSpawn_x                                           0xF85BD4
#define pinstControlledMissile_x                                   0xF85BA8
#define pinstControlledPlayer_x                                    0xF85BD4
#define pinstCSidlManager_x                                        0x178E0AC
#define pinstCXWndManager_x                                        0x178E0A4
#define instDynamicZone_x                                          0xF92A90
#define pinstDZMember_x                                            0xF92BA0
#define pinstDZTimerInfo_x                                         0xF92BA4
#define pinstEQItemList_x                                          0xF82308
#define instEQMisc_x                                               0xB93B88
#define pinstEQSoundManager_x                                      0xED3450
#define instExpeditionLeader_x                                     0xF92ADA
#define instExpeditionName_x                                       0xF92B1A
#define pinstGroup_x                                               0xF8367E
#define pinstImeManager_x                                          0x178E0B0
#define pinstLocalPlayer_x                                         0xF85BC0
#define pinstMercenaryData_x                                       0x1017FF0
#define pinstMercAltAbilities_x                                    0xED336C
#define pinstModelPlayer_x                                         0xF85BEC
#define pinstPCData_x                                              0xF85BAC
#define pinstSkillMgr_x                                            0x1018E28
#define pinstSpawnManager_x                                        0x1018710
#define pinstSpellManager_x                                        0x1018F70
#define pinstSpellSets_x                                           0x100FED0
#define pinstStringTable_x                                         0xF85B54
#define pinstSwitchManager_x                                       0xF83210
#define pinstTarget_x                                              0xF85BD8
#define pinstTargetObject_x                                        0xF85BB0
#define pinstTargetSwitch_x                                        0xF85BB4
#define pinstTaskMember_x                                          0xED1E58
#define pinstTrackTarget_x                                         0xF85BCC
#define pinstTradeTarget_x                                         0xF85BBC
#define instTributeActive_x                                        0xB93BAD
#define pinstViewActor_x                                           0xED295C
#define pinstWorldData_x                                           0xF85B90


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD968D8
#define pinstCAudioTriggersWindow_x                                0xD96768
#define pinstCCharacterSelect_x                                    0xED2800
#define pinstCFacePick_x                                           0xED27B0
#define pinstCNoteWnd_x                                            0xED27B8
#define pinstCBookWnd_x                                            0xED27C0
#define pinstCPetInfoWnd_x                                         0xED27C4
#define pinstCTrainWnd_x                                           0xED27C8
#define pinstCSkillsWnd_x                                          0xED27CC
#define pinstCSkillsSelectWnd_x                                    0xED27D0
#define pinstCCombatSkillSelectWnd_x                               0xED27D4
#define pinstCFriendsWnd_x                                         0xED27D8
#define pinstCAuraWnd_x                                            0xED27DC
#define pinstCRespawnWnd_x                                         0xED27E0
#define pinstCBandolierWnd_x                                       0xED27E4
#define pinstCPotionBeltWnd_x                                      0xED27E8
#define pinstCAAWnd_x                                              0xED27EC
#define pinstCGroupSearchFiltersWnd_x                              0xED27F0
#define pinstCLoadskinWnd_x                                        0xED27F4
#define pinstCAlarmWnd_x                                           0xED27F8
#define pinstCMusicPlayerWnd_x                                     0xED27FC
#define pinstCMailWnd_x                                            0xED2804
#define pinstCMailCompositionWnd_x                                 0xED2808
#define pinstCMailAddressBookWnd_x                                 0xED280C
#define pinstCRaidWnd_x                                            0xED2814
#define pinstCRaidOptionsWnd_x                                     0xED2818
#define pinstCBreathWnd_x                                          0xED281C
#define pinstCMapViewWnd_x                                         0xED2820
#define pinstCMapToolbarWnd_x                                      0xED2824
#define pinstCEditLabelWnd_x                                       0xED2828
#define pinstCTargetWnd_x                                          0xED282C
#define pinstCColorPickerWnd_x                                     0xED2830
#define pinstCPlayerWnd_x                                          0xED2834
#define pinstCOptionsWnd_x                                         0xED2838
#define pinstCBuffWindowNORMAL_x                                   0xED283C
#define pinstCBuffWindowSHORT_x                                    0xED2840
#define pinstCharacterCreation_x                                   0xED2844
#define pinstCCursorAttachment_x                                   0xED2848
#define pinstCCastingWnd_x                                         0xED284C
#define pinstCCastSpellWnd_x                                       0xED2850
#define pinstCSpellBookWnd_x                                       0xED2854
#define pinstCInventoryWnd_x                                       0xED2858
#define pinstCBankWnd_x                                            0xED285C
#define pinstCQuantityWnd_x                                        0xED2860
#define pinstCLootWnd_x                                            0xED2864
#define pinstCActionsWnd_x                                         0xED2868
#define pinstCCombatAbilityWnd_x                                   0xED286C
#define pinstCMerchantWnd_x                                        0xED2870
#define pinstCTradeWnd_x                                           0xED2874
#define pinstCSelectorWnd_x                                        0xED2878
#define pinstCBazaarWnd_x                                          0xED287C
#define pinstCBazaarSearchWnd_x                                    0xED2880
#define pinstCGiveWnd_x                                            0xED289C
#define pinstCTrackingWnd_x                                        0xED28A4
#define pinstCInspectWnd_x                                         0xED28A8
#define pinstCSocialEditWnd_x                                      0xED28AC
#define pinstCFeedbackWnd_x                                        0xED28B0
#define pinstCBugReportWnd_x                                       0xED28B4
#define pinstCVideoModesWnd_x                                      0xED28B8
#define pinstCTextEntryWnd_x                                       0xED28C0
#define pinstCFileSelectionWnd_x                                   0xED28C4
#define pinstCCompassWnd_x                                         0xED28C8
#define pinstCPlayerNotesWnd_x                                     0xED28CC
#define pinstCGemsGameWnd_x                                        0xED28D0
#define pinstCTimeLeftWnd_x                                        0xED28D4
#define pinstCPetitionQWnd_x                                       0xED28E8
#define pinstCSoulmarkWnd_x                                        0xED28EC
#define pinstCStoryWnd_x                                           0xED28F0
#define pinstCJournalTextWnd_x                                     0xED28F4
#define pinstCJournalCatWnd_x                                      0xED28F8
#define pinstCBodyTintWnd_x                                        0xED28FC
#define pinstCServerListWnd_x                                      0xED2900
#define pinstCAvaZoneWnd_x                                         0xED290C
#define pinstCBlockedBuffWnd_x                                     0xED2910
#define pinstCBlockedPetBuffWnd_x                                  0xED2914
#define pinstCInvSlotMgr_x                                         0xED2954
#define pinstCContainerMgr_x                                       0xED2958
#define pinstCAdventureLeaderboardWnd_x                            0x1125158
#define pinstCAdventureRequestWnd_x                                0x11251D0
#define pinstCAltStorageWnd_x                                      0x11254B0
#define pinstCAdventureStatsWnd_x                                  0x1125248
#define pinstCBarterMerchantWnd_x                                  0x1126098
#define pinstCBarterSearchWnd_x                                    0x1126110
#define pinstCBarterWnd_x                                          0x1126188
#define pinstCChatManager_x                                        0x1126818
#define pinstCDynamicZoneWnd_x                                     0x1126CC8
#define pinstCEQMainWnd_x                                          0x1126E60
#define pinstCFellowshipWnd_x                                      0x1126C5C
#define pinstCFindLocationWnd_x                                    0x1127130
#define pinstCGroupSearchWnd_x                                     0x1127400
#define pinstCGroupWnd_x                                           0x1127478
#define pinstCGuildBankWnd_x                                       0x11274F0
#define pinstCGuildMgmtWnd_x                                       0x11295E0
#define pinstCHotButtonWnd_x                                       0x11296AC
#define pinstCHotButtonWnd1_x                                      0x11296AC
#define pinstCHotButtonWnd2_x                                      0x11296B0
#define pinstCHotButtonWnd3_x                                      0x11296B4
#define pinstCHotButtonWnd4_x                                      0x11296D8
#define pinstCItemDisplayManager_x                                 0x11299D0
#define pinstCItemExpTransferWnd_x                                 0x1129A4C
#define pinstCLFGuildWnd_x                                         0x1129D28
#define pinstCMIZoneSelectWnd_x                                    0x112A310
#define pinstCConfirmationDialog_x                                 0x112AA18
#define pinstCPopupWndManager_x                                    0x112AA18
#define pinstCProgressionSelectionWnd_x                            0x112AB08
#define pinstCPvPStatsWnd_x                                        0x112ABF8
#define pinstCSystemInfoDialogBox_x                                0x112B300
#define pinstCTaskWnd_x                                            0x112C6C8
#define pinstCTaskSomething_x                                      0xDA0A00
#define pinstCTaskTemplateSelectWnd_x                              0x112C650
#define pinstCTipWndOFDAY_x                                        0x112C920
#define pinstCTipWndCONTEXT_x                                      0x112C924
#define pinstCTitleWnd_x                                           0x112C9A0
#define pinstCContextMenuManager_x                                 0x178E130
#define pinstCVoiceMacroWnd_x                                      0x10195D8
#define pinstCHtmlWnd_x                                            0x10196D0
#define pinstIconCache_x                                           0x1126E34
#define pinstCTradeskillWnd_x                                      0x112CAA0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x525700
#define __ConvertItemTags_x                                        0x512990
#define __ExecuteCmd_x                                             0x4FD350
#define __EQGetTime_x                                              0x858ED0
#define __get_melee_range_x                                        0x504030
#define __GetGaugeValueFromEQ_x                                    0x7989D0
#define __GetLabelFromEQ_x                                         0x799C10
#define __ToggleMount_x                                            0x6C2000
#define __GetXTargetType_x                                         0x917170
#define __LoadFrontEnd_x                                           0x6271E0
#define __NewUIINI_x                                               0x7982D0
#define __ProcessGameEvents_x                                      0x568FF0
#define __ProcessMouseEvent_x                                      0x568790
#define CrashDetected_x                                            0x628CB0
#define wwsCrashReportCheckForUploader_x                           0x7EDC20
#define DrawNetStatus_x                                            0x59FD00
#define Util__FastTime_x                                           0x858A20
#define Expansion_HoT_x                                            0xF93FD4
#define __HelpPath_x                                               0x1017728
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4BD4A0
#define AltAdvManager__IsAbilityReady_x                            0x4BD510
#define AltAdvManager__GetAltAbility_x                             0x4BD8D0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x462020
#define CharacterZoneClient__MakeMeVisible_x                       0x4670E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x656A10

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x664940

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x57F0D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x67FD60
#define CChatManager__InitContextMenu_x                            0x680880

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8C8390
#define CContextMenu__AddMenuItem_x                                0x8C85B0
#define CContextMenu__dCContextMenu_x                              0x8C85A0
#define CContextMenu__RemoveMenuItem_x                             0x8C88A0
#define CContextMenu__RemoveAllMenuItems_x                         0x8C88C0
#define CContextMenuManager__AddMenu_x                             0x8CB590
#define CContextMenuManager__RemoveMenu_x                          0x8CB8D0
#define CContextMenuManager__PopupMenu_x                           0x8CBD20
#define CContextMenuManager__Flush_x                               0x8CB600

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x83F750
#define CChatService__GetFriendName_x                              0x83F760

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6856D0
#define CChatWindow__Clear_x                                       0x685280
#define CChatWindow__WndNotification_x                             0x685C10

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8BBA50
#define CComboWnd__Draw_x                                          0x8BBC50
#define CComboWnd__GetCurChoice_x                                  0x8BB820
#define CComboWnd__GetListRect_x                                   0x8BBEF0
#define CComboWnd__GetTextRect_x                                   0x8BBAB0
#define CComboWnd__InsertChoice_x                                  0x8BBF60
#define CComboWnd__SetColors_x                                     0x8BB7B0
#define CComboWnd__SetChoice_x                                     0x8BB7E0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x68EE80
#define CContainerWnd__vftable_x                                   0xA82750

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4ABD20
#define CDisplay__GetClickedActor_x                                0x4A48A0
#define CDisplay__GetUserDefinedColor_x                            0x4A3160
#define CDisplay__GetWorldFilePath_x                               0x4A25B0
#define CDisplay__is3dON_x                                         0x4A1980
#define CDisplay__ReloadUI_x                                       0x4B7120
#define CDisplay__WriteTextHD2_x                                   0x4A80C0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8DF4D0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8CD8E0
#define CEditWnd__GetCharIndexPt_x                                 0x8CE900
#define CEditWnd__GetDisplayString_x                               0x8CDA90
#define CEditWnd__GetHorzOffset_x                                  0x8CDDD0
#define CEditWnd__GetLineForPrintableChar_x                        0x8CE3D0
#define CEditWnd__GetSelStartPt_x                                  0x8CEBB0
#define CEditWnd__GetSTMLSafeText_x                                0x8CDF70
#define CEditWnd__PointFromPrintableChar_x                         0x8CE4C0
#define CEditWnd__SelectableCharFromPoint_x                        0x8CE640
#define CEditWnd__SetEditable_x                                    0x8CDF40

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x5468F0
#define CEverQuest__DoTellWindow_x                                 0x54C2F0
#define CEverQuest__DropHeldItemOnGround_x                         0x554E20
#define CEverQuest__dsp_chat_x                                     0x54DA90
#define CEverQuest__Emote_x                                        0x54DCF0
#define CEverQuest__EnterZone_x                                    0x561600
#define CEverQuest__GetBodyTypeDesc_x                              0x543150
#define CEverQuest__GetClassDesc_x                                 0x548E60
#define CEverQuest__GetClassThreeLetterCode_x                      0x549460
#define CEverQuest__GetDeityDesc_x                                 0x543A30
#define CEverQuest__GetLangDesc_x                                  0x5434E0
#define CEverQuest__GetRaceDesc_x                                  0x549620
#define CEverQuest__InterpretCmd_x                                 0x54E5D0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5656F0
#define CEverQuest__LMouseUp_x                                     0x5677E0
#define CEverQuest__RightClickedOnPlayer_x                         0x5661F0
#define CEverQuest__RMouseUp_x                                     0x567240
#define CEverQuest__SetGameState_x                                 0x546FA0
#define CEverQuest__UPCNotificationFlush_x                         0x54F770
#define CEverQuest__IssuePetCommand_x                              0x54F2D0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x69F930
#define CGaugeWnd__CalcLinesFillRect_x                             0x69F990
#define CGaugeWnd__Draw_x                                          0x69FDC0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4338E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6BCA40

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6CA850
#define CInvSlotMgr__MoveItem_x                                    0x6CB790
#define CInvSlotMgr__SelectSlot_x                                  0x6CA900

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6C9CF0
#define CInvSlot__SliderComplete_x                                 0x6C76B0
#define CInvSlot__GetItemBase_x                                    0x6C6B00

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6CC950

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7954D0
#define CItemDisplayWnd__UpdateStrings_x                           0x6CDC80

// CLabel 
#define CLabel__Draw_x                                             0x6E89E0

// CListWnd 
#define CListWnd__CListWnd_x                                       0x8A4CB0
#define CListWnd__dCListWnd_x                                      0x8A5D40
#define CListWnd__AddColumn_x                                      0x8A5CE0
#define CListWnd__AddColumn1_x                                     0x8A54C0
#define CListWnd__AddLine_x                                        0x8A4F70
#define CListWnd__AddString_x                                      0x8A5180
#define CListWnd__CalculateFirstVisibleLine_x                      0x8A2010
#define CListWnd__CalculateVSBRange_x                              0x8A4170
#define CListWnd__ClearAllSel_x                                    0x8A12D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8A4B40
#define CListWnd__Compare_x                                        0x8A2B00
#define CListWnd__Draw_x                                           0x8A3D80
#define CListWnd__DrawColumnSeparators_x                           0x8A3C10
#define CListWnd__DrawHeader_x                                     0x8A15E0
#define CListWnd__DrawItem_x                                       0x8A3140
#define CListWnd__DrawLine_x                                       0x8A38B0
#define CListWnd__DrawSeparator_x                                  0x8A3CB0
#define CListWnd__EnsureVisible_x                                  0x8A2170
#define CListWnd__ExtendSel_x                                      0x8A3050
#define CListWnd__GetColumnMinWidth_x                              0x8A0CF0
#define CListWnd__GetColumnWidth_x                                 0x8A0C10
#define CListWnd__GetCurSel_x                                      0x8A03E0
#define CListWnd__GetItemAtPoint_x                                 0x8A2400
#define CListWnd__GetItemAtPoint1_x                                0x8A2470
#define CListWnd__GetItemData_x                                    0x8A0720
#define CListWnd__GetItemHeight_x                                  0x8A1C70
#define CListWnd__GetItemIcon_x                                    0x8A0900
#define CListWnd__GetItemRect_x                                    0x8A2240
#define CListWnd__GetItemText_x                                    0x8A07B0
#define CListWnd__GetSelList_x                                     0x8A53B0
#define CListWnd__GetSeparatorRect_x                               0x8A2A30
#define CListWnd__RemoveLine_x                                     0x8A5360
#define CListWnd__SetColors_x                                      0x8A0530
#define CListWnd__SetColumnJustification_x                         0x8A0FC0
#define CListWnd__SetColumnWidth_x                                 0x8A0CA0
#define CListWnd__SetCurSel_x                                      0x8A0420
#define CListWnd__SetItemColor_x                                   0x8A4820
#define CListWnd__SetItemData_x                                    0x8A1380
#define CListWnd__SetItemText_x                                    0x8A4660
#define CListWnd__ShiftColumnSeparator_x                           0x8A44F0
#define CListWnd__Sort_x                                           0x8A5E40
#define CListWnd__ToggleSel_x                                      0x8A1250

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x701DE0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7231E0
#define CMerchantWnd__RequestBuyItem_x                             0x72A050
#define CMerchantWnd__RequestSellItem_x                            0x72AAC0
#define CMerchantWnd__SelectRecoverySlot_x                         0x723490
#define CMerchantWnd__SelectBuySellSlot_x                          0x7226F0
#define CMerchantWnd__ActualSelect_x                               0x726F70

// CObfuscator
#define CObfuscator__doit_x                                        0x81F930

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8C3280
#define CSidlManager__CreateLabel_x                                0x78B460

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x64DD40
#define CSidlScreenWnd__CalculateVSBRange_x                        0x64DC70
#define CSidlScreenWnd__ConvertToRes_x                             0x8DF3B0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8AEDD0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8B02D0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8B0380
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8AF840
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8AE7A0
#define CSidlScreenWnd__EnableIniStorage_x                         0x8ADF10
#define CSidlScreenWnd__GetSidlPiece_x                             0x8AE990
#define CSidlScreenWnd__Init1_x                                    0x8AFFA0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8AEE80
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8AE0D0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8AFA90
#define CSidlScreenWnd__StoreIniInfo_x                             0x8AD9D0
#define CSidlScreenWnd__StoreIniVis_x                              0x8ADEA0
#define CSidlScreenWnd__WndNotification_x                          0x8AFD20
#define CSidlScreenWnd__GetChildItem_x                             0x8ADFE0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8B4400

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5E92F0
#define CSkillMgr__GetSkillCap_x                                   0x5E9490
#define CSkillMgr__GetNameToken_x                                  0x5E8F60

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8DE660
#define CSliderWnd__SetValue_x                                     0x8DE830
#define CSliderWnd__SetNumTicks_x                                  0x8DEFB0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x793170

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8D8FD0
#define CStmlWnd__CalculateHSBRange_x                              0x8D15A0
#define CStmlWnd__CalculateVSBRange_x                              0x8D1510
#define CStmlWnd__CanBreakAtCharacter_x                            0x8D1710
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8D1FF0
#define CStmlWnd__ForceParseNow_x                                  0x8D9990
#define CStmlWnd__GetNextTagPiece_x                                0x8D1EF0
#define CStmlWnd__GetSTMLText_x                                    0x684B20
#define CStmlWnd__GetVisibleText_x                                 0x8D2A40
#define CStmlWnd__InitializeWindowVariables_x                      0x8D4DB0
#define CStmlWnd__MakeStmlColorTag_x                               0x8D0810
#define CStmlWnd__MakeWndNotificationTag_x                         0x8D0870
#define CStmlWnd__SetSTMLText_x                                    0x8D6610
#define CStmlWnd__StripFirstSTMLLines_x                            0x8D8C70
#define CStmlWnd__UpdateHistoryString_x                            0x8D3970

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8E0BA0
#define CTabWnd__DrawCurrentPage_x                                 0x8E0410
#define CTabWnd__DrawTab_x                                         0x8E01D0
#define CTabWnd__GetCurrentPage_x                                  0x8E07E0
#define CTabWnd__GetPageInnerRect_x                                0x8DFEC0
#define CTabWnd__GetTabInnerRect_x                                 0x8E00C0
#define CTabWnd__GetTabRect_x                                      0x8DFF90
#define CTabWnd__InsertPage_x                                      0x8E0E90
#define CTabWnd__SetPage_x                                         0x8E0810
#define CTabWnd__SetPageRect_x                                     0x8E0AE0
#define CTabWnd__UpdatePage_x                                      0x8E0E30

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x42F630

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BB420

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8E5E20

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x89E630

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x414CB0
#define CXStr__CXStr1_x                                            0x89F600
#define CXStr__CXStr3_x                                            0x855AB0
#define CXStr__dCXStr_x                                            0x796570
#define CXStr__operator_equal_x                                    0x855C20
#define CXStr__operator_equal1_x                                   0x855C70
#define CXStr__operator_plus_equal1_x                              0x856D50

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8B3630
#define CXWnd__Center_x                                            0x8B97F0
#define CXWnd__ClrFocus_x                                          0x8B3210
#define CXWnd__DoAllDrawing_x                                      0x8B9450
#define CXWnd__DrawChildren_x                                      0x8B95F0
#define CXWnd__DrawColoredRect_x                                   0x8B39D0
#define CXWnd__DrawTooltip_x                                       0x8B3C60
#define CXWnd__DrawTooltipAtPoint_x                                0x8B83D0
#define CXWnd__GetBorderFrame_x                                    0x8B40D0
#define CXWnd__GetChildWndAt_x                                     0x8B73C0
#define CXWnd__GetClientClipRect_x                                 0x8B3E80
#define CXWnd__GetScreenClipRect_x                                 0x8B8AD0
#define CXWnd__GetScreenRect_x                                     0x8B42A0
#define CXWnd__GetTooltipRect_x                                    0x8B3AF0
#define CXWnd__GetWindowTextA_x                                    0x420B00
#define CXWnd__IsActive_x                                          0x8A8B20
#define CXWnd__IsDescendantOf_x                                    0x8B4010
#define CXWnd__IsReallyVisible_x                                   0x8B73A0
#define CXWnd__IsType_x                                            0x8E2660
#define CXWnd__Move_x                                              0x8B6AA0
#define CXWnd__Move1_x                                             0x8B9100
#define CXWnd__ProcessTransition_x                                 0x8B35D0
#define CXWnd__Refade_x                                            0x8B33B0
#define CXWnd__Resize_x                                            0x8B4360
#define CXWnd__Right_x                                             0x8B88D0
#define CXWnd__SetFocus_x                                          0x8B5C00
#define CXWnd__SetFont_x                                           0x8B3260
#define CXWnd__SetKeyTooltip_x                                     0x8B45D0
#define CXWnd__SetMouseOver_x                                      0x8B8DF0
#define CXWnd__StartFade_x                                         0x8B3680
#define CXWnd__GetChildItem_x                                      0x8B8D30

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8AA440
#define CXWndManager__DrawWindows_x                                0x8AA080
#define CXWndManager__GetKeyboardFlags_x                           0x8A8650
#define CXWndManager__HandleKeyboardMsg_x                          0x8A8FB0
#define CXWndManager__RemoveWnd_x                                  0x8A8CB0

// CDBStr
#define CDBStr__GetString_x                                        0x49FE40

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44BA00
#define EQ_Character__Cur_HP_x                                     0x4616E0
#define EQ_Character__GetAACastingTimeModifier_x                   0x444AD0
#define EQ_Character__GetCharInfo2_x                               0x82A0F0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43CDE0
#define EQ_Character__GetFocusRangeModifier_x                      0x43CFC0
#define EQ_Character__Max_Endurance_x                              0x5B1960
#define EQ_Character__Max_HP_x                                     0x4579D0
#define EQ_Character__Max_Mana_x                                   0x5B1790
#define EQ_Character__doCombatAbility_x                            0x5AED80
#define EQ_Character__UseSkill_x                                   0x46C220
#define EQ_Character__GetConLevel_x                                0x5A4360
#define EQ_Character__IsExpansionFlag_x                            0x420050
#define EQ_Character__TotalEffect_x                                0x449B30

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x584900
#define EQ_Item__CreateItemTagString_x                             0x8096A0
#define EQ_Item__IsStackable_x                                     0x7FD830
#define EQ_Item__GetImageNum_x                                     0x800550

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4BF590
#define EQ_LoadingS__Array_x                                       0xBA15C0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5B3100
#define EQ_PC__GetAltAbilityIndex_x                                0x812650
#define EQ_PC__GetCombatAbility_x                                  0x8126E0
#define EQ_PC__GetCombatAbilityTimer_x                             0x812790
#define EQ_PC__GetItemTimerValue_x                                 0x5ACB60
#define EQ_PC__HasLoreItem_x                                       0x5A76A0
#define EQ_PC__AlertInventoryChanged_x                             0x5A4330
#define EQ_PC__GetPcZoneClient_x                                   0x5CD490
#define EQ_PC__RemoveMyAffect_x                                    0x5AC070

// EQItemList 
#define EQItemList__EQItemList_x                                   0x502040
#define EQItemList__add_item_x                                     0x501F80
#define EQItemList__delete_item_x                                  0x502440
#define EQItemList__FreeItemList_x                                 0x502340

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x49F070

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5B8580
#define EQPlayer__dEQPlayer_x                                      0x5C1370
#define EQPlayer__DoAttack_x                                       0x5D3310
#define EQPlayer__EQPlayer_x                                       0x5C3790
#define EQPlayer__SetNameSpriteState_x                             0x5BE040
#define EQPlayer__SetNameSpriteTint_x                              0x5B9950
#define EQPlayer__IsBodyType_j_x                                   0x913440
#define EQPlayer__IsTargetable_x                                   0x913CB0
#define EQPlayer__CanSee_x                                         0x9141D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5C7AA0
#define EQPlayerManager__GetSpawnByName_x                          0x5C7F00

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x58ABA0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x58ABE0
#define KeypressHandler__ClearCommandStateArray_x                  0x58A780
#define KeypressHandler__HandleKeyDown_x                           0x5890E0
#define KeypressHandler__HandleKeyUp_x                             0x589400
#define KeypressHandler__SaveKeymapping_x                          0x58A850

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6FA1C0
#define MapViewMap__SaveEx_x                                       0x6FDAA0

#define PlayerPointManager__GetAltCurrency_x                       0x824FE0

// StringTable 
#define StringTable__getString_x                                   0x81FBD0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5B1410

//Doors
#define EQSwitch__UseSwitch_x                                      0x540590

//IconCache
#define IconCache__GetIcon_x                                       0x695300

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x68C190
#define CContainerMgr__CloseContainer_x                            0x68C9B0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x75B5C0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x57DB90

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4D1AE0
#define EQ_Spell__SpellAffects_x                                   0x4D1B80
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4D1BB0
#define CharacterZoneClient__CalcAffectChange_x                    0x445DF0
#define CLootWnd__LootAll_x                                        0x6EFB60
//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7A0F50
#define CTargetWnd__WndNotification_x                              0x7A0A40

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7A6100
