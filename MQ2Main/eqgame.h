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
#define __ExpectedVersionDate                                     "Mar 15 2011"
#define __ExpectedVersionTime                                     "13:33:15"
#define __ActualVersionDate                                        0x8A5C5C
#define __ActualVersionTime                                        0x8A5C68

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x524990
#define __MemChecker1                                              0x7B74F0
#define __MemChecker2                                              0x59C800
#define __MemChecker3                                              0x59C750
#define __MemChecker4                                              0x7D9160
#define __EncryptPad0                                              0x9465F0
#define __EncryptPad1                                              0x9527D0
#define __EncryptPad2                                              0x949380
#define __EncryptPad3                                              0x948F80
#define __EncryptPad4                                              0x954278
#define __AC1                                                      0x6B6790
#define __AC2                                                      0x4E7535
#define __AC3                                                      0x4F9CA8
#define __AC4                                                      0x4FF328
#define __AC5                                                      0x50B54E
#define __AC6                                                      0x50ECBE
#define __AC7                                                      0x5070FB
#define __AC1_Data                                                 0x88C96D
// Direct Input
#define DI8__Main                                                  0xB98EA4
#define DI8__Keyboard                                              0xB98EA8
#define DI8__Mouse                                                 0xB98EAC
#define __AltTimerReady                                            0xB1D59A
#define __Attack                                                   0xB81086
#define __Autofire                                                 0xB81087
#define __BindList                                                 0x940BA0
#define __Clicks                                                   0xB1C248
#define __CommandList                                              0x941590
#define __CurrentMapLabel                                          0xBC4148
#define __CurrentSocial                                            0x93C9F0
#define __DoAbilityAvailable                                       0xB1D534
#define __DoAbilityList                                            0xB52FA4
#define __do_loot                                                  0x4BC5D0
#define __DrawHandler                                              0x1208D24
#define __GroupCount                                               0xB16032
#define __Guilds                                                   0xB17FC0
#define __gWorld                                                   0xB17EEC
#define __HotkeyPage                                               0xB7A390
#define __HWnd                                                     0xB98BE0
#define __InChatMode                                               0xB1C180
#define __LastTell                                                 0xB1DEBC
#define __LMouseHeldTime                                           0xB1C2B4
#define __Mouse                                                    0xB98EB0
#define __MouseLook                                                0xB1C216
#define __MouseEventTime                                           0xB811E8
#define __NetStatusToggle                                          0xB1C219
#define __PCNames                                                  0xB1D900
#define __RangeAttackReady                                         0xB1D598
#define __RMouseHeldTime                                           0xB1C2B0
#define __RunWalkState                                             0xB1C184
#define __ScreenMode                                               0xA65870
#define __ScreenX                                                  0xB1C138
#define __ScreenY                                                  0xB1C13C
#define __ScreenXMax                                               0xB1C140
#define __ScreenYMax                                               0xB1C144
#define __ServerHost                                               0xB15F74
#define __ServerName                                               0xB52F64
#define __ShiftKeyDown                                             0xB1C844
#define __ShowNames                                                0xB1D7D0
#define __Socials                                                  0xB53064


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xB18520
#define instEQZoneInfo                                             0xB1C400
#define instKeypressHandler                                        0xB811CC
#define pinstActiveBanker                                          0xB17F94
#define pinstActiveCorpse                                          0xB17F98
#define pinstActiveGMaster                                         0xB17F9C
#define pinstActiveMerchant                                        0xB17F90
#define pinstAltAdvManager                                         0xA66718
#define pinstAuraMgr                                               0x966C5C
#define pinstBandageTarget                                         0xB17F7C
#define pinstCamActor                                              0xA66208
#define pinstCDBStr                                                0xA65864
#define pinstCDisplay                                              0xB17FA4
#define pinstCEverQuest                                            0xB99028
#define pinstCharData                                              0xB17F60
#define pinstCharSpawn                                             0xB17F88
#define pinstControlledMissile                                     0xB17F5C
#define pinstControlledPlayer                                      0xB17F88
#define pinstCSidlManager                                          0x12091F4
#define pinstCXWndManager                                          0x12091EC
#define instDynamicZone                                            0xB1BB88
#define pinstDZMember                                              0xB1BC98
#define pinstDZTimerInfo                                           0xB1BC9C
#define pinstEQItemList                                            0xB15244
#define instEQMisc                                                 0xA65810
#define pinstEQSoundManager                                        0xA6673C
#define instExpeditionLeader                                       0xB1BBD2
#define instExpeditionName                                         0xB1BC12
#define pinstGroup                                                 0xB1602E
#define pinstImeManager                                            0x12091F8
#define pinstLocalPlayer                                           0xB17F74
#define pinstMercenaryData                                         0xB8155C
#define pinstModelPlayer                                           0xB17FA0
#define pinstPCData                                                0xB17F60
#define pinstSkillMgr                                              0xB95C64
#define pinstSpawnManager                                          0xB95A48
#define pinstSpellManager                                          0xB95C70
#define pinstSpellSets                                             0xB7A394
#define pinstStringTable                                           0xB17F08
#define pinstSwitchManager                                         0xB15C74
#define pinstTarget                                                0xB17F8C
#define pinstTargetObject                                          0xB17F64
#define pinstTargetSwitch                                          0xB17F68
#define pinstTaskMember                                            0xA657F0
#define pinstTrackTarget                                           0xB17F80
#define pinstTradeTarget                                           0xB17F70
#define instTributeActive                                          0xA65835
#define pinstViewActor                                             0xA66204
#define pinstWorldData                                             0xB17F44


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x964520
#define pinstCAudioTriggersWindow                                  0x9644EC
#define pinstCCharacterSelect                                      0xA660E0
#define pinstCFacePick                                             0xA66090
#define pinstCNoteWnd                                              0xA66098
#define pinstCBookWnd                                              0xA6609C
#define pinstCPetInfoWnd                                           0xA660A0
#define pinstCTrainWnd                                             0xA660A4
#define pinstCSkillsWnd                                            0xA660A8
#define pinstCSkillsSelectWnd                                      0xA660AC
#define pinstCCombatSkillSelectWnd                                 0xA660B0
#define pinstCFriendsWnd                                           0xA660B4
#define pinstCAuraWnd                                              0xA660B8
#define pinstCRespawnWnd                                           0xA660BC
#define pinstCBandolierWnd                                         0xA660C0
#define pinstCPotionBeltWnd                                        0xA660C4
#define pinstCAAWnd                                                0xA660C8
#define pinstCGroupSearchFiltersWnd                                0xA660CC
#define pinstCLoadskinWnd                                          0xA660D0
#define pinstCAlarmWnd                                             0xA660D4
#define pinstCMusicPlayerWnd                                       0xA660D8
#define pinstCMailWnd                                              0xA660E4
#define pinstCMailCompositionWnd                                   0xA660E8
#define pinstCMailAddressBookWnd                                   0xA660EC
#define pinstCRaidWnd                                              0xA660F4
#define pinstCRaidOptionsWnd                                       0xA660F8
#define pinstCBreathWnd                                            0xA660FC
#define pinstCMapViewWnd                                           0xA66100
#define pinstCMapToolbarWnd                                        0xA66104
#define pinstCEditLabelWnd                                         0xA66108
#define pinstCTargetWnd                                            0xA6610C
#define pinstCColorPickerWnd                                       0xA66110
#define pinstCPlayerWnd                                            0xA66114
#define pinstCOptionsWnd                                           0xA66118
#define pinstCBuffWindowNORMAL                                     0xA6611C
#define pinstCBuffWindowSHORT                                      0xA66120
#define pinstCharacterCreation                                     0xA66124
#define pinstCCursorAttachment                                     0xA66128
#define pinstCCastingWnd                                           0xA6612C
#define pinstCCastSpellWnd                                         0xA66130
#define pinstCSpellBookWnd                                         0xA66134
#define pinstCInventoryWnd                                         0xA66138
#define pinstCBankWnd                                              0xA6613C
#define pinstCQuantityWnd                                          0xA66140
#define pinstCLootWnd                                              0xA66144
#define pinstCActionsWnd                                           0xA66148
#define pinstCCombatAbilityWnd                                     0xA6614C
#define pinstCMerchantWnd                                          0xA66150
#define pinstCTradeWnd                                             0xA66154
#define pinstCSelectorWnd                                          0xA66158
#define pinstCBazaarWnd                                            0xA6615C
#define pinstCBazaarSearchWnd                                      0xA66160
#define pinstCGiveWnd                                              0xA6617C
#define pinstCTrackingWnd                                          0xA66180
#define pinstCInspectWnd                                           0xA66184
#define pinstCSocialEditWnd                                        0xA66188
#define pinstCFeedbackWnd                                          0xA6618C
#define pinstCBugReportWnd                                         0xA66190
#define pinstCVideoModesWnd                                        0xA66194
#define pinstCTextEntryWnd                                         0xA6619C
#define pinstCFileSelectionWnd                                     0xA661A0
#define pinstCCompassWnd                                           0xA661A4
#define pinstCPlayerNotesWnd                                       0xA661A8
#define pinstCGemsGameWnd                                          0xA661AC
#define pinstCTimeLeftWnd                                          0xA661B0
#define pinstCPetitionQWnd                                         0xA661C4
#define pinstCSoulmarkWnd                                          0xA661C8
#define pinstCStoryWnd                                             0xA661CC
#define pinstCJournalTextWnd                                       0xA661D0
#define pinstCJournalCatWnd                                        0xA661D4
#define pinstCBodyTintWnd                                          0xA661D8
#define pinstCServerListWnd                                        0xA661DC
#define pinstCAvaZoneWnd                                           0xA661E4
#define pinstCBlockedBuffWnd                                       0xA661E8
#define pinstCBlockedPetBuffWnd                                    0xA661EC
#define pinstCInvSlotMgr                                           0xA661FC
#define pinstCContainerMgr                                         0xA66200
#define pinstCAdventureLeaderboardWnd                              0xBC1660
#define pinstCAdventureRequestWnd                                  0xBC167C
#define pinstCAltStorageWnd                                        0xBC16DC
#define pinstCAdventureStatsWnd                                    0xBC1698
#define pinstCBarterMerchantWnd                                    0xBC18A8
#define pinstCBarterSearchWnd                                      0xBC18C4
#define pinstCBarterWnd                                            0xBC18E0
#define pinstCChatManager                                          0xBC1B84
#define pinstCDynamicZoneWnd                                       0xBC1C7C
#define pinstCEQMainWnd                                            0xBC1CF0
#define pinstCFellowshipWnd                                        0xBC1D54
#define pinstCFindLocationWnd                                      0xBC1D88
#define pinstCGroupSearchWnd                                       0xBC1E38
#define pinstCGroupWnd                                             0xBC1E54
#define pinstCGuildBankWnd                                         0xBC1E70
#define pinstCGuildMgmtWnd                                         0xBC3EA8
#define pinstCGuildTributeMasterWnd                                0xBC3EC8
#define pinstCHotButtonWnd                                         0xBC3EFC
#define pinstCHotButtonWnd1                                        0xBC3EFC
#define pinstCHotButtonWnd2                                        0xBC3F00
#define pinstCHotButtonWnd3                                        0xBC3F04
#define pinstCHotButtonWnd4                                        0xBC3F08
#define pinstCItemDisplayManager                                   0xBC3FB4
#define pinstCItemExpTransferWnd                                   0xBC3FD4
#define pinstCLeadershipWnd                                        0xBC4070
#define pinstCLFGuildWnd                                           0xBC408C
#define pinstCMIZoneSelectWnd                                      0xBC41FC
#define pinstCAdventureMerchantWnd                                 0xBC4324
#define pinstCConfirmationDialog                                   0xBC4340
#define pinstCPopupWndManager                                      0xBC4340
#define pinstCProgressionSelectionWnd                              0xBC4374
#define pinstCPvPLeaderboardWnd                                    0xBC4390
#define pinstCPvPStatsWnd                                          0xBC43AC
#define pinstCSystemInfoDialogBox                                  0xBC44F0
#define pinstCTargetOfTargetWnd                                    0xBC4FF8
#define pinstCTaskSelectWnd                                        0xBC502C
#define pinstCTaskTemplateSelectWnd                                0xBC5048
#define pinstCTaskWnd                                              0xBC5064
#define pinstCTipWndOFDAY                                          0xBC50E0
#define pinstCTipWndCONTEXT                                        0xBC50E4
#define pinstCTitleWnd                                             0xBC5100
#define pinstCTradeskillWnd                                        0xBC5144
#define pinstCTributeBenefitWnd                                    0xBC5190
#define pinstCTributeMasterWnd                                     0xBC51AC
#define pinstCContextMenuManager                                   0x1209250
#define pinstCVoiceMacroWnd                                        0xB95E64
#define pinstCHtmlWnd                                              0xB95EA0


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D0460
#define __ConvertItemTags                                          0x4C1C60
#define __ExecuteCmd                                               0x4ADB30
#define __get_melee_range                                          0x4B3BA0
#define __GetGaugeValueFromEQ                                      0x6B5610
#define __GetLabelFromEQ                                           0x6B6730
#define __GetXTargetType                                           0x72CC00
#define __LoadFrontEnd                                             0x59B730
#define __NewUIINI                                                 0x6B51D0
#define __ProcessGameEvents                                        0x507870
#define CrashDetected                                              0x59B530
#define DrawNetStatus                                              0x530F10
#define Util__FastTime                                             0x7B7C60
#define Expansion_HoT                                              0xB1D730

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x482880
#define AltAdvManager__IsAbilityReady                              0x4828C0
#define AltAdvManager__GetAltAbility                               0x482B90

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x439320

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5B9340

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5C33C0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x77DB30

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5DB130
#define CChatManager__InitContextMenu                              0x5DB900

// CChatService
#define CChatService__GetNumberOfFriends                           0x721A10
#define CChatService__GetFriendName                                0x721A20

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5DFC30
#define CChatWindow__Clear                                         0x5E0590
#define CChatWindow__WndNotification                               0x5E0780

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x767540
#define CComboWnd__Draw                                            0x767710
#define CComboWnd__GetCurChoice                                    0x767400
#define CComboWnd__GetListRect                                     0x767A00
#define CComboWnd__GetTextRect                                     0x767570
#define CComboWnd__InsertChoice                                    0x767A70
#define CComboWnd__SetColors                                       0x767390
#define CComboWnd__SetChoice                                       0x7673C0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5E9A30
#define CContainerWnd__vftable                                     0x8AD488

// CDisplay 
#define CDisplay__CleanGameUI                                      0x476A10
#define CDisplay__GetClickedActor                                  0x46FA60
#define CDisplay__GetUserDefinedColor                              0x46E440
#define CDisplay__GetWorldFilePath                                 0x46D8F0
#define CDisplay__is3dON                                           0x46CA20
#define CDisplay__ReloadUI                                         0x47F9B0
#define CDisplay__WriteTextHD2                                     0x472790

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5B3320
#define CEditBaseWnd__SetSel                                       0x78B3D0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7709B0
#define CEditWnd__GetCharIndexPt                                   0x771970
#define CEditWnd__GetDisplayString                                 0x770B40
#define CEditWnd__GetHorzOffset                                    0x770DD0
#define CEditWnd__GetLineForPrintableChar                          0x771420
#define CEditWnd__GetSelStartPt                                    0x771BC0
#define CEditWnd__GetSTMLSafeText                                  0x770F70
#define CEditWnd__PointFromPrintableChar                           0x771530
#define CEditWnd__SelectableCharFromPoint                          0x7716B0
#define CEditWnd__SetEditable                                      0x770F40

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4E7C60
#define CEverQuest__DropHeldItemOnGround                           0x4F5070
#define CEverQuest__dsp_chat                                       0x4EE010
#define CEverQuest__DoTellWindow                                   0x4EC7B0
#define CEverQuest__EnterZone                                      0x4FF2C0
#define CEverQuest__GetBodyTypeDesc                                0x4E4AD0
#define CEverQuest__GetClassDesc                                   0x4E4310
#define CEverQuest__GetClassThreeLetterCode                        0x4E4910
#define CEverQuest__GetDeityDesc                                   0x4E5140
#define CEverQuest__GetLangDesc                                    0x4E4E60
#define CEverQuest__GetRaceDesc                                    0x4E5110
#define CEverQuest__InterpretCmd                                   0x4EEB70
#define CEverQuest__LeftClickedOnPlayer                            0x501420
#define CEverQuest__LMouseUp                                       0x504DE0
#define CEverQuest__RightClickedOnPlayer                           0x505F40
#define CEverQuest__RMouseUp                                       0x5070C0
#define CEverQuest__SetGameState                                   0x4E80F0
#define CEverQuest__Emote                                          0x4EE230

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5F6940
#define CGaugeWnd__CalcLinesFillRect                               0x5F69A0
#define CGaugeWnd__Draw                                            0x5F6DF0

// CGuild
#define CGuild__FindMemberByName                                   0x41B890

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x60FBC0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x61B6B0
#define CInvSlotMgr__MoveItem                                      0x61BAC0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x61AB10
#define CInvSlot__SliderComplete                                   0x618E70
#define CInvSlot__GetItemBase                                      0x6185D0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x61C8A0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6B2EE0
#define CItemDisplayWnd__UpdateStrings                             0x61D790

// CLabel 
#define CLabel__Draw                                               0x631B80

// CListWnd 
#define CListWnd__AddColumn                                        0x7600D0
#define CListWnd__AddColumn1                                       0x75F780
#define CListWnd__AddLine                                          0x75F2E0
#define CListWnd__AddString                                        0x75F480
#define CListWnd__CalculateFirstVisibleLine                        0x75B5F0
#define CListWnd__CalculateVSBRange                                0x75D920
#define CListWnd__ClearAllSel                                      0x75AB40
#define CListWnd__CloseAndUpdateEditWindow                         0x75E950
#define CListWnd__Compare                                          0x75BFF0
#define CListWnd__Draw                                             0x75D560
#define CListWnd__DrawColumnSeparators                             0x75D3D0
#define CListWnd__DrawHeader                                       0x75ADD0
#define CListWnd__DrawItem                                         0x75C9F0
#define CListWnd__DrawLine                                         0x75D050
#define CListWnd__DrawSeparator                                    0x75D470
#define CListWnd__EnsureVisible                                    0x75B750
#define CListWnd__ExtendSel                                        0x75C910
#define CListWnd__GetColumnMinWidth                                0x75A810
#define CListWnd__GetColumnWidth                                   0x75A750
#define CListWnd__GetCurSel                                        0x759FD0
#define CListWnd__GetHeaderRect                                    0x75A130
#define CListWnd__GetItemAtPoint                                   0x75BA20
#define CListWnd__GetItemAtPoint1                                  0x75BA90
#define CListWnd__GetItemData                                      0x75A350
#define CListWnd__GetItemHeight                                    0x75B260
#define CListWnd__GetItemIcon                                      0x75A530
#define CListWnd__GetItemRect                                      0x75B820
#define CListWnd__GetItemText                                      0x75A3E0
#define CListWnd__GetSelList                                       0x75F660
#define CListWnd__GetSeparatorRect                                 0x75BF40
#define CListWnd__RemoveLine                                       0x75F610
#define CListWnd__SetColors                                        0x75A0A0
#define CListWnd__SetColumnJustification                           0x75A9B0
#define CListWnd__SetColumnWidth                                   0x75A7D0
#define CListWnd__SetCurSel                                        0x75A010
#define CListWnd__SetItemColor                                     0x75E610
#define CListWnd__SetItemData                                      0x75ABE0
#define CListWnd__SetItemText                                      0x75E3F0
#define CListWnd__ShiftColumnSeparator                             0x75E260
#define CListWnd__Sort                                             0x760810
#define CListWnd__ToggleSel                                        0x75AAB0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x647B40

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x659B30
#define CMerchantWnd__RequestBuyItem                               0x65D380
#define CMerchantWnd__RequestSellItem                              0x67C410
#define CMerchantWnd__SelectBuySellSlot                            0x65AE10

// CObfuscator
#define CObfuscator__doit                                          0x6F0FF0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x779260
#define CSidlManager__CreateLabel                                  0x6ABD20

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5B54D0
#define CSidlScreenWnd__CalculateVSBRange                          0x5B53F0
#define CSidlScreenWnd__ConvertToRes                               0x78B2B0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x769AF0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x76AB80
#define CSidlScreenWnd__CSidlScreenWnd2                            0x76AC30
#define CSidlScreenWnd__dCSidlScreenWnd                            0x76A3A0
#define CSidlScreenWnd__DrawSidlPiece                              0x7695C0
#define CSidlScreenWnd__EnableIniStorage                           0x768D80
#define CSidlScreenWnd__GetSidlPiece                               0x7697D0
#define CSidlScreenWnd__Init1                                      0x76A9E0
#define CSidlScreenWnd__LoadIniInfo                                0x769BA0
#define CSidlScreenWnd__LoadIniListWnd                             0x768ED0
#define CSidlScreenWnd__LoadSidlScreen                             0x76A5F0
#define CSidlScreenWnd__StoreIniInfo                               0x768980
#define CSidlScreenWnd__StoreIniVis                                0x768D10
#define CSidlScreenWnd__WndNotification                            0x76A7D0
#define CSidlScreenWnd__GetChildItem                               0x768DE0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x5686B0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x78BCB0
#define CSliderWnd__SetValue                                       0x78BDB0
#define CSliderWnd__SetNumTicks                                    0x78C360

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6B0AF0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x788930
#define CStmlWnd__CalculateHSBRange                                0x780030
#define CStmlWnd__CalculateVSBRange                                0x77FFA0
#define CStmlWnd__CanBreakAtCharacter                              0x780190
#define CStmlWnd__FastForwardToEndOfTag                            0x780E90
#define CStmlWnd__ForceParseNow                                    0x788E60
#define CStmlWnd__GetNextTagPiece                                  0x780DB0
#define CStmlWnd__GetSTMLText                                      0x5DFBD0
#define CStmlWnd__GetThisChar                                      0x7B0930
#define CStmlWnd__GetVisiableText                                  0x7822E0
#define CStmlWnd__InitializeWindowVariables                        0x7848B0
#define CStmlWnd__MakeStmlColorTag                                 0x77EEC0
#define CStmlWnd__MakeWndNotificationTag                           0x77EF60
#define CStmlWnd__SetSTMLText                                      0x7849D0
#define CStmlWnd__StripFirstSTMLLines                              0x7885E0
#define CStmlWnd__UpdateHistoryString                              0x782B70

// CTabWnd 
#define CTabWnd__Draw                                              0x78D260
#define CTabWnd__DrawCurrentPage                                   0x78CB30
#define CTabWnd__DrawTab                                           0x78C910
#define CTabWnd__GetCurrentPage                                    0x78CEF0
#define CTabWnd__GetPageClientRect                                 0x78C5C0
#define CTabWnd__GetPageFromTabIndex                               0x78C840
#define CTabWnd__GetPageInnerRect                                  0x78C620
#define CTabWnd__GetTabInnerRect                                   0x78C7C0
#define CTabWnd__GetTabRect                                        0x78C6B0
#define CTabWnd__InsertPage                                        0x78D4F0
#define CTabWnd__SetPage                                           0x78CF30
#define CTabWnd__SetPageRect                                       0x78D190
#define CTabWnd__UpdatePage                                        0x78D470

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417E90

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x76AFB0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x78E100

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x758F30

// CXRect 
#define CXRect__CenterPoint                                        0x5B8BA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4160A0
#define CXStr__CXStr1                                              0x7C7C60
#define CXStr__CXStr3                                              0x7B4F00
#define CXStr__dCXStr                                              0x780420
#define CXStr__operator_equal                                      0x7B5070
#define CXStr__operator_equal1                                     0x7B50C0
#define CXStr__operator_plus_equal1                                0x7B6150

// CXWnd 
#define CXWnd__BringToTop                                          0x760DF0
#define CXWnd__Center                                              0x765DE0
#define CXWnd__ClrFocus                                            0x760C20
#define CXWnd__DoAllDrawing                                        0x766730
#define CXWnd__DrawChildren                                        0x766880
#define CXWnd__DrawColoredRect                                     0x7610D0
#define CXWnd__DrawTooltip                                         0x765D10
#define CXWnd__DrawTooltipAtPoint                                  0x765490
#define CXWnd__GetBorderFrame                                      0x761610
#define CXWnd__GetChildWndAt                                       0x764900
#define CXWnd__GetClientClipRect                                   0x761390
#define CXWnd__GetScreenClipRect                                   0x765950
#define CXWnd__GetScreenRect                                       0x761730
#define CXWnd__GetTooltipRect                                      0x7611E0
#define CXWnd__GetWindowTextA                                      0x5A67F0
#define CXWnd__IsActive                                            0x76C0E0
#define CXWnd__IsDescendantOf                                      0x761500
#define CXWnd__IsReallyVisible                                     0x7648E0
#define CXWnd__IsType                                              0x790F70
#define CXWnd__Move                                                0x763DF0
#define CXWnd__Move1                                               0x763E90
#define CXWnd__ProcessTransition                                   0x760DA0
#define CXWnd__Refade                                              0x760D20
#define CXWnd__Resize                                              0x761800
#define CXWnd__Right                                               0x765860
#define CXWnd__SetFocus                                            0x762FF0
#define CXWnd__SetKeyTooltip                                       0x761A50
#define CXWnd__SetMouseOver                                        0x765BF0
#define CXWnd__StartFade                                           0x760E20
#define CXWnd__GetChildItem                                        0x765B60

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x76D700
#define CXWndManager__DrawWindows                                  0x76D380
#define CXWndManager__GetKeyboardFlags                             0x76BD40
#define CXWndManager__HandleKeyboardMsg                            0x76C3B0
#define CXWndManager__RemoveWnd                                    0x76C200

// CDBStr
#define CDBStr__GetString                                          0x46B2A0

// EQ_Character 
#define EQ_Character__CastRay                                      0x70F530
#define EQ_Character__CastSpell                                    0x430240
#define EQ_Character__Cur_HP                                       0x438FE0
#define EQ_Character__GetAACastingTimeModifier                     0x425200
#define EQ_Character__GetCharInfo2                                 0x70E270
#define EQ_Character__GetFocusCastingTimeModifier                  0x420900
#define EQ_Character__GetFocusRangeModifier                        0x420AD0
#define EQ_Character__Max_Endurance                                0x5390A0
#define EQ_Character__Max_HP                                       0x433FB0
#define EQ_Character__Max_Mana                                     0x538EA0
#define EQ_Character__doCombatAbility                              0x537D10
#define EQ_Character__UseSkill                                     0x447870
#define EQ_Character__GetConLevel                                  0x532B50
#define EQ_Character__IsExpansionFlag                              0x40D8D0
#define EQ_Character__TotalEffect                                  0x429710

// EQ_Item 
#define EQ_Item__CanDrop                                           0x518B90
#define EQ_Item__CreateItemTagString                               0x6FDF20
#define EQ_Item__IsStackable                                       0x6F1E20

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x483A60
#define EQ_LoadingS__Array                                         0x93EF60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x53D010
#define EQ_PC__GetAltAbilityIndex                                  0x703CD0
#define EQ_PC__GetCombatAbility                                    0x703D60
#define EQ_PC__GetCombatAbilityTimer                               0x703E10
#define EQ_PC__GetItemTimerValue                                   0x537B30
#define EQ_PC__HasLoreItem                                         0x70CDC0

// EQItemList 
#define EQItemList__EQItemList                                     0x4B1DF0
#define EQItemList__add_item                                       0x4B1D80
#define EQItemList__delete_item                                    0x4B21A0
#define EQItemList__FreeItemList                                   0x4B20D0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46AA90

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x541AD0
#define EQPlayer__dEQPlayer                                        0x546480
#define EQPlayer__DoAttack                                         0x5570F0
#define EQPlayer__EQPlayer                                         0x54BCA0
#define EQPlayer__SetNameSpriteState                               0x543EE0
#define EQPlayer__SetNameSpriteTint                                0x541B40
#define EQPlayer__IsBodyType_j                                     0x70EE00
#define EQPlayer__IsTargetable                                     0x70EFD0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x54CF60
#define EQPlayerManager__GetSpawnByName                            0x54D300

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x51DC30
#define KeypressHandler__AttachKeyToEqCommand                      0x51DC70
#define KeypressHandler__ClearCommandStateArray                    0x51DA40
#define KeypressHandler__HandleKeyDown                             0x51C4B0
#define KeypressHandler__HandleKeyUp                               0x51C7C0
#define KeypressHandler__SaveKeymapping                            0x51DB10

// MapViewMap 
#define MapViewMap__Clear                                          0x6431E0
#define MapViewMap__SaveEx                                         0x643BB0

#define PlayerPointManager__GetAltCurrency                         0x6FF370

// StringTable 
#define StringTable__getString                                     0x6F1270
