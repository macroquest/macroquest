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
#define __ExpectedVersionDate                                     "Mar 11 2014"
#define __ExpectedVersionTime                                     "14:07:00"
#define __ActualVersionDate_x                                      0xA3C068
#define __ActualVersionTime_x                                      0xA3C074

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x570230
#define __MemChecker1_x                                            0x82ECF0
#define __MemChecker2_x                                            0x6062A0
#define __MemChecker3_x                                            0x6061F0
#define __MemChecker4_x                                            0x7B40F0
#define __EncryptPad0_x                                            0xBA28D0
#define __EncryptPad1_x                                            0xD18D88
#define __EncryptPad2_x                                            0xBE8FB8
#define __EncryptPad3_x                                            0xBE8BB8
#define __EncryptPad4_x                                            0xCF6E18
#define __AC1_x                                                    0x771C75
#define __AC2_x                                                    0x526EB7
#define __AC3_x                                                    0x53B310
#define __AC4_x                                                    0x541340
#define __AC5_x                                                    0x54D901
#define __AC6_x                                                    0x5513D2
#define __AC7_x                                                    0x54740C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10C74C8
#define DI8__Keyboard_x                                            0x10C74CC
#define DI8__Mouse_x                                               0x10C74D0
#define __AltTimerReady_x                                          0xF27291
#define __Attack_x                                                 0xFBA072
#define __Autofire_x                                               0xFBA073
#define __BindList_x                                               0xB673F0
#define __Clicks_x                                                 0xF35ED0
#define __CommandList_x                                            0xB6B460
#define __CurrentMapLabel_x                                        0x10CD148
#define __CurrentSocial_x                                          0xB2D8AC
#define __DoAbilityList_x                                          0xF6C620
#define __do_loot_x                                                0x4EFBE0
#define __DrawHandler_x                                            0x172F6AC
#define __GroupCount_x                                             0xF2696A

#define __Guilds_x                                                 0xF2C450
#define __gWorld_x                                                 0xF28E24
#define __HotkeyPage_x                                             0xFB3020
#define __HWnd_x                                                   0xFBF3D0
#define __InChatMode_x                                             0xF35DFC
#define __LastTell_x                                               0xF37D28
#define __LMouseHeldTime_x                                         0xF35F3C
#define __Mouse_x                                                  0x10C74D4
#define __MouseLook_x                                              0xF35E96
#define __MouseEventTime_x                                         0xFBA85C
#define __NetStatusToggle_x                                        0xF35E99
#define __PCNames_x                                                0xF3736C
#define __RangeAttackReady_x                                       0xF37008
#define __RMouseHeldTime_x                                         0xF35F38
#define __RunWalkState_x                                           0xF35E00
#define __ScreenMode_x                                             0xE75370
#define __ScreenX_x                                                0xF35DB4
#define __ScreenY_x                                                0xF35DB0
#define __ScreenXMax_x                                             0xF35DB8
#define __ScreenYMax_x                                             0xF35DBC
#define __ServerHost_x                                             0xF268B4
#define __ServerName_x                                             0xF6C5E0
#define __ShiftKeyDown_x                                           0xF3649C
#define __ShowNames_x                                              0xF37210
#define __Socials_x                                                0xF6C6E0
#define __SubscriptionType_x                                       0x10F6E78
#define __TargetAggroHolder_x                                      0x10CF360
#define __GroupAggro_x                                             0x10CF3A0
#define __LoginName_x                                              0xFBDFA8


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF28F08
#define instEQZoneInfo_x                                           0xF3608C
#define instKeypressHandler_x                                      0xFBA840
#define pinstActiveBanker_x                                        0xF28EC8
#define pinstActiveCorpse_x                                        0xF28ECC
#define pinstActiveGMaster_x                                       0xF28ED0
#define pinstActiveMerchant_x                                      0xF28EC4
#define pinstAggroInfo_x                                           0xD39958
#define pinstAltAdvManager_x                                       0xE76438
#define pinstAuraMgr_x                                             0xD43820
#define pinstBandageTarget_x                                       0xF28EB0
#define pinstCamActor_x                                            0xE75D44
#define pinstCDBStr_x                                              0xE75304
#define pinstCDisplay_x                                            0xF28ED8
#define pinstCEverQuest_x                                          0x10C764C
#define pinstCharData_x                                            0xF28E94
#define pinstCharSpawn_x                                           0xF28EBC
#define pinstControlledMissile_x                                   0xF28E90
#define pinstControlledPlayer_x                                    0xF28EBC
#define pinstCSidlManager_x                                        0x172EB18
#define pinstCXWndManager_x                                        0x172EB10
#define instDynamicZone_x                                          0xF35C48
#define pinstDZMember_x                                            0xF35D58
#define pinstDZTimerInfo_x                                         0xF35D5C
#define pinstEQItemList_x                                          0xF255EC
#define instEQMisc_x                                               0xB48D60
#define pinstEQSoundManager_x                                      0xE76738
#define instExpeditionLeader_x                                     0xF35C92
#define instExpeditionName_x                                       0xF35CD2
#define pinstGroup_x                                               0xF26966
#define pinstImeManager_x                                          0x172EB1C
#define pinstLocalPlayer_x                                         0xF28EA8
#define pinstMercenaryData_x                                       0xFBAE90
#define pinstMercAltAbilities_x                                    0xE76658
#define pinstModelPlayer_x                                         0xF28ED4
#define pinstPCData_x                                              0xF28E94
#define pinstSkillMgr_x                                            0xFBBCC8
#define pinstSpawnManager_x                                        0xFBB5B0
#define pinstSpellManager_x                                        0xFBBE10
#define pinstSpellSets_x                                           0xFB3084
#define pinstStringTable_x                                         0xF28E3C
#define pinstSwitchManager_x                                       0xF264F8
#define pinstTarget_x                                              0xF28EC0
#define pinstTargetObject_x                                        0xF28E98
#define pinstTargetSwitch_x                                        0xF28E9C
#define pinstTaskMember_x                                          0xE75250
#define pinstTrackTarget_x                                         0xF28EB4
#define pinstTradeTarget_x                                         0xF28EA4
#define instTributeActive_x                                        0xB48D85
#define pinstViewActor_x                                           0xE75D40
#define pinstWorldData_x                                           0xF28E78


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD39E38
#define pinstCAudioTriggersWindow_x                                0xD39CC8
#define pinstCCharacterSelect_x                                    0xE75BEC
#define pinstCFacePick_x                                           0xE7599C
#define pinstCNoteWnd_x                                            0xE75BA4
#define pinstCBookWnd_x                                            0xE75BAC
#define pinstCPetInfoWnd_x                                         0xE75BB0
#define pinstCTrainWnd_x                                           0xE75BB4
#define pinstCSkillsWnd_x                                          0xE75BB8
#define pinstCSkillsSelectWnd_x                                    0xE75BBC
#define pinstCCombatSkillSelectWnd_x                               0xE75BC0
#define pinstCFriendsWnd_x                                         0xE75BC4
#define pinstCAuraWnd_x                                            0xE75BC8
#define pinstCRespawnWnd_x                                         0xE75BCC
#define pinstCBandolierWnd_x                                       0xE75BD0
#define pinstCPotionBeltWnd_x                                      0xE75BD4
#define pinstCAAWnd_x                                              0xE75BD8
#define pinstCGroupSearchFiltersWnd_x                              0xE75BDC
#define pinstCLoadskinWnd_x                                        0xE75BE0
#define pinstCAlarmWnd_x                                           0xE75BE4
#define pinstCMusicPlayerWnd_x                                     0xE75BE8
#define pinstCMailWnd_x                                            0xE75BF0
#define pinstCMailCompositionWnd_x                                 0xE75BF4
#define pinstCMailAddressBookWnd_x                                 0xE75BF8
#define pinstCRaidWnd_x                                            0xE75C00
#define pinstCRaidOptionsWnd_x                                     0xE75C04
#define pinstCBreathWnd_x                                          0xE75C08
#define pinstCMapViewWnd_x                                         0xE75C0C
#define pinstCMapToolbarWnd_x                                      0xE75C10
#define pinstCEditLabelWnd_x                                       0xE75C14
#define pinstCTargetWnd_x                                          0xE75C18
#define pinstCColorPickerWnd_x                                     0xE75C1C
#define pinstCPlayerWnd_x                                          0xE75C20
#define pinstCOptionsWnd_x                                         0xE75C24
#define pinstCBuffWindowNORMAL_x                                   0xE75C28
#define pinstCBuffWindowSHORT_x                                    0xE75C2C
#define pinstCharacterCreation_x                                   0xE75C30
#define pinstCCursorAttachment_x                                   0xE75C34
#define pinstCCastingWnd_x                                         0xE75C38
#define pinstCCastSpellWnd_x                                       0xE75C3C
#define pinstCSpellBookWnd_x                                       0xE75C40
#define pinstCInventoryWnd_x                                       0xE75C44
#define pinstCBankWnd_x                                            0xE75C48
#define pinstCQuantityWnd_x                                        0xE75C4C
#define pinstCLootWnd_x                                            0xE75C50
#define pinstCActionsWnd_x                                         0xE75C54
#define pinstCCombatAbilityWnd_x                                   0xE75C58
#define pinstCMerchantWnd_x                                        0xE75C5C
#define pinstCTradeWnd_x                                           0xE75C60
#define pinstCSelectorWnd_x                                        0xE75C64
#define pinstCBazaarWnd_x                                          0xE75C68
#define pinstCBazaarSearchWnd_x                                    0xE75C6C
#define pinstCGiveWnd_x                                            0xE75C88
#define pinstCTrackingWnd_x                                        0xE75C90
#define pinstCInspectWnd_x                                         0xE75C94
#define pinstCSocialEditWnd_x                                      0xE75C98
#define pinstCFeedbackWnd_x                                        0xE75C9C
#define pinstCBugReportWnd_x                                       0xE75CA0
#define pinstCVideoModesWnd_x                                      0xE75CA4
#define pinstCTextEntryWnd_x                                       0xE75CAC
#define pinstCFileSelectionWnd_x                                   0xE75CB0
#define pinstCCompassWnd_x                                         0xE75CB4
#define pinstCPlayerNotesWnd_x                                     0xE75CB8
#define pinstCGemsGameWnd_x                                        0xE75CBC
#define pinstCTimeLeftWnd_x                                        0xE75CC0
#define pinstCPetitionQWnd_x                                       0xE75CD4
#define pinstCSoulmarkWnd_x                                        0xE75CD8
#define pinstCStoryWnd_x                                           0xE75CDC
#define pinstCJournalTextWnd_x                                     0xE75CE0
#define pinstCJournalCatWnd_x                                      0xE75CE4
#define pinstCBodyTintWnd_x                                        0xE75CE8
#define pinstCServerListWnd_x                                      0xE75CEC
#define pinstCAvaZoneWnd_x                                         0xE75CF8
#define pinstCBlockedBuffWnd_x                                     0xE75CFC
#define pinstCBlockedPetBuffWnd_x                                  0xE75D00
#define pinstCInvSlotMgr_x                                         0xE75D38
#define pinstCContainerMgr_x                                       0xE75D3C
#define pinstCAdventureLeaderboardWnd_x                            0x10C8220
#define pinstCAdventureRequestWnd_x                                0x10C8298
#define pinstCAltStorageWnd_x                                      0x10C8578
#define pinstCAdventureStatsWnd_x                                  0x10C8310
#define pinstCBarterMerchantWnd_x                                  0x10C9160
#define pinstCBarterSearchWnd_x                                    0x10C91D8
#define pinstCBarterWnd_x                                          0x10C9250
#define pinstCChatManager_x                                        0x10C98E0
#define pinstCDynamicZoneWnd_x                                     0x10C9D90
#define pinstCEQMainWnd_x                                          0x10C9F28
#define pinstCFellowshipWnd_x                                      0x10C9D24
#define pinstCFindLocationWnd_x                                    0x10CA1F8
#define pinstCGroupSearchWnd_x                                     0x10CA4C8
#define pinstCGroupWnd_x                                           0x10CA540
#define pinstCGuildBankWnd_x                                       0x10CA5B8
#define pinstCGuildMgmtWnd_x                                       0x10CC6A8
#define pinstCHotButtonWnd_x                                       0x10CC774
#define pinstCHotButtonWnd1_x                                      0x10CC774
#define pinstCHotButtonWnd2_x                                      0x10CC778
#define pinstCHotButtonWnd3_x                                      0x10CC77C
#define pinstCHotButtonWnd4_x                                      0x10CC7A0
#define pinstCItemDisplayManager_x                                 0x10CCA98
#define pinstCItemExpTransferWnd_x                                 0x10CCB14
#define pinstCLFGuildWnd_x                                         0x10CCDF0
#define pinstCMIZoneSelectWnd_x                                    0x10CD3D8
#define pinstCConfirmationDialog_x                                 0x10CDAE0
#define pinstCPopupWndManager_x                                    0x10CDAE0
#define pinstCProgressionSelectionWnd_x                            0x10CDBD0
#define pinstCPvPStatsWnd_x                                        0x10CDCC0
#define pinstCSystemInfoDialogBox_x                                0x10CE3C8
#define pinstCTaskWnd_x                                            0x10CF758
#define pinstCTaskTemplateSelectWnd_x                              0x10CF6E0
#define pinstCTipWndOFDAY_x                                        0x10CF9B0
#define pinstCTipWndCONTEXT_x                                      0x10CF9B4
#define pinstCTitleWnd_x                                           0x10CFA30
#define pinstCContextMenuManager_x                                 0x172E72C
#define pinstCVoiceMacroWnd_x                                      0xFBC478
#define pinstCHtmlWnd_x                                            0xFBC570
#define pinstIconCache_x                                           0x10C9EFC
#define pinstCTradeskillWnd_x                                      0x10CFB30

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x5066A0
#define __ConvertItemTags_x                                        0x4F48F0
#define __ExecuteCmd_x                                             0x4DF890
#define __EQGetTime_x                                              0x82F850
#define __get_melee_range_x                                        0x4E6440
#define __GetGaugeValueFromEQ_x                                    0x7709D0
#define __GetLabelFromEQ_x                                         0x771C00
#define __GetXTargetType_x                                         0x8EBED0
#define __LoadFrontEnd_x                                           0x605950
#define __NewUIINI_x                                               0x770300
#define __ProcessGameEvents_x                                      0x549550
#define CrashDetected_x                                            0x60B0B0
#define DrawNetStatus_x                                            0x57F740
#define Util__FastTime_x                                           0x82EB90
#define Expansion_HoT_x                                            0xF37170
#define __HelpPath_x                                               0xFBA5C8
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A50B0
#define AltAdvManager__IsAbilityReady_x                            0x4A5120
#define AltAdvManager__GetAltAbility_x                             0x4A54E0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x4522D0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x6358F0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6436B0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x55FAE0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x65E9C0
#define CChatManager__InitContextMenu_x                            0x65F4E0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x8158B0
#define CChatService__GetFriendName_x                              0x8158C0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x664220
#define CChatWindow__Clear_x                                       0x663DD0
#define CChatWindow__WndNotification_x                             0x664760

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x88DE40
#define CComboWnd__Draw_x                                          0x88E020
#define CComboWnd__GetCurChoice_x                                  0x88DC60
#define CComboWnd__GetListRect_x                                   0x88E2C0
#define CComboWnd__GetTextRect_x                                   0x88DEA0
#define CComboWnd__InsertChoice_x                                  0x88E330
#define CComboWnd__SetColors_x                                     0x88DBF0
#define CComboWnd__SetChoice_x                                     0x88DC20

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x66D890
#define CContainerWnd__vftable_x                                   0xA44BE0

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x493A60
#define CDisplay__GetClickedActor_x                                0x48C690
#define CDisplay__GetUserDefinedColor_x                            0x48AF50
#define CDisplay__GetWorldFilePath_x                               0x48A350
#define CDisplay__is3dON_x                                         0x489720
#define CDisplay__ReloadUI_x                                       0x49EE30
#define CDisplay__WriteTextHD2_x                                   0x48FEE0

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8AF890

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x89E840
#define CEditWnd__GetCharIndexPt_x                                 0x89F870
#define CEditWnd__GetDisplayString_x                               0x89E9F0
#define CEditWnd__GetHorzOffset_x                                  0x89ED30
#define CEditWnd__GetLineForPrintableChar_x                        0x89F330
#define CEditWnd__GetSelStartPt_x                                  0x89FB30
#define CEditWnd__GetSTMLSafeText_x                                0x89EED0
#define CEditWnd__PointFromPrintableChar_x                         0x89F420
#define CEditWnd__SelectableCharFromPoint_x                        0x89F5A0
#define CEditWnd__SetEditable_x                                    0x89EEA0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x527600
#define CEverQuest__DoTellWindow_x                                 0x52CD70
#define CEverQuest__DropHeldItemOnGround_x                         0x535810
#define CEverQuest__dsp_chat_x                                     0x52E510
#define CEverQuest__Emote_x                                        0x52E770
#define CEverQuest__EnterZone_x                                    0x5414D0
#define CEverQuest__GetBodyTypeDesc_x                              0x524000
#define CEverQuest__GetClassDesc_x                                 0x5298E0
#define CEverQuest__GetClassThreeLetterCode_x                      0x529EE0
#define CEverQuest__GetDeityDesc_x                                 0x5248E0
#define CEverQuest__GetLangDesc_x                                  0x524390
#define CEverQuest__GetRaceDesc_x                                  0x52A0A0
#define CEverQuest__InterpretCmd_x                                 0x52F050
#define CEverQuest__LeftClickedOnPlayer_x                          0x545880
#define CEverQuest__LMouseUp_x                                     0x547B70
#define CEverQuest__RightClickedOnPlayer_x                         0x546380
#define CEverQuest__RMouseUp_x                                     0x5473C0
#define CEverQuest__SetGameState_x                                 0x527CB0
#define CEverQuest__UPCNotificationFlush_x                         0x5301F0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x67E250
#define CGaugeWnd__CalcLinesFillRect_x                             0x67E2B0
#define CGaugeWnd__Draw_x                                          0x67E6E0

// CGuild
#define CGuild__FindMemberByName_x                                 0x424310

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69AB10

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6A68C0
#define CInvSlotMgr__MoveItem_x                                    0x6A7800
#define CInvSlotMgr__SelectSlot_x                                  0x6A6970

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6A5BF0
#define CInvSlot__SliderComplete_x                                 0x6A3A40
#define CInvSlot__GetItemBase_x                                    0x6A2EC0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6A85D0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x76D610
#define CItemDisplayWnd__UpdateStrings_x                           0x6A9900

// CLabel 
#define CLabel__Draw_x                                             0x6C4180

// CListWnd 
#define CListWnd__AddColumn_x                                      0x87BD40
#define CListWnd__AddColumn1_x                                     0x87B520
#define CListWnd__AddLine_x                                        0x87AFD0
#define CListWnd__AddString_x                                      0x87B1E0
#define CListWnd__CalculateFirstVisibleLine_x                      0x878090
#define CListWnd__CalculateVSBRange_x                              0x87A1C0
#define CListWnd__ClearAllSel_x                                    0x877350
#define CListWnd__CloseAndUpdateEditWindow_x                       0x87ABA0
#define CListWnd__Compare_x                                        0x878B90
#define CListWnd__Draw_x                                           0x879E20
#define CListWnd__DrawColumnSeparators_x                           0x879CB0
#define CListWnd__DrawHeader_x                                     0x877660
#define CListWnd__DrawItem_x                                       0x8791E0
#define CListWnd__DrawLine_x                                       0x879950
#define CListWnd__DrawSeparator_x                                  0x879D50
#define CListWnd__EnsureVisible_x                                  0x8781F0
#define CListWnd__ExtendSel_x                                      0x8790F0
#define CListWnd__GetColumnMinWidth_x                              0x876D70
#define CListWnd__GetColumnWidth_x                                 0x876C90
#define CListWnd__GetCurSel_x                                      0x876560
#define CListWnd__GetItemAtPoint_x                                 0x878490
#define CListWnd__GetItemAtPoint1_x                                0x878500
#define CListWnd__GetItemData_x                                    0x8767A0
#define CListWnd__GetItemHeight_x                                  0x877CF0
#define CListWnd__GetItemIcon_x                                    0x876980
#define CListWnd__GetItemRect_x                                    0x8782D0
#define CListWnd__GetItemText_x                                    0x876830
#define CListWnd__GetSelList_x                                     0x87B410
#define CListWnd__GetSeparatorRect_x                               0x878AC0
#define CListWnd__RemoveLine_x                                     0x87B3C0
#define CListWnd__SetColors_x                                      0x8765C0
#define CListWnd__SetColumnJustification_x                         0x877040
#define CListWnd__SetColumnWidth_x                                 0x876D20
#define CListWnd__SetCurSel_x                                      0x8765A0
#define CListWnd__SetItemColor_x                                   0x87A880
#define CListWnd__SetItemData_x                                    0x877400
#define CListWnd__SetItemText_x                                    0x87A6C0
#define CListWnd__ShiftColumnSeparator_x                           0x87A550
#define CListWnd__Sort_x                                           0x87BEAD
#define CListWnd__ToggleSel_x                                      0x8772D0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6DD360

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6FD5B0
#define CMerchantWnd__RequestBuyItem_x                             0x703B80
#define CMerchantWnd__RequestSellItem_x                            0x72AF90
#define CMerchantWnd__SelectRecoverySlot_x                         0x6FD860
#define CMerchantWnd__SelectBuySellSlot_x                          0x6FCA70
#define CMerchantWnd__ActualSelect_x                               0x700FE0

// CObfuscator
#define CObfuscator__doit_x                                        0x7F62C0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8936A0
#define CSidlManager__CreateLabel_x                                0x763AE0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x62CAC0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x62C9E0
#define CSidlScreenWnd__ConvertToRes_x                             0x8AF770
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x880E70
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x882370
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x882420
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8818E0
#define CSidlScreenWnd__DrawSidlPiece_x                            0x880950
#define CSidlScreenWnd__EnableIniStorage_x                         0x880090
#define CSidlScreenWnd__GetSidlPiece_x                             0x880B40
#define CSidlScreenWnd__Init1_x                                    0x882040
#define CSidlScreenWnd__LoadIniInfo_x                              0x880F20
#define CSidlScreenWnd__LoadIniListWnd_x                           0x880250
#define CSidlScreenWnd__LoadSidlScreen_x                           0x881B30
#define CSidlScreenWnd__StoreIniInfo_x                             0x87FB50
#define CSidlScreenWnd__StoreIniVis_x                              0x880020
#define CSidlScreenWnd__WndNotification_x                          0x881DC0
#define CSidlScreenWnd__GetChildItem_x                             0x880160
#define CSidlScreenWnd__HandleLButtonUp_x                          0x886DE0

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5C79F0
#define CSkillMgr__GetSkillCap_x                                   0x5C7B90

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8B9790
#define CSliderWnd__SetValue_x                                     0x8B9960
#define CSliderWnd__SetNumTicks_x                                  0x8BA0E0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x76B2B0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8A9EF0
#define CStmlWnd__CalculateHSBRange_x                              0x8A2550
#define CStmlWnd__CalculateVSBRange_x                              0x8A25E0
#define CStmlWnd__CanBreakAtCharacter_x                            0x8A2760
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8A3040
#define CStmlWnd__ForceParseNow_x                                  0x8AA840
#define CStmlWnd__GetNextTagPiece_x                                0x8A2F40
#define CStmlWnd__GetSTMLText_x                                    0x663670
#define CStmlWnd__GetVisibleText_x                                 0x8A3A90
#define CStmlWnd__InitializeWindowVariables_x                      0x8A5D20
#define CStmlWnd__MakeStmlColorTag_x                               0x8A1730
#define CStmlWnd__MakeWndNotificationTag_x                         0x8A1790
#define CStmlWnd__SetSTMLText_x                                    0x8A7580
#define CStmlWnd__StripFirstSTMLLines_x                            0x8A9B90
#define CStmlWnd__UpdateHistoryString_x                            0x8A49C0

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8B0F80
#define CTabWnd__DrawCurrentPage_x                                 0x8B07F0
#define CTabWnd__DrawTab_x                                         0x8B05B0
#define CTabWnd__GetCurrentPage_x                                  0x8B0BC0
#define CTabWnd__GetPageInnerRect_x                                0x8B02A0
#define CTabWnd__GetTabInnerRect_x                                 0x8B04A0
#define CTabWnd__GetTabRect_x                                      0x8B0370
#define CTabWnd__InsertPage_x                                      0x8B1270
#define CTabWnd__SetPage_x                                         0x8B0BF0
#define CTabWnd__SetPageRect_x                                     0x8B0EC0
#define CTabWnd__UpdatePage_x                                      0x8B1210

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41FFE0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8AD340

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8B6150

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8745D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x411600
#define CXStr__CXStr1_x                                            0x869CD0
#define CXStr__CXStr3_x                                            0x82BC20
#define CXStr__dCXStr_x                                            0x41D3C0
#define CXStr__operator_equal_x                                    0x82BD90
#define CXStr__operator_equal1_x                                   0x82BDE0
#define CXStr__operator_plus_equal1_x                              0x82CEC0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x885FF0
#define CXWnd__Center_x                                            0x88C280
#define CXWnd__ClrFocus_x                                          0x885BB0
#define CXWnd__DoAllDrawing_x                                      0x88BED0
#define CXWnd__DrawChildren_x                                      0x88C070
#define CXWnd__DrawColoredRect_x                                   0x8863B0
#define CXWnd__DrawTooltip_x                                       0x886650
#define CXWnd__DrawTooltipAtPoint_x                                0x88AE40
#define CXWnd__GetBorderFrame_x                                    0x886AA0
#define CXWnd__GetChildWndAt_x                                     0x889E00
#define CXWnd__GetClientClipRect_x                                 0x886870
#define CXWnd__GetScreenClipRect_x                                 0x88B540
#define CXWnd__GetScreenRect_x                                     0x886C70
#define CXWnd__GetTooltipRect_x                                    0x8864E0
#define CXWnd__GetWindowTextA_x                                    0x411640
#define CXWnd__IsActive_x                                          0x8995B0
#define CXWnd__IsDescendantOf_x                                    0x8869E0
#define CXWnd__IsReallyVisible_x                                   0x889DE0
#define CXWnd__IsType_x                                            0x8B2940
#define CXWnd__Move_x                                              0x8894C0
#define CXWnd__Move1_x                                             0x88BB70
#define CXWnd__ProcessTransition_x                                 0x885F90
#define CXWnd__Refade_x                                            0x885D60
#define CXWnd__Resize_x                                            0x886D40
#define CXWnd__Right_x                                             0x88B340
#define CXWnd__SetFocus_x                                          0x888610
#define CXWnd__SetFont_x                                           0x885C00
#define CXWnd__SetKeyTooltip_x                                     0x886FB0
#define CXWnd__SetMouseOver_x                                      0x88B850
#define CXWnd__StartFade_x                                         0x886040
#define CXWnd__GetChildItem_x                                      0x88B790

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x89AEF0
#define CXWndManager__DrawWindows_x                                0x89AB30
#define CXWndManager__GetKeyboardFlags_x                           0x8990E0
#define CXWndManager__HandleKeyboardMsg_x                          0x899A50
#define CXWndManager__RemoveWnd_x                                  0x899740

// CDBStr
#define CDBStr__GetString_x                                        0x487B90

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8E87C0
#define EQ_Character__CastSpell_x                                  0x43BC00
#define EQ_Character__Cur_HP_x                                     0x451990
#define EQ_Character__GetAACastingTimeModifier_x                   0x434D60
#define EQ_Character__GetCharInfo2_x                               0x800500
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42D1B0
#define EQ_Character__GetFocusRangeModifier_x                      0x42D390
#define EQ_Character__Max_Endurance_x                              0x5910F0
#define EQ_Character__Max_HP_x                                     0x447C70
#define EQ_Character__Max_Mana_x                                   0x590F20
#define EQ_Character__doCombatAbility_x                            0x58E750
#define EQ_Character__UseSkill_x                                   0x45C4D0
#define EQ_Character__GetConLevel_x                                0x583D90
#define EQ_Character__IsExpansionFlag_x                            0x410B50
#define EQ_Character__TotalEffect_x                                0x439D30

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x564B00
#define EQ_Item__CreateItemTagString_x                             0x7E1480
#define EQ_Item__IsStackable_x                                     0x7D5A60
#define EQ_Item__GetImageNum_x                                     0x7D86F0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A7190
#define EQ_LoadingS__Array_x                                       0xB562F8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x592750
#define EQ_PC__GetAltAbilityIndex_x                                0x7E9580
#define EQ_PC__GetCombatAbility_x                                  0x7E9610
#define EQ_PC__GetCombatAbilityTimer_x                             0x7E96C0
#define EQ_PC__GetItemTimerValue_x                                 0x58C520
#define EQ_PC__HasLoreItem_x                                       0x586F40
#define EQ_PC__AlertInventoryChanged_x                             0x583D60

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E4400
#define EQItemList__add_item_x                                     0x4E4340
#define EQItemList__delete_item_x                                  0x4E4800
#define EQItemList__FreeItemList_x                                 0x4E4700

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x486FA0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x597D70
#define EQPlayer__dEQPlayer_x                                      0x5A08A0
#define EQPlayer__DoAttack_x                                       0x5B1D40
#define EQPlayer__EQPlayer_x                                       0x5A2D30
#define EQPlayer__SetNameSpriteState_x                             0x59D650
#define EQPlayer__SetNameSpriteTint_x                              0x5990A0
#define EQPlayer__IsBodyType_j_x                                   0x8E7AD0
#define EQPlayer__IsTargetable_x                                   0x8E82A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5A66E0
#define EQPlayerManager__GetSpawnByName_x                          0x5A6B40

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56ACE0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56AD20
#define KeypressHandler__ClearCommandStateArray_x                  0x56A8C0
#define KeypressHandler__HandleKeyDown_x                           0x569200
#define KeypressHandler__HandleKeyUp_x                             0x569520
#define KeypressHandler__SaveKeymapping_x                          0x56A990

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6D5780
#define MapViewMap__SaveEx_x                                       0x6D9060

#define PlayerPointManager__GetAltCurrency_x                       0x7FA6C0

// StringTable 
#define StringTable__getString_x                                   0x7F6560

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x590BA0

//Doors
#define EQSwitch__UseSwitch_x                                      0x521390

//IconCache
#define IconCache__GetIcon_x                                       0x673B70

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66ABC0
#define CContainerMgr__CloseContainer_x                            0x66B3D0

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x733E40

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x55E5C0
