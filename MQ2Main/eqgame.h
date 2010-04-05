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
#define __ExpectedVersionDate                                     "Jun  9 2009"
#define __ExpectedVersionTime                                     "15:58:50"
#define __ActualVersionDate                                        0x7E2B94
#define __ActualVersionTime                                        0x7E2BA0

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x50D310
#define __MemChecker1                                              0x6B8AF0
#define __MemChecker2                                              0x564230
#define __MemChecker3                                              0x564180
#define __MemChecker4                                              0x67AAA0
#define __EncryptPad0                                              0x868710
#define __EncryptPad1                                              0x872DE8
#define __EncryptPad2                                              0x86B168
#define __EncryptPad3                                              0x86AD68
#define __EncryptPad4                                              0x8724B8
#define __AC1                                                      0x643A70
#define __AC2                                                      0x4DA085
#define __AC3                                                      0x4ED1E8
#define __AC4                                                      0x4F0F78
#define __AC5                                                      0x4FB2F8
#define __AC6                                                      0x4FE5AB
#define __AC7                                                      0x4F7874
#define __AC1_Data                                                 0x7CC42A

// Direct Input
#define DI8__Main                                                  0xACA594
#define DI8__Keyboard                                              0xACA598
#define DI8__Mouse                                                 0xACA59C
#define __AltTimerReady                                            0xA54F56
#define __Attack                                                   0xAB49FA
#define __Autofire                                                 0xAB49FB
#define __BindList                                                 0x863688
#define __Clicks                                                   0xA53C68
#define __CommandList                                              0x863EF8
#define __CurrentMapLabel                                          0xAF57D0
#define __CurrentSocial                                            0x85F6A4
#define __DoAbilityAvailable                                       0xA54EF0
#define __DoAbilityList                                            0xA8A510
#define __do_loot                                                  0x4B3C50
#define __DrawHandler                                              0xB04C3C
#define __GroupCount                                               0xA4DF22
#define __Guilds                                                   0xA4FAA0
#define __gWorld                                                   0xA4F9E0
#define __HotkeyPage                                               0xAB18FC
#define __HWnd                                                     0xACA2D4
#define __InChatMode                                               0xA53BA0
#define __LastTell                                                 0xA55868
#define __LMouseHeldTime                                           0xA53C88
#define __Mouse                                                    0xACA5A0
#define __MouseLook                                                0xA53C36
#define __MouseEventTime                                           0xAB4B04
#define __NetStatusToggle                                          0xA53C39
#define __PCNames                                                  0xA552AC
#define __RangeAttackReady                                         0xA54F54
#define __RMouseHeldTime                                           0xA53C84
#define __RunWalkState                                             0xA53BA4
#define __ScreenMode                                               0x99D7F0
#define __ScreenX                                                  0xA53B58
#define __ScreenY                                                  0xA53B5C
#define __ScreenXMax                                               0xA53B60
#define __ScreenYMax                                               0xA53B64
#define __ServerHost                                               0xA4DE64
#define __ServerName                                               0xA8A4D0
#define __ShiftKeyDown                                             0xA54208
#define __ShowNames                                                0xA55180
#define __Socials                                                  0xA8A5D0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA50000
#define instEQZoneInfo                                             0xA53DD4
#define instKeypressHandler                                        0xAB4AE8
#define pinstActiveBanker                                          0xA4FA78
#define pinstActiveCorpse                                          0xA4FA7C
#define pinstActiveGMaster                                         0xA4FA80
#define pinstActiveMerchant                                        0xA4FA74
#define pinstAltAdvManager                                         0x99E650
#define pinstAuraMgr                                               0x8870B4
#define pinstBandageTarget                                         0xA4FA60
#define pinstCamActor                                              0x99E140
#define pinstCDBStr                                                0x99D7E0
#define pinstCDisplay                                              0xA4FA88
#define pinstCEverQuest                                            0xACA718
#define pinstCharData                                              0xA4FA44
#define pinstCharSpawn                                             0xA4FA6C
#define pinstControlledMissile                                     0xA4FA40
#define pinstControlledPlayer                                      0xA4FA6C
#define pinstCSidlManager                                          0xB043C0
#define pinstCXWndManager                                          0xB043B8
#define instDynamicZone                                            0xA535A8
#define pinstDZMember                                              0xA536B8
#define pinstDZTimerInfo                                           0xA536BC
#define pinstEQItemList                                            0xA4FA28
#define instEQMisc                                                 0x99D798
#define pinstEQSoundManager                                        0x99E674
#define instExpeditionLeader                                       0xA535F2
#define instExpeditionName                                         0xA53632
#define pinstGroup                                                 0xA4DF1E
#define pinstImeManager                                            0xB043C4
#define pinstLocalPlayer                                           0xA4FA58
#define pinstMercenaryData                                         0xAB4E60
#define pinstModelPlayer                                           0xA4FA84
#define pinstPCData                                                0xA4FA44
#define pinstSkillMgr                                              0xAC73B4
#define pinstSpawnManager                                          0xAC725C
#define pinstSpellManager                                          0xAC73B8
#define pinstSpellSets                                             0xAB1900
#define pinstStringTable                                           0xA4F9FC
#define pinstSwitchManager                                         0xA4DB64
#define pinstTarget                                                0xA4FA70
#define pinstTargetObject                                          0xA4FA48
#define pinstTargetSwitch                                          0xA4FA4C
#define pinstTaskMember                                            0x99D778
#define pinstTrackTarget                                           0xA4FA64
#define pinstTradeTarget                                           0xA4FA54
#define instTributeActive                                          0x99D7BD
#define pinstViewActor                                             0x99E13C
#define pinstWorldData                                             0xA4FA24


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x884960
#define pinstCAudioTriggersWindow                                  0x88492C
#define pinstCCharacterSelect                                      0x99E04C
#define pinstCFacePick                                             0x99E000
#define pinstCNoteWnd                                              0x99E004
#define pinstCBookWnd                                              0x99E008
#define pinstCPetInfoWnd                                           0x99E00C
#define pinstCTrainWnd                                             0x99E010
#define pinstCSkillsWnd                                            0x99E014
#define pinstCSkillsSelectWnd                                      0x99E018
#define pinstCCombatSkillSelectWnd                                 0x99E01C
#define pinstCFriendsWnd                                           0x99E020
#define pinstCAuraWnd                                              0x99E024
#define pinstCRespawnWnd                                           0x99E028
#define pinstCBandolierWnd                                         0x99E02C
#define pinstCPotionBeltWnd                                        0x99E030
#define pinstCAAWnd                                                0x99E034
#define pinstCGroupSearchFiltersWnd                                0x99E038
#define pinstCLoadskinWnd                                          0x99E03C
#define pinstCAlarmWnd                                             0x99E040
#define pinstCMusicPlayerWnd                                       0x99E044
#define pinstCMailWnd                                              0x99E050
#define pinstCMailCompositionWnd                                   0x99E054
#define pinstCMailAddressBookWnd                                   0x99E058
#define pinstCRaidWnd                                              0x99E060
#define pinstCRaidOptionsWnd                                       0x99E064
#define pinstCBreathWnd                                            0x99E068
#define pinstCMapViewWnd                                           0x99E06C
#define pinstCMapToolbarWnd                                        0x99E070
#define pinstCEditLabelWnd                                         0x99E074
#define pinstCTargetWnd                                            0x99E078
#define pinstCColorPickerWnd                                       0x99E07C
#define pinstCPlayerWnd                                            0x99E080
#define pinstCOptionsWnd                                           0x99E084
#define pinstCBuffWindowNORMAL                                     0x99E088
#define pinstCBuffWindowSHORT                                      0x99E08C
#define pinstCharacterCreation                                     0x99E090
#define pinstCCursorAttachment                                     0x99E094
#define pinstCCastingWnd                                           0x99E098
#define pinstCCastSpellWnd                                         0x99E09C
#define pinstCSpellBookWnd                                         0x99E0A0
#define pinstCInventoryWnd                                         0x99E0A4
#define pinstCBankWnd                                              0x99E0A8
#define pinstCQuantityWnd                                          0x99E0AC
#define pinstCLootWnd                                              0x99E0B0
#define pinstCActionsWnd                                           0x99E0B4
#define pinstCCombatAbilityWnd                                     0x99E0B8
#define pinstCMerchantWnd                                          0x99E0BC
#define pinstCTradeWnd                                             0x99E0C0
#define pinstCSelectorWnd                                          0x99E0C4
#define pinstCBazaarWnd                                            0x99E0C8
#define pinstCBazaarSearchWnd                                      0x99E0CC
#define pinstCGiveWnd                                              0x99E0D0
#define pinstCTrackingWnd                                          0x99E0D4
#define pinstCInspectWnd                                           0x99E0D8
#define pinstCSocialEditWnd                                        0x99E0DC
#define pinstCFeedbackWnd                                          0x99E0E0
#define pinstCBugReportWnd                                         0x99E0E4
#define pinstCVideoModesWnd                                        0x99E0E8
#define pinstCTextEntryWnd                                         0x99E0F0
#define pinstCFileSelectionWnd                                     0x99E0F4
#define pinstCCompassWnd                                           0x99E0F8
#define pinstCPlayerNotesWnd                                       0x99E0FC
#define pinstCGemsGameWnd                                          0x99E100
#define pinstCTimeLeftWnd                                          0x99E104
#define pinstCPetitionQWnd                                         0x99E10C
#define pinstCSoulmarkWnd                                          0x99E110
#define pinstCStoryWnd                                             0x99E114
#define pinstCJournalTextWnd                                       0x99E118
#define pinstCJournalCatWnd                                        0x99E11C
#define pinstCBodyTintWnd                                          0x99E120
#define pinstCServerListWnd                                        0x99E124
#define pinstCAvaZoneWnd                                           0x99E128
#define pinstCBlockedBuffWnd                                       0x99E12C
#define pinstCBlockedPetBuffWnd                                    0x99E130
#define pinstCInvSlotMgr                                           0x99E134
#define pinstCContainerMgr                                         0x99E138
#define pinstCAdventureLeaderboardWnd                              0xAF2D00
#define pinstCAdventureRequestWnd                                  0xAF2D1C
#define pinstCAltStorageWnd                                        0xAF2D7C
#define pinstCAdventureStatsWnd                                    0xAF2D38
#define pinstCBarterMerchantWnd                                    0xAF2F48
#define pinstCBarterSearchWnd                                      0xAF2F64
#define pinstCBarterWnd                                            0xAF2F80
#define pinstCChatManager                                          0xAF3224
#define pinstCDynamicZoneWnd                                       0xAF331C
#define pinstCEQMainWnd                                            0xAF3390
#define pinstCFellowshipWnd                                        0xAF33F4
#define pinstCFindLocationWnd                                      0xAF3428
#define pinstCGroupSearchWnd                                       0xAF34D8
#define pinstCGroupWnd                                             0xAF34F4
#define pinstCGuildBankWnd                                         0xAF3510
#define pinstCGuildMgmtWnd                                         0xAF5548
#define pinstCGuildTributeMasterWnd                                0xAF5568
#define pinstCHotButtonWnd                                         0xAF5584
#define pinstCHotButtonWnd1                                        0xAF5584
#define pinstCHotButtonWnd2                                        0xAF5588
#define pinstCHotButtonWnd3                                        0xAF558C
#define pinstCHotButtonWnd4                                        0xAF5590
#define pinstCItemDisplayManager                                   0xAF563C
#define pinstCItemExpTransferWnd                                   0xAF565C
#define pinstCLeadershipWnd                                        0xAF56F8
#define pinstCLFGuildWnd                                           0xAF5714
#define pinstCMIZoneSelectWnd                                      0xAF5884
#define pinstCAdventureMerchantWnd                                 0xAF597C
#define pinstCConfirmationDialog                                   0xAF5998
#define pinstCPopupWndManager                                      0xAF5998
#define pinstCProgressionSelectionWnd                              0xAF59CC
#define pinstCPvPLeaderboardWnd                                    0xAF59E8
#define pinstCPvPStatsWnd                                          0xAF5A04
#define pinstCSystemInfoDialogBox                                  0xAF5AB8
#define pinstCTargetOfTargetWnd                                    0xAF63C4
#define pinstCTaskSelectWnd                                        0xAF63F8
#define pinstCTaskTemplateSelectWnd                                0xAF6414
#define pinstCTaskWnd                                              0xAF6430
#define pinstCTipWndOFDAY                                          0xAF64AC
#define pinstCTipWndCONTEXT                                        0xAF64B0
#define pinstCTitleWnd                                             0xAF64CC
#define pinstCTradeskillWnd                                        0xAF6510
#define pinstCTributeBenefitWnd                                    0xAF655C
#define pinstCTributeMasterWnd                                     0xAF6578
#define pinstCContextMenuManager                                   0xB0441C
#define pinstCVoiceMacroWnd                                        0xAC759C
#define pinstCHtmlWnd                                              0xAC75D8


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4C6FA0
#define __ConvertItemTags                                          0x4B9060
#define __ExecuteCmd                                               0x4A7720
#define __get_melee_range                                          0x4ACD70
#define __GetGaugeValueFromEQ                                      0x642CB0
#define __GetLabelFromEQ                                           0x643A10
#define __NewUIINI                                                 0x642840
#define __ProcessGameEvents                                        0x4F7C60
#define CrashDetected                                              0x562F00
#define DrawNetStatus                                              0x515A80
#define Util__FastTime                                             0x6B9200


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x480230
#define AltAdvManager__IsAbilityReady                              0x480270
#define AltAdvManager__GetAltAbility                               0x480490

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x57AED0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5843F0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6E7230

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x59A150
#define CChatManager__InitContextMenu                              0x59A8F0

// CChatService
#define CChatService__GetNumberOfFriends                           0x6A90F0
#define CChatService__GetFriendName                                0x6A9100

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x59EAD0
#define CChatWindow__Clear                                         0x59F440
#define CChatWindow__WndNotification                               0x59F520

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6D1E40
#define CComboWnd__Draw                                            0x6D1FF0
#define CComboWnd__GetCurChoice                                    0x6D1DE0
#define CComboWnd__GetListRect                                     0x6D22B0
#define CComboWnd__GetTextRect                                     0x6D1E70
#define CComboWnd__InsertChoice                                    0x6D2320
#define CComboWnd__SetColors                                       0x6D1D70
#define CComboWnd__SetChoice                                       0x6D1DA0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5A6640
#define CContainerWnd__vftable                                     0x7E9748

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46EBB0
#define CDisplay__GetClickedActor                                  0x46C2D0
#define CDisplay__GetUserDefinedColor                              0x46B3F0
#define CDisplay__GetWorldFilePath                                 0x46A8F0
#define CDisplay__is3dON                                           0x469A60
#define CDisplay__ReloadUI                                         0x47D3B0
#define CDisplay__WriteTextHD2                                     0x46F330

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x574DC0
#define CEditBaseWnd__SetSel                                       0x6F2660

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6DA8D0
#define CEditWnd__GetCharIndexPt                                   0x6DB730
#define CEditWnd__GetDisplayString                                 0x6DAA60
#define CEditWnd__GetHorzOffset                                    0x6DACF0
#define CEditWnd__GetLineForPrintableChar                          0x6DB1E0
#define CEditWnd__GetSelStartPt                                    0x6DB970
#define CEditWnd__GetSTMLSafeText                                  0x6DAE80
#define CEditWnd__PointFromPrintableChar                           0x6DB2F0
#define CEditWnd__SelectableCharFromPoint                          0x6DB470
#define CEditWnd__SetEditable                                      0x6DAE50

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4DA760
#define CEverQuest__DropHeldItemOnGround                           0x4DE7D0
#define CEverQuest__dsp_chat                                       0x4DFC80
#define CEverQuest__DoTellWindow                                   0x4DE950
#define CEverQuest__EnterZone                                      0x4F0F10
#define CEverQuest__GetBodyTypeDesc                                0x4D79E0
#define CEverQuest__GetClassDesc                                   0x4D7220
#define CEverQuest__GetClassThreeLetterCode                        0x4D7820
#define CEverQuest__GetDeityDesc                                   0x4D8050
#define CEverQuest__GetLangDesc                                    0x4D7D70
#define CEverQuest__GetRaceDesc                                    0x4D8020
#define CEverQuest__InterpretCmd                                   0x4E0710
#define CEverQuest__LeftClickedOnPlayer                            0x4F2820
#define CEverQuest__LMouseUp                                       0x4F6100
#define CEverQuest__RightClickedOnPlayer                           0x4F6910
#define CEverQuest__RMouseUp                                       0x4F7830
#define CEverQuest__SetGameState                                   0x4DABF0
#define CEverQuest__Emote                                          0x4DFE70

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5B3010
#define CGaugeWnd__CalcLinesFillRect                               0x5B3070
#define CGaugeWnd__Draw                                            0x5B3480

// CGuild
#define CGuild__FindMemberByName                                   0x421420

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5CB6B0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5D4D10
#define CInvSlotMgr__MoveItem                                      0x5D4EB0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5D45B0
#define CInvSlot__SliderComplete                                   0x5D3710

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5E3B00
#define CItemDisplayWnd__SetSpell                                  0x640970

// CLabel 
#define CLabel__Draw                                               0x5E93D0

// CListWnd 
#define CListWnd__AddColumn                                        0x6CC660
#define CListWnd__AddColumn1                                       0x6CC140
#define CListWnd__AddLine                                          0x6CBC30
#define CListWnd__AddString                                        0x6CBE20
#define CListWnd__CalculateFirstVisibleLine                        0x6C8EF0
#define CListWnd__CalculateVSBRange                                0x6CAC90
#define CListWnd__ClearAllSel                                      0x6C8620
#define CListWnd__CloseAndUpdateEditWindow                         0x6C9515
#define CListWnd__Compare                                          0x6C9890
#define CListWnd__Draw                                             0x6CA980
#define CListWnd__DrawColumnSeparators                             0x6CA7F0
#define CListWnd__DrawHeader                                       0x6C87F0
#define CListWnd__DrawItem                                         0x6CA120
#define CListWnd__DrawLine                                         0x6CA490
#define CListWnd__DrawSeparator                                    0x6CA890
#define CListWnd__EnsureVisible                                    0x6C8F40
#define CListWnd__ExtendSel                                        0x6CA040
#define CListWnd__GetColumnMinWidth                                0x6C83B0
#define CListWnd__GetColumnWidth                                   0x6C82F0
#define CListWnd__GetCurSel                                        0x6C7D00
#define CListWnd__GetHeaderRect                                    0x6C7E70
#define CListWnd__GetItemAtPoint                                   0x6C9220
#define CListWnd__GetItemAtPoint1                                  0x6C9290
#define CListWnd__GetItemData                                      0x6C80A0
#define CListWnd__GetItemHeight                                    0x6C8C80
#define CListWnd__GetItemIcon                                      0x6C8230
#define CListWnd__GetItemRect                                      0x6C9010
#define CListWnd__GetItemText                                      0x6C80E0
#define CListWnd__GetSelList                                       0x6CC020
#define CListWnd__GetSeparatorRect                                 0x6C97D0
#define CListWnd__RemoveLine                                       0x6CBFD0
#define CListWnd__SetColors                                        0x6C7DD0
#define CListWnd__SetColumnJustification                           0x6C8490
#define CListWnd__SetColumnWidth                                   0x6C8370
#define CListWnd__SetCurSel                                        0x6C7D40
#define CListWnd__SetItemColor                                     0x6CB8A0
#define CListWnd__SetItemData                                      0x6C86C0
#define CListWnd__SetItemText                                      0x6CB820
#define CListWnd__ShiftColumnSeparator                             0x6C9FB0
#define CListWnd__Sort                                             0x6CC6A0
#define CListWnd__ToggleSel                                        0x6C8590

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5FE5B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x6099C0
#define CMerchantWnd__RequestBuyItem                               0x60B220
#define CMerchantWnd__RequestSellItem                              0x60B620
#define CMerchantWnd__SelectBuySellSlot                            0x60A6F0

// CObfuscator
#define CObfuscator__doit                                          0x684180

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6E2CE0
#define CSidlManager__CreateLabel                                  0x639940

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x576E90
#define CSidlScreenWnd__CalculateVSBRange                          0x6E87F0
#define CSidlScreenWnd__ConvertToRes                               0x6F2540
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6D3E00
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6D4F00
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6D4FB0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6D46D0
#define CSidlScreenWnd__DrawSidlPiece                              0x6D3AD0
#define CSidlScreenWnd__EnableIniStorage                           0x6D3720
#define CSidlScreenWnd__GetSidlPiece                               0x6D3CD0
#define CSidlScreenWnd__Init1                                      0x6D4D70
#define CSidlScreenWnd__LoadIniInfo                                0x6D3EB0
#define CSidlScreenWnd__LoadIniListWnd                             0x6D3870
#define CSidlScreenWnd__LoadSidlScreen                             0x6D4920
#define CSidlScreenWnd__StoreIniInfo                               0x6D3330
#define CSidlScreenWnd__WndNotification                            0x6D4AF0
#define CSidlScreenWnd__GetChildItem                               0x6D3780

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x538200

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x6F3AF0
#define CSliderWnd__SetValue                                       0x6F3BF0
#define CSliderWnd__SetNumTicks                                    0x6F4160

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x63E710

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6F07C0
#define CStmlWnd__CalculateVSBRange                                0x6E87F0
#define CStmlWnd__CanBreakAtCharacter                              0x6E8930
#define CStmlWnd__FastForwardToEndOfTag                            0x6E94F0
#define CStmlWnd__ForceParseNow                                    0x6F0C40
#define CStmlWnd__GetNextTagPiece                                  0x6E9410
#define CStmlWnd__GetSTMLText                                      0x59EA70
#define CStmlWnd__GetThisChar                                      0x7162B0
#define CStmlWnd__GetVisiableText                                  0x6EA710
#define CStmlWnd__InitializeWindowVariables                        0x6EC8E0
#define CStmlWnd__MakeStmlColorTag                                 0x6E7E90
#define CStmlWnd__MakeWndNotificationTag                           0x6E7F30
#define CStmlWnd__SetSTMLText                                      0x6ECA10
#define CStmlWnd__StripFirstSTMLLines                              0x6F0550
#define CStmlWnd__UpdateHistoryString                              0x6EAF80

// CTabWnd 
#define CTabWnd__Draw                                              0x6F4F70
#define CTabWnd__DrawCurrentPage                                   0x6F4910
#define CTabWnd__DrawTab                                           0x6F46F0
#define CTabWnd__GetCurrentPage                                    0x6F4C10
#define CTabWnd__GetPageClientRect                                 0x6F43C0
#define CTabWnd__GetPageFromTabIndex                               0x6F4620
#define CTabWnd__GetPageInnerRect                                  0x6F4420
#define CTabWnd__GetTabInnerRect                                   0x6F45A0
#define CTabWnd__GetTabRect                                        0x6F44B0
#define CTabWnd__InsertPage                                        0x6F51E0
#define CTabWnd__SetPage                                           0x6F4C50
#define CTabWnd__SetPageRect                                       0x6F4EA0
#define CTabWnd__UpdatePage                                        0x6F5160

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x41DA20

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6D5310

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6F9530

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6C79F0

// CXRect 
#define CXRect__CenterPoint                                        0x57A560

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x41BDA0
#define CXStr__CXStr1                                              0x6C1660
#define CXStr__CXStr3                                              0x6BA880
#define CXStr__dCXStr                                              0x44D780
#define CXStr__operator_equal1                                     0x6BAA40
#define CXStr__operator_plus_equal1                                0x6BB940

// CXWnd 
#define CXWnd__BringToTop                                          0x6CCD80
#define CXWnd__Center                                              0x6D07D0
#define CXWnd__ClrFocus                                            0x6CCAA0
#define CXWnd__DoAllDrawing                                        0x6D15E0
#define CXWnd__DrawChildren                                        0x6D1710
#define CXWnd__DrawColoredRect                                     0x6CD010
#define CXWnd__DrawTooltip                                         0x6D1400
#define CXWnd__DrawTooltipAtPoint                                  0x6D0590
#define CXWnd__GetBorderFrame                                      0x6CD4F0
#define CXWnd__GetChildWndAt                                       0x6D00D0
#define CXWnd__GetClientClipRect                                   0x6CD400
#define CXWnd__GetScreenClipRect                                   0x6D09F0
#define CXWnd__GetScreenRect                                       0x6CD690
#define CXWnd__GetTooltipRect                                      0x6CD260
#define CXWnd__GetWindowTextA                                      0x56DB20
#define CXWnd__IsActive                                            0x6D6420
#define CXWnd__IsDescendantOf                                      0x6CD480
#define CXWnd__IsReallyVisible                                     0x6D00B0
#define CXWnd__IsType                                              0x6F63D0
#define CXWnd__Move                                                0x6CFC90
#define CXWnd__Move1                                               0x6D1260
#define CXWnd__ProcessTransition                                   0x6CCD40
#define CXWnd__Refade                                              0x6CCB50
#define CXWnd__Resize                                              0x6CD760
#define CXWnd__Right                                               0x6D0930
#define CXWnd__SetFocus                                            0x6CEEC0
#define CXWnd__SetKeyTooltip                                       0x6CD970
#define CXWnd__SetMouseOver                                        0x6CD940
#define CXWnd__StartFade                                           0x6CCDC0
#define CXWnd__GetChildItem                                        0x6D0BB0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6D7820
#define CXWndManager__DrawWindows                                  0x6D7430
#define CXWndManager__GetKeyboardFlags                             0x6D60D0
#define CXWndManager__HandleKeyboardMsg                            0x6D6620
#define CXWndManager__RemoveWnd                                    0x6D6540

// CDBStr
#define CDBStr__GetString                                          0x4683C0

// EQ_Character 
#define EQ_Character__CastRay                                      0x722410
#define EQ_Character__CastSpell                                    0x433CB0
#define EQ_Character__Cur_HP                                       0x43D2E0
#define EQ_Character__GetAACastingTimeModifier                     0x429DC0
#define EQ_Character__GetCharInfo2                                 0x69A280
#define EQ_Character__GetFocusCastingTimeModifier                  0x425700
#define EQ_Character__GetFocusRangeModifier                        0x425840
#define EQ_Character__Max_Endurance                                0x51BBE0
#define EQ_Character__Max_HP                                       0x4381E0
#define EQ_Character__Max_Mana                                     0x51BA10
#define EQ_Character__doCombatAbility                              0x51A920
#define EQ_Character__UseSkill                                     0x448A90
#define EQ_Character__GetConLevel                                  0x516ED0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x504C40
#define EQ_Item__GetItemLinkHash                                   0x68DC20
#define EQ_Item__IsStackable                                       0x684A60

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x481360
#define EQ_LoadingS__Array                                         0x861B60

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x51EA50
#define EQ_PC__GetAltAbilityIndex                                  0x692680
#define EQ_PC__GetCombatAbility                                    0x692710
#define EQ_PC__GetCombatAbilityTimer                               0x6927C0
#define EQ_PC__GetItemTimerValue                                   0x519860
#define EQ_PC__HasLoreItem                                         0x51CF20

// EQItemList 
#define EQItemList__dEQItemList                                    0x4AB300
#define EQItemList__EQItemList                                     0x4AB250

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x467D70

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x5232B0
#define EQPlayer__dEQPlayer                                        0x527300
#define EQPlayer__DoAttack                                         0x5344D0
#define EQPlayer__EQPlayer                                         0x52AFA0
#define EQPlayer__SetNameSpriteState                               0x525280
#define EQPlayer__SetNameSpriteTint                                0x523320
#define EQPlayer__IsBodyType_j                                     0x721D20
#define EQPlayer__IsTargetable                                     0x721EB0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x52C080
#define EQPlayerManager__GetSpawnByName                            0x52C360

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x5068E0
#define KeypressHandler__AttachKeyToEqCommand                      0x506920
#define KeypressHandler__ClearCommandStateArray                    0x5066F0
#define KeypressHandler__HandleKeyDown                             0x5052A0
#define KeypressHandler__HandleKeyUp                               0x5055B0
#define KeypressHandler__SaveKeymapping                            0x5067C0

// MapViewMap 
#define MapViewMap__Clear                                          0x5F9C80
#define MapViewMap__SaveEx                                         0x5FA650

#define OtherCharData__GetAltCurrency                              0x6B18F0

// StringTable 
#define StringTable__getString                                     0x684400
