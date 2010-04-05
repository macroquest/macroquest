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
#define __ExpectedVersionDate                                     "Jan 12 2010"
#define __ExpectedVersionTime                                     "15:27:15"
#define __ActualVersionDate                                        0x817B68
#define __ActualVersionTime                                        0x817B74

#define __ClientOverride                                           0
#define __MacroQuestWinClassName                                  "__MacroQuestTray"
#define __MacroQuestWinName                                       "MacroQuest"

// Memory Protection
#define __MemChecker0                                              0x5113C0
#define __MemChecker1                                              0x6E0710
#define __MemChecker2                                              0x571190
#define __MemChecker3                                              0x5710E0
#define __MemChecker4                                              0x694B70
#define __EncryptPad0                                              0x8A8190
#define __EncryptPad1                                              0x8B3290
#define __EncryptPad2                                              0x8AADC8
#define __EncryptPad3                                              0x8AA9C8
#define __EncryptPad4                                              0x8B28D8
#define __AC1                                                      0x65CB10
#define __AC2                                                      0x4D9535
#define __AC3                                                      0x4ED558
#define __AC4                                                      0x4F1428
#define __AC5                                                      0x4FBB78
#define __AC6                                                      0x4FEFFB
#define __AC7                                                      0x4F80A4
#define __AC1_Data                                                 0x800C00

// Direct Input
#define DI8__Main                                                  0xB0DCBC
#define DI8__Keyboard                                              0xB0DCC0
#define DI8__Mouse                                                 0xB0DCC4
#define __AltTimerReady                                            0xA949CE
#define __Attack                                                   0xAF806E
#define __Autofire                                                 0xAF806F
#define __BindList                                                 0x8A2910
#define __Clicks                                                   0xA936C8
#define __CommandList                                              0x8A3260
#define __CurrentMapLabel                                          0xB38F58
#define __CurrentSocial                                            0x89E83C
#define __DoAbilityAvailable                                       0xA94968
#define __DoAbilityList                                            0xAC9F8C
#define __do_loot                                                  0x4B2030
#define __DrawHandler                                              0xB4855C
#define __GroupCount                                               0xA8D4C2
#define __Guilds                                                   0xA92AA8
#define __gWorld                                                   0xA8F380
#define __HotkeyPage                                               0xAF1378
#define __HWnd                                                     0xB0D9F8
#define __InChatMode                                               0xA93600
#define __LastTell                                                 0xA952E4
#define __LMouseHeldTime                                           0xA936F4
#define __Mouse                                                    0xB0DCC8
#define __MouseLook                                                0xA93696
#define __MouseEventTime                                           0xAF81B0
#define __NetStatusToggle                                          0xA93699
#define __PCNames                                                  0xA94D28
#define __RangeAttackReady                                         0xA949CC
#define __RMouseHeldTime                                           0xA936F0
#define __RunWalkState                                             0xA93604
#define __ScreenMode                                               0x9DCD58
#define __ScreenX                                                  0xA935B8
#define __ScreenY                                                  0xA935BC
#define __ScreenXMax                                               0xA935C0
#define __ScreenYMax                                               0xA935C4
#define __ServerHost                                               0xA8D404
#define __ServerName                                               0xAC9F4C
#define __ShiftKeyDown                                             0xA93C80
#define __ShowNames                                                0xA94BFC
#define __Socials                                                  0xACA04C


//// 
//Section 1: Vital Offsets 
//// 
#define instCRaid                                                  0xA8F440
#define instEQZoneInfo                                             0xA93840
#define instKeypressHandler                                        0xAF8194
#define pinstActiveBanker                                          0xA8F418
#define pinstActiveCorpse                                          0xA8F41C
#define pinstActiveGMaster                                         0xA8F420
#define pinstActiveMerchant                                        0xA8F414
#define pinstAltAdvManager                                         0x9DDBD8
#define pinstAuraMgr                                               0x8C661C
#define pinstBandageTarget                                         0xA8F400
#define pinstCamActor                                              0x9DD6C4
#define pinstCDBStr                                                0x9DCD48
#define pinstCDisplay                                              0xA8F428
#define pinstCEverQuest                                            0xB0DE40
#define pinstCharData                                              0xA8F3E4
#define pinstCharSpawn                                             0xA8F40C
#define pinstControlledMissile                                     0xA8F3E0
#define pinstControlledPlayer                                      0xA8F40C
#define pinstCSidlManager                                          0xB47CD0
#define pinstCXWndManager                                          0xB47CC8
#define instDynamicZone                                            0xA93488
#define pinstDZMember                                              0xA93598
#define pinstDZTimerInfo                                           0xA9359C
#define pinstEQItemList                                            0xA8F3C8
#define instEQMisc                                                 0x9DCD00
#define pinstEQSoundManager                                        0x9DDBFC
#define instExpeditionLeader                                       0xA934D2
#define instExpeditionName                                         0xA93512
#define pinstGroup                                                 0xA8D4BE
#define pinstImeManager                                            0xB47CD4
#define pinstLocalPlayer                                           0xA8F3F8
#define pinstMercenaryData                                         0xAF8508
#define pinstModelPlayer                                           0xA8F424
#define pinstPCData                                                0xA8F3E4
#define pinstSkillMgr                                              0xB0AAAC
#define pinstSpawnManager                                          0xB0A908
#define pinstSpellManager                                          0xB0AAB8
#define pinstSpellSets                                             0xAF137C
#define pinstStringTable                                           0xA8F39C
#define pinstSwitchManager                                         0xA8D104
#define pinstTarget                                                0xA8F410
#define pinstTargetObject                                          0xA8F3E8
#define pinstTargetSwitch                                          0xA8F3EC
#define pinstTaskMember                                            0x9DCCE0
#define pinstTrackTarget                                           0xA8F404
#define pinstTradeTarget                                           0xA8F3F4
#define instTributeActive                                          0x9DCD25
#define pinstViewActor                                             0x9DD6C0
#define pinstWorldData                                             0xA8F3C4


//// 
//Section 2:  UI Related Offsets 
//// 
#define pinstCTextOverlay                                          0x8C3EE4
#define pinstCAudioTriggersWindow                                  0x8C3EB0
#define pinstCCharacterSelect                                      0x9DD5C0
#define pinstCFacePick                                             0x9DD570
#define pinstCNoteWnd                                              0x9DD578
#define pinstCBookWnd                                              0x9DD57C
#define pinstCPetInfoWnd                                           0x9DD580
#define pinstCTrainWnd                                             0x9DD584
#define pinstCSkillsWnd                                            0x9DD588
#define pinstCSkillsSelectWnd                                      0x9DD58C
#define pinstCCombatSkillSelectWnd                                 0x9DD590
#define pinstCFriendsWnd                                           0x9DD594
#define pinstCAuraWnd                                              0x9DD598
#define pinstCRespawnWnd                                           0x9DD59C
#define pinstCBandolierWnd                                         0x9DD5A0
#define pinstCPotionBeltWnd                                        0x9DD5A4
#define pinstCAAWnd                                                0x9DD5A8
#define pinstCGroupSearchFiltersWnd                                0x9DD5AC
#define pinstCLoadskinWnd                                          0x9DD5B0
#define pinstCAlarmWnd                                             0x9DD5B4
#define pinstCMusicPlayerWnd                                       0x9DD5B8
#define pinstCMailWnd                                              0x9DD5C4
#define pinstCMailCompositionWnd                                   0x9DD5C8
#define pinstCMailAddressBookWnd                                   0x9DD5CC
#define pinstCRaidWnd                                              0x9DD5D4
#define pinstCRaidOptionsWnd                                       0x9DD5D8
#define pinstCBreathWnd                                            0x9DD5DC
#define pinstCMapViewWnd                                           0x9DD5E0
#define pinstCMapToolbarWnd                                        0x9DD5E4
#define pinstCEditLabelWnd                                         0x9DD5E8
#define pinstCTargetWnd                                            0x9DD5EC
#define pinstCColorPickerWnd                                       0x9DD5F0
#define pinstCPlayerWnd                                            0x9DD5F4
#define pinstCOptionsWnd                                           0x9DD5F8
#define pinstCBuffWindowNORMAL                                     0x9DD5FC
#define pinstCBuffWindowSHORT                                      0x9DD600
#define pinstCharacterCreation                                     0x9DD604
#define pinstCCursorAttachment                                     0x9DD608
#define pinstCCastingWnd                                           0x9DD60C
#define pinstCCastSpellWnd                                         0x9DD610
#define pinstCSpellBookWnd                                         0x9DD614
#define pinstCInventoryWnd                                         0x9DD618
#define pinstCBankWnd                                              0x9DD61C
#define pinstCQuantityWnd                                          0x9DD620
#define pinstCLootWnd                                              0x9DD624
#define pinstCActionsWnd                                           0x9DD628
#define pinstCCombatAbilityWnd                                     0x9DD62C
#define pinstCMerchantWnd                                          0x9DD630
#define pinstCTradeWnd                                             0x9DD634
#define pinstCSelectorWnd                                          0x9DD638
#define pinstCBazaarWnd                                            0x9DD63C
#define pinstCBazaarSearchWnd                                      0x9DD640
#define pinstCGiveWnd                                              0x9DD644
#define pinstCTrackingWnd                                          0x9DD648
#define pinstCInspectWnd                                           0x9DD64C
#define pinstCSocialEditWnd                                        0x9DD650
#define pinstCFeedbackWnd                                          0x9DD654
#define pinstCBugReportWnd                                         0x9DD658
#define pinstCVideoModesWnd                                        0x9DD65C
#define pinstCTextEntryWnd                                         0x9DD664
#define pinstCFileSelectionWnd                                     0x9DD668
#define pinstCCompassWnd                                           0x9DD66C
#define pinstCPlayerNotesWnd                                       0x9DD670
#define pinstCGemsGameWnd                                          0x9DD674
#define pinstCTimeLeftWnd                                          0x9DD678
#define pinstCPetitionQWnd                                         0x9DD68C
#define pinstCSoulmarkWnd                                          0x9DD690
#define pinstCStoryWnd                                             0x9DD694
#define pinstCJournalTextWnd                                       0x9DD698
#define pinstCJournalCatWnd                                        0x9DD69C
#define pinstCBodyTintWnd                                          0x9DD6A0
#define pinstCServerListWnd                                        0x9DD6A4
#define pinstCAvaZoneWnd                                           0x9DD6AC
#define pinstCBlockedBuffWnd                                       0x9DD6B0
#define pinstCBlockedPetBuffWnd                                    0x9DD6B4
#define pinstCInvSlotMgr                                           0x9DD6B8
#define pinstCContainerMgr                                         0x9DD6BC
#define pinstCAdventureLeaderboardWnd                              0xB36470
#define pinstCAdventureRequestWnd                                  0xB3648C
#define pinstCAltStorageWnd                                        0xB364EC
#define pinstCAdventureStatsWnd                                    0xB364A8
#define pinstCBarterMerchantWnd                                    0xB366B8
#define pinstCBarterSearchWnd                                      0xB366D4
#define pinstCBarterWnd                                            0xB366F0
#define pinstCChatManager                                          0xB36994
#define pinstCDynamicZoneWnd                                       0xB36A8C
#define pinstCEQMainWnd                                            0xB36B00
#define pinstCFellowshipWnd                                        0xB36B64
#define pinstCFindLocationWnd                                      0xB36B98
#define pinstCGroupSearchWnd                                       0xB36C48
#define pinstCGroupWnd                                             0xB36C64
#define pinstCGuildBankWnd                                         0xB36C80
#define pinstCGuildMgmtWnd                                         0xB38CB8
#define pinstCGuildTributeMasterWnd                                0xB38CD8
#define pinstCHotButtonWnd                                         0xB38D0C
#define pinstCHotButtonWnd1                                        0xB38D0C
#define pinstCHotButtonWnd2                                        0xB38D10
#define pinstCHotButtonWnd3                                        0xB38D14
#define pinstCHotButtonWnd4                                        0xB38D18
#define pinstCItemDisplayManager                                   0xB38DC4
#define pinstCItemExpTransferWnd                                   0xB38DE4
#define pinstCLeadershipWnd                                        0xB38E80
#define pinstCLFGuildWnd                                           0xB38E9C
#define pinstCMIZoneSelectWnd                                      0xB3900C
#define pinstCAdventureMerchantWnd                                 0xB3911C
#define pinstCConfirmationDialog                                   0xB39138
#define pinstCPopupWndManager                                      0xB39138
#define pinstCProgressionSelectionWnd                              0xB3916C
#define pinstCPvPLeaderboardWnd                                    0xB39188
#define pinstCPvPStatsWnd                                          0xB391A4
#define pinstCSystemInfoDialogBox                                  0xB39270
#define pinstCTargetOfTargetWnd                                    0xB39C6C
#define pinstCTaskSelectWnd                                        0xB39CA0
#define pinstCTaskTemplateSelectWnd                                0xB39CBC
#define pinstCTaskWnd                                              0xB39CD8
#define pinstCTipWndOFDAY                                          0xB39D54
#define pinstCTipWndCONTEXT                                        0xB39D58
#define pinstCTitleWnd                                             0xB39D74
#define pinstCTradeskillWnd                                        0xB39DB8
#define pinstCTributeBenefitWnd                                    0xB39E04
#define pinstCTributeMasterWnd                                     0xB39E20
#define pinstCContextMenuManager                                   0xB47D2C
#define pinstCVoiceMacroWnd                                        0xB0ACAC
#define pinstCHtmlWnd                                              0xB0ACF8


//// 
// Section 3: Miscellaneous Offsets 
//// 
#define __CastRay                                                  0x4C5E90
#define __ConvertItemTags                                          0x4B76B0
#define __ExecuteCmd                                               0x4A3CF0
#define __get_melee_range                                          0x4A9690
#define __GetGaugeValueFromEQ                                      0x65B9D0
#define __GetLabelFromEQ                                           0x65CAB0
#define __GetXTargetType                                           0x74EBA0
#define __LoadFrontEnd                                             0x570060
#define __NewUIINI                                                 0x65B560
#define __ProcessGameEvents                                        0x4F8490
#define CrashDetected                                              0x56FE60
#define DrawNetStatus                                              0x519F50
#define Util__FastTime                                             0x6E0E20


//// 
// Section 4: Function Offsets 
//// 
// AltAdvManager 
#define AltAdvManager__GetCalculatedTimer                          0x47AEF0
#define AltAdvManager__IsAbilityReady                              0x47AF30
#define AltAdvManager__GetAltAbility                               0x47B190

// CBankWnd 
#define CBankWnd__GetNumBankSlots                                  0x58D1E0

// CBazaarSearchWnd 
#define CBazaarSearchWnd__HandleBazaarMsg                          0x596970

// CButtonWnd 
#define CButtonWnd__SetCheck                                       0x70EB20

// CChatManager 
#define CChatManager__GetRGBAFromIndex                             0x5AC790
#define CChatManager__InitContextMenu                              0x5ACF60

// CChatService
#define CChatService__GetNumberOfFriends                           0x6CB230
#define CChatService__GetFriendName                                0x6CB240

// CChatWindow 
#define CChatWindow__CChatWindow                                   0x5B1160
#define CChatWindow__Clear                                         0x5B1AD0
#define CChatWindow__WndNotification                               0x5B1CC0

// CComboWnd 
#define CComboWnd__DeleteAll                                       0x6F8B60
#define CComboWnd__Draw                                            0x6F8D20
#define CComboWnd__GetCurChoice                                    0x6F8B00
#define CComboWnd__GetListRect                                     0x6F9010
#define CComboWnd__GetTextRect                                     0x6F8B90
#define CComboWnd__InsertChoice                                    0x6F9080
#define CComboWnd__SetColors                                       0x6F8A90
#define CComboWnd__SetChoice                                       0x6F8AC0

// CContainerWnd 
#define CContainerWnd__HandleCombine                               0x5B9180
#define CContainerWnd__vftable                                     0x81F538

// CDisplay 
#define CDisplay__CleanGameUI                                      0x46DFF0
#define CDisplay__GetClickedActor                                  0x467320
#define CDisplay__GetUserDefinedColor                              0x466440
#define CDisplay__GetWorldFilePath                                 0x4658B0
#define CDisplay__is3dON                                           0x4649F0
#define CDisplay__ReloadUI                                         0x478070
#define CDisplay__WriteTextHD2                                     0x46A010

// CEditBaseWnd 
#define CEditBaseWnd__SetMaxChars                                  0x587120
#define CEditBaseWnd__SetSel                                       0x71B570

// CEditWnd 
#define CEditWnd__DrawCaret                                        0x701AB0
#define CEditWnd__GetCharIndexPt                                   0x702A80
#define CEditWnd__GetDisplayString                                 0x701C50
#define CEditWnd__GetHorzOffset                                    0x701EE0
#define CEditWnd__GetLineForPrintableChar                          0x702530
#define CEditWnd__GetSelStartPt                                    0x702CD0
#define CEditWnd__GetSTMLSafeText                                  0x702080
#define CEditWnd__PointFromPrintableChar                           0x702640
#define CEditWnd__SelectableCharFromPoint                          0x7027C0
#define CEditWnd__SetEditable                                      0x702050

// CEverQuest 
#define CEverQuest__ClickedPlayer                                  0x4D9C10
#define CEverQuest__DropHeldItemOnGround                           0x4DE180
#define CEverQuest__dsp_chat                                       0x4DF920
#define CEverQuest__DoTellWindow                                   0x4DE300
#define CEverQuest__EnterZone                                      0x4F13C0
#define CEverQuest__GetBodyTypeDesc                                0x4D6E10
#define CEverQuest__GetClassDesc                                   0x4D6650
#define CEverQuest__GetClassThreeLetterCode                        0x4D6C50
#define CEverQuest__GetDeityDesc                                   0x4D7480
#define CEverQuest__GetLangDesc                                    0x4D71A0
#define CEverQuest__GetRaceDesc                                    0x4D7450
#define CEverQuest__InterpretCmd                                   0x4E0480
#define CEverQuest__LeftClickedOnPlayer                            0x4F2EF0
#define CEverQuest__LMouseUp                                       0x4F67E0
#define CEverQuest__RightClickedOnPlayer                           0x4F7080
#define CEverQuest__RMouseUp                                       0x4F8060
#define CEverQuest__SetGameState                                   0x4DA0A0
#define CEverQuest__Emote                                          0x4DFB40

// CGaugeWnd 
#define CGaugeWnd__CalcFillRect                                    0x5C5A30
#define CGaugeWnd__CalcLinesFillRect                               0x5C5A90
#define CGaugeWnd__Draw                                            0x5C5EE0

// CGuild
#define CGuild__FindMemberByName                                   0x41AEB0

// CHotButtonWnd 
#define CHotButtonWnd__DoHotButton                                 0x5DEA00

// CInvSlotMgr 
#define CInvSlotMgr__FindInvSlot                                   0x5E8050
#define CInvSlotMgr__MoveItem                                      0x5E81F0

// CInvSLot
#define CInvSlot__HandleRButtonUp                                  0x5E78E0
#define CInvSlot__SliderComplete                                   0x5E69F0

// CInvSlotWnd
#define CInvSlotWnd__DrawTooltip                                   0x5E9190

// CItemDisplayWnd 
#define CItemDisplayWnd__SetSpell                                  0x659400
#define CItemDisplayWnd__UpdateStrings                             0x5E9E40

// CLabel 
#define CLabel__Draw                                               0x5FC500

// CListWnd 
#define CListWnd__AddColumn                                        0x6F2580
#define CListWnd__AddColumn1                                       0x6F2050
#define CListWnd__AddLine                                          0x6F1B70
#define CListWnd__AddString                                        0x6F1D10
#define CListWnd__CalculateFirstVisibleLine                        0x6EE830
#define CListWnd__CalculateVSBRange                                0x6F0A50
#define CListWnd__ClearAllSel                                      0x6EDD80
#define CListWnd__CloseAndUpdateEditWindow                         0x6EEEB0
#define CListWnd__Compare                                          0x6EF250
#define CListWnd__Draw                                             0x6F06D0
#define CListWnd__DrawColumnSeparators                             0x6F0540
#define CListWnd__DrawHeader                                       0x6EE010
#define CListWnd__DrawItem                                         0x6EFB60
#define CListWnd__DrawLine                                         0x6F01B0
#define CListWnd__DrawSeparator                                    0x6F05E0
#define CListWnd__EnsureVisible                                    0x6EE8C0
#define CListWnd__ExtendSel                                        0x6EFA80
#define CListWnd__GetColumnMinWidth                                0x6EDB10
#define CListWnd__GetColumnWidth                                   0x6EDA50
#define CListWnd__GetCurSel                                        0x6ED490
#define CListWnd__GetHeaderRect                                    0x6ED600
#define CListWnd__GetItemAtPoint                                   0x6EEBC0
#define CListWnd__GetItemAtPoint1                                  0x6EEC30
#define CListWnd__GetItemData                                      0x6ED800
#define CListWnd__GetItemHeight                                    0x6EE4A0
#define CListWnd__GetItemIcon                                      0x6ED990
#define CListWnd__GetItemRect                                      0x6EE9A0
#define CListWnd__GetItemText                                      0x6ED840
#define CListWnd__GetSelList                                       0x6F1F30
#define CListWnd__GetSeparatorRect                                 0x6EF190
#define CListWnd__RemoveLine                                       0x6F1EE0
#define CListWnd__SetColors                                        0x6ED560
#define CListWnd__SetColumnJustification                           0x6EDBF0
#define CListWnd__SetColumnWidth                                   0x6EDAD0
#define CListWnd__SetCurSel                                        0x6ED4D0
#define CListWnd__SetItemColor                                     0x6F1700
#define CListWnd__SetItemData                                      0x6EDE20
#define CListWnd__SetItemText                                      0x6F1680
#define CListWnd__ShiftColumnSeparator                             0x6EF990
#define CListWnd__Sort                                             0x6F25C0
#define CListWnd__ToggleSel                                        0x6EDCF0

// CMapViewWnd 
#define CMapViewWnd__CMapViewWnd                                   0x611D90

// CMerchantWnd 
#define CMerchantWnd__DisplayBuyOrSellPrice                        0x61DDB0
#define CMerchantWnd__RequestBuyItem                               0x61FCF0
#define CMerchantWnd__RequestSellItem                              0x620110
#define CMerchantWnd__SelectBuySellSlot                            0x61F180

// CObfuscator
#define CObfuscator__doit                                          0x6A5230

// CSidlManager 
#define CSidlManager__FindScreenPieceTemplate1                     0x70A340
#define CSidlManager__CreateLabel                                  0x652350

// CSidlScreenWnd 
#define CSidlScreenWnd__CalculateHSBRange                          0x5891E0
#define CSidlScreenWnd__CalculateVSBRange                          0x6FA7B0
#define CSidlScreenWnd__ConvertToRes                               0x71B450
#define CSidlScreenWnd__CreateChildrenFromSidl                     0x6FAC80
#define CSidlScreenWnd__CSidlScreenWnd1                            0x6FBD70
#define CSidlScreenWnd__CSidlScreenWnd2                            0x6FBE20
#define CSidlScreenWnd__dCSidlScreenWnd                            0x6FB520
#define CSidlScreenWnd__DrawSidlPiece                              0x6FA940
#define CSidlScreenWnd__EnableIniStorage                           0x6FA4A0
#define CSidlScreenWnd__GetSidlPiece                               0x6FAB50
#define CSidlScreenWnd__Init1                                      0x6FBBD0
#define CSidlScreenWnd__LoadIniInfo                                0x6FAD40
#define CSidlScreenWnd__LoadIniListWnd                             0x6FA5F0
#define CSidlScreenWnd__LoadSidlScreen                             0x6FB770
#define CSidlScreenWnd__StoreIniInfo                               0x6FA0B0
#define CSidlScreenWnd__StoreIniVis                                0x6FA430
#define CSidlScreenWnd__WndNotification                            0x6FB950
#define CSidlScreenWnd__GetChildItem                               0x6FA500

// CSkillMgr
#define CSkillMgr__GetSkillCap                                     0x53DCF0

// CSliderWnd 
#define CSliderWnd__GetValue                                       0x71CAA0
#define CSliderWnd__SetValue                                       0x71CBA0
#define CSliderWnd__SetNumTicks                                    0x71D150

// CSpellBookWnd 
#define CSpellBookWnd__MemorizeSet                                 0x657160

// CStmlWnd
#define CStmlWnd__AppendSTML                                       0x719630
#define CStmlWnd__CalculateHSBRange                                0x710DB0
#define CStmlWnd__CalculateVSBRange                                0x710D20
#define CStmlWnd__CanBreakAtCharacter                              0x710F30
#define CStmlWnd__FastForwardToEndOfTag                            0x711C30
#define CStmlWnd__ForceParseNow                                    0x719B30
#define CStmlWnd__GetNextTagPiece                                  0x711B50
#define CStmlWnd__GetSTMLText                                      0x5B1100
#define CStmlWnd__GetThisChar                                      0x740A10
#define CStmlWnd__GetVisiableText                                  0x713050
#define CStmlWnd__InitializeWindowVariables                        0x7155B0
#define CStmlWnd__MakeStmlColorTag                                 0x70FC40
#define CStmlWnd__MakeWndNotificationTag                           0x70FCE0
#define CStmlWnd__SetSTMLText                                      0x7156D0
#define CStmlWnd__StripFirstSTMLLines                              0x7192D0
#define CStmlWnd__UpdateHistoryString                              0x7138E0

// CTabWnd 
#define CTabWnd__Draw                                              0x71DF70
#define CTabWnd__DrawCurrentPage                                   0x71D900
#define CTabWnd__DrawTab                                           0x71D6E0
#define CTabWnd__GetCurrentPage                                    0x71DC00
#define CTabWnd__GetPageClientRect                                 0x71D3B0
#define CTabWnd__GetPageFromTabIndex                               0x71D610
#define CTabWnd__GetPageInnerRect                                  0x71D410
#define CTabWnd__GetTabInnerRect                                   0x71D590
#define CTabWnd__GetTabRect                                        0x71D4A0
#define CTabWnd__InsertPage                                        0x71E200
#define CTabWnd__SetPage                                           0x71DC40
#define CTabWnd__SetPageRect                                       0x71DEA0
#define CTabWnd__UpdatePage                                        0x71E180

// CTextOverlay 
#define CTextOverlay__DisplayText                                  0x4174A0

// CTextureFont
#define CTextureFont__DrawWrappedText                              0x6FC1A0

// CXMLDataManager 
#define CXMLDataManager__GetXMLData                                0x71EE10

// CXMLSOMDocumentBase 
#define CXMLSOMDocumentBase__XMLRead                               0x6EC740

// CXRect 
#define CXRect__CenterPoint                                        0x58C860

// CXStr 
// WARNING:  Be sure that none of these offsets are identical! 
// 
// Note:  dCXStr, CXStr1, & CXStr3 can be found in the 'BookWindow' constructor. 
#define CXStr__CXStr                                               0x50AE20
#define CXStr__CXStr1                                              0x6E63A0
#define CXStr__CXStr3                                              0x6DE120
#define CXStr__dCXStr                                              0x7111C0
#define CXStr__operator_equal1                                     0x6DE2E0
#define CXStr__operator_plus_equal1                                0x6DF320

// CXWnd 
#define CXWnd__BringToTop                                          0x6F2BA0
#define CXWnd__Center                                              0x6F73E0
#define CXWnd__ClrFocus                                            0x6F29C0
#define CXWnd__DoAllDrawing                                        0x6F8230
#define CXWnd__DrawChildren                                        0x6F8380
#define CXWnd__DrawColoredRect                                     0x6F2E80
#define CXWnd__DrawTooltip                                         0x6F8080
#define CXWnd__DrawTooltipAtPoint                                  0x6F7190
#define CXWnd__GetBorderFrame                                      0x6F32C0
#define CXWnd__GetChildWndAt                                       0x6F69C0
#define CXWnd__GetClientClipRect                                   0x6F3140
#define CXWnd__GetScreenClipRect                                   0x6F7600
#define CXWnd__GetScreenRect                                       0x6F3450
#define CXWnd__GetTooltipRect                                      0x6F2F90
#define CXWnd__GetWindowTextA                                      0x57AEE0
#define CXWnd__IsActive                                            0x6FD310
#define CXWnd__IsDescendantOf                                      0x6F31F0
#define CXWnd__IsReallyVisible                                     0x6F69A0
#define CXWnd__IsType                                              0x721C00
#define CXWnd__Move                                                0x6F6160
#define CXWnd__Move1                                               0x6F7E60
#define CXWnd__ProcessTransition                                   0x6F2B50
#define CXWnd__Refade                                              0x6F2AD0
#define CXWnd__Resize                                              0x6F3520
#define CXWnd__Right                                               0x6F7540
#define CXWnd__SetFocus                                            0x6F4D30
#define CXWnd__SetKeyTooltip                                       0x6F3700
#define CXWnd__SetMouseOver                                        0x6F7890
#define CXWnd__StartFade                                           0x6F2BE0
#define CXWnd__GetChildItem                                        0x6F7810

// CXWndManager 
#define CXWndManager__DrawCursor                                   0x6FE860
#define CXWndManager__DrawWindows                                  0x6FE4E0
#define CXWndManager__GetKeyboardFlags                             0x6FCF60
#define CXWndManager__HandleKeyboardMsg                            0x6FD5E0
#define CXWndManager__RemoveWnd                                    0x6FD430

// CDBStr
#define CDBStr__GetString                                          0x463320

// EQ_Character 
#define EQ_Character__CastRay                                      0x74CA20
#define EQ_Character__CastSpell                                    0x42DC20
#define EQ_Character__Cur_HP                                       0x436E70
#define EQ_Character__GetAACastingTimeModifier                     0x423AF0
#define EQ_Character__GetCharInfo2                                 0x6BC260
#define EQ_Character__GetFocusCastingTimeModifier                  0x41F370
#define EQ_Character__GetFocusRangeModifier                        0x41F4B0
#define EQ_Character__Max_Endurance                                0x5203D0
#define EQ_Character__Max_HP                                       0x432050
#define EQ_Character__Max_Mana                                     0x520200
#define EQ_Character__doCombatAbility                              0x51F110
#define EQ_Character__UseSkill                                     0x440E20
#define EQ_Character__GetConLevel                                  0x51B410

// EQ_Item 
#define EQ_Item__CanDrop                                           0x508BC0
#define EQ_Item__GetItemLinkHash                                   0x6AECE0
#define EQ_Item__IsStackable                                       0x6A5B10

// EQ_LoadingS 
#define EQ_LoadingS__SetProgressBar                                0x47C060
#define EQ_LoadingS__Array                                         0x8A0D78

// EQ_PC 
#define EQ_PC__DestroyHeldItemOrMoney                              0x523260
#define EQ_PC__GetAltAbilityIndex                                  0x6B3F20
#define EQ_PC__GetCombatAbility                                    0x6B3FB0
#define EQ_PC__GetCombatAbilityTimer                               0x6B4060
#define EQ_PC__GetItemTimerValue                                   0x51E040
#define EQ_PC__HasLoreItem                                         0x521720

// EQItemList 
#define EQItemList__dEQItemList                                    0x4A7BA0
#define EQItemList__EQItemList                                     0x4A7AF0

// EQMisc
#define EQMisc__GetActiveFavorCost                                 0x462C80

// EQPlayer 
#define EQPlayer__ChangeBoneStringSprite                           0x527C40
#define EQPlayer__dEQPlayer                                        0x52BEE0
#define EQPlayer__DoAttack                                         0x539EA0
#define EQPlayer__EQPlayer                                         0x52FC70
#define EQPlayer__SetNameSpriteState                               0x529D50
#define EQPlayer__SetNameSpriteTint                                0x527CB0
#define EQPlayer__IsBodyType_j                                     0x74C330
#define EQPlayer__IsTargetable                                     0x74C4C0

//EQPlayerManager
#define EQPlayerManager__GetSpawnByID                              0x530E20
#define EQPlayerManager__GetSpawnByName                            0x531100

// KeyPressHandler 
#define KeypressHandler__AttachAltKeyToEqCommand                   0x50A840
#define KeypressHandler__AttachKeyToEqCommand                      0x50A880
#define KeypressHandler__ClearCommandStateArray                    0x50A650
#define KeypressHandler__HandleKeyDown                             0x5091D0
#define KeypressHandler__HandleKeyUp                               0x5094E0
#define KeypressHandler__SaveKeymapping                            0x50A720

// MapViewMap 
#define MapViewMap__Clear                                          0x60D430
#define MapViewMap__SaveEx                                         0x60DE00

#define OtherCharData__GetAltCurrency                              0x6D3D30

// StringTable 
#define StringTable__getString                                     0x6A54B0
