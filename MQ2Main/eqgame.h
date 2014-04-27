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
#define __ExpectedVersionDate                                     "Sep 13 2013"
#define __ExpectedVersionTime                                     "10:56:15"
#define __ActualVersionDate_x                                      0x9E57A8
#define __ActualVersionTime_x                                      0x9E57B4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5674B0
#define __MemChecker1_x                                            0x81F7D0
#define __MemChecker2_x                                            0x5FC770
#define __MemChecker3_x                                            0x5FC6C0
#define __MemChecker4_x                                            0x7A9110
#define __EncryptPad0_x                                            0xAEDC58
#define __EncryptPad1_x                                            0xB6EE90
#define __EncryptPad2_x                                            0xB077A8
#define __EncryptPad3_x                                            0xB073A8
#define __EncryptPad4_x                                            0xB6B810
#define __AC1_x                                                    0x767165
#define __AC2_x                                                    0x51B947
#define __AC3_x                                                    0x52EDB0
#define __AC4_x                                                    0x534E04
#define __AC5_x                                                    0x540F51
#define __AC6_x                                                    0x544892
#define __AC7_x                                                    0x53ADCC
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0xE73B18
#define DI8__Keyboard_x                                            0xE73B1C
#define DI8__Mouse_x                                               0xE73B20
#define __AltTimerReady_x                                          0xDDC621
#define __Attack_x                                                 0xE6F1C2
#define __Autofire_x                                               0xE6F1C3
#define __BindList_x                                               0xAD54B0
#define __Clicks_x                                                 0xDEB34C
#define __CommandList_x                                            0xAD6BC8
#define __CurrentMapLabel_x                                        0xF80278
#define __CurrentSocial_x                                          0xABFC88
#define __DoAbilityList_x                                          0xE21A68
#define __do_loot_x                                                0x4E9EA0
#define __DrawHandler_x                                            0x15E1334
#define __GroupCount_x                                             0xDDBCFA

#define __Guilds_x                                                 0xDE1900
#define __gWorld_x                                                 0xDDE1B4
#define __HotkeyPage_x                                             0xE68468
#define __HWnd_x                                                   0xE73870
#define __InChatMode_x                                             0xDEB284
#define __LastTell_x                                               0xDED170
#define __LMouseHeldTime_x                                         0xDEB3B8
#define __Mouse_x                                                  0xE73B24
#define __MouseLook_x                                              0xDEB31A
#define __MouseEventTime_x                                         0xE6F6AC
#define __NetStatusToggle_x                                        0xDEB31D
#define __PCNames_x                                                0xDEC7E0
#define __RangeAttackReady_x                                       0xDEC47C
#define __RMouseHeldTime_x                                         0xDEB3B4
#define __RunWalkState_x                                           0xDEB288
#define __ScreenMode_x                                             0xD2ADC0
#define __ScreenX_x                                                0xDEB23C
#define __ScreenY_x                                                0xDEB238
#define __ScreenXMax_x                                             0xDEB240
#define __ScreenYMax_x                                             0xDEB244
#define __ServerHost_x                                             0xDDBC44
#define __ServerName_x                                             0xE21A28
#define __ShiftKeyDown_x                                           0xDEB918
#define __ShowNames_x                                              0xDEC688
#define __Socials_x                                                0xE21B28


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xDDE298
#define instEQZoneInfo_x                                           0xDEB508
#define instKeypressHandler_x                                      0xE6F690
#define pinstActiveBanker_x                                        0xDDE258
#define pinstActiveCorpse_x                                        0xDDE25C
#define pinstActiveGMaster_x                                       0xDDE260
#define pinstActiveMerchant_x                                      0xDDE254
#define pinstAggroInfo_x                                           0xB84860
#define pinstAltAdvManager_x                                       0xD2BDA8
#define pinstAuraMgr_x                                             0xB8E2D0
#define pinstBandageTarget_x                                       0xDDE240
#define pinstCamActor_x                                            0xD2B794
#define pinstCDBStr_x                                              0xD2AD80
#define pinstCDisplay_x                                            0xDDE268
#define pinstCEverQuest_x                                          0xE73C9C
#define pinstCharData_x                                            0xDDE224
#define pinstCharSpawn_x                                           0xDDE24C
#define pinstControlledMissile_x                                   0xDDE220
#define pinstControlledPlayer_x                                    0xDDE24C
#define pinstCSidlManager_x                                        0x15E09E8
#define pinstCXWndManager_x                                        0x15E09E0
#define instDynamicZone_x                                          0xDEB0D8
#define pinstDZMember_x                                            0xDEB1E8
#define pinstDZTimerInfo_x                                         0xDEB1EC
#define pinstEQItemList_x                                          0xDDAC40
#define instEQMisc_x                                               0xAC90E0
#define pinstEQSoundManager_x                                      0xD2BEE8
#define instExpeditionLeader_x                                     0xDEB122
#define instExpeditionName_x                                       0xDEB162
#define pinstGroup_x                                               0xDDBCF6
#define pinstImeManager_x                                          0x15E09EC
#define pinstLocalPlayer_x                                         0xDDE238
#define pinstMercenaryData_x                                       0xE6FBD0
#define pinstModelPlayer_x                                         0xDDE264
#define pinstPCData_x                                              0xDDE224
#define pinstSkillMgr_x                                            0xE704D0
#define pinstSpawnManager_x                                        0xE6FFF8
#define pinstSpellManager_x                                        0xE70590
#define pinstSpellSets_x                                           0xE684CC
#define pinstStringTable_x                                         0xDDE1CC
#define pinstSwitchManager_x                                       0xDDB8E0
#define pinstTarget_x                                              0xDDE250
#define pinstTargetObject_x                                        0xDDE228
#define pinstTargetSwitch_x                                        0xDDE22C
#define pinstTaskMember_x                                          0xD2AD04
#define pinstTrackTarget_x                                         0xDDE244
#define pinstTradeTarget_x                                         0xDDE234
#define instTributeActive_x                                        0xAC9105
#define pinstViewActor_x                                           0xD2B790
#define pinstWorldData_x                                           0xDDE208


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xB84B50
#define pinstCAudioTriggersWindow_x                                0xB84A70
#define pinstCCharacterSelect_x                                    0xD2B63C
#define pinstCFacePick_x                                           0xD2B3EC
#define pinstCNoteWnd_x                                            0xD2B5F4
#define pinstCBookWnd_x                                            0xD2B5FC
#define pinstCPetInfoWnd_x                                         0xD2B600
#define pinstCTrainWnd_x                                           0xD2B604
#define pinstCSkillsWnd_x                                          0xD2B608
#define pinstCSkillsSelectWnd_x                                    0xD2B60C
#define pinstCCombatSkillSelectWnd_x                               0xD2B610
#define pinstCFriendsWnd_x                                         0xD2B614
#define pinstCAuraWnd_x                                            0xD2B618
#define pinstCRespawnWnd_x                                         0xD2B61C
#define pinstCBandolierWnd_x                                       0xD2B620
#define pinstCPotionBeltWnd_x                                      0xD2B624
#define pinstCAAWnd_x                                              0xD2B628
#define pinstCGroupSearchFiltersWnd_x                              0xD2B62C
#define pinstCLoadskinWnd_x                                        0xD2B630
#define pinstCAlarmWnd_x                                           0xD2B634
#define pinstCMusicPlayerWnd_x                                     0xD2B638
#define pinstCMailWnd_x                                            0xD2B640
#define pinstCMailCompositionWnd_x                                 0xD2B644
#define pinstCMailAddressBookWnd_x                                 0xD2B648
#define pinstCRaidWnd_x                                            0xD2B650
#define pinstCRaidOptionsWnd_x                                     0xD2B654
#define pinstCBreathWnd_x                                          0xD2B658
#define pinstCMapViewWnd_x                                         0xD2B65C
#define pinstCMapToolbarWnd_x                                      0xD2B660
#define pinstCEditLabelWnd_x                                       0xD2B664
#define pinstCTargetWnd_x                                          0xD2B668
#define pinstCColorPickerWnd_x                                     0xD2B66C
#define pinstCPlayerWnd_x                                          0xD2B670
#define pinstCOptionsWnd_x                                         0xD2B674
#define pinstCBuffWindowNORMAL_x                                   0xD2B678
#define pinstCBuffWindowSHORT_x                                    0xD2B67C
#define pinstCharacterCreation_x                                   0xD2B680
#define pinstCCursorAttachment_x                                   0xD2B684
#define pinstCCastingWnd_x                                         0xD2B688
#define pinstCCastSpellWnd_x                                       0xD2B68C
#define pinstCSpellBookWnd_x                                       0xD2B690
#define pinstCInventoryWnd_x                                       0xD2B694
#define pinstCBankWnd_x                                            0xD2B698
#define pinstCQuantityWnd_x                                        0xD2B69C
#define pinstCLootWnd_x                                            0xD2B6A0
#define pinstCActionsWnd_x                                         0xD2B6A4
#define pinstCCombatAbilityWnd_x                                   0xD2B6A8
#define pinstCMerchantWnd_x                                        0xD2B6AC
#define pinstCTradeWnd_x                                           0xD2B6B0
#define pinstCSelectorWnd_x                                        0xD2B6B4
#define pinstCBazaarWnd_x                                          0xD2B6B8
#define pinstCBazaarSearchWnd_x                                    0xD2B6BC
#define pinstCGiveWnd_x                                            0xD2B6D8
#define pinstCTrackingWnd_x                                        0xD2B6E0
#define pinstCInspectWnd_x                                         0xD2B6E4
#define pinstCSocialEditWnd_x                                      0xD2B6E8
#define pinstCFeedbackWnd_x                                        0xD2B6EC
#define pinstCBugReportWnd_x                                       0xD2B6F0
#define pinstCVideoModesWnd_x                                      0xD2B6F4
#define pinstCTextEntryWnd_x                                       0xD2B6FC
#define pinstCFileSelectionWnd_x                                   0xD2B700
#define pinstCCompassWnd_x                                         0xD2B704
#define pinstCPlayerNotesWnd_x                                     0xD2B708
#define pinstCGemsGameWnd_x                                        0xD2B70C
#define pinstCTimeLeftWnd_x                                        0xD2B710
#define pinstCPetitionQWnd_x                                       0xD2B724
#define pinstCSoulmarkWnd_x                                        0xD2B728
#define pinstCStoryWnd_x                                           0xD2B72C
#define pinstCJournalTextWnd_x                                     0xD2B730
#define pinstCJournalCatWnd_x                                      0xD2B734
#define pinstCBodyTintWnd_x                                        0xD2B738
#define pinstCServerListWnd_x                                      0xD2B73C
#define pinstCAvaZoneWnd_x                                         0xD2B748
#define pinstCBlockedBuffWnd_x                                     0xD2B74C
#define pinstCBlockedPetBuffWnd_x                                  0xD2B750
#define pinstCInvSlotMgr_x                                         0xD2B788
#define pinstCContainerMgr_x                                       0xD2B78C
#define pinstCAdventureLeaderboardWnd_x                            0xF7C4F0
#define pinstCAdventureRequestWnd_x                                0xF7C540
#define pinstCAltStorageWnd_x                                      0xF7C710
#define pinstCAdventureStatsWnd_x                                  0xF7C590
#define pinstCBarterMerchantWnd_x                                  0xF7CDF0
#define pinstCBarterSearchWnd_x                                    0xF7CE40
#define pinstCBarterWnd_x                                          0xF7CE90
#define pinstCChatManager_x                                        0xF7D290
#define pinstCDynamicZoneWnd_x                                     0xF7D570
#define pinstCEQMainWnd_x                                          0xF7D678
#define pinstCFellowshipWnd_x                                      0xF7D534
#define pinstCFindLocationWnd_x                                    0xF7D838
#define pinstCGroupSearchWnd_x                                     0xF7DA40
#define pinstCGroupWnd_x                                           0xF7DA90
#define pinstCGuildBankWnd_x                                       0xF7DAE0
#define pinstCGuildMgmtWnd_x                                       0xF7FB80
#define pinstCHotButtonWnd_x                                       0xF7FBF4
#define pinstCHotButtonWnd1_x                                      0xF7FBF4
#define pinstCHotButtonWnd2_x                                      0xF7FBF8
#define pinstCHotButtonWnd3_x                                      0xF7FBFC
#define pinstCHotButtonWnd4_x                                      0xF7FC20
#define pinstCItemDisplayManager_x                                 0xF7FE00
#define pinstCItemExpTransferWnd_x                                 0xF7FE54
#define pinstCLFGuildWnd_x                                         0xF80060
#define pinstCMIZoneSelectWnd_x                                    0xF80420
#define pinstCConfirmationDialog_x                                 0xF80870
#define pinstCPopupWndManager_x                                    0xF80870
#define pinstCProgressionSelectionWnd_x                            0xF80908
#define pinstCPvPStatsWnd_x                                        0xF809A8
#define pinstCSystemInfoDialogBox_x                                0xF80DF8
#define pinstCTaskTemplateSelectWnd_x                              0xF81E00
#define pinstCTipWndOFDAY_x                                        0xF81FC0
#define pinstCTipWndCONTEXT_x                                      0xF81FC4
#define pinstCTitleWnd_x                                           0xF82010
#define pinstCContextMenuManager_x                                 0x15E05FC
#define pinstCVoiceMacroWnd_x                                      0xE709F8
#define pinstCHtmlWnd_x                                            0xE70AA0


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x4FF9C0
#define __ConvertItemTags_x                                        0x4EF8A0
#define __ExecuteCmd_x                                             0x4D9520
#define __EQGetTime_x                                              0x820330
#define __get_melee_range_x                                        0x4E0180
#define __GetGaugeValueFromEQ_x                                    0x765EC0
#define __GetLabelFromEQ_x                                         0x7670F0
#define __GetXTargetType_x                                         0x8DC180
#define __LoadFrontEnd_x                                           0x5FBE20
#define __NewUIINI_x                                               0x7657F0
#define __ProcessGameEvents_x                                      0x53CEB0
#define CrashDetected_x                                            0x5FE49B
#define DrawNetStatus_x                                            0x576680
#define Util__FastTime_x                                           0x81F670
#define Expansion_HoT_x                                            0xDEC5E8
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A3CB0
#define AltAdvManager__IsAbilityReady_x                            0x4A3CF0
#define AltAdvManager__GetAltAbility_x                             0x4A40D0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x44A330

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x62AD00

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x639190

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x552CA0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x653930
#define CChatManager__InitContextMenu_x                            0x654450

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x806530
#define CChatService__GetFriendName_x                              0x806540

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x659190
#define CChatWindow__Clear_x                                       0x658D40
#define CChatWindow__WndNotification_x                             0x6596C0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x87E6A0
#define CComboWnd__Draw_x                                          0x87E880
#define CComboWnd__GetCurChoice_x                                  0x87E4C0
#define CComboWnd__GetListRect_x                                   0x87EB20
#define CComboWnd__GetTextRect_x                                   0x87E700
#define CComboWnd__InsertChoice_x                                  0x87EB90
#define CComboWnd__SetColors_x                                     0x87E450
#define CComboWnd__SetChoice_x                                     0x87E480

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x662800
#define CContainerWnd__vftable_x                                   0x9EECD8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4939D0
#define CDisplay__GetClickedActor_x                                0x48B990
#define CDisplay__GetUserDefinedColor_x                            0x48A250
#define CDisplay__GetWorldFilePath_x                               0x489650
#define CDisplay__is3dON_x                                         0x488720
#define CDisplay__ReloadUI_x                                       0x49D9A0
#define CDisplay__WriteTextHD2_x                                   0x48EE20

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x89FF60

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x88EF20
#define CEditWnd__GetCharIndexPt_x                                 0x88FF40
#define CEditWnd__GetDisplayString_x                               0x88F0D0
#define CEditWnd__GetHorzOffset_x                                  0x88F410
#define CEditWnd__GetLineForPrintableChar_x                        0x88FA10
#define CEditWnd__GetSelStartPt_x                                  0x8901F0
#define CEditWnd__GetSTMLSafeText_x                                0x88F5B0
#define CEditWnd__PointFromPrintableChar_x                         0x88FB00
#define CEditWnd__SelectableCharFromPoint_x                        0x88FC80
#define CEditWnd__SetEditable_x                                    0x88F580

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x51C090
#define CEverQuest__DoTellWindow_x                                 0x5209F0
#define CEverQuest__DropHeldItemOnGround_x                         0x5292B0
#define CEverQuest__dsp_chat_x                                     0x522190
#define CEverQuest__Emote_x                                        0x5223F0
#define CEverQuest__EnterZone_x                                    0x534F90
#define CEverQuest__GetBodyTypeDesc_x                              0x518650
#define CEverQuest__GetClassDesc_x                                 0x517DB0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5183B0
#define CEverQuest__GetDeityDesc_x                                 0x518F60
#define CEverQuest__GetLangDesc_x                                  0x5189E0
#define CEverQuest__GetRaceDesc_x                                  0x518CD0
#define CEverQuest__InterpretCmd_x                                 0x522CD0
#define CEverQuest__LeftClickedOnPlayer_x                          0x539310
#define CEverQuest__LMouseUp_x                                     0x53B520
#define CEverQuest__RightClickedOnPlayer_x                         0x539DD0
#define CEverQuest__RMouseUp_x                                     0x53AD80
#define CEverQuest__SetGameState_x                                 0x51C740
#define CEverQuest__UPCNotificationFlush_x                         0x523C60

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x672860
#define CGaugeWnd__CalcLinesFillRect_x                             0x6728C0
#define CGaugeWnd__Draw_x                                          0x672CF0

// CGuild
#define CGuild__FindMemberByName_x                                 0x423EE0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x68F9E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x69AF90
#define CInvSlotMgr__MoveItem_x                                    0x69BEC0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x69A390
#define CInvSlot__SliderComplete_x                                 0x6983B0
#define CInvSlot__GetItemBase_x                                    0x6978C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x69CC20

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x762B20
#define CItemDisplayWnd__UpdateStrings_x                           0x69DF90

// CLabel 
#define CLabel__Draw_x                                             0x6B8620

// CListWnd 
#define CListWnd__AddColumn_x                                      0x86C800
#define CListWnd__AddColumn1_x                                     0x86BFE0
#define CListWnd__AddLine_x                                        0x86BA90
#define CListWnd__AddString_x                                      0x86BCA0
#define CListWnd__CalculateFirstVisibleLine_x                      0x868B40
#define CListWnd__CalculateVSBRange_x                              0x86AC80
#define CListWnd__ClearAllSel_x                                    0x867DF0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x86B660
#define CListWnd__Compare_x                                        0x869650
#define CListWnd__Draw_x                                           0x86A8E0
#define CListWnd__DrawColumnSeparators_x                           0x86A770
#define CListWnd__DrawHeader_x                                     0x868100
#define CListWnd__DrawItem_x                                       0x869CA0
#define CListWnd__DrawLine_x                                       0x868100
#define CListWnd__DrawSeparator_x                                  0x86A810
#define CListWnd__EnsureVisible_x                                  0x868CA0
#define CListWnd__ExtendSel_x                                      0x869BB0
#define CListWnd__GetColumnMinWidth_x                              0x867810
#define CListWnd__GetColumnWidth_x                                 0x867730
#define CListWnd__GetCurSel_x                                      0x867000
#define CListWnd__GetItemAtPoint_x                                 0x868F40
#define CListWnd__GetItemAtPoint1_x                                0x868FB0
#define CListWnd__GetItemData_x                                    0x867240
#define CListWnd__GetItemHeight_x                                  0x868790
#define CListWnd__GetItemIcon_x                                    0x867420
#define CListWnd__GetItemRect_x                                    0x868D80
#define CListWnd__GetItemText_x                                    0x8672D0
#define CListWnd__GetSelList_x                                     0x86BED0
#define CListWnd__GetSeparatorRect_x                               0x869570
#define CListWnd__RemoveLine_x                                     0x86BE80
#define CListWnd__SetColors_x                                      0x867060
#define CListWnd__SetColumnJustification_x                         0x867AE0
#define CListWnd__SetColumnWidth_x                                 0x8677C0
#define CListWnd__SetCurSel_x                                      0x867040
#define CListWnd__SetItemColor_x                                   0x86B340
#define CListWnd__SetItemData_x                                    0x867EA0
#define CListWnd__SetItemText_x                                    0x86B180
#define CListWnd__ShiftColumnSeparator_x                           0x86B010
#define CListWnd__Sort_x                                           0x86C960
#define CListWnd__ToggleSel_x                                      0x867D70

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6D33D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6F3210
#define CMerchantWnd__RequestBuyItem_x                             0x6F9630
#define CMerchantWnd__RequestSellItem_x                            0x720710
#define CMerchantWnd__SelectBuySellSlot_x                          0x6F34C0

// CObfuscator
#define CObfuscator__doit_x                                        0x7E6260

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x883E50
#define CSidlManager__CreateLabel_x                                0x7591C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x621EC0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x621DE0
#define CSidlScreenWnd__ConvertToRes_x                             0x89FE40
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8718B0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x872C60
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x872D10
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8721E0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x871390
#define CSidlScreenWnd__EnableIniStorage_x                         0x870AD0
#define CSidlScreenWnd__GetSidlPiece_x                             0x871580
#define CSidlScreenWnd__Init1_x                                    0x872930
#define CSidlScreenWnd__LoadIniInfo_x                              0x871960
#define CSidlScreenWnd__LoadIniListWnd_x                           0x870C90
#define CSidlScreenWnd__LoadSidlScreen_x                           0x872430
#define CSidlScreenWnd__StoreIniInfo_x                             0x870630
#define CSidlScreenWnd__StoreIniVis_x                              0x870A60
#define CSidlScreenWnd__WndNotification_x                          0x8726B0
#define CSidlScreenWnd__GetChildItem_x                             0x870BA0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5BDF20
#define CSkillMgr__GetSkillCap_x                                   0x5BDFA0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8A9E70
#define CSliderWnd__SetValue_x                                     0x8AA040
#define CSliderWnd__SetNumTicks_x                                  0x8AA7C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x760580

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x89A5C0
#define CStmlWnd__CalculateHSBRange_x                              0x892C00
#define CStmlWnd__CalculateVSBRange_x                              0x892C90
#define CStmlWnd__CanBreakAtCharacter_x                            0x892E10
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8936F0
#define CStmlWnd__ForceParseNow_x                                  0x89AF10
#define CStmlWnd__GetNextTagPiece_x                                0x8935F0
#define CStmlWnd__GetSTMLText_x                                    0x6585D0
#define CStmlWnd__GetVisibleText_x                                 0x894140
#define CStmlWnd__InitializeWindowVariables_x                      0x8963F0
#define CStmlWnd__MakeStmlColorTag_x                               0x891DE0
#define CStmlWnd__MakeWndNotificationTag_x                         0x891E40
#define CStmlWnd__SetSTMLText_x                                    0x897C60
#define CStmlWnd__StripFirstSTMLLines_x                            0x89A260
#define CStmlWnd__UpdateHistoryString_x                            0x895080

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8A1630
#define CTabWnd__DrawCurrentPage_x                                 0x8A0EA0
#define CTabWnd__DrawTab_x                                         0x8A0C60
#define CTabWnd__GetCurrentPage_x                                  0x8A1270
#define CTabWnd__GetPageInnerRect_x                                0x8A0950
#define CTabWnd__GetTabInnerRect_x                                 0x8A0B50
#define CTabWnd__GetTabRect_x                                      0x8A0A20
#define CTabWnd__InsertPage_x                                      0x8A1920
#define CTabWnd__SetPage_x                                         0x8A12A0
#define CTabWnd__SetPageRect_x                                     0x8A1570
#define CTabWnd__UpdatePage_x                                      0x8A18C0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41FA00

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x89DA00

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8A6830

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8651C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x411270
#define CXStr__CXStr1_x                                            0x795A60
#define CXStr__CXStr3_x                                            0x81C700
#define CXStr__dCXStr_x                                            0x4A53B0
#define CXStr__operator_equal_x                                    0x81C870
#define CXStr__operator_equal1_x                                   0x81C8C0
#define CXStr__operator_plus_equal1_x                              0x81D9A0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x876890
#define CXWnd__Center_x                                            0x87CAC0
#define CXWnd__ClrFocus_x                                          0x876460
#define CXWnd__DoAllDrawing_x                                      0x87C730
#define CXWnd__DrawChildren_x                                      0x87C8C0
#define CXWnd__DrawColoredRect_x                                   0x876C50
#define CXWnd__DrawTooltip_x                                       0x876F00
#define CXWnd__DrawTooltipAtPoint_x                                0x87B6A0
#define CXWnd__GetBorderFrame_x                                    0x877300
#define CXWnd__GetChildWndAt_x                                     0x87A640
#define CXWnd__GetClientClipRect_x                                 0x877110
#define CXWnd__GetScreenClipRect_x                                 0x87BDA0
#define CXWnd__GetScreenRect_x                                     0x8774B0
#define CXWnd__GetTooltipRect_x                                    0x876D90
#define CXWnd__GetWindowTextA_x                                    0x4112B0
#define CXWnd__IsActive_x                                          0x889D80
#define CXWnd__IsDescendantOf_x                                    0x877250
#define CXWnd__IsReallyVisible_x                                   0x87A620
#define CXWnd__IsType_x                                            0x8A3050
#define CXWnd__Move_x                                              0x879D20
#define CXWnd__Move1_x                                             0x87C3D0
#define CXWnd__ProcessTransition_x                                 0x876830
#define CXWnd__Refade_x                                            0x876610
#define CXWnd__Resize_x                                            0x877570
#define CXWnd__Right_x                                             0x87BBA0
#define CXWnd__SetFocus_x                                          0x878E80
#define CXWnd__SetFont_x                                           0x8764B0
#define CXWnd__SetKeyTooltip_x                                     0x8777E0
#define CXWnd__SetMouseOver_x                                      0x87C0C0
#define CXWnd__StartFade_x                                         0x8768E0
#define CXWnd__GetChildItem_x                                      0x87C000

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x88B6B0
#define CXWndManager__DrawWindows_x                                0x88B2F0
#define CXWndManager__GetKeyboardFlags_x                           0x8898F0
#define CXWndManager__HandleKeyboardMsg_x                          0x88A210
#define CXWndManager__RemoveWnd_x                                  0x889F10

// CDBStr
#define CDBStr__GetString_x                                        0x486930

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8D89F0
#define EQ_Character__CastSpell_x                                  0x43A980
#define EQ_Character__Cur_HP_x                                     0x449F80
#define EQ_Character__GetAACastingTimeModifier_x                   0x433820
#define EQ_Character__GetCharInfo2_x                               0x7F1170
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42CAC0
#define EQ_Character__GetFocusRangeModifier_x                      0x42CCA0
#define EQ_Character__Max_Endurance_x                              0x5850C0
#define EQ_Character__Max_HP_x                                     0x444120
#define EQ_Character__Max_Mana_x                                   0x584F00
#define EQ_Character__doCombatAbility_x                            0x583960
#define EQ_Character__UseSkill_x                                   0x45B440
#define EQ_Character__GetConLevel_x                                0x57ACB0
#define EQ_Character__IsExpansionFlag_x                            0x4107B0
#define EQ_Character__TotalEffect_x                                0x438AE0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x557F70
#define EQ_Item__CreateItemTagString_x                             0x7D1A20
#define EQ_Item__IsStackable_x                                     0x7C6130

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A5D40
#define EQ_LoadingS__Array_x                                       0xACF800

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5893D0
#define EQ_PC__GetAltAbilityIndex_x                                0x7DA300
#define EQ_PC__GetCombatAbility_x                                  0x7DA390
#define EQ_PC__GetCombatAbilityTimer_x                             0x7DA440
#define EQ_PC__GetItemTimerValue_x                                 0x5836A0
#define EQ_PC__HasLoreItem_x                                       0x57DE20

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4DDEC0
#define EQItemList__add_item_x                                     0x4DDE00
#define EQItemList__delete_item_x                                  0x4DE2C0
#define EQItemList__FreeItemList_x                                 0x4DE1C0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x485D00

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x58EF30
#define EQPlayer__dEQPlayer_x                                      0x593BA0
#define EQPlayer__DoAttack_x                                       0x5A81D0
#define EQPlayer__EQPlayer_x                                       0x599390
#define EQPlayer__SetNameSpriteState_x                             0x5913B0
#define EQPlayer__SetNameSpriteTint_x                              0x58EFA0
#define EQPlayer__IsBodyType_j_x                                   0x8D8290
#define EQPlayer__IsTargetable_x                                   0x8D8560

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x59C880
#define EQPlayerManager__GetSpawnByName_x                          0x59CCE0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x55E040
#define KeypressHandler__AttachKeyToEqCommand_x                    0x55E080
#define KeypressHandler__ClearCommandStateArray_x                  0x55DC20
#define KeypressHandler__HandleKeyDown_x                           0x55C580
#define KeypressHandler__HandleKeyUp_x                             0x55C8A0
#define KeypressHandler__SaveKeymapping_x                          0x55DCF0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6CB830
#define MapViewMap__SaveEx_x                                       0x6CF0E0

#define PlayerPointManager__GetAltCurrency_x                       0x7EB2B0

// StringTable 
#define StringTable__getString_x                                   0x7E6500

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x587CC0
