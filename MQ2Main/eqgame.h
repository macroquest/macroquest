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
#define __ExpectedVersionDate                                     "Oct 29 2014"
#define __ExpectedVersionTime                                     "18:12:43"
#define __ActualVersionDate_x                                      0xA57880
#define __ActualVersionTime_x                                      0xA5788C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x574870
#define __MemChecker1_x                                            0x83BD20
#define __MemChecker2_x                                            0x60BBE0
#define __MemChecker3_x                                            0x60BB30
#define __MemChecker4_x                                            0x7C0200
#define __EncryptPad0_x                                            0xBC3760
#define __EncryptPad1_x                                            0xD3EB98
#define __EncryptPad2_x                                            0xC0ACE8
#define __EncryptPad3_x                                            0xC0A8E8
#define __EncryptPad4_x                                            0xD1C320
#define __AC1_x                                                    0x77D425
#define __AC2_x                                                    0x52A7A7
#define __AC3_x                                                    0x53EE80
#define __AC4_x                                                    0x544FB0
#define __AC5_x                                                    0x55161E
#define __AC6_x                                                    0x555152
#define __AC7_x                                                    0x54B0CC
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10EFE90
#define DI8__Keyboard_x                                            0x10EFE94
#define DI8__Mouse_x                                               0x10EFE98
#define __AltTimerReady_x                                          0xF4F921
#define __Attack_x                                                 0xFE2A37
#define __Autofire_x                                               0xFE2A38
#define __BindList_x                                               0xB87688
#define __bCommandEnabled_x                                        0xF4DA30
#define __Clicks_x                                                 0xF5E568
#define __CommandList_x                                            0xB8B7D0
#define __CurrentMapLabel_x                                        0x10F58E8
#define __CurrentSocial_x                                          0xB4CFBC
#define __DoAbilityList_x                                          0xF94CEC
#define __do_loot_x                                                0x4F2150
#define __DrawHandler_x                                            0x175A4FC
#define __GroupCount_x                                             0xF4EFFA

#define __Guilds_x                                                 0xF54AE8
#define __gWorld_x                                                 0xF514B4
#define __HotkeyPage_x                                             0xFDB6EC
#define __HWnd_x                                                   0xFE7D98
#define __InChatMode_x                                             0xF5E494
#define __LastTell_x                                               0xF603F4
#define __LMouseHeldTime_x                                         0xF5E5D4
#define __Mouse_x                                                  0x10EFE9C
#define __MouseLook_x                                              0xF5E52E
#define __MouseEventTime_x                                         0xFE3224
#define __NetStatusToggle_x                                        0xF5E531
#define __PCNames_x                                                0xF5FA24
#define __RangeAttackReady_x                                       0xF5F6B8
#define __RMouseHeldTime_x                                         0xF5E5D0
#define __RunWalkState_x                                           0xF5E498
#define __ScreenMode_x                                             0xE9D9F0
#define __ScreenX_x                                                0xF5E44C
#define __ScreenY_x                                                0xF5E448
#define __ScreenXMax_x                                             0xF5E450
#define __ScreenYMax_x                                             0xF5E454
#define __ServerHost_x                                             0xF4EF44
#define __ServerName_x                                             0xF94CAC
#define __ShiftKeyDown_x                                           0xF5EB3C
#define __ShowNames_x                                              0xF5F8C8
#define __Socials_x                                                0xF94DAC
#define __SubscriptionType_x                                       0x1121C78
#define __TargetAggroHolder_x                                      0x10F7B24
#define __GroupAggro_x                                             0x10F7B64
#define __LoginName_x                                              0xFE6970
#define __Inviter_x                                                0xFE29B4


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF515A0
#define instEQZoneInfo_x                                           0xF5E724
#define instKeypressHandler_x                                      0xFE3208
#define pinstActiveBanker_x                                        0xF51558
#define pinstActiveCorpse_x                                        0xF5155C
#define pinstActiveGMaster_x                                       0xF51560
#define pinstActiveMerchant_x                                      0xF51554
#define pinstAggroInfo_x                                           0xD61FD8
#define pinstAltAdvManager_x                                       0xE9EAC8
#define pinstAuraMgr_x                                             0xD6BEA0
#define pinstBandageTarget_x                                       0xF51540
#define pinstCamActor_x                                            0xE9E3D4
#define pinstCDBStr_x                                              0xE9D984
#define pinstCDisplay_x                                            0xF51568
#define pinstCEverQuest_x                                          0x10F0014
#define pinstCharData_x                                            0xF51524
#define pinstCharSpawn_x                                           0xF5154C
#define pinstControlledMissile_x                                   0xF51520
#define pinstControlledPlayer_x                                    0xF5154C
#define pinstCSidlManager_x                                        0x1759910
#define pinstCXWndManager_x                                        0x1759908
#define instDynamicZone_x                                          0xF5E2E0
#define pinstDZMember_x                                            0xF5E3F0
#define pinstDZTimerInfo_x                                         0xF5E3F4
#define pinstEQItemList_x                                          0xF4DC7C
#define instEQMisc_x                                               0xB68A48
#define pinstEQSoundManager_x                                      0xE9EDC8
#define instExpeditionLeader_x                                     0xF5E32A
#define instExpeditionName_x                                       0xF5E36A
#define pinstGroup_x                                               0xF4EFF6
#define pinstImeManager_x                                          0x1759914
#define pinstLocalPlayer_x                                         0xF51538
#define pinstMercenaryData_x                                       0xFE3858
#define pinstMercAltAbilities_x                                    0xE9ECE8
#define pinstModelPlayer_x                                         0xF51564
#define pinstPCData_x                                              0xF51524
#define pinstSkillMgr_x                                            0xFE4690
#define pinstSpawnManager_x                                        0xFE3F78
#define pinstSpellManager_x                                        0xFE47D8
#define pinstSpellSets_x                                           0xFDB750
#define pinstStringTable_x                                         0xF514CC
#define pinstSwitchManager_x                                       0xF4EB88
#define pinstTarget_x                                              0xF51550
#define pinstTargetObject_x                                        0xF51528
#define pinstTargetSwitch_x                                        0xF5152C
#define pinstTaskMember_x                                          0xE9D8D0
#define pinstTrackTarget_x                                         0xF51544
#define pinstTradeTarget_x                                         0xF51534
#define instTributeActive_x                                        0xB68A6D
#define pinstViewActor_x                                           0xE9E3D0
#define pinstWorldData_x                                           0xF51508


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD624B8
#define pinstCAudioTriggersWindow_x                                0xD62348
#define pinstCCharacterSelect_x                                    0xE9E27C
#define pinstCFacePick_x                                           0xE9E02C
#define pinstCNoteWnd_x                                            0xE9E234
#define pinstCBookWnd_x                                            0xE9E23C
#define pinstCPetInfoWnd_x                                         0xE9E240
#define pinstCTrainWnd_x                                           0xE9E244
#define pinstCSkillsWnd_x                                          0xE9E248
#define pinstCSkillsSelectWnd_x                                    0xE9E24C
#define pinstCCombatSkillSelectWnd_x                               0xE9E250
#define pinstCFriendsWnd_x                                         0xE9E254
#define pinstCAuraWnd_x                                            0xE9E258
#define pinstCRespawnWnd_x                                         0xE9E25C
#define pinstCBandolierWnd_x                                       0xE9E260
#define pinstCPotionBeltWnd_x                                      0xE9E264
#define pinstCAAWnd_x                                              0xE9E268
#define pinstCGroupSearchFiltersWnd_x                              0xE9E26C
#define pinstCLoadskinWnd_x                                        0xE9E270
#define pinstCAlarmWnd_x                                           0xE9E274
#define pinstCMusicPlayerWnd_x                                     0xE9E278
#define pinstCMailWnd_x                                            0xE9E280
#define pinstCMailCompositionWnd_x                                 0xE9E284
#define pinstCMailAddressBookWnd_x                                 0xE9E288
#define pinstCRaidWnd_x                                            0xE9E290
#define pinstCRaidOptionsWnd_x                                     0xE9E294
#define pinstCBreathWnd_x                                          0xE9E298
#define pinstCMapViewWnd_x                                         0xE9E29C
#define pinstCMapToolbarWnd_x                                      0xE9E2A0
#define pinstCEditLabelWnd_x                                       0xE9E2A4
#define pinstCTargetWnd_x                                          0xE9E2A8
#define pinstCColorPickerWnd_x                                     0xE9E2AC
#define pinstCPlayerWnd_x                                          0xE9E2B0
#define pinstCOptionsWnd_x                                         0xE9E2B4
#define pinstCBuffWindowNORMAL_x                                   0xE9E2B8
#define pinstCBuffWindowSHORT_x                                    0xE9E2BC
#define pinstCharacterCreation_x                                   0xE9E2C0
#define pinstCCursorAttachment_x                                   0xE9E2C4
#define pinstCCastingWnd_x                                         0xE9E2C8
#define pinstCCastSpellWnd_x                                       0xE9E2CC
#define pinstCSpellBookWnd_x                                       0xE9E2D0
#define pinstCInventoryWnd_x                                       0xE9E2D4
#define pinstCBankWnd_x                                            0xE9E2D8
#define pinstCQuantityWnd_x                                        0xE9E2DC
#define pinstCLootWnd_x                                            0xE9E2E0
#define pinstCActionsWnd_x                                         0xE9E2E4
#define pinstCCombatAbilityWnd_x                                   0xE9E2E8
#define pinstCMerchantWnd_x                                        0xE9E2EC
#define pinstCTradeWnd_x                                           0xE9E2F0
#define pinstCSelectorWnd_x                                        0xE9E2F4
#define pinstCBazaarWnd_x                                          0xE9E2F8
#define pinstCBazaarSearchWnd_x                                    0xE9E2FC
#define pinstCGiveWnd_x                                            0xE9E318
#define pinstCTrackingWnd_x                                        0xE9E320
#define pinstCInspectWnd_x                                         0xE9E324
#define pinstCSocialEditWnd_x                                      0xE9E328
#define pinstCFeedbackWnd_x                                        0xE9E32C
#define pinstCBugReportWnd_x                                       0xE9E330
#define pinstCVideoModesWnd_x                                      0xE9E334
#define pinstCTextEntryWnd_x                                       0xE9E33C
#define pinstCFileSelectionWnd_x                                   0xE9E340
#define pinstCCompassWnd_x                                         0xE9E344
#define pinstCPlayerNotesWnd_x                                     0xE9E348
#define pinstCGemsGameWnd_x                                        0xE9E34C
#define pinstCTimeLeftWnd_x                                        0xE9E350
#define pinstCPetitionQWnd_x                                       0xE9E364
#define pinstCSoulmarkWnd_x                                        0xE9E368
#define pinstCStoryWnd_x                                           0xE9E36C
#define pinstCJournalTextWnd_x                                     0xE9E370
#define pinstCJournalCatWnd_x                                      0xE9E374
#define pinstCBodyTintWnd_x                                        0xE9E378
#define pinstCServerListWnd_x                                      0xE9E37C
#define pinstCAvaZoneWnd_x                                         0xE9E388
#define pinstCBlockedBuffWnd_x                                     0xE9E38C
#define pinstCBlockedPetBuffWnd_x                                  0xE9E390
#define pinstCInvSlotMgr_x                                         0xE9E3C8
#define pinstCContainerMgr_x                                       0xE9E3CC
#define pinstCAdventureLeaderboardWnd_x                            0x10F09C0
#define pinstCAdventureRequestWnd_x                                0x10F0A38
#define pinstCAltStorageWnd_x                                      0x10F0D18
#define pinstCAdventureStatsWnd_x                                  0x10F0AB0
#define pinstCBarterMerchantWnd_x                                  0x10F1900
#define pinstCBarterSearchWnd_x                                    0x10F1978
#define pinstCBarterWnd_x                                          0x10F19F0
#define pinstCChatManager_x                                        0x10F2080
#define pinstCDynamicZoneWnd_x                                     0x10F2530
#define pinstCEQMainWnd_x                                          0x10F26C8
#define pinstCFellowshipWnd_x                                      0x10F24C4
#define pinstCFindLocationWnd_x                                    0x10F2998
#define pinstCGroupSearchWnd_x                                     0x10F2C68
#define pinstCGroupWnd_x                                           0x10F2CE0
#define pinstCGuildBankWnd_x                                       0x10F2D58
#define pinstCGuildMgmtWnd_x                                       0x10F4E48
#define pinstCHotButtonWnd_x                                       0x10F4F14
#define pinstCHotButtonWnd1_x                                      0x10F4F14
#define pinstCHotButtonWnd2_x                                      0x10F4F18
#define pinstCHotButtonWnd3_x                                      0x10F4F1C
#define pinstCHotButtonWnd4_x                                      0x10F4F40
#define pinstCItemDisplayManager_x                                 0x10F5238
#define pinstCItemExpTransferWnd_x                                 0x10F52B4
#define pinstCLFGuildWnd_x                                         0x10F5590
#define pinstCMIZoneSelectWnd_x                                    0x10F5B78
#define pinstCConfirmationDialog_x                                 0x10F6280
#define pinstCPopupWndManager_x                                    0x10F6280
#define pinstCProgressionSelectionWnd_x                            0x10F6370
#define pinstCPvPStatsWnd_x                                        0x10F6460
#define pinstCSystemInfoDialogBox_x                                0x10F6B68
#define pinstCTaskWnd_x                                            0x10F7F30
#define pinstCTaskTemplateSelectWnd_x                              0x10F7EB8
#define pinstCTipWndOFDAY_x                                        0x10F8188
#define pinstCTipWndCONTEXT_x                                      0x10F818C
#define pinstCTitleWnd_x                                           0x10F8208
#define pinstCContextMenuManager_x                                 0x1759524
#define pinstCVoiceMacroWnd_x                                      0xFE4E40
#define pinstCHtmlWnd_x                                            0xFE4F38
#define pinstIconCache_x                                           0x10F269C
#define pinstCTradeskillWnd_x                                      0x10F8308

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x509C60
#define __ConvertItemTags_x                                        0x4F6E10
#define __ExecuteCmd_x                                             0x4E1940
#define __EQGetTime_x                                              0x83C880
#define __get_melee_range_x                                        0x4E8630
#define __GetGaugeValueFromEQ_x                                    0x77C170
#define __GetLabelFromEQ_x                                         0x77D3B0
#define __GetXTargetType_x                                         0x8FA100
#define __LoadFrontEnd_x                                           0x60B290
#define __NewUIINI_x                                               0x77BAB0
#define __ProcessGameEvents_x                                      0x54DA70
#define __ProcessMouseEvent_x                                      0x54D210
#define CrashDetected_x                                            0x60CD60
#define DrawNetStatus_x                                            0x583FC0
#define Util__FastTime_x                                           0x83BB90
#define Expansion_HoT_x                                            0xF5F824
#define __HelpPath_x                                               0xFE2F90
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A6260
#define AltAdvManager__IsAbilityReady_x                            0x4A62D0
#define AltAdvManager__GetAltAbility_x                             0x4A6690

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x452F50
#define CharacterZoneClient__MakeMeVisible_x                       0x458010

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x63A9C0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x648570

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x563A20

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x663C20
#define CChatManager__InitContextMenu_x                            0x664740

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x822880
#define CChatService__GetFriendName_x                              0x822890

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x669530
#define CChatWindow__Clear_x                                       0x6690E0
#define CChatWindow__WndNotification_x                             0x669A70

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x89B220
#define CComboWnd__Draw_x                                          0x89B400
#define CComboWnd__GetCurChoice_x                                  0x89B040
#define CComboWnd__GetListRect_x                                   0x89B6A0
#define CComboWnd__GetTextRect_x                                   0x89B280
#define CComboWnd__InsertChoice_x                                  0x89B710
#define CComboWnd__SetColors_x                                     0x89AFD0
#define CComboWnd__SetChoice_x                                     0x89B000

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x672D40
#define CContainerWnd__vftable_x                                   0xA60FE8

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x494A20
#define CDisplay__GetClickedActor_x                                0x48D4C0
#define CDisplay__GetUserDefinedColor_x                            0x48BD80
#define CDisplay__GetWorldFilePath_x                               0x48B180
#define CDisplay__is3dON_x                                         0x48A550
#define CDisplay__ReloadUI_x                                       0x49FE80
#define CDisplay__WriteTextHD2_x                                   0x490D10

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8BD000

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8ABBA0
#define CEditWnd__GetCharIndexPt_x                                 0x8ACBD0
#define CEditWnd__GetDisplayString_x                               0x8ABD50
#define CEditWnd__GetHorzOffset_x                                  0x8AC090
#define CEditWnd__GetLineForPrintableChar_x                        0x8AC690
#define CEditWnd__GetSelStartPt_x                                  0x8ACE90
#define CEditWnd__GetSTMLSafeText_x                                0x8AC230
#define CEditWnd__PointFromPrintableChar_x                         0x8AC780
#define CEditWnd__SelectableCharFromPoint_x                        0x8AC900
#define CEditWnd__SetEditable_x                                    0x8AC200

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x52AEF0
#define CEverQuest__DoTellWindow_x                                 0x530870
#define CEverQuest__DropHeldItemOnGround_x                         0x539300
#define CEverQuest__dsp_chat_x                                     0x532010
#define CEverQuest__Emote_x                                        0x532270
#define CEverQuest__EnterZone_x                                    0x545140
#define CEverQuest__GetBodyTypeDesc_x                              0x527820
#define CEverQuest__GetClassDesc_x                                 0x52D3F0
#define CEverQuest__GetClassThreeLetterCode_x                      0x52D9F0
#define CEverQuest__GetDeityDesc_x                                 0x528100
#define CEverQuest__GetLangDesc_x                                  0x527BB0
#define CEverQuest__GetRaceDesc_x                                  0x52DBB0
#define CEverQuest__InterpretCmd_x                                 0x532B50
#define CEverQuest__LeftClickedOnPlayer_x                          0x549540
#define CEverQuest__LMouseUp_x                                     0x54B830
#define CEverQuest__RightClickedOnPlayer_x                         0x54A040
#define CEverQuest__RMouseUp_x                                     0x54B080
#define CEverQuest__SetGameState_x                                 0x52B5A0
#define CEverQuest__UPCNotificationFlush_x                         0x533CF0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x683970
#define CGaugeWnd__CalcLinesFillRect_x                             0x6839D0
#define CGaugeWnd__Draw_x                                          0x683E00

// CGuild
#define CGuild__FindMemberByName_x                                 0x424860

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6A0A40

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6AE8A0
#define CInvSlotMgr__MoveItem_x                                    0x6AF7E0
#define CInvSlotMgr__SelectSlot_x                                  0x6AE950

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6ADD40
#define CInvSlot__SliderComplete_x                                 0x6AB710
#define CInvSlot__GetItemBase_x                                    0x6AAB60

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6B0990

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x778CC0
#define CItemDisplayWnd__UpdateStrings_x                           0x6B1CC0

// CLabel 
#define CLabel__Draw_x                                             0x6CCA00

// CListWnd 
#define CListWnd__AddColumn_x                                      0x889080
#define CListWnd__AddColumn1_x                                     0x888860
#define CListWnd__AddLine_x                                        0x888310
#define CListWnd__AddString_x                                      0x888520
#define CListWnd__CalculateFirstVisibleLine_x                      0x8853D0
#define CListWnd__CalculateVSBRange_x                              0x887510
#define CListWnd__ClearAllSel_x                                    0x884680
#define CListWnd__CloseAndUpdateEditWindow_x                       0x887EF0
#define CListWnd__Compare_x                                        0x885EE0
#define CListWnd__Draw_x                                           0x887170
#define CListWnd__DrawColumnSeparators_x                           0x887000
#define CListWnd__DrawHeader_x                                     0x884990
#define CListWnd__DrawItem_x                                       0x886530
#define CListWnd__DrawLine_x                                       0x886CA0
#define CListWnd__DrawSeparator_x                                  0x8870A0
#define CListWnd__EnsureVisible_x                                  0x885530
#define CListWnd__ExtendSel_x                                      0x886440
#define CListWnd__GetColumnMinWidth_x                              0x8840A0
#define CListWnd__GetColumnWidth_x                                 0x883FC0
#define CListWnd__GetCurSel_x                                      0x883790
#define CListWnd__GetItemAtPoint_x                                 0x8857D0
#define CListWnd__GetItemAtPoint1_x                                0x885840
#define CListWnd__GetItemData_x                                    0x883AD0
#define CListWnd__GetItemHeight_x                                  0x885020
#define CListWnd__GetItemIcon_x                                    0x883CB0
#define CListWnd__GetItemRect_x                                    0x885610
#define CListWnd__GetItemText_x                                    0x883B60
#define CListWnd__GetSelList_x                                     0x888750
#define CListWnd__GetSeparatorRect_x                               0x885E00
#define CListWnd__RemoveLine_x                                     0x888700
#define CListWnd__SetColors_x                                      0x8838E0
#define CListWnd__SetColumnJustification_x                         0x884370
#define CListWnd__SetColumnWidth_x                                 0x884050
#define CListWnd__SetCurSel_x                                      0x8837D0
#define CListWnd__SetItemColor_x                                   0x887BD0
#define CListWnd__SetItemData_x                                    0x884730
#define CListWnd__SetItemText_x                                    0x887A10
#define CListWnd__ShiftColumnSeparator_x                           0x8878A0
#define CListWnd__Sort_x                                           0x8891E0
#define CListWnd__ToggleSel_x                                      0x884600

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6E5D80

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x7070A0
#define CMerchantWnd__RequestBuyItem_x                             0x70DED0
#define CMerchantWnd__RequestSellItem_x                            0x736100
#define CMerchantWnd__SelectRecoverySlot_x                         0x707350
#define CMerchantWnd__SelectBuySellSlot_x                          0x7065B0
#define CMerchantWnd__ActualSelect_x                               0x70AE00

// CObfuscator
#define CObfuscator__doit_x                                        0x802C10

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8A0990
#define CSidlManager__CreateLabel_x                                0x76ECC0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x631CD0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x631BF0
#define CSidlScreenWnd__ConvertToRes_x                             0x8BCEE0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x88E200
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x88F6F0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x88F7A0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x88EC70
#define CSidlScreenWnd__DrawSidlPiece_x                            0x88DCE0
#define CSidlScreenWnd__EnableIniStorage_x                         0x88D410
#define CSidlScreenWnd__GetSidlPiece_x                             0x88DED0
#define CSidlScreenWnd__Init1_x                                    0x88F3D0
#define CSidlScreenWnd__LoadIniInfo_x                              0x88E2B0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x88D5D0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x88EEC0
#define CSidlScreenWnd__StoreIniInfo_x                             0x88CED0
#define CSidlScreenWnd__StoreIniVis_x                              0x88D3A0
#define CSidlScreenWnd__WndNotification_x                          0x88F150
#define CSidlScreenWnd__GetChildItem_x                             0x88D4E0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x894160

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5CD150
#define CSkillMgr__GetSkillCap_x                                   0x5CD2F0
#define CSkillMgr__GetNameToken_x                                  0x5CCDC0

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8C6ED0
#define CSliderWnd__SetValue_x                                     0x8C70A0
#define CSliderWnd__SetNumTicks_x                                  0x8C7820

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x776960

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8B72D0
#define CStmlWnd__CalculateHSBRange_x                              0x8AF7F0
#define CStmlWnd__CalculateVSBRange_x                              0x8AF880
#define CStmlWnd__CanBreakAtCharacter_x                            0x8AFA00
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8B02E0
#define CStmlWnd__ForceParseNow_x                                  0x8B7C20
#define CStmlWnd__GetNextTagPiece_x                                0x8B01E0
#define CStmlWnd__GetSTMLText_x                                    0x668980
#define CStmlWnd__GetVisibleText_x                                 0x8B0D30
#define CStmlWnd__InitializeWindowVariables_x                      0x8B30C0
#define CStmlWnd__MakeStmlColorTag_x                               0x8AEAF0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8AEB50
#define CStmlWnd__SetSTMLText_x                                    0x8B4930
#define CStmlWnd__StripFirstSTMLLines_x                            0x8B6F70
#define CStmlWnd__UpdateHistoryString_x                            0x8B1C70

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8BE6E0
#define CTabWnd__DrawCurrentPage_x                                 0x8BDF50
#define CTabWnd__DrawTab_x                                         0x8BDD10
#define CTabWnd__GetCurrentPage_x                                  0x8BE320
#define CTabWnd__GetPageInnerRect_x                                0x8BDA00
#define CTabWnd__GetTabInnerRect_x                                 0x8BDC00
#define CTabWnd__GetTabRect_x                                      0x8BDAD0
#define CTabWnd__InsertPage_x                                      0x8BE9D0
#define CTabWnd__SetPage_x                                         0x8BE350
#define CTabWnd__SetPageRect_x                                     0x8BE620
#define CTabWnd__UpdatePage_x                                      0x8BE970

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x420610

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8BA740

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8C3890

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x881980

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x570F60
#define CXStr__CXStr1_x                                            0x876650
#define CXStr__CXStr3_x                                            0x838C20
#define CXStr__dCXStr_x                                            0x4A7A10
#define CXStr__operator_equal_x                                    0x838D90
#define CXStr__operator_equal1_x                                   0x838DE0
#define CXStr__operator_plus_equal1_x                              0x839EC0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x893380
#define CXWnd__Center_x                                            0x899650
#define CXWnd__ClrFocus_x                                          0x892F50
#define CXWnd__DoAllDrawing_x                                      0x8992A0
#define CXWnd__DrawChildren_x                                      0x899440
#define CXWnd__DrawColoredRect_x                                   0x893740
#define CXWnd__DrawTooltip_x                                       0x8939F0
#define CXWnd__DrawTooltipAtPoint_x                                0x8981F0
#define CXWnd__GetBorderFrame_x                                    0x893E30
#define CXWnd__GetChildWndAt_x                                     0x8971A0
#define CXWnd__GetClientClipRect_x                                 0x893C00
#define CXWnd__GetScreenClipRect_x                                 0x8988F0
#define CXWnd__GetScreenRect_x                                     0x894000
#define CXWnd__GetTooltipRect_x                                    0x893880
#define CXWnd__GetWindowTextA_x                                    0x411910
#define CXWnd__IsActive_x                                          0x8A6910
#define CXWnd__IsDescendantOf_x                                    0x893D70
#define CXWnd__IsReallyVisible_x                                   0x897180
#define CXWnd__IsType_x                                            0x8C0070
#define CXWnd__Move_x                                              0x896880
#define CXWnd__Move1_x                                             0x898F40
#define CXWnd__ProcessTransition_x                                 0x893330
#define CXWnd__Refade_x                                            0x893100
#define CXWnd__Resize_x                                            0x8940C0
#define CXWnd__Right_x                                             0x8986F0
#define CXWnd__SetFocus_x                                          0x8959D0
#define CXWnd__SetFont_x                                           0x892FA0
#define CXWnd__SetKeyTooltip_x                                     0x894330
#define CXWnd__SetMouseOver_x                                      0x898C20
#define CXWnd__StartFade_x                                         0x8933D0
#define CXWnd__GetChildItem_x                                      0x898B60

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A8250
#define CXWndManager__DrawWindows_x                                0x8A7E90
#define CXWndManager__GetKeyboardFlags_x                           0x8A6440
#define CXWndManager__HandleKeyboardMsg_x                          0x8A6DB0
#define CXWndManager__RemoveWnd_x                                  0x8A6AA0

// CDBStr
#define CDBStr__GetString_x                                        0x488980

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8F7120
#define EQ_Character__CastSpell_x                                  0x43C8A0
#define EQ_Character__Cur_HP_x                                     0x452610
#define EQ_Character__GetAACastingTimeModifier_x                   0x435970
#define EQ_Character__GetCharInfo2_x                               0x80D340
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42DCC0
#define EQ_Character__GetFocusRangeModifier_x                      0x42DEA0
#define EQ_Character__Max_Endurance_x                              0x595EB0
#define EQ_Character__Max_HP_x                                     0x448920
#define EQ_Character__Max_Mana_x                                   0x595CE0
#define EQ_Character__doCombatAbility_x                            0x5932D0
#define EQ_Character__UseSkill_x                                   0x45D140
#define EQ_Character__GetConLevel_x                                0x588640
#define EQ_Character__IsExpansionFlag_x                            0x410E40
#define EQ_Character__TotalEffect_x                                0x43A9D0

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x569080
#define EQ_Item__CreateItemTagString_x                             0x7ED7F0
#define EQ_Item__IsStackable_x                                     0x7E1D40
#define EQ_Item__GetImageNum_x                                     0x7E49D0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A83A0
#define EQ_LoadingS__Array_x                                       0xB76238

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x597640
#define EQ_PC__GetAltAbilityIndex_x                                0x7F59E0
#define EQ_PC__GetCombatAbility_x                                  0x7F5A70
#define EQ_PC__GetCombatAbilityTimer_x                             0x7F5B20
#define EQ_PC__GetItemTimerValue_x                                 0x5910A0
#define EQ_PC__HasLoreItem_x                                       0x58B930
#define EQ_PC__AlertInventoryChanged_x                             0x588610
#define EQ_PC__GetPcZoneClient_x                                   0x5B1880
#define EQ_PC__RemoveMyAffect_x									   0x5905B0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E65D0
#define EQItemList__add_item_x                                     0x4E6510
#define EQItemList__delete_item_x                                  0x4E69D0
#define EQItemList__FreeItemList_x                                 0x4E68D0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487EC0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x59CAE0
#define EQPlayer__dEQPlayer_x                                      0x5A5740
#define EQPlayer__DoAttack_x                                       0x5B7670
#define EQPlayer__EQPlayer_x                                       0x5A7B90
#define EQPlayer__SetNameSpriteState_x                             0x5A24F0
#define EQPlayer__SetNameSpriteTint_x                              0x59DE70
#define EQPlayer__IsBodyType_j_x                                   0x8F63D0
#define EQPlayer__IsTargetable_x                                   0x8F6C00

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5ABE60
#define EQPlayerManager__GetSpawnByName_x                          0x5AC2C0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56F290
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56F2D0
#define KeypressHandler__ClearCommandStateArray_x                  0x56EE70
#define KeypressHandler__HandleKeyDown_x                           0x56D7C0
#define KeypressHandler__HandleKeyUp_x                             0x56DAE0
#define KeypressHandler__SaveKeymapping_x                          0x56EF40

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6DE160
#define MapViewMap__SaveEx_x                                       0x6E1A40

#define PlayerPointManager__GetAltCurrency_x                       0x807500

// StringTable 
#define StringTable__getString_x                                   0x802EB0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x595960

//Doors
#define EQSwitch__UseSwitch_x                                      0x524BB0

//IconCache
#define IconCache__GetIcon_x                                       0x6791D0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x670060
#define CContainerMgr__CloseContainer_x                            0x670870

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x73F0B0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x5624D0

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B6980
#define EQ_Spell__SpellAffects_x                                   0x4B6A20
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B6A50
#define CharacterZoneClient__CalcAffectChange_x                    0x436C90
#define CLootWnd__LootAll_x                                        0x6D3BC0
#define CTargetWnd__GetBuffCaster_x                                0x784750
