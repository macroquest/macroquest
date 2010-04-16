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
#define __ExpectedVersionDate                                     "Apr 14 2010"
#define __ExpectedVersionTime                                     "05:57:08"
#define __ActualVersionDate                                        0x81F408
#define __ActualVersionTime                                        0x81F414

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x511B60
#define __MemChecker1                                              0x6E7330
#define __MemChecker2                                              0x5736B0
#define __MemChecker3                                              0x573600
#define __MemChecker4                                              0x69B410
#define __EncryptPad0                                              0x8B0190
#define __EncryptPad1                                              0x8BB290
#define __EncryptPad2                                              0x8B2DC8
#define __EncryptPad3                                              0x8B29C8
#define __EncryptPad4                                              0x8BA8D8
#define __AC1                                                      0x661AA0
#define __AC2                                                      0x4D9CC5
#define __AC3                                                      0x4EDD48
#define __AC4                                                      0x4F1C18
#define __AC5                                                      0x4FC388
#define __AC6                                                      0x4FF80B
#define __AC7                                                      0x4F88B4
#define __AC1_Data                                                 0x807CD0

// Direct Input
#define DI8__Main                                                  0xB15CC4
#define DI8__Keyboard                                              0xB15CC8
#define DI8__Mouse                                                 0xB15CCC
#define __AltTimerReady                                            0xA9C9D6
#define __Attack                                                   0xB00076
#define __Autofire                                                 0xB00077
#define __BindList                                                 0x8AA910
#define __Clicks                                                   0xA9B6D0
#define __CommandList                                              0x8AB260
#define __CurrentMapLabel                                          0xB40F60
#define __CurrentSocial                                            0x8A683C
#define __DoAbilityAvailable                                       0xA9C970
#define __DoAbilityList                                            0xAD1F94
#define __do_loot                                                  0x4B2790
#define __DrawHandler                                              0xB50684
#define __GroupCount                                               0xA954CA
#define __Guilds                                                   0xA9AAB0
#define __gWorld                                                   0xA97388
#define __HotkeyPage                                               0xAF9380
#define __HWnd                                                     0xB15A00
#define __InChatMode                                               0xA9B608
#define __LastTell                                                 0xA9D2EC
#define __LMouseHeldTime                                           0xA9B6FC
#define __Mouse                                                    0xB15CD0
#define __MouseLook                                                0xA9B69E
#define __MouseEventTime                                           0xB001B8
#define __NetStatusToggle                                          0xA9B6A1
#define __PCNames                                                  0xA9CD30
#define __RangeAttackReady                                         0xA9C9D4
#define __RMouseHeldTime                                           0xA9B6F8
#define __RunWalkState                                             0xA9B60C
#define __ScreenMode                                               0x9E4D58
#define __ScreenX                                                  0xA9B5C0
#define __ScreenY                                                  0xA9B5C4
#define __ScreenXMax                                               0xA9B5C8
#define __ScreenYMax                                               0xA9B5CC
#define __ServerHost                                               0xA9540C
#define __ServerName                                               0xAD1F54
#define __ShiftKeyDown                                             0xA9BC88
#define __ShowNames                                                0xA9CC04
#define __Socials                                                  0xAD2054


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA97448
#define instEQZoneInfo                                             0xA9B848
#define instKeypressHandler                                        0xB0019C
#define pinstActiveBanker                                          0xA9741C
#define pinstActiveCorpse                                          0xA97420
#define pinstActiveGMaster                                         0xA97424
#define pinstActiveMerchant                                        0xA97418
#define pinstAltAdvManager                                         0x9E5BD8
#define pinstAuraMgr                                               0x8CE61C
#define pinstBandageTarget                                         0xA97404
#define pinstCamActor                                              0x9E56C4
#define pinstCDBStr                                                0x9E4D48
#define pinstCDisplay                                              0xA9742C
#define pinstCEverQuest                                            0xB15E48
#define pinstCharData                                              0xA973E8
#define pinstCharSpawn                                             0xA97410
#define pinstControlledMissile                                     0xA973E4
#define pinstControlledPlayer                                      0xA97410
#define pinstCSidlManager                                          0xB4FDF8
#define pinstCXWndManager                                          0xB4FDF0
#define instDynamicZone                                            0xA9B490
#define pinstDZMember                                              0xA9B5A0
#define pinstDZTimerInfo                                           0xA9B5A4
#define pinstEQItemList                                            0xA946F0
#define instEQMisc                                                 0x9E4D00
#define pinstEQSoundManager                                        0x9E5BFC
#define instExpeditionLeader                                       0xA9B4DA
#define instExpeditionName                                         0xA9B51A
#define pinstGroup                                                 0xA954C6
#define pinstImeManager                                            0xB4FDFC
#define pinstLocalPlayer                                           0xA973FC
#define pinstMercenaryData                                         0xB00510
#define pinstModelPlayer                                           0xA97428
#define pinstPCData                                                0xA973E8
#define pinstSkillMgr                                              0xB12AB4
#define pinstSpawnManager                                          0xB12910
#define pinstSpellManager                                          0xB12AC0
#define pinstSpellSets                                             0xAF9384
#define pinstStringTable                                           0xA973A4
#define pinstSwitchManager                                         0xA9510C
#define pinstTarget                                                0xA97414
#define pinstTargetObject                                          0xA973EC
#define pinstTargetSwitch                                          0xA973F0
#define pinstTaskMember                                            0x9E4CE0
#define pinstTrackTarget                                           0xA97408
#define pinstTradeTarget                                           0xA973F8
#define instTributeActive                                          0x9E4D25
#define pinstViewActor                                             0x9E56C0
#define pinstWorldData                                             0xA973CC


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x8CBEE4
#define pinstCAudioTriggersWindow                                  0x8CBEB0
#define pinstCCharacterSelect                                      0x9E55C0
#define pinstCFacePick                                             0x9E5570
#define pinstCNoteWnd                                              0x9E5578
#define pinstCBookWnd                                              0x9E557C
#define pinstCPetInfoWnd                                           0x9E5580
#define pinstCTrainWnd                                             0x9E5584
#define pinstCSkillsWnd                                            0x9E5588
#define pinstCSkillsSelectWnd                                      0x9E558C
#define pinstCCombatSkillSelectWnd                                 0x9E5590
#define pinstCFriendsWnd                                           0x9E5594
#define pinstCAuraWnd                                              0x9E5598
#define pinstCRespawnWnd                                           0x9E559C
#define pinstCBandolierWnd                                         0x9E55A0
#define pinstCPotionBeltWnd                                        0x9E55A4
#define pinstCAAWnd                                                0x9E55A8
#define pinstCGroupSearchFiltersWnd                                0x9E55AC
#define pinstCLoadskinWnd                                          0x9E55B0
#define pinstCAlarmWnd                                             0x9E55B4
#define pinstCMusicPlayerWnd                                       0x9E55B8
#define pinstCMailWnd                                              0x9E55C4
#define pinstCMailCompositionWnd                                   0x9E55C8
#define pinstCMailAddressBookWnd                                   0x9E55CC
#define pinstCRaidWnd                                              0x9E55D4
#define pinstCRaidOptionsWnd                                       0x9E55D8
#define pinstCBreathWnd                                            0x9E55DC
#define pinstCMapViewWnd                                           0x9E55E0
#define pinstCMapToolbarWnd                                        0x9E55E4
#define pinstCEditLabelWnd                                         0x9E55E8
#define pinstCTargetWnd                                            0x9E55EC
#define pinstCColorPickerWnd                                       0x9E55F0
#define pinstCPlayerWnd                                            0x9E55F4
#define pinstCOptionsWnd                                           0x9E55F8
#define pinstCBuffWindowNORMAL                                     0x9E55FC
#define pinstCBuffWindowSHORT                                      0x9E5600
#define pinstCharacterCreation                                     0x9E5604
#define pinstCCursorAttachment                                     0x9E5608
#define pinstCCastingWnd                                           0x9E560C
#define pinstCCastSpellWnd                                         0x9E5610
#define pinstCSpellBookWnd                                         0x9E5614
#define pinstCInventoryWnd                                         0x9E5618
#define pinstCBankWnd                                              0x9E561C
#define pinstCQuantityWnd                                          0x9E5620
#define pinstCLootWnd                                              0x9E5624
#define pinstCActionsWnd                                           0x9E5628
#define pinstCCombatAbilityWnd                                     0x9E562C
#define pinstCMerchantWnd                                          0x9E5630
#define pinstCTradeWnd                                             0x9E5634
#define pinstCSelectorWnd                                          0x9E5638
#define pinstCBazaarWnd                                            0x9E563C
#define pinstCBazaarSearchWnd                                      0x9E5640
#define pinstCGiveWnd                                              0x9E5644
#define pinstCTrackingWnd                                          0x9E5648
#define pinstCInspectWnd                                           0x9E564C
#define pinstCSocialEditWnd                                        0x9E5650
#define pinstCFeedbackWnd                                          0x9E5654
#define pinstCBugReportWnd                                         0x9E5658
#define pinstCVideoModesWnd                                        0x9E565C
#define pinstCTextEntryWnd                                         0x9E5664
#define pinstCFileSelectionWnd                                     0x9E5668
#define pinstCCompassWnd                                           0x9E566C
#define pinstCPlayerNotesWnd                                       0x9E5670
#define pinstCGemsGameWnd                                          0x9E5674
#define pinstCTimeLeftWnd                                          0x9E5678
#define pinstCPetitionQWnd                                         0x9E568C
#define pinstCSoulmarkWnd                                          0x9E5690
#define pinstCStoryWnd                                             0x9E5694
#define pinstCJournalTextWnd                                       0x9E5698
#define pinstCJournalCatWnd                                        0x9E569C
#define pinstCBodyTintWnd                                          0x9E56A0
#define pinstCServerListWnd                                        0x9E56A4
#define pinstCAvaZoneWnd                                           0x9E56AC
#define pinstCBlockedBuffWnd                                       0x9E56B0
#define pinstCBlockedPetBuffWnd                                    0x9E56B4
#define pinstCInvSlotMgr                                           0x9E56B8
#define pinstCContainerMgr                                         0x9E56BC
#define pinstCAdventureLeaderboardWnd                              0xB3E478
#define pinstCAdventureRequestWnd                                  0xB3E494
#define pinstCAltStorageWnd                                        0xB3E4F4
#define pinstCAdventureStatsWnd                                    0xB3E4B0
#define pinstCBarterMerchantWnd                                    0xB3E6C0
#define pinstCBarterSearchWnd                                      0xB3E6DC
#define pinstCBarterWnd                                            0xB3E6F8
#define pinstCChatManager                                          0xB3E99C
#define pinstCDynamicZoneWnd                                       0xB3EA94
#define pinstCEQMainWnd                                            0xB3EB08
#define pinstCFellowshipWnd                                        0xB3EB6C
#define pinstCFindLocationWnd                                      0xB3EBA0
#define pinstCGroupSearchWnd                                       0xB3EC50
#define pinstCGroupWnd                                             0xB3EC6C
#define pinstCGuildBankWnd                                         0xB3EC88
#define pinstCGuildMgmtWnd                                         0xB40CC0
#define pinstCGuildTributeMasterWnd                                0xB40CE0
#define pinstCHotButtonWnd                                         0xB40D14
#define pinstCHotButtonWnd1                                        0xB40D14
#define pinstCHotButtonWnd2                                        0xB40D18
#define pinstCHotButtonWnd3                                        0xB40D1C
#define pinstCHotButtonWnd4                                        0xB40D20
#define pinstCItemDisplayManager                                   0xB40DCC
#define pinstCItemExpTransferWnd                                   0xB40DEC
#define pinstCLeadershipWnd                                        0xB40E88
#define pinstCLFGuildWnd                                           0xB40EA4
#define pinstCMIZoneSelectWnd                                      0xB41014
#define pinstCAdventureMerchantWnd                                 0xB41124
#define pinstCConfirmationDialog                                   0xB41140
#define pinstCPopupWndManager                                      0xB41140
#define pinstCProgressionSelectionWnd                              0xB41174
#define pinstCPvPLeaderboardWnd                                    0xB41190
#define pinstCPvPStatsWnd                                          0xB411AC
#define pinstCSystemInfoDialogBox                                  0xB41278
#define pinstCTargetOfTargetWnd                                    0xB41D78
#define pinstCTaskSelectWnd                                        0xB41DAC
#define pinstCTaskTemplateSelectWnd                                0xB41DC8
#define pinstCTaskWnd                                              0xB41DE4
#define pinstCTipWndOFDAY                                          0xB41E60
#define pinstCTipWndCONTEXT                                        0xB41E64
#define pinstCTitleWnd                                             0xB41E80
#define pinstCTradeskillWnd                                        0xB41EC4
#define pinstCTributeBenefitWnd                                    0xB41F10
#define pinstCTributeMasterWnd                                     0xB41F2C
#define pinstCContextMenuManager                                   0xB4FE54
#define pinstCVoiceMacroWnd                                        0xB12CB4
#define pinstCHtmlWnd                                              0xB12D00


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4C6600
#define __ConvertItemTags                                          0x4B7E20
#define __ExecuteCmd                                               0x4A4170
#define __get_melee_range                                          0x4A9DF0
#define __GetGaugeValueFromEQ                                      0x660960
#define __GetLabelFromEQ                                           0x661A40
#define __GetXTargetType                                           0x755970
#define __LoadFrontEnd                                             0x572580
#define __NewUIINI                                                 0x6604F0
#define __ProcessGameEvents                                        0x4F8CA0
#define CrashDetected                                              0x572380
#define DrawNetStatus                                              0x51C570
#define Util__FastTime                                             0x6E7A80


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47B550
#define AltAdvManager__IsAbilityReady                              0x47B590
#define AltAdvManager__GetAltAbility                               0x47B7B0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x58FC20

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x599100

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x715880

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5AF6E0
#define CChatManager__InitContextMenu                              0x5AFEB0

// CChatService
#define CChatService__GetNumberOfFriends                           0x6D1D10
#define CChatService__GetFriendName                                0x6D1D20

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5B40B0
#define CChatWindow__Clear                                         0x5B4A20
#define CChatWindow__WndNotification                               0x5B4C10

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6FF6D0
#define CComboWnd__Draw                                            0x6FF890
#define CComboWnd__GetCurChoice                                    0x6FF670
#define CComboWnd__GetListRect                                     0x6FFB80
#define CComboWnd__GetTextRect                                     0x6FF700
#define CComboWnd__InsertChoice                                    0x6FFBF0
#define CComboWnd__SetColors                                       0x6FF600
#define CComboWnd__SetChoice                                       0x6FF630

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5BC0A0
#define CContainerWnd__vftable                                     0x826E38

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46E670
#define CDisplay__GetClickedActor                                  0x467970
#define CDisplay__GetUserDefinedColor                              0x466A90
#define CDisplay__GetWorldFilePath                                 0x465F20
#define CDisplay__is3dON                                           0x465060
#define CDisplay__ReloadUI                                         0x478760
#define CDisplay__WriteTextHD2                                     0x46A690

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x589A60
#define CEditBaseWnd__SetSel                                       0x722290

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7086A0
#define CEditWnd__GetCharIndexPt                                   0x709670
#define CEditWnd__GetDisplayString                                 0x708840
#define CEditWnd__GetHorzOffset                                    0x708AD0
#define CEditWnd__GetLineForPrintableChar                          0x709120
#define CEditWnd__GetSelStartPt                                    0x7098C0
#define CEditWnd__GetSTMLSafeText                                  0x708C70
#define CEditWnd__PointFromPrintableChar                           0x709230
#define CEditWnd__SelectableCharFromPoint                          0x7093B0
#define CEditWnd__SetEditable                                      0x708C40

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4DA3A0
#define CEverQuest__DropHeldItemOnGround                           0x4DE970
#define CEverQuest__dsp_chat                                       0x4E0110
#define CEverQuest__DoTellWindow                                   0x4DEAF0
#define CEverQuest__EnterZone                                      0x4F1BB0
#define CEverQuest__GetBodyTypeDesc                                0x4D75A0
#define CEverQuest__GetClassDesc                                   0x4D6DE0
#define CEverQuest__GetClassThreeLetterCode                        0x4D73E0
#define CEverQuest__GetDeityDesc                                   0x4D7C10
#define CEverQuest__GetLangDesc                                    0x4D7930
#define CEverQuest__GetRaceDesc                                    0x4D7BE0
#define CEverQuest__InterpretCmd                                   0x4E0C70
#define CEverQuest__LeftClickedOnPlayer                            0x4F36E0
#define CEverQuest__LMouseUp                                       0x4F6FF0
#define CEverQuest__RightClickedOnPlayer                           0x4F7890
#define CEverQuest__RMouseUp                                       0x4F8870
#define CEverQuest__SetGameState                                   0x4DA830
#define CEverQuest__Emote                                          0x4E0330

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5C8930
#define CGaugeWnd__CalcLinesFillRect                               0x5C8990
#define CGaugeWnd__Draw                                            0x5C8DE0

// CGuild
#define CGuild__FindMemberByName                                   0x41AF00

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5E18E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5EAE90
#define CInvSlotMgr__MoveItem                                      0x5EB030

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5EA720
#define CInvSlot__SliderComplete                                   0x5E9830

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5EBFE0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x65E2C0
#define CItemDisplayWnd__UpdateStrings                             0x5ECC90

// CLabel 
#define CLabel__Draw                                               0x5FF360

// CListWnd 
#define CListWnd__AddColumn                                        0x6F90D0
#define CListWnd__AddColumn1                                       0x6F8BA0
#define CListWnd__AddLine                                          0x6F86C0
#define CListWnd__AddString                                        0x6F8860
#define CListWnd__CalculateFirstVisibleLine                        0x6F5380
#define CListWnd__CalculateVSBRange                                0x6F75A0
#define CListWnd__ClearAllSel                                      0x6F48D0
#define CListWnd__CloseAndUpdateEditWindow                         0x6F5A00
#define CListWnd__Compare                                          0x6F5DA0
#define CListWnd__Draw                                             0x6F7220
#define CListWnd__DrawColumnSeparators                             0x6F7090
#define CListWnd__DrawHeader                                       0x6F4B60
#define CListWnd__DrawItem                                         0x6F66B0
#define CListWnd__DrawLine                                         0x6F6D00
#define CListWnd__DrawSeparator                                    0x6F7130
#define CListWnd__EnsureVisible                                    0x6F5410
#define CListWnd__ExtendSel                                        0x6F65D0
#define CListWnd__GetColumnMinWidth                                0x6F4660
#define CListWnd__GetColumnWidth                                   0x6F45A0
#define CListWnd__GetCurSel                                        0x6F3FE0
#define CListWnd__GetHeaderRect                                    0x6F4150
#define CListWnd__GetItemAtPoint                                   0x6F5710
#define CListWnd__GetItemAtPoint1                                  0x6F5780
#define CListWnd__GetItemData                                      0x6F4350
#define CListWnd__GetItemHeight                                    0x6F4FF0
#define CListWnd__GetItemIcon                                      0x6F44E0
#define CListWnd__GetItemRect                                      0x6F54F0
#define CListWnd__GetItemText                                      0x6F4390
#define CListWnd__GetSelList                                       0x6F8A80
#define CListWnd__GetSeparatorRect                                 0x6F5CE0
#define CListWnd__RemoveLine                                       0x6F8A30
#define CListWnd__SetColors                                        0x6F40B0
#define CListWnd__SetColumnJustification                           0x6F4740
#define CListWnd__SetColumnWidth                                   0x6F4620
#define CListWnd__SetCurSel                                        0x6F4020
#define CListWnd__SetItemColor                                     0x6F8250
#define CListWnd__SetItemData                                      0x6F4970
#define CListWnd__SetItemText                                      0x6F81D0
#define CListWnd__ShiftColumnSeparator                             0x6F64E0
#define CListWnd__Sort                                             0x6F9110
#define CListWnd__ToggleSel                                        0x6F4840

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x614BF0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x622B50
#define CMerchantWnd__RequestBuyItem                               0x624B70
#define CMerchantWnd__RequestSellItem                              0x624F90
#define CMerchantWnd__SelectBuySellSlot                            0x623FA0

// CObfuscator
#define CObfuscator__doit                                          0x6ABCC0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x710FC0
#define CSidlManager__CreateLabel                                  0x6571F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x701320
#define CSidlScreenWnd__CalculateVSBRange                          0x58BBD0
#define CSidlScreenWnd__ConvertToRes                               0x722170
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7017F0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7028E0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x702990
#define CSidlScreenWnd__dCSidlScreenWnd                            0x702090
#define CSidlScreenWnd__DrawSidlPiece                              0x7014B0
#define CSidlScreenWnd__EnableIniStorage                           0x701010
#define CSidlScreenWnd__GetSidlPiece                               0x7016C0
#define CSidlScreenWnd__Init1                                      0x702740
#define CSidlScreenWnd__LoadIniInfo                                0x7018B0
#define CSidlScreenWnd__LoadIniListWnd                             0x701160
#define CSidlScreenWnd__LoadSidlScreen                             0x7022E0
#define CSidlScreenWnd__StoreIniInfo                               0x700C20
#define CSidlScreenWnd__StoreIniVis                                0x700FA0
#define CSidlScreenWnd__WndNotification                            0x7024C0
#define CSidlScreenWnd__GetChildItem                               0x701070

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x540220

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7236C0
#define CSliderWnd__SetValue                                       0x7237C0
#define CSliderWnd__SetNumTicks                                    0x723D70

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x65C020

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x720380
#define CStmlWnd__CalculateHSBRange                                0x717B10
#define CStmlWnd__CalculateVSBRange                                0x717A80
#define CStmlWnd__CanBreakAtCharacter                              0x717C90
#define CStmlWnd__FastForwardToEndOfTag                            0x718960
#define CStmlWnd__ForceParseNow                                    0x720880
#define CStmlWnd__GetNextTagPiece                                  0x718880
#define CStmlWnd__GetSTMLText                                      0x5B4050
#define CStmlWnd__GetThisChar                                      0x747510
#define CStmlWnd__GetVisiableText                                  0x719DA0
#define CStmlWnd__InitializeWindowVariables                        0x71C300
#define CStmlWnd__MakeStmlColorTag                                 0x7169A0
#define CStmlWnd__MakeWndNotificationTag                           0x716A40
#define CStmlWnd__SetSTMLText                                      0x71C420
#define CStmlWnd__StripFirstSTMLLines                              0x720020
#define CStmlWnd__UpdateHistoryString                              0x71A630

// CTabWnd 
#define CTabWnd__Draw                                              0x724B10
#define CTabWnd__DrawCurrentPage                                   0x724520
#define CTabWnd__DrawTab                                           0x724300
#define CTabWnd__GetCurrentPage                                    0x7247A0
#define CTabWnd__GetPageClientRect                                 0x723FD0
#define CTabWnd__GetPageFromTabIndex                               0x724230
#define CTabWnd__GetPageInnerRect                                  0x724030
#define CTabWnd__GetTabInnerRect                                   0x7241B0
#define CTabWnd__GetTabRect                                        0x7240C0
#define CTabWnd__InsertPage                                        0x724DA0
#define CTabWnd__SetPage                                           0x7247E0
#define CTabWnd__SetPageRect                                       0x724A40
#define CTabWnd__UpdatePage                                        0x724D20

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4174C0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x702D10

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x725A10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6F3290

// CXRect 
#define CXRect__CenterPoint                                        0x58F2A0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x50B5A0
#define CXStr__CXStr1                                              0x7709C0
#define CXStr__CXStr3                                              0x6E4D40
#define CXStr__dCXStr                                              0x6F9260
#define CXStr__operator_equal1                                     0x6E4F00
#define CXStr__operator_plus_equal1                                0x6E5F40

// CXWnd 
#define CXWnd__BringToTop                                          0x6F9710
#define CXWnd__Center                                              0x6FDF50
#define CXWnd__ClrFocus                                            0x6F9530
#define CXWnd__DoAllDrawing                                        0x6FEDA0
#define CXWnd__DrawChildren                                        0x6FEEF0
#define CXWnd__DrawColoredRect                                     0x6F99F0
#define CXWnd__DrawTooltip                                         0x6FEBF0
#define CXWnd__DrawTooltipAtPoint                                  0x6FDD00
#define CXWnd__GetBorderFrame                                      0x6F9E30
#define CXWnd__GetChildWndAt                                       0x6FD530
#define CXWnd__GetClientClipRect                                   0x6F9CB0
#define CXWnd__GetScreenClipRect                                   0x6FE170
#define CXWnd__GetScreenRect                                       0x6F9FC0
#define CXWnd__GetTooltipRect                                      0x6F9B00
#define CXWnd__GetWindowTextA                                      0x57D410
#define CXWnd__IsActive                                            0x703E80
#define CXWnd__IsDescendantOf                                      0x6F9D60
#define CXWnd__IsReallyVisible                                     0x6FD510
#define CXWnd__IsType                                              0x728800
#define CXWnd__Move                                                0x6FCCD0
#define CXWnd__Move1                                               0x6FE9D0
#define CXWnd__ProcessTransition                                   0x6F96C0
#define CXWnd__Refade                                              0x6F9640
#define CXWnd__Resize                                              0x6FA090
#define CXWnd__Right                                               0x6FE0B0
#define CXWnd__SetFocus                                            0x6FB8A0
#define CXWnd__SetKeyTooltip                                       0x6FA270
#define CXWnd__SetMouseOver                                        0x6FE400
#define CXWnd__StartFade                                           0x6F9750
#define CXWnd__GetChildItem                                        0x6FE380

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x705450
#define CXWndManager__DrawWindows                                  0x7050D0
#define CXWndManager__GetKeyboardFlags                             0x703AD0
#define CXWndManager__HandleKeyboardMsg                            0x704150
#define CXWndManager__RemoveWnd                                    0x703FA0

// CDBStr
#define CDBStr__GetString                                          0x4639E0

// EQ_Character 
#define EQ_Character__CastRay                                      0x7537F0
#define EQ_Character__CastSpell                                    0x42DCB0
#define EQ_Character__Cur_HP                                       0x437200
#define EQ_Character__GetAACastingTimeModifier                     0x423AC0
#define EQ_Character__GetCharInfo2                                 0x6C2D30
#define EQ_Character__GetFocusCastingTimeModifier                  0x41F300
#define EQ_Character__GetFocusRangeModifier                        0x41F440
#define EQ_Character__Max_Endurance                                0x522AF0
#define EQ_Character__Max_HP                                       0x4321D0
#define EQ_Character__Max_Mana                                     0x522920
#define EQ_Character__doCombatAbility                              0x521830
#define EQ_Character__UseSkill                                     0x441B70
#define EQ_Character__GetConLevel                                  0x51DA30

// EQ_Item 
#define EQ_Item__CanDrop                                           0x509310
#define EQ_Item__GetItemLinkHash                                   0x6B5770
#define EQ_Item__IsStackable                                       0x6AC5A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x47C680
#define EQ_LoadingS__Array                                         0x8A8D78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x525990
#define EQ_PC__GetAltAbilityIndex                                  0x6BAA00
#define EQ_PC__GetCombatAbility                                    0x6BAA90
#define EQ_PC__GetCombatAbilityTimer                               0x6BAB40
#define EQ_PC__GetItemTimerValue                                   0x520750
#define EQ_PC__HasLoreItem                                         0x523E40

// EQItemList 
#define EQItemList__EQItemList                                     0x4A7F70
#define EQItemList__add_item                                       0x4A8020
#define EQItemList__delete_item                                    0x4A8280
#define EQItemList__FreeItemList                                   0x4A8040

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x463370

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x52A360
#define EQPlayer__dEQPlayer                                        0x52E510
#define EQPlayer__DoAttack                                         0x53C420
#define EQPlayer__EQPlayer                                         0x532270
#define EQPlayer__SetNameSpriteState                               0x52C470
#define EQPlayer__SetNameSpriteTint                                0x52A3D0
#define EQPlayer__IsBodyType_j                                     0x753100
#define EQPlayer__IsTargetable                                     0x753290

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x533420
#define EQPlayerManager__GetSpawnByName                            0x533700

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x50AFC0
#define KeypressHandler__AttachKeyToEqCommand                      0x50B000
#define KeypressHandler__ClearCommandStateArray                    0x50ADD0
#define KeypressHandler__HandleKeyDown                             0x509950
#define KeypressHandler__HandleKeyUp                               0x509C60
#define KeypressHandler__SaveKeymapping                            0x50AEA0

// MapViewMap 
#define MapViewMap__Clear                                          0x610290
#define MapViewMap__SaveEx                                         0x610C60

#define OtherCharData__GetAltCurrency                              0x6DA930

// StringTable 
#define StringTable__getString                                     0x6ABF40
