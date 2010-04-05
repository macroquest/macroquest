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
#define __ExpectedVersionDate                                     "Oct  7 2009"
#define __ExpectedVersionTime                                     "16:08:46"
#define __ActualVersionDate                                        0x7F8D10
#define __ActualVersionTime                                        0x7F8D1C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x507980
#define __MemChecker1                                              0x6C5A50
#define __MemChecker2                                              0x566640
#define __MemChecker3                                              0x566590
#define __MemChecker4                                              0x67FFE0
#define __EncryptPad0                                              0x884778
#define __EncryptPad1                                              0x88EF50
#define __EncryptPad2                                              0x887210
#define __EncryptPad3                                              0x886E10
#define __EncryptPad4                                              0x88E5D8
#define __AC1                                                      0x648740
#define __AC2                                                      0x4D33E5
#define __AC3                                                      0x4E6FD8
#define __AC4                                                      0x4EAEA8
#define __AC5                                                      0x4F55E8
#define __AC6                                                      0x4F89BB
#define __AC7                                                      0x4F1B44
#define __AC1_Data                                                 0x7E2400

// Direct Input
#define DI8__Main                                                  0xAE58AC
#define DI8__Keyboard                                              0xAE58B0
#define DI8__Mouse                                                 0xAE58B4
#define __AltTimerReady                                            0xA701AA
#define __Attack                                                   0xACFC9E
#define __Autofire                                                 0xACFC9F
#define __BindList                                                 0x87F6D0
#define __Clicks                                                   0xA6EEB0
#define __CommandList                                              0x87FF50
#define __CurrentMapLabel                                          0xB10AE8
#define __CurrentSocial                                            0x87B6DC
#define __DoAbilityAvailable                                       0xA70144
#define __DoAbilityList                                            0xAA5764
#define __do_loot                                                  0x4AC6A0
#define __DrawHandler                                              0xB1FF5C
#define __GroupCount                                               0xA6916A
#define __Guilds                                                   0xA6E290
#define __gWorld                                                   0xA6AC28
#define __HotkeyPage                                               0xACCB50
#define __HWnd                                                     0xAE55E8
#define __InChatMode                                               0xA6EDE8
#define __LastTell                                                 0xA70ABC
#define __LMouseHeldTime                                           0xA6EEDC
#define __Mouse                                                    0xAE58B8
#define __MouseLook                                                0xA6EE7E
#define __MouseEventTime                                           0xACFDB0
#define __NetStatusToggle                                          0xA6EE81
#define __PCNames                                                  0xA70500
#define __RangeAttackReady                                         0xA701A8
#define __RMouseHeldTime                                           0xA6EED8
#define __RunWalkState                                             0xA6EDEC
#define __ScreenMode                                               0x9B8A30
#define __ScreenX                                                  0xA6EDA0
#define __ScreenY                                                  0xA6EDA4
#define __ScreenXMax                                               0xA6EDA8
#define __ScreenYMax                                               0xA6EDAC
#define __ServerHost                                               0xA690AC
#define __ServerName                                               0xAA5724
#define __ShiftKeyDown                                             0xA6F45C
#define __ShowNames                                                0xA703D8
#define __Socials                                                  0xAA5824


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA6ACE8
#define instEQZoneInfo                                             0xA6F028
#define instKeypressHandler                                        0xACFD94
#define pinstActiveBanker                                          0xA6ACC0
#define pinstActiveCorpse                                          0xA6ACC4
#define pinstActiveGMaster                                         0xA6ACC8
#define pinstActiveMerchant                                        0xA6ACBC
#define pinstAltAdvManager                                         0x9B9898
#define pinstAuraMgr                                               0x8A22F4
#define pinstBandageTarget                                         0xA6ACA8
#define pinstCamActor                                              0x9B9384
#define pinstCDBStr                                                0x9B8A20
#define pinstCDisplay                                              0xA6ACD0
#define pinstCEverQuest                                            0xAE5A30
#define pinstCharData                                              0xA6AC8C
#define pinstCharSpawn                                             0xA6ACB4
#define pinstControlledMissile                                     0xA6AC88
#define pinstControlledPlayer                                      0xA6ACB4
#define pinstCSidlManager                                          0xB1F6E0
#define pinstCXWndManager                                          0xB1F6D8
#define instDynamicZone                                            0xA6EC70
#define pinstDZMember                                              0xA6ED80
#define pinstDZTimerInfo                                           0xA6ED84
#define pinstEQItemList                                            0xA6AC70
#define instEQMisc                                                 0x9B89D8
#define pinstEQSoundManager                                        0x9B98BC
#define instExpeditionLeader                                       0xA6ECBA
#define instExpeditionName                                         0xA6ECFA
#define pinstGroup                                                 0xA69166
#define pinstImeManager                                            0xB1F6E4
#define pinstLocalPlayer                                           0xA6ACA0
#define pinstMercenaryData                                         0xAD0108
#define pinstModelPlayer                                           0xA6ACCC
#define pinstPCData                                                0xA6AC8C
#define pinstSkillMgr                                              0xAE26A8
#define pinstSpawnManager                                          0xAE2504
#define pinstSpellManager                                          0xAE26AC
#define pinstSpellSets                                             0xACCB54
#define pinstStringTable                                           0xA6AC44
#define pinstSwitchManager                                         0xA68DAC
#define pinstTarget                                                0xA6ACB8
#define pinstTargetObject                                          0xA6AC90
#define pinstTargetSwitch                                          0xA6AC94
#define pinstTaskMember                                            0x9B89B8
#define pinstTrackTarget                                           0xA6ACAC
#define pinstTradeTarget                                           0xA6AC9C
#define instTributeActive                                          0x9B89FD
#define pinstViewActor                                             0x9B9380
#define pinstWorldData                                             0xA6AC6C


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x89FBA4
#define pinstCAudioTriggersWindow                                  0x89FB70
#define pinstCCharacterSelect                                      0x9B928C
#define pinstCFacePick                                             0x9B9240
#define pinstCNoteWnd                                              0x9B9244
#define pinstCBookWnd                                              0x9B9248
#define pinstCPetInfoWnd                                           0x9B924C
#define pinstCTrainWnd                                             0x9B9250
#define pinstCSkillsWnd                                            0x9B9254
#define pinstCSkillsSelectWnd                                      0x9B9258
#define pinstCCombatSkillSelectWnd                                 0x9B925C
#define pinstCFriendsWnd                                           0x9B9260
#define pinstCAuraWnd                                              0x9B9264
#define pinstCRespawnWnd                                           0x9B9268
#define pinstCBandolierWnd                                         0x9B926C
#define pinstCPotionBeltWnd                                        0x9B9270
#define pinstCAAWnd                                                0x9B9274
#define pinstCGroupSearchFiltersWnd                                0x9B9278
#define pinstCLoadskinWnd                                          0x9B927C
#define pinstCAlarmWnd                                             0x9B9280
#define pinstCMusicPlayerWnd                                       0x9B9284
#define pinstCMailWnd                                              0x9B9290
#define pinstCMailCompositionWnd                                   0x9B9294
#define pinstCMailAddressBookWnd                                   0x9B9298
#define pinstCRaidWnd                                              0x9B92A0
#define pinstCRaidOptionsWnd                                       0x9B92A4
#define pinstCBreathWnd                                            0x9B92A8
#define pinstCMapViewWnd                                           0x9B92AC
#define pinstCMapToolbarWnd                                        0x9B92B0
#define pinstCEditLabelWnd                                         0x9B92B4
#define pinstCTargetWnd                                            0x9B92B8
#define pinstCColorPickerWnd                                       0x9B92BC
#define pinstCPlayerWnd                                            0x9B92C0
#define pinstCOptionsWnd                                           0x9B92C4
#define pinstCBuffWindowNORMAL                                     0x9B92C8
#define pinstCBuffWindowSHORT                                      0x9B92CC
#define pinstCharacterCreation                                     0x9B92D0
#define pinstCCursorAttachment                                     0x9B92D4
#define pinstCCastingWnd                                           0x9B92D8
#define pinstCCastSpellWnd                                         0x9B92DC
#define pinstCSpellBookWnd                                         0x9B92E0
#define pinstCInventoryWnd                                         0x9B92E4
#define pinstCBankWnd                                              0x9B92E8
#define pinstCQuantityWnd                                          0x9B92EC
#define pinstCLootWnd                                              0x9B92F0
#define pinstCActionsWnd                                           0x9B92F4
#define pinstCCombatAbilityWnd                                     0x9B92F8
#define pinstCMerchantWnd                                          0x9B92FC
#define pinstCTradeWnd                                             0x9B9300
#define pinstCSelectorWnd                                          0x9B9304
#define pinstCBazaarWnd                                            0x9B9308
#define pinstCBazaarSearchWnd                                      0x9B930C
#define pinstCGiveWnd                                              0x9B9310
#define pinstCTrackingWnd                                          0x9B9314
#define pinstCInspectWnd                                           0x9B9318
#define pinstCSocialEditWnd                                        0x9B931C
#define pinstCFeedbackWnd                                          0x9B9320
#define pinstCBugReportWnd                                         0x9B9324
#define pinstCVideoModesWnd                                        0x9B9328
#define pinstCTextEntryWnd                                         0x9B9330
#define pinstCFileSelectionWnd                                     0x9B9334
#define pinstCCompassWnd                                           0x9B9338
#define pinstCPlayerNotesWnd                                       0x9B933C
#define pinstCGemsGameWnd                                          0x9B9340
#define pinstCTimeLeftWnd                                          0x9B9344
#define pinstCPetitionQWnd                                         0x9B9350
#define pinstCSoulmarkWnd                                          0x9B9354
#define pinstCStoryWnd                                             0x9B9358
#define pinstCJournalTextWnd                                       0x9B935C
#define pinstCJournalCatWnd                                        0x9B9360
#define pinstCBodyTintWnd                                          0x9B9364
#define pinstCServerListWnd                                        0x9B9368
#define pinstCAvaZoneWnd                                           0x9B936C
#define pinstCBlockedBuffWnd                                       0x9B9370
#define pinstCBlockedPetBuffWnd                                    0x9B9374
#define pinstCInvSlotMgr                                           0x9B9378
#define pinstCContainerMgr                                         0x9B937C
#define pinstCAdventureLeaderboardWnd                              0xB0E018
#define pinstCAdventureRequestWnd                                  0xB0E034
#define pinstCAltStorageWnd                                        0xB0E094
#define pinstCAdventureStatsWnd                                    0xB0E050
#define pinstCBarterMerchantWnd                                    0xB0E260
#define pinstCBarterSearchWnd                                      0xB0E27C
#define pinstCBarterWnd                                            0xB0E298
#define pinstCChatManager                                          0xB0E53C
#define pinstCDynamicZoneWnd                                       0xB0E634
#define pinstCEQMainWnd                                            0xB0E6A8
#define pinstCFellowshipWnd                                        0xB0E70C
#define pinstCFindLocationWnd                                      0xB0E740
#define pinstCGroupSearchWnd                                       0xB0E7F0
#define pinstCGroupWnd                                             0xB0E80C
#define pinstCGuildBankWnd                                         0xB0E828
#define pinstCGuildMgmtWnd                                         0xB10860
#define pinstCGuildTributeMasterWnd                                0xB10880
#define pinstCHotButtonWnd                                         0xB1089C
#define pinstCHotButtonWnd1                                        0xB1089C
#define pinstCHotButtonWnd2                                        0xB108A0
#define pinstCHotButtonWnd3                                        0xB108A4
#define pinstCHotButtonWnd4                                        0xB108A8
#define pinstCItemDisplayManager                                   0xB10954
#define pinstCItemExpTransferWnd                                   0xB10974
#define pinstCLeadershipWnd                                        0xB10A10
#define pinstCLFGuildWnd                                           0xB10A2C
#define pinstCMIZoneSelectWnd                                      0xB10B9C
#define pinstCAdventureMerchantWnd                                 0xB10CAC
#define pinstCConfirmationDialog                                   0xB10CC8
#define pinstCPopupWndManager                                      0xB10CC8
#define pinstCProgressionSelectionWnd                              0xB10CFC
#define pinstCPvPLeaderboardWnd                                    0xB10D18
#define pinstCPvPStatsWnd                                          0xB10D34
#define pinstCSystemInfoDialogBox                                  0xB10DE8
#define pinstCTargetOfTargetWnd                                    0xB116F4
#define pinstCTaskSelectWnd                                        0xB11728
#define pinstCTaskTemplateSelectWnd                                0xB11744
#define pinstCTaskWnd                                              0xB11760
#define pinstCTipWndOFDAY                                          0xB117DC
#define pinstCTipWndCONTEXT                                        0xB117E0
#define pinstCTitleWnd                                             0xB117FC
#define pinstCTradeskillWnd                                        0xB11840
#define pinstCTributeBenefitWnd                                    0xB1188C
#define pinstCTributeMasterWnd                                     0xB118A8
#define pinstCContextMenuManager                                   0xB1F73C
#define pinstCVoiceMacroWnd                                        0xAE289C
#define pinstCHtmlWnd                                              0xAE28E8


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4C00D0
#define __ConvertItemTags                                          0x4B1C60
#define __ExecuteCmd                                               0x4A0170
#define __get_melee_range                                          0x4A5780
#define __GetGaugeValueFromEQ                                      0x647980
#define __GetLabelFromEQ                                           0x6486E0
#define __LoadFrontEnd                                             0x565510
#define __NewUIINI                                                 0x647510
#define __ProcessGameEvents                                        0x4F1F30
#define CrashDetected                                              0x565310
#define DrawNetStatus                                              0x510020
#define Util__FastTime                                             0x6C61A0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x4775E0
#define AltAdvManager__IsAbilityReady                              0x477620
#define AltAdvManager__GetAltAbility                               0x4779B0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x57D6E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x586AA0

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x6F49F0

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x59CDE0
#define CChatManager__InitContextMenu                              0x59D5B0

// CChatService
#define CChatService__GetNumberOfFriends                           0x6B4120
#define CChatService__GetFriendName                                0x6B4130

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5A1790
#define CChatWindow__Clear                                         0x5A2100
#define CChatWindow__WndNotification                               0x5A21E0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6DF140
#define CComboWnd__Draw                                            0x6DF2F0
#define CComboWnd__GetCurChoice                                    0x6DF0E0
#define CComboWnd__GetListRect                                     0x6DF5B0
#define CComboWnd__GetTextRect                                     0x6DF170
#define CComboWnd__InsertChoice                                    0x6DF620
#define CComboWnd__SetColors                                       0x6DF070
#define CComboWnd__SetChoice                                       0x6DF0A0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5A9550
#define CContainerWnd__vftable                                     0x7FF970

// CDisplay 
#define CDisplay__CleanGameUI                                      0x4664F0
#define CDisplay__GetClickedActor                                  0x463C50
#define CDisplay__GetUserDefinedColor                              0x462D70
#define CDisplay__GetWorldFilePath                                 0x4621E0
#define CDisplay__is3dON                                           0x461350
#define CDisplay__ReloadUI                                         0x474740
#define CDisplay__WriteTextHD2                                     0x466C90

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x577650
#define CEditBaseWnd__SetSel                                       0x7008A0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x6E7D00
#define CEditWnd__GetCharIndexPt                                   0x6E8B40
#define CEditWnd__GetDisplayString                                 0x6E7E90
#define CEditWnd__GetHorzOffset                                    0x6E8120
#define CEditWnd__GetLineForPrintableChar                          0x6E85F0
#define CEditWnd__GetSelStartPt                                    0x6E8D80
#define CEditWnd__GetSTMLSafeText                                  0x6E82B0
#define CEditWnd__PointFromPrintableChar                           0x6E8700
#define CEditWnd__SelectableCharFromPoint                          0x6E8880
#define CEditWnd__SetEditable                                      0x6E8280

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4D3AC0
#define CEverQuest__DropHeldItemOnGround                           0x4D7E20
#define CEverQuest__dsp_chat                                       0x4D95D0
#define CEverQuest__DoTellWindow                                   0x4D7FA0
#define CEverQuest__EnterZone                                      0x4EAE40
#define CEverQuest__GetBodyTypeDesc                                0x4D0CC0
#define CEverQuest__GetClassDesc                                   0x4D0500
#define CEverQuest__GetClassThreeLetterCode                        0x4D0B00
#define CEverQuest__GetDeityDesc                                   0x4D1330
#define CEverQuest__GetLangDesc                                    0x4D1050
#define CEverQuest__GetRaceDesc                                    0x4D1300
#define CEverQuest__InterpretCmd                                   0x4D9FE0
#define CEverQuest__LeftClickedOnPlayer                            0x4EC9A0
#define CEverQuest__LMouseUp                                       0x4F0280
#define CEverQuest__RightClickedOnPlayer                           0x4F0B20
#define CEverQuest__RMouseUp                                       0x4F1B00
#define CEverQuest__SetGameState                                   0x4D3F50
#define CEverQuest__Emote                                          0x4D97F0

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5B60A0
#define CGaugeWnd__CalcLinesFillRect                               0x5B6100
#define CGaugeWnd__Draw                                            0x5B6510

// CGuild
#define CGuild__FindMemberByName                                   0x418200

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5CE6E0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5D7D60
#define CInvSlotMgr__MoveItem                                      0x5D7F00

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5D75F0
#define CInvSlot__SliderComplete                                   0x5D6730

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5D8EA0

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x645670
#define CItemDisplayWnd__UpdateStrings                             0x5D9BA0

// CLabel 
#define CLabel__Draw                                               0x5EC460

// CListWnd 
#define CListWnd__AddColumn                                        0x6D9970
#define CListWnd__AddColumn1                                       0x6D9400
#define CListWnd__AddLine                                          0x6D8F20
#define CListWnd__AddString                                        0x6D9120
#define CListWnd__CalculateFirstVisibleLine                        0x6D6120
#define CListWnd__CalculateVSBRange                                0x6D7F50
#define CListWnd__ClearAllSel                                      0x6D57E0
#define CListWnd__CloseAndUpdateEditWindow                         0x6D6780
#define CListWnd__Compare                                          0x6D6B10
#define CListWnd__Draw                                             0x6D7C30
#define CListWnd__DrawColumnSeparators                             0x6D7AA0
#define CListWnd__DrawHeader                                       0x6D59F0
#define CListWnd__DrawItem                                         0x6D73A0
#define CListWnd__DrawLine                                         0x6D7740
#define CListWnd__DrawSeparator                                    0x6D7B40
#define CListWnd__EnsureVisible                                    0x6D61B0
#define CListWnd__ExtendSel                                        0x6D72C0
#define CListWnd__GetColumnMinWidth                                0x6D5570
#define CListWnd__GetColumnWidth                                   0x6D54B0
#define CListWnd__GetCurSel                                        0x6D4EF0
#define CListWnd__GetHeaderRect                                    0x6D5060
#define CListWnd__GetItemAtPoint                                   0x6D64A0
#define CListWnd__GetItemAtPoint1                                  0x6D6510
#define CListWnd__GetItemData                                      0x6D5260
#define CListWnd__GetItemHeight                                    0x6D5E80
#define CListWnd__GetItemIcon                                      0x6D53F0
#define CListWnd__GetItemRect                                      0x6D6280
#define CListWnd__GetItemText                                      0x6D52A0
#define CListWnd__GetSelList                                       0x6D92E0
#define CListWnd__GetSeparatorRect                                 0x6D6A50
#define CListWnd__RemoveLine                                       0x6D9920
#define CListWnd__SetColors                                        0x6D4FC0
#define CListWnd__SetColumnJustification                           0x6D5650
#define CListWnd__SetColumnWidth                                   0x6D5530
#define CListWnd__SetCurSel                                        0x6D4F30
#define CListWnd__SetItemColor                                     0x6D8B70
#define CListWnd__SetItemData                                      0x6D5880
#define CListWnd__SetItemText                                      0x6D8AF0
#define CListWnd__ShiftColumnSeparator                             0x6D7230
#define CListWnd__Sort                                             0x6D99B0
#define CListWnd__ToggleSel                                        0x6D5750

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x601B50

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x60D290
#define CMerchantWnd__RequestBuyItem                               0x60EB00
#define CMerchantWnd__RequestSellItem                              0x60EF20
#define CMerchantWnd__SelectBuySellSlot                            0x60DFC0

// CObfuscator
#define CObfuscator__doit                                          0x68F0A0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x6F0140
#define CSidlManager__CreateLabel                                  0x63E5C0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5796F0
#define CSidlScreenWnd__CalculateVSBRange                          0x6F6660
#define CSidlScreenWnd__ConvertToRes                               0x700780
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6E11B0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6E2280
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6E2330
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6E1A50
#define CSidlScreenWnd__DrawSidlPiece                              0x6E0E80
#define CSidlScreenWnd__EnableIniStorage                           0x6E0A20
#define CSidlScreenWnd__GetSidlPiece                               0x6E1080
#define CSidlScreenWnd__Init1                                      0x6E20F0
#define CSidlScreenWnd__LoadIniInfo                                0x6E1260
#define CSidlScreenWnd__LoadIniListWnd                             0x6E0B70
#define CSidlScreenWnd__LoadSidlScreen                             0x6E1CA0
#define CSidlScreenWnd__StoreIniInfo                               0x6E0630
#define CSidlScreenWnd__WndNotification                            0x6E1E70
#define CSidlScreenWnd__GetChildItem                               0x6E0A80

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x533160

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x701CD0
#define CSliderWnd__SetValue                                       0x701DD0
#define CSliderWnd__SetNumTicks                                    0x702340

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x6433B0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x6FE9C0
#define CStmlWnd__CalculateVSBRange                                0x6F6660
#define CStmlWnd__CanBreakAtCharacter                              0x6F67A0
#define CStmlWnd__FastForwardToEndOfTag                            0x6F73F0
#define CStmlWnd__ForceParseNow                                    0x6FEE60
#define CStmlWnd__GetNextTagPiece                                  0x6F7310
#define CStmlWnd__GetSTMLText                                      0x5A1730
#define CStmlWnd__GetThisChar                                      0x724390
#define CStmlWnd__GetVisiableText                                  0x6F87C0
#define CStmlWnd__InitializeWindowVariables                        0x6FAA30
#define CStmlWnd__MakeStmlColorTag                                 0x6F5650
#define CStmlWnd__MakeWndNotificationTag                           0x6F56F0
#define CStmlWnd__SetSTMLText                                      0x6FAB60
#define CStmlWnd__StripFirstSTMLLines                              0x6FE750
#define CStmlWnd__UpdateHistoryString                              0x6F9030

// CTabWnd 
#define CTabWnd__Draw                                              0x7030D0
#define CTabWnd__DrawCurrentPage                                   0x702AF0
#define CTabWnd__DrawTab                                           0x7028D0
#define CTabWnd__GetCurrentPage                                    0x702D70
#define CTabWnd__GetPageClientRect                                 0x7025A0
#define CTabWnd__GetPageFromTabIndex                               0x702800
#define CTabWnd__GetPageInnerRect                                  0x702600
#define CTabWnd__GetTabInnerRect                                   0x702780
#define CTabWnd__GetTabRect                                        0x702690
#define CTabWnd__InsertPage                                        0x703340
#define CTabWnd__SetPage                                           0x702DB0
#define CTabWnd__SetPageRect                                       0x703000
#define CTabWnd__UpdatePage                                        0x7032C0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4147A0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6E2690

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x7076A0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6D4BE0

// CXRect 
#define CXRect__CenterPoint                                        0x57CD60

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, &amp; CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x5014A0
#define CXStr__CXStr1                                              0x6CE850
#define CXStr__CXStr3                                              0x6C78C0
#define CXStr__dCXStr                                              0x4035F0
#define CXStr__operator_equal1                                     0x6C7A80
#define CXStr__operator_plus_equal1                                0x6C8AC0

// CXWnd 
#define CXWnd__BringToTop                                          0x6DA090
#define CXWnd__Center                                              0x6DDB20
#define CXWnd__ClrFocus                                            0x6D9DB0
#define CXWnd__DoAllDrawing                                        0x6DE8E0
#define CXWnd__DrawChildren                                        0x6DEA10
#define CXWnd__DrawColoredRect                                     0x6DA310
#define CXWnd__DrawTooltip                                         0x6DE700
#define CXWnd__DrawTooltipAtPoint                                  0x6DD8E0
#define CXWnd__GetBorderFrame                                      0x6DA7F0
#define CXWnd__GetChildWndAt                                       0x6DD420
#define CXWnd__GetClientClipRect                                   0x6DA700
#define CXWnd__GetScreenClipRect                                   0x6DDD40
#define CXWnd__GetScreenRect                                       0x6DA990
#define CXWnd__GetTooltipRect                                      0x6DA560
#define CXWnd__GetWindowTextA                                      0x5700F0
#define CXWnd__IsActive                                            0x6E37A0
#define CXWnd__IsDescendantOf                                      0x6DA780
#define CXWnd__IsReallyVisible                                     0x6DD400
#define CXWnd__IsType                                              0x7045D0
#define CXWnd__Move                                                0x6DCFE0
#define CXWnd__Move1                                               0x6DE560
#define CXWnd__ProcessTransition                                   0x6DA050
#define CXWnd__Refade                                              0x6D9E60
#define CXWnd__Resize                                              0x6DAA60
#define CXWnd__Right                                               0x6DDC80
#define CXWnd__SetFocus                                            0x6DC210
#define CXWnd__SetKeyTooltip                                       0x6DAC70
#define CXWnd__SetMouseOver                                        0x6DAC40
#define CXWnd__StartFade                                           0x6DA0D0
#define CXWnd__GetChildItem                                        0x6DDEB0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6E4C50
#define CXWndManager__DrawWindows                                  0x6E4860
#define CXWndManager__GetKeyboardFlags                             0x6E3450
#define CXWndManager__HandleKeyboardMsg                            0x6E39A0
#define CXWndManager__RemoveWnd                                    0x6E38C0

// CDBStr
#define CDBStr__GetString                                          0x45FC90

// EQ_Character 
#define EQ_Character__CastRay                                      0x7304B0
#define EQ_Character__CastSpell                                    0x42AE00
#define EQ_Character__Cur_HP                                       0x434600
#define EQ_Character__GetAACastingTimeModifier                     0x420C80
#define EQ_Character__GetCharInfo2                                 0x6A5230
#define EQ_Character__GetFocusCastingTimeModifier                  0x41C5A0
#define EQ_Character__GetFocusRangeModifier                        0x41C6E0
#define EQ_Character__Max_Endurance                                0x516180
#define EQ_Character__Max_HP                                       0x42F410
#define EQ_Character__Max_Mana                                     0x515FB0
#define EQ_Character__doCombatAbility                              0x514EC0
#define EQ_Character__UseSkill                                     0x43DD40
#define EQ_Character__GetConLevel                                  0x511470

// EQ_Item 
#define EQ_Item__CanDrop                                           0x4FF240
#define EQ_Item__GetItemLinkHash                                   0x698B50
#define EQ_Item__IsStackable                                       0x68F980

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x478880
#define EQ_LoadingS__Array                                         0x87DBA0

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x518FF0
#define EQ_PC__GetAltAbilityIndex                                  0x69D550
#define EQ_PC__GetCombatAbility                                    0x69D5E0
#define EQ_PC__GetCombatAbilityTimer                               0x69D690
#define EQ_PC__GetItemTimerValue                                   0x513E00
#define EQ_PC__HasLoreItem                                         0x5174C0

// EQItemList 
#define EQItemList__dEQItemList                                    0x4A3D60
#define EQItemList__EQItemList                                     0x4A3CB0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x45F620

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x51D860
#define EQPlayer__dEQPlayer                                        0x521910
#define EQPlayer__DoAttack                                         0x52F360
#define EQPlayer__EQPlayer                                         0x525650
#define EQPlayer__SetNameSpriteState                               0x51F850
#define EQPlayer__SetNameSpriteTint                                0x51D8D0
#define EQPlayer__IsBodyType_j                                     0x72FDC0
#define EQPlayer__IsTargetable                                     0x72FF50

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5267B0
#define EQPlayerManager__GetSpawnByName                            0x526A90

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x500EC0
#define KeypressHandler__AttachKeyToEqCommand                      0x500F00
#define KeypressHandler__ClearCommandStateArray                    0x500CD0
#define KeypressHandler__HandleKeyDown                             0x4FF850
#define KeypressHandler__HandleKeyUp                               0x4FFB60
#define KeypressHandler__SaveKeymapping                            0x500DA0

// MapViewMap 
#define MapViewMap__Clear                                          0x5FD220
#define MapViewMap__SaveEx                                         0x5FDBF0

#define OtherCharData__GetAltCurrency                              0x6BC830

// StringTable 
#define StringTable__getString                                     0x68F320
