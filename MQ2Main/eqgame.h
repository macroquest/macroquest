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
#define __ExpectedVersionDate                                     "Jul 13 2010"
#define __ExpectedVersionTime                                     "15:23:28"
#define __ActualVersionDate                                        0x8286A8
#define __ActualVersionTime                                        0x8286B4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x512770
#define __MemChecker1                                              0x6EE8A0
#define __MemChecker2                                              0x577010
#define __MemChecker3                                              0x576F60
#define __MemChecker4                                              0x6A21E0
#define __EncryptPad0                                              0x8BA1C0
#define __EncryptPad1                                              0x8C52E8
#define __EncryptPad2                                              0x8BCE00
#define __EncryptPad3                                              0x8BCA00
#define __EncryptPad4                                              0x8C4930
#define __AC1                                                      0x6687D0
#define __AC2                                                      0x4DA7D5
#define __AC3                                                      0x4EE838
#define __AC4                                                      0x4F2708
#define __AC5                                                      0x4FCE78
#define __AC6                                                      0x50030B
#define __AC7                                                      0x4F93A4
#define __AC1_Data                                                 0x810000

// Direct Input
#define DI8__Main                                                  0xB1FD3C
#define DI8__Keyboard                                              0xB1FD40
#define DI8__Mouse                                                 0xB1FD44
#define __AltTimerReady                                            0xAA6A36
#define __Attack                                                   0xB0A0D6
#define __Autofire                                                 0xB0A0D7
#define __BindList                                                 0x8B4920
#define __Clicks                                                   0xAA5730
#define __CommandList                                              0x8B5270
#define __CurrentMapLabel                                          0xB4AFF0
#define __CurrentSocial                                            0x8B0870
#define __DoAbilityAvailable                                       0xAA69D0
#define __DoAbilityList                                            0xADBFF4
#define __do_loot                                                  0x4B2860
#define __DrawHandler                                              0xB5A714
#define __GroupCount                                               0xA9F52A
#define __Guilds                                                   0xAA4B10
#define __gWorld                                                   0xAA13E8
#define __HotkeyPage                                               0xB033E0
#define __HWnd                                                     0xB1FA78
#define __InChatMode                                               0xAA5668
#define __LastTell                                                 0xAA734C
#define __LMouseHeldTime                                           0xAA575C
#define __Mouse                                                    0xB1FD48
#define __MouseLook                                                0xAA56FE
#define __MouseEventTime                                           0xB0A218
#define __NetStatusToggle                                          0xAA5701
#define __PCNames                                                  0xAA6D90
#define __RangeAttackReady                                         0xAA6A34
#define __RMouseHeldTime                                           0xAA5758
#define __RunWalkState                                             0xAA566C
#define __ScreenMode                                               0x9EEDB8
#define __ScreenX                                                  0xAA5620
#define __ScreenY                                                  0xAA5624
#define __ScreenXMax                                               0xAA5628
#define __ScreenYMax                                               0xAA562C
#define __ServerHost                                               0xA9F46C
#define __ServerName                                               0xADBFB4
#define __ShiftKeyDown                                             0xAA5CE8
#define __ShowNames                                                0xAA6C64
#define __Socials                                                  0xADC0B4


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xAA14A8
#define instEQZoneInfo                                             0xAA58A8
#define instKeypressHandler                                        0xB0A1FC
#define pinstActiveBanker                                          0xAA147C
#define pinstActiveCorpse                                          0xAA1480
#define pinstActiveGMaster                                         0xAA1484
#define pinstActiveMerchant                                        0xAA1478
#define pinstAltAdvManager                                         0x9EFC38
#define pinstAuraMgr                                               0x8D867C
#define pinstBandageTarget                                         0xAA1464
#define pinstCamActor                                              0x9EF728
#define pinstCDBStr                                                0x9EEDA8
#define pinstCDisplay                                              0xAA148C
#define pinstCEverQuest                                            0xB1FEC0
#define pinstCharData                                              0xAA1448
#define pinstCharSpawn                                             0xAA1470
#define pinstControlledMissile                                     0xAA1444
#define pinstControlledPlayer                                      0xAA1470
#define pinstCSidlManager                                          0xB59E8C
#define pinstCXWndManager                                          0xB59E84
#define instDynamicZone                                            0xAA54F0
#define pinstDZMember                                              0xAA5600
#define pinstDZTimerInfo                                           0xAA5604
#define pinstEQItemList                                            0xA9E750
#define instEQMisc                                                 0x9EED60
#define pinstEQSoundManager                                        0x9EFC5C
#define instExpeditionLeader                                       0xAA553A
#define instExpeditionName                                         0xAA557A
#define pinstGroup                                                 0xA9F526
#define pinstImeManager                                            0xB59E90
#define pinstLocalPlayer                                           0xAA145C
#define pinstMercenaryData                                         0xB0A570
#define pinstModelPlayer                                           0xAA1488
#define pinstPCData                                                0xAA1448
#define pinstSkillMgr                                              0xB1CB2C
#define pinstSpawnManager                                          0xB1C988
#define pinstSpellManager                                          0xB1CB38
#define pinstSpellSets                                             0xB033E4
#define pinstStringTable                                           0xAA1404
#define pinstSwitchManager                                         0xA9F16C
#define pinstTarget                                                0xAA1474
#define pinstTargetObject                                          0xAA144C
#define pinstTargetSwitch                                          0xAA1450
#define pinstTaskMember                                            0x9EED40
#define pinstTrackTarget                                           0xAA1468
#define pinstTradeTarget                                           0xAA1458
#define instTributeActive                                          0x9EED85
#define pinstViewActor                                             0x9EF724
#define pinstWorldData                                             0xAA142C


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x8D5F44
#define pinstCAudioTriggersWindow                                  0x8D5F10
#define pinstCCharacterSelect                                      0x9EF620
#define pinstCFacePick                                             0x9EF5D0
#define pinstCNoteWnd                                              0x9EF5D8
#define pinstCBookWnd                                              0x9EF5DC
#define pinstCPetInfoWnd                                           0x9EF5E0
#define pinstCTrainWnd                                             0x9EF5E4
#define pinstCSkillsWnd                                            0x9EF5E8
#define pinstCSkillsSelectWnd                                      0x9EF5EC
#define pinstCCombatSkillSelectWnd                                 0x9EF5F0
#define pinstCFriendsWnd                                           0x9EF5F4
#define pinstCAuraWnd                                              0x9EF5F8
#define pinstCRespawnWnd                                           0x9EF5FC
#define pinstCBandolierWnd                                         0x9EF600
#define pinstCPotionBeltWnd                                        0x9EF604
#define pinstCAAWnd                                                0x9EF608
#define pinstCGroupSearchFiltersWnd                                0x9EF60C
#define pinstCLoadskinWnd                                          0x9EF610
#define pinstCAlarmWnd                                             0x9EF614
#define pinstCMusicPlayerWnd                                       0x9EF618
#define pinstCMailWnd                                              0x9EF624
#define pinstCMailCompositionWnd                                   0x9EF628
#define pinstCMailAddressBookWnd                                   0x9EF62C
#define pinstCRaidWnd                                              0x9EF634
#define pinstCRaidOptionsWnd                                       0x9EF638
#define pinstCBreathWnd                                            0x9EF63C
#define pinstCMapViewWnd                                           0x9EF640
#define pinstCMapToolbarWnd                                        0x9EF644
#define pinstCEditLabelWnd                                         0x9EF648
#define pinstCTargetWnd                                            0x9EF64C
#define pinstCColorPickerWnd                                       0x9EF650
#define pinstCPlayerWnd                                            0x9EF654
#define pinstCOptionsWnd                                           0x9EF658
#define pinstCBuffWindowNORMAL                                     0x9EF65C
#define pinstCBuffWindowSHORT                                      0x9EF660
#define pinstCharacterCreation                                     0x9EF664
#define pinstCCursorAttachment                                     0x9EF668
#define pinstCCastingWnd                                           0x9EF66C
#define pinstCCastSpellWnd                                         0x9EF670
#define pinstCSpellBookWnd                                         0x9EF674
#define pinstCInventoryWnd                                         0x9EF678
#define pinstCBankWnd                                              0x9EF67C
#define pinstCQuantityWnd                                          0x9EF680
#define pinstCLootWnd                                              0x9EF684
#define pinstCActionsWnd                                           0x9EF688
#define pinstCCombatAbilityWnd                                     0x9EF68C
#define pinstCMerchantWnd                                          0x9EF690
#define pinstCTradeWnd                                             0x9EF694
#define pinstCSelectorWnd                                          0x9EF698
#define pinstCBazaarWnd                                            0x9EF69C
#define pinstCBazaarSearchWnd                                      0x9EF6A0
#define pinstCGiveWnd                                              0x9EF6A4
#define pinstCTrackingWnd                                          0x9EF6A8
#define pinstCInspectWnd                                           0x9EF6AC
#define pinstCSocialEditWnd                                        0x9EF6B0
#define pinstCFeedbackWnd                                          0x9EF6B4
#define pinstCBugReportWnd                                         0x9EF6B8
#define pinstCVideoModesWnd                                        0x9EF6BC
#define pinstCTextEntryWnd                                         0x9EF6C4
#define pinstCFileSelectionWnd                                     0x9EF6C8
#define pinstCCompassWnd                                           0x9EF6CC
#define pinstCPlayerNotesWnd                                       0x9EF6D0
#define pinstCGemsGameWnd                                          0x9EF6D4
#define pinstCTimeLeftWnd                                          0x9EF6D8
#define pinstCPetitionQWnd                                         0x9EF6EC
#define pinstCSoulmarkWnd                                          0x9EF6F0
#define pinstCStoryWnd                                             0x9EF6F4
#define pinstCJournalTextWnd                                       0x9EF6F8
#define pinstCJournalCatWnd                                        0x9EF6FC
#define pinstCBodyTintWnd                                          0x9EF700
#define pinstCServerListWnd                                        0x9EF704
#define pinstCAvaZoneWnd                                           0x9EF70C
#define pinstCBlockedBuffWnd                                       0x9EF710
#define pinstCBlockedPetBuffWnd                                    0x9EF714
#define pinstCInvSlotMgr                                           0x9EF71C
#define pinstCContainerMgr                                         0x9EF720
#define pinstCAdventureLeaderboardWnd                              0xB48508
#define pinstCAdventureRequestWnd                                  0xB48524
#define pinstCAltStorageWnd                                        0xB48584
#define pinstCAdventureStatsWnd                                    0xB48540
#define pinstCBarterMerchantWnd                                    0xB48750
#define pinstCBarterSearchWnd                                      0xB4876C
#define pinstCBarterWnd                                            0xB48788
#define pinstCChatManager                                          0xB48A2C
#define pinstCDynamicZoneWnd                                       0xB48B24
#define pinstCEQMainWnd                                            0xB48B98
#define pinstCFellowshipWnd                                        0xB48BFC
#define pinstCFindLocationWnd                                      0xB48C30
#define pinstCGroupSearchWnd                                       0xB48CE0
#define pinstCGroupWnd                                             0xB48CFC
#define pinstCGuildBankWnd                                         0xB48D18
#define pinstCGuildMgmtWnd                                         0xB4AD50
#define pinstCGuildTributeMasterWnd                                0xB4AD70
#define pinstCHotButtonWnd                                         0xB4ADA4
#define pinstCHotButtonWnd1                                        0xB4ADA4
#define pinstCHotButtonWnd2                                        0xB4ADA8
#define pinstCHotButtonWnd3                                        0xB4ADAC
#define pinstCHotButtonWnd4                                        0xB4ADB0
#define pinstCItemDisplayManager                                   0xB4AE5C
#define pinstCItemExpTransferWnd                                   0xB4AE7C
#define pinstCLeadershipWnd                                        0xB4AF18
#define pinstCLFGuildWnd                                           0xB4AF34
#define pinstCMIZoneSelectWnd                                      0xB4B0A4
#define pinstCAdventureMerchantWnd                                 0xB4B1B4
#define pinstCConfirmationDialog                                   0xB4B1D0
#define pinstCPopupWndManager                                      0xB4B1D0
#define pinstCProgressionSelectionWnd                              0xB4B204
#define pinstCPvPLeaderboardWnd                                    0xB4B220
#define pinstCPvPStatsWnd                                          0xB4B23C
#define pinstCSystemInfoDialogBox                                  0xB4B308
#define pinstCTargetOfTargetWnd                                    0xB4BE08
#define pinstCTaskSelectWnd                                        0xB4BE3C
#define pinstCTaskTemplateSelectWnd                                0xB4BE58
#define pinstCTaskWnd                                              0xB4BE74
#define pinstCTipWndOFDAY                                          0xB4BEF0
#define pinstCTipWndCONTEXT                                        0xB4BEF4
#define pinstCTitleWnd                                             0xB4BF10
#define pinstCTradeskillWnd                                        0xB4BF54
#define pinstCTributeBenefitWnd                                    0xB4BFA0
#define pinstCTributeMasterWnd                                     0xB4BFBC
#define pinstCContextMenuManager                                   0xB59EE8
#define pinstCVoiceMacroWnd                                        0xB1CD2C
#define pinstCHtmlWnd                                              0xB1CD78


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4C6430
#define __ConvertItemTags                                          0x4B7EE0
#define __ExecuteCmd                                               0x4A41E0
#define __get_melee_range                                          0x4A9EA0
#define __GetGaugeValueFromEQ                                      0x667690
#define __GetLabelFromEQ                                           0x668770
#define __GetXTargetType                                           0x75D490
#define __LoadFrontEnd                                             0x575EE0
#define __NewUIINI                                                 0x667220
#define __ProcessGameEvents                                        0x4F9790
#define CrashDetected                                              0x575CE0
#define DrawNetStatus                                              0x51D290
#define Util__FastTime                                             0x6EEFB0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47B940
#define AltAdvManager__IsAbilityReady                              0x47B980
#define AltAdvManager__GetAltAbility                               0x47BB60

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x593BC0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x59D0A0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x71D410

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5B3350
#define CChatManager__InitContextMenu                              0x5B3B20

// CChatService
#define CChatService__GetNumberOfFriends                           0x6D9530
#define CChatService__GetFriendName                                0x6D9540

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5B7D00
#define CChatWindow__Clear                                         0x5B8660
#define CChatWindow__WndNotification                               0x5B8850

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x7074C0
#define CComboWnd__Draw                                            0x707680
#define CComboWnd__GetCurChoice                                    0x707460
#define CComboWnd__GetListRect                                     0x707970
#define CComboWnd__GetTextRect                                     0x7074F0
#define CComboWnd__InsertChoice                                    0x7079E0
#define CComboWnd__SetColors                                       0x7073F0
#define CComboWnd__SetChoice                                       0x707420

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5BFBF0
#define CContainerWnd__vftable                                     0x830300

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46E9F0
#define CDisplay__GetClickedActor                                  0x467DA0
#define CDisplay__GetUserDefinedColor                              0x466EC0
#define CDisplay__GetWorldFilePath                                 0x466350
#define CDisplay__is3dON                                           0x465480
#define CDisplay__ReloadUI                                         0x478B40
#define CDisplay__WriteTextHD2                                     0x46AA90

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x58DB10
#define CEditBaseWnd__SetSel                                       0x729DC0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x710550
#define CEditWnd__GetCharIndexPt                                   0x711510
#define CEditWnd__GetDisplayString                                 0x7106E0
#define CEditWnd__GetHorzOffset                                    0x710970
#define CEditWnd__GetLineForPrintableChar                          0x710FC0
#define CEditWnd__GetSelStartPt                                    0x711760
#define CEditWnd__GetSTMLSafeText                                  0x710B10
#define CEditWnd__PointFromPrintableChar                           0x7110D0
#define CEditWnd__SelectableCharFromPoint                          0x711250
#define CEditWnd__SetEditable                                      0x710AE0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4DAEB0
#define CEverQuest__DropHeldItemOnGround                           0x4DF460
#define CEverQuest__dsp_chat                                       0x4E0C00
#define CEverQuest__DoTellWindow                                   0x4DF5E0
#define CEverQuest__EnterZone                                      0x4F26A0
#define CEverQuest__GetBodyTypeDesc                                0x4D80B0
#define CEverQuest__GetClassDesc                                   0x4D78F0
#define CEverQuest__GetClassThreeLetterCode                        0x4D7EF0
#define CEverQuest__GetDeityDesc                                   0x4D8720
#define CEverQuest__GetLangDesc                                    0x4D8440
#define CEverQuest__GetRaceDesc                                    0x4D86F0
#define CEverQuest__InterpretCmd                                   0x4E1760
#define CEverQuest__LeftClickedOnPlayer                            0x4F41D0
#define CEverQuest__LMouseUp                                       0x4F7AE0
#define CEverQuest__RightClickedOnPlayer                           0x4F8380
#define CEverQuest__RMouseUp                                       0x4F9360
#define CEverQuest__SetGameState                                   0x4DB340
#define CEverQuest__Emote                                          0x4E0E20

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5CC3C0
#define CGaugeWnd__CalcLinesFillRect                               0x5CC420
#define CGaugeWnd__Draw                                            0x5CC870

// CGuild
#define CGuild__FindMemberByName                                   0x41B770

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5E53A0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5EEB40
#define CInvSlotMgr__MoveItem                                      0x5EECE0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5EE390
#define CInvSlot__SliderComplete                                   0x5ED4A0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5EFC90

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x665000
#define CItemDisplayWnd__UpdateStrings                             0x5F0940

// CLabel 
#define CLabel__Draw                                               0x603160

// CListWnd 
#define CListWnd__AddColumn                                        0x700AF0
#define CListWnd__AddColumn1                                       0x700580
#define CListWnd__AddLine                                          0x7000F0
#define CListWnd__AddString                                        0x700290
#define CListWnd__CalculateFirstVisibleLine                        0x6FCDD0
#define CListWnd__CalculateVSBRange                                0x6FEFD0
#define CListWnd__ClearAllSel                                      0x6FC320
#define CListWnd__CloseAndUpdateEditWindow                         0x6FD440
#define CListWnd__Compare                                          0x6FD7E0
#define CListWnd__Draw                                             0x6FEC50
#define CListWnd__DrawColumnSeparators                             0x6FEAC0
#define CListWnd__DrawHeader                                       0x6FC5B0
#define CListWnd__DrawItem                                         0x6FE0F0
#define CListWnd__DrawLine                                         0x6FE730
#define CListWnd__DrawSeparator                                    0x6FEB60
#define CListWnd__EnsureVisible                                    0x6FCE60
#define CListWnd__ExtendSel                                        0x6FE010
#define CListWnd__GetColumnMinWidth                                0x6FC0B0
#define CListWnd__GetColumnWidth                                   0x6FBFF0
#define CListWnd__GetCurSel                                        0x6FBA10
#define CListWnd__GetHeaderRect                                    0x6FBB70
#define CListWnd__GetItemAtPoint                                   0x6FD150
#define CListWnd__GetItemAtPoint1                                  0x6FD1C0
#define CListWnd__GetItemData                                      0x6FBDA0
#define CListWnd__GetItemHeight                                    0x6FCA40
#define CListWnd__GetItemIcon                                      0x6FBF30
#define CListWnd__GetItemRect                                      0x6FCF30
#define CListWnd__GetItemText                                      0x6FBDE0
#define CListWnd__GetSelList                                       0x700460
#define CListWnd__GetSeparatorRect                                 0x6FD720
#define CListWnd__RemoveLine                                       0x700AA0
#define CListWnd__SetColors                                        0x6FBAE0
#define CListWnd__SetColumnJustification                           0x6FC190
#define CListWnd__SetColumnWidth                                   0x6FC070
#define CListWnd__SetCurSel                                        0x6FBA50
#define CListWnd__SetItemColor                                     0x6FFC80
#define CListWnd__SetItemData                                      0x6FC3C0
#define CListWnd__SetItemText                                      0x6FFC00
#define CListWnd__ShiftColumnSeparator                             0x6FDF20
#define CListWnd__Sort                                             0x700B30
#define CListWnd__ToggleSel                                        0x6FC290

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x618A90

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x629A30
#define CMerchantWnd__RequestBuyItem                               0x62BA60
#define CMerchantWnd__RequestSellItem                              0x62BE80
#define CMerchantWnd__SelectBuySellSlot                            0x62AE80

// CObfuscator
#define CObfuscator__doit                                          0x6B2C50

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x718CD0
#define CSidlManager__CreateLabel                                  0x65DFB0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x709120
#define CSidlScreenWnd__CalculateVSBRange                          0x58FBC0
#define CSidlScreenWnd__ConvertToRes                               0x729CA0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7095E0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x70A6D0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x70A780
#define CSidlScreenWnd__dCSidlScreenWnd                            0x709E90
#define CSidlScreenWnd__DrawSidlPiece                              0x7092A0
#define CSidlScreenWnd__EnableIniStorage                           0x708E10
#define CSidlScreenWnd__GetSidlPiece                               0x7094B0
#define CSidlScreenWnd__Init1                                      0x70A530
#define CSidlScreenWnd__LoadIniInfo                                0x709690
#define CSidlScreenWnd__LoadIniListWnd                             0x708F60
#define CSidlScreenWnd__LoadSidlScreen                             0x70A0E0
#define CSidlScreenWnd__StoreIniInfo                               0x708A10
#define CSidlScreenWnd__StoreIniVis                                0x708DA0
#define CSidlScreenWnd__WndNotification                            0x70A2B0
#define CSidlScreenWnd__GetChildItem                               0x708E70

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x543830

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x72B1F0
#define CSliderWnd__SetValue                                       0x72B2F0
#define CSliderWnd__SetNumTicks                                    0x72B8A0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x662D40

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x727EE0
#define CStmlWnd__CalculateHSBRange                                0x71F6B0
#define CStmlWnd__CalculateVSBRange                                0x71F620
#define CStmlWnd__CanBreakAtCharacter                              0x71F810
#define CStmlWnd__FastForwardToEndOfTag                            0x7204F0
#define CStmlWnd__ForceParseNow                                    0x7283E0
#define CStmlWnd__GetNextTagPiece                                  0x720410
#define CStmlWnd__GetSTMLText                                      0x5B7CA0
#define CStmlWnd__GetThisChar                                      0x74F120
#define CStmlWnd__GetVisiableText                                  0x721910
#define CStmlWnd__InitializeWindowVariables                        0x723E70
#define CStmlWnd__MakeStmlColorTag                                 0x71E520
#define CStmlWnd__MakeWndNotificationTag                           0x71E5C0
#define CStmlWnd__SetSTMLText                                      0x723F90
#define CStmlWnd__StripFirstSTMLLines                              0x727B90
#define CStmlWnd__UpdateHistoryString                              0x7221A0

// CTabWnd 
#define CTabWnd__Draw                                              0x72C630
#define CTabWnd__DrawCurrentPage                                   0x72C050
#define CTabWnd__DrawTab                                           0x72BE30
#define CTabWnd__GetCurrentPage                                    0x72C2D0
#define CTabWnd__GetPageClientRect                                 0x72BB00
#define CTabWnd__GetPageFromTabIndex                               0x72BD60
#define CTabWnd__GetPageInnerRect                                  0x72BB60
#define CTabWnd__GetTabInnerRect                                   0x72BCE0
#define CTabWnd__GetTabRect                                        0x72BBF0
#define CTabWnd__InsertPage                                        0x72C8C0
#define CTabWnd__SetPage                                           0x72C310
#define CTabWnd__SetPageRect                                       0x72C560
#define CTabWnd__UpdatePage                                        0x72C840

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417D50

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x70AB00

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x72D4D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6FAA80

// CXRect 
#define CXRect__CenterPoint                                        0x593250

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x50C190
#define CXStr__CXStr1                                              0x6F5A60
#define CXStr__CXStr3                                              0x6EC2B0
#define CXStr__dCXStr                                              0x4489F0
#define CXStr__operator_equal1                                     0x6EC470
#define CXStr__operator_plus_equal1                                0x6ED4B0

// CXWnd 
#define CXWnd__BringToTop                                          0x701110
#define CXWnd__Center                                              0x705EE0
#define CXWnd__ClrFocus                                            0x700F30
#define CXWnd__DoAllDrawing                                        0x706860
#define CXWnd__DrawChildren                                        0x7069B0
#define CXWnd__DrawColoredRect                                     0x7013F0
#define CXWnd__DrawTooltip                                         0x705E10
#define CXWnd__DrawTooltipAtPoint                                  0x705200
#define CXWnd__GetBorderFrame                                      0x7018A0
#define CXWnd__GetChildWndAt                                       0x704690
#define CXWnd__GetClientClipRect                                   0x7016B0
#define CXWnd__GetScreenClipRect                                   0x705660
#define CXWnd__GetScreenRect                                       0x7019C0
#define CXWnd__GetTooltipRect                                      0x701500
#define CXWnd__GetWindowTextA                                      0x5811D0
#define CXWnd__IsActive                                            0x70BC30
#define CXWnd__IsDescendantOf                                      0x701790
#define CXWnd__IsReallyVisible                                     0x704670
#define CXWnd__IsType                                              0x730340
#define CXWnd__Move                                                0x703DC0
#define CXWnd__Move1                                               0x705BB0
#define CXWnd__ProcessTransition                                   0x7010C0
#define CXWnd__Refade                                              0x701030
#define CXWnd__Resize                                              0x701A90
#define CXWnd__Right                                               0x7055A0
#define CXWnd__SetFocus                                            0x7031D0
#define CXWnd__SetKeyTooltip                                       0x701C80
#define CXWnd__SetMouseOver                                        0x705900
#define CXWnd__StartFade                                           0x701140
#define CXWnd__GetChildItem                                        0x705870

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x70D2C0
#define CXWndManager__DrawWindows                                  0x70CF40
#define CXWndManager__GetKeyboardFlags                             0x70B890
#define CXWndManager__HandleKeyboardMsg                            0x70BFB0
#define CXWndManager__RemoveWnd                                    0x70BE00

// CDBStr
#define CDBStr__GetString                                          0x463DE0

// EQ_Character 
#define EQ_Character__CastRay                                      0x75B2C0
#define EQ_Character__CastSpell                                    0x42E310
#define EQ_Character__Cur_HP                                       0x4374A0
#define EQ_Character__GetAACastingTimeModifier                     0x4242B0
#define EQ_Character__GetCharInfo2                                 0x6C9D90
#define EQ_Character__GetFocusCastingTimeModifier                  0x41FB60
#define EQ_Character__GetFocusRangeModifier                        0x41FCA0
#define EQ_Character__Max_Endurance                                0x5244E0
#define EQ_Character__Max_HP                                       0x432470
#define EQ_Character__Max_Mana                                     0x524310
#define EQ_Character__doCombatAbility                              0x523220
#define EQ_Character__UseSkill                                     0x441EA0
#define EQ_Character__GetConLevel                                  0x51F400

// EQ_Item 
#define EQ_Item__CanDrop                                           0x509F00
#define EQ_Item__GetItemLinkHash                                   0x6BC700
#define EQ_Item__IsStackable                                       0x6B3530

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x47CA30
#define EQ_LoadingS__Array                                         0x8B2D88

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x527380
#define EQ_PC__GetAltAbilityIndex                                  0x6C1A00
#define EQ_PC__GetCombatAbility                                    0x6C1A90
#define EQ_PC__GetCombatAbilityTimer                               0x6C1B40
#define EQ_PC__GetItemTimerValue                                   0x522150
#define EQ_PC__HasLoreItem                                         0x525830

// EQItemList 
#define EQItemList__EQItemList                                     0x4A8040
#define EQItemList__add_item                                       0x4A80F0
#define EQItemList__delete_item                                    0x4A8350
#define EQItemList__FreeItemList                                   0x4A8110

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x463790

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x52BF70
#define EQPlayer__dEQPlayer                                        0x530850
#define EQPlayer__DoAttack                                         0x53FA00
#define EQPlayer__EQPlayer                                         0x535750
#define EQPlayer__SetNameSpriteState                               0x52E370
#define EQPlayer__SetNameSpriteTint                                0x52BFE0
#define EQPlayer__IsBodyType_j                                     0x75ABD0
#define EQPlayer__IsTargetable                                     0x75AD60

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5369E0
#define EQPlayerManager__GetSpawnByName                            0x536CC0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x50BBB0
#define KeypressHandler__AttachKeyToEqCommand                      0x50BBF0
#define KeypressHandler__ClearCommandStateArray                    0x50B9C0
#define KeypressHandler__HandleKeyDown                             0x50A540
#define KeypressHandler__HandleKeyUp                               0x50A850
#define KeypressHandler__SaveKeymapping                            0x50BA90

// MapViewMap 
#define MapViewMap__Clear                                          0x614130
#define MapViewMap__SaveEx                                         0x614B00

#define PlayerPointManager__GetAltCurrency                         0x6E21E0

// StringTable 
#define StringTable__getString                                     0x6B2ED0