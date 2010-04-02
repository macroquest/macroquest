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
#define __ExpectedVersionDate                                     "Jul  8 2008"
#define __ExpectedVersionTime                                     "16:08:38"
#define __ActualVersionDate                                        0x71D384
#define __ActualVersionTime                                        0x71D390

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4FBBF0
#define __MemChecker1                                              0x6680C0
#define __MemChecker2                                              0x530A10
#define __MemChecker3                                              0x530960
#define __MemChecker4                                              0x62C370
#define __EncryptPad0                                              0x778120
#define __EncryptPad1                                              0x781F08
#define __EncryptPad2                                              0x77AAA8
#define __EncryptPad3                                              0x77A6A8
#define __EncryptPad4                                              0x7815E8

// Direct Input
#define DI8__Main                                                  0x9E2B44
#define DI8__Keyboard                                              0x9E2B48
#define DI8__Mouse                                                 0x9E2B4C
#define __AltTimerReady                                            0x96F8A2
#define __Attack                                                   0x9CD1EE
#define __Autofire                                                 0x9CD1EF
#define __BindList                                                 0x7732C8
#define __Clicks                                                   0x96E5C0
#define __CommandList                                              0x773AD8
#define __CurrentMapLabel                                          0xA0DD60
#define __CurrentSocial                                            0x76F544
#define __DoAbilityAvailable                                       0x96F83C
#define __DoAbilityList                                            0x9A4D0C
#define __do_loot                                                  0x4A5890
#define __DrawHandler                                              0xA1D04C
#define __GroupCount                                               0x94EAD2
#define __GroupLeader                                              0x94EE24
#define __Guilds                                                   0x9507F0
#define __gWorld                                                   0x95072C
#define __HotkeyPage                                               0x9CC0F8
#define __HWnd                                                     0x9E2884
#define __InChatMode                                               0x96E4F8
#define __LastTell                                                 0x9701A4
#define __LMouseHeldTime                                           0x96E5E0
#define __Mouse                                                    0x9E2B50
#define __MouseLook                                                0x96E58E
#define __NetStatusToggle                                          0x96E590
#define __PCNames                                                  0x96FBF4
#define __RangeAttackReady                                         0x96F8A0
#define __RMouseHeldTime                                           0x96E5DC
#define __RunWalkState                                             0x96E4FC
#define __ScreenMode                                               0x89E3C8
#define __ScreenX                                                  0x96E4B0
#define __ScreenY                                                  0x96E4B4
#define __ScreenXMax                                               0x96E4B8
#define __ScreenYMax                                               0x96E4BC
#define __ServerHost                                               0x94EA1C
#define __ServerName                                               0x9A4CCC
#define __ShiftKeyDown                                             0x96EB58
#define __ShowNames                                                0x96FACC
#define __Socials                                                  0x9A4DCC


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0x968440
#define instEQZoneInfo                                             0x96E72C
#define instKeypressHandler                                        0x9CD2D8
#define pinstActiveBanker                                          0x9507C4
#define pinstActiveCorpse                                          0x9507C8
#define pinstActiveGMaster                                         0x9507CC
#define pinstActiveMerchant                                        0x9507C0
#define pinstAltAdvManager                                         0x89F218
#define pinstAuraMgr                                               0x787C8C
#define pinstBandageTarget                                         0x9507AC
#define pinstCamActor                                              0x89ED08
#define pinstCDBStr                                                0x89E3B8
#define pinstCDisplay                                              0x9507D4
#define pinstCEverQuest                                            0x9E2CC8
#define pinstCharData                                              0x950790
#define pinstCharSpawn                                             0x9507B8
#define pinstControlledMissile                                     0x95078C
#define pinstControlledPlayer                                      0x9507B8
#define pinstCSidlManager                                          0xA1C818
#define pinstCXWndManager                                          0xA1C810
#define instDynamicZone                                            0x96DF00
#define pinstDZMember                                              0x96E010
#define pinstDZTimerInfo                                           0x96E014
#define pinstEQItemList                                            0x950774
#define instEQMisc                                                 0x89E370
#define pinstEQSoundManager                                        0x89F23C
#define instExpeditionLeader                                       0x96DF4A
#define instExpeditionName                                         0x96DF8A
#define instGroup                                                  0x94ECC8
#define pinstGroup                                                 0x94EACE
#define pinstImeManager                                            0xA1C81C
#define pinstLocalPlayer                                           0x9507A4
#define pinstModelPlayer                                           0x9507D0
#define pinstPCData                                                0x950790
#define pinstSkillMgr                                              0x9DFAB4
#define pinstSpawnManager                                          0x9DFA34
#define pinstSpellManager                                          0x9DFAB8
#define pinstSpellSets                                             0x9CC0FC
#define pinstStringTable                                           0x950748
#define pinstSwitchManager                                         0x94E71C
#define pinstTarget                                                0x9507BC
#define pinstTargetObject                                          0x950794
#define pinstTargetSwitch                                          0x950798
#define pinstTaskMember                                            0x89E350
#define pinstTrackTarget                                           0x9507B0
#define pinstTradeTarget                                           0x9507A0
#define instTributeActive                                          0x89E395
#define pinstViewActor                                             0x89ED04
#define pinstWorldData                                             0x950770


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x785540
#define pinstCAudioTriggersWindow                                  0x78550C
#define pinstCCharacterSelect                                      0x89EC18
#define pinstCFacePick                                             0x89EBD0
#define pinstCNoteWnd                                              0x89EBD4
#define pinstCBookWnd                                              0x89EBD8
#define pinstCPetInfoWnd                                           0x89EBDC
#define pinstCTrainWnd                                             0x89EBE0
#define pinstCSkillsWnd                                            0x89EBE4
#define pinstCSkillsSelectWnd                                      0x89EBE8
#define pinstCCombatSkillSelectWnd                                 0x89EBEC
#define pinstCFriendsWnd                                           0x89EBF0
#define pinstCAuraWnd                                              0x89EBF4
#define pinstCRespawnWnd                                           0x89EBF8
#define pinstCBandolierWnd                                         0x89EBFC
#define pinstCPotionBeltWnd                                        0x89EC00
#define pinstCAAWnd                                                0x89EC04
#define pinstCGroupSearchFiltersWnd                                0x89EC08
#define pinstCLoadskinWnd                                          0x89EC0C
#define pinstCAlarmWnd                                             0x89EC10
#define pinstCMusicPlayerWnd                                       0x89EC14
#define pinstCMailWnd                                              0x89EC1C
#define pinstCMailCompositionWnd                                   0x89EC20
#define pinstCMailAddressBookWnd                                   0x89EC24
#define pinstCRaidWnd                                              0x89EC2C
#define pinstCRaidOptionsWnd                                       0x89EC30
#define pinstCBreathWnd                                            0x89EC34
#define pinstCMapViewWnd                                           0x89EC38
#define pinstCMapToolbarWnd                                        0x89EC3C
#define pinstCEditLabelWnd                                         0x89EC40
#define pinstCTargetWnd                                            0x89EC44
#define pinstCColorPickerWnd                                       0x89EC48
#define pinstCPlayerWnd                                            0x89EC4C
#define pinstCOptionsWnd                                           0x89EC50
#define pinstCBuffWindowNORMAL                                     0x89EC54
#define pinstCBuffWindowSHORT                                      0x89EC58
#define pinstCharacterCreation                                     0x89EC5C
#define pinstCCursorAttachment                                     0x89EC60
#define pinstCCastingWnd                                           0x89EC64
#define pinstCCastSpellWnd                                         0x89EC68
#define pinstCSpellBookWnd                                         0x89EC6C
#define pinstCInventoryWnd                                         0x89EC70
#define pinstCBankWnd                                              0x89EC74
#define pinstCQuantityWnd                                          0x89EC78
#define pinstCLootWnd                                              0x89EC7C
#define pinstCActionsWnd                                           0x89EC80
#define pinstCCombatAbilityWnd                                     0x89EC84
#define pinstCMerchantWnd                                          0x89EC88
#define pinstCTradeWnd                                             0x89EC8C
#define pinstCSelectorWnd                                          0x89EC90
#define pinstCBazaarWnd                                            0x89EC94
#define pinstCBazaarSearchWnd                                      0x89EC98
#define pinstCGiveWnd                                              0x89EC9C
#define pinstCTrackingWnd                                          0x89ECA0
#define pinstCInspectWnd                                           0x89ECA4
#define pinstCSocialEditWnd                                        0x89ECA8
#define pinstCFeedbackWnd                                          0x89ECAC
#define pinstCBugReportWnd                                         0x89ECB0
#define pinstCVideoModesWnd                                        0x89ECB4
#define pinstCTextEntryWnd                                         0x89ECBC
#define pinstCFileSelectionWnd                                     0x89ECC0
#define pinstCCompassWnd                                           0x89ECC4
#define pinstCPlayerNotesWnd                                       0x89ECC8
#define pinstCGemsGameWnd                                          0x89ECCC
#define pinstCTimeLeftWnd                                          0x89ECD0
#define pinstCPetitionQWnd                                         0x89ECD4
#define pinstCSoulmarkWnd                                          0x89ECD8
#define pinstCStoryWnd                                             0x89ECDC
#define pinstCJournalTextWnd                                       0x89ECE0
#define pinstCJournalCatWnd                                        0x89ECE4
#define pinstCBodyTintWnd                                          0x89ECE8
#define pinstCServerListWnd                                        0x89ECEC
#define pinstCAvaZoneWnd                                           0x89ECF0
#define pinstCBlockedBuffWnd                                       0x89ECF4
#define pinstCBlockedPetBuffWnd                                    0x89ECF8
#define pinstCInvSlotMgr                                           0x89ECFC
#define pinstCContainerMgr                                         0x89ED00
#define pinstCAdventureLeaderboardWnd                              0xA0B2B0
#define pinstCAdventureRequestWnd                                  0xA0B2CC
#define pinstCAltStorageWnd                                        0xA0B32C
#define pinstCAdventureStatsWnd                                    0xA0B2E8
#define pinstCBarterMerchantWnd                                    0xA0B4F8
#define pinstCBarterSearchWnd                                      0xA0B514
#define pinstCBarterWnd                                            0xA0B530
#define pinstCChatManager                                          0xA0B7D4
#define pinstCDynamicZoneWnd                                       0xA0B8CC
#define pinstCEQMainWnd                                            0xA0B93C
#define pinstCFellowshipWnd                                        0xA0B9A0
#define pinstCFindLocationWnd                                      0xA0B9D4
#define pinstCGroupSearchWnd                                       0xA0BA84
#define pinstCGroupWnd                                             0xA0BAA0
#define pinstCGuildBankWnd                                         0xA0BABC
#define pinstCGuildMgmtWnd                                         0xA0DAD8
#define pinstCGuildTributeMasterWnd                                0xA0DAF8
#define pinstCHotButtonWnd                                         0xA0DB14
#define pinstCHotButtonWnd1                                        0xA0DB14
#define pinstCHotButtonWnd2                                        0xA0DB18
#define pinstCHotButtonWnd3                                        0xA0DB1C
#define pinstCHotButtonWnd4                                        0xA0DB20
#define pinstCItemDisplayManager                                   0xA0DBCC
#define pinstCItemExpTransferWnd                                   0xA0DBEC
#define pinstCLeadershipWnd                                        0xA0DC88
#define pinstCLFGuildWnd                                           0xA0DCA4
#define pinstCMIZoneSelectWnd                                      0xA0DDC8
#define pinstCAdventureMerchantWnd                                 0xA0DEC0
#define pinstCConfirmationDialog                                   0xA0DEDC
#define pinstCPopupWndManager                                      0xA0DEDC
#define pinstCProgressionSelectionWnd                              0xA0DF10
#define pinstCPvPLeaderboardWnd                                    0xA0DF2C
#define pinstCPvPStatsWnd                                          0xA0DF48
#define pinstCSystemInfoDialogBox                                  0xA0DFF8
#define pinstCTargetOfTargetWnd                                    0xA0E8EC
#define pinstCTaskSelectWnd                                        0xA0E908
#define pinstCTaskTemplateSelectWnd                                0xA0E924
#define pinstCTaskWnd                                              0xA0E940
#define pinstCTipWndOFDAY                                          0xA0E9BC
#define pinstCTipWndCONTEXT                                        0xA0E9C0
#define pinstCTitleWnd                                             0xA0E9DC
#define pinstCTradeskillWnd                                        0xA0EA20
#define pinstCTributeBenefitWnd                                    0xA0EA6C
#define pinstCTributeMasterWnd                                     0xA0EA88
#define pinstCContextMenuManager                                   0xA1C874
#define pinstCVoiceMacroWnd                                        0x9DFBA4
#define pinstCHtmlWnd                                              0x9DFBC0


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4B7A40
#define __ConvertItemTags                                          0x4AAC00
#define __ExecuteCmd                                               0x49A150
#define __get_melee_range                                          0x49F300
#define __GetGaugeValueFromEQ                                      0x5FDBB0
#define __GetLabelFromEQ                                           0x5FE3C0
#define __NewUIINI                                                 0x5FD7A0
#define __ProcessGameEvents                                        0x4E6DD0
#define CrashDetected                                              0x52F6E0
#define DrawNetStatus                                              0x4FE9E0
#define Util__FastTime                                             0x668810


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x473CD0
#define AltAdvManager__IsAbilityReady                              0x473D10
#define AltAdvManager__GetAltAbility                               0x473F30

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5472E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x550A40

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x693FE0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5661C0
#define CChatManager__InitContextMenu                              0x566950

// CChatService
#define CChatService__GetNumberOfFriends                           0x658AA0
#define CChatService__GetFriendName                                0x658AB0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x56AAC0
#define CChatWindow__WndNotification                               0x56B4B0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x67A350
#define CComboWnd__Draw                                            0x67A500
#define CComboWnd__GetCurChoice                                    0x67A2F0
#define CComboWnd__GetListRect                                     0x67A7C0
#define CComboWnd__GetTextRect                                     0x67A380
#define CComboWnd__InsertChoice                                    0x67A830
#define CComboWnd__SetColors                                       0x67A280
#define CComboWnd__SetChoice                                       0x67A2B0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x572080
#define CContainerWnd__vftable                                     0x723EC0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x462ED0
#define CDisplay__GetClickedActor                                  0x4605E0
#define CDisplay__GetUserDefinedColor                              0x45F760
#define CDisplay__GetWorldFilePath                                 0x45ECD0
#define CDisplay__is3dON                                           0x45DE30
#define CDisplay__ReloadUI                                         0x46EA40
#define CDisplay__WriteTextHD2                                     0x4635C0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x541320
#define CEditBaseWnd__SetSel                                       0x69EF90

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x688110
#define CEditWnd__GetCharIndexPt                                   0x688F70
#define CEditWnd__GetDisplayString                                 0x6882B0
#define CEditWnd__GetHorzOffset                                    0x688540
#define CEditWnd__GetLineForPrintableChar                          0x688A20
#define CEditWnd__GetSelStartPt                                    0x6891B0
#define CEditWnd__GetSTMLSafeText                                  0x6886E0
#define CEditWnd__PointFromPrintableChar                           0x688B30
#define CEditWnd__SelectableCharFromPoint                          0x688CB0
#define CEditWnd__SetEditable                                      0x6886B0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4CAF30
#define CEverQuest__DropHeldItemOnGround                           0x4CF1B0
#define CEverQuest__dsp_chat                                       0x4D06E0
#define CEverQuest__DoTellWindow                                   0x4CF330
#define CEverQuest__EnterZone                                      0x4E57B0
#define CEverQuest__GetBodyTypeDesc                                0x4C83B0
#define CEverQuest__GetClassDesc                                   0x4C7B10
#define CEverQuest__GetClassThreeLetterCode                        0x4C8110
#define CEverQuest__GetDeityDesc                                   0x4C8A20
#define CEverQuest__GetLangDesc                                    0x4C8740
#define CEverQuest__GetRaceDesc                                    0x4C89F0
#define CEverQuest__InterpretCmd                                   0x4D1110
#define CEverQuest__LeftClickedOnPlayer                            0x4E3FD0
#define CEverQuest__LMouseUp                                       0x4E65B0
#define CEverQuest__RightClickedOnPlayer                           0x4E43A0
#define CEverQuest__RMouseUp                                       0x4E5DB0
#define CEverQuest__SetGameState                                   0x4CB3B0
#define CEverQuest__Emote                                          0x4D08B0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x57E400
#define CGaugeWnd__CalcLinesFillRect                               0x57E470
#define CGaugeWnd__Draw                                            0x57E7F0

// CGuild
#define CGuild__FindMemberByName                                   0x4180E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x594CB0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x59E0B0
#define CInvSlotMgr__MoveItem                                      0x59E250

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x59CA90
#define CInvSlot__SliderComplete                                   0x59CFA0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5AD1B0
#define CItemDisplayWnd__SetSpell                                  0x5FB870

// CLabel 
#define CLabel__Draw                                               0x5B2A10

// CListWnd 
#define CListWnd__AddColumn                                        0x67A070
#define CListWnd__AddColumn1                                       0x679BB0
#define CListWnd__AddLine                                          0x679740
#define CListWnd__AddString                                        0x679910
#define CListWnd__CalculateFirstVisibleLine                        0x676B00
#define CListWnd__CalculateVSBRange                                0x678710
#define CListWnd__ClearAllSel                                      0x676250
#define CListWnd__CloseAndUpdateEditWindow                         0x677100
#define CListWnd__Compare                                          0x677490
#define CListWnd__Draw                                             0x678410
#define CListWnd__DrawColumnSeparators                             0x678280
#define CListWnd__DrawHeader                                       0x676420
#define CListWnd__DrawItem                                         0x677B90
#define CListWnd__DrawLine                                         0x677F30
#define CListWnd__DrawSeparator                                    0x678320
#define CListWnd__EnsureVisible                                    0x676B50
#define CListWnd__ExtendSel                                        0x677AC0
#define CListWnd__GetColumnMinWidth                                0x675FF0
#define CListWnd__GetColumnWidth                                   0x675F30
#define CListWnd__GetCurSel                                        0x675A00
#define CListWnd__GetHeaderRect                                    0x675B00
#define CListWnd__GetItemAtPoint                                   0x676E20
#define CListWnd__GetItemAtPoint1                                  0x676E90
#define CListWnd__GetItemData                                      0x675CE0
#define CListWnd__GetItemHeight                                    0x676890
#define CListWnd__GetItemIcon                                      0x675E70
#define CListWnd__GetItemRect                                      0x676C10
#define CListWnd__GetItemText                                      0x675D20
#define CListWnd__GetSelList                                       0x679A90
#define CListWnd__GetSeparatorRect                                 0x6773D0
#define CListWnd__RemoveLine                                       0x679A40
#define CListWnd__SetColors                                        0x675A60
#define CListWnd__SetColumnJustification                           0x676050
#define CListWnd__SetColumnWidth                                   0x675FB0
#define CListWnd__SetCurSel                                        0x675A40
#define CListWnd__SetItemColor                                     0x679310
#define CListWnd__SetItemData                                      0x6762F0
#define CListWnd__SetItemText                                      0x679290
#define CListWnd__ShiftColumnSeparator                             0x677A30
#define CListWnd__Sort                                             0x67A0A0
#define CListWnd__ToggleSel                                        0x6761C0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5C7790

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5C9280
#define CMerchantWnd__RequestBuyItem                               0x5CA5B0
#define CMerchantWnd__RequestSellItem                              0x5C94D0
#define CMerchantWnd__SelectBuySellSlot                            0x5CA2E0

// CObfuscator
#define CObfuscator__doit                                          0x6356A0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x68FC10
#define CSidlManager__CreateLabel                                  0x5F4A10

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x542E00
#define CSidlScreenWnd__CalculateVSBRange                          0x542D50
#define CSidlScreenWnd__ConvertToRes                               0x69EE70
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x681800
#define CSidlScreenWnd__CSidlScreenWnd1                            0x682640
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6826F0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x682090
#define CSidlScreenWnd__DrawSidlPiece                              0x6814E0
#define CSidlScreenWnd__EnableIniStorage                           0x680FF0
#define CSidlScreenWnd__GetSidlPiece                               0x6816E0
#define CSidlScreenWnd__Init1                                      0x6824B0
#define CSidlScreenWnd__LoadIniInfo                                0x6818B0
#define CSidlScreenWnd__LoadIniListWnd                             0x681140
#define CSidlScreenWnd__LoadSidlScreen                             0x681300
#define CSidlScreenWnd__StoreIniInfo                               0x680C00
#define CSidlScreenWnd__WndNotification                            0x681440

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x520560

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x69FB80
#define CSliderWnd__SetValue                                       0x69FC80
#define CSliderWnd__SetNumTicks                                    0x6A01F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5FA0B0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x69D130
#define CStmlWnd__CalculateVSBRange                                0x678710
#define CStmlWnd__CanBreakAtCharacter                              0x695620
#define CStmlWnd__FastForwardToEndOfTag                            0x696130
#define CStmlWnd__ForceParseNow                                    0x69D580
#define CStmlWnd__GetNextTagPiece                                  0x696050
#define CStmlWnd__GetSTMLText                                      0x56AA60
#define CStmlWnd__GetThisChar                                      0x6BD660
#define CStmlWnd__GetVisiableText                                  0x697350
#define CStmlWnd__InitializeWindowVariables                        0x699490
#define CStmlWnd__MakeStmlColorTag                                 0x694BE0
#define CStmlWnd__MakeWndNotificationTag                           0x694C80
#define CStmlWnd__SetSTMLText                                      0x6995B0
#define CStmlWnd__StripFirstSTMLLines                              0x69CEC0
#define CStmlWnd__UpdateHistoryString                              0x697BB0

// CTabWnd 
#define CTabWnd__Draw                                              0x6A0F70
#define CTabWnd__DrawCurrentPage                                   0x6A0990
#define CTabWnd__DrawTab                                           0x6A0770
#define CTabWnd__GetCurrentPage                                    0x6A0C10
#define CTabWnd__GetPageClientRect                                 0x6A0440
#define CTabWnd__GetPageFromTabIndex                               0x6A06A0
#define CTabWnd__GetPageInnerRect                                  0x6A04A0
#define CTabWnd__GetTabInnerRect                                   0x6A0620
#define CTabWnd__GetTabRect                                        0x6A0530
#define CTabWnd__IndexInBounds                                     0x6A073D
#define CTabWnd__InsertPage                                        0x6A1190
#define CTabWnd__SetPage                                           0x6A0C50
#define CTabWnd__SetPageRect                                       0x6A0EA0
#define CTabWnd__UpdatePage                                        0x6A1110

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4145D0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x682A50

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6A6680

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x675770

// CXRect 
#define CXRect__CenterPoint                                        0x546A40

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4F5C00
#define CXStr__CXStr1                                              0x66F3D0
#define CXStr__CXStr3                                              0x669F60
#define CXStr__dCXStr                                              0x67A1F0
#define CXStr__operator_equal1                                     0x66A120
#define CXStr__operator_plus_equal1                                0x66B020

// CXWnd 
#define CXWnd__BringToTop                                          0x67B0C0
#define CXWnd__Center                                              0x67EDC0
#define CXWnd__ClrFocus                                            0x67ADA0
#define CXWnd__DoAllDrawing                                        0x67F860
#define CXWnd__DrawChildren                                        0x67F990
#define CXWnd__DrawColoredRect                                     0x67B340
#define CXWnd__DrawTooltip                                         0x67F780
#define CXWnd__DrawTooltipAtPoint                                  0x67EB90
#define CXWnd__GetBorderFrame                                      0x67B800
#define CXWnd__GetChildWndAt                                       0x67E630
#define CXWnd__GetClientClipRect                                   0x67B730
#define CXWnd__GetFirstChildWnd                                    0x67B160
#define CXWnd__GetNextChildWnd                                     0x67E5F0
#define CXWnd__GetNextSib                                          0x67B180
#define CXWnd__GetScreenClipRect                                   0x67EFE0
#define CXWnd__GetScreenRect                                       0x67B9C0
#define CXWnd__GetTooltipRect                                      0x67B560
#define CXWnd__GetWindowTextA                                      0x53A1F0
#define CXWnd__IsActive                                            0x683B50
#define CXWnd__IsDescendantOf                                      0x67B7B0
#define CXWnd__IsReallyVisible                                     0x67E5D0
#define CXWnd__IsType                                              0x6A2080
#define CXWnd__Move                                                0x67E080
#define CXWnd__Move1                                               0x67E120
#define CXWnd__ProcessTransition                                   0x67B080
#define CXWnd__Refade                                              0x67AE50
#define CXWnd__Resize                                              0x67BA90
#define CXWnd__Right                                               0x67EF20
#define CXWnd__SetFirstChildPointer                                0x67BC70
#define CXWnd__SetFocus                                            0x67D0F0
#define CXWnd__SetKeyTooltip                                       0x67BCE0
#define CXWnd__SetMouseOver                                        0x67BCB0
#define CXWnd__SetNextSibPointer                                   0x67BC90
#define CXWnd__StartFade                                           0x67B0E0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x685040
#define CXWndManager__DrawWindows                                  0x684C80
#define CXWndManager__GetFirstChildWnd                             0x6844F0
#define CXWndManager__GetKeyboardFlags                             0x683810
#define CXWndManager__HandleKeyboardMsg                            0x683D40
#define CXWndManager__RemoveWnd                                    0x683C60

// CDBStr
#define CDBStr__GetString                                          0x45C7B0

// EQ_Character 
#define EQ_Character__CastRay                                      0x6C95A0
#define EQ_Character__CastSpell                                    0x425650
#define EQ_Character__Cur_HP                                       0x431D90
#define EQ_Character__GetAACastingTimeModifier                     0x420030
#define EQ_Character__GetCharInfo2                                 0x64AE70
#define EQ_Character__GetFocusCastingTimeModifier                  0x41BCA0
#define EQ_Character__GetFocusRangeModifier                        0x41BDE0
#define EQ_Character__Max_Endurance                                0x42D390
#define EQ_Character__Max_HP                                       0x42D210
#define EQ_Character__Max_Mana                                     0x504B20
#define EQ_Character__doCombatAbility                              0x5037E0
#define EQ_Character__UseSkill                                     0x437EA0
#define EQ_Character__GetConLevel                                  0x4FFEB0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F3960
#define EQ_Item__GetItemLinkHash                                   0x63F080
#define EQ_Item__IsStackable                                       0x635F50

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x474DF0
#define EQ_LoadingS__Array                                         0x7717D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x507B60
#define EQ_PC__GetAltAbilityIndex                                  0x643AE0
#define EQ_PC__GetCombatAbility                                    0x643B70
#define EQ_PC__GetCombatAbilityTimer                               0x643C20
#define EQ_PC__GetItemTimerValue                                   0x502710
#define EQ_PC__HasLoreItem                                         0x505FC0

// EQItemList 
#define EQItemList__dEQItemList                                    0x49DA30
#define EQItemList__EQItemList                                     0x49D980

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45C120

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x50C300
#define EQPlayer__dEQPlayer                                        0x510220
#define EQPlayer__DoAttack                                         0x51D060
#define EQPlayer__EQPlayer                                         0x513EA0
#define EQPlayer__SetNameSpriteState                               0x50E220
#define EQPlayer__SetNameSpriteTint                                0x50C370
#define EQPlayer__IsBodyType_j                                     0x6C8F70

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x514F30
#define EQPlayerManager__GetSpawnByName                            0x515270

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F5570
#define KeypressHandler__AttachKeyToEqCommand                      0x4F55B0
#define KeypressHandler__ClearCommandStateArray                    0x4F5380
#define KeypressHandler__HandleKeyDown                             0x4F3F60
#define KeypressHandler__HandleKeyUp                               0x4F4260
#define KeypressHandler__SaveKeymapping                            0x4F5450

// MapViewMap 
#define MapViewMap__Clear                                          0x5C2E80
#define MapViewMap__SaveEx                                         0x5C3850

#define OtherCharData__GetAltCurrency                              0x6610C0

// StringTable 
#define StringTable__getString                                     0x635920
