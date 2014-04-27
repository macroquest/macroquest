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
#define __ExpectedVersionDate                                     "Sep 17 2012"
#define __ExpectedVersionTime                                     "19:48:59"
#define __ActualVersionDate                                        0x91C790
#define __ActualVersionTime                                        0x91C79C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x537920
#define __MemChecker1                                              0x825860
#define __MemChecker2                                              0x5BF090
#define __MemChecker3                                              0x5BEFE0
#define __MemChecker4                                              0x847FA0
#define __EncryptPad0                                              0x9F6888
#define __EncryptPad1                                              0xA70998
#define __EncryptPad2                                              0xA0F620
#define __EncryptPad3                                              0xA0F220
#define __EncryptPad4                                              0xA72440
#define __AC1                                                      0x6FFB10
#define __AC2                                                      0x4F38E5
#define __AC3                                                      0x505B18
#define __AC4                                                      0x50B284
#define __AC5                                                      0x51712E
#define __AC6                                                      0x51AAEB
#define __AC7                                                      0x5129FB
#define __AC1_Data                                                 0x9022CD
// Direct Input
#define DI8__Main                                                  0xCF57D8
#define DI8__Keyboard                                              0xCF57DC
#define DI8__Mouse                                                 0xCF57E0
#define __AltTimerReady                                            0xBBE361
#define __Attack                                                   0xCF15A2
#define __Autofire                                                 0xCF15A3
#define __BindList                                                 0x9DED18
#define __Clicks                                                   0xC7B874
#define __CommandList                                              0x9E0368
#define __CurrentMapLabel                                          0xE01618
#define __CurrentSocial                                            0x9CAEDC
#define __DoAbilityList                                            0xCB1F78
#define __do_loot                                                  0x4C6F90
#define __DrawHandler                                              0x145E2E4
#define __GroupCount                                               0xC6C22A
#define __Guilds                                                   0xC6E7C0
#define __gWorld                                                   0xC6E6EC
#define __HotkeyPage                                               0xCDAB54
#define __HWnd                                                     0xCF5528
#define __InChatMode                                               0xC7B7AC
#define __LastTell                                                 0xC7D680
#define __LMouseHeldTime                                           0xC7B8E0
#define __Mouse                                                    0xCF57E4
#define __MouseLook                                                0xC7B842
#define __MouseEventTime                                           0xCF18BC
#define __NetStatusToggle                                          0xC7B845
#define __PCNames                                                  0xC7CD00
#define __RangeAttackReady                                         0xC7C998
#define __RMouseHeldTime                                           0xC7B8DC
#define __RunWalkState                                             0xC7B7B0
#define __ScreenMode                                               0xBBB6A8
#define __ScreenX                                                  0xC7B760
#define __ScreenY                                                  0xC7B764
#define __ScreenXMax                                               0xC7B768
#define __ScreenYMax                                               0xC7B76C
#define __ServerHost                                               0xC6C16C
#define __ServerName                                               0xCB1F38
#define __ShiftKeyDown                                             0xC7BE34
#define __ShowNames                                                0xC7CBA4
#define __Socials                                                  0xCB2038


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xC780D8
#define instEQZoneInfo                                             0xC7BA2C
#define instKeypressHandler                                        0xCF18B8
#define pinstActiveBanker                                          0xC6E794
#define pinstActiveCorpse                                          0xC6E798
#define pinstActiveGMaster                                         0xC6E79C
#define pinstActiveMerchant                                        0xC6E790
#define pinstAltAdvManager                                         0xBBC5F0
#define pinstAuraMgr                                               0xA8B830
#define pinstBandageTarget                                         0xC6E77C
#define pinstCamActor                                              0xBBC068
#define pinstCDBStr                                                0xBBB680
#define pinstCDisplay                                              0xC6E7A4
#define pinstCEverQuest                                            0xCF5960
#define pinstCharData                                              0xC6E760
#define pinstCharSpawn                                             0xC6E788
#define pinstControlledMissile                                     0xC6E75C
#define pinstControlledPlayer                                      0xC6E788
#define pinstCSidlManager                                          0x145E824
#define pinstCXWndManager                                          0x145E81C
#define instDynamicZone                                            0xC77B30
#define pinstDZMember                                              0xC77C40
#define pinstDZTimerInfo                                           0xC77C44
#define pinstEQItemList                                            0xC6B2D0
#define instEQMisc                                                 0xBBB5E8
#define pinstEQSoundManager                                        0xBBC660
#define instExpeditionLeader                                       0xC77B7A
#define instExpeditionName                                         0xC77BBA
#define pinstGroup                                                 0xC6C226
#define pinstImeManager                                            0x145E828
#define pinstLocalPlayer                                           0xC6E774
#define pinstMercenaryData                                         0xCF1D38
#define pinstModelPlayer                                           0xC6E7A0
#define pinstPCData                                                0xC6E760
#define pinstSkillMgr                                              0xCF2368
#define pinstSpawnManager                                          0xCF1FD8
#define pinstSpellManager                                          0xCF23E0
#define pinstSpellSets                                             0xCEA8AC
#define pinstStringTable                                           0xC6E708
#define pinstSwitchManager                                         0xC6BE38
#define pinstTarget                                                0xC6E78C
#define pinstTargetObject                                          0xC6E764
#define pinstTargetSwitch                                          0xC6E768
#define pinstTaskMember                                            0xBBB5B0
#define pinstTrackTarget                                           0xC6E780
#define pinstTradeTarget                                           0xC6E770
#define instTributeActive                                          0xBBB60D
#define pinstViewActor                                             0xBBC064
#define pinstWorldData                                             0xC6E744


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0xA82870
#define pinstCAudioTriggersWindow                                  0xA82808
#define pinstCCharacterSelect                                      0xBBBF18
#define pinstCFacePick                                             0xBBBEC8
#define pinstCNoteWnd                                              0xBBBED0
#define pinstCBookWnd                                              0xBBBED8
#define pinstCPetInfoWnd                                           0xBBBEDC
#define pinstCTrainWnd                                             0xBBBEE0
#define pinstCSkillsWnd                                            0xBBBEE4
#define pinstCSkillsSelectWnd                                      0xBBBEE8
#define pinstCCombatSkillSelectWnd                                 0xBBBEEC
#define pinstCFriendsWnd                                           0xBBBEF0
#define pinstCAuraWnd                                              0xBBBEF4
#define pinstCRespawnWnd                                           0xBBBEF8
#define pinstCBandolierWnd                                         0xBBBEFC
#define pinstCPotionBeltWnd                                        0xBBBF00
#define pinstCAAWnd                                                0xBBBF04
#define pinstCGroupSearchFiltersWnd                                0xBBBF08
#define pinstCLoadskinWnd                                          0xBBBF0C
#define pinstCAlarmWnd                                             0xBBBF10
#define pinstCMusicPlayerWnd                                       0xBBBF14
#define pinstCMailWnd                                              0xBBBF1C
#define pinstCMailCompositionWnd                                   0xBBBF20
#define pinstCMailAddressBookWnd                                   0xBBBF24
#define pinstCRaidWnd                                              0xBBBF2C
#define pinstCRaidOptionsWnd                                       0xBBBF30
#define pinstCBreathWnd                                            0xBBBF34
#define pinstCMapViewWnd                                           0xBBBF38
#define pinstCMapToolbarWnd                                        0xBBBF3C
#define pinstCEditLabelWnd                                         0xBBBF40
#define pinstCTargetWnd                                            0xBBBF44
#define pinstCColorPickerWnd                                       0xBBBF48
#define pinstCPlayerWnd                                            0xBBBF4C
#define pinstCOptionsWnd                                           0xBBBF50
#define pinstCBuffWindowNORMAL                                     0xBBBF54
#define pinstCBuffWindowSHORT                                      0xBBBF58
#define pinstCharacterCreation                                     0xBBBF5C
#define pinstCCursorAttachment                                     0xBBBF60
#define pinstCCastingWnd                                           0xBBBF64
#define pinstCCastSpellWnd                                         0xBBBF68
#define pinstCSpellBookWnd                                         0xBBBF6C
#define pinstCInventoryWnd                                         0xBBBF70
#define pinstCBankWnd                                              0xBBBF74
#define pinstCQuantityWnd                                          0xBBBF78
#define pinstCLootWnd                                              0xBBBF7C
#define pinstCActionsWnd                                           0xBBBF80
#define pinstCCombatAbilityWnd                                     0xBBBF84
#define pinstCMerchantWnd                                          0xBBBF88
#define pinstCTradeWnd                                             0xBBBF8C
#define pinstCSelectorWnd                                          0xBBBF90
#define pinstCBazaarWnd                                            0xBBBF94
#define pinstCBazaarSearchWnd                                      0xBBBF98
#define pinstCGiveWnd                                              0xBBBFB4
#define pinstCTrackingWnd                                          0xBBBFBC
#define pinstCInspectWnd                                           0xBBBFC0
#define pinstCSocialEditWnd                                        0xBBBFC4
#define pinstCFeedbackWnd                                          0xBBBFC8
#define pinstCBugReportWnd                                         0xBBBFCC
#define pinstCVideoModesWnd                                        0xBBBFD0
#define pinstCTextEntryWnd                                         0xBBBFD8
#define pinstCFileSelectionWnd                                     0xBBBFDC
#define pinstCCompassWnd                                           0xBBBFE0
#define pinstCPlayerNotesWnd                                       0xBBBFE4
#define pinstCGemsGameWnd                                          0xBBBFE8
#define pinstCTimeLeftWnd                                          0xBBBFEC
#define pinstCPetitionQWnd                                         0xBBC000
#define pinstCSoulmarkWnd                                          0xBBC004
#define pinstCStoryWnd                                             0xBBC008
#define pinstCJournalTextWnd                                       0xBBC00C
#define pinstCJournalCatWnd                                        0xBBC010
#define pinstCBodyTintWnd                                          0xBBC014
#define pinstCServerListWnd                                        0xBBC018
#define pinstCAvaZoneWnd                                           0xBBC020
#define pinstCBlockedBuffWnd                                       0xBBC024
#define pinstCBlockedPetBuffWnd                                    0xBBC028
#define pinstCInvSlotMgr                                           0xBBC05C
#define pinstCContainerMgr                                         0xBBC060
#define pinstCAdventureLeaderboardWnd                              0xDFE150
#define pinstCAdventureRequestWnd                                  0xDFE118
#define pinstCAltStorageWnd                                        0xDFE258
#define pinstCAdventureStatsWnd                                    0xDFE150
#define pinstCBarterMerchantWnd                                    0xDFE6B0
#define pinstCBarterSearchWnd                                      0xDFE6E8
#define pinstCBarterWnd                                            0xDFE720
#define pinstCChatManager                                          0xDFEB18
#define pinstCDynamicZoneWnd                                       0xDFED08
#define pinstCEQMainWnd                                            0xDFEDC8
#define pinstCFellowshipWnd                                        0xDFECFC
#define pinstCFindLocationWnd                                      0xDFEEF8
#define pinstCGroupSearchWnd                                       0xDFF058
#define pinstCGroupWnd                                             0xDFF090
#define pinstCGuildBankWnd                                         0xDFF0C8
#define pinstCGuildMgmtWnd                                         0xE01138
#define pinstCGuildTributeMasterWnd                                0xE02D90
#define pinstCHotButtonWnd                                         0xE0118C
#define pinstCHotButtonWnd1                                        0xE0118C
#define pinstCHotButtonWnd2                                        0xE01190
#define pinstCHotButtonWnd3                                        0xE01194
#define pinstCHotButtonWnd4                                        0xE011D4
#define pinstCItemDisplayManager                                   0xE01308
#define pinstCItemExpTransferWnd                                   0xE01344
#define pinstCLeadershipWnd                                        0xE01470
#define pinstCLFGuildWnd                                           0xE014A8
#define pinstCMIZoneSelectWnd                                      0xE01748
#define pinstCAdventureMerchantWnd                                 0xE019F8
#define pinstCConfirmationDialog                                   0xE01A30
#define pinstCPopupWndManager                                      0xE01A30
#define pinstCProgressionSelectionWnd                              0xE01A98
#define pinstCPvPLeaderboardWnd                                    0xE01AD0
#define pinstCPvPStatsWnd                                          0xE01B08
#define pinstCSystemInfoDialogBox                                  0xE01DF0
#define pinstCTargetOfTargetWnd                                    0xE02A40
#define pinstCTaskSelectWnd                                        0xE01CAC
#define pinstCTaskTemplateSelectWnd                                0xE02AE0
#define pinstCTaskWnd                                              0xE02B18
#define pinstCTipWndOFDAY                                          0xE02C10
#define pinstCTipWndCONTEXT                                        0xE02C14
#define pinstCTitleWnd                                             0xE02C48
#define pinstCTradeskillWnd                                        0xE02CC0
#define pinstCTributeBenefitWnd                                    0xE02D58
#define pinstCTributeMasterWnd                                     0xE02D90
#define pinstCContextMenuManager                                   0x145E880
#define pinstCVoiceMacroWnd                                        0xCF2728
#define pinstCHtmlWnd                                              0xCF27A0


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4DB7B0
#define __ConvertItemTags                                          0x4CC6B0
#define __ExecuteCmd                                               0x4B8190
#define __EQGetTime                                                0x826C80
#define __get_melee_range                                          0x4BE470
#define __GetGaugeValueFromEQ                                      0x6FE8C0
#define __GetLabelFromEQ                                           0x6FFAB0
#define __GetXTargetType                                           0x77E730
#define __LoadFrontEnd                                             0x5BE000
#define __NewUIINI                                                 0x6FE470
#define __ProcessGameEvents                                        0x5131E0
#define CrashDetected                                              0x5C0A10
#define DrawNetStatus                                              0x545280
#define Util__FastTime                                             0x826130
#define Expansion_HoT                                              0xC7CB04
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x48A4D0
#define AltAdvManager__IsAbilityReady                              0x48A580
#define AltAdvManager__GetAltAbility                               0x48A7A0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x43D3A0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5E53B0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5EFAD0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x525820

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x608C60
#define CChatManager__InitContextMenu                              0x609590

// CChatService
#define CChatService__GetNumberOfFriends                           0x7749E0
#define CChatService__GetFriendName                                0x7749F0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x60E350
#define CChatWindow__Clear                                         0x60DF00
#define CChatWindow__WndNotification                               0x60E760

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x7D5290
#define CComboWnd__Draw                                            0x7D5450
#define CComboWnd__GetCurChoice                                    0x7D50B0
#define CComboWnd__GetListRect                                     0x7D5730
#define CComboWnd__GetTextRect                                     0x7D52C0
#define CComboWnd__InsertChoice                                    0x7D57A0
#define CComboWnd__SetColors                                       0x7D5040
#define CComboWnd__SetChoice                                       0x7D5070

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x6165A0
#define CContainerWnd__vftable                                     0x9251F0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x47DCA0
#define CDisplay__GetClickedActor                                  0x476770
#define CDisplay__GetUserDefinedColor                              0x475060
#define CDisplay__GetWorldFilePath                                 0x474580
#define CDisplay__is3dON                                           0x473680
#define CDisplay__ReloadUI                                         0x487420
#define CDisplay__WriteTextHD2                                     0x4797D0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5DCE20
#define CEditBaseWnd__SetSel                                       0x7F5CD0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7DE930
#define CEditWnd__GetCharIndexPt                                   0x7DF900
#define CEditWnd__GetDisplayString                                 0x7DEAD0
#define CEditWnd__GetHorzOffset                                    0x7DED60
#define CEditWnd__GetLineForPrintableChar                          0x7DF3B0
#define CEditWnd__GetSelStartPt                                    0x7DFB40
#define CEditWnd__GetSTMLSafeText                                  0x7DEF00
#define CEditWnd__PointFromPrintableChar                           0x7DF4C0
#define CEditWnd__SelectableCharFromPoint                          0x7DF640
#define CEditWnd__SetEditable                                      0x7DEED0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4F4030
#define CEverQuest__DropHeldItemOnGround                           0x500FD0
#define CEverQuest__dsp_chat                                       0x4FA360
#define CEverQuest__DoTellWindow                                   0x4F8A50
#define CEverQuest__EnterZone                                      0x50B410
#define CEverQuest__GetBodyTypeDesc                                0x4F0E30
#define CEverQuest__GetClassDesc                                   0x4F0670
#define CEverQuest__GetClassThreeLetterCode                        0x4F0C70
#define CEverQuest__GetDeityDesc                                   0x4F14E0
#define CEverQuest__GetLangDesc                                    0x4F11C0
#define CEverQuest__GetRaceDesc                                    0x4F14B0
#define CEverQuest__InterpretCmd                                   0x4FAE70
#define CEverQuest__LeftClickedOnPlayer                            0x50D0F0
#define CEverQuest__LMouseUp                                       0x510810
#define CEverQuest__RightClickedOnPlayer                           0x5119E0
#define CEverQuest__RMouseUp                                       0x5129C0
#define CEverQuest__SetGameState                                   0x4F44C0
#define CEverQuest__Emote                                          0x4FA580

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x624340
#define CGaugeWnd__CalcLinesFillRect                               0x6243A0
#define CGaugeWnd__Draw                                            0x6247F0

// CGuild
#define CGuild__FindMemberByName                                   0x41D1B0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x63E830

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x648B50
#define CInvSlotMgr__MoveItem                                      0x649800

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x6481E0
#define CInvSlot__SliderComplete                                   0x6465A0
#define CInvSlot__GetItemBase                                      0x645C20

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x64A560

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6FBE70
#define CItemDisplayWnd__UpdateStrings                             0x64B5B0

// CLabel 
#define CLabel__Draw                                               0x662860

// CListWnd 
#define CListWnd__AddColumn                                        0x7CACD0
#define CListWnd__AddColumn1                                       0x7CA300
#define CListWnd__AddLine                                          0x7C9EB0
#define CListWnd__AddString                                        0x7CA050
#define CListWnd__CalculateFirstVisibleLine                        0x7C6120
#define CListWnd__CalculateVSBRange                                0x7C8520
#define CListWnd__ClearAllSel                                      0x7C5670
#define CListWnd__CloseAndUpdateEditWindow                         0x7C9520
#define CListWnd__Compare                                          0x7C6BC0
#define CListWnd__Draw                                             0x7C8160
#define CListWnd__DrawColumnSeparators                             0x7C7FF0
#define CListWnd__DrawHeader                                       0x7C5900
#define CListWnd__DrawItem                                         0x7C75C0
#define CListWnd__DrawLine                                         0x7C7CB0
#define CListWnd__DrawSeparator                                    0x7C8090
#define CListWnd__EnsureVisible                                    0x7C6280
#define CListWnd__ExtendSel                                        0x7C74E0
#define CListWnd__GetColumnMinWidth                                0x7C5340
#define CListWnd__GetColumnWidth                                   0x7C5280
#define CListWnd__GetCurSel                                        0x7C4A40
#define CListWnd__GetHeaderRect                                    0x7C4BA0
#define CListWnd__GetItemAtPoint                                   0x7C6550
#define CListWnd__GetItemAtPoint1                                  0x7C65C0
#define CListWnd__GetItemData                                      0x7C4E80
#define CListWnd__GetItemHeight                                    0x7C5D90
#define CListWnd__GetItemIcon                                      0x7C5060
#define CListWnd__GetItemRect                                      0x7C6350
#define CListWnd__GetItemText                                      0x7C4F10
#define CListWnd__GetSelList                                       0x7CA1E0
#define CListWnd__GetSeparatorRect                                 0x7C6B10
#define CListWnd__RemoveLine                                       0x7CAC80
#define CListWnd__SetColors                                        0x7C4B10
#define CListWnd__SetColumnJustification                           0x7C54E0
#define CListWnd__SetColumnWidth                                   0x7C5300
#define CListWnd__SetCurSel                                        0x7C4A80
#define CListWnd__SetItemColor                                     0x7C91D0
#define CListWnd__SetItemData                                      0x7C5710
#define CListWnd__SetItemText                                      0x7C9000
#define CListWnd__ShiftColumnSeparator                             0x7C8E70
#define CListWnd__Sort                                             0x7CB430
#define CListWnd__ToggleSel                                        0x7C55E0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x67B300

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x697370
#define CMerchantWnd__RequestBuyItem                               0x69D4E0
#define CMerchantWnd__RequestSellItem                              0x6BFAB0
#define CMerchantWnd__SelectBuySellSlot                            0x697620

// CObfuscator
#define CObfuscator__doit                                          0x747CB0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7E73F0
#define CSidlManager__CreateLabel                                  0x6F39B0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5E1060
#define CSidlScreenWnd__CalculateVSBRange                          0x5E0F80
#define CSidlScreenWnd__ConvertToRes                               0x7F5BB0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7D78E0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7D8B20
#define CSidlScreenWnd__CSidlScreenWnd2                            0x7D8BD0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x7D82B0
#define CSidlScreenWnd__DrawSidlPiece                              0x7D7380
#define CSidlScreenWnd__EnableIniStorage                           0x7D6B40
#define CSidlScreenWnd__GetSidlPiece                               0x7D75A0
#define CSidlScreenWnd__Init1                                      0x7D8970
#define CSidlScreenWnd__LoadIniInfo                                0x7D79A0
#define CSidlScreenWnd__LoadIniListWnd                             0x7D6C90
#define CSidlScreenWnd__LoadSidlScreen                             0x7D8510
#define CSidlScreenWnd__StoreIniInfo                               0x7D6710
#define CSidlScreenWnd__StoreIniVis                                0x7D6AD0
#define CSidlScreenWnd__WndNotification                            0x7D8760
#define CSidlScreenWnd__GetChildItem                               0x7D6BA0

// CSkillMgr
#define CSkillMgr__IsAvailable                                     0x586260
#define CSkillMgr__GetSkillCap                                     0x5862D0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7FDEA0
#define CSliderWnd__SetValue                                       0x7FDFA0
#define CSliderWnd__SetNumTicks                                    0x7FE550

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6F9B10

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7F3020
#define CStmlWnd__CalculateHSBRange                                0x7EA5E0
#define CStmlWnd__CalculateVSBRange                                0x7EA670
#define CStmlWnd__CanBreakAtCharacter                              0x7EA7E0
#define CStmlWnd__FastForwardToEndOfTag                            0x7EB4D0
#define CStmlWnd__ForceParseNow                                    0x7F3610
#define CStmlWnd__GetNextTagPiece                                  0x7EB3F0
#define CStmlWnd__GetSTMLText                                      0x60D7A0
#define CStmlWnd__GetThisChar                                      0x81E9A0
#define CStmlWnd__GetVisiableText                                  0x7EC930
#define CStmlWnd__InitializeWindowVariables                        0x7EEF20
#define CStmlWnd__MakeStmlColorTag                                 0x7E9500
#define CStmlWnd__MakeWndNotificationTag                           0x7E95A0
#define CStmlWnd__SetSTMLText                                      0x7EF050
#define CStmlWnd__StripFirstSTMLLines                              0x7F2CC0
#define CStmlWnd__UpdateHistoryString                              0x7ED1D0

// CTabWnd 
#define CTabWnd__Draw                                              0x7F9AA0
#define CTabWnd__DrawCurrentPage                                   0x7F9320
#define CTabWnd__DrawTab                                           0x7F90F0
#define CTabWnd__GetCurrentPage                                    0x7F96E0
#define CTabWnd__GetPageClientRect                                 0x7F8DA0
#define CTabWnd__GetPageFromTabIndex                               0x7F9020
#define CTabWnd__GetPageInnerRect                                  0x7F8E00
#define CTabWnd__GetTabInnerRect                                   0x7F8FA0
#define CTabWnd__GetTabRect                                        0x7F8E90
#define CTabWnd__InsertPage                                        0x7F9D30
#define CTabWnd__SetPage                                           0x7F9720
#define CTabWnd__SetPageRect                                       0x7F99D0
#define CTabWnd__UpdatePage                                        0x7F9CB0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x419410

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x7D8F50

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7F6F50

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x7C39A0

// CXRect 
#define CXRect__CenterPoint                                        0x524940

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x530270
#define CXStr__CXStr1                                              0x6A60C0
#define CXStr__CXStr3                                              0x822FC0
#define CXStr__dCXStr                                              0x465830
#define CXStr__operator_equal                                      0x823130
#define CXStr__operator_equal1                                     0x823180
#define CXStr__operator_plus_equal1                                0x824290

// CXWnd 
#define CXWnd__BringToTop                                          0x7CE250
#define CXWnd__Center                                              0x7D3C10
#define CXWnd__ClrFocus                                            0x7CE090
#define CXWnd__DoAllDrawing                                        0x7D3AA0
#define CXWnd__DrawChildren                                        0x7D3BE0
#define CXWnd__DrawColoredRect                                     0x7CE570
#define CXWnd__DrawTooltip                                         0x7CE770
#define CXWnd__DrawTooltipAtPoint                                  0x7D2D10
#define CXWnd__GetBorderFrame                                      0x7CEB90
#define CXWnd__GetChildWndAt                                       0x7D1F00
#define CXWnd__GetClientClipRect                                   0x7CE910
#define CXWnd__GetScreenClipRect                                   0x7D3240
#define CXWnd__GetScreenRect                                       0x7CECC0
#define CXWnd__GetTooltipRect                                      0x7CE690
#define CXWnd__GetWindowTextA                                      0x5244C0
#define CXWnd__IsActive                                            0x7DA090
#define CXWnd__IsDescendantOf                                      0x7CEA80
#define CXWnd__IsReallyVisible                                     0x7D1EE0
#define CXWnd__IsType                                              0x7FB370
#define CXWnd__Move                                                0x7D1650
#define CXWnd__Move1                                               0x7D3770
#define CXWnd__ProcessTransition                                   0x7CE200
#define CXWnd__Refade                                              0x7CE190
#define CXWnd__Resize                                              0x7CED90
#define CXWnd__Right                                               0x7D3150
#define CXWnd__SetFocus                                            0x7D07C0
#define CXWnd__SetKeyTooltip                                       0x7CEFE0
#define CXWnd__SetMouseOver                                        0x7D3560
#define CXWnd__StartFade                                           0x7CE290
#define CXWnd__GetChildItem                                        0x7D34A0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x7DB5F0
#define CXWndManager__DrawWindows                                  0x7DB270
#define CXWndManager__GetKeyboardFlags                             0x7D9CE0
#define CXWndManager__HandleKeyboardMsg                            0x7DA360
#define CXWndManager__RemoveWnd                                    0x7DA1B0

// CDBStr
#define CDBStr__GetString                                          0x471BE0

// EQ_Character 
#define EQ_Character__CastRay                                      0x761960
#define EQ_Character__CastSpell                                    0x4336E0
#define EQ_Character__Cur_HP                                       0x43D040
#define EQ_Character__GetAACastingTimeModifier                     0x428280
#define EQ_Character__GetCharInfo2                                 0x75FC80
#define EQ_Character__GetFocusCastingTimeModifier                  0x422EA0
#define EQ_Character__GetFocusRangeModifier                        0x423070
#define EQ_Character__Max_Endurance                                0x552B10
#define EQ_Character__Max_HP                                       0x4376F0
#define EQ_Character__Max_Mana                                     0x552910
#define EQ_Character__doCombatAbility                              0x551700
#define EQ_Character__UseSkill                                     0x44CBF0
#define EQ_Character__GetConLevel                                  0x5489F0
#define EQ_Character__IsExpansionFlag                              0x40DE90
#define EQ_Character__TotalEffect                                  0x42CB40

// EQ_Item 
#define EQ_Item__CanDrop                                           0x529F70
#define EQ_Item__CreateItemTagString                               0x745D50
#define EQ_Item__IsStackable                                       0x73A060

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x48BA90
#define EQ_LoadingS__Array                                         0x9D9A50

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x556730
#define EQ_PC__GetAltAbilityIndex                                  0x751030
#define EQ_PC__GetCombatAbility                                    0x7510C0
#define EQ_PC__GetCombatAbilityTimer                               0x751170
#define EQ_PC__GetItemTimerValue                                   0x551470
#define EQ_PC__HasLoreItem                                         0x54FF40

// EQItemList 
#define EQItemList__EQItemList                                     0x4BC7A0
#define EQItemList__add_item                                       0x4BC730
#define EQItemList__delete_item                                    0x4BCB50
#define EQItemList__FreeItemList                                   0x4BCA80

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x471190

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x55B8E0
#define EQPlayer__dEQPlayer                                        0x5605D0
#define EQPlayer__DoAttack                                         0x572760
#define EQPlayer__EQPlayer                                         0x5668F0
#define EQPlayer__SetNameSpriteState                               0x55DE10
#define EQPlayer__SetNameSpriteTint                                0x55B950
#define EQPlayer__IsBodyType_j                                     0x761200
#define EQPlayer__IsTargetable                                     0x7614D0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x567E90
#define EQPlayerManager__GetSpawnByName                            0x568120

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x52FBE0
#define KeypressHandler__AttachKeyToEqCommand                      0x52FC20
#define KeypressHandler__ClearCommandStateArray                    0x52F9F0
#define KeypressHandler__HandleKeyDown                             0x52E380
#define KeypressHandler__HandleKeyUp                               0x52E690
#define KeypressHandler__SaveKeymapping                            0x52FAC0

// MapViewMap 
#define MapViewMap__Clear                                          0x674530
#define MapViewMap__SaveEx                                         0x677BE0

#define PlayerPointManager__GetAltCurrency                         0x74B880

// StringTable 
#define StringTable__getString                                     0x747F30

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x554E40
