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
#define __ExpectedVersionDate                                     "Jul 13 2012"
#define __ExpectedVersionTime                                     "15:58:09"
#define __ActualVersionDate                                        0x90C610
#define __ActualVersionTime                                        0x90C61C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x5366A0
#define __MemChecker1                                              0x816080
#define __MemChecker2                                              0x5B8FC0
#define __MemChecker3                                              0x5B8F10
#define __MemChecker4                                              0x838970
#define __EncryptPad0                                              0x9E44F0
#define __EncryptPad1                                              0xA5CEA8
#define __EncryptPad2                                              0x9FC9A8
#define __EncryptPad3                                              0x9FC5A8
#define __EncryptPad4                                              0xA5E950
#define __AC1                                                      0x6F58E0
#define __AC2                                                      0x4F2385
#define __AC3                                                      0x504568
#define __AC4                                                      0x509EE4
#define __AC5                                                      0x516338
#define __AC6                                                      0x519C8B
#define __AC7                                                      0x511CBB
#define __AC1_Data                                                 0x8F1DDD
// Direct Input
#define DI8__Main                                                  0xCE34A0
#define DI8__Keyboard                                              0xCE34A4
#define DI8__Mouse                                                 0xCE34A8
#define __AltTimerReady                                            0xBAA881
#define __Attack                                                   0xCDF29E
#define __Autofire                                                 0xCDF29F
#define __BindList                                                 0x9CCB58
#define __Clicks                                                   0xC67D8C
#define __CommandList                                              0x9CE190
#define __CurrentMapLabel                                          0xDEF2E0
#define __CurrentSocial                                            0x9B8E30
#define __DoAbilityList                                            0xC9FC78
#define __do_loot                                                  0x4C5D10
#define __DrawHandler                                              0x144BF7C
#define __GroupCount                                               0xC58742
#define __Guilds                                                   0xC5ACD8
#define __gWorld                                                   0xC5AC04
#define __HotkeyPage                                               0xCC8854
#define __HWnd                                                     0xCE31F0
#define __InChatMode                                               0xC67CC4
#define __LastTell                                                 0xC69B90
#define __LMouseHeldTime                                           0xC67DF8
#define __Mouse                                                    0xCE34AC
#define __MouseLook                                                0xC67D5A
#define __MouseEventTime                                           0xCDF5BC
#define __NetStatusToggle                                          0xC67D5D
#define __PCNames                                                  0xC69214
#define __RangeAttackReady                                         0xC68EAC
#define __RMouseHeldTime                                           0xC67DF4
#define __RunWalkState                                             0xC67CC8
#define __ScreenMode                                               0xBA7BC8
#define __ScreenX                                                  0xC67C78
#define __ScreenY                                                  0xC67C7C
#define __ScreenXMax                                               0xC67C80
#define __ScreenYMax                                               0xC67C84
#define __ServerHost                                               0xC58684
#define __ServerName                                               0xC9FC38
#define __ShiftKeyDown                                             0xC68348
#define __ShowNames                                                0xC690B8
#define __Socials                                                  0xC9FD38


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xC645F0
#define instEQZoneInfo                                             0xC67F40
#define instKeypressHandler                                        0xCDF5B8
#define pinstActiveBanker                                          0xC5ACAC
#define pinstActiveCorpse                                          0xC5ACB0
#define pinstActiveGMaster                                         0xC5ACB4
#define pinstActiveMerchant                                        0xC5ACA8
#define pinstAltAdvManager                                         0xBA8B10
#define pinstAuraMgr                                               0xA77D50
#define pinstBandageTarget                                         0xC5AC94
#define pinstCamActor                                              0xBA8584
#define pinstCDBStr                                                0xBA7BA0
#define pinstCDisplay                                              0xC5ACBC
#define pinstCEverQuest                                            0xCE3628
#define pinstCharData                                              0xC5AC78
#define pinstCharSpawn                                             0xC5ACA0
#define pinstControlledMissile                                     0xC5AC74
#define pinstControlledPlayer                                      0xC5ACA0
#define pinstCSidlManager                                          0x144C4BC
#define pinstCXWndManager                                          0x144C4B4
#define instDynamicZone                                            0xC64048
#define pinstDZMember                                              0xC64158
#define pinstDZTimerInfo                                           0xC6415C
#define pinstEQItemList                                            0xC577F0
#define instEQMisc                                                 0xBA7B08
#define pinstEQSoundManager                                        0xBA8B80
#define instExpeditionLeader                                       0xC64092
#define instExpeditionName                                         0xC640D2
#define pinstGroup                                                 0xC5873E
#define pinstImeManager                                            0x144C4C0
#define pinstLocalPlayer                                           0xC5AC8C
#define pinstMercenaryData                                         0xCDFA38
#define pinstModelPlayer                                           0xC5ACB8
#define pinstPCData                                                0xC5AC78
#define pinstSkillMgr                                              0xCE0068
#define pinstSpawnManager                                          0xCDFCD8
#define pinstSpellManager                                          0xCE00A8
#define pinstSpellSets                                             0xCD85AC
#define pinstStringTable                                           0xC5AC20
#define pinstSwitchManager                                         0xC58350
#define pinstTarget                                                0xC5ACA4
#define pinstTargetObject                                          0xC5AC7C
#define pinstTargetSwitch                                          0xC5AC80
#define pinstTaskMember                                            0xBA7AD0
#define pinstTrackTarget                                           0xC5AC98
#define pinstTradeTarget                                           0xC5AC88
#define instTributeActive                                          0xBA7B2D
#define pinstViewActor                                             0xBA8580
#define pinstWorldData                                             0xC5AC5C


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0xA6ED90
#define pinstCAudioTriggersWindow                                  0xA6ED28
#define pinstCCharacterSelect                                      0xBA8438
#define pinstCFacePick                                             0xBA83E8
#define pinstCNoteWnd                                              0xBA83F0
#define pinstCBookWnd                                              0xBA83F8
#define pinstCPetInfoWnd                                           0xBA83FC
#define pinstCTrainWnd                                             0xBA8400
#define pinstCSkillsWnd                                            0xBA8404
#define pinstCSkillsSelectWnd                                      0xBA8408
#define pinstCCombatSkillSelectWnd                                 0xBA840C
#define pinstCFriendsWnd                                           0xBA8410
#define pinstCAuraWnd                                              0xBA8414
#define pinstCRespawnWnd                                           0xBA8418
#define pinstCBandolierWnd                                         0xBA841C
#define pinstCPotionBeltWnd                                        0xBA8420
#define pinstCAAWnd                                                0xBA8424
#define pinstCGroupSearchFiltersWnd                                0xBA8428
#define pinstCLoadskinWnd                                          0xBA842C
#define pinstCAlarmWnd                                             0xBA8430
#define pinstCMusicPlayerWnd                                       0xBA8434
#define pinstCMailWnd                                              0xBA843C
#define pinstCMailCompositionWnd                                   0xBA8440
#define pinstCMailAddressBookWnd                                   0xBA8444
#define pinstCRaidWnd                                              0xBA844C
#define pinstCRaidOptionsWnd                                       0xBA8450
#define pinstCBreathWnd                                            0xBA8454
#define pinstCMapViewWnd                                           0xBA8458
#define pinstCMapToolbarWnd                                        0xBA845C
#define pinstCEditLabelWnd                                         0xBA8460
#define pinstCTargetWnd                                            0xBA8464
#define pinstCColorPickerWnd                                       0xBA8468
#define pinstCPlayerWnd                                            0xBA846C
#define pinstCOptionsWnd                                           0xBA8470
#define pinstCBuffWindowNORMAL                                     0xBA8474
#define pinstCBuffWindowSHORT                                      0xBA8478
#define pinstCharacterCreation                                     0xBA847C
#define pinstCCursorAttachment                                     0xBA8480
#define pinstCCastingWnd                                           0xBA8484
#define pinstCCastSpellWnd                                         0xBA8488
#define pinstCSpellBookWnd                                         0xBA848C
#define pinstCInventoryWnd                                         0xBA8490
#define pinstCBankWnd                                              0xBA8494
#define pinstCQuantityWnd                                          0xBA8498
#define pinstCLootWnd                                              0xBA849C
#define pinstCActionsWnd                                           0xBA84A0
#define pinstCCombatAbilityWnd                                     0xBA84A4
#define pinstCMerchantWnd                                          0xBA84A8
#define pinstCTradeWnd                                             0xBA84AC
#define pinstCSelectorWnd                                          0xBA84B0
#define pinstCBazaarWnd                                            0xBA84B4
#define pinstCBazaarSearchWnd                                      0xBA84B8
#define pinstCGiveWnd                                              0xBA84D4
#define pinstCTrackingWnd                                          0xBA84DC
#define pinstCInspectWnd                                           0xBA84E0
#define pinstCSocialEditWnd                                        0xBA84E4
#define pinstCFeedbackWnd                                          0xBA84E8
#define pinstCBugReportWnd                                         0xBA84EC
#define pinstCVideoModesWnd                                        0xBA84F0
#define pinstCTextEntryWnd                                         0xBA84F8
#define pinstCFileSelectionWnd                                     0xBA84FC
#define pinstCCompassWnd                                           0xBA8500
#define pinstCPlayerNotesWnd                                       0xBA8504
#define pinstCGemsGameWnd                                          0xBA8508
#define pinstCTimeLeftWnd                                          0xBA850C
#define pinstCPetitionQWnd                                         0xBA8520
#define pinstCSoulmarkWnd                                          0xBA8524
#define pinstCStoryWnd                                             0xBA8528
#define pinstCJournalTextWnd                                       0xBA852C
#define pinstCJournalCatWnd                                        0xBA8530
#define pinstCBodyTintWnd                                          0xBA8534
#define pinstCServerListWnd                                        0xBA8538
#define pinstCAvaZoneWnd                                           0xBA8540
#define pinstCBlockedBuffWnd                                       0xBA8544
#define pinstCBlockedPetBuffWnd                                    0xBA8548
#define pinstCInvSlotMgr                                           0xBA8578
#define pinstCContainerMgr                                         0xBA857C
#define pinstCAdventureLeaderboardWnd                              0xDEBE18
#define pinstCAdventureRequestWnd                                  0xDEBDE0
#define pinstCAltStorageWnd                                        0xDEBF20
#define pinstCAdventureStatsWnd                                    0xDEBE18
#define pinstCBarterMerchantWnd                                    0xDEC378
#define pinstCBarterSearchWnd                                      0xDEC3B0
#define pinstCBarterWnd                                            0xDEC3E8
#define pinstCChatManager                                          0xDEC7E0
#define pinstCDynamicZoneWnd                                       0xDEC9D0
#define pinstCEQMainWnd                                            0xDECA90
#define pinstCFellowshipWnd                                        0xDEC9C4
#define pinstCFindLocationWnd                                      0xDECBC0
#define pinstCGroupSearchWnd                                       0xDECD20
#define pinstCGroupWnd                                             0xDECD58
#define pinstCGuildBankWnd                                         0xDECD90
#define pinstCGuildMgmtWnd                                         0xDEEE00
#define pinstCGuildTributeMasterWnd                                0xDF0A28
#define pinstCHotButtonWnd                                         0xDEEE54
#define pinstCHotButtonWnd1                                        0xDEEE54
#define pinstCHotButtonWnd2                                        0xDEEE58
#define pinstCHotButtonWnd3                                        0xDEEE5C
#define pinstCHotButtonWnd4                                        0xDEEE9C
#define pinstCItemDisplayManager                                   0xDEEFD0
#define pinstCItemExpTransferWnd                                   0xDEF00C
#define pinstCLeadershipWnd                                        0xDEF138
#define pinstCLFGuildWnd                                           0xDEF170
#define pinstCMIZoneSelectWnd                                      0xDEF410
#define pinstCAdventureMerchantWnd                                 0xDEF6C0
#define pinstCConfirmationDialog                                   0xDEF6F8
#define pinstCPopupWndManager                                      0xDEF6F8
#define pinstCProgressionSelectionWnd                              0xDEF760
#define pinstCPvPLeaderboardWnd                                    0xDEF798
#define pinstCPvPStatsWnd                                          0xDEF7D0
#define pinstCSystemInfoDialogBox                                  0xDEFAB8
#define pinstCTargetOfTargetWnd                                    0xDF06D8
#define pinstCTaskSelectWnd                                        0xDEF974
#define pinstCTaskTemplateSelectWnd                                0xDF0778
#define pinstCTaskWnd                                              0xDF07B0
#define pinstCTipWndOFDAY                                          0xDF08A8
#define pinstCTipWndCONTEXT                                        0xDF08AC
#define pinstCTitleWnd                                             0xDF08E0
#define pinstCTradeskillWnd                                        0xDF0958
#define pinstCTributeBenefitWnd                                    0xDF09F0
#define pinstCTributeMasterWnd                                     0xDF0A28
#define pinstCContextMenuManager                                   0x144C518
#define pinstCVoiceMacroWnd                                        0xCE03F0
#define pinstCHtmlWnd                                              0xCE0468


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4DA4D0
#define __ConvertItemTags                                          0x4CB430
#define __ExecuteCmd                                               0x4B6F50
#define __EQGetTime                                                0x8174B0
#define __get_melee_range                                          0x4BD1F0
#define __GetGaugeValueFromEQ                                      0x6F4690
#define __GetLabelFromEQ                                           0x6F5880
#define __GetXTargetType                                           0x773280
#define __LoadFrontEnd                                             0x5B7F30
#define __NewUIINI                                                 0x6F4240
#define __ProcessGameEvents                                        0x5124A0
#define CrashDetected                                              0x5BA940
#define DrawNetStatus                                              0x544080
#define Util__FastTime                                             0x816910
#define Expansion_HoT                                              0xC69018
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x489A00
#define AltAdvManager__IsAbilityReady                              0x489AB0
#define AltAdvManager__GetAltAbility                               0x489D50

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x43CD80

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5DF1F0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5E92B0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x524930

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x602620
#define CChatManager__InitContextMenu                              0x602F50

// CChatService
#define CChatService__GetNumberOfFriends                           0x769D00
#define CChatService__GetFriendName                                0x769D10

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x607D10
#define CChatWindow__Clear                                         0x6078C0
#define CChatWindow__WndNotification                               0x608120

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x7C5D70
#define CComboWnd__Draw                                            0x7C5F30
#define CComboWnd__GetCurChoice                                    0x7C5B90
#define CComboWnd__GetListRect                                     0x7C6210
#define CComboWnd__GetTextRect                                     0x7C5DA0
#define CComboWnd__InsertChoice                                    0x7C6280
#define CComboWnd__SetColors                                       0x7C5B20
#define CComboWnd__SetChoice                                       0x7C5B50

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x611520
#define CContainerWnd__vftable                                     0x915040

// CDisplay 
#define CDisplay__CleanGameUI                                      0x47D2D0
#define CDisplay__GetClickedActor                                  0x475D60
#define CDisplay__GetUserDefinedColor                              0x474690
#define CDisplay__GetWorldFilePath                                 0x473BB0
#define CDisplay__is3dON                                           0x472CB0
#define CDisplay__ReloadUI                                         0x486900
#define CDisplay__WriteTextHD2                                     0x478D90

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5D6E20
#define CEditBaseWnd__SetSel                                       0x7E66D0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7CF410
#define CEditWnd__GetCharIndexPt                                   0x7D03E0
#define CEditWnd__GetDisplayString                                 0x7CF5B0
#define CEditWnd__GetHorzOffset                                    0x7CF840
#define CEditWnd__GetLineForPrintableChar                          0x7CFE90
#define CEditWnd__GetSelStartPt                                    0x7D0620
#define CEditWnd__GetSTMLSafeText                                  0x7CF9E0
#define CEditWnd__PointFromPrintableChar                           0x7CFFA0
#define CEditWnd__SelectableCharFromPoint                          0x7D0120
#define CEditWnd__SetEditable                                      0x7CF9B0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4F2AD0
#define CEverQuest__DropHeldItemOnGround                           0x4FFA20
#define CEverQuest__dsp_chat                                       0x4F8DC0
#define CEverQuest__DoTellWindow                                   0x4F7500
#define CEverQuest__EnterZone                                      0x509E70
#define CEverQuest__GetBodyTypeDesc                                0x4EF8D0
#define CEverQuest__GetClassDesc                                   0x4EF110
#define CEverQuest__GetClassThreeLetterCode                        0x4EF710
#define CEverQuest__GetDeityDesc                                   0x4EFF80
#define CEverQuest__GetLangDesc                                    0x4EFC60
#define CEverQuest__GetRaceDesc                                    0x4EFF50
#define CEverQuest__InterpretCmd                                   0x4F98D0
#define CEverQuest__LeftClickedOnPlayer                            0x50BF40
#define CEverQuest__LMouseUp                                       0x50FB40
#define CEverQuest__RightClickedOnPlayer                           0x510CA0
#define CEverQuest__RMouseUp                                       0x511C80
#define CEverQuest__SetGameState                                   0x4F2F60
#define CEverQuest__Emote                                          0x4F8FE0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x61F540
#define CGaugeWnd__CalcLinesFillRect                               0x61F5A0
#define CGaugeWnd__Draw                                            0x61F9F0

// CGuild
#define CGuild__FindMemberByName                                   0x41CC80

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x639A30

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x643E10
#define CInvSlotMgr__MoveItem                                      0x644AC0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x643490
#define CInvSlot__SliderComplete                                   0x641780
#define CInvSlot__GetItemBase                                      0x640E10

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x645810

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6F1C50
#define CItemDisplayWnd__UpdateStrings                             0x646850

// CLabel 
#define CLabel__Draw                                               0x65AFC0

// CListWnd 
#define CListWnd__AddColumn                                        0x7BB880
#define CListWnd__AddColumn1                                       0x7BAF00
#define CListWnd__AddLine                                          0x7BAA60
#define CListWnd__AddString                                        0x7BAC00
#define CListWnd__CalculateFirstVisibleLine                        0x7B6CD0
#define CListWnd__CalculateVSBRange                                0x7B90D0
#define CListWnd__ClearAllSel                                      0x7B6220
#define CListWnd__CloseAndUpdateEditWindow                         0x7BA0D0
#define CListWnd__Compare                                          0x7B7770
#define CListWnd__Draw                                             0x7B8D10
#define CListWnd__DrawColumnSeparators                             0x7B8BA0
#define CListWnd__DrawHeader                                       0x7B64B0
#define CListWnd__DrawItem                                         0x7B8170
#define CListWnd__DrawLine                                         0x7B8860
#define CListWnd__DrawSeparator                                    0x7B8C40
#define CListWnd__EnsureVisible                                    0x7B6E30
#define CListWnd__ExtendSel                                        0x7B8090
#define CListWnd__GetColumnMinWidth                                0x7B5EF0
#define CListWnd__GetColumnWidth                                   0x7B5E30
#define CListWnd__GetCurSel                                        0x7B55F0
#define CListWnd__GetHeaderRect                                    0x7B5750
#define CListWnd__GetItemAtPoint                                   0x7B7100
#define CListWnd__GetItemAtPoint1                                  0x7B7170
#define CListWnd__GetItemData                                      0x7B5A30
#define CListWnd__GetItemHeight                                    0x7B6940
#define CListWnd__GetItemIcon                                      0x7B5C10
#define CListWnd__GetItemRect                                      0x7B6F00
#define CListWnd__GetItemText                                      0x7B5AC0
#define CListWnd__GetSelList                                       0x7BADE0
#define CListWnd__GetSeparatorRect                                 0x7B76C0
#define CListWnd__RemoveLine                                       0x7BAD90
#define CListWnd__SetColors                                        0x7B56C0
#define CListWnd__SetColumnJustification                           0x7B6090
#define CListWnd__SetColumnWidth                                   0x7B5EB0
#define CListWnd__SetCurSel                                        0x7B5630
#define CListWnd__SetItemColor                                     0x7B9D80
#define CListWnd__SetItemData                                      0x7B62C0
#define CListWnd__SetItemText                                      0x7B9BB0
#define CListWnd__ShiftColumnSeparator                             0x7B9A20
#define CListWnd__Sort                                             0x7BBFE0
#define CListWnd__ToggleSel                                        0x7B6190

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x673A40

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x68EE70
#define CMerchantWnd__RequestBuyItem                               0x6950A0
#define CMerchantWnd__RequestSellItem                              0x6B6750
#define CMerchantWnd__SelectBuySellSlot                            0x68F120

// CObfuscator
#define CObfuscator__doit                                          0x73D3B0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7D7E90
#define CSidlManager__CreateLabel                                  0x6EA350

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5DAEB0
#define CSidlScreenWnd__CalculateVSBRange                          0x5DADD0
#define CSidlScreenWnd__ConvertToRes                               0x7E65B0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7C83C0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7C9600
#define CSidlScreenWnd__CSidlScreenWnd2                            0x7C96B0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x7C8D90
#define CSidlScreenWnd__DrawSidlPiece                              0x7C7E60
#define CSidlScreenWnd__EnableIniStorage                           0x7C7620
#define CSidlScreenWnd__GetSidlPiece                               0x7C8080
#define CSidlScreenWnd__Init1                                      0x7C9450
#define CSidlScreenWnd__LoadIniInfo                                0x7C8480
#define CSidlScreenWnd__LoadIniListWnd                             0x7C7770
#define CSidlScreenWnd__LoadSidlScreen                             0x7C8FF0
#define CSidlScreenWnd__StoreIniInfo                               0x7C71F0
#define CSidlScreenWnd__StoreIniVis                                0x7C75B0
#define CSidlScreenWnd__WndNotification                            0x7C9240
#define CSidlScreenWnd__GetChildItem                               0x7C7680

// CSkillMgr
#define CSkillMgr__IsAvailable                                     0x581F20
#define CSkillMgr__GetSkillCap                                     0x581F90

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7EE770
#define CSliderWnd__SetValue                                       0x7EE870
#define CSliderWnd__SetNumTicks                                    0x7EEE20

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6EF8F0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7E3B50
#define CStmlWnd__CalculateHSBRange                                0x7DB0A0
#define CStmlWnd__CalculateVSBRange                                0x7DB130
#define CStmlWnd__CanBreakAtCharacter                              0x7DB2A0
#define CStmlWnd__FastForwardToEndOfTag                            0x7DC000
#define CStmlWnd__ForceParseNow                                    0x7E4140
#define CStmlWnd__GetNextTagPiece                                  0x7DBF20
#define CStmlWnd__GetSTMLText                                      0x607160
#define CStmlWnd__GetThisChar                                      0x80F1C0
#define CStmlWnd__GetVisiableText                                  0x7DD460
#define CStmlWnd__InitializeWindowVariables                        0x7DFA50
#define CStmlWnd__MakeStmlColorTag                                 0x7D9FA0
#define CStmlWnd__MakeWndNotificationTag                           0x7DA040
#define CStmlWnd__SetSTMLText                                      0x7DFB80
#define CStmlWnd__StripFirstSTMLLines                              0x7E37F0
#define CStmlWnd__UpdateHistoryString                              0x7DDD00

// CTabWnd 
#define CTabWnd__Draw                                              0x7EA370
#define CTabWnd__DrawCurrentPage                                   0x7E9BC0
#define CTabWnd__DrawTab                                           0x7E9990
#define CTabWnd__GetCurrentPage                                    0x7E9FB0
#define CTabWnd__GetPageClientRect                                 0x7E9640
#define CTabWnd__GetPageFromTabIndex                               0x7E98C0
#define CTabWnd__GetPageInnerRect                                  0x7E96A0
#define CTabWnd__GetTabInnerRect                                   0x7E9840
#define CTabWnd__GetTabRect                                        0x7E9730
#define CTabWnd__InsertPage                                        0x7EA600
#define CTabWnd__SetPage                                           0x7E9FF0
#define CTabWnd__SetPageRect                                       0x7EA2A0
#define CTabWnd__UpdatePage                                        0x7EA580

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4191E0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x7C9A30

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7E77F0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x7B44B0

// CXRect 
#define CXRect__CenterPoint                                        0x523A50

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x417440
#define CXStr__CXStr1                                              0x7AF3C0
#define CXStr__CXStr3                                              0x8137E0
#define CXStr__dCXStr                                              0x7DB540
#define CXStr__operator_equal                                      0x813950
#define CXStr__operator_equal1                                     0x8139A0
#define CXStr__operator_plus_equal1                                0x814AB0

// CXWnd 
#define CXWnd__BringToTop                                          0x7BED40
#define CXWnd__Center                                              0x7C46F0
#define CXWnd__ClrFocus                                            0x7BEB80
#define CXWnd__DoAllDrawing                                        0x7C4580
#define CXWnd__DrawChildren                                        0x7C46C0
#define CXWnd__DrawColoredRect                                     0x7BF060
#define CXWnd__DrawTooltip                                         0x7BF250
#define CXWnd__DrawTooltipAtPoint                                  0x7C37F0
#define CXWnd__GetBorderFrame                                      0x7BF670
#define CXWnd__GetChildWndAt                                       0x7C29E0
#define CXWnd__GetClientClipRect                                   0x7BF3F0
#define CXWnd__GetScreenClipRect                                   0x7C3D20
#define CXWnd__GetScreenRect                                       0x7BF7A0
#define CXWnd__GetTooltipRect                                      0x7BF170
#define CXWnd__GetWindowTextA                                      0x5235D0
#define CXWnd__IsActive                                            0x7CAB70
#define CXWnd__IsDescendantOf                                      0x7BF560
#define CXWnd__IsReallyVisible                                     0x7C29C0
#define CXWnd__IsType                                              0x7EBC40
#define CXWnd__Move                                                0x7C2130
#define CXWnd__Move1                                               0x7C4250
#define CXWnd__ProcessTransition                                   0x7BECF0
#define CXWnd__Refade                                              0x7BEC80
#define CXWnd__Resize                                              0x7BF870
#define CXWnd__Right                                               0x7C3C30
#define CXWnd__SetFocus                                            0x7C12A0
#define CXWnd__SetKeyTooltip                                       0x7BFAC0
#define CXWnd__SetMouseOver                                        0x7C4040
#define CXWnd__StartFade                                           0x7BED80
#define CXWnd__GetChildItem                                        0x7C3F80

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x7CC0D0
#define CXWndManager__DrawWindows                                  0x7CBD50
#define CXWndManager__GetKeyboardFlags                             0x7CA7C0
#define CXWndManager__HandleKeyboardMsg                            0x7CAE40
#define CXWndManager__RemoveWnd                                    0x7CAC90

// CDBStr
#define CDBStr__GetString                                          0x4712F0

// EQ_Character 
#define EQ_Character__CastRay                                      0x756E30
#define EQ_Character__CastSpell                                    0x433090
#define EQ_Character__Cur_HP                                       0x43CA20
#define EQ_Character__GetAACastingTimeModifier                     0x427C70
#define EQ_Character__GetCharInfo2                                 0x755230
#define EQ_Character__GetFocusCastingTimeModifier                  0x4229C0
#define EQ_Character__GetFocusRangeModifier                        0x422B90
#define EQ_Character__Max_Endurance                                0x54F620
#define EQ_Character__Max_HP                                       0x4370D0
#define EQ_Character__Max_Mana                                     0x54F420
#define EQ_Character__doCombatAbility                              0x54E210
#define EQ_Character__UseSkill                                     0x44C740
#define EQ_Character__GetConLevel                                  0x547750
#define EQ_Character__IsExpansionFlag                              0x40DCF0
#define EQ_Character__TotalEffect                                  0x42C4F0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x5290A0
#define EQ_Item__CreateItemTagString                               0x73B4D0
#define EQ_Item__IsStackable                                       0x72FE00

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x48B040
#define EQ_LoadingS__Array                                         0x9C78D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x552EF0
#define EQ_PC__GetAltAbilityIndex                                  0x7466E0
#define EQ_PC__GetCombatAbility                                    0x746770
#define EQ_PC__GetCombatAbilityTimer                               0x746820
#define EQ_PC__GetItemTimerValue                                   0x54DF80
#define EQ_PC__HasLoreItem                                         0x54CA60

// EQItemList 
#define EQItemList__EQItemList                                     0x4BB560
#define EQItemList__add_item                                       0x4BB4F0
#define EQItemList__delete_item                                    0x4BB910
#define EQItemList__FreeItemList                                   0x4BB840

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x4708C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x557FD0
#define EQPlayer__dEQPlayer                                        0x55CBE0
#define EQPlayer__DoAttack                                         0x56E2B0
#define EQPlayer__EQPlayer                                         0x562680
#define EQPlayer__SetNameSpriteState                               0x55A4F0
#define EQPlayer__SetNameSpriteTint                                0x558040
#define EQPlayer__IsBodyType_j                                     0x7566D0
#define EQPlayer__IsTargetable                                     0x7569A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x563A40
#define EQPlayerManager__GetSpawnByName                            0x563CD0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x52EAD0
#define KeypressHandler__AttachKeyToEqCommand                      0x52EB10
#define KeypressHandler__ClearCommandStateArray                    0x52E8E0
#define KeypressHandler__HandleKeyDown                             0x52D280
#define KeypressHandler__HandleKeyUp                               0x52D590
#define KeypressHandler__SaveKeymapping                            0x52E9B0

// MapViewMap 
#define MapViewMap__Clear                                          0x66CC90
#define MapViewMap__SaveEx                                         0x670340

#define PlayerPointManager__GetAltCurrency                         0x740E10

// StringTable 
#define StringTable__getString                                     0x73D630

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x5517B0
