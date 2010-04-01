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
#define __ExpectedVersionDate                                     "Sep 19 2006"
#define __ExpectedVersionTime                                     "23:46:50"
#define __ActualVersionDate                                        0x6C1394
#define __ActualVersionTime                                        0x6C13A0

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x4E0470
#define __MemChecker1                                              0x5EC210
#define __MemChecker2                                              0x50F500
#define __MemChecker3                                              0x50F5B0
#define __MemChecker4                                              0x5E7490
#define __EncryptPad0                                              0x714748
#define __EncryptPad1                                              0x71DDE8
#define __EncryptPad2                                              0x716C88
#define __EncryptPad3                                              0x717088
#define __EncryptPad4                                              0x71D5E0

// Direct Input
#define DI8__Main                                                  0x904D54
#define DI8__Keyboard                                              0x904D58
#define DI8__Mouse                                                 0x904D5C

#define __AltTimerReady                                            0x8A42D6
#define __Attack                                                   0x90193A
#define __Autofire                                                 0x90193B
#define __BindList                                                 0x70FA18
#define __Clicks                                                   0x8A344C
#define __CommandList                                              0x710208
#define __CurrentMapLabel                                          0x90DDF8
#define __CurrentSocial                                            0x70C4C4
#define __DoAbilityAvailable                                       0x8A4270
#define __DoAbilityList                                            0x8D9480
#define __DrawHandler                                              0x91A264
#define __GroupCount                                               0x883BA8
#define __GroupLeader                                              0x883D04
#define __Guilds                                                   0x885690
#define __gWorld                                                   0x885600
#define __HotkeyPage                                               0x90086C
#define __HWnd                                                     0x904CFC
#define __InChatMode                                               0x8A3388
#define __LastTell                                                 0x8A4B88
#define __Mouse                                                    0x904D60
#define __MouseLook                                                0x8A341A
#define __NetStatusToggle                                          0x8A341C
#define __PCNames                                                  0x8A45E0
#define __RangeAttackReady                                         0x8A42D4
#define __RunWalkState                                             0x8A338C
#define __ScreenMode                                               0x7D3690
#define __ScreenX                                                  0x8A3350
#define __ScreenY                                                  0x8A3354
#define __ServerHost                                               0x883AFC
#define __ServerName                                               0x8D9440
#define __ShowNames                                                0x8A44BC
#define __Socials                                                  0x8D9540

////
//Section 1: Vital Offsets
////
#define instCRaid                                                  0x89D2E0
#define instEQZoneInfo                                             0x8A35B8
#define instKeypressHandler                                        0x901A0C
#define pinstActiveBanker                                          0x885670
#define pinstActiveCorpse                                          0x885674
#define pinstActiveGMaster                                         0x885678
#define pinstActiveMerchant                                        0x88566C
#define pinstAltAdvManager                                         0x7D4360
#define pinstAuraInfo                                              0x722FB0
#define pinstBandageTarget                                         0x885658
#define pinstCamActor                                              0x7D3E54
#define pinstCDBStr                                                0x7D3520
#define pinstCDisplay                                              0x885680
#define pinstCEverQuest                                            0x904EC8
#define pinstCharData                                              0x885640
#define pinstCharSpawn                                             0x885664
#define pinstControlledMissile                                     0x88563C
#define pinstControlledPlayer                                      0x885664
#define pinstCSidlManager                                          0x919AB4
#define pinstCXWndManager                                          0x919AAC
#define pinstDynamicZone                                           0x8A2DA0
#define pinstDZMember                                              0x8A2EB0
#define pinstDZTimerInfo                                           0x8A2EB4
#define pinstEQItemList                                            0x885624
#define instEQMisc                                                 0x7D34D8
#define pinstEQSoundManager                                        0x7D4384
#define instExpeditionLeader                                       0x8A2DEA
#define instExpeditionName                                         0x8A2E2A
#define instGroup                                                  0x883BA8
#define pinstGroup                                                 0x883BA4
#define pinstImeManager                                            0x919AB8
#define pinstLocalPlayer                                           0x885650
#define pinstModelPlayer                                           0x88567C
#define pinstPCData                                                0x885640
#define pinstSelectedItem                                          0x90DC50
#define pinstSkillMgr                                              0x901DA0
#define pinstSpawnManager                                          0x901D1C
#define pinstSpellManager                                          0x901DA4
#define pinstSpellSets                                             0x900870
#define pinstStringTable                                           0x885610
#define pinstSwitchManager                                         0x8837F8
#define pinstTarget                                                0x885668
#define pinstTargetObject                                          0x885644
#define pinstTargetSwitch                                          0x885648
#define pinstTaskMember                                            0x7D34BC
#define pinstTrackTarget                                           0x88565C
#define pinstTradeTarget                                           0x88564C
#define instTributeActive                                          0x7D34FD
#define pinstViewActor                                             0x7D3E50
#define pinstWorldData                                             0x885620


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                          0x7214E8
#define pinstCAudioTriggersWindow                                  0x7214CC
#define pinstCCharacterSelect                                      0x7D3D60
#define pinstCFacePick                                             0x7D3D18
#define pinstCNoteWnd                                              0x7D3D1C
#define pinstCBookWnd                                              0x7D3D20
#define pinstCPetInfoWnd                                           0x7D3D24
#define pinstCTrainWnd                                             0x7D3D28
#define pinstCSkillsWnd                                            0x7D3D2C
#define pinstCSkillsSelectWnd                                      0x7D3D30
#define pinstCCombatSkillSelectWnd                                 0x7D3D34
#define pinstCFriendsWnd                                           0x7D3D38
#define pinstCAuraWnd                                              0x7D3D3C
#define pinstCRespawnWnd                                           0x7D3D40
#define pinstCBandolierWnd                                         0x7D3D44
#define pinstCPotionBeltWnd                                        0x7D3D48
#define pinstCAAWnd                                                0x7D3D4C
#define pinstCGroupSearchFiltersWnd                                0x7D3D50
#define pinstCLoadskinWnd                                          0x7D3D54
#define pinstCAlarmWnd                                             0x7D3D58
#define pinstCMusicPlayerWnd                                       0x7D3D5C
#define pinstCMailWnd                                              0x7D3D64
#define pinstCMailCompositionWnd                                   0x7D3D68
#define pinstCMailAddressBookWnd                                   0x7D3D6C
#define pinstCRaidWnd                                              0x7D3D74
#define pinstCRaidOptionsWnd                                       0x7D3D78
#define pinstCBreathWnd                                            0x7D3D7C
#define pinstCMapViewWnd                                           0x7D3D80
#define pinstCMapToolbarWnd                                        0x7D3D84
#define pinstCEditLabelWnd                                         0x7D3D88
#define pinstCTargetWnd                                            0x7D3D8C
#define pinstCColorPickerWnd                                       0x7D3D90
#define pinstCPlayerWnd                                            0x7D3D94
#define pinstCOptionsWnd                                           0x7D3D98
#define pinstCBuffWindowNORMAL                                     0x7D3D9C
#define pinstCBuffWindowSHORT                                      0x7D3DA0
#define pinstCharacterCreation                                     0x7D3DA4
#define pinstCCursorAttachment                                     0x7D3DA8
#define pinstCCastingWnd                                           0x7D3DAC
#define pinstCCastSpellWnd                                         0x7D3DB0
#define pinstCSpellBookWnd                                         0x7D3DB4
#define pinstCInventoryWnd                                         0x7D3DB8
#define pinstCBankWnd                                              0x7D3DBC
#define pinstCQuantityWnd                                          0x7D3DC0
#define pinstCLootWnd                                              0x7D3DC4
#define pinstCActionsWnd                                           0x7D3DC8
#define pinstCCombatAbilityWnd                                     0x7D3DCC
#define pinstCMerchantWnd                                          0x7D3DD0
#define pinstCTradeWnd                                             0x7D3DD4
#define pinstCSelectorWnd                                          0x7D3DD8
#define pinstCBazaarWnd                                            0x7D3DDC
#define pinstCBazaarSearchWnd                                      0x7D3DE0
#define pinstCGiveWnd                                              0x7D3DE4
#define pinstCTrackingWnd                                          0x7D3DE8
#define pinstCInspectWnd                                           0x7D3DEC
#define pinstCSocialEditWnd                                        0x7D3DF0
#define pinstCFeedbackWnd                                          0x7D3DF4
#define pinstCBugReportWnd                                         0x7D3DF8
#define pinstCVideoModesWnd                                        0x7D3DFC
#define pinstCTextEntryWnd                                         0x7D3E04
#define pinstCFileSelectionWnd                                     0x7D3E08
#define pinstCCompassWnd                                           0x7D3E0C
#define pinstCPlayerNotesWnd                                       0x7D3E10
#define pinstCGemsGameWnd                                          0x7D3E14
#define pinstCTimeLeftWnd                                          0x7D3E18
#define pinstCPetitionQWnd                                         0x7D3E1C
#define pinstCSoulmarkWnd                                          0x7D3E20
#define pinstCStoryWnd                                             0x7D3E24
#define pinstCJournalTextWnd                                       0x7D3E28
#define pinstCJournalCatWnd                                        0x7D3E2C
#define pinstCBodyTintWnd                                          0x7D3E30
#define pinstCServerListWnd                                        0x7D3E34
#define pinstCAvaZoneWnd                                           0x7D3E38
#define pinstCBlockedBuffWnd                                       0x7D3E3C
#define pinstCBlockedPetBuffWnd                                    0x7D3E40
#define pinstCInvSlotMgr                                           0x7D3E44
#define pinstCContainerMgr                                         0x7D3E48
#define pinstCAdventureLeaderboardWnd                              0x90D494
#define pinstCAdventureRequestWnd                                  0x90D4B0
#define pinstCAltStorageWnd                                        0x90D510
#define pinstCAdventureStatsWnd                                    0x90D4CC
#define pinstCBarterMerchantWnd                                    0x90D6C4
#define pinstCBarterSearchWnd                                      0x90D6E0
#define pinstCBarterWnd                                            0x90D6FC
#define pinstCChatManager                                          0x90D8DC
#define pinstCDynamicZoneWnd                                       0x90D9B8
#define pinstCEQMainWnd                                            0x90DA28
#define pinstCFindLocationWnd                                      0x90DAA4
#define pinstCGroupSearchWnd                                       0x90DB78
#define pinstCGroupWnd                                             0x90DB70
#define pinstCGuildBankWnd                                         0x90DB8C
#define pinstCGuildMgmtWnd                                         0x90DBA8
#define pinstCGuildTributeMasterWnd                                0x90DBC4
#define pinstCHotButtonWnd                                         0x90DBE0
#define pinstCHotButtonWnd1                                        0x90DBE0
#define pinstCHotButtonWnd2                                        0x90DBE4
#define pinstCHotButtonWnd3                                        0x90DBE8
#define pinstCHotButtonWnd4                                        0x90DBEC
#define pinstCItemDisplayManager                                   0x90DC84
#define pinstCItemExpTransferWnd                                   0x90DCA4
#define pinstCLeadershipWnd                                        0x90DD20
#define pinstCLFGuildWnd                                           0x90DD3C
#define pinstCMIZoneSelectWnd                                      0x90DE60
#define pinstCAdventureMerchantWnd                                 0x90DF3C
#define pinstCConfirmationDialog                                   0x90DF58
#define pinstCPopupWndManager                                      0x90DF58
#define pinstCProgressionSelectionWnd                              0x90DF8C
#define pinstCPvPLeaderboardWnd                                    0x90DFA8
#define pinstCPvPStatsWnd                                          0x90DFC4
#define pinstCSystemInfoDialogBox                                  0x90E944
#define pinstCTargetOfTargetWnd                                    0x90E960
#define pinstCTaskSelectWnd                                        0x90E994
#define pinstCTaskTemplateSelectWnd                                0x90E9B0
#define pinstCTaskWnd                                              0x90E9CC
#define pinstCTicketCommentWnd                                     0x90EA00
#define pinstCHelpWnd                                              0x90EA1C
#define pinstCTipWndOFDAY                                          0x90EA50
#define pinstCTipWndCONTEXT                                        0x90EA54
#define pinstCTitleWnd                                             0x90EA70
#define pinstCTradeskillWnd                                        0x90EAB4
#define pinstCTributeBenefitWnd                                    0x90EB00
#define pinstCTributeMasterWnd                                     0x90EB1C
#define pinstCContextMenuManager                                   0x919B74
#define pinstCVoiceMacroWnd                                        0x901E6C


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                                  0x4A4F10
#define __ConvertItemTags                                          0x499E30
#define __ExecuteCmd                                               0x48B610
#define __get_melee_range                                          0x4907B0
#define __GetGaugeValueFromEQ                                      0x5BE680
#define __GetLabelFromEQ                                           0x5BEDA0
#define __NewUIINI                                                 0x5BE280
#define __ProcessGameEvents                                        0x4CEDB0
#define __SendMessage                                              0x4B18F0
#define CrashDetected                                              0x50F1B0
#define DrawNetStatus                                              0x4E3140
#define Util__FastTime                                             0x5EC930


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                          0x46C260
#define AltAdvManager__IsAbilityReady                              0x46C2A0
#define AltAdvManager__GetAltAbility                               0x46C460

// CBankWnd
#define CBankWnd__GetNumBankSlots                                  0x523600

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                          0x52CA00

// CButtonWnd
#define CButtonWnd__SetCheck                                       0x631BF0

// CChatManager
#define CChatManager__GetRGBAFromIndex                             0x540090
#define CChatManager__InitContextMenu                              0x540820

// CChatService
#define CChatService__GetNumberOfFriends                      0x60F1C0
#define CChatService__GetFriendName                           0x60F1D0

// CChatWindow
#define CChatWindow__CChatWindow                                   0x544950

// CComboWnd
#define CComboWnd__DeleteAll                                       0x627DA0
#define CComboWnd__Draw                                            0x627F50
#define CComboWnd__GetCurChoice                                    0x627D50
#define CComboWnd__GetListRect                                     0x628220
#define CComboWnd__GetTextRect                                     0x627DD0
#define CComboWnd__InsertChoice                                    0x628290
#define CComboWnd__SetColors                                       0x627CE0
#define CComboWnd__SetChoice                                       0x627D10

// CContainerWnd
#define CContainerWnd__HandleCombine                               0x54AF80
#define CContainerWnd__vftable                                     0x6C7528

// CDisplay
#define CDisplay__CleanGameUI                                      0x45B930
#define CDisplay__GetClickedActor                                  0x459260
#define CDisplay__GetUserDefinedColor                              0x4586D0
#define CDisplay__GetWorldFilePath                                 0x457C80
#define CDisplay__ReloadUI                                         0x467760
#define CDisplay__WriteTextHD2                                     0x45D140

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                                  0x51D7C0
#define CEditBaseWnd__SetSel                                       0x64A160

// CEditWnd
#define CEditWnd__DrawCaret                                        0x6478C5
#define CEditWnd__GetCharIndexPt                                   0x6486E0
#define CEditWnd__GetDisplayString                                 0x647A40
#define CEditWnd__GetHorzOffset                                    0x647CC0
#define CEditWnd__GetLineForPrintableChar                          0x6481A0
#define CEditWnd__GetSelStartPt                                    0x648930
#define CEditWnd__GetSTMLSafeText                                  0x647E60
#define CEditWnd__PointFromPrintableChar                           0x6482B0
#define CEditWnd__SelectableCharFromPoint                          0x648430
#define CEditWnd__SetEditable                                      0x647E30

// CEverQuest
#define CEverQuest__ClickedPlayer                                  0x4B59D0
#define CEverQuest__DropHeldItemOnGround                           0x4BA380
#define CEverQuest__dsp_chat                                       0x4BAF60
#define CEverQuest__EnterZone                                      0x4CD9A0
#define CEverQuest__GetBodyTypeDesc                                0x4B3130
#define CEverQuest__GetClassDesc                                   0x4B2890
#define CEverQuest__GetClassThreeLetterCode                        0x4B2E90
#define CEverQuest__GetDeityDesc                                   0x4B3780
#define CEverQuest__GetLangDesc                                    0x4B34A0
#define CEverQuest__GetRaceDesc                                    0x4B3750
#define CEverQuest__InterpretCmd                                   0x4BB870
#define CEverQuest__LeftClickedOnPlayer                            0x4CC670
#define CEverQuest__RightClickedOnPlayer                           0x4CCA30
#define CEverQuest__SetGameState                                   0x4B5AA0

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                                    0x554450
#define CGaugeWnd__CalcLinesFillRect                               0x5544C0
#define CGaugeWnd__Draw                                            0x554850

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                                 0x568950

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                                   0x56FA30
#define CInvSlotMgr__MoveItem                                      0x56FBD0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x570AC0

// CItemDisplayWnd
#define CItemDisplayWnd__SetItem                                   0x5779A0
#define CItemDisplayWnd__SetSpell                                  0x5BC700

// CLabel
#define CLabel__Draw                                               0x57CE70

// CListWnd
#define CListWnd__AddColumn                                        0x627AF0
#define CListWnd__AddColumn1                                       0x6275E0
#define CListWnd__AddLine                                          0x6271C0
#define CListWnd__AddString                                        0x627390
#define CListWnd__CalculateFirstVisibleLine                        0x6244B0
#define CListWnd__CalculateVSBRange                                0x626150
#define CListWnd__ClearAllSel                                      0x623C00
#define CListWnd__CloseAndUpdateEditWindow                         0x624AF0
#define CListWnd__Compare                                          0x624EA0
#define CListWnd__Draw                                             0x625E40
#define CListWnd__DrawColumnSeparators                             0x625CB0
#define CListWnd__DrawHeader                                       0x623DD0
#define CListWnd__DrawItem                                         0x6255B0
#define CListWnd__DrawLine                                         0x625960
#define CListWnd__DrawSeparator                                    0x625960
#define CListWnd__EnsureVisible                                    0x624500
#define CListWnd__ExtendSel                                        0x6254E0
#define CListWnd__GetColumnMinWidth                                0x6239A0
#define CListWnd__GetColumnWidth                                   0x6238E0
#define CListWnd__GetCurSel                                        0x6233C0
#define CListWnd__GetHeaderRect                                    0x6234B0
#define CListWnd__GetItemAtPoint                                   0x624800
#define CListWnd__GetItemAtPoint1                                  0x624870
#define CListWnd__GetItemData                                      0x623690
#define CListWnd__GetItemHeight                                    0x624240
#define CListWnd__GetItemIcon                                      0x623820
#define CListWnd__GetItemRect                                      0x6245E0
#define CListWnd__GetItemText                                      0x6236D0
#define CListWnd__GetSelList                                       0x6274C0
#define CListWnd__GetSeparatorRect                                 0x624DE0
#define CListWnd__RemoveLine                                       0x627AA0
#define CListWnd__SetColors                                        0x623420
#define CListWnd__SetColumnJustification                           0x623A00
#define CListWnd__SetColumnWidth                                   0x623960
#define CListWnd__SetCurSel                                        0x623400
#define CListWnd__SetItemColor                                     0x626D90
#define CListWnd__SetItemData                                      0x623CA0
#define CListWnd__SetItemText                                      0x626D10
#define CListWnd__ShiftColumnSeparator                             0x625450
#define CListWnd__Sort                                             0x627B20
#define CListWnd__ToggleSel                                        0x623B70

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                                   0x58F220

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x590C20
#define CMerchantWnd__RequestBuyItem                               0x591DA0
#define CMerchantWnd__RequestSellItem                              0x590E80
#define CMerchantWnd__SelectBuySellSlot                            0x591AA0

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1                     0x636710

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                          0x51F170
#define CSidlScreenWnd__CalculateVSBRange                          0x62D270
#define CSidlScreenWnd__ConvertToRes                               0x62D9C0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x62E190
#define CSidlScreenWnd__CSidlScreenWnd1                            0x62F460
#define CSidlScreenWnd__CSidlScreenWnd2                            0x62F510
#define CSidlScreenWnd__dCSidlScreenWnd                            0x62ED10
#define CSidlScreenWnd__DrawSidlPiece                              0x62DEB0
#define CSidlScreenWnd__EnableIniStorage                           0x62D970
#define CSidlScreenWnd__GetSidlPiece                               0x62E070
#define CSidlScreenWnd__Init1                                      0x62F270
#define CSidlScreenWnd__LoadIniInfo                                0x62E240
#define CSidlScreenWnd__LoadIniListWnd                             0x62DB20
#define CSidlScreenWnd__LoadSidlScreen                             0x62DCE0
#define CSidlScreenWnd__StoreIniInfo                               0x62D4B0
#define CSidlScreenWnd__WndNotification                            0x62DE10

// CSkillMgr
#define CSkillMgr__GetSkillCap                                    0x503EF0

// CSliderWnd
#define CSliderWnd__GetValue                                       0x64BF30
#define CSliderWnd__SetValue                                       0x64C030
#define CSliderWnd__SetNumTicks                                    0x64C570

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                                 0x5BB460

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x640B80
#define CStmlWnd__CalculateHSBRange                                0x638F10
#define CStmlWnd__CalculateVSBRange                                0x638EB0
#define CStmlWnd__CanBreakAtCharacter                              0x639050
#define CStmlWnd__CanGoBackward                                    0x639100
#define CStmlWnd__FastForwardToEndOfTag                            0x639B50
#define CStmlWnd__GetNextTagPiece                                  0x639A70
#define CStmlWnd__GetSTMLText                                      0x5448F0
#define CStmlWnd__GetThisChar                                      0x668050
#define CStmlWnd__GetVisiableText                                  0x63AD90
#define CStmlWnd__InitializeWindowVariables                        0x63CEE0
#define CStmlWnd__MakeStmlColorTag                                 0x6385B0
#define CStmlWnd__MakeWndNotificationTag                           0x638650
#define CStmlWnd__StripFirstSTMLLines                              0x640900
#define CStmlWnd__UpdateHistoryString                              0x63B5F0

// CTabWnd
#define CTabWnd__Draw                                              0x64B7D0
#define CTabWnd__DrawCurrentPage                                   0x64B1C0
#define CTabWnd__DrawTab                                           0x64AFA0
#define CTabWnd__GetCurrentPage                                    0x64B440
#define CTabWnd__GetPageClientRect                                 0x64AC70
#define CTabWnd__GetPageFromTabIndex                               0x64AED0
#define CTabWnd__GetPageInnerRect                                  0x64ACD0
#define CTabWnd__GetTabInnerRect                                   0x64AE50
#define CTabWnd__GetTabRect                                        0x64AD60
#define CTabWnd__IndexInBounds                                     0x64AF6D
#define CTabWnd__InsertPage                                        0x64B9F0
#define CTabWnd__SetPage                                           0x64B480
#define CTabWnd__SetPageRect                                       0x64B700
#define CTabWnd__UpdatePage                                        0x64B970

// CTextOverlay
#define CTextOverlay__DisplayText                                  0x412680

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x62F870

// CXMLDataManager
#define CXMLDataManager__GetXMLData                                0x6523E0

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                               0x623150

// CXRect
#define CXRect__CenterPoint                                        0x522DC0

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                               0x412220
#define CXStr__CXStr1                                              0x61E130
#define CXStr__CXStr3                                              0x5EDFE0
#define CXStr__dCXStr                                              0x5BD2A0
#define CXStr__operator_equal1                                     0x5EE1A0
#define CXStr__operator_plus_equal1                                0x5EF090

// CXWnd
#define CXWnd__BringToTop                                          0x628A80
#define CXWnd__Center                                              0x62C040
#define CXWnd__ClrFocus                                            0x6287B0
#define CXWnd__DoAllDrawing                                        0x62CCF0
#define CXWnd__DrawChildren                                        0x62CE20
#define CXWnd__DrawColoredRect                                     0x628CE0
#define CXWnd__DrawTooltip                                         0x62CC20
#define CXWnd__DrawTooltipAtPoint                                  0x62BEA0
#define CXWnd__GetBorderFrame                                      0x629160
#define CXWnd__GetChildWndAt                                       0x62B9C0
#define CXWnd__GetClientClipRect                                   0x6290A0
#define CXWnd__GetFirstChildWnd                                    0x628B10
#define CXWnd__GetNextChildWnd                                     0x62B980
#define CXWnd__GetNextSib                                          0x628B30
#define CXWnd__GetScreenClipRect                                   0x62C260
#define CXWnd__GetScreenRect                                       0x629310
#define CXWnd__GetTooltipRect                                      0x628F20
#define CXWnd__GetWindowTextA                                      0x5169A0
#define CXWnd__IsActive                                            0x642B40
#define CXWnd__IsDescendantOf                                      0x629110
#define CXWnd__IsReallyVisible                                     0x62B960
#define CXWnd__IsType                                              0x64D140
#define CXWnd__Move                                                0x62B4A0
#define CXWnd__Move1                                               0x62B540
#define CXWnd__ProcessTransition                                   0x628A40
#define CXWnd__Refade                                              0x628850
#define CXWnd__Resize                                              0x62C3A0
#define CXWnd__Right                                               0x62C1B0
#define CXWnd__SetFirstChildPointer                                0x629560
#define CXWnd__SetFocus                                            0x62A810
#define CXWnd__SetKeyTooltip                                       0x6295D0
#define CXWnd__SetMouseOver                                        0x6295A0
#define CXWnd__SetNextSibPointer                                   0x629580
#define CXWnd__StartFade                                           0x628AA0

// CXWndManager
#define CXWndManager__DrawCursor                                   0x643F60
#define CXWndManager__DrawWindows                                  0x643C30
#define CXWndManager__GetFirstChildWnd                             0x6434D0
#define CXWndManager__GetKeyboardFlags                             0x642820
#define CXWndManager__HandleKeyboardMsg                            0x642D30
#define CXWndManager__RemoveWnd                                    0x642C50

// CDBStr
#define CDBStr__GetString                                          0x455250

// EQ_Character
#define EQ_Character__CastRay                                      0x673750
#define EQ_Character__CastSpell                                    0x421860
#define EQ_Character__Cur_HP                                       0x428B90
#define EQ_Character__GetAACastingTimeModifier                     0x41C700
#define EQ_Character__GetCharInfo2                                 0x5F7DC0
#define EQ_Character__GetFocusCastingTimeModifier                  0x418EC0
#define EQ_Character__Max_Endurance                                0x427A40
#define EQ_Character__Max_HP                                       0x4278F0
#define EQ_Character__Max_Mana                                     0x4E7FF0
#define EQ_Character__doCombatAbility                              0x4E6E70
#define EQ_Character__UseSkill                                     0x433F40
#define EQ_Character__GetConLevel                                  0x4E44F0

// EQ_Item
#define EQ_Item__CanDrop                                           0x4D9DD0
#define EQ_Item__GetItemLinkHash                                   0x5F6F70
#define EQ_Item__IsStackable                                       0x5F8270

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar                                0x46D350
#define EQ_LoadingS__Array                                         0x70DF30

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                              0x4EAD80
#define EQ_PC__GetAltAbilityIndex                                  0x5FC860
#define EQ_PC__GetCombatAbility                                    0x5FC9A0
#define EQ_PC__GetCombatAbilityTimer                               0x5FCA50
#define EQ_PC__GetItemTimerValue                                   0x4E6270

// EQItemList
#define EQItemList__dEQItemList                                    0x48EFA0
#define EQItemList__EQItemList                                     0x48EEF0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x454CC0

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                           0x4EF6B0
#define EQPlayer__dEQPlayer                                        0x4F3990
#define EQPlayer__DoAttack                                         0x4FED50
#define EQPlayer__EQPlayer                                         0x4F6040
#define EQPlayer__SetNameSpriteState                               0x4F1CA0
#define EQPlayer__SetNameSpriteTint                                0x4EF720
#define EQPlayer__IsBodyType_j                                     0x673500

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4F6E40

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4DBC50
#define KeypressHandler__AttachKeyToEqCommand                      0x4DBC90
#define KeypressHandler__ClearCommandStateArray                    0x4DBA60
#define KeypressHandler__HandleKeyDown                             0x4DA690
#define KeypressHandler__HandleKeyUp                               0x4DA990
#define KeypressHandler__SaveKeymapping                            0x4DBB30

// MapViewMap
#define MapViewMap__Clear                                          0x58B250
#define MapViewMap__SaveEx                                         0x58BC20

// StringTable
#define StringTable__getString                                     0x5F2C70
