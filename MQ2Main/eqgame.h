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
#define __ExpectedVersionDate                                     "Aug 11 2008"
#define __ExpectedVersionTime                                     "09:05:55"
#define __ActualVersionDate                                        0x71D384
#define __ActualVersionTime                                        0x71D390

#define __ClientOverride                                           0 
#define __MacroQuestWinClassName                                  "__MacroQuestTray" 
#define __MacroQuestWinName                                       "MacroQuest" 

// Memory Protection
#define __MemChecker0                                              0x4FB8F0
#define __MemChecker1                                              0x667DE0
#define __MemChecker2                                              0x5307D0
#define __MemChecker3                                              0x530720
#define __MemChecker4                                              0x62C140
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
#define __do_loot                                                  0x4A55F0
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
#define pinstCTargetOfTargetWnd                                    0xA0E8D4
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
#define __CastRay                                                  0x4B77A0
#define __ConvertItemTags                                          0x4AA960
#define __ExecuteCmd                                               0x499EE0
#define __get_melee_range                                          0x49F060
#define __GetGaugeValueFromEQ                                      0x5FD900
#define __GetLabelFromEQ                                           0x5FE110
#define __NewUIINI                                                 0x5FD4F0
#define __ProcessGameEvents                                        0x4E6B60
#define CrashDetected                                              0x52F4A0
#define DrawNetStatus                                              0x4FE6A0
#define Util__FastTime                                             0x668530


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x473940
#define AltAdvManager__IsAbilityReady                              0x473980
#define AltAdvManager__GetAltAbility                               0x473C90

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x547110

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5503B0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x693ED0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x566110
#define CChatManager__InitContextMenu                              0x5668A0

// CChatService
#define CChatService__GetNumberOfFriends                           0x658720
#define CChatService__GetFriendName                                0x658730

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x56AA10
#define CChatWindow__WndNotification                               0x56B400

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x67A180
#define CComboWnd__Draw                                            0x67A330
#define CComboWnd__GetCurChoice                                    0x67A120
#define CComboWnd__GetListRect                                     0x67A5F0
#define CComboWnd__GetTextRect                                     0x67A1B0
#define CComboWnd__InsertChoice                                    0x67A660
#define CComboWnd__SetColors                                       0x67A0B0
#define CComboWnd__SetChoice                                       0x67A0E0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x571D90
#define CContainerWnd__vftable                                     0x723EC0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x462B40
#define CDisplay__GetClickedActor                                  0x460290
#define CDisplay__GetUserDefinedColor                              0x45F410
#define CDisplay__GetWorldFilePath                                 0x45E980
#define CDisplay__is3dON                                           0x45DAE0
#define CDisplay__ReloadUI                                         0x46E6B0
#define CDisplay__WriteTextHD2                                     0x463230

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x541100
#define CEditBaseWnd__SetSel                                       0x69EF10

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x687F30
#define CEditWnd__GetCharIndexPt                                   0x688D90
#define CEditWnd__GetDisplayString                                 0x6880D0
#define CEditWnd__GetHorzOffset                                    0x688360
#define CEditWnd__GetLineForPrintableChar                          0x688840
#define CEditWnd__GetSelStartPt                                    0x688FD0
#define CEditWnd__GetSTMLSafeText                                  0x688500
#define CEditWnd__PointFromPrintableChar                           0x688950
#define CEditWnd__SelectableCharFromPoint                          0x688AD0
#define CEditWnd__SetEditable                                      0x6884D0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4CACC0
#define CEverQuest__DropHeldItemOnGround                           0x4CEF40
#define CEverQuest__dsp_chat                                       0x4D0470
#define CEverQuest__DoTellWindow                                   0x4CF0C0
#define CEverQuest__EnterZone                                      0x4E5540
#define CEverQuest__GetBodyTypeDesc                                0x4C80D0
#define CEverQuest__GetClassDesc                                   0x4C7830
#define CEverQuest__GetClassThreeLetterCode                        0x4C7E30
#define CEverQuest__GetDeityDesc                                   0x4C8740
#define CEverQuest__GetLangDesc                                    0x4C8460
#define CEverQuest__GetRaceDesc                                    0x4C8710
#define CEverQuest__InterpretCmd                                   0x4D0EA0
#define CEverQuest__LeftClickedOnPlayer                            0x4E3D60
#define CEverQuest__LMouseUp                                       0x4E6340
#define CEverQuest__RightClickedOnPlayer                           0x4E4130
#define CEverQuest__RMouseUp                                       0x4E5B40
#define CEverQuest__SetGameState                                   0x4CB140
#define CEverQuest__Emote                                          0x4D0640

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x57E0D0
#define CGaugeWnd__CalcLinesFillRect                               0x57E140
#define CGaugeWnd__Draw                                            0x57E4C0

// CGuild
#define CGuild__FindMemberByName                                   0x417DB0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5949C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x59DE00
#define CInvSlotMgr__MoveItem                                      0x59DFA0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x59C7E0
#define CInvSlot__SliderComplete                                   0x59CCF0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetItem                                   0x5ACFE0
#define CItemDisplayWnd__SetSpell                                  0x5FB5D0

// CLabel 
#define CLabel__Draw                                               0x5B2840

// CListWnd 
#define CListWnd__AddColumn                                        0x679EC0
#define CListWnd__AddColumn1                                       0x6799B0
#define CListWnd__AddLine                                          0x679590
#define CListWnd__AddString                                        0x679760
#define CListWnd__CalculateFirstVisibleLine                        0x676950
#define CListWnd__CalculateVSBRange                                0x678560
#define CListWnd__ClearAllSel                                      0x6760A0
#define CListWnd__CloseAndUpdateEditWindow                         0x676F50
#define CListWnd__Compare                                          0x6772E0
#define CListWnd__Draw                                             0x678260
#define CListWnd__DrawColumnSeparators                             0x6780D0
#define CListWnd__DrawHeader                                       0x676270
#define CListWnd__DrawItem                                         0x6779E0
#define CListWnd__DrawLine                                         0x677D80
#define CListWnd__DrawSeparator                                    0x678170
#define CListWnd__EnsureVisible                                    0x6769A0
#define CListWnd__ExtendSel                                        0x677910
#define CListWnd__GetColumnMinWidth                                0x675E40
#define CListWnd__GetColumnWidth                                   0x675D80
#define CListWnd__GetCurSel                                        0x675850
#define CListWnd__GetHeaderRect                                    0x675950
#define CListWnd__GetItemAtPoint                                   0x676C70
#define CListWnd__GetItemAtPoint1                                  0x676CE0
#define CListWnd__GetItemData                                      0x675B30
#define CListWnd__GetItemHeight                                    0x6766E0
#define CListWnd__GetItemIcon                                      0x675CC0
#define CListWnd__GetItemRect                                      0x676A60
#define CListWnd__GetItemText                                      0x675B70
#define CListWnd__GetSelList                                       0x679890
#define CListWnd__GetSeparatorRect                                 0x677220
#define CListWnd__RemoveLine                                       0x679E70
#define CListWnd__SetColors                                        0x6758B0
#define CListWnd__SetColumnJustification                           0x675EA0
#define CListWnd__SetColumnWidth                                   0x675E00
#define CListWnd__SetCurSel                                        0x675890
#define CListWnd__SetItemColor                                     0x679160
#define CListWnd__SetItemData                                      0x676140
#define CListWnd__SetItemText                                      0x6790E0
#define CListWnd__ShiftColumnSeparator                             0x677880
#define CListWnd__Sort                                             0x679EF0
#define CListWnd__ToggleSel                                        0x676010

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x5C75B0

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x5C9090
#define CMerchantWnd__RequestBuyItem                               0x5CA3C0
#define CMerchantWnd__RequestSellItem                              0x5C92E0
#define CMerchantWnd__SelectBuySellSlot                            0x5CA0F0

// CObfuscator
#define CObfuscator__doit                                          0x6353A0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x68F9F0
#define CSidlManager__CreateLabel                                  0x5F4710

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x542C20
#define CSidlScreenWnd__CalculateVSBRange                          0x6953D0
#define CSidlScreenWnd__ConvertToRes                               0x69EDF0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x681620
#define CSidlScreenWnd__CSidlScreenWnd1                            0x682460
#define CSidlScreenWnd__CSidlScreenWnd2                            0x682510
#define CSidlScreenWnd__dCSidlScreenWnd                            0x681EB0
#define CSidlScreenWnd__DrawSidlPiece                              0x681300
#define CSidlScreenWnd__EnableIniStorage                           0x680E10
#define CSidlScreenWnd__GetSidlPiece                               0x681500
#define CSidlScreenWnd__Init1                                      0x6822D0
#define CSidlScreenWnd__LoadIniInfo                                0x6816D0
#define CSidlScreenWnd__LoadIniListWnd                             0x680F60
#define CSidlScreenWnd__LoadSidlScreen                             0x681120
#define CSidlScreenWnd__StoreIniInfo                               0x680A20
#define CSidlScreenWnd__WndNotification                            0x681260

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x520260

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x69FB00
#define CSliderWnd__SetValue                                       0x69FC10
#define CSliderWnd__SetNumTicks                                    0x6A0180

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x5F9E00

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x69D0B0
#define CStmlWnd__CalculateVSBRange                                0x6953D0
#define CStmlWnd__CanBreakAtCharacter                              0x695510
#define CStmlWnd__FastForwardToEndOfTag                            0x696090
#define CStmlWnd__ForceParseNow                                    0x69D500
#define CStmlWnd__GetNextTagPiece                                  0x695FB0
#define CStmlWnd__GetSTMLText                                      0x56A9B0
#define CStmlWnd__GetThisChar                                      0x6BD550
#define CStmlWnd__GetVisiableText                                  0x6972D0
#define CStmlWnd__InitializeWindowVariables                        0x699410
#define CStmlWnd__MakeStmlColorTag                                 0x694AD0
#define CStmlWnd__MakeWndNotificationTag                           0x694B70
#define CStmlWnd__SetSTMLText                                      0x699530
#define CStmlWnd__StripFirstSTMLLines                              0x69CE40
#define CStmlWnd__UpdateHistoryString                              0x697B30

// CTabWnd 
#define CTabWnd__Draw                                              0x6A0F00
#define CTabWnd__DrawCurrentPage                                   0x6A0920
#define CTabWnd__DrawTab                                           0x6A0700
#define CTabWnd__GetCurrentPage                                    0x6A0BA0
#define CTabWnd__GetPageClientRect                                 0x6A03D0
#define CTabWnd__GetPageFromTabIndex                               0x6A0630
#define CTabWnd__GetPageInnerRect                                  0x6A0430
#define CTabWnd__GetTabInnerRect                                   0x6A05B0
#define CTabWnd__GetTabRect                                        0x6A04C0
#define CTabWnd__IndexInBounds                                     0x6A06CD
#define CTabWnd__InsertPage                                        0x6A1120
#define CTabWnd__SetPage                                           0x6A0BE0
#define CTabWnd__SetPageRect                                       0x6A0E30
#define CTabWnd__UpdatePage                                        0x6A10A0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4142A0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x682870

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x6A6610

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6755C0

// CXRect 
#define CXRect__CenterPoint                                        0x546870

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x4127A0
#define CXStr__CXStr1                                              0x66F230
#define CXStr__CXStr3                                              0x669C80
#define CXStr__dCXStr                                              0x695650
#define CXStr__operator_equal1                                     0x669E40
#define CXStr__operator_plus_equal1                                0x66AD40

// CXWnd 
#define CXWnd__BringToTop                                          0x67AEE0
#define CXWnd__Center                                              0x67EBE0
#define CXWnd__ClrFocus                                            0x67ABD0
#define CXWnd__DoAllDrawing                                        0x67F680
#define CXWnd__DrawChildren                                        0x67F7B0
#define CXWnd__DrawColoredRect                                     0x67B160
#define CXWnd__DrawTooltip                                         0x67F5A0
#define CXWnd__DrawTooltipAtPoint                                  0x67E9B0
#define CXWnd__GetBorderFrame                                      0x67B620
#define CXWnd__GetChildWndAt                                       0x67E450
#define CXWnd__GetClientClipRect                                   0x67B550
#define CXWnd__GetFirstChildWnd                                    0x67AF80
#define CXWnd__GetNextChildWnd                                     0x67E410
#define CXWnd__GetNextSib                                          0x67AFA0
#define CXWnd__GetScreenClipRect                                   0x67EE00
#define CXWnd__GetScreenRect                                       0x67B7E0
#define CXWnd__GetTooltipRect                                      0x67B380
#define CXWnd__GetWindowTextA                                      0x539FD0
#define CXWnd__IsActive                                            0x683970
#define CXWnd__IsDescendantOf                                      0x67B5D0
#define CXWnd__IsReallyVisible                                     0x67E3F0
#define CXWnd__IsType                                              0x6A1FF0
#define CXWnd__Move                                                0x67DEA0
#define CXWnd__Move1                                               0x67DF40
#define CXWnd__ProcessTransition                                   0x67AEA0
#define CXWnd__Refade                                              0x67AC80
#define CXWnd__Resize                                              0x67B8B0
#define CXWnd__Right                                               0x67ED40
#define CXWnd__SetFirstChildPointer                                0x67BA90
#define CXWnd__SetFocus                                            0x67CF10
#define CXWnd__SetKeyTooltip                                       0x67BB00
#define CXWnd__SetMouseOver                                        0x67BAD0
#define CXWnd__SetNextSibPointer                                   0x67BAB0
#define CXWnd__StartFade                                           0x67AF00

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x684E60
#define CXWndManager__DrawWindows                                  0x684AA0
#define CXWndManager__GetFirstChildWnd                             0x684310
#define CXWndManager__GetKeyboardFlags                             0x683630
#define CXWndManager__HandleKeyboardMsg                            0x683B60
#define CXWndManager__RemoveWnd                                    0x683A80

// CDBStr
#define CDBStr__GetString                                          0x45C440

// EQ_Character 
#define EQ_Character__CastRay                                      0x6C95E0
#define EQ_Character__CastSpell                                    0x425340
#define EQ_Character__Cur_HP                                       0x431A80
#define EQ_Character__GetAACastingTimeModifier                     0x41FD20
#define EQ_Character__GetCharInfo2                                 0x64AB00
#define EQ_Character__GetFocusCastingTimeModifier                  0x41B980
#define EQ_Character__GetFocusRangeModifier                        0x41BAC0
#define EQ_Character__Max_Endurance                                0x42D080
#define EQ_Character__Max_HP                                       0x42CF00
#define EQ_Character__Max_Mana                                     0x5047E0
#define EQ_Character__doCombatAbility                              0x5034A0
#define EQ_Character__UseSkill                                     0x437B90
#define EQ_Character__GetConLevel                                  0x4FFB80

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4F3650
#define EQ_Item__GetItemLinkHash                                   0x63ED80
#define EQ_Item__IsStackable                                       0x635C50

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x474B50
#define EQ_LoadingS__Array                                         0x7717D0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x507820
#define EQ_PC__GetAltAbilityIndex                                  0x643770
#define EQ_PC__GetCombatAbility                                    0x643800
#define EQ_PC__GetCombatAbilityTimer                               0x6438B0
#define EQ_PC__GetItemTimerValue                                   0x5023E0
#define EQ_PC__HasLoreItem                                         0x505C80

// EQItemList 
#define EQItemList__dEQItemList                                    0x49D7C0
#define EQItemList__EQItemList                                     0x49D710

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45BDB0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x50BFC0
#define EQPlayer__dEQPlayer                                        0x50FEE0
#define EQPlayer__DoAttack                                         0x51CD00
#define EQPlayer__EQPlayer                                         0x513B10
#define EQPlayer__SetNameSpriteState                               0x50DEE0
#define EQPlayer__SetNameSpriteTint                                0x50C030
#define EQPlayer__IsBodyType_j                                     0x6C8FB0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x514BB0
#define EQPlayerManager__GetSpawnByName                            0x514EF0

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x4F5260
#define KeypressHandler__AttachKeyToEqCommand                      0x4F52A0
#define KeypressHandler__ClearCommandStateArray                    0x4F5070
#define KeypressHandler__HandleKeyDown                             0x4F3C50
#define KeypressHandler__HandleKeyUp                               0x4F3F50
#define KeypressHandler__SaveKeymapping                            0x4F5140

// MapViewMap 
#define MapViewMap__Clear                                          0x5C2CA0
#define MapViewMap__SaveEx                                         0x5C3670

#define OtherCharData__GetAltCurrency                              0x660DF0

// StringTable 
#define StringTable__getString                                     0x635620
