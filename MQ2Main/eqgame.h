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
#define __ExpectedVersionDate                                     "Aug 17 2010"
#define __ExpectedVersionTime                                     "12:19:09"
#define __ActualVersionDate                                        0x8286A8
#define __ActualVersionTime                                        0x8286B4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x512730
#define __MemChecker1                                              0x6EEC30
#define __MemChecker2                                              0x577070
#define __MemChecker3                                              0x576FC0
#define __MemChecker4                                              0x6A2550
#define __EncryptPad0                                              0x8BA1C0
#define __EncryptPad1                                              0x8C52E8
#define __EncryptPad2                                              0x8BCE00
#define __EncryptPad3                                              0x8BCA00
#define __EncryptPad4                                              0x8C4930
#define __AC1                                                      0x668B30
#define __AC2                                                      0x4DA865
#define __AC3                                                      0x4EE808
#define __AC4                                                      0x4F26D8
#define __AC5                                                      0x4FCE48
#define __AC6                                                      0x5002DB
#define __AC7                                                      0x4F9374
#define __AC1_Data                                                 0x810630

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
#define __do_loot                                                  0x4B2840
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
#define __CastRay                                                  0x4C6410
#define __ConvertItemTags                                          0x4B7EC0
#define __ExecuteCmd                                               0x4A4200
#define __get_melee_range                                          0x4A9E80
#define __GetGaugeValueFromEQ                                      0x6679E0
#define __GetLabelFromEQ                                           0x668AD0
#define __GetXTargetType                                           0x75D9B0
#define __LoadFrontEnd                                             0x575F40
#define __NewUIINI                                                 0x667570
#define __ProcessGameEvents                                        0x4F9760
#define CrashDetected                                              0x575D40
#define DrawNetStatus                                              0x51D250
#define Util__FastTime                                             0x6EF380


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47B900
#define AltAdvManager__IsAbilityReady                              0x47B940
#define AltAdvManager__GetAltAbility                               0x47BB20

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x4378F0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x593B50

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x59D3C0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x71D6B0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5B3070
#define CChatManager__InitContextMenu                              0x5B3840

// CChatService
#define CChatService__GetNumberOfFriends                           0x6D9960
#define CChatService__GetFriendName                                0x6D9970

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5B7A20
#define CChatWindow__Clear                                         0x5B8380
#define CChatWindow__WndNotification                               0x5B8570

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x707730
#define CComboWnd__Draw                                            0x7078F0
#define CComboWnd__GetCurChoice                                    0x7076D0
#define CComboWnd__GetListRect                                     0x707BE0
#define CComboWnd__GetTextRect                                     0x707760
#define CComboWnd__InsertChoice                                    0x707C50
#define CComboWnd__SetColors                                       0x707660
#define CComboWnd__SetChoice                                       0x707690

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5BF9B0
#define CContainerWnd__vftable                                     0x830300

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46E950
#define CDisplay__GetClickedActor                                  0x467D00
#define CDisplay__GetUserDefinedColor                              0x466E20
#define CDisplay__GetWorldFilePath                                 0x4662B0
#define CDisplay__is3dON                                           0x4653E0
#define CDisplay__ReloadUI                                         0x478B10
#define CDisplay__WriteTextHD2                                     0x46A9F0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x58DA30
#define CEditBaseWnd__SetSel                                       0x72A080

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x710600
#define CEditWnd__GetCharIndexPt                                   0x7115C0
#define CEditWnd__GetDisplayString                                 0x710790
#define CEditWnd__GetHorzOffset                                    0x710A20
#define CEditWnd__GetLineForPrintableChar                          0x711070
#define CEditWnd__GetSelStartPt                                    0x711810
#define CEditWnd__GetSTMLSafeText                                  0x710BC0
#define CEditWnd__PointFromPrintableChar                           0x711180
#define CEditWnd__SelectableCharFromPoint                          0x711300
#define CEditWnd__SetEditable                                      0x710B90

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4DAF40
#define CEverQuest__DropHeldItemOnGround                           0x4DF480
#define CEverQuest__dsp_chat                                       0x4E0BD0
#define CEverQuest__DoTellWindow                                   0x4DF600
#define CEverQuest__EnterZone                                      0x4F2670
#define CEverQuest__GetBodyTypeDesc                                0x4D8140
#define CEverQuest__GetClassDesc                                   0x4D7980
#define CEverQuest__GetClassThreeLetterCode                        0x4D7F80
#define CEverQuest__GetDeityDesc                                   0x4D87B0
#define CEverQuest__GetLangDesc                                    0x4D84D0
#define CEverQuest__GetRaceDesc                                    0x4D8780
#define CEverQuest__InterpretCmd                                   0x4E1730
#define CEverQuest__LeftClickedOnPlayer                            0x4F41A0
#define CEverQuest__LMouseUp                                       0x4F7AB0
#define CEverQuest__RightClickedOnPlayer                           0x4F8350
#define CEverQuest__RMouseUp                                       0x4F9330
#define CEverQuest__SetGameState                                   0x4DB3D0
#define CEverQuest__Emote                                          0x4E0DF0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5CC200
#define CGaugeWnd__CalcLinesFillRect                               0x5CC260
#define CGaugeWnd__Draw                                            0x5CC6B0

// CGuild
#define CGuild__FindMemberByName                                   0x41B890

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5E5240

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5EE9D0
#define CInvSlotMgr__MoveItem                                      0x5EEB70

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5EE220
#define CInvSlot__SliderComplete                                   0x5ED330

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5EFB20

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x665350
#define CItemDisplayWnd__UpdateStrings                             0x5F07D0

// CLabel 
#define CLabel__Draw                                               0x602FB0

// CListWnd 
#define CListWnd__AddColumn                                        0x700D10
#define CListWnd__AddColumn1                                       0x7007F0
#define CListWnd__AddLine                                          0x700310
#define CListWnd__AddString                                        0x7004B0
#define CListWnd__CalculateFirstVisibleLine                        0x6FCFF0
#define CListWnd__CalculateVSBRange                                0x6FF1F0
#define CListWnd__ClearAllSel                                      0x6FC540
#define CListWnd__CloseAndUpdateEditWindow                         0x6FD660
#define CListWnd__Compare                                          0x6FDA00
#define CListWnd__Draw                                             0x6FEE70
#define CListWnd__DrawColumnSeparators                             0x6FECE0
#define CListWnd__DrawHeader                                       0x6FC7D0
#define CListWnd__DrawItem                                         0x6FE310
#define CListWnd__DrawLine                                         0x6FE950
#define CListWnd__DrawSeparator                                    0x6FED80
#define CListWnd__EnsureVisible                                    0x6FD080
#define CListWnd__ExtendSel                                        0x6FE230
#define CListWnd__GetColumnMinWidth                                0x6FC260
#define CListWnd__GetColumnWidth                                   0x6FC1A0
#define CListWnd__GetCurSel                                        0x6FBBF0
#define CListWnd__GetHeaderRect                                    0x6FBD50
#define CListWnd__GetItemAtPoint                                   0x6FD370
#define CListWnd__GetItemAtPoint1                                  0x6FD3E0
#define CListWnd__GetItemData                                      0x6FBF50
#define CListWnd__GetItemHeight                                    0x6FCC60
#define CListWnd__GetItemIcon                                      0x6FC0E0
#define CListWnd__GetItemRect                                      0x6FD150
#define CListWnd__GetItemText                                      0x6FBF90
#define CListWnd__GetSelList                                       0x7006D0
#define CListWnd__GetSeparatorRect                                 0x6FD940
#define CListWnd__RemoveLine                                       0x700680
#define CListWnd__SetColors                                        0x6FBCC0
#define CListWnd__SetColumnJustification                           0x6FC3B0
#define CListWnd__SetColumnWidth                                   0x6FC220
#define CListWnd__SetCurSel                                        0x6FBC30
#define CListWnd__SetItemColor                                     0x6FFEA0
#define CListWnd__SetItemData                                      0x6FC5E0
#define CListWnd__SetItemText                                      0x6FFE20
#define CListWnd__ShiftColumnSeparator                             0x6FE140
#define CListWnd__Sort                                             0x700D50
#define CListWnd__ToggleSel                                        0x6FC4B0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x618940

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x629A20
#define CMerchantWnd__RequestBuyItem                               0x62BAF0
#define CMerchantWnd__RequestSellItem                              0x62BF10
#define CMerchantWnd__SelectBuySellSlot                            0x62AF10

// CObfuscator
#define CObfuscator__doit                                          0x6B2FB0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x718E90
#define CSidlManager__CreateLabel                                  0x65E2A0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x58FBC0
#define CSidlScreenWnd__CalculateVSBRange                          0x58FAE0
#define CSidlScreenWnd__ConvertToRes                               0x729F60
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7097C0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x70A8B0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x70A960
#define CSidlScreenWnd__dCSidlScreenWnd                            0x70A070
#define CSidlScreenWnd__DrawSidlPiece                              0x709480
#define CSidlScreenWnd__EnableIniStorage                           0x7090C0
#define CSidlScreenWnd__GetSidlPiece                               0x709690
#define CSidlScreenWnd__Init1                                      0x70A710
#define CSidlScreenWnd__LoadIniInfo                                0x709870
#define CSidlScreenWnd__LoadIniListWnd                             0x709210
#define CSidlScreenWnd__LoadSidlScreen                             0x70A2C0
#define CSidlScreenWnd__StoreIniInfo                               0x708CC0
#define CSidlScreenWnd__StoreIniVis                                0x709050
#define CSidlScreenWnd__WndNotification                            0x70A490
#define CSidlScreenWnd__GetChildItem                               0x709120

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x5438F0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x72B4B0
#define CSliderWnd__SetValue                                       0x72B5B0
#define CSliderWnd__SetNumTicks                                    0x72BB60

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6630A0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x728160
#define CStmlWnd__CalculateHSBRange                                0x71F930
#define CStmlWnd__CalculateVSBRange                                0x71F8A0
#define CStmlWnd__CanBreakAtCharacter                              0x71FA90
#define CStmlWnd__FastForwardToEndOfTag                            0x720770
#define CStmlWnd__ForceParseNow                                    0x728660
#define CStmlWnd__GetNextTagPiece                                  0x720690
#define CStmlWnd__GetSTMLText                                      0x5B79C0
#define CStmlWnd__GetThisChar                                      0x74F4A0
#define CStmlWnd__GetVisiableText                                  0x721B90
#define CStmlWnd__InitializeWindowVariables                        0x7240F0
#define CStmlWnd__MakeStmlColorTag                                 0x71E7C0
#define CStmlWnd__MakeWndNotificationTag                           0x71E860
#define CStmlWnd__SetSTMLText                                      0x724210
#define CStmlWnd__StripFirstSTMLLines                              0x727E10
#define CStmlWnd__UpdateHistoryString                              0x722420

// CTabWnd 
#define CTabWnd__Draw                                              0x72C970
#define CTabWnd__DrawCurrentPage                                   0x72C310
#define CTabWnd__DrawTab                                           0x72C0F0
#define CTabWnd__GetCurrentPage                                    0x72C610
#define CTabWnd__GetPageClientRect                                 0x72BDC0
#define CTabWnd__GetPageFromTabIndex                               0x72C020
#define CTabWnd__GetPageInnerRect                                  0x72BE20
#define CTabWnd__GetTabInnerRect                                   0x72BFA0
#define CTabWnd__GetTabRect                                        0x72BEB0
#define CTabWnd__InsertPage                                        0x72CC00
#define CTabWnd__SetPage                                           0x72C650
#define CTabWnd__SetPageRect                                       0x72C8A0
#define CTabWnd__UpdatePage                                        0x72CB80

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417E80

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x70ACE0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x72D800

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6FACA0

// CXRect 
#define CXRect__CenterPoint                                        0x5931E0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x416090
#define CXStr__CXStr1                                              0x6F4910
#define CXStr__CXStr3                                              0x6EC640
#define CXStr__dCXStr                                              0x4596A0
#define CXStr__operator_equal1                                     0x6EC800
#define CXStr__operator_plus_equal1                                0x6ED840

// CXWnd 
#define CXWnd__BringToTop                                          0x701320
#define CXWnd__Center                                              0x706150
#define CXWnd__ClrFocus                                            0x701150
#define CXWnd__DoAllDrawing                                        0x706AD0
#define CXWnd__DrawChildren                                        0x706C20
#define CXWnd__DrawColoredRect                                     0x701600
#define CXWnd__DrawTooltip                                         0x706080
#define CXWnd__DrawTooltipAtPoint                                  0x7053E0
#define CXWnd__GetBorderFrame                                      0x701AB0
#define CXWnd__GetChildWndAt                                       0x704850
#define CXWnd__GetClientClipRect                                   0x7018C0
#define CXWnd__GetScreenClipRect                                   0x705840
#define CXWnd__GetScreenRect                                       0x701BD0
#define CXWnd__GetTooltipRect                                      0x701710
#define CXWnd__GetWindowTextA                                      0x581240
#define CXWnd__IsActive                                            0x70BE10
#define CXWnd__IsDescendantOf                                      0x7019A0
#define CXWnd__IsReallyVisible                                     0x704830
#define CXWnd__IsType                                              0x730670
#define CXWnd__Move                                                0x703F80
#define CXWnd__Move1                                               0x705DE0
#define CXWnd__ProcessTransition                                   0x7012D0
#define CXWnd__Refade                                              0x701250
#define CXWnd__Resize                                              0x701CA0
#define CXWnd__Right                                               0x705780
#define CXWnd__SetFocus                                            0x703390
#define CXWnd__SetKeyTooltip                                       0x701E90
#define CXWnd__SetMouseOver                                        0x705B30
#define CXWnd__StartFade                                           0x701350
#define CXWnd__GetChildItem                                        0x705AA0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x70D370
#define CXWndManager__DrawWindows                                  0x70CFF0
#define CXWndManager__GetKeyboardFlags                             0x70BA70
#define CXWndManager__HandleKeyboardMsg                            0x70C0E0
#define CXWndManager__RemoveWnd                                    0x70BF30

// CDBStr
#define CDBStr__GetString                                          0x463D40

// EQ_Character 
#define EQ_Character__CastRay                                      0x75B830
#define EQ_Character__CastSpell                                    0x42E400
#define EQ_Character__Cur_HP                                       0x4375B0
#define EQ_Character__GetAACastingTimeModifier                     0x4243C0
#define EQ_Character__GetCharInfo2                                 0x6CA1B0
#define EQ_Character__GetFocusCastingTimeModifier                  0x41FC60
#define EQ_Character__GetFocusRangeModifier                        0x41FDA0
#define EQ_Character__Max_Endurance                                0x5244A0
#define EQ_Character__Max_HP                                       0x432580
#define EQ_Character__Max_Mana                                     0x5242D0
#define EQ_Character__doCombatAbility                              0x5231E0
#define EQ_Character__UseSkill                                     0x441FB0
#define EQ_Character__GetConLevel                                  0x51F3C0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x509F50
#define EQ_Item__GetItemLinkHash                                   0x6BCB20
#define EQ_Item__IsStackable                                       0x6B3950

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x47C9F0
#define EQ_LoadingS__Array                                         0x8B2D88

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x527340
#define EQ_PC__GetAltAbilityIndex                                  0x6C1E10
#define EQ_PC__GetCombatAbility                                    0x6C1EA0
#define EQ_PC__GetCombatAbilityTimer                               0x6C1F50
#define EQ_PC__GetItemTimerValue                                   0x522110
#define EQ_PC__HasLoreItem                                         0x5257F0

// EQItemList 
#define EQItemList__EQItemList                                     0x4A8060
#define EQItemList__add_item                                       0x4A8110
#define EQItemList__delete_item                                    0x4A8370
#define EQItemList__FreeItemList                                   0x4A8130

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x4636F0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x52BF10
#define EQPlayer__dEQPlayer                                        0x5308C0
#define EQPlayer__DoAttack                                         0x53FA30
#define EQPlayer__EQPlayer                                         0x5357A0
#define EQPlayer__SetNameSpriteState                               0x52E310
#define EQPlayer__SetNameSpriteTint                                0x52BF80
#define EQPlayer__IsBodyType_j                                     0x75B140
#define EQPlayer__IsTargetable                                     0x75B2D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x536A30
#define EQPlayerManager__GetSpawnByName                            0x536D10

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x50BC00
#define KeypressHandler__AttachKeyToEqCommand                      0x50BC40
#define KeypressHandler__ClearCommandStateArray                    0x50BA10
#define KeypressHandler__HandleKeyDown                             0x50A590
#define KeypressHandler__HandleKeyUp                               0x50A8A0
#define KeypressHandler__SaveKeymapping                            0x50BAE0

// MapViewMap 
#define MapViewMap__Clear                                          0x613FE0
#define MapViewMap__SaveEx                                         0x6149B0

#define PlayerPointManager__GetAltCurrency                         0x6E2590

// StringTable 
#define StringTable__getString                                     0x6B3230
