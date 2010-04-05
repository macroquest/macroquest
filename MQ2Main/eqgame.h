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
#define __ExpectedVersionDate                                     "Dec 19 2008"
#define __ExpectedVersionTime                                     "15:22:49"
#define __ActualVersionDate                                        0x7D6D3C
#define __ActualVersionTime                                        0x7D6D48

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x509A00
#define __MemChecker1                                              0x6B02E0
#define __MemChecker2                                              0x55F5C0
#define __MemChecker3                                              0x55F510
#define __MemChecker4                                              0x672B60
#define __EncryptPad0                                              0x85B430
#define __EncryptPad1                                              0x865970
#define __EncryptPad2                                              0x85DE70
#define __EncryptPad3                                              0x85DA70
#define __EncryptPad4                                              0x865040

// Direct Input
#define DI8__Main                                                  0xAD6C34
#define DI8__Keyboard                                              0xAD6C38
#define DI8__Mouse                                                 0xAD6C3C
#define __AltTimerReady                                            0xA616FA
#define __Attack                                                   0xAC1196
#define __Autofire                                                 0xAC1197
#define __BindList                                                 0x856450
#define __Clicks                                                   0xA60410
#define __CommandList                                              0x856CB0
#define __CurrentMapLabel                                          0xB01E58
#define __CurrentSocial                                            0x852680
#define __DoAbilityAvailable                                       0xA61694
#define __DoAbilityList                                            0xA96CAC
#define __do_loot                                                  0x4B1270
#define __DrawHandler                                              0xB112BC
#define __GroupCount                                               0xA40AC2
#define __Guilds                                                   0xA42640
#define __gWorld                                                   0xA42580
#define __HotkeyPage                                               0xABE098
#define __HWnd                                                     0xAD6974
#define __InChatMode                                               0xA60348
#define __LastTell                                                 0xA62004
#define __LMouseHeldTime                                           0xA60430
#define __Mouse                                                    0xAD6C40
#define __MouseLook                                                0xA603DE
#define __MouseEventTime                                           0xAC12A0
#define __NetStatusToggle                                          0xA603E1
#define __PCNames                                                  0xA61A50
#define __RangeAttackReady                                         0xA616F8
#define __RMouseHeldTime                                           0xA6042C
#define __RunWalkState                                             0xA6034C
#define __ScreenMode                                               0x990390
#define __ScreenX                                                  0xA60300
#define __ScreenY                                                  0xA60304
#define __ScreenXMax                                               0xA60308
#define __ScreenYMax                                               0xA6030C
#define __ServerHost                                               0xA40A04
#define __ServerName                                               0xA96C6C
#define __ShiftKeyDown                                             0xA609B0
#define __ShowNames                                                0xA61924
#define __Socials                                                  0xA96D6C


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA5A290
#define instEQZoneInfo                                             0xA6057C
#define instKeypressHandler                                        0xAC1284
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
#define pinstCEverQuest                                            0xAD6DB8
#define pinstCharData                                              0xA425E4
#define pinstCharSpawn                                             0xA4260C
#define pinstControlledMissile                                     0xA425E0
#define pinstControlledPlayer                                      0xA4260C
#define pinstCSidlManager                                          0xB10A40
#define pinstCXWndManager                                          0xB10A38
#define instDynamicZone                                            0xA5FD50
#define pinstDZMember                                              0xA5FE60
#define pinstDZTimerInfo                                           0xA5FE64
#define pinstEQItemList                                            0xA425C8
#define instEQMisc                                                 0x990338
#define pinstEQSoundManager                                        0x991214
#define instExpeditionLeader                                       0xA5FD9A
#define instExpeditionName                                         0xA5FDDA
#define pinstGroup                                                 0xA40ABE
#define pinstImeManager                                            0xB10A44
#define pinstLocalPlayer                                           0xA425F8
#define pinstModelPlayer                                           0xA42624
#define pinstPCData                                                0xA425E4
#define pinstSkillMgr                                              0xAD3A8C
#define pinstSpawnManager                                          0xAD3A0C
#define pinstSpellManager                                          0xAD3A90
#define pinstSpellSets                                             0xABE09C
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
#define pinstCAdventureLeaderboardWnd                              0xAFF3A0
#define pinstCAdventureRequestWnd                                  0xAFF3BC
#define pinstCAltStorageWnd                                        0xAFF41C
#define pinstCAdventureStatsWnd                                    0xAFF3D8
#define pinstCBarterMerchantWnd                                    0xAFF5E8
#define pinstCBarterSearchWnd                                      0xAFF604
#define pinstCBarterWnd                                            0xAFF620
#define pinstCChatManager                                          0xAFF8C4
#define pinstCDynamicZoneWnd                                       0xAFF9BC
#define pinstCEQMainWnd                                            0xAFFA30
#define pinstCFellowshipWnd                                        0xAFFA94
#define pinstCFindLocationWnd                                      0xAFFAC8
#define pinstCGroupSearchWnd                                       0xAFFB78
#define pinstCGroupWnd                                             0xAFFB94
#define pinstCGuildBankWnd                                         0xAFFBB0
#define pinstCGuildMgmtWnd                                         0xB01BD0
#define pinstCGuildTributeMasterWnd                                0xB01BF0
#define pinstCHotButtonWnd                                         0xB01C0C
#define pinstCHotButtonWnd1                                        0xB01C0C
#define pinstCHotButtonWnd2                                        0xB01C10
#define pinstCHotButtonWnd3                                        0xB01C14
#define pinstCHotButtonWnd4                                        0xB01C18
#define pinstCItemDisplayManager                                   0xB01CC4
#define pinstCItemExpTransferWnd                                   0xB01CE4
#define pinstCLeadershipWnd                                        0xB01D80
#define pinstCLFGuildWnd                                           0xB01D9C
#define pinstCMIZoneSelectWnd                                      0xB01F0C
#define pinstCAdventureMerchantWnd                                 0xB02004
#define pinstCConfirmationDialog                                   0xB02020
#define pinstCPopupWndManager                                      0xB02020
#define pinstCProgressionSelectionWnd                              0xB02054
#define pinstCPvPLeaderboardWnd                                    0xB02070
#define pinstCPvPStatsWnd                                          0xB0208C
#define pinstCSystemInfoDialogBox                                  0xB0213C
#define pinstCTargetOfTargetWnd                                    0xB02A44
#define pinstCTaskSelectWnd                                        0xB02A78
#define pinstCTaskTemplateSelectWnd                                0xB02A94
#define pinstCTaskWnd                                              0xB02AB0
#define pinstCTipWndOFDAY                                          0xB02B2C
#define pinstCTipWndCONTEXT                                        0xB02B30
#define pinstCTitleWnd                                             0xB02B4C
#define pinstCTradeskillWnd                                        0xB02B90
#define pinstCTributeBenefitWnd                                    0xB02BDC
#define pinstCTributeMasterWnd                                     0xB02BF8
#define pinstCContextMenuManager                                   0xB10A9C
#define pinstCVoiceMacroWnd                                        0xAD3C74
#define pinstCHtmlWnd                                              0xAD3CB0


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4C3E40
#define __ConvertItemTags                                          0x4B6680
#define __ExecuteCmd                                               0x4A5580
#define __get_melee_range                                          0x4AAA20
#define __GetGaugeValueFromEQ                                      0x63AD50
#define __GetLabelFromEQ                                           0x63B9D0
#define __NewUIINI                                                 0x63A930
#define __ProcessGameEvents                                        0x4F3A60
#define CrashDetected                                              0x55E290
#define DrawNetStatus                                              0x512280
#define Util__FastTime                                             0x6B0A30


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47E500
#define AltAdvManager__IsAbilityReady                              0x47E540
#define AltAdvManager__GetAltAbility                               0x47E810

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x576090

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x57F470

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6DE1A0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5950D0
#define CChatManager__InitContextMenu                              0x595870

// CChatService
#define CChatService__GetNumberOfFriends                           0x6A0B80
#define CChatService__GetFriendName                                0x6A0B90

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x599A70
#define CChatWindow__WndNotification                               0x59A4C0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6C8C00
#define CComboWnd__Draw                                            0x6C8DB0
#define CComboWnd__GetCurChoice                                    0x6C8BA0
#define CComboWnd__GetListRect                                     0x6C9080
#define CComboWnd__GetTextRect                                     0x6C8C30
#define CComboWnd__InsertChoice                                    0x6C90F0
#define CComboWnd__SetColors                                       0x6C8B30
#define CComboWnd__SetChoice                                       0x6C8B60

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5A10E0
#define CContainerWnd__vftable                                     0x7DD8F8

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46D110
#define CDisplay__GetClickedActor                                  0x46A7A0
#define CDisplay__GetUserDefinedColor                              0x4698C0
#define CDisplay__GetWorldFilePath                                 0x468E10
#define CDisplay__is3dON                                           0x467F80
#define CDisplay__ReloadUI                                         0x47B720
#define CDisplay__WriteTextHD2                                     0x46D880

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x570110
#define CEditBaseWnd__SetSel                                       0x6E91E0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6D18C0
#define CEditWnd__GetCharIndexPt                                   0x6D2710
#define CEditWnd__GetDisplayString                                 0x6D1A50
#define CEditWnd__GetHorzOffset                                    0x6D1CE0
#define CEditWnd__GetLineForPrintableChar                          0x6D21C0
#define CEditWnd__GetSelStartPt                                    0x6D2960
#define CEditWnd__GetSTMLSafeText                                  0x6D1E80
#define CEditWnd__PointFromPrintableChar                           0x6D22D0
#define CEditWnd__SelectableCharFromPoint                          0x6D2450
#define CEditWnd__SetEditable                                      0x6D1E50

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4D7410
#define CEverQuest__DropHeldItemOnGround                           0x4DB840
#define CEverQuest__dsp_chat                                       0x4DCD60
#define CEverQuest__DoTellWindow                                   0x4DB9C0
#define CEverQuest__EnterZone                                      0x4F2420
#define CEverQuest__GetBodyTypeDesc                                0x4D4660
#define CEverQuest__GetClassDesc                                   0x4D3DC0
#define CEverQuest__GetClassThreeLetterCode                        0x4D43C0
#define CEverQuest__GetDeityDesc                                   0x4D4CD0
#define CEverQuest__GetLangDesc                                    0x4D49F0
#define CEverQuest__GetRaceDesc                                    0x4D4CA0
#define CEverQuest__InterpretCmd                                   0x4DD7C0
#define CEverQuest__LeftClickedOnPlayer                            0x4F0BC0
#define CEverQuest__LMouseUp                                       0x4F3200
#define CEverQuest__RightClickedOnPlayer                           0x4F0F90
#define CEverQuest__RMouseUp                                       0x4F2A20
#define CEverQuest__SetGameState                                   0x4D7890
#define CEverQuest__Emote                                          0x4DCF50

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5ADCD0
#define CGaugeWnd__CalcLinesFillRect                               0x5ADD30
#define CGaugeWnd__Draw                                            0x5AE140

// CGuild
#define CGuild__FindMemberByName                                   0x421620

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5C5E80

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5CF3D0
#define CInvSlotMgr__MoveItem                                      0x5CF570

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5CDD90
#define CInvSlot__SliderComplete                                   0x5CE2A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5DE2D0
#define CItemDisplayWnd__SetSpell                                  0x638AB0

// CLabel 
#define CLabel__Draw                                               0x5E3BD0

// CListWnd 
#define CListWnd__AddColumn                                        0x6C33D0
#define CListWnd__AddColumn1                                       0x6C2E90
#define CListWnd__AddLine                                          0x6C29C0
#define CListWnd__AddString                                        0x6C2BC0
#define CListWnd__CalculateFirstVisibleLine                        0x6BFDA0
#define CListWnd__CalculateVSBRange                                0x6C1A00
#define CListWnd__ClearAllSel                                      0x6BF4D0
#define CListWnd__CloseAndUpdateEditWindow                         0x6C03E5
#define CListWnd__Compare                                          0x6C0770
#define CListWnd__Draw                                             0x6C16F0
#define CListWnd__DrawColumnSeparators                             0x6C1560
#define CListWnd__DrawHeader                                       0x6BF6A0
#define CListWnd__DrawItem                                         0x6C0E80
#define CListWnd__DrawLine                                         0x6C1200
#define CListWnd__DrawSeparator                                    0x6C1600
#define CListWnd__EnsureVisible                                    0x6BFDF0
#define CListWnd__ExtendSel                                        0x6C0DA0
#define CListWnd__GetColumnMinWidth                                0x6BF2E0
#define CListWnd__GetColumnWidth                                   0x6BF220
#define CListWnd__GetCurSel                                        0x6BED00
#define CListWnd__GetHeaderRect                                    0x6BEDF0
#define CListWnd__GetItemAtPoint                                   0x6C00F0
#define CListWnd__GetItemAtPoint1                                  0x6C0160
#define CListWnd__GetItemData                                      0x6BEFD0
#define CListWnd__GetItemHeight                                    0x6BFB30
#define CListWnd__GetItemIcon                                      0x6BF160
#define CListWnd__GetItemRect                                      0x6BFED0
#define CListWnd__GetItemText                                      0x6BF010
#define CListWnd__GetSelList                                       0x6C2D70
#define CListWnd__GetSeparatorRect                                 0x6C06B0
#define CListWnd__RemoveLine                                       0x6C3380
#define CListWnd__SetColors                                        0x6BED60
#define CListWnd__SetColumnJustification                           0x6BF340
#define CListWnd__SetColumnWidth                                   0x6BF2A0
#define CListWnd__SetCurSel                                        0x6BED40
#define CListWnd__SetItemColor                                     0x6C2630
#define CListWnd__SetItemData                                      0x6BF570
#define CListWnd__SetItemText                                      0x6C25B0
#define CListWnd__ShiftColumnSeparator                             0x6C0D10
#define CListWnd__Sort                                             0x6C3400
#define CListWnd__ToggleSel                                        0x6BF440

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5F8D60

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x603F50
#define CMerchantWnd__RequestBuyItem                               0x6052D0
#define CMerchantWnd__RequestSellItem                              0x6041A0
#define CMerchantWnd__SelectBuySellSlot                            0x605000

// CObfuscator
#define CObfuscator__doit                                          0x67C1F0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6D9BE0
#define CSidlManager__CreateLabel                                  0x631AC0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x6CA8D0
#define CSidlScreenWnd__CalculateVSBRange                          0x6DF710
#define CSidlScreenWnd__ConvertToRes                               0x6E90C0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6CAD40
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6CBE30
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6CBEE0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6CB5E0
#define CSidlScreenWnd__DrawSidlPiece                              0x6CAA10
#define CSidlScreenWnd__EnableIniStorage                           0x6CA510
#define CSidlScreenWnd__GetSidlPiece                               0x6CAC10
#define CSidlScreenWnd__Init1                                      0x6CBC90
#define CSidlScreenWnd__LoadIniInfo                                0x6CAE00
#define CSidlScreenWnd__LoadIniListWnd                             0x6CA660
#define CSidlScreenWnd__LoadSidlScreen                             0x6CB830
#define CSidlScreenWnd__StoreIniInfo                               0x6CA120
#define CSidlScreenWnd__WndNotification                            0x6CBA10
#define CSidlScreenWnd__GetChildItem                               0x6CA570

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x5346E0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6EA560
#define CSliderWnd__SetValue                                       0x6EA660
#define CSliderWnd__SetNumTicks                                    0x6EABE0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x637220

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6E7380
#define CStmlWnd__CalculateVSBRange                                0x6DF710
#define CStmlWnd__CanBreakAtCharacter                              0x6DF850
#define CStmlWnd__FastForwardToEndOfTag                            0x6E0350
#define CStmlWnd__ForceParseNow                                    0x6E77D0
#define CStmlWnd__GetNextTagPiece                                  0x6E0270
#define CStmlWnd__GetSTMLText                                      0x599A10
#define CStmlWnd__GetThisChar                                      0x70C800
#define CStmlWnd__GetVisiableText                                  0x6E1580
#define CStmlWnd__InitializeWindowVariables                        0x6E36C0
#define CStmlWnd__MakeStmlColorTag                                 0x6DEE10
#define CStmlWnd__MakeWndNotificationTag                           0x6DEEB0
#define CStmlWnd__SetSTMLText                                      0x6E37E0
#define CStmlWnd__StripFirstSTMLLines                              0x6E7100
#define CStmlWnd__UpdateHistoryString                              0x6E1DE0

// CTabWnd 
#define CTabWnd__Draw                                              0x6EB980
#define CTabWnd__DrawCurrentPage                                   0x6EB390
#define CTabWnd__DrawTab                                           0x6EB170
#define CTabWnd__GetCurrentPage                                    0x6EB610
#define CTabWnd__GetPageClientRect                                 0x6EAE40
#define CTabWnd__GetPageFromTabIndex                               0x6EB0A0
#define CTabWnd__GetPageInnerRect                                  0x6EAEA0
#define CTabWnd__GetTabInnerRect                                   0x6EB020
#define CTabWnd__GetTabRect                                        0x6EAF30
#define CTabWnd__IndexInBounds                                     0x6EB13D
#define CTabWnd__InsertPage                                        0x6EBBF0
#define CTabWnd__SetPage                                           0x6EB650
#define CTabWnd__SetPageRect                                       0x6EB8B0
#define CTabWnd__UpdatePage                                        0x6EBB70

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x41DB10

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6CC240

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6EFF10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6BEA70

// CXRect 
#define CXRect__CenterPoint                                        0x575720

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x41BDD0
#define CXStr__CXStr1                                              0x6B86E0
#define CXStr__CXStr3                                              0x6B2130
#define CXStr__dCXStr                                              0x6EC6B0
#define CXStr__operator_equal1                                     0x6B22F0
#define CXStr__operator_plus_equal1                                0x6B31F0

// CXWnd 
#define CXWnd__BringToTop                                          0x6C3B10
#define CXWnd__Center                                              0x6C7610
#define CXWnd__ClrFocus                                            0x6C3800
#define CXWnd__DoAllDrawing                                        0x6C83A0
#define CXWnd__DrawChildren                                        0x6C84D0
#define CXWnd__DrawColoredRect                                     0x6C3D80
#define CXWnd__DrawTooltip                                         0x6C81D0
#define CXWnd__DrawTooltipAtPoint                                  0x6C73C0
#define CXWnd__GetBorderFrame                                      0x6C4200
#define CXWnd__GetChildWndAt                                       0x6C6EE0
#define CXWnd__GetClientClipRect                                   0x6C4140
#define CXWnd__GetScreenClipRect                                   0x6C7830
#define CXWnd__GetScreenRect                                       0x6C4410
#define CXWnd__GetTooltipRect                                      0x6C3FA0
#define CXWnd__GetWindowTextA                                      0x568E50
#define CXWnd__IsActive                                            0x6CD370
#define CXWnd__IsDescendantOf                                      0x6C41B0
#define CXWnd__IsReallyVisible                                     0x6C6EC0
#define CXWnd__IsType                                              0x6ECE10
#define CXWnd__Move                                                0x6C6A90
#define CXWnd__Move1                                               0x6C8030
#define CXWnd__ProcessTransition                                   0x6C3AD0
#define CXWnd__Refade                                              0x6C38B0
#define CXWnd__Resize                                              0x6C44D0
#define CXWnd__Right                                               0x6C7770
#define CXWnd__SetFocus                                            0x6C5C70
#define CXWnd__SetKeyTooltip                                       0x6C46E0
#define CXWnd__SetMouseOver                                        0x6C46B0
#define CXWnd__StartFade                                           0x6C3B50
#define CXWnd__GetChildItem                                        0x6C79A0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6CE830
#define CXWndManager__DrawWindows                                  0x6CE440
#define CXWndManager__GetKeyboardFlags                             0x6CD000
#define CXWndManager__HandleKeyboardMsg                            0x6CD570
#define CXWndManager__RemoveWnd                                    0x6CD490

// CDBStr
#define CDBStr__GetString                                          0x4668E0

// EQ_Character 
#define EQ_Character__CastRay                                      0x7188B0
#define EQ_Character__CastSpell                                    0x42EF30
#define EQ_Character__Cur_HP                                       0x43BED0
#define EQ_Character__GetAACastingTimeModifier                     0x429610
#define EQ_Character__GetCharInfo2                                 0x691F60
#define EQ_Character__GetFocusCastingTimeModifier                  0x4251D0
#define EQ_Character__GetFocusRangeModifier                        0x425310
#define EQ_Character__Max_Endurance                                0x518360
#define EQ_Character__Max_HP                                       0x436DD0
#define EQ_Character__Max_Mana                                     0x518190
#define EQ_Character__doCombatAbility                              0x5170C0
#define EQ_Character__UseSkill                                     0x441FC0
#define EQ_Character__GetConLevel                                  0x5136A0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x5012F0
#define EQ_Item__GetItemLinkHash                                   0x685D00
#define EQ_Item__IsStackable                                       0x67CAD0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x47F6E0
#define EQ_LoadingS__Array                                         0x854930

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x51B1D0
#define EQ_PC__GetAltAbilityIndex                                  0x68A4C0
#define EQ_PC__GetCombatAbility                                    0x68A550
#define EQ_PC__GetCombatAbilityTimer                               0x68A600
#define EQ_PC__GetItemTimerValue                                   0x516010
#define EQ_PC__HasLoreItem                                         0x5196A0

// EQItemList 
#define EQItemList__dEQItemList                                    0x4A9140
#define EQItemList__EQItemList                                     0x4A9090

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x466290

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x51F9E0
#define EQPlayer__dEQPlayer                                        0x523A80
#define EQPlayer__DoAttack                                         0x530970
#define EQPlayer__EQPlayer                                         0x5276F0
#define EQPlayer__SetNameSpriteState                               0x521980
#define EQPlayer__SetNameSpriteTint                                0x51FA50
#define EQPlayer__IsBodyType_j                                     0x718280

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5287B0
#define EQPlayerManager__GetSpawnByName                            0x528990

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x502F90
#define KeypressHandler__AttachKeyToEqCommand                      0x502FD0
#define KeypressHandler__ClearCommandStateArray                    0x502DA0
#define KeypressHandler__HandleKeyDown                             0x501950
#define KeypressHandler__HandleKeyUp                               0x501C60
#define KeypressHandler__SaveKeymapping                            0x502E70

// MapViewMap 
#define MapViewMap__Clear                                          0x5F4430
#define MapViewMap__SaveEx                                         0x5F4E00

#define OtherCharData__GetAltCurrency                              0x6A9240

// StringTable 
#define StringTable__getString                                     0x67C470
