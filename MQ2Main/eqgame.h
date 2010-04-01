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
#define __ExpectedVersionDate                                     "Jul 10 2006"
#define __ExpectedVersionTime                                     "14:03:12"
#define __ActualVersionDate                                        0x6A2B74
#define __ActualVersionTime                                        0x6A2B80

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x4D5190
#define __MemChecker2                                              0x500270
#define __MemChecker3                                              0x500320
#define __MemChecker4                                              0x5D3B90
#define __EncryptPad0                                              0x7E3720
#define __EncryptPad2                                              0x7E5860
#define __EncryptPad3                                              0x7E5C60
#define __EncryptPad4                                              0x7EC688

// Direct Input
#define DI8__Main                                                  0x9D7A8C
#define DI8__Keyboard                                              0x9D7A90
#define DI8__Mouse                                                 0x9D7A94

#define __AltTimerReady                                            0x97343A
#define __Attack                                                   0x9D468F
#define __Autofire                                                 0x9D4690
#define __BindList                                                 0x7DEB20
#define __Clicks                                                   0x9725C4
#define __CommandList                                              0x7DF300
#define __CurrentMapLabel                                          0x9E0B3C
#define __CurrentSocial                                            0x6EAF10
#define __DoAbilityAvailable                                       0x9733D4
#define __DoAbilityList                                            0x9AC1DC
#define __DrawHandler                                              0x9ECEBC
#define __FriendsList                                              0x9A8F7C
#define __GroupCount                                               0x952D20
#define __GroupLeader                                              0x952E7C
#define __Guilds                                                   0x954808
#define __gWorld                                                   0x954778
#define __HotkeyPage                                               0x9D35C8
#define __HWnd                                                     0x9D7A34
#define __IgnoreList                                               0x9AA87C
#define __InChatMode                                               0x972500
#define __LastTell                                                 0x9746E8
#define __Mouse                                                    0x9D7A98
#define __MouseLook                                                0x972592
#define __NetStatusToggle                                          0x972594
#define __PCNames                                                  0x973740
#define __RangeAttackReady                                         0x973438
#define __RunWalkState                                             0x972504
#define __ScreenMode                                               0x8A26D0
#define __ScreenX                                                  0x9724C8
#define __ScreenY                                                  0x9724CC
#define __ServerHost                                               0x952C74
#define __ServerName                                               0x9AC19C
#define __ShowNames                                                0x973620
#define __SkillDict                                                0x8A33C8
#define __Socials                                                  0x9AC29C

////
//Section 1: Vital Offsets
////
#define instCRaid                                                  0x96C458
#define instEQZoneInfo                                             0x972730
#define instKeypressHandler                                        0x9D4764
#define pinstActiveBanker                                          0x9547E8
#define pinstActiveCorpse                                          0x9547EC
#define pinstActiveGMaster                                         0x9547F0
#define pinstActiveMerchant                                        0x9547E4
#define pinstAltAdvManager                                         0x8A33A0
#define pinstAuraInfo                                              0x7F2004
#define pinstBandageTarget                                         0x9547D0
#define pinstCamActor                                              0x8A2E90
#define pinstCDBStr                                                0x8A2560
#define pinstCDisplay                                              0x9547F8
#define pinstCEverQuest                                            0x9D7C00
#define pinstCharData                                              0x9547B8
#define pinstCharSpawn                                             0x9547DC
#define pinstControlledMissile                                     0x9547B4
#define pinstControlledPlayer                                      0x9547DC
#define pinstCSidlManager                                          0x9EC760
#define pinstCXWndManager                                          0x9EC758
#define pinstDynamicZone                                           0x971F18
#define pinstDZMember                                              0x972028
#define pinstDZTimerInfo                                           0x97202C
#define pinstEQItemList                                            0x95479C
#define pinstEQSoundManager                                        0x8A3558
#define instExpeditionLeader                                       0x971F62
#define instExpeditionName                                         0x971FA2
#define instGroup                                                  0x952D20
#define pinstGroup                                                 0x952D1C
#define pinstImeManager                                            0x9EC764
#define pinstLocalPlayer                                           0x9547C8
#define pinstModelPlayer                                           0x9547F4
#define pinstPCData                                                0x9547B8
#define pinstSelectedItem                                          0x9E0994
#define pinstSpawnManager                                          0x9D4A74
#define pinstSpellManager                                          0x9D4ADC
#define pinstSpellSets                                             0x9D35CC
#define pinstStringTable                                           0x954788
#define pinstSwitchManager                                         0x952970
#define pinstTarget                                                0x9547E0
#define pinstTargetObject                                          0x9547BC
#define pinstTargetSwitch                                          0x9547C0
#define pinstTaskMember                                            0x8A24FC
#define pinstTrackTarget                                           0x9547D4
#define pinstTradeTarget                                           0x9547C4
#define instTributeActive                                          0x8A253D
#define pinstViewActor                                             0x8A2E8C
#define pinstWorldData                                             0x954798


////
//Section 2:  UI Related Offsets
////
//#define pinstCAdventureMerchantWnd                                 0x801ED0
#define pinstCTextOverlay                                          0x7F0588
#define pinstCAudioTriggersWindow                                  0x7F0554
//                                                                   0x803988
#define pinstCCharacterSelect                                      0x8A2D58
#define pinstCFacePick                                             0x8A2D5C
#define pinstCNoteWnd                                              0x8A2D60
#define pinstCBookWnd                                              0x8A2D64
#define pinstCPetInfoWnd                                           0x8A2D68
#define pinstCTrainWnd                                             0x8A2D6C
#define pinstCSkillsWnd                                            0x8A2D70
#define pinstCSkillsSelectWnd                                      0x8A2D74
#define pinstCCombatSkillSelectWnd                                 0x8A2D78
#define pinstCFriendsWnd                                           0x8A2D7C
#define pinstCAuraWnd                                              0x8A2D80
#define pinstCRespawnWnd                                           0x8A2D84
#define pinstCBandolierWnd                                         0x8A2D88
#define pinstCPotionBeltWnd                                        0x8A2D8C
#define pinstCAAWnd                                                0x8A2D90
#define pinstCGroupSearchFiltersWnd                                0x8A2D94
#define pinstCLoadskinWnd                                          0x8A2D98
#define pinstCAlarmWnd                                             0x8A2D9C
#define pinstCMusicPlayerWnd                                       0x8A2DA0
#define pinstCMailWnd                                              0x8A2DA4
#define pinstCMailCompositionWnd                                   0x8A2DA8
#define pinstCMailAddressBookWnd                                   0x8A2DAC
#define pinstCRaidWnd                                              0x8A2DB0
#define pinstCRaidOptionsWnd                                       0x8A2DB4
#define pinstCBreathWnd                                            0x8A2DB8
#define pinstCMapViewWnd                                           0x8A2DBC
#define pinstCMapToolbarWnd                                        0x8A2DC0
#define pinstCEditLabelWnd                                         0x8A2DC4
#define pinstCTargetWnd                                            0x8A2DC8
#define pinstCColorPickerWnd                                       0x8A2DCC
#define pinstCPlayerWnd                                            0x8A2DD0
#define pinstCOptionsWnd                                           0x8A2DD4
#define pinstCBuffWindowNORMAL                                     0x8A2DD8
#define pinstCBuffWindowSHORT                                      0x8A2DDC
#define pinstCharacterCreation                                     0x8A2DE0
#define pinstCCursorAttachment                                     0x8A2DE4
#define pinstCCastingWnd                                           0x8A2DE8
#define pinstCCastSpellWnd                                         0x8A2DEC
#define pinstCSpellBookWnd                                         0x8A2DF0
#define pinstCInventoryWnd                                         0x8A2DF4
#define pinstCBankWnd                                              0x8A2DF8
#define pinstCQuantityWnd                                          0x8A2DFC
#define pinstCLootWnd                                              0x8A2E00
#define pinstCActionsWnd                                           0x8A2E04
#define pinstCCombatAbilityWnd                                     0x8A2E08
#define pinstCMerchantWnd                                          0x8A2E0C
#define pinstCTradeWnd                                             0x8A2E10
#define pinstCSelectorWnd                                          0x8A2E14
#define pinstCBazaarWnd                                            0x8A2E18
#define pinstCBazaarSearchWnd                                      0x8A2E1C
#define pinstCGiveWnd                                              0x8A2E20
#define pinstCTrackingWnd                                          0x8A2E24
#define pinstCInspectWnd                                           0x8A2E28
#define pinstCSocialEditWnd                                        0x8A2E2C
#define pinstCFeedbackWnd                                          0x8A2E30
#define pinstCBugReportWnd                                         0x8A2E34
#define pinstCVideoModesWnd                                        0x8A2E38
#define pinstCTextEntryWnd                                         0x8A2E40
#define pinstCFileSelectionWnd                                     0x8A2E44
#define pinstCCompassWnd                                           0x8A2E48
#define pinstCPlayerNotesWnd                                       0x8A2E4C
#define pinstCGemsGameWnd                                          0x8A2E50
#define pinstCTimeLeftWnd                                          0x8A2E54
#define pinstCPetitionQWnd                                         0x8A2E58
#define pinstCSoulmarkWnd                                          0x8A2E5C
#define pinstCStoryWnd                                             0x8A2E60
#define pinstCJournalTextWnd                                       0x8A2E64
#define pinstCJournalCatWnd                                        0x8A2E68
#define pinstCBodyTintWnd                                          0x8A2E6C
#define pinstCServerListWnd                                        0x8A2E70
#define pinstCAvaZoneWnd                                           0x8A2E74
#define pinstCBlockedBuffWnd                                       0x8A2E78
#define pinstCBlockedPetBuffWnd                                    0x8A2E7C
#define pinstCInvSlotMgr                                           0x8A2E80
#define pinstCContainerMgr                                         0x8A2E84
//                                                                   0x9E6074
//                                                                   0x9E60AC
//                                                                   0x9E6450
#define pinstCAdventureLeaderboardWnd                              0x9E01CC
#define pinstCAdventureRequestWnd                                  0x9E01E8
#define pinstCAltStorageWnd                                        0x9E0248
#define pinstCAdventureStatsWnd                                    0x9E0204
#define pinstCBarterMerchantWnd                                    0x9E03FC
#define pinstCBarterSearchWnd                                      0x9E0418
#define pinstCBarterWnd                                            0x9E0434
//                                                                   0x9F1F40
#define pinstCChatManager                                          0x9E0624
#define pinstCDynamicZoneWnd                                       0x9E0700
#define pinstCEQMainWnd                                            0x9E0770
#define pinstCFindLocationWnd                                      0x9E0804
#define pinstCGroupSearchWnd                                       0x9E08BC
#define pinstCGroupWnd                                             0x9E08B4
#define pinstCGuildBankWnd                                         0x9E08D0
#define pinstCGuildMgmtWnd                                         0x9E08EC
#define pinstCGuildTributeMasterWnd                                0x9E0908
#define pinstCHotButtonWnd                                         0x9E0924
#define pinstCHotButtonWnd1                                        0x9E0924
#define pinstCHotButtonWnd2                                        0x9E0928
#define pinstCHotButtonWnd3                                        0x9E092C
#define pinstCHotButtonWnd4                                        0x9E0930
#define pinstCItemDisplayManager                                   0x9E09C8
#define pinstCItemExpTransferWnd                                   0x9E09E8
#define pinstCLeadershipWnd                                        0x9E0A64
#define pinstCLFGuildWnd                                           0x9E0A80
#define pinstCMIZoneSelectWnd                                      0x9E0BA4
#define pinstCAdventureMerchantWnd                                 0x9E0C68
#define pinstCConfirmationDialog                                   0x9E0C84
#define pinstCPopupWndManager                                      0x9E0C84
#define pinstCProgressionSelectionWnd                              0x9E0CB8
#define pinstCPvPLeaderboardWnd                                    0x9E0CD4
#define pinstCPvPStatsWnd                                          0x9E0CF0
//                                                                   0x9F2744
#define pinstCSystemInfoDialogBox                                  0x9E1650
#define pinstCTargetOfTargetWnd                                    0x9E166C
#define pinstCTaskSelectWnd                                        0x9E16A0
#define pinstCTaskTemplateSelectWnd                                0x9E16BC
#define pinstCTaskWnd                                              0x9E16D8
#define pinstCTicketCommentWnd                                     0x9E170C
#define pinstCHelpWnd                                              0x9E1728
#define pinstCTipWndOFDAY                                          0x9E175C
#define pinstCTipWndCONTEXT                                        0x9E1760
#define pinstCTitleWnd                                             0x9E177C
#define pinstCTradeskillWnd                                        0x9E17C0
#define pinstCTributeBenefitWnd                                    0x9E180C
#define pinstCTributeMasterWnd                                     0x9E1828
#define pinstCContextMenuManager                                   0x9EC7BC
#define pinstCVoiceMacroWnd                                        0x9D4BA4


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                                  0x49BA10
#define __ConvertItemTags                                          0x490C20
#define __ExecuteCmd                                               0x482760
#define __get_melee_range                                          0x4877E0
#define __GetGaugeValueFromEQ                                      0x5AB0F0
#define __GetLabelFromEQ                                           0x5AB7A0
#define __NewUIINI                                                 0x5AACE0
#define __ProcessGameEvents                                        0x4C40F0
#define __SendMessage                                              0x4A78B0
#define CrashDetected                                              0x4FFF40
#define DrawNetStatus                                              0x4D7E20
#define Util__FastTime                                             0x5D90A0


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                          0x464C10
#define AltAdvManager__IsAbilityReady                              0x464C50
#define AltAdvManager__GetAltAbility                               0x464E10

// CBankWnd
#define CBankWnd__GetNumBankSlots                                  0x4F6810

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                          0x51D2C0

// CButtonWnd
#define CButtonWnd__SetCheck                                       0x62DF60

// CChatManager
#define CChatManager__GetRGBAFromIndex                             0x530280
#define CChatManager__InitContextMenu                              0x5309C0

// CChatWindow
#define CChatWindow__CChatWindow                                   0x534AD0

// CComboWnd
#define CComboWnd__DeleteAll                                       0x60CEF0
#define CComboWnd__Draw                                            0x60D0A0
//#define CComboWnd__GetButtonRect                                   0x0
#define CComboWnd__GetCurChoice                                    0x60CEA0
#define CComboWnd__GetListRect                                     0x60D390
#define CComboWnd__GetTextRect                                     0x60CF20
#define CComboWnd__InsertChoice                                    0x60D400
#define CComboWnd__SetColors                                       0x60CE30
#define CComboWnd__SetChoice                                       0x60CE60

// CContainerWnd
#define CContainerWnd__HandleCombine                               0x53B0F0
#define CContainerWnd__vftable                                     0x6A8DB0

// CDisplay
#define CDisplay__CleanGameUI                                      0x4550B0
#define CDisplay__GetClickedActor                                  0x452A10
#define CDisplay__GetUserDefinedColor                              0x451E80
#define CDisplay__GetWorldFilePath                                 0x4514D0
#define CDisplay__ReloadUI                                         0x460460
#define CDisplay__WriteTextHD2                                     0x456810

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                                  0x50E210
#define CEditBaseWnd__SetSel                                       0x62CFE0

// CEditWnd
#define CEditWnd__DrawCaret                                        0x61A070
#define CEditWnd__GetCharIndexPt                                   0x61AE90
#define CEditWnd__GetDisplayString                                 0x61A200
#define CEditWnd__GetHorzOffset                                    0x61A470
#define CEditWnd__GetLineForPrintableChar                          0x61A950
#define CEditWnd__GetSelStartPt                                    0x61B0D0
#define CEditWnd__GetSTMLSafeText                                  0x61A610
#define CEditWnd__PointFromPrintableChar                           0x61AA60
#define CEditWnd__SelectableCharFromPoint                          0x61ABE0
#define CEditWnd__SetEditable                                      0x61A5E0

// CEverQuest
#define CEverQuest__ClickedPlayer                                  0x4ABD60
#define CEverQuest__DropHeldItemOnGround                           0x4AF860
#define CEverQuest__dsp_chat                                       0x4B0410
#define CEverQuest__EnterZone                                      0x4C2CC0
#define CEverQuest__GetBodyTypeDesc                                0x4A9150
#define CEverQuest__GetClassDesc                                   0x4A88B0
#define CEverQuest__GetClassThreeLetterCode                        0x4A8EB0
#define CEverQuest__GetDeityDesc                                   0x4A96A0
#define CEverQuest__GetLangDesc                                    0x4A93C0
#define CEverQuest__GetRaceDesc                                    0x4A9670
#define CEverQuest__InterpretCmd                                   0x4B0D20
#define CEverQuest__LeftClickedOnPlayer                            0x4C1930
#define CEverQuest__RightClickedOnPlayer                           0x4C1D40
#define CEverQuest__SetGameState                                   0x4ABDA0

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                                    0x545E60
#define CGaugeWnd__CalcLinesFillRect                               0x545ED0
#define CGaugeWnd__Draw                                            0x546260

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                                 0x559810

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                                   0x560E90
#define CInvSlotMgr__MoveItem                                      0x561030

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x561F40

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                                   0x568C40
#define CItemDisplayWnd__SetSpell                                  0x564930

// CLabel
#define CLabel__Draw                                               0x56E060

// CListWnd
#define CListWnd__AddColumn                                        0x60CC40
#define CListWnd__AddColumn1                                       0x60C770
#define CListWnd__AddLine                                          0x60C300
#define CListWnd__AddString                                        0x60C4D0
#define CListWnd__CalculateFirstVisibleLine                        0x609630
#define CListWnd__CalculateVSBRange                                0x60B2B0
#define CListWnd__ClearAllSel                                      0x608DC0
#define CListWnd__CloseAndUpdateEditWindow                         0x609C60
#define CListWnd__Compare                                          0x60A010
#define CListWnd__Draw                                             0x60ABB0
#define CListWnd__DrawColumnSeparators                             0x60AE20
#define CListWnd__DrawHeader                                       0x608F50
#define CListWnd__DrawItem                                         0x60A720
#define CListWnd__DrawLine                                         0x60AAD0
#define CListWnd__DrawSeparator                                    0x60AAD0
#define CListWnd__EnsureVisible                                    0x609680
#define CListWnd__ExtendSel                                        0x60A650
//#define CListWnd__GetColumnFlags                                   0x0
//#define CListWnd__GetColumnJustification                           0x0
#define CListWnd__GetColumnMinWidth                                0x608B60
#define CListWnd__GetColumnWidth                                   0x608AA0
#define CListWnd__GetCurSel                                        0x608580
#define CListWnd__GetHeaderRect                                    0x608670
#define CListWnd__GetItemAtPoint                                   0x609970
#define CListWnd__GetItemAtPoint1                                  0x6099E0
#define CListWnd__GetItemData                                      0x608850
#define CListWnd__GetItemHeight                                    0x6093C0
#define CListWnd__GetItemIcon                                      0x6089E0
#define CListWnd__GetItemRect                                      0x609760
#define CListWnd__GetItemText                                      0x608890
#define CListWnd__GetSelList                                       0x60C650
#define CListWnd__GetSeparatorRect                                 0x609F50
//#define CListWnd__IsLineEnabled                                    0x0
#define CListWnd__RemoveLine                                       0x60C600
#define CListWnd__SetColors                                        0x6085E0
#define CListWnd__SetColumnJustification                           0x608BC0
#define CListWnd__SetColumnWidth                                   0x608B20
#define CListWnd__SetCurSel                                        0x6085C0
#define CListWnd__SetItemColor                                     0x60BED0
#define CListWnd__SetItemData                                      0x608E60
#define CListWnd__SetItemText                                      0x60BE50
#define CListWnd__ShiftColumnSeparator                             0x60A5C0
#define CListWnd__Sort                                             0x60CC70
#define CListWnd__ToggleSel                                        0x608D30

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                                   0x580330

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x581D20
#define CMerchantWnd__RequestBuyItem                               0x582E90
#define CMerchantWnd__RequestSellItem                              0x581F80
#define CMerchantWnd__SelectBuySellSlot                            0x582B90

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1                     0x621860

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                          0x612550
#define CSidlScreenWnd__CalculateVSBRange                          0x50FB70
#define CSidlScreenWnd__ConvertToRes                               0x612CA0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6135B0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x614870
#define CSidlScreenWnd__CSidlScreenWnd2                            0x614920
#define CSidlScreenWnd__dCSidlScreenWnd                            0x614130
#define CSidlScreenWnd__DrawSidlPiece                              0x6132D0
#define CSidlScreenWnd__EnableIniStorage                           0x612C50
#define CSidlScreenWnd__GetSidlPiece                               0x613490
#define CSidlScreenWnd__Init1                                      0x614690
#define CSidlScreenWnd__LoadIniInfo                                0x613660
#define CSidlScreenWnd__LoadIniListWnd                             0x612E10
#define CSidlScreenWnd__LoadSidlScreen                             0x613100
//#define CSidlScreenWnd__SetScreen                                  0x0
#define CSidlScreenWnd__StoreIniInfo                               0x612780
#define CSidlScreenWnd__WndNotification                            0x613230

// CSliderWnd
#define CSliderWnd__GetValue                                       0x62FBF0
#define CSliderWnd__SetValue                                       0x62FCF0
#define CSliderWnd__SetNumTicks                                    0x630230

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                                 0x5A8E10

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x62BC90
#define CStmlWnd__CalculateHSBRange                                0x624020
#define CStmlWnd__CalculateVSBRange                                0x623FC0
#define CStmlWnd__CanBreakAtCharacter                              0x624160
#define CStmlWnd__CanGoBackward                                    0x624210
#define CStmlWnd__FastForwardToEndOfTag                            0x624C60
//#define CStmlWnd__GetNextChar                                      0x0
#define CStmlWnd__GetNextTagPiece                                  0x624B80
#define CStmlWnd__GetSTMLText                                      0x534A70
#define CStmlWnd__GetThisChar                                      0x64ABF0
#define CStmlWnd__GetVisiableText                                  0x625EA0
#define CStmlWnd__InitializeWindowVariables                        0x628000
#define CStmlWnd__MakeStmlColorTag                                 0x6236C0
#define CStmlWnd__MakeWndNotificationTag                           0x623760
#define CStmlWnd__StripFirstSTMLLines                              0x62BA20
#define CStmlWnd__UpdateHistoryString                              0x626700

// CTabWnd
#define CTabWnd__Draw                                              0x62F620
#define CTabWnd__DrawCurrentPage                                   0x62EFA0
#define CTabWnd__DrawTab                                           0x62ED80
#define CTabWnd__GetCurrentPage                                    0x62F2A0
//#define CTabWnd__GetCurrentTabIndex                                0x0
//#define CTabWnd__GetNumTabs                                        0x0
#define CTabWnd__GetPageClientRect                                 0x62EA50
#define CTabWnd__GetPageFromTabIndex                               0x62ECB0
#define CTabWnd__GetPageInnerRect                                  0x62EAB0
#define CTabWnd__GetTabInnerRect                                   0x62EC30
#define CTabWnd__GetTabRect                                        0x62EB40
#define CTabWnd__IndexInBounds                                     0x62ED4D
#define CTabWnd__InsertPage                                        0x62F840
#define CTabWnd__SetPage                                           0x62F2E0
#define CTabWnd__SetPageRect                                       0x62F550
#define CTabWnd__UpdatePage                                        0x62F7C0

// CTextOverlay
#define CTextOverlay__DisplayText                                  0x412330

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x614C80

// CXMLDataManager
#define CXMLDataManager__GetXMLData                                0x634FF0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                               0x608310

// CXRect
#define CXRect__CenterPoint                                        0x5136C0

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                               0x410730
#define CXStr__CXStr1                                              0x4F32B0
#define CXStr__CXStr3                                              0x5DA6B0
#define CXStr__dCXStr                                              0x407950
#define CXStr__operator_equal1                                     0x5DA870
#define CXStr__operator_plus_equal1                                0x5DB6B0

// CXWnd
#define CXWnd__BringToTop                                          0x60DC10
#define CXWnd__Center                                              0x6112B0
#define CXWnd__ClrFocus                                            0x60D910
#define CXWnd__DoAllDrawing                                        0x611FC0
#define CXWnd__DrawChildren                                        0x6120F0
#define CXWnd__DrawColoredRect                                     0x60DE70
#define CXWnd__DrawTooltip                                         0x611EF0
#define CXWnd__DrawTooltipAtPoint                                  0x611110
#define CXWnd__GetBorderFrame                                      0x60E310
#define CXWnd__GetChildWndAt                                       0x610C10
#define CXWnd__GetClientClipRect                                   0x60E240
#define CXWnd__GetFirstChildWnd                                    0x60DCB0
#define CXWnd__GetNextChildWnd                                     0x610BD0
#define CXWnd__GetNextSib                                          0x60DCD0
#define CXWnd__GetScreenClipRect                                   0x611540
#define CXWnd__GetScreenRect                                       0x60E4B0
#define CXWnd__GetTooltipRect                                      0x60E0B0
#define CXWnd__GetWindowTextA                                      0x507540
#define CXWnd__IsActive                                            0x615D30
#define CXWnd__IsDescendantOf                                      0x60E2C0
#define CXWnd__IsReallyVisible                                     0x610BB0
#define CXWnd__IsType                                              0x611F70
#define CXWnd__Move                                                0x6106C0
#define CXWnd__Move1                                               0x610760
#define CXWnd__ProcessTransition                                   0x60DBE0
#define CXWnd__Refade                                              0x60D9C0
#define CXWnd__Resize                                              0x611680
#define CXWnd__Right                                               0x611420
#define CXWnd__SetFirstChildPointer                                0x60E720
#define CXWnd__SetFocus                                            0x60FA10
#define CXWnd__SetKeyTooltip                                       0x60E780
#define CXWnd__SetMouseOver                                        0x60E750
#define CXWnd__SetNextSibPointer                                   0x60E730
#define CXWnd__StartFade                                           0x60DC30

// CXWndManager
#define CXWndManager__DrawCursor                                   0x6170F0
#define CXWndManager__DrawWindows                                  0x616DB0
#define CXWndManager__GetFirstChildWnd                             0x6166D0
#define CXWndManager__GetKeyboardFlags                             0x615A40
#define CXWndManager__HandleKeyboardMsg                            0x615F20
#define CXWndManager__RemoveWnd                                    0x615E40

// CDBStr
#define CDBStr__GetString                                          0x44EAF0

// EQ_Character
#define EQ_Character__CastRay                                      0x657520
#define EQ_Character__CastSpell                                    0x41E6D0
#define EQ_Character__Cur_HP                                       0x425930
#define EQ_Character__GetAACastingTimeModifier                     0x419850
#define EQ_Character__GetCharInfo2                                 0x5ED770
#define EQ_Character__GetFocusCastingTimeModifier                  0x418AE0
#define EQ_Character__Max_Endurance                                0x424290
#define EQ_Character__Max_HP                                       0x424140
#define EQ_Character__Max_Mana                                     0x4DC750
#define EQ_Character__doCombatAbility                              0x4DB5E0
#define EQ_Character__UseSkill                                     0x430F80

// EQ_Item
#define EQ_Item__CanDrop                                           0x4CF300
#define EQ_Item__GetItemLinkHash                                   0x5E2C40
#define EQ_Item__IsStackable                                       0x5EDC30

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar                                0x465CE0
#define EQ_LoadingS__Array                                         0x6EDC20

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                              0x4DF4B0
#define EQ_PC__GetAltAbilityIndex                                  0x5E6EC0
#define EQ_PC__GetCombatAbility                                    0x5E6FB0
#define EQ_PC__GetCombatAbilityTimer                               0x5E7060
#define EQ_PC__GetItemTimerValue                                   0x4DAC10

// EQItemList
#define EQItemList__dEQItemList                                    0x4860A0
#define EQItemList__EQItemList                                     0x486000

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                           0x4E39F0
#define EQPlayer__dEQPlayer                                        0x4E7780
#define EQPlayer__DoAttack                                         0x4F2630
#define EQPlayer__EQPlayer                                         0x4E9B10
#define EQPlayer__SetNameSpriteState                               0x4E5B50
#define EQPlayer__SetNameSpriteTint                                0x4E3A60

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4EA7D0

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4D10C0
#define KeypressHandler__AttachKeyToEqCommand                      0x4D1100
#define KeypressHandler__ClearCommandStateArray                    0x4D0ED0
#define KeypressHandler__HandleKeyDown                             0x4CFB30
#define KeypressHandler__HandleKeyUp                               0x4CFE30
#define KeypressHandler__SaveKeymapping                            0x4D0FA0

// MapViewMap
#define MapViewMap__Clear                                          0x57C350
#define MapViewMap__SaveEx                                         0x57CD20

// StringTable
#define StringTable__getString                                     0x5DEB30