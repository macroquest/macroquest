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
#define __ExpectedVersionDate                                     "Sep 14 2010"
#define __ExpectedVersionTime                                     "11:48:45"
#define __ActualVersionDate                                        0x828740
#define __ActualVersionTime                                        0x82874C

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x512C00
#define __MemChecker1                                              0x74D8A0
#define __MemChecker2                                              0x577510
#define __MemChecker3                                              0x577460
#define __MemChecker4                                              0x766DF0
#define __EncryptPad0                                              0x8B81C0
#define __EncryptPad1                                              0x8C3430
#define __EncryptPad2                                              0x8BAE00
#define __EncryptPad3                                              0x8BAA00
#define __EncryptPad4                                              0x8C4E20
#define __AC1                                                      0x6690C0
#define __AC2                                                      0x4DAAE5
#define __AC3                                                      0x4EEB38
#define __AC4                                                      0x4F2A08
#define __AC5                                                      0x4FD1D0
#define __AC6                                                      0x50066B
#define __AC7                                                      0x4F96F4
#define __AC1_Data                                                 0x81058D

// Direct Input
#define DI8__Main                                                  0xB1EED4
#define DI8__Keyboard                                              0xB1EED8
#define DI8__Mouse                                                 0xB1EEDC
#define __AltTimerReady                                            0xAA5BB6
#define __Attack                                                   0xB09256
#define __Autofire                                                 0xB09257
#define __BindList                                                 0x8B2920
#define __Clicks                                                   0xAA48B0
#define __CommandList                                              0x8B3270
#define __CurrentMapLabel                                          0xB4A188
#define __CurrentSocial                                            0x8AE870
#define __DoAbilityAvailable                                       0xAA5B50
#define __DoAbilityList                                            0xADB174
#define __do_loot                                                  0x4B2C00
#define __DrawHandler                                              0xB589BC
#define __GroupCount                                               0xA9E6AA
#define __Guilds                                                   0xAA3C90
#define __gWorld                                                   0xAA0568
#define __HotkeyPage                                               0xB02560
#define __HWnd                                                     0xB1EC10
#define __InChatMode                                               0xAA47E8
#define __LastTell                                                 0xAA64CC
#define __LMouseHeldTime                                           0xAA48DC
#define __Mouse                                                    0xB1EEE0
#define __MouseLook                                                0xAA487E
#define __MouseEventTime                                           0xB09398
#define __NetStatusToggle                                          0xAA4881
#define __PCNames                                                  0xAA5F10
#define __RangeAttackReady                                         0xAA5BB4
#define __RMouseHeldTime                                           0xAA48D8
#define __RunWalkState                                             0xAA47EC
#define __ScreenMode                                               0x9EDF38
#define __ScreenX                                                  0xAA47A0
#define __ScreenY                                                  0xAA47A4
#define __ScreenXMax                                               0xAA47A8
#define __ScreenYMax                                               0xAA47AC
#define __ServerHost                                               0xA9E5EC
#define __ServerName                                               0xADB134
#define __ShiftKeyDown                                             0xAA4E68
#define __ShowNames                                                0xAA5DE4
#define __Socials                                                  0xADB234


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xAA0628
#define instEQZoneInfo                                             0xAA4A28
#define instKeypressHandler                                        0xB0937C
#define pinstActiveBanker                                          0xAA05FC
#define pinstActiveCorpse                                          0xAA0600
#define pinstActiveGMaster                                         0xAA0604
#define pinstActiveMerchant                                        0xAA05F8
#define pinstAltAdvManager                                         0x9EEDB8
#define pinstAuraMgr                                               0x8D77FC
#define pinstBandageTarget                                         0xAA05E4
#define pinstCamActor                                              0x9EE8A8
#define pinstCDBStr                                                0x9EDF28
#define pinstCDisplay                                              0xAA060C
#define pinstCEverQuest                                            0xB1F058
#define pinstCharData                                              0xAA05C8
#define pinstCharSpawn                                             0xAA05F0
#define pinstControlledMissile                                     0xAA05C4
#define pinstControlledPlayer                                      0xAA05F0
#define pinstCSidlManager                                          0xB58E8C
#define pinstCXWndManager                                          0xB58E84
#define instDynamicZone                                            0xAA4670
#define pinstDZMember                                              0xAA4780
#define pinstDZTimerInfo                                           0xAA4784
#define pinstEQItemList                                            0xA9D8D0
#define instEQMisc                                                 0x9EDEE0
#define pinstEQSoundManager                                        0x9EEDDC
#define instExpeditionLeader                                       0xAA46BA
#define instExpeditionName                                         0xAA46FA
#define pinstGroup                                                 0xA9E6A6
#define pinstImeManager                                            0xB58E90
#define pinstLocalPlayer                                           0xAA05DC
#define pinstMercenaryData                                         0xB0970C
#define pinstModelPlayer                                           0xAA0608
#define pinstPCData                                                0xAA05C8
#define pinstSkillMgr                                              0xB1BCC4
#define pinstSpawnManager                                          0xB1BB20
#define pinstSpellManager                                          0xB1BCD0
#define pinstSpellSets                                             0xB02564
#define pinstStringTable                                           0xAA0584
#define pinstSwitchManager                                         0xA9E2EC
#define pinstTarget                                                0xAA05F4
#define pinstTargetObject                                          0xAA05CC
#define pinstTargetSwitch                                          0xAA05D0
#define pinstTaskMember                                            0x9EDEC0
#define pinstTrackTarget                                           0xAA05E8
#define pinstTradeTarget                                           0xAA05D8
#define instTributeActive                                          0x9EDF05
#define pinstViewActor                                             0x9EE8A4
#define pinstWorldData                                             0xAA05AC


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x8D50C0
#define pinstCAudioTriggersWindow                                  0x8D508C
#define pinstCCharacterSelect                                      0x9EE7A0
#define pinstCFacePick                                             0x9EE750
#define pinstCNoteWnd                                              0x9EE758
#define pinstCBookWnd                                              0x9EE75C
#define pinstCPetInfoWnd                                           0x9EE760
#define pinstCTrainWnd                                             0x9EE764
#define pinstCSkillsWnd                                            0x9EE768
#define pinstCSkillsSelectWnd                                      0x9EE76C
#define pinstCCombatSkillSelectWnd                                 0x9EE770
#define pinstCFriendsWnd                                           0x9EE774
#define pinstCAuraWnd                                              0x9EE778
#define pinstCRespawnWnd                                           0x9EE77C
#define pinstCBandolierWnd                                         0x9EE780
#define pinstCPotionBeltWnd                                        0x9EE784
#define pinstCAAWnd                                                0x9EE788
#define pinstCGroupSearchFiltersWnd                                0x9EE78C
#define pinstCLoadskinWnd                                          0x9EE790
#define pinstCAlarmWnd                                             0x9EE794
#define pinstCMusicPlayerWnd                                       0x9EE798
#define pinstCMailWnd                                              0x9EE7A4
#define pinstCMailCompositionWnd                                   0x9EE7A8
#define pinstCMailAddressBookWnd                                   0x9EE7AC
#define pinstCRaidWnd                                              0x9EE7B4
#define pinstCRaidOptionsWnd                                       0x9EE7B8
#define pinstCBreathWnd                                            0x9EE7BC
#define pinstCMapViewWnd                                           0x9EE7C0
#define pinstCMapToolbarWnd                                        0x9EE7C4
#define pinstCEditLabelWnd                                         0x9EE7C8
#define pinstCTargetWnd                                            0x9EE7CC
#define pinstCColorPickerWnd                                       0x9EE7D0
#define pinstCPlayerWnd                                            0x9EE7D4
#define pinstCOptionsWnd                                           0x9EE7D8
#define pinstCBuffWindowNORMAL                                     0x9EE7DC
#define pinstCBuffWindowSHORT                                      0x9EE7E0
#define pinstCharacterCreation                                     0x9EE7E4
#define pinstCCursorAttachment                                     0x9EE7E8
#define pinstCCastingWnd                                           0x9EE7EC
#define pinstCCastSpellWnd                                         0x9EE7F0
#define pinstCSpellBookWnd                                         0x9EE7F4
#define pinstCInventoryWnd                                         0x9EE7F8
#define pinstCBankWnd                                              0x9EE7FC
#define pinstCQuantityWnd                                          0x9EE800
#define pinstCLootWnd                                              0x9EE804
#define pinstCActionsWnd                                           0x9EE808
#define pinstCCombatAbilityWnd                                     0x9EE80C
#define pinstCMerchantWnd                                          0x9EE810
#define pinstCTradeWnd                                             0x9EE814
#define pinstCSelectorWnd                                          0x9EE818
#define pinstCBazaarWnd                                            0x9EE81C
#define pinstCBazaarSearchWnd                                      0x9EE820
#define pinstCGiveWnd                                              0x9EE824
#define pinstCTrackingWnd                                          0x9EE828
#define pinstCInspectWnd                                           0x9EE82C
#define pinstCSocialEditWnd                                        0x9EE830
#define pinstCFeedbackWnd                                          0x9EE834
#define pinstCBugReportWnd                                         0x9EE838
#define pinstCVideoModesWnd                                        0x9EE83C
#define pinstCTextEntryWnd                                         0x9EE844
#define pinstCFileSelectionWnd                                     0x9EE848
#define pinstCCompassWnd                                           0x9EE84C
#define pinstCPlayerNotesWnd                                       0x9EE850
#define pinstCGemsGameWnd                                          0x9EE854
#define pinstCTimeLeftWnd                                          0x9EE858
#define pinstCPetitionQWnd                                         0x9EE86C
#define pinstCSoulmarkWnd                                          0x9EE870
#define pinstCStoryWnd                                             0x9EE874
#define pinstCJournalTextWnd                                       0x9EE878
#define pinstCJournalCatWnd                                        0x9EE87C
#define pinstCBodyTintWnd                                          0x9EE880
#define pinstCServerListWnd                                        0x9EE884
#define pinstCAvaZoneWnd                                           0x9EE88C
#define pinstCBlockedBuffWnd                                       0x9EE890
#define pinstCBlockedPetBuffWnd                                    0x9EE894
#define pinstCInvSlotMgr                                           0x9EE89C
#define pinstCContainerMgr                                         0x9EE8A0
#define pinstCAdventureLeaderboardWnd                              0xB476A0
#define pinstCAdventureRequestWnd                                  0xB476BC
#define pinstCAltStorageWnd                                        0xB4771C
#define pinstCAdventureStatsWnd                                    0xB476D8
#define pinstCBarterMerchantWnd                                    0xB478E8
#define pinstCBarterSearchWnd                                      0xB47904
#define pinstCBarterWnd                                            0xB47920
#define pinstCChatManager                                          0xB47BC4
#define pinstCDynamicZoneWnd                                       0xB47CBC
#define pinstCEQMainWnd                                            0xB47D30
#define pinstCFellowshipWnd                                        0xB47D94
#define pinstCFindLocationWnd                                      0xB47DC8
#define pinstCGroupSearchWnd                                       0xB47E78
#define pinstCGroupWnd                                             0xB47E94
#define pinstCGuildBankWnd                                         0xB47EB0
#define pinstCGuildMgmtWnd                                         0xB49EE8
#define pinstCGuildTributeMasterWnd                                0xB49F08
#define pinstCHotButtonWnd                                         0xB49F3C
#define pinstCHotButtonWnd1                                        0xB49F3C
#define pinstCHotButtonWnd2                                        0xB49F40
#define pinstCHotButtonWnd3                                        0xB49F44
#define pinstCHotButtonWnd4                                        0xB49F48
#define pinstCItemDisplayManager                                   0xB49FF4
#define pinstCItemExpTransferWnd                                   0xB4A014
#define pinstCLeadershipWnd                                        0xB4A0B0
#define pinstCLFGuildWnd                                           0xB4A0CC
#define pinstCMIZoneSelectWnd                                      0xB4A23C
#define pinstCAdventureMerchantWnd                                 0xB4A34C
#define pinstCConfirmationDialog                                   0xB4A368
#define pinstCPopupWndManager                                      0xB4A368
#define pinstCProgressionSelectionWnd                              0xB4A39C
#define pinstCPvPLeaderboardWnd                                    0xB4A3B8
#define pinstCPvPStatsWnd                                          0xB4A3D4
#define pinstCSystemInfoDialogBox                                  0xB4A4A0
#define pinstCTargetOfTargetWnd                                    0xB4AFA8
#define pinstCTaskSelectWnd                                        0xB4AFDC
#define pinstCTaskTemplateSelectWnd                                0xB4AFF8
#define pinstCTaskWnd                                              0xB4B014
#define pinstCTipWndOFDAY                                          0xB4B090
#define pinstCTipWndCONTEXT                                        0xB4B094
#define pinstCTitleWnd                                             0xB4B0B0
#define pinstCTradeskillWnd                                        0xB4B0F4
#define pinstCTributeBenefitWnd                                    0xB4B140
#define pinstCTributeMasterWnd                                     0xB4B15C
#define pinstCContextMenuManager                                   0xB58EE8
#define pinstCVoiceMacroWnd                                        0xB1BEC4
#define pinstCHtmlWnd                                              0xB1BF10


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4C67D0
#define __ConvertItemTags                                          0x4B8280
#define __ExecuteCmd                                               0x4A4570
#define __get_melee_range                                          0x4AA240
#define __GetGaugeValueFromEQ                                      0x667F70
#define __GetLabelFromEQ                                           0x669060
#define __GetXTargetType                                           0x6D1F70
#define __LoadFrontEnd                                             0x5763E0
#define __NewUIINI                                                 0x667B00
#define __ProcessGameEvents                                        0x4F9AE0
#define CrashDetected                                              0x5761E0
#define DrawNetStatus                                              0x51D720
#define Util__FastTime                                             0x74DFF0


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47BB50
#define AltAdvManager__IsAbilityReady                              0x47BB90
#define AltAdvManager__GetAltAbility                               0x47BE40

// CharacterZoneClient
#define CharacterZoneClient__HasSkill                              0x4379E0

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x593FD0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x59D770

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x714F20

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5B36F0
#define CChatManager__InitContextMenu                              0x5B3EC0

// CChatService
#define CChatService__GetNumberOfFriends                           0x6C6FE0
#define CChatService__GetFriendName                                0x6C6FF0

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5B80A0
#define CChatWindow__Clear                                         0x5B8A00
#define CChatWindow__WndNotification                               0x5B8BF0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6FEE40
#define CComboWnd__Draw                                            0x6FF000
#define CComboWnd__GetCurChoice                                    0x6FEDE0
#define CComboWnd__GetListRect                                     0x6FF2F0
#define CComboWnd__GetTextRect                                     0x6FEE70
#define CComboWnd__InsertChoice                                    0x6FF360
#define CComboWnd__SetColors                                       0x6FED70
#define CComboWnd__SetChoice                                       0x6FEDA0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5C0030
#define CContainerWnd__vftable                                     0x830398

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46EB60
#define CDisplay__GetClickedActor                                  0x467F10
#define CDisplay__GetUserDefinedColor                              0x467030
#define CDisplay__GetWorldFilePath                                 0x4664C0
#define CDisplay__is3dON                                           0x4655F0
#define CDisplay__ReloadUI                                         0x478D50
#define CDisplay__WriteTextHD2                                     0x46AC00

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x58DF70
#define CEditBaseWnd__SetSel                                       0x7218D0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x707DF0
#define CEditWnd__GetCharIndexPt                                   0x708DB0
#define CEditWnd__GetDisplayString                                 0x707F80
#define CEditWnd__GetHorzOffset                                    0x708210
#define CEditWnd__GetLineForPrintableChar                          0x708860
#define CEditWnd__GetSelStartPt                                    0x709000
#define CEditWnd__GetSTMLSafeText                                  0x7083B0
#define CEditWnd__PointFromPrintableChar                           0x708970
#define CEditWnd__SelectableCharFromPoint                          0x708AF0
#define CEditWnd__SetEditable                                      0x708380

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4DB1C0
#define CEverQuest__DropHeldItemOnGround                           0x4DF760
#define CEverQuest__dsp_chat                                       0x4E0F00
#define CEverQuest__DoTellWindow                                   0x4DF8E0
#define CEverQuest__EnterZone                                      0x4F29A0
#define CEverQuest__GetBodyTypeDesc                                0x4D83C0
#define CEverQuest__GetClassDesc                                   0x4D7C00
#define CEverQuest__GetClassThreeLetterCode                        0x4D8200
#define CEverQuest__GetDeityDesc                                   0x4D8A30
#define CEverQuest__GetLangDesc                                    0x4D8750
#define CEverQuest__GetRaceDesc                                    0x4D8A00
#define CEverQuest__InterpretCmd                                   0x4E1A60
#define CEverQuest__LeftClickedOnPlayer                            0x4F44D0
#define CEverQuest__LMouseUp                                       0x4F7DE0
#define CEverQuest__RightClickedOnPlayer                           0x4F8680
#define CEverQuest__RMouseUp                                       0x4F96B0
#define CEverQuest__SetGameState                                   0x4DB650
#define CEverQuest__Emote                                          0x4E1120

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5CC890
#define CGaugeWnd__CalcLinesFillRect                               0x5CC8F0
#define CGaugeWnd__Draw                                            0x5CCD40

// CGuild
#define CGuild__FindMemberByName                                   0x41B9E0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5E5810

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5EEFB0
#define CInvSlotMgr__MoveItem                                      0x5EF150

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5EE800
#define CInvSlot__SliderComplete                                   0x5ED910

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5F0100

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x6658F0
#define CItemDisplayWnd__UpdateStrings                             0x5F0DB0

// CLabel 
#define CLabel__Draw                                               0x603580

// CListWnd 
#define CListWnd__AddColumn                                        0x6F8400
#define CListWnd__AddColumn1                                       0x6F7E90
#define CListWnd__AddLine                                          0x6F7A00
#define CListWnd__AddString                                        0x6F7BA0
#define CListWnd__CalculateFirstVisibleLine                        0x6F46E0
#define CListWnd__CalculateVSBRange                                0x6F68E0
#define CListWnd__ClearAllSel                                      0x6F3C30
#define CListWnd__CloseAndUpdateEditWindow                         0x6F4D50
#define CListWnd__Compare                                          0x6F50F0
#define CListWnd__Draw                                             0x6F6560
#define CListWnd__DrawColumnSeparators                             0x6F63D0
#define CListWnd__DrawHeader                                       0x6F3EC0
#define CListWnd__DrawItem                                         0x6F5A00
#define CListWnd__DrawLine                                         0x6F6040
#define CListWnd__DrawSeparator                                    0x6F6470
#define CListWnd__EnsureVisible                                    0x6F4770
#define CListWnd__ExtendSel                                        0x6F5920
#define CListWnd__GetColumnMinWidth                                0x6F3950
#define CListWnd__GetColumnWidth                                   0x6F3890
#define CListWnd__GetCurSel                                        0x6F32C0
#define CListWnd__GetHeaderRect                                    0x6F3440
#define CListWnd__GetItemAtPoint                                   0x6F4A60
#define CListWnd__GetItemAtPoint1                                  0x6F4AD0
#define CListWnd__GetItemData                                      0x6F3640
#define CListWnd__GetItemHeight                                    0x6F4350
#define CListWnd__GetItemIcon                                      0x6F37D0
#define CListWnd__GetItemRect                                      0x6F4840
#define CListWnd__GetItemText                                      0x6F3680
#define CListWnd__GetSelList                                       0x6F7D70
#define CListWnd__GetSeparatorRect                                 0x6F5030
#define CListWnd__RemoveLine                                       0x6F83B0
#define CListWnd__SetColors                                        0x6F33B0
#define CListWnd__SetColumnJustification                           0x6F3AA0
#define CListWnd__SetColumnWidth                                   0x6F3910
#define CListWnd__SetCurSel                                        0x6F3300
#define CListWnd__SetItemColor                                     0x6F7590
#define CListWnd__SetItemData                                      0x6F3CD0
#define CListWnd__SetItemText                                      0x6F7510
#define CListWnd__ShiftColumnSeparator                             0x6F5830
#define CListWnd__Sort                                             0x6F8440
#define CListWnd__ToggleSel                                        0x6F3BA0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x618F40

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x62A040
#define CMerchantWnd__RequestBuyItem                               0x62C110
#define CMerchantWnd__RequestSellItem                              0x62C530
#define CMerchantWnd__SelectBuySellSlot                            0x62B530

// CObfuscator
#define CObfuscator__doit                                          0x69D790

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x7106A0
#define CSidlManager__CreateLabel                                  0x65E860

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x590020
#define CSidlScreenWnd__CalculateVSBRange                          0x700AE0
#define CSidlScreenWnd__ConvertToRes                               0x7217B0
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x700FB0
#define CSidlScreenWnd__CSidlScreenWnd1                            0x7020A0
#define CSidlScreenWnd__CSidlScreenWnd2                            0x702150
#define CSidlScreenWnd__dCSidlScreenWnd                            0x701860
#define CSidlScreenWnd__DrawSidlPiece                              0x700C70
#define CSidlScreenWnd__EnableIniStorage                           0x7007D0
#define CSidlScreenWnd__GetSidlPiece                               0x700E80
#define CSidlScreenWnd__Init1                                      0x701F00
#define CSidlScreenWnd__LoadIniInfo                                0x701060
#define CSidlScreenWnd__LoadIniListWnd                             0x700920
#define CSidlScreenWnd__LoadSidlScreen                             0x701AB0
#define CSidlScreenWnd__StoreIniInfo                               0x7003D0
#define CSidlScreenWnd__StoreIniVis                                0x700760
#define CSidlScreenWnd__WndNotification                            0x701C80
#define CSidlScreenWnd__GetChildItem                               0x700830

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x543CA0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x722D00
#define CSliderWnd__SetValue                                       0x722E00
#define CSliderWnd__SetNumTicks                                    0x7233B0

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x663640

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x71F9C0
#define CStmlWnd__CalculateHSBRange                                0x7171A0
#define CStmlWnd__CalculateVSBRange                                0x717110
#define CStmlWnd__CanBreakAtCharacter                              0x717300
#define CStmlWnd__FastForwardToEndOfTag                            0x717FD0
#define CStmlWnd__ForceParseNow                                    0x71FEC0
#define CStmlWnd__GetNextTagPiece                                  0x717EF0
#define CStmlWnd__GetSTMLText                                      0x5B8040
#define CStmlWnd__GetThisChar                                      0x746CF0
#define CStmlWnd__GetVisiableText                                  0x7193F0
#define CStmlWnd__InitializeWindowVariables                        0x71B950
#define CStmlWnd__MakeStmlColorTag                                 0x716030
#define CStmlWnd__MakeWndNotificationTag                           0x7160D0
#define CStmlWnd__SetSTMLText                                      0x71BA70
#define CStmlWnd__StripFirstSTMLLines                              0x71F670
#define CStmlWnd__UpdateHistoryString                              0x719C80

// CTabWnd 
#define CTabWnd__Draw                                              0x7241C0
#define CTabWnd__DrawCurrentPage                                   0x723B60
#define CTabWnd__DrawTab                                           0x723940
#define CTabWnd__GetCurrentPage                                    0x723E60
#define CTabWnd__GetPageClientRect                                 0x723610
#define CTabWnd__GetPageFromTabIndex                               0x723870
#define CTabWnd__GetPageInnerRect                                  0x723670
#define CTabWnd__GetTabInnerRect                                   0x7237F0
#define CTabWnd__GetTabRect                                        0x723700
#define CTabWnd__InsertPage                                        0x724450
#define CTabWnd__SetPage                                           0x723EA0
#define CTabWnd__SetPageRect                                       0x7240F0
#define CTabWnd__UpdatePage                                        0x7243D0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417FA0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x7024D0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x725050

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6F22D0

// CXRect 
#define CXRect__CenterPoint                                        0x593660

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x50C470
#define CXStr__CXStr1                                              0x6885E0
#define CXStr__CXStr3                                              0x74B2B0
#define CXStr__dCXStr                                              0x6F8590
#define CXStr__operator_equal1                                     0x74B470
#define CXStr__operator_plus_equal1                                0x74C4B0

// CXWnd 
#define CXWnd__BringToTop                                          0x6F8A30
#define CXWnd__Center                                              0x6FD860
#define CXWnd__ClrFocus                                            0x6F8860
#define CXWnd__DoAllDrawing                                        0x6FE1E0
#define CXWnd__DrawChildren                                        0x6FE330
#define CXWnd__DrawColoredRect                                     0x6F8D10
#define CXWnd__DrawTooltip                                         0x6FD790
#define CXWnd__DrawTooltipAtPoint                                  0x6FCAF0
#define CXWnd__GetBorderFrame                                      0x6F91C0
#define CXWnd__GetChildWndAt                                       0x6FBF60
#define CXWnd__GetClientClipRect                                   0x6F8FD0
#define CXWnd__GetScreenClipRect                                   0x6FCF50
#define CXWnd__GetScreenRect                                       0x6F92E0
#define CXWnd__GetTooltipRect                                      0x6F8E20
#define CXWnd__GetWindowTextA                                      0x581750
#define CXWnd__IsActive                                            0x703600
#define CXWnd__IsDescendantOf                                      0x6F90B0
#define CXWnd__IsReallyVisible                                     0x6FBF40
#define CXWnd__IsType                                              0x727E50
#define CXWnd__Move                                                0x6FB690
#define CXWnd__Move1                                               0x6FD4F0
#define CXWnd__ProcessTransition                                   0x6F89E0
#define CXWnd__Refade                                              0x6F8960
#define CXWnd__Resize                                              0x6F93B0
#define CXWnd__Right                                               0x6FCE90
#define CXWnd__SetFocus                                            0x6FAAA0
#define CXWnd__SetKeyTooltip                                       0x6F95A0
#define CXWnd__SetMouseOver                                        0x6FD240
#define CXWnd__StartFade                                           0x6F8A60
#define CXWnd__GetChildItem                                        0x6FD1B0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x704B60
#define CXWndManager__DrawWindows                                  0x7047E0
#define CXWndManager__GetKeyboardFlags                             0x703260
#define CXWndManager__HandleKeyboardMsg                            0x7038D0
#define CXWndManager__RemoveWnd                                    0x703720

// CDBStr
#define CDBStr__GetString                                          0x463F50

// EQ_Character 
#define EQ_Character__CastRay                                      0x6B7170
#define EQ_Character__CastSpell                                    0x42E500
#define EQ_Character__Cur_HP                                       0x4376A0
#define EQ_Character__GetAACastingTimeModifier                     0x4244F0
#define EQ_Character__GetCharInfo2                                 0x6B5490
#define EQ_Character__GetFocusCastingTimeModifier                  0x41FDB0
#define EQ_Character__GetFocusRangeModifier                        0x41FEF0
#define EQ_Character__Max_Endurance                                0x524990
#define EQ_Character__Max_HP                                       0x432670
#define EQ_Character__Max_Mana                                     0x5247C0
#define EQ_Character__doCombatAbility                              0x5236D0
#define EQ_Character__UseSkill                                     0x4420A0
#define EQ_Character__GetConLevel                                  0x51F8A0

// EQ_Item 
#define EQ_Item__CanDrop                                           0x50A1E0
#define EQ_Item__GetItemLinkHash                                   0x6A7300
#define EQ_Item__IsStackable                                       0x69E130

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x47CD10
#define EQ_LoadingS__Array                                         0x8B0D88

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x527830
#define EQ_PC__GetAltAbilityIndex                                  0x6ACFF0
#define EQ_PC__GetCombatAbility                                    0x6AD080
#define EQ_PC__GetCombatAbilityTimer                               0x6AD130
#define EQ_PC__GetItemTimerValue                                   0x522600
#define EQ_PC__HasLoreItem                                         0x525CE0

// EQItemList 
#define EQItemList__EQItemList                                     0x4A83D0
#define EQItemList__add_item                                       0x4A8480
#define EQItemList__delete_item                                    0x4A86E0
#define EQItemList__FreeItemList                                   0x4A84A0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x463810

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x52C420
#define EQPlayer__dEQPlayer                                        0x530D10
#define EQPlayer__DoAttack                                         0x53FE30
#define EQPlayer__EQPlayer                                         0x535BC0
#define EQPlayer__SetNameSpriteState                               0x52E820
#define EQPlayer__SetNameSpriteTint                                0x52C490
#define EQPlayer__IsBodyType_j                                     0x6B6A80
#define EQPlayer__IsTargetable                                     0x6B6C10

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x536E50
#define EQPlayerManager__GetSpawnByName                            0x537130

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x50BE90
#define KeypressHandler__AttachKeyToEqCommand                      0x50BED0
#define KeypressHandler__ClearCommandStateArray                    0x50BCA0
#define KeypressHandler__HandleKeyDown                             0x50A820
#define KeypressHandler__HandleKeyUp                               0x50AB30
#define KeypressHandler__SaveKeymapping                            0x50BD70

// MapViewMap 
#define MapViewMap__Clear                                          0x6145E0
#define MapViewMap__SaveEx                                         0x614FB0

#define PlayerPointManager__GetAltCurrency                         0x6A7CC0

// StringTable 
#define StringTable__getString                                     0x69DA10