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
#define __ExpectedVersionDate                                     "Dec  7 2009"
#define __ExpectedVersionTime                                     "09:19:26"
#define __ActualVersionDate                                        0x816B20
#define __ActualVersionTime                                        0x816B2C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x510D60
#define __MemChecker1                                              0x6DFF00
#define __MemChecker2                                              0x570B00
#define __MemChecker3                                              0x570A50
#define __MemChecker4                                              0x694740
#define __EncryptPad0                                              0x8A7190
#define __EncryptPad1                                              0x8B2298
#define __EncryptPad2                                              0x8A9DC8
#define __EncryptPad3                                              0x8A99C8
#define __EncryptPad4                                              0x8B18D8
#define __AC1                                                      0x65C610
#define __AC2                                                      0x4D8D85
#define __AC3                                                      0x4ECE48
#define __AC4                                                      0x4F0D18
#define __AC5                                                      0x4FB468
#define __AC6                                                      0x4FE8EB
#define __AC7                                                      0x4F7994
#define __AC1_Data                                                 0x7FF880

// Direct Input
#define DI8__Main                                                  0xB0CCBC
#define DI8__Keyboard                                              0xB0CCC0
#define DI8__Mouse                                                 0xB0CCC4
#define __AltTimerReady                                            0xA939CE
#define __Attack                                                   0xAF706E
#define __Autofire                                                 0xAF706F
#define __BindList                                                 0x8A1910
#define __Clicks                                                   0xA926C8
#define __CommandList                                              0x8A2260
#define __CurrentMapLabel                                          0xB37F58
#define __CurrentSocial                                            0x89D83C
#define __DoAbilityAvailable                                       0xA93968
#define __DoAbilityList                                            0xAC8F8C
#define __do_loot                                                  0x4B1AA0
#define __DrawHandler                                              0xB4755C
#define __GroupCount                                               0xA8C4C2
#define __Guilds                                                   0xA91AA8
#define __gWorld                                                   0xA8E380
#define __HotkeyPage                                               0xAF0378
#define __HWnd                                                     0xB0C9F8
#define __InChatMode                                               0xA92600
#define __LastTell                                                 0xA942E4
#define __LMouseHeldTime                                           0xA926F4
#define __Mouse                                                    0xB0CCC8
#define __MouseLook                                                0xA92696
#define __MouseEventTime                                           0xAF71B0
#define __NetStatusToggle                                          0xA92699
#define __PCNames                                                  0xA93D28
#define __RangeAttackReady                                         0xA939CC
#define __RMouseHeldTime                                           0xA926F0
#define __RunWalkState                                             0xA92604
#define __ScreenMode                                               0x9DBD58
#define __ScreenX                                                  0xA925B8
#define __ScreenY                                                  0xA925BC
#define __ScreenXMax                                               0xA925C0
#define __ScreenYMax                                               0xA925C4
#define __ServerHost                                               0xA8C404
#define __ServerName                                               0xAC8F4C
#define __ShiftKeyDown                                             0xA92C80
#define __ShowNames                                                0xA93BFC
#define __Socials                                                  0xAC904C


////
//Section 1: Vital Offsets
////
#define instCRaid                                                  0xA8E440
#define instEQZoneInfo                                             0xA92840
#define instKeypressHandler                                        0xAF7194
#define pinstActiveBanker                                          0xA8E418
#define pinstActiveCorpse                                          0xA8E41C
#define pinstActiveGMaster                                         0xA8E420
#define pinstActiveMerchant                                        0xA8E414
#define pinstAltAdvManager                                         0x9DCBD8
#define pinstAuraMgr                                               0x8C561C
#define pinstBandageTarget                                         0xA8E400
#define pinstCamActor                                              0x9DC6C4
#define pinstCDBStr                                                0x9DBD48
#define pinstCDisplay                                              0xA8E428
#define pinstCEverQuest                                            0xB0CE40
#define pinstCharData                                              0xA8E3E4
#define pinstCharSpawn                                             0xA8E40C
#define pinstControlledMissile                                     0xA8E3E0
#define pinstControlledPlayer                                      0xA8E40C
#define pinstCSidlManager                                          0xB46CD0
#define pinstCXWndManager                                          0xB46CC8
#define instDynamicZone                                            0xA92488
#define pinstDZMember                                              0xA92598
#define pinstDZTimerInfo                                           0xA9259C
#define pinstEQItemList                                            0xA8E3C8
#define instEQMisc                                                 0x9DBD00
#define pinstEQSoundManager                                        0x9DCBFC
#define instExpeditionLeader                                       0xA924D2
#define instExpeditionName                                         0xA92512
#define pinstGroup                                                 0xA8C4BE
#define pinstImeManager                                            0xB46CD4
#define pinstLocalPlayer                                           0xA8E3F8
#define pinstMercenaryData                                         0xAF7508
#define pinstModelPlayer                                           0xA8E424
#define pinstPCData                                                0xA8E3E4
#define pinstSkillMgr                                              0xB09AAC
#define pinstSpawnManager                                          0xB09908
#define pinstSpellManager                                          0xB09AB8
#define pinstSpellSets                                             0xAF037C
#define pinstStringTable                                           0xA8E39C
#define pinstSwitchManager                                         0xA8C104
#define pinstTarget                                                0xA8E410
#define pinstTargetObject                                          0xA8E3E8
#define pinstTargetSwitch                                          0xA8E3EC
#define pinstTaskMember                                            0x9DBCE0
#define pinstTrackTarget                                           0xA8E404
#define pinstTradeTarget                                           0xA8E3F4
#define instTributeActive                                          0x9DBD25
#define pinstViewActor                                             0x9DC6C0
#define pinstWorldData                                             0xA8E3C4


////
//Section 2:  UI Related Offsets
////
#define pinstCTextOverlay                                          0x8C2EE4
#define pinstCAudioTriggersWindow                                  0x8C2EB0
#define pinstCCharacterSelect                                      0x9DC5C0
#define pinstCFacePick                                             0x9DC570
#define pinstCNoteWnd                                              0x9DC578
#define pinstCBookWnd                                              0x9DC57C
#define pinstCPetInfoWnd                                           0x9DC580
#define pinstCTrainWnd                                             0x9DC584
#define pinstCSkillsWnd                                            0x9DC588
#define pinstCSkillsSelectWnd                                      0x9DC58C
#define pinstCCombatSkillSelectWnd                                 0x9DC590
#define pinstCFriendsWnd                                           0x9DC594
#define pinstCAuraWnd                                              0x9DC598
#define pinstCRespawnWnd                                           0x9DC59C
#define pinstCBandolierWnd                                         0x9DC5A0
#define pinstCPotionBeltWnd                                        0x9DC5A4
#define pinstCAAWnd                                                0x9DC5A8
#define pinstCGroupSearchFiltersWnd                                0x9DC5AC
#define pinstCLoadskinWnd                                          0x9DC5B0
#define pinstCAlarmWnd                                             0x9DC5B4
#define pinstCMusicPlayerWnd                                       0x9DC5B8
#define pinstCMailWnd                                              0x9DC5C4
#define pinstCMailCompositionWnd                                   0x9DC5C8
#define pinstCMailAddressBookWnd                                   0x9DC5CC
#define pinstCRaidWnd                                              0x9DC5D4
#define pinstCRaidOptionsWnd                                       0x9DC5D8
#define pinstCBreathWnd                                            0x9DC5DC
#define pinstCMapViewWnd                                           0x9DC5E0
#define pinstCMapToolbarWnd                                        0x9DC5E4
#define pinstCEditLabelWnd                                         0x9DC5E8
#define pinstCTargetWnd                                            0x9DC5EC
#define pinstCColorPickerWnd                                       0x9DC5F0
#define pinstCPlayerWnd                                            0x9DC5F4
#define pinstCOptionsWnd                                           0x9DC5F8
#define pinstCBuffWindowNORMAL                                     0x9DC5FC
#define pinstCBuffWindowSHORT                                      0x9DC600
#define pinstCharacterCreation                                     0x9DC604
#define pinstCCursorAttachment                                     0x9DC608
#define pinstCCastingWnd                                           0x9DC60C
#define pinstCCastSpellWnd                                         0x9DC610
#define pinstCSpellBookWnd                                         0x9DC614
#define pinstCInventoryWnd                                         0x9DC618
#define pinstCBankWnd                                              0x9DC61C
#define pinstCQuantityWnd                                          0x9DC620
#define pinstCLootWnd                                              0x9DC624
#define pinstCActionsWnd                                           0x9DC628
#define pinstCCombatAbilityWnd                                     0x9DC62C
#define pinstCMerchantWnd                                          0x9DC630
#define pinstCTradeWnd                                             0x9DC634
#define pinstCSelectorWnd                                          0x9DC638
#define pinstCBazaarWnd                                            0x9DC63C
#define pinstCBazaarSearchWnd                                      0x9DC640
#define pinstCGiveWnd                                              0x9DC644
#define pinstCTrackingWnd                                          0x9DC648
#define pinstCInspectWnd                                           0x9DC64C
#define pinstCSocialEditWnd                                        0x9DC650
#define pinstCFeedbackWnd                                          0x9DC654
#define pinstCBugReportWnd                                         0x9DC658
#define pinstCVideoModesWnd                                        0x9DC65C
#define pinstCTextEntryWnd                                         0x9DC664
#define pinstCFileSelectionWnd                                     0x9DC668
#define pinstCCompassWnd                                           0x9DC66C
#define pinstCPlayerNotesWnd                                       0x9DC670
#define pinstCGemsGameWnd                                          0x9DC674
#define pinstCTimeLeftWnd                                          0x9DC678
#define pinstCPetitionQWnd                                         0x9DC68C
#define pinstCSoulmarkWnd                                          0x9DC690
#define pinstCStoryWnd                                             0x9DC694
#define pinstCJournalTextWnd                                       0x9DC698
#define pinstCJournalCatWnd                                        0x9DC69C
#define pinstCBodyTintWnd                                          0x9DC6A0
#define pinstCServerListWnd                                        0x9DC6A4
#define pinstCAvaZoneWnd                                           0x9DC6AC
#define pinstCBlockedBuffWnd                                       0x9DC6B0
#define pinstCBlockedPetBuffWnd                                    0x9DC6B4
#define pinstCInvSlotMgr                                           0x9DC6B8
#define pinstCContainerMgr                                         0x9DC6BC
#define pinstCAdventureLeaderboardWnd                              0xB35470
#define pinstCAdventureRequestWnd                                  0xB3548C
#define pinstCAltStorageWnd                                        0xB354EC
#define pinstCAdventureStatsWnd                                    0xB354A8
#define pinstCBarterMerchantWnd                                    0xB356B8
#define pinstCBarterSearchWnd                                      0xB356D4
#define pinstCBarterWnd                                            0xB356F0
#define pinstCChatManager                                          0xB35994
#define pinstCDynamicZoneWnd                                       0xB35A8C
#define pinstCEQMainWnd                                            0xB35B00
#define pinstCFellowshipWnd                                        0xB35B64
#define pinstCFindLocationWnd                                      0xB35B98
#define pinstCGroupSearchWnd                                       0xB35C48
#define pinstCGroupWnd                                             0xB35C64
#define pinstCGuildBankWnd                                         0xB35C80
#define pinstCGuildMgmtWnd                                         0xB37CB8
#define pinstCGuildTributeMasterWnd                                0xB37CD8
#define pinstCHotButtonWnd                                         0xB37D0C
#define pinstCHotButtonWnd1                                        0xB37D0C
#define pinstCHotButtonWnd2                                        0xB37D10
#define pinstCHotButtonWnd3                                        0xB37D14
#define pinstCHotButtonWnd4                                        0xB37D18
#define pinstCItemDisplayManager                                   0xB37DC4
#define pinstCItemExpTransferWnd                                   0xB37DE4
#define pinstCLeadershipWnd                                        0xB37E80
#define pinstCLFGuildWnd                                           0xB37E9C
#define pinstCMIZoneSelectWnd                                      0xB3800C
#define pinstCAdventureMerchantWnd                                 0xB3811C
#define pinstCConfirmationDialog                                   0xB38138
#define pinstCPopupWndManager                                      0xB38138
#define pinstCProgressionSelectionWnd                              0xB3816C
#define pinstCPvPLeaderboardWnd                                    0xB38188
#define pinstCPvPStatsWnd                                          0xB381A4
#define pinstCSystemInfoDialogBox                                  0xB38270
#define pinstCTargetOfTargetWnd                                    0xB38C6C
#define pinstCTaskSelectWnd                                        0xB38CA0
#define pinstCTaskTemplateSelectWnd                                0xB38CBC
#define pinstCTaskWnd                                              0xB38CD8
#define pinstCTipWndOFDAY                                          0xB38D54
#define pinstCTipWndCONTEXT                                        0xB38D58
#define pinstCTitleWnd                                             0xB38D74
#define pinstCTradeskillWnd                                        0xB38DB8
#define pinstCTributeBenefitWnd                                    0xB38E04
#define pinstCTributeMasterWnd                                     0xB38E20
#define pinstCContextMenuManager                                   0xB46D2C
#define pinstCVoiceMacroWnd                                        0xB09CAC
#define pinstCHtmlWnd                                              0xB09CF8


////
// Section 3: Miscellaneous Offsets
////
#define __CastRay                                                  0x4C57E0
#define __ConvertItemTags                                          0x4B7120
#define __ExecuteCmd                                               0x4A3900
#define __get_melee_range                                          0x4A9230
#define __GetGaugeValueFromEQ                                      0x65B500
#define __GetLabelFromEQ                                           0x65C5B0
#define __LoadFrontEnd                                             0x56F9C0
#define __NewUIINI                                                 0x65B090
#define __ProcessGameEvents                                        0x4F7D80
#define CrashDetected                                              0x56F7C0
#define DrawNetStatus                                              0x5199F0
#define Util__FastTime                                             0x6E0610


////
// Section 4: Function Offsets
////
// AltAdvManager
#define AltAdvManager__GetCalculatedTimer                          0x47AB10
#define AltAdvManager__IsAbilityReady                              0x47AB50
#define AltAdvManager__GetAltAbility                               0x47AD30

// CBankWnd
#define CBankWnd__GetNumBankSlots                                  0x58CB70

// CBazaarSearchWnd
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5960B0

// CButtonWnd
#define CButtonWnd__SetCheck                                       0x70E320

// CChatManager
#define CChatManager__GetRGBAFromIndex                             0x5AC280
#define CChatManager__InitContextMenu                              0x5ACA50

// CChatService
#define CChatService__GetNumberOfFriends                           0x6CAC40
#define CChatService__GetFriendName                                0x6CAC50

// CChatWindow
#define CChatWindow__CChatWindow                                   0x5B0C50
#define CChatWindow__Clear                                         0x5B15C0
#define CChatWindow__WndNotification                               0x5B17E0

// CComboWnd
#define CComboWnd__DeleteAll                                       0x6F8180
#define CComboWnd__Draw                                            0x6F8340
#define CComboWnd__GetCurChoice                                    0x6F8120
#define CComboWnd__GetListRect                                     0x6F8630
#define CComboWnd__GetTextRect                                     0x6F81B0
#define CComboWnd__InsertChoice                                    0x6F86A0
#define CComboWnd__SetColors                                       0x6F80B0
#define CComboWnd__SetChoice                                       0x6F80E0

// CContainerWnd
#define CContainerWnd__HandleCombine                               0x5B8CD0
#define CContainerWnd__vftable                                     0x81E480

// CDisplay
#define CDisplay__CleanGameUI                                      0x46DC40
#define CDisplay__GetClickedActor                                  0x466F30
#define CDisplay__GetUserDefinedColor                              0x466050
#define CDisplay__GetWorldFilePath                                 0x4654C0
#define CDisplay__is3dON                                           0x464600
#define CDisplay__ReloadUI                                         0x477D10
#define CDisplay__WriteTextHD2                                     0x469C60

// CEditBaseWnd
#define CEditBaseWnd__SetMaxChars                                  0x586AC0
#define CEditBaseWnd__SetSel                                       0x71A7F0

// CEditWnd
#define CEditWnd__DrawCaret                                        0x701150
#define CEditWnd__GetCharIndexPt                                   0x702120
#define CEditWnd__GetDisplayString                                 0x7012F0
#define CEditWnd__GetHorzOffset                                    0x701580
#define CEditWnd__GetLineForPrintableChar                          0x701BD0
#define CEditWnd__GetSelStartPt                                    0x702370
#define CEditWnd__GetSTMLSafeText                                  0x701720
#define CEditWnd__PointFromPrintableChar                           0x701CE0
#define CEditWnd__SelectableCharFromPoint                          0x701E60
#define CEditWnd__SetEditable                                      0x7016F0

// CEverQuest
#define CEverQuest__ClickedPlayer                                  0x4D9460
#define CEverQuest__DropHeldItemOnGround                           0x4DDAC0
#define CEverQuest__dsp_chat                                       0x4DF210
#define CEverQuest__DoTellWindow                                   0x4DDC40
#define CEverQuest__EnterZone                                      0x4F0CB0
#define CEverQuest__GetBodyTypeDesc                                0x4D6660
#define CEverQuest__GetClassDesc                                   0x4D5EA0
#define CEverQuest__GetClassThreeLetterCode                        0x4D64A0
#define CEverQuest__GetDeityDesc                                   0x4D6CD0
#define CEverQuest__GetLangDesc                                    0x4D69F0
#define CEverQuest__GetRaceDesc                                    0x4D6CA0
#define CEverQuest__InterpretCmd                                   0x4DFD70
#define CEverQuest__LeftClickedOnPlayer                            0x4F27E0
#define CEverQuest__LMouseUp                                       0x4F60D0
#define CEverQuest__RightClickedOnPlayer                           0x4F6970
#define CEverQuest__RMouseUp                                       0x4F7950
#define CEverQuest__SetGameState                                   0x4D98F0
#define CEverQuest__Emote                                          0x4DF430

// CGaugeWnd
#define CGaugeWnd__CalcFillRect                                    0x5C5560
#define CGaugeWnd__CalcLinesFillRect                               0x5C55C0
#define CGaugeWnd__Draw                                            0x5C5A10

// CGuild
#define CGuild__FindMemberByName                                   0x41AEF0

// CHotButtonWnd
#define CHotButtonWnd__DoHotButton                                 0x5DE580

// CInvSlotMgr
#define CInvSlotMgr__FindInvSlot                                   0x5E7BD0
#define CInvSlotMgr__MoveItem                                      0x5E7D70

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5E7460
#define CInvSlot__SliderComplete                                   0x5E6570

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5E8D10

// CItemDisplayWnd
#define CItemDisplayWnd__SetSpell                                  0x658F50
#define CItemDisplayWnd__UpdateStrings                             0x5E99C0

// CLabel
#define CLabel__Draw                                               0x5FC0B0

// CListWnd
#define CListWnd__AddColumn                                        0x6F1BA0
#define CListWnd__AddColumn1                                       0x6F1670
#define CListWnd__AddLine                                          0x6F1190
#define CListWnd__AddString                                        0x6F1330
#define CListWnd__CalculateFirstVisibleLine                        0x6EDE50
#define CListWnd__CalculateVSBRange                                0x6F0070
#define CListWnd__ClearAllSel                                      0x6ED3A0
#define CListWnd__CloseAndUpdateEditWindow                         0x6EE4D0
#define CListWnd__Compare                                          0x6EE870
#define CListWnd__Draw                                             0x6EFCF0
#define CListWnd__DrawColumnSeparators                             0x6EFB60
#define CListWnd__DrawHeader                                       0x6ED630
#define CListWnd__DrawItem                                         0x6EF180
#define CListWnd__DrawLine                                         0x6EF7D0
#define CListWnd__DrawSeparator                                    0x6EFC00
#define CListWnd__EnsureVisible                                    0x6EDEE0
#define CListWnd__ExtendSel                                        0x6EF0A0
#define CListWnd__GetColumnMinWidth                                0x6ED130
#define CListWnd__GetColumnWidth                                   0x6ED070
#define CListWnd__GetCurSel                                        0x6ECA80
#define CListWnd__GetHeaderRect                                    0x6ECBF0
#define CListWnd__GetItemAtPoint                                   0x6EE1E0
#define CListWnd__GetItemAtPoint1                                  0x6EE250
#define CListWnd__GetItemData                                      0x6ECE20
#define CListWnd__GetItemHeight                                    0x6EDAC0
#define CListWnd__GetItemIcon                                      0x6ECFB0
#define CListWnd__GetItemRect                                      0x6EDFC0
#define CListWnd__GetItemText                                      0x6ECE60
#define CListWnd__GetSelList                                       0x6F1550
#define CListWnd__GetSeparatorRect                                 0x6EE7B0
#define CListWnd__RemoveLine                                       0x6F1500
#define CListWnd__SetColors                                        0x6ECB50
#define CListWnd__SetColumnJustification                           0x6ED210
#define CListWnd__SetColumnWidth                                   0x6ED0F0
#define CListWnd__SetCurSel                                        0x6ECAC0
#define CListWnd__SetItemColor                                     0x6F0D20
#define CListWnd__SetItemData                                      0x6ED440
#define CListWnd__SetItemText                                      0x6F0CA0
#define CListWnd__ShiftColumnSeparator                             0x6EEFB0
#define CListWnd__Sort                                             0x6F1BE0
#define CListWnd__ToggleSel                                        0x6ED310

// CMapViewWnd
#define CMapViewWnd__CMapViewWnd                                   0x611950

// CMerchantWnd
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x61D980
#define CMerchantWnd__RequestBuyItem                               0x61F8C0
#define CMerchantWnd__RequestSellItem                              0x61FCE0
#define CMerchantWnd__SelectBuySellSlot                            0x61ED50

// CObfuscator
#define CObfuscator__doit                                          0x6A4B10

// CSidlManager
#define CSidlManager__FindScreenPieceTemplate1                     0x709A20
#define CSidlManager__CreateLabel                                  0x651EF0

// CSidlScreenWnd
#define CSidlScreenWnd__CalculateHSBRange                          0x6F9DD0
#define CSidlScreenWnd__CalculateVSBRange                          0x588B80
#define CSidlScreenWnd__ConvertToRes                               0x71A6D0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6FA2A0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6FB390
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6FB440
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6FAB40
#define CSidlScreenWnd__DrawSidlPiece                              0x6F9F60
#define CSidlScreenWnd__EnableIniStorage                           0x6F9AC0
#define CSidlScreenWnd__GetSidlPiece                               0x6FA170
#define CSidlScreenWnd__Init1                                      0x6FB1F0
#define CSidlScreenWnd__LoadIniInfo                                0x6FA360
#define CSidlScreenWnd__LoadIniListWnd                             0x6F9C10
#define CSidlScreenWnd__LoadSidlScreen                             0x6FAD90
#define CSidlScreenWnd__StoreIniInfo                               0x6F96D0
#define CSidlScreenWnd__StoreIniVis                                0x6F9A50
#define CSidlScreenWnd__WndNotification                            0x6FAF70
#define CSidlScreenWnd__GetChildItem                               0x6F9B20

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x53D530

// CSliderWnd
#define CSliderWnd__GetValue                                       0x71BC30
#define CSliderWnd__SetValue                                       0x71BD30
#define CSliderWnd__SetNumTicks                                    0x71C2E0

// CSpellBookWnd
#define CSpellBookWnd__MemorizeSet                                 0x656CB0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7189A0
#define CStmlWnd__CalculateVSBRange                                0x7105B0
#define CStmlWnd__CanBreakAtCharacter                              0x710730
#define CStmlWnd__FastForwardToEndOfTag                            0x711390
#define CStmlWnd__ForceParseNow                                    0x718DF0
#define CStmlWnd__GetNextTagPiece                                  0x7112B0
#define CStmlWnd__GetSTMLText                                      0x5B0BF0
#define CStmlWnd__GetThisChar                                      0x73F870
#define CStmlWnd__GetVisiableText                                  0x712770
#define CStmlWnd__InitializeWindowVariables                        0x714A00
#define CStmlWnd__MakeStmlColorTag                                 0x70F440
#define CStmlWnd__MakeWndNotificationTag                           0x70F4E0
#define CStmlWnd__SetSTMLText                                      0x714B20
#define CStmlWnd__StripFirstSTMLLines                              0x718720
#define CStmlWnd__UpdateHistoryString                              0x712FD0

// CTabWnd
#define CTabWnd__Draw                                              0x71D080
#define CTabWnd__DrawCurrentPage                                   0x71CA90
#define CTabWnd__DrawTab                                           0x71C870
#define CTabWnd__GetCurrentPage                                    0x71CD10
#define CTabWnd__GetPageClientRect                                 0x71C540
#define CTabWnd__GetPageFromTabIndex                               0x71C7A0
#define CTabWnd__GetPageInnerRect                                  0x71C5A0
#define CTabWnd__GetTabInnerRect                                   0x71C720
#define CTabWnd__GetTabRect                                        0x71C630
#define CTabWnd__InsertPage                                        0x71D310
#define CTabWnd__SetPage                                           0x71CD50
#define CTabWnd__SetPageRect                                       0x71CFB0
#define CTabWnd__UpdatePage                                        0x71D290

// CTextOverlay
#define CTextOverlay__DisplayText                                  0x4174D0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6FB7C0

// CXMLDataManager
#define CXMLDataManager__GetXMLData                                0x71DF20

// CXMLSOMDocumentBase
#define CXMLSOMDocumentBase__XMLRead                               0x6EBD30

// CXRect
#define CXRect__CenterPoint                                        0x58C1F0

// CXStr
// WARNING:  Be sure that none of these offsets are identical!
//
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor.
#define CXStr__CXStr                                               0x415830
#define CXStr__CXStr1                                              0x67A1B0
#define CXStr__CXStr3                                              0x6DD910
#define CXStr__dCXStr                                              0x467F20
#define CXStr__operator_equal1                                     0x6DDAD0
#define CXStr__operator_plus_equal1                                0x6DEB10

// CXWnd
#define CXWnd__BringToTop                                          0x6F21C0
#define CXWnd__Center                                              0x6F6A00
#define CXWnd__ClrFocus                                            0x6F1FE0
#define CXWnd__DoAllDrawing                                        0x6F7850
#define CXWnd__DrawChildren                                        0x6F79A0
#define CXWnd__DrawColoredRect                                     0x6F24A0
#define CXWnd__DrawTooltip                                         0x6F76A0
#define CXWnd__DrawTooltipAtPoint                                  0x6F67B0
#define CXWnd__GetBorderFrame                                      0x6F28E0
#define CXWnd__GetChildWndAt                                       0x6F5FE0
#define CXWnd__GetClientClipRect                                   0x6F2760
#define CXWnd__GetScreenClipRect                                   0x6F6C20
#define CXWnd__GetScreenRect                                       0x6F2A70
#define CXWnd__GetTooltipRect                                      0x6F25B0
#define CXWnd__GetWindowTextA                                      0x57A850
#define CXWnd__IsActive                                            0x6FC930
#define CXWnd__IsDescendantOf                                      0x6F2810
#define CXWnd__IsReallyVisible                                     0x6F5FC0
#define CXWnd__IsType                                              0x720D00
#define CXWnd__Move                                                0x6F5780
#define CXWnd__Move1                                               0x6F7480
#define CXWnd__ProcessTransition                                   0x6F2170
#define CXWnd__Refade                                              0x6F20F0
#define CXWnd__Resize                                              0x6F2B40
#define CXWnd__Right                                               0x6F6B60
#define CXWnd__SetFocus                                            0x6F4350
#define CXWnd__SetKeyTooltip                                       0x6F2D20
#define CXWnd__SetMouseOver                                        0x6F6EB0
#define CXWnd__StartFade                                           0x6F2200
#define CXWnd__GetChildItem                                        0x6F6E30

// CXWndManager
#define CXWndManager__DrawCursor                                   0x6FDF00
#define CXWndManager__DrawWindows                                  0x6FDB80
#define CXWndManager__GetKeyboardFlags                             0x6FC580
#define CXWndManager__HandleKeyboardMsg                            0x6FCC00
#define CXWndManager__RemoveWnd                                    0x6FCA50

// CDBStr
#define CDBStr__GetString                                          0x462F50

// EQ_Character
#define EQ_Character__CastRay                                      0x74BA40
#define EQ_Character__CastSpell                                    0x42DBD0
#define EQ_Character__Cur_HP                                       0x436DF0
#define EQ_Character__GetAACastingTimeModifier                     0x423AA0
#define EQ_Character__GetCharInfo2                                 0x6BBC70
#define EQ_Character__GetFocusCastingTimeModifier                  0x41F2F0
#define EQ_Character__GetFocusRangeModifier                        0x41F430
#define EQ_Character__Max_Endurance                                0x51FE60
#define EQ_Character__Max_HP                                       0x431FD0
#define EQ_Character__Max_Mana                                     0x51FC90
#define EQ_Character__doCombatAbility                              0x51EBA0
#define EQ_Character__UseSkill                                     0x440DA0
#define EQ_Character__GetConLevel                                  0x51AEA0

// EQ_Item
#define EQ_Item__CanDrop                                           0x5085A0
#define EQ_Item__GetItemLinkHash                                   0x6AE5C0
#define EQ_Item__IsStackable                                       0x6A53F0

// EQ_LoadingS
#define EQ_LoadingS__SetProgressBar                                0x47BC00
#define EQ_LoadingS__Array                                         0x89FD78

// EQ_PC
#define EQ_PC__DestroyHeldItemOrMoney                              0x522CF0
#define EQ_PC__GetAltAbilityIndex                                  0x6B3930
#define EQ_PC__GetCombatAbility                                    0x6B39C0
#define EQ_PC__GetCombatAbilityTimer                               0x6B3A70
#define EQ_PC__GetItemTimerValue                                   0x51DAD0
#define EQ_PC__HasLoreItem                                         0x5211B0

// EQItemList
#define EQItemList__dEQItemList                                    0x4A77B0
#define EQItemList__EQItemList                                     0x4A7700

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x4628B0

// EQPlayer
#define EQPlayer__ChangeBoneStringSprite                           0x5276A0
#define EQPlayer__dEQPlayer                                        0x52B850
#define EQPlayer__DoAttack                                         0x5397E0
#define EQPlayer__EQPlayer                                         0x52F5B0
#define EQPlayer__SetNameSpriteState                               0x5297B0
#define EQPlayer__SetNameSpriteTint                                0x527710
#define EQPlayer__IsBodyType_j                                     0x74B350
#define EQPlayer__IsTargetable                                     0x74B4E0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x530760
#define EQPlayerManager__GetSpawnByName                            0x530A40

// KeyPressHandler
#define KeypressHandler__AttachAltKeyToEqCommand                   0x50A220
#define KeypressHandler__AttachKeyToEqCommand                      0x50A260
#define KeypressHandler__ClearCommandStateArray                    0x50A030
#define KeypressHandler__HandleKeyDown                             0x508BB0
#define KeypressHandler__HandleKeyUp                               0x508EC0
#define KeypressHandler__SaveKeymapping                            0x50A100

// MapViewMap
#define MapViewMap__Clear                                          0x60CFF0
#define MapViewMap__SaveEx                                         0x60D9C0

#define OtherCharData__GetAltCurrency                              0x6D3540

// StringTable
#define StringTable__getString                                     0x6A4D90
