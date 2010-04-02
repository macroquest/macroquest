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
#define __ExpectedVersionDate                                     "May  6 2008"
#define __ExpectedVersionTime                                     "10:36:19"
#define __ActualVersionDate                                        0x71A344
#define __ActualVersionTime                                        0x71A350

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                              0x4FB720
#define __MemChecker1                                              0x665190
#define __MemChecker2                                              0x52FE80
#define __MemChecker3                                              0x52FDD0
#define __MemChecker4                                              0x6297F0
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
#define __GetGaugeValueFromEQ                                      0x5FAF90
#define __GetLabelFromEQ                                           0x5FB7A0
#define __NewUIINI                                                 0x5FAB80
#define __ProcessGameEvents                                        0x4E6A30
#define CrashDetected                                              0x52EB50
#define DrawNetStatus                                              0x4FE520
#define Util__FastTime                                             0x6658E0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x473610
#define AltAdvManager__IsAbilityReady                              0x473650
#define AltAdvManager__GetAltAbility                               0x473830

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x545F30

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x54F350

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x691340

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5642C0
#define CChatManager__InitContextMenu                              0x564A50

// CChatService
#define CChatService__GetNumberOfFriends                           0x655BC0
#define CChatService__GetFriendName                                0x655BD0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x568BC0
#define CChatWindow__WndNotification                               0x5695B0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x677670
#define CComboWnd__Draw                                            0x677820
#define CComboWnd__GetCurChoice                                    0x677610
#define CComboWnd__GetListRect                                     0x677AE0
#define CComboWnd__GetTextRect                                     0x6776A0
#define CComboWnd__InsertChoice                                    0x677B50
#define CComboWnd__SetColors                                       0x6775A0
#define CComboWnd__SetChoice                                       0x6775D0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x56FEB0
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
#define CEditBaseWnd__SetMaxChars                                  0x5400B0
#define CEditBaseWnd__SetSel                                       0x69C2D0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x685590
#define CEditWnd__GetCharIndexPt                                   0x6863F0
#define CEditWnd__GetDisplayString                                 0x685730
#define CEditWnd__GetHorzOffset                                    0x6859C0
#define CEditWnd__GetLineForPrintableChar                          0x685EA0
#define CEditWnd__GetSelStartPt                                    0x686630
#define CEditWnd__GetSTMLSafeText                                  0x685B60
#define CEditWnd__PointFromPrintableChar                           0x685FB0
#define CEditWnd__SelectableCharFromPoint                          0x686130
#define CEditWnd__SetEditable                                      0x685B30

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
#define CGaugeWnd__CalcFillRect                                    0x57C280
#define CGaugeWnd__CalcLinesFillRect                               0x57C2F0
#define CGaugeWnd__Draw                                            0x57C670

// CGuild
#define CGuild__FindMemberByName                                   0x417B70

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x592B50

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x59BF80
#define CInvSlotMgr__MoveItem                                      0x59C120

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x59A960
#define CInvSlot__SliderComplete                                   0x59AE70

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5AB050
#define CItemDisplayWnd__SetSpell                                  0x5F8EB0

// CLabel 
#define CLabel__Draw                                               0x5B08A0

// CListWnd 
#define CListWnd__AddColumn                                        0x6773B0
#define CListWnd__AddColumn1                                       0x676EA0
#define CListWnd__AddLine                                          0x676A80
#define CListWnd__AddString                                        0x676C50
#define CListWnd__CalculateFirstVisibleLine                        0x673E40
#define CListWnd__CalculateVSBRange                                0x675A50
#define CListWnd__ClearAllSel                                      0x673590
#define CListWnd__CloseAndUpdateEditWindow                         0x674440
#define CListWnd__Compare                                          0x6747D0
#define CListWnd__Draw                                             0x675750
#define CListWnd__DrawColumnSeparators                             0x6755C0
#define CListWnd__DrawHeader                                       0x673760
#define CListWnd__DrawItem                                         0x674ED0
#define CListWnd__DrawLine                                         0x675270
#define CListWnd__DrawSeparator                                    0x675660
#define CListWnd__EnsureVisible                                    0x673E90
#define CListWnd__ExtendSel                                        0x674E00
#define CListWnd__GetColumnMinWidth                                0x673330
#define CListWnd__GetColumnWidth                                   0x673270
#define CListWnd__GetCurSel                                        0x672D40
#define CListWnd__GetHeaderRect                                    0x672E40
#define CListWnd__GetItemAtPoint                                   0x674160
#define CListWnd__GetItemAtPoint1                                  0x6741D0
#define CListWnd__GetItemData                                      0x673020
#define CListWnd__GetItemHeight                                    0x673BD0
#define CListWnd__GetItemIcon                                      0x6731B0
#define CListWnd__GetItemRect                                      0x673F50
#define CListWnd__GetItemText                                      0x673060
#define CListWnd__GetSelList                                       0x676D80
#define CListWnd__GetSeparatorRect                                 0x674710
#define CListWnd__RemoveLine                                       0x677360
#define CListWnd__SetColors                                        0x672DA0
#define CListWnd__SetColumnJustification                           0x673390
#define CListWnd__SetColumnWidth                                   0x6732F0
#define CListWnd__SetCurSel                                        0x672D80
#define CListWnd__SetItemColor                                     0x676650
#define CListWnd__SetItemData                                      0x673630
#define CListWnd__SetItemText                                      0x6765D0
#define CListWnd__ShiftColumnSeparator                             0x674D70
#define CListWnd__Sort                                             0x6773E0
#define CListWnd__ToggleSel                                        0x673500

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5C55D0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5C70B0
#define CMerchantWnd__RequestBuyItem                               0x5C83E0
#define CMerchantWnd__RequestSellItem                              0x5C7300
#define CMerchantWnd__SelectBuySellSlot                            0x5C8110

// CObfuscator
#define CObfuscator__doit                                          0x63CBF0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x68D000
#define CSidlManager__CreateLabel                                  0x5F24C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x67D330
#define CSidlScreenWnd__CalculateVSBRange                          0x67D280
#define CSidlScreenWnd__ConvertToRes                               0x69C1B0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x67EC50
#define CSidlScreenWnd__CSidlScreenWnd1                            0x67FA90
#define CSidlScreenWnd__CSidlScreenWnd2                            0x67FB40
#define CSidlScreenWnd__dCSidlScreenWnd                            0x67F4E0
#define CSidlScreenWnd__DrawSidlPiece                              0x67E930
#define CSidlScreenWnd__EnableIniStorage                           0x67E440
#define CSidlScreenWnd__GetSidlPiece                               0x67EB30
#define CSidlScreenWnd__Init1                                      0x67F900
#define CSidlScreenWnd__LoadIniInfo                                0x67ED00
#define CSidlScreenWnd__LoadIniListWnd                             0x67E590
#define CSidlScreenWnd__LoadSidlScreen                             0x67E750
#define CSidlScreenWnd__StoreIniInfo                               0x67E050
#define CSidlScreenWnd__WndNotification                            0x67E890

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x51F8A0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x69CEC0
#define CSliderWnd__SetValue                                       0x69CFC0
#define CSliderWnd__SetNumTicks                                    0x69D530

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5F7B50

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x69A490
#define CStmlWnd__CalculateVSBRange                                0x675A50
#define CStmlWnd__CanBreakAtCharacter                              0x6929A0
#define CStmlWnd__FastForwardToEndOfTag                            0x6934A0
#define CStmlWnd__ForceParseNow                                    0x69A8E0
#define CStmlWnd__GetNextTagPiece                                  0x6933C0
#define CStmlWnd__GetSTMLText                                      0x568B60
#define CStmlWnd__GetThisChar                                      0x6BA8A0
#define CStmlWnd__GetVisiableText                                  0x6946C0
#define CStmlWnd__InitializeWindowVariables                        0x696800
#define CStmlWnd__MakeStmlColorTag                                 0x691F40
#define CStmlWnd__MakeWndNotificationTag                           0x691FE0
#define CStmlWnd__SetSTMLText                                      0x696910
#define CStmlWnd__StripFirstSTMLLines                              0x69A220
#define CStmlWnd__UpdateHistoryString                              0x694F20

// CTabWnd 
#define CTabWnd__Draw                                              0x69E330
#define CTabWnd__DrawCurrentPage                                   0x69DCD0
#define CTabWnd__DrawTab                                           0x69DAB0
#define CTabWnd__GetCurrentPage                                    0x69DFD0
#define CTabWnd__GetPageClientRect                                 0x69D780
#define CTabWnd__GetPageFromTabIndex                               0x69D9E0
#define CTabWnd__GetPageInnerRect                                  0x69D7E0
#define CTabWnd__GetTabInnerRect                                   0x69D960
#define CTabWnd__GetTabRect                                        0x69D870
#define CTabWnd__IndexInBounds                                     0x69DA7D
#define CTabWnd__InsertPage                                        0x69E550
#define CTabWnd__SetPage                                           0x69E010
#define CTabWnd__SetPageRect                                       0x69E260
#define CTabWnd__UpdatePage                                        0x69E4D0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x414060

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x67FEA0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6A3A40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x672AB0

// CXRect 
#define CXRect__CenterPoint                                        0x545690

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4123F0
#define CXStr__CXStr1                                              0x66C1D0
#define CXStr__CXStr3                                              0x667030
#define CXStr__dCXStr                                              0x5EEA30
#define CXStr__operator_equal1                                     0x6671F0
#define CXStr__operator_plus_equal1                                0x6680F0

// CXWnd 
#define CXWnd__BringToTop                                          0x6783D0
#define CXWnd__Center                                              0x67C060
#define CXWnd__ClrFocus                                            0x6780C0
#define CXWnd__DoAllDrawing                                        0x67CB50
#define CXWnd__DrawChildren                                        0x67CC80
#define CXWnd__DrawColoredRect                                     0x678650
#define CXWnd__DrawTooltip                                         0x67CA70
#define CXWnd__DrawTooltipAtPoint                                  0x67BE30
#define CXWnd__GetBorderFrame                                      0x678B10
#define CXWnd__GetChildWndAt                                       0x67B8D0
#define CXWnd__GetClientClipRect                                   0x678A40
#define CXWnd__GetFirstChildWnd                                    0x678470
#define CXWnd__GetNextChildWnd                                     0x67B890
#define CXWnd__GetNextSib                                          0x678490
#define CXWnd__GetScreenClipRect                                   0x67C280
#define CXWnd__GetScreenRect                                       0x678CD0
#define CXWnd__GetTooltipRect                                      0x678870
#define CXWnd__GetWindowTextA                                      0x5391A0
#define CXWnd__IsActive                                            0x680FA0
#define CXWnd__IsDescendantOf                                      0x678AC0
#define CXWnd__IsReallyVisible                                     0x67B870
#define CXWnd__IsType                                              0x69F440
#define CXWnd__Move                                                0x67B320
#define CXWnd__Move1                                               0x67B3C0
#define CXWnd__ProcessTransition                                   0x678390
#define CXWnd__Refade                                              0x678170
#define CXWnd__Resize                                              0x678DA0
#define CXWnd__Right                                               0x67C1C0
#define CXWnd__SetFirstChildPointer                                0x678F60
#define CXWnd__SetFocus                                            0x67A390
#define CXWnd__SetKeyTooltip                                       0x678FD0
#define CXWnd__SetMouseOver                                        0x678FA0
#define CXWnd__SetNextSibPointer                                   0x678F80
#define CXWnd__StartFade                                           0x6783F0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6824C0
#define CXWndManager__DrawWindows                                  0x682100
#define CXWndManager__GetFirstChildWnd                             0x6819F0
#define CXWndManager__GetKeyboardFlags                             0x680C60
#define CXWndManager__HandleKeyboardMsg                            0x681240
#define CXWndManager__RemoveWnd                                    0x681160

// CDBStr
#define CDBStr__GetString                                          0x45C0F0

// EQ_Character 
#define EQ_Character__CastRay                                      0x6C67F0
#define EQ_Character__CastSpell                                    0x425040
#define EQ_Character__Cur_HP                                       0x4317A0
#define EQ_Character__GetAACastingTimeModifier                     0x41FA20
#define EQ_Character__GetCharInfo2                                 0x648020
#define EQ_Character__GetFocusCastingTimeModifier                  0x41B6C0
#define EQ_Character__GetFocusRangeModifier                        0x41B7F0
#define EQ_Character__Max_Endurance                                0x42CDA0
#define EQ_Character__Max_HP                                       0x42CC20
#define EQ_Character__Max_Mana                                     0x504650
#define EQ_Character__doCombatAbility                              0x503310
#define EQ_Character__UseSkill                                     0x437890
#define EQ_Character__GetConLevel                                  0x4FF9E0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F34C0
#define EQ_Item__GetItemLinkHash                                   0x63C2A0
#define EQ_Item__IsStackable                                       0x633170

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x4746F0
#define EQ_LoadingS__Array                                         0x76E7D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x507690
#define EQ_PC__GetAltAbilityIndex                                  0x640D40
#define EQ_PC__GetCombatAbility                                    0x640DD0
#define EQ_PC__GetCombatAbilityTimer                               0x640E80
#define EQ_PC__GetItemTimerValue                                   0x502240
#define EQ_PC__HasLoreItem                                         0x505AF0

// EQItemList 
#define EQItemList__dEQItemList                                    0x49D860
#define EQItemList__EQItemList                                     0x49D7B0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45B970

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x50BE40
#define EQPlayer__dEQPlayer                                        0x5106D0
#define EQPlayer__DoAttack                                         0x51C340
#define EQPlayer__EQPlayer                                         0x513360
#define EQPlayer__SetNameSpriteState                               0x50E5E0
#define EQPlayer__SetNameSpriteTint                                0x50BEB0
#define EQPlayer__IsBodyType_j                                     0x6C61C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x514390

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F50D0
#define KeypressHandler__AttachKeyToEqCommand                      0x4F5110
#define KeypressHandler__ClearCommandStateArray                    0x4F4EE0
#define KeypressHandler__HandleKeyDown                             0x4F3AC0
#define KeypressHandler__HandleKeyUp                               0x4F3DC0
#define KeypressHandler__SaveKeymapping                            0x4F4FB0

// MapViewMap 
#define MapViewMap__Clear                                          0x5C0CC0
#define MapViewMap__SaveEx                                         0x5C1690

#define OtherCharData__GetAltCurrency                              0x65E1A0

// StringTable 
#define StringTable__getString                                     0x632B40
