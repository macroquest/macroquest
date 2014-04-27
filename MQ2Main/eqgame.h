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
#define __ExpectedVersionDate                                     "Aug 19 2013"
#define __ExpectedVersionTime                                     "20:35:46"
#define __ActualVersionDate_x                                      0x9E57F0
#define __ActualVersionTime_x                                      0x9E57FC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5662C0
#define __MemChecker1_x                                            0x81E8E0
#define __MemChecker2_x                                            0x5FB580
#define __MemChecker3_x                                            0x5FB4D0
#define __MemChecker4_x                                            0x7A81F0
#define __EncryptPad0_x                                            0xAEDC58
#define __EncryptPad1_x                                            0xB6EE90
#define __EncryptPad2_x                                            0xB077A8
#define __EncryptPad3_x                                            0xB073A8
#define __EncryptPad4_x                                            0xB6B810
#define __AC1_x                                                    0x766045
#define __AC2_x                                                    0x51A707
#define __AC3_x                                                    0x52DB70
#define __AC4_x                                                    0x533BD4
#define __AC5_x                                                    0x53FD21
#define __AC6_x                                                    0x543652
#define __AC7_x                                                    0x539B9C
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
#define __do_loot_x                                                0x4E8BA0
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
#define __CastRay_x                                                0x4FE6C0
#define __ConvertItemTags_x                                        0x4EE5A0
#define __ExecuteCmd_x                                             0x4D8210
#define __EQGetTime_x                                              0x81F440
#define __get_melee_range_x                                        0x4DEE80
#define __GetGaugeValueFromEQ_x                                    0x764DA0
#define __GetLabelFromEQ_x                                         0x765FD0
#define __GetXTargetType_x                                         0x8DB1E0
#define __LoadFrontEnd_x                                           0x5FAC30
#define __NewUIINI_x                                               0x7646D0
#define __ProcessGameEvents_x                                      0x53BC80
#define CrashDetected_x                                            0x5FD2AB
#define DrawNetStatus_x                                            0x5754E0
#define Util__FastTime_x                                           0x81E780
#define Expansion_HoT_x                                            0xDEC5E8
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A3ED0
#define AltAdvManager__IsAbilityReady_x                            0x4A3F10
#define AltAdvManager__GetAltAbility_x                             0x4A42F0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x44A590

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x629A10

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x637980

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x551AA0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x6525D0
#define CChatManager__InitContextMenu_x                            0x6530F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x805570
#define CChatService__GetFriendName_x                              0x805580

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x657E30
#define CChatWindow__Clear_x                                       0x6579E0
#define CChatWindow__WndNotification_x                             0x658360

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x87D790
#define CComboWnd__Draw_x                                          0x87D970
#define CComboWnd__GetCurChoice_x                                  0x87D5B0
#define CComboWnd__GetListRect_x                                   0x87DC10
#define CComboWnd__GetTextRect_x                                   0x87D7F0
#define CComboWnd__InsertChoice_x                                  0x87DC80
#define CComboWnd__SetColors_x                                     0x87D540
#define CComboWnd__SetChoice_x                                     0x87D570

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x661530
#define CContainerWnd__vftable_x                                   0x9EED20

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x493C00
#define CDisplay__GetClickedActor_x                                0x48BBC0
#define CDisplay__GetUserDefinedColor_x                            0x48A480
#define CDisplay__GetWorldFilePath_x                               0x489880
#define CDisplay__is3dON_x                                         0x488950
#define CDisplay__ReloadUI_x                                       0x49DBD0
#define CDisplay__WriteTextHD2_x                                   0x48F050

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x89F0B0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x88DFF0
#define CEditWnd__GetCharIndexPt_x                                 0x88F020
#define CEditWnd__GetDisplayString_x                               0x88E1A0
#define CEditWnd__GetHorzOffset_x                                  0x88E4E0
#define CEditWnd__GetLineForPrintableChar_x                        0x88EAE0
#define CEditWnd__GetSelStartPt_x                                  0x88F2E0
#define CEditWnd__GetSTMLSafeText_x                                0x88E680
#define CEditWnd__PointFromPrintableChar_x                         0x88EBD0
#define CEditWnd__SelectableCharFromPoint_x                        0x88ED50
#define CEditWnd__SetEditable_x                                    0x88E650

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x51AE50
#define CEverQuest__DoTellWindow_x                                 0x51F7B0
#define CEverQuest__DropHeldItemOnGround_x                         0x528070
#define CEverQuest__dsp_chat_x                                     0x520F50
#define CEverQuest__Emote_x                                        0x5211B0
#define CEverQuest__EnterZone_x                                    0x533D60
#define CEverQuest__GetBodyTypeDesc_x                              0x517410
#define CEverQuest__GetClassDesc_x                                 0x516B70
#define CEverQuest__GetClassThreeLetterCode_x                      0x517170
#define CEverQuest__GetDeityDesc_x                                 0x517D20
#define CEverQuest__GetLangDesc_x                                  0x5177A0
#define CEverQuest__GetRaceDesc_x                                  0x517A90
#define CEverQuest__InterpretCmd_x                                 0x521A90
#define CEverQuest__LeftClickedOnPlayer_x                          0x5380E0
#define CEverQuest__LMouseUp_x                                     0x53A2F0
#define CEverQuest__RightClickedOnPlayer_x                         0x538BA0
#define CEverQuest__RMouseUp_x                                     0x539B50
#define CEverQuest__SetGameState_x                                 0x51B500
#define CEverQuest__UPCNotificationFlush_x                         0x522A20

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6715E0
#define CGaugeWnd__CalcLinesFillRect_x                             0x671640
#define CGaugeWnd__Draw_x                                          0x671A70

// CGuild
#define CGuild__FindMemberByName_x                                 0x423F80

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x68E730

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x699CE0
#define CInvSlotMgr__MoveItem_x                                    0x69AC10

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6990E0
#define CInvSlot__SliderComplete_x                                 0x697100
#define CInvSlot__GetItemBase_x                                    0x696610

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x69B970

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x761A10
#define CItemDisplayWnd__UpdateStrings_x                           0x69CCB0

// CLabel 
#define CLabel__Draw_x                                             0x6B73B0

// CListWnd 
#define CListWnd__AddColumn_x                                      0x86B820
#define CListWnd__AddColumn1_x                                     0x86B000
#define CListWnd__AddLine_x                                        0x86AAB0
#define CListWnd__AddString_x                                      0x86ACC0
#define CListWnd__CalculateFirstVisibleLine_x                      0x867B60
#define CListWnd__CalculateVSBRange_x                              0x869CA0
#define CListWnd__ClearAllSel_x                                    0x866E10
#define CListWnd__CloseAndUpdateEditWindow_x                       0x86A680
#define CListWnd__Compare_x                                        0x868670
#define CListWnd__Draw_x                                           0x869900
#define CListWnd__DrawColumnSeparators_x                           0x869790
#define CListWnd__DrawHeader_x                                     0x867120
#define CListWnd__DrawItem_x                                       0x868CC0
#define CListWnd__DrawLine_x                                       0x867120
#define CListWnd__DrawSeparator_x                                  0x869830
#define CListWnd__EnsureVisible_x                                  0x867CC0
#define CListWnd__ExtendSel_x                                      0x868BD0
#define CListWnd__GetColumnMinWidth_x                              0x866830
#define CListWnd__GetColumnWidth_x                                 0x866750
#define CListWnd__GetCurSel_x                                      0x866010
#define CListWnd__GetItemAtPoint_x                                 0x867F60
#define CListWnd__GetItemAtPoint1_x                                0x867FD0
#define CListWnd__GetItemData_x                                    0x866260
#define CListWnd__GetItemHeight_x                                  0x8677B0
#define CListWnd__GetItemIcon_x                                    0x866440
#define CListWnd__GetItemRect_x                                    0x867DA0
#define CListWnd__GetItemText_x                                    0x8662F0
#define CListWnd__GetSelList_x                                     0x86AEF0
#define CListWnd__GetSeparatorRect_x                               0x868590
#define CListWnd__RemoveLine_x                                     0x86AEA0
#define CListWnd__SetColors_x                                      0x866070
#define CListWnd__SetColumnJustification_x                         0x866B00
#define CListWnd__SetColumnWidth_x                                 0x8667E0
#define CListWnd__SetCurSel_x                                      0x866050
#define CListWnd__SetItemColor_x                                   0x86A360
#define CListWnd__SetItemData_x                                    0x866EC0
#define CListWnd__SetItemText_x                                    0x86A1A0
#define CListWnd__ShiftColumnSeparator_x                           0x86A030
#define CListWnd__Sort_x                                           0x86B980
#define CListWnd__ToggleSel_x                                      0x866D90

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6D2190

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6F2040
#define CMerchantWnd__RequestBuyItem_x                             0x6F84D0
#define CMerchantWnd__RequestSellItem_x                            0x71F630
#define CMerchantWnd__SelectBuySellSlot_x                          0x6F22F0

// CObfuscator
#define CObfuscator__doit_x                                        0x7E5220

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x882EC0
#define CSidlManager__CreateLabel_x                                0x758080

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x620BD0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x620AF0
#define CSidlScreenWnd__ConvertToRes_x                             0x89EF90
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x870910
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x871CC0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x871D70
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x871240
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8703F0
#define CSidlScreenWnd__EnableIniStorage_x                         0x86FB20
#define CSidlScreenWnd__GetSidlPiece_x                             0x8705E0
#define CSidlScreenWnd__Init1_x                                    0x871990
#define CSidlScreenWnd__LoadIniInfo_x                              0x8709C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x86FCE0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x871490
#define CSidlScreenWnd__StoreIniInfo_x                             0x86F680
#define CSidlScreenWnd__StoreIniVis_x                              0x86FAB0
#define CSidlScreenWnd__WndNotification_x                          0x871710
#define CSidlScreenWnd__GetChildItem_x                             0x86FBF0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5BCE00
#define CSkillMgr__GetSkillCap_x                                   0x5BCE80

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8A8F30
#define CSliderWnd__SetValue_x                                     0x8A9100
#define CSliderWnd__SetNumTicks_x                                  0x8A9880

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x75F460

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8996D0
#define CStmlWnd__CalculateHSBRange_x                              0x891D00
#define CStmlWnd__CalculateVSBRange_x                              0x891D90
#define CStmlWnd__CanBreakAtCharacter_x                            0x891F10
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8927F0
#define CStmlWnd__ForceParseNow_x                                  0x89A020
#define CStmlWnd__GetNextTagPiece_x                                0x8926F0
#define CStmlWnd__GetSTMLText_x                                    0x657280
#define CStmlWnd__GetVisibleText_x                                 0x893240
#define CStmlWnd__InitializeWindowVariables_x                      0x8954F0
#define CStmlWnd__MakeStmlColorTag_x                               0x890EE0
#define CStmlWnd__MakeWndNotificationTag_x                         0x890F40
#define CStmlWnd__SetSTMLText_x                                    0x896D60
#define CStmlWnd__StripFirstSTMLLines_x                            0x899370
#define CStmlWnd__UpdateHistoryString_x                            0x894180

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8A0790
#define CTabWnd__DrawCurrentPage_x                                 0x8A0000
#define CTabWnd__DrawTab_x                                         0x89FDC0
#define CTabWnd__GetCurrentPage_x                                  0x8A03D0
#define CTabWnd__GetPageInnerRect_x                                0x89FAB0
#define CTabWnd__GetTabInnerRect_x                                 0x89FCB0
#define CTabWnd__GetTabRect_x                                      0x89FB80
#define CTabWnd__InsertPage_x                                      0x8A0A80
#define CTabWnd__SetPage_x                                         0x8A0400
#define CTabWnd__SetPageRect_x                                     0x8A06D0
#define CTabWnd__UpdatePage_x                                      0x8A0A20

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41FB30

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x89CB70

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8A58F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x864170

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x411320
#define CXStr__CXStr1_x                                            0x7A0DD0
#define CXStr__CXStr3_x                                            0x81B800
#define CXStr__dCXStr_x                                            0x794990
#define CXStr__operator_equal_x                                    0x81B970
#define CXStr__operator_equal1_x                                   0x81B9C0
#define CXStr__operator_plus_equal1_x                              0x81CAB0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x875980
#define CXWnd__Center_x                                            0x87BBA0
#define CXWnd__ClrFocus_x                                          0x875550
#define CXWnd__DoAllDrawing_x                                      0x87B800
#define CXWnd__DrawChildren_x                                      0x87B990
#define CXWnd__DrawColoredRect_x                                   0x875D10
#define CXWnd__DrawTooltip_x                                       0x875FC0
#define CXWnd__DrawTooltipAtPoint_x                                0x87A780
#define CXWnd__GetBorderFrame_x                                    0x8763D0
#define CXWnd__GetChildWndAt_x                                     0x879720
#define CXWnd__GetClientClipRect_x                                 0x8761D0
#define CXWnd__GetScreenClipRect_x                                 0x87AE80
#define CXWnd__GetScreenRect_x                                     0x8765A0
#define CXWnd__GetTooltipRect_x                                    0x875E50
#define CXWnd__GetWindowTextA_x                                    0x411360
#define CXWnd__IsActive_x                                          0x888E70
#define CXWnd__IsDescendantOf_x                                    0x876310
#define CXWnd__IsReallyVisible_x                                   0x879700
#define CXWnd__IsType_x                                            0x8A2170
#define CXWnd__Move_x                                              0x878DD0
#define CXWnd__Move1_x                                             0x87B4A0
#define CXWnd__ProcessTransition_x                                 0x875930
#define CXWnd__Refade_x                                            0x875700
#define CXWnd__Resize_x                                            0x876670
#define CXWnd__Right_x                                             0x87AC80
#define CXWnd__SetFocus_x                                          0x877F20
#define CXWnd__SetFont_x                                           0x8755A0
#define CXWnd__SetKeyTooltip_x                                     0x8768E0
#define CXWnd__SetMouseOver_x                                      0x87B190
#define CXWnd__StartFade_x                                         0x8759D0
#define CXWnd__GetChildItem_x                                      0x87B0D0

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x88A7B0
#define CXWndManager__DrawWindows_x                                0x88A3F0
#define CXWndManager__GetKeyboardFlags_x                           0x8889A0
#define CXWndManager__HandleKeyboardMsg_x                          0x889310
#define CXWndManager__RemoveWnd_x                                  0x889000

// CDBStr
#define CDBStr__GetString_x                                        0x486B20

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8D7B90
#define EQ_Character__CastSpell_x                                  0x43AC00
#define EQ_Character__Cur_HP_x                                     0x44A1E0
#define EQ_Character__GetAACastingTimeModifier_x                   0x433AA0
#define EQ_Character__GetCharInfo2_x                               0x7F01A0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42CD00
#define EQ_Character__GetFocusRangeModifier_x                      0x42CEE0
#define EQ_Character__Max_Endurance_x                              0x583D40
#define EQ_Character__Max_HP_x                                     0x444380
#define EQ_Character__Max_Mana_x                                   0x583B80
#define EQ_Character__doCombatAbility_x                            0x5825E0
#define EQ_Character__UseSkill_x                                   0x45B6B0
#define EQ_Character__GetConLevel_x                                0x579AE0
#define EQ_Character__IsExpansionFlag_x                            0x410860
#define EQ_Character__TotalEffect_x                                0x438D60

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x556D10
#define EQ_Item__CreateItemTagString_x                             0x7D0AC0
#define EQ_Item__IsStackable_x                                     0x7C51A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A5F50
#define EQ_LoadingS__Array_x                                       0xACF800

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x588070
#define EQ_PC__GetAltAbilityIndex_x                                0x7D9290
#define EQ_PC__GetCombatAbility_x                                  0x7D9320
#define EQ_PC__GetCombatAbilityTimer_x                             0x7D93D0
#define EQ_PC__GetItemTimerValue_x                                 0x582320
#define EQ_PC__HasLoreItem_x                                       0x57CC60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4DCBB0
#define EQItemList__add_item_x                                     0x4DCAF0
#define EQItemList__delete_item_x                                  0x4DCFB0
#define EQItemList__FreeItemList_x                                 0x4DCEB0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x486030

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x58DBD0
#define EQPlayer__dEQPlayer_x                                      0x592840
#define EQPlayer__DoAttack_x                                       0x5A6F30
#define EQPlayer__EQPlayer_x                                       0x598030
#define EQPlayer__SetNameSpriteState_x                             0x590050
#define EQPlayer__SetNameSpriteTint_x                              0x58DC40
#define EQPlayer__IsBodyType_j_x                                   0x8D7430
#define EQPlayer__IsTargetable_x                                   0x8D7700

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x59B530
#define EQPlayerManager__GetSpawnByName_x                          0x59B990

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x55CED0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x55CF10
#define KeypressHandler__ClearCommandStateArray_x                  0x55CAB0
#define KeypressHandler__HandleKeyDown_x                           0x55B410
#define KeypressHandler__HandleKeyUp_x                             0x55B730
#define KeypressHandler__SaveKeymapping_x                          0x55CB80

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6CA5F0
#define MapViewMap__SaveEx_x                                       0x6CDEA0

#define PlayerPointManager__GetAltCurrency_x                       0x7EA2D0

// StringTable 
#define StringTable__getString_x                                   0x7E54C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x586960
