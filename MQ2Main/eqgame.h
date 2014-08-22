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
#define __ExpectedVersionDate                                     "Aug 19 2014"
#define __ExpectedVersionTime                                     "10:22:22"
#define __ActualVersionDate_x                                      0xA4C7C8
#define __ActualVersionTime_x                                      0xA4C7D4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0_x                                            0x572F80
#define __MemChecker1_x                                            0x8369F0
#define __MemChecker2_x                                            0x60A190
#define __MemChecker3_x                                            0x60A0E0
#define __MemChecker4_x                                            0x7BB010
#define __EncryptPad0_x                                            0xBB7088
#define __EncryptPad1_x                                            0xD31360
#define __EncryptPad2_x                                            0xBFE2E8
#define __EncryptPad3_x                                            0xBFDEE8
#define __EncryptPad4_x                                            0xD0EC90
#define __AC1_x                                                    0x778485
#define __AC2_x                                                    0x5296B7
#define __AC3_x                                                    0x53DD90
#define __AC4_x                                                    0x543EC0
#define __AC5_x                                                    0x5504F1
#define __AC6_x                                                    0x554032
#define __AC7_x                                                    0x549FCC
#define __AC1_Data                                                 0x11111111
// Direct Input
#define DI8__Main_x                                                0x10E1EF8
#define DI8__Keyboard_x                                            0x10E1EFC
#define DI8__Mouse_x                                               0x10E1F00
#define __AltTimerReady_x                                          0xF41999
#define __Attack_x                                                 0xFD4A9E
#define __Autofire_x                                               0xFD4A9F
#define __BindList_x                                               0xB7B258
#define __bCommandEnabled_x                                        0xF3FAA8
#define __Clicks_x                                                 0xF505E0
#define __CommandList_x                                            0xB7F370
#define __CurrentMapLabel_x                                        0x10E7B78
#define __CurrentSocial_x                                          0xB40E28
#define __DoAbilityList_x                                          0xF86D54
#define __do_loot_x                                                0x4F0F00
#define __DrawHandler_x                                            0x174A134
#define __GroupCount_x                                             0xF41072

#define __Guilds_x                                                 0xF46B60
#define __gWorld_x                                                 0xF4352C
#define __HotkeyPage_x                                             0xFCD754
#define __HWnd_x                                                   0xFD9E00
#define __InChatMode_x                                             0xF5050C
#define __LastTell_x                                               0xF5245C
#define __LMouseHeldTime_x                                         0xF5064C
#define __Mouse_x                                                  0x10E1F04
#define __MouseLook_x                                              0xF505A6
#define __MouseEventTime_x                                         0xFD528C
#define __NetStatusToggle_x                                        0xF505A9
#define __PCNames_x                                                0xF51A94
#define __RangeAttackReady_x                                       0xF5172C
#define __RMouseHeldTime_x                                         0xF50648
#define __RunWalkState_x                                           0xF50510
#define __ScreenMode_x                                             0xE8FA70
#define __ScreenX_x                                                0xF504C4
#define __ScreenY_x                                                0xF504C0
#define __ScreenXMax_x                                             0xF504C8
#define __ScreenYMax_x                                             0xF504CC
#define __ServerHost_x                                             0xF40FBC
#define __ServerName_x                                             0xF86D14
#define __ShiftKeyDown_x                                           0xF50BB0
#define __ShowNames_x                                              0xF51938
#define __Socials_x                                                0xF86E14
#define __SubscriptionType_x                                       0x11118B0
#define __TargetAggroHolder_x                                      0x10E9D90
#define __GroupAggro_x                                             0x10E9DD0
#define __LoginName_x                                              0xFD89D8
#define __Inviter_x                                                0xFD4A1C


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid_x                                                0xF43618
#define instEQZoneInfo_x                                           0xF5079C
#define instKeypressHandler_x                                      0xFD5270
#define pinstActiveBanker_x                                        0xF435D0
#define pinstActiveCorpse_x                                        0xF435D4
#define pinstActiveGMaster_x                                       0xF435D8
#define pinstActiveMerchant_x                                      0xF435CC
#define pinstAggroInfo_x                                           0xD54058
#define pinstAltAdvManager_x                                       0xE90B40
#define pinstAuraMgr_x                                             0xD5DF20
#define pinstBandageTarget_x                                       0xF435B8
#define pinstCamActor_x                                            0xE9044C
#define pinstCDBStr_x                                              0xE8FA04
#define pinstCDisplay_x                                            0xF435E0
#define pinstCEverQuest_x                                          0x10E207C
#define pinstCharData_x                                            0xF4359C
#define pinstCharSpawn_x                                           0xF435C4
#define pinstControlledMissile_x                                   0xF43598
#define pinstControlledPlayer_x                                    0xF435C4
#define pinstCSidlManager_x                                        0x1749548
#define pinstCXWndManager_x                                        0x1749540
#define instDynamicZone_x                                          0xF50358
#define pinstDZMember_x                                            0xF50468
#define pinstDZTimerInfo_x                                         0xF5046C
#define pinstEQItemList_x                                          0xF3FCF4
#define instEQMisc_x                                               0xB5C770
#define pinstEQSoundManager_x                                      0xE90E40
#define instExpeditionLeader_x                                     0xF503A2
#define instExpeditionName_x                                       0xF503E2
#define pinstGroup_x                                               0xF4106E
#define pinstImeManager_x                                          0x174954C
#define pinstLocalPlayer_x                                         0xF435B0
#define pinstMercenaryData_x                                       0xFD58C0
#define pinstMercAltAbilities_x                                    0xE90D60
#define pinstModelPlayer_x                                         0xF435DC
#define pinstPCData_x                                              0xF4359C
#define pinstSkillMgr_x                                            0xFD66F8
#define pinstSpawnManager_x                                        0xFD5FE0
#define pinstSpellManager_x                                        0xFD6840
#define pinstSpellSets_x                                           0xFCD7B8
#define pinstStringTable_x                                         0xF43544
#define pinstSwitchManager_x                                       0xF40C00
#define pinstTarget_x                                              0xF435C8
#define pinstTargetObject_x                                        0xF435A0
#define pinstTargetSwitch_x                                        0xF435A4
#define pinstTaskMember_x                                          0xE8F950
#define pinstTrackTarget_x                                         0xF435BC
#define pinstTradeTarget_x                                         0xF435AC
#define instTributeActive_x                                        0xB5C795
#define pinstViewActor_x                                           0xE90448
#define pinstWorldData_x                                           0xF43580


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay_x                                        0xD54538
#define pinstCAudioTriggersWindow_x                                0xD543C8
#define pinstCCharacterSelect_x                                    0xE902F4
#define pinstCFacePick_x                                           0xE900A4
#define pinstCNoteWnd_x                                            0xE902AC
#define pinstCBookWnd_x                                            0xE902B4
#define pinstCPetInfoWnd_x                                         0xE902B8
#define pinstCTrainWnd_x                                           0xE902BC
#define pinstCSkillsWnd_x                                          0xE902C0
#define pinstCSkillsSelectWnd_x                                    0xE902C4
#define pinstCCombatSkillSelectWnd_x                               0xE902C8
#define pinstCFriendsWnd_x                                         0xE902CC
#define pinstCAuraWnd_x                                            0xE902D0
#define pinstCRespawnWnd_x                                         0xE902D4
#define pinstCBandolierWnd_x                                       0xE902D8
#define pinstCPotionBeltWnd_x                                      0xE902DC
#define pinstCAAWnd_x                                              0xE902E0
#define pinstCGroupSearchFiltersWnd_x                              0xE902E4
#define pinstCLoadskinWnd_x                                        0xE902E8
#define pinstCAlarmWnd_x                                           0xE902EC
#define pinstCMusicPlayerWnd_x                                     0xE902F0
#define pinstCMailWnd_x                                            0xE902F8
#define pinstCMailCompositionWnd_x                                 0xE902FC
#define pinstCMailAddressBookWnd_x                                 0xE90300
#define pinstCRaidWnd_x                                            0xE90308
#define pinstCRaidOptionsWnd_x                                     0xE9030C
#define pinstCBreathWnd_x                                          0xE90310
#define pinstCMapViewWnd_x                                         0xE90314
#define pinstCMapToolbarWnd_x                                      0xE90318
#define pinstCEditLabelWnd_x                                       0xE9031C
#define pinstCTargetWnd_x                                          0xE90320
#define pinstCColorPickerWnd_x                                     0xE90324
#define pinstCPlayerWnd_x                                          0xE90328
#define pinstCOptionsWnd_x                                         0xE9032C
#define pinstCBuffWindowNORMAL_x                                   0xE90330
#define pinstCBuffWindowSHORT_x                                    0xE90334
#define pinstCharacterCreation_x                                   0xE90338
#define pinstCCursorAttachment_x                                   0xE9033C
#define pinstCCastingWnd_x                                         0xE90340
#define pinstCCastSpellWnd_x                                       0xE90344
#define pinstCSpellBookWnd_x                                       0xE90348
#define pinstCInventoryWnd_x                                       0xE9034C
#define pinstCBankWnd_x                                            0xE90350
#define pinstCQuantityWnd_x                                        0xE90354
#define pinstCLootWnd_x                                            0xE90358
#define pinstCActionsWnd_x                                         0xE9035C
#define pinstCCombatAbilityWnd_x                                   0xE90360
#define pinstCMerchantWnd_x                                        0xE90364
#define pinstCTradeWnd_x                                           0xE90368
#define pinstCSelectorWnd_x                                        0xE9036C
#define pinstCBazaarWnd_x                                          0xE90370
#define pinstCBazaarSearchWnd_x                                    0xE90374
#define pinstCGiveWnd_x                                            0xE90390
#define pinstCTrackingWnd_x                                        0xE90398
#define pinstCInspectWnd_x                                         0xE9039C
#define pinstCSocialEditWnd_x                                      0xE903A0
#define pinstCFeedbackWnd_x                                        0xE903A4
#define pinstCBugReportWnd_x                                       0xE903A8
#define pinstCVideoModesWnd_x                                      0xE903AC
#define pinstCTextEntryWnd_x                                       0xE903B4
#define pinstCFileSelectionWnd_x                                   0xE903B8
#define pinstCCompassWnd_x                                         0xE903BC
#define pinstCPlayerNotesWnd_x                                     0xE903C0
#define pinstCGemsGameWnd_x                                        0xE903C4
#define pinstCTimeLeftWnd_x                                        0xE903C8
#define pinstCPetitionQWnd_x                                       0xE903DC
#define pinstCSoulmarkWnd_x                                        0xE903E0
#define pinstCStoryWnd_x                                           0xE903E4
#define pinstCJournalTextWnd_x                                     0xE903E8
#define pinstCJournalCatWnd_x                                      0xE903EC
#define pinstCBodyTintWnd_x                                        0xE903F0
#define pinstCServerListWnd_x                                      0xE903F4
#define pinstCAvaZoneWnd_x                                         0xE90400
#define pinstCBlockedBuffWnd_x                                     0xE90404
#define pinstCBlockedPetBuffWnd_x                                  0xE90408
#define pinstCInvSlotMgr_x                                         0xE90440
#define pinstCContainerMgr_x                                       0xE90444
#define pinstCAdventureLeaderboardWnd_x                            0x10E2C50
#define pinstCAdventureRequestWnd_x                                0x10E2CC8
#define pinstCAltStorageWnd_x                                      0x10E2FA8
#define pinstCAdventureStatsWnd_x                                  0x10E2D40
#define pinstCBarterMerchantWnd_x                                  0x10E3B90
#define pinstCBarterSearchWnd_x                                    0x10E3C08
#define pinstCBarterWnd_x                                          0x10E3C80
#define pinstCChatManager_x                                        0x10E4310
#define pinstCDynamicZoneWnd_x                                     0x10E47C0
#define pinstCEQMainWnd_x                                          0x10E4958
#define pinstCFellowshipWnd_x                                      0x10E4754
#define pinstCFindLocationWnd_x                                    0x10E4C28
#define pinstCGroupSearchWnd_x                                     0x10E4EF8
#define pinstCGroupWnd_x                                           0x10E4F70
#define pinstCGuildBankWnd_x                                       0x10E4FE8
#define pinstCGuildMgmtWnd_x                                       0x10E70D8
#define pinstCHotButtonWnd_x                                       0x10E71A4
#define pinstCHotButtonWnd1_x                                      0x10E71A4
#define pinstCHotButtonWnd2_x                                      0x10E71A8
#define pinstCHotButtonWnd3_x                                      0x10E71AC
#define pinstCHotButtonWnd4_x                                      0x10E71D0
#define pinstCItemDisplayManager_x                                 0x10E74C8
#define pinstCItemExpTransferWnd_x                                 0x10E7544
#define pinstCLFGuildWnd_x                                         0x10E7820
#define pinstCMIZoneSelectWnd_x                                    0x10E7E08
#define pinstCConfirmationDialog_x                                 0x10E8510
#define pinstCPopupWndManager_x                                    0x10E8510
#define pinstCProgressionSelectionWnd_x                            0x10E8600
#define pinstCPvPStatsWnd_x                                        0x10E86F0
#define pinstCSystemInfoDialogBox_x                                0x10E8DF8
#define pinstCTaskWnd_x                                            0x10EA190
#define pinstCTaskTemplateSelectWnd_x                              0x10EA118
#define pinstCTipWndOFDAY_x                                        0x10EA3E8
#define pinstCTipWndCONTEXT_x                                      0x10EA3EC
#define pinstCTitleWnd_x                                           0x10EA468
#define pinstCContextMenuManager_x                                 0x174915C
#define pinstCVoiceMacroWnd_x                                      0xFD6EA8
#define pinstCHtmlWnd_x                                            0xFD6FA0
#define pinstIconCache_x                                           0x10E492C
#define pinstCTradeskillWnd_x                                      0x10EA568

//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay_x                                                0x508A10
#define __ConvertItemTags_x                                        0x4F5BC0
#define __ExecuteCmd_x                                             0x4E07D0
#define __EQGetTime_x                                              0x837550
#define __get_melee_range_x                                        0x4E7430
#define __GetGaugeValueFromEQ_x                                    0x7771E0
#define __GetLabelFromEQ_x                                         0x778410
#define __GetXTargetType_x                                         0x8F4C10
#define __LoadFrontEnd_x                                           0x609840
#define __NewUIINI_x                                               0x776B20
#define __ProcessGameEvents_x                                      0x54C110
#define CrashDetected_x                                            0x60B310
#define DrawNetStatus_x                                            0x582780
#define Util__FastTime_x                                           0x836860
#define Expansion_HoT_x                                            0xF51898
#define __HelpPath_x                                               0xFD4FF8
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer_x                        0x4A5A20
#define AltAdvManager__IsAbilityReady_x                            0x4A5A90
#define AltAdvManager__GetAltAbility_x                             0x4A5E50

// CharacterZoneClient
#define CharacterZoneClient__HasSkill_x                            0x452950
#define CharacterZoneClient__MakeMeVisible_x                       0x4578F0

// CBankWnd 
#define CBankWnd__GetNumBankSlots_x                                0x639620

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg_x                        0x647B40

// CButtonWnd 
#define CButtonWnd__SetCheck_x                                     0x5628B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex_x                           0x662820
#define CChatManager__InitContextMenu_x                            0x663340

// CChatService
#define CChatService__GetNumberOfFriends_x                         0x81D4C0
#define CChatService__GetFriendName_x                              0x81D4D0

// CChatWindow 
#define CChatWindow__CChatWindow_x                                 0x6680D0
#define CChatWindow__Clear_x                                       0x667C90
#define CChatWindow__WndNotification_x                             0x668600

// CComboWnd 
#define CComboWnd__DeleteAll_x                                     0x895BC0
#define CComboWnd__Draw_x                                          0x895DA0
#define CComboWnd__GetCurChoice_x                                  0x8959E0
#define CComboWnd__GetListRect_x                                   0x896040
#define CComboWnd__GetTextRect_x                                   0x895C20
#define CComboWnd__InsertChoice_x                                  0x8960B0
#define CComboWnd__SetColors_x                                     0x895970
#define CComboWnd__SetChoice_x                                     0x8959A0

// CContainerWnd 
#define CContainerWnd__HandleCombine_x                             0x671810
#define CContainerWnd__vftable_x                                   0xA55F90

// CDisplay 
#define CDisplay__CleanGameUI_x                                    0x494340
#define CDisplay__GetClickedActor_x                                0x48CDE0
#define CDisplay__GetUserDefinedColor_x                            0x48B6A0
#define CDisplay__GetWorldFilePath_x                               0x48AAA0
#define CDisplay__is3dON_x                                         0x489E70
#define CDisplay__ReloadUI_x                                       0x49F760
#define CDisplay__WriteTextHD2_x                                   0x490630

// CEditBaseWnd 
#define CEditBaseWnd__SetSel_x                                     0x8B7AD0

// CEditWnd 
#define CEditWnd__DrawCaret_x                                      0x8A6660
#define CEditWnd__GetCharIndexPt_x                                 0x8A7690
#define CEditWnd__GetDisplayString_x                               0x8A6810
#define CEditWnd__GetHorzOffset_x                                  0x8A6B50
#define CEditWnd__GetLineForPrintableChar_x                        0x8A7150
#define CEditWnd__GetSelStartPt_x                                  0x8A7950
#define CEditWnd__GetSTMLSafeText_x                                0x8A6CF0
#define CEditWnd__PointFromPrintableChar_x                         0x8A7240
#define CEditWnd__SelectableCharFromPoint_x                        0x8A73C0
#define CEditWnd__SetEditable_x                                    0x8A6CC0

// CEverQuest 
#define CEverQuest__ClickedPlayer_x                                0x529E00
#define CEverQuest__DoTellWindow_x                                 0x52F780
#define CEverQuest__DropHeldItemOnGround_x                         0x538210
#define CEverQuest__dsp_chat_x                                     0x530F20
#define CEverQuest__Emote_x                                        0x531180
#define CEverQuest__EnterZone_x                                    0x544050
#define CEverQuest__GetBodyTypeDesc_x                              0x526730
#define CEverQuest__GetClassDesc_x                                 0x52C300
#define CEverQuest__GetClassThreeLetterCode_x                      0x52C900
#define CEverQuest__GetDeityDesc_x                                 0x527010
#define CEverQuest__GetLangDesc_x                                  0x526AC0
#define CEverQuest__GetRaceDesc_x                                  0x52CAC0
#define CEverQuest__InterpretCmd_x                                 0x531A60
#define CEverQuest__LeftClickedOnPlayer_x                          0x548440
#define CEverQuest__LMouseUp_x                                     0x54A730
#define CEverQuest__RightClickedOnPlayer_x                         0x548F40
#define CEverQuest__RMouseUp_x                                     0x549F80
#define CEverQuest__SetGameState_x                                 0x52A4B0
#define CEverQuest__UPCNotificationFlush_x                         0x532C00

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect_x                                  0x6823D0
#define CGaugeWnd__CalcLinesFillRect_x                             0x682430
#define CGaugeWnd__Draw_x                                          0x682860

// CGuild
#define CGuild__FindMemberByName_x                                 0x4245F0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton_x                               0x69F440

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot_x                                 0x6AB1D0
#define CInvSlotMgr__MoveItem_x                                    0x6AC110
#define CInvSlotMgr__SelectSlot_x                                  0x6AB280

// CInvSLot
#define CInvSlot__HandleRButtonUp_x                                0x6AA500
#define CInvSlot__SliderComplete_x                                 0x6A8350
#define CInvSlot__GetItemBase_x                                    0x6A77D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip_x                                 0x6ACEF0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell_x                                0x773E50
#define CItemDisplayWnd__UpdateStrings_x                           0x6AE220

// CLabel 
#define CLabel__Draw_x                                             0x6C8C90

// CListWnd 
#define CListWnd__AddColumn_x                                      0x883A60
#define CListWnd__AddColumn1_x                                     0x883250
#define CListWnd__AddLine_x                                        0x882D00
#define CListWnd__AddString_x                                      0x882F10
#define CListWnd__CalculateFirstVisibleLine_x                      0x87FDD0
#define CListWnd__CalculateVSBRange_x                              0x881F00
#define CListWnd__ClearAllSel_x                                    0x87F090
#define CListWnd__CloseAndUpdateEditWindow_x                       0x8828D0
#define CListWnd__Compare_x                                        0x8808D0
#define CListWnd__Draw_x                                           0x881B60
#define CListWnd__DrawColumnSeparators_x                           0x8819F0
#define CListWnd__DrawHeader_x                                     0x87F3A0
#define CListWnd__DrawItem_x                                       0x880F20
#define CListWnd__DrawLine_x                                       0x881690
#define CListWnd__DrawSeparator_x                                  0x881A90
#define CListWnd__EnsureVisible_x                                  0x87FF30
#define CListWnd__ExtendSel_x                                      0x880E30
#define CListWnd__GetColumnMinWidth_x                              0x87EAB0
#define CListWnd__GetColumnWidth_x                                 0x87E9D0
#define CListWnd__GetCurSel_x                                      0x87E2B0
#define CListWnd__GetItemAtPoint_x                                 0x8801D0
#define CListWnd__GetItemAtPoint1_x                                0x880240
#define CListWnd__GetItemData_x                                    0x87E4E0
#define CListWnd__GetItemHeight_x                                  0x87FA30
#define CListWnd__GetItemIcon_x                                    0x87E6C0
#define CListWnd__GetItemRect_x                                    0x880010
#define CListWnd__GetItemText_x                                    0x87E570
#define CListWnd__GetSelList_x                                     0x883140
#define CListWnd__GetSeparatorRect_x                               0x880800
#define CListWnd__RemoveLine_x                                     0x8830F0
#define CListWnd__SetColors_x                                      0x87E310
#define CListWnd__SetColumnJustification_x                         0x87ED80
#define CListWnd__SetColumnWidth_x                                 0x87EA60
#define CListWnd__SetCurSel_x                                      0x87E2F0
#define CListWnd__SetItemColor_x                                   0x8825B0
#define CListWnd__SetItemData_x                                    0x87F140
#define CListWnd__SetItemText_x                                    0x8823F0
#define CListWnd__ShiftColumnSeparator_x                           0x882280
#define CListWnd__Sort_x                                           0x883BC0
#define CListWnd__ToggleSel_x                                      0x87F010

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd_x                                 0x6E1F00

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice_x                      0x702E20
#define CMerchantWnd__RequestBuyItem_x                             0x709710
#define CMerchantWnd__RequestSellItem_x                            0x7313A0
#define CMerchantWnd__SelectRecoverySlot_x                         0x7030D0
#define CMerchantWnd__SelectBuySellSlot_x                          0x702330
#define CMerchantWnd__ActualSelect_x                               0x706B10

// CObfuscator
#define CObfuscator__doit_x                                        0x7FDB70

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1_x                   0x89B3E0
#define CSidlManager__CreateLabel_x                                0x769E90

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange_x                        0x6307C0
#define CSidlScreenWnd__CalculateVSBRange_x                        0x6306F0
#define CSidlScreenWnd__ConvertToRes_x                             0x8B79B0
#define CSidlScreenWnd__CreateChildrenFromSidl_x                   0x888BB0
#define CSidlScreenWnd__CSidlScreenWnd1_x                          0x88A0B0
#define CSidlScreenWnd__CSidlScreenWnd2_x                          0x88A160
#define CSidlScreenWnd__dCSidlScreenWnd_x                          0x889620
#define CSidlScreenWnd__DrawSidlPiece_x                            0x888690
#define CSidlScreenWnd__EnableIniStorage_x                         0x887DE0
#define CSidlScreenWnd__GetSidlPiece_x                             0x888880
#define CSidlScreenWnd__Init1_x                                    0x889D80
#define CSidlScreenWnd__LoadIniInfo_x                              0x888C60
#define CSidlScreenWnd__LoadIniListWnd_x                           0x887FA0
#define CSidlScreenWnd__LoadSidlScreen_x                           0x889870
#define CSidlScreenWnd__StoreIniInfo_x                             0x8878B0
#define CSidlScreenWnd__StoreIniVis_x                              0x887D70
#define CSidlScreenWnd__WndNotification_x                          0x889B00
#define CSidlScreenWnd__GetChildItem_x                             0x887EB0
#define CSidlScreenWnd__HandleLButtonUp_x                          0x88EB50

// CSkillMgr
#define CSkillMgr__IsAvailable_x                                   0x5CB8F0
#define CSkillMgr__GetSkillCap_x                                   0x5CBA90
#define CSkillMgr__GetNameToken_x                                  0x5CB560

// CSliderWnd 
#define CSliderWnd__GetValue_x                                     0x8C1A90
#define CSliderWnd__SetValue_x                                     0x8C1C60
#define CSliderWnd__SetNumTicks_x                                  0x8C23E0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet_x                               0x771AF0

// CStmlWnd
#define CStmlWnd__AppendSTML_x                                     0x8B1D80
#define CStmlWnd__CalculateHSBRange_x                              0x8AA2B0
#define CStmlWnd__CalculateVSBRange_x                              0x8AA340
#define CStmlWnd__CanBreakAtCharacter_x                            0x8AA4C0
#define CStmlWnd__FastForwardToEndOfTag_x                          0x8AADA0
#define CStmlWnd__ForceParseNow_x                                  0x8B26D0
#define CStmlWnd__GetNextTagPiece_x                                0x8AACA0
#define CStmlWnd__GetSTMLText_x                                    0x667530
#define CStmlWnd__GetVisibleText_x                                 0x8AB7F0
#define CStmlWnd__InitializeWindowVariables_x                      0x8ADB60
#define CStmlWnd__MakeStmlColorTag_x                               0x8A95B0
#define CStmlWnd__MakeWndNotificationTag_x                         0x8A9610
#define CStmlWnd__SetSTMLText_x                                    0x8AF3C0
#define CStmlWnd__StripFirstSTMLLines_x                            0x8B1A20
#define CStmlWnd__UpdateHistoryString_x                            0x8AC720

// CTabWnd 
#define CTabWnd__Draw_x                                            0x8B9280
#define CTabWnd__DrawCurrentPage_x                                 0x8B8AF0
#define CTabWnd__DrawTab_x                                         0x8B88B0
#define CTabWnd__GetCurrentPage_x                                  0x8B8EC0
#define CTabWnd__GetPageInnerRect_x                                0x8B85A0
#define CTabWnd__GetTabInnerRect_x                                 0x8B87A0
#define CTabWnd__GetTabRect_x                                      0x8B8670
#define CTabWnd__InsertPage_x                                      0x8B9570
#define CTabWnd__SetPage_x                                         0x8B8EF0
#define CTabWnd__SetPageRect_x                                     0x8B91C0
#define CTabWnd__UpdatePage_x                                      0x8B9510

// CTextOverlay 
#define CTextOverlay__DisplayText_x                                0x4202D0

// CTextureFont
#define CTextureFont__DrawWrappedText_x                            0x8B5210

// CXMLDataManager 
#define CXMLDataManager__GetXMLData_x                              0x8BE450

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead_x                             0x87C370

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr_x                                             0x411620
#define CXStr__CXStr1_x                                            0x7B41D0
#define CXStr__CXStr3_x                                            0x8338F0
#define CXStr__dCXStr_x                                            0x774EF0
#define CXStr__operator_equal_x                                    0x833A60
#define CXStr__operator_equal1_x                                   0x833AB0
#define CXStr__operator_plus_equal1_x                              0x834B90

// CXWnd 
#define CXWnd__BringToTop_x                                        0x88DD60
#define CXWnd__Center_x                                            0x893FF0
#define CXWnd__ClrFocus_x                                          0x88D930
#define CXWnd__DoAllDrawing_x                                      0x893C40
#define CXWnd__DrawChildren_x                                      0x893DE0
#define CXWnd__DrawColoredRect_x                                   0x88E110
#define CXWnd__DrawTooltip_x                                       0x88E3B0
#define CXWnd__DrawTooltipAtPoint_x                                0x892BA0
#define CXWnd__GetBorderFrame_x                                    0x88E810
#define CXWnd__GetChildWndAt_x                                     0x891B60
#define CXWnd__GetClientClipRect_x                                 0x88E5C0
#define CXWnd__GetScreenClipRect_x                                 0x8932A0
#define CXWnd__GetScreenRect_x                                     0x88E9E0
#define CXWnd__GetTooltipRect_x                                    0x88E240
#define CXWnd__GetWindowTextA_x                                    0x411660
#define CXWnd__IsActive_x                                          0x8A1370
#define CXWnd__IsDescendantOf_x                                    0x88E750
#define CXWnd__IsReallyVisible_x                                   0x891B40
#define CXWnd__IsType_x                                            0x8BAC30
#define CXWnd__Move_x                                              0x891220
#define CXWnd__Move1_x                                             0x8938F0
#define CXWnd__ProcessTransition_x                                 0x88DD10
#define CXWnd__Refade_x                                            0x88DAE0
#define CXWnd__Resize_x                                            0x88EAB0
#define CXWnd__Right_x                                             0x8930A0
#define CXWnd__SetFocus_x                                          0x890380
#define CXWnd__SetFont_x                                           0x88D980
#define CXWnd__SetKeyTooltip_x                                     0x88ED20
#define CXWnd__SetMouseOver_x                                      0x8935E0
#define CXWnd__StartFade_x                                         0x88DDB0
#define CXWnd__GetChildItem_x                                      0x893520

// CXWndManager 
#define CXWndManager__DrawCursor_x                                 0x8A2CA0
#define CXWndManager__DrawWindows_x                                0x8A28E0
#define CXWndManager__GetKeyboardFlags_x                           0x8A0EA0
#define CXWndManager__HandleKeyboardMsg_x                          0x8A1800
#define CXWndManager__RemoveWnd_x                                  0x8A1500

// CDBStr
#define CDBStr__GetString_x                                        0x488310

// EQ_Character 
#define EQ_Character__CastRay_x                                    0x8F1C00
#define EQ_Character__CastSpell_x                                  0x43C5D0
#define EQ_Character__Cur_HP_x                                     0x452010
#define EQ_Character__GetAACastingTimeModifier_x                   0x4356A0
#define EQ_Character__GetCharInfo2_x                               0x8081F0
#define EQ_Character__GetFocusCastingTimeModifier_x                0x42DA70
#define EQ_Character__GetFocusRangeModifier_x                      0x42DC50
#define EQ_Character__Max_Endurance_x                              0x5941F0
#define EQ_Character__Max_HP_x                                     0x448630
#define EQ_Character__Max_Mana_x                                   0x594020
#define EQ_Character__doCombatAbility_x                            0x591850
#define EQ_Character__UseSkill_x                                   0x45CB50
#define EQ_Character__GetConLevel_x                                0x586DB0
#define EQ_Character__IsExpansionFlag_x                            0x410B60
#define EQ_Character__TotalEffect_x                                0x43A700

// EQ_Item 
#define EQ_Item__CanDrop_x                                         0x5678C0
#define EQ_Item__CreateItemTagString_x                             0x7E8910
#define EQ_Item__IsStackable_x                                     0x7DCB60
#define EQ_Item__GetImageNum_x                                     0x7DF7A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar_x                              0x4A7B10
#define EQ_LoadingS__Array_x                                       0xB69ED0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney_x                            0x595850
#define EQ_PC__GetAltAbilityIndex_x                                0x7F0CB0
#define EQ_PC__GetCombatAbility_x                                  0x7F0D40
#define EQ_PC__GetCombatAbilityTimer_x                             0x7F0DF0
#define EQ_PC__GetItemTimerValue_x                                 0x58F620
#define EQ_PC__HasLoreItem_x                                       0x589F30
#define EQ_PC__AlertInventoryChanged_x                             0x586D80
#define EQ_PC__GetPcZoneClient_x                                   0x5AFA80
#define EQ_PC__RemoveMyAffect_x									   0x58EB50

// EQItemList 
#define EQItemList__EQItemList_x                                   0x4E53D0
#define EQItemList__add_item_x                                     0x4E5310
#define EQItemList__delete_item_x                                  0x4E57D0
#define EQItemList__FreeItemList_x                                 0x4E56D0

// EQMisc
#define EQMisc__GetActiveFavorCost_x                               0x487790

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite_x                         0x59ACA0
#define EQPlayer__dEQPlayer_x                                      0x5A3900
#define EQPlayer__DoAttack_x                                       0x5B5880
#define EQPlayer__EQPlayer_x                                       0x5A5D50
#define EQPlayer__SetNameSpriteState_x                             0x5A06B0
#define EQPlayer__SetNameSpriteTint_x                              0x59C030
#define EQPlayer__IsBodyType_j_x                                   0x8F0EB0
#define EQPlayer__IsTargetable_x                                   0x8F16E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID_x                            0x5AA090
#define EQPlayerManager__GetSpawnByName_x                          0x5AA4F0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand_x                 0x56D990
#define KeypressHandler__AttachKeyToEqCommand_x                    0x56D9D0
#define KeypressHandler__ClearCommandStateArray_x                  0x56D570
#define KeypressHandler__HandleKeyDown_x                           0x56BEC0
#define KeypressHandler__HandleKeyUp_x                             0x56C1E0
#define KeypressHandler__SaveKeymapping_x                          0x56D640

// MapViewMap 
#define MapViewMap__Clear_x                                        0x6DA2E0
#define MapViewMap__SaveEx_x                                       0x6DDBC0

#define PlayerPointManager__GetAltCurrency_x                       0x8023E0

// StringTable 
#define StringTable__getString_x                                   0x7FDE10

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit_x                            0x593CA0

//Doors
#define EQSwitch__UseSwitch_x                                      0x523B80

//IconCache
#define IconCache__GetIcon_x                                       0x677B30

//CContainerMgr
#define CContainerMgr__OpenContainer_x                             0x66EB40
#define CContainerMgr__CloseContainer_x                            0x66F350

//CQuantityWnd
#define CQuantityWnd__Open_x                                       0x73A320

//CHelpWnd
#define CHelpWnd__SetFile_x                                        0x561370

//EQ_Spell
#define EQ_Spell__GetSpellLevelNeeded_x                            0x4B6000
#define EQ_Spell__SpellAffects_x                                   0x4B60A0
#define EQ_Spell__GetSpellBaseByAttrib_x                           0x4B60D0
#define CharacterZoneClient__CalcAffectChange_x                    0x4369C0
#define CLootWnd__LootAll_x                                        0x6CFE20
#define CTargetWnd__GetBuffCaster_x                                0x77F780
