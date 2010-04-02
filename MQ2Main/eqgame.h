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
#define __ExpectedVersionDate                                     "Apr 17 2007"
#define __ExpectedVersionTime                                     "11:25:30"
#define __ActualVersionDate                                        0x6D0684
#define __ActualVersionTime                                        0x6D0690

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                              0x4E4020
#define __MemChecker1                                              0x622DA0
#define __MemChecker2                                              0x512FF0
#define __MemChecker3                                              0x5130A0
#define __MemChecker4                                              0x5F00A0
#define __EncryptPad0                                              0x728988
#define __EncryptPad1                                              0x732168
#define __EncryptPad2                                              0x72AED8
#define __EncryptPad3                                              0x72B2D8
#define __EncryptPad4                                              0x731880

// Direct Input
#define DI8__Main                                                  0x95FFC4
#define DI8__Keyboard                                              0x95FFC8
#define DI8__Mouse                                                 0x95FFCC
#define __AltTimerReady                                            0x8FC1FA
#define __Attack                                                   0x959872
#define __Autofire                                                 0x959873
#define __BindList                                                 0x723C18
#define __Clicks                                                   0x8FB324
#define __CommandList                                              0x724408
#define __CurrentMapLabel                                          0x96B08C
#define __CurrentSocial                                            0x7204B8
#define __DoAbilityAvailable                                       0x8FC194
#define __DoAbilityList                                            0x9313B8
#define __DrawHandler                                              0x979CF4
#define __GroupCount                                               0x8DBA70
#define __GroupLeader                                              0x8DBBCC
#define __Guilds                                                   0x8DD568
#define __gWorld                                                   0x8DD4C8
#define __HotkeyPage                                               0x9587A4
#define __HWnd                                                     0x95FF6C
#define __InChatMode                                               0x8FB260
#define __LastTell                                                 0x8FCAC0
#define __Mouse                                                    0x95FFD0
#define __MouseLook                                                0x8FB2F2
#define __NetStatusToggle                                          0x8FB2F4
#define __PCNames                                                  0x8FC518
#define __RangeAttackReady                                         0x8FC1F8
#define __RunWalkState                                             0x8FB264
#define __ScreenMode                                               0x82B548
#define __ScreenX                                                  0x8FB228
#define __ScreenY                                                  0x8FB22C
#define __ServerHost                                               0x8DB9C4
#define __ServerName                                               0x931378
#define __ShowNames                                                0x8FC3EC
#define __Socials                                                  0x931478


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x8F51B8
#define instEQZoneInfo                                             0x8FB490
#define instKeypressHandler                                        0x959944
#define pinstActiveBanker                                          0x8DD544
#define pinstActiveCorpse                                          0x8DD548
#define pinstActiveGMaster                                         0x8DD54C
#define pinstActiveMerchant                                        0x8DD540
#define pinstAltAdvManager                                         0x82C228
#define pinstAuraMgr                                               0x737274
#define pinstBandageTarget                                         0x8DD52C
#define pinstCamActor                                              0x82BD1C
#define pinstCDBStr                                                0x82B3C8
#define pinstCDisplay                                              0x8DD554
#define pinstCEverQuest                                            0x960138
#define pinstCharData                                              0x8DD510
#define pinstCharSpawn                                             0x8DD538
#define pinstControlledMissile                                     0x8DD50C
#define pinstControlledPlayer                                      0x8DD538
#define pinstCSidlManager                                          0x979544
#define pinstCXWndManager                                          0x97953C
#define instDynamicZone                                            0x8FAC78
#define pinstDZMember                                              0x8FAD88
#define pinstDZTimerInfo                                           0x8FAD8C
#define pinstEQItemList                                            0x8DD4F4
#define instEQMisc                                                 0x82B380
#define pinstEQSoundManager                                        0x82C24C
#define instExpeditionLeader                                       0x8FACC2
#define instExpeditionName                                         0x8FAD02
#define instGroup                                                  0x8DBA70
#define pinstGroup                                                 0x8DBA6C
#define pinstImeManager                                            0x979548
#define pinstLocalPlayer                                           0x8DD524
#define pinstModelPlayer                                           0x8DD550
#define pinstPCData                                                0x8DD510
#define pinstSelectedItem                                          0x96AEE4
#define pinstSkillMgr                                              0x95D028
#define pinstSpawnManager                                          0x95CFA4
#define pinstSpellManager                                          0x95D02C
#define pinstSpellSets                                             0x9587A8
#define pinstStringTable                                           0x8DD4D8
#define pinstSwitchManager                                         0x8DB6C0
#define pinstTarget                                                0x8DD53C
#define pinstTargetObject                                          0x8DD514
#define pinstTargetSwitch                                          0x8DD518
#define pinstTaskMember                                            0x82B360
#define pinstTrackTarget                                           0x8DD530
#define pinstTradeTarget                                           0x8DD520
#define instTributeActive                                          0x82B3A5
#define pinstViewActor                                             0x82BD18
#define pinstWorldData                                             0x8DD4F0


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x7357A8
#define pinstCAudioTriggersWindow                                  0x73578C
#define pinstCCharacterSelect                                      0x82BC28
#define pinstCFacePick                                             0x82BBE0
#define pinstCNoteWnd                                              0x82BBE4
#define pinstCBookWnd                                              0x82BBE8
#define pinstCPetInfoWnd                                           0x82BBEC
#define pinstCTrainWnd                                             0x82BBF0
#define pinstCSkillsWnd                                            0x82BBF4
#define pinstCSkillsSelectWnd                                      0x82BBF8
#define pinstCCombatSkillSelectWnd                                 0x82BBFC
#define pinstCFriendsWnd                                           0x82BC00
#define pinstCAuraWnd                                              0x82BC04
#define pinstCRespawnWnd                                           0x82BC08
#define pinstCBandolierWnd                                         0x82BC0C
#define pinstCPotionBeltWnd                                        0x82BC10
#define pinstCAAWnd                                                0x82BC14
#define pinstCGroupSearchFiltersWnd                                0x82BC18
#define pinstCLoadskinWnd                                          0x82BC1C
#define pinstCAlarmWnd                                             0x82BC20
#define pinstCMusicPlayerWnd                                       0x82BC24
#define pinstCMailWnd                                              0x82BC2C
#define pinstCMailCompositionWnd                                   0x82BC30
#define pinstCMailAddressBookWnd                                   0x82BC34
#define pinstCRaidWnd                                              0x82BC3C
#define pinstCRaidOptionsWnd                                       0x82BC40
#define pinstCBreathWnd                                            0x82BC44
#define pinstCMapViewWnd                                           0x82BC48
#define pinstCMapToolbarWnd                                        0x82BC4C
#define pinstCEditLabelWnd                                         0x82BC50
#define pinstCTargetWnd                                            0x82BC54
#define pinstCColorPickerWnd                                       0x82BC58
#define pinstCPlayerWnd                                            0x82BC5C
#define pinstCOptionsWnd                                           0x82BC60
#define pinstCBuffWindowNORMAL                                     0x82BC64
#define pinstCBuffWindowSHORT                                      0x82BC68
#define pinstCharacterCreation                                     0x82BC6C
#define pinstCCursorAttachment                                     0x82BC70
#define pinstCCastingWnd                                           0x82BC74
#define pinstCCastSpellWnd                                         0x82BC78
#define pinstCSpellBookWnd                                         0x82BC7C
#define pinstCInventoryWnd                                         0x82BC80
#define pinstCBankWnd                                              0x82BC84
#define pinstCQuantityWnd                                          0x82BC88
#define pinstCLootWnd                                              0x82BC8C
#define pinstCActionsWnd                                           0x82BC90
#define pinstCCombatAbilityWnd                                     0x82BC94
#define pinstCMerchantWnd                                          0x82BC98
#define pinstCTradeWnd                                             0x82BC9C
#define pinstCSelectorWnd                                          0x82BCA0
#define pinstCBazaarWnd                                            0x82BCA4
#define pinstCBazaarSearchWnd                                      0x82BCA8
#define pinstCGiveWnd                                              0x82BCAC
#define pinstCTrackingWnd                                          0x82BCB0
#define pinstCInspectWnd                                           0x82BCB4
#define pinstCSocialEditWnd                                        0x82BCB8
#define pinstCFeedbackWnd                                          0x82BCBC
#define pinstCBugReportWnd                                         0x82BCC0
#define pinstCVideoModesWnd                                        0x82BCC4
#define pinstCTextEntryWnd                                         0x82BCCC
#define pinstCFileSelectionWnd                                     0x82BCD0
#define pinstCCompassWnd                                           0x82BCD4
#define pinstCPlayerNotesWnd                                       0x82BCD8
#define pinstCGemsGameWnd                                          0x82BCDC
#define pinstCTimeLeftWnd                                          0x82BCE0
#define pinstCPetitionQWnd                                         0x82BCE4
#define pinstCSoulmarkWnd                                          0x82BCE8
#define pinstCStoryWnd                                             0x82BCEC
#define pinstCJournalTextWnd                                       0x82BCF0
#define pinstCJournalCatWnd                                        0x82BCF4
#define pinstCBodyTintWnd                                          0x82BCF8
#define pinstCServerListWnd                                        0x82BCFC
#define pinstCAvaZoneWnd                                           0x82BD00
#define pinstCBlockedBuffWnd                                       0x82BD04
#define pinstCBlockedPetBuffWnd                                    0x82BD08
#define pinstCInvSlotMgr                                           0x82BD0C
#define pinstCContainerMgr                                         0x82BD10
#define pinstCAdventureLeaderboardWnd                              0x968704
#define pinstCAdventureRequestWnd                                  0x968720
#define pinstCAltStorageWnd                                        0x968780
#define pinstCAdventureStatsWnd                                    0x96873C
#define pinstCBarterMerchantWnd                                    0x968934
#define pinstCBarterSearchWnd                                      0x968950
#define pinstCBarterWnd                                            0x96896C
#define pinstCChatManager                                          0x968B4C
#define pinstCDynamicZoneWnd                                       0x968C28
#define pinstCEQMainWnd                                            0x968C98
#define pinstCFellowshipWnd                                        0x968CFC
#define pinstCFindLocationWnd                                      0x968D30
#define pinstCGroupSearchWnd                                       0x968E04
#define pinstCGroupWnd                                             0x968DFC
#define pinstCGuildBankWnd                                         0x968E18
#define pinstCGuildMgmtWnd                                         0x96AE38
#define pinstCGuildTributeMasterWnd                                0x96AE58
#define pinstCHotButtonWnd                                         0x96AE74
#define pinstCHotButtonWnd1                                        0x96AE74
#define pinstCHotButtonWnd2                                        0x96AE78
#define pinstCHotButtonWnd3                                        0x96AE7C
#define pinstCHotButtonWnd4                                        0x96AE80
#define pinstCItemDisplayManager                                   0x96AF18
#define pinstCItemExpTransferWnd                                   0x96AF38
#define pinstCLeadershipWnd                                        0x96AFB4
#define pinstCLFGuildWnd                                           0x96AFD0
#define pinstCMIZoneSelectWnd                                      0x96B0F4
#define pinstCAdventureMerchantWnd                                 0x96B1EC
#define pinstCConfirmationDialog                                   0x96B208
#define pinstCPopupWndManager                                      0x96B208
#define pinstCProgressionSelectionWnd                              0x96B23C
#define pinstCPvPLeaderboardWnd                                    0x96B258
#define pinstCPvPStatsWnd                                          0x96B274
#define pinstCSystemInfoDialogBox                                  0x96BBF4
#define pinstCTargetOfTargetWnd                                    0x96BC10
#define pinstCTaskSelectWnd                                        0x96BC44
#define pinstCTaskTemplateSelectWnd                                0x96BC60
#define pinstCTaskWnd                                              0x96BC7C
#define pinstCTipWndOFDAY                                          0x96BCC8
#define pinstCTipWndCONTEXT                                        0x96BCCC
#define pinstCTitleWnd                                             0x96BCE8
#define pinstCTradeskillWnd                                        0x96BD2C
#define pinstCTributeBenefitWnd                                    0x96BD78
#define pinstCTributeMasterWnd                                     0x96BD94
#define pinstCContextMenuManager                                   0x979604
#define pinstCVoiceMacroWnd                                        0x95D0DC


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4A76D0
#define __ConvertItemTags                                          0x49C120
#define __ExecuteCmd                                               0x48D900
#define __get_melee_range                                          0x492910
#define __GetGaugeValueFromEQ                                      0x5CA930
#define __GetLabelFromEQ                                           0x5CB060
#define __NewUIINI                                                 0x5CA530
#define __ProcessGameEvents                                        0x4D2980
#define __SendMessage                                              0x4B4CD0
#define CrashDetected                                              0x512CA0
#define DrawNetStatus                                              0x4E6CF0
#define Util__FastTime                                             0x6233F0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x46DA30
#define AltAdvManager__IsAbilityReady                              0x46DA70
#define AltAdvManager__GetAltAbility                               0x46DC70

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5270C0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x530530

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x63F330

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5443F0
#define CChatManager__InitContextMenu                              0x544B80

// CChatService
#define CChatService__GetNumberOfFriends                           0x6144F0
#define CChatService__GetFriendName                                0x614500

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x548D00

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x634E10
#define CComboWnd__Draw                                            0x634FC0
#define CComboWnd__GetCurChoice                                    0x634DC0
#define CComboWnd__GetListRect                                     0x6352A0
#define CComboWnd__GetTextRect                                     0x634E40
#define CComboWnd__InsertChoice                                    0x635310
#define CComboWnd__SetColors                                       0x634D50
#define CComboWnd__SetChoice                                       0x634D80

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x54F380
#define CContainerWnd__vftable                                     0x6D68D0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x45D010
#define CDisplay__GetClickedActor                                  0x45A8C0
#define CDisplay__GetUserDefinedColor                              0x459D30
#define CDisplay__GetWorldFilePath                                 0x4592E0
#define CDisplay__is3dON                                           0x457F00
#define CDisplay__ReloadUI                                         0x468DB0
#define CDisplay__WriteTextHD2                                     0x45E7B0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5212A0
#define CEditBaseWnd__SetSel                                       0x6578B0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x654FE0
#define CEditWnd__GetCharIndexPt                                   0x655E20
#define CEditWnd__GetDisplayString                                 0x655170
#define CEditWnd__GetHorzOffset                                    0x6553F0
#define CEditWnd__GetLineForPrintableChar                          0x6558D0
#define CEditWnd__GetSelStartPt                                    0x656060
#define CEditWnd__GetSTMLSafeText                                  0x655590
#define CEditWnd__PointFromPrintableChar                           0x6559E0
#define CEditWnd__SelectableCharFromPoint                          0x655B60
#define CEditWnd__SetEditable                                      0x655560

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4B8DE0
#define CEverQuest__DropHeldItemOnGround                           0x4BD9A0
#define CEverQuest__dsp_chat                                       0x4BE620
#define CEverQuest__EnterZone                                      0x4D1530
#define CEverQuest__GetBodyTypeDesc                                0x4B6520
#define CEverQuest__GetClassDesc                                   0x4B5C80
#define CEverQuest__GetClassThreeLetterCode                        0x4B6280
#define CEverQuest__GetDeityDesc                                   0x4B6B70
#define CEverQuest__GetLangDesc                                    0x4B6890
#define CEverQuest__GetRaceDesc                                    0x4B6B40
#define CEverQuest__InterpretCmd                                   0x4BEF80
#define CEverQuest__LeftClickedOnPlayer                            0x4D0120
#define CEverQuest__RightClickedOnPlayer                           0x4D04E0
#define CEverQuest__SetGameState                                   0x4B8EB0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x55A390
#define CGaugeWnd__CalcLinesFillRect                               0x55A400
#define CGaugeWnd__Draw                                            0x55A790

// CGuild
#define CGuild__FindMemberByName                                   0x415A70

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5701E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x577CA0
#define CInvSlotMgr__MoveItem                                      0x577E40

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x578D40

// CInvSLot
#define CInvSlot__SliderComplete                                   0x576CC0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5802C0
#define CItemDisplayWnd__SetSpell                                  0x5C89A0

// CLabel 
#define CLabel__Draw                                               0x5858E0

// CListWnd 
#define CListWnd__AddColumn                                        0x634B60
#define CListWnd__AddColumn1                                       0x634650
#define CListWnd__AddLine                                          0x634230
#define CListWnd__AddString                                        0x634400
#define CListWnd__CalculateFirstVisibleLine                        0x631560
#define CListWnd__CalculateVSBRange                                0x6331D0
#define CListWnd__ClearAllSel                                      0x630CD0
#define CListWnd__CloseAndUpdateEditWindow                         0x631B70
#define CListWnd__Compare                                          0x631F20
#define CListWnd__Draw                                             0x632ED0
#define CListWnd__DrawColumnSeparators                             0x632D40
#define CListWnd__DrawHeader                                       0x630EA0
#define CListWnd__DrawItem                                         0x632630
#define CListWnd__DrawLine                                         0x6329E0
#define CListWnd__DrawSeparator                                    0x632DE0
#define CListWnd__EnsureVisible                                    0x6315B0
#define CListWnd__ExtendSel                                        0x632560
#define CListWnd__GetColumnMinWidth                                0x630A70
#define CListWnd__GetColumnWidth                                   0x6309B0
#define CListWnd__GetCurSel                                        0x630490
#define CListWnd__GetHeaderRect                                    0x630580
#define CListWnd__GetItemAtPoint                                   0x631880
#define CListWnd__GetItemAtPoint1                                  0x6318F0
#define CListWnd__GetItemData                                      0x630760
#define CListWnd__GetItemHeight                                    0x631300
#define CListWnd__GetItemIcon                                      0x6308F0
#define CListWnd__GetItemRect                                      0x631670
#define CListWnd__GetItemText                                      0x6307A0
#define CListWnd__GetSelList                                       0x634530
#define CListWnd__GetSeparatorRect                                 0x631E60
#define CListWnd__RemoveLine                                       0x634B10
#define CListWnd__SetColors                                        0x6304F0
#define CListWnd__SetColumnJustification                           0x630AD0
#define CListWnd__SetColumnWidth                                   0x630A30
#define CListWnd__SetCurSel                                        0x6304D0
#define CListWnd__SetItemColor                                     0x633E00
#define CListWnd__SetItemData                                      0x630D70
#define CListWnd__SetItemText                                      0x633D80
#define CListWnd__ShiftColumnSeparator                             0x6324D0
#define CListWnd__Sort                                             0x634B90
#define CListWnd__ToggleSel                                        0x630C40

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x598690

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x59A070
#define CMerchantWnd__RequestBuyItem                               0x59B320
#define CMerchantWnd__RequestSellItem                              0x59A2D0
#define CMerchantWnd__SelectBuySellSlot                            0x59B060

// CObfuscator
#define CObfuscator__doit                                          0x615BA0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x643F10

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x63A4A0
#define CSidlScreenWnd__CalculateVSBRange                          0x522C40
#define CSidlScreenWnd__ConvertToRes                               0x63AC01
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x63B400
#define CSidlScreenWnd__CSidlScreenWnd1                            0x63C6C0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x63C770
#define CSidlScreenWnd__dCSidlScreenWnd                            0x63BF70
#define CSidlScreenWnd__DrawSidlPiece                              0x63B0E0
#define CSidlScreenWnd__EnableIniStorage                           0x63ABA0
#define CSidlScreenWnd__GetSidlPiece                               0x63B2E0
#define CSidlScreenWnd__Init1                                      0x63C4D0
#define CSidlScreenWnd__LoadIniInfo                                0x63B4B0
#define CSidlScreenWnd__LoadIniListWnd                             0x63AD50
#define CSidlScreenWnd__LoadSidlScreen                             0x63AF10
#define CSidlScreenWnd__StoreIniInfo                               0x63A6E0
#define CSidlScreenWnd__WndNotification                            0x63B040

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x508190

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x659730
#define CSliderWnd__SetValue                                       0x659830
#define CSliderWnd__SetNumTicks                                    0x659D70

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5C76F0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x64E310
#define CStmlWnd__CalculateVSBRange                                0x6466A0
#define CStmlWnd__CanBreakAtCharacter                              0x6467E0
#define CStmlWnd__FastForwardToEndOfTag                            0x6472F0
#define CStmlWnd__GetNextTagPiece                                  0x647210
#define CStmlWnd__GetSTMLText                                      0x548CA0
#define CStmlWnd__GetThisChar                                      0x6767E0
#define CStmlWnd__GetVisiableText                                  0x648510
#define CStmlWnd__InitializeWindowVariables                        0x64A670
#define CStmlWnd__MakeStmlColorTag                                 0x645DA0
#define CStmlWnd__MakeWndNotificationTag                           0x645E40
#define CStmlWnd__StripFirstSTMLLines                              0x64E090
#define CStmlWnd__UpdateHistoryString                              0x648D70

// CTabWnd 
#define CTabWnd__Draw                                              0x658FB0
#define CTabWnd__DrawCurrentPage                                   0x658920
#define CTabWnd__DrawTab                                           0x658700
#define CTabWnd__GetCurrentPage                                    0x658C20
#define CTabWnd__GetPageClientRect                                 0x6583D0
#define CTabWnd__GetPageFromTabIndex                               0x658630
#define CTabWnd__GetPageInnerRect                                  0x658430
#define CTabWnd__GetTabInnerRect                                   0x6585B0
#define CTabWnd__GetTabRect                                        0x6584C0
#define CTabWnd__IndexInBounds                                     0x6586CD
#define CTabWnd__InsertPage                                        0x6591D0
#define CTabWnd__SetPage                                           0x658C60
#define CTabWnd__SetPageRect                                       0x658EE0
#define CTabWnd__UpdatePage                                        0x659150

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x412680

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x63CAD0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x65FF50

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x630200

// CXRect 
#define CXRect__CenterPoint                                        0x526880

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x412220
#define CXStr__CXStr1                                              0x503A60
#define CXStr__CXStr3                                              0x624AF0
#define CXStr__dCXStr                                              0x46E4F0
#define CXStr__operator_equal1                                     0x624CB0
#define CXStr__operator_plus_equal1                                0x625BA0

// CXWnd 
#define CXWnd__BringToTop                                          0x635B00
#define CXWnd__Center                                              0x6391F0
#define CXWnd__ClrFocus                                            0x635830
#define CXWnd__DoAllDrawing                                        0x639EA0
#define CXWnd__DrawChildren                                        0x639FD0
#define CXWnd__DrawColoredRect                                     0x635D60
#define CXWnd__DrawTooltip                                         0x639DC0
#define CXWnd__DrawTooltipAtPoint                                  0x639040
#define CXWnd__GetBorderFrame                                      0x6362A0
#define CXWnd__GetChildWndAt                                       0x638B40
#define CXWnd__GetClientClipRect                                   0x636160
#define CXWnd__GetFirstChildWnd                                    0x635BA0
#define CXWnd__GetNextChildWnd                                     0x638B00
#define CXWnd__GetNextSib                                          0x635BC0
#define CXWnd__GetScreenClipRect                                   0x639410
#define CXWnd__GetScreenRect                                       0x636400
#define CXWnd__GetTooltipRect                                      0x635F90
#define CXWnd__GetWindowTextA                                      0x51A460
#define CXWnd__IsActive                                            0x6502A0
#define CXWnd__IsDescendantOf                                      0x6361D0
#define CXWnd__IsReallyVisible                                     0x638AE0
#define CXWnd__IsType                                              0x65ABE0
#define CXWnd__Move                                                0x638610
#define CXWnd__Move1                                               0x6386B0
#define CXWnd__ProcessTransition                                   0x635AD0
#define CXWnd__Refade                                              0x6358E0
#define CXWnd__Resize                                              0x639550
#define CXWnd__Right                                               0x639360
#define CXWnd__SetFirstChildPointer                                0x636670
#define CXWnd__SetFocus                                            0x637960
#define CXWnd__SetKeyTooltip                                       0x6366E0
#define CXWnd__SetMouseOver                                        0x6366B0
#define CXWnd__SetNextSibPointer                                   0x636690
#define CXWnd__StartFade                                           0x635B20

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6516F0
#define CXWndManager__DrawWindows                                  0x651330
#define CXWndManager__GetFirstChildWnd                             0x650C40
#define CXWndManager__GetKeyboardFlags                             0x64FF80
#define CXWndManager__HandleKeyboardMsg                            0x650490
#define CXWndManager__RemoveWnd                                    0x6503B0

// CDBStr
#define CDBStr__GetString                                          0x456850

// EQ_Character 
#define EQ_Character__CastRay                                      0x6821E0
#define EQ_Character__CastSpell                                    0x421CA0
#define EQ_Character__Cur_HP                                       0x429190
#define EQ_Character__GetAACastingTimeModifier                     0x41CAC0
#define EQ_Character__GetCharInfo2                                 0x5FC640
#define EQ_Character__GetFocusCastingTimeModifier                  0x419170
#define EQ_Character__GetFocusRangeModifier                        0x4192A0
#define EQ_Character__Max_Endurance                                0x427F90
#define EQ_Character__Max_HP                                       0x427E40
#define EQ_Character__Max_Mana                                     0x4EBCE0
#define EQ_Character__doCombatAbility                              0x4EAB60
#define EQ_Character__UseSkill                                     0x434630
#define EQ_Character__GetConLevel                                  0x4E80D0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4DDC60
#define EQ_Item__GetItemLinkHash                                   0x5FB890
#define EQ_Item__IsStackable                                       0x5F5C00

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x46EBD0
#define EQ_LoadingS__Array                                         0x722130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x4EEB90
#define EQ_PC__GetAltAbilityIndex                                  0x6015C0
#define EQ_PC__GetCombatAbility                                    0x601650
#define EQ_PC__GetCombatAbilityTimer                               0x601700
#define EQ_PC__GetItemTimerValue                                   0x4E9E90
#define EQ_PC__HasLoreItem                                         0x4ED1B0

// EQItemList 
#define EQItemList__dEQItemList                                    0x4911D0
#define EQItemList__EQItemList                                     0x491120

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x4562D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x4F3550
#define EQPlayer__dEQPlayer                                        0x4F7980
#define EQPlayer__DoAttack                                         0x502D60
#define EQPlayer__EQPlayer                                         0x4FA0A0
#define EQPlayer__SetNameSpriteState                               0x4F5C30
#define EQPlayer__SetNameSpriteTint                                0x4F35C0
#define EQPlayer__IsBodyType_j                                     0x681C10

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4FAEA0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4DF7F0
#define KeypressHandler__AttachKeyToEqCommand                      0x4DF830
#define KeypressHandler__ClearCommandStateArray                    0x4DF600
#define KeypressHandler__HandleKeyDown                             0x4DE210
#define KeypressHandler__HandleKeyUp                               0x4DE510
#define KeypressHandler__SaveKeymapping                            0x4DF6D0

// MapViewMap 
#define MapViewMap__Clear                                          0x5946D0
#define MapViewMap__SaveEx                                         0x5950A0

// StringTable 
#define StringTable__getString                                     0x5F5600
