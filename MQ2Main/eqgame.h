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
#define __ExpectedVersionDate                                     "Oct  3 2006"
#define __ExpectedVersionTime                                     "16:48:28"
#define __ActualVersionDate                                        0x6C23CC
#define __ActualVersionTime                                        0x6C23D8

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                              0x4E0570
#define __MemChecker1                                              0x5EC500
#define __MemChecker2                                              0x50F5C0
#define __MemChecker3                                              0x50F670
#define __MemChecker4                                              0x5E7810
#define __EncryptPad0                                              0x715748
#define __EncryptPad1                                              0x71EDE8
#define __EncryptPad2                                              0x717C88
#define __EncryptPad3                                              0x718088
#define __EncryptPad4                                              0x71E5E0

// Direct Input
#define DI8__Main                                                  0x905D54
#define DI8__Keyboard                                              0x905D58
#define DI8__Mouse                                                 0x905D5C
#define __AltTimerReady                                            0x8A52D6
#define __Attack                                                   0x90293A
#define __Autofire                                                 0x90293B
#define __BindList                                                 0x710A18
#define __Clicks                                                   0x8A444C
#define __CommandList                                              0x711208
#define __CurrentMapLabel                                          0x90EDF8
#define __CurrentSocial                                            0x70D4C4
#define __DoAbilityAvailable                                       0x8A5270
#define __DoAbilityList                                            0x8DA480
#define __DrawHandler                                              0x91B264
#define __GroupCount                                               0x884BA8
#define __GroupLeader                                              0x884D04
#define __Guilds                                                   0x886690
#define __gWorld                                                   0x886600
#define __HotkeyPage                                               0x90186C
#define __HWnd                                                     0x905CFC
#define __InChatMode                                               0x8A4388
#define __LastTell                                                 0x8A5B88
#define __Mouse                                                    0x905D60
#define __MouseLook                                                0x8A441A
#define __NetStatusToggle                                          0x8A441C
#define __PCNames                                                  0x8A55E0
#define __RangeAttackReady                                         0x8A52D4
#define __RunWalkState                                             0x8A438C
#define __ScreenMode                                               0x7D4690
#define __ScreenX                                                  0x8A4350
#define __ScreenY                                                  0x8A4354
#define __ServerHost                                               0x884AFC
#define __ServerName                                               0x8DA440
#define __ShowNames                                                0x8A54BC
#define __Socials                                                  0x8DA540


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x89E2E0
#define instEQZoneInfo                                             0x8A45B8
#define instKeypressHandler                                        0x902A0C
#define pinstActiveBanker                                          0x886670
#define pinstActiveCorpse                                          0x886674
#define pinstActiveGMaster                                         0x886678
#define pinstActiveMerchant                                        0x88666C
#define pinstAltAdvManager                                         0x7D5360
#define pinstAuraInfo                                              0x723FB0
#define pinstBandageTarget                                         0x886658
#define pinstCamActor                                              0x7D4E54
#define pinstCDBStr                                                0x7D4520
#define pinstCDisplay                                              0x886680
#define pinstCEverQuest                                            0x905EC8
#define pinstCharData                                              0x886640
#define pinstCharSpawn                                             0x886664
#define pinstControlledMissile                                     0x88663C
#define pinstControlledPlayer                                      0x886664
#define pinstCSidlManager                                          0x91AAB4
#define pinstCXWndManager                                          0x91AAAC
#define pinstDynamicZone                                           0x8A3DA0
#define pinstDZMember                                              0x8A3EB0
#define pinstDZTimerInfo                                           0x8A3EB4
#define pinstEQItemList                                            0x886624
#define instEQMisc                                                 0x7D44D8
#define pinstEQSoundManager                                        0x7D5384
#define instExpeditionLeader                                       0x8A3DEA
#define instExpeditionName                                         0x8A3E2A
#define instGroup                                                  0x884BA8
#define pinstGroup                                                 0x884BA4
#define pinstImeManager                                            0x91AAB8
#define pinstLocalPlayer                                           0x886650
#define pinstModelPlayer                                           0x88667C
#define pinstPCData                                                0x886640
#define pinstSelectedItem                                          0x90EC50
#define pinstSkillMgr                                              0x902DA0
#define pinstSpawnManager                                          0x902D1C
#define pinstSpellManager                                          0x902DA4
#define pinstSpellSets                                             0x901870
#define pinstStringTable                                           0x886610
#define pinstSwitchManager                                         0x8847F8
#define pinstTarget                                                0x886668
#define pinstTargetObject                                          0x886644
#define pinstTargetSwitch                                          0x886648
#define pinstTaskMember                                            0x7D44BC
#define pinstTrackTarget                                           0x88665C
#define pinstTradeTarget                                           0x88664C
#define instTributeActive                                          0x7D44FD
#define pinstViewActor                                             0x7D4E50
#define pinstWorldData                                             0x886620


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x7224E8
#define pinstCAudioTriggersWindow                                  0x7224CC
#define pinstCCharacterSelect                                      0x7D4D60
#define pinstCFacePick                                             0x7D4D18
#define pinstCNoteWnd                                              0x7D4D1C
#define pinstCBookWnd                                              0x7D4D20
#define pinstCPetInfoWnd                                           0x7D4D24
#define pinstCTrainWnd                                             0x7D4D28
#define pinstCSkillsWnd                                            0x7D4D2C
#define pinstCSkillsSelectWnd                                      0x7D4D30
#define pinstCCombatSkillSelectWnd                                 0x7D4D34
#define pinstCFriendsWnd                                           0x7D4D38
#define pinstCAuraWnd                                              0x7D4D3C
#define pinstCRespawnWnd                                           0x7D4D40
#define pinstCBandolierWnd                                         0x7D4D44
#define pinstCPotionBeltWnd                                        0x7D4D48
#define pinstCAAWnd                                                0x7D4D4C
#define pinstCGroupSearchFiltersWnd                                0x7D4D50
#define pinstCLoadskinWnd                                          0x7D4D54
#define pinstCAlarmWnd                                             0x7D4D58
#define pinstCMusicPlayerWnd                                       0x7D4D5C
#define pinstCMailWnd                                              0x7D4D64
#define pinstCMailCompositionWnd                                   0x7D4D68
#define pinstCMailAddressBookWnd                                   0x7D4D6C
#define pinstCRaidWnd                                              0x7D4D74
#define pinstCRaidOptionsWnd                                       0x7D4D78
#define pinstCBreathWnd                                            0x7D4D7C
#define pinstCMapViewWnd                                           0x7D4D80
#define pinstCMapToolbarWnd                                        0x7D4D84
#define pinstCEditLabelWnd                                         0x7D4D88
#define pinstCTargetWnd                                            0x7D4D8C
#define pinstCColorPickerWnd                                       0x7D4D90
#define pinstCPlayerWnd                                            0x7D4D94
#define pinstCOptionsWnd                                           0x7D4D98
#define pinstCBuffWindowNORMAL                                     0x7D4D9C
#define pinstCBuffWindowSHORT                                      0x7D4DA0
#define pinstCharacterCreation                                     0x7D4DA4
#define pinstCCursorAttachment                                     0x7D4DA8
#define pinstCCastingWnd                                           0x7D4DAC
#define pinstCCastSpellWnd                                         0x7D4DB0
#define pinstCSpellBookWnd                                         0x7D4DB4
#define pinstCInventoryWnd                                         0x7D4DB8
#define pinstCBankWnd                                              0x7D4DBC
#define pinstCQuantityWnd                                          0x7D4DC0
#define pinstCLootWnd                                              0x7D4DC4
#define pinstCActionsWnd                                           0x7D4DC8
#define pinstCCombatAbilityWnd                                     0x7D4DCC
#define pinstCMerchantWnd                                          0x7D4DD0
#define pinstCTradeWnd                                             0x7D4DD4
#define pinstCSelectorWnd                                          0x7D4DD8
#define pinstCBazaarWnd                                            0x7D4DDC
#define pinstCBazaarSearchWnd                                      0x7D4DE0
#define pinstCGiveWnd                                              0x7D4DE4
#define pinstCTrackingWnd                                          0x7D4DE8
#define pinstCInspectWnd                                           0x7D4DEC
#define pinstCSocialEditWnd                                        0x7D4DF0
#define pinstCFeedbackWnd                                          0x7D4DF4
#define pinstCBugReportWnd                                         0x7D4DF8
#define pinstCVideoModesWnd                                        0x7D4DFC
#define pinstCTextEntryWnd                                         0x7D4E04
#define pinstCFileSelectionWnd                                     0x7D4E08
#define pinstCCompassWnd                                           0x7D4E0C
#define pinstCPlayerNotesWnd                                       0x7D4E10
#define pinstCGemsGameWnd                                          0x7D4E14
#define pinstCTimeLeftWnd                                          0x7D4E18
#define pinstCPetitionQWnd                                         0x7D4E1C
#define pinstCSoulmarkWnd                                          0x7D4E20
#define pinstCStoryWnd                                             0x7D4E24
#define pinstCJournalTextWnd                                       0x7D4E28
#define pinstCJournalCatWnd                                        0x7D4E2C
#define pinstCBodyTintWnd                                          0x7D4E30
#define pinstCServerListWnd                                        0x7D4E34
#define pinstCAvaZoneWnd                                           0x7D4E38
#define pinstCBlockedBuffWnd                                       0x7D4E3C
#define pinstCBlockedPetBuffWnd                                    0x7D4E40
#define pinstCInvSlotMgr                                           0x7D4E44
#define pinstCContainerMgr                                         0x7D4E48
#define pinstCAdventureLeaderboardWnd                              0x90E494
#define pinstCAdventureRequestWnd                                  0x90E4B0
#define pinstCAltStorageWnd                                        0x90E510
#define pinstCAdventureStatsWnd                                    0x90E4CC
#define pinstCBarterMerchantWnd                                    0x90E6C4
#define pinstCBarterSearchWnd                                      0x90E6E0
#define pinstCBarterWnd                                            0x90E6FC
#define pinstCChatManager                                          0x90E8DC
#define pinstCDynamicZoneWnd                                       0x90E9B8
#define pinstCEQMainWnd                                            0x90EA28
#define pinstCFindLocationWnd                                      0x90EAA4
#define pinstCGroupSearchWnd                                       0x90EB78
#define pinstCGroupWnd                                             0x90EB70
#define pinstCGuildBankWnd                                         0x90EB8C
#define pinstCGuildMgmtWnd                                         0x90EBA8
#define pinstCGuildTributeMasterWnd                                0x90EBC4
#define pinstCHotButtonWnd                                         0x90EBE0
#define pinstCHotButtonWnd1                                        0x90EBE0
#define pinstCHotButtonWnd2                                        0x90EBE4
#define pinstCHotButtonWnd3                                        0x90EBE8
#define pinstCHotButtonWnd4                                        0x90EBEC
#define pinstCItemDisplayManager                                   0x90EC84
#define pinstCItemExpTransferWnd                                   0x90ECA4
#define pinstCLeadershipWnd                                        0x90ED20
#define pinstCLFGuildWnd                                           0x90ED3C
#define pinstCMIZoneSelectWnd                                      0x90EE60
#define pinstCAdventureMerchantWnd                                 0x90EF3C
#define pinstCConfirmationDialog                                   0x90EF58
#define pinstCPopupWndManager                                      0x90EF58
#define pinstCProgressionSelectionWnd                              0x90EF8C
#define pinstCPvPLeaderboardWnd                                    0x90EFA8
#define pinstCPvPStatsWnd                                          0x90EFC4
#define pinstCSystemInfoDialogBox                                  0x90F944
#define pinstCTargetOfTargetWnd                                    0x90F960
#define pinstCTaskSelectWnd                                        0x90F994
#define pinstCTaskTemplateSelectWnd                                0x90F9B0
#define pinstCTaskWnd                                              0x90F9CC
#define pinstCTicketCommentWnd                                     0x90FA00
#define pinstCHelpWnd                                              0x90FA1C
#define pinstCTipWndOFDAY                                          0x90FA50
#define pinstCTipWndCONTEXT                                        0x90FA54
#define pinstCTitleWnd                                             0x90FA70
#define pinstCTradeskillWnd                                        0x90FAB4
#define pinstCTributeBenefitWnd                                    0x90FB00
#define pinstCTributeMasterWnd                                     0x90FB1C
#define pinstCContextMenuManager                                   0x91AB74
#define pinstCVoiceMacroWnd                                        0x902E6C


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4A4FC0
#define __ConvertItemTags                                          0x499EE0
#define __ExecuteCmd                                               0x48B6A0
#define __get_melee_range                                          0x490840
#define __GetGaugeValueFromEQ                                      0x5BE900
#define __GetLabelFromEQ                                           0x5BF030
#define __NewUIINI                                                 0x5BE500
#define __ProcessGameEvents                                        0x4CEEF0
#define __SendMessage                                              0x4B1A70
#define CrashDetected                                              0x50F270
#define DrawNetStatus                                              0x4E3280
#define Util__FastTime                                             0x5ECBE0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x46C1F0
#define AltAdvManager__IsAbilityReady                              0x46C230
#define AltAdvManager__GetAltAbility                               0x46C3C0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x523610

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x52CA60

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6321D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5400D0
#define CChatManager__InitContextMenu                              0x540860

// CChatService
#define CChatService__GetNumberOfFriends                           0x60F5B0
#define CChatService__GetFriendName                                0x60F5C0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x544990

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6282E0
#define CComboWnd__Draw                                            0x628490
#define CComboWnd__GetCurChoice                                    0x628290
#define CComboWnd__GetListRect                                     0x628760
#define CComboWnd__GetTextRect                                     0x628310
#define CComboWnd__InsertChoice                                    0x6287D0
#define CComboWnd__SetColors                                       0x628220
#define CComboWnd__SetChoice                                       0x628250

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x54AFF0
#define CContainerWnd__vftable                                     0x6C8560

// CDisplay 
#define CDisplay__CleanGameUI                                      0x45B8C0
#define CDisplay__GetClickedActor                                  0x4591E0
#define CDisplay__GetUserDefinedColor                              0x458650
#define CDisplay__GetWorldFilePath                                 0x457C00
#define CDisplay__ReloadUI                                         0x4676D0
#define CDisplay__WriteTextHD2                                     0x45D0D0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x51D8B0
#define CEditBaseWnd__SetSel                                       0x64A770

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x647ED5
#define CEditWnd__GetCharIndexPt                                   0x648CF0
#define CEditWnd__GetDisplayString                                 0x648050
#define CEditWnd__GetHorzOffset                                    0x6482D0
#define CEditWnd__GetLineForPrintableChar                          0x6487B0
#define CEditWnd__GetSelStartPt                                    0x648F40
#define CEditWnd__GetSTMLSafeText                                  0x648470
#define CEditWnd__PointFromPrintableChar                           0x6488C0
#define CEditWnd__SelectableCharFromPoint                          0x648A40
#define CEditWnd__SetEditable                                      0x648440

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4B5B00
#define CEverQuest__DropHeldItemOnGround                           0x4BA4A0
#define CEverQuest__dsp_chat                                       0x4BB080
#define CEverQuest__EnterZone                                      0x4CDAE0
#define CEverQuest__GetBodyTypeDesc                                0x4B3260
#define CEverQuest__GetClassDesc                                   0x4B29C0
#define CEverQuest__GetClassThreeLetterCode                        0x4B2FC0
#define CEverQuest__GetDeityDesc                                   0x4B38B0
#define CEverQuest__GetLangDesc                                    0x4B35D0
#define CEverQuest__GetRaceDesc                                    0x4B3880
#define CEverQuest__InterpretCmd                                   0x4BB990
#define CEverQuest__LeftClickedOnPlayer                            0x4CC7B0
#define CEverQuest__RightClickedOnPlayer                           0x4CCB70
#define CEverQuest__SetGameState                                   0x4B5BD0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5544E0
#define CGaugeWnd__CalcLinesFillRect                               0x554550
#define CGaugeWnd__Draw                                            0x5548E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x568980

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x56FA40
#define CInvSlotMgr__MoveItem                                      0x56FBE0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x570AD0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5779F0
#define CItemDisplayWnd__SetSpell                                  0x5BC920

// CLabel 
#define CLabel__Draw                                               0x57CEB0

// CListWnd 
#define CListWnd__AddColumn                                        0x628030
#define CListWnd__AddColumn1                                       0x627B20
#define CListWnd__AddLine                                          0x627700
#define CListWnd__AddString                                        0x6278D0
#define CListWnd__CalculateFirstVisibleLine                        0x6249F0
#define CListWnd__CalculateVSBRange                                0x626690
#define CListWnd__ClearAllSel                                      0x624140
#define CListWnd__CloseAndUpdateEditWindow                         0x625030
#define CListWnd__Compare                                          0x6253E0
#define CListWnd__Draw                                             0x626380
#define CListWnd__DrawColumnSeparators                             0x6261F0
#define CListWnd__DrawHeader                                       0x624310
#define CListWnd__DrawItem                                         0x625AF0
#define CListWnd__DrawLine                                         0x625EA0
#define CListWnd__DrawSeparator                                    0x625EA0
#define CListWnd__EnsureVisible                                    0x624A40
#define CListWnd__ExtendSel                                        0x625A20
#define CListWnd__GetColumnMinWidth                                0x623EE0
#define CListWnd__GetColumnWidth                                   0x623E20
#define CListWnd__GetCurSel                                        0x6238E0
#define CListWnd__GetHeaderRect                                    0x6239F0
#define CListWnd__GetItemAtPoint                                   0x624D40
#define CListWnd__GetItemAtPoint1                                  0x624DB0
#define CListWnd__GetItemData                                      0x623BD0
#define CListWnd__GetItemHeight                                    0x624780
#define CListWnd__GetItemIcon                                      0x623D60
#define CListWnd__GetItemRect                                      0x624B20
#define CListWnd__GetItemText                                      0x623C10
#define CListWnd__GetSelList                                       0x627A00
#define CListWnd__GetSeparatorRect                                 0x625320
#define CListWnd__RemoveLine                                       0x627FE0
#define CListWnd__SetColors                                        0x623960
#define CListWnd__SetColumnJustification                           0x623F40
#define CListWnd__SetColumnWidth                                   0x623EA0
#define CListWnd__SetCurSel                                        0x623920
#define CListWnd__SetItemColor                                     0x6272D0
#define CListWnd__SetItemData                                      0x6241E0
#define CListWnd__SetItemText                                      0x627250
#define CListWnd__ShiftColumnSeparator                             0x625990
#define CListWnd__Sort                                             0x628060
#define CListWnd__ToggleSel                                        0x6240B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x58F490

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x590E60
#define CMerchantWnd__RequestBuyItem                               0x591FE0
#define CMerchantWnd__RequestSellItem                              0x5910C0
#define CMerchantWnd__SelectBuySellSlot                            0x591CE0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x636D60

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x62D870
#define CSidlScreenWnd__CalculateVSBRange                          0x62D7B0
#define CSidlScreenWnd__ConvertToRes                               0x62DFB0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x62E780
#define CSidlScreenWnd__CSidlScreenWnd1                            0x62FA50
#define CSidlScreenWnd__CSidlScreenWnd2                            0x62FB00
#define CSidlScreenWnd__dCSidlScreenWnd                            0x62F300
#define CSidlScreenWnd__DrawSidlPiece                              0x62E4A0
#define CSidlScreenWnd__EnableIniStorage                           0x62DF60
#define CSidlScreenWnd__GetSidlPiece                               0x62E660
#define CSidlScreenWnd__Init1                                      0x62F860
#define CSidlScreenWnd__LoadIniInfo                                0x62E830
#define CSidlScreenWnd__LoadIniListWnd                             0x62E110
#define CSidlScreenWnd__LoadSidlScreen                             0x62E2D0
#define CSidlScreenWnd__StoreIniInfo                               0x62DAA0
#define CSidlScreenWnd__WndNotification                            0x62E400

// CSkillMgr
#define CSkillMgr__GetSkillCap                                    0x5040A0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x64C540
#define CSliderWnd__SetValue                                       0x64C640
#define CSliderWnd__SetNumTicks                                    0x64CB80

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5BB680

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6411A0
#define CStmlWnd__CalculateHSBRange                                0x639550
#define CStmlWnd__CalculateVSBRange                                0x6394F0
#define CStmlWnd__CanBreakAtCharacter                              0x639690
#define CStmlWnd__CanGoBackward                                    0x639740
#define CStmlWnd__FastForwardToEndOfTag                            0x63A190
#define CStmlWnd__GetNextTagPiece                                  0x63A0B0
#define CStmlWnd__GetSTMLText                                      0x544930
#define CStmlWnd__GetThisChar                                      0x668640
#define CStmlWnd__GetVisiableText                                  0x63B3B0
#define CStmlWnd__InitializeWindowVariables                        0x63D500
#define CStmlWnd__MakeStmlColorTag                                 0x638BF0
#define CStmlWnd__MakeWndNotificationTag                           0x638C90
#define CStmlWnd__StripFirstSTMLLines                              0x640F20
#define CStmlWnd__UpdateHistoryString                              0x63BC10

// CTabWnd 
#define CTabWnd__Draw                                              0x64BDE0
#define CTabWnd__DrawCurrentPage                                   0x64B7D0
#define CTabWnd__DrawTab                                           0x64B5B0
#define CTabWnd__GetCurrentPage                                    0x64BA50
#define CTabWnd__GetPageClientRect                                 0x64B280
#define CTabWnd__GetPageFromTabIndex                               0x64B4E0
#define CTabWnd__GetPageInnerRect                                  0x64B2E0
#define CTabWnd__GetTabInnerRect                                   0x64B460
#define CTabWnd__GetTabRect                                        0x64B370
#define CTabWnd__IndexInBounds                                     0x64B57D
#define CTabWnd__InsertPage                                        0x64C000
#define CTabWnd__SetPage                                           0x64BA90
#define CTabWnd__SetPageRect                                       0x64BD10
#define CTabWnd__UpdatePage                                        0x64BF80

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x412490

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x62FE60

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x652A60

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x623670

// CXRect 
#define CXRect__CenterPoint                                        0x522DD0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x412030
#define CXStr__CXStr1                                              0x61CD80
#define CXStr__CXStr3                                              0x5EE290
#define CXStr__dCXStr                                              0x406560
#define CXStr__operator_equal1                                     0x5EE450
#define CXStr__operator_plus_equal1                                0x5EF340

// CXWnd 
#define CXWnd__BringToTop                                          0x628FC0
#define CXWnd__Center                                              0x62C580
#define CXWnd__ClrFocus                                            0x628CF0
#define CXWnd__DoAllDrawing                                        0x62D230
#define CXWnd__DrawChildren                                        0x62D360
#define CXWnd__DrawColoredRect                                     0x629220
#define CXWnd__DrawTooltip                                         0x62D160
#define CXWnd__DrawTooltipAtPoint                                  0x62C3E0
#define CXWnd__GetBorderFrame                                      0x6296A0
#define CXWnd__GetChildWndAt                                       0x62BF00
#define CXWnd__GetClientClipRect                                   0x6295E0
#define CXWnd__GetFirstChildWnd                                    0x629050
#define CXWnd__GetNextChildWnd                                     0x62BEC0
#define CXWnd__GetNextSib                                          0x629070
#define CXWnd__GetScreenClipRect                                   0x62C7A0
#define CXWnd__GetScreenRect                                       0x629850
#define CXWnd__GetTooltipRect                                      0x629460
#define CXWnd__GetWindowTextA                                      0x516A60
#define CXWnd__IsActive                                            0x643160
#define CXWnd__IsDescendantOf                                      0x629650
#define CXWnd__IsReallyVisible                                     0x62BEA0
#define CXWnd__IsType                                              0x64D7A0
#define CXWnd__Move                                                0x62B9E0
#define CXWnd__Move1                                               0x62BA80
#define CXWnd__ProcessTransition                                   0x628F80
#define CXWnd__Refade                                              0x628D90
#define CXWnd__Resize                                              0x62C8E0
#define CXWnd__Right                                               0x62C6F0
#define CXWnd__SetFirstChildPointer                                0x629AA0
#define CXWnd__SetFocus                                            0x62AD50
#define CXWnd__SetKeyTooltip                                       0x629B10
#define CXWnd__SetMouseOver                                        0x629AE0
#define CXWnd__SetNextSibPointer                                   0x629AC0
#define CXWnd__StartFade                                           0x628FE0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x644580
#define CXWndManager__DrawWindows                                  0x644250
#define CXWndManager__GetFirstChildWnd                             0x643AF0
#define CXWndManager__GetKeyboardFlags                             0x642E40
#define CXWndManager__HandleKeyboardMsg                            0x643350
#define CXWndManager__RemoveWnd                                    0x643270

// CDBStr
#define CDBStr__GetString                                          0x4551B0

// EQ_Character 
#define EQ_Character__CastRay                                      0x673C90
#define EQ_Character__CastSpell                                    0x421660
#define EQ_Character__Cur_HP                                       0x428980
#define EQ_Character__GetAACastingTimeModifier                     0x41C550
#define EQ_Character__GetCharInfo2                                 0x5F81E0
#define EQ_Character__GetFocusCastingTimeModifier                  0x418C90
#define EQ_Character__Max_Endurance                                0x427830
#define EQ_Character__Max_HP                                       0x4276E0
#define EQ_Character__Max_Mana                                     0x4E8150
#define EQ_Character__doCombatAbility                              0x4E6FD0
#define EQ_Character__UseSkill                                     0x433D40
#define EQ_Character__GetConLevel                                  0x4E4630

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4D9F10
#define EQ_Item__GetItemLinkHash                                   0x5F7390
#define EQ_Item__IsStackable                                       0x5F86A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x46D2B0
#define EQ_LoadingS__Array                                         0x70EF30

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x4EAEE0
#define EQ_PC__GetAltAbilityIndex                                  0x5FCE30
#define EQ_PC__GetCombatAbility                                    0x5FCF70
#define EQ_PC__GetCombatAbilityTimer                               0x5FD020
#define EQ_PC__GetItemTimerValue                                   0x4E63D0

// EQItemList 
#define EQItemList__dEQItemList                                    0x48F030
#define EQItemList__EQItemList                                     0x48EF80

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x454C20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x4EF800
#define EQPlayer__dEQPlayer                                        0x4F3AF0
#define EQPlayer__DoAttack                                         0x4FEE90
#define EQPlayer__EQPlayer                                         0x4F61A0
#define EQPlayer__SetNameSpriteState                               0x4F1E00
#define EQPlayer__SetNameSpriteTint                                0x4EF870
#define EQPlayer__IsBodyType_j                                     0x673A40

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4F6FA0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4DBD90
#define KeypressHandler__AttachKeyToEqCommand                      0x4DBDD0
#define KeypressHandler__ClearCommandStateArray                    0x4DBBA0
#define KeypressHandler__HandleKeyDown                             0x4DA7D0
#define KeypressHandler__HandleKeyUp                               0x4DAAD0
#define KeypressHandler__SaveKeymapping                            0x4DBC70

// MapViewMap 
#define MapViewMap__Clear                                          0x58B4D0
#define MapViewMap__SaveEx                                         0x58BEA0

// StringTable 
#define StringTable__getString                                     0x5F3090
