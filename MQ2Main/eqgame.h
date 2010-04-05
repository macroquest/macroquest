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
#define __ExpectedVersionDate                                     "Jun 23 2009"
#define __ExpectedVersionTime                                     "17:53:49"
#define __ActualVersionDate                                        0x7EAA9C
#define __ActualVersionTime                                        0x7EAAA8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x50DAD0
#define __MemChecker1                                              0x6C0270
#define __MemChecker2                                              0x56AD70
#define __MemChecker3                                              0x56ACC0
#define __MemChecker4                                              0x682170
#define __EncryptPad0                                              0x871758
#define __EncryptPad1                                              0x87BEC0
#define __EncryptPad2                                              0x8741D0
#define __EncryptPad3                                              0x873DD0
#define __EncryptPad4                                              0x87B590
#define __AC1                                                      0x64A9B0
#define __AC2                                                      0x4DA635
#define __AC3                                                      0x4ED7E8
#define __AC4                                                      0x4F1578
#define __AC5                                                      0x4FBA58
#define __AC6                                                      0x4FED1B
#define __AC7                                                      0x4F7FB4
#define __AC1_Data                                                 0x7D43BA

// Direct Input
#define DI8__Main                                                  0xAD371C
#define DI8__Keyboard                                              0xAD3720
#define DI8__Mouse                                                 0xAD3724
#define __AltTimerReady                                            0xA5E036
#define __Attack                                                   0xABDB22
#define __Autofire                                                 0xABDB23
#define __BindList                                                 0x86C6B0
#define __Clicks                                                   0xA5CD48
#define __CommandList                                              0x86CF30
#define __CurrentMapLabel                                          0xAFE958
#define __CurrentSocial                                            0x8686BC
#define __DoAbilityAvailable                                       0xA5DFD0
#define __DoAbilityList                                            0xA935E8
#define __do_loot                                                  0x4B4210
#define __DrawHandler                                              0xB0DDC4
#define __GroupCount                                               0xA57002
#define __Guilds                                                   0xA58B80
#define __gWorld                                                   0xA58AC0
#define __HotkeyPage                                               0xABA9D4
#define __HWnd                                                     0xAD345C
#define __InChatMode                                               0xA5CC80
#define __LastTell                                                 0xA5E940
#define __LMouseHeldTime                                           0xA5CD68
#define __Mouse                                                    0xAD3728
#define __MouseLook                                                0xA5CD16
#define __MouseEventTime                                           0xABDC34
#define __NetStatusToggle                                          0xA5CD19
#define __PCNames                                                  0xA5E384
#define __RangeAttackReady                                         0xA5E034
#define __RMouseHeldTime                                           0xA5CD64
#define __RunWalkState                                             0xA5CC84
#define __ScreenMode                                               0x9A68D0
#define __ScreenX                                                  0xA5CC38
#define __ScreenY                                                  0xA5CC3C
#define __ScreenXMax                                               0xA5CC40
#define __ScreenYMax                                               0xA5CC44
#define __ServerHost                                               0xA56F44
#define __ServerName                                               0xA935A8
#define __ShiftKeyDown                                             0xA5D2E8
#define __ShowNames                                                0xA5E260
#define __Socials                                                  0xA936A8


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA590E0
#define instEQZoneInfo                                             0xA5CEB4
#define instKeypressHandler                                        0xABDC18
#define pinstActiveBanker                                          0xA58B58
#define pinstActiveCorpse                                          0xA58B5C
#define pinstActiveGMaster                                         0xA58B60
#define pinstActiveMerchant                                        0xA58B54
#define pinstAltAdvManager                                         0x9A7730
#define pinstAuraMgr                                               0x890194
#define pinstBandageTarget                                         0xA58B40
#define pinstCamActor                                              0x9A7220
#define pinstCDBStr                                                0x9A68C0
#define pinstCDisplay                                              0xA58B68
#define pinstCEverQuest                                            0xAD38A0
#define pinstCharData                                              0xA58B24
#define pinstCharSpawn                                             0xA58B4C
#define pinstControlledMissile                                     0xA58B20
#define pinstControlledPlayer                                      0xA58B4C
#define pinstCSidlManager                                          0xB0D548
#define pinstCXWndManager                                          0xB0D540
#define instDynamicZone                                            0xA5C688
#define pinstDZMember                                              0xA5C798
#define pinstDZTimerInfo                                           0xA5C79C
#define pinstEQItemList                                            0xA58B08
#define instEQMisc                                                 0x9A6878
#define pinstEQSoundManager                                        0x9A7754
#define instExpeditionLeader                                       0xA5C6D2
#define instExpeditionName                                         0xA5C712
#define pinstGroup                                                 0xA56FFE
#define pinstImeManager                                            0xB0D54C
#define pinstLocalPlayer                                           0xA58B38
#define pinstMercenaryData                                         0xABDF90
#define pinstModelPlayer                                           0xA58B64
#define pinstPCData                                                0xA58B24
#define pinstSkillMgr                                              0xAD0530
#define pinstSpawnManager                                          0xAD038C
#define pinstSpellManager                                          0xAD0534
#define pinstSpellSets                                             0xABA9D8
#define pinstStringTable                                           0xA58ADC
#define pinstSwitchManager                                         0xA56C44
#define pinstTarget                                                0xA58B50
#define pinstTargetObject                                          0xA58B28
#define pinstTargetSwitch                                          0xA58B2C
#define pinstTaskMember                                            0x9A6858
#define pinstTrackTarget                                           0xA58B44
#define pinstTradeTarget                                           0xA58B34
#define instTributeActive                                          0x9A689D
#define pinstViewActor                                             0x9A721C
#define pinstWorldData                                             0xA58B04


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x88DA40
#define pinstCAudioTriggersWindow                                  0x88DA0C
#define pinstCCharacterSelect                                      0x9A712C
#define pinstCFacePick                                             0x9A70E0
#define pinstCNoteWnd                                              0x9A70E4
#define pinstCBookWnd                                              0x9A70E8
#define pinstCPetInfoWnd                                           0x9A70EC
#define pinstCTrainWnd                                             0x9A70F0
#define pinstCSkillsWnd                                            0x9A70F4
#define pinstCSkillsSelectWnd                                      0x9A70F8
#define pinstCCombatSkillSelectWnd                                 0x9A70FC
#define pinstCFriendsWnd                                           0x9A7100
#define pinstCAuraWnd                                              0x9A7104
#define pinstCRespawnWnd                                           0x9A7108
#define pinstCBandolierWnd                                         0x9A710C
#define pinstCPotionBeltWnd                                        0x9A7110
#define pinstCAAWnd                                                0x9A7114
#define pinstCGroupSearchFiltersWnd                                0x9A7118
#define pinstCLoadskinWnd                                          0x9A711C
#define pinstCAlarmWnd                                             0x9A7120
#define pinstCMusicPlayerWnd                                       0x9A7124
#define pinstCMailWnd                                              0x9A7130
#define pinstCMailCompositionWnd                                   0x9A7134
#define pinstCMailAddressBookWnd                                   0x9A7138
#define pinstCRaidWnd                                              0x9A7140
#define pinstCRaidOptionsWnd                                       0x9A7144
#define pinstCBreathWnd                                            0x9A7148
#define pinstCMapViewWnd                                           0x9A714C
#define pinstCMapToolbarWnd                                        0x9A7150
#define pinstCEditLabelWnd                                         0x9A7154
#define pinstCTargetWnd                                            0x9A7158
#define pinstCColorPickerWnd                                       0x9A715C
#define pinstCPlayerWnd                                            0x9A7160
#define pinstCOptionsWnd                                           0x9A7164
#define pinstCBuffWindowNORMAL                                     0x9A7168
#define pinstCBuffWindowSHORT                                      0x9A716C
#define pinstCharacterCreation                                     0x9A7170
#define pinstCCursorAttachment                                     0x9A7174
#define pinstCCastingWnd                                           0x9A7178
#define pinstCCastSpellWnd                                         0x9A717C
#define pinstCSpellBookWnd                                         0x9A7180
#define pinstCInventoryWnd                                         0x9A7184
#define pinstCBankWnd                                              0x9A7188
#define pinstCQuantityWnd                                          0x9A718C
#define pinstCLootWnd                                              0x9A7190
#define pinstCActionsWnd                                           0x9A7194
#define pinstCCombatAbilityWnd                                     0x9A7198
#define pinstCMerchantWnd                                          0x9A719C
#define pinstCTradeWnd                                             0x9A71A0
#define pinstCSelectorWnd                                          0x9A71A4
#define pinstCBazaarWnd                                            0x9A71A8
#define pinstCBazaarSearchWnd                                      0x9A71AC
#define pinstCGiveWnd                                              0x9A71B0
#define pinstCTrackingWnd                                          0x9A71B4
#define pinstCInspectWnd                                           0x9A71B8
#define pinstCSocialEditWnd                                        0x9A71BC
#define pinstCFeedbackWnd                                          0x9A71C0
#define pinstCBugReportWnd                                         0x9A71C4
#define pinstCVideoModesWnd                                        0x9A71C8
#define pinstCTextEntryWnd                                         0x9A71D0
#define pinstCFileSelectionWnd                                     0x9A71D4
#define pinstCCompassWnd                                           0x9A71D8
#define pinstCPlayerNotesWnd                                       0x9A71DC
#define pinstCGemsGameWnd                                          0x9A71E0
#define pinstCTimeLeftWnd                                          0x9A71E4
#define pinstCPetitionQWnd                                         0x9A71EC
#define pinstCSoulmarkWnd                                          0x9A71F0
#define pinstCStoryWnd                                             0x9A71F4
#define pinstCJournalTextWnd                                       0x9A71F8
#define pinstCJournalCatWnd                                        0x9A71FC
#define pinstCBodyTintWnd                                          0x9A7200
#define pinstCServerListWnd                                        0x9A7204
#define pinstCAvaZoneWnd                                           0x9A7208
#define pinstCBlockedBuffWnd                                       0x9A720C
#define pinstCBlockedPetBuffWnd                                    0x9A7210
#define pinstCInvSlotMgr                                           0x9A7214
#define pinstCContainerMgr                                         0x9A7218
#define pinstCAdventureLeaderboardWnd                              0xAFBE88
#define pinstCAdventureRequestWnd                                  0xAFBEA4
#define pinstCAltStorageWnd                                        0xAFBF04
#define pinstCAdventureStatsWnd                                    0xAFBEC0
#define pinstCBarterMerchantWnd                                    0xAFC0D0
#define pinstCBarterSearchWnd                                      0xAFC0EC
#define pinstCBarterWnd                                            0xAFC108
#define pinstCChatManager                                          0xAFC3AC
#define pinstCDynamicZoneWnd                                       0xAFC4A4
#define pinstCEQMainWnd                                            0xAFC518
#define pinstCFellowshipWnd                                        0xAFC57C
#define pinstCFindLocationWnd                                      0xAFC5B0
#define pinstCGroupSearchWnd                                       0xAFC660
#define pinstCGroupWnd                                             0xAFC67C
#define pinstCGuildBankWnd                                         0xAFC698
#define pinstCGuildMgmtWnd                                         0xAFE6D0
#define pinstCGuildTributeMasterWnd                                0xAFE6F0
#define pinstCHotButtonWnd                                         0xAFE70C
#define pinstCHotButtonWnd1                                        0xAFE70C
#define pinstCHotButtonWnd2                                        0xAFE710
#define pinstCHotButtonWnd3                                        0xAFE714
#define pinstCHotButtonWnd4                                        0xAFE718
#define pinstCItemDisplayManager                                   0xAFE7C4
#define pinstCItemExpTransferWnd                                   0xAFE7E4
#define pinstCLeadershipWnd                                        0xAFE880
#define pinstCLFGuildWnd                                           0xAFE89C
#define pinstCMIZoneSelectWnd                                      0xAFEA0C
#define pinstCAdventureMerchantWnd                                 0xAFEB04
#define pinstCConfirmationDialog                                   0xAFEB20
#define pinstCPopupWndManager                                      0xAFEB20
#define pinstCProgressionSelectionWnd                              0xAFEB54
#define pinstCPvPLeaderboardWnd                                    0xAFEB70
#define pinstCPvPStatsWnd                                          0xAFEB8C
#define pinstCSystemInfoDialogBox                                  0xAFEC40
#define pinstCTargetOfTargetWnd                                    0xAFF54C
#define pinstCTaskSelectWnd                                        0xAFF580
#define pinstCTaskTemplateSelectWnd                                0xAFF59C
#define pinstCTaskWnd                                              0xAFF5B8
#define pinstCTipWndOFDAY                                          0xAFF634
#define pinstCTipWndCONTEXT                                        0xAFF638
#define pinstCTitleWnd                                             0xAFF654
#define pinstCTradeskillWnd                                        0xAFF698
#define pinstCTributeBenefitWnd                                    0xAFF6E4
#define pinstCTributeMasterWnd                                     0xAFF700
#define pinstCContextMenuManager                                   0xB0D5A4
#define pinstCVoiceMacroWnd                                        0xAD0724
#define pinstCHtmlWnd                                              0xAD0760


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4C75D0
#define __ConvertItemTags                                          0x4B9620
#define __ExecuteCmd                                               0x4A7CB0
#define __get_melee_range                                          0x4AD330
#define __GetGaugeValueFromEQ                                      0x649BF0
#define __GetLabelFromEQ                                           0x64A950
#define __LoadFrontEnd                                             0x569C40
#define __NewUIINI                                                 0x649780
#define __ProcessGameEvents                                        0x4F83A0
#define CrashDetected                                              0x569A40
#define DrawNetStatus                                              0x516210
#define Util__FastTime                                             0x6C0980


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x4807B0
#define AltAdvManager__IsAbilityReady                              0x4807F0
#define AltAdvManager__GetAltAbility                               0x4809D0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5819A0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x58B210

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6EEAA0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5A0DA0
#define CChatManager__InitContextMenu                              0x5A1540

// CChatService
#define CChatService__GetNumberOfFriends                           0x6B0890
#define CChatService__GetFriendName                                0x6B08A0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5A5720
#define CChatWindow__Clear                                         0x5A6090
#define CChatWindow__WndNotification                               0x5A6170

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6D9360
#define CComboWnd__Draw                                            0x6D9510
#define CComboWnd__GetCurChoice                                    0x6D9300
#define CComboWnd__GetListRect                                     0x6D97D0
#define CComboWnd__GetTextRect                                     0x6D9390
#define CComboWnd__InsertChoice                                    0x6D9840
#define CComboWnd__SetColors                                       0x6D9290
#define CComboWnd__SetChoice                                       0x6D92C0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5AD310
#define CContainerWnd__vftable                                     0x7F1650

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46F1B0
#define CDisplay__GetClickedActor                                  0x46C8D0
#define CDisplay__GetUserDefinedColor                              0x46B9F0
#define CDisplay__GetWorldFilePath                                 0x46AEF0
#define CDisplay__is3dON                                           0x46A060
#define CDisplay__ReloadUI                                         0x47D9C0
#define CDisplay__WriteTextHD2                                     0x46F930

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x57B9A0
#define CEditBaseWnd__SetSel                                       0x6F9E90

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6E1EF0
#define CEditWnd__GetCharIndexPt                                   0x6E2D30
#define CEditWnd__GetDisplayString                                 0x6E2080
#define CEditWnd__GetHorzOffset                                    0x6E2310
#define CEditWnd__GetLineForPrintableChar                          0x6E27E0
#define CEditWnd__GetSelStartPt                                    0x6E2F70
#define CEditWnd__GetSTMLSafeText                                  0x6E24A0
#define CEditWnd__PointFromPrintableChar                           0x6E28F0
#define CEditWnd__SelectableCharFromPoint                          0x6E2A70
#define CEditWnd__SetEditable                                      0x6E2470

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4DAD10
#define CEverQuest__DropHeldItemOnGround                           0x4DED80
#define CEverQuest__dsp_chat                                       0x4E0280
#define CEverQuest__DoTellWindow                                   0x4DEF00
#define CEverQuest__EnterZone                                      0x4F1510
#define CEverQuest__GetBodyTypeDesc                                0x4D7F90
#define CEverQuest__GetClassDesc                                   0x4D77D0
#define CEverQuest__GetClassThreeLetterCode                        0x4D7DD0
#define CEverQuest__GetDeityDesc                                   0x4D8600
#define CEverQuest__GetLangDesc                                    0x4D8320
#define CEverQuest__GetRaceDesc                                    0x4D85D0
#define CEverQuest__InterpretCmd                                   0x4E0D10
#define CEverQuest__LeftClickedOnPlayer                            0x4F2E30
#define CEverQuest__LMouseUp                                       0x4F6710
#define CEverQuest__RightClickedOnPlayer                           0x4F6FB0
#define CEverQuest__RMouseUp                                       0x4F7F70
#define CEverQuest__SetGameState                                   0x4DB1A0
#define CEverQuest__Emote                                          0x4E0470

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5B9CE0
#define CGaugeWnd__CalcLinesFillRect                               0x5B9D40
#define CGaugeWnd__Draw                                            0x5BA150

// CGuild
#define CGuild__FindMemberByName                                   0x4215A0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5D2270

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5DB8E0
#define CInvSlotMgr__MoveItem                                      0x5DBA80

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5DB170
#define CInvSlot__SliderComplete                                   0x5DA2C0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5DCA10

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5EA7D0
#define CItemDisplayWnd__SetSpell                                  0x6478F0

// CLabel 
#define CLabel__Draw                                               0x5F00C0

// CListWnd 
#define CListWnd__AddColumn                                        0x6D3B90
#define CListWnd__AddColumn1                                       0x6D3670
#define CListWnd__AddLine                                          0x6D3160
#define CListWnd__AddString                                        0x6D3350
#define CListWnd__CalculateFirstVisibleLine                        0x6D0420
#define CListWnd__CalculateVSBRange                                0x6D21C0
#define CListWnd__ClearAllSel                                      0x6CFB50
#define CListWnd__CloseAndUpdateEditWindow                         0x6D0A45
#define CListWnd__Compare                                          0x6D0DC0
#define CListWnd__Draw                                             0x6D1EB0
#define CListWnd__DrawColumnSeparators                             0x6D1D20
#define CListWnd__DrawHeader                                       0x6CFD20
#define CListWnd__DrawItem                                         0x6D1650
#define CListWnd__DrawLine                                         0x6D19C0
#define CListWnd__DrawSeparator                                    0x6D1DC0
#define CListWnd__EnsureVisible                                    0x6D0470
#define CListWnd__ExtendSel                                        0x6D1570
#define CListWnd__GetColumnMinWidth                                0x6CF8E0
#define CListWnd__GetColumnWidth                                   0x6CF820
#define CListWnd__GetCurSel                                        0x6CF230
#define CListWnd__GetHeaderRect                                    0x6CF3A0
#define CListWnd__GetItemAtPoint                                   0x6D0750
#define CListWnd__GetItemAtPoint1                                  0x6D07C0
#define CListWnd__GetItemData                                      0x6CF5D0
#define CListWnd__GetItemHeight                                    0x6D01B0
#define CListWnd__GetItemIcon                                      0x6CF760
#define CListWnd__GetItemRect                                      0x6D0540
#define CListWnd__GetItemText                                      0x6CF610
#define CListWnd__GetSelList                                       0x6D3550
#define CListWnd__GetSeparatorRect                                 0x6D0D00
#define CListWnd__RemoveLine                                       0x6D3500
#define CListWnd__SetColors                                        0x6CF300
#define CListWnd__SetColumnJustification                           0x6CF9C0
#define CListWnd__SetColumnWidth                                   0x6CF8A0
#define CListWnd__SetCurSel                                        0x6CF270
#define CListWnd__SetItemColor                                     0x6D2DD0
#define CListWnd__SetItemData                                      0x6CFBF0
#define CListWnd__SetItemText                                      0x6D2D50
#define CListWnd__ShiftColumnSeparator                             0x6D14E0
#define CListWnd__Sort                                             0x6D3BD0
#define CListWnd__ToggleSel                                        0x6CFAC0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x605310

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x610850
#define CMerchantWnd__RequestBuyItem                               0x6120B0
#define CMerchantWnd__RequestSellItem                              0x6124D0
#define CMerchantWnd__SelectBuySellSlot                            0x611580

// CObfuscator
#define CObfuscator__doit                                          0x68B950

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6EA2F0
#define CSidlManager__CreateLabel                                  0x640900

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x6DAF50
#define CSidlScreenWnd__CalculateVSBRange                          0x6F0060
#define CSidlScreenWnd__ConvertToRes                               0x6F9D70
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6DB3D0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6DC4A0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6DC550
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6DBC70
#define CSidlScreenWnd__DrawSidlPiece                              0x6DB0A0
#define CSidlScreenWnd__EnableIniStorage                           0x6DAC40
#define CSidlScreenWnd__GetSidlPiece                               0x6DB2A0
#define CSidlScreenWnd__Init1                                      0x6DC310
#define CSidlScreenWnd__LoadIniInfo                                0x6DB480
#define CSidlScreenWnd__LoadIniListWnd                             0x6DAD90
#define CSidlScreenWnd__LoadSidlScreen                             0x6DBEC0
#define CSidlScreenWnd__StoreIniInfo                               0x6DA850
#define CSidlScreenWnd__WndNotification                            0x6DC090
#define CSidlScreenWnd__GetChildItem                               0x6DACA0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x538980

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6FB210
#define CSliderWnd__SetValue                                       0x6FB310
#define CSliderWnd__SetNumTicks                                    0x6FB880

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x645680

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6F8000
#define CStmlWnd__CalculateVSBRange                                0x6F0060
#define CStmlWnd__CanBreakAtCharacter                              0x6F01A0
#define CStmlWnd__FastForwardToEndOfTag                            0x6F0D10
#define CStmlWnd__ForceParseNow                                    0x6F8480
#define CStmlWnd__GetNextTagPiece                                  0x6F0C30
#define CStmlWnd__GetSTMLText                                      0x5A56C0
#define CStmlWnd__GetThisChar                                      0x71D900
#define CStmlWnd__GetVisiableText                                  0x6F1F50
#define CStmlWnd__InitializeWindowVariables                        0x6F4120
#define CStmlWnd__MakeStmlColorTag                                 0x6EF700
#define CStmlWnd__MakeWndNotificationTag                           0x6EF7A0
#define CStmlWnd__SetSTMLText                                      0x6F4250
#define CStmlWnd__StripFirstSTMLLines                              0x6F7D90
#define CStmlWnd__UpdateHistoryString                              0x6F27C0

// CTabWnd 
#define CTabWnd__Draw                                              0x6FC640
#define CTabWnd__DrawCurrentPage                                   0x6FC030
#define CTabWnd__DrawTab                                           0x6FBE10
#define CTabWnd__GetCurrentPage                                    0x6FC2E0
#define CTabWnd__GetPageClientRect                                 0x6FBAE0
#define CTabWnd__GetPageFromTabIndex                               0x6FBD40
#define CTabWnd__GetPageInnerRect                                  0x6FBB40
#define CTabWnd__GetTabInnerRect                                   0x6FBCC0
#define CTabWnd__GetTabRect                                        0x6FBBD0
#define CTabWnd__InsertPage                                        0x6FC8B0
#define CTabWnd__SetPage                                           0x6FC320
#define CTabWnd__SetPageRect                                       0x6FC570
#define CTabWnd__UpdatePage                                        0x6FC830

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x41DB60

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6DC8B0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x700C00

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6CEF20

// CXRect 
#define CXRect__CenterPoint                                        0x581030

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x507690
#define CXStr__CXStr1                                              0x6C9F00
#define CXStr__CXStr3                                              0x6C2000
#define CXStr__dCXStr                                              0x44D5A0
#define CXStr__operator_equal1                                     0x6C21C0
#define CXStr__operator_plus_equal1                                0x6C30C0

// CXWnd 
#define CXWnd__BringToTop                                          0x6D42B0
#define CXWnd__Center                                              0x6D7D40
#define CXWnd__ClrFocus                                            0x6D3FD0
#define CXWnd__DoAllDrawing                                        0x6D8B00
#define CXWnd__DrawChildren                                        0x6D8C30
#define CXWnd__DrawColoredRect                                     0x6D4530
#define CXWnd__DrawTooltip                                         0x6D8920
#define CXWnd__DrawTooltipAtPoint                                  0x6D7B00
#define CXWnd__GetBorderFrame                                      0x6D4A10
#define CXWnd__GetChildWndAt                                       0x6D7640
#define CXWnd__GetClientClipRect                                   0x6D4920
#define CXWnd__GetScreenClipRect                                   0x6D7F60
#define CXWnd__GetScreenRect                                       0x6D4BB0
#define CXWnd__GetTooltipRect                                      0x6D4780
#define CXWnd__GetWindowTextA                                      0x574700
#define CXWnd__IsActive                                            0x6DD9C0
#define CXWnd__IsDescendantOf                                      0x6D49A0
#define CXWnd__IsReallyVisible                                     0x6D7620
#define CXWnd__IsType                                              0x6FDAC0
#define CXWnd__Move                                                0x6D7200
#define CXWnd__Move1                                               0x6D8780
#define CXWnd__ProcessTransition                                   0x6D4270
#define CXWnd__Refade                                              0x6D4080
#define CXWnd__Resize                                              0x6D4C80
#define CXWnd__Right                                               0x6D7EA0
#define CXWnd__SetFocus                                            0x6D6430
#define CXWnd__SetKeyTooltip                                       0x6D4E90
#define CXWnd__SetMouseOver                                        0x6D4E60
#define CXWnd__StartFade                                           0x6D42F0
#define CXWnd__GetChildItem                                        0x6D80D0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6DEE40
#define CXWndManager__DrawWindows                                  0x6DEA50
#define CXWndManager__GetKeyboardFlags                             0x6DD670
#define CXWndManager__HandleKeyboardMsg                            0x6DDBC0
#define CXWndManager__RemoveWnd                                    0x6DDAE0

// CDBStr
#define CDBStr__GetString                                          0x4689E0

// EQ_Character 
#define EQ_Character__CastRay                                      0x729A20
#define EQ_Character__CastSpell                                    0x434030
#define EQ_Character__Cur_HP                                       0x43D6C0
#define EQ_Character__GetAACastingTimeModifier                     0x429FE0
#define EQ_Character__GetCharInfo2                                 0x6A1A30
#define EQ_Character__GetFocusCastingTimeModifier                  0x425930
#define EQ_Character__GetFocusRangeModifier                        0x425A70
#define EQ_Character__Max_Endurance                                0x51C360
#define EQ_Character__Max_HP                                       0x4385C0
#define EQ_Character__Max_Mana                                     0x51C190
#define EQ_Character__doCombatAbility                              0x51B0A0
#define EQ_Character__UseSkill                                     0x446DE0
#define EQ_Character__GetConLevel                                  0x517650

// EQ_Item 
#define EQ_Item__CanDrop                                           0x5053E0
#define EQ_Item__GetItemLinkHash                                   0x6953F0
#define EQ_Item__IsStackable                                       0x68C230

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x4818A0
#define EQ_LoadingS__Array                                         0x86AB80

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x51F1D0
#define EQ_PC__GetAltAbilityIndex                                  0x699E20
#define EQ_PC__GetCombatAbility                                    0x699EB0
#define EQ_PC__GetCombatAbilityTimer                               0x699F60
#define EQ_PC__GetItemTimerValue                                   0x519FE0
#define EQ_PC__HasLoreItem                                         0x51D6A0

// EQItemList 
#define EQItemList__dEQItemList                                    0x4AB890
#define EQItemList__EQItemList                                     0x4AB7E0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x468320

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x523A30
#define EQPlayer__dEQPlayer                                        0x527A90
#define EQPlayer__DoAttack                                         0x534C10
#define EQPlayer__EQPlayer                                         0x52B7A0
#define EQPlayer__SetNameSpriteState                               0x525A00
#define EQPlayer__SetNameSpriteTint                                0x523AA0
#define EQPlayer__IsBodyType_j                                     0x729330
#define EQPlayer__IsTargetable                                     0x7294C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x52C8A0
#define EQPlayerManager__GetSpawnByName                            0x52CB80

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x5070B0
#define KeypressHandler__AttachKeyToEqCommand                      0x5070F0
#define KeypressHandler__ClearCommandStateArray                    0x506EC0
#define KeypressHandler__HandleKeyDown                             0x505A40
#define KeypressHandler__HandleKeyUp                               0x505D50
#define KeypressHandler__SaveKeymapping                            0x506F90

// MapViewMap 
#define MapViewMap__Clear                                          0x6009E0
#define MapViewMap__SaveEx                                         0x6013B0

#define OtherCharData__GetAltCurrency                              0x6B9060

// StringTable 
#define StringTable__getString                                     0x68BBD0
