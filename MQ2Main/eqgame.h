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
#define __ExpectedVersionDate                                     "Aug  2 2012"
#define __ExpectedVersionTime                                     "15:17:11"
#define __ActualVersionDate                                        0x90C620
#define __ActualVersionTime                                        0x90C62C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x5366A0
#define __MemChecker1                                              0x8160E0
#define __MemChecker2                                              0x5B8FD0
#define __MemChecker3                                              0x5B8F20
#define __MemChecker4                                              0x8389D0
#define __EncryptPad0                                              0x9E44F0
#define __EncryptPad1                                              0xA5CEA8
#define __EncryptPad2                                              0x9FC9A8
#define __EncryptPad3                                              0x9FC5A8
#define __EncryptPad4                                              0xA5E950
#define __AC1                                                      0x6F5900
#define __AC2                                                      0x4F2385
#define __AC3                                                      0x504568
#define __AC4                                                      0x509EE4
#define __AC5                                                      0x516338
#define __AC6                                                      0x519C8B
#define __AC7                                                      0x511CBB
#define __AC1_Data                                                 0x8F1E3D
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
#define __EQGetTime                                                0x817510
#define __get_melee_range                                          0x4BD1F0
#define __GetGaugeValueFromEQ                                      0x6F46B0
#define __GetLabelFromEQ                                           0x6F58A0
#define __GetXTargetType                                           0x7732E0
#define __LoadFrontEnd                                             0x5B7F40
#define __NewUIINI                                                 0x6F4260
#define __ProcessGameEvents                                        0x5124A0
#define CrashDetected                                              0x5BA950
#define DrawNetStatus                                              0x544080
#define Util__FastTime                                             0x816970
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
#define CBankWnd__GetNumBankSlots                                  0x5DF200

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5E92C0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x524930

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x602630
#define CChatManager__InitContextMenu                              0x602F60

// CChatService
#define CChatService__GetNumberOfFriends                           0x769D60
#define CChatService__GetFriendName                                0x769D70

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x607D20
#define CChatWindow__Clear                                         0x6078D0
#define CChatWindow__WndNotification                               0x608130

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x7C5DD0
#define CComboWnd__Draw                                            0x7C5F90
#define CComboWnd__GetCurChoice                                    0x7C5BF0
#define CComboWnd__GetListRect                                     0x7C6270
#define CComboWnd__GetTextRect                                     0x7C5E00
#define CComboWnd__InsertChoice                                    0x7C62E0
#define CComboWnd__SetColors                                       0x7C5B80
#define CComboWnd__SetChoice                                       0x7C5BB0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x611530
#define CContainerWnd__vftable                                     0x915050

// CDisplay 
#define CDisplay__CleanGameUI                                      0x47D2D0
#define CDisplay__GetClickedActor                                  0x475D60
#define CDisplay__GetUserDefinedColor                              0x474690
#define CDisplay__GetWorldFilePath                                 0x473BB0
#define CDisplay__is3dON                                           0x472CB0
#define CDisplay__ReloadUI                                         0x486900
#define CDisplay__WriteTextHD2                                     0x478D90

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5D6E30
#define CEditBaseWnd__SetSel                                       0x7E6730

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7CF470
#define CEditWnd__GetCharIndexPt                                   0x7D0440
#define CEditWnd__GetDisplayString                                 0x7CF610
#define CEditWnd__GetHorzOffset                                    0x7CF8A0
#define CEditWnd__GetLineForPrintableChar                          0x7CFEF0
#define CEditWnd__GetSelStartPt                                    0x7D0680
#define CEditWnd__GetSTMLSafeText                                  0x7CFA40
#define CEditWnd__PointFromPrintableChar                           0x7D0000
#define CEditWnd__SelectableCharFromPoint                          0x7D0180
#define CEditWnd__SetEditable                                      0x7CFA10

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
#define CGaugeWnd__CalcFillRect                                    0x61F550
#define CGaugeWnd__CalcLinesFillRect                               0x61F5B0
#define CGaugeWnd__Draw                                            0x61FA00

// CGuild
#define CGuild__FindMemberByName                                   0x41CC80

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x639A40

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x643E20
#define CInvSlotMgr__MoveItem                                      0x644AD0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x6434A0
#define CInvSlot__SliderComplete                                   0x641790
#define CInvSlot__GetItemBase                                      0x640E20

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x645820

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6F1C70
#define CItemDisplayWnd__UpdateStrings                             0x646860

// CLabel 
#define CLabel__Draw                                               0x65AFD0

// CListWnd 
#define CListWnd__AddColumn                                        0x7BB8E0
#define CListWnd__AddColumn1                                       0x7BAF60
#define CListWnd__AddLine                                          0x7BAAC0
#define CListWnd__AddString                                        0x7BAC60
#define CListWnd__CalculateFirstVisibleLine                        0x7B6D30
#define CListWnd__CalculateVSBRange                                0x7B9130
#define CListWnd__ClearAllSel                                      0x7B6280
#define CListWnd__CloseAndUpdateEditWindow                         0x7BA130
#define CListWnd__Compare                                          0x7B77D0
#define CListWnd__Draw                                             0x7B8D70
#define CListWnd__DrawColumnSeparators                             0x7B8C00
#define CListWnd__DrawHeader                                       0x7B6510
#define CListWnd__DrawItem                                         0x7B81D0
#define CListWnd__DrawLine                                         0x7B88C0
#define CListWnd__DrawSeparator                                    0x7B8CA0
#define CListWnd__EnsureVisible                                    0x7B6E90
#define CListWnd__ExtendSel                                        0x7B80F0
#define CListWnd__GetColumnMinWidth                                0x7B5F50
#define CListWnd__GetColumnWidth                                   0x7B5E90
#define CListWnd__GetCurSel                                        0x7B5650
#define CListWnd__GetHeaderRect                                    0x7B57B0
#define CListWnd__GetItemAtPoint                                   0x7B7160
#define CListWnd__GetItemAtPoint1                                  0x7B71D0
#define CListWnd__GetItemData                                      0x7B5A90
#define CListWnd__GetItemHeight                                    0x7B69A0
#define CListWnd__GetItemIcon                                      0x7B5C70
#define CListWnd__GetItemRect                                      0x7B6F60
#define CListWnd__GetItemText                                      0x7B5B20
#define CListWnd__GetSelList                                       0x7BAE40
#define CListWnd__GetSeparatorRect                                 0x7B7720
#define CListWnd__RemoveLine                                       0x7BADF0
#define CListWnd__SetColors                                        0x7B5720
#define CListWnd__SetColumnJustification                           0x7B60F0
#define CListWnd__SetColumnWidth                                   0x7B5F10
#define CListWnd__SetCurSel                                        0x7B5690
#define CListWnd__SetItemColor                                     0x7B9DE0
#define CListWnd__SetItemData                                      0x7B6320
#define CListWnd__SetItemText                                      0x7B9C10
#define CListWnd__ShiftColumnSeparator                             0x7B9A80
#define CListWnd__Sort                                             0x7BC040
#define CListWnd__ToggleSel                                        0x7B61F0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x673A50

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x68EE80
#define CMerchantWnd__RequestBuyItem                               0x6950B0
#define CMerchantWnd__RequestSellItem                              0x6B6770
#define CMerchantWnd__SelectBuySellSlot                            0x68F130

// CObfuscator
#define CObfuscator__doit                                          0x73D3D0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7D7EF0
#define CSidlManager__CreateLabel                                  0x6EA370

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5DAEC0
#define CSidlScreenWnd__CalculateVSBRange                          0x5DADE0
#define CSidlScreenWnd__ConvertToRes                               0x7E6610
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7C8420
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7C9660
#define CSidlScreenWnd__CSidlScreenWnd2                            0x7C9710
#define CSidlScreenWnd__dCSidlScreenWnd                            0x7C8DF0
#define CSidlScreenWnd__DrawSidlPiece                              0x7C7EC0
#define CSidlScreenWnd__EnableIniStorage                           0x7C7680
#define CSidlScreenWnd__GetSidlPiece                               0x7C80E0
#define CSidlScreenWnd__Init1                                      0x7C94B0
#define CSidlScreenWnd__LoadIniInfo                                0x7C84E0
#define CSidlScreenWnd__LoadIniListWnd                             0x7C77D0
#define CSidlScreenWnd__LoadSidlScreen                             0x7C9050
#define CSidlScreenWnd__StoreIniInfo                               0x7C7250
#define CSidlScreenWnd__StoreIniVis                                0x7C7610
#define CSidlScreenWnd__WndNotification                            0x7C92A0
#define CSidlScreenWnd__GetChildItem                               0x7C76E0

// CSkillMgr
#define CSkillMgr__IsAvailable                                     0x581F30
#define CSkillMgr__GetSkillCap                                     0x581FA0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7EE7D0
#define CSliderWnd__SetValue                                       0x7EE8D0
#define CSliderWnd__SetNumTicks                                    0x7EEE80

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6EF910

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7E3BB0
#define CStmlWnd__CalculateHSBRange                                0x7DB100
#define CStmlWnd__CalculateVSBRange                                0x7DB190
#define CStmlWnd__CanBreakAtCharacter                              0x7DB300
#define CStmlWnd__FastForwardToEndOfTag                            0x7DC060
#define CStmlWnd__ForceParseNow                                    0x7E41A0
#define CStmlWnd__GetNextTagPiece                                  0x7DBF80
#define CStmlWnd__GetSTMLText                                      0x607170
#define CStmlWnd__GetThisChar                                      0x80F220
#define CStmlWnd__GetVisiableText                                  0x7DD4C0
#define CStmlWnd__InitializeWindowVariables                        0x7DFAB0
#define CStmlWnd__MakeStmlColorTag                                 0x7DA000
#define CStmlWnd__MakeWndNotificationTag                           0x7DA0A0
#define CStmlWnd__SetSTMLText                                      0x7DFBE0
#define CStmlWnd__StripFirstSTMLLines                              0x7E3850
#define CStmlWnd__UpdateHistoryString                              0x7DDD60

// CTabWnd 
#define CTabWnd__Draw                                              0x7EA3D0
#define CTabWnd__DrawCurrentPage                                   0x7E9C20
#define CTabWnd__DrawTab                                           0x7E99F0
#define CTabWnd__GetCurrentPage                                    0x7EA010
#define CTabWnd__GetPageClientRect                                 0x7E96A0
#define CTabWnd__GetPageFromTabIndex                               0x7E9920
#define CTabWnd__GetPageInnerRect                                  0x7E9700
#define CTabWnd__GetTabInnerRect                                   0x7E98A0
#define CTabWnd__GetTabRect                                        0x7E9790
#define CTabWnd__InsertPage                                        0x7EA660
#define CTabWnd__SetPage                                           0x7EA050
#define CTabWnd__SetPageRect                                       0x7EA300
#define CTabWnd__UpdatePage                                        0x7EA5E0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4191E0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x7C9A90

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7E7850

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x7B4510

// CXRect 
#define CXRect__CenterPoint                                        0x523A50

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x417440
#define CXStr__CXStr1                                              0x7AF420
#define CXStr__CXStr3                                              0x813840
#define CXStr__dCXStr                                              0x7DB5A0
#define CXStr__operator_equal                                      0x8139B0
#define CXStr__operator_equal1                                     0x813A00
#define CXStr__operator_plus_equal1                                0x814B10

// CXWnd 
#define CXWnd__BringToTop                                          0x7BEDA0
#define CXWnd__Center                                              0x7C4750
#define CXWnd__ClrFocus                                            0x7BEBE0
#define CXWnd__DoAllDrawing                                        0x7C45E0
#define CXWnd__DrawChildren                                        0x7C4720
#define CXWnd__DrawColoredRect                                     0x7BF0C0
#define CXWnd__DrawTooltip                                         0x7BF2B0
#define CXWnd__DrawTooltipAtPoint                                  0x7C3850
#define CXWnd__GetBorderFrame                                      0x7BF6D0
#define CXWnd__GetChildWndAt                                       0x7C2A40
#define CXWnd__GetClientClipRect                                   0x7BF450
#define CXWnd__GetScreenClipRect                                   0x7C3D80
#define CXWnd__GetScreenRect                                       0x7BF800
#define CXWnd__GetTooltipRect                                      0x7BF1D0
#define CXWnd__GetWindowTextA                                      0x5235D0
#define CXWnd__IsActive                                            0x7CABD0
#define CXWnd__IsDescendantOf                                      0x7BF5C0
#define CXWnd__IsReallyVisible                                     0x7C2A20
#define CXWnd__IsType                                              0x7EBCA0
#define CXWnd__Move                                                0x7C2190
#define CXWnd__Move1                                               0x7C42B0
#define CXWnd__ProcessTransition                                   0x7BED50
#define CXWnd__Refade                                              0x7BECE0
#define CXWnd__Resize                                              0x7BF8D0
#define CXWnd__Right                                               0x7C3C90
#define CXWnd__SetFocus                                            0x7C1300
#define CXWnd__SetKeyTooltip                                       0x7BFB20
#define CXWnd__SetMouseOver                                        0x7C40A0
#define CXWnd__StartFade                                           0x7BEDE0
#define CXWnd__GetChildItem                                        0x7C3FE0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x7CC130
#define CXWndManager__DrawWindows                                  0x7CBDB0
#define CXWndManager__GetKeyboardFlags                             0x7CA820
#define CXWndManager__HandleKeyboardMsg                            0x7CAEA0
#define CXWndManager__RemoveWnd                                    0x7CACF0

// CDBStr
#define CDBStr__GetString                                          0x4712F0

// EQ_Character 
#define EQ_Character__CastRay                                      0x756E90
#define EQ_Character__CastSpell                                    0x433090
#define EQ_Character__Cur_HP                                       0x43CA20
#define EQ_Character__GetAACastingTimeModifier                     0x427C70
#define EQ_Character__GetCharInfo2                                 0x755290
#define EQ_Character__GetFocusCastingTimeModifier                  0x4229C0
#define EQ_Character__GetFocusRangeModifier                        0x422B90
#define EQ_Character__Max_Endurance                                0x54F630
#define EQ_Character__Max_HP                                       0x4370D0
#define EQ_Character__Max_Mana                                     0x54F430
#define EQ_Character__doCombatAbility                              0x54E220
#define EQ_Character__UseSkill                                     0x44C740
#define EQ_Character__GetConLevel                                  0x547750
#define EQ_Character__IsExpansionFlag                              0x40DCF0
#define EQ_Character__TotalEffect                                  0x42C4F0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x5290A0
#define EQ_Item__CreateItemTagString                               0x73B4F0
#define EQ_Item__IsStackable                                       0x72FE20

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x48B040
#define EQ_LoadingS__Array                                         0x9C78D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x552F00
#define EQ_PC__GetAltAbilityIndex                                  0x746740
#define EQ_PC__GetCombatAbility                                    0x7467D0
#define EQ_PC__GetCombatAbilityTimer                               0x746880
#define EQ_PC__GetItemTimerValue                                   0x54DF90
#define EQ_PC__HasLoreItem                                         0x54CA60

// EQItemList 
#define EQItemList__EQItemList                                     0x4BB560
#define EQItemList__add_item                                       0x4BB4F0
#define EQItemList__delete_item                                    0x4BB910
#define EQItemList__FreeItemList                                   0x4BB840

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x4708C0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x557FE0
#define EQPlayer__dEQPlayer                                        0x55CBF0
#define EQPlayer__DoAttack                                         0x56E2C0
#define EQPlayer__EQPlayer                                         0x562690
#define EQPlayer__SetNameSpriteState                               0x55A500
#define EQPlayer__SetNameSpriteTint                                0x558050
#define EQPlayer__IsBodyType_j                                     0x756730
#define EQPlayer__IsTargetable                                     0x756A00

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x563A50
#define EQPlayerManager__GetSpawnByName                            0x563CE0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x52EAD0
#define KeypressHandler__AttachKeyToEqCommand                      0x52EB10
#define KeypressHandler__ClearCommandStateArray                    0x52E8E0
#define KeypressHandler__HandleKeyDown                             0x52D280
#define KeypressHandler__HandleKeyUp                               0x52D590
#define KeypressHandler__SaveKeymapping                            0x52E9B0

// MapViewMap 
#define MapViewMap__Clear                                          0x66CCA0
#define MapViewMap__SaveEx                                         0x670350

#define PlayerPointManager__GetAltCurrency                         0x740E30

// StringTable 
#define StringTable__getString                                     0x73D650

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x5517C0
