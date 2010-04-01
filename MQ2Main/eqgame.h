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
#define __ExpectedVersionDate                                     "Apr 17 2006" 
#define __ExpectedVersionTime                                     "14:53:02" 
#define __ActualVersionDate                                        0x6B0B74
#define __ActualVersionTime                                        0x6B0B80

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x4D5D00
#define __MemChecker2                                              0x500E20
#define __MemChecker3                                              0x500ED0
#define __MemChecker4                                              0x5E3790
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
#define pinstControlledPlayer                                      0x966194
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
#define __CastRay                                                  0x49BB60
#define __ConvertItemTags                                          0x490D70
#define __ExecuteCmd                                               0x482610
#define __get_melee_range                                          0x487650
#define __GetGaugeValueFromEQ                                      0x5A9F70
#define __GetLabelFromEQ                                           0x5AA620
#define __NewUIINI                                                 0x5A9B50
#define __ProcessGameEvents                                        0x4C5280
#define __SendMessage                                              0x4A79B0
#define CrashDetected                                              0x500AF0
#define DrawNetStatus                                              0x4D89A0
#define Util__FastTime                                             0x5E8CB0


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                          0x464C70
#define AltAdvManager__IsAbilityReady                              0x464CB0
#define AltAdvManager__GetAltAbility                               0x464E00

// CBankWnd
#define CBankWnd__GetNumBankSlots                                  0x514A50

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                          0x51DB10

// CButtonWnd
#define CButtonWnd__SetCheck                                       0x63CDD0

// CChatManager
#define CChatManager__GetRGBAFromIndex                             0x530320
#define CChatManager__InitContextMenu                              0x530A60

// CChatWindow
#define CChatWindow__CChatWindow                                   0x534B90

// CComboWnd
#define CComboWnd__DeleteAll                                       0x61BD00
#define CComboWnd__Draw                                            0x61BEB0
//#define CComboWnd__GetButtonRect                                   0x0
#define CComboWnd__GetCurChoice                                    0x61BCB0
#define CComboWnd__GetListRect                                     0x61C1A0
#define CComboWnd__GetTextRect                                     0x61BD30
#define CComboWnd__InsertChoice                                    0x61C210
#define CComboWnd__SetColors                                       0x61BC40
#define CComboWnd__SetChoice                                       0x61BC70

// CContainerWnd
#define CContainerWnd__HandleCombine                               0x53B190
#define CContainerWnd__vftable                                     0x6B6D18

// CDisplay
#define CDisplay__CleanGameUI                                      0x455070
#define CDisplay__GetClickedActor                                  0x452890
#define CDisplay__GetUserDefinedColor                              0x451D00
#define CDisplay__GetWorldFilePath                                 0x451350
#define CDisplay__ReloadUI                                         0x4604B0
#define CDisplay__WriteTextHD2                                     0x4567D0

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                                  0x50EC60
#define CEditBaseWnd__SetSel                                       0x63BE50

// CEditWnd
#define CEditWnd__DrawCaret                                        0x6395B0
#define CEditWnd__GetCharIndexPt                                   0x63A3D0
#define CEditWnd__GetDisplayString                                 0x639740
#define CEditWnd__GetHorzOffset                                    0x6399B0
#define CEditWnd__GetLineForPrintableChar                          0x639E90
#define CEditWnd__GetSelStartPt                                    0x63A610
#define CEditWnd__GetSTMLSafeText                                  0x639B50
#define CEditWnd__PointFromPrintableChar                           0x639FA0
#define CEditWnd__SelectableCharFromPoint                          0x63A120
#define CEditWnd__SetEditable                                      0x639B20

// CEverQuest
#define CEverQuest__ClickedPlayer                                  0x4ABEB0
#define CEverQuest__DropHeldItemOnGround                           0x4AFC60
#define CEverQuest__dsp_chat                                       0x4B0820
#define CEverQuest__EnterZone                                      0x4C3EE0
#define CEverQuest__GetBodyTypeDesc                                0x4A92E0
#define CEverQuest__GetClassDesc                                   0x4A8A40
#define CEverQuest__GetClassThreeLetterCode                        0x4A9040
#define CEverQuest__GetDeityDesc                                   0x4A9830
#define CEverQuest__GetRaceDesc                                    0x4A9800
#define CEverQuest__InterpretCmd                                   0x4B1140
#define CEverQuest__LeftClickedOnPlayer                            0x4C2580
#define CEverQuest__RightClickedOnPlayer                           0x4C2990
#define CEverQuest__SetGameState                                   0x4ABEF0

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                                    0x5453D0
#define CGaugeWnd__CalcLinesFillRect                               0x545440
#define CGaugeWnd__Draw                                            0x5457D0

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                                 0x558CC0

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                                   0x5601F0
#define CInvSlotMgr__MoveItem                                      0x560390

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5612A0

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                                   0x567F20
#define CItemDisplayWnd__SetSpell                                  0x563B70

// CLabel
#define CLabel__Draw                                               0x56D360

// CListWnd
#define CListWnd__AddColumn                                        0x61BA50
#define CListWnd__AddColumn1                                       0x61B540
#define CListWnd__AddLine                                          0x61B120
#define CListWnd__AddString                                        0x61B2F0
#define CListWnd__CalculateFirstVisibleLine                        0x618450
#define CListWnd__CalculateVSBRange                                0x61A0D0
#define CListWnd__ClearAllSel                                      0x617BE0
#define CListWnd__CloseAndUpdateEditWindow                         0x618A80
#define CListWnd__Compare                                          0x618E30
#define CListWnd__Draw                                             0x6199D0
#define CListWnd__DrawColumnSeparators                             0x619C40
#define CListWnd__DrawHeader                                       0x617D70
#define CListWnd__DrawItem                                         0x619540
#define CListWnd__DrawLine                                         0x6198F0
#define CListWnd__DrawSeparator                                    0x6198F0
#define CListWnd__EnsureVisible                                    0x6184A0
#define CListWnd__ExtendSel                                        0x619470
//#define CListWnd__GetColumnFlags                                   0x0
//#define CListWnd__GetColumnJustification                           0x0
#define CListWnd__GetColumnMinWidth                                0x617980
#define CListWnd__GetColumnWidth                                   0x6178C0
#define CListWnd__GetCurSel                                        0x6173A0
#define CListWnd__GetHeaderRect                                    0x617490
#define CListWnd__GetItemAtPoint                                   0x618790
#define CListWnd__GetItemAtPoint1                                  0x618800
#define CListWnd__GetItemData                                      0x617670
#define CListWnd__GetItemHeight                                    0x6181E0
#define CListWnd__GetItemIcon                                      0x617800
#define CListWnd__GetItemRect                                      0x618580
#define CListWnd__GetItemText                                      0x6176B0
#define CListWnd__GetSelList                                       0x61B420
#define CListWnd__GetSeparatorRect                                 0x618D70
//#define CListWnd__IsLineEnabled                                    0x0
#define CListWnd__RemoveLine                                       0x61BA00
#define CListWnd__SetColors                                        0x617400
#define CListWnd__SetColumnJustification                           0x6179E0
#define CListWnd__SetColumnWidth                                   0x617940
#define CListWnd__SetCurSel                                        0x6173E0
#define CListWnd__SetItemColor                                     0x61ACF0
#define CListWnd__SetItemData                                      0x617C80
#define CListWnd__SetItemText                                      0x61AC70
#define CListWnd__ShiftColumnSeparator                             0x6193E0
#define CListWnd__Sort                                             0x61BA80
#define CListWnd__ToggleSel                                        0x617B50

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                                   0x57F150

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x580AB0 
#define CMerchantWnd__RequestBuyItem                               0x581C20
#define CMerchantWnd__RequestSellItem                              0x580D10
#define CMerchantWnd__SelectBuySellSlot                            0x581920

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1                     0x62DDC0

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                          0x510670
#define CSidlScreenWnd__CalculateVSBRange                          0x5105B0
#define CSidlScreenWnd__ConvertToRes                               0x621A00
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x622260
#define CSidlScreenWnd__CSidlScreenWnd1                            0x623520
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6235D0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x622DE0
#define CSidlScreenWnd__DrawSidlPiece                              0x621F80
#define CSidlScreenWnd__EnableIniStorage                           0x6219B0
#define CSidlScreenWnd__GetSidlPiece                               0x622140
#define CSidlScreenWnd__Init1                                      0x623340
#define CSidlScreenWnd__LoadIniInfo                                0x622310
#define CSidlScreenWnd__LoadIniListWnd                             0x621B70
#define CSidlScreenWnd__LoadSidlScreen                             0x621DB0
//#define CSidlScreenWnd__SetScreen                                  0x0
#define CSidlScreenWnd__StoreIniInfo                               0x6214E0
#define CSidlScreenWnd__WndNotification                            0x621EE0

// CSliderWnd
#define CSliderWnd__GetValue                                       0x63EA00
#define CSliderWnd__SetValue                                       0x63EB00
//#define CSliderWnd__UpdateThumb                                    0x0

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                                 0x5A7C80

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6381D0
#define CStmlWnd__CalculateHSBRange                                0x630570
#define CStmlWnd__CalculateVSBRange                                0x630510
#define CStmlWnd__CanBreakAtCharacter                              0x6306B0
#define CStmlWnd__CanGoBackward                                    0x630770
#define CStmlWnd__FastForwardToEndOfTag                            0x6311C0
//#define CStmlWnd__GetNextChar                                      0x0
#define CStmlWnd__GetNextTagPiece                                  0x6310E0
#define CStmlWnd__GetSTMLText                                      0x534B30
#define CStmlWnd__GetThisChar                                      0x659990
#define CStmlWnd__GetVisiableText                                  0x6323E0
#define CStmlWnd__InitializeWindowVariables                        0x634540
#define CStmlWnd__MakeStmlColorTag                                 0x62FC10
#define CStmlWnd__MakeWndNotificationTag                           0x62FCB0
#define CStmlWnd__StripFirstSTMLLines                              0x637F60
#define CStmlWnd__UpdateHistoryString                              0x632C40

// CTabWnd
#define CTabWnd__Draw                                              0x63E420
#define CTabWnd__DrawCurrentPage                                   0x63DE20
#define CTabWnd__DrawTab                                           0x63DC00
#define CTabWnd__GetCurrentPage                                    0x63E0A0
//#define CTabWnd__GetCurrentTabIndex                                0x0
//#define CTabWnd__GetNumTabs                                        0x0
#define CTabWnd__GetPageClientRect                                 0x63D8D0
#define CTabWnd__GetPageFromTabIndex                               0x63DB30
#define CTabWnd__GetPageInnerRect                                  0x63D930
#define CTabWnd__GetTabInnerRect                                   0x63DAB0
#define CTabWnd__GetTabRect                                        0x63D9C0
#define CTabWnd__IndexInBounds                                     0x63DBCD
#define CTabWnd__InsertPage                                        0x63E640
#define CTabWnd__SetPage                                           0x63E0E0
#define CTabWnd__SetPageRect                                       0x63E350
#define CTabWnd__UpdatePage                                        0x63E5C0

// CTextOverlay
#define CTextOverlay__DisplayText                                  0x411FB0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x623930

// CXMLDataManager
#define CXMLDataManager__GetXMLData                                0x643E20

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                               0x617130

// CXRect
#define CXRect__CenterPoint                                        0x514200

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                               0x4105A0
#define CXStr__CXStr1                                              0x4F3E50
#define CXStr__CXStr3                                              0x5EA270
#define CXStr__dCXStr                                              0x445890
#define CXStr__operator_equal1                                     0x5EA430
#define CXStr__operator_plus_equal1                                0x5EB270

// CXWnd
#define CXWnd__BringToTop                                          0x61CA20
#define CXWnd__Center                                              0x6200C0
#define CXWnd__ClrFocus                                            0x61C720
#define CXWnd__DoAllDrawing                                        0x620DD0
#define CXWnd__DrawChildren                                        0x620F00
#define CXWnd__DrawColoredRect                                     0x61CC80
#define CXWnd__DrawTooltip                                         0x620D00
#define CXWnd__DrawTooltipAtPoint                                  0x61FF20
#define CXWnd__GetBorderFrame                                      0x61D120
#define CXWnd__GetChildWndAt                                       0x61FA20
#define CXWnd__GetClientClipRect                                   0x61D050
#define CXWnd__GetFirstChildWnd                                    0x61CAC0
#define CXWnd__GetNextChildWnd                                     0x61F9E0
#define CXWnd__GetNextSib                                          0x61CAE0
#define CXWnd__GetScreenClipRect                                   0x620350
#define CXWnd__GetScreenRect                                       0x61D2C0
#define CXWnd__GetTooltipRect                                      0x61CEC0
#define CXWnd__GetWindowTextA                                      0x508060
#define CXWnd__IsActive                                            0x6249E0
#define CXWnd__IsDescendantOf                                      0x61D0D0
#define CXWnd__IsReallyVisible                                     0x61F9C0
#define CXWnd__IsType                                              0x620D80
#define CXWnd__Move                                                0x61F4D0
#define CXWnd__Move1                                               0x61F570
#define CXWnd__ProcessTransition                                   0x61C9F0
#define CXWnd__Refade                                              0x61C7D0
#define CXWnd__Resize                                              0x620490
#define CXWnd__Right                                               0x620230
#define CXWnd__SetFirstChildPointer                                0x61D530
#define CXWnd__SetFocus                                            0x61E820
#define CXWnd__SetKeyTooltip                                       0x61D590
#define CXWnd__SetMouseOver                                        0x61D560
#define CXWnd__SetNextSibPointer                                   0x61D540
#define CXWnd__StartFade                                           0x61CA40

// CXWndManager
#define CXWndManager__DrawCursor                                   0x625ED0
#define CXWndManager__DrawWindows                                  0x625B90
#define CXWndManager__GetFirstChildWnd                             0x625430
#define CXWndManager__GetKeyboardFlags                             0x6246F0
#define CXWndManager__HandleKeyboardMsg                            0x624C80
#define CXWndManager__RemoveWnd                                    0x624BA0

// CDBStr
#define CDBStr__GetString                                          0x44E960

// EQ_Character
#define EQ_Character__CastRay                                      0x666150
#define EQ_Character__CastSpell                                    0x41E760
#define EQ_Character__Cur_HP                                       0x4259B0
#define EQ_Character__GetAACastingTimeModifier                     0x419810
#define EQ_Character__GetCharInfo2                                 0x5FD490
#define EQ_Character__GetFocusCastingTimeModifier                  0x418A70
#define EQ_Character__Max_Endurance                                0x4242E0
#define EQ_Character__Max_HP                                       0x424190
#define EQ_Character__Max_Mana                                     0x4DD310
#define EQ_Character__doCombatAbility                              0x4DC1C0

// EQ_Item
#define EQ_Item__CanDrop                                           0x4D0030
#define EQ_Item__GetItemLinkHash                                   0x5F2780
#define EQ_Item__IsStackable                                       0x5FD950

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar                                0x465CD0
#define EQ_LoadingS__Array                                         0x6FDAC8

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                              0x4DFC60
#define EQ_PC__GetAltAbilityIndex                                  0x5F6C10
#define EQ_PC__GetCombatAbility                                    0x5F6D00
#define EQ_PC__GetCombatAbilityTimer                               0x5F6DB0
#define EQ_PC__GetItemTimerValue                                   0x4DB790

// EQItemList
#define EQItemList__dEQItemList                                    0x485EE0
#define EQItemList__EQItemList                                     0x485E40

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                           0x4E45F0
#define EQPlayer__dEQPlayer                                        0x4E8440
#define EQPlayer__DoAttack                                         0x4F3280
#define EQPlayer__EQPlayer                                         0x4EA7A0
#define EQPlayer__SetNameSpriteState                               0x4E6740
#define EQPlayer__SetNameSpriteTint                                0x4E4660

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4EB530

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4D1B80
#define KeypressHandler__AttachKeyToEqCommand                      0x4D1BC0
#define KeypressHandler__ClearCommandStateArray                    0x4D1990
#define KeypressHandler__HandleKeyDown                             0x4D05D0
#define KeypressHandler__HandleKeyUp                               0x4D08D0
#define KeypressHandler__SaveKeymapping                            0x4D1A60

// MapViewMap
#define MapViewMap__Clear                                          0x57B580
#define MapViewMap__SaveEx                                         0x57BF50

// StringTable
#define StringTable__getString                                     0x5EE780
