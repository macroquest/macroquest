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
#define __ExpectedVersionDate                                     "Oct 23 2006"
#define __ExpectedVersionTime                                     "17:34:12"
#define __ActualVersionDate                                        0x6C2524
#define __ActualVersionTime                                        0x6C2530

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                              0x4E04D0
#define __MemChecker1                                              0x5EC9A0
#define __MemChecker2                                              0x50F790
#define __MemChecker3                                              0x50F840
#define __MemChecker4                                              0x5E7C60
#define __EncryptPad0                                              0x715748
#define __EncryptPad1                                              0x71EDE8
#define __EncryptPad2                                              0x717C88
#define __EncryptPad3                                              0x718088
#define __EncryptPad4                                              0x71E5E0

// Direct Input
#define DI8__Main                                                  0x9090A4
#define DI8__Keyboard                                              0x9090A8
#define DI8__Mouse                                                 0x9090AC
#define __AltTimerReady                                            0x8A52D6
#define __Attack                                                   0x90293A
#define __Autofire                                                 0x90293B
#define __BindList                                                 0x710A18
#define __Clicks                                                   0x8A444C
#define __CommandList                                              0x711208
#define __CurrentMapLabel                                          0x912148
#define __CurrentSocial                                            0x70D4C4
#define __DoAbilityAvailable                                       0x8A5270
#define __DoAbilityList                                            0x8DA480
#define __DrawHandler                                              0x91E5B4
#define __GroupCount                                               0x884BA8
#define __GroupLeader                                              0x884D04
#define __Guilds                                                   0x886690
#define __gWorld                                                   0x886600
#define __HotkeyPage                                               0x90186C
#define __HWnd                                                     0x90904C
#define __InChatMode                                               0x8A4388
#define __LastTell                                                 0x8A5B88
#define __Mouse                                                    0x9090B0
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
#define pinstCEverQuest                                            0x909218
#define pinstCharData                                              0x886640
#define pinstCharSpawn                                             0x886664
#define pinstControlledMissile                                     0x88663C
#define pinstControlledPlayer                                      0x886664
#define pinstCSidlManager                                          0x91DE04
#define pinstCXWndManager                                          0x91DDFC
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
#define pinstImeManager                                            0x91DE08
#define pinstLocalPlayer                                           0x886650
#define pinstModelPlayer                                           0x88667C
#define pinstPCData                                                0x886640
#define pinstSelectedItem                                          0x911FA0
#define pinstSkillMgr                                              0x9060F0
#define pinstSpawnManager                                          0x90606C
#define pinstSpellManager                                          0x9060F4
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
#define pinstCAdventureLeaderboardWnd                              0x9117E4
#define pinstCAdventureRequestWnd                                  0x911800
#define pinstCAltStorageWnd                                        0x911860
#define pinstCAdventureStatsWnd                                    0x91181C
#define pinstCBarterMerchantWnd                                    0x911A14
#define pinstCBarterSearchWnd                                      0x911A30
#define pinstCBarterWnd                                            0x911A4C
#define pinstCChatManager                                          0x911C2C
#define pinstCDynamicZoneWnd                                       0x911D08
#define pinstCEQMainWnd                                            0x911D78
#define pinstCFindLocationWnd                                      0x911DF4
#define pinstCGroupSearchWnd                                       0x911EC8
#define pinstCGroupWnd                                             0x911EC0
#define pinstCGuildBankWnd                                         0x911EDC
#define pinstCGuildMgmtWnd                                         0x911EF8
#define pinstCGuildTributeMasterWnd                                0x911F14
#define pinstCHotButtonWnd                                         0x911F30
#define pinstCHotButtonWnd1                                        0x911F30
#define pinstCHotButtonWnd2                                        0x911F34
#define pinstCHotButtonWnd3                                        0x911F38
#define pinstCHotButtonWnd4                                        0x911F3C
#define pinstCItemDisplayManager                                   0x911FD4
#define pinstCItemExpTransferWnd                                   0x911FF4
#define pinstCLeadershipWnd                                        0x912070
#define pinstCLFGuildWnd                                           0x91208C
#define pinstCMIZoneSelectWnd                                      0x9121B0
#define pinstCAdventureMerchantWnd                                 0x91228C
#define pinstCConfirmationDialog                                   0x9122A8
#define pinstCPopupWndManager                                      0x9122A8
#define pinstCProgressionSelectionWnd                              0x9122DC
#define pinstCPvPLeaderboardWnd                                    0x9122F8
#define pinstCPvPStatsWnd                                          0x912314
#define pinstCSystemInfoDialogBox                                  0x912C94
#define pinstCTargetOfTargetWnd                                    0x912CB0
#define pinstCTaskSelectWnd                                        0x912CE4
#define pinstCTaskTemplateSelectWnd                                0x912D00
#define pinstCTaskWnd                                              0x912D1C
#define pinstCTicketCommentWnd                                     0x912D50
#define pinstCHelpWnd                                              0x912D6C
#define pinstCTipWndOFDAY                                          0x912DA0
#define pinstCTipWndCONTEXT                                        0x912DA4
#define pinstCTitleWnd                                             0x912DC0
#define pinstCTradeskillWnd                                        0x912E04
#define pinstCTributeBenefitWnd                                    0x912E50
#define pinstCTributeMasterWnd                                     0x912E6C
#define pinstCContextMenuManager                                   0x91DEC4
#define pinstCVoiceMacroWnd                                        0x9061BC


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4A4FE0
#define __ConvertItemTags                                          0x499C90
#define __ExecuteCmd                                               0x48B510
#define __get_melee_range                                          0x4906A0
#define __GetGaugeValueFromEQ                                      0x5BED20
#define __GetLabelFromEQ                                           0x5BF450
#define __NewUIINI                                                 0x5BE920
#define __ProcessGameEvents                                        0x4CEE20
#define __SendMessage                                              0x4B1990
#define CrashDetected                                              0x50F440
#define DrawNetStatus                                              0x4E31A0
#define Util__FastTime                                             0x5ED080


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x46C0C0
#define AltAdvManager__IsAbilityReady                              0x46C100
#define AltAdvManager__GetAltAbility                               0x46C290

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5237E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x52CC40

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x632750

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5403A0
#define CChatManager__InitContextMenu                              0x540B30

// CChatService
#define CChatService__GetNumberOfFriends                           0x60FB20
#define CChatService__GetFriendName                                0x60FB30

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x544C60

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x628840
#define CComboWnd__Draw                                            0x6289F0
#define CComboWnd__GetCurChoice                                    0x6287F0
#define CComboWnd__GetListRect                                     0x628CC0
#define CComboWnd__GetTextRect                                     0x628870
#define CComboWnd__InsertChoice                                    0x628D30
#define CComboWnd__SetColors                                       0x628780
#define CComboWnd__SetChoice                                       0x6287B0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x54B2C0
#define CContainerWnd__vftable                                     0x6C86B8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x45B7A0
#define CDisplay__GetClickedActor                                  0x4590D0
#define CDisplay__GetUserDefinedColor                              0x458540
#define CDisplay__GetWorldFilePath                                 0x457AF0
#define CDisplay__ReloadUI                                         0x467580
#define CDisplay__WriteTextHD2                                     0x45CFB0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x51DA80
#define CEditBaseWnd__SetSel                                       0x64AE00

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x648550
#define CEditWnd__GetCharIndexPt                                   0x649380
#define CEditWnd__GetDisplayString                                 0x6486E0
#define CEditWnd__GetHorzOffset                                    0x648960
#define CEditWnd__GetLineForPrintableChar                          0x648E40
#define CEditWnd__GetSelStartPt                                    0x6495D0
#define CEditWnd__GetSTMLSafeText                                  0x648B00
#define CEditWnd__PointFromPrintableChar                           0x648F50
#define CEditWnd__SelectableCharFromPoint                          0x6490D0
#define CEditWnd__SetEditable                                      0x648AD0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4B5A30
#define CEverQuest__DropHeldItemOnGround                           0x4BA3D0
#define CEverQuest__dsp_chat                                       0x4BAFB0
#define CEverQuest__EnterZone                                      0x4CDA10
#define CEverQuest__GetBodyTypeDesc                                0x4B3190
#define CEverQuest__GetClassDesc                                   0x4B28F0
#define CEverQuest__GetClassThreeLetterCode                        0x4B2EF0
#define CEverQuest__GetDeityDesc                                   0x4B37E0
#define CEverQuest__GetLangDesc                                    0x4B3500
#define CEverQuest__GetRaceDesc                                    0x4B37B0
#define CEverQuest__InterpretCmd                                   0x4BB8C0
#define CEverQuest__LeftClickedOnPlayer                            0x4CC6E0
#define CEverQuest__RightClickedOnPlayer                           0x4CCAA0
#define CEverQuest__SetGameState                                   0x4B5B00

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5547E0
#define CGaugeWnd__CalcLinesFillRect                               0x554850
#define CGaugeWnd__Draw                                            0x554BE0

// CGuild
#define CGuild__FindMemberByName                                   0x415550

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x568D40

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x56FE30
#define CInvSlotMgr__MoveItem                                      0x56FFD0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x570EC0

// CInvSLot
#define CInvSlot__SliderComplete                                   0x56EE70

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x577DD0
#define CItemDisplayWnd__SetSpell                                  0x5BCD30

// CLabel 
#define CLabel__Draw                                               0x57D290

// CListWnd 
#define CListWnd__AddColumn                                        0x628590
#define CListWnd__AddColumn1                                       0x628080
#define CListWnd__AddLine                                          0x627C60
#define CListWnd__AddString                                        0x627E30
#define CListWnd__CalculateFirstVisibleLine                        0x624F50
#define CListWnd__CalculateVSBRange                                0x626BF0
#define CListWnd__ClearAllSel                                      0x6246A0
#define CListWnd__CloseAndUpdateEditWindow                         0x625590
#define CListWnd__Compare                                          0x625940
#define CListWnd__Draw                                             0x6268E0
#define CListWnd__DrawColumnSeparators                             0x626750
#define CListWnd__DrawHeader                                       0x624870
#define CListWnd__DrawItem                                         0x626050
#define CListWnd__DrawLine                                         0x626400
#define CListWnd__DrawSeparator                                    0x626400
#define CListWnd__EnsureVisible                                    0x624FA0
#define CListWnd__ExtendSel                                        0x625F80
#define CListWnd__GetColumnMinWidth                                0x624440
#define CListWnd__GetColumnWidth                                   0x624380
#define CListWnd__GetCurSel                                        0x623E60
#define CListWnd__GetHeaderRect                                    0x623F50
#define CListWnd__GetItemAtPoint                                   0x6252A0
#define CListWnd__GetItemAtPoint1                                  0x625310
#define CListWnd__GetItemData                                      0x624130
#define CListWnd__GetItemHeight                                    0x624CE0
#define CListWnd__GetItemIcon                                      0x6242C0
#define CListWnd__GetItemRect                                      0x625080
#define CListWnd__GetItemText                                      0x624170
#define CListWnd__GetSelList                                       0x627F60
#define CListWnd__GetSeparatorRect                                 0x625880
#define CListWnd__RemoveLine                                       0x628540
#define CListWnd__SetColors                                        0x623EC0
#define CListWnd__SetColumnJustification                           0x6244A0
#define CListWnd__SetColumnWidth                                   0x624400
#define CListWnd__SetCurSel                                        0x623EA0
#define CListWnd__SetItemColor                                     0x627830
#define CListWnd__SetItemData                                      0x624740
#define CListWnd__SetItemText                                      0x6277B0
#define CListWnd__ShiftColumnSeparator                             0x625EF0
#define CListWnd__Sort                                             0x6285C0
#define CListWnd__ToggleSel                                        0x624610

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x58F870

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x591240
#define CMerchantWnd__RequestBuyItem                               0x5923C0
#define CMerchantWnd__RequestSellItem                              0x5914A0
#define CMerchantWnd__SelectBuySellSlot                            0x5920C0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x637350

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x62DD20
#define CSidlScreenWnd__CalculateVSBRange                          0x51F400
#define CSidlScreenWnd__ConvertToRes                               0x62E460
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x62EC30
#define CSidlScreenWnd__CSidlScreenWnd1                            0x62FF00
#define CSidlScreenWnd__CSidlScreenWnd2                            0x62FFB0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x62F7B0
#define CSidlScreenWnd__DrawSidlPiece                              0x62E950
#define CSidlScreenWnd__EnableIniStorage                           0x62E410
#define CSidlScreenWnd__GetSidlPiece                               0x62EB10
#define CSidlScreenWnd__Init1                                      0x62FD10
#define CSidlScreenWnd__LoadIniInfo                                0x62ECE0
#define CSidlScreenWnd__LoadIniListWnd                             0x62E5C0
#define CSidlScreenWnd__LoadSidlScreen                             0x62E780
#define CSidlScreenWnd__StoreIniInfo                               0x62DF50
#define CSidlScreenWnd__WndNotification                            0x62E8B0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                    0x5041A0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x64CBE0
#define CSliderWnd__SetValue                                       0x64CCE0
#define CSliderWnd__SetNumTicks                                    0x64D220

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5BBA90

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x641840
#define CStmlWnd__CalculateHSBRange                                0x639B80
#define CStmlWnd__CalculateVSBRange                                0x639B20
#define CStmlWnd__CanBreakAtCharacter                              0x639CC0
#define CStmlWnd__CanGoBackward                                    0x639D70
#define CStmlWnd__FastForwardToEndOfTag                            0x63A810
#define CStmlWnd__GetNextTagPiece                                  0x63A730
#define CStmlWnd__GetSTMLText                                      0x544C00
#define CStmlWnd__GetThisChar                                      0x668CF0
#define CStmlWnd__GetVisiableText                                  0x63BA50
#define CStmlWnd__InitializeWindowVariables                        0x63DBA0
#define CStmlWnd__MakeStmlColorTag                                 0x639200
#define CStmlWnd__MakeWndNotificationTag                           0x6392A0
#define CStmlWnd__StripFirstSTMLLines                              0x6415C0
#define CStmlWnd__UpdateHistoryString                              0x63C2B0

// CTabWnd 
#define CTabWnd__Draw                                              0x64C470
#define CTabWnd__DrawCurrentPage                                   0x64BE60
#define CTabWnd__DrawTab                                           0x64BC40
#define CTabWnd__GetCurrentPage                                    0x64C0E0
#define CTabWnd__GetPageClientRect                                 0x64B910
#define CTabWnd__GetPageFromTabIndex                               0x64BB70
#define CTabWnd__GetPageInnerRect                                  0x64B970
#define CTabWnd__GetTabInnerRect                                   0x64BAF0
#define CTabWnd__GetTabRect                                        0x64BA00
#define CTabWnd__IndexInBounds                                     0x64BC0D
#define CTabWnd__InsertPage                                        0x64C690
#define CTabWnd__SetPage                                           0x64C120
#define CTabWnd__SetPageRect                                       0x64C3A0
#define CTabWnd__UpdatePage                                        0x64C610

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x412320

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x630310

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6530C0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x623BF0

// CXRect 
#define CXRect__CenterPoint                                        0x522FA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x411EC0
#define CXStr__CXStr1                                              0x595410
#define CXStr__CXStr3                                              0x5EE780
#define CXStr__dCXStr                                              0x5BD960
#define CXStr__operator_equal1                                     0x5EE940
#define CXStr__operator_plus_equal1                                0x5EF830

// CXWnd 
#define CXWnd__BringToTop                                          0x629530
#define CXWnd__Center                                              0x62CAF0
#define CXWnd__ClrFocus                                            0x629250
#define CXWnd__DoAllDrawing                                        0x62D7A0
#define CXWnd__DrawChildren                                        0x62D8D0
#define CXWnd__DrawColoredRect                                     0x629790
#define CXWnd__DrawTooltip                                         0x62D6D0
#define CXWnd__DrawTooltipAtPoint                                  0x62C950
#define CXWnd__GetBorderFrame                                      0x629C10
#define CXWnd__GetChildWndAt                                       0x62C470
#define CXWnd__GetClientClipRect                                   0x629B50
#define CXWnd__GetFirstChildWnd                                    0x6295C0
#define CXWnd__GetNextChildWnd                                     0x62C430
#define CXWnd__GetNextSib                                          0x6295E0
#define CXWnd__GetScreenClipRect                                   0x62CD10
#define CXWnd__GetScreenRect                                       0x629DC0
#define CXWnd__GetTooltipRect                                      0x6299D0
#define CXWnd__GetWindowTextA                                      0x516C30
#define CXWnd__IsActive                                            0x6437E0
#define CXWnd__IsDescendantOf                                      0x629BC0
#define CXWnd__IsReallyVisible                                     0x62C410
#define CXWnd__IsType                                              0x64DE70
#define CXWnd__Move                                                0x62BF50
#define CXWnd__Move1                                               0x62BFF0
#define CXWnd__ProcessTransition                                   0x6294F0
#define CXWnd__Refade                                              0x6292F0
#define CXWnd__Resize                                              0x62CE50
#define CXWnd__Right                                               0x62CC60
#define CXWnd__SetFirstChildPointer                                0x62A010
#define CXWnd__SetFocus                                            0x62B2C0
#define CXWnd__SetKeyTooltip                                       0x62A080
#define CXWnd__SetMouseOver                                        0x62A050
#define CXWnd__SetNextSibPointer                                   0x62A030
#define CXWnd__StartFade                                           0x629550

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x644C00
#define CXWndManager__DrawWindows                                  0x6448D0
#define CXWndManager__GetFirstChildWnd                             0x644170
#define CXWndManager__GetKeyboardFlags                             0x6434D0
#define CXWndManager__HandleKeyboardMsg                            0x6439D0
#define CXWndManager__RemoveWnd                                    0x6438F0

// CDBStr
#define CDBStr__GetString                                          0x4550C0

// EQ_Character 
#define EQ_Character__CastRay                                      0x674330
#define EQ_Character__CastSpell                                    0x4214F0
#define EQ_Character__Cur_HP                                       0x428800
#define EQ_Character__GetAACastingTimeModifier                     0x41C3E0
#define EQ_Character__GetCharInfo2                                 0x5F8680
#define EQ_Character__GetFocusCastingTimeModifier                  0x418B20
#define EQ_Character__GetFocusRangeModifier                        0x418C50
#define EQ_Character__Max_Endurance                                0x4276C0
#define EQ_Character__Max_HP                                       0x427570
#define EQ_Character__Max_Mana                                     0x4E8150
#define EQ_Character__doCombatAbility                              0x4E6FD0
#define EQ_Character__UseSkill                                     0x433BF0
#define EQ_Character__GetConLevel                                  0x4E4540

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4D9E30
#define EQ_Item__GetItemLinkHash                                   0x5F7830
#define EQ_Item__IsStackable                                       0x5F8B30

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x46D180
#define EQ_LoadingS__Array                                         0x70EF30

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x4EAF90
#define EQ_PC__GetAltAbilityIndex                                  0x5FD280
#define EQ_PC__GetCombatAbility                                    0x5FD3C0
#define EQ_PC__GetCombatAbilityTimer                               0x5FD470
#define EQ_PC__GetItemTimerValue                                   0x4E62E0

// EQItemList 
#define EQItemList__dEQItemList                                    0x48EEA0
#define EQItemList__EQItemList                                     0x48EDF0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x454B30

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x4EF8C0
#define EQPlayer__dEQPlayer                                        0x4F3BB0
#define EQPlayer__DoAttack                                         0x4FEF50
#define EQPlayer__EQPlayer                                         0x4F6260
#define EQPlayer__SetNameSpriteState                               0x4F1EC0
#define EQPlayer__SetNameSpriteTint                                0x4EF930
#define EQPlayer__IsBodyType_j                                     0x6740E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4F7060

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4DBCB0
#define KeypressHandler__AttachKeyToEqCommand                      0x4DBCF0
#define KeypressHandler__ClearCommandStateArray                    0x4DBAC0
#define KeypressHandler__HandleKeyDown                             0x4DA6F0
#define KeypressHandler__HandleKeyUp                               0x4DA9F0
#define KeypressHandler__SaveKeymapping                            0x4DBB90

// MapViewMap 
#define MapViewMap__Clear                                          0x58B8B0
#define MapViewMap__SaveEx                                         0x58C280

// StringTable 
#define StringTable__getString                                     0x5F3470
