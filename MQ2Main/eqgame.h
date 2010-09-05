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
#define __ExpectedVersionDate                                     "Jul 27 2010"
#define __ExpectedVersionTime                                     "14:05:17"
#define __ActualVersionDate                                        0x828698
#define __ActualVersionTime                                        0x8286A4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x512620
#define __MemChecker1                                              0x6EE780
#define __MemChecker2                                              0x577130
#define __MemChecker3                                              0x577080
#define __MemChecker4                                              0x6A2160
#define __EncryptPad0                                              0x8BA1C0
#define __EncryptPad1                                              0x8C52E8
#define __EncryptPad2                                              0x8BCE00
#define __EncryptPad3                                              0x8BCA00
#define __EncryptPad4                                              0x8C4930
#define __AC1                                                      0x668620
#define __AC2                                                      0x4DA825
#define __AC3                                                      0x4EE848
#define __AC4                                                      0x4F2718
#define __AC5                                                      0x4FCE88
#define __AC6                                                      0x50031B
#define __AC7                                                      0x4F93B4
#define __AC1_Data                                                 0x8100A0

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
#define __do_loot                                                  0x4B2920
#define __DrawHandler                                              0xB5A71C
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
#define pinstCSidlManager                                          0xB59E94
#define pinstCXWndManager                                          0xB59E8C
#define instDynamicZone                                            0xAA54F0
#define pinstDZMember                                              0xAA5600
#define pinstDZTimerInfo                                           0xAA5604
#define pinstEQItemList                                            0xA9E750
#define instEQMisc                                                 0x9EED60
#define pinstEQSoundManager                                        0x9EFC5C
#define instExpeditionLeader                                       0xAA553A
#define instExpeditionName                                         0xAA557A
#define pinstGroup                                                 0xA9F526
#define pinstImeManager                                            0xB59E98
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
#define pinstCTargetOfTargetWnd                                    0xB4BE10
#define pinstCTaskSelectWnd                                        0xB4BE44
#define pinstCTaskTemplateSelectWnd                                0xB4BE60
#define pinstCTaskWnd                                              0xB4BE7C
#define pinstCTipWndOFDAY                                          0xB4BEF8
#define pinstCTipWndCONTEXT                                        0xB4BEFC
#define pinstCTitleWnd                                             0xB4BF18
#define pinstCTradeskillWnd                                        0xB4BF5C
#define pinstCTributeBenefitWnd                                    0xB4BFA8
#define pinstCTributeMasterWnd                                     0xB4BFC4
#define pinstCContextMenuManager                                   0xB59EF0
#define pinstCVoiceMacroWnd                                        0xB1CD2C
#define pinstCHtmlWnd                                              0xB1CD78


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4C64F0
#define __ConvertItemTags                                          0x4B7FA0
#define __ExecuteCmd                                               0x4A42D0
#define __get_melee_range                                          0x4A9F60
#define __GetGaugeValueFromEQ                                      0x6674D0
#define __GetLabelFromEQ                                           0x6685C0
#define __GetXTargetType                                           0x75D4E0
#define __LoadFrontEnd                                             0x576000
#define __NewUIINI                                                 0x667060
#define __ProcessGameEvents                                        0x4F97A0
#define CrashDetected                                              0x575E00
#define DrawNetStatus                                              0x51D1D0
#define Util__FastTime                                             0x6EEE90


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47B9A0
#define AltAdvManager__IsAbilityReady                              0x47B9E0
#define AltAdvManager__GetAltAbility                               0x47BBF0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x4378E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x593C40

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x59D450

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x71D350

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5B2F40
#define CChatManager__InitContextMenu                              0x5B3710

// CChatService
#define CChatService__GetNumberOfFriends                           0x6D9400
#define CChatService__GetFriendName                                0x6D9410

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5B78F0
#define CChatWindow__Clear                                         0x5B8250
#define CChatWindow__WndNotification                               0x5B8440

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x7073A0
#define CComboWnd__Draw                                            0x707560
#define CComboWnd__GetCurChoice                                    0x707340
#define CComboWnd__GetListRect                                     0x707850
#define CComboWnd__GetTextRect                                     0x7073D0
#define CComboWnd__InsertChoice                                    0x7078C0
#define CComboWnd__SetColors                                       0x7072D0
#define CComboWnd__SetChoice                                       0x707300

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5BF880
#define CContainerWnd__vftable                                     0x8302F0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46E9F0
#define CDisplay__GetClickedActor                                  0x467D90
#define CDisplay__GetUserDefinedColor                              0x466EB0
#define CDisplay__GetWorldFilePath                                 0x466340
#define CDisplay__is3dON                                           0x465470
#define CDisplay__ReloadUI                                         0x478B30
#define CDisplay__WriteTextHD2                                     0x46AA90

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x58DB30
#define CEditBaseWnd__SetSel                                       0x729D10

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7103B0
#define CEditWnd__GetCharIndexPt                                   0x711370
#define CEditWnd__GetDisplayString                                 0x710540
#define CEditWnd__GetHorzOffset                                    0x7107D0
#define CEditWnd__GetLineForPrintableChar                          0x710E20
#define CEditWnd__GetSelStartPt                                    0x7115C0
#define CEditWnd__GetSTMLSafeText                                  0x710970
#define CEditWnd__PointFromPrintableChar                           0x710F30
#define CEditWnd__SelectableCharFromPoint                          0x7110B0
#define CEditWnd__SetEditable                                      0x710940

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4DAF00
#define CEverQuest__DropHeldItemOnGround                           0x4DF470
#define CEverQuest__dsp_chat                                       0x4E0C10
#define CEverQuest__DoTellWindow                                   0x4DF5F0
#define CEverQuest__EnterZone                                      0x4F26B0
#define CEverQuest__GetBodyTypeDesc                                0x4D8100
#define CEverQuest__GetClassDesc                                   0x4D7940
#define CEverQuest__GetClassThreeLetterCode                        0x4D7F40
#define CEverQuest__GetDeityDesc                                   0x4D8770
#define CEverQuest__GetLangDesc                                    0x4D8490
#define CEverQuest__GetRaceDesc                                    0x4D8740
#define CEverQuest__InterpretCmd                                   0x4E1770
#define CEverQuest__LeftClickedOnPlayer                            0x4F41E0
#define CEverQuest__LMouseUp                                       0x4F7AF0
#define CEverQuest__RightClickedOnPlayer                           0x4F8390
#define CEverQuest__RMouseUp                                       0x4F9370
#define CEverQuest__SetGameState                                   0x4DB390
#define CEverQuest__Emote                                          0x4E0E30

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5CC1A0
#define CGaugeWnd__CalcLinesFillRect                               0x5CC200
#define CGaugeWnd__Draw                                            0x5CC650

// CGuild
#define CGuild__FindMemberByName                                   0x41B890

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5E51B0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5EE990
#define CInvSlotMgr__MoveItem                                      0x5EEB30

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5EE1E0
#define CInvSlot__SliderComplete                                   0x5ED2F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5EFAE0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x664E30
#define CItemDisplayWnd__UpdateStrings                             0x5F0790

// CLabel 
#define CLabel__Draw                                               0x602F60

// CListWnd 
#define CListWnd__AddColumn                                        0x700980
#define CListWnd__AddColumn1                                       0x700460
#define CListWnd__AddLine                                          0x6FFF80
#define CListWnd__AddString                                        0x700120
#define CListWnd__CalculateFirstVisibleLine                        0x6FCC60
#define CListWnd__CalculateVSBRange                                0x6FEE60
#define CListWnd__ClearAllSel                                      0x6FC1B0
#define CListWnd__CloseAndUpdateEditWindow                         0x6FD2D0
#define CListWnd__Compare                                          0x6FD670
#define CListWnd__Draw                                             0x6FEAE0
#define CListWnd__DrawColumnSeparators                             0x6FE950
#define CListWnd__DrawHeader                                       0x6FC440
#define CListWnd__DrawItem                                         0x6FDF80
#define CListWnd__DrawLine                                         0x6FE5C0
#define CListWnd__DrawSeparator                                    0x6FE9F0
#define CListWnd__EnsureVisible                                    0x6FCCF0
#define CListWnd__ExtendSel                                        0x6FDEA0
#define CListWnd__GetColumnMinWidth                                0x6FBF40
#define CListWnd__GetColumnWidth                                   0x6FBE80
#define CListWnd__GetCurSel                                        0x6FB8A0
#define CListWnd__GetHeaderRect                                    0x6FBA00
#define CListWnd__GetItemAtPoint                                   0x6FCFE0
#define CListWnd__GetItemAtPoint1                                  0x6FD050
#define CListWnd__GetItemData                                      0x6FBC30
#define CListWnd__GetItemHeight                                    0x6FC8D0
#define CListWnd__GetItemIcon                                      0x6FBDC0
#define CListWnd__GetItemRect                                      0x6FCDC0
#define CListWnd__GetItemText                                      0x6FBC70
#define CListWnd__GetSelList                                       0x700340
#define CListWnd__GetSeparatorRect                                 0x6FD5B0
#define CListWnd__RemoveLine                                       0x7002F0
#define CListWnd__SetColors                                        0x6FB970
#define CListWnd__SetColumnJustification                           0x6FC020
#define CListWnd__SetColumnWidth                                   0x6FBF00
#define CListWnd__SetCurSel                                        0x6FB8E0
#define CListWnd__SetItemColor                                     0x6FFB10
#define CListWnd__SetItemData                                      0x6FC250
#define CListWnd__SetItemText                                      0x6FFA90
#define CListWnd__ShiftColumnSeparator                             0x6FDDB0
#define CListWnd__Sort                                             0x7009C0
#define CListWnd__ToggleSel                                        0x6FC120

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x6188C0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x629830
#define CMerchantWnd__RequestBuyItem                               0x62B860
#define CMerchantWnd__RequestSellItem                              0x62BC80
#define CMerchantWnd__SelectBuySellSlot                            0x62AC80

// CObfuscator
#define CObfuscator__doit                                          0x6B2BC0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x718C40
#define CSidlManager__CreateLabel                                  0x65DDF0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x709000
#define CSidlScreenWnd__CalculateVSBRange                          0x58FC90
#define CSidlScreenWnd__ConvertToRes                               0x729BF0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7094C0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x70A5E0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x70A690
#define CSidlScreenWnd__dCSidlScreenWnd                            0x709DA0
#define CSidlScreenWnd__DrawSidlPiece                              0x709180
#define CSidlScreenWnd__EnableIniStorage                           0x708CF0
#define CSidlScreenWnd__GetSidlPiece                               0x709390
#define CSidlScreenWnd__Init1                                      0x70A440
#define CSidlScreenWnd__LoadIniInfo                                0x709570
#define CSidlScreenWnd__LoadIniListWnd                             0x708E40
#define CSidlScreenWnd__LoadSidlScreen                             0x709FF0
#define CSidlScreenWnd__StoreIniInfo                               0x7088F0
#define CSidlScreenWnd__StoreIniVis                                0x708C80
#define CSidlScreenWnd__WndNotification                            0x70A1C0
#define CSidlScreenWnd__GetChildItem                               0x708D50

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x543710

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x72B150
#define CSliderWnd__SetValue                                       0x72B260
#define CSliderWnd__SetNumTicks                                    0x72B810

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x662B80

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x727E30
#define CStmlWnd__CalculateHSBRange                                0x71F5D0
#define CStmlWnd__CalculateVSBRange                                0x71F540
#define CStmlWnd__CanBreakAtCharacter                              0x71F740
#define CStmlWnd__FastForwardToEndOfTag                            0x720420
#define CStmlWnd__ForceParseNow                                    0x728330
#define CStmlWnd__GetNextTagPiece                                  0x720340
#define CStmlWnd__GetSTMLText                                      0x5B7890
#define CStmlWnd__GetThisChar                                      0x74F100
#define CStmlWnd__GetVisiableText                                  0x721860
#define CStmlWnd__InitializeWindowVariables                        0x723DC0
#define CStmlWnd__MakeStmlColorTag                                 0x71E460
#define CStmlWnd__MakeWndNotificationTag                           0x71E500
#define CStmlWnd__SetSTMLText                                      0x723EE0
#define CStmlWnd__StripFirstSTMLLines                              0x727AE0
#define CStmlWnd__UpdateHistoryString                              0x7220F0

// CTabWnd 
#define CTabWnd__Draw                                              0x72C5A0
#define CTabWnd__DrawCurrentPage                                   0x72BFC0
#define CTabWnd__DrawTab                                           0x72BDA0
#define CTabWnd__GetCurrentPage                                    0x72C240
#define CTabWnd__GetPageClientRect                                 0x72BA70
#define CTabWnd__GetPageFromTabIndex                               0x72BCD0
#define CTabWnd__GetPageInnerRect                                  0x72BAD0
#define CTabWnd__GetTabInnerRect                                   0x72BC50
#define CTabWnd__GetTabRect                                        0x72BB60
#define CTabWnd__InsertPage                                        0x72C830
#define CTabWnd__SetPage                                           0x72C280
#define CTabWnd__SetPageRect                                       0x72C4D0
#define CTabWnd__UpdatePage                                        0x72C7B0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417E50

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x70AA10

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x72D480

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6FA910

// CXRect 
#define CXRect__CenterPoint                                        0x5932D0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x50C0C0
#define CXStr__CXStr1                                              0x779480
#define CXStr__CXStr3                                              0x6EC190
#define CXStr__dCXStr                                              0x72FA40
#define CXStr__operator_equal1                                     0x6EC350
#define CXStr__operator_plus_equal1                                0x6ED390

// CXWnd 
#define CXWnd__BringToTop                                          0x700F90
#define CXWnd__Center                                              0x705DC0
#define CXWnd__ClrFocus                                            0x700DC0
#define CXWnd__DoAllDrawing                                        0x706740
#define CXWnd__DrawChildren                                        0x706890
#define CXWnd__DrawColoredRect                                     0x701270
#define CXWnd__DrawTooltip                                         0x705CF0
#define CXWnd__DrawTooltipAtPoint                                  0x7050A0
#define CXWnd__GetBorderFrame                                      0x701720
#define CXWnd__GetChildWndAt                                       0x704510
#define CXWnd__GetClientClipRect                                   0x701530
#define CXWnd__GetScreenClipRect                                   0x705500
#define CXWnd__GetScreenRect                                       0x701840
#define CXWnd__GetTooltipRect                                      0x701380
#define CXWnd__GetWindowTextA                                      0x5812D0
#define CXWnd__IsActive                                            0x70BB40
#define CXWnd__IsDescendantOf                                      0x701610
#define CXWnd__IsReallyVisible                                     0x7044F0
#define CXWnd__IsType                                              0x730330
#define CXWnd__Move                                                0x703C40
#define CXWnd__Move1                                               0x705A50
#define CXWnd__ProcessTransition                                   0x700F40
#define CXWnd__Refade                                              0x700EC0
#define CXWnd__Resize                                              0x701910
#define CXWnd__Right                                               0x705440
#define CXWnd__SetFocus                                            0x703050
#define CXWnd__SetKeyTooltip                                       0x701B00
#define CXWnd__SetMouseOver                                        0x7057A0
#define CXWnd__StartFade                                           0x700FC0
#define CXWnd__GetChildItem                                        0x705710

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x70D120
#define CXWndManager__DrawWindows                                  0x70CDA0
#define CXWndManager__GetKeyboardFlags                             0x70B7A0
#define CXWndManager__HandleKeyboardMsg                            0x70BE10
#define CXWndManager__RemoveWnd                                    0x70BC60

// CDBStr
#define CDBStr__GetString                                          0x463DE0

// EQ_Character 
#define EQ_Character__CastRay                                      0x75B360
#define EQ_Character__CastSpell                                    0x42E400
#define EQ_Character__Cur_HP                                       0x4375A0
#define EQ_Character__GetAACastingTimeModifier                     0x4243F0
#define EQ_Character__GetCharInfo2                                 0x6C9C60
#define EQ_Character__GetFocusCastingTimeModifier                  0x41FC60
#define EQ_Character__GetFocusRangeModifier                        0x41FDA0
#define EQ_Character__Max_Endurance                                0x524400
#define EQ_Character__Max_HP                                       0x432570
#define EQ_Character__Max_Mana                                     0x524230
#define EQ_Character__doCombatAbility                              0x523140
#define EQ_Character__UseSkill                                     0x441FA0
#define EQ_Character__GetConLevel                                  0x51F340

// EQ_Item 
#define EQ_Item__CanDrop                                           0x509E30
#define EQ_Item__GetItemLinkHash                                   0x6BC670
#define EQ_Item__IsStackable                                       0x6B34A0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x47CAC0
#define EQ_LoadingS__Array                                         0x8B2D88

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x5272A0
#define EQ_PC__GetAltAbilityIndex                                  0x6C18B0
#define EQ_PC__GetCombatAbility                                    0x6C1940
#define EQ_PC__GetCombatAbilityTimer                               0x6C19F0
#define EQ_PC__GetItemTimerValue                                   0x522070
#define EQ_PC__HasLoreItem                                         0x525750

// EQItemList 
#define EQItemList__EQItemList                                     0x4A8130
#define EQItemList__add_item                                       0x4A81E0
#define EQItemList__delete_item                                    0x4A8440
#define EQItemList__FreeItemList                                   0x4A8200

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x463790

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x52BEA0
#define EQPlayer__dEQPlayer                                        0x530780
#define EQPlayer__DoAttack                                         0x53F8A0
#define EQPlayer__EQPlayer                                         0x535630
#define EQPlayer__SetNameSpriteState                               0x52E2A0
#define EQPlayer__SetNameSpriteTint                                0x52BF10
#define EQPlayer__IsBodyType_j                                     0x75AC70
#define EQPlayer__IsTargetable                                     0x75AE00

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5368C0
#define EQPlayerManager__GetSpawnByName                            0x536BA0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x50BAE0
#define KeypressHandler__AttachKeyToEqCommand                      0x50BB20
#define KeypressHandler__ClearCommandStateArray                    0x50B8F0
#define KeypressHandler__HandleKeyDown                             0x50A470
#define KeypressHandler__HandleKeyUp                               0x50A780
#define KeypressHandler__SaveKeymapping                            0x50B9C0

// MapViewMap 
#define MapViewMap__Clear                                          0x613F60
#define MapViewMap__SaveEx                                         0x614930

#define PlayerPointManager__GetAltCurrency                         0x6E2110

// StringTable 
#define StringTable__getString                                     0x6B2E40