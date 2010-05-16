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
#define __ExpectedVersionDate                                     "May 11 2010"
#define __ExpectedVersionTime                                     "11:09:17"
#define __ActualVersionDate                                        0x8203F0
#define __ActualVersionTime                                        0x8203FC

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x511AE0
#define __MemChecker1                                              0x6E7850
#define __MemChecker2                                              0x573A30
#define __MemChecker3                                              0x573980
#define __MemChecker4                                              0x69B5F0
#define __EncryptPad0                                              0x8B11B0
#define __EncryptPad1                                              0x8BC2D8
#define __EncryptPad2                                              0x8B3DF0
#define __EncryptPad3                                              0x8B39F0
#define __EncryptPad4                                              0x8BB920
#define __AC1                                                      0x661C70
#define __AC2                                                      0x4D9D45
#define __AC3                                                      0x4EDD48
#define __AC4                                                      0x4F1C18
#define __AC5                                                      0x4FC388
#define __AC6                                                      0x4FF80B
#define __AC7                                                      0x4F88B4
#define __AC1_Data                                                 0x8081D0

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
#define __do_loot                                                  0x4B2820
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
#define __CastRay                                                  0x4C6680
#define __ConvertItemTags                                          0x4B7EA0
#define __ExecuteCmd                                               0x4A41C0
#define __get_melee_range                                          0x4A9E60
#define __GetGaugeValueFromEQ                                      0x660B30
#define __GetLabelFromEQ                                           0x661C10
#define __GetXTargetType                                           0x755D50
#define __LoadFrontEnd                                             0x572900
#define __NewUIINI                                                 0x6606C0
#define __ProcessGameEvents                                        0x4F8CA0
#define CrashDetected                                              0x572700
#define DrawNetStatus                                              0x51C470
#define Util__FastTime                                             0x6E7F60


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47B5E0
#define AltAdvManager__IsAbilityReady                              0x47B620
#define AltAdvManager__GetAltAbility                               0x47B830

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x58FF90

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x599470

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x715D20

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5AF740
#define CChatManager__InitContextMenu                              0x5AFF10

// CChatService
#define CChatService__GetNumberOfFriends                           0x6D2640
#define CChatService__GetFriendName                                0x6D2650

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5B4110
#define CChatWindow__Clear                                         0x5B4A90
#define CChatWindow__WndNotification                               0x5B4C80

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6FFD10
#define CComboWnd__Draw                                            0x6FFED0
#define CComboWnd__GetCurChoice                                    0x6FFCB0
#define CComboWnd__GetListRect                                     0x7001C0
#define CComboWnd__GetTextRect                                     0x6FFD40
#define CComboWnd__InsertChoice                                    0x700230
#define CComboWnd__SetColors                                       0x6FFC40
#define CComboWnd__SetChoice                                       0x6FFC70

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5BC1B0
#define CContainerWnd__vftable                                     0x827E20

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46E710
#define CDisplay__GetClickedActor                                  0x467A80
#define CDisplay__GetUserDefinedColor                              0x466BA0
#define CDisplay__GetWorldFilePath                                 0x466030
#define CDisplay__is3dON                                           0x465170
#define CDisplay__ReloadUI                                         0x4787F0
#define CDisplay__WriteTextHD2                                     0x46A730

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x589DD0
#define CEditBaseWnd__SetSel                                       0x722750

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x708BC0
#define CEditWnd__GetCharIndexPt                                   0x709B90
#define CEditWnd__GetDisplayString                                 0x708D60
#define CEditWnd__GetHorzOffset                                    0x708FF0
#define CEditWnd__GetLineForPrintableChar                          0x709640
#define CEditWnd__GetSelStartPt                                    0x709DE0
#define CEditWnd__GetSTMLSafeText                                  0x709190
#define CEditWnd__PointFromPrintableChar                           0x709750
#define CEditWnd__SelectableCharFromPoint                          0x7098D0
#define CEditWnd__SetEditable                                      0x709160

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4DA420
#define CEverQuest__DropHeldItemOnGround                           0x4DE9C0
#define CEverQuest__dsp_chat                                       0x4E0110
#define CEverQuest__DoTellWindow                                   0x4DEB40
#define CEverQuest__EnterZone                                      0x4F1BB0
#define CEverQuest__GetBodyTypeDesc                                0x4D7620
#define CEverQuest__GetClassDesc                                   0x4D6E60
#define CEverQuest__GetClassThreeLetterCode                        0x4D7460
#define CEverQuest__GetDeityDesc                                   0x4D7C90
#define CEverQuest__GetLangDesc                                    0x4D79B0
#define CEverQuest__GetRaceDesc                                    0x4D7C60
#define CEverQuest__InterpretCmd                                   0x4E0C70
#define CEverQuest__LeftClickedOnPlayer                            0x4F36E0
#define CEverQuest__LMouseUp                                       0x4F6FF0
#define CEverQuest__RightClickedOnPlayer                           0x4F7890
#define CEverQuest__RMouseUp                                       0x4F8870
#define CEverQuest__SetGameState                                   0x4DA8B0
#define CEverQuest__Emote                                          0x4E0330

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5C89E0
#define CGaugeWnd__CalcLinesFillRect                               0x5C8A40
#define CGaugeWnd__Draw                                            0x5C8E90

// CGuild
#define CGuild__FindMemberByName                                   0x41AE40

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5E1A00

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5EB000
#define CInvSlotMgr__MoveItem                                      0x5EB1A0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5EA890
#define CInvSlot__SliderComplete                                   0x5E99A0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5EC150

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x65E490
#define CItemDisplayWnd__UpdateStrings                             0x5ECE00

// CLabel 
#define CLabel__Draw                                               0x5FF4C0

// CListWnd 
#define CListWnd__AddColumn                                        0x6F9730
#define CListWnd__AddColumn1                                       0x6F9200
#define CListWnd__AddLine                                          0x6F8D20
#define CListWnd__AddString                                        0x6F8EC0
#define CListWnd__CalculateFirstVisibleLine                        0x6F59E0
#define CListWnd__CalculateVSBRange                                0x6F7C00
#define CListWnd__ClearAllSel                                      0x6F4F30
#define CListWnd__CloseAndUpdateEditWindow                         0x6F6060
#define CListWnd__Compare                                          0x6F6400
#define CListWnd__Draw                                             0x6F7880
#define CListWnd__DrawColumnSeparators                             0x6F76F0
#define CListWnd__DrawHeader                                       0x6F51C0
#define CListWnd__DrawItem                                         0x6F6D10
#define CListWnd__DrawLine                                         0x6F7360
#define CListWnd__DrawSeparator                                    0x6F7790
#define CListWnd__EnsureVisible                                    0x6F5A70
#define CListWnd__ExtendSel                                        0x6F6C30
#define CListWnd__GetColumnMinWidth                                0x6F4CC0
#define CListWnd__GetColumnWidth                                   0x6F4C00
#define CListWnd__GetCurSel                                        0x6F4620
#define CListWnd__GetHeaderRect                                    0x6F47B0
#define CListWnd__GetItemAtPoint                                   0x6F5D70
#define CListWnd__GetItemAtPoint1                                  0x6F5DE0
#define CListWnd__GetItemData                                      0x6F49B0
#define CListWnd__GetItemHeight                                    0x6F5650
#define CListWnd__GetItemIcon                                      0x6F4B40
#define CListWnd__GetItemRect                                      0x6F5B50
#define CListWnd__GetItemText                                      0x6F49F0
#define CListWnd__GetSelList                                       0x6F90E0
#define CListWnd__GetSeparatorRect                                 0x6F6340
#define CListWnd__RemoveLine                                       0x6F9090
#define CListWnd__SetColors                                        0x6F4710
#define CListWnd__SetColumnJustification                           0x6F4DA0
#define CListWnd__SetColumnWidth                                   0x6F4C80
#define CListWnd__SetCurSel                                        0x6F4660
#define CListWnd__SetItemColor                                     0x6F88B0
#define CListWnd__SetItemData                                      0x6F4FD0
#define CListWnd__SetItemText                                      0x6F8830
#define CListWnd__ShiftColumnSeparator                             0x6F6B40
#define CListWnd__Sort                                             0x6F9770
#define CListWnd__ToggleSel                                        0x6F4EA0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x614D80

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x622D70
#define CMerchantWnd__RequestBuyItem                               0x624D90
#define CMerchantWnd__RequestSellItem                              0x6251B0
#define CMerchantWnd__SelectBuySellSlot                            0x6241C0

// CObfuscator
#define CObfuscator__doit                                          0x6ABEE0

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x711400
#define CSidlManager__CreateLabel                                  0x657410

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x58BF70
#define CSidlScreenWnd__CalculateVSBRange                          0x58BE90
#define CSidlScreenWnd__ConvertToRes                               0x722630
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x701D10
#define CSidlScreenWnd__CSidlScreenWnd1                            0x702E00
#define CSidlScreenWnd__CSidlScreenWnd2                            0x702EB0
#define CSidlScreenWnd__dCSidlScreenWnd                            0x7025B0
#define CSidlScreenWnd__DrawSidlPiece                              0x7019D0
#define CSidlScreenWnd__EnableIniStorage                           0x701610
#define CSidlScreenWnd__GetSidlPiece                               0x701BE0
#define CSidlScreenWnd__Init1                                      0x702C60
#define CSidlScreenWnd__LoadIniInfo                                0x701DD0
#define CSidlScreenWnd__LoadIniListWnd                             0x701760
#define CSidlScreenWnd__LoadSidlScreen                             0x702800
#define CSidlScreenWnd__StoreIniInfo                               0x701220
#define CSidlScreenWnd__StoreIniVis                                0x7015A0
#define CSidlScreenWnd__WndNotification                            0x7029E0
#define CSidlScreenWnd__GetChildItem                               0x701670

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x540270

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x723B90
#define CSliderWnd__SetValue                                       0x723C90
#define CSliderWnd__SetNumTicks                                    0x724240

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x65C1D0

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x720830
#define CStmlWnd__CalculateHSBRange                                0x717FB0
#define CStmlWnd__CalculateVSBRange                                0x717F20
#define CStmlWnd__CanBreakAtCharacter                              0x718130
#define CStmlWnd__FastForwardToEndOfTag                            0x718E10
#define CStmlWnd__ForceParseNow                                    0x720D30
#define CStmlWnd__GetNextTagPiece                                  0x718D30
#define CStmlWnd__GetSTMLText                                      0x5B40B0
#define CStmlWnd__GetThisChar                                      0x747AC0
#define CStmlWnd__GetVisiableText                                  0x71A250
#define CStmlWnd__InitializeWindowVariables                        0x71C7B0
#define CStmlWnd__MakeStmlColorTag                                 0x716E40
#define CStmlWnd__MakeWndNotificationTag                           0x716EE0
#define CStmlWnd__SetSTMLText                                      0x71C8D0
#define CStmlWnd__StripFirstSTMLLines                              0x7204D0
#define CStmlWnd__UpdateHistoryString                              0x71AAE0

// CTabWnd 
#define CTabWnd__Draw                                              0x725010
#define CTabWnd__DrawCurrentPage                                   0x7249F0
#define CTabWnd__DrawTab                                           0x7247D0
#define CTabWnd__GetCurrentPage                                    0x724CA0
#define CTabWnd__GetPageClientRect                                 0x7244A0
#define CTabWnd__GetPageFromTabIndex                               0x724700
#define CTabWnd__GetPageInnerRect                                  0x724500
#define CTabWnd__GetTabInnerRect                                   0x724680
#define CTabWnd__GetTabRect                                        0x724590
#define CTabWnd__InsertPage                                        0x7252A0
#define CTabWnd__SetPage                                           0x724CE0
#define CTabWnd__SetPageRect                                       0x724F40
#define CTabWnd__UpdatePage                                        0x725220

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x417410

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x703230

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x725EB0

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6F37F0

// CXRect 
#define CXRect__CenterPoint                                        0x58F610

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x415780
#define CXStr__CXStr1                                              0x6EE7D0
#define CXStr__CXStr3                                              0x6E5260
#define CXStr__dCXStr                                              0x448730
#define CXStr__operator_equal1                                     0x6E5420
#define CXStr__operator_plus_equal1                                0x6E6460

// CXWnd 
#define CXWnd__BringToTop                                          0x6F9D50
#define CXWnd__Center                                              0x6FE590
#define CXWnd__ClrFocus                                            0x6F9B70
#define CXWnd__DoAllDrawing                                        0x6FF3E0
#define CXWnd__DrawChildren                                        0x6FF530
#define CXWnd__DrawColoredRect                                     0x6FA030
#define CXWnd__DrawTooltip                                         0x6FF230
#define CXWnd__DrawTooltipAtPoint                                  0x6FE340
#define CXWnd__GetBorderFrame                                      0x6FA470
#define CXWnd__GetChildWndAt                                       0x6FDB70
#define CXWnd__GetClientClipRect                                   0x6FA2F0
#define CXWnd__GetScreenClipRect                                   0x6FE7B0
#define CXWnd__GetScreenRect                                       0x6FA600
#define CXWnd__GetTooltipRect                                      0x6FA140
#define CXWnd__GetWindowTextA                                      0x57D7A0
#define CXWnd__IsActive                                            0x7043A0
#define CXWnd__IsDescendantOf                                      0x6FA3A0
#define CXWnd__IsReallyVisible                                     0x6FDB50
#define CXWnd__IsType                                              0x728CC0
#define CXWnd__Move                                                0x6FD310
#define CXWnd__Move1                                               0x6FF010
#define CXWnd__ProcessTransition                                   0x6F9D00
#define CXWnd__Refade                                              0x6F9C80
#define CXWnd__Resize                                              0x6FA6D0
#define CXWnd__Right                                               0x6FE6F0
#define CXWnd__SetFocus                                            0x6FBEE0
#define CXWnd__SetKeyTooltip                                       0x6FA8B0
#define CXWnd__SetMouseOver                                        0x6FEA40
#define CXWnd__StartFade                                           0x6F9D90
#define CXWnd__GetChildItem                                        0x6FE9C0

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x705970
#define CXWndManager__DrawWindows                                  0x7055F0
#define CXWndManager__GetKeyboardFlags                             0x703FF0
#define CXWndManager__HandleKeyboardMsg                            0x704670
#define CXWndManager__RemoveWnd                                    0x7044C0

// CDBStr
#define CDBStr__GetString                                          0x463AD0

// EQ_Character 
#define EQ_Character__CastRay                                      0x753B70
#define EQ_Character__CastSpell                                    0x42DCF0
#define EQ_Character__Cur_HP                                       0x437260
#define EQ_Character__GetAACastingTimeModifier                     0x423A00
#define EQ_Character__GetCharInfo2                                 0x6C2F60
#define EQ_Character__GetFocusCastingTimeModifier                  0x41F240
#define EQ_Character__GetFocusRangeModifier                        0x41F380
#define EQ_Character__Max_Endurance                                0x522A00
#define EQ_Character__Max_HP                                       0x432230
#define EQ_Character__Max_Mana                                     0x522830
#define EQ_Character__doCombatAbility                              0x521740
#define EQ_Character__UseSkill                                     0x441C30
#define EQ_Character__GetConLevel                                  0x51D950

// EQ_Item 
#define EQ_Item__CanDrop                                           0x509320
#define EQ_Item__GetItemLinkHash                                   0x6B5990
#define EQ_Item__IsStackable                                       0x6AC7C0

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x47C700
#define EQ_LoadingS__Array                                         0x8A9D78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x5258A0
#define EQ_PC__GetAltAbilityIndex                                  0x6BAC20
#define EQ_PC__GetCombatAbility                                    0x6BACB0
#define EQ_PC__GetCombatAbilityTimer                               0x6BAD60
#define EQ_PC__GetItemTimerValue                                   0x520670
#define EQ_PC__HasLoreItem                                         0x523D50

// EQItemList 
#define EQItemList__EQItemList                                     0x4A8020
#define EQItemList__add_item                                       0x4A80D0
#define EQItemList__delete_item                                    0x4A8330
#define EQItemList__FreeItemList                                   0x4A80F0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x463480

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x52A250
#define EQPlayer__dEQPlayer                                        0x52E450
#define EQPlayer__DoAttack                                         0x53C470
#define EQPlayer__EQPlayer                                         0x532200
#define EQPlayer__SetNameSpriteState                               0x52C3B0
#define EQPlayer__SetNameSpriteTint                                0x52A2C0
#define EQPlayer__IsBodyType_j                                     0x753480
#define EQPlayer__IsTargetable                                     0x753610

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x5333B0
#define EQPlayerManager__GetSpawnByName                            0x533690

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x50AFD0
#define KeypressHandler__AttachKeyToEqCommand                      0x50B010
#define KeypressHandler__ClearCommandStateArray                    0x50ADE0
#define KeypressHandler__HandleKeyDown                             0x509960
#define KeypressHandler__HandleKeyUp                               0x509C70
#define KeypressHandler__SaveKeymapping                            0x50AEB0

// MapViewMap 
#define MapViewMap__Clear                                          0x610420
#define MapViewMap__SaveEx                                         0x610DF0

#define OtherCharData__GetAltCurrency                              0x6DB390

// StringTable 
#define StringTable__getString                                     0x6AC160
