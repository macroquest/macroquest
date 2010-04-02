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
#define __ExpectedVersionDate                                     "Jun 29 2007"
#define __ExpectedVersionTime                                     "10:34:18"
#define __ActualVersionDate                                        0x6EBF24
#define __ActualVersionTime                                        0x6EBF30

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                              0x4EE9F0
#define __MemChecker1                                              0x63C560
#define __MemChecker2                                              0x51F550
#define __MemChecker3                                              0x51F600
#define __MemChecker4                                              0x607200
#define __EncryptPad0                                              0x745A20
#define __EncryptPad1                                              0x74F258
#define __EncryptPad2                                              0x747F80
#define __EncryptPad3                                              0x748380
#define __EncryptPad4                                              0x74E970

// Direct Input
#define DI8__Main                                                  0x97D204
#define DI8__Keyboard                                              0x97D208
#define DI8__Mouse                                                 0x97D20C
#define __AltTimerReady                                            0x919342
#define __Attack                                                   0x9769BA
#define __Autofire                                                 0x9769BB
#define __BindList                                                 0x740C50
#define __Clicks                                                   0x91846C
#define __CommandList                                              0x741450
#define __CurrentMapLabel                                          0x9882D4
#define __CurrentSocial                                            0x73D4DC
#define __DoAbilityAvailable                                       0x9192DC
#define __DoAbilityList                                            0x94E500
#define __DrawHandler                                              0x99712C
#define __GroupCount                                               0x8F8B90
#define __GroupLeader                                              0x8F8CEC
#define __Guilds                                                   0x8FA6B0
#define __gWorld                                                   0x8FA5F0
#define __HotkeyPage                                               0x9758EC
#define __HWnd                                                     0x97D1AC
#define __InChatMode                                               0x9183A8
#define __LastTell                                                 0x919C08
#define __LMouseHeldTime                                           0x91848C
#define __Mouse                                                    0x97D210
#define __MouseLook                                                0x91843A
#define __NetStatusToggle                                          0x91843C
#define __PCNames                                                  0x919660
#define __RangeAttackReady                                         0x919340
#define __RMouseHeldTime                                           0x918488
#define __RunWalkState                                             0x9183AC
#define __ScreenMode                                               0x848660
#define __ScreenX                                                  0x918370
#define __ScreenY                                                  0x918374
#define __ScreenXMax                                               0x918378
#define __ScreenYMax                                               0x91837C
#define __ServerHost                                               0x8F8AE4
#define __ServerName                                               0x94E4C0
#define __ShowNames                                                0x919534
#define __Socials                                                  0x94E5C0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x912300
#define instEQZoneInfo                                             0x9185D8
#define instKeypressHandler                                        0x976ABC
#define pinstActiveBanker                                          0x8FA688
#define pinstActiveCorpse                                          0x8FA68C
#define pinstActiveGMaster                                         0x8FA690
#define pinstActiveMerchant                                        0x8FA684
#define pinstAltAdvManager                                         0x849348
#define pinstAuraMgr                                               0x75438C
#define pinstBandageTarget                                         0x8FA670
#define pinstCamActor                                              0x848E3C
#define pinstCDBStr                                                0x8484E0
#define pinstCDisplay                                              0x8FA698
#define pinstCEverQuest                                            0x97D384
#define pinstCharData                                              0x8FA654
#define pinstCharSpawn                                             0x8FA67C
#define pinstControlledMissile                                     0x8FA650
#define pinstControlledPlayer                                      0x8FA67C
#define pinstCSidlManager                                          0x996928
#define pinstCXWndManager                                          0x996920
#define instDynamicZone                                            0x917DC0
#define pinstDZMember                                              0x917ED0
#define pinstDZTimerInfo                                           0x917ED4
#define pinstEQItemList                                            0x8FA638
#define instEQMisc                                                 0x848498
#define pinstEQSoundManager                                        0x84936C
#define instExpeditionLeader                                       0x917E0A
#define instExpeditionName                                         0x917E4A
#define instGroup                                                  0x8F8B90
#define pinstGroup                                                 0x8F8B8C
#define pinstImeManager                                            0x99692C
#define pinstLocalPlayer                                           0x8FA668
#define pinstModelPlayer                                           0x8FA694
#define pinstPCData                                                0x8FA654
#define pinstSelectedItem                                          0x98812C
#define pinstSkillMgr                                              0x97A1B8
#define pinstSpawnManager                                          0x97A134
#define pinstSpellManager                                          0x97A1BC
#define pinstSpellSets                                             0x9758F0
#define pinstStringTable                                           0x8FA60C
#define pinstSwitchManager                                         0x8F87E0
#define pinstTarget                                                0x8FA680
#define pinstTargetObject                                          0x8FA658
#define pinstTargetSwitch                                          0x8FA65C
#define pinstTaskMember                                            0x848478
#define pinstTrackTarget                                           0x8FA674
#define pinstTradeTarget                                           0x8FA664
#define instTributeActive                                          0x8484BD
#define pinstViewActor                                             0x848E38
#define pinstWorldData                                             0x8FA634


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x7528C0
#define pinstCAudioTriggersWindow                                  0x75288C
#define pinstCCharacterSelect                                      0x848D48
#define pinstCFacePick                                             0x848D00
#define pinstCNoteWnd                                              0x848D04
#define pinstCBookWnd                                              0x848D08
#define pinstCPetInfoWnd                                           0x848D0C
#define pinstCTrainWnd                                             0x848D10
#define pinstCSkillsWnd                                            0x848D14
#define pinstCSkillsSelectWnd                                      0x848D18
#define pinstCCombatSkillSelectWnd                                 0x848D1C
#define pinstCFriendsWnd                                           0x848D20
#define pinstCAuraWnd                                              0x848D24
#define pinstCRespawnWnd                                           0x848D28
#define pinstCBandolierWnd                                         0x848D2C
#define pinstCPotionBeltWnd                                        0x848D30
#define pinstCAAWnd                                                0x848D34
#define pinstCGroupSearchFiltersWnd                                0x848D38
#define pinstCLoadskinWnd                                          0x848D3C
#define pinstCAlarmWnd                                             0x848D40
#define pinstCMusicPlayerWnd                                       0x848D44
#define pinstCMailWnd                                              0x848D4C
#define pinstCMailCompositionWnd                                   0x848D50
#define pinstCMailAddressBookWnd                                   0x848D54
#define pinstCRaidWnd                                              0x848D5C
#define pinstCRaidOptionsWnd                                       0x848D60
#define pinstCBreathWnd                                            0x848D64
#define pinstCMapViewWnd                                           0x848D68
#define pinstCMapToolbarWnd                                        0x848D6C
#define pinstCEditLabelWnd                                         0x848D70
#define pinstCTargetWnd                                            0x848D74
#define pinstCColorPickerWnd                                       0x848D78
#define pinstCPlayerWnd                                            0x848D7C
#define pinstCOptionsWnd                                           0x848D80
#define pinstCBuffWindowNORMAL                                     0x848D84
#define pinstCBuffWindowSHORT                                      0x848D88
#define pinstCharacterCreation                                     0x848D8C
#define pinstCCursorAttachment                                     0x848D90
#define pinstCCastingWnd                                           0x848D94
#define pinstCCastSpellWnd                                         0x848D98
#define pinstCSpellBookWnd                                         0x848D9C
#define pinstCInventoryWnd                                         0x848DA0
#define pinstCBankWnd                                              0x848DA4
#define pinstCQuantityWnd                                          0x848DA8
#define pinstCLootWnd                                              0x848DAC
#define pinstCActionsWnd                                           0x848DB0
#define pinstCCombatAbilityWnd                                     0x848DB4
#define pinstCMerchantWnd                                          0x848DB8
#define pinstCTradeWnd                                             0x848DBC
#define pinstCSelectorWnd                                          0x848DC0
#define pinstCBazaarWnd                                            0x848DC4
#define pinstCBazaarSearchWnd                                      0x848DC8
#define pinstCGiveWnd                                              0x848DCC
#define pinstCTrackingWnd                                          0x848DD0
#define pinstCInspectWnd                                           0x848DD4
#define pinstCSocialEditWnd                                        0x848DD8
#define pinstCFeedbackWnd                                          0x848DDC
#define pinstCBugReportWnd                                         0x848DE0
#define pinstCVideoModesWnd                                        0x848DE4
#define pinstCTextEntryWnd                                         0x848DEC
#define pinstCFileSelectionWnd                                     0x848DF0
#define pinstCCompassWnd                                           0x848DF4
#define pinstCPlayerNotesWnd                                       0x848DF8
#define pinstCGemsGameWnd                                          0x848DFC
#define pinstCTimeLeftWnd                                          0x848E00
#define pinstCPetitionQWnd                                         0x848E04
#define pinstCSoulmarkWnd                                          0x848E08
#define pinstCStoryWnd                                             0x848E0C
#define pinstCJournalTextWnd                                       0x848E10
#define pinstCJournalCatWnd                                        0x848E14
#define pinstCBodyTintWnd                                          0x848E18
#define pinstCServerListWnd                                        0x848E1C
#define pinstCAvaZoneWnd                                           0x848E20
#define pinstCBlockedBuffWnd                                       0x848E24
#define pinstCBlockedPetBuffWnd                                    0x848E28
#define pinstCInvSlotMgr                                           0x848E2C
#define pinstCContainerMgr                                         0x848E30
#define pinstCAdventureLeaderboardWnd                              0x985964
#define pinstCAdventureRequestWnd                                  0x985980
#define pinstCAltStorageWnd                                        0x9859E0
#define pinstCAdventureStatsWnd                                    0x98599C
#define pinstCBarterMerchantWnd                                    0x985B94
#define pinstCBarterSearchWnd                                      0x985BB0
#define pinstCBarterWnd                                            0x985BCC
#define pinstCChatManager                                          0x985D94
#define pinstCDynamicZoneWnd                                       0x985E70
#define pinstCEQMainWnd                                            0x985EE0
#define pinstCFellowshipWnd                                        0x985F44
#define pinstCFindLocationWnd                                      0x985F78
#define pinstCGroupSearchWnd                                       0x986028
#define pinstCGroupWnd                                             0x986044
#define pinstCGuildBankWnd                                         0x986060
#define pinstCGuildMgmtWnd                                         0x988080
#define pinstCGuildTributeMasterWnd                                0x9880A0
#define pinstCHotButtonWnd                                         0x9880BC
#define pinstCHotButtonWnd1                                        0x9880BC
#define pinstCHotButtonWnd2                                        0x9880C0
#define pinstCHotButtonWnd3                                        0x9880C4
#define pinstCHotButtonWnd4                                        0x9880C8
#define pinstCItemDisplayManager                                   0x988160
#define pinstCItemExpTransferWnd                                   0x988180
#define pinstCLeadershipWnd                                        0x9881FC
#define pinstCLFGuildWnd                                           0x988218
#define pinstCMIZoneSelectWnd                                      0x98833C
#define pinstCAdventureMerchantWnd                                 0x988434
#define pinstCConfirmationDialog                                   0x988450
#define pinstCPopupWndManager                                      0x988450
#define pinstCProgressionSelectionWnd                              0x988484
#define pinstCPvPLeaderboardWnd                                    0x9884A0
#define pinstCPvPStatsWnd                                          0x9884BC
#define pinstCSystemInfoDialogBox                                  0x988E24
#define pinstCTargetOfTargetWnd                                    0x988E40
#define pinstCTaskSelectWnd                                        0x988E74
#define pinstCTaskTemplateSelectWnd                                0x988E90
#define pinstCTaskWnd                                              0x988EAC
#define pinstCTipWndOFDAY                                          0x988EF8
#define pinstCTipWndCONTEXT                                        0x988EFC
#define pinstCTitleWnd                                             0x988F18
#define pinstCTradeskillWnd                                        0x988F5C
#define pinstCTributeBenefitWnd                                    0x988FA8
#define pinstCTributeMasterWnd                                     0x988FC4
#define pinstCContextMenuManager                                   0x996984
#define pinstCVoiceMacroWnd                                        0x97A26C
#define pinstCHtmlWnd                                              0x97A288


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4B0140
#define __ConvertItemTags                                          0x4A4AD0
#define __ExecuteCmd                                               0x496190
#define __get_melee_range                                          0x49B1C0
#define __GetGaugeValueFromEQ                                      0x5DD840
#define __GetLabelFromEQ                                           0x5DE050
#define __NewUIINI                                                 0x5DD430
#define __ProcessGameEvents                                        0x4DB7F0
#define __SendMessage                                              0x4BD860
#define CrashDetected                                              0x51E650
#define DrawNetStatus                                              0x4F1720
#define Util__FastTime                                             0x63CBB0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x470AB0
#define AltAdvManager__IsAbilityReady                              0x470AF0
#define AltAdvManager__GetAltAbility                               0x470C80

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x534A30

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x53DFC0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x667630

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x550D60
#define CChatManager__InitContextMenu                              0x5514F0

// CChatService
#define CChatService__GetNumberOfFriends                           0x62D340
#define CChatService__GetFriendName                                0x62D350

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x555670
#define CChatWindow__WndNotification                               0x556060

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x64E630
#define CComboWnd__Draw                                            0x64E7E0
#define CComboWnd__GetCurChoice                                    0x64E5D0
#define CComboWnd__GetListRect                                     0x64EAC0
#define CComboWnd__GetTextRect                                     0x64E660
#define CComboWnd__InsertChoice                                    0x64EB30
#define CComboWnd__SetColors                                       0x64E560
#define CComboWnd__SetChoice                                       0x64E590

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x55BD40
#define CContainerWnd__vftable                                     0x6F2258

// CDisplay 
#define CDisplay__CleanGameUI                                      0x45FDE0
#define CDisplay__GetClickedActor                                  0x45D680
#define CDisplay__GetUserDefinedColor                              0x45CAE0
#define CDisplay__GetWorldFilePath                                 0x45C050
#define CDisplay__is3dON                                           0x45AC00
#define CDisplay__ReloadUI                                         0x46BDA0
#define CDisplay__WriteTextHD2                                     0x4615A0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x52ED80
#define CEditBaseWnd__SetSel                                       0x6724F0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x65B8E0
#define CEditWnd__GetCharIndexPt                                   0x65C740
#define CEditWnd__GetDisplayString                                 0x65BA70
#define CEditWnd__GetHorzOffset                                    0x65BD10
#define CEditWnd__GetLineForPrintableChar                          0x65C1F0
#define CEditWnd__GetSelStartPt                                    0x65C980
#define CEditWnd__GetSTMLSafeText                                  0x65BEB0
#define CEditWnd__PointFromPrintableChar                           0x65C300
#define CEditWnd__SelectableCharFromPoint                          0x65C480
#define CEditWnd__SetEditable                                      0x65BE80

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4C1A10
#define CEverQuest__DropHeldItemOnGround                           0x4C65F0
#define CEverQuest__dsp_chat                                       0x4C7280
#define CEverQuest__DoTellWindow                                   0x4C6720
#define CEverQuest__EnterZone                                      0x4DA2E0
#define CEverQuest__GetBodyTypeDesc                                0x4BF0B0
#define CEverQuest__GetClassDesc                                   0x4BE810
#define CEverQuest__GetClassThreeLetterCode                        0x4BEE10
#define CEverQuest__GetDeityDesc                                   0x4BF720
#define CEverQuest__GetLangDesc                                    0x4BF440
#define CEverQuest__GetRaceDesc                                    0x4BF6F0
#define CEverQuest__InterpretCmd                                   0x4C7C00
#define CEverQuest__LeftClickedOnPlayer                            0x4D8E90
#define CEverQuest__LMouseUp                                       0x4DB050
#define CEverQuest__RightClickedOnPlayer                           0x4D9260
#define CEverQuest__RMouseUp                                       0x4DA900
#define CEverQuest__SetGameState                                   0x4C1AE0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x566DF0
#define CGaugeWnd__CalcLinesFillRect                               0x566E60
#define CGaugeWnd__Draw                                            0x5671F0

// CGuild
#define CGuild__FindMemberByName                                   0x4172A0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x57CCD0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5848B0
#define CInvSlotMgr__MoveItem                                      0x584A50

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x585950

// CInvSLot
#define CInvSlot__SliderComplete                                   0x583830

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x593410
#define CItemDisplayWnd__SetSpell                                  0x5DB800

// CLabel 
#define CLabel__Draw                                               0x598AA0

// CListWnd 
#define CListWnd__AddColumn                                        0x64E370
#define CListWnd__AddColumn1                                       0x64DEA0
#define CListWnd__AddLine                                          0x64DA30
#define CListWnd__AddString                                        0x64DC00
#define CListWnd__CalculateFirstVisibleLine                        0x64AD60
#define CListWnd__CalculateVSBRange                                0x64C9D0
#define CListWnd__ClearAllSel                                      0x64A4D0
#define CListWnd__CloseAndUpdateEditWindow                         0x64B370
#define CListWnd__Compare                                          0x64B720
#define CListWnd__Draw                                             0x64C6D0
#define CListWnd__DrawColumnSeparators                             0x64C540
#define CListWnd__DrawHeader                                       0x64A6A0
#define CListWnd__DrawItem                                         0x64BE30
#define CListWnd__DrawLine                                         0x64C1E0
#define CListWnd__DrawSeparator                                    0x64C5E0
#define CListWnd__EnsureVisible                                    0x64ADB0
#define CListWnd__ExtendSel                                        0x64BD60
#define CListWnd__GetColumnMinWidth                                0x64A270
#define CListWnd__GetColumnWidth                                   0x64A1B0
#define CListWnd__GetCurSel                                        0x649C90
#define CListWnd__GetHeaderRect                                    0x649D80
#define CListWnd__GetItemAtPoint                                   0x64B080
#define CListWnd__GetItemAtPoint1                                  0x64B0F0
#define CListWnd__GetItemData                                      0x649F60
#define CListWnd__GetItemHeight                                    0x64AB00
#define CListWnd__GetItemIcon                                      0x64A0F0
#define CListWnd__GetItemRect                                      0x64AE70
#define CListWnd__GetItemText                                      0x649FA0
#define CListWnd__GetSelList                                       0x64DD80
#define CListWnd__GetSeparatorRect                                 0x64B660
#define CListWnd__RemoveLine                                       0x64DD30
#define CListWnd__SetColors                                        0x649CF0
#define CListWnd__SetColumnJustification                           0x64A2D0
#define CListWnd__SetColumnWidth                                   0x64A230
#define CListWnd__SetCurSel                                        0x649CD0
#define CListWnd__SetItemColor                                     0x64D600
#define CListWnd__SetItemData                                      0x64A570
#define CListWnd__SetItemText                                      0x64D580
#define CListWnd__ShiftColumnSeparator                             0x64BCD0
#define CListWnd__Sort                                             0x64E3A0
#define CListWnd__ToggleSel                                        0x64A440

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5AB990

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5AD380
#define CMerchantWnd__RequestBuyItem                               0x5AE610
#define CMerchantWnd__RequestSellItem                              0x5AD5E0
#define CMerchantWnd__SelectBuySellSlot                            0x5AE350

// CObfuscator
#define CObfuscator__doit                                          0x62E9B0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x663290

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x653D40
#define CSidlScreenWnd__CalculateVSBRange                          0x653C90
#define CSidlScreenWnd__ConvertToRes                               0x6544A1
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x654CA0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x655F60
#define CSidlScreenWnd__CSidlScreenWnd2                            0x656010
#define CSidlScreenWnd__dCSidlScreenWnd                            0x655810
#define CSidlScreenWnd__DrawSidlPiece                              0x654980
#define CSidlScreenWnd__EnableIniStorage                           0x654440
#define CSidlScreenWnd__GetSidlPiece                               0x654B80
#define CSidlScreenWnd__Init1                                      0x655D70
#define CSidlScreenWnd__LoadIniInfo                                0x654D50
#define CSidlScreenWnd__LoadIniListWnd                             0x6545F0
#define CSidlScreenWnd__LoadSidlScreen                             0x6547B0
#define CSidlScreenWnd__StoreIniInfo                               0x653F80
#define CSidlScreenWnd__WndNotification                            0x6548E0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x512EB0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6742F0
#define CSliderWnd__SetValue                                       0x6743F0
#define CSliderWnd__SetNumTicks                                    0x674930

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5DA550

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x670810
#define CStmlWnd__CalculateVSBRange                                0x668B80
#define CStmlWnd__CanBreakAtCharacter                              0x668CC0
#define CStmlWnd__FastForwardToEndOfTag                            0x6697D0
#define CStmlWnd__GetNextTagPiece                                  0x6696F0
#define CStmlWnd__GetSTMLText                                      0x555610
#define CStmlWnd__GetThisChar                                      0x6907C0
#define CStmlWnd__GetVisiableText                                  0x66AA10
#define CStmlWnd__InitializeWindowVariables                        0x66CB70
#define CStmlWnd__MakeStmlColorTag                                 0x668280
#define CStmlWnd__MakeWndNotificationTag                           0x668320
#define CStmlWnd__StripFirstSTMLLines                              0x670590
#define CStmlWnd__UpdateHistoryString                              0x66B270

// CTabWnd 
#define CTabWnd__Draw                                              0x673B70
#define CTabWnd__DrawCurrentPage                                   0x673560
#define CTabWnd__DrawTab                                           0x673340
#define CTabWnd__GetCurrentPage                                    0x6737E0
#define CTabWnd__GetPageClientRect                                 0x673010
#define CTabWnd__GetPageFromTabIndex                               0x673270
#define CTabWnd__GetPageInnerRect                                  0x673070
#define CTabWnd__GetTabInnerRect                                   0x6731F0
#define CTabWnd__GetTabRect                                        0x673100
#define CTabWnd__IndexInBounds                                     0x67330D
#define CTabWnd__InsertPage                                        0x673D90
#define CTabWnd__SetPage                                           0x673820
#define CTabWnd__SetPageRect                                       0x673AA0
#define CTabWnd__UpdatePage                                        0x673D10

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x413E70

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x656370

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x679AC0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x649A00

// CXRect 
#define CXRect__CenterPoint                                        0x534190

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4122D0
#define CXStr__CXStr1                                              0x643670
#define CXStr__CXStr3                                              0x63E2F0
#define CXStr__dCXStr                                              0x64EDC0
#define CXStr__operator_equal1                                     0x63E4B0
#define CXStr__operator_plus_equal1                                0x63F3A0

// CXWnd 
#define CXWnd__BringToTop                                          0x64F340
#define CXWnd__Center                                              0x652A30
#define CXWnd__ClrFocus                                            0x64F070
#define CXWnd__DoAllDrawing                                        0x6536E0
#define CXWnd__DrawChildren                                        0x653810
#define CXWnd__DrawColoredRect                                     0x64F5A0
#define CXWnd__DrawTooltip                                         0x653600
#define CXWnd__DrawTooltipAtPoint                                  0x652880
#define CXWnd__GetBorderFrame                                      0x64FA60
#define CXWnd__GetChildWndAt                                       0x652380
#define CXWnd__GetClientClipRect                                   0x64F9A0
#define CXWnd__GetFirstChildWnd                                    0x64F3E0
#define CXWnd__GetNextChildWnd                                     0x652340
#define CXWnd__GetNextSib                                          0x64F400
#define CXWnd__GetScreenClipRect                                   0x652C50
#define CXWnd__GetScreenRect                                       0x64FC40
#define CXWnd__GetTooltipRect                                      0x64F7D0
#define CXWnd__GetWindowTextA                                      0x4E6A80
#define CXWnd__IsActive                                            0x657450
#define CXWnd__IsDescendantOf                                      0x64FA10
#define CXWnd__IsReallyVisible                                     0x652320
#define CXWnd__IsType                                              0x675800
#define CXWnd__Move                                                0x651E50
#define CXWnd__Move1                                               0x651EF0
#define CXWnd__ProcessTransition                                   0x64F310
#define CXWnd__Refade                                              0x64F120
#define CXWnd__Resize                                              0x652D90
#define CXWnd__Right                                               0x652BA0
#define CXWnd__SetFirstChildPointer                                0x64FE90
#define CXWnd__SetFocus                                            0x651180
#define CXWnd__SetKeyTooltip                                       0x64FF00
#define CXWnd__SetMouseOver                                        0x64FED0
#define CXWnd__SetNextSibPointer                                   0x64FEB0
#define CXWnd__StartFade                                           0x64F360

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x658920
#define CXWndManager__DrawWindows                                  0x658560
#define CXWndManager__GetFirstChildWnd                             0x657DF0
#define CXWndManager__GetKeyboardFlags                             0x657130
#define CXWndManager__HandleKeyboardMsg                            0x657640
#define CXWndManager__RemoveWnd                                    0x657560

// CDBStr
#define CDBStr__GetString                                          0x459540

// EQ_Character 
#define EQ_Character__CastRay                                      0x69C230
#define EQ_Character__CastSpell                                    0x4237D0
#define EQ_Character__Cur_HP                                       0x42B240
#define EQ_Character__GetAACastingTimeModifier                     0x41E970
#define EQ_Character__GetCharInfo2                                 0x61FE00
#define EQ_Character__GetFocusCastingTimeModifier                  0x41AA20
#define EQ_Character__GetFocusRangeModifier                        0x41AB50
#define EQ_Character__Max_Endurance                                0x429F10
#define EQ_Character__Max_HP                                       0x429DC0
#define EQ_Character__Max_Mana                                     0x4F67C0
#define EQ_Character__doCombatAbility                              0x4F5640
#define EQ_Character__UseSkill                                     0x436C70
#define EQ_Character__GetConLevel                                  0x4F2AF0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4E85F0
#define EQ_Item__GetItemLinkHash                                   0x614940
#define EQ_Item__IsStackable                                       0x60CCB0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x471B50
#define EQ_LoadingS__Array                                         0x73F160

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x4F96F0
#define EQ_PC__GetAltAbilityIndex                                  0x619180
#define EQ_PC__GetCombatAbility                                    0x619210
#define EQ_PC__GetCombatAbilityTimer                               0x6192C0
#define EQ_PC__GetItemTimerValue                                   0x4F4890
#define EQ_PC__HasLoreItem                                         0x4F7D10

// EQItemList 
#define EQItemList__dEQItemList                                    0x499A90
#define EQItemList__EQItemList                                     0x4999E0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x458FC0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x4FE1F0
#define EQPlayer__dEQPlayer                                        0x502880
#define EQPlayer__DoAttack                                         0x50DF50
#define EQPlayer__EQPlayer                                         0x505030
#define EQPlayer__SetNameSpriteState                               0x500900
#define EQPlayer__SetNameSpriteTint                                0x4FE260
#define EQPlayer__IsBodyType_j                                     0x69BC30

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x505FC0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4EA1A0
#define KeypressHandler__AttachKeyToEqCommand                      0x4EA1E0
#define KeypressHandler__ClearCommandStateArray                    0x4E9FB0
#define KeypressHandler__HandleKeyDown                             0x4E8BC0
#define KeypressHandler__HandleKeyUp                               0x4E8EC0
#define KeypressHandler__SaveKeymapping                            0x4EA080

// MapViewMap 
#define MapViewMap__Clear                                          0x5A79B0
#define MapViewMap__SaveEx                                         0x5A8380

#define OtherCharData__GetAltCurrency                              0x6358E0

// StringTable 
#define StringTable__getString                                     0x60C6D0
