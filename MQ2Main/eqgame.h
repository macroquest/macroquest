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
#define __ExpectedVersionDate                                     "Apr 19 2007"
#define __ExpectedVersionTime                                     "14:31:05"
#define __ActualVersionDate                                        0x6D086C
#define __ActualVersionTime                                        0x6D0878

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                              0x4E59C0
#define __MemChecker1                                              0x619990
#define __MemChecker2                                              0x514410
#define __MemChecker3                                              0x5144C0
#define __MemChecker4                                              0x681BF0
#define __EncryptPad0                                              0x728988
#define __EncryptPad1                                              0x7309F0
#define __EncryptPad2                                              0x72AED8
#define __EncryptPad3                                              0x72B2D8
#define __EncryptPad4                                              0x733720

// Direct Input
#define DI8__Main                                                  0x95FFDC
#define DI8__Keyboard                                              0x95FFE0
#define DI8__Mouse                                                 0x95FFE4
#define __AltTimerReady                                            0x8FC212
#define __Attack                                                   0x95988A
#define __Autofire                                                 0x95988B
#define __BindList                                                 0x723C18
#define __Clicks                                                   0x8FB33C
#define __CommandList                                              0x724408
#define __CurrentMapLabel                                          0x96B08C
#define __CurrentSocial                                            0x7204B8
#define __DoAbilityAvailable                                       0x8FC1AC
#define __DoAbilityList                                            0x9313D0
#define __DrawHandler                                              0x978EDC
#define __GroupCount                                               0x8DBA88
#define __GroupLeader                                              0x8DBBE4
#define __Guilds                                                   0x8DD580
#define __gWorld                                                   0x8DD4E0
#define __HotkeyPage                                               0x9587BC
#define __HWnd                                                     0x95FF84
#define __InChatMode                                               0x8FB278
#define __LastTell                                                 0x8FCAD8
#define __Mouse                                                    0x95FFE8
#define __MouseLook                                                0x8FB30A
#define __NetStatusToggle                                          0x8FB30C
#define __PCNames                                                  0x8FC530
#define __RangeAttackReady                                         0x8FC210
#define __RunWalkState                                             0x8FB27C
#define __ScreenMode                                               0x82B560
#define __ScreenX                                                  0x8FB240
#define __ScreenY                                                  0x8FB244
#define __ServerHost                                               0x8DB9DC
#define __ServerName                                               0x931390
#define __ShowNames                                                0x8FC404
#define __Socials                                                  0x931490


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x8F51D0
#define instEQZoneInfo                                             0x8FB4A8
#define instKeypressHandler                                        0x95995C
#define pinstActiveBanker                                          0x8DD55C
#define pinstActiveCorpse                                          0x8DD560
#define pinstActiveGMaster                                         0x8DD564
#define pinstActiveMerchant                                        0x8DD558
#define pinstAltAdvManager                                         0x82C240
#define pinstAuraMgr                                               0x73728C
#define pinstBandageTarget                                         0x8DD544
#define pinstCamActor                                              0x82BD34
#define pinstCDBStr                                                0x82B3E0
#define pinstCDisplay                                              0x8DD56C
#define pinstCEverQuest                                            0x960150
#define pinstCharData                                              0x8DD528
#define pinstCharSpawn                                             0x8DD550
#define pinstControlledMissile                                     0x8DD524
#define pinstControlledPlayer                                      0x8DD550
#define pinstCSidlManager                                          0x9792E8
#define pinstCXWndManager                                          0x9792E0
#define instDynamicZone                                            0x8FAC90
#define pinstDZMember                                              0x8FADA0
#define pinstDZTimerInfo                                           0x8FADA4
#define pinstEQItemList                                            0x8DD50C
#define instEQMisc                                                 0x82B398
#define pinstEQSoundManager                                        0x82C264
#define instExpeditionLeader                                       0x8FACDA
#define instExpeditionName                                         0x8FAD1A
#define instGroup                                                  0x8DBA88
#define pinstGroup                                                 0x8DBA84
#define pinstImeManager                                            0x9792EC
#define pinstLocalPlayer                                           0x8DD53C
#define pinstModelPlayer                                           0x8DD568
#define pinstPCData                                                0x8DD528
#define pinstSelectedItem                                          0x96AEE4
#define pinstSkillMgr                                              0x95D040
#define pinstSpawnManager                                          0x95CFBC
#define pinstSpellManager                                          0x95D044
#define pinstSpellSets                                             0x9587C0
#define pinstStringTable                                           0x8DD4F0
#define pinstSwitchManager                                         0x8DB6D8
#define pinstTarget                                                0x8DD554
#define pinstTargetObject                                          0x8DD52C
#define pinstTargetSwitch                                          0x8DD530
#define pinstTaskMember                                            0x82B378
#define pinstTrackTarget                                           0x8DD548
#define pinstTradeTarget                                           0x8DD538
#define instTributeActive                                          0x82B3BD
#define pinstViewActor                                             0x82BD30
#define pinstWorldData                                             0x8DD508


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x7357C0
#define pinstCAudioTriggersWindow                                  0x73578C
#define pinstCCharacterSelect                                      0x82BC40
#define pinstCFacePick                                             0x82BBF8
#define pinstCNoteWnd                                              0x82BBFC
#define pinstCBookWnd                                              0x82BC00
#define pinstCPetInfoWnd                                           0x82BC04
#define pinstCTrainWnd                                             0x82BC08
#define pinstCSkillsWnd                                            0x82BC0C
#define pinstCSkillsSelectWnd                                      0x82BC10
#define pinstCCombatSkillSelectWnd                                 0x82BC14
#define pinstCFriendsWnd                                           0x82BC18
#define pinstCAuraWnd                                              0x82BC1C
#define pinstCRespawnWnd                                           0x82BC20
#define pinstCBandolierWnd                                         0x82BC24
#define pinstCPotionBeltWnd                                        0x82BC28
#define pinstCAAWnd                                                0x82BC2C
#define pinstCGroupSearchFiltersWnd                                0x82BC30
#define pinstCLoadskinWnd                                          0x82BC34
#define pinstCAlarmWnd                                             0x82BC38
#define pinstCMusicPlayerWnd                                       0x82BC3C
#define pinstCMailWnd                                              0x82BC44
#define pinstCMailCompositionWnd                                   0x82BC48
#define pinstCMailAddressBookWnd                                   0x82BC4C
#define pinstCRaidWnd                                              0x82BC54
#define pinstCRaidOptionsWnd                                       0x82BC58
#define pinstCBreathWnd                                            0x82BC5C
#define pinstCMapViewWnd                                           0x82BC60
#define pinstCMapToolbarWnd                                        0x82BC64
#define pinstCEditLabelWnd                                         0x82BC68
#define pinstCTargetWnd                                            0x82BC6C
#define pinstCColorPickerWnd                                       0x82BC70
#define pinstCPlayerWnd                                            0x82BC74
#define pinstCOptionsWnd                                           0x82BC78
#define pinstCBuffWindowNORMAL                                     0x82BC7C
#define pinstCBuffWindowSHORT                                      0x82BC80
#define pinstCharacterCreation                                     0x82BC84
#define pinstCCursorAttachment                                     0x82BC88
#define pinstCCastingWnd                                           0x82BC8C
#define pinstCCastSpellWnd                                         0x82BC90
#define pinstCSpellBookWnd                                         0x82BC94
#define pinstCInventoryWnd                                         0x82BC98
#define pinstCBankWnd                                              0x82BC9C
#define pinstCQuantityWnd                                          0x82BCA0
#define pinstCLootWnd                                              0x82BCA4
#define pinstCActionsWnd                                           0x82BCA8
#define pinstCCombatAbilityWnd                                     0x82BCAC
#define pinstCMerchantWnd                                          0x82BCB0
#define pinstCTradeWnd                                             0x82BCB4
#define pinstCSelectorWnd                                          0x82BCB8
#define pinstCBazaarWnd                                            0x82BCBC
#define pinstCBazaarSearchWnd                                      0x82BCC0
#define pinstCGiveWnd                                              0x82BCC4
#define pinstCTrackingWnd                                          0x82BCC8
#define pinstCInspectWnd                                           0x82BCCC
#define pinstCSocialEditWnd                                        0x82BCD0
#define pinstCFeedbackWnd                                          0x82BCD4
#define pinstCBugReportWnd                                         0x82BCD8
#define pinstCVideoModesWnd                                        0x82BCDC
#define pinstCTextEntryWnd                                         0x82BCE4
#define pinstCFileSelectionWnd                                     0x82BCE8
#define pinstCCompassWnd                                           0x82BCEC
#define pinstCPlayerNotesWnd                                       0x82BCF0
#define pinstCGemsGameWnd                                          0x82BCF4
#define pinstCTimeLeftWnd                                          0x82BCF8
#define pinstCPetitionQWnd                                         0x82BCFC
#define pinstCSoulmarkWnd                                          0x82BD00
#define pinstCStoryWnd                                             0x82BD04
#define pinstCJournalTextWnd                                       0x82BD08
#define pinstCJournalCatWnd                                        0x82BD0C
#define pinstCBodyTintWnd                                          0x82BD10
#define pinstCServerListWnd                                        0x82BD14
#define pinstCAvaZoneWnd                                           0x82BD18
#define pinstCBlockedBuffWnd                                       0x82BD1C
#define pinstCBlockedPetBuffWnd                                    0x82BD20
#define pinstCInvSlotMgr                                           0x82BD24
#define pinstCContainerMgr                                         0x82BD28
#define pinstCAdventureLeaderboardWnd                              0x96871C
#define pinstCAdventureRequestWnd                                  0x968738
#define pinstCAltStorageWnd                                        0x968798
#define pinstCAdventureStatsWnd                                    0x968754
#define pinstCBarterMerchantWnd                                    0x96894C
#define pinstCBarterSearchWnd                                      0x968968
#define pinstCBarterWnd                                            0x968984
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
#define pinstCContextMenuManager                                   0x979344
#define pinstCVoiceMacroWnd                                        0x95D0F4


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4A8FE0
#define __ConvertItemTags                                          0x49DA30
#define __ExecuteCmd                                               0x48F1D0
#define __get_melee_range                                          0x494220
#define __GetGaugeValueFromEQ                                      0x5CAB60
#define __GetLabelFromEQ                                           0x5CB290
#define __NewUIINI                                                 0x5CA760
#define __ProcessGameEvents                                        0x4D4290
#define __SendMessage                                              0x4B6620
#define CrashDetected                                              0x5140C0
#define DrawNetStatus                                              0x4E8650
#define Util__FastTime                                             0x61A020


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x46F2E0
#define AltAdvManager__IsAbilityReady                              0x46F320
#define AltAdvManager__GetAltAbility                               0x46F4B0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x528490

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x531900

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x64AEF0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5445D0
#define CChatManager__InitContextMenu                              0x544D60

// CChatService
#define CChatService__GetNumberOfFriends                           0x60A260
#define CChatService__GetFriendName                                0x60A270

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x548EE0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6320F0
#define CComboWnd__Draw                                            0x6322A0
#define CComboWnd__GetCurChoice                                    0x6320A0
#define CComboWnd__GetListRect                                     0x632580
#define CComboWnd__GetTextRect                                     0x632120
#define CComboWnd__InsertChoice                                    0x6325F0
#define CComboWnd__SetColors                                       0x632030
#define CComboWnd__SetChoice                                       0x632060

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x54F550
#define CContainerWnd__vftable                                     0x6D68E8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x45E890
#define CDisplay__GetClickedActor                                  0x45C090
#define CDisplay__GetUserDefinedColor                              0x45B500
#define CDisplay__GetWorldFilePath                                 0x45AAB0
#define CDisplay__is3dON                                           0x4596D0
#define CDisplay__ReloadUI                                         0x46A630
#define CDisplay__WriteTextHD2                                     0x460030

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5226C0
#define CEditBaseWnd__SetSel                                       0x655DD0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x63F3C0
#define CEditWnd__GetCharIndexPt                                   0x640200
#define CEditWnd__GetDisplayString                                 0x63F550
#define CEditWnd__GetHorzOffset                                    0x63F7D0
#define CEditWnd__GetLineForPrintableChar                          0x63FCB0
#define CEditWnd__GetSelStartPt                                    0x640440
#define CEditWnd__GetSTMLSafeText                                  0x63F970
#define CEditWnd__PointFromPrintableChar                           0x63FDC0
#define CEditWnd__SelectableCharFromPoint                          0x63FF40
#define CEditWnd__SetEditable                                      0x63F940

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4BA700
#define CEverQuest__DropHeldItemOnGround                           0x4BF2B0
#define CEverQuest__dsp_chat                                       0x4BFF30
#define CEverQuest__EnterZone                                      0x4D2E40
#define CEverQuest__GetBodyTypeDesc                                0x4B7E40
#define CEverQuest__GetClassDesc                                   0x4B75A0
#define CEverQuest__GetClassThreeLetterCode                        0x4B7BA0
#define CEverQuest__GetDeityDesc                                   0x4B8490
#define CEverQuest__GetLangDesc                                    0x4B81B0
#define CEverQuest__GetRaceDesc                                    0x4B8460
#define CEverQuest__InterpretCmd                                   0x4C0890
#define CEverQuest__LeftClickedOnPlayer                            0x4D1A30
#define CEverQuest__RightClickedOnPlayer                           0x4D1DF0
#define CEverQuest__SetGameState                                   0x4BA7D0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x55A5E0
#define CGaugeWnd__CalcLinesFillRect                               0x55A650
#define CGaugeWnd__Draw                                            0x55A9E0

// CGuild
#define CGuild__FindMemberByName                                   0x417270

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5704B0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x577F70
#define CInvSlotMgr__MoveItem                                      0x578110

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x579010

// CInvSLot
#define CInvSlot__SliderComplete                                   0x576F90

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5804A0
#define CItemDisplayWnd__SetSpell                                  0x5C8B30

// CLabel 
#define CLabel__Draw                                               0x585A60

// CListWnd 
#define CListWnd__AddColumn                                        0x631E20
#define CListWnd__AddColumn1                                       0x631950
#define CListWnd__AddLine                                          0x6314E0
#define CListWnd__AddString                                        0x6316B0
#define CListWnd__CalculateFirstVisibleLine                        0x62E810
#define CListWnd__CalculateVSBRange                                0x630480
#define CListWnd__ClearAllSel                                      0x62DF80
#define CListWnd__CloseAndUpdateEditWindow                         0x62EE20
#define CListWnd__Compare                                          0x62F1D0
#define CListWnd__Draw                                             0x630180
#define CListWnd__DrawColumnSeparators                             0x62FFF0
#define CListWnd__DrawHeader                                       0x62E150
#define CListWnd__DrawItem                                         0x62F8E0
#define CListWnd__DrawLine                                         0x62FC90
#define CListWnd__DrawSeparator                                    0x630090
#define CListWnd__EnsureVisible                                    0x62E860
#define CListWnd__ExtendSel                                        0x62F810
#define CListWnd__GetColumnMinWidth                                0x62DD20
#define CListWnd__GetColumnWidth                                   0x62DC60
#define CListWnd__GetCurSel                                        0x62D740
#define CListWnd__GetHeaderRect                                    0x62D830
#define CListWnd__GetItemAtPoint                                   0x62EB30
#define CListWnd__GetItemAtPoint1                                  0x62EBA0
#define CListWnd__GetItemData                                      0x62DA10
#define CListWnd__GetItemHeight                                    0x62E5B0
#define CListWnd__GetItemIcon                                      0x62DBA0
#define CListWnd__GetItemRect                                      0x62E920
#define CListWnd__GetItemText                                      0x62DA50
#define CListWnd__GetSelList                                       0x631830
#define CListWnd__GetSeparatorRect                                 0x62F110
#define CListWnd__RemoveLine                                       0x6317E0
#define CListWnd__SetColors                                        0x62D7A0
#define CListWnd__SetColumnJustification                           0x62DD80
#define CListWnd__SetColumnWidth                                   0x62DCE0
#define CListWnd__SetCurSel                                        0x62D780
#define CListWnd__SetItemColor                                     0x6310B0
#define CListWnd__SetItemData                                      0x62E020
#define CListWnd__SetItemText                                      0x631030
#define CListWnd__ShiftColumnSeparator                             0x62F780
#define CListWnd__Sort                                             0x631E50
#define CListWnd__ToggleSel                                        0x62DEF0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x598830

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x59A210
#define CMerchantWnd__RequestBuyItem                               0x59B4C0
#define CMerchantWnd__RequestSellItem                              0x59A470
#define CMerchantWnd__SelectBuySellSlot                            0x59B200

// CObfuscator
#define CObfuscator__doit                                          0x60B8D0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x646D00

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x637770
#define CSidlScreenWnd__CalculateVSBRange                          0x524030
#define CSidlScreenWnd__ConvertToRes                               0x637ED1
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6386D0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x639990
#define CSidlScreenWnd__CSidlScreenWnd2                            0x639A40
#define CSidlScreenWnd__dCSidlScreenWnd                            0x639240
#define CSidlScreenWnd__DrawSidlPiece                              0x6383B0
#define CSidlScreenWnd__EnableIniStorage                           0x637E70
#define CSidlScreenWnd__GetSidlPiece                               0x6385B0
#define CSidlScreenWnd__Init1                                      0x6397A0
#define CSidlScreenWnd__LoadIniInfo                                0x638780
#define CSidlScreenWnd__LoadIniListWnd                             0x638020
#define CSidlScreenWnd__LoadSidlScreen                             0x6381E0
#define CSidlScreenWnd__StoreIniInfo                               0x6379B0
#define CSidlScreenWnd__WndNotification                            0x638310

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x509650

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x657BD0
#define CSliderWnd__SetValue                                       0x657CE0
#define CSliderWnd__SetNumTicks                                    0x658220

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5C7880

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6540C0
#define CStmlWnd__CalculateVSBRange                                0x64C440
#define CStmlWnd__CanBreakAtCharacter                              0x64C580
#define CStmlWnd__FastForwardToEndOfTag                            0x64D080
#define CStmlWnd__GetNextTagPiece                                  0x64CFA0
#define CStmlWnd__GetSTMLText                                      0x548E80
#define CStmlWnd__GetThisChar                                      0x673C10
#define CStmlWnd__GetVisiableText                                  0x64E2C0
#define CStmlWnd__InitializeWindowVariables                        0x650420
#define CStmlWnd__MakeStmlColorTag                                 0x64BB40
#define CStmlWnd__MakeWndNotificationTag                           0x64BBE0
#define CStmlWnd__StripFirstSTMLLines                              0x653E40
#define CStmlWnd__UpdateHistoryString                              0x64EB20

// CTabWnd 
#define CTabWnd__Draw                                              0x657450
#define CTabWnd__DrawCurrentPage                                   0x656E40
#define CTabWnd__DrawTab                                           0x656C20
#define CTabWnd__GetCurrentPage                                    0x6570C0
#define CTabWnd__GetPageClientRect                                 0x6568F0
#define CTabWnd__GetPageFromTabIndex                               0x656B50
#define CTabWnd__GetPageInnerRect                                  0x656950
#define CTabWnd__GetTabInnerRect                                   0x656AD0
#define CTabWnd__GetTabRect                                        0x6569E0
#define CTabWnd__IndexInBounds                                     0x656BED
#define CTabWnd__InsertPage                                        0x657670
#define CTabWnd__SetPage                                           0x657100
#define CTabWnd__SetPageRect                                       0x657380
#define CTabWnd__UpdatePage                                        0x6575F0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x413E80

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x639DA0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x65D250

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x62D4B0

// CXRect 
#define CXRect__CenterPoint                                        0x527C50

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4122F0
#define CXStr__CXStr1                                              0x5054D0
#define CXStr__CXStr3                                              0x61B6D0
#define CXStr__dCXStr                                              0x631FA0
#define CXStr__operator_equal1                                     0x61B890
#define CXStr__operator_plus_equal1                                0x61C780

// CXWnd 
#define CXWnd__BringToTop                                          0x632DF0
#define CXWnd__Center                                              0x6364C0
#define CXWnd__ClrFocus                                            0x632B10
#define CXWnd__DoAllDrawing                                        0x637170
#define CXWnd__DrawChildren                                        0x6372A0
#define CXWnd__DrawColoredRect                                     0x633050
#define CXWnd__DrawTooltip                                         0x637090
#define CXWnd__DrawTooltipAtPoint                                  0x636310
#define CXWnd__GetBorderFrame                                      0x633590
#define CXWnd__GetChildWndAt                                       0x635E10
#define CXWnd__GetClientClipRect                                   0x633450
#define CXWnd__GetFirstChildWnd                                    0x632E90
#define CXWnd__GetNextChildWnd                                     0x635DD0
#define CXWnd__GetNextSib                                          0x632EB0
#define CXWnd__GetScreenClipRect                                   0x6366E0
#define CXWnd__GetScreenRect                                       0x6336F0
#define CXWnd__GetTooltipRect                                      0x633280
#define CXWnd__GetWindowTextA                                      0x51B870
#define CXWnd__IsActive                                            0x63AE80
#define CXWnd__IsDescendantOf                                      0x6334C0
#define CXWnd__IsReallyVisible                                     0x635DB0
#define CXWnd__IsType                                              0x6590A0
#define CXWnd__Move                                                0x6358E0
#define CXWnd__Move1                                               0x635980
#define CXWnd__ProcessTransition                                   0x632DC0
#define CXWnd__Refade                                              0x632BC0
#define CXWnd__Resize                                              0x636820
#define CXWnd__Right                                               0x636630
#define CXWnd__SetFirstChildPointer                                0x633940
#define CXWnd__SetFocus                                            0x634C30
#define CXWnd__SetKeyTooltip                                       0x6339B0
#define CXWnd__SetMouseOver                                        0x633980
#define CXWnd__SetNextSibPointer                                   0x633960
#define CXWnd__StartFade                                           0x632E10

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x63C400
#define CXWndManager__DrawWindows                                  0x63C040
#define CXWndManager__GetFirstChildWnd                             0x63B8D0
#define CXWndManager__GetKeyboardFlags                             0x63AB60
#define CXWndManager__HandleKeyboardMsg                            0x63B120
#define CXWndManager__RemoveWnd                                    0x63B040

// CDBStr
#define CDBStr__GetString                                          0x458060

// EQ_Character 
#define EQ_Character__CastRay                                      0x5FC690
#define EQ_Character__CastSpell                                    0x4234A0
#define EQ_Character__Cur_HP                                       0x42A980
#define EQ_Character__GetAACastingTimeModifier                     0x41E2C0
#define EQ_Character__GetCharInfo2                                 0x5FAF60
#define EQ_Character__GetFocusCastingTimeModifier                  0x41A970
#define EQ_Character__GetFocusRangeModifier                        0x41AAA0
#define EQ_Character__Max_Endurance                                0x4297A0
#define EQ_Character__Max_HP                                       0x429650
#define EQ_Character__Max_Mana                                     0x4ED630
#define EQ_Character__doCombatAbility                              0x4EC4B0
#define EQ_Character__UseSkill                                     0x435E20
#define EQ_Character__GetConLevel                                  0x4E9A20

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4DF5C0
#define EQ_Item__GetItemLinkHash                                   0x5EFA00
#define EQ_Item__IsStackable                                       0x5E9DA0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x4703F0
#define EQ_LoadingS__Array                                         0x722130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x4F04E0
#define EQ_PC__GetAltAbilityIndex                                  0x5F4310
#define EQ_PC__GetCombatAbility                                    0x5F43A0
#define EQ_PC__GetCombatAbilityTimer                               0x5F4450
#define EQ_PC__GetItemTimerValue                                   0x4EB7E0
#define EQ_PC__HasLoreItem                                         0x4EEB00

// EQItemList 
#define EQItemList__dEQItemList                                    0x492AA0
#define EQItemList__EQItemList                                     0x4929F0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x457AE0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x4F4EA0
#define EQPlayer__dEQPlayer                                        0x4F93A0
#define EQPlayer__DoAttack                                         0x5047B0
#define EQPlayer__EQPlayer                                         0x4FBAC0
#define EQPlayer__SetNameSpriteState                               0x4F7580
#define EQPlayer__SetNameSpriteTint                                0x4F4F10
#define EQPlayer__IsBodyType_j                                     0x5FC0C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4FC8C0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4E1150
#define KeypressHandler__AttachKeyToEqCommand                      0x4E1190
#define KeypressHandler__ClearCommandStateArray                    0x4E0F60
#define KeypressHandler__HandleKeyDown                             0x4DFB70
#define KeypressHandler__HandleKeyUp                               0x4DFE70
#define KeypressHandler__SaveKeymapping                            0x4E1030

// MapViewMap 
#define MapViewMap__Clear                                          0x594870
#define MapViewMap__SaveEx                                         0x595240

// StringTable 
#define StringTable__getString                                     0x5E97B0
