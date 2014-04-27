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
#define __ExpectedVersionDate                                     "Jun 30 2011"
#define __ExpectedVersionTime                                     "15:30:35"
#define __ActualVersionDate                                        0x8ACE54
#define __ActualVersionTime                                        0x8ACE60

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x5282E0
#define __MemChecker1                                              0x7BDBB0
#define __MemChecker2                                              0x5A00C0
#define __MemChecker3                                              0x5A0010
#define __MemChecker4                                              0x7DFAD0
#define __EncryptPad0                                              0x94EB50
#define __EncryptPad1                                              0x95ADB0
#define __EncryptPad2                                              0x9518E8
#define __EncryptPad3                                              0x9514E8
#define __EncryptPad4                                              0x95C858
#define __AC1                                                      0x6BC1A0
#define __AC2                                                      0x4EA115
#define __AC3                                                      0x4FC8F8
#define __AC4                                                      0x502134
#define __AC5                                                      0x50E3FC
#define __AC6                                                      0x511B5E
#define __AC7                                                      0x50A05B
#define __AC1_Data                                                 0x893C6D
// Direct Input
#define DI8__Main                                                  0xBBF3C4
#define DI8__Keyboard                                              0xBBF3C8
#define DI8__Mouse                                                 0xBBF3CC
#define __AltTimerReady                                            0xB577A6
#define __Attack                                                   0xBBB2C2
#define __Autofire                                                 0xBBB2C3
#define __BindList                                                 0x9490A8
#define __Clicks                                                   0xB56450
#define __CommandList                                              0x949A98
#define __CurrentMapLabel                                          0xBEB0D0
#define __CurrentSocial                                            0x9449D8
#define __DoAbilityAvailable                                       0xB57740
#define __DoAbilityList                                            0xB8D1E0
#define __do_loot                                                  0x4BEE70
#define __DrawHandler                                              0x1245AA4
#define __GroupCount                                               0xB4FE22
#define __Guilds                                                   0xB521B0
#define __gWorld                                                   0xB520DC
#define __HotkeyPage                                               0xBB45CC
#define __HWnd                                                     0xBBF100
#define __InChatMode                                               0xB56388
#define __LastTell                                                 0xB580F8
#define __LMouseHeldTime                                           0xB564BC
#define __Mouse                                                    0xBBF3D0
#define __MouseLook                                                0xB5641E
#define __MouseEventTime                                           0xBBB574
#define __NetStatusToggle                                          0xB56421
#define __PCNames                                                  0xB57B3C
#define __RangeAttackReady                                         0xB577A4
#define __RMouseHeldTime                                           0xB564B8
#define __RunWalkState                                             0xB5638C
#define __ScreenMode                                               0xA9F358
#define __ScreenX                                                  0xB56340
#define __ScreenY                                                  0xB56344
#define __ScreenXMax                                               0xB56348
#define __ScreenYMax                                               0xB5634C
#define __ServerHost                                               0xB4FD64
#define __ServerName                                               0xB8D1A0
#define __ShiftKeyDown                                             0xB56A4C
#define __ShowNames                                                0xB579E0
#define __Socials                                                  0xB8D2A0


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xB52CB8
#define instEQZoneInfo                                             0xB56608
#define instKeypressHandler                                        0xBBB570
#define pinstActiveBanker                                          0xB52184
#define pinstActiveCorpse                                          0xB52188
#define pinstActiveGMaster                                         0xB5218C
#define pinstActiveMerchant                                        0xB52180
#define pinstAltAdvManager                                         0xAA0280
#define pinstAuraMgr                                               0x96F4F0
#define pinstBandageTarget                                         0xB5216C
#define pinstCamActor                                              0xA9FCF8
#define pinstCDBStr                                                0xA9F330
#define pinstCDisplay                                              0xB52194
#define pinstCEverQuest                                            0xBBF548
#define pinstCharData                                              0xB52150
#define pinstCharSpawn                                             0xB52178
#define pinstControlledMissile                                     0xB5214C
#define pinstControlledPlayer                                      0xB52178
#define pinstCSidlManager                                          0x1245F74
#define pinstCXWndManager                                          0x1245F6C
#define instDynamicZone                                            0xB52710
#define pinstDZMember                                              0xB52820
#define pinstDZTimerInfo                                           0xB52824
#define pinstEQItemList                                            0xB4EEC8
#define instEQMisc                                                 0xA9F2A8
#define pinstEQSoundManager                                        0xAA02F0
#define instExpeditionLeader                                       0xB5275A
#define instExpeditionName                                         0xB5279A
#define pinstGroup                                                 0xB4FE1E
#define pinstImeManager                                            0x1245F78
#define pinstLocalPlayer                                           0xB52164
#define pinstMercenaryData                                         0xBBB9D8
#define pinstModelPlayer                                           0xB52190
#define pinstPCData                                                0xB52150
#define pinstSkillMgr                                              0xBBBFA8
#define pinstSpawnManager                                          0xBBBC40
#define pinstSpellManager                                          0xBBBFE8
#define pinstSpellSets                                             0xBB45D0
#define pinstStringTable                                           0xB520F8
#define pinstSwitchManager                                         0xB4FA30
#define pinstTarget                                                0xB5217C
#define pinstTargetObject                                          0xB52154
#define pinstTargetSwitch                                          0xB52158
#define pinstTaskMember                                            0xA9F270
#define pinstTrackTarget                                           0xB52170
#define pinstTradeTarget                                           0xB52160
#define instTributeActive                                          0xA9F2CD
#define pinstViewActor                                             0xA9FCF4
#define pinstWorldData                                             0xB52134


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x96CC50
#define pinstCAudioTriggersWindow                                  0x96CBE8
#define pinstCCharacterSelect                                      0xA9FBC8
#define pinstCFacePick                                             0xA9FB78
#define pinstCNoteWnd                                              0xA9FB80
#define pinstCBookWnd                                              0xA9FB84
#define pinstCPetInfoWnd                                           0xA9FB88
#define pinstCTrainWnd                                             0xA9FB8C
#define pinstCSkillsWnd                                            0xA9FB90
#define pinstCSkillsSelectWnd                                      0xA9FB94
#define pinstCCombatSkillSelectWnd                                 0xA9FB98
#define pinstCFriendsWnd                                           0xA9FB9C
#define pinstCAuraWnd                                              0xA9FBA0
#define pinstCRespawnWnd                                           0xA9FBA4
#define pinstCBandolierWnd                                         0xA9FBA8
#define pinstCPotionBeltWnd                                        0xA9FBAC
#define pinstCAAWnd                                                0xA9FBB0
#define pinstCGroupSearchFiltersWnd                                0xA9FBB4
#define pinstCLoadskinWnd                                          0xA9FBB8
#define pinstCAlarmWnd                                             0xA9FBBC
#define pinstCMusicPlayerWnd                                       0xA9FBC0
#define pinstCMailWnd                                              0xA9FBCC
#define pinstCMailCompositionWnd                                   0xA9FBD0
#define pinstCMailAddressBookWnd                                   0xA9FBD4
#define pinstCRaidWnd                                              0xA9FBDC
#define pinstCRaidOptionsWnd                                       0xA9FBE0
#define pinstCBreathWnd                                            0xA9FBE4
#define pinstCMapViewWnd                                           0xA9FBE8
#define pinstCMapToolbarWnd                                        0xA9FBEC
#define pinstCEditLabelWnd                                         0xA9FBF0
#define pinstCTargetWnd                                            0xA9FBF4
#define pinstCColorPickerWnd                                       0xA9FBF8
#define pinstCPlayerWnd                                            0xA9FBFC
#define pinstCOptionsWnd                                           0xA9FC00
#define pinstCBuffWindowNORMAL                                     0xA9FC04
#define pinstCBuffWindowSHORT                                      0xA9FC08
#define pinstCharacterCreation                                     0xA9FC0C
#define pinstCCursorAttachment                                     0xA9FC10
#define pinstCCastingWnd                                           0xA9FC14
#define pinstCCastSpellWnd                                         0xA9FC18
#define pinstCSpellBookWnd                                         0xA9FC1C
#define pinstCInventoryWnd                                         0xA9FC20
#define pinstCBankWnd                                              0xA9FC24
#define pinstCQuantityWnd                                          0xA9FC28
#define pinstCLootWnd                                              0xA9FC2C
#define pinstCActionsWnd                                           0xA9FC30
#define pinstCCombatAbilityWnd                                     0xA9FC34
#define pinstCMerchantWnd                                          0xA9FC38
#define pinstCTradeWnd                                             0xA9FC3C
#define pinstCSelectorWnd                                          0xA9FC40
#define pinstCBazaarWnd                                            0xA9FC44
#define pinstCBazaarSearchWnd                                      0xA9FC48
#define pinstCGiveWnd                                              0xA9FC64
#define pinstCTrackingWnd                                          0xA9FC68
#define pinstCInspectWnd                                           0xA9FC6C
#define pinstCSocialEditWnd                                        0xA9FC70
#define pinstCFeedbackWnd                                          0xA9FC74
#define pinstCBugReportWnd                                         0xA9FC78
#define pinstCVideoModesWnd                                        0xA9FC7C
#define pinstCTextEntryWnd                                         0xA9FC84
#define pinstCFileSelectionWnd                                     0xA9FC88
#define pinstCCompassWnd                                           0xA9FC8C
#define pinstCPlayerNotesWnd                                       0xA9FC90
#define pinstCGemsGameWnd                                          0xA9FC94
#define pinstCTimeLeftWnd                                          0xA9FC98
#define pinstCPetitionQWnd                                         0xA9FCAC
#define pinstCSoulmarkWnd                                          0xA9FCB0
#define pinstCStoryWnd                                             0xA9FCB4
#define pinstCJournalTextWnd                                       0xA9FCB8
#define pinstCJournalCatWnd                                        0xA9FCBC
#define pinstCBodyTintWnd                                          0xA9FCC0
#define pinstCServerListWnd                                        0xA9FCC4
#define pinstCAvaZoneWnd                                           0xA9FCCC
#define pinstCBlockedBuffWnd                                       0xA9FCD0
#define pinstCBlockedPetBuffWnd                                    0xA9FCD4
#define pinstCInvSlotMgr                                           0xA9FCEC
#define pinstCContainerMgr                                         0xA9FCF0
#define pinstCAdventureLeaderboardWnd                              0xBE7CA0
#define pinstCAdventureRequestWnd                                  0xBE7C68
#define pinstCAltStorageWnd                                        0xBE7D18
#define pinstCAdventureStatsWnd                                    0xBE7CA0
#define pinstCBarterMerchantWnd                                    0xBE8170
#define pinstCBarterSearchWnd                                      0xBE81A8
#define pinstCBarterWnd                                            0xBE81E0
#define pinstCChatManager                                          0xBE85D8
#define pinstCDynamicZoneWnd                                       0xBE87C8
#define pinstCEQMainWnd                                            0xBE8888
#define pinstCFellowshipWnd                                        0xBE8950
#define pinstCFindLocationWnd                                      0xBE89B8
#define pinstCGroupSearchWnd                                       0xBE8B18
#define pinstCGroupWnd                                             0xBE8B50
#define pinstCGuildBankWnd                                         0xBE8B88
#define pinstCGuildMgmtWnd                                         0xBEABF8
#define pinstCGuildTributeMasterWnd                                0xBEAC30
#define pinstCHotButtonWnd                                         0xBEAC80
#define pinstCHotButtonWnd1                                        0xBEAC80
#define pinstCHotButtonWnd2                                        0xBEAC84
#define pinstCHotButtonWnd3                                        0xBEAC88
#define pinstCHotButtonWnd4                                        0xBEAC8C
#define pinstCItemDisplayManager                                   0xBEADC8
#define pinstCItemExpTransferWnd                                   0xBEAE04
#define pinstCLeadershipWnd                                        0xBEAF30
#define pinstCLFGuildWnd                                           0xBEAF68
#define pinstCMIZoneSelectWnd                                      0xBEB200
#define pinstCAdventureMerchantWnd                                 0xBEB4B0
#define pinstCConfirmationDialog                                   0xBEB4E8
#define pinstCPopupWndManager                                      0xBEB4E8
#define pinstCProgressionSelectionWnd                              0xBEB550
#define pinstCPvPLeaderboardWnd                                    0xBEB588
#define pinstCPvPStatsWnd                                          0xBEB5C0
#define pinstCSystemInfoDialogBox                                  0xBEB848
#define pinstCTargetOfTargetWnd                                    0xBEC448
#define pinstCTaskSelectWnd                                        0xBEC4B0
#define pinstCTaskTemplateSelectWnd                                0xBEC4E8
#define pinstCTaskWnd                                              0xBEC520
#define pinstCTipWndOFDAY                                          0xBEC698
#define pinstCTipWndCONTEXT                                        0xBEC69C
#define pinstCTitleWnd                                             0xBEC6D0
#define pinstCTradeskillWnd                                        0xBEC748
#define pinstCTributeBenefitWnd                                    0xBEC7E0
#define pinstCTributeMasterWnd                                     0xBEC818
#define pinstCContextMenuManager                                   0x1245FD0
#define pinstCVoiceMacroWnd                                        0xBBC300
#define pinstCHtmlWnd                                              0xBBC378


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4D32E0
#define __ConvertItemTags                                          0x4C4650
#define __ExecuteCmd                                               0x4B04B0
#define __get_melee_range                                          0x4B6460
#define __GetGaugeValueFromEQ                                      0x6BB020
#define __GetLabelFromEQ                                           0x6BC140
#define __GetXTargetType                                           0x732F00
#define __LoadFrontEnd                                             0x59EFF0
#define __NewUIINI                                                 0x6BABD0
#define __ProcessGameEvents                                        0x50A7E0
#define CrashDetected                                              0x59EDF0
#define DrawNetStatus                                              0x534790
#define Util__FastTime                                             0x7BE3F0
#define Expansion_HoT                                              0xB57940

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x4839B0
#define AltAdvManager__IsAbilityReady                              0x483A60
#define AltAdvManager__GetAltAbility                               0x483D60

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x439440

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5BCC70

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5C6FF0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x784000

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5DEDA0
#define CChatManager__InitContextMenu                              0x5DF570

// CChatService
#define CChatService__GetNumberOfFriends                           0x727140
#define CChatService__GetFriendName                                0x727150

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5E38D0
#define CChatWindow__Clear                                         0x5E4220
#define CChatWindow__WndNotification                               0x5E4400

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x76DBE0
#define CComboWnd__Draw                                            0x76DDA0
#define CComboWnd__GetCurChoice                                    0x76DAA0
#define CComboWnd__GetListRect                                     0x76E070
#define CComboWnd__GetTextRect                                     0x76DC10
#define CComboWnd__InsertChoice                                    0x76E0E0
#define CComboWnd__SetColors                                       0x76DA30
#define CComboWnd__SetChoice                                       0x76DA60

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5ED6C0
#define CContainerWnd__vftable                                     0x8B46A0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x477760
#define CDisplay__GetClickedActor                                  0x4707C0
#define CDisplay__GetUserDefinedColor                              0x46F1A0
#define CDisplay__GetWorldFilePath                                 0x46E650
#define CDisplay__is3dON                                           0x46D780
#define CDisplay__ReloadUI                                         0x4807F0
#define CDisplay__WriteTextHD2                                     0x4734D0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5B6CC0
#define CEditBaseWnd__SetSel                                       0x791850

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x777000
#define CEditWnd__GetCharIndexPt                                   0x777F90
#define CEditWnd__GetDisplayString                                 0x777190
#define CEditWnd__GetHorzOffset                                    0x777420
#define CEditWnd__GetLineForPrintableChar                          0x777A60
#define CEditWnd__GetSelStartPt                                    0x7781D0
#define CEditWnd__GetSTMLSafeText                                  0x7775B0
#define CEditWnd__PointFromPrintableChar                           0x777B70
#define CEditWnd__SelectableCharFromPoint                          0x777CE0
#define CEditWnd__SetEditable                                      0x777580

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4EA840
#define CEverQuest__DropHeldItemOnGround                           0x4F7DB0
#define CEverQuest__dsp_chat                                       0x4F0C60
#define CEverQuest__DoTellWindow                                   0x4EF3D0
#define CEverQuest__EnterZone                                      0x5020C0
#define CEverQuest__GetBodyTypeDesc                                0x4E76B0
#define CEverQuest__GetClassDesc                                   0x4E6EF0
#define CEverQuest__GetClassThreeLetterCode                        0x4E74F0
#define CEverQuest__GetDeityDesc                                   0x4E7D20
#define CEverQuest__GetLangDesc                                    0x4E7A40
#define CEverQuest__GetRaceDesc                                    0x4E7CF0
#define CEverQuest__InterpretCmd                                   0x4F1870
#define CEverQuest__LeftClickedOnPlayer                            0x5041C0
#define CEverQuest__LMouseUp                                       0x507D40
#define CEverQuest__RightClickedOnPlayer                           0x508EA0
#define CEverQuest__RMouseUp                                       0x50A020
#define CEverQuest__SetGameState                                   0x4EACD0
#define CEverQuest__Emote                                          0x4F0E80

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5FA920
#define CGaugeWnd__CalcLinesFillRect                               0x5FA980
#define CGaugeWnd__Draw                                            0x5FADD0

// CGuild
#define CGuild__FindMemberByName                                   0x41B8C0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x613B50

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x61F580
#define CInvSlotMgr__MoveItem                                      0x61F990

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x61EA30
#define CInvSlot__SliderComplete                                   0x61CE20
#define CInvSlot__GetItemBase                                      0x61C580

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x620770

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6B88E0
#define CItemDisplayWnd__UpdateStrings                             0x621660

// CLabel 
#define CLabel__Draw                                               0x635A70

// CListWnd 
#define CListWnd__AddColumn                                        0x7667F0
#define CListWnd__AddColumn1                                       0x765EB0
#define CListWnd__AddLine                                          0x765A10
#define CListWnd__AddString                                        0x765BB0
#define CListWnd__CalculateFirstVisibleLine                        0x761D50
#define CListWnd__CalculateVSBRange                                0x764060
#define CListWnd__ClearAllSel                                      0x7612B0
#define CListWnd__CloseAndUpdateEditWindow                         0x765080
#define CListWnd__Compare                                          0x762730
#define CListWnd__Draw                                             0x763CA0
#define CListWnd__DrawColumnSeparators                             0x763B10
#define CListWnd__DrawHeader                                       0x761540
#define CListWnd__DrawItem                                         0x763130
#define CListWnd__DrawLine                                         0x763790
#define CListWnd__DrawSeparator                                    0x763BB0
#define CListWnd__EnsureVisible                                    0x761EA0
#define CListWnd__ExtendSel                                        0x763050
#define CListWnd__GetColumnMinWidth                                0x760F80
#define CListWnd__GetColumnWidth                                   0x760EC0
#define CListWnd__GetCurSel                                        0x760730
#define CListWnd__GetHeaderRect                                    0x7608A0
#define CListWnd__GetItemAtPoint                                   0x762160
#define CListWnd__GetItemAtPoint1                                  0x7621D0
#define CListWnd__GetItemData                                      0x760AC0
#define CListWnd__GetItemHeight                                    0x7619D0
#define CListWnd__GetItemIcon                                      0x760CA0
#define CListWnd__GetItemRect                                      0x761F60
#define CListWnd__GetItemText                                      0x760B50
#define CListWnd__GetSelList                                       0x765D90
#define CListWnd__GetSeparatorRect                                 0x762680
#define CListWnd__RemoveLine                                       0x765D40
#define CListWnd__SetColors                                        0x760800
#define CListWnd__SetColumnJustification                           0x761120
#define CListWnd__SetColumnWidth                                   0x760F40
#define CListWnd__SetCurSel                                        0x760770
#define CListWnd__SetItemColor                                     0x764D40
#define CListWnd__SetItemData                                      0x761350
#define CListWnd__SetItemText                                      0x764B20
#define CListWnd__ShiftColumnSeparator                             0x764990
#define CListWnd__Sort                                             0x766F30
#define CListWnd__ToggleSel                                        0x761220

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x64BA20

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x65DFF0
#define CMerchantWnd__RequestBuyItem                               0x661940
#define CMerchantWnd__RequestSellItem                              0x681940
#define CMerchantWnd__SelectBuySellSlot                            0x65F580

// CObfuscator
#define CObfuscator__doit                                          0x6F6E40

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x77F8E0
#define CSidlManager__CreateLabel                                  0x6B1740

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5B8E50
#define CSidlScreenWnd__CalculateVSBRange                          0x5B8D80
#define CSidlScreenWnd__ConvertToRes                               0x791730
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x770150
#define CSidlScreenWnd__CSidlScreenWnd1                            0x771260
#define CSidlScreenWnd__CSidlScreenWnd2                            0x771310
#define CSidlScreenWnd__dCSidlScreenWnd                            0x770A80
#define CSidlScreenWnd__DrawSidlPiece                              0x76FC20
#define CSidlScreenWnd__EnableIniStorage                           0x76F410
#define CSidlScreenWnd__GetSidlPiece                               0x76FE30
#define CSidlScreenWnd__Init1                                      0x7710C0
#define CSidlScreenWnd__LoadIniInfo                                0x770200
#define CSidlScreenWnd__LoadIniListWnd                             0x76F560
#define CSidlScreenWnd__LoadSidlScreen                             0x770CD0
#define CSidlScreenWnd__StoreIniInfo                               0x76F010
#define CSidlScreenWnd__StoreIniVis                                0x76F3A0
#define CSidlScreenWnd__WndNotification                            0x770EB0
#define CSidlScreenWnd__GetChildItem                               0x76F470

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x56BF70

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x792140
#define CSliderWnd__SetValue                                       0x792240
#define CSliderWnd__SetNumTicks                                    0x7927F0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6B64E0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x78EDB0
#define CStmlWnd__CalculateHSBRange                                0x786480
#define CStmlWnd__CalculateVSBRange                                0x786500
#define CStmlWnd__CanBreakAtCharacter                              0x786670
#define CStmlWnd__FastForwardToEndOfTag                            0x787340
#define CStmlWnd__ForceParseNow                                    0x78F2E0
#define CStmlWnd__GetNextTagPiece                                  0x787260
#define CStmlWnd__GetSTMLText                                      0x5E3870
#define CStmlWnd__GetThisChar                                      0x7B6DC0
#define CStmlWnd__GetVisiableText                                  0x788780
#define CStmlWnd__InitializeWindowVariables                        0x78AD50
#define CStmlWnd__MakeStmlColorTag                                 0x7853A0
#define CStmlWnd__MakeWndNotificationTag                           0x785440
#define CStmlWnd__SetSTMLText                                      0x78AE70
#define CStmlWnd__StripFirstSTMLLines                              0x78EA60
#define CStmlWnd__UpdateHistoryString                              0x789010

// CTabWnd 
#define CTabWnd__Draw                                              0x7936F0
#define CTabWnd__DrawCurrentPage                                   0x792FC0
#define CTabWnd__DrawTab                                           0x792DA0
#define CTabWnd__GetCurrentPage                                    0x793380
#define CTabWnd__GetPageClientRect                                 0x792A50
#define CTabWnd__GetPageFromTabIndex                               0x792CD0
#define CTabWnd__GetPageInnerRect                                  0x792AB0
#define CTabWnd__GetTabInnerRect                                   0x792C50
#define CTabWnd__GetTabRect                                        0x792B40
#define CTabWnd__InsertPage                                        0x793980
#define CTabWnd__SetPage                                           0x7933C0
#define CTabWnd__SetPageRect                                       0x793620
#define CTabWnd__UpdatePage                                        0x793900

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417E60

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x771690

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7945D0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x75F630

// CXRect 
#define CXRect__CenterPoint                                        0x535120

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x416060
#define CXStr__CXStr1                                              0x41E070
#define CXStr__CXStr3                                              0x7BB390
#define CXStr__dCXStr                                              0x767090
#define CXStr__operator_equal                                      0x7BB500
#define CXStr__operator_equal1                                     0x7BB550
#define CXStr__operator_plus_equal1                                0x7BC5E0

// CXWnd 
#define CXWnd__BringToTop                                          0x767540
#define CXWnd__Center                                              0x76C530
#define CXWnd__ClrFocus                                            0x767360
#define CXWnd__DoAllDrawing                                        0x76CE50
#define CXWnd__DrawChildren                                        0x76CF90
#define CXWnd__DrawColoredRect                                     0x767820
#define CXWnd__DrawTooltip                                         0x76C460
#define CXWnd__DrawTooltipAtPoint                                  0x76BB90
#define CXWnd__GetBorderFrame                                      0x767D10
#define CXWnd__GetChildWndAt                                       0x76B050
#define CXWnd__GetClientClipRect                                   0x767AE0
#define CXWnd__GetScreenClipRect                                   0x76C0C0
#define CXWnd__GetScreenRect                                       0x767E50
#define CXWnd__GetTooltipRect                                      0x767930
#define CXWnd__GetWindowTextA                                      0x5AA0E0
#define CXWnd__IsActive                                            0x7727C0
#define CXWnd__IsDescendantOf                                      0x767C40
#define CXWnd__IsReallyVisible                                     0x76B030
#define CXWnd__IsType                                              0x7973C0
#define CXWnd__Move                                                0x76A4F0
#define CXWnd__Move1                                               0x76A5B0
#define CXWnd__ProcessTransition                                   0x7674F0
#define CXWnd__Refade                                              0x767470
#define CXWnd__Resize                                              0x767F10
#define CXWnd__Right                                               0x76BFD0
#define CXWnd__SetFocus                                            0x769720
#define CXWnd__SetKeyTooltip                                       0x768160
#define CXWnd__SetMouseOver                                        0x76C350
#define CXWnd__StartFade                                           0x767580
#define CXWnd__GetChildItem                                        0x76C2C0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x773D30
#define CXWndManager__DrawWindows                                  0x7739B0
#define CXWndManager__GetKeyboardFlags                             0x772420
#define CXWndManager__HandleKeyboardMsg                            0x772A90
#define CXWndManager__RemoveWnd                                    0x7728E0

// CDBStr
#define CDBStr__GetString                                          0x46BFC0

// EQ_Character 
#define EQ_Character__CastRay                                      0x714A30
#define EQ_Character__CastSpell                                    0x4302E0
#define EQ_Character__Cur_HP                                       0x439100
#define EQ_Character__GetAACastingTimeModifier                     0x425290
#define EQ_Character__GetCharInfo2                                 0x7137D0
#define EQ_Character__GetFocusCastingTimeModifier                  0x4209B0
#define EQ_Character__GetFocusRangeModifier                        0x420B80
#define EQ_Character__Max_Endurance                                0x53C880
#define EQ_Character__Max_HP                                       0x4340C0
#define EQ_Character__Max_Mana                                     0x53C680
#define EQ_Character__doCombatAbility                              0x53B500
#define EQ_Character__UseSkill                                     0x447990
#define EQ_Character__GetConLevel                                  0x5366D0
#define EQ_Character__IsExpansionFlag                              0x40D800
#define EQ_Character__TotalEffect                                  0x4297D0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x51BBD0
#define EQ_Item__CreateItemTagString                               0x7020B0
#define EQ_Item__IsStackable                                       0x6F74C0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x484E10
#define EQ_LoadingS__Array                                         0x947468

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x53FDB0
#define EQ_PC__GetAltAbilityIndex                                  0x708750
#define EQ_PC__GetCombatAbility                                    0x7087E0
#define EQ_PC__GetCombatAbilityTimer                               0x708890
#define EQ_PC__GetItemTimerValue                                   0x53B320
#define EQ_PC__HasLoreItem                                         0x712320

// EQItemList 
#define EQItemList__EQItemList                                     0x4B4750
#define EQItemList__add_item                                       0x4B46E0
#define EQItemList__delete_item                                    0x4B4B00
#define EQItemList__FreeItemList                                   0x4B4A30

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46B7B0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x5449A0
#define EQPlayer__dEQPlayer                                        0x549460
#define EQPlayer__DoAttack                                         0x55A280
#define EQPlayer__EQPlayer                                         0x54ED30
#define EQPlayer__SetNameSpriteState                               0x546DD0
#define EQPlayer__SetNameSpriteTint                                0x544A10
#define EQPlayer__IsBodyType_j                                     0x7142F0
#define EQPlayer__IsTargetable                                     0x7145B0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x550000
#define EQPlayerManager__GetSpawnByName                            0x550290

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x5215A0
#define KeypressHandler__AttachKeyToEqCommand                      0x5215E0
#define KeypressHandler__ClearCommandStateArray                    0x5213B0
#define KeypressHandler__HandleKeyDown                             0x51FDB0
#define KeypressHandler__HandleKeyUp                               0x5200C0
#define KeypressHandler__SaveKeymapping                            0x521480

// MapViewMap 
#define MapViewMap__Clear                                          0x6470A0
#define MapViewMap__SaveEx                                         0x647A70

#define PlayerPointManager__GetAltCurrency                         0x703240

// StringTable 
#define StringTable__getString                                     0x6F70C0

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x53E540
