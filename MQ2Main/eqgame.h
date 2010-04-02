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
#define __ExpectedVersionDate                                     "Mar 13 2007"
#define __ExpectedVersionTime                                     "11:19:32"
#define __ActualVersionDate                                        0x6CD66C
#define __ActualVersionTime                                        0x6CD678

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                              0x4E1DC0
#define __MemChecker1                                              0x5F2790
#define __MemChecker2                                              0x510B20
#define __MemChecker3                                              0x510BD0
#define __MemChecker4                                              0x5ED9A0
#define __EncryptPad0                                              0x721788
#define __EncryptPad1                                              0x72AE98
#define __EncryptPad2                                              0x723CD8
#define __EncryptPad3                                              0x7240D8
#define __EncryptPad4                                              0x72A690

// Direct Input
#define DI8__Main                                                  0x958D8C
#define DI8__Keyboard                                              0x958D90
#define DI8__Mouse                                                 0x958D94
#define __AltTimerReady                                            0x8F4FCA
#define __Attack                                                   0x95263A
#define __Autofire                                                 0x95263B
#define __BindList                                                 0x71CA18
#define __Clicks                                                   0x8F40F4
#define __CommandList                                              0x71D208
#define __CurrentMapLabel                                          0x963E54
#define __CurrentSocial                                            0x7194B8
#define __DoAbilityAvailable                                       0x8F4F64
#define __DoAbilityList                                            0x92A180
#define __DrawHandler                                              0x972AAC
#define __GroupCount                                               0x8D4840
#define __GroupLeader                                              0x8D499C
#define __Guilds                                                   0x8D6338
#define __gWorld                                                   0x8D6298
#define __HotkeyPage                                               0x95156C
#define __HWnd                                                     0x958D34
#define __InChatMode                                               0x8F4030
#define __LastTell                                                 0x8F5888
#define __Mouse                                                    0x958D98
#define __MouseLook                                                0x8F40C2
#define __NetStatusToggle                                          0x8F40C4
#define __PCNames                                                  0x8F52E0
#define __RangeAttackReady                                         0x8F4FC8
#define __RunWalkState                                             0x8F4034
#define __ScreenMode                                               0x824320
#define __ScreenX                                                  0x8F3FF8
#define __ScreenY                                                  0x8F3FFC
#define __ServerHost                                               0x8D4794
#define __ServerName                                               0x92A140
#define __ShowNames                                                0x8F51B8
#define __Socials                                                  0x92A240


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x8EDF88
#define instEQZoneInfo                                             0x8F4260
#define instKeypressHandler                                        0x95270C
#define pinstActiveBanker                                          0x8D6314
#define pinstActiveCorpse                                          0x8D6318
#define pinstActiveGMaster                                         0x8D631C
#define pinstActiveMerchant                                        0x8D6310
#define pinstAltAdvManager                                         0x824FF8
#define pinstAuraMgr                                               0x730050
#define pinstBandageTarget                                         0x8D62FC
#define pinstCamActor                                              0x824AEC
#define pinstCDBStr                                                0x8241A0
#define pinstCDisplay                                              0x8D6324
#define pinstCEverQuest                                            0x958F00
#define pinstCharData                                              0x8D62E0
#define pinstCharSpawn                                             0x8D6308
#define pinstControlledMissile                                     0x8D62DC
#define pinstControlledPlayer                                      0x8D6308
#define pinstCSidlManager                                          0x9722FC
#define pinstCXWndManager                                          0x9722F4
#define instDynamicZone                                            0x8F3A48
#define pinstDZMember                                              0x8F3B58
#define pinstDZTimerInfo                                           0x8F3B5C
#define pinstEQItemList                                            0x8D62C4
#define instEQMisc                                                 0x824158
#define pinstEQSoundManager                                        0x82501C
#define instExpeditionLeader                                       0x8F3A92
#define instExpeditionName                                         0x8F3AD2
#define instGroup                                                  0x8D4840
#define pinstGroup                                                 0x8D483C
#define pinstImeManager                                            0x972300
#define pinstLocalPlayer                                           0x8D62F4
#define pinstModelPlayer                                           0x8D6320
#define pinstPCData                                                0x8D62E0
#define pinstSelectedItem                                          0x963CAC
#define pinstSkillMgr                                              0x955DF0
#define pinstSpawnManager                                          0x955D6C
#define pinstSpellManager                                          0x955DF4
#define pinstSpellSets                                             0x951570
#define pinstStringTable                                           0x8D62A8
#define pinstSwitchManager                                         0x8D4490
#define pinstTarget                                                0x8D630C
#define pinstTargetObject                                          0x8D62E4
#define pinstTargetSwitch                                          0x8D62E8
#define pinstTaskMember                                            0x824138
#define pinstTrackTarget                                           0x8D6300
#define pinstTradeTarget                                           0x8D62F0
#define instTributeActive                                          0x82417D
#define pinstViewActor                                             0x824AE8
#define pinstWorldData                                             0x8D62C0


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x72E588
#define pinstCAudioTriggersWindow                                  0x72E56C
#define pinstCCharacterSelect                                      0x8249F8
#define pinstCFacePick                                             0x8249B0
#define pinstCNoteWnd                                              0x8249B4
#define pinstCBookWnd                                              0x8249B8
#define pinstCPetInfoWnd                                           0x8249BC
#define pinstCTrainWnd                                             0x8249C0
#define pinstCSkillsWnd                                            0x8249C4
#define pinstCSkillsSelectWnd                                      0x8249C8
#define pinstCCombatSkillSelectWnd                                 0x8249CC
#define pinstCFriendsWnd                                           0x8249D0
#define pinstCAuraWnd                                              0x8249D4
#define pinstCRespawnWnd                                           0x8249D8
#define pinstCBandolierWnd                                         0x8249DC
#define pinstCPotionBeltWnd                                        0x8249E0
#define pinstCAAWnd                                                0x8249E4
#define pinstCGroupSearchFiltersWnd                                0x8249E8
#define pinstCLoadskinWnd                                          0x8249EC
#define pinstCAlarmWnd                                             0x8249F0
#define pinstCMusicPlayerWnd                                       0x8249F4
#define pinstCMailWnd                                              0x8249FC
#define pinstCMailCompositionWnd                                   0x824A00
#define pinstCMailAddressBookWnd                                   0x824A04
#define pinstCRaidWnd                                              0x824A0C
#define pinstCRaidOptionsWnd                                       0x824A10
#define pinstCBreathWnd                                            0x824A14
#define pinstCMapViewWnd                                           0x824A18
#define pinstCMapToolbarWnd                                        0x824A1C
#define pinstCEditLabelWnd                                         0x824A20
#define pinstCTargetWnd                                            0x824A24
#define pinstCColorPickerWnd                                       0x824A28
#define pinstCPlayerWnd                                            0x824A2C
#define pinstCOptionsWnd                                           0x824A30
#define pinstCBuffWindowNORMAL                                     0x824A34
#define pinstCBuffWindowSHORT                                      0x824A38
#define pinstCharacterCreation                                     0x824A3C
#define pinstCCursorAttachment                                     0x824A40
#define pinstCCastingWnd                                           0x824A44
#define pinstCCastSpellWnd                                         0x824A48
#define pinstCSpellBookWnd                                         0x824A4C
#define pinstCInventoryWnd                                         0x824A50
#define pinstCBankWnd                                              0x824A54
#define pinstCQuantityWnd                                          0x824A58
#define pinstCLootWnd                                              0x824A5C
#define pinstCActionsWnd                                           0x824A60
#define pinstCCombatAbilityWnd                                     0x824A64
#define pinstCMerchantWnd                                          0x824A68
#define pinstCTradeWnd                                             0x824A6C
#define pinstCSelectorWnd                                          0x824A70
#define pinstCBazaarWnd                                            0x824A74
#define pinstCBazaarSearchWnd                                      0x824A78
#define pinstCGiveWnd                                              0x824A7C
#define pinstCTrackingWnd                                          0x824A80
#define pinstCInspectWnd                                           0x824A84
#define pinstCSocialEditWnd                                        0x824A88
#define pinstCFeedbackWnd                                          0x824A8C
#define pinstCBugReportWnd                                         0x824A90
#define pinstCVideoModesWnd                                        0x824A94
#define pinstCTextEntryWnd                                         0x824A9C
#define pinstCFileSelectionWnd                                     0x824AA0
#define pinstCCompassWnd                                           0x824AA4
#define pinstCPlayerNotesWnd                                       0x824AA8
#define pinstCGemsGameWnd                                          0x824AAC
#define pinstCTimeLeftWnd                                          0x824AB0
#define pinstCPetitionQWnd                                         0x824AB4
#define pinstCSoulmarkWnd                                          0x824AB8
#define pinstCStoryWnd                                             0x824ABC
#define pinstCJournalTextWnd                                       0x824AC0
#define pinstCJournalCatWnd                                        0x824AC4
#define pinstCBodyTintWnd                                          0x824AC8
#define pinstCServerListWnd                                        0x824ACC
#define pinstCAvaZoneWnd                                           0x824AD0
#define pinstCBlockedBuffWnd                                       0x824AD4
#define pinstCBlockedPetBuffWnd                                    0x824AD8
#define pinstCInvSlotMgr                                           0x824ADC
#define pinstCContainerMgr                                         0x824AE0
#define pinstCAdventureLeaderboardWnd                              0x9614CC
#define pinstCAdventureRequestWnd                                  0x9614E8
#define pinstCAltStorageWnd                                        0x961548
#define pinstCAdventureStatsWnd                                    0x961504
#define pinstCBarterMerchantWnd                                    0x9616FC
#define pinstCBarterSearchWnd                                      0x961718
#define pinstCBarterWnd                                            0x961734
#define pinstCChatManager                                          0x961914
#define pinstCDynamicZoneWnd                                       0x9619F0
#define pinstCEQMainWnd                                            0x961A60
#define pinstCFellowshipWnd                                        0x961AC4
#define pinstCFindLocationWnd                                      0x961AF8
#define pinstCGroupSearchWnd                                       0x961BCC
#define pinstCGroupWnd                                             0x961BC4
#define pinstCGuildBankWnd                                         0x961BE0
#define pinstCGuildMgmtWnd                                         0x963C00
#define pinstCGuildTributeMasterWnd                                0x963C20
#define pinstCHotButtonWnd                                         0x963C3C
#define pinstCHotButtonWnd1                                        0x963C3C
#define pinstCHotButtonWnd2                                        0x963C40
#define pinstCHotButtonWnd3                                        0x963C44
#define pinstCHotButtonWnd4                                        0x963C48
#define pinstCItemDisplayManager                                   0x963CE0
#define pinstCItemExpTransferWnd                                   0x963D00
#define pinstCLeadershipWnd                                        0x963D7C
#define pinstCLFGuildWnd                                           0x963D98
#define pinstCMIZoneSelectWnd                                      0x963EBC
#define pinstCAdventureMerchantWnd                                 0x963FB4
#define pinstCConfirmationDialog                                   0x963FD0
#define pinstCPopupWndManager                                      0x963FD0
#define pinstCProgressionSelectionWnd                              0x964004
#define pinstCPvPLeaderboardWnd                                    0x964020
#define pinstCPvPStatsWnd                                          0x96403C
#define pinstCSystemInfoDialogBox                                  0x9649BC
#define pinstCTargetOfTargetWnd                                    0x9649D8
#define pinstCTaskSelectWnd                                        0x964A0C
#define pinstCTaskTemplateSelectWnd                                0x964A28
#define pinstCTaskWnd                                              0x964A44
#define pinstCTipWndOFDAY                                          0x964A90
#define pinstCTipWndCONTEXT                                        0x964A94
#define pinstCTitleWnd                                             0x964AB0
#define pinstCTradeskillWnd                                        0x964AF4
#define pinstCTributeBenefitWnd                                    0x964B40
#define pinstCTributeMasterWnd                                     0x964B5C
#define pinstCContextMenuManager                                   0x9723BC
#define pinstCVoiceMacroWnd                                        0x955EA4


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4A5D40
#define __ConvertItemTags                                          0x49AA00
#define __ExecuteCmd                                               0x48C450
#define __get_melee_range                                          0x491480
#define __GetGaugeValueFromEQ                                      0x5C7DD0
#define __GetLabelFromEQ                                           0x5C8500
#define __NewUIINI                                                 0x5C79D0
#define __ProcessGameEvents                                        0x4D0A30
#define __SendMessage                                              0x4B32F0
#define CrashDetected                                              0x5107C0
#define DrawNetStatus                                              0x4E4A40
#define Util__FastTime                                             0x5F2E20


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x46D010
#define AltAdvManager__IsAbilityReady                              0x46D050
#define AltAdvManager__GetAltAbility                               0x46D1A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x524D00

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x52E140

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x63BD10

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x541EA0
#define CChatManager__InitContextMenu                              0x542630

// CChatService
#define CChatService__GetNumberOfFriends                           0x617DA0
#define CChatService__GetFriendName                                0x617DB0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5467B0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x631830
#define CComboWnd__Draw                                            0x6319E0
#define CComboWnd__GetCurChoice                                    0x6317E0
#define CComboWnd__GetListRect                                     0x631CC0
#define CComboWnd__GetTextRect                                     0x631860
#define CComboWnd__InsertChoice                                    0x631D30
#define CComboWnd__SetColors                                       0x631770
#define CComboWnd__SetChoice                                       0x6317A0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x54CE10
#define CContainerWnd__vftable                                     0x6D38B8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x45C750
#define CDisplay__GetClickedActor                                  0x459FF0
#define CDisplay__GetUserDefinedColor                              0x459460
#define CDisplay__GetWorldFilePath                                 0x458A10
#define CDisplay__ReloadUI                                         0x4684D0
#define CDisplay__WriteTextHD2                                     0x45DEF0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x51EDC0
#define CEditBaseWnd__SetSel                                       0x6542F0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x651A20
#define CEditWnd__GetCharIndexPt                                   0x652860
#define CEditWnd__GetDisplayString                                 0x651BB0
#define CEditWnd__GetHorzOffset                                    0x651E30
#define CEditWnd__GetLineForPrintableChar                          0x652310
#define CEditWnd__GetSelStartPt                                    0x652AA0
#define CEditWnd__GetSTMLSafeText                                  0x651FD0
#define CEditWnd__PointFromPrintableChar                           0x652420
#define CEditWnd__SelectableCharFromPoint                          0x6525A0
#define CEditWnd__SetEditable                                      0x651FA0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4B7370
#define CEverQuest__DropHeldItemOnGround                           0x4BBCD0
#define CEverQuest__dsp_chat                                       0x4BC8B0
#define CEverQuest__EnterZone                                      0x4CF620
#define CEverQuest__GetBodyTypeDesc                                0x4B4AF0
#define CEverQuest__GetClassDesc                                   0x4B4250
#define CEverQuest__GetClassThreeLetterCode                        0x4B4850
#define CEverQuest__GetDeityDesc                                   0x4B5140
#define CEverQuest__GetLangDesc                                    0x4B4E60
#define CEverQuest__GetRaceDesc                                    0x4B5110
#define CEverQuest__InterpretCmd                                   0x4BD1C0
#define CEverQuest__LeftClickedOnPlayer                            0x4CE1F0
#define CEverQuest__RightClickedOnPlayer                           0x4CE5B0
#define CEverQuest__SetGameState                                   0x4B7440

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x557D80
#define CGaugeWnd__CalcLinesFillRect                               0x557DF0
#define CGaugeWnd__Draw                                            0x558180

// CGuild
#define CGuild__FindMemberByName                                   0x415940

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x56DBA0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5755D0
#define CInvSlotMgr__MoveItem                                      0x575770

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x576660

// CInvSLot
#define CInvSlot__SliderComplete                                   0x5745F0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x57DB20
#define CItemDisplayWnd__SetSpell                                  0x5C5CF0

// CLabel 
#define CLabel__Draw                                               0x583090

// CListWnd 
#define CListWnd__AddColumn                                        0x631580
#define CListWnd__AddColumn1                                       0x6310C0
#define CListWnd__AddLine                                          0x630C50
#define CListWnd__AddString                                        0x630E20
#define CListWnd__CalculateFirstVisibleLine                        0x62DF80
#define CListWnd__CalculateVSBRange                                0x62FBF0
#define CListWnd__ClearAllSel                                      0x62D6F0
#define CListWnd__CloseAndUpdateEditWindow                         0x62E590
#define CListWnd__Compare                                          0x62E940
#define CListWnd__Draw                                             0x62F8F0
#define CListWnd__DrawColumnSeparators                             0x62F760
#define CListWnd__DrawHeader                                       0x62D8C0
#define CListWnd__DrawItem                                         0x62F050
#define CListWnd__DrawLine                                         0x62F4A1
#define CListWnd__DrawSeparator                                    0x62F4A1
#define CListWnd__EnsureVisible                                    0x62DFD0
#define CListWnd__ExtendSel                                        0x62EF80
#define CListWnd__GetColumnMinWidth                                0x62D490
#define CListWnd__GetColumnWidth                                   0x62D3D0
#define CListWnd__GetCurSel                                        0x62CEB0
#define CListWnd__GetHeaderRect                                    0x62CFA0
#define CListWnd__GetItemAtPoint                                   0x62E2A0
#define CListWnd__GetItemAtPoint1                                  0x62E310
#define CListWnd__GetItemData                                      0x62D180
#define CListWnd__GetItemHeight                                    0x62DD20
#define CListWnd__GetItemIcon                                      0x62D310
#define CListWnd__GetItemRect                                      0x62E090
#define CListWnd__GetItemText                                      0x62D1C0
#define CListWnd__GetSelList                                       0x630FA0
#define CListWnd__GetSeparatorRect                                 0x62E880
#define CListWnd__RemoveLine                                       0x630F50
#define CListWnd__SetColors                                        0x62CF10
#define CListWnd__SetColumnJustification                           0x62D4F0
#define CListWnd__SetColumnWidth                                   0x62D450
#define CListWnd__SetCurSel                                        0x62CEF0
#define CListWnd__SetItemColor                                     0x630820
#define CListWnd__SetItemData                                      0x62D790
#define CListWnd__SetItemText                                      0x6307A0
#define CListWnd__ShiftColumnSeparator                             0x62EEF0
#define CListWnd__Sort                                             0x6315B0
#define CListWnd__ToggleSel                                        0x62D660

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x595E10

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5977E0
#define CMerchantWnd__RequestBuyItem                               0x5989A0
#define CMerchantWnd__RequestSellItem                              0x597A40
#define CMerchantWnd__SelectBuySellSlot                            0x5986E0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x640910

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5207F0
#define CSidlScreenWnd__CalculateVSBRange                          0x520740
#define CSidlScreenWnd__ConvertToRes                               0x637561
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x637D60
#define CSidlScreenWnd__CSidlScreenWnd1                            0x639020
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6390D0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6388D0
#define CSidlScreenWnd__DrawSidlPiece                              0x637A40
#define CSidlScreenWnd__EnableIniStorage                           0x637500
#define CSidlScreenWnd__GetSidlPiece                               0x637C40
#define CSidlScreenWnd__Init1                                      0x638E30
#define CSidlScreenWnd__LoadIniInfo                                0x637E10
#define CSidlScreenWnd__LoadIniListWnd                             0x6376B0
#define CSidlScreenWnd__LoadSidlScreen                             0x637870
#define CSidlScreenWnd__StoreIniInfo                               0x637040
#define CSidlScreenWnd__WndNotification                            0x6379A0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x505D20

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x656180
#define CSliderWnd__SetValue                                       0x656280
#define CSliderWnd__SetNumTicks                                    0x6567C0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5C4A50

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x64AD40
#define CStmlWnd__CalculateVSBRange                                0x6430A0
#define CStmlWnd__CanBreakAtCharacter                              0x6431E0
#define CStmlWnd__FastForwardToEndOfTag                            0x643D00
#define CStmlWnd__GetNextTagPiece                                  0x643C20
#define CStmlWnd__GetSTMLText                                      0x546750
#define CStmlWnd__GetThisChar                                      0x673180
#define CStmlWnd__GetVisiableText                                  0x644F40
#define CStmlWnd__InitializeWindowVariables                        0x6470A0
#define CStmlWnd__MakeStmlColorTag                                 0x6427A0
#define CStmlWnd__MakeWndNotificationTag                           0x642840
#define CStmlWnd__StripFirstSTMLLines                              0x64AAC0
#define CStmlWnd__UpdateHistoryString                              0x6457A0

// CTabWnd 
#define CTabWnd__Draw                                              0x6559F0
#define CTabWnd__DrawCurrentPage                                   0x655360
#define CTabWnd__DrawTab                                           0x655140
#define CTabWnd__GetCurrentPage                                    0x655660
#define CTabWnd__GetPageClientRect                                 0x654E10
#define CTabWnd__GetPageFromTabIndex                               0x655070
#define CTabWnd__GetPageInnerRect                                  0x654E70
#define CTabWnd__GetTabInnerRect                                   0x654FF0
#define CTabWnd__GetTabRect                                        0x654F00
#define CTabWnd__IndexInBounds                                     0x65510D
#define CTabWnd__InsertPage                                        0x655C10
#define CTabWnd__SetPage                                           0x6556A0
#define CTabWnd__SetPageRect                                       0x655920
#define CTabWnd__UpdatePage                                        0x655B90

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4125F0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x639430

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x65C9A0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x62CC20

// CXRect 
#define CXRect__CenterPoint                                        0x5244C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x412190
#define CXStr__CXStr1                                              0x501670
#define CXStr__CXStr3                                              0x5F44D0
#define CXStr__dCXStr                                              0x643310
#define CXStr__operator_equal1                                     0x5F4690
#define CXStr__operator_plus_equal1                                0x5F5580

// CXWnd 
#define CXWnd__BringToTop                                          0x632520
#define CXWnd__Center                                              0x635C10
#define CXWnd__ClrFocus                                            0x632250
#define CXWnd__DoAllDrawing                                        0x6368C0
#define CXWnd__DrawChildren                                        0x6369F0
#define CXWnd__DrawColoredRect                                     0x632780
#define CXWnd__DrawTooltip                                         0x6367E0
#define CXWnd__DrawTooltipAtPoint                                  0x635A60
#define CXWnd__GetBorderFrame                                      0x632CC0
#define CXWnd__GetChildWndAt                                       0x635560
#define CXWnd__GetClientClipRect                                   0x632B80
#define CXWnd__GetFirstChildWnd                                    0x6325C0
#define CXWnd__GetNextChildWnd                                     0x635520
#define CXWnd__GetNextSib                                          0x6325E0
#define CXWnd__GetScreenClipRect                                   0x635E30
#define CXWnd__GetScreenRect                                       0x632E20
#define CXWnd__GetTooltipRect                                      0x6329B0
#define CXWnd__GetWindowTextA                                      0x517F80
#define CXWnd__IsActive                                            0x64CD00
#define CXWnd__IsDescendantOf                                      0x632BF0
#define CXWnd__IsReallyVisible                                     0x635500
#define CXWnd__IsType                                              0x657640
#define CXWnd__Move                                                0x635030
#define CXWnd__Move1                                               0x6350D0
#define CXWnd__ProcessTransition                                   0x6324F0
#define CXWnd__Refade                                              0x632300
#define CXWnd__Resize                                              0x635F70
#define CXWnd__Right                                               0x635D80
#define CXWnd__SetFirstChildPointer                                0x633090
#define CXWnd__SetFocus                                            0x634380
#define CXWnd__SetKeyTooltip                                       0x633100
#define CXWnd__SetMouseOver                                        0x6330D0
#define CXWnd__SetNextSibPointer                                   0x6330B0
#define CXWnd__StartFade                                           0x632540

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x64E150
#define CXWndManager__DrawWindows                                  0x64DD90
#define CXWndManager__GetFirstChildWnd                             0x64D6A0
#define CXWndManager__GetKeyboardFlags                             0x64C9E0
#define CXWndManager__HandleKeyboardMsg                            0x64CEF0
#define CXWndManager__RemoveWnd                                    0x64CE10

// CDBStr
#define CDBStr__GetString                                          0x455F90

// EQ_Character 
#define EQ_Character__CastRay                                      0x67EBE0
#define EQ_Character__CastSpell                                    0x4219B0
#define EQ_Character__Cur_HP                                       0x428D90
#define EQ_Character__GetAACastingTimeModifier                     0x41C920
#define EQ_Character__GetCharInfo2                                 0x600110
#define EQ_Character__GetFocusCastingTimeModifier                  0x418FC0
#define EQ_Character__GetFocusRangeModifier                        0x4190F0
#define EQ_Character__Max_Endurance                                0x427C00
#define EQ_Character__Max_HP                                       0x427AB0
#define EQ_Character__Max_Mana                                     0x4E99E0
#define EQ_Character__doCombatAbility                              0x4E8860
#define EQ_Character__UseSkill                                     0x4340F0
#define EQ_Character__GetConLevel                                  0x4E5E10

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4DBA10
#define EQ_Item__GetItemLinkHash                                   0x5FF370
#define EQ_Item__IsStackable                                       0x5F9850

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x46E0C0
#define EQ_LoadingS__Array                                         0x71AF30

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x4EC870
#define EQ_PC__GetAltAbilityIndex                                  0x605100
#define EQ_PC__GetCombatAbility                                    0x605190
#define EQ_PC__GetCombatAbilityTimer                               0x605240
#define EQ_PC__GetItemTimerValue                                   0x4E7BC0
#define EQ_PC__HasLoreItem                                         0x4EAEB0

// EQItemList 
#define EQItemList__dEQItemList                                    0x48FD20
#define EQItemList__EQItemList                                     0x48FC70

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x455A20

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x4F1200
#define EQPlayer__dEQPlayer                                        0x4F5630
#define EQPlayer__DoAttack                                         0x5009B0
#define EQPlayer__EQPlayer                                         0x4F7D30
#define EQPlayer__SetNameSpriteState                               0x4F38F0
#define EQPlayer__SetNameSpriteTint                                0x4F1270
#define EQPlayer__IsBodyType_j                                     0x67E610

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4F8B30

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4DD5A0
#define KeypressHandler__AttachKeyToEqCommand                      0x4DD5E0
#define KeypressHandler__ClearCommandStateArray                    0x4DD3B0
#define KeypressHandler__HandleKeyDown                             0x4DBFC0
#define KeypressHandler__HandleKeyUp                               0x4DC2C0
#define KeypressHandler__SaveKeymapping                            0x4DD480

// MapViewMap 
#define MapViewMap__Clear                                          0x591E50
#define MapViewMap__SaveEx                                         0x592820

// StringTable 
#define StringTable__getString                                     0x5F9250
