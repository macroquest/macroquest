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
#define __ExpectedVersionDate                                     "Sep 17 2014"
#define __ExpectedVersionTime                                     "15:10:34"
#define __ActualVersionDate_x                                      0xA4C858
#define __ActualVersionTime_x                                      0xA4C864

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x572B40
#define __MemChecker1_x                                            0x8364F0
#define __MemChecker2_x                                            0x6099B0
#define __MemChecker3_x                                            0x609900
#define __MemChecker4_x                                            0x7BAF10
#define __EncryptPad0_x                                            0xBB8090
#define __EncryptPad1_x                                            0xD32378
#define __EncryptPad2_x                                            0xBFF2F0
#define __EncryptPad3_x                                            0xBFEEF0
#define __EncryptPad4_x                                            0xD0FCA8
#define __AC1_x                                                    0x778815
#define __AC2_x                                                    0x5290D7
#define __AC3_x                                                    0x53D7C0
#define __AC4_x                                                    0x5438F0
#define __AC5_x                                                    0x54FF4E
#define __AC6_x                                                    0x553A82
#define __AC7_x                                                    0x5499FC
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10E2F08
#define DI8__Keyboard_x                                            0x10E2F0C
#define DI8__Mouse_x                                               0x10E2F10
#define __AltTimerReady_x                                          0xF429A1
#define __Attack_x                                                 0xFD5AAB
#define __Autofire_x                                               0xFD5AAC
#define __BindList_x                                               0xB7C260
#define __bCommandEnabled_x                                        0xF40AB0
#define __Clicks_x                                                 0xF515E8
#define __CommandList_x                                            0xB80378
#define __CurrentMapLabel_x                                        0x10E8B88
#define __CurrentSocial_x                                          0xB41E28
#define __DoAbilityList_x                                          0xF87D60
#define __do_loot_x                                                0x4F0AB0
#define __DrawHandler_x                                            0x174B144
#define __GroupCount_x                                             0xF4207A

#define __Guilds_x                                                 0xF47B68
#define __gWorld_x                                                 0xF44534
#define __HotkeyPage_x                                             0xFCE760
#define __HWnd_x                                                   0xFDAE10
#define __InChatMode_x                                             0xF51514
#define __LastTell_x                                               0xF53468
#define __LMouseHeldTime_x                                         0xF51654
#define __Mouse_x                                                  0x10E2F14
#define __MouseLook_x                                              0xF515AE
#define __MouseEventTime_x                                         0xFD629C
#define __NetStatusToggle_x                                        0xF515B1
#define __PCNames_x                                                0xF52A9C
#define __RangeAttackReady_x                                       0xF52734
#define __RMouseHeldTime_x                                         0xF51650
#define __RunWalkState_x                                           0xF51518
#define __ScreenMode_x                                             0xE90A70
#define __ScreenX_x                                                0xF514CC
#define __ScreenY_x                                                0xF514C8
#define __ScreenXMax_x                                             0xF514D0
#define __ScreenYMax_x                                             0xF514D4
#define __ServerHost_x                                             0xF41FC4
#define __ServerName_x                                             0xF87D20
#define __ShiftKeyDown_x                                           0xF51BB8
#define __ShowNames_x                                              0xF52940
#define __Socials_x                                                0xF87E20
#define __SubscriptionType_x                                       0x11128C0
#define __TargetAggroHolder_x                                      0x10EADA0
#define __GroupAggro_x                                             0x10EADE0
#define __LoginName_x                                              0xFD99E8
#define __Inviter_x                                                0xFD5A28


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF44620
#define instEQZoneInfo_x                                           0xF517A4
#define instKeypressHandler_x                                      0xFD6280
#define pinstActiveBanker_x                                        0xF445D8
#define pinstActiveCorpse_x                                        0xF445DC
#define pinstActiveGMaster_x                                       0xF445E0
#define pinstActiveMerchant_x                                      0xF445D4
#define pinstAggroInfo_x                                           0xD55058
#define pinstAltAdvManager_x                                       0xE91B48
#define pinstAuraMgr_x                                             0xD5EF20
#define pinstBandageTarget_x                                       0xF445C0
#define pinstCamActor_x                                            0xE91454
#define pinstCDBStr_x                                              0xE90A04
#define pinstCDisplay_x                                            0xF445E8
#define pinstCEverQuest_x                                          0x10E308C
#define pinstCharData_x                                            0xF445A4
#define pinstCharSpawn_x                                           0xF445CC
#define pinstControlledMissile_x                                   0xF445A0
#define pinstControlledPlayer_x                                    0xF445CC
#define pinstCSidlManager_x                                        0x174A558
#define pinstCXWndManager_x                                        0x174A550
#define instDynamicZone_x                                          0xF51360
#define pinstDZMember_x                                            0xF51470
#define pinstDZTimerInfo_x                                         0xF51474
#define pinstEQItemList_x                                          0xF40CFC
#define instEQMisc_x                                               0xB5D770
#define pinstEQSoundManager_x                                      0xE91E48
#define instExpeditionLeader_x                                     0xF513AA
#define instExpeditionName_x                                       0xF513EA
#define pinstGroup_x                                               0xF42076
#define pinstImeManager_x                                          0x174A55C
#define pinstLocalPlayer_x                                         0xF445B8
#define pinstMercenaryData_x                                       0xFD68D0
#define pinstMercAltAbilities_x                                    0xE91D68
#define pinstModelPlayer_x                                         0xF445E4
#define pinstPCData_x                                              0xF445A4
#define pinstSkillMgr_x                                            0xFD7708
#define pinstSpawnManager_x                                        0xFD6FF0
#define pinstSpellManager_x                                        0xFD7850
#define pinstSpellSets_x                                           0xFCE7C4
#define pinstStringTable_x                                         0xF4454C
#define pinstSwitchManager_x                                       0xF41C08
#define pinstTarget_x                                              0xF445D0
#define pinstTargetObject_x                                        0xF445A8
#define pinstTargetSwitch_x                                        0xF445AC
#define pinstTaskMember_x                                          0xE90950
#define pinstTrackTarget_x                                         0xF445C4
#define pinstTradeTarget_x                                         0xF445B4
#define instTributeActive_x                                        0xB5D795
#define pinstViewActor_x                                           0xE91450
#define pinstWorldData_x                                           0xF44588


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD55538
#define pinstCAudioTriggersWindow_x                                0xD553C8
#define pinstCCharacterSelect_x                                    0xE912FC
#define pinstCFacePick_x                                           0xE910AC
#define pinstCNoteWnd_x                                            0xE912B4
#define pinstCBookWnd_x                                            0xE912BC
#define pinstCPetInfoWnd_x                                         0xE912C0
#define pinstCTrainWnd_x                                           0xE912C4
#define pinstCSkillsWnd_x                                          0xE912C8
#define pinstCSkillsSelectWnd_x                                    0xE912CC
#define pinstCCombatSkillSelectWnd_x                               0xE912D0
#define pinstCFriendsWnd_x                                         0xE912D4
#define pinstCAuraWnd_x                                            0xE912D8
#define pinstCRespawnWnd_x                                         0xE912DC
#define pinstCBandolierWnd_x                                       0xE912E0
#define pinstCPotionBeltWnd_x                                      0xE912E4
#define pinstCAAWnd_x                                              0xE912E8
#define pinstCGroupSearchFiltersWnd_x                              0xE912EC
#define pinstCLoadskinWnd_x                                        0xE912F0
#define pinstCAlarmWnd_x                                           0xE912F4
#define pinstCMusicPlayerWnd_x                                     0xE912F8
#define pinstCMailWnd_x                                            0xE91300
#define pinstCMailCompositionWnd_x                                 0xE91304
#define pinstCMailAddressBookWnd_x                                 0xE91308
#define pinstCRaidWnd_x                                            0xE91310
#define pinstCRaidOptionsWnd_x                                     0xE91314
#define pinstCBreathWnd_x                                          0xE91318
#define pinstCMapViewWnd_x                                         0xE9131C
#define pinstCMapToolbarWnd_x                                      0xE91320
#define pinstCEditLabelWnd_x                                       0xE91324
#define pinstCTargetWnd_x                                          0xE91328
#define pinstCColorPickerWnd_x                                     0xE9132C
#define pinstCPlayerWnd_x                                          0xE91330
#define pinstCOptionsWnd_x                                         0xE91334
#define pinstCBuffWindowNORMAL_x                                   0xE91338
#define pinstCBuffWindowSHORT_x                                    0xE9133C
#define pinstCharacterCreation_x                                   0xE91340
#define pinstCCursorAttachment_x                                   0xE91344
#define pinstCCastingWnd_x                                         0xE91348
#define pinstCCastSpellWnd_x                                       0xE9134C
#define pinstCSpellBookWnd_x                                       0xE91350
#define pinstCInventoryWnd_x                                       0xE91354
#define pinstCBankWnd_x                                            0xE91358
#define pinstCQuantityWnd_x                                        0xE9135C
#define pinstCLootWnd_x                                            0xE91360
#define pinstCActionsWnd_x                                         0xE91364
#define pinstCCombatAbilityWnd_x                                   0xE91368
#define pinstCMerchantWnd_x                                        0xE9136C
#define pinstCTradeWnd_x                                           0xE91370
#define pinstCSelectorWnd_x                                        0xE91374
#define pinstCBazaarWnd_x                                          0xE91378
#define pinstCBazaarSearchWnd_x                                    0xE9137C
#define pinstCGiveWnd_x                                            0xE91398
#define pinstCTrackingWnd_x                                        0xE913A0
#define pinstCInspectWnd_x                                         0xE913A4
#define pinstCSocialEditWnd_x                                      0xE913A8
#define pinstCFeedbackWnd_x                                        0xE913AC
#define pinstCBugReportWnd_x                                       0xE913B0
#define pinstCVideoModesWnd_x                                      0xE913B4
#define pinstCTextEntryWnd_x                                       0xE913BC
#define pinstCFileSelectionWnd_x                                   0xE913C0
#define pinstCCompassWnd_x                                         0xE913C4
#define pinstCPlayerNotesWnd_x                                     0xE913C8
#define pinstCGemsGameWnd_x                                        0xE913CC
#define pinstCTimeLeftWnd_x                                        0xE913D0
#define pinstCPetitionQWnd_x                                       0xE913E4
#define pinstCSoulmarkWnd_x                                        0xE913E8
#define pinstCStoryWnd_x                                           0xE913EC
#define pinstCJournalTextWnd_x                                     0xE913F0
#define pinstCJournalCatWnd_x                                      0xE913F4
#define pinstCBodyTintWnd_x                                        0xE913F8
#define pinstCServerListWnd_x                                      0xE913FC
#define pinstCAvaZoneWnd_x                                         0xE91408
#define pinstCBlockedBuffWnd_x                                     0xE9140C
#define pinstCBlockedPetBuffWnd_x                                  0xE91410
#define pinstCInvSlotMgr_x                                         0xE91448
#define pinstCContainerMgr_x                                       0xE9144C
#define pinstCAdventureLeaderboardWnd_x                            0x10E3C60
#define pinstCAdventureRequestWnd_x                                0x10E3CD8
#define pinstCAltStorageWnd_x                                      0x10E3FB8
#define pinstCAdventureStatsWnd_x                                  0x10E3D50
#define pinstCBarterMerchantWnd_x                                  0x10E4BA0
#define pinstCBarterSearchWnd_x                                    0x10E4C18
#define pinstCBarterWnd_x                                          0x10E4C90
#define pinstCChatManager_x                                        0x10E5320
#define pinstCDynamicZoneWnd_x                                     0x10E57D0
#define pinstCEQMainWnd_x                                          0x10E5968
#define pinstCFellowshipWnd_x                                      0x10E5764
#define pinstCFindLocationWnd_x                                    0x10E5C38
#define pinstCGroupSearchWnd_x                                     0x10E5F08
#define pinstCGroupWnd_x                                           0x10E5F80
#define pinstCGuildBankWnd_x                                       0x10E5FF8
#define pinstCGuildMgmtWnd_x                                       0x10E80E8
#define pinstCHotButtonWnd_x                                       0x10E81B4
#define pinstCHotButtonWnd1_x                                      0x10E81B4
#define pinstCHotButtonWnd2_x                                      0x10E81B8
#define pinstCHotButtonWnd3_x                                      0x10E81BC
#define pinstCHotButtonWnd4_x                                      0x10E81E0
#define pinstCItemDisplayManager_x                                 0x10E84D8
#define pinstCItemExpTransferWnd_x                                 0x10E8554
#define pinstCLFGuildWnd_x                                         0x10E8830
#define pinstCMIZoneSelectWnd_x                                    0x10E8E18
#define pinstCConfirmationDialog_x                                 0x10E9520
#define pinstCPopupWndManager_x                                    0x10E9520
#define pinstCProgressionSelectionWnd_x                            0x10E9610
#define pinstCPvPStatsWnd_x                                        0x10E9700
#define pinstCSystemInfoDialogBox_x                                0x10E9E08
#define pinstCTaskWnd_x                                            0x10EB1A0
#define pinstCTaskTemplateSelectWnd_x                              0x10EB128
#define pinstCTipWndOFDAY_x                                        0x10EB3F8
#define pinstCTipWndCONTEXT_x                                      0x10EB3FC
#define pinstCTitleWnd_x                                           0x10EB478
#define pinstCContextMenuManager_x                                 0x174A16C
#define pinstCVoiceMacroWnd_x                                      0xFD7EB8
#define pinstCHtmlWnd_x                                            0xFD7FB0
#define pinstIconCache_x                                           0x10E593C
#define pinstCTradeskillWnd_x                                      0x10EB578

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5085C0
#define __ConvertItemTags_x                                        0x4F5770
#define __ExecuteCmd_x                                             0x4E0390
#define __EQGetTime_x                                              0x837050
#define __get_melee_range_x                                        0x4E6FE0
#define __GetGaugeValueFromEQ_x                                    0x777570
#define __GetLabelFromEQ_x                                         0x7787A0
#define __GetXTargetType_x                                         0x8F4300
#define __LoadFrontEnd_x                                           0x609060
#define __NewUIINI_x                                               0x776EB0
#define __ProcessGameEvents_x                                      0x54BB40
#define CrashDetected_x                                            0x60AB30
#define DrawNetStatus_x                                            0x582360
#define Util__FastTime_x                                           0x836360
#define Expansion_HoT_x                                            0xF528A0
#define __HelpPath_x                                               0xFD6008
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A5C10
#define AltAdvManager__IsAbilityReady_x                            0x4A5C80
#define AltAdvManager__GetAltAbility_x                             0x4A6040

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4529A0
#define CharacterZoneClient__MakeMeVisible_x                       0x457940

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x638CE0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x646F20

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x562310

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x661E10
#define CChatManager__InitContextMenu_x                            0x662930

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x81D050
#define CChatService__GetFriendName_x                              0x81D060

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x667710
#define CChatWindow__Clear_x                                       0x6672D0
#define CChatWindow__WndNotification_x                             0x667C50

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8954A0
#define CComboWnd__Draw_x                                          0x895680
#define CComboWnd__GetCurChoice_x                                  0x8952C0
#define CComboWnd__GetListRect_x                                   0x895920
#define CComboWnd__GetTextRect_x                                   0x895500
#define CComboWnd__InsertChoice_x                                  0x895990
#define CComboWnd__SetColors_x                                     0x895250
#define CComboWnd__SetChoice_x                                     0x895280

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x670DE0
#define CContainerWnd__vftable_x                                   0xA56028

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x494400
#define CDisplay__GetClickedActor_x                                0x48CEA0
#define CDisplay__GetUserDefinedColor_x                            0x48B760
#define CDisplay__GetWorldFilePath_x                               0x48AB60
#define CDisplay__is3dON_x                                         0x489F30
#define CDisplay__ReloadUI_x                                       0x49F820
#define CDisplay__WriteTextHD2_x                                   0x4906F0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8B7320

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8A5EC0
#define CEditWnd__GetCharIndexPt_x                                 0x8A6EC0
#define CEditWnd__GetDisplayString_x                               0x8A6070
#define CEditWnd__GetHorzOffset_x                                  0x8A63B0
#define CEditWnd__GetLineForPrintableChar_x                        0x8A69A0
#define CEditWnd__GetSelStartPt_x                                  0x8A7170
#define CEditWnd__GetSTMLSafeText_x                                0x8A6540
#define CEditWnd__PointFromPrintableChar_x                         0x8A6A90
#define CEditWnd__SelectableCharFromPoint_x                        0x8A6C00
#define CEditWnd__SetEditable_x                                    0x8A6510

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x529820
#define CEverQuest__DoTellWindow_x                                 0x52F1B0
#define CEverQuest__DropHeldItemOnGround_x                         0x537C40
#define CEverQuest__dsp_chat_x                                     0x530950
#define CEverQuest__Emote_x                                        0x530BB0
#define CEverQuest__EnterZone_x                                    0x543A80
#define CEverQuest__GetBodyTypeDesc_x                              0x526150
#define CEverQuest__GetClassDesc_x                                 0x52BD20
#define CEverQuest__GetClassThreeLetterCode_x                      0x52C320
#define CEverQuest__GetDeityDesc_x                                 0x526A30
#define CEverQuest__GetLangDesc_x                                  0x5264E0
#define CEverQuest__GetRaceDesc_x                                  0x52C4E0
#define CEverQuest__InterpretCmd_x                                 0x531490
#define CEverQuest__LeftClickedOnPlayer_x                          0x547E70
#define CEverQuest__LMouseUp_x                                     0x54A160
#define CEverQuest__RightClickedOnPlayer_x                         0x548970
#define CEverQuest__RMouseUp_x                                     0x5499B0
#define CEverQuest__SetGameState_x                                 0x529ED0
#define CEverQuest__UPCNotificationFlush_x                         0x532630

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x681820
#define CGaugeWnd__CalcLinesFillRect_x                             0x681880
#define CGaugeWnd__Draw_x                                          0x681CB0

// CGuild
#define CGuild__FindMemberByName_x                                 0x4245F0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69E920

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6AA6A0
#define CInvSlotMgr__MoveItem_x                                    0x6AB5E0
#define CInvSlotMgr__SelectSlot_x                                  0x6AA750

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6A99D0
#define CInvSlot__SliderComplete_x                                 0x6A7820
#define CInvSlot__GetItemBase_x                                    0x6A6CC0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6AC380

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7741C0
#define CItemDisplayWnd__UpdateStrings_x                           0x6AD6D0

// CLabel 
#define CLabel__Draw_x                                             0x6C7FF0

// CListWnd 
#define CListWnd__AddColumn_x                                      0x883680
#define CListWnd__AddColumn1_x                                     0x882E60
#define CListWnd__AddLine_x                                        0x882910
#define CListWnd__AddString_x                                      0x882B20
#define CListWnd__CalculateFirstVisibleLine_x                      0x87FA00
#define CListWnd__CalculateVSBRange_x                              0x881B10
#define CListWnd__ClearAllSel_x                                    0x87ECC0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8824E0
#define CListWnd__Compare_x                                        0x880500
#define CListWnd__Draw_x                                           0x881770
#define CListWnd__DrawColumnSeparators_x                           0x881600
#define CListWnd__DrawHeader_x                                     0x87EFD0
#define CListWnd__DrawItem_x                                       0x880B40
#define CListWnd__DrawLine_x                                       0x8812A0
#define CListWnd__DrawSeparator_x                                  0x8816A0
#define CListWnd__EnsureVisible_x                                  0x87FB60
#define CListWnd__ExtendSel_x                                      0x880A50
#define CListWnd__GetColumnMinWidth_x                              0x87E6E0
#define CListWnd__GetColumnWidth_x                                 0x87E600
#define CListWnd__GetCurSel_x                                      0x87DDF0
#define CListWnd__GetItemAtPoint_x                                 0x87FDF0
#define CListWnd__GetItemAtPoint1_x                                0x87FE60
#define CListWnd__GetItemData_x                                    0x87E120
#define CListWnd__GetItemHeight_x                                  0x87F660
#define CListWnd__GetItemIcon_x                                    0x87E300
#define CListWnd__GetItemRect_x                                    0x87FC30
#define CListWnd__GetItemText_x                                    0x87E1B0
#define CListWnd__GetSelList_x                                     0x882D50
#define CListWnd__GetSeparatorRect_x                               0x880420
#define CListWnd__RemoveLine_x                                     0x882D00
#define CListWnd__SetColors_x                                      0x87DF40
#define CListWnd__SetColumnJustification_x                         0x87E9B0
#define CListWnd__SetColumnWidth_x                                 0x87E690
#define CListWnd__SetCurSel_x                                      0x87DE30
#define CListWnd__SetItemColor_x                                   0x8821C0
#define CListWnd__SetItemData_x                                    0x87ED70
#define CListWnd__SetItemText_x                                    0x882000
#define CListWnd__ShiftColumnSeparator_x                           0x881E90
#define CListWnd__Sort_x                                           0x8837E0
#define CListWnd__ToggleSel_x                                      0x87EC40

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6E1250

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7025C0
#define CMerchantWnd__RequestBuyItem_x                             0x7093B0
#define CMerchantWnd__RequestSellItem_x                            0x7315C0
#define CMerchantWnd__SelectRecoverySlot_x                         0x702870
#define CMerchantWnd__SelectBuySellSlot_x                          0x701AD0
#define CMerchantWnd__ActualSelect_x                               0x7062F0

// CObfuscator
#define CObfuscator__doit_x                                        0x7FD600

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x89AD00
#define CSidlManager__CreateLabel_x                                0x76A100

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x62FE70
#define CSidlScreenWnd__CalculateVSBRange_x                        0x62FDA0
#define CSidlScreenWnd__ConvertToRes_x                             0x8B7200
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8887D0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x889CE0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x889D90
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x889250
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8882B0
#define CSidlScreenWnd__EnableIniStorage_x                         0x887A00
#define CSidlScreenWnd__GetSidlPiece_x                             0x8884A0
#define CSidlScreenWnd__Init1_x                                    0x8899B0
#define CSidlScreenWnd__LoadIniInfo_x                              0x888880
#define CSidlScreenWnd__LoadIniListWnd_x                           0x887BC0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8894A0
#define CSidlScreenWnd__StoreIniInfo_x                             0x8874C0
#define CSidlScreenWnd__StoreIniVis_x                              0x887990
#define CSidlScreenWnd__WndNotification_x                          0x889730
#define CSidlScreenWnd__GetChildItem_x                             0x887AD0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x88E5F0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5CAF70
#define CSkillMgr__GetSkillCap_x                                   0x5CB110
#define CSkillMgr__GetNameToken_x                                  0x5CABE0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8C11D0
#define CSliderWnd__SetValue_x                                     0x8C13A0
#define CSliderWnd__SetNumTicks_x                                  0x8C1B20

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x771E60

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8B15A0
#define CStmlWnd__CalculateHSBRange_x                              0x8A9AC0
#define CStmlWnd__CalculateVSBRange_x                              0x8A9B50
#define CStmlWnd__CanBreakAtCharacter_x                            0x8A9CD0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8AA5B0
#define CStmlWnd__ForceParseNow_x                                  0x8B1EF0
#define CStmlWnd__GetNextTagPiece_x                                0x8AA4B0
#define CStmlWnd__GetSTMLText_x                                    0x666B70
#define CStmlWnd__GetVisibleText_x                                 0x8AB000
#define CStmlWnd__InitializeWindowVariables_x                      0x8AD390
#define CStmlWnd__MakeStmlColorTag_x                               0x8A8DC0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8A8E20
#define CStmlWnd__SetSTMLText_x                                    0x8AEBF0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8B1240
#define CStmlWnd__UpdateHistoryString_x                            0x8ABF40

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8B89E0
#define CTabWnd__DrawCurrentPage_x                                 0x8B8250
#define CTabWnd__DrawTab_x                                         0x8B8020
#define CTabWnd__GetCurrentPage_x                                  0x8B8620
#define CTabWnd__GetPageInnerRect_x                                0x8B7D10
#define CTabWnd__GetTabInnerRect_x                                 0x8B7F10
#define CTabWnd__GetTabRect_x                                      0x8B7DE0
#define CTabWnd__InsertPage_x                                      0x8B8CD0
#define CTabWnd__SetPage_x                                         0x8B8650
#define CTabWnd__SetPageRect_x                                     0x8B8920
#define CTabWnd__UpdatePage_x                                      0x8B8C70

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4202E0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B4A60

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8BDB90

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x87C0A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x411610
#define CXStr__CXStr1_x                                            0x8BC920
#define CXStr__CXStr3_x                                            0x8333F0
#define CXStr__dCXStr_x                                            0x4A7400
#define CXStr__operator_equal_x                                    0x833560
#define CXStr__operator_equal1_x                                   0x8335B0
#define CXStr__operator_plus_equal1_x                              0x834690

// CXWnd 
#define CXWnd__BringToTop_x                                        0x88D8B0
#define CXWnd__Center_x                                            0x893940
#define CXWnd__ClrFocus_x                                          0x88D4A0
#define CXWnd__DoAllDrawing_x                                      0x893580
#define CXWnd__DrawChildren_x                                      0x893730
#define CXWnd__DrawColoredRect_x                                   0x88DC40
#define CXWnd__DrawTooltip_x                                       0x88DEF0
#define CXWnd__DrawTooltipAtPoint_x                                0x892510
#define CXWnd__GetBorderFrame_x                                    0x88E2F0
#define CXWnd__GetChildWndAt_x                                     0x8914E0
#define CXWnd__GetClientClipRect_x                                 0x88E100
#define CXWnd__GetScreenClipRect_x                                 0x892C00
#define CXWnd__GetScreenRect_x                                     0x88E490
#define CXWnd__GetTooltipRect_x                                    0x88DD80
#define CXWnd__GetWindowTextA_x                                    0x411650
#define CXWnd__IsActive_x                                          0x8A0C80
#define CXWnd__IsDescendantOf_x                                    0x88E240
#define CXWnd__IsReallyVisible_x                                   0x8914C0
#define CXWnd__IsType_x                                            0x8BA3C0
#define CXWnd__Move_x                                              0x890BE0
#define CXWnd__Move1_x                                             0x893240
#define CXWnd__ProcessTransition_x                                 0x88D860
#define CXWnd__Refade_x                                            0x88D640
#define CXWnd__Resize_x                                            0x88E550
#define CXWnd__Right_x                                             0x892A00
#define CXWnd__SetFocus_x                                          0x88FD80
#define CXWnd__SetFont_x                                           0x88D4F0
#define CXWnd__SetKeyTooltip_x                                     0x88E7C0
#define CXWnd__SetMouseOver_x                                      0x892F40
#define CXWnd__StartFade_x                                         0x88D900
#define CXWnd__GetChildItem_x                                      0x892E80

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A25B0
#define CXWndManager__DrawWindows_x                                0x8A21F0
#define CXWndManager__GetKeyboardFlags_x                           0x8A07B0
#define CXWndManager__HandleKeyboardMsg_x                          0x8A1110
#define CXWndManager__RemoveWnd_x                                  0x8A0E10

// CDBStr
#define CDBStr__GetString_x                                        0x4883F0

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8F1320
#define EQ_Character__CastSpell_x                                  0x43C620
#define EQ_Character__Cur_HP_x                                     0x452060
#define EQ_Character__GetAACastingTimeModifier_x                   0x435720
#define EQ_Character__GetCharInfo2_x                               0x807DB0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42DA70
#define EQ_Character__GetFocusRangeModifier_x                      0x42DC50
#define EQ_Character__Max_Endurance_x                              0x593F60
#define EQ_Character__Max_HP_x                                     0x4486A0
#define EQ_Character__Max_Mana_x                                   0x593D90
#define EQ_Character__doCombatAbility_x                            0x5915C0
#define EQ_Character__UseSkill_x                                   0x45CB90
#define EQ_Character__GetConLevel_x                                0x5869D0
#define EQ_Character__IsExpansionFlag_x                            0x410B30
#define EQ_Character__TotalEffect_x                                0x43A750

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x567380
#define EQ_Item__CreateItemTagString_x                             0x7E8740
#define EQ_Item__IsStackable_x                                     0x7DCC70
#define EQ_Item__GetImageNum_x                                     0x7DF960

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A7DA0
#define EQ_LoadingS__Array_x                                       0xB6AED8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5955B0
#define EQ_PC__GetAltAbilityIndex_x                                0x7F0840
#define EQ_PC__GetCombatAbility_x                                  0x7F08D0
#define EQ_PC__GetCombatAbilityTimer_x                             0x7F0980
#define EQ_PC__GetItemTimerValue_x                                 0x58F390
#define EQ_PC__HasLoreItem_x                                       0x589B30
#define EQ_PC__AlertInventoryChanged_x                             0x5869A0
#define EQ_PC__GetPcZoneClient_x                                   0x5AF840
#define EQ_PC__RemoveMyAffect_x									   0x58E8E0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E4F90
#define EQItemList__add_item_x                                     0x4E4ED0
#define EQItemList__delete_item_x                                  0x4E5390
#define EQItemList__FreeItemList_x                                 0x4E5290

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487900

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x59AA10
#define EQPlayer__dEQPlayer_x                                      0x5A3670
#define EQPlayer__DoAttack_x                                       0x5B5630
#define EQPlayer__EQPlayer_x                                       0x5A5AC0
#define EQPlayer__SetNameSpriteState_x                             0x5A0420
#define EQPlayer__SetNameSpriteTint_x                              0x59BDA0
#define EQPlayer__IsBodyType_j_x                                   0x8F05D0
#define EQPlayer__IsTargetable_x                                   0x8F0E00

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5A9DF0
#define EQPlayerManager__GetSpawnByName_x                          0x5AA250

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56D560
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56D5A0
#define KeypressHandler__ClearCommandStateArray_x                  0x56D140
#define KeypressHandler__HandleKeyDown_x                           0x56BA90
#define KeypressHandler__HandleKeyUp_x                             0x56BDB0
#define KeypressHandler__SaveKeymapping_x                          0x56D210

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6D9630
#define MapViewMap__SaveEx_x                                       0x6DCF10

#define PlayerPointManager__GetAltCurrency_x                       0x801EB0

// StringTable 
#define StringTable__getString_x                                   0x7FD8A0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x593A10

//Doors
#define EQSwitch__UseSwitch_x                                      0x5235A0

//IconCache
#define IconCache__GetIcon_x                                       0x6770E0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66E110
#define CContainerMgr__CloseContainer_x                            0x66E920

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x73A550

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x560DF0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B6480
#define EQ_Spell__SpellAffects_x                                   0x4B6520
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B6550
#define CharacterZoneClient__CalcAffectChange_x                    0x436A40
#define CLootWnd__LootAll_x                                        0x6CF180
#define CTargetWnd__GetBuffCaster_x                                0x77FAA0
