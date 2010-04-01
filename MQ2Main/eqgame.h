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
#define __ExpectedVersionDate                                     "Mar 13 2006"
#define __ExpectedVersionTime                                     "17:31:55"
#define __ActualVersionDate                                        0x6B0AE4
#define __ActualVersionTime                                        0x6B0AF0

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x4D56B0
#define __MemChecker2                                              0x5005D0
#define __MemChecker3                                              0x500680
#define __MemChecker4                                              0x5E3470
#define __EncryptPad0                                              0x7F3598
#define __EncryptPad2                                              0x7F56D8
#define __EncryptPad3                                              0x7F5AD8
#define __EncryptPad4                                              0x7FE090

// Direct Input
#define DI8__Main                                                  0x9E9434
#define DI8__Keyboard                                              0x9E9438
#define DI8__Mouse                                                 0x9E943C

#define __AltTimerReady                                            0x984DDE
#define __Attack                                                   0x9E6037
#define __BindList                                                 0x7EE9C8
#define __Clicks                                                   0x983F7C
#define __CommandList                                              0x7EF1A8
#define __CurrentMapLabel                                          0x9F24E4
#define __CurrentSocial                                            0x6FADB8
#define __DoAbilityAvailable                                       0x984D78
#define __DoAbilityList                                            0x9BDB84
#define __DrawHandler                                              0x9FE854
#define __FriendsList                                              0x987020
#define __GroupCount                                               0x9646D8
#define __GroupLeader                                              0x964834
#define __Guilds                                                   0x9661C0
#define __gWorld                                                   0x966130
#define __HotkeyPage                                               0x9E4F70
#define __HWnd                                                     0x9E93DC
#define __IgnoreList                                               0x9BC224
#define __InChatMode                                               0x983EB8
#define __LastTell                                                 0x986090
#define __Mouse                                                    0x9E9440
#define __MouseLook                                                0x983F4A
#define __NetStatusToggle                                          0x983F4C
#define __PCNames                                                  0x9850E8
#define __RangeAttackReady                                         0x984DDC
#define __RunWalkState                                             0x983EBC
#define __ScreenMode                                               0x8B4088
#define __ScreenX                                                  0x983E80
#define __ScreenY                                                  0x983E84
#define __ServerHost                                               0x96462C
#define __ServerName                                               0x9BDB44
#define __ShowNames                                                0x984FCC
#define __SkillDict                                                0x8B4D88
#define __Socials                                                  0x9BDC44

////
//Section 1: Vital Offsets
////
#define instCRaid                                                  0x97DE10
#define instEQZoneInfo                                             0x9840E8
#define instKeypressHandler                                        0x9E610C
#define pinstActiveBanker                                          0x9661A0
#define pinstActiveCorpse                                          0x9661A4
#define pinstActiveGMaster                                         0x9661A8
#define pinstActiveMerchant                                        0x96619C
#define pinstAltAdvManager                                         0x8B4D60
#define pinstBandageTarget                                         0x966188
#define pinstCamActor                                              0x8B4854
#define pinstCDBStr                                                0x8B3F18
#define pinstCDisplay                                              0x9661B0
#define pinstCEverQuest                                            0x9E95A8
#define pinstCharData                                              0x966170
#define pinstCharSpawn                                             0x966194
#define pinstControlledMissile                                     0x96616C
#define pinstControlledPlayer                                      0x0
#define pinstCSidlManager                                          0x9FE108
#define pinstCXWndManager                                          0x9FE100
#define pinstEQItemList                                            0x966154
#define pinstEQSoundManager                                        0x8B4F18
#define instGroup                                                  0x9646D8
#define pinstGroup                                                 0x9646D4
#define pinstImeManager                                            0x9FE10C
#define pinstLocalPlayer                                           0x966180
#define pinstModelPlayer                                           0x9661AC
#define pinstPCData                                                0x966170
#define pinstSelectedItem                                          0x9F233C
#define pinstSpawnManager                                          0x9E641C
#define pinstSpellManager                                          0x9E6484
#define pinstSpellSets                                             0x9E4F74
#define pinstStringTable                                           0x966140
#define pinstSwitchManager                                         0x964328
#define pinstTarget                                                0x966198
#define pinstTargetObject                                          0x966174
#define pinstTargetSwitch                                          0x966178
#define pinstTrackTarget                                           0x96618C
#define pinstTradeTarget                                           0x96617C
#define instTributeActive                                          0x8B3EF5
#define pinstViewActor                                             0x8B4850
#define pinstWorldData                                             0x966150


////
//Section 2:  UI Related Offsets
////
//#define pinstCAdventureMerchantWnd                                 0x801ED0
#define pinstCTextOverlay                                          0x801F48
#define pinstCAudioTriggersWindow                                  0x801F14
//                                                                   0x803988
#define pinstCCharacterSelect                                      0x8B471C
#define pinstCFacePick                                             0x8B4720
#define pinstCNoteWnd                                              0x8B4724
#define pinstCBookWnd                                              0x8B4728
#define pinstCPetInfoWnd                                           0x8B472C
#define pinstCTrainWnd                                             0x8B4730
#define pinstCSkillsWnd                                            0x8B4734
#define pinstCSkillsSelectWnd                                      0x8B4738
#define pinstCCombatSkillSelectWnd                                 0x8B473C
#define pinstCFriendsWnd                                           0x8B4740
#define pinstCAuraWnd                                              0x8B4744
#define pinstCRespawnWnd                                           0x8B4748
#define pinstCBandolierWnd                                         0x8B474C
#define pinstCPotionBeltWnd                                        0x8B4750
#define pinstCAAWnd                                                0x8B4754
#define pinstCGroupSearchFiltersWnd                                0x8B4758
#define pinstCLoadskinWnd                                          0x8B475C
#define pinstCAlarmWnd                                             0x8B4760
#define pinstCMusicPlayerWnd                                       0x8B4764
#define pinstCMailWnd                                              0x8B4768
#define pinstCMailCompositionWnd                                   0x8B476C
#define pinstCMailAddressBookWnd                                   0x8B4770
#define pinstCRaidWnd                                              0x8B4774
#define pinstCRaidOptionsWnd                                       0x8B4778
#define pinstCBreathWnd                                            0x8B477C
#define pinstCMapViewWnd                                           0x8B4780
#define pinstCMapToolbarWnd                                        0x8B4784
#define pinstCEditLabelWnd                                         0x8B4788
#define pinstCTargetWnd                                            0x8B478C
#define pinstCColorPickerWnd                                       0x8B4790
#define pinstCPlayerWnd                                            0x8B4794
#define pinstCOptionsWnd                                           0x8B4798
#define pinstCBuffWindowNORMAL                                     0x8B479C
#define pinstCBuffWindowSHORT                                      0x8B47A0
#define pinstCharacterCreation                                     0x8B47A4
#define pinstCCursorAttachment                                     0x8B47A8
#define pinstCCastingWnd                                           0x8B47AC
#define pinstCCastSpellWnd                                         0x8B47B0
#define pinstCSpellBookWnd                                         0x8B47B4
#define pinstCInventoryWnd                                         0x8B47B8
#define pinstCBankWnd                                              0x8B47BC
#define pinstCQuantityWnd                                          0x8B47C0
#define pinstCLootWnd                                              0x8B47C4
#define pinstCActionsWnd                                           0x8B47C8
#define pinstCCombatAbilityWnd                                     0x8B47CC
#define pinstCMerchantWnd                                          0x8B47D0
#define pinstCTradeWnd                                             0x8B47D4
#define pinstCSelectorWnd                                          0x8B47D8
#define pinstCBazaarWnd                                            0x8B47DC
#define pinstCBazaarSearchWnd                                      0x8B47E0
#define pinstCGiveWnd                                              0x8B47E4
#define pinstCTrackingWnd                                          0x8B47E8
#define pinstCInspectWnd                                           0x8B47EC
#define pinstCSocialEditWnd                                        0x8B47F0
#define pinstCFeedbackWnd                                          0x8B47F4
#define pinstCBugReportWnd                                         0x8B47F8
#define pinstCVideoModesWnd                                        0x8B47FC
#define pinstCTextEntryWnd                                         0x8B4804
#define pinstCFileSelectionWnd                                     0x8B4808
#define pinstCCompassWnd                                           0x8B480C
#define pinstCPlayerNotesWnd                                       0x8B4810
#define pinstCGemsGameWnd                                          0x8B4814
#define pinstCTimeLeftWnd                                          0x8B4818
#define pinstCPetitionQWnd                                         0x8B481C
#define pinstCSoulmarkWnd                                          0x8B4820
#define pinstCStoryWnd                                             0x8B4824
#define pinstCJournalTextWnd                                       0x8B4828
#define pinstCJournalCatWnd                                        0x8B482C
#define pinstCBodyTintWnd                                          0x8B4830
#define pinstCServerListWnd                                        0x8B4834
#define pinstCAvaZoneWnd                                           0x8B4838
#define pinstCBlockedBuffWnd                                       0x8B483C
#define pinstCBlockedPetBuffWnd                                    0x8B4840
#define pinstCInvSlotMgr                                           0x8B4844
#define pinstCContainerMgr                                         0x8B4848
//                                                                   0x9E6074
//                                                                   0x9E60AC
//                                                                   0x9E6450
#define pinstCAdventureLeaderboardWnd                              0x9F1B74
#define pinstCAdventureRequestWnd                                  0x9F1B90
#define pinstCAltStorageWnd                                        0x9F1BF0
#define pinstCAdventureStatsWnd                                    0x9F1BAC
#define pinstCBarterMerchantWnd                                    0x9F1DA4
#define pinstCBarterSearchWnd                                      0x9F1DC0
#define pinstCBarterWnd                                            0x9F1DDC
//                                                                   0x9F1F40
#define pinstCChatManager                                          0x9F1FCC
#define pinstCDynamicZoneWnd                                       0x9F20A8
#define pinstCEQMainWnd                                            0x9F2118
#define pinstCFindLocationWnd                                      0x9F21AC
#define pinstCGroupSearchWnd                                       0x9F2264
#define pinstCGroupWnd                                             0x9F225C
#define pinstCGuildBankWnd                                         0x9F2278
#define pinstCGuildMgmtWnd                                         0x9F2294
#define pinstCGuildTributeMasterWnd                                0x9F22B0
#define pinstCHotButtonWnd                                         0x9F22CC
#define pinstCHotButtonWnd1                                        0x9F22CC
#define pinstCHotButtonWnd2                                        0x9F22D0
#define pinstCHotButtonWnd3                                        0x9F22D4
#define pinstCHotButtonWnd4                                        0x9F22D8
#define pinstCItemDisplayManager                                   0x9F2370
#define pinstCItemExpTransferWnd                                   0x9F2390
#define pinstCLeadershipWnd                                        0x9F240C
#define pinstCLFGuildWnd                                           0x9F2428
#define pinstCMIZoneSelectWnd                                      0x9F254C
#define pinstCAdventureMerchantWnd                                 0x9F2610
#define pinstCConfirmationDialog                                   0x9F262C
#define pinstCPopupWndManager                                      0x9F262C
#define pinstCProgressionSelectionWnd                              0x9F2660
#define pinstCPvPLeaderboardWnd                                    0x9F267C
#define pinstCPvPStatsWnd                                          0x9F2698
//                                                                   0x9F2744
#define pinstCSystemInfoDialogBox                                  0x9F2FF8
#define pinstCTargetOfTargetWnd                                    0x9F3014
#define pinstCTaskSelectWnd                                        0x9F3048
#define pinstCTaskTemplateSelectWnd                                0x9F3064
#define pinstCTaskWnd                                              0x9F3080
#define pinstCTicketCommentWnd                                     0x9F30B4
#define pinstCHelpWnd                                              0x9F30D0
#define pinstCTipWndOFDAY                                          0x9F3104
#define pinstCTipWndCONTEXT                                        0x9F3108
#define pinstCTitleWnd                                             0x9F3124
#define pinstCTradeskillWnd                                        0x9F3168
#define pinstCTributeBenefitWnd                                    0x9F31B4
#define pinstCTributeMasterWnd                                     0x9F31D0
#define pinstCContextMenuManager                                   0x9FE148
#define pinstCVoiceMacroWnd                                        0x9E654C


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                                  0x49B640
#define __ConvertItemTags                                          0x490850
#define __ExecuteCmd                                               0x482100
#define __get_melee_range                                          0x487130
#define __GetGaugeValueFromEQ                                      0x5A9D00
#define __GetLabelFromEQ                                           0x5AA3B0
#define __NewUIINI                                                 0x5A98E0
#define __ProcessGameEvents                                        0x4C4CB0
#define __SendMessage                                              0x4A7390
#define CrashDetected                                              0x5002A0
#define DrawNetStatus                                              0x4D8340
#define Util__FastTime                                             0x5E8900


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                          0x464A70
#define AltAdvManager__IsAbilityReady                              0x464AB0
#define AltAdvManager__GetAltAbility                               0x464CD0

// CBankWnd
#define CBankWnd__GetNumBankSlots                                  0x4F6C30

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                          0x51D1E0

// CButtonWnd
#define CButtonWnd__SetCheck                                       0x63CB90

// CChatManager
#define CChatManager__GetRGBAFromIndex                             0x52FE50
#define CChatManager__InitContextMenu                              0x530590

// CChatWindow
#define CChatWindow__CChatWindow                                   0x5346C0

// CComboWnd
#define CComboWnd__DeleteAll                                       0x61BAD0
#define CComboWnd__Draw                                            0x61BC80
//#define CComboWnd__GetButtonRect                                   0x0
#define CComboWnd__GetCurChoice                                    0x61BA80
#define CComboWnd__GetListRect                                     0x61BF70
#define CComboWnd__GetTextRect                                     0x61BB00
#define CComboWnd__InsertChoice                                    0x61BFE0
#define CComboWnd__SetColors                                       0x61BA10
#define CComboWnd__SetChoice                                       0x61BA40

// CContainerWnd
#define CContainerWnd__HandleCombine                               0x53AD70
#define CContainerWnd__vftable                                     0x6B6C88

// CDisplay
#define CDisplay__CleanGameUI                                      0x454E70
#define CDisplay__GetClickedActor                                  0x452740
#define CDisplay__GetUserDefinedColor                              0x451BB0
#define CDisplay__GetWorldFilePath                                 0x451200
#define CDisplay__ReloadUI                                         0x4602B0
#define CDisplay__WriteTextHD2                                     0x4565D0

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                                  0x50E410
#define CEditBaseWnd__SetSel                                       0x63BC10

// CEditWnd
#define CEditWnd__DrawCaret                                        0x639370
#define CEditWnd__GetCharIndexPt                                   0x63A190
#define CEditWnd__GetDisplayString                                 0x639500
#define CEditWnd__GetHorzOffset                                    0x639770
#define CEditWnd__GetLineForPrintableChar                          0x639C50
#define CEditWnd__GetSelStartPt                                    0x63A3D0
#define CEditWnd__GetSTMLSafeText                                  0x639910
#define CEditWnd__PointFromPrintableChar                           0x639D60
#define CEditWnd__SelectableCharFromPoint                          0x639EE0
#define CEditWnd__SetEditable                                      0x6398E0

// CEverQuest
#define CEverQuest__ClickedPlayer                                  0x4AB8A0
#define CEverQuest__DropHeldItemOnGround                           0x4AF680
#define CEverQuest__dsp_chat                                       0x4B0240
#define CEverQuest__EnterZone                                      0x4C3910
#define CEverQuest__GetBodyTypeDesc                                0x4A8CD0
#define CEverQuest__GetClassDesc                                   0x4A8430
#define CEverQuest__GetClassThreeLetterCode                        0x4A8A30
#define CEverQuest__GetDeityDesc                                   0x4A9220
#define CEverQuest__GetRaceDesc                                    0x4A91F0
#define CEverQuest__InterpretCmd                                   0x4B0B60
#define CEverQuest__LeftClickedOnPlayer                            0x4C1FB0
#define CEverQuest__RightClickedOnPlayer                           0x4C23C0
#define CEverQuest__SetGameState                                   0x4AB8E0

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                                    0x5450C0
#define CGaugeWnd__CalcLinesFillRect                               0x545130
#define CGaugeWnd__Draw                                            0x5454C0

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                                 0x5589D0

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                                   0x55FF20
#define CInvSlotMgr__MoveItem                                      0x5600C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x560FD0

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                                   0x567CA0
#define CItemDisplayWnd__SetSpell                                  0x5638F0

// CLabel
#define CLabel__Draw                                               0x56D0D0

// CListWnd
#define CListWnd__AddColumn                                        0x61B820
#define CListWnd__AddColumn1                                       0x61B360
#define CListWnd__AddLine                                          0x61AEF0
#define CListWnd__AddString                                        0x61B0C0
#define CListWnd__CalculateFirstVisibleLine                        0x618220
#define CListWnd__CalculateVSBRange                                0x619EA0
#define CListWnd__ClearAllSel                                      0x6179B0
#define CListWnd__CloseAndUpdateEditWindow                         0x618850
#define CListWnd__Compare                                          0x618C00
#define CListWnd__Draw                                             0x6197A0
#define CListWnd__DrawColumnSeparators                             0x619A10
#define CListWnd__DrawHeader                                       0x617B40
#define CListWnd__DrawItem                                         0x619310
#define CListWnd__DrawLine                                         0x6196C0
#define CListWnd__DrawSeparator                                    0x6196C0
#define CListWnd__EnsureVisible                                    0x618270
#define CListWnd__ExtendSel                                        0x619240
//#define CListWnd__GetColumnFlags                                   0x0
//#define CListWnd__GetColumnJustification                           0x0
#define CListWnd__GetColumnMinWidth                                0x617750
#define CListWnd__GetColumnWidth                                   0x617690
#define CListWnd__GetCurSel                                        0x617150
#define CListWnd__GetHeaderRect                                    0x617260
#define CListWnd__GetItemAtPoint                                   0x618560
#define CListWnd__GetItemAtPoint1                                  0x6185D0
#define CListWnd__GetItemData                                      0x617440
#define CListWnd__GetItemHeight                                    0x617FB0
#define CListWnd__GetItemIcon                                      0x6175D0
#define CListWnd__GetItemRect                                      0x618350
#define CListWnd__GetItemText                                      0x617480
#define CListWnd__GetSelList                                       0x61B240
#define CListWnd__GetSeparatorRect                                 0x618B40
//#define CListWnd__IsLineEnabled                                    0x0
#define CListWnd__RemoveLine                                       0x61B1F0
#define CListWnd__SetColors                                        0x6171D0
#define CListWnd__SetColumnJustification                           0x6177B0
#define CListWnd__SetColumnWidth                                   0x617710
#define CListWnd__SetCurSel                                        0x617190
#define CListWnd__SetItemColor                                     0x61AAC0
#define CListWnd__SetItemData                                      0x617A50
#define CListWnd__SetItemText                                      0x61AA40
#define CListWnd__ShiftColumnSeparator                             0x6191B0
#define CListWnd__Sort                                             0x61B850
#define CListWnd__ToggleSel                                        0x617920

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                                   0x57EEC0

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x580350 // or 0x580A80
#define CMerchantWnd__RequestBuyItem                               0x581990
#define CMerchantWnd__RequestSellItem                              0x5805B0 // or 0x580820
#define CMerchantWnd__SelectBuySellSlot                            0x581690

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1                     0x62DBA0

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                          0x621140
#define CSidlScreenWnd__CalculateVSBRange                          0x50FD60
#define CSidlScreenWnd__ConvertToRes                               0x621890
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6220F0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6233B0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x623460
#define CSidlScreenWnd__dCSidlScreenWnd                            0x622C70
#define CSidlScreenWnd__DrawSidlPiece                              0x621E10
#define CSidlScreenWnd__EnableIniStorage                           0x621840
#define CSidlScreenWnd__GetSidlPiece                               0x621FD0
#define CSidlScreenWnd__Init1                                      0x6231D0
#define CSidlScreenWnd__LoadIniInfo                                0x6221A0
#define CSidlScreenWnd__LoadIniListWnd                             0x621A00
#define CSidlScreenWnd__LoadSidlScreen                             0x621C40
//#define CSidlScreenWnd__SetScreen                                  0x0
#define CSidlScreenWnd__StoreIniInfo                               0x621370
#define CSidlScreenWnd__WndNotification                            0x621D70

// CSliderWnd
#define CSliderWnd__GetValue                                       0x63E820
#define CSliderWnd__SetValue                                       0x63E920
//#define CSliderWnd__UpdateThumb                                    0x0

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                                 0x5A7A00

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x637FB0
#define CStmlWnd__CalculateHSBRange                                0x630330
#define CStmlWnd__CalculateVSBRange                                0x6302D0
#define CStmlWnd__CanBreakAtCharacter                              0x630470
#define CStmlWnd__CanGoBackward                                    0x630530
#define CStmlWnd__FastForwardToEndOfTag                            0x630F80
#define CStmlWnd__GetNextChar                                      0x0
#define CStmlWnd__GetNextTagPiece                                  0x630EA0
#define CStmlWnd__GetSTMLText                                      0x534660
#define CStmlWnd__GetThisChar                                      0x659720
#define CStmlWnd__GetVisiableText                                  0x6321C0
#define CStmlWnd__InitializeWindowVariables                        0x634320
#define CStmlWnd__MakeStmlColorTag                                 0x62F9D0
#define CStmlWnd__MakeWndNotificationTag                           0x62FA70
#define CStmlWnd__StripFirstSTMLLines                              0x637D40
#define CStmlWnd__UpdateHistoryString                              0x632A20

// CTabWnd
#define CTabWnd__Draw                                              0x63E250
#define CTabWnd__DrawCurrentPage                                   0x63DBD0
#define CTabWnd__DrawTab                                           0x63D9B0
#define CTabWnd__GetCurrentPage                                    0x63DED0
//#define CTabWnd__GetCurrentTabIndex                                0x0
//#define CTabWnd__GetNumTabs                                        0x0
#define CTabWnd__GetPageClientRect                                 0x63D680
#define CTabWnd__GetPageFromTabIndex                               0x63D8E0
#define CTabWnd__GetPageInnerRect                                  0x63D6E0
#define CTabWnd__GetTabInnerRect                                   0x63D860
#define CTabWnd__GetTabRect                                        0x63D770
#define CTabWnd__IndexInBounds                                     0x63D97D
#define CTabWnd__InsertPage                                        0x63E470
#define CTabWnd__SetPage                                           0x63DF10
#define CTabWnd__SetPageRect                                       0x63E180
#define CTabWnd__UpdatePage                                        0x63E3F0

// CTextOverlay
#define CTextOverlay__DisplayText                                  0x411CF0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6237C0

// CXMLDataManager
#define CXMLDataManager__GetXMLData                                0x643C40

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                               0x616EE0

// CXRect
#define CXRect__CenterPoint                                        0x5138D0

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                               0x410720
#define CXStr__CXStr1                                              0x611EC0
#define CXStr__CXStr3                                              0x5E9EE0
#define CXStr__dCXStr                                              0x44E7F0
#define CXStr__operator_equal1                                     0x5EA0A0
#define CXStr__operator_plus_equal1                                0x5EAEE0

// CXWnd
#define CXWnd__BringToTop                                          0x61C800
#define CXWnd__Center                                              0x61FEA0
#define CXWnd__ClrFocus                                            0x61C4F0
#define CXWnd__DoAllDrawing                                        0x620BB0
#define CXWnd__DrawChildren                                        0x620CE0
#define CXWnd__DrawColoredRect                                     0x61CA60
#define CXWnd__DrawTooltip                                         0x620AE0
#define CXWnd__DrawTooltipAtPoint                                  0x61FD00
//#define CXWnd__GetBorderFrame                                      0x0
#define CXWnd__GetChildWndAt                                       0x61F800
#define CXWnd__GetClientClipRect                                   0x61CE30
#define CXWnd__GetFirstChildWnd                                    0x61C8A0
#define CXWnd__GetNextChildWnd                                     0x61F7C0
#define CXWnd__GetNextSib                                          0x61C8C0
#define CXWnd__GetScreenClipRect                                   0x620130
#define CXWnd__GetScreenRect                                       0x61D0A0
#define CXWnd__GetTooltipRect                                      0x61CCA0
#define CXWnd__GetWindowTextA                                      0x507810
#define CXWnd__IsActive                                            0x624870
#define CXWnd__IsDescendantOf                                      0x61CEB0
#define CXWnd__IsReallyVisible                                     0x61F7A0
#define CXWnd__IsType                                              0x620B60
#define CXWnd__Move                                                0x61F2B0
#define CXWnd__Move1                                               0x61F350
#define CXWnd__ProcessTransition                                   0x61C7D0
#define CXWnd__Refade                                              0x61C5A0
#define CXWnd__Resize                                              0x620270
#define CXWnd__Right                                               0x620010
#define CXWnd__SetFirstChildPointer                                0x61D310
#define CXWnd__SetFocus                                            0x61E600
#define CXWnd__SetKeyTooltip                                       0x61D370
#define CXWnd__SetMouseOver                                        0x61D340
#define CXWnd__SetNextSibPointer                                   0x61D320
#define CXWnd__StartFade                                           0x61C820

// CXWndManager
#define CXWndManager__DrawCursor                                   0x625C30
#define CXWndManager__DrawWindows                                  0x6258F0
#define CXWndManager__GetFirstChildWnd                             0x625210
#define CXWndManager__GetKeyboardFlags                             0x624580
#define CXWndManager__HandleKeyboardMsg                            0x624A60
#define CXWndManager__RemoveWnd                                    0x624980

// CDBStr
#define CDBStr__GetString                                          0x44E810

// EQ_Character
#define EQ_Character__CastRay                                      0x665F70
#define EQ_Character__CastSpell                                    0x41E770
#define EQ_Character__Cur_HP                                       0x4259B0
#define EQ_Character__GetAACastingTimeModifier                     0x419820
#define EQ_Character__GetCharInfo2                                 0x5FD430
#define EQ_Character__GetFocusCastingTimeModifier                  0x418A70
#define EQ_Character__Max_Endurance                                0x4242E0
#define EQ_Character__Max_HP                                       0x424190
#define EQ_Character__Max_Mana                                     0x4DCCB0
#define EQ_Character__doCombatAbility                              0x4DBB60

// EQ_Item
#define EQ_Item__CanDrop                                           0x4CFA60
#define EQ_Item__GetItemLinkHash                                   0x5F2720
#define EQ_Item__IsStackable                                       0x5FD8F0

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar                                0x465BA0
#define EQ_LoadingS__Array                                         0x6FDAC8

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                              0x4DF600
#define EQ_PC__GetAltAbilityIndex                                  0x5F6BB0
#define EQ_PC__GetCombatAbility                                    0x5F6CA0
#define EQ_PC__GetCombatAbilityTimer                               0x5F6D50
#define EQ_PC__GetItemTimerValue                                   0x4DB130

// EQItemList
#define EQItemList__dEQItemList                                    0x4859D0
#define EQItemList__EQItemList                                     0x485930

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                           0x4E3F90
#define EQPlayer__dEQPlayer                                        0x4E7D10
#define EQPlayer__DoAttack                                         0x4F2B00
#define EQPlayer__EQPlayer                                         0x4EA0C0
#define EQPlayer__SetNameSpriteState                               0x4E60E0
#define EQPlayer__SetNameSpriteTint                                0x4E4000

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4EAE50

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4D1520
#define KeypressHandler__AttachKeyToEqCommand                      0x4D1560
#define KeypressHandler__ClearCommandStateArray                    0x4D1330
#define KeypressHandler__HandleKeyDown                             0x4CFF70
#define KeypressHandler__HandleKeyUp                               0x4D0270
#define KeypressHandler__SaveKeymapping                            0x4D1400

// MapViewMap
#define MapViewMap__Clear                                          0x57B2F0
#define MapViewMap__SaveEx                                         0x57BCC0

// StringTable
#define StringTable__getString                                     0x5EE720
