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
#define __ExpectedVersionDate                                     "Oct 11 2012"
#define __ExpectedVersionTime                                     "17:37:36"
#define __ActualVersionDate                                        0x91D7A8
#define __ActualVersionTime                                        0x91D7B4

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x537C40
#define __MemChecker1                                              0x826710
#define __MemChecker2                                              0x5BF6B0
#define __MemChecker3                                              0x5BF600
#define __MemChecker4                                              0x848EE0
#define __EncryptPad0                                              0x9F6FF8
#define __EncryptPad1                                              0xA71108
#define __EncryptPad2                                              0xA0FD90
#define __EncryptPad3                                              0xA0F990
#define __EncryptPad4                                              0xA72BB0
#define __AC1                                                      0x700690
#define __AC2                                                      0x4F3D05
#define __AC3                                                      0x505EE8
#define __AC4                                                      0x50B654
#define __AC5                                                      0x51752E
#define __AC6                                                      0x51AEEB
#define __AC7                                                      0x512DFB
#define __AC1_Data                                                 0x90332D
// Direct Input
#define DI8__Main                                                  0xCF5F88
#define DI8__Keyboard                                              0xCF5F8C
#define DI8__Mouse                                                 0xCF5F90
#define __AltTimerReady                                            0xBBEAE1
#define __Attack                                                   0xCF1D52
#define __Autofire                                                 0xCF1D53
#define __BindList                                                 0x9DED18
#define __Clicks                                                   0xC7C024
#define __CommandList                                              0x9E0368
#define __CurrentMapLabel                                          0xE01DC8
#define __CurrentSocial                                            0x9CAEDC
#define __DoAbilityList                                            0xCB2728
#define __do_loot                                                  0x4C73A0
#define __DrawHandler                                              0x145EA94
#define __GroupCount                                               0xC6C9DA
#define __Guilds                                                   0xC6EF70
#define __gWorld                                                   0xC6EE9C
#define __HotkeyPage                                               0xCDB304
#define __HWnd                                                     0xCF5CD8
#define __InChatMode                                               0xC7BF5C
#define __LastTell                                                 0xC7DE30
#define __LMouseHeldTime                                           0xC7C090
#define __Mouse                                                    0xCF5F94
#define __MouseLook                                                0xC7BFF2
#define __MouseEventTime                                           0xCF206C
#define __NetStatusToggle                                          0xC7BFF5
#define __PCNames                                                  0xC7D4B0
#define __RangeAttackReady                                         0xC7D148
#define __RMouseHeldTime                                           0xC7C08C
#define __RunWalkState                                             0xC7BF60
#define __ScreenMode                                               0xBBBE28
#define __ScreenX                                                  0xC7BF10
#define __ScreenY                                                  0xC7BF14
#define __ScreenXMax                                               0xC7BF18
#define __ScreenYMax                                               0xC7BF1C
#define __ServerHost                                               0xC6C91C
#define __ServerName                                               0xCB26E8
#define __ShiftKeyDown                                             0xC7C5E4
#define __ShowNames                                                0xC7D354
#define __Socials                                                  0xCB27E8


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xC78888
#define instEQZoneInfo                                             0xC7C1DC
#define instKeypressHandler                                        0xCF2068
#define pinstActiveBanker                                          0xC6EF44
#define pinstActiveCorpse                                          0xC6EF48
#define pinstActiveGMaster                                         0xC6EF4C
#define pinstActiveMerchant                                        0xC6EF40
#define pinstAltAdvManager                                         0xBBCD70
#define pinstAuraMgr                                               0xA8BFB0
#define pinstBandageTarget                                         0xC6EF2C
#define pinstCamActor                                              0xBBC7E8
#define pinstCDBStr                                                0xBBBE00
#define pinstCDisplay                                              0xC6EF54
#define pinstCEverQuest                                            0xCF6110
#define pinstCharData                                              0xC6EF10
#define pinstCharSpawn                                             0xC6EF38
#define pinstControlledMissile                                     0xC6EF0C
#define pinstControlledPlayer                                      0xC6EF38
#define pinstCSidlManager                                          0x145EFD4
#define pinstCXWndManager                                          0x145EFCC
#define instDynamicZone                                            0xC782E0
#define pinstDZMember                                              0xC783F0
#define pinstDZTimerInfo                                           0xC783F4
#define pinstEQItemList                                            0xC6BA50
#define instEQMisc                                                 0xBBBD68
#define pinstEQSoundManager                                        0xBBCDE0
#define instExpeditionLeader                                       0xC7832A
#define instExpeditionName                                         0xC7836A
#define pinstGroup                                                 0xC6C9D6
#define pinstImeManager                                            0x145EFD8
#define pinstLocalPlayer                                           0xC6EF24
#define pinstMercenaryData                                         0xCF24E8
#define pinstModelPlayer                                           0xC6EF50
#define pinstPCData                                                0xC6EF10
#define pinstSkillMgr                                              0xCF2B18
#define pinstSpawnManager                                          0xCF2788
#define pinstSpellManager                                          0xCF2B90
#define pinstSpellSets                                             0xCEB05C
#define pinstStringTable                                           0xC6EEB8
#define pinstSwitchManager                                         0xC6C5E8
#define pinstTarget                                                0xC6EF3C
#define pinstTargetObject                                          0xC6EF14
#define pinstTargetSwitch                                          0xC6EF18
#define pinstTaskMember                                            0xBBBD30
#define pinstTrackTarget                                           0xC6EF30
#define pinstTradeTarget                                           0xC6EF20
#define instTributeActive                                          0xBBBD8D
#define pinstViewActor                                             0xBBC7E4
#define pinstWorldData                                             0xC6EEF4


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0xA82FF0
#define pinstCAudioTriggersWindow                                  0xA82F88
#define pinstCCharacterSelect                                      0xBBC698
#define pinstCFacePick                                             0xBBC648
#define pinstCNoteWnd                                              0xBBC650
#define pinstCBookWnd                                              0xBBC658
#define pinstCPetInfoWnd                                           0xBBC65C
#define pinstCTrainWnd                                             0xBBC660
#define pinstCSkillsWnd                                            0xBBC664
#define pinstCSkillsSelectWnd                                      0xBBC668
#define pinstCCombatSkillSelectWnd                                 0xBBC66C
#define pinstCFriendsWnd                                           0xBBC670
#define pinstCAuraWnd                                              0xBBC674
#define pinstCRespawnWnd                                           0xBBC678
#define pinstCBandolierWnd                                         0xBBC67C
#define pinstCPotionBeltWnd                                        0xBBC680
#define pinstCAAWnd                                                0xBBC684
#define pinstCGroupSearchFiltersWnd                                0xBBC688
#define pinstCLoadskinWnd                                          0xBBC68C
#define pinstCAlarmWnd                                             0xBBC690
#define pinstCMusicPlayerWnd                                       0xBBC694
#define pinstCMailWnd                                              0xBBC69C
#define pinstCMailCompositionWnd                                   0xBBC6A0
#define pinstCMailAddressBookWnd                                   0xBBC6A4
#define pinstCRaidWnd                                              0xBBC6AC
#define pinstCRaidOptionsWnd                                       0xBBC6B0
#define pinstCBreathWnd                                            0xBBC6B4
#define pinstCMapViewWnd                                           0xBBC6B8
#define pinstCMapToolbarWnd                                        0xBBC6BC
#define pinstCEditLabelWnd                                         0xBBC6C0
#define pinstCTargetWnd                                            0xBBC6C4
#define pinstCColorPickerWnd                                       0xBBC6C8
#define pinstCPlayerWnd                                            0xBBC6CC
#define pinstCOptionsWnd                                           0xBBC6D0
#define pinstCBuffWindowNORMAL                                     0xBBC6D4
#define pinstCBuffWindowSHORT                                      0xBBC6D8
#define pinstCharacterCreation                                     0xBBC6DC
#define pinstCCursorAttachment                                     0xBBC6E0
#define pinstCCastingWnd                                           0xBBC6E4
#define pinstCCastSpellWnd                                         0xBBC6E8
#define pinstCSpellBookWnd                                         0xBBC6EC
#define pinstCInventoryWnd                                         0xBBC6F0
#define pinstCBankWnd                                              0xBBC6F4
#define pinstCQuantityWnd                                          0xBBC6F8
#define pinstCLootWnd                                              0xBBC6FC
#define pinstCActionsWnd                                           0xBBC700
#define pinstCCombatAbilityWnd                                     0xBBC704
#define pinstCMerchantWnd                                          0xBBC708
#define pinstCTradeWnd                                             0xBBC70C
#define pinstCSelectorWnd                                          0xBBC710
#define pinstCBazaarWnd                                            0xBBC714
#define pinstCBazaarSearchWnd                                      0xBBC718
#define pinstCGiveWnd                                              0xBBC734
#define pinstCTrackingWnd                                          0xBBC73C
#define pinstCInspectWnd                                           0xBBC740
#define pinstCSocialEditWnd                                        0xBBC744
#define pinstCFeedbackWnd                                          0xBBC748
#define pinstCBugReportWnd                                         0xBBC74C
#define pinstCVideoModesWnd                                        0xBBC750
#define pinstCTextEntryWnd                                         0xBBC758
#define pinstCFileSelectionWnd                                     0xBBC75C
#define pinstCCompassWnd                                           0xBBC760
#define pinstCPlayerNotesWnd                                       0xBBC764
#define pinstCGemsGameWnd                                          0xBBC768
#define pinstCTimeLeftWnd                                          0xBBC76C
#define pinstCPetitionQWnd                                         0xBBC780
#define pinstCSoulmarkWnd                                          0xBBC784
#define pinstCStoryWnd                                             0xBBC788
#define pinstCJournalTextWnd                                       0xBBC78C
#define pinstCJournalCatWnd                                        0xBBC790
#define pinstCBodyTintWnd                                          0xBBC794
#define pinstCServerListWnd                                        0xBBC798
#define pinstCAvaZoneWnd                                           0xBBC7A0
#define pinstCBlockedBuffWnd                                       0xBBC7A4
#define pinstCBlockedPetBuffWnd                                    0xBBC7A8
#define pinstCInvSlotMgr                                           0xBBC7DC
#define pinstCContainerMgr                                         0xBBC7E0
#define pinstCAdventureLeaderboardWnd                              0xDFE900
#define pinstCAdventureRequestWnd                                  0xDFE8C8
#define pinstCAltStorageWnd                                        0xDFEA08
#define pinstCAdventureStatsWnd                                    0xDFE900
#define pinstCBarterMerchantWnd                                    0xDFEE60
#define pinstCBarterSearchWnd                                      0xDFEE98
#define pinstCBarterWnd                                            0xDFEED0
#define pinstCChatManager                                          0xDFF2C8
#define pinstCDynamicZoneWnd                                       0xDFF4B8
#define pinstCEQMainWnd                                            0xDFF578
#define pinstCFellowshipWnd                                        0xDFF4AC
#define pinstCFindLocationWnd                                      0xDFF6A8
#define pinstCGroupSearchWnd                                       0xDFF808
#define pinstCGroupWnd                                             0xDFF840
#define pinstCGuildBankWnd                                         0xDFF878
#define pinstCGuildMgmtWnd                                         0xE018E8
#define pinstCGuildTributeMasterWnd                                0xE03540
#define pinstCHotButtonWnd                                         0xE0193C
#define pinstCHotButtonWnd1                                        0xE0193C
#define pinstCHotButtonWnd2                                        0xE01940
#define pinstCHotButtonWnd3                                        0xE01944
#define pinstCHotButtonWnd4                                        0xE01984
#define pinstCItemDisplayManager                                   0xE01AB8
#define pinstCItemExpTransferWnd                                   0xE01AF4
#define pinstCLeadershipWnd                                        0xE01C20
#define pinstCLFGuildWnd                                           0xE01C58
#define pinstCMIZoneSelectWnd                                      0xE01EF8
#define pinstCAdventureMerchantWnd                                 0xE021A8
#define pinstCConfirmationDialog                                   0xE021E0
#define pinstCPopupWndManager                                      0xE021E0
#define pinstCProgressionSelectionWnd                              0xE02248
#define pinstCPvPLeaderboardWnd                                    0xE02280
#define pinstCPvPStatsWnd                                          0xE022B8
#define pinstCSystemInfoDialogBox                                  0xE025A0
#define pinstCTargetOfTargetWnd                                    0xE031F0
#define pinstCTaskSelectWnd                                        0xE0245C
#define pinstCTaskTemplateSelectWnd                                0xE03290
#define pinstCTaskWnd                                              0xE032C8
#define pinstCTipWndOFDAY                                          0xE033C0
#define pinstCTipWndCONTEXT                                        0xE033C4
#define pinstCTitleWnd                                             0xE033F8
#define pinstCTradeskillWnd                                        0xE03470
#define pinstCTributeBenefitWnd                                    0xE03508
#define pinstCTributeMasterWnd                                     0xE03540
#define pinstCContextMenuManager                                   0x145F030
#define pinstCVoiceMacroWnd                                        0xCF2ED8
#define pinstCHtmlWnd                                              0xCF2F50


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4DBB50
#define __ConvertItemTags                                          0x4CCAC0
#define __ExecuteCmd                                               0x4B8580
#define __EQGetTime                                                0x827AF0
#define __get_melee_range                                          0x4BE880
#define __GetGaugeValueFromEQ                                      0x6FF440
#define __GetLabelFromEQ                                           0x700630
#define __GetXTargetType                                           0x77F500
#define __LoadFrontEnd                                             0x5BE620
#define __NewUIINI                                                 0x6FEFF0
#define __ProcessGameEvents                                        0x5135E0
#define CrashDetected                                              0x5C1030
#define DrawNetStatus                                              0x545600
#define Util__FastTime                                             0x826FA0
#define Expansion_HoT                                              0xC7D2B4
//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x48A7C0
#define AltAdvManager__IsAbilityReady                              0x48A8A0
#define AltAdvManager__GetAltAbility                               0x48AB20

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x43D640

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5E5C70

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5F0200

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x525C10

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x6092F0
#define CChatManager__InitContextMenu                              0x609C20

// CChatService
#define CChatService__GetNumberOfFriends                           0x73B1A0
#define CChatService__GetFriendName                                0x775670

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x60E9E0
#define CChatWindow__Clear                                         0x60E590
#define CChatWindow__WndNotification                               0x60EE00

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x7D61F0
#define CComboWnd__Draw                                            0x7D63B0
#define CComboWnd__GetCurChoice                                    0x7D6010
#define CComboWnd__GetListRect                                     0x7D66A0
#define CComboWnd__GetTextRect                                     0x7D6220
#define CComboWnd__InsertChoice                                    0x7D6710
#define CComboWnd__SetColors                                       0x7D5FA0
#define CComboWnd__SetChoice                                       0x7D5FD0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x616CC0
#define CContainerWnd__vftable                                     0x926208

// CDisplay 
#define CDisplay__CleanGameUI                                      0x47DF90
#define CDisplay__GetClickedActor                                  0x476A30
#define CDisplay__GetUserDefinedColor                              0x475320
#define CDisplay__GetWorldFilePath                                 0x474840
#define CDisplay__is3dON                                           0x473940
#define CDisplay__ReloadUI                                         0x487710
#define CDisplay__WriteTextHD2                                     0x479AC0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5DD6E0
#define CEditBaseWnd__SetSel                                       0x7F6D10

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x7DFA20
#define CEditWnd__GetCharIndexPt                                   0x7E09F0
#define CEditWnd__GetDisplayString                                 0x7DFBC0
#define CEditWnd__GetHorzOffset                                    0x7DFE50
#define CEditWnd__GetLineForPrintableChar                          0x7E04A0
#define CEditWnd__GetSelStartPt                                    0x7E0C30
#define CEditWnd__GetSTMLSafeText                                  0x7DFFF0
#define CEditWnd__PointFromPrintableChar                           0x7E05B0
#define CEditWnd__SelectableCharFromPoint                          0x7E0730
#define CEditWnd__SetEditable                                      0x7DFFC0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4F4450
#define CEverQuest__DropHeldItemOnGround                           0x5013A0
#define CEverQuest__dsp_chat                                       0x4FA730
#define CEverQuest__DoTellWindow                                   0x4F8E70
#define CEverQuest__EnterZone                                      0x50B7E0
#define CEverQuest__GetBodyTypeDesc                                0x4F1250
#define CEverQuest__GetClassDesc                                   0x4F0A90
#define CEverQuest__GetClassThreeLetterCode                        0x4F1090
#define CEverQuest__GetDeityDesc                                   0x4F1900
#define CEverQuest__GetLangDesc                                    0x4F15E0
#define CEverQuest__GetRaceDesc                                    0x4F18D0
#define CEverQuest__InterpretCmd                                   0x4FB240
#define CEverQuest__LeftClickedOnPlayer                            0x50D4F0
#define CEverQuest__LMouseUp                                       0x510C10
#define CEverQuest__RightClickedOnPlayer                           0x511DE0
#define CEverQuest__RMouseUp                                       0x512DC0
#define CEverQuest__SetGameState                                   0x4F48E0
#define CEverQuest__Emote                                          0x4FA950

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x624A60
#define CGaugeWnd__CalcLinesFillRect                               0x624AC0
#define CGaugeWnd__Draw                                            0x624F10

// CGuild
#define CGuild__FindMemberByName                                   0x41D390

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x63EFB0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x649520
#define CInvSlotMgr__MoveItem                                      0x64A1D0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x648BB0
#define CInvSlot__SliderComplete                                   0x646F70
#define CInvSlot__GetItemBase                                      0x646600

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x64AF20

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6FCA00
#define CItemDisplayWnd__UpdateStrings                             0x64BF60

// CLabel 
#define CLabel__Draw                                               0x6631D0

// CListWnd 
#define CListWnd__AddColumn                                        0x7CBC90
#define CListWnd__AddColumn1                                       0x7CB310
#define CListWnd__AddLine                                          0x7CAE70
#define CListWnd__AddString                                        0x7CB010
#define CListWnd__CalculateFirstVisibleLine                        0x7C70B0
#define CListWnd__CalculateVSBRange                                0x7C94D0
#define CListWnd__ClearAllSel                                      0x7C6610
#define CListWnd__CloseAndUpdateEditWindow                         0x7CA4D0
#define CListWnd__Compare                                          0x7C7B60
#define CListWnd__Draw                                             0x7C9110
#define CListWnd__DrawColumnSeparators                             0x7C8FA0
#define CListWnd__DrawHeader                                       0x7C68A0
#define CListWnd__DrawItem                                         0x7C8570
#define CListWnd__DrawLine                                         0x7C8C60
#define CListWnd__DrawSeparator                                    0x7C9040
#define CListWnd__EnsureVisible                                    0x7C7210
#define CListWnd__ExtendSel                                        0x7C8490
#define CListWnd__GetColumnMinWidth                                0x7C62E0
#define CListWnd__GetColumnWidth                                   0x7C6220
#define CListWnd__GetCurSel                                        0x7C59D0
#define CListWnd__GetHeaderRect                                    0x7C5B40
#define CListWnd__GetItemAtPoint                                   0x7C74E0
#define CListWnd__GetItemAtPoint1                                  0x7C7550
#define CListWnd__GetItemData                                      0x7C5E20
#define CListWnd__GetItemHeight                                    0x7C6D30
#define CListWnd__GetItemIcon                                      0x7C6000
#define CListWnd__GetItemRect                                      0x7C72E0
#define CListWnd__GetItemText                                      0x7C5EB0
#define CListWnd__GetSelList                                       0x7CB1F0
#define CListWnd__GetSeparatorRect                                 0x7C7AB0
#define CListWnd__RemoveLine                                       0x7CB1A0
#define CListWnd__SetColors                                        0x7C5AA0
#define CListWnd__SetColumnJustification                           0x7C6480
#define CListWnd__SetColumnWidth                                   0x7C62A0
#define CListWnd__SetCurSel                                        0x7C5A10
#define CListWnd__SetItemColor                                     0x7CA180
#define CListWnd__SetItemData                                      0x7C66B0
#define CListWnd__SetItemText                                      0x7C9FB0
#define CListWnd__ShiftColumnSeparator                             0x7C9E20
#define CListWnd__Sort                                             0x7CC3F0
#define CListWnd__ToggleSel                                        0x7C6580

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x67BC80

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x697F40
#define CMerchantWnd__RequestBuyItem                               0x69E150
#define CMerchantWnd__RequestSellItem                              0x6C0710
#define CMerchantWnd__SelectBuySellSlot                            0x6981F0

// CObfuscator
#define CObfuscator__doit                                          0x748B30

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7E8470
#define CSidlManager__CreateLabel                                  0x6F4520

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5E1900
#define CSidlScreenWnd__CalculateVSBRange                          0x5E1820
#define CSidlScreenWnd__ConvertToRes                               0x7F6BF0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x7D8870
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7D9AB0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x7D9B60
#define CSidlScreenWnd__dCSidlScreenWnd                            0x7D9240
#define CSidlScreenWnd__DrawSidlPiece                              0x7D8310
#define CSidlScreenWnd__EnableIniStorage                           0x7D7AC0
#define CSidlScreenWnd__GetSidlPiece                               0x7D8530
#define CSidlScreenWnd__Init1                                      0x7D9900
#define CSidlScreenWnd__LoadIniInfo                                0x7D8930
#define CSidlScreenWnd__LoadIniListWnd                             0x7D7C10
#define CSidlScreenWnd__LoadSidlScreen                             0x7D9490
#define CSidlScreenWnd__StoreIniInfo                               0x7D7690
#define CSidlScreenWnd__StoreIniVis                                0x7D7A50
#define CSidlScreenWnd__WndNotification                            0x7D96F0
#define CSidlScreenWnd__GetChildItem                               0x7D7B20

// CSkillMgr
#define CSkillMgr__IsAvailable                                     0x5869D0
#define CSkillMgr__GetSkillCap                                     0x586A40

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7FED90
#define CSliderWnd__SetValue                                       0x7FEE90
#define CSliderWnd__SetNumTicks                                    0x7FF440

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6FA690

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x7F4080
#define CStmlWnd__CalculateHSBRange                                0x7EB680
#define CStmlWnd__CalculateVSBRange                                0x7EB710
#define CStmlWnd__CanBreakAtCharacter                              0x7EB880
#define CStmlWnd__FastForwardToEndOfTag                            0x7EC560
#define CStmlWnd__ForceParseNow                                    0x7F4670
#define CStmlWnd__GetNextTagPiece                                  0x7EC480
#define CStmlWnd__GetSTMLText                                      0x60DE30
#define CStmlWnd__GetThisChar                                      0x81F850
#define CStmlWnd__GetVisiableText                                  0x7ED9B0
#define CStmlWnd__InitializeWindowVariables                        0x7EFF90
#define CStmlWnd__MakeStmlColorTag                                 0x7EA5A0
#define CStmlWnd__MakeWndNotificationTag                           0x7EA640
#define CStmlWnd__SetSTMLText                                      0x7F00B0
#define CStmlWnd__StripFirstSTMLLines                              0x7F3D20
#define CStmlWnd__UpdateHistoryString                              0x7EE250

// CTabWnd 
#define CTabWnd__Draw                                              0x7FA990
#define CTabWnd__DrawCurrentPage                                   0x7FA210
#define CTabWnd__DrawTab                                           0x7F9FE0
#define CTabWnd__GetCurrentPage                                    0x7FA5D0
#define CTabWnd__GetPageClientRect                                 0x7F9C90
#define CTabWnd__GetPageFromTabIndex                               0x7F9F10
#define CTabWnd__GetPageInnerRect                                  0x7F9CF0
#define CTabWnd__GetTabInnerRect                                   0x7F9E90
#define CTabWnd__GetTabRect                                        0x7F9D80
#define CTabWnd__InsertPage                                        0x7FAC20
#define CTabWnd__SetPage                                           0x7FA610
#define CTabWnd__SetPageRect                                       0x7FA8C0
#define CTabWnd__UpdatePage                                        0x7FABA0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x419620

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x7D9EE0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7F7E40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x7C4930

// CXRect 
#define CXRect__CenterPoint                                        0x524D30

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4177C0
#define CXStr__CXStr1                                              0x7BF840
#define CXStr__CXStr3                                              0x823E70
#define CXStr__dCXStr                                              0x7CEC30
#define CXStr__operator_equal                                      0x823FE0
#define CXStr__operator_equal1                                     0x824030
#define CXStr__operator_plus_equal1                                0x825140

// CXWnd 
#define CXWnd__BringToTop                                          0x7CF0D0
#define CXWnd__Center                                              0x7D4B60
#define CXWnd__ClrFocus                                            0x7CEF00
#define CXWnd__DoAllDrawing                                        0x7D49E0
#define CXWnd__DrawChildren                                        0x7D4B20
#define CXWnd__DrawColoredRect                                     0x7CF410
#define CXWnd__DrawTooltip                                         0x7CF600
#define CXWnd__DrawTooltipAtPoint                                  0x7D3C20
#define CXWnd__GetBorderFrame                                      0x7CF9E0
#define CXWnd__GetChildWndAt                                       0x7D2E10
#define CXWnd__GetClientClipRect                                   0x7CF7A0
#define CXWnd__GetScreenClipRect                                   0x7D4160
#define CXWnd__GetScreenRect                                       0x7CFB10
#define CXWnd__GetTooltipRect                                      0x7CF520
#define CXWnd__GetWindowTextA                                      0x5248B0
#define CXWnd__IsActive                                            0x7DB020
#define CXWnd__IsDescendantOf                                      0x7CF8D0
#define CXWnd__IsReallyVisible                                     0x7D2DF0
#define CXWnd__IsType                                              0x7FC300
#define CXWnd__Move                                                0x7D2570
#define CXWnd__Move1                                               0x7D46A0
#define CXWnd__ProcessTransition                                   0x7CF080
#define CXWnd__Refade                                              0x7CF000
#define CXWnd__Resize                                              0x7CFBE0
#define CXWnd__Right                                               0x7D4070
#define CXWnd__SetFocus                                            0x7D16C0
#define CXWnd__SetKeyTooltip                                       0x7CFE30
#define CXWnd__SetMouseOver                                        0x7D44A0
#define CXWnd__StartFade                                           0x7CF110
#define CXWnd__GetChildItem                                        0x7D43E0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x7DC640
#define CXWndManager__DrawWindows                                  0x7DC2C0
#define CXWndManager__GetKeyboardFlags                             0x7DAC70
#define CXWndManager__HandleKeyboardMsg                            0x7DB3A0
#define CXWndManager__RemoveWnd                                    0x7DB1F0

// CDBStr
#define CDBStr__GetString                                          0x471ED0

// EQ_Character 
#define EQ_Character__CastRay                                      0x762730
#define EQ_Character__CastSpell                                    0x433970
#define EQ_Character__Cur_HP                                       0x43D2E0
#define EQ_Character__GetAACastingTimeModifier                     0x428510
#define EQ_Character__GetCharInfo2                                 0x760A70
#define EQ_Character__GetFocusCastingTimeModifier                  0x423130
#define EQ_Character__GetFocusRangeModifier                        0x423300
#define EQ_Character__Max_Endurance                                0x552EF0
#define EQ_Character__Max_HP                                       0x437990
#define EQ_Character__Max_Mana                                     0x552CF0
#define EQ_Character__doCombatAbility                              0x551AE0
#define EQ_Character__UseSkill                                     0x44CE90
#define EQ_Character__GetConLevel                                  0x548DE0
#define EQ_Character__IsExpansionFlag                              0x40DF90
#define EQ_Character__TotalEffect                                  0x42CD80

// EQ_Item 
#define EQ_Item__CanDrop                                           0x52A3E0
#define EQ_Item__CreateItemTagString                               0x746B90
#define EQ_Item__IsStackable                                       0x73ADE0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x48BE10
#define EQ_LoadingS__Array                                         0x9D9A50

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x556B10
#define EQ_PC__GetAltAbilityIndex                                  0x751E80
#define EQ_PC__GetCombatAbility                                    0x751F10
#define EQ_PC__GetCombatAbilityTimer                               0x751FC0
#define EQ_PC__GetItemTimerValue                                   0x551850
#define EQ_PC__HasLoreItem                                         0x550320

// EQItemList 
#define EQItemList__EQItemList                                     0x4BCB90
#define EQItemList__add_item                                       0x4BCB20
#define EQItemList__delete_item                                    0x4BCF40
#define EQItemList__FreeItemList                                   0x4BCE70

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x471450

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x55BCE0
#define EQPlayer__dEQPlayer                                        0x560A50
#define EQPlayer__DoAttack                                         0x572BA0
#define EQPlayer__EQPlayer                                         0x566D60
#define EQPlayer__SetNameSpriteState                               0x55E1D0
#define EQPlayer__SetNameSpriteTint                                0x55BD50
#define EQPlayer__IsBodyType_j                                     0x761FD0
#define EQPlayer__IsTargetable                                     0x7622A0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x568300
#define EQPlayerManager__GetSpawnByName                            0x568590

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x530040
#define KeypressHandler__AttachKeyToEqCommand                      0x530080
#define KeypressHandler__ClearCommandStateArray                    0x52FE50
#define KeypressHandler__HandleKeyDown                             0x52E7E0
#define KeypressHandler__HandleKeyUp                               0x52EAF0
#define KeypressHandler__SaveKeymapping                            0x52FF20

// MapViewMap 
#define MapViewMap__Clear                                          0x674EB0
#define MapViewMap__SaveEx                                         0x678560

#define PlayerPointManager__GetAltCurrency                         0x74C6E0

// StringTable 
#define StringTable__getString                                     0x748DB0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x555220
