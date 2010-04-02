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
#define __ExpectedVersionDate                                     "Apr 23 2008"
#define __ExpectedVersionTime                                     "17:30:55"
#define __ActualVersionDate                                        0x71A344
#define __ActualVersionTime                                        0x71A350

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                              0x4FB680
#define __MemChecker1                                              0x6650F0
#define __MemChecker2                                              0x52FDE0
#define __MemChecker3                                              0x52FD30
#define __MemChecker4                                              0x629750
#define __EncryptPad0                                              0x775120
#define __EncryptPad1                                              0x77EEB8
#define __EncryptPad2                                              0x777A98
#define __EncryptPad3                                              0x777698
#define __EncryptPad4                                              0x77E598

// Direct Input
#define DI8__Main                                                  0x9BD4BC
#define DI8__Keyboard                                              0x9BD4C0
#define DI8__Mouse                                                 0x9BD4C4
#define __AltTimerReady                                            0x94A23A
#define __Attack                                                   0x9A7B7E
#define __Autofire                                                 0x9A7B7F
#define __BindList                                                 0x7702C8
#define __Clicks                                                   0x948F58
#define __CommandList                                              0x770AD8
#define __CurrentMapLabel                                          0x9E86D8
#define __CurrentSocial                                            0x76C544
#define __DoAbilityAvailable                                       0x94A1D4
#define __DoAbilityList                                            0x97F69C
#define __do_loot                                                  0x4A5690
#define __DrawHandler                                              0x9F79B4
#define __GroupCount                                               0x92946A
#define __GroupLeader                                              0x9297BC
#define __Guilds                                                   0x92B188
#define __gWorld                                                   0x92B0C4
#define __HotkeyPage                                               0x9A6A88
#define __HWnd                                                     0x9BD1FC
#define __InChatMode                                               0x948E90
#define __LastTell                                                 0x94AB34
#define __LMouseHeldTime                                           0x948F78
#define __Mouse                                                    0x9BD4C8
#define __MouseLook                                                0x948F26
#define __NetStatusToggle                                          0x948F28
#define __PCNames                                                  0x94A58C
#define __RangeAttackReady                                         0x94A238
#define __RMouseHeldTime                                           0x948F74
#define __RunWalkState                                             0x948E94
#define __ScreenMode                                               0x878DD0
#define __ScreenX                                                  0x948E48
#define __ScreenY                                                  0x948E4C
#define __ScreenXMax                                               0x948E50
#define __ScreenYMax                                               0x948E54
#define __ServerHost                                               0x9293B4
#define __ServerName                                               0x97F65C
#define __ShiftKeyDown                                             0x9494F0
#define __ShowNames                                                0x94A464
#define __Socials                                                  0x97F75C


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x942DD8
#define instEQZoneInfo                                             0x9490C4
#define instKeypressHandler                                        0x9A7C68
#define pinstActiveBanker                                          0x92B15C
#define pinstActiveCorpse                                          0x92B160
#define pinstActiveGMaster                                         0x92B164
#define pinstActiveMerchant                                        0x92B158
#define pinstAltAdvManager                                         0x879C20
#define pinstAuraMgr                                               0x784C6C
#define pinstBandageTarget                                         0x92B144
#define pinstCamActor                                              0x879710
#define pinstCDBStr                                                0x878DC0
#define pinstCDisplay                                              0x92B16C
#define pinstCEverQuest                                            0x9BD640
#define pinstCharData                                              0x92B128
#define pinstCharSpawn                                             0x92B150
#define pinstControlledMissile                                     0x92B124
#define pinstControlledPlayer                                      0x92B150
#define pinstCSidlManager                                          0x9F7180
#define pinstCXWndManager                                          0x9F7178
#define instDynamicZone                                            0x948898
#define pinstDZMember                                              0x9489A8
#define pinstDZTimerInfo                                           0x9489AC
#define pinstEQItemList                                            0x92B10C
#define instEQMisc                                                 0x878D78
#define pinstEQSoundManager                                        0x879C44
#define instExpeditionLeader                                       0x9488E2
#define instExpeditionName                                         0x948922
#define instGroup                                                  0x929660
#define pinstGroup                                                 0x929466
#define pinstImeManager                                            0x9F7184
#define pinstLocalPlayer                                           0x92B13C
#define pinstModelPlayer                                           0x92B168
#define pinstPCData                                                0x92B128
#define pinstSkillMgr                                              0x9BA42C
#define pinstSpawnManager                                          0x9BA3AC
#define pinstSpellManager                                          0x9BA430
#define pinstSpellSets                                             0x9A6A8C
#define pinstStringTable                                           0x92B0E0
#define pinstSwitchManager                                         0x9290B4
#define pinstTarget                                                0x92B154
#define pinstTargetObject                                          0x92B12C
#define pinstTargetSwitch                                          0x92B130
#define pinstTaskMember                                            0x878D58
#define pinstTrackTarget                                           0x92B148
#define pinstTradeTarget                                           0x92B138
#define instTributeActive                                          0x878D9D
#define pinstViewActor                                             0x87970C
#define pinstWorldData                                             0x92B108


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x782520
#define pinstCAudioTriggersWindow                                  0x7824EC
#define pinstCCharacterSelect                                      0x879620
#define pinstCFacePick                                             0x8795D8
#define pinstCNoteWnd                                              0x8795DC
#define pinstCBookWnd                                              0x8795E0
#define pinstCPetInfoWnd                                           0x8795E4
#define pinstCTrainWnd                                             0x8795E8
#define pinstCSkillsWnd                                            0x8795EC
#define pinstCSkillsSelectWnd                                      0x8795F0
#define pinstCCombatSkillSelectWnd                                 0x8795F4
#define pinstCFriendsWnd                                           0x8795F8
#define pinstCAuraWnd                                              0x8795FC
#define pinstCRespawnWnd                                           0x879600
#define pinstCBandolierWnd                                         0x879604
#define pinstCPotionBeltWnd                                        0x879608
#define pinstCAAWnd                                                0x87960C
#define pinstCGroupSearchFiltersWnd                                0x879610
#define pinstCLoadskinWnd                                          0x879614
#define pinstCAlarmWnd                                             0x879618
#define pinstCMusicPlayerWnd                                       0x87961C
#define pinstCMailWnd                                              0x879624
#define pinstCMailCompositionWnd                                   0x879628
#define pinstCMailAddressBookWnd                                   0x87962C
#define pinstCRaidWnd                                              0x879634
#define pinstCRaidOptionsWnd                                       0x879638
#define pinstCBreathWnd                                            0x87963C
#define pinstCMapViewWnd                                           0x879640
#define pinstCMapToolbarWnd                                        0x879644
#define pinstCEditLabelWnd                                         0x879648
#define pinstCTargetWnd                                            0x87964C
#define pinstCColorPickerWnd                                       0x879650
#define pinstCPlayerWnd                                            0x879654
#define pinstCOptionsWnd                                           0x879658
#define pinstCBuffWindowNORMAL                                     0x87965C
#define pinstCBuffWindowSHORT                                      0x879660
#define pinstCharacterCreation                                     0x879664
#define pinstCCursorAttachment                                     0x879668
#define pinstCCastingWnd                                           0x87966C
#define pinstCCastSpellWnd                                         0x879670
#define pinstCSpellBookWnd                                         0x879674
#define pinstCInventoryWnd                                         0x879678
#define pinstCBankWnd                                              0x87967C
#define pinstCQuantityWnd                                          0x879680
#define pinstCLootWnd                                              0x879684
#define pinstCActionsWnd                                           0x879688
#define pinstCCombatAbilityWnd                                     0x87968C
#define pinstCMerchantWnd                                          0x879690
#define pinstCTradeWnd                                             0x879694
#define pinstCSelectorWnd                                          0x879698
#define pinstCBazaarWnd                                            0x87969C
#define pinstCBazaarSearchWnd                                      0x8796A0
#define pinstCGiveWnd                                              0x8796A4
#define pinstCTrackingWnd                                          0x8796A8
#define pinstCInspectWnd                                           0x8796AC
#define pinstCSocialEditWnd                                        0x8796B0
#define pinstCFeedbackWnd                                          0x8796B4
#define pinstCBugReportWnd                                         0x8796B8
#define pinstCVideoModesWnd                                        0x8796BC
#define pinstCTextEntryWnd                                         0x8796C4
#define pinstCFileSelectionWnd                                     0x8796C8
#define pinstCCompassWnd                                           0x8796CC
#define pinstCPlayerNotesWnd                                       0x8796D0
#define pinstCGemsGameWnd                                          0x8796D4
#define pinstCTimeLeftWnd                                          0x8796D8
#define pinstCPetitionQWnd                                         0x8796DC
#define pinstCSoulmarkWnd                                          0x8796E0
#define pinstCStoryWnd                                             0x8796E4
#define pinstCJournalTextWnd                                       0x8796E8
#define pinstCJournalCatWnd                                        0x8796EC
#define pinstCBodyTintWnd                                          0x8796F0
#define pinstCServerListWnd                                        0x8796F4
#define pinstCAvaZoneWnd                                           0x8796F8
#define pinstCBlockedBuffWnd                                       0x8796FC
#define pinstCBlockedPetBuffWnd                                    0x879700
#define pinstCInvSlotMgr                                           0x879704
#define pinstCContainerMgr                                         0x879708
#define pinstCAdventureLeaderboardWnd                              0x9E5C28
#define pinstCAdventureRequestWnd                                  0x9E5C44
#define pinstCAltStorageWnd                                        0x9E5CA4
#define pinstCAdventureStatsWnd                                    0x9E5C60
#define pinstCBarterMerchantWnd                                    0x9E5E70
#define pinstCBarterSearchWnd                                      0x9E5E8C
#define pinstCBarterWnd                                            0x9E5EA8
#define pinstCChatManager                                          0x9E614C
#define pinstCDynamicZoneWnd                                       0x9E6244
#define pinstCEQMainWnd                                            0x9E62B4
#define pinstCFellowshipWnd                                        0x9E6318
#define pinstCFindLocationWnd                                      0x9E634C
#define pinstCGroupSearchWnd                                       0x9E63FC
#define pinstCGroupWnd                                             0x9E6418
#define pinstCGuildBankWnd                                         0x9E6434
#define pinstCGuildMgmtWnd                                         0x9E8450
#define pinstCGuildTributeMasterWnd                                0x9E8470
#define pinstCHotButtonWnd                                         0x9E848C
#define pinstCHotButtonWnd1                                        0x9E848C
#define pinstCHotButtonWnd2                                        0x9E8490
#define pinstCHotButtonWnd3                                        0x9E8494
#define pinstCHotButtonWnd4                                        0x9E8498
#define pinstCItemDisplayManager                                   0x9E8544
#define pinstCItemExpTransferWnd                                   0x9E8564
#define pinstCLeadershipWnd                                        0x9E8600
#define pinstCLFGuildWnd                                           0x9E861C
#define pinstCMIZoneSelectWnd                                      0x9E8740
#define pinstCAdventureMerchantWnd                                 0x9E8838
#define pinstCConfirmationDialog                                   0x9E8854
#define pinstCPopupWndManager                                      0x9E8854
#define pinstCProgressionSelectionWnd                              0x9E8888
#define pinstCPvPLeaderboardWnd                                    0x9E88A4
#define pinstCPvPStatsWnd                                          0x9E88C0
#define pinstCSystemInfoDialogBox                                  0x9E8970
#define pinstCTargetOfTargetWnd                                    0x9E9264
#define pinstCTaskSelectWnd                                        0x9E9280
#define pinstCTaskTemplateSelectWnd                                0x9E929C
#define pinstCTaskWnd                                              0x9E92B8
#define pinstCTipWndOFDAY                                          0x9E9334
#define pinstCTipWndCONTEXT                                        0x9E9338
#define pinstCTitleWnd                                             0x9E9354
#define pinstCTradeskillWnd                                        0x9E9398
#define pinstCTributeBenefitWnd                                    0x9E93E4
#define pinstCTributeMasterWnd                                     0x9E9400
#define pinstCContextMenuManager                                   0x9F71DC
#define pinstCVoiceMacroWnd                                        0x9BA51C
#define pinstCHtmlWnd                                              0x9BA538


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4B7740
#define __ConvertItemTags                                          0x4AAA10
#define __ExecuteCmd                                               0x499F80
#define __get_melee_range                                          0x49F100
#define __GetGaugeValueFromEQ                                      0x5FAEF0
#define __GetLabelFromEQ                                           0x5FB700
#define __NewUIINI                                                 0x5FAAE0
#define __ProcessGameEvents                                        0x4E6A30
#define CrashDetected                                              0x52EAB0
#define DrawNetStatus                                              0x4FE480
#define Util__FastTime                                             0x665840


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x473610
#define AltAdvManager__IsAbilityReady                              0x473650
#define AltAdvManager__GetAltAbility                               0x473830

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x545E90

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x54F2B0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6912A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x564220
#define CChatManager__InitContextMenu                              0x5649B0

// CChatService
#define CChatService__GetNumberOfFriends                           0x655B20
#define CChatService__GetFriendName                                0x655B30

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x568B20
#define CChatWindow__WndNotification                               0x569510

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6775D0
#define CComboWnd__Draw                                            0x677780
#define CComboWnd__GetCurChoice                                    0x677570
#define CComboWnd__GetListRect                                     0x677A40
#define CComboWnd__GetTextRect                                     0x677600
#define CComboWnd__InsertChoice                                    0x677AB0
#define CComboWnd__SetColors                                       0x677500
#define CComboWnd__SetChoice                                       0x677530

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x56FE10
#define CContainerWnd__vftable                                     0x720C80

// CDisplay 
#define CDisplay__CleanGameUI                                      0x462810
#define CDisplay__GetClickedActor                                  0x45FF20
#define CDisplay__GetUserDefinedColor                              0x45F0A0
#define CDisplay__GetWorldFilePath                                 0x45E610
#define CDisplay__is3dON                                           0x45D770
#define CDisplay__ReloadUI                                         0x46E380
#define CDisplay__WriteTextHD2                                     0x462F00

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x540010
#define CEditBaseWnd__SetSel                                       0x69C230

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6854F0
#define CEditWnd__GetCharIndexPt                                   0x686350
#define CEditWnd__GetDisplayString                                 0x685690
#define CEditWnd__GetHorzOffset                                    0x685920
#define CEditWnd__GetLineForPrintableChar                          0x685E00
#define CEditWnd__GetSelStartPt                                    0x686590
#define CEditWnd__GetSTMLSafeText                                  0x685AC0
#define CEditWnd__PointFromPrintableChar                           0x685F10
#define CEditWnd__SelectableCharFromPoint                          0x686090
#define CEditWnd__SetEditable                                      0x685A90

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4CABF0
#define CEverQuest__DropHeldItemOnGround                           0x4CEE60
#define CEverQuest__dsp_chat                                       0x4D0340
#define CEverQuest__DoTellWindow                                   0x4CEFE0
#define CEverQuest__EnterZone                                      0x4E5410
#define CEverQuest__GetBodyTypeDesc                                0x4C8070
#define CEverQuest__GetClassDesc                                   0x4C77D0
#define CEverQuest__GetClassThreeLetterCode                        0x4C7DD0
#define CEverQuest__GetDeityDesc                                   0x4C86E0
#define CEverQuest__GetLangDesc                                    0x4C8400
#define CEverQuest__GetRaceDesc                                    0x4C86B0
#define CEverQuest__InterpretCmd                                   0x4D0D70
#define CEverQuest__LeftClickedOnPlayer                            0x4E3C30
#define CEverQuest__LMouseUp                                       0x4E6210
#define CEverQuest__RightClickedOnPlayer                           0x4E4000
#define CEverQuest__RMouseUp                                       0x4E5A10
#define CEverQuest__SetGameState                                   0x4CB070
#define CEverQuest__Emote                                          0x4D0510

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x57C1E0
#define CGaugeWnd__CalcLinesFillRect                               0x57C250
#define CGaugeWnd__Draw                                            0x57C5D0

// CGuild
#define CGuild__FindMemberByName                                   0x417B70

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x592AB0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x59BEE0
#define CInvSlotMgr__MoveItem                                      0x59C080

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x59A8C0
#define CInvSlot__SliderComplete                                   0x59ADD0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5AAFB0
#define CItemDisplayWnd__SetSpell                                  0x5F8E10

// CLabel 
#define CLabel__Draw                                               0x5B0800

// CListWnd 
#define CListWnd__AddColumn                                        0x677310
#define CListWnd__AddColumn1                                       0x676E00
#define CListWnd__AddLine                                          0x6769E0
#define CListWnd__AddString                                        0x676BB0
#define CListWnd__CalculateFirstVisibleLine                        0x673DA0
#define CListWnd__CalculateVSBRange                                0x6759B0
#define CListWnd__ClearAllSel                                      0x6734F0
#define CListWnd__CloseAndUpdateEditWindow                         0x6743A0
#define CListWnd__Compare                                          0x674730
#define CListWnd__Draw                                             0x6756B0
#define CListWnd__DrawColumnSeparators                             0x675520
#define CListWnd__DrawHeader                                       0x6736C0
#define CListWnd__DrawItem                                         0x674E30
#define CListWnd__DrawLine                                         0x6751D0
#define CListWnd__DrawSeparator                                    0x6755C0
#define CListWnd__EnsureVisible                                    0x673DF0
#define CListWnd__ExtendSel                                        0x674D60
#define CListWnd__GetColumnMinWidth                                0x673290
#define CListWnd__GetColumnWidth                                   0x6731D0
#define CListWnd__GetCurSel                                        0x672CA0
#define CListWnd__GetHeaderRect                                    0x672DA0
#define CListWnd__GetItemAtPoint                                   0x6740C0
#define CListWnd__GetItemAtPoint1                                  0x674130
#define CListWnd__GetItemData                                      0x672F80
#define CListWnd__GetItemHeight                                    0x673B30
#define CListWnd__GetItemIcon                                      0x673110
#define CListWnd__GetItemRect                                      0x673EB0
#define CListWnd__GetItemText                                      0x672FC0
#define CListWnd__GetSelList                                       0x676CE0
#define CListWnd__GetSeparatorRect                                 0x674670
#define CListWnd__RemoveLine                                       0x6772C0
#define CListWnd__SetColors                                        0x672D00
#define CListWnd__SetColumnJustification                           0x6732F0
#define CListWnd__SetColumnWidth                                   0x673250
#define CListWnd__SetCurSel                                        0x672CE0
#define CListWnd__SetItemColor                                     0x6765B0
#define CListWnd__SetItemData                                      0x673590
#define CListWnd__SetItemText                                      0x676530
#define CListWnd__ShiftColumnSeparator                             0x674CD0
#define CListWnd__Sort                                             0x677340
#define CListWnd__ToggleSel                                        0x673460

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5C5530

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5C7010
#define CMerchantWnd__RequestBuyItem                               0x5C8340
#define CMerchantWnd__RequestSellItem                              0x5C7260
#define CMerchantWnd__SelectBuySellSlot                            0x5C8070

// CObfuscator
#define CObfuscator__doit                                          0x63CB50

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x68CF60
#define CSidlManager__CreateLabel                                  0x5F2420

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x67D290
#define CSidlScreenWnd__CalculateVSBRange                          0x67D1E0
#define CSidlScreenWnd__ConvertToRes                               0x69C110
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x67EBB0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x67F9F0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x67FAA0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x67F440
#define CSidlScreenWnd__DrawSidlPiece                              0x67E890
#define CSidlScreenWnd__EnableIniStorage                           0x67E3A0
#define CSidlScreenWnd__GetSidlPiece                               0x67EA90
#define CSidlScreenWnd__Init1                                      0x67F860
#define CSidlScreenWnd__LoadIniInfo                                0x67EC60
#define CSidlScreenWnd__LoadIniListWnd                             0x67E4F0
#define CSidlScreenWnd__LoadSidlScreen                             0x67E6B0
#define CSidlScreenWnd__StoreIniInfo                               0x67DFB0
#define CSidlScreenWnd__WndNotification                            0x67E7F0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x51F800

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x69CE20
#define CSliderWnd__SetValue                                       0x69CF20
#define CSliderWnd__SetNumTicks                                    0x69D490

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5F7AB0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x69A3F0
#define CStmlWnd__CalculateVSBRange                                0x6759B0
#define CStmlWnd__CanBreakAtCharacter                              0x692900
#define CStmlWnd__FastForwardToEndOfTag                            0x693400
#define CStmlWnd__ForceParseNow                                    0x69A840
#define CStmlWnd__GetNextTagPiece                                  0x693320
#define CStmlWnd__GetSTMLText                                      0x568AC0
#define CStmlWnd__GetThisChar                                      0x6BA800
#define CStmlWnd__GetVisiableText                                  0x694620
#define CStmlWnd__InitializeWindowVariables                        0x696760
#define CStmlWnd__MakeStmlColorTag                                 0x691EA0
#define CStmlWnd__MakeWndNotificationTag                           0x691F40
#define CStmlWnd__SetSTMLText                                      0x696870
#define CStmlWnd__StripFirstSTMLLines                              0x69A180
#define CStmlWnd__UpdateHistoryString                              0x694E80

// CTabWnd 
#define CTabWnd__Draw                                              0x69E290
#define CTabWnd__DrawCurrentPage                                   0x69DC30
#define CTabWnd__DrawTab                                           0x69DA10
#define CTabWnd__GetCurrentPage                                    0x69DF30
#define CTabWnd__GetPageClientRect                                 0x69D6E0
#define CTabWnd__GetPageFromTabIndex                               0x69D940
#define CTabWnd__GetPageInnerRect                                  0x69D740
#define CTabWnd__GetTabInnerRect                                   0x69D8C0
#define CTabWnd__GetTabRect                                        0x69D7D0
#define CTabWnd__IndexInBounds                                     0x69D9DD
#define CTabWnd__InsertPage                                        0x69E4B0
#define CTabWnd__SetPage                                           0x69DF70
#define CTabWnd__SetPageRect                                       0x69E1C0
#define CTabWnd__UpdatePage                                        0x69E430

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x414060

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x67FE00

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6A39A0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x672A10

// CXRect 
#define CXRect__CenterPoint                                        0x5455F0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4123F0
#define CXStr__CXStr1                                              0x66C130
#define CXStr__CXStr3                                              0x666F90
#define CXStr__dCXStr                                              0x5EE990
#define CXStr__operator_equal1                                     0x667150
#define CXStr__operator_plus_equal1                                0x668050

// CXWnd 
#define CXWnd__BringToTop                                          0x678330
#define CXWnd__Center                                              0x67BFC0
#define CXWnd__ClrFocus                                            0x678020
#define CXWnd__DoAllDrawing                                        0x67CAB0
#define CXWnd__DrawChildren                                        0x67CBE0
#define CXWnd__DrawColoredRect                                     0x6785B0
#define CXWnd__DrawTooltip                                         0x67C9D0
#define CXWnd__DrawTooltipAtPoint                                  0x67BD90
#define CXWnd__GetBorderFrame                                      0x678A70
#define CXWnd__GetChildWndAt                                       0x67B830
#define CXWnd__GetClientClipRect                                   0x6789A0
#define CXWnd__GetFirstChildWnd                                    0x6783D0
#define CXWnd__GetNextChildWnd                                     0x67B7F0
#define CXWnd__GetNextSib                                          0x6783F0
#define CXWnd__GetScreenClipRect                                   0x67C1E0
#define CXWnd__GetScreenRect                                       0x678C30
#define CXWnd__GetTooltipRect                                      0x6787D0
#define CXWnd__GetWindowTextA                                      0x539100
#define CXWnd__IsActive                                            0x680F00
#define CXWnd__IsDescendantOf                                      0x678A20
#define CXWnd__IsReallyVisible                                     0x67B7D0
#define CXWnd__IsType                                              0x69F3A0
#define CXWnd__Move                                                0x67B280
#define CXWnd__Move1                                               0x67B320
#define CXWnd__ProcessTransition                                   0x6782F0
#define CXWnd__Refade                                              0x6780D0
#define CXWnd__Resize                                              0x678D00
#define CXWnd__Right                                               0x67C120
#define CXWnd__SetFirstChildPointer                                0x678EC0
#define CXWnd__SetFocus                                            0x67A2F0
#define CXWnd__SetKeyTooltip                                       0x678F30
#define CXWnd__SetMouseOver                                        0x678F00
#define CXWnd__SetNextSibPointer                                   0x678EE0
#define CXWnd__StartFade                                           0x678350

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x682420
#define CXWndManager__DrawWindows                                  0x682060
#define CXWndManager__GetFirstChildWnd                             0x681950
#define CXWndManager__GetKeyboardFlags                             0x680BC0
#define CXWndManager__HandleKeyboardMsg                            0x6811A0
#define CXWndManager__RemoveWnd                                    0x6810C0

// CDBStr
#define CDBStr__GetString                                          0x45C0F0

// EQ_Character 
#define EQ_Character__CastRay                                      0x6C6750
#define EQ_Character__CastSpell                                    0x425040
#define EQ_Character__Cur_HP                                       0x4317A0
#define EQ_Character__GetAACastingTimeModifier                     0x41FA20
#define EQ_Character__GetCharInfo2                                 0x647F80
#define EQ_Character__GetFocusCastingTimeModifier                  0x41B6C0
#define EQ_Character__GetFocusRangeModifier                        0x41B7F0
#define EQ_Character__Max_Endurance                                0x42CDA0
#define EQ_Character__Max_HP                                       0x42CC20
#define EQ_Character__Max_Mana                                     0x5045B0
#define EQ_Character__doCombatAbility                              0x503270
#define EQ_Character__UseSkill                                     0x437890
#define EQ_Character__GetConLevel                                  0x4FF940

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F3420
#define EQ_Item__GetItemLinkHash                                   0x63C200
#define EQ_Item__IsStackable                                       0x6330D0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x4746F0
#define EQ_LoadingS__Array                                         0x76E7D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x5075F0
#define EQ_PC__GetAltAbilityIndex                                  0x640CA0
#define EQ_PC__GetCombatAbility                                    0x640D30
#define EQ_PC__GetCombatAbilityTimer                               0x640DE0
#define EQ_PC__GetItemTimerValue                                   0x5021A0
#define EQ_PC__HasLoreItem                                         0x505A50

// EQItemList 
#define EQItemList__dEQItemList                                    0x49D860
#define EQItemList__EQItemList                                     0x49D7B0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45B970

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x50BDA0
#define EQPlayer__dEQPlayer                                        0x510630
#define EQPlayer__DoAttack                                         0x51C2A0
#define EQPlayer__EQPlayer                                         0x5132C0
#define EQPlayer__SetNameSpriteState                               0x50E540
#define EQPlayer__SetNameSpriteTint                                0x50BE10
#define EQPlayer__IsBodyType_j                                     0x6C6120

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5142F0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F5030
#define KeypressHandler__AttachKeyToEqCommand                      0x4F5070
#define KeypressHandler__ClearCommandStateArray                    0x4F4E40
#define KeypressHandler__HandleKeyDown                             0x4F3A20
#define KeypressHandler__HandleKeyUp                               0x4F3D20
#define KeypressHandler__SaveKeymapping                            0x4F4F10

// MapViewMap 
#define MapViewMap__Clear                                          0x5C0C20
#define MapViewMap__SaveEx                                         0x5C15F0

#define OtherCharData__GetAltCurrency                              0x65E100

// StringTable 
#define StringTable__getString                                     0x632AA0
