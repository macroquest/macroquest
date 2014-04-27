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
#define __ExpectedVersionDate                                     "Jun 28 2011"
#define __ExpectedVersionTime                                     "09:45:34"
#define __ActualVersionDate                                        0x8ACE54
#define __ActualVersionTime                                        0x8ACE60

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x528690
#define __MemChecker1                                              0x7BDA40
#define __MemChecker2                                              0x5A0680
#define __MemChecker3                                              0x5A05D0
#define __MemChecker4                                              0x7DFA70
#define __EncryptPad0                                              0x94EB50
#define __EncryptPad1                                              0x95ADB0
#define __EncryptPad2                                              0x9518E8
#define __EncryptPad3                                              0x9514E8
#define __EncryptPad4                                              0x95C858
#define __AC1                                                      0x6BC470
#define __AC2                                                      0x4EA2C5
#define __AC3                                                      0x4FCAA8
#define __AC4                                                      0x5022E4
#define __AC5                                                      0x50E5AC
#define __AC6                                                      0x511D0E
#define __AC7                                                      0x50A20B
#define __AC1_Data                                                 0x893C4D
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
#define __do_loot                                                  0x4BF080
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
#define __CastRay                                                  0x4D3420
#define __ConvertItemTags                                          0x4C4860
#define __ExecuteCmd                                               0x4B06A0
#define __get_melee_range                                          0x4B6670
#define __GetGaugeValueFromEQ                                      0x6BB2F0
#define __GetLabelFromEQ                                           0x6BC410
#define __GetXTargetType                                           0x732F60
#define __LoadFrontEnd                                             0x59F5B0
#define __NewUIINI                                                 0x6BAEA0
#define __ProcessGameEvents                                        0x50A990
#define CrashDetected                                              0x59F3B0
#define DrawNetStatus                                              0x534B50
#define Util__FastTime                                             0x7BE240
#define Expansion_HoT                                              0xB57940

//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x483CE0
#define AltAdvManager__IsAbilityReady                              0x483D60
#define AltAdvManager__GetAltAbility                               0x483FA0

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x439600

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x5BD2C0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x5C7530

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x783EB0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5DF1A0
#define CChatManager__InitContextMenu                              0x5DF970

// CChatService
#define CChatService__GetNumberOfFriends                           0x7270A0
#define CChatService__GetFriendName                                0x7270B0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5E3CD0
#define CChatWindow__Clear                                         0x5E4620
#define CChatWindow__WndNotification                               0x5E4800

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x76DC10
#define CComboWnd__Draw                                            0x76DDD0
#define CComboWnd__GetCurChoice                                    0x76DAD0
#define CComboWnd__GetListRect                                     0x76E0A0
#define CComboWnd__GetTextRect                                     0x76DC40
#define CComboWnd__InsertChoice                                    0x76E110
#define CComboWnd__SetColors                                       0x76DA60
#define CComboWnd__SetChoice                                       0x76DA90

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5EDA50
#define CContainerWnd__vftable                                     0x8B46A0

// CDisplay 
#define CDisplay__CleanGameUI                                      0x477AC0
#define CDisplay__GetClickedActor                                  0x470AB0
#define CDisplay__GetUserDefinedColor                              0x46F490
#define CDisplay__GetWorldFilePath                                 0x46E940
#define CDisplay__is3dON                                           0x46DA70
#define CDisplay__ReloadUI                                         0x480B20
#define CDisplay__WriteTextHD2                                     0x473830

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x5B7310
#define CEditBaseWnd__SetSel                                       0x791710

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x777060
#define CEditWnd__GetCharIndexPt                                   0x777FF0
#define CEditWnd__GetDisplayString                                 0x7771F0
#define CEditWnd__GetHorzOffset                                    0x777480
#define CEditWnd__GetLineForPrintableChar                          0x777AC0
#define CEditWnd__GetSelStartPt                                    0x778230
#define CEditWnd__GetSTMLSafeText                                  0x777610
#define CEditWnd__PointFromPrintableChar                           0x777BD0
#define CEditWnd__SelectableCharFromPoint                          0x777D40
#define CEditWnd__SetEditable                                      0x7775E0

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4EA9F0
#define CEverQuest__DropHeldItemOnGround                           0x4F7F60
#define CEverQuest__dsp_chat                                       0x4F0E10
#define CEverQuest__DoTellWindow                                   0x4EF580
#define CEverQuest__EnterZone                                      0x502270
#define CEverQuest__GetBodyTypeDesc                                0x4E7860
#define CEverQuest__GetClassDesc                                   0x4E70A0
#define CEverQuest__GetClassThreeLetterCode                        0x4E76A0
#define CEverQuest__GetDeityDesc                                   0x4E7ED0
#define CEverQuest__GetLangDesc                                    0x4E7BF0
#define CEverQuest__GetRaceDesc                                    0x4E7EA0
#define CEverQuest__InterpretCmd                                   0x4F1A20
#define CEverQuest__LeftClickedOnPlayer                            0x504370
#define CEverQuest__LMouseUp                                       0x507EF0
#define CEverQuest__RightClickedOnPlayer                           0x509050
#define CEverQuest__RMouseUp                                       0x50A1D0
#define CEverQuest__SetGameState                                   0x4EAE80
#define CEverQuest__Emote                                          0x4F1030

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5FAB60
#define CGaugeWnd__CalcLinesFillRect                               0x5FABC0
#define CGaugeWnd__Draw                                            0x5FB010

// CGuild
#define CGuild__FindMemberByName                                   0x41BAC0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x613CF0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x61F720
#define CInvSlotMgr__MoveItem                                      0x61FB30

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x61EBD0
#define CInvSlot__SliderComplete                                   0x61CFC0
#define CInvSlot__GetItemBase                                      0x61C720

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x620910

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6B8BC0
#define CItemDisplayWnd__UpdateStrings                             0x621800

// CLabel 
#define CLabel__Draw                                               0x635C10

// CListWnd 
#define CListWnd__AddColumn                                        0x766840
#define CListWnd__AddColumn1                                       0x765EB0
#define CListWnd__AddLine                                          0x765A60
#define CListWnd__AddString                                        0x765C00
#define CListWnd__CalculateFirstVisibleLine                        0x761DA0
#define CListWnd__CalculateVSBRange                                0x7640B0
#define CListWnd__ClearAllSel                                      0x761300
#define CListWnd__CloseAndUpdateEditWindow                         0x7650D0
#define CListWnd__Compare                                          0x762780
#define CListWnd__Draw                                             0x763CF0
#define CListWnd__DrawColumnSeparators                             0x763B60
#define CListWnd__DrawHeader                                       0x761590
#define CListWnd__DrawItem                                         0x763180
#define CListWnd__DrawLine                                         0x7637E0
#define CListWnd__DrawSeparator                                    0x763C00
#define CListWnd__EnsureVisible                                    0x761EF0
#define CListWnd__ExtendSel                                        0x7630A0
#define CListWnd__GetColumnMinWidth                                0x760FD0
#define CListWnd__GetColumnWidth                                   0x760F10
#define CListWnd__GetCurSel                                        0x760780
#define CListWnd__GetHeaderRect                                    0x7608F0
#define CListWnd__GetItemAtPoint                                   0x7621B0
#define CListWnd__GetItemAtPoint1                                  0x762220
#define CListWnd__GetItemData                                      0x760B10
#define CListWnd__GetItemHeight                                    0x761A20
#define CListWnd__GetItemIcon                                      0x760CF0
#define CListWnd__GetItemRect                                      0x761FB0
#define CListWnd__GetItemText                                      0x760BA0
#define CListWnd__GetSelList                                       0x765D90
#define CListWnd__GetSeparatorRect                                 0x7626D0
#define CListWnd__RemoveLine                                       0x7667F0
#define CListWnd__SetColors                                        0x760850
#define CListWnd__SetColumnJustification                           0x761170
#define CListWnd__SetColumnWidth                                   0x760F90
#define CListWnd__SetCurSel                                        0x7607C0
#define CListWnd__SetItemColor                                     0x764D90
#define CListWnd__SetItemData                                      0x7613A0
#define CListWnd__SetItemText                                      0x764B70
#define CListWnd__ShiftColumnSeparator                             0x7649E0
#define CListWnd__Sort                                             0x766F80
#define CListWnd__ToggleSel                                        0x761270

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x64BB90

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x65E160
#define CMerchantWnd__RequestBuyItem                               0x661AB0
#define CMerchantWnd__RequestSellItem                              0x681A80
#define CMerchantWnd__SelectBuySellSlot                            0x65F6F0

// CObfuscator
#define CObfuscator__doit                                          0x6F6FD0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x77F850
#define CSidlManager__CreateLabel                                  0x6B1A30

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5B94A0
#define CSidlScreenWnd__CalculateVSBRange                          0x5B93D0
#define CSidlScreenWnd__ConvertToRes                               0x7915F0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x770180
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7712C0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x771370
#define CSidlScreenWnd__dCSidlScreenWnd                            0x770AE0
#define CSidlScreenWnd__DrawSidlPiece                              0x76FC50
#define CSidlScreenWnd__EnableIniStorage                           0x76F440
#define CSidlScreenWnd__GetSidlPiece                               0x76FE60
#define CSidlScreenWnd__Init1                                      0x771120
#define CSidlScreenWnd__LoadIniInfo                                0x770230
#define CSidlScreenWnd__LoadIniListWnd                             0x76F590
#define CSidlScreenWnd__LoadSidlScreen                             0x770D30
#define CSidlScreenWnd__StoreIniInfo                               0x76F040
#define CSidlScreenWnd__StoreIniVis                                0x76F3D0
#define CSidlScreenWnd__WndNotification                            0x770F10
#define CSidlScreenWnd__GetChildItem                               0x76F4A0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x56C4E0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x792000
#define CSliderWnd__SetValue                                       0x792100
#define CSliderWnd__SetNumTicks                                    0x7926B0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6B67D0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x78EC90
#define CStmlWnd__CalculateHSBRange                                0x786330
#define CStmlWnd__CalculateVSBRange                                0x7863B0
#define CStmlWnd__CanBreakAtCharacter                              0x786530
#define CStmlWnd__FastForwardToEndOfTag                            0x787200
#define CStmlWnd__ForceParseNow                                    0x78F1C0
#define CStmlWnd__GetNextTagPiece                                  0x787120
#define CStmlWnd__GetSTMLText                                      0x5E3C70
#define CStmlWnd__GetThisChar                                      0x7B6C50
#define CStmlWnd__GetVisiableText                                  0x788660
#define CStmlWnd__InitializeWindowVariables                        0x78AC30
#define CStmlWnd__MakeStmlColorTag                                 0x785250
#define CStmlWnd__MakeWndNotificationTag                           0x7852F0
#define CStmlWnd__SetSTMLText                                      0x78AD50
#define CStmlWnd__StripFirstSTMLLines                              0x78E940
#define CStmlWnd__UpdateHistoryString                              0x788EF0

// CTabWnd 
#define CTabWnd__Draw                                              0x7935B0
#define CTabWnd__DrawCurrentPage                                   0x792E80
#define CTabWnd__DrawTab                                           0x792C60
#define CTabWnd__GetCurrentPage                                    0x793240
#define CTabWnd__GetPageClientRect                                 0x792910
#define CTabWnd__GetPageFromTabIndex                               0x792B90
#define CTabWnd__GetPageInnerRect                                  0x792970
#define CTabWnd__GetTabInnerRect                                   0x792B10
#define CTabWnd__GetTabRect                                        0x792A00
#define CTabWnd__InsertPage                                        0x793840
#define CTabWnd__SetPage                                           0x793280
#define CTabWnd__SetPageRect                                       0x7934E0
#define CTabWnd__UpdatePage                                        0x7937C0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x418070

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x7716F0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x794440

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x75F640

// CXRect 
#define CXRect__CenterPoint                                        0x5354C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x416270
#define CXStr__CXStr1                                              0x66A970
#define CXStr__CXStr3                                              0x7BB220
#define CXStr__dCXStr                                              0x471B80
#define CXStr__operator_equal                                      0x7BB390
#define CXStr__operator_equal1                                     0x7BB3E0
#define CXStr__operator_plus_equal1                                0x7BC470

// CXWnd 
#define CXWnd__BringToTop                                          0x767570
#define CXWnd__Center                                              0x76C560
#define CXWnd__ClrFocus                                            0x767390
#define CXWnd__DoAllDrawing                                        0x76CE80
#define CXWnd__DrawChildren                                        0x76CFC0
#define CXWnd__DrawColoredRect                                     0x767850
#define CXWnd__DrawTooltip                                         0x76C490
#define CXWnd__DrawTooltipAtPoint                                  0x76BB70
#define CXWnd__GetBorderFrame                                      0x767D40
#define CXWnd__GetChildWndAt                                       0x76B030
#define CXWnd__GetClientClipRect                                   0x767B10
#define CXWnd__GetScreenClipRect                                   0x76C0A0
#define CXWnd__GetScreenRect                                       0x767E80
#define CXWnd__GetTooltipRect                                      0x767960
#define CXWnd__GetWindowTextA                                      0x5AA670
#define CXWnd__IsActive                                            0x772820
#define CXWnd__IsDescendantOf                                      0x767C70
#define CXWnd__IsReallyVisible                                     0x76B010
#define CXWnd__IsType                                              0x797230
#define CXWnd__Move                                                0x76A4D0
#define CXWnd__Move1                                               0x76A590
#define CXWnd__ProcessTransition                                   0x767520
#define CXWnd__Refade                                              0x7674A0
#define CXWnd__Resize                                              0x767F40
#define CXWnd__Right                                               0x76BFB0
#define CXWnd__SetFocus                                            0x769700
#define CXWnd__SetKeyTooltip                                       0x768190
#define CXWnd__SetMouseOver                                        0x76C380
#define CXWnd__StartFade                                           0x7675B0
#define CXWnd__GetChildItem                                        0x76C2F0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x773D90
#define CXWndManager__DrawWindows                                  0x773A10
#define CXWndManager__GetKeyboardFlags                             0x772480
#define CXWndManager__HandleKeyboardMsg                            0x772AF0
#define CXWndManager__RemoveWnd                                    0x772940

// CDBStr
#define CDBStr__GetString                                          0x46C2E0

// EQ_Character 
#define EQ_Character__CastRay                                      0x714A10
#define EQ_Character__CastSpell                                    0x4304A0
#define EQ_Character__Cur_HP                                       0x4392C0
#define EQ_Character__GetAACastingTimeModifier                     0x425450
#define EQ_Character__GetCharInfo2                                 0x7137A0
#define EQ_Character__GetFocusCastingTimeModifier                  0x420B80
#define EQ_Character__GetFocusRangeModifier                        0x420D50
#define EQ_Character__Max_Endurance                                0x53CC60
#define EQ_Character__Max_HP                                       0x434280
#define EQ_Character__Max_Mana                                     0x53CA60
#define EQ_Character__doCombatAbility                              0x53B8E0
#define EQ_Character__UseSkill                                     0x447B50
#define EQ_Character__GetConLevel                                  0x536A70
#define EQ_Character__IsExpansionFlag                              0x40D990
#define EQ_Character__TotalEffect                                  0x429990

// EQ_Item 
#define EQ_Item__CanDrop                                           0x51BE60
#define EQ_Item__CreateItemTagString                               0x702260
#define EQ_Item__IsStackable                                       0x6F7650

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x485050
#define EQ_LoadingS__Array                                         0x947468

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x540190
#define EQ_PC__GetAltAbilityIndex                                  0x708730
#define EQ_PC__GetCombatAbility                                    0x7087C0
#define EQ_PC__GetCombatAbilityTimer                               0x708870
#define EQ_PC__GetItemTimerValue                                   0x53B700
#define EQ_PC__HasLoreItem                                         0x712300

// EQItemList 
#define EQItemList__EQItemList                                     0x4B4940
#define EQItemList__add_item                                       0x4B48D0
#define EQItemList__delete_item                                    0x4B4CF0
#define EQItemList__FreeItemList                                   0x4B4C20

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x46BAB0

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x544D40
#define EQPlayer__dEQPlayer                                        0x5497F0
#define EQPlayer__DoAttack                                         0x55A640
#define EQPlayer__EQPlayer                                         0x54F0A0
#define EQPlayer__SetNameSpriteState                               0x547170
#define EQPlayer__SetNameSpriteTint                                0x544DB0
#define EQPlayer__IsBodyType_j                                     0x7142D0
#define EQPlayer__IsTargetable                                     0x714590

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x550370
#define EQPlayerManager__GetSpawnByName                            0x550600

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x521920
#define KeypressHandler__AttachKeyToEqCommand                      0x521960
#define KeypressHandler__ClearCommandStateArray                    0x521730
#define KeypressHandler__HandleKeyDown                             0x520130
#define KeypressHandler__HandleKeyUp                               0x520440
#define KeypressHandler__SaveKeymapping                            0x521800

// MapViewMap 
#define MapViewMap__Clear                                          0x647210
#define MapViewMap__SaveEx                                         0x647BE0

#define PlayerPointManager__GetAltCurrency                         0x7033F0

// StringTable 
#define StringTable__getString                                     0x6F7250

// PcZoneClient
#define PcZoneClient__GetPcSkillLimit                              0x53E920
