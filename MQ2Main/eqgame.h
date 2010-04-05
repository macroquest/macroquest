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
#define __ExpectedVersionDate                                     "Jun 18 2009"
#define __ExpectedVersionTime                                     "06:20:28"
#define __ActualVersionDate                                        0x7EAAAC
#define __ActualVersionTime                                        0x7EAAB8

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x50D990
#define __MemChecker1                                              0x6BFE00
#define __MemChecker2                                              0x56A970
#define __MemChecker3                                              0x56A8C0
#define __MemChecker4                                              0x681CF0
#define __EncryptPad0                                              0x871758
#define __EncryptPad1                                              0x87BEC0
#define __EncryptPad2                                              0x8741D0
#define __EncryptPad3                                              0x873DD0
#define __EncryptPad4                                              0x87B590
#define __AC1                                                      0x64A530
#define __AC2                                                      0x4DA525
#define __AC3                                                      0x4ED6D8
#define __AC4                                                      0x4F1468
#define __AC5                                                      0x4FB948
#define __AC6                                                      0x4FEC0B
#define __AC7                                                      0x4F7EA4
#define __AC1_Data                                                 0x7D3F7A

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
#define __do_loot                                                  0x4B40D0
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
#define pinstCVoiceMacroWnd                                        0xAD0720
#define pinstCHtmlWnd                                              0xAD075C


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4C7460
#define __ConvertItemTags                                          0x4B94E0
#define __ExecuteCmd                                               0x4A7B60
#define __get_melee_range                                          0x4AD1F0
#define __GetGaugeValueFromEQ                                      0x649770
#define __GetLabelFromEQ                                           0x64A4D0
#define __NewUIINI                                                 0x649300
#define __ProcessGameEvents                                        0x4F8290
#define CrashDetected                                              0x569640
#define DrawNetStatus                                              0x5160B0
#define Util__FastTime                                             0x6C0510


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x480670
#define AltAdvManager__IsAbilityReady                              0x4806B0
#define AltAdvManager__GetAltAbility                               0x4808C0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5815E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x58AA60

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6EE6D0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5A07C0
#define CChatManager__InitContextMenu                              0x5A0F60

// CChatService
#define CChatService__GetNumberOfFriends                           0x6B0400
#define CChatService__GetFriendName                                0x6B0410

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5A5140
#define CChatWindow__Clear                                         0x5A5AB0
#define CChatWindow__WndNotification                               0x5A5B90

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6D8ED0
#define CComboWnd__Draw                                            0x6D9080
#define CComboWnd__GetCurChoice                                    0x6D8E70
#define CComboWnd__GetListRect                                     0x6D9340
#define CComboWnd__GetTextRect                                     0x6D8F00
#define CComboWnd__InsertChoice                                    0x6D93B0
#define CComboWnd__SetColors                                       0x6D8E00
#define CComboWnd__SetChoice                                       0x6D8E30

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5ACD40
#define CContainerWnd__vftable                                     0x7F1660

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46F040
#define CDisplay__GetClickedActor                                  0x46C790
#define CDisplay__GetUserDefinedColor                              0x46B8B0
#define CDisplay__GetWorldFilePath                                 0x46ADB0
#define CDisplay__is3dON                                           0x469F20
#define CDisplay__ReloadUI                                         0x47D850
#define CDisplay__WriteTextHD2                                     0x46F7C0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x57B5D0
#define CEditBaseWnd__SetSel                                       0x6F9B10

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6E1A90
#define CEditWnd__GetCharIndexPt                                   0x6E28D0
#define CEditWnd__GetDisplayString                                 0x6E1C20
#define CEditWnd__GetHorzOffset                                    0x6E1EB0
#define CEditWnd__GetLineForPrintableChar                          0x6E2380
#define CEditWnd__GetSelStartPt                                    0x6E2B10
#define CEditWnd__GetSTMLSafeText                                  0x6E2040
#define CEditWnd__PointFromPrintableChar                           0x6E2490
#define CEditWnd__SelectableCharFromPoint                          0x6E2610
#define CEditWnd__SetEditable                                      0x6E2010

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4DAC00
#define CEverQuest__DropHeldItemOnGround                           0x4DEC70
#define CEverQuest__dsp_chat                                       0x4E0170
#define CEverQuest__DoTellWindow                                   0x4DEDF0
#define CEverQuest__EnterZone                                      0x4F1400
#define CEverQuest__GetBodyTypeDesc                                0x4D7E80
#define CEverQuest__GetClassDesc                                   0x4D76C0
#define CEverQuest__GetClassThreeLetterCode                        0x4D7CC0
#define CEverQuest__GetDeityDesc                                   0x4D84F0
#define CEverQuest__GetLangDesc                                    0x4D8210
#define CEverQuest__GetRaceDesc                                    0x4D84C0
#define CEverQuest__InterpretCmd                                   0x4E0C00
#define CEverQuest__LeftClickedOnPlayer                            0x4F2D20
#define CEverQuest__LMouseUp                                       0x4F6600
#define CEverQuest__RightClickedOnPlayer                           0x4F6EA0
#define CEverQuest__RMouseUp                                       0x4F7E60
#define CEverQuest__SetGameState                                   0x4DB090
#define CEverQuest__Emote                                          0x4E0360

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5B9740
#define CGaugeWnd__CalcLinesFillRect                               0x5B97A0
#define CGaugeWnd__Draw                                            0x5B9BB0

// CGuild
#define CGuild__FindMemberByName                                   0x421500

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5D1DA0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5DB3D0
#define CInvSlotMgr__MoveItem                                      0x5DB570

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5DAC60
#define CInvSlot__SliderComplete                                   0x5D9DB0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5EA1F0
#define CItemDisplayWnd__SetSpell                                  0x647480

// CLabel 
#define CLabel__Draw                                               0x5EFAC0

// CListWnd 
#define CListWnd__AddColumn                                        0x6D3700
#define CListWnd__AddColumn1                                       0x6D31E0
#define CListWnd__AddLine                                          0x6D2CD0
#define CListWnd__AddString                                        0x6D2EC0
#define CListWnd__CalculateFirstVisibleLine                        0x6CFF90
#define CListWnd__CalculateVSBRange                                0x6D1D30
#define CListWnd__ClearAllSel                                      0x6CF6C0
#define CListWnd__CloseAndUpdateEditWindow                         0x6D05B5
#define CListWnd__Compare                                          0x6D0930
#define CListWnd__Draw                                             0x6D1A20
#define CListWnd__DrawColumnSeparators                             0x6D1890
#define CListWnd__DrawHeader                                       0x6CF890
#define CListWnd__DrawItem                                         0x6D11C0
#define CListWnd__DrawLine                                         0x6D1530
#define CListWnd__DrawSeparator                                    0x6D1930
#define CListWnd__EnsureVisible                                    0x6CFFE0
#define CListWnd__ExtendSel                                        0x6D10E0
#define CListWnd__GetColumnMinWidth                                0x6CF450
#define CListWnd__GetColumnWidth                                   0x6CF390
#define CListWnd__GetCurSel                                        0x6CEDA0
#define CListWnd__GetHeaderRect                                    0x6CEF10
#define CListWnd__GetItemAtPoint                                   0x6D02C0
#define CListWnd__GetItemAtPoint1                                  0x6D0330
#define CListWnd__GetItemData                                      0x6CF140
#define CListWnd__GetItemHeight                                    0x6CFD20
#define CListWnd__GetItemIcon                                      0x6CF2D0
#define CListWnd__GetItemRect                                      0x6D00B0
#define CListWnd__GetItemText                                      0x6CF180
#define CListWnd__GetSelList                                       0x6D30C0
#define CListWnd__GetSeparatorRect                                 0x6D0870
#define CListWnd__RemoveLine                                       0x6D3070
#define CListWnd__SetColors                                        0x6CEE70
#define CListWnd__SetColumnJustification                           0x6CF530
#define CListWnd__SetColumnWidth                                   0x6CF410
#define CListWnd__SetCurSel                                        0x6CEDE0
#define CListWnd__SetItemColor                                     0x6D2940
#define CListWnd__SetItemData                                      0x6CF760
#define CListWnd__SetItemText                                      0x6D28C0
#define CListWnd__ShiftColumnSeparator                             0x6D1050
#define CListWnd__Sort                                             0x6D3740
#define CListWnd__ToggleSel                                        0x6CF630

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x604D30

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x610260
#define CMerchantWnd__RequestBuyItem                               0x611AD0
#define CMerchantWnd__RequestSellItem                              0x611EF0
#define CMerchantWnd__SelectBuySellSlot                            0x610FA0

// CObfuscator
#define CObfuscator__doit                                          0x68B400

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6E9E80
#define CSidlManager__CreateLabel                                  0x640430

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x6DAAC0
#define CSidlScreenWnd__CalculateVSBRange                          0x6EFCB0
#define CSidlScreenWnd__ConvertToRes                               0x6F99F0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6DAF40
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6DC010
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6DC0C0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6DB7E0
#define CSidlScreenWnd__DrawSidlPiece                              0x6DAC10
#define CSidlScreenWnd__EnableIniStorage                           0x6DA7B0
#define CSidlScreenWnd__GetSidlPiece                               0x6DAE10
#define CSidlScreenWnd__Init1                                      0x6DBE80
#define CSidlScreenWnd__LoadIniInfo                                0x6DAFF0
#define CSidlScreenWnd__LoadIniListWnd                             0x6DA900
#define CSidlScreenWnd__LoadSidlScreen                             0x6DBA30
#define CSidlScreenWnd__StoreIniInfo                               0x6DA3C0
#define CSidlScreenWnd__WndNotification                            0x6DBC00
#define CSidlScreenWnd__GetChildItem                               0x6DA810

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x5389A0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6FAEA0
#define CSliderWnd__SetValue                                       0x6FAFA0
#define CSliderWnd__SetNumTicks                                    0x6FB510

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x645210

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6F7C80
#define CStmlWnd__CalculateVSBRange                                0x6EFCB0
#define CStmlWnd__CanBreakAtCharacter                              0x6EFDF0
#define CStmlWnd__FastForwardToEndOfTag                            0x6F09B0
#define CStmlWnd__ForceParseNow                                    0x6F8100
#define CStmlWnd__GetNextTagPiece                                  0x6F08D0
#define CStmlWnd__GetSTMLText                                      0x5A50E0
#define CStmlWnd__GetThisChar                                      0x71D540
#define CStmlWnd__GetVisiableText                                  0x6F1BD0
#define CStmlWnd__InitializeWindowVariables                        0x6F3DA0
#define CStmlWnd__MakeStmlColorTag                                 0x6EF330
#define CStmlWnd__MakeWndNotificationTag                           0x6EF3D0
#define CStmlWnd__SetSTMLText                                      0x6F3ED0
#define CStmlWnd__StripFirstSTMLLines                              0x6F7A10
#define CStmlWnd__UpdateHistoryString                              0x6F2440

// CTabWnd 
#define CTabWnd__Draw                                              0x6FC2A0
#define CTabWnd__DrawCurrentPage                                   0x6FBCC0
#define CTabWnd__DrawTab                                           0x6FBAA0
#define CTabWnd__GetCurrentPage                                    0x6FBF40
#define CTabWnd__GetPageClientRect                                 0x6FB770
#define CTabWnd__GetPageFromTabIndex                               0x6FB9D0
#define CTabWnd__GetPageInnerRect                                  0x6FB7D0
#define CTabWnd__GetTabInnerRect                                   0x6FB950
#define CTabWnd__GetTabRect                                        0x6FB860
#define CTabWnd__InsertPage                                        0x6FC510
#define CTabWnd__SetPage                                           0x6FBF80
#define CTabWnd__SetPageRect                                       0x6FC1D0
#define CTabWnd__UpdatePage                                        0x6FC490

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x41DAD0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6DC420

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x700860

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6CEA90

// CXRect 
#define CXRect__CenterPoint                                        0x580C70

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x41BD90
#define CXStr__CXStr1                                              0x79ABA0
#define CXStr__CXStr3                                              0x6C1B90
#define CXStr__dCXStr                                              0x507840
#define CXStr__operator_equal1                                     0x6C1D50
#define CXStr__operator_plus_equal1                                0x6C2C50

// CXWnd 
#define CXWnd__BringToTop                                          0x6D3E20
#define CXWnd__Center                                              0x6D78B0
#define CXWnd__ClrFocus                                            0x6D3B40
#define CXWnd__DoAllDrawing                                        0x6D8670
#define CXWnd__DrawChildren                                        0x6D87A0
#define CXWnd__DrawColoredRect                                     0x6D40A0
#define CXWnd__DrawTooltip                                         0x6D8490
#define CXWnd__DrawTooltipAtPoint                                  0x6D7670
#define CXWnd__GetBorderFrame                                      0x6D4580
#define CXWnd__GetChildWndAt                                       0x6D71B0
#define CXWnd__GetClientClipRect                                   0x6D4490
#define CXWnd__GetScreenClipRect                                   0x6D7AD0
#define CXWnd__GetScreenRect                                       0x6D4720
#define CXWnd__GetTooltipRect                                      0x6D42F0
#define CXWnd__GetWindowTextA                                      0x574310
#define CXWnd__IsActive                                            0x6DD530
#define CXWnd__IsDescendantOf                                      0x6D4510
#define CXWnd__IsReallyVisible                                     0x6D7190
#define CXWnd__IsType                                              0x6FD770
#define CXWnd__Move                                                0x6D6D70
#define CXWnd__Move1                                               0x6D82F0
#define CXWnd__ProcessTransition                                   0x6D3DE0
#define CXWnd__Refade                                              0x6D3BF0
#define CXWnd__Resize                                              0x6D47F0
#define CXWnd__Right                                               0x6D7A10
#define CXWnd__SetFocus                                            0x6D5FA0
#define CXWnd__SetKeyTooltip                                       0x6D4A00
#define CXWnd__SetMouseOver                                        0x6D49D0
#define CXWnd__StartFade                                           0x6D3E60
#define CXWnd__GetChildItem                                        0x6D7C40

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6DE9E0
#define CXWndManager__DrawWindows                                  0x6DE5F0
#define CXWndManager__GetKeyboardFlags                             0x6DD1E0
#define CXWndManager__HandleKeyboardMsg                            0x6DD730
#define CXWndManager__RemoveWnd                                    0x6DD650

// CDBStr
#define CDBStr__GetString                                          0x468870

// EQ_Character 
#define EQ_Character__CastRay                                      0x7295E0
#define EQ_Character__CastSpell                                    0x433ED0
#define EQ_Character__Cur_HP                                       0x43D510
#define EQ_Character__GetAACastingTimeModifier                     0x429E50
#define EQ_Character__GetCharInfo2                                 0x6A1590
#define EQ_Character__GetFocusCastingTimeModifier                  0x4257C0
#define EQ_Character__GetFocusRangeModifier                        0x425900
#define EQ_Character__Max_Endurance                                0x51C200
#define EQ_Character__Max_HP                                       0x438410
#define EQ_Character__Max_Mana                                     0x51C030
#define EQ_Character__doCombatAbility                              0x51AF40
#define EQ_Character__UseSkill                                     0x446C30
#define EQ_Character__GetConLevel                                  0x5174F0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x505250
#define EQ_Item__GetItemLinkHash                                   0x694EA0
#define EQ_Item__IsStackable                                       0x68BCE0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x481790
#define EQ_LoadingS__Array                                         0x86AB80

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x51F070
#define EQ_PC__GetAltAbilityIndex                                  0x699980
#define EQ_PC__GetCombatAbility                                    0x699A10
#define EQ_PC__GetCombatAbilityTimer                               0x699AC0
#define EQ_PC__GetItemTimerValue                                   0x519E80
#define EQ_PC__HasLoreItem                                         0x51D540

// EQItemList 
#define EQItemList__dEQItemList                                    0x4AB740
#define EQItemList__EQItemList                                     0x4AB690

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x468200

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x5238C0
#define EQPlayer__dEQPlayer                                        0x527920
#define EQPlayer__DoAttack                                         0x534AE0
#define EQPlayer__EQPlayer                                         0x52B630
#define EQPlayer__SetNameSpriteState                               0x525890
#define EQPlayer__SetNameSpriteTint                                0x523930
#define EQPlayer__IsBodyType_j                                     0x728EF0
#define EQPlayer__IsTargetable                                     0x729080

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x52C730
#define EQPlayerManager__GetSpawnByName                            0x52CA10

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x506F20
#define KeypressHandler__AttachKeyToEqCommand                      0x506F60
#define KeypressHandler__ClearCommandStateArray                    0x506D30
#define KeypressHandler__HandleKeyDown                             0x5058B0
#define KeypressHandler__HandleKeyUp                               0x505BC0
#define KeypressHandler__SaveKeymapping                            0x506E00

// MapViewMap 
#define MapViewMap__Clear                                          0x600400
#define MapViewMap__SaveEx                                         0x600DD0

#define OtherCharData__GetAltCurrency                              0x6B8BD0

// StringTable 
#define StringTable__getString                                     0x68B680
