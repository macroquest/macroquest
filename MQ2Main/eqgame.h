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
#define __ExpectedVersionDate                                     "Dec 10 2008"
#define __ExpectedVersionTime                                     "15:47:47"
#define __ActualVersionDate                                        0x7D6D74
#define __ActualVersionTime                                        0x7D6D80

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x509B70
#define __MemChecker1                                              0x6B0010
#define __MemChecker2                                              0x55F490
#define __MemChecker3                                              0x55F3E0
#define __MemChecker4                                              0x672810
#define __EncryptPad0                                              0x85B418
#define __EncryptPad1                                              0x865948
#define __EncryptPad2                                              0x85DE58
#define __EncryptPad3                                              0x85DA58
#define __EncryptPad4                                              0x865018

// Direct Input
#define DI8__Main                                                  0xAD6BF4
#define DI8__Keyboard                                              0xAD6BF8
#define DI8__Mouse                                                 0xAD6BFC
#define __AltTimerReady                                            0xA616BA
#define __Attack                                                   0xAC1156
#define __Autofire                                                 0xAC1157
#define __BindList                                                 0x856450
#define __Clicks                                                   0xA603D0
#define __CommandList                                              0x856CB0
#define __CurrentMapLabel                                          0xB01E18
#define __CurrentSocial                                            0x852680
#define __DoAbilityAvailable                                       0xA61654
#define __DoAbilityList                                            0xA96C6C
#define __do_loot                                                  0x4B1510
#define __DrawHandler                                              0xB1127C
#define __GroupCount                                               0xA40A82
#define __Guilds                                                   0xA42600
#define __gWorld                                                   0xA42540
#define __HotkeyPage                                               0xABE058
#define __HWnd                                                     0xAD6934
#define __InChatMode                                               0xA60308
#define __LastTell                                                 0xA61FC4
#define __LMouseHeldTime                                           0xA603F0
#define __Mouse                                                    0xAD6C00
#define __MouseLook                                                0xA6039E
#define __NetStatusToggle                                          0xA603A0
#define __PCNames                                                  0xA61A10
#define __RangeAttackReady                                         0xA616B8
#define __RMouseHeldTime                                           0xA603EC
#define __RunWalkState                                             0xA6030C
#define __ScreenMode                                               0x990350
#define __ScreenX                                                  0xA602C0
#define __ScreenY                                                  0xA602C4
#define __ScreenXMax                                               0xA602C8
#define __ScreenYMax                                               0xA602CC
#define __ServerHost                                               0xA409C4
#define __ServerName                                               0xA96C2C
#define __ShiftKeyDown                                             0xA60970
#define __ShowNames                                                0xA618E4
#define __Socials                                                  0xA96D2C


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA5A250
#define instEQZoneInfo                                             0xA6053C
#define instKeypressHandler                                        0xAC1244
#define pinstActiveBanker                                          0xA425D8
#define pinstActiveCorpse                                          0xA425DC
#define pinstActiveGMaster                                         0xA425E0
#define pinstActiveMerchant                                        0xA425D4
#define pinstAltAdvManager                                         0x9911B0
#define pinstAuraMgr                                               0x879C14
#define pinstBandageTarget                                         0xA425C0
#define pinstCamActor                                              0x990CA0
#define pinstCDBStr                                                0x990340
#define pinstCDisplay                                              0xA425E8
#define pinstCEverQuest                                            0xAD6D78
#define pinstCharData                                              0xA425A4
#define pinstCharSpawn                                             0xA425CC
#define pinstControlledMissile                                     0xA425A0
#define pinstControlledPlayer                                      0xA425CC
#define pinstCSidlManager                                          0xB10A00
#define pinstCXWndManager                                          0xB109F8
#define instDynamicZone                                            0xA5FD10
#define pinstDZMember                                              0xA5FE20
#define pinstDZTimerInfo                                           0xA5FE24
#define pinstEQItemList                                            0xA42588
#define instEQMisc                                                 0x9902F8
#define pinstEQSoundManager                                        0x9911D4
#define instExpeditionLeader                                       0xA5FD5A
#define instExpeditionName                                         0xA5FD9A
#define pinstGroup                                                 0xA40A7E
#define pinstImeManager                                            0xB10A04
#define pinstLocalPlayer                                           0xA425B8
#define pinstModelPlayer                                           0xA425E4
#define pinstPCData                                                0xA425A4
#define pinstSkillMgr                                              0xAD3A4C
#define pinstSpawnManager                                          0xAD39CC
#define pinstSpellManager                                          0xAD3A50
#define pinstSpellSets                                             0xABE05C
#define pinstStringTable                                           0xA4255C
#define pinstSwitchManager                                         0xA406C4
#define pinstTarget                                                0xA425D0
#define pinstTargetObject                                          0xA425A8
#define pinstTargetSwitch                                          0xA425AC
#define pinstTaskMember                                            0x9902D8
#define pinstTrackTarget                                           0xA425C4
#define pinstTradeTarget                                           0xA425B4
#define instTributeActive                                          0x99031D
#define pinstViewActor                                             0x990C9C
#define pinstWorldData                                             0xA42584


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x8774C0
#define pinstCAudioTriggersWindow                                  0x87748C
#define pinstCCharacterSelect                                      0x990BAC
#define pinstCFacePick                                             0x990B60
#define pinstCNoteWnd                                              0x990B64
#define pinstCBookWnd                                              0x990B68
#define pinstCPetInfoWnd                                           0x990B6C
#define pinstCTrainWnd                                             0x990B70
#define pinstCSkillsWnd                                            0x990B74
#define pinstCSkillsSelectWnd                                      0x990B78
#define pinstCCombatSkillSelectWnd                                 0x990B7C
#define pinstCFriendsWnd                                           0x990B80
#define pinstCAuraWnd                                              0x990B84
#define pinstCRespawnWnd                                           0x990B88
#define pinstCBandolierWnd                                         0x990B8C
#define pinstCPotionBeltWnd                                        0x990B90
#define pinstCAAWnd                                                0x990B94
#define pinstCGroupSearchFiltersWnd                                0x990B98
#define pinstCLoadskinWnd                                          0x990B9C
#define pinstCAlarmWnd                                             0x990BA0
#define pinstCMusicPlayerWnd                                       0x990BA4
#define pinstCMailWnd                                              0x990BB0
#define pinstCMailCompositionWnd                                   0x990BB4
#define pinstCMailAddressBookWnd                                   0x990BB8
#define pinstCRaidWnd                                              0x990BC0
#define pinstCRaidOptionsWnd                                       0x990BC4
#define pinstCBreathWnd                                            0x990BC8
#define pinstCMapViewWnd                                           0x990BCC
#define pinstCMapToolbarWnd                                        0x990BD0
#define pinstCEditLabelWnd                                         0x990BD4
#define pinstCTargetWnd                                            0x990BD8
#define pinstCColorPickerWnd                                       0x990BDC
#define pinstCPlayerWnd                                            0x990BE0
#define pinstCOptionsWnd                                           0x990BE4
#define pinstCBuffWindowNORMAL                                     0x990BE8
#define pinstCBuffWindowSHORT                                      0x990BEC
#define pinstCharacterCreation                                     0x990BF0
#define pinstCCursorAttachment                                     0x990BF4
#define pinstCCastingWnd                                           0x990BF8
#define pinstCCastSpellWnd                                         0x990BFC
#define pinstCSpellBookWnd                                         0x990C00
#define pinstCInventoryWnd                                         0x990C04
#define pinstCBankWnd                                              0x990C08
#define pinstCQuantityWnd                                          0x990C0C
#define pinstCLootWnd                                              0x990C10
#define pinstCActionsWnd                                           0x990C14
#define pinstCCombatAbilityWnd                                     0x990C18
#define pinstCMerchantWnd                                          0x990C1C
#define pinstCTradeWnd                                             0x990C20
#define pinstCSelectorWnd                                          0x990C24
#define pinstCBazaarWnd                                            0x990C28
#define pinstCBazaarSearchWnd                                      0x990C2C
#define pinstCGiveWnd                                              0x990C30
#define pinstCTrackingWnd                                          0x990C34
#define pinstCInspectWnd                                           0x990C38
#define pinstCSocialEditWnd                                        0x990C3C
#define pinstCFeedbackWnd                                          0x990C40
#define pinstCBugReportWnd                                         0x990C44
#define pinstCVideoModesWnd                                        0x990C48
#define pinstCTextEntryWnd                                         0x990C50
#define pinstCFileSelectionWnd                                     0x990C54
#define pinstCCompassWnd                                           0x990C58
#define pinstCPlayerNotesWnd                                       0x990C5C
#define pinstCGemsGameWnd                                          0x990C60
#define pinstCTimeLeftWnd                                          0x990C64
#define pinstCPetitionQWnd                                         0x990C6C
#define pinstCSoulmarkWnd                                          0x990C70
#define pinstCStoryWnd                                             0x990C74
#define pinstCJournalTextWnd                                       0x990C78
#define pinstCJournalCatWnd                                        0x990C7C
#define pinstCBodyTintWnd                                          0x990C80
#define pinstCServerListWnd                                        0x990C84
#define pinstCAvaZoneWnd                                           0x990C88
#define pinstCBlockedBuffWnd                                       0x990C8C
#define pinstCBlockedPetBuffWnd                                    0x990C90
#define pinstCInvSlotMgr                                           0x990C94
#define pinstCContainerMgr                                         0x990C98
#define pinstCAdventureLeaderboardWnd                              0xAFF360
#define pinstCAdventureRequestWnd                                  0xAFF37C
#define pinstCAltStorageWnd                                        0xAFF3DC
#define pinstCAdventureStatsWnd                                    0xAFF398
#define pinstCBarterMerchantWnd                                    0xAFF5A8
#define pinstCBarterSearchWnd                                      0xAFF5C4
#define pinstCBarterWnd                                            0xAFF5E0
#define pinstCChatManager                                          0xAFF884
#define pinstCDynamicZoneWnd                                       0xAFF97C
#define pinstCEQMainWnd                                            0xAFF9F0
#define pinstCFellowshipWnd                                        0xAFFA54
#define pinstCFindLocationWnd                                      0xAFFA88
#define pinstCGroupSearchWnd                                       0xAFFB38
#define pinstCGroupWnd                                             0xAFFB54
#define pinstCGuildBankWnd                                         0xAFFB70
#define pinstCGuildMgmtWnd                                         0xB01B90
#define pinstCGuildTributeMasterWnd                                0xB01BB0
#define pinstCHotButtonWnd                                         0xB01BCC
#define pinstCHotButtonWnd1                                        0xB01BCC
#define pinstCHotButtonWnd2                                        0xB01BD0
#define pinstCHotButtonWnd3                                        0xB01BD4
#define pinstCHotButtonWnd4                                        0xB01BD8
#define pinstCItemDisplayManager                                   0xB01C84
#define pinstCItemExpTransferWnd                                   0xB01CA4
#define pinstCLeadershipWnd                                        0xB01D40
#define pinstCLFGuildWnd                                           0xB01D5C
#define pinstCMIZoneSelectWnd                                      0xB01ECC
#define pinstCAdventureMerchantWnd                                 0xB01FC4
#define pinstCConfirmationDialog                                   0xB01FE0
#define pinstCPopupWndManager                                      0xB01FE0
#define pinstCProgressionSelectionWnd                              0xB02014
#define pinstCPvPLeaderboardWnd                                    0xB02030
#define pinstCPvPStatsWnd                                          0xB0204C
#define pinstCSystemInfoDialogBox                                  0xB020FC
#define pinstCTargetOfTargetWnd                                    0xB02A04
#define pinstCTaskSelectWnd                                        0xB02A38
#define pinstCTaskTemplateSelectWnd                                0xB02A54
#define pinstCTaskWnd                                              0xB02A70
#define pinstCTipWndOFDAY                                          0xB02AEC
#define pinstCTipWndCONTEXT                                        0xB02AF0
#define pinstCTitleWnd                                             0xB02B0C
#define pinstCTradeskillWnd                                        0xB02B50
#define pinstCTributeBenefitWnd                                    0xB02B9C
#define pinstCTributeMasterWnd                                     0xB02BB8
#define pinstCContextMenuManager                                   0xB10A5C
#define pinstCVoiceMacroWnd                                        0xAD3C34
#define pinstCHtmlWnd                                              0xAD3C70


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4C40E0
#define __ConvertItemTags                                          0x4B6920
#define __ExecuteCmd                                               0x4A57E0
#define __get_melee_range                                          0x4AACC0
#define __GetGaugeValueFromEQ                                      0x63AEA0
#define __GetLabelFromEQ                                           0x63BB20
#define __NewUIINI                                                 0x63AA80
#define __ProcessGameEvents                                        0x4F3B50
#define CrashDetected                                              0x55E160
#define DrawNetStatus                                              0x512440
#define Util__FastTime                                             0x6B0720


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47E4C0
#define AltAdvManager__IsAbilityReady                              0x47E500
#define AltAdvManager__GetAltAbility                               0x47E840

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x576050

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x57F3E0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6DDDB0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5951E0
#define CChatManager__InitContextMenu                              0x595980

// CChatService
#define CChatService__GetNumberOfFriends                           0x6A0900
#define CChatService__GetFriendName                                0x6A0910

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x599B80
#define CChatWindow__WndNotification                               0x59A5D0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6C8830
#define CComboWnd__Draw                                            0x6C89E0
#define CComboWnd__GetCurChoice                                    0x6C87D0
#define CComboWnd__GetListRect                                     0x6C8CB0
#define CComboWnd__GetTextRect                                     0x6C8860
#define CComboWnd__InsertChoice                                    0x6C8D20
#define CComboWnd__SetColors                                       0x6C8760
#define CComboWnd__SetChoice                                       0x6C8790

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5A11B0
#define CContainerWnd__vftable                                     0x7DD928

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46D150
#define CDisplay__GetClickedActor                                  0x46A8A0
#define CDisplay__GetUserDefinedColor                              0x4699C0
#define CDisplay__GetWorldFilePath                                 0x468F10
#define CDisplay__is3dON                                           0x468080
#define CDisplay__ReloadUI                                         0x47B6F0
#define CDisplay__WriteTextHD2                                     0x46D8C0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x570040
#define CEditBaseWnd__SetSel                                       0x6E8DF0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6D1390
#define CEditWnd__GetCharIndexPt                                   0x6D21E0
#define CEditWnd__GetDisplayString                                 0x6D1520
#define CEditWnd__GetHorzOffset                                    0x6D17B0
#define CEditWnd__GetLineForPrintableChar                          0x6D1C90
#define CEditWnd__GetSelStartPt                                    0x6D2430
#define CEditWnd__GetSTMLSafeText                                  0x6D1950
#define CEditWnd__PointFromPrintableChar                           0x6D1DA0
#define CEditWnd__SelectableCharFromPoint                          0x6D1F20
#define CEditWnd__SetEditable                                      0x6D1920

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4D76A0
#define CEverQuest__DropHeldItemOnGround                           0x4DBA80
#define CEverQuest__dsp_chat                                       0x4DCF50
#define CEverQuest__DoTellWindow                                   0x4DBC00
#define CEverQuest__EnterZone                                      0x4F2560
#define CEverQuest__GetBodyTypeDesc                                0x4D4A60
#define CEverQuest__GetClassDesc                                   0x4D41C0
#define CEverQuest__GetClassThreeLetterCode                        0x4D47C0
#define CEverQuest__GetDeityDesc                                   0x4D50D0
#define CEverQuest__GetLangDesc                                    0x4D4DF0
#define CEverQuest__GetRaceDesc                                    0x4D50A0
#define CEverQuest__InterpretCmd                                   0x4DD9B0
#define CEverQuest__LeftClickedOnPlayer                            0x4F0D00
#define CEverQuest__LMouseUp                                       0x4F3330
#define CEverQuest__RightClickedOnPlayer                           0x4F10D0
#define CEverQuest__RMouseUp                                       0x4F2B60
#define CEverQuest__SetGameState                                   0x4D7B20
#define CEverQuest__Emote                                          0x4DD140

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5ADDD0
#define CGaugeWnd__CalcLinesFillRect                               0x5ADE30
#define CGaugeWnd__Draw                                            0x5AE240

// CGuild
#define CGuild__FindMemberByName                                   0x4216B0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5C5F30

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5CF470
#define CInvSlotMgr__MoveItem                                      0x5CF610

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5CDE30
#define CInvSlot__SliderComplete                                   0x5CE340

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5DE440
#define CItemDisplayWnd__SetSpell                                  0x638C00

// CLabel 
#define CLabel__Draw                                               0x5E3D50

// CListWnd 
#define CListWnd__AddColumn                                        0x6C3000
#define CListWnd__AddColumn1                                       0x6C2B20
#define CListWnd__AddLine                                          0x6C2600
#define CListWnd__AddString                                        0x6C2800
#define CListWnd__CalculateFirstVisibleLine                        0x6BF9E0
#define CListWnd__CalculateVSBRange                                0x6C1640
#define CListWnd__ClearAllSel                                      0x6BF110
#define CListWnd__CloseAndUpdateEditWindow                         0x6C0025
#define CListWnd__Compare                                          0x6C03B0
#define CListWnd__Draw                                             0x6C1330
#define CListWnd__DrawColumnSeparators                             0x6C11A0
#define CListWnd__DrawHeader                                       0x6BF2E0
#define CListWnd__DrawItem                                         0x6C0AC0
#define CListWnd__DrawLine                                         0x6C0E40
#define CListWnd__DrawSeparator                                    0x6C1240
#define CListWnd__EnsureVisible                                    0x6BFA30
#define CListWnd__ExtendSel                                        0x6C09E0
#define CListWnd__GetColumnMinWidth                                0x6BEF20
#define CListWnd__GetColumnWidth                                   0x6BEE60
#define CListWnd__GetCurSel                                        0x6BE940
#define CListWnd__GetHeaderRect                                    0x6BEA30
#define CListWnd__GetItemAtPoint                                   0x6BFD30
#define CListWnd__GetItemAtPoint1                                  0x6BFDA0
#define CListWnd__GetItemData                                      0x6BEC10
#define CListWnd__GetItemHeight                                    0x6BF770
#define CListWnd__GetItemIcon                                      0x6BEDA0
#define CListWnd__GetItemRect                                      0x6BFB10
#define CListWnd__GetItemText                                      0x6BEC50
#define CListWnd__GetSelList                                       0x6C2A00
#define CListWnd__GetSeparatorRect                                 0x6C02F0
#define CListWnd__RemoveLine                                       0x6C29B0
#define CListWnd__SetColors                                        0x6BE9A0
#define CListWnd__SetColumnJustification                           0x6BEF80
#define CListWnd__SetColumnWidth                                   0x6BEEE0
#define CListWnd__SetCurSel                                        0x6BE980
#define CListWnd__SetItemColor                                     0x6C2270
#define CListWnd__SetItemData                                      0x6BF1B0
#define CListWnd__SetItemText                                      0x6C21F0
#define CListWnd__ShiftColumnSeparator                             0x6C0950
#define CListWnd__Sort                                             0x6C3030
#define CListWnd__ToggleSel                                        0x6BF080

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5F8F70

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x6040D0
#define CMerchantWnd__RequestBuyItem                               0x605460
#define CMerchantWnd__RequestSellItem                              0x604320
#define CMerchantWnd__SelectBuySellSlot                            0x605190

// CObfuscator
#define CObfuscator__doit                                          0x67BF00

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6D9720
#define CSidlManager__CreateLabel                                  0x631C10

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x6CA450
#define CSidlScreenWnd__CalculateVSBRange                          0x6DF320
#define CSidlScreenWnd__ConvertToRes                               0x6E8CD0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6CA8C0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6CB9B0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6CBA60
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6CB160
#define CSidlScreenWnd__DrawSidlPiece                              0x6CA590
#define CSidlScreenWnd__EnableIniStorage                           0x6CA140
#define CSidlScreenWnd__GetSidlPiece                               0x6CA790
#define CSidlScreenWnd__Init1                                      0x6CB810
#define CSidlScreenWnd__LoadIniInfo                                0x6CA980
#define CSidlScreenWnd__LoadIniListWnd                             0x6CA290
#define CSidlScreenWnd__LoadSidlScreen                             0x6CB3B0
#define CSidlScreenWnd__StoreIniInfo                               0x6C9D50
#define CSidlScreenWnd__WndNotification                            0x6CB590
#define CSidlScreenWnd__GetChildItem                               0x6CA1A0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x534860

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6EA1E0
#define CSliderWnd__SetValue                                       0x6EA2E0
#define CSliderWnd__SetNumTicks                                    0x6EA860

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x637370

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6E6F70
#define CStmlWnd__CalculateVSBRange                                0x6DF320
#define CStmlWnd__CanBreakAtCharacter                              0x6DF460
#define CStmlWnd__FastForwardToEndOfTag                            0x6DFF60
#define CStmlWnd__ForceParseNow                                    0x6E73C0
#define CStmlWnd__GetNextTagPiece                                  0x6DFE80
#define CStmlWnd__GetSTMLText                                      0x599B20
#define CStmlWnd__GetThisChar                                      0x70C600
#define CStmlWnd__GetVisiableText                                  0x6E1170
#define CStmlWnd__InitializeWindowVariables                        0x6E32B0
#define CStmlWnd__MakeStmlColorTag                                 0x6DEA20
#define CStmlWnd__MakeWndNotificationTag                           0x6DEAC0
#define CStmlWnd__SetSTMLText                                      0x6E33D0
#define CStmlWnd__StripFirstSTMLLines                              0x6E6CF0
#define CStmlWnd__UpdateHistoryString                              0x6E19D0

// CTabWnd 
#define CTabWnd__Draw                                              0x6EB680
#define CTabWnd__DrawCurrentPage                                   0x6EB010
#define CTabWnd__DrawTab                                           0x6EADF0
#define CTabWnd__GetCurrentPage                                    0x6EB310
#define CTabWnd__GetPageClientRect                                 0x6EAAC0
#define CTabWnd__GetPageFromTabIndex                               0x6EAD20
#define CTabWnd__GetPageInnerRect                                  0x6EAB20
#define CTabWnd__GetTabInnerRect                                   0x6EACA0
#define CTabWnd__GetTabRect                                        0x6EABB0
#define CTabWnd__IndexInBounds                                     0x6EADBD
#define CTabWnd__InsertPage                                        0x6EB8F0
#define CTabWnd__SetPage                                           0x6EB350
#define CTabWnd__SetPageRect                                       0x6EB5B0
#define CTabWnd__UpdatePage                                        0x6EB870

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x41DBA0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6CBDC0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6EFBF0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6BE6B0

// CXRect 
#define CXRect__CenterPoint                                        0x5756E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x503740
#define CXStr__CXStr1                                              0x60B5C0
#define CXStr__CXStr3                                              0x6B1E20
#define CXStr__dCXStr                                              0x503AB0
#define CXStr__operator_equal1                                     0x6B1FE0
#define CXStr__operator_plus_equal1                                0x6B2EE0

// CXWnd 
#define CXWnd__BringToTop                                          0x6C3740
#define CXWnd__Center                                              0x6C71F0
#define CXWnd__ClrFocus                                            0x6C3430
#define CXWnd__DoAllDrawing                                        0x6C7FD0
#define CXWnd__DrawChildren                                        0x6C8100
#define CXWnd__DrawColoredRect                                     0x6C39B0
#define CXWnd__DrawTooltip                                         0x6C7E00
#define CXWnd__DrawTooltipAtPoint                                  0x6C6FA0
#define CXWnd__GetBorderFrame                                      0x6C3E30
#define CXWnd__GetChildWndAt                                       0x6C6AC0
#define CXWnd__GetClientClipRect                                   0x6C3D70
#define CXWnd__GetScreenClipRect                                   0x6C7410
#define CXWnd__GetScreenRect                                       0x6C4040
#define CXWnd__GetTooltipRect                                      0x6C3BD0
#define CXWnd__GetWindowTextA                                      0x568D80
#define CXWnd__IsActive                                            0x6CCEF0
#define CXWnd__IsDescendantOf                                      0x6C3DE0
#define CXWnd__IsReallyVisible                                     0x6C6AA0
#define CXWnd__IsType                                              0x6ECB60
#define CXWnd__Move                                                0x6C6670
#define CXWnd__Move1                                               0x6C7C60
#define CXWnd__ProcessTransition                                   0x6C3700
#define CXWnd__Refade                                              0x6C34E0
#define CXWnd__Resize                                              0x6C4100
#define CXWnd__Right                                               0x6C7350
#define CXWnd__SetFocus                                            0x6C5850
#define CXWnd__SetKeyTooltip                                       0x6C4310
#define CXWnd__SetMouseOver                                        0x6C42E0
#define CXWnd__StartFade                                           0x6C3780
#define CXWnd__GetChildItem                                        0x6C75D0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6CE300
#define CXWndManager__DrawWindows                                  0x6CDF10
#define CXWndManager__GetKeyboardFlags                             0x6CCB80
#define CXWndManager__HandleKeyboardMsg                            0x6CD0F0
#define CXWndManager__RemoveWnd                                    0x6CD010

// CDBStr
#define CDBStr__GetString                                          0x4669D0

// EQ_Character 
#define EQ_Character__CastRay                                      0x7187E0
#define EQ_Character__CastSpell                                    0x42EFC0
#define EQ_Character__Cur_HP                                       0x43BDC0
#define EQ_Character__GetAACastingTimeModifier                     0x4296C0
#define EQ_Character__GetCharInfo2                                 0x691CC0
#define EQ_Character__GetFocusCastingTimeModifier                  0x425250
#define EQ_Character__GetFocusRangeModifier                        0x425390
#define EQ_Character__Max_Endurance                                0x518530
#define EQ_Character__Max_HP                                       0x436ED0
#define EQ_Character__Max_Mana                                     0x518360
#define EQ_Character__doCombatAbility                              0x517290
#define EQ_Character__UseSkill                                     0x441E30
#define EQ_Character__GetConLevel                                  0x513850

// EQ_Item 
#define EQ_Item__CanDrop                                           0x501410
#define EQ_Item__GetItemLinkHash                                   0x685A10
#define EQ_Item__IsStackable                                       0x67C7E0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x47F710
#define EQ_LoadingS__Array                                         0x854930

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x51B3A0
#define EQ_PC__GetAltAbilityIndex                                  0x68A220
#define EQ_PC__GetCombatAbility                                    0x68A2B0
#define EQ_PC__GetCombatAbilityTimer                               0x68A360
#define EQ_PC__GetItemTimerValue                                   0x5161C0
#define EQ_PC__HasLoreItem                                         0x519870

// EQItemList 
#define EQItemList__dEQItemList                                    0x4A93A0
#define EQItemList__EQItemList                                     0x4A92F0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x466360

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x51FBC0
#define EQPlayer__dEQPlayer                                        0x523B90
#define EQPlayer__DoAttack                                         0x530B40
#define EQPlayer__EQPlayer                                         0x527800
#define EQPlayer__SetNameSpriteState                               0x521B60
#define EQPlayer__SetNameSpriteTint                                0x51FC30
#define EQPlayer__IsBodyType_j                                     0x7181B0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5288C0
#define EQPlayerManager__GetSpawnByName                            0x528B20

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x5030B0
#define KeypressHandler__AttachKeyToEqCommand                      0x5030F0
#define KeypressHandler__ClearCommandStateArray                    0x502EC0
#define KeypressHandler__HandleKeyDown                             0x501A70
#define KeypressHandler__HandleKeyUp                               0x501D80
#define KeypressHandler__SaveKeymapping                            0x502F90

// MapViewMap 
#define MapViewMap__Clear                                          0x5F4640
#define MapViewMap__SaveEx                                         0x5F5010

#define OtherCharData__GetAltCurrency                              0x6A9040

// StringTable 
#define StringTable__getString                                     0x67C180
