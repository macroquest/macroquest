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
#define __ExpectedVersionDate                                     "Apr  3 2007"
#define __ExpectedVersionTime                                     "11:33:36"
#define __ActualVersionDate                                        0x6CD68C
#define __ActualVersionTime                                        0x6CD698

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection 
#define __MemChecker0                                              0x4E22F0
#define __MemChecker1                                              0x5F2C30
#define __MemChecker2                                              0x5110A0
#define __MemChecker3                                              0x511150
#define __MemChecker4                                              0x5EDE90
#define __EncryptPad0                                              0x721988
#define __EncryptPad1                                              0x72B0A8
#define __EncryptPad2                                              0x723ED8
#define __EncryptPad3                                              0x7242D8
#define __EncryptPad4                                              0x72A8A0

// Direct Input
#define DI8__Main                                                  0x958FB4
#define DI8__Keyboard                                              0x958FB8
#define DI8__Mouse                                                 0x958FBC
#define __AltTimerReady                                            0x8F51EA
#define __Attack                                                   0x95285E
#define __Autofire                                                 0x95285F
#define __BindList                                                 0x71CC18
#define __Clicks                                                   0x8F4314
#define __CommandList                                              0x71D408
#define __CurrentMapLabel                                          0x96407C
#define __CurrentSocial                                            0x7194B8
#define __DoAbilityAvailable                                       0x8F5184
#define __DoAbilityList                                            0x92A3A4
#define __DrawHandler                                              0x972CD4
#define __GroupCount                                               0x8D4A60
#define __GroupLeader                                              0x8D4BBC
#define __Guilds                                                   0x8D6558
#define __gWorld                                                   0x8D64B8
#define __HotkeyPage                                               0x951790
#define __HWnd                                                     0x958F5C
#define __InChatMode                                               0x8F4250
#define __LastTell                                                 0x8F5AAC
#define __Mouse                                                    0x958FC0
#define __MouseLook                                                0x8F42E2
#define __NetStatusToggle                                          0x8F42E4
#define __PCNames                                                  0x8F5504
#define __RangeAttackReady                                         0x8F51E8
#define __RunWalkState                                             0x8F4254
#define __ScreenMode                                               0x824540
#define __ScreenX                                                  0x8F4218
#define __ScreenY                                                  0x8F421C
#define __ServerHost                                               0x8D49B4
#define __ServerName                                               0x92A364
#define __ShowNames                                                0x8F53D8
#define __Socials                                                  0x92A464


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x8EE1A8
#define instEQZoneInfo                                             0x8F4480
#define instKeypressHandler                                        0x952930
#define pinstActiveBanker                                          0x8D6534
#define pinstActiveCorpse                                          0x8D6538
#define pinstActiveGMaster                                         0x8D653C
#define pinstActiveMerchant                                        0x8D6530
#define pinstAltAdvManager                                         0x825218
#define pinstAuraMgr                                               0x730270
#define pinstBandageTarget                                         0x8D651C
#define pinstCamActor                                              0x824D0C
#define pinstCDBStr                                                0x8243C0
#define pinstCDisplay                                              0x8D6544
#define pinstCEverQuest                                            0x959128
#define pinstCharData                                              0x8D6500
#define pinstCharSpawn                                             0x8D6528
#define pinstControlledMissile                                     0x8D64FC
#define pinstControlledPlayer                                      0x8D6528
#define pinstCSidlManager                                          0x972524
#define pinstCXWndManager                                          0x97251C
#define instDynamicZone                                            0x8F3C68
#define pinstDZMember                                              0x8F3D78
#define pinstDZTimerInfo                                           0x8F3D7C
#define pinstEQItemList                                            0x8D64E4
#define instEQMisc                                                 0x824378
#define pinstEQSoundManager                                        0x82523C
#define instExpeditionLeader                                       0x8F3CB2
#define instExpeditionName                                         0x8F3CF2
#define instGroup                                                  0x8D4A60
#define pinstGroup                                                 0x8D4A5C
#define pinstImeManager                                            0x972528
#define pinstLocalPlayer                                           0x8D6514
#define pinstModelPlayer                                           0x8D6540
#define pinstPCData                                                0x8D6500
#define pinstSelectedItem                                          0x963ED4
#define pinstSkillMgr                                              0x956018
#define pinstSpawnManager                                          0x955F94
#define pinstSpellManager                                          0x95601C
#define pinstSpellSets                                             0x951794
#define pinstStringTable                                           0x8D64C8
#define pinstSwitchManager                                         0x8D46B0
#define pinstTarget                                                0x8D652C
#define pinstTargetObject                                          0x8D6504
#define pinstTargetSwitch                                          0x8D6508
#define pinstTaskMember                                            0x824358
#define pinstTrackTarget                                           0x8D6520
#define pinstTradeTarget                                           0x8D6510
#define instTributeActive                                          0x82439D
#define pinstViewActor                                             0x824D08
#define pinstWorldData                                             0x8D64E0


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x72E7A8
#define pinstCAudioTriggersWindow                                  0x72E78C
#define pinstCCharacterSelect                                      0x824C18
#define pinstCFacePick                                             0x824BD0
#define pinstCNoteWnd                                              0x824BD4
#define pinstCBookWnd                                              0x824BD8
#define pinstCPetInfoWnd                                           0x824BDC
#define pinstCTrainWnd                                             0x824BE0
#define pinstCSkillsWnd                                            0x824BE4
#define pinstCSkillsSelectWnd                                      0x824BE8
#define pinstCCombatSkillSelectWnd                                 0x824BEC
#define pinstCFriendsWnd                                           0x824BF0
#define pinstCAuraWnd                                              0x824BF4
#define pinstCRespawnWnd                                           0x824BF8
#define pinstCBandolierWnd                                         0x824BFC
#define pinstCPotionBeltWnd                                        0x824C00
#define pinstCAAWnd                                                0x824C04
#define pinstCGroupSearchFiltersWnd                                0x824C08
#define pinstCLoadskinWnd                                          0x824C0C
#define pinstCAlarmWnd                                             0x824C10
#define pinstCMusicPlayerWnd                                       0x824C14
#define pinstCMailWnd                                              0x824C1C
#define pinstCMailCompositionWnd                                   0x824C20
#define pinstCMailAddressBookWnd                                   0x824C24
#define pinstCRaidWnd                                              0x824C2C
#define pinstCRaidOptionsWnd                                       0x824C30
#define pinstCBreathWnd                                            0x824C34
#define pinstCMapViewWnd                                           0x824C38
#define pinstCMapToolbarWnd                                        0x824C3C
#define pinstCEditLabelWnd                                         0x824C40
#define pinstCTargetWnd                                            0x824C44
#define pinstCColorPickerWnd                                       0x824C48
#define pinstCPlayerWnd                                            0x824C4C
#define pinstCOptionsWnd                                           0x824C50
#define pinstCBuffWindowNORMAL                                     0x824C54
#define pinstCBuffWindowSHORT                                      0x824C58
#define pinstCharacterCreation                                     0x824C5C
#define pinstCCursorAttachment                                     0x824C60
#define pinstCCastingWnd                                           0x824C64
#define pinstCCastSpellWnd                                         0x824C68
#define pinstCSpellBookWnd                                         0x824C6C
#define pinstCInventoryWnd                                         0x824C70
#define pinstCBankWnd                                              0x824C74
#define pinstCQuantityWnd                                          0x824C78
#define pinstCLootWnd                                              0x824C7C
#define pinstCActionsWnd                                           0x824C80
#define pinstCCombatAbilityWnd                                     0x824C84
#define pinstCMerchantWnd                                          0x824C88
#define pinstCTradeWnd                                             0x824C8C
#define pinstCSelectorWnd                                          0x824C90
#define pinstCBazaarWnd                                            0x824C94
#define pinstCBazaarSearchWnd                                      0x824C98
#define pinstCGiveWnd                                              0x824C9C
#define pinstCTrackingWnd                                          0x824CA0
#define pinstCInspectWnd                                           0x824CA4
#define pinstCSocialEditWnd                                        0x824CA8
#define pinstCFeedbackWnd                                          0x824CAC
#define pinstCBugReportWnd                                         0x824CB0
#define pinstCVideoModesWnd                                        0x824CB4
#define pinstCTextEntryWnd                                         0x824CBC
#define pinstCFileSelectionWnd                                     0x824CC0
#define pinstCCompassWnd                                           0x824CC4
#define pinstCPlayerNotesWnd                                       0x824CC8
#define pinstCGemsGameWnd                                          0x824CCC
#define pinstCTimeLeftWnd                                          0x824CD0
#define pinstCPetitionQWnd                                         0x824CD4
#define pinstCSoulmarkWnd                                          0x824CD8
#define pinstCStoryWnd                                             0x824CDC
#define pinstCJournalTextWnd                                       0x824CE0
#define pinstCJournalCatWnd                                        0x824CE4
#define pinstCBodyTintWnd                                          0x824CE8
#define pinstCServerListWnd                                        0x824CEC
#define pinstCAvaZoneWnd                                           0x824CF0
#define pinstCBlockedBuffWnd                                       0x824CF4
#define pinstCBlockedPetBuffWnd                                    0x824CF8
#define pinstCInvSlotMgr                                           0x824CFC
#define pinstCContainerMgr                                         0x824D00
#define pinstCAdventureLeaderboardWnd                              0x9616F4
#define pinstCAdventureRequestWnd                                  0x961710
#define pinstCAltStorageWnd                                        0x961770
#define pinstCAdventureStatsWnd                                    0x96172C
#define pinstCBarterMerchantWnd                                    0x961924
#define pinstCBarterSearchWnd                                      0x961940
#define pinstCBarterWnd                                            0x96195C
#define pinstCChatManager                                          0x961B3C
#define pinstCDynamicZoneWnd                                       0x961C18
#define pinstCEQMainWnd                                            0x961C88
#define pinstCFellowshipWnd                                        0x961CEC
#define pinstCFindLocationWnd                                      0x961D20
#define pinstCGroupSearchWnd                                       0x961DF4
#define pinstCGroupWnd                                             0x961DEC
#define pinstCGuildBankWnd                                         0x961E08
#define pinstCGuildMgmtWnd                                         0x963E28
#define pinstCGuildTributeMasterWnd                                0x963E48
#define pinstCHotButtonWnd                                         0x963E64
#define pinstCHotButtonWnd1                                        0x963E64
#define pinstCHotButtonWnd2                                        0x963E68
#define pinstCHotButtonWnd3                                        0x963E6C
#define pinstCHotButtonWnd4                                        0x963E70
#define pinstCItemDisplayManager                                   0x963F08
#define pinstCItemExpTransferWnd                                   0x963F28
#define pinstCLeadershipWnd                                        0x963FA4
#define pinstCLFGuildWnd                                           0x963FC0
#define pinstCMIZoneSelectWnd                                      0x9640E4
#define pinstCAdventureMerchantWnd                                 0x9641DC
#define pinstCConfirmationDialog                                   0x9641F8
#define pinstCPopupWndManager                                      0x9641F8
#define pinstCProgressionSelectionWnd                              0x96422C
#define pinstCPvPLeaderboardWnd                                    0x964248
#define pinstCPvPStatsWnd                                          0x964264
#define pinstCSystemInfoDialogBox                                  0x964BE4
#define pinstCTargetOfTargetWnd                                    0x964C00
#define pinstCTaskSelectWnd                                        0x964C34
#define pinstCTaskTemplateSelectWnd                                0x964C50
#define pinstCTaskWnd                                              0x964C6C
#define pinstCTipWndOFDAY                                          0x964CB8
#define pinstCTipWndCONTEXT                                        0x964CBC
#define pinstCTitleWnd                                             0x964CD8
#define pinstCTradeskillWnd                                        0x964D1C
#define pinstCTributeBenefitWnd                                    0x964D68
#define pinstCTributeMasterWnd                                     0x964D84
#define pinstCContextMenuManager                                   0x9725E4
#define pinstCVoiceMacroWnd                                        0x9560CC


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4A6220
#define __ConvertItemTags                                          0x49AEC0
#define __ExecuteCmd                                               0x48C950
#define __get_melee_range                                          0x491940
#define __GetGaugeValueFromEQ                                      0x5C83D0
#define __GetLabelFromEQ                                           0x5C8B00
#define __NewUIINI                                                 0x5C7FD0
#define __ProcessGameEvents                                        0x4D0F50
#define __SendMessage                                              0x4B37F0
#define CrashDetected                                              0x510D50
#define DrawNetStatus                                              0x4E4F70
#define Util__FastTime                                             0x5F3280


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x46D290
#define AltAdvManager__IsAbilityReady                              0x46D2D0
#define AltAdvManager__GetAltAbility                               0x46D4A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x525180

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x52E5B0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x63C280

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x542360
#define CChatManager__InitContextMenu                              0x542AF0

// CChatService
#define CChatService__GetNumberOfFriends                           0x618160
#define CChatService__GetFriendName                                0x618170

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x546C70

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x631C70
#define CComboWnd__Draw                                            0x631E20
#define CComboWnd__GetCurChoice                                    0x631C20
#define CComboWnd__GetListRect                                     0x632100
#define CComboWnd__GetTextRect                                     0x631CA0
#define CComboWnd__InsertChoice                                    0x632170
#define CComboWnd__SetColors                                       0x631BB0
#define CComboWnd__SetChoice                                       0x631BE0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x54D3C0
#define CContainerWnd__vftable                                     0x6D38D8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x45C9D0
#define CDisplay__GetClickedActor                                  0x45A270
#define CDisplay__GetUserDefinedColor                              0x4596E0
#define CDisplay__GetWorldFilePath                                 0x458C90
#define CDisplay__ReloadUI                                         0x468760
#define CDisplay__WriteTextHD2                                     0x45E170

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x51F330
#define CEditBaseWnd__SetSel                                       0x654710

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x651E40
#define CEditWnd__GetCharIndexPt                                   0x652C80
#define CEditWnd__GetDisplayString                                 0x651FD0
#define CEditWnd__GetHorzOffset                                    0x652250
#define CEditWnd__GetLineForPrintableChar                          0x652730
#define CEditWnd__GetSelStartPt                                    0x652EC0
#define CEditWnd__GetSTMLSafeText                                  0x6523F0
#define CEditWnd__PointFromPrintableChar                           0x652840
#define CEditWnd__SelectableCharFromPoint                          0x6529C0
#define CEditWnd__SetEditable                                      0x6523C0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4B7880
#define CEverQuest__DropHeldItemOnGround                           0x4BC1F0
#define CEverQuest__dsp_chat                                       0x4BCDD0
#define CEverQuest__EnterZone                                      0x4CFB40
#define CEverQuest__GetBodyTypeDesc                                0x4B5000
#define CEverQuest__GetClassDesc                                   0x4B4760
#define CEverQuest__GetClassThreeLetterCode                        0x4B4D60
#define CEverQuest__GetDeityDesc                                   0x4B5650
#define CEverQuest__GetLangDesc                                    0x4B5370
#define CEverQuest__GetRaceDesc                                    0x4B5620
#define CEverQuest__InterpretCmd                                   0x4BD6E0
#define CEverQuest__LeftClickedOnPlayer                            0x4CE710
#define CEverQuest__RightClickedOnPlayer                           0x4CEAD0
#define CEverQuest__SetGameState                                   0x4B7950

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x558370
#define CGaugeWnd__CalcLinesFillRect                               0x5583E0
#define CGaugeWnd__Draw                                            0x558770

// CGuild
#define CGuild__FindMemberByName                                   0x4158E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x56E110

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x575B60
#define CInvSlotMgr__MoveItem                                      0x575D00

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x576BF0

// CInvSLot
#define CInvSlot__SliderComplete                                   0x574B80

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x57E160
#define CItemDisplayWnd__SetSpell                                  0x5C64B0

// CLabel 
#define CLabel__Draw                                               0x5836B0

// CListWnd 
#define CListWnd__AddColumn                                        0x6319C0
#define CListWnd__AddColumn1                                       0x6314A0
#define CListWnd__AddLine                                          0x631080
#define CListWnd__AddString                                        0x631250
#define CListWnd__CalculateFirstVisibleLine                        0x62E3B0
#define CListWnd__CalculateVSBRange                                0x630020
#define CListWnd__ClearAllSel                                      0x62DB20
#define CListWnd__CloseAndUpdateEditWindow                         0x62E9C0
#define CListWnd__Compare                                          0x62ED70
#define CListWnd__Draw                                             0x62FD20
#define CListWnd__DrawColumnSeparators                             0x62FB90
#define CListWnd__DrawHeader                                       0x62DCF0
#define CListWnd__DrawItem                                         0x62F480
#define CListWnd__DrawLine                                         0x62F8D1
#define CListWnd__DrawSeparator                                    0x62F8D1
#define CListWnd__EnsureVisible                                    0x62E400
#define CListWnd__ExtendSel                                        0x62F3B0
#define CListWnd__GetColumnMinWidth                                0x62D8C0
#define CListWnd__GetColumnWidth                                   0x62D800
#define CListWnd__GetCurSel                                        0x62D2E0
#define CListWnd__GetHeaderRect                                    0x62D3D0
#define CListWnd__GetItemAtPoint                                   0x62E6D0
#define CListWnd__GetItemAtPoint1                                  0x62E740
#define CListWnd__GetItemData                                      0x62D5B0
#define CListWnd__GetItemHeight                                    0x62E150
#define CListWnd__GetItemIcon                                      0x62D740
#define CListWnd__GetItemRect                                      0x62E4C0
#define CListWnd__GetItemText                                      0x62D5F0
#define CListWnd__GetSelList                                       0x631380
#define CListWnd__GetSeparatorRect                                 0x62ECB0
#define CListWnd__RemoveLine                                       0x631970
#define CListWnd__SetColors                                        0x62D340
#define CListWnd__SetColumnJustification                           0x62D920
#define CListWnd__SetColumnWidth                                   0x62D880
#define CListWnd__SetCurSel                                        0x62D320
#define CListWnd__SetItemColor                                     0x630C50
#define CListWnd__SetItemData                                      0x62DBC0
#define CListWnd__SetItemText                                      0x630BD0
#define CListWnd__ShiftColumnSeparator                             0x62F320
#define CListWnd__Sort                                             0x6319F0
#define CListWnd__ToggleSel                                        0x62DA90

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x596470

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x597E40
#define CMerchantWnd__RequestBuyItem                               0x599000
#define CMerchantWnd__RequestSellItem                              0x5980A0
#define CMerchantWnd__SelectBuySellSlot                            0x598D40

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x640D90

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x637310
#define CSidlScreenWnd__CalculateVSBRange                          0x520CB0
#define CSidlScreenWnd__ConvertToRes                               0x637A71
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x638270
#define CSidlScreenWnd__CSidlScreenWnd1                            0x639530
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6395E0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x638DE0
#define CSidlScreenWnd__DrawSidlPiece                              0x637F50
#define CSidlScreenWnd__EnableIniStorage                           0x637A10
#define CSidlScreenWnd__GetSidlPiece                               0x638150
#define CSidlScreenWnd__Init1                                      0x639340
#define CSidlScreenWnd__LoadIniInfo                                0x638320
#define CSidlScreenWnd__LoadIniListWnd                             0x637BC0
#define CSidlScreenWnd__LoadSidlScreen                             0x637D80
#define CSidlScreenWnd__StoreIniInfo                               0x637550
#define CSidlScreenWnd__WndNotification                            0x637EB0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x506320

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x656590
#define CSliderWnd__SetValue                                       0x656690
#define CSliderWnd__SetNumTicks                                    0x656BD0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5C5210

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x64B180
#define CStmlWnd__CalculateVSBRange                                0x643520
#define CStmlWnd__CanBreakAtCharacter                              0x643660
#define CStmlWnd__FastForwardToEndOfTag                            0x644160
#define CStmlWnd__GetNextTagPiece                                  0x644080
#define CStmlWnd__GetSTMLText                                      0x546C10
#define CStmlWnd__GetThisChar                                      0x673690
#define CStmlWnd__GetVisiableText                                  0x645380
#define CStmlWnd__InitializeWindowVariables                        0x6474E0
#define CStmlWnd__MakeStmlColorTag                                 0x642C20
#define CStmlWnd__MakeWndNotificationTag                           0x642CC0
#define CStmlWnd__StripFirstSTMLLines                              0x64AF00
#define CStmlWnd__UpdateHistoryString                              0x645BE0

// CTabWnd 
#define CTabWnd__Draw                                              0x655E10
#define CTabWnd__DrawCurrentPage                                   0x655780
#define CTabWnd__DrawTab                                           0x655560
#define CTabWnd__GetCurrentPage                                    0x655A80
#define CTabWnd__GetPageClientRect                                 0x655230
#define CTabWnd__GetPageFromTabIndex                               0x655490
#define CTabWnd__GetPageInnerRect                                  0x655290
#define CTabWnd__GetTabInnerRect                                   0x655410
#define CTabWnd__GetTabRect                                        0x655320
#define CTabWnd__IndexInBounds                                     0x65552D
#define CTabWnd__InsertPage                                        0x656030
#define CTabWnd__SetPage                                           0x655AC0
#define CTabWnd__SetPageRect                                       0x655D40
#define CTabWnd__UpdatePage                                        0x655FB0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x412590

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x639940

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x65CE80

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x62D050

// CXRect 
#define CXRect__CenterPoint                                        0x524940

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x412130
#define CXStr__CXStr1                                              0x501BF0
#define CXStr__CXStr3                                              0x5F4980
#define CXStr__dCXStr                                              0x406590
#define CXStr__operator_equal1                                     0x5F4B40
#define CXStr__operator_plus_equal1                                0x5F5A30

// CXWnd 
#define CXWnd__BringToTop                                          0x632970
#define CXWnd__Center                                              0x636060
#define CXWnd__ClrFocus                                            0x632690
#define CXWnd__DoAllDrawing                                        0x636D10
#define CXWnd__DrawChildren                                        0x636E40
#define CXWnd__DrawColoredRect                                     0x632BD0
#define CXWnd__DrawTooltip                                         0x636C30
#define CXWnd__DrawTooltipAtPoint                                  0x635EB0
#define CXWnd__GetBorderFrame                                      0x633110
#define CXWnd__GetChildWndAt                                       0x6359B0
#define CXWnd__GetClientClipRect                                   0x632FD0
#define CXWnd__GetFirstChildWnd                                    0x632A10
#define CXWnd__GetNextChildWnd                                     0x635970
#define CXWnd__GetNextSib                                          0x632A30
#define CXWnd__GetScreenClipRect                                   0x636280
#define CXWnd__GetScreenRect                                       0x633270
#define CXWnd__GetTooltipRect                                      0x632E00
#define CXWnd__GetWindowTextA                                      0x5184F0
#define CXWnd__IsActive                                            0x64D120
#define CXWnd__IsDescendantOf                                      0x633040
#define CXWnd__IsReallyVisible                                     0x635950
#define CXWnd__IsType                                              0x657A90
#define CXWnd__Move                                                0x635480
#define CXWnd__Move1                                               0x635520
#define CXWnd__ProcessTransition                                   0x632940
#define CXWnd__Refade                                              0x632740
#define CXWnd__Resize                                              0x6363C0
#define CXWnd__Right                                               0x6361D0
#define CXWnd__SetFirstChildPointer                                0x6334E0
#define CXWnd__SetFocus                                            0x6347D0
#define CXWnd__SetKeyTooltip                                       0x633550
#define CXWnd__SetMouseOver                                        0x633520
#define CXWnd__SetNextSibPointer                                   0x633500
#define CXWnd__StartFade                                           0x632990

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x64E570
#define CXWndManager__DrawWindows                                  0x64E1B0
#define CXWndManager__GetFirstChildWnd                             0x64DAC0
#define CXWndManager__GetKeyboardFlags                             0x64CE00
#define CXWndManager__HandleKeyboardMsg                            0x64D310
#define CXWndManager__RemoveWnd                                    0x64D230

// CDBStr
#define CDBStr__GetString                                          0x456210

// EQ_Character 
#define EQ_Character__CastRay                                      0x67F080
#define EQ_Character__CastSpell                                    0x421990
#define EQ_Character__Cur_HP                                       0x428DB0
#define EQ_Character__GetAACastingTimeModifier                     0x41C900
#define EQ_Character__GetCharInfo2                                 0x600660
#define EQ_Character__GetFocusCastingTimeModifier                  0x418FA0
#define EQ_Character__GetFocusRangeModifier                        0x4190D0
#define EQ_Character__Max_Endurance                                0x427C30
#define EQ_Character__Max_HP                                       0x427AE0
#define EQ_Character__Max_Mana                                     0x4E9F20
#define EQ_Character__doCombatAbility                              0x4E8DA0
#define EQ_Character__UseSkill                                     0x434110
#define EQ_Character__GetConLevel                                  0x4E6350

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4DBF40
#define EQ_Item__GetItemLinkHash                                   0x5FF8C0
#define EQ_Item__IsStackable                                       0x5F9DA0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x46E3C0
#define EQ_LoadingS__Array                                         0x71B130

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x4ECDB0
#define EQ_PC__GetAltAbilityIndex                                  0x605490
#define EQ_PC__GetCombatAbility                                    0x605520
#define EQ_PC__GetCombatAbilityTimer                               0x6055D0
#define EQ_PC__GetItemTimerValue                                   0x4E8100
#define EQ_PC__HasLoreItem                                         0x4EB3F0

// EQItemList 
#define EQItemList__dEQItemList                                    0x490220
#define EQItemList__EQItemList                                     0x490170

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x455CA0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x4F1730
#define EQPlayer__dEQPlayer                                        0x4F5B60
#define EQPlayer__DoAttack                                         0x500F10
#define EQPlayer__EQPlayer                                         0x4F8260
#define EQPlayer__SetNameSpriteState                               0x4F3E20
#define EQPlayer__SetNameSpriteTint                                0x4F17A0
#define EQPlayer__IsBodyType_j                                     0x67EAB0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x4F9060

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4DDAD0
#define KeypressHandler__AttachKeyToEqCommand                      0x4DDB10
#define KeypressHandler__ClearCommandStateArray                    0x4DD8E0
#define KeypressHandler__HandleKeyDown                             0x4DC4F0
#define KeypressHandler__HandleKeyUp                               0x4DC7F0
#define KeypressHandler__SaveKeymapping                            0x4DD9B0

// MapViewMap 
#define MapViewMap__Clear                                          0x5924B0
#define MapViewMap__SaveEx                                         0x592E80

// StringTable 
#define StringTable__getString                                     0x5F97C0
