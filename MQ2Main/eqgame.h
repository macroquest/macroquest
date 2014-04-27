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
#define __ExpectedVersionDate                                     "Feb 13 2013"
#define __ExpectedVersionTime                                     "16:00:39"
#define __ActualVersionDate_x                                      0x9D4BB0
#define __ActualVersionTime_x                                      0x9D4BBC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5622B0
#define __MemChecker1_x                                            0x804E30
#define __MemChecker2_x                                            0x5F7260
#define __MemChecker3_x                                            0x5F71B0
#define __MemChecker4_x                                            0x8C7B80
#define __EncryptPad0_x                                            0xADA2F0
#define __EncryptPad1_x                                            0xB55298
#define __EncryptPad2_x                                            0xAF3250
#define __EncryptPad3_x                                            0xAF2E50
#define __EncryptPad4_x                                            0xB5AA48
#define __AC1_x                                                    0x75FB65
#define __AC2_x                                                    0x516C37
#define __AC3_x                                                    0x52A070
#define __AC4_x                                                    0x5300E4
#define __AC5_x                                                    0x53BFFB
#define __AC6_x                                                    0x53F932
#define __AC7_x                                                    0x535F1C
#define __AC1_Data                                                 0x33333333
// Direct Input
#define DI8__Main_x                                                0xDEE230
#define DI8__Keyboard_x                                            0xDEE234
#define DI8__Mouse_x                                               0xDEE238
#define __AltTimerReady_x                                          0xD57461
#define __Attack_x                                                 0xDE9FDE
#define __Autofire_x                                               0xDE9FDF
#define __BindList_x                                               0xAC25C8
#define __Clicks_x                                                 0xD66174
#define __CommandList_x                                            0xAC3C14
#define __CurrentMapLabel_x                                        0xEF9F10
#define __CurrentSocial_x                                          0xAAD688
#define __DoAbilityList_x                                          0xD9C884
#define __do_loot_x                                                0x4E5C60
#define __DrawHandler_x                                            0x155A33C
#define __GroupCount_x                                             0xD56B3A

#define __Guilds_x                                                 0xD5C740
#define __gWorld_x                                                 0xD58FF4
#define __HotkeyPage_x                                             0xDE3284
#define __HWnd_x                                                   0xDEDF88
#define __InChatMode_x                                             0xD660AC
#define __LastTell_x                                               0xD67F8C
#define __LMouseHeldTime_x                                         0xD661E0
#define __Mouse_x                                                  0xDEE23C
#define __MouseLook_x                                              0xD66142
#define __MouseEventTime_x                                         0xDEA32C
#define __NetStatusToggle_x                                        0xD66145
#define __PCNames_x                                                0xD67600
#define __RangeAttackReady_x                                       0xD6729C
#define __RMouseHeldTime_x                                         0xD661DC
#define __RunWalkState_x                                           0xD660B0
#define __ScreenMode_x                                             0xCA5F18
#define __ScreenX_x                                                0xD66064
#define __ScreenY_x                                                0xD66060
#define __ScreenXMax_x                                             0xD66068
#define __ScreenYMax_x                                             0xD6606C
#define __ServerHost_x                                             0xD56A84
#define __ServerName_x                                             0xD9C844
#define __ShiftKeyDown_x                                           0xD66738
#define __ShowNames_x                                              0xD674A8
#define __Socials_x                                                0xD9C944


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xD590D8
#define instEQZoneInfo_x                                           0xD66330
#define instKeypressHandler_x                                      0xDEA310
#define pinstActiveBanker_x                                        0xD59098
#define pinstActiveCorpse_x                                        0xD5909C
#define pinstActiveGMaster_x                                       0xD590A0
#define pinstActiveMerchant_x                                      0xD59094
#define pinstAggroInfo_x                                           0xB6C920
#define pinstAltAdvManager_x                                       0xCA6E80
#define pinstAuraMgr_x                                             0xB76108
#define pinstBandageTarget_x                                       0xD59080
#define pinstCamActor_x                                            0xCA68EC
#define pinstCDBStr_x                                              0xCA5EF0
#define pinstCDisplay_x                                            0xD590A8
#define pinstCEverQuest_x                                          0xDEE3B4
#define pinstCharData_x                                            0xD59064
#define pinstCharSpawn_x                                           0xD5908C
#define pinstControlledMissile_x                                   0xD59060
#define pinstControlledPlayer_x                                    0xD5908C
#define pinstCSidlManager_x                                        0x15599A0
#define pinstCXWndManager_x                                        0x1559998
#define instDynamicZone_x                                          0xD65F18
#define pinstDZMember_x                                            0xD66028
#define pinstDZTimerInfo_x                                         0xD6602C
#define pinstEQItemList_x                                          0xD55BE0
#define instEQMisc_x                                               0xAB6630
#define pinstEQSoundManager_x                                      0xCA6F48
#define instExpeditionLeader_x                                     0xD65F62
#define instExpeditionName_x                                       0xD65FA2
#define pinstGroup_x                                               0xD56B36
#define pinstImeManager_x                                          0x15599A4
#define pinstLocalPlayer_x                                         0xD59078
#define pinstMercenaryData_x                                       0xDEA788
#define pinstModelPlayer_x                                         0xD590A4
#define pinstPCData_x                                              0xD59064
#define pinstSkillMgr_x                                            0xDEADC8
#define pinstSpawnManager_x                                        0xDEAA28
#define pinstSpellManager_x                                        0xDEAE40
#define pinstSpellSets_x                                           0xDE32E8
#define pinstStringTable_x                                         0xD5900C
#define pinstSwitchManager_x                                       0xD56750
#define pinstTarget_x                                              0xD59090
#define pinstTargetObject_x                                        0xD59068
#define pinstTargetSwitch_x                                        0xD5906C
#define pinstTaskMember_x                                          0xCA5EA0
#define pinstTrackTarget_x                                         0xD59084
#define pinstTradeTarget_x                                         0xD59074
#define instTributeActive_x                                        0xAB6655
#define pinstViewActor_x                                           0xCA68E8
#define pinstWorldData_x                                           0xD59048


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xB6CB08
#define pinstCAudioTriggersWindow_x                                0xB6CA70
#define pinstCCharacterSelect_x                                    0xCA6794
#define pinstCFacePick_x                                           0xCA6544
#define pinstCNoteWnd_x                                            0xCA674C
#define pinstCBookWnd_x                                            0xCA6754
#define pinstCPetInfoWnd_x                                         0xCA6758
#define pinstCTrainWnd_x                                           0xCA675C
#define pinstCSkillsWnd_x                                          0xCA6760
#define pinstCSkillsSelectWnd_x                                    0xCA6764
#define pinstCCombatSkillSelectWnd_x                               0xCA6768
#define pinstCFriendsWnd_x                                         0xCA676C
#define pinstCAuraWnd_x                                            0xCA6770
#define pinstCRespawnWnd_x                                         0xCA6774
#define pinstCBandolierWnd_x                                       0xCA6778
#define pinstCPotionBeltWnd_x                                      0xCA677C
#define pinstCAAWnd_x                                              0xCA6780
#define pinstCGroupSearchFiltersWnd_x                              0xCA6784
#define pinstCLoadskinWnd_x                                        0xCA6788
#define pinstCAlarmWnd_x                                           0xCA678C
#define pinstCMusicPlayerWnd_x                                     0xCA6790
#define pinstCMailWnd_x                                            0xCA6798
#define pinstCMailCompositionWnd_x                                 0xCA679C
#define pinstCMailAddressBookWnd_x                                 0xCA67A0
#define pinstCRaidWnd_x                                            0xCA67A8
#define pinstCRaidOptionsWnd_x                                     0xCA67AC
#define pinstCBreathWnd_x                                          0xCA67B0
#define pinstCMapViewWnd_x                                         0xCA67B4
#define pinstCMapToolbarWnd_x                                      0xCA67B8
#define pinstCEditLabelWnd_x                                       0xCA67BC
#define pinstCTargetWnd_x                                          0xCA67C0
#define pinstCColorPickerWnd_x                                     0xCA67C4
#define pinstCPlayerWnd_x                                          0xCA67C8
#define pinstCOptionsWnd_x                                         0xCA67CC
#define pinstCBuffWindowNORMAL_x                                   0xCA67D0
#define pinstCBuffWindowSHORT_x                                    0xCA67D4
#define pinstCharacterCreation_x                                   0xCA67D8
#define pinstCCursorAttachment_x                                   0xCA67DC
#define pinstCCastingWnd_x                                         0xCA67E0
#define pinstCCastSpellWnd_x                                       0xCA67E4
#define pinstCSpellBookWnd_x                                       0xCA67E8
#define pinstCInventoryWnd_x                                       0xCA67EC
#define pinstCBankWnd_x                                            0xCA67F0
#define pinstCQuantityWnd_x                                        0xCA67F4
#define pinstCLootWnd_x                                            0xCA67F8
#define pinstCActionsWnd_x                                         0xCA67FC
#define pinstCCombatAbilityWnd_x                                   0xCA6800
#define pinstCMerchantWnd_x                                        0xCA6804
#define pinstCTradeWnd_x                                           0xCA6808
#define pinstCSelectorWnd_x                                        0xCA680C
#define pinstCBazaarWnd_x                                          0xCA6810
#define pinstCBazaarSearchWnd_x                                    0xCA6814
#define pinstCGiveWnd_x                                            0xCA6830
#define pinstCTrackingWnd_x                                        0xCA6838
#define pinstCInspectWnd_x                                         0xCA683C
#define pinstCSocialEditWnd_x                                      0xCA6840
#define pinstCFeedbackWnd_x                                        0xCA6844
#define pinstCBugReportWnd_x                                       0xCA6848
#define pinstCVideoModesWnd_x                                      0xCA684C
#define pinstCTextEntryWnd_x                                       0xCA6854
#define pinstCFileSelectionWnd_x                                   0xCA6858
#define pinstCCompassWnd_x                                         0xCA685C
#define pinstCPlayerNotesWnd_x                                     0xCA6860
#define pinstCGemsGameWnd_x                                        0xCA6864
#define pinstCTimeLeftWnd_x                                        0xCA6868
#define pinstCPetitionQWnd_x                                       0xCA687C
#define pinstCSoulmarkWnd_x                                        0xCA6880
#define pinstCStoryWnd_x                                           0xCA6884
#define pinstCJournalTextWnd_x                                     0xCA6888
#define pinstCJournalCatWnd_x                                      0xCA688C
#define pinstCBodyTintWnd_x                                        0xCA6890
#define pinstCServerListWnd_x                                      0xCA6894
#define pinstCAvaZoneWnd_x                                         0xCA68A0
#define pinstCBlockedBuffWnd_x                                     0xCA68A4
#define pinstCBlockedPetBuffWnd_x                                  0xCA68A8
#define pinstCInvSlotMgr_x                                         0xCA68E0
#define pinstCContainerMgr_x                                       0xCA68E4
#define pinstCAdventureLeaderboardWnd_x                            0xEF6B68
#define pinstCAdventureRequestWnd_x                                0xEF6B50
#define pinstCAltStorageWnd_x                                      0xEF6CA8
#define pinstCAdventureStatsWnd_x                                  0xEF6B68
#define pinstCBarterMerchantWnd_x                                  0xEF70E8
#define pinstCBarterSearchWnd_x                                    0xEF7100
#define pinstCBarterWnd_x                                          0xEF7138
#define pinstCChatManager_x                                        0xEF7410
#define pinstCDynamicZoneWnd_x                                     0xEF7600
#define pinstCEQMainWnd_x                                          0xEF76C0
#define pinstCFellowshipWnd_x                                      0xEF75DC
#define pinstCFindLocationWnd_x                                    0xEF77F0
#define pinstCGroupSearchWnd_x                                     0xEF7950
#define pinstCGroupWnd_x                                           0xEF7988
#define pinstCGuildBankWnd_x                                       0xEF79A0
#define pinstCGuildMgmtWnd_x                                       0xEF9A30
#define pinstCGuildTributeMasterWnd_x                              0xEFB850
#define pinstCHotButtonWnd_x                                       0xEF9A84
#define pinstCHotButtonWnd1_x                                      0xEF9A84
#define pinstCHotButtonWnd2_x                                      0xEF9A88
#define pinstCHotButtonWnd3_x                                      0xEF9A8C
#define pinstCHotButtonWnd4_x                                      0xEF9AB0
#define pinstCItemDisplayManager_x                                 0xEF9C00
#define pinstCItemExpTransferWnd_x                                 0xEF9C3C
#define pinstCLeadershipWnd_x                                      0xEF9D80
#define pinstCLFGuildWnd_x                                         0xEF9DA0
#define pinstCMIZoneSelectWnd_x                                    0xEFA040
#define pinstCAdventureMerchantWnd_x                               0xEFA308
#define pinstCConfirmationDialog_x                                 0xEFA328
#define pinstCPopupWndManager_x                                    0xEFA328
#define pinstCProgressionSelectionWnd_x                            0xEFA390
#define pinstCPvPLeaderboardWnd_x                                  0xEFA3E0
#define pinstCPvPStatsWnd_x                                        0xEFA400
#define pinstCSystemInfoDialogBox_x                                0xEFA6E8
#define pinstCTargetOfTargetWnd_x                                  0xEFB4CC
#define pinstCTaskSelectWnd_x                                      0xEFA5A4
#define pinstCTaskTemplateSelectWnd_x                              0xEFB588
#define pinstCTaskWnd_x                                            0xEFB5D8
#define pinstCTipWndOFDAY_x                                        0xEFB6B8
#define pinstCTipWndCONTEXT_x                                      0xEFB6BC
#define pinstCTitleWnd_x                                           0xEFB6F0
#define pinstCTradeskillWnd_x                                      0xEFB74C
#define pinstCTributeBenefitWnd_x                                  0xEFB818
#define pinstCTributeMasterWnd_x                                   0xEFB850
#define pinstCContextMenuManager_x                                 0x15595B4
#define pinstCVoiceMacroWnd_x                                      0xDEB188
#define pinstCHtmlWnd_x                                            0xDEB200


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x4FB570
#define __ConvertItemTags_x                                        0x4EB4E0
#define __ExecuteCmd_x                                             0x4D5900
#define __EQGetTime_x                                              0x805990
#define __get_melee_range_x                                        0x4DC530
#define __GetGaugeValueFromEQ_x                                    0x75E8C0
#define __GetLabelFromEQ_x                                         0x75FAF0
#define __GetXTargetType_x                                         0x8CF800
#define __LoadFrontEnd_x                                           0x5F6910
#define __NewUIINI_x                                               0x75E1F0
#define __ProcessGameEvents_x                                      0x538000
#define CrashDetected_x                                            0x5F8F8B
#define DrawNetStatus_x                                            0x5714E0
#define Util__FastTime_x                                           0x804CD0
#define Expansion_HoT_x                                            0xD67408
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A1FF0
#define AltAdvManager__IsAbilityReady_x                            0x4A2030
#define AltAdvManager__GetAltAbility_x                             0x4A2400

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x44A130

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6256F0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6338D0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x54DC70

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x64DE60
#define CChatManager__InitContextMenu_x                            0x64E950

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x7EBA40
#define CChatService__GetFriendName_x                              0x7EBA50

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x653670
#define CChatWindow__Clear_x                                       0x653230
#define CChatWindow__WndNotification_x                             0x653BB0

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x866740
#define CComboWnd__Draw_x                                          0x866920
#define CComboWnd__GetCurChoice_x                                  0x866560
#define CComboWnd__GetListRect_x                                   0x866BC0
#define CComboWnd__GetTextRect_x                                   0x8667A0
#define CComboWnd__InsertChoice_x                                  0x866C30
#define CComboWnd__SetColors_x                                     0x8664F0
#define CComboWnd__SetChoice_x                                     0x866520

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x65CC50
#define CContainerWnd__vftable_x                                   0x9DDC68

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x492020
#define CDisplay__GetClickedActor_x                                0x48A140
#define CDisplay__GetUserDefinedColor_x                            0x488A10
#define CDisplay__GetWorldFilePath_x                               0x487E10
#define CDisplay__is3dON_x                                         0x486EF0
#define CDisplay__ReloadUI_x                                       0x49BFF0
#define CDisplay__WriteTextHD2_x                                   0x48D550

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x887F00

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x877070
#define CEditWnd__GetCharIndexPt_x                                 0x8780A0
#define CEditWnd__GetDisplayString_x                               0x877220
#define CEditWnd__GetHorzOffset_x                                  0x877560
#define CEditWnd__GetLineForPrintableChar_x                        0x877B60
#define CEditWnd__GetSelStartPt_x                                  0x878360
#define CEditWnd__GetSTMLSafeText_x                                0x877700
#define CEditWnd__PointFromPrintableChar_x                         0x877C50
#define CEditWnd__SelectableCharFromPoint_x                        0x877DD0
#define CEditWnd__SetEditable_x                                    0x8776D0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x517380
#define CEverQuest__DoTellWindow_x                                 0x51BCE0
#define CEverQuest__DropHeldItemOnGround_x                         0x524570
#define CEverQuest__dsp_chat_x                                     0x51D480
#define CEverQuest__Emote_x                                        0x51D6E0
#define CEverQuest__EnterZone_x                                    0x530270
#define CEverQuest__GetBodyTypeDesc_x                              0x513940
#define CEverQuest__GetClassDesc_x                                 0x5130A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5136A0
#define CEverQuest__GetDeityDesc_x                                 0x514250
#define CEverQuest__GetLangDesc_x                                  0x513CD0
#define CEverQuest__GetRaceDesc_x                                  0x513FC0
#define CEverQuest__InterpretCmd_x                                 0x51DFC0
#define CEverQuest__LeftClickedOnPlayer_x                          0x5344B0
#define CEverQuest__LMouseUp_x                                     0x536670
#define CEverQuest__RightClickedOnPlayer_x                         0x534F20
#define CEverQuest__RMouseUp_x                                     0x535ED0
#define CEverQuest__SetGameState_x                                 0x517A30
#define CEverQuest__UPCNotificationFlush_x                         0x51EF50

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x66C890
#define CGaugeWnd__CalcLinesFillRect_x                             0x66C8F0
#define CGaugeWnd__Draw_x                                          0x66CD20

// CGuild
#define CGuild__FindMemberByName_x                                 0x423D30

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6899C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x694DA0
#define CInvSlotMgr__MoveItem_x                                    0x695CD0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x694200
#define CInvSlot__SliderComplete_x                                 0x692380
#define CInvSlot__GetItemBase_x                                    0x691890

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6969E0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x75B5B0
#define CItemDisplayWnd__UpdateStrings_x                           0x697D00

// CLabel 
#define CLabel__Draw_x                                             0x6B1B80

// CListWnd 
#define CListWnd__AddColumn_x                                      0x854A60
#define CListWnd__AddColumn1_x                                     0x854240
#define CListWnd__AddLine_x                                        0x853CF0
#define CListWnd__AddString_x                                      0x853F00
#define CListWnd__CalculateFirstVisibleLine_x                      0x850DC0
#define CListWnd__CalculateVSBRange_x                              0x852EF0
#define CListWnd__ClearAllSel_x                                    0x850070
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8538C0
#define CListWnd__Compare_x                                        0x8518C0
#define CListWnd__Draw_x                                           0x852B50
#define CListWnd__DrawColumnSeparators_x                           0x8529E0
#define CListWnd__DrawHeader_x                                     0x850380
#define CListWnd__DrawItem_x                                       0x851F10
#define CListWnd__DrawLine_x                                       0x852680
#define CListWnd__DrawSeparator_x                                  0x852A80
#define CListWnd__EnsureVisible_x                                  0x850F20
#define CListWnd__ExtendSel_x                                      0x851E20
#define CListWnd__GetColumnMinWidth_x                              0x84FA90
#define CListWnd__GetColumnWidth_x                                 0x84F9B0
#define CListWnd__GetCurSel_x                                      0x84F290
#define CListWnd__GetItemAtPoint_x                                 0x8511C0
#define CListWnd__GetItemAtPoint1_x                                0x851230
#define CListWnd__GetItemData_x                                    0x84F4C0
#define CListWnd__GetItemHeight_x                                  0x850A10
#define CListWnd__GetItemIcon_x                                    0x84F6A0
#define CListWnd__GetItemRect_x                                    0x851000
#define CListWnd__GetItemText_x                                    0x84F550
#define CListWnd__GetSelList_x                                     0x854130
#define CListWnd__GetSeparatorRect_x                               0x8517E0
#define CListWnd__RemoveLine_x                                     0x8540E0
#define CListWnd__SetColors_x                                      0x84F2F0
#define CListWnd__SetColumnJustification_x                         0x84FD60
#define CListWnd__SetColumnWidth_x                                 0x84FA40
#define CListWnd__SetCurSel_x                                      0x84F2D0
#define CListWnd__SetItemColor_x                                   0x8535A0
#define CListWnd__SetItemData_x                                    0x850120
#define CListWnd__SetItemText_x                                    0x8533E0
#define CListWnd__ShiftColumnSeparator_x                           0x853270
#define CListWnd__Sort_x                                           0x854BC0
#define CListWnd__ToggleSel_x                                      0x84FFF0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6CC9D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6EC3B0
#define CMerchantWnd__RequestBuyItem_x                             0x6F26D0
#define CMerchantWnd__RequestSellItem_x                            0x7194C0
#define CMerchantWnd__SelectBuySellSlot_x                          0x6EC660

// CObfuscator
#define CObfuscator__doit_x                                        0x7CC310

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x86BDD0
#define CSidlManager__CreateLabel_x                                0x751E20

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x61C8A0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x61C7D0
#define CSidlScreenWnd__ConvertToRes_x                             0x887DE0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x859AD0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x85ADF0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x85AEA0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x85A390
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8595B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x858D00
#define CSidlScreenWnd__GetSidlPiece_x                             0x8597A0
#define CSidlScreenWnd__Init1_x                                    0x85AAC0
#define CSidlScreenWnd__LoadIniInfo_x                              0x859B80
#define CSidlScreenWnd__LoadIniListWnd_x                           0x858EC0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x85A5E0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8588A0
#define CSidlScreenWnd__StoreIniVis_x                              0x858C90
#define CSidlScreenWnd__WndNotification_x                          0x85A840
#define CSidlScreenWnd__GetChildItem_x                             0x858DD0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5B8B20
#define CSkillMgr__GetSkillCap_x                                   0x5B8B90

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x891D90
#define CSliderWnd__SetValue_x                                     0x891F60
#define CSliderWnd__SetNumTicks_x                                  0x8926E0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x759010

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x882540
#define CStmlWnd__CalculateHSBRange_x                              0x87ACB0
#define CStmlWnd__CalculateVSBRange_x                              0x87AD40
#define CStmlWnd__CanBreakAtCharacter_x                            0x87AEC0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x87B7A0
#define CStmlWnd__ForceParseNow_x                                  0x882E90
#define CStmlWnd__GetNextTagPiece_x                                0x87B6A0
#define CStmlWnd__GetSTMLText_x                                    0x652AD0
#define CStmlWnd__GetVisibleText_x                                 0x87C1F0
#define CStmlWnd__InitializeWindowVariables_x                      0x87E3D0
#define CStmlWnd__MakeStmlColorTag_x                               0x879F00
#define CStmlWnd__MakeWndNotificationTag_x                         0x879F60
#define CStmlWnd__SetSTMLText_x                                    0x87FC30
#define CStmlWnd__StripFirstSTMLLines_x                            0x8821E0
#define CStmlWnd__UpdateHistoryString_x                            0x87D130

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8895E0
#define CTabWnd__DrawCurrentPage_x                                 0x888E50
#define CTabWnd__DrawTab_x                                         0x888C10
#define CTabWnd__GetCurrentPage_x                                  0x889220
#define CTabWnd__GetPageInnerRect_x                                0x888900
#define CTabWnd__GetTabInnerRect_x                                 0x888B00
#define CTabWnd__GetTabRect_x                                      0x8889D0
#define CTabWnd__InsertPage_x                                      0x8898D0
#define CTabWnd__SetPage_x                                         0x889250
#define CTabWnd__SetPageRect_x                                     0x889520
#define CTabWnd__UpdatePage_x                                      0x889870

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41F8C0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8859B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x88E750

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x84D330

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x55AC40
#define CXStr__CXStr1_x                                            0x4DA1A0
#define CXStr__CXStr3_x                                            0x801DA0
#define CXStr__dCXStr_x                                            0x66C770
#define CXStr__operator_equal_x                                    0x801F10
#define CXStr__operator_equal1_x                                   0x801F60
#define CXStr__operator_plus_equal1_x                              0x803040

// CXWnd 
#define CXWnd__BringToTop_x                                        0x85EA60
#define CXWnd__Center_x                                            0x864BB0
#define CXWnd__ClrFocus_x                                          0x85E630
#define CXWnd__DoAllDrawing_x                                      0x864820
#define CXWnd__DrawChildren_x                                      0x8649B0
#define CXWnd__DrawColoredRect_x                                   0x85EE10
#define CXWnd__DrawTooltip_x                                       0x85F0C0
#define CXWnd__DrawTooltipAtPoint_x                                0x8637A0
#define CXWnd__GetBorderFrame_x                                    0x85F4C0
#define CXWnd__GetChildWndAt_x                                     0x862760
#define CXWnd__GetClientClipRect_x                                 0x85F2D0
#define CXWnd__GetScreenClipRect_x                                 0x863EA0
#define CXWnd__GetScreenRect_x                                     0x85F650
#define CXWnd__GetTooltipRect_x                                    0x85EF50
#define CXWnd__GetWindowTextA_x                                    0x411190
#define CXWnd__IsActive_x                                          0x871E20
#define CXWnd__IsDescendantOf_x                                    0x85F410
#define CXWnd__IsReallyVisible_x                                   0x862740
#define CXWnd__IsType_x                                            0x88AFA0
#define CXWnd__Move_x                                              0x861E20
#define CXWnd__Move1_x                                             0x8644E0
#define CXWnd__ProcessTransition_x                                 0x85EA00
#define CXWnd__Refade_x                                            0x85E7E0
#define CXWnd__Resize_x                                            0x85F710
#define CXWnd__Right_x                                             0x863CA0
#define CXWnd__SetFocus_x                                          0x860F80
#define CXWnd__SetFont_x                                           0x85E680
#define CXWnd__SetKeyTooltip_x                                     0x85F980
#define CXWnd__SetMouseOver_x                                      0x8641E0
#define CXWnd__StartFade_x                                         0x85EAB0
#define CXWnd__GetChildItem_x                                      0x864120

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x873740
#define CXWndManager__DrawWindows_x                                0x873380
#define CXWndManager__GetKeyboardFlags_x                           0x871990
#define CXWndManager__HandleKeyboardMsg_x                          0x8722A0
#define CXWndManager__RemoveWnd_x                                  0x871FB0

// CDBStr
#define CDBStr__GetString_x                                        0x4850E0

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8CC160
#define EQ_Character__CastSpell_x                                  0x43A780
#define EQ_Character__Cur_HP_x                                     0x449D80
#define EQ_Character__GetAACastingTimeModifier_x                   0x433640
#define EQ_Character__GetCharInfo2_x                               0x7D7230
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42C940
#define EQ_Character__GetFocusRangeModifier_x                      0x42CB20
#define EQ_Character__Max_Endurance_x                              0x5800E0
#define EQ_Character__Max_HP_x                                     0x443F20
#define EQ_Character__Max_Mana_x                                   0x57FF20
#define EQ_Character__doCombatAbility_x                            0x57E980
#define EQ_Character__UseSkill_x                                   0x45ADD0
#define EQ_Character__GetConLevel_x                                0x575AE0
#define EQ_Character__IsExpansionFlag_x                            0x4106D0
#define EQ_Character__TotalEffect_x                                0x4388F0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x552F40
#define EQ_Item__CreateItemTagString_x                             0x7B7D00
#define EQ_Item__IsStackable_x                                     0x7AC4E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A3FE0
#define EQ_LoadingS__Array_x                                       0xABCB48

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5843D0
#define EQ_PC__GetAltAbilityIndex_x                                0x7C03E0
#define EQ_PC__GetCombatAbility_x                                  0x7C0470
#define EQ_PC__GetCombatAbilityTimer_x                             0x7C0520
#define EQ_PC__GetItemTimerValue_x                                 0x57E6C0
#define EQ_PC__HasLoreItem_x                                       0x578C60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4DA270
#define EQItemList__add_item_x                                     0x4DA1B0
#define EQItemList__delete_item_x                                  0x4DA670
#define EQItemList__FreeItemList_x                                 0x4DA570

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4844D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x589F90
#define EQPlayer__dEQPlayer_x                                      0x58EB10
#define EQPlayer__DoAttack_x                                       0x5A3030
#define EQPlayer__EQPlayer_x                                       0x594290
#define EQPlayer__SetNameSpriteState_x                             0x58C3C0
#define EQPlayer__SetNameSpriteTint_x                              0x58A000
#define EQPlayer__IsBodyType_j_x                                   0x8CBA00
#define EQPlayer__IsTargetable_x                                   0x8CBCD0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x597790
#define EQPlayerManager__GetSpawnByName_x                          0x597BF0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x558F70
#define KeypressHandler__AttachKeyToEqCommand_x                    0x558FB0
#define KeypressHandler__ClearCommandStateArray_x                  0x558B50
#define KeypressHandler__HandleKeyDown_x                           0x5574B0
#define KeypressHandler__HandleKeyUp_x                             0x5577D0
#define KeypressHandler__SaveKeymapping_x                          0x558C20

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6C4E30
#define MapViewMap__SaveEx_x                                       0x6C86E0

#define PlayerPointManager__GetAltCurrency_x                       0x7D1360

// StringTable 
#define StringTable__getString_x                                   0x7CC5B0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x582CC0
