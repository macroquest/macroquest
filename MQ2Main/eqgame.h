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
#define __ExpectedVersionDate                                     "Jan 16 2009"
#define __ExpectedVersionTime                                     "18:33:10"
#define __ActualVersionDate                                        0x7D6D1C
#define __ActualVersionTime                                        0x7D6D28

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x509DD0
#define __MemChecker1                                              0x6B0970
#define __MemChecker2                                              0x55F820
#define __MemChecker3                                              0x55F770
#define __MemChecker4                                              0x6731B0
#define __EncryptPad0                                              0x85B430
#define __EncryptPad1                                              0x865970
#define __EncryptPad2                                              0x85DE70
#define __EncryptPad3                                              0x85DA70
#define __EncryptPad4                                              0x865040

// Direct Input
#define DI8__Main                                                  0xAD6C44
#define DI8__Keyboard                                              0xAD6C48
#define DI8__Mouse                                                 0xAD6C4C
#define __AltTimerReady                                            0xA61702
#define __Attack                                                   0xAC11A2
#define __Autofire                                                 0xAC11A3
#define __BindList                                                 0x856450
#define __Clicks                                                   0xA60418
#define __CommandList                                              0x856CB0
#define __CurrentMapLabel                                          0xB01E68
#define __CurrentSocial                                            0x852680
#define __DoAbilityAvailable                                       0xA6169C
#define __DoAbilityList                                            0xA96CB8
#define __do_loot                                                  0x4B14F0
#define __DrawHandler                                              0xB112CC
#define __GroupCount                                               0xA40AC2
#define __Guilds                                                   0xA42640
#define __gWorld                                                   0xA42580
#define __HotkeyPage                                               0xABE0A4
#define __HWnd                                                     0xAD6984
#define __InChatMode                                               0xA60350
#define __LastTell                                                 0xA62010
#define __LMouseHeldTime                                           0xA60438
#define __Mouse                                                    0xAD6C50
#define __MouseLook                                                0xA603E6
#define __MouseEventTime                                           0xAC12AC
#define __NetStatusToggle                                          0xA603E9
#define __PCNames                                                  0xA61A58
#define __RangeAttackReady                                         0xA61700
#define __RMouseHeldTime                                           0xA60434
#define __RunWalkState                                             0xA60354
#define __ScreenMode                                               0x990390
#define __ScreenX                                                  0xA60308
#define __ScreenY                                                  0xA6030C
#define __ScreenXMax                                               0xA60310
#define __ScreenYMax                                               0xA60314
#define __ServerHost                                               0xA40A04
#define __ServerName                                               0xA96C78
#define __ShiftKeyDown                                             0xA609B8
#define __ShowNames                                                0xA6192C
#define __Socials                                                  0xA96D78


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA5A290
#define instEQZoneInfo                                             0xA60584
#define instKeypressHandler                                        0xAC1290
#define pinstActiveBanker                                          0xA42618
#define pinstActiveCorpse                                          0xA4261C
#define pinstActiveGMaster                                         0xA42620
#define pinstActiveMerchant                                        0xA42614
#define pinstAltAdvManager                                         0x9911F0
#define pinstAuraMgr                                               0x879C54
#define pinstBandageTarget                                         0xA42600
#define pinstCamActor                                              0x990CE0
#define pinstCDBStr                                                0x990380
#define pinstCDisplay                                              0xA42628
#define pinstCEverQuest                                            0xAD6DC8
#define pinstCharData                                              0xA425E4
#define pinstCharSpawn                                             0xA4260C
#define pinstControlledMissile                                     0xA425E0
#define pinstControlledPlayer                                      0xA4260C
#define pinstCSidlManager                                          0xB10A50
#define pinstCXWndManager                                          0xB10A48
#define instDynamicZone                                            0xA5FD58
#define pinstDZMember                                              0xA5FE68
#define pinstDZTimerInfo                                           0xA5FE6C
#define pinstEQItemList                                            0xA425C8
#define instEQMisc                                                 0x990338
#define pinstEQSoundManager                                        0x991214
#define instExpeditionLeader                                       0xA5FDA2
#define instExpeditionName                                         0xA5FDE2
#define pinstGroup                                                 0xA40ABE
#define pinstImeManager                                            0xB10A54
#define pinstLocalPlayer                                           0xA425F8
#define pinstModelPlayer                                           0xA42624
#define pinstPCData                                                0xA425E4
#define pinstSkillMgr                                              0xAD3A9C
#define pinstSpawnManager                                          0xAD3A1C
#define pinstSpellManager                                          0xAD3AA0
#define pinstSpellSets                                             0xABE0A8
#define pinstStringTable                                           0xA4259C
#define pinstSwitchManager                                         0xA40704
#define pinstTarget                                                0xA42610
#define pinstTargetObject                                          0xA425E8
#define pinstTargetSwitch                                          0xA425EC
#define pinstTaskMember                                            0x990318
#define pinstTrackTarget                                           0xA42604
#define pinstTradeTarget                                           0xA425F4
#define instTributeActive                                          0x99035D
#define pinstViewActor                                             0x990CDC
#define pinstWorldData                                             0xA425C4


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x877500
#define pinstCAudioTriggersWindow                                  0x8774CC
#define pinstCCharacterSelect                                      0x990BEC
#define pinstCFacePick                                             0x990BA0
#define pinstCNoteWnd                                              0x990BA4
#define pinstCBookWnd                                              0x990BA8
#define pinstCPetInfoWnd                                           0x990BAC
#define pinstCTrainWnd                                             0x990BB0
#define pinstCSkillsWnd                                            0x990BB4
#define pinstCSkillsSelectWnd                                      0x990BB8
#define pinstCCombatSkillSelectWnd                                 0x990BBC
#define pinstCFriendsWnd                                           0x990BC0
#define pinstCAuraWnd                                              0x990BC4
#define pinstCRespawnWnd                                           0x990BC8
#define pinstCBandolierWnd                                         0x990BCC
#define pinstCPotionBeltWnd                                        0x990BD0
#define pinstCAAWnd                                                0x990BD4
#define pinstCGroupSearchFiltersWnd                                0x990BD8
#define pinstCLoadskinWnd                                          0x990BDC
#define pinstCAlarmWnd                                             0x990BE0
#define pinstCMusicPlayerWnd                                       0x990BE4
#define pinstCMailWnd                                              0x990BF0
#define pinstCMailCompositionWnd                                   0x990BF4
#define pinstCMailAddressBookWnd                                   0x990BF8
#define pinstCRaidWnd                                              0x990C00
#define pinstCRaidOptionsWnd                                       0x990C04
#define pinstCBreathWnd                                            0x990C08
#define pinstCMapViewWnd                                           0x990C0C
#define pinstCMapToolbarWnd                                        0x990C10
#define pinstCEditLabelWnd                                         0x990C14
#define pinstCTargetWnd                                            0x990C18
#define pinstCColorPickerWnd                                       0x990C1C
#define pinstCPlayerWnd                                            0x990C20
#define pinstCOptionsWnd                                           0x990C24
#define pinstCBuffWindowNORMAL                                     0x990C28
#define pinstCBuffWindowSHORT                                      0x990C2C
#define pinstCharacterCreation                                     0x990C30
#define pinstCCursorAttachment                                     0x990C34
#define pinstCCastingWnd                                           0x990C38
#define pinstCCastSpellWnd                                         0x990C3C
#define pinstCSpellBookWnd                                         0x990C40
#define pinstCInventoryWnd                                         0x990C44
#define pinstCBankWnd                                              0x990C48
#define pinstCQuantityWnd                                          0x990C4C
#define pinstCLootWnd                                              0x990C50
#define pinstCActionsWnd                                           0x990C54
#define pinstCCombatAbilityWnd                                     0x990C58
#define pinstCMerchantWnd                                          0x990C5C
#define pinstCTradeWnd                                             0x990C60
#define pinstCSelectorWnd                                          0x990C64
#define pinstCBazaarWnd                                            0x990C68
#define pinstCBazaarSearchWnd                                      0x990C6C
#define pinstCGiveWnd                                              0x990C70
#define pinstCTrackingWnd                                          0x990C74
#define pinstCInspectWnd                                           0x990C78
#define pinstCSocialEditWnd                                        0x990C7C
#define pinstCFeedbackWnd                                          0x990C80
#define pinstCBugReportWnd                                         0x990C84
#define pinstCVideoModesWnd                                        0x990C88
#define pinstCTextEntryWnd                                         0x990C90
#define pinstCFileSelectionWnd                                     0x990C94
#define pinstCCompassWnd                                           0x990C98
#define pinstCPlayerNotesWnd                                       0x990C9C
#define pinstCGemsGameWnd                                          0x990CA0
#define pinstCTimeLeftWnd                                          0x990CA4
#define pinstCPetitionQWnd                                         0x990CAC
#define pinstCSoulmarkWnd                                          0x990CB0
#define pinstCStoryWnd                                             0x990CB4
#define pinstCJournalTextWnd                                       0x990CB8
#define pinstCJournalCatWnd                                        0x990CBC
#define pinstCBodyTintWnd                                          0x990CC0
#define pinstCServerListWnd                                        0x990CC4
#define pinstCAvaZoneWnd                                           0x990CC8
#define pinstCBlockedBuffWnd                                       0x990CCC
#define pinstCBlockedPetBuffWnd                                    0x990CD0
#define pinstCInvSlotMgr                                           0x990CD4
#define pinstCContainerMgr                                         0x990CD8
#define pinstCAdventureLeaderboardWnd                              0xAFF3B0
#define pinstCAdventureRequestWnd                                  0xAFF3CC
#define pinstCAltStorageWnd                                        0xAFF42C
#define pinstCAdventureStatsWnd                                    0xAFF3E8
#define pinstCBarterMerchantWnd                                    0xAFF5F8
#define pinstCBarterSearchWnd                                      0xAFF614
#define pinstCBarterWnd                                            0xAFF630
#define pinstCChatManager                                          0xAFF8D4
#define pinstCDynamicZoneWnd                                       0xAFF9CC
#define pinstCEQMainWnd                                            0xAFFA40
#define pinstCFellowshipWnd                                        0xAFFAA4
#define pinstCFindLocationWnd                                      0xAFFAD8
#define pinstCGroupSearchWnd                                       0xAFFB88
#define pinstCGroupWnd                                             0xAFFBA4
#define pinstCGuildBankWnd                                         0xAFFBC0
#define pinstCGuildMgmtWnd                                         0xB01BE0
#define pinstCGuildTributeMasterWnd                                0xB01C00
#define pinstCHotButtonWnd                                         0xB01C1C
#define pinstCHotButtonWnd1                                        0xB01C1C
#define pinstCHotButtonWnd2                                        0xB01C20
#define pinstCHotButtonWnd3                                        0xB01C24
#define pinstCHotButtonWnd4                                        0xB01C28
#define pinstCItemDisplayManager                                   0xB01CD4
#define pinstCItemExpTransferWnd                                   0xB01CF4
#define pinstCLeadershipWnd                                        0xB01D90
#define pinstCLFGuildWnd                                           0xB01DAC
#define pinstCMIZoneSelectWnd                                      0xB01F1C
#define pinstCAdventureMerchantWnd                                 0xB02014
#define pinstCConfirmationDialog                                   0xB02030
#define pinstCPopupWndManager                                      0xB02030
#define pinstCProgressionSelectionWnd                              0xB02064
#define pinstCPvPLeaderboardWnd                                    0xB02080
#define pinstCPvPStatsWnd                                          0xB0209C
#define pinstCSystemInfoDialogBox                                  0xB0214C
#define pinstCTargetOfTargetWnd                                    0xB02A54
#define pinstCTaskSelectWnd                                        0xB02A88
#define pinstCTaskTemplateSelectWnd                                0xB02AA4
#define pinstCTaskWnd                                              0xB02AC0
#define pinstCTipWndOFDAY                                          0xB02B3C
#define pinstCTipWndCONTEXT                                        0xB02B40
#define pinstCTitleWnd                                             0xB02B5C
#define pinstCTradeskillWnd                                        0xB02BA0
#define pinstCTributeBenefitWnd                                    0xB02BEC
#define pinstCTributeMasterWnd                                     0xB02C08
#define pinstCContextMenuManager                                   0xB10AAC
#define pinstCVoiceMacroWnd                                        0xAD3C84
#define pinstCHtmlWnd                                              0xAD3CC0


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4C40C0
#define __ConvertItemTags                                          0x4B6900
#define __ExecuteCmd                                               0x4A5850
#define __get_melee_range                                          0x4AACA0
#define __GetGaugeValueFromEQ                                      0x63B330
#define __GetLabelFromEQ                                           0x63BFB0
#define __NewUIINI                                                 0x63AF10
#define __ProcessGameEvents                                        0x4F3D80
#define CrashDetected                                              0x55E4F0
#define DrawNetStatus                                              0x5124E0
#define Util__FastTime                                             0x6B1080


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47E720
#define AltAdvManager__IsAbilityReady                              0x47E760
#define AltAdvManager__GetAltAbility                               0x47E980

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x576400

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x57FC10

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6DE8E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x595560
#define CChatManager__InitContextMenu                              0x595D00

// CChatService
#define CChatService__GetNumberOfFriends                           0x6A1240
#define CChatService__GetFriendName                                0x6A1250

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x599F00
#define CChatWindow__Clear                                         0x59A870
#define CChatWindow__WndNotification                               0x59A950

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6C9380
#define CComboWnd__Draw                                            0x6C9530
#define CComboWnd__GetCurChoice                                    0x6C9320
#define CComboWnd__GetListRect                                     0x6C9800
#define CComboWnd__GetTextRect                                     0x6C93B0
#define CComboWnd__InsertChoice                                    0x6C9870
#define CComboWnd__SetColors                                       0x6C92B0
#define CComboWnd__SetChoice                                       0x6C92E0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5A1440
#define CContainerWnd__vftable                                     0x7DD8D0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46D3E0
#define CDisplay__GetClickedActor                                  0x46AA60
#define CDisplay__GetUserDefinedColor                              0x469B80
#define CDisplay__GetWorldFilePath                                 0x4690B0
#define CDisplay__is3dON                                           0x468220
#define CDisplay__ReloadUI                                         0x47B980
#define CDisplay__WriteTextHD2                                     0x46DB50

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x570380
#define CEditBaseWnd__SetSel                                       0x6E9940

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6D1F60
#define CEditWnd__GetCharIndexPt                                   0x6D2DB0
#define CEditWnd__GetDisplayString                                 0x6D20F0
#define CEditWnd__GetHorzOffset                                    0x6D2380
#define CEditWnd__GetLineForPrintableChar                          0x6D2860
#define CEditWnd__GetSelStartPt                                    0x6D3000
#define CEditWnd__GetSTMLSafeText                                  0x6D2520
#define CEditWnd__PointFromPrintableChar                           0x6D2970
#define CEditWnd__SelectableCharFromPoint                          0x6D2AF0
#define CEditWnd__SetEditable                                      0x6D24F0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4D76E0
#define CEverQuest__DropHeldItemOnGround                           0x4DBB10
#define CEverQuest__dsp_chat                                       0x4DD030
#define CEverQuest__DoTellWindow                                   0x4DBC90
#define CEverQuest__EnterZone                                      0x4F2740
#define CEverQuest__GetBodyTypeDesc                                0x4D48F0
#define CEverQuest__GetClassDesc                                   0x4D4050
#define CEverQuest__GetClassThreeLetterCode                        0x4D4650
#define CEverQuest__GetDeityDesc                                   0x4D4F60
#define CEverQuest__GetLangDesc                                    0x4D4C80
#define CEverQuest__GetRaceDesc                                    0x4D4F30
#define CEverQuest__InterpretCmd                                   0x4DDA90
#define CEverQuest__LeftClickedOnPlayer                            0x4F0EE0
#define CEverQuest__LMouseUp                                       0x4F3520
#define CEverQuest__RightClickedOnPlayer                           0x4F12B0
#define CEverQuest__RMouseUp                                       0x4F2D40
#define CEverQuest__SetGameState                                   0x4D7B60
#define CEverQuest__Emote                                          0x4DD220

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5AE030
#define CGaugeWnd__CalcLinesFillRect                               0x5AE090
#define CGaugeWnd__Draw                                            0x5AE4A0

// CGuild
#define CGuild__FindMemberByName                                   0x421570

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5C6190

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5CF6D0
#define CInvSlotMgr__MoveItem                                      0x5CF870

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5CE090
#define CInvSlot__SliderComplete                                   0x5CE5A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5DE530
#define CItemDisplayWnd__SetSpell                                  0x638FF0

// CLabel 
#define CLabel__Draw                                               0x5E3E40

// CListWnd 
#define CListWnd__AddColumn                                        0x6C3B40
#define CListWnd__AddColumn1                                       0x6C3610
#define CListWnd__AddLine                                          0x6C3140
#define CListWnd__AddString                                        0x6C3340
#define CListWnd__CalculateFirstVisibleLine                        0x6C0520
#define CListWnd__CalculateVSBRange                                0x6C2180
#define CListWnd__ClearAllSel                                      0x6BFC50
#define CListWnd__CloseAndUpdateEditWindow                         0x6C0B65
#define CListWnd__Compare                                          0x6C0EF0
#define CListWnd__Draw                                             0x6C1E70
#define CListWnd__DrawColumnSeparators                             0x6C1CE0
#define CListWnd__DrawHeader                                       0x6BFE20
#define CListWnd__DrawItem                                         0x6C1600
#define CListWnd__DrawLine                                         0x6C1980
#define CListWnd__DrawSeparator                                    0x6C1D80
#define CListWnd__EnsureVisible                                    0x6C0570
#define CListWnd__ExtendSel                                        0x6C1520
#define CListWnd__GetColumnMinWidth                                0x6BFA60
#define CListWnd__GetColumnWidth                                   0x6BF9A0
#define CListWnd__GetCurSel                                        0x6BF480
#define CListWnd__GetHeaderRect                                    0x6BF570
#define CListWnd__GetItemAtPoint                                   0x6C0870
#define CListWnd__GetItemAtPoint1                                  0x6C08E0
#define CListWnd__GetItemData                                      0x6BF750
#define CListWnd__GetItemHeight                                    0x6C02B0
#define CListWnd__GetItemIcon                                      0x6BF8E0
#define CListWnd__GetItemRect                                      0x6C0650
#define CListWnd__GetItemText                                      0x6BF790
#define CListWnd__GetSelList                                       0x6C34F0
#define CListWnd__GetSeparatorRect                                 0x6C0E30
#define CListWnd__RemoveLine                                       0x6C3AF0
#define CListWnd__SetColors                                        0x6BF4E0
#define CListWnd__SetColumnJustification                           0x6BFAC0
#define CListWnd__SetColumnWidth                                   0x6BFA20
#define CListWnd__SetCurSel                                        0x6BF4C0
#define CListWnd__SetItemColor                                     0x6C2DB0
#define CListWnd__SetItemData                                      0x6BFCF0
#define CListWnd__SetItemText                                      0x6C2D30
#define CListWnd__ShiftColumnSeparator                             0x6C1490
#define CListWnd__Sort                                             0x6C3B70
#define CListWnd__ToggleSel                                        0x6BFBC0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5F9060

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x604260
#define CMerchantWnd__RequestBuyItem                               0x6055E0
#define CMerchantWnd__RequestSellItem                              0x6044B0
#define CMerchantWnd__SelectBuySellSlot                            0x605310

// CObfuscator
#define CObfuscator__doit                                          0x67C880

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6DA330
#define CSidlManager__CreateLabel                                  0x632000

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x6CAFA0
#define CSidlScreenWnd__CalculateVSBRange                          0x6DFE70
#define CSidlScreenWnd__ConvertToRes                               0x6E9820
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6CB410
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6CC500
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6CC5B0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6CBCB0
#define CSidlScreenWnd__DrawSidlPiece                              0x6CB0E0
#define CSidlScreenWnd__EnableIniStorage                           0x6CAC90
#define CSidlScreenWnd__GetSidlPiece                               0x6CB2E0
#define CSidlScreenWnd__Init1                                      0x6CC360
#define CSidlScreenWnd__LoadIniInfo                                0x6CB4D0
#define CSidlScreenWnd__LoadIniListWnd                             0x6CADE0
#define CSidlScreenWnd__LoadSidlScreen                             0x6CBF00
#define CSidlScreenWnd__StoreIniInfo                               0x6CA8A0
#define CSidlScreenWnd__WndNotification                            0x6CC0E0
#define CSidlScreenWnd__GetChildItem                               0x6CACF0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x534A10

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6EACC0
#define CSliderWnd__SetValue                                       0x6EADC0
#define CSliderWnd__SetNumTicks                                    0x6EB340

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x637760

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6E7AE0
#define CStmlWnd__CalculateVSBRange                                0x6DFE70
#define CStmlWnd__CanBreakAtCharacter                              0x6DFFB0
#define CStmlWnd__FastForwardToEndOfTag                            0x6E0AB0
#define CStmlWnd__ForceParseNow                                    0x6E7F30
#define CStmlWnd__GetNextTagPiece                                  0x6E09D0
#define CStmlWnd__GetSTMLText                                      0x599EA0
#define CStmlWnd__GetThisChar                                      0x70CEF0
#define CStmlWnd__GetVisiableText                                  0x6E1CE0
#define CStmlWnd__InitializeWindowVariables                        0x6E3E20
#define CStmlWnd__MakeStmlColorTag                                 0x6DF550
#define CStmlWnd__MakeWndNotificationTag                           0x6DF5F0
#define CStmlWnd__SetSTMLText                                      0x6E3F40
#define CStmlWnd__StripFirstSTMLLines                              0x6E7860
#define CStmlWnd__UpdateHistoryString                              0x6E2540

// CTabWnd 
#define CTabWnd__Draw                                              0x6EC0E0
#define CTabWnd__DrawCurrentPage                                   0x6EBAF0
#define CTabWnd__DrawTab                                           0x6EB8D0
#define CTabWnd__GetCurrentPage                                    0x6EBD70
#define CTabWnd__GetPageClientRect                                 0x6EB5A0
#define CTabWnd__GetPageFromTabIndex                               0x6EB800
#define CTabWnd__GetPageInnerRect                                  0x6EB600
#define CTabWnd__GetTabInnerRect                                   0x6EB780
#define CTabWnd__GetTabRect                                        0x6EB690
#define CTabWnd__IndexInBounds                                     0x6EB89D
#define CTabWnd__InsertPage                                        0x6EC350
#define CTabWnd__SetPage                                           0x6EBDB0
#define CTabWnd__SetPageRect                                       0x6EC010
#define CTabWnd__UpdatePage                                        0x6EC2D0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x41DA60

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6CC910

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6F0650

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6BF1F0

// CXRect 
#define CXRect__CenterPoint                                        0x575A90

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x41BDD0
#define CXStr__CXStr1                                              0x531B00
#define CXStr__CXStr3                                              0x6B27D0
#define CXStr__dCXStr                                              0x466AD0
#define CXStr__operator_equal1                                     0x6B2990
#define CXStr__operator_plus_equal1                                0x6B3890

// CXWnd 
#define CXWnd__BringToTop                                          0x6C4280
#define CXWnd__Center                                              0x6C7D40
#define CXWnd__ClrFocus                                            0x6C3F70
#define CXWnd__DoAllDrawing                                        0x6C8B20
#define CXWnd__DrawChildren                                        0x6C8C50
#define CXWnd__DrawColoredRect                                     0x6C4500
#define CXWnd__DrawTooltip                                         0x6C8950
#define CXWnd__DrawTooltipAtPoint                                  0x6C7AF0
#define CXWnd__GetBorderFrame                                      0x6C4980
#define CXWnd__GetChildWndAt                                       0x6C7610
#define CXWnd__GetClientClipRect                                   0x6C48C0
#define CXWnd__GetScreenClipRect                                   0x6C7F60
#define CXWnd__GetScreenRect                                       0x6C4B90
#define CXWnd__GetTooltipRect                                      0x6C4720
#define CXWnd__GetWindowTextA                                      0x5690E0
#define CXWnd__IsActive                                            0x6CDA40
#define CXWnd__IsDescendantOf                                      0x6C4930
#define CXWnd__IsReallyVisible                                     0x6C75F0
#define CXWnd__IsType                                              0x6ED550
#define CXWnd__Move                                                0x6C71C0
#define CXWnd__Move1                                               0x6C87B0
#define CXWnd__ProcessTransition                                   0x6C4240
#define CXWnd__Refade                                              0x6C4020
#define CXWnd__Resize                                              0x6C4C50
#define CXWnd__Right                                               0x6C7EA0
#define CXWnd__SetFocus                                            0x6C63A0
#define CXWnd__SetKeyTooltip                                       0x6C4E60
#define CXWnd__SetMouseOver                                        0x6C4E30
#define CXWnd__StartFade                                           0x6C42C0
#define CXWnd__GetChildItem                                        0x6C8120

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6CEED0
#define CXWndManager__DrawWindows                                  0x6CEAE0
#define CXWndManager__GetKeyboardFlags                             0x6CD6D0
#define CXWndManager__HandleKeyboardMsg                            0x6CDC40
#define CXWndManager__RemoveWnd                                    0x6CDB60

// CDBStr
#define CDBStr__GetString                                          0x466B70

// EQ_Character 
#define EQ_Character__CastRay                                      0x719000
#define EQ_Character__CastSpell                                    0x42EEC0
#define EQ_Character__Cur_HP                                       0x43BE60
#define EQ_Character__GetAACastingTimeModifier                     0x4295C0
#define EQ_Character__GetCharInfo2                                 0x692610
#define EQ_Character__GetFocusCastingTimeModifier                  0x425160
#define EQ_Character__GetFocusRangeModifier                        0x4252A0
#define EQ_Character__Max_Endurance                                0x518600
#define EQ_Character__Max_HP                                       0x436D60
#define EQ_Character__Max_Mana                                     0x518430
#define EQ_Character__doCombatAbility                              0x517360
#define EQ_Character__UseSkill                                     0x441F50
#define EQ_Character__GetConLevel                                  0x513910

// EQ_Item 
#define EQ_Item__CanDrop                                           0x5016C0
#define EQ_Item__GetItemLinkHash                                   0x686390
#define EQ_Item__IsStackable                                       0x67D160

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x47F850
#define EQ_LoadingS__Array                                         0x854930

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x51B470
#define EQ_PC__GetAltAbilityIndex                                  0x68AB80
#define EQ_PC__GetCombatAbility                                    0x68AC10
#define EQ_PC__GetCombatAbilityTimer                               0x68ACC0
#define EQ_PC__GetItemTimerValue                                   0x516280
#define EQ_PC__HasLoreItem                                         0x519940

// EQItemList 
#define EQItemList__dEQItemList                                    0x4A9410
#define EQItemList__EQItemList                                     0x4A9360

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x4664B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x51FCA0
#define EQPlayer__dEQPlayer                                        0x523C70
#define EQPlayer__DoAttack                                         0x530C40
#define EQPlayer__EQPlayer                                         0x527930
#define EQPlayer__SetNameSpriteState                               0x521C40
#define EQPlayer__SetNameSpriteTint                                0x51FD10
#define EQPlayer__IsBodyType_j                                     0x7189D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5289F0
#define EQPlayerManager__GetSpawnByName                            0x528BD0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x503360
#define KeypressHandler__AttachKeyToEqCommand                      0x5033A0
#define KeypressHandler__ClearCommandStateArray                    0x503170
#define KeypressHandler__HandleKeyDown                             0x501D20
#define KeypressHandler__HandleKeyUp                               0x502030
#define KeypressHandler__SaveKeymapping                            0x503240

// MapViewMap 
#define MapViewMap__Clear                                          0x5F4730
#define MapViewMap__SaveEx                                         0x5F5100

#define OtherCharData__GetAltCurrency                              0x6A9990

// StringTable 
#define StringTable__getString                                     0x67CB00
