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
#define __ExpectedVersionDate                                     "May 13 2009"
#define __ExpectedVersionTime                                     "13:00:15"
#define __ActualVersionDate                                        0x7DEFFC
#define __ActualVersionTime                                        0x7DF008

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x50BEF0
#define __MemChecker1                                              0x6B6C10
#define __MemChecker2                                              0x562890
#define __MemChecker3                                              0x5627E0
#define __MemChecker4                                              0x678C40
#define __EncryptPad0                                              0x864710
#define __EncryptPad1                                              0x86EDE8
#define __EncryptPad2                                              0x867168
#define __EncryptPad3                                              0x866D68
#define __EncryptPad4                                              0x86E4B8

// Direct Input
#define DI8__Main                                                  0xAC64B4
#define DI8__Keyboard                                              0xAC64B8
#define DI8__Mouse                                                 0xAC64BC
#define __AltTimerReady                                            0xA50F56
#define __Attack                                                   0xAB09FA
#define __Autofire                                                 0xAB09FB
#define __BindList                                                 0x85F688
#define __Clicks                                                   0xA4FC68
#define __CommandList                                              0x85FEF8
#define __CurrentMapLabel                                          0xAF16F0
#define __CurrentSocial                                            0x85B6A4
#define __DoAbilityAvailable                                       0xA50EF0
#define __DoAbilityList                                            0xA86510
#define __do_loot                                                  0x4B3250
#define __DrawHandler                                              0xB00B5C
#define __GroupCount                                               0xA49F22
#define __Guilds                                                   0xA4BAA0
#define __gWorld                                                   0xA4B9E0
#define __HotkeyPage                                               0xAAD8FC
#define __HWnd                                                     0xAC61F4
#define __InChatMode                                               0xA4FBA0
#define __LastTell                                                 0xA51868
#define __LMouseHeldTime                                           0xA4FC88
#define __Mouse                                                    0xAC64C0
#define __MouseLook                                                0xA4FC36
#define __MouseEventTime                                           0xAB0B04
#define __NetStatusToggle                                          0xA4FC39
#define __PCNames                                                  0xA512AC
#define __RangeAttackReady                                         0xA50F54
#define __RMouseHeldTime                                           0xA4FC84
#define __RunWalkState                                             0xA4FBA4
#define __ScreenMode                                               0x9997F0
#define __ScreenX                                                  0xA4FB58
#define __ScreenY                                                  0xA4FB5C
#define __ScreenXMax                                               0xA4FB60
#define __ScreenYMax                                               0xA4FB64
#define __ServerHost                                               0xA49E64
#define __ServerName                                               0xA864D0
#define __ShiftKeyDown                                             0xA50208
#define __ShowNames                                                0xA51180
#define __Socials                                                  0xA865D0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA4C000
#define instEQZoneInfo                                             0xA4FDD4
#define instKeypressHandler                                        0xAB0AE8
#define pinstActiveBanker                                          0xA4BA78
#define pinstActiveCorpse                                          0xA4BA7C
#define pinstActiveGMaster                                         0xA4BA80
#define pinstActiveMerchant                                        0xA4BA74
#define pinstAltAdvManager                                         0x99A650
#define pinstAuraMgr                                               0x8830B4
#define pinstBandageTarget                                         0xA4BA60
#define pinstCamActor                                              0x99A140
#define pinstCDBStr                                                0x9997E0
#define pinstCDisplay                                              0xA4BA88
#define pinstCEverQuest                                            0xAC6638
#define pinstCharData                                              0xA4BA44
#define pinstCharSpawn                                             0xA4BA6C
#define pinstControlledMissile                                     0xA4BA40
#define pinstControlledPlayer                                      0xA4BA6C
#define pinstCSidlManager                                          0xB002E0
#define pinstCXWndManager                                          0xB002D8
#define instDynamicZone                                            0xA4F5A8
#define pinstDZMember                                              0xA4F6B8
#define pinstDZTimerInfo                                           0xA4F6BC
#define pinstEQItemList                                            0xA4BA28
#define instEQMisc                                                 0x999798
#define pinstEQSoundManager                                        0x99A674
#define instExpeditionLeader                                       0xA4F5F2
#define instExpeditionName                                         0xA4F632
#define pinstGroup                                                 0xA49F1E
#define pinstImeManager                                            0xB002E4
#define pinstLocalPlayer                                           0xA4BA58
#define pinstMercenaryData                                         0xAB0E60
#define pinstModelPlayer                                           0xA4BA84
#define pinstPCData                                                0xA4BA44
#define pinstSkillMgr                                              0xAC32F4
#define pinstSpawnManager                                          0xAC3274
#define pinstSpellManager                                          0xAC32F8
#define pinstSpellSets                                             0xAAD900
#define pinstStringTable                                           0xA4B9FC
#define pinstSwitchManager                                         0xA49B64
#define pinstTarget                                                0xA4BA70
#define pinstTargetObject                                          0xA4BA48
#define pinstTargetSwitch                                          0xA4BA4C
#define pinstTaskMember                                            0x999778
#define pinstTrackTarget                                           0xA4BA64
#define pinstTradeTarget                                           0xA4BA54
#define instTributeActive                                          0x9997BD
#define pinstViewActor                                             0x99A13C
#define pinstWorldData                                             0xA4BA24


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x880960
#define pinstCAudioTriggersWindow                                  0x88092C
#define pinstCCharacterSelect                                      0x99A04C
#define pinstCFacePick                                             0x99A000
#define pinstCNoteWnd                                              0x99A004
#define pinstCBookWnd                                              0x99A008
#define pinstCPetInfoWnd                                           0x99A00C
#define pinstCTrainWnd                                             0x99A010
#define pinstCSkillsWnd                                            0x99A014
#define pinstCSkillsSelectWnd                                      0x99A018
#define pinstCCombatSkillSelectWnd                                 0x99A01C
#define pinstCFriendsWnd                                           0x99A020
#define pinstCAuraWnd                                              0x99A024
#define pinstCRespawnWnd                                           0x99A028
#define pinstCBandolierWnd                                         0x99A02C
#define pinstCPotionBeltWnd                                        0x99A030
#define pinstCAAWnd                                                0x99A034
#define pinstCGroupSearchFiltersWnd                                0x99A038
#define pinstCLoadskinWnd                                          0x99A03C
#define pinstCAlarmWnd                                             0x99A040
#define pinstCMusicPlayerWnd                                       0x99A044
#define pinstCMailWnd                                              0x99A050
#define pinstCMailCompositionWnd                                   0x99A054
#define pinstCMailAddressBookWnd                                   0x99A058
#define pinstCRaidWnd                                              0x99A060
#define pinstCRaidOptionsWnd                                       0x99A064
#define pinstCBreathWnd                                            0x99A068
#define pinstCMapViewWnd                                           0x99A06C
#define pinstCMapToolbarWnd                                        0x99A070
#define pinstCEditLabelWnd                                         0x99A074
#define pinstCTargetWnd                                            0x99A078
#define pinstCColorPickerWnd                                       0x99A07C
#define pinstCPlayerWnd                                            0x99A080
#define pinstCOptionsWnd                                           0x99A084
#define pinstCBuffWindowNORMAL                                     0x99A088
#define pinstCBuffWindowSHORT                                      0x99A08C
#define pinstCharacterCreation                                     0x99A090
#define pinstCCursorAttachment                                     0x99A094
#define pinstCCastingWnd                                           0x99A098
#define pinstCCastSpellWnd                                         0x99A09C
#define pinstCSpellBookWnd                                         0x99A0A0
#define pinstCInventoryWnd                                         0x99A0A4
#define pinstCBankWnd                                              0x99A0A8
#define pinstCQuantityWnd                                          0x99A0AC
#define pinstCLootWnd                                              0x99A0B0
#define pinstCActionsWnd                                           0x99A0B4
#define pinstCCombatAbilityWnd                                     0x99A0B8
#define pinstCMerchantWnd                                          0x99A0BC
#define pinstCTradeWnd                                             0x99A0C0
#define pinstCSelectorWnd                                          0x99A0C4
#define pinstCBazaarWnd                                            0x99A0C8
#define pinstCBazaarSearchWnd                                      0x99A0CC
#define pinstCGiveWnd                                              0x99A0D0
#define pinstCTrackingWnd                                          0x99A0D4
#define pinstCInspectWnd                                           0x99A0D8
#define pinstCSocialEditWnd                                        0x99A0DC
#define pinstCFeedbackWnd                                          0x99A0E0
#define pinstCBugReportWnd                                         0x99A0E4
#define pinstCVideoModesWnd                                        0x99A0E8
#define pinstCTextEntryWnd                                         0x99A0F0
#define pinstCFileSelectionWnd                                     0x99A0F4
#define pinstCCompassWnd                                           0x99A0F8
#define pinstCPlayerNotesWnd                                       0x99A0FC
#define pinstCGemsGameWnd                                          0x99A100
#define pinstCTimeLeftWnd                                          0x99A104
#define pinstCPetitionQWnd                                         0x99A10C
#define pinstCSoulmarkWnd                                          0x99A110
#define pinstCStoryWnd                                             0x99A114
#define pinstCJournalTextWnd                                       0x99A118
#define pinstCJournalCatWnd                                        0x99A11C
#define pinstCBodyTintWnd                                          0x99A120
#define pinstCServerListWnd                                        0x99A124
#define pinstCAvaZoneWnd                                           0x99A128
#define pinstCBlockedBuffWnd                                       0x99A12C
#define pinstCBlockedPetBuffWnd                                    0x99A130
#define pinstCInvSlotMgr                                           0x99A134
#define pinstCContainerMgr                                         0x99A138
#define pinstCAdventureLeaderboardWnd                              0xAEEC20
#define pinstCAdventureRequestWnd                                  0xAEEC3C
#define pinstCAltStorageWnd                                        0xAEEC9C
#define pinstCAdventureStatsWnd                                    0xAEEC58
#define pinstCBarterMerchantWnd                                    0xAEEE68
#define pinstCBarterSearchWnd                                      0xAEEE84
#define pinstCBarterWnd                                            0xAEEEA0
#define pinstCChatManager                                          0xAEF144
#define pinstCDynamicZoneWnd                                       0xAEF23C
#define pinstCEQMainWnd                                            0xAEF2B0
#define pinstCFellowshipWnd                                        0xAEF314
#define pinstCFindLocationWnd                                      0xAEF348
#define pinstCGroupSearchWnd                                       0xAEF3F8
#define pinstCGroupWnd                                             0xAEF414
#define pinstCGuildBankWnd                                         0xAEF430
#define pinstCGuildMgmtWnd                                         0xAF1468
#define pinstCGuildTributeMasterWnd                                0xAF1488
#define pinstCHotButtonWnd                                         0xAF14A4
#define pinstCHotButtonWnd1                                        0xAF14A4
#define pinstCHotButtonWnd2                                        0xAF14A8
#define pinstCHotButtonWnd3                                        0xAF14AC
#define pinstCHotButtonWnd4                                        0xAF14B0
#define pinstCItemDisplayManager                                   0xAF155C
#define pinstCItemExpTransferWnd                                   0xAF157C
#define pinstCLeadershipWnd                                        0xAF1618
#define pinstCLFGuildWnd                                           0xAF1634
#define pinstCMIZoneSelectWnd                                      0xAF17A4
#define pinstCAdventureMerchantWnd                                 0xAF189C
#define pinstCConfirmationDialog                                   0xAF18B8
#define pinstCPopupWndManager                                      0xAF18B8
#define pinstCProgressionSelectionWnd                              0xAF18EC
#define pinstCPvPLeaderboardWnd                                    0xAF1908
#define pinstCPvPStatsWnd                                          0xAF1924
#define pinstCSystemInfoDialogBox                                  0xAF19D8
#define pinstCTargetOfTargetWnd                                    0xAF22E4
#define pinstCTaskSelectWnd                                        0xAF2318
#define pinstCTaskTemplateSelectWnd                                0xAF2334
#define pinstCTaskWnd                                              0xAF2350
#define pinstCTipWndOFDAY                                          0xAF23CC
#define pinstCTipWndCONTEXT                                        0xAF23D0
#define pinstCTitleWnd                                             0xAF23EC
#define pinstCTradeskillWnd                                        0xAF2430
#define pinstCTributeBenefitWnd                                    0xAF247C
#define pinstCTributeMasterWnd                                     0xAF2498
#define pinstCContextMenuManager                                   0xB0033C
#define pinstCVoiceMacroWnd                                        0xAC34DC
#define pinstCHtmlWnd                                              0xAC3518


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4C6660
#define __ConvertItemTags                                          0x4B8660
#define __ExecuteCmd                                               0x4A6D00
#define __get_melee_range                                          0x4AC370
#define __GetGaugeValueFromEQ                                      0x640D30
#define __GetLabelFromEQ                                           0x641A50
#define __NewUIINI                                                 0x640910
#define __ProcessGameEvents                                        0x4F5BF0
#define CrashDetected                                              0x561560
#define DrawNetStatus                                              0x514780
#define Util__FastTime                                             0x6B7320


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47F7A0
#define AltAdvManager__IsAbilityReady                              0x47F7E0
#define AltAdvManager__GetAltAbility                               0x47FA40

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x579410

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x582850

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6E55E0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5984F0
#define CChatManager__InitContextMenu                              0x598C90

// CChatService
#define CChatService__GetNumberOfFriends                           0x6A71D0
#define CChatService__GetFriendName                                0x6A71E0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x59CE70
#define CChatWindow__Clear                                         0x59D7E0
#define CChatWindow__WndNotification                               0x59D8C0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6CFEA0
#define CComboWnd__Draw                                            0x6D0050
#define CComboWnd__GetCurChoice                                    0x6CFE40
#define CComboWnd__GetListRect                                     0x6D0310
#define CComboWnd__GetTextRect                                     0x6CFED0
#define CComboWnd__InsertChoice                                    0x6D0380
#define CComboWnd__SetColors                                       0x6CFDD0
#define CComboWnd__SetChoice                                       0x6CFE00

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5A4470
#define CContainerWnd__vftable                                     0x7E5BB0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46E1E0
#define CDisplay__GetClickedActor                                  0x46B930
#define CDisplay__GetUserDefinedColor                              0x46AA50
#define CDisplay__GetWorldFilePath                                 0x469F50
#define CDisplay__is3dON                                           0x4690C0
#define CDisplay__ReloadUI                                         0x47C920
#define CDisplay__WriteTextHD2                                     0x46E970

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x573410
#define CEditBaseWnd__SetSel                                       0x6F0A50

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6D8AE0
#define CEditWnd__GetCharIndexPt                                   0x6D9920
#define CEditWnd__GetDisplayString                                 0x6D8C70
#define CEditWnd__GetHorzOffset                                    0x6D8F00
#define CEditWnd__GetLineForPrintableChar                          0x6D93D0
#define CEditWnd__GetSelStartPt                                    0x6D9B60
#define CEditWnd__GetSTMLSafeText                                  0x6D9090
#define CEditWnd__PointFromPrintableChar                           0x6D94E0
#define CEditWnd__SelectableCharFromPoint                          0x6D9660
#define CEditWnd__SetEditable                                      0x6D9060

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4D9DF0
#define CEverQuest__DropHeldItemOnGround                           0x4DE340
#define CEverQuest__dsp_chat                                       0x4DF860
#define CEverQuest__DoTellWindow                                   0x4DE4C0
#define CEverQuest__EnterZone                                      0x4F4540
#define CEverQuest__GetBodyTypeDesc                                0x4D7070
#define CEverQuest__GetClassDesc                                   0x4D68B0
#define CEverQuest__GetClassThreeLetterCode                        0x4D6EB0
#define CEverQuest__GetDeityDesc                                   0x4D76E0
#define CEverQuest__GetLangDesc                                    0x4D7400
#define CEverQuest__GetRaceDesc                                    0x4D76B0
#define CEverQuest__InterpretCmd                                   0x4E02F0
#define CEverQuest__LeftClickedOnPlayer                            0x4F2CE0
#define CEverQuest__LMouseUp                                       0x4F5340
#define CEverQuest__RightClickedOnPlayer                           0x4F30B0
#define CEverQuest__RMouseUp                                       0x4F4B40
#define CEverQuest__SetGameState                                   0x4DA270
#define CEverQuest__Emote                                          0x4DFA50

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5B13C0
#define CGaugeWnd__CalcLinesFillRect                               0x5B1420
#define CGaugeWnd__Draw                                            0x5B1830

// CGuild
#define CGuild__FindMemberByName                                   0x421460

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5C98F0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5D2F00
#define CInvSlotMgr__MoveItem                                      0x5D30A0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5D18C0
#define CInvSlot__SliderComplete                                   0x5D1DD0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5E1D20
#define CItemDisplayWnd__SetSpell                                  0x63EA90

// CLabel 
#define CLabel__Draw                                               0x5E75F0

// CListWnd 
#define CListWnd__AddColumn                                        0x6CA660
#define CListWnd__AddColumn1                                       0x6CA0F0
#define CListWnd__AddLine                                          0x6C9C30
#define CListWnd__AddString                                        0x6C9E20
#define CListWnd__CalculateFirstVisibleLine                        0x6C6EF0
#define CListWnd__CalculateVSBRange                                0x6C8C90
#define CListWnd__ClearAllSel                                      0x6C6620
#define CListWnd__CloseAndUpdateEditWindow                         0x6C7515
#define CListWnd__Compare                                          0x6C7890
#define CListWnd__Draw                                             0x6C8980
#define CListWnd__DrawColumnSeparators                             0x6C87F0
#define CListWnd__DrawHeader                                       0x6C67F0
#define CListWnd__DrawItem                                         0x6C8120
#define CListWnd__DrawLine                                         0x6C8490
#define CListWnd__DrawSeparator                                    0x6C8890
#define CListWnd__EnsureVisible                                    0x6C6F40
#define CListWnd__ExtendSel                                        0x6C8040
#define CListWnd__GetColumnMinWidth                                0x6C63B0
#define CListWnd__GetColumnWidth                                   0x6C62F0
#define CListWnd__GetCurSel                                        0x6C5D00
#define CListWnd__GetHeaderRect                                    0x6C5E70
#define CListWnd__GetItemAtPoint                                   0x6C7220
#define CListWnd__GetItemAtPoint1                                  0x6C7290
#define CListWnd__GetItemData                                      0x6C60A0
#define CListWnd__GetItemHeight                                    0x6C6C80
#define CListWnd__GetItemIcon                                      0x6C6230
#define CListWnd__GetItemRect                                      0x6C7010
#define CListWnd__GetItemText                                      0x6C60E0
#define CListWnd__GetSelList                                       0x6C9FD0
#define CListWnd__GetSeparatorRect                                 0x6C77D0
#define CListWnd__RemoveLine                                       0x6CA610
#define CListWnd__SetColors                                        0x6C5DD0
#define CListWnd__SetColumnJustification                           0x6C6490
#define CListWnd__SetColumnWidth                                   0x6C6370
#define CListWnd__SetCurSel                                        0x6C5D40
#define CListWnd__SetItemColor                                     0x6C98A0
#define CListWnd__SetItemData                                      0x6C66C0
#define CListWnd__SetItemText                                      0x6C9820
#define CListWnd__ShiftColumnSeparator                             0x6C7FB0
#define CListWnd__Sort                                             0x6CA6A0
#define CListWnd__ToggleSel                                        0x6C6590

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5FC770

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x607BA0
#define CMerchantWnd__RequestBuyItem                               0x608F20
#define CMerchantWnd__RequestSellItem                              0x607DF0
#define CMerchantWnd__SelectBuySellSlot                            0x608C50

// CObfuscator
#define CObfuscator__doit                                          0x682360

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6E0F30
#define CSidlManager__CreateLabel                                  0x637AD0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x6D1B40
#define CSidlScreenWnd__CalculateVSBRange                          0x6E6BC0
#define CSidlScreenWnd__ConvertToRes                               0x6F0930
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6D1FC0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6D3090
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6D3140
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6D2860
#define CSidlScreenWnd__DrawSidlPiece                              0x6D1C90
#define CSidlScreenWnd__EnableIniStorage                           0x6D1780
#define CSidlScreenWnd__GetSidlPiece                               0x6D1E90
#define CSidlScreenWnd__Init1                                      0x6D2F00
#define CSidlScreenWnd__LoadIniInfo                                0x6D2070
#define CSidlScreenWnd__LoadIniListWnd                             0x6D18D0
#define CSidlScreenWnd__LoadSidlScreen                             0x6D2AB0
#define CSidlScreenWnd__StoreIniInfo                               0x6D1390
#define CSidlScreenWnd__WndNotification                            0x6D2C80
#define CSidlScreenWnd__GetChildItem                               0x6D17E0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x536F20

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6F1DD0
#define CSliderWnd__SetValue                                       0x6F1ED0
#define CSliderWnd__SetNumTicks                                    0x6F2440

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x63D280

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6EEB80
#define CStmlWnd__CalculateVSBRange                                0x6E6BC0
#define CStmlWnd__CanBreakAtCharacter                              0x6E6D00
#define CStmlWnd__FastForwardToEndOfTag                            0x6E7890
#define CStmlWnd__ForceParseNow                                    0x6EF000
#define CStmlWnd__GetNextTagPiece                                  0x6E77B0
#define CStmlWnd__GetSTMLText                                      0x59CE10
#define CStmlWnd__GetThisChar                                      0x7144D0
#define CStmlWnd__GetVisiableText                                  0x6E8AD0
#define CStmlWnd__InitializeWindowVariables                        0x6EACA0
#define CStmlWnd__MakeStmlColorTag                                 0x6E6240
#define CStmlWnd__MakeWndNotificationTag                           0x6E62E0
#define CStmlWnd__SetSTMLText                                      0x6EADD0
#define CStmlWnd__StripFirstSTMLLines                              0x6EE910
#define CStmlWnd__UpdateHistoryString                              0x6E9340

// CTabWnd 
#define CTabWnd__Draw                                              0x6F31D0
#define CTabWnd__DrawCurrentPage                                   0x6F2BF0
#define CTabWnd__DrawTab                                           0x6F29D0
#define CTabWnd__GetCurrentPage                                    0x6F2E70
#define CTabWnd__GetPageClientRect                                 0x6F26A0
#define CTabWnd__GetPageFromTabIndex                               0x6F2900
#define CTabWnd__GetPageInnerRect                                  0x6F2700
#define CTabWnd__GetTabInnerRect                                   0x6F2880
#define CTabWnd__GetTabRect                                        0x6F2790
#define CTabWnd__IndexInBounds                                     0x0
#define CTabWnd__InsertPage                                        0x6F3440
#define CTabWnd__SetPage                                           0x6F2EB0
#define CTabWnd__SetPageRect                                       0x6F3100
#define CTabWnd__UpdatePage                                        0x6F33C0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x41DA60

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6D34A0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6F77E0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6C59F0

// CXRect 
#define CXRect__CenterPoint                                        0x578AA0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x505A70
#define CXStr__CXStr1                                              0x6BF660
#define CXStr__CXStr3                                              0x6B89A0
#define CXStr__dCXStr                                              0x6E6EA0
#define CXStr__operator_equal1                                     0x6B8B60
#define CXStr__operator_plus_equal1                                0x6B9A60

// CXWnd 
#define CXWnd__BringToTop                                          0x6CAD90
#define CXWnd__Center                                              0x6CE7D0
#define CXWnd__ClrFocus                                            0x6CAAA0
#define CXWnd__DoAllDrawing                                        0x6CF640
#define CXWnd__DrawChildren                                        0x6CF770
#define CXWnd__DrawColoredRect                                     0x6CB010
#define CXWnd__DrawTooltip                                         0x6CF400
#define CXWnd__DrawTooltipAtPoint                                  0x6CE590
#define CXWnd__GetBorderFrame                                      0x6CB4F0
#define CXWnd__GetChildWndAt                                       0x6CE0D0
#define CXWnd__GetClientClipRect                                   0x6CB400
#define CXWnd__GetScreenClipRect                                   0x6CE9F0
#define CXWnd__GetScreenRect                                       0x6CB690
#define CXWnd__GetTooltipRect                                      0x6CB260
#define CXWnd__GetWindowTextA                                      0x56C140
#define CXWnd__IsActive                                            0x6D45B0
#define CXWnd__IsDescendantOf                                      0x6CB480
#define CXWnd__IsReallyVisible                                     0x6CE0B0
#define CXWnd__IsType                                              0x6F46C0
#define CXWnd__Move                                                0x6CDC90
#define CXWnd__Move1                                               0x6CF260
#define CXWnd__ProcessTransition                                   0x6CAD50
#define CXWnd__Refade                                              0x6CAB50
#define CXWnd__Resize                                              0x6CB760
#define CXWnd__Right                                               0x6CE930
#define CXWnd__SetFocus                                            0x6CCEC0
#define CXWnd__SetKeyTooltip                                       0x6CB970
#define CXWnd__SetMouseOver                                        0x6CB940
#define CXWnd__StartFade                                           0x6CADD0
#define CXWnd__GetChildItem                                        0x6CEBB0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6D5A30
#define CXWndManager__DrawWindows                                  0x6D5640
#define CXWndManager__GetKeyboardFlags                             0x6D4260
#define CXWndManager__HandleKeyboardMsg                            0x6D47B0
#define CXWndManager__RemoveWnd                                    0x6D46D0

// CDBStr
#define CDBStr__GetString                                          0x467A10

// EQ_Character 
#define EQ_Character__CastRay                                      0x720540
#define EQ_Character__CastSpell                                    0x42F150
#define EQ_Character__Cur_HP                                       0x43CA00
#define EQ_Character__GetAACastingTimeModifier                     0x429C50
#define EQ_Character__GetCharInfo2                                 0x698340
#define EQ_Character__GetFocusCastingTimeModifier                  0x4256E0
#define EQ_Character__GetFocusRangeModifier                        0x425820
#define EQ_Character__Max_Endurance                                0x51A910
#define EQ_Character__Max_HP                                       0x437900
#define EQ_Character__Max_Mana                                     0x51A740
#define EQ_Character__doCombatAbility                              0x519650
#define EQ_Character__UseSkill                                     0x442AF0
#define EQ_Character__GetConLevel                                  0x515BD0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x5037F0
#define EQ_Item__GetItemLinkHash                                   0x68BE00
#define EQ_Item__IsStackable                                       0x682C40

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x480910
#define EQ_LoadingS__Array                                         0x85DB60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x51D780
#define EQ_PC__GetAltAbilityIndex                                  0x690740
#define EQ_PC__GetCombatAbility                                    0x6907D0
#define EQ_PC__GetCombatAbilityTimer                               0x690880
#define EQ_PC__GetItemTimerValue                                   0x518590
#define EQ_PC__HasLoreItem                                         0x51BC50

// EQItemList 
#define EQItemList__dEQItemList                                    0x4AA8F0
#define EQItemList__EQItemList                                     0x4AA840

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x4673D0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x521FB0
#define EQPlayer__dEQPlayer                                        0x526000
#define EQPlayer__DoAttack                                         0x533160
#define EQPlayer__EQPlayer                                         0x529C90
#define EQPlayer__SetNameSpriteState                               0x523F80
#define EQPlayer__SetNameSpriteTint                                0x522020
#define EQPlayer__IsBodyType_j                                     0x71FE50
#define EQPlayer__IsTargetable                                     0x71FFE0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x52AD70
#define EQPlayerManager__GetSpawnByName                            0x52B050

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x505490
#define KeypressHandler__AttachKeyToEqCommand                      0x5054D0
#define KeypressHandler__ClearCommandStateArray                    0x5052A0
#define KeypressHandler__HandleKeyDown                             0x503E50
#define KeypressHandler__HandleKeyUp                               0x504160
#define KeypressHandler__SaveKeymapping                            0x505370

// MapViewMap 
#define MapViewMap__Clear                                          0x5F7E40
#define MapViewMap__SaveEx                                         0x5F8810

#define OtherCharData__GetAltCurrency                              0x6AFA30

// StringTable 
#define StringTable__getString                                     0x6825E0
