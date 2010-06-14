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
#define __ExpectedVersionDate                                     "Jun  8 2010"
#define __ExpectedVersionTime                                     "16:44:32"
#define __ActualVersionDate                                        0x820428
#define __ActualVersionTime                                        0x820434

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x511D40
#define __MemChecker1                                              0x6E76B0
#define __MemChecker2                                              0x573B70
#define __MemChecker3                                              0x573AC0
#define __MemChecker4                                              0x69B570
#define __EncryptPad0                                              0x8B11B0
#define __EncryptPad1                                              0x8BC2D8
#define __EncryptPad2                                              0x8B3DF0
#define __EncryptPad3                                              0x8B39F0
#define __EncryptPad4                                              0x8BB920
#define __AC1                                                      0x661A40
#define __AC2                                                      0x4D9F95
#define __AC3                                                      0x4EDF48
#define __AC4                                                      0x4F1E18
#define __AC5                                                      0x4FC588
#define __AC6                                                      0x4FFA0B
#define __AC7                                                      0x4F8AB4
#define __AC1_Data                                                 0x808020

// Direct Input
#define DI8__Main                                                  0xB16D04
#define DI8__Keyboard                                              0xB16D08
#define DI8__Mouse                                                 0xB16D0C
#define __AltTimerReady                                            0xA9DA16
#define __Attack                                                   0xB010B6
#define __Autofire                                                 0xB010B7
#define __BindList                                                 0x8AB910
#define __Clicks                                                   0xA9C710
#define __CommandList                                              0x8AC260
#define __CurrentMapLabel                                          0xB41FA0
#define __CurrentSocial                                            0x8A7840
#define __DoAbilityAvailable                                       0xA9D9B0
#define __DoAbilityList                                            0xAD2FD4
#define __do_loot                                                  0x4B2890
#define __DrawHandler                                              0xB516C4
#define __GroupCount                                               0xA9650A
#define __Guilds                                                   0xA9BAF0
#define __gWorld                                                   0xA983C8
#define __HotkeyPage                                               0xAFA3C0
#define __HWnd                                                     0xB16A40
#define __InChatMode                                               0xA9C648
#define __LastTell                                                 0xA9E32C
#define __LMouseHeldTime                                           0xA9C73C
#define __Mouse                                                    0xB16D10
#define __MouseLook                                                0xA9C6DE
#define __MouseEventTime                                           0xB011F8
#define __NetStatusToggle                                          0xA9C6E1
#define __PCNames                                                  0xA9DD70
#define __RangeAttackReady                                         0xA9DA14
#define __RMouseHeldTime                                           0xA9C738
#define __RunWalkState                                             0xA9C64C
#define __ScreenMode                                               0x9E5D98
#define __ScreenX                                                  0xA9C600
#define __ScreenY                                                  0xA9C604
#define __ScreenXMax                                               0xA9C608
#define __ScreenYMax                                               0xA9C60C
#define __ServerHost                                               0xA9644C
#define __ServerName                                               0xAD2F94
#define __ShiftKeyDown                                             0xA9CCC8
#define __ShowNames                                                0xA9DC44
#define __Socials                                                  0xAD3094


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA98488
#define instEQZoneInfo                                             0xA9C888
#define instKeypressHandler                                        0xB011DC
#define pinstActiveBanker                                          0xA9845C
#define pinstActiveCorpse                                          0xA98460
#define pinstActiveGMaster                                         0xA98464
#define pinstActiveMerchant                                        0xA98458
#define pinstAltAdvManager                                         0x9E6C18
#define pinstAuraMgr                                               0x8CF65C
#define pinstBandageTarget                                         0xA98444
#define pinstCamActor                                              0x9E6704
#define pinstCDBStr                                                0x9E5D88
#define pinstCDisplay                                              0xA9846C
#define pinstCEverQuest                                            0xB16E88
#define pinstCharData                                              0xA98428
#define pinstCharSpawn                                             0xA98450
#define pinstControlledMissile                                     0xA98424
#define pinstControlledPlayer                                      0xA98450
#define pinstCSidlManager                                          0xB50E38
#define pinstCXWndManager                                          0xB50E30
#define instDynamicZone                                            0xA9C4D0
#define pinstDZMember                                              0xA9C5E0
#define pinstDZTimerInfo                                           0xA9C5E4
#define pinstEQItemList                                            0xA95730
#define instEQMisc                                                 0x9E5D40
#define pinstEQSoundManager                                        0x9E6C3C
#define instExpeditionLeader                                       0xA9C51A
#define instExpeditionName                                         0xA9C55A
#define pinstGroup                                                 0xA96506
#define pinstImeManager                                            0xB50E3C
#define pinstLocalPlayer                                           0xA9843C
#define pinstMercenaryData                                         0xB01550
#define pinstModelPlayer                                           0xA98468
#define pinstPCData                                                0xA98428
#define pinstSkillMgr                                              0xB13AF4
#define pinstSpawnManager                                          0xB13950
#define pinstSpellManager                                          0xB13B00
#define pinstSpellSets                                             0xAFA3C4
#define pinstStringTable                                           0xA983E4
#define pinstSwitchManager                                         0xA9614C
#define pinstTarget                                                0xA98454
#define pinstTargetObject                                          0xA9842C
#define pinstTargetSwitch                                          0xA98430
#define pinstTaskMember                                            0x9E5D20
#define pinstTrackTarget                                           0xA98448
#define pinstTradeTarget                                           0xA98438
#define instTributeActive                                          0x9E5D65
#define pinstViewActor                                             0x9E6700
#define pinstWorldData                                             0xA9840C


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x8CCF24
#define pinstCAudioTriggersWindow                                  0x8CCEF0
#define pinstCCharacterSelect                                      0x9E6600
#define pinstCFacePick                                             0x9E65B0
#define pinstCNoteWnd                                              0x9E65B8
#define pinstCBookWnd                                              0x9E65BC
#define pinstCPetInfoWnd                                           0x9E65C0
#define pinstCTrainWnd                                             0x9E65C4
#define pinstCSkillsWnd                                            0x9E65C8
#define pinstCSkillsSelectWnd                                      0x9E65CC
#define pinstCCombatSkillSelectWnd                                 0x9E65D0
#define pinstCFriendsWnd                                           0x9E65D4
#define pinstCAuraWnd                                              0x9E65D8
#define pinstCRespawnWnd                                           0x9E65DC
#define pinstCBandolierWnd                                         0x9E65E0
#define pinstCPotionBeltWnd                                        0x9E65E4
#define pinstCAAWnd                                                0x9E65E8
#define pinstCGroupSearchFiltersWnd                                0x9E65EC
#define pinstCLoadskinWnd                                          0x9E65F0
#define pinstCAlarmWnd                                             0x9E65F4
#define pinstCMusicPlayerWnd                                       0x9E65F8
#define pinstCMailWnd                                              0x9E6604
#define pinstCMailCompositionWnd                                   0x9E6608
#define pinstCMailAddressBookWnd                                   0x9E660C
#define pinstCRaidWnd                                              0x9E6614
#define pinstCRaidOptionsWnd                                       0x9E6618
#define pinstCBreathWnd                                            0x9E661C
#define pinstCMapViewWnd                                           0x9E6620
#define pinstCMapToolbarWnd                                        0x9E6624
#define pinstCEditLabelWnd                                         0x9E6628
#define pinstCTargetWnd                                            0x9E662C
#define pinstCColorPickerWnd                                       0x9E6630
#define pinstCPlayerWnd                                            0x9E6634
#define pinstCOptionsWnd                                           0x9E6638
#define pinstCBuffWindowNORMAL                                     0x9E663C
#define pinstCBuffWindowSHORT                                      0x9E6640
#define pinstCharacterCreation                                     0x9E6644
#define pinstCCursorAttachment                                     0x9E6648
#define pinstCCastingWnd                                           0x9E664C
#define pinstCCastSpellWnd                                         0x9E6650
#define pinstCSpellBookWnd                                         0x9E6654
#define pinstCInventoryWnd                                         0x9E6658
#define pinstCBankWnd                                              0x9E665C
#define pinstCQuantityWnd                                          0x9E6660
#define pinstCLootWnd                                              0x9E6664
#define pinstCActionsWnd                                           0x9E6668
#define pinstCCombatAbilityWnd                                     0x9E666C
#define pinstCMerchantWnd                                          0x9E6670
#define pinstCTradeWnd                                             0x9E6674
#define pinstCSelectorWnd                                          0x9E6678
#define pinstCBazaarWnd                                            0x9E667C
#define pinstCBazaarSearchWnd                                      0x9E6680
#define pinstCGiveWnd                                              0x9E6684
#define pinstCTrackingWnd                                          0x9E6688
#define pinstCInspectWnd                                           0x9E668C
#define pinstCSocialEditWnd                                        0x9E6690
#define pinstCFeedbackWnd                                          0x9E6694
#define pinstCBugReportWnd                                         0x9E6698
#define pinstCVideoModesWnd                                        0x9E669C
#define pinstCTextEntryWnd                                         0x9E66A4
#define pinstCFileSelectionWnd                                     0x9E66A8
#define pinstCCompassWnd                                           0x9E66AC
#define pinstCPlayerNotesWnd                                       0x9E66B0
#define pinstCGemsGameWnd                                          0x9E66B4
#define pinstCTimeLeftWnd                                          0x9E66B8
#define pinstCPetitionQWnd                                         0x9E66CC
#define pinstCSoulmarkWnd                                          0x9E66D0
#define pinstCStoryWnd                                             0x9E66D4
#define pinstCJournalTextWnd                                       0x9E66D8
#define pinstCJournalCatWnd                                        0x9E66DC
#define pinstCBodyTintWnd                                          0x9E66E0
#define pinstCServerListWnd                                        0x9E66E4
#define pinstCAvaZoneWnd                                           0x9E66EC
#define pinstCBlockedBuffWnd                                       0x9E66F0
#define pinstCBlockedPetBuffWnd                                    0x9E66F4
#define pinstCInvSlotMgr                                           0x9E66F8
#define pinstCContainerMgr                                         0x9E66FC
#define pinstCAdventureLeaderboardWnd                              0xB3F4B8
#define pinstCAdventureRequestWnd                                  0xB3F4D4
#define pinstCAltStorageWnd                                        0xB3F534
#define pinstCAdventureStatsWnd                                    0xB3F4F0
#define pinstCBarterMerchantWnd                                    0xB3F700
#define pinstCBarterSearchWnd                                      0xB3F71C
#define pinstCBarterWnd                                            0xB3F738
#define pinstCChatManager                                          0xB3F9DC
#define pinstCDynamicZoneWnd                                       0xB3FAD4
#define pinstCEQMainWnd                                            0xB3FB48
#define pinstCFellowshipWnd                                        0xB3FBAC
#define pinstCFindLocationWnd                                      0xB3FBE0
#define pinstCGroupSearchWnd                                       0xB3FC90
#define pinstCGroupWnd                                             0xB3FCAC
#define pinstCGuildBankWnd                                         0xB3FCC8
#define pinstCGuildMgmtWnd                                         0xB41D00
#define pinstCGuildTributeMasterWnd                                0xB41D20
#define pinstCHotButtonWnd                                         0xB41D54
#define pinstCHotButtonWnd1                                        0xB41D54
#define pinstCHotButtonWnd2                                        0xB41D58
#define pinstCHotButtonWnd3                                        0xB41D5C
#define pinstCHotButtonWnd4                                        0xB41D60
#define pinstCItemDisplayManager                                   0xB41E0C
#define pinstCItemExpTransferWnd                                   0xB41E2C
#define pinstCLeadershipWnd                                        0xB41EC8
#define pinstCLFGuildWnd                                           0xB41EE4
#define pinstCMIZoneSelectWnd                                      0xB42054
#define pinstCAdventureMerchantWnd                                 0xB42164
#define pinstCConfirmationDialog                                   0xB42180
#define pinstCPopupWndManager                                      0xB42180
#define pinstCProgressionSelectionWnd                              0xB421B4
#define pinstCPvPLeaderboardWnd                                    0xB421D0
#define pinstCPvPStatsWnd                                          0xB421EC
#define pinstCSystemInfoDialogBox                                  0xB422B8
#define pinstCTargetOfTargetWnd                                    0xB42DB8
#define pinstCTaskSelectWnd                                        0xB42DEC
#define pinstCTaskTemplateSelectWnd                                0xB42E08
#define pinstCTaskWnd                                              0xB42E24
#define pinstCTipWndOFDAY                                          0xB42EA0
#define pinstCTipWndCONTEXT                                        0xB42EA4
#define pinstCTitleWnd                                             0xB42EC0
#define pinstCTradeskillWnd                                        0xB42F04
#define pinstCTributeBenefitWnd                                    0xB42F50
#define pinstCTributeMasterWnd                                     0xB42F6C
#define pinstCContextMenuManager                                   0xB50E94
#define pinstCVoiceMacroWnd                                        0xB13CF4
#define pinstCHtmlWnd                                              0xB13D40


//// 
// Section 3: Miscellaneous Offsets 
////
#define __CastRay                                                  0x4C66F0
#define __ConvertItemTags                                          0x4B7F10
#define __ExecuteCmd                                               0x4A4260
#define __get_melee_range                                          0x4A9ED0
#define __GetGaugeValueFromEQ                                      0x660900
#define __GetLabelFromEQ                                           0x6619E0
#define __GetXTargetType                                           0x755CA0
#define __LoadFrontEnd                                             0x572A40
#define __NewUIINI                                                 0x660490
#define __ProcessGameEvents                                        0x4F8EA0
#define CrashDetected                                              0x572840
#define DrawNetStatus                                              0x51C720
#define Util__FastTime                                             0x6E7E00


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47B630
#define AltAdvManager__IsAbilityReady                              0x47B670
#define AltAdvManager__GetAltAbility                               0x47B850

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x590140

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x599410

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x715B70

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5AF580
#define CChatManager__InitContextMenu                              0x5AFD50

// CChatService
#define CChatService__GetNumberOfFriends                           0x6D2620
#define CChatService__GetFriendName                                0x6D2630

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5B3F50
#define CChatWindow__Clear                                         0x5B48C0
#define CChatWindow__WndNotification                               0x5B4AB0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6FFC50
#define CComboWnd__Draw                                            0x6FFE10
#define CComboWnd__GetCurChoice                                    0x6FFBF0
#define CComboWnd__GetListRect                                     0x700100
#define CComboWnd__GetTextRect                                     0x6FFC80
#define CComboWnd__InsertChoice                                    0x700170
#define CComboWnd__SetColors                                       0x6FFB80
#define CComboWnd__SetChoice                                       0x6FFBB0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5BBF60
#define CContainerWnd__vftable                                     0x827E58

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46E6D0
#define CDisplay__GetClickedActor                                  0x467A20
#define CDisplay__GetUserDefinedColor                              0x466B40
#define CDisplay__GetWorldFilePath                                 0x465FD0
#define CDisplay__is3dON                                           0x465110
#define CDisplay__ReloadUI                                         0x4787C0
#define CDisplay__WriteTextHD2                                     0x46A6F0

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x589FE0
#define CEditBaseWnd__SetSel                                       0x7225A0

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x708BA0
#define CEditWnd__GetCharIndexPt                                   0x709B70
#define CEditWnd__GetDisplayString                                 0x708D40
#define CEditWnd__GetHorzOffset                                    0x708FD0
#define CEditWnd__GetLineForPrintableChar                          0x709620
#define CEditWnd__GetSelStartPt                                    0x709DC0
#define CEditWnd__GetSTMLSafeText                                  0x709170
#define CEditWnd__PointFromPrintableChar                           0x709730
#define CEditWnd__SelectableCharFromPoint                          0x7098B0
#define CEditWnd__SetEditable                                      0x709140

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4DA670
#define CEverQuest__DropHeldItemOnGround                           0x4DEBC0
#define CEverQuest__dsp_chat                                       0x4E0310
#define CEverQuest__DoTellWindow                                   0x4DED40
#define CEverQuest__EnterZone                                      0x4F1DB0
#define CEverQuest__GetBodyTypeDesc                                0x4D7870
#define CEverQuest__GetClassDesc                                   0x4D70B0
#define CEverQuest__GetClassThreeLetterCode                        0x4D76B0
#define CEverQuest__GetDeityDesc                                   0x4D7EE0
#define CEverQuest__GetLangDesc                                    0x4D7C00
#define CEverQuest__GetRaceDesc                                    0x4D7EB0
#define CEverQuest__InterpretCmd                                   0x4E0E70
#define CEverQuest__LeftClickedOnPlayer                            0x4F38E0
#define CEverQuest__LMouseUp                                       0x4F71F0
#define CEverQuest__RightClickedOnPlayer                           0x4F7A90
#define CEverQuest__RMouseUp                                       0x4F8A70
#define CEverQuest__SetGameState                                   0x4DAB00
#define CEverQuest__Emote                                          0x4E0530

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5C8800
#define CGaugeWnd__CalcLinesFillRect                               0x5C8860
#define CGaugeWnd__Draw                                            0x5C8CB0

// CGuild
#define CGuild__FindMemberByName                                   0x41B210

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5E17C0

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5EADC0
#define CInvSlotMgr__MoveItem                                      0x5EAF60

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5EA650
#define CInvSlot__SliderComplete                                   0x5E9760

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5EBF10

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x65E270
#define CItemDisplayWnd__UpdateStrings                             0x5ECBC0

// CLabel 
#define CLabel__Draw                                               0x5FF2A0

// CListWnd 
#define CListWnd__AddColumn                                        0x6F9670
#define CListWnd__AddColumn1                                       0x6F9140
#define CListWnd__AddLine                                          0x6F8C60
#define CListWnd__AddString                                        0x6F8E00
#define CListWnd__CalculateFirstVisibleLine                        0x6F5920
#define CListWnd__CalculateVSBRange                                0x6F7B40
#define CListWnd__ClearAllSel                                      0x6F4E70
#define CListWnd__CloseAndUpdateEditWindow                         0x6F5FA0
#define CListWnd__Compare                                          0x6F6340
#define CListWnd__Draw                                             0x6F77C0
#define CListWnd__DrawColumnSeparators                             0x6F7630
#define CListWnd__DrawHeader                                       0x6F5100
#define CListWnd__DrawItem                                         0x6F6C50
#define CListWnd__DrawLine                                         0x6F72A0
#define CListWnd__DrawSeparator                                    0x6F76D0
#define CListWnd__EnsureVisible                                    0x6F59B0
#define CListWnd__ExtendSel                                        0x6F6B70
#define CListWnd__GetColumnMinWidth                                0x6F4C00
#define CListWnd__GetColumnWidth                                   0x6F4B40
#define CListWnd__GetCurSel                                        0x6F4580
#define CListWnd__GetHeaderRect                                    0x6F46F0
#define CListWnd__GetItemAtPoint                                   0x6F5CB0
#define CListWnd__GetItemAtPoint1                                  0x6F5D20
#define CListWnd__GetItemData                                      0x6F48F0
#define CListWnd__GetItemHeight                                    0x6F5590
#define CListWnd__GetItemIcon                                      0x6F4A80
#define CListWnd__GetItemRect                                      0x6F5A90
#define CListWnd__GetItemText                                      0x6F4930
#define CListWnd__GetSelList                                       0x6F9020
#define CListWnd__GetSeparatorRect                                 0x6F6280
#define CListWnd__RemoveLine                                       0x6F8FD0
#define CListWnd__SetColors                                        0x6F4650
#define CListWnd__SetColumnJustification                           0x6F4CE0
#define CListWnd__SetColumnWidth                                   0x6F4BC0
#define CListWnd__SetCurSel                                        0x6F45C0
#define CListWnd__SetItemColor                                     0x6F87F0
#define CListWnd__SetItemData                                      0x6F4F10
#define CListWnd__SetItemText                                      0x6F8770
#define CListWnd__ShiftColumnSeparator                             0x6F6A80
#define CListWnd__Sort                                             0x6F96B0
#define CListWnd__ToggleSel                                        0x6F4DE0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x614B70

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x622B70
#define CMerchantWnd__RequestBuyItem                               0x624B90
#define CMerchantWnd__RequestSellItem                              0x624FB0
#define CMerchantWnd__SelectBuySellSlot                            0x623FC0

// CObfuscator
#define CObfuscator__doit                                          0x6ABDD0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x711430
#define CSidlManager__CreateLabel                                  0x6571F0

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x7018A0
#define CSidlScreenWnd__CalculateVSBRange                          0x58C150
#define CSidlScreenWnd__ConvertToRes                               0x722480
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x701D70
#define CSidlScreenWnd__CSidlScreenWnd1                            0x702E60
#define CSidlScreenWnd__CSidlScreenWnd2                            0x702F10
#define CSidlScreenWnd__dCSidlScreenWnd                            0x702610
#define CSidlScreenWnd__DrawSidlPiece                              0x701A30
#define CSidlScreenWnd__EnableIniStorage                           0x701590
#define CSidlScreenWnd__GetSidlPiece                               0x701C40
#define CSidlScreenWnd__Init1                                      0x702CC0
#define CSidlScreenWnd__LoadIniInfo                                0x701E30
#define CSidlScreenWnd__LoadIniListWnd                             0x7016E0
#define CSidlScreenWnd__LoadSidlScreen                             0x702860
#define CSidlScreenWnd__StoreIniInfo                               0x7011A0
#define CSidlScreenWnd__StoreIniVis                                0x701520
#define CSidlScreenWnd__WndNotification                            0x702A40
#define CSidlScreenWnd__GetChildItem                               0x7015F0

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x540450

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x7239D0
#define CSliderWnd__SetValue                                       0x723AD0
#define CSliderWnd__SetNumTicks                                    0x724080

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x65BFB0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x720680
#define CStmlWnd__CalculateHSBRange                                0x717E00
#define CStmlWnd__CalculateVSBRange                                0x717D70
#define CStmlWnd__CanBreakAtCharacter                              0x717F80
#define CStmlWnd__FastForwardToEndOfTag                            0x718C60
#define CStmlWnd__ForceParseNow                                    0x720B80
#define CStmlWnd__GetNextTagPiece                                  0x718B80
#define CStmlWnd__GetSTMLText                                      0x5B3EF0
#define CStmlWnd__GetThisChar                                      0x7478F0
#define CStmlWnd__GetVisiableText                                  0x71A0A0
#define CStmlWnd__InitializeWindowVariables                        0x71C600
#define CStmlWnd__MakeStmlColorTag                                 0x716C90
#define CStmlWnd__MakeWndNotificationTag                           0x716D30
#define CStmlWnd__SetSTMLText                                      0x71C720
#define CStmlWnd__StripFirstSTMLLines                              0x720320
#define CStmlWnd__UpdateHistoryString                              0x71A930

// CTabWnd 
#define CTabWnd__Draw                                              0x724EA0
#define CTabWnd__DrawCurrentPage                                   0x724830
#define CTabWnd__DrawTab                                           0x724610
#define CTabWnd__GetCurrentPage                                    0x724B30
#define CTabWnd__GetPageClientRect                                 0x7242E0
#define CTabWnd__GetPageFromTabIndex                               0x724540
#define CTabWnd__GetPageInnerRect                                  0x724340
#define CTabWnd__GetTabInnerRect                                   0x7244C0
#define CTabWnd__GetTabRect                                        0x7243D0
#define CTabWnd__InsertPage                                        0x725130
#define CTabWnd__SetPage                                           0x724B70
#define CTabWnd__SetPageRect                                       0x724DD0
#define CTabWnd__UpdatePage                                        0x7250B0

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417800

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x703290

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x725D40

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6F3830

// CXRect 
#define CXRect__CenterPoint                                        0x58F7C0

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x50B780
#define CXStr__CXStr1                                              0x6ED4A0
#define CXStr__CXStr3                                              0x6E50C0
#define CXStr__dCXStr                                              0x5C86F0
#define CXStr__operator_equal1                                     0x6E5280
#define CXStr__operator_plus_equal1                                0x6E62C0

// CXWnd 
#define CXWnd__BringToTop                                          0x6F9C90
#define CXWnd__Center                                              0x6FE480
#define CXWnd__ClrFocus                                            0x6F9AB0
#define CXWnd__DoAllDrawing                                        0x6FF320
#define CXWnd__DrawChildren                                        0x6FF470
#define CXWnd__DrawColoredRect                                     0x6F9F70
#define CXWnd__DrawTooltip                                         0x6FF170
#define CXWnd__DrawTooltipAtPoint                                  0x6FE230
#define CXWnd__GetBorderFrame                                      0x6FA3B0
#define CXWnd__GetChildWndAt                                       0x6FDA60
#define CXWnd__GetClientClipRect                                   0x6FA230
#define CXWnd__GetScreenClipRect                                   0x6FE6A0
#define CXWnd__GetScreenRect                                       0x6FA540
#define CXWnd__GetTooltipRect                                      0x6FA080
#define CXWnd__GetWindowTextA                                      0x57D920
#define CXWnd__IsActive                                            0x704400
#define CXWnd__IsDescendantOf                                      0x6FA2E0
#define CXWnd__IsReallyVisible                                     0x6FDA40
#define CXWnd__IsType                                              0x728B30
#define CXWnd__Move                                                0x6FD200
#define CXWnd__Move1                                               0x6FEF50
#define CXWnd__ProcessTransition                                   0x6F9C40
#define CXWnd__Refade                                              0x6F9BC0
#define CXWnd__Resize                                              0x6FA610
#define CXWnd__Right                                               0x6FE5E0
#define CXWnd__SetFocus                                            0x6FBDD0
#define CXWnd__SetKeyTooltip                                       0x6FA7F0
#define CXWnd__SetMouseOver                                        0x6FE980
#define CXWnd__StartFade                                           0x6F9CD0
#define CXWnd__GetChildItem                                        0x6FE900

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x705950
#define CXWndManager__DrawWindows                                  0x7055D0
#define CXWndManager__GetKeyboardFlags                             0x704050
#define CXWndManager__HandleKeyboardMsg                            0x7046D0
#define CXWndManager__RemoveWnd                                    0x704520

// CDBStr
#define CDBStr__GetString                                          0x463A80

// EQ_Character 
#define EQ_Character__CastRay                                      0x753B20
#define EQ_Character__CastSpell                                    0x42E0D0
#define EQ_Character__Cur_HP                                       0x437250
#define EQ_Character__GetAACastingTimeModifier                     0x423DE0
#define EQ_Character__GetCharInfo2                                 0x6C2E40
#define EQ_Character__GetFocusCastingTimeModifier                  0x41F640
#define EQ_Character__GetFocusRangeModifier                        0x41F780
#define EQ_Character__Max_Endurance                                0x522CC0
#define EQ_Character__Max_HP                                       0x432220
#define EQ_Character__Max_Mana                                     0x522AF0
#define EQ_Character__doCombatAbility                              0x521A00
#define EQ_Character__UseSkill                                     0x441C50
#define EQ_Character__GetConLevel                                  0x51DC00

// EQ_Item 
#define EQ_Item__CanDrop                                           0x5094F0
#define EQ_Item__GetItemLinkHash                                   0x6B5880
#define EQ_Item__IsStackable                                       0x6AC6B0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x47C720
#define EQ_LoadingS__Array                                         0x8A9D78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x525B60
#define EQ_PC__GetAltAbilityIndex                                  0x6BAAB0
#define EQ_PC__GetCombatAbility                                    0x6BAB40
#define EQ_PC__GetCombatAbilityTimer                               0x6BABF0
#define EQ_PC__GetItemTimerValue                                   0x520920
#define EQ_PC__HasLoreItem                                         0x524010

// EQItemList 
#define EQItemList__EQItemList                                     0x4A80C0
#define EQItemList__add_item                                       0x4A8170
#define EQItemList__delete_item                                    0x4A83D0
#define EQItemList__FreeItemList                                   0x4A8190

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x463430

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x52A540
#define EQPlayer__dEQPlayer                                        0x52E6F0
#define EQPlayer__DoAttack                                         0x53C680
#define EQPlayer__EQPlayer                                         0x5324C0
#define EQPlayer__SetNameSpriteState                               0x52C650
#define EQPlayer__SetNameSpriteTint                                0x52A5B0
#define EQPlayer__IsBodyType_j                                     0x753430
#define EQPlayer__IsTargetable                                     0x7535C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x533670
#define EQPlayerManager__GetSpawnByName                            0x533950

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x50B1A0
#define KeypressHandler__AttachKeyToEqCommand                      0x50B1E0
#define KeypressHandler__ClearCommandStateArray                    0x50AFB0
#define KeypressHandler__HandleKeyDown                             0x509B30
#define KeypressHandler__HandleKeyUp                               0x509E40
#define KeypressHandler__SaveKeymapping                            0x50B080

// MapViewMap 
#define MapViewMap__Clear                                          0x610210
#define MapViewMap__SaveEx                                         0x610BE0

#define OtherCharData__GetAltCurrency                              0x6DB240

// StringTable 
#define StringTable__getString                                     0x6AC050
