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
#define __ExpectedVersionDate                                     "Sep 22 2015"
#define __ExpectedVersionTime                                     "10:49:10"
#define __ActualVersionDate_x                                      0xACBB00
#define __ActualVersionTime_x                                      0xACBB0C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x59A000
#define __MemChecker1_x                                            0x896E00
#define __MemChecker2_x                                            0x632F00
#define __MemChecker3_x                                            0x632E50
#define __MemChecker4_x                                            0x7E8E50
#define __EncryptPad0_x                                            0xC61FE0
#define __EncryptPad1_x                                            0xDEBB58
#define __EncryptPad2_x                                            0xCABAC8
#define __EncryptPad3_x                                            0xCAB6C8
#define __EncryptPad4_x                                            0xDC6240
#define __AC1_x                                                    0x7A5DB5
#define __AC2_x                                                    0x54F3E7
#define __AC3_x                                                    0x563BE0
#define __AC4_x                                                    0x56A850
#define __AC5_x                                                    0x5766CE
#define __AC6_x                                                    0x57A179
#define __AC7_x                                                    0x570D7C
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x11978C8
#define DI8__Keyboard_x                                            0x11978CC
#define DI8__Mouse_x                                               0x11978D0
#define DI8__Mouse_Copy_x                                          0x1005EE4
#define DI8__Mouse_Check_x                                         0x108F7B4
#define __AltTimerReady_x                                          0xFF7231
#define __Attack_x                                                 0x108A453
#define __Autofire_x                                               0x108A454
#define __BindList_x                                               0xC240F0
#define __bCommandEnabled_x                                        0xFF5340
#define __Clicks_x                                                 0x1005FA0
#define __CommandList_x                                            0xC28460
#define __CurrentMapLabel_x                                        0x119D320
#define __CurrentSocial_x                                          0xBDDF54
#define __DoAbilityList_x                                          0x103C708
#define __do_loot_x                                                0x5169A0
#define __DrawHandler_x                                            0x180400C
#define __GroupCount_x                                             0xFF690A

#define __Guilds_x                                                 0xFFC520
#define __gWorld_x                                                 0xFF8DC4
#define __HotkeyPage_x                                             0x1083108
#define __HWnd_x                                                   0x108F7D0
#define __InChatMode_x                                             0x1005ECC
#define __LastTell_x                                               0x1007E10
#define __LMouseHeldTime_x                                         0x100600C
#define __Mouse_x                                                  0x11978D4
#define __MouseLook_x                                              0x1005F66
#define __MouseEventTime_x                                         0x108AC5C
#define __gpbCommandEvent_x                                        0xFF8E8C
#define __NetStatusToggle_x                                        0x1005F69
#define __PCNames_x                                                0x1007430
#define __RangeAttackReady_x                                       0x10070F0
#define __RMouseHeldTime_x                                         0x1006008
#define __RunWalkState_x                                           0x1005ED0
#define __ScreenMode_x                                             0xF450F0
#define __ScreenX_x                                                0x1005E84
#define __ScreenY_x                                                0x1005E80
#define __ScreenXMax_x                                             0x1005E88
#define __ScreenYMax_x                                             0x1005E8C
#define __ServerHost_x                                             0xFF6854
#define __ServerName_x                                             0x103C6C8
#define __ShiftKeyDown_x                                           0x1006574
#define __ShowNames_x                                              0x10072C4
#define __Socials_x                                                0x103C7C8
#define __SubscriptionType_x                                       0x11CB7F0
#define __TargetAggroHolder_x                                      0x119F55C
#define __GroupAggro_x                                             0x119F59C
#define __LoginName_x                                              0x108E3A8
#define __Inviter_x                                                0x108A3D0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xFF8EB0
#define instEQZoneInfo_x                                           0x100615C
#define instKeypressHandler_x                                      0x108AC40
#define pinstActiveBanker_x                                        0xFF8E68
#define pinstActiveCorpse_x                                        0xFF8E6C
#define pinstActiveGMaster_x                                       0xFF8E70
#define pinstActiveMerchant_x                                      0xFF8E64
#define pinstAggroInfo_x                                           0xE07538
#define pinstAltAdvManager_x                                       0xF461F0
#define pinstAuraMgr_x                                             0xE13438
#define pinstBandageTarget_x                                       0xFF8E50
#define pinstCamActor_x                                            0xF45AFC
#define pinstCDBStr_x                                              0xF45084
#define pinstCDisplay_x                                            0xFF8E78
#define pinstCEverQuest_x                                          0x1197A48
#define pinstCharData_x                                            0xFF8E34
#define pinstCharSpawn_x                                           0xFF8E5C
#define pinstControlledMissile_x                                   0xFF8E30
#define pinstControlledPlayer_x                                    0xFF8E5C
#define pinstCSidlManager_x                                        0x1803444
#define pinstCXWndManager_x                                        0x180343C
#define instDynamicZone_x                                          0x1005D18
#define pinstDZMember_x                                            0x1005E28
#define pinstDZTimerInfo_x                                         0x1005E2C
#define pinstEQItemList_x                                          0xFF5590
#define instEQMisc_x                                               0xBFEC58
#define pinstEQSoundManager_x                                      0xF466D8
#define instExpeditionLeader_x                                     0x1005D62
#define instExpeditionName_x                                       0x1005DA2
#define pinstGroup_x                                               0xFF6906
#define pinstImeManager_x                                          0x1803448
#define pinstLocalPlayer_x                                         0xFF8E48
#define pinstMercenaryData_x                                       0x108B290
#define pinstMercenaryStats_x                                      0x119F6A8
#define pinstMercAltAbilities_x                                    0xF4657C
#define pinstModelPlayer_x                                         0xFF8E74
#define pinstPCData_x                                              0xFF8E34
#define pinstSkillMgr_x                                            0x108C0C8
#define pinstSpawnManager_x                                        0x108B9B0
#define pinstSpellManager_x                                        0x108C210
#define pinstSpellSets_x                                           0x108316C
#define pinstStringTable_x                                         0xFF8DDC
#define pinstSwitchManager_x                                       0xFF6498
#define pinstTarget_x                                              0xFF8E60
#define pinstTargetObject_x                                        0xFF8E38
#define pinstTargetSwitch_x                                        0xFF8E3C
#define pinstTaskMember_x                                          0xF44FD0
#define pinstTrackTarget_x                                         0xFF8E54
#define pinstTradeTarget_x                                         0xFF8E44
#define instTributeActive_x                                        0xBFEC7D
#define pinstViewActor_x                                           0xF45AF8
#define pinstWorldData_x                                           0xFF8E18


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xE07A18
#define pinstCAudioTriggersWindow_x                                0xE078A8
#define pinstCCharacterSelect_x                                    0xF45994
#define pinstCFacePick_x                                           0xF45744
#define pinstCNoteWnd_x                                            0xF4594C
#define pinstCBookWnd_x                                            0xF45954
#define pinstCPetInfoWnd_x                                         0xF45958
#define pinstCTrainWnd_x                                           0xF4595C
#define pinstCSkillsWnd_x                                          0xF45960
#define pinstCSkillsSelectWnd_x                                    0xF45964
#define pinstCCombatSkillsSelectWnd_x                              0xF45968
#define pinstCFriendsWnd_x                                         0xF4596C
#define pinstCAuraWnd_x                                            0xF45970
#define pinstCRespawnWnd_x                                         0xF45974
#define pinstCBandolierWnd_x                                       0xF45978
#define pinstCPotionBeltWnd_x                                      0xF4597C
#define pinstCAAWnd_x                                              0xF45980
#define pinstCGroupSearchFiltersWnd_x                              0xF45984
#define pinstCLoadskinWnd_x                                        0xF45988
#define pinstCAlarmWnd_x                                           0xF4598C
#define pinstCMusicPlayerWnd_x                                     0xF45990
#define pinstCMailWnd_x                                            0xF45998
#define pinstCMailCompositionWnd_x                                 0xF4599C
#define pinstCMailAddressBookWnd_x                                 0xF459A0
#define pinstCRaidWnd_x                                            0xF459A8
#define pinstCRaidOptionsWnd_x                                     0xF459AC
#define pinstCBreathWnd_x                                          0xF459B0
#define pinstCMapViewWnd_x                                         0xF459B4
#define pinstCMapToolbarWnd_x                                      0xF459B8
#define pinstCEditLabelWnd_x                                       0xF459BC
#define pinstCTargetWnd_x                                          0xF459C0
#define pinstCColorPickerWnd_x                                     0xF459C4
#define pinstCPlayerWnd_x                                          0xF459C8
#define pinstCOptionsWnd_x                                         0xF459CC
#define pinstCBuffWindowNORMAL_x                                   0xF459D0
#define pinstCBuffWindowSHORT_x                                    0xF459D4
#define pinstCharacterCreation_x                                   0xF459D8
#define pinstCCursorAttachment_x                                   0xF459DC
#define pinstCCastingWnd_x                                         0xF459E0
#define pinstCCastSpellWnd_x                                       0xF459E4
#define pinstCSpellBookWnd_x                                       0xF459E8
#define pinstCInventoryWnd_x                                       0xF459EC
#define pinstCBankWnd_x                                            0xF459F0
#define pinstCQuantityWnd_x                                        0xF459F4
#define pinstCLootWnd_x                                            0xF459F8
#define pinstCActionsWnd_x                                         0xF459FC
#define pinstCCombatAbilityWnd_x                                   0xF45A00
#define pinstCMerchantWnd_x                                        0xF45A04
#define pinstCTradeWnd_x                                           0xF45A08
#define pinstCSelectorWnd_x                                        0xF45A0C
#define pinstCBazaarWnd_x                                          0xF45A10
#define pinstCBazaarSearchWnd_x                                    0xF45A14
#define pinstCGiveWnd_x                                            0xF45A30
#define pinstCTrackingWnd_x                                        0xF45A38
#define pinstCInspectWnd_x                                         0xF45A3C
#define pinstCSocialEditWnd_x                                      0xF45A40
#define pinstCFeedbackWnd_x                                        0xF45A44
#define pinstCBugReportWnd_x                                       0xF45A48
#define pinstCVideoModesWnd_x                                      0xF45A4C
#define pinstCTextEntryWnd_x                                       0xF45A54
#define pinstCFileSelectionWnd_x                                   0xF45A58
#define pinstCCompassWnd_x                                         0xF45A5C
#define pinstCPlayerNotesWnd_x                                     0xF45A60
#define pinstCGemsGameWnd_x                                        0xF45A64
#define pinstCTimeLeftWnd_x                                        0xF45A68
#define pinstCPetitionQWnd_x                                       0xF45A80
#define pinstCSoulmarkWnd_x                                        0xF45A84
#define pinstCStoryWnd_x                                           0xF45A88
#define pinstCJournalTextWnd_x                                     0xF45A8C
#define pinstCJournalCatWnd_x                                      0xF45A90
#define pinstCBodyTintWnd_x                                        0xF45A94
#define pinstCServerListWnd_x                                      0xF45A98
#define pinstCAvaZoneWnd_x                                         0xF45AA4
#define pinstCBlockedBuffWnd_x                                     0xF45AA8
#define pinstCBlockedPetBuffWnd_x                                  0xF45AAC
#define pinstCInvSlotMgr_x                                         0xF45AF0
#define pinstCContainerMgr_x                                       0xF45AF4
#define pinstCAdventureLeaderboardWnd_x                            0x11983F8
#define pinstCAdventureRequestWnd_x                                0x1198470
#define pinstCAltStorageWnd_x                                      0x1198750
#define pinstCAdventureStatsWnd_x                                  0x11984E8
#define pinstCBarterMerchantWnd_x                                  0x1199338
#define pinstCBarterSearchWnd_x                                    0x11993B0
#define pinstCBarterWnd_x                                          0x1199428
#define pinstCChatManager_x                                        0x1199AB8
#define pinstCDynamicZoneWnd_x                                     0x1199F68
#define pinstCEQMainWnd_x                                          0x119A100
#define pinstCFellowshipWnd_x                                      0x1199EFC
#define pinstCFindLocationWnd_x                                    0x119A3D0
#define pinstCGroupSearchWnd_x                                     0x119A6A0
#define pinstCGroupWnd_x                                           0x119A718
#define pinstCGuildBankWnd_x                                       0x119A790
#define pinstCGuildMgmtWnd_x                                       0x119C880
#define pinstCHotButtonWnd_x                                       0x119C94C
#define pinstCHotButtonWnd1_x                                      0x119C94C
#define pinstCHotButtonWnd2_x                                      0x119C950
#define pinstCHotButtonWnd3_x                                      0x119C954
#define pinstCHotButtonWnd4_x                                      0x119C978
#define pinstCItemDisplayManager_x                                 0x119CC70
#define pinstCItemExpTransferWnd_x                                 0x119CCEC
#define pinstCLFGuildWnd_x                                         0x119CFC8
#define pinstCMIZoneSelectWnd_x                                    0x119D5B0
#define pinstCConfirmationDialog_x                                 0x119DCB8
#define pinstCPopupWndManager_x                                    0x119DCB8
#define pinstCProgressionSelectionWnd_x                            0x119DDA8
#define pinstCPvPStatsWnd_x                                        0x119DE98
#define pinstCSystemInfoDialogBox_x                                0x119E5A0
#define pinstCTaskWnd_x                                            0x119F968
#define pinstCTaskSomething_x                                      0xE13B78
#define pinstCTaskTemplateSelectWnd_x                              0x119F8F0
#define pinstCTipWndOFDAY_x                                        0x119FBC0
#define pinstCTipWndCONTEXT_x                                      0x119FBC4
#define pinstCTitleWnd_x                                           0x119FC40
#define pinstCContextMenuManager_x                                 0x18033B4
#define pinstCVoiceMacroWnd_x                                      0x108C878
#define pinstCHtmlWnd_x                                            0x108C970
#define pinstIconCache_x                                           0x119A0D4
#define pinstCTradeskillWnd_x                                      0x119FD40
#define pinstCAdvancedLootWnd_x                                    0xF45AE4
#define pinstRewardSelectionWnd_x                                  0x119E3C0

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x52E4C0
#define __ConvertItemTags_x                                        0x51B620
#define __ExecuteCmd_x                                             0x506120
#define __EQGetTime_x                                              0x897160
#define __get_melee_range_x                                        0x50CDE0
#define __GetGaugeValueFromEQ_x                                    0x7A4AF0
#define __GetLabelFromEQ_x                                         0x7A5D40
#define __ToggleMount_x                                            0x6CDBE0
#define __GetXTargetType_x                                         0x928460
#define __LoadFrontEnd_x                                           0x6325B0
#define __NewUIINI_x                                               0x7A43F0
#define __ProcessGameEvents_x                                      0x572AE0
#define __ProcessMouseEvent_x                                      0x572280
#define CrashDetected_x                                            0x634080
#define wwsCrashReportCheckForUploader_x                           0x7F83F0
#define DrawNetStatus_x                                            0x5A9AF0
#define Util__FastTime_x                                           0x896AB0
#define Expansion_HoT_x                                            0x100725C
#define __HelpPath_x                                               0x108A9C8

//// 
// Section 4: Function Offsets 
//// 
// CAdvancedLootWnd
#define CAdvancedLootWnd__CAdvancedLootWnd_x                       0x41F010
#define CAdvancedLootWnd__DoAdvLootAction_x                        0x419E80

// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4C2B40
#define AltAdvManager__IsAbilityReady_x                            0x4C2BB0
#define AltAdvManager__GetAltAbility_x                             0x4C2F70

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x465860
#define CharacterZoneClient__MakeMeVisible_x                       0x46B240
#define CharacterZoneClient__IsStackBlocked_x                      0x447E10

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x662060

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x66FE60

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x588EC0
#define CButtonWnd__CButtonWnd_x                                   0x8CFD90

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x68B330
#define CChatManager__InitContextMenu_x                            0x68BEB0

// CContextMenu 
#define CContextMenu__CContextMenu_x                               0x8D9F10
#define CContextMenu__dCContextMenu_x                              0x8DA120
#define CContextMenu__AddMenuItem_x                                0x8DA130
#define CContextMenu__RemoveMenuItem_x                             0x8DA420
#define CContextMenu__RemoveAllMenuItems_x                         0x8DA440
#define CContextMenuManager__AddMenu_x                             0x8C5D00
#define CContextMenuManager__RemoveMenu_x                          0x8C6050
#define CContextMenuManager__PopupMenu_x                           0x8C64A0
#define CContextMenuManager__Flush_x                               0x8C5D70
#define CContextMenuManager__GetMenu_x                             0x4154F0

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x87CFA0
#define CChatService__GetFriendName_x                              0x87CFB0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x691150
#define CChatWindow__Clear_x                                       0x690D10
#define CChatWindow__WndNotification_x                             0x691690

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x8C9C00
#define CComboWnd__Draw_x                                          0x8C9E10
#define CComboWnd__GetCurChoice_x                                  0x8C99D0
#define CComboWnd__GetListRect_x                                   0x8CA0B0
#define CComboWnd__GetTextRect_x                                   0x8C9C70
#define CComboWnd__InsertChoice_x                                  0x8CA120
#define CComboWnd__SetColors_x                                     0x8C9960
#define CComboWnd__SetChoice_x                                     0x8C9990
#define CComboWnd__GetItemCount_x                                  0x8C99C0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x69A920
#define CContainerWnd__vftable_x                                   0xAD5498

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x4B0CE0
#define CDisplay__GetClickedActor_x                                0x4A9860
#define CDisplay__GetUserDefinedColor_x                            0x4A8120
#define CDisplay__GetWorldFilePath_x                               0x4A7570
#define CDisplay__is3dON_x                                         0x4A6940
#define CDisplay__ReloadUI_x                                       0x4BC200
#define CDisplay__WriteTextHD2_x                                   0x4AD080

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8F0550

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8DE8B0
#define CEditWnd__GetCharIndexPt_x                                 0x8DF950
#define CEditWnd__GetDisplayString_x                               0x8DEA60
#define CEditWnd__GetHorzOffset_x                                  0x8DEDA0
#define CEditWnd__GetLineForPrintableChar_x                        0x8DF410
#define CEditWnd__GetSelStartPt_x                                  0x8DFC10
#define CEditWnd__GetSTMLSafeText_x                                0x8DEF40
#define CEditWnd__PointFromPrintableChar_x                         0x8DF500
#define CEditWnd__SelectableCharFromPoint_x                        0x8DF680
#define CEditWnd__SetEditable_x                                    0x8DEF10

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x54FB30
#define CEverQuest__DoTellWindow_x                                 0x555530
#define CEverQuest__DropHeldItemOnGround_x                         0x55E060
#define CEverQuest__dsp_chat_x                                     0x556CD0
#define CEverQuest__Emote_x                                        0x556F30
#define CEverQuest__EnterZone_x                                    0x56B070
#define CEverQuest__GetBodyTypeDesc_x                              0x54C390
#define CEverQuest__GetClassDesc_x                                 0x5520A0
#define CEverQuest__GetClassThreeLetterCode_x                      0x5526A0
#define CEverQuest__GetDeityDesc_x                                 0x54CC70
#define CEverQuest__GetLangDesc_x                                  0x54C720
#define CEverQuest__GetRaceDesc_x                                  0x552860
#define CEverQuest__InterpretCmd_x                                 0x557810
#define CEverQuest__LeftClickedOnPlayer_x                          0x56F1E0
#define CEverQuest__LMouseUp_x                                     0x5712D0
#define CEverQuest__RightClickedOnPlayer_x                         0x56FCE0
#define CEverQuest__RMouseUp_x                                     0x570D30
#define CEverQuest__SetGameState_x                                 0x5501E0
#define CEverQuest__UPCNotificationFlush_x                         0x5589B0
#define CEverQuest__IssuePetCommand_x                              0x558510

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6AB480
#define CGaugeWnd__CalcLinesFillRect_x                             0x6AB4E0
#define CGaugeWnd__Draw_x                                          0x6AB910

// CGuild
#define CGuild__FindMemberByName_x                                 0x435FC0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x6C8620

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6D6440
#define CInvSlotMgr__MoveItem_x                                    0x6D7380
#define CInvSlotMgr__SelectSlot_x                                  0x6D64F0

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6D58D0
#define CInvSlot__SliderComplete_x                                 0x6D3290
#define CInvSlot__GetItemBase_x                                    0x6D2720

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6D8500

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x7A1480
#define CItemDisplayWnd__UpdateStrings_x                           0x6D9850

// CLabel 
#define CLabel__Draw_x                                             0x6F45F0

// CListWnd
#define CListWnd__CListWnd_x                                       0x8B5960
#define CListWnd__dCListWnd_x                                      0x8B6980
#define CListWnd__AddColumn_x                                      0x8B6920
#define CListWnd__AddColumn1_x                                     0x8B61A0
#define CListWnd__AddLine_x                                        0x8B5C20
#define CListWnd__AddString_x                                      0x8B5E30
#define CListWnd__CalculateFirstVisibleLine_x                      0x8B2CB0
#define CListWnd__CalculateVSBRange_x                              0x8B4E20
#define CListWnd__ClearAllSel_x                                    0x8B1F70
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8B57F0
#define CListWnd__Compare_x                                        0x8B37A0
#define CListWnd__Draw_x                                           0x8B4A30
#define CListWnd__DrawColumnSeparators_x                           0x8B48C0
#define CListWnd__DrawHeader_x                                     0x8B2280
#define CListWnd__DrawItem_x                                       0x8B3DF0
#define CListWnd__DrawLine_x                                       0x8B4560
#define CListWnd__DrawSeparator_x                                  0x8B4960
#define CListWnd__EnsureVisible_x                                  0x8B2E10
#define CListWnd__ExtendSel_x                                      0x8B3D00
#define CListWnd__GetColumnMinWidth_x                              0x8B1930
#define CListWnd__GetColumnWidth_x                                 0x8B1850
#define CListWnd__GetCurSel_x                                      0x8B1020
#define CListWnd__GetItemAtPoint_x                                 0x8B30B0
#define CListWnd__GetItemAtPoint1_x                                0x8B3120
#define CListWnd__GetItemData_x                                    0x8B1360
#define CListWnd__GetItemHeight_x                                  0x8B2910
#define CListWnd__GetItemIcon_x                                    0x8B1540
#define CListWnd__GetItemRect_x                                    0x8B2EF0
#define CListWnd__GetItemText_x                                    0x8B13F0
#define CListWnd__GetSelList_x                                     0x8B6090
#define CListWnd__GetSeparatorRect_x                               0x8B36D0
#define CListWnd__RemoveLine_x                                     0x8B6010
#define CListWnd__SetColors_x                                      0x8B1170
#define CListWnd__SetColumnJustification_x                         0x8B1C00
#define CListWnd__SetColumnWidth_x                                 0x8B18E0
#define CListWnd__SetCurSel_x                                      0x8B1060
#define CListWnd__SetItemColor_x                                   0x8B54D0
#define CListWnd__SetItemData_x                                    0x8B2020
#define CListWnd__SetItemText_x                                    0x8B5310
#define CListWnd__ShiftColumnSeparator_x                           0x8B51A0
#define CListWnd__Sort_x                                           0x8B6A80
#define CListWnd__ToggleSel_x                                      0x8B1EF0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x70DC20

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x72EDE0
#define CMerchantWnd__RequestBuyItem_x                             0x735C10
#define CMerchantWnd__RequestSellItem_x                            0x736680
#define CMerchantWnd__SelectRecoverySlot_x                         0x72F090
#define CMerchantWnd__SelectBuySellSlot_x                          0x72E2F0
#define CMerchantWnd__ActualSelect_x                               0x732B40

// CObfuscator
#define CObfuscator__doit_x                                        0x85D290

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x8D4E00
#define CSidlManager__CreateLabel_x                                0x797430

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x659370
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6592A0
#define CSidlScreenWnd__ConvertToRes_x                             0x8F0430
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x8CC8A0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x8CDDB0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x8CDE60
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x8CD330
#define CSidlScreenWnd__DrawSidlPiece_x                            0x8CC250
#define CSidlScreenWnd__EnableIniStorage_x                         0x8CB9A0
#define CSidlScreenWnd__GetSidlPiece_x                             0x8CC440
#define CSidlScreenWnd__Init1_x                                    0x8CDA90
#define CSidlScreenWnd__LoadIniInfo_x                              0x8CC950
#define CSidlScreenWnd__LoadIniListWnd_x                           0x8CBB60
#define CSidlScreenWnd__LoadSidlScreen_x                           0x8CD580
#define CSidlScreenWnd__StoreIniInfo_x                             0x8CB460
#define CSidlScreenWnd__StoreIniVis_x                              0x8CB930
#define CSidlScreenWnd__WndNotification_x                          0x8CD810
#define CSidlScreenWnd__GetChildItem_x                             0x8CBA70
#define CSidlScreenWnd__HandleLButtonUp_x                          0x8BEF50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5F4670
#define CSkillMgr__GetSkillCap_x                                   0x5F4830
#define CSkillMgr__GetNameToken_x                                  0x5F4290

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8EF6D0
#define CSliderWnd__SetValue_x                                     0x8EF8A0
#define CSliderWnd__SetNumTicks_x                                  0x8F0020

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x79F100

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8EA0C0
#define CStmlWnd__CalculateHSBRange_x                              0x8E25F0
#define CStmlWnd__CalculateVSBRange_x                              0x8E2680
#define CStmlWnd__CanBreakAtCharacter_x                            0x8E2800
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8E30E0
#define CStmlWnd__ForceParseNow_x                                  0x8EAA10
#define CStmlWnd__GetNextTagPiece_x                                0x8E2FE0
#define CStmlWnd__GetSTMLText_x                                    0x6905B0
#define CStmlWnd__GetVisibleText_x                                 0x8E3B30
#define CStmlWnd__InitializeWindowVariables_x                      0x8E5EA0
#define CStmlWnd__MakeStmlColorTag_x                               0x8E18F0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8E1950
#define CStmlWnd__SetSTMLText_x                                    0x8E7700
#define CStmlWnd__StripFirstSTMLLines_x                            0x8E9D60
#define CStmlWnd__UpdateHistoryString_x                            0x8E4A60

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8F1D00
#define CTabWnd__DrawCurrentPage_x                                 0x8F1570
#define CTabWnd__DrawTab_x                                         0x8F1330
#define CTabWnd__GetCurrentPage_x                                  0x8F1940
#define CTabWnd__GetPageInnerRect_x                                0x8F1020
#define CTabWnd__GetTabInnerRect_x                                 0x8F1220
#define CTabWnd__GetTabRect_x                                      0x8F10F0
#define CTabWnd__InsertPage_x                                      0x8F1FF0
#define CTabWnd__SetPage_x                                         0x8F1970
#define CTabWnd__SetPageRect_x                                     0x8F1C40
#define CTabWnd__UpdatePage_x                                      0x8F1F90

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x431D20

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8C95D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8F6EE0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x8AF070

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x5965C0
#define CXStr__CXStr1_x                                            0x4DEA30
#define CXStr__CXStr3_x                                            0x893B40
#define CXStr__dCXStr_x                                            0x408FD0
#define CXStr__operator_equal_x                                    0x893CB0
#define CXStr__operator_equal1_x                                   0x893D00
#define CXStr__operator_plus_equal1_x                              0x894DE0

// CXWnd 
#define CXWnd__BringToTop_x                                        0x8BE1F0
#define CXWnd__Center_x                                            0x8C4320
#define CXWnd__ClrFocus_x                                          0x8BDDD0
#define CXWnd__DoAllDrawing_x                                      0x8C3F50
#define CXWnd__DrawChildren_x                                      0x8C4100
#define CXWnd__DrawColoredRect_x                                   0x8BE5A0
#define CXWnd__DrawTooltip_x                                       0x8BE840
#define CXWnd__DrawTooltipAtPoint_x                                0x8C2EA0
#define CXWnd__GetBorderFrame_x                                    0x8BEC40
#define CXWnd__GetChildWndAt_x                                     0x8C4CC0
#define CXWnd__GetClientClipRect_x                                 0x8BEA50
#define CXWnd__GetScreenClipRect_x                                 0x8C35A0
#define CXWnd__GetScreenRect_x                                     0x8BEDF0
#define CXWnd__GetTooltipRect_x                                    0x8BE6D0
#define CXWnd__GetWindowTextA_x                                    0x422F70
#define CXWnd__IsActive_x                                          0x8B9780
#define CXWnd__IsDescendantOf_x                                    0x8BEB90
#define CXWnd__IsReallyVisible_x                                   0x8C1F00
#define CXWnd__IsType_x                                            0x8F36C0
#define CXWnd__Move_x                                              0x8C15F0
#define CXWnd__Move1_x                                             0x8C3BF0
#define CXWnd__ProcessTransition_x                                 0x8BE1A0
#define CXWnd__Refade_x                                            0x8BE1A0
#define CXWnd__Resize_x                                            0x8BEEB0
#define CXWnd__Right_x                                             0x8C33A0
#define CXWnd__SetFocus_x                                          0x8C0760
#define CXWnd__SetFont_x                                           0x8BDE20
#define CXWnd__SetKeyTooltip_x                                     0x8BF120
#define CXWnd__SetMouseOver_x                                      0x8C38D0
#define CXWnd__StartFade_x                                         0x8BE240
#define CXWnd__GetChildItem_x                                      0x8C3820

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8BB0B0
#define CXWndManager__DrawWindows_x                                0x8BACF0
#define CXWndManager__GetKeyboardFlags_x                           0x8B92B0
#define CXWndManager__HandleKeyboardMsg_x                          0x8B9C20
#define CXWndManager__RemoveWnd_x                                  0x8B9910

// CDBStr
#define CDBStr__GetString_x                                        0x4A4F10

// EQ_Character 
#define EQ_Character__CastSpell_x                                  0x44FA70
#define EQ_Character__Cur_HP_x                                     0x464F30
#define EQ_Character__GetAACastingTimeModifier_x                   0x447990
#define EQ_Character__GetCharInfo2_x                               0x867B80
#define EQ_Character__GetFocusCastingTimeModifier_x                0x43F8F0
#define EQ_Character__GetFocusRangeModifier_x                      0x43FAE0
#define EQ_Character__Max_Endurance_x                              0x5BBB30
#define EQ_Character__Max_HP_x                                     0x45ABC0
#define EQ_Character__Max_Mana_x                                   0x5BB960
#define EQ_Character__doCombatAbility_x                            0x5B8F40
#define EQ_Character__UseSkill_x                                   0x470430
#define EQ_Character__GetConLevel_x                                0x5AE0E0
#define EQ_Character__IsExpansionFlag_x                            0x4224B0
#define EQ_Character__TotalEffect_x                                0x44CD10

// EQ_Item (ItemClient)
#define EQ_Item__CanDrop_x                                         0x58E650
#define EQ_Item__CreateItemTagString_x                             0x847030
#define EQ_Item__IsStackable_x                                     0x83B550
#define EQ_Item__GetImageNum_x                                     0x83E220
#define EQ_Item__CreateItemClient_x                                0x58F240
#define EQ_Item__GetItemValue_x                                    0x845C90
#define EQ_Item__ValueSellMerchant_x                               0x848340

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4C4C30
#define EQ_LoadingS__Array_x                                       0xC0CA30

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x5BD2C0
#define EQ_PC__GetAltAbilityIndex_x                                0x850030
#define EQ_PC__GetCombatAbility_x                                  0x8500C0
#define EQ_PC__GetCombatAbilityTimer_x                             0x84B070
#define EQ_PC__GetItemTimerValue_x                                 0x5B6D10
#define EQ_PC__HasLoreItem_x                                       0x5B1450
#define EQ_PC__AlertInventoryChanged_x                             0x5AE0B0
#define EQ_PC__GetPcZoneClient_x                                   0x5D78E0
#define EQ_PC__RemoveMyAffect_x									   0x5B6220

// EQItemList 
#define EQItemList__EQItemList_x                                   0x50AE40
#define EQItemList__add_item_x                                     0x50AD80
#define EQItemList__delete_item_x                                  0x50B240
#define EQItemList__FreeItemList_x                                 0x50B140

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x4A4210

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x5C2870
#define EQPlayer__dEQPlayer_x                                      0x5CB6F0
#define EQPlayer__DoAttack_x                                       0x5DD7F0
#define EQPlayer__EQPlayer_x                                       0x5CDB10
#define EQPlayer__SetNameSpriteState_x                             0x5C83C0
#define EQPlayer__SetNameSpriteTint_x                              0x5C3C80
#define EQPlayer__IsBodyType_j_x                                   0x9245F0
#define EQPlayer__IsTargetable_x                                   0x924EF0
#define EQPlayer__CanSee_x                                         0x925410

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5D1E90
#define EQPlayerManager__GetSpawnByName_x                          0x5D22F0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x5948F0
#define KeypressHandler__AttachKeyToEqCommand_x                    0x594930
#define KeypressHandler__ClearCommandStateArray_x                  0x5944D0
#define KeypressHandler__HandleKeyDown_x                           0x592E30
#define KeypressHandler__HandleKeyUp_x                             0x593150
#define KeypressHandler__SaveKeymapping_x                          0x5945A0

// MapViewMap 
#define MapViewMap__Clear_x                                        0x706000
#define MapViewMap__SaveEx_x                                       0x7098E0

#define PlayerPointManager__GetAltCurrency_x                       0x862A60

// StringTable 
#define StringTable__getString_x                                   0x85D530

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x5BB5E0
#define PcZoneClient__RemovePetEffect_x                            0x5B6F40

//Doors
#define EQSwitch__UseSwitch_x                                      0x5497E0

//IconCache
#define IconCache__GetIcon_x                                       0x6A0D90

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x697C20
#define CContainerMgr__CloseContainer_x                            0x698440

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x7676E0

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x587980

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4DA760
#define EQ_Spell__SpellAffects_x                                   0x4DA800
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4DA830
#define CharacterZoneClient__CalcAffectChange_x                    0x448D80
#define CLootWnd__LootAll_x                                        0x6FB930

//CTargetWnd
#define CTargetWnd__GetBuffCaster_x                                0x7AD100
#define CTargetWnd__WndNotification_x                              0x7ACBF0

//CTaskWnd
#define CTaskWnd__UpdateTaskTimers_x                               0x7B22E0

//EqSoundManager
#define EqSoundManager__WavePlay_x                                 0x4D3FA0

//CCombatSkillsSelectWnd
#define CCombatSkillsSelectWnd__ShouldDisplayThisSkill_x           0x494DB0

//CTextureAnimation
#define CTextureAnimation__SetCurCell_x                            0x8DDEE0
#define CSidlManager__FindAnimation1_x                             0x8D2CF0
