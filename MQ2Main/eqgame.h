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
#define __ExpectedVersionDate                                     "Mar 12 2014"
#define __ExpectedVersionTime                                     "18:39:01"
#define __ActualVersionDate_x                                      0xA3C068
#define __ActualVersionTime_x                                      0xA3C074

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x5702B0
#define __MemChecker1_x                                            0x82EE50
#define __MemChecker2_x                                            0x606370
#define __MemChecker3_x                                            0x6062C0
#define __MemChecker4_x                                            0x7B4260
#define __EncryptPad0_x                                            0xBA28D0
#define __EncryptPad1_x                                            0xD18D88
#define __EncryptPad2_x                                            0xBE8FB8
#define __EncryptPad3_x                                            0xBE8BB8
#define __EncryptPad4_x                                            0xCF6E18
#define __AC1_x                                                    0x771DD5
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
#define __Inviter_x                                                0xFB9FF0


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
#define __EQGetTime_x                                              0x82F9C0
#define __get_melee_range_x                                        0x4E6440
#define __GetGaugeValueFromEQ_x                                    0x770B30
#define __GetLabelFromEQ_x                                         0x771D60
#define __GetXTargetType_x                                         0x8EC070
#define __LoadFrontEnd_x                                           0x605A20
#define __NewUIINI_x                                               0x770460
#define __ProcessGameEvents_x                                      0x549550
#define CrashDetected_x                                            0x60B180
#define DrawNetStatus_x                                            0x57F7C0
#define Util__FastTime_x                                           0x82ECF0
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
#define CBankWnd__GetNumBankSlots_x                                0x635A00

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x6437C0

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x55FB60

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x65EAF0
#define CChatManager__InitContextMenu_x                            0x65F610

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x815A30
#define CChatService__GetFriendName_x                              0x815A40

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x664350
#define CChatWindow__Clear_x                                       0x663F00
#define CChatWindow__WndNotification_x                             0x664890

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x88DFE0
#define CComboWnd__Draw_x                                          0x88E1C0
#define CComboWnd__GetCurChoice_x                                  0x88DE00
#define CComboWnd__GetListRect_x                                   0x88E460
#define CComboWnd__GetTextRect_x                                   0x88E040
#define CComboWnd__InsertChoice_x                                  0x88E4D0
#define CComboWnd__SetColors_x                                     0x88DD90
#define CComboWnd__SetChoice_x                                     0x88DDC0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x66D9C0
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
#define CEditBaseWnd__SetSel_x                                     0x8AFA30

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x89E9E0
#define CEditWnd__GetCharIndexPt_x                                 0x89FA10
#define CEditWnd__GetDisplayString_x                               0x89EB90
#define CEditWnd__GetHorzOffset_x                                  0x89EED0
#define CEditWnd__GetLineForPrintableChar_x                        0x89F4D0
#define CEditWnd__GetSelStartPt_x                                  0x89FCD0
#define CEditWnd__GetSTMLSafeText_x                                0x89F070
#define CEditWnd__PointFromPrintableChar_x                         0x89F5C0
#define CEditWnd__SelectableCharFromPoint_x                        0x89F740
#define CEditWnd__SetEditable_x                                    0x89F040

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
#define CGaugeWnd__CalcFillRect_x                                  0x67E380
#define CGaugeWnd__CalcLinesFillRect_x                             0x67E3E0
#define CGaugeWnd__Draw_x                                          0x67E810

// CGuild
#define CGuild__FindMemberByName_x                                 0x424310

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69AC70

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6A6A10
#define CInvSlotMgr__MoveItem_x                                    0x6A7950
#define CInvSlotMgr__SelectSlot_x                                  0x6A6AC0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6A5D40
#define CInvSlot__SliderComplete_x                                 0x6A3B90
#define CInvSlot__GetItemBase_x                                    0x6A3010

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6A8720

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x76D780
#define CItemDisplayWnd__UpdateStrings_x                           0x6A9A60

// CLabel 
#define CLabel__Draw_x                                             0x6C42E0

// CListWnd 
#define CListWnd__AddColumn_x                                      0x87BEC0
#define CListWnd__AddColumn1_x                                     0x87B6A0
#define CListWnd__AddLine_x                                        0x87B150
#define CListWnd__AddString_x                                      0x87B360
#define CListWnd__CalculateFirstVisibleLine_x                      0x878210
#define CListWnd__CalculateVSBRange_x                              0x87A340
#define CListWnd__ClearAllSel_x                                    0x8774D0
#define CListWnd__CloseAndUpdateEditWindow_x                       0x87AD20
#define CListWnd__Compare_x                                        0x878D10
#define CListWnd__Draw_x                                           0x879FA0
#define CListWnd__DrawColumnSeparators_x                           0x879E30
#define CListWnd__DrawHeader_x                                     0x8777E0
#define CListWnd__DrawItem_x                                       0x879360
#define CListWnd__DrawLine_x                                       0x879AD0
#define CListWnd__DrawSeparator_x                                  0x879ED0
#define CListWnd__EnsureVisible_x                                  0x878370
#define CListWnd__ExtendSel_x                                      0x879270
#define CListWnd__GetColumnMinWidth_x                              0x876EF0
#define CListWnd__GetColumnWidth_x                                 0x876E10
#define CListWnd__GetCurSel_x                                      0x8766E0
#define CListWnd__GetItemAtPoint_x                                 0x878610
#define CListWnd__GetItemAtPoint1_x                                0x878680
#define CListWnd__GetItemData_x                                    0x876920
#define CListWnd__GetItemHeight_x                                  0x877E70
#define CListWnd__GetItemIcon_x                                    0x876B00
#define CListWnd__GetItemRect_x                                    0x878450
#define CListWnd__GetItemText_x                                    0x8769B0
#define CListWnd__GetSelList_x                                     0x87B590
#define CListWnd__GetSeparatorRect_x                               0x878C40
#define CListWnd__RemoveLine_x                                     0x87B540
#define CListWnd__SetColors_x                                      0x876740
#define CListWnd__SetColumnJustification_x                         0x8771C0
#define CListWnd__SetColumnWidth_x                                 0x876EA0
#define CListWnd__SetCurSel_x                                      0x876720
#define CListWnd__SetItemColor_x                                   0x87AA00
#define CListWnd__SetItemData_x                                    0x877580
#define CListWnd__SetItemText_x                                    0x87A840
#define CListWnd__ShiftColumnSeparator_x                           0x87A6D0
#define CListWnd__Sort_x                                           0x87C02D
#define CListWnd__ToggleSel_x                                      0x877450

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6DD4B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x6FD6D0
#define CMerchantWnd__RequestBuyItem_x                             0x703CA0
#define CMerchantWnd__RequestSellItem_x                            0x72B0C0
#define CMerchantWnd__SelectRecoverySlot_x                         0x6FD980
#define CMerchantWnd__SelectBuySellSlot_x                          0x6FCB90
#define CMerchantWnd__ActualSelect_x                               0x701100

// CObfuscator
#define CObfuscator__doit_x                                        0x7F6420

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x893840
#define CSidlManager__CreateLabel_x                                0x763C30

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x62CBC0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x62CAE0
#define CSidlScreenWnd__ConvertToRes_x                             0x8AF910
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x881010
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x882510
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8825C0
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x881A80
#define CSidlScreenWnd__DrawSidlPiece_x                            0x880AF0
#define CSidlScreenWnd__EnableIniStorage_x                         0x880230
#define CSidlScreenWnd__GetSidlPiece_x                             0x880CE0
#define CSidlScreenWnd__Init1_x                                    0x8821E0
#define CSidlScreenWnd__LoadIniInfo_x                              0x8810C0
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8803F0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x881CD0
#define CSidlScreenWnd__StoreIniInfo_x                             0x87FCF0
#define CSidlScreenWnd__StoreIniVis_x                              0x8801C0
#define CSidlScreenWnd__WndNotification_x                          0x881F60
#define CSidlScreenWnd__GetChildItem_x                             0x880300
#define CSidlScreenWnd__HandleLButtonUp_x                          0x886F80

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5C7AB0
#define CSkillMgr__GetSkillCap_x                                   0x5C7C50

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8B9930
#define CSliderWnd__SetValue_x                                     0x8B9B00
#define CSliderWnd__SetNumTicks_x                                  0x8BA280

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x76B410

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8AA090
#define CStmlWnd__CalculateHSBRange_x                              0x8A26F0
#define CStmlWnd__CalculateVSBRange_x                              0x8A2780
#define CStmlWnd__CanBreakAtCharacter_x                            0x8A2900
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8A31E0
#define CStmlWnd__ForceParseNow_x                                  0x8AA9E0
#define CStmlWnd__GetNextTagPiece_x                                0x8A30E0
#define CStmlWnd__GetSTMLText_x                                    0x6637A0
#define CStmlWnd__GetVisibleText_x                                 0x8A3C30
#define CStmlWnd__InitializeWindowVariables_x                      0x8A5EC0
#define CStmlWnd__MakeStmlColorTag_x                               0x8A18D0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8A1930
#define CStmlWnd__SetSTMLText_x                                    0x8A7720
#define CStmlWnd__StripFirstSTMLLines_x                            0x8A9D30
#define CStmlWnd__UpdateHistoryString_x                            0x8A4B60

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8B1120
#define CTabWnd__DrawCurrentPage_x                                 0x8B0990
#define CTabWnd__DrawTab_x                                         0x8B0750
#define CTabWnd__GetCurrentPage_x                                  0x8B0D60
#define CTabWnd__GetPageInnerRect_x                                0x8B0440
#define CTabWnd__GetTabInnerRect_x                                 0x8B0640
#define CTabWnd__GetTabRect_x                                      0x8B0510
#define CTabWnd__InsertPage_x                                      0x8B1410
#define CTabWnd__SetPage_x                                         0x8B0D90
#define CTabWnd__SetPageRect_x                                     0x8B1060
#define CTabWnd__UpdatePage_x                                      0x8B13B0

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x41FFE0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8AD4E0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8B62F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x874750

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x411600
#define CXStr__CXStr1_x                                            0x869E50
#define CXStr__CXStr3_x                                            0x82BD80
#define CXStr__dCXStr_x                                            0x41D3C0
#define CXStr__operator_equal_x                                    0x82BEF0
#define CXStr__operator_equal1_x                                   0x82BF40
#define CXStr__operator_plus_equal1_x                              0x82D020

// CXWnd 
#define CXWnd__BringToTop_x                                        0x886190
#define CXWnd__Center_x                                            0x88C420
#define CXWnd__ClrFocus_x                                          0x885D50
#define CXWnd__DoAllDrawing_x                                      0x88C070
#define CXWnd__DrawChildren_x                                      0x88C210
#define CXWnd__DrawColoredRect_x                                   0x886550
#define CXWnd__DrawTooltip_x                                       0x8867F0
#define CXWnd__DrawTooltipAtPoint_x                                0x88AFE0
#define CXWnd__GetBorderFrame_x                                    0x886C40
#define CXWnd__GetChildWndAt_x                                     0x889FA0
#define CXWnd__GetClientClipRect_x                                 0x886A10
#define CXWnd__GetScreenClipRect_x                                 0x88B6E0
#define CXWnd__GetScreenRect_x                                     0x886E10
#define CXWnd__GetTooltipRect_x                                    0x886680
#define CXWnd__GetWindowTextA_x                                    0x411640
#define CXWnd__IsActive_x                                          0x899750
#define CXWnd__IsDescendantOf_x                                    0x886B80
#define CXWnd__IsReallyVisible_x                                   0x889F80
#define CXWnd__IsType_x                                            0x8B2AE0
#define CXWnd__Move_x                                              0x889660
#define CXWnd__Move1_x                                             0x88BD10
#define CXWnd__ProcessTransition_x                                 0x886130
#define CXWnd__Refade_x                                            0x885F00
#define CXWnd__Resize_x                                            0x886EE0
#define CXWnd__Right_x                                             0x88B4E0
#define CXWnd__SetFocus_x                                          0x8887B0
#define CXWnd__SetFont_x                                           0x885DA0
#define CXWnd__SetKeyTooltip_x                                     0x887150
#define CXWnd__SetMouseOver_x                                      0x88B9F0
#define CXWnd__StartFade_x                                         0x8861E0
#define CXWnd__GetChildItem_x                                      0x88B930

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x89B090
#define CXWndManager__DrawWindows_x                                0x89ACD0
#define CXWndManager__GetKeyboardFlags_x                           0x899280
#define CXWndManager__HandleKeyboardMsg_x                          0x899BF0
#define CXWndManager__RemoveWnd_x                                  0x8998E0

// CDBStr
#define CDBStr__GetString_x                                        0x487B90

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8E8960
#define EQ_Character__CastSpell_x                                  0x43BC00
#define EQ_Character__Cur_HP_x                                     0x451990
#define EQ_Character__GetAACastingTimeModifier_x                   0x434D60
#define EQ_Character__GetCharInfo2_x                               0x800660
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42D1B0
#define EQ_Character__GetFocusRangeModifier_x                      0x42D390
#define EQ_Character__Max_Endurance_x                              0x591180
#define EQ_Character__Max_HP_x                                     0x447C70
#define EQ_Character__Max_Mana_x                                   0x590FB0
#define EQ_Character__doCombatAbility_x                            0x58E7E0
#define EQ_Character__UseSkill_x                                   0x45C4D0
#define EQ_Character__GetConLevel_x                                0x583E20
#define EQ_Character__IsExpansionFlag_x                            0x410B50
#define EQ_Character__TotalEffect_x                                0x439D30

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x564B80
#define EQ_Item__CreateItemTagString_x                             0x7E15D0
#define EQ_Item__IsStackable_x                                     0x7D5BB0
#define EQ_Item__GetImageNum_x                                     0x7D8840

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A7190
#define EQ_LoadingS__Array_x                                       0xB562F8

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5927E0
#define EQ_PC__GetAltAbilityIndex_x                                0x7E96D0
#define EQ_PC__GetCombatAbility_x                                  0x7E9760
#define EQ_PC__GetCombatAbilityTimer_x                             0x7E9810
#define EQ_PC__GetItemTimerValue_x                                 0x58C5B0
#define EQ_PC__HasLoreItem_x                                       0x586FD0
#define EQ_PC__AlertInventoryChanged_x                             0x583DF0

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E4400
#define EQItemList__add_item_x                                     0x4E4340
#define EQItemList__delete_item_x                                  0x4E4800
#define EQItemList__FreeItemList_x                                 0x4E4700

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x486FA0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x597E10
#define EQPlayer__dEQPlayer_x                                      0x5A0940
#define EQPlayer__DoAttack_x                                       0x5B1DF0
#define EQPlayer__EQPlayer_x                                       0x5A2DD0
#define EQPlayer__SetNameSpriteState_x                             0x59D6F0
#define EQPlayer__SetNameSpriteTint_x                              0x599140
#define EQPlayer__IsBodyType_j_x                                   0x8E7C70
#define EQPlayer__IsTargetable_x                                   0x8E8440

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5A6780
#define EQPlayerManager__GetSpawnByName_x                          0x5A6BE0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56AD60
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56ADA0
#define KeypressHandler__ClearCommandStateArray_x                  0x56A940
#define KeypressHandler__HandleKeyDown_x                           0x569280
#define KeypressHandler__HandleKeyUp_x                             0x5695A0
#define KeypressHandler__SaveKeymapping_x                          0x56AA10

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6D58D0
#define MapViewMap__SaveEx_x                                       0x6D91B0

#define PlayerPointManager__GetAltCurrency_x                       0x7FA820

// StringTable 
#define StringTable__getString_x                                   0x7F66C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x590C30

//Doors
#define EQSwitch__UseSwitch_x                                      0x521390

//IconCache
#define IconCache__GetIcon_x                                       0x673CA0

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66ACF0
#define CContainerMgr__CloseContainer_x                            0x66B500

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x733F70

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x55E630

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B5760
